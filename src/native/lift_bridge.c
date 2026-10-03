/*
 * lift_bridge.c - see lift_bridge.h. Compiled only into builds that have the generated handlers (handlers_gen.c).
 */
#ifndef LIFT_BACKEND_MEM
#define LIFT_BACKEND_MEM 1
#endif
#include "lift_bridge.h"

#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lift_rt.h"

#define MAX_CALL_ARGS 32
#define RETURN_TRAP 0xfeedfac0u /* the return address pushed for a call from native code: nothing is ever run there */

Mem *lift_mem;
uint64_t lift_icount; /* instructions executed by lifted code, when built with -DLIFT_COUNT */
LiftRegs lift_in, lift_out;
int lift_inplace;

void lift_call_regs(uint32_t regs[7])
{
    regs[0] = lift_out.eax;
    regs[1] = lift_out.ecx;
    regs[2] = lift_out.edx;
    regs[3] = lift_out.ebx;
    regs[4] = lift_out.ebp;
    regs[5] = lift_out.esi;
    regs[6] = lift_out.edi;
}

#ifdef LIFT_COVERAGE
/* Which lifted instructions ran, appended to the file $FLAT_COV at exit (tools/lift/coverage.py reads it). */
static uint32_t *cov;
static size_t ncov, capcov;
static int cov_registered;

static void dump_cov(void)
{
    const char *path = getenv("FLAT_COV");
    FILE *f = path ? fopen(path, "a") : NULL;
    size_t i;
    if (!f)
        return;
    for (i = 0; i < ncov; i++)
        fprintf(f, "%x\n", cov[i]);
    fclose(f);
}

void lift_cov(uint32_t a)
{
    size_t i;
    if (!cov_registered) {
        cov_registered = 1;
        atexit(dump_cov);
    }
    for (i = 0; i < ncov; i++)
        if (cov[i] == a)
            return;
    if (ncov == capcov)
        cov = realloc(cov, sizeof(uint32_t) * (capcov = capcov ? capcov * 2 : 1024));
    cov[ncov++] = a;
}
#endif
static Vm *bridge_vm;
static LiftCalls bridge_mode;
static uint32_t stack_top = LIFT_STACK_TOP;

void lift_set_stack(uint32_t top)
{
    stack_top = top;
}

uint32_t lift_get_stack(void)
{
    return stack_top;
}

/* Lifted functions the host does not stand in for (native_host.c host_set_enabled): they are not run from here, the call goes
 * out to the original instead. */
static unsigned char lifted_off[4096];

void lift_set_enabled(uint32_t entry, int on)
{
    int i;
    for (i = 0; i < LIFTED_COUNT && i < (int)sizeof(lifted_off); i++)
        if (LIFTED[i].entry == entry)
            lifted_off[i] = !on;
}

const LiftedFn *lift_find(uint32_t entry)
{
    int i;
    for (i = 0; i < LIFTED_COUNT; i++)
        if (LIFTED[i].entry == entry && !(i < (int)sizeof(lifted_off) && lifted_off[i]))
            return &LIFTED[i];
    return NULL;
}

static const CalleeRow *callee_row(uint32_t target)
{
    int i;
    for (i = 0; i < LIFT_CALLEE_COUNT; i++)
        if (LIFT_CALLEES[i].addr == target)
            return &LIFT_CALLEES[i];
    return NULL;
}

void lift_bad_jump(uint32_t from)
{
    char what[80];
    snprintf(what, sizeof(what), "lifted jump at 0x%08x indexed past its table", from);
    NATIVE_UNIMPLEMENTED(what);
}

/* A call into the lifted function at `entry` on the frame the caller has already built at `esp` (a return address, then
 * the arguments): what a host does when the original program calls a function that has been lifted. */
int lift_run_at(Vm *vm, uint32_t entry, uint32_t esp, const uint32_t *regs, uint32_t *ret)
{
    const LiftedFn *f = NULL;
    int i;
    for (i = 0; i < LIFTED_COUNT; i++) /* the host replaces this function: it runs whatever the enabled flags say about calls */
        if (LIFTED[i].entry == entry)
            f = &LIFTED[i];
    uint32_t saved = stack_top;

    if (!f)
        return 0;
    lift_mem = vm->mem;
    stack_top = esp;
    if (regs)
        lift_in = (LiftRegs){regs[0], regs[1], regs[2], regs[3], regs[4], regs[5], regs[6]};
    else
        memset(&lift_in, 0, sizeof(lift_in));
    *ret = f->fn(esp);
    stack_top = saved;
    return 1;
}

/* A call made from native code (the scan running a card's handler): put the arguments on the lifted stack and run. */
int lift_call_function(Vm *vm, uint32_t entry, int nargs, const uint32_t *args, uint32_t *ret)
{
    const LiftedFn *f = lift_find(entry);
    uint32_t esp, saved = stack_top;
    int i;

    if (!f)
        return 0;
    if (getenv("LIFT_TRACE"))   /* which handlers a run used, for tests that must be sure the lifted code ran */
        fprintf(stderr, "lifted: %s\n", f->name);
    lift_mem = vm->mem;
    esp = stack_top - 4u * (uint32_t)(nargs + 1);
    mem_wr32(vm->mem, esp, RETURN_TRAP);
    for (i = 0; i < nargs; i++)
        mem_wr32(vm->mem, esp + 4u + 4u * (uint32_t)i, args[i]);
    stack_top = esp; /* anything the handler calls from here on uses the stack below the frame */
    memset(&lift_in, 0, sizeof(lift_in));
    *ret = f->fn(esp);
    stack_top = saved;
    return 1;
}

uint32_t lift_call(uint32_t target, uint32_t argp, uint32_t *cleanup)
{
    const CalleeRow *row = callee_row(target);
    uint32_t args[MAX_CALL_ARGS], ret = 0;
    const LiftRegs rg = lift_out; /* the registers at the call: a nested call overwrites lift_out */
    int nargs = row ? row->nargs : 3; /* a call through the master table is a handler(player, slot, event) */
    int i;

    if (nargs > MAX_CALL_ARGS)
        NATIVE_UNIMPLEMENTED("a lifted call with more than 32 arguments");
    if (getenv("LIFT_TRACE"))
        fprintf(stderr, "  calls 0x%08x\n", target);
    for (i = 0; i < nargs; i++)
        args[i] = mem_rd32(bridge_vm->mem, argp + 4u * (uint32_t)i);
    *cleanup = row ? row->cleanup : 0;

    if (bridge_mode == LIFT_CALLS_NATIVE || bridge_mode == LIFT_CALLS_NATIVES_ONLY) {
        int f;
        for (f = 0; f < FN_COUNT; f++)
            if (bridge_vm->L->entry[f] == target && NATIVE_FUNCTIONS[f].nargs == nargs && !native_disabled[f] &&
                (!native_exact_only || NATIVE_FUNCTIONS[f].self_charging)) {
                /* a native function can run lifted code again (a query scans the cards): that code's frames go below this
                 * one's, not over the locals it is using */
                uint32_t saved_top = stack_top;
                stack_top = argp - 4u;
                if (f == FN_CRT_MEMCPY) {   /* the prologue's saves of EBP, EDI and ESI, which stay on the stack below the call */
                    mem_wr32(bridge_vm->mem, argp - 8u, rg.ebp);
                    mem_wr32(bridge_vm->mem, argp - 12u, rg.edi);
                    mem_wr32(bridge_vm->mem, argp - 16u, rg.esi);
                }
                if (f == FN_CRT_MEMSET && args[2])   /* its prologue saves EDI (not for a length of 0) */
                    mem_wr32(bridge_vm->mem, argp - 8u, rg.edi);
                ret = NATIVE_FUNCTIONS[f].run(bridge_vm, args);
                stack_top = saved_top;
                if (getenv("LIFT_TRACE")) {
                    fprintf(stderr, "  native %s(", NATIVE_FUNCTIONS[f].name);
                    for (i = 0; i < nargs; i++)
                        fprintf(stderr, "%s%d", i ? ", " : "", (int)args[i]);
                    fprintf(stderr, ") -> %d\n", (int)ret);
                }
                return ret;
            }
        if (bridge_mode == LIFT_CALLS_NATIVE && lift_find(target)) {
            const LiftedFn *lf = lift_find(target);
            uint32_t saved = stack_top;
            stack_top = argp - 4u;
            lift_in = rg;
            ret = lf->fn(argp - 4u);
            stack_top = saved;
            return ret;
        }
    }
    {   /* out to the Vm's hook: a guest function called from here gets its frame below this one's */
        uint32_t saved_top = stack_top;
        stack_top = argp - 4u;
        lift_out = rg;
        lift_inplace = 1;
        ret = vm_call_at(bridge_vm, CALLEE_FUNCTION, target, nargs, args);
        lift_inplace = 0;
        stack_top = saved_top;
        return ret;
    }
}

/* LIFT_DUMP="address:length,..." prints that memory (?? where nothing defined it) each time the scan starts a handler. */
static void dump_memory(Vm *vm)
{
    const char *spec = getenv("LIFT_DUMP");
    char buf[256];
    char *part;

    if (!spec)
        return;
    snprintf(buf, sizeof(buf), "%s", spec);
    fprintf(stderr, "dump");
    for (part = strtok(buf, ","); part; part = strtok(NULL, ",")) {
        uint32_t a = (uint32_t)strtoul(part, &part, 0), n, i;
        n = (uint32_t)strtoul(part + 1, NULL, 0);
        fprintf(stderr, " ");
        for (i = 0; i < n; i++) {
            if (mem_is_defined(vm->mem, a + i))
                fprintf(stderr, "%02x", mem_rd8(vm->mem, a + i));
            else
                fprintf(stderr, "??");
        }
        part = NULL;
    }
    fprintf(stderr, "\n");
}

static int dispatch_handler(Vm *vm, uint32_t addr, int nargs, const uint32_t *args, uint32_t *ret)
{
    dump_memory(vm);
    return lift_call_function(vm, addr, nargs, args, ret);
}

void lift_attach(Vm *vm, LiftCalls mode)
{
    bridge_vm = vm;
    bridge_mode = mode;
    lift_mem = vm->mem;
    native_handler_dispatch = mode == LIFT_CALLS_NATIVE ? dispatch_handler : NULL;
}

void lift_detach(void)
{
    native_handler_dispatch = NULL;
    bridge_vm = NULL;
}

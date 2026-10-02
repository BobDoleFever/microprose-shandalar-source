/*
 * lift_bridge.c - see lift_bridge.h. Compiled only into builds that have the generated handlers (handlers_gen.c).
 */
#ifndef LIFT_BACKEND_MEM
#define LIFT_BACKEND_MEM 1
#endif
#include "lift_bridge.h"

#include <setjmp.h>
#include <stdio.h>
#include <string.h>

#include "lift_rt.h"

#define MAX_CALL_ARGS 32
#define RETURN_TRAP 0xfeedfac0u /* the return address pushed for a call from native code: nothing is ever run there */

Mem *lift_mem;
static Vm *bridge_vm;
static LiftCalls bridge_mode;
static uint32_t stack_top = LIFT_STACK_TOP;

void lift_set_stack(uint32_t top)
{
    stack_top = top;
}

const LiftedFn *lift_find(uint32_t entry)
{
    int i;
    for (i = 0; i < LIFTED_COUNT; i++)
        if (LIFTED[i].entry == entry)
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

/* A call made from native code (the scan running a card's handler): put the arguments on the lifted stack and run. */
int lift_call_function(Vm *vm, uint32_t entry, int nargs, const uint32_t *args, uint32_t *ret)
{
    const LiftedFn *f = lift_find(entry);
    uint32_t esp, saved = stack_top;
    int i;

    if (!f)
        return 0;
    lift_mem = vm->mem;
    esp = stack_top - 4u * (uint32_t)(nargs + 1);
    mem_wr32(vm->mem, esp, RETURN_TRAP);
    for (i = 0; i < nargs; i++)
        mem_wr32(vm->mem, esp + 4u + 4u * (uint32_t)i, args[i]);
    stack_top = esp; /* anything the handler calls from here on uses the stack below the frame */
    *ret = f->fn(esp);
    stack_top = saved;
    return 1;
}

uint32_t lift_call(uint32_t target, uint32_t argp, uint32_t *cleanup)
{
    const CalleeRow *row = callee_row(target);
    uint32_t args[MAX_CALL_ARGS], ret = 0;
    int nargs = row ? row->nargs : 3; /* a call through the master table is a handler(player, slot, event) */
    int i;

    if (nargs > MAX_CALL_ARGS)
        NATIVE_UNIMPLEMENTED("a lifted call with more than 32 arguments");
    for (i = 0; i < nargs; i++)
        args[i] = mem_rd32(bridge_vm->mem, argp + 4u * (uint32_t)i);
    *cleanup = row ? row->cleanup : 0;

    if (bridge_mode == LIFT_CALLS_NATIVE) {
        int f;
        for (f = 0; f < FN_COUNT; f++)
            if (bridge_vm->L->entry[f] == target && NATIVE_FUNCTIONS[f].nargs == nargs)
                return NATIVE_FUNCTIONS[f].run(bridge_vm, args);
        if (lift_find(target)) {
            const LiftedFn *lf = lift_find(target);
            uint32_t saved = stack_top;
            stack_top = argp - 4u;
            ret = lf->fn(argp - 4u);
            stack_top = saved;
            return ret;
        }
    }
    return vm_call_at(bridge_vm, CALLEE_FUNCTION, target, nargs, args);
}

static int dispatch_handler(Vm *vm, uint32_t addr, int nargs, const uint32_t *args, uint32_t *ret)
{
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

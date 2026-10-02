/*
 * native_host.c - see native_host.h.
 */
#include "native_host.h"

#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "engine.h"
#ifdef HOST_LIFTED
#include "lift_bridge.h"
#endif

static Mem host_mem;
static Vm host_vm;
static HostCall host_call;
static uint32_t host_sp; /* where the guest's stack is, when no lifted code is tracking it */

#define MAX_REGIONS 32
static struct {
    uint32_t base, size;
    uint8_t *ptr;
} regions[MAX_REGIONS];
static int nregions;
static HostMemRead fallback_read;
static HostMemWrite fallback_write;

void host_add_region(uint32_t base, uint32_t size, void *ptr)
{
    if (nregions < MAX_REGIONS) {
        regions[nregions].base = base;
        regions[nregions].size = size;
        regions[nregions].ptr = ptr;
        nregions++;
    }
}

static uint8_t *locate(uint32_t addr, int size)
{
    int i;
    for (i = 0; i < nregions; i++)
        if (addr >= regions[i].base && (uint64_t)addr + (uint64_t)size <= (uint64_t)regions[i].base + regions[i].size)
            return regions[i].ptr + (addr - regions[i].base);
    return NULL;
}

/* host_native_try runs a call without a thread: a call out stops it (longjmp) and what it wrote is put back. */
static int trying;
static jmp_buf try_jb;
typedef struct {
    uint32_t addr;
    uint32_t old;
    int size;
} Undo;
static Undo *undo;
static size_t nundo, capundo;

static uint32_t direct_read(void *ctx, uint32_t addr, int size)
{
    uint8_t *p = locate(addr, size);
    uint32_t v = 0;
    if (p) {
        memcpy(&v, p, (size_t)size);   /* little-endian host, like the guest */
        return v;
    }
    return fallback_read ? fallback_read(ctx, addr, size) : 0;
}

static void direct_write(void *ctx, uint32_t addr, int size, uint32_t value)
{
    uint8_t *p = locate(addr, size);
    if (p) {
        if (trying) {
            if (nundo == capundo) {
                capundo = capundo ? capundo * 2 : 4096;
                undo = realloc(undo, capundo * sizeof(*undo));
                if (!undo)
                    abort();
            }
            undo[nundo].addr = addr;
            undo[nundo].size = size;
            undo[nundo].old = 0;
            memcpy(&undo[nundo].old, p, (size_t)size);
            nundo++;
        }
        memcpy(p, &value, (size_t)size);
    } else if (fallback_write)
        fallback_write(ctx, addr, size, value);
}

static uint32_t current_sp(void)
{
#ifdef HOST_LIFTED
    return lift_get_stack();
#else
    return host_sp;
#endif
}

static uint32_t call_out(void *ctx, Callee callee, uint32_t addr, int nargs, const uint32_t *args)
{
    (void)ctx;
    if (trying)
        longjmp(try_jb, 1);
    (void)callee; /* the address says which function; the host does not need the enum */
    return host_call(addr, nargs, args, current_sp());
}

int host_init(const char *program, HostMemRead rd, HostMemWrite wr, HostCall call)
{
    const Layout *layout = layout_for(program);

    if (!layout)
        return -1;
    mem_init(&host_mem);
    fallback_read = rd;
    fallback_write = wr;
    host_mem.ext_read = direct_read;
    host_mem.ext_write = direct_write;
    host_vm.mem = &host_mem;
    host_vm.L = layout;
    host_vm.call = call_out;
    host_call = call;
#ifdef HOST_LIFTED
    lift_attach(&host_vm, LIFT_CALLS_NATIVE);
#endif
    return 0;
}

/* Put back what a stopped call wrote, newest first. */
static void roll_back(void)
{
    while (nundo > 0) {
        Undo *u = &undo[--nundo];
        uint8_t *p = locate(u->addr, u->size);
        if (p)
            memcpy(p, &u->old, (size_t)u->size);
    }
}

void host_counters(uint64_t *entries, uint64_t *lifted_instructions)
{
    int i;
    for (i = 0; i < FN_COUNT; i++)
        entries[i] = native_entries[i];
#ifdef HOST_LIFTED
    {
        extern uint64_t lift_icount;
        *lifted_instructions = lift_icount;
    }
#else
    *lifted_instructions = 0;
#endif
}

int host_native_count(void)
{
    return FN_COUNT;
}

int host_native_find(const char *name)
{
    const NativeInfo *n = native_find(name);
    return n ? (int)n->id : -1;
}

int host_native_try(int id, const uint32_t *args, uint32_t sp, uint32_t *ret)
{
#ifdef HOST_LIFTED
    uint32_t saved_sp = lift_get_stack();
    lift_set_stack(sp);
#endif
    host_sp = sp;
    nundo = 0;
    trying = 1;
    if (setjmp(try_jb)) {
        trying = 0;
        roll_back();
#ifdef HOST_LIFTED
        lift_set_stack(saved_sp);
#endif
        return 1;
    }
    *ret = NATIVE_FUNCTIONS[id].run(&host_vm, args);
    trying = 0;
    nundo = 0;
#ifdef HOST_LIFTED
    lift_set_stack(saved_sp);
#endif
    return 0;
}

const char *host_native_name(int id)
{
    return NATIVE_FUNCTIONS[id].name;
}

uint32_t host_native_entry(int id)
{
    return host_vm.L->entry[id];
}

int host_native_nargs(int id)
{
    return NATIVE_FUNCTIONS[id].nargs;
}

int host_native_ret_bits(int id)
{
    return NATIVE_FUNCTIONS[id].ret_bits;
}

uint32_t host_native_run(int id, const uint32_t *args, uint32_t sp)
{
#ifdef HOST_LIFTED
    lift_set_stack(sp); /* a native function that runs lifted code puts its frames below the guest's */
#endif
    host_sp = sp;
    return NATIVE_FUNCTIONS[id].run(&host_vm, args);
}

#ifdef HOST_LIFTED
int host_lifted_count(void)
{
    return LIFTED_COUNT;
}

uint32_t host_lifted_entry(int index)
{
    return LIFTED[index].entry;
}

const char *host_lifted_name(int index)
{
    return LIFTED[index].name;
}

uint32_t host_lifted_run(uint32_t entry, uint32_t esp)
{
    uint32_t ret = 0;
    lift_run_at(&host_vm, entry, esp, &ret);
    return ret;
}

int host_lifted_try(uint32_t entry, uint32_t esp, uint32_t *ret)
{
    uint32_t saved_sp = lift_get_stack();

    nundo = 0;
    trying = 1;
    if (setjmp(try_jb)) {
        trying = 0;
        roll_back();
        lift_set_stack(saved_sp);
        return 1;
    }
    lift_run_at(&host_vm, entry, esp, ret);
    trying = 0;
    nundo = 0;
    lift_set_stack(saved_sp);
    return 0;
}
#else
int host_lifted_count(void)
{
    return 0;
}

uint32_t host_lifted_entry(int index)
{
    (void)index;
    return 0;
}

const char *host_lifted_name(int index)
{
    (void)index;
    return "";
}

uint32_t host_lifted_run(uint32_t entry, uint32_t esp)
{
    (void)entry;
    (void)esp;
    return 0;
}

int host_lifted_try(uint32_t entry, uint32_t esp, uint32_t *ret)
{
    (void)entry;
    (void)esp;
    *ret = 0;
    return 0;
}
#endif

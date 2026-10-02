/* The tables a generated handlers_gen.c defines and the harness reads (tools/lift/gen_handlers.py). */
#ifndef LIFT_TABLES_H
#define LIFT_TABLES_H

#include <stdint.h>

typedef struct LiftedFn {
    const char *name;
    uint32_t entry;                  /* where the original function starts */
    uint32_t (*fn)(uint32_t esp);    /* the lifted function: esp points at the return address, the arguments follow */
} LiftedFn;

typedef struct CalleeRow {
    uint32_t addr;
    int nargs;        /* stack arguments the call passes (from the function index) */
    uint32_t cleanup; /* bytes the callee pops itself (a `ret imm16`), 0 for a cdecl function */
} CalleeRow;

extern const LiftedFn LIFTED[];
extern const int LIFTED_COUNT;
extern const CalleeRow LIFT_CALLEES[];
extern const int LIFT_CALLEE_COUNT;

#endif

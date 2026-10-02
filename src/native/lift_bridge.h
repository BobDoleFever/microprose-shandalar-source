/*
 * lift_bridge.h - lifted card handlers (tools/lift) running inside the native layer.
 *
 * A lifted handler is the original's machine code translated to C over the same registers and memory
 * (lift_rt.h). Built with LIFT_BACKEND_MEM it reads and writes the sparse image (mem.h) the hand-written native
 * functions use, so the two layers share state and a read of memory nothing defined is a fault, as it is for them.
 *
 * The handlers are generated from the user's own executable (tools/lift/gen_handlers.py) and never committed, so this
 * file and lift_bridge.c are the only part of the layer in the repository: a build that has no generated code simply
 * does not link lift_bridge.c, and the layer behaves as before.
 *
 * Calls out of a lifted handler (lift_call in lift_rt.h) are routed by lift_attach's mode:
 *   LIFT_CALLS_HOOK    every call goes to the Vm's hook (the difftest harness replays recorded calls: handlers are
 *                      checked on their own, one at a time)
 *   LIFT_CALLS_NATIVE  a function that has a native implementation runs it, another lifted function runs lifted, and
 *                      anything else goes to the hook
 */
#ifndef NATIVE_LIFT_BRIDGE_H
#define NATIVE_LIFT_BRIDGE_H

#include "engine.h"
#include "lift_tables.h"

typedef enum { LIFT_CALLS_HOOK, LIFT_CALLS_NATIVE } LiftCalls;

/* Make the Vm's memory and hook the ones lifted code uses, and install the card-handler dispatch of vm_call_at. */
void lift_attach(Vm *vm, LiftCalls mode);
void lift_detach(void);

/* Where the lifted code's stack lives while it runs (it needs memory for pushes and locals), and its current top. */
#define LIFT_STACK_TOP 0x7ff00000u
void lift_set_stack(uint32_t top);

/* The generated function that stands for the original at `entry`, or NULL. */
const LiftedFn *lift_find(uint32_t entry);

/* Run the lifted function at `entry` as a call with these cdecl/stdcall arguments; 1 if there is such a function. */
int lift_call_function(Vm *vm, uint32_t entry, int nargs, const uint32_t *args, uint32_t *ret);

#endif

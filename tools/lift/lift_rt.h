/*
 * lift_rt.h - the runtime the lifted x86 code is compiled against (tools/lift/x86lift.py).
 *
 * Lifted code is a mechanical translation of a function's machine code: each instruction becomes C that works on
 * the same registers and the same memory, so there is nothing to guess about types or names. Registers are local
 * variables of the lifted function, memory is the guest address space (a flat array G addressed by the original
 * virtual addresses), and the stack is part of that memory. Flags are computed eagerly after each instruction that
 * sets them (the compiler removes the ones nothing reads). Calls out of the function go through lift_call, which
 * reads the arguments off the guest stack.
 *
 * Only what x86lift.py is able to emit is here: the 32-bit integer subset (no FPU, SSE, string instructions or
 * segment overrides). Anything else makes the lifter refuse the function.
 */
#ifndef LIFT_RT_H
#define LIFT_RT_H

#include <stdint.h>

extern uint8_t *G; /* the guest address space, indexed by lift_xl(virtual address) */

/* The flat harness records every write (a function that stores the value the memory already holds still wrote), and
 * a debug build (LIFT_UNDEF_CHECK) also reports reads of memory that neither the vector nor an earlier write defined. */
#ifdef LIFT_TRACK_WRITES
void lift_chk_write(uint32_t a, uint32_t n);
#define CHK_W(a, n) (lift_chk_write((uint32_t)(a), n), 0)
#else
#define CHK_W(a, n) 0
#endif
#ifdef LIFT_UNDEF_CHECK
void lift_chk_read(uint32_t a, uint32_t n);
#define CHK_R(a, n) (lift_chk_read((uint32_t)(a), n), 0)
#else
#define CHK_R(a, n) 0
#endif

/* Instruction coverage: the debug harness build (LIFT_COVERAGE) records which instructions the vectors executed. */
#ifdef LIFT_COVERAGE
void lift_cov(uint32_t a);
#define LIFT_COV(a) lift_cov(a)
#else
#define LIFT_COV(a) ((void)0)
#endif

/* Where in G a guest address lives. The harness keeps the low 16 MB in place and folds the few high blocks a vector
 * touches (heap, a thread's stack) in behind them. */
uint32_t lift_xl(uint32_t a);

#define RD8(a) (CHK_R(a, 1), *(uint8_t *)(G + lift_xl((uint32_t)(a))))
#define RD16(a) (CHK_R(a, 2), *(uint16_t *)(G + lift_xl((uint32_t)(a))))
#define RD32(a) (CHK_R(a, 4), *(uint32_t *)(G + lift_xl((uint32_t)(a))))
#define WR8(a, v) (CHK_W(a, 1), *(uint8_t *)(G + lift_xl((uint32_t)(a))) = (uint8_t)(v))
#define WR16(a, v) (CHK_W(a, 2), *(uint16_t *)(G + lift_xl((uint32_t)(a))) = (uint16_t)(v))
#define WR32(a, v) (CHK_W(a, 4), *(uint32_t *)(G + lift_xl((uint32_t)(a))) = (uint32_t)(v))

/* Partial registers of a 32-bit register variable r. */
#define LO8(r) ((uint8_t)(r))
#define HI8(r) ((uint8_t)((r) >> 8))
#define LO16(r) ((uint16_t)(r))
#define SET_LO8(r, v) ((r) = ((r) & 0xffffff00u) | (uint8_t)(v))
#define SET_HI8(r, v) ((r) = ((r) & 0xffff00ffu) | ((uint32_t)(uint8_t)(v) << 8))
#define SET_LO16(r, v) ((r) = ((r) & 0xffff0000u) | (uint16_t)(v))

#define MASK(bits) ((bits) == 32 ? 0xffffffffu : ((1u << (bits)) - 1u))
#define SIGNBIT(x, bits) (((x) >> ((bits) - 1)) & 1u)

/* Flag updates: a, b are the operands and r the (masked) result of an operation on `bits` bits. */
#define FLAGS_ZS(r, bits) \
    do { ZF = ((r) & MASK(bits)) == 0; SF = SIGNBIT(r, bits); } while (0)
#define FLAGS_ADD(a, b, r, bits) \
    do { uint32_t m_ = MASK(bits); FLAGS_ZS(r, bits); CF = ((r) & m_) < ((a) & m_); \
         OF = SIGNBIT(~((a) ^ (b)) & ((a) ^ (r)), bits); } while (0)
#define FLAGS_SUB(a, b, r, bits) \
    do { uint32_t m_ = MASK(bits); FLAGS_ZS(r, bits); CF = ((a) & m_) < ((b) & m_); \
         OF = SIGNBIT(((a) ^ (b)) & ((a) ^ (r)), bits); } while (0)
#define FLAGS_LOGIC(r, bits) \
    do { FLAGS_ZS(r, bits); CF = 0; OF = 0; } while (0)

/* Calls out of a lifted function. `argp` is the guest address of the first argument (just above the return address that
 * the call pushed); the result is the callee's EAX. The generated module defines the table it consults. */
uint32_t lift_call(uint32_t target, uint32_t argp, uint32_t *cleanup);

/* An indirect jump whose index fell outside its table (the original's bound check should make this impossible). */
void lift_bad_jump(uint32_t from);

/* Signed division of EDX:EAX by a 32-bit divisor, as IDIV does (the original faults on zero or overflow). */
static inline void lift_idiv32(uint32_t *eax, uint32_t *edx, uint32_t divisor)
{
    int64_t n = (int64_t)(((uint64_t)*edx << 32) | *eax);
    int64_t d = (int32_t)divisor;
    *eax = (uint32_t)(int32_t)(n / d);
    *edx = (uint32_t)(int32_t)(n % d);
}

#endif

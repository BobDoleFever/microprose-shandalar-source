# Lifting card handlers

The question this answers: can the card handlers (the 383 distinct functions the master card table points at, one
per card behaviour) be turned into native code *mechanically*, and proved right against the original, instead of
being rewritten by hand from decompiled C?

The answer here is a **static recompiler for the integer subset of x86**: it reads a handler's machine code out of
the executable and writes C that performs the same instructions on the same registers and memory. There are no types
or names to guess, which is where hand translation of decompiled code goes wrong. The result is checked the way every
native function in this project is: against vectors recorded from the original running in the emulator.

Nothing generated here is committed. The lifted C is derived from the game's machine code, so it goes under
`sources/generated/` (git-ignored) and only the tools are in the repository.

## Pieces

| File | Job |
|---|---|
| `x86lift.py` | the lifter. Recursive-descent over the function's own instructions (the function index's sizes are sometimes short), one C statement block per instruction, eager flags, calls out through `lift_call`. Refuses (`Unsupported`) rather than guess: indirect jumps and calls, segment overrides, anything outside the integer subset |
| `lift_rt.h` | what the lifted C compiles against: registers are locals, memory is `G` addressed through `lift_xl`, flag macros, `lift_idiv32` |
| `lift_tables.h` | the shape of the generated tables (`LIFTED`, `LIFT_CALLEES`) |
| `gen_handlers.py` | reads the handler pointers from the master card table, lifts each distinct handler, writes `handlers_gen.c` and `handler_spec.json` (per handler: size, instruction count, whether it lifted and why not, the exact functions it calls with argument counts and stack cleanup) |
| `make_inject_script.py` | builds the emulator script that runs each handler on demand with the events its own body tests |
| `coverage.py` | how many of the lifted instructions the vectors executed |
| `../difftest/harness_flat.c` | runs a lifted handler on a recorded vector (same line protocol as the native harness) |

## Running it

```
python3 tools/lift/gen_handlers.py --program duel --exe sources/installed/Magic/Program/DUEL.EXE --out sources/generated/lift
make -C tools/difftest flat

# record: the game runs in the emulator; handlers are called on demand (see below)
python3 tools/lift/make_inject_script.py sources/generated/lift/handler_spec.json --all \
    --base "2:dlgsel 1122 59;2.1:dlgsel 1123 59;3:dlg 1;5:dlg 1158;6:dlg 1;43:cast land" > script.txt
cd tools/emu_spike
LIFT_SPEC=../../sources/generated/lift/handler_spec.json RECORD_HANDLER_SPEC=../../sources/generated/lift/handler_spec.json \
    INJECT_RESTORE=0.07 python3 ../difftest/record_vectors.py OUTDIR 6 --exe ../../sources/installed/Magic/Program/DUEL.EXE \
    --seconds N --script "$(cat script.txt)"

# check
python3 tools/difftest/run_vectors.py --harness tools/difftest/build/harness-flat OUTDIR/Handler_*.json
```

`make_inject_script.py --shard I/N` splits the handlers so several recordings can run in parallel (six at once is fine;
each takes about ten minutes).

## How a handler is recorded

A handler is `handler(player, slot, event)`. Waiting for the game to call each of 383 of them naturally would take
forever, so the emulator's `inject HANDLER EVENT NTH K` script operation calls one on a new guest thread with the
event globals set the way the game's own dispatcher sets them. Two things make that safe and repeatable:

* **The game is put back.** The data section is saved before the call and restored 0.07 virtual seconds later, so one
  handler's effects do not change what the next one sees. A handler still running at that point is stopped.
* **Callees are stubbed.** Handlers call into the UI (prompts, animation, waiting for a click), which cannot work on
  an injected thread. Every function the handler calls is patched for the duration to return `K` at once. The
  recorder sees that return value as the call's result, so the vector says exactly what the lifted code is given
  when it makes the same call. The handler's own logic runs for real; callees are mocked. The injection script
  repeats each (handler, event) with several K so both sides of the branches on a callee's result get exercised.

The recorder also keeps reads of stack slots below ESP that the handler had not written (a local read before it is
set holds whatever the stack held), and writes the entry ESP into the vector as `stack_pointer`.

## What a passing vector means

The harness runs the lifted function twice, with all memory the vector does not define filled with two different bytes,
and the runs must agree. Then it compares the return value, every byte stored outside the stack frame, and every call
made (target and all arguments) with the recording. A pass says: given this memory and these callee results, the C does
what the original machine code did.

It does not say the handler is *understood*. Naming and explaining handlers is still the verified-symbols work; the
point of lifting is that correctness does not wait for it.

## Limits

* Ten handlers are refused: nine call `Sleep` through the import table (`call [0x6c3654]`) and one calls another card's
  handler through the master table (`call [eax*4 + 0x4ff5a0]`). Both are small additions (an import is a callee with a
  fixed argument count; the table call is the card scan's dynamic callee). The refusal is by design: the lifter stops
  at anything it cannot translate exactly instead of guessing.
* Callees are mocked, so a handler's behaviour is checked up to its calls. Each callee is a function in its own right
  and gets its own vectors.
* The injection reaches the states a one-card board and a handful of events produce. It is a sample of paths, not a
  proof, and the more situations are recorded the better (see Results for how much of the code that is).

## Results

All 383 distinct handlers of DUEL.EXE's master card table:

| | |
|---|---|
| lifted to C | 373 (97.4%): 350 straight-line and loop code, 23 more once jump tables were supported |
| refused | 10 (see Limits) |
| recorded vectors | 7323, covering all 373 lifted handlers (events from each handler's own body plus four common ones, each with the callees returning 0, 1 and 2) |
| lifted code vs the original | every vector the harness can run matches: return value, every byte stored, every call and its arguments |
| instructions executed by the vectors | 42,194 of 79,016 (53%); 78 handlers fully, every handler at least partly |
| instruction forms | 163 distinct forms executed. Only 31 forms (112 instructions, 0.14%) occur solely in code no vector reached, and each is a variant of an operation that other executed code already covers |

The 53% matters. A passing vector proves the instructions it ran, so the rest is covered only by the fact that the
lifter translates every instruction of a given form the same way. The way to raise the number is more situations (more
cards in play, more callee results, more events), not more handlers.

Getting here found and fixed a lot of faults in the test machinery, none of them in the lifter's treatment of the
instructions that were exercised: the harness compared changed bytes instead of stored bytes (a store of the value
already there was invisible), the recorder missed reads made by the load half of `add [mem], reg` and reads of stack
locals written before use, stack pointers outside the harness's memory, a callee-argument limit of eight when one takes
twenty, and a recording that kept going on a thread that had been killed so the next call's data was attributed to the
wrong handler. The unit tests (`test_lift.py`) found one lifter bug the vectors never reached: `push [esp+4]` read the
operand after ESP had moved.

## Coverage

```
cc -O1 -DLIFT_TRACK_WRITES -DLIFT_COVERAGE -w -Itools/lift -Isources/generated/lift -o tools/difftest/build/harness-flat-cov \
    tools/difftest/harness_flat.c sources/generated/lift/handlers_gen.c
FLAT_COV=cov.txt python3 tools/difftest/run_vectors.py --harness tools/difftest/build/harness-flat-cov OUTDIR/Handler_*.json
python3 tools/lift/coverage.py sources/generated/lift/handlers_gen.c cov.txt
```

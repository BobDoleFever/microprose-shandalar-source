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
| `src/native/lift_rt.h` | what the lifted C compiles against: registers are locals, memory is `G` addressed through `lift_xl`, flag macros, `lift_idiv32` |
| `src/native/lift_tables.h` | the shape of the generated tables (`LIFTED`, `LIFT_CALLEES`) |
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

* A call through the import table is understood for the imports in `KNOWN_IMPORTS` (`Sleep`) only; any other import
  makes the handler refuse. A call through the master table takes its argument count from the recorded call, and
  assumes cdecl, as card handlers are.
* Callees are mocked, so a handler's behaviour is checked up to its calls. Each callee is a function in its own right
  and gets its own vectors.
* The injection reaches the states a one-card board and a handful of events produce. It is a sample of paths, not a
  proof, and the more situations are recorded the better (see Results for how much of the code that is).

## Results

All 383 distinct handlers of DUEL.EXE's master card table:

| | |
|---|---|
| lifted to C | **383 (all)**: 350 straight-line and loop code, 23 more with jump tables, 10 more with calls through the import table (`Sleep`, nine handlers) and the master card table (one handler) |
| refused | none |
| first corpus | 7,323 vectors, events from each handler's own body, callees returning 0, 1 or 2: all match, and run 53% of the lifted instructions |
| grown corpus | about 86,000 more vectors from `grow_coverage.py` (random events, a different result for each function the handler calls, the handler's own card in play, slot fields and other cards' zones filled with arbitrary values, and the globals the handler is gated on set to the values it tests for): all match |
| instructions executed | 70,451 of 82,074 (**85.8%**); 141 handlers fully, every handler at least partly. Four of the nine `Sleep` handlers and the table-call handler have vectors that reach their call; the other five do not yet |
| instruction forms | 188 distinct forms executed; 6 forms (10 instructions) occur only in code no vector reached |

Every vector the harness can run matches the original: return value, every byte stored outside the stack frame, and
every call made with its arguments, under four fills of the memory the vector does not define. The vectors are not
committed (they hold the game's memory); the driver keeps the 904 that each added coverage.

A passing vector proves the instructions it ran, so the remaining 14% is covered only by the lifter translating every
instruction of a given form the same way. What is left is
mostly code behind several conditions at once (a card state, an event, a callee result and a global together) that random
search reaches slowly; `grow_coverage.py` gains about 0.3 points per 25-minute round now, against 5 at the start.

Getting here found and fixed a lot of faults in the test machinery, none of them in the lifter's treatment of the
instructions that were exercised: the harness compared changed bytes instead of stored bytes (a store of the value
already there was invisible), and two fills could agree by luck (`cmp x, 2; jl` gives the same answer under fills of
0x00 and 0xff), so there are four; the recorder missed reads made by the load half of `add [mem], reg` and reads of
stack locals written before use (it now keeps the stack frame as the call found it); stack pointers outside the
harness's memory; a callee-argument limit of eight when one callee takes twenty; a recording that carried on after its
thread was killed and attributed the next call's data to the wrong handler; callee stubs that did not take effect for
functions the game had already run (Unicorn kept the translated original: the cache is now cleared after patching),
which dropped a callee's writes into the caller's locals. Several of these showed up as a handful of vectors that
failed, which is what the differing-vector folder is for. The unit tests (`test_lift.py`) found one lifter bug the
vectors never reached: `push [esp+4]` read its operand after ESP had moved.

## As part of the native layer

The lifted code is also built against the sparse memory image of `src/native/mem.h` (`LIFT_BACKEND_MEM`), where it
shares state with the hand-written native functions. `src/native/lift_bridge.c` routes a lifted function's calls: to a
native function if there is one for that address, to another lifted function, or to the Vm's hook (the difftest harness
replays recorded calls there; hosted in the emulator it would call the original). `native_handler_dispatch` in
`engine.c` is how the native card scan runs a card's handler as lifted code instead of calling out for it.

```
python3 tools/lift/gen_handlers.py --program duel --exe sources/installed/Magic/Program/DUEL.EXE --out sources/generated/lift
make -C tools/difftest lifted                    # build/harness-lifted
python3 tools/difftest/run_vectors.py --harness tools/difftest/build/harness-lifted OUTDIR/Handler_*.json
```

The generated code is derived from the user's own executable, so a build that has not run `gen_handlers.py` does not link
the bridge and the native layer behaves as before.

### What was checked, and how

1. **Each handler on its own** in the native harness (strict memory: a read of a byte nothing defined is a fault): the
   kept vectors of the coverage driver and the first corpus, 2,200+ vectors, all match.
2. **The native scan with the handlers running lifted inside it**, against the original, on boards of arbitrary cards
   (`winemu/run.py` `scan EVENT SEED [K [CARDS]]`: up to a dozen cards with random handlers in play, fields filled with
   arbitrary values, every function a handler can call made to return a value from the seed; recorded with
   `RECORD_LIFTED_HANDLERS=1`, which makes the handlers transparent as nested native calls are). 2,065 scans, all match;
   they reach 382 of the 383 handlers. A native function or lifted handler that the original's real version would
   disagree with shows up here, and the fuzz found two faults of the test setup and one of the bridge (below).
3. **The native functions on the same fuzzed boards** (`callfn ADDR SEED K ARGS...`): 2,362 calls of
   `Magic_QueryCardAttribute`, `Magic_IsManaSource`, `Card_IsInPlay` and `Card_GetColorAndTypeFlags`, and 1,650 of the
   three colour-remap lookups, all match the original. These were verified before only against calls the game made
   by itself; fuzzed boards are a much wider sample.

What the fuzz found: stubbing a function that is also the one under test (or one of the natives, or a handler another
handler calls) made the *original* return early, so the original's recording was wrong, not the native layer; and the
bridge placed the stack frames of lifted code that a native function re-enters (a query scans the cards, which runs
handlers) over the locals of the handler that called it, so a loop counter in a handler was overwritten. The first two
were found by `tools/lift/scan_diff.py`, which runs a failing scan with `LIFT_TRACE` and lines up, handler by handler,
what the lifted run called and what memory held against what the recording says (`RECORD_DUMP`, `RECORD_NATIVE_TRACE`).

## Growing the coverage

```
python3 tools/lift/grow_coverage.py --out DIR --hours 6
```

Records in `--workers` emulators at once (each spends its first few minutes playing the game up to a board it can inject
on), checks every vector through the lifted code with coverage on, keeps the ones that executed something new in
`DIR/keep`, and puts any vector the lifted code does not match in `DIR/fail` with the harness's message. It can be
stopped and started again. Each round aims at the handlers with the most uncovered instructions: the globals a handler
compares (and the slot fields, and the event codes) are found in its lifted code, so injections set them to what it
tests for. An emulator that stops producing vectors (the game wedged on some state) is cut off and only its own chunk
is lost.

## Coverage of a corpus

```
cc -O1 -DLIFT_TRACK_WRITES -DLIFT_COVERAGE -w -Isrc/native -Isources/generated/lift -o tools/difftest/build/harness-flat-cov \
    tools/difftest/harness_flat.c sources/generated/lift/handlers_gen.c
FLAT_COV=cov.txt python3 tools/difftest/run_vectors.py --harness tools/difftest/build/harness-flat-cov OUTDIR/Handler_*.json
python3 tools/lift/coverage.py sources/generated/lift/handlers_gen.c cov.txt
```

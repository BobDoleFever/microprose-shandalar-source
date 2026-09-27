# Difftest vectors

A **vector** is one call of one original game function, recorded as data: the memory the function
read, its arguments, the calls it made to other functions, its return value, and the memory it left
behind. The difftest harness runs the **native** replacement of the same function (`src/native/`) on the
same inputs and checks that it produces the same outputs. This is Phase B of `docs/PORT_STRATEGY.md`
(replace verified functions one at a time, each checked against the original), without needing the game
files at test time: the original only has to run once, when the vector is recorded.

Seed vectors are hand-made from the numbers in `docs/SYMBOL_VERIFICATION.md`
(`make_doc_vectors.py` writes `vectors/doc_*.json`). The real supply is meant to come from tracing the
original in the emulator (below); that tracer is not part of this folder yet.

## The format

One JSON object per file in `tools/difftest/vectors/`. Numbers are JSON integers or strings (`"0x006826c4"`,
`"-1"`); negative values are two's complement and everything is 32-bit. An abridged example (a runnable
vector also lists every other byte the function reads; see `vectors/doc_query_power_elves_recompute.json`):

```json
{
  "function": "Magic_QueryCardAttribute",
  "program": "DUEL",
  "address": "0x0048b81a",
  "description": "Llanowar Elves, code 0x32 (power)",
  "source": "docs/SYMBOL_VERIFICATION.md, Magic_QueryCardAttribute codes",
  "args": [0, 3, 50, -1],
  "memory_in": [
    {"addr": "0x00682a24", "dwords": ["0x00000038"]},
    {"addr": "0x005000fa", "bytes": "0100"}
  ],
  "calls": [
    {"callee": "0x0048a33f", "name": "Duel_CardIsTapped", "args": [0, 3], "return": 0,
     "memory_writes": []}
  ],
  "expected_return": 1,
  "memory_out_expected": [
    {"addr": "0x0066642c", "dwords": [1]}
  ],
  "memory_out_exhaustive": true
}
```

| Field | Required | Meaning |
|---|---|---|
| `function` | yes | the verified name of the original function; the harness has a native implementation under this name (`NATIVE_FUNCTIONS` in `src/native/engine.c`) |
| `program` | yes | `MAGIC` or `DUEL`: which program's addresses the vector uses. Both carry the same engine at different addresses (`src/native/layout.c`) |
| `args` | yes | the stack arguments, in order, as 32-bit values |
| `memory_in` | yes (may be empty) | the snapshot. Each region is `{addr, dwords}` (little-endian 32-bit values) or `{addr, bytes}` (a hex string or a list of byte values). Only these bytes exist: see "Undefined memory" |
| `expected_return` | yes | EAX when the function returned. Compared on the function's return width (below) |
| `memory_out_expected` | yes (may be empty) | regions (`dwords` or `bytes`) whose contents must match after the call. Regions not listed are not compared, unless `memory_out_exhaustive` is set |
| `address` | no | the function's entry address in `program`. If given, it must match the harness's layout, which catches a vector recorded from the wrong function |
| `calls` | no | every call the function makes to a function that is not native, in order (see "Calls") |
| `memory_out_exhaustive` | no | when true, every byte the native code changed must lie in a `memory_out_expected` region. Recorded vectors should set it: then an extra write is a failure too |
| `return_bits` | no | overrides the return width: 8, 16 or 32 |
| `description`, `source` | no | for people: what the vector shows and where its numbers come from |

### Undefined memory

The harness's memory image (`src/native/mem.h`) is sparse and addressed by the original virtual
addresses, so native code keeps using the original globals (`0x006764b8` is still the spell-stack count).
A byte exists only if `memory_in` or a replayed call defined it, or the native code wrote it. **Reading any
other byte fails the vector** and names the address: a vector must contain everything the function reads,
and a native function must not read more than the original did.

### Calls

Native functions call functions that are not native yet through a hook (`vm_call` in
`src/native/engine.h`). In the harness the hook **replays** the vector's `calls` list in order:

- `callee` is the callee's address in `program`. Names are labels only (several decompiler names of these
  callees are wrong: `Card_SetTapState` is a colour-override lookup), so the address is what is compared.
- `args` are the stack arguments the original passed. The native code's must be equal.
- `return` is what the callee returned in EAX, handed back to the native code.
- `memory_writes` are the callee's side effects (regions like `memory_in`), applied before it returns, so
  the native code sees what the original saw. Memory the callee only *read* is not needed.

A call to a different address, a call beyond the end of the list, or a list entry that is never reached
fails the vector. Later, hosted in the emulator, the same hook can call the emulated original instead of
replaying.

### Return width

`Magic_IsManaSource` returns a C `bool` in AL; the rest of EAX is whatever was there. The harness knows
each native function's width (`ret_bits` in `NATIVE_FUNCTIONS`) and compares only those bits.
`return_bits` in a vector overrides it.

## Running

```bash
python3 tools/difftest/run_vectors.py              # all vectors; builds tools/difftest/build/harness if needed
python3 tools/difftest/run_vectors.py -v a.json    # also list the calls and writes of each vector
python3 tools/difftest/run_vectors.py --strict     # UNIMPLEMENTED counts as a failure
make -C tools/difftest                             # build the harness with the full warning set
make -C tools/difftest asan                        # build/harness-asan, with AddressSanitizer and UBSan
python3 -m pytest tools/difftest                   # the pipeline's own tests (needs pytest)
python3 tools/difftest/record_vectors.py OUT N --exe ... --seconds N --script "..."  # record from the original
```

Each vector is **PASS**, **FAIL** (with every difference: return value, calls, undefined reads, memory),
**UNIMPLEMENTED** (the native function reached a path it asserts it does not cover, such as query codes
0x35 and 0x36), or **ERROR** (the vector is malformed, names a function with no native version, or gives
the wrong entry address). The exit status is 1 if any vector failed or errored.

The runner turns each vector into a small line protocol for the harness (documented at the top of
`harness.c`), one process per vector, so an assert in one vector cannot affect another.

## Recording vectors from the original

`record_vectors.py` does this. It hooks every native function's entry in a running `tools/emu_spike`
`Machine` (the same Unicorn instance that runs the original game unmodified) and, for a sampled call:

1. **At entry**, reads the stack arguments (their count comes from `NATIVE_FUNCTIONS`, mirroring
   `src/native/engine.c`) and notes the return address and ESP.
2. **While the function runs** (until EIP reaches the return address with ESP back above it), logs memory
   accesses with `UC_HOOK_MEM_READ` and `UC_HOOK_MEM_WRITE`:
   - a byte **read** that it (or a callee) has not written earlier in this call goes to `memory_in`, with
     the value it had;
   - every byte **written** goes to `memory_out_expected`, with its final value, and
     `memory_out_exhaustive` is set;
   - accesses to the caller's stack frame (between the entry ESP and the arguments) are left out: native
     code keeps its locals in C variables.
3. **Calls**: when control leaves the function to one of `CALLEES_INFO`'s addresses, it records the
   target and its stack arguments, then hooks the return address for EAX. Writes made while inside the
   callee go to that call's `memory_writes`; reads made inside the callee are not recorded.
4. **At return**, EAX is `expected_return`, and `function`/`program`/`address`/`source` (with the virtual
   time) are written so a failing vector can be reproduced.

`record_vectors.py`'s function and callee tables (`NATIVE_FUNCTIONS`, `CALLEES_INFO`) are checked against
`src/native/engine.h`'s `NativeFn`/`Callee` enums and both programs' `layout.c` tables by
`test_record_vectors_tables_match_native_code` in `test_difftest.py` (no unicorn or game files needed),
so adding a native function without updating the recorder fails that test rather than silently recording
nothing for it.

```bash
python3 tools/difftest/record_vectors.py OUTDIR MAX_PER_SITUATION --exe path/to/DUEL.EXE --seconds N --script "..."
```

needs the user's own copy of the game (see `tools/emu_spike`'s own docs); the vectors it writes are plain
numbers, not game assets, and are fine to commit (`vectors/recorded_*.json` in this repo were made this
way, from a mono-green mirror match and a game against a red AI deck).

A call is skipped once `MAX_PER_SITUATION` examples of its "situation" (`Recorder.situation_key`, a rough
bucket on the slot's flags, its card's colour and type, and whether the AI is thinking) have been recorded,
so a long game yields a manageable regression suite rather than one vector per call of the card-attribute
query's roughly 350,000 calls in a single scripted turn.
times in one game).

## Adding a native function

1. Write it in `src/native/` from the decompiled body in `magic/magic_unified.c`, checked against its
   `DUEL.EXE` twin (`tools/twins/twins.csv`), reading every global through the layout and every non-native
   callee through `vm_call`. Keep the order of reads and calls the original has: a vector records what the
   original read, and a read the original did not make is undefined memory.
2. Add its globals and callees to `Layout` in `engine.h` and their addresses for both programs in
   `layout.c`, each read off the decompiled body in that program (symbol names in the maps are not
   reliable enough: several `DUEL.EXE` field names point at neighbouring fields).
3. Add it to `NATIVE_FUNCTIONS` with its argument count and return width.
4. Add vectors. A path the native version does not cover calls `NATIVE_UNIMPLEMENTED`, which asserts.

## What is native today

| Function | MAGIC.EXE | DUEL.EXE | Not covered | Callees replayed |
|---|---|---|---|---|
| `Magic_QueryCardAttribute` | `0x00473179` | `0x0048b81a` | codes 0x35, 0x36 and any code other than 0x32, 0x33, 0x34, 0x3c assert | `Magic_ScanCards`, `Card_IsTapped`, the two colour overrides, `Pic_Subsystem_0044867e`, `Pic_Subsystem_004488a0`, the event-context push and pop |
| `Magic_IsManaSource` | `0x00474389` | `0x0048ca2a` | | |
| `Magic_DropTopSpell` | `0x00475bb0` | `0x0048e251` | | |
| `Magic_PushSpellStack` | `0x004751d7` | `0x0048d878` | | the free-slot finder `Pic_Subsystem_00451291` |
| `Magic_ClearSpellStack` | `0x00474d1e` | `0x0048d3bf` | | |
| `Card_GetColorAndTypeFlags` | `0x004d0a42` | `0x004521e2` | | `Card_ColorMaskToColorIndex`, the `+0xf9` colour override |

The original's default case of the query (any other code returns 0 through the card scan) is not in the
verified set and asserts too; no call site passes such a code.

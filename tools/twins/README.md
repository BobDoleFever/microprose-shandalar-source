# MAGIC.EXE / DUEL.EXE function twins

`MAGIC.EXE` and `DUEL.EXE` contain the same duel engine at different addresses
(`docs/SYMBOL_VERIFICATION.md`). `find_twins.py` pairs every `MAGIC.EXE` function in
`magic/magic_unified.c` with its likely twin in `duel/duel_unified.c` and writes `twins.csv`.

```bash
python3 tools/twins/find_twins.py        # about 20 s; rewrites tools/twins/twins.csv
python3 -m pytest tools/twins            # needs pytest; the tool itself is standard library only
```

Names are never compared: they are unreliable in both programs, and in `DUEL.EXE` two different
functions once shared one. Each body is normalised (locals and parameters, globals, calls to the
program's own functions, image addresses and string labels are masked) and candidates are scored on
the edit-distance ratio of the statement lines, token 5-gram overlap, body size, call-graph shape,
Win32 calls, string literals and constants, then on call-graph agreement with the confident pairs of a
first pass.

`twins.csv` columns: `magic_addr`, `duel_addr`, `score`, `second_best_score`, `evidence`. The evidence
starts with a verdict, and rows are grouped by it:

| Verdict | Meaning |
|---|---|
| `twin` | score at least 0.70 and more than 0.02 above the runner-up |
| `weak` | a clear best, but scoring 0.55 to 0.70 |
| `ambiguous` | the runner-up is within 0.02 (`close=`), or the DUEL function matches another MAGIC function as well (`contested-by=`; identical copies exist). Do not take `duel_addr` as the twin |
| `no-twin` | best score below 0.55: probably `MAGIC.EXE`-only code such as the overworld |

Current run: 1,924 `MAGIC.EXE` functions, 1,293 `twin`, 29 `weak`, 182 `ambiguous`, 420 `no-twin`.

**Checks.** All 8 verified pairs in `KNOWN_PAIRS` are found at rank 1 (8/8), and `SpellChain_WndProc`
(`0x004cdb4f`) goes to `0x0049fc0f`, not to `0x00493e30`, which once shared its name. The 27 other twin
addresses listed in `SYMBOL_VERIFICATION.md` (not used for tuning the tests) come out 26 at rank 1;
the miss is `Card_DefaultEventHandler` (`xor eax,eax; ret`), which has several identical copies in
`DUEL.EXE` and is correctly marked `ambiguous`.

A pair here is a static resemblance, not a verification: confirm a twin on the emulator before
renaming anything on the strength of it.

## Carrying names across: `propagate.py`

```bash
python3 tools/twins/propagate.py         # rewrites tools/twins/propagation.md (under a second)
python3 -m pytest tools/twins/test_propagate.py
```

For every `twin` row it compares the names in `magic/function_index.csv` and `duel/function_index.csv` and
lists, in `propagation.md`: pairs where only MAGIC.EXE has a semantic name, the reverse, pairs where both
have different semantic names, and DUEL.EXE names carried by more than one address with a twin among them
(cross-referenced with `tools/registry/duplicates.md`). Generic means `FUN_`, `..._Subsystem_<hex>` or a
name ending in an 8-digit address (its own or another: copied auto-labels end in the twin's address).
Every semantic name is marked **verified** only when `tools/registry/verified_names.csv` has it at that
address, and **UNVERIFIED** everywhere else; notes flag names shared by several DUEL.EXE addresses and C
files whose names the index has not caught up with. It renames nothing.

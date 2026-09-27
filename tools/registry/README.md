# Verified-name registry

`docs/SYMBOL_VERIFICATION.md` records, in prose and tables, which names were checked against the running
game. This folder turns its tables into a registry and checks the repository against it. Standard
library only; nothing here renames anything.

```bash
python3 tools/registry/build_registry.py   # doc -> verified_names.csv + parse_report.md
python3 tools/registry/check_registry.py   # exit 1 if a verified name is missing at its address
python3 tools/registry/audit_names.py      # duplicates.md + generator_hits.md
python3 -m pytest tools/registry           # needs pytest
```

| File | What |
|---|---|
| `verified_names.csv` | `program` (MAGIC/DUEL), `address`, `name`, `kind` (function/global), `evidence`, `section` (the doc heading), `notes` (old names, confidence, where the evidence grade came from) |
| `parse_report.md` | tables with no names (skipped), rows that could not be read, and named addresses the doc mentions outside its name tables |
| `duplicates.md` | function names carried by more than one address in one program's `function_index.csv`, marked where a verified name or address is involved |
| `generator_hits.md` | lines in `scripts/*.py`, `scripts/*.java` and the root symbol maps that tie a registry address to another name |

## How the doc is read

Every table with an address column and a new-name column (`Now`, `New name`, or `Called` written as
`old -> new`) is a name table; the other seven tables (step codes, traces, bit meanings) are skipped
and listed in `parse_report.md`. A `MAGIC.EXE / DUEL.EXE` address cell gives one row per program
(`none` means no twin). A cell like `0x681eb0` (`0x006a4a08`) under "`DUEL.EXE` addresses; the
MAGIC.EXE global ... in brackets" gives a DUEL row and a MAGIC row. Otherwise the program comes from the
paragraph right above the table, or the nearest heading that names one program.

`evidence` is the strongest grade the row states: `natural`, `synthetic` (the doc's "injected" is
counted as synthetic), `static`, or `qemu` for the live runs on the original game under QEMU (the doc's
"verified, live" before the in-process emulator section). A few rows are upgraded from prose, each
quoting its sentence in `registry.py` (`EVIDENCE_OVERRIDES`), for example "The step runner and
`g_CurrentStepCode` are **verified live**". The `notes` column says where each grade came from.

## Checks

`check_registry.py` compares each function row with `<program>/function_index.csv`, and each global
row with `engine_globals_map.csv` (or `<program>/symbols.csv` when the map has no entry). It exits 1 on any
mismatch. It currently finds none (it found two when it was written, DUEL `0x0048d00c` and MAGIC `0x006a3f78`,
which are fixed). `test_registry.py` keeps a `KNOWN_DRIFT` set, empty now, and fails if the checker finds anything
not listed there, or no longer finds something that is: real drift can be recorded, and a fixed entry cannot linger.

The two table rows that cannot be read give the DUEL twin as "(twin shares a name)" (`SpellChain_InsertEntry`
and `SpellChain_RebuildEntryTargets`). The doc's prose says the two DUEL twins share
`Palette_Subsystem_0049608e`, and `tools/twins/twins.csv` pairs them with `0x004a1bf7` and `0x004a1f15`,
but neither is written in the table, so they are not registered.

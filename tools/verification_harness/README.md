# Verification Harness

Automated differential-testing tooling for checking the modern port's behavior against
the original 1997 binaries, without requiring anyone to manually play the game.

See [`docs/VERIFICATION_HARNESS_PLAN.md`](../../docs/VERIFICATION_HARNESS_PLAN.md) for
the full design and roadmap. This directory holds the Phase 0 pieces — the parts that
don't need Wine, MinGW, Frida, or the original discs to build and test.

## Layout

- `input_schema.py` — JSON schema + validator for scripted input event sequences.
- `monkey_policy.py` — deterministic, seeded decision policy that generates an input
  script without any human playthrough or real AI.
- `state_snapshot.py` — data model for the per-tick state record we diff between the
  port and the original (field list cross-referenced against `engine_globals_map.csv`
  and `include/shandalar/*.h`).
- `divergence_bisect.py` — binary-search over a divergence between two tick-indexed traces, to
  localize the earliest tick (and therefore the responsible function) automatically.
- `orchestrator.py` — drives a run and produces a trace. Currently only wired up
  against the port binary (`build/shandalar`); the Wine/original-binary side is stubbed
  pending Phase 1/2 (toolchain + discs).
- `oracle_launch.sh`, `oracle_qemu.py` — boot the Windows 98 oracle under QEMU and drive it (QMP
  keys/screenshots, gdbstub breakpoints/memory). See `docs/ORACLE_VM.md`.
- `probe_drawcard.py` — first oracle experiment (see `docs/SYMBOL_VERIFICATION.md`).
- `tests/` — unit tests for everything above that doesn't require the real toolchain.

## Running the tests

```sh
cd tools/verification_harness
python3 -m unittest discover tests
```

## What's real vs. stubbed right now

| Piece | Status |
|---|---|
| Input schema + validator | Real, tested |
| Monkey policy generator | Real, tested (pure logic, no game needed) |
| State snapshot data model | Real, tested (structure only — no live memory reads yet) |
| Bisection algorithm | Real, tested against synthetic traces |
| Orchestrator → port | Skeleton — port binary doesn't yet expose a scriptable input/state API to drive it against; see TODOs in file |
| Orchestrator → original binary (Wine) | Stub only — needs `wine-stable`, `mingw-w64`, the clock-override shim DLL, and a legally obtained copy of the game |
| Frida-based function tracing | Not started — Phase 2 |

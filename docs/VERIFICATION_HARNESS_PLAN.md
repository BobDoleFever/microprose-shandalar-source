# Automated Verification Harness — Design & Roadmap

## Why this exists

The decompilation in this repo has two very different layers of trustworthiness:

1. **Raw decompiled control flow and constants** — mechanically produced by Ghidra from
   the real binaries. This is almost certainly accurate at the instruction level.
2. **Human-readable names, types, and doc comments** — added afterward by a bulk
   automated pass (1,650+ function renames, 268+ global renames, ASD-STE100 comments,
   the AI FAQ, etc.) in a matter of days, with no verification loop against actual
   program behavior.

Layer 2 is demonstrably unreliable in specific, checkable ways:

- [`src/magic/sid/Magic.c`](../src/magic/sid/Magic.c) names a function `Magic_DrawCardPhase`
  and comments it as drawing a card from the library. The actual body loops over
  artifact `.wav` filenames and preloads sound effects — it is not a draw-phase function.
- [`src/magic/sid/glue_adventure.c`](../src/magic/sid/glue_adventure.c) assigns
  `g_CampaignDifficultyLevel` and `g_OverworldPlayerDirection` from the return values of
  `Pic_Load_menu2_hi_...` / `Pic_Load_menu3_but1_...` — image/UI loader calls, not
  gameplay state.
- [`docs/SHANDALAR_AI_FAQ.md`](SHANDALAR_AI_FAQ.md) makes specific factual claims about
  AI behavior (fog-of-war respect, hand-slot flag meanings) in the same confident,
  unverified voice.

Goal precedent: **DevilutionX**. Their port is trustworthy because every recovered
function was checked against the real `.exe`'s actual behavior before being renamed or
relied on — not because the decompiler produced good names on its own. We don't have
that verification yet. This harness is how we get it, without requiring anyone to sit
and manually play through the game to generate test cases.

## Non-goals

- This harness does not need to "play well." A dumb, deterministic, seeded policy that
  always takes the first legal action is sufficient — we're testing **behavioral
  equivalence between two implementations**, not game-playing skill.
- We are not trying to prove the whole game is correct in one pass. We're building a
  tool that we run repeatedly, subsystem by subsystem, as we work through the codebase.

## Architecture — four layers

### Layer 1: Deterministic virtual clock (foundation, blocks everything else)

Both the real binary (under Wine) and the port read real-time clocks
(`GetTickCount`, `timeGetTime`, `QueryPerformanceCounter`) for animation and input
pacing. Two runs will never line up frame-for-frame against wall-clock time. Before any
comparison is possible, both sides must run off a **logical tick counter** we control.

- **Port side**: already ours — [`src/platform/win32_compat.c`](../src/platform/win32_compat.c)
  intercepts these calls; add a "harness mode" that advances the tick counter only when
  the orchestrator tells it to.
- **Real binary side**: inject a small shim DLL via `WINEDLLOVERRIDES`, exporting
  replacements for the same timing entry points, driven by the same external tick
  source (e.g. a small IPC channel — a local socket or named pipe — the orchestrator
  writes to).

This cannot be fully built or tested without Wine installed and a real binary to run
against, but the DLL source and the tick-sync protocol can be written now.

### Layer 2: Synthetic deterministic input driver ("the monkey")

A scripted, seeded decision policy, not a human and not a real AI:

- Menu/dialog navigation: fixed coordinate sequences (recoverable from the decompiled
  UI code in `glue_adventure.c` / `glue_duel_ui.c` — the dialog layout constants are
  part of Layer 1's "trustworthy raw logic," even where names are wrong).
- In-duel decisions: a simple deterministic rule ("first legal action," "attack with
  everything," "cast cheapest castable spell") parameterized by a seed, so we can run
  many varied but fully reproducible sessions.
- Delivered as a **script file** (see format below) replayed as a sequence of
  `(logical_tick, message)` pairs into both processes' message queues.

Input script format (JSON, draft):

```json
{
  "seed": 12345,
  "events": [
    { "tick": 0,   "type": "WM_LBUTTONDOWN", "x": 320, "y": 240 },
    { "tick": 4,   "type": "WM_LBUTTONUP",   "x": 320, "y": 240 },
    { "tick": 20,  "type": "WM_KEYDOWN",     "vk": "VK_RETURN" }
  ]
}
```

This can be designed and the replay-side code written now, against the port only
(which we can already drive), even before the real binary is in the loop.

### Layer 3: State snapshot + diff

At each checkpoint tick, dump known global state from both processes and compare:

- We already have static addresses and struct layouts recovered from Ghidra
  (`MasterCardRecord`, `g_ActiveCardsInPlay`, board/hand/life globals, etc. — see
  `engine_globals_map.csv`, `include/shandalar/cards.h`).
- Read raw memory at those addresses from both the live Wine process and the port
  process, hash/serialize into a comparable structured record, and diff.
- First divergence between two runs = either a bug in our port or a mislabeled/incorrect
  piece of decompiled logic. Either way, it's now a concrete, localized, reproducible
  finding instead of a vague suspicion.

### Layer 4: Bisection + targeted Frida tracing

- **Bisection**: when two runs diverge, re-run with checkpoints at finer granularity to
  binary-search the exact tick where state first differs. This localizes the problem to
  a small window of execution automatically.
- **Frida tracing**: once localized, attach Frida to the live process (it's a normal OS
  process even under Wine; hook by runtime-adjusted address) and log a single function's
  entry/exit args and memory touches. Used surgically on a handful of suspect functions
  per session, not broadly.

## Toolchain

| Piece | Tool | Status on this machine |
|---|---|---|
| Windows cross-compiler | `mingw-w64` (`i686-w64-mingw32-gcc`) | not installed — in `Brewfile` |
| Run original binaries | `wine-stable` | not installed — in `Brewfile` |
| Dynamic instrumentation | Frida (`frida-tools`, pip) | not installed |
| Orchestration | Python 3 | installed (`/opt/homebrew/bin/python3`) |

`brew bundle` (already specified in this repo's `Brewfile`) plus `pip install
frida-tools` covers everything. None of this needs the discs.

## Phased roadmap

**Phase 0 — no discs, no toolchain needed (can start immediately)**
- [ ] This design doc.
- [ ] Input script JSON schema + a validator.
- [ ] Deterministic "monkey" policy skeleton (pure logic, unit-testable on its own).
- [ ] State-diff data model: define the canonical "snapshot" struct we'll compare,
      cross-referenced against `include/shandalar/*.h` and `engine_globals_map.csv`.
- [ ] Orchestrator skeleton (drives the port only, since we already control it fully).
- [ ] Bisection algorithm, unit-tested against synthetic divergent traces.

**Phase 1 — toolchain, no discs needed**
- [ ] `brew bundle` (mingw-w64, wine-stable), `pip install frida-tools`.
- [ ] Verify `make pe-toolcheck` passes.
- [ ] Write and test the Wine clock-override shim DLL against a trivial test EXE (not
      the real game) to prove the interception mechanism works.

**Phase 2 — discs required**
- [ ] Get `MAGIC.EXE` (and companions) actually booting under Wine at all.
- [ ] Wire the clock shim into a real run.
- [ ] Record the first real port-vs-original diff on a short, scripted sequence
      (e.g. boot to main menu).
- [ ] Expand scripted sequences subsystem by subsystem, prioritizing duel/AI logic
      over UI chrome.

## Current status

Phase 0, item 1 (this document) — in progress. See `tools/verification_harness/` for
scaffolding of the remaining Phase 0 items.

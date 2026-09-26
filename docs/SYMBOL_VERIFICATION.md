# Symbol verification log

Each entry records what the live oracle (see [ORACLE_VM.md](ORACLE_VM.md)) showed about a name
or comment produced by the bulk rename pass. A name is only trustworthy once it appears here as
**verified**. Everything else is a hypothesis.

## Magic_DrawCardPhase (MAGIC.EXE 0x00474c7f): unverified, evidence against

Claim in the repo: `src/magic/sid/Magic.c` says it executes the draw step.
Decompiled body: loops 0x14 times building `g_DuelSoundsDirectory + <name>.wav` and calling
`Pic_Subsystem_00423b57(path, i, 0)`, i.e. it looks like a sound preloader.

Oracle result (`tools/verification_harness/probe_drawcard.py`, 300 s from cold boot to the game's
main menu, breakpoints on the function and on the callee):

- The function never ran (startup and main menu).
- The callee ran 15 times, always from `0x004ec64b` (outside the function), passing walking
  sounds: `kwalkl`, `kwalkr`, `bwalkl`, `bwalkr`, `gwalkl`, `gwalkr` (all under `C:sound\`).

What this does and does not show:

- It does not prove the label wrong: a real draw step would also be silent until a duel starts.
- The decomp's own README lists duels as the job of `DUEL.EXE`, a separate process. A draw phase
  in `MAGIC.EXE` (the overworld program) is therefore doubtful on its face.
- Caution for all future probes: every program loads at `0x00400000`, so a breakpoint address means
  different code in `DUEL.EXE`. Check the code bytes at the address before trusting a hit.

Next: start a duel and see whether the function ever runs (it should if the label is right), then
locate the real draw logic, most likely in `DUEL.EXE`.

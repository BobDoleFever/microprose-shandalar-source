# Symbol verification log

Each entry records what the live oracle (see [ORACLE_VM.md](ORACLE_VM.md)) showed about a name
or comment produced by the bulk rename pass. A name is only trustworthy once it appears here as
**verified**. Everything else is a hypothesis.

## Magic_DrawCardPhase (MAGIC.EXE 0x00474c7f): WRONG LABEL, it preloads duel sound effects

Claim in the repo: `src/magic/sid/Magic.c` says it executes the draw step.

Oracle evidence (`probe_drawcard.py`, `probe_duel_start.py`, all on the live game):

1. From cold boot to the main menu the function never ran.
2. Clicking "Duel a Sorcerer" runs it during the duel-loading splash (a card back on a black
   screen). Once its page was resident, the code at `0x00474c7f` matched the `MAGIC.EXE` file
   byte for byte (`55 8b ec 81 ec 2c 01 00`), so this is `MAGIC.EXE` and not `DUEL.EXE`.
   It was called from `0x00495bbc`, inside `Palette_Subsystem_00495958` (0x495958 to 0x495cde;
   that name is also an unverified auto-label).
3. The 20 names it loads (table at `0x00525788`, read from the binary) are duel sound effects:
   artifact, buried, draw, enchant, endphase, endturn, instant, interupt, GREY, BLACK, BLUE,
   GREEN, RED, WHITE, lifeloss, sacrfice, sorcery, summon, tap, untap. One of them is `draw.wav`,
   which probably explains the mislabel.

Verdict: it is a duel sound-effects preloader run once when a duel starts. A better name is
something like `Duel_PreloadSoundEffects`. It has not been renamed in the source yet.

Method notes (they cost real time):

- **Code pages are demand-loaded.** The first time a function runs, a breakpoint on it can fire
  before its page is in memory, and reading the code bytes fails with `E14`. Step over the
  breakpoint (this takes the page fault), re-arm, continue: the retried instruction hits again
  with readable code. `GDBRemote.resume` already does the step-over.
- **Every program loads at `0x00400000`**, so an address alone does not identify the program.
  Compare code bytes with the file in `sources/installed/Magic/Program` before trusting a hit.
- Where the real draw logic lives is still unknown; `DUEL.EXE` is the likely place.

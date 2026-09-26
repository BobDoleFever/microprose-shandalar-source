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

Verdict: it is a duel sound-effects preloader run once when a duel starts. Renamed to
`Duel_PreloadSoundEffects` (and its invented doc comment corrected) everywhere in the repo.

Method notes (they cost real time):

- **Code pages are demand-loaded.** The first time a function runs, a breakpoint on it can fire
  before its page is in memory, and reading the code bytes fails with `E14`. Step over the
  breakpoint (this takes the page fault), re-arm, continue: the retried instruction hits again
  with readable code. `GDBRemote.resume` already does the step-over.
- **Every program loads at `0x00400000`**, so an address alone does not identify the program.
  Compare code bytes with the file in `sources/installed/Magic/Program` before trusting a hit.

## FUN_0046f5d1 (MAGIC.EXE): VERIFIED, the real draw-a-card function

Found statically, confirmed on the live game (`probe_duel_start.py`, saved in
`sources/oracle/probe_draw_result.log`).

Static: 1130 bytes; references the string "Draw a card Phase" (`0x00525af8`), "No more cards, you
lose", and "Draw Card"; chooses a card slot for the player (a random one for the AI), marks the slot
as drawn (`flags |= 1`), increments the hand counter, and is the *only* caller of the sound player
with sound id 2 (`draw.wav`), at `0x0046fa01`.

Dynamic, during a duel (opponent's draw step):

1. `0x0046f5d1` was entered, code bytes matching `MAGIC.EXE`, `arg0 = 1` (the opponent), called
   from `0x00502e28`.
2. Immediately afterwards the sound player was entered with sound id 2 from `0x0046fa06`, the
   instruction right after the call at `0x0046fa01` inside this function.

Also seen on screen, outside the probe: my hand went 7 -> 8 on my own draw step, and the game then
forced a discard back to 7 in the discard phase.

Name: `Magic_ExecuteDrawPhase(player)`. The rename maps already proposed this name, and the
`src/` tree and `include/magic.h` already used it; the raw `magic/` files still called the function
`FUN_0046f5d1`, which is now renamed to match. The oracle supports the name, since the function is
the per-player draw step. Only the opponent's draw was caught by the debugger; the player-0 branch
is verified by reading the code only.

## Magic_UpkeepPhase (MAGIC.EXE 0x0047496b): WRONG LABEL, it is the sound player

788 bytes. Takes a sound id (0..0x2f), looks it up in the 20-name table at `0x00525788` (ids
0x14+ use further tables), loads the `.wav` on demand and plays it. Verified on the live game: it
is called with id 2 from inside the draw function. Renamed to `Duel_PlaySoundById` (prototype fixed
to `int Duel_PlaySoundById(int sound_id)`; the header had `void(void)`). The parameter is named `player` in the
decompilation (in `DUEL.EXE`'s twin, `Sound_PlayTrackById`) but it is a sound id.

## Both programs run the duel engine (verified on the live game)

`MAGIC.EXE` and `DUEL.EXE` contain the same duel engine (identical function sizes: draw 1130
bytes, sound player 788, preloader 143). Which one runs depends on how the game is started:

- **Campaign duels run inside `MAGIC.EXE`.** In two runs a campaign duel loaded and played through
  the coin toss and several turns while breakpoints on `DUEL.EXE`'s entry point (`0x004dea30`) and
  on its draw and sound functions never fired.
- **Launching `DUEL.EXE` from its own shortcut runs the engine from `DUEL.EXE`.** With breakpoints
  on its twins (code bytes checked against the file each time), one run showed:
  1. entry point `0x004dea30` at t=16 s;
  2. sound preloader twin `0x0048d320` at t=18 s (called from `0x00437e96`);
  3. after the coin toss and the deal, the draw twin `0x00487ce1` with `arg0 = 0` (my draw step)
     at t=47 s, called from `0x004a6773`;
  4. immediately after, the sound player twin `0x0048d00c` with sound id 2, returning to
     `0x00488116`, which is the instruction after the call at `0x00488111` found by static
     analysis. The prediction matched exactly.

This closes the earlier caveat that the `DUEL.EXE` entry-point breakpoint might never fire: it does
when `DUEL.EXE` is really launched, so its silence during campaign duels is real. It also covers
both branches of the draw function: the opponent's draw (`arg0 = 1`) in `MAGIC.EXE`, mine
(`arg0 = 0`) in `DUEL.EXE`. The repo's claim that `MAGIC.EXE` is only the overworld and `DUEL.EXE`
the combat engine is wrong: both contain and run the combat engine.

Raw evidence: `sources/oracle/probe_draw_result.log` (MAGIC.EXE) and
`sources/oracle/probe_duelexe_result.log` (DUEL.EXE); both git-ignored.

Method notes added:

- The gdbstub can deliver an asynchronous stop notice (`T02...`) before the reply to your first
  command when you attach to a running guest, and a queued notice must be dropped when you
  resume. Both are handled in `GDBRemote`.
- Mouse: the guest drops events that arrive too fast while the game is loading, so movement is
  paced (12 ms per 2-count step), and a click needs a hold of about 0.35 s to register.

## Renames applied (MAGIC.EXE)

| Address | Was | Now | Status |
|---|---|---|---|
| `0x0047496b` | `Magic_UpkeepPhase` | `Duel_PlaySoundById` | verified, live |
| `0x00474c7f` | `Magic_DrawCardPhase` | `Duel_PreloadSoundEffects` | verified, live |
| `0x0046f5d1` | `FUN_0046f5d1` | `Magic_ExecuteDrawPhase` | verified, live (opponent's draw) |

Applied across the generated sources, headers, symbol CSVs and generator scripts, so re-running the
pipeline does not bring the wrong names back. The `OldName` column of the rename maps keeps the
original `FUN_` names, which is what the Ghidra sync looks up.

The same three functions in `DUEL.EXE`, now observed running too (see above):

| Address | Was | Now | Status |
|---|---|---|---|
| `0x00487ce1` | `FUN_00487ce1` | `Magic_ExecuteDrawPhase` | verified, live (my draw) |
| `0x0048d320` | `FUN_0048d320` | `Duel_PreloadSoundEffects` | verified, live |
| `0x0048d00c` | `Sound_PlayTrackById` | unchanged (name is fine) | verified, live; parameter renamed `player` -> `sound_id` |

The engine functions keep the `Magic_`/`Duel_` names they have in `MAGIC.EXE`, so the same code has the
same name in both programs. The sound player has two names for the same code
(`Duel_PlaySoundById` and `Sound_PlayTrackById`); unifying them would touch unrelated uses of the
latter, so it is left for later.

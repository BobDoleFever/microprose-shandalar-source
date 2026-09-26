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

Suggested name: `Duel_DrawCard(player)`. Not renamed in the source yet. Only the opponent's draw
was caught by the debugger; the player-0 branch is verified by reading the code only.

## Magic_UpkeepPhase (MAGIC.EXE 0x0047496b): WRONG LABEL, it is the sound player

788 bytes. Takes a sound id (0..0x2f), looks it up in the 20-name table at `0x00525788` (ids
0x14+ use further tables), loads the `.wav` on demand and plays it. Verified on the live game: it
is called with id 2 from inside the draw function. The parameter is named `player` in the
decompilation (in `DUEL.EXE`'s twin, `Sound_PlayTrackById`) but it is a sound id.

## Duels run inside MAGIC.EXE (strong evidence, not proof)

`MAGIC.EXE` and `DUEL.EXE` contain the same duel engine (identical function sizes: draw 1130
bytes, sound player 788, preloader 143). `DUEL.EXE`'s twins are at `0x00487ce1` (draw),
`0x0048d00c` (sound player) and `0x0048d320` (preloader). In two separate runs a campaign duel
loaded and played through the coin toss and several turns while breakpoints on `DUEL.EXE`'s
entry point (`0x004dea30`) and on its draw and sound functions never fired. I did not check that
the entry-point breakpoint fires when `DUEL.EXE` is really started, so this could still be a probe
blind spot. Either way the repo's claim that `MAGIC.EXE` is the overworld program and `DUEL.EXE`
is the combat engine is not what campaign play does: the duel code that runs is in `MAGIC.EXE`.

Method notes added:

- The gdbstub can deliver an asynchronous stop notice (`T02...`) before the reply to your first
  command when you attach to a running guest, and a queued notice must be dropped when you
  resume. Both are handled in `GDBRemote`.
- Mouse: the guest drops events that arrive too fast while the game is loading, so movement is
  paced (12 ms per 2-count step), and a click needs a hold of about 0.35 s to register.

# emu_spike: the original game in an emulated Windows

`winemu` runs the 1997 executables (MAGIC.EXE, DUEL.EXE, DECK.EXE) from your own copy in `sources/installed/Magic` on Unicorn, with
Win32, GDI, USER, KERNEL32 and the C runtime written in Python. Nothing from the game is in the repository. Writes go to
`sources/emu_overlay`, so the installed copy is never changed.

    pip install -r requirements.txt         # unicorn, pefile, numpy, pillow, pygame-ce (for --live)
    cd tools/emu_spike

## Play it

    python3 -m winemu.run --live            # a window; mouse and keyboard

Title screen in about 8 s, a new game's overworld in about 20 s. **Resume Game** loads the autosave the game makes at a wizard's door
(click it at the title: about 45 s to the "Duel / Pay gold" choice), and a duel starts from there: coin toss, start-of-duel dialog,
then the board; lands and phases (the bar under the board advances them) work, right-click a card for its menu ("View in full card" shows it in the left panel). The sound effects, the coin-toss movie (`winemu/movie.py`: the AVI decoded on the host, with its sound) and the music play (`winemu/magsnd.py` is a host version of the game's sound library on pygame.mixer; `EMU_NO_AUDIO=1` mutes; the music is on the game CD, which the install does not copy: run `python3 install_cd_music.py` once, see below), the dialogs are drawn plainly, and the AI thinks at emulator speed.

`--live` implies `--accel` (the card-text keyword search as Python, `winemu/accel.py`) and `--host-sound`. Environment:
`LIVE_TICK_MS` (default 10; 0 = counted slices, 35 times slower but the simplest), `LIVE_FALLBACK_MS`, `LIVE_PRESS_SLICES`, `LIVE_STATS=1`.
See `winemu/live.py` for how slices, the clock and input work, and `docs/PORT_STRATEGY.md` for why.

### Music

The game plays its music from the CD (`sound\locmus0.wav` ... the duel tune, the castle themes), not from the install. Copy it once from your disc image:

    python3 install_cd_music.py            # reads the .iso in sources/Magic_The_Gathering_ISO (macOS mounts it read only)
    python3 install_cd_music.py /Volumes/MTG   # or a mounted CD / any folder with a Sound folder

The files go to `sources/emu_overlay/Program/Sound` (git-ignored). `MAGSND_LOG=1` logs what the game loads and plays.

## Without a screen

`live_drive.py` posts real input events to the live window under SDL's dummy video driver and saves frames as PNG, from a script or a
command file you append to while it runs (see its docstring). This is how the live mode is tested.

## Scripted runs (no window)

    python3 -m winemu.run --seconds 60 --script "20:click 230 308;25:shot a;30:key 13 13"

`--script` ops (`click`, `key`, `shot`, `state`, `inject`, ...), `--native` (host the native layer, `tools/lift`), `--profile`, `--break`,
`--watch`, `--dump-windows`, `--dump-bitmaps`: see `python3 -m winemu.run --help`.

## Debugging aids (environment)

| | |
|---|---|
| `EMU_OVERLAY=DIR` | where the game's writes (saves) go instead of `sources/emu_overlay`; copy that folder first to start from your saves. Runs side by side need one each |
| `EMU_SRAND=N` | every `srand` seeds with N (the game seeds from the clock) |
| `EMU_REGCHECK=1` | report an import or a guest callback that changes EBP/EBX/ESI/EDI |
| `EMU_PROCTRACE=ADDR[,ADDR]` | the last instructions of that guest callback if it changed them |
| `EMU_PEEK=ADDR[,ADDR]` | print all registers each time the guest reaches ADDR |
| `EMU_CALL_HASH=N`, `EMU_CALL_DETAIL=A:B` | running hash of the import calls (compare two runs), and the calls A..B in detail |
| `MAGSND_LOG=1`, `MAGVID_LOG=1` | log what the game loads and plays through the host sound and video libraries |
| `GDI_DEBUG=1` | log mouse routing and blits |
| `PALDBG=1` | log every `RealizePalette` (which DC, window class and palette handle) |
| `PAL_LEGACY=1` | let any DC's `RealizePalette` set the system palette (the old rule) |

Do not read the guest's registers from another thread while it runs: it corrupts it (use Python-side state only).

## What works (checked in the live window)

| | |
|---|---|
| Start-up | title in about 8 s; a new game's overworld in about 20 s; **Resume Game** loads the autosave (about 45 s) |
| Overworld | walking, villages (Buy Cards, Edit deck/Sell cards, Begin a Quest, buy food), towers (trivia, tolls, duels), world map, City Info, wizard sheet and journal |
| Quests | accept in a village, deliver (a delivery from Windlass Village to Sahrmal's Bazaar was completed and paid a blue amulet and a mana link) |
| Duels | coin toss with its movie, start dialogs, lands, creatures, auras and targeted spells (target prompt with Cancel), attacking, blocking, damage assignment, the opponent's spell popups, game over and the ante |
| Deck editor | shows the deck, double click moves cards both ways, colour/type filters, Stats, right-click menus, Deck1-3 slots (kept with the game's save), Exit |
| Saves | right-click the map, Save, slot, name, Enter; Load Saved Game at the title. Files go to `sources/emu_overlay/Program` |
| Sound | effects, music from the CD (`install_cd_music.py`), the coin-toss movie and the ending movie (Indeo 4 through `ffmpeg`) |

Over about 45 minutes of soak play (four runs, walking, towers and duels) there were no emulator errors and memory stayed near 610 MB.

## The native layer on MAGIC.EXE (Phase B)

The native functions (`src/native`: spell stack, card queries, event contexts, the AI search's state and evaluation) now run in
the game you play, MAGIC.EXE, not only in DUEL.EXE: `src/native/layout.c` has MAGIC's addresses, `native_host.py` picks the layout
from the executable, and 28 of the 30 functions are replaced (`Crt_Memcpy` and `Crt_Memset` are imports in MAGIC.EXE). Build the
library from MAGIC's own machine code (these lifted twins are what the natives are checked against; the generated C is git-ignored):

    python3 tools/lift/gen_handlers.py --program magic --exe sources/installed/Magic/Program/MAGIC.EXE --out sources/generated/lift_magic --no-handlers
    make -C tools/difftest host GEN=../../sources/generated/lift_magic BUILD=build_magic

    python3 live_drive.py --native ...          # or: python3 -m winemu.run --live --native

Checked: a scripted run (resume, duel, pass turns through the opponent's first turn) with `--native --native-exact --native-shadow-check`
ran every native call both ways: 378,999 calls compared against the lifted machine code of MAGIC.EXE, 0 differ, no memory faults (the
calls that call out to the guest are not compared, as in DUEL.EXE). 29 of the 30 functions have a MAGIC twin; `Magic_QueryCardAttribute`
has none (a jump table the lifter cannot bound). A live duel with `--native` ran 144,000 native calls and the autopilot won it. Not
shown: that it makes the opponent's turn shorter, and exact timing on MAGIC (the exact cost model is DUEL's: MAGIC copies through an import).

## Playing tips

- The quest and tower text menus take the keyboard: Down moves the highlight, Enter chooses (a click on a line sometimes does not).
- A tower on the road stops you until you pay its toll (the Pay line shows only if you have the gold) or beat its wizard. With no gold only the duel is offered, and losing it leaves you at the same tower facing a stronger wizard. Selling cards in a village (double click a deck card out, right-click it in the list, Sell) raises toll money.
- Cards in hand are played by clicking their name; lands are tapped by clicking them first. Attack: click your creature in the attackers prompt, Done. Block: click your creature, then the attacker.
- Keep a deck at about 40 cards or more: a shorter one is padded with random basic lands (a 28-card deck was dealt Swamps and Plains that are not in the collection). Leaving the editor with Deck2 or Deck3 active makes duels use that deck, so switch back to Deck1.
- A game saved while standing at a wizard's tower resumes at that tower's prompt; a new game's start varies from run to run (the game seeds from the clock), so use a saved slot for repeatable scripts.

## The test driver and the duel autopilot

`live_drive.py` (see its docstring for every token): clicks, keys, screenshots, window and card listings (`win:`, `hand:`, `cards:`, `texts:`), `call:ADDR,args` to run a guest function, and two duel players:

- `play:SECS` answers the dialogs and plays the top card of the hand each turn; it loses every duel.
- `duel:SECS` (`autoplay.py`, with `winemu/duelview.py` reading the duel from guest memory) plays the game: lands of the colour the hand needs, creatures and the set of spells that spends the most mana (Llanowar Elves and Sisters of the Flame are tapped for mana), helpful auras on its best creature, curses and damage or removal on the opponent's creature it can kill, attacks when enough stays home to survive the opponent's side, blocks (chump blocks when the damage would leave it at 2 life or less), assigns damage to blockers, discards, and prints `RESULT WON/LOST`. It does not play instants held for combat, spells aimed at players or lands, or X spells. With the starter deck it won three of twelve duels against tower wizards, and 0 of 6 (previously 1 of 5) against the red Sorcerer at the Resume Game tower: more play logic made no measurable difference against that opponent.
- Use `EMU_OVERLAY=DIR` (a copy of `sources/emu_overlay`) per run to run several games side by side.

## Known defects (what a player will see)

- The opponent's turn takes 15-30 s. Measured in a live duel (`LIVE_SAMPLE=1` with `live_drive.py duel:`, which prints the import calls made while the prompt bar is empty): the opponent's turn is millions of import calls, not guest computation: 60% were `GetWindowLongA` from the board's message handler scanning its card windows (now replaced by a Python stand-in, `accel.py`), the rest `rand` and `Enter/LeaveCriticalSection` from the AI's search, `SendMessageA` and drawing. So the work left is the search's imports (which a native layer for MAGIC.EXE would make plain C), not only the lifted search functions.
- Sound, music and both movies are checked in the logs and frames, not by ear. The wizards' animation clips on the CD (`StatWin/*.AVI`) were never asked for in a duel. The ending movie was run by calling the game's player directly (`live_drive.py call:`), not by winning the game.
- The dialogs are drawn plainly (a grey panel) when the game does not paint them itself.
- Not tried: the stand-alone deck builder's New/Load/Save deck menu, instants held for combat and X spells (the autopilot does not cast them), trading with another wizard.

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
| `EMU_SRAND=N` | every `srand` seeds with N (the game seeds from the clock) |
| `EMU_REGCHECK=1` | report an import or a guest callback that changes EBP/EBX/ESI/EDI |
| `EMU_PROCTRACE=ADDR[,ADDR]` | the last instructions of that guest callback if it changed them |
| `EMU_PEEK=ADDR[,ADDR]` | print all registers each time the guest reaches ADDR |
| `EMU_CALL_HASH=N`, `EMU_CALL_DETAIL=A:B` | running hash of the import calls (compare two runs), and the calls A..B in detail |
| `GDI_DEBUG=1` | log mouse routing and blits |
| `PALDBG=1` | log every `RealizePalette` (which DC, window class and palette handle) |
| `PAL_LEGACY=1` | let any DC's `RealizePalette` set the system palette (the old rule) |

Do not read the guest's registers from another thread while it runs: it corrupts it (use Python-side state only).

## Known defects (what a player will see)

- The ending movie (`MTGEND.AVI`, shown after winning the game) has not been tried: the game plays it with `MAGVID.DLL`, which is not hosted. Sound, music and the coin-toss movie play but are unheard by the author: they were checked in the logs, not by ear.
- The AI's turn takes about 15 s: MAGIC.EXE's duel engine is not yet hosted on the native layer.
- The deck editor (the book icon on the map, or "Edit deck/Sell cards" in a village) opens, shows the deck, moves cards between deck and collection on a double click, filters by colour or type, shows Stats, and Exit returns to the map. Saving a named deck (Deck1-3 buttons, the right-click menu's save and load), the Deck1-3 saves and cancelling a target prompt have not been exercised.
- Quests and the overworld screens work: a village's Begin a Quest offers a quest (accept it and the scroll shows it with a day counter, the button becomes Speak to Wise Man), walking to a tower asks a trivia question and pays a card, the world map, City Info (cities visited, mana stones, cards for trade), the wizard sheet and its journal open and close. Completing a quest (defeating its monster) was not tried.
- Combat works: in the combat phase click your creature to attack and Done to confirm, then Done through the opponent's blockers; on the opponent's turn the "Choose blockers" prompt takes a click on your creature and then on the attacker it blocks. Creature damage, the "Sorcerer casts..." card popup and Winds of Change reshuffling the hand were seen working. Targeted spells work: Flight asked "Select target creature" (with Cancel) and the chosen creature showed the aura. Cards in hand are played by clicking their name; lands are tapped by clicking them first.
- Saving and loading games work: right-click the map, Save, pick a slot, type a name, Enter; the title's Load Saved Game lists the slots. Files go to `sources/emu_overlay/Program` (`MAGICn.SVE/.map/.fce`, `saveDescs`). A game saved while standing at a wizard's tower resumes at that tower's prompt.

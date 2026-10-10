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

## Known defects (what a player will see)

- The ending movie (`MTGEND.AVI`, after winning the game) plays: `MAGVID.DLL` is hosted (`winemu/movie.py`), and the movie is Indeo 4, which is decoded by `ffmpeg` if it is installed (without it the movie is skipped). It was run by calling the game's player directly (`live_drive.py call:`), not by winning the game. Sound, music and the movies play but are unheard by the author: they were checked in the logs and frames, not by ear. The wizards' animation clips on the CD (`StatWin/*.AVI`) were not seen to be asked for in a duel.
- The AI's turn takes about 15 s: MAGIC.EXE's duel engine is not yet hosted on the native layer.
- The deck editor (the book icon on the map, or "Edit deck/Sell cards" in a village) opens, shows the deck, moves cards between deck and collection on a double click, filters by colour or type, shows Stats, and Exit returns to the map. Saving a named deck (Deck1-3 buttons, the right-click menu's save and load), the Deck1-3 saves and cancelling a target prompt have not been exercised.
- Quests and the overworld screens work: a village's Begin a Quest offers a quest (accept it and the scroll shows it with a day counter, the button becomes Speak to Wise Man), walking to a tower asks a trivia question and pays a card, the world map, City Info (cities visited, mana stones, cards for trade), the wizard sheet and its journal open and close. A quest was completed: the delivery from Windlass Village ("Take a Blue Enchantment spell North to Sahrmal's Bazaar", 5 days) with Flight in the deck: walk north to Mardrake Village, leave it and click far left along the shore; the Bazaar's people took Flight and paid a blue amulet and a mana link (the amulet count on the status bar went 0 to 1).
- Quests and towers, what was learned playing it: the quest and tower text menus take the keyboard (Down moves the highlight, Enter chooses; a click on the line sometimes does not), and the scroll at the bottom right shows the quest and its days. A tower on the road stops you until you pay its toll (the Pay line appears only when you have the gold) or beat its wizard: with 0 gold the game offers only the duel, and losing it leaves you at the same tower, facing a stronger wizard. Selling cards in a village (double click a deck card out, right click it in the list, Sell) is how to raise toll money. The delivery quests tried needed a long road with several towers (a message to Sahrmal's Bazaar) or a card to be found first (a green sorcery spell for Mardrake Forge); the first was stopped by tolls and the autopilot cannot win duels, so that attempt did not finish (a different route and the quest above did).
- A duel autopilot: `live_drive.py duel:SECS` (code in `autoplay.py`) plays a duel through the real window: lands (of the colour the hand needs), creatures it can pay for (reading each card's cost from `INFO.CSV` and the card windows from guest memory, `winemu/duelview.py`), attacks when enough stays home to survive the opponent's side, blocks, assigns damage to blockers, discards, and ends the duel with a `RESULT WON/LOST` line. It also casts spells that are safe to play from their rules text: auras that help (`+N/+N`, flying) on its best creature, auras that hurt (Wanderlust, `-N`) and damage or removal spells on the opponent's creature it can kill; it does not play instants held for combat, spells aimed at players or lands, or X spells. With the starter deck it won three of twelve duels against the tower wizards; use `EMU_OVERLAY=DIR` per run to run several at once. (`play:SECS` is the old one that only plays the top card.)
- Deck size matters: a duel from a deck of 28 cards (Stats window) dealt Swamps and Plains, which were not in the collection (6 Islands, 4 Plains and 3 Swamps were played over 6 duels after the Islands were taken out), so the game seems to pad a short deck with random basic lands up to its minimum size. Cutting the starter deck down to its red and green cards therefore did not help (1 win in 6 duels, against 3 in 12 for the 46-card starter deck); keep a deck at or above about 40 cards.
- Combat works: in the combat phase click your creature to attack and Done to confirm, then Done through the opponent's blockers; on the opponent's turn the "Choose blockers" prompt takes a click on your creature and then on the attacker it blocks. Creature damage, the "Sorcerer casts..." card popup and Winds of Change reshuffling the hand were seen working. Targeted spells work: Flight asked "Select target creature" (with Cancel) and the chosen creature showed the aura. Cards in hand are played by clicking their name; lands are tapped by clicking them first.
- Saving and loading games work: right-click the map, Save, pick a slot, type a name, Enter; the title's Load Saved Game lists the slots. Files go to `sources/emu_overlay/Program` (`MAGICn.SVE/.map/.fce`, `saveDescs`). A game saved while standing at a wizard's tower resumes at that tower's prompt.

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
then the board; lands and phases (the bar under the board advances them) work, right-click a card for its menu ("View in full card" shows it in the left panel). The sound effects play (`winemu/magsnd.py` is a host version of the game's sound library on pygame.mixer; `EMU_NO_AUDIO=1` mutes; music tracks and the coin-toss movie are not there), the dialogs are drawn plainly, and the AI thinks at emulator speed.

`--live` implies `--accel` (the card-text keyword search as Python, `winemu/accel.py`) and `--host-sound`. Environment:
`LIVE_TICK_MS` (default 10; 0 = counted slices, 35 times slower but the simplest), `LIVE_FALLBACK_MS`, `LIVE_PRESS_SLICES`, `LIVE_STATS=1`.
See `winemu/live.py` for how slices, the clock and input work, and `docs/PORT_STRATEGY.md` for why.

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
| `EMU_PEEK=ADDR` | print all registers each time the guest reaches ADDR |
| `EMU_CALL_HASH=N`, `EMU_CALL_DETAIL=A:B` | running hash of the import calls (compare two runs), and the calls A..B in detail |
| `GDI_DEBUG=1` | log mouse routing and blits |
| `PALDBG=1` | log every `RealizePalette` (which DC, window class and palette handle) |

Do not read the guest's registers from another thread while it runs: it corrupts it (use Python-side state only).

## Known defects (what a player will see)

- **The shop screens' backgrounds (Buy Cards) are speckled with wrong colours**: the layout, text and cards are right, the textured
  background has noise in it. The palette is the same as on the working screens (checked), so it is the picture's indices; not found yet.
- Music tracks and the coin-toss movie (AVI) are not played; sound effects are (unheard by the author).
- The AI's turn takes about 15 s: MAGIC.EXE's duel engine is not yet hosted on the native layer.
- Saving and loading games, the deck editor, trading, combat targeting dialogs have not been exercised.

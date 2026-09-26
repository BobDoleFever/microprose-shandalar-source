# How the port will run

**Decision (proposed, 2026-09-26): host the original x86 code in a CPU emulator, supply the Windows and
C-runtime imports natively, and replace engine functions with clean native code one at a time, each checked
against the original code still running underneath.** Nothing here is built yet beyond a feasibility spike.

## Why not just compile the decompiled C

The decompilation is 3,762 functions, 228,562 lines in the two unified files, and references about 2,600
unnamed globals at fixed addresses (`DAT_00695ec4`, and 0x120 and 0x5b20 strides into card-slot tables). The
duel engine and the user interface are the same code: the engine calls `SendMessageA` (389 call sites),
`GetWindowLongA` (368), `SelectObject`, `InvalidateRect` and so on directly. Recompiling it natively means
rewriting all of that by hand before anything runs, and the raw files still have compile errors. Ghidra's
output is also only right where it is right: the name samples found about 1 in 5 wrong.

## What the game needs from the outside

`MAGIC.EXE` imports **325 functions from 11 DLLs**: `USER32` 114, `MSVCRTD` (the debug C runtime) 79, `GDI32`
72, `KERNEL32` 45, `ADVAPI32` 6, `WINMM` 4, and one each from `COMDLG32`, `SHELL32`, `COMCTL32`, `MSVFW32`
and `DECKDLL` (the game's own). There is **no DirectX**: it draws with GDI (`BitBlt`, palettes, `DrawText`).
Sound is `WINMM` plus its own `MAGSND.DLL`. 242 of the 245 non-C-runtime imports have call sites in the
decompiled code, from which their argument counts were derived (`tools/emu_spike/derive_argc.py`).

## The spike: it runs, and draws the title menu

`tools/emu_spike/winemu/` is a small Win32 host in Python around Unicorn (a QEMU-derived CPU emulator with an
arm64 macOS build). It maps `MAGIC.EXE` at its base, points every import at a trap, and answers the calls
itself. On this Apple Silicon Mac the original code now runs from the entry point through:

- C runtime start-up, `WinMain`, window-class registration, and `CreateWindowEx` for the main window (the game's
  window procedure runs in the emulator and is called back by the host),
- the second thread: the game's engine runs on a thread it creates just before entering the message loop
  (`WinMain` only pumps messages), so the host has a cooperative scheduler with per-thread CPU contexts,
  critical sections, sleeps and multimedia timers,
- loading its data: fonts, the palette table, `CONCISE.CSV`, the map files and sprite files, through a C runtime
  (`fopen`, `fscanf`, `sscanf`, `_read`, ...) mapped onto the installed game folder,
- anonymous shared-memory mappings (`CreateFileMappingA` on `-1`), which its resource library needs,
- drawing: GDI device contexts, 8-bit DIB sections kept in emulated memory (the game draws into them itself), palette
  changes (`SetDIBColorTable`) and `BitBlt`, onto a host surface saved as PNG.

**Result: the game runs from the title screen into the adventure screen, driven by injected input.** Scripted clicks
and keys walked it through Start New Game, difficulty, colour, portrait ("Select Your Visage": all fourteen
render) and the name prompt to the stained-glass adventure frame, every screen decoded and drawn by the original
code. There is no sound and no `DUEL.EXE` yet, dialogs made with `DialogBoxParam` are not implemented, and the
adventure screen has only been seen fading in.

Run it the same way with `--script`:

```
python3 -m winemu.run --seconds 200 --script "30:move 300 308;32:click 300 308;50:move 350 120;52:click 350 120;72:move 160 90;74:click 160 90;105:move 130 100;107:click 130 100;130:key 13 13;185:shot adventure"
```

(times are host seconds; each screen takes the emulator several seconds to build).

Things worth knowing that the run turned up:

- MSVC's `feof` is a macro that reads `FILE._flag & 0x10` directly, so the emulated `FILE` structure must keep
  that flag: without it the game's read-until-EOF loops never end.
- `_filelength(_fileno(f))` is used to size a buffer before `fread`, so it must work on `FILE*` descriptors.
- Portraits and sprites are drawn with `SetDIBitsToDevice` one row-strip at a time, in `DIB_PAL_COLORS` mode: the
  colour table is 16-bit *indices into the selected logical palette*, not colours. Reading it as RGBQUADs produced
  black bands across every face. The call also takes a start scan line and a bottom-up source origin.
- The game reads keys from `WM_KEYDOWN` and needs the scan code in `lParam`, or Enter is ignored.
- The display must be modelled as **8-bit palettized**: the game draws into 8-bit DIB sections, blits them
  with `StretchBlt`, and fades by animating the *system palette* (`AnimatePalette`, `RealizePalette`), not by
  redrawing. Window surfaces therefore hold palette indices and colours are resolved when the screen is
  composed; converting through RGB at blit time lost the picture while the palette was faded to black.
- Files are looked up case-insensitively and writes go to a separate overlay folder, so the installed copy is
  never touched.
- The import argument counts (needed for stdcall stack clean-up) come from the decompiled call sites of all
  seven binaries (`derive_argc.py`, 357 of 358 imports).

## What it would cost, honestly

Bounded, but not small:

1. **The CRT and file calls**: `fopen`, `fread`, `sprintf` and friends, mapped to the host. Easy, mechanical.
2. **A window manager**: `CreateWindowEx`, window procedures, `SendMessage`, dialogs from the PE resources,
   `GetDlgItem`. The hard part is not the count but **re-entrancy**: the host must call back into emulated
   code (a window procedure, a dialog procedure, a `timeSetEvent` callback) from inside an import call.
3. **GDI**: device contexts, bitmaps, palettes, `BitBlt` and text, drawn to an SDL2 surface. The port already
   has an SDL2/Win32 shim in `src/platform` that covers part of this.
4. **Audio and timers**: WINMM and the two sound DLLs, and `timeSetEvent` on another thread in the original.
5. **`DUEL.EXE`, `DECK.EXE` and the DLLs** are loaded and started the same way.

Speed should be fine: the game is a 1997 turn-based GUI program, and Unicorn runs orders of magnitude faster
than that machine needed.

## The plan

1. **Phase A, exact and playable.** Grow the spike into a host that runs the original code. A duel that plays
   identically to the retail game, because it is the retail game's code, on any machine.
2. **Phase B, native replacement.** Take engine functions we have named and verified (`Magic_ExecuteDrawPhase`,
   `Magic_RunTurnStep`, the spell stack) and reimplement them in clean C. Host both: the emulated original and
   the native version run on the same state and must agree. This replaces the QEMU oracle with an in-process
   one that is fast and scriptable, which is the harness in `VERIFICATION_HARNESS_PLAN.md` with a better engine.
3. **Phase C.** Replace the UI and the Win32 dependence last, when there are enough native pieces that the
   emulator is only running leftovers.

The naming work (`SYMBOL_VERIFICATION.md`) carries on, now prioritised by what Phase B replaces first, not by
alphabet.

## Risks and open points

- **Licence.** Unicorn is GPL-2.0. Linking it makes the port GPL-2 compatible, which suits a preservation
  project but should be a deliberate choice. The repository has no licence file today.
- **Undocumented corners** of the Win32 behaviour the game leans on (window-message ordering, palette
  realisation, `timeSetEvent` timing) are found by running it; the QEMU oracle stays the reference for those.
- **Only x86.** This avoids needing Wine. On x86 machines Wine already runs the game; this path is for
  Apple Silicon, mobile, consoles and the long term.
- **What was not tested:** speed under a full duel, anything past game start-up, `DUEL.EXE`.

## Try it

```bash
python3 -m venv .venv && .venv/bin/pip install -r tools/emu_spike/requirements.txt
cd tools/emu_spike
../../.venv/bin/python -m winemu.run --seconds 60      # runs MAGIC.EXE from sources/installed, saves sources/emu_shots/screen.png
../../.venv/bin/python -m unittest discover -s tests   # the parts that need no game files
```

Useful flags: `--trace-only REGEX` (log matching import calls), `--log-files` (log every file the game opens).
`derive_argc.py` regenerates `argc_magic.json` from the decompiled C.

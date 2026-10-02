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

**Result (second stage): `DUEL.EXE` runs from its setup dialog through the coin toss and "Start the duel" into the
first main phase**, drawing life totals, mana, the hand and the phase prompt, with the backgrounds and card art still
missing. **First stage: the game runs from the title screen into the adventure screen, driven by injected input.** Scripted clicks
and keys walked it through Start New Game, difficulty, colour, portrait ("Select Your Visage": all fourteen
render) and the name prompt to the stained-glass adventure frame, every screen decoded and drawn by the original
code. There is no sound yet, dialogs made with `DialogBoxParam` are not implemented, and the
adventure screen has only been seen fading in.

**Duel input now works.** Clicking a hand card plays it (a land moved from the hand into play, card slot flags
changed, and the prompt lost "play land"), and the Done button advances the phase ("Main phase (before combat)"
to "(after combat)"). The bug was `SendMessage` across threads: the engine thread sends the main window a "wait
for the player's choice" message (`0x403`) and then loops reading its own queue for the answer (`0x464`). Windows
runs a window's procedure on the thread that created it, so that loop reads the *main* thread's queue, where the
click is posted. Running it on the sender's thread starved the loop. The host now marshals cross-thread sends to the
owner thread and blocks the sender until it replies (and an in-progress sent message must not be re-entered by
the nested pumps inside its own handler, or the stack overflows).

Scheduling matters too: `DUEL.EXE`'s statically linked C runtime is not thread-safe (two threads reading files
share a static buffer), so threads are run cooperatively (a thread keeps the CPU until it blocks) instead of
being cut into short time slices, which produced random crashes.

The "spin" after a phase change was not a spin: the duel's wait-for-input loop polls with `PeekMessage`, and the run's time
limit was only checked inside `GetMessage`, so a run never stopped and each idle virtual millisecond cost real time.
The limit is now enforced by the scheduler and idle polling backs off (1 ms doubling to 16 ms), so 80 virtual seconds
cost about 70 real ones. Still rough: the hand list rows draw at the wrong size.

**The emulator is now a working oracle.** `--break ADDR:label:nargs` traces any guest function (its stack arguments,
strings, caller and virtual time; identical bursts are collapsed and totalled). On `DUEL.EXE` it reproduces the
QEMU findings from `SYMBOL_VERIFICATION.md` with no debugger: `Magic_RunTurnStep` is `Magic_RunTurnStep` (step codes 201
"Begin Upkeep", 203, 205 "End of Turn", 206 "Draw Phase", 207 "Draw a card Phase", 210 "Tapping", 211 "Casting"),
`Magic_PushSpellStack` is `Magic_PushSpellStack` (`(0, 0, 113, 0, 0)` for my land, `(1, 6, 113, 1, 0)` for the opponent's,
`(0, 7, 114, 0, 0)` at my draw) and `Magic_ClearSpellStack` is `Magic_ClearSpellStack` (once at the start of every
turn). The `DUEL.EXE` twin of `Magic_DropTopSpell` is `Magic_DropTopSpell` (not entered yet: nothing has been cast). Runs
are deterministic, so a trace can be diffed between two builds of a replacement.

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
- `DUEL.EXE` is a different build: a statically linked C runtime (so it calls the raw heap, locale, time and
  startup APIs itself), and it loads the game's own DLLs (`DECKDLL.DLL`, `MAGSND.DLL`) from the game folder, whose
  `DllMain` must run first. It opens a Windows 9x virtual device, `\\.\MPStime.VXD` ("Dave's Extra Cool Timer"), with
  `CreateFile` and reads a tick counter with `DeviceIoControl`; the host emulates that device.
- Dialogs are real: `DialogBoxParam` templates (the extended `DLGTEMPLATEEX` form) are parsed into child controls,
  the control messages a game uses (combo boxes and list boxes with `LB_DIR`, radio buttons, text) are
  implemented, and a modal loop waits mid-call while the host presses buttons (`--script "58:dlg 1"`).
- Window messages are per thread: a window's messages go to the thread that created it (the duel engine and
  the main thread both pump messages).
- The duel draws in direct colour (24- and 32-bit DIB sections) while the title screens use the palette, so a window
  surface keeps palette indices *and* a direct-colour overlay.
- **All guest time is virtual.** The clock advances with executed instructions (`ips` per second) and jumps to the
  next deadline when every thread is waiting, so a run is exactly repeatable (two runs give identical screenshots),
  script times are virtual seconds, and idle waiting costs nothing. Threads that poll an empty message queue are
  put to sleep for a virtual millisecond.
- **Reading the game's memory works.** `--script "...:state"` prints the duel's card slots straight from emulated
  memory (DUEL.EXE `g_DuelCardSlot_CardId` at 0x6826c4, stride 0x120 per slot and 0x5b20 per player) and the
  prompt text; this is the in-process replacement for the QEMU + gdb oracle.
- The duel draws its window backgrounds in `WM_ERASEBKGND` (a window's own procedure, not the class brush), through
  a pattern brush, and copies 8-bit `DIB_PAL_COLORS` sections into 24-bit ones, which needs the section's own colour table.
- Input routing needs real window semantics: a popup window (the prompt strip with its Done button) is above the
  child windows of its owner, built-in push buttons turn a click into `WM_COMMAND`, and hover sends
  `WM_NCHITTEST`/`WM_SETCURSOR` first.
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

**The card handlers do not need to be rewritten by hand.** Each of the 383 distinct handlers is a small function whose
whole behaviour is in its machine code, so `tools/lift` translates the machine code into C mechanically (a static
recompiler for the integer subset of x86) and the result is checked against vectors recorded from the original, the same
way as every native function above. 373 of 383 lift; all 373 match their recorded vectors (7,323 of them); the vectors run
53% of the lifted instructions, which is the number to raise. See `tools/lift/README.md`. What it changes for the plan:
the hand-written native work is the engine around the handlers, and the handlers become a generated, verified bulk
layer, not hundreds of rewrites.

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

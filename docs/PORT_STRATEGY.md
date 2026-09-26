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

## The spike: it runs

`tools/emu_spike/pe_run.py` maps `MAGIC.EXE` at its preferred base under Unicorn (a QEMU-derived CPU
emulator with an arm64 macOS build), points each import at a trap address, and answers them from a small table.
On this Apple Silicon Mac, with about 300 lines of Python:

- the C runtime start-up runs (`__set_app_type`, `_initterm`, `__getmainargs`),
- `WinMain` (the function around `0x00500ea5`) runs: `FindWindowA` (single-instance check), `srand`, trimming `argv[0]`, `_chdir`,
  `LoadIconA`, `LoadCursorA`, `RegisterClassA` (it shows an error box and exits if that returns 0),
- and it gets on into game start-up: `GetDriveTypeA`, a run of `fopen` calls, `timeBeginPeriod` and
  `timeSetEvent` (78 imports called in all),

where it stops inside the stand-in `sprintf`, handed a bad pointer, a knock-on of the fake `fopen` calls
returning 0. That is the expected next gap: the file and window calls are still fake, so this shows that the
code executes, not that the game works.

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

## Try the spike

```bash
python3 -m venv .venv && .venv/bin/pip install -r tools/emu_spike/requirements.txt
.venv/bin/python tools/emu_spike/pe_run.py [path/to/MAGIC.EXE] [max_calls]
```

`derive_argc.py` regenerates `argc_magic.json` from the decompiled C.

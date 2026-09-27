# Shandalar decompilation

Work toward a modern port of MicroProse's 1997 *Magic: The Gathering* (Shandalar), in the spirit of
DevilutionX: the game's own code, running on current systems, using data files from a copy of the
game you own. **No game files are in this repository.**

The game is seven Windows programs (`MAGIC.EXE`, `DUEL.EXE`, `DECK.EXE` and four DLLs). They were
decompiled with Ghidra into C (5,359 functions). That is the raw material. It is **not** a
working port yet.

## Where things stand

| | |
|---|---|
| Decompiled C for all 7 binaries | done, but only partly readable (see below) |
| SDL2 platform layer with a Win32 compatibility shim | builds, 85 unit tests pass |
| Sprite (`.SPR`) decoder | loads the real `ICONS.SPR`, all 24 sprites |
| A running, playable game | **no** |
| An emulated original to compare against | **yes** ([docs/ORACLE_VM.md](docs/ORACLE_VM.md)) |

**Function names are unreliable.** Most were guessed by script. A random sample of 30 "meaningful"
names found about 1 in 5 wrong or misleading and about 1 in 3 unsupported by the code
([docs/SYMBOL_SAMPLE.md](docs/SYMBOL_SAMPLE.md)). Names confirmed by running the real game are logged in
[docs/SYMBOL_VERIFICATION.md](docs/SYMBOL_VERIFICATION.md); trust those, and read the code for the rest.

## Try it

You need a C compiler, SDL2 (`brew install sdl2` on macOS, `libsdl2-dev` on Debian) and Python 3.

```bash
make check    # syntax-check the curated sources
make test     # 85 platform-layer tests, then a 120-frame headless run
python3 -m unittest discover -s tools/verification_harness/tests   # harness tests
```

To let `make test` load real sprites, put your game's `Program` folder at
`sources/installed/Magic/Program`, or point `SHANDALAR_PROGRAM_DIR` at it.

The `make game*` targets build a Windows executable for Wine. They are untested and Wine is not
usable on Apple Silicon Macs, so the working reference is the emulated original below. `make sync`
needs the original author's Ghidra project and will not work elsewhere.

## The reference copy of the original

To learn what the original code really does, run it. `docs/ORACLE_VM.md` describes a Windows 98 virtual
machine (QEMU) that boots the retail game headlessly, with scripted mouse and keyboard input and
a debugger connection, so a function can be checked by watching it run. Media and disk images stay
in the git-ignored `sources/` folder; you supply your own.

```bash
tools/verification_harness/oracle_launch.sh      # boot the original under QEMU
tools/verification_harness/oracle_ctl.py shot    # screenshot; also: click X Y, key ...
```

## Repository map

| Path | What |
|---|---|
| `magic/ duel/ deck/ deckdll/ statwin/ magsnd/ magvid/` | raw decompilation per binary: `*_all.c`, `*_unified.c`, `symbols.csv`, `function_index.csv` |
| `src/`, `include/` | hand-curated tree: SDL2 platform layer (`src/platform`), sprite and catalog code, headers |
| `*_symbol_map.csv`, `*_renames.csv`, `engine_globals_map.csv` | name maps applied to Ghidra by the scripts |
| `scripts/` | the Ghidra and Python pipeline that produced the tree |
| `tools/verification_harness/` | drive and inspect the emulated original, plus tests |
| `tools/emu_spike/` | spike: run `MAGIC.EXE` in a CPU emulator with our own imports |
| `tools/registry/` | the names `docs/SYMBOL_VERIFICATION.md` verified, as a CSV, and a check that the repo still carries them |
| `tools/twins/` | pair each `MAGIC.EXE` function with its `DUEL.EXE` twin by normalised body (`twins.csv`) |
| `docs/` | see below |
| `sources/` | local only, ignored by git: installers, disc images, extracted game files |

## Docs

- [ORACLE_VM.md](docs/ORACLE_VM.md): building and using the emulated original, and its quirks
- [PORT_STRATEGY.md](docs/PORT_STRATEGY.md): how the port will run (emulated original first, native replacement after), with a spike
- [VERIFICATION_HARNESS_PLAN.md](docs/VERIFICATION_HARNESS_PLAN.md): the verification plan and checklist
- [SYMBOL_VERIFICATION.md](docs/SYMBOL_VERIFICATION.md): names confirmed on the running game
- [SYMBOL_SAMPLE.md](docs/SYMBOL_SAMPLE.md): how reliable the names are, and the known bad patterns
- [FILE_FORMATS.md](docs/FILE_FORMATS.md): `.SPR` and `.PIC`, checked against real files
- [SDL2_WIN32_API_IMPLEMENTATION_PLAN.md](docs/SDL2_WIN32_API_IMPLEMENTATION_PLAN.md): review of which
  Win32 calls the game needs (dated 2026-08-27, numbers not re-checked)

## Legal

*Magic: The Gathering* is a trademark of Wizards of the Coast; *Shandalar* and *MicroProse* belong to
their owners. This is preservation and research work. The repository has no license file; do not
redistribute game files.

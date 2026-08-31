# MAGIC 32-bit PE Implementation Plan

## Objective

Build `MAGIC.EXE` as an i686 PE32 program from the recovered C source. Run the new program through Wine on macOS and directly through WOW64 on compatible Windows systems. Do not run or redistribute the retail `MAGIC.EXE` as the application program.

The first release can use retail companion modules from a user-supplied data directory. The final release must replace all required EXE and DLL modules with source-built PE files.

## Fixed decisions

- Use `i686-w64-mingw32-gcc` and `i686-w64-mingw32-windres`.
- Build a Windows GUI program at image base `0x10000000` with dynamic relocation disabled.
- Put generated source in `build/generated/pe32`.
- Put runtime files in `build/pe32/bin`.
- Use the isolated prefix `build/wineprefix` with `WINEARCH=wow64`.
- Map the recovered logical image range at `0x00400000` as read/write data. Do not execute bytes from that image.
- Use direct 32-bit process pointers for recovered global addresses.
- Keep `make sidtest` as the Sid test program. Use `make game` for the source-built PE program.
- Keep the arm64 address-virtualization work behind `make game-native` as an experiment.

## Current implementation status

| Area | Status | Evidence or next gate |
|---|---|---|
| Homebrew dependencies | Implemented | `Brewfile` installs MinGW-w64 and Wine 11 stable. |
| Tool validation | Implemented | `make pe-toolcheck` checks the compiler, resource compiler, Wine, `winepath`, and Wine major version. |
| PE Make targets | Implemented | `pe-audit`, `game-build`, `wine-prefix`, `game`, and `game-test` exist. |
| MAGIC source generation | Initial implementation | The PE profile generates source, an import header, a callable map, callback trampolines, image constants, and audit reports. A real MinGW compile is the next gate. |
| Recovered image loader | Initial implementation | The loader uses fixed-address `VirtualAlloc`, validates PE32 metadata and CRC32, and keeps the image non-executable. Wine and Windows tests remain. |
| Resource extraction | Initial implementation | The exporter currently finds 31 resources and emits deterministic `.res` and JSON files. Link and resource lookup tests remain. |
| Wine launcher | Implemented | The launcher validates `ADVINTER.pic`, converts paths with `winepath`, uses the local prefix, and starts only the source-built file. |
| MAGIC startup | Not verified | MinGW-w64 and Wine are not installed in the current environment. |
| Playable adventure loop | Not complete | This needs runtime debugging with legally obtained data and companion modules. |
| Source-built companion suite | Not started | Each of the six remaining modules needs its own generator input, ABI manifest, resources, and tests. |
| CMake parity | Deferred | Add this only after the Makefile reaches the playable milestone. |

## Build and launch interface

Install tools without automatic project-side package installation:

```sh
brew bundle
make pe-toolcheck
```

Build and launch:

```sh
make game-build
make game DATA_DIR="/path/to/legal/game/data"
```

The build must produce:

- `build/pe32/bin/MAGIC.EXE`
- `build/pe32/bin/magic_image.bin`
- `build/pe32/MAGIC.map`
- `build/generated/pe32/magic_resources.res`
- `build/generated/pe32/magic_resources.json`
- `build/generated/pe32/magic_pe_audit.json`
- `build/generated/pe32/magic_pe_audit.md`

## Phase 1: Prove the PE build skeleton

1. Install the packages from `Brewfile`.
2. Run `make pe-toolcheck` and record exact tool versions.
3. Compile every PE object with the i686 compiler.
4. Link `MAGIC.EXE` with the Windows GUI subsystem and the required system libraries.
5. Inspect the result with `i686-w64-mingw32-objdump`.
6. Confirm PE32/i386, image base `0x10000000`, disabled dynamic base, and the expected import set.
7. Start it in a new local Wine prefix.
8. Confirm that diagnostics show a four-byte pointer, the new module base, and the Wine version.

Exit gate: the minimal source-built GUI PE starts and exits cleanly under Wine.

### Known phase 1 gaps

- The generated source has passed a host-Clang syntax check, but it has not passed MinGW compilation.
- Decompiler conversions still produce many warnings. Each warning that can affect values, pointer ownership, or ABI behavior needs review.
- The current source unit uses recovered Win32 type declarations. Move public Win32 declarations to canonical MinGW headers after conflicts with recovered structures are resolved.
- Wine Homebrew casks are scheduled for deprecation. The build must document a replacement installation path if Homebrew removes the cask.

## Phase 2: Complete the generator and ABI audit

1. Separate common recovery transformations from native and PE target profiles.
2. Define each recovered internal function as 32-bit `__cdecl`.
3. Replace old-style CRT declarations with canonical CRT prototypes or small typed adapters.
4. Use canonical MinGW headers for all public Windows APIs.
5. Generate typed `WINAPI` and `CALLBACK` trampolines for window, dialog, timer, multimedia, thread, enumeration, and hook callbacks.
6. Find every indirect call and route recovered addresses through `MagicPe_ResolveCallable`.
7. Generate one sorted, duplicate-free map from original code addresses to compiled functions.
8. Add a module export manifest with module name, ordinal, signature, and calling convention for each ordinal lookup.
9. Fail generation for unresolved imports, unknown ordinals, raw callbacks, unsafe callable addresses, duplicate addresses, or incompatible structure layouts.
10. Add static assertions for 32-bit pointers, packing, field sizes, and critical Win32 layouts.

Exit gate: all generated MAGIC objects compile without implicit declarations, callback ABI warnings, or missing returns.

### Known phase 2 gaps

- The current audit detects unresolved calls and window callback assignments, but it does not yet prove all pointer conversions or structure layouts.
- Callback discovery covers observed API calls. Hook and less common enumeration callback types need an explicit inventory.
- `STATWIN.DLL` and `MAGSND.DLL` ordinal signatures need verified manifests.
- Direct CRT use and Microsoft-specific wrappers need a function-by-function ABI review.

## Phase 3: Validate the recovered image runtime

1. Locate runtime artifacts relative to the loaded `MAGIC.EXE` module.
2. Reserve and commit the full original virtual image range at `0x00400000`.
3. Reject a reservation at any other address.
4. Validate the MZ signature, PE signature, PE32 magic, source image base, `SizeOfImage`, exported file size, CRC32, and manifest version.
5. Load initialized bytes and leave the allocation as `PAGE_READWRITE`.
6. Reject calls into the mapped data image unless an original address has a generated callable entry.
7. Pass through only valid native 32-bit callable pointers.
8. Report the original address and recovered symbol for failures.
9. Implement trace groups for imports, calls, files, and resources.
10. Implement debugger breaks when `SHANDALAR_PE_BREAK_ON_ERROR=1`.

Exit gate: Wine and Windows tests can read known globals, resolve known functions, reject bad addresses, and release the mapping.

### Known phase 3 gaps

- Image signature validation uses CRC32. Add a versioned manifest and a cryptographic source hash.
- Native callable pass-through needs executable-page validation with `VirtualQuery`.
- Symbol names are not yet included in runtime resolution errors.
- Only import tracing is partially implemented. Call, file, and resource trace groups remain.
- Fixed-address collision and cleanup need automated Windows-side tests.

## Phase 4: Link real APIs and resources

1. Remove every SDL and native Win32-compatibility object from the PE link.
2. Resolve each import to a Windows library, the MinGW CRT, or a typed project adapter.
3. Link the generated COFF resource object.
4. Compare the exported resource manifest with a source manifest.
5. Test icons, menus, dialogs, accelerators, bitmaps, and arbitrary `FindResourceA` data by type, name, and language.
6. Save and inspect the linker map and import table.
7. Reach recovered `WinMain`, register the main class, create the window, start timers and threads, and close cleanly.

Exit gate: MAGIC reaches its main message loop without SDL or Mach-O dependencies.

### Known phase 4 gaps

- Resource data is exported, but source-versus-output manifest comparison is not yet independent.
- Resource directory flags are not stored in the linked PE resource tree. The exporter uses standard `.res` memory flags.
- Runtime resource lookup has not been tested under Wine.
- The expected import allow-list is not yet enforced after linking.

## Phase 5: Playable MAGIC milestone

Bring up and test these features in order:

1. Main window and message loop.
2. Palette and picture loading.
3. Title screen and main menu.
4. `MAGSND.DLL` loading and audio initialization.
5. `STATWIN.DLL` loading by ordinal.
6. New-game dialogs.
7. Player creation and difficulty selection.
8. Overworld entry.
9. Save and load.
10. Duel and deck transitions.

Trace every retail companion load as a temporary dependency. The source-built `MAGIC.EXE` must remain the only file named `MAGIC.EXE` that the launcher can select.

Exit gate: a user can create a game, enter the overworld, save, exit, and reload under Wine.

## Phase 6: Replace companion modules

Process modules in this order:

1. `STATWIN.DLL`
2. `MAGSND.DLL`
3. `MAGVID.DLL`
4. `DECKDLL.DLL`
5. `DUEL.EXE`
6. `DECK.EXE`

For each DLL:

- Generate source, an initialized image, resources, symbols, and an ABI audit.
- Preserve the retail basename.
- Generate a `.def` file with verified export names and ordinals.
- Preserve calling conventions, parameter layouts, and stack cleanup.
- Test every exported ordinal repeatedly to detect stack damage.

For each EXE:

- Preserve command-line parsing and working-directory behavior.
- Inventory window messages, files, registry entries, shared memory, and child-process contracts.
- Generate a separate map and audit.
- Test round trips from MAGIC into the module and back.

Exit gate: a staging directory with no retail EXE or DLL completes overworld, duel, deck editing, save, and load workflows.

### Known phase 6 gaps

- No companion-module PE generator profile exists.
- The repository needs exported initialized images and symbol manifests for each module.
- Export ordinals and signatures need verification against recovered call sites.
- Interprocess and intermodule contracts are not documented.
- The clean-suite asset staging tool does not exist.

## Test matrix

### Static and generator tests

- Repeat generation and compare files byte for byte.
- Require zero unresolved imports and unknown ordinals.
- Require a typed trampoline for every recovered callback.
- Require a callable mapping for every original indirect target.
- Validate pointer size, packing, structure sizes, and offsets.
- Compare resource type, name, language, size, and checksum manifests.

### Runtime tests

- Test successful and failed fixed-address allocation.
- Test all image metadata and hash failures.
- Test valid and invalid recovered data access.
- Test original callable resolution and invalid code rejection.
- Test artifact lookup relative to the module.
- Test data paths with spaces and non-ASCII characters.
- Test callback stack integrity under repeated calls.

### Wine integration tests

- Create a clean local WoW64 prefix.
- Confirm that Wine loads `build/pe32/bin/MAGIC.EXE`.
- Confirm that no retail `MAGIC.EXE` is opened.
- Test startup, menu, new game, audio, overworld, save/load, duel, and deck transitions.
- Save module-load traces.
- Run the final test with every retail EXE and DLL removed from the staged asset view.

### Windows integration tests

- Run the same artifacts through WOW64 on Windows x64 or Arm64.
- Repeat startup, menu, overworld, save/load, duel, and deck smoke tests.
- Confirm save-file compatibility between Wine and Windows.

## Completion criteria

The project is complete only when `make game` builds and starts the recovered PE, `make sidtest` still starts the Sid test program, all seven source-built modules pass their ABI audits, the clean-suite test contains no retail executable or DLL, the original initialized images remain data-only, and Wine and Windows smoke tests pass.

## Required external inputs

- A legally obtained data directory that contains `ADVINTER.pic` and the other game assets.
- Temporary retail companion modules for the phase 5 milestone.
- MinGW-w64 and Wine 11 or newer.
- A compatible Windows host for the required WOW64 test pass.

The build must not download dependencies, game data, or retail modules automatically.

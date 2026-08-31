# MAGIC Game Build Fix Plan

## Objective

Make the recovered PE32 `MAGIC.EXE` compile, link, and start under Wine with the installed MinGW GCC 16.2 toolchain. Keep useful diagnostics enabled while suppressing only warning classes that are unavoidable artifacts of the generated decompilation.

## Reproduction

The failing command was:

```sh
make game DATA_DIR="~/Downloads/shand-decomp/program" GAME_ARGS="/MTGshell /6"
```

The immediate failure occurs while compiling `build/generated/pe32/magic_pe.c`. The build does not reach Wine.

The requested data directory also has two separate problems:

- A quoted `~` is not expanded by the shell.
- `/Users/ben/Downloads/shand-decomp/program` does not exist.

The available directory `/Users/ben/Downloads/shand-extract/program` contains `ADVINTER.pic`. After the build is fixed, use:

```sh
make game DATA_DIR="/Users/ben/Downloads/shand-extract/program" GAME_ARGS="/MTGshell /6"
```

## Findings

### 1. GCC 16 reports required pointer-conversion diagnostics

The generated 120,000-line translation unit produces approximately:

- 1,526 pointer and integer conversions
- 1,724 signedness comparisons
- 386 pointer-signedness warnings
- 359 unused-but-set variables
- 308 precedence warnings
- 61 overflow warnings
- 46 built-in declaration mismatches
- 32 comparisons between distinct pointer types
- 19 character-subscript warnings
- 15 incompatible pointer types
- 3 missing returns

With GCC 16, `-Wno-error=int-conversion` is not sufficient. A compile probe required `-fpermissive` to downgrade the pointer and integer conversion diagnostics.

### 2. The generator emits invalid CRT declarations

`scripts/prepare_magic_pe.py` emits CRT functions as generic declarations of this form:

```c
uintptr_t function_name();
```

This creates invalid or misleading declarations for `_errno`, `malloc`, `fopen`, `strlen`, and many other CRT functions. The `_errno` declaration is a hard conflict because MinGW declares it as `int *_errno(void)`.

### 3. Import classification uses the wrong function set

The generator treats every prototype in `magic_unified.h` as a recovered function. Some of these functions are import thunks that are later removed from the generated body. They are therefore excluded from import generation even though no definition remains.

`GetSaveFileNameA` is one example. It keeps a generated `__cdecl` declaration instead of the required `WINAPI` declaration. The linker then searches for the wrong symbol.

### 4. Legacy CRT symbols do not link

After temporarily bypassing the compilation blockers, the linker reports missing symbols:

- `__p___mb_cur_max`
- `__p__pctype`
- `_atexit`

These are legacy MSVC interfaces and need typed MinGW-compatible replacements or adapters.

### 5. A companion import thunk becomes infinite recursion

The generated `DeckBuilderMain()` definition calls itself. The original function is an import thunk for `DECKDLL.DLL` ordinal 1. The current audit classifies it as recovered code and does not detect the recursion.

### 6. Optimization exposes additional unsafe constructs

At `-O2`, GCC also reports hundreds of possibly uninitialized values, array-bound issues, aggressive-loop warnings, and one infinite-recursion warning. Some can be decompiler artifacts, but the recursive import thunk is real. The initial PE build should use `-O0` until these cases are classified.

### 7. Current tests do not compile or link the PE

`make game-test` passes seven tests, and the generated ABI audit reports no fatal errors. Neither check compiles or links `MAGIC.EXE`, so both miss the current blockers.

## Fix Plan

### Phase 1: Correct recovered-function and import classification

1. Compute the recovered function set from definitions that remain after host and import thunks are removed.
2. Do not use every header prototype as proof that a recovered definition exists.
3. Remove CRT and external Win32 imports from the generated recovered-function header.
4. Generate typed import declarations from the compatibility manifest.
5. Make the audit fail when a called function has neither a generated definition nor a typed import.

Exit gate: `GetSaveFileNameA` is emitted with `WINAPI`, and no removed stub remains classified as recovered code.

### Phase 2: Add typed CRT compatibility

1. Replace the generic CRT declaration generation with canonical headers or typed adapters.
2. Use the correct `_errno` declaration or rewrite its uses through a project adapter.
3. Translate old multibyte and character-table access:
   - Replace `__p___mb_cur_max` behavior with `___mb_cur_max_func()`.
   - Replace `__p__pctype` behavior with `__pctype_func()`.
4. Add a typed adapter for `_atexit` that preserves the expected recovered callback convention.
5. Remove built-in declarations such as `uintptr_t malloc()` and `uintptr_t strlen()`.

Exit gate: the generated translation unit has no conflicting CRT declarations and the legacy CRT symbols do not appear as unresolved linker inputs.

### Phase 3: Handle companion-module imports

1. Remove the recursive `DeckBuilderMain` thunk from the recovered function set.
2. Generate an import library from `build/generated/pe32/deckdll.def`.
3. Link `DeckBuilderMain` against `DECKDLL.DLL` ordinal 1.
4. Extend the same mechanism to all retail companion imports used by the initial playable milestone.
5. Add an audit that rejects a generated function whose only operation is a direct call to itself.

Exit gate: `DeckBuilderMain` is an external PE import, not a generated recursive definition.

### Phase 4: Split compiler policies

Use strict flags for handwritten runtime code, callable maps, and callback trampolines. Use separate transitional flags only for the recovered translation unit.

Initial recovered-source policy:

- Compile at `-O0`.
- Add `-fpermissive` for GCC 16 pointer and integer diagnostics.
- Suppress high-volume decompiler noise only for `magic_pe.c`, including `int-conversion`, `sign-compare`, `pointer-sign`, and unused-but-set variables.

Do not suppress these categories globally:

- `overflow`
- `array-bounds`
- `uninitialized` and `maybe-uninitialized`
- `infinite-recursion`
- incompatible callback pointer types
- missing returns
- built-in declaration mismatches

Fix the missing-return transformation so that it matches generated `uintptr_t __cdecl` definitions. Keep callback ABI checks strict because a calling-convention mismatch can corrupt the 32-bit stack.

Exit gate: all generated and handwritten PE objects compile, with transitional suppressions scoped only to recovered decompiled source.

### Phase 5: Add real build acceptance tests

1. Extend `game-test` or add a separate toolchain test that compiles every PE object.
2. Link `MAGIC.EXE` as part of the acceptance test.
3. Inspect the result with `i686-w64-mingw32-objdump`.
4. Verify PE32/i386 format, image base `0x10000000`, disabled dynamic base, and the expected import set.
5. Assert that removed import stubs are absent from generated definitions.
6. Assert that generated functions do not directly recurse as unresolved import thunks.
7. Keep the existing deterministic generation and ABI-audit tests.

Exit gate: a clean build produces `build/pe32/bin/MAGIC.EXE` and the expected linker map without unresolved symbols.

### Phase 6: Wine startup validation

1. Run the source-built executable with the valid absolute data directory.
2. Confirm that the isolated Wine prefix initializes correctly.
3. Verify that the recovered image maps at its required address.
4. Confirm that `WinMain` is reached and the main window class is registered.
5. Trace system and companion imports during startup.
6. Stop at the first runtime ABI or resource error and add a focused regression test.

Exit gate: `MAGIC.EXE` reaches its main message loop and closes cleanly under Wine.

## Recommended Order

Implement phases 1 through 3 before changing warning flags. Then apply the scoped `-O0` and `-fpermissive` policy, add compile-and-link tests, and start Wine debugging. Do not use a blanket `-w` because it hides the overflow, recursion, ABI, and uninitialized-value diagnostics that can identify real runtime defects.

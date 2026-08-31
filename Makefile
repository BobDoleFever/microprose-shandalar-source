# ==============================================================================
# Makefile - MicroProse Magic: The Gathering (Shandalar) ANSI C Build
# ==============================================================================
CC ?= clang

# SDL2 paths
SDL_CFLAGS ?= -I/opt/homebrew/include/SDL2 -D_THREAD_SAFE
SDL_LDFLAGS ?= -L/opt/homebrew/lib -lSDL2 -lm

CFLAGS ?= -std=c99 -Wall -Wextra -O2 -Iinclude -Iinclude/shandalar $(SDL_CFLAGS) \
          -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function \
          -Wno-pointer-to-int-cast -Wno-int-to-pointer-cast

BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/obj

# Recovered 32-bit Windows build
PE_CC ?= i686-w64-mingw32-gcc
PE_WINDRES ?= i686-w64-mingw32-windres
PE_DLLTOOL ?= i686-w64-mingw32-dlltool
PE_OBJDUMP ?= i686-w64-mingw32-objdump
WINE ?= wine
WINEPATH ?= winepath
WINEPREFIX ?= $(abspath $(BUILD_DIR)/wineprefix)
WINEARCH ?= wow64
GAME_ARGS ?= /MTGshell /6
DATA_DIR ?= /Users/ben/Downloads/shand-extract/program

PE_BUILD_DIR = $(BUILD_DIR)/pe32
PE_BIN_DIR = $(PE_BUILD_DIR)/bin
PE_OBJ_DIR = $(PE_BUILD_DIR)/obj
PE_GEN_DIR = $(BUILD_DIR)/generated/pe32
PE_IMAGE = $(BUILD_DIR)/generated/magic_image.bin
PE_SYMBOLS = $(BUILD_DIR)/generated/magic_symbols.csv
PE_EXE = $(PE_BIN_DIR)/MAGIC.EXE
PE_ORDINALS = $(PE_GEN_DIR)/magic_module_ordinals.json
PE_CFLAGS = -m32 -std=gnu99 -O2 -Wall -Wextra \
            -Werror=implicit-function-declaration \
            -Werror=incompatible-pointer-types \
            -Werror=return-type \
            -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function \
            -I$(PE_GEN_DIR) -Iinclude -Iinclude/shandalar
PE_RECOVERED_CFLAGS = -m32 -std=gnu99 -O0 -fpermissive -Wall -Wextra \
            -Werror=implicit-function-declaration \
            -Werror=return-type \
            -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function \
            -Wno-int-conversion -Wno-incompatible-pointer-types \
            -Wno-sign-compare -Wno-pointer-sign -Wno-unused-but-set-variable \
            -Wno-parentheses -Wno-compare-distinct-pointer-types \
            -Wno-implicit-fallthrough \
            -I$(PE_GEN_DIR) -Iinclude -Iinclude/shandalar
PE_LDFLAGS = -m32 -mwindows \
             -Wl,--image-base,0x10000000 \
             -Wl,--disable-dynamicbase \
             -Wl,-Map,$(PE_BUILD_DIR)/MAGIC.map
PE_IMPORT_LIBS = $(PE_BUILD_DIR)/libdeckdll.a \
                 $(PE_BUILD_DIR)/libstatwin.a \
                 $(PE_BUILD_DIR)/libmagsnd.a \
                 $(PE_BUILD_DIR)/libmagvid.a
PE_LIBS = -L$(PE_BUILD_DIR) -ldeckdll -lstatwin -lmagsnd -lmagvid \
          -lkernel32 -luser32 -lgdi32 -ladvapi32 -lwinmm \
          -lcomdlg32 -lcomctl32 -lshell32 -lmsvfw32 -lvfw32

# Platform & Win32 Compat Subsystems
PLATFORM_OBJS = $(OBJ_DIR)/platform_handle.o \
                $(OBJ_DIR)/api_manifest.o \
                $(OBJ_DIR)/win32_user.o \
                $(OBJ_DIR)/win32_message.o \
                $(OBJ_DIR)/win32_gdi.o \
                $(OBJ_DIR)/win32_kernel.o \
                $(OBJ_DIR)/win32_config.o \
                $(OBJ_DIR)/win32_multimedia.o \
                $(OBJ_DIR)/win32_compat.o \
                $(OBJ_DIR)/display_shim_sdl2.o \
                $(OBJ_DIR)/sound_shim.o

# Core Subsystems
CORE_OBJS = $(OBJ_DIR)/sprite.o \
            $(OBJ_DIR)/Catalog.o \
            $(OBJ_DIR)/Test.o \
            $(PLATFORM_OBJS)

HEADERS = include/windows_types.h \
          include/shandalar/shandalar.h \
          include/shandalar/types.h \
          include/shandalar/sound.h \
          include/shandalar/ai.h \
          include/shandalar/magic_engine.h \
          include/shandalar/catalog.h \
          include/shandalar/sprite.h \
          include/shandalar/haar.h \
          include/shandalar/cards.h \
          include/shandalar/graphics.h \
          include/shandalar/fileio.h \
          include/shandalar/ui.h \
          include/shandalar/display_shim.h \
          include/shandalar/platform_handle.h \
          include/shandalar/api_manifest.h \
          include/shandalar/win32_internal.h \
          include/shandalar/win32_compat.h

.PHONY: all check run game game-build game-test game-native sidtest test clean \
        help sync stats pe-toolcheck pe-audit wine-prefix

all: check $(BUILD_DIR)/shandalar $(BUILD_DIR)/shandalar_game $(BUILD_DIR)/test_win32_compat
	@echo "Build complete."
	@echo "  -> Test Runner: $(BUILD_DIR)/shandalar"
	@echo "  -> Sid Test Program: $(BUILD_DIR)/shandalar_game"
	@echo "  -> Win32 Compat Test Suite: $(BUILD_DIR)/test_win32_compat"

sync:
	@echo "Synchronizing symbols with Ghidra database across all 7 binaries..."
	python3 scripts/refactor_all_subsystems.py

stats:
	@echo "=========================================================="
	@echo " Shandalar Decompilation & Symbol Statistics"
	@echo "=========================================================="
	@python3 -c "import csv; \
		g = sum(1 for _ in open('engine_globals_map.csv')) - 1; \
		u = sum(1 for _ in open('unified_engine_symbol_map.csv')) - 1; \
		m = sum(1 for _ in open('magic_symbol_renames.csv')) - 1; \
		d = sum(1 for _ in open('duel_symbol_renames.csv')) - 1; \
		print(f'  Total Refactored Engine Globals: {g}'); \
		print(f'  Total Unified Function Symbols:  {u}'); \
		print(f'  MAGIC.EXE Function Renames:      {m}'); \
		print(f'  DUEL.EXE Function Renames:       {d}'); \
		print('==========================================================')"

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR) $(OBJ_DIR)

$(OBJ_DIR)/sprite.o: src/magic/sidlib/sprite.c $(HEADERS) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/Catalog.o: src/magic/NedCard/Catalog.c $(HEADERS) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/Test.o: src/magic/sid/Test.c $(HEADERS) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/platform_handle.o: src/platform/platform_handle.c $(HEADERS) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/api_manifest.o: src/platform/api_manifest.c $(HEADERS) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/win32_user.o: src/platform/win32_user.c $(HEADERS) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/win32_message.o: src/platform/win32_message.c $(HEADERS) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/win32_gdi.o: src/platform/win32_gdi.c $(HEADERS) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/win32_kernel.o: src/platform/win32_kernel.c $(HEADERS) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/win32_config.o: src/platform/win32_config.c $(HEADERS) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/win32_multimedia.o: src/platform/win32_multimedia.c $(HEADERS) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/win32_compat.o: src/platform/win32_compat.c $(HEADERS) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/display_shim_sdl2.o: src/platform/display_shim_sdl2.c $(HEADERS) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/sound_shim.o: src/platform/sound_shim.c $(HEADERS) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/main.o: src/main.c $(HEADERS) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/main_game_entry.o: src/main_game_entry.c $(HEADERS) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/test_win32_compat.o: tests/test_win32_compat.c $(HEADERS) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/libshandalar_core.a: $(CORE_OBJS)
	ar rcs $@ $^

$(BUILD_DIR)/shandalar: $(OBJ_DIR)/main.o $(BUILD_DIR)/libshandalar_core.a
	$(CC) $(CFLAGS) $< -L$(BUILD_DIR) -lshandalar_core $(SDL_LDFLAGS) -o $@

$(BUILD_DIR)/shandalar_game: $(OBJ_DIR)/main_game_entry.o $(BUILD_DIR)/libshandalar_core.a
	$(CC) $(CFLAGS) $< -L$(BUILD_DIR) -lshandalar_core $(SDL_LDFLAGS) -o $@

$(BUILD_DIR)/test_win32_compat: $(OBJ_DIR)/test_win32_compat.o $(BUILD_DIR)/libshandalar_core.a
	$(CC) $(CFLAGS) $< -L$(BUILD_DIR) -lshandalar_core $(SDL_LDFLAGS) -o $@

check:
	@echo "Verifying Shandalar ANSI C headers syntax..."
	$(CC) -fsyntax-only -std=c99 -Iinclude -Iinclude/shandalar $(SDL_CFLAGS) include/shandalar/shandalar.h
	@echo "Verifying Win32 compatibility headers syntax..."
	$(CC) -fsyntax-only -std=c99 -Iinclude -Iinclude/shandalar $(SDL_CFLAGS) include/shandalar/win32_compat.h
	@echo "Verifying 2D Sprite engine syntax..."
	$(CC) -fsyntax-only -std=c99 -Iinclude -Iinclude/shandalar $(SDL_CFLAGS) src/magic/sidlib/sprite.c
	@echo "Verifying Card Catalog engine syntax..."
	$(CC) -fsyntax-only -std=c99 -Iinclude -Iinclude/shandalar $(SDL_CFLAGS) src/magic/NedCard/Catalog.c
	@echo "Verifying WinMain entry module (Test.c) syntax..."
	$(CC) -fsyntax-only -std=c99 -Iinclude -Iinclude/shandalar $(SDL_CFLAGS) src/magic/sid/Test.c
	@echo "Verifying Platform Handle Subsystem syntax..."
	$(CC) -fsyntax-only -std=c99 -Iinclude -Iinclude/shandalar $(SDL_CFLAGS) src/platform/platform_handle.c
	@echo "Verifying Platform API Manifest syntax..."
	$(CC) -fsyntax-only -std=c99 -Iinclude -Iinclude/shandalar $(SDL_CFLAGS) src/platform/api_manifest.c
	@echo "Verifying Win32 User Subsystem syntax..."
	$(CC) -fsyntax-only -std=c99 -Iinclude -Iinclude/shandalar $(SDL_CFLAGS) src/platform/win32_user.c
	@echo "Verifying Win32 Message Subsystem syntax..."
	$(CC) -fsyntax-only -std=c99 -Iinclude -Iinclude/shandalar $(SDL_CFLAGS) src/platform/win32_message.c
	@echo "Verifying Win32 GDI Subsystem syntax..."
	$(CC) -fsyntax-only -std=c99 -Iinclude -Iinclude/shandalar $(SDL_CFLAGS) src/platform/win32_gdi.c
	@echo "Verifying Win32 Kernel Subsystem syntax..."
	$(CC) -fsyntax-only -std=c99 -Iinclude -Iinclude/shandalar $(SDL_CFLAGS) src/platform/win32_kernel.c
	@echo "Verifying Win32 Config Subsystem syntax..."
	$(CC) -fsyntax-only -std=c99 -Iinclude -Iinclude/shandalar $(SDL_CFLAGS) src/platform/win32_config.c
	@echo "Verifying Win32 Multimedia Subsystem syntax..."
	$(CC) -fsyntax-only -std=c99 -Iinclude -Iinclude/shandalar $(SDL_CFLAGS) src/platform/win32_multimedia.c
	@echo "Verifying SDL2 Modern Display Shim syntax..."
	$(CC) -fsyntax-only -std=c99 -Iinclude -Iinclude/shandalar $(SDL_CFLAGS) src/platform/display_shim_sdl2.c
	@echo "Verifying SDL2 Sound Shim syntax..."
	$(CC) -fsyntax-only -std=c99 -Iinclude -Iinclude/shandalar $(SDL_CFLAGS) src/platform/sound_shim.c
	@echo "Verifying Win32 Compatibility Master Shim syntax..."
	$(CC) -fsyntax-only -std=c99 -Iinclude -Iinclude/shandalar $(SDL_CFLAGS) src/platform/win32_compat.c
	@echo "All syntax checks passed with 0 errors!"

test: $(BUILD_DIR)/test_win32_compat $(BUILD_DIR)/shandalar
	@echo "Running Win32 Compatibility Layer unit tests..."
	SDL_VIDEODRIVER=dummy ./$(BUILD_DIR)/test_win32_compat
	@echo "Running automated Shandalar engine verification test..."
	SDL_VIDEODRIVER=dummy ./$(BUILD_DIR)/shandalar --test

run: $(BUILD_DIR)/shandalar
	./$(BUILD_DIR)/shandalar

$(PE_GEN_DIR) $(PE_BIN_DIR) $(PE_OBJ_DIR):
	mkdir -p $@

$(PE_GEN_DIR)/.generated: scripts/prepare_magic_pe.py scripts/prepare_magic_native.py \
		magic/magic_unified.c magic/magic_unified.h $(PE_SYMBOLS) $(PE_IMAGE) $(PE_ORDINALS) | $(PE_GEN_DIR)
	python3 scripts/prepare_magic_pe.py \
		--source magic/magic_unified.c \
		--header magic/magic_unified.h \
		--symbols $(PE_SYMBOLS) \
		--ordinals $(PE_ORDINALS) \
		--output-dir $(PE_GEN_DIR)
	touch $@

$(PE_GEN_DIR)/.resources: scripts/export_magic_pe_resources.py $(PE_IMAGE) | $(PE_GEN_DIR)
	python3 scripts/export_magic_pe_resources.py \
		--image $(PE_IMAGE) \
		--output-res $(PE_GEN_DIR)/magic_resources.res \
		--output-manifest $(PE_GEN_DIR)/magic_resources.json
	touch $@

$(PE_GEN_DIR)/magic_resources.res $(PE_GEN_DIR)/magic_resources.json: $(PE_GEN_DIR)/.resources

$(PE_ORDINALS): scripts/generate_pe_ordinal_manifest.py \
		statwin/function_index.csv statwin/symbols.csv statwin/statwin_unified.h \
		magsnd/function_index.csv magsnd/symbols.csv magsnd/magsnd_unified.h \
		magvid/function_index.csv magvid/symbols.csv magvid/magvid_unified.h \
		deckdll/function_index.csv deckdll/symbols.csv deckdll/deckdll_unified.h | $(PE_GEN_DIR)
	python3 scripts/generate_pe_ordinal_manifest.py --root . --output $@ --def-dir $(PE_GEN_DIR)

$(PE_BUILD_DIR)/libdeckdll.a: $(PE_GEN_DIR)/deckdll.def | $(PE_BUILD_DIR)
	$(PE_DLLTOOL) -d $< -l $@ -D DECKDLL.DLL

$(PE_BUILD_DIR)/libstatwin.a: $(PE_GEN_DIR)/statwin.def | $(PE_BUILD_DIR)
	$(PE_DLLTOOL) -d $< -l $@ -D STATWIN.DLL

$(PE_BUILD_DIR)/libmagsnd.a: $(PE_GEN_DIR)/magsnd.def | $(PE_BUILD_DIR)
	$(PE_DLLTOOL) -d $< -l $@ -D MAGSND.DLL

$(PE_BUILD_DIR)/libmagvid.a: $(PE_GEN_DIR)/magvid.def | $(PE_BUILD_DIR)
	$(PE_DLLTOOL) -d $< -l $@ -D MAGVID.DLL

$(PE_OBJ_DIR)/magic_resources.o: $(PE_GEN_DIR)/magic_resources.res | $(PE_OBJ_DIR)
	$(PE_WINDRES) -J res -O coff -F pe-i386 $< $@

$(PE_OBJ_DIR)/magic_pe.o: $(PE_GEN_DIR)/magic_pe.c $(PE_GEN_DIR)/.generated | $(PE_OBJ_DIR)
	$(PE_CC) $(PE_RECOVERED_CFLAGS) -c $< -o $@

$(PE_OBJ_DIR)/magic_callable_map.o: $(PE_GEN_DIR)/magic_callable_map.c $(PE_GEN_DIR)/.generated | $(PE_OBJ_DIR)
	$(PE_CC) $(PE_CFLAGS) -c $< -o $@

$(PE_OBJ_DIR)/magic_callback_trampolines.o: $(PE_GEN_DIR)/magic_callback_trampolines.c \
		$(PE_GEN_DIR)/.generated | $(PE_OBJ_DIR)
	$(PE_CC) $(PE_CFLAGS) -c $< -o $@

$(PE_OBJ_DIR)/magic_pe_runtime.o: src/magic_pe_runtime.c \
		include/shandalar/magic_pe_runtime.h $(PE_GEN_DIR)/.generated | $(PE_OBJ_DIR)
	$(PE_CC) $(PE_CFLAGS) -c $< -o $@

$(PE_OBJ_DIR)/main_magic_pe.o: src/main_magic_pe.c \
		include/shandalar/magic_pe_runtime.h $(PE_GEN_DIR)/.generated | $(PE_OBJ_DIR)
	$(PE_CC) $(PE_CFLAGS) -c $< -o $@

$(PE_EXE): $(PE_OBJ_DIR)/main_magic_pe.o $(PE_OBJ_DIR)/magic_pe_runtime.o \
		$(PE_OBJ_DIR)/magic_pe.o $(PE_OBJ_DIR)/magic_callable_map.o \
		$(PE_OBJ_DIR)/magic_callback_trampolines.o $(PE_OBJ_DIR)/magic_resources.o \
		$(PE_IMPORT_LIBS) $(PE_IMAGE) | $(PE_BIN_DIR)
	$(PE_CC) $(PE_LDFLAGS) \
		$(PE_OBJ_DIR)/main_magic_pe.o \
		$(PE_OBJ_DIR)/magic_pe_runtime.o \
		$(PE_OBJ_DIR)/magic_pe.o \
		$(PE_OBJ_DIR)/magic_callable_map.o \
		$(PE_OBJ_DIR)/magic_callback_trampolines.o \
		$(PE_OBJ_DIR)/magic_resources.o \
		$(PE_LIBS) -o $@
	cp $(PE_IMAGE) $(PE_BIN_DIR)/magic_image.bin

pe-toolcheck:
	python3 scripts/check_pe_toolchain.py \
		--compiler "$(PE_CC)" \
		--windres "$(PE_WINDRES)" \
		--wine "$(WINE)" \
		--winepath "$(WINEPATH)"

pe-audit: $(PE_GEN_DIR)/.generated $(PE_ORDINALS)
	python3 scripts/check_magic_pe_audit.py \
		$(PE_GEN_DIR)/magic_pe_audit.json $(PE_ORDINALS)

game-build: pe-toolcheck pe-audit $(PE_EXE)

$(WINEPREFIX)/.shandalar-initialized: pe-toolcheck
	mkdir -p "$(WINEPREFIX)"
	WINEARCH="$(WINEARCH)" WINEPREFIX="$(WINEPREFIX)" "$(WINE)" wineboot -u
	touch $@

wine-prefix: $(WINEPREFIX)/.shandalar-initialized

game: game-build wine-prefix
	DATA_DIR="$(DATA_DIR)" GAME_ARGS="$(GAME_ARGS)" \
		WINE="$(WINE)" WINEPATH="$(WINEPATH)" \
		WINEARCH="$(WINEARCH)" WINEPREFIX="$(WINEPREFIX)" \
		scripts/run_magic_wine.sh "$(PE_EXE)"

game-test: $(PE_GEN_DIR)/.generated $(PE_ORDINALS) $(PE_GEN_DIR)/.resources
	python3 -m unittest tests.test_magic_pe

game-native:
	@echo "The arm64 address-virtualization build remains experimental." >&2
	@echo "Use the PE32 'game-build' target for the recovered game." >&2
	@false

sidtest: $(BUILD_DIR)/shandalar_game
	./$(BUILD_DIR)/shandalar_game

clean:
	rm -rf $(OBJ_DIR) $(PE_BUILD_DIR) $(WINEPREFIX) $(PE_GEN_DIR)
	rm -f $(BUILD_DIR)/shandalar $(BUILD_DIR)/shandalar_game \
		$(BUILD_DIR)/test_win32_compat
	rm -f $(BUILD_DIR)/generated/magic_native.c \
		$(BUILD_DIR)/generated/magic_native.h \
		$(BUILD_DIR)/generated/magic_native.o \
		$(BUILD_DIR)/generated/magic_native_runtime.o \
		$(BUILD_DIR)/generated/main_magic_native.o
	@echo "Preserved $(PE_IMAGE) and $(PE_SYMBOLS)."

help:
	@echo "Available targets:"
	@echo "  make check  - Verify syntax of all headers and C modules"
	@echo "  make all    - Build the test runners and unit tests"
	@echo "  make test   - Run automated headless unit and engine tests"
	@echo "  make pe-toolcheck - Verify the MinGW-w64 and Wine 11 tools"
	@echo "  make pe-audit - Verify the generated PE32 ABI report"
	@echo "  make game-build - Build MAGIC.EXE from the recovered source"
	@echo "  make sync   - Synchronize symbols with Ghidra across all 7 binaries"
	@echo "  make stats  - Display decompilation and symbol naming metrics"
	@echo "  make run    - Run interactive test runner"
	@echo "  make game   - Build and launch the recovered PE32 game with Wine"
	@echo "  make game-test - Run PE32 generator and runtime tests"
	@echo "  make game-native - Report the experimental arm64 port status"
	@echo "  make sidtest - Launch the reconstructed Sid test program"
	@echo "  make clean  - Remove build artifacts"

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

# Core Subsystems
CORE_SRCS = src/magic/sidlib/sprite.c \
            src/magic/NedCard/Catalog.c \
            src/magic/sid/Test.c \
            src/platform/display_shim_sdl2.c \
            src/platform/sound_shim.c \
            src/platform/win32_compat.c

HEADERS = include/shandalar/shandalar.h \
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
          include/shandalar/win32_compat.h

OBJS = $(OBJ_DIR)/sprite.o \
       $(OBJ_DIR)/Catalog.o \
       $(OBJ_DIR)/Test.o \
       $(OBJ_DIR)/display_shim_sdl2.o \
       $(OBJ_DIR)/sound_shim.o \
       $(OBJ_DIR)/win32_compat.o

.PHONY: all check run game test clean help sync stats

all: check $(BUILD_DIR)/shandalar $(BUILD_DIR)/shandalar_game
	@echo "Build complete."
	@echo "  -> Test Runner: $(BUILD_DIR)/shandalar"
	@echo "  -> Full Game Entry: $(BUILD_DIR)/shandalar_game"

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

$(OBJ_DIR)/display_shim_sdl2.o: src/platform/display_shim_sdl2.c $(HEADERS) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/sound_shim.o: src/platform/sound_shim.c $(HEADERS) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/win32_compat.o: src/platform/win32_compat.c $(HEADERS) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/main.o: src/main.c $(HEADERS) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/main_game_entry.o: src/main_game_entry.c $(HEADERS) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/libshandalar_core.a: $(OBJS)
	ar rcs $@ $^

$(BUILD_DIR)/shandalar: $(OBJ_DIR)/main.o $(BUILD_DIR)/libshandalar_core.a
	$(CC) $(CFLAGS) $< -L$(BUILD_DIR) -lshandalar_core $(SDL_LDFLAGS) -o $@

$(BUILD_DIR)/shandalar_game: $(OBJ_DIR)/main_game_entry.o $(BUILD_DIR)/libshandalar_core.a
	$(CC) $(CFLAGS) $< -L$(BUILD_DIR) -lshandalar_core $(SDL_LDFLAGS) -o $@

check:
	@echo "Verifying Shandalar ANSI C headers syntax..."
	$(CC) -fsyntax-only -std=c99 -Iinclude -Iinclude/shandalar $(SDL_CFLAGS) include/shandalar/shandalar.h
	@echo "Verifying 2D Sprite engine syntax..."
	$(CC) -fsyntax-only -std=c99 -Iinclude -Iinclude/shandalar src/magic/sidlib/sprite.c
	@echo "Verifying Card Catalog engine syntax..."
	$(CC) -fsyntax-only -std=c99 -Iinclude -Iinclude/shandalar src/magic/NedCard/Catalog.c
	@echo "Verifying WinMain entry module (Test.c) syntax..."
	$(CC) -fsyntax-only -std=c99 -Iinclude -Iinclude/shandalar $(SDL_CFLAGS) src/magic/sid/Test.c
	@echo "Verifying SDL2 Modern Display Shim syntax..."
	$(CC) -fsyntax-only -std=c99 -Iinclude -Iinclude/shandalar $(SDL_CFLAGS) src/platform/display_shim_sdl2.c
	@echo "Verifying SDL2 Sound Shim syntax..."
	$(CC) -fsyntax-only -std=c99 -Iinclude -Iinclude/shandalar $(SDL_CFLAGS) src/platform/sound_shim.c
	@echo "Verifying Win32 Compatibility Shim syntax..."
	$(CC) -fsyntax-only -std=c99 -Iinclude -Iinclude/shandalar $(SDL_CFLAGS) src/platform/win32_compat.c
	@echo "All syntax checks passed with 0 errors!"

test: $(BUILD_DIR)/shandalar
	@echo "Running automated Shandalar engine verification test..."
	./$(BUILD_DIR)/shandalar --test

run: $(BUILD_DIR)/shandalar
	./$(BUILD_DIR)/shandalar

game: $(BUILD_DIR)/shandalar_game
	./$(BUILD_DIR)/shandalar_game

clean:
	rm -rf $(BUILD_DIR)

help:
	@echo "Available targets:"
	@echo "  make check  - Verify syntax of all headers and C modules"
	@echo "  make all    - Build all binaries (test runner and game entry)"
	@echo "  make test   - Run automated headless engine verification test"
	@echo "  make sync   - Synchronize symbols with Ghidra across all 7 binaries"
	@echo "  make stats  - Display decompilation and symbol naming metrics"
	@echo "  make run    - Run interactive test runner"
	@echo "  make game   - Launch game from authentic WinMain entry point"
	@echo "  make clean  - Remove build artifacts"

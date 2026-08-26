# ==============================================================================
# CMakeLists.txt - MicroProse 1997 Magic: The Gathering (Shandalar)
# Modern ANSI C Reconstructed Build Configuration
# ==============================================================================
cmake_minimum_required(VERSION 3.16)
project(ShandalarDecomp
    VERSION 1.0.0
    DESCRIPTION "Decompiled ANSI C Codebase for MicroProse Magic: The Gathering (1997)"
    LANGUAGES C
)

# ------------------------------------------------------------------------------
# C Standard & Compiler Options
# ------------------------------------------------------------------------------
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

if(MSVC)
    add_compile_options(/W3 /WX- /O2 /Oi /Oy-)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS -D_CRT_NONSTDC_NO_DEPRECATE)
else()
    add_compile_options(
        -Wall
        -Wextra
        -Wno-unused-parameter
        -Wno-unused-variable
        -Wno-unused-function
        -Wno-pointer-to-int-cast
        -Wno-int-to-pointer-cast
        -O2
    )
endif()

# ------------------------------------------------------------------------------
# Include Directories
# ------------------------------------------------------------------------------
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/include/shandalar
)

# ------------------------------------------------------------------------------
# Source Groups & Definitions
# ------------------------------------------------------------------------------
set(SHANDALAR_COMMON_HEADERS
    include/shandalar/shandalar.h
    include/shandalar/types.h
    include/shandalar/sound.h
    include/shandalar/ai.h
    include/shandalar/magic_engine.h
    include/shandalar/cards.h
    include/shandalar/catalog.h
    include/shandalar/sprite.h
    include/shandalar/haar.h
    include/shandalar/graphics.h
    include/shandalar/fileio.h
    include/shandalar/ui.h
    include/windows_types.h
)

# Shared Subsystem Core Library
set(SHANDALAR_CORE_SOURCES
    src/magic/sidlib/sprite.c
    src/magic/sidlib/Fileio.c
    src/magic/sidlib/text.c
    src/magic/sidlib/Pcxw.c
    src/magic/NedCard/Catalog.c
    src/magic/NedCard/Palette.c
    src/magic/NedCard/haar.c
    src/magic/sid/Ai.c
    src/magic/sid/Magic.c
    src/magic/sid/Minit.c
    src/magic/sid/glue.c
)

add_library(shandalar_core STATIC
    ${SHANDALAR_CORE_SOURCES}
    ${SHANDALAR_COMMON_HEADERS}
)

target_include_directories(shandalar_core PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/include/shandalar
)

# ------------------------------------------------------------------------------
# Executables
# ------------------------------------------------------------------------------

# 1. Main Game Engine (MAGIC.EXE equivalent)
add_library(magic_monolithic STATIC
    magic/magic_all.c
)
target_include_directories(magic_monolithic PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/include/shandalar
)

# 2. Standalone Duel Match Engine (DUEL.EXE equivalent)
add_library(duel_monolithic STATIC
    duel/duel_all.c
)
target_include_directories(duel_monolithic PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/include/shandalar
)

# ------------------------------------------------------------------------------
# Tests & Verification
# ------------------------------------------------------------------------------
enable_testing()

add_custom_target(check_syntax
    COMMAND ${CMAKE_C_COMPILER} -fsyntax-only -std=c99
            -I${CMAKE_CURRENT_SOURCE_DIR}/include
            -I${CMAKE_CURRENT_SOURCE_DIR}/include/shandalar
            ${CMAKE_CURRENT_SOURCE_DIR}/src/magic/sidlib/sprite.c
    COMMAND ${CMAKE_C_COMPILER} -fsyntax-only -std=c99
            -I${CMAKE_CURRENT_SOURCE_DIR}/include
            -I${CMAKE_CURRENT_SOURCE_DIR}/include/shandalar
            ${CMAKE_CURRENT_SOURCE_DIR}/include/shandalar/shandalar.h
    COMMENT "Verifying Shandalar ANSI C headers and modules syntax..."
)

message(STATUS "Configured ShandalarDecomp ANSI C Build System successfully.")

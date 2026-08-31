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
# SDL2 Dependencies
# ------------------------------------------------------------------------------
find_package(SDL2 REQUIRED)

# ------------------------------------------------------------------------------
# Include Directories
# ------------------------------------------------------------------------------
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/include/shandalar
    ${SDL2_INCLUDE_DIRS}
)

# ------------------------------------------------------------------------------
# Source Groups & Definitions
# ------------------------------------------------------------------------------
set(SHANDALAR_COMMON_HEADERS
    include/windows_types.h
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
    include/shandalar/display_shim.h
    include/shandalar/platform_handle.h
    include/shandalar/api_manifest.h
    include/shandalar/win32_internal.h
    include/shandalar/win32_compat.h
)

set(SHANDALAR_PLATFORM_SOURCES
    src/platform/platform_handle.c
    src/platform/api_manifest.c
    src/platform/win32_user.c
    src/platform/win32_message.c
    src/platform/win32_gdi.c
    src/platform/win32_kernel.c
    src/platform/win32_config.c
    src/platform/win32_multimedia.c
    src/platform/win32_compat.c
    src/platform/display_shim_sdl2.c
    src/platform/sound_shim.c
)

# Shared Subsystem Core Library
set(SHANDALAR_CORE_SOURCES
    src/magic/sidlib/sprite.c
    src/magic/NedCard/Catalog.c
    src/magic/sid/Test.c
    ${SHANDALAR_PLATFORM_SOURCES}
)

add_library(shandalar_core STATIC
    ${SHANDALAR_CORE_SOURCES}
    ${SHANDALAR_COMMON_HEADERS}
)

target_include_directories(shandalar_core PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/include/shandalar
    ${SDL2_INCLUDE_DIRS}
)

target_link_libraries(shandalar_core PUBLIC
    ${SDL2_LIBRARIES}
    m
)

# ------------------------------------------------------------------------------
# Executables
# ------------------------------------------------------------------------------

# 1. Test Runner Executable
add_executable(shandalar
    src/main.c
)
target_link_libraries(shandalar PRIVATE shandalar_core ${SDL2_LIBRARIES} m)

# 2. Authentic Game Entry Point Executable
add_executable(shandalar_game
    src/main_game_entry.c
)
target_link_libraries(shandalar_game PRIVATE shandalar_core ${SDL2_LIBRARIES} m)

# 3. Win32 Compatibility Layer Unit Test Suite
add_executable(test_win32_compat
    tests/test_win32_compat.c
)
target_link_libraries(test_win32_compat PRIVATE shandalar_core ${SDL2_LIBRARIES} m)

# ------------------------------------------------------------------------------
# Tests & Verification
# ------------------------------------------------------------------------------
enable_testing()

add_test(NAME Win32CompatTest COMMAND test_win32_compat)
set_tests_properties(Win32CompatTest PROPERTIES ENVIRONMENT "SDL_VIDEODRIVER=dummy")

add_test(NAME EngineVerificationTest COMMAND shandalar --test)
set_tests_properties(EngineVerificationTest PROPERTIES ENVIRONMENT "SDL_VIDEODRIVER=dummy")

message(STATUS "Configured ShandalarDecomp ANSI C Build System successfully.")

#!/bin/sh
set -eu

if [ "$#" -ne 1 ]; then
    echo "Usage: run_magic_wine.sh <MAGIC.EXE>" >&2
    exit 2
fi

game_exe=$1
wine_command=${WINE:-wine}
winepath_command=${WINEPATH:-winepath}
data_dir=${DATA_DIR:-${SHANDALAR_DATA_DIR:-}}
game_args=${GAME_ARGS:-/MTGshell /6}

if [ ! -f "$game_exe" ]; then
    echo "The source-built game does not exist: $game_exe" >&2
    exit 2
fi
if [ -z "$data_dir" ]; then
    echo "Set DATA_DIR or SHANDALAR_DATA_DIR to the game data directory." >&2
    exit 2
fi
if [ ! -d "$data_dir" ]; then
    echo "The game data directory does not exist: $data_dir" >&2
    exit 2
fi
if [ ! -f "$data_dir/ADVINTER.pic" ] && [ ! -f "$data_dir/advinter.pic" ]; then
    echo "The game data directory does not contain ADVINTER.pic: $data_dir" >&2
    exit 2
fi

game_exe_absolute=$(cd "$(dirname "$game_exe")" && pwd)/$(basename "$game_exe")
data_dir_absolute=$(cd "$data_dir" && pwd)
game_exe_windows=$($winepath_command -w "$game_exe_absolute")
data_dir_windows=$($winepath_command -w "$data_dir_absolute")

export SHANDALAR_DATA_DIR_WIN=$data_dir_windows
set -- $game_args
exec "$wine_command" "$game_exe_windows" "$@"

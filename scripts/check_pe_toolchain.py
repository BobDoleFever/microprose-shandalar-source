#!/usr/bin/env python3
"""Check the tools that build and run the recovered PE32 game."""

from __future__ import annotations

import argparse
import re
import shlex
import shutil
import subprocess
import sys


def parse_arguments() -> argparse.Namespace:
    parser = argparse.ArgumentParser()
    parser.add_argument("--compiler", required=True)
    parser.add_argument("--windres", required=True)
    parser.add_argument("--wine", required=True)
    parser.add_argument("--winepath", required=True)
    return parser.parse_args()


def executable(command: str) -> str | None:
    words = shlex.split(command)
    return shutil.which(words[0]) if words else None


def version_output(command: str) -> str:
    words = shlex.split(command)
    result = subprocess.run(
        [*words, "--version"],
        check=False,
        capture_output=True,
        text=True,
    )
    return (result.stdout or result.stderr).strip()


def main() -> int:
    arguments = parse_arguments()
    tools = {
        "i686 compiler": arguments.compiler,
        "resource compiler": arguments.windres,
        "Wine": arguments.wine,
        "winepath": arguments.winepath,
    }
    missing = [label for label, command in tools.items() if executable(command) is None]
    if missing:
        print("Missing PE32 tools: " + ", ".join(missing), file=sys.stderr)
        print("Run 'brew bundle' from the repository root.", file=sys.stderr)
        return 2

    wine_version = version_output(arguments.wine)
    match = re.search(r"wine-(\d+)(?:\.(\d+))?", wine_version, re.IGNORECASE)
    if match is None:
        print(f"Could not read the Wine version: {wine_version}", file=sys.stderr)
        return 2
    if int(match.group(1)) < 11:
        print(f"Wine 11 or newer is required: {wine_version}", file=sys.stderr)
        return 2

    compiler_version = version_output(arguments.compiler).splitlines()[0]
    print(f"PE32 compiler: {compiler_version}")
    print(f"Wine runtime: {wine_version.splitlines()[0]}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())

#!/usr/bin/env python3
"""
Derive the argument count of every imported function from how the decompiled code calls it (the most
common count over all call sites), for stdcall stack clean-up in pe_run.py.

    python3 derive_argc.py [decompiled .c ...] > argc_magic.json
"""
import collections
import json
import os
import re
import sys

import pefile

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.join(HERE, "..", "..")
EXE = os.path.join(ROOT, "sources", "installed", "Magic", "Program", "MAGIC.EXE")


def split_args(text, start):
    """Count top-level arguments of the call whose '(' is at text[start]."""
    depth, n, seen, i = 0, 0, False, start
    while i < len(text):
        c = text[i]
        if c in "([{":
            depth += 1
        elif c in ")]}":
            depth -= 1
            if depth == 0:
                return n + (1 if seen else 0)
        elif c == "," and depth == 1:
            n += 1
        elif depth == 1 and not c.isspace():
            seen = True
        i += 1
    return None


def main():
    files = sys.argv[1:] or [os.path.join(ROOT, "magic", "magic_unified.c")]
    pe = pefile.PE(EXE)
    names = [i.name.decode() for e in pe.DIRECTORY_ENTRY_IMPORT for i in e.imports if i.name
             and not e.dll.decode().lower().startswith("msvcrt")]
    counts = {n: collections.Counter() for n in names}
    for f in files:
        text = open(f, errors="replace").read()
        for n in names:
            for m in re.finditer(r"\b%s\(" % re.escape(n), text):
                a = split_args(text, m.end() - 1)
                if a is not None:
                    counts[n][a] += 1
    out = {n: c.most_common(1)[0][0] for n, c in counts.items() if c}
    missing = [n for n in names if n not in out]
    json.dump(out, sys.stdout, indent=0, sort_keys=True)
    print(f"\n{len(out)} of {len(names)} non-CRT imports have call sites; no call site: {missing}", file=sys.stderr)


if __name__ == "__main__":
    main()

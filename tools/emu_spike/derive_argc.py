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


PROGRAMS = {"MAGIC.EXE": "magic", "DUEL.EXE": "duel", "DECK.EXE": "deck", "DECKDLL.DLL": "deckdll",
            "STATWIN.DLL": "statwin", "MAGSND.DLL": "magsnd", "MAGVID.DLL": "magvid"}
EXTRA = {"GetPrivateProfileStringA": 6, "SetWindowRgn": 3, "CreatePolygonRgn": 3, "DisableThreadLibraryCalls": 1}


def main():
    """One table for all seven binaries: each import's argument count from that binary's own decompiled calls."""
    prog_dir = os.path.dirname(EXE)
    out, missing = {}, set()
    for exe, folder in PROGRAMS.items():
        path = os.path.join(prog_dir, exe)
        src = os.path.join(ROOT, folder, f"{folder}_unified.c")
        if not (os.path.exists(path) and os.path.exists(src)):
            continue
        pe = pefile.PE(path)
        names = [i.name.decode() for e in getattr(pe, "DIRECTORY_ENTRY_IMPORT", []) for i in e.imports if i.name
                 and not e.dll.decode().lower().startswith("msvcrt")]
        text = open(src, errors="replace").read()
        for n in names:
            counts = collections.Counter()
            for m in re.finditer(r"\b%s\(" % re.escape(n), text):
                a = split_args(text, m.end() - 1)
                if a is not None:
                    counts[a] += 1
            if counts:
                out.setdefault(n, counts.most_common(1)[0][0])
            else:
                missing.add(n)
    out.update(EXTRA)
    json.dump(out, sys.stdout, indent=0, sort_keys=True)
    print(f"\n{len(out)} imports with a known argument count; still none: {sorted(missing - set(out))}", file=sys.stderr)


if __name__ == "__main__":
    main()

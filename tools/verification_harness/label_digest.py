#!/usr/bin/env python3
"""
Summarise what a decompiled function actually does, so its name can be judged against it.

For each address (from a JSON list of [addr, name, size] or command-line hex addresses) print:
the size, the string literals it references, the Win32/CRT-looking calls, and the other functions
it calls. Reads the per-binary `<exe>/<exe>_all.c`, which has a "Function: <name> @ <addr>" header
above every function.

    label_digest.py magic sample.json
    label_digest.py magic 0046f5d1 00474c7f
"""
import json
import re
import sys

STR = re.compile(r's_([A-Za-z0-9_]+?)_[0-9a-f]{8}|"([^"\n]{3,60})"')
CALL = re.compile(r"\b([A-Za-z_][A-Za-z0-9_]*)\s*\(")
KEYWORDS = {"if", "while", "for", "switch", "return", "sizeof", "do", "else"}


def bodies(path):
    text = open(path, errors="replace").read()
    heads = list(re.finditer(r"^ \* Function: (\S+) @ ([0-9a-f]{8})", text, re.M))
    out = {}
    for i, m in enumerate(heads):
        end = heads[i + 1].start() if i + 1 < len(heads) else len(text)
        out[m.group(2)] = (m.group(1), text[m.end():end])
    return out


def digest(name, body):
    strings, calls = [], []
    for m in STR.finditer(body):
        s = m.group(1) or m.group(2)
        if s not in strings:
            strings.append(s)
    for m in CALL.finditer(body):
        c = m.group(1)
        if c in KEYWORDS or c == name or c in calls:
            continue
        calls.append(c)
    api = [c for c in calls if re.match(r"^[A-Z][a-z]+[A-Z]?[A-Za-z]*$", c) and "_" not in c]
    other = [c for c in calls if c not in api]
    return strings, api, other


def main():
    exe, arg = sys.argv[1], sys.argv[2:]
    funcs = bodies(f"{exe}/{exe}_all.c")
    if len(arg) == 1 and arg[0].endswith(".json"):
        items = [(f"{a:08x}", n, sz) for a, n, sz in json.load(open(arg[0]))]
    else:
        items = [(a, funcs[a][0], None) for a in arg]
    for addr, name, sz in items:
        if addr not in funcs:
            print(f"### 0x{addr} {name}: NOT FOUND in {exe}_all.c\n")
            continue
        real, body = funcs[addr]
        strings, api, other = digest(real, body)
        lines = body.count("\n")
        print(f"### 0x{addr} {real}  ({sz} bytes, {lines} lines)")
        print("  strings:", strings[:10] or "-")
        print("  win32/crt:", api[:12] or "-")
        print("  calls:", other[:12] or "-")
        print()


if __name__ == "__main__":
    main()

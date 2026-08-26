#!/usr/bin/env python3
import re
import glob

def dedup_file(target_file):
    shandalar_funcs = set()
    for hpath in glob.glob("/Users/ben/decomp/include/shandalar/*.h"):
        with open(hpath, "r") as f:
            c = f.read()
        matches = re.findall(r'\b([A-Za-z_][A-Za-z0-9_]*)\s*\([^)]*\)\s*;', c)
        for m in matches:
            if not m.startswith("typedef") and not m.startswith("define"):
                shandalar_funcs.add(m)

    with open(target_file, "r") as f:
        lines = f.readlines()

    out_lines = []
    removed = 0
    for line in lines:
        matched = False
        for fn in shandalar_funcs:
            if re.search(r'\b' + re.escape(fn) + r'\s*\(', line):
                matched = True
                removed += 1
                break
        if not matched:
            out_lines.append(line)

    with open(target_file, "w") as f:
        f.writelines(out_lines)

    print(f"Removed {removed} duplicate declarations from {target_file}!")

if __name__ == "__main__":
    dedup_file("/Users/ben/decomp/include/magic.h")
    dedup_file("/Users/ben/decomp/magic/magic_unified.h")

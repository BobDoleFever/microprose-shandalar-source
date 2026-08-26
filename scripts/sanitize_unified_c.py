#!/usr/bin/env python3
import re
import glob

def sanitize_unified():
    filepath = "/Users/ben/decomp/magic/magic_unified.c"
    with open(filepath, "r") as f:
        content = f.read()

    # Read all function names from shandalar headers
    func_names = set()
    for h in glob.glob("/Users/ben/decomp/include/shandalar/*.h"):
        with open(h, "r") as hf:
            hc = hf.read()
        matches = re.findall(r'\b([A-Za-z_][A-Za-z0-9_]*)\s*\([^)]*\)\s*;', hc)
        for m in matches:
            if not m.startswith("typedef") and not m.startswith("define"):
                func_names.add(m)

    with open("/Users/ben/decomp/magic/magic_unified.h", "r") as hf:
        hc = hf.read()
    matches = re.findall(r'\b([A-Za-z_][A-Za-z0-9_]*)\s*\([^)]*\)\s*;', hc)
    for m in matches:
        if not m.startswith("typedef") and not m.startswith("define"):
            func_names.add(m)

    print(f"Known function names count: {len(func_names)}")

    lines = content.splitlines(keepends=True)
    out_lines = []
    for line in lines:
        stripped = line.strip()
        # Check if line is "undefined <function_name>;"
        m = re.match(r'^(?:undefined\d?)\s+([A-Za-z_][A-Za-z0-9_]*)\s*;$', stripped)
        if m:
            name = m.group(1)
            if name in func_names:
                # Skip duplicate function symbol exported as variable
                continue
        out_lines.append(line)

    with open(filepath, "w") as f:
        f.writelines(out_lines)

    print("Sanitized function symbols exported as variables!")

if __name__ == "__main__":
    sanitize_unified()

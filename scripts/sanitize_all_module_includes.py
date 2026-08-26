#!/usr/bin/env python3
import os
import re

def sanitize_file(fpath):
    with open(fpath, "r", encoding="utf-8", errors="ignore") as f:
        content = f.read()

    # Replace #include "magic.h" and #include "duel.h"
    new_content = re.sub(r'#include\s+"(?:magic|duel)\.h"', '/* Modular Shandalar Subsystem */', content)
    
    if new_content != content:
        with open(fpath, "w", encoding="utf-8") as f:
            f.write(new_content)
        print(f"Sanitized includes in {fpath}")

def main():
    roots = ["/Users/ben/decomp/src/magic", "/Users/ben/decomp/src/duel"]
    for root in roots:
        for dirpath, _, filenames in os.walk(root):
            for fname in filenames:
                if fname.endswith(".c") or fname.endswith(".h"):
                    sanitize_file(os.path.join(dirpath, fname))

if __name__ == "__main__":
    main()

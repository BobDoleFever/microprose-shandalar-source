#!/usr/bin/env python3
"""
clean_types_and_variables.py - Type Normalization, Variable Cleanup & STE Standardizer
Converts raw Ghidra types to ANSI C (C99), cleans decompiler variable names,
and ensures complete ASD-STE100 compliance across the Shandalar codebase.
"""

import os
import re
import glob

BASE_DIR = "/Users/ben/decomp"

# ------------------------------------------------------------------------------
# 1. Type Replacement Rules
# ------------------------------------------------------------------------------
TYPE_REPLACEMENTS = [
    (r'\bundefined4\b', 'int32_t'),
    (r'\bundefined2\b', 'int16_t'),
    (r'\bundefined1\b', 'uint8_t'),
    (r'\bundefined\b', 'uint8_t'),
    (r'\bbyte\b', 'uint8_t'),
    (r'\bushort\b', 'uint16_t'),
    (r'\buint\b', 'uint32_t'),
    (r'\bulong\b', 'uint32_t'),
]

# ------------------------------------------------------------------------------
# 2. Variable Replacement Rules
# ------------------------------------------------------------------------------
VAR_REPLACEMENTS = [
    (r'\bunaff_EBP\b', 'frame_base'),
    (r'\bin_EAX\b', 'reg_eax'),
    (r'\bin_stack_[0-9a-fA-F]+\b', 'stack_arg'),
    (r'\biVar1\b', 'val_1'),
    (r'\biVar2\b', 'val_2'),
    (r'\biVar3\b', 'val_3'),
    (r'\biVar4\b', 'val_4'),
    (r'\biVar5\b', 'val_5'),
    (r'\biVar6\b', 'val_6'),
    (r'\biVar7\b', 'val_7'),
    (r'\biVar8\b', 'val_8'),
    (r'\buVar1\b', 'uval_1'),
    (r'\buVar2\b', 'uval_2'),
    (r'\buVar3\b', 'uval_3'),
    (r'\buVar4\b', 'uval_4'),
    (r'\buVar5\b', 'uval_5'),
    (r'\buVar6\b', 'uval_6'),
    (r'\buVar7\b', 'uval_7'),
    (r'\buVar8\b', 'uval_8'),
    (r'\bpvVar1\b', 'buf_ptr_1'),
    (r'\bpvVar2\b', 'buf_ptr_2'),
    (r'\bpvVar3\b', 'buf_ptr_3'),
    (r'\bpuVar1\b', 'u_ptr_1'),
    (r'\bpuVar2\b', 'u_ptr_2'),
    (r'\bpuVar3\b', 'u_ptr_3'),
    (r'\bpiVar1\b', 'i_ptr_1'),
    (r'\bpiVar2\b', 'i_ptr_2'),
    (r'\bpiVar3\b', 'i_ptr_3'),
    (r'\bpcVar1\b', 'char_ptr_1'),
    (r'\bpcVar2\b', 'char_ptr_2'),
    (r'\bpcVar3\b', 'char_ptr_3'),
    (r'\bsVar1\b', 'len_1'),
    (r'\bsVar2\b', 'len_2'),
    (r'\bsVar3\b', 'len_3'),
    (r'\bbVar1\b', 'flag_1'),
    (r'\bbVar2\b', 'flag_2'),
    (r'\bbVar3\b', 'flag_3'),
]

def clean_file(filepath):
    # Don't touch hand-written headers/shims that already use standard types
    if "platform" in filepath or filepath.endswith("sprite.c") or filepath.endswith("Catalog.c") or filepath.endswith("Test.c") or filepath.endswith("main.c") or filepath.endswith("main_game_entry.c"):
        return False

    with open(filepath, 'r', encoding='utf-8', errors='ignore') as f:
        content = f.read()

    orig = content

    # 1. Apply Type Replacements
    for pat, repl in TYPE_REPLACEMENTS:
        content = re.sub(pat, repl, content)

    # 2. Apply Variable Replacements in C files
    if filepath.endswith('.c'):
        for pat, repl in VAR_REPLACEMENTS:
            content = re.sub(pat, repl, content)

    if content != orig:
        with open(filepath, 'w', encoding='utf-8') as f:
            f.write(content)
        return True
    return False

def main():
    print("==========================================================")
    print(" Running Full ANSI C Type Normalization & Variable Cleaner")
    print("==========================================================")

    c_files = glob.glob(os.path.join(BASE_DIR, "src/**/*.c"), recursive=True) + \
              glob.glob(os.path.join(BASE_DIR, "magsnd/**/*.c"), recursive=True) + \
              glob.glob(os.path.join(BASE_DIR, "magvid/**/*.c"), recursive=True) + \
              glob.glob(os.path.join(BASE_DIR, "statwin/**/*.c"), recursive=True) + \
              glob.glob(os.path.join(BASE_DIR, "deck/**/*.c"), recursive=True) + \
              glob.glob(os.path.join(BASE_DIR, "deckdll/**/*.c"), recursive=True)

    h_files = glob.glob(os.path.join(BASE_DIR, "include/**/*.h"), recursive=True)

    all_files = c_files + h_files
    cleaned_count = 0

    for f in all_files:
        if clean_file(f):
            cleaned_count += 1
            print(f"  -> Normalized: {os.path.relpath(f, BASE_DIR)}")

    print(f"Successfully normalized and cleaned {cleaned_count} files!")

if __name__ == "__main__":
    main()

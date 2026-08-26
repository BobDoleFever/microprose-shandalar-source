#!/usr/bin/env python3
import re

def trim():
    with open("/Users/ben/decomp/magic/magic_unified.h", "r") as f:
        content = f.read()

    idx = content.find("bool UI_CreateWindow_00401c91(LPCSTR str_1);")
    if idx == -1:
        print("Could not find start of functions!")
        return

    fn_body = content[idx:]

    prologue = """#ifndef MAGIC_UNIFIED_H
#define MAGIC_UNIFIED_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include "windows_types.h"
#include "magic_types.h"
#include "shandalar/shandalar.h"
#include "shandalar/win32_compat.h"
#include "shandalar/display_shim.h"

typedef char* string;

"""
    crt_names = {"strlen", "sprintf", "vsprintf", "strcpy", "strncpy", "strcat", "strncat",
                 "strcmp", "strncmp", "strchr", "strrchr", "strstr", "strtok", "memcpy",
                 "memmove", "memset", "memcmp", "malloc", "calloc", "realloc", "free",
                 "printf", "fprintf", "fscanf", "sscanf", "fopen", "fclose", "fread",
                 "fwrite", "fseek", "ftell", "rewind", "fgetc", "fputc", "fgets", "fputs",
                 "rand", "srand", "abs", "labs", "exit", "abort", "atexit", "qsort",
                 "bsearch", "atoi", "atol", "atof", "time", "clock", "sin", "cos", "tan",
                 "sqrt", "pow", "log", "exp", "floor", "ceil", "_fileno", "_filelength"}

    clean_lines = []
    for line in fn_body.splitlines(keepends=True):
        matched = False
        for name in crt_names:
            if re.search(r'\b(?:__cdecl\s+)?' + re.escape(name) + r'\s*\(', line):
                matched = True
                break
        if not matched:
            clean_lines.append(line)

    final_content = prologue + "".join(clean_lines)
    if not final_content.strip().endswith("#endif"):
        final_content += "\n#endif /* MAGIC_UNIFIED_H */\n"

    with open("/Users/ben/decomp/magic/magic_unified.h", "w") as f:
        f.write(final_content)

    print("Trimmed magic_unified.h to exact function prototypes!")

if __name__ == "__main__":
    trim()

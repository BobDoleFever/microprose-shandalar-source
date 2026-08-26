#!/usr/bin/env python3
import re

def strip_crt():
    with open("/Users/ben/decomp/include/magic.h", "r") as f:
        lines = f.readlines()

    crt_names = {
        "strlen", "sprintf", "vsprintf", "strcpy", "strncpy", "strcat", "strncat",
        "strcmp", "strncmp", "strchr", "strrchr", "strstr", "strtok", "memcpy",
        "memmove", "memset", "memcmp", "malloc", "calloc", "realloc", "free",
        "printf", "fprintf", "fscanf", "sscanf", "fopen", "fclose", "fread",
        "fwrite", "fseek", "ftell", "rewind", "fgetc", "fputc", "fgets", "fputs",
        "rand", "srand", "abs", "labs", "exit", "abort", "atexit", "qsort",
        "bsearch", "atoi", "atol", "atof", "time", "clock", "sin", "cos", "tan",
        "sqrt", "pow", "log", "exp", "floor", "ceil", "_fileno", "_filelength"
    }

    out = []
    removed = 0
    for line in lines:
        matched = False
        for name in crt_names:
            if re.search(r'\b(?:__cdecl\s+)?' + re.escape(name) + r'\s*\(', line):
                matched = True
                removed += 1
                break
        if not matched:
            out.append(line)

    with open("/Users/ben/decomp/include/magic.h", "w") as f:
        f.writelines(out)
    print(f"Removed {removed} standard CRT re-declarations from magic.h!")

if __name__ == "__main__":
    strip_crt()

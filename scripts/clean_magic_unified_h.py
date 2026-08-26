#!/usr/bin/env python3
import re

def clean():
    with open("/Users/ben/decomp/magic/magic_unified.h", "r") as f:
        content = f.read()

    # Remove conflicting Ghidra primitive typedefs that are in windows_types.h
    types_to_remove = [
        r'typedef\s+pointer32\s+ImageBaseOffset32;',
        r'typedef\s+unsigned\s+long\s+ulong;',
        r'typedef\s+ulong\s+ULONG_PTR;',
        r'typedef\s+struct\s+_RTL_CRITICAL_SECTION\s*\*PRTL_CRITICAL_SECTION;',
        r'typedef\s+struct\s+_RTL_CRITICAL_SECTION_DEBUG\s*\*PRTL_CRITICAL_SECTION_DEBUG;',
        r'typedef\s+void\*\s+PEXCEPTION_RECORD;',
        r'typedef\s+void\*\s+PCONTEXT;',
        r'typedef\s+unsigned\s+char\s+undefined;',
        r'typedef\s+unsigned\s+char\s+byte;',
        r'typedef\s+unsigned\s+int\s+dword;',
        r'typedef\s+long\s+long\s+longlong;',
        r'typedef\s+unsigned\s+char\s+uchar;',
        r'typedef\s+unsigned\s+int\s+uint;',
        r'typedef\s+unsigned\s+char\s+undefined1;',
        r'typedef\s+unsigned\s+short\s+undefined2;',
        r'typedef\s+unsigned\s+int\s+undefined4;',
        r'typedef\s+unsigned\s+long\s+long\s+undefined8;',
        r'typedef\s+unsigned\s+short\s+ushort;',
        r'typedef\s+unsigned\s+short\s+word;',
        r'typedef\s+void\*\s+pointer32;',
        r'typedef\s+void\*\s+pointer;',
        r'typedef\s+void\*\s+code;',
        r'typedef\s+void\*\s+BADSPACEBASE;'
    ]

    for pat in types_to_remove:
        content = re.sub(pat, '/* primitive typedef */', content)

    with open("/Users/ben/decomp/magic/magic_unified.h", "w") as f:
        f.write(content)
    print("Cleaned magic_unified.h primitives!")

if __name__ == "__main__":
    clean()

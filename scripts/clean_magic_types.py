#!/usr/bin/env python3
import re

def clean():
    with open("/Users/ben/decomp/include/magic_types.h", "r") as f:
        content = f.read()

    prologue = """#ifndef MAGIC_TYPES_H
#define MAGIC_TYPES_H

#include "windows_types.h"

typedef uint32_t COLORREF;
typedef void* LPOFNHOOKPROC;
typedef struct _union_655 { char pad[16]; } _union_655;
typedef struct _union_658 { char pad[16]; } _union_658;
typedef struct _union_518 { char pad[16]; } _union_518;
typedef struct IMAGE_RESOURCE_DIRECTORY_ENTRY_NameUnion { uint32_t val; } IMAGE_RESOURCE_DIRECTORY_ENTRY_NameUnion;
typedef struct IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryUnion { uint32_t val; } IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryUnion;
typedef struct Misc { uint32_t val; } Misc;
typedef struct SectionFlags { uint32_t val; } SectionFlags;
typedef struct tagRGBQUAD { uint8_t b, g, r, a; } RGBQUAD;
typedef struct _LIST_ENTRY _LIST_ENTRY;
typedef struct _LIST_ENTRY LIST_ENTRY;
typedef struct _EXCEPTION_RECORD _EXCEPTION_RECORD;
typedef struct _RTL_CRITICAL_SECTION _RTL_CRITICAL_SECTION;
typedef struct IMAGE_FILE_HEADER IMAGE_FILE_HEADER;
typedef struct tagBITMAPINFOHEADER BITMAPINFOHEADER;
typedef struct tagPALETTEENTRY PALETTEENTRY;
"""
    # Remove previous prologue
    content = re.sub(r'#ifndef MAGIC_TYPES_H[\s\S]*?typedef struct tagPALETTEENTRY PALETTEENTRY;\n', '', content)
    content = re.sub(r'struct tagLOGFONTA \{[^}]+\};', '/* tagLOGFONTA */', content)
    content = re.sub(r'struct _FLOATING_SAVE_AREA \{[^}]+\};', '/* _FLOATING_SAVE_AREA */', content)
    content = re.sub(r'struct tagMSG \{[^}]+\};', '/* tagMSG */', content)
    content = re.sub(r'struct tagPAINTSTRUCT \{[^}]+\};', '/* tagPAINTSTRUCT */', content)
    content = re.sub(r'struct tagRECT \{[^}]+\};', '/* tagRECT */', content)
    content = re.sub(r'struct tagPOINT \{[^}]+\};', '/* tagPOINT */', content)
    content = re.sub(r'struct tagPALETTEENTRY \{[^}]+\};', '/* tagPALETTEENTRY */', content)

    final_content = prologue + "\n" + content.strip() + "\n#endif\n"
    with open("/Users/ben/decomp/include/magic_types.h", "w") as f:
        f.write(final_content)
    print("Fixed magic_types.h forward declarations!")

if __name__ == "__main__":
    clean()

/*
 * statwin_types.h - Data Types and Structure Definitions for STATWIN.DLL
 */
#ifndef STATWIN_TYPES_H
#define STATWIN_TYPES_H

#include "windows_types.h"

/* Forward Declarations */
typedef struct _iobuf _iobuf;
typedef struct _OVERLAPPED _OVERLAPPED;
typedef struct _SECURITY_ATTRIBUTES _SECURITY_ATTRIBUTES;
typedef struct _struct_519 _struct_519;
typedef struct HBRUSH__ HBRUSH__;
typedef struct HDC__ HDC__;
typedef struct HICON__ HICON__;
typedef struct HINSTANCE__ HINSTANCE__;
typedef struct HMENU__ HMENU__;
typedef struct HPALETTE__ HPALETTE__;
typedef struct HWND__ HWND__;
typedef struct IMAGE_BASE_RELOCATION IMAGE_BASE_RELOCATION;
typedef struct IMAGE_DATA_DIRECTORY IMAGE_DATA_DIRECTORY;
typedef struct IMAGE_DEBUG_DIRECTORY IMAGE_DEBUG_DIRECTORY;
typedef struct IMAGE_DIRECTORY_ENTRY_EXPORT IMAGE_DIRECTORY_ENTRY_EXPORT;
typedef struct IMAGE_DOS_HEADER IMAGE_DOS_HEADER;
typedef struct IMAGE_FILE_HEADER IMAGE_FILE_HEADER;
typedef struct IMAGE_NT_HEADERS32 IMAGE_NT_HEADERS32;
typedef struct IMAGE_OPTIONAL_HEADER32 IMAGE_OPTIONAL_HEADER32;
typedef struct IMAGE_RESOURCE_DATA_ENTRY IMAGE_RESOURCE_DATA_ENTRY;
typedef struct IMAGE_RESOURCE_DIRECTORY IMAGE_RESOURCE_DIRECTORY;
typedef struct IMAGE_RESOURCE_DIRECTORY_ENTRY IMAGE_RESOURCE_DIRECTORY_ENTRY;
typedef struct IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryStruct IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryStruct;
typedef struct IMAGE_RESOURCE_DIRECTORY_ENTRY_NameStruct IMAGE_RESOURCE_DIRECTORY_ENTRY_NameStruct;
typedef struct IMAGE_SECTION_HEADER IMAGE_SECTION_HEADER;
typedef struct tagMSG tagMSG;
typedef struct tagPALETTEENTRY tagPALETTEENTRY;
typedef struct tagPOINT tagPOINT;
typedef struct tagRECT tagRECT;
typedef struct tagWNDCLASSA tagWNDCLASSA;

/* Struct: _iobuf (Size: 32 bytes) */
struct _iobuf {
    char * _ptr; /* offset: 0x0 */
    int _cnt; /* offset: 0x4 */
    char * _base; /* offset: 0x8 */
    int _flag; /* offset: 0xc */
    int _file; /* offset: 0x10 */
    int _charbuf; /* offset: 0x14 */
    int _bufsiz; /* offset: 0x18 */
    char * _tmpfname; /* offset: 0x1c */
};

/* Struct: _OVERLAPPED (Size: 20 bytes) */
struct _OVERLAPPED {
    ULONG_PTR Internal; /* offset: 0x0 */
    ULONG_PTR InternalHigh; /* offset: 0x4 */
    _union_518 u; /* offset: 0x8 */
    HANDLE hEvent; /* offset: 0x10 */
};

/* Struct: _SECURITY_ATTRIBUTES (Size: 12 bytes) */
struct _SECURITY_ATTRIBUTES {
    DWORD nLength; /* offset: 0x0 */
    LPVOID lpSecurityDescriptor; /* offset: 0x4 */
    BOOL bInheritHandle; /* offset: 0x8 */
};

/* Struct: _struct_519 (Size: 8 bytes) */
struct _struct_519 {
    DWORD Offset; /* offset: 0x0 */
    DWORD OffsetHigh; /* offset: 0x4 */
};

/* Struct: HBRUSH__ (Size: 4 bytes) */
struct HBRUSH__ {
    int unused; /* offset: 0x0 */
};

/* Struct: HDC__ (Size: 4 bytes) */
struct HDC__ {
    int unused; /* offset: 0x0 */
};

/* Struct: HICON__ (Size: 4 bytes) */
struct HICON__ {
    int unused; /* offset: 0x0 */
};

/* Struct: HINSTANCE__ (Size: 4 bytes) */
struct HINSTANCE__ {
    int unused; /* offset: 0x0 */
};

/* Struct: HMENU__ (Size: 4 bytes) */
struct HMENU__ {
    int unused; /* offset: 0x0 */
};

/* Struct: HPALETTE__ (Size: 4 bytes) */
struct HPALETTE__ {
    int unused; /* offset: 0x0 */
};

/* Struct: HWND__ (Size: 4 bytes) */
struct HWND__ {
    int unused; /* offset: 0x0 */
};

/* Struct: IMAGE_BASE_RELOCATION (Size: 8 bytes) */
struct IMAGE_BASE_RELOCATION {
    dword VirtualAddress; /* offset: 0x0 */
    dword SizeOfBlock; /* offset: 0x4 */
};

/* Struct: IMAGE_DATA_DIRECTORY (Size: 8 bytes) */
struct IMAGE_DATA_DIRECTORY {
    ImageBaseOffset32 VirtualAddress; /* offset: 0x0 */
    dword Size; /* offset: 0x4 */
};

/* Struct: IMAGE_DEBUG_DIRECTORY (Size: 28 bytes) */
struct IMAGE_DEBUG_DIRECTORY {
    dword Characteristics; /* offset: 0x0 */
    dword TimeDateStamp; /* offset: 0x4 */
    word MajorVersion; /* offset: 0x8 */
    word MinorVersion; /* offset: 0xa */
    dword Type; /* offset: 0xc */
    dword SizeOfData; /* offset: 0x10 */
    dword AddressOfRawData; /* offset: 0x14 */
    dword PointerToRawData; /* offset: 0x18 */
};

/* Struct: IMAGE_DIRECTORY_ENTRY_EXPORT (Size: 40 bytes) */
struct IMAGE_DIRECTORY_ENTRY_EXPORT {
    dword Characteristics; /* offset: 0x0 */
    dword TimeDateStamp; /* offset: 0x4 */
    word MajorVersion; /* offset: 0x8 */
    word MinorVersion; /* offset: 0xa */
    ImageBaseOffset32 Name; /* offset: 0xc */
    dword Base; /* offset: 0x10 */
    dword NumberOfFunctions; /* offset: 0x14 */
    dword NumberOfNames; /* offset: 0x18 */
    ImageBaseOffset32 AddressOfFunctions; /* offset: 0x1c */
    ImageBaseOffset32 AddressOfNames; /* offset: 0x20 */
    ImageBaseOffset32 AddressOfNameOrdinals; /* offset: 0x24 */
};

/* Struct: IMAGE_DOS_HEADER (Size: 128 bytes) */
struct IMAGE_DOS_HEADER {
    char e_magic[2]; /* offset: 0x0 */
    word e_cblp; /* offset: 0x2 */
    word e_cp; /* offset: 0x4 */
    word e_crlc; /* offset: 0x6 */
    word e_cparhdr; /* offset: 0x8 */
    word e_minalloc; /* offset: 0xa */
    word e_maxalloc; /* offset: 0xc */
    word e_ss; /* offset: 0xe */
    word e_sp; /* offset: 0x10 */
    word e_csum; /* offset: 0x12 */
    word e_ip; /* offset: 0x14 */
    word e_cs; /* offset: 0x16 */
    word e_lfarlc; /* offset: 0x18 */
    word e_ovno; /* offset: 0x1a */
    word e_res_4_[4]; /* offset: 0x1c */
    word e_oemid; /* offset: 0x24 */
    word e_oeminfo; /* offset: 0x26 */
    word e_res2_10_[10]; /* offset: 0x28 */
    dword e_lfanew; /* offset: 0x3c */
    uint8_t e_program[64]; /* offset: 0x40 */
};

/* Struct: IMAGE_FILE_HEADER (Size: 20 bytes) */
struct IMAGE_FILE_HEADER {
    word Machine; /* offset: 0x0 */
    word NumberOfSections; /* offset: 0x2 */
    dword TimeDateStamp; /* offset: 0x4 */
    dword PointerToSymbolTable; /* offset: 0x8 */
    dword NumberOfSymbols; /* offset: 0xc */
    word SizeOfOptionalHeader; /* offset: 0x10 */
    word Characteristics; /* offset: 0x12 */
};

/* Struct: IMAGE_NT_HEADERS32 (Size: 248 bytes) */
struct IMAGE_NT_HEADERS32 {
    char Signature[4]; /* offset: 0x0 */
    IMAGE_FILE_HEADER FileHeader; /* offset: 0x4 */
    IMAGE_OPTIONAL_HEADER32 OptionalHeader; /* offset: 0x18 */
};

/* Struct: IMAGE_OPTIONAL_HEADER32 (Size: 224 bytes) */
struct IMAGE_OPTIONAL_HEADER32 {
    word Magic; /* offset: 0x0 */
    uint8_t MajorLinkerVersion; /* offset: 0x2 */
    uint8_t MinorLinkerVersion; /* offset: 0x3 */
    dword SizeOfCode; /* offset: 0x4 */
    dword SizeOfInitializedData; /* offset: 0x8 */
    dword SizeOfUninitializedData; /* offset: 0xc */
    ImageBaseOffset32 AddressOfEntryPoint; /* offset: 0x10 */
    ImageBaseOffset32 BaseOfCode; /* offset: 0x14 */
    ImageBaseOffset32 BaseOfData; /* offset: 0x18 */
    pointer32 ImageBase; /* offset: 0x1c */
    dword SectionAlignment; /* offset: 0x20 */
    dword FileAlignment; /* offset: 0x24 */
    word MajorOperatingSystemVersion; /* offset: 0x28 */
    word MinorOperatingSystemVersion; /* offset: 0x2a */
    word MajorImageVersion; /* offset: 0x2c */
    word MinorImageVersion; /* offset: 0x2e */
    word MajorSubsystemVersion; /* offset: 0x30 */
    word MinorSubsystemVersion; /* offset: 0x32 */
    dword Win32VersionValue; /* offset: 0x34 */
    dword SizeOfImage; /* offset: 0x38 */
    dword SizeOfHeaders; /* offset: 0x3c */
    dword CheckSum; /* offset: 0x40 */
    word Subsystem; /* offset: 0x44 */
    word DllCharacteristics; /* offset: 0x46 */
    dword SizeOfStackReserve; /* offset: 0x48 */
    dword SizeOfStackCommit; /* offset: 0x4c */
    dword SizeOfHeapReserve; /* offset: 0x50 */
    dword SizeOfHeapCommit; /* offset: 0x54 */
    dword LoaderFlags; /* offset: 0x58 */
    dword NumberOfRvaAndSizes; /* offset: 0x5c */
    IMAGE_DATA_DIRECTORY DataDirectory[16]; /* offset: 0x60 */
};

/* Struct: IMAGE_RESOURCE_DATA_ENTRY (Size: 16 bytes) */
struct IMAGE_RESOURCE_DATA_ENTRY {
    dword OffsetToData; /* offset: 0x0 */
    dword Size; /* offset: 0x4 */
    dword CodePage; /* offset: 0x8 */
    dword Reserved; /* offset: 0xc */
};

/* Struct: IMAGE_RESOURCE_DIRECTORY (Size: 16 bytes) */
struct IMAGE_RESOURCE_DIRECTORY {
    dword Characteristics; /* offset: 0x0 */
    dword TimeDateStamp; /* offset: 0x4 */
    word MajorVersion; /* offset: 0x8 */
    word MinorVersion; /* offset: 0xa */
    word NumberOfNamedEntries; /* offset: 0xc */
    word NumberOfIdEntries; /* offset: 0xe */
};

/* Struct: IMAGE_RESOURCE_DIRECTORY_ENTRY (Size: 8 bytes) */
struct IMAGE_RESOURCE_DIRECTORY_ENTRY {
    IMAGE_RESOURCE_DIRECTORY_ENTRY_NameUnion NameUnion; /* offset: 0x0 */
    IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryUnion DirectoryUnion; /* offset: 0x4 */
};

/* Struct: IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryStruct (Size: 4 bytes) */
struct IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryStruct {
    dword:31 OffsetToDirectory; /* offset: 0x0 */
    dword:1 DataIsDirectory; /* offset: 0x3 */
};

/* Struct: IMAGE_RESOURCE_DIRECTORY_ENTRY_NameStruct (Size: 4 bytes) */
struct IMAGE_RESOURCE_DIRECTORY_ENTRY_NameStruct {
    dword:31 NameOffset; /* offset: 0x0 */
    dword:1 NameIsString; /* offset: 0x3 */
};

/* Struct: IMAGE_SECTION_HEADER (Size: 40 bytes) */
struct IMAGE_SECTION_HEADER {
    char Name[8]; /* offset: 0x0 */
    Misc Misc; /* offset: 0x8 */
    ImageBaseOffset32 VirtualAddress; /* offset: 0xc */
    dword SizeOfRawData; /* offset: 0x10 */
    dword PointerToRawData; /* offset: 0x14 */
    dword PointerToRelocations; /* offset: 0x18 */
    dword PointerToLinenumbers; /* offset: 0x1c */
    word NumberOfRelocations; /* offset: 0x20 */
    word NumberOfLinenumbers; /* offset: 0x22 */
    SectionFlags Characteristics; /* offset: 0x24 */
};

/* Struct: tagMSG (Size: 28 bytes) */
struct tagMSG {
    HWND hwnd; /* offset: 0x0 */
    UINT message; /* offset: 0x4 */
    WPARAM wParam; /* offset: 0x8 */
    LPARAM lParam; /* offset: 0xc */
    DWORD time; /* offset: 0x10 */
    POINT pt; /* offset: 0x14 */
};

/* Struct: tagPALETTEENTRY (Size: 4 bytes) */
struct tagPALETTEENTRY {
    BYTE peRed; /* offset: 0x0 */
    BYTE peGreen; /* offset: 0x1 */
    BYTE peBlue; /* offset: 0x2 */
    BYTE peFlags; /* offset: 0x3 */
};

/* Struct: tagPOINT (Size: 8 bytes) */
struct tagPOINT {
    LONG x; /* offset: 0x0 */
    LONG y; /* offset: 0x4 */
};

/* Struct: tagRECT (Size: 16 bytes) */
struct tagRECT {
    LONG left; /* offset: 0x0 */
    LONG top; /* offset: 0x4 */
    LONG right; /* offset: 0x8 */
    LONG bottom; /* offset: 0xc */
};

/* Struct: tagWNDCLASSA (Size: 40 bytes) */
struct tagWNDCLASSA {
    UINT style; /* offset: 0x0 */
    WNDPROC lpfnWndProc; /* offset: 0x4 */
    int cbClsExtra; /* offset: 0x8 */
    int cbWndExtra; /* offset: 0xc */
    HINSTANCE hInstance; /* offset: 0x10 */
    HICON hIcon; /* offset: 0x14 */
    HCURSOR hCursor; /* offset: 0x18 */
    HBRUSH hbrBackground; /* offset: 0x1c */
    LPCSTR lpszMenuName; /* offset: 0x20 */
    LPCSTR lpszClassName; /* offset: 0x24 */
};

#endif /* STATWIN_TYPES_H */

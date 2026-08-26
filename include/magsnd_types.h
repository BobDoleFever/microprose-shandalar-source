/*
 * magsnd_types.h - Data Types and Structure Definitions for MAGSND.DLL
 */
#ifndef MAGSND_TYPES_H
#define MAGSND_TYPES_H

#include "windows_types.h"

/* Forward Declarations */
typedef struct _iobuf _iobuf;
typedef struct _LIST_ENTRY _LIST_ENTRY;
typedef struct _MMCKINFO _MMCKINFO;
typedef struct _MMIOINFO _MMIOINFO;
typedef struct _RTL_CRITICAL_SECTION _RTL_CRITICAL_SECTION;
typedef struct _RTL_CRITICAL_SECTION_DEBUG _RTL_CRITICAL_SECTION_DEBUG;
typedef struct HINSTANCE__ HINSTANCE__;
typedef struct HMMIO__ HMMIO__;
typedef struct HTASK__ HTASK__;
typedef struct HWND__ HWND__;
typedef struct IMAGE_BASE_RELOCATION IMAGE_BASE_RELOCATION;
typedef struct IMAGE_DATA_DIRECTORY IMAGE_DATA_DIRECTORY;
typedef struct IMAGE_DEBUG_DIRECTORY IMAGE_DEBUG_DIRECTORY;
typedef struct IMAGE_DIRECTORY_ENTRY_EXPORT IMAGE_DIRECTORY_ENTRY_EXPORT;
typedef struct IMAGE_DOS_HEADER IMAGE_DOS_HEADER;
typedef struct IMAGE_FILE_HEADER IMAGE_FILE_HEADER;
typedef struct IMAGE_NT_HEADERS32 IMAGE_NT_HEADERS32;
typedef struct IMAGE_OPTIONAL_HEADER32 IMAGE_OPTIONAL_HEADER32;
typedef struct IMAGE_SECTION_HEADER IMAGE_SECTION_HEADER;
typedef struct timecaps_tag timecaps_tag;

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

/* Struct: _LIST_ENTRY (Size: 8 bytes) */
struct _LIST_ENTRY {
    _LIST_ENTRY * Flink; /* offset: 0x0 */
    _LIST_ENTRY * Blink; /* offset: 0x4 */
};

/* Struct: _MMCKINFO (Size: 20 bytes) */
struct _MMCKINFO {
    FOURCC ckid; /* offset: 0x0 */
    DWORD cksize; /* offset: 0x4 */
    FOURCC fccType; /* offset: 0x8 */
    DWORD dwDataOffset; /* offset: 0xc */
    DWORD dwFlags; /* offset: 0x10 */
};

/* Struct: _MMIOINFO (Size: 72 bytes) */
struct _MMIOINFO {
    DWORD dwFlags; /* offset: 0x0 */
    FOURCC fccIOProc; /* offset: 0x4 */
    LPMMIOPROC pIOProc; /* offset: 0x8 */
    UINT wErrorRet; /* offset: 0xc */
    HTASK htask; /* offset: 0x10 */
    LONG cchBuffer; /* offset: 0x14 */
    HPSTR pchBuffer; /* offset: 0x18 */
    HPSTR pchNext; /* offset: 0x1c */
    HPSTR pchEndRead; /* offset: 0x20 */
    HPSTR pchEndWrite; /* offset: 0x24 */
    LONG lBufOffset; /* offset: 0x28 */
    LONG lDiskOffset; /* offset: 0x2c */
    DWORD adwInfo[3]; /* offset: 0x30 */
    DWORD dwReserved1; /* offset: 0x3c */
    DWORD dwReserved2; /* offset: 0x40 */
    HMMIO hmmio; /* offset: 0x44 */
};

/* Struct: _RTL_CRITICAL_SECTION (Size: 24 bytes) */
struct _RTL_CRITICAL_SECTION {
    PRTL_CRITICAL_SECTION_DEBUG DebugInfo; /* offset: 0x0 */
    LONG LockCount; /* offset: 0x4 */
    LONG RecursionCount; /* offset: 0x8 */
    HANDLE OwningThread; /* offset: 0xc */
    HANDLE LockSemaphore; /* offset: 0x10 */
    ULONG_PTR SpinCount; /* offset: 0x14 */
};

/* Struct: _RTL_CRITICAL_SECTION_DEBUG (Size: 32 bytes) */
struct _RTL_CRITICAL_SECTION_DEBUG {
    WORD Type; /* offset: 0x0 */
    WORD CreatorBackTraceIndex; /* offset: 0x2 */
    _RTL_CRITICAL_SECTION * CriticalSection; /* offset: 0x4 */
    LIST_ENTRY ProcessLocksList; /* offset: 0x8 */
    DWORD EntryCount; /* offset: 0x10 */
    DWORD ContentionCount; /* offset: 0x14 */
    DWORD Flags; /* offset: 0x18 */
    WORD CreatorBackTraceIndexHigh; /* offset: 0x1c */
    WORD SpareWORD; /* offset: 0x1e */
};

/* Struct: HINSTANCE__ (Size: 4 bytes) */
struct HINSTANCE__ {
    int unused; /* offset: 0x0 */
};

/* Struct: HMMIO__ (Size: 4 bytes) */
struct HMMIO__ {
    int unused; /* offset: 0x0 */
};

/* Struct: HTASK__ (Size: 4 bytes) */
struct HTASK__ {
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

/* Struct: timecaps_tag (Size: 8 bytes) */
struct timecaps_tag {
    UINT wPeriodMin; /* offset: 0x0 */
    UINT wPeriodMax; /* offset: 0x4 */
};

#endif /* MAGSND_TYPES_H */

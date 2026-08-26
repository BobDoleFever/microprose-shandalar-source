/*
 * magvid_types.h - Data Types and Structure Definitions for MAGVID.DLL
 */
#ifndef MAGVID_TYPES_H
#define MAGVID_TYPES_H

#include "windows_types.h"

/* Forward Declarations */
typedef struct _LIST_ENTRY _LIST_ENTRY;
typedef struct _MMCKINFO _MMCKINFO;
typedef struct _MMIOINFO _MMIOINFO;
typedef struct _OVERLAPPED _OVERLAPPED;
typedef struct _RTL_CRITICAL_SECTION _RTL_CRITICAL_SECTION;
typedef struct _RTL_CRITICAL_SECTION_DEBUG _RTL_CRITICAL_SECTION_DEBUG;
typedef struct _SECURITY_ATTRIBUTES _SECURITY_ATTRIBUTES;
typedef struct _struct_519 _struct_519;
typedef struct HBRUSH__ HBRUSH__;
typedef struct HDC__ HDC__;
typedef struct HICON__ HICON__;
typedef struct HINSTANCE__ HINSTANCE__;
typedef struct HMENU__ HMENU__;
typedef struct HMMIO__ HMMIO__;
typedef struct HPALETTE__ HPALETTE__;
typedef struct HTASK__ HTASK__;
typedef struct HWAVEOUT__ HWAVEOUT__;
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
typedef struct tagOFNA tagOFNA;
typedef struct tagPAINTSTRUCT tagPAINTSTRUCT;
typedef struct tagPALETTEENTRY tagPALETTEENTRY;
typedef struct tagPOINT tagPOINT;
typedef struct tagRECT tagRECT;
typedef struct tagWNDCLASSA tagWNDCLASSA;
typedef struct timecaps_tag timecaps_tag;
typedef struct wavehdr_tag wavehdr_tag;

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

/* Struct: _OVERLAPPED (Size: 20 bytes) */
struct _OVERLAPPED {
    ULONG_PTR Internal; /* offset: 0x0 */
    ULONG_PTR InternalHigh; /* offset: 0x4 */
    _union_518 u; /* offset: 0x8 */
    HANDLE hEvent; /* offset: 0x10 */
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

/* Struct: HMMIO__ (Size: 4 bytes) */
struct HMMIO__ {
    int unused; /* offset: 0x0 */
};

/* Struct: HPALETTE__ (Size: 4 bytes) */
struct HPALETTE__ {
    int unused; /* offset: 0x0 */
};

/* Struct: HTASK__ (Size: 4 bytes) */
struct HTASK__ {
    int unused; /* offset: 0x0 */
};

/* Struct: HWAVEOUT__ (Size: 4 bytes) */
struct HWAVEOUT__ {
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

/* Struct: tagOFNA (Size: 88 bytes) */
struct tagOFNA {
    DWORD lStructSize; /* offset: 0x0 */
    HWND hwndOwner; /* offset: 0x4 */
    HINSTANCE hInstance; /* offset: 0x8 */
    LPCSTR lpstrFilter; /* offset: 0xc */
    LPSTR lpstrCustomFilter; /* offset: 0x10 */
    DWORD nMaxCustFilter; /* offset: 0x14 */
    DWORD nFilterIndex; /* offset: 0x18 */
    LPSTR lpstrFile; /* offset: 0x1c */
    DWORD nMaxFile; /* offset: 0x20 */
    LPSTR lpstrFileTitle; /* offset: 0x24 */
    DWORD nMaxFileTitle; /* offset: 0x28 */
    LPCSTR lpstrInitialDir; /* offset: 0x2c */
    LPCSTR lpstrTitle; /* offset: 0x30 */
    DWORD Flags; /* offset: 0x34 */
    WORD nFileOffset; /* offset: 0x38 */
    WORD nFileExtension; /* offset: 0x3a */
    LPCSTR lpstrDefExt; /* offset: 0x3c */
    LPARAM lCustData; /* offset: 0x40 */
    LPOFNHOOKPROC lpfnHook; /* offset: 0x44 */
    LPCSTR lpTemplateName; /* offset: 0x48 */
    void * pvReserved; /* offset: 0x4c */
    DWORD dwReserved; /* offset: 0x50 */
    DWORD FlagsEx; /* offset: 0x54 */
};

/* Struct: tagPAINTSTRUCT (Size: 64 bytes) */
struct tagPAINTSTRUCT {
    HDC hdc; /* offset: 0x0 */
    BOOL fErase; /* offset: 0x4 */
    RECT rcPaint; /* offset: 0x8 */
    BOOL fRestore; /* offset: 0x18 */
    BOOL fIncUpdate; /* offset: 0x1c */
    BYTE rgbReserved[32]; /* offset: 0x20 */
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

/* Struct: timecaps_tag (Size: 8 bytes) */
struct timecaps_tag {
    UINT wPeriodMin; /* offset: 0x0 */
    UINT wPeriodMax; /* offset: 0x4 */
};

/* Struct: wavehdr_tag (Size: 32 bytes) */
struct wavehdr_tag {
    LPSTR lpData; /* offset: 0x0 */
    DWORD dwBufferLength; /* offset: 0x4 */
    DWORD dwBytesRecorded; /* offset: 0x8 */
    DWORD_PTR dwUser; /* offset: 0xc */
    DWORD dwFlags; /* offset: 0x10 */
    DWORD dwLoops; /* offset: 0x14 */
    wavehdr_tag * lpNext; /* offset: 0x18 */
    DWORD_PTR reserved; /* offset: 0x1c */
};

#endif /* MAGVID_TYPES_H */

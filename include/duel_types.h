/*
 * duel_types.h - Data Types and Structure Definitions for DUEL.EXE
 */
#ifndef DUEL_TYPES_H
#define DUEL_TYPES_H

#include "windows_types.h"

/* Forward Declarations */
typedef struct __lc_time_data __lc_time_data;
typedef struct _ABC _ABC;
typedef struct _AppBarData _AppBarData;
typedef struct _CONTEXT _CONTEXT;
typedef struct _cpinfo _cpinfo;
typedef struct _CRT_DOUBLE _CRT_DOUBLE;
typedef struct _CRT_FLOAT _CRT_FLOAT;
typedef struct _devicemodeA _devicemodeA;
typedef struct _EXCEPTION_POINTERS _EXCEPTION_POINTERS;
typedef struct _EXCEPTION_RECORD _EXCEPTION_RECORD;
typedef struct _FLOATING_SAVE_AREA _FLOATING_SAVE_AREA;
typedef struct _iobuf _iobuf;
typedef struct _LDBL12 _LDBL12;
typedef struct _LDOUBLE _LDOUBLE;
typedef struct _LIST_ENTRY _LIST_ENTRY;
typedef struct _OVERLAPPED _OVERLAPPED;
typedef struct _POINTL _POINTL;
typedef struct _RTL_CRITICAL_SECTION _RTL_CRITICAL_SECTION;
typedef struct _RTL_CRITICAL_SECTION_DEBUG _RTL_CRITICAL_SECTION_DEBUG;
typedef struct _SECURITY_ATTRIBUTES _SECURITY_ATTRIBUTES;
typedef struct _STARTUPINFOA _STARTUPINFOA;
typedef struct _strflt _strflt;
typedef struct _struct_519 _struct_519;
typedef struct _struct_656 _struct_656;
typedef struct _struct_657 _struct_657;
typedef struct _SYSTEMTIME _SYSTEMTIME;
typedef struct _TIME_ZONE_INFORMATION _TIME_ZONE_INFORMATION;
typedef struct HACCEL__ HACCEL__;
typedef struct HBITMAP__ HBITMAP__;
typedef struct HBRUSH__ HBRUSH__;
typedef struct HDC__ HDC__;
typedef struct HFONT__ HFONT__;
typedef struct HICON__ HICON__;
typedef struct HINSTANCE__ HINSTANCE__;
typedef struct HKEY__ HKEY__;
typedef struct HMENU__ HMENU__;
typedef struct HPALETTE__ HPALETTE__;
typedef struct HPEN__ HPEN__;
typedef struct HRGN__ HRGN__;
typedef struct HRSRC__ HRSRC__;
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
typedef struct lconv lconv;
typedef struct localeinfo_struct localeinfo_struct;
typedef struct localerefcount localerefcount;
typedef struct StringFileInfo StringFileInfo;
typedef struct StringInfo StringInfo;
typedef struct StringTable StringTable;
typedef struct tagBITMAPINFO tagBITMAPINFO;
typedef struct tagBITMAPINFOHEADER tagBITMAPINFOHEADER;
typedef struct tagLOGFONTA tagLOGFONTA;
typedef struct tagLOGPALETTE tagLOGPALETTE;
typedef struct tagMSG tagMSG;
typedef struct tagOFNA tagOFNA;
typedef struct tagPAINTSTRUCT tagPAINTSTRUCT;
typedef struct tagPALETTEENTRY tagPALETTEENTRY;
typedef struct tagPOINT tagPOINT;
typedef struct tagRECT tagRECT;
typedef struct tagRGBQUAD tagRGBQUAD;
typedef struct tagSIZE tagSIZE;
typedef struct tagTEXTMETRICA tagTEXTMETRICA;
typedef struct tagWNDCLASSA tagWNDCLASSA;
typedef struct threadlocaleinfostruct threadlocaleinfostruct;
typedef struct threadmbcinfostruct threadmbcinfostruct;
typedef struct tm tm;
typedef struct Var Var;
typedef struct VarFileInfo VarFileInfo;
typedef struct VS_VERSION_INFO VS_VERSION_INFO;

/* Struct: __lc_time_data (Size: 356 bytes) */
struct __lc_time_data {
    char * wday_abbr[7]; /* offset: 0x0 */
    char * wday[7]; /* offset: 0x1c */
    char * month_abbr[12]; /* offset: 0x38 */
    char * month[12]; /* offset: 0x68 */
    char * ampm[2]; /* offset: 0x98 */
    char * ww_sdatefmt; /* offset: 0xa0 */
    char * ww_ldatefmt; /* offset: 0xa4 */
    char * ww_timefmt; /* offset: 0xa8 */
    int ww_caltype; /* offset: 0xac */
    int refcount; /* offset: 0xb0 */
    wchar_t * _W_wday_abbr[7]; /* offset: 0xb4 */
    wchar_t * _W_wday[7]; /* offset: 0xd0 */
    wchar_t * _W_month_abbr[12]; /* offset: 0xec */
    wchar_t * _W_month[12]; /* offset: 0x11c */
    wchar_t * _W_ampm[2]; /* offset: 0x14c */
    wchar_t * _W_ww_sdatefmt; /* offset: 0x154 */
    wchar_t * _W_ww_ldatefmt; /* offset: 0x158 */
    wchar_t * _W_ww_timefmt; /* offset: 0x15c */
    wchar_t * _W_ww_locale_name; /* offset: 0x160 */
};

/* Struct: _ABC (Size: 12 bytes) */
struct _ABC {
    int abcA; /* offset: 0x0 */
    UINT abcB; /* offset: 0x4 */
    int abcC; /* offset: 0x8 */
};

/* Struct: _AppBarData (Size: 36 bytes) */
struct _AppBarData {
    DWORD cbSize; /* offset: 0x0 */
    HWND hWnd; /* offset: 0x4 */
    UINT uCallbackMessage; /* offset: 0x8 */
    UINT uEdge; /* offset: 0xc */
    RECT rc; /* offset: 0x10 */
    LPARAM lParam; /* offset: 0x20 */
};

/* Struct: _CONTEXT (Size: 716 bytes) */
struct _CONTEXT {
    DWORD ContextFlags; /* offset: 0x0 */
    DWORD Dr0; /* offset: 0x4 */
    DWORD Dr1; /* offset: 0x8 */
    DWORD Dr2; /* offset: 0xc */
    DWORD Dr3; /* offset: 0x10 */
    DWORD Dr6; /* offset: 0x14 */
    DWORD Dr7; /* offset: 0x18 */
    FLOATING_SAVE_AREA FloatSave; /* offset: 0x1c */
    DWORD SegGs; /* offset: 0x8c */
    DWORD SegFs; /* offset: 0x90 */
    DWORD SegEs; /* offset: 0x94 */
    DWORD SegDs; /* offset: 0x98 */
    DWORD Edi; /* offset: 0x9c */
    DWORD Esi; /* offset: 0xa0 */
    DWORD Ebx; /* offset: 0xa4 */
    DWORD Edx; /* offset: 0xa8 */
    DWORD Ecx; /* offset: 0xac */
    DWORD Eax; /* offset: 0xb0 */
    DWORD Ebp; /* offset: 0xb4 */
    DWORD Eip; /* offset: 0xb8 */
    DWORD SegCs; /* offset: 0xbc */
    DWORD EFlags; /* offset: 0xc0 */
    DWORD Esp; /* offset: 0xc4 */
    DWORD SegSs; /* offset: 0xc8 */
    BYTE ExtendedRegisters[512]; /* offset: 0xcc */
};

/* Struct: _cpinfo (Size: 20 bytes) */
struct _cpinfo {
    UINT MaxCharSize; /* offset: 0x0 */
    BYTE DefaultChar[2]; /* offset: 0x4 */
    BYTE LeadByte[12]; /* offset: 0x6 */
};

/* Struct: _CRT_DOUBLE (Size: 8 bytes) */
struct _CRT_DOUBLE {
    double x; /* offset: 0x0 */
};

/* Struct: _CRT_FLOAT (Size: 4 bytes) */
struct _CRT_FLOAT {
    float f; /* offset: 0x0 */
};

/* Struct: _devicemodeA (Size: 156 bytes) */
struct _devicemodeA {
    BYTE dmDeviceName[32]; /* offset: 0x0 */
    WORD dmSpecVersion; /* offset: 0x20 */
    WORD dmDriverVersion; /* offset: 0x22 */
    WORD dmSize; /* offset: 0x24 */
    WORD dmDriverExtra; /* offset: 0x26 */
    DWORD dmFields; /* offset: 0x28 */
    _union_655 field_2c; /* offset: 0x2c */
    short dmColor; /* offset: 0x3c */
    short dmDuplex; /* offset: 0x3e */
    short dmYResolution; /* offset: 0x40 */
    short dmTTOption; /* offset: 0x42 */
    short dmCollate; /* offset: 0x44 */
    BYTE dmFormName[32]; /* offset: 0x46 */
    WORD dmLogPixels; /* offset: 0x66 */
    DWORD dmBitsPerPel; /* offset: 0x68 */
    DWORD dmPelsWidth; /* offset: 0x6c */
    DWORD dmPelsHeight; /* offset: 0x70 */
    _union_658 field_74; /* offset: 0x74 */
    DWORD dmDisplayFrequency; /* offset: 0x78 */
    DWORD dmICMMethod; /* offset: 0x7c */
    DWORD dmICMIntent; /* offset: 0x80 */
    DWORD dmMediaType; /* offset: 0x84 */
    DWORD dmDitherType; /* offset: 0x88 */
    DWORD dmReserved1; /* offset: 0x8c */
    DWORD dmReserved2; /* offset: 0x90 */
    DWORD dmPanningWidth; /* offset: 0x94 */
    DWORD dmPanningHeight; /* offset: 0x98 */
};

/* Struct: _EXCEPTION_POINTERS (Size: 8 bytes) */
struct _EXCEPTION_POINTERS {
    PEXCEPTION_RECORD ExceptionRecord; /* offset: 0x0 */
    PCONTEXT ContextRecord; /* offset: 0x4 */
};

/* Struct: _EXCEPTION_RECORD (Size: 80 bytes) */
struct _EXCEPTION_RECORD {
    DWORD ExceptionCode; /* offset: 0x0 */
    DWORD ExceptionFlags; /* offset: 0x4 */
    _EXCEPTION_RECORD * ExceptionRecord; /* offset: 0x8 */
    PVOID ExceptionAddress; /* offset: 0xc */
    DWORD NumberParameters; /* offset: 0x10 */
    ULONG_PTR ExceptionInformation[15]; /* offset: 0x14 */
};

/* Struct: _FLOATING_SAVE_AREA (Size: 112 bytes) */
struct _FLOATING_SAVE_AREA {
    DWORD ControlWord; /* offset: 0x0 */
    DWORD StatusWord; /* offset: 0x4 */
    DWORD TagWord; /* offset: 0x8 */
    DWORD ErrorOffset; /* offset: 0xc */
    DWORD ErrorSelector; /* offset: 0x10 */
    DWORD DataOffset; /* offset: 0x14 */
    DWORD DataSelector; /* offset: 0x18 */
    BYTE RegisterArea[80]; /* offset: 0x1c */
    DWORD Cr0NpxState; /* offset: 0x6c */
};

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

/* Struct: _LDBL12 (Size: 12 bytes) */
struct _LDBL12 {
    uchar ld12[12]; /* offset: 0x0 */
};

/* Struct: _LDOUBLE (Size: 10 bytes) */
struct _LDOUBLE {
    uchar ld[10]; /* offset: 0x0 */
};

/* Struct: _LIST_ENTRY (Size: 8 bytes) */
struct _LIST_ENTRY {
    _LIST_ENTRY * Flink; /* offset: 0x0 */
    _LIST_ENTRY * Blink; /* offset: 0x4 */
};

/* Struct: _OVERLAPPED (Size: 20 bytes) */
struct _OVERLAPPED {
    ULONG_PTR Internal; /* offset: 0x0 */
    ULONG_PTR InternalHigh; /* offset: 0x4 */
    _union_518 u; /* offset: 0x8 */
    HANDLE hEvent; /* offset: 0x10 */
};

/* Struct: _POINTL (Size: 8 bytes) */
struct _POINTL {
    LONG x; /* offset: 0x0 */
    LONG y; /* offset: 0x4 */
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

/* Struct: _STARTUPINFOA (Size: 68 bytes) */
struct _STARTUPINFOA {
    DWORD cb; /* offset: 0x0 */
    LPSTR lpReserved; /* offset: 0x4 */
    LPSTR lpDesktop; /* offset: 0x8 */
    LPSTR lpTitle; /* offset: 0xc */
    DWORD dwX; /* offset: 0x10 */
    DWORD dwY; /* offset: 0x14 */
    DWORD dwXSize; /* offset: 0x18 */
    DWORD dwYSize; /* offset: 0x1c */
    DWORD dwXCountChars; /* offset: 0x20 */
    DWORD dwYCountChars; /* offset: 0x24 */
    DWORD dwFillAttribute; /* offset: 0x28 */
    DWORD dwFlags; /* offset: 0x2c */
    WORD wShowWindow; /* offset: 0x30 */
    WORD cbReserved2; /* offset: 0x32 */
    LPBYTE lpReserved2; /* offset: 0x34 */
    HANDLE hStdInput; /* offset: 0x38 */
    HANDLE hStdOutput; /* offset: 0x3c */
    HANDLE hStdError; /* offset: 0x40 */
};

/* Struct: _strflt (Size: 16 bytes) */
struct _strflt {
    int sign; /* offset: 0x0 */
    int decpt; /* offset: 0x4 */
    int flag; /* offset: 0x8 */
    char * mantissa; /* offset: 0xc */
};

/* Struct: _struct_519 (Size: 8 bytes) */
struct _struct_519 {
    DWORD Offset; /* offset: 0x0 */
    DWORD OffsetHigh; /* offset: 0x4 */
};

/* Struct: _struct_656 (Size: 16 bytes) */
struct _struct_656 {
    short dmOrientation; /* offset: 0x0 */
    short dmPaperSize; /* offset: 0x2 */
    short dmPaperLength; /* offset: 0x4 */
    short dmPaperWidth; /* offset: 0x6 */
    short dmScale; /* offset: 0x8 */
    short dmCopies; /* offset: 0xa */
    short dmDefaultSource; /* offset: 0xc */
    short dmPrintQuality; /* offset: 0xe */
};

/* Struct: _struct_657 (Size: 16 bytes) */
struct _struct_657 {
    POINTL dmPosition; /* offset: 0x0 */
    DWORD dmDisplayOrientation; /* offset: 0x8 */
    DWORD dmDisplayFixedOutput; /* offset: 0xc */
};

/* Struct: _SYSTEMTIME (Size: 16 bytes) */
struct _SYSTEMTIME {
    WORD wYear; /* offset: 0x0 */
    WORD wMonth; /* offset: 0x2 */
    WORD wDayOfWeek; /* offset: 0x4 */
    WORD wDay; /* offset: 0x6 */
    WORD wHour; /* offset: 0x8 */
    WORD wMinute; /* offset: 0xa */
    WORD wSecond; /* offset: 0xc */
    WORD wMilliseconds; /* offset: 0xe */
};

/* Struct: _TIME_ZONE_INFORMATION (Size: 172 bytes) */
struct _TIME_ZONE_INFORMATION {
    LONG Bias; /* offset: 0x0 */
    WCHAR StandardName[32]; /* offset: 0x4 */
    SYSTEMTIME StandardDate; /* offset: 0x44 */
    LONG StandardBias; /* offset: 0x54 */
    WCHAR DaylightName[32]; /* offset: 0x58 */
    SYSTEMTIME DaylightDate; /* offset: 0x98 */
    LONG DaylightBias; /* offset: 0xa8 */
};

/* Struct: HACCEL__ (Size: 4 bytes) */
struct HACCEL__ {
    int unused; /* offset: 0x0 */
};

/* Struct: HBITMAP__ (Size: 4 bytes) */
struct HBITMAP__ {
    int unused; /* offset: 0x0 */
};

/* Struct: HBRUSH__ (Size: 4 bytes) */
struct HBRUSH__ {
    int unused; /* offset: 0x0 */
};

/* Struct: HDC__ (Size: 4 bytes) */
struct HDC__ {
    int unused; /* offset: 0x0 */
};

/* Struct: HFONT__ (Size: 4 bytes) */
struct HFONT__ {
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

/* Struct: HKEY__ (Size: 4 bytes) */
struct HKEY__ {
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

/* Struct: HPEN__ (Size: 4 bytes) */
struct HPEN__ {
    int unused; /* offset: 0x0 */
};

/* Struct: HRGN__ (Size: 4 bytes) */
struct HRGN__ {
    int unused; /* offset: 0x0 */
};

/* Struct: HRSRC__ (Size: 4 bytes) */
struct HRSRC__ {
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

/* Struct: lconv (Size: 80 bytes) */
struct lconv {
    char * decimal_point; /* offset: 0x0 */
    char * thousands_sep; /* offset: 0x4 */
    char * grouping; /* offset: 0x8 */
    char * int_curr_symbol; /* offset: 0xc */
    char * currency_symbol; /* offset: 0x10 */
    char * mon_decimal_point; /* offset: 0x14 */
    char * mon_thousands_sep; /* offset: 0x18 */
    char * mon_grouping; /* offset: 0x1c */
    char * positive_sign; /* offset: 0x20 */
    char * negative_sign; /* offset: 0x24 */
    char int_frac_digits; /* offset: 0x28 */
    char frac_digits; /* offset: 0x29 */
    char p_cs_precedes; /* offset: 0x2a */
    char p_sep_by_space; /* offset: 0x2b */
    char n_cs_precedes; /* offset: 0x2c */
    char n_sep_by_space; /* offset: 0x2d */
    char p_sign_posn; /* offset: 0x2e */
    char n_sign_posn; /* offset: 0x2f */
    wchar_t * _W_decimal_point; /* offset: 0x30 */
    wchar_t * _W_thousands_sep; /* offset: 0x34 */
    wchar_t * _W_int_curr_symbol; /* offset: 0x38 */
    wchar_t * _W_currency_symbol; /* offset: 0x3c */
    wchar_t * _W_mon_decimal_point; /* offset: 0x40 */
    wchar_t * _W_mon_thousands_sep; /* offset: 0x44 */
    wchar_t * _W_positive_sign; /* offset: 0x48 */
    wchar_t * _W_negative_sign; /* offset: 0x4c */
};

/* Struct: localeinfo_struct (Size: 8 bytes) */
struct localeinfo_struct {
    pthreadlocinfo locinfo; /* offset: 0x0 */
    pthreadmbcinfo mbcinfo; /* offset: 0x4 */
};

/* Struct: localerefcount (Size: 16 bytes) */
struct localerefcount {
    char * locale; /* offset: 0x0 */
    wchar_t * wlocale; /* offset: 0x4 */
    int * refcount; /* offset: 0x8 */
    int * wrefcount; /* offset: 0xc */
};

/* Struct: StringFileInfo (Size: 6 bytes) */
struct StringFileInfo {
    word wLength; /* offset: 0x0 */
    word wValueLength; /* offset: 0x2 */
    word wType; /* offset: 0x4 */
};

/* Struct: StringInfo (Size: 6 bytes) */
struct StringInfo {
    word wLength; /* offset: 0x0 */
    word wValueLength; /* offset: 0x2 */
    word wType; /* offset: 0x4 */
};

/* Struct: StringTable (Size: 6 bytes) */
struct StringTable {
    word wLength; /* offset: 0x0 */
    word wValueLength; /* offset: 0x2 */
    word wType; /* offset: 0x4 */
};

/* Struct: tagBITMAPINFO (Size: 44 bytes) */
struct tagBITMAPINFO {
    BITMAPINFOHEADER bmiHeader; /* offset: 0x0 */
    RGBQUAD bmiColors[1]; /* offset: 0x28 */
};

/* Struct: tagBITMAPINFOHEADER (Size: 40 bytes) */
struct tagBITMAPINFOHEADER {
    DWORD biSize; /* offset: 0x0 */
    LONG biWidth; /* offset: 0x4 */
    LONG biHeight; /* offset: 0x8 */
    WORD biPlanes; /* offset: 0xc */
    WORD biBitCount; /* offset: 0xe */
    DWORD biCompression; /* offset: 0x10 */
    DWORD biSizeImage; /* offset: 0x14 */
    LONG biXPelsPerMeter; /* offset: 0x18 */
    LONG biYPelsPerMeter; /* offset: 0x1c */
    DWORD biClrUsed; /* offset: 0x20 */
    DWORD biClrImportant; /* offset: 0x24 */
};

/* Struct: tagLOGFONTA (Size: 60 bytes) */
struct tagLOGFONTA {
    LONG lfHeight; /* offset: 0x0 */
    LONG lfWidth; /* offset: 0x4 */
    LONG lfEscapement; /* offset: 0x8 */
    LONG lfOrientation; /* offset: 0xc */
    LONG lfWeight; /* offset: 0x10 */
    BYTE lfItalic; /* offset: 0x14 */
    BYTE lfUnderline; /* offset: 0x15 */
    BYTE lfStrikeOut; /* offset: 0x16 */
    BYTE lfCharSet; /* offset: 0x17 */
    BYTE lfOutPrecision; /* offset: 0x18 */
    BYTE lfClipPrecision; /* offset: 0x19 */
    BYTE lfQuality; /* offset: 0x1a */
    BYTE lfPitchAndFamily; /* offset: 0x1b */
    CHAR lfFaceName[32]; /* offset: 0x1c */
};

/* Struct: tagLOGPALETTE (Size: 8 bytes) */
struct tagLOGPALETTE {
    WORD palVersion; /* offset: 0x0 */
    WORD palNumEntries; /* offset: 0x2 */
    PALETTEENTRY palPalEntry[1]; /* offset: 0x4 */
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

/* Struct: tagRGBQUAD (Size: 4 bytes) */
struct tagRGBQUAD {
    BYTE rgbBlue; /* offset: 0x0 */
    BYTE rgbGreen; /* offset: 0x1 */
    BYTE rgbRed; /* offset: 0x2 */
    BYTE rgbReserved; /* offset: 0x3 */
};

/* Struct: tagSIZE (Size: 8 bytes) */
struct tagSIZE {
    LONG cx; /* offset: 0x0 */
    LONG cy; /* offset: 0x4 */
};

/* Struct: tagTEXTMETRICA (Size: 56 bytes) */
struct tagTEXTMETRICA {
    LONG tmHeight; /* offset: 0x0 */
    LONG tmAscent; /* offset: 0x4 */
    LONG tmDescent; /* offset: 0x8 */
    LONG tmInternalLeading; /* offset: 0xc */
    LONG tmExternalLeading; /* offset: 0x10 */
    LONG tmAveCharWidth; /* offset: 0x14 */
    LONG tmMaxCharWidth; /* offset: 0x18 */
    LONG tmWeight; /* offset: 0x1c */
    LONG tmOverhang; /* offset: 0x20 */
    LONG tmDigitizedAspectX; /* offset: 0x24 */
    LONG tmDigitizedAspectY; /* offset: 0x28 */
    BYTE tmFirstChar; /* offset: 0x2c */
    BYTE tmLastChar; /* offset: 0x2d */
    BYTE tmDefaultChar; /* offset: 0x2e */
    BYTE tmBreakChar; /* offset: 0x2f */
    BYTE tmItalic; /* offset: 0x30 */
    BYTE tmUnderlined; /* offset: 0x31 */
    BYTE tmStruckOut; /* offset: 0x32 */
    BYTE tmPitchAndFamily; /* offset: 0x33 */
    BYTE tmCharSet; /* offset: 0x34 */
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

/* Struct: threadlocaleinfostruct (Size: 184 bytes) */
struct threadlocaleinfostruct {
    int refcount; /* offset: 0x0 */
    uint32_t lc_codepage; /* offset: 0x4 */
    uint32_t lc_collate_cp; /* offset: 0x8 */
    uint32_t lc_time_cp; /* offset: 0xc */
    locrefcount lc_category[6]; /* offset: 0x10 */
    int lc_clike; /* offset: 0x70 */
    int mb_cur_max; /* offset: 0x74 */
    int * lconv_intl_refcount; /* offset: 0x78 */
    int * lconv_num_refcount; /* offset: 0x7c */
    int * lconv_mon_refcount; /* offset: 0x80 */
    lconv * lconv; /* offset: 0x84 */
    int * ctype1_refcount; /* offset: 0x88 */
    uint16_t * ctype1; /* offset: 0x8c */
    uint16_t * pctype; /* offset: 0x90 */
    uchar * pclmap; /* offset: 0x94 */
    uchar * pcumap; /* offset: 0x98 */
    __lc_time_data * lc_time_curr; /* offset: 0x9c */
    wchar_t * locale_name[6]; /* offset: 0xa0 */
};

/* Struct: threadmbcinfostruct (Size: 544 bytes) */
struct threadmbcinfostruct {
    int refcount; /* offset: 0x0 */
    int mbcodepage; /* offset: 0x4 */
    int ismbcodepage; /* offset: 0x8 */
    uint16_t mbulinfo[6]; /* offset: 0xc */
    uchar mbctype[257]; /* offset: 0x18 */
    uchar mbcasemap[256]; /* offset: 0x119 */
    wchar_t * mblocalename; /* offset: 0x21c */
};

/* Struct: tm (Size: 36 bytes) */
struct tm {
    int tm_sec; /* offset: 0x0 */
    int tm_min; /* offset: 0x4 */
    int tm_hour; /* offset: 0x8 */
    int tm_mday; /* offset: 0xc */
    int tm_mon; /* offset: 0x10 */
    int tm_year; /* offset: 0x14 */
    int tm_wday; /* offset: 0x18 */
    int tm_yday; /* offset: 0x1c */
    int tm_isdst; /* offset: 0x20 */
};

/* Struct: Var (Size: 6 bytes) */
struct Var {
    word wLength; /* offset: 0x0 */
    word wValueLength; /* offset: 0x2 */
    word wType; /* offset: 0x4 */
};

/* Struct: VarFileInfo (Size: 6 bytes) */
struct VarFileInfo {
    word wLength; /* offset: 0x0 */
    word wValueLength; /* offset: 0x2 */
    word wType; /* offset: 0x4 */
};

/* Struct: VS_VERSION_INFO (Size: 92 bytes) */
struct VS_VERSION_INFO {
    word StructLength; /* offset: 0x0 */
    word ValueLength; /* offset: 0x2 */
    word StructType; /* offset: 0x4 */
    unicode Info; /* offset: 0x6 */
    uint8_t Padding[2]; /* offset: 0x26 */
    dword Signature; /* offset: 0x28 */
    word StructVersion[2]; /* offset: 0x2c */
    word FileVersion[4]; /* offset: 0x30 */
    word ProductVersion[4]; /* offset: 0x38 */
    dword FileFlagsMask[2]; /* offset: 0x40 */
    dword FileFlags; /* offset: 0x48 */
    dword FileOS; /* offset: 0x4c */
    dword FileType; /* offset: 0x50 */
    dword FileSubtype; /* offset: 0x54 */
    dword FileTimestamp; /* offset: 0x58 */
};

#endif /* DUEL_TYPES_H */

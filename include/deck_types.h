/*
 * deck_types.h - Data Types and Structure Definitions for DECK.EXE
 */
#ifndef DECK_TYPES_H
#define DECK_TYPES_H

#include "windows_types.h"

/* Forward Declarations */
typedef struct __lc_time_data __lc_time_data;
typedef struct _CONTEXT _CONTEXT;
typedef struct _cpinfo _cpinfo;
typedef struct _EXCEPTION_POINTERS _EXCEPTION_POINTERS;
typedef struct _EXCEPTION_RECORD _EXCEPTION_RECORD;
typedef struct _FLOATING_SAVE_AREA _FLOATING_SAVE_AREA;
typedef struct _iobuf _iobuf;
typedef struct _OVERLAPPED _OVERLAPPED;
typedef struct _STARTUPINFOA _STARTUPINFOA;
typedef struct _struct_519 _struct_519;
typedef struct HINSTANCE__ HINSTANCE__;
typedef struct HWND__ HWND__;
typedef struct IMAGE_BASE_RELOCATION IMAGE_BASE_RELOCATION;
typedef struct IMAGE_DATA_DIRECTORY IMAGE_DATA_DIRECTORY;
typedef struct IMAGE_DEBUG_DIRECTORY IMAGE_DEBUG_DIRECTORY;
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
typedef struct threadlocaleinfostruct threadlocaleinfostruct;
typedef struct threadmbcinfostruct threadmbcinfostruct;

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

/* Struct: _OVERLAPPED (Size: 20 bytes) */
struct _OVERLAPPED {
    ULONG_PTR Internal; /* offset: 0x0 */
    ULONG_PTR InternalHigh; /* offset: 0x4 */
    _union_518 u; /* offset: 0x8 */
    HANDLE hEvent; /* offset: 0x10 */
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

/* Struct: _struct_519 (Size: 8 bytes) */
struct _struct_519 {
    DWORD Offset; /* offset: 0x0 */
    DWORD OffsetHigh; /* offset: 0x4 */
};

/* Struct: HINSTANCE__ (Size: 4 bytes) */
struct HINSTANCE__ {
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

#endif /* DECK_TYPES_H */

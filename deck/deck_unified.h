typedef unsigned char   undefined;

typedef unsigned char    bool;
typedef unsigned char    byte;
typedef unsigned int    dword;
typedef pointer32 ImageBaseOffset32;

typedef long long    longlong;
typedef unsigned char    uchar;
typedef unsigned int    uint;
typedef unsigned long    ulong;
typedef unsigned long long    ulonglong;
typedef unsigned char    undefined1;
typedef unsigned short    undefined2;
typedef unsigned int    undefined4;
typedef unsigned long long    undefined8;
typedef unsigned short    ushort;
typedef short    wchar_t;
typedef unsigned short    word;
#define unkbyte9   unsigned long long
#define unkbyte10   unsigned long long
#define unkbyte11   unsigned long long
#define unkbyte12   unsigned long long
#define unkbyte13   unsigned long long
#define unkbyte14   unsigned long long
#define unkbyte15   unsigned long long
#define unkbyte16   unsigned long long

#define unkuint9   unsigned long long
#define unkuint10   unsigned long long
#define unkuint11   unsigned long long
#define unkuint12   unsigned long long
#define unkuint13   unsigned long long
#define unkuint14   unsigned long long
#define unkuint15   unsigned long long
#define unkuint16   unsigned long long

#define unkint9   long long
#define unkint10   long long
#define unkint11   long long
#define unkint12   long long
#define unkint13   long long
#define unkint14   long long
#define unkint15   long long
#define unkint16   long long

#define unkfloat1   float
#define unkfloat2   float
#define unkfloat3   float
#define unkfloat5   double
#define unkfloat6   double
#define unkfloat7   double
#define unkfloat9   long double
#define unkfloat11   long double
#define unkfloat12   long double
#define unkfloat13   long double
#define unkfloat14   long double
#define unkfloat15   long double
#define unkfloat16   long double

#define BADSPACEBASE   void
#define code   void

typedef union IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryUnion IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryUnion, *PIMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryUnion;

typedef struct IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryStruct IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryStruct, *PIMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryStruct;

struct IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryStruct {
    dword OffsetToDirectory:31;
    dword DataIsDirectory:1;
};

union IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryUnion {
    dword OffsetToData;
    struct IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryStruct IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryStruct;
};

typedef unsigned short    wchar16;
typedef struct _cpinfo _cpinfo, *P_cpinfo;

typedef uint UINT;

typedef uchar BYTE;

struct _cpinfo {
    UINT MaxCharSize;
    BYTE DefaultChar[2];
    BYTE LeadByte[12];
};

typedef struct _cpinfo *LPCPINFO;

typedef struct _STARTUPINFOA _STARTUPINFOA, *P_STARTUPINFOA;

typedef ulong DWORD;

typedef char CHAR;

typedef CHAR *LPSTR;

typedef ushort WORD;

typedef BYTE *LPBYTE;

typedef void *HANDLE;

struct _STARTUPINFOA {
    DWORD cb;
    LPSTR lpReserved;
    LPSTR lpDesktop;
    LPSTR lpTitle;
    DWORD dwX;
    DWORD dwY;
    DWORD dwXSize;
    DWORD dwYSize;
    DWORD dwXCountChars;
    DWORD dwYCountChars;
    DWORD dwFillAttribute;
    DWORD dwFlags;
    WORD wShowWindow;
    WORD cbReserved2;
    LPBYTE lpReserved2;
    HANDLE hStdInput;
    HANDLE hStdOutput;
    HANDLE hStdError;
};

typedef struct _STARTUPINFOA *LPSTARTUPINFOA;

typedef struct _OVERLAPPED _OVERLAPPED, *P_OVERLAPPED;

typedef ulong ULONG_PTR;

typedef union _union_518 _union_518, *P_union_518;

typedef struct _struct_519 _struct_519, *P_struct_519;

typedef void *PVOID;

struct _struct_519 {
    DWORD Offset;
    DWORD OffsetHigh;
};

union _union_518 {
    struct _struct_519 s;
    PVOID Pointer;
};

struct _OVERLAPPED {
    ULONG_PTR Internal;
    ULONG_PTR InternalHigh;
    union _union_518 u;
    HANDLE hEvent;
};

typedef struct _OVERLAPPED *LPOVERLAPPED;

typedef struct _CONTEXT _CONTEXT, *P_CONTEXT;

typedef struct _FLOATING_SAVE_AREA _FLOATING_SAVE_AREA, *P_FLOATING_SAVE_AREA;

typedef struct _FLOATING_SAVE_AREA FLOATING_SAVE_AREA;

struct _FLOATING_SAVE_AREA {
    DWORD ControlWord;
    DWORD StatusWord;
    DWORD TagWord;
    DWORD ErrorOffset;
    DWORD ErrorSelector;
    DWORD DataOffset;
    DWORD DataSelector;
    BYTE RegisterArea[80];
    DWORD Cr0NpxState;
};

struct _CONTEXT {
    DWORD ContextFlags;
    DWORD Dr0;
    DWORD Dr1;
    DWORD Dr2;
    DWORD Dr3;
    DWORD Dr6;
    DWORD Dr7;
    FLOATING_SAVE_AREA FloatSave;
    DWORD SegGs;
    DWORD SegFs;
    DWORD SegEs;
    DWORD SegDs;
    DWORD Edi;
    DWORD Esi;
    DWORD Ebx;
    DWORD Edx;
    DWORD Ecx;
    DWORD Eax;
    DWORD Ebp;
    DWORD Eip;
    DWORD SegCs;
    DWORD EFlags;
    DWORD Esp;
    DWORD SegSs;
    BYTE ExtendedRegisters[512];
};

typedef struct _EXCEPTION_RECORD _EXCEPTION_RECORD, *P_EXCEPTION_RECORD;

struct _EXCEPTION_RECORD {
    DWORD ExceptionCode;
    DWORD ExceptionFlags;
    struct _EXCEPTION_RECORD *ExceptionRecord;
    PVOID ExceptionAddress;
    DWORD NumberParameters;
    ULONG_PTR ExceptionInformation[15];
};

typedef struct _EXCEPTION_POINTERS _EXCEPTION_POINTERS, *P_EXCEPTION_POINTERS;

typedef struct _EXCEPTION_RECORD EXCEPTION_RECORD;

typedef EXCEPTION_RECORD *PEXCEPTION_RECORD;

typedef struct _CONTEXT CONTEXT;

typedef CONTEXT *PCONTEXT;

struct _EXCEPTION_POINTERS {
    PEXCEPTION_RECORD ExceptionRecord;
    PCONTEXT ContextRecord;
};

typedef struct _iobuf _iobuf, *P_iobuf;

struct _iobuf {
    char *_ptr;
    int _cnt;
    char *_base;
    int _flag;
    int _file;
    int _charbuf;
    int _bufsiz;
    char *_tmpfname;
};

typedef struct _iobuf FILE;

typedef int BOOL;

typedef BOOL (*PHANDLER_ROUTINE)(DWORD);

typedef char *va_list;

typedef struct lconv lconv, *Plconv;

struct lconv {
    char *decimal_point;
    char *thousands_sep;
    char *grouping;
    char *int_curr_symbol;
    char *currency_symbol;
    char *mon_decimal_point;
    char *mon_thousands_sep;
    char *mon_grouping;
    char *positive_sign;
    char *negative_sign;
    char int_frac_digits;
    char frac_digits;
    char p_cs_precedes;
    char p_sep_by_space;
    char n_cs_precedes;
    char n_sep_by_space;
    char p_sign_posn;
    char n_sign_posn;
    wchar_t *_W_decimal_point;
    wchar_t *_W_thousands_sep;
    wchar_t *_W_int_curr_symbol;
    wchar_t *_W_currency_symbol;
    wchar_t *_W_mon_decimal_point;
    wchar_t *_W_mon_thousands_sep;
    wchar_t *_W_positive_sign;
    wchar_t *_W_negative_sign;
};

typedef struct threadlocaleinfostruct threadlocaleinfostruct, *Pthreadlocaleinfostruct;

typedef struct threadlocaleinfostruct *pthreadlocinfo;

typedef struct localerefcount localerefcount, *Plocalerefcount;

typedef struct localerefcount locrefcount;

typedef struct __lc_time_data __lc_time_data, *P__lc_time_data;

struct localerefcount {
    char *locale;
    wchar_t *wlocale;
    int *refcount;
    int *wrefcount;
};

struct threadlocaleinfostruct {
    int refcount;
    uint lc_codepage;
    uint lc_collate_cp;
    uint lc_time_cp;
    locrefcount lc_category[6];
    int lc_clike;
    int mb_cur_max;
    int *lconv_intl_refcount;
    int *lconv_num_refcount;
    int *lconv_mon_refcount;
    struct lconv *lconv;
    int *ctype1_refcount;
    ushort *ctype1;
    ushort *pctype;
    uchar *pclmap;
    uchar *pcumap;
    struct __lc_time_data *lc_time_curr;
    wchar_t *locale_name[6];
};

struct __lc_time_data {
    char *wday_abbr[7];
    char *wday[7];
    char *month_abbr[12];
    char *month[12];
    char *ampm[2];
    char *ww_sdatefmt;
    char *ww_ldatefmt;
    char *ww_timefmt;
    int ww_caltype;
    int refcount;
    wchar_t *_W_wday_abbr[7];
    wchar_t *_W_wday[7];
    wchar_t *_W_month_abbr[12];
    wchar_t *_W_month[12];
    wchar_t *_W_ampm[2];
    wchar_t *_W_ww_sdatefmt;
    wchar_t *_W_ww_ldatefmt;
    wchar_t *_W_ww_timefmt;
    wchar_t *_W_ww_locale_name;
};

typedef uint size_t;

typedef struct localeinfo_struct localeinfo_struct, *Plocaleinfo_struct;

typedef struct threadmbcinfostruct threadmbcinfostruct, *Pthreadmbcinfostruct;

typedef struct threadmbcinfostruct *pthreadmbcinfo;

struct threadmbcinfostruct {
    int refcount;
    int mbcodepage;
    int ismbcodepage;
    ushort mbulinfo[6];
    uchar mbctype[257];
    uchar mbcasemap[256];
    wchar_t *mblocalename;
};

struct localeinfo_struct {
    pthreadlocinfo locinfo;
    pthreadmbcinfo mbcinfo;
};

typedef int intptr_t;

typedef struct localeinfo_struct *_locale_t;

typedef wchar_t WCHAR;

typedef WCHAR *LPWSTR;

typedef long LONG;

typedef WCHAR *LPWCH;

typedef WCHAR *LPCWSTR;

typedef CHAR *LPCSTR;

typedef LONG *PLONG;

typedef CHAR *LPCH;

typedef DWORD LCID;

typedef struct IMAGE_DOS_HEADER IMAGE_DOS_HEADER, *PIMAGE_DOS_HEADER;

struct IMAGE_DOS_HEADER {
    char e_magic[2]; /* Magic number */
    word e_cblp; /* Bytes of last page */
    word e_cp; /* Pages in file */
    word e_crlc; /* Relocations */
    word e_cparhdr; /* Size of header in paragraphs */
    word e_minalloc; /* Minimum extra paragraphs needed */
    word e_maxalloc; /* Maximum extra paragraphs needed */
    word e_ss; /* Initial (relative) SS value */
    word e_sp; /* Initial SP value */
    word e_csum; /* Checksum */
    word e_ip; /* Initial IP value */
    word e_cs; /* Initial (relative) CS value */
    word e_lfarlc; /* File address of relocation table */
    word e_ovno; /* Overlay number */
    word e_res[4][4]; /* Reserved words */
    word e_oemid; /* OEM identifier (for e_oeminfo) */
    word e_oeminfo; /* OEM information; e_oemid specific */
    word e_res2[10][10]; /* Reserved words */
    dword e_lfanew; /* File address of new exe header */
    byte e_program[64]; /* Actual DOS program */
};

typedef ULONG_PTR SIZE_T;

typedef uint UINT_PTR;

typedef long LONG_PTR;

typedef UINT_PTR WPARAM;

typedef DWORD *LPDWORD;

typedef LONG_PTR LPARAM;

typedef struct HINSTANCE__ HINSTANCE__, *PHINSTANCE__;

typedef struct HINSTANCE__ *HINSTANCE;

struct HINSTANCE__ {
    int unused;
};

typedef void *LPVOID;

typedef struct HWND__ HWND__, *PHWND__;

typedef struct HWND__ *HWND;

struct HWND__ {
    int unused;
};

typedef HINSTANCE HMODULE;

typedef int (*FARPROC)(void);

typedef WORD *LPWORD;

typedef BOOL *LPBOOL;

typedef void *LPCVOID;

typedef struct IMAGE_OPTIONAL_HEADER32 IMAGE_OPTIONAL_HEADER32, *PIMAGE_OPTIONAL_HEADER32;

typedef struct IMAGE_DATA_DIRECTORY IMAGE_DATA_DIRECTORY, *PIMAGE_DATA_DIRECTORY;

struct IMAGE_DATA_DIRECTORY {
    ImageBaseOffset32 VirtualAddress;
    dword Size;
};

struct IMAGE_OPTIONAL_HEADER32 {
    word Magic;
    byte MajorLinkerVersion;
    byte MinorLinkerVersion;
    dword SizeOfCode;
    dword SizeOfInitializedData;
    dword SizeOfUninitializedData;
    ImageBaseOffset32 AddressOfEntryPoint;
    ImageBaseOffset32 BaseOfCode;
    ImageBaseOffset32 BaseOfData;
    pointer32 ImageBase;
    dword SectionAlignment;
    dword FileAlignment;
    word MajorOperatingSystemVersion;
    word MinorOperatingSystemVersion;
    word MajorImageVersion;
    word MinorImageVersion;
    word MajorSubsystemVersion;
    word MinorSubsystemVersion;
    dword Win32VersionValue;
    dword SizeOfImage;
    dword SizeOfHeaders;
    dword CheckSum;
    word Subsystem;
    word DllCharacteristics;
    dword SizeOfStackReserve;
    dword SizeOfStackCommit;
    dword SizeOfHeapReserve;
    dword SizeOfHeapCommit;
    dword LoaderFlags;
    dword NumberOfRvaAndSizes;
    struct IMAGE_DATA_DIRECTORY DataDirectory[16];
};

typedef struct IMAGE_RESOURCE_DIRECTORY_ENTRY_NameStruct IMAGE_RESOURCE_DIRECTORY_ENTRY_NameStruct, *PIMAGE_RESOURCE_DIRECTORY_ENTRY_NameStruct;

struct IMAGE_RESOURCE_DIRECTORY_ENTRY_NameStruct {
    dword NameOffset:31;
    dword NameIsString:1;
};

typedef struct IMAGE_DEBUG_DIRECTORY IMAGE_DEBUG_DIRECTORY, *PIMAGE_DEBUG_DIRECTORY;

struct IMAGE_DEBUG_DIRECTORY {
    dword Characteristics;
    dword TimeDateStamp;
    word MajorVersion;
    word MinorVersion;
    dword Type;
    dword SizeOfData;
    dword AddressOfRawData;
    dword PointerToRawData;
};

typedef struct IMAGE_FILE_HEADER IMAGE_FILE_HEADER, *PIMAGE_FILE_HEADER;

struct IMAGE_FILE_HEADER {
    word Machine; /* 332 */
    word NumberOfSections;
    dword TimeDateStamp;
    dword PointerToSymbolTable;
    dword NumberOfSymbols;
    word SizeOfOptionalHeader;
    word Characteristics;
};

typedef struct IMAGE_NT_HEADERS32 IMAGE_NT_HEADERS32, *PIMAGE_NT_HEADERS32;

struct IMAGE_NT_HEADERS32 {
    char Signature[4];
    struct IMAGE_FILE_HEADER FileHeader;
    struct IMAGE_OPTIONAL_HEADER32 OptionalHeader;
};

typedef struct IMAGE_RESOURCE_DIRECTORY_ENTRY IMAGE_RESOURCE_DIRECTORY_ENTRY, *PIMAGE_RESOURCE_DIRECTORY_ENTRY;

typedef union IMAGE_RESOURCE_DIRECTORY_ENTRY_NameUnion IMAGE_RESOURCE_DIRECTORY_ENTRY_NameUnion, *PIMAGE_RESOURCE_DIRECTORY_ENTRY_NameUnion;

union IMAGE_RESOURCE_DIRECTORY_ENTRY_NameUnion {
    struct IMAGE_RESOURCE_DIRECTORY_ENTRY_NameStruct IMAGE_RESOURCE_DIRECTORY_ENTRY_NameStruct;
    dword Name;
    word Id;
};

struct IMAGE_RESOURCE_DIRECTORY_ENTRY {
    union IMAGE_RESOURCE_DIRECTORY_ENTRY_NameUnion NameUnion;
    union IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryUnion DirectoryUnion;
};

typedef struct IMAGE_SECTION_HEADER IMAGE_SECTION_HEADER, *PIMAGE_SECTION_HEADER;

typedef union Misc Misc, *PMisc;

typedef enum SectionFlags {
    IMAGE_SCN_TYPE_NO_PAD=8,
    IMAGE_SCN_RESERVED_0001=16,
    IMAGE_SCN_CNT_CODE=32,
    IMAGE_SCN_CNT_INITIALIZED_DATA=64,
    IMAGE_SCN_CNT_UNINITIALIZED_DATA=128,
    IMAGE_SCN_LNK_OTHER=256,
    IMAGE_SCN_LNK_INFO=512,
    IMAGE_SCN_RESERVED_0040=1024,
    IMAGE_SCN_LNK_REMOVE=2048,
    IMAGE_SCN_LNK_COMDAT=4096,
    IMAGE_SCN_GPREL=32768,
    IMAGE_SCN_MEM_16BIT=131072,
    IMAGE_SCN_MEM_PURGEABLE=131072,
    IMAGE_SCN_MEM_LOCKED=262144,
    IMAGE_SCN_MEM_PRELOAD=524288,
    IMAGE_SCN_ALIGN_1BYTES=1048576,
    IMAGE_SCN_ALIGN_2BYTES=2097152,
    IMAGE_SCN_ALIGN_4BYTES=3145728,
    IMAGE_SCN_ALIGN_8BYTES=4194304,
    IMAGE_SCN_ALIGN_16BYTES=5242880,
    IMAGE_SCN_ALIGN_32BYTES=6291456,
    IMAGE_SCN_ALIGN_64BYTES=7340032,
    IMAGE_SCN_ALIGN_128BYTES=8388608,
    IMAGE_SCN_ALIGN_256BYTES=9437184,
    IMAGE_SCN_ALIGN_512BYTES=10485760,
    IMAGE_SCN_ALIGN_1024BYTES=11534336,
    IMAGE_SCN_ALIGN_2048BYTES=12582912,
    IMAGE_SCN_ALIGN_4096BYTES=13631488,
    IMAGE_SCN_ALIGN_8192BYTES=14680064,
    IMAGE_SCN_LNK_NRELOC_OVFL=16777216,
    IMAGE_SCN_MEM_DISCARDABLE=33554432,
    IMAGE_SCN_MEM_NOT_CACHED=67108864,
    IMAGE_SCN_MEM_NOT_PAGED=134217728,
    IMAGE_SCN_MEM_SHARED=268435456,
    IMAGE_SCN_MEM_EXECUTE=536870912,
    IMAGE_SCN_MEM_READ=1073741824,
    IMAGE_SCN_MEM_WRITE=2147483648
} SectionFlags;

union Misc {
    dword PhysicalAddress;
    dword VirtualSize;
};

struct IMAGE_SECTION_HEADER {
    char Name[8];
    union Misc Misc;
    ImageBaseOffset32 VirtualAddress;
    dword SizeOfRawData;
    dword PointerToRawData;
    dword PointerToRelocations;
    dword PointerToLinenumbers;
    word NumberOfRelocations;
    word NumberOfLinenumbers;
    enum SectionFlags Characteristics;
};

typedef struct IMAGE_BASE_RELOCATION IMAGE_BASE_RELOCATION, *PIMAGE_BASE_RELOCATION;

struct IMAGE_BASE_RELOCATION {
    dword VirtualAddress;
    dword SizeOfBlock;
};

typedef struct IMAGE_RESOURCE_DATA_ENTRY IMAGE_RESOURCE_DATA_ENTRY, *PIMAGE_RESOURCE_DATA_ENTRY;

struct IMAGE_RESOURCE_DATA_ENTRY {
    dword OffsetToData;
    dword Size;
    dword CodePage;
    dword Reserved;
};

typedef struct IMAGE_RESOURCE_DIRECTORY IMAGE_RESOURCE_DIRECTORY, *PIMAGE_RESOURCE_DIRECTORY;

struct IMAGE_RESOURCE_DIRECTORY {
    dword Characteristics;
    dword TimeDateStamp;
    word MajorVersion;
    word MinorVersion;
    word NumberOfNamedEntries;
    word NumberOfIdEntries;
};




undefined4 thunk_FUN_00401010(undefined4 arg_1,undefined4 arg_2,char *str_3);
undefined4 DeckBuilder_CheckExistingInstance(undefined4 arg_1,undefined4 arg_2,char *str_3);
void DeckBuilderMain(void);
void entry(void);
void __cdecl __amsg_exit(int arg_1);
int __cdecl __cinit(int arg_1);
void __cdecl _exit(int arg_1);
void __cdecl __exit(UINT arg_1);
void __cdecl __cexit(void);
void __cdecl __c_exit(void);
void __cdecl doexit(UINT arg_1,int arg_2,int arg_3);
void __cdecl __initterm(int *ptr_1,int *ptr_2);
void __cdecl __global_unwind2(PVOID arg_1);
void __cdecl __local_unwind2(int arg1,int arg2);
void DeckBuilder_InitSubsystems(void);
int __cdecl __XcptFilter(ulong card_id,_EXCEPTION_POINTERS *out_filter);
int * __cdecl xcptlookup(int arg_1);
int __cdecl __ismbbkalnum(uint arg_1);
int __cdecl __ismbbkprint(uint arg_1);
int __cdecl __ismbbkpunct(uint arg_1);
int __cdecl __ismbbalnum(uint arg_1);
int __cdecl __ismbbalpha(uint arg_1);
int __cdecl __ismbbgraph(uint arg_1);
int __cdecl __ismbbprint(uint arg_1);
int __cdecl __ismbbpunct(uint arg_1);
int __cdecl __ismbblead(uint arg_1);
int __cdecl __ismbbtrail(uint arg_1);
int __cdecl __ismbbkana(uint arg_1);
undefined4 __cdecl x_ismbbtype(byte arg_1,uint arg_2,byte arg_3);
int __cdecl __setenvp(void);
int __cdecl __setargv(void);
void __cdecl parse_cmdline(byte *ptr_1,undefined4 *ptr_2,byte *ptr_3,int *ptr_4,int *ptr_5);
LPVOID __cdecl ___crtGetEnvironmentStringsW(void);
LPVOID __cdecl ___crtGetEnvironmentStringsA(void);
int __cdecl __setmbcp(int arg_1);
UINT __cdecl getSystemCP(UINT arg_1);
undefined4 __cdecl _CPtoLCID(undefined4 arg_1);
void __cdecl setSBCS(void);
undefined4 FUN_00402ac0(void);
void ___initmbctable(void);
int __cdecl __ioinit(void);
void __cdecl __ioterm(void);
int __cdecl __heap_init(void);
void __cdecl __heap_term(void);
void FUN_00403025(int arg_1);
void __cdecl __FF_MSGBANNER(void);
void __cdecl __NMSG_WRITE(int arg_1);
wchar_t * __cdecl __GET_RTERRMSG(int arg_1);
void * __cdecl _malloc(size_t arg_1);
void __cdecl __malloc_dbg(uint x,uint y,int width,undefined4 height);
void * __cdecl __nh_malloc(size_t arg_1,int arg_2);
undefined4 * __cdecl __nh_malloc_dbg(uint arg_1,int arg_2,uint arg_3,int arg_4,undefined4 arg_5);
void * __cdecl __heap_alloc(size_t arg_1);
undefined4 * __cdecl __heap_alloc_dbg(uint x,uint y,int width,undefined4 height);
void * __cdecl _calloc(size_t arg_1,size_t arg_2);
undefined1 * __cdecl __calloc_dbg(int arg_1,int arg_2,uint arg_3,int arg_4,undefined4 arg_5);
void * __cdecl FID_conflict:__expand(void *ptr_1,size_t arg_2);
int * __cdecl __realloc_dbg(void *ptr_1,uint arg_2,uint arg_3,int arg_4,int arg_5);
int * __cdecl realloc_help(void *ptr_1,uint arg_2,uint arg_3,int arg_4,int arg_5,int arg_6);
void * __cdecl FID_conflict:__expand(void *ptr_1,size_t arg_2);
int * __cdecl __expand_dbg(void *ptr_1,uint arg_2,uint arg_3,int arg_4,int arg_5);
void __cdecl FUN_00403ec0(void *ptr_1);
void __cdecl __free_dbg(void *ptr_1,int arg_2);
size_t __cdecl __msize(void *ptr_1);
undefined4 __cdecl __msize_dbg(int arg1,int arg2);
undefined4 __cdecl FUN_004044a0(undefined4 arg_1);
void __cdecl __CrtSetDbgBlockType(int arg1,undefined4 arg2);
undefined * __cdecl FUN_00404570(undefined *ptr_1);
undefined4 __cdecl _CheckBytes(char *str_1,char arg_2,int arg_3);
undefined4 __CrtCheckMemory(void);
int __cdecl __CrtSetDbgFlag(int arg_1);
void __cdecl __CrtDoForAllClientObjects(undefined *ptr_1,undefined4 arg_2);
undefined4 __cdecl __CrtIsValidPointer(void *ptr_1,UINT_PTR arg_2,int arg_3);
BOOL __cdecl __CrtIsValidHeapPointer(int arg_1);
undefined4 __cdecl __CrtIsMemoryBlock(void *ptr_1,UINT_PTR arg_2,undefined4 *ptr_3,undefined4 *ptr_4,undefined4 *ptr_5);
undefined4 __cdecl FUN_00404c80(undefined4 arg_1);
void __cdecl __CrtMemCheckpoint(undefined4 *ptr_1);
undefined4 __cdecl __CrtMemDifference(undefined4 *ptr_1,int arg_2,int arg_3);
void __cdecl __CrtMemDumpAllObjectsSince(undefined4 *ptr_1);
void __cdecl __printMemBlockData(int arg_1);
undefined4 __CrtDumpMemoryLeaks(void);
void __cdecl __CrtMemDumpStatistics(int arg_1);
uint * __cdecl FUN_00405450(uint *ptr_1,uint *ptr_2);
uint * __cdecl FUN_00405460(uint *ptr_1,uint *ptr_2);
size_t __cdecl _strlen(char *str_1);
size_t __cdecl _wcslen(wchar_t *str_1);
void * __cdecl FID_conflict:_memcpy(void *ptr_1,void *ptr_2,size_t arg_3);
undefined4 FUN_00405760(void);
bool __cdecl __set_sbh_threshold(int arg_1);
undefined ** ___sbh_new_region(void);
void __cdecl ___sbh_release_region(undefined **ptr_1);
void __cdecl ___sbh_decommit_pages(int arg_1);
int __cdecl ___sbh_find_block(undefined *ptr_1,undefined4 *ptr_2,uint *ptr_3);
void __cdecl ___sbh_free_block(int arg_1,int arg_2,char *str_3);
undefined * __cdecl ___sbh_alloc_block(uint arg_1);
int __cdecl ___sbh_alloc_block_from_page(int *ptr_1,uint arg_2,uint arg_3);
undefined4 __cdecl ___sbh_resize_block(int x,undefined4 *y,byte *width,uint height);
undefined4 ___sbh_heap_check(void);
int __cdecl ___crtMessageBoxA(LPCSTR arg_1,LPCSTR arg_2,UINT arg_3);
char * __cdecl _strncpy(char *str_1,char *str_2,size_t arg_3);
void __CrtDbgBreak(void);
undefined4 __cdecl __CrtSetReportMode(int arg1,uint arg2);
undefined4 __cdecl __CrtSetReportFile(int arg1,int arg2);
undefined4 __cdecl FUN_00406c60(undefined4 arg_1);
undefined4 __cdecl __CrtDbgReport(int arg_1,int arg_2,int arg_3,undefined4 arg_4,char *str_5);
bool _CrtMessageWindow(void);
undefined4 __cdecl FUN_004073b0(undefined4 arg_1);
undefined4 FUN_004073e0(void);
int __cdecl __callnewh(size_t arg_1);
void * __cdecl _memset(void *ptr_1,int arg_2,size_t arg_3);
void __cdecl __malloc_base(uint arg_1);
undefined * __cdecl __nh_malloc_base(uint arg1,int arg2);
undefined * __cdecl __heap_alloc_base(int arg_1);
undefined4 FUN_004075e0(void);
undefined * __cdecl __expand_base(undefined *ptr_1,uint arg_2);
undefined * __cdecl __realloc_base(undefined *ptr_1,uint arg_2);
void __cdecl __free_base(undefined *ptr_1);
int __cdecl __heapchk(void);
int __cdecl __heapset(uint arg_1);
int __cdecl _sprintf(char *str_1,char *str_2,...);
int __cdecl __isctype(int arg1,int arg2);
char * __cdecl __itoa(int arg_1,char *str_2,int arg_3);
void __cdecl xtoa(uint x,char *y,uint width,int height);
char * __cdecl __ltoa(long arg_1,char *str_2,int arg_3);
char * __cdecl __ultoa(ulong arg_1,char *str_2,int arg_3);
char * __cdecl __i64toa(longlong arg_1,char *str_2,int arg_3);
void x64toa(undefined8 x,char *y,uint width,int height);
char * __cdecl __ui64toa(ulonglong arg_1,char *str_2,int arg_3);
int __cdecl __snprintf(char *str_1,size_t arg_2,char *str_3,...);
int __cdecl __vsnprintf(char *str_1,size_t arg_2,char *str_3,va_list arg_4);
void FUN_004080b0(void);
void __cdecl _signal(int arg_1);
undefined4 ctrlevent_capture(int arg_1);
int __cdecl _raise(int arg_1);
undefined4 * __cdecl siglookup(int arg_1);
int __cdecl __flsbuf(int arg1,FILE *arg2);
int __cdecl __output(FILE *fp,byte *ptr_2,undefined4 *ptr_3);
void __cdecl write_char(int arg_1,FILE *fp,int *ptr_3);
void __cdecl write_multi_char(int x,int y,FILE *width,int *height);
void __cdecl write_string(char *x,int y,FILE *width,int *height);
undefined4 __cdecl get_int_arg(int *ptr_1);
undefined8 __cdecl get_int64_arg(int *ptr_1);
undefined4 __cdecl get_short_arg(int *ptr_1);
void __cdecl ___crtGetStringTypeW(DWORD arg_1,LPCWSTR arg_2,int arg_3,LPWORD arg_4,UINT arg_5,LCID arg_6);
BOOL __cdecl ___crtGetStringTypeA(_locale_t arg_1,DWORD arg_2,LPCSTR arg_3,int arg_4,LPWORD arg_5,int arg_6,BOOL arg_7);
undefined8 __aulldiv(uint x,uint y,uint width,uint height);
undefined8 __aullrem(uint x,uint y,uint width,uint height);
int __cdecl __write(int arg_1,void *ptr_2,uint arg_3);
long __cdecl __lseek(int arg_1,long arg_2,int arg_3);
void __cdecl __getbuf(FILE *fp);
int __cdecl __isatty(int arg_1);
void ___initstdio(void);
void ___endstdio(void);
int __cdecl _wctomb(char *str_1,wchar_t arg_2);
void * __cdecl FID_conflict:_memcpy(void *ptr_1,void *ptr_2,size_t arg_3);
void __cdecl __dosmaperr(ulong arg_1);
int __cdecl __alloc_osfhnd(void);
int __cdecl __set_osfhnd(int arg1,intptr_t arg2);
int __cdecl __free_osfhnd(int arg_1);
intptr_t __cdecl __get_osfhandle(int arg_1);
int __cdecl __open_osfhandle(intptr_t arg1,int arg2);
int __cdecl __fcloseall(void);
int __cdecl _fflush(FILE *fp);
int __cdecl __flush(FILE *fp);
int __cdecl __flushall(void);
int __cdecl flsall(int arg_1);
void __cdecl __fptrap(void);
int __cdecl _fclose(FILE *fp);
int __cdecl __commit(int arg_1);
int __cdecl __close(int arg_1);
void __cdecl __freebuf(FILE *fp);
void RtlUnwind(PVOID arg_1,PVOID arg_2,PEXCEPTION_RECORD arg_3,PVOID arg_4);
int __cdecl __strnicmp(char *str_1,char *str_2,size_t arg_3);
int __cdecl FUN_0040b3b0(int arg_1);
int __cdecl _tolower(int arg_1);
int __cdecl ___crtLCMapStringW(LPCWSTR arg_1,DWORD arg_2,LPCWSTR arg_3,int arg_4,LPWSTR arg_5,int arg_6);
int __cdecl wcsncnt(short *ptr_1,int arg_2);
int __cdecl ___crtLCMapStringA(_locale_t arg_1,LPCWSTR arg_2,DWORD arg_3,LPCSTR arg_4,int arg_5,LPSTR arg_6,int arg_7,int arg_8,BOOL arg_9);
size_t __cdecl _strncnt(char *str_1,size_t arg_2);


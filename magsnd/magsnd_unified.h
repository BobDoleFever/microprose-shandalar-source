typedef unsigned char   undefined;

typedef unsigned char    byte;
typedef unsigned int    dword;
typedef pointer32 ImageBaseOffset32;

typedef unsigned int    uint;
typedef unsigned long    ulong;
typedef unsigned short    undefined2;
typedef unsigned int    undefined4;
typedef unsigned long long    undefined8;
typedef unsigned short    ushort;
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

typedef struct _RTL_CRITICAL_SECTION _RTL_CRITICAL_SECTION, *P_RTL_CRITICAL_SECTION;

typedef struct _RTL_CRITICAL_SECTION *PRTL_CRITICAL_SECTION;

typedef PRTL_CRITICAL_SECTION LPCRITICAL_SECTION;

typedef struct _RTL_CRITICAL_SECTION_DEBUG _RTL_CRITICAL_SECTION_DEBUG, *P_RTL_CRITICAL_SECTION_DEBUG;

typedef struct _RTL_CRITICAL_SECTION_DEBUG *PRTL_CRITICAL_SECTION_DEBUG;

typedef long LONG;

typedef void *HANDLE;

typedef ulong ULONG_PTR;

typedef ushort WORD;

typedef struct _LIST_ENTRY _LIST_ENTRY, *P_LIST_ENTRY;

typedef struct _LIST_ENTRY LIST_ENTRY;

typedef ulong DWORD;

struct _RTL_CRITICAL_SECTION {
    PRTL_CRITICAL_SECTION_DEBUG DebugInfo;
    LONG LockCount;
    LONG RecursionCount;
    HANDLE OwningThread;
    HANDLE LockSemaphore;
    ULONG_PTR SpinCount;
};

struct _LIST_ENTRY {
    struct _LIST_ENTRY *Flink;
    struct _LIST_ENTRY *Blink;
};

struct _RTL_CRITICAL_SECTION_DEBUG {
    WORD Type;
    WORD CreatorBackTraceIndex;
    struct _RTL_CRITICAL_SECTION *CriticalSection;
    LIST_ENTRY ProcessLocksList;
    DWORD EntryCount;
    DWORD ContentionCount;
    DWORD Flags;
    WORD CreatorBackTraceIndexHigh;
    WORD SpareWORD;
};

typedef char CHAR;

typedef CHAR *LPSTR;

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

typedef ULONG_PTR DWORD_PTR;

typedef ULONG_PTR SIZE_T;

typedef uint UINT_PTR;

typedef long LONG_PTR;

typedef UINT_PTR WPARAM;

typedef struct HTASK__ HTASK__, *PHTASK__;

typedef struct HTASK__ *HTASK;

struct HTASK__ {
    int unused;
};

typedef LONG_PTR LRESULT;

typedef struct HINSTANCE__ HINSTANCE__, *PHINSTANCE__;

struct HINSTANCE__ {
    int unused;
};

typedef LONG_PTR LPARAM;

typedef HANDLE HGLOBAL;

typedef struct HINSTANCE__ *HINSTANCE;

typedef struct HWND__ HWND__, *PHWND__;

typedef struct HWND__ *HWND;

struct HWND__ {
    int unused;
};

typedef HINSTANCE HMODULE;

typedef int BOOL;

typedef uint UINT;

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

typedef struct IMAGE_DIRECTORY_ENTRY_EXPORT IMAGE_DIRECTORY_ENTRY_EXPORT, *PIMAGE_DIRECTORY_ENTRY_EXPORT;

struct IMAGE_DIRECTORY_ENTRY_EXPORT {
    dword Characteristics;
    dword TimeDateStamp;
    word MajorVersion;
    word MinorVersion;
    ImageBaseOffset32 Name;
    dword Base;
    dword NumberOfFunctions;
    dword NumberOfNames;
    ImageBaseOffset32 AddressOfFunctions;
    ImageBaseOffset32 AddressOfNames;
    ImageBaseOffset32 AddressOfNameOrdinals;
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

typedef struct timecaps_tag timecaps_tag, *Ptimecaps_tag;

struct timecaps_tag {
    UINT wPeriodMin;
    UINT wPeriodMax;
};

typedef struct _MMIOINFO _MMIOINFO, *P_MMIOINFO;

typedef struct _MMIOINFO MMIOINFO;

typedef DWORD FOURCC;

typedef LRESULT (MMIOPROC)(LPSTR, UINT, LPARAM, LPARAM);

typedef MMIOPROC *LPMMIOPROC;

typedef char *HPSTR;

typedef struct HMMIO__ HMMIO__, *PHMMIO__;

typedef struct HMMIO__ *HMMIO;

struct HMMIO__ {
    int unused;
};

struct _MMIOINFO {
    DWORD dwFlags;
    FOURCC fccIOProc;
    LPMMIOPROC pIOProc;
    UINT wErrorRet;
    HTASK htask;
    LONG cchBuffer;
    HPSTR pchBuffer;
    HPSTR pchNext;
    HPSTR pchEndRead;
    HPSTR pchEndWrite;
    LONG lBufOffset;
    LONG lDiskOffset;
    DWORD adwInfo[3];
    DWORD dwReserved1;
    DWORD dwReserved2;
    HMMIO hmmio;
};

typedef void (TIMECALLBACK)(UINT, UINT, DWORD_PTR, DWORD_PTR, DWORD_PTR);

typedef TIMECALLBACK *LPTIMECALLBACK;

typedef struct _MMCKINFO _MMCKINFO, *P_MMCKINFO;

typedef struct _MMCKINFO MMCKINFO;

struct _MMCKINFO {
    FOURCC ckid;
    DWORD cksize;
    FOURCC fccType;
    DWORD dwDataOffset;
    DWORD dwFlags;
};

typedef struct timecaps_tag *LPTIMECAPS;

typedef struct _MMIOINFO *LPMMIOINFO;

typedef UINT MMRESULT;

typedef struct _MMCKINFO *LPMMCKINFO;

typedef MMIOINFO *LPCMMIOINFO;

typedef int (*_onexit_t)(void);

typedef uint size_t;




void __cdecl thunk_FUN_10005a46(undefined4 *ptr_1);
void __cdecl thunk_FUN_1000460c(int arg_1);
undefined4 __cdecl thunk_FUN_1000667b(undefined4 arg_1,int *ptr_2);
void __cdecl thunk_FUN_1000458d(int arg_1);
int __cdecl SetSndMarker(int arg1,uint arg2);
undefined4 __cdecl GetSndState(int arg1,undefined4 *arg2);
undefined4 __cdecl PlaySnd(int arg1,int *arg2);
int __cdecl thunk_FUN_1000394f(undefined4 *ptr_1);
undefined4 UnloadAllSnds(void);
int __cdecl thunk_FUN_1000219c(int arg1,int arg2);
undefined4 __cdecl GetAVISndBuff(int arg1,uint arg2);
undefined4 __cdecl ReleaseAVISndBuff(int arg_1);
void StopAllSnds(void);
undefined4 ResetSnd(void);
undefined4 __cdecl GetLRUSnd(int *ptr_1,int arg_2,int arg_3);
undefined4 __cdecl thunk_FUN_10002900(int arg_1);
undefined4 __cdecl InitSnd(int arg_1,undefined4 arg_2,byte arg_3);
undefined4 __cdecl SetVol(int arg1,uint arg2);
void __cdecl thunk_FUN_10004534(int arg_1);
undefined4 __cdecl GetSndTime(int arg1,uint *arg2);
undefined4 __cdecl thunk_FUN_1000630c(undefined4 *ptr_1);
void __cdecl thunk_FUN_10006830(undefined4 *ptr_1,undefined4 arg_2);
undefined4 thunk_FUN_100046fb(void);
undefined4 thunk_FUN_1000681e(void);
undefined4 PlayMidiFile(void);
int __cdecl PlaySndMarker(int arg1,uint arg2);
undefined4 __cdecl thunk_FUN_10005abe(FILE *fp,int *ptr_2);
undefined4 GetSndHWND(void);
undefined4 __cdecl thunk_FUN_1000405a(undefined4 *ptr_1);
undefined4 __cdecl thunk_FUN_10006622(void *ptr_1);
undefined4 __cdecl thunk_FUN_10005d4a(int arg1,int arg2);
undefined4 GetPitch(void);
void thunk_FUN_10004788(void);
int __cdecl PlaySndFile(LPSTR arg_1,int arg_2,int *ptr_3);
undefined4 GetVol(void);
int __cdecl thunk_FUN_10006e80(int arg_1);
void __cdecl thunk_FUN_10003a41(int arg_1);
void * __cdecl thunk_FUN_10006540(int *ptr_1,undefined4 arg_2,undefined4 *ptr_3,undefined4 arg_4);
int __cdecl thunk_FUN_1000207f(undefined4 *ptr_1,int arg_2);
undefined4 __cdecl UnloadSnd(int arg_1);
undefined4 __cdecl IsSndLoaded(int arg1,undefined4 *arg2);
undefined4 __cdecl StopSnd(int arg_1);
int __cdecl thunk_FUN_1000192c(undefined4 *ptr_1,int *ptr_2);
undefined4 __cdecl SetPan(int arg1,int arg2);
undefined4 __cdecl thunk_FUN_100055b0(char *str_1,int *ptr_2);
undefined4 __cdecl SetPitch(int arg1,undefined4 arg2);
undefined4 __cdecl thunk_FUN_10005f0c(undefined4 *ptr_1,int arg_2);
undefined4 UpdateSnd(void);
undefined4 __cdecl thunk_FUN_1000560f(LPSTR arg_1,int *ptr_2);
undefined4 __cdecl thunk_FUN_100043c4(int arg1,int *arg2);
undefined4 __cdecl thunk_FUN_10005dff(FILE *x,int y,long width,uint height);
void ReleaseSnd(void);
int __cdecl LoadSnd(LPSTR arg_1,int arg_2,int arg_3);
void __cdecl thunk_FUN_10004665(int arg_1);
undefined4 GetPan(void);
undefined4 __cdecl Sound_DirectSoundInit(int arg_1,undefined4 arg_2,byte arg_3);
void Sound_DirectSoundShutdown(void);
undefined4 FUN_10001428(void);
int __cdecl FUN_1000143d(LPSTR arg_1,int arg_2,int arg_3);
undefined4 __cdecl Sound_LockAudioBuffer(int arg_1);
undefined4 Sound_UnlockAudioBuffer(void);
undefined4 __cdecl Sound_SetChannelVolume(int arg1,int *arg2);
int __cdecl Sound_UnloadSample(undefined4 *ptr_1,int *ptr_2);
int __cdecl Sound_SetChannelPanning(LPSTR arg_1,int arg_2,int *ptr_3);
int __cdecl FUN_1000207f(undefined4 *ptr_1,int arg_2);
int __cdecl FUN_1000219c(int arg1,int arg2);
void __cdecl FUN_100022b9(int *ptr_1,int *ptr_2);
int __cdecl Sound_PlayWaveSample(int arg1,uint arg2);
int __cdecl Sound_StopWaveSample(int arg1,uint arg2);
undefined4 __cdecl Sound_GetChannelStatus(int arg_1);
void Sound_SetMasterVolume(void);
undefined4 __cdecl FUN_10002900(int arg_1);
undefined4 FUN_10002b3c(void);
undefined4 __cdecl FUN_10002b4e(int arg1,undefined4 arg2);
undefined4 FUN_10002c54(void);
undefined4 __cdecl FUN_10002c66(int arg1,uint arg2);
undefined4 FUN_10002e62(void);
undefined4 __cdecl FUN_10002e74(int arg1,int arg2);
undefined4 FUN_10002f85(void);
undefined4 FUN_10002f97(void);
undefined4 __cdecl FUN_100030e6(int arg1,uint *arg2);
undefined4 __cdecl FUN_1000337e(int arg1,undefined4 *arg2);
undefined4 FUN_1000343e(void);
undefined4 __cdecl FUN_10003450(int arg1,undefined4 *arg2);
undefined4 __cdecl FUN_100034de(int *ptr_1,int arg_2,int arg_3);
undefined4 __cdecl FUN_100035d3(int arg1,uint arg2);
undefined4 __cdecl FUN_100037be(int arg_1);
int __cdecl FUN_1000394f(undefined4 *ptr_1);
void __cdecl FUN_10003a41(int arg_1);
undefined4 __cdecl FUN_1000405a(undefined4 *ptr_1);
undefined4 __cdecl FUN_100043c4(int arg1,int *arg2);
void __cdecl FUN_10004534(int arg_1);
void __cdecl FUN_1000458d(int arg_1);
void __cdecl FUN_1000460c(int arg_1);
void __cdecl FUN_10004665(int arg_1);
void FUN_100046e4(void);
undefined4 FUN_100046fb(void);
void FUN_10004788(void);
undefined4 __cdecl FUN_100055b0(char *str_1,int *ptr_2);
undefined4 __cdecl FUN_1000560f(LPSTR arg_1,int *ptr_2);
void __cdecl FUN_10005a46(undefined4 *ptr_1);
undefined4 __cdecl FUN_10005abe(FILE *fp,int *ptr_2);
undefined4 __cdecl FUN_10005d4a(int arg1,int arg2);
undefined4 __cdecl FUN_10005dff(FILE *x,int y,long width,uint height);
undefined4 __cdecl FUN_10005f0c(undefined4 *ptr_1,int arg_2);
undefined4 __cdecl FUN_1000630c(undefined4 *ptr_1);
void * __cdecl FUN_10006540(int *ptr_1,undefined4 arg_2,undefined4 *ptr_3,undefined4 arg_4);
undefined4 __cdecl FUN_10006622(void *ptr_1);
undefined4 __cdecl FUN_1000667b(undefined4 arg_1,int *ptr_2);
undefined4 FUN_1000681e(void);
void __cdecl FUN_10006830(undefined4 *ptr_1,undefined4 arg_2);
int __cdecl FUN_10006e80(int arg_1);
void AVIStreamRead(void);
void AVIStreamReadFormat(void);
void AVIStreamInfoA(void);
void DirectSoundCreate(void);
void __cdecl ftol(void);
void * __cdecl memset(void *ptr_1,int arg_2,size_t arg_3);
void __cdecl operator_delete(void *ptr_1);
void * __cdecl operator_new(uint arg_1);
char * __cdecl strcpy(char *str_1,char *str_2);
size_t __cdecl strlen(char *str_1);
undefined4 __CRT_INIT@12(undefined4 arg_1,int arg_2);
int entry(HMODULE arg_1,int arg_2,undefined4 arg_3);
_onexit_t __cdecl __onexit(_onexit_t arg_1);
int __cdecl _atexit(_func_4879 *ptr_1);
void __cdecl initterm(void);
undefined4 _DllMain@12(HMODULE arg_1,int arg_2);
void __dllonexit(void);


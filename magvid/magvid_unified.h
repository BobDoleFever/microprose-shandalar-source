typedef unsigned char   undefined;

typedef unsigned char    bool;
typedef unsigned char    byte;
typedef unsigned int    dword;
typedef pointer32 ImageBaseOffset32;

typedef unsigned char    uchar;
typedef unsigned int    uint;
typedef unsigned long    ulong;
typedef unsigned char    undefined1;
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

typedef struct _SECURITY_ATTRIBUTES _SECURITY_ATTRIBUTES, *P_SECURITY_ATTRIBUTES;

typedef ulong DWORD;

typedef void *LPVOID;

typedef int BOOL;

struct _SECURITY_ATTRIBUTES {
    DWORD nLength;
    LPVOID lpSecurityDescriptor;
    BOOL bInheritHandle;
};

typedef struct _OVERLAPPED _OVERLAPPED, *P_OVERLAPPED;

typedef ulong ULONG_PTR;

typedef union _union_518 _union_518, *P_union_518;

typedef void *HANDLE;

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

typedef struct _RTL_CRITICAL_SECTION _RTL_CRITICAL_SECTION, *P_RTL_CRITICAL_SECTION;

typedef struct _RTL_CRITICAL_SECTION *PRTL_CRITICAL_SECTION;

typedef PRTL_CRITICAL_SECTION LPCRITICAL_SECTION;

typedef struct _RTL_CRITICAL_SECTION_DEBUG _RTL_CRITICAL_SECTION_DEBUG, *P_RTL_CRITICAL_SECTION_DEBUG;

typedef struct _RTL_CRITICAL_SECTION_DEBUG *PRTL_CRITICAL_SECTION_DEBUG;

typedef long LONG;

typedef ushort WORD;

typedef struct _LIST_ENTRY _LIST_ENTRY, *P_LIST_ENTRY;

typedef struct _LIST_ENTRY LIST_ENTRY;

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

typedef DWORD (*PTHREAD_START_ROUTINE)(LPVOID);

typedef PTHREAD_START_ROUTINE LPTHREAD_START_ROUTINE;

typedef struct _OVERLAPPED *LPOVERLAPPED;

typedef struct _SECURITY_ATTRIBUTES *LPSECURITY_ATTRIBUTES;

typedef char *va_list;

typedef struct tagOFNA tagOFNA, *PtagOFNA;

typedef struct tagOFNA *LPOPENFILENAMEA;

typedef struct HWND__ HWND__, *PHWND__;

typedef struct HWND__ *HWND;

typedef struct HINSTANCE__ HINSTANCE__, *PHINSTANCE__;

typedef struct HINSTANCE__ *HINSTANCE;

typedef char CHAR;

typedef CHAR *LPCSTR;

typedef CHAR *LPSTR;

typedef long LONG_PTR;

typedef LONG_PTR LPARAM;

typedef uint UINT_PTR;

typedef uint UINT;

typedef UINT_PTR WPARAM;

typedef UINT_PTR (*LPOFNHOOKPROC)(HWND, UINT, WPARAM, LPARAM);

struct tagOFNA {
    DWORD lStructSize;
    HWND hwndOwner;
    HINSTANCE hInstance;
    LPCSTR lpstrFilter;
    LPSTR lpstrCustomFilter;
    DWORD nMaxCustFilter;
    DWORD nFilterIndex;
    LPSTR lpstrFile;
    DWORD nMaxFile;
    LPSTR lpstrFileTitle;
    DWORD nMaxFileTitle;
    LPCSTR lpstrInitialDir;
    LPCSTR lpstrTitle;
    DWORD Flags;
    WORD nFileOffset;
    WORD nFileExtension;
    LPCSTR lpstrDefExt;
    LPARAM lCustData;
    LPOFNHOOKPROC lpfnHook;
    LPCSTR lpTemplateName;
    void *pvReserved;
    DWORD dwReserved;
    DWORD FlagsEx;
};

struct HINSTANCE__ {
    int unused;
};

struct HWND__ {
    int unused;
};

typedef uint size_t;

typedef struct tagPAINTSTRUCT tagPAINTSTRUCT, *PtagPAINTSTRUCT;

typedef struct tagPAINTSTRUCT PAINTSTRUCT;

typedef struct HDC__ HDC__, *PHDC__;

typedef struct HDC__ *HDC;

typedef struct tagRECT tagRECT, *PtagRECT;

typedef struct tagRECT RECT;

typedef uchar BYTE;

struct HDC__ {
    int unused;
};

struct tagRECT {
    LONG left;
    LONG top;
    LONG right;
    LONG bottom;
};

struct tagPAINTSTRUCT {
    HDC hdc;
    BOOL fErase;
    RECT rcPaint;
    BOOL fRestore;
    BOOL fIncUpdate;
    BYTE rgbReserved[32];
};

typedef struct tagWNDCLASSA tagWNDCLASSA, *PtagWNDCLASSA;

typedef LONG_PTR LRESULT;

typedef LRESULT (*WNDPROC)(HWND, UINT, WPARAM, LPARAM);

typedef struct HICON__ HICON__, *PHICON__;

typedef struct HICON__ *HICON;

typedef HICON HCURSOR;

typedef struct HBRUSH__ HBRUSH__, *PHBRUSH__;

typedef struct HBRUSH__ *HBRUSH;

struct HBRUSH__ {
    int unused;
};

struct tagWNDCLASSA {
    UINT style;
    WNDPROC lpfnWndProc;
    int cbClsExtra;
    int cbWndExtra;
    HINSTANCE hInstance;
    HICON hIcon;
    HCURSOR hCursor;
    HBRUSH hbrBackground;
    LPCSTR lpszMenuName;
    LPCSTR lpszClassName;
};

struct HICON__ {
    int unused;
};

typedef struct tagWNDCLASSA WNDCLASSA;

typedef struct tagPAINTSTRUCT *LPPAINTSTRUCT;

typedef struct tagPALETTEENTRY tagPALETTEENTRY, *PtagPALETTEENTRY;

typedef struct tagPALETTEENTRY *LPPALETTEENTRY;

struct tagPALETTEENTRY {
    BYTE peRed;
    BYTE peGreen;
    BYTE peBlue;
    BYTE peFlags;
};

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

typedef struct HPALETTE__ HPALETTE__, *PHPALETTE__;

struct HPALETTE__ {
    int unused;
};

typedef HINSTANCE HMODULE;

typedef HANDLE HLOCAL;

typedef int (*FARPROC)(void);

typedef WORD ATOM;

typedef struct tagRECT *LPRECT;

typedef void *HGDIOBJ;

typedef DWORD COLORREF;

typedef struct tagPOINT tagPOINT, *PtagPOINT;

struct tagPOINT {
    LONG x;
    LONG y;
};

typedef DWORD *LPDWORD;

typedef struct HPALETTE__ *HPALETTE;

typedef struct HTASK__ HTASK__, *PHTASK__;

struct HTASK__ {
    int unused;
};

typedef struct HMENU__ HMENU__, *PHMENU__;

typedef struct HMENU__ *HMENU;

struct HMENU__ {
    int unused;
};

typedef struct HTASK__ *HTASK;

typedef int HFILE;

typedef HANDLE HGLOBAL;

typedef void *LPCVOID;

typedef struct tagPOINT POINT;

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

typedef struct timecaps_tag timecaps_tag, *Ptimecaps_tag;

struct timecaps_tag {
    UINT wPeriodMin;
    UINT wPeriodMax;
};

typedef struct wavehdr_tag wavehdr_tag, *Pwavehdr_tag;

typedef struct wavehdr_tag *LPWAVEHDR;

struct wavehdr_tag {
    LPSTR lpData;
    DWORD dwBufferLength;
    DWORD dwBytesRecorded;
    DWORD_PTR dwUser;
    DWORD dwFlags;
    DWORD dwLoops;
    struct wavehdr_tag *lpNext;
    DWORD_PTR reserved;
};

typedef struct HMMIO__ HMMIO__, *PHMMIO__;

typedef struct HMMIO__ *HMMIO;

struct HMMIO__ {
    int unused;
};

typedef char *HPSTR;

typedef LRESULT (MMIOPROC)(LPSTR, UINT, LPARAM, LPARAM);

typedef struct HWAVEOUT__ HWAVEOUT__, *PHWAVEOUT__;

typedef struct HWAVEOUT__ *HWAVEOUT;

struct HWAVEOUT__ {
    int unused;
};

typedef MMIOPROC *LPMMIOPROC;

typedef struct _MMCKINFO _MMCKINFO, *P_MMCKINFO;

typedef struct _MMCKINFO MMCKINFO;

typedef DWORD FOURCC;

struct _MMCKINFO {
    FOURCC ckid;
    DWORD cksize;
    FOURCC fccType;
    DWORD dwDataOffset;
    DWORD dwFlags;
};

typedef struct timecaps_tag *LPTIMECAPS;

typedef struct _MMIOINFO _MMIOINFO, *P_MMIOINFO;

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

typedef struct _MMIOINFO *LPMMIOINFO;

typedef UINT MMRESULT;

typedef struct _MMCKINFO *LPMMCKINFO;

typedef struct CFontDialog CFontDialog, *PCFontDialog;

struct CFontDialog { /* PlaceHolder Structure */
};

typedef struct CPrintPreviewState CPrintPreviewState, *PCPrintPreviewState;

struct CPrintPreviewState { /* PlaceHolder Structure */
};

typedef struct CArchive CArchive, *PCArchive;

struct CArchive { /* PlaceHolder Structure */
};

typedef int (*_onexit_t)(void);




void __thiscall thunk_FUN_100086b0(void *this,undefined4 arg_2,undefined4 arg_3,undefined4 arg_4,undefined4 arg_5);
undefined4 __thiscall thunk_FUN_10007eaf(void *this,undefined4 arg_2);
undefined4 __thiscall thunk_FUN_1000b685(void *this,int *ptr_2);
undefined4 __fastcall thunk_FUN_1000ae35(undefined4 *ptr_1);
undefined4 __thiscall thunk_FUN_100089e8(void *this,int *ptr_2,undefined4 arg_3);
undefined4 __cdecl thunk_FUN_10004249(int arg1,int *arg2);
int __thiscall thunk_FUN_100095cf(void *this,int arg_2,int arg_3);
undefined4 __thiscall thunk_FUN_10002289(void *this,int arg_2);
void __thiscall thunk_FUN_10007bde(void *this,int arg_2);
int __thiscall thunk_FUN_10001a02(void *this,int arg_2,int arg_3);
undefined4 __fastcall thunk_FUN_10007bff(undefined4 *ptr_1);
undefined4 thunk_FUN_1000286a(undefined4 arg_1,undefined4 arg_2);
void __fastcall thunk_FUN_100027a0(int arg_1);
undefined4 __fastcall thunk_FUN_10001d28(undefined4 *ptr_1);
undefined4 __cdecl thunk_FUN_10004f02(undefined4 arg_1,undefined4 arg_2);
uint __fastcall thunk_FUN_1000a200(int arg_1);
void __thiscall thunk_FUN_10008600(void *this,undefined4 arg_2,undefined4 arg_3,undefined4 arg_4,undefined4 arg_5);
void __thiscall thunk_FUN_10008660(void *this,char *str_2);
bool __thiscall thunk_FUN_1000b99f(void *this,int arg_2);
undefined4 thunk_FUN_1000735d(void);
undefined4 __fastcall thunk_FUN_1000acaf(undefined4 *ptr_1);
void __fastcall thunk_FUN_1000a2f1(int *ptr_1);
void __cdecl thunk_FUN_10005c78(int arg1,int arg2);
undefined4 __cdecl PaintVid(int arg_1);
undefined4 __fastcall thunk_FUN_1000a795(int *ptr_1);
void __fastcall thunk_FUN_10001926(int *ptr_1);
undefined4 __fastcall thunk_FUN_10007c85(int *ptr_1);
void __thiscall thunk_FUN_1000b633(void *this,int *ptr_2);
int __cdecl thunk_FUN_10004c90(int arg_1,undefined4 arg_2,uint arg_3);
DWORD __thiscall thunk_FUN_1000af14(void *this,undefined4 arg_2,undefined4 arg_3);
void thunk_FUN_100054bc(void);
undefined4 __cdecl thunk_FUN_100052e9(undefined4 arg_1,undefined4 arg_2);
undefined2 __fastcall thunk_FUN_1000a130(int arg_1);
void __fastcall thunk_FUN_10004c60(int arg_1);
undefined4 __cdecl thunk_FUN_10005a5b(LPARAM *ptr_1,LPCSTR arg_2);
int __thiscall CFontDialog::GetWeight(CFontDialog *this);
void __cdecl thunk_FUN_10005ce8(int arg1,int arg2);
undefined4 __cdecl SetVidPos(int arg1,short *arg2);
int __thiscall thunk_FUN_1000743e(void *this,int arg_2);
undefined4 __cdecl SetVidBackground(int arg1,int arg2);
undefined4 * __fastcall thunk_FUN_1000a250(undefined4 *ptr_1);
void thunk_FUN_10005fee(void);
void __cdecl thunk_FUN_10005b92(LPARAM *ptr_1);
undefined4 __cdecl UnloadAVI(int arg_1);
bool __thiscall thunk_FUN_1000bd47(void *this,int arg_2);
undefined4 __thiscall thunk_FUN_1000bc86(void *this,int *ptr_2);
void __thiscall thunk_FUN_1000b54e(void *this,int *ptr_2);
undefined4 __fastcall thunk_FUN_1000aea5(undefined4 *ptr_1);
undefined4 __fastcall thunk_FUN_100019c7(int arg_1);
void __thiscall thunk_FUN_1000b4fb(void *this,undefined4 *ptr_2);
undefined4 __cdecl LinkVids(int arg1,int arg2);
undefined4 __thiscall thunk_FUN_10001f9d(void *this,float arg_2,uint arg_3,int arg_4,int arg_5,int arg_6);
undefined4 __cdecl SetVidBackgroundToBMP(int *ptr_1,undefined4 arg_2,int arg_3);
int __thiscall thunk_FUN_1000a8d3(void *this,int arg_2);
int __thiscall CFontDialog::GetWeight(CFontDialog *this);
void __thiscall thunk_FUN_1000b6ff(void *this,void *ptr_2);
undefined4 thunk_FUN_100053fa(void);
void __fastcall thunk_FUN_1000a1b0(int arg_1);
undefined4 __fastcall thunk_FUN_10004bf0(int arg_1);
void __cdecl thunk_FUN_100059e8(int arg_1);
void __thiscall thunk_FUN_1000b3b1(void *this,undefined4 *ptr_2);
void __thiscall thunk_FUN_1000b786(void *this,void *ptr_2);
undefined4 __thiscall thunk_FUN_10007b00(void *this,int arg_2,int arg_3);
void __cdecl thunk_FUN_100063e6(int arg_1,int arg_2,int arg_3);
void __fastcall thunk_FUN_10008774(undefined4 *ptr_1);
void __thiscall thunk_FUN_1000b5e0(void *this,undefined4 *ptr_2);
undefined4 __thiscall thunk_FUN_1000bbec(void *this,int arg_2);
undefined4 __thiscall thunk_FUN_1000bac7(void *this,int *ptr_2);
undefined4 thunk_FUN_10007383(void);
undefined4 __fastcall thunk_FUN_1000785e(int *ptr_1);
undefined4 __cdecl thunk_FUN_100065fe(LPARAM *ptr_1,int arg_2);
undefined4 __cdecl thunk_FUN_100066d7(LPARAM *ptr_1);
void __thiscall thunk_FUN_1000b759(void *this,void *ptr_2);
int __fastcall thunk_FUN_10007080(int arg_1);
undefined4 __cdecl SetVidBackgroundToDIB(int *ptr_1,int arg_2);
void __thiscall thunk_FUN_1000a160(void *this,undefined4 arg_2);
undefined4 __fastcall thunk_FUN_1000715a(int arg_1);
undefined4 * __fastcall thunk_FUN_10001740(undefined4 *ptr_1);
void __cdecl thunk_FUN_10006a43(LPARAM *ptr_1);
void __thiscall thunk_FUN_100085b0(void *this,char *str_2);
undefined4 __cdecl SetVidForeground(int *ptr_1,int arg_2);
undefined4 __cdecl DrawVidBackground(int arg_1);
void __fastcall thunk_FUN_10008570(uint *ptr_1);
undefined4 __fastcall thunk_FUN_10004bc0(int arg_1);
int __thiscall thunk_FUN_1000b2fb(void *this,undefined4 arg_2,undefined4 arg_3);
undefined4 __fastcall thunk_FUN_1000761c(void *ptr_1);
undefined4 __thiscall thunk_FUN_1000a30f(void *this,int arg_2,void *ptr_3);
void __fastcall thunk_FUN_10008136(undefined4 *ptr_1);
int * __thiscall thunk_FUN_10008520(void *this,byte arg_2);
undefined4 __fastcall thunk_FUN_10001c16(int *ptr_1);
void __cdecl thunk_FUN_10005ef9(int arg_1);
undefined4 __cdecl SetVidCallBack(int arg1,undefined4 arg2);
undefined4 __cdecl SetVidTransparency(int arg1,int arg2);
undefined4 __fastcall thunk_FUN_10007238(int arg_1);
void __fastcall thunk_FUN_10007050(int arg_1);
bool __fastcall thunk_FUN_10004c20(int arg_1);
undefined4 InitVid(void);
undefined4 __thiscall thunk_FUN_10002227(void *this,int arg_2);
undefined4 __cdecl thunk_FUN_10004ea1(undefined4 arg_1);
undefined4 __cdecl thunk_FUN_10004f90(undefined4 arg_1);
undefined4 thunk_FUN_100073d1(void);
undefined4 __cdecl StopAVI(int arg_1);
undefined4 __cdecl PasteToVidBackground(int *x,short *y,int *width,int height);
undefined4 __cdecl LoadAVI(LPCSTR x,int *y,short *width,uint height);
int __thiscall CArchive::IsBufferEmpty(CArchive *this);
void __cdecl thunk_FUN_10005d8d(LPVOID arg_1);
int __thiscall thunk_FUN_1000b83e(void *this,int arg_2,int arg_3,int arg_4,int arg_5,int arg_6);
undefined4 __thiscall thunk_FUN_100023d1(void *this,int arg_2);
undefined4 thunk_FUN_100051e4(void);
undefined4 __cdecl thunk_FUN_10004e65(undefined4 arg_1,undefined4 arg_2,undefined4 arg_3);
undefined4 __thiscall thunk_FUN_10001c8e(void *this,int arg_2);
undefined4 * __thiscall thunk_FUN_10004b70(void *this,byte arg_2);
undefined4 __fastcall thunk_FUN_10007f71(undefined4 *ptr_1);
undefined4 __cdecl VidStatus(int arg_1);
void __fastcall thunk_FUN_10009348(int arg_1);
void __thiscall thunk_FUN_1000b456(void *this,undefined4 *ptr_2);
undefined4 __cdecl PlayAVI(int arg_1);
void thunk_FUN_10004def(void);
undefined4 __fastcall thunk_FUN_10007a85(int *ptr_1);
int * __thiscall thunk_FUN_10004b20(void *this,byte arg_2);
void __cdecl thunk_FUN_10006020(int arg_1);
int __thiscall thunk_FUN_10001951(void *this,undefined4 arg_2);
undefined4 ReleaseVid(void);
void __cdecl thunk_FUN_10006467(LPARAM *ptr_1);
int __fastcall thunk_FUN_1000755a(int arg_1);
undefined4 __cdecl SetVidThreadPriority(int arg1,int arg2);
void __thiscall thunk_FUN_1000b4a9(void *this,int *ptr_2);
CPrintPreviewState * __thiscall CPrintPreviewState::CPrintPreviewState(CPrintPreviewState *this);
undefined4 * __fastcall thunk_FUN_10004af0(undefined4 *ptr_1);
undefined4 * __fastcall AVI_InitializeSubsystem(undefined4 *ptr_1);
void __fastcall AVI_ShutdownSubsystem(int *ptr_1);
int __thiscall AVI_OpenFileStream(void *this,undefined4 arg_2);
undefined4 __fastcall AVI_ReleaseFileStream(int arg_1);
int __thiscall AVI_GetVideoStreamInfo(void *this,int arg_2,int arg_3);
undefined4 __fastcall AVI_ReleaseVideoStream(int *ptr_1);
undefined4 __thiscall AVI_InitTimerPeriod(void *this,int arg_2);
undefined4 __fastcall AVI_EndTimerPeriod(undefined4 *ptr_1);
undefined4 __fastcall AVI_StopPlaybackTimer(undefined4 *ptr_1);
undefined4 __thiscall AVI_SeekFrameToTime(void *this,undefined4 arg_2);
undefined4 __thiscall AVI_GetNextFrameSample(void *this,int arg_2);
undefined4 __thiscall FUN_10001f9d(void *this,float arg_2,uint arg_3,int arg_4,int arg_5,int arg_6);
undefined4 __thiscall FUN_10002227(void *this,int arg_2);
undefined4 __thiscall FUN_10002289(void *this,int arg_2);
undefined4 __thiscall FUN_100023d1(void *this,int arg_2);
void __fastcall FUN_100027a0(int arg_1);
void FUN_100027d0(void);
void FUN_100027e5(void);
void FID_conflict:_$E31(void);
void FUN_10002819(void);
void FUN_10002833(void);
void FUN_10002850(void);
undefined4 FUN_1000286a(undefined4 arg_1,undefined4 arg_2);
undefined4 FUN_100028d4(void);
undefined4 FUN_10002986(void);
undefined4 __cdecl FUN_100029cf(LPCSTR x,int *y,short *width,uint height);
undefined4 __cdecl FUN_10002dc7(int arg_1);
undefined4 __cdecl FUN_10002fc8(int arg_1);
undefined4 __cdecl FUN_1000303e(int arg_1);
undefined4 __cdecl FUN_100030dd(int arg1,undefined4 arg2);
undefined4 FUN_1000313a(void);
undefined4 __cdecl FUN_1000314c(int arg1,int arg2);
undefined4 __cdecl FUN_100031ce(int *ptr_1,undefined4 arg_2,int arg_3);
undefined4 __cdecl FUN_100032f0(int *ptr_1,int arg_2);
undefined4 __cdecl FUN_10003401(int arg_1);
undefined4 __cdecl FUN_10003525(int *x,short *y,int *width,int height);
undefined4 __cdecl FUN_100035f5(int *ptr_1,int arg_2);
undefined4 __cdecl FUN_1000365d(int arg_1);
undefined4 __cdecl FUN_10003766(int arg_1);
undefined4 __cdecl FUN_1000381e(int arg1,int arg2);
undefined4 __cdecl FUN_100038a4(int arg1,int arg2);
undefined4 __cdecl FUN_1000394a(int arg1,short *arg2);
undefined4 __cdecl FUN_10003a7e(int arg_1);
void FUN_10003ad3(HWND x,uint y,WPARAM width,int height);
LRESULT FUN_10003d1b(HWND x,uint y,uint width,LPVOID height);
undefined4 __cdecl FUN_10004249(int arg1,int *arg2);
undefined4 __cdecl FUN_100042c0(int arg_1);
undefined4 __cdecl FUN_10004344(int arg1,int arg2);
undefined4 * __fastcall FUN_10004af0(undefined4 *ptr_1);
int * __thiscall DeckDll_SideboardWndProc(void *this,byte arg_2);
undefined4 * __thiscall FUN_10004b70(void *this,byte arg_2);
undefined4 __fastcall FUN_10004bc0(int arg_1);
undefined4 __fastcall FUN_10004bf0(int arg_1);
bool __fastcall FUN_10004c20(int arg_1);
void __fastcall FUN_10004c60(int arg_1);
int __cdecl FUN_10004c90(int arg_1,undefined4 arg_2,uint arg_3);
void FUN_10004def(void);
undefined4 __cdecl FUN_10004e65(undefined4 arg_1,undefined4 arg_2,undefined4 arg_3);
undefined4 __cdecl FUN_10004ea1(undefined4 arg_1);
undefined4 FUN_10004ed5(void);
undefined4 __cdecl FUN_10004f02(undefined4 arg_1,undefined4 arg_2);
undefined4 __cdecl FUN_10004f47(undefined4 arg_1,undefined4 arg_2,undefined4 arg_3);
undefined4 __cdecl FUN_10004f90(undefined4 arg_1);
void FUN_10004fd1(void);
undefined4 __cdecl FUN_10005001(undefined4 arg_1,undefined4 arg_2);
undefined4 __cdecl FUN_10005046(undefined4 arg_1,undefined4 arg_2);
undefined4 __cdecl FUN_1000508b(undefined4 arg_1,undefined4 arg_2);
undefined4 __cdecl FUN_100050d0(undefined4 arg_1,undefined4 arg_2);
undefined4 __cdecl FUN_10005115(undefined4 arg_1,undefined4 arg_2);
undefined4 __cdecl FUN_1000515a(undefined4 arg_1,undefined4 arg_2);
undefined4 __cdecl FUN_1000519f(undefined4 arg_1,undefined4 arg_2);
undefined4 FUN_100051e4(void);
undefined4 __cdecl FUN_1000521e(undefined4 arg_1,undefined4 arg_2);
undefined4 __cdecl FUN_10005263(undefined4 arg_1,undefined4 arg_2);
undefined4 __cdecl FUN_100052a8(undefined4 arg_1);
undefined4 __cdecl FUN_100052e9(undefined4 arg_1,undefined4 arg_2);
undefined4 __cdecl FUN_1000532e(undefined4 arg_1,undefined4 arg_2);
undefined4 __cdecl FUN_10005373(undefined4 arg_1,undefined4 arg_2);
undefined4 __cdecl FUN_100053b5(undefined4 arg_1,undefined4 arg_2);
undefined4 FUN_100053fa(void);
undefined4 __cdecl FUN_10005431(undefined4 arg_1,undefined4 arg_2);
undefined4 __cdecl FUN_10005473(undefined4 arg_1,undefined4 arg_2,undefined4 arg_3);
void FUN_100054bc(void);
void __cdecl FUN_10005710(LPARAM *ptr_1);
void __cdecl FUN_1000592b(int arg_1);
void __cdecl FUN_100059e8(int arg_1);
undefined4 __cdecl FUN_10005a5b(LPARAM *ptr_1,LPCSTR arg_2);
void __cdecl FUN_10005b92(LPARAM *ptr_1);
void __cdecl FUN_10005c78(int arg1,int arg2);
void __cdecl FUN_10005ce8(int arg1,int arg2);
void __cdecl FUN_10005d8d(LPVOID arg_1);
void __cdecl FUN_10005ef9(int arg_1);
void FUN_10005fee(void);
void __cdecl FUN_10006020(int arg_1);
void __cdecl FUN_100060dd(HWND hwnd);
void __cdecl FUN_10006154(LPVOID arg_1,int arg_2);
undefined4 __cdecl FUN_1000634a(int arg_1,LONG arg_2,LONG arg_3);
void __cdecl FUN_100063e6(int arg_1,int arg_2,int arg_3);
void __cdecl FUN_10006467(LPARAM *ptr_1);
undefined4 __cdecl FUN_100065fe(LPARAM *ptr_1,int arg_2);
undefined4 __cdecl FUN_100066d7(LPARAM *ptr_1);
undefined4 __cdecl FUN_100067b9(undefined4 arg_1,HPSTR arg_2);
void __cdecl FUN_100069c9(LPARAM *ptr_1,short *ptr_2);
void __cdecl FUN_10006a43(LPARAM *ptr_1);
int __thiscall CArchive::IsBufferEmpty(CArchive *this);
void __fastcall FUN_10007050(int arg_1);
int __fastcall FUN_10007080(int arg_1);
void FUN_100070d0(undefined4 arg_1,int arg_2,void *ptr_3);
undefined4 __fastcall FUN_1000715a(int arg_1);
undefined4 __fastcall FUN_10007238(int arg_1);
int __thiscall FUN_10007268(void *this,int y,undefined4 width,int height);
undefined4 FUN_1000735d(void);
undefined4 FUN_10007383(void);
undefined4 FUN_100073a9(void);
undefined4 FUN_100073d1(void);
undefined4 __thiscall FUN_10007410(void *this,undefined4 arg_2);
int __thiscall FUN_1000743e(void *this,int arg_2);
int __fastcall FUN_1000755a(int arg_1);
undefined4 __fastcall FUN_1000761c(void *ptr_1);
void __cdecl FUN_100077f0(HWND hwnd,LPCSTR arg_2);
undefined4 __fastcall FUN_1000785e(int *ptr_1);
undefined4 __fastcall FUN_10007a85(int *ptr_1);
undefined4 __thiscall FUN_10007b00(void *this,int arg_2,int arg_3);
void __thiscall FUN_10007bde(void *this,int arg_2);
undefined4 __fastcall FUN_10007bff(undefined4 *ptr_1);
void FUN_10007c56(void);
void FUN_10007c6b(void);
undefined4 __fastcall FUN_10007c85(int *ptr_1);
undefined4 __thiscall FUN_10007eaf(void *this,undefined4 arg_2);
undefined4 __thiscall FUN_10007edd(void *this,undefined4 arg_2);
bool __thiscall FUN_10007f0b(void *this,int arg_2);
undefined4 __fastcall FUN_10007f71(undefined4 *ptr_1);
void __fastcall FUN_10008136(undefined4 *ptr_1);
int * __thiscall FUN_10008520(void *this,byte arg_2);
void __fastcall FUN_10008570(uint *ptr_1);
void __thiscall FUN_100085b0(void *this,char *str_2);
void __thiscall FUN_10008600(void *this,undefined4 arg_2,undefined4 arg_3,undefined4 arg_4,undefined4 arg_5);
void __thiscall FUN_10008660(void *this,char *str_2);
void __thiscall FUN_100086b0(void *this,undefined4 arg_2,undefined4 arg_3,undefined4 arg_4,undefined4 arg_5);
CPrintPreviewState * __thiscall CPrintPreviewState::CPrintPreviewState(CPrintPreviewState *this);
void __fastcall FUN_10008774(undefined4 *ptr_1);
undefined4 __thiscall FUN_10008802(void *this,int y,int width,int height);
undefined4 __thiscall FUN_100089e8(void *this,int *ptr_2,undefined4 arg_3);
int __cdecl FUN_10008ad5(int *ptr_1);
bool __cdecl FUN_10008c4c(int *ptr_1);
undefined4 __thiscall FUN_10008c74(void *this,HWND y,LPCSTR width,uint height);
undefined4 __thiscall FUN_100091ea(void *this,LPCSTR arg_2);
void __fastcall FUN_10009348(int arg_1);
undefined4 __thiscall FUN_1000936d(void *this,HPALETTE arg_2);
int __thiscall FUN_100095cf(void *this,int arg_2,int arg_3);
void __thiscall FUN_10009652(void *this,undefined4 *ptr_2);
void __thiscall FUN_10009699(void *this,CFontDialog *ptr_2,int arg_3,int arg_4,int arg_5,int arg_6,int arg_7,int arg_8);
undefined4 FUN_10009af2(int arg1,int arg2);
void __fastcall FUN_1000a070(CFontDialog *ptr_1);
void __fastcall FUN_1000a0a0(CFontDialog *ptr_1);
int __thiscall CFontDialog::GetWeight(CFontDialog *this);
int __thiscall CFontDialog::GetWeight(CFontDialog *this);
undefined2 __fastcall FUN_1000a130(int arg_1);
void __thiscall FUN_1000a160(void *this,undefined4 arg_2);
void __fastcall FUN_1000a1b0(int arg_1);
uint __fastcall FUN_1000a200(int arg_1);
undefined4 * __fastcall FUN_1000a250(undefined4 *ptr_1);
void __fastcall FUN_1000a2f1(int *ptr_1);
undefined4 __thiscall FUN_1000a30f(void *this,int arg_2,void *ptr_3);
undefined4 __fastcall FUN_1000a795(int *ptr_1);
int __thiscall FUN_1000a8d3(void *this,int arg_2);
void FUN_1000abc1(undefined4 arg_1,undefined4 arg_2,undefined4 arg_3,undefined4 arg_4,undefined4 arg_5,undefined4 arg_6,undefined4 arg_7,undefined4 arg_8,undefined4 arg_9,undefined4 arg_10,undefined4 arg_11,undefined4 arg_12,undefined4 arg_13,undefined4 arg_14);
void FUN_1000ac38(undefined4 arg_1,undefined4 arg_2,undefined4 arg_3,undefined4 arg_4,undefined4 arg_5,undefined4 arg_6,undefined4 arg_7,undefined4 arg_8,undefined4 arg_9,undefined4 arg_10,undefined4 arg_11,undefined4 arg_12,undefined4 arg_13,undefined4 arg_14);
undefined4 __fastcall FUN_1000acaf(undefined4 *ptr_1);
undefined4 __fastcall FUN_1000ae35(undefined4 *ptr_1);
undefined4 __fastcall FUN_1000aea5(undefined4 *ptr_1);
void FUN_1000aee5(void);
void FUN_1000aefa(void);
DWORD __thiscall FUN_1000af14(void *this,undefined4 arg_2,undefined4 arg_3);
void FUN_1000b284(undefined4 arg_1,undefined4 arg_2,undefined4 arg_3,undefined4 arg_4,undefined4 arg_5,undefined4 arg_6,undefined4 arg_7,undefined4 arg_8,undefined4 arg_9,undefined4 arg_10,undefined4 arg_11,undefined4 arg_12,undefined4 arg_13,undefined4 arg_14);
int __thiscall FUN_1000b2fb(void *this,undefined4 arg_2,undefined4 arg_3);
void __thiscall FUN_1000b3b1(void *this,undefined4 *ptr_2);
void __thiscall FUN_1000b404(void *this,int *ptr_2);
void __thiscall FUN_1000b456(void *this,undefined4 *ptr_2);
void __thiscall FUN_1000b4a9(void *this,int *ptr_2);
void __thiscall FUN_1000b4fb(void *this,undefined4 *ptr_2);
void __thiscall FUN_1000b54e(void *this,int *ptr_2);
void __thiscall FUN_1000b5e0(void *this,undefined4 *ptr_2);
void __thiscall FUN_1000b633(void *this,int *ptr_2);
undefined4 __thiscall FUN_1000b685(void *this,int *ptr_2);
void __thiscall FUN_1000b6ff(void *this,void *ptr_2);
void __thiscall FUN_1000b72c(void *this,void *ptr_2);
void __thiscall FUN_1000b759(void *this,void *ptr_2);
void __thiscall FUN_1000b786(void *this,void *ptr_2);
int __thiscall FUN_1000b83e(void *this,int arg_2,int arg_3,int arg_4,int arg_5,int arg_6);
bool __thiscall FUN_1000b99f(void *this,int arg_2);
undefined4 __thiscall FUN_1000bac7(void *this,int *ptr_2);
undefined4 __thiscall FUN_1000bbec(void *this,int arg_2);
undefined4 __thiscall FUN_1000bc86(void *this,int *ptr_2);
bool __thiscall FUN_1000bd47(void *this,int arg_2);
void __thiscall FUN_1000bdea(void *this,undefined4 *ptr_2,undefined4 *ptr_3,undefined4 *ptr_4,int arg_5);
void __thiscall FUN_1000bec3(void *this,int arg_2,int arg_3,int arg_4,int arg_5);
void __thiscall FUN_1000bfe1(void *this,undefined4 y,undefined4 *width,int height);
void __thiscall FUN_1000c0a4(void *this,undefined4 y,undefined4 width,int height);
void __thiscall FUN_1000c165(void *this,undefined4 arg_2);
BOOL GetOpenFileNameA(LPOPENFILENAMEA arg_1);
void AVIFileInit(void);
void AVIFileExit(void);
void AVIFileOpenA(void);
void AVIFileRelease(void);
void AVIStreamInfoA(void);
void AVIFileGetStream(void);
void AVIStreamRelease(void);
void AVIStreamTimeToSample(void);
void AVIStreamSampleToTime(void);
void DrawDibClose(void);
void DrawDibDraw(void);
void DrawDibOpen(void);
void AVIStreamRead(void);
void AVIStreamReadFormat(void);
void AVIStreamFindSample(void);
void ICSendMessage(void);
void ICLocate(void);
void ICClose(void);
void DrawDibStart(void);
void DrawDibBegin(void);
void DrawDibEnd(void);
void DrawDibStop(void);
void ICDrawBegin(void);
void __cdecl ftol(void);
void __cdecl operator_delete(void *ptr_1);
void * __cdecl operator_new(uint arg_1);
_onexit_t __cdecl __onexit(_onexit_t arg_1);
int __cdecl _atexit(_func_4879 *ptr_1);
void * __cdecl memset(void *ptr_1,int arg_2,size_t arg_3);
int __cdecl abs(int arg_1);
char * __cdecl strcpy(char *str_1,char *str_2);
void * __cdecl memcpy(void *ptr_1,void *ptr_2,size_t arg_3);
undefined4 __CRT_INIT@12(undefined4 arg_1,int arg_2);
int entry(undefined4 arg_1,int arg_2,undefined4 arg_3);
void __dllonexit(void);
void __cdecl initterm(void);


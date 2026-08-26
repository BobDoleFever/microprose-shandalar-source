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

typedef struct _OVERLAPPED *LPOVERLAPPED;

typedef struct _SECURITY_ATTRIBUTES *LPSECURITY_ATTRIBUTES;

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

typedef uint size_t;

typedef struct tagMSG tagMSG, *PtagMSG;

typedef struct tagMSG MSG;

typedef struct HWND__ HWND__, *PHWND__;

typedef struct HWND__ *HWND;

typedef uint UINT;

typedef uint UINT_PTR;

typedef UINT_PTR WPARAM;

typedef long LONG_PTR;

typedef LONG_PTR LPARAM;

typedef struct tagPOINT tagPOINT, *PtagPOINT;

typedef struct tagPOINT POINT;

typedef long LONG;

struct tagPOINT {
    LONG x;
    LONG y;
};

struct tagMSG {
    HWND hwnd;
    UINT message;
    WPARAM wParam;
    LPARAM lParam;
    DWORD time;
    POINT pt;
};

struct HWND__ {
    int unused;
};

typedef struct tagWNDCLASSA tagWNDCLASSA, *PtagWNDCLASSA;

typedef LONG_PTR LRESULT;

typedef LRESULT (*WNDPROC)(HWND, UINT, WPARAM, LPARAM);

typedef struct HINSTANCE__ HINSTANCE__, *PHINSTANCE__;

typedef struct HINSTANCE__ *HINSTANCE;

typedef struct HICON__ HICON__, *PHICON__;

typedef struct HICON__ *HICON;

typedef HICON HCURSOR;

typedef struct HBRUSH__ HBRUSH__, *PHBRUSH__;

typedef struct HBRUSH__ *HBRUSH;

typedef char CHAR;

typedef CHAR *LPCSTR;

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

struct HINSTANCE__ {
    int unused;
};

typedef struct tagMSG *LPMSG;

typedef struct tagWNDCLASSA WNDCLASSA;

typedef int INT_PTR;

typedef INT_PTR (*DLGPROC)(HWND, UINT, WPARAM, LPARAM);

typedef struct tagPALETTEENTRY tagPALETTEENTRY, *PtagPALETTEENTRY;

typedef struct tagPALETTEENTRY *LPPALETTEENTRY;

typedef uchar BYTE;

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

typedef ULONG_PTR SIZE_T;

typedef struct HPALETTE__ HPALETTE__, *PHPALETTE__;

struct HPALETTE__ {
    int unused;
};

typedef DWORD *LPDWORD;

typedef struct HPALETTE__ *HPALETTE;

typedef struct HDC__ HDC__, *PHDC__;

struct HDC__ {
    int unused;
};

typedef ushort WORD;

typedef HINSTANCE HMODULE;

typedef struct tagRECT tagRECT, *PtagRECT;

typedef struct tagRECT RECT;

struct tagRECT {
    LONG left;
    LONG top;
    LONG right;
    LONG bottom;
};

typedef struct HMENU__ HMENU__, *PHMENU__;

typedef struct HMENU__ *HMENU;

struct HMENU__ {
    int unused;
};

typedef int (*FARPROC)(void);

typedef struct HDC__ *HDC;

typedef WORD ATOM;

typedef struct tagRECT *LPRECT;

typedef HANDLE HGLOBAL;

typedef void *HGDIOBJ;

typedef void *LPCVOID;

typedef DWORD COLORREF;

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

typedef struct CFontDialog CFontDialog, *PCFontDialog;

struct CFontDialog { /* PlaceHolder Structure */
};

typedef struct CPrintPreviewState CPrintPreviewState, *PCPrintPreviewState;

struct CPrintPreviewState { /* PlaceHolder Structure */
};

typedef int (*_onexit_t)(void);




undefined4 __thiscall thunk_FUN_1000a058(void *this,int *ptr_2,undefined4 arg_3);
int __thiscall thunk_FUN_1000ac3f(void *this,int arg_2,int arg_3);
void __thiscall thunk_FUN_10006d86(void *this,int arg_2);
undefined4 __thiscall thunk_FUN_100080e7(void *this,int arg_2);
void __fastcall thunk_FUN_10004e94(int *ptr_1);
undefined4 __thiscall thunk_FUN_10007083(void *this,int arg_2);
void __fastcall thunk_FUN_100095b0(CFontDialog *ptr_1);
void __cdecl status_show(int arg1,int arg2);
undefined4 thunk_FUN_10001f30(HINSTANCE hInstance,undefined4 arg_2);
undefined4 __cdecl thunk_FUN_10001722(undefined4 arg_1,undefined4 arg_2);
uint __fastcall thunk_FUN_1000b760(int arg_1);
void __fastcall thunk_FUN_10004afa(undefined4 *ptr_1);
void __cdecl thunk_FUN_1000432f(char *str_1,char *str_2,char *str_3);
undefined4 thunk_FUN_1000245c(void);
void __cdecl thunk_FUN_1000268a(int arg_1);
undefined4 * __fastcall thunk_FUN_10004407(undefined4 *ptr_1);
bool thunk_FUN_100035b2(void);
undefined4 __fastcall thunk_FUN_100058cd(int *ptr_1);
int __cdecl thunk_FUN_100014b0(int arg_1,undefined4 arg_2,uint arg_3);
void thunk_FUN_10002be9(void);
void __cdecl thunk_FUN_10002f86(HWND hwnd);
void __thiscall thunk_FUN_10006870(void *this,int arg_2);
void __fastcall thunk_FUN_10007805(int arg_1);
void thunk_FUN_10001cdc(void);
undefined2 __fastcall thunk_FUN_1000b6e0(int arg_1);
void __thiscall thunk_FUN_10006b3f(void *this,int arg_2);
int __thiscall CFontDialog::GetWeight(CFontDialog *this);
void thunk_FUN_10009bda(void);
undefined4 __cdecl thunk_FUN_100099ba(undefined4 arg_1,undefined4 arg_2);
undefined4 __thiscall thunk_FUN_10008419(void *this,int arg_2);
undefined4 __cdecl thunk_FUN_100097f0(undefined4 arg_1);
undefined4 thunk_FUN_100023fd(void);
undefined4 __thiscall thunk_FUN_1000a2e4(void *this,HWND y,LPCSTR width,uint height);
uint __cdecl thunk_FUN_10003472(char *str_1);
void __thiscall thunk_FUN_1000735d(void *this,int arg_2);
int __thiscall CFontDialog::GetWeight(CFontDialog *this);
undefined4 thunk_FUN_10001c1a(void);
void __fastcall thunk_FUN_1000b710(int arg_1);
undefined4 __fastcall thunk_FUN_100042d0(int arg_1);
void * __thiscall thunk_FUN_100041b0(void *this,byte arg_2);
void __fastcall thunk_FUN_10009de4(undefined4 *ptr_1);
bool __cdecl thunk_FUN_10007c74(int *ptr_1,int *ptr_2,int *ptr_3);
void thunk_FUN_1000310f(int arg_1);
void __cdecl thunk_FUN_1000308a(undefined4 arg_1);
int __cdecl status_init(undefined4 *ptr_1);
undefined4 __thiscall thunk_FUN_1000814f(void *this,int arg_2);
int __fastcall thunk_FUN_10009530(int arg_1);
undefined4 __thiscall thunk_FUN_100049cf(void *this,int arg_2,int arg_3);
undefined4 __cdecl thunk_FUN_100099ff(undefined4 arg_1,undefined4 arg_2);
void __thiscall thunk_FUN_10004200(void *this,undefined4 arg_2);
void thunk_FUN_10003303(CFontDialog *ptr_1,LPCSTR arg_2);
undefined4 __cdecl thunk_FUN_10009ace(undefined4 arg_1);
undefined4 __fastcall thunk_FUN_100042a0(int arg_1);
void __thiscall thunk_FUN_1000acc2(void *this,undefined4 *ptr_2);
undefined4 __thiscall thunk_FUN_10006212(void *this,int arg_2,int *ptr_3);
undefined4 __thiscall thunk_FUN_10009e72(void *this,int y,int width,int height);
undefined4 __cdecl thunk_FUN_10009a89(undefined4 arg_1,undefined4 arg_2);
int __cdecl thunk_FUN_10009640(undefined4 arg_1,undefined4 arg_2,undefined4 arg_3);
undefined4 __cdecl thunk_FUN_100016c1(undefined4 arg_1);
int __thiscall thunk_FUN_1000435f(void *this,int *y,int width,int *height);
undefined4 __cdecl thunk_FUN_100017b0(undefined4 arg_1);
undefined4 __cdecl thunk_FUN_10009865(undefined4 arg_1);
undefined4 __cdecl thunk_FUN_100097b0(undefined4 arg_1,undefined4 arg_2,undefined4 arg_3,undefined4 arg_4);
int __cdecl play_video(undefined4 arg_1,undefined2 arg_2,undefined2 arg_3,byte arg_4);
undefined4 __cdecl thunk_FUN_10001685(undefined4 arg_1,undefined4 arg_2,undefined4 arg_3);
undefined4 __fastcall thunk_FUN_100065ce(int *ptr_1);
undefined4 * __thiscall thunk_FUN_10004250(void *this,byte arg_2);
void __thiscall thunk_FUN_1000ad09(void *this,CFontDialog *ptr_2,int arg_3,int arg_4,int arg_5,int arg_6,int arg_7,int arg_8);
undefined4 __cdecl thunk_FUN_10009b0f(undefined4 arg_1);
void __fastcall thunk_FUN_1000a9b8(int arg_1);
undefined4 __thiscall thunk_FUN_10005d98(void *this,int arg_2,int *ptr_3);
undefined4 __cdecl thunk_FUN_10009824(undefined4 arg_1);
void __thiscall thunk_FUN_10004512(void *this,undefined4 *ptr_2,int arg_3);
void thunk_FUN_1000160f(void);
void __thiscall thunk_FUN_100059af(void *this,int arg_2);
undefined4 __thiscall thunk_FUN_10007d32(void *this,int arg_2);
void __fastcall thunk_FUN_10009580(CFontDialog *ptr_1);
undefined4 __cdecl thunk_FUN_10009a44(undefined4 arg_1,undefined4 arg_2);
char thunk_FUN_1000353c(void);
void __fastcall thunk_FUN_10004481(int arg_1);
undefined4 thunk_FUN_10009766(void);
int __thiscall thunk_FUN_10007b3b(void *this,int *ptr_2,int arg_3);
CPrintPreviewState * __thiscall CPrintPreviewState::CPrintPreviewState(CPrintPreviewState *this);
undefined4 * __fastcall thunk_FUN_10009500(undefined4 *ptr_1);
int __cdecl StatWin_LoadSoundDll(int arg_1,undefined4 arg_2,uint arg_3);
void StatWin_FreeSoundDll(void);
undefined4 __cdecl FUN_10001685(undefined4 arg_1,undefined4 arg_2,undefined4 arg_3);
undefined4 __cdecl FUN_100016c1(undefined4 arg_1);
undefined4 FUN_100016f5(void);
undefined4 __cdecl FUN_10001722(undefined4 arg_1,undefined4 arg_2);
undefined4 __cdecl FUN_10001767(undefined4 arg_1,undefined4 arg_2,undefined4 arg_3);
undefined4 __cdecl FUN_100017b0(undefined4 arg_1);
void FUN_100017f1(void);
undefined4 __cdecl FUN_10001821(undefined4 arg_1,undefined4 arg_2);
undefined4 __cdecl FUN_10001866(undefined4 arg_1,undefined4 arg_2);
undefined4 __cdecl FUN_100018ab(undefined4 arg_1,undefined4 arg_2);
undefined4 __cdecl FUN_100018f0(undefined4 arg_1,undefined4 arg_2);
undefined4 __cdecl FUN_10001935(undefined4 arg_1,undefined4 arg_2);
undefined4 __cdecl FUN_1000197a(undefined4 arg_1,undefined4 arg_2);
undefined4 __cdecl FUN_100019bf(undefined4 arg_1,undefined4 arg_2);
undefined4 FUN_10001a04(void);
undefined4 __cdecl FUN_10001a3e(undefined4 arg_1,undefined4 arg_2);
undefined4 __cdecl FUN_10001a83(undefined4 arg_1,undefined4 arg_2);
undefined4 __cdecl FUN_10001ac8(undefined4 arg_1);
undefined4 __cdecl FUN_10001b09(undefined4 arg_1,undefined4 arg_2);
undefined4 __cdecl FUN_10001b4e(undefined4 arg_1,undefined4 arg_2);
undefined4 __cdecl FUN_10001b93(undefined4 arg_1,undefined4 arg_2);
undefined4 __cdecl FUN_10001bd5(undefined4 arg_1,undefined4 arg_2);
undefined4 FUN_10001c1a(void);
undefined4 __cdecl FUN_10001c51(undefined4 arg_1,undefined4 arg_2);
undefined4 __cdecl FUN_10001c93(undefined4 arg_1,undefined4 arg_2,undefined4 arg_3);
void FUN_10001cdc(void);
undefined4 StatWin_RegisterWindowClass(HINSTANCE hInstance,undefined4 arg_2);
int __cdecl StatWin_SetAssetPath(undefined4 *ptr_1);
void __cdecl FUN_10002209(int arg1,int arg2);
undefined4 StatWin_ProcessMessagePump(void);
void __cdecl FUN_10002440(undefined4 arg_1);
undefined4 StatWin_ProcessPendingEvents(void);
void __cdecl StatWin_PlayVictorySound(int arg_1);
void __cdecl StatWin_DisplayStatusScreen(int arg_1);
void StatWin_CreateStatusWindow(void);
LRESULT StatWin_WindowProc(HWND x,uint y,WPARAM width,LPARAM height);
void __cdecl StatWin_DrawDibRender(HWND hwnd);
void __cdecl FUN_1000308a(undefined4 arg_1);
void FUN_1000310f(int arg_1);
void FUN_100032e1(void);
void FUN_100032f4(void);
void FUN_10003303(CFontDialog *ptr_1,LPCSTR arg_2);
void FUN_10003450(void);
void FUN_10003463(void);
uint __cdecl FUN_10003472(char *str_1);
char FUN_1000353c(void);
bool FUN_100035b2(void);
undefined4 FUN_10003677(HWND hwnd,int arg_2,ushort arg_3);
int __cdecl FUN_100037ad(undefined4 arg_1,undefined2 arg_2,undefined2 arg_3,byte arg_4);
void FUN_1000396a(HWND x,uint y,WPARAM width,LPARAM height);
void * __thiscall FUN_100041b0(void *this,byte arg_2);
void __thiscall FUN_10004200(void *this,undefined4 arg_2);
undefined4 * __thiscall FUN_10004250(void *this,byte arg_2);
undefined4 __fastcall FUN_100042a0(int arg_1);
undefined4 __fastcall FUN_100042d0(int arg_1);
void FUN_10004300(void);
void FUN_10004315(void);
void __cdecl FUN_1000432f(char *str_1,char *str_2,char *str_3);
int __thiscall FUN_1000435f(void *this,int *y,int width,int *height);
undefined4 * __fastcall FUN_10004407(undefined4 *ptr_1);
void __fastcall FUN_10004481(int arg_1);
void __thiscall FUN_10004512(void *this,undefined4 *ptr_2,int arg_3);
void FUN_100049ab(void);
void FUN_100049be(void);
undefined4 __thiscall FUN_100049cf(void *this,int arg_2,int arg_3);
void __fastcall FUN_10004afa(undefined4 *ptr_1);
void FUN_10004e72(void);
void FUN_10004e85(void);
void __fastcall FUN_10004e94(int *ptr_1);
void FUN_100058ab(void);
void FUN_100058be(void);
undefined4 __fastcall FUN_100058cd(int *ptr_1);
void FUN_10005999(void);
void __thiscall FUN_100059af(void *this,int arg_2);
undefined4 __thiscall FUN_10005d98(void *this,int arg_2,int *ptr_3);
undefined4 __thiscall FUN_10006212(void *this,int arg_2,int *ptr_3);
undefined4 __cdecl DeckDll_LoadDeckFile(undefined4 arg_1);
undefined4 __fastcall FUN_100065ce(int *ptr_1);
void __thiscall FUN_10006870(void *this,int arg_2);
void __thiscall FUN_10006b3f(void *this,int arg_2);
void __fastcall FUN_10006d00(int *ptr_1);
void __thiscall FUN_10006d86(void *this,int arg_2);
void FUN_10007044(void);
void FUN_1000704d(void);
void FUN_10007056(void);
void FUN_1000705f(void);
void FUN_10007072(void);
undefined4 __thiscall FUN_10007083(void *this,int arg_2);
void __thiscall FUN_1000735d(void *this,int arg_2);
void FUN_100077d8(void);
void FUN_100077e1(void);
void FUN_100077f4(void);
void __fastcall FUN_10007805(int arg_1);
int __thiscall FUN_10007b3b(void *this,int *ptr_2,int arg_3);
bool __cdecl FUN_10007c74(int *ptr_1,int *ptr_2,int *ptr_3);
undefined4 __thiscall FUN_10007d32(void *this,int arg_2);
undefined4 __thiscall FUN_100080e7(void *this,int arg_2);
undefined4 __thiscall FUN_1000814f(void *this,int arg_2);
undefined4 __thiscall FUN_10008419(void *this,int arg_2);
undefined4 * __fastcall FUN_10009500(undefined4 *ptr_1);
int __fastcall FUN_10009530(int arg_1);
void __fastcall FUN_10009580(CFontDialog *ptr_1);
void __fastcall FUN_100095b0(CFontDialog *ptr_1);
int __thiscall CFontDialog::GetWeight(CFontDialog *this);
int __thiscall CFontDialog::GetWeight(CFontDialog *this);
int __cdecl FUN_10009640(undefined4 arg_1,undefined4 arg_2,undefined4 arg_3);
undefined4 FUN_10009766(void);
undefined4 __cdecl FUN_100097b0(undefined4 arg_1,undefined4 arg_2,undefined4 arg_3,undefined4 arg_4);
undefined4 __cdecl FUN_100097f0(undefined4 arg_1);
undefined4 __cdecl FUN_10009824(undefined4 arg_1);
undefined4 __cdecl FUN_10009865(undefined4 arg_1);
undefined4 __cdecl FUN_100098a6(undefined4 arg_1,undefined4 arg_2);
undefined4 __cdecl FUN_100098eb(undefined4 arg_1,undefined4 arg_2);
undefined4 __cdecl FUN_10009930(undefined4 arg_1,undefined4 arg_2,undefined4 arg_3);
undefined4 __cdecl FUN_10009979(undefined4 arg_1);
undefined4 __cdecl FUN_100099ba(undefined4 arg_1,undefined4 arg_2);
undefined4 __cdecl FUN_100099ff(undefined4 arg_1,undefined4 arg_2);
undefined4 __cdecl FUN_10009a44(undefined4 arg_1,undefined4 arg_2);
undefined4 __cdecl FUN_10009a89(undefined4 arg_1,undefined4 arg_2);
undefined4 __cdecl FUN_10009ace(undefined4 arg_1);
undefined4 __cdecl FUN_10009b0f(undefined4 arg_1);
undefined4 __cdecl FUN_10009b50(undefined4 arg_1,undefined4 arg_2);
undefined4 __cdecl FUN_10009b95(undefined4 arg_1,undefined4 arg_2);
void FUN_10009bda(void);
CPrintPreviewState * __thiscall CPrintPreviewState::CPrintPreviewState(CPrintPreviewState *this);
void __fastcall FUN_10009de4(undefined4 *ptr_1);
undefined4 __thiscall FUN_10009e72(void *this,int y,int width,int height);
undefined4 __thiscall FUN_1000a058(void *this,int *ptr_2,undefined4 arg_3);
int __cdecl FUN_1000a145(int *ptr_1);
bool __cdecl FUN_1000a2bc(int *ptr_1);
undefined4 __thiscall FUN_1000a2e4(void *this,HWND y,LPCSTR width,uint height);
undefined4 __thiscall FUN_1000a85a(void *this,LPCSTR arg_2);
void __fastcall FUN_1000a9b8(int arg_1);
undefined4 __thiscall FUN_1000a9dd(void *this,HPALETTE arg_2);
int __thiscall FUN_1000ac3f(void *this,int arg_2,int arg_3);
void __thiscall FUN_1000acc2(void *this,undefined4 *ptr_2);
void __thiscall FUN_1000ad09(void *this,CFontDialog *ptr_2,int arg_3,int arg_4,int arg_5,int arg_6,int arg_7,int arg_8);
undefined4 FUN_1000b162(int arg1,int arg2);
undefined2 __fastcall FUN_1000b6e0(int arg_1);
void __fastcall FUN_1000b710(int arg_1);
uint __fastcall FUN_1000b760(int arg_1);
void DrawDibClose(void);
void DrawDibDraw(void);
void DrawDibOpen(void);
void __cdecl operator_delete(void *ptr_1);
void * __cdecl operator_new(uint arg_1);
void * __cdecl memset(void *ptr_1,int arg_2,size_t arg_3);
char * __cdecl strcat(char *str_1,char *str_2);
char * __cdecl strcpy(char *str_1,char *str_2);
void * __cdecl memcpy(void *ptr_1,void *ptr_2,size_t arg_3);
undefined4 __CRT_INIT@12(undefined4 arg_1,int arg_2);
int entry(HINSTANCE hInstance,int arg_2,undefined4 arg_3);
_onexit_t __cdecl __onexit(_onexit_t arg_1);
int __cdecl _atexit(_func_4879 *ptr_1);
void __cdecl initterm(void);
void __dllonexit(void);


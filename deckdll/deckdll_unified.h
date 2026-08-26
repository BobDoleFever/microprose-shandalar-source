typedef unsigned char   undefined;

typedef unsigned char    byte;
typedef unsigned int    dword;
typedef pointer32 ImageBaseOffset32;

typedef long long    longlong;
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
typedef struct _OVERLAPPED _OVERLAPPED, *P_OVERLAPPED;

typedef ulong ULONG_PTR;

typedef union _union_518 _union_518, *P_union_518;

typedef void *HANDLE;

typedef struct _struct_519 _struct_519, *P_struct_519;

typedef void *PVOID;

typedef ulong DWORD;

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

typedef struct _SECURITY_ATTRIBUTES _SECURITY_ATTRIBUTES, *P_SECURITY_ATTRIBUTES;

typedef void *LPVOID;

typedef int BOOL;

struct _SECURITY_ATTRIBUTES {
    DWORD nLength;
    LPVOID lpSecurityDescriptor;
    BOOL bInheritHandle;
};

typedef struct _SYSTEMTIME _SYSTEMTIME, *P_SYSTEMTIME;

typedef struct _SYSTEMTIME SYSTEMTIME;

typedef ushort WORD;

struct _SYSTEMTIME {
    WORD wYear;
    WORD wMonth;
    WORD wDayOfWeek;
    WORD wDay;
    WORD wHour;
    WORD wMinute;
    WORD wSecond;
    WORD wMilliseconds;
};

typedef struct _OVERLAPPED *LPOVERLAPPED;

typedef struct _SECURITY_ATTRIBUTES *LPSECURITY_ATTRIBUTES;

typedef struct _RTL_CRITICAL_SECTION _RTL_CRITICAL_SECTION, *P_RTL_CRITICAL_SECTION;

typedef struct _RTL_CRITICAL_SECTION *PRTL_CRITICAL_SECTION;

typedef PRTL_CRITICAL_SECTION LPCRITICAL_SECTION;

typedef struct _RTL_CRITICAL_SECTION_DEBUG _RTL_CRITICAL_SECTION_DEBUG, *P_RTL_CRITICAL_SECTION_DEBUG;

typedef struct _RTL_CRITICAL_SECTION_DEBUG *PRTL_CRITICAL_SECTION_DEBUG;

typedef long LONG;

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

typedef char *va_list;

typedef longlong __time64_t;

typedef uint size_t;

typedef __time64_t time_t;

typedef struct tagWNDCLASSA tagWNDCLASSA, *PtagWNDCLASSA;

typedef uint UINT;

typedef long LONG_PTR;

typedef LONG_PTR LRESULT;

typedef struct HWND__ HWND__, *PHWND__;

typedef struct HWND__ *HWND;

typedef uint UINT_PTR;

typedef UINT_PTR WPARAM;

typedef LONG_PTR LPARAM;

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

struct HWND__ {
    int unused;
};

typedef struct tagMSG tagMSG, *PtagMSG;

typedef struct tagMSG MSG;

typedef struct tagPOINT tagPOINT, *PtagPOINT;

typedef struct tagPOINT POINT;

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

typedef struct tagMSG *LPMSG;

typedef struct tagWNDCLASSA WNDCLASSA;

typedef struct tagPAINTSTRUCT tagPAINTSTRUCT, *PtagPAINTSTRUCT;

typedef struct tagPAINTSTRUCT *LPPAINTSTRUCT;

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

typedef struct tagPAINTSTRUCT PAINTSTRUCT;

typedef BOOL (*WNDENUMPROC)(HWND, LPARAM);

typedef void (*TIMERPROC)(HWND, UINT, UINT_PTR, DWORD);

typedef int INT_PTR;

typedef INT_PTR (*DLGPROC)(HWND, UINT, WPARAM, LPARAM);

typedef struct tagPALETTEENTRY tagPALETTEENTRY, *PtagPALETTEENTRY;

typedef struct tagPALETTEENTRY PALETTEENTRY;

struct tagPALETTEENTRY {
    BYTE peRed;
    BYTE peGreen;
    BYTE peBlue;
    BYTE peFlags;
};

typedef struct _ABC _ABC, *P_ABC;

struct _ABC {
    int abcA;
    UINT abcB;
    int abcC;
};

typedef struct tagTEXTMETRICA tagTEXTMETRICA, *PtagTEXTMETRICA;

struct tagTEXTMETRICA {
    LONG tmHeight;
    LONG tmAscent;
    LONG tmDescent;
    LONG tmInternalLeading;
    LONG tmExternalLeading;
    LONG tmAveCharWidth;
    LONG tmMaxCharWidth;
    LONG tmWeight;
    LONG tmOverhang;
    LONG tmDigitizedAspectX;
    LONG tmDigitizedAspectY;
    BYTE tmFirstChar;
    BYTE tmLastChar;
    BYTE tmDefaultChar;
    BYTE tmBreakChar;
    BYTE tmItalic;
    BYTE tmUnderlined;
    BYTE tmStruckOut;
    BYTE tmPitchAndFamily;
    BYTE tmCharSet;
};

typedef struct _devicemodeA _devicemodeA, *P_devicemodeA;

typedef union _union_655 _union_655, *P_union_655;

typedef union _union_658 _union_658, *P_union_658;

typedef struct _struct_656 _struct_656, *P_struct_656;

typedef struct _struct_657 _struct_657, *P_struct_657;

typedef struct _POINTL _POINTL, *P_POINTL;

typedef struct _POINTL POINTL;

struct _POINTL {
    LONG x;
    LONG y;
};

struct _struct_657 {
    POINTL dmPosition;
    DWORD dmDisplayOrientation;
    DWORD dmDisplayFixedOutput;
};

struct _struct_656 {
    short dmOrientation;
    short dmPaperSize;
    short dmPaperLength;
    short dmPaperWidth;
    short dmScale;
    short dmCopies;
    short dmDefaultSource;
    short dmPrintQuality;
};

union _union_655 {
    struct _struct_656 field0;
    struct _struct_657 field1;
};

union _union_658 {
    DWORD dmDisplayFlags;
    DWORD dmNup;
};

struct _devicemodeA {
    BYTE dmDeviceName[32];
    WORD dmSpecVersion;
    WORD dmDriverVersion;
    WORD dmSize;
    WORD dmDriverExtra;
    DWORD dmFields;
    union _union_655 field6_0x2c;
    short dmColor;
    short dmDuplex;
    short dmYResolution;
    short dmTTOption;
    short dmCollate;
    BYTE dmFormName[32];
    WORD dmLogPixels;
    DWORD dmBitsPerPel;
    DWORD dmPelsWidth;
    DWORD dmPelsHeight;
    union _union_658 field17_0x74;
    DWORD dmDisplayFrequency;
    DWORD dmICMMethod;
    DWORD dmICMIntent;
    DWORD dmMediaType;
    DWORD dmDitherType;
    DWORD dmReserved1;
    DWORD dmReserved2;
    DWORD dmPanningWidth;
    DWORD dmPanningHeight;
};

typedef struct tagLOGPALETTE tagLOGPALETTE, *PtagLOGPALETTE;

typedef struct tagLOGPALETTE LOGPALETTE;

struct tagLOGPALETTE {
    WORD palVersion;
    WORD palNumEntries;
    PALETTEENTRY palPalEntry[1];
};

typedef struct tagLOGFONTA tagLOGFONTA, *PtagLOGFONTA;

typedef struct tagLOGFONTA LOGFONTA;

struct tagLOGFONTA {
    LONG lfHeight;
    LONG lfWidth;
    LONG lfEscapement;
    LONG lfOrientation;
    LONG lfWeight;
    BYTE lfItalic;
    BYTE lfUnderline;
    BYTE lfStrikeOut;
    BYTE lfCharSet;
    BYTE lfOutPrecision;
    BYTE lfClipPrecision;
    BYTE lfQuality;
    BYTE lfPitchAndFamily;
    CHAR lfFaceName[32];
};

typedef struct _devicemodeA DEVMODEA;

typedef struct tagTEXTMETRICA *LPTEXTMETRICA;

typedef struct tagBITMAPINFOHEADER tagBITMAPINFOHEADER, *PtagBITMAPINFOHEADER;

typedef struct tagBITMAPINFOHEADER BITMAPINFOHEADER;

struct tagBITMAPINFOHEADER {
    DWORD biSize;
    LONG biWidth;
    LONG biHeight;
    WORD biPlanes;
    WORD biBitCount;
    DWORD biCompression;
    DWORD biSizeImage;
    LONG biXPelsPerMeter;
    LONG biYPelsPerMeter;
    DWORD biClrUsed;
    DWORD biClrImportant;
};

typedef struct tagRGBQUAD tagRGBQUAD, *PtagRGBQUAD;

typedef struct tagRGBQUAD RGBQUAD;

struct tagRGBQUAD {
    BYTE rgbBlue;
    BYTE rgbGreen;
    BYTE rgbRed;
    BYTE rgbReserved;
};

typedef struct tagBITMAPINFO tagBITMAPINFO, *PtagBITMAPINFO;

struct tagBITMAPINFO {
    BITMAPINFOHEADER bmiHeader;
    RGBQUAD bmiColors[1];
};

typedef struct tagBITMAPINFO BITMAPINFO;

typedef struct tagPALETTEENTRY *LPPALETTEENTRY;

typedef struct _ABC *LPABC;

typedef CHAR *LPSTR;

typedef DWORD ACCESS_MASK;

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

typedef long clock_t;

typedef ULONG_PTR SIZE_T;

typedef struct tagPOINT *LPPOINT;

typedef struct HFONT__ HFONT__, *PHFONT__;

struct HFONT__ {
    int unused;
};

typedef struct HKEY__ HKEY__, *PHKEY__;

struct HKEY__ {
    int unused;
};

typedef struct HACCEL__ HACCEL__, *PHACCEL__;

typedef struct HACCEL__ *HACCEL;

struct HACCEL__ {
    int unused;
};

typedef struct tagSIZE tagSIZE, *PtagSIZE;

struct tagSIZE {
    LONG cx;
    LONG cy;
};

typedef struct HPALETTE__ HPALETTE__, *PHPALETTE__;

struct HPALETTE__ {
    int unused;
};

typedef HINSTANCE HMODULE;

typedef struct HBITMAP__ HBITMAP__, *PHBITMAP__;

struct HBITMAP__ {
    int unused;
};

typedef struct HPEN__ HPEN__, *PHPEN__;

struct HPEN__ {
    int unused;
};

typedef int (*FARPROC)(void);

typedef WORD ATOM;

typedef struct HRGN__ HRGN__, *PHRGN__;

typedef struct HRGN__ *HRGN;

struct HRGN__ {
    int unused;
};

typedef struct tagRECT *LPRECT;

typedef void *HGDIOBJ;

typedef struct HKEY__ *HKEY;

typedef struct HRSRC__ HRSRC__, *PHRSRC__;

typedef struct HRSRC__ *HRSRC;

struct HRSRC__ {
    int unused;
};

typedef DWORD COLORREF;

typedef struct HFONT__ *HFONT;

typedef DWORD *LPDWORD;

typedef struct HPEN__ *HPEN;

typedef struct HPALETTE__ *HPALETTE;

typedef int *LPINT;

typedef struct tagSIZE *LPSIZE;

typedef BYTE *LPBYTE;

typedef struct HMENU__ HMENU__, *PHMENU__;

typedef struct HMENU__ *HMENU;

struct HMENU__ {
    int unused;
};

typedef int INT;

typedef HKEY *PHKEY;

typedef HANDLE HGLOBAL;

typedef void *LPCVOID;

typedef struct HBITMAP__ *HBITMAP;

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

typedef struct Var Var, *PVar;

struct Var {
    word wLength;
    word wValueLength;
    word wType;
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

typedef struct StringFileInfo StringFileInfo, *PStringFileInfo;

struct StringFileInfo {
    word wLength;
    word wValueLength;
    word wType;
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

typedef struct StringTable StringTable, *PStringTable;

struct StringTable {
    word wLength;
    word wValueLength;
    word wType;
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

typedef struct VS_VERSION_INFO VS_VERSION_INFO, *PVS_VERSION_INFO;

struct VS_VERSION_INFO {
    word StructLength;
    word ValueLength;
    word StructType;
    wchar16 Info[16];
    byte Padding[2];
    dword Signature;
    word StructVersion[2];
    word FileVersion[4];
    word ProductVersion[4];
    dword FileFlagsMask[2];
    dword FileFlags;
    dword FileOS;
    dword FileType;
    dword FileSubtype;
    dword FileTimestamp;
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

typedef struct VarFileInfo VarFileInfo, *PVarFileInfo;

struct VarFileInfo {
    word wLength;
    word wValueLength;
    word wType;
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

typedef struct StringInfo StringInfo, *PStringInfo;

struct StringInfo {
    word wLength;
    word wValueLength;
    word wType;
};

typedef ACCESS_MASK REGSAM;

typedef LONG LSTATUS;

typedef int (*_onexit_t)(void);




undefined4 thunk_FUN_10023c58(undefined4 arg1,short arg2);
void thunk_FUN_10012943(void);
undefined4 thunk_FUN_1000ad0b(void);
undefined4 * thunk_FUN_100034d0(undefined4 *arg_1,int y,int width,int height);
uint thunk_FUN_10010980(uint arg_1);
void thunk_FUN_10027b96(undefined4 arg1,undefined4 arg2);
void thunk_FUN_10024243(void);
bool thunk_FUN_1000c470(void);
void thunk_FUN_1001f340(HDC hdc,undefined4 *arg_2,uint arg_3);
undefined4 thunk_FUN_1000d64e(int arg1,int arg2);
void thunk_FUN_10020a41(HDC hdc,int *y,int width,int height);
int thunk_FUN_100327b1(char *str_1,char *str_2,int arg_3);
undefined4 thunk_FUN_1001f009(int arg_1,int *arg_2,int arg_3,int arg_4,int arg_5);
void thunk_FUN_10009244(void);
undefined4 thunk_FUN_100337ea(HWND hwnd,uint y,HWND param_3,undefined4 arg_4);
void thunk_FUN_100241f0(void);
int thunk_FUN_1000e9d4(int *arg_1);
void thunk_FUN_10023e33(byte arg_1);
void thunk_FUN_1003c9e0(void);
undefined4 thunk_FUN_1001ae07(HDC hdc,int *arg_2,undefined4 *arg_3,int arg_4,uint arg_5,int arg_6);
undefined4 thunk_FUN_100336c9(HWND hwnd,int arg_2,int arg_3);
bool thunk_FUN_10034670(void);
void thunk_FUN_1003239b(void);
undefined4 * thunk_FUN_10001f20(int arg_1,char *str_2,int arg_3);
undefined4 thunk_FUN_100129a2(LPCSTR str_1,HWND hwnd);
undefined4 thunk_FUN_10014828(char *str_1);
int thunk_FUN_100298f0(char *str_1);
void thunk_FUN_10027181(void);
undefined4 thunk_FUN_100241ba(void);
void thunk_FUN_10012ca3(void);
HBITMAP thunk_FUN_10031cb7(BITMAPINFO *arg1,void *arg2);
undefined4 thunk_FUN_100109a0(undefined4 arg1,undefined4 arg2);
undefined4 thunk_FUN_1003b524(undefined4 arg1,undefined4 arg2);
undefined4 thunk_FUN_1002389f(void *arg_1);
void thunk_FUN_100129f0(void);
int thunk_FUN_10028a10(WPARAM arg_1,int arg_2,int width,int height);
undefined4 thunk_FUN_10029386(int x,int arg_2,int width,int height);
uint thunk_FUN_10039c49(int arg_1);
undefined1 *thunk_FUN_10002e20(undefined1 *arg_1,int *arg_2,int arg_3,int arg_4,int *arg_5,int *arg_6,int arg_7,undefined4 arg_8,int arg_9);
undefined4 thunk_FUN_10027335(char *str_1);
void thunk_FUN_1001f83a(HDC hdc,int *arg_2,char *str_3,int arg_4,int arg_5);
void thunk_FUN_10031425(HDC hdc);
void thunk_FUN_10016850(int x,int y,int width,char *str_4);
void thunk_FUN_10037627(HWND hwnd,HWND param_2);
int thunk_FUN_1002929b(HDC hdc,RECT *arg_2,int width,int height);
void thunk_FUN_10032562(char *str_1,char *str_2,int width,char *str_4);
void thunk_FUN_100392dc(int x,int y,int width,int height);
void thunk_FUN_10218484(undefined4 arg1,uint arg2);
bool thunk_FUN_10024410(void);
int thunk_FUN_10016060(int *arg_1,uint *arg_2,int arg_3);
void thunk_FUN_10020dbf(undefined4 arg1,undefined4 arg2);
int thunk_FUN_10023e82(char arg_1,char *str_2,int arg_3);
undefined4 thunk_FUN_1003ac8b(int arg_1,undefined4 arg_2,undefined4 arg_3,char *str_4,undefined1 *arg_5);
undefined4 thunk_FUN_10010a1f(undefined4 arg_1);
undefined4 thunk_FUN_1001772e(undefined4 arg1,char *str_2);
int thunk_FUN_10013b53(HDC hdc,RECT *arg_2,int width,int height);
void thunk_FUN_1003c03a(HDC hdc,int arg_2,int arg_3,int arg_4,int arg_5,HGDIOBJ arg_6);
int thunk_FUN_1000dd80(char *str_1);
void thunk_FUN_1002140e(char *str_1,char *str_2,int arg_3);
undefined4 thunk_FUN_10015a50(int arg_1);
void thunk_FUN_100101e4(void);
undefined4 thunk_FUN_1000f6ef(int arg1,int arg2);
undefined4 thunk_FUN_10017444(int arg1,int arg2);
undefined4 thunk_FUN_100242a8(void);
undefined4 thunk_FUN_100241de(void);
undefined4 thunk_FUN_1002431f(void);
undefined4 thunk_FUN_1001162f(void);
void thunk_FUN_1003a490(void);
undefined4 thunk_FUN_1000e6cc(void);
undefined4 thunk_FUN_1000e8f4(undefined4 *arg_1,char *str_2,undefined4 arg_3);
void thunk_FUN_10013cd0(int arg1,int arg2);
void thunk_FUN_100084ce(HWND hwnd);
undefined4 thunk_FUN_1000b097(void);
void thunk_FUN_100391f0(int arg_1,int arg_2,int arg_3);
int thunk_FUN_1003afa3(char *str_1);
undefined4 thunk_FUN_10024296(void);
int thunk_FUN_1003724f(int arg_1);
int thunk_FUN_1003b2b0(int arg_1,undefined4 arg_2,uint arg_3);
undefined4 thunk_FUN_10011447(int *arg_1);
void thunk_FUN_1001f5d7(LPRECT arg_1,uint y,int *width,uint height);
void thunk_FUN_1001ad0b(HDC hdc,RECT *arg2);
undefined * thunk_FUN_10029205(int arg1,int arg2);
undefined4 thunk_FUN_10004070(void);
void thunk_FUN_1003c467(HDC hdc,int arg_2,int arg_3,int *arg_4,int *arg_5,int *arg_6,int *arg_7);
uint thunk_FUN_10034390(int arg_1,int arg_2,int arg_3,int arg_4,int arg_5);
void thunk_FUN_1000880b(void);
undefined4 thunk_FUN_100318f9(HDC arg_1,int *arg_2,HANDLE arg_3);
void thunk_FUN_1001e9d2(LPRECT arg1,int *arg2);
bool thunk_FUN_10031350(void);
undefined4 thunk_FUN_1003b840(undefined4 arg1,undefined4 arg2);
void thunk_FUN_1000f6ae(undefined4 *arg1,int arg2);
void thunk_FUN_100315fc(HDC hdc,HGDIOBJ arg2);
undefined4 thunk_FUN_1002ed06(int arg_1);
void thunk_FUN_1003bade(void);
uint thunk_FUN_10034b40(char *str_1,char *str_2);
undefined4 thunk_FUN_1000eae7(void);
undefined4 thunk_FUN_1002433c(void);
undefined4 thunk_FUN_1002c0c7(int *arg_1,int arg_2,LPRECT arg_3);
undefined4 thunk_FUN_10031474(undefined4 arg_1,int arg_2,undefined4 *arg_3,BITMAPINFO *arg_4,undefined4 *arg_5,undefined4 *arg_6,int *arg_7);
int thunk_FUN_10008085(int arg_1,int arg_2,POINT *arg_3);
undefined4 thunk_FUN_1001cb7b(HDC hdc,int arg_2,int arg_3);
undefined4 thunk_FUN_10019440(void);
void thunk_FUN_1000ce3f(HWND hwnd,int arg_2,int arg_3,int arg_4,int arg_5);
void thunk_FUN_10002a60(int *arg_1,int arg_2,int arg_3);
uint thunk_FUN_1003378c(int arg_1);
int thunk_FUN_1001c3ea(int *arg1,char *str_2);
void thunk_FUN_1003c100(HDC hdc,undefined4 arg_2,int arg_3,int arg_4,int arg_5,int arg_6,int arg_7);
int thunk_FUN_10027871(void);
undefined4 thunk_FUN_1000ebea(uint arg_1);
undefined4 thunk_FUN_10018411(int arg_1);
undefined4 thunk_FUN_1003197a(HDC hdc,int *arg_2,HANDLE arg_3,int arg_4,int arg_5,int arg_6,int arg_7,int arg_8,int arg_9);
undefined4 thunk_FUN_10028def(WPARAM arg_1,undefined4 arg_2,int width,int height);
undefined4 thunk_FUN_1002e012(HWND hwnd,LONG arg_2,LONG arg_3);
void thunk_FUN_10032018(HANDLE arg_1);
undefined4 thunk_FUN_100182b4(undefined4 arg1,int arg2);
undefined4 thunk_FUN_10024231(void);
void thunk_FUN_100395de(int arg_1,int arg_2,int arg_3);
void thunk_FUN_1002e884(void);
void thunk_FUN_10024180(void);
void thunk_FUN_1002c220(HDC hdc,int *y,LPRECT arg_3,int height);
undefined2 * thunk_FUN_1000e474(char *str_1,char *str_2);
undefined4 thunk_FUN_100242c5(void);
void thunk_FUN_1002c4d3(HDC hdc,int *y,undefined4 arg_3,int height);
undefined4 thunk_FUN_10024260(void);
void thunk_FUN_1000842b(HWND hwnd,int arg2);
undefined4 thunk_FUN_10031af5(undefined4 arg_1,LPCSTR str_2,void *arg_3);
void thunk_FUN_100095ec(void);
undefined4 thunk_FUN_1000d754(int arg_1);
HWND thunk_FUN_1000833a(HWND hwnd,int arg2);
void thunk_FUN_100242ba(void);
undefined4 thunk_FUN_10017128(int arg_1);
void thunk_FUN_10020d38(undefined4 arg1,undefined4 arg2);
undefined4 thunk_FUN_10017926(int arg_1);
undefined4 thunk_FUN_10024272(void);
undefined4 thunk_FUN_1000ef86(uint *x,int y,int width,int height);
void * thunk_FUN_1000e0da(int arg1,byte *arg2);
undefined4 thunk_FUN_100241fb(void);
void thunk_FUN_1001c8d1(HDC hdc,char arg_2,int arg_3,int arg_4,int arg_5,int arg_6);
undefined4 thunk_FUN_100242fb(void);
void thunk_FUN_1003798a(HWND hwnd,HWND param_2);
undefined4 thunk_FUN_1000bb7d(void);
void thunk_FUN_1000ea83(uint arg1,uint *arg2);
void __fastcall thunk_FUN_10218000(undefined4 arg_1,undefined4 arg_2,ushort *arg_3);
bool thunk_FUN_100091bd(HWND hwnd,LPVOID arg_2,WPARAM arg_3);
bool thunk_FUN_1003336e(HWND hwnd);
undefined4 thunk_FUN_100179ce(undefined4 arg1,int arg2);
LRESULT thunk_FUN_1001429f(char *str_1);
undefined4 thunk_FUN_10024372(void);
int thunk_FUN_10013ae3(int x,int arg_2,int width,int height);
undefined4 thunk_FUN_1002434e(void);
void thunk_FUN_10003410(undefined4 arg_1,int arg_2,int arg_3);
int thunk_FUN_1000eef0(int *arg1,int *arg2);
void thunk_FUN_1003b0ec(void);
int thunk_FUN_1001477a(FILE *fp,undefined1 *arg2);
void thunk_FUN_1000d7b5(void);
undefined4 thunk_FUN_100211be(int arg_1);
char * thunk_FUN_1002a529(undefined4 *arg_1);
undefined8 * thunk_FUN_10002360(int *arg1,undefined8 *arg2);
void thunk_FUN_1000852a(HWND hwnd,int *arg2);
bool thunk_FUN_1002a940(void);
undefined4 thunk_FUN_10037c37(HWND hwnd,int arg_2,int arg_3);
undefined4 thunk_FUN_10023d1d(byte *arg1,int arg2);
undefined4 thunk_FUN_1003162f(int arg_1,int arg_2,HANDLE arg_3);
int thunk_FUN_1000f104(int arg_1,int arg_2,uint *arg_3,int arg_4,int arg_5,int arg_6);
void thunk_FUN_1003b0f7(void);
int thunk_FUN_1001c315(HDC hdc,char *str_2);
undefined4 thunk_FUN_1001ecca(HDC hdc,int y,int width,int height);
void thunk_FUN_100029d0(undefined8 *arg_1,uint arg_2,uint arg_3);
undefined4 thunk_FUN_100030e0(undefined4 *arg1,int *arg2);
undefined4 thunk_FUN_10023a88(byte *arg_1);
bool thunk_FUN_1001138a(void);
undefined4 thunk_FUN_100372c5(HWND hwnd,int arg_2,LPRECT arg_3);
undefined4 thunk_FUN_1002e9bb(int arg_1);
void thunk_FUN_10027adb(undefined4 arg_1,int arg_2,int arg_3);
void thunk_FUN_1001ee4b(LPRECT arg_1,int *arg_2,int arg_3);
void thunk_FUN_1001e1a3(HDC hdc,RECT *arg_2,int arg_3);
undefined4 thunk_FUN_1001e87a(HDC hdc,int *arg_2,undefined4 arg_3);
void thunk_FUN_10032bd7(int arg_1,HBRUSH arg_2,HGDIOBJ arg_3,HGDIOBJ arg_4,COLORREF arg_5,int arg_6);
void thunk_FUN_10019f35(void);
uint thunk_FUN_1001cbfc(HDC hdc,int *y,char *str_3,int height);
int thunk_FUN_10013760(WPARAM arg_1,int y,int width,int height);
HWND thunk_FUN_100083a9(HWND hwnd,int arg_2,int arg_3);
uint * thunk_FUN_100037d0(void);
int thunk_FUN_1000e7bd(int *arg_1);
undefined4 thunk_FUN_100174ee(int arg1,int arg2);
uint thunk_FUN_1000ed78(uint arg_1);
undefined4 thunk_FUN_10024360(void);
void thunk_FUN_1000e73e(int *arg_1,int arg_2,int *arg_3);
void thunk_FUN_100272be(int arg_1,int arg_2,int *arg_3);
int thunk_FUN_10016b40(int arg_1);
undefined4 thunk_FUN_1001a9ec(int *arg_1);
undefined4 thunk_FUN_1003b4c3(undefined4 arg_1);
void thunk_FUN_100313ad(void);
undefined4 thunk_FUN_10010cda(void);
void thunk_FUN_10024331(void);
undefined4 thunk_FUN_100242d7(void);
undefined4 thunk_FUN_1000b79e(void);
void thunk_FUN_1000950c(void);
void thunk_FUN_10034510(int arg_1,int arg_2,int arg_3,int arg_4,int arg_5,undefined4 arg_6);
undefined4 thunk_FUN_10017624(int arg1,int arg2);
undefined4 thunk_FUN_1003b5b2(undefined4 arg_1);
int thunk_FUN_10013e94(int arg_1,int arg_2,int arg_3);
void thunk_FUN_10029435(int arg1,int arg2);
void thunk_FUN_10012141(void);
undefined4 thunk_FUN_100241a8(void);
void thunk_FUN_100210e3(LPRECT arg1,int *arg2);
void thunk_FUN_1001e527(HDC hdc,int *y,uint width,uint height);
void thunk_FUN_1000862d(HWND hwnd,int arg_2,int arg_3);
void thunk_FUN_10028f03(int arg_1);
undefined4 thunk_FUN_10023ee1(void *arg_1);
void thunk_FUN_10027036(void);
void thunk_FUN_1002418b(void);
void thunk_FUN_10012740(void);
undefined4 thunk_FUN_100242e9(void);
void thunk_FUN_10002d30(int *arg_1,int *arg_2,int *arg_3,int arg_4,int arg_5,undefined4 arg_6,int arg_7);
undefined4 thunk_FUN_1002421f(void);
void thunk_FUN_1001df0d(HDC hdc,RECT *arg_2,WPARAM *arg_3,int arg_4,int arg_5);
void thunk_FUN_10013e46(void);
undefined4 thunk_FUN_1003b487(undefined4 arg_1,undefined4 arg_2,undefined4 arg_3);
undefined4 thunk_FUN_10028c81(int arg1,int arg2);
undefined4 thunk_FUN_10002340(void);
undefined4 thunk_FUN_1002430d(void);
undefined4 thunk_FUN_1001787e(int arg_1);
int thunk_FUN_10018360(char *str_1,int arg2);
void thunk_FUN_1002c7e8(HDC hdc,undefined4 arg_2,undefined4 arg_3,int arg_4,int arg_5);
undefined * thunk_FUN_10013a4c(int arg1,int arg2);
void thunk_FUN_1001c0c3(HDC hdc,int arg_2,uint arg_3);
undefined4 thunk_FUN_100320aa(void);
undefined4 thunk_FUN_1002420d(void);
undefined4 thunk_FUN_10024284(void);
int thunk_FUN_10015770(uint *arg_1,undefined4 arg_2,undefined4 arg_3);
void thunk_FUN_1002e266(void);
uint thunk_FUN_1000e202(byte *arg_1);
undefined4 thunk_FUN_1002cf32(undefined4 arg_1);
void thunk_FUN_1001c251(HDC hdc,int arg_2,char *str_3);
undefined4 thunk_FUN_100147ed(char *str_1);
undefined4 thunk_FUN_1000d510(int arg1,int arg2);
undefined4 thunk_FUN_10017aa2(undefined4 arg_1,int arg_2,int arg_3);
undefined4 thunk_FUN_1002424e(void);
bool thunk_FUN_10018af0(void);
void thunk_FUN_10023560(undefined4 *arg_1,undefined4 arg_2,int arg_3);
void thunk_FUN_10027a00(void);
undefined4 thunk_FUN_10017566(int arg1,int arg2);
void thunk_FUN_1003b411(void);
void * thunk_FUN_1000e440(void);
bool thunk_FUN_100350c9(void);
void thunk_FUN_10039fb5(int arg1,byte arg2);
WPARAM DeckBuilderMain(HWND hwnd,uint arg_2,undefined4 arg_3);
bool thunk_FUN_10030df0(void);
undefined4 thunk_FUN_10031697(HDC hdc,int *arg_2,HANDLE arg_3,int arg_4,int arg_5,int arg_6,int arg_7);
undefined4 thunk_FUN_1002d55f(HWND hwnd,undefined4 arg_2,uint arg_3);
void thunk_FUN_1000849a(HWND hwnd);
size_t thunk_FUN_1000e156(int arg_1,undefined4 arg_2,int *arg_3);
uint thunk_FUN_1001c5f1(HDC hdc,int arg_2,int arg_3,LONG arg_4,char *str_5);
void thunk_FUN_10014a60(undefined8 *arg1,uint arg2);
int thunk_FUN_10038346(int arg_1);
void thunk_FUN_10027a61(undefined4 arg_1,int y,int width,int height);
void thunk_FUN_100331dc(HWND hwnd);
undefined * thunk_FUN_100333bb(char *str_1,int arg2);
void thunk_FUN_100397d0(int x,int y,int width,int height);
undefined4 thunk_FUN_100034b0(void *arg_1);
int thunk_FUN_10028f53(WPARAM arg_1,int y,int width,int height);
undefined4 thunk_FUN_100241cc(void);
void thunk_FUN_10037837(HWND hwnd,HWND param_2);
void thunk_FUN_10007dbf(HDC hdc,RECT *arg_2,char *str_3);
undefined4 thunk_FUN_100127ad(void);
undefined4 thunk_FUN_1000ac70(void);
undefined4 thunk_FUN_10024196(void);
void thunk_FUN_10039a61(int x,int y,int width,int height);
undefined4 thunk_FUN_10014100(char *str_1);
int thunk_FUN_10033646(int arg1,int arg2);
void thunk_FUN_100093a8(void);
void thunk_FUN_100278e9(void);
undefined4 thunk_FUN_1000fc9e(int arg_1,int arg_2,int arg_3,int arg_4,int arg_5,int arg_6);
int thunk_FUN_10028d12(HDC hdc,RECT *arg_2,int width,int height);
undefined * thunk_FUN_1003aa60(int arg_1,int arg_2,int arg_3);
void thunk_FUN_1003947f(int x,int y,undefined4 arg_3,int height);
undefined4 * DeckDll_LoadCardArtCatalogs(int arg_1,char *str_2,int arg_3);
undefined4 DeckDll_ReleaseCardArtCatalogs(void);
undefined8 * DeckDll_DecompressHaarWavelet(int *arg1,undefined8 *arg2);
void FUN_1000282a(void);
void FUN_10002990(undefined8 *arg_1,undefined8 *arg_2,uint arg_3);
void FUN_100029d0(undefined8 *arg_1,uint arg_2,uint arg_3);
void FUN_10002a60(int *arg_1,int arg_2,int arg_3);
void FUN_10002a6b(void);
void FUN_10002c7a(int arg_1,undefined4 arg_2,int *arg_3,int *arg_4,int *arg_5,int arg_6,undefined4 arg_7,undefined4 arg_8,int arg_9);
void FUN_10002d30(int *arg_1,int *arg_2,int *arg_3,int arg_4,int arg_5,undefined4 arg_6,int arg_7);
void FUN_10002d3a(int arg_1,undefined4 arg_2,int *arg_3,int *arg_4,int *arg_5,int arg_6,undefined4 arg_7,undefined4 arg_8,int arg_9);
undefined1 *FUN_10002e20(undefined1 *arg_1,int *arg_2,int arg_3,int arg_4,int *arg_5,int *arg_6,int arg_7,undefined4 arg_8,int arg_9);
undefined1 * FUN_10002e2b(void);
undefined4 FUN_100030e0(undefined4 *arg1,int *arg2);
undefined4 DeckDll_RenderCardPreview(HWND hwnd);
int DeckDll_BlitCardArtwork(HWND hwnd,void *arg_2,int arg_3,int arg_4,DWORD arg_5,DWORD arg_6);
void FUN_10003410(undefined4 arg_1,int arg_2,int arg_3);
undefined4 FUN_100034b0(void *arg_1);
undefined4 * FUN_100034d0(undefined4 *arg_1,int y,int width,int height);
undefined4 FUN_1000370a(undefined4 arg_1,HWND hwnd,undefined4 arg_3,DWORD arg_4,DWORD arg_5);
uint * FUN_100037d0(void);
undefined4 FUN_10003d80(HWND hwnd,int y,DWORD arg_3,DWORD arg_4);
int FUN_10003f00(HWND hwnd,int arg_2,int arg_3,int arg_4,DWORD arg_5,DWORD arg_6);
undefined4 DeckDll_RegisterWindowClasses(void);
LRESULT FUN_100041e7(HWND hwnd,uint y,HDC hdc,uint height);
LRESULT FUN_1000590d(HWND hwnd,uint y,HDC hdc,uint height);
LRESULT FUN_10006d68(HWND hwnd,uint y,HDC hdc,uint height);
void FUN_10007dbf(HDC hdc,RECT *arg_2,char *str_3);
int FUN_10008085(int arg_1,int arg_2,POINT *arg_3);
HWND FUN_1000833a(HWND hwnd,int arg2);
HWND FUN_100083a9(HWND hwnd,int arg_2,int arg_3);
void FUN_1000842b(HWND hwnd,int arg2);
void FUN_1000849a(HWND hwnd);
void FUN_100084ce(HWND hwnd);
void FUN_1000852a(HWND hwnd,int *arg2);
void FUN_1000862d(HWND hwnd,int arg_2,int arg_3);
void FUN_1000880b(void);
bool FUN_100091bd(HWND hwnd,LPVOID arg_2,WPARAM arg_3);
void FUN_10009244(void);
void FUN_100093a8(void);
void FUN_1000950c(void);
void FUN_100095ec(void);
undefined4 FUN_1000ac70(void);
undefined4 FUN_1000ad0b(void);
HGDIOBJ FUN_1000ada6(HWND hwnd,uint y,HDC hdc,undefined4 arg_4);
undefined4 FUN_1000b097(void);
HGDIOBJ FUN_1000b123(HWND hwnd,uint y,HDC hdc,undefined4 arg_4);
undefined4 FUN_1000b79e(void);
HGDIOBJ FUN_1000b82a(HWND hwnd,uint y,HDC hdc,undefined4 arg_4);
undefined4 FUN_1000bb7d(void);
HGDIOBJ FUN_1000bc09(HWND hwnd,uint y,HDC hdc,undefined4 arg_4);
bool FUN_1000c470(void);
uint FUN_1000c4fe(HWND hwnd,uint y,uint width,LONG *arg_4);
void FUN_1000ce3f(HWND hwnd,int arg_2,int arg_3,int arg_4,int arg_5);
undefined4 FUN_1000d510(int arg1,int arg2);
undefined4 FUN_1000d64e(int arg1,int arg2);
undefined4 FUN_1000d754(int arg_1);
void FUN_1000d7b5(void);
int FUN_1000dd80(char *str_1);
bool FUN_1000dfcc(int arg_1);
undefined4 FUN_1000e08a(int *arg1,int *arg2);
void * FUN_1000e0da(int arg1,byte *arg2);
size_t FUN_1000e156(int arg_1,undefined4 arg_2,int *arg_3);
uint FUN_1000e202(byte *arg_1);
void * FUN_1000e440(void);
undefined2 * FUN_1000e474(char *str_1,char *str_2);
undefined4 FUN_1000e6cc(void);
void FUN_1000e73e(int *arg_1,int arg_2,int *arg_3);
int FUN_1000e7bd(int *arg_1);
undefined4 FUN_1000e8f4(undefined4 *arg_1,char *str_2,undefined4 arg_3);
int FUN_1000e9d4(int *arg_1);
void FUN_1000ea83(uint arg1,uint *arg2);
undefined4 FUN_1000eae7(void);
undefined4 FUN_1000ebea(uint arg_1);
uint FUN_1000ed78(uint arg_1);
int FUN_1000eef0(int *arg1,int *arg2);
undefined4 FUN_1000ef86(uint *x,int y,int width,int height);
undefined4 FUN_1000f01e(uint *x,int y,int width,int height);
int FUN_1000f104(int arg_1,int arg_2,uint *arg_3,int arg_4,int arg_5,int arg_6);
void FUN_1000f6ae(undefined4 *arg1,int arg2);
undefined4 FUN_1000f6ef(int arg1,int arg2);
undefined4 FUN_1000f877(int arg_1,byte *arg_2,int arg_3,int arg_4,int arg_5);
undefined4 FUN_1000fc9e(int arg_1,int arg_2,int arg_3,int arg_4,int arg_5,int arg_6);
void FUN_100101e4(void);
uint FUN_10010980(uint arg_1);
undefined4 FUN_100109a0(undefined4 arg1,undefined4 arg2);
undefined4 FUN_10010a1f(undefined4 arg_1);
undefined4 FUN_10010cda(void);
WPARAM FUN_10010e1f(HWND hwnd,uint arg_2,undefined4 arg_3);
bool FUN_1001138a(void);
undefined4 FUN_10011447(int *arg_1);
undefined4 FUN_1001162f(void);
void FUN_10012141(void);
undefined4 FUN_10012548(void);
void FUN_10012740(void);
undefined4 FUN_100127ad(void);
void FUN_10012943(void);
undefined4 FUN_100129a2(LPCSTR str_1,HWND hwnd);
void FUN_100129f0(void);
void FUN_10012ca3(void);
int FUN_10013760(WPARAM arg_1,int y,int width,int height);
undefined * FUN_10013a4c(int arg1,int arg2);
int FUN_10013ae3(int x,int arg_2,int width,int height);
int FUN_10013b53(HDC hdc,RECT *arg_2,int width,int height);
undefined4 FUN_10013c3f(WPARAM arg_1,int y,int width,int height);
void FUN_10013cd0(int arg1,int arg2);
void FUN_10013e46(void);
int FUN_10013e94(int arg_1,int arg_2,int arg_3);
undefined4 FUN_10014100(char *str_1);
LRESULT FUN_1001429f(char *str_1);
int FUN_1001477a(FILE *fp,undefined1 *arg2);
undefined4 FUN_100147ed(char *str_1);
undefined4 FUN_10014828(char *str_1);
void FUN_10014a60(undefined8 *arg1,uint arg2);
int FUN_10015770(uint *arg_1,undefined4 arg_2,undefined4 arg_3);
undefined4 FUN_10015a50(int arg_1);
undefined4 __thiscall FUN_10015ce1(void *this);
int FUN_10015df0(undefined4 *arg_1,uint *arg_2,int arg_3);
int FUN_10016060(int *arg_1,uint *arg_2,int arg_3);
void FUN_10016850(int x,int y,int width,char *str_4);
void FUN_10016980(int x,int y,int width,char *str_4);
int FUN_10016b40(int arg_1);
undefined4 FUN_10017128(int arg_1);
undefined4 FUN_10017192(undefined4 arg_1,int arg_2,int arg_3);
undefined4 FUN_10017444(int arg1,int arg2);
undefined4 FUN_100174ee(int arg1,int arg2);
undefined4 FUN_10017566(int arg1,int arg2);
undefined4 FUN_10017624(int arg1,int arg2);
undefined4 FUN_1001772e(undefined4 arg1,char *str_2);
undefined4 FUN_1001787e(int arg_1);
undefined4 FUN_10017926(int arg_1);
undefined4 FUN_100179ce(undefined4 arg1,int arg2);
undefined4 FUN_10017aa2(undefined4 arg_1,int arg_2,int arg_3);
undefined4 FUN_100182b4(undefined4 arg1,int arg2);
int FUN_10018360(char *str_1,int arg2);
undefined4 FUN_10018411(int arg_1);
bool FUN_10018af0(void);
uint FUN_10018b75(HWND hwnd,uint y,uint width,uint height);
void FUN_10019002(HDC hdc,int arg_2,int arg_3);
void FUN_1001911d(HWND hwnd,POINT *arg_2,int arg_3);
undefined4 FUN_10019440(void);
void FUN_10019f35(void);
void FUN_1001a747(void);
undefined4 FUN_1001a9ec(int *arg_1);
void FUN_1001ad0b(HDC hdc,RECT *arg2);
undefined4 FUN_1001ae07(HDC hdc,int *arg_2,undefined4 *arg_3,int arg_4,uint arg_5,int arg_6);
undefined4 FUN_1001be83(HDC hdc,int *arg_2,int arg_3,int arg_4,int arg_5,uint arg_6,int arg_7);
void FUN_1001c0c3(HDC hdc,int arg_2,uint arg_3);
void FUN_1001c251(HDC hdc,int arg_2,char *str_3);
int FUN_1001c315(HDC hdc,char *str_2);
int FUN_1001c3ea(int *arg1,char *str_2);
uint FUN_1001c5f1(HDC hdc,int arg_2,int arg_3,LONG arg_4,char *str_5);
void FUN_1001c8d1(HDC hdc,char arg_2,int arg_3,int arg_4,int arg_5,int arg_6);
undefined4 FUN_1001cb7b(HDC hdc,int arg_2,int arg_3);
uint FUN_1001cbfc(HDC hdc,int *y,char *str_3,int height);
void FUN_1001d236(HDC hdc,RECT *arg_2,undefined4 arg_3,undefined4 arg_4);
void FUN_1001d3e9(HDC hdc,int *arg_2,int arg_3,undefined4 arg_4,undefined4 arg_5);
void FUN_1001df0d(HDC hdc,RECT *arg_2,WPARAM *arg_3,int arg_4,int arg_5);
void FUN_1001e1a3(HDC hdc,RECT *arg_2,int arg_3);
void FUN_1001e527(HDC hdc,int *y,uint width,uint height);
void FUN_1001e711(HDC hdc,int *arg_2,undefined4 arg_3);
undefined4 FUN_1001e87a(HDC hdc,int *arg_2,undefined4 arg_3);
void FUN_1001e9d2(LPRECT arg1,int *arg2);
void FUN_1001eaa6(HDC hdc,int *arg_2,int arg_3,int arg_4,int arg_5);
undefined4 FUN_1001ecca(HDC hdc,int y,int width,int height);
void FUN_1001ee4b(LPRECT arg_1,int *arg_2,int arg_3);
undefined4 FUN_1001f009(int arg_1,int *arg_2,int arg_3,int arg_4,int arg_5);
void FUN_1001f340(HDC hdc,undefined4 *arg_2,uint arg_3);
void FUN_1001f5d7(LPRECT arg_1,uint y,int *width,uint height);
void FUN_1001f83a(HDC hdc,int *arg_2,char *str_3,int arg_4,int arg_5);
void FUN_1001f9f7(HDC hdc,int *arg_2,int arg_3,undefined4 arg_4,int arg_5);
void FUN_1001fb9f(HDC hdc,RECT *arg_2,int arg_3,int arg_4,int arg_5);
void FUN_100201a4(HDC hdc,RECT *arg_2,int arg_3,int arg_4,undefined4 arg_5,int arg_6,int arg_7);
void FUN_10020449(HDC hdc,RECT *arg_2,int width,int height);
void FUN_10020a41(HDC hdc,int *y,int width,int height);
void FUN_10020d38(undefined4 arg1,undefined4 arg2);
void FUN_10020dbf(undefined4 arg1,undefined4 arg2);
void FUN_10020e46(HDC hdc,int *arg2);
uint FUN_10020edf(HDC hdc,int *y,int width,int height);
void FUN_10021005(HDC hdc,int *arg_2,int arg_3);
void FUN_1002109b(undefined4 arg_1,int *arg_2,byte arg_3);
void FUN_100210e3(LPRECT arg1,int *arg2);
undefined4 FUN_100211be(int arg_1);
void FUN_1002140e(char *str_1,char *str_2,int arg_3);
void FUN_1002151c(void);
void FUN_10023560(undefined4 *arg_1,undefined4 arg_2,int arg_3);
undefined1 * FUN_10023600(char *str_1,undefined1 *arg_2,void *arg_3);
bool FUN_1002381a(char *str_1,void *arg2);
undefined4 FUN_1002389f(void *arg_1);
undefined4 FUN_10023a88(byte *arg_1);
undefined4 FUN_10023b66(undefined4 arg_1,char *str_2,void *arg_3,undefined4 arg_4,undefined4 arg_5,int arg_6,int arg_7);
undefined4 FUN_10023c58(undefined4 arg1,short arg2);
undefined4 FUN_10023d1d(byte *arg1,int arg2);
void FUN_10023e33(byte arg_1);
int FUN_10023e82(char arg_1,char *str_2,int arg_3);
undefined4 FUN_10023ee1(void *arg_1);
void FUN_10024180(void);
void FUN_1002418b(void);
undefined4 FUN_10024196(void);
undefined4 FUN_100241a8(void);
undefined4 FUN_100241ba(void);
undefined4 FUN_100241cc(void);
undefined4 FUN_100241de(void);
void FUN_100241f0(void);
undefined4 FUN_100241fb(void);
undefined4 FUN_1002420d(void);
undefined4 FUN_1002421f(void);
undefined4 FUN_10024231(void);
void FUN_10024243(void);
undefined4 FUN_1002424e(void);
undefined4 FUN_10024260(void);
undefined4 FUN_10024272(void);
undefined4 FUN_10024284(void);
undefined4 FUN_10024296(void);
undefined4 FUN_100242a8(void);
void FUN_100242ba(void);
undefined4 FUN_100242c5(void);
undefined4 FUN_100242d7(void);
undefined4 FUN_100242e9(void);
undefined4 FUN_100242fb(void);
undefined4 FUN_1002430d(void);
undefined4 FUN_1002431f(void);
void FUN_10024331(void);
undefined4 FUN_1002433c(void);
undefined4 FUN_1002434e(void);
undefined4 FUN_10024360(void);
undefined4 FUN_10024372(void);
bool FUN_10024410(void);
HGDIOBJ FUN_1002449e(HWND hwnd,uint y,HDC hdc,HWND param_4);
void FUN_10027036(void);
void FUN_1002707c(undefined4 arg_1);
void FUN_10027181(void);
void FUN_100272be(int arg_1,int arg_2,int *arg_3);
undefined4 FUN_10027335(char *str_1);
HGDIOBJ FUN_100273d2(HWND hwnd,uint y,HDC hdc,undefined4 arg_4);
int FUN_10027871(void);
void FUN_100278e9(void);
void FUN_10027a00(void);
void FUN_10027a61(undefined4 arg_1,int y,int width,int height);
void FUN_10027adb(undefined4 arg_1,int arg_2,int arg_3);
void FUN_10027b3d(undefined4 arg_1,int arg_2,int arg_3);
void FUN_10027b96(undefined4 arg1,undefined4 arg2);
int FUN_10028a10(WPARAM arg_1,int arg_2,int width,int height);
undefined4 FUN_10028c81(int arg1,int arg2);
int FUN_10028d12(HDC hdc,RECT *arg_2,int width,int height);
undefined4 FUN_10028def(WPARAM arg_1,undefined4 arg_2,int width,int height);
void FUN_10028f03(int arg_1);
int FUN_10028f53(WPARAM arg_1,int y,int width,int height);
undefined * FUN_10029205(int arg1,int arg2);
int FUN_1002929b(HDC hdc,RECT *arg_2,int width,int height);
undefined4 FUN_10029386(int x,int arg_2,int width,int height);
void FUN_10029435(int arg1,int arg2);
void FUN_100295a9(void);
int FUN_100298f0(char *str_1);
void FUN_1002a272(void);
undefined4 FUN_1002a2a3(LPCSTR str_1);
void FUN_1002a4f8(void);
char * FUN_1002a529(undefined4 *arg_1);
bool FUN_1002a940(void);
LRESULT FUN_1002a9c5(HWND hwnd,uint y,HMENU arg_3,uint height);
undefined4 FUN_1002c0c7(int *arg_1,int arg_2,LPRECT arg_3);
void FUN_1002c220(HDC hdc,int *y,LPRECT arg_3,int height);
void FUN_1002c4d3(HDC hdc,int *y,undefined4 arg_3,int height);
void FUN_1002c7e8(HDC hdc,undefined4 arg_2,undefined4 arg_3,int arg_4,int arg_5);
undefined4 FUN_1002cf32(undefined4 arg_1);
undefined4 FUN_1002d55f(HWND hwnd,undefined4 arg_2,uint arg_3);
undefined4 FUN_1002e012(HWND hwnd,LONG arg_2,LONG arg_3);
void FUN_1002e266(void);
void FUN_1002e884(void);
undefined4 FUN_1002e9bb(int arg_1);
HGDIOBJ FUN_1002eab9(HWND hwnd,uint y,HDC hdc,undefined4 arg_4);
undefined4 FUN_1002ed06(int arg_1);
HGDIOBJ FUN_1002ee16(HWND hwnd,uint y,HDC hdc,undefined4 arg_4);
HGDIOBJ FUN_1002f3a3(HWND hwnd,uint y,HDC hdc,undefined4 arg_4);
bool FUN_10030df0(void);
LRESULT FUN_10030e7e(HWND hwnd,uint y,uint width,LPCSTR str_4);
bool FUN_10031350(void);
void FUN_100313ad(void);
void FUN_100313ee(char *str_1);
void FUN_10031425(HDC hdc);
undefined4 FUN_10031474(undefined4 arg_1,int arg_2,undefined4 *arg_3,BITMAPINFO *arg_4,undefined4 *arg_5,undefined4 *arg_6,int *arg_7);
void FUN_100315fc(HDC hdc,HGDIOBJ arg2);
undefined4 FUN_1003162f(int arg_1,int arg_2,HANDLE arg_3);
undefined4 FUN_10031697(HDC hdc,int *arg_2,HANDLE arg_3,int arg_4,int arg_5,int arg_6,int arg_7);
undefined4 FUN_100317e1(HDC hdc,int *arg_2,HANDLE arg_3);
undefined4 FUN_100318f9(HDC arg_1,int *arg_2,HANDLE arg_3);
undefined4 FUN_1003197a(HDC hdc,int *arg_2,HANDLE arg_3,int arg_4,int arg_5,int arg_6,int arg_7,int arg_8,int arg_9);
undefined4 FUN_10031af5(undefined4 arg_1,LPCSTR str_2,void *arg_3);
undefined4 FUN_10031bb6(LPCSTR str_1,void *arg2);
HBITMAP FUN_10031cb7(BITMAPINFO *arg1,void *arg2);
void FUN_10032018(HANDLE arg_1);
undefined4 FUN_100320aa(void);
void FUN_1003239b(void);
void FUN_100323c1(int arg_1,int arg_2,RECT *arg_3);
void FUN_10032562(char *str_1,char *str_2,int width,char *str_4);
int FUN_100327b1(char *str_1,char *str_2,int arg_3);
int FUN_10032983(HWND hwnd,char *str_2);
LRESULT FUN_10032a88(HWND hwnd,UINT y,WPARAM arg_3,LPARAM arg_4);
undefined4 FUN_10032b18(char *str_1,COLORREF arg_2,HBRUSH arg_3);
void FUN_10032bd7(int arg_1,HBRUSH arg_2,HGDIOBJ arg_3,HGDIOBJ arg_4,COLORREF arg_5,int arg_6);
void FUN_10032fa5(int arg_1,HANDLE arg_2,HANDLE arg_3,HANDLE arg_4,COLORREF arg_5,int arg_6);
void FUN_100331dc(HWND hwnd);
undefined4 FUN_100331f8(HWND hwnd);
LRESULT FUN_10033239(HWND hwnd,uint y,HWND param_3,LPARAM arg_4);
bool FUN_1003336e(HWND hwnd);
undefined * FUN_100333bb(char *str_1,int arg2);
void FUN_100334c7(void);
int FUN_10033646(int arg1,int arg2);
undefined4 FUN_100336c9(HWND hwnd,int arg_2,int arg_3);
uint FUN_1003378c(int arg_1);
undefined4 FUN_100337ea(HWND hwnd,uint y,HWND param_3,undefined4 arg_4);
undefined4 FUN_10033994(HWND hwnd,int *arg2);
uint FUN_10034390(int arg_1,int arg_2,int arg_3,int arg_4,int arg_5);
void FUN_10034510(int arg_1,int arg_2,int arg_3,int arg_4,int arg_5,undefined4 arg_6);
bool FUN_10034670(void);
LRESULT FUN_100346fd(HWND hwnd,uint y,HDC hdc,LPARAM arg_4);
uint FUN_10034b40(char *str_1,char *str_2);
LRESULT FUN_10034e70(HWND hwnd,uint y,uint width,LPARAM arg_4);
bool FUN_100350c9(void);
uint FUN_1003514e(HWND hwnd,uint y,uint width,uint height);
int FUN_1003724f(int arg_1);
undefined4 FUN_100372c5(HWND hwnd,int arg_2,LPRECT arg_3);
void FUN_100373af(HDC hdc,RECT *arg_2,WPARAM *arg_3,int height);
void FUN_10037627(HWND hwnd,HWND param_2);
void FUN_10037837(HWND hwnd,HWND param_2);
void FUN_1003798a(HWND hwnd,HWND param_2);
undefined4 FUN_10037c37(HWND hwnd,int arg_2,int arg_3);
int FUN_10038346(int arg_1);
void FUN_100391f0(int arg_1,int arg_2,int arg_3);
void FUN_100392dc(int x,int y,int width,int height);
void FUN_1003947f(int x,int y,undefined4 arg_3,int height);
void FUN_100395de(int arg_1,int arg_2,int arg_3);
void FUN_100397d0(int x,int y,int width,int height);
void FUN_10039a61(int x,int y,int width,int height);
uint FUN_10039c49(int arg_1);
void FUN_10039fb5(int arg1,byte arg2);
void FUN_1003a490(void);
undefined * FUN_1003aa60(int arg_1,int arg_2,int arg_3);
undefined4 FUN_1003ac8b(int arg_1,undefined4 arg_2,undefined4 arg_3,char *str_4,undefined1 *arg_5);
int FUN_1003afa3(char *str_1);
int FUN_1003b02a(char *str_1,int arg2);
void FUN_1003b05e(int arg_1);
void FUN_1003b089(undefined4 arg_1);
int FUN_1003b0b0(void);
void FUN_1003b0ec(void);
void FUN_1003b0f7(void);
int FUN_1003b2b0(int arg_1,undefined4 arg_2,uint arg_3);
void FUN_1003b411(void);
undefined4 FUN_1003b487(undefined4 arg_1,undefined4 arg_2,undefined4 arg_3);
undefined4 FUN_1003b4c3(undefined4 arg_1);
undefined4 FUN_1003b4f7(void);
undefined4 FUN_1003b524(undefined4 arg1,undefined4 arg2);
undefined4 FUN_1003b569(undefined4 arg_1,undefined4 arg_2,undefined4 arg_3);
undefined4 FUN_1003b5b2(undefined4 arg_1);
void FUN_1003b5f3(void);
undefined4 FUN_1003b623(undefined4 arg1,undefined4 arg2);
undefined4 FUN_1003b668(undefined4 arg1,undefined4 arg2);
undefined4 FUN_1003b6ad(undefined4 arg1,undefined4 arg2);
undefined4 FUN_1003b6f2(undefined4 arg1,undefined4 arg2);
undefined4 FUN_1003b737(undefined4 arg1,undefined4 arg2);
undefined4 FUN_1003b77c(undefined4 arg1,undefined4 arg2);
undefined4 FUN_1003b7c1(undefined4 arg1,undefined4 arg2);
undefined4 FUN_1003b806(void);
undefined4 FUN_1003b840(undefined4 arg1,undefined4 arg2);
undefined4 FUN_1003b885(undefined4 arg1,undefined4 arg2);
undefined4 FUN_1003b8ca(undefined4 arg_1);
undefined4 FUN_1003b90b(undefined4 arg1,undefined4 arg2);
undefined4 FUN_1003b950(undefined4 arg1,undefined4 arg2);
undefined4 FUN_1003b995(undefined4 arg1,undefined4 arg2);
undefined4 FUN_1003b9d7(undefined4 arg1,undefined4 arg2);
undefined4 FUN_1003ba1c(void);
undefined4 FUN_1003ba53(undefined4 arg1,undefined4 arg2);
undefined4 FUN_1003ba95(undefined4 arg_1,undefined4 arg_2,undefined4 arg_3);
void FUN_1003bade(void);
HGDIOBJ FUN_1003bd40(HWND hwnd,uint y,HDC hdc,undefined4 arg_4);
void FUN_1003c03a(HDC hdc,int arg_2,int arg_3,int arg_4,int arg_5,HGDIOBJ arg_6);
void FUN_1003c100(HDC hdc,undefined4 arg_2,int arg_3,int arg_4,int arg_5,int arg_6,int arg_7);
void FUN_1003c467(HDC hdc,int arg_2,int arg_3,int *arg_4,int *arg_5,int *arg_6,int *arg_7);
void FUN_1003c9e0(void);
longlong __fastcall __allshl(byte arg1,int arg2);
void FUN_1003d810(void);
char * __cdecl strcpy(char *str_1,char *str_2);
size_t __cdecl strlen(char *str_1);
int __cdecl abs(int arg_1);
int __cdecl strcmp(char *str_1,char *str_2);
char * __cdecl strcat(char *str_1,char *str_2);
void * __cdecl memset(void *ptr_1,int arg_2,size_t arg_3);
void * __cdecl memcpy(void *ptr_1,void *ptr_2,size_t arg_3);
longlong __allmul(uint x,int y,uint width,int height);
undefined4 __CRT_INIT@12(undefined4 arg1,int arg2);
int entry(undefined4 arg_1,int arg_2,undefined4 arg_3);
_onexit_t __onexit(_onexit_t arg_1);
int __cdecl _atexit(_func_4879 *ptr_1);
void __cdecl initterm(void);
void __dllonexit(void);
void __fastcall FUN_10218000(undefined4 arg_1,undefined4 arg_2,ushort *arg_3);
void __fastcall FUN_10218245(undefined4 arg1,undefined4 arg2);
void FUN_102182b5(void);
void __fastcall FUN_10218300(uint arg_1);
undefined4 __fastcall FUN_10218392(undefined4 arg_1,uint arg_2,undefined4 arg_3);
void FUN_10218484(undefined4 arg1,uint arg2);


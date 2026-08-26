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

typedef struct _OVERLAPPED *LPOVERLAPPED;

typedef DWORD (*PTHREAD_START_ROUTINE)(LPVOID);

typedef PTHREAD_START_ROUTINE LPTHREAD_START_ROUTINE;

typedef struct _SECURITY_ATTRIBUTES *LPSECURITY_ATTRIBUTES;

typedef struct _STARTUPINFOA _STARTUPINFOA, *P_STARTUPINFOA;

typedef char CHAR;

typedef CHAR *LPSTR;

typedef ushort WORD;

typedef uchar BYTE;

typedef BYTE *LPBYTE;

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

typedef char *va_list;

typedef struct tagOFNA tagOFNA, *PtagOFNA;

typedef struct tagOFNA *LPOPENFILENAMEA;

typedef struct HWND__ HWND__, *PHWND__;

typedef struct HWND__ *HWND;

typedef struct HINSTANCE__ HINSTANCE__, *PHINSTANCE__;

typedef struct HINSTANCE__ *HINSTANCE;

typedef CHAR *LPCSTR;

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

typedef longlong __time64_t;

typedef uint size_t;

typedef __time64_t time_t;

typedef struct _startupinfo _startupinfo, *P_startupinfo;

struct _startupinfo {
    int newmode;
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

typedef struct tagLOGPEN tagLOGPEN, *PtagLOGPEN;

typedef struct tagLOGPEN LOGPEN;

typedef DWORD COLORREF;

struct tagLOGPEN {
    UINT lopnStyle;
    POINT lopnWidth;
    COLORREF lopnColor;
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

typedef struct tagLOGBRUSH tagLOGBRUSH, *PtagLOGBRUSH;

typedef struct tagLOGBRUSH LOGBRUSH;

struct tagLOGBRUSH {
    UINT lbStyle;
    COLORREF lbColor;
    ULONG_PTR lbHatch;
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

typedef DWORD ACCESS_MASK;

typedef short SHORT;

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

typedef ULONG_PTR DWORD_PTR;

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

typedef struct HFONT__ *HFONT;

typedef DWORD *LPDWORD;

typedef struct HPEN__ *HPEN;

typedef struct HPALETTE__ *HPALETTE;

typedef int *LPINT;

typedef struct tagSIZE *LPSIZE;

typedef struct HMENU__ HMENU__, *PHMENU__;

typedef struct HMENU__ *HMENU;

struct HMENU__ {
    int unused;
};

typedef HANDLE *LPHANDLE;

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

typedef void (TIMECALLBACK)(UINT, UINT, DWORD_PTR, DWORD_PTR, DWORD_PTR);

typedef TIMECALLBACK *LPTIMECALLBACK;

typedef UINT MMRESULT;

typedef int (*_onexit_t)(void);

typedef struct _AppBarData _AppBarData, *P_AppBarData;

typedef struct _AppBarData *PAPPBARDATA;

struct _AppBarData {
    DWORD cbSize;
    HWND hWnd;
    UINT uCallbackMessage;
    UINT uEdge;
    RECT rc;
    LPARAM lParam;
};




undefined4 UI_Register_MAGICGAME_BigCardCardClass_00401000(HWND hwnd,uint y,HDC hdc,undefined4 *arg_4);
bool UI_CreateWindow_00401c91(LPCSTR str_1);
void Mem_AllocOrFree_00401d23(void);
LRESULT UI_WndProc_00401d2e(HWND hwnd,uint uMsg,WPARAM wParam,uint lParam);
undefined4 UI_Register_WINBK_BigCard_00401e65(LPCSTR str_1);
void Mem_AllocOrFree_00401f40(void);
LRESULT UI_WndProc_00401f70(HWND hwnd,uint uMsg,WPARAM wParam,LONG *lParam);
bool FUN_00403189(HWND hwnd,int arg2);
undefined4 FUN_00403250(int *arg_1,int arg_2,int arg_3,uint arg_4,uint arg_5,uint arg_6,uint arg_7,uint arg_8,uint arg_9,uint arg_10,uint arg_11,uint arg_12,int arg_13,int arg_14,uint arg_15,uint arg_16,uint arg_17,uint arg_18,uint arg_19);
uint Rules_ParseFilter_0040360b(int card_id,int color_mask,char *str_3,int arg_4,byte arg_5,byte arg_6,uint arg_7,uint arg_8,uint arg_9,uint arg_10,uint arg_11,uint arg_12,uint arg_13,int arg_14,int arg_15,uint arg_16,uint arg_17,uint arg_18,uint arg_19,uint arg_20);
int FUN_00405277(int arg1,int arg2);
void Action_PromptTarget_00405370(uint spell_id,undefined4 target_id,int flags);
int Action_ValidateTarget_00405802(int spell_id,uint target_id,uint flags,uint arg_4,uint arg_5,uint arg_6,uint arg_7,uint arg_8,uint arg_9,uint arg_10,int arg_11,int arg_12,uint arg_13,uint arg_14,uint arg_15,uint arg_16,uint arg_17,undefined1 *arg_18,undefined4 arg_19,int *arg_20);
undefined4 FUN_00405edf(int arg1,int arg2);
undefined4 FUN_00405f97(int arg1,int arg2);
void Csv_LoadInfo_004060e0(void);
void Csv_LoadMaster_004063b8(void);
void Csv_WriteConcise_004064f8(void);
void Csv_ReadConcise_0040659f(void);
void Csv_SearchMaster_00406681(char *filepath,int y,int width,char *str_4);
int FUN_0040683a(char *str_1,int arg_2,int arg_3,int arg_4,undefined4 arg_5);
void FUN_00406a88(char *str_1,int arg2);
bool FUN_00406b01(char *str_1);
int Deck_FilterAttributes_00406b4c(char *filter_string,int color_mask,uint width,int height);
void Story_Load_0040706f(void);
void Tale_Load_0040710a(int arg_1);
void Hints_Load_004071ce(void);
void Hints_GetNext_0040741b(int arg_1);
int FUN_00407499(int arg_1);
undefined4 FUN_00407747(int arg_1);
char * FUN_004077ae(char *str_1);
char * FUN_00407843(char *str_1,char *str_2,int arg_3);
void Merchant_ProcessBuy_00407b34(int arg_1);
void FUN_00407e40(undefined4 arg1,uint arg2);
bool Mem_AllocOrFree_00408089(void);
undefined4 FUN_004080b2(void);
undefined4 Mem_AllocOrFree_0040810f(void);
undefined4 Mem_AllocOrFree_0040813d(void);
void FUN_0040816b(undefined4 arg_1);
bool UI_CreateWindow_004081b0(LPCSTR str_1);
void FUN_004082d1(void);
LRESULT UI_WndProc_0040836a(HWND hwnd,uint uMsg,uint wParam,LPSTR lParam);
undefined4 FUN_004088d0(int *arg_1);
undefined4 UI_Register_FACE_BLACK_00408e20(LPCSTR str_1);
void FUN_00409052(void);
LRESULT UI_WndProc_004090f6(HWND hwnd,uint uMsg,uint wParam,uint lParam);
void FUN_004097e2(HDC hdc,RECT *arg_2,int arg_3);
void FUN_00409b2c(int arg1,int arg2);
void FUN_00409c73(undefined4 arg_1);
undefined4 FUN_00409cb2(int arg_1);
undefined4 FUN_00409d10(void);
void FUN_00409db6(void);
void Mem_AllocOrFree_00409e13(undefined4 arg1,undefined4 arg2);
undefined4 Mem_AllocOrFree_00409e3c(undefined4 arg_1);
undefined4 FUN_00409e6d(undefined4 arg_1,undefined4 arg_2,undefined4 arg_3,undefined4 arg_4);
void FUN_00409eb0(int arg_1);
void FUN_00409f16(int arg1,int arg2);
void FUN_00409f99(char *str_1,int y,uint width,int height);
int FUN_0040a02a(int arg_1);
void FUN_0040a16e(void);
void Mem_AllocOrFree_0040a1a3(void);
int FUN_0040a1d2(int arg_1);
void FUN_0040a1ff(void);
void Mem_AllocOrFree_0040a240(void);
uint FUN_0040a255(uint arg_1);
undefined4 FUN_0040a2c0(void);
int FUN_0040a305(int arg_1,int arg_2,int arg_3);
void FUN_0040a33c(void);
int FUN_0040a36f(int arg1,int arg2);
void FUN_0040a3e1(void);
void Mem_AllocOrFree_0040a422(void);
int FUN_0040a444(void);
void Mem_AllocOrFree_0040a4ac(void *arg_1,void *arg_2,size_t arg_3);
void Mem_AllocOrFree_0040a4d4(void *arg_1,void *arg_2,size_t arg_3);
undefined4 Pic_Load_advfac64_0040a4fc(void);
undefined4 FUN_0040a566(void);
void FUN_0040a5de(void);
void FUN_0040a725(char *arg_1);
void FUN_0040a883(char *arg_1);
void FUN_0040a95d(char *arg_1);
void FUN_0040aaf1(char *arg_1);
void FUN_0040abf9(char *arg_1);
void FUN_0040acfd(char *arg_1);
void FUN_0040adaf(char *arg_1,int arg_2,int arg_3);
undefined4 FUN_0040ae70(int arg1,int arg2);
undefined4 Sound_LoadWav_x_sound_button2_0040b00c(int arg_1);
undefined4 FUN_0040b03e(int arg1,int arg2);
undefined4 FUN_0040b143(int arg_1);
undefined4 FUN_0040b2c8(int arg_1);
void FUN_0040b3c2(undefined4 arg1,undefined4 arg2);
void FUN_0040b441(int *arg1,int arg2);
void FUN_0040b4e8(void);
int Castle_Process_0040b7fa(int arg_1);
void FUN_0040bcff(uint arg1,uint arg2);
void Mem_AllocOrFree_0040c180(int arg_1,int arg_2,int arg_3,int arg_4,int arg_5);
void FUN_0040c1ad(char *arg_1,int y,int width,undefined4 arg_4);
void FUN_0040c274(undefined4 arg_1,int y,int width,undefined4 arg_4);
void FUN_0040c2af(undefined4 arg_1,int y,int width,undefined4 arg_4);
void FUN_0040c2e9(undefined4 arg_1,int y,int width,undefined4 arg_4);
void FUN_0040c336(undefined4 arg_1,int y,int width,int arg_4);
void FUN_0040c381(undefined4 arg_1,int y,int width,undefined4 arg_4);
void FUN_0040c3cc(char *arg_1,int y,int width,undefined4 arg_4);
void FUN_0040c421(undefined4 arg_1,int y,int width,int height);
int FUN_0040c465(char *str_1);
void FUN_0040c4c5(int *arg_1,int arg_2,int arg_3,int arg_4,int arg_5,int *arg_6,int arg_7,int arg_8);
void FUN_0040c550(int *arg_1,int arg_2,int arg_3,int arg_4,int arg_5,int *arg_6,int arg_7,int arg_8);
void FUN_0040c5d9(int *arg_1,int arg_2,int arg_3,int arg_4,int arg_5,int *arg_6,int arg_7,int arg_8);
void FUN_0040c662(int *arg_1,int arg_2,int arg_3,int arg_4,int arg_5,uint arg_6);
void FUN_0040c6c7(int *arg_1,int arg_2,int arg_3,int arg_4,int arg_5,int arg_6);
void FUN_0040c72c(int arg_1,int arg_2,int arg_3,int arg_4,uint arg_5);
uint FUN_0040c761(int arg1,int arg2);
undefined4 FUN_0040c7c0(int arg1,int arg2);
void FUN_0040c81c(uint arg_1,int arg_2,int arg_3);
void FUN_0040c889(uint arg_1,int arg_2,int arg_3);
undefined4 FUN_0040c8fa(int arg1,int arg2);
void FUN_0040c959(uint arg_1,int arg_2,int arg_3);
void FUN_0040c9cc(uint arg_1,int arg_2,int arg_3);
void FUN_0040ca43(int arg_1,int arg_2,int arg_3);
uint FUN_0040cb4f(int arg_1,int arg_2,char arg_3);
undefined4 FUN_0040cbbd(int arg1,int arg2);
int FUN_0040cc08(char *str_1);
int FUN_0040cc7e(int arg_1,int arg_2,int arg_3,int arg_4,int arg_5,int arg_6,int arg_7,int arg_8,undefined4 *arg_9);
void FUN_0040cea5(int arg_1,int arg_2,int arg_3);
void FUN_0040ced7(int arg_1,int arg_2,int arg_3);
void FUN_0040cf09(int arg_1,int arg_2,int arg_3);
void FUN_0040cf3b(int arg_1,int arg_2,int arg_3);
void FUN_0040cf6d(int x,int y,int width,int height);
void FUN_0040cfa1(int x,int y,int width,int height);
void FUN_0040cfd5(int x,int y,int width,int height);
void FUN_0040d009(int x,int y,int width,int height);
void FUN_0040d03d(int arg_1,int arg_2,int arg_3);
void FUN_0040d06f(int arg_1,int arg_2,int arg_3);
void FUN_0040d0a1(int arg_1,int arg_2,int arg_3);
void FUN_0040d0d3(int arg_1,int arg_2,int arg_3);
void FUN_0040d105(int arg_1,int arg_2,int arg_3);
void FUN_0040d137(int arg_1,int arg_2,int arg_3);
void FUN_0040d169(int arg_1,int arg_2,int arg_3);
void FUN_0040d19b(int arg_1,int arg_2,int arg_3);
void FUN_0040d1cd(int x,int y,int width,int height);
void FUN_0040d201(int x,int y,int width,int height);
void FUN_0040d235(int x,int y,int width,int height);
void FUN_0040d269(int x,int y,int width,int height);
void FUN_0040d29d(int x,int y,int width,int height);
void FUN_0040d2d1(int x,int y,int width,int height);
void FUN_0040d305(int x,int y,int width,int height);
void FUN_0040d339(int x,int y,int width,int height);
void FUN_0040d36d(int arg_1,int arg_2,int arg_3);
void FUN_0040d39f(int arg_1,int arg_2,int arg_3);
void FUN_0040d3d1(int arg_1,int arg_2,int arg_3);
void FUN_0040d403(int arg_1,int arg_2,int arg_3);
void FUN_0040d435(int x,int y,int width,int height);
void FUN_0040d469(int x,int y,int width,int height);
void FUN_0040d49d(int x,int y,int width,int height);
void FUN_0040d4d1(int x,int y,int width,int height);
undefined4 FUN_0040d510(int arg_1,int arg_2,int arg_3);
undefined4 FUN_0040d552(int arg_1,int arg_2,int arg_3);
void FUN_0040d59c(int arg_1,uint arg_2,int arg_3);
void FUN_0040d64c(int arg_1,uint arg_2,int arg_3);
void FUN_0040d72b(int arg_1,uint arg_2,int arg_3);
undefined4 FUN_0040d7e9(int arg_1,int arg_2,int arg_3);
undefined4 FUN_0040d82b(int arg_1,int arg_2,int arg_3);
undefined4 FUN_0040d875(int arg_1,int arg_2,int arg_3);
undefined4 FUN_0040d8b7(int arg_1,int arg_2,int arg_3);
undefined4 FUN_0040d901(int arg_1,int arg_2,int arg_3);
int FUN_0040d949(int arg_1,uint arg_2,int arg_3);
int FUN_0040dcca(int x,int y,uint width,int height);
void Sound_LoadWav_x_DuelSounds_artifact_0040de30(int arg_1);
int FUN_0040eab1(void);
void FUN_0040eb04(int arg_1);
void Pic_Load_winbak01_0040eb5a(int arg1,int arg2);
undefined4 Mem_AllocOrFree_0040eea2(void);
undefined4 FUN_0040eeb4(int arg1,int arg2);
void FUN_0040f514(byte arg_1);
int FUN_0040f636(char *str_1);
int FUN_0040f681(int *arg1,undefined4 *arg2);
int FUN_0040f6e9(void);
int FUN_0040f78d(int arg_1);
int FUN_0040f9b7(byte arg_1);
undefined4 FUN_0040fa39(char *str_1,char *str_2,int arg_3);
int FUN_0040fbe2(void);
void FUN_0040fc9a(int arg_1,char *str_2,char *str_3);
void Mem_AllocOrFree_0040fcf2(void);
undefined4 Dungeon_Process_0040fcfd(int arg_1,int arg_2,int arg_3);
void FUN_00410c7d(char *arg_1);
int FUN_00410cc0(int arg_1,int arg_2,int arg_3,int arg_4,int arg_5);
undefined4 FUN_00410ef1(int arg_1,int arg_2,int arg_3);
undefined4 FUN_0041115f(int arg_1,int arg_2,int arg_3);
undefined4 FUN_00411201(int arg_1,int arg_2,int arg_3);
undefined4 FUN_0041130e(int arg_1,int arg_2,int arg_3);
undefined4 FUN_00411753(int arg_1,int arg_2,int arg_3);
undefined4 FUN_004118a8(int arg_1,int arg_2,int arg_3);
undefined4 FUN_00411f98(int arg_1,int arg_2,int arg_3);
undefined4 FUN_0041214b(int arg_1,int arg_2,int arg_3);
undefined4 FUN_00412246(int arg_1,int arg_2,int arg_3);
undefined4 FUN_00412413(int arg_1,int arg_2,int arg_3);
undefined4 FUN_00412586(int arg_1,int arg_2,int arg_3);
bool FUN_0041268a(int arg_1,int arg_2,int arg_3);
undefined4 FUN_0041283f(int arg_1,int arg_2,int arg_3);
undefined4 FUN_00412f15(int arg_1,int arg_2,int arg_3);
undefined4 FUN_00413570(int arg_1,int arg_2,int arg_3);
undefined4 FUN_00413869(int arg_1,int arg_2,int arg_3);
undefined4 FUN_00413a32(int arg_1,int arg_2,int arg_3);
undefined4 FUN_00413baa(int arg_1,int arg_2,int arg_3);
undefined4 FUN_00413d01(int arg1,int arg2);
undefined4 FUN_00413d8d(int arg_1,int arg_2,int arg_3);
undefined4 FUN_00413fb4(int arg_1,int arg_2,int arg_3);
undefined4 FUN_00414270(int arg_1,int arg_2,int arg_3);
undefined4 FUN_0041459d(int arg_1,int arg_2,int arg_3);
undefined4 FUN_004147a4(int arg_1,int arg_2,int arg_3);
undefined4 FUN_00414875(int arg_1,int arg_2,int arg_3);
undefined4 FUN_00414947(int arg_1,undefined4 arg_2,int arg_3);
undefined4 FUN_00414ac1(int arg_1,int arg_2,int arg_3);
undefined4 Prompts_Load_00414d99(int spell_id,int target_id,int flags);
undefined4 FUN_00414f59(int arg_1,int arg_2,int arg_3);
undefined4 FUN_00415080(int arg_1,int arg_2,int arg_3);
undefined4 Prompts_Load_004150fe(int spell_id,int target_id,int flags);
undefined4 Prompts_Load_0041529a(int spell_id,int target_id,int flags);
undefined4 Prompts_Load_00415517(int spell_id,int target_id,int flags);
undefined4 Prompts_Load_004156c9(int spell_id,int target_id,int flags);
undefined4 Prompts_Load_00415920(int spell_id,int target_id,int flags);
undefined4 FUN_00415d48(int arg1,int arg2);
undefined4 Prompts_Load_00415df8(int spell_id,int target_id,int flags);
undefined4 FUN_00416059(int arg_1,int arg_2,int arg_3);
undefined4 FUN_00416129(int arg_1,int arg_2,int arg_3);
undefined4 Prompts_Load_00416222(int spell_id,int target_id,int flags);
undefined4 Prompts_Load_0041652b(int spell_id,int target_id,int flags);
undefined4 Prompts_Load_004167ac(int spell_id,int target_id,int flags);
undefined4 Prompts_Load_00416a6a(int spell_id,int target_id,int flags);
undefined4 FUN_00416cda(int arg_1,int arg_2,int arg_3);
undefined4 Prompts_Load_00416d36(int spell_id,int target_id,int flags);
undefined4 Prompts_Load_00416f1a(int spell_id,int target_id,int flags);
undefined4 Prompts_Load_004172a6(int spell_id,int target_id,int flags);
undefined4 Prompts_Load_0041765d(int spell_id,int target_id,int flags);
undefined4 FUN_00417919(int arg_1,int arg_2,int arg_3);
undefined4 FUN_004179a4(int arg_1,int arg_2,int arg_3);
undefined4 FUN_00417a57(int arg1,int arg2);
undefined4 FUN_00417b09(int arg_1,int arg_2,int arg_3);
undefined4 FUN_00417bb9(int arg1,int arg2);
undefined4 FUN_00417c96(int arg_1,int arg_2,int arg_3);
undefined4 Prompts_Load_00417f38(int spell_id,int target_id,int flags);
undefined4 Prompts_Load_00417ff5(int spell_id,int target_id,int flags);
undefined4 Prompts_Load_00418254(int spell_id,int target_id,int flags);
undefined4 Prompts_Load_004184e1(int spell_id,int target_id,int flags);
bool FUN_004186ac(int arg_1,int arg_2,int arg_3);
undefined4 FUN_0041872f(int arg1,int arg2);
undefined4 Prompts_Load_00418785(int spell_id,int target_id,int flags);
void FUN_00418c59(int x,int y,int width,undefined1 arg_4);
undefined4 Prompts_Load_00418d2a(int spell_id,int target_id,int flags);
void FUN_004194cf(int x,int y,int width,undefined1 arg_4);
undefined4 Prompts_Load_004195a4(int spell_id,int target_id,int flags);
undefined4 Prompts_Load_00419d5e(int spell_id,int target_id,int flags);
uint FUN_0041a245(int arg_1,int arg_2,int arg_3);
undefined4 FUN_0041a4c6(int arg_1,int arg_2,int arg_3);
undefined4 FUN_0041a782(int arg_1,int arg_2,int arg_3);
undefined4 FUN_0041adc1(int arg_1,int arg_2,int arg_3);
undefined4 Prompts_Load_0041b1ae(int spell_id,int target_id,int flags);
uint FUN_0041b695(int arg_1,int arg_2,int arg_3);
undefined4 FUN_0041b89c(int arg_1,int arg_2,int arg_3);
void Mem_AllocOrFree_0041b93a(int arg_1,int arg_2,int arg_3);
void Mem_AllocOrFree_0041b964(int arg_1,int arg_2,int arg_3);
undefined4 Prompts_Load_0041b98a(int spell_id,int target_id,int flags,int height);
undefined4 Prompts_Load_0041c22f(int spell_id,int target_id,int flags);
undefined4 Prompts_Load_0041c8e1(int spell_id,int target_id,int flags);
uint FUN_0041cb9a(int arg_1,int arg_2,int arg_3);
undefined4 FUN_0041cf9f(int arg_1,int arg_2,int arg_3);
undefined4 FUN_0041d019(int arg_1,int arg_2,int arg_3);
undefined4 Prompts_Load_0041d1ab(int spell_id,int target_id,int flags);
undefined4 FUN_0041d411(int arg_1,int arg_2,int arg_3);
int FUN_0041d8a6(int arg_1);
void Mem_AllocOrFree_0041d942(int arg_1);
int FUN_0041d963(int arg_1,int arg_2,int arg_3);
int FUN_0041d9d2(int arg_1,int arg_2,int arg_3);
void FUN_0041da41(int arg1,int arg2);
int FUN_0041db67(int arg_1,int arg_2,int arg_3,int arg_4,int arg_5);
void Mem_AllocOrFree_0041df33(int x,int y,int width,int height);
bool UI_CreateWindow_0041df60(LPCSTR str_1);
LRESULT UI_WndProc_0041dfe4(HWND hwnd,uint uMsg,WPARAM wParam,uint lParam);
undefined4 FUN_0041e370(int arg1,int arg2);
undefined4 FUN_0041e486(int arg1,int arg2);
undefined4 FUN_0041e682(int arg1,int arg2);
undefined4 FUN_0041e8b8(int arg1,int arg2);
undefined4 FUN_0041ec8d(int arg_1);
undefined4 FUN_0041ece4(int arg_1);
undefined4 FUN_0041ed3a(int arg_1);
undefined4 Sound_LoadWav_x_sound_button2_0041ed86(int arg_1);
undefined4 FUN_0041edd4(void);
undefined4 Mem_AllocOrFree_0041f12b(int arg_1);
undefined4 Mem_AllocOrFree_0041f159(undefined4 arg_1);
undefined4 FUN_0041f17e(int arg_1,int arg_2,int arg_3);
undefined4 FUN_0041f213(void);
undefined4 FUN_0041f2af(int arg1,int arg2);
int FUN_0041f354(void);
int FUN_0041f391(void);
int FUN_0041f3ea(undefined4 arg_1,undefined4 arg_2,int arg_3);
undefined4 Sound_LoadWav_x_sound_button2_0041fe70(undefined4 arg1,int arg2);
undefined4 Mem_AllocOrFree_0041feab(void);
undefined4 FUN_0041fec7(int arg_1,int arg_2,int arg_3,int arg_4,char *str_5,int arg_6);
undefined4 FUN_0041fffc(int arg_1,int *arg_2,int arg_3,int arg_4,char *str_5,int arg_6,int arg_7);
undefined4 FUN_0042024f(int arg1,int arg2);
undefined4 FUN_0042038c(int *arg_1,int arg_2,int arg_3,int arg_4,int arg_5);
int Save_ProcessGame_004207a8(int arg_1);
undefined4 FUN_004211bd(int arg1,int arg2);
undefined4 Sound_LoadWav_x_sound_button2_004212b4(int arg_1);
undefined4 FUN_004212f0(int arg1,int arg2);
undefined4 FUN_004214cf(int arg1,int arg2);
undefined4 Sound_LoadWav_x_sound_button2_00421655(int arg_1);
undefined4 FUN_004216e5(int arg1,int arg2);
undefined4 FUN_004217ea(int arg_1);
undefined4 FUN_0042192b(int arg_1);
void FUN_004219e1(int *arg_1,int arg_2,int arg_3,int arg_4,int arg_5,int arg_6);
undefined4 FUN_00421a81(int arg1,int arg2);
undefined4 Castle_Process_00421b32(void);
void FUN_00422b04(int arg_1);
void FUN_00422f06(void);
void Pic_Load_worlbak1_004230bd(int arg_1);
undefined * FUN_004232f0(int arg_1,int arg_2,int arg_3);
undefined4 Pic_Load_0042351b(int arg_1,undefined4 arg_2,undefined4 arg_3,char *str_4,undefined1 *arg_5);
int Pic_Load_00423833(char *str_1);
int Pic_Subsystem_004238ba(char *str_1,int arg2);
void Pic_Subsystem_004238ee(int arg_1);
void Pic_Util_00423919(undefined4 arg_1);
int Pic_Subsystem_00423940(void);
int Pic_Subsystem_00423980(int hInst,undefined4 hWnd,uint flags);
void Pic_Subsystem_00423ae1(void);
undefined4 Pic_Subsystem_00423b57(undefined4 arg_1,undefined4 arg_2,undefined4 arg_3);
undefined4 Pic_Subsystem_00423b93(undefined4 arg_1);
undefined4 Pic_Subsystem_00423bc7(void);
undefined4 Pic_Subsystem_00423bf4(undefined4 sound_id,undefined4 flags);
undefined4 Pic_Subsystem_00423c39(undefined4 filename,undefined4 loop_flag,undefined4 out_handle);
undefined4 Pic_Subsystem_00423c82(undefined4 sound_id);
void Pic_Subsystem_00423cc3(void);
undefined4 Pic_Subsystem_00423cf3(undefined4 arg1,undefined4 arg2);
undefined4 Pic_Subsystem_00423d38(undefined4 value,undefined4 arg2);
undefined4 Pic_Subsystem_00423d7d(undefined4 arg1,undefined4 arg2);
undefined4 Pic_Subsystem_00423dc2(undefined4 value,undefined4 arg2);
undefined4 Pic_Subsystem_00423e07(undefined4 arg1,undefined4 arg2);
undefined4 Pic_Subsystem_00423e4c(undefined4 value,undefined4 arg2);
undefined4 Pic_Subsystem_00423e91(undefined4 arg1,undefined4 arg2);
undefined4 Pic_Subsystem_00423ed6(void);
undefined4 Pic_Subsystem_00423f10(undefined4 arg1,undefined4 arg2);
undefined4 Pic_Subsystem_00423f55(undefined4 arg1,undefined4 arg2);
undefined4 Pic_Subsystem_00423f9a(undefined4 arg_1);
undefined4 Pic_Subsystem_00423fdb(undefined4 arg1,undefined4 arg2);
undefined4 Pic_Subsystem_00424020(undefined4 arg1,undefined4 arg2);
undefined4 Pic_Subsystem_00424065(undefined4 arg1,undefined4 arg2);
undefined4 Pic_Subsystem_004240a7(undefined4 arg1,undefined4 arg2);
undefined4 Pic_Subsystem_004240ec(void);
undefined4 Pic_Subsystem_00424123(undefined4 arg1,undefined4 arg2);
undefined4 Pic_Subsystem_00424165(undefined4 arg_1,undefined4 arg_2,undefined4 arg_3);
void Pic_Subsystem_004241ae(void);
bool Pic_Subsystem_004241f0(LPCSTR str_1);
LRESULT Pic_Subsystem_00424282(HWND hwnd,uint uMsg,HDC wParam,LPARAM lParam);
void Pic_Load_004244a0(void);
int Pic_Subsystem_00424500(char *str_1,char *str_2);
int Pic_Subsystem_0042475a(char *str_1,char *str_2);
undefined4 Pic_Load_004248b0(LPCSTR str_1);
void Pic_Subsystem_004249a8(void);
undefined4 Pic_Load_00424a1e(LPCSTR str_1);
void Pic_Subsystem_00424aef(void);
LRESULT Pic_Load_00424b1f(HWND hwnd,uint uMsg,char *wParam,uint lParam);
void Pic_Subsystem_00425ee3(POINT *x,RECT *arg_2,undefined4 *arg_3,int *height);
void Pic_Subsystem_004262cf(LPRECT arg_1,int arg_2,int arg_3,int arg_4,int arg_5);
void Pic_Subsystem_00426518(HDC hdc,int arg2);
LRESULT Pic_Load_004267c5(HWND hwnd,uint uMsg,char *wParam,uint lParam);
void Pic_Subsystem_0042784d(POINT *arg_1,RECT *arg_2,undefined4 *arg_3);
void Pic_Subsystem_00427a0a(LPRECT arg_1,int y,int width,int height);
void Pic_Subsystem_00427bcb(HDC hdc,int arg2);
void Pic_Draw_00427e36(int *arg_1,undefined4 *arg_2,char *str_3);
void Pic_Util_004280cf(void);
undefined4 Pic_Subsystem_00428320(int arg_1,int arg_2,int arg_3);
undefined4 Pic_Subsystem_0042881e(int arg_1,int arg_2,int arg_3);
undefined4 Pic_Subsystem_00428d5a(int arg_1,int arg_2,int arg_3);
undefined4 Pic_Subsystem_00429237(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_004297ed(int spell_id,int target_id,int flags);
int Pic_Subsystem_00429e7d(int spell_id,int target_id,int flags);
void Pic_Subsystem_0042a0d6(int arg_1,int arg_2,int arg_3);
uint Pic_Load_0042a1c9(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_0042ac1f(int arg1,int arg2);
undefined4 Pic_Subsystem_0042ae1d(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_0042b5f5(int arg_1,int arg_2,int arg_3);
undefined4 Pic_Subsystem_0042baae(int arg_1,int arg_2,int arg_3);
undefined4 Pic_Subsystem_0042baee(int arg_1,int arg_2,int arg_3);
undefined4 Pic_Subsystem_0042bb2e(int spell_id,int target_id,int flags);
void Pic_Subsystem_0042bee5(int spell_id,int target_id,int flags);
void Pic_Subsystem_0042bf45(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_0042bfa5(int x,int y,int width,uint height);
undefined4 Pic_Subsystem_0042c92f(int arg_1,int arg_2,int arg_3);
int Pic_Subsystem_0042ca53(int arg1,int arg2);
undefined4 Pic_Subsystem_0042ce63(int x,int y,int width,int height);
undefined4 Pic_Subsystem_0042d64f(int arg_1,int arg_2,int arg_3);
undefined4 Pic_Subsystem_0042db29(int arg_1,int arg_2,int arg_3);
undefined4 Pic_Subsystem_0042dd1f(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_0042e2d9(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_0042e80e(int arg_1,int arg_2,int arg_3);
undefined4 Pic_Subsystem_0042e8c0(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_0042ec65(int arg1,int arg2);
undefined4 Pic_Subsystem_0042ed9f(uint spell_id,int target_id,int flags);
uint Pic_Subsystem_0042f2f8(int arg_1,int arg_2,int arg_3);
undefined4 Pic_Subsystem_0042f690(int arg_1,int arg_2,int arg_3);
undefined4 Pic_Subsystem_0042f789(int arg_1,int arg_2,int arg_3);
undefined4 Pic_Subsystem_0042f87b(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_0042fe9a(int arg_1,int arg_2,int arg_3);
undefined4 Pic_Subsystem_0043001d(int arg_1,int arg_2,int arg_3);
undefined4 Pic_Subsystem_004301b4(int arg_1,int arg_2,int arg_3);
uint Pic_Subsystem_00430252(int arg_1,int arg_2,int arg_3);
undefined4 Pic_Subsystem_004305f1(int arg_1,int arg_2,int arg_3);
undefined4 Pic_Subsystem_0043070c(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_00430f0a(int spell_id,int target_id,int flags);
uint Pic_Subsystem_0043143d(int arg_1,int arg_2,int arg_3);
undefined4 Pic_Subsystem_004316cc(int arg_1,int arg_2,int arg_3);
undefined4 Pic_Subsystem_004319c5(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_00431ed3(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_004325fe(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_00432b12(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_00432f70(int arg_1,int arg_2,int arg_3);
undefined4 Pic_Subsystem_00433057(int arg_1,int arg_2,int arg_3);
undefined4 Pic_Subsystem_00433232(int arg_1,int arg_2,int arg_3);
void Pic_Subsystem_00433334(int arg_1,undefined4 arg_2,int arg_3);
undefined4 Pic_Subsystem_00433466(int arg_1,int arg_2,int arg_3);
undefined4 Pic_Subsystem_0043361c(int arg_1,int arg_2,int arg_3);
undefined4 Pic_Subsystem_004336f8(int arg_1,int arg_2,int arg_3);
undefined4 Pic_Subsystem_00433a9e(int arg_1,int arg_2,int arg_3);
undefined4 Pic_Subsystem_00433b83(int arg_1,int arg_2,int arg_3);
undefined4 Pic_Subsystem_00433c62(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_00433fb5(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_0043452e(int x,int arg_2,int arg_3,int arg_4);
undefined4 Pic_Subsystem_004345a9(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_00434b1f(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_00434f32(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_004353b3(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_00435abf(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_00436500(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_00436f60(int spell_id,int target_id,int flags);
void Pic_Subsystem_0043793a(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_00437ac2(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_00437df6(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_0043812a(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_0043841c(int arg_1,int arg_2,int arg_3);
undefined4 Pic_Subsystem_00438893(int arg_1,int arg_2,int arg_3);
undefined4 Pic_Subsystem_00438995(int arg_1,int arg_2,int arg_3);
undefined4 Pic_Subsystem_00438ced(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_00439408(int arg_1,int arg_2,int arg_3);
undefined4 Pic_Subsystem_004397e3(int arg_1,int arg_2,int arg_3);
uint Pic_Subsystem_00439b92(int spell_id,int target_id,int flags);
void Pic_Subsystem_00439d8b(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_00439e06(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_0043a32c(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_0043ac68(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_0043af93(int arg_1,int arg_2,int arg_3);
undefined4 Pic_Subsystem_0043b067(int arg_1,int arg_2,int arg_3);
undefined4 Pic_Subsystem_0043b1d7(int arg_1,int arg_2,int arg_3);
undefined4 Pic_Subsystem_0043b224(int arg_1,int arg_2,int arg_3);
undefined4 Pic_Subsystem_0043b424(int arg_1,int arg_2,int arg_3);
void Pic_Subsystem_0043b6eb(int spell_id,int target_id,int flags);
void Pic_Subsystem_0043b74e(int spell_id,int target_id,int flags);
void Pic_Subsystem_0043b7c9(int x,int y,int width,uint height);
void Pic_Subsystem_0043ba6e(int spell_id,int target_id,int flags);
void Pic_Subsystem_0043bad0(int spell_id,int target_id,int flags);
void Pic_Subsystem_0043bb32(int spell_id,int target_id,int flags);
void Pic_Subsystem_0043bb94(int spell_id,int target_id,int flags);
void Pic_Subsystem_0043bbf6(int spell_id,int target_id,int flags);
void Pic_Subsystem_0043bc58(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_0043bcba(int arg_1,int arg_2,int arg_3,int arg_4,int arg_5);
undefined4 Pic_Subsystem_0043c0b2(int arg_1,int arg_2,int arg_3);
void Pic_Subsystem_0043c174(int arg_1,int arg_2,int arg_3);
void Pic_Subsystem_0043c1ab(int arg_1,int arg_2,int arg_3);
void Pic_Subsystem_0043c1e2(int arg_1,int arg_2,int arg_3);
void Pic_Subsystem_0043c219(int arg_1,int arg_2,int arg_3);
void Pic_Subsystem_0043c250(int arg_1,int arg_2,int arg_3);
undefined4 Pic_Subsystem_0043c287(int spell_id,int target_id,int flags,int height);
undefined4 Pic_Subsystem_0043c8f5(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_0043d1c3(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_0043da0f(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_0043dfbb(int arg_1,int arg_2,int arg_3);
undefined4 Pic_Subsystem_0043e0f6(int arg_1,int arg_2,int arg_3);
undefined4 Pic_Subsystem_0043e79c(int arg_1,int arg_2,int arg_3);
undefined4 Pic_Subsystem_0043ebbf(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_0043f19e(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_0043f51d(int spell_id,int target_id,int flags);
uint Pic_Subsystem_0043faf7(int spell_id,int target_id,int flags);
void Pic_Subsystem_0043fd7b(int arg_1,int arg_2,int arg_3);
void Pic_Subsystem_0043fdb2(int arg_1,int arg_2,int arg_3);
void Pic_Subsystem_0043fde9(int arg_1,int arg_2,int arg_3);
void Pic_Subsystem_0043fe20(int arg_1,int arg_2,int arg_3);
void Pic_Subsystem_0043fe57(int arg_1,int arg_2,int arg_3);
undefined4 Pic_Subsystem_0043fe8e(int spell_id,int target_id,int flags,int height);
undefined4 Pic_Subsystem_00440289(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_0044068c(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_00440b49(int arg_1,int arg_2,int arg_3);
undefined4 Pic_Subsystem_00440db5(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_00441167(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_004414dc(int arg_1,int arg_2,int arg_3);
undefined4 Pic_Subsystem_0044178f(int arg_1,int arg_2,int arg_3);
int Pic_Subsystem_00441a42(int arg1,int arg2);
bool Pic_Subsystem_00442010(LPCSTR str_1);
uint Pic_Load_004420a1(HWND hwnd,uint y,void *arg_3,int *height);
WPARAM Pic_Subsystem_00443b0c(void);
undefined4 Pic_Clip_00443b63(HWND hwnd);
void Pic_Subsystem_004441cc(HWND hwnd,int arg2);
void Pic_Load_004450c3(int arg_1,int arg_2,int arg_3);
void Pic_Subsystem_0044559e(void);
undefined4 Pic_Subsystem_004455e3(HWND hwnd,uint y,HDC hdc,undefined4 arg_4);
uint Pic_Subsystem_004458b0(int arg1,char *str_2);
uint Pic_Subsystem_004468dc(int arg_1);
undefined4 Pic_Subsystem_00446d52(int arg1,int arg2);
undefined4 Pic_Subsystem_0044724d(void);
void Pic_Subsystem_004475a4(void);
void Pic_Subsystem_00447a1a(void);
int Pic_Subsystem_00447b57(int arg1,int arg2);
undefined4 Pic_Subsystem_004485d6(int x,int y,int width,undefined4 arg_4);
void Pic_Subsystem_0044867e(int arg_1,int arg_2,int arg_3);
undefined4 Pic_Subsystem_004488a0(void);
undefined4 Pic_Subsystem_0044895f(int arg1,int arg2);
void Pic_Subsystem_00448e29(int arg1,int arg2);
void Pic_Subsystem_0044913a(int arg1,int arg2);
void Pic_Subsystem_00449223(int arg1,int arg2);
void Pic_Subsystem_0044929c(int arg1,int arg2);
bool Pic_Subsystem_00449340(LPCSTR str_1);
void Pic_Subsystem_004494d1(void);
LRESULT Pic_Subsystem_004494ff(HWND hwnd,uint uMsg,char *wParam,uint lParam);
LRESULT Pic_Subsystem_00449fbb(HWND hwnd,uint uMsg,WPARAM wParam,LPARAM lParam);
LRESULT Pic_Subsystem_0044a135(HWND hwnd,uint uMsg,WPARAM wParam,LPARAM lParam);
HWND Pic_Subsystem_0044a402(HWND hwnd,int arg2);
void Pic_Util_0044a7cc(HWND hwnd);
undefined4 Pic_Subsystem_0044a7e1(int arg_1);
void Pic_Subsystem_0044a839(void);
HGDIOBJ Pic_Load_0044a862(HWND hwnd,uint uMsg,HDC wParam,HWND lParam);
void Pic_Subsystem_0044b26c(LPRECT arg_1,HWND hwnd,int width,int height);
void Pic_Subsystem_0044b460(void);
undefined4 Pic_Util_0044b839(void);
void Pic_Subsystem_0044b84b(void);
void Pic_Subsystem_0044b8aa(void);
void Pic_Subsystem_0044b8da(void);
void Pic_Subsystem_0044b90a(char *arg1,undefined4 arg2);
void Pic_Util_0044b943(undefined4 arg1,short *arg2);
undefined4 Pic_Util_0044b95a(void);
undefined4 Pic_Subsystem_0044b96c(int arg_1);
bool Pic_Subsystem_0044b9c0(LPCSTR str_1);
void Pic_Subsystem_0044ba83(void);
LRESULT Pic_Subsystem_0044bad4(HWND hwnd,uint y,undefined4 *arg_3,LONG *arg_4);
void Pic_Subsystem_0044cfe4(HWND hwnd);
void Pic_Subsystem_0044d31a(int arg_1,int *arg_2,int *arg_3,int arg_4,int arg_5,int arg_6,int arg_7,int arg_8,HANDLE arg_9);
void Pic_Subsystem_0044d58f(undefined4 arg_1,int arg_2,int arg_3,int arg_4,int arg_5,int arg_6,int *arg_7,int *arg_8,int *arg_9,int *arg_10);
void Pic_Subsystem_0044d61a(char *str_1,HWND hwnd,undefined4 arg_3);
void Pic_Subsystem_0044d680(void);
void Pic_Util_0044da1a(void);
undefined4 Pic_Subsystem_0044da25(void);
void Pic_Subsystem_0044e17e(void);
undefined4 Pic_Subsystem_0044e2e7(int x,int y,int width,int height);
void Pic_Subsystem_0044e528(void);
void Pic_Subsystem_0044e75d(int arg_1,int arg_2,int arg_3);
void Pic_Util_0044e844(int arg1,int arg2);
void Pic_Subsystem_0044e864(int arg1,int arg2);
void Pic_Subsystem_0044e9ac(void);
int Pic_Subsystem_0044eb9d(int arg1,int arg2);
void Pic_Subsystem_0044eca0(void);
void Pic_Subsystem_0044edf5(undefined4 arg_1);
void Pic_Subsystem_0044ef03(LPCSTR str_1);
undefined4 Pic_Load_0044ef70(undefined4 arg1,LPVOID out_buffer);
undefined4 Pic_Subsystem_0044f1de(undefined4 arg1,int arg2);
void Pic_Subsystem_00450711(undefined4 *arg_1,undefined4 *arg_2,undefined4 *arg_3);
void Pic_Subsystem_0045083f(int arg1,int arg2);
void Pic_Util_00450975(DWORD arg_1);
void Pic_Subsystem_004509a1(int arg_1,int *arg_2,int arg_3,int arg_4,undefined4 arg_5,int arg_6,char *arg_7);
int Pic_Load_004509e8(int arg_1,int arg_2,int arg_3,undefined4 arg_4,int arg_5);
int Pic_Subsystem_00451291(int arg1,int arg2);
void Pic_Subsystem_0045134b(int arg_1,int arg_2,int arg_3);
undefined4 Pic_Subsystem_00451a82(void);
int Pic_Subsystem_00451b1c(int arg1,int arg2);
uint Pic_Subsystem_00451cb2(void);
int Pic_Subsystem_00451d90(uint arg1,uint arg2);
int Pic_Subsystem_00451e40(uint arg_1);
void Pic_Subsystem_0045200d(uint arg_1);
void Pic_Subsystem_00452065(int arg_1);
void Pic_Subsystem_004520b2(void);
undefined4 Pic_Subsystem_004521a6(int arg_1,int arg_2,int arg_3);
void Pic_Subsystem_00452276(int arg_1);
void Pic_Subsystem_004523fd(int arg1,int arg2);
int Pic_Subsystem_0045245e(int arg1,undefined4 arg2);
void Pic_Subsystem_004524db(int arg1,undefined4 arg2);
int Pic_Subsystem_00452551(int arg_1);
int Pic_Subsystem_0045268f(int arg_1);
void Pic_Subsystem_00452708(char *str_1);
void Pic_Subsystem_0045275a(undefined1 *arg_1);
void Engine_ReportFatalError(char *arg_1);
void UI_DrawCombatBanner(void);
void Minit_Util_0045280c(void);
int Minit_Subsystem_00452827(void);
undefined4 Minit_Subsystem_004528c0(int x,int y,int width,int height);
void Minit_Subsystem_00452ab3(int arg_1,int arg_2,int arg_3);
void Minit_Subsystem_00452ad9(int arg_1,int arg_2,int arg_3);
void Minit_Subsystem_00452aff(int arg_1,int arg_2,int arg_3);
void Minit_Subsystem_00452b25(int arg_1,int arg_2,int arg_3);
void Minit_Subsystem_00452b4b(int arg_1,int arg_2,int arg_3);
void Mana_Init_00452b71(int arg_1,int arg_2,int arg_3,int arg_4,int arg_5);
undefined4 Minit_Subsystem_00452e81(int arg_1,int arg_2,int arg_3);
undefined4 Minit_Subsystem_00452eab(int arg_1,int arg_2,int arg_3);
undefined4 Minit_Subsystem_00452ed5(int arg_1,int arg_2,int arg_3);
undefined4 Minit_Subsystem_00452eff(int arg_1,int arg_2,int arg_3);
undefined4 Minit_Subsystem_00452f29(int arg_1,int arg_2,int arg_3);
undefined4 Minit_Subsystem_00452f53(int arg_1,int arg_2,int arg_3);
undefined4 Minit_Subsystem_00452f7d(int arg_1,int arg_2,int arg_3);
undefined4 Minit_Subsystem_00452fa7(int arg_1,int arg_2,int arg_3);
undefined4 Minit_Subsystem_00452fd1(int arg_1,int arg_2,int arg_3);
undefined4 Minit_Subsystem_00452ffb(int arg_1,int arg_2,int arg_3);
undefined4 Minit_Subsystem_00453025(int arg_1,int arg_2,int arg_3);
undefined4 Mana_Init_004532f1(int arg_1,int arg_2,int arg_3);
undefined4 Minit_Subsystem_0045350d(int arg_1,int arg_2,int arg_3);
undefined4 Minit_Subsystem_004537b0(int spell_id,int target_id,int flags);
undefined4 Minit_Subsystem_00453c60(int arg_1,int arg_2,int arg_3);
undefined4 Mana_Init_00453fdb(int spell_id,int target_id,int flags);
undefined4 Minit_Subsystem_004543d3(int arg_1,int arg_2,int arg_3);
undefined4 Minit_Subsystem_004545c7(int arg_1,int arg_2,int arg_3);
undefined4 Card_Setup_00454702(int arg_1,int arg_2,int arg_3);
undefined4 Mana_Init_004549ea(int spell_id,int target_id,int flags);
undefined4 Mana_Init_004555c8(int spell_id,int target_id,int flags);
undefined4 Minit_Subsystem_00456158(int arg_1,int arg_2,int arg_3);
undefined4 Minit_Subsystem_00456218(int arg_1,int arg_2,int arg_3);
undefined4 Minit_Subsystem_004563fa(int arg_1,int arg_2,int arg_3);
undefined4 Minit_Subsystem_00456552(undefined4 arg_1,undefined4 arg_2,int arg_3);
undefined4 Minit_Subsystem_004565d7(int arg_1,int arg_2,int arg_3);
undefined4 Minit_Subsystem_0045672f(int spell_id,int target_id,int flags);
void Minit_Subsystem_00456d10(int arg_1,int arg_2,int arg_3);
void Minit_Subsystem_00456d36(int arg_1,int arg_2,int arg_3);
void Minit_Subsystem_00456d5c(int arg_1,int arg_2,int arg_3);
void Minit_Subsystem_00456d82(int arg_1,int arg_2,int arg_3);
void Minit_Subsystem_00456da8(int arg_1,int arg_2,int arg_3);
undefined4 Minit_Subsystem_00456dce(int x,int y,int width,int height);
undefined4 Mana_Init_00456f29(int spell_id,int target_id,int flags);
undefined4 Minit_Subsystem_004572aa(int spell_id,int target_id,int flags);
undefined4 Minit_Subsystem_00457747(int arg_1,int arg_2,int arg_3);
undefined4 Minit_Subsystem_00457979(int arg_1,int arg_2,int arg_3);
undefined4 Minit_Subsystem_00457baf(int arg_1,int arg_2,int arg_3);
undefined4 Minit_Subsystem_00457d5b(int arg_1,int arg_2,int arg_3);
undefined4 Minit_Subsystem_00457e67(int spell_id,int target_id,int flags);
undefined4 Minit_Subsystem_00458596(int arg_1,int arg_2,int arg_3);
undefined4 Minit_Subsystem_004586d8(int arg_1,int arg_2,int arg_3);
undefined4 Minit_Subsystem_00458895(int arg_1,int arg_2,int arg_3);
undefined4 Minit_Subsystem_00458c07(int arg_1,int arg_2,int arg_3);
undefined4 Minit_Subsystem_00458c6f(int arg1,int arg2);
undefined4 Minit_Subsystem_00458cae(int arg_1,int arg_2,int arg_3);
undefined4 Card_Setup_004590b4(int arg_1,int arg_2,int arg_3);
undefined4 Minit_Subsystem_004592ae(int arg_1,int arg_2,int arg_3);
undefined4 Minit_Subsystem_004594d8(int spell_id,int target_id,int flags);
undefined4 Minit_Subsystem_004597d4(int spell_id,int target_id,int flags);
undefined4 Minit_Subsystem_00459d0a(int arg_1,int arg_2,int arg_3);
int Minit_Subsystem_0045a120(int arg1,int arg2);
undefined4 Minit_Subsystem_0045a252(int spell_id,int target_id,int flags);
undefined4 Minit_Subsystem_0045a42a(int arg1,int arg2);
undefined4 Minit_Subsystem_0045a575(int spell_id,int target_id);
undefined4 Minit_Subsystem_0045a789(int arg_1,int arg_2,int arg_3);
bool Minit_Subsystem_0045a825(int spell_id,int target_id,int flags);
undefined4 Minit_Subsystem_0045a9ff(int spell_id,int target_id,int flags);
undefined4 Minit_Subsystem_0045b156(int spell_id,int target_id,int flags);
undefined4 Mana_Init_0045b502(int spell_id,int target_id,int flags);
undefined4 Mana_Init_0045b7d9(int spell_id,int target_id,int flags);
undefined4 Minit_Subsystem_0045bc8b(int arg_1,int arg_2,int arg_3);
undefined4 Minit_Subsystem_0045bd50(int spell_id,int target_id,int flags);
undefined4 Minit_Subsystem_0045c59a(int spell_id,int target_id,int flags);
undefined4 Minit_Subsystem_0045d028(int arg_1,int arg_2,int arg_3);
undefined4 Minit_Subsystem_0045d1f0(int spell_id,int target_id,int flags);
undefined4 Minit_Subsystem_0045d842(int arg_1,int arg_2,int arg_3);
undefined4 Minit_Subsystem_0045d88f(int arg_1,int arg_2,int arg_3);
undefined4 Minit_Subsystem_0045d8dc(int spell_id,int target_id,int flags);
undefined4 Minit_Subsystem_0045dda5(int spell_id,int target_id,int flags);
undefined4 Minit_Subsystem_0045e071(int arg_1,int arg_2,int arg_3);
undefined4 Minit_Subsystem_0045e1fc(int arg_1,int arg_2,int arg_3);
undefined4 Minit_Subsystem_0045e2a5(int arg_1,int arg_2,int arg_3);
undefined4 Minit_Subsystem_0045e350(undefined4 arg_1,undefined4 arg_2,int arg_3);
void Minit_Subsystem_0045e372(int arg_1,int arg_2,int arg_3);
void Minit_Subsystem_0045e398(int arg_1,int arg_2,int arg_3);
void Minit_Subsystem_0045e3be(int arg_1,int arg_2,int arg_3);
void Minit_Subsystem_0045e3e4(int arg_1,int arg_2,int arg_3);
void Minit_Subsystem_0045e40a(int arg_1,int arg_2,int arg_3);
undefined4 Mana_Init_0045e430(int x,int y,int width,int height);
undefined4 Minit_Subsystem_0045ea5b(int arg_1,int arg_2,int arg_3);
undefined4 Minit_Subsystem_0045ebe4(int spell_id,int target_id,int flags);
undefined4 Minit_Subsystem_0045f258(int arg_1,int arg_2,int arg_3);
void Minit_Subsystem_0045f3cb(int arg_1,int arg_2,int arg_3);
void Minit_Subsystem_0045f3f1(int arg_1,int arg_2,int arg_3);
void Minit_Subsystem_0045f417(int arg_1,int arg_2,int arg_3);
void Minit_Subsystem_0045f43d(int arg_1,int arg_2,int arg_3);
void Minit_Subsystem_0045f463(int arg_1,int arg_2,int arg_3);
void Minit_Subsystem_0045f489(int arg_1,int arg_2,int arg_3);
undefined4 Minit_Subsystem_0045f4af(int x,int y,int width,int height);
undefined4 Minit_Subsystem_0045f682(int arg_1,int arg_2,int arg_3);
int Minit_Subsystem_0045f82b(int arg_1,int arg_2,int arg_3);
undefined4 Minit_Subsystem_0045fdb5(int arg_1,int arg_2,int arg_3);
undefined4 Minit_Subsystem_0046007c(int arg_1,int arg_2,int arg_3);
undefined4 Minit_Subsystem_004603b5(int arg_1,int arg_2,int arg_3);
undefined4 Minit_Subsystem_004604e2(int arg_1,int arg_2,int arg_3);
undefined4 Minit_Subsystem_004605e4(int spell_id,int target_id,int flags);
undefined4 Minit_Subsystem_00460a22(int arg_1,int arg_2,int arg_3);
undefined4 Minit_Subsystem_00460bfa(int arg_1,int arg_2,int arg_3);
undefined4 Minit_Subsystem_00461041(int arg_1,int arg_2,int arg_3);
undefined4 Minit_Subsystem_004611f4(int arg_1,int arg_2,int arg_3);
undefined4 Minit_Subsystem_00461390(int arg_1,int arg_2,int arg_3);
undefined4 Minit_Subsystem_004617ad(int spell_id,int target_id,int flags);
undefined4 Minit_Subsystem_00461ba1(int spell_id,int target_id,int flags);
void Minit_Subsystem_00461f3e(int arg_1,int arg_2,int arg_3);
undefined4 Minit_Subsystem_004620c3(int arg_1,int arg_2,int arg_3);
undefined4 Minit_Subsystem_0046228f(int arg_1,int arg_2,int arg_3);
undefined4 Minit_Subsystem_004622d9(int spell_id,int target_id,int flags);
undefined4 Minit_Subsystem_004626d2(int arg_1,int arg_2,int arg_3);
undefined4 Minit_Subsystem_00462a0a(int spell_id,int target_id,int flags);
undefined4 Minit_Subsystem_00462d1e(int arg_1,int arg_2,int arg_3);
undefined4 Minit_Subsystem_00462f7e(int spell_id,int target_id,int flags);
undefined4 Minit_Subsystem_00463723(int arg_1,int arg_2,int arg_3);
undefined4 Minit_Subsystem_00463c10(int arg_1,int arg_2,int arg_3);
undefined4 Minit_Subsystem_00463cd1(int spell_id,int target_id,int flags);
undefined4 Minit_Subsystem_00463ef0(int spell_id,int target_id,int flags);
undefined4 Minit_Subsystem_0046410a(int arg_1,int arg_2,int arg_3);
undefined4 Minit_Subsystem_0046458f(int arg_1,int arg_2,int arg_3);
int Minit_Subsystem_00464723(int arg_1,int arg_2,int arg_3);
void Minit_Subsystem_00464b28(int arg_1,int arg_2,int arg_3);
void Minit_Subsystem_00464b4e(int arg_1,int arg_2,int arg_3);
undefined4 Minit_Subsystem_00464b74(int x,int y,int width,int height);
undefined4 Minit_Subsystem_00464fcd(int arg_1,int arg_2,int arg_3);
undefined4 Minit_Subsystem_00465165(int spell_id,int target_id,int flags);
undefined4 Minit_Subsystem_00465602(int arg_1,int arg_2,int arg_3);
void Minit_Subsystem_004659d9(int arg_1,int arg_2,uint arg_3);
uint Minit_Subsystem_00465a19(int arg1,int arg2);
undefined4 Minit_Subsystem_00465a75(int spell_id,int target_id,int flags);
undefined4 Minit_Subsystem_00465e9c(int spell_id,int target_id,int flags);
undefined4 Minit_Subsystem_004662e2(int arg_1,int arg_2,int arg_3);
undefined4 Minit_Subsystem_00466541(int spell_id,int target_id,int flags);
undefined4 Card_Setup_0046695e(int arg_1,int arg_2,int arg_3);
undefined4 Minit_Subsystem_00466abb(int arg_1,int arg_2,int arg_3);
undefined4 Minit_Subsystem_00466d29(int arg_1,int arg_2,int arg_3);
undefined4 Minit_Subsystem_00466f5c(int arg_1,int arg_2,int arg_3);
undefined4 Player_Init_0046709c(int spell_id,int target_id,int flags);
undefined4 Minit_Subsystem_0046736a(int arg_1,int arg_2,int arg_3);
undefined4 Minit_Subsystem_0046746c(int arg_1,int arg_2,int arg_3);
undefined4 Minit_Subsystem_0046758c(void);
undefined4 Minit_Subsystem_004677ae(int arg_1,int arg_2,int arg_3);
bool Minit_Subsystem_00467880(LPCSTR str_1);
void Minit_Subsystem_0046799f(void);
LRESULT Card_Setup_00467a68(HWND hwnd,uint uMsg,LONG *wParam,int *lParam);
void FUN_0046aa75(HWND hwnd);
undefined4 FUN_0046ab25(HWND hwnd);
int FUN_0046ad4a(HWND hwnd);
bool FUN_0046adbc(int arg1,int arg2);
uint FUN_0046b04a(int arg1,int arg2);
bool FUN_0046b3e6(int arg1,int arg2);
bool FUN_0046b41c(int arg1,int arg2);
void Mem_AllocOrFree_0046b4bb(int arg1,int arg2);
void FUN_0046b4db(char *str_1,int arg_2,undefined4 arg_3);
void FUN_0046b887(char *str_1,int arg_2,int arg_3);
void Mem_AllocOrFree_0046b92b(void);
void FUN_0046ba19(HDC hdc,int y,undefined4 arg_3,undefined4 arg_4);
undefined4 FUN_0046bb29(HWND hwnd,int *arg2);
undefined4 FUN_0046bbab(HWND hwnd,int arg2);
undefined4 FUN_0046bc2f(HWND hwnd);
LONG FUN_0046bc92(HWND hwnd);
int FUN_0046bcc0(WPARAM arg_1,int arg_2,int width,int height);
undefined4 FUN_0046bf31(int arg1,int arg2);
int FUN_0046bfc2(HDC hdc,RECT *arg_2,int width,int arg_4);
undefined4 FUN_0046c09f(WPARAM arg_1,int arg_2,int width,int height);
void FUN_0046c1b3(int arg_1);
int FUN_0046c203(WPARAM arg_1,int y,int width,int height);
undefined * FUN_0046c4b5(int arg1,int arg2);
int FUN_0046c54b(HDC hdc,RECT *arg_2,int width,int height);
undefined4 FUN_0046c636(WPARAM arg_1,int y,int width,int height);
void FUN_0046c6e5(int arg1,int arg2);
void FUN_0046c859(void);
void Castle_Process_0046c8b0(void);
void Sprite_Load_BK_AMG_0046d333(undefined4 arg_1,int arg_2,int arg_3);
void FUN_0046e70d(int arg1,int arg2);
void FUN_0046e77a(char *arg1,int arg2);
int FUN_0046e922(uint arg_1);
void FUN_0046e960(void);
undefined4 FUN_0046ed22(uint arg_1,int arg_2,int arg_3,int arg_4,int arg_5,int arg_6);
undefined1 * FUN_0046f172(char *str_1);
void FUN_0046f21e(char *arg_1,undefined4 arg_2,undefined4 arg_3);
void FUN_0046f300(void);
int FUN_0046f5d1(int arg_1);
void Prompts_Load_0046fa40(int spell_id,int target_id,int flags);
undefined4 FUN_0046fe86(int arg1,int arg2);
undefined4 FUN_0046ff50(int arg_1,int arg_2,int arg_3);
undefined4 FUN_00470b36(int arg1,int arg2);
bool FUN_00470ea3(int arg_1,int arg_2,int arg_3);
bool FUN_0047103b(int arg1,int arg2);
undefined4 FUN_00471971(int arg1,int arg2);
undefined4 FUN_00471aba(int arg_1,int arg_2,int arg_3);
bool FUN_00471bc0(int arg1,int arg2);
bool FUN_00471c32(int arg1,int arg2);
undefined4 FUN_00471ca4(int arg1,int arg2);
void FUN_00471d16(uint arg_1);
undefined4 FUN_00472616(int arg_1);
undefined4 FUN_004726c5(int arg1,int arg2);
bool FUN_004728c3(int arg1,int arg2);
undefined4 FUN_00472905(int arg_1);
undefined4 FUN_00472a0a(int arg_1);
undefined4 FUN_00472b91(int x,int arg_2,int arg_3,int arg_4);
bool FUN_00472c0c(int arg_1,int arg_2,undefined4 arg_3,undefined4 arg_4,uint arg_5,uint arg_6);
int FUN_00472e08(int x,int y,undefined4 arg_3,undefined4 arg_4);
void FUN_00472f0c(undefined4 arg1,int arg2);
void FUN_00472fae(void);
uint FUN_00473179(int x,int y,int width,undefined4 arg_4);
undefined4 FUN_00473cc5(byte arg_1);
undefined * Mem_AllocOrFree_00473d7e(int arg_1);
int FUN_00473d98(int arg_1);
undefined4 FUN_00473e69(int arg_1,undefined4 arg_2,int arg_3);
void Magic_ScanCards(int arg_1);
int Magic_TriggerCardEvent(int arg_1,int arg_2,int arg_3,undefined4 arg_4,undefined4 arg_5);
bool Magic_ResolveSpellStack(int arg1,int arg2);
void Magic_PayManaCost(void);
void Magic_TapCardForMana(void);
void Magic_UntapTurnPhase(void);
void Magic_CheckTurnTriggers(int arg1,int arg2);
undefined4 Magic_UpkeepPhase(int arg_1);
void Magic_DrawCardPhase(void);
void FUN_00474d0e(void);
undefined4 Mem_AllocOrFree_00474d1e(void);
undefined4 FUN_00474d4a(void);
undefined4 Magic_MainTurnPhase(undefined4 arg_1);
undefined4 Magic_CombatPhase(int arg_1,int arg_2,int arg_3,int arg_4,undefined4 arg_5);
undefined4 FUN_004755fd(void);
undefined4 Magic_EndTurnPhase(void);
undefined4 Magic_DiscardToHandSize(void);
void Mem_AllocOrFree_00475c61(void);
undefined4 FUN_00475c8a(int x,int arg_2,char *arg_3,undefined4 arg_4);
int Magic_CleanupPhase(int x,int y,char *str_3,undefined4 arg_4);
undefined4 FUN_00476205(int x,undefined4 arg_2,char *arg_3,int arg_4);
undefined4 FUN_0047624f(int x,undefined4 arg_2,char *str_3,int height);
undefined4 FUN_0047643e(void);
int FUN_00476482(int arg1,int arg2);
void FUN_00476510(void);
undefined4 FUN_00476675(int arg1,int arg2);
void FUN_004767ee(int arg_1);
undefined4 FUN_004769c4(int arg1,int arg2);
void FUN_00476a80(void);
void FUN_00476b0e(void);
uint FUN_00476c77(int x,int y,int width,int height);
undefined4 Prompts_Load_00476e60(LPCSTR filepath);
void FUN_004770bc(void);
uint UI_Register_WINBK_TellUser_004771fa(HWND hwnd,uint y,LPSTR str_3,int height);
void FUN_00477d73(HWND hwnd,char *str_2,uint arg_3);
void FUN_00478163(HWND hwnd);
void FUN_0047820f(HWND hwnd,HDC hdc,int *arg_3);
int FUN_00478370(WPARAM arg_1,int y,int width,int height);
undefined * FUN_0047865c(int arg1,int arg2);
int FUN_004786f3(int x,int y,int width,int height);
int FUN_00478763(HDC hdc,RECT *arg_2,int width,int height);
undefined4 FUN_0047884f(WPARAM arg_1,int y,int width,int height);
void FUN_004788e0(int arg1,int arg2);
void FUN_00478a56(void);
int FUN_00478aa4(int arg_1,int arg_2,int arg_3);
byte UI_CreateWindow_00478b20(LPCSTR str_1);
void FUN_00478bd5(void);
uint UI_WndProc_00478c08(HWND hwnd,uint uMsg,uint *wParam,LONG *lParam);
int FUN_00479d16(HWND hwnd,int arg2);
int FUN_00479dac(HWND hwnd,int arg2);
void FUN_00479e3f(HWND hwnd,LPRECT arg2);
undefined4 Mem_AllocOrFree_00479fb0(int arg1,int arg2);
undefined4 Mem_AllocOrFree_00479fdc(int arg_1);
undefined4 FUN_00479ff9(int arg1,int arg2);
int Sprite_Load_begin_0047a2e6(void);
undefined4 FUN_0047a94c(int arg1,int arg2);
undefined4 Sound_LoadWav_x_sound_button2_0047aa4a(int arg_1);
undefined4 FUN_0047aa7c(int arg1,int arg2);
int Pic_Load_menu2_hi_0047abf1(void);
undefined4 FUN_0047afa2(int arg1,int arg2);
undefined4 Sound_LoadWav_x_sound_button2_0047b097(int arg_1);
undefined4 FUN_0047b0c9(int arg1,int arg2);
undefined4 Pic_Load_menu3_but1_0047b208(void);
undefined4 FUN_0047b616(int arg1,int arg2);
undefined4 Sound_LoadWav_x_sound_button2_0047b70b(int arg_1);
undefined4 FUN_0047b73d(int arg1,int arg2);
int Sprite_Load__16faces_0047b899(void);
void FUN_0047bcf1(undefined4 *arg_1,int arg_2,int arg_3,int arg_4,int arg_5,undefined4 *arg_6,int arg_7,int arg_8);
void Pic_Load_namepick_0047be64(char *filepath);
undefined4 FUN_0047c080(int arg1,int arg2);
undefined4 Sound_LoadWav_x_sound_button2_0047c175(int arg_1);
void Sprite_Load__16faces_0047c1a7(int arg_1);
undefined4 Pic_Load_advfac64_0047c1fe(undefined4 *arg_1,int y,int width,int height);
undefined4 FUN_0047c2fd(int arg_1);
undefined4 FUN_0047c360(char *str_1,uint arg_2,uint arg_3);
undefined4 UI_Register_sPoison_0047c640(LPCSTR str_1);
void FUN_0047c734(void);
LRESULT UI_WndProc_0047c7aa(HWND hwnd,uint uMsg,char *wParam,uint lParam);
void FUN_0047d3cf(undefined4 arg_1);
undefined4 FUN_0047d40e(int arg_1);
undefined4 UI_Register_WINBK_Attack_0047d460(LPCSTR str_1);
void FUN_0047d85c(void);
uint UI_Register_MAGICGAME_CardClass_0047da80(HWND hwnd,uint y,HWND param_3,HWND param_4);
undefined4 FUN_00481491(int arg_1,int arg_2,int arg_3);
void FUN_00481586(HWND hwnd);
void FUN_0048201a(HWND hwnd,LPRECT arg2);
bool FUN_0048225c(int arg1,int arg2);
uint UI_WndProc_004822b7(HWND hwnd,uint uMsg,uint wParam,int lParam);
void FUN_00482d6f(HWND hwnd);
LRESULT UI_WndProc_00482dd6(HWND hwnd,uint uMsg,HDC wParam,uint lParam);
int FUN_00483139(HWND hwnd,int *arg_2,undefined4 *arg_3,undefined4 *arg_4,undefined4 *arg_5);
int FUN_004833e9(HWND hwnd,int arg2);
void FUN_00483590(char *str_1,int arg_2,int arg_3);
undefined4 FUN_0048365c(void);
void Pic_Load_combat2_0048369c(int arg1,int arg2);
void FUN_00484668(char *str_1);
void FUN_00484691(byte arg1,int arg2);
void Sprite_Load_dungbutt_00484738(int arg_1,undefined4 arg_2,char *str_3);
void FUN_00484c45(undefined4 arg_1);
void FUN_00484df9(undefined4 arg1,undefined4 arg2);
void FUN_00484e2d(int arg_1,undefined4 arg_2,undefined4 arg_3,int arg_4,undefined4 arg_5);
undefined4 Mem_AllocOrFree_00484ebb(void);
int FUN_00484ecd(int x,int y,int width,undefined4 arg_4);
bool FUN_00485005(int arg_1);
undefined4 FUN_00485040(undefined4 arg1,undefined4 arg2);
void Mem_AllocOrFree_00485229(void);
void FUN_00485234(int arg_1);
void FUN_004853c2(void);
int FUN_004854a4(int arg_1,char *str_2,int arg_3);
int FUN_00485605(int arg_1,char *str_2,int arg_3);
int Dungeon_Process_004856b0(uint arg1,int arg2);
undefined4 FUN_00488f92(int arg_1);
void FUN_00488fdb(undefined4 *arg_1,int arg_2,int arg_3,int arg_4,int arg_5,char *str_6,char *str_7);
void Pic_Load_advfac64_00489188(int arg_1,int arg_2,int arg_3,int arg_4,int arg_5);
void FUN_00489630(uint arg_1);
void Mem_AllocOrFree_00489690(undefined4 arg_1,undefined4 arg_2,undefined4 arg_3);
void FUN_004896be(undefined4 arg_1,int arg_2,uint arg_3);
void FUN_00489710(undefined4 arg_1,undefined4 arg_2,undefined4 arg_3);
int FUN_00489748(char *arg1,int arg2);
int FUN_00489c9c(char *str_1,int arg2);
void FUN_0048a1ba(undefined4 arg_1,int y,undefined4 arg_3,undefined4 arg_4);
void FUN_0048a2a5(int arg_1,int arg_2,int arg_3,int arg_4,undefined4 arg_5);
void FUN_0048a338(int arg_1,int arg_2,int arg_3,int arg_4,undefined4 arg_5,undefined4 arg_6);
void FUN_0048a3cc(int arg_1,int arg_2,int arg_3,int arg_4,int arg_5);
void FUN_0048a6ef(int arg_1,int arg_2,int arg_3,int arg_4,undefined4 *arg_5);
uint FUN_0048ac2f(void);
void FUN_0048aee0(undefined8 *arg1,uint arg2);
int FUN_0048b950(uint *arg_1,undefined4 arg_2,undefined4 arg_3);
undefined4 FUN_0048bba0(int arg_1);
undefined4 __thiscall FUN_0048bda1(void *this);
int FUN_0048be80(undefined4 *arg_1,uint *arg_2,int arg_3);
int FUN_0048c070(int *arg_1,uint *arg_2,int arg_3);
int FUN_0048c6d0(int arg_1);
int FUN_0048c72a(int arg_1);
uint FUN_0048c8b2(char *str_1,int arg2);
void FUN_0048c970(int arg_1);
undefined4 FUN_0048caaf(char *arg_1);
bool FUN_0048caf4(int arg_1,void *arg_2,uint arg_3);
int FUN_0048cb40(void);
undefined4 Mem_AllocOrFree_0048cdf5(void);
undefined4 FUN_0048ce07(char *str_1);
undefined4 FUN_0048d087(char *str_1);
uint FUN_0048d259(void);
uint FUN_0048e01d(void *arg1,uint arg2);
int FUN_0048e0a1(char *str_1);
void Mem_AllocOrFree_0048e0ee(void);
void Mem_AllocOrFree_0048e108(void);
void FUN_0048e122(char *str_1);
uint FUN_0048e1bf(char *str_1);
void FUN_0048e2b0(int arg_1);
void FUN_0048e306(void);
void FUN_0048ea81(int arg_1);
undefined4 FUN_0048eadc(int arg1,int arg2);
undefined4 Sound_LoadWav_x_sound_button2_0048ec68(int arg_1);
int FUN_0048ec9a(int arg1,int arg2);
void FUN_0048ed04(int arg_1,uint *arg_2,int *arg_3);
undefined4 FUN_0048edeb(int arg_1,int arg_2,int arg_3,int arg_4,int arg_5,int arg_6);
undefined4 FUN_0048ee42(void);
undefined4 FUN_0048efc7(int *arg_1,int arg_2,int arg_3,int arg_4,int arg_5,int arg_6);
int FUN_0048f0ae(int *arg_1,int arg_2,int arg_3,int arg_4,int arg_5,int arg_6);
undefined4 FUN_0048f224(int arg1,int arg2);
undefined4 Sound_LoadWav_x_sound_button2_0048f343(int arg_1);
undefined4 FUN_0048f375(int *arg_1,int arg_2,int arg_3);
void Castle_Process_0048f523(void);
int FUN_0049094c(void);
void FUN_004909a0(int arg_1);
void FUN_004909d3(int x,undefined4 arg_2,uint width,int height);
undefined4 FUN_00490ae2(int arg1,int arg2);
undefined4 Sound_LoadWav_x_sound_button2_00490c01(int arg_1);
undefined4 FUN_00490c33(int arg1,int arg2);
undefined4 Sound_LoadWav_x_sound_button2_00490d49(int arg_1);
void Town_Process_00490d7b(void);
undefined4 Castle_Process_00491d8f(undefined4 arg_1,int y,int width,int height);
int FUN_004922dc(void);
void Action_PromptTarget_0049239e(int spell_id);
int FUN_00492cb1(int arg1,int arg2);
void Castle_Process_00492ddf(int arg_1);
int Catalog_Open(char *str_1);
bool Catalog_Close(int arg_1);
undefined4 Catalog_CompareEntryHash(int *arg1,int *arg2);
void * Catalog_FindEntry(int arg1,byte *arg2);
size_t Catalog_ReadFile(int arg_1,undefined4 arg_2,int *arg_3);
uint Catalog_ComputeFilenameHash(byte *arg_1);
undefined4 * ColorOctree_AllocNode(void);
undefined * Catalog_LoadPaletteMap(char *str_1,char *str_2);
undefined4 Palette_InitSquareDistanceTable(void);
void ColorOctree_CollectLeaves(int *arg_1,int arg_2,int *arg_3);
int ColorOctree_BuildClusters(int *arg_1);
undefined4 ColorOctree_InsertColor(undefined4 *arg_1,char *str_2,undefined4 arg_3);
int ColorOctree_FreeTree(int *arg_1);
void Color_QuantizeRGBToPalette(uint arg1,uint *arg2);
undefined4 Palette_BuildFastColorLookup(void);
undefined4 Color_FindNearestRGB(uint arg_1);
uint Color_FindNearestPaletteIndex(uint arg_1);
int ColorOctree_Flatten(int *arg1,int *arg2);
undefined4 Palette_RemapBitmapRGB(uint *x,int y,int width,int height);
uint * Palette_DitherBitmapRGB(uint *arg_1,int arg_2,uint *arg_3,int arg_4,int arg_5,int arg_6);
void Palette_RotateDitherBuffers(undefined4 *arg1,int arg2);
undefined4 Palette_AllocErrorDiffusionTable(int arg1,int arg2);
undefined4 Palette_DitherScanline(int arg_1,int arg_2,int arg_3,int arg_4,int arg_5,int arg_6);
void Palette_Util_00495410(void);
undefined4 Palette_Color_00495430(char *str_1);
void Palette_Subsystem_00495829(void);
int Palette_Subsystem_004958b1(int arg_1);
undefined4 Palette_Subsystem_00495958(char *str_1);
void Palette_Subsystem_00495cde(MSG *arg_1);
undefined4 Palette_Subsystem_00495eec(int *arg1,UINT arg2);
undefined4 Palette_Subsystem_0049608e(void);
void Palette_Subsystem_00496230(void);
undefined4 Palette_Util_00496332(void);
undefined4 Palette_Subsystem_0049635c(HWND arg_1,uint y,HWND arg_3,undefined4 arg_4);
undefined4 Palette_Subsystem_004963e7(void);
LRESULT Palette_Subsystem_00496497(HWND hwnd,uint y,WPARAM arg_3,uint height);
undefined4 Palette_Subsystem_004966a0(void);
uint Palette_Subsystem_00496ccf(void);
void Palette_Util_00496d20(void);
int Palette_Subsystem_00496d30(HDC hdc,int *y,WPARAM *arg_3,int height);
int Palette_Subsystem_00496eaf(void);
undefined4 Palette_Subsystem_00496f10(void);
undefined4 Palette_Subsystem_00496f60(void);
undefined4 Palette_Subsystem_00496fa4(int arg1,int arg2);
undefined4 Palette_Subsystem_0049713c(int arg_1);
uint Palette_Color_0049716e(undefined4 arg_1,uint arg_2,uint arg_3,int arg_4,int arg_5);
void Palette_Subsystem_004981b5(int arg_1);
void Palette_Subsystem_004989a9(int x,int y,int width,undefined4 arg_4);
bool Palette_Subsystem_00498a18(void);
bool Palette_Subsystem_00499720(LPCSTR str_1);
void Palette_Subsystem_004997b8(void);
LRESULT Palette_Subsystem_004997e6(HWND hwnd,uint uMsg,int *wParam,int *lParam);
undefined4 Palette_Color_0049ae00(void);
void Palette_Subsystem_0049b8f5(void);
void Palette_Subsystem_0049c107(void);
undefined4 Palette_Subsystem_0049c3ac(int *arg_1);
void Palette_Subsystem_0049c6cb(HDC hdc,RECT *arg2);
undefined4 Palette_Subsystem_0049c7c7(HDC hdc,int *arg_2,WPARAM *arg_3,int arg_4,uint arg_5,int arg_6);
undefined4 Palette_Subsystem_0049d843(HDC hdc,int *arg_2,int arg_3,int arg_4,int arg_5,uint arg_6,int arg_7);
void Palette_Subsystem_0049da83(int arg_1,int arg_2,uint arg_3);
void Palette_Subsystem_0049dc11(HDC hdc,int arg_2,char *str_3);
int Palette_Subsystem_0049dcd5(HDC hdc,char *str_2);
int Palette_Subsystem_0049ddaa(int *arg1,char *str_2);
uint Palette_Subsystem_0049dfb1(HDC hdc,int arg_2,int arg_3,LONG arg_4,char *str_5);
void Palette_Subsystem_0049e291(int arg_1,char arg_2,int arg_3,int arg_4,int arg_5,int arg_6);
undefined4 Palette_Subsystem_0049e53b(HDC hdc,int arg_2,int arg_3);
uint Palette_Subsystem_0049e5bc(HDC hdc,int *y,char *str_3,int height);
void Palette_Subsystem_0049ebf6(HDC hdc,RECT *arg_2,int arg_3,int arg_4);
void Palette_Subsystem_0049eda9(HDC hdc,int *arg_2,int arg_3,int arg_4,int arg_5);
void Palette_Subsystem_0049f8cd(HDC hdc,int *arg_2,WPARAM *arg_3,int arg_4,int arg_5);
void Palette_Subsystem_0049fb63(HDC hdc,RECT *arg_2,int arg_3);
void Palette_Subsystem_0049fee7(HDC hdc,int *y,uint width,uint height);
void Palette_Subsystem_004a00d1(HDC hdc,int *arg_2,undefined4 arg_3);
undefined4 Palette_Subsystem_004a023a(HDC hdc,int arg_2,undefined4 arg_3);
void Palette_Subsystem_004a0392(LPRECT arg1,int *arg2);
void Palette_Subsystem_004a0466(HDC hdc,int *arg_2,int arg_3,int arg_4,int arg_5);
undefined4 Palette_Subsystem_004a068a(int x,int y,int width,int height);
void Palette_Subsystem_004a080b(LPRECT arg_1,int *arg_2,int arg_3);
undefined4 Palette_Subsystem_004a09c9(int arg_1,int *arg_2,int arg_3,int arg_4,int arg_5);
void Palette_Subsystem_004a0d00(HDC hdc,undefined4 *arg_2,uint arg_3);
void Palette_Subsystem_004a0f97(LPRECT arg_1,uint y,int *width,uint height);
void Palette_Subsystem_004a11fa(HDC hdc,int *arg_2,char *str_3,int arg_4,int arg_5);
void Palette_Subsystem_004a13b7(HDC hdc,int *arg_2,int arg_3,undefined4 arg_4,int arg_5);
void Palette_Subsystem_004a155f(HDC hdc,int *arg_2,int arg_3,int arg_4,int arg_5);
void Palette_Subsystem_004a1b64(HDC hdc,RECT *arg_2,int arg_3,int arg_4,int arg_5,int arg_6,int arg_7);
void Palette_Subsystem_004a1e09(HDC hdc,int *y,int width,int height);
void Palette_Subsystem_004a2401(HDC hdc,int *y,int width,int height);
void Palette_Subsystem_004a26f8(undefined4 arg1,undefined4 arg2);
void Palette_Subsystem_004a277f(undefined4 arg1,undefined4 arg2);
void Palette_Subsystem_004a2806(HDC hdc,int *arg2);
uint Palette_Subsystem_004a289f(HDC hdc,int *y,int width,int height);
void Palette_Subsystem_004a29c5(HDC hdc,int *arg_2,int arg_3);
void Palette_Subsystem_004a2a5b(undefined4 arg_1,int *arg_2,byte arg_3);
void Palette_Subsystem_004a2aa3(LPRECT arg1,int *arg2);
undefined4 Palette_Subsystem_004a2b7e(int arg_1);
void Palette_Subsystem_004a2dce(char *str_1,char *str_2,int arg_3);
void Palette_Util_004a2edc(void);
undefined4 Palette_Subsystem_004a2ef0(int arg_1);
int Palette_Subsystem_004a41fd(void);
void Palette_Subsystem_004a4760(int arg_1,int arg_2,int arg_3);
void Palette_Subsystem_004a486f(int arg1,int arg2);
void Palette_Subsystem_004a4a47(int arg_1,int arg_2,int arg_3);
void Palette_Subsystem_004a554b(int x,int y,int *width,int *height);
void Palette_Subsystem_004a5586(int x,int y,int *width,int *height);
void Palette_Subsystem_004a5603(int arg1,int arg2);
int Palette_Subsystem_004a5722(int arg_1,int arg_2,int arg_3);
void Palette_Subsystem_004a5e4c(void);
void Palette_Subsystem_004a5f7c(void);
void Palette_Subsystem_004a5fdc(void);
void Palette_Subsystem_004a6018(void);
undefined4 Palette_Subsystem_004a610e(int arg1,int arg2);
int Palette_Subsystem_004a62a0(undefined4 arg_1,int arg_2,int arg_3);
undefined4 Palette_Subsystem_004a6370(HWND hwnd,uint uMsg,uint wParam,byte *lParam);
void Palette_Subsystem_004a69c8(HWND hwnd,byte arg_2,byte arg_3);
int Palette_Subsystem_004a6d20(int arg_1,int arg_2,int arg_3);
int Palette_Subsystem_004a6eb8(int arg_1);
undefined4 Palette_Subsystem_004a6fef(int spell_id,int target_id,int flags);
int Palette_Subsystem_004a75bd(int arg_1);
int Palette_Subsystem_004a7650(int arg1,int arg2);
int Palette_Subsystem_004a771b(int arg_1,int arg_2,undefined4 arg_3);
undefined4 Palette_Subsystem_004a7814(int arg_1,int arg_2,int arg_3);
int Palette_Subsystem_004a7a25(int arg_1,int arg_2,int arg_3);
int Palette_Subsystem_004a7bcd(int arg_1,int arg_2,int arg_3);
int Palette_Subsystem_004a7d05(int arg1,int arg2);
undefined4 Palette_Subsystem_004a7e3c(int arg_1,int arg_2,int arg_3);
undefined4 Palette_Subsystem_004a7f2a(int arg_1,int arg_2,int arg_3);
undefined4 Palette_Subsystem_004a8111(int arg_1,int arg_2,int arg_3);
undefined4 Palette_Subsystem_004a8d46(int arg_1,int arg_2,int arg_3);
int Palette_Subsystem_004a8fd8(int arg_1,int arg_2,int width,uint height);
undefined4 Palette_Subsystem_004a9137(int arg_1,int arg_2,undefined4 arg_3);
uint Palette_Subsystem_004a99a0(int arg_1);
void Ai_SaveGameState(void);
void Ai_RestoreGameState(void);
void Ai_PushBoardState(void);
void Ai_PopBoardState(void);
void Ai_ResetEvaluationState(void);
void Ai_GetActivePlayerScore(void);
void Ai_EvaluateCreaturePower(void);
undefined4 Ai_GetOpponentPlayerScore(int arg_1);
undefined4 Ai_CalcLifeAdvantage(int arg_1);
void Ai_CalcCardAdvantage(void);
void Ai_ScoreBoardPosition(void);
undefined4 Ai_Util_004ab510(void);
void Ai_Util_004ab525(void);
int Ai_SimulateCombatRound(int arg_1);
int Ai_ChooseAttackers(int arg1,int arg2);
undefined4 Ai_ChooseBlockers(int arg1,int arg2);
void Ai_FilterValidBlockers(uint *arg1,uint *arg2);
undefined4 Ai_AssignCombatDamage(undefined4 *arg_1,uint *arg_2,uint arg_3,int arg_4,uint arg_5,uint arg_6,undefined4 arg_7,int arg_8,undefined4 arg_9);
HGDIOBJ Ai_DuelDialogProc(HWND hwnd,uint uMsg,HWND wParam,HWND lParam);
void Ai_LoadStartDuel2Backdrop(undefined4 *arg_1,undefined4 *out_buffer,undefined4 *arg_3,undefined4 *arg_4,undefined4 *arg_5,undefined4 *arg_6);
void Ai_Subsystem_004ad77b(int arg_1,int arg_2,int arg_3);
HGDIOBJ Ai_StartDuelWndProc(HWND hwnd,uint uMsg,HWND wParam,HWND lParam);
void Ai_LoadStartDuelBackdrop(undefined4 *arg_1,undefined4 *out_buffer,undefined4 *arg_3,undefined4 *arg_4,undefined4 *arg_5,undefined4 *arg_6,undefined4 *arg_7);
void Ai_Subsystem_004ae716(int x,int y,int width,int height);
void Ai_Subsystem_004ae779(int arg_1);
INT_PTR Ai_Subsystem_004ae8a3(undefined4 arg_1,undefined4 arg_2,undefined4 arg_3,undefined4 arg_4,undefined4 arg_5);
HGDIOBJ Ai_DuelMainWndProc(HWND hwnd,uint uMsg,HDC wParam,HWND lParam);
void Ai_LoadEndDuelBackdrop(undefined4 *arg_1,undefined4 *out_buffer,undefined4 *arg_3,int *arg_4,int *arg_5,int *arg_6,undefined4 *arg_7,undefined4 *arg_8);
void Ai_Subsystem_004af5e3(int x,HGDIOBJ arg_2,HGDIOBJ arg_3,HGDIOBJ arg_4);
undefined4 Ai_Subsystem_004af640(int arg1,int arg2);
LRESULT Ai_Subsystem_004af765(undefined4 arg_1,char *str_2,undefined4 arg_3,undefined4 arg_4,undefined4 arg_5,undefined4 arg_6,undefined4 arg_7,int *arg_8,undefined4 *arg_9,undefined4 arg_10,undefined4 arg_11);
void Ai_Util_004afa46(void);
INT_PTR Ai_ScoreCardPlay_004afa69(int *arg_1,int arg_2,int arg_3,undefined4 arg_4,int arg_5,char *str_6);
LRESULT Ai_ScoreCardPlay_004afc26(HWND hwnd,uint y,HDC hdc,undefined4 *arg_4);
void Ai_Subsystem_004b0d24(int *arg_1,int *arg_2,int *arg_3,int *arg_4,int *arg_5,undefined4 *arg_6);
void Ai_Subsystem_004b0e11(HGDIOBJ arg_1,HGDIOBJ arg_2,HGDIOBJ arg_3,HGDIOBJ arg_4,HGDIOBJ arg_5);
LRESULT Ai_Subsystem_004b0e80(HWND hwnd,uint uMsg,WPARAM wParam,LONG *lParam);
void Ai_Util_004b128e(void);
void Ai_Subsystem_004b137d(uint arg_1,int arg_2,int arg_3);
void Ai_Util_004b1406(void);
INT_PTR Ai_Subsystem_004b1416(int arg_1,undefined4 arg_2,INT_PTR arg_3,char *str_4,char *str_5,char *str_6);
HWND Ai_Subsystem_004b15df(HWND hwnd,uint uMsg,uint wParam,undefined4 *lParam);
INT_PTR Ai_Subsystem_004b1974(int arg_1,undefined4 arg_2,INT_PTR arg_3);
undefined4 Ai_Subsystem_004b19d0(HWND hwnd,uint uMsg,uint wParam,undefined4 *lParam);
INT_PTR Ai_Subsystem_004b1b38(int arg_1,undefined4 arg_2,INT_PTR arg_3);
HGDIOBJ Ai_Subsystem_004b1b9b(HWND hwnd,uint uMsg,HDC wParam,HWND lParam);
LRESULT Ai_Subsystem_004b20e5(HWND hwnd,UINT y,uint width,LPARAM arg_4);
void Ai_Subsystem_004b2183(undefined4 *arg_1,undefined4 *out_buffer,int *arg_3,int *arg_4,int *arg_5,undefined4 *arg_6,undefined4 *arg_7);
void Ai_Subsystem_004b2260(int x,HGDIOBJ arg_2,HGDIOBJ arg_3,HGDIOBJ arg_4);
INT_PTR Ai_Subsystem_004b22bd(int arg_1,undefined4 arg_2,undefined4 arg_3,int arg_4,uint arg_5);
HGDIOBJ Ai_Subsystem_004b257c(HWND hwnd,uint uMsg,HDC wParam,HWND lParam);
void Ai_CalcManaRequirement_004b32d1(undefined4 *arg_1,undefined4 *out_buffer,undefined4 *arg_3,undefined4 *arg_4,undefined4 *arg_5,int *arg_6,int *arg_7,int *arg_8,undefined4 *arg_9,undefined4 *arg_10);
void Ai_Subsystem_004b34fe(int arg_1,int arg_2,int arg_3,HGDIOBJ arg_4,HGDIOBJ arg_5,HGDIOBJ arg_6);
void Ai_Subsystem_004b35b4(LPRECT arg_1,HWND hwnd,int arg_3);
INT_PTR Ai_Subsystem_004b3777(int arg_1,undefined4 *arg_2,undefined4 arg_3,int arg_4,uint arg_5);
HBRUSH Ai_Subsystem_004b3847(HWND hwnd,uint uMsg,HWND wParam,HWND lParam);
void Ai_Subsystem_004b4197(undefined4 *arg_1,undefined4 *out_buffer,int *arg_3,int *arg_4,int *arg_5,undefined4 *arg_6,undefined4 *arg_7);
void Ai_Subsystem_004b4274(int x,HGDIOBJ arg_2,HGDIOBJ arg_3,HGDIOBJ arg_4);
void Ai_Util_004b42d1(void);
uint Ai_Subsystem_004b42dc(void);
void Ai_EvalAttackCandidate_004b4a3f(undefined4 arg1,uint arg2);
void Ai_Util_004b53a1(void);
undefined4 Ai_Util_004b53c6(void);
uint Ai_Subsystem_004b53ed(void);
void Ai_Util_004b542d(void);
void Ai_Util_004b543d(void);
undefined4 Ai_Subsystem_004b544d(void);
void Ai_Subsystem_004b5501(char *str_1);
void Ai_Subsystem_004b553f(char *str_1);
int Ai_Subsystem_004b574d(int arg_1,int arg_2,int arg_3,int arg_4,undefined4 arg_5,undefined4 arg_6);
undefined4 Ai_Subsystem_004b584e(void);
void Ai_Subsystem_004b58d9(int arg_1);
undefined4 Ai_Subsystem_004b5919(int arg1,int arg2);
uint Ai_Subsystem_004b5967(int arg1,int arg2);
undefined4 Ai_Subsystem_004b59d9(int arg1,int arg2);
uint Ai_Subsystem_004b5a46(int arg1,int arg2);
void Ai_Subsystem_004b5ab8(int arg_1,int arg_2,uint *arg_3,uint *arg_4,uint *arg_5);
int Ai_Subsystem_004b5b6f(int arg1,int arg2);
int Ai_Subsystem_004b5bdd(int arg1,int arg2);
undefined4 Ai_Subsystem_004b5c4b(int arg1,int arg2);
undefined4 Ai_Subsystem_004b5cbb(int arg1,int arg2);
undefined4 Ai_Subsystem_004b5d2e(int arg1,int arg2);
byte Ai_Subsystem_004b5de4(int arg1,int arg2);
void Ai_Subsystem_004b5f74(int *arg_1,int arg_2,int arg_3);
undefined4 Ai_Subsystem_004b6023(int *arg_1,int arg_2,int arg_3);
undefined1 Ai_Subsystem_004b613b(int arg1,int arg2);
int Ai_Subsystem_004b61ac(int arg1,int arg2);
int Ai_Subsystem_004b621a(int arg1,int arg2);
uint Ai_Subsystem_004b6288(int arg1,int arg2);
int Ai_Subsystem_004b6356(int arg1,int arg2);
int Ai_Subsystem_004b63c4(int arg1,int arg2);
undefined4 Ai_Subsystem_004b6432(int arg1,int arg2);
undefined4 Ai_Subsystem_004b649f(int arg1,int arg2);
void Ai_Subsystem_004b650c(int x,int y,int *width,int *height);
undefined4 Ai_Util_004b65ad(void);
uint Ai_Subsystem_004b65bf(int arg1,int arg2);
uint Ai_Subsystem_004b6623(int arg1,int arg2);
bool Ai_Subsystem_004b6696(int arg1,int arg2);
undefined4 Ai_Subsystem_004b673e(int arg1,int arg2);
bool Ai_Subsystem_004b67ab(int arg1,int arg2);
bool Ai_Subsystem_004b682f(int arg1,int arg2);
void Ai_Subsystem_004b68b3(int arg_1,int arg_2,char *arg_3);
void Ai_Subsystem_004b69ba(int arg_1,int arg_2,char *arg_3);
int Ai_Subsystem_004b6ba8(int arg_1,int arg_2,void *arg_3);
undefined4 Ai_Subsystem_004b6c5b(int arg1,int arg2);
undefined4 Ai_Subsystem_004b6cc8(int arg1,int arg2);
undefined4 Ai_Subsystem_004b6d35(int arg1,int arg2);
void Ai_Subsystem_004b6da5(undefined4 *arg_1,int arg_2,int arg_3);
undefined4 Ai_Subsystem_004b6e3b(int arg1,int arg2);
int Ai_Subsystem_004b6eab(int arg1,int arg2);
undefined4 Ai_Util_004b6f19(int arg_1);
void Ai_Subsystem_004b6f49(char *str_1);
undefined4 Ai_Subsystem_004b6fa6(int arg_1);
undefined4 Ai_Subsystem_004b700c(int arg_1);
undefined4 Ai_Subsystem_004b7072(void *arg1,int arg2);
undefined4 Ai_Subsystem_004b70fe(void *arg_1,int arg_2,int arg_3);
undefined4 Ai_Subsystem_004b718a(void *arg1,int arg2);
undefined4 Ai_Subsystem_004b722d(void *arg1,int arg2);
undefined4 Ai_Subsystem_004b72d0(void *arg1,int arg2);
undefined4 Ai_Subsystem_004b7373(void *arg_1);
void Ai_Subsystem_004b73ce(int x,int *y,int width,int *height);
void Ai_Subsystem_004b74b1(undefined4 *arg1,undefined4 *arg2);
void Ai_Subsystem_004b74fa(void *arg1,int arg2);
void Ai_Subsystem_004b756f(undefined4 *arg_1);
undefined4 Ai_Subsystem_004b75a4(void);
bool Ai_Subsystem_004b75d8(undefined4 *arg_1);
undefined4 Ai_Subsystem_004b7629(void);
void Ai_Subsystem_004b765d(undefined4 *arg1,undefined4 *arg2);
int Ai_Subsystem_004b76a6(void *arg_1,int y,int width,int height);
void Ai_Subsystem_004b784d(undefined4 arg1,undefined4 arg2);
undefined4 Ai_CalcManaRequirement_004b7897(HWND hwnd,uint uMsg,HDC wParam,int *lParam);
int Ai_Subsystem_004b7d38(char *str_1);
HBRUSH Ai_Subsystem_004b7de8(HWND hwnd,uint uMsg,HDC wParam,HWND lParam);
void Ai_Util_004b82ea(undefined4 *arg1,undefined4 *arg2);
void Ai_Util_004b830e(HGDIOBJ arg_1);
undefined4 Ai_Subsystem_004b832d(int arg_1,int arg_2,undefined4 arg_3,undefined4 arg_4,undefined4 *arg_5,undefined4 *arg_6,undefined4 *arg_7);
HBRUSH Ai_Subsystem_004b8421(HWND hwnd,uint uMsg,HWND wParam,HWND lParam);
void Ai_Subsystem_004b8cc3(undefined4 *arg_1,undefined4 *out_buffer,int *arg_3,int *arg_4,int *arg_5,undefined4 *arg_6,undefined4 *arg_7);
void Ai_Subsystem_004b8da0(int x,HGDIOBJ arg_2,HGDIOBJ arg_3,HGDIOBJ arg_4);
int Ai_Subsystem_004b8dfd(int arg1,int arg2);
char * Ai_Subsystem_004b8e4d(int arg1,int arg2);
void Ai_Subsystem_004b90de(int arg1,int arg2);
undefined4 Ai_CalcManaRequirement_004b9120(LPCSTR str_1);
void Ai_Subsystem_004b920e(void);
LRESULT Ai_CalcManaRequirement_004b9284(HWND hwnd,uint uMsg,char *wParam,uint lParam);
void Ai_Subsystem_004ba6b6(LPRECT arg_1,HWND hwnd,int arg_3);
int Ai_CalcManaRequirement_004ba890(int arg_1,int arg_2,int arg_3);
void Ai_Subsystem_004bb9f3(int x,int arg_2,int *arg_3,int height);
void Ai_Subsystem_004bbb99(int arg_1,int arg_2,int *arg_3,int arg_4,int *arg_5,int arg_6);
void Ai_Subsystem_004bbd93(int arg_1,int arg_2,int *arg_3,int arg_4,int *arg_5,int arg_6);
undefined4 Ai_Subsystem_004bbf8e(int arg_1,int arg_2,int arg_3);
undefined4 Ai_Subsystem_004bc029(undefined4 spell_id,int *target_id,int flags,int height);
undefined4 Ai_CalcManaRequirement_004bc423(void);
undefined4 Ai_Subsystem_004bc72e(int arg_1,undefined4 arg_2,undefined4 arg_3,undefined4 arg_4,int arg_5);
undefined4 Ai_Subsystem_004bd035(int arg_1,int arg_2,byte arg_3);
undefined4 Ai_Subsystem_004bd23f(int arg1,int arg2);
void Ai_Subsystem_004bd3e9(int arg_1,int arg_2,int arg_3,int *arg_4,undefined4 arg_5,int arg_6,int arg_7,int arg_8,int *arg_9);
int Ai_Subsystem_004bd459(int arg_1,int arg_2,int arg_3,int arg_4,int arg_5,int arg_6,int arg_7);
undefined4 Ai_Subsystem_004bd4f0(void);
bool Ai_Subsystem_004bd563(int arg1,int arg2);
bool Ai_Util_004bd5af(void);
undefined4 Ai_Subsystem_004bd5e3(int arg_1);
undefined4 Ai_Subsystem_004bd682(int arg_1);
undefined4 Ai_Subsystem_004bd6f9(int arg_1,uint arg_2,int arg_3);
int Ai_Subsystem_004be192(int x,int y,int width,int height);
void Ai_Util_004be240(void);
void Ai_Subsystem_004be25f(undefined4 arg_1,undefined4 arg_2,undefined4 arg_3,int arg_4,undefined4 arg_5);
void Ai_Subsystem_004be357(void);
void Ai_Subsystem_004be3c4(int *arg_1,int arg_2,int arg_3,int arg_4,int arg_5,int arg_6);
void Ai_Subsystem_004be43f(int x,int y,int *width,int *height);
void Ai_Subsystem_004be49b(int x,int y,int *width,int *height);
void Ai_Subsystem_004be525(int x,int y,int *width,int *height);
void Ai_Subsystem_004be5ae(int x,int y,int *width,int *height);
void Ai_Subsystem_004be643(int arg_1,int arg_2,int arg_3);
void Ai_Subsystem_004bf23a(void);
void Ai_CalcManaRequirement_004bf4b3(int card_id);
void Ai_CalcManaRequirement_004c003d(void);
void Ai_Subsystem_004c05ba(void);
void Ai_Subsystem_004c06df(uint arg1,uint arg2);
void Ai_CastleEncounter_004c0efe(uint arg_1,uint arg_2,int arg_3,int arg_4,uint arg_5,int arg_6,int arg_7,int arg_8);
undefined4 Ai_Subsystem_004c207a(int arg1,int arg2);
undefined4 Ai_Subsystem_004c2270(int arg_1);
int Ai_Subsystem_004c22a2(int x,int y,int width,byte *arg_4);
void Ai_Subsystem_004c2340(undefined4 *arg_1,int arg_2,int arg_3,int arg_4,int arg_5,uint arg_6,int arg_7);
void Ai_CastleEncounter_004c24b3(int arg_1);
void Ai_Subsystem_004c3aa1(int x,int y,int *width,int *height);
void Ai_Subsystem_004c3ad4(int x,int y,int *width,int *height);
void Ai_TownEncounter_004c3b19(uint arg_1);
int Ai_Util_004c3ba3(int arg_1);
int Ai_Util_004c3bc4(int arg_1);
undefined4 Ai_Subsystem_004c3be5(int arg1,int arg2);
void Ai_Subsystem_004c3c5c(int arg_1);
void Ai_Subsystem_004c4210(int arg_1);
void Ai_Subsystem_004c4c84(int arg_1);
uint Ai_Subsystem_004c5fc9(int arg_1);
void Ai_Subsystem_004c7aa8(int arg_1);
void Ai_Subsystem_004c7be5(undefined4 arg1,int arg2);
int Ai_Subsystem_004c7d69(void);
void Ai_EvalAttackCandidate_004c864d(uint spell_id);
undefined4 Ai_Subsystem_004c9f3a(int arg1,uint arg2);
undefined4 Ai_Subsystem_004c9f88(int arg_1);
void Ai_Subsystem_004ca07b(void);
void Ai_Subsystem_004ca0d9(int arg_1,int arg_2,int arg_3,int arg_4,int arg_5,int arg_6,int *arg_7,int *arg_8);
void Ai_Subsystem_004ca714(int arg_1,int arg_2,int arg_3,int arg_4,int arg_5,int arg_6,int *arg_7,int *arg_8);
void Ai_Subsystem_004cab92(void);
void Ai_Subsystem_004cad65(int arg_1,int arg_2,int arg_3);
void Ai_Subsystem_004cadc5(int arg_1,int arg_2,int arg_3);
void Ai_Util_004cae25(WPARAM arg_1);
int Ai_Subsystem_004cae47(int arg1,int arg2);
int Ai_Subsystem_004cb04d(int arg1,int arg2);
undefined4 Ai_Subsystem_004cb1d6(int arg1,int arg2);
undefined4 Ai_Util_004cb2d0(void);
uint Ai_Subsystem_004cbad0(int arg1,int arg2);
undefined4 Ai_Util_004cbb04(int arg1,int arg2);
uint Ai_Subsystem_004cbb33(int arg1,int arg2);
int Ai_Util_004cbba7(int arg1,int arg2);
int Ai_Util_004cbbd7(int arg1,int arg2);
undefined4 Ai_Util_004cbc07(int arg1,int arg2);
undefined4 Ai_Util_004cbc36(int arg1,int arg2);
undefined4 Ai_Subsystem_004cbc65(int arg1,int arg2);
int Ai_Subsystem_004cbcd9(int arg_1);
undefined4 Ai_Subsystem_004cbd67(uint arg_1);
uint Ai_Util_004cbda9(uint arg_1);
void Ai_Subsystem_004cbdda(int arg1,int arg2);
bool Ai_Subsystem_004cbe10(int arg1,int arg2);
byte Ai_Subsystem_004cbe57(int arg1,int arg2);
undefined8 Ai_Subsystem_004cbf72(int arg1,int arg2);
undefined4 Ai_Subsystem_004cbfd0(int arg_1,int arg_2,int *arg_3);
undefined1 Ai_Subsystem_004cc053(int arg1,int arg2);
int Ai_Util_004cc0c7(int arg1,int arg2);
int Ai_Util_004cc0f7(int arg1,int arg2);
undefined4 Ai_Subsystem_004cc127(int arg1,int arg2);
int Ai_Util_004cc188(int arg1,int arg2);
int Ai_Util_004cc1b8(int arg1,int arg2);
char * Ai_Subsystem_004cc1e8(int arg1,int arg2);
int Ai_Subsystem_004cc25b(int arg1,int arg2);
int Ai_Subsystem_004cc2cc(int arg1,int arg2);
undefined4 Ai_Subsystem_004cc33d(int arg_1,int arg_2,undefined4 arg_3);
undefined4 Ai_Subsystem_004cc3c4(int arg1,int arg2);
void Ai_Subsystem_004cc3f8(undefined4 arg_1,undefined4 arg_2,undefined4 arg_3,undefined4 arg_4);
void Ai_Util_004cc42d(char *str_1);
undefined4 Ai_Subsystem_004cc455(int *arg_1,int arg_2,undefined4 arg_3,int arg_4,char *str_5);
undefined4 Ai_Subsystem_004cc49a(int *arg_1,int arg_2,int arg_3,undefined4 arg_4,int arg_5,char *str_6);
void Ai_Util_004cc4e1(undefined4 arg_1);
void Ai_Subsystem_004cc50a(undefined4 arg_1,undefined4 arg_2,char *str_3);
int Ai_Subsystem_004cc56d(int arg_1,int arg_2,int arg_3,int arg_4,int arg_5,char *str_6,int arg_7);
void Ai_Subsystem_004cc7c5(undefined4 arg1,undefined4 arg2);
INT_PTR Ai_Subsystem_004cc814(int arg_1,char *str_2,INT_PTR arg_3,char *str_4,char *str_5,char *str_6);
INT_PTR Ai_Subsystem_004cc87f(int arg_1,char *str_2,INT_PTR arg_3);
INT_PTR Ai_Subsystem_004cc8de(int arg_1,char *str_2,INT_PTR arg_3);
int Ai_Subsystem_004cc93d(int arg_1,undefined4 arg_2,undefined4 arg_3,int arg_4,uint arg_5);
void Ai_Subsystem_004cc97e(char *str_1);
void Ai_Subsystem_004cc9c5(int arg1,int arg2);
void Ai_Subsystem_004ccca3(void);
void Ai_Subsystem_004cced8(void);
void Ai_Subsystem_004cd14f(int arg_1);
void Ai_Subsystem_004cd198(void);
undefined4 Ai_Subsystem_004cd1d1(void);
undefined4 Ai_Subsystem_004cd20e(void);
void Ai_Subsystem_004cd3eb(void);
undefined4 Timer_InitVxD(void);
undefined4 Timer_GetTicks(void);
void Timer_MarkStart(void);
int Timer_GetElapsedFraction(void);
undefined4 SpellChain_RegisterClass(LPCSTR str_1);
void SpellChain_CleanupUI(void);
uint SpellChain_WndProc(HWND hwnd,uint y,HWND param_3,uint height);
int SpellChain_GetCardCount(HWND hwnd);
void SpellChain_UpdateTargetPositions(HWND hwnd,int arg2);
bool SpellChain_HasActiveSpells(void);
int SpellChain_CreateCardSlot(HWND hwnd,undefined4 arg_2,undefined4 arg_3);
void SpellChain_RemoveCardSlot(HWND hwnd,int arg2);
int SpellChain_CreateTargetSlot(HWND hwnd);
void SpellChain_UpdateLayout(HWND hwnd,LPRECT arg2);
void SpellChain_SetWindowRect(undefined4 arg1,LPRECT arg2);
LRESULT SpellChain_MinimizedWndProc(HWND hwnd,uint uMsg,HDC wParam,uint lParam);
BOOL SpellChain_IsVisible(void);
bool SpellChain_IsMinimized(void);
undefined4 SpellChain_GetActiveCount(void);
uint SpellChain_ProcessTriggerEvent(int arg1,int arg2);
undefined4 Card_ColorWard_ChangeColor(int arg_1,int arg_2,int arg_3);
undefined4 Card_ChaosLace_ModifyAttributes(int arg_1,int arg_2,int arg_3);
bool Card_Sinbad_Draw(int arg_1,int arg_2,int arg_3);
undefined4 Card_Kudzu_LandDestruction(int arg_1,int arg_2,int arg_3);
void Card_BronzeTablets_AnteSwap(int arg_1,int arg_2,int arg_3);
undefined4 Card_XenicPoltergeist_AnimateArtifact(int spell_id,int target_id,int flags);
undefined4 Card_VesuvanDoppelganger_Copy(int spell_id,int target_id,int flags);
undefined4 Card_VesuvanDoppelganger_Upkeep(int arg_1,int arg_2,int arg_3);
undefined4 Card_Doppelganger_ClearMimic(int arg1,int arg2);
undefined4 Card_Doppelganger_ApplyMimicStats(int arg1,int arg2);
undefined4 Card_Doppelganger_SyncAbilities(int arg1,int arg2);
undefined4 Card_Doppelganger_CheckState(int arg_1,int arg_2,int arg_3);
undefined4 Card_IslandSanctuary_SkipDraw(int arg_1,int arg_2,int arg_3);
undefined4 Card_IslandSanctuary_AttackRestriction(int arg_1,int arg_2,int arg_3);
undefined4 Card_IslandSanctuary_Trigger(int arg_1,int arg_2,int arg_3);
undefined4 Card_IslandSanctuary_CheckActive(int arg_1,int arg_2,int arg_3);
undefined4 Card_IslandSanctuary_Prompt(int arg_1,int arg_2,int arg_3);
undefined4 Card_LivingLands_AnimateForests(int arg_1,int arg_2,int arg_3);
undefined4 Card_KormusBell_AnimateSwamps(int arg_1,int arg_2,int arg_3);
undefined4 Card_TitaniasSong_AnimateArtifacts(int arg_1,int arg_2,int arg_3);
undefined4 Card_TitaniasSong_RemoveAbilities(int arg_1,int arg_2,int arg_3);
undefined4 Card_TitaniasSong_RestoreAbilities(int arg_1,int arg_2,int arg_3);
undefined4 Card_TitaniasSong_UpdateStatus(int arg_1,int arg_2,int arg_3);
undefined4 Card_TitaniasSong_ClearFlags(int arg_1,int arg_2,int arg_3);
undefined4 Card_TitaniasSong_CheckTrigger(int arg_1,int arg_2,int arg_3);
undefined4 Card_PersonalIncarnation_RedirectDamage(int spell_id,int target_id,int flags);
undefined4 Card_AliFromCairo_PreventLethalDamage(int spell_id,int target_id,int flags);
undefined4 Card_AliFromCairo_ResetState(int arg_1,int arg_2,int arg_3);
undefined4 Card_ShivanDragon_PumpFirebreathing(int arg_1,int arg_2,int arg_3);
undefined4 Card_DragonWhelp_PumpFirebreathing(int arg_1,int arg_2,int arg_3);
int Card_DragonWhelp_EndTurnCheck(int arg_1,int arg_2,int arg_3);
undefined4 Card_FrozenShade_ClearBoost(int arg1,int arg2);
undefined4 Card_FrozenShade_PumpBlack(int arg_1,int arg_2,int arg_3);
undefined4 Card_WaterElemental_PumpBlue(int arg_1,int arg_2,int arg_3);
undefined4 Card_ClockworkBeast_ResetCounters(int arg_1,int arg_2,int arg_3);
undefined4 Card_ClockworkBeast_CombatTrigger(int arg_1,int arg_2,int arg_3);
undefined4 Card_ClockworkBeast_Rewind(int arg_1,int arg_2,int arg_3);
undefined4 Card_ClockworkBeast_GetPower(int arg_1,int arg_2,int arg_3);
undefined4 Card_ClockworkBeast_GetToughness(int arg_1,int arg_2,int arg_3);
undefined4 Card_GaeasLiege_TransformLand(int spell_id,int target_id,int flags);
undefined4 Card_GaeasLiege_ResetLand(int arg_1,int arg_2,int arg_3);
undefined4 Card_GaeasLiege_CheckAttackRestriction(int arg_1,int arg_2,int arg_3);
undefined4 Card_GaeasLiege_IsForest(undefined4 arg_1,undefined4 arg_2,int arg_3);
undefined4 Card_GaeasLiege_CombatCheck(int arg_1,int arg_2,int arg_3);
undefined4 Card_SedgeTroll_CheckSwamp(int arg_1,int arg_2,int arg_3);
undefined4 Card_SedgeTroll_Regenerate(int arg_1,int arg_2,int arg_3);
undefined4 Card_LivingWall_PromptRegenerate(int arg_1,int arg_2,int arg_3);
undefined4 Card_LivingWall_Regenerate(int arg_1,int arg_2,int arg_3);
undefined4 Card_GenericCreature_Regenerate(int arg_1,int arg_2,int arg_3,uint arg_4,int arg_5);
undefined4 Card_GenericCreature_CanRegenerate(int arg1,int arg2);
undefined4 Card_GenericCreature_TriggerRegen(int arg_1,int arg_2,int arg_3);
undefined4 Card_DrudgeSkeletons_Regenerate(int arg_1,int arg_2,int arg_3);
undefined4 Card_UthdenTroll_Regenerate(int arg_1,int arg_2,int arg_3);
undefined4 Card_WillOTheWisp_Regenerate(int arg_1,int arg_2,int arg_3);
undefined4 Card_MarrowThieves_Regenerate(int arg_1,int arg_2,int arg_3);
void Card_HypnoticSpecter_RandomDiscard(int arg_1,int arg_2,int arg_3);
undefined4 Card_TimeElemental_BouncePermanent(int spell_id,int target_id,int flags);
undefined4 Card_NorthernPaladin_DestroyBlack(int spell_id,int target_id,int flags);
undefined4 Card_RoyalAssassin_DestroyTapped(int spell_id,int target_id,int flags);
undefined4 Card_DwarvenDemolitionTeam_DestroyWall(int spell_id,int target_id,int flags);
undefined4 Card_KingSuleiman_DestroyDjinn(int spell_id,int target_id,int flags);
undefined4 Card_Targeting_PromptCreature(int x,int y,int width,uint height);
undefined4 Card_NettlingImp_ForceAttack(int spell_id,int target_id,int flags);
bool Card_NettlingImp_CheckEndTurn(int arg_1,int arg_2,int arg_3);
undefined4 Card_NettlingImp_IsTargetEligible(int arg_1,int arg_2,int arg_3);
undefined4 Card_SorceressQueen_SetStats02(int spell_id,int target_id,int flags);
void Card_SorceressQueen_ResetStats(int arg_1,int arg_2,int arg_3);
undefined4 Card_StoneGiant_Fling(int spell_id,int target_id,int flags);
undefined4 Card_DwarvenWarriors_MakeUnblockable(int spell_id,int target_id,int flags);
undefined4 Card_CavePeople_Mountainwalk(int spell_id,int target_id,int flags);
undefined4 Card_PradeshGypsies_PreventAttack(int spell_id,int target_id,int flags);
undefined4 Card_PradeshGypsies_ResetRestriction(int arg_1,int arg_2,int arg_3);
undefined1 Card_SamiteHealer_PreventDamage(int spell_id,int target_id,int flags);
undefined4 Card_SamiteHealer_CalculateHealAdvantage(int arg_1,int arg_2,int arg_3);
undefined4 Card_AlabasterPotion_HealOrPrevent(int arg_1,int arg_2,int arg_3);
undefined4 Card_HealingSalve_DamagePrevention(int arg_1,int arg_2,int arg_3);
undefined4 Card_DamagePrevention_ApplyBubble(int arg1,int arg2);
undefined4 Card_DamagePrevention_ReduceDamage(int arg_1,int arg_2,int arg_3);
undefined4 Card_DamagePrevention_ClearAtCleanup(int arg_1,int arg_2,int arg_3);
undefined4 Card_DamagePrevention_QueryAmount(int arg_1,int arg_2,int arg_3);
undefined4 Card_DamagePrevention_PromptTarget(int arg_1,int arg_2,int arg_3);
undefined4 Card_DamagePrevention_CheckSource(int arg_1,int arg_2,int arg_3);
undefined4 Card_ErgRaiders_UpkeepDamage(int arg_1,int arg_2,int arg_3);
undefined4 Card_ErgRaiders_MarkAttack(int arg_1,int arg_2,int arg_3);
undefined4 Card_ErgRaiders_ClearTurnAttack(int arg_1,int arg_2,int arg_3);
undefined4 Card_Leviathan_SacrificeLands(int arg_1,int arg_2,int arg_3);
undefined4 Card_Leviathan_PromptLandSacrifice(int spell_id,int target_id,int flags);
undefined4 Card_Leviathan_SelectLand(int arg_1,int arg_2,int arg_3);
undefined4 Card_Leviathan_AttackTrigger(int arg_1,int arg_2,int arg_3);
undefined4 Card_BrothersOfFire_Ping(int spell_id,int target_id,int flags);
bool Card_BrothersOfFire_EvaluateTarget(int arg_1,int arg_2,int arg_3);
undefined4 Card_CrimsonManticore_DamageTarget(int spell_id,int target_id,int flags);
bool Card_ProdigalSorcerer_PingTarget(int spell_id,int target_id,int flags);
bool Card_DirectDamage_EvaluateBestTarget(int arg1,int arg2);
undefined4 Card_DirectDamage_PromptAndDealDamage(int x,int y,int width,int height);
bool Card_PirateShip_PingTarget(int spell_id,int target_id,int flags);
undefined4 Card_PirateShip_CheckIslandwalk(int arg_1,int arg_2,int arg_3);
undefined4 Card_PirateShip_HasIsland(int arg_1,int arg_2,int arg_3);
undefined4 Card_PirateShip_AttackTrigger(int arg_1,int arg_2,int arg_3);
undefined4 Card_IslandFishJasconius_PayToUntap(int arg_1,int arg_2,int arg_3);
undefined4 Card_IslandFishJasconius_CheckIslands(int arg_1,int arg_2,int arg_3);
undefined4 Card_IslandFishJasconius_DestroyIfNoIslands(int arg_1,int arg_2,int arg_3);
uint Card_RodOfRuin_Ping(int arg_1,int arg_2,int arg_3);
undefined4 Card_RodOfRuin_EvaluateAi(int arg_1,int arg_2,int arg_3);
undefined4 Card_RodOfRuin_PayActivation(int arg_1,int arg_2,int arg_3);
undefined4 Card_RodOfRuin_SelectTarget(int arg_1,int arg_2,int arg_3);
bool Card_OrcishArtillery_ShootTarget(int spell_id,int target_id,int flags);
bool Card_PsionicEntity_ShootTarget(int spell_id,int target_id,int flags);
undefined4 Card_PsionicEntity_EvaluateTarget(int arg_1,int arg_2,int arg_3);
undefined4 Card_PsionicEntity_SelfDamage(int arg_1,int arg_2,int arg_3);
undefined4 Card_KhabalGhoul_AddCounterOnDeath(int arg_1,int arg_2,int arg_3);
undefined4 Card_KhabalGhoul_CheckCreatureDeath(int arg_1,int arg_2,int arg_3);
undefined4 Card_KhabalGhoul_ApplyCounterBonus(int arg_1,int arg_2,int arg_3);
undefined4 Card_KhabalGhoul_ResetCounterBonus(int arg_1,int arg_2,int arg_3);
undefined4 Card_LordOfAtlantis_PayOrSacrifice(int arg_1,int arg_2,int arg_3);
undefined4 Card_LordOfAtlantis_ApplyMerfolkBuff(int arg_1,int arg_2,int arg_3);
undefined4 Card_LordOfAtlantis_RemoveMerfolkBuff(int arg_1,int arg_2,int arg_3);
undefined4 Card_LordOfAtlantis_IslandwalkTrigger(int arg_1,int arg_2,int arg_3);
undefined4 Card_LordOfAtlantis_CheckMerfolkType(int arg1,int arg2);
undefined4 Card_ForceOfNature_PayUpkeep(int arg_1,int arg_2,int arg_3);
bool Card_ForceOfNature_AiPayOrTakeDamage(int arg_1,int arg_2,int arg_3);
bool Card_BirdsOfParadise_TapForMana(int spell_id,int target_id,int flags);
undefined4 Card_CosmicHorror_PayUpkeep(int arg_1,int arg_2,int arg_3);
undefined4 Card_LordOfThePit_SacrificeOrDamage(int spell_id,int target_id,int flags);
int Card_LordOfThePit_FindSacrificeCandidate(int arg1,int arg2);
undefined4 Card_KormusBell_PayLandUpkeep(int arg_1,int arg_2,int arg_3);
undefined4 Card_KormusBell_CheckSwampCreature(int arg_1,int arg_2,int arg_3);
undefined4 Card_NetherShadow_CheckGraveyard(int arg_1,int arg_2,int arg_3);
undefined4 Card_NetherShadow_CountCreaturesAbove(int arg_1,int arg_2,int arg_3);
undefined4 Card_NetherShadow_ReturnFromGrave(int arg_1,int arg_2,int arg_3);
undefined4 Card_RockHydra_DecrementHead(int arg_1,int arg_2,int arg_3);
undefined4 Card_RockHydra_DamageTrigger(int arg_1,int arg_2,int arg_3);
void Card_RockHydra_UpdateStatsFromHeads(int arg_1,int arg_2,int arg_3);
undefined4 Card_RockHydra_InitHeads(int arg_1,int arg_2,int arg_3);
undefined4 Card_RockHydra_RegrowHead(int arg_1,int arg_2,int arg_3);
undefined4 Card_AliBaba_TapWall(int spell_id,int target_id,int flags);
undefined4 Card_LeyDruid_UntapLand(int spell_id,int target_id,int flags);
uint Card_LeyDruid_AiEvaluateLand(int arg_1,int arg_2,int arg_3);
undefined4 Card_LeyDruid_ExecuteUntap(int arg_1,int arg_2,int arg_3);
void Card_HurkylsRecall_PickArtifact(int arg_1,int arg_2,int arg_3);
void Card_HurkylsRecall_ReturnAllArtifacts(int arg_1,int arg_2,int arg_3);
undefined4 Card_Venom_DestroyCombatBlocker(int spell_id,int target_id,int flags);
undefined4 Card_Venom_AttachToCreature(int arg_1,int arg_2,int arg_3);
undefined4 Card_Venom_CombatDamageTrigger(int arg_1,int arg_2,int arg_3);
undefined4 Card_Venom_DestroyAtEndOfCombat(int arg_1,int arg_2,int arg_3);
bool Card_Venom_AiEvaluateAura(int arg_1,int arg_2,int arg_3);
undefined4 Card_Venom_AiCastScore(int arg_1,int arg_2,int arg_3);
undefined4 Card_Venom_ClearAuraFlags(int arg_1,int arg_2,int arg_3);
undefined4 Card_RadjanSpirit_RemoveFlying(int spell_id,int target_id,int flags);
undefined4 Card_HurrJackal_GrantCombatAbility(int spell_id,int target_id,int flags);
undefined4 CardQuery_PlayerControlsColor(int arg1,byte arg2);
void CardQuery_ForEachPermanent(undefined *arg1,int arg2);
void Card_IncrementCounter(int arg1,int arg2);
void Card_DecrementCounter(int arg1,int arg2);
void Card_AddCounters(int arg_1,int arg_2,int arg_3);
void Card_RemoveCounters(int arg_1,int arg_2,int arg_3);
void Card_SetCounters(int arg_1,int arg_2,int arg_3);
uint Card_GetCounters(int arg1,int arg2);
bool CardTarget_PromptTargetCreature(int arg_1,uint arg_2,int arg_3);
bool CardTarget_SetTargetCreature(int arg_1,uint arg_2,int arg_3);
int CardTarget_HasValidCreatureTarget(int arg_1);
bool CardTarget_PromptTargetPermanent(int arg_1,uint arg_2,int arg_3);
bool CardTarget_SetTargetPermanent(int arg_1,uint arg_2,int arg_3);
undefined4 CardTarget_HasValidPermanentTarget(int arg_1);
bool CardTarget_PromptTargetPlayerOrCreature(int arg_1,uint arg_2,int arg_3);
bool CardTarget_SetTargetPlayerOrCreature(int arg_1,uint arg_2,int arg_3);
undefined4 CardTarget_HasValidPlayerOrCreatureTarget(int arg_1);
undefined4 Adventure_EnterTownLocation(void);
void Adventure_PromptLocationMenu(void);
int Adventure_HandleLocationMenuChoice(int arg1,int arg2);
void Adventure_ExitTownLocation(void);
int Adventure_PlayLocationMusic(void);
void Adventure_UpdateWorldMapLoop(void);
undefined4 Adventure_GetLocationEncounterIndex(undefined4 arg_1);
undefined4 Adventure_SetLocationEncounterIndex(undefined4 arg_1);
int Adventure_CheckMonsterEncounter(int arg1,int arg2);
void Adventure_FormatNewsString(int arg_1,int arg_2,int arg_3);
undefined4 Adventure_AppendNewsDetails(undefined4 arg1,int arg2);
void Adventure_PlayMonsterEncounterSound(int x,int arg_2,int arg_3,int height);
void Adventure_TriggerDuelFromEncounter(void);
void Adventure_ReloadWorldPalette(int arg_1);
void Adventure_LoadFacePalette(int arg_1);
void Adventure_NewsFlash_EnemyAttack(void);
void Adventure_NewsFlash_Retaliation(int arg_1);
void Adventure_NewsFlash_DominionSpell(void);
void Adventure_Audio_PlayEffect(char *arg_1,undefined4 arg_2,int arg_3,int arg_4,int arg_5);
void Adventure_Audio_PlayEffectAtVolume(undefined4 arg_1,int y,int width,int height);
void Adventure_Audio_PlayEffectLooped(undefined4 arg_1,int arg_2,int arg_3);
void Adventure_Audio_StopEffectChannel(undefined4 arg_1,int arg_2,int arg_3);
void Adventure_Audio_SetPlaybackPosition(char *arg1,undefined4 arg2);
void Adventure_Audio_StopAllTracks(void);
void Adventure_Audio_PlayCastleVictory(int arg_1);
void Adventure_Audio_PlayDuelIntro(int arg_1);
void Adventure_Audio_PlayTerrainAmbience(int arg_1);
void Adventure_Audio_PlayFootstep(void);
uint Adventure_Audio_FindSoundOnDrives(char *str_1);
char Adventure_Audio_GetMusicDrivePath(void);
void Adventure_Audio_FreeSoundTrack(void *arg_1);
undefined4 Adventure_Audio_InitSoundTrack(char *str_1,undefined4 arg_2,undefined4 arg_3);
undefined4 Adventure_Audio_GetTrackStatus(undefined4 arg_1);
int Adventure_Map_GetTerrainAtCoord(uint arg_1);
void Adventure_Map_RedrawViewport(void);
undefined4 Adventure_Map_UpdateLightingAndPalette(uint arg1,uint arg2);
void Adventure_ShowDefeatScreen(void);
bool Adventure_PromptConfirmDialog(LPCSTR str_1);
void Adventure_DestroyConfirmMenu(void);
int Duel_MainArena_WndProc(HWND hwnd,uint y,HWND param_3,uint height);
void Duel_UpdateWindowScroll(HWND hwnd);
void Duel_BringCardWindowToTop(HWND hwnd);
void Duel_GetBattlefieldClientRect(HWND hwnd);
void Duel_LayoutCardSlots(HWND hwnd,int *arg_2,int arg_3,int *arg_4,int *arg_5,int arg_6);
void Duel_ScrollLeftButton_Handler(HWND hwnd,HWND param_2);
void Duel_ScrollRightButton_Handler(HWND hwnd,LPARAM arg_2,byte arg_3);
int Duel_HitTestCardSlot(HWND hwnd,int *y,undefined4 *arg_3,undefined4 *arg_4);
undefined4 Duel_GetHoveredCardSlot(HWND hwnd,int *arg2);
int Duel_GetCardSlotWindowHandle(HWND hwnd,int arg2);
int Duel_GetTargetSlotWindowHandle(HWND hwnd,int arg2);
HGDIOBJ Duel_PaintBattlefieldBackground(HWND hwnd,uint arg_2,HDC hdc);
int Duel_LogActionStatusBanner(int spell_id,int target_id,int flags,uint arg_4,uint arg_5,char *str_6,undefined4 arg_7);
bool Duel_RegisterChildCardWindowClass(LPCSTR str_1);
void Duel_UnregisterCardWindowClass(void);
LRESULT Duel_ChildCard_WndProc(HWND hwnd,uint uMsg,WPARAM wParam,LPARAM lParam);
int Duel_GetCardDrawOriginX(int arg1,int arg2);
int Duel_GetCardDrawOriginY(int arg1,int arg2);
void Duel_TriggerCardDrawAnimation(void);
int Duel_UpdateCardMotionStep(uint arg_1);
void Duel_ResetCardAnimationState(char arg1,char arg2);
int Bazaar_GetCardBaseValue(int arg_1);
int Bazaar_SellCardsDialog(int arg_1);
undefined4 * Catalog_LoadWaveletCardArt(int arg_1,char *str_2,int arg_3);
undefined4 Catalog_ReleaseWaveletLock(void);
undefined8 * Haar_DecompressWaveletImage(int *arg1,undefined8 *arg2);
void FUN_004f1cfa(void);
void Mem_AllocOrFree_004f1e20(undefined8 *arg_1,undefined8 *arg_2,uint arg_3);
void Haar_Transform2D_Inverse(undefined8 *arg_1,uint arg_2,uint arg_3);
void Mem_AllocOrFree_004f1ec0(int *arg_1,int arg_2,int arg_3);
void FUN_004f1ecb(void);
void FUN_004f207a(int arg_1,undefined4 arg_2,int *arg_3,int *arg_4,int *arg_5,int arg_6,undefined4 arg_7,undefined4 arg_8,int arg_9);
void Mem_AllocOrFree_004f2110(int *arg_1,int *arg_2,int *arg_3,int arg_4,int arg_5,undefined4 arg_6,int arg_7);
void FUN_004f211a(int arg_1,undefined4 arg_2,int *arg_3,int *arg_4,int *arg_5,int arg_6,undefined4 arg_7,undefined4 arg_8,int arg_9);
undefined1 *Mem_AllocOrFree_004f21d0(undefined1 *arg_1,int *arg_2,int arg_3,int arg_4,int *arg_5,int *arg_6,int arg_7,undefined4 arg_8,int arg_9);
undefined1 * FUN_004f21db(void);
undefined4 Haar_DecompressHeader(undefined4 *arg1,int *arg2);
uint * FUN_004f27c0(void);
undefined4 FUN_004f2c50(HWND arg_1,int y,int width,int height);
int FUN_004f2d30(HWND hwnd,int arg_2,int arg_3,int arg_4,DWORD arg_5,DWORD arg_6);
undefined4 UI_DialogProc_004f2e60(char *str_1,char *str_2,undefined4 *arg_3);
HGDIOBJ UI_CreateWindow_004f2f56(HWND hwnd,uint y,HDC hdc,HWND param_4);
undefined4 FUN_004f3579(int arg_1);
bool FUN_004f3880(void);
void FUN_004f38dd(void);
void FUN_004f391e(char *str_1);
void FUN_004f3955(HDC hdc);
undefined4 FUN_004f39a4(undefined4 arg_1,int arg_2,undefined4 *arg_3,BITMAPINFO *arg_4,undefined4 *arg_5,undefined4 *arg_6,int *arg_7);
void FUN_004f3b2c(HDC hdc,HGDIOBJ arg2);
undefined4 FUN_004f3b5f(int arg_1,int arg_2,HANDLE arg_3);
undefined4 FUN_004f3bc7(HDC hdc,int *arg_2,HANDLE arg_3,int arg_4,int arg_5,int arg_6,int arg_7);
undefined4 FUN_004f3d11(HDC hdc,int *arg_2,HANDLE arg_3);
undefined4 FUN_004f3e29(HDC arg_1,int *arg_2,HANDLE arg_3);
undefined4 FUN_004f3eaa(HDC hdc,int *arg_2,HANDLE arg_3,int arg_4,int arg_5,int arg_6,int arg_7,int arg_8,int arg_9);
undefined4 FUN_004f4025(undefined4 arg_1,LPCSTR str_2,void *arg_3,undefined4 arg_4);
undefined4 FUN_004f40e6(LPCSTR str_1,void *arg_2,undefined4 arg_3);
HBITMAP FUN_004f41e7(BITMAPINFO *arg1,void *arg2);
void FUN_004f4548(HANDLE arg_1);
undefined4 FUN_004f45da(void);
void FUN_004f48cb(void);
void FUN_004f48f1(int arg_1,int arg_2,RECT *arg_3);
void FUN_004f4a92(char *str_1,char *str_2,int width,char *str_4);
int FUN_004f4ce1(char *str_1,char *str_2,int arg_3);
int FUN_004f4eb3(HWND hwnd,char *str_2);
LRESULT UI_WndProc_004f4fb8(HWND hwnd,UINT uMsg,WPARAM wParam,LPARAM lParam);
undefined4 FUN_004f5048(char *str_1,COLORREF arg_2,HBRUSH arg_3);
void FUN_004f5107(int arg_1,HBRUSH arg_2,HGDIOBJ arg_3,HGDIOBJ arg_4,COLORREF arg_5,int arg_6);
void FUN_004f54d5(int arg_1,HANDLE arg_2,HANDLE arg_3,HANDLE arg_4,COLORREF arg_5,int arg_6);
void FUN_004f570c(HWND hwnd);
undefined4 FUN_004f5728(HWND hwnd);
LRESULT FUN_004f5769(HWND hwnd,UINT y,HWND param_3,LPARAM arg_4);
bool FUN_004f589e(HWND hwnd);
undefined * FUN_004f58eb(char *str_1,int arg2);
void FUN_004f59f7(void);
int FUN_004f5b76(int arg1,int arg2);
undefined4 FUN_004f5bf9(HWND hwnd,int arg_2,int arg_3);
uint FUN_004f5cbc(int arg_1);
undefined4 FUN_004f5d1a(HWND hwnd,uint y,HWND param_3,undefined4 arg_4);
undefined4 FUN_004f5ec4(HWND hwnd,int *arg2);
uint FUN_004f5f20(int arg_1,int arg_2,int arg_3,int arg_4,int arg_5);
void FUN_004f6060(int arg_1,int arg_2,int arg_3,int arg_4,int arg_5,undefined4 arg_6);
int FUN_004f6180(char *str_1);
void Mem_AllocOrFree_004f6b02(void);
undefined4 FUN_004f6b33(LPCSTR str_1);
void Mem_AllocOrFree_004f6d88(void);
char * FUN_004f6db9(undefined4 *arg_1);
undefined4 FUN_004f6e90(int arg_1,int arg_2,int arg_3);
undefined4 FUN_004f714d(int arg_1,int arg_2,int arg_3);
undefined4 Prompts_Load_004f72b0(int spell_id,int target_id,int flags);
undefined4 Prompts_Load_004f7658(int spell_id,int target_id,int flags);
undefined4 FUN_004f7869(int arg_1,int arg_2,int arg_3);
undefined4 FUN_004f7a7a(int arg_1,int arg_2,int arg_3);
undefined4 FUN_004f7bf6(int arg_1,int arg_2,int arg_3);
undefined4 FUN_004f7d11(int arg_1,int arg_2,int arg_3);
undefined4 FUN_004f7eee(int arg_1,int arg_2,int arg_3);
undefined4 FUN_004f8031(int arg_1,int arg_2,int arg_3);
void FUN_004f823a(int arg1,int arg2);
undefined4 FUN_004f8295(int arg_1,int arg_2,int arg_3);
undefined4 Prompts_Load_004f8321(int spell_id,int target_id,int flags);
undefined4 Prompts_Load_004f8672(int spell_id,int target_id,int flags);
undefined4 FUN_004f88ae(int arg_1,int arg_2,int arg_3);
undefined4 Prompts_Load_004f899b(int spell_id,int target_id,int flags);
undefined4 FUN_004f90d7(int arg_1,int arg_2,int arg_3);
undefined4 FUN_004f92f3(int arg_1,int arg_2,int arg_3);
undefined4 FUN_004f9510(int arg_1,int arg_2,int arg_3);
undefined4 FUN_004f95fd(int arg_1,int arg_2,int arg_3);
undefined4 Prompts_Load_004f9737(int spell_id,int target_id,int flags);
undefined4 Prompts_Load_004f9bbd(int spell_id,int target_id,int flags);
undefined4 Prompts_Load_004f9e64(int spell_id,int target_id,int flags);
int FUN_004fa423(int arg1,int arg2);
int FUN_004fa4b8(int arg_1,int arg_2,int arg_3);
undefined4 Prompts_Load_004fa586(int spell_id,int target_id,int flags);
undefined4 Prompts_Load_004fb1e4(int spell_id,int target_id,int flags);
undefined4 FUN_004fb573(int arg_1,int arg_2,int arg_3);
undefined4 Prompts_Load_004fb6b5(int spell_id,int target_id,int flags);
int Prompts_Load_004fbbd4(int spell_id,int target_id,int flags);
undefined4 FUN_004fc023(int arg_1,int arg_2,int arg_3);
int Prompts_Load_004fc2e5(int spell_id,int target_id,int flags);
undefined4 FUN_004fc65e(int arg_1,int arg_2,int arg_3);
undefined4 Prompts_Load_004fc89e(int spell_id,int target_id,int flags);
undefined4 Prompts_Load_004fcb7a(int spell_id,int target_id,int flags);
undefined4 Prompts_Load_004fceea(int spell_id,int target_id,int flags);
undefined4 FUN_004fd11b(int arg_1,int arg_2,int arg_3);
undefined4 Prompts_Load_004fd3cf(int spell_id,int target_id,int flags);
undefined4 FUN_004fd5e4(int arg_1,int arg_2,int arg_3);
undefined4 FUN_004fd844(int arg_1,int arg_2,int arg_3);
int FUN_004fd9c0(int arg1,uint arg2);
int FUN_004fdad2(int arg_1,int arg_2,uint arg_3);
int FUN_004fdc20(int x,int y,uint width,int height);
undefined4 FUN_004fdd4b(int arg_1,int arg_2,int arg_3);
undefined4 FUN_004fde38(int arg_1,int arg_2,int arg_3);
undefined4 FUN_004fdf72(int arg_1,int arg_2,int arg_3);
undefined4 Prompts_Load_004fe05f(int spell_id,int target_id,int flags);
undefined4 Prompts_Load_004fe67f(int spell_id,int target_id,int flags);
undefined4 FUN_004fe901(int arg_1,int arg_2,int arg_3);
undefined4 Prompts_Load_004fe9b6(int spell_id,int target_id,int flags);
undefined4 Prompts_Load_004fef61(int spell_id,int target_id,int flags);
undefined4 Prompts_Load_004ff17f(int spell_id,int target_id,int flags);
undefined4 FUN_004ff36b(int arg_1,int arg_2,int arg_3);
void FUN_004ff450(HWND hwnd);
HBRUSH UI_DialogProc_004ff5c6(HWND hwnd,uint uMsg,HDC wParam,HWND lParam);
void Pic_Load_s_WINBK_Options_004ffd9c(undefined4 *arg_1,undefined4 *out_buffer,undefined4 *arg_3,int *arg_4,int *arg_5,int *arg_6,undefined4 *arg_7,undefined4 *arg_8);
void FUN_004ffe82(HANDLE arg_1,HGDIOBJ arg_2,HGDIOBJ arg_3,HGDIOBJ arg_4);
void Rules_ParseFilter_004ffedf(void);
void Rules_ParseFilter_0050065d(void);
void FUN_00500a5b(void);
void FUN_00500cd5(void);
int WinMain(HINSTANCE x,HINSTANCE y,LPSTR width,int height);
LRESULT UI_WndProc_ShowPaletteClass_005013be(HWND hwnd,uint uMsg,WPARAM wParam,uint lParam);
void FUN_00501671(void);
undefined4 Mem_AllocOrFree_005016f9(void);
undefined4 Mem_AllocOrFree_00501721(void);
void FUN_00501736(int arg_1);
void FUN_0050176a(void);
void FUN_0050178d(void);
undefined4 Sound_LoadWav_sound_locmus1_005017a6(void);
void FUN_005017f0(undefined4 *arg_1,undefined4 arg_2,int arg_3);
void AssertOrLog(int x,int y,int width,char *str_4);
void Assert_Handler_005019a0(int x,int y,int width,char *str_4);
bool UI_CreateWindow_00501ad0(LPCSTR str_1);
LRESULT UI_WndProc_00501b54(HWND hwnd,uint uMsg,WPARAM wParam,uint lParam);
void FUN_00501f50(uint arg_1);
undefined4 FUN_00505c74(void);
bool FUN_00505d20(int arg_1);
undefined4 FUN_00505e3f(int arg_1);
void FUN_00505ea7(int arg_1);
void FUN_00506029(char *str_1);
void FUN_00506102(void);
undefined4 FUN_005062b1(void);
undefined4 FUN_0050638d(int x,int y,int width,int height);
undefined4 FUN_005063f6(int arg1,int arg2);
undefined4 FUN_005064e9(int arg1,int arg2);
int Town_Process_00506580(uint arg_1);
void Sound_LoadWav_x_sound_button2_00507b1a(void);
undefined4 FUN_00507b44(int arg1,int arg2);
undefined4 Town_Process_00507c86(uint arg_1);
void Town_Process_00508c3e(void);
void Town_Process_00508cd7(void);
undefined4 FUN_0050935e(int arg1,int arg2);
void Merchant_ProcessBuy_00509517(void);
void Town_Process_00509fd4(void);
void Town_Process_0050a065(void);
void Town_Process_0050a0fd(void);
void Town_Process_0050a17b(void);
void Town_Process_0050a1f9(void);
void Town_Process_0050a262(void);
void FUN_0050a2e0(int arg_1,int arg_2,char *str_3);
undefined1 * FUN_0050a73e(int arg_1);
int SellPrice(int arg_1);
int FUN_0050a9bf(int arg_1);
undefined4 FUN_0050aef6(int arg1,int arg2);
void FUN_0050afbd(void);
int FUN_0050b00c(void);
int FUN_0050b0fc(byte arg1,byte arg2);
void FUN_0050b1a0(void);
void FUN_0050b206(int arg_1,int arg_2,int arg_3,int arg_4,char *str_5);
void FUN_0050b3de(int arg_1,int arg_2,int arg_3,int arg_4,int arg_5,int arg_6,char *str_7);
void FUN_0050b5be(int arg_1,int arg_2,int arg_3,int arg_4,int arg_5);
void FUN_0050b65f(int arg_1,int arg_2,int arg_3,int arg_4,char *str_5);
void FUN_0050b9d5(int *arg_1);
bool UI_CreateWindow_0050bba0(LPCSTR str_1);
void FUN_0050bcd6(void);
LRESULT UI_CreateWindow_0050bd27(HWND hwnd,uint y,HWND param_3,uint height);
void Mem_AllocOrFree_0050c82b(int arg_1);
LRESULT UI_WndProc_0050c854(HWND hwnd,uint uMsg,HDC wParam,LPARAM lParam);
BOOL GetSaveFileNameA(LPOPENFILENAMEA arg_1);
void MCIWndCreateA(void);
void DeckBuilderMain(void);
undefined4 Mem_AllocOrFree_0050ce80(void);
undefined4 Mem_AllocOrFree_0050ce90(undefined4 arg1,int arg2);
undefined4 * thunk_FUN_0050cef0(void);
void Mem_AllocOrFree_0050cec0(int arg_1);
undefined4 * FUN_0050cef0(void);
undefined4 * FUN_0050d0b0(int x,int y,int width,int height);
undefined4 FUN_0050d2a0(int arg_1);
void FUN_0050d370(int arg1,undefined4 arg2);
void FUN_0050d4a0(int *arg1,int arg2);
void FUN_0050d4e0(int arg_1);
void FUN_0050d520(int arg_1);
void FUN_0050d560(int arg1,int arg2);
uint Surface_GetPixel(int arg_1,int arg_2,int arg_3);
uint Surface_GetPixelPtr(int *arg_1,int arg_2,int arg_3);
void Surface_DrawLine(int *arg_1,int arg_2,int arg_3,int arg_4,int arg_5,int arg_6);
void Surface_PutPixel(int *x,int y,int width,uint height);
void Surface_FillRect(int *arg_1,int arg_2,int arg_3,int arg_4,int arg_5,uint arg_6);
void FUN_0050dce0(int *arg_1,uint arg_2,int arg_3,uint arg_4,DWORD arg_5,int *arg_6,int arg_7,int arg_8);
void FUN_0050e040(int *arg_1,uint arg_2,int arg_3,uint arg_4,DWORD arg_5,int *arg_6,int arg_7,int arg_8);
void Surface_StretchBlt(int *arg_1,int arg_2,int arg_3,int arg_4,int arg_5,int *arg_6,int arg_7,int arg_8,int arg_9,int arg_10);
void FUN_0050e2f0(void);
void FUN_0050e6f0(int *arg_1,int arg_2,int arg_3,int arg_4,int arg_5,int arg_6);
void Surface_PutLine(undefined4 *arg_1,int arg_2,int arg_3,int arg_4,uint arg_5);
void Surface_GetLine(undefined4 *arg_1,int arg_2,int arg_3,int arg_4,uint arg_5);
void FUN_0050e8b0(short *arg_1);
void FUN_0050eb90(int arg_1);
int FUN_0050ec20(HWND hwnd,void *arg_2,int arg_3,int arg_4,DWORD arg_5,DWORD arg_6);
void FUN_0050ec90(undefined4 arg_1,int arg_2,int arg_3);
undefined4 Mem_AllocOrFree_0050ed10(void *arg_1);
int FUN_0050edf0(char *str_1);
undefined4 FUN_0050eef0(int arg1,FILE *fp);
undefined4 FUN_0050f0f0(int arg_1,int arg_2,char *str_3);
undefined4 FUN_0050f1e0(int arg_1,int arg_2,LPCSTR str_3,LPCSTR str_4,int arg_5,DWORD arg_6);
HFONT FUN_0050f2e0(int arg1,LONG arg2);
BOOL FUN_0050f350(int arg_1);
int FUN_0050f390(int arg1,char arg2);
int FUN_0050f440(int *arg1,char *str_2);
int FUN_0050f610(int *arg_1,char *str_2,int arg_3);
int Mem_AllocOrFree_0050f740(int arg_1);
undefined4 FUN_0050f760(int *x,int y,int width,LPCSTR str_4);
int FUN_0050f820(int *x,int y,int width,char *str_4);
void Mem_AllocOrFree_0050fc00(void);
void FUN_0050fc20(void);
void Mem_AllocOrFree_0050fc50(void *arg_1);
size_t FUN_0050fc70(void *arg1,char *str_2);
int Sprite_LoadAll(undefined4 *arg1,char *str_2);
uint Sprite_LoadCount(undefined4 *arg_1,char *str_2,uint arg_3);
int Sprite_ScanRunLength(int arg_1,int arg_2,int arg_3,int arg_4,int arg_5);
void Sprite_EncodeFromSurface(int arg_1,int arg_2,int arg_3,uint arg_4,int arg_5);
void Sprite_DrawDirect(int *x,int y,int width,int height);
void Sprite_DrawClipped(int *x,int y,int width,int height);
void Sprite_DrawScaled(int *arg_1,int arg_2,int arg_3,int arg_4,int arg_5,int arg_6);
void FUN_00510b70(int arg_1,int arg_2,int arg_3,char *str_4,short *arg_5);
void Mem_AllocOrFree_00510de0(int arg1,char *str_2);
void Mem_AllocOrFree_00510e20(int arg1,char *str_2);
void LoadPalNoPic(char *filepath);
void Mem_AllocOrFree_00510e60(char *str_1,short *arg2);
void FUN_00510fc0(int *arg1,int *arg2);
void FUN_00511120(uint *arg1,int *arg2);
int FUN_005112b0(short arg1,short arg2);
int FUN_005115a0(short arg1,short arg2);
undefined4 FUN_00511930(HDC hdc,COLORREF arg_2,int arg_3,int arg_4,int arg_5,int arg_6,int arg_7,int arg_8);
uint FUN_005119e0(HDC hdc,int arg_2,int arg_3,int arg_4,int arg_5,int arg_6,int arg_7,HDC param_8);
uint FUN_00511b90(HDC hdc,int arg_2,int arg_3,int arg_4,int arg_5,int arg_6,int arg_7,HDC param_8,int arg_9,int arg_10);
undefined4 FUN_00511d60(HDC hdc,COLORREF arg_2,int arg_3,int arg_4,int arg_5,int arg_6,int arg_7,int arg_8,int arg_9,int arg_10);
void FUN_00511e20(HDC hdc,int arg_2,int arg_3,int arg_4,int arg_5,int arg_6,int arg_7,int arg_8,int arg_9,HDC param_10);
undefined4 Mem_AllocOrFree_005121d0(void);
undefined4 Mem_AllocOrFree_005121e0(void);
void FUN_005121f0(void);
void FUN_00512200(void);
undefined4 Mem_AllocOrFree_00512210(void);
void Mem_AllocOrFree_00512220(void);
undefined4 * FUN_00512230(char *str_1,undefined4 *arg_2,void *arg_3);
undefined4 FUN_00512500(void *arg_1);
undefined4 FUN_005126b0(byte *arg_1);
undefined4 FUN_00512740(void);
undefined4 FUN_005129a0(byte *arg1,int arg2);
undefined4 FUN_00512b50(void *arg_1);
int FUN_00512ba0(undefined4 arg1,char *str_2);
int FUN_00512c00(undefined4 arg_1,int arg_2,int arg_3,int arg_4,int arg_5,int arg_6,char *str_7);
void Mem_AllocOrFree_00512c90(int arg_1,undefined *arg_2,undefined4 arg_3,int arg_4,int arg_5,int arg_6,int arg_7);
void FUN_00512c9d(void);
void FUN_00513200(int arg_1);
void FUN_005134a0(void);
uint FUN_00513510(int arg_1);
void FUN_005135e0(int arg1,uint arg2);
ATOM UI_Register_ShowPaletteClass_00513820(HINSTANCE hInstance);
void UI_Register_ShowPaletteClass_005138b0(HINSTANCE hInstance,HWND hwnd);
void FUN_00513a70(HDC hdc,int arg_2,int arg_3,int arg_4,int arg_5,uint arg_6);
size_t __cdecl strlen(char *str_1);
int __cdecl sprintf(char *str_1,char *str_2,...);
int __cdecl abs(int arg_1);
char * __cdecl strcat(char *str_1,char *str_2);
char * __cdecl strcpy(char *str_1,char *str_2);
int __cdecl strcmp(char *str_1,char *str_2);
void * __cdecl memcpy(void *ptr_1,void *ptr_2,size_t arg_3);
int __cdecl _vsnprintf(char *str_1,size_t arg_2,char *str_3,va_list arg_4);
void * __cdecl memset(void *ptr_1,int arg_2,size_t arg_3);
clock_t __cdecl clock(void);
void Mem_AllocOrFree_00513bd0(void);
int __cdecl memcmp(void *ptr_1,void *ptr_2,size_t arg_3);
longlong __fastcall __allshl(byte arg1,int arg2);
_onexit_t __onexit(_onexit_t arg_1);
int __cdecl _atexit(_func_4879 *ptr_1);
void entry(void);
int __cdecl _write(int arg_1,void *ptr_2,uint arg_3);
void __dllonexit(void);
void __cdecl initterm(void);
void __setdefaultprecision(void);
undefined4 Mem_AllocOrFree_00514060(void);
int __cdecl __setargv(void);
uint __cdecl _controlfp(uint arg1,uint arg2);
int __cdecl _chdir(char *str_1);
void __fastcall FUN_0070d000(undefined4 arg_1,undefined4 arg_2,ushort *arg_3);
void __fastcall FUN_0070d245(undefined4 arg1,undefined4 arg2);
void FUN_0070d2b5(void);
void __fastcall FUN_0070d300(uint arg_1);
undefined4 __fastcall FUN_0070d392(undefined4 arg_1,uint arg_2,undefined4 arg_3);
void Mem_AllocOrFree_0070d484(undefined4 arg1,uint arg2);


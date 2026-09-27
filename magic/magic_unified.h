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




undefined4 UI_Register_MAGICGAME_BigCardCardClass_00401000(HWND hwnd,uint y,HDC hdc,undefined4 *flags);
bool UI_CreateWindow_00401c91(LPCSTR str_1);
void Mem_AllocOrFree_00401d23(void);
LRESULT UI_WndProc_00401d2e(HWND hwnd,uint uMsg,WPARAM wParam,uint lParam);
undefined4 UI_Register_WINBK_BigCard_00401e65(LPCSTR str_1);
void Mem_AllocOrFree_00401f40(void);
LRESULT UI_WndProc_00401f70(HWND hwnd,uint uMsg,WPARAM wParam,LONG *lParam);
bool FUN_00403189(HWND hwnd,int card_slot);
undefined4 UI_PaintBigCardInfo(int *value,int min_val,int max_val,uint flags,uint flags,uint arg_6,uint arg_7,uint arg_8,uint arg_9,uint arg_10,uint arg_11,uint arg_12,int arg_13,int arg_14,uint arg_15,uint arg_16,uint arg_17,uint arg_18,uint arg_19);
uint Rules_ParseFilter_0040360b(int card_id,int color_mask,char *str_3,int flags,byte flags,byte arg_6,uint arg_7,uint arg_8,uint arg_9,uint arg_10,uint arg_11,uint arg_12,uint arg_13,int arg_14,int arg_15,uint arg_16,uint arg_17,uint arg_18,uint arg_19,uint arg_20);
int FUN_00405277(int player,int card_slot);
void Action_PromptTarget_00405370(uint spell_id,undefined4 target_id,int flags);
int Duel_ChooseTarget(int spell_id,uint target_id,uint flags,uint flags,uint flags,uint arg_6,uint arg_7,uint arg_8,uint arg_9,uint arg_10,int arg_11,int arg_12,uint arg_13,uint arg_14,uint arg_15,uint arg_16,uint arg_17,undefined1 *arg_18,undefined4 arg_19,int *arg_20);
undefined4 FUN_00405edf(int player,int card_slot);
undefined4 FUN_00405f97(int player,int card_slot);
void Csv_LoadInfo_004060e0(void);
void Csv_LoadMaster_004063b8(void);
void Csv_WriteConcise_004064f8(void);
void Csv_ReadConcise_0040659f(void);
void Csv_SearchMaster_00406681(char *filepath,int y,int width,char *str_4);
int FUN_0040683a(char *str_1,int min_val,int max_val,int flags,undefined4 flags);
void FUN_00406a88(char *str_1,int card_slot);
bool FUN_00406b01(char *str_1);
int Deck_FilterAttributes_00406b4c(char *filter_string,int color_mask,uint width,int height);
void Story_Load_0040706f(void);
void Tale_Load_0040710a(int value);
void Hints_Load_004071ce(void);
void Hints_GetNext_0040741b(int value);
int FUN_00407499(int value);
undefined4 FUN_00407747(int value);
char * FUN_004077ae(char *str_1);
char * FUN_00407843(char *str_1,char *str_2,int max_val);
void Merchant_ProcessBuy_00407b34(int value);
void FUN_00407e40(undefined4 player,uint card_slot);
bool Mem_AllocOrFree_00408089(void);
undefined4 FUN_004080b2(void);
undefined4 Mem_AllocOrFree_0040810f(void);
undefined4 Mem_AllocOrFree_0040813d(void);
void FUN_0040816b(undefined4 value);
bool UI_CreateWindow_004081b0(LPCSTR str_1);
void FUN_004082d1(void);
LRESULT UI_WndProc_0040836a(HWND hwnd,uint uMsg,uint wParam,LPSTR lParam);
undefined4 FUN_004088d0(int *value);
undefined4 UI_Register_FACE_BLACK_00408e20(LPCSTR str_1);
void FUN_00409052(void);
LRESULT UI_WndProc_004090f6(HWND hwnd,uint uMsg,uint wParam,uint lParam);
void FUN_004097e2(HDC hdc,RECT *min_val,int max_val);
void FUN_00409b2c(int player,int card_slot);
void FUN_00409c73(undefined4 value);
undefined4 FUN_00409cb2(int value);
undefined4 FUN_00409d10(void);
void FUN_00409db6(void);
void Mem_AllocOrFree_00409e13(undefined4 player,undefined4 card_slot);
undefined4 Mem_AllocOrFree_00409e3c(undefined4 value);
undefined4 FUN_00409e6d(undefined4 value,undefined4 min_val,undefined4 max_val,undefined4 flags);
void FUN_00409eb0(int value);
void FUN_00409f16(int player,int card_slot);
void FUN_00409f99(char *str_1,int y,uint width,int height);
int FUN_0040a02a(int value);
void FUN_0040a16e(void);
void Mem_AllocOrFree_0040a1a3(void);
int Math_RandomRange(int value);
void FUN_0040a1ff(void);
void Mem_AllocOrFree_0040a240(void);
uint FUN_0040a255(uint value);
undefined4 FUN_0040a2c0(void);
int Math_Clamp(int value,int min_val,int max_val);
void FUN_0040a33c(void);
int FUN_0040a36f(int player,int card_slot);
void App_ProcessPendingMessages(void);
void Mem_AllocOrFree_0040a422(void);
int FUN_0040a444(void);
void Mem_AllocOrFree_0040a4ac(void *value,void *min_val,size_t max_val);
void Mem_AllocOrFree_0040a4d4(void *value,void *min_val,size_t max_val);
undefined4 Pic_Load_advfac64_0040a4fc(void);
undefined4 FUN_0040a566(void);
void FUN_0040a5de(void);
void FUN_0040a725(char *value);
void FUN_0040a883(char *value);
void FUN_0040a95d(char *value);
void FUN_0040aaf1(char *value);
void FUN_0040abf9(char *value);
void FUN_0040acfd(char *value);
void FUN_0040adaf(char *value,int min_val,int max_val);
undefined4 FUN_0040ae70(int player,int card_slot);
undefined4 Sound_LoadWav_x_sound_button2_0040b00c(int value);
undefined4 FUN_0040b03e(int player,int card_slot);
undefined4 FUN_0040b143(int value);
undefined4 FUN_0040b2c8(int value);
void FUN_0040b3c2(undefined4 player,undefined4 card_slot);
void FUN_0040b441(int *player,int card_slot);
void FUN_0040b4e8(void);
int Castle_Process_0040b7fa(int value);
void FUN_0040bcff(uint player,uint card_slot);
void Mem_AllocOrFree_0040c180(int value,int min_val,int max_val,int flags,int flags);
void FUN_0040c1ad(char *value,int y,int width,undefined4 flags);
void FUN_0040c274(undefined4 value,int y,int width,undefined4 flags);
void FUN_0040c2af(undefined4 value,int y,int width,undefined4 flags);
void FUN_0040c2e9(undefined4 value,int y,int width,undefined4 flags);
void FUN_0040c336(undefined4 value,int y,int width,int flags);
void FUN_0040c381(undefined4 value,int y,int width,undefined4 flags);
void FUN_0040c3cc(char *value,int y,int width,undefined4 flags);
void FUN_0040c421(undefined4 value,int y,int width,int height);
int FUN_0040c465(char *str_1);
void FUN_0040c4c5(int *value,int min_val,int max_val,int flags,int flags,int *arg_6,int arg_7,int arg_8);
void FUN_0040c550(int *value,int min_val,int max_val,int flags,int flags,int *arg_6,int arg_7,int arg_8);
void FUN_0040c5d9(int *value,int min_val,int max_val,int flags,int flags,int *arg_6,int arg_7,int arg_8);
void FUN_0040c662(int *value,int min_val,int max_val,int flags,int flags,uint arg_6);
void FUN_0040c6c7(int *value,int min_val,int max_val,int flags,int flags,int arg_6);
void FUN_0040c72c(int value,int min_val,int max_val,int flags,uint flags);
uint Surface_GetPixelColor(int player, int card_slot);
undefined4 FUN_0040c7c0(int player,int card_slot);
void FUN_0040c81c(uint value,int min_val,int max_val);
void FUN_0040c889(uint value,int min_val,int max_val);
undefined4 FUN_0040c8fa(int player,int card_slot);
void FUN_0040c959(uint value,int min_val,int max_val);
void FUN_0040c9cc(uint value,int min_val,int max_val);
void FUN_0040ca43(int value,int min_val,int max_val);
uint FUN_0040cb4f(int value,int min_val,char max_val);
undefined4 FUN_0040cbbd(int player,int card_slot);
int FUN_0040cc08(char *str_1);
int Font_DrawFormattedText(int value,int min_val,int max_val,int flags,int flags,int arg_6,int arg_7,int arg_8,undefined4 *arg_9);
void FUN_0040cea5(int value,int min_val,int max_val);
void FUN_0040ced7(int value,int min_val,int max_val);
void FUN_0040cf09(int value,int min_val,int max_val);
void FUN_0040cf3b(int value,int min_val,int max_val);
void FUN_0040cf6d(int x,int y,int width,int height);
void FUN_0040cfa1(int x,int y,int width,int height);
void FUN_0040cfd5(int x,int y,int width,int height);
void FUN_0040d009(int x,int y,int width,int height);
void FUN_0040d03d(int value,int min_val,int max_val);
void FUN_0040d06f(int value,int min_val,int max_val);
void FUN_0040d0a1(int value,int min_val,int max_val);
void FUN_0040d0d3(int value,int min_val,int max_val);
void FUN_0040d105(int value,int min_val,int max_val);
void FUN_0040d137(int value,int min_val,int max_val);
void FUN_0040d169(int value,int min_val,int max_val);
void FUN_0040d19b(int value,int min_val,int max_val);
void FUN_0040d1cd(int x,int y,int width,int height);
void FUN_0040d201(int x,int y,int width,int height);
void FUN_0040d235(int x,int y,int width,int height);
void FUN_0040d269(int x,int y,int width,int height);
void FUN_0040d29d(int x,int y,int width,int height);
void FUN_0040d2d1(int x,int y,int width,int height);
void FUN_0040d305(int x,int y,int width,int height);
void FUN_0040d339(int x,int y,int width,int height);
void FUN_0040d36d(int value,int min_val,int max_val);
void FUN_0040d39f(int value,int min_val,int max_val);
void FUN_0040d3d1(int value,int min_val,int max_val);
void FUN_0040d403(int value,int min_val,int max_val);
void FUN_0040d435(int x,int y,int width,int height);
void FUN_0040d469(int x,int y,int width,int height);
void FUN_0040d49d(int x,int y,int width,int height);
void Font_DrawTextInRect(int x, int y, int width, int height);
undefined4 FUN_0040d510(int value,int min_val,int max_val);
undefined4 FUN_0040d552(int value,int min_val,int max_val);
void FUN_0040d59c(int value,uint min_val,int max_val);
void FUN_0040d64c(int value,uint min_val,int max_val);
void FUN_0040d72b(int value,uint min_val,int max_val);
undefined4 FUN_0040d7e9(int value,int min_val,int max_val);
undefined4 FUN_0040d82b(int value,int min_val,int max_val);
undefined4 FUN_0040d875(int value,int min_val,int max_val);
undefined4 FUN_0040d8b7(int value,int min_val,int max_val);
undefined4 FUN_0040d901(int value,int min_val,int max_val);
int Font_DrawString(int value, uint min_val, int max_val);
int FUN_0040dcca(int x,int y,uint width,int height);
void Sound_LoadWav_x_DuelSounds_artifact_0040de30(int value);
int FUN_0040eab1(void);
void FUN_0040eb04(int value);
void Pic_Load_winbak01_0040eb5a(int player,int card_slot);
undefined4 Mem_AllocOrFree_0040eea2(void);
undefined4 FUN_0040eeb4(int player,int card_slot);
void FUN_0040f514(byte value);
int FUN_0040f636(char *str_1);
int FUN_0040f681(int *player,undefined4 *card_slot);
int FUN_0040f6e9(void);
int FUN_0040f78d(int value);
int FUN_0040f9b7(byte value);
undefined4 FUN_0040fa39(char *str_1,char *str_2,int max_val);
int FUN_0040fbe2(void);
void FUN_0040fc9a(int value,char *str_2,char *str_3);
void Mem_AllocOrFree_0040fcf2(void);
undefined4 Dungeon_Process_0040fcfd(int value,int min_val,int max_val);
void FUN_00410c7d(char *value);
int Card_ApplyTriggerEffect(int value,int min_val,int max_val,int flags,int flags);
undefined4 FUN_00410ef1(int value,int min_val,int max_val);
undefined4 FUN_0041115f(int value,int min_val,int max_val);
undefined4 FUN_00411201(int value,int min_val,int max_val);
undefined4 FUN_0041130e(int value,int min_val,int max_val);
undefined4 FUN_00411753(int value,int min_val,int max_val);
undefined4 FUN_004118a8(int value,int min_val,int max_val);
undefined4 FUN_00411f98(int value,int min_val,int max_val);
undefined4 FUN_0041214b(int value,int min_val,int max_val);
undefined4 FUN_00412246(int value,int min_val,int max_val);
undefined4 FUN_00412413(int value,int min_val,int max_val);
undefined4 FUN_00412586(int value,int min_val,int max_val);
bool FUN_0041268a(int value,int min_val,int max_val);
undefined4 FUN_0041283f(int value,int min_val,int max_val);
undefined4 FUN_00412f15(int value,int min_val,int max_val);
undefined4 FUN_00413570(int value,int min_val,int max_val);
undefined4 FUN_00413869(int value,int min_val,int max_val);
undefined4 FUN_00413a32(int value,int min_val,int max_val);
undefined4 FUN_00413baa(int value,int min_val,int max_val);
undefined4 FUN_00413d01(int player,int card_slot);
undefined4 FUN_00413d8d(int value,int min_val,int max_val);
undefined4 FUN_00413fb4(int value,int min_val,int max_val);
undefined4 FUN_00414270(int value,int min_val,int max_val);
undefined4 FUN_0041459d(int value,int min_val,int max_val);
undefined4 FUN_004147a4(int value,int min_val,int max_val);
undefined4 FUN_00414875(int value,int min_val,int max_val);
undefined4 FUN_00414947(int value,undefined4 min_val,int max_val);
undefined4 FUN_00414ac1(int value,int min_val,int max_val);
undefined4 Prompts_Load_00414d99(int spell_id,int target_id,int flags);
undefined4 FUN_00414f59(int value,int min_val,int max_val);
undefined4 FUN_00415080(int value,int min_val,int max_val);
undefined4 Prompts_Load_004150fe(int spell_id,int target_id,int flags);
undefined4 Prompts_Load_0041529a(int spell_id,int target_id,int flags);
undefined4 Prompts_Load_00415517(int spell_id,int target_id,int flags);
undefined4 Prompts_Load_004156c9(int spell_id,int target_id,int flags);
undefined4 Prompts_Load_00415920(int spell_id,int target_id,int flags);
undefined4 FUN_00415d48(int player,int card_slot);
undefined4 Prompts_Load_00415df8(int spell_id,int target_id,int flags);
undefined4 FUN_00416059(int value,int min_val,int max_val);
undefined4 FUN_00416129(int value,int min_val,int max_val);
undefined4 Prompts_Load_00416222(int spell_id,int target_id,int flags);
undefined4 Prompts_Load_0041652b(int spell_id,int target_id,int flags);
undefined4 Prompts_Load_004167ac(int spell_id,int target_id,int flags);
undefined4 Prompts_Load_00416a6a(int spell_id,int target_id,int flags);
undefined4 FUN_00416cda(int value,int min_val,int max_val);
undefined4 Prompts_Load_00416d36(int spell_id,int target_id,int flags);
undefined4 Prompts_Load_00416f1a(int spell_id,int target_id,int flags);
undefined4 Prompts_Load_004172a6(int spell_id,int target_id,int flags);
undefined4 Prompts_Load_0041765d(int spell_id,int target_id,int flags);
undefined4 FUN_00417919(int value,int min_val,int max_val);
undefined4 FUN_004179a4(int value,int min_val,int max_val);
undefined4 FUN_00417a57(int player,int card_slot);
undefined4 FUN_00417b09(int value,int min_val,int max_val);
undefined4 FUN_00417bb9(int player,int card_slot);
undefined4 FUN_00417c96(int value,int min_val,int max_val);
undefined4 Prompts_Load_00417f38(int spell_id,int target_id,int flags);
undefined4 Prompts_Load_00417ff5(int spell_id,int target_id,int flags);
undefined4 Prompts_Load_00418254(int spell_id,int target_id,int flags);
undefined4 Prompts_Load_004184e1(int spell_id,int target_id,int flags);
bool FUN_004186ac(int value,int min_val,int max_val);
undefined4 FUN_0041872f(int player,int card_slot);
undefined4 Prompts_Load_00418785(int spell_id,int target_id,int flags);
void FUN_00418c59(int x,int y,int width,undefined1 flags);
undefined4 Prompts_Load_00418d2a(int spell_id,int target_id,int flags);
void FUN_004194cf(int x,int y,int width,undefined1 flags);
undefined4 Prompts_Load_004195a4(int spell_id,int target_id,int flags);
undefined4 Prompts_Load_00419d5e(int spell_id,int target_id,int flags);
uint FUN_0041a245(int value,int min_val,int max_val);
undefined4 FUN_0041a4c6(int value,int min_val,int max_val);
undefined4 FUN_0041a782(int value,int min_val,int max_val);
undefined4 FUN_0041adc1(int value,int min_val,int max_val);
undefined4 Prompts_Load_0041b1ae(int spell_id,int target_id,int flags);
uint FUN_0041b695(int value,int min_val,int max_val);
undefined4 FUN_0041b89c(int value,int min_val,int max_val);
void Mem_AllocOrFree_0041b93a(int value,int min_val,int max_val);
void Mem_AllocOrFree_0041b964(int value,int min_val,int max_val);
undefined4 Prompts_Load_0041b98a(int spell_id,int target_id,int flags,int height);
undefined4 Prompts_Load_0041c22f(int spell_id,int target_id,int flags);
undefined4 Prompts_Load_0041c8e1(int spell_id,int target_id,int flags);
uint FUN_0041cb9a(int value,int min_val,int max_val);
undefined4 FUN_0041cf9f(int value,int min_val,int max_val);
undefined4 FUN_0041d019(int value,int min_val,int max_val);
undefined4 Prompts_Load_0041d1ab(int spell_id,int target_id,int flags);
undefined4 FUN_0041d411(int value,int min_val,int max_val);
int FUN_0041d8a6(int value);
void Mem_AllocOrFree_0041d942(int value);
int Card_UntapCard(int value, int min_val, int max_val);
int Card_SetTapState(int value, int min_val, int max_val);
void FUN_0041da41(int player,int card_slot);
int Card_ApplyCombatDamage(int value, int min_val, int max_val, int flags, int flags);
void Mem_AllocOrFree_0041df33(int x,int y,int width,int height);
bool UI_CreateWindow_0041df60(LPCSTR str_1);
LRESULT UI_WndProc_0041dfe4(HWND hwnd,uint uMsg,WPARAM wParam,uint lParam);
undefined4 FUN_0041e370(int player,int card_slot);
undefined4 FUN_0041e486(int player,int card_slot);
undefined4 FUN_0041e682(int player,int card_slot);
undefined4 FUN_0041e8b8(int player,int card_slot);
undefined4 FUN_0041ec8d(int value);
undefined4 FUN_0041ece4(int value);
undefined4 FUN_0041ed3a(int value);
undefined4 Sound_LoadWav_x_sound_button2_0041ed86(int value);
undefined4 FUN_0041edd4(void);
undefined4 Mem_AllocOrFree_0041f12b(int value);
undefined4 Mem_AllocOrFree_0041f159(undefined4 value);
undefined4 FUN_0041f17e(int value,int min_val,int max_val);
undefined4 FUN_0041f213(void);
undefined4 FUN_0041f2af(int player,int card_slot);
int FUN_0041f354(void);
int FUN_0041f391(void);
int FUN_0041f3ea(undefined4 value,undefined4 min_val,int max_val);
undefined4 Sound_LoadWav_x_sound_button2_0041fe70(undefined4 player,int card_slot);
undefined4 Mem_AllocOrFree_0041feab(void);
undefined4 FUN_0041fec7(int value,int min_val,int max_val,int flags,char *str_5,int arg_6);
undefined4 FUN_0041fffc(int value,int *min_val,int max_val,int flags,char *str_5,int arg_6,int arg_7);
undefined4 FUN_0042024f(int player,int card_slot);
undefined4 FUN_0042038c(int *value,int min_val,int max_val,int flags,int flags);
int Save_ProcessGame_004207a8(int value);
undefined4 FUN_004211bd(int player,int card_slot);
undefined4 Sound_LoadWav_x_sound_button2_004212b4(int value);
undefined4 FUN_004212f0(int player,int card_slot);
undefined4 FUN_004214cf(int player,int card_slot);
undefined4 Sound_LoadWav_x_sound_button2_00421655(int value);
undefined4 FUN_004216e5(int player,int card_slot);
undefined4 FUN_004217ea(int value);
undefined4 FUN_0042192b(int value);
void FUN_004219e1(int *value,int min_val,int max_val,int flags,int flags,int arg_6);
undefined4 FUN_00421a81(int player,int card_slot);
undefined4 Castle_Process_00421b32(void);
void FUN_00422b04(int value);
void FUN_00422f06(void);
void Pic_Load_worlbak1_004230bd(int value);
undefined * FUN_004232f0(int value,int min_val,int max_val);
undefined4 Pic_Load_0042351b(int value,undefined4 min_val,undefined4 max_val,char *str_4,undefined1 *flags);
int Pic_Load_00423833(char *str_1);
int Pic_Subsystem_004238ba(char *str_1,int card_slot);
void Pic_Subsystem_004238ee(int value);
void Pic_Util_00423919(undefined4 value);
int Pic_Subsystem_00423940(void);
int Sound_Init(int hInst,undefined4 hWnd,uint flags);
void CloseSnd(void);
undefined4 InitSndTrack(undefined4 value,undefined4 min_val,undefined4 max_val);
undefined4 CloseSndTrack(undefined4 value);
undefined4 StopSndTrack(void);
undefined4 PlaySnd(undefined4 sound_id,undefined4 flags);
undefined4 PlaySndFile(undefined4 filename,undefined4 loop_flag,undefined4 out_handle);
undefined4 StopSnd(undefined4 sound_id);
void PauseSnd(void);
undefined4 ResumeSnd(undefined4 player,undefined4 card_slot);
undefined4 SetPitch(undefined4 value,undefined4 card_slot);
undefined4 GetPitch(undefined4 player,undefined4 card_slot);
undefined4 SetVol(undefined4 value,undefined4 card_slot);
undefined4 GetVol(undefined4 player,undefined4 card_slot);
undefined4 SetPan(undefined4 value,undefined4 card_slot);
undefined4 GetPan(undefined4 player,undefined4 card_slot);
undefined4 UpdateSnd(void);
undefined4 SetSndMarker(undefined4 player,undefined4 card_slot);
undefined4 PlaySndMarker(undefined4 player,undefined4 card_slot);
undefined4 GetSndTime(undefined4 value);
undefined4 ResetSnd(undefined4 player,undefined4 card_slot);
undefined4 GetSndState(undefined4 player,undefined4 card_slot);
undefined4 GetAVISndBuff(undefined4 player,undefined4 card_slot);
undefined4 ReleaseAVISndBuff(undefined4 player,undefined4 card_slot);
undefined4 GetSndHWND(void);
undefined4 IsSndLoaded(undefined4 player,undefined4 card_slot);
undefined4 GetLRUSnd(undefined4 value,undefined4 min_val,undefined4 max_val);
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
void Pic_Subsystem_00425ee3(POINT *x,RECT *min_val,undefined4 *max_val,int *height);
void Pic_Subsystem_004262cf(LPRECT value,int min_val,int max_val,int flags,int flags);
void Pic_Subsystem_00426518(HDC hdc,int card_slot);
LRESULT Pic_Load_004267c5(HWND hwnd,uint uMsg,char *wParam,uint lParam);
void Pic_Subsystem_0042784d(POINT *value,RECT *min_val,undefined4 *max_val);
void Pic_Subsystem_00427a0a(LPRECT value,int y,int width,int height);
void Pic_Subsystem_00427bcb(HDC hdc,int card_slot);
void Pic_Draw_00427e36(int *value,undefined4 *min_val,char *str_3);
void Pic_Util_004280cf(void);
undefined4 Pic_Subsystem_00428320(int value,int min_val,int max_val);
undefined4 Pic_Subsystem_0042881e(int value,int min_val,int max_val);
undefined4 Pic_Subsystem_00428d5a(int value,int min_val,int max_val);
undefined4 Pic_Subsystem_00429237(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_004297ed(int spell_id,int target_id,int flags);
int Pic_Subsystem_00429e7d(int spell_id,int target_id,int flags);
void Pic_Subsystem_0042a0d6(int value,int min_val,int max_val);
uint Pic_Load_0042a1c9(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_0042ac1f(int player,int card_slot);
undefined4 Pic_Subsystem_0042ae1d(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_0042b5f5(int value,int min_val,int max_val);
undefined4 Pic_Subsystem_0042baae(int value,int min_val,int max_val);
undefined4 Pic_Subsystem_0042baee(int value,int min_val,int max_val);
undefined4 Pic_Subsystem_0042bb2e(int spell_id,int target_id,int flags);
void Pic_Subsystem_0042bee5(int spell_id,int target_id,int flags);
void Pic_Subsystem_0042bf45(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_0042bfa5(int x,int y,int width,uint height);
undefined4 Pic_Subsystem_0042c92f(int value,int min_val,int max_val);
int Pic_Subsystem_0042ca53(int player,int card_slot);
undefined4 Pic_Subsystem_0042ce63(int x,int y,int width,int height);
undefined4 Pic_Subsystem_0042d64f(int value,int min_val,int max_val);
undefined4 Pic_Subsystem_0042db29(int value,int min_val,int max_val);
undefined4 Pic_Subsystem_0042dd1f(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_0042e2d9(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_0042e80e(int value,int min_val,int max_val);
undefined4 Pic_Subsystem_0042e8c0(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_0042ec65(int player,int card_slot);
undefined4 Pic_Subsystem_0042ed9f(uint spell_id,int target_id,int flags);
uint Pic_Subsystem_0042f2f8(int value,int min_val,int max_val);
undefined4 Pic_Subsystem_0042f690(int value,int min_val,int max_val);
undefined4 Pic_Subsystem_0042f789(int value,int min_val,int max_val);
undefined4 Pic_Subsystem_0042f87b(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_0042fe9a(int value,int min_val,int max_val);
undefined4 Pic_Subsystem_0043001d(int value,int min_val,int max_val);
undefined4 Pic_Subsystem_004301b4(int value,int min_val,int max_val);
uint Pic_Subsystem_00430252(int value,int min_val,int max_val);
undefined4 Pic_Subsystem_004305f1(int value,int min_val,int max_val);
undefined4 Pic_Subsystem_0043070c(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_00430f0a(int spell_id,int target_id,int flags);
uint Pic_Subsystem_0043143d(int value,int min_val,int max_val);
undefined4 Pic_Subsystem_004316cc(int value,int min_val,int max_val);
undefined4 Pic_Subsystem_004319c5(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_00431ed3(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_004325fe(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_00432b12(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_00432f70(int value,int min_val,int max_val);
undefined4 Pic_Subsystem_00433057(int value,int min_val,int max_val);
undefined4 Pic_Subsystem_00433232(int value,int min_val,int max_val);
void Pic_Subsystem_00433334(int value,undefined4 min_val,int max_val);
undefined4 Pic_Subsystem_00433466(int value,int min_val,int max_val);
undefined4 Pic_Subsystem_0043361c(int value,int min_val,int max_val);
undefined4 Pic_Subsystem_004336f8(int value,int min_val,int max_val);
undefined4 Pic_Subsystem_00433a9e(int value,int min_val,int max_val);
undefined4 Pic_Subsystem_00433b83(int value,int min_val,int max_val);
undefined4 Pic_Subsystem_00433c62(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_00433fb5(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_0043452e(int x,int min_val,int max_val,int flags);
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
undefined4 Pic_Subsystem_0043841c(int value,int min_val,int max_val);
undefined4 Pic_Subsystem_00438893(int value,int min_val,int max_val);
undefined4 Pic_Subsystem_00438995(int value,int min_val,int max_val);
undefined4 Pic_Subsystem_00438ced(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_00439408(int value,int min_val,int max_val);
undefined4 Pic_Subsystem_004397e3(int value,int min_val,int max_val);
uint Pic_Subsystem_00439b92(int spell_id,int target_id,int flags);
void Pic_Subsystem_00439d8b(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_00439e06(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_0043a32c(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_0043ac68(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_0043af93(int value,int min_val,int max_val);
undefined4 Pic_Subsystem_0043b067(int value,int min_val,int max_val);
undefined4 Pic_Subsystem_0043b1d7(int value,int min_val,int max_val);
undefined4 Pic_Subsystem_0043b224(int value,int min_val,int max_val);
undefined4 Pic_Subsystem_0043b424(int value,int min_val,int max_val);
void Pic_Subsystem_0043b6eb(int spell_id,int target_id,int flags);
void Pic_Subsystem_0043b74e(int spell_id,int target_id,int flags);
void Pic_Subsystem_0043b7c9(int x,int y,int width,uint height);
void Pic_Subsystem_0043ba6e(int spell_id,int target_id,int flags);
void Pic_Subsystem_0043bad0(int spell_id,int target_id,int flags);
void Pic_Subsystem_0043bb32(int spell_id,int target_id,int flags);
void Pic_Subsystem_0043bb94(int spell_id,int target_id,int flags);
void Pic_Subsystem_0043bbf6(int spell_id,int target_id,int flags);
void Pic_Subsystem_0043bc58(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_0043bcba(int value,int min_val,int max_val,int flags,int flags);
undefined4 Pic_Subsystem_0043c0b2(int value,int min_val,int max_val);
void Pic_Subsystem_0043c174(int value,int min_val,int max_val);
void Pic_Subsystem_0043c1ab(int value,int min_val,int max_val);
void Pic_Subsystem_0043c1e2(int value,int min_val,int max_val);
void Pic_Subsystem_0043c219(int value,int min_val,int max_val);
void Pic_Subsystem_0043c250(int value,int min_val,int max_val);
undefined4 Pic_Subsystem_0043c287(int spell_id,int target_id,int flags,int height);
undefined4 Pic_Subsystem_0043c8f5(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_0043d1c3(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_0043da0f(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_0043dfbb(int value,int min_val,int max_val);
undefined4 Pic_Subsystem_0043e0f6(int value,int min_val,int max_val);
undefined4 Pic_Subsystem_0043e79c(int value,int min_val,int max_val);
undefined4 Pic_Subsystem_0043ebbf(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_0043f19e(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_0043f51d(int spell_id,int target_id,int flags);
uint Pic_Subsystem_0043faf7(int spell_id,int target_id,int flags);
void Pic_Subsystem_0043fd7b(int value,int min_val,int max_val);
void Pic_Subsystem_0043fdb2(int value,int min_val,int max_val);
void Pic_Subsystem_0043fde9(int value,int min_val,int max_val);
void Pic_Subsystem_0043fe20(int value,int min_val,int max_val);
void Pic_Subsystem_0043fe57(int value,int min_val,int max_val);
undefined4 Pic_Subsystem_0043fe8e(int spell_id,int target_id,int flags,int height);
undefined4 Pic_Subsystem_00440289(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_0044068c(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_00440b49(int value,int min_val,int max_val);
undefined4 Pic_Subsystem_00440db5(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_00441167(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_004414dc(int value,int min_val,int max_val);
undefined4 Pic_Subsystem_0044178f(int value,int min_val,int max_val);
int Pic_Subsystem_00441a42(int player,int card_slot);
bool Pic_Subsystem_00442010(LPCSTR str_1);
uint Pic_Load_004420a1(HWND hwnd,uint y,void *max_val,int *height);
WPARAM Pic_Subsystem_00443b0c(void);
undefined4 Pic_Clip_00443b63(HWND hwnd);
void Pic_Subsystem_004441cc(HWND hwnd,int card_slot);
void Pic_Load_004450c3(int value,int min_val,int max_val);
void Pic_Subsystem_0044559e(void);
undefined4 Pic_Subsystem_004455e3(HWND hwnd,uint y,HDC hdc,undefined4 flags);
uint Pic_Subsystem_004458b0(int player,char *str_2);
uint Ai_ChooseChainResponse(int value);
undefined4 Pic_Subsystem_00446d52(int player,int card_slot);
undefined4 Pic_Subsystem_0044724d(void);
void Pic_Subsystem_004475a4(void);
void Pic_Subsystem_00447a1a(void);
int Pic_Subsystem_00447b57(int player,int card_slot);
undefined4 Magic_BroadcastCardEventInStep(int player,int slot,int event_code,undefined4 event_arg);
void Pic_Subsystem_0044867e(int value,int min_val,int max_val);
undefined4 Pic_Subsystem_004488a0(void);
undefined4 Pic_Subsystem_0044895f(int player,int card_slot);
void Pic_Subsystem_00448e29(int player,int card_slot);
void Pic_Subsystem_0044913a(int player,int card_slot);
void Pic_Subsystem_00449223(int player,int card_slot);
void Pic_Subsystem_0044929c(int player,int card_slot);
bool Pic_Subsystem_00449340(LPCSTR str_1);
void Pic_Subsystem_004494d1(void);
LRESULT Pic_Subsystem_004494ff(HWND hwnd,uint uMsg,char *wParam,uint lParam);
LRESULT Pic_Subsystem_00449fbb(HWND hwnd,uint uMsg,WPARAM wParam,LPARAM lParam);
LRESULT Pic_Subsystem_0044a135(HWND hwnd,uint uMsg,WPARAM wParam,LPARAM lParam);
HWND Pic_Subsystem_0044a402(HWND hwnd,int card_slot);
void Pic_Util_0044a7cc(HWND hwnd);
undefined4 Pic_Subsystem_0044a7e1(int value);
void Pic_Subsystem_0044a839(void);
HGDIOBJ Pic_Load_0044a862(HWND hwnd,uint uMsg,HDC wParam,HWND lParam);
void Pic_Subsystem_0044b26c(LPRECT value,HWND hwnd,int width,int height);
void Pic_Subsystem_0044b460(void);
undefined4 Pic_Util_0044b839(void);
void Pic_Subsystem_0044b84b(void);
void Pic_Subsystem_0044b8aa(void);
void Pic_Subsystem_0044b8da(void);
void Pic_Subsystem_0044b90a(char *player,undefined4 card_slot);
void Pic_Util_0044b943(undefined4 player,short *card_slot);
undefined4 Pic_Util_0044b95a(void);
undefined4 Pic_Subsystem_0044b96c(int value);
bool Pic_Subsystem_0044b9c0(LPCSTR str_1);
void Pic_Subsystem_0044ba83(void);
LRESULT Pic_Subsystem_0044bad4(HWND hwnd,uint y,undefined4 *max_val,LONG *flags);
void Pic_Subsystem_0044cfe4(HWND hwnd);
void Pic_Subsystem_0044d31a(int value,int *min_val,int *max_val,int flags,int flags,int arg_6,int arg_7,int arg_8,HANDLE arg_9);
void Pic_Subsystem_0044d58f(undefined4 value,int min_val,int max_val,int flags,int flags,int arg_6,int *arg_7,int *arg_8,int *arg_9,int *arg_10);
void Pic_Subsystem_0044d61a(char *str_1,HWND hwnd,undefined4 max_val);
void Pic_Subsystem_0044d680(void);
void Pic_Util_0044da1a(void);
undefined4 Pic_Subsystem_0044da25(void);
void Pic_Subsystem_0044e17e(void);
undefined4 Pic_Subsystem_0044e2e7(int x,int y,int width,int height);
void Pic_Subsystem_0044e528(void);
void Pic_Subsystem_0044e75d(int value,int min_val,int max_val);
void Pic_Util_0044e844(int player,int card_slot);
void Pic_Subsystem_0044e864(int player,int card_slot);
void Pic_Subsystem_0044e9ac(void);
int Pic_Subsystem_0044eb9d(int player,int card_slot);
void Pic_Subsystem_0044eca0(void);
void Pic_Subsystem_0044edf5(undefined4 value);
void Pic_Subsystem_0044ef03(LPCSTR str_1);
undefined4 Pic_Load_0044ef70(undefined4 player,LPVOID out_buffer);
undefined4 Pic_Subsystem_0044f1de(undefined4 player,int card_slot);
void Pic_Subsystem_00450711(undefined4 *value,undefined4 *min_val,undefined4 *max_val);
void Pic_Subsystem_0045083f(int player,int card_slot);
void Pic_Util_00450975(DWORD value);
void Pic_Subsystem_004509a1(int value,int *min_val,int max_val,int flags,undefined4 flags,int arg_6,char *arg_7);
int Pic_Load_004509e8(int value,int min_val,int max_val,undefined4 flags,int flags);
int Pic_Subsystem_00451291(int player,int card_slot);
void Pic_Subsystem_0045134b(int value,int min_val,int max_val);
undefined4 Pic_Subsystem_00451a82(void);
int Pic_Subsystem_00451b1c(int player,int card_slot);
uint Pic_Subsystem_00451cb2(void);
int Pic_Subsystem_00451d90(uint player,uint card_slot);
int Pic_Subsystem_00451e40(uint value);
void Pic_Subsystem_0045200d(uint value);
void Pic_Subsystem_00452065(int value);
void Pic_Subsystem_004520b2(void);
undefined4 Pic_Subsystem_004521a6(int value,int min_val,int max_val);
void Pic_Subsystem_00452276(int value);
void Pic_Subsystem_004523fd(int player,int card_slot);
int Pic_Subsystem_0045245e(int player,undefined4 card_slot);
void Pic_Subsystem_004524db(int player,undefined4 card_slot);
int Pic_Subsystem_00452551(int value);
int Pic_Subsystem_0045268f(int value);
void Pic_Subsystem_00452708(char *str_1);
void Pic_Subsystem_0045275a(undefined1 *value);
void Engine_ReportFatalError(char *value);
void UI_DrawCombatBanner(void);
void Minit_Util_0045280c(void);
int Minit_Subsystem_00452827(void);
undefined4 Minit_Subsystem_004528c0(int x,int y,int width,int height);
void Minit_Subsystem_00452ab3(int value,int min_val,int max_val);
void Minit_Subsystem_00452ad9(int value,int min_val,int max_val);
void Minit_Subsystem_00452aff(int value,int min_val,int max_val);
void Minit_Subsystem_00452b25(int value,int min_val,int max_val);
void Minit_Subsystem_00452b4b(int value,int min_val,int max_val);
void Mana_Init_00452b71(int value,int min_val,int max_val,int flags,int flags);
undefined4 Minit_Subsystem_00452e81(int value,int min_val,int max_val);
undefined4 Minit_Subsystem_00452eab(int value,int min_val,int max_val);
undefined4 Minit_Subsystem_00452ed5(int value,int min_val,int max_val);
undefined4 Minit_Subsystem_00452eff(int value,int min_val,int max_val);
undefined4 Minit_Subsystem_00452f29(int value,int min_val,int max_val);
undefined4 Minit_Subsystem_00452f53(int value,int min_val,int max_val);
undefined4 Minit_Subsystem_00452f7d(int value,int min_val,int max_val);
undefined4 Minit_Subsystem_00452fa7(int value,int min_val,int max_val);
undefined4 Minit_Subsystem_00452fd1(int value,int min_val,int max_val);
undefined4 Minit_Subsystem_00452ffb(int value,int min_val,int max_val);
undefined4 Minit_Subsystem_00453025(int value,int min_val,int max_val);
undefined4 Mana_Init_004532f1(int value,int min_val,int max_val);
undefined4 Minit_Subsystem_0045350d(int value,int min_val,int max_val);
undefined4 Minit_Subsystem_004537b0(int spell_id,int target_id,int flags);
undefined4 Minit_Subsystem_00453c60(int value,int min_val,int max_val);
undefined4 Mana_Init_00453fdb(int spell_id,int target_id,int flags);
undefined4 Minit_Subsystem_004543d3(int value,int min_val,int max_val);
undefined4 Minit_Subsystem_004545c7(int value,int min_val,int max_val);
undefined4 Card_Setup_00454702(int value,int min_val,int max_val);
undefined4 Mana_Init_004549ea(int spell_id,int target_id,int flags);
undefined4 Mana_Init_004555c8(int spell_id,int target_id,int flags);
undefined4 Minit_Subsystem_00456158(int value,int min_val,int max_val);
undefined4 Minit_Subsystem_00456218(int value,int min_val,int max_val);
undefined4 Minit_Subsystem_004563fa(int value,int min_val,int max_val);
undefined4 Minit_Subsystem_00456552(undefined4 value,undefined4 min_val,int max_val);
undefined4 Minit_Subsystem_004565d7(int value,int min_val,int max_val);
undefined4 Minit_Subsystem_0045672f(int spell_id,int target_id,int flags);
void Minit_Subsystem_00456d10(int value,int min_val,int max_val);
void Minit_Subsystem_00456d36(int value,int min_val,int max_val);
void Minit_Subsystem_00456d5c(int value,int min_val,int max_val);
void Minit_Subsystem_00456d82(int value,int min_val,int max_val);
void Minit_Subsystem_00456da8(int value,int min_val,int max_val);
undefined4 Minit_Subsystem_00456dce(int x,int y,int width,int height);
undefined4 Mana_Init_00456f29(int spell_id,int target_id,int flags);
undefined4 Minit_Subsystem_004572aa(int spell_id,int target_id,int flags);
undefined4 Minit_Subsystem_00457747(int value,int min_val,int max_val);
undefined4 Minit_Subsystem_00457979(int value,int min_val,int max_val);
undefined4 Minit_Subsystem_00457baf(int value,int min_val,int max_val);
undefined4 Minit_Subsystem_00457d5b(int value,int min_val,int max_val);
undefined4 Minit_Subsystem_00457e67(int spell_id,int target_id,int flags);
undefined4 Minit_Subsystem_00458596(int value,int min_val,int max_val);
undefined4 Minit_Subsystem_004586d8(int value,int min_val,int max_val);
undefined4 Minit_Subsystem_00458895(int value,int min_val,int max_val);
undefined4 Minit_Subsystem_00458c07(int value,int min_val,int max_val);
undefined4 Minit_Subsystem_00458c6f(int player,int card_slot);
undefined4 Minit_Subsystem_00458cae(int value,int min_val,int max_val);
undefined4 Card_Setup_004590b4(int value,int min_val,int max_val);
undefined4 Minit_Subsystem_004592ae(int value,int min_val,int max_val);
undefined4 Minit_Subsystem_004594d8(int spell_id,int target_id,int flags);
undefined4 Minit_Subsystem_004597d4(int spell_id,int target_id,int flags);
undefined4 Minit_Subsystem_00459d0a(int value,int min_val,int max_val);
int Minit_Subsystem_0045a120(int player,int card_slot);
undefined4 Minit_Subsystem_0045a252(int spell_id,int target_id,int flags);
undefined4 Minit_Subsystem_0045a42a(int player,int card_slot);
undefined4 Minit_Subsystem_0045a575(int spell_id,int target_id);
undefined4 Minit_Subsystem_0045a789(int value,int min_val,int max_val);
bool Minit_Subsystem_0045a825(int spell_id,int target_id,int flags);
undefined4 Minit_Subsystem_0045a9ff(int spell_id,int target_id,int flags);
undefined4 Minit_Subsystem_0045b156(int spell_id,int target_id,int flags);
undefined4 Mana_Init_0045b502(int spell_id,int target_id,int flags);
undefined4 Mana_Init_0045b7d9(int spell_id,int target_id,int flags);
undefined4 Minit_Subsystem_0045bc8b(int value,int min_val,int max_val);
undefined4 Minit_Subsystem_0045bd50(int spell_id,int target_id,int flags);
undefined4 Minit_Subsystem_0045c59a(int spell_id,int target_id,int flags);
undefined4 Minit_Subsystem_0045d028(int value,int min_val,int max_val);
undefined4 Minit_Subsystem_0045d1f0(int spell_id,int target_id,int flags);
undefined4 Minit_Subsystem_0045d842(int value,int min_val,int max_val);
undefined4 Minit_Subsystem_0045d88f(int value,int min_val,int max_val);
undefined4 Minit_Subsystem_0045d8dc(int spell_id,int target_id,int flags);
undefined4 Minit_Subsystem_0045dda5(int spell_id,int target_id,int flags);
undefined4 Minit_Subsystem_0045e071(int value,int min_val,int max_val);
undefined4 Minit_Subsystem_0045e1fc(int value,int min_val,int max_val);
undefined4 Minit_Subsystem_0045e2a5(int value,int min_val,int max_val);
undefined4 Minit_Subsystem_0045e350(undefined4 value,undefined4 min_val,int max_val);
void Minit_Subsystem_0045e372(int value,int min_val,int max_val);
void Minit_Subsystem_0045e398(int value,int min_val,int max_val);
void Minit_Subsystem_0045e3be(int value,int min_val,int max_val);
void Minit_Subsystem_0045e3e4(int value,int min_val,int max_val);
void Minit_Subsystem_0045e40a(int value,int min_val,int max_val);
undefined4 Mana_Init_0045e430(int x,int y,int width,int height);
undefined4 Minit_Subsystem_0045ea5b(int value,int min_val,int max_val);
undefined4 Minit_Subsystem_0045ebe4(int spell_id,int target_id,int flags);
undefined4 Minit_Subsystem_0045f258(int value,int min_val,int max_val);
void Minit_Subsystem_0045f3cb(int value,int min_val,int max_val);
void Minit_Subsystem_0045f3f1(int value,int min_val,int max_val);
void Minit_Subsystem_0045f417(int value,int min_val,int max_val);
void Minit_Subsystem_0045f43d(int value,int min_val,int max_val);
void Minit_Subsystem_0045f463(int value,int min_val,int max_val);
void Minit_Subsystem_0045f489(int value,int min_val,int max_val);
undefined4 Minit_Subsystem_0045f4af(int x,int y,int width,int height);
undefined4 Minit_Subsystem_0045f682(int value,int min_val,int max_val);
int Minit_Subsystem_0045f82b(int value,int min_val,int max_val);
undefined4 Minit_Subsystem_0045fdb5(int value,int min_val,int max_val);
undefined4 Minit_Subsystem_0046007c(int value,int min_val,int max_val);
undefined4 Minit_Subsystem_004603b5(int value,int min_val,int max_val);
undefined4 Minit_Subsystem_004604e2(int value,int min_val,int max_val);
undefined4 Minit_Subsystem_004605e4(int spell_id,int target_id,int flags);
undefined4 Minit_Subsystem_00460a22(int value,int min_val,int max_val);
undefined4 Minit_Subsystem_00460bfa(int value,int min_val,int max_val);
undefined4 Minit_Subsystem_00461041(int value,int min_val,int max_val);
undefined4 Minit_Subsystem_004611f4(int value,int min_val,int max_val);
undefined4 Minit_Subsystem_00461390(int value,int min_val,int max_val);
undefined4 Minit_Subsystem_004617ad(int spell_id,int target_id,int flags);
undefined4 Minit_Subsystem_00461ba1(int spell_id,int target_id,int flags);
void Minit_Subsystem_00461f3e(int value,int min_val,int max_val);
undefined4 Minit_Subsystem_004620c3(int value,int min_val,int max_val);
undefined4 Minit_Subsystem_0046228f(int value,int min_val,int max_val);
undefined4 Minit_Subsystem_004622d9(int spell_id,int target_id,int flags);
undefined4 Minit_Subsystem_004626d2(int value,int min_val,int max_val);
undefined4 Minit_Subsystem_00462a0a(int spell_id,int target_id,int flags);
undefined4 Minit_Subsystem_00462d1e(int value,int min_val,int max_val);
undefined4 Minit_Subsystem_00462f7e(int spell_id,int target_id,int flags);
undefined4 Minit_Subsystem_00463723(int value,int min_val,int max_val);
undefined4 Minit_Subsystem_00463c10(int value,int min_val,int max_val);
undefined4 Minit_Subsystem_00463cd1(int spell_id,int target_id,int flags);
undefined4 Minit_Subsystem_00463ef0(int spell_id,int target_id,int flags);
undefined4 Minit_Subsystem_0046410a(int value,int min_val,int max_val);
undefined4 Minit_Subsystem_0046458f(int value,int min_val,int max_val);
int Minit_Subsystem_00464723(int value,int min_val,int max_val);
void Minit_Subsystem_00464b28(int value,int min_val,int max_val);
void Minit_Subsystem_00464b4e(int value,int min_val,int max_val);
undefined4 Minit_Subsystem_00464b74(int x,int y,int width,int height);
undefined4 Minit_Subsystem_00464fcd(int value,int min_val,int max_val);
undefined4 Minit_Subsystem_00465165(int spell_id,int target_id,int flags);
undefined4 Minit_Subsystem_00465602(int value,int min_val,int max_val);
void Minit_Subsystem_004659d9(int value,int min_val,uint max_val);
uint Minit_Subsystem_00465a19(int player,int card_slot);
undefined4 Minit_Subsystem_00465a75(int spell_id,int target_id,int flags);
undefined4 Minit_Subsystem_00465e9c(int spell_id,int target_id,int flags);
undefined4 Minit_Subsystem_004662e2(int value,int min_val,int max_val);
undefined4 Minit_Subsystem_00466541(int spell_id,int target_id,int flags);
undefined4 Card_Setup_0046695e(int value,int min_val,int max_val);
undefined4 Minit_Subsystem_00466abb(int value,int min_val,int max_val);
undefined4 Minit_Subsystem_00466d29(int value,int min_val,int max_val);
undefined4 Minit_Subsystem_00466f5c(int value,int min_val,int max_val);
undefined4 Player_Init_0046709c(int spell_id,int target_id,int flags);
undefined4 Minit_Subsystem_0046736a(int value,int min_val,int max_val);
undefined4 Minit_Subsystem_0046746c(int value,int min_val,int max_val);
undefined4 Minit_Subsystem_0046758c(void);
undefined4 Minit_Subsystem_004677ae(int value,int min_val,int max_val);
bool Minit_Subsystem_00467880(LPCSTR str_1);
void Minit_Subsystem_0046799f(void);
LRESULT Card_Setup_00467a68(HWND hwnd,uint uMsg,LONG *wParam,int *lParam);
void FUN_0046aa75(HWND hwnd);
undefined4 FUN_0046ab25(HWND hwnd);
int FUN_0046ad4a(HWND hwnd);
bool FUN_0046adbc(int player,int card_slot);
uint FUN_0046b04a(int player,int card_slot);
bool FUN_0046b3e6(int player,int card_slot);
bool FUN_0046b41c(int player,int card_slot);
void Mem_AllocOrFree_0046b4bb(int player,int card_slot);
void FUN_0046b4db(char *str_1,int min_val,undefined4 max_val);
void FUN_0046b887(char *str_1,int min_val,int max_val);
void Mem_AllocOrFree_0046b92b(void);
void FUN_0046ba19(HDC hdc,int y,undefined4 max_val,undefined4 flags);
undefined4 FUN_0046bb29(HWND hwnd,int *card_slot);
undefined4 FUN_0046bbab(HWND hwnd,int card_slot);
undefined4 FUN_0046bc2f(HWND hwnd);
LONG FUN_0046bc92(HWND hwnd);
int FUN_0046bcc0(WPARAM value,int min_val,int width,int height);
undefined4 FUN_0046bf31(int player,int card_slot);
int FUN_0046bfc2(HDC hdc,RECT *min_val,int width,int flags);
undefined4 FUN_0046c09f(WPARAM value,int min_val,int width,int height);
void FUN_0046c1b3(int value);
int FUN_0046c203(WPARAM value,int y,int width,int height);
undefined * FUN_0046c4b5(int player,int card_slot);
int FUN_0046c54b(HDC hdc,RECT *min_val,int width,int height);
undefined4 FUN_0046c636(WPARAM value,int y,int width,int height);
void FUN_0046c6e5(int player,int card_slot);
void FUN_0046c859(void);
void Castle_Process_0046c8b0(void);
void Sprite_Load_BK_AMG_0046d333(undefined4 value,int min_val,int max_val);
void FUN_0046e70d(int player,int card_slot);
void FUN_0046e77a(char *player,int card_slot);
int FUN_0046e922(uint value);
void FUN_0046e960(void);
undefined4 FUN_0046ed22(uint value,int min_val,int max_val,int flags,int flags,int arg_6);
undefined1 * Sprite_ResolveAssetPath(char *str_1);
void FUN_0046f21e(char *value,undefined4 min_val,undefined4 max_val);
void FUN_0046f300(void);
int Magic_ExecuteDrawPhase(int value);
void Prompts_Load_0046fa40(int spell_id,int target_id,int flags);
undefined4 FUN_0046fe86(int player,int card_slot);
undefined4 FUN_0046ff50(int value,int min_val,int max_val);
undefined4 FUN_00470b36(int player,int card_slot);
bool FUN_00470ea3(int value,int min_val,int max_val);
bool FUN_0047103b(int player,int card_slot);
undefined4 FUN_00471971(int player,int card_slot);
undefined4 FUN_00471aba(int value,int min_val,int max_val);
bool FUN_00471bc0(int player,int card_slot);
bool Card_IsTapped(int player,int card_slot);
undefined4 FUN_00471ca4(int player,int card_slot);
void FUN_00471d16(uint value);
undefined4 FUN_00472616(int value);
undefined4 FUN_004726c5(int player,int card_slot);
bool FUN_004728c3(int player,int card_slot);
undefined4 FUN_00472905(int value);
undefined4 FUN_00472a0a(int value);
undefined4 FUN_00472b91(int x,int min_val,int max_val,int flags);
bool FUN_00472c0c(int value,int min_val,undefined4 max_val,undefined4 flags,uint flags,uint arg_6);
int FUN_00472e08(int x,int y,undefined4 max_val,undefined4 flags);
void FUN_00472f0c(undefined4 player,int card_slot);
void FUN_00472fae(void);
uint Magic_QueryCardAttribute(int player,int slot,int event_code,undefined4 target_slot);
undefined4 Card_ColorMaskToColorIndex(byte value);
undefined * Mem_AllocOrFree_00473d7e(int value);
int FUN_00473d98(int value);
undefined4 Magic_BroadcastCardEvent(int player,undefined4 slot,int event_code);
void Magic_ScanCards(int value);
int Magic_TriggerCardEvent(int player,int slot,int event_code,undefined4 target_player,undefined4 target_slot);
bool Magic_IsManaSource(int player,int slot);
void Magic_PushEventContext(void);
void Magic_PopEventContext(void);
void Magic_UntapTurnPhase(void);
void Magic_CheckTurnTriggers(int player,int card_slot);
undefined4 Duel_PlaySoundById(int value);
void Duel_PreloadSoundEffects(void);
void FUN_00474d0e(void);
undefined4 Magic_ClearSpellStack(void);
undefined4 FUN_00474d4a(void);
undefined4 Magic_MainTurnPhase(undefined4 value);
undefined4 Magic_PushSpellStack(int player,int slot,int event_code,int target_slot,undefined4 flags);
undefined4 FUN_004755fd(void);
undefined4 Magic_ResolveTopSpell(void);
undefined4 Magic_DropTopSpell(void);
void Mem_AllocOrFree_00475c61(void);
undefined4 FUN_00475c8a(int x,int min_val,char *max_val,undefined4 flags);
int Magic_CleanupPhase(int x,int y,char *str_3,undefined4 flags);
undefined4 FUN_00476205(int x,undefined4 min_val,char *max_val,int flags);
undefined4 Magic_RunTurnStep(int player,undefined4 step_code,char *step_name,int repeat_while_active);
undefined4 FUN_0047643e(void);
int FUN_00476482(int player,int card_slot);
void FUN_00476510(void);
undefined4 FUN_00476675(int player,int card_slot);
void FUN_004767ee(int value);
undefined4 FUN_004769c4(int player,int card_slot);
void FUN_00476a80(void);
void FUN_00476b0e(void);
uint FUN_00476c77(int x,int y,int width,int height);
undefined4 Prompts_Load_00476e60(LPCSTR filepath);
void FUN_004770bc(void);
uint UI_Register_WINBK_TellUser_004771fa(HWND hwnd,uint y,LPSTR str_3,int height);
void FUN_00477d73(HWND hwnd,char *str_2,uint max_val);
void FUN_00478163(HWND hwnd);
void FUN_0047820f(HWND hwnd,HDC hdc,int *max_val);
int FUN_00478370(WPARAM value,int y,int width,int height);
undefined * FUN_0047865c(int player,int card_slot);
int FUN_004786f3(int x,int y,int width,int height);
int FUN_00478763(HDC hdc,RECT *min_val,int width,int height);
undefined4 FUN_0047884f(WPARAM value,int y,int width,int height);
void FUN_004788e0(int player,int card_slot);
void FUN_00478a56(void);
int FUN_00478aa4(int value,int min_val,int max_val);
byte UI_CreateWindow_00478b20(LPCSTR str_1);
void FUN_00478bd5(void);
uint UI_WndProc_00478c08(HWND hwnd,uint uMsg,uint *wParam,LONG *lParam);
int FUN_00479d16(HWND hwnd,int card_slot);
int FUN_00479dac(HWND hwnd,int card_slot);
void FUN_00479e3f(HWND hwnd,LPRECT card_slot);
undefined4 Mem_AllocOrFree_00479fb0(int player,int card_slot);
undefined4 Mem_AllocOrFree_00479fdc(int value);
undefined4 FUN_00479ff9(int player,int card_slot);
int Sprite_Load_begin_0047a2e6(void);
undefined4 FUN_0047a94c(int player,int card_slot);
undefined4 Sound_LoadWav_x_sound_button2_0047aa4a(int value);
undefined4 FUN_0047aa7c(int player,int card_slot);
int Pic_Load_menu2_hi_0047abf1(void);
undefined4 FUN_0047afa2(int player,int card_slot);
undefined4 Sound_LoadWav_x_sound_button2_0047b097(int value);
undefined4 FUN_0047b0c9(int player,int card_slot);
undefined4 Pic_Load_menu3_but1_0047b208(void);
undefined4 FUN_0047b616(int player,int card_slot);
undefined4 Sound_LoadWav_x_sound_button2_0047b70b(int value);
undefined4 FUN_0047b73d(int player,int card_slot);
int Sprite_Load__16faces_0047b899(void);
void FUN_0047bcf1(undefined4 *value,int min_val,int max_val,int flags,int flags,undefined4 *arg_6,int arg_7,int arg_8);
void Pic_Load_namepick_0047be64(char *filepath);
undefined4 FUN_0047c080(int player,int card_slot);
undefined4 Sound_LoadWav_x_sound_button2_0047c175(int value);
void Sprite_Load__16faces_0047c1a7(int value);
undefined4 Pic_Load_advfac64_0047c1fe(undefined4 *value,int y,int width,int height);
undefined4 FUN_0047c2fd(int value);
undefined4 FUN_0047c360(char *str_1,uint min_val,uint max_val);
undefined4 UI_Register_sPoison_0047c640(LPCSTR str_1);
void FUN_0047c734(void);
LRESULT UI_WndProc_0047c7aa(HWND hwnd,uint uMsg,char *wParam,uint lParam);
void FUN_0047d3cf(undefined4 value);
undefined4 FUN_0047d40e(int value);
undefined4 UI_Register_WINBK_Attack_0047d460(LPCSTR str_1);
void FUN_0047d85c(void);
uint UI_Register_MAGICGAME_CardClass_0047da80(HWND hwnd,uint y,HWND param_3,HWND param_4);
undefined4 FUN_00481491(int value,int min_val,int max_val);
void FUN_00481586(HWND hwnd);
void FUN_0048201a(HWND hwnd,LPRECT card_slot);
bool FUN_0048225c(int player,int card_slot);
uint UI_WndProc_004822b7(HWND hwnd,uint uMsg,uint wParam,int lParam);
void FUN_00482d6f(HWND hwnd);
LRESULT UI_WndProc_00482dd6(HWND hwnd,uint uMsg,HDC wParam,uint lParam);
int FUN_00483139(HWND hwnd,int *min_val,undefined4 *max_val,undefined4 *flags,undefined4 *flags);
int FUN_004833e9(HWND hwnd,int card_slot);
void FUN_00483590(char *str_1,int min_val,int max_val);
undefined4 FUN_0048365c(void);
void Pic_Load_combat2_0048369c(int player,int card_slot);
void FUN_00484668(char *str_1);
void FUN_00484691(byte player,int card_slot);
void Sprite_Load_dungbutt_00484738(int value,undefined4 min_val,char *str_3);
void FUN_00484c45(undefined4 value);
void FUN_00484df9(undefined4 player,undefined4 card_slot);
void FUN_00484e2d(int value,undefined4 min_val,undefined4 max_val,int flags,undefined4 flags);
undefined4 Mem_AllocOrFree_00484ebb(void);
int FUN_00484ecd(int x,int y,int width,undefined4 flags);
bool FUN_00485005(int value);
undefined4 FUN_00485040(undefined4 player,undefined4 card_slot);
void Mem_AllocOrFree_00485229(void);
void FUN_00485234(int value);
void FUN_004853c2(void);
int FUN_004854a4(int value,char *str_2,int max_val);
int FUN_00485605(int value,char *str_2,int max_val);
int Dungeon_Process_004856b0(uint player,int card_slot);
undefined4 FUN_00488f92(int value);
void FUN_00488fdb(undefined4 *value,int min_val,int max_val,int flags,int flags,char *str_6,char *str_7);
void Pic_Load_advfac64_00489188(int value,int min_val,int max_val,int flags,int flags);
void FUN_00489630(uint value);
void Mem_AllocOrFree_00489690(undefined4 value,undefined4 min_val,undefined4 max_val);
void FUN_004896be(undefined4 value,int min_val,uint max_val);
void FUN_00489710(undefined4 value,undefined4 min_val,undefined4 max_val);
int FUN_00489748(char *player,int card_slot);
int FUN_00489c9c(char *str_1,int card_slot);
void FUN_0048a1ba(undefined4 value,int y,undefined4 max_val,undefined4 flags);
void FUN_0048a2a5(int value,int min_val,int max_val,int flags,undefined4 flags);
void FUN_0048a338(int value,int min_val,int max_val,int flags,undefined4 flags,undefined4 arg_6);
void FUN_0048a3cc(int value,int min_val,int max_val,int flags,int flags);
void FUN_0048a6ef(int value,int min_val,int max_val,int flags,undefined4 *flags);
uint FUN_0048ac2f(void);
void FUN_0048aee0(undefined8 *player,uint card_slot);
int FUN_0048b950(uint *value,undefined4 min_val,undefined4 max_val);
undefined4 FUN_0048bba0(int value);
undefined4 __thiscall FUN_0048bda1(void *this);
int FUN_0048be80(undefined4 *value,uint *min_val,int max_val);
int FUN_0048c070(int *value,uint *min_val,int max_val);
int FUN_0048c6d0(int value);
int FUN_0048c72a(int value);
uint FUN_0048c8b2(char *str_1,int card_slot);
void FUN_0048c970(int value);
undefined4 FUN_0048caaf(char *value);
bool FUN_0048caf4(int value,void *min_val,uint max_val);
int FUN_0048cb40(void);
undefined4 Mem_AllocOrFree_0048cdf5(void);
undefined4 FUN_0048ce07(char *str_1);
undefined4 FUN_0048d087(char *str_1);
uint FUN_0048d259(void);
uint FileIo_ReadStream(void *player, uint card_slot);
int FUN_0048e0a1(char *str_1);
void Mem_AllocOrFree_0048e0ee(void);
void Mem_AllocOrFree_0048e108(void);
void FUN_0048e122(char *str_1);
uint FUN_0048e1bf(char *str_1);
void FUN_0048e2b0(int value);
void FUN_0048e306(void);
void FUN_0048ea81(int value);
undefined4 FUN_0048eadc(int player,int card_slot);
undefined4 Sound_LoadWav_x_sound_button2_0048ec68(int value);
int FUN_0048ec9a(int player,int card_slot);
void FUN_0048ed04(int value,uint *min_val,int *max_val);
undefined4 FUN_0048edeb(int value,int min_val,int max_val,int flags,int flags,int arg_6);
undefined4 FUN_0048ee42(void);
undefined4 FUN_0048efc7(int *value,int min_val,int max_val,int flags,int flags,int arg_6);
int FUN_0048f0ae(int *value,int min_val,int max_val,int flags,int flags,int arg_6);
undefined4 FUN_0048f224(int player,int card_slot);
undefined4 Sound_LoadWav_x_sound_button2_0048f343(int value);
undefined4 FUN_0048f375(int *value,int min_val,int max_val);
void Castle_Process_0048f523(void);
int FUN_0049094c(void);
void FUN_004909a0(int value);
void FUN_004909d3(int x,undefined4 min_val,uint width,int height);
undefined4 FUN_00490ae2(int player,int card_slot);
undefined4 Sound_LoadWav_x_sound_button2_00490c01(int value);
undefined4 FUN_00490c33(int player,int card_slot);
undefined4 Sound_LoadWav_x_sound_button2_00490d49(int value);
void Town_Process_00490d7b(void);
undefined4 Castle_Process_00491d8f(undefined4 value,int y,int width,int height);
int FUN_004922dc(void);
void Action_PromptTarget_0049239e(int spell_id);
int FUN_00492cb1(int player,int card_slot);
void Castle_Process_00492ddf(int value);
int Catalog_Open(char *str_1);
bool Catalog_Close(int value);
undefined4 Catalog_CompareEntryHash(int *player,int *card_slot);
void * Catalog_FindEntry(int player,byte *card_slot);
size_t Catalog_ReadFile(int value,undefined4 min_val,int *max_val);
uint Catalog_ComputeFilenameHash(byte *value);
undefined4 * ColorOctree_AllocNode(void);
undefined * Catalog_LoadPaletteMap(char *str_1,char *str_2);
undefined4 Palette_InitSquareDistanceTable(void);
void ColorOctree_CollectLeaves(int *value,int min_val,int *max_val);
int ColorOctree_BuildClusters(int *value);
undefined4 ColorOctree_InsertColor(undefined4 *value,char *str_2,undefined4 max_val);
int ColorOctree_FreeTree(int *value);
void Color_QuantizeRGBToPalette(uint player,uint *card_slot);
undefined4 Palette_BuildFastColorLookup(void);
undefined4 Color_FindNearestRGB(uint value);
uint Color_FindNearestPaletteIndex(uint value);
int ColorOctree_Flatten(int *player,int *card_slot);
undefined4 Palette_RemapBitmapRGB(uint *x,int y,int width,int height);
uint * Palette_DitherBitmapRGB(uint *value,int min_val,uint *max_val,int flags,int flags,int arg_6);
void Palette_RotateDitherBuffers(undefined4 *player,int card_slot);
undefined4 Palette_AllocErrorDiffusionTable(int player,int card_slot);
undefined4 Palette_DitherScanline(int value,int min_val,int max_val,int flags,int flags,int arg_6);
void Palette_Util_00495410(void);
undefined4 Palette_Color_00495430(char *str_1);
void Palette_Subsystem_00495829(void);
int Palette_Subsystem_004958b1(int value);
undefined4 Palette_Subsystem_00495958(char *str_1);
void Palette_Subsystem_00495cde(MSG *value);
undefined4 Palette_Subsystem_00495eec(int *player,UINT card_slot);
undefined4 Palette_Subsystem_0049608e(void);
void Palette_Subsystem_00496230(void);
undefined4 Palette_Util_00496332(void);
undefined4 Palette_Subsystem_0049635c(HWND value,uint y,HWND max_val,undefined4 flags);
undefined4 Palette_Subsystem_004963e7(void);
LRESULT Palette_Subsystem_00496497(HWND hwnd,uint y,WPARAM max_val,uint height);
undefined4 Palette_Subsystem_004966a0(void);
uint Palette_Subsystem_00496ccf(void);
void Palette_Util_00496d20(void);
int Palette_Subsystem_00496d30(HDC hdc,int *y,WPARAM *max_val,int height);
int Palette_Subsystem_00496eaf(void);
undefined4 Palette_Subsystem_00496f10(void);
undefined4 Palette_Subsystem_00496f60(void);
undefined4 Palette_Subsystem_00496fa4(int player,int card_slot);
undefined4 Palette_Subsystem_0049713c(int value);
uint Palette_Color_0049716e(undefined4 value,uint min_val,uint max_val,int flags,int flags);
void Palette_Subsystem_004981b5(int value);
void Palette_Subsystem_004989a9(int x,int y,int width,undefined4 flags);
bool Palette_Subsystem_00498a18(void);
bool Palette_Subsystem_00499720(LPCSTR str_1);
void Palette_Subsystem_004997b8(void);
LRESULT Palette_Subsystem_004997e6(HWND hwnd,uint uMsg,int *wParam,int *lParam);
undefined4 Palette_Color_0049ae00(void);
void Palette_Subsystem_0049b8f5(void);
void Palette_Subsystem_0049c107(void);
undefined4 Palette_Subsystem_0049c3ac(int *value);
void Palette_Subsystem_0049c6cb(HDC hdc,RECT *card_slot);
undefined4 Palette_Subsystem_0049c7c7(HDC hdc,int *min_val,WPARAM *max_val,int flags,uint flags,int arg_6);
undefined4 Palette_Subsystem_0049d843(HDC hdc,int *min_val,int max_val,int flags,int flags,uint arg_6,int arg_7);
void Palette_Subsystem_0049da83(int value,int min_val,uint max_val);
void Palette_Subsystem_0049dc11(HDC hdc,int min_val,char *str_3);
int Palette_Subsystem_0049dcd5(HDC hdc,char *str_2);
int Palette_Subsystem_0049ddaa(int *player,char *str_2);
uint Palette_Subsystem_0049dfb1(HDC hdc,int min_val,int max_val,LONG flags,char *str_5);
void Palette_Subsystem_0049e291(int value,char min_val,int max_val,int flags,int flags,int arg_6);
undefined4 Palette_Subsystem_0049e53b(HDC hdc,int min_val,int max_val);
uint Palette_Subsystem_0049e5bc(HDC hdc,int *y,char *str_3,int height);
void Palette_Subsystem_0049ebf6(HDC hdc,RECT *min_val,int max_val,int flags);
void Palette_Subsystem_0049eda9(HDC hdc,int *min_val,int max_val,int flags,int flags);
void Palette_Subsystem_0049f8cd(HDC hdc,int *min_val,WPARAM *max_val,int flags,int flags);
void Palette_Subsystem_0049fb63(HDC hdc,RECT *min_val,int max_val);
void Palette_Subsystem_0049fee7(HDC hdc,int *y,uint width,uint height);
void Palette_Subsystem_004a00d1(HDC hdc,int *min_val,undefined4 max_val);
undefined4 Palette_Subsystem_004a023a(HDC hdc,int min_val,undefined4 max_val);
void Palette_Subsystem_004a0392(LPRECT player,int *card_slot);
void Palette_Subsystem_004a0466(HDC hdc,int *min_val,int max_val,int flags,int flags);
undefined4 Palette_Subsystem_004a068a(int x,int y,int width,int height);
void Palette_Subsystem_004a080b(LPRECT value,int *min_val,int max_val);
undefined4 Palette_Subsystem_004a09c9(int value,int *min_val,int max_val,int flags,int flags);
void Palette_Subsystem_004a0d00(HDC hdc,undefined4 *min_val,uint max_val);
void Palette_Subsystem_004a0f97(LPRECT value,uint y,int *width,uint height);
void Palette_Subsystem_004a11fa(HDC hdc,int *min_val,char *str_3,int flags,int flags);
void Palette_Subsystem_004a13b7(HDC hdc,int *min_val,int max_val,undefined4 flags,int flags);
void Palette_Subsystem_004a155f(HDC hdc,int *min_val,int max_val,int flags,int flags);
void Palette_Subsystem_004a1b64(HDC hdc,RECT *min_val,int max_val,int flags,int flags,int arg_6,int arg_7);
void Palette_Subsystem_004a1e09(HDC hdc,int *y,int width,int height);
void Palette_Subsystem_004a2401(HDC hdc,int *y,int width,int height);
void Palette_Subsystem_004a26f8(undefined4 player,undefined4 card_slot);
void Palette_Subsystem_004a277f(undefined4 player,undefined4 card_slot);
void Palette_Subsystem_004a2806(HDC hdc,int *card_slot);
uint Palette_Subsystem_004a289f(HDC hdc,int *y,int width,int height);
void Palette_Subsystem_004a29c5(HDC hdc,int *min_val,int max_val);
void Palette_Subsystem_004a2a5b(undefined4 value,int *min_val,byte max_val);
void Palette_Subsystem_004a2aa3(LPRECT player,int *card_slot);
undefined4 Palette_Subsystem_004a2b7e(int value);
void Palette_Subsystem_004a2dce(char *str_1,char *str_2,int max_val);
void Palette_Util_004a2edc(void);
undefined4 Palette_Subsystem_004a2ef0(int value);
int Palette_Subsystem_004a41fd(void);
void Palette_Subsystem_004a4760(int value,int min_val,int max_val);
void Palette_Subsystem_004a486f(int player,int card_slot);
void Palette_Subsystem_004a4a47(int value,int min_val,int max_val);
void Palette_Subsystem_004a554b(int x,int y,int *width,int *height);
void Palette_Subsystem_004a5586(int x,int y,int *width,int *height);
void Palette_Subsystem_004a5603(int player,int card_slot);
int Palette_Subsystem_004a5722(int value,int min_val,int max_val);
void Palette_Subsystem_004a5e4c(void);
void Palette_Subsystem_004a5f7c(void);
void Palette_Subsystem_004a5fdc(void);
void Palette_Subsystem_004a6018(void);
undefined4 Palette_Subsystem_004a610e(int player,int card_slot);
int Palette_Subsystem_004a62a0(undefined4 value,int min_val,int max_val);
undefined4 Palette_Subsystem_004a6370(HWND hwnd,uint uMsg,uint wParam,byte *lParam);
void Palette_Subsystem_004a69c8(HWND hwnd,byte min_val,byte max_val);
int Palette_Subsystem_004a6d20(int value,int min_val,int max_val);
int Palette_Subsystem_004a6eb8(int value);
undefined4 Palette_Subsystem_004a6fef(int spell_id,int target_id,int flags);
int Palette_Subsystem_004a75bd(int value);
int Palette_Subsystem_004a7650(int player,int card_slot);
int Palette_Subsystem_004a771b(int value,int min_val,undefined4 max_val);
undefined4 Palette_Subsystem_004a7814(int value,int min_val,int max_val);
int Palette_Subsystem_004a7a25(int value,int min_val,int max_val);
int Palette_Subsystem_004a7bcd(int value,int min_val,int max_val);
int Palette_Subsystem_004a7d05(int player,int card_slot);
undefined4 Palette_Subsystem_004a7e3c(int value,int min_val,int max_val);
undefined4 Palette_Subsystem_004a7f2a(int value,int min_val,int max_val);
undefined4 Palette_Subsystem_004a8111(int value,int min_val,int max_val);
undefined4 Palette_Subsystem_004a8d46(int value,int min_val,int max_val);
int Palette_Subsystem_004a8fd8(int value,int min_val,int width,uint height);
undefined4 Palette_Subsystem_004a9137(int value,int min_val,undefined4 max_val);
uint Ai_ChooseCardToPlay(int value);
void Ai_SaveGameState(void);
void Ai_RestoreGameState(void);
void Ai_PushBoardState(void);
void Ai_PopBoardState(void);
void Ai_ClearPlan(void);
void Ai_BeginTrial(void);
void Ai_RecordChoice(void);
undefined4 Ai_GetOpponentPlayerScore(int value);
undefined4 Ai_CalcLifeAdvantage(int value);
void Ai_ReplayChoice(void);
void Ai_CommitBestPlan(void);
undefined4 Ai_GetPlanCursor(void);
void Ai_Util_004ab525(void);
int Ai_EvaluateBoard(int value);
int Ai_PenalizeCounterattack(int player,int card_slot);
undefined4 Ai_ChooseBlockers(int player,int card_slot);
void Ai_FilterValidBlockers(uint *player,uint *card_slot);
undefined4 Duel_ShowStartOfDuelDialog(undefined4 *value,uint *min_val,uint max_val,int flags,uint flags,uint arg_6,undefined4 arg_7,int arg_8,undefined4 arg_9);
HGDIOBJ Ai_DuelDialogProc(HWND hwnd,uint uMsg,HWND wParam,HWND lParam);
void Ai_LoadStartDuel2Backdrop(undefined4 *value,undefined4 *out_buffer,undefined4 *max_val,undefined4 *flags,undefined4 *flags,undefined4 *arg_6);
void Ai_Subsystem_004ad77b(int value,int min_val,int max_val);
HGDIOBJ Ai_StartDuelWndProc(HWND hwnd,uint uMsg,HWND wParam,HWND lParam);
void Ai_LoadStartDuelBackdrop(undefined4 *value,undefined4 *out_buffer,undefined4 *max_val,undefined4 *flags,undefined4 *flags,undefined4 *arg_6,undefined4 *arg_7);
void Ai_Subsystem_004ae716(int x,int y,int width,int height);
void Ai_Subsystem_004ae779(int value);
INT_PTR Ai_Subsystem_004ae8a3(undefined4 value,undefined4 min_val,undefined4 max_val,undefined4 flags,undefined4 flags);
HGDIOBJ Ai_DuelMainWndProc(HWND hwnd,uint uMsg,HDC wParam,HWND lParam);
void Ai_LoadEndDuelBackdrop(undefined4 *value,undefined4 *out_buffer,undefined4 *max_val,int *flags,int *flags,int *arg_6,undefined4 *arg_7,undefined4 *arg_8);
void Ai_Subsystem_004af5e3(int x,HGDIOBJ min_val,HGDIOBJ max_val,HGDIOBJ flags);
undefined4 Ai_Subsystem_004af640(int player,int card_slot);
LRESULT Ai_Subsystem_004af765(undefined4 value,char *str_2,undefined4 max_val,undefined4 flags,undefined4 flags,undefined4 arg_6,undefined4 arg_7,int *arg_8,undefined4 *arg_9,undefined4 arg_10,undefined4 arg_11);
void Ai_Util_004afa46(void);
INT_PTR Ai_ScoreCardPlay_004afa69(int *value,int min_val,int max_val,undefined4 flags,int flags,char *str_6);
LRESULT Ai_ScoreCardPlay_004afc26(HWND hwnd,uint y,HDC hdc,undefined4 *flags);
void Ai_Subsystem_004b0d24(int *value,int *min_val,int *max_val,int *flags,int *flags,undefined4 *arg_6);
void Ai_Subsystem_004b0e11(HGDIOBJ value,HGDIOBJ min_val,HGDIOBJ max_val,HGDIOBJ flags,HGDIOBJ flags);
LRESULT Ai_Subsystem_004b0e80(HWND hwnd,uint uMsg,WPARAM wParam,LONG *lParam);
void Ai_Util_004b128e(void);
void Ai_Subsystem_004b137d(uint value,int min_val,int max_val);
void Ai_Util_004b1406(void);
INT_PTR Ai_Subsystem_004b1416(int value,undefined4 min_val,INT_PTR max_val,char *str_4,char *str_5,char *str_6);
HWND Ai_Subsystem_004b15df(HWND hwnd,uint uMsg,uint wParam,undefined4 *lParam);
INT_PTR Ai_Subsystem_004b1974(int value,undefined4 min_val,INT_PTR max_val);
undefined4 Ai_Subsystem_004b19d0(HWND hwnd,uint uMsg,uint wParam,undefined4 *lParam);
INT_PTR Ai_Subsystem_004b1b38(int value,undefined4 min_val,INT_PTR max_val);
HGDIOBJ Ai_Subsystem_004b1b9b(HWND hwnd,uint uMsg,HDC wParam,HWND lParam);
LRESULT Ai_Subsystem_004b20e5(HWND hwnd,UINT y,uint width,LPARAM flags);
void Ai_Subsystem_004b2183(undefined4 *value,undefined4 *out_buffer,int *max_val,int *flags,int *flags,undefined4 *arg_6,undefined4 *arg_7);
void Ai_Subsystem_004b2260(int x,HGDIOBJ min_val,HGDIOBJ max_val,HGDIOBJ flags);
INT_PTR Ai_Subsystem_004b22bd(int value,undefined4 min_val,undefined4 max_val,int flags,uint flags);
HGDIOBJ Ai_Subsystem_004b257c(HWND hwnd,uint uMsg,HDC wParam,HWND lParam);
void Ai_CalcManaRequirement_004b32d1(undefined4 *value,undefined4 *out_buffer,undefined4 *max_val,undefined4 *flags,undefined4 *flags,int *arg_6,int *arg_7,int *arg_8,undefined4 *arg_9,undefined4 *arg_10);
void Ai_Subsystem_004b34fe(int value,int min_val,int max_val,HGDIOBJ flags,HGDIOBJ flags,HGDIOBJ arg_6);
void Ai_Subsystem_004b35b4(LPRECT value,HWND hwnd,int max_val);
INT_PTR Ai_Subsystem_004b3777(int value,undefined4 *min_val,undefined4 max_val,int flags,uint flags);
HBRUSH Ai_Subsystem_004b3847(HWND hwnd,uint uMsg,HWND wParam,HWND lParam);
void Ai_Subsystem_004b4197(undefined4 *value,undefined4 *out_buffer,int *max_val,int *flags,int *flags,undefined4 *arg_6,undefined4 *arg_7);
void Ai_Subsystem_004b4274(int x,HGDIOBJ min_val,HGDIOBJ max_val,HGDIOBJ flags);
void Ai_Util_004b42d1(void);
uint Ai_Subsystem_004b42dc(void);
void Duel_RefreshAllWindows(undefined4 player,uint card_slot);
void Ai_Util_004b53a1(void);
undefined4 Ai_Util_004b53c6(void);
uint Ai_Subsystem_004b53ed(void);
void Ai_Util_004b542d(void);
void Ai_Util_004b543d(void);
undefined4 Ai_Subsystem_004b544d(void);
void Ai_Subsystem_004b5501(char *str_1);
void Ai_Subsystem_004b553f(char *str_1);
int Ai_Subsystem_004b574d(int value,int min_val,int max_val,int flags,undefined4 flags,undefined4 arg_6);
undefined4 Ai_Subsystem_004b584e(void);
void Ai_Subsystem_004b58d9(int value);
undefined4 Ai_Subsystem_004b5919(int player,int card_slot);
uint Ai_Subsystem_004b5967(int player,int card_slot);
undefined4 Ai_Subsystem_004b59d9(int player,int card_slot);
uint Ai_Subsystem_004b5a46(int player,int card_slot);
void Ai_Subsystem_004b5ab8(int value,int min_val,uint *max_val,uint *flags,uint *flags);
int Ai_Subsystem_004b5b6f(int player,int card_slot);
int Ai_Subsystem_004b5bdd(int player,int card_slot);
undefined4 Ai_Subsystem_004b5c4b(int player,int card_slot);
undefined4 Ai_Subsystem_004b5cbb(int player,int card_slot);
undefined4 Ai_Subsystem_004b5d2e(int player,int card_slot);
byte Ai_Subsystem_004b5de4(int player,int card_slot);
void Ai_Subsystem_004b5f74(int *value,int min_val,int max_val);
undefined4 Ai_Subsystem_004b6023(int *value,int min_val,int max_val);
undefined1 Ai_Subsystem_004b613b(int player,int card_slot);
int Ai_Subsystem_004b61ac(int player,int card_slot);
int Ai_Subsystem_004b621a(int player,int card_slot);
uint Ai_Subsystem_004b6288(int player,int card_slot);
int Ai_Subsystem_004b6356(int player,int card_slot);
int Ai_Subsystem_004b63c4(int player,int card_slot);
undefined4 Ai_Subsystem_004b6432(int player,int card_slot);
undefined4 Ai_Subsystem_004b649f(int player,int card_slot);
void Ai_Subsystem_004b650c(int x,int y,int *width,int *height);
undefined4 Ai_Util_004b65ad(void);
uint Ai_Subsystem_004b65bf(int player,int card_slot);
uint Ai_Subsystem_004b6623(int player,int card_slot);
bool Ai_Subsystem_004b6696(int player,int card_slot);
undefined4 Ai_Subsystem_004b673e(int player,int card_slot);
bool Ai_Subsystem_004b67ab(int player,int card_slot);
bool Ai_Subsystem_004b682f(int player,int card_slot);
void Ai_Subsystem_004b68b3(int value,int min_val,char *max_val);
void Ai_Subsystem_004b69ba(int value,int min_val,char *max_val);
int Ai_Subsystem_004b6ba8(int value,int min_val,void *max_val);
undefined4 Ai_Subsystem_004b6c5b(int player,int card_slot);
undefined4 Ai_Subsystem_004b6cc8(int player,int card_slot);
undefined4 Ai_Subsystem_004b6d35(int player,int card_slot);
void Ai_Subsystem_004b6da5(undefined4 *value,int min_val,int max_val);
undefined4 Ai_Subsystem_004b6e3b(int player,int card_slot);
int Ai_Subsystem_004b6eab(int player,int card_slot);
undefined4 Ai_Util_004b6f19(int value);
void Ai_Subsystem_004b6f49(char *str_1);
undefined4 Ai_Subsystem_004b6fa6(int value);
undefined4 Ai_Subsystem_004b700c(int value);
undefined4 Ai_Subsystem_004b7072(void *player,int card_slot);
undefined4 Ai_Subsystem_004b70fe(void *value,int min_val,int max_val);
undefined4 Ai_Subsystem_004b718a(void *player,int card_slot);
undefined4 Ai_Subsystem_004b722d(void *player,int card_slot);
undefined4 Ai_Subsystem_004b72d0(void *player,int card_slot);
undefined4 Ai_Subsystem_004b7373(void *value);
void Ai_Subsystem_004b73ce(int x,int *y,int width,int *height);
void Ai_Subsystem_004b74b1(undefined4 *player,undefined4 *card_slot);
void Ai_Subsystem_004b74fa(void *player,int card_slot);
void Ai_Subsystem_004b756f(undefined4 *value);
undefined4 Ai_Subsystem_004b75a4(void);
bool Ai_Subsystem_004b75d8(undefined4 *value);
undefined4 Ai_Subsystem_004b7629(void);
void Ai_Subsystem_004b765d(undefined4 *player,undefined4 *card_slot);
int Ai_Subsystem_004b76a6(void *value,int y,int width,int height);
void Ai_Subsystem_004b784d(undefined4 player,undefined4 card_slot);
undefined4 Ai_CalcManaRequirement_004b7897(HWND hwnd,uint uMsg,HDC wParam,int *lParam);
int Ai_Subsystem_004b7d38(char *str_1);
HBRUSH Ai_Subsystem_004b7de8(HWND hwnd,uint uMsg,HDC wParam,HWND lParam);
void Ai_Util_004b82ea(undefined4 *player,undefined4 *card_slot);
void Ai_Util_004b830e(HGDIOBJ value);
undefined4 Ai_Subsystem_004b832d(int value,int min_val,undefined4 max_val,undefined4 flags,undefined4 *flags,undefined4 *arg_6,undefined4 *arg_7);
HBRUSH Ai_Subsystem_004b8421(HWND hwnd,uint uMsg,HWND wParam,HWND lParam);
void Ai_Subsystem_004b8cc3(undefined4 *value,undefined4 *out_buffer,int *max_val,int *flags,int *flags,undefined4 *arg_6,undefined4 *arg_7);
void Ai_Subsystem_004b8da0(int x,HGDIOBJ min_val,HGDIOBJ max_val,HGDIOBJ flags);
int Ai_Subsystem_004b8dfd(int player,int card_slot);
char * Ai_Subsystem_004b8e4d(int player,int card_slot);
void Ai_Subsystem_004b90de(int player,int card_slot);
undefined4 UI_Register_WINBK_ManaPool_004b9120(LPCSTR str_1);
void Ai_Subsystem_004b920e(void);
LRESULT Ai_CalcManaRequirement_004b9284(HWND hwnd,uint uMsg,char *wParam,uint lParam);
void Ai_Subsystem_004ba6b6(LPRECT value,HWND hwnd,int max_val);
int Ai_CalcManaRequirement_004ba890(int value,int min_val,int max_val);
void Ai_Subsystem_004bb9f3(int x,int min_val,int *max_val,int height);
void Ai_Subsystem_004bbb99(int value,int min_val,int *max_val,int flags,int *flags,int arg_6);
void Ai_Subsystem_004bbd93(int value,int min_val,int *max_val,int flags,int *flags,int arg_6);
undefined4 Ai_Subsystem_004bbf8e(int value,int min_val,int max_val);
undefined4 Ai_Subsystem_004bc029(undefined4 spell_id,int *target_id,int flags,int height);
undefined4 Ai_CalcManaRequirement_004bc423(void);
undefined4 Ai_Subsystem_004bc72e(int value,undefined4 min_val,undefined4 max_val,undefined4 flags,int flags);
undefined4 Ai_Subsystem_004bd035(int value,int min_val,byte max_val);
undefined4 Ai_Subsystem_004bd23f(int player,int card_slot);
void Ai_Subsystem_004bd3e9(int value,int min_val,int max_val,int *flags,undefined4 flags,int arg_6,int arg_7,int arg_8,int *arg_9);
int Ai_Subsystem_004bd459(int value,int min_val,int max_val,int flags,int flags,int arg_6,int arg_7);
undefined4 Ai_Subsystem_004bd4f0(void);
bool Ai_Subsystem_004bd563(int player,int card_slot);
bool Ai_Util_004bd5af(void);
undefined4 Ai_Subsystem_004bd5e3(int value);
undefined4 Ai_Subsystem_004bd682(int value);
undefined4 Ai_Subsystem_004bd6f9(int value,uint min_val,int max_val);
int Ai_Subsystem_004be192(int x,int y,int width,int height);
void Ai_Util_004be240(void);
void Ai_Subsystem_004be25f(undefined4 value,undefined4 min_val,undefined4 max_val,int flags,undefined4 flags);
void Ai_Subsystem_004be357(void);
void Ai_Subsystem_004be3c4(int *value,int min_val,int max_val,int flags,int flags,int arg_6);
void Ai_Subsystem_004be43f(int x,int y,int *width,int *height);
void Ai_Subsystem_004be49b(int x,int y,int *width,int *height);
void Ai_Subsystem_004be525(int x,int y,int *width,int *height);
void Ai_Subsystem_004be5ae(int x,int y,int *width,int *height);
void Ai_Subsystem_004be643(int value,int min_val,int max_val);
void Ai_Subsystem_004bf23a(void);
void Ai_CalcManaRequirement_004bf4b3(int card_id);
void Ai_CalcManaRequirement_004c003d(void);
void Ai_Subsystem_004c05ba(void);
void Ai_Subsystem_004c06df(uint player,uint card_slot);
void Ai_CastleEncounter_004c0efe(uint value,uint min_val,int max_val,int flags,uint flags,int arg_6,int arg_7,int arg_8);
undefined4 Ai_Subsystem_004c207a(int player,int card_slot);
undefined4 Ai_Subsystem_004c2270(int value);
int Ai_Subsystem_004c22a2(int x,int y,int width,byte *flags);
void Ai_Subsystem_004c2340(undefined4 *value,int min_val,int max_val,int flags,int flags,uint arg_6,int arg_7);
void Ai_CastleEncounter_004c24b3(int value);
void Ai_Subsystem_004c3aa1(int x,int y,int *width,int *height);
void Ai_Subsystem_004c3ad4(int x,int y,int *width,int *height);
void Ai_TownEncounter_004c3b19(uint value);
int Ai_Util_004c3ba3(int value);
int Ai_Util_004c3bc4(int value);
undefined4 Ai_Subsystem_004c3be5(int player,int card_slot);
void Ai_Subsystem_004c3c5c(int value);
void Ai_Subsystem_004c4210(int value);
void Ai_Subsystem_004c4c84(int value);
uint Ai_Subsystem_004c5fc9(int value);
void Ai_Subsystem_004c7aa8(int value);
void Ai_Subsystem_004c7be5(undefined4 player,int card_slot);
int Ai_Subsystem_004c7d69(void);
void Ai_EvalAttackCandidate_004c864d(uint spell_id);
undefined4 Ai_Subsystem_004c9f3a(int player,uint card_slot);
undefined4 Ai_Subsystem_004c9f88(int value);
void Ai_Subsystem_004ca07b(void);
void Ai_Subsystem_004ca0d9(int value,int min_val,int max_val,int flags,int flags,int arg_6,int *arg_7,int *arg_8);
void Ai_Subsystem_004ca714(int value,int min_val,int max_val,int flags,int flags,int arg_6,int *arg_7,int *arg_8);
void Ai_Subsystem_004cab92(void);
void Ai_Subsystem_004cad65(int value,int min_val,int max_val);
void Ai_Subsystem_004cadc5(int value,int min_val,int max_val);
void Ai_Util_004cae25(WPARAM value);
int Ai_Subsystem_004cae47(int player,int card_slot);
int Ai_Subsystem_004cb04d(int player,int card_slot);
undefined4 Ai_Subsystem_004cb1d6(int player,int card_slot);
undefined4 Ai_Util_004cb2d0(void);
uint Ai_Subsystem_004cbad0(int player,int card_slot);
undefined4 Ai_Util_004cbb04(int player,int card_slot);
uint Ai_Subsystem_004cbb33(int player,int card_slot);
int Ai_Util_004cbba7(int player,int card_slot);
int Ai_Util_004cbbd7(int player,int card_slot);
undefined4 Ai_Util_004cbc07(int player,int card_slot);
undefined4 Ai_Util_004cbc36(int player,int card_slot);
undefined4 Ai_Subsystem_004cbc65(int player,int card_slot);
int CardTypeFromID(int value);
undefined4 CardIDFromType(uint value);
uint Ai_Util_004cbda9(uint value);
void Ai_Subsystem_004cbdda(int player,int card_slot);
bool Ai_Subsystem_004cbe10(int player,int card_slot);
byte Ai_Subsystem_004cbe57(int player,int card_slot);
undefined8 Ai_Subsystem_004cbf72(int player,int card_slot);
undefined4 Ai_Subsystem_004cbfd0(int value,int min_val,int *max_val);
undefined1 Ai_Subsystem_004cc053(int player,int card_slot);
int Ai_Util_004cc0c7(int player,int card_slot);
int Ai_Util_004cc0f7(int player,int card_slot);
undefined4 Ai_Subsystem_004cc127(int player,int card_slot);
int Ai_Util_004cc188(int player,int card_slot);
int Ai_Util_004cc1b8(int player,int card_slot);
char * Ai_Subsystem_004cc1e8(int player,int card_slot);
int Ai_Subsystem_004cc25b(int player,int card_slot);
int Ai_Subsystem_004cc2cc(int player,int card_slot);
undefined4 Ai_Subsystem_004cc33d(int value,int min_val,undefined4 max_val);
undefined4 Ai_Subsystem_004cc3c4(int player,int card_slot);
void Ai_Subsystem_004cc3f8(undefined4 value,undefined4 min_val,undefined4 max_val,undefined4 flags);
void Ai_Util_004cc42d(char *str_1);
undefined4 Ai_Subsystem_004cc455(int *value,int min_val,undefined4 max_val,int flags,char *str_5);
undefined4 Ai_Subsystem_004cc49a(int *value,int min_val,int max_val,undefined4 flags,int flags,char *str_6);
void Ai_Util_004cc4e1(undefined4 value);
void Ai_Subsystem_004cc50a(undefined4 value,undefined4 min_val,char *str_3);
int Ai_Subsystem_004cc56d(int value,int min_val,int max_val,int flags,int flags,char *str_6,int arg_7);
void Ai_Subsystem_004cc7c5(undefined4 player,undefined4 card_slot);
INT_PTR Ai_Subsystem_004cc814(int value,char *str_2,INT_PTR max_val,char *str_4,char *str_5,char *str_6);
INT_PTR Ai_Subsystem_004cc87f(int value,char *str_2,INT_PTR max_val);
INT_PTR Ai_Subsystem_004cc8de(int value,char *str_2,INT_PTR max_val);
int Ai_Subsystem_004cc93d(int value,undefined4 min_val,undefined4 max_val,int flags,uint flags);
void Ai_Subsystem_004cc97e(char *str_1);
void Ai_Subsystem_004cc9c5(int player,int card_slot);
void Ai_Subsystem_004ccca3(void);
void Ai_Subsystem_004cced8(void);
void Ai_Subsystem_004cd14f(int value);
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
int SpellChain_FindEntryIndex(HWND hwnd);
void SpellChain_RemoveEntry(HWND hwnd,int card_slot);
bool SpellChain_EntryTargetsMatch(void);
int SpellChain_InsertEntry(HWND hwnd,undefined4 min_val,undefined4 max_val);
void SpellChain_ClearEntryTargets(HWND hwnd,int card_slot);
int SpellChain_RebuildEntryTargets(HWND hwnd);
void SpellChain_UpdateLayout(HWND hwnd,LPRECT card_slot);
void SpellChain_GetContentRect(undefined4 player,LPRECT card_slot);
LRESULT SpellChain_MinimizedWndProc(HWND hwnd,uint uMsg,HDC wParam,uint lParam);
BOOL SpellChain_MinimizeIfShown(void);
bool SpellChain_RestoreIfMinimized(void);
undefined4 Card_DefaultEventHandler(void);
uint Card_GetColorAndTypeFlags(int player,int card_slot);
undefined4 Card_ColorWard_ChangeColor(int value,int min_val,int max_val);
undefined4 Card_ChaosLace_ModifyAttributes(int value,int min_val,int max_val);
bool Card_Sinbad_Draw(int value,int min_val,int max_val);
undefined4 Card_Kudzu_LandDestruction(int value,int min_val,int max_val);
void Card_BronzeTablets_AnteSwap(int value,int min_val,int max_val);
undefined4 Card_XenicPoltergeist_AnimateArtifact(int spell_id,int target_id,int flags);
undefined4 Card_VesuvanDoppelganger_Copy(int spell_id,int target_id,int flags);
undefined4 Card_VesuvanDoppelganger_Upkeep(int value,int min_val,int max_val);
undefined4 Card_Doppelganger_ClearMimic(int player,int card_slot);
undefined4 Card_Doppelganger_ApplyMimicStats(int player,int card_slot);
undefined4 Card_Doppelganger_SyncAbilities(int player,int card_slot);
undefined4 Card_Doppelganger_CheckState(int value,int min_val,int max_val);
undefined4 Card_IslandSanctuary_SkipDraw(int value,int min_val,int max_val);
undefined4 Card_IslandSanctuary_AttackRestriction(int value,int min_val,int max_val);
undefined4 Card_IslandSanctuary_Trigger(int value,int min_val,int max_val);
undefined4 Card_IslandSanctuary_CheckActive(int value,int min_val,int max_val);
undefined4 Card_IslandSanctuary_Prompt(int value,int min_val,int max_val);
undefined4 Card_LivingLands_AnimateForests(int value,int min_val,int max_val);
undefined4 Card_KormusBell_AnimateSwamps(int value,int min_val,int max_val);
undefined4 Card_TitaniasSong_AnimateArtifacts(int value,int min_val,int max_val);
undefined4 Card_TitaniasSong_RemoveAbilities(int value,int min_val,int max_val);
undefined4 Card_TitaniasSong_RestoreAbilities(int value,int min_val,int max_val);
undefined4 Card_TitaniasSong_UpdateStatus(int value,int min_val,int max_val);
undefined4 Card_TitaniasSong_ClearFlags(int value,int min_val,int max_val);
undefined4 Card_TitaniasSong_CheckTrigger(int value,int min_val,int max_val);
undefined4 Card_PersonalIncarnation_RedirectDamage(int spell_id,int target_id,int flags);
undefined4 Card_AliFromCairo_PreventLethalDamage(int spell_id,int target_id,int flags);
undefined4 Card_AliFromCairo_ResetState(int value,int min_val,int max_val);
undefined4 Card_ShivanDragon_PumpFirebreathing(int value,int min_val,int max_val);
undefined4 Card_DragonWhelp_PumpFirebreathing(int value,int min_val,int max_val);
int Card_DragonWhelp_EndTurnCheck(int value,int min_val,int max_val);
undefined4 Card_FrozenShade_ClearBoost(int player,int card_slot);
undefined4 Card_FrozenShade_PumpBlack(int value,int min_val,int max_val);
undefined4 Card_WaterElemental_PumpBlue(int value,int min_val,int max_val);
undefined4 Card_ClockworkBeast_ResetCounters(int value,int min_val,int max_val);
undefined4 Card_ClockworkBeast_CombatTrigger(int value,int min_val,int max_val);
undefined4 Card_ClockworkBeast_Rewind(int value,int min_val,int max_val);
undefined4 Card_ClockworkBeast_GetPower(int value,int min_val,int max_val);
undefined4 Card_ClockworkBeast_GetToughness(int value,int min_val,int max_val);
undefined4 Card_GaeasLiege_TransformLand(int spell_id,int target_id,int flags);
undefined4 Card_GaeasLiege_ResetLand(int value,int min_val,int max_val);
undefined4 Card_GaeasLiege_CheckAttackRestriction(int value,int min_val,int max_val);
undefined4 Card_GaeasLiege_IsForest(undefined4 value,undefined4 min_val,int max_val);
undefined4 Card_GaeasLiege_CombatCheck(int value,int min_val,int max_val);
undefined4 Card_SedgeTroll_CheckSwamp(int value,int min_val,int max_val);
undefined4 Card_SedgeTroll_Regenerate(int value,int min_val,int max_val);
undefined4 Card_LivingWall_PromptRegenerate(int value,int min_val,int max_val);
undefined4 Card_LivingWall_Regenerate(int value,int min_val,int max_val);
undefined4 Card_GenericCreature_Regenerate(int value,int min_val,int max_val,uint flags,int flags);
undefined4 Card_GenericCreature_CanRegenerate(int player,int card_slot);
undefined4 Card_GenericCreature_TriggerRegen(int value,int min_val,int max_val);
undefined4 Card_DrudgeSkeletons_Regenerate(int value,int min_val,int max_val);
undefined4 Card_UthdenTroll_Regenerate(int value,int min_val,int max_val);
undefined4 Card_WillOTheWisp_Regenerate(int value,int min_val,int max_val);
undefined4 Card_MarrowThieves_Regenerate(int value,int min_val,int max_val);
void Card_HypnoticSpecter_RandomDiscard(int value,int min_val,int max_val);
undefined4 Card_TimeElemental_BouncePermanent(int spell_id,int target_id,int flags);
undefined4 Card_NorthernPaladin_DestroyBlack(int spell_id,int target_id,int flags);
undefined4 Card_RoyalAssassin_DestroyTapped(int spell_id,int target_id,int flags);
undefined4 Card_DwarvenDemolitionTeam_DestroyWall(int spell_id,int target_id,int flags);
undefined4 Card_KingSuleiman_DestroyDjinn(int spell_id,int target_id,int flags);
undefined4 Card_Targeting_PromptCreature(int x,int y,int width,uint height);
undefined4 Card_NettlingImp_ForceAttack(int spell_id,int target_id,int flags);
bool Card_NettlingImp_CheckEndTurn(int value,int min_val,int max_val);
undefined4 Card_NettlingImp_IsTargetEligible(int value,int min_val,int max_val);
undefined4 Card_SorceressQueen_SetStats02(int spell_id,int target_id,int flags);
void Card_SorceressQueen_ResetStats(int value,int min_val,int max_val);
undefined4 Card_StoneGiant_Fling(int spell_id,int target_id,int flags);
undefined4 Card_DwarvenWarriors_MakeUnblockable(int spell_id,int target_id,int flags);
undefined4 Card_CavePeople_Mountainwalk(int spell_id,int target_id,int flags);
undefined4 Card_PradeshGypsies_PreventAttack(int spell_id,int target_id,int flags);
undefined4 Card_PradeshGypsies_ResetRestriction(int value,int min_val,int max_val);
undefined1 Card_SamiteHealer_PreventDamage(int spell_id,int target_id,int flags);
undefined4 Card_SamiteHealer_CalculateHealAdvantage(int value,int min_val,int max_val);
undefined4 Card_AlabasterPotion_HealOrPrevent(int value,int min_val,int max_val);
undefined4 Card_HealingSalve_DamagePrevention(int value,int min_val,int max_val);
undefined4 Card_DamagePrevention_ApplyBubble(int player,int card_slot);
undefined4 Card_DamagePrevention_ReduceDamage(int value,int min_val,int max_val);
undefined4 Card_DamagePrevention_ClearAtCleanup(int value,int min_val,int max_val);
undefined4 Card_DamagePrevention_QueryAmount(int value,int min_val,int max_val);
undefined4 Card_DamagePrevention_PromptTarget(int value,int min_val,int max_val);
undefined4 Card_DamagePrevention_CheckSource(int value,int min_val,int max_val);
undefined4 Card_ErgRaiders_UpkeepDamage(int value,int min_val,int max_val);
undefined4 Card_ErgRaiders_MarkAttack(int value,int min_val,int max_val);
undefined4 Card_ErgRaiders_ClearTurnAttack(int value,int min_val,int max_val);
undefined4 Card_Leviathan_SacrificeLands(int value,int min_val,int max_val);
undefined4 Card_Leviathan_PromptLandSacrifice(int spell_id,int target_id,int flags);
undefined4 Card_Leviathan_SelectLand(int value,int min_val,int max_val);
undefined4 Card_Leviathan_AttackTrigger(int value,int min_val,int max_val);
undefined4 Card_BrothersOfFire_Ping(int spell_id,int target_id,int flags);
bool Card_BrothersOfFire_EvaluateTarget(int value,int min_val,int max_val);
undefined4 Card_CrimsonManticore_DamageTarget(int spell_id,int target_id,int flags);
bool Card_ProdigalSorcerer_PingTarget(int spell_id,int target_id,int flags);
bool Card_DirectDamage_EvaluateBestTarget(int player,int card_slot);
undefined4 Card_DirectDamage_PromptAndDealDamage(int x,int y,int width,int height);
bool Card_PirateShip_PingTarget(int spell_id,int target_id,int flags);
undefined4 Card_PirateShip_CheckIslandwalk(int value,int min_val,int max_val);
undefined4 Card_PirateShip_HasIsland(int value,int min_val,int max_val);
undefined4 Card_PirateShip_AttackTrigger(int value,int min_val,int max_val);
undefined4 Card_IslandFishJasconius_PayToUntap(int value,int min_val,int max_val);
undefined4 Card_IslandFishJasconius_CheckIslands(int value,int min_val,int max_val);
undefined4 Card_IslandFishJasconius_DestroyIfNoIslands(int value,int min_val,int max_val);
uint Card_RodOfRuin_Ping(int value,int min_val,int max_val);
undefined4 Card_RodOfRuin_EvaluateAi(int value,int min_val,int max_val);
undefined4 Card_RodOfRuin_PayActivation(int value,int min_val,int max_val);
undefined4 Card_RodOfRuin_SelectTarget(int value,int min_val,int max_val);
bool Card_OrcishArtillery_ShootTarget(int spell_id,int target_id,int flags);
bool Card_PsionicEntity_ShootTarget(int spell_id,int target_id,int flags);
undefined4 Card_PsionicEntity_EvaluateTarget(int value,int min_val,int max_val);
undefined4 Card_PsionicEntity_SelfDamage(int value,int min_val,int max_val);
undefined4 Card_KhabalGhoul_AddCounterOnDeath(int value,int min_val,int max_val);
undefined4 Card_KhabalGhoul_CheckCreatureDeath(int value,int min_val,int max_val);
undefined4 Card_KhabalGhoul_ApplyCounterBonus(int value,int min_val,int max_val);
undefined4 Card_KhabalGhoul_ResetCounterBonus(int value,int min_val,int max_val);
undefined4 Card_LordOfAtlantis_PayOrSacrifice(int value,int min_val,int max_val);
undefined4 Card_LordOfAtlantis_ApplyMerfolkBuff(int value,int min_val,int max_val);
undefined4 Card_LordOfAtlantis_RemoveMerfolkBuff(int value,int min_val,int max_val);
undefined4 Card_LordOfAtlantis_IslandwalkTrigger(int value,int min_val,int max_val);
undefined4 Card_LordOfAtlantis_CheckMerfolkType(int player,int card_slot);
undefined4 Card_ForceOfNature_PayUpkeep(int value,int min_val,int max_val);
bool Card_ForceOfNature_AiPayOrTakeDamage(int value,int min_val,int max_val);
bool Card_BirdsOfParadise_TapForMana(int spell_id,int target_id,int flags);
undefined4 Card_CosmicHorror_PayUpkeep(int value,int min_val,int max_val);
undefined4 Card_LordOfThePit_SacrificeOrDamage(int spell_id,int target_id,int flags);
int Card_LordOfThePit_FindSacrificeCandidate(int player,int card_slot);
undefined4 Card_KormusBell_PayLandUpkeep(int value,int min_val,int max_val);
undefined4 Card_KormusBell_CheckSwampCreature(int value,int min_val,int max_val);
undefined4 Card_NetherShadow_CheckGraveyard(int value,int min_val,int max_val);
undefined4 Card_NetherShadow_CountCreaturesAbove(int value,int min_val,int max_val);
undefined4 Card_NetherShadow_ReturnFromGrave(int value,int min_val,int max_val);
undefined4 Card_RockHydra_DecrementHead(int value,int min_val,int max_val);
undefined4 Card_RockHydra_DamageTrigger(int value,int min_val,int max_val);
void Card_RockHydra_UpdateStatsFromHeads(int value,int min_val,int max_val);
undefined4 Card_RockHydra_InitHeads(int value,int min_val,int max_val);
undefined4 Card_RockHydra_RegrowHead(int value,int min_val,int max_val);
undefined4 Card_AliBaba_TapWall(int spell_id,int target_id,int flags);
undefined4 Card_LeyDruid_UntapLand(int spell_id,int target_id,int flags);
uint Card_LeyDruid_AiEvaluateLand(int value,int min_val,int max_val);
undefined4 Card_LeyDruid_ExecuteUntap(int value,int min_val,int max_val);
void Card_HurkylsRecall_PickArtifact(int value,int min_val,int max_val);
void Card_HurkylsRecall_ReturnAllArtifacts(int value,int min_val,int max_val);
undefined4 Card_Venom_DestroyCombatBlocker(int spell_id,int target_id,int flags);
undefined4 Card_Venom_AttachToCreature(int value,int min_val,int max_val);
undefined4 Card_Venom_CombatDamageTrigger(int value,int min_val,int max_val);
undefined4 Card_Venom_DestroyAtEndOfCombat(int value,int min_val,int max_val);
bool Card_Venom_AiEvaluateAura(int value,int min_val,int max_val);
undefined4 Card_Venom_AiCastScore(int value,int min_val,int max_val);
undefined4 Card_Venom_ClearAuraFlags(int value,int min_val,int max_val);
undefined4 Card_RadjanSpirit_RemoveFlying(int spell_id,int target_id,int flags);
undefined4 Card_HurrJackal_GrantCombatAbility(int spell_id,int target_id,int flags);
undefined4 CardQuery_PlayerControlsColor(int player,byte card_slot);
void CardQuery_ForEachPermanent(undefined *player,int card_slot);
void Card_IncrementCounter(int player,int card_slot);
void Card_DecrementCounter(int player,int card_slot);
void Card_AddCounters(int value,int min_val,int max_val);
void Card_RemoveCounters(int value,int min_val,int max_val);
void Card_SetCounters(int value,int min_val,int max_val);
uint Card_GetCounters(int player,int card_slot);
bool CardTarget_PromptTargetCreature(int value,uint min_val,int max_val);
bool CardTarget_SetTargetCreature(int value,uint min_val,int max_val);
int CardTarget_HasValidCreatureTarget(int value);
bool CardTarget_PromptTargetPermanent(int value,uint min_val,int max_val);
bool CardTarget_SetTargetPermanent(int value,uint min_val,int max_val);
undefined4 CardTarget_HasValidPermanentTarget(int value);
bool CardTarget_PromptTargetPlayerOrCreature(int value,uint min_val,int max_val);
bool CardTarget_SetTargetPlayerOrCreature(int value,uint min_val,int max_val);
undefined4 CardTarget_HasValidPlayerOrCreatureTarget(int value);
undefined4 Adventure_EnterTownLocation(void);
void Adventure_PromptLocationMenu(void);
int Adventure_HandleLocationMenuChoice(int player,int card_slot);
void Adventure_ExitTownLocation(void);
int Adventure_PlayLocationMusic(void);
void Adventure_UpdateWorldMapLoop(void);
undefined4 Adventure_GetLocationEncounterIndex(undefined4 value);
undefined4 Adventure_SetLocationEncounterIndex(undefined4 value);
int Adventure_CheckMonsterEncounter(int player,int card_slot);
void Adventure_FormatNewsString(int value,int min_val,int max_val);
undefined4 Adventure_AppendNewsDetails(undefined4 player,int card_slot);
void Adventure_PlayMonsterEncounterSound(int x,int min_val,int max_val,int height);
void Adventure_TriggerDuelFromEncounter(void);
void Adventure_ReloadWorldPalette(int value);
void Adventure_LoadFacePalette(int value);
void Adventure_NewsFlash_EnemyAttack(void);
void Adventure_NewsFlash_Retaliation(int value);
void Adventure_NewsFlash_DominionSpell(void);
void Adventure_Audio_PlayEffect(char *value,undefined4 min_val,int max_val,int flags,int flags);
void Adventure_Audio_PlayEffectAtVolume(undefined4 value,int y,int width,int height);
void Adventure_Audio_PlayEffectLooped(undefined4 value,int min_val,int max_val);
void Adventure_Audio_StopEffectChannel(undefined4 value,int min_val,int max_val);
void Adventure_Audio_SetPlaybackPosition(char *player,undefined4 card_slot);
void Adventure_Audio_StopAllTracks(void);
void Adventure_Audio_PlayCastleVictory(int value);
void Adventure_Audio_PlayDuelIntro(int value);
void Adventure_Audio_PlayTerrainAmbience(int value);
void Adventure_Audio_PlayFootstep(void);
uint Adventure_Audio_FindSoundOnDrives(char *str_1);
char Adventure_Audio_GetMusicDrivePath(void);
void Adventure_Audio_FreeSoundTrack(void *value);
undefined4 Adventure_Audio_InitSoundTrack(char *str_1,undefined4 min_val,undefined4 max_val);
undefined4 Adventure_Audio_GetTrackStatus(undefined4 value);
int Adventure_Map_GetTerrainAtCoord(uint value);
void Adventure_Map_RedrawViewport(void);
undefined4 Adventure_Map_UpdateLightingAndPalette(uint player,uint card_slot);
void Adventure_ShowDefeatScreen(void);
bool Adventure_PromptConfirmDialog(LPCSTR str_1);
void Adventure_DestroyConfirmMenu(void);
int Duel_MainArena_WndProc(HWND hwnd,uint y,HWND param_3,uint height);
void Duel_UpdateWindowScroll(HWND hwnd);
void Duel_BringCardWindowToTop(HWND hwnd);
void Duel_GetBattlefieldClientRect(HWND hwnd);
void Duel_LayoutCardSlots(HWND hwnd,int *min_val,int max_val,int *flags,int *flags,int arg_6);
void Duel_ScrollLeftButton_Handler(HWND hwnd,HWND param_2);
void Duel_ScrollRightButton_Handler(HWND hwnd,LPARAM min_val,byte max_val);
int Duel_HitTestCardSlot(HWND hwnd,int *y,undefined4 *max_val,undefined4 *flags);
undefined4 Duel_GetHoveredCardSlot(HWND hwnd,int *card_slot);
int Duel_GetCardSlotWindowHandle(HWND hwnd,int card_slot);
int Duel_GetTargetSlotWindowHandle(HWND hwnd,int card_slot);
HGDIOBJ Duel_PaintBattlefieldBackground(HWND hwnd,uint min_val,HDC hdc);
int Duel_LogActionStatusBanner(int spell_id,int target_id,int flags,uint flags,uint flags,char *str_6,undefined4 arg_7);
bool Duel_RegisterChildCardWindowClass(LPCSTR str_1);
void Duel_UnregisterCardWindowClass(void);
LRESULT Duel_ChildCard_WndProc(HWND hwnd,uint uMsg,WPARAM wParam,LPARAM lParam);
int Duel_GetCardDrawOriginX(int player,int card_slot);
int Duel_GetCardDrawOriginY(int player,int card_slot);
void Duel_TriggerCardDrawAnimation(void);
int Duel_UpdateCardMotionStep(uint value);
void Duel_ResetCardAnimationState(char player,char card_slot);
int Bazaar_GetCardBaseValue(int value);
int Bazaar_SellCardsDialog(int value);
undefined4 * Catalog_LoadWaveletCardArt(int value,char *str_2,int max_val);
undefined4 Catalog_ReleaseWaveletLock(void);
undefined8 * Haar_DecompressWaveletImage(int *player,undefined8 *card_slot);
void FUN_004f1cfa(void);
void Mem_AllocOrFree_004f1e20(undefined8 *value,undefined8 *min_val,uint max_val);
void Haar_Transform2D_Inverse(undefined8 *value,uint min_val,uint max_val);
void Mem_AllocOrFree_004f1ec0(int *value,int min_val,int max_val);
void FUN_004f1ecb(void);
void FUN_004f207a(int value,undefined4 min_val,int *max_val,int *flags,int *flags,int arg_6,undefined4 arg_7,undefined4 arg_8,int arg_9);
void Mem_AllocOrFree_004f2110(int *value,int *min_val,int *max_val,int flags,int flags,undefined4 arg_6,int arg_7);
void FUN_004f211a(int value,undefined4 min_val,int *max_val,int *flags,int *flags,int arg_6,undefined4 arg_7,undefined4 arg_8,int arg_9);
undefined1 *Mem_AllocOrFree_004f21d0(undefined1 *value,int *min_val,int max_val,int flags,int *flags,int *arg_6,int arg_7,undefined4 arg_8,int arg_9);
undefined1 * FUN_004f21db(void);
undefined4 Haar_DecompressHeader(undefined4 *player,int *card_slot);
uint * FUN_004f27c0(void);
undefined4 FUN_004f2c50(HWND value,int y,int width,int height);
int FUN_004f2d30(HWND hwnd,int min_val,int max_val,int flags,DWORD flags,DWORD arg_6);
undefined4 UI_DialogProc_004f2e60(char *str_1,char *str_2,undefined4 *max_val);
HGDIOBJ UI_CreateWindow_004f2f56(HWND hwnd,uint y,HDC hdc,HWND param_4);
undefined4 FUN_004f3579(int value);
bool FUN_004f3880(void);
void FUN_004f38dd(void);
void FUN_004f391e(char *str_1);
void GDI_RealizeAndFlushPalette_Magic(HDC hdc);
undefined4 FUN_004f39a4(undefined4 value,int min_val,undefined4 *max_val,BITMAPINFO *flags,undefined4 *flags,undefined4 *arg_6,int *arg_7);
void FUN_004f3b2c(HDC hdc,HGDIOBJ card_slot);
undefined4 FUN_004f3b5f(int value,int min_val,HANDLE max_val);
undefined4 FUN_004f3bc7(HDC hdc,int *min_val,HANDLE max_val,int flags,int flags,int arg_6,int arg_7);
undefined4 FUN_004f3d11(HDC hdc,int *min_val,HANDLE max_val);
undefined4 FUN_004f3e29(HDC value,int *min_val,HANDLE max_val);
undefined4 FUN_004f3eaa(HDC hdc,int *min_val,HANDLE max_val,int flags,int flags,int arg_6,int arg_7,int arg_8,int arg_9);
undefined4 FUN_004f4025(undefined4 value,LPCSTR str_2,void *max_val,undefined4 flags);
undefined4 FUN_004f40e6(LPCSTR str_1,void *min_val,undefined4 max_val);
HBITMAP FUN_004f41e7(BITMAPINFO *player,void *card_slot);
void GDI_DestroyDIBSection_Magic(HANDLE value);
undefined4 FUN_004f45da(void);
void FUN_004f48cb(void);
void FUN_004f48f1(int value,int min_val,RECT *max_val);
void FUN_004f4a92(char *str_1,char *str_2,int width,char *str_4);
int FUN_004f4ce1(char *str_1,char *str_2,int max_val);
int FUN_004f4eb3(HWND hwnd,char *str_2);
LRESULT UI_WndProc_004f4fb8(HWND hwnd,UINT uMsg,WPARAM wParam,LPARAM lParam);
undefined4 FUN_004f5048(char *str_1,COLORREF min_val,HBRUSH max_val);
void FUN_004f5107(int value,HBRUSH min_val,HGDIOBJ max_val,HGDIOBJ flags,COLORREF flags,int arg_6);
void FUN_004f54d5(int value,HANDLE min_val,HANDLE max_val,HANDLE flags,COLORREF flags,int arg_6);
void FUN_004f570c(HWND hwnd);
undefined4 FUN_004f5728(HWND hwnd);
LRESULT FUN_004f5769(HWND hwnd,UINT y,HWND param_3,LPARAM flags);
bool FUN_004f589e(HWND hwnd);
undefined * FUN_004f58eb(char *str_1,int card_slot);
void FUN_004f59f7(void);
int FUN_004f5b76(int player,int card_slot);
undefined4 FUN_004f5bf9(HWND hwnd,int min_val,int max_val);
uint FUN_004f5cbc(int value);
undefined4 GDI_RealizePaletteTree_Magic(HWND hwnd,uint y,HWND param_3,undefined4 flags);
undefined4 FUN_004f5ec4(HWND hwnd,int *card_slot);
uint FUN_004f5f20(int value,int min_val,int max_val,int flags,int flags);
void FUN_004f6060(int value,int min_val,int max_val,int flags,int flags,undefined4 arg_6);
int FUN_004f6180(char *str_1);
void Mem_AllocOrFree_004f6b02(void);
undefined4 FUN_004f6b33(LPCSTR str_1);
void Mem_AllocOrFree_004f6d88(void);
char * FUN_004f6db9(undefined4 *value);
undefined4 FUN_004f6e90(int value,int min_val,int max_val);
undefined4 FUN_004f714d(int value,int min_val,int max_val);
undefined4 Prompts_Load_004f72b0(int spell_id,int target_id,int flags);
undefined4 Prompts_Load_004f7658(int spell_id,int target_id,int flags);
undefined4 FUN_004f7869(int value,int min_val,int max_val);
undefined4 FUN_004f7a7a(int value,int min_val,int max_val);
undefined4 FUN_004f7bf6(int value,int min_val,int max_val);
undefined4 FUN_004f7d11(int value,int min_val,int max_val);
undefined4 FUN_004f7eee(int value,int min_val,int max_val);
undefined4 FUN_004f8031(int value,int min_val,int max_val);
void FUN_004f823a(int player,int card_slot);
undefined4 FUN_004f8295(int value,int min_val,int max_val);
undefined4 Prompts_Load_004f8321(int spell_id,int target_id,int flags);
undefined4 Prompts_Load_004f8672(int spell_id,int target_id,int flags);
undefined4 FUN_004f88ae(int value,int min_val,int max_val);
undefined4 Prompts_Load_004f899b(int spell_id,int target_id,int flags);
undefined4 FUN_004f90d7(int value,int min_val,int max_val);
undefined4 FUN_004f92f3(int value,int min_val,int max_val);
undefined4 FUN_004f9510(int value,int min_val,int max_val);
undefined4 FUN_004f95fd(int value,int min_val,int max_val);
undefined4 Prompts_Load_004f9737(int spell_id,int target_id,int flags);
undefined4 Prompts_Load_004f9bbd(int spell_id,int target_id,int flags);
undefined4 Prompts_Load_004f9e64(int spell_id,int target_id,int flags);
int FUN_004fa423(int player,int card_slot);
int FUN_004fa4b8(int value,int min_val,int max_val);
undefined4 Prompts_Load_004fa586(int spell_id,int target_id,int flags);
undefined4 Prompts_Load_004fb1e4(int spell_id,int target_id,int flags);
undefined4 FUN_004fb573(int value,int min_val,int max_val);
undefined4 Prompts_Load_004fb6b5(int spell_id,int target_id,int flags);
int Prompts_Load_004fbbd4(int spell_id,int target_id,int flags);
undefined4 FUN_004fc023(int value,int min_val,int max_val);
int Prompts_Load_004fc2e5(int spell_id,int target_id,int flags);
undefined4 FUN_004fc65e(int value,int min_val,int max_val);
undefined4 Prompts_Load_004fc89e(int spell_id,int target_id,int flags);
undefined4 Prompts_Load_004fcb7a(int spell_id,int target_id,int flags);
undefined4 Prompts_Load_004fceea(int spell_id,int target_id,int flags);
undefined4 FUN_004fd11b(int value,int min_val,int max_val);
undefined4 Prompts_Load_004fd3cf(int spell_id,int target_id,int flags);
undefined4 FUN_004fd5e4(int value,int min_val,int max_val);
undefined4 FUN_004fd844(int value,int min_val,int max_val);
int FUN_004fd9c0(int player,uint card_slot);
int FUN_004fdad2(int value,int min_val,uint max_val);
int FUN_004fdc20(int x,int y,uint width,int height);
undefined4 FUN_004fdd4b(int value,int min_val,int max_val);
undefined4 FUN_004fde38(int value,int min_val,int max_val);
undefined4 FUN_004fdf72(int value,int min_val,int max_val);
undefined4 Prompts_Load_004fe05f(int spell_id,int target_id,int flags);
undefined4 Prompts_Load_004fe67f(int spell_id,int target_id,int flags);
undefined4 FUN_004fe901(int value,int min_val,int max_val);
undefined4 Prompts_Load_004fe9b6(int spell_id,int target_id,int flags);
undefined4 Prompts_Load_004fef61(int spell_id,int target_id,int flags);
undefined4 Prompts_Load_004ff17f(int spell_id,int target_id,int flags);
undefined4 FUN_004ff36b(int value,int min_val,int max_val);
void FUN_004ff450(HWND hwnd);
HBRUSH UI_DialogProc_004ff5c6(HWND hwnd,uint uMsg,HDC wParam,HWND lParam);
void Pic_Load_s_WINBK_Options_004ffd9c(undefined4 *value,undefined4 *out_buffer,undefined4 *max_val,int *flags,int *flags,int *arg_6,undefined4 *arg_7,undefined4 *arg_8);
void FUN_004ffe82(HANDLE value,HGDIOBJ min_val,HGDIOBJ max_val,HGDIOBJ flags);
void Rules_ParseFilter_004ffedf(void);
void Rules_ParseFilter_0050065d(void);
void FUN_00500a5b(void);
void FUN_00500cd5(void);
int WinMain(HINSTANCE x,HINSTANCE y,LPSTR width,int height);
LRESULT UI_WndProc_ShowPaletteClass_005013be(HWND hwnd,uint uMsg,WPARAM wParam,uint lParam);
void FUN_00501671(void);
undefined4 Mem_AllocOrFree_005016f9(void);
undefined4 Mem_AllocOrFree_00501721(void);
void FUN_00501736(int value);
void FUN_0050176a(void);
void FUN_0050178d(void);
undefined4 Sound_LoadWav_sound_locmus1_005017a6(void);
void FUN_005017f0(undefined4 *value,undefined4 min_val,int max_val);
void AssertOrLog(int x,int y,int width,char *str_4);
void Assert_Handler_005019a0(int x,int y,int width,char *str_4);
bool UI_CreateWindow_00501ad0(LPCSTR str_1);
LRESULT UI_WndProc_00501b54(HWND hwnd,uint uMsg,WPARAM wParam,uint lParam);
void FUN_00501f50(uint value);
undefined4 FUN_00505c74(void);
bool FUN_00505d20(int value);
undefined4 FUN_00505e3f(int value);
void FUN_00505ea7(int value);
void FUN_00506029(char *str_1);
void FUN_00506102(void);
undefined4 FUN_005062b1(void);
undefined4 FUN_0050638d(int x,int y,int width,int height);
undefined4 FUN_005063f6(int player,int card_slot);
undefined4 FUN_005064e9(int player,int card_slot);
int Town_Process_00506580(uint value);
void Sound_LoadWav_x_sound_button2_00507b1a(void);
undefined4 FUN_00507b44(int player,int card_slot);
undefined4 Town_Process_00507c86(uint value);
void Town_Process_00508c3e(void);
void Town_Process_00508cd7(void);
undefined4 FUN_0050935e(int player,int card_slot);
void Merchant_ProcessBuy_00509517(void);
void Town_Process_00509fd4(void);
void Town_Process_0050a065(void);
void Town_Process_0050a0fd(void);
void Town_Process_0050a17b(void);
void Town_Process_0050a1f9(void);
void Town_Process_0050a262(void);
void FUN_0050a2e0(int value,int min_val,char *str_3);
undefined1 * FUN_0050a73e(int value);
int SellPrice(int value);
int FUN_0050a9bf(int value);
undefined4 FUN_0050aef6(int player,int card_slot);
void FUN_0050afbd(void);
int FUN_0050b00c(void);
int FUN_0050b0fc(byte player,byte card_slot);
void FUN_0050b1a0(void);
void FUN_0050b206(int value,int min_val,int max_val,int flags,char *str_5);
void FUN_0050b3de(int value,int min_val,int max_val,int flags,int flags,int arg_6,char *str_7);
void FUN_0050b5be(int value,int min_val,int max_val,int flags,int flags);
void FUN_0050b65f(int value,int min_val,int max_val,int flags,char *str_5);
void FUN_0050b9d5(int *value);
bool UI_CreateWindow_0050bba0(LPCSTR str_1);
void FUN_0050bcd6(void);
LRESULT UI_CreateWindow_0050bd27(HWND hwnd,uint y,HWND param_3,uint height);
void Mem_AllocOrFree_0050c82b(int value);
LRESULT UI_WndProc_0050c854(HWND hwnd,uint uMsg,HDC wParam,LPARAM lParam);
BOOL GetSaveFileNameA(LPOPENFILENAMEA value);
void MCIWndCreateA(void);
void DeckBuilderMain(void);
undefined4 Mem_AllocOrFree_0050ce80(void);
undefined4 Mem_AllocOrFree_0050ce90(undefined4 player,int card_slot);
undefined4 * thunk_FUN_0050cef0(void);
void Mem_AllocOrFree_0050cec0(int value);
undefined4 * FUN_0050cef0(void);
undefined4 * FUN_0050d0b0(int x,int y,int width,int height);
undefined4 FUN_0050d2a0(int value);
void FUN_0050d370(int player,undefined4 card_slot);
void FUN_0050d4a0(int *player,int card_slot);
void FUN_0050d4e0(int value);
void FUN_0050d520(int value);
void FUN_0050d560(int player,int card_slot);
uint Surface_GetPixel(int value,int min_val,int max_val);
uint Surface_GetPixelPtr(int *value,int min_val,int max_val);
void Surface_DrawLine(int *value,int min_val,int max_val,int flags,int flags,int arg_6);
void Surface_PutPixel(int *x,int y,int width,uint height);
void Surface_FillRect(int *value,int min_val,int max_val,int flags,int flags,uint arg_6);
void Surface_BlitToDevice(int *value,uint min_val,int max_val,uint flags,DWORD flags,int *arg_6,int arg_7,int arg_8);
void FUN_0050e040(int *value,uint min_val,int max_val,uint flags,DWORD flags,int *arg_6,int arg_7,int arg_8);
void Surface_StretchBlt(int *value,int min_val,int max_val,int flags,int flags,int *arg_6,int arg_7,int arg_8,int arg_9,int arg_10);
void FUN_0050e2f0(void);
void FUN_0050e6f0(int *value,int min_val,int max_val,int flags,int flags,int arg_6);
void Surface_PutLine(undefined4 *value,int min_val,int max_val,int flags,uint flags);
void Surface_GetLine(undefined4 *value,int min_val,int max_val,int flags,uint flags);
void FUN_0050e8b0(short *value);
void FUN_0050eb90(int value);
int FUN_0050ec20(HWND hwnd,void *min_val,int max_val,int flags,DWORD flags,DWORD arg_6);
void FUN_0050ec90(undefined4 value,int min_val,int max_val);
undefined4 Mem_AllocOrFree_0050ed10(void *value);
int FUN_0050edf0(char *str_1);
undefined4 FUN_0050eef0(int player,FILE *fp);
undefined4 FUN_0050f0f0(int value,int min_val,char *str_3);
undefined4 FUN_0050f1e0(int value,int min_val,LPCSTR str_3,LPCSTR str_4,int flags,DWORD arg_6);
HFONT FUN_0050f2e0(int player,LONG card_slot);
BOOL FUN_0050f350(int value);
int FUN_0050f390(int player,char card_slot);
int FUN_0050f440(int *player,char *str_2);
int FUN_0050f610(int *value,char *str_2,int max_val);
int Mem_AllocOrFree_0050f740(int value);
undefined4 FUN_0050f760(int *x,int y,int width,LPCSTR str_4);
int FUN_0050f820(int *x,int y,int width,char *str_4);
void Mem_AllocOrFree_0050fc00(void);
void FUN_0050fc20(void);
void Mem_AllocOrFree_0050fc50(void *value);
size_t FUN_0050fc70(void *player,char *str_2);
int Sprite_LoadAll(undefined4 *player,char *str_2);
uint Sprite_LoadCount(undefined4 *value,char *str_2,uint max_val);
int Sprite_ScanRunLength(int value,int min_val,int max_val,int flags,int flags);
void Sprite_EncodeFromSurface(int value,int min_val,int max_val,uint flags,int flags);
void Sprite_DrawDirect(int *x,int y,int width,int height);
void Sprite_DrawClipped(int *x,int y,int width,int height);
void Sprite_DrawScaled(int *value,int min_val,int max_val,int flags,int flags,int arg_6);
void FUN_00510b70(int value,int min_val,int max_val,char *str_4,short *flags);
void Mem_AllocOrFree_00510de0(int player,char *str_2);
void Mem_AllocOrFree_00510e20(int player,char *str_2);
void LoadPalNoPic(char *filepath);
void Mem_AllocOrFree_00510e60(char *str_1,short *card_slot);
void FUN_00510fc0(int *player,int *card_slot);
void FUN_00511120(uint *player,int *card_slot);
int Surface_TransformPoint(short player,short card_slot);
int FUN_005115a0(short player,short card_slot);
undefined4 FUN_00511930(HDC hdc,COLORREF min_val,int max_val,int flags,int flags,int arg_6,int arg_7,int arg_8);
uint FUN_005119e0(HDC hdc,int min_val,int max_val,int flags,int flags,int arg_6,int arg_7,HDC param_8);
uint FUN_00511b90(HDC hdc,int min_val,int max_val,int flags,int flags,int arg_6,int arg_7,HDC param_8,int arg_9,int arg_10);
undefined4 FUN_00511d60(HDC hdc,COLORREF min_val,int max_val,int flags,int flags,int arg_6,int arg_7,int arg_8,int arg_9,int arg_10);
void FUN_00511e20(HDC hdc,int min_val,int max_val,int flags,int flags,int arg_6,int arg_7,int arg_8,int arg_9,HDC param_10);
undefined4 Mem_AllocOrFree_005121d0(void);
undefined4 Mem_AllocOrFree_005121e0(void);
void FUN_005121f0(void);
void FUN_00512200(void);
undefined4 Mem_AllocOrFree_00512210(void);
void Mem_AllocOrFree_00512220(void);
undefined4 * FUN_00512230(char *str_1,undefined4 *min_val,void *max_val);
undefined4 FUN_00512500(void *value);
undefined4 FUN_005126b0(byte *value);
undefined4 FUN_00512740(void);
undefined4 FUN_005129a0(byte *player,int card_slot);
undefined4 FUN_00512b50(void *value);
int FUN_00512ba0(undefined4 player,char *str_2);
int FUN_00512c00(undefined4 value,int min_val,int max_val,int flags,int flags,int arg_6,char *str_7);
void Mem_AllocOrFree_00512c90(int value,undefined *min_val,undefined4 max_val,int flags,int flags,int arg_6,int arg_7);
void FUN_00512c9d(void);
void FUN_00513200(int value);
void FUN_005134a0(void);
uint FUN_00513510(int value);
void FUN_005135e0(int player,uint card_slot);
ATOM UI_Register_ShowPaletteClass_00513820(HINSTANCE hInstance);
void UI_Register_ShowPaletteClass_005138b0(HINSTANCE hInstance,HWND hwnd);
void FUN_00513a70(HDC hdc,int min_val,int max_val,int flags,int flags,uint arg_6);
size_t __cdecl strlen(char *str_1);
int __cdecl sprintf(char *str_1,char *str_2,...);
int __cdecl abs(int value);
char * __cdecl strcat(char *str_1,char *str_2);
char * __cdecl strcpy(char *str_1,char *str_2);
int __cdecl strcmp(char *str_1,char *str_2);
void * __cdecl memcpy(void *ptr_1,void *ptr_2,size_t max_val);
int __cdecl _vsnprintf(char *str_1,size_t min_val,char *str_3,va_list flags);
void * __cdecl memset(void *ptr_1,int min_val,size_t max_val);
clock_t __cdecl clock(void);
void Mem_AllocOrFree_00513bd0(void);
int __cdecl memcmp(void *ptr_1,void *ptr_2,size_t max_val);
longlong __fastcall __allshl(byte player,int card_slot);
_onexit_t __onexit(_onexit_t value);
int __cdecl _atexit(_func_4879 *ptr_1);
void entry(void);
int __cdecl _write(int value,void *ptr_2,uint max_val);
void __dllonexit(void);
void __cdecl initterm(void);
void __setdefaultprecision(void);
undefined4 Mem_AllocOrFree_00514060(void);
int __cdecl __setargv(void);
uint __cdecl _controlfp(uint player,uint card_slot);
int __cdecl _chdir(char *str_1);
void __fastcall FUN_0070d000(undefined4 value,undefined4 min_val,ushort *max_val);
void __fastcall FUN_0070d245(undefined4 player,undefined4 card_slot);
void FUN_0070d2b5(void);
void __fastcall FUN_0070d300(uint value);
undefined4 __fastcall FUN_0070d392(undefined4 value,uint min_val,undefined4 max_val);
void Mem_AllocOrFree_0070d484(undefined4 player,uint card_slot);


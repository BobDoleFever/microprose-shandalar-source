typedef unsigned char   undefined;

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

typedef struct _TIME_ZONE_INFORMATION _TIME_ZONE_INFORMATION, *P_TIME_ZONE_INFORMATION;

typedef struct _TIME_ZONE_INFORMATION *LPTIME_ZONE_INFORMATION;

typedef long LONG;

typedef wchar_t WCHAR;

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

struct _TIME_ZONE_INFORMATION {
    LONG Bias;
    WCHAR StandardName[32];
    SYSTEMTIME StandardDate;
    LONG StandardBias;
    WCHAR DaylightName[32];
    SYSTEMTIME DaylightDate;
    LONG DaylightBias;
};

typedef struct _OVERLAPPED *LPOVERLAPPED;

typedef DWORD (*PTHREAD_START_ROUTINE)(LPVOID);

typedef PTHREAD_START_ROUTINE LPTHREAD_START_ROUTINE;

typedef struct _SECURITY_ATTRIBUTES *LPSECURITY_ATTRIBUTES;

typedef struct _STARTUPINFOA _STARTUPINFOA, *P_STARTUPINFOA;

typedef char CHAR;

typedef CHAR *LPSTR;

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

typedef struct _SYSTEMTIME *LPSYSTEMTIME;

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

typedef struct _strflt _strflt, *P_strflt;

struct _strflt {
    int sign;
    int decpt;
    int flag;
    char *mantissa;
};

typedef struct _strflt *STRFLT;

typedef enum enum_3272 {
    INTRNCVT_OK=0,
    INTRNCVT_OVERFLOW=1,
    INTRNCVT_UNDERFLOW=2
} enum_3272;

typedef enum enum_3272 INTRNCVT_STATUS;

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

typedef BOOL (*PHANDLER_ROUTINE)(DWORD);

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

typedef int errno_t;

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

typedef longlong __time64_t;

typedef __time64_t time_t;

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

typedef WCHAR *LPWSTR;

typedef WCHAR *PCNZWCH;

typedef WCHAR *LPWCH;

typedef WCHAR *LPCWSTR;

typedef LONG *PLONG;

typedef CHAR *LPCH;

typedef DWORD ACCESS_MASK;

typedef short SHORT;

typedef DWORD LCID;

typedef CHAR *PCNZCH;

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

typedef struct tm tm, *Ptm;

struct tm {
    int tm_sec;
    int tm_min;
    int tm_hour;
    int tm_mday;
    int tm_mon;
    int tm_year;
    int tm_wday;
    int tm_yday;
    int tm_isdst;
};

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

typedef BOOL *LPBOOL;

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

typedef struct HMENU__ HMENU__, *PHMENU__;

typedef struct HMENU__ *HMENU;

struct HMENU__ {
    int unused;
};

typedef WORD *LPWORD;

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

typedef struct _LDBL12 _LDBL12, *P_LDBL12;

struct _LDBL12 {
    uchar ld12[12];
};

typedef struct _CRT_FLOAT _CRT_FLOAT, *P_CRT_FLOAT;

struct _CRT_FLOAT {
    float f;
};

typedef struct _LDOUBLE _LDOUBLE, *P_LDOUBLE;

struct _LDOUBLE {
    uchar ld[10];
};

typedef struct _CRT_DOUBLE _CRT_DOUBLE, *P_CRT_DOUBLE;

struct _CRT_DOUBLE {
    double x;
};

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




bool UI_CreateWindow_00401000(LPCSTR str_1);
void FUN_004010b7(void);
LRESULT UI_WndProc_004010e5(HWND hwnd,uint uMsg,WPARAM wParam,LPARAM lParam);
undefined4 FUN_004014e0(int max_val,int point,int hBitmap);
undefined4 FUN_0040179d(int max_val,int point,int hBitmap);
undefined4 Palette_Color_0049ae00(int spell_id,int target_id,int flags);
undefined4 Palette_Color_0049ae00(int spell_id,int target_id,int flags);
undefined4 FUN_00401eb9(int max_val,int point,int hBitmap);
undefined4 FUN_004020ca(int max_val,int point,int hBitmap);
undefined4 FUN_00402245(int max_val,int point,int hBitmap);
undefined4 FUN_00402360(int max_val,int point,int hBitmap);
undefined4 FUN_0040253d(int max_val,int point,int hBitmap);
undefined4 FUN_00402680(int max_val,int point,int hBitmap);
void FUN_00402889(int player,int card_slot);
undefined4 FUN_004028e4(int max_val,int point,int hBitmap);
undefined4 Palette_Color_0049ae00(int spell_id,int target_id,int flags);
undefined4 Palette_Color_0049ae00(int spell_id,int target_id,int flags);
undefined4 FUN_00402efd(int max_val,int point,int hBitmap);
undefined4 Glue_Subsystem_004dec09(int spell_id,int target_id,int flags);
undefined4 FUN_00403725(int max_val,int point,int hBitmap);
undefined4 FUN_00403943(int max_val,int point,int hBitmap);
undefined4 FUN_00403b5f(int max_val,int point,int hBitmap);
undefined4 FUN_00403c4c(int max_val,int point,int hBitmap);
undefined4 Palette_Color_0049ae00(int spell_id,int target_id,int flags);
undefined4 Palette_Color_0049ae00(int spell_id,int target_id,int flags);
undefined4 Palette_Color_0049ae00(int spell_id,int target_id,int flags);
int FUN_00404a71(int player,int card_slot);
int FUN_00404b06(int max_val,int point,int hBitmap);
undefined4 Palette_Color_0049ae00(int spell_id,int target_id,int flags);
undefined4 Palette_Color_0049ae00(int spell_id,int target_id,int flags);
undefined4 FUN_00405bc0(int max_val,int point,int hBitmap);
undefined4 Palette_Color_0049ae00(int spell_id,int target_id,int flags);
int Pic_Load_0042a1c9(int spell_id,int target_id,int flags);
undefined4 Glue_Subsystem_004e4508(int max_val,int point,int hBitmap);
int Pic_Load_0042a1c9(int spell_id,int target_id,int flags);
undefined4 Glue_Subsystem_004e4508(int max_val,int point,int hBitmap);
undefined4 Palette_Color_0049ae00(int spell_id,int target_id,int flags);
undefined4 Palette_Color_0049ae00(int spell_id,int target_id,int flags);
undefined4 Palette_Color_0049ae00(int spell_id,int target_id,int flags);
undefined4 Glue_Subsystem_004e4508(int max_val,int point,int hBitmap);
undefined4 Palette_Color_0049ae00(int spell_id,int target_id,int flags);
undefined4 FUN_00407c33(int max_val,int point,int hBitmap);
undefined4 FUN_00407e93(int max_val,int point,int hBitmap);
int FUN_0040800f(int player,uint card_slot);
int FUN_00408121(int max_val,int point,uint hBitmap);
int FUN_0040826f(int x,int y,uint width,int height);
undefined4 FUN_0040839a(int max_val,int point,int hBitmap);
undefined4 FUN_00408487(int max_val,int point,int hBitmap);
undefined4 FUN_004085c1(int max_val,int point,int hBitmap);
undefined4 Palette_Color_0049ae00(int spell_id,int target_id,int flags);
undefined4 Palette_Color_0049ae00(int spell_id,int target_id,int flags);
undefined4 FUN_00408f50(int max_val,int point,int hBitmap);
undefined4 Palette_Color_0049ae00(int spell_id,int target_id,int flags);
undefined4 Palette_Color_0049ae00(int spell_id,int target_id,int flags);
undefined4 Palette_Color_0049ae00(int spell_id,int target_id,int flags);
undefined4 FUN_004099bb(int max_val,int point,int hBitmap);
void Mem_AllocOrFree_00409aa0(int max_val,int point,int hBitmap);
void Mem_AllocOrFree_00409ac6(int max_val,int point,int hBitmap);
void Mem_AllocOrFree_00409aec(int max_val,int point,int hBitmap);
void Mem_AllocOrFree_00409b12(int max_val,int point,int hBitmap);
void Mem_AllocOrFree_00409b38(int max_val,int point,int hBitmap);
undefined4 FUN_00409b5e(int x,int y,int width,int flags);
undefined4 Mana_Init_00456f29(int spell_id,int target_id,int flags);
undefined4 Minit_Subsystem_004572aa(int spell_id,int target_id,int flags);
undefined4 FUN_0040a4d6(int max_val,int point,int hBitmap);
undefined4 FUN_0040a70a(int max_val,int point,int hBitmap);
undefined4 FUN_0040a940(int max_val,int point,int hBitmap);
undefined4 FUN_0040aaec(int max_val,int point,int hBitmap);
undefined4 Minit_Subsystem_00457e67(int spell_id,int target_id,int flags);
undefined4 FUN_0040b327(int max_val,int point,int hBitmap);
undefined4 FUN_0040b469(int max_val,int point,int hBitmap);
undefined4 FUN_0040b626(int max_val,int point,int hBitmap);
undefined4 FUN_0040b998(int max_val,int point,int hBitmap);
undefined4 FUN_0040b9fe(int player,int card_slot);
undefined4 FUN_0040ba3d(int max_val,int point,int hBitmap);
undefined4 Card_Setup_004590b4(int max_val,int point,int hBitmap);
undefined4 Minit_Subsystem_004592ae(int max_val,int point,int hBitmap);
undefined4 Minit_Subsystem_004594d8(int spell_id,int target_id,int flags);
undefined4 Minit_Subsystem_004597d4(int spell_id,int target_id,int flags);
undefined4 Minit_Subsystem_00459d0a(int max_val,int point,int hBitmap);
int FUN_0040cea5(int player,int card_slot);
undefined4 Minit_Subsystem_0045a252(int spell_id,int target_id,int flags);
undefined4 FUN_0040d1af(int player,int card_slot);
undefined4 Minit_Subsystem_0045a575(int spell_id,int target_id);
undefined4 FUN_0040d50e(int max_val,int point,int hBitmap);
bool Minit_Subsystem_0045a825(int spell_id,int target_id,int flags);
undefined4 Minit_Subsystem_0045a9ff(int spell_id,int target_id,int flags);
undefined4 Minit_Subsystem_0045b156(int spell_id,int target_id,int flags);
undefined4 Mana_Init_0045b502(int spell_id,int target_id,int flags);
undefined4 Mana_Init_0045b7d9(int spell_id,int target_id,int flags);
undefined4 FUN_0040ea12(int max_val,int point,int hBitmap);
undefined4 Minit_Subsystem_0045bd50(int spell_id,int target_id,int flags);
undefined4 Minit_Subsystem_0045c59a(int spell_id,int target_id,int flags);
undefined4 FUN_0040fdb5(int max_val,int point,int hBitmap);
undefined4 Minit_Subsystem_0045d1f0(int spell_id,int target_id,int flags);
undefined4 FUN_004105cf(int max_val,int point,int hBitmap);
undefined4 FUN_0041061c(int max_val,int point,int hBitmap);
undefined4 Minit_Subsystem_0045d8dc(int spell_id,int target_id,int flags);
undefined4 Minit_Subsystem_0045dda5(int spell_id,int target_id,int flags);
undefined4 FUN_00410dfe(int max_val,int point,int hBitmap);
undefined4 FUN_00410f89(int max_val,int point,int hBitmap);
undefined4 FUN_00411032(int max_val,int point,int hBitmap);
undefined4 Mem_AllocOrFree_004110dc(undefined4 max_val,undefined4 point,int hBitmap);
void Mem_AllocOrFree_004110fe(int max_val,int point,int hBitmap);
void Mem_AllocOrFree_00411124(int max_val,int point,int hBitmap);
void Mem_AllocOrFree_0041114a(int max_val,int point,int hBitmap);
void Mem_AllocOrFree_00411170(int max_val,int point,int hBitmap);
void Mem_AllocOrFree_00411196(int max_val,int point,int hBitmap);
undefined4 Mana_Init_0045e430(int x,int y,int width,int flags);
undefined4 FUN_004117e6(int max_val,int point,int hBitmap);
undefined4 Minit_Subsystem_0045ebe4(int spell_id,int target_id,int flags);
undefined4 FUN_00411fe0(int max_val,int point,int hBitmap);
void Mem_AllocOrFree_00412153(int max_val,int point,int hBitmap);
void Mem_AllocOrFree_00412179(int max_val,int point,int hBitmap);
void Mem_AllocOrFree_0041219f(int max_val,int point,int hBitmap);
void Mem_AllocOrFree_004121c5(int max_val,int point,int hBitmap);
void Mem_AllocOrFree_004121eb(int max_val,int point,int hBitmap);
void Mem_AllocOrFree_00412211(int max_val,int point,int hBitmap);
undefined4 FUN_00412237(int x,int y,int width,int height);
undefined4 FUN_0041240a(int max_val,int point,int hBitmap);
int FUN_004125b3(int max_val,int point,int hBitmap);
undefined4 FUN_00412b3d(int max_val,int point,int hBitmap);
undefined4 FUN_00412e05(int max_val,int point,int hBitmap);
undefined4 FUN_0041313c(int max_val,int point,int hBitmap);
undefined4 FUN_00413269(int max_val,int point,int hBitmap);
undefined4 Minit_Subsystem_004605e4(int spell_id,int target_id,int flags);
undefined4 FUN_004137a7(int max_val,int point,int hBitmap);
undefined4 FUN_0041397d(int max_val,int point,int hBitmap);
undefined4 FUN_00413dc5(int max_val,int point,int hBitmap);
undefined4 FUN_00413f72(int max_val,int point,int hBitmap);
undefined4 FUN_0041410e(int max_val,int point,int hBitmap);
undefined4 Minit_Subsystem_004617ad(int spell_id,int target_id,int flags);
undefined4 Minit_Subsystem_00461ba1(int spell_id,int target_id,int flags);
void FUN_00414cbc(int max_val,int point,int hBitmap);
undefined4 FUN_00414e41(int max_val,int point,int hBitmap);
undefined4 FUN_0041500d(int max_val,int point,int hBitmap);
undefined4 Minit_Subsystem_004622d9(int spell_id,int target_id,int flags);
undefined4 FUN_00415450(int max_val,int point,int hBitmap);
undefined4 Minit_Subsystem_00462a0a(int spell_id,int target_id,int flags);
undefined4 FUN_00415a9c(int max_val,int point,int hBitmap);
undefined4 Minit_Subsystem_00462f7e(int spell_id,int target_id,int flags);
undefined4 FUN_0041649d(int max_val,int point,int hBitmap);
undefined4 FUN_0041698a(int max_val,int point,int hBitmap);
undefined4 Minit_Subsystem_00463cd1(int spell_id,int target_id,int flags);
undefined4 Minit_Subsystem_00463ef0(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_00439408(int max_val,int point,int hBitmap);
undefined4 FUN_00417308(int max_val,int point,int hBitmap);
int FUN_0041749c(int max_val,int point,int hBitmap);
void Mem_AllocOrFree_004178a4(int max_val,int point,int hBitmap);
void Mem_AllocOrFree_004178ca(int max_val,int point,int hBitmap);
undefined4 FUN_004178f0(int x,int y,int width,int height);
undefined4 FUN_00417d49(int max_val,int point,int hBitmap);
undefined4 Minit_Subsystem_00465165(int spell_id,int target_id,int flags);
undefined4 FUN_00418380(int max_val,int point,int hBitmap);
void FUN_00418755(int max_val,int point,uint hBitmap);
uint FUN_00418795(int player,int card_slot);
undefined4 Minit_Subsystem_00465a75(int spell_id,int target_id,int flags);
undefined4 Minit_Subsystem_00465e9c(int spell_id,int target_id,int flags);
undefined4 FUN_00419061(int max_val,int point,int hBitmap);
undefined4 Minit_Subsystem_00466541(int spell_id,int target_id,int flags);
undefined4 Card_Setup_0046695e(int max_val,int point,int hBitmap);
undefined4 FUN_0041983c(int max_val,int point,int hBitmap);
undefined4 Palette_Subsystem_004a9137(int max_val,int point,int hBitmap);
undefined4 FUN_00419cde(int max_val,int point,int hBitmap);
undefined4 Player_Init_0046709c(int spell_id,int target_id,int flags);
undefined4 FUN_0041a0ec(int max_val,int point,int hBitmap);
undefined4 FUN_0041a1eb(int max_val,int point,int hBitmap);
undefined4 FUN_0041a30b(void);
undefined4 FUN_0041a52d(int max_val,int point,int hBitmap);
bool UI_CreateWindow_0041a600(LPCSTR str_1);
void FUN_0041a698(void);
LRESULT Palette_Subsystem_004997e6(HWND hwnd,uint uMsg,int *wParam,int *lParam);
undefined4 UI_SelectTargetCardDialog(int *max_val,int point,int hBitmap,uint flags,uint damage,uint arg_6,uint arg_7,uint arg_8,uint arg_9,uint arg_10,uint arg_11,uint arg_12,int arg_13,int arg_14,uint arg_15,uint arg_16,uint arg_17,uint arg_18,uint arg_19);
uint Rules_ParseFilter_0041c0ab(int card_id,int color_mask,undefined1 *hBitmap,int flags,byte damage,byte arg_6,uint arg_7,uint arg_8,uint arg_9,uint arg_10,uint arg_11,uint arg_12,uint arg_13,int arg_14,int arg_15,uint arg_16,uint arg_17,uint arg_18,uint arg_19,uint arg_20);
int FUN_0041dd17(int player,int card_slot);
void Ai_Subsystem_004bc029(uint spell_id,undefined4 target_id,int flags);
int Duel_ChooseTarget(int spell_id,uint target_id,uint flags,uint flags,uint damage,uint arg_6,uint arg_7,uint arg_8,uint arg_9,uint arg_10,int arg_11,int arg_12,uint arg_13,uint arg_14,uint arg_15,uint arg_16,uint arg_17,undefined *arg_18,undefined4 arg_19,int *arg_20);
undefined4 FUN_0041e97e(int player,int card_slot);
undefined4 FUN_0041ea36(int player,int card_slot);
undefined4 Palette_Color_0049ae00(void);
void Palette_Color_0049ae00(void);
void FUN_0041fe7b(void);
undefined4 Palette_Subsystem_0049c3ac(int *max_val);
void FUN_0042043e(HDC hdc,RECT *card_slot);
undefined4 Palette_Subsystem_0049c7c7(HDC hdc,int *point,undefined4 *hBitmap,int flags,uint damage,int arg_6);
undefined4 FUN_004215c2(HDC hdc,int *point,int hBitmap,int flags,int damage,uint arg_6,int arg_7);
void FUN_00421802(int max_val,int point,uint hBitmap);
void FUN_00421990(HDC hdc,int point,char *str_3);
int FUN_00421a54(HDC hdc,char *str_2);
int FUN_00421b29(int *player,int card_slot);
uint Palette_Subsystem_0049dfb1(HDC hdc,int point,int hBitmap,LONG flags,char *str_5);
void FUN_0042200f(int max_val,char point,int hBitmap,int flags,int damage,int arg_6);
undefined4 FUN_004222b9(HDC hdc,int point,int hBitmap);
uint FUN_0042233a(HDC hdc,int *y,char *str_3,int height);
void FUN_0042297a(HDC hdc,RECT *point,int hBitmap,int flags);
void Palette_Subsystem_0049eda9(HDC hdc,int *point,int hBitmap,int flags,int damage);
void FUN_00423651(HDC hdc,int *point,undefined4 *hBitmap,int flags,int damage);
void Palette_Subsystem_0049c7c7(HDC hdc,RECT *point,int hBitmap);
void FUN_00423c6b(HDC hdc,int *y,uint width,uint height);
void FUN_00423e55(HDC hdc,int *point,undefined4 hBitmap);
undefined4 FUN_00423fbd(HDC hdc,int point,undefined4 hBitmap);
void FUN_00424114(LPRECT player,int *card_slot);
void FUN_004241e8(HDC hdc,int *point,int hBitmap,int flags,int damage);
undefined4 FUN_0042440b(int x,int y,int width,int height);
void FUN_0042458c(LPRECT max_val,int *point,int hBitmap);
undefined4 FUN_0042474a(int max_val,int *point,int hBitmap,int flags,int damage);
void FUN_00424a81(HDC hdc,undefined4 *point,uint hBitmap);
void FUN_00424d18(LPRECT max_val,uint y,int *width,uint height);
void FUN_00424f7b(HDC hdc,int *point,int hBitmap,int flags,int damage);
void FUN_00425138(HDC hdc,int *point,int hBitmap,undefined4 flags,int damage);
void Palette_Subsystem_0049eda9(HDC hdc,int *point,int hBitmap,int flags,int damage);
void Palette_Subsystem_004a155f(HDC hdc,RECT *point,int hBitmap,int flags,int damage,int arg_6,int arg_7);
void Palette_Subsystem_004a155f(HDC hdc,int *y,int width,int flags);
void FUN_00426181(HDC hdc,int *y,int width,int height);
void FUN_00426479(undefined4 player,undefined4 card_slot);
void FUN_00426500(undefined4 player,undefined4 card_slot);
void FUN_00426587(HDC hdc,int *card_slot);
uint FUN_00426620(HDC hdc,int *y,int width,int height);
void FUN_00426746(HDC hdc,int *point,int hBitmap);
void FUN_004267dc(undefined4 max_val,int *point,byte hBitmap);
void FUN_00426824(LPRECT player,int *card_slot);
undefined4 FUN_00426901(int max_val);
void FUN_00426b51(char *str_1,char *str_2,int hBitmap);
void Mem_AllocOrFree_00426c5c(void);
void FUN_00426c70(int max_val);
undefined4 FUN_0042a99c(void);
bool FUN_0042aa48(int max_val);
undefined4 FUN_0042ab67(int max_val);
void FUN_0042abcf(int max_val);
void FUN_0042ad51(int max_val);
void FUN_0042ae2a(void);
undefined4 FUN_0042afdb(void);
undefined4 FUN_0042b0b7(int x,int y,int width,int height);
undefined4 FUN_0042b120(int player,int card_slot);
undefined4 FUN_0042b213(int player,int card_slot);
bool UI_CreateWindow_0042b2a0(LPCSTR str_1);
LRESULT UI_WndProc_0042b324(HWND hwnd,uint uMsg,WPARAM wParam,uint lParam);
int Ai_CalcManaRequirement_004ba890(int max_val,int point,int hBitmap);
void FUN_0042c815(int x,int point,int *hBitmap,int height);
void FUN_0042c9be(int max_val,int point,int *hBitmap,int flags,int *damage,int arg_6);
void FUN_0042cbbb(int max_val,int point,int *hBitmap,int flags,int *damage,int arg_6);
undefined4 FUN_0042cdb6(int max_val,int point,int hBitmap);
undefined4 Ai_Subsystem_004bc029(undefined4 spell_id,int *target_id,int flags,int height);
undefined4 FUN_0042d247(int max_val,undefined4 point,undefined4 hBitmap,undefined4 flags,int damage);
undefined4 FUN_0042db54(int max_val,int point,byte hBitmap);
undefined4 FUN_0042dd5e(int player,int card_slot);
void FUN_0042df08(int max_val,int point,int hBitmap,int *flags,undefined4 damage,int arg_6,int arg_7,int arg_8,int *arg_9);
int FUN_0042df78(int max_val,int point,int hBitmap,int flags,int damage,int arg_6,int arg_7);
undefined4 FUN_0042e00f(void);
bool FUN_0042e081(int player,int card_slot);
bool Mem_AllocOrFree_0042e0cd(void);
undefined4 FUN_0042e101(int max_val);
undefined4 FUN_0042e1a0(int max_val);
undefined4 Ai_Subsystem_004bd6f9(int max_val,uint point,int hBitmap);
int FUN_0042ecaf(int x,int y,int width,int height);
uint Ai_ChooseCardToPlay(int max_val);
void Ai_SaveGameState(void);
void FUN_0042fea9(void);
void FUN_00430120(void);
void FUN_00430367(void);
void Ai_ClearPlan(void);
void Ai_BeginTrial(void);
void Ai_RecordChoice(void);
undefined4 Card_DispatchRulesEvent(int max_val);
undefined4 FUN_00430768(int max_val);
void Ai_ReplayChoice(void);
void Ai_CommitBestPlan(void);
undefined4 Ai_GetPlanCursor(void);
void Mem_AllocOrFree_004308e4(void);
int Ai_EvaluateBoard(int max_val);
int Ai_PenalizeCounterattack(int player,int card_slot);
undefined4 Ai_ChooseBlockers(int player,int card_slot);
void FUN_00431f41(uint *player,uint *card_slot);
undefined4 Mem_AllocOrFree_00431fe0(void);
undefined4 FUN_004327e0(void);
undefined4 FUN_00432822(void);
int FUN_00432860(int max_val);
int FUN_004328ba(int max_val);
uint FUN_00432a0b(char *str_1,int card_slot);
void FUN_00432ac7(int max_val);
undefined4 FUN_00432be5(char *max_val);
bool FUN_00432c2a(int max_val,void *point,uint hBitmap);
undefined4 Mem_AllocOrFree_00432c72(void);
undefined4 Mem_AllocOrFree_00432c87(void);
undefined4 FUN_00432c99(char *str_1);
undefined4 FUN_00432d7b(char *str_1);
uint FUN_00432e04(void);
uint FileIo_ReadDataBlock(void *player, uint card_slot);
int FUN_00433c39(char *str_1);
undefined4 Mem_AllocOrFree_00433c86(void);
undefined4 Mem_AllocOrFree_00433c98(void);
void FUN_00433caa(char *str_1);
uint FUN_00433d45(char *str_1);
bool UI_CreateWindow_00433e40(LPCSTR str_1);
LRESULT UI_WndProc_00433ed2(HWND hwnd,uint uMsg,HDC wParam,LPARAM lParam);
int Catalog_Open(char *str_1);
bool FUN_0043433a(int max_val);
undefined4 FUN_004343f6(int *player,int *card_slot);
void * FUN_00434446(int player,byte *card_slot);
size_t FUN_004344c1(int max_val,undefined4 point,int *hBitmap);
uint FUN_0043456a(byte *max_val);
int Catalog_ParseCsvLine(uint *player, uint *card_slot);
uint FUN_004348b2(undefined4 player,undefined4 card_slot);
void * FUN_00434a10(void);
undefined2 * Catalog_LoadPaletteMap(char *str_1,char *str_2);
undefined4 FUN_00434c97(void);
void FUN_00434d09(int *max_val,int point,int *hBitmap);
int FUN_00434d88(int *max_val);
undefined4 FUN_00434ec7(undefined4 *max_val,char *str_2,undefined4 hBitmap);
int FUN_00434fa1(int *max_val);
void FUN_0043504d(uint player,uint *card_slot);
undefined4 FUN_004350b1(void);
undefined4 FUN_004351b5(uint max_val);
uint FUN_00435343(uint max_val);
int FUN_004354bb(int *player,int *card_slot);
undefined4 FUN_00435551(uint *x,int y,int width,int height);
undefined4 FUN_004355e9(uint *x,int y,int width,int height);
int FUN_004356cf(int max_val,int point,uint *hBitmap,int flags,int damage,int arg_6);
void FUN_00435c74(undefined4 *player,int card_slot);
undefined4 Palette_AllocErrorDiffusionTable(int player,int card_slot);
undefined4 FUN_00435e6e(int max_val,byte *point,int hBitmap,int flags,int damage);
undefined4 FUN_00436293(int max_val,int point,int hBitmap,int flags,int damage,int arg_6);
void Mem_AllocOrFree_004367d4(void);
uint Mem_AllocOrFree_00436800(uint max_val);
undefined4 UI_Register_FACE_BLACK_00436820(LPCSTR str_1);
void FUN_00436a52(void);
LRESULT Ai_CalcManaRequirement_004b9284(HWND hwnd,uint uMsg,uint wParam,uint lParam);
void FUN_004371ec(HDC hdc,RECT *point,int hBitmap);
void FUN_0043753a(int player,int card_slot);
void FUN_00437681(undefined4 max_val);
undefined4 FUN_004376c0(int max_val);
undefined4 Palette_Color_00495430(char *str_1);
void FUN_00437b05(void);
int Palette_Subsystem_004958b1(int max_val);
undefined4 Palette_Subsystem_00495958(undefined1 *max_val);
void FUN_00437fb8(MSG *max_val);
undefined4 FUN_004381c6(int *player,UINT card_slot);
undefined4 Palette_Subsystem_0049608e(void);
void Palette_Subsystem_0049608e(void);
undefined4 Mem_AllocOrFree_0043860c(void);
undefined4 FUN_00438636(HWND max_val,uint y,HWND hBitmap,undefined4 flags);
undefined4 Palette_Subsystem_004963e7(void);
LRESULT Palette_Subsystem_00496497(HWND hwnd,uint y,WPARAM hBitmap,uint height);
int FUN_00438980(WPARAM max_val,int point,int width,int height);
undefined4 FUN_00438bf0(int player,int card_slot);
int FUN_00438c81(HDC hdc,RECT *point,int width,int flags);
undefined4 FUN_00438d5e(WPARAM max_val,int point,int width,int height);
void FUN_00438e72(int max_val);
int FUN_00438ec2(WPARAM max_val,int y,int width,int height);
undefined * FUN_00439172(int player,int card_slot);
int FUN_00439208(HDC hdc,RECT *point,int width,int height);
undefined4 FUN_004392f3(WPARAM max_val,int y,int width,int height);
void FUN_004393a2(int player,int card_slot);
void FUN_00439516(void);
void FUN_00439570(int max_val);
void FUN_004395d6(int player,int card_slot);
void FUN_00439659(char *max_val,int y,uint hBitmap,int flags);
int FUN_004396ea(int max_val);
void FUN_0043982e(void);
void Mem_AllocOrFree_00439863(void);
int Duel_RandomRange(int max_val);
void FUN_004398be(void);
void Mem_AllocOrFree_004398fe(void);
uint FUN_00439913(uint max_val);
undefined4 UI_DialogProc_00439980(uint *max_val,uint *point,undefined4 *hBitmap);
HGDIOBJ Palette_Subsystem_00496497(HWND hwnd,uint y,HDC hdc,HWND param_4);
undefined4 FUN_0043a094(int max_val);
bool Pic_Subsystem_00449340(LPCSTR str_1);
void FUN_0043a531(void);
LRESULT Pic_Subsystem_004494ff(HWND hwnd,uint uMsg,uint wParam,uint lParam);
LRESULT UI_WndProc_0043b02a(HWND hwnd,uint uMsg,WPARAM wParam,LPARAM lParam);
LRESULT UI_WndProc_0043b1a4(HWND hwnd,uint uMsg,WPARAM wParam,LPARAM lParam);
HWND Pic_Subsystem_00449340(HWND hwnd,int card_slot);
void FUN_0043b83b(HWND hwnd);
undefined4 FUN_0043b850(int max_val);
void Mem_AllocOrFree_0043b8a8(void);
HGDIOBJ Pic_Load_0044a862(HWND hwnd,uint uMsg,HDC wParam,HWND lParam);
void FUN_0043c2dd(LPRECT max_val,HWND hwnd,int width,int height);
size_t Ai_CalcManaRequirement_004b9284(char *str_1);
void Mem_AllocOrFree_0043ce47(void);
undefined4 FUN_0043ce77(LPCSTR str_1);
void Mem_AllocOrFree_0043d0c9(void);
char * FUN_0043d0f9(undefined4 *max_val);
undefined * FUN_0043d1d0(int max_val,int point,int hBitmap);
undefined4 Pic_Load_0042351b(int max_val,undefined4 point,undefined4 hBitmap,char *str_4,undefined1 *damage);
int Pic_Load_00423833(char *str_1);
int FUN_0043d799(char *str_1,int card_slot);
void FUN_0043d7cc(int max_val);
void Mem_AllocOrFree_0043d7f6(undefined4 max_val);
int FUN_0043d81d(void);
void Mem_AllocOrFree_0043d858(void);
void Mem_AllocOrFree_0043d863(void);
int Sound_Init(int hInst,undefined4 hWnd,uint flags);
void CloseSnd(void);
undefined4 InitSndTrack(undefined4 max_val,undefined4 point,undefined4 hBitmap);
undefined4 CloseSndTrack(undefined4 max_val);
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
undefined4 GetSndTime(undefined4 max_val);
undefined4 ResetSnd(undefined4 player,undefined4 card_slot);
undefined4 GetSndState(undefined4 player,undefined4 card_slot);
undefined4 GetAVISndBuff(undefined4 player,undefined4 card_slot);
undefined4 ReleaseAVISndBuff(undefined4 player,undefined4 card_slot);
undefined4 GetSndHWND(void);
undefined4 IsSndLoaded(undefined4 player,undefined4 card_slot);
undefined4 GetLRUSnd(undefined4 max_val,undefined4 point,undefined4 hBitmap);
void FUN_0043e09c(void);
undefined4 Duel_ShowStartOfDuelDialog(undefined4 *max_val,uint *point,uint hBitmap,int flags,uint damage,uint arg_6,undefined4 arg_7,int arg_8,undefined4 arg_9);
HGDIOBJ Ai_DuelDialogProc(HWND hwnd,uint uMsg,HWND wParam,HWND lParam);
void Ai_LoadStartDuel2Backdrop(undefined4 *max_val,undefined4 *out_buffer,undefined4 *hBitmap,undefined4 *flags,undefined4 *damage,undefined4 *arg_6);
void FUN_0043ec34(int max_val,int point,int hBitmap);
HGDIOBJ Ai_StartDuelWndProc(HWND hwnd,uint uMsg,HWND wParam,HWND lParam);
void Ai_LoadStartDuelBackdrop(undefined4 *max_val,undefined4 *out_buffer,undefined4 *hBitmap,undefined4 *flags,undefined4 *damage,undefined4 *arg_6,undefined4 *arg_7);
void FUN_0043fbce(int x,int y,int width,int height);
void Ai_Subsystem_004ae779(int max_val);
INT_PTR Ai_Subsystem_004ae8a3(undefined4 max_val,undefined4 point,undefined4 hBitmap,undefined4 flags,undefined4 damage);
HGDIOBJ Ai_DuelMainWndProc(HWND hwnd,uint uMsg,HDC wParam,HWND lParam);
void Ai_LoadEndDuelBackdrop(undefined4 *max_val,undefined4 *out_buffer,undefined4 *hBitmap,int *flags,int *damage,int *arg_6,undefined4 *arg_7,undefined4 *arg_8);
void FUN_00440a9c(int x,HGDIOBJ point,HGDIOBJ hBitmap,HGDIOBJ flags);
undefined4 FUN_00440af9(int player,int card_slot);
LRESULT FUN_00440c1e(undefined4 max_val,int point,undefined4 hBitmap,undefined4 flags,undefined4 damage,undefined4 arg_6,undefined4 arg_7,int *arg_8,undefined4 *arg_9,undefined4 arg_10,undefined4 arg_11);
void FUN_00440eff(void);
INT_PTR Ai_ScoreCardPlay_004afa69(int *max_val,int point,int hBitmap,undefined4 flags,int damage,uint *arg_6);
LRESULT Ai_ScoreCardPlay_004afc26(HWND hwnd,uint y,HDC hdc,undefined4 *flags);
void FUN_004421e2(int *max_val,int *point,int *hBitmap,int *flags,int *damage,undefined4 *arg_6);
void FUN_004422cf(HGDIOBJ max_val,HGDIOBJ point,HGDIOBJ hBitmap,HGDIOBJ flags,HGDIOBJ damage);
LRESULT UI_WndProc_0044233e(HWND hwnd,uint uMsg,WPARAM wParam,LONG *lParam);
void Mem_AllocOrFree_0044274a(void);
void FUN_00442839(uint max_val,int point,int hBitmap);
void Mem_AllocOrFree_004428c2(void);
INT_PTR FUN_004428d2(int max_val,undefined4 point,INT_PTR hBitmap,char *str_4,char *str_5,char *str_6);
HWND UI_DialogProc_00442a9b(HWND hwnd,uint uMsg,uint wParam,undefined4 *lParam);
INT_PTR FUN_00442e3c(int max_val,undefined4 point,INT_PTR hBitmap);
undefined4 UI_DialogProc_00442e98(HWND hwnd,uint uMsg,uint wParam,undefined4 *lParam);
INT_PTR FUN_00443000(int max_val,undefined4 point,INT_PTR hBitmap);
HGDIOBJ UI_DialogProc_00443063(HWND hwnd,uint uMsg,HDC wParam,HWND lParam);
LRESULT FUN_004435ad(HWND hwnd,UINT y,uint width,LPARAM flags);
void Ai_Subsystem_004b2183(undefined4 *max_val,undefined4 *out_buffer,int *hBitmap,int *flags,int *damage,undefined4 *arg_6,undefined4 *arg_7);
void FUN_00443727(int x,HGDIOBJ point,HGDIOBJ hBitmap,HGDIOBJ flags);
INT_PTR FUN_00443784(int max_val,undefined4 point,undefined4 hBitmap,int flags,uint damage);
HGDIOBJ Ai_Subsystem_004b257c(HWND hwnd,uint uMsg,HDC wParam,HWND lParam);
void Ai_CalcManaRequirement_004b32d1(undefined4 *max_val,undefined4 *out_buffer,undefined4 *hBitmap,undefined4 *flags,undefined4 *damage,int *arg_6,int *arg_7,int *arg_8,undefined4 *arg_9,undefined4 *arg_10);
void FUN_004449cf(int max_val,int point,int hBitmap,HGDIOBJ flags,HGDIOBJ damage,HGDIOBJ arg_6);
void FUN_00444a85(LPRECT max_val,HWND hwnd,int hBitmap);
INT_PTR FUN_00444c48(int max_val,undefined4 *point,undefined4 hBitmap,int flags,uint damage);
HBRUSH Ai_Subsystem_004b3847(HWND hwnd,uint uMsg,HWND wParam,HWND lParam);
void Ai_Subsystem_004b4197(undefined4 *max_val,undefined4 *out_buffer,int *hBitmap,int *flags,int *damage,undefined4 *arg_6,undefined4 *arg_7);
void FUN_0044573a(int x,HGDIOBJ point,HGDIOBJ hBitmap,HGDIOBJ flags);
void Mem_AllocOrFree_00445797(void);
uint FUN_004457a2(void);
void Duel_RefreshAllWindows(undefined4 player,uint card_slot);
void Mem_AllocOrFree_00446869(void);
undefined4 FUN_0044688e(void);
uint FUN_004468b5(void);
void Mem_AllocOrFree_004468f5(void);
void Mem_AllocOrFree_00446905(void);
undefined4 Ai_Subsystem_004b544d(void);
void FUN_004469c9(undefined *max_val);
void FUN_00446a07(char *str_1);
int FUN_00446c16(int max_val,int point,int hBitmap,int flags,undefined4 damage,undefined4 arg_6);
undefined4 FUN_00446d17(void);
void FUN_00446da2(int max_val);
undefined4 FUN_00446de2(int player,int card_slot);
uint FUN_00446e30(int player,int card_slot);
undefined4 FUN_00446ea2(int player,int card_slot);
uint FUN_00446f0f(int player,int card_slot);
void FUN_00446f81(int max_val,int point,uint *hBitmap,uint *flags,uint *damage);
int FUN_00447038(int player,int card_slot);
int FUN_004470a6(int player,int card_slot);
undefined4 FUN_00447114(int player,int card_slot);
undefined4 Deck_ValidateCardLimit(int player, int card_slot);
undefined4 FUN_004471f7(int player,int card_slot);
byte FUN_004472ad(int player,int card_slot);
void FUN_0044743d(int *max_val,int point,int hBitmap);
undefined4 FUN_004474ec(int *max_val,int point,int hBitmap);
undefined1 FUN_00447604(int player,int card_slot);
int FUN_00447675(int player,int card_slot);
int FUN_004476e3(int player,int card_slot);
uint FUN_00447751(int player,int card_slot);
int FUN_0044781f(int player,int card_slot);
int FUN_0044788d(int player,int card_slot);
undefined4 FUN_004478fb(int player,int card_slot);
undefined4 FUN_00447968(int player,int card_slot);
void FUN_004479d5(int x,int y,int *width,int *height);
undefined4 Mem_AllocOrFree_00447a76(void);
uint FUN_00447a88(int player,int card_slot);
uint FUN_00447aec(int player,int card_slot);
bool FUN_00447b5f(int player,int card_slot);
undefined4 FUN_00447c07(int player,int card_slot);
bool FUN_00447c74(int player,int card_slot);
bool FUN_00447cf8(int player,int card_slot);
void FUN_00447d7c(int max_val,int point,char *hBitmap);
void Ai_Subsystem_004b69ba(int max_val,int point,char *hBitmap);
int FUN_00448071(int max_val,int point,void *hBitmap);
undefined4 FUN_00448124(int player,int card_slot);
undefined4 FUN_00448191(int player,int card_slot);
undefined4 FUN_004481fe(int player,int card_slot);
void FUN_0044826e(undefined4 *max_val,int point,int hBitmap);
undefined4 FUN_00448304(int player,int card_slot);
int FUN_00448374(int player,int card_slot);
undefined4 Mem_AllocOrFree_004483e2(int max_val);
void FUN_00448412(char *str_1);
undefined4 FUN_0044846f(int max_val);
undefined4 FUN_004484d5(int max_val);
undefined4 FUN_0044853b(void *player,int card_slot);
undefined4 FUN_004485c7(void *max_val,int point,int hBitmap);
undefined4 FUN_00448653(void *player,int card_slot);
undefined4 FUN_004486f6(void *player,int card_slot);
undefined4 FUN_00448799(void *player,int card_slot);
undefined4 FUN_0044883c(void *max_val);
void FUN_00448897(int x,int *y,int width,int *height);
void FUN_0044897a(undefined4 *player,undefined4 *card_slot);
void FUN_004489c3(void *player,int card_slot);
void FUN_00448a38(undefined4 *max_val);
undefined4 FUN_00448a6d(void);
bool FUN_00448aa1(undefined4 *max_val);
undefined4 FUN_00448af2(void);
void FUN_00448b26(undefined4 *player,undefined4 *card_slot);
int FUN_00448b6f(void *max_val,int y,int width,int height);
void FUN_00448d16(undefined4 player,undefined4 card_slot);
undefined4 Ai_CalcManaRequirement_004b7897(HWND hwnd,uint uMsg,HDC wParam,undefined4 lParam);
int FUN_004491fe(uint *max_val);
HBRUSH Ai_Subsystem_004b7de8(HWND hwnd,uint uMsg,HDC wParam,HWND lParam);
void FUN_004497ae(undefined4 *player,undefined4 *card_slot);
void FUN_004497d2(HGDIOBJ max_val);
undefined4 FUN_004497f1(int max_val,int point,undefined4 hBitmap,undefined4 flags,undefined4 *damage,undefined4 *arg_6,undefined4 *arg_7);
HBRUSH Ai_Subsystem_004b8421(HWND hwnd,uint uMsg,HWND wParam,HWND lParam);
void Ai_Subsystem_004b8cc3(undefined4 *max_val,undefined4 *out_buffer,int *hBitmap,int *flags,int *damage,undefined4 *arg_6,undefined4 *arg_7);
void FUN_0044a267(int x,HGDIOBJ point,HGDIOBJ hBitmap,HGDIOBJ flags);
int FUN_0044a2c4(int player,int card_slot);
undefined1 * Ai_Subsystem_004b8e4d(int player,int card_slot);
void FUN_0044a5a4(int player,int card_slot);
undefined4 UI_Register_WINBK_ManaPool_004b9120(LPCSTR str_1);
void FUN_0044a6ce(void);
LRESULT Ai_CalcManaRequirement_004b9284(HWND hwnd,uint uMsg,uint wParam,uint lParam);
void FUN_0044bb84(LPRECT max_val,HWND hwnd,int hBitmap);
bool UI_CreateWindow_0044bd60(LPCSTR str_1);
LRESULT UI_WndProc_0044bde4(HWND hwnd,uint uMsg,WPARAM wParam,uint lParam);
undefined1 * FUN_0044c1e0(char *str_1,undefined1 *point,void *hBitmap);
bool FUN_0044c3f7(char *str_1,void *card_slot);
undefined4 FUN_0044c47a(void *max_val);
undefined4 FUN_0044c660(byte *max_val);
undefined4 FUN_0044c73c(undefined *max_val,char *str_2,void *hBitmap,undefined4 flags,undefined4 damage,int arg_6,int arg_7);
undefined4 FUN_0044c82c(undefined4 player,short card_slot);
undefined4 FUN_0044c8f0(char *str_1,int card_slot);
void FUN_0044ca03(byte max_val);
int FUN_0044ca50(char max_val,char *str_2,int hBitmap);
undefined4 FUN_0044caaf(void *max_val);
undefined4 Pic_Load_004248b0(LPCSTR str_1);
void FUN_0044cbf8(void);
undefined4 Pic_Load_00424a1e(LPCSTR str_1);
void Mem_AllocOrFree_0044cd3f(void);
LRESULT Pic_Load_00424b1f(HWND hwnd,uint uMsg,uint wParam,uint lParam);
void FUN_0044e141(POINT *x,RECT *point,undefined4 *hBitmap,int *height);
void FUN_0044e52d(LPRECT max_val,int point,int hBitmap,int flags,int damage);
void FUN_0044e776(HDC hdc,int card_slot);
LRESULT Pic_Load_004267c5(HWND hwnd,uint uMsg,uint wParam,uint lParam);
void FUN_0044fab8(POINT *max_val,RECT *point,undefined4 *hBitmap);
void FUN_0044fc75(LPRECT max_val,int y,int width,int height);
void FUN_0044fe36(HDC hdc,int card_slot);
void Pic_Draw_00427e36(int *max_val,undefined4 *point,int hBitmap);
void Mem_AllocOrFree_0045033a(void);
uint FUN_00450590(int player,int card_slot);
undefined4 Mem_AllocOrFree_004505c4(int player,int card_slot);
uint FUN_004505f3(int player,int card_slot);
int Mem_AllocOrFree_00450667(int player,int card_slot);
int Mem_AllocOrFree_00450697(int player,int card_slot);
undefined4 Mem_AllocOrFree_004506c7(int player,int card_slot);
undefined4 Mem_AllocOrFree_004506f6(int player,int card_slot);
undefined4 FUN_00450725(int player,int card_slot);
int CardTypeFromID(int max_val);
undefined4 CardIDFromType(uint max_val);
uint CardInDeck(uint max_val);
void SetCardInDeck(int player,int card_slot);
bool FUN_004508d0(int player,int card_slot);
byte FUN_00450917(int player,int card_slot);
undefined8 FUN_00450a32(int player,int card_slot);
undefined4 FUN_00450a90(int max_val,int point,int *hBitmap);
undefined1 FUN_00450b13(int player,int card_slot);
int Mem_AllocOrFree_00450b87(int player,int card_slot);
int Mem_AllocOrFree_00450bb7(int player,int card_slot);
undefined4 FUN_00450be7(int player,int card_slot);
int Mem_AllocOrFree_00450c48(int player,int card_slot);
int Mem_AllocOrFree_00450c78(int player,int card_slot);
char * Ai_Subsystem_004cc1e8(int player,int card_slot);
int FUN_00450d1b(int player,int card_slot);
int FUN_00450d8c(int player,int card_slot);
undefined4 FUN_00450dfd(int max_val,int point,undefined4 hBitmap);
undefined4 FUN_00450e84(int player,int card_slot);
void FUN_00450eb8(undefined4 max_val,undefined4 point,undefined4 hBitmap,undefined4 flags);
void Mem_AllocOrFree_00450eed(undefined *max_val);
undefined4 FUN_00450f15(int *max_val,int point,undefined4 hBitmap,int flags,undefined4 damage);
undefined4 FUN_00450f5a(int *max_val,int point,int hBitmap,undefined4 flags,int damage,undefined4 arg_6);
void Mem_AllocOrFree_00450fa1(undefined4 max_val);
void FUN_00450fca(undefined4 max_val,undefined4 point,undefined4 hBitmap,undefined4 flags);
int Ai_Subsystem_004cc56d(int max_val,int point,int hBitmap,int flags,int damage,uint *arg_6,int arg_7);
void FUN_00451282(undefined4 player,undefined4 card_slot);
INT_PTR FUN_004512d1(int max_val,undefined4 point,INT_PTR hBitmap,char *str_4,char *str_5,char *str_6);
INT_PTR FUN_0045133c(int max_val,undefined4 point,INT_PTR hBitmap);
INT_PTR FUN_0045139b(int max_val,undefined4 point,INT_PTR hBitmap);
int FUN_004513fa(int max_val,undefined4 point,undefined4 hBitmap,int flags,uint damage);
void FUN_0045143b(undefined4 max_val);
void Duel_UpdateBoardState(undefined4 player,undefined4 card_slot);
void FUN_00451760(void);
void FUN_00451995(void);
void FUN_00451c0c(undefined4 max_val);
void FUN_00451c55(void);
undefined4 FUN_00451c8e(void);
undefined4 Ai_Subsystem_004cd20e(void);
void FUN_00451e58(void);
undefined4 Glue_Timer_004cd63b(void);
undefined4 FUN_00452153(void);
void Mem_AllocOrFree_00452185(void);
int FUN_0045219a(void);
undefined4 Card_DefaultEventHandler(void);
uint Mana_GetCardColorRequirement(int player, int card_slot);
undefined4 Glue_Subsystem_004d0cdb(int max_val,int point,int hBitmap);
undefined4 Glue_Subsystem_004d109a(int max_val,int point,int hBitmap);
bool Palette_Subsystem_004a9137(int max_val,int point,int hBitmap);
undefined4 FUN_004535af(int max_val,int point,int hBitmap);
void Glue_Subsystem_004d212c(int max_val,int point,int hBitmap);
undefined4 Glue_Subsystem_004d2610(int spell_id,int target_id,int flags);
undefined4 Glue_Subsystem_004d29da(int spell_id,int target_id,int flags);
undefined4 Glue_Subsystem_004d2c17(int max_val,int point,int hBitmap);
undefined4 FUN_004544c7(int player,int card_slot);
undefined4 FUN_004545c9(int player,int card_slot);
undefined4 FUN_0045470b(int player,int card_slot);
undefined4 FUN_0045484d(int max_val,int point,int hBitmap);
undefined4 FUN_004548e3(int max_val,int point,int hBitmap);
undefined4 FUN_00454948(int max_val,int point,int hBitmap);
undefined4 FUN_004549c8(int max_val,int point,int hBitmap);
undefined4 FUN_00454a2b(int max_val,int point,int hBitmap);
undefined4 FUN_00454ac9(int max_val,int point,int hBitmap);
undefined4 FUN_00454cdc(int max_val,int point,int hBitmap);
undefined4 FUN_00454eec(int max_val,int point,int hBitmap);
undefined4 FUN_004550fc(int max_val,int point,int hBitmap);
undefined4 FUN_004554bc(int max_val,int point,int hBitmap);
undefined4 FUN_00455521(int max_val,int point,int hBitmap);
undefined4 FUN_0045559e(int max_val,int point,int hBitmap);
undefined4 FUN_00455740(int max_val,int point,int hBitmap);
undefined4 FUN_00455838(int max_val,int point,int hBitmap);
undefined4 Glue_Subsystem_004d420e(int spell_id,int target_id,int flags);
undefined4 Glue_Subsystem_004d4762(int spell_id,int target_id,int flags);
undefined4 FUN_004564bd(int max_val,int point,int hBitmap);
undefined4 FUN_00456711(int max_val,int point,int hBitmap);
undefined4 FUN_00456dc4(int max_val,int point,int hBitmap);
int FUN_004573bc(int max_val,int point,int hBitmap);
undefined4 FUN_00457b2f(int player,int card_slot);
undefined4 FUN_00457b9e(int max_val,int point,int hBitmap);
undefined4 FUN_00457ea3(int max_val,int point,int hBitmap);
undefined4 FUN_00457fdc(int max_val,int point,int hBitmap);
undefined4 FUN_00458271(int max_val,int point,int hBitmap);
undefined4 FUN_004583e0(int max_val,int point,int hBitmap);
undefined4 FUN_0045851f(int max_val,int point,int hBitmap);
undefined4 FUN_00458616(int max_val,int point,int hBitmap);
undefined4 Glue_Subsystem_004d7065(int spell_id,int target_id,int flags);
undefined4 FUN_00458ec1(int max_val,int point,int hBitmap);
undefined4 FUN_00458f18(int max_val,int point,int hBitmap);
undefined4 FUN_0045902a(undefined4 max_val,undefined4 point,int hBitmap);
undefined4 FUN_0045906f(int max_val,int point,int hBitmap);
undefined4 FUN_00459143(int max_val,int point,int hBitmap);
undefined4 Glue_Subsystem_004d7a1b(int max_val,int point,int hBitmap);
undefined4 FUN_00459305(int max_val,int point,int hBitmap);
undefined4 Glue_Subsystem_004d7bb5(int max_val,int point,int hBitmap);
undefined4 FUN_004593fd(int max_val,int point,int hBitmap,int flags,int damage);
undefined4 FUN_0045962d(int player,int card_slot);
undefined4 FUN_00459870(int max_val,int point,int hBitmap);
undefined4 FUN_00459918(int max_val,int point,int hBitmap);
undefined4 FUN_00459f68(int max_val,int point,int hBitmap);
undefined4 FUN_0045a5e9(int max_val,int point,int hBitmap);
undefined4 FUN_0045ac7e(int max_val,int point,int hBitmap);
void Glue_Subsystem_004d9afd(int max_val,int point,int hBitmap);
undefined4 Glue_Subsystem_004d9f7e(int spell_id,int target_id,int flags);
undefined4 Glue_Subsystem_004da482(int spell_id,int target_id,int flags);
undefined4 Glue_Subsystem_004da858(int spell_id,int target_id,int flags);
undefined4 Glue_Subsystem_004daa50(int spell_id,int target_id,int flags);
undefined4 Glue_Subsystem_004dac11(int spell_id,int target_id,int flags);
undefined4 FUN_0045c613(int x,int y,int width,uint height);
undefined4 Glue_Subsystem_004db024(int spell_id,int target_id,int flags);
bool FUN_0045cb9e(int max_val,int point,int hBitmap);
undefined4 FUN_0045d064(int max_val,int point,int hBitmap);
undefined4 Glue_Subsystem_004dba1c(int spell_id,int target_id,int flags);
void FUN_0045d774(int max_val,int point,int hBitmap);
undefined4 Glue_Subsystem_004dc2ca(int spell_id,int target_id,int flags);
undefined4 Glue_Subsystem_004dc6c7(int spell_id,int target_id,int flags);
undefined4 Glue_Subsystem_004dc9ed(int spell_id,int target_id,int flags);
undefined4 Glue_Subsystem_004dce51(int spell_id,int target_id,int flags);
undefined4 FUN_0045ead4(int max_val,int point,int hBitmap);
undefined1 Glue_Subsystem_004dd632(int spell_id,int target_id,int flags);
undefined4 FUN_0045f127(int max_val,int point,int hBitmap);
undefined4 FUN_0045f48c(int max_val,int point,int hBitmap);
undefined4 FUN_0045f5e4(int max_val,int point,int hBitmap);
undefined4 FUN_0045f68c(int player,int card_slot);
undefined4 FUN_0045f6dd(int max_val,int point,int hBitmap);
undefined4 FUN_0045f72a(int max_val,int point,int hBitmap);
undefined4 FUN_0045f7f1(int max_val,int point,int hBitmap);
undefined4 FUN_0045f845(int max_val,int point,int hBitmap);
undefined4 FUN_0045f892(int max_val,int point,int hBitmap);
undefined4 Glue_Subsystem_004de1c0(int max_val,int point,int hBitmap);
undefined4 FUN_0045faf0(int max_val,int point,int hBitmap);
undefined4 FUN_0045fc24(int max_val,int point,int hBitmap);
undefined4 FUN_0045ffcf(int max_val,int point,int hBitmap);
undefined4 Glue_Subsystem_004dec09(int spell_id,int target_id,int flags);
undefined4 Glue_Subsystem_004dee6b(int max_val,int point,int hBitmap);
undefined4 FUN_0046074f(int max_val,int point,int hBitmap);
undefined4 Glue_Subsystem_004df04a(int spell_id,int target_id,int flags);
bool FUN_00460999(int max_val,int point,int hBitmap);
undefined4 Glue_Subsystem_004df314(int spell_id,int target_id,int flags);
bool Glue_Subsystem_004df678(int spell_id,int target_id,int flags);
bool FUN_00461047(int player,int card_slot);
undefined4 FUN_004612b0(int x,int y,int width,int flags);
bool Glue_Subsystem_004dfd39(int spell_id,int target_id,int flags);
undefined4 FUN_00461621(int max_val,int point,int hBitmap);
undefined4 FUN_00461715(int max_val,int point,int hBitmap);
undefined4 FUN_004617c4(int max_val,int point,int hBitmap);
undefined4 Glue_Subsystem_004e00e7(int max_val,int point,int hBitmap);
undefined4 FUN_00461b42(int max_val,int point,int hBitmap);
undefined4 FUN_00461c4b(int max_val,int point,int hBitmap);
uint FUN_00461d0d(int max_val,int point,int hBitmap);
undefined4 FUN_00461f42(int max_val,int point,int hBitmap);
undefined4 FUN_00462039(int max_val,int point,int hBitmap);
undefined4 FUN_004620e8(int max_val,int point,int hBitmap);
bool Glue_Subsystem_004e0ab7(int spell_id,int target_id,int flags);
bool Glue_Subsystem_004e0c1c(int spell_id,int target_id,int flags);
undefined4 FUN_004625ed(int max_val,int point,int hBitmap);
undefined4 FUN_0046275d(int max_val,int point,int hBitmap);
undefined4 FUN_004628db(int max_val,int point,int hBitmap);
undefined4 FUN_00462a5c(int max_val,int point,int hBitmap);
undefined4 FUN_004630aa(int max_val,int point,int hBitmap);
undefined4 FUN_004631b8(int max_val,int point,int hBitmap);
undefined4 Glue_Subsystem_004e1b38(int max_val,int point,int hBitmap);
undefined4 FUN_00463419(int max_val,int point,int hBitmap);
undefined4 FUN_00463523(int max_val,int point,int hBitmap);
undefined4 FUN_004635f8(int max_val,int point,int hBitmap);
undefined4 FUN_00463699(int player,int card_slot);
undefined4 Glue_Subsystem_004e1fcb(int max_val,int point,int hBitmap);
bool FUN_0046388d(int max_val,int point,int hBitmap);
bool Glue_Subsystem_004e22b2(int spell_id,int target_id,int flags);
undefined4 Glue_Subsystem_004e268e(int max_val,int point,int hBitmap);
undefined4 Glue_Subsystem_004e2841(int spell_id,int target_id,int flags);
int FUN_00464325(int player,int card_slot);
undefined4 Glue_Subsystem_004e2c7f(int max_val,int point,int hBitmap);
undefined4 FUN_00464774(int max_val,int point,int hBitmap);
undefined4 FUN_004648af(int max_val,int point,int hBitmap);
undefined4 FUN_0046490c(int max_val,int point,int hBitmap);
undefined4 Glue_Subsystem_004e32f3(int max_val,int point,int hBitmap);
undefined4 FUN_00464c69(int max_val,int point,int hBitmap);
undefined4 FUN_00464ce8(int max_val,int point,int hBitmap);
void FUN_00464d69(int max_val,int point,int hBitmap);
undefined4 FUN_00464eb5(int max_val,int point,int hBitmap);
undefined4 Glue_Subsystem_004e378b(int max_val,int point,int hBitmap);
undefined4 Glue_Subsystem_004e3b55(int spell_id,int target_id,int flags);
undefined4 Glue_Subsystem_004e3e46(int spell_id,int target_id,int flags);
uint FUN_004658c8(int max_val,int point,int hBitmap);
undefined4 FUN_00465a30(int max_val,int point,int hBitmap);
void Pic_Load_0042a1c9(int max_val,int point,int hBitmap);
void FUN_00465ed2(int max_val,int point,int hBitmap);
undefined4 Glue_Subsystem_004e4807(int spell_id,int target_id,int flags);
undefined4 FUN_00466732(int max_val,int point,int hBitmap);
undefined4 FUN_00466b12(int max_val,int point,int hBitmap);
undefined4 FUN_00466d59(int max_val,int point,int hBitmap);
bool FUN_00466f91(int max_val,int point,int hBitmap);
undefined4 FUN_004670b0(int max_val,int point,int hBitmap);
undefined4 FUN_004671bd(int max_val,int point,int hBitmap);
undefined4 Glue_Subsystem_004e5e3b(int spell_id,int target_id,int flags);
undefined4 Glue_Subsystem_004e61a6(int spell_id,int target_id,int flags);
undefined4 FUN_00467cce(int player,byte card_slot);
void FUN_00467d65(undefined *player,int card_slot);
void FUN_00467e37(int player,int card_slot);
void FUN_00467eef(int player,int card_slot);
void FUN_00467f65(int max_val,int point,int hBitmap);
void FUN_0046801f(int max_val,int point,int hBitmap);
void FUN_00468097(int max_val,int point,int hBitmap);
uint FUN_004680fc(int player,int card_slot);
bool Mana_CanAffordCost(int max_val, uint point, int hBitmap);
bool FUN_00468261(int max_val,uint point,int hBitmap);
int FUN_00468383(int max_val);
bool FUN_00468550(int max_val,uint point,int hBitmap);
bool FUN_00468681(int max_val,uint point,int hBitmap);
undefined4 FUN_004687a3(int max_val);
bool FUN_00468831(int max_val,uint point,int hBitmap);
bool FUN_00468962(int max_val,uint point,int hBitmap);
undefined4 FUN_00468a84(int max_val);
int FUN_00468b20(int max_val,int point,int hBitmap);
int FUN_00468cb8(int max_val);
undefined4 Palette_Subsystem_004a6fef(int spell_id,int target_id,int flags);
int FUN_004693bd(int max_val);
int FUN_00469450(int player,int card_slot);
int FUN_0046951b(int max_val,int point,undefined4 hBitmap);
undefined4 FUN_00469614(int max_val,int point,int hBitmap);
int FUN_00469825(int max_val,int point,int hBitmap);
int FUN_004699cd(int max_val,int point,int hBitmap);
int FUN_00469b05(int player,int card_slot);
undefined4 FUN_00469c3c(int max_val,int point,int hBitmap);
undefined4 FUN_00469d2a(int max_val,int point,int hBitmap);
undefined4 Palette_Subsystem_004a8111(int max_val,int point,int hBitmap);
undefined4 Palette_Subsystem_004a8d46(int max_val,int point,int hBitmap);
int FUN_0046add8(int x,int y,int width,uint height);
undefined4 Palette_Subsystem_004a9137(int max_val,int point,undefined4 hBitmap);
uint Pic_Subsystem_004458b0(int player,uint *card_slot);
uint Ai_ChooseChainResponse(int max_val);
undefined4 FUN_0046cc45(int player,int card_slot);
undefined4 FUN_0046d140(void);
void Pic_Subsystem_004475a4(void);
void FUN_0046d90d(void);
int FUN_0046da4a(int player,int card_slot);
undefined4 FUN_0046e4c9(int x,int y,int width,undefined4 flags);
void Duel_DrawCardSprite(int max_val,int point,int hBitmap);
undefined4 Pic_Subsystem_004488a0(void);
undefined4 Pic_Subsystem_0044895f(int player,int card_slot);
void FUN_0046ed1c(int player,int card_slot);
void FUN_0046f02d(int player,int card_slot);
void FUN_0046f116(int player,int card_slot);
void FUN_0046f18f(int player,int card_slot);
byte UI_CreateWindow_0046f240(LPCSTR str_1);
void FUN_0046f2f5(void);
uint UI_WndProc_0046f328(HWND hwnd,uint uMsg,uint *wParam,LONG *lParam);
int FUN_00470437(HWND hwnd,int card_slot);
int FUN_004704cd(HWND hwnd,int card_slot);
void FUN_00470560(HWND hwnd,LPRECT card_slot);
bool FUN_004706d0(void);
void FUN_0047072d(void);
void FUN_0047076e(char *str_1);
void GDI_RealizeAndFlushPalette(HDC hdc);
undefined4 FUN_004707f3(undefined4 max_val,int point,undefined4 *hBitmap,BITMAPINFO *flags,undefined4 *damage,undefined4 *arg_6,int *arg_7);
void FUN_0047097b(HDC hdc,HGDIOBJ card_slot);
undefined4 GDI_DrawBitmapToHDC(int max_val,int point,HANDLE hBitmap);
undefined4 FUN_00470a16(HDC hdc,int *point,HANDLE hBitmap,int flags,int damage,int arg_6,int arg_7);
undefined4 FUN_00470b60(HDC hdc,int *point,HANDLE hBitmap);
undefined4 FUN_00470c78(HDC max_val,int *point,HANDLE hBitmap);
undefined4 FUN_00470cfa(HDC hdc,int *point,HANDLE hBitmap,int flags,int damage,int arg_6,int arg_7,int arg_8,int arg_9);
undefined4 FUN_00470e75(undefined4 max_val,LPCSTR str_2,void *hBitmap,undefined4 flags);
undefined4 FUN_00470f35(LPCSTR str_1,void *point,undefined4 hBitmap);
HBITMAP FUN_00471035(BITMAPINFO *player,void *card_slot);
void GDI_DestroyDIBSection(HANDLE max_val);
undefined4 FUN_00471426(void);
void FUN_00471717(void);
void FUN_0047173d(int max_val,int point,RECT *hBitmap);
void FUN_004718de(char *str_1,char *str_2,int width,char *str_4);
int FUN_00471b26(char *str_1,char *str_2,int hBitmap);
int FUN_00471cf1(HWND hwnd,int card_slot);
LRESULT UI_WndProc_00471df6(HWND hwnd,UINT uMsg,WPARAM wParam,LPARAM lParam);
undefined4 FUN_00471e86(char *str_1,COLORREF point,HBRUSH hBitmap);
void FUN_00471f45(int max_val,HBRUSH point,HGDIOBJ hBitmap,HGDIOBJ flags,COLORREF damage,int arg_6);
void FUN_00472317(int max_val,HANDLE point,HANDLE hBitmap,HANDLE flags,COLORREF damage,int arg_6);
void FUN_00472552(HWND hwnd);
undefined4 FUN_0047256e(HWND hwnd);
LRESULT FUN_004725af(HWND hwnd,UINT y,HWND param_3,LPARAM flags);
bool FUN_004726e4(HWND hwnd);
undefined * FUN_00472731(uint *player,int card_slot);
void FUN_0047283d(void);
int FUN_004729bc(int player,int card_slot);
undefined4 FUN_00472a3f(HWND hwnd,int point,int hBitmap);
uint FUN_00472b02(int max_val);
undefined4 GDI_RealizePaletteTree(HWND hwnd,uint y,HWND param_3,undefined4 flags);
undefined4 FUN_00472d0a(HWND hwnd,int *card_slot);
uint FUN_00472d60(int max_val,int point,int hBitmap,int flags,int damage);
void FUN_00472ea0(int max_val,int point,int hBitmap,int flags,int damage,undefined4 arg_6);
void FUN_00472fc0(int max_val);
void FUN_00473a32(int max_val);
uint FUN_00474d83(int max_val);
void FUN_00476868(int max_val);
void FUN_004769a5(undefined4 player,int card_slot);
int FUN_00476b29(void);
void Ai_EvalAttackCandidate_004c864d(uint spell_id);
undefined4 FUN_00478cfa(int player,uint card_slot);
undefined4 FUN_00478d48(int max_val);
void FUN_00478e3b(void);
void FUN_00478e99(int max_val,int point,int hBitmap,int flags,int damage,int arg_6,int *arg_7,int *arg_8);
void FUN_004794d4(int max_val,int point,int hBitmap,int flags,int damage,int arg_6,int *arg_7,int *arg_8);
void FUN_00479952(void);
void FUN_00479b25(int max_val,int point,int hBitmap);
void FUN_00479b85(int max_val,int point,int hBitmap);
void FUN_00479be5(WPARAM max_val);
int FUN_00479c07(int player,int card_slot);
int FUN_00479e13(int player,int card_slot);
undefined4 FUN_00479f9f(int player,int card_slot);
undefined4 Sound_PlaySpatialSound(int x, int y, int width, int height);
void Mem_AllocOrFree_0047a283(int max_val,int point,int hBitmap);
void Mem_AllocOrFree_0047a2a9(int max_val,int point,int hBitmap);
void Mem_AllocOrFree_0047a2cf(int max_val,int point,int hBitmap);
void Mem_AllocOrFree_0047a2f5(int max_val,int point,int hBitmap);
void Mem_AllocOrFree_0047a31b(int max_val,int point,int hBitmap);
void Mana_Init_00452b71(int max_val,int point,int hBitmap,int flags,int damage);
undefined4 Mem_AllocOrFree_0047a651(int max_val,int point,int hBitmap);
undefined4 Mem_AllocOrFree_0047a67b(int max_val,int point,int hBitmap);
undefined4 Mem_AllocOrFree_0047a6a5(int max_val,int point,int hBitmap);
undefined4 Mem_AllocOrFree_0047a6cf(int max_val,int point,int hBitmap);
undefined4 Mem_AllocOrFree_0047a6f9(int max_val,int point,int hBitmap);
undefined4 Mem_AllocOrFree_0047a723(int max_val,int point,int hBitmap);
undefined4 Mem_AllocOrFree_0047a74d(int max_val,int point,int hBitmap);
undefined4 Mem_AllocOrFree_0047a777(int max_val,int point,int hBitmap);
undefined4 Mem_AllocOrFree_0047a7a1(int max_val,int point,int hBitmap);
undefined4 Mem_AllocOrFree_0047a7cb(int max_val,int point,int hBitmap);
undefined4 FUN_0047a7f5(int max_val,int point,int hBitmap);
undefined4 Mana_Init_004532f1(int max_val,int point,int hBitmap);
undefined4 Ai_Subsystem_004b8e4d(int max_val,int point,int hBitmap);
undefined4 Minit_Subsystem_004537b0(int spell_id,int target_id,int flags);
undefined4 Minit_Subsystem_00453c60(int max_val,int point,int hBitmap);
undefined4 Mana_Init_00453fdb(int spell_id,int target_id,int flags);
undefined4 FUN_0047bba3(int max_val,int point,int hBitmap);
undefined4 FUN_0047bd97(int max_val,int point,int hBitmap);
undefined4 Mana_Init_00453fdb(int max_val,int point,int hBitmap);
undefined4 Mana_Init_00453fdb(int spell_id,int target_id,int flags);
undefined4 Mana_Init_004555c8(int spell_id,int target_id,int flags);
undefined4 FUN_0047d928(int max_val,int point,int hBitmap);
undefined4 FUN_0047d9e8(int max_val,int point,int hBitmap);
undefined4 FUN_0047dbca(int max_val,int point,int hBitmap);
undefined4 FUN_0047dd22(undefined4 max_val,undefined4 point,int hBitmap);
undefined4 FUN_0047dda7(int max_val,int point,int hBitmap);
undefined4 Minit_Subsystem_0045672f(int spell_id,int target_id,int flags);
int * Glue_Subsystem_004f15c0(int max_val,char *str_2,int hBitmap);
undefined4 FUN_0047e7a5(void);
void * Haar_DecompressWaveletImage(int *player,void *card_slot);
void FUN_0047ec25(int max_val,int point,int hBitmap,int flags,int damage,int arg_6,int arg_7);
void FUN_0047ec8c(int *max_val,int *point,int *hBitmap,int flags,int damage,undefined4 arg_6,int arg_7);
void FUN_0047ee28(undefined8 *max_val,undefined8 *point,uint hBitmap);
void FUN_0047ee63(undefined8 *max_val,uint point,uint hBitmap);
void FUN_0047eecc(int max_val,int point,int hBitmap);
void FUN_0047f011(int *max_val,int *point,int *hBitmap,int flags,int damage,undefined4 arg_6,int arg_7);
void FUN_0047f0e6(int *max_val,int *point,int *hBitmap,int flags,int damage,undefined4 arg_6,int arg_7);
undefined2 Mem_AllocOrFree_0047f1c1(uint player,uint card_slot);
undefined1 *FUN_0047f1e7(undefined1 *max_val,int *point,int hBitmap,int flags,int damage,int arg_6,int arg_7,undefined4 arg_8,int arg_9);
undefined4 FUN_0047f4b0(int player,int *card_slot);
bool FUN_0047f6e7(HWND hwnd);
int FUN_0047f750(HWND hwnd,void *point,int hBitmap,int flags,DWORD damage,DWORD arg_6);
undefined4 * FUN_0047f7d3(undefined4 max_val,int point,int hBitmap);
undefined4 Mem_AllocOrFree_0047f8f7(undefined4 max_val);
undefined4 * FUN_0047f918(undefined4 *max_val,int *y,int width,int height);
bool FUN_0047fc0d(HWND hwnd,int *y,DWORD hBitmap,DWORD flags);
uint * FUN_0047fc77(uint *x,int *y,int width,int height);
undefined4 FUN_0048039e(HWND hwnd,int *y,DWORD hBitmap,DWORD flags);
undefined4 * FUN_0048045f(int max_val);
void FUN_004804b1(int max_val);
int FUN_004804eb(HWND hwnd,int point,int hBitmap,int flags,DWORD damage,DWORD arg_6);
void FUN_00480690(HWND hwnd);
HBRUSH UI_DialogProc_00480806(HWND hwnd,uint uMsg,HDC wParam,HWND lParam);
void Pic_Load_s_WINBK_Options_00480fdc(undefined4 *max_val,undefined4 *out_buffer,undefined4 *hBitmap,int *flags,int *damage,int *arg_6,undefined4 *arg_7,undefined4 *arg_8);
void FUN_004810c1(HANDLE max_val,HGDIOBJ point,HGDIOBJ hBitmap,HGDIOBJ flags);
void Rules_ParseFilter_0048111e(void);
void Rules_ParseFilter_00481890(void);
void FUN_00481c8e(void);
void FUN_00481f02(void);
bool Minit_Subsystem_00467880(LPCSTR str_1);
void FUN_004821cf(void);
LRESULT Card_Setup_00467a68(HWND hwnd,uint uMsg,HWND wParam,int *lParam);
void FUN_004852b1(HWND hwnd);
undefined4 FUN_00485361(HWND hwnd);
int FUN_00485587(HWND hwnd);
bool FUN_004855f9(int player,int card_slot);
uint Palette_Subsystem_0049c7c7(int player,int card_slot);
bool FUN_00485c20(int player,int card_slot);
bool FUN_00485c56(int player,int card_slot);
void Mem_AllocOrFree_00485cf5(int player,int card_slot);
void FUN_00485d15(char *str_1,int point,undefined4 hBitmap);
void FUN_004860aa(char *str_1,int point,int hBitmap);
void Mem_AllocOrFree_0048614b(void);
void FUN_00486239(HDC hdc,int y,undefined4 hBitmap,undefined4 flags);
undefined4 FUN_00486348(HWND hwnd,int *card_slot);
undefined4 FUN_004863ca(HWND hwnd,int card_slot);
undefined4 FUN_0048644e(HWND hwnd);
LONG FUN_004864b1(HWND hwnd);
int FUN_004864e0(WPARAM max_val,int y,int width,int height);
undefined * FUN_004867ca(int player,int card_slot);
int FUN_00486861(int x,int y,int width,int height);
int FUN_004868d1(HDC hdc,RECT *point,int width,int height);
undefined4 FUN_004869bd(WPARAM max_val,int y,int width,int height);
void FUN_00486a4e(int player,int card_slot);
void FUN_00486bc3(void);
int FUN_00486c12(int max_val,int point,int hBitmap);
bool UI_CreateWindow_00486c90(LPCSTR str_1);
void FUN_00486dc6(void);
LRESULT Ai_CalcManaRequirement_004b9284(HWND hwnd,uint y,HWND param_3,uint height);
void Mem_AllocOrFree_00487924(int max_val);
LRESULT UI_WndProc_0048794d(HWND hwnd,uint uMsg,HDC wParam,LPARAM lParam);
void FUN_00487a10(void);
int Magic_ExecuteDrawPhase(int max_val);
void Palette_Color_0049ae00(int spell_id,int target_id,int flags);
undefined4 FUN_00488598(int player,int card_slot);
undefined4 FUN_00488662(int max_val,int point,int hBitmap);
undefined4 Ai_ChooseBlockers(int player,int card_slot);
bool FUN_004895b4(int max_val,int point,int hBitmap);
bool FUN_0048974c(int player,int card_slot);
undefined4 FUN_0048a07d(int player,int card_slot);
undefined4 FUN_0048a1c7(int max_val,int point,int hBitmap);
bool FUN_0048a2cd(int player,int card_slot);
bool Duel_CardIsTapped(int player,int card_slot);
undefined4 FUN_0048a3b1(int player,int card_slot);
void Card_Setup_00467a68(uint max_val);
undefined4 FUN_0048acd3(int max_val);
undefined4 FUN_0048ad82(int player,int card_slot);
bool FUN_0048af80(int player,int card_slot);
undefined4 FUN_0048afc2(int max_val);
undefined4 FUN_0048b0c7(int max_val);
undefined4 FUN_0048b24e(int x,int point,int hBitmap,int flags);
bool FUN_0048b2c9(int max_val,int point,undefined4 hBitmap,undefined4 flags,uint damage,uint arg_6);
int FUN_0048b4c5(int x,int y,undefined4 hBitmap,undefined4 flags);
void FUN_0048b5c9(undefined4 player,int card_slot);
void FUN_0048b64f(void);
uint Duel_QueryCardAttribute(int player, int slot, int event_code, undefined4 target_slot);
undefined4 Duel_ColorMaskToIndex(byte max_val);
undefined * Mem_AllocOrFree_0048c420(int max_val);
int FUN_0048c43a(int max_val);
undefined4 FUN_0048c50b(int max_val,undefined4 point,int hBitmap);
void Magic_ScanCards(int max_val);
int Duel_PlayCardSoundEffect(int max_val,int point,int hBitmap,undefined4 flags,undefined4 damage);
bool Magic_IsManaSource(int player,int slot);
void FUN_0048cac9(void);
void FUN_0048cb7f(void);
void FUN_0048cc29(void);
void FUN_0048cfda(int player,int card_slot);
undefined4 Sound_PlayTrackById(int max_val);
void Duel_PreloadSoundEffects(void);
void FUN_0048d3af(void);
undefined4 Magic_ClearSpellStack(void);
undefined4 FUN_0048d3eb(void);
undefined4 FUN_0048d41e(undefined4 max_val);
undefined4 Magic_PushSpellStack(int player,int slot,int event_code,int target_slot,undefined4 flags);
undefined4 FUN_0048dc9e(void);
undefined4 FUN_0048dd43(void);
undefined4 FUN_0048e251(void);
void Mem_AllocOrFree_0048e302(void);
undefined4 FUN_0048e32b(int x,int point,undefined4 hBitmap,undefined4 flags);
int FUN_0048e405(int x,int y,uint *hBitmap,undefined4 flags);
undefined4 FUN_0048e8a8(int x,undefined4 point,undefined4 hBitmap,int flags);
undefined4 Magic_RunTurnStep(int player,undefined4 step_code,char *step_name,int repeat_while_active);
undefined4 FUN_0048eae1(void);
int FUN_0048eb25(int player,int card_slot);
void FUN_0048ebb3(void);
undefined4 FUN_0048ed18(int player,int card_slot);
void FUN_0048ee91(int max_val);
undefined4 FUN_0048f067(int player,int card_slot);
void FUN_0048f123(void);
void FUN_0048f1b1(void);
uint FUN_0048f31a(int x,int y,int width,int height);
undefined4 Palette_Subsystem_0049608e(HWND hwnd,uint y,HDC hdc,uint height);
bool UI_CreateWindow_00490196(LPCSTR str_1);
void Mem_AllocOrFree_00490228(void);
LRESULT UI_WndProc_00490233(HWND hwnd,uint uMsg,WPARAM wParam,uint lParam);
undefined4 UI_Register_WINBK_BigCard_0049036d(LPCSTR str_1);
void Mem_AllocOrFree_00490448(void);
LRESULT UI_WndProc_00490478(HWND hwnd,uint uMsg,HWND wParam,LONG *lParam);
bool FUN_00491688(HWND hwnd,int card_slot);
void FUN_00491750(undefined4 *max_val,undefined4 point,int hBitmap);
bool UI_CreateWindow_004917d0(LPCSTR str_1);
void FUN_004918f1(void);
LRESULT UI_WndProc_0049198a(HWND hwnd,uint uMsg,HWND wParam,LPSTR lParam);
undefined4 FUN_00491ef3(int *max_val);
void Pic_Subsystem_00452551(void);
void Csv_LoadMaster_00492693(void);
void Csv_ReadConcise_004927ce(void);
void Csv_ReadConcise_00492872(void);
void Csv_LoadMaster_00492951(undefined1 *max_val,int y,int width,char *str_4);
undefined4 Mem_AllocOrFree_00492b05(void);
void FUN_00492b17(char *str_1,int card_slot);
bool FUN_00492b90(char *str_1);
int Deck_FilterAttributes_00492bd9(char *filter_string,int color_mask,uint width,int height);
void Tale_Load_004930ea(int max_val);
void Hints_Load_004931aa(void);
void Hints_Load_004933ec(int max_val);
int FUN_00493466(int max_val);
undefined4 FUN_00493714(int max_val);
char * FUN_0049377b(char *str_1);
undefined4 UI_Register_WINBK_Attack_00493810(LPCSTR str_1);
void FUN_00493c0c(void);
uint SpellChain_WndProc(HWND hwnd,uint y,HWND param_3,HWND param_4);
undefined4 FUN_00497849(int max_val,int point,int hBitmap);
void FUN_0049793e(HWND hwnd);
void FUN_004983d1(HWND hwnd,LPRECT card_slot);
bool FUN_00498613(int player,int card_slot);
uint UI_WndProc_0049866e(HWND hwnd,uint uMsg,HWND wParam,int lParam);
void FUN_00499128(HWND hwnd);
LRESULT SpellChain_MinimizedWndProc(HWND hwnd,uint uMsg,HDC wParam,uint lParam);
int FUN_004994f8(HWND hwnd,int *point,undefined4 *hBitmap,undefined4 *flags,undefined4 *damage);
int FUN_004997a8(HWND hwnd,int card_slot);
void Assert_Handler_00499950(int x,int y,int width,char *str_4);
void Assert_Handler_00499a78(int x,int y,int width,char *str_4);
undefined4 UI_Register_sPoison_00499ba0(LPCSTR str_1);
void FUN_00499c93(void);
LRESULT Ai_CalcManaRequirement_004b9284(HWND hwnd,uint uMsg,HWND wParam,uint lParam);
void FUN_0049a93a(undefined4 max_val);
undefined4 FUN_0049a979(int max_val);
undefined4 FUN_0049a9d0(void);
int FUN_0049aa14(int max_val,int point,int hBitmap);
void FUN_0049aa4b(void);
int FUN_0049aa7e(int player,int card_slot);
void Mem_AllocOrFree_0049aaf0(void);
void Mem_AllocOrFree_0049aafb(void);
undefined4 Mem_AllocOrFree_0049ab06(void);
void FUN_0049ab18(void *max_val,void *point,size_t hBitmap);
void FUN_0049ab40(void *max_val,void *point,size_t hBitmap);
undefined4 Mem_AllocOrFree_0049ab68(void);
undefined4 FUN_0049ab7a(void);
void Pic_Subsystem_0044eca0(void);
void Pic_Subsystem_0044edf5(undefined4 max_val);
void Pic_Subsystem_0044edf5(LPCSTR str_1);
undefined4 FUN_0049aed0(int max_val,int point,int hBitmap);
undefined4 FUN_0049af12(int max_val,int point,int hBitmap);
void FUN_0049af5c(int max_val,uint point,int hBitmap);
void FUN_0049b00c(int max_val,uint point,int hBitmap);
void FUN_0049b0eb(int max_val,uint point,int hBitmap);
undefined4 FUN_0049b1a9(int max_val,int point,int hBitmap);
undefined4 FUN_0049b1eb(int max_val,int point,int hBitmap);
undefined4 FUN_0049b235(int max_val,int point,int hBitmap);
undefined4 FUN_0049b277(int max_val,int point,int hBitmap);
undefined4 FUN_0049b2c1(int max_val,int point,int hBitmap);
int Duel_DrawString(int max_val, uint point, int hBitmap);
int FUN_0049b68d(int x,int y,uint width,int height);
undefined4 Palette_Subsystem_00495958(undefined4 max_val,undefined4 point,char *str_3);
int Pic_Load_004420a1(HWND hwnd,int card_slot);
undefined4 FUN_0049c211(void);
INT_PTR FUN_0049c24f(HWND hwnd);
HBRUSH UI_DialogProc_0049c2d0(HWND hwnd,uint uMsg,HDC wParam,HWND lParam);
void Pic_Load_s_GAUN_Startup_0049cff7(undefined4 *max_val,undefined4 *out_buffer,undefined4 *hBitmap,int *flags,int *damage,int *arg_6,undefined4 *arg_7,undefined4 *arg_8);
void FUN_0049d0dc(HANDLE max_val,HGDIOBJ point,HGDIOBJ hBitmap,HGDIOBJ flags);
void FUN_0049d139(uint *player,int card_slot);
LRESULT Palette_Subsystem_00496497(HWND hwnd);
undefined4 Deck_FilterAttributes_0049d3c0(char *filter_string);
undefined4 FUN_0049e5d3(int max_val,int point,int hBitmap);
WPARAM FUN_0049e65c(HWND hwnd,char *str_2);
void FUN_0049e6f9(void);
void FUN_0049e807(HWND hwnd,int card_slot);
void FUN_0049e921(HWND hwnd,int card_slot);
HBRUSH UI_DialogProc_0049eaa0(HWND hwnd,uint uMsg,HDC wParam,HWND lParam);
void Pic_Load_s_GAUN_Options_0049f242(undefined4 *max_val,undefined4 *out_buffer,undefined4 *hBitmap,int *flags,int *damage,int *arg_6,undefined4 *arg_7,undefined4 *arg_8);
void FUN_0049f327(HANDLE max_val,HGDIOBJ point,HGDIOBJ hBitmap,HGDIOBJ flags);
void FUN_0049f384(HWND hwnd);
bool FUN_0049f4d8(char *str_1,undefined4 card_slot);
void Mem_AllocOrFree_0049f52a(undefined4 max_val);
void Mem_AllocOrFree_0049f553(void);
void Mem_AllocOrFree_0049f568(void);
void Mem_AllocOrFree_0049f57d(void);
undefined4 Mem_AllocOrFree_0049f588(void);
void Mem_AllocOrFree_0049f59a(void);
void Mem_AllocOrFree_0049f5a5(void);
void Mem_AllocOrFree_0049f5b0(void);
void Mem_AllocOrFree_0049f5bb(void);
undefined4 Mem_AllocOrFree_0049f5c6(void);
void Mem_AllocOrFree_0049f5d8(void);
void Mem_AllocOrFree_0049f5e3(void);
void Mem_AllocOrFree_0049f5ee(void);
void Mem_AllocOrFree_0049f5f9(void);
undefined4 Mem_AllocOrFree_0049f604(void);
undefined4 Mem_AllocOrFree_0049f616(void);
void Mem_AllocOrFree_0049f628(void);
void FUN_0049f633(int max_val);
undefined4 Mem_AllocOrFree_0049f697(void);
void Mem_AllocOrFree_0049f6a9(void);
void Mem_AllocOrFree_0049f6b4(void);
void Mem_AllocOrFree_0049f6bf(void);
void Mem_AllocOrFree_0049f6ca(void);
undefined4 Mem_AllocOrFree_0049f6d5(void);
undefined4 Mem_AllocOrFree_0049f6e7(void);
void Mem_AllocOrFree_0049f6f9(void);
void Mem_AllocOrFree_0049f704(void);
void Mem_AllocOrFree_0049f70f(void);
void Mem_AllocOrFree_0049f71a(void);
undefined4 Mem_AllocOrFree_0049f725(void);
undefined4 Mem_AllocOrFree_0049f737(void);
void Mem_AllocOrFree_0049f749(void);
void Mem_AllocOrFree_0049f754(void);
undefined4 Mem_AllocOrFree_0049f75f(void);
undefined4 Mem_AllocOrFree_0049f771(void);
undefined4 Mem_AllocOrFree_0049f783(void);
void Mem_AllocOrFree_0049f795(void);
undefined4 Mem_AllocOrFree_0049f7a0(void);
undefined4 Mem_AllocOrFree_0049f7b2(void);
undefined4 Mem_AllocOrFree_0049f7c4(void);
undefined4 Mem_AllocOrFree_0049f7d9(void);
undefined2 Mem_AllocOrFree_0049f7ee(void);
undefined2 Mem_AllocOrFree_0049f801(void);
undefined4 SpellChain_RegisterClass(LPCSTR str_1);
void SpellChain_CleanupUI(void);
uint SpellChain_WndProc(HWND hwnd,uint y,HWND param_3,uint height);
int SpellChain_FindEntryIndex(HWND hwnd);
void SpellChain_RemoveEntry(HWND hwnd,int card_slot);
bool SpellChain_EntryTargetsMatch(void);
int Palette_Subsystem_0049608e(HWND hwnd,undefined4 point,undefined4 hBitmap);
void SpellChain_ClearEntryTargets(HWND hwnd,int card_slot);
int Palette_Subsystem_0049608e(HWND hwnd);
void SpellChain_UpdateLayout(HWND hwnd,LPRECT card_slot);
void SpellChain_GetContentRect(undefined4 player,LPRECT card_slot);
LRESULT SpellChain_MinimizedWndProc(HWND hwnd,uint uMsg,HDC wParam,uint lParam);
BOOL SpellChain_MinimizeIfShown(void);
bool SpellChain_RestoreIfMinimized(void);
int Duel_TriggerCardEvent(int max_val,int point,int hBitmap,int flags,int damage);
undefined4 FUN_004a2d31(int max_val,int point,int hBitmap);
undefined4 FUN_004a2f9f(int max_val,int point,int hBitmap);
undefined4 FUN_004a3041(int max_val,int point,int hBitmap);
undefined4 FUN_004a314e(int max_val,int point,int hBitmap);
undefined4 FUN_004a3593(int max_val,int point,int hBitmap);
undefined4 FUN_004a36e8(int max_val,int point,int hBitmap);
undefined4 FUN_004a3dd6(int max_val,int point,int hBitmap);
undefined4 FUN_004a3f89(int max_val,int point,int hBitmap);
undefined4 FUN_004a4084(int max_val,int point,int hBitmap);
undefined4 FUN_004a4251(int max_val,int point,int hBitmap);
undefined4 FUN_004a43c4(int max_val,int point,int hBitmap);
bool FUN_004a44c8(int max_val,int point,int hBitmap);
undefined4 FUN_004a467d(int max_val,int point,int hBitmap);
undefined4 FUN_004a4d51(int max_val,int point,int hBitmap);
undefined4 FUN_004a53ac(int max_val,int point,int hBitmap);
undefined4 FUN_004a56a5(int max_val,int point,int hBitmap);
undefined4 FUN_004a586e(int max_val,int point,int hBitmap);
undefined4 FUN_004a59e6(int max_val,int point,int hBitmap);
undefined4 FUN_004a5b3d(int player,int card_slot);
undefined4 FUN_004a5bc8(int max_val,int point,int hBitmap);
undefined4 FUN_004a5def(int max_val,int point,int hBitmap);
undefined4 FUN_004a60aa(int max_val,int point,int hBitmap);
undefined4 FUN_004a63d8(int max_val,int point,int hBitmap);
undefined4 FUN_004a65df(int max_val,int point,int hBitmap);
undefined4 FUN_004a66b0(int max_val,int point,int hBitmap);
undefined4 FUN_004a6782(int max_val,undefined4 point,int hBitmap);
undefined4 FUN_004a68fc(int max_val,int point,int hBitmap);
undefined4 Palette_Color_0049ae00(int spell_id,int target_id,int flags);
undefined4 FUN_004a6d94(int max_val,int point,int hBitmap);
undefined4 FUN_004a6ebb(int max_val,int point,int hBitmap);
undefined4 Palette_Color_0049ae00(int spell_id,int target_id,int flags);
undefined4 Palette_Color_0049ae00(int spell_id,int target_id,int flags);
undefined4 Palette_Color_0049ae00(int spell_id,int target_id,int flags);
undefined4 Palette_Color_0049ae00(int spell_id,int target_id,int flags);
undefined4 Palette_Color_0049ae00(int spell_id,int target_id,int flags);
undefined4 FUN_004a7b83(int player,int card_slot);
undefined4 Palette_Color_0049ae00(int spell_id,int target_id,int flags);
undefined4 FUN_004a7e94(int max_val,int point,int hBitmap);
undefined4 FUN_004a7f64(int max_val,int point,int hBitmap);
undefined4 Palette_Color_0049ae00(int spell_id,int target_id,int flags);
undefined4 Palette_Color_0049ae00(int spell_id,int target_id,int flags);
undefined4 Palette_Color_0049ae00(int spell_id,int target_id,int flags);
undefined4 Palette_Color_0049ae00(int spell_id,int target_id,int flags);
undefined4 FUN_004a8b15(int max_val,int point,int hBitmap);
undefined4 Palette_Color_0049ae00(int spell_id,int target_id,int flags);
undefined4 Palette_Color_0049ae00(int spell_id,int target_id,int flags);
undefined4 Palette_Color_0049ae00(int spell_id,int target_id,int flags);
undefined4 Palette_Color_0049ae00(int spell_id,int target_id,int flags);
undefined4 FUN_004a9754(int max_val,int point,int hBitmap);
undefined4 FUN_004a97df(int max_val,int point,int hBitmap);
undefined4 FUN_004a9892(int player,int card_slot);
undefined4 FUN_004a9944(int max_val,int point,int hBitmap);
undefined4 FUN_004a99f4(int player,int card_slot);
undefined4 FUN_004a9ad1(int max_val,int point,int hBitmap);
undefined4 Palette_Color_0049ae00(int spell_id,int target_id,int flags);
undefined4 Palette_Color_0049ae00(int spell_id,int target_id,int flags);
undefined4 Palette_Color_0049ae00(int spell_id,int target_id,int flags);
undefined4 Palette_Color_0049ae00(int spell_id,int target_id,int flags);
bool FUN_004aa4e6(int max_val,int point,int hBitmap);
undefined4 FUN_004aa569(int player,int card_slot);
undefined4 Palette_Color_0049ae00(int spell_id,int target_id,int flags);
void FUN_004aaa93(int x,int y,int width,undefined1 flags);
undefined4 Palette_Color_0049ae00(int spell_id,int target_id,int flags);
void FUN_004ab2e3(int x,int y,int width,undefined1 flags);
undefined4 Palette_Color_0049ae00(int spell_id,int target_id,int flags);
undefined4 Palette_Color_0049ae00(int spell_id,int target_id,int flags);
uint FUN_004ac030(int max_val,int point,int hBitmap);
undefined4 FUN_004ac2b1(int max_val,int point,int hBitmap);
undefined4 FUN_004ac56d(int max_val,int point,int hBitmap);
undefined4 FUN_004acbac(int max_val,int point,int hBitmap);
undefined4 Palette_Color_0049ae00(int spell_id,int target_id,int flags);
uint FUN_004ad480(int max_val,int point,int hBitmap);
undefined4 FUN_004ad687(int max_val,int point,int hBitmap);
void Mem_AllocOrFree_004ad725(int max_val,int point,int hBitmap);
void Mem_AllocOrFree_004ad74f(int max_val,int point,int hBitmap);
undefined4 Palette_Color_0049ae00(int spell_id,int target_id,int flags,int height);
undefined4 Glue_Subsystem_004dd632(int spell_id,int target_id,int flags);
undefined4 Palette_Color_0049ae00(int spell_id,int target_id,int flags);
uint FUN_004ae985(int max_val,int point,int hBitmap);
undefined4 FUN_004aed88(int max_val,int point,int hBitmap);
undefined4 FUN_004aee02(int max_val,int point,int hBitmap);
undefined4 Palette_Color_0049ae00(int spell_id,int target_id,int flags);
undefined4 FUN_004af1fa(int max_val,int point,int hBitmap);
int FUN_004af68f(int max_val);
void Mem_AllocOrFree_004af72b(int max_val);
int Duel_GetCardModifiedPower(int max_val, int point, int hBitmap);
int Duel_GetCardColorOverride(int max_val, int point, int hBitmap);
void Pic_Subsystem_0044895f(int player,int card_slot);
int Duel_ApplyCombatDamage(int max_val,int point,int hBitmap,int flags,int damage);
void Mem_AllocOrFree_004afd1c(int x,int y,int width,int height);
bool Glue_Subsystem_004ecee0(LPCSTR str_1);
void FUN_004afe04(void);
int Glue_UI_004ecfe5(HWND hwnd,uint y,HWND param_3,uint height);
void FUN_004b1bba(HWND hwnd);
void FUN_004b1cc1(HWND hwnd);
void FUN_004b1ed2(HWND hwnd);
void FUN_004b1fcf(HWND hwnd,int *point,int hBitmap,int *flags,int *damage,int arg_6);
void FUN_004b24c6(HWND hwnd,HWND param_2);
void FUN_004b25bb(HWND hwnd,LPARAM point,byte hBitmap);
int FUN_004b26c4(HWND hwnd,int *y,undefined4 *hBitmap,undefined4 *flags);
undefined4 FUN_004b27eb(HWND hwnd,int *card_slot);
int FUN_004b289b(HWND hwnd,int card_slot);
int FUN_004b2935(HWND hwnd,int card_slot);
HGDIOBJ UI_DialogProc_004b29b6(HWND hwnd,uint point,HDC hdc);
int Ai_Subsystem_004bc029(int spell_id,int target_id,int flags,uint flags,uint damage,int arg_6,undefined4 arg_7);
bool UI_CreateWindow_004b3360(LPCSTR str_1);
uint Pic_Load_004420a1(HWND hwnd,uint y,HWND param_3,int *height);
WPARAM FUN_004b4ea6(void);
undefined4 Pic_Clip_00443b63(HWND hwnd);
void FUN_004b5565(HWND hwnd,int card_slot);
void Palette_Subsystem_0049c3ac(int max_val,int point,int hBitmap);
void FUN_004b693d(void);
undefined4 Palette_Subsystem_0049608e(HWND hwnd,uint y,HDC hdc,undefined4 flags);
undefined4 Palette_Color_0049ae00(LPCSTR filepath);
void FUN_004b6eac(void);
uint UI_Register_WINBK_TellUser_004b6fea(HWND hwnd,uint y,HWND param_3,int height);
void FUN_004b7b63(HWND hwnd,char *str_2,uint hBitmap);
void FUN_004b7f54(HWND hwnd);
void FUN_004b8001(HWND hwnd,HDC hdc,int *hBitmap);
int FUN_004b8160(undefined4 max_val,int point,int hBitmap);
undefined4 UI_DialogProc_004b8231(HWND hwnd,uint uMsg,HWND wParam,byte *lParam);
void FUN_004b8899(HWND hwnd,byte point,byte hBitmap);
undefined4 FUN_004b8bf0(void);
uint FUN_004b921d(void);
void Mem_AllocOrFree_004b926e(void);
int FUN_004b927e(HDC hdc,int *y,WPARAM *hBitmap,int height);
int FUN_004b93c4(void);
undefined4 Mem_AllocOrFree_004b9420(void);
void Mem_AllocOrFree_004b9432(void);
void Mem_AllocOrFree_004b943d(void);
void Mem_AllocOrFree_004b9448(void);
bool UI_CreateWindow_004b9460(LPCSTR str_1);
void FUN_004b9523(void);
LRESULT Pic_Subsystem_0044bad4(HWND hwnd,uint y,HWND param_3,LONG *flags);
void FUN_004baa8b(HWND hwnd);
void FUN_004badc2(HDC hdc,int *point,int *hBitmap,int flags,int damage,int arg_6,int arg_7,int arg_8,HANDLE arg_9);
void FUN_004bb037(undefined4 max_val,int point,int hBitmap,int flags,int damage,int arg_6,int *arg_7,int *arg_8,int *arg_9,int *arg_10);
void Pic_Subsystem_0044d61a(char *str_1,HWND hwnd,undefined4 hBitmap);
undefined4 FUN_004bb120(int max_val,int point,int hBitmap);
undefined4 FUN_004bb61e(int max_val,int point,int hBitmap);
undefined4 FUN_004bbb5a(int max_val,int point,int hBitmap);
undefined4 Pic_Subsystem_00429237(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_004297ed(int spell_id,int target_id,int flags);
int Pic_Subsystem_00429e7d(int spell_id,int target_id,int flags);
void FUN_004bced7(int max_val,int point,int hBitmap);
uint Pic_Load_0042a1c9(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_0042ac1f(int player,int card_slot);
undefined4 Pic_Subsystem_0042ae1d(int spell_id,int target_id,int flags);
undefined4 FUN_004be3f6(int max_val,int point,int hBitmap);
undefined4 FUN_004be8ae(int max_val,int point,int hBitmap);
undefined4 FUN_004be8ee(int max_val,int point,int hBitmap);
undefined4 Pic_Subsystem_0042bb2e(int spell_id,int target_id,int flags);
void Pic_Subsystem_0042bee5(int spell_id,int target_id,int flags);
void Pic_Subsystem_0042bf45(int spell_id,int target_id,int flags);
undefined4 FUN_004beda5(int x,int y,int width,uint height);
undefined4 FUN_004bf72f(int max_val,int point,int hBitmap);
int FUN_004bf853(int player,int card_slot);
undefined4 FUN_004bfc63(int x,int y,int width,int height);
undefined4 FUN_004c044f(int max_val,int point,int hBitmap);
undefined4 FUN_004c0929(int max_val,int point,int hBitmap);
undefined4 Pic_Subsystem_0042dd1f(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_0042e2d9(int spell_id,int target_id,int flags);
undefined4 FUN_004c1610(int max_val,int point,int hBitmap);
undefined4 Pic_Subsystem_0042e8c0(int spell_id,int target_id,int flags);
undefined4 FUN_004c1a69(int player,int card_slot);
undefined4 Pic_Subsystem_0042ed9f(uint spell_id,int target_id,int flags);
uint FUN_004c20fd(int max_val,int point,int hBitmap);
undefined4 FUN_004c2495(int max_val,int point,int hBitmap);
undefined4 FUN_004c258e(int max_val,int point,int hBitmap);
undefined4 Pic_Subsystem_0042f87b(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_0042fe9a(int max_val,int point,int hBitmap);
undefined4 FUN_004c2e23(int max_val,int point,int hBitmap);
undefined4 FUN_004c2fbb(int max_val,int point,int hBitmap);
uint FUN_004c3059(int max_val,int point,int hBitmap);
undefined4 FUN_004c33f8(int max_val,int point,int hBitmap);
undefined4 Pic_Subsystem_0043070c(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_00430f0a(int spell_id,int target_id,int flags);
uint FUN_004c4244(int max_val,int point,int hBitmap);
undefined4 FUN_004c44d3(int max_val,int point,int hBitmap);
undefined4 Pic_Subsystem_004319c5(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_00431ed3(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_004325fe(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_00432b12(int spell_id,int target_id,int flags);
undefined4 FUN_004c5d78(int max_val,int point,int hBitmap);
undefined4 FUN_004c5e5f(int max_val,int point,int hBitmap);
undefined4 FUN_004c6039(int max_val,int point,int hBitmap);
void FUN_004c613b(int max_val,undefined4 point,int hBitmap);
undefined4 FUN_004c626d(int max_val,int point,int hBitmap);
undefined4 FUN_004c6423(int max_val,int point,int hBitmap);
undefined4 Pic_Subsystem_004336f8(int max_val,int point,int hBitmap);
undefined4 FUN_004c68a5(int max_val,int point,int hBitmap);
undefined4 FUN_004c698a(int max_val,int point,int hBitmap);
undefined4 Pic_Subsystem_00433c62(int spell_id,int target_id,int flags);
undefined4 Palette_Color_0049ae00(int spell_id,int target_id,int flags);
undefined4 FUN_004c7337(int x,int y,int width,int height);
undefined4 Pic_Subsystem_004345a9(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_00434b1f(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_00434f32(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_004353b3(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_00435abf(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_00436500(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_00436f60(int spell_id,int target_id,int flags);
void Pic_Subsystem_0043793a(int spell_id,int target_id,int flags);
undefined4 Palette_Color_0049ae00(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_00437df6(int spell_id,int target_id,int flags);
undefined4 Palette_Color_0049ae00(int spell_id,int target_id,int flags);
undefined4 FUN_004cb223(int max_val,int point,int hBitmap);
undefined4 FUN_004cb69a(int max_val,int point,int hBitmap);
undefined4 FUN_004cb79c(int max_val,int point,int hBitmap);
undefined4 Pic_Subsystem_00438ced(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_00439408(int max_val,int point,int hBitmap);
undefined4 FUN_004cc5eb(int max_val,int point,int hBitmap);
uint Pic_Subsystem_00439b92(int spell_id,int target_id,int flags);
void Pic_Subsystem_00439d8b(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_00439e06(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_0043a32c(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_0043ac68(int spell_id,int target_id,int flags);
undefined4 FUN_004cdd9b(int max_val,int point,int hBitmap);
undefined4 FUN_004cde6f(int max_val,int point,int hBitmap);
undefined4 FUN_004cdfdd(int max_val,int point,int hBitmap);
undefined4 Pic_Subsystem_0043b224(int max_val,int point,int hBitmap);
undefined4 Pic_Subsystem_0043b424(int max_val,int point,int hBitmap);
void Pic_Subsystem_0043b6eb(int spell_id,int target_id,int flags);
void Pic_Subsystem_0043b74e(int spell_id,int target_id,int flags);
void FUN_004ce5ce(int x,int y,int width,uint height);
void Pic_Subsystem_0043ba6e(int spell_id,int target_id,int flags);
void Pic_Subsystem_0043bad0(int spell_id,int target_id,int flags);
void Pic_Subsystem_0043bb32(int spell_id,int target_id,int flags);
void Pic_Subsystem_0043bb94(int spell_id,int target_id,int flags);
void Pic_Subsystem_0043bbf6(int spell_id,int target_id,int flags);
void Pic_Subsystem_0043bc58(int spell_id,int target_id,int flags);
undefined4 FUN_004ceabe(uint max_val,int point,int hBitmap,int flags,int damage);
undefined4 FUN_004ceeb6(int max_val,int point,int hBitmap);
void FUN_004cef78(int max_val,int point,int hBitmap);
void FUN_004cefaf(int max_val,int point,int hBitmap);
void FUN_004cefe6(int max_val,int point,int hBitmap);
void FUN_004cf01d(int max_val,int point,int hBitmap);
void FUN_004cf054(int max_val,int point,int hBitmap);
undefined4 Pic_Subsystem_0043c287(int spell_id,int target_id,int flags,int height);
undefined4 Pic_Subsystem_0043c8f5(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_0043d1c3(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_0043da0f(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_0043dfbb(int max_val,int point,int hBitmap);
undefined4 Pic_Subsystem_0043e0f6(int max_val,int point,int hBitmap);
undefined4 FUN_004d1597(int max_val,int point,int hBitmap);
undefined4 Pic_Subsystem_0043ebbf(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_0043f19e(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_0043f51d(int spell_id,int target_id,int flags);
uint Pic_Subsystem_0043faf7(int spell_id,int target_id,int flags);
void FUN_004d2b76(int max_val,int point,int hBitmap);
void FUN_004d2bad(int max_val,int point,int hBitmap);
void FUN_004d2be4(int max_val,int point,int hBitmap);
void FUN_004d2c1b(int max_val,int point,int hBitmap);
void FUN_004d2c52(int max_val,int point,int hBitmap);
undefined4 Pic_Subsystem_0043fe8e(int spell_id,int target_id,int flags,int height);
undefined4 Pic_Subsystem_0043fe8e(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_0044068c(int spell_id,int target_id,int flags);
undefined4 FUN_004d3945(int max_val,int point,int hBitmap);
undefined4 Pic_Subsystem_00440db5(int spell_id,int target_id,int flags);
undefined4 Pic_Subsystem_00441167(int spell_id,int target_id,int flags);
undefined4 FUN_004d42d8(int max_val,int point,int hBitmap);
undefined4 FUN_004d458b(int max_val,int point,int hBitmap);
int FUN_004d483e(int player,int card_slot);
undefined4 Mem_AllocOrFree_004d4e10(void);
undefined4 Pic_Load_0044ef70(undefined4 player,int card_slot);
void FUN_004d6362(undefined4 *max_val,undefined4 *point,undefined4 *hBitmap);
void FUN_004d6490(int player,int card_slot);
void FUN_004d65c6(DWORD max_val);
void FUN_004d65f2(int max_val,int *point,int hBitmap,int flags,undefined4 damage,int arg_6,undefined4 arg_7);
int Palette_Subsystem_004a5722(int max_val,int *out_buffer,int hBitmap,undefined4 flags,int damage,undefined4 arg_6);
int Pic_Subsystem_00451291(int player,int card_slot);
void FUN_004d6a15(int max_val,int point,int hBitmap);
undefined4 FUN_004d714c(void);
int FUN_004d71e6(int player,int card_slot);
uint FUN_004d7382(void);
int FUN_004d7460(uint player,uint card_slot);
int Ai_Subsystem_004cc1e8(uint max_val);
void FUN_004d76dd(uint max_val);
void FUN_004d7735(int max_val);
void FUN_004d7782(void);
undefined4 FUN_004d7876(int max_val,int point,int hBitmap);
void FUN_004d7946(int max_val);
void FUN_004d7acc(int player,int card_slot);
int FUN_004d7b2d(int player,undefined4 card_slot);
void FUN_004d7baa(int player,undefined4 card_slot);
int Pic_Subsystem_00452551(int max_val);
int Card_IsValidCardId(int max_val);
void FUN_004d7dd7(undefined4 max_val);
void FUN_004d7e29(undefined1 *max_val);
void FUN_004d7e62(undefined4 max_val);
void Mem_AllocOrFree_004d7ea5(void);
void Mem_AllocOrFree_004d7eb0(void);
int FUN_004d7ecb(void);
void FUN_004d7f60(undefined8 *player,uint card_slot);
int FUN_004d7fb8(undefined1 *max_val,undefined4 point,undefined4 hBitmap);
undefined4 FUN_004d8174(int max_val);
int FUN_004d8477(undefined4 *max_val,undefined4 point,undefined4 hBitmap);
int FUN_004d85eb(undefined4 max_val,undefined4 point,undefined4 hBitmap);
undefined4 FUN_004d8703(int max_val);
undefined4 FUN_004d8a53(int max_val);
int FUN_004d8bee(undefined4 *max_val,undefined4 point,undefined4 hBitmap);
int FUN_004d8cfe(undefined8 *max_val,uint *point,undefined4 hBitmap);
uint FUN_004d8f90(uint max_val);
uint FUN_004d9080(void);
void MCIWndCreateA(void);
BOOL GetOpenFileNameA(LPOPENFILENAMEA max_val);
BOOL GetSaveFileNameA(LPOPENFILENAMEA max_val);
void DeckBuilderMain(void);
uint * Mem_AllocOrFree_004d9630(uint *player,uint *card_slot);
uint * Str_CopyFast(uint *player, uint *card_slot);
int __cdecl _sprintf(char *str_1,char *str_2,...);
int Mem_AllocOrFree_004d9810(uint max_val);
void Mem_AllocOrFree_004d9830(undefined4 max_val);
int __cdecl _rand(void);
size_t __cdecl _strlen(char *str_1);
int __cdecl _strcmp(char *str_1,char *str_2);
void * __cdecl FID_conflict:_memcpy(void *ptr_1,void *ptr_2,size_t hBitmap);
int __cdecl _strncmp(char *str_1,char *str_2,size_t hBitmap);
long __cdecl _atol(char *str_1);
int __cdecl _atoi(char *str_1);
longlong __cdecl __atoi64(char *str_1);
void __assert(uint *max_val,uint *point,int hBitmap);
void * __cdecl _memset(void *ptr_1,int point,size_t hBitmap);
int __cdecl __cinit(int max_val);
void __cdecl _exit(int max_val);
void __exit(UINT max_val);
void __cdecl __cexit(void);
void __cdecl __c_exit(void);
void __cdecl doexit(UINT max_val,int point,int hBitmap);
void __initterm(int *player,int *card_slot);
size_t __cdecl _fread(void *ptr_1,size_t point,size_t hBitmap,FILE *fp);
void * __cdecl _malloc(size_t max_val);
void __malloc_dbg(size_t max_val,undefined4 point,undefined4 hBitmap,undefined4 flags);
void * __cdecl __nh_malloc(size_t max_val,int point);
int __nh_malloc_dbg(size_t max_val,int point,uint hBitmap,int flags,undefined4 damage);
void * __cdecl __heap_alloc(size_t max_val);
undefined4 * __heap_alloc_dbg(uint x,uint y,int width,undefined4 flags);
void * __cdecl _calloc(size_t max_val,size_t point);
undefined1 * __calloc_dbg(int max_val,int point,undefined4 hBitmap,undefined4 flags,undefined4 damage);
void * __cdecl FID_conflict:__expand(void *ptr_1,size_t point);
undefined4 __realloc_dbg(int max_val,uint point,uint hBitmap,int flags,int damage);
int * __cdecl realloc_help(int max_val,uint point,uint hBitmap,int flags,int damage,int arg_6);
void * __cdecl FID_conflict:__expand(void *ptr_1,size_t point);
undefined4 __expand_dbg(int max_val,uint point,uint hBitmap,int flags,int damage);
void FUN_004db150(void *max_val);
void __free_dbg(void *player,int card_slot);
size_t __cdecl __msize(void *ptr_1);
undefined4 __msize_dbg(int player,int card_slot);
undefined4 Mem_AllocOrFree_004db730(undefined4 max_val);
void __CrtSetDbgBlockType(int player,undefined4 card_slot);
undefined * Mem_AllocOrFree_004db800(undefined *max_val);
undefined4 _CheckBytes(char *str_1,char point,int hBitmap);
undefined4 __CrtCheckMemory(void);
int __CrtSetDbgFlag(int max_val);
void __CrtDoForAllClientObjects(undefined *player,undefined4 card_slot);
undefined4 __CrtIsValidPointer(void *max_val,UINT_PTR point,int hBitmap);
BOOL __CrtIsValidHeapPointer(int max_val);
undefined4 __CrtIsMemoryBlock(void *max_val,UINT_PTR point,undefined4 *hBitmap,undefined4 *flags,undefined4 *damage);
undefined4 Mem_AllocOrFree_004dbf10(undefined4 max_val);
void __CrtMemCheckpoint(undefined4 *max_val);
undefined4 __CrtMemDifference(undefined4 *max_val,int point,int hBitmap);
void __CrtMemDumpAllObjectsSince(undefined4 *max_val);
void __printMemBlockData(int max_val);
undefined4 __CrtDumpMemoryLeaks(void);
void __CrtMemDumpStatistics(int max_val);
FILE * __cdecl __fsopen(char *filename,char *str_2,int hBitmap);
FILE * __cdecl _fopen(char *filename,char *str_2);
int __cdecl _fclose(FILE *fp);
void * __cdecl _bsearch(void *ptr_1,void *out_buffer,size_t hBitmap,size_t flags,_PtFuncCompare *ptr_5);
int __cdecl _fseek(FILE *fp,long point,int hBitmap);
void __cdecl __splitpath(char *str_1,char *str_2,char *str_3,char *str_4,char *str_5);
char * __cdecl _fgets(char *str_1,int point,FILE *fp);
int __cdecl _fscanf(FILE *fp,char *str_2,...);
char * __cdecl _strchr(char *str_1,int point);
int __cdecl _sscanf(char *str_1,char *str_2,...);
size_t __cdecl _strspn(char *str_1,char *str_2);
size_t __cdecl _strcspn(char *str_1,char *str_2);
int __cdecl FID_conflict:__mkdir(char *str_1);
int __cdecl _fgetc(FILE *fp);
int __cdecl _getc(FILE *fp);
int __cdecl __open(char *filename,int point,...);
int __cdecl __sopen(char *filename,int point,int hBitmap,...);
int __cdecl __close(int max_val);
int __cdecl __read(int max_val,void *out_buffer,uint hBitmap);
int __cdecl _memcmp(void *ptr_1,void *ptr_2,size_t hBitmap);
void Mem_AllocOrFree_004ddee0(void);
size_t __cdecl FID_conflict:__fwrite_lk(void *ptr_1,size_t point,size_t hBitmap,FILE *fp);
char * __cdecl _strrchr(char *str_1,int point);
int __cdecl __isctype(int player,int card_slot);
longlong __fastcall __allshl(byte player,int card_slot);
long __cdecl _ftell(FILE *fp);
int __cdecl _fprintf(FILE *fp,char *str_2,...);
char * __cdecl _ctime(time_t *ptr_1);
time_t __cdecl _time(time_t *ptr_1);
int __cdecl __vsnprintf(char *str_1,size_t point,char *str_3,va_list flags);
char * __cdecl _strncpy(char *str_1,char *str_2,size_t hBitmap);
void __cdecl __fpmath(int max_val);
void Mem_AllocOrFree_004de9a0(void);
void __cfltcvt_init(void);
undefined4 Mem_AllocOrFree_004dea00(undefined4 max_val);
void entry(void);
void __cdecl __amsg_exit(int max_val);
int __cdecl __flsbuf(int player,FILE *card_slot);
int __output(FILE *max_val,byte *point,undefined4 *hBitmap);
void __cdecl write_char(int max_val,FILE *fp,int *hBitmap);
void __cdecl write_multi_char(int x,int y,FILE *fp,int *height);
void __cdecl write_string(char *str_1,int y,FILE *fp,int *height);
undefined4 __cdecl get_int_arg(int *max_val);
undefined8 __cdecl get_int64_arg(int *max_val);
undefined4 __cdecl get_short_arg(int *max_val);
void __CrtDbgBreak(void);
undefined4 __CrtSetReportMode(int player,uint card_slot);
undefined4 __CrtSetReportFile(int player,int card_slot);
undefined4 Mem_AllocOrFree_004dffe0(undefined4 max_val);
undefined4 __CrtDbgReport(int max_val,int point,int hBitmap,undefined4 flags,char *str_5);
bool _CrtMessageWindow(void);
longlong __allmul(uint x,int y,uint width,int height);
void __cdecl _abort(void);
void __cdecl _signal(int max_val);
undefined4 ctrlevent_capture(int max_val);
int __cdecl _raise(int max_val);
undefined4 * __cdecl siglookup(int max_val);
int __cdecl ___crtMessageBoxA(LPCSTR max_val,LPCSTR point,UINT hBitmap);
char * __cdecl _strncat(char *str_1,char *str_2,size_t hBitmap);
char * __cdecl __itoa(int max_val,char *str_2,int hBitmap);
void __cdecl xtoa(uint x,char *str_2,uint width,int height);
char * __cdecl __ltoa(long max_val,char *str_2,int hBitmap);
char * __cdecl __ultoa(ulong max_val,char *str_2,int hBitmap);
char * __cdecl __i64toa(longlong max_val,char *str_2,int hBitmap);
void x64toa(uint max_val,uint point,char *str_3,uint flags,int damage);
char * __cdecl __ui64toa(ulonglong max_val,char *str_2,int hBitmap);
int __cdecl _fflush(FILE *fp);
int __cdecl __flush(FILE *fp);
int __cdecl __flushall(void);
int __cdecl flsall(int max_val);
void ___initstdio(void);
void ___endstdio(void);
int __cdecl _setvbuf(FILE *x,char *y,int width,size_t height);
int __cdecl __filbuf(FILE *fp);
undefined4 Mem_AllocOrFree_004e1910(undefined4 max_val);
undefined4 Mem_AllocOrFree_004e1940(void);
int __cdecl __callnewh(size_t max_val);
void __malloc_base(uint max_val);
int __nh_malloc_base(uint player,int card_slot);
LPVOID __heap_alloc_base(int max_val);
undefined4 Mem_AllocOrFree_004e1ae0(void);
LPVOID __expand_base(LPVOID player,uint card_slot);
void * __realloc_base(void *player,uint card_slot);
void __free_base(LPVOID max_val);
int __cdecl __heapchk(void);
int __cdecl __heapset(uint max_val);
int __cdecl __heap_init(void);
void __cdecl __heap_term(void);
undefined4 Mem_AllocOrFree_004e1fb0(void);
bool __set_sbh_threshold(int max_val);
undefined ** ___sbh_new_region(void);
void ___sbh_release_region(undefined **max_val);
void ___sbh_decommit_pages(int max_val);
int ___sbh_find_block(undefined *max_val,undefined4 *point,uint *hBitmap);
void ___sbh_free_block(int max_val,int point,char *str_3);
undefined * ___sbh_alloc_block(uint max_val);
int ___sbh_alloc_block_from_page(int *max_val,uint point,uint hBitmap);
undefined4 ___sbh_resize_block(int x,undefined4 *point,byte *hBitmap,uint height);
undefined4 ___sbh_heap_check(void);
FILE * __cdecl __openfile(char *x,char *y,int width,FILE *height);
FILE * __cdecl __getstream(void);
void __cdecl __freebuf(FILE *fp);
long __cdecl __lseek(int max_val,long point,int hBitmap);
uchar * __cdecl __mbsnbcpy(uchar *str_1,uchar *str_2,size_t hBitmap);
int __cdecl __setmbcp(int max_val);
UINT __cdecl getSystemCP(UINT max_val);
undefined4 _CPtoLCID(undefined4 max_val);
void __cdecl setSBCS(void);
undefined4 Mem_AllocOrFree_004e3e10(void);
void ___initmbctable(void);
uint __input(int max_val,byte *point,undefined4 *hBitmap);
uint __hextodec(uint max_val);
uint __inc(FILE *fp);
void __un_inc(int player,FILE *fp);
int __whiteout(int *player,FILE *fp);
void __cdecl __dosmaperr(ulong max_val);
int __cdecl __ioinit(void);
void __cdecl __ioterm(void);
int __cdecl __chsize(int player,long card_slot);
int __cdecl __alloc_osfhnd(void);
int __cdecl __set_osfhnd(int player,intptr_t card_slot);
int __cdecl __free_osfhnd(int max_val);
intptr_t __cdecl __get_osfhandle(int max_val);
int __cdecl __open_osfhandle(intptr_t player,int card_slot);
int __cdecl __write(int max_val,void *ptr_2,uint hBitmap);
void ___crtGetStringTypeW(DWORD max_val,LPCWSTR point,int hBitmap,LPWORD flags,UINT damage,LCID arg_6);
BOOL __cdecl ___crtGetStringTypeA(_locale_t max_val,DWORD point,LPCSTR hBitmap,int flags,LPWORD damage,int arg_6,BOOL arg_7);
int __cdecl __stbuf(FILE *fp);
void __cdecl __ftbuf(int player,FILE *card_slot);
char * __cdecl _asctime(tm *ptr_1);
char * __cdecl store_dt(char *str_1,int card_slot);
tm * __cdecl _localtime(time_t *ptr_1);
int ___loctotime_t(int max_val,int point,int hBitmap,int flags,int damage,int arg_6,int arg_7);
void __setdefaultprecision(void);
undefined4 __ms_p5_test_fdiv(void);
void __ms_p5_mp_test_fdiv(void);
void __cdecl __forcdecpt(char *str_1);
void __cdecl __cropzeros(char *str_1);
int __cdecl __positive(double *ptr_1);
void __cdecl __fassign(int max_val,char *str_2,char *str_3);
errno_t __cdecl __cftoe(double *ptr_1,char *str_2,size_t hBitmap,int flags,int damage);
errno_t __cdecl __cftof(double *x,char *y,size_t width,int height);
void __cftog(undefined4 *max_val,int y,size_t hBitmap,int flags);
errno_t __cftoe_g(double *max_val,char *str_2,size_t hBitmap,int height);
errno_t __cftof_g(double *max_val,char *str_2,size_t hBitmap);
errno_t __cdecl __cfltcvt(double *ptr_1,char *str_2,size_t hBitmap,int flags,int damage,int arg_6);
void __shift(char *str_1,int card_slot);
void __global_unwind2(PVOID max_val);
void __local_unwind2(int player,int card_slot);
void Mem_AllocOrFree_004e771e(void);
int __cdecl __XcptFilter(ulong card_id,_EXCEPTION_POINTERS *out_filter);
int * __cdecl xcptlookup(int max_val);
int __cdecl __ismbbkalnum(uint max_val);
int __cdecl __ismbbkprint(uint max_val);
int __cdecl __ismbbkpunct(uint max_val);
int __cdecl __ismbbalnum(uint max_val);
int __cdecl __ismbbalpha(uint max_val);
int __cdecl __ismbbgraph(uint max_val);
int __cdecl __ismbbprint(uint max_val);
int __cdecl __ismbbpunct(uint max_val);
int __cdecl __ismbblead(uint max_val);
int __cdecl __ismbbtrail(uint max_val);
int __cdecl __ismbbkana(uint max_val);
undefined4 __cdecl x_ismbbtype(byte max_val,uint point,byte hBitmap);
int __cdecl __setargv(void);
void __cdecl parse_cmdline(byte *max_val,undefined4 *point,byte *hBitmap,int *flags,int *damage);
LPVOID __cdecl ___crtGetEnvironmentStringsW(void);
LPVOID __cdecl ___crtGetEnvironmentStringsA(void);
void FUN_004e8661(int max_val);
void __cdecl __FF_MSGBANNER(void);
void __cdecl __NMSG_WRITE(int max_val);
wchar_t * __cdecl __GET_RTERRMSG(int max_val);
void __cdecl __getbuf(FILE *fp);
int __cdecl __isatty(int max_val);
int __cdecl _wctomb(char *str_1,wchar_t point);
undefined8 __aulldiv(uint x,uint y,uint width,uint height);
undefined8 __aullrem(uint x,uint y,uint width,uint height);
int __cdecl __snprintf(char *str_1,size_t point,char *str_3,...);
int __cdecl __commit(int max_val);
int __cdecl __fcloseall(void);
int __cdecl _mbtowc(wchar_t *str_1,char *str_2,size_t hBitmap);
int __cdecl _isalpha(int max_val);
int __cdecl _isupper(int max_val);
int __cdecl _islower(int max_val);
int __cdecl _isdigit(int max_val);
int __cdecl _isxdigit(int max_val);
int __cdecl _isspace(int max_val);
int __cdecl _ispunct(int max_val);
int __cdecl _isalnum(int max_val);
int __cdecl _isprint(int max_val);
int __cdecl _isgraph(int max_val);
int __cdecl _iscntrl(int max_val);
int __cdecl ___isascii(int max_val);
uint Mem_AllocOrFree_004e9420(uint max_val);
int __cdecl ___iscsymf(int max_val);
int __cdecl ___iscsym(int max_val);
int __cdecl _ungetc(int player,FILE *card_slot);
int __cdecl __setmode(int player,int card_slot);
void * __cdecl FID_conflict:_memcpy(void *ptr_1,void *ptr_2,size_t hBitmap);
void ___tzset(void);
void __cdecl __tzset(void);
int __cdecl __isindst(tm *ptr_1);
void __cdecl cvtdate(int max_val,int point,uint hBitmap,int flags,int damage,int arg_6,int arg_7,int arg_8,int arg_9,int arg_10,int arg_11);
tm * __cdecl _gmtime(time_t *ptr_1);
uint __cdecl __statusfp(void);
uint __cdecl __clearfp(void);
uint __cdecl __control87(uint player,uint card_slot);
uint __cdecl __controlfp(uint player,uint card_slot);
void __cdecl __fpreset(void);
uint __abstract_cw(uint max_val);
undefined4 __hw_cw(uint max_val);
uint __abstract_sw(byte max_val);
void __cdecl __fptrap(void);
int Mem_AllocOrFree_004ea900(int max_val);
int __cdecl _tolower(int max_val);
undefined4 __ZeroTail(int player,int card_slot);
int __IncMan(int player,int card_slot);
undefined4 __RoundMan(int player,int card_slot);
void __CopyMan(undefined4 *player,undefined4 *card_slot);
void __FillZeroMan(int max_val);
undefined4 __IsZeroMan(int max_val);
void __ShrMan(int player,int card_slot);
undefined4 __ld12cvt(ushort *max_val,uint *point,int *hBitmap);
INTRNCVT_STATUS __cdecl FID_conflict:__ld12tod(_LDBL12 *ptr_1,_CRT_DOUBLE *ptr_2);
INTRNCVT_STATUS __cdecl FID_conflict:__ld12tod(_LDBL12 *ptr_1,_CRT_DOUBLE *ptr_2);
INTRNCVT_STATUS __cdecl __ld12told(_LDBL12 *ptr_1,_LDOUBLE *ptr_2);
int __cdecl FID_conflict:__atodbl(_CRT_FLOAT *ptr_1,char *str_2);
int __cdecl __atoldbl(_LDOUBLE *ptr_1,char *str_2);
int __cdecl FID_conflict:__atodbl(_CRT_FLOAT *ptr_1,char *str_2);
errno_t __cdecl __fptostr(char *x,size_t y,int width,STRFLT height);
undefined * __fltout(void);
void ___dtold(uint *player,uint *card_slot);
size_t __cdecl _wcslen(wchar_t *str_1);
size_t __cdecl _wcstombs(char *str_1,wchar_t *str_2,size_t hBitmap);
int __cdecl wcsncnt(short *player,int card_slot);
char * __cdecl _getenv(char *str_1);
int __cdecl ___crtLCMapStringW(LPCWSTR max_val,DWORD point,LPCWSTR hBitmap,int flags,LPWSTR damage,int arg_6);
int __cdecl wcsncnt(short *player,int card_slot);
int __cdecl ___crtLCMapStringA(_locale_t max_val,LPCWSTR point,DWORD hBitmap,LPCSTR flags,int damage,LPSTR arg_6,int arg_7,int arg_8,BOOL arg_9);
size_t __cdecl _strncnt(char *str_1,size_t point);
undefined4 ___addl(uint max_val,uint point,uint *hBitmap);
void ___add_12(uint *player,uint *card_slot);
void ___shl_12(int *max_val);
void ___shr_12(uint *max_val);
void ___mtold12(char *str_1,int point,uint *hBitmap);
uint __cdecl ___strgtold12(_LDBL12 *ptr_1,char **str_2,char *str_3,int flags,int damage,int arg_6,int arg_7);
uint __cdecl ___STRINGTOLD(_LDOUBLE *x,char **y,char *width,int height);
undefined4 __cdecl $I10_OUTPUT(int max_val,uint point,ushort hBitmap,int flags,byte damage,short *arg_6);
int __cdecl __mbsnbicoll(uchar *str_1,uchar *str_2,size_t hBitmap);
int __cdecl ___wtomb_environ(void);
void ___ld12mul(int *player,int *card_slot);
void ___multtenpow12(int *max_val,uint point,int hBitmap);
int __cdecl ___crtCompareStringW(LPCWSTR max_val,DWORD point,LPCWSTR hBitmap,int flags,LPCWSTR damage,int arg_6);
int __cdecl wcsncnt(short *player,int card_slot);
int __cdecl ___crtCompareStringA(_locale_t max_val,LPCWSTR point,DWORD hBitmap,LPCSTR flags,int damage,LPCSTR arg_6,int arg_7,int arg_8);
size_t __cdecl _strncnt(char *str_1,size_t point);
int __cdecl ___crtsetenv(char **str_1,int point);
int __cdecl findenv(uchar *str_1,size_t card_slot);
int * __cdecl copy_environ(int *max_val);
uchar * __cdecl __mbschr(uchar *str_1,uint point);
void RtlUnwind(PVOID max_val,PVOID point,PEXCEPTION_RECORD hBitmap,PVOID flags);
int __cdecl __chdir(char *str_1);
int __cdecl __strcmpi(char *str_1,char *str_2);
int __cdecl __strnicmp(char *str_1,char *str_2,size_t hBitmap);
char * __cdecl __strlwr(char *str_1);
uint __cdecl __mbctoupper(uint max_val);
void __fastcall FUN_006c5000(undefined4 max_val,undefined4 point,ushort *hBitmap);
void __fastcall FUN_006c5245(undefined4 player,undefined4 card_slot);
void FUN_006c52b5(void);
void __fastcall FUN_006c5300(uint max_val);
undefined4 __fastcall FUN_006c5392(undefined4 max_val,uint point,undefined4 hBitmap);
void Mem_AllocOrFree_006c5484(undefined4 player,uint card_slot);


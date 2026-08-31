/*
 * windows_types.h - Standard ANSI C Win32/x86 Type Definitions & Ghidra Compatibility
 */
#ifndef WINDOWS_TYPES_H
#define WINDOWS_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

/* Calling conventions */
#ifndef __cdecl
#define __cdecl
#endif
#ifndef __stdcall
#define __stdcall
#endif
#ifndef __fastcall
#define __fastcall
#endif
#ifndef CALLBACK
#define CALLBACK
#endif
#ifndef WINAPI
#define WINAPI
#endif

/* Basic Windows Types */
typedef uint8_t   BYTE;
typedef uint16_t  WORD;
typedef uint32_t  DWORD;
typedef int32_t   BOOL;
typedef int32_t   LONG;
typedef uint32_t  ULONG;
typedef uint32_t  UINT;
typedef int32_t   INT;
typedef int16_t   SHORT;
typedef uint16_t  USHORT;
typedef uint8_t   UCHAR;
typedef char      CHAR;
typedef wchar_t   WCHAR;
typedef void*     LPVOID;
typedef const void* LPCVOID;
typedef void*     PVOID;
typedef void*     HANDLE;
typedef HANDLE*   LPHANDLE;
typedef void*     HWND;
typedef void*     HDC;
typedef void*     HINSTANCE;
typedef void*     HBITMAP;
typedef void*     HPALETTE;
typedef void*     HMENU;
typedef void*     HACCEL;
typedef uint32_t  MMRESULT;
typedef int32_t   HRESULT;
typedef void*     HPEN;
typedef void*     HBRUSH;
typedef void*     HFONT;
typedef void*     HGDIOBJ;
typedef void*     HRGN;
typedef void*     HICON;
typedef void*     HCURSOR;
typedef void*     HMODULE;
typedef void*     HKEY;
typedef HKEY*     PHKEY;
typedef void*     HGLOBAL;
typedef void*     HLOCAL;
typedef void*     HRSRC;
typedef void*     HHOOK;
typedef void*     HRAWINPUT;
typedef void*     HMONITOR;
typedef int       HFILE;
typedef uint16_t  ATOM;
typedef char*     LPSTR;
typedef const char* LPCSTR;
typedef wchar_t*  LPWSTR;
typedef const wchar_t* LPCWSTR;
typedef uint8_t*  LPBYTE;
typedef intptr_t  LRESULT;
typedef uintptr_t WPARAM;
typedef intptr_t  LPARAM;
typedef uintptr_t ULONG_PTR;
typedef intptr_t  LONG_PTR;
typedef uintptr_t DWORD_PTR;
typedef intptr_t  INT_PTR;
typedef uintptr_t UINT_PTR;
typedef size_t    SIZE_T;
typedef uint32_t  COLORREF;
typedef void*     LPOFNHOOKPROC;
typedef int       (*FARPROC)(void);
typedef int       (*NEARPROC)(void);
typedef void*     HMMIO;
typedef char*     HPSTR;
typedef uint32_t  FOURCC;
typedef void*     PAVIFILE;
typedef void*     PAVISTREAM;
typedef void*     HDRAWDIB;
typedef void*     HIC;
typedef void*     HWAVEOUT;
typedef uint32_t  LCID;
typedef uint32_t  REGSAM;
typedef const void* LPCLSID;
typedef int*      LPINT;
typedef LONG*     PLONG;
typedef LONG*     LPLONG;
typedef DWORD*    LPDWORD;
typedef BOOL*     LPBOOL;
typedef WORD*     LPWORD;

#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif

/* Bit concatenation macros used in decompiled bitfield manipulation */
#ifndef CONCAT31
#define CONCAT31(a,b) ((uint32_t)(((uint32_t)(a) << 8) | ((uint8_t)(b))))
#endif
#ifndef CONCAT11
#define CONCAT11(a,b) ((uint16_t)(((uint16_t)(a) << 8) | ((uint8_t)(b))))
#endif
#ifndef CONCAT22
#define CONCAT22(a,b) ((uint32_t)(((uint32_t)(a) << 16) | ((uint16_t)(b))))
#endif

/* Ghidra Builtin Pseudo-types & Compatibility Aliases */
typedef uint8_t   undefined;
typedef uint8_t   undefined1;
typedef uint16_t  undefined2;
typedef uint32_t  undefined4;
typedef uint64_t  undefined8;
typedef uint8_t   byte;
typedef uint16_t  word;
typedef uint32_t  dword;
typedef uint64_t  qword;
typedef uint32_t  uint;
typedef uint16_t  ushort;
typedef uint8_t   uchar;
typedef uint32_t  ulong;
typedef int64_t   longlong;
typedef uint64_t  ulonglong;
typedef void*     pointer32;
typedef void*     pointer;
typedef void*     code;
typedef void*     BADSPACEBASE;
typedef uint32_t  ImageBaseOffset32;

/* Basic Geometry Structures */
typedef struct tagPOINT {
    LONG x;
    LONG y;
} POINT, *PPOINT, *LPPOINT;

typedef struct tagRECT {
    LONG left;
    LONG top;
    LONG right;
    LONG bottom;
} RECT, *PRECT, *LPRECT;

typedef struct tagSIZE {
    LONG cx;
    LONG cy;
} SIZE, *PSIZE, *LPSIZE;

/* GDI Graphics & Color Structures */
typedef struct tagRGBQUAD {
    uint8_t rgbBlue;
    uint8_t rgbGreen;
    uint8_t rgbRed;
    uint8_t rgbReserved;
} RGBQUAD;

typedef struct tagPALETTEENTRY {
    uint8_t peRed;
    uint8_t peGreen;
    uint8_t peBlue;
    uint8_t peFlags;
} PALETTEENTRY, *PPALETTEENTRY, *LPPALETTEENTRY;

typedef struct tagLOGPALETTE {
    WORD         palVersion;
    WORD         palNumEntries;
    PALETTEENTRY palPalEntry[1];
} LOGPALETTE, *PLOGPALETTE, *LPLOGPALETTE;

typedef struct tagBITMAPINFOHEADER {
    DWORD biSize;
    LONG  biWidth;
    LONG  biHeight;
    WORD  biPlanes;
    WORD  biBitCount;
    DWORD biCompression;
    DWORD biSizeImage;
    LONG  biXPelsPerMeter;
    LONG  biYPelsPerMeter;
    DWORD biClrUsed;
    DWORD biClrImportant;
} BITMAPINFOHEADER, *PBITMAPINFOHEADER, *LPBITMAPINFOHEADER;

typedef struct tagBITMAPINFO {
    BITMAPINFOHEADER bmiHeader;
    RGBQUAD          bmiColors[1];
} BITMAPINFO, *PBITMAPINFO, *LPBITMAPINFO;

typedef struct tagBITMAP {
    LONG   bmType;
    LONG   bmWidth;
    LONG   bmHeight;
    LONG   bmWidthBytes;
    WORD   bmPlanes;
    WORD   bmBitsPixel;
    LPVOID bmBits;
} BITMAP, *PBITMAP, *LPBITMAP;

typedef struct tagPAINTSTRUCT {
    HDC  hdc;
    BOOL fErase;
    RECT rcPaint;
    BOOL fRestore;
    BOOL fIncUpdate;
    BYTE rgbReserved[32];
} PAINTSTRUCT, *PPAINTSTRUCT, *LPPAINTSTRUCT;

typedef struct tagLOGFONTA {
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
} LOGFONTA, *PLOGFONTA, *LPLOGFONTA;

typedef struct tagLOGPEN {
    UINT     lopnStyle;
    POINT    lopnWidth;
    COLORREF lopnColor;
} LOGPEN, *PLOGPEN, *LPLOGPEN;

typedef struct tagLOGBRUSH {
    UINT      lbStyle;
    COLORREF  lbColor;
    ULONG_PTR lbHatch;
} LOGBRUSH, *PLOGBRUSH, *LPLOGBRUSH;

typedef struct tagTEXTMETRICA {
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
} TEXTMETRICA, *PTEXTMETRICA, *LPTEXTMETRICA;

typedef struct _ABC {
    int  abcA;
    UINT abcB;
    int  abcC;
} ABC, *PABC, *LPABC;

/* Windowing & Message Structures */
typedef struct tagWNDCLASSA {
    UINT      style;
    void*     lpfnWndProc;
    int       cbClsExtra;
    int       cbWndExtra;
    HINSTANCE hInstance;
    HICON     hIcon;
    HCURSOR   hCursor;
    HBRUSH    hbrBackground;
    LPCSTR    lpszMenuName;
    LPCSTR    lpszClassName;
} WNDCLASSA, *PWNDCLASSA, *LPWNDCLASSA;

typedef struct tagMSG tagMSG;
typedef struct tagMSG {
    HWND   hwnd;
    UINT   message;
    WPARAM wParam;
    LPARAM lParam;
    DWORD  time;
    POINT  pt;
} MSG, *PMSG, *LPMSG;

typedef struct tagACCEL {
    BYTE  fVirt;
    WORD  key;
    WORD  cmd;
} ACCEL, *LPACCEL;

typedef struct tagMENUITEMINFOA {
    UINT      cbSize;
    UINT      fMask;
    UINT      fType;
    UINT      fState;
    UINT      wID;
    HMENU     hSubMenu;
    HBITMAP   hbmpChecked;
    HBITMAP   hbmpUnchecked;
    ULONG_PTR dwItemData;
    LPSTR     dwTypeData;
    UINT      cch;
    HBITMAP   hbmpItem;
} MENUITEMINFOA, *LPMENUITEMINFOA;

typedef struct tagOPENFILENAMEA {
    DWORD         lStructSize;
    HWND          hwndOwner;
    HINSTANCE     hInstance;
    LPCSTR        lpstrFilter;
    LPSTR         lpstrCustomFilter;
    DWORD         nMaxCustFilter;
    DWORD         nFilterIndex;
    LPSTR         lpstrFile;
    DWORD         nMaxFile;
    LPSTR         lpstrFileTitle;
    DWORD         nMaxFileTitle;
    LPCSTR        lpstrInitialDir;
    LPCSTR        lpstrTitle;
    DWORD         Flags;
    WORD          nFileOffset;
    WORD          nFileExtension;
    LPCSTR        lpstrDefExt;
    LPARAM        lCustData;
    LPOFNHOOKPROC lpfnHook;
    LPCSTR        lpTemplateName;
} OPENFILENAMEA, *LPOPENFILENAMEA;

/* Synchronization & Process Structures */
typedef struct _CRITICAL_SECTION {
    void *DebugInfo;
    LONG LockCount;
    LONG RecursionCount;
    HANDLE OwningThread;
    HANDLE LockSemaphore;
    ULONG_PTR SpinCount;
} CRITICAL_SECTION, *LPCRITICAL_SECTION;

typedef struct _SYSTEMTIME {
    WORD wYear;
    WORD wMonth;
    WORD wDayOfWeek;
    WORD wDay;
    WORD wHour;
    WORD wMinute;
    WORD wSecond;
    WORD wMilliseconds;
} SYSTEMTIME, *PSYSTEMTIME, *LPSYSTEMTIME;

typedef struct _TIME_ZONE_INFORMATION {
    LONG       Bias;
    WCHAR      StandardName[32];
    SYSTEMTIME StandardDate;
    LONG       StandardBias;
    WCHAR      DaylightName[32];
    SYSTEMTIME DaylightDate;
    LONG       DaylightBias;
} TIME_ZONE_INFORMATION, *PTIME_ZONE_INFORMATION, *LPTIME_ZONE_INFORMATION;

typedef struct _SECURITY_ATTRIBUTES {
    DWORD  nLength;
    LPVOID lpSecurityDescriptor;
    BOOL   bInheritHandle;
} SECURITY_ATTRIBUTES, *PSECURITY_ATTRIBUTES, *LPSECURITY_ATTRIBUTES;

typedef struct _OVERLAPPED {
    ULONG_PTR Internal;
    ULONG_PTR InternalHigh;
    union {
        struct {
            DWORD Offset;
            DWORD OffsetHigh;
        };
        PVOID Pointer;
    };
    HANDLE    hEvent;
} OVERLAPPED, *LPOVERLAPPED;

typedef struct _STARTUPINFOA {
    DWORD  cb;
    LPSTR  lpReserved;
    LPSTR  lpDesktop;
    LPSTR  lpTitle;
    DWORD  dwX;
    DWORD  dwY;
    DWORD  dwXSize;
    DWORD  dwYSize;
    DWORD  dwXCountChars;
    DWORD  dwYCountChars;
    DWORD  dwFillAttribute;
    DWORD  dwFlags;
    WORD   wShowWindow;
    WORD   cbReserved2;
    LPBYTE lpReserved2;
    HANDLE hStdInput;
    HANDLE hStdOutput;
    HANDLE hStdError;
} STARTUPINFOA, *LPSTARTUPINFOA;

typedef struct _PROCESS_INFORMATION {
    HANDLE hProcess;
    HANDLE hThread;
    DWORD  dwProcessId;
    DWORD  dwThreadId;
} PROCESS_INFORMATION, *PPROCESS_INFORMATION, *LPPROCESS_INFORMATION;

typedef struct _CPINFO {
    UINT MaxCharSize;
    BYTE DefaultChar[2];
    BYTE LeadByte[12];
} CPINFO, *LPCPINFO;

/* Multimedia Structures */
typedef struct tagMMIOINFO {
    DWORD     dwFlags;
    FOURCC    fccIOProc;
    void*     pIOProc;
    UINT      wErrorRet;
    void*     htask;
    LONG      cchBuffer;
    char*     pchBuffer;
    char*     pchNext;
    char*     pchEndRead;
    char*     pchEndWrite;
    LONG      lBufOffset;
    LONG      lDiskOffset;
    DWORD     adwInfo[3];
    DWORD     dwReserved1;
    DWORD     dwReserved2;
    HMMIO     hmmio;
} MMIOINFO, *PMMIOINFO, *LPMMIOINFO;
typedef const MMIOINFO *LPCMMIOINFO;

typedef struct tagMMCKINFO {
    FOURCC  ckid;
    DWORD   cksize;
    FOURCC  fccType;
    DWORD   dwDataOffset;
    DWORD   dwFlags;
} MMCKINFO, *PMMCKINFO, *LPMMCKINFO;

typedef struct tagTIMECAPS {
    UINT wPeriodMin;
    UINT wPeriodMax;
} TIMECAPS, *PTIMECAPS, *LPTIMECAPS;

typedef struct tagAVIFILEINFOA {
    DWORD   dwMaxBytesPerSec;
    DWORD   dwFlags;
    DWORD   dwCaps;
    DWORD   dwStreams;
    DWORD   dwSuggestedBufferSize;
    DWORD   dwWidth;
    DWORD   dwHeight;
    DWORD   dwScale;
    DWORD   dwRate;
    DWORD   dwLength;
    DWORD   dwEditCount;
    CHAR    szFileType[64];
} AVIFILEINFOA, *LPAVIFILEINFOA;

typedef struct tagAVISTREAMINFOA {
    DWORD   fccType;
    FOURCC  fccHandler;
    DWORD   dwFlags;
    DWORD   dwCaps;
    WORD    wPriority;
    WORD    wLanguage;
    DWORD   dwScale;
    DWORD   dwRate;
    DWORD   dwStart;
    DWORD   dwLength;
    DWORD   dwInitialFrames;
    DWORD   dwSuggestedBufferSize;
    DWORD   dwQuality;
    DWORD   dwSampleSize;
    RECT    rcFrame;
    DWORD   dwEditCount;
    DWORD   dwFormatChangeCount;
    CHAR    szName[64];
} AVISTREAMINFOA, *LPAVISTREAMINFOA;

typedef struct tagDRAWDIBTIME {
    LONG timeCount;
    LONG timeDraw;
    LONG timeDecompress;
    LONG timeDither;
    LONG timeStretch;
    LONG timeBlt;
    LONG timeSetDIBits;
} DRAWDIBTIME, *LPDRAWDIBTIME;

typedef struct tagICOPEN {
    DWORD   dwSize;
    DWORD   fccType;
    DWORD   fccHandler;
    DWORD   dwVersion;
    DWORD   dwFlags;
    LRESULT dwError;
    LPVOID  pV1Reserved;
    LPVOID  pV2Reserved;
    DWORD   dnDevNode;
} ICOPEN, *LPICOPEN;

typedef struct tagICINFO {
    DWORD   dwSize;
    DWORD   fccType;
    DWORD   fccHandler;
    DWORD   dwFlags;
    DWORD   dwVersion;
    DWORD   dwVersionICM;
    WCHAR   szName[16];
    WCHAR   szDescription[128];
    WCHAR   szDriver[128];
} ICINFO, *LPICINFO;

typedef struct tagWAVEHDR {
    LPSTR      lpData;
    DWORD      dwBufferLength;
    DWORD      dwBytesRecorded;
    DWORD_PTR  dwUser;
    DWORD      dwFlags;
    DWORD      dwLoops;
    struct tagWAVEHDR *lpNext;
    DWORD_PTR  reserved;
} WAVEHDR, *PWAVEHDR, *LPWAVEHDR;

typedef struct tagAPPBARDATA {
    DWORD  cbSize;
    HWND   hWnd;
    UINT   uCallbackMessage;
    UINT   uEdge;
    RECT   rc;
    LPARAM lParam;
} APPBARDATA, *PAPPBARDATA;

/* Function pointer typedefs */
typedef LRESULT (*WNDPROC)(HWND, UINT, WPARAM, LPARAM);
typedef INT_PTR (*DLGPROC)(HWND, UINT, WPARAM, LPARAM);
typedef BOOL    (*WNDENUMPROC)(HWND, LPARAM);
typedef void    (CALLBACK *TIMECALLBACK)(UINT uTimerID, UINT uMsg, DWORD_PTR dwUser, DWORD_PTR dw1, DWORD_PTR dw2);
typedef void    (CALLBACK *LPTIMECALLBACK)(UINT uTimerID, UINT uMsg, DWORD_PTR dwUser, DWORD_PTR dw1, DWORD_PTR dw2);
typedef void    (*TIMERPROC)(HWND, UINT, UINT_PTR, DWORD);
typedef DWORD   (WINAPI *LPTHREAD_START_ROUTINE)(LPVOID lpThreadParameter);
typedef BOOL    (WINAPI *PHANDLER_ROUTINE)(DWORD CtrlType);

/* Constants: Window Styles & Window Long Offsets */
#define WS_OVERLAPPED       0x00000000L
#define WS_POPUP            0x80000000L
#define WS_CHILD            0x40000000L
#define WS_MINIMIZE         0x20000000L
#define WS_VISIBLE          0x10000000L
#define WS_DISABLED         0x08000000L
#define WS_CLIPSIBLINGS     0x04000000L
#define WS_CLIPCHILDREN     0x02000000L
#define WS_MAXIMIZE         0x01000000L
#define WS_CAPTION          0x00C00000L
#define WS_BORDER           0x00800000L
#define WS_DLGFRAME         0x00400000L
#define WS_VSCROLL          0x00200000L
#define WS_HSCROLL          0x00100000L
#define WS_SYSMENU          0x00080000L
#define WS_THICKFRAME       0x00040000L
#define WS_GROUP            0x00020000L
#define WS_TABSTOP          0x00010000L
#define WS_MINIMIZEBOX      0x00020000L
#define WS_MAXIMIZEBOX      0x00010000L
#define WS_OVERLAPPEDWINDOW (WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX)
#define WS_POPUPWINDOW      (WS_POPUP | WS_BORDER | WS_SYSMENU)
#define WS_CHILDWINDOW      (WS_CHILD)

#define WS_EX_DLGMODALFRAME 0x00000001L
#define WS_EX_NOPARENTNOTIFY 0x00000004L
#define WS_EX_TOPMOST       0x00000008L
#define WS_EX_ACCEPTFILES   0x00000010L
#define WS_EX_TRANSPARENT   0x00000020L
#define WS_EX_TOOLWINDOW    0x00000080L
#define WS_EX_WINDOWEDGE    0x00000100L
#define WS_EX_CLIENTEDGE    0x00000200L
#define WS_EX_CONTEXTHELP   0x00000400L
#define WS_EX_APPWINDOW     0x00040000L

#define GWL_WNDPROC         (-4)
#define GWL_HINSTANCE       (-6)
#define GWL_HWNDPARENT      (-8)
#define GWL_STYLE           (-16)
#define GWL_EXSTYLE         (-20)
#define GWL_USERDATA        (-21)
#define GWL_ID              (-12)
#define DWL_MSGRESULT       0
#define DWL_DLGPROC         4
#define DWL_USER            8

/* ShowWindow Commands */
#define SW_HIDE             0
#define SW_SHOWNORMAL       1
#define SW_NORMAL           1
#define SW_SHOWMINIMIZED    2
#define SW_SHOWMAXIMIZED    3
#define SW_MAXIMIZE         3
#define SW_SHOWNOACTIVATE   4
#define SW_SHOW             5
#define SW_MINIMIZE         6
#define SW_SHOWMINNOACTIVE  7
#define SW_SHOWNA           8
#define SW_RESTORE          9
#define SW_SHOWDEFAULT      10
#define SW_FORCEMINIMIZE    11

/* SetWindowPos Flags & HWND placement constants */
#define SWP_NOSIZE          0x0001
#define SWP_NOMOVE          0x0002
#define SWP_NOZORDER        0x0004
#define SWP_NOREDRAW        0x0008
#define SWP_NOACTIVATE      0x0010
#define SWP_FRAMECHANGED    0x0020
#define SWP_SHOWWINDOW      0x0040
#define SWP_HIDEWINDOW      0x0080
#define SWP_NOCOPYBITS      0x0100
#define SWP_NOOWNERZORDER   0x0200
#define SWP_NOSENDCHANGING  0x0400

#define HWND_TOP            ((HWND)(intptr_t)0)
#define HWND_BOTTOM         ((HWND)(intptr_t)1)
#define HWND_TOPMOST        ((HWND)(intptr_t)-1)
#define HWND_NOTOPMOST      ((HWND)(intptr_t)-2)

/* Windows Messages */
#define WM_NULL             0x0000
#define WM_CREATE           0x0001
#define WM_DESTROY          0x0002
#define WM_MOVE             0x0003
#define WM_SIZE             0x0005
#define WM_ACTIVATE         0x0006
#define WM_SETFOCUS         0x0007
#define WM_KILLFOCUS        0x0008
#define WM_ENABLE           0x000A
#define WM_SETREDRAW        0x000B
#define WM_SETTEXT          0x000C
#define WM_GETTEXT          0x000D
#define WM_GETTEXTLENGTH    0x000E
#define WM_PAINT            0x000F
#define WM_CLOSE            0x0010
#define WM_QUERYENDSESSION  0x0011
#define WM_QUIT             0x0012
#define WM_QUERYOPEN        0x0013
#define WM_ERASEBKGND       0x0014
#define WM_SYSCOLORCHANGE   0x0015
#define WM_SHOWWINDOW       0x0018
#define WM_ACTIVATEAPP      0x001C
#define WM_CANCELMODE       0x001F
#define WM_SETCURSOR        0x0020
#define WM_MOUSEACTIVATE    0x0021
#define WM_DRAWITEM         0x002B
#define WM_MEASUREITEM      0x002C
#define WM_DELETEITEM       0x002D
#define WM_VKEYTOITEM       0x002E
#define WM_CHARTOITEM       0x002F
#define WM_SETFONT          0x0030
#define WM_GETFONT          0x0031
#define WM_WINDOWPOSCHANGING 0x0046
#define WM_WINDOWPOSCHANGED 0x0047
#define WM_NOTIFY           0x004E
#define WM_NCCREATE         0x0081
#define WM_NCDESTROY        0x0082
#define WM_NCCALCSIZE       0x0083
#define WM_NCHITTEST        0x0084
#define WM_NCPAINT          0x0085
#define WM_NCACTIVATE       0x0086
#define WM_KEYDOWN          0x0100
#define WM_KEYUP            0x0101
#define WM_CHAR             0x0102
#define WM_DEADCHAR         0x0103
#define WM_SYSKEYDOWN       0x0104
#define WM_SYSKEYUP         0x0105
#define WM_SYSCHAR          0x0106
#define WM_INITDIALOG       0x0110
#define WM_COMMAND          0x0111
#define WM_SYSCOMMAND       0x0112
#define WM_TIMER            0x0113
#define WM_HSCROLL          0x0114
#define WM_VSCROLL          0x0115
#define WM_INITMENU         0x0116
#define WM_INITMENUPOPUP    0x0117
#define WM_MENUSELECT       0x011F
#define WM_MENUCHAR         0x0120
#define WM_ENTERIDLE        0x0121
#define WM_MOUSEMOVE        0x0200
#define WM_LBUTTONDOWN      0x0201
#define WM_LBUTTONUP        0x0202
#define WM_LBUTTONDBLCLK    0x0203
#define WM_RBUTTONDOWN      0x0204
#define WM_RBUTTONUP        0x0205
#define WM_RBUTTONDBLCLK    0x0206
#define WM_MBUTTONDOWN      0x0207
#define WM_MBUTTONUP        0x0208
#define WM_MBUTTONDBLCLK    0x0209
#define WM_MOUSEWHEEL       0x020A
#define WM_PALETTECHANGED   0x0311
#define WM_PALETTEISCHANGING 0x0310
#define WM_QUERYNEWPALETTE  0x030F
#define WM_USER             0x0400

/* PeekMessage Options */
#define PM_NOREMOVE         0x0000
#define PM_REMOVE           0x0001
#define PM_NOYIELD          0x0002

/* Virtual Keys */
#define VK_LBUTTON          0x01
#define VK_RBUTTON          0x02
#define VK_CANCEL           0x03
#define VK_MBUTTON          0x04
#define VK_BACK             0x08
#define VK_TAB              0x09
#define VK_CLEAR            0x0C
#define VK_RETURN           0x0D
#define VK_SHIFT            0x10
#define VK_CONTROL          0x11
#define VK_MENU             0x12
#define VK_PAUSE            0x13
#define VK_CAPITAL          0x14
#define VK_ESCAPE           0x1B
#define VK_SPACE            0x20
#define VK_PRIOR            0x21
#define VK_NEXT             0x22
#define VK_END              0x23
#define VK_HOME             0x24
#define VK_LEFT             0x25
#define VK_UP               0x26
#define VK_RIGHT            0x27
#define VK_DOWN             0x28
#define VK_SELECT           0x29
#define VK_PRINT            0x2A
#define VK_EXECUTE          0x2B
#define VK_SNAPSHOT         0x2C
#define VK_INSERT           0x2D
#define VK_DELETE           0x2E
#define VK_HELP             0x2F
#define VK_NUMPAD0          0x60
#define VK_NUMPAD1          0x61
#define VK_NUMPAD2          0x62
#define VK_NUMPAD3          0x63
#define VK_NUMPAD4          0x64
#define VK_NUMPAD5          0x65
#define VK_NUMPAD6          0x66
#define VK_NUMPAD7          0x67
#define VK_NUMPAD8          0x68
#define VK_NUMPAD9          0x69
#define VK_MULTIPLY         0x6A
#define VK_ADD              0x6B
#define VK_SEPARATOR        0x6C
#define VK_SUBTRACT         0x6D
#define VK_DECIMAL          0x6E
#define VK_DIVIDE           0x6F
#define VK_F1               0x70
#define VK_F2               0x71
#define VK_F3               0x72
#define VK_F4               0x73
#define VK_F5               0x74
#define VK_F6               0x75
#define VK_F7               0x76
#define VK_F8               0x77
#define VK_F9               0x78
#define VK_F10              0x79
#define VK_F11              0x7A
#define VK_F12              0x7B
#define VK_NUMLOCK          0x90
#define VK_SCROLL           0x91
#define VK_LSHIFT           0xA0
#define VK_RSHIFT           0xA1
#define VK_LCONTROL         0xA2
#define VK_RCONTROL         0xA3
#define VK_LMENU            0xA4
#define VK_RMENU            0xA5

/* Mouse Keys (wParam for mouse messages) */
#define MK_LBUTTON          0x0001
#define MK_RBUTTON          0x0002
#define MK_SHIFT            0x0004
#define MK_CONTROL          0x0008
#define MK_MBUTTON          0x0010

/* GDI Stock Objects */
#define WHITE_BRUSH         0
#define LTGRAY_BRUSH        1
#define GRAY_BRUSH          2
#define DKGRAY_BRUSH        3
#define BLACK_BRUSH         4
#define NULL_BRUSH          5
#define HOLLOW_BRUSH        NULL_BRUSH
#define WHITE_PEN           6
#define BLACK_PEN           7
#define NULL_PEN            8
#define OEM_FIXED_FONT      10
#define ANSI_FIXED_FONT     11
#define ANSI_VAR_FONT       12
#define SYSTEM_FONT         13
#define DEVICE_DEFAULT_FONT 14
#define DEFAULT_PALETTE     15
#define SYSTEM_FIXED_FONT   16
#define DEFAULT_GUI_FONT    17

/* GDI Raster Operations (Ternary) */
#define SRCCOPY             0x00CC0020L
#define SRCPAINT            0x00EE0086L
#define SRCAND              0x008800C6L
#define SRCINVERT           0x00660046L
#define SRCERASE            0x00440328L
#define NOTSRCCOPY          0x00330008L
#define NOTSRCERASE         0x001100A6L
#define MERGECOPY           0x00C000CAL
#define MERGEPAINT          0x00BB0226L
#define PATCOPY             0x00F00021L
#define PATPAINT            0x00FB0A09L
#define PATINVERT           0x005A0049L
#define DSTINVERT           0x00550009L
#define BLACKNESS           0x00000042L
#define WHITENESS           0x00FF0062L

/* GDI Binary Raster Ops (ROP2) */
#define R2_BLACK            1
#define R2_NOTMERGEPEN      2
#define R2_MASKNOTPEN       3
#define R2_NOTCOPYPEN       4
#define R2_MASKPENNOT       5
#define R2_NOT              6
#define R2_XORPEN           7
#define R2_NOTXORPEN        8
#define R2_NOP              9
#define R2_MERGENOTPEN      10
#define R2_COPYPEN          11
#define R2_MERGEPENNOT      12
#define R2_MERGEPEN         13
#define R2_WHITE            14

/* GDI Background & Draw Modes */
#define TRANSPARENT         1
#define OPAQUE              2
#define BKMODE_LAST         2

#define MM_TEXT             1
#define MM_LOMETRIC         2
#define MM_HIMETRIC         3
#define MM_LOENGLISH        4
#define MM_HIENGLISH        5
#define MM_TWIPS            6
#define MM_ISOTROPIC        7
#define MM_ANISOTROPIC      8

/* GDI Text Alignment & DrawText Flags */
#define TA_NOUPDATECP       0
#define TA_UPDATECP         1
#define TA_LEFT             0
#define TA_RIGHT            2
#define TA_CENTER           6
#define TA_TOP              0
#define TA_BOTTOM           8
#define TA_BASELINE         24

#define DT_TOP              0x00000000
#define DT_LEFT             0x00000000
#define DT_CENTER           0x00000001
#define DT_RIGHT            0x00000002
#define DT_VCENTER          0x00000004
#define DT_BOTTOM           0x00000008
#define DT_WORDBREAK        0x00000010
#define DT_SINGLELINE       0x00000020
#define DT_EXPANDTABS       0x00000040
#define DT_TABSTOP          0x00000080
#define DT_NOCLIP           0x00000100
#define DT_EXTERNALLEADING  0x00000200
#define DT_CALCRECT         0x00000400
#define DT_NOPREFIX         0x00000800
#define DT_INTERNAL         0x00001000

/* Pen & Brush Styles */
#define PS_SOLID            0
#define PS_DASH             1
#define PS_DOT              2
#define PS_DASHDOT          3
#define PS_DASHDOTDOT       4
#define PS_NULL             5
#define PS_INSIDEFRAME      6

#define BS_SOLID            0
#define BS_NULL             1
#define BS_HOLLOW           BS_NULL
#define BS_HATCHED          2
#define BS_PATTERN          3
#define BS_INDEXED          4
#define BS_DIBPATTERN       5
#define BS_DIBPATTERNPT     6
#define BS_PATTERN8X8       7
#define BS_DIBPATTERN8X8    8

/* DIB Constants */
#define BI_RGB              0L
#define BI_RLE8             1L
#define BI_RLE4             2L
#define BI_BITFIELDS        3L

#define DIB_RGB_COLORS      0
#define DIB_PAL_COLORS      1

/* DeviceCaps Constants */
#define HORZRES             8
#define VERTRES             10
#define BITSPIXEL           12
#define PLANES              14
#define NUMCOLORS           24
#define SIZEPALETTE         104
#define NUMRESERVED         106
#define COLORRES            108
#define RASTERCAPS          38
#define LOGPIXELSX          88
#define LOGPIXELSY          90

/* Scrollbar Constants */
#define SB_HORZ             0
#define SB_VERT             1
#define SB_CTL              2
#define SB_BOTH             3

#define SB_LINEUP           0
#define SB_LINELEFT         0
#define SB_LINEDOWN         1
#define SB_LINERIGHT        1
#define SB_PAGEUP           2
#define SB_PAGELEFT         2
#define SB_PAGEDOWN         3
#define SB_PAGERIGHT        3
#define SB_THUMBPOSITION    4
#define SB_THUMBTRACK       5
#define SB_TOP              6
#define SB_LEFT             6
#define SB_BOTTOM           7
#define SB_RIGHT            7
#define SB_ENDSCROLL        8

/* Dialog / Button / MessageBox Constants */
#define MB_OK               0x00000000L
#define MB_OKCANCEL         0x00000001L
#define MB_ABORTRETRYIGNORE 0x00000002L
#define MB_YESNOCANCEL      0x00000003L
#define MB_YESNO            0x00000004L
#define MB_RETRYCANCEL      0x00000005L
#define MB_ICONHAND         0x00000010L
#define MB_ICONQUESTION     0x00000020L
#define MB_ICONEXCLAMATION  0x00000030L
#define MB_ICONASTERISK     0x00000040L
#define MB_ICONWARNING      MB_ICONEXCLAMATION
#define MB_ICONERROR        MB_ICONHAND
#define MB_ICONINFORMATION  MB_ICONASTERISK
#define MB_ICONSTOP         MB_ICONHAND

#define IDOK                1
#define IDCANCEL            2
#define IDABORT             3
#define IDRETRY             4
#define IDIGNORE            5
#define IDYES               6
#define IDNO                7

#define BST_UNCHECKED       0x0000
#define BST_CHECKED         0x0001
#define BST_INDETERMINATE   0x0002

#define BS_PUSHBUTTON       0x00000000L
#define BS_DEFPUSHBUTTON    0x00000001L
#define BS_CHECKBOX         0x00000002L
#define BS_AUTOCHECKBOX     0x00000003L
#define BS_RADIOBUTTON      0x00000004L
#define BS_3STATE           0x00000005L
#define BS_AUTO3STATE       0x00000006L
#define BS_GROUPBOX         0x00000007L
#define BS_USERBUTTON       0x00000008L
#define BS_AUTORADIOBUTTON  0x00000009L

/* Menu Flags */
#define MF_BYCOMMAND        0x00000000L
#define MF_BYPOSITION       0x00000400L
#define MF_SEPARATOR        0x00000800L
#define MF_ENABLED          0x00000000L
#define MF_GRAYED           0x00000001L
#define MF_DISABLED         0x00000002L
#define MF_UNCHECKED        0x00000000L
#define MF_CHECKED          0x00000008L
#define MF_STRING           0x00000000L
#define MF_BITMAP           0x00000004L
#define MF_POPUP            0x00000010L
#define MF_MENUBARBREAK     0x00000020L
#define MF_MENUBREAK        0x00000040L

#define TPM_LEFTBUTTON      0x0000L
#define TPM_RIGHTBUTTON     0x0002L
#define TPM_LEFTALIGN       0x0000L
#define TPM_CENTERALIGN     0x0004L
#define TPM_RIGHTALIGN      0x0008L
#define TPM_TOPALIGN        0x0000L
#define TPM_VCENTERALIGN    0x0010L
#define TPM_BOTTOMALIGN     0x0020L
#define TPM_HORIZONTAL      0x0000L
#define TPM_VERTICAL        0x0040L
#define TPM_NONOTIFY        0x0080L
#define TPM_RETURNCMD       0x0100L

/* System Metrics */
#define SM_CXSCREEN         0
#define SM_CYSCREEN         1
#define SM_CXVSCROLL        2
#define SM_CYHSCROLL        3
#define SM_CYCAPTION        4
#define SM_CXBORDER         5
#define SM_CYBORDER         6
#define SM_CXDLGFRAME       7
#define SM_CYDLGFRAME       8
#define SM_CXHTHUMB         10
#define SM_CYVTHUMB         11
#define SM_CXICON           11
#define SM_CYICON           12
#define SM_CXCURSOR         13
#define SM_CYCURSOR         14
#define SM_CYMENU           15
#define SM_CXFULLSCREEN     16
#define SM_CYFULLSCREEN     17
#define SM_MOUSEPRESENT     19
#define SM_SWAPBUTTON       23
#define SM_CXDOUBLECLK      36
#define SM_CYDOUBLECLK      37
#define SM_CMOUSEBUTTONS    43
#define SM_CXEDGE           45
#define SM_CYEDGE           46

/* System Colors */
#define COLOR_SCROLLBAR         0
#define COLOR_BACKGROUND        1
#define COLOR_ACTIVECAPTION     2
#define COLOR_INACTIVECAPTION   3
#define COLOR_MENU              4
#define COLOR_WINDOW            5
#define COLOR_WINDOWFRAME       6
#define COLOR_MENUTEXT          7
#define COLOR_WINDOWTEXT        8
#define COLOR_CAPTIONTEXT       9
#define COLOR_ACTIVEBORDER      10
#define COLOR_INACTIVEBORDER    11
#define COLOR_APPWORKSPACE      12
#define COLOR_HIGHLIGHT         13
#define COLOR_HIGHLIGHTTEXT     14
#define COLOR_BTNFACE           15
#define COLOR_BTNSHADOW         16
#define COLOR_GRAYTEXT          17
#define COLOR_BTNTEXT           18
#define COLOR_INACTIVECAPTIONTEXT 19
#define COLOR_BTNHIGHLIGHT      20
#define COLOR_3DDKSHADOW        21
#define COLOR_3DLIGHT           22
#define COLOR_INFOTEXT          23
#define COLOR_INFOBK            24
#define COLOR_HOTLIGHT          26

/* File I/O & Mapping Constants */
#define GENERIC_READ        (0x80000000L)
#define GENERIC_WRITE       (0x40000000L)
#define GENERIC_EXECUTE     (0x20000000L)
#define GENERIC_ALL         (0x10000000L)

#define FILE_SHARE_READ     0x00000001
#define FILE_SHARE_WRITE    0x00000002
#define FILE_SHARE_DELETE   0x00000004

#define CREATE_NEW          1
#define CREATE_ALWAYS       2
#define OPEN_EXISTING       3
#define OPEN_ALWAYS         4
#define TRUNCATE_EXISTING   5

#define FILE_ATTRIBUTE_READONLY  0x00000001
#define FILE_ATTRIBUTE_HIDDEN    0x00000002
#define FILE_ATTRIBUTE_SYSTEM    0x00000004
#define FILE_ATTRIBUTE_DIRECTORY 0x00000010
#define FILE_ATTRIBUTE_ARCHIVE   0x00000020
#define FILE_ATTRIBUTE_NORMAL    0x00000080

#define FILE_BEGIN          0
#define FILE_CURRENT        1
#define FILE_END            2

#define INVALID_HANDLE_VALUE ((HANDLE)(intptr_t)-1)
#define INVALID_FILE_SIZE   ((DWORD)0xFFFFFFFF)
#define INVALID_SET_FILE_POINTER ((DWORD)-1)

#define DRIVE_UNKNOWN       0
#define DRIVE_NO_ROOT_DIR   1
#define DRIVE_REMOVABLE     2
#define DRIVE_FIXED         3
#define DRIVE_REMOTE        4
#define DRIVE_CDROM         5
#define DRIVE_RAMDISK       6

#define STD_INPUT_HANDLE    ((DWORD)-10)
#define STD_OUTPUT_HANDLE   ((DWORD)-11)
#define STD_ERROR_HANDLE    ((DWORD)-12)

#define PAGE_NOACCESS          0x01
#define PAGE_READONLY          0x02
#define PAGE_READWRITE         0x04
#define PAGE_WRITECOPY         0x08
#define PAGE_EXECUTE           0x10
#define PAGE_EXECUTE_READ      0x20
#define PAGE_EXECUTE_READWRITE 0x40

#define FILE_MAP_COPY       0x0001
#define FILE_MAP_WRITE      0x0002
#define FILE_MAP_READ       0x0004
#define FILE_MAP_ALL_ACCESS 0x001F

#define GMEM_FIXED          0x0000
#define GMEM_MOVEABLE       0x0002
#define GMEM_NOCOMPACT      0x0010
#define GMEM_NODISCARD      0x0020
#define GMEM_ZEROINIT       0x0040
#define GMEM_MODIFY         0x0080
#define GMEM_DISCARDABLE    0x0100
#define GMEM_NOT_BANKED     0x1000
#define GMEM_SHARE          0x2000
#define GMEM_DDESHARE       0x2000
#define GMEM_NOTIFY         0x4000
#define GMEM_LOWER          GMEM_NOT_BANKED
#define GMEM_VALID_FLAGS    0x7F72
#define GMEM_INVALID_HANDLE 0x8000
#define GHND                (GMEM_MOVEABLE | GMEM_ZEROINIT)
#define GPTR                (GMEM_FIXED | GMEM_ZEROINIT)

#define MEM_COMMIT          0x1000
#define MEM_RESERVE         0x2000
#define MEM_DECOMMIT        0x4000
#define MEM_RELEASE         0x8000
#define MEM_FREE            0x10000

/* Registry Constants & Errors */
#define HKEY_CLASSES_ROOT   ((HKEY)(intptr_t)0x80000000)
#define HKEY_CURRENT_USER   ((HKEY)(intptr_t)0x80000001)
#define HKEY_LOCAL_MACHINE  ((HKEY)(intptr_t)0x80000002)
#define HKEY_USERS          ((HKEY)(intptr_t)0x80000003)

#define KEY_QUERY_VALUE     0x0001
#define KEY_SET_VALUE       0x0002
#define KEY_CREATE_SUB_KEY  0x0004
#define KEY_ENUMERATE_SUB_KEYS 0x0008
#define KEY_NOTIFY          0x0010
#define KEY_CREATE_LINK     0x0020
#define KEY_READ            0x00020019
#define KEY_WRITE           0x00020006
#define KEY_EXECUTE         0x00020019
#define KEY_ALL_ACCESS      0x000F003F

#define REG_NONE            0
#define REG_SZ              1
#define REG_EXPAND_SZ       2
#define REG_BINARY          3
#define REG_DWORD           4
#define REG_DWORD_LITTLE_ENDIAN 4
#define REG_DWORD_BIG_ENDIAN 5

#define ERROR_SUCCESS           0L
#define ERROR_FILE_NOT_FOUND    2L
#define ERROR_PATH_NOT_FOUND    3L
#define ERROR_ACCESS_DENIED     5L
#define ERROR_INVALID_HANDLE    6L
#define ERROR_NOT_ENOUGH_MEMORY 8L
#define ERROR_INVALID_PARAMETER 87L
#define ERROR_MORE_DATA         234L

/* WinMM / Timer / MMIO Constants */
#define TIME_ONESHOT        0x0000
#define TIME_PERIODIC       0x0001
#define TIME_CALLBACK_FUNCTION 0x0000
#define TIME_CALLBACK_EVENT_SET 0x0010

#define MMIO_READ           0x00000000
#define MMIO_WRITE          0x00000001
#define MMIO_READWRITE      0x00000002
#define MMIO_CREATE         0x00001000
#define MMIO_DELETE         0x00000200
#define MMIO_ALLOCBUF       0x00010000
#define MMIO_FINDCHUNK      0x00000010
#define MMIO_FINDRIFF       0x00000020
#define MMIO_FINDLIST       0x00000040
#define MMIO_DIRTY          0x10000000

#define mmioFOURCC(ch0, ch1, ch2, ch3) \
    ((DWORD)(BYTE)(ch0) | ((DWORD)(BYTE)(ch1) << 8) | \
    ((DWORD)(BYTE)(ch2) << 16) | ((DWORD)(BYTE)(ch3) << 24))

#define RGB(r,g,b) ((COLORREF)(((BYTE)(r)|((WORD)((BYTE)(g))<<8))|(((DWORD)(BYTE)(b))<<16)))
#define GetRValue(rgb) ((BYTE)(rgb))
#define GetGValue(rgb) ((BYTE)(((WORD)(rgb)) >> 8))
#define GetBValue(rgb) ((BYTE)((rgb)>>16))
#define PALETTERGB(r,g,b) (0x02000000 | RGB(r,g,b))
#define PALETTEINDEX(i)   ((COLORREF)(0x01000000 | (DWORD)(WORD)(i)))

#define LOWORD(l) ((WORD)(((DWORD_PTR)(l)) & 0xffff))
#define HIWORD(l) ((WORD)((((DWORD_PTR)(l)) >> 16) & 0xffff))
#define LOBYTE(w) ((BYTE)(((DWORD_PTR)(w)) & 0xff))
#define HIBYTE(w) ((BYTE)((((DWORD_PTR)(w)) >> 8) & 0xff))

#define MAKEINTRESOURCEA(i) ((LPSTR)((ULONG_PTR)((WORD)(i))))

typedef struct _LIST_ENTRY {
    struct _LIST_ENTRY *Flink;
    struct _LIST_ENTRY *Blink;
} LIST_ENTRY, _LIST_ENTRY;

typedef struct _FLOATING_SAVE_AREA {
    uint32_t ControlWord;
    uint32_t StatusWord;
    uint32_t TagWord;
    uint32_t ErrorOffset;
    uint32_t ErrorSelector;
    uint32_t DataOffset;
    uint32_t DataSelector;
    uint8_t  RegisterArea[80];
    uint32_t Cr0NpxState;
} FLOATING_SAVE_AREA;

typedef void* PEXCEPTION_RECORD;
typedef void* PCONTEXT;
typedef void* PRTL_CRITICAL_SECTION_DEBUG;
typedef void* PRTL_CRITICAL_SECTION;

typedef struct _EXCEPTION_POINTERS {
    PEXCEPTION_RECORD ExceptionRecord;
    PCONTEXT          ContextRecord;
} EXCEPTION_POINTERS, *PEXCEPTION_POINTERS;

#endif /* WINDOWS_TYPES_H */

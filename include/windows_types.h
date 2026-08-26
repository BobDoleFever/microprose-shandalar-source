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
typedef void*     PVOID;
typedef void*     HANDLE;
typedef void*     HWND;
typedef void*     HDC;
typedef void*     HINSTANCE;
typedef void*     HBITMAP;
typedef void*     HPALETTE;
typedef void*     HMENU;
typedef void*     HACCEL;
typedef uint32_t  MMRESULT;
typedef void*     HPEN;
typedef void*     HBRUSH;
typedef void*     HFONT;
typedef void*     HGDIOBJ;
typedef void*     HRGN;
typedef void*     HICON;
typedef void*     HCURSOR;
typedef void*     HMODULE;
typedef uint16_t  ATOM;
typedef char*     LPSTR;
typedef const char* LPCSTR;
typedef uint8_t*  LPBYTE;
typedef int32_t   LRESULT;
typedef uint32_t  WPARAM;
typedef int32_t   LPARAM;
typedef uintptr_t ULONG_PTR;
typedef intptr_t  LONG_PTR;
typedef uintptr_t DWORD_PTR;
typedef intptr_t  INT_PTR;
typedef uintptr_t UINT_PTR;
typedef uint32_t  COLORREF;
typedef void*     LPOFNHOOKPROC;
typedef void*     LPOPENFILENAMEA;

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

#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif
typedef struct tagPOINT tagPOINT;
typedef struct tagPOINT {
    LONG x;
    LONG y;
} POINT, *PPOINT, *LPPOINT;

typedef struct tagRECT tagRECT;
typedef struct tagRECT {
    LONG left;
    LONG top;
    LONG right;
    LONG bottom;
} RECT, *PRECT, *LPRECT;

typedef struct tagSIZE tagSIZE;
typedef struct tagSIZE {
    LONG cx;
    LONG cy;
} SIZE, *PSIZE, *LPSIZE;

typedef struct tagPAINTSTRUCT tagPAINTSTRUCT;
typedef struct tagLOGFONTA tagLOGFONTA;
typedef struct tagMSG tagMSG;
typedef void (*_onexit_t)(void);
typedef void (*_func_4879)(void);

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

typedef struct tagPAINTSTRUCT {
    HDC  hdc;
    BOOL fErase;
    RECT rcPaint;
    BOOL fRestore;
    BOOL fIncUpdate;
    BYTE rgbReserved[32];
} PAINTSTRUCT, *PPAINTSTRUCT, *LPPAINTSTRUCT;

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

typedef struct tagMSG {
    HWND   hwnd;
    UINT   message;
    WPARAM wParam;
    LPARAM lParam;
    DWORD  time;
    POINT  pt;
} MSG, *PMSG, *LPMSG;

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

#endif /* WINDOWS_TYPES_H */

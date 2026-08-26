/*
 * Decompiled function: thunk_FUN_100337ea
 * Entry Point: 10001055
 * Size: 5 bytes
 */
#include "deckdll.h"


int32_t thunk_FUN_100337ea(HWND hwnd,uint32_t y,HWND param_3,int32_t arg_4)

{
  uint32_t uval_1;
  UINT UVar2;
  HDC hdc;
  int32_t uval_3;
  HWND pHStack_38;
  uint32_t uStack_34;
  HWND pHStack_30;
  int32_t uStack_2c;
  DWORD DStack_1c;
  HDC pHStack_18;
  DWORD DStack_14;
  DWORD DStack_10;
  HWND pHStack_c;
  DWORD DStack_8;
  
  if (y == 0x30f) {
    UnrealizeObject(DAT_10140990);
    hdc = GetDC(hwnd);
    SelectPalette(hdc,DAT_10140990,0);
    UVar2 = RealizePalette(hdc);
    if (UVar2 != 0) {
      InvalidateRect(hwnd,(RECT *)0x0,1);
    }
    ReleaseDC(hwnd,hdc);
    uval_3 = 1;
  }
  else if ((y < 0x310) || (0x311 < y)) {
    uval_3 = 0;
  }
  else {
    pHStack_c = param_3;
    if (hwnd != param_3) {
      DStack_14 = GetWindowThreadProcessId(param_3,&DStack_8);
      DStack_1c = GetWindowThreadProcessId(hwnd,&DStack_10);
      if (DStack_10 == DStack_8) {
        uval_1 = GetWindowLongA(hwnd,-0x10);
        if ((uval_1 & 0x40000000) == 0) {
          pHStack_18 = GetDC(hwnd);
          SelectPalette(pHStack_18,DAT_10140990,1);
          UVar2 = RealizePalette(pHStack_18);
          if (UVar2 != 0) {
            InvalidateRect(hwnd,(RECT *)0x0,1);
          }
          ReleaseDC(hwnd,pHStack_18);
        }
      }
      else {
        InvalidateRect(hwnd,(RECT *)0x0,1);
      }
    }
    if (y == 0x311) {
      pHStack_38 = hwnd;
      uStack_34 = y;
      pHStack_30 = param_3;
      uStack_2c = arg_4;
      EnumChildWindows(hwnd,(WNDENUMPROC)&LAB_1000114a,(LPARAM)&pHStack_38);
    }
    uval_3 = 0;
  }
  return uval_3;
}



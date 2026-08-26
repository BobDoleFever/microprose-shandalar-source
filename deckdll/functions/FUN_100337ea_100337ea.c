/*
 * Decompiled function: FUN_100337ea
 * Entry Point: 100337ea
 * Size: 421 bytes
 */
#include "deckdll.h"


int32_t FUN_100337ea(HWND hwnd,uint32_t y,HWND param_3,int32_t arg_4)

{
  uint32_t uval_1;
  UINT UVar2;
  HDC hdc;
  int32_t uval_3;
  HWND local_38;
  uint32_t local_34;
  HWND local_30;
  int32_t local_2c;
  DWORD local_1c;
  HDC local_18;
  DWORD local_14;
  DWORD local_10;
  HWND local_c;
  DWORD local_8;
  
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
    local_c = param_3;
    if (hwnd != param_3) {
      local_14 = GetWindowThreadProcessId(param_3,&local_8);
      local_1c = GetWindowThreadProcessId(hwnd,&local_10);
      if (local_10 == local_8) {
        uval_1 = GetWindowLongA(hwnd,-0x10);
        if ((uval_1 & 0x40000000) == 0) {
          local_18 = GetDC(hwnd);
          SelectPalette(local_18,DAT_10140990,1);
          UVar2 = RealizePalette(local_18);
          if (UVar2 != 0) {
            InvalidateRect(hwnd,(RECT *)0x0,1);
          }
          ReleaseDC(hwnd,local_18);
        }
      }
      else {
        InvalidateRect(hwnd,(RECT *)0x0,1);
      }
    }
    if (y == 0x311) {
      local_38 = hwnd;
      local_34 = y;
      local_30 = param_3;
      local_2c = arg_4;
      EnumChildWindows(hwnd,(WNDENUMPROC)&LAB_1000114a,(LPARAM)&local_38);
    }
    uval_3 = 0;
  }
  return uval_3;
}



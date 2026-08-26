/*
 * Decompiled function: FUN_004f5d1a
 * Entry Point: 004f5d1a
 * Size: 421 bytes
 */
#include "magic.h"


undefined4 FUN_004f5d1a(HWND hwnd,uint y,HWND param_3,undefined4 arg_4)

{
  uint uVar1;
  UINT UVar2;
  HDC hdc;
  undefined4 uVar3;
  HWND local_38;
  uint local_34;
  HWND local_30;
  undefined4 local_2c;
  DWORD local_1c;
  HDC local_18;
  DWORD local_14;
  DWORD local_10;
  HWND local_c;
  DWORD local_8;
  
  if (y == 0x30f) {
    UnrealizeObject(DAT_00680774);
    hdc = GetDC(hwnd);
    SelectPalette(hdc,DAT_00680774,0);
    UVar2 = RealizePalette(hdc);
    if (UVar2 != 0) {
      InvalidateRect(hwnd,(RECT *)0x0,1);
    }
    ReleaseDC(hwnd,hdc);
    uVar3 = 1;
  }
  else if ((y < 0x310) || (0x311 < y)) {
    uVar3 = 0;
  }
  else {
    local_c = param_3;
    if (hwnd != param_3) {
      local_14 = GetWindowThreadProcessId(param_3,&local_8);
      local_1c = GetWindowThreadProcessId(hwnd,&local_10);
      if (local_10 == local_8) {
        uVar1 = GetWindowLongA(hwnd,-0x10);
        if ((uVar1 & 0x40000000) == 0) {
          local_18 = GetDC(hwnd);
          SelectPalette(local_18,DAT_00680774,1);
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
      EnumChildWindows(hwnd,FUN_004f5ec4,(LPARAM)&local_38);
    }
    uVar3 = 0;
  }
  return uVar3;
}



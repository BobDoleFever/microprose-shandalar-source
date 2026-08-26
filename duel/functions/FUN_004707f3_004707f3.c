/*
 * Decompiled function: FUN_004707f3
 * Entry Point: 004707f3
 * Size: 387 bytes
 */
#include "duel.h"


undefined4
FUN_004707f3(undefined4 arg_1,int arg_2,undefined4 *arg_3,BITMAPINFO *arg_4,undefined4 *arg_5,
            undefined4 *arg_6,int *arg_7)

{
  undefined4 uVar1;
  HDC hdc;
  HBITMAP local_44;
  HDC local_3c;
  BITMAPINFO local_38;
  HGDIOBJ local_c;
  void *local_8;
  
  local_3c = (HDC)0x0;
  local_44 = (HBITMAP)0x0;
  local_8 = (void *)0x0;
  if ((arg_3 == (undefined4 *)0x0) || (arg_5 == (undefined4 *)0x0)) {
    uVar1 = 0;
  }
  else {
    if (arg_4 == (BITMAPINFO *)0x0) {
      arg_4 = &local_38;
    }
    hdc = GetDC((HWND)0x0);
    if (hdc != (HDC)0x0) {
      FUN_004707a4(hdc);
      local_3c = CreateCompatibleDC(hdc);
      if (local_3c != (HDC)0x0) {
        FUN_00491750((undefined4 *)arg_4,arg_1,arg_2);
        local_38.bmiHeader.biBitCount = 0x20;
        local_44 = CreateDIBSection(hdc,arg_4,0,&local_8,(HANDLE)0x0,0);
        local_c = SelectObject(local_3c,local_44);
        FUN_004707a4(local_3c);
      }
      ReleaseDC((HWND)0x0,hdc);
    }
    if (((local_3c == (HDC)0x0) || (local_44 == (HBITMAP)0x0)) || (local_8 == (void *)0x0)) {
      if (local_3c != (HDC)0x0) {
        DeleteDC(local_3c);
      }
      if (local_44 != (HBITMAP)0x0) {
        DeleteObject(local_44);
      }
      uVar1 = 0;
    }
    else {
      if (arg_3 != (undefined4 *)0x0) {
        *arg_3 = local_3c;
      }
      if (arg_5 != (undefined4 *)0x0) {
        *arg_5 = local_44;
      }
      if (arg_6 != (undefined4 *)0x0) {
        *arg_6 = local_c;
      }
      if (arg_7 != (int *)0x0) {
        *arg_7 = (int)local_8;
      }
      uVar1 = 1;
    }
  }
  return uVar1;
}



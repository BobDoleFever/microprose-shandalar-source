/*
 * Decompiled function: FUN_00479dac
 * Entry Point: 00479dac
 * Size: 147 bytes
 */
#include "magic.h"


int FUN_00479dac(HWND hwnd,int arg2)

{
  int iVar1;
  LONG LVar2;
  tagRECT local_18;
  int local_8;
  
  if (hwnd == (HWND)0x0) {
    iVar1 = 0;
  }
  else {
    LVar2 = GetWindowLongA(hwnd,4);
    local_8 = GetWindowLongA(hwnd,8);
    GetClientRect(hwnd,&local_18);
    if (arg2 < LVar2) {
      arg2 = LVar2;
    }
    if (local_8 < arg2) {
      arg2 = local_8;
    }
    iVar1 = (local_18.right * arg2) / ((local_8 - LVar2) + 1);
  }
  return iVar1;
}



/*
 * Decompiled function: FUN_00479d16
 * Entry Point: 00479d16
 * Size: 150 bytes
 */
#include "magic.h"


int FUN_00479d16(HWND hwnd,int arg2)

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
    if (arg2 < local_18.left) {
      arg2 = local_18.left;
    }
    if (local_18.right < arg2) {
      arg2 = local_18.right;
    }
    iVar1 = LVar2 + (((local_8 - LVar2) + 1) * arg2) / local_18.right;
  }
  return iVar1;
}



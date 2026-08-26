/*
 * Decompiled function: FUN_0048644e
 * Entry Point: 0048644e
 * Size: 99 bytes
 */
#include "duel.h"


undefined4 FUN_0048644e(HWND hwnd)

{
  undefined4 uVar1;
  LONG arg1;
  LONG arg2;
  
  if (hwnd == (HWND)0x0) {
    uVar1 = 0xffffffff;
  }
  else {
    arg1 = GetWindowLongA(hwnd,0);
    arg2 = GetWindowLongA(hwnd,4);
    uVar1 = FUN_00447184(arg1,arg2);
  }
  return uVar1;
}



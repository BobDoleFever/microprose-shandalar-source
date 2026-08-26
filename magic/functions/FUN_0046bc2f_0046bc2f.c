/*
 * Decompiled function: FUN_0046bc2f
 * Entry Point: 0046bc2f
 * Size: 99 bytes
 */
#include "magic.h"


undefined4 FUN_0046bc2f(HWND hwnd)

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
    uVar1 = Ai_Subsystem_004b5cbb(arg1,arg2);
  }
  return uVar1;
}



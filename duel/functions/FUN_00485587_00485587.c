/*
 * Decompiled function: FUN_00485587
 * Entry Point: 00485587
 * Size: 114 bytes
 */
#include "duel.h"


int FUN_00485587(HWND hwnd)

{
  LONG arg1;
  LONG arg2;
  uint uVar1;
  uint uVar2;
  
  arg1 = GetWindowLongA(hwnd,0);
  arg2 = GetWindowLongA(hwnd,4);
  uVar1 = FUN_00447184(arg1,arg2);
  uVar2 = (int)uVar1 >> 0x1f;
  return (arg2 % 3) * 3 + (((uVar1 ^ uVar2) - uVar2 & 3 ^ uVar2) - uVar2) * 2;
}



/*
 * Decompiled function: FUN_00486348
 * Entry Point: 00486348
 * Size: 125 bytes
 */
#include "duel.h"


undefined4 FUN_00486348(HWND hwnd,int *arg2)

{
  undefined4 uVar1;
  LONG LVar2;
  LONG LVar3;
  
  if ((hwnd == (HWND)0x0) || (arg2 == (int *)0x0)) {
    uVar1 = 0;
  }
  else {
    LVar2 = GetWindowLongA(hwnd,0);
    LVar3 = GetWindowLongA(hwnd,4);
    if ((*arg2 == LVar2) && (arg2[1] == LVar3)) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}



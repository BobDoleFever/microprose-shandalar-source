/*
 * Decompiled function: FUN_004863ca
 * Entry Point: 004863ca
 * Size: 127 bytes
 */
#include "duel.h"


undefined4 FUN_004863ca(HWND hwnd,int arg2)

{
  undefined4 uVar1;
  LONG arg1;
  LONG arg2_00;
  int iVar2;
  
  if ((hwnd == (HWND)0x0) || (arg2 < 0)) {
    uVar1 = 0;
  }
  else {
    arg1 = GetWindowLongA(hwnd,0);
    arg2_00 = GetWindowLongA(hwnd,4);
    iVar2 = FUN_00447184(arg1,arg2_00);
    if (iVar2 == arg2) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}



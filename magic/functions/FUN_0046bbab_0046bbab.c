/*
 * Decompiled function: FUN_0046bbab
 * Entry Point: 0046bbab
 * Size: 127 bytes
 */
#include "magic.h"


undefined4 FUN_0046bbab(HWND hwnd,int arg2)

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
    iVar2 = Ai_Subsystem_004b5cbb(arg1,arg2_00);
    if (iVar2 == arg2) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}



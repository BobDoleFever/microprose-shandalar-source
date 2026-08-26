/*
 * Decompiled function: FUN_004869bd
 * Entry Point: 004869bd
 * Size: 135 bytes
 */
#include "duel.h"


undefined4 FUN_004869bd(WPARAM arg_1,int y,int width,int height)

{
  undefined4 uVar1;
  int iVar2;
  
  if (arg_1 == 0xffffffff) {
    uVar1 = 0;
  }
  else {
    iVar2 = FUN_00486861(arg_1,y,width,height);
    if (iVar2 == 0) {
      FUN_00486a4e(arg_1,y);
      iVar2 = FUN_004864e0(arg_1,y,width,height);
      if (iVar2 == 0) {
        uVar1 = 0;
      }
      else {
        uVar1 = 1;
      }
    }
    else {
      uVar1 = 1;
    }
  }
  return uVar1;
}



/*
 * Decompiled function: FUN_00438bf0
 * Entry Point: 00438bf0
 * Size: 130 bytes
 */
#include "duel.h"


undefined4 FUN_00438bf0(int arg1,int arg2)

{
  undefined4 uVar1;
  int iVar2;
  
  if (arg1 == -1) {
    uVar1 = 0;
  }
  else if (*(int *)(&DAT_00618b04 + arg1 * 0x98) < 2) {
    if (*(int *)(&DAT_0060d5b0 + arg1 * 0x10) == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  else {
    iVar2 = FUN_00439172(arg1,arg2);
    if (iVar2 == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  return uVar1;
}



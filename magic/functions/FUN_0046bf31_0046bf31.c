/*
 * Decompiled function: FUN_0046bf31
 * Entry Point: 0046bf31
 * Size: 130 bytes
 */
#include "magic.h"


undefined4 FUN_0046bf31(int arg1,int arg2)

{
  undefined4 uVar1;
  int iVar2;
  
  if (arg1 == -1) {
    uVar1 = 0;
  }
  else if (*(int *)(&DAT_006b30b4 + arg1 * 0x98) < 2) {
    if (*(int *)(&DAT_00696a20 + arg1 * 0x10) == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  else {
    iVar2 = FUN_0046c4b5(arg1,arg2);
    if (iVar2 == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  return uVar1;
}



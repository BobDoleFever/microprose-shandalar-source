/*
 * Decompiled function: FUN_00447184
 * Entry Point: 00447184
 * Size: 110 bytes
 */
#include "duel.h"


undefined4 FUN_00447184(int arg1,int arg2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_00446de2(arg1,arg2);
  if (iVar1 == 0) {
    iVar1 = FUN_00447114(arg1,arg2);
    if (iVar1 == -1) {
      uVar2 = 0xffffffff;
    }
    else {
      uVar2 = *(undefined4 *)(&DAT_004ff590 + iVar1 * 0x34);
    }
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}



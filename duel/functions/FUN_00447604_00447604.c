/*
 * Decompiled function: FUN_00447604
 * Entry Point: 00447604
 * Size: 108 bytes
 */
#include "duel.h"


undefined1 FUN_00447604(int arg1,int arg2)

{
  undefined1 uVar1;
  int iVar2;
  
  iVar2 = FUN_00446de2(arg1,arg2);
  if (iVar2 == 0) {
    iVar2 = FUN_00447114(arg1,arg2);
    if (iVar2 == -1) {
      uVar1 = 0;
    }
    else {
      uVar1 = (&DAT_004ff594)[iVar2 * 0x34];
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



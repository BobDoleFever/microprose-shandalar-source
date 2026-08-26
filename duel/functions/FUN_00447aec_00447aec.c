/*
 * Decompiled function: FUN_00447aec
 * Entry Point: 00447aec
 * Size: 115 bytes
 */
#include "duel.h"


uint FUN_00447aec(int arg1,int arg2)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_00446de2(arg1,arg2);
  if (iVar1 == 0) {
    iVar1 = FUN_00447114(arg1,arg2);
    if (iVar1 == -1) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(uint *)(&DAT_004ff5a8 + iVar1 * 0x34) & 0x1000;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



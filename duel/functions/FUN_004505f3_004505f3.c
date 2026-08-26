/*
 * Decompiled function: FUN_004505f3
 * Entry Point: 004505f3
 * Size: 106 bytes
 */
#include "duel.h"


uint FUN_004505f3(int arg1,int arg2)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = Mem_AllocOrFree_004506f6(arg1,arg2);
  if (iVar1 == -1) {
    uVar2 = 0;
  }
  else if (((&DAT_004ff5a8)[iVar1 * 0x34] & 0x20) == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = Mem_AllocOrFree_004505c4(arg1,arg2);
    uVar2 = uVar2 & 0xf;
  }
  return uVar2;
}



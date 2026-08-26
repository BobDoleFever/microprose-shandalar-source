/*
 * Decompiled function: FUN_00450725
 * Entry Point: 00450725
 * Size: 106 bytes
 */
#include "duel.h"


undefined4 FUN_00450725(int arg1,int arg2)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((arg1 == -1) || (arg2 == -1)) {
    uVar1 = 0xffffffff;
  }
  else {
    iVar2 = Mem_AllocOrFree_004506f6(arg1,arg2);
    if (iVar2 == -1) {
      uVar1 = 0xffffffff;
    }
    else {
      uVar1 = *(undefined4 *)(&DAT_004ff590 + iVar2 * 0x34);
    }
  }
  return uVar1;
}



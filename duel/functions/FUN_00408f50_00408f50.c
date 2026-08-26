/*
 * Decompiled function: FUN_00408f50
 * Entry Point: 00408f50
 * Size: 182 bytes
 */
#include "duel.h"


undefined4 FUN_00408f50(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (arg_3 == 0x71) {
      iVar3 = arg_1;
      iVar4 = arg_2;
      iVar2 = FUN_004af74c(arg_1,arg_2,4);
      Mem_AllocOrFree_004afd1c
                (1 - arg_1,*(int *)(&DAT_0068ef50 + iVar2 * 4 + arg_1 * 0x20),iVar3,iVar4);
      iVar3 = arg_1;
      iVar4 = arg_2;
      iVar2 = FUN_004af74c(arg_1,arg_2,4);
      Mem_AllocOrFree_004afd1c
                (arg_1,(*(int *)(&DAT_0068ef50 + iVar2 * 4 + arg_1 * 0x20) + 1) / 2,iVar3,iVar4);
      FUN_0046e571(arg_1,arg_2,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}



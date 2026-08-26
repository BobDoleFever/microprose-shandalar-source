/*
 * Decompiled function: FUN_004fe901
 * Entry Point: 004fe901
 * Size: 181 bytes
 */
#include "magic.h"


undefined4 FUN_004fe901(int arg_1,int arg_2,int arg_3)

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
      iVar2 = FUN_0041d963(arg_1,arg_2,4);
      Mem_AllocOrFree_0041df33
                (1 - arg_1,*(int *)(&DAT_0063ee30 + iVar2 * 4 + arg_1 * 0x20),iVar3,iVar4);
      iVar3 = arg_1;
      iVar4 = arg_2;
      iVar2 = FUN_0041d963(arg_1,arg_2,4);
      Mem_AllocOrFree_0041df33
                (arg_1,(*(int *)(&DAT_0063ee30 + iVar2 * 4 + arg_1 * 0x20) + 1) / 2,iVar3,iVar4);
      Pic_Subsystem_0044867e(arg_1,arg_2,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: FUN_0041fec7
 * Entry Point: 0041fec7
 * Size: 309 bytes
 */
#include "magic.h"


undefined4 FUN_0041fec7(int arg_1,int arg_2,int arg_3,int arg_4,char *str_5,int arg_6)

{
  size_t sVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int local_c;
  int local_8;
  
  sVar1 = strlen(str_5);
  uVar2 = Mem_AllocOrFree_00501721();
  if ((uVar2 & 7) == 0) {
    uVar3 = 0;
  }
  else {
    for (local_c = 0; local_c < arg_6; local_c = local_c + 1) {
      if (local_c < (int)sVar1) {
        iVar4 = FUN_0050f390(*(int *)(arg_1 + 0x20),str_5[local_c]);
      }
      else {
        iVar4 = FUN_0050f390(*(int *)(arg_1 + 0x20),' ');
      }
      arg_3 = arg_3 + iVar4;
    }
    if (local_c < (int)sVar1) {
      local_8 = FUN_0050f390(*(int *)(arg_1 + 0x20),str_5[arg_6]);
    }
    else {
      local_8 = FUN_0050f390(*(int *)(arg_1 + 0x20),' ');
    }
    iVar4 = Mem_AllocOrFree_0050f740(*(int *)(arg_1 + 0x20));
    iVar4 = arg_4 + iVar4 / 2;
    Surface_DrawLine((int *)arg_1,arg_3,iVar4 + -1,local_8 + arg_3,iVar4 + -1,arg_2);
    uVar3 = Surface_DrawLine((int *)arg_1,arg_3,iVar4,local_8 + arg_3,iVar4,arg_2);
  }
  return uVar3;
}



/*
 * Decompiled function: FUN_0041fffc
 * Entry Point: 0041fffc
 * Size: 595 bytes
 */
#include "magic.h"


undefined4 FUN_0041fffc(int arg_1,int *arg_2,int arg_3,int arg_4,char *str_5,int arg_6,int arg_7)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  size_t sVar6;
  int local_1c;
  int local_18;
  int local_14;
  int local_c;
  
  iVar1 = Ai_Util_004c3bc4(arg_3);
  local_18 = Ai_Util_004c3bc4(arg_4);
  iVar5 = *arg_2;
  iVar4 = iVar5;
  iVar2 = Ai_Util_004c3bc4((int)*(short *)(iVar5 + 6));
  iVar3 = Ai_Util_004c3bc4((int)*(short *)(iVar5 + 4));
  Sprite_DrawScaled((int *)arg_1,0,0,iVar3,iVar2,iVar4);
  local_14 = Ai_Util_004c3bc4((int)*(short *)(iVar5 + 4));
  iVar5 = arg_2[1];
  for (; local_14 < iVar1; local_14 = local_14 + iVar4) {
    iVar4 = iVar5;
    iVar2 = Ai_Util_004c3bc4((int)*(short *)(iVar5 + 6));
    iVar3 = Ai_Util_004c3bc4((int)*(short *)(iVar5 + 4));
    Sprite_DrawScaled((int *)arg_1,local_14,0,iVar3,iVar2,iVar4);
    iVar4 = Ai_Util_004c3bc4((int)*(short *)(iVar5 + 4));
  }
  iVar5 = arg_2[2];
  iVar2 = Ai_Util_004c3bc4((int)*(short *)(iVar5 + 4));
  iVar4 = iVar5;
  iVar3 = Ai_Util_004c3bc4((int)*(short *)(iVar5 + 6));
  iVar5 = Ai_Util_004c3bc4((int)*(short *)(iVar5 + 4));
  Sprite_DrawScaled((int *)arg_1,iVar1 - iVar2,0,iVar5,iVar3,iVar4);
  *(int *)(arg_1 + 0x20) = arg_6;
  Mem_AllocOrFree_0050f740(arg_6);
  local_1c = FUN_0050f440((int *)arg_1,str_5);
  while (iVar1 < local_1c) {
    sVar6 = strlen(str_5);
    str_5[sVar6 - 1] = '\0';
    local_1c = FUN_0050f440((int *)arg_1,str_5);
  }
  local_14 = 10;
  local_18 = local_18 / 2;
  local_c = 0x25;
  if (arg_7 == 1) {
    local_c = 0x67;
  }
  if (arg_7 == 2) {
    local_c = 0x67;
    local_18 = local_18 + 2;
    local_14 = 8;
  }
  if (arg_7 == 3) {
    local_c = 0xf0;
  }
  FUN_0040cfd5(arg_1,local_c,local_14,local_18);
  if (DAT_00538834 != 0) {
    FUN_0041fec7(arg_1,local_c,local_14,local_18,str_5,DAT_00538830);
  }
  return 0;
}



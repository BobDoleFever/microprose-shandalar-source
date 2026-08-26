/*
 * Decompiled function: Ai_CalcManaRequirement_004b32d1
 * Entry Point: 004b32d1
 * Size: 557 bytes
 */
#include "magic.h"


void Ai_CalcManaRequirement_004b32d1
               (undefined4 *arg_1,undefined4 *out_buffer,undefined4 *arg_3,undefined4 *arg_4,
               undefined4 *arg_5,int *arg_6,int *arg_7,int *arg_8,undefined4 *arg_9,
               undefined4 *arg_10)

{
  undefined4 uVar1;
  HBRUSH pHVar2;
  HPEN pHVar3;
  HGDIOBJ pvVar4;
  char local_10c [264];
  
  sprintf(local_10c,s__s_WINBK_QuestMana_pic_0052d260,&DAT_006b2e90);
  uVar1 = Pic_Load_00423833(local_10c);
  *arg_1 = uVar1;
  *out_buffer = 0x1000031;
  sprintf(local_10c,s__s_WINBK_QuestManaSelection_pic_0052d278,&DAT_006b2e90);
  uVar1 = Pic_Load_00423833(local_10c);
  *arg_3 = uVar1;
  sprintf(local_10c,s__s_QUESTMANA_Black_pic_0052d298,&DAT_006b2e90);
  uVar1 = Pic_Load_00423833(local_10c);
  arg_4[1] = uVar1;
  sprintf(local_10c,s__s_QUESTMANA_White_pic_0052d2b0,&DAT_006b2e90);
  uVar1 = Pic_Load_00423833(local_10c);
  arg_4[5] = uVar1;
  sprintf(local_10c,s__s_QUESTMANA_Green_pic_0052d2c8,&DAT_006b2e90);
  uVar1 = Pic_Load_00423833(local_10c);
  arg_4[3] = uVar1;
  sprintf(local_10c,s__s_QUESTMANA_Blue_pic_0052d2e0,&DAT_006b2e90);
  uVar1 = Pic_Load_00423833(local_10c);
  arg_4[2] = uVar1;
  sprintf(local_10c,s__s_QUESTMANA_Red_pic_0052d2f8,&DAT_006b2e90);
  uVar1 = Pic_Load_00423833(local_10c);
  arg_4[4] = uVar1;
  sprintf(local_10c,s__s_QUESTMANA_Gray_pic_0052d310,&DAT_006b2e90);
  uVar1 = Pic_Load_00423833(local_10c);
  *arg_4 = uVar1;
  *arg_5 = 0x1000031;
  pHVar2 = CreateSolidBrush(0x10000c6);
  *arg_6 = (int)pHVar2;
  pHVar3 = CreatePen(0,0,0x10000c2);
  *arg_7 = (int)pHVar3;
  pHVar3 = CreatePen(0,0,0x10000c8);
  *arg_8 = (int)pHVar3;
  *arg_9 = 0x1000031;
  *arg_10 = 0x10000bf;
  if (*arg_6 == 0) {
    pvVar4 = GetStockObject(2);
    *arg_6 = (int)pvVar4;
  }
  if (*arg_7 == 0) {
    pvVar4 = GetStockObject(6);
    *arg_7 = (int)pvVar4;
  }
  if (*arg_8 == 0) {
    pvVar4 = GetStockObject(7);
    *arg_8 = (int)pvVar4;
  }
  return;
}



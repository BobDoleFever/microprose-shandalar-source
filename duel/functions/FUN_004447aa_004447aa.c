/*
 * Decompiled function: FUN_004447aa
 * Entry Point: 004447aa
 * Size: 549 bytes
 */
#include "duel.h"


void FUN_004447aa(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4,
                 undefined4 *param_5,int *param_6,int *param_7,int *param_8,undefined4 *param_9,
                 undefined4 *param_10)

{
  undefined4 uVar1;
  HBRUSH pHVar2;
  HPEN pHVar3;
  HGDIOBJ pvVar4;
  char local_10c [264];
  
  _sprintf(local_10c,s__s_WINBK_QuestMana_pic_004f7d80,&DAT_006189a0);
  uVar1 = FUN_0043d713(local_10c);
  *param_1 = uVar1;
  *param_2 = 0x1000031;
  _sprintf(local_10c,s__s_WINBK_QuestManaSelection_pic_004f7d98,&DAT_006189a0);
  uVar1 = FUN_0043d713(local_10c);
  *param_3 = uVar1;
  _sprintf(local_10c,s__s_QUESTMANA_Black_pic_004f7db8,&DAT_006189a0);
  uVar1 = FUN_0043d713(local_10c);
  param_4[1] = uVar1;
  _sprintf(local_10c,s__s_QUESTMANA_White_pic_004f7dd0,&DAT_006189a0);
  uVar1 = FUN_0043d713(local_10c);
  param_4[5] = uVar1;
  _sprintf(local_10c,s__s_QUESTMANA_Green_pic_004f7de8,&DAT_006189a0);
  uVar1 = FUN_0043d713(local_10c);
  param_4[3] = uVar1;
  _sprintf(local_10c,s__s_QUESTMANA_Blue_pic_004f7e00,&DAT_006189a0);
  uVar1 = FUN_0043d713(local_10c);
  param_4[2] = uVar1;
  _sprintf(local_10c,s__s_QUESTMANA_Red_pic_004f7e18,&DAT_006189a0);
  uVar1 = FUN_0043d713(local_10c);
  param_4[4] = uVar1;
  _sprintf(local_10c,s__s_QUESTMANA_Gray_pic_004f7e30,&DAT_006189a0);
  uVar1 = FUN_0043d713(local_10c);
  *param_4 = uVar1;
  *param_5 = 0x1000031;
  pHVar2 = CreateSolidBrush(0x10000c6);
  *param_6 = (int)pHVar2;
  pHVar3 = CreatePen(0,0,0x10000c2);
  *param_7 = (int)pHVar3;
  pHVar3 = CreatePen(0,0,0x10000c8);
  *param_8 = (int)pHVar3;
  *param_9 = 0x1000031;
  *param_10 = 0x10000bf;
  if (*param_6 == 0) {
    pvVar4 = GetStockObject(2);
    *param_6 = (int)pvVar4;
  }
  if (*param_7 == 0) {
    pvVar4 = GetStockObject(6);
    *param_7 = (int)pvVar4;
  }
  if (*param_8 == 0) {
    pvVar4 = GetStockObject(7);
    *param_8 = (int)pvVar4;
  }
  return;
}



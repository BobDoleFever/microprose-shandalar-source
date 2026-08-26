/*
 * Decompiled function: Pic_Load_s_QUESTMANA_Black_004447aa
 * Entry Point: 004447aa
 * Size: 549 bytes
 */
#include "duel.h"


void Pic_Load_s_QUESTMANA_Black_004447aa
               (undefined4 *arg_1,undefined4 *out_buffer,undefined4 *arg_3,undefined4 *arg_4,
               undefined4 *arg_5,int *arg_6,int *arg_7,int *arg_8,undefined4 *arg_9,
               undefined4 *arg_10)

{
  undefined4 uVar1;
  HBRUSH pHVar2;
  HPEN pHVar3;
  HGDIOBJ pvVar4;
  char local_10c [264];
  
  _sprintf(local_10c,s__s_WINBK_QuestMana_pic_004f7d80,&DAT_006189a0);
  uVar1 = FUN_0043d713(local_10c);
  *arg_1 = uVar1;
  *out_buffer = 0x1000031;
  _sprintf(local_10c,s__s_WINBK_QuestManaSelection_pic_004f7d98,&DAT_006189a0);
  uVar1 = FUN_0043d713(local_10c);
  *arg_3 = uVar1;
  _sprintf(local_10c,s__s_QUESTMANA_Black_pic_004f7db8,&DAT_006189a0);
  uVar1 = FUN_0043d713(local_10c);
  arg_4[1] = uVar1;
  _sprintf(local_10c,s__s_QUESTMANA_White_pic_004f7dd0,&DAT_006189a0);
  uVar1 = FUN_0043d713(local_10c);
  arg_4[5] = uVar1;
  _sprintf(local_10c,s__s_QUESTMANA_Green_pic_004f7de8,&DAT_006189a0);
  uVar1 = FUN_0043d713(local_10c);
  arg_4[3] = uVar1;
  _sprintf(local_10c,s__s_QUESTMANA_Blue_pic_004f7e00,&DAT_006189a0);
  uVar1 = FUN_0043d713(local_10c);
  arg_4[2] = uVar1;
  _sprintf(local_10c,s__s_QUESTMANA_Red_pic_004f7e18,&DAT_006189a0);
  uVar1 = FUN_0043d713(local_10c);
  arg_4[4] = uVar1;
  _sprintf(local_10c,s__s_QUESTMANA_Gray_pic_004f7e30,&DAT_006189a0);
  uVar1 = FUN_0043d713(local_10c);
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



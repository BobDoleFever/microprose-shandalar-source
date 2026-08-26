/*
 * Decompiled function: FUN_0044565e
 * Entry Point: 0044565e
 * Size: 220 bytes
 */
#include "duel.h"


void FUN_0044565e(undefined4 *param_1,undefined4 *param_2,int *param_3,int *param_4,int *param_5,
                 undefined4 *param_6,undefined4 *param_7)

{
  undefined4 uVar1;
  HBRUSH pHVar2;
  HPEN pHVar3;
  HGDIOBJ pvVar4;
  char local_10c [264];
  
  _sprintf(local_10c,s__s_WINBK_ChangeText_pic_004f7e98,&DAT_006189a0);
  uVar1 = FUN_0043d713(local_10c);
  *param_1 = uVar1;
  *param_2 = 0x1000098;
  pHVar2 = CreateSolidBrush(0x1000076);
  *param_3 = (int)pHVar2;
  pHVar3 = CreatePen(0,0,0x10000b3);
  *param_4 = (int)pHVar3;
  pHVar3 = CreatePen(0,0,0x100004e);
  *param_5 = (int)pHVar3;
  *param_6 = 0x1000098;
  *param_7 = 0x10000bf;
  if (*param_3 == 0) {
    pvVar4 = GetStockObject(2);
    *param_3 = (int)pvVar4;
  }
  if (*param_4 == 0) {
    pvVar4 = GetStockObject(6);
    *param_4 = (int)pvVar4;
  }
  if (*param_5 == 0) {
    pvVar4 = GetStockObject(7);
    *param_5 = (int)pvVar4;
  }
  return;
}



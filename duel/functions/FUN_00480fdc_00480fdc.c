/*
 * Decompiled function: FUN_00480fdc
 * Entry Point: 00480fdc
 * Size: 229 bytes
 */
#include "duel.h"


void FUN_00480fdc(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,int *param_4,
                 int *param_5,int *param_6,undefined4 *param_7,undefined4 *param_8)

{
  undefined4 uVar1;
  HBRUSH pHVar2;
  HPEN pHVar3;
  HGDIOBJ pvVar4;
  char local_10c [264];
  
  _sprintf(local_10c,s__s_WINBK_Options_pic_004f9ec4,&DAT_006189a0);
  uVar1 = FUN_0043d713(local_10c);
  *param_1 = uVar1;
  *param_2 = 0x1000007;
  *param_3 = 0x1000001;
  pHVar2 = CreateSolidBrush(0x1000036);
  *param_4 = (int)pHVar2;
  pHVar3 = CreatePen(0,0,0x10000ba);
  *param_5 = (int)pHVar3;
  pHVar3 = CreatePen(0,0,0x1000016);
  *param_6 = (int)pHVar3;
  *param_7 = 0x1000001;
  *param_8 = 0x10000bf;
  if (*param_4 == 0) {
    pvVar4 = GetStockObject(2);
    *param_4 = (int)pvVar4;
  }
  if (*param_5 == 0) {
    pvVar4 = GetStockObject(6);
    *param_5 = (int)pvVar4;
  }
  if (*param_6 == 0) {
    pvVar4 = GetStockObject(7);
    *param_6 = (int)pvVar4;
  }
  return;
}



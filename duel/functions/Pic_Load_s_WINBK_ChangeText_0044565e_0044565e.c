/*
 * Decompiled function: Pic_Load_s_WINBK_ChangeText_0044565e
 * Entry Point: 0044565e
 * Size: 220 bytes
 */
#include "duel.h"


void Pic_Load_s_WINBK_ChangeText_0044565e
               (undefined4 *arg_1,undefined4 *out_buffer,int *arg_3,int *arg_4,int *arg_5,
               undefined4 *arg_6,undefined4 *arg_7)

{
  undefined4 uVar1;
  HBRUSH pHVar2;
  HPEN pHVar3;
  HGDIOBJ pvVar4;
  char local_10c [264];
  
  _sprintf(local_10c,s__s_WINBK_ChangeText_pic_004f7e98,&DAT_006189a0);
  uVar1 = FUN_0043d713(local_10c);
  *arg_1 = uVar1;
  *out_buffer = 0x1000098;
  pHVar2 = CreateSolidBrush(0x1000076);
  *arg_3 = (int)pHVar2;
  pHVar3 = CreatePen(0,0,0x10000b3);
  *arg_4 = (int)pHVar3;
  pHVar3 = CreatePen(0,0,0x100004e);
  *arg_5 = (int)pHVar3;
  *arg_6 = 0x1000098;
  *arg_7 = 0x10000bf;
  if (*arg_3 == 0) {
    pvVar4 = GetStockObject(2);
    *arg_3 = (int)pvVar4;
  }
  if (*arg_4 == 0) {
    pvVar4 = GetStockObject(6);
    *arg_4 = (int)pvVar4;
  }
  if (*arg_5 == 0) {
    pvVar4 = GetStockObject(7);
    *arg_5 = (int)pvVar4;
  }
  return;
}



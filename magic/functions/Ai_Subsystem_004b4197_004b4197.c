/*
 * Decompiled function: Ai_Subsystem_004b4197
 * Entry Point: 004b4197
 * Size: 221 bytes
 */
#include "magic.h"


void Ai_Subsystem_004b4197
               (undefined4 *arg_1,undefined4 *out_buffer,int *arg_3,int *arg_4,int *arg_5,
               undefined4 *arg_6,undefined4 *arg_7)

{
  undefined4 uVar1;
  HBRUSH pHVar2;
  HPEN pHVar3;
  HGDIOBJ pvVar4;
  char local_10c [264];
  
  sprintf(local_10c,s__s_WINBK_ChangeText_pic_0052d378,&DAT_006b2e90);
  uVar1 = Pic_Load_00423833(local_10c);
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



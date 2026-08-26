/*
 * Decompiled function: Ai_LoadEndDuelBackdrop
 * Entry Point: 004409b7
 * Size: 229 bytes
 */
#include "duel.h"


void Ai_LoadEndDuelBackdrop
               (undefined4 *arg_1,undefined4 *out_buffer,undefined4 *arg_3,int *arg_4,int *arg_5,
               int *arg_6,undefined4 *arg_7,undefined4 *arg_8)

{
  undefined4 uVar1;
  HBRUSH pHVar2;
  HPEN pHVar3;
  HGDIOBJ pvVar4;
  char local_10c [264];
  
  _sprintf(local_10c,s__s_WINBK_EndDuel_pic_004f7ce4,&DAT_006189a0);
  uVar1 = Pic_Load_00423833(local_10c);
  *arg_1 = uVar1;
  *out_buffer = 0x1000040;
  *arg_3 = 0x1000040;
  pHVar2 = CreateSolidBrush(0x100001a);
  *arg_4 = (int)pHVar2;
  pHVar3 = CreatePen(0,0,0x100008c);
  *arg_5 = (int)pHVar3;
  pHVar3 = CreatePen(0,0,0x1000001);
  *arg_6 = (int)pHVar3;
  *arg_7 = 0x1000040;
  *arg_8 = 0x10000bf;
  if (*arg_4 == 0) {
    pvVar4 = GetStockObject(2);
    *arg_4 = (int)pvVar4;
  }
  if (*arg_5 == 0) {
    pvVar4 = GetStockObject(6);
    *arg_5 = (int)pvVar4;
  }
  if (*arg_6 == 0) {
    pvVar4 = GetStockObject(7);
    *arg_6 = (int)pvVar4;
  }
  return;
}



/*
 * Decompiled function: FUN_0043eb81
 * Entry Point: 0043eb81
 * Size: 179 bytes
 */
#include "duel.h"


void FUN_0043eb81(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4,
                 undefined4 *param_5,undefined4 *param_6)

{
  undefined4 uVar1;
  char local_10c [264];
  
  _sprintf(local_10c,s__s_WINBK_StartDuel2_pic_004f7a40,&DAT_006189a0);
  uVar1 = FUN_0043d713(local_10c);
  *param_1 = uVar1;
  *param_2 = 0;
  _sprintf(local_10c,s__s_WINBK_StartDuelButtonNormal_p_004f7a58,&DAT_006189a0);
  uVar1 = FUN_0043d713(local_10c);
  *param_3 = uVar1;
  _sprintf(local_10c,s__s_WINBK_StartDuelButtonDepresse_004f7a7c,&DAT_006189a0);
  uVar1 = FUN_0043d713(local_10c);
  *param_4 = uVar1;
  *param_5 = 0x1000001;
  *param_6 = 0x10000bf;
  return;
}



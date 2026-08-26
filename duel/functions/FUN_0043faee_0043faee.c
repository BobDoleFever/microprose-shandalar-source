/*
 * Decompiled function: FUN_0043faee
 * Entry Point: 0043faee
 * Size: 224 bytes
 */
#include "duel.h"


void FUN_0043faee(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4,
                 undefined4 *param_5,undefined4 *param_6,undefined4 *param_7)

{
  undefined4 uVar1;
  char local_10c [264];
  
  _sprintf(local_10c,s__s_WINBK_StartDuel_pic_004f7bc4,&DAT_006189a0);
  uVar1 = FUN_0043d713(local_10c);
  *param_1 = uVar1;
  *param_2 = 0;
  _sprintf(local_10c,s__s_WINBK_StartDuelButtonNormal_p_004f7bdc,&DAT_006189a0);
  uVar1 = FUN_0043d713(local_10c);
  *param_3 = uVar1;
  _sprintf(local_10c,s__s_WINBK_StartDuelButtonDepresse_004f7c00,&DAT_006189a0);
  uVar1 = FUN_0043d713(local_10c);
  *param_4 = uVar1;
  _sprintf(local_10c,s__s_WINBK_StartDuelButtonDisabled_004f7c28,&DAT_006189a0);
  uVar1 = FUN_0043d713(local_10c);
  *param_5 = uVar1;
  *param_6 = 0x1000001;
  *param_7 = 0x10000bf;
  return;
}



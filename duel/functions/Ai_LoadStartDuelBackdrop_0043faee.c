/*
 * Decompiled function: Ai_LoadStartDuelBackdrop
 * Entry Point: 0043faee
 * Size: 224 bytes
 */
#include "duel.h"


void Ai_LoadStartDuelBackdrop
               (undefined4 *arg_1,undefined4 *out_buffer,undefined4 *arg_3,undefined4 *arg_4,
               undefined4 *arg_5,undefined4 *arg_6,undefined4 *arg_7)

{
  undefined4 uVar1;
  char local_10c [264];
  
  _sprintf(local_10c,s__s_WINBK_StartDuel_pic_004f7bc4,&DAT_006189a0);
  uVar1 = Pic_Load_00423833(local_10c);
  *arg_1 = uVar1;
  *out_buffer = 0;
  _sprintf(local_10c,s__s_WINBK_StartDuelButtonNormal_p_004f7bdc,&DAT_006189a0);
  uVar1 = Pic_Load_00423833(local_10c);
  *arg_3 = uVar1;
  _sprintf(local_10c,s__s_WINBK_StartDuelButtonDepresse_004f7c00,&DAT_006189a0);
  uVar1 = Pic_Load_00423833(local_10c);
  *arg_4 = uVar1;
  _sprintf(local_10c,s__s_WINBK_StartDuelButtonDisabled_004f7c28,&DAT_006189a0);
  uVar1 = Pic_Load_00423833(local_10c);
  *arg_5 = uVar1;
  *arg_6 = 0x1000001;
  *arg_7 = 0x10000bf;
  return;
}



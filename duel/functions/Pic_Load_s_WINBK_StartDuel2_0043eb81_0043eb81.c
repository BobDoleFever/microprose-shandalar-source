/*
 * Decompiled function: Pic_Load_s_WINBK_StartDuel2_0043eb81
 * Entry Point: 0043eb81
 * Size: 179 bytes
 */
#include "duel.h"


void Pic_Load_s_WINBK_StartDuel2_0043eb81
               (undefined4 *arg_1,undefined4 *out_buffer,undefined4 *arg_3,undefined4 *arg_4,
               undefined4 *arg_5,undefined4 *arg_6)

{
  undefined4 uVar1;
  char local_10c [264];
  
  _sprintf(local_10c,s__s_WINBK_StartDuel2_pic_004f7a40,&DAT_006189a0);
  uVar1 = FUN_0043d713(local_10c);
  *arg_1 = uVar1;
  *out_buffer = 0;
  _sprintf(local_10c,s__s_WINBK_StartDuelButtonNormal_p_004f7a58,&DAT_006189a0);
  uVar1 = FUN_0043d713(local_10c);
  *arg_3 = uVar1;
  _sprintf(local_10c,s__s_WINBK_StartDuelButtonDepresse_004f7a7c,&DAT_006189a0);
  uVar1 = FUN_0043d713(local_10c);
  *arg_4 = uVar1;
  *arg_5 = 0x1000001;
  *arg_6 = 0x10000bf;
  return;
}



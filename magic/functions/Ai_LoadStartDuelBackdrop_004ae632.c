/*
 * Decompiled function: Ai_LoadStartDuelBackdrop
 * Entry Point: 004ae632
 * Size: 228 bytes
 */
#include "magic.h"


void Ai_LoadStartDuelBackdrop
               (undefined4 *arg_1,undefined4 *out_buffer,undefined4 *arg_3,undefined4 *arg_4,
               undefined4 *arg_5,undefined4 *arg_6,undefined4 *arg_7)

{
  undefined4 uVar1;
  char local_10c [264];
  
  sprintf(local_10c,s__s_WINBK_StartDuel_pic_0052d0a4,&DAT_006b2e90);
  uVar1 = Pic_Load_00423833(local_10c);
  *arg_1 = uVar1;
  *out_buffer = 0;
  sprintf(local_10c,s__s_WINBK_StartDuelButtonNormal_p_0052d0bc,&DAT_006b2e90);
  uVar1 = Pic_Load_00423833(local_10c);
  *arg_3 = uVar1;
  sprintf(local_10c,s__s_WINBK_StartDuelButtonDepresse_0052d0e0,&DAT_006b2e90);
  uVar1 = Pic_Load_00423833(local_10c);
  *arg_4 = uVar1;
  sprintf(local_10c,s__s_WINBK_StartDuelButtonDisabled_0052d108,&DAT_006b2e90);
  uVar1 = Pic_Load_00423833(local_10c);
  *arg_5 = uVar1;
  *arg_6 = 0x1000001;
  *arg_7 = 0x10000bf;
  return;
}



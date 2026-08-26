/*
 * Decompiled function: Prompts_Load_004ce8d5
 * Entry Point: 004ce8d5
 * Size: 98 bytes
 */
#include "duel.h"


void Prompts_Load_004ce8d5(int spell_id,int target_id,int flags)

{
  if (((flags == 0x6c) && (DAT_00690c48 == target_id)) && (DAT_0068ecb0 == spell_id)) {
    FUN_00434660(s_prompts_txt_00508ddc,s_GIANT_STRENGTH_00508dcc);
  }
  FUN_004ceabe(spell_id,target_id,flags,2,2);
  return;
}



/*
 * Decompiled function: Prompts_Load_004ce873
 * Entry Point: 004ce873
 * Size: 98 bytes
 */
#include "duel.h"


void Prompts_Load_004ce873(int spell_id,int target_id,int flags)

{
  if (((flags == 0x6c) && (DAT_00690c48 == target_id)) && (DAT_0068ecb0 == spell_id)) {
    FUN_00434660(s_prompts_txt_00508dc0,s_HOLY_STRENGTH_00508db0);
  }
  FUN_004ceabe(spell_id,target_id,flags,1,2);
  return;
}



/*
 * Decompiled function: Prompts_Load_004ce553
 * Entry Point: 004ce553
 * Size: 123 bytes
 */
#include "duel.h"


void Prompts_Load_004ce553(int spell_id,int target_id,int flags)

{
  char cVar1;
  
  if (((flags == 0x6c) && (DAT_00690c48 == target_id)) && (DAT_0068ecb0 == spell_id)) {
    FUN_00434660(s_prompts_txt_00508da4,s_FISHLIVEROIL_00508d94);
  }
  cVar1 = FUN_004af74c(spell_id,target_id,2);
  FUN_004ce5ce(spell_id,target_id,flags,1 << (cVar1 - 1U & 0x1f));
  return;
}



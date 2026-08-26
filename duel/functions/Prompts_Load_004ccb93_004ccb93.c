/*
 * Decompiled function: Prompts_Load_004ccb93
 * Entry Point: 004ccb93
 * Size: 123 bytes
 */
#include "duel.h"


void Prompts_Load_004ccb93(int spell_id,int target_id,int flags)

{
  char cVar1;
  
  if (((flags == 0x6c) && (DAT_00690c48 == target_id)) && (DAT_0068ecb0 == spell_id)) {
    FUN_00434660(s_prompts_txt_00508d04,s_BURROWING_00508cf8);
  }
  cVar1 = FUN_004af74c(spell_id,target_id,4);
  FUN_004ce5ce(spell_id,target_id,flags,1 << (cVar1 - 1U & 0x1f));
  return;
}



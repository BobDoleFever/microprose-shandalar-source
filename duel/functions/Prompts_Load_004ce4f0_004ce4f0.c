/*
 * Decompiled function: Prompts_Load_004ce4f0
 * Entry Point: 004ce4f0
 * Size: 99 bytes
 */
#include "duel.h"


void Prompts_Load_004ce4f0(int spell_id,int target_id,int flags)

{
  if (((flags == 0x6c) && (DAT_00690c48 == target_id)) && (DAT_0068ecb0 == spell_id)) {
    FUN_00434660(s_prompts_txt_00508d88,s_LANCE_00508d80);
  }
  FUN_004ce5ce(spell_id,target_id,flags,0x100);
  return;
}



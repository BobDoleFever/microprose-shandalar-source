/*
 * Decompiled function: Pic_Subsystem_0042bf45
 * Entry Point: 004bed45
 * Size: 96 bytes
 */
#include "duel.h"


void Pic_Subsystem_0042bf45(int spell_id,int target_id,int flags)

{
  if (((flags == 0x6c) && (DAT_00690c48 == target_id)) && (DAT_0068ecb0 == spell_id)) {
    FUN_00434660(s_prompts_txt_00508948,s_STEAL_ARTIFACT_00508938);
  }
  FUN_004beda5(spell_id,target_id,flags,0x40);
  return;
}



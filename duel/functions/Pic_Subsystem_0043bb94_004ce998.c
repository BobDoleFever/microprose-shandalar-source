/*
 * Decompiled function: Pic_Subsystem_0043bb94
 * Entry Point: 004ce998
 * Size: 98 bytes
 */
#include "duel.h"


void Pic_Subsystem_0043bb94(int spell_id,int target_id,int flags)

{
  if (((flags == 0x6c) && (DAT_00690c48 == target_id)) && (DAT_0068ecb0 == spell_id)) {
    FUN_00434660(s_prompts_txt_00508e18,s_DIVINE_TRANSFORMATION_00508e00);
  }
  FUN_004ceabe(spell_id,target_id,flags,3,3);
  return;
}



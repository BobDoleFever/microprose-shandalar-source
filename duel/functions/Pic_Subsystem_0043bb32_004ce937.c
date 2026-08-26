/*
 * Decompiled function: Pic_Subsystem_0043bb32
 * Entry Point: 004ce937
 * Size: 97 bytes
 */
#include "duel.h"


void Pic_Subsystem_0043bb32(int spell_id,int target_id,int flags)

{
  if (((flags == 0x6c) && (DAT_00690c48 == target_id)) && (spell_id == DAT_0068ecb0)) {
    FUN_00434660(s_prompts_txt_00508df4,s_IMMOLATION_00508de8);
  }
  FUN_004ceabe(spell_id,target_id,flags,2,-2);
  return;
}



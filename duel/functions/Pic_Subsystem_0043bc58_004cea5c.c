/*
 * Decompiled function: Pic_Subsystem_0043bc58
 * Entry Point: 004cea5c
 * Size: 98 bytes
 */
#include "duel.h"


void Pic_Subsystem_0043bc58(int spell_id,int target_id,int flags)

{
  if (((flags == 0x6c) && (DAT_00690c48 == target_id)) && (DAT_0068ecb0 == spell_id)) {
    FUN_00434660(s_prompts_txt_00508e4c,s_WEAKNESS_00508e40);
  }
  FUN_004ceabe(spell_id,target_id,flags,-2,-1);
  return;
}



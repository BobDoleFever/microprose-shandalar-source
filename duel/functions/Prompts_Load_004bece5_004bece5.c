/*
 * Decompiled function: Prompts_Load_004bece5
 * Entry Point: 004bece5
 * Size: 96 bytes
 */
#include "duel.h"


void Prompts_Load_004bece5(int spell_id,int target_id,int flags)

{
  if (((flags == 0x6c) && (DAT_00690c48 == target_id)) && (DAT_0068ecb0 == spell_id)) {
    FUN_00434660(s_prompts_txt_0050892c,s_CONTROL_MAGIC_0050891c);
  }
  FUN_004beda5(spell_id,target_id,flags,2);
  return;
}



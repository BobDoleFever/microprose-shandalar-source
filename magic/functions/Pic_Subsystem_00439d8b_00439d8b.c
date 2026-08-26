/*
 * Decompiled function: Pic_Subsystem_00439d8b
 * Entry Point: 00439d8b
 * Size: 123 bytes
 */
#include "magic.h"


void Pic_Subsystem_00439d8b(int spell_id,int target_id,int flags)

{
  char cVar1;
  
  if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
     (g_OverworldPlayerCoordX == spell_id)) {
    Pic_Subsystem_00424500(s_prompts_txt_0052167c,s_BURROWING_00521670);
  }
  cVar1 = FUN_0041d963(spell_id,target_id,4);
  Pic_Subsystem_0043b7c9(spell_id,target_id,flags,1 << (cVar1 - 1U & 0x1f));
  return;
}



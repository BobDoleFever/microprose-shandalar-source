/*
 * Decompiled function: Pic_Subsystem_0043b6eb
 * Entry Point: 0043b6eb
 * Size: 99 bytes
 */
#include "magic.h"


void Pic_Subsystem_0043b6eb(int spell_id,int target_id,int flags)

{
  if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
     (g_OverworldPlayerCoordX == spell_id)) {
    Pic_Subsystem_00424500(s_prompts_txt_00521700,s_LANCE_005216f8);
  }
  Pic_Subsystem_0043b7c9(spell_id,target_id,flags,0x100);
  return;
}



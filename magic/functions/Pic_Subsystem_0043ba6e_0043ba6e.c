/*
 * Decompiled function: Pic_Subsystem_0043ba6e
 * Entry Point: 0043ba6e
 * Size: 98 bytes
 */
#include "magic.h"


void Pic_Subsystem_0043ba6e(int spell_id,int target_id,int flags)

{
  if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
     (g_OverworldPlayerCoordX == spell_id)) {
    Pic_Subsystem_00424500(s_prompts_txt_00521738,s_HOLY_STRENGTH_00521728);
  }
  Pic_Subsystem_0043bcba(spell_id,target_id,flags,1,2);
  return;
}



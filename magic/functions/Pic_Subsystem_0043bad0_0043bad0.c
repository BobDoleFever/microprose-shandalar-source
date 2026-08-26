/*
 * Decompiled function: Pic_Subsystem_0043bad0
 * Entry Point: 0043bad0
 * Size: 98 bytes
 */
#include "magic.h"


void Pic_Subsystem_0043bad0(int spell_id,int target_id,int flags)

{
  if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
     (g_OverworldPlayerCoordX == spell_id)) {
    Pic_Subsystem_00424500(s_prompts_txt_00521754,s_GIANT_STRENGTH_00521744);
  }
  Pic_Subsystem_0043bcba(spell_id,target_id,flags,2,2);
  return;
}



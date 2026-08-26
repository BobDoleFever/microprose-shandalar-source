/*
 * Decompiled function: Pic_Subsystem_0042bf45
 * Entry Point: 0042bf45
 * Size: 96 bytes
 */
#include "magic.h"


void Pic_Subsystem_0042bf45(int spell_id,int target_id,int flags)

{
  if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
     (g_OverworldPlayerCoordX == spell_id)) {
    Pic_Subsystem_00424500(s_prompts_txt_005212c0,s_STEAL_ARTIFACT_005212b0);
  }
  Pic_Subsystem_0042bfa5(spell_id,target_id,flags,0x40);
  return;
}



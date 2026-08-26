/*
 * Decompiled function: Pic_Subsystem_0042bee5
 * Entry Point: 0042bee5
 * Size: 96 bytes
 */
#include "magic.h"


void Pic_Subsystem_0042bee5(int spell_id,int target_id,int flags)

{
  if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
     (g_OverworldPlayerCoordX == spell_id)) {
    Pic_Subsystem_00424500(s_prompts_txt_005212a4,s_CONTROL_MAGIC_00521294);
  }
  Pic_Subsystem_0042bfa5(spell_id,target_id,flags,2);
  return;
}



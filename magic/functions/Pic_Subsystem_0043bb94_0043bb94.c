/*
 * Decompiled function: Pic_Subsystem_0043bb94
 * Entry Point: 0043bb94
 * Size: 98 bytes
 */
#include "magic.h"


void Pic_Subsystem_0043bb94(int spell_id,int target_id,int flags)

{
  if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
     (g_OverworldPlayerCoordX == spell_id)) {
    Pic_Subsystem_00424500(s_prompts_txt_00521790,s_DIVINE_TRANSFORMATION_00521778);
  }
  Pic_Subsystem_0043bcba(spell_id,target_id,flags,3,3);
  return;
}



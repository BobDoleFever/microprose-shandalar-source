/*
 * Decompiled function: Pic_Subsystem_0043bc58
 * Entry Point: 0043bc58
 * Size: 98 bytes
 */
#include "magic.h"


void Pic_Subsystem_0043bc58(int spell_id,int target_id,int flags)

{
  if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
     (g_OverworldPlayerCoordX == spell_id)) {
    Pic_Subsystem_00424500(s_prompts_txt_005217c4,s_WEAKNESS_005217b8);
  }
  Pic_Subsystem_0043bcba(spell_id,target_id,flags,-2,-1);
  return;
}



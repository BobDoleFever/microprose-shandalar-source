/*
 * Decompiled function: Prompts_Load_00417f38
 * Entry Point: 00417f38
 * Size: 189 bytes
 */
#include "magic.h"


undefined4 Prompts_Load_00417f38(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  int iVar2;
  
  if (flags == 0x74) {
    Ai_GetOpponentPlayerScore(1);
    uVar1 = 1;
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_00519994,s_LIGHTNING_BOLT_00519984);
      iVar2 = Card_DirectDamage_EvaluateBestTarget(spell_id,target_id);
      if (iVar2 != 0) {
        g_SpellStackDepth = g_SpellStackDepth + -0x24;
      }
    }
    if (flags == 0x71) {
      Card_DirectDamage_PromptAndDealDamage(spell_id,target_id,0x71,3);
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Card_ProdigalSorcerer_PingTarget
 * Entry Point: 004df678
 * Size: 578 bytes
 */
#include "magic.h"


bool Card_ProdigalSorcerer_PingTarget(int spell_id,int target_id,int flags)

{
  bool bVar1;
  
  if (flags == 0x73) {
    bVar1 = (*(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) & 0x20010) == 0;
  }
  else if (flags == 0x90) {
    Ai_GetOpponentPlayerScore(1);
    bVar1 = false;
  }
  else {
    if (flags == 0x6d) {
      Pic_Subsystem_00424500(s_prompts_txt_0052ed88,s_PRODIGAL_SORCERER_0052ed74);
      Card_DirectDamage_EvaluateBestTarget(spell_id,target_id);
      if (g_ActivePlayer != 1) {
        *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
      }
    }
    if (flags == 0x72) {
      Card_DirectDamage_PromptAndDealDamage(spell_id,target_id,0x72,1);
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
       *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20] = 0;
    }
    if ((flags == 0x3b) &&
       ((*(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) & 0x20014) == 0)) {
      *(int *)(&DAT_00695eb8 + (1 - spell_id) * 4) =
           *(int *)(&DAT_00695eb8 + (1 - spell_id) * 4) + -1;
    }
    if ((((flags == 199) && (spell_id == g_DefendingPlayer)) && (spell_id == g_ActivePlayerPriority)
        ) && ((*(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) & 0x20010) == 0)
       ) {
      g_SpellStackDepth = g_SpellStackDepth + 0x18;
    }
    if (((flags == 0x8a) && (target_id == g_OverworldMapGrid)) &&
       (spell_id == g_OverworldPlayerCoordX)) {
      DAT_006ff19c = DAT_006ff19c + 0x30;
    }
    if (((flags == 0x8b) && (target_id == g_OverworldMapGrid)) &&
       (spell_id == g_OverworldPlayerCoordX)) {
      DAT_006ff19c = DAT_006ff19c + -0x30;
    }
    bVar1 = false;
  }
  return bVar1;
}



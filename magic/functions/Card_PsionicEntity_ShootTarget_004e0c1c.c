/*
 * Decompiled function: Card_PsionicEntity_ShootTarget
 * Entry Point: 004e0c1c
 * Size: 580 bytes
 */
#include "magic.h"


bool Card_PsionicEntity_ShootTarget(int spell_id,int target_id,int flags)

{
  int iVar1;
  bool bVar2;
  
  if (((flags == 199) && (iVar1 = FUN_00471c32(spell_id,target_id), iVar1 != 0)) &&
     (3 < *(short *)(&DAT_006a5f46 + target_id * 0x120 + spell_id * 0x5b20))) {
    if (spell_id == g_ActivePlayerPriority) {
      g_SpellStackDepth = g_SpellStackDepth + 200;
    }
    else {
      g_SpellStackDepth = g_SpellStackDepth + -200;
    }
  }
  if (flags == 0x73) {
    bVar2 = (*(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) & 0x20010) == 0;
  }
  else if (flags == 0x90) {
    Ai_GetOpponentPlayerScore(1);
    bVar2 = false;
  }
  else {
    if (flags == 0x6d) {
      Pic_Subsystem_00424500(s_prompts_txt_0052ee00,s_PSIONIC_ENTITY_0052edf0);
      Card_DirectDamage_EvaluateBestTarget(spell_id,target_id);
      if (g_ActivePlayer != 1) {
        *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
      }
    }
    if (flags == 0x72) {
      iVar1 = Card_DirectDamage_PromptAndDealDamage(spell_id,target_id,0x72,2);
      if ((iVar1 != 0) &&
         (*(int *)(&g_CardSlot_CardId +
                  *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
                  *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) *
                  0x120) != -1)) {
        FUN_0041db67(g_DialogPromptHwnd,g_DuelArenaHwnd,3,g_DialogPromptHwnd,g_DuelArenaHwnd);
      }
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120] = 0;
    }
    bVar2 = false;
  }
  return bVar2;
}



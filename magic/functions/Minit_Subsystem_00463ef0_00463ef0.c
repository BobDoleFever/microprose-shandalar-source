/*
 * Decompiled function: Minit_Subsystem_00463ef0
 * Entry Point: 00463ef0
 * Size: 538 bytes
 */
#include "magic.h"


undefined4 Minit_Subsystem_00463ef0(int spell_id,int target_id,int flags)

{
  int iVar1;
  undefined4 uVar2;
  
  if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
     (spell_id == g_OverworldPlayerCoordX)) {
    g_SpellStackDepth =
         g_SpellStackDepth + (*(int *)(&DAT_0063edec + g_ActivePlayerPriority * 0x20) * 3 + -6) * 4;
  }
  if (flags == 0x73) {
    iVar1 = FUN_0040d949(spell_id,7,3);
    if (((iVar1 == 0) ||
        ((((&DAT_006a5f3e)[target_id * 0x120 + spell_id * 0x5b20] & 3) != 0 &&
         (((&g_MasterCardColorTable)
           [*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) * 0x34] & 2) != 0))
        )) || (((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) != 0)) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  else if (flags == 0x90) {
    Ai_GetOpponentPlayerScore(1);
    uVar2 = 0;
  }
  else {
    if ((flags == 0x6d) && (Ai_CalcManaRequirement_004ba890(spell_id,0,3), g_ActivePlayer != 1)) {
      Pic_Subsystem_00424500(s_prompts_txt_00524678,s_ROD_OF_RUIN_0052466c);
      Card_DirectDamage_EvaluateBestTarget(spell_id,target_id);
      if (g_ActivePlayer != 1) {
        *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
      }
    }
    if (flags == 0x72) {
      Card_DirectDamage_PromptAndDealDamage(spell_id,target_id,0x72,1);
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120] = 0;
    }
    uVar2 = 0;
  }
  return uVar2;
}



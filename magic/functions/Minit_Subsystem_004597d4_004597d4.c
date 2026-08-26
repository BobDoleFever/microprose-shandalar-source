/*
 * Decompiled function: Minit_Subsystem_004597d4
 * Entry Point: 004597d4
 * Size: 1329 bytes
 */
#include "magic.h"


undefined4 Minit_Subsystem_004597d4(int spell_id,int target_id,int flags)

{
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  short local_c;
  
  if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
     (g_OverworldPlayerCoordX == spell_id)) {
    if (g_CurrentTurnPhase != spell_id) {
      if (g_IsAiThinking == 1) {
        g_AiDecisionScore = FUN_0040a1d2(7);
        Ai_EvaluateCreaturePower();
      }
      else {
        Ai_CalcCardAdvantage();
      }
    }
    Pic_Subsystem_0042475a(s_prompts_txt_005242c0,s_SHAPESHIFTER_005242b0);
    local_c = Ai_Subsystem_004cc56d
                        (spell_id,spell_id,target_id,-1,-1,&g_OverworldGoldAmount,g_AiDecisionScore)
    ;
    if (g_ActivePlayerPriority == spell_id) {
      local_c = (short)g_AiDecisionScore;
    }
    iVar2 = FUN_0041d8a6(*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20));
    if (iVar2 != -1) {
      *(short *)(&DAT_0051aec2 + iVar2 * 0x34) = local_c;
      *(short *)(&DAT_0051aec4 + iVar2 * 0x34) = 7 - local_c;
      *(int *)(&g_CardSlot_Controller + target_id * 0x120 + spell_id * 0x5b20) = iVar2;
      *(undefined4 *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) =
           *(undefined4 *)(&g_CardSlot_Controller + target_id * 0x120 + spell_id * 0x5b20);
      *(uint *)(&g_CardSlot_Abilities2 + target_id * 0x120 + spell_id * 0x5b20) =
           *(uint *)(&g_CardSlot_Abilities2 + target_id * 0x120 + spell_id * 0x5b20) | 0x1000000;
    }
  }
  if (((flags == 0x3c) && ((g_PlayerHandCardCount._2_1_ & 2) == 0)) &&
     ((g_OverworldMapGrid == target_id && (g_OverworldPlayerCoordX == spell_id)))) {
    iVar2 = FUN_00471c32(spell_id,target_id);
    if (iVar2 != 0) {
      g_ActivePalette =
           *(undefined4 *)(&g_CardSlot_Controller + target_id * 0x120 + spell_id * 0x5b20);
    }
  }
  if (flags == 0x73) {
    if ((((g_ScWillyScore == 4) && (g_DefendingPlayer == spell_id)) &&
        (*(int *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) == 0)) &&
       (DAT_0063edc0 == spell_id)) {
      uVar3 = 1;
    }
    else {
      uVar3 = 0;
    }
  }
  else {
    if (((flags == 0x6d) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = spell_id;
      *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = target_id;
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
      *(int *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) =
           *(int *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) + 1;
    }
    if ((flags == 0x72) &&
       (*(int *)(&g_CardSlot_CardId +
                *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120
                + *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20)
        != -1)) {
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
       *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20] = 0;
      Pic_Subsystem_0042475a(s_prompts_txt_005242dc,s_SHAPESHIFTER_005242cc);
      sVar1 = Ai_Subsystem_004cc56d(spell_id,spell_id,target_id,-1,-1,&g_OverworldGoldAmount,4);
      *(short *)(&DAT_0051aec2 +
                *(int *)(&g_CardSlot_CardId +
                        *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20)
                        * 0x120 + *(int *)(&g_CardSlot_TapState +
                                          target_id * 0x120 + spell_id * 0x5b20) * 0x5b20) * 0x34) =
           sVar1;
      *(short *)(&DAT_0051aec4 +
                *(int *)(&g_CardSlot_CardId +
                        *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20)
                        * 0x120 + *(int *)(&g_CardSlot_TapState +
                                          target_id * 0x120 + spell_id * 0x5b20) * 0x5b20) * 0x34) =
           7 - sVar1;
    }
    if (flags == 0x22) {
      *(undefined4 *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) = 0;
    }
    uVar3 = 0;
  }
  return uVar3;
}



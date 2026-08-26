/*
 * Decompiled function: Prompts_Load_004172a6
 * Entry Point: 004172a6
 * Size: 951 bytes
 */
#include "magic.h"


undefined4 Prompts_Load_004172a6(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  int iVar2;
  uint local_18;
  int local_14;
  undefined4 local_10;
  int local_c;
  int local_8;
  
  if (flags == 0x74) {
    uVar1 = 1;
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      if (g_CurrentTurnPhase == spell_id) {
        Pic_Subsystem_00424500(s_prompts_txt_00519954,s_HURKYLS_RECALL_00519944);
        iVar2 = Action_ValidateTarget_00405802
                          (spell_id,2,1 - spell_id,0x1000,0,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0,
                           0,0,&g_OverworldGoldAmount,1,&local_14);
        if (iVar2 == 0) {
          g_ActivePlayer = 1;
        }
        else {
          *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = local_14;
          *(undefined4 *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) =
               local_10;
          (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        }
      }
      else {
        if (g_IsAiThinking == 1) {
          iVar2 = FUN_0040a1d2(3);
          g_AiDecisionScore = (uint)(iVar2 == 0);
          if (g_AiDecisionScore != 0) {
            iVar2 = CardQuery_PlayerControlsColor(1 - spell_id,0x40);
            if (iVar2 == 0) {
              g_AiDecisionScore = 0;
            }
            else {
              iVar2 = CardQuery_PlayerControlsColor(spell_id,0x40);
              if (iVar2 == 0) {
                g_AiDecisionScore = 1;
              }
            }
          }
          Ai_EvaluateCreaturePower();
        }
        else {
          Ai_CalcCardAdvantage();
        }
        if (g_AiDecisionScore == 0) {
          *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = 1 - spell_id;
        }
        else {
          *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = spell_id;
        }
        *(undefined4 *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) =
             0xffffffff;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
      }
    }
    if (flags == 0x71) {
      if (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) == 0) {
        local_18 = 0;
      }
      else {
        local_18 = 0x1000;
      }
      for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
        for (local_c = 0; local_c < (int)(&g_PlayerActiveCardCount)[local_8]; local_c = local_c + 1)
        {
          iVar2 = FUN_00471c32(local_8,local_c);
          if (((iVar2 != 0) &&
              (((&g_MasterCardColorTable)
                [*(int *)(&g_CardSlot_CardId + local_c * 0x120 + local_8 * 0x5b20) * 0x34] & 0x40)
               != 0)) &&
             ((*(uint *)(&g_CardSlot_Flags + local_c * 0x120 + local_8 * 0x5b20) & 0x1000) ==
              local_18)) {
            FUN_0041da41(local_8,local_c);
          }
        }
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}



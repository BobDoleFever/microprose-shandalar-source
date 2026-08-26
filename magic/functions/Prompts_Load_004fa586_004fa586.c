/*
 * Decompiled function: Prompts_Load_004fa586
 * Entry Point: 004fa586
 * Size: 3166 bytes
 */
#include "magic.h"


undefined4 Prompts_Load_004fa586(int spell_id,int target_id,int flags)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 arg_11;
  uint uVar4;
  undefined4 arg_12;
  uint uVar5;
  undefined4 arg_13;
  undefined4 arg_14;
  undefined4 arg_15;
  uint uVar6;
  undefined4 arg_16;
  uint uVar7;
  undefined4 arg_17;
  undefined1 *puVar8;
  uint uVar9;
  int iVar10;
  undefined4 arg_18;
  uint uVar11;
  int arg_3;
  undefined4 arg_19;
  int *piVar12;
  uint uVar13;
  int local_30;
  int local_28;
  int local_24;
  int local_20;
  undefined4 local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (flags == 0x74) {
    if (g_CurrentTurnPhase == spell_id) {
      DAT_006fe3f4 = 1;
    }
    else {
      iVar1 = FUN_0040d949(spell_id,7,2);
      if (iVar1 == 0) {
        return 0;
      }
    }
    uVar2 = 1;
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      iVar1 = FUN_004fa423(spell_id,*(int *)(&g_CardSlot_CardId +
                                            target_id * 0x120 + spell_id * 0x5b20));
      g_SpellStackDepth = g_SpellStackDepth - (int)(0x48 / (longlong)iVar1);
      if ((g_CurrentTurnPhase == spell_id) && (g_IsAiThinking != 1)) {
        if ((g_PlayerHandCardCount._1_1_ & 4) == 0) {
          local_14 = FUN_0040d949(spell_id,7,1);
          local_14 = local_14 + -1;
          arg_19 = 0;
          arg_18 = 0;
          arg_17 = 0;
          arg_16 = 0xffffffff;
          arg_15 = 0xffffffff;
          arg_14 = 0xffffffff;
          arg_13 = 0xffffffff;
          arg_12 = 0;
          arg_11 = 0;
          uVar2 = SpellChain_ProcessTriggerEvent(spell_id,target_id);
          FUN_00403250(&local_18,0,spell_id,2,2,0x200,2,0,0,uVar2,arg_11,arg_12,arg_13,arg_14,arg_15
                       ,arg_16,arg_17,arg_18,arg_19);
          local_18 = local_18 + 2;
          local_10 = local_14;
          local_c = 1;
          iVar1 = Ai_Subsystem_004b832d
                            (spell_id,*(int *)(&g_CardSlot_CardId +
                                              target_id * 0x120 + spell_id * 0x5b20),local_14,
                             local_18,&local_10,&local_c,&local_1c);
          if (iVar1 == 0) {
            g_ActivePlayer = 1;
          }
          else {
            *(undefined4 *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
                 local_1c;
            g_TurnCounter = 0;
            DAT_006b2d50 = 1;
            Ai_CalcManaRequirement_004ba890(spell_id,0,local_10);
            if (g_ActivePlayer != 1) {
              g_TurnCounter = local_10 - (local_c + -1);
              (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
              local_20 = 0;
              while ((local_20 < local_c && (g_ActivePlayer != 1))) {
                Pic_Subsystem_00424500(s_prompts_txt_00530514,s_FIREBALL_00530508);
                sprintf(&g_OverworldGoldAmount,&g_OverworldGoldAmount,local_20 + 1,local_c);
                piVar12 = &local_28;
                uVar2 = 1;
                puVar8 = &g_OverworldGoldAmount;
                uVar13 = 0;
                uVar11 = 0;
                uVar9 = 0;
                uVar7 = 0xffffffff;
                uVar6 = 0xffffffff;
                iVar10 = -1;
                iVar1 = -1;
                uVar5 = 0;
                uVar4 = 0;
                uVar3 = SpellChain_ProcessTriggerEvent(spell_id,target_id);
                iVar1 = Action_ValidateTarget_00405802
                                  (spell_id,2,1 - spell_id,0x1200,2,0,0,uVar3,uVar4,uVar5,iVar1,
                                   iVar10,uVar6,uVar7,uVar9,uVar11,uVar13,puVar8,uVar2,piVar12);
                if (iVar1 == 0) {
                  g_ActivePlayer = 1;
                }
                else {
                  *(uint *)(&g_CardSlot_Flags + local_28 * 0x5b20 + local_24 * 0x120) =
                       *(uint *)(&g_CardSlot_Flags + local_28 * 0x5b20 + local_24 * 0x120) |
                       0x300000;
                  Ai_Subsystem_004cc9c5(0,0x20);
                  *(int *)(&g_CardSlot_CombatTarget +
                          target_id * 0x120 +
                          spell_id * 0x5b20 +
                          (char)(&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] * 8)
                       = local_28;
                  *(int *)(&g_CardSlot_AttachedAura +
                          target_id * 0x120 +
                          spell_id * 0x5b20 +
                          (char)(&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] * 8)
                       = local_24;
                  (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] =
                       (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] + '\x01';
                }
                local_20 = local_20 + 1;
              }
              for (local_20 = 0;
                  local_20 < (char)(&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20];
                  local_20 = local_20 + 1) {
                *(uint *)(&g_CardSlot_Flags +
                         *(int *)(&g_CardSlot_AttachedAura +
                                 target_id * 0x120 + spell_id * 0x5b20 + local_20 * 8) * 0x120 +
                         *(int *)(&g_CardSlot_CombatTarget +
                                 target_id * 0x120 + spell_id * 0x5b20 + local_20 * 8) * 0x5b20) =
                     *(uint *)(&g_CardSlot_Flags +
                              *(int *)(&g_CardSlot_AttachedAura +
                                      target_id * 0x120 + spell_id * 0x5b20 + local_20 * 8) * 0x120
                              + *(int *)(&g_CardSlot_CombatTarget +
                                        target_id * 0x120 + spell_id * 0x5b20 + local_20 * 8) *
                                0x5b20) & 0xffcfffff;
              }
              if (g_ActivePlayer == 1) {
                (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
              }
            }
          }
        }
        else {
          *(undefined4 *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
               *(undefined4 *)
                (&g_CardSlot_ConvertedManaCost + DAT_006b2d2c * 0x120 + DAT_006b2d3c * 0x5b20);
          local_c = (int)(char)(&g_CardSlot_TurnPlayed)
                               [DAT_006b2d2c * 0x120 + DAT_006b2d3c * 0x5b20];
          (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
          local_20 = 0;
          while ((local_20 < local_c && (g_ActivePlayer != 1))) {
            Pic_Subsystem_00424500(s_prompts_txt_0053052c,s_FIREBALL_00530520);
            sprintf(&g_OverworldGoldAmount,&g_OverworldGoldAmount,local_20 + 1,local_c);
            piVar12 = &local_28;
            uVar2 = 1;
            puVar8 = &g_OverworldGoldAmount;
            uVar13 = 0;
            uVar11 = 0;
            uVar9 = 0;
            uVar7 = 0xffffffff;
            uVar6 = 0xffffffff;
            iVar10 = -1;
            iVar1 = -1;
            uVar5 = 0;
            uVar4 = 0;
            uVar3 = SpellChain_ProcessTriggerEvent(spell_id,target_id);
            iVar1 = Action_ValidateTarget_00405802
                              (spell_id,2,1 - spell_id,0x1200,2,0,0,uVar3,uVar4,uVar5,iVar1,iVar10,
                               uVar6,uVar7,uVar9,uVar11,uVar13,puVar8,uVar2,piVar12);
            if (iVar1 == 0) {
              g_ActivePlayer = 1;
            }
            else {
              *(uint *)(&g_CardSlot_Flags + local_28 * 0x5b20 + local_24 * 0x120) =
                   *(uint *)(&g_CardSlot_Flags + local_28 * 0x5b20 + local_24 * 0x120) | 0x300000;
              Ai_Subsystem_004cc9c5(0,0x20);
              *(int *)(&g_CardSlot_CombatTarget +
                      target_id * 0x120 +
                      spell_id * 0x5b20 +
                      (char)(&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] * 8) =
                   local_28;
              *(int *)(&g_CardSlot_AttachedAura +
                      target_id * 0x120 +
                      spell_id * 0x5b20 +
                      (char)(&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] * 8) =
                   local_24;
              (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] =
                   (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] + '\x01';
            }
            local_20 = local_20 + 1;
          }
          for (local_20 = 0;
              local_20 < (char)(&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20];
              local_20 = local_20 + 1) {
            *(uint *)(&g_CardSlot_Flags +
                     *(int *)(&g_CardSlot_AttachedAura +
                             target_id * 0x120 + spell_id * 0x5b20 + local_20 * 8) * 0x120 +
                     *(int *)(&g_CardSlot_CombatTarget +
                             target_id * 0x120 + spell_id * 0x5b20 + local_20 * 8) * 0x5b20) =
                 *(uint *)(&g_CardSlot_Flags +
                          *(int *)(&g_CardSlot_AttachedAura +
                                  target_id * 0x120 + spell_id * 0x5b20 + local_20 * 8) * 0x120 +
                          *(int *)(&g_CardSlot_CombatTarget +
                                  target_id * 0x120 + spell_id * 0x5b20 + local_20 * 8) * 0x5b20) &
                 0xffcfffff;
          }
          if (g_ActivePlayer == 1) {
            (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
          }
        }
      }
      else {
        *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
             g_TurnCounter;
        if (g_IsAiThinking == 1) {
          if ((g_PlayerHandCardCount._1_1_ & 4) == 0) {
            arg_3 = 5;
            iVar10 = 1;
            iVar1 = FUN_0040a1d2((g_TurnCounter + 1) / 2);
            g_AiDecisionScore = FUN_0040a305(iVar1 + 1,iVar10,arg_3);
          }
          else {
            g_AiDecisionScore =
                 (int)(char)(&g_CardSlot_TurnPlayed)[DAT_006b2d2c * 0x120 + DAT_006b2d3c * 0x5b20];
          }
          Ai_EvaluateCreaturePower();
        }
        else {
          Ai_CalcCardAdvantage();
        }
        local_30 = g_AiDecisionScore;
        if (g_AiDecisionScore == 99) {
          local_30 = 1;
        }
        iVar1 = g_TurnCounter - local_30;
        for (local_20 = 0; local_20 < local_30; local_20 = local_20 + 1) {
          Card_DirectDamage_EvaluateBestTarget(spell_id,target_id);
          *(undefined4 *)
           (&g_CardSlot_CombatTarget +
           target_id * 0x120 + spell_id * 0x5b20 + ((local_30 + -1) - local_20) * 8) =
               *(undefined4 *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
          *(undefined4 *)
           (&g_CardSlot_AttachedAura +
           target_id * 0x120 + spell_id * 0x5b20 + ((local_30 + -1) - local_20) * 8) =
               *(undefined4 *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
          (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = (undefined1)local_30;
        }
        *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
             (iVar1 + 1) / local_30;
      }
    }
    if (flags == 0x71) {
      if (g_CurrentTurnPhase == spell_id) {
        local_8 = 0;
        for (local_20 = 0;
            local_20 < (char)(&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20];
            local_20 = local_20 + 1) {
          uVar13 = 0;
          uVar11 = 0;
          uVar9 = 0;
          uVar7 = 0xffffffff;
          uVar6 = 0xffffffff;
          iVar10 = -1;
          iVar1 = -1;
          uVar5 = 0;
          uVar4 = 0;
          uVar3 = SpellChain_ProcessTriggerEvent(spell_id,target_id);
          iVar1 = Rules_ParseFilter_0040360b
                            (*(int *)(&g_CardSlot_CombatTarget +
                                     target_id * 0x120 + spell_id * 0x5b20 + local_20 * 8),
                             *(int *)(&g_CardSlot_AttachedAura +
                                     target_id * 0x120 + spell_id * 0x5b20 + local_20 * 8),
                             (char *)0x0,spell_id,2,2,0x1200,2,0,0,uVar3,uVar4,uVar5,iVar1,iVar10,
                             uVar6,uVar7,uVar9,uVar11,uVar13);
          if (iVar1 == 0) {
            local_8 = local_8 + 1;
          }
          else {
            FUN_0041db67(*(int *)(&g_CardSlot_CombatTarget +
                                 target_id * 0x120 + spell_id * 0x5b20 + local_20 * 8),
                         *(int *)(&g_CardSlot_AttachedAura +
                                 target_id * 0x120 + spell_id * 0x5b20 + local_20 * 8),
                         *(int *)(&g_CardSlot_ConvertedManaCost +
                                 target_id * 0x120 + spell_id * 0x5b20),spell_id,target_id);
          }
        }
      }
      else {
        iVar1 = *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20);
        for (local_20 = 0;
            local_20 < (char)(&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20];
            local_20 = local_20 + 1) {
          *(undefined4 *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) =
               *(undefined4 *)
                (&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20 + local_20 * 8);
          *(undefined4 *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) =
               *(undefined4 *)
                (&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20 + local_20 * 8);
          Card_DirectDamage_PromptAndDealDamage(spell_id,target_id,0x71,iVar1);
        }
      }
      if ((char)(&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] == local_8) {
        g_ActivePlayer = 1;
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    uVar2 = 0;
  }
  return uVar2;
}



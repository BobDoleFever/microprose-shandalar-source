/*
 * Decompiled function: Prompts_Load_004195a4
 * Entry Point: 004195a4
 * Size: 1963 bytes
 */
#include "magic.h"


undefined4 Prompts_Load_004195a4(int spell_id,int target_id,int flags)

{
  byte bVar1;
  undefined4 uVar2;
  uint arg_8;
  int iVar3;
  int iVar4;
  uint arg_9;
  uint arg_10;
  uint arg_13;
  uint arg_14;
  uint arg_15;
  uint arg_16;
  uint arg_17;
  undefined1 *arg_18;
  int *arg_20;
  uint local_e4;
  int local_e0;
  int local_dc;
  int local_d8;
  int local_d4;
  char local_d0 [200];
  int local_8;
  
  if (flags == 0x74) {
    if (g_CurrentTurnPhase == spell_id) {
      if (DAT_006b2d3c == -1) {
        Ai_GetOpponentPlayerScore(0);
        uVar2 = 1;
      }
      else {
        uVar2 = 99;
      }
    }
    else if ((DAT_006b2d3c == -1) || (g_DefendingPlayer != g_CurrentTurnPhase)) {
      Ai_GetOpponentPlayerScore(0);
      uVar2 = 1;
    }
    else {
      uVar2 = 99;
    }
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      if (DAT_006b2d3c == -1) {
        Pic_Subsystem_00424500(s_prompts_txt_00519a68,s_SLEIGHT_OF_MIND_00519a58);
        arg_20 = &local_d8;
        uVar2 = 1;
        arg_18 = &g_OverworldGoldAmount;
        arg_17 = 0;
        arg_16 = 0;
        arg_15 = 0;
        arg_14 = 0xffffffff;
        arg_13 = 0xffffffff;
        iVar4 = -1;
        iVar3 = -1;
        arg_10 = 0;
        arg_9 = 0;
        arg_8 = SpellChain_ProcessTriggerEvent(spell_id,target_id);
        iVar3 = Action_ValidateTarget_00405802
                          (spell_id,2,2,0x200,0x7f,0,0,arg_8,arg_9,arg_10,iVar3,iVar4,arg_13,arg_14,
                           arg_15,arg_16,arg_17,arg_18,uVar2,arg_20);
        if (iVar3 == 0) {
          g_ActivePlayer = 1;
        }
        else {
          *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = local_d8;
          *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = local_d4;
          (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        }
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = DAT_006b2d3c;
        *(undefined4 *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) =
             DAT_006b2d2c;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
      }
      if (g_ActivePlayer != 1) {
        local_8 = FUN_0040a1d2(5);
        local_8 = local_8 + 1;
        if (((g_CurrentTurnPhase == spell_id) && (g_IsAiThinking != 1)) && (DAT_006fedc0 == 0)) {
          iVar3 = Ai_Subsystem_004b3777
                            (spell_id,(undefined4 *)
                                      (&g_CardSlot_CombatTarget +
                                      spell_id * 0x5b20 + target_id * 0x120),
                             s_Sleight_of_Mind_00519aa4,(1 << ((byte)local_8 & 0x1f) & 0xffU) << 8,0
                            );
          if (iVar3 == -1) {
            g_ActivePlayer = 1;
          }
          else {
            iVar4 = FUN_00473cc5((byte)((uint)iVar3 >> 8));
            iVar3 = FUN_00473cc5((byte)iVar3);
            *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
                 iVar4 * 0x100 + iVar3;
          }
        }
        else {
          local_e4 = *(uint *)(&DAT_006b30cc +
                              *(int *)(&g_MasterCardTypeTable +
                                      *(int *)(&g_CardSlot_CardId +
                                              *(int *)(&g_CardSlot_CombatTarget +
                                                      target_id * 0x120 + spell_id * 0x5b20) *
                                              0x5b20 + *(int *)(&g_CardSlot_AttachedAura +
                                                               target_id * 0x120 + spell_id * 0x5b20
                                                               ) * 0x120) * 0x34) * 0x98);
          if (local_e4 == 0) {
            g_ActivePlayer = 1;
          }
          else {
            if (((&g_CardSlot_Abilities1)
                 [*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) *
                  0x5b20 + *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20
                                   ) * 0x120] & 4) != 0) {
              iVar3 = FUN_00473cc5((byte)local_e4);
              bVar1 = FUN_0041d9d2(*(int *)(&g_CardSlot_CombatTarget +
                                           target_id * 0x120 + spell_id * 0x5b20),
                                   *(int *)(&g_CardSlot_AttachedAura +
                                           target_id * 0x120 + spell_id * 0x5b20),iVar3);
              local_e4 = 1 << (bVar1 & 0x1f);
            }
            do {
              local_e0 = FUN_0040a1d2(5);
              local_e0 = local_e0 + 1;
            } while ((local_e4 & 1 << ((byte)local_e0 & 0x1f)) == 0);
            do {
              local_dc = FUN_0040a1d2(5);
              local_dc = local_dc + 1;
            } while (local_dc == local_e0);
            if (g_IsAiThinking == 1) {
              g_AiDecisionScore = local_e0;
              Ai_EvaluateCreaturePower();
              g_AiDecisionScore = local_dc;
              Ai_EvaluateCreaturePower();
            }
            else {
              Ai_CalcCardAdvantage();
              local_e0 = g_AiDecisionScore;
              Ai_CalcCardAdvantage();
              local_dc = g_AiDecisionScore;
            }
            *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
                 local_dc * 0x100 + local_e0;
            if (g_IsAiThinking != 1) {
              Pic_Subsystem_00424500(s_prompts_txt_00519a80,s_COLORWORDS_00519a74);
              strcpy(local_d0,s_Sleighting_00519a8c);
              strcat(local_d0,&g_OverworldGoldAmount + (local_e0 * 5 + -5) * 0x32);
              strcat(local_d0,&DAT_00519a9c);
              strcat(local_d0,&g_OverworldGoldAmount + (local_dc * 5 + 0x2d) * 0x32);
              Ai_Subsystem_004cc56d
                        (spell_id,spell_id,target_id,
                         *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20),
                         local_d0,0);
            }
          }
        }
      }
      if (g_ActivePlayer == 1) {
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      }
    }
    if (flags == 0x71) {
      local_d8 = *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
      local_d4 = *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      if (g_IsAiThinking != 1) {
        Magic_UpkeepPhase(0x1e);
      }
      *(uint *)(&g_CardSlot_Abilities1 + local_d8 * 0x5b20 + local_d4 * 0x120) =
           *(uint *)(&g_CardSlot_Abilities1 + local_d8 * 0x5b20 + local_d4 * 0x120) | 4;
      FUN_004194cf(local_d8,local_d4,
                   (uint)(byte)(&g_CardSlot_ConvertedManaCost)
                               [target_id * 0x120 + spell_id * 0x5b20],
                   (char)((ushort)*(undefined2 *)
                                   (&g_CardSlot_ConvertedManaCost +
                                   target_id * 0x120 + spell_id * 0x5b20) >> 8));
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    uVar2 = 0;
  }
  return uVar2;
}



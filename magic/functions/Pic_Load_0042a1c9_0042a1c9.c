/*
 * Decompiled function: Pic_Load_0042a1c9
 * Entry Point: 0042a1c9
 * Size: 2641 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint Pic_Load_0042a1c9(int spell_id,int target_id,int flags)

{
  char cVar1;
  uint uVar2;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14 [4];
  
  if (flags == 0x74) {
    if (g_CurrentTurnPhase == spell_id) {
      uVar2 = (DAT_00695e04 | _DAT_00695e00) & 2;
    }
    else {
      if (g_IsAiThinking == 1) {
        g_AiDecisionScore = FUN_0040a1d2(2);
        Ai_EvaluateCreaturePower();
      }
      else {
        Ai_CalcCardAdvantage();
      }
      *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
           g_AiDecisionScore;
      uVar2 = *(uint *)(&DAT_00695e00 + g_AiDecisionScore * 4) & 2;
    }
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      if ((g_CurrentTurnPhase == spell_id) && (g_IsAiThinking != 1)) {
        local_14[1] = 0;
        local_14[0] = 0;
        for (local_18 = 0; local_18 < 2; local_18 = local_18 + 1) {
          local_20 = 0;
          while( true ) {
            if ((499 < local_20) || (*(int *)(&DAT_006ff710 + local_20 * 4 + spell_id * 2000) == -1)
               ) goto LAB_0042a2fb;
            if (((&g_MasterCardColorTable)
                 [*(int *)(&DAT_006ff710 + local_20 * 4 + local_18 * 2000) * 0x34] & 2) != 0) break;
            local_20 = local_20 + 1;
          }
          local_14[local_18] = local_14[local_18] + 1;
LAB_0042a2fb:
        }
        if ((local_14[0] == 0) || (local_14[1] == 0)) {
          if (local_14[0] == 0) {
            local_24 = 1;
          }
          else {
            local_24 = 0;
          }
        }
        else {
          local_24 = Ai_Subsystem_004cc56d
                               (spell_id,spell_id,target_id,-1,-1,
                                s_From_my_graveyard__From_opponent_005211cc,0);
          if (local_24 == 2) {
            g_ActivePlayer = 1;
          }
        }
        if (g_ActivePlayer != 1) {
          if (local_24 == 0) {
            strcpy(&g_OverworldWorldState,&DAT_00521208);
          }
          else {
            Ai_Subsystem_004b6f49(&g_OverworldWorldState);
            strcat(&g_OverworldWorldState,&DAT_00521204);
          }
          strcat(&g_OverworldWorldState,s_graveyard__Pick_a_creature_00521210);
          local_1c = 0;
          do {
            local_14[3] = Pic_Load_004509e8(spell_id,(int)(&DAT_006ff710 + local_24 * 2000),500,
                                            &g_OverworldWorldState,0);
            if (local_14[3] == -1) {
              g_ActivePlayer = 1;
            }
            else if (((&g_MasterCardColorTable)
                      [*(int *)(&DAT_006ff710 + local_14[3] * 4 + local_24 * 2000) * 0x34] & 2) == 0
                    ) {
              if (g_IsAiThinking != 1) {
                Ai_Util_004cc42d(s_Illegal_Target_00521234);
                Sleep(2000);
                Ai_Util_004cc42d(&DAT_00521244);
              }
            }
            else {
              local_1c = local_1c + 1;
            }
          } while ((g_ActivePlayer != 1) && (local_1c == 0));
        }
      }
      else {
        local_24 = *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20);
        local_14[3] = FUN_004fd9c0(local_24,2);
      }
      if ((g_ActivePlayer == 1) ||
         (((local_14[3] == -1 || (*(int *)(&DAT_006ff710 + local_14[3] * 4 + local_24 * 2000) == -1)
           ) || (((&g_MasterCardColorTable)
                  [*(int *)(&DAT_006ff710 + local_14[3] * 4 + local_24 * 2000) * 0x34] & 2) == 0))))
      {
        g_ActivePlayer = 1;
      }
      else {
        local_14[2] = Pic_Subsystem_00451291
                                (spell_id,*(int *)(&DAT_006ff710 + local_14[3] * 4 + local_24 * 2000
                                                  ));
        if (local_14[2] != -1) {
          *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) = local_14[2]
          ;
          (&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] = (undefined1)spell_id;
          *(uint *)(&g_CardSlot_Flags +
                   *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                   0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                           0x5b20) =
               *(uint *)(&g_CardSlot_Flags +
                        *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20)
                        * 0x120 + (char)(&g_CardSlot_Toughness)
                                        [target_id * 0x120 + spell_id * 0x5b20] * 0x5b20) &
               0xffffefff;
          if (local_24 != 0) {
            *(uint *)(&g_CardSlot_Flags +
                     *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                     0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                             0x5b20) =
                 *(uint *)(&g_CardSlot_Flags +
                          *(int *)(&g_CardSlot_OriginalCardId +
                                  target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
                          (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                          0x5b20) | 0x1000;
          }
          *(uint *)(&g_CardSlot_Flags +
                   *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                   0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                           0x5b20) =
               *(uint *)(&g_CardSlot_Flags +
                        *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20)
                        * 0x120 + (char)(&g_CardSlot_Toughness)
                                        [target_id * 0x120 + spell_id * 0x5b20] * 0x5b20) | 0x20;
          *(undefined4 *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) = 1;
          *(int *)(&DAT_006a5f90 + target_id * 0x120 + spell_id * 0x5b20) = local_24;
          *(int *)(&DAT_006a5f94 + target_id * 0x120 + spell_id * 0x5b20) = local_14[3];
          *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) =
               (int)(char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20];
          *(undefined4 *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) =
               *(undefined4 *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20);
          (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        }
      }
    }
    if (flags == 0x71) {
      local_14[3] = *(int *)(&DAT_006a5f94 + target_id * 0x120 + spell_id * 0x5b20);
      if (*(int *)(&DAT_006ff710 +
                  local_14[3] * 4 +
                  *(int *)(&DAT_006a5f90 + target_id * 0x120 + spell_id * 0x5b20) * 2000) == -1) {
        Pic_Subsystem_0044867e(spell_id,target_id,2);
        *(undefined4 *)
         (&g_CardSlot_CardId +
         *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) * 0x120) =
             0xffffffff;
        g_ActivePlayer = 1;
      }
      else {
        Pic_Subsystem_00449223
                  (*(int *)(&DAT_006a5f90 + target_id * 0x120 + spell_id * 0x5b20),local_14[3]);
        *(undefined4 *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) = 0;
        Pic_Subsystem_0042ac1f
                  ((int)(char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20],
                   *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20));
        *(undefined2 *)
         (&DAT_006a5f48 +
         *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
         (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] * 0x5b20) = 0xffff;
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    }
    if (((((g_PlayerManaPool == 0xd4) && (g_OverworldMapGrid == target_id)) &&
         ((g_OverworldPlayerCoordX == spell_id &&
          (((&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] != -1 &&
           (*(int *)(&g_CardSlot_CardId +
                    *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                    0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                            0x5b20) != -1)))))) && (DAT_00695f08 == spell_id)) &&
       ((DAT_006b2e14 == target_id && (spell_id == DAT_006a4b5c)))) {
      if (flags == 0x7d) {
        g_ActivePalette = g_ActivePalette | 2;
      }
      if (flags == 0x7e) {
        if (*(int *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) != 0) {
          *(uint *)(&g_CardSlot_Abilities1 +
                   *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                   0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                           0x5b20) =
               *(uint *)(&g_CardSlot_Abilities1 +
                        *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20)
                        * 0x120 + (char)(&g_CardSlot_Toughness)
                                        [target_id * 0x120 + spell_id * 0x5b20] * 0x5b20) | 8;
        }
        cVar1 = (&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20];
        (&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] = 0xff;
        Pic_Subsystem_0044867e
                  ((int)cVar1,
                   *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20),1);
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}



/*
 * sid/glue_card_scripts.c - Specific Card Rules Scripts & Activated/Triggered Abilities
 * Reconstructed MicroProse Source Module
 * Author: Sid Meier & Ned Way / MicroProse (1997)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include "shandalar/shandalar.h"
#include "shandalar/win32_compat.h"
#include "shandalar/glue.h"

/*
 * Card_PrismaticDragon_ColorChange
 * Purpose: Execute Prismatic Dragon (Astral set) upkeep color change ability.
 * Procedure:
 * 1. Choose random replacement color at upkeep.
 * 2. Apply new color mask to creature slot.
 * 3. Trigger card refresh event.
 */
/*
 * Decompiled function: Card_PrismaticDragon_ColorChange
 * Entry Point: 004d0cdb
 * Size: 959 bytes
 */

int Card_PrismaticDragon_ColorChange(int player,int card_index,int event_code)

{
  bool is_valid;
  int val_result;
  char *char_ptr_3;
  int uval_4;
  uint8_t slot_idx;
  
  if (((((g_CurrentStepCode == 0xc9) || (event_code == 199)) && (card_index == g_EventSourceSlot)) &&
      ((player == g_EventSourcePlayer && (player == g_TurnPlayer)))) &&
     (g_CurrentCardColorTarget == player)) {
    if (event_code == 0x7d) {
      g_CardEventResult = g_CardEventResult | 2;
    }
    if ((event_code == 0x7e) || (event_code == 199)) {
      if (g_IsAiThinking != 1) {
        Duel_PlaySoundById(0x29);
      }
      val_result = Util_GetRandomNumber(5);
      slot_idx = (uint8_t)(val_result + 1);
      (&g_CardSlot_MinusOneCounters)[card_index * 0x120 + player * 0x5b20] = (char)(1 << (slot_idx & 0x1f));
      strcpy(&g_OverworldWorldState,s_changes_color_to_0052e874);
      char_ptr_3 = (char *)Mem_AllocOrFree_00473d7e(val_result + 1);
      strcat(&g_OverworldWorldState,char_ptr_3);
      Ai_Subsystem_004cc56d(player,player,card_index,-1,-1,&g_OverworldWorldState,0);
    }
  }
  if (event_code == 0x73) {
    if ((*(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) == 0) &&
       (val_result = Font_DrawString(player, 7, 2), val_result != 0)) {
      uval_4 = 1;
    }
    else {
      uval_4 = 0;
    }
  }
  else {
    if ((event_code == 0x6d) && (val_result = Font_DrawString(player, 7, 2), val_result != 0)) {
      Ai_CalcManaRequirement_004ba890(player,0,2);
    }
    if (event_code == 0x72) {
      if (*(int *)(&g_CardSlot_CardId +
                  *(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20 +
                  *(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120) ==
          -1) {
        g_ActivePlayer = 1;
      }
      else {
        if (g_IsAiThinking != 1) {
          Duel_PlaySoundById(0x29);
        }
        val_result = Util_GetRandomNumber(5);
        slot_idx = (uint8_t)(val_result + 1);
        (&g_CardSlot_MinusOneCounters)
        [*(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20 +
         *(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120] =
             (char)(1 << (slot_idx & 0x1f));
        strcpy(&g_OverworldWorldState,s_changes_color_to_0052e888);
        char_ptr_3 = (char *)Mem_AllocOrFree_00473d7e(val_result + 1);
        strcat(&g_OverworldWorldState,char_ptr_3);
        Ai_Subsystem_004cc56d(player,player,card_index,-1,-1,&g_OverworldWorldState,0);
        *(uint32_t *)(&g_CardSlot_ConvertedManaCost +
                 *(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20 +
                 *(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120) =
             *(uint32_t *)(&g_CardSlot_ConvertedManaCost +
                      *(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20 +
                      *(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120)
             | 1 << ((uint8_t)g_TurnPlayer & 0x1f);
      }
    }
    if ((card_index == g_EventSourceSlot) && (player == g_EventSourcePlayer)) {
      is_valid = true;
    }
    else {
      is_valid = false;
    }
    if (is_valid) {
      *(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) = 0;
    }
    uval_4 = 0;
  }
  return uval_4;
}

/*
 * Card_RainbowKnights_ActivatedAbility
 * Purpose: Execute Rainbow Knights (Astral set) activated abilities and random protection.
 * Procedure:
 * 1. On cast: select random color and grant protection from that color.
 * 2. Option 1 (pay RR): add random power bonus (+0 to +2) until end of turn.
 * 3. Option 2 (pay W): grant first strike until end of turn.
 * 4. Option 3: cancel activation.
 */
/*
 * Decompiled function: Card_RainbowKnights_ActivatedAbility
 * Entry Point: 004d109a
 * Size: 3109 bytes
 */

int Card_RainbowKnights_ActivatedAbility(int player,int card_index,int event_code)

{
  uint8_t is_valid;
  int val_result;
  int uval_3;
  int val_4;
  uint32_t uval_5;
  char *mode_str;
  int card_idx;
  
  if (((event_code == 0x6c) && (card_index == g_EventSourceSlot)) && (player == g_EventSourcePlayer)) {
    is_valid = Util_GetRandomNumber(5);
    *(int *)(&g_CardSlot_TargetSlot + card_index * 0x120 + player * 0x5b20) = 0x800 << (is_valid & 0x1f);
  }
  if (event_code == 0x71) {
    *(uint32_t *)(&g_CardSlot_Abilities2 + card_index * 0x120 + player * 0x5b20) =
         *(uint32_t *)(&g_CardSlot_Abilities2 + card_index * 0x120 + player * 0x5b20) |
         *(uint32_t *)(&g_CardSlot_TargetSlot + card_index * 0x120 + player * 0x5b20);
  }
  if (event_code == 0x73) {
    val_result = Font_DrawString(player,5,2);
    if (val_result == 0) {
      val_result = Font_DrawString(player,7,1);
      if ((val_result == 0) || (((&DAT_006a5f61)[card_index * 0x120 + player * 0x5b20] & 1) != 0)) {
        uval_3 = 0;
      }
      else {
        uval_3 = 1;
      }
    }
    else {
      uval_3 = 1;
    }
  }
  else {
    if (event_code == 0x6d) {
      val_result = Font_DrawString(player,7,1);
      val_4 = Font_DrawString(player,5,2);
      *(uint32_t *)(&g_CardSlot_TargetSlot + card_index * 0x120 + player * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_TargetSlot + card_index * 0x120 + player * 0x5b20) & 0xfffffffe;
      if ((val_4 != 0) ||
         ((val_result != 0 && (((&DAT_006a5f61)[card_index * 0x120 + player * 0x5b20] & 1) == 0)))) {
        if (val_4 == 0) {
          strcpy(&g_OverworldWorldState,s__Add_random_power__0052e8b0);
        }
        else {
          strcpy(&g_OverworldWorldState,s_Add_random_power__0052e89c);
        }
        if ((val_result == 0) || (((&DAT_006a5f61)[card_index * 0x120 + player * 0x5b20] & 1) != 0)) {
          strcat(&g_OverworldWorldState,s__Gain_first_strike__0052e8dc);
        }
        else {
          strcat(&g_OverworldWorldState,s_Gain_first_strike__0052e8c4);
        }
        strcat(&g_OverworldWorldState,s_Cancel__0052e8f4);
        if ((g_ActiveBattlefieldFlag == 0) ||
           ((((&g_CardSlot_Flags)[card_index * 0x120 + player * 0x5b20] & 8) == 0 &&
            ((((&g_CardSlot_Flags)[card_index * 0x120 + player * 0x5b20] & 4) == 0 ||
             (((&DAT_006a5f3d)[card_index * 0x120 + player * 0x5b20] & 2) == 0)))))) {
          if (val_4 == 0) {
            if ((val_result == 0) || (((&DAT_006a5f61)[card_index * 0x120 + player * 0x5b20] & 1) != 0)) {
              card_idx = 2;
            }
            else {
              card_idx = 1;
            }
          }
          else {
            card_idx = 0;
          }
        }
        else if ((val_result == 0) || (((&DAT_006a5f61)[card_index * 0x120 + player * 0x5b20] & 1) != 0)) {
          if (val_4 == 0) {
            card_idx = 2;
          }
          else {
            card_idx = 0;
          }
        }
        else {
          card_idx = 1;
        }
        val_result = Ai_Subsystem_004cc56d(player,player,card_index,-1,-1,&g_OverworldWorldState,card_idx);
        if (val_result == 0) {
          if ((val_4 != 0) && (Ai_CalcManaRequirement_004ba890(player,5,2), g_ActivePlayer != 1)) {
            *(int *)(&g_CardSlot_CombatTarget + card_index * 0x120 + player * 0x5b20) = player;
            *(int *)(&g_CardSlot_AttachedAura + card_index * 0x120 + player * 0x5b20) = card_index;
            (&g_CardSlot_TurnPlayed)[card_index * 0x120 + player * 0x5b20] = 1;
            if (*(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) == 0) {
              *(uint32_t *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) =
                   *(uint32_t *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) |
                   0x80000;
            }
          }
        }
        else if (val_result == 1) {
          Ai_CalcManaRequirement_004ba890(player,0,1);
          if (g_ActivePlayer != 1) {
            *(int *)(&g_CardSlot_CombatTarget + card_index * 0x120 + player * 0x5b20) = player;
            *(int *)(&g_CardSlot_AttachedAura + card_index * 0x120 + player * 0x5b20) = card_index;
            (&g_CardSlot_TurnPlayed)[card_index * 0x120 + player * 0x5b20] = 1;
            *(uint32_t *)(&g_CardSlot_TargetSlot + card_index * 0x120 + player * 0x5b20) =
                 *(uint32_t *)(&g_CardSlot_TargetSlot + card_index * 0x120 + player * 0x5b20) | 1;
          }
        }
        else if (val_result == 2) {
          g_ActivePlayer = 1;
        }
      }
    }
    if (event_code == 0x72) {
      if (*(int *)(&g_CardSlot_CardId +
                  *(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20 +
                  *(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120) ==
          -1) {
        g_ActivePlayer = 1;
      }
      else if (((&g_CardSlot_TargetSlot)[card_index * 0x120 + player * 0x5b20] & 1) == 0) {
        uval_5 = Util_GetRandomNumber(3);
        *(uint32_t *)(&g_CardSlot_ConvertedManaCost +
                 *(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120 +
                 *(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20) =
             *(int *)(&g_CardSlot_ConvertedManaCost +
                     *(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120 +
                     *(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20) +
             (uval_5 & 0xff);
        strcpy(&g_OverworldWorldState,s_Power_increased_by_0052e900);
        str_2 = _itoa(uval_5,&DAT_00565998,10);
        strcat(&g_OverworldWorldState,str_2);
        Ai_Subsystem_004cc56d(player,player,card_index,-1,-1,&g_OverworldWorldState,0);
        (&g_CardSlot_TurnPlayed)
        [*(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20 +
         *(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120] = 0;
        if (g_IsAiThinking != 1) {
          Duel_PlaySoundById(0x2e);
        }
        if ((uval_5 != 0) &&
           (((&DAT_006a5f56)
             [*(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20 +
              *(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120] & 8) !=
            0)) {
          *(uint32_t *)(&g_CardSlot_ConvertedManaCost +
                   *(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120 +
                   *(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20) =
               *(uint32_t *)(&g_CardSlot_ConvertedManaCost +
                        *(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120
                        + *(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20)
               & 0xfff7ffff;
          val_result = Card_ApplyTriggerEffect(g_DialogPromptHwnd, g_DuelArenaHwnd, g_PlayerSelectionPriority, g_DialogPromptHwnd, g_DuelArenaHwnd);
          if (val_result != -1) {
            *(short *)(&g_CardSlot_PowerCounters + val_result * 0x120 + player * 0x5b20) = (short)uval_5;
            *(uint32_t *)(&g_CardSlot_ConvertedManaCost + val_result * 0x120 + player * 0x5b20) =
                 *(uint32_t *)(&g_CardSlot_ConvertedManaCost + val_result * 0x120 + player * 0x5b20) | 0x80000
            ;
            *(int *)(&g_CardSlot_TargetSlot + val_result * 0x120 + player * 0x5b20) = 1;
          }
        }
      }
      else if (((&DAT_006a5f61)
                [*(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20 +
                 *(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120] & 1)
               == 0) {
        *(uint32_t *)(&g_CardSlot_TargetSlot +
                 *(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120 +
                 *(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_TargetSlot +
                      *(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120 +
                      *(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20) &
             0x1ff800;
        *(uint32_t *)(&g_CardSlot_TargetSlot +
                 *(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120 +
                 *(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_TargetSlot +
                      *(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120 +
                      *(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20) |
             0x100;
        (&g_CardSlot_TurnPlayed)
        [*(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20 +
         *(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120] = 0;
        val_result = Card_ApplyTriggerEffect(g_DialogPromptHwnd,g_DuelArenaHwnd,DAT_0069f6dc,g_DialogPromptHwnd,
                             g_DuelArenaHwnd);
        if (val_result != -1) {
          *(int *)(&g_CardSlot_ConvertedManaCost + val_result * 0x120 + player * 0x5b20) = 0x100;
          *(int *)(&g_CardSlot_Abilities2 + val_result * 0x120 + player * 0x5b20) = 0;
          *(int *)(&g_CardSlot_TargetSlot + val_result * 0x120 + player * 0x5b20) = 2;
        }
        if (g_IsAiThinking != 1) {
          Duel_PlaySoundById(0x2e);
        }
      }
    }
    if ((((event_code == 0x34) && (card_index == g_EventSourceSlot)) && (player == g_EventSourcePlayer))
       && (((&g_CardSlot_Flags)[card_index * 0x120 + player * 0x5b20] & 0x20) == 0)) {
      g_CardEventResult =
           g_CardEventResult |
           *(uint32_t *)(&g_CardSlot_TargetSlot + card_index * 0x120 + player * 0x5b20) & 0x1ff800;
      uval_5 = g_CardEventResult;
      val_result = Rules_CalculateManaCostReduction((uint8_t)((*(uint32_t *)(&g_CardSlot_TargetSlot + card_index * 0x120 + player * 0x5b20
                                            ) & 0x1ff800) >> 10));
      Card_RockHydra_UpdateStatsFromHeads(player,card_index,val_result);
      g_CardEventResult = uval_5;
    }
    if (((event_code == 0x8c) && (card_index == g_EventSourceSlot)) &&
       ((player == g_EventSourcePlayer && (val_result = Font_DrawString(player,7,1), val_result != 0)))) {
      g_AiAttackingCreatureCount = g_AiAttackingCreatureCount | 0x100;
    }
    if ((event_code == 0x22) || (event_code == 199)) {
      *(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) = 0;
      *(uint32_t *)(&g_CardSlot_TargetSlot + card_index * 0x120 + player * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_TargetSlot + card_index * 0x120 + player * 0x5b20) & 0xfffffeff;
    }
    uval_3 = 0;
  }
  return uval_3;
}

/*
 * Card_Sinbad_Draw
 * Purpose: Execute Sinbad card draw ability.
 * Procedure:
 * 1. Draw top card from active library.
 * 2. Reveal drawn card and verify if land.
 * 3. Discard card if not a land, or put into hand.
 */
/*
 * Decompiled function: Card_Sinbad_Draw
 * Entry Point: 004d1cc4
 * Size: 332 bytes
 */

bool Card_Sinbad_Draw(int player,int card_index,int event_code)

{
  int extra_flags;
  bool is_valid;
  
  if (event_code == 0x73) {
    is_valid = (*(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) & 0x20010) == 0;
  }
  else {
    if (event_code == 0x6d) {
      *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) | 0x10;
    }
    if (event_code == 0x72) {
      extra_flags = Magic_ExecuteDrawPhase(player);
      Ai_Subsystem_004cc56d(player,player,card_index,player,extra_flags,s_Sinbad_draws____0052e914,0);
      if (((&g_MasterCardColorTable)
           [*(int *)(&g_CardSlot_CardId + extra_flags * 0x120 + player * 0x5b20) * 0x34] & 1) == 0) {
        Pic_Subsystem_0044913a(player,extra_flags);
        *(int *)(&g_CardSlot_CardId + extra_flags * 0x120 + player * 0x5b20) = 0xffffffff;
        (&g_ActivePlayerSpellPriority)[player] = (&g_ActivePlayerSpellPriority)[player] + -1;
        if (g_IsAiThinking != 1) {
          Duel_PlaySoundById(0x18);
        }
      }
    }
    is_valid = false;
  }
  return is_valid;
}

/*
 * Card_Kudzu_LandDestruction
 * Purpose: Process Kudzu land destruction and transfer trigger.
 * Procedure:
 * 1. Trigger destruction of enchanted land.
 * 2. Prompt controller to attach Kudzu to opponent land.
 */
/*
 * Decompiled function: Card_Kudzu_LandDestruction
 * Entry Point: 004d1e10
 * Size: 796 bytes
 */

int Card_Kudzu_LandDestruction(int player,int card_index,int event_code)

{
  int status;
  int u_temp;
  uint32_t uval_3;
  int card_idx;
  int match_count;
  
  if (((event_code == 0x6c) && (card_index == g_EventSourceSlot)) && (player == g_EventSourcePlayer)) {
    status = Pic_Subsystem_0045268f(0x38f);
    status = Deck_AddCardToDeck(1 - player,status);
    if (status != -1) {
      *(uint32_t *)(&g_CardSlot_Flags + status * 0x120 + (1 - player) * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_Flags + status * 0x120 + (1 - player) * 0x5b20) | 2;
      *(int *)(&DAT_006a5f74 + status * 0x120 + (1 - player) * 0x5b20) =
           *(int *)
            (&g_MasterCardTypeTable +
            *(int *)(&g_CardSlot_CardId + player * 0x5b20 + card_index * 0x120) * 0x34);
    }
    *(int *)(&g_CardSlot_ConvertedManaCost + player * 0x5b20 + card_index * 0x120) = status;
  }
  if (event_code == 0x73) {
    u_temp = Font_DrawString(player,3,1);
  }
  else {
    if (event_code == 0x6d) {
      status = Font_DrawString(player,3,1);
      if (status != 0) {
        Ai_CalcManaRequirement_004ba890(player,3,1);
        *(int *)(&g_CardSlot_ConvertedManaCost + player * 0x5b20 + card_index * 0x120) =
             g_TurnCounter;
      }
    }
    if ((event_code == 0x72) &&
       (*(int *)(&g_CardSlot_ConvertedManaCost + player * 0x5b20 + card_index * 0x120) != 0)) {
      Mem_AllocOrFree_0041df33
                (1 - player,*(int *)(&g_CardSlot_ConvertedManaCost + player * 0x5b20 + card_index * 0x120),
                 player,card_index);
      Mem_AllocOrFree_0041df33
                (player,*(int *)(&g_CardSlot_ConvertedManaCost + player * 0x5b20 + card_index * 0x120),
                 player,card_index);
      for (match_count = 0; match_count < 2; match_count = match_count + 1) {
        for (card_idx = 0; card_idx < (int)(&g_PlayerActiveCardCount)[match_count];
            card_idx = card_idx + 1) {
          status = Card_IsTapped(match_count, card_idx);
          if (status != 0) {
            uval_3 = Magic_QueryCardAttribute(match_count, card_idx, 0x34, 0xffffffff);
            if ((uval_3 & 0x20) != 0) {
              Card_ApplyCombatDamage(match_count, card_idx, *(int *)(&g_CardSlot_ConvertedManaCost + player * 0x5b20 + card_index * 0x120),
                           player,card_index);
            }
          }
        }
      }
    }
    if (((event_code == 0x77) && (card_index == g_EventSourceSlot)) && (player == g_EventSourcePlayer)) {
      Pic_Subsystem_0044867e
                (1 - player,*(int *)(&g_CardSlot_ConvertedManaCost + player * 0x5b20 + card_index * 0x120),
                 4);
    }
    u_temp = 0;
  }
  return u_temp;
}

/*
 * Card_BronzeTablets_AnteSwap
 * Purpose: Execute Bronze Tablets ante swap ability.
 * Procedure:
 * 1. Prompt target player (Swap cards, lose 10 life, or concede).
 * 2. Execute chosen ante swap or life loss effect.
 */
/*
 * Decompiled function: Card_BronzeTablets_AnteSwap
 * Entry Point: 004d212c
 * Size: 1247 bytes
 */

void Card_BronzeTablets_AnteSwap(int player,int card_index,int event_code)

{
  int action_param;
  int u_res;
  int val_result;
  int card_idx;
  
  if (event_code != 0x73) {
    if (event_code == 0x6d) {
      *(int *)(&g_CardSlot_TargetSlot + card_index * 0x120 + player * 0x5b20) = 1 - player;
      u_res = Ai_Subsystem_004cc56d
                        (*(int *)(&g_CardSlot_TargetSlot + card_index * 0x120 + player * 0x5b20),player,
                         card_index,-1,-1,s_Swap_cards__Lose_10_life__Conced_0052e924,0);
      *(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) = u_res;
      *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) | 0x10;
    }
    if (event_code == 0x72) {
      action_param = *(int *)(&g_CardSlot_TargetSlot + card_index * 0x120 + player * 0x5b20);
      val_result = *(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20);
      if (val_result == 0) {
        *(uint32_t *)(&g_CardSlot_Flags +
                 *(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120 +
                 *(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_Flags +
                      *(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120 +
                      *(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20) ^
             0x1000;
        if (g_IsAiThinking != 1) {
          Duel_PlaySoundById(0xf);
        }
        Pic_Subsystem_0044867e(g_DialogPromptHwnd,g_DuelArenaHwnd,3);
        if (player == g_CurrentTurnPhase) {
          Pic_Subsystem_0045200d
                    (*(uint32_t *)(&g_CardSlot_CardId +
                              *(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) *
                              0x120 + *(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20
                                              ) * 0x5b20));
        }
        else {
          Pic_Subsystem_00451e40
                    (*(uint32_t *)(&g_CardSlot_CardId +
                              *(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) *
                              0x120 + *(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20
                                              ) * 0x5b20));
        }
        *(int *)
         (&g_CardSlot_CardId +
         *(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120 +
         *(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20) = 0xffffffff;
        card_idx = 0;
        do {
          do {
            val_result = Util_GetRandomNumber((&g_PlayerActiveCardCount)[action_param]);
          } while (*(int *)(&g_CardSlot_CardId + val_result * 0x120 + action_param * 0x5b20) == -1);
        } while ((((&g_CardSlot_Flags)[val_result * 0x120 + action_param * 0x5b20] & 2) != 0) &&
                (card_idx = card_idx + 1, card_idx < 999));
        if (card_idx < 999) {
          Ai_Subsystem_004cc56d(player,player,card_index,action_param,val_result,s_randomly_chooses____0052e950,0);
          *(uint32_t *)(&g_CardSlot_Flags + val_result * 0x120 + action_param * 0x5b20) =
               *(uint32_t *)(&g_CardSlot_Flags + val_result * 0x120 + action_param * 0x5b20) ^ 0x1000;
          Pic_Subsystem_0044913a(action_param,val_result);
          if (player == g_CurrentTurnPhase) {
            Pic_Subsystem_00451e40(*(uint32_t *)(&g_CardSlot_CardId + val_result * 0x120 + action_param * 0x5b20));
          }
          else {
            Pic_Subsystem_0045200d(*(uint32_t *)(&g_CardSlot_CardId + val_result * 0x120 + action_param * 0x5b20));
          }
          *(int *)(&g_CardSlot_CardId + val_result * 0x120 + action_param * 0x5b20) = 0xffffffff;
        }
      }
      else if (val_result == 1) {
        (&g_PlayerCreatureCount)[action_param] = (&g_PlayerCreatureCount)[action_param] + -10;
        Pic_Subsystem_0044867e(g_DialogPromptHwnd,g_DuelArenaHwnd,1);
      }
      else if (val_result == 2) {
        (&g_PlayerCreatureCount)[action_param] = 0xffffff9d;
        Pic_Subsystem_0044867e(g_DialogPromptHwnd,g_DuelArenaHwnd,1);
      }
    }
  }
  return;
}

/*
 * Card_XenicPoltergeist_AnimateArtifact
 * Purpose: Execute Xenic Poltergeist ability to animate artifact into creature.
 * Procedure:
 * 1. Validate noncreature artifact target.
 * 2. Set power and toughness equal to converted mana cost.
 * 3. Grant creature type until end of turn.
 */
/*
 * Decompiled function: Card_XenicPoltergeist_AnimateArtifact
 * Entry Point: 004d2610
 * Size: 970 bytes
 */

int Card_XenicPoltergeist_AnimateArtifact(int player,int card_index,int event_code)

{
  int u_res;
  int val_result;
  uint32_t uval_3;
  uint32_t uval_4;
  uint32_t uval_5;
  int arg_11;
  int val_6;
  int arg_12;
  uint32_t uval_7;
  int arg_13;
  uint32_t uval_8;
  int arg_14;
  uint32_t uVar9;
  int arg_15;
  uint32_t uVar10;
  int arg_16;
  uint32_t uVar11;
  int arg_17;
  uint8_t *arg_18;
  int arg_18_00;
  int arg_19;
  int *arg_20;
  int player_idx;
  int card_idx;
  int match_count;
  
  if (event_code == 0x73) {
    if ((*(uint32_t *)(&g_CardSlot_Flags + player * 0x5b20 + card_index * 0x120) & 0x20010) == 0) {
      arg_19 = 0;
      arg_18_00 = 0;
      arg_17 = 0;
      arg_16 = 0xffffffff;
      arg_15 = 0xffffffff;
      arg_14 = 0xffffffff;
      arg_13 = 0xffffffff;
      arg_12 = 0;
      arg_11 = 0;
      u_res = Card_GetColorAndTypeFlags(player,card_index);
      val_result = UI_PaintBigCardInfo((int *)0x0,0,player,2,2,0x200,0x40,2,0,u_res,arg_11,arg_12,arg_13,
                           arg_14,arg_15,arg_16,arg_17,arg_18_00,arg_19);
      if (val_result != 0) {
        return 1;
      }
    }
  }
  else if (event_code == 0x90) {
    Ai_GetOpponentPlayerScore(0);
  }
  else {
    if (event_code == 0x6d) {
      Pic_Subsystem_00424500(s_prompts_txt_0052e97c,s_XENIC_POLTERGEIST_0052e968);
      arg_20 = &player_idx;
      u_res = 1;
      arg_18 = &g_OverworldGoldAmount;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      val_6 = -1;
      val_result = -1;
      uval_5 = 0;
      uval_4 = 0;
      uval_3 = Card_GetColorAndTypeFlags(player,card_index);
      val_result = Duel_ChooseTarget
                        (player,2,player,0x200,0x40,2,0,uval_3,uval_4,uval_5,val_result,val_6,uval_7,
                         uval_8,uVar9,uVar10,uVar11,arg_18,u_res,arg_20);
      if (val_result == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + player * 0x5b20 + card_index * 0x120) = player_idx;
        *(int *)(&g_CardSlot_AttachedAura + player * 0x5b20 + card_index * 0x120) = card_idx;
        (&g_CardSlot_TurnPlayed)[player * 0x5b20 + card_index * 0x120] = 1;
        *(uint32_t *)(&g_CardSlot_Flags + player * 0x5b20 + card_index * 0x120) =
             *(uint32_t *)(&g_CardSlot_Flags + player * 0x5b20 + card_index * 0x120) | 0x10;
      }
    }
    if (event_code == 0x72) {
      player_idx = *(int *)(&g_CardSlot_CombatTarget + player * 0x5b20 + card_index * 0x120);
      card_idx = *(int *)(&g_CardSlot_AttachedAura + player * 0x5b20 + card_index * 0x120);
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      val_6 = -1;
      val_result = -1;
      uval_5 = 0;
      uval_4 = 0;
      uval_3 = Card_GetColorAndTypeFlags(player,card_index);
      val_result = Rules_ParseFilter_0040360b
                        (player_idx,card_idx,(char *)0x0,player,2,2,0x200,0x40,2,0,uval_3,uval_4,uval_5
                         ,val_result,val_6,uval_7,uval_8,uVar9,uVar10,uVar11);
      if (val_result == 0) {
        g_ActivePlayer = 1;
      }
      else {
        match_count = Card_ApplyTriggerEffect(g_DialogPromptHwnd,g_DuelArenaHwnd,DAT_006809d8,player_idx,card_idx);
        if ((match_count != -1) &&
           (val_result = FUN_0041d8a6(*(int *)(&g_CardSlot_CardId + player_idx * 0x5b20 + card_idx * 0x120)
                                ), val_result != -1)) {
          *(int *)(&g_CardSlot_Controller + match_count * 0x120 + player * 0x5b20) = val_result;
          (&g_MasterCardColorTable)[val_result * 0x34] = 0x42;
          *(short *)(&DAT_0051aec4 + val_result * 0x34) =
               (short)(char)(&g_MasterCardManaCostTable)
                            [*(int *)(&g_CardSlot_CardId + player_idx * 0x5b20 + card_idx * 0x120) *
                             0x34];
          *(int16_t *)(&DAT_0051aec2 + val_result * 0x34) =
               *(int16_t *)(&DAT_0051aec4 + val_result * 0x34);
        }
      }
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_TapState + player * 0x5b20 + card_index * 0x120) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + player * 0x5b20 + card_index * 0x120) * 0x120] = 0;
    }
  }
  return 0;
}

/*
 * Card_VesuvanDoppelganger_Copy
 * Purpose: Copy target creature on battlefield as Vesuvan Doppelganger.
 * Procedure:
 * 1. Validate chosen creature target.
 * 2. Copy power, toughness, colors, and abilities.
 * 3. Retain original blue color identity.
 */
/*
 * Decompiled function: Card_VesuvanDoppelganger_Copy
 * Entry Point: 004d29da
 * Size: 573 bytes
 */

int Card_VesuvanDoppelganger_Copy(int player,int card_index,int event_code)

{
  int status;
  uint8_t match_count [4];
  int slot_idx;
  
  if (((event_code == 0x6c) && (g_EventSourceSlot == card_index)) &&
     (g_EventSourcePlayer == player)) {
    Pic_Subsystem_00424500(s_prompts_txt_0052e9a0,s_VESUVAN_DOPPELGANGER_0052e988);
    status = Duel_ChooseTarget
                      (player,2,2,0x200,2,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0,0,0,
                       &g_OverworldGoldAmount,1,(int *)match_count);
    if (status == 0) {
      Pic_Subsystem_0044867e(player,card_index,1);
      g_ActivePlayer = 1;
    }
    else {
      (&g_CardSlot_Toughness)[card_index * 0x120 + player * 0x5b20] = match_count[0];
      *(int *)(&g_CardSlot_OriginalCardId + card_index * 0x120 + player * 0x5b20) = slot_idx;
    }
  }
  if (event_code == 0x71) {
    *(int *)(&g_CardSlot_CardId + card_index * 0x120 + player * 0x5b20) =
         *(int *)
          (&g_CardSlot_CardId +
          *(int *)(&g_CardSlot_OriginalCardId + card_index * 0x120 + player * 0x5b20) * 0x120 +
          (char)(&g_CardSlot_Toughness)[card_index * 0x120 + player * 0x5b20] * 0x5b20);
    (&g_CardSlot_PlusOneCounters)[card_index * 0x120 + player * 0x5b20] =
         (&g_MasterCardColorTable)
         [*(int *)(&g_CardSlot_CardId +
                  *(int *)(&g_CardSlot_OriginalCardId + card_index * 0x120 + player * 0x5b20) *
                  0x120 + (char)(&g_CardSlot_Toughness)[card_index * 0x120 + player * 0x5b20] *
                          0x5b20) * 0x34];
    *(uint32_t *)(&g_CardSlot_Abilities1 + card_index * 0x120 + player * 0x5b20) =
         *(uint32_t *)(&g_CardSlot_Abilities1 + card_index * 0x120 + player * 0x5b20) | 0x2000;
    Magic_TriggerCardEvent(player,card_index,0x6c,1 - player,0xffffffff);
  }
  return 0;
}

/*
 * Card_VesuvanDoppelganger_Upkeep
 * Purpose: Prompt player at upkeep to choose a new Doppelganger mimic target.
 * Procedure:
 * 1. Display prompt asking to switch copied creature.
 * 2. Re-execute copy routine if player approves.
 */
/*
 * Decompiled function: Card_VesuvanDoppelganger_Upkeep
 * Entry Point: 004d2c17
 * Size: 273 bytes
 */

int Card_VesuvanDoppelganger_Upkeep(int player,int card_index,int event_code)

{
  int status;
  
  if (((event_code == 2) && (card_index == g_EventSourceSlot)) && (player == g_EventSourcePlayer)) {
    g_CardEventResult = g_CardEventResult | 1;
  }
  if ((((event_code == 4) && (card_index == g_EventSourceSlot)) && (player == g_EventSourcePlayer)) ||
     (event_code == 199)) {
    if (g_IsAiThinking != 1) {
      strcpy(&g_OverworldWorldState,s_Mimic_0052e9ac);
      Ai_Subsystem_004b90de(player,card_index);
      strcat(&g_OverworldWorldState,s___Mimic_different_creature__0052e9b4);
    }
    status = Ai_Subsystem_004cc56d(player,player,card_index,-1,-1,&g_OverworldWorldState,0);
    if (status != 0) {
      Card_VesuvanDoppelganger_Copy(player,card_index,0x6c);
    }
  }
  return 0;
}

/*
 * Card_Doppelganger_ClearMimic
 * Purpose: Clear copied attributes when Doppelganger leaves play.
 * Procedure:
 * 1. Reset overridden stats to base Doppelganger card stats.
 */
/*
 * Decompiled function: Card_Doppelganger_ClearMimic
 * Entry Point: 004d2d28
 * Size: 258 bytes
 */

int Card_Doppelganger_ClearMimic(int player,int card_index)

{
  if ((((*(int *)(&g_CardSlot_CardId + g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20
                 ) == g_PendingSpellTargetSlot) &&
       (*(int *)(&g_CardSlot_OriginalCardId +
                g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20) == card_index)) &&
      ((char)(&g_CardSlot_Toughness)[g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20]
       == player)) &&
     (*(int *)(&g_MasterCardTypeTable +
              *(int *)(&g_CardSlot_CardId +
                      g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20) * 0x34) ==
      0x197)) {
    *(int *)
     (&g_CardSlot_ConvertedManaCost + g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20)
         = 0;
  }
  return 0;
}

/*
 * Card_Doppelganger_ApplyMimicStats
 * Purpose: Apply copied stats and abilities to Doppelganger slot.
 * Procedure:
 * 1. Copy base power and toughness from source creature.
 */
/*
 * Decompiled function: Card_Doppelganger_ApplyMimicStats
 * Entry Point: 004d2e2a
 * Size: 322 bytes
 */

int Card_Doppelganger_ApplyMimicStats(int player,int card_index)

{
  if ((((*(int *)(&g_CardSlot_CardId + g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20
                 ) == g_PendingSpellTargetSlot) &&
       (*(int *)(&g_CardSlot_OriginalCardId +
                g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20) == card_index)) &&
      ((char)(&g_CardSlot_Toughness)[g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20]
       == player)) &&
     (((&g_MasterCardColorTable)
       [*(int *)(&g_CardSlot_CardId +
                *(int *)(&g_CardSlot_TypeFlags +
                        g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20) * 0x120 +
                (char)(&g_CardSlot_DamageReceived)
                      [g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20] * 0x5b20) *
        0x34] & 2) != 0)) {
    *(int *)
     (&g_CardSlot_ConvertedManaCost + g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20)
         = 0;
  }
  return 0;
}

/*
 * Card_Doppelganger_SyncAbilities
 * Purpose: Synchronize active keyword abilities with copied creature.
 * Procedure:
 * 1. Copy flying, first strike, trample, and protection flags.
 */
/*
 * Decompiled function: Card_Doppelganger_SyncAbilities
 * Entry Point: 004d2f6c
 * Size: 322 bytes
 */

int Card_Doppelganger_SyncAbilities(int player,int card_index)

{
  if ((((*(int *)(&g_CardSlot_CardId + g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20
                 ) == g_PendingSpellTargetSlot) &&
       (*(int *)(&g_CardSlot_OriginalCardId +
                g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20) == card_index)) &&
      ((char)(&g_CardSlot_Toughness)[g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20]
       == player)) &&
     (((&g_MasterCardColorTable)
       [*(int *)(&g_CardSlot_CardId +
                *(int *)(&g_CardSlot_TypeFlags +
                        g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20) * 0x120 +
                (char)(&g_CardSlot_DamageReceived)
                      [g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20] * 0x5b20) *
        0x34] & 0x40) != 0)) {
    *(int *)
     (&g_CardSlot_ConvertedManaCost + g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20)
         = 0;
  }
  return 0;
}

/*
 * Card_Doppelganger_CheckState
 * Purpose: Validate Doppelganger mimic state integrity.
 * Procedure:
 * 1. Check if copied creature reference remains valid.
 */
/*
 * Decompiled function: Card_Doppelganger_CheckState
 * Entry Point: 004d30ae
 * Size: 150 bytes
 */

int Card_Doppelganger_CheckState(int player,int card_index,int event_code)

{
  Card_Doppelganger_SyncAbilities(player,card_index);
  if ((((event_code == 0x78) && (g_EventTargetSlot == card_index)) && (g_EventTargetPlayer == player)) &&
     (((&g_MasterCardColorTable)
       [*(int *)(&g_CardSlot_CardId + g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20)
        * 0x34] & 0x40) != 0)) {
    g_CardEventResult = 1;
  }
  return 0;
}

/*
 * Card_IslandSanctuary_SkipDraw
 * Purpose: Skip draw step to activate Island Sanctuary combat barrier.
 * Procedure:
 * 1. Set flag to skip regular draw step.
 */
/*
 * Decompiled function: Card_IslandSanctuary_SkipDraw
 * Entry Point: 004d3144
 * Size: 101 bytes
 */

int Card_IslandSanctuary_SkipDraw(int player,int card_index,int event_code)

{
  int status;
  
  if (((event_code == 0x78) && (card_index == g_EventSourceSlot)) && (player == g_EventSourcePlayer)) {
    status = Magic_QueryCardAttribute(g_EventTargetPlayer,g_EventTargetSlot,0x32,card_index);
    if (1 < status) {
      g_CardEventResult = 1;
    }
  }
  return 0;
}

/*
 * Card_IslandSanctuary_AttackRestriction
 * Purpose: Apply attack restriction preventing non-flying/islandwalk attackers.
 * Procedure:
 * 1. Check attacker abilities against Island Sanctuary restriction.
 */
/*
 * Decompiled function: Card_IslandSanctuary_AttackRestriction
 * Entry Point: 004d31a9
 * Size: 128 bytes
 */

int Card_IslandSanctuary_AttackRestriction(int player,int card_index,int event_code)

{
  if ((((event_code == 0x78) && (g_EventTargetSlot == card_index)) && (g_EventTargetPlayer == player)) &&
     ((&g_MasterCardRarityTable)
      [*(int *)(&g_CardSlot_CardId + g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20)
       * 0x34] == '\0')) {
    g_CardEventResult = 1;
  }
  return 0;
}

/*
 * Card_IslandSanctuary_Trigger
 * Purpose: Trigger Island Sanctuary upkeep choice.
 * Procedure:
 * 1. Prompt controller to activate protection effect.
 */
/*
 * Decompiled function: Card_IslandSanctuary_Trigger
 * Entry Point: 004d3229
 * Size: 99 bytes
 */

int Card_IslandSanctuary_Trigger(int player,int card_index,int event_code)

{
  int status;
  
  if (((event_code == 0x78) && (card_index == g_EventTargetSlot)) && (player == g_EventTargetPlayer)) {
    status = Magic_QueryCardAttribute(g_EventSourcePlayer,g_EventSourceSlot,0x32,0xffffffff);
    if (2 < status) {
      g_CardEventResult = 1;
    }
  }
  return 0;
}

/*
 * Card_IslandSanctuary_CheckActive
 * Purpose: Check if Island Sanctuary protection is active this turn.
 * Procedure:
 * 1. Return active state flag.
 */
/*
 * Decompiled function: Card_IslandSanctuary_CheckActive
 * Entry Point: 004d328c
 * Size: 158 bytes
 */

int Card_IslandSanctuary_CheckActive(int player,int card_index,int event_code)

{
  uint32_t u_res;
  
  if ((((event_code == 0x78) && (card_index == g_EventTargetSlot)) && (player == g_EventTargetPlayer)) &&
     ((&g_MasterCardRarityTable)
      [*(int *)(&g_CardSlot_CardId + g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20)
       * 0x34] != '\0')) {
    u_res = Magic_QueryCardAttribute(g_EventSourcePlayer,g_EventSourceSlot,0x34,0xffffffff);
    if ((u_res & 0x20) == 0) {
      g_CardEventResult = 1;
    }
  }
  return 0;
}

/*
 * Card_IslandSanctuary_Prompt
 * Purpose: Display Island Sanctuary activation prompt.
 * Procedure:
 * 1. Load prompt text and query player decision.
 */
/*
 * Decompiled function: Card_IslandSanctuary_Prompt
 * Entry Point: 004d332a
 * Size: 531 bytes
 */

int Card_IslandSanctuary_Prompt(int player,int card_index,int event_code)

{
  if (((((event_code == 0x6e) &&
        (*(int *)(&g_CardSlot_CardId + g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20
                 ) == g_PendingSpellTargetSlot)) &&
       (*(int *)(&g_CardSlot_OriginalCardId +
                g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20) == -1)) &&
      (((char)(&g_CardSlot_DamageReceived)
              [g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20] == player &&
       (*(int *)(&g_CardSlot_TypeFlags +
                g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20) == card_index)))) &&
     (*(int *)(&g_CardSlot_ConvertedManaCost +
              g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20) != 0)) {
    (&g_CardSlot_DamageReceived)[card_index * 0x120 + player * 0x5b20] =
         (uint8_t)g_EventSourcePlayer;
    *(int *)(&g_CardSlot_TypeFlags + card_index * 0x120 + player * 0x5b20) = g_EventSourceSlot;
  }
  if (((g_CurrentStepCode == 0xd7) && (g_EventSourceSlot == card_index)) &&
     ((g_EventSourcePlayer == player &&
      (((&g_CardSlot_DamageReceived)[card_index * 0x120 + player * 0x5b20] != -1 &&
       (g_CurrentCardColorTarget == player)))))) {
    if (event_code == 0x7d) {
      g_CardEventResult = g_CardEventResult | 2;
    }
    if (event_code == 0x7e) {
      Prompts_Load_0046fa40
                ((int)(char)(&g_CardSlot_DamageReceived)[card_index * 0x120 + player * 0x5b20],1,0);
      (&g_CardSlot_DamageReceived)[card_index * 0x120 + player * 0x5b20] = 0xff;
    }
  }
  return 0;
}

/*
 * Card_LivingLands_AnimateForests
 * Purpose: Apply Living Lands continuous effect making Forests 1/1 creatures.
 * Procedure:
 * 1. Iterate all lands in play.
 * 2. Set Forest permanents to 1/1 creatures.
 */
/*
 * Decompiled function: Card_LivingLands_AnimateForests
 * Entry Point: 004d353d
 * Size: 528 bytes
 */

int Card_LivingLands_AnimateForests(int player,int card_index,int event_code)

{
  if (((((event_code == 0x6e) &&
        (*(int *)(&g_CardSlot_CardId + g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20
                 ) == g_PendingSpellTargetSlot)) &&
       (*(int *)(&g_CardSlot_OriginalCardId +
                g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20) == -1)) &&
      (((char)(&g_CardSlot_DamageReceived)
              [g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20] == player &&
       (*(int *)(&g_CardSlot_TypeFlags +
                g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20) == card_index)))) &&
     (*(int *)(&g_CardSlot_ConvertedManaCost +
              g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20) != 0)) {
    (&g_CardSlot_DamageReceived)[player * 0x5b20 + card_index * 0x120] =
         (uint8_t)g_EventSourcePlayer;
    *(int *)(&g_CardSlot_TypeFlags + player * 0x5b20 + card_index * 0x120) = g_EventSourceSlot;
  }
  if (((g_CurrentStepCode == 0xd7) && (card_index == g_EventSourceSlot)) &&
     ((player == g_EventSourcePlayer &&
      (((&g_CardSlot_DamageReceived)[player * 0x5b20 + card_index * 0x120] != -1 &&
       (player == g_CurrentCardColorTarget)))))) {
    if (event_code == 0x7d) {
      g_CardEventResult = g_CardEventResult | 2;
    }
    if (event_code == 0x7e) {
      (&DAT_00696870)[(char)(&g_CardSlot_DamageReceived)[player * 0x5b20 + card_index * 0x120]] =
           (&DAT_00696870)[(char)(&g_CardSlot_DamageReceived)[player * 0x5b20 + card_index * 0x120]] + 2;
      (&g_CardSlot_DamageReceived)[player * 0x5b20 + card_index * 0x120] = 0xff;
      FUN_005062b1();
    }
  }
  return 0;
}

/*
 * Card_KormusBell_AnimateSwamps
 * Purpose: Apply Kormus Bell continuous effect making Swamps 1/1 creatures.
 * Procedure:
 * 1. Iterate all lands in play.
 * 2. Set Swamp permanents to 1/1 creatures.
 */
/*
 * Decompiled function: Card_KormusBell_AnimateSwamps
 * Entry Point: 004d374d
 * Size: 528 bytes
 */

int Card_KormusBell_AnimateSwamps(int player,int card_index,int event_code)

{
  if (((((event_code == 0x6e) &&
        (*(int *)(&g_CardSlot_CardId + g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20
                 ) == g_PendingSpellTargetSlot)) &&
       (*(int *)(&g_CardSlot_OriginalCardId +
                g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20) == -1)) &&
      (((char)(&g_CardSlot_DamageReceived)
              [g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20] == player &&
       (*(int *)(&g_CardSlot_TypeFlags +
                g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20) == card_index)))) &&
     (*(int *)(&g_CardSlot_ConvertedManaCost +
              g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20) != 0)) {
    (&g_CardSlot_DamageReceived)[card_index * 0x120 + player * 0x5b20] =
         (uint8_t)g_EventSourcePlayer;
    *(int *)(&g_CardSlot_TypeFlags + card_index * 0x120 + player * 0x5b20) = g_EventSourceSlot;
  }
  if (((g_CurrentStepCode == 0xd7) && (card_index == g_EventSourceSlot)) &&
     ((player == g_EventSourcePlayer &&
      (((&g_CardSlot_DamageReceived)[card_index * 0x120 + player * 0x5b20] != -1 &&
       (g_CurrentCardColorTarget == player)))))) {
    if (event_code == 0x7d) {
      g_CardEventResult = g_CardEventResult | 2;
    }
    if (event_code == 0x7e) {
      (&DAT_00696870)[(char)(&g_CardSlot_DamageReceived)[card_index * 0x120 + player * 0x5b20]] =
           (&DAT_00696870)[(char)(&g_CardSlot_DamageReceived)[card_index * 0x120 + player * 0x5b20]] + 1;
      (&g_CardSlot_DamageReceived)[card_index * 0x120 + player * 0x5b20] = 0xff;
      FUN_005062b1();
    }
  }
  return 0;
}

/*
 * Card_TitaniasSong_AnimateArtifacts
 * Purpose: Apply Titania's Song continuous effect animating noncreature artifacts.
 * Procedure:
 * 1. Iterate artifacts in play.
 * 2. Set power/toughness equal to casting cost.
 * 3. Remove noncreature artifact abilities.
 */
/*
 * Decompiled function: Card_TitaniasSong_AnimateArtifacts
 * Entry Point: 004d395d
 * Size: 960 bytes
 */

int Card_TitaniasSong_AnimateArtifacts(int player,int card_index,int event_code)

{
  char c_res;
  uint32_t u_temp;
  int player;
  int temp_idx;
  int val_4;
  
  if (((((event_code == 0x6e) &&
        (*(int *)(&g_CardSlot_CardId + g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20
                 ) == g_PendingSpellTargetSlot)) &&
       (*(int *)(&g_CardSlot_OriginalCardId +
                g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20) == -1)) &&
      (((char)(&g_CardSlot_DamageReceived)
              [g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20] == player &&
       (*(int *)(&g_CardSlot_TypeFlags +
                g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20) == card_index)))) &&
     (*(int *)(&g_CardSlot_ConvertedManaCost +
              g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20) != 0)) {
    (&g_CardSlot_DamageReceived)[player * 0x5b20 + card_index * 0x120] =
         (uint8_t)g_EventSourcePlayer;
    *(int *)(&g_CardSlot_TypeFlags + player * 0x5b20 + card_index * 0x120) = g_EventSourceSlot;
  }
  if (((g_CurrentStepCode == 0xd7) && (card_index == g_EventSourceSlot)) &&
     ((player == g_EventSourcePlayer &&
      (((&g_CardSlot_DamageReceived)[player * 0x5b20 + card_index * 0x120] != -1 &&
       (player == g_CurrentCardColorTarget)))))) {
    if (event_code == 0x7d) {
      g_CardEventResult = g_CardEventResult | 2;
    }
    if (event_code == 0x7e) {
      c_res = (&g_CardSlot_DamageReceived)[player * 0x5b20 + card_index * 0x120];
      player = (int)c_res;
      temp_idx = Deck_AddCardToDeck(player,DAT_006a28ac);
      if (temp_idx != -1) {
        *(uint32_t *)(&g_CardSlot_Flags + player * 0x5b20 + temp_idx * 0x120) =
             *(uint32_t *)(&g_CardSlot_Flags + player * 0x5b20 + temp_idx * 0x120) | 2;
        *(uint32_t *)(&g_CardSlot_Abilities1 + player * 0x5b20 + temp_idx * 0x120) =
             *(uint32_t *)(&g_CardSlot_Abilities1 + player * 0x5b20 + temp_idx * 0x120) | 8;
        (&g_CardSlot_MinusOneCounters)[player * 0x5b20 + temp_idx * 0x120] =
             (&g_CardSlot_MinusOneCounters)[player * 0x5b20 + card_index * 0x120];
        u_temp = *(uint32_t *)(&g_MasterCardTypeTable +
                         *(int *)(&g_CardSlot_CardId + player * 0x5b20 + card_index * 0x120) * 0x34);
        val_4 = FUN_00478aa4(*(int *)(&g_MasterCardTypeTable +
                                     *(int *)(&g_CardSlot_CardId + player * 0x5b20 + card_index * 0x120) *
                                     0x34),player,card_index);
        *(uint32_t *)(&DAT_006a5f74 + player * 0x5b20 + temp_idx * 0x120) = u_temp | val_4 << 0x10;
        (&g_CardSlot_DamageReceived)[player * 0x5b20 + temp_idx * 0x120] = (uint8_t)player;
        *(int *)(&g_CardSlot_TypeFlags + player * 0x5b20 + temp_idx * 0x120) = card_index;
        (&g_CardSlot_Toughness)[player * 0x5b20 + temp_idx * 0x120] = c_res;
        *(int *)(&g_CardSlot_OriginalCardId + player * 0x5b20 + temp_idx * 0x120) = 0xffffffff;
      }
      (&g_CardSlot_DamageReceived)[player * 0x5b20 + card_index * 0x120] = 0xff;
    }
  }
  return 0;
}

/*
 * Card_TitaniasSong_RemoveAbilities
 * Purpose: Disable native abilities of artifacts animated by Titania's Song.
 * Procedure:
 * 1. Clear ability bitmask flags.
 */
/*
 * Decompiled function: Card_TitaniasSong_RemoveAbilities
 * Entry Point: 004d3d1d
 * Size: 101 bytes
 */

int Card_TitaniasSong_RemoveAbilities(int player,int card_index,int event_code)

{
  if ((((event_code == 0x33) && (card_index == g_EventSourceSlot)) && (player == g_EventSourcePlayer)) &&
     (((&g_CardSlot_Flags)[card_index * 0x120 + player * 0x5b20] & 0x10) == 0)) {
    g_CardEventResult = g_CardEventResult + 3;
  }
  return 0;
}

/*
 * Card_TitaniasSong_RestoreAbilities
 * Purpose: Restore native abilities of artifacts when Titania's Song leaves.
 * Procedure:
 * 1. Re-enable original ability flags.
 */
/*
 * Decompiled function: Card_TitaniasSong_RestoreAbilities
 * Entry Point: 004d3d82
 * Size: 125 bytes
 */

int Card_TitaniasSong_RestoreAbilities(int player,int card_index,int event_code)

{
  if ((((event_code == 0x33) || (event_code == 0x32)) && (card_index == g_EventSourceSlot)) &&
     (((player == g_EventSourcePlayer &&
       (((&g_CardSlot_Flags)[player * 0x5b20 + card_index * 0x120] & 8) != 0)) &&
      (player != g_TurnPlayer)))) {
    g_CardEventResult = g_CardEventResult + 2;
  }
  return 0;
}

/*
 * Card_TitaniasSong_UpdateStatus
 * Purpose: Refresh active status of animated artifacts.
 * Procedure:
 * 1. Re-evaluate active artifact list.
 */
/*
 * Decompiled function: Card_TitaniasSong_UpdateStatus
 * Entry Point: 004d3dff
 * Size: 418 bytes
 */

int Card_TitaniasSong_UpdateStatus(int player,int card_index,int event_code)

{
  if ((((event_code == 0x77) && (g_EventSourceSlot == card_index)) && (g_EventSourcePlayer == player)) &&
     (*(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) == 0)) {
    card_index = Deck_AddCardToDeck
                      (player,*(int *)(&g_CardSlot_CardId + card_index * 0x120 + player * 0x5b20));
    if (card_index != -1) {
      *(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) = 1;
      *(int *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) = 2;
      *(int *)(&g_CardSlot_Abilities2 + card_index * 0x120 + player * 0x5b20) = 0x8000000;
    }
  }
  if (((g_EventSourceSlot == card_index) && (g_EventSourcePlayer == player)) &&
     (*(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) != 0)) {
    if (event_code == 0x34) {
      g_CardEventResult = g_CardEventResult | 0x20;
    }
    if (event_code == 0x32) {
      g_CardEventResult = g_CardEventResult + 4;
    }
    if (event_code == 0x33) {
      g_CardEventResult = g_CardEventResult + 1;
    }
    if (event_code == 0x22) {
      *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) | 2;
    }
  }
  return 0;
}

/*
 * Card_TitaniasSong_ClearFlags
 * Purpose: Clear continuous animation flags.
 * Procedure:
 * 1. Reset artifact status markers.
 */
/*
 * Decompiled function: Card_TitaniasSong_ClearFlags
 * Entry Point: 004d3fa1
 * Size: 248 bytes
 */

int Card_TitaniasSong_ClearFlags(int player,int card_index,int event_code)

{
  if ((((event_code == 0x21) && (g_ScWillyScore == 0x1a)) &&
      (((&g_CardSlot_Flags)[player * 0x5b20 + card_index * 0x120] & 0x10) == 0)) &&
     (((char)(&g_CardSlot_Toughness)[g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20]
       == player &&
      (*(int *)(&g_CardSlot_OriginalCardId +
               g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20) == -1)))) {
    (&g_CardSlot_Toughness)[g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20] =
         (uint8_t)player;
    *(int *)(&g_CardSlot_OriginalCardId +
            g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20) = card_index;
  }
  return 0;
}

/*
 * Card_TitaniasSong_CheckTrigger
 * Purpose: Check if Titania's Song should trigger upon artifact entering play.
 * Procedure:
 * 1. Evaluate newly entered permanent.
 */
/*
 * Decompiled function: Card_TitaniasSong_CheckTrigger
 * Entry Point: 004d4099
 * Size: 373 bytes
 */

int Card_TitaniasSong_CheckTrigger(int player,int card_index,int event_code)

{
  if ((((event_code == 0x21) && (g_ScWillyScore == 0x1a)) &&
      (((&g_CardSlot_Flags)[card_index * 0x120 + player * 0x5b20] & 0x10) == 0)) &&
     ((((char)(&g_CardSlot_Toughness)[g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20]
        == player &&
       (*(int *)(&g_CardSlot_OriginalCardId +
                g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20) == -1)) &&
      (((&g_MasterCardColorTable)
        [*(int *)(&g_CardSlot_CardId +
                 *(int *)(&g_CardSlot_TypeFlags +
                         g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20) * 0x120 +
                 (char)(&g_CardSlot_DamageReceived)
                       [g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20] * 0x5b20) *
         0x34] & 0x40) != 0)))) {
    (&g_CardSlot_Toughness)[g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20] =
         (uint8_t)player;
    *(int *)(&g_CardSlot_OriginalCardId +
            g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20) = card_index;
  }
  return 0;
}

/*
 * Card_PersonalIncarnation_RedirectDamage
 * Purpose: Execute Personal Incarnation damage redirection ability.
 * Procedure:
 * 1. Prompt controller for amount of damage to redirect.
 * 2. Redirect chosen damage to Personal Incarnation.
 */
/*
 * Decompiled function: Card_PersonalIncarnation_RedirectDamage
 * Entry Point: 004d420e
 * Size: 1364 bytes
 */

int Card_PersonalIncarnation_RedirectDamage(int player,int card_index,int event_code)

{
  int u_res;
  int val_result;
  INT_PTR loop_idx;
  int target_idx;
  int player_idx;
  int card_idx;
  int match_count;
  int slot_idx;
  
  if (((event_code == 0x21) &&
      ((char)(&g_CardSlot_Toughness)[g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20]
       == player)) &&
     (*(int *)(&g_CardSlot_OriginalCardId +
              g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20) == card_index)) {
    *(uint32_t *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) =
         *(uint32_t *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) | 1;
  }
  if (event_code == 0x73) {
    if ((((&g_CardSlot_ConvertedManaCost)[card_index * 0x120 + player * 0x5b20] & 1) == 0) ||
       (((uint8_t)g_DuelModeFlags & 4) == 0)) {
      u_res = 0;
    }
    else {
      u_res = 99;
    }
  }
  else if (event_code == 0x90) {
    Ai_GetOpponentPlayerScore(0);
    u_res = 0;
  }
  else {
    if (((event_code == 0x6d) &&
        (((&g_CardSlot_ConvertedManaCost)[card_index * 0x120 + player * 0x5b20] & 1) != 0)) &&
       (((uint8_t)g_DuelModeFlags & 4) != 0)) {
      if (((&DAT_006a5f3d)[card_index * 0x120 + player * 0x5b20] & 0x10) == 0) {
        target_idx = 0;
      }
      else {
        target_idx = 1;
      }
      do {
        Pic_Subsystem_00424500(s_prompts_txt_0052e9ec,s_PERSONAL_INCARNATION_0052e9d4);
        val_result = Duel_ChooseTarget
                          (player,2,2,0x200,0,0,0,0,0,0,g_PendingSpellTargetSlot,-1,0xffffffff,0xffffffff,0,0,
                           0,&g_OverworldGoldAmount,1,&player_idx);
        if (val_result == 0) {
          g_ActivePlayer = 1;
        }
        else if (((char)(&g_CardSlot_Toughness)[player_idx * 0x5b20 + card_idx * 0x120] == player)
                && (*(int *)(&g_CardSlot_OriginalCardId + player_idx * 0x5b20 + card_idx * 0x120) ==
                    card_index)) {
          if (*(int *)(&g_CardSlot_ConvertedManaCost + player_idx * 0x5b20 + card_idx * 0x120) +
              (int)*(short *)(&g_CardSlot_Power + card_index * 0x120 + player * 0x5b20) < 6) {
            loop_idx = 0;
          }
          else {
            loop_idx = *(int *)(&g_CardSlot_ConvertedManaCost + player_idx * 0x5b20 + card_idx * 0x120
                               ) -
                       (5 - *(short *)(&g_CardSlot_Power + card_index * 0x120 + player * 0x5b20));
          }
          slot_idx = Ai_Subsystem_004cc8de
                              (player,s_How_much_damage_to_redirect_to_y_0052e9f8,loop_idx);
          match_count = Card_ApplyCombatDamage(target_idx,-1,slot_idx,
                                 (int)(char)(&g_CardSlot_DamageReceived)
                                            [player_idx * 0x5b20 + card_idx * 0x120],
                                 *(int *)(&g_CardSlot_TypeFlags +
                                         player_idx * 0x5b20 + card_idx * 0x120));
          if (match_count != -1) {
            *(int *)(&DAT_006a5f74 + match_count * 0x120 + player * 0x5b20) =
                 *(int *)(&DAT_006a5f74 + player_idx * 0x5b20 + card_idx * 0x120);
            *(uint32_t *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) =
                 *(uint32_t *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) &
                 0xfffffffe;
            *(int *)(&g_CardSlot_ConvertedManaCost + player_idx * 0x5b20 + card_idx * 0x120) =
                 *(int *)(&g_CardSlot_ConvertedManaCost + player_idx * 0x5b20 + card_idx * 0x120) -
                 slot_idx;
          }
        }
      } while ((g_ActivePlayer != 1) &&
              (((char)(&g_CardSlot_Toughness)[player_idx * 0x5b20 + card_idx * 0x120] != player ||
               (*(int *)(&g_CardSlot_OriginalCardId + player_idx * 0x5b20 + card_idx * 0x120) !=
                card_index))));
    }
    if (event_code == 0x25) {
      *(uint32_t *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) &
           0xfffffffe;
    }
    if ((((event_code == 0x77) && (card_index == g_EventSourceSlot)) &&
        (player == g_EventSourcePlayer)) &&
       (val_result = Deck_AddCardToDeck(player,DAT_006ff564), val_result != -1)) {
      *(int *)(&g_ActiveCardsInPlay + val_result * 0x120 + player * 0x5b20) =
           *(int *)(&g_CardSlot_CardId + card_index * 0x120 + player * 0x5b20);
      *(uint32_t *)(&g_CardSlot_Flags + val_result * 0x120 + player * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_Flags + val_result * 0x120 + player * 0x5b20) |
           CONCAT31((uint3)((uint32_t)*(int *)
                                   (&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) >> 8)
                    & 0x10,2);
      *(int *)(&DAT_006a5f74 + val_result * 0x120 + player * 0x5b20) = 0xb5;
      FUN_00476482(player,val_result);
    }
    u_res = 0;
  }
  return u_res;
}

/*
 * Card_AliFromCairo_PreventLethalDamage
 * Purpose: Execute Ali from Cairo damage prevention preventing life from dropping below 1.
 * Procedure:
 * 1. Check incoming lethal combat or spell damage.
 * 2. Reduce damage such that player life remains at least 1.
 * 3. Log prevention message.
 */
/*
 * Decompiled function: Card_AliFromCairo_PreventLethalDamage
 * Entry Point: 004d4762
 * Size: 1469 bytes
 */

int Card_AliFromCairo_PreventLethalDamage(int player,int card_index,int event_code)

{
  int status;
  int player_idx;
  int card_idx;
  int match_count;
  int slot_idx;
  
  if (((event_code == 0x6c) && (g_EventSourceSlot == card_index)) &&
     (g_EventSourcePlayer == player)) {
    g_SpellStackDepth = g_SpellStackDepth + 0x30;
  }
  if ((event_code == 0x25) && (0 < (int)(&g_PlayerCreatureCount)[player])) {
    slot_idx = 0;
    player_idx = 0;
    while( true ) {
      status = (&g_PlayerActiveCardCount)[g_ActivePlayerPriority];
      if ((int)(&g_PlayerActiveCardCount)[g_ActivePlayerPriority] <=
          (int)(&g_PlayerActiveCardCount)[g_CurrentTurnPhase]) {
        status = (&g_PlayerActiveCardCount)[g_CurrentTurnPhase];
      }
      if (status <= slot_idx) break;
      if ((((*(int *)(&g_CardSlot_CardId + g_CurrentTurnPhase * 0x5b20 + slot_idx * 0x120) ==
             g_PendingSpellTargetSlot) &&
           (((&g_CardSlot_Flags)[g_CurrentTurnPhase * 0x5b20 + slot_idx * 0x120] & 2) != 0)) &&
          ((char)(&g_CardSlot_Toughness)[g_CurrentTurnPhase * 0x5b20 + slot_idx * 0x120] == player)
          ) && (*(int *)(&g_CardSlot_OriginalCardId + g_CurrentTurnPhase * 0x5b20 + slot_idx * 0x120)
                == -1)) {
        player_idx = player_idx +
                   *(int *)(&g_CardSlot_ConvertedManaCost +
                           g_CurrentTurnPhase * 0x5b20 + slot_idx * 0x120);
      }
      if (((*(int *)(&g_CardSlot_CardId + slot_idx * 0x120 + g_ActivePlayerPriority * 0x5b20) ==
            g_PendingSpellTargetSlot) &&
          (((&g_CardSlot_Flags)[slot_idx * 0x120 + g_ActivePlayerPriority * 0x5b20] & 2) != 0)) &&
         (((char)(&g_CardSlot_Toughness)[slot_idx * 0x120 + g_ActivePlayerPriority * 0x5b20] ==
           player &&
          (*(int *)(&g_CardSlot_OriginalCardId + slot_idx * 0x120 + g_ActivePlayerPriority * 0x5b20)
           == -1)))) {
        player_idx = player_idx +
                   *(int *)(&g_CardSlot_ConvertedManaCost +
                           slot_idx * 0x120 + g_ActivePlayerPriority * 0x5b20);
      }
      slot_idx = slot_idx + 1;
    }
    if ((0 < player_idx) && ((int)(&g_PlayerCreatureCount)[player] <= player_idx)) {
      Ai_Subsystem_004cc56d(player,player,card_index,-1,-1,s_is_doin__his_thing__0052ea1c,0);
      player_idx = player_idx + (1 - (&g_PlayerCreatureCount)[player]);
      *(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) = 0;
      while (*(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) <
             player_idx) {
        Pic_Subsystem_00424500(s_prompts_txt_0052ea44,s_ALI_FROM_CAIRO_0052ea34);
        sprintf(&g_OverworldWorldState,&g_OverworldGoldAmount,
                *(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) + 1,
                player_idx);
        Duel_ChooseTarget
                  (player,2,player,0x200,0,0,0,0,0,0,g_PendingSpellTargetSlot,-1,0xffffffff,0xffffffff,0,0,0
                   ,&g_OverworldWorldState,0,&card_idx);
        if (((char)(&g_CardSlot_Toughness)[card_idx * 0x5b20 + match_count * 0x120] == player) &&
           (*(int *)(&g_CardSlot_OriginalCardId + card_idx * 0x5b20 + match_count * 0x120) == -1)) {
          *(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) =
               *(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) + 1;
          if (*(int *)(&g_CardSlot_ConvertedManaCost + card_idx * 0x5b20 + match_count * 0x120) != 0) {
            *(int *)(&g_CardSlot_ConvertedManaCost + card_idx * 0x5b20 + match_count * 0x120) =
                 *(int *)(&g_CardSlot_ConvertedManaCost + card_idx * 0x5b20 + match_count * 0x120) + -1;
          }
          if (g_AiTemporaryCardState == 1) {
            while ((*(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20)
                    < player_idx &&
                   (*(int *)(&g_CardSlot_ConvertedManaCost + card_idx * 0x5b20 + match_count * 0x120) !=
                    0))) {
              *(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) =
                   *(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) +
                   1;
              *(int *)(&g_CardSlot_ConvertedManaCost + card_idx * 0x5b20 + match_count * 0x120) =
                   *(int *)(&g_CardSlot_ConvertedManaCost + card_idx * 0x5b20 + match_count * 0x120) +
                   -1;
            }
          }
          Ai_EvaluateTacticalPosition(0,0x20);
        }
        else if (g_IsAiThinking != 1) {
          Ai_Util_004cc42d(s_Illegal_target__prevent_damage_t_0052ea50);
          Sleep(2000);
          Ai_Util_004cc42d(&DAT_0052ea88);
        }
      }
    }
  }
  if (((event_code == 0x8a) && (g_EventSourceSlot == card_index)) &&
     (g_EventSourcePlayer == player)) {
    g_AiBlockingCreatureCount = g_AiBlockingCreatureCount + 0x18;
  }
  if (((event_code == 0x8b) && (g_EventSourceSlot == card_index)) &&
     (g_EventSourcePlayer == player)) {
    g_AiBlockingCreatureCount = g_AiBlockingCreatureCount + -0x18;
  }
  if ((event_code == 199) && (((&g_CardSlot_Flags)[card_index * 0x120 + player * 0x5b20] & 2) != 0)) {
    if (player == g_ActivePlayerPriority) {
      g_SpellStackDepth = g_SpellStackDepth + 0x1e0;
    }
    else {
      g_SpellStackDepth = g_SpellStackDepth + -0x1e0;
    }
  }
  return 0;
}

/*
 * Card_AliFromCairo_ResetState
 * Purpose: Reset Ali from Cairo prevention tracking at end of turn.
 * Procedure:
 * 1. Clear turn damage counters.
 */
/*
 * Decompiled function: Card_AliFromCairo_ResetState
 * Entry Point: 004d4d1f
 * Size: 596 bytes
 */

int Card_AliFromCairo_ResetState(int player,int card_index,int event_code)

{
  if ((((event_code == 0x80) && ((g_DuelModeFlags._1_1_ & 2) != 0)) &&
      ((char)(&g_CardSlot_Toughness)[g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20]
       == player)) &&
     ((*(int *)(&g_CardSlot_OriginalCardId +
               g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20) == card_index &&
      (0 < *(short *)(&g_CardSlot_Power + card_index * 0x120 + player * 0x5b20))))) {
    *(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) = 1;
  }
  if (((g_CurrentStepCode == 0xd7) && (card_index == g_EventSourceSlot)) &&
     ((player == g_EventSourcePlayer &&
      (0 < *(short *)(&g_CardSlot_Power + card_index * 0x120 + player * 0x5b20))))) {
    *(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) = 1;
  }
  if (((((g_CurrentStepCode == 0xcd) || (event_code == 199)) && (card_index == g_EventSourceSlot)) &&
      ((player == g_EventSourcePlayer &&
       (*(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) != 0)))) &&
     (g_CurrentCardColorTarget == player)) {
    if (event_code == 0x7d) {
      g_CardEventResult = g_CardEventResult | 2;
    }
    if ((event_code == 0x7e) || (event_code == 199)) {
      *(short *)(&g_CardSlot_PowerCounters + card_index * 0x120 + player * 0x5b20) =
           *(short *)(&g_CardSlot_PowerCounters + card_index * 0x120 + player * 0x5b20) + 1;
      *(short *)(&g_CardSlot_ToughnessCounters + card_index * 0x120 + player * 0x5b20) =
           *(short *)(&g_CardSlot_ToughnessCounters + card_index * 0x120 + player * 0x5b20) + 1;
      Card_AddCounters(player,card_index,1);
      *(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) = 0;
    }
  }
  return 0;
}

/*
 * Card_ShivanDragon_PumpFirebreathing
 * Purpose: Activate Shivan Dragon firebreathing (+1/+0 for R).
 * Procedure:
 * 1. Pay R mana cost.
 * 2. Add +1 power boost until end of turn.
 */
/*
 * Decompiled function: Card_ShivanDragon_PumpFirebreathing
 * Entry Point: 004d4f73
 * Size: 1715 bytes
 */

int Card_ShivanDragon_PumpFirebreathing(int player,int card_index,int event_code)

{
  int u_res;
  int val_result;
  
  if (((event_code == 0x6c) && (g_EventSourceSlot == card_index)) && (g_EventSourcePlayer == player)) {
    *(int *)(&g_CardSlot_TargetSlot + card_index * 0x120 + player * 0x5b20) = 0;
    *(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) =
         *(int *)(&g_CardSlot_TargetSlot + card_index * 0x120 + player * 0x5b20);
  }
  if (event_code == 0x73) {
    u_res = Font_DrawString(player,7,1);
  }
  else if (event_code == 0x90) {
    Ai_CalcLifeAdvantage(0);
    u_res = 0;
  }
  else {
    if ((event_code == 0x6d) && (val_result = Font_DrawString(player,7,1), val_result != 0)) {
      if (g_TurnPlayer == player) {
        Ai_CalcManaRequirement_004ba890(player,0,-1);
        if (g_TurnCounter < 1) {
          g_ActivePlayer = 1;
        }
        else {
          *(int *)(&g_CardSlot_TargetSlot + card_index * 0x120 + player * 0x5b20) = g_TurnCounter;
        }
      }
      else {
        Ai_CalcManaRequirement_004ba890(player,0,1);
        *(int *)(&g_CardSlot_TargetSlot + card_index * 0x120 + player * 0x5b20) = 1;
      }
      if (g_ActivePlayer == 1) {
        *(int *)(&g_CardSlot_TargetSlot + card_index * 0x120 + player * 0x5b20) = 0;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + card_index * 0x120 + player * 0x5b20) = player;
        *(int *)(&g_CardSlot_AttachedAura + card_index * 0x120 + player * 0x5b20) = card_index;
        (&g_CardSlot_TurnPlayed)[card_index * 0x120 + player * 0x5b20] = 1;
        if (*(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) == 0) {
          *(uint32_t *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) =
               *(uint32_t *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) | 0x80000;
        }
      }
    }
    if (event_code == 0x72) {
      if (*(int *)(&g_CardSlot_CardId +
                  *(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120 +
                  *(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20) == -1) {
        g_ActivePlayer = 1;
      }
      else {
        *(uint32_t *)(&g_CardSlot_ConvertedManaCost +
                 *(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120 +
                 *(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20) =
             *(int *)(&g_CardSlot_ConvertedManaCost +
                     *(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120 +
                     *(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20) +
             (*(uint32_t *)(&g_CardSlot_TargetSlot + card_index * 0x120 + player * 0x5b20) & 0xff);
        *(uint32_t *)(&g_CardSlot_ConvertedManaCost +
                 *(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120 +
                 *(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20) =
             *(int *)(&g_CardSlot_ConvertedManaCost +
                     *(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120 +
                     *(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20) +
             (*(uint32_t *)(&g_CardSlot_TargetSlot + card_index * 0x120 + player * 0x5b20) & 0xff) * 0x100;
        (&g_CardSlot_TurnPlayed)
        [*(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120 +
         *(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20] = 0;
        if (((&DAT_006a5f56)
             [*(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120 +
              *(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20] & 8) != 0) {
          *(uint32_t *)(&g_CardSlot_ConvertedManaCost +
                   *(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120 +
                   *(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20) =
               *(uint32_t *)(&g_CardSlot_ConvertedManaCost +
                        *(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120
                        + *(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20)
               & 0xfff7ffff;
          val_result = Card_ApplyTriggerEffect(g_DialogPromptHwnd, g_DuelArenaHwnd, g_PlayerSelectionPriority, g_DialogPromptHwnd, g_DuelArenaHwnd);
          if (val_result != -1) {
            *(int16_t *)(&g_CardSlot_PowerCounters + val_result * 0x120 + player * 0x5b20) = 1;
            *(int16_t *)(&g_CardSlot_ToughnessCounters + val_result * 0x120 + player * 0x5b20) = 1;
            *(uint32_t *)(&g_CardSlot_ConvertedManaCost + val_result * 0x120 + player * 0x5b20) =
                 *(uint32_t *)(&g_CardSlot_ConvertedManaCost + val_result * 0x120 + player * 0x5b20) | 0x80000
            ;
          }
        }
      }
    }
    if (event_code == 0x39) {
      u_res = Font_DrawString(player,7,1);
    }
    else if (event_code == 0x3a) {
      u_res = Font_DrawString(player,7,1);
    }
    else {
      if (event_code == 0x8f) {
        g_CardEventResult = g_CardEventResult | 1;
      }
      if (event_code == 199) {
        if (player == g_ActivePlayerPriority) {
          g_SpellStackDepth =
               g_SpellStackDepth + (*(int *)(&g_PlayerManaPoolDelta + player * 0x20) * 3 + 6) * 4;
        }
        else {
          g_SpellStackDepth =
               g_SpellStackDepth + (*(int *)(&g_PlayerManaPoolDelta + player * 0x20) * 3 + 6) * -4;
        }
      }
      if ((event_code == 0x22) || (event_code == 199)) {
        *(int *)(&g_CardSlot_TargetSlot + card_index * 0x120 + player * 0x5b20) = 0;
        *(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) =
             *(int *)(&g_CardSlot_TargetSlot + card_index * 0x120 + player * 0x5b20);
      }
      u_res = 0;
    }
  }
  return u_res;
}

/*
 * Card_DragonWhelp_PumpFirebreathing
 * Purpose: Activate Dragon Whelp firebreathing (+1/+0 for R).
 * Procedure:
 * 1. Pay R mana cost.
 * 2. Increment pump counter.
 * 3. Add +1 power boost until end of turn.
 */
/*
 * Decompiled function: Card_DragonWhelp_PumpFirebreathing
 * Entry Point: 004d5626
 * Size: 1528 bytes
 */

int Card_DragonWhelp_PumpFirebreathing(int player,int card_index,int event_code)

{
  int u_res;
  int val_result;
  
  if (event_code == 1) {
    *(int *)(&DAT_006ff6a0 + player * 0x20) = *(int *)(&DAT_006ff6a0 + player * 0x20) + 1;
  }
  if (((event_code == 0x6c) && (card_index == g_EventSourceSlot)) && (player == g_EventSourcePlayer)) {
    *(int *)(&g_CardSlot_TargetSlot + player * 0x5b20 + card_index * 0x120) = 0;
    *(int *)(&g_CardSlot_ConvertedManaCost + player * 0x5b20 + card_index * 0x120) =
         *(int *)(&g_CardSlot_TargetSlot + player * 0x5b20 + card_index * 0x120);
  }
  if (event_code == 0x73) {
    u_res = Font_DrawString(player,4,1);
  }
  else if (event_code == 0x90) {
    Ai_CalcLifeAdvantage(0);
    u_res = 0;
  }
  else {
    if ((event_code == 0x6d) && (val_result = Font_DrawString(player,4,1), val_result != 0)) {
      if (player == g_TurnPlayer) {
        Ai_CalcManaRequirement_004ba890(player,4,-1);
        if (g_TurnCounter < 1) {
          g_ActivePlayer = 1;
        }
        else {
          *(int *)(&g_CardSlot_TargetSlot + player * 0x5b20 + card_index * 0x120) = g_TurnCounter;
        }
      }
      else {
        Ai_CalcManaRequirement_004ba890(player,4,1);
        *(int *)(&g_CardSlot_TargetSlot + player * 0x5b20 + card_index * 0x120) = 1;
      }
      if (g_ActivePlayer == 1) {
        *(int *)(&g_CardSlot_TargetSlot + player * 0x5b20 + card_index * 0x120) = 0;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + player * 0x5b20 + card_index * 0x120) = player;
        *(int *)(&g_CardSlot_AttachedAura + player * 0x5b20 + card_index * 0x120) = card_index;
        (&g_CardSlot_TurnPlayed)[player * 0x5b20 + card_index * 0x120] = 1;
        if (*(int *)(&g_CardSlot_ConvertedManaCost + player * 0x5b20 + card_index * 0x120) == 0) {
          *(uint32_t *)(&g_CardSlot_ConvertedManaCost + player * 0x5b20 + card_index * 0x120) =
               *(uint32_t *)(&g_CardSlot_ConvertedManaCost + player * 0x5b20 + card_index * 0x120) | 0x80000;
        }
      }
    }
    if (event_code == 0x72) {
      if (*(int *)(&g_CardSlot_CardId +
                  *(int *)(&g_CardSlot_TapState + player * 0x5b20 + card_index * 0x120) * 0x5b20 +
                  *(int *)(&g_CardSlot_SicknessState + player * 0x5b20 + card_index * 0x120) * 0x120) ==
          -1) {
        g_ActivePlayer = 1;
      }
      else {
        *(uint32_t *)(&g_CardSlot_ConvertedManaCost +
                 *(int *)(&g_CardSlot_SicknessState + player * 0x5b20 + card_index * 0x120) * 0x120 +
                 *(int *)(&g_CardSlot_TapState + player * 0x5b20 + card_index * 0x120) * 0x5b20) =
             *(int *)(&g_CardSlot_ConvertedManaCost +
                     *(int *)(&g_CardSlot_SicknessState + player * 0x5b20 + card_index * 0x120) * 0x120 +
                     *(int *)(&g_CardSlot_TapState + player * 0x5b20 + card_index * 0x120) * 0x5b20) +
             (*(uint32_t *)(&g_CardSlot_TargetSlot + player * 0x5b20 + card_index * 0x120) & 0xff);
        (&g_CardSlot_TurnPlayed)
        [*(int *)(&g_CardSlot_TapState + player * 0x5b20 + card_index * 0x120) * 0x5b20 +
         *(int *)(&g_CardSlot_SicknessState + player * 0x5b20 + card_index * 0x120) * 0x120] = 0;
        if (((&DAT_006a5f56)
             [*(int *)(&g_CardSlot_TapState + player * 0x5b20 + card_index * 0x120) * 0x5b20 +
              *(int *)(&g_CardSlot_SicknessState + player * 0x5b20 + card_index * 0x120) * 0x120] & 8) !=
            0) {
          *(uint32_t *)(&g_CardSlot_ConvertedManaCost +
                   *(int *)(&g_CardSlot_SicknessState + player * 0x5b20 + card_index * 0x120) * 0x120 +
                   *(int *)(&g_CardSlot_TapState + player * 0x5b20 + card_index * 0x120) * 0x5b20) =
               *(uint32_t *)(&g_CardSlot_ConvertedManaCost +
                        *(int *)(&g_CardSlot_SicknessState + player * 0x5b20 + card_index * 0x120) * 0x120
                        + *(int *)(&g_CardSlot_TapState + player * 0x5b20 + card_index * 0x120) * 0x5b20)
               & 0xfff7ffff;
          val_result = Card_ApplyTriggerEffect(g_DialogPromptHwnd, g_DuelArenaHwnd, g_PlayerSelectionPriority, g_DialogPromptHwnd, g_DuelArenaHwnd);
          if (val_result != -1) {
            *(uint32_t *)(&g_CardSlot_ConvertedManaCost + val_result * 0x120 + player * 0x5b20) =
                 *(uint32_t *)(&g_CardSlot_ConvertedManaCost + val_result * 0x120 + player * 0x5b20) | 0x80000
            ;
          }
        }
      }
    }
    if (event_code == 0x39) {
      u_res = Font_DrawString(player,4,1);
    }
    else {
      if ((event_code == 0x8f) && (*(int *)(&DAT_0063eea0 + player * 0x20) != 0)) {
        g_CardEventResult = g_CardEventResult | 1;
      }
      if (event_code == 199) {
        if (player == g_ActivePlayerPriority) {
          g_SpellStackDepth =
               g_SpellStackDepth + (*(int *)(&DAT_0063ee40 + player * 0x20) * 3 + 3) * 4;
        }
        else {
          g_SpellStackDepth =
               g_SpellStackDepth + (*(int *)(&DAT_0063ee40 + player * 0x20) * 3 + 3) * -4;
        }
      }
      if ((event_code == 0x22) || (event_code == 199)) {
        *(int *)(&g_CardSlot_TargetSlot + player * 0x5b20 + card_index * 0x120) = 0;
        *(int *)(&g_CardSlot_ConvertedManaCost + player * 0x5b20 + card_index * 0x120) =
             *(int *)(&g_CardSlot_TargetSlot + player * 0x5b20 + card_index * 0x120);
      }
      u_res = 0;
    }
  }
  return u_res;
}

/*
 * Card_DragonWhelp_EndTurnCheck
 * Purpose: Destroy Dragon Whelp at end of turn if pumped more than twice.
 * Procedure:
 * 1. Check pump counter.
 * 2. Destroy Dragon Whelp if counter exceeds 2.
 */
/*
 * Decompiled function: Card_DragonWhelp_EndTurnCheck
 * Entry Point: 004d5c1e
 * Size: 1907 bytes
 */

int Card_DragonWhelp_EndTurnCheck(int player,int card_index,int event_code)

{
  int u_res;
  int val_result;
  int arg_2_00;
  int arg_3_00;
  
  if (event_code == 1) {
    *(int *)(&DAT_006ff6a0 + player * 0x20) = *(int *)(&DAT_006ff6a0 + player * 0x20) + 1;
  }
  if (((event_code == 0x6c) && (card_index == g_EventSourceSlot)) && (player == g_EventSourcePlayer)) {
    *(int *)(&g_CardSlot_TargetSlot + card_index * 0x120 + player * 0x5b20) = 0;
    *(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) =
         *(int *)(&g_CardSlot_TargetSlot + card_index * 0x120 + player * 0x5b20);
  }
  if (event_code == 0x73) {
    val_result = Font_DrawString(player,4,1);
  }
  else if (event_code == 0x90) {
    Ai_CalcLifeAdvantage(0);
    val_result = 0;
  }
  else {
    if ((event_code == 0x6d) &&
       (val_result = Font_DrawString(player,4,1), u_res = g_OverworldPlayerCoordY, val_result != 0)) {
      g_TurnCounter = 0;
      if (player == g_TurnPlayer) {
        if (((player == g_ActivePlayerPriority) ||
            ((*(uint32_t *)(&g_CardSlot_TargetSlot + card_index * 0x120 + player * 0x5b20) & 0xff0000) ==
             0x30000)) || (g_AiTemporaryCardState != 1)) {
          g_OverworldPlayerCoordY = -1;
        }
        else {
          g_OverworldPlayerCoordY =
               3 - ((*(uint32_t *)(&g_CardSlot_TargetSlot + card_index * 0x120 + player * 0x5b20) & 0xff0000)
                   >> 0x10);
        }
        Ai_CalcManaRequirement_004ba890(player,4,-1);
        g_OverworldPlayerCoordY = u_res;
        if (g_TurnCounter < 1) {
          g_ActivePlayer = 1;
        }
      }
      else {
        Ai_CalcManaRequirement_004ba890(player,4,1);
        g_TurnCounter = 1;
      }
      *(uint32_t *)(&g_CardSlot_TargetSlot + card_index * 0x120 + player * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_TargetSlot + card_index * 0x120 + player * 0x5b20) & 0xff0000;
      if (g_ActivePlayer == 1) {
        *(int *)(&g_CardSlot_TargetSlot + card_index * 0x120 + player * 0x5b20) = 0;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + card_index * 0x120 + player * 0x5b20) = player;
        *(int *)(&g_CardSlot_AttachedAura + card_index * 0x120 + player * 0x5b20) = card_index;
        (&g_CardSlot_TurnPlayed)[card_index * 0x120 + player * 0x5b20] = 1;
        *(int *)(&g_CardSlot_TargetSlot + card_index * 0x120 + player * 0x5b20) =
             *(int *)(&g_CardSlot_TargetSlot + card_index * 0x120 + player * 0x5b20) +
             g_TurnCounter * 0x10001;
        if (*(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) == 0) {
          *(uint32_t *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) =
               *(uint32_t *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) | 0x80000;
        }
      }
    }
    if (event_code == 0x72) {
      if (*(int *)(&g_CardSlot_CardId +
                  *(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120 +
                  *(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20) == -1) {
        g_ActivePlayer = 1;
      }
      else {
        *(uint32_t *)(&g_CardSlot_ConvertedManaCost +
                 *(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120 +
                 *(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20) =
             *(int *)(&g_CardSlot_ConvertedManaCost +
                     *(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120 +
                     *(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20) +
             (*(uint32_t *)(&g_CardSlot_TargetSlot + card_index * 0x120 + player * 0x5b20) & 0xff);
        (&g_CardSlot_TurnPlayed)
        [*(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120 +
         *(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20] = 0;
        if (((&DAT_006a5f56)
             [*(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120 +
              *(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20] & 8) != 0) {
          *(uint32_t *)(&g_CardSlot_ConvertedManaCost +
                   *(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120 +
                   *(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20) =
               *(uint32_t *)(&g_CardSlot_ConvertedManaCost +
                        *(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120
                        + *(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20)
               & 0xfff7ffff;
          val_result = Card_ApplyTriggerEffect(g_DialogPromptHwnd, g_DuelArenaHwnd, g_PlayerSelectionPriority, g_DialogPromptHwnd, g_DuelArenaHwnd);
          if (val_result != -1) {
            *(uint32_t *)(&g_CardSlot_ConvertedManaCost + val_result * 0x120 + player * 0x5b20) =
                 *(uint32_t *)(&g_CardSlot_ConvertedManaCost + val_result * 0x120 + player * 0x5b20) | 0x80000
            ;
          }
        }
      }
    }
    if (event_code == 0x39) {
      arg_3_00 = 3;
      arg_2_00 = 0;
      val_result = Font_DrawString(player,4,1);
      val_result = Math_Clamp(val_result, arg_2_00, arg_3_00);
      val_result = val_result - *(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20);
    }
    else {
      if (((((g_CurrentStepCode == 0xcd) || (event_code == 199)) && (card_index == g_EventSourceSlot)) &&
          ((player == g_EventSourcePlayer &&
           ((&g_CardSlot_ConvertedManaCost)[card_index * 0x120 + player * 0x5b20] != '\0')))) &&
         (player == g_CurrentCardColorTarget)) {
        if (*(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) < 4) {
          *(int *)(&g_CardSlot_TargetSlot + card_index * 0x120 + player * 0x5b20) = 0;
          *(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) =
               *(int *)(&g_CardSlot_TargetSlot + card_index * 0x120 + player * 0x5b20);
        }
        else {
          if (event_code == 0x7d) {
            g_CardEventResult = g_CardEventResult | 2;
          }
          if ((event_code == 0x7e) || (event_code == 199)) {
            Pic_Subsystem_0044867e(player,card_index,2);
          }
        }
      }
      if (event_code == 199) {
        if (player == g_ActivePlayerPriority) {
          g_SpellStackDepth = g_SpellStackDepth + *(int *)(&DAT_0063ee40 + player * 0x20) * 0xc;
        }
        else {
          g_SpellStackDepth = g_SpellStackDepth + *(int *)(&DAT_0063ee40 + player * 0x20) * -0xc;
        }
      }
      val_result = 0;
    }
  }
  return val_result;
}

/*
 * Card_FrozenShade_ClearBoost
 * Purpose: Clear Frozen Shade power and toughness boost at cleanup.
 * Procedure:
 * 1. Reset temporary power/toughness buffs.
 */
/*
 * Decompiled function: Card_FrozenShade_ClearBoost
 * Entry Point: 004d6391
 * Size: 111 bytes
 */

int Card_FrozenShade_ClearBoost(int player,int card_index)

{
  if ((player == g_EventSourcePlayer) &&
     ((&g_MasterCardRarityTable)
      [*(int *)(&g_CardSlot_CardId + g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20)
       * 0x34] == '\x04')) {
    Pic_Subsystem_0044867e(player,card_index,1);
  }
  return 0;
}

/*
 * Card_FrozenShade_PumpBlack
 * Purpose: Activate Frozen Shade pump ability (+1/+1 for B).
 * Procedure:
 * 1. Pay B mana cost.
 * 2. Add +1/+1 buff until end of turn.
 */
/*
 * Decompiled function: Card_FrozenShade_PumpBlack
 * Entry Point: 004d6400
 * Size: 774 bytes
 */

int Card_FrozenShade_PumpBlack(int player,int card_index,int event_code)

{
  int status;
  int u_temp;
  
  if (event_code == 0x6c) {
    *(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) = 0x20;
  }
  if (event_code == 1) {
    *(int *)(&DAT_006ff6a0 + player * 0x20) = *(int *)(&DAT_006ff6a0 + player * 0x20) + 1;
  }
  if (event_code == 0x73) {
    if ((*(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) == 0) ||
       (status = Font_DrawString(player,4,1), status == 0)) {
      u_temp = 0;
    }
    else {
      u_temp = 1;
    }
  }
  else {
    if (((event_code == 0x6d) && (status = Font_DrawString(player,4,1), status != 0)) &&
       (Ai_CalcManaRequirement_004ba890(player,4,1), g_ActivePlayer != 1)) {
      *(int *)(&g_CardSlot_CombatTarget + card_index * 0x120 + player * 0x5b20) = player;
      *(int *)(&g_CardSlot_AttachedAura + card_index * 0x120 + player * 0x5b20) = card_index;
      (&g_CardSlot_TurnPlayed)[card_index * 0x120 + player * 0x5b20] = 1;
      if (g_ActivePlayerPriority == player) {
        *(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) = 0;
      }
    }
    if (event_code == 0x72) {
      if (*(int *)(&g_CardSlot_CardId +
                  *(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120 +
                  *(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20) == -1) {
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_TurnPlayed)
        [*(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120 +
         *(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20] = 0;
        *(int *)
         (&g_CardSlot_ConvertedManaCost +
         *(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120 +
         *(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20) = 0x20;
        status = Card_ApplyTriggerEffect(g_DialogPromptHwnd,g_DuelArenaHwnd,DAT_0069f6dc,g_DialogPromptHwnd,
                             g_DuelArenaHwnd);
        if (status != -1) {
          *(int *)(&g_CardSlot_ConvertedManaCost + status * 0x120 + player * 0x5b20) = 0x20;
        }
      }
    }
    u_temp = 0;
  }
  return u_temp;
}

/*
 * Card_WaterElemental_PumpBlue
 * Purpose: Activate Water Elemental pump ability (+1/-1 for U).
 * Procedure:
 * 1. Pay U mana cost.
 * 2. Modify power and toughness.
 */
/*
 * Decompiled function: Card_WaterElemental_PumpBlue
 * Entry Point: 004d6706
 * Size: 313 bytes
 */

int Card_WaterElemental_PumpBlue(int player,int card_index,int event_code)

{
  int status;
  int u_temp;
  int arg_2_00;
  int arg_3_00;
  
  if (event_code == 1) {
    *(int *)(&DAT_006ff6a0 + player * 0x20) = *(int *)(&DAT_006ff6a0 + player * 0x20) + 1;
  }
  if (event_code == 0x73) {
    if ((*(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) == 0) &&
       (status = Font_DrawString(player,4,1), status != 0)) {
      u_temp = 1;
    }
    else {
      u_temp = 0;
    }
  }
  else {
    if ((event_code == 0x6d) && (status = Font_DrawString(player,4,1), status != 0)) {
      Ai_CalcManaRequirement_004ba890(player,4,1);
    }
    if ((event_code == 0x72) && (status = Card_ApplyTriggerEffect(player,card_index,g_PlayerSelectionPriority,player,card_index), status != -1)
       ) {
      *(int16_t *)(&g_CardSlot_PowerCounters + status * 0x120 + player * 0x5b20) = 1;
    }
    if (event_code == 0x39) {
      arg_3_00 = 1;
      arg_2_00 = 0;
      status = Font_DrawString(player,4,1);
      u_temp = Math_Clamp(status,arg_2_00,arg_3_00);
    }
    else {
      u_temp = 0;
    }
  }
  return u_temp;
}

/*
 * Card_ClockworkBeast_ResetCounters
 * Purpose: Initialize +1/+0 counters on Clockwork Beast.
 * Procedure:
 * 1. Set +1/+0 counters to 7 upon entering play.
 */
/*
 * Decompiled function: Card_ClockworkBeast_ResetCounters
 * Entry Point: 004d683f
 * Size: 661 bytes
 */

int Card_ClockworkBeast_ResetCounters(int player,int card_index,int event_code)

{
  uint32_t u_res;
  char cVar2;
  
  if (((event_code == 0x34) && (card_index == g_EventSourceSlot)) && (player == g_EventSourcePlayer)) {
    cVar2 = Card_SetTapState(player, card_index, 1);
    g_CardEventResult = g_CardEventResult | 0x800 << (cVar2 - 1U & 0x1f);
    u_res = g_CardEventResult;
    Card_RockHydra_UpdateStatsFromHeads(player,card_index,1);
    g_CardEventResult = u_res;
  }
  if ((((event_code == 0x6e) &&
       (*(int *)(&g_CardSlot_CardId + g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20)
        == g_PendingSpellTargetSlot)) &&
      ((*(int *)(&g_CardSlot_OriginalCardId +
                g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20) == -1 &&
       (((char)(&g_CardSlot_DamageReceived)
               [g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20] == player &&
        (*(int *)(&g_CardSlot_TypeFlags +
                 g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20) == card_index)))))) &&
     (*(int *)(&g_CardSlot_ConvertedManaCost +
              g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20) != 0)) {
    *(int *)(&g_CardSlot_ConvertedManaCost + player * 0x5b20 + card_index * 0x120) = 1;
  }
  if (((((g_CurrentStepCode == 0xcd) || (event_code == 199)) && (card_index == g_EventSourceSlot)) &&
      ((player == g_EventSourcePlayer &&
       (*(int *)(&g_CardSlot_ConvertedManaCost + player * 0x5b20 + card_index * 0x120) != 0)))) &&
     (player == g_CurrentCardColorTarget)) {
    if (event_code == 0x7d) {
      g_CardEventResult = g_CardEventResult | 2;
    }
    if ((event_code == 0x7e) || (event_code == 199)) {
      Card_IncrementCounter(player,card_index);
      *(short *)(&g_CardSlot_PowerCounters + player * 0x5b20 + card_index * 0x120) =
           *(short *)(&g_CardSlot_PowerCounters + player * 0x5b20 + card_index * 0x120) + 1;
      *(short *)(&g_CardSlot_ToughnessCounters + player * 0x5b20 + card_index * 0x120) =
           *(short *)(&g_CardSlot_ToughnessCounters + player * 0x5b20 + card_index * 0x120) + 1;
      *(int *)(&g_CardSlot_ConvertedManaCost + player * 0x5b20 + card_index * 0x120) = 0;
    }
  }
  return 0;
}

/*
 * Card_ClockworkBeast_CombatTrigger
 * Purpose: Deduct counter from Clockwork Beast after attacking or blocking.
 * Procedure:
 * 1. Deduct 1 counter at end of combat.
 */
/*
 * Decompiled function: Card_ClockworkBeast_CombatTrigger
 * Entry Point: 004d6ad4
 * Size: 367 bytes
 */

int Card_ClockworkBeast_CombatTrigger(int player,int card_index,int event_code)

{
  char c_res;
  uint8_t is_match;
  int temp_idx;
  bool bVar4;
  int slot_idx;
  
  if (((event_code == 0x34) && (card_index == g_EventSourceSlot)) && (player == g_EventSourcePlayer)) {
    c_res = Card_UntapCard(player, card_index, 4);
    g_CardEventResult = g_CardEventResult | 0x800 << (c_res - 1U & 0x1f);
  }
  if (((event_code == 0x32) || (event_code == 0x33)) &&
     ((card_index == g_EventSourceSlot && (player == g_EventSourcePlayer)))) {
    temp_idx = Card_SetTapState(player,card_index,5);
    bVar4 = *(int *)(&g_AiCombatScore_Attacker + temp_idx * 4 + (1 - player) * 0x20) != 0;
    if (!bVar4) {
      for (slot_idx = 0; slot_idx < 0x50; slot_idx = slot_idx + 1) {
        temp_idx = Card_IsTapped(1 - player,slot_idx);
        if ((temp_idx != 0) &&
           (c_res = (&g_CardSlot_PlusOneCounters)[slot_idx * 0x120 + (1 - player) * 0x5b20],
           is_match = Card_SetTapState(player,card_index,5), (1 << (is_match & 0x1f) & (int)c_res) != 0)) {
          bVar4 = true;
          break;
        }
      }
    }
    if (bVar4) {
      g_CardEventResult = g_CardEventResult + 1;
    }
  }
  return 0;
}

/*
 * Card_ClockworkBeast_Rewind
 * Purpose: Pay mana during upkeep to wind up Clockwork Beast counters.
 * Procedure:
 * 1. Prompt player to pay mana to restore +1/+0 counters.
 */
/*
 * Decompiled function: Card_ClockworkBeast_Rewind
 * Entry Point: 004d6c43
 * Size: 319 bytes
 */

int Card_ClockworkBeast_Rewind(int player,int card_index,int event_code)

{
  int u_res;
  int val_result;
  
  if (event_code == 1) {
    *(int *)(&DAT_006ff6a0 + player * 0x20) = *(int *)(&DAT_006ff6a0 + player * 0x20) + 1;
  }
  if (event_code == 0x73) {
    u_res = Font_DrawString(player,4,1);
  }
  else {
    if (event_code == 0x6d) {
      val_result = Font_DrawString(player,4,1);
      if (val_result != 0) {
        Ai_CalcManaRequirement_004ba890(player,4,1);
        if (g_ActivePlayer != 1) {
          *(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) = 1;
        }
      }
    }
    if (event_code == 0x72) {
      val_result = Card_ApplyTriggerEffect(player,card_index,g_PlayerSelectionPriority,player,card_index);
      if (val_result != -1) {
        *(short *)(&g_CardSlot_ToughnessCounters + val_result * 0x120 + player * 0x5b20) =
             (short)*(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20);
      }
    }
    if (event_code == 0x3a) {
      u_res = Font_DrawString(player,4,1);
    }
    else {
      u_res = 0;
    }
  }
  return u_res;
}

/*
 * Card_ClockworkBeast_GetPower
 * Purpose: Calculate effective power of Clockwork Beast.
 * Procedure:
 * 1. Return base power plus active counter count.
 */
/*
 * Decompiled function: Card_ClockworkBeast_GetPower
 * Entry Point: 004d6d82
 * Size: 247 bytes
 */

int Card_ClockworkBeast_GetPower(int player,int card_index,int event_code)

{
  int status;
  
  if (event_code == 0x71) {
    status = Card_ApplyTriggerEffect(player,card_index,DAT_00701000,player,card_index);
    if (status != -1) {
      *(int *)(&g_CardSlot_ConvertedManaCost + status * 0x120 + player * 0x5b20) = 1;
      *(int *)(&g_CardSlot_TargetSlot + status * 0x120 + player * 0x5b20) = 0x10d;
      *(int *)(&g_CardSlot_Abilities1 + status * 0x120 + player * 0x5b20) = 0x10000;
      (&g_CardSlot_DamageReceived)[card_index * 0x120 + player * 0x5b20] = (uint8_t)player;
      *(int *)(&g_CardSlot_TypeFlags + card_index * 0x120 + player * 0x5b20) = status;
    }
  }
  return 0;
}

/*
 * Card_ClockworkBeast_GetToughness
 * Purpose: Calculate effective toughness of Clockwork Beast.
 * Procedure:
 * 1. Return base toughness plus active counter count.
 */
/*
 * Decompiled function: Card_ClockworkBeast_GetToughness
 * Entry Point: 004d6e79
 * Size: 492 bytes
 */

int Card_ClockworkBeast_GetToughness(int player,int card_index,int event_code)

{
  int status;
  
  if (event_code == 0x71) {
    status = Card_ApplyTriggerEffect(player,card_index,DAT_00701000,player,card_index);
    if (status != -1) {
      *(int *)(&g_CardSlot_ConvertedManaCost + status * 0x120 + player * 0x5b20) = 1;
      *(int *)(&g_CardSlot_TargetSlot + status * 0x120 + player * 0x5b20) = 0x10e;
      *(int *)(&g_CardSlot_Abilities1 + status * 0x120 + player * 0x5b20) = 0x10000;
      (&g_CardSlot_DamageReceived)[card_index * 0x120 + player * 0x5b20] = (uint8_t)player;
      *(int *)(&g_CardSlot_TypeFlags + card_index * 0x120 + player * 0x5b20) = status;
    }
  }
  if ((((event_code == 0x32) || (event_code == 0x33)) && (card_index == g_EventSourceSlot)) &&
     (player == g_EventSourcePlayer)) {
    if (player == g_TurnPlayer) {
      *(uint32_t *)(&g_CardSlot_TargetSlot +
               *(int *)(&g_CardSlot_TypeFlags + card_index * 0x120 + player * 0x5b20) * 0x120 +
               (char)(&g_CardSlot_DamageReceived)[card_index * 0x120 + player * 0x5b20] * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_TargetSlot +
                    *(int *)(&g_CardSlot_TypeFlags + card_index * 0x120 + player * 0x5b20) * 0x120 +
                    (char)(&g_CardSlot_DamageReceived)[card_index * 0x120 + player * 0x5b20] * 0x5b20) | 2
      ;
    }
    else {
      *(uint32_t *)(&g_CardSlot_TargetSlot +
               *(int *)(&g_CardSlot_TypeFlags + card_index * 0x120 + player * 0x5b20) * 0x120 +
               (char)(&g_CardSlot_DamageReceived)[card_index * 0x120 + player * 0x5b20] * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_TargetSlot +
                    *(int *)(&g_CardSlot_TypeFlags + card_index * 0x120 + player * 0x5b20) * 0x120 +
                    (char)(&g_CardSlot_DamageReceived)[card_index * 0x120 + player * 0x5b20] * 0x5b20) &
           0xfffffffd;
    }
  }
  return 0;
}

/*
 * Card_GaeasLiege_TransformLand
 * Purpose: Transform target land into Forest with Gaea's Liege.
 * Procedure:
 * 1. Validate chosen target land.
 * 2. Override land type to Forest until Gaea's Liege leaves.
 */
/*
 * Decompiled function: Card_GaeasLiege_TransformLand
 * Entry Point: 004d7065
 * Size: 1727 bytes
 */

int Card_GaeasLiege_TransformLand(int player,int card_index,int event_code)

{
  int u_res;
  int val_result;
  uint32_t uval_3;
  uint32_t uval_4;
  uint32_t uval_5;
  int arg_11;
  int val_6;
  int arg_12;
  uint32_t uval_7;
  int arg_13;
  uint32_t uval_8;
  int arg_14;
  uint32_t uVar9;
  int arg_15;
  uint32_t uVar10;
  int arg_16;
  uint32_t uVar11;
  int arg_17;
  uint8_t *arg_18;
  int arg_18_00;
  int arg_19;
  int *arg_20;
  int card_idx;
  int match_count;
  int slot_idx;
  
  if ((event_code == 0x71) &&
     (slot_idx = Card_ApplyTriggerEffect(player,card_index,DAT_00701000,player,card_index), slot_idx != -1)) {
    *(int *)(&g_CardSlot_ConvertedManaCost + slot_idx * 0x120 + player * 0x5b20) = 3;
    *(int *)(&g_CardSlot_TargetSlot + slot_idx * 0x120 + player * 0x5b20) = 0x10d;
    *(int *)(&g_CardSlot_Abilities1 + slot_idx * 0x120 + player * 0x5b20) = 0x10000;
    (&g_CardSlot_DamageReceived)[card_index * 0x120 + player * 0x5b20] = (uint8_t)player;
    *(int *)(&g_CardSlot_TypeFlags + card_index * 0x120 + player * 0x5b20) = slot_idx;
  }
  if ((((event_code == 0x32) || (event_code == 0x33)) && (card_index == g_EventSourceSlot)) &&
     (player == g_EventSourcePlayer)) {
    if (((&g_CardSlot_Flags)[card_index * 0x120 + player * 0x5b20] & 4) == 0) {
      *(uint32_t *)(&g_CardSlot_TargetSlot +
               *(int *)(&g_CardSlot_TypeFlags + card_index * 0x120 + player * 0x5b20) * 0x120 +
               (char)(&g_CardSlot_DamageReceived)[card_index * 0x120 + player * 0x5b20] * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_TargetSlot +
                    *(int *)(&g_CardSlot_TypeFlags + card_index * 0x120 + player * 0x5b20) * 0x120
                    + (char)(&g_CardSlot_DamageReceived)[card_index * 0x120 + player * 0x5b20] *
                      0x5b20) | 1;
      *(uint32_t *)(&g_CardSlot_TargetSlot +
               *(int *)(&g_CardSlot_TypeFlags + card_index * 0x120 + player * 0x5b20) * 0x120 +
               (char)(&g_CardSlot_DamageReceived)[card_index * 0x120 + player * 0x5b20] * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_TargetSlot +
                    *(int *)(&g_CardSlot_TypeFlags + card_index * 0x120 + player * 0x5b20) * 0x120
                    + (char)(&g_CardSlot_DamageReceived)[card_index * 0x120 + player * 0x5b20] *
                      0x5b20) & 0xfffffffd;
    }
    else {
      *(uint32_t *)(&g_CardSlot_TargetSlot +
               *(int *)(&g_CardSlot_TypeFlags + card_index * 0x120 + player * 0x5b20) * 0x120 +
               (char)(&g_CardSlot_DamageReceived)[card_index * 0x120 + player * 0x5b20] * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_TargetSlot +
                    *(int *)(&g_CardSlot_TypeFlags + card_index * 0x120 + player * 0x5b20) * 0x120
                    + (char)(&g_CardSlot_DamageReceived)[card_index * 0x120 + player * 0x5b20] *
                      0x5b20) | 2;
      *(uint32_t *)(&g_CardSlot_TargetSlot +
               *(int *)(&g_CardSlot_TypeFlags + card_index * 0x120 + player * 0x5b20) * 0x120 +
               (char)(&g_CardSlot_DamageReceived)[card_index * 0x120 + player * 0x5b20] * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_TargetSlot +
                    *(int *)(&g_CardSlot_TypeFlags + card_index * 0x120 + player * 0x5b20) * 0x120
                    + (char)(&g_CardSlot_DamageReceived)[card_index * 0x120 + player * 0x5b20] *
                      0x5b20) & 0xfffffffe;
    }
  }
  if (event_code == 0x73) {
    if ((*(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) & 0x20010) == 0) {
      arg_19 = 0;
      arg_18_00 = 0;
      arg_17 = 0;
      arg_16 = 0xffffffff;
      arg_15 = 0xffffffff;
      arg_14 = 0xffffffff;
      arg_13 = 0xffffffff;
      arg_12 = 0;
      arg_11 = 0;
      u_res = Card_GetColorAndTypeFlags(player,card_index);
      val_result = UI_PaintBigCardInfo((int *)0x0,0,player,2,2,0x200,1,0,0,u_res,arg_11,arg_12,arg_13,arg_14,
                           arg_15,arg_16,arg_17,arg_18_00,arg_19);
      if (val_result != 0) {
        return 1;
      }
    }
  }
  else if (event_code == 0x90) {
    Ai_GetOpponentPlayerScore(0);
  }
  else {
    if (event_code == 0x6d) {
      Pic_Subsystem_00424500(s_prompts_txt_0052ea98,s_GAEAS_LIEGE_0052ea8c);
      arg_20 = &card_idx;
      u_res = 1;
      arg_18 = &g_OverworldGoldAmount;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      val_6 = -1;
      val_result = -1;
      uval_5 = 0;
      uval_4 = 0;
      uval_3 = Card_GetColorAndTypeFlags(player,card_index);
      val_result = Duel_ChooseTarget
                        (player,2,1 - player,0x200,1,0,0,uval_3,uval_4,uval_5,val_result,val_6,uval_7,
                         uval_8,uVar9,uVar10,uVar11,arg_18,u_res,arg_20);
      if (val_result == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + card_index * 0x120 + player * 0x5b20) = card_idx;
        *(int *)(&g_CardSlot_AttachedAura + card_index * 0x120 + player * 0x5b20) = match_count;
        (&g_CardSlot_TurnPlayed)[card_index * 0x120 + player * 0x5b20] = 1;
        *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) | 0x10;
      }
    }
    if (event_code == 0x72) {
      card_idx = *(int *)(&g_CardSlot_CombatTarget + card_index * 0x120 + player * 0x5b20);
      match_count = *(int *)(&g_CardSlot_AttachedAura + card_index * 0x120 + player * 0x5b20);
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      val_6 = -1;
      val_result = -1;
      uval_5 = 0;
      uval_4 = 0;
      uval_3 = Card_GetColorAndTypeFlags(player,card_index);
      val_result = Rules_ParseFilter_0040360b
                        (card_idx,match_count,(char *)0x0,player,2,2,0x200,1,0,0,uval_3,uval_4,uval_5,
                         val_result,val_6,uval_7,uval_8,uVar9,uVar10,uVar11);
      if (val_result == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)
         (&g_CardSlot_ConvertedManaCost +
         *(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20 +
         *(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120) = 3;
        slot_idx = Card_ApplyTriggerEffect(g_DialogPromptHwnd,g_DuelArenaHwnd,DAT_006a4b64,card_idx,match_count);
        if (slot_idx != -1) {
          *(uint32_t *)(&g_CardSlot_Abilities1 + slot_idx * 0x120 + player * 0x5b20) =
               *(uint32_t *)(&g_CardSlot_Abilities1 + slot_idx * 0x120 + player * 0x5b20) | 0x11020;
        }
      }
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120] = 0;
    }
    if (((event_code == 0x22) || (event_code == 199)) &&
       ((card_index == g_EventSourceSlot &&
        ((player == g_EventSourcePlayer &&
         (((&DAT_006a5f55)[card_index * 0x120 + player * 0x5b20] & 0x40) != 0)))))) {
      *(uint32_t *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) &
           0xffffbfff;
      Magic_QueryCardAttribute(player,card_index,0x32,0xffffffff);
      Magic_QueryCardAttribute(player,card_index,0x33,0xffffffff);
    }
  }
  return 0;
}

/*
 * Card_GaeasLiege_ResetLand
 * Purpose: Revert transformed lands when Gaea's Liege leaves play.
 * Procedure:
 * 1. Restore original land types.
 */
/*
 * Decompiled function: Card_GaeasLiege_ResetLand
 * Entry Point: 004d7724
 * Size: 87 bytes
 */

int Card_GaeasLiege_ResetLand(int player,int card_index,int event_code)

{
  if ((((event_code == 0x32) || (event_code == 0x33)) && (card_index == g_EventSourceSlot)) &&
     (player == g_EventSourcePlayer)) {
    g_CardEventResult = g_CardEventResult + *(int *)(&DAT_006b3000 + (7 - player) * 4);
  }
  return 0;
}

/*
 * Card_GaeasLiege_CheckAttackRestriction
 * Purpose: Verify if defending player controls a Forest before attacking.
 * Procedure:
 * 1. Check defending player land types.
 */
/*
 * Decompiled function: Card_GaeasLiege_CheckAttackRestriction
 * Entry Point: 004d777b
 * Size: 274 bytes
 */

int Card_GaeasLiege_CheckAttackRestriction(int player,int card_index,int event_code)

{
  int status;
  
  if (event_code == 0x71) {
    status = Card_ApplyTriggerEffect(player,card_index,DAT_00701000,player,card_index);
    if (status != -1) {
      *(int *)(&g_CardSlot_ConvertedManaCost + status * 0x120 + player * 0x5b20) =
           *(int *)(&g_CardSlot_CardId + card_index * 0x120 + player * 0x5b20);
      *(int *)(&g_CardSlot_TargetSlot + status * 0x120 + player * 0x5b20) = 0x20f;
      *(int *)(&g_CardSlot_Abilities1 + status * 0x120 + player * 0x5b20) = 0x10000;
      (&g_CardSlot_DamageReceived)[card_index * 0x120 + player * 0x5b20] = (uint8_t)player;
      *(int *)(&g_CardSlot_TypeFlags + card_index * 0x120 + player * 0x5b20) = status;
    }
  }
  return 0;
}

/*
 * Card_GaeasLiege_IsForest
 * Purpose: Test if target card is a Forest.
 * Procedure:
 * 1. Check land subtype.
 */
/*
 * Decompiled function: Card_GaeasLiege_IsForest
 * Entry Point: 004d788d
 * Size: 69 bytes
 */

int Card_GaeasLiege_IsForest(int player,int card_index,int event_code)

{
  if (*(int *)(&g_CardSlot_CardId + g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20)
      == event_code) {
    g_CardEventResult = g_CardEventResult + 1;
  }
  return 0;
}

/*
 * Card_GaeasLiege_CombatCheck
 * Purpose: Evaluate combat viability for Gaea's Liege.
 * Procedure:
 * 1. Return combat suitability score.
 */
/*
 * Decompiled function: Card_GaeasLiege_CombatCheck
 * Entry Point: 004d78d2
 * Size: 212 bytes
 */

int Card_GaeasLiege_CombatCheck(int player,int card_index,int event_code)

{
  int status;
  
  if (event_code == 0x71) {
    status = Card_ApplyTriggerEffect(player,card_index,DAT_00701000,player,card_index);
    if (status != -1) {
      *(int *)(&g_CardSlot_TargetSlot + status * 0x120 + player * 0x5b20) = 0x80d;
      *(int *)(&g_CardSlot_Abilities1 + status * 0x120 + player * 0x5b20) = 0x10000;
      (&g_CardSlot_DamageReceived)[card_index * 0x120 + player * 0x5b20] = (uint8_t)player;
      *(int *)(&g_CardSlot_TypeFlags + card_index * 0x120 + player * 0x5b20) = status;
    }
  }
  return 0;
}

/*
 * Card_SedgeTroll_CheckSwamp
 * Purpose: Check if controller controls a Swamp for Sedge Troll +1/+1 buff.
 * Procedure:
 * 1. Query player land list for Swamps.
 */
/*
 * Decompiled function: Card_SedgeTroll_CheckSwamp
 * Entry Point: 004d79a6
 * Size: 117 bytes
 */

int Card_SedgeTroll_CheckSwamp(int player,int card_index,int event_code)

{
  int status;
  
  if ((card_index == g_EventSourceSlot) && (player == g_EventSourcePlayer)) {
    status = Card_UntapCard(player,card_index,3);
    if (0 < *(int *)(&g_AiCombatScore_Attacker + status * 4 + player * 0x20)) {
      if (event_code == 0x32) {
        g_CardEventResult = g_CardEventResult + 1;
      }
      if (event_code == 0x33) {
        g_CardEventResult = g_CardEventResult + 2;
      }
    }
  }
  return 0;
}

/*
 * Card_SedgeTroll_Regenerate
 * Purpose: Activate Sedge Troll regeneration ability (pay B).
 * Procedure:
 * 1. Pay B mana cost.
 * 2. Apply regeneration shield to Sedge Troll.
 */
/*
 * Decompiled function: Card_SedgeTroll_Regenerate
 * Entry Point: 004d7a1b
 * Size: 333 bytes
 */

int Card_SedgeTroll_Regenerate(int player,int card_index,int event_code)

{
  int status;
  uint32_t arg_2_00;
  int arg_3_00;
  
  if (((card_index == g_EventSourceSlot) && (player == g_EventSourcePlayer)) &&
     (0 < (int)(&DAT_0063ee34)[player * 8])) {
    if (event_code == 0x32) {
      g_CardEventResult = g_CardEventResult + 1;
    }
    if (event_code == 0x33) {
      g_CardEventResult = g_CardEventResult + 1;
    }
  }
  if (event_code == 1) {
    status = Card_UntapCard(player,card_index,1);
    *(int *)(&DAT_006ff690 + status * 4 + player * 0x20) =
         *(int *)(&DAT_006ff690 + status * 4 + player * 0x20) + 2;
  }
  if (((event_code == 0x70) && (card_index == g_EventSourceSlot)) && (player == g_EventSourcePlayer)) {
    status = 1;
    arg_2_00 = Card_UntapCard(player,card_index,1);
    status = Font_DrawString(player,arg_2_00,status);
    if (status != 0) {
      status = Ai_Subsystem_004cc56d
                        (player,player,card_index,-1,-1,s_Regenerate_Sedge_Troll__Don_t_re_0052eaa4,0);
      if (status == 0) {
        arg_3_00 = 1;
        status = Card_UntapCard(player,card_index,1);
        Ai_CalcManaRequirement_004ba890(player,status,arg_3_00);
        if (g_ActivePlayer == 1) {
          g_ActivePlayer = -1;
        }
        else {
          g_CardEventResult = g_CardEventResult + 1;
        }
      }
    }
  }
  return 0;
}

/*
 * Card_LivingWall_PromptRegenerate
 * Purpose: Prompt controller to regenerate Living Wall.
 * Procedure:
 * 1. Query player decision to pay regeneration cost.
 */
/*
 * Decompiled function: Card_LivingWall_PromptRegenerate
 * Entry Point: 004d7b68
 * Size: 77 bytes
 */

int Card_LivingWall_PromptRegenerate(int player,int card_index,int event_code)

{
  int u_res;
  
  if (((event_code == 0x73) || (event_code == 0x6d)) || (event_code == 0x72)) {
    u_res = Card_GenericCreature_Regenerate(player,card_index,event_code,2,3);
  }
  else {
    u_res = 0;
  }
  return u_res;
}

/*
 * Card_LivingWall_Regenerate
 * Purpose: Activate Living Wall regeneration ability (pay 1).
 * Procedure:
 * 1. Pay 1 mana cost.
 * 2. Apply regeneration shield.
 */
/*
 * Decompiled function: Card_LivingWall_Regenerate
 * Entry Point: 004d7bb5
 * Size: 171 bytes
 */

int Card_LivingWall_Regenerate(int player,int card_index,int event_code)

{
  int status;
  
  if (((event_code == 0x70) && (g_EventSourceSlot == card_index)) && (g_EventSourcePlayer == player)) {
    status = Font_DrawString(player,7,1);
    if (status != 0) {
      status = Ai_Subsystem_004cc56d
                        (player,player,card_index,-1,-1,s_Regenerate_Living_Wall__Don_t_re_0052ead0,0);
      if (status == 0) {
        Ai_CalcManaRequirement_004ba890(player,0,1);
        if (g_ActivePlayer == 1) {
          g_ActivePlayer = -1;
        }
        else {
          g_CardEventResult = g_CardEventResult + 1;
        }
      }
    }
  }
  return 0;
}

/*
 * Card_GenericCreature_Regenerate
 * Purpose: Apply generic regeneration shield to creature.
 * Procedure:
 * 1. Validate mana payment.
 * 2. Set STATUS_REGENERATED flag on card slot.
 */
/*
 * Decompiled function: Card_GenericCreature_Regenerate
 * Entry Point: 004d7c60
 * Size: 560 bytes
 */

int Card_GenericCreature_Regenerate(int player,int card_index,int event_code,uint32_t action_param,int extra_flags)

{
  bool is_valid;
  int val_result;
  int uval_3;
  
  if (((event_code == 0x73) && ((g_DuelModeFlags._1_1_ & 2) != 0)) &&
     (*(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) == 0)) {
    is_valid = (&g_CardSlot_CardTypeIndex)[card_index * 0x120 + player * 0x5b20] == '\x02' &&
            (((&g_CardSlot_Flags)[card_index * 0x120 + player * 0x5b20] & 2) != 0 &&
            ((&DAT_006a5f6d)[card_index * 0x120 + player * 0x5b20] & 2) != 0);
    if ((is_valid) && (val_result = Font_DrawString(player,action_param,extra_flags), val_result == 0)) {
      is_valid = false;
    }
    if (is_valid) {
      uval_3 = 99;
    }
    else {
      uval_3 = 0;
    }
  }
  else if (event_code == 0x90) {
    Ai_GetOpponentPlayerScore(0);
    uval_3 = 0;
  }
  else {
    if (((event_code == 0x6d) && ((g_DuelModeFlags._1_1_ & 2) != 0)) &&
       (Ai_CalcManaRequirement_004ba890(player,action_param,extra_flags), g_ActivePlayer != 1)) {
      DAT_00695df8 = 1;
      *(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) =
           *(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) + 1;
    }
    if ((event_code == 0x72) && ((g_DuelModeFlags._1_1_ & 2) != 0)) {
      *(int *)
       (&g_CardSlot_ConvertedManaCost +
       *(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120 +
       *(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20) = 0;
      Card_GenericCreature_CanRegenerate(g_DialogPromptHwnd,g_DuelArenaHwnd);
    }
    uval_3 = 0;
  }
  return uval_3;
}

/*
 * Card_GenericCreature_CanRegenerate
 * Purpose: Check if creature can activate its regeneration ability.
 * Procedure:
 * 1. Check mana availability and tapped state.
 */
/*
 * Decompiled function: Card_GenericCreature_CanRegenerate
 * Entry Point: 004d7e90
 * Size: 579 bytes
 */

int Card_GenericCreature_CanRegenerate(int player,int card_index)

{
  bool is_valid;
  int val_result;
  int match_count;
  int slot_idx;
  
  match_count = 0;
  is_valid = false;
  while ((match_count < 2 && (!is_valid))) {
    slot_idx = 0;
    while ((slot_idx < (int)(&g_PlayerActiveCardCount)[match_count] && (!is_valid))) {
      val_result = Card_IsTapped(match_count,slot_idx);
      if ((((val_result != 0) &&
           ((char)(&g_CardSlot_Toughness)[match_count * 0x5b20 + slot_idx * 0x120] == player)) &&
          (*(int *)(&g_CardSlot_OriginalCardId + match_count * 0x5b20 + slot_idx * 0x120) == card_index)) &&
         (((*(int *)(&g_CardSlot_CardId + match_count * 0x5b20 + slot_idx * 0x120) == DAT_006a4b64 &&
           (((&DAT_006a5f6a)[match_count * 0x5b20 + slot_idx * 0x120] & 0x80) != 0)) ||
          (*(int *)(&g_CardSlot_CardId + match_count * 0x5b20 + slot_idx * 0x120) == DAT_006a49ec)))) {
        is_valid = true;
      }
      slot_idx = slot_idx + 1;
    }
    match_count = match_count + 1;
  }
  if (!is_valid) {
    (&g_CardSlot_CardTypeIndex)[card_index * 0x120 + player * 0x5b20] = 0;
    *(int *)(&DAT_006a5f80 + card_index * 0x120 + player * 0x5b20) = 0;
    *(int16_t *)(&g_CardSlot_Power + card_index * 0x120 + player * 0x5b20) = 0;
    FUN_00415d48(player,card_index);
    *(uint32_t *)(&g_CardSlot_Abilities1 + card_index * 0x120 + player * 0x5b20) =
         *(uint32_t *)(&g_CardSlot_Abilities1 + card_index * 0x120 + player * 0x5b20) & 0xffffff7f;
    (&g_CardSlot_ColorMask)[card_index * 0x120 + player * 0x5b20] = 0xff;
    *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) =
         *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) & 0xfffffff3;
  }
  return 0;
}

/*
 * Card_GenericCreature_TriggerRegen
 * Purpose: Trigger creature regeneration during fatal damage resolution.
 * Procedure:
 * 1. Consume regeneration shield, tap creature, and remove from combat.
 */
/*
 * Decompiled function: Card_GenericCreature_TriggerRegen
 * Entry Point: 004d80d3
 * Size: 168 bytes
 */

int Card_GenericCreature_TriggerRegen(int player,int card_index,int event_code)

{
  uint32_t action_param;
  int u_res;
  
  action_param = Rules_CalculateManaCostReduction((&g_MasterCardColorTable)
                       [*(int *)(&g_CardSlot_CardId + card_index * 0x120 + player * 0x5b20) * 0x34]);
  if (event_code == 1) {
    *(int *)(&DAT_006ff690 + action_param * 4 + player * 0x20) =
         *(int *)(&DAT_006ff690 + action_param * 4 + player * 0x20) + 2;
  }
  if (((event_code == 0x73) || (event_code == 0x6d)) || (event_code == 0x72)) {
    u_res = Card_GenericCreature_Regenerate(player,card_index,event_code,action_param,1);
  }
  else {
    u_res = 0;
  }
  return u_res;
}

/*
 * Card_DrudgeSkeletons_Regenerate
 * Purpose: Activate Drudge Skeletons regeneration ability (pay B).
 * Procedure:
 * 1. Pay B mana cost.
 * 2. Apply regeneration shield.
 */
/*
 * Decompiled function: Card_DrudgeSkeletons_Regenerate
 * Entry Point: 004d817b
 * Size: 1616 bytes
 */

int Card_DrudgeSkeletons_Regenerate(int player,int card_index,int event_code)

{
  int u_res;
  int val_result;
  
  if (event_code == 1) {
    *(int *)(&DAT_006ff694 + player * 0x20) = *(int *)(&DAT_006ff694 + player * 0x20) + 1;
  }
  if (event_code == 0x73) {
    if (((g_ActivePlayerPriority == player) && (g_TurnPlayer == player)) &&
       ((*(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) != 0 &&
        (g_ScWillyScore < 0x1a)))) {
      u_res = 0;
    }
    else {
      val_result = Font_DrawString(player,1,1);
      if ((val_result == 0) ||
         (0x1ffff < (int)(*(uint32_t *)(&g_CardSlot_TargetSlot + card_index * 0x120 + player * 0x5b20) &
                         0xffff0000))) {
        u_res = 0;
      }
      else {
        u_res = 1;
      }
    }
  }
  else if (event_code == 0x90) {
    Ai_CalcLifeAdvantage(0);
    u_res = 0;
  }
  else {
    if (((event_code == 0x6d) &&
        (val_result = Font_DrawString(player,1,1), u_res = g_OverworldPlayerCoordY, val_result != 0)) &&
       ((int)(*(uint32_t *)(&g_CardSlot_TargetSlot + card_index * 0x120 + player * 0x5b20) & 0xffff0000) <
        0x20000)) {
      if (((&DAT_006a5f62)[card_index * 0x120 + player * 0x5b20] & 0xf) == 0) {
        g_OverworldPlayerCoordY = 2;
      }
      else {
        g_OverworldPlayerCoordY = 1;
      }
      if (g_TurnPlayer == player) {
        Ai_CalcManaRequirement_004ba890(player,1,-1);
        if (g_TurnCounter < 1) {
          g_ActivePlayer = 1;
        }
      }
      else {
        Ai_CalcManaRequirement_004ba890(player,1,1);
        g_TurnCounter = 1;
      }
      g_OverworldPlayerCoordY = u_res;
      *(uint32_t *)(&g_CardSlot_TargetSlot + card_index * 0x120 + player * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_TargetSlot + card_index * 0x120 + player * 0x5b20) & 0xf0000;
      if (g_ActivePlayer != 1) {
        *(int *)(&g_CardSlot_CombatTarget + card_index * 0x120 + player * 0x5b20) = player;
        *(int *)(&g_CardSlot_AttachedAura + card_index * 0x120 + player * 0x5b20) = card_index;
        (&g_CardSlot_TurnPlayed)[card_index * 0x120 + player * 0x5b20] = 1;
        *(int *)(&g_CardSlot_TargetSlot + card_index * 0x120 + player * 0x5b20) =
             *(int *)(&g_CardSlot_TargetSlot + card_index * 0x120 + player * 0x5b20) +
             g_TurnCounter * 0x10001;
        if (*(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) == 0) {
          *(uint32_t *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) =
               *(uint32_t *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) | 0x80000;
        }
      }
    }
    if (event_code == 0x72) {
      if (*(int *)(&g_CardSlot_CardId +
                  *(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120 +
                  *(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20) == -1) {
        g_ActivePlayer = 1;
      }
      else {
        *(uint32_t *)(&g_CardSlot_ConvertedManaCost +
                 *(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120 +
                 *(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20) =
             *(int *)(&g_CardSlot_ConvertedManaCost +
                     *(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120 +
                     *(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20) +
             (*(uint32_t *)(&g_CardSlot_TargetSlot + card_index * 0x120 + player * 0x5b20) & 0xff);
        (&g_CardSlot_TurnPlayed)
        [*(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120 +
         *(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20] = 0;
        if (((&DAT_006a5f56)
             [*(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120 +
              *(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20] & 8) != 0) {
          *(uint32_t *)(&g_CardSlot_ConvertedManaCost +
                   *(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120 +
                   *(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20) =
               *(uint32_t *)(&g_CardSlot_ConvertedManaCost +
                        *(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120
                        + *(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20)
               & 0xfff7ffff;
          val_result = Card_ApplyTriggerEffect(g_DialogPromptHwnd, g_DuelArenaHwnd, g_PlayerSelectionPriority, g_DialogPromptHwnd, g_DuelArenaHwnd);
          if (val_result != -1) {
            *(int16_t *)(&g_CardSlot_PowerCounters + val_result * 0x120 + player * 0x5b20) = 1;
            *(uint32_t *)(&g_CardSlot_ConvertedManaCost + val_result * 0x120 + player * 0x5b20) =
                 *(uint32_t *)(&g_CardSlot_ConvertedManaCost + val_result * 0x120 + player * 0x5b20) | 0x80000
            ;
          }
        }
      }
    }
    if (event_code == 0x39) {
      u_res = Math_Clamp(*(int *)(&DAT_0063edd4 + player * 0x20),0,
                           2 - *(int *)(&g_CardSlot_ConvertedManaCost +
                                       card_index * 0x120 + player * 0x5b20));
    }
    else {
      if ((event_code == 0x22) || (event_code == 199)) {
        *(int *)(&g_CardSlot_TargetSlot + card_index * 0x120 + player * 0x5b20) = 0;
        *(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) =
             *(int *)(&g_CardSlot_TargetSlot + card_index * 0x120 + player * 0x5b20);
      }
      u_res = 0;
    }
  }
  return u_res;
}

/*
 * Card_UthdenTroll_Regenerate
 * Purpose: Activate Uthden Troll regeneration ability (pay R).
 * Procedure:
 * 1. Pay R mana cost.
 * 2. Apply regeneration shield.
 */
/*
 * Decompiled function: Card_UthdenTroll_Regenerate
 * Entry Point: 004d87cb
 * Size: 1665 bytes
 */

int Card_UthdenTroll_Regenerate(int player,int card_index,int event_code)

{
  int u_res;
  int val_result;
  
  if (((event_code == 0x6c) && (card_index == g_EventSourceSlot)) && (player == g_EventSourcePlayer)) {
    *(int *)(&g_CardSlot_TargetSlot + card_index * 0x120 + player * 0x5b20) = 0;
    *(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) =
         *(int *)(&g_CardSlot_TargetSlot + card_index * 0x120 + player * 0x5b20);
  }
  if (event_code == 1) {
    *(int *)(&DAT_006ff694 + player * 0x20) = *(int *)(&DAT_006ff694 + player * 0x20) + 1;
  }
  if (event_code == 0x73) {
    u_res = Font_DrawString(player,1,1);
  }
  else if (event_code == 0x90) {
    Ai_CalcLifeAdvantage(0);
    u_res = 0;
  }
  else {
    if ((event_code == 0x6d) && (val_result = Font_DrawString(player,1,1), val_result != 0)) {
      if (player == g_TurnPlayer) {
        Ai_CalcManaRequirement_004ba890(player,1,-1);
        if (g_TurnCounter < 1) {
          g_ActivePlayer = 1;
        }
        else {
          *(int *)(&g_CardSlot_TargetSlot + card_index * 0x120 + player * 0x5b20) = g_TurnCounter;
        }
      }
      else {
        Ai_CalcManaRequirement_004ba890(player,1,1);
        *(int *)(&g_CardSlot_TargetSlot + card_index * 0x120 + player * 0x5b20) = 1;
      }
      if (g_ActivePlayer == 1) {
        *(int *)(&g_CardSlot_TargetSlot + card_index * 0x120 + player * 0x5b20) = 0;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + card_index * 0x120 + player * 0x5b20) = player;
        *(int *)(&g_CardSlot_AttachedAura + card_index * 0x120 + player * 0x5b20) = card_index;
        (&g_CardSlot_TurnPlayed)[card_index * 0x120 + player * 0x5b20] = 1;
        if (*(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) == 0) {
          *(uint32_t *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) =
               *(uint32_t *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) | 0x80000;
        }
      }
    }
    if (event_code == 0x72) {
      if (*(int *)(&g_CardSlot_CardId +
                  *(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120 +
                  *(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20) == -1) {
        g_ActivePlayer = 1;
      }
      else {
        *(uint32_t *)(&g_CardSlot_ConvertedManaCost +
                 *(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120 +
                 *(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20) =
             *(int *)(&g_CardSlot_ConvertedManaCost +
                     *(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120 +
                     *(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20) +
             (*(uint32_t *)(&g_CardSlot_TargetSlot + card_index * 0x120 + player * 0x5b20) & 0xff);
        *(uint32_t *)(&g_CardSlot_ConvertedManaCost +
                 *(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120 +
                 *(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20) =
             *(int *)(&g_CardSlot_ConvertedManaCost +
                     *(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120 +
                     *(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20) +
             (*(uint32_t *)(&g_CardSlot_TargetSlot + card_index * 0x120 + player * 0x5b20) & 0xff) * 0x100;
        (&g_CardSlot_TurnPlayed)
        [*(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120 +
         *(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20] = 0;
        if (((&DAT_006a5f56)
             [*(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120 +
              *(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20] & 8) != 0) {
          *(uint32_t *)(&g_CardSlot_ConvertedManaCost +
                   *(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120 +
                   *(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20) =
               *(uint32_t *)(&g_CardSlot_ConvertedManaCost +
                        *(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120
                        + *(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20)
               & 0xfff7ffff;
          val_result = Card_ApplyTriggerEffect(g_DialogPromptHwnd, g_DuelArenaHwnd, g_PlayerSelectionPriority, g_DialogPromptHwnd, g_DuelArenaHwnd);
          if (val_result != -1) {
            *(int16_t *)(&g_CardSlot_PowerCounters + val_result * 0x120 + player * 0x5b20) = 1;
            *(int16_t *)(&g_CardSlot_ToughnessCounters + val_result * 0x120 + player * 0x5b20) = 1;
            *(uint32_t *)(&g_CardSlot_ConvertedManaCost + val_result * 0x120 + player * 0x5b20) =
                 *(uint32_t *)(&g_CardSlot_ConvertedManaCost + val_result * 0x120 + player * 0x5b20) | 0x80000
            ;
          }
        }
      }
    }
    if (event_code == 0x39) {
      u_res = Font_DrawString(player,1,1);
    }
    else if (event_code == 0x3a) {
      u_res = Font_DrawString(player,1,1);
    }
    else {
      if ((event_code == 0x8f) && (*(int *)(&DAT_0063ee94 + player * 0x20) != 0)) {
        g_CardEventResult = g_CardEventResult | 1;
      }
      if ((event_code == 0x22) || (event_code == 199)) {
        *(int *)(&g_CardSlot_TargetSlot + card_index * 0x120 + player * 0x5b20) = 0;
        *(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) =
             *(int *)(&g_CardSlot_TargetSlot + card_index * 0x120 + player * 0x5b20);
      }
      u_res = 0;
    }
  }
  return u_res;
}

/*
 * Card_WillOTheWisp_Regenerate
 * Purpose: Activate Will-o'-the-Wisp regeneration ability (pay B).
 * Procedure:
 * 1. Pay B mana cost.
 * 2. Apply regeneration shield.
 */
/*
 * Decompiled function: Card_WillOTheWisp_Regenerate
 * Entry Point: 004d8e4c
 * Size: 1685 bytes
 */

int Card_WillOTheWisp_Regenerate(int player,int card_index,int event_code)

{
  int u_res;
  int val_result;
  
  if (event_code == 1) {
    *(int *)(&DAT_006ff69c + player * 0x20) = *(int *)(&DAT_006ff69c + player * 0x20) + 1;
  }
  if (((event_code == 0x6c) && (card_index == g_EventSourceSlot)) && (player == g_EventSourcePlayer)) {
    *(int *)(&g_CardSlot_TargetSlot + card_index * 0x120 + player * 0x5b20) = 0;
    *(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) =
         *(int *)(&g_CardSlot_TargetSlot + card_index * 0x120 + player * 0x5b20);
  }
  if (event_code == 0x73) {
    u_res = Font_DrawString(player,3,1);
  }
  else if (event_code == 0x90) {
    Ai_CalcLifeAdvantage(0);
    u_res = 0;
  }
  else {
    if ((event_code == 0x6d) && (val_result = Font_DrawString(player,3,1), val_result != 0)) {
      if (player == g_TurnPlayer) {
        Ai_CalcManaRequirement_004ba890(player,3,-1);
        if (g_TurnCounter < 1) {
          g_ActivePlayer = 1;
        }
        else {
          *(int *)(&g_CardSlot_TargetSlot + card_index * 0x120 + player * 0x5b20) = g_TurnCounter;
        }
      }
      else {
        Ai_CalcManaRequirement_004ba890(player,3,1);
        *(int *)(&g_CardSlot_TargetSlot + card_index * 0x120 + player * 0x5b20) = 1;
      }
      if (g_ActivePlayer == 1) {
        *(int *)(&g_CardSlot_TargetSlot + card_index * 0x120 + player * 0x5b20) = 0;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + card_index * 0x120 + player * 0x5b20) = player;
        *(int *)(&g_CardSlot_AttachedAura + card_index * 0x120 + player * 0x5b20) = card_index;
        (&g_CardSlot_TurnPlayed)[card_index * 0x120 + player * 0x5b20] = 1;
        if (*(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) == 0) {
          *(uint32_t *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) =
               *(uint32_t *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) | 0x80000;
        }
      }
    }
    if (event_code == 0x72) {
      if (*(int *)(&g_CardSlot_CardId +
                  *(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20 +
                  *(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120) ==
          -1) {
        g_ActivePlayer = 1;
      }
      else {
        *(uint32_t *)(&g_CardSlot_ConvertedManaCost +
                 *(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20 +
                 *(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120) =
             *(int *)(&g_CardSlot_ConvertedManaCost +
                     *(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20 +
                     *(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120) +
             (*(uint32_t *)(&g_CardSlot_TargetSlot + card_index * 0x120 + player * 0x5b20) & 0xff);
        *(uint32_t *)(&g_CardSlot_ConvertedManaCost +
                 *(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20 +
                 *(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120) =
             *(int *)(&g_CardSlot_ConvertedManaCost +
                     *(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20 +
                     *(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120) +
             (*(uint32_t *)(&g_CardSlot_TargetSlot + card_index * 0x120 + player * 0x5b20) & 0xff) * 0x100;
        (&g_CardSlot_TurnPlayed)
        [*(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20 +
         *(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120] = 0;
        if (((&DAT_006a5f56)
             [*(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20 +
              *(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120] & 8) !=
            0) {
          *(uint32_t *)(&g_CardSlot_ConvertedManaCost +
                   *(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20 +
                   *(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120) =
               *(uint32_t *)(&g_CardSlot_ConvertedManaCost +
                        *(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20 +
                        *(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120
                        ) & 0xfff7ffff;
          val_result = Card_ApplyTriggerEffect(g_DialogPromptHwnd, g_DuelArenaHwnd, g_PlayerSelectionPriority, g_DialogPromptHwnd, g_DuelArenaHwnd);
          if (val_result != -1) {
            *(uint32_t *)(&g_CardSlot_ConvertedManaCost + val_result * 0x120 + player * 0x5b20) =
                 *(uint32_t *)(&g_CardSlot_ConvertedManaCost + val_result * 0x120 + player * 0x5b20) | 0x80000
            ;
          }
        }
      }
    }
    if (event_code == 0x39) {
      u_res = Font_DrawString(player,3,1);
    }
    else if (event_code == 0x3a) {
      u_res = Font_DrawString(player,3,1);
    }
    else {
      if ((event_code == 0x8f) && (*(int *)(&DAT_0063ee9c + player * 0x20) != 0)) {
        g_CardEventResult = g_CardEventResult | 1;
      }
      if (event_code == 199) {
        if (player == g_ActivePlayerPriority) {
          g_SpellStackDepth =
               g_SpellStackDepth + (*(int *)(&DAT_0063ee3c + player * 0x20) * 3 + 6) * 4;
        }
        else {
          g_SpellStackDepth =
               g_SpellStackDepth + (*(int *)(&DAT_0063ee3c + player * 0x20) * 3 + 6) * -4;
        }
      }
      if ((event_code == 0x22) || (event_code == 199)) {
        *(int *)(&g_CardSlot_TargetSlot + card_index * 0x120 + player * 0x5b20) = 0;
        *(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) =
             *(int *)(&g_CardSlot_TargetSlot + card_index * 0x120 + player * 0x5b20);
      }
      u_res = 0;
    }
  }
  return u_res;
}

/*
 * Card_MarrowThieves_Regenerate
 * Purpose: Activate Marrow Thieves regeneration ability.
 * Procedure:
 * 1. Sacrifice creature to apply regeneration shield.
 */
/*
 * Decompiled function: Card_MarrowThieves_Regenerate
 * Entry Point: 004d94e1
 * Size: 1564 bytes
 */

int Card_MarrowThieves_Regenerate(int player,int card_index,int event_code)

{
  int u_res;
  int val_result;
  
  if (event_code == 1) {
    *(int *)(&DAT_006ff698 + player * 0x20) = *(int *)(&DAT_006ff698 + player * 0x20) + 1;
  }
  if (((event_code == 0x6c) && (g_EventSourceSlot == card_index)) && (g_EventSourcePlayer == player)) {
    *(int *)(&g_CardSlot_TargetSlot + card_index * 0x120 + player * 0x5b20) = 0;
    *(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) =
         *(int *)(&g_CardSlot_TargetSlot + card_index * 0x120 + player * 0x5b20);
  }
  if (event_code == 0x73) {
    u_res = Font_DrawString(player,2,1);
  }
  else if (event_code == 0x90) {
    Ai_CalcLifeAdvantage(0);
    u_res = 0;
  }
  else {
    if ((event_code == 0x6d) && (val_result = Font_DrawString(player,2,1), val_result != 0)) {
      if (g_TurnPlayer == player) {
        Ai_CalcManaRequirement_004ba890(player,2,-1);
        if (g_TurnCounter < 1) {
          g_ActivePlayer = 1;
        }
        else {
          *(int *)(&g_CardSlot_TargetSlot + card_index * 0x120 + player * 0x5b20) = g_TurnCounter;
        }
      }
      else {
        Ai_CalcManaRequirement_004ba890(player,2,1);
        *(int *)(&g_CardSlot_TargetSlot + card_index * 0x120 + player * 0x5b20) = 1;
      }
      if (g_ActivePlayer == 1) {
        *(int *)(&g_CardSlot_TargetSlot + card_index * 0x120 + player * 0x5b20) = 0;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + card_index * 0x120 + player * 0x5b20) = player;
        *(int *)(&g_CardSlot_AttachedAura + card_index * 0x120 + player * 0x5b20) = card_index;
        (&g_CardSlot_TurnPlayed)[card_index * 0x120 + player * 0x5b20] = 1;
        if (*(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) == 0) {
          *(uint32_t *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) =
               *(uint32_t *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) | 0x80000;
        }
      }
    }
    if (event_code == 0x72) {
      if (*(int *)(&g_CardSlot_CardId +
                  *(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20 +
                  *(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120) ==
          -1) {
        g_ActivePlayer = 1;
      }
      else {
        *(uint32_t *)(&g_CardSlot_ConvertedManaCost +
                 *(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120 +
                 *(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20) =
             *(int *)(&g_CardSlot_ConvertedManaCost +
                     *(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120 +
                     *(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20) +
             (*(uint32_t *)(&g_CardSlot_TargetSlot + card_index * 0x120 + player * 0x5b20) & 0xff);
        (&g_CardSlot_TurnPlayed)
        [*(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20 +
         *(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120] = 0;
        if (((&DAT_006a5f56)
             [*(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20 +
              *(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120] & 8) !=
            0) {
          *(uint32_t *)(&g_CardSlot_ConvertedManaCost +
                   *(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120 +
                   *(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20) =
               *(uint32_t *)(&g_CardSlot_ConvertedManaCost +
                        *(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120
                        + *(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20)
               & 0xfff7ffff;
          val_result = Card_ApplyTriggerEffect(g_DialogPromptHwnd, g_DuelArenaHwnd, g_PlayerSelectionPriority, g_DialogPromptHwnd, g_DuelArenaHwnd);
          if (val_result != -1) {
            *(int16_t *)(&g_CardSlot_PowerCounters + val_result * 0x120 + player * 0x5b20) = 1;
            *(uint32_t *)(&g_CardSlot_ConvertedManaCost + val_result * 0x120 + player * 0x5b20) =
                 *(uint32_t *)(&g_CardSlot_ConvertedManaCost + val_result * 0x120 + player * 0x5b20) | 0x80000
            ;
          }
        }
      }
    }
    if (event_code == 0x39) {
      u_res = Font_DrawString(player,2,1);
    }
    else {
      if ((event_code == 0x8f) && (*(int *)(&DAT_0063ee98 + player * 0x20) != 0)) {
        g_CardEventResult = g_CardEventResult | 1;
      }
      if (event_code == 199) {
        if (g_ActivePlayerPriority == player) {
          g_SpellStackDepth = g_SpellStackDepth + (&DAT_0063ee38)[player * 8] * 0xc;
        }
        else {
          g_SpellStackDepth = g_SpellStackDepth + (&DAT_0063ee38)[player * 8] * -0xc;
        }
      }
      if ((event_code == 0x22) || (event_code == 199)) {
        *(int *)(&g_CardSlot_TargetSlot + card_index * 0x120 + player * 0x5b20) = 0;
        *(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) =
             *(int *)(&g_CardSlot_TargetSlot + card_index * 0x120 + player * 0x5b20);
      }
      u_res = 0;
    }
  }
  return u_res;
}

/*
 * Card_HypnoticSpecter_RandomDiscard
 * Purpose: Force defending player to discard a random card on combat damage.
 * Procedure:
 * 1. Verify unblocked combat damage dealt to opponent.
 * 2. Select random card from opponent hand.
 * 3. Move card to opponent graveyard.
 */
/*
 * Decompiled function: Card_HypnoticSpecter_RandomDiscard
 * Entry Point: 004d9afd
 * Size: 1153 bytes
 */

void Card_HypnoticSpecter_RandomDiscard(int player,int card_index,int event_code)

{
  int action_param;
  int local_94;
  int local_90;
  int local_88;
  int local_80 [30];
  int slot_idx;
  
  if (event_code == 1) {
    *(int *)(&DAT_006ff694 + player * 0x20) = *(int *)(&DAT_006ff694 + player * 0x20) + 1;
  }
  if (event_code == 0x73) {
    Font_DrawString(player,1,3);
  }
  else {
    if (((event_code == 0x6d) &&
        ((*(uint32_t *)(&g_CardSlot_Flags + player * 0x5b20 + card_index * 0x120) & 0x20010) == 0)) &&
       (Ai_CalcManaRequirement_004ba890(player,1,3), g_ActivePlayer != 1)) {
      *(uint32_t *)(&g_CardSlot_Flags + player * 0x5b20 + card_index * 0x120) =
           *(uint32_t *)(&g_CardSlot_Flags + player * 0x5b20 + card_index * 0x120) | 0x10;
    }
    if (event_code == 0x72) {
      action_param = 1 - player;
      if (((g_IsAiThinking != 1) && (player == 0)) && (g_AiTurnDecisionFlag == 0)) {
        local_90 = 0;
        for (local_88 = 0; local_88 < DAT_006808bc; local_88 = local_88 + 1) {
          if ((*(int *)(&DAT_006aba54 + local_88 * 0x120) != -1) &&
             (((&DAT_006aba5c)[local_88 * 0x120] & 2) == 0)) {
            local_80[local_90] = *(int *)(&DAT_006aba54 + local_88 * 0x120);
            local_90 = local_90 + 1;
          }
        }
        if (g_IsAiThinking != 1) {
          UI_DeckSelectionMenu(0,(int)local_80,local_90,s_Opponent_s_Hand_0052eb04,0);
        }
      }
      local_90 = 0;
      do {
        local_94 = Util_GetRandomNumber((&g_PlayerActiveCardCount)[action_param]);
        local_90 = local_90 + 1;
        if (0x3e6 < local_90) break;
      } while (((*(int *)(&g_CardSlot_CardId + action_param * 0x5b20 + local_94 * 0x120) == -1) ||
               (((&g_MasterCardColorTable)
                 [*(int *)(&g_CardSlot_CardId + action_param * 0x5b20 + local_94 * 0x120) * 0x34] & 2) == 0
               )) || (((&g_CardSlot_Flags)[action_param * 0x5b20 + local_94 * 0x120] & 2) != 0));
      if (local_90 < 999) {
        slot_idx = 1;
      }
      else {
        slot_idx = 0;
        local_88 = 0;
        while ((local_88 < (int)(&g_PlayerActiveCardCount)[action_param] && (slot_idx == 0))) {
          if ((*(int *)(&g_CardSlot_CardId + local_88 * 0x120 + action_param * 0x5b20) != -1) &&
             ((((&g_MasterCardColorTable)
                [*(int *)(&g_CardSlot_CardId + local_88 * 0x120 + action_param * 0x5b20) * 0x34] & 2) != 0
              && (((&g_CardSlot_Flags)[local_88 * 0x120 + action_param * 0x5b20] & 2) == 0)))) {
            slot_idx = 1;
            local_94 = local_88;
          }
          local_88 = local_88 + 1;
        }
      }
      if (slot_idx != 0) {
        if (g_IsAiThinking != 1) {
          Duel_PlaySoundById(0x19);
        }
        if (g_IsAiThinking != 1) {
          Ai_Subsystem_004cc56d
                    (player,player,card_index,action_param,local_94,s_Randomly_chose_this_creature_to_d_0052eb14,0
                    );
        }
        Pic_Subsystem_0044913a(action_param,local_94);
        *(int *)(&g_CardSlot_CardId + action_param * 0x5b20 + local_94 * 0x120) = 0xffffffff;
        (&g_ActivePlayerSpellPriority)[action_param] = (&g_ActivePlayerSpellPriority)[action_param] + -1;
      }
    }
  }
  return;
}

/*
 * Card_TimeElemental_BouncePermanent
 * Purpose: Activate Time Elemental ability to return permanent to hand.
 * Procedure:
 * 1. Validate target permanent.
 * 2. Return permanent to owner hand.
 * 3. Deal 5 damage to Time Elemental controller.
 */
/*
 * Decompiled function: Card_TimeElemental_BouncePermanent
 * Entry Point: 004d9f7e
 * Size: 1284 bytes
 */

int Card_TimeElemental_BouncePermanent(int player,int card_index,int event_code)

{
  int status;
  int u_temp;
  uint32_t uval_3;
  bool bVar4;
  uint32_t uval_5;
  uint32_t uval_6;
  int arg_11;
  int val_7;
  int arg_12;
  uint32_t uval_8;
  int arg_13;
  uint32_t uVar9;
  int arg_14;
  uint32_t uVar10;
  int arg_15;
  uint32_t uVar11;
  int arg_16;
  uint32_t uVar12;
  int arg_17;
  uint8_t *arg_18;
  int arg_18_00;
  int arg_19;
  int *arg_20;
  int match_count;
  int slot_idx;
  
  if (event_code == 1) {
    *(int *)(&DAT_006ff6a4 + player * 0x20) = *(int *)(&DAT_006ff6a4 + player * 0x20) + 1;
  }
  if (event_code == 0x73) {
    bVar4 = (*(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) & 0x20010) == 0;
    if ((bVar4) && (status = Font_DrawString(player,2,2), status == 0)) {
      bVar4 = false;
    }
    if ((bVar4) && (status = Font_DrawString(player,7,4), status == 0)) {
      bVar4 = false;
    }
    u_temp = 0;
    if (bVar4) {
      arg_19 = 0x40;
      arg_18_00 = 0;
      arg_17 = 0;
      arg_16 = 0xffffffff;
      arg_15 = 0xffffffff;
      arg_14 = 0xffffffff;
      arg_13 = 0xffffffff;
      arg_12 = 0;
      arg_11 = 0;
      u_temp = Card_GetColorAndTypeFlags(player,card_index);
      u_temp = UI_PaintBigCardInfo((int *)0x0,0,player,2,2,0x200,0x1047,0,0,u_temp,arg_11,arg_12,arg_13,
                           arg_14,arg_15,arg_16,arg_17,arg_18_00,arg_19);
    }
  }
  else if (event_code == 0x90) {
    Ai_GetOpponentPlayerScore(0);
    u_temp = 0;
  }
  else {
    if ((event_code == 0x6d) &&
       ((*(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) & 0x20010) == 0)) {
      g_AiSelectedTargetCard = 2;
      Ai_CalcManaRequirement_004ba890(player,2,2);
      if (g_ActivePlayer != 1) {
        Pic_Subsystem_00424500(s_prompts_txt_0052eb50,s_TIME_ELEMENTAL_0052eb40);
        arg_20 = &match_count;
        u_temp = 1;
        arg_18 = &g_OverworldGoldAmount;
        uVar12 = 0x40;
        uVar11 = 0;
        uVar10 = 0;
        uVar9 = 0xffffffff;
        uval_8 = 0xffffffff;
        val_7 = -1;
        status = -1;
        uval_6 = 0;
        uval_5 = 0;
        uval_3 = Card_GetColorAndTypeFlags(player,card_index);
        status = Duel_ChooseTarget
                          (player,2,1 - player,0x200,0x1047,0,0,uval_3,uval_5,uval_6,status,val_7,
                           uval_8,uVar9,uVar10,uVar11,uVar12,arg_18,u_temp,arg_20);
        if (status == 0) {
          g_ActivePlayer = 1;
        }
        else {
          *(int *)(&g_CardSlot_CombatTarget + card_index * 0x120 + player * 0x5b20) = match_count;
          *(int *)(&g_CardSlot_AttachedAura + card_index * 0x120 + player * 0x5b20) = slot_idx;
          (&g_CardSlot_TurnPlayed)[card_index * 0x120 + player * 0x5b20] = 1;
          *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) =
               *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) | 0x10;
        }
      }
    }
    if (event_code == 0x72) {
      match_count = *(int *)(&g_CardSlot_CombatTarget + card_index * 0x120 + player * 0x5b20);
      slot_idx = *(int *)(&g_CardSlot_AttachedAura + card_index * 0x120 + player * 0x5b20);
      uVar12 = 0x40;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0xffffffff;
      uval_8 = 0xffffffff;
      val_7 = -1;
      status = -1;
      uval_6 = 0;
      uval_5 = 0;
      uval_3 = Card_GetColorAndTypeFlags(player,card_index);
      status = Rules_ParseFilter_0040360b
                        (match_count,slot_idx,(char *)0x0,player,2,2,0x200,0x1047,0,0,uval_3,uval_5,uval_6
                         ,status,val_7,uval_8,uVar9,uVar10,uVar11,uVar12);
      if (status == 0) {
        g_ActivePlayer = 1;
      }
      else {
        FUN_0041da41(match_count,slot_idx);
      }
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120] = 0;
    }
    if (((event_code == 0x15) || (event_code == 199)) &&
       (((&g_CardSlot_Flags)[card_index * 0x120 + player * 0x5b20] & 4) != 0)) {
      Card_ApplyTriggerEffect(player,card_index,DAT_00695ed0,player,-1);
    }
    if (((event_code == 0x1a) || (event_code == 199)) &&
       ((g_ScWillyScore == 0x17 &&
        ((&g_CardSlot_ColorMask)[card_index * 0x120 + player * 0x5b20] != -1)))) {
      Card_ApplyTriggerEffect(player,card_index,DAT_00695ed0,player,-1);
    }
    if ((event_code == 0x22) || (event_code == 199)) {
      *(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) = 0;
    }
    if (((event_code == 0x8a) && (card_index == g_EventSourceSlot)) &&
       (player == g_EventSourcePlayer)) {
      g_AiBlockingCreatureCount = g_AiBlockingCreatureCount + 0x78;
    }
    if (((event_code == 0x8b) && (card_index == g_EventSourceSlot)) &&
       (player == g_EventSourcePlayer)) {
      g_AiBlockingCreatureCount = g_AiBlockingCreatureCount + -0x78;
    }
    u_temp = 0;
  }
  return u_temp;
}

/*
 * Card_NorthernPaladin_DestroyBlack
 * Purpose: Activate Northern Paladin ability to destroy target black permanent.
 * Procedure:
 * 1. Validate target black permanent.
 * 2. Destroy target permanent.
 */
/*
 * Decompiled function: Card_NorthernPaladin_DestroyBlack
 * Entry Point: 004da482
 * Size: 982 bytes
 */

int Card_NorthernPaladin_DestroyBlack(int player,int card_index,int event_code)

{
  uint8_t is_valid;
  int val_result;
  int uval_3;
  uint32_t uval_4;
  uint32_t uval_5;
  bool bVar6;
  uint32_t uval_7;
  int val_8;
  int arg_12;
  uint32_t uVar9;
  int arg_13;
  uint32_t uVar10;
  int arg_14;
  uint32_t uVar11;
  int arg_15;
  uint32_t uVar12;
  int arg_16;
  uint32_t uVar13;
  int arg_17;
  uint8_t *arg_18;
  int arg_18_00;
  int arg_19;
  int *arg_20;
  int match_count;
  int slot_idx;
  
  if (event_code == 1) {
    *(int *)(&DAT_006ff6a4 + player * 0x20) = *(int *)(&DAT_006ff6a4 + player * 0x20) + 1;
  }
  if (event_code == 0x73) {
    bVar6 = (*(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) & 0x20010) == 0;
    if ((bVar6) && (val_result = Font_DrawString(player,5,2), val_result == 0)) {
      bVar6 = false;
    }
    uval_3 = 0;
    if (bVar6) {
      arg_19 = 0;
      arg_18_00 = 0;
      arg_17 = 0;
      arg_16 = 0xffffffff;
      arg_15 = 0xffffffff;
      arg_14 = 0xffffffff;
      arg_13 = 0xffffffff;
      arg_12 = 0;
      is_valid = Card_SetTapState(player, card_index, 1);
      val_result = 1 << (is_valid & 0x1f);
      uval_3 = Card_GetColorAndTypeFlags(player,card_index);
      uval_3 = UI_PaintBigCardInfo((int *)0x0,0,player,2,2,0x200,0x1047,0,0,uval_3,val_result,arg_12,arg_13,
                           arg_14,arg_15,arg_16,arg_17,arg_18_00,arg_19);
    }
  }
  else if (event_code == 0x90) {
    Ai_GetOpponentPlayerScore(0);
    uval_3 = 0;
  }
  else {
    if ((((event_code == 0x6d) && (val_result = Font_DrawString(player,5,2), val_result != 0)) &&
        ((*(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) & 0x20010) == 0)) &&
       (Ai_CalcManaRequirement_004ba890(player,5,2), g_ActivePlayer != 1)) {
      Pic_Subsystem_00424500(s_prompts_txt_0052eb70,s_NORTHERN_PALADIN_0052eb5c);
      arg_20 = &match_count;
      uval_3 = 1;
      arg_18 = &g_OverworldGoldAmount;
      uVar13 = 0;
      uVar12 = 0;
      uVar11 = 0;
      uVar10 = 0xffffffff;
      uVar9 = 0xffffffff;
      val_8 = -1;
      val_result = -1;
      uval_7 = 0;
      is_valid = Card_SetTapState(player, card_index, 1);
      uval_5 = 1 << (is_valid & 0x1f);
      uval_4 = Card_GetColorAndTypeFlags(player,card_index);
      val_result = Duel_ChooseTarget
                        (player,2,2,0x200,0x1047,0,0,uval_4,uval_5,uval_7,val_result,val_8,uVar9,uVar10,
                         uVar11,uVar12,uVar13,arg_18,uval_3,arg_20);
      if (val_result == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + card_index * 0x120 + player * 0x5b20) = match_count;
        *(int *)(&g_CardSlot_AttachedAura + card_index * 0x120 + player * 0x5b20) = slot_idx;
        (&g_CardSlot_TurnPlayed)[card_index * 0x120 + player * 0x5b20] = 1;
        *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) | 0x10;
      }
    }
    if (event_code == 0x72) {
      match_count = *(int *)(&g_CardSlot_CombatTarget + card_index * 0x120 + player * 0x5b20);
      slot_idx = *(int *)(&g_CardSlot_AttachedAura + card_index * 0x120 + player * 0x5b20);
      uVar13 = 0;
      uVar12 = 0;
      uVar11 = 0;
      uVar10 = 0xffffffff;
      uVar9 = 0xffffffff;
      val_8 = -1;
      val_result = -1;
      uval_7 = 0;
      is_valid = Card_SetTapState(player, card_index, 1);
      uval_5 = 1 << (is_valid & 0x1f);
      uval_4 = Card_GetColorAndTypeFlags(player,card_index);
      val_result = Rules_ParseFilter_0040360b
                        (match_count,slot_idx,(char *)0x0,player,2,2,0x200,0x1047,0,0,uval_4,uval_5,uval_7
                         ,val_result,val_8,uVar9,uVar10,uVar11,uVar12,uVar13);
      if (val_result == 0) {
        g_ActivePlayer = 1;
      }
      else {
        Pic_Subsystem_0044867e(match_count,slot_idx,2);
      }
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120] = 0;
    }
    uval_3 = 0;
  }
  return uval_3;
}

/*
 * Card_RoyalAssassin_DestroyTapped
 * Purpose: Activate Royal Assassin ability to destroy target tapped creature.
 * Procedure:
 * 1. Validate target tapped creature.
 * 2. Destroy target creature.
 */
/*
 * Decompiled function: Card_RoyalAssassin_DestroyTapped
 * Entry Point: 004da858
 * Size: 504 bytes
 */

int Card_RoyalAssassin_DestroyTapped(int player,int card_index,int event_code)

{
  int card_id;
  int color_mask;
  uint32_t arg_11;
  uint32_t arg_12;
  uint32_t arg_13;
  int status;
  int arg_15;
  uint32_t arg_16;
  uint32_t arg_17;
  uint32_t arg_18;
  uint32_t arg_19;
  uint32_t arg_20;
  int slot_idx;
  
  if ((event_code == 0x73) || (event_code == 0x6d)) {
    Pic_Subsystem_00424500(s_prompts_txt_0052eb8c,s_ROYAL_ASSASSIN_0052eb7c);
    slot_idx = Card_Targeting_PromptCreature(player,card_index,event_code,1 - player);
  }
  if (event_code == 0x90) {
    Ai_GetOpponentPlayerScore(0);
    slot_idx = 0;
  }
  else {
    if (event_code == 0x72) {
      card_id = *(int *)(&g_CardSlot_CombatTarget + card_index * 0x120 + player * 0x5b20);
      color_mask = *(int *)(&g_CardSlot_AttachedAura + card_index * 0x120 + player * 0x5b20);
      arg_20 = 0;
      arg_19 = 1;
      arg_18 = 0;
      arg_17 = 0xffffffff;
      arg_16 = 0xffffffff;
      arg_15 = -1;
      status = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = Card_GetColorAndTypeFlags(player,card_index);
      status = Rules_ParseFilter_0040360b
                        (card_id,color_mask,(char *)0x0,player,2,2,0x200,2,0,0,arg_11,arg_12,
                         arg_13,status,arg_15,arg_16,arg_17,arg_18,arg_19,arg_20);
      if (status == 0) {
        g_ActivePlayer = 1;
      }
      else {
        Pic_Subsystem_0044867e(card_id,color_mask,2);
      }
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120 +
       *(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20] = 0;
      slot_idx = 0;
    }
    if (((event_code == 0x8a) && (card_index == g_EventSourceSlot)) &&
       (player == g_EventSourcePlayer)) {
      g_AiBlockingCreatureCount = g_AiBlockingCreatureCount + 0x30;
    }
    if (((event_code == 0x8b) && (card_index == g_EventSourceSlot)) &&
       (player == g_EventSourcePlayer)) {
      g_AiBlockingCreatureCount = g_AiBlockingCreatureCount + -0x30;
    }
  }
  return slot_idx;
}

/*
 * Card_DwarvenDemolitionTeam_DestroyWall
 * Purpose: Activate Dwarven Demolition Team ability to destroy target Wall.
 * Procedure:
 * 1. Validate target Wall creature.
 * 2. Destroy target Wall.
 */
/*
 * Decompiled function: Card_DwarvenDemolitionTeam_DestroyWall
 * Entry Point: 004daa50
 * Size: 449 bytes
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int Card_DwarvenDemolitionTeam_DestroyWall(int player,int card_index,int event_code)

{
  int card_index;
  int slot_idx;
  
  if ((event_code == 0x73) || (event_code == 0x6d)) {
    Pic_Subsystem_00424500(s_prompts_txt_0052eba8,s_DWARVEN_DTEAM_0052eb98);
    slot_idx = Card_Targeting_PromptCreature(player,card_index,event_code,1 - player);
  }
  if (event_code == 0x90) {
    Ai_GetOpponentPlayerScore(0);
    slot_idx = 0;
  }
  else if ((event_code == 0x72) &&
          (*(int *)(&g_CardSlot_OriginalCardId + card_index * 0x120 + player * 0x5b20) != -1)) {
    card_index = *(int *)(&g_CardSlot_OriginalCardId + card_index * 0x120 + player * 0x5b20);
    g_TemporaryToughnessBuffer = (int)(char)(&g_CardSlot_Toughness)[card_index * 0x120 + player * 0x5b20];
    *(int *)(&g_CardSlot_OriginalCardId + card_index * 0x120 + player * 0x5b20) = 0xffffffff
    ;
    *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) =
         *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) & 0xffffffef;
    if ((card_index != -1) &&
       ((&g_MasterCardRarityTable)
        [*(int *)(&g_CardSlot_CardId +
                 *(int *)(&g_CardSlot_CombatTarget + card_index * 0x120 + player * 0x5b20) * 0x5b20
                 + *(int *)(&g_CardSlot_AttachedAura + card_index * 0x120 + player * 0x5b20) *
                   0x120) * 0x34] == '\0')) {
      Pic_Subsystem_0044867e(g_TemporaryToughnessBuffer,card_index,2);
    }
  }
  return slot_idx;
}

/*
 * Card_KingSuleiman_DestroyDjinn
 * Purpose: Activate King Suleiman ability to destroy target Djinn or Efreet.
 * Procedure:
 * 1. Validate target Djinn or Efreet creature.
 * 2. Destroy target creature.
 */
/*
 * Decompiled function: Card_KingSuleiman_DestroyDjinn
 * Entry Point: 004dac11
 * Size: 613 bytes
 */

int Card_KingSuleiman_DestroyDjinn(int player,int card_index,int event_code)

{
  int slot_idx;
  
  if ((event_code == 0x73) || (event_code == 0x6d)) {
    Pic_Subsystem_00424500(s_prompts_txt_0052ebc4,s_KING_SULEIMAN_0052ebb4);
    slot_idx = Card_Targeting_PromptCreature(player,card_index,event_code,1 - player);
  }
  if (event_code == 0x90) {
    Ai_GetOpponentPlayerScore(0);
    slot_idx = 0;
  }
  else if ((event_code == 0x72) &&
          (*(int *)(&g_CardSlot_OriginalCardId + card_index * 0x120 + player * 0x5b20) != -1)) {
    if (((&g_MasterCardRarityTable)
         [*(int *)(&g_CardSlot_CardId +
                  *(int *)(&g_CardSlot_OriginalCardId + card_index * 0x120 + player * 0x5b20) *
                  0x120 + (char)(&g_CardSlot_Toughness)[card_index * 0x120 + player * 0x5b20] *
                          0x5b20) * 0x34] == '\x05') ||
       ((&g_MasterCardRarityTable)
        [*(int *)(&g_CardSlot_CardId +
                 *(int *)(&g_CardSlot_OriginalCardId + card_index * 0x120 + player * 0x5b20) *
                 0x120 + (char)(&g_CardSlot_Toughness)[card_index * 0x120 + player * 0x5b20] *
                         0x5b20) * 0x34] == '\x06')) {
      Pic_Subsystem_0044867e
                ((int)(char)(&g_CardSlot_Toughness)[card_index * 0x120 + player * 0x5b20],
                 *(int *)(&g_CardSlot_OriginalCardId + card_index * 0x120 + player * 0x5b20),2);
    }
    else {
      g_ActivePlayer = 1;
    }
    (&g_CardSlot_Toughness)[card_index * 0x120 + player * 0x5b20] = 0xff;
    *(int *)(&g_CardSlot_OriginalCardId + card_index * 0x120 + player * 0x5b20) =
         (int)(char)(&g_CardSlot_Toughness)[card_index * 0x120 + player * 0x5b20];
    *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) =
         *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) | 0x10;
  }
  return slot_idx;
}

/*
 * Card_Targeting_PromptCreature
 * Purpose: Prompt player to select creature target for activated ability.
 * Procedure:
 * 1. Display creature target selector.
 * 2. Return chosen target slot index.
 */
/*
 * Decompiled function: Card_Targeting_PromptCreature
 * Entry Point: 004dae76
 * Size: 430 bytes
 */

int Card_Targeting_PromptCreature(int x,int y,int width,uint32_t height)

{
  int u_res;
  uint32_t arg_8;
  uint32_t arg_9;
  uint32_t arg_10;
  int val_result;
  int arg_11;
  int arg_12;
  int arg_12_00;
  uint32_t arg_13;
  int arg_13_00;
  uint32_t arg_14;
  int arg_14_00;
  uint32_t arg_15;
  int arg_15_00;
  uint32_t arg_16;
  int arg_16_00;
  uint32_t arg_17;
  int arg_17_00;
  uint8_t *arg_18;
  int arg_18_00;
  int arg_19;
  int *arg_20;
  int match_count;
  int slot_idx;
  
  if (height == 0xffffffff) {
    height = 2;
  }
  if (width == 0x73) {
    u_res = 0;
    if ((*(uint32_t *)(&g_CardSlot_Flags + y * 0x120 + x * 0x5b20) & 0x20010) == 0) {
      arg_19 = 0;
      arg_18_00 = 1;
      arg_17_00 = 0;
      arg_16_00 = 0xffffffff;
      arg_15_00 = 0xffffffff;
      arg_14_00 = 0xffffffff;
      arg_13_00 = 0xffffffff;
      arg_12_00 = 0;
      arg_11 = 0;
      u_res = Card_GetColorAndTypeFlags(x,y);
      u_res = UI_PaintBigCardInfo((int *)0x0,0,x,2,2,0x200,2,0,0,u_res,arg_11,arg_12_00,arg_13_00,arg_14_00
                           ,arg_15_00,arg_16_00,arg_17_00,arg_18_00,arg_19);
    }
  }
  else {
    if (width == 0x6d) {
      arg_20 = &match_count;
      u_res = 1;
      arg_18 = &g_OverworldGoldAmount;
      arg_17 = 0;
      arg_16 = 1;
      arg_15 = 0;
      arg_14 = 0xffffffff;
      arg_13 = 0xffffffff;
      arg_12 = -1;
      val_result = -1;
      arg_10 = 0;
      arg_9 = 0;
      arg_8 = Card_GetColorAndTypeFlags(x,y);
      val_result = Duel_ChooseTarget
                        (x,2,height,0x200,2,0,0,arg_8,arg_9,arg_10,val_result,arg_12,arg_13,arg_14,arg_15
                         ,arg_16,arg_17,arg_18,u_res,arg_20);
      if (val_result == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + y * 0x120 + x * 0x5b20) = match_count;
        *(int *)(&g_CardSlot_AttachedAura + y * 0x120 + x * 0x5b20) = slot_idx;
        (&g_CardSlot_TurnPlayed)[y * 0x120 + x * 0x5b20] = 1;
        *(uint32_t *)(&g_CardSlot_Flags + y * 0x120 + x * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_Flags + y * 0x120 + x * 0x5b20) | 0x10;
      }
    }
    u_res = 0;
  }
  return u_res;
}

/*
 * Card_NettlingImp_ForceAttack
 * Purpose: Activate Nettling Imp ability to force creature to attack.
 * Procedure:
 * 1. Validate target non-Wall creature.
 * 2. Set forced attack flag on target creature.
 */
/*
 * Decompiled function: Card_NettlingImp_ForceAttack
 * Entry Point: 004db024
 * Size: 989 bytes
 */

int Card_NettlingImp_ForceAttack(int player,int card_index,int event_code)

{
  int slot_idx;
  
  if (event_code == 0x73) {
    if ((*(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) & 0x20010) == 0) {
      if ((player == g_TurnPlayer) || (0x1a < g_ScWillyScore)) {
        slot_idx = 0;
      }
      else {
        slot_idx = 1;
      }
    }
    else {
      slot_idx = 0;
    }
  }
  else if (event_code == 0x90) {
    Ai_GetOpponentPlayerScore(0);
    slot_idx = 0;
  }
  else {
    if (event_code == 0x6d) {
      Pic_Subsystem_00424500(s_prompts_txt_0052ebe0,s_NETTLING_IMP_0052ebd0);
      slot_idx = Card_Targeting_PromptCreature(player,card_index,0x6d,1 - player);
    }
    if (((event_code == 0x72) &&
        (*(int *)(&g_CardSlot_OriginalCardId + card_index * 0x120 + player * 0x5b20) != -1)) &&
       ((&g_MasterCardRarityTable)
        [*(int *)(&g_CardSlot_CardId +
                 *(int *)(&g_CardSlot_OriginalCardId + card_index * 0x120 + player * 0x5b20) *
                 0x120 + (char)(&g_CardSlot_Toughness)[card_index * 0x120 + player * 0x5b20] *
                         0x5b20) * 0x34] == '\0')) {
      (&g_CardSlot_Toughness)[card_index * 0x120 + player * 0x5b20] = 0xff;
      *(int *)(&g_CardSlot_OriginalCardId + card_index * 0x120 + player * 0x5b20) =
           (int)(char)(&g_CardSlot_Toughness)[card_index * 0x120 + player * 0x5b20];
      *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) & 0xffffffef;
    }
    if (((event_code == 0x15) &&
        (*(int *)(&g_CardSlot_OriginalCardId + card_index * 0x120 + player * 0x5b20) != -1)) &&
       (player != g_TurnPlayer)) {
      *(uint32_t *)(&g_CardSlot_Flags +
               *(int *)(&g_CardSlot_OriginalCardId + card_index * 0x120 + player * 0x5b20) * 0x120
               + (char)(&g_CardSlot_Toughness)[card_index * 0x120 + player * 0x5b20] * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_Flags +
                    *(int *)(&g_CardSlot_OriginalCardId + card_index * 0x120 + player * 0x5b20) *
                    0x120 + (char)(&g_CardSlot_Toughness)[card_index * 0x120 + player * 0x5b20] *
                            0x5b20) | 4;
      g_ActiveBattlefieldFlag = 1;
      (&g_CardSlot_Toughness)[card_index * 0x120 + player * 0x5b20] = 0xff;
      *(int *)(&g_CardSlot_OriginalCardId + card_index * 0x120 + player * 0x5b20) =
           (int)(char)(&g_CardSlot_Toughness)[card_index * 0x120 + player * 0x5b20];
    }
    if (((event_code == 0x1f) &&
        (*(int *)(&g_CardSlot_OriginalCardId + card_index * 0x120 + player * 0x5b20) != -1)) &&
       ((player != g_TurnPlayer &&
        (((&g_CardSlot_Flags)
          [*(int *)(&g_CardSlot_OriginalCardId + card_index * 0x120 + player * 0x5b20) * 0x120 +
           (char)(&g_CardSlot_Toughness)[card_index * 0x120 + player * 0x5b20] * 0x5b20] & 0x40) ==
         0)))) {
      Pic_Subsystem_0044867e
                ((int)(char)(&g_CardSlot_Toughness)[card_index * 0x120 + player * 0x5b20],
                 *(int *)(&g_CardSlot_OriginalCardId + card_index * 0x120 + player * 0x5b20),2);
    }
  }
  return slot_idx;
}

/*
 * Card_NettlingImp_CheckEndTurn
 * Purpose: Destroy creature forced by Nettling Imp if it failed to attack.
 * Procedure:
 * 1. Check if creature attacked during turn.
 * 2. Destroy creature if it did not attack.
 */
/*
 * Decompiled function: Card_NettlingImp_CheckEndTurn
 * Entry Point: 004db401
 * Size: 1224 bytes
 */

bool Card_NettlingImp_CheckEndTurn(int player,int card_index,int event_code)

{
  bool is_valid;
  int val_result;
  
  if (event_code == 0x73) {
    val_result = Card_GetCounters(player,card_index);
    is_valid = 1 < val_result;
  }
  else {
    if ((event_code == 0x6d) && (val_result = Card_GetCounters(player,card_index), 1 < val_result)) {
      *(int *)(&g_CardSlot_CombatTarget + player * 0x5b20 + card_index * 0x120) = player;
      *(int *)(&g_CardSlot_AttachedAura + player * 0x5b20 + card_index * 0x120) = card_index;
      (&g_CardSlot_TurnPlayed)[player * 0x5b20 + card_index * 0x120] = 1;
      if (*(int *)(&g_CardSlot_ConvertedManaCost + player * 0x5b20 + card_index * 0x120) == 0) {
        *(uint32_t *)(&g_CardSlot_ConvertedManaCost + player * 0x5b20 + card_index * 0x120) =
             *(uint32_t *)(&g_CardSlot_ConvertedManaCost + player * 0x5b20 + card_index * 0x120) | 0x80000;
      }
      Card_RemoveCounters(player,card_index,2);
    }
    if (event_code == 0x72) {
      if (*(int *)(&g_CardSlot_CardId +
                  *(int *)(&g_CardSlot_TapState + player * 0x5b20 + card_index * 0x120) * 0x5b20 +
                  *(int *)(&g_CardSlot_SicknessState + player * 0x5b20 + card_index * 0x120) * 0x120) ==
          -1) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_ConvertedManaCost +
                *(int *)(&g_CardSlot_SicknessState + player * 0x5b20 + card_index * 0x120) * 0x120 +
                *(int *)(&g_CardSlot_TapState + player * 0x5b20 + card_index * 0x120) * 0x5b20) =
             *(int *)(&g_CardSlot_ConvertedManaCost +
                     *(int *)(&g_CardSlot_SicknessState + player * 0x5b20 + card_index * 0x120) * 0x120 +
                     *(int *)(&g_CardSlot_TapState + player * 0x5b20 + card_index * 0x120) * 0x5b20) + 1;
        *(int *)(&g_CardSlot_ConvertedManaCost +
                *(int *)(&g_CardSlot_SicknessState + player * 0x5b20 + card_index * 0x120) * 0x120 +
                *(int *)(&g_CardSlot_TapState + player * 0x5b20 + card_index * 0x120) * 0x5b20) =
             *(int *)(&g_CardSlot_ConvertedManaCost +
                     *(int *)(&g_CardSlot_SicknessState + player * 0x5b20 + card_index * 0x120) * 0x120 +
                     *(int *)(&g_CardSlot_TapState + player * 0x5b20 + card_index * 0x120) * 0x5b20) +
             0x100;
        (&g_CardSlot_TurnPlayed)
        [*(int *)(&g_CardSlot_TapState + player * 0x5b20 + card_index * 0x120) * 0x5b20 +
         *(int *)(&g_CardSlot_SicknessState + player * 0x5b20 + card_index * 0x120) * 0x120] = 0;
        if (((&DAT_006a5f56)
             [*(int *)(&g_CardSlot_TapState + player * 0x5b20 + card_index * 0x120) * 0x5b20 +
              *(int *)(&g_CardSlot_SicknessState + player * 0x5b20 + card_index * 0x120) * 0x120] & 8) !=
            0) {
          *(uint32_t *)(&g_CardSlot_ConvertedManaCost +
                   *(int *)(&g_CardSlot_SicknessState + player * 0x5b20 + card_index * 0x120) * 0x120 +
                   *(int *)(&g_CardSlot_TapState + player * 0x5b20 + card_index * 0x120) * 0x5b20) =
               *(uint32_t *)(&g_CardSlot_ConvertedManaCost +
                        *(int *)(&g_CardSlot_SicknessState + player * 0x5b20 + card_index * 0x120) * 0x120
                        + *(int *)(&g_CardSlot_TapState + player * 0x5b20 + card_index * 0x120) * 0x5b20)
               & 0xfff7ffff;
          val_result = Card_ApplyTriggerEffect(g_DialogPromptHwnd, g_DuelArenaHwnd, g_PlayerSelectionPriority, g_DialogPromptHwnd, g_DuelArenaHwnd);
          if (val_result != -1) {
            *(int16_t *)(&g_CardSlot_PowerCounters + val_result * 0x120 + player * 0x5b20) = 1;
            *(int16_t *)(&g_CardSlot_ToughnessCounters + val_result * 0x120 + player * 0x5b20) = 1;
            *(uint32_t *)(&g_CardSlot_ConvertedManaCost + val_result * 0x120 + player * 0x5b20) =
                 *(uint32_t *)(&g_CardSlot_ConvertedManaCost + val_result * 0x120 + player * 0x5b20) | 0x80000
            ;
          }
        }
      }
    }
    if (((((g_CurrentStepCode == 0xcd) || (event_code == 199)) && (g_EventSourceSlot == card_index)) &&
        ((g_EventSourcePlayer == player && (DAT_006b303c != 0)))) && (g_CurrentCardColorTarget == player)) {
      if (event_code == 0x7d) {
        g_CardEventResult = g_CardEventResult | 2;
      }
      if ((event_code == 0x7e) || (event_code == 199)) {
        Card_IncrementCounter(player,card_index);
      }
    }
    if ((event_code == 0x22) || (event_code == 199)) {
      *(int *)(&g_CardSlot_ConvertedManaCost + player * 0x5b20 + card_index * 0x120) = 0;
    }
    is_valid = false;
  }
  return is_valid;
}

/*
 * Card_NettlingImp_IsTargetEligible
 * Purpose: Validate if creature is eligible for Nettling Imp targeting.
 * Procedure:
 * 1. Verify creature is controlled by active turn player and is not a Wall.
 */
/*
 * Decompiled function: Card_NettlingImp_IsTargetEligible
 * Entry Point: 004db8c9
 * Size: 339 bytes
 */

int Card_NettlingImp_IsTargetEligible(int player,int card_index,int event_code)

{
  bool is_valid;
  int val_result;
  int temp_idx;
  int slot_idx;
  
  if (((event_code == 0x1a) && (g_TurnPlayer == player)) &&
     (((&g_CardSlot_Flags)[card_index * 0x120 + player * 0x5b20] & 4) != 0)) {
    val_result = 1 - player;
    is_valid = true;
    for (slot_idx = 0; slot_idx < (int)(&g_PlayerActiveCardCount)[val_result]; slot_idx = slot_idx + 1) {
      temp_idx = Card_IsTapped(val_result,slot_idx);
      if ((temp_idx != 0) && ((char)(&g_CardSlot_ColorMask)[slot_idx * 0x120 + val_result * 0x5b20] == card_index)
         ) {
        is_valid = false;
        break;
      }
    }
    if (is_valid) {
      val_result = Card_ApplyTriggerEffect(player,card_index,g_PlayerSelectionPriority,player,card_index);
      if (val_result != -1) {
        *(int16_t *)(&g_CardSlot_PowerCounters + player * 0x5b20 + val_result * 0x120) = 2;
        *(int16_t *)(&g_CardSlot_ToughnessCounters + player * 0x5b20 + val_result * 0x120) = 0;
      }
    }
  }
  return 0;
}

/*
 * Card_SorceressQueen_SetStats02
 * Purpose: Activate Sorceress Queen ability to set creature stats to 0/2.
 * Procedure:
 * 1. Validate target creature.
 * 2. Set target power to 0 and toughness to 2 until end of turn.
 */
/*
 * Decompiled function: Card_SorceressQueen_SetStats02
 * Entry Point: 004dba1c
 * Size: 1471 bytes
 */

int Card_SorceressQueen_SetStats02(int player,int card_index,int event_code)

{
  int u_res;
  uint32_t u_temp;
  uint32_t uval_3;
  uint32_t uval_4;
  int val_5;
  int arg_11;
  int val_6;
  int arg_12;
  uint32_t uval_7;
  int arg_13;
  uint32_t uval_8;
  int arg_14;
  uint32_t uVar9;
  int arg_15;
  uint32_t uVar10;
  int arg_16;
  uint32_t uVar11;
  int arg_17;
  uint8_t *arg_18;
  int arg_18_00;
  int arg_19;
  int *arg_20;
  int player_idx;
  int card_idx;
  int match_count;
  int slot_idx;
  
  if (event_code == 0x73) {
    u_res = 0;
    if ((*(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) & 0x20010) == 0) {
      arg_19 = 0;
      arg_18_00 = 0;
      arg_17 = 0;
      arg_16 = 0xffffffff;
      arg_15 = 0xffffffff;
      arg_14 = 0xffffffff;
      arg_13 = 0xffffffff;
      arg_12 = 0;
      arg_11 = 0;
      u_res = Card_GetColorAndTypeFlags(player,card_index);
      u_res = UI_PaintBigCardInfo((int *)0x0,0,player,2,2,0x200,2,0,0,u_res,arg_11,arg_12,arg_13,arg_14,
                           arg_15,arg_16,arg_17,arg_18_00,arg_19);
    }
  }
  else if (event_code == 0x90) {
    Ai_GetOpponentPlayerScore(0);
    u_res = 0;
  }
  else {
    if ((event_code == 0x6d) &&
       ((*(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) & 0x20010) == 0)) {
      Pic_Subsystem_00424500(s_prompts_txt_0052ebfc,s_SORCERESS_QUEEN_0052ebec);
      *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) | 0x100000;
      Ai_EvaluateTacticalPosition(0,0x20);
      arg_20 = &player_idx;
      u_res = 1;
      arg_18 = &g_OverworldGoldAmount;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      val_6 = -1;
      val_5 = -1;
      uval_4 = 0;
      uval_3 = 0;
      u_temp = Card_GetColorAndTypeFlags(player,card_index);
      val_5 = Duel_ChooseTarget
                        (player,2,1 - player,0x200,2,0,0,u_temp,uval_3,uval_4,val_5,val_6,uval_7,
                         uval_8,uVar9,uVar10,uVar11,arg_18,u_res,arg_20);
      if (val_5 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + card_index * 0x120 + player * 0x5b20) = player_idx;
        *(int *)(&g_CardSlot_AttachedAura + card_index * 0x120 + player * 0x5b20) = card_idx;
        (&g_CardSlot_TurnPlayed)[card_index * 0x120 + player * 0x5b20] = 1;
        *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) | 0x10;
      }
      *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) & 0xffefffff;
    }
    if (event_code == 0x72) {
      player_idx = *(int *)(&g_CardSlot_CombatTarget + card_index * 0x120 + player * 0x5b20);
      card_idx = *(int *)(&g_CardSlot_AttachedAura + card_index * 0x120 + player * 0x5b20);
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      val_6 = -1;
      val_5 = -1;
      uval_4 = 0;
      uval_3 = 0;
      u_temp = Card_GetColorAndTypeFlags(player,card_index);
      val_5 = Rules_ParseFilter_0040360b
                        (player_idx,card_idx,(char *)0x0,player,2,2,0x200,2,0,0,u_temp,uval_3,uval_4,
                         val_5,val_6,uval_7,uval_8,uVar9,uVar10,uVar11);
      if (val_5 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        for (slot_idx = 0; slot_idx < 2; slot_idx = slot_idx + 1) {
          for (match_count = 0; match_count < (int)(&g_PlayerActiveCardCount)[slot_idx];
              match_count = match_count + 1) {
            if ((((*(int *)(&g_CardSlot_CardId + match_count * 0x120 + slot_idx * 0x5b20) == DAT_006b3060
                  ) && (((&g_CardSlot_Flags)[match_count * 0x120 + slot_idx * 0x5b20] & 2) != 0)) &&
                ((char)(&g_CardSlot_Toughness)[match_count * 0x120 + slot_idx * 0x5b20] == player_idx)) &&
               (*(int *)(&g_CardSlot_OriginalCardId + match_count * 0x120 + slot_idx * 0x5b20) ==
                card_idx)) {
              *(uint32_t *)(&g_CardSlot_Abilities1 + match_count * 0x120 + slot_idx * 0x5b20) =
                   *(uint32_t *)(&g_CardSlot_Abilities1 + match_count * 0x120 + slot_idx * 0x5b20) &
                   0xfeffffff;
            }
          }
        }
        val_5 = Card_ApplyTriggerEffect(g_DialogPromptHwnd,g_DuelArenaHwnd,DAT_006b3060,player_idx,card_idx);
        if (val_5 != -1) {
          *(uint32_t *)(&g_CardSlot_Abilities1 + val_5 * 0x120 + player * 0x5b20) =
               *(uint32_t *)(&g_CardSlot_Abilities1 + val_5 * 0x120 + player * 0x5b20) | 0x1000000;
          *(uint16_t *)(&g_CardSlot_PowerCounters + val_5 * 0x120 + player * 0x5b20) =
               -(*(uint16_t *)
                  (&DAT_0051aec2 +
                  *(int *)(&g_CardSlot_CardId + player_idx * 0x5b20 + card_idx * 0x120) * 0x34) &
                0xbfff);
          *(uint16_t *)(&g_CardSlot_ToughnessCounters + val_5 * 0x120 + player * 0x5b20) =
               2 - (*(uint16_t *)
                     (&DAT_0051aec4 +
                     *(int *)(&g_CardSlot_CardId + player_idx * 0x5b20 + card_idx * 0x120) * 0x34) &
                   0xbfff);
        }
      }
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120] = 0;
    }
    if (((event_code == 0x8a) && (g_EventSourceSlot == card_index)) &&
       (player == g_EventSourcePlayer)) {
      g_AiBlockingCreatureCount = g_AiBlockingCreatureCount + 0xc;
    }
    if (((event_code == 0x8b) && (g_EventSourceSlot == card_index)) &&
       (player == g_EventSourcePlayer)) {
      g_AiBlockingCreatureCount = g_AiBlockingCreatureCount + -0xc;
    }
    u_res = 0;
  }
  return u_res;
}

/*
 * Card_SorceressQueen_ResetStats
 * Purpose: Reset creature stats modified by Sorceress Queen at cleanup.
 * Procedure:
 * 1. Restore original base power and toughness.
 */
/*
 * Decompiled function: Card_SorceressQueen_ResetStats
 * Entry Point: 004dbfdb
 * Size: 746 bytes
 */

void Card_SorceressQueen_ResetStats(int player,int card_index,int event_code)

{
  short s_res;
  int val_result;
  int match_count;
  
  if (event_code != 0x73) {
    if (event_code == 0x90) {
      Ai_GetOpponentPlayerScore(0);
    }
    else {
      if ((event_code == 0x6d) &&
         ((*(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) & 0x20010) == 0)) {
        if (match_count == -1) {
          g_ActivePlayer = 1;
        }
        else {
          (&g_CardSlot_Toughness)[card_index * 0x120 + player * 0x5b20] = g_TemporaryToughnessBuffer;
          *(int *)(&g_CardSlot_OriginalCardId + card_index * 0x120 + player * 0x5b20) = match_count;
        }
      }
      if (event_code == 0x72) {
        val_result = Card_ApplyTriggerEffect(player,card_index,g_PlayerSelectionPriority,
                             (int)(char)(&g_CardSlot_Toughness)[card_index * 0x120 + player * 0x5b20],
                             *(int *)(&g_CardSlot_OriginalCardId + card_index * 0x120 + player * 0x5b20));
        if (val_result != -1) {
          s_res = Magic_QueryCardAttribute((int)(char)(&g_CardSlot_Toughness)[card_index * 0x120 + player * 0x5b20],
                               *(int *)(&g_CardSlot_OriginalCardId + card_index * 0x120 + player * 0x5b20)
                               ,0x32,0xffffffff);
          *(short *)(&g_CardSlot_PowerCounters + val_result * 0x120 + player * 0x5b20) = -s_res;
        }
        *(int *)(&g_CardSlot_OriginalCardId + card_index * 0x120 + player * 0x5b20) = 0xffffffff;
        (&g_CardSlot_Toughness)[card_index * 0x120 + player * 0x5b20] =
             (&g_CardSlot_OriginalCardId)[card_index * 0x120 + player * 0x5b20];
        *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) | 0x10;
      }
    }
  }
  return;
}

/*
 * Card_StoneGiant_Fling
 * Purpose: Activate Stone Giant ability to grant flying to smaller creature.
 * Procedure:
 * 1. Validate creature target with toughness less than Stone Giant power.
 * 2. Grant flying until end of turn.
 * 3. Destroy target creature at end of turn.
 */
/*
 * Decompiled function: Card_StoneGiant_Fling
 * Entry Point: 004dc2ca
 * Size: 1021 bytes
 */

int Card_StoneGiant_Fling(int player,int card_index,int event_code)

{
  uint32_t u_res;
  int u_temp;
  int temp_idx;
  uint32_t uval_4;
  uint32_t uval_5;
  uint32_t uval_6;
  int arg_11;
  int val_7;
  int arg_12;
  uint32_t uval_8;
  int arg_13;
  int arg_14;
  uint32_t uVar9;
  uint32_t uVar10;
  int arg_16;
  uint32_t uVar11;
  int arg_17;
  uint8_t *arg_18;
  int arg_18_00;
  int arg_19;
  int *arg_20;
  int card_idx;
  int match_count;
  
  if (event_code == 0x73) {
    u_temp = 0;
    if ((*(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) & 0x20010) == 0) {
      arg_19 = 0;
      arg_18_00 = 0;
      arg_17 = 0;
      arg_16 = 0xffffffff;
      u_res = (int)*(short *)(&g_CardSlot_Counters + card_index * 0x120 + player * 0x5b20) - 1U |
              0x2000;
      arg_14 = 0xffffffff;
      arg_13 = 0xffffffff;
      arg_12 = 0;
      arg_11 = 0;
      u_temp = Card_GetColorAndTypeFlags(player,card_index);
      u_temp = UI_PaintBigCardInfo((int *)0x0,0,player,player,player,0x200,2,0,0,u_temp,arg_11,arg_12,
                           arg_13,arg_14,u_res,arg_16,arg_17,arg_18_00,arg_19);
    }
  }
  else if (event_code == 0x90) {
    Ai_GetOpponentPlayerScore(0);
    u_temp = 0;
  }
  else {
    if ((event_code == 0x6d) &&
       ((*(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) & 0x20010) == 0)) {
      Pic_Subsystem_00424500(s_prompts_txt_0052ec14,s_STONE_GIANT_0052ec08);
      arg_20 = &card_idx;
      u_temp = 1;
      arg_18 = &g_OverworldGoldAmount;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      temp_idx = Magic_QueryCardAttribute(player,card_index,0x32,0xffffffff);
      u_res = temp_idx - 1U | 0x2000;
      uval_8 = 0xffffffff;
      val_7 = -1;
      temp_idx = -1;
      uval_6 = 0;
      uval_5 = 0;
      uval_4 = Card_GetColorAndTypeFlags(player,card_index);
      temp_idx = Duel_ChooseTarget
                        (player,player,player,0x200,2,0,0,uval_4,uval_5,uval_6,temp_idx,val_7,uval_8,
                         u_res,uVar9,uVar10,uVar11,arg_18,u_temp,arg_20);
      if (temp_idx == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + card_index * 0x120 + player * 0x5b20) = card_idx;
        *(int *)(&g_CardSlot_AttachedAura + card_index * 0x120 + player * 0x5b20) = match_count;
        (&g_CardSlot_TurnPlayed)[card_index * 0x120 + player * 0x5b20] = 1;
        *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) | 0x10;
      }
    }
    if (event_code == 0x72) {
      card_idx = *(int *)(&g_CardSlot_CombatTarget + card_index * 0x120 + player * 0x5b20);
      match_count = *(int *)(&g_CardSlot_AttachedAura + card_index * 0x120 + player * 0x5b20);
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      u_res = (int)*(short *)(&g_CardSlot_Counters + card_index * 0x120 + player * 0x5b20) - 1U |
              0x2000;
      uval_8 = 0xffffffff;
      val_7 = -1;
      temp_idx = -1;
      uval_6 = 0;
      uval_5 = 0;
      uval_4 = Card_GetColorAndTypeFlags(player,card_index);
      temp_idx = Rules_ParseFilter_0040360b
                        (card_idx,match_count,(char *)0x0,player,(uint8_t)player,(uint8_t)player,0x200,2
                         ,0,0,uval_4,uval_5,uval_6,temp_idx,val_7,uval_8,u_res,uVar9,uVar10,uVar11);
      if (temp_idx == 0) {
        g_ActivePlayer = 1;
      }
      else {
        temp_idx = Card_ApplyTriggerEffect(g_DialogPromptHwnd,g_DuelArenaHwnd,DAT_0069f6dc,card_idx,match_count);
        if (temp_idx != -1) {
          (&g_CardSlot_CardTypeIndex)[temp_idx * 0x120 + player * 0x5b20] = 5;
          *(int *)(&g_CardSlot_ConvertedManaCost + temp_idx * 0x120 + player * 0x5b20) = 0x20;
          *(int *)(&g_CardSlot_Abilities2 + card_idx * 0x5b20 + match_count * 0x120) = 0x8000000;
        }
      }
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120 +
       *(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20] = 0;
    }
    u_temp = 0;
  }
  return u_temp;
}

/*
 * Card_DwarvenWarriors_MakeUnblockable
 * Purpose: Activate Dwarven Warriors ability making creature unblockable.
 * Procedure:
 * 1. Validate creature target with power 2 or less.
 * 2. Set unblockable flag until end of turn.
 */
/*
 * Decompiled function: Card_DwarvenWarriors_MakeUnblockable
 * Entry Point: 004dc6c7
 * Size: 806 bytes
 */

int Card_DwarvenWarriors_MakeUnblockable(int player,int card_index,int event_code)

{
  int u_res;
  uint32_t u_temp;
  uint32_t uval_3;
  uint32_t uval_4;
  int val_5;
  int arg_11;
  int val_6;
  int arg_12;
  uint32_t uval_7;
  int arg_13;
  uint32_t uval_8;
  int arg_14;
  uint32_t uVar9;
  int arg_15;
  uint32_t uVar10;
  int arg_16;
  uint32_t uVar11;
  int arg_17;
  uint8_t *arg_18;
  int arg_18_00;
  int arg_19;
  int *arg_20;
  int match_count;
  int slot_idx;
  
  if (event_code == 0x73) {
    u_res = 0;
    if ((*(uint32_t *)(&g_CardSlot_Flags + player * 0x5b20 + card_index * 0x120) & 0x20010) == 0) {
      arg_19 = 0;
      arg_18_00 = 0;
      arg_17 = 0;
      arg_16 = 0xffffffff;
      arg_15 = 0x2002;
      arg_14 = 0xffffffff;
      arg_13 = 0xffffffff;
      arg_12 = 0;
      arg_11 = 0;
      u_res = Card_GetColorAndTypeFlags(player,card_index);
      u_res = UI_PaintBigCardInfo((int *)0x0,0,player,2,2,0x200,2,0,0,u_res,arg_11,arg_12,arg_13,arg_14,
                           arg_15,arg_16,arg_17,arg_18_00,arg_19);
    }
  }
  else if (event_code == 0x90) {
    Ai_GetOpponentPlayerScore(0);
    u_res = 0;
  }
  else {
    if ((event_code == 0x6d) &&
       ((*(uint32_t *)(&g_CardSlot_Flags + player * 0x5b20 + card_index * 0x120) & 0x20010) == 0)) {
      Pic_Subsystem_00424500(s_prompts_txt_0052ec34,s_DWARVEN_WARRIORS_0052ec20);
      arg_20 = &match_count;
      u_res = 1;
      arg_18 = &g_OverworldGoldAmount;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uval_8 = 0xffffffff;
      uval_7 = 0x2002;
      val_6 = -1;
      val_5 = -1;
      uval_4 = 0;
      uval_3 = 0;
      u_temp = Card_GetColorAndTypeFlags(player,card_index);
      val_5 = Duel_ChooseTarget
                        (player,2,player,0x200,2,0,0,u_temp,uval_3,uval_4,val_5,val_6,uval_7,uval_8,
                         uVar9,uVar10,uVar11,arg_18,u_res,arg_20);
      if (val_5 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + player * 0x5b20 + card_index * 0x120) = match_count;
        *(int *)(&g_CardSlot_AttachedAura + player * 0x5b20 + card_index * 0x120) = slot_idx;
        (&g_CardSlot_TurnPlayed)[player * 0x5b20 + card_index * 0x120] = 1;
        *(uint32_t *)(&g_CardSlot_Flags + player * 0x5b20 + card_index * 0x120) =
             *(uint32_t *)(&g_CardSlot_Flags + player * 0x5b20 + card_index * 0x120) | 0x10;
      }
    }
    if (event_code == 0x72) {
      match_count = *(int *)(&g_CardSlot_CombatTarget + player * 0x5b20 + card_index * 0x120);
      slot_idx = *(int *)(&g_CardSlot_AttachedAura + player * 0x5b20 + card_index * 0x120);
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uval_8 = 0xffffffff;
      uval_7 = 0x2002;
      val_6 = -1;
      val_5 = -1;
      uval_4 = 0;
      uval_3 = 0;
      u_temp = Card_GetColorAndTypeFlags(player,card_index);
      val_5 = Rules_ParseFilter_0040360b
                        (match_count,slot_idx,(char *)0x0,player,2,2,0x200,2,0,0,u_temp,uval_3,uval_4,
                         val_5,val_6,uval_7,uval_8,uVar9,uVar10,uVar11);
      if (val_5 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        Card_ApplyTriggerEffect(g_DialogPromptHwnd,g_DuelArenaHwnd,DAT_00696734,match_count,slot_idx);
      }
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_TapState + player * 0x5b20 + card_index * 0x120) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + player * 0x5b20 + card_index * 0x120) * 0x120] = 0;
    }
    u_res = 0;
  }
  return u_res;
}

/*
 * Card_CavePeople_Mountainwalk
 * Purpose: Activate Cave People ability granting mountainwalk.
 * Procedure:
 * 1. Pay activation cost.
 * 2. Grant mountainwalk until end of turn.
 */
/*
 * Decompiled function: Card_CavePeople_Mountainwalk
 * Entry Point: 004dc9ed
 * Size: 1124 bytes
 */

int Card_CavePeople_Mountainwalk(int player,int card_index,int event_code)

{
  char c_res;
  int val_result;
  int uval_3;
  uint32_t uval_4;
  bool bVar5;
  uint32_t uval_6;
  uint32_t uval_7;
  int arg_11;
  int val_8;
  int arg_12;
  uint32_t uVar9;
  int arg_13;
  uint32_t uVar10;
  int arg_14;
  uint32_t uVar11;
  int arg_15;
  uint32_t uVar12;
  int arg_16;
  uint32_t uVar13;
  int arg_17;
  uint8_t *arg_18;
  int arg_18_00;
  int arg_19;
  int *arg_20;
  int card_idx;
  int match_count;
  int slot_idx;
  
  if (event_code == 0x73) {
    bVar5 = (*(uint32_t *)(&g_CardSlot_Flags + player * 0x5b20 + card_index * 0x120) & 0x20010) == 0;
    if ((bVar5) && (val_result = Font_DrawString(player,4,2), val_result == 0)) {
      bVar5 = false;
    }
    if ((bVar5) && (val_result = Font_DrawString(player,7,3), val_result == 0)) {
      bVar5 = false;
    }
    uval_3 = 0;
    if (bVar5) {
      arg_19 = 0;
      arg_18_00 = 0;
      arg_17 = 0;
      arg_16 = 0xffffffff;
      arg_15 = 0xffffffff;
      arg_14 = 0xffffffff;
      arg_13 = 0xffffffff;
      arg_12 = 0;
      arg_11 = 0;
      uval_3 = Card_GetColorAndTypeFlags(player,card_index);
      uval_3 = UI_PaintBigCardInfo((int *)0x0,0,player,2,2,0x200,2,0,0,uval_3,arg_11,arg_12,arg_13,arg_14,
                           arg_15,arg_16,arg_17,arg_18_00,arg_19);
    }
  }
  else if (event_code == 0x90) {
    Ai_GetOpponentPlayerScore(0);
    uval_3 = 0;
  }
  else {
    if (((card_index == g_EventSourceSlot) && (player == g_EventSourcePlayer)) &&
       (((&g_CardSlot_Flags)[player * 0x5b20 + card_index * 0x120] & 0x44) != 0)) {
      if (event_code == 0x32) {
        g_CardEventResult = g_CardEventResult + 1;
      }
      if (event_code == 0x33) {
        g_CardEventResult = g_CardEventResult + -2;
      }
    }
    if ((event_code == 0x6d) &&
       ((*(uint32_t *)(&g_CardSlot_Flags + player * 0x5b20 + card_index * 0x120) & 0x20010) == 0)) {
      g_AiSelectedTargetCard = 1;
      Ai_CalcManaRequirement_004ba890(player,4,2);
      if (g_ActivePlayer != 1) {
        Pic_Subsystem_00424500(s_prompts_txt_0052ec4c,s_CAVE_PEOPLE_0052ec40);
        arg_20 = &card_idx;
        uval_3 = 1;
        arg_18 = &g_OverworldGoldAmount;
        uVar13 = 0;
        uVar12 = 0;
        uVar11 = 0;
        uVar10 = 0xffffffff;
        uVar9 = 0xffffffff;
        val_8 = -1;
        val_result = -1;
        uval_7 = 0;
        uval_6 = 0;
        uval_4 = Card_GetColorAndTypeFlags(player,card_index);
        val_result = Duel_ChooseTarget
                          (player,2,player,0x200,2,0,0,uval_4,uval_6,uval_7,val_result,val_8,uVar9,
                           uVar10,uVar11,uVar12,uVar13,arg_18,uval_3,arg_20);
        if (val_result == 0) {
          g_ActivePlayer = 1;
        }
        else {
          *(int *)(&g_CardSlot_CombatTarget + player * 0x5b20 + card_index * 0x120) = card_idx;
          *(int *)(&g_CardSlot_AttachedAura + player * 0x5b20 + card_index * 0x120) = match_count;
          (&g_CardSlot_TurnPlayed)[player * 0x5b20 + card_index * 0x120] = 1;
          *(uint32_t *)(&g_CardSlot_Flags + player * 0x5b20 + card_index * 0x120) =
               *(uint32_t *)(&g_CardSlot_Flags + player * 0x5b20 + card_index * 0x120) | 0x10;
        }
      }
    }
    if (event_code == 0x72) {
      card_idx = *(int *)(&g_CardSlot_CombatTarget + player * 0x5b20 + card_index * 0x120);
      match_count = *(int *)(&g_CardSlot_AttachedAura + player * 0x5b20 + card_index * 0x120);
      uVar13 = 0;
      uVar12 = 0;
      uVar11 = 0;
      uVar10 = 0xffffffff;
      uVar9 = 0xffffffff;
      val_8 = -1;
      val_result = -1;
      uval_7 = 0;
      uval_6 = 0;
      uval_4 = Card_GetColorAndTypeFlags(player,card_index);
      val_result = Rules_ParseFilter_0040360b
                        (card_idx,match_count,(char *)0x0,player,2,2,0x200,2,0,0,uval_4,uval_6,uval_7,
                         val_result,val_8,uVar9,uVar10,uVar11,uVar12,uVar13);
      if (val_result == 0) {
        g_ActivePlayer = 1;
      }
      else {
        slot_idx = Card_ApplyTriggerEffect(g_DialogPromptHwnd,g_DuelArenaHwnd,DAT_0069f6dc,card_idx,match_count);
        if (slot_idx != -1) {
          c_res = Card_UntapCard(player, card_index, 4);
          *(int *)(&g_CardSlot_ConvertedManaCost + slot_idx * 0x120 + player * 0x5b20) =
               1 << (c_res - 1U & 0x1f);
        }
        *(int *)(&g_CardSlot_Abilities2 + card_idx * 0x5b20 + match_count * 0x120) = 0x8000000;
      }
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_TapState + player * 0x5b20 + card_index * 0x120) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + player * 0x5b20 + card_index * 0x120) * 0x120] = 0;
    }
    uval_3 = 0;
  }
  return uval_3;
}

/*
 * Card_PradeshGypsies_PreventAttack
 * Purpose: Activate Pradesh Gypsies ability preventing creature from attacking.
 * Procedure:
 * 1. Pay activation cost and tap target creature.
 * 2. Prevent target creature from attacking this turn.
 */
/*
 * Decompiled function: Card_PradeshGypsies_PreventAttack
 * Entry Point: 004dce51
 * Size: 1258 bytes
 */

int Card_PradeshGypsies_PreventAttack(int player,int card_index,int event_code)

{
  int status;
  int u_temp;
  uint32_t uval_3;
  bool bVar4;
  uint32_t uval_5;
  uint32_t uval_6;
  int arg_11;
  int val_7;
  int arg_12;
  uint32_t uval_8;
  int arg_13;
  uint32_t uVar9;
  int arg_14;
  uint32_t uVar10;
  int arg_15;
  uint32_t uVar11;
  int arg_16;
  uint32_t uVar12;
  int arg_17;
  uint8_t *arg_18;
  int arg_18_00;
  int arg_19;
  int *arg_20;
  int card_idx;
  int match_count;
  int slot_idx;
  
  if (event_code == 0x73) {
    bVar4 = (*(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) & 0x20010) == 0;
    if ((bVar4) && (status = Font_DrawString(player,3,1), status == 0)) {
      bVar4 = false;
    }
    if ((bVar4) && (status = Font_DrawString(player, 7, 2), status == 0)) {
      bVar4 = false;
    }
    u_temp = 0;
    if (bVar4) {
      arg_19 = 0;
      arg_18_00 = 0;
      arg_17 = 0;
      arg_16 = 0xffffffff;
      arg_15 = 0xffffffff;
      arg_14 = 0xffffffff;
      arg_13 = 0xffffffff;
      arg_12 = 0;
      arg_11 = 0;
      u_temp = Card_GetColorAndTypeFlags(player,card_index);
      u_temp = UI_PaintBigCardInfo((int *)0x0,0,player,2,2,0x200,2,0,0,u_temp,arg_11,arg_12,arg_13,arg_14,
                           arg_15,arg_16,arg_17,arg_18_00,arg_19);
    }
  }
  else if (event_code == 0x90) {
    Ai_GetOpponentPlayerScore(0);
    u_temp = 0;
  }
  else {
    if ((event_code == 0x6d) &&
       ((*(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) & 0x20010) == 0)) {
      g_AiSelectedTargetCard = 1;
      Ai_CalcManaRequirement_004ba890(player,3,1);
      if (g_ActivePlayer != 1) {
        Pic_Subsystem_00424500(s_prompts_txt_0052ec68,s_PRADESH_GYPSIES_0052ec58);
        arg_20 = &card_idx;
        u_temp = 1;
        arg_18 = &g_OverworldGoldAmount;
        uVar12 = 0;
        uVar11 = 0;
        uVar10 = 0;
        uVar9 = 0xffffffff;
        uval_8 = 0xffffffff;
        val_7 = -1;
        status = -1;
        uval_6 = 0;
        uval_5 = 0;
        uval_3 = Card_GetColorAndTypeFlags(player,card_index);
        status = Duel_ChooseTarget
                          (player,2,player,0x200,2,0,0,uval_3,uval_5,uval_6,status,val_7,uval_8,uVar9
                           ,uVar10,uVar11,uVar12,arg_18,u_temp,arg_20);
        if (status == 0) {
          g_ActivePlayer = 1;
        }
        else {
          *(int *)(&g_CardSlot_CombatTarget + card_index * 0x120 + player * 0x5b20) = card_idx;
          *(int *)(&g_CardSlot_AttachedAura + card_index * 0x120 + player * 0x5b20) = match_count;
          (&g_CardSlot_TurnPlayed)[card_index * 0x120 + player * 0x5b20] = 1;
          *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) =
               *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) | 0x10;
        }
      }
    }
    if (event_code == 0x72) {
      card_idx = *(int *)(&g_CardSlot_CombatTarget + card_index * 0x120 + player * 0x5b20);
      match_count = *(int *)(&g_CardSlot_AttachedAura + card_index * 0x120 + player * 0x5b20);
      uVar12 = 0;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0xffffffff;
      uval_8 = 0xffffffff;
      val_7 = -1;
      status = -1;
      uval_6 = 0;
      uval_5 = 0;
      uval_3 = Card_GetColorAndTypeFlags(player,card_index);
      status = Rules_ParseFilter_0040360b
                        (card_idx,match_count,(char *)0x0,player,2,2,0x200,2,0,0,uval_3,uval_5,uval_6,
                         status,val_7,uval_8,uVar9,uVar10,uVar11,uVar12);
      if (status == 0) {
        g_ActivePlayer = 1;
      }
      else {
        slot_idx = Card_ApplyTriggerEffect(g_DialogPromptHwnd,g_DuelArenaHwnd,g_PlayerSelectionPriority,card_idx,match_count);
        if (slot_idx != -1) {
          *(int16_t *)(&g_CardSlot_PowerCounters + slot_idx * 0x120 + player * 0x5b20) = 0xfffe;
          *(int16_t *)(&g_CardSlot_ToughnessCounters + slot_idx * 0x120 + player * 0x5b20) = 0;
        }
      }
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120] = 0;
    }
    if ((((event_code == 0x3b) &&
         ((*(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) & 0x20010) == 0)) &&
        (status = Font_DrawString(player,3,1), status != 0)) &&
       (status = Font_DrawString(player, 7, 2), status != 0)) {
      *(int *)(&DAT_00695eb0 + (1 - player) * 4) =
           *(int *)(&DAT_00695eb0 + (1 - player) * 4) + -2;
    }
    if (((event_code == 0x8a) && (card_index == g_EventSourceSlot)) &&
       ((player == g_EventSourcePlayer && (status = Font_DrawString(player,3,1), status != 0))))
    {
      g_AiBlockingCreatureCount = g_AiBlockingCreatureCount + 0xc;
    }
    if (((event_code == 0x8b) && (card_index == g_EventSourceSlot)) &&
       ((player == g_EventSourcePlayer && (status = Font_DrawString(player,3,1), status != 0))))
    {
      g_AiBlockingCreatureCount = g_AiBlockingCreatureCount + -0xc;
    }
    u_temp = 0;
  }
  return u_temp;
}

/*
 * Card_PradeshGypsies_ResetRestriction
 * Purpose: Clear attack restriction applied by Pradesh Gypsies at end of turn.
 * Procedure:
 * 1. Reset attack restriction flag.
 */
/*
 * Decompiled function: Card_PradeshGypsies_ResetRestriction
 * Entry Point: 004dd33b
 * Size: 754 bytes
 */

int Card_PradeshGypsies_ResetRestriction(int player,int card_index,int event_code)

{
  int u_res;
  int val_result;
  int match_count;
  
  if (event_code == 0x73) {
    if (g_CurrentTurnPhase == player) {
      if (((*(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) & 0x20010) == 0) &&
         (((DAT_006a282c | g_PlayerPoisonCounters) & 2) != 0)) {
        u_res = 1;
      }
      else {
        u_res = 0;
      }
    }
    else if (((*(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) & 0x20010) == 0) &&
            ((*(uint8_t *)(&g_PlayerPoisonCounters + g_ActivePlayerPriority) & 2) != 0)) {
      u_res = 1;
    }
    else {
      u_res = 0;
    }
  }
  else if (event_code == 0x90) {
    Ai_GetOpponentPlayerScore(0);
    u_res = 0;
  }
  else {
    if ((event_code == 0x6d) &&
       ((*(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) & 0x20010) == 0)) {
      if (match_count == -1) {
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[card_index * 0x120 + player * 0x5b20] = g_TemporaryToughnessBuffer;
        *(int *)(&g_CardSlot_OriginalCardId + card_index * 0x120 + player * 0x5b20) = match_count;
      }
      *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) | 0x10;
    }
    if (event_code == 0x72) {
      val_result = Card_ApplyTriggerEffect(player,card_index,g_PlayerSelectionPriority,
                           (int)(char)(&g_CardSlot_Toughness)[card_index * 0x120 + player * 0x5b20],
                           *(int *)(&g_CardSlot_OriginalCardId + card_index * 0x120 + player * 0x5b20));
      if (val_result != -1) {
        *(int16_t *)(&g_CardSlot_PowerCounters + val_result * 0x120 + player * 0x5b20) = 1;
        *(int16_t *)(&g_CardSlot_ToughnessCounters + val_result * 0x120 + player * 0x5b20) = 1;
      }
      *(int *)(&g_CardSlot_OriginalCardId + card_index * 0x120 + player * 0x5b20) = 0xffffffff;
      (&g_CardSlot_Toughness)[card_index * 0x120 + player * 0x5b20] =
           (&g_CardSlot_OriginalCardId)[card_index * 0x120 + player * 0x5b20];
    }
    if ((event_code == 0x3b) &&
       ((*(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) & 0x20014) == 0)) {
      *(int *)(&DAT_00695eb0 + player * 4) = *(int *)(&DAT_00695eb0 + player * 4) + 1;
      *(int *)(&DAT_00695eb8 + player * 4) = *(int *)(&DAT_00695eb8 + player * 4) + 1;
    }
    u_res = 0;
  }
  return u_res;
}

/*
 * Card_SamiteHealer_PreventDamage
 * Purpose: Activate Samite Healer ability to prevent 1 damage.
 * Procedure:
 * 1. Validate target creature or player.
 * 2. Apply 1 point damage prevention shield.
 */
/*
 * Decompiled function: Card_SamiteHealer_PreventDamage
 * Entry Point: 004dd632
 * Size: 861 bytes
 */

uint8_t Card_SamiteHealer_PreventDamage(int player,int card_index,int event_code)

{
  uint8_t u_res;
  int val_result;
  int match_count;
  int slot_idx;
  
  if (event_code == 0x73) {
    u_res = 0;
    if ((*(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) & 0x20010) == 0 &&
        ((uint8_t)g_DuelModeFlags & 4) != 0) {
      val_result = UI_PaintBigCardInfo((int *)0x0,0,player,2,2,0x200,0,0,0,0,0,0,g_PendingSpellTargetSlot,0xffffffff,
                           0xffffffff,0xffffffff,0,0,0);
      if (val_result == 0) {
        u_res = 0;
      }
      else {
        u_res = 99;
      }
    }
  }
  else if (event_code == 0x90) {
    Ai_GetOpponentPlayerScore(0);
    u_res = 0;
  }
  else {
    if (event_code == 0x6d) {
      Pic_Subsystem_00424500(s_prompts_txt_0052ec84,s_SAMITE_HEALER_0052ec74);
      val_result = Duel_ChooseTarget
                        (player,2,2,0x200,0,0,0,0,0,0,g_PendingSpellTargetSlot,-1,0xffffffff,0xffffffff,0,0,0,
                         &g_OverworldGoldAmount,1,&match_count);
      if (val_result == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + card_index * 0x120 + player * 0x5b20) = match_count;
        *(int *)(&g_CardSlot_AttachedAura + card_index * 0x120 + player * 0x5b20) = slot_idx;
        (&g_CardSlot_TurnPlayed)[card_index * 0x120 + player * 0x5b20] = 1;
        *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) | 0x10;
      }
    }
    if (event_code == 0x72) {
      match_count = *(int *)(&g_CardSlot_CombatTarget + card_index * 0x120 + player * 0x5b20);
      slot_idx = *(int *)(&g_CardSlot_AttachedAura + card_index * 0x120 + player * 0x5b20);
      val_result = Rules_ParseFilter_0040360b
                        (match_count,slot_idx,(char *)0x0,player,2,2,0x200,0,0,0,0,0,0,g_PendingSpellTargetSlot,-1,
                         0xffffffff,0xffffffff,0,0,0);
      if (val_result == 0) {
        g_ActivePlayer = 1;
      }
      else if (*(int *)(&g_CardSlot_ConvertedManaCost + match_count * 0x5b20 + slot_idx * 0x120) != 0) {
        *(int *)(&g_CardSlot_ConvertedManaCost + match_count * 0x5b20 + slot_idx * 0x120) =
             *(int *)(&g_CardSlot_ConvertedManaCost + match_count * 0x5b20 + slot_idx * 0x120) + -1;
      }
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120] = 0;
    }
    if ((event_code == 0x3b) &&
       ((*(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) & 0x20010) == 0)) {
      *(int *)(&DAT_00695eb8 + player * 4) = *(int *)(&DAT_00695eb8 + player * 4) + 1;
    }
    u_res = 0;
  }
  return u_res;
}

/*
 * Card_SamiteHealer_CalculateHealAdvantage
 * Purpose: Calculate AI tactical heuristic for Samite Healer prevention.
 * Procedure:
 * 1. Evaluate damage on friendly creatures and player life.
 */
/*
 * Decompiled function: Card_SamiteHealer_CalculateHealAdvantage
 * Entry Point: 004dd98f
 * Size: 869 bytes
 */

int Card_SamiteHealer_CalculateHealAdvantage(int player,int card_index,int event_code)

{
  int u_res;
  int slot_idx;
  
  if (event_code == 0x73) {
    if (((*(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) & 0x20010) == 0) &&
       (((uint8_t)g_DuelModeFlags & 4) != 0)) {
      u_res = 1;
    }
    else {
      u_res = 0;
    }
  }
  else if (event_code == 0x90) {
    Ai_GetOpponentPlayerScore(0);
    u_res = 0;
  }
  else {
    if (event_code == 0x6d) {
      if ((slot_idx == -1) ||
         (*(int *)(&g_CardSlot_CardId +
                  *(int *)(&g_CardSlot_AttachedAura + card_index * 0x120 + player * 0x5b20) * 0x120 +
                  *(int *)(&g_CardSlot_CombatTarget + card_index * 0x120 + player * 0x5b20) * 0x5b20) !=
          g_PendingSpellTargetSlot)) {
        g_ActivePlayer = 1;
      }
      else if ((*(int *)(&g_CardSlot_ConvertedManaCost +
                        *(int *)(&g_CardSlot_AttachedAura + card_index * 0x120 + player * 0x5b20) * 0x120
                        + *(int *)(&g_CardSlot_CombatTarget + card_index * 0x120 + player * 0x5b20) *
                          0x5b20) == 0) ||
              (((&g_MasterCardColorTable)
                [*(int *)(&g_CardSlot_CardId +
                         *(int *)(&g_CardSlot_OriginalCardId +
                                 *(int *)(&g_CardSlot_AttachedAura + card_index * 0x120 + player * 0x5b20)
                                 * 0x120 + *(int *)(&g_CardSlot_CombatTarget +
                                                   card_index * 0x120 + player * 0x5b20) * 0x5b20) * 0x120
                         + (char)(&g_CardSlot_Toughness)
                                 [*(int *)(&g_CardSlot_AttachedAura + card_index * 0x120 + player * 0x5b20
                                          ) * 0x120 +
                                  *(int *)(&g_CardSlot_CombatTarget + card_index * 0x120 + player * 0x5b20
                                          ) * 0x5b20] * 0x5b20) * 0x34] & 0x40) == 0)) {
        g_ActivePlayer = 1;
      }
      else {
        u_res = Math_Clamp(*(int *)(&g_CardSlot_ConvertedManaCost +
                                     *(int *)(&g_CardSlot_AttachedAura +
                                             card_index * 0x120 + player * 0x5b20) * 0x120 +
                                     *(int *)(&g_CardSlot_CombatTarget +
                                             card_index * 0x120 + player * 0x5b20) * 0x5b20) + -2,0,99);
        *(int *)
         (&g_CardSlot_ConvertedManaCost +
         *(int *)(&g_CardSlot_AttachedAura + card_index * 0x120 + player * 0x5b20) * 0x120 +
         *(int *)(&g_CardSlot_CombatTarget + card_index * 0x120 + player * 0x5b20) * 0x5b20) = u_res;
        *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) | 0x10;
      }
      if (player == g_ActivePlayerPriority) {
        *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) | 0x10;
      }
    }
    u_res = 0;
  }
  return u_res;
}

/*
 * Card_AlabasterPotion_HealOrPrevent
 * Purpose: Execute Alabaster Potion spell (gain X life or prevent X damage).
 * Procedure:
 * 1. Prompt player for life gain or damage prevention mode.
 * 2. Apply life gain or damage prevention shield.
 */
/*
 * Decompiled function: Card_AlabasterPotion_HealOrPrevent
 * Entry Point: 004ddcf4
 * Size: 349 bytes
 */

int Card_AlabasterPotion_HealOrPrevent(int player,int card_index,int event_code)

{
  int slot_idx;
  
  if (((((g_CurrentStepCode == 0xd3) && (g_EventSourceSlot == card_index)) &&
       (g_EventSourcePlayer == player)) &&
      ((g_CurrentCardColorTarget == player && (g_TurnPlayer == player)))) &&
     ((g_EventSourcePlayer == player &&
      (((&g_MasterCardColorTable)
        [*(int *)(&g_CardSlot_CardId + DAT_006b2e14 * 0x120 + DAT_00695f08 * 0x5b20) * 0x34] & 4) !=
       0)))) {
    if (event_code == 0x7d) {
      if (g_CurrentTurnPhase == player) {
        g_CardEventResult = g_CardEventResult | 1;
      }
      else {
        slot_idx = 0;
        while ((slot_idx < 500 && (*(int *)(&g_PlayerDeckCardList + slot_idx * 4 + player * 2000) != -1))) {
          slot_idx = slot_idx + 1;
        }
        if (((int)(&g_ActivePlayerSpellPriority)[player] < 8) && (5 < slot_idx)) {
          g_CardEventResult = g_CardEventResult | 2;
        }
        else {
          g_CardEventResult = g_CardEventResult | 1;
        }
      }
    }
    if (event_code == 0x7e) {
      Magic_ExecuteDrawPhase(player);
    }
  }
  return 0;
}

/*
 * Card_HealingSalve_DamagePrevention
 * Purpose: Process Healing Salve damage prevention shield.
 * Procedure:
 * 1. Deduct incoming damage from active prevention pool.
 */
/*
 * Decompiled function: Card_HealingSalve_DamagePrevention
 * Entry Point: 004dde51
 * Size: 169 bytes
 */

int Card_HealingSalve_DamagePrevention(int player,int card_index,int event_code)

{
  if (((event_code == 0x6c) &&
      (((&g_MasterCardColorTable)
        [*(int *)(&g_CardSlot_CardId + g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20
                 ) * 0x34] & 0x40) != 0)) && (g_EventSourcePlayer != player)) {
    *(short *)(&g_CardSlot_PowerCounters + card_index * 0x120 + player * 0x5b20) =
         *(short *)(&g_CardSlot_PowerCounters + card_index * 0x120 + player * 0x5b20) + 1;
    *(short *)(&g_CardSlot_ToughnessCounters + card_index * 0x120 + player * 0x5b20) =
         *(short *)(&g_CardSlot_ToughnessCounters + card_index * 0x120 + player * 0x5b20) + 1;
  }
  return 0;
}

/*
 * Card_DamagePrevention_ApplyBubble
 * Purpose: Add damage prevention bubble to card slot.
 * Procedure:
 * 1. Increment prevention counter.
 */
/*
 * Decompiled function: Card_DamagePrevention_ApplyBubble
 * Entry Point: 004ddefa
 * Size: 81 bytes
 */

int Card_DamagePrevention_ApplyBubble(int player,int card_index)

{
  if ((card_index == g_EventSourceSlot) && (player == g_EventSourcePlayer)) {
    *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) =
         *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) | 0x2000;
  }
  return 0;
}

/*
 * Card_DamagePrevention_ReduceDamage
 * Purpose: Deduct prevented damage from incoming damage payload.
 * Procedure:
 * 1. Calculate reduced damage amount.
 */
/*
 * Decompiled function: Card_DamagePrevention_ReduceDamage
 * Entry Point: 004ddf4b
 * Size: 77 bytes
 */

int Card_DamagePrevention_ReduceDamage(int player,int card_index,int event_code)

{
  if ((((event_code == 0x34) && (card_index == g_EventSourceSlot)) && (player == g_EventSourcePlayer)) &&
     (player == g_TurnPlayer)) {
    g_CardEventResult = g_CardEventResult & 0xffffffdf;
  }
  return 0;
}

/*
 * Card_DamagePrevention_ClearAtCleanup
 * Purpose: Clear remaining damage prevention shields at cleanup.
 * Procedure:
 * 1. Reset prevention counters to zero.
 */
/*
 * Decompiled function: Card_DamagePrevention_ClearAtCleanup
 * Entry Point: 004ddf98
 * Size: 199 bytes
 */

int Card_DamagePrevention_ClearAtCleanup(int player,int card_index,int event_code)

{
  char c_res;
  
  if (((&g_MasterCardRarityTable)
       [*(int *)(&g_CardSlot_CardId + g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20)
        * 0x34] == '\x02') && (event_code == 0x34)) {
    c_res = Card_UntapCard(player,card_index,1);
    g_CardEventResult = g_CardEventResult | (1 << (c_res - 1U & 0x1f)) + 0x200U;
  }
  if (((event_code == 0x77) && (g_EventSourceSlot == card_index)) && (g_EventSourcePlayer == player)) {
    CardQuery_ForEachPermanent(Card_DamagePrevention_QueryAmount,-1);
    Ai_EvaluateTacticalPosition(0,0xff);
  }
  return 0;
}

/*
 * Card_DamagePrevention_QueryAmount
 * Purpose: Query active damage prevention capacity on target.
 * Procedure:
 * 1. Return available prevention points.
 */
/*
 * Decompiled function: Card_DamagePrevention_QueryAmount
 * Entry Point: 004de05f
 * Size: 84 bytes
 */

int Card_DamagePrevention_QueryAmount(int player,int card_index,int event_code)

{
  if ((&g_MasterCardRarityTable)[event_code * 0x34] == '\x02') {
    *(uint32_t *)(&g_CardSlot_Abilities2 + card_index * 0x120 + player * 0x5b20) =
         *(uint32_t *)(&g_CardSlot_Abilities2 + card_index * 0x120 + player * 0x5b20) | 0x8000000;
  }
  return 1;
}

/*
 * Card_DamagePrevention_PromptTarget
 * Purpose: Prompt player for damage prevention target.
 * Procedure:
 * 1. Display target selector dialog.
 */
/*
 * Decompiled function: Card_DamagePrevention_PromptTarget
 * Entry Point: 004de0b3
 * Size: 77 bytes
 */

int Card_DamagePrevention_PromptTarget(int player,int card_index,int event_code)

{
  int u_res;
  
  if (((event_code == 0x73) || (event_code == 0x6d)) || (event_code == 0x72)) {
    u_res = Card_GenericCreature_Regenerate(player,card_index,event_code,1,1);
  }
  else {
    u_res = 0;
  }
  return u_res;
}

/*
 * Card_DamagePrevention_CheckSource
 * Purpose: Validate damage source for prevention effect.
 * Procedure:
 * 1. Verify source damage validity.
 */
/*
 * Decompiled function: Card_DamagePrevention_CheckSource
 * Entry Point: 004de100
 * Size: 192 bytes
 */

int Card_DamagePrevention_CheckSource(int player,int card_index,int event_code)

{
  char c_res;
  
  if (((&g_MasterCardRarityTable)
       [*(int *)(&g_CardSlot_CardId + g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20)
        * 0x34] == '\x03') &&
     (((&g_CardSlot_Flags)[g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20] & 2) != 0)
     ) {
    if (event_code == 0x34) {
      c_res = Card_UntapCard(player, card_index, 4);
      g_CardEventResult = g_CardEventResult | 1 << (c_res - 1U & 0x1f);
    }
    if ((event_code == 0x32) || (event_code == 0x33)) {
      g_CardEventResult = g_CardEventResult + 1;
    }
  }
  return 0;
}

/*
 * Card_ErgRaiders_UpkeepDamage
 * Purpose: Deal 2 damage to controller if Erg Raiders did not attack.
 * Procedure:
 * 1. Check if Erg Raiders attacked last turn.
 * 2. Deal 2 damage to controller if no attack occurred.
 */
/*
 * Decompiled function: Card_ErgRaiders_UpkeepDamage
 * Entry Point: 004de1c0
 * Size: 414 bytes
 */

int Card_ErgRaiders_UpkeepDamage(int player,int card_index,int event_code)

{
  if ((((event_code == 199) && (card_index == g_EventSourceSlot)) && (player == g_EventSourcePlayer)) &&
     ((player == g_TurnPlayer &&
      ((*(uint32_t *)(&g_CardSlot_Flags + player * 0x5b20 + card_index * 0x120) & 0x30044) == 0)))) {
    if ((player == g_CurrentTurnPhase) && (g_IsAiThinking != 1)) {
      Ai_Subsystem_004cc56d(player,player,card_index,-1,-1,s_Erg_Raiders_take_2_life__0052ec90,0);
    }
    Mem_AllocOrFree_0041df33(player,2,player,card_index);
  }
  if (((g_CurrentStepCode == 0xcd) && (card_index == g_EventSourceSlot)) &&
     ((player == g_EventSourcePlayer &&
      (((player == g_TurnPlayer && (player == g_CurrentCardColorTarget)) &&
       ((*(uint32_t *)(&g_CardSlot_Flags + player * 0x5b20 + card_index * 0x120) & 0x30044) == 0)))))) {
    if (event_code == 0x7d) {
      g_CardEventResult = g_CardEventResult | 2;
    }
    if (event_code == 0x7e) {
      if ((player == g_CurrentTurnPhase) && (g_IsAiThinking != 1)) {
        Ai_Subsystem_004cc56d(player,player,card_index,-1,-1,s_Erg_Raiders_take_2_life__0052ecac,0);
      }
      Mem_AllocOrFree_0041df33(player,2,player,card_index);
    }
  }
  return 0;
}

/*
 * Card_ErgRaiders_MarkAttack
 * Purpose: Mark Erg Raiders as having attacked this turn.
 * Procedure:
 * 1. Set attacked flag on card slot.
 */
/*
 * Decompiled function: Card_ErgRaiders_MarkAttack
 * Entry Point: 004de35e
 * Size: 308 bytes
 */

int Card_ErgRaiders_MarkAttack(int player,int card_index,int event_code)

{
  int status;
  
  if ((((event_code == 0x78) && (card_index == g_EventTargetSlot)) && (player == g_EventTargetPlayer)) &&
     ((&g_MasterCardRarityTable)
      [*(int *)(&g_CardSlot_CardId + g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20)
       * 0x34] == '\0')) {
    g_CardEventResult = 1;
  }
  if ((event_code == 0x15) && (player == g_TurnPlayer)) {
    status = FUN_004726c5(player,card_index);
    if (status != 0) {
      *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) | 4;
      g_ActiveBattlefieldFlag = g_ActiveBattlefieldFlag + 1;
    }
  }
  if (((event_code == 0x22) || (event_code == 199)) &&
     ((player == g_TurnPlayer &&
      ((*(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) & 0x20054) == 0)))) {
    Pic_Subsystem_0044867e(player,card_index,4);
  }
  return 0;
}

/*
 * Card_ErgRaiders_ClearTurnAttack
 * Purpose: Reset Erg Raiders turn attack state at untap.
 * Procedure:
 * 1. Clear attacked flag.
 */
/*
 * Decompiled function: Card_ErgRaiders_ClearTurnAttack
 * Entry Point: 004de492
 * Size: 939 bytes
 */

int Card_ErgRaiders_ClearTurnAttack(int player,int card_index,int event_code)

{
  int arg_3_00;
  int slot_idx;
  
  if ((((event_code == 0x6e) &&
       (*(int *)(&g_CardSlot_CardId + g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20)
        == g_PendingSpellTargetSlot)) &&
      ((char)(&g_CardSlot_DamageReceived)
             [g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20] == player)) &&
     ((*(int *)(&g_CardSlot_TypeFlags +
               g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20) == card_index &&
      (*(int *)(&g_CardSlot_ConvertedManaCost +
               g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20) != 0)))) {
    (&g_CardSlot_DamageReceived)[card_index * 0x120 + player * 0x5b20] =
         (uint8_t)g_EventSourcePlayer;
    *(int *)(&g_CardSlot_TypeFlags + card_index * 0x120 + player * 0x5b20) = g_EventSourceSlot;
  }
  if (((g_CurrentStepCode == 0xd7) && (g_EventSourceSlot == card_index)) &&
     ((g_EventSourcePlayer == player &&
      (((&g_CardSlot_DamageReceived)[card_index * 0x120 + player * 0x5b20] != -1 &&
       (g_CurrentCardColorTarget == player)))))) {
    if (event_code == 0x7d) {
      g_CardEventResult = g_CardEventResult | 2;
    }
    if (event_code == 0x7e) {
      slot_idx = *(int *)(&g_CardSlot_ConvertedManaCost +
                        *(int *)(&g_CardSlot_TypeFlags + card_index * 0x120 + player * 0x5b20) * 0x120 +
                        (char)(&g_CardSlot_DamageReceived)[card_index * 0x120 + player * 0x5b20] * 0x5b20)
      ;
      if (*(int *)(&g_CardSlot_OriginalCardId +
                  *(int *)(&g_CardSlot_TypeFlags + card_index * 0x120 + player * 0x5b20) * 0x120 +
                  (char)(&g_CardSlot_DamageReceived)[card_index * 0x120 + player * 0x5b20] * 0x5b20) != -1
         ) {
        arg_3_00 = Magic_QueryCardAttribute((int)(char)(&g_CardSlot_Toughness)
                                           [*(int *)(&g_CardSlot_TypeFlags +
                                                    card_index * 0x120 + player * 0x5b20) * 0x120 +
                                            (char)(&g_CardSlot_DamageReceived)
                                                  [card_index * 0x120 + player * 0x5b20] * 0x5b20],
                                *(int *)(&g_CardSlot_OriginalCardId +
                                        *(int *)(&g_CardSlot_TypeFlags +
                                                card_index * 0x120 + player * 0x5b20) * 0x120 +
                                        (char)(&g_CardSlot_DamageReceived)
                                              [card_index * 0x120 + player * 0x5b20] * 0x5b20),0x33,
                                0xffffffff);
        slot_idx = Math_Clamp(*(int *)(&g_CardSlot_ConvertedManaCost +
                                       *(int *)(&g_CardSlot_TypeFlags +
                                               card_index * 0x120 + player * 0x5b20) * 0x120 +
                                       (char)(&g_CardSlot_DamageReceived)
                                             [card_index * 0x120 + player * 0x5b20] * 0x5b20),0,arg_3_00);
      }
      (&g_PlayerCreatureCount)[player] = (&g_PlayerCreatureCount)[player] + slot_idx;
      (&g_CardSlot_DamageReceived)[card_index * 0x120 + player * 0x5b20] = 0xff;
    }
  }
  return 0;
}

/*
 * Card_Leviathan_SacrificeLands
 * Purpose: Process Leviathan upkeep requirement (sacrifice two Islands or remain tapped).
 * Procedure:
 * 1. Prompt controller to sacrifice two Islands.
 * 2. Sacrifice Islands or keep Leviathan tapped.
 */
/*
 * Decompiled function: Card_Leviathan_SacrificeLands
 * Entry Point: 004de83d
 * Size: 972 bytes
 */

int Card_Leviathan_SacrificeLands(int player,int card_index,int event_code)

{
  int status;
  
  if (((event_code == 0x6c) && (g_EventSourceSlot == card_index)) && (player == g_EventSourcePlayer)) {
    *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) =
         *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) | 0x10;
  }
  if (((event_code == 0x82) && (g_EventSourceSlot == card_index)) && (player == g_EventSourcePlayer)) {
    *(uint32_t *)(&g_CardSlot_ProtectionFlags + card_index * 0x120 + player * 0x5b20) =
         *(uint32_t *)(&g_CardSlot_ProtectionFlags + card_index * 0x120 + player * 0x5b20) & 0xfffffffc;
  }
  if (((event_code == 0x84) && (g_EventSourceSlot == card_index)) &&
     ((player == g_EventSourcePlayer &&
      (((((&g_CardSlot_Flags)[card_index * 0x120 + player * 0x5b20] & 0x10) != 0 &&
        (player == g_TurnPlayer)) && (player == g_CurrentTurnTargetPlayer)))))) {
    *(uint32_t *)(&g_CardSlot_SpecialState + card_index * 0x120 + player * 0x5b20) =
         *(uint32_t *)(&g_CardSlot_SpecialState + card_index * 0x120 + player * 0x5b20) | 0x10;
  }
  if ((event_code == 0x88) &&
     (status = Card_UntapCard(player,card_index,2), *(int *)(&g_AiCombatScore_Attacker + status * 4 + player * 0x20) < 2))
  {
    g_CardEventResult = g_CardEventResult | 1;
  }
  if (event_code == 1) {
    status = Card_Leviathan_PromptLandSacrifice(player,card_index,1);
    if (status == 0) {
      g_CardEventResult = g_CardEventResult | 1;
    }
    else {
      *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) & 0xffffffef;
    }
  }
  if ((event_code == 0x79) && (*(int *)(&g_CardSlot_TargetSlot + card_index * 0x120 + player * 0x5b20) == 0)) {
    status = Card_UntapCard(player,card_index,2);
    if (*(int *)(&g_AiCombatScore_Attacker + status * 4 + player * 0x20) < 2) {
      g_CardEventResult = 1;
    }
  }
  else {
    if ((((g_CurrentStepCode == 0xdc) &&
         ((((g_ScWillyScore == 0x15 && (g_EventSourceSlot == card_index)) &&
           (player == g_EventSourcePlayer)) &&
          ((g_CurrentCardColorTarget == g_TurnPlayer &&
           (*(int *)(&g_CardSlot_TargetSlot + card_index * 0x120 + player * 0x5b20) == 0)))))) &&
        (player == DAT_00695f08)) && (DAT_006b2e14 == card_index)) {
      status = Card_UntapCard(player,card_index,2);
      if (*(int *)(&g_AiCombatScore_Attacker + status * 4 + player * 0x20) < 2) {
        DAT_0068a65c = 1;
      }
      else {
        if (event_code == 0x7d) {
          g_CardEventResult = g_CardEventResult | 2;
        }
        if (event_code == 0x7e) {
          status = Card_Leviathan_PromptLandSacrifice(player,card_index,0);
          if (status == 0) {
            DAT_0068a65c = 1;
            g_ActivePlayer = 0;
          }
          else {
            *(int *)(&g_CardSlot_TargetSlot + card_index * 0x120 + player * 0x5b20) = 1;
          }
        }
      }
    }
    if ((event_code == 0x22) || (event_code == 199)) {
      *(int *)(&g_CardSlot_TargetSlot + card_index * 0x120 + player * 0x5b20) = 0;
      *(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) =
           *(int *)(&g_CardSlot_TargetSlot + card_index * 0x120 + player * 0x5b20);
    }
  }
  return 0;
}

/*
 * Card_Leviathan_PromptLandSacrifice
 * Purpose: Display land sacrifice selection dialog for Leviathan.
 * Procedure:
 * 1. Prompt player to select two Islands to sacrifice.
 */
/*
 * Decompiled function: Card_Leviathan_PromptLandSacrifice
 * Entry Point: 004dec09
 * Size: 610 bytes
 */

int Card_Leviathan_PromptLandSacrifice(int player,int card_index,int event_code)

{
  int status;
  int u_temp;
  int aiStack_20 [7];
  
  status = Card_UntapCard(player,card_index,2);
  aiStack_20[6] = status + -1;
  aiStack_20[5] = 0;
  while ((aiStack_20[5] < 2 && (g_ActivePlayer != 1))) {
    Pic_Subsystem_00424500(s_prompts_txt_0052ecd4,s_LEVIATHAN_0052ecc8);
    if (aiStack_20[6] == 4) {
      FUN_004f4a92(&g_OverworldGoldAmount,s_island_0052ece8,0,s_PLAINS_0052ece0);
    }
    else if (aiStack_20[6] == 0) {
      FUN_004f4a92(&g_OverworldGoldAmount,s_island_0052ecf8,0,s_SWAMP_0052ecf0);
    }
    else if (aiStack_20[6] == 3) {
      FUN_004f4a92(&g_OverworldGoldAmount,s_island_0052ed0c,0,s_MOUNTAIN_0052ed00);
    }
    else if (aiStack_20[6] == 2) {
      FUN_004f4a92(&g_OverworldGoldAmount,s_island_0052ed1c,0,s_FOREST_0052ed14);
    }
    status = Duel_ChooseTarget
                      (player,player,player,0x200,0,0,0,0,0,0,aiStack_20[6],-1,0xffffffff,
                       0xffffffff,0,0,0,&g_OverworldGoldAmount,(uint32_t)(event_code != 0),
                       aiStack_20 + aiStack_20[5] * 2);
    if (status == 0) {
      for (aiStack_20[4] = 0; aiStack_20[4] < aiStack_20[5]; aiStack_20[4] = aiStack_20[4] + 1) {
        *(uint32_t *)(&g_CardSlot_Flags +
                 aiStack_20[aiStack_20[4] * 2] * 0x5b20 + aiStack_20[aiStack_20[4] * 2 + 1] * 0x120)
             = *(uint32_t *)(&g_CardSlot_Flags +
                        aiStack_20[aiStack_20[4] * 2] * 0x5b20 +
                        aiStack_20[aiStack_20[4] * 2 + 1] * 0x120) & 0xffcfffff;
      }
      Ai_EvaluateTacticalPosition(0,0x20);
      g_ActivePlayer = 1;
    }
    else {
      *(uint32_t *)(&g_CardSlot_Flags +
               aiStack_20[aiStack_20[5] * 2] * 0x5b20 + aiStack_20[aiStack_20[5] * 2 + 1] * 0x120) =
           *(uint32_t *)(&g_CardSlot_Flags +
                    aiStack_20[aiStack_20[5] * 2] * 0x5b20 +
                    aiStack_20[aiStack_20[5] * 2 + 1] * 0x120) | 0x300000;
      Ai_EvaluateTacticalPosition(0,0x20);
    }
    aiStack_20[5] = aiStack_20[5] + 1;
  }
  if (g_ActivePlayer == 1) {
    g_ActivePlayer = -1;
    u_temp = 0;
  }
  else {
    for (aiStack_20[5] = 0; aiStack_20[5] < 2; aiStack_20[5] = aiStack_20[5] + 1) {
      if (g_IsAiThinking != 1) {
        Duel_PlaySoundById(0xf);
      }
      Pic_Subsystem_0044867e(aiStack_20[aiStack_20[5] * 2],aiStack_20[aiStack_20[5] * 2 + 1],3);
    }
    u_temp = 1;
  }
  return u_temp;
}

/*
 * Card_Leviathan_SelectLand
 * Purpose: Handle individual land selection for Leviathan sacrifice.
 * Procedure:
 * 1. Move selected land to graveyard.
 */
/*
 * Decompiled function: Card_Leviathan_SelectLand
 * Entry Point: 004dee6b
 * Size: 343 bytes
 */

int Card_Leviathan_SelectLand(int player,int card_index,int event_code)

{
  int status;
  int slot_idx;
  
  if (((event_code == 2) && (card_index == g_EventSourceSlot)) && (player == g_EventSourcePlayer)) {
    g_CardEventResult = g_CardEventResult | 2;
  }
  if ((card_index == g_EventSourceSlot) && (player == g_EventSourcePlayer)) {
    status = CardQuery_PlayerControlsColor(player,1);
    if (status == 0) {
      Pic_Subsystem_0044867e(player,card_index,2);
    }
  }
  if ((((event_code == 4) && (card_index == g_EventSourceSlot)) && (player == g_EventSourcePlayer)) ||
     (event_code == 199)) {
    strcpy(&g_OverworldWorldState,s_Pick_a_land__0052ed24);
    do {
    } while (slot_idx == -1);
    if (slot_idx != -1) {
      if (((&g_CardSlot_PlusOneCounters)[slot_idx * 0x120 + player * 0x5b20] & 4) != 0) {
        Mem_AllocOrFree_0041df33(player,3,player,card_index);
      }
      Pic_Subsystem_0044867e(player,slot_idx,3);
    }
    status = CardQuery_PlayerControlsColor(player,1);
    if (status == 0) {
      Pic_Subsystem_0044867e(player,card_index,2);
    }
  }
  return 0;
}

/*
 * Card_Leviathan_AttackTrigger
 * Purpose: Require sacrifice of two Islands when Leviathan attacks.
 * Procedure:
 * 1. Process attack declaration land sacrifice.
 */
/*
 * Decompiled function: Card_Leviathan_AttackTrigger
 * Entry Point: 004defc2
 * Size: 136 bytes
 */

int Card_Leviathan_AttackTrigger(int player,int card_index,int event_code)

{
  if (((event_code == 2) && (card_index == g_EventSourceSlot)) && (player == g_EventSourcePlayer)) {
    g_CardEventResult = g_CardEventResult | 2;
  }
  if ((((event_code == 4) && (card_index == g_EventSourceSlot)) && (player == g_EventSourcePlayer)) ||
     (event_code == 199)) {
    Mem_AllocOrFree_0041df33(player,1,player,card_index);
  }
  return 0;
}

/*
 * Card_BrothersOfFire_Ping
 * Purpose: Activate Brothers of Fire ability (deal 1 damage to target and 1 to self).
 * Procedure:
 * 1. Validate target creature or player.
 * 2. Deal 1 damage to target.
 * 3. Deal 1 damage to Brothers of Fire controller.
 */
/*
 * Decompiled function: Card_BrothersOfFire_Ping
 * Entry Point: 004df04a
 * Size: 450 bytes
 */

int Card_BrothersOfFire_Ping(int player,int card_index,int event_code)

{
  int status;
  int u_temp;
  
  if (event_code == 0x73) {
    status = Font_DrawString(player,4,2);
    if ((status == 0) || (status = Font_DrawString(player,7,3), status == 0)) {
      u_temp = 0;
    }
    else {
      u_temp = 1;
    }
  }
  else if (event_code == 0x90) {
    Ai_GetOpponentPlayerScore(1);
    u_temp = 0;
  }
  else {
    if (event_code == 0x6d) {
      g_AiSelectedTargetCard = 1;
      Ai_CalcManaRequirement_004ba890(player,4,2);
      if (g_ActivePlayer != 1) {
        Pic_Subsystem_00424500(s_prompts_txt_0052ed48,s_BROTHERS_OF_FIRE_0052ed34);
      }
      Card_DirectDamage_EvaluateBestTarget(player,card_index);
    }
    if (event_code == 0x72) {
      status = Card_DirectDamage_PromptAndDealDamage(player,card_index,0x72,1);
      if (status != 0) {
        *(uint32_t *)(&g_CardSlot_Flags +
                 *(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20 +
                 *(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120
                 ) = *(uint32_t *)(&g_CardSlot_Flags +
                              *(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20)
                              * 0x5b20 +
                              *(int *)(&g_CardSlot_SicknessState +
                                      card_index * 0x120 + player * 0x5b20) * 0x120) & 0xffffffef;
        Mem_AllocOrFree_0041df33(player,1,g_DialogPromptHwnd,g_DuelArenaHwnd);
      }
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120] = 0;
    }
    u_temp = 0;
  }
  return u_temp;
}

/*
 * Card_BrothersOfFire_EvaluateTarget
 * Purpose: Calculate AI tactical score for Brothers of Fire activation.
 * Procedure:
 * 1. Evaluate board advantage of pinging target.
 */
/*
 * Decompiled function: Card_BrothersOfFire_EvaluateTarget
 * Entry Point: 004df20c
 * Size: 264 bytes
 */

bool Card_BrothersOfFire_EvaluateTarget(int player,int card_index,int event_code)

{
  bool is_valid;
  
  if (event_code == 0x73) {
    is_valid = (*(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) & 0x20010) == 0;
  }
  else if (event_code == 0x90) {
    Ai_GetOpponentPlayerScore(1);
    is_valid = false;
  }
  else {
    if (event_code == 0x6d) {
      Card_DirectDamage_EvaluateBestTarget(player,card_index);
    }
    if (event_code == 0x72) {
      Card_DirectDamage_PromptAndDealDamage(player,card_index,0x72,1);
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120] = 0;
    }
    is_valid = false;
  }
  return is_valid;
}

/*
 * Card_CrimsonManticore_DamageTarget
 * Purpose: Activate Crimson Manticore ability (deal 1 damage to attacking/blocking creature).
 * Procedure:
 * 1. Validate target combat creature.
 * 2. Deal 1 damage to target.
 */
/*
 * Decompiled function: Card_CrimsonManticore_DamageTarget
 * Entry Point: 004df314
 * Size: 868 bytes
 */

int Card_CrimsonManticore_DamageTarget(int player,int card_index,int event_code)

{
  int status;
  int u_temp;
  uint32_t uval_3;
  bool bVar4;
  uint32_t uval_5;
  uint32_t uval_6;
  int arg_11;
  int val_7;
  int arg_12;
  uint32_t uval_8;
  int arg_13;
  uint32_t uVar9;
  int arg_14;
  uint32_t uVar10;
  int arg_15;
  uint32_t uVar11;
  int arg_16;
  uint32_t uVar12;
  int arg_17;
  uint8_t *arg_18;
  int arg_18_00;
  int arg_19;
  int *arg_20;
  int match_count;
  int slot_idx;
  
  if (event_code == 0x73) {
    bVar4 = (*(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) & 0x20010) == 0;
    if ((bVar4) && (status = Font_DrawString(player,4,1), status == 0)) {
      bVar4 = false;
    }
    u_temp = 0;
    if (bVar4) {
      arg_19 = 0;
      arg_18_00 = 0x20;
      arg_17 = 0;
      arg_16 = 0xffffffff;
      arg_15 = 0xffffffff;
      arg_14 = 0xffffffff;
      arg_13 = 0xffffffff;
      arg_12 = 0;
      arg_11 = 0;
      u_temp = Card_GetColorAndTypeFlags(player,card_index);
      u_temp = UI_PaintBigCardInfo((int *)0x0,0,player,2,2,0x200,2,0,0,u_temp,arg_11,arg_12,arg_13,arg_14,
                           arg_15,arg_16,arg_17,arg_18_00,arg_19);
    }
  }
  else if (event_code == 0x90) {
    Ai_GetOpponentPlayerScore(0);
    u_temp = 0;
  }
  else {
    if (((event_code == 0x6d) &&
        ((*(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) & 0x20010) == 0)) &&
       (Ai_CalcManaRequirement_004ba890(player,4,1), g_ActivePlayer != 1)) {
      Pic_Subsystem_00424500(s_prompts_txt_0052ed68,s_CRIMSON_MANTICORE_0052ed54);
      arg_20 = &match_count;
      u_temp = 1;
      arg_18 = &g_OverworldGoldAmount;
      uVar12 = 0;
      uVar11 = 0x20;
      uVar10 = 0;
      uVar9 = 0xffffffff;
      uval_8 = 0xffffffff;
      val_7 = -1;
      status = -1;
      uval_6 = 0;
      uval_5 = 0;
      uval_3 = Card_GetColorAndTypeFlags(player,card_index);
      status = Duel_ChooseTarget
                        (player,2,1 - player,0x200,2,0,0,uval_3,uval_5,uval_6,status,val_7,uval_8,
                         uVar9,uVar10,uVar11,uVar12,arg_18,u_temp,arg_20);
      if (status == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + card_index * 0x120 + player * 0x5b20) = match_count;
        *(int *)(&g_CardSlot_AttachedAura + card_index * 0x120 + player * 0x5b20) = slot_idx;
        (&g_CardSlot_TurnPlayed)[card_index * 0x120 + player * 0x5b20] = 1;
        *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) | 0x10;
      }
    }
    if (event_code == 0x72) {
      match_count = *(int *)(&g_CardSlot_CombatTarget + card_index * 0x120 + player * 0x5b20);
      slot_idx = *(int *)(&g_CardSlot_AttachedAura + card_index * 0x120 + player * 0x5b20);
      uVar12 = 0;
      uVar11 = 0x20;
      uVar10 = 0;
      uVar9 = 0xffffffff;
      uval_8 = 0xffffffff;
      val_7 = -1;
      status = -1;
      uval_6 = 0;
      uval_5 = 0;
      uval_3 = Card_GetColorAndTypeFlags(player,card_index);
      status = Rules_ParseFilter_0040360b
                        (match_count,slot_idx,(char *)0x0,player,2,2,0x200,2,0,0,uval_3,uval_5,uval_6,
                         status,val_7,uval_8,uVar9,uVar10,uVar11,uVar12);
      if (status == 0) {
        g_ActivePlayer = 1;
      }
      else {
        Card_ApplyCombatDamage(match_count,slot_idx,1,g_DialogPromptHwnd,g_DuelArenaHwnd);
      }
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120] = 0;
    }
    u_temp = 0;
  }
  return u_temp;
}

/*
 * Card_ProdigalSorcerer_PingTarget
 * Purpose: Activate Prodigal Sorcerer ability (deal 1 damage to target).
 * Procedure:
 * 1. Validate target creature or player.
 * 2. Deal 1 damage to target.
 */
/*
 * Decompiled function: Card_ProdigalSorcerer_PingTarget
 * Entry Point: 004df678
 * Size: 578 bytes
 */

bool Card_ProdigalSorcerer_PingTarget(int player,int card_index,int event_code)

{
  bool is_valid;
  
  if (event_code == 0x73) {
    is_valid = (*(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) & 0x20010) == 0;
  }
  else if (event_code == 0x90) {
    Ai_GetOpponentPlayerScore(1);
    is_valid = false;
  }
  else {
    if (event_code == 0x6d) {
      Pic_Subsystem_00424500(s_prompts_txt_0052ed88,s_PRODIGAL_SORCERER_0052ed74);
      Card_DirectDamage_EvaluateBestTarget(player,card_index);
      if (g_ActivePlayer != 1) {
        *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) | 0x10;
      }
    }
    if (event_code == 0x72) {
      Card_DirectDamage_PromptAndDealDamage(player,card_index,0x72,1);
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120 +
       *(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20] = 0;
    }
    if ((event_code == 0x3b) &&
       ((*(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) & 0x20014) == 0)) {
      *(int *)(&DAT_00695eb8 + (1 - player) * 4) =
           *(int *)(&DAT_00695eb8 + (1 - player) * 4) + -1;
    }
    if ((((event_code == 199) && (player == g_TurnPlayer)) && (player == g_ActivePlayerPriority)
        ) && ((*(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) & 0x20010) == 0)
       ) {
      g_SpellStackDepth = g_SpellStackDepth + 0x18;
    }
    if (((event_code == 0x8a) && (card_index == g_EventSourceSlot)) &&
       (player == g_EventSourcePlayer)) {
      g_AiBlockingCreatureCount = g_AiBlockingCreatureCount + 0x30;
    }
    if (((event_code == 0x8b) && (card_index == g_EventSourceSlot)) &&
       (player == g_EventSourcePlayer)) {
      g_AiBlockingCreatureCount = g_AiBlockingCreatureCount + -0x30;
    }
    is_valid = false;
  }
  return is_valid;
}

/*
 * Card_DirectDamage_EvaluateBestTarget
 * Purpose: AI heuristic to find highest priority direct damage target.
 * Procedure:
 * 1. Iterate enemy creatures and player.
 * 2. Return highest tactical value target.
 */
/*
 * Decompiled function: Card_DirectDamage_EvaluateBestTarget
 * Entry Point: 004df8ba
 * Size: 612 bytes
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool Card_DirectDamage_EvaluateBestTarget(int player,int card_index)

{
  uint32_t u_res;
  bool is_match;
  uint32_t uval_3;
  uint32_t uval_4;
  int val_5;
  int val_6;
  uint32_t uval_7;
  uint32_t uval_8;
  uint32_t uVar9;
  uint32_t uVar10;
  uint32_t uVar11;
  uint8_t *puVar12;
  int uVar13;
  int *piVar14;
  int player_idx;
  int card_idx;
  int match_count;
  int slot_idx;
  
  slot_idx = 0;
  if (player == g_CurrentTurnPhase) {
    if (g_IsAiThinking == 1) {
      player_idx = 0xffffffff;
      g_TemporaryToughnessBuffer = 1 - player;
    }
    else {
      piVar14 = &card_idx;
      uVar13 = 1;
      puVar12 = &g_OverworldGoldAmount;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      val_6 = -1;
      val_5 = -1;
      uval_4 = 0;
      uval_3 = 0;
      u_res = Card_GetColorAndTypeFlags(player,card_index);
      val_5 = Duel_ChooseTarget
                        (player,2,1 - player,0x1200,2,0,0,u_res,uval_3,uval_4,val_5,val_6,uval_7,uval_8,
                         uVar9,uVar10,uVar11,puVar12,uVar13,piVar14);
      if (val_5 == 0) {
        g_ActivePlayer = 1;
        player_idx = 0xffffffff;
        g_TemporaryToughnessBuffer = -1;
      }
      else {
        player_idx = match_count;
        g_TemporaryToughnessBuffer = card_idx;
      }
    }
  }
  else {
    if (g_IsAiThinking == 1) {
      val_5 = Util_GetRandomNumber(3);
      g_AiChoiceValue = (uint32_t)(val_5 == 0);
      Ai_RecordChoice();
    }
    else {
      Ai_ReplayChoice();
    }
    if (g_AiChoiceValue == 0) {
      piVar14 = &card_idx;
      uVar13 = 1;
      puVar12 = &g_OverworldGoldAmount;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      val_6 = -1;
      val_5 = -1;
      uval_4 = 0;
      uval_3 = 0;
      u_res = Card_GetColorAndTypeFlags(player,card_index);
      Duel_ChooseTarget
                (player,2,1 - player,0x1200,2,0,0,u_res,uval_3,uval_4,val_5,val_6,uval_7,uval_8,uVar9,uVar10
                 ,uVar11,puVar12,uVar13,piVar14);
      player_idx = match_count;
      g_TemporaryToughnessBuffer = card_idx;
    }
    else {
      player_idx = 0xffffffff;
      g_TemporaryToughnessBuffer = 1 - player;
      if (g_IsAiThinking == 1) {
        g_AiChoiceValue = 0;
        g_AiCurrentSearchPath = CONCAT31((uint3)((g_TemporaryToughnessBuffer == 0) - 1 >> 8) & 1,0xff);
        Ai_RecordChoice();
      }
      else {
        Ai_ReplayChoice();
      }
    }
  }
  is_match = g_ActivePlayer != 1;
  if (is_match) {
    *(int *)(&g_CardSlot_AttachedAura + card_index * 0x120 + player * 0x5b20) = player_idx;
    *(int *)(&g_CardSlot_CombatTarget + card_index * 0x120 + player * 0x5b20) = g_TemporaryToughnessBuffer;
    (&g_CardSlot_TurnPlayed)[card_index * 0x120 + player * 0x5b20] = 1;
  }
  return is_match;
}

/*
 * Card_DirectDamage_PromptAndDealDamage
 * Purpose: Prompt player for direct damage target and execute damage.
 * Procedure:
 * 1. Display target selector.
 * 2. Apply damage to chosen target.
 */
/*
 * Decompiled function: Card_DirectDamage_PromptAndDealDamage
 * Entry Point: 004dfb23
 * Size: 529 bytes
 */

int Card_DirectDamage_PromptAndDealDamage(int x,int y,int width,int height)

{
  int u_res;
  uint32_t arg_11;
  uint32_t arg_12;
  uint32_t arg_13;
  int val_result;
  int arg_15;
  uint32_t arg_16;
  uint32_t arg_17;
  uint32_t arg_18;
  uint32_t arg_19;
  uint32_t arg_20;
  int match_count;
  int slot_idx;
  
  if ((&g_CardSlot_TurnPlayed)[y * 0x120 + x * 0x5b20] == '\0') {
    u_res = 0;
  }
  else {
    if (width == 0x72) {
      match_count = g_DialogPromptHwnd;
      slot_idx = g_DuelArenaHwnd;
    }
    else {
      match_count = x;
      slot_idx = y;
    }
    if ((*(int *)(&g_CardSlot_CombatTarget + y * 0x120 + x * 0x5b20) == -1) &&
       (*(int *)(&g_CardSlot_AttachedAura + y * 0x120 + x * 0x5b20) == -1)) {
      u_res = 0;
    }
    else {
      arg_20 = 0;
      arg_19 = 0;
      arg_18 = 0;
      arg_17 = 0xffffffff;
      arg_16 = 0xffffffff;
      arg_15 = -1;
      val_result = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = Card_GetColorAndTypeFlags(x,y);
      val_result = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + y * 0x120 + x * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + y * 0x120 + x * 0x5b20),(char *)0x0,x,2
                         ,2,0x1200,2,0,0,arg_11,arg_12,arg_13,val_result,arg_15,arg_16,arg_17,arg_18,
                         arg_19,arg_20);
      if (val_result == 0) {
        g_ActivePlayer = 1;
        u_res = 0;
      }
      else {
        if (*(int *)(&g_CardSlot_AttachedAura + y * 0x120 + x * 0x5b20) == -1) {
          Mem_AllocOrFree_0041df33
                    (*(int *)(&g_CardSlot_CombatTarget + y * 0x120 + x * 0x5b20),height,match_count,
                     slot_idx);
        }
        else {
          Card_ApplyCombatDamage(*(int *)(&g_CardSlot_CombatTarget + y * 0x120 + x * 0x5b20),
                       *(int *)(&g_CardSlot_AttachedAura + y * 0x120 + x * 0x5b20),height,match_count,
                       slot_idx);
        }
        u_res = 1;
      }
    }
  }
  return u_res;
}

/*
 * Card_PirateShip_PingTarget
 * Purpose: Activate Pirate Ship ability (deal 1 damage to target).
 * Procedure:
 * 1. Verify Pirate Ship is not summoning sick.
 * 2. Deal 1 damage to target creature or player.
 */
/*
 * Decompiled function: Card_PirateShip_PingTarget
 * Entry Point: 004dfd39
 * Size: 347 bytes
 */

bool Card_PirateShip_PingTarget(int player,int card_index,int event_code)

{
  bool is_valid;
  
  if (event_code == 0x73) {
    is_valid = (*(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) & 0x20010) == 0;
  }
  else if (event_code == 0x90) {
    Ai_GetOpponentPlayerScore(1);
    is_valid = false;
  }
  else {
    if (event_code == 0x6d) {
      Pic_Subsystem_00424500(s_prompts_txt_0052eda0,s_PIRATE_SHIP_0052ed94);
      Card_DirectDamage_EvaluateBestTarget(player,card_index);
      if (g_ActivePlayer != 1) {
        *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) | 0x10;
      }
    }
    if (event_code == 0x72) {
      Card_DirectDamage_PromptAndDealDamage(player,card_index,0x72,1);
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120 +
       *(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20] = 0;
    }
    Card_PirateShip_HasIsland(player,card_index,event_code);
    is_valid = false;
  }
  return is_valid;
}

/*
 * Card_PirateShip_CheckIslandwalk
 * Purpose: Check if Pirate Ship can attack defending player.
 * Procedure:
 * 1. Verify defending player controls an Island.
 */
/*
 * Decompiled function: Card_PirateShip_CheckIslandwalk
 * Entry Point: 004dfe94
 * Size: 244 bytes
 */

int Card_PirateShip_CheckIslandwalk(int player,int card_index,int event_code)

{
  bool is_valid;
  int player;
  int val_result;
  int slot_idx;
  
  if ((event_code == 0x1a) && (((&g_CardSlot_Flags)[card_index * 0x120 + player * 0x5b20] & 4) != 0)) {
    is_valid = true;
    player = 1 - player;
    for (slot_idx = 0; slot_idx < (int)(&g_PlayerActiveCardCount)[player]; slot_idx = slot_idx + 1) {
      val_result = Card_IsTapped(player,slot_idx);
      if ((val_result != 0) && ((char)(&g_CardSlot_ColorMask)[slot_idx * 0x120 + player * 0x5b20] == card_index))
      {
        is_valid = false;
        break;
      }
    }
    if (is_valid) {
      (&g_PlayerCreatureCount)[player] = (&g_PlayerCreatureCount)[player] + 2;
    }
  }
  Card_PirateShip_HasIsland(player,card_index,event_code);
  return 0;
}

/*
 * Card_PirateShip_HasIsland
 * Purpose: Check if controller controls an Island for Pirate Ship survival.
 * Procedure:
 * 1. Query controller lands for Islands.
 */
/*
 * Decompiled function: Card_PirateShip_HasIsland
 * Entry Point: 004dff88
 * Size: 175 bytes
 */

int Card_PirateShip_HasIsland(int player,int card_index,int event_code)

{
  int status;
  
  if (((&g_CardSlot_Flags)[card_index * 0x120 + player * 0x5b20] & 2) != 0) {
    status = Card_UntapCard(player,card_index,2);
    if (*(int *)(&g_AiCombatScore_Attacker + status * 4 + player * 0x20) == 0) {
      Pic_Subsystem_0044867e(player,card_index,2);
    }
  }
  if (event_code == 0x79) {
    status = Card_UntapCard(player,card_index,2);
    if (*(int *)(&g_AiCombatScore_Attacker + status * 4 + (1 - player) * 0x20) == 0) {
      g_CardEventResult = 1;
    }
  }
  return 0;
}

/*
 * Card_PirateShip_AttackTrigger
 * Purpose: Destroy Pirate Ship if controller controls no Islands.
 * Procedure:
 * 1. Destroy card if no Island is in play.
 */
/*
 * Decompiled function: Card_PirateShip_AttackTrigger
 * Entry Point: 004e0037
 * Size: 176 bytes
 */

int Card_PirateShip_AttackTrigger(int player,int card_index,int event_code)

{
  if (((event_code == 0x1a) && (player != g_TurnPlayer)) &&
     ((&g_CardSlot_ColorMask)[card_index * 0x120 + player * 0x5b20] != -1)) {
    *(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) = 1;
  }
  if ((event_code == 0x79) &&
     (*(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) == 0)) {
    g_CardEventResult = 1;
  }
  return 0;
}

/*
 * Card_IslandFishJasconius_PayToUntap
 * Purpose: Process Island Fish Jasconius upkeep (pay UUU to untap).
 * Procedure:
 * 1. Prompt player to pay UUU.
 * 2. Untap creature if paid.
 */
/*
 * Decompiled function: Card_IslandFishJasconius_PayToUntap
 * Entry Point: 004e00e7
 * Size: 718 bytes
 */

int Card_IslandFishJasconius_PayToUntap(int player,int card_index,int event_code)

{
  int status;
  
  if (((((event_code == 0x84) && (card_index == g_EventSourceSlot)) && (player == g_EventSourcePlayer)) &&
      ((((&g_CardSlot_Flags)[player * 0x5b20 + card_index * 0x120] & 0x10) != 0 &&
       (player == g_TurnPlayer)))) && (player == g_CurrentTurnTargetPlayer)) {
    *(uint32_t *)(&g_CardSlot_SpecialState + player * 0x5b20 + card_index * 0x120) =
         *(uint32_t *)(&g_CardSlot_SpecialState + player * 0x5b20 + card_index * 0x120) | 0x10;
    (&DAT_006a603e)[player * 0x5b20 + card_index * 0x120] =
         (&DAT_006a603e)[player * 0x5b20 + card_index * 0x120] + '\x03';
  }
  if (event_code == 1) {
    *(int *)(&DAT_006ff698 + player * 0x20) = *(int *)(&DAT_006ff698 + player * 0x20) + 1;
  }
  Card_PirateShip_HasIsland(player,card_index,event_code);
  if (((event_code == 0x82) && (card_index == g_EventSourceSlot)) && (player == g_EventSourcePlayer)) {
    *(uint32_t *)(&g_CardSlot_ProtectionFlags + player * 0x5b20 + card_index * 0x120) =
         *(uint32_t *)(&g_CardSlot_ProtectionFlags + player * 0x5b20 + card_index * 0x120) & 0xfffffffc;
  }
  if (((event_code == 0x6c) && (card_index == g_EventSourceSlot)) && (player == g_EventSourcePlayer)) {
    (&DAT_006a603e)[player * 0x5b20 + card_index * 0x120] =
         (&DAT_006a603e)[player * 0x5b20 + card_index * 0x120] + '\x03';
  }
  if ((((g_CurrentStepCode == 0xca) && (player == g_TurnPlayer)) &&
      ((card_index == g_EventSourceSlot &&
       ((player == g_EventSourcePlayer && (player == g_CurrentCardColorTarget)))))) &&
     (((&g_CardSlot_Flags)[player * 0x5b20 + card_index * 0x120] & 0x10) != 0)) {
    status = Font_DrawString(player,2,3);
    if (status != 0) {
      if (event_code == 0x7d) {
        g_CardEventResult = g_CardEventResult | 1;
      }
      if (event_code == 0x7e) {
        status = Ai_Subsystem_004cc56d
                          (player,player,card_index,-1,-1,s_Untap_Island_Fish__Don_t_untap__0052edac,0);
        if (status == 0) {
          Ai_CalcManaRequirement_004ba890(player,2,3);
          if (g_ActivePlayer == 1) {
            g_ActivePlayer = -1;
          }
          else {
            *(uint32_t *)(&g_CardSlot_Flags + player * 0x5b20 + card_index * 0x120) =
                 *(uint32_t *)(&g_CardSlot_Flags + player * 0x5b20 + card_index * 0x120) & 0xffffffef;
          }
        }
      }
    }
  }
  return 0;
}

/*
 * Card_IslandFishJasconius_CheckIslands
 * Purpose: Check if defending player controls an Island for attack eligibility.
 * Procedure:
 * 1. Verify defender Island presence.
 */
/*
 * Decompiled function: Card_IslandFishJasconius_CheckIslands
 * Entry Point: 004e03b5
 * Size: 265 bytes
 */

int Card_IslandFishJasconius_CheckIslands(int player,int card_index,int event_code)

{
  char c_res;
  int val_result;
  
  val_result = Card_IsTapped(g_EventSourcePlayer,g_EventSourceSlot);
  if ((val_result != 0) &&
     ((&g_MasterCardRarityTable)
      [*(int *)(&g_CardSlot_CardId + g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20)
       * 0x34] == '\x01')) {
    if (event_code == 0x34) {
      c_res = Card_UntapCard(player,card_index,2);
      g_CardEventResult = g_CardEventResult | 1 << (c_res - 1U & 0x1f);
    }
    if ((event_code == 0x32) || (event_code == 0x33)) {
      g_CardEventResult = g_CardEventResult + 1;
    }
    if ((event_code == 0x77) && (((&g_CardSlot_Abilities1)[card_index * 0x120 + player * 0x5b20] & 0x80) != 0))
    {
      *(uint32_t *)(&g_CardSlot_Abilities2 +
               g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_Abilities2 +
                    g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20) | 0xe000000;
    }
  }
  return 0;
}

/*
 * Card_IslandFishJasconius_DestroyIfNoIslands
 * Purpose: Destroy Island Fish Jasconius if controller has no Islands.
 * Procedure:
 * 1. Destroy card if no Island remains.
 */
/*
 * Decompiled function: Card_IslandFishJasconius_DestroyIfNoIslands
 * Entry Point: 004e04be
 * Size: 194 bytes
 */

int Card_IslandFishJasconius_DestroyIfNoIslands(int player,int card_index,int event_code)

{
  int status;
  
  if (event_code == 0x79) {
    status = Card_UntapCard(player, card_index, 4);
    if (*(int *)(&g_AiCombatScore_Attacker + status * 4 + (1 - player) * 0x20) == 0) {
      g_CardEventResult = 1;
    }
  }
  if ((event_code == 0x1a) && (((&g_CardSlot_Flags)[card_index * 0x120 + player * 0x5b20] & 4) != 0)) {
    Card_ApplyTriggerEffect(player,card_index,DAT_00695df4,player,card_index);
    *(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) = 1;
  }
  return 0;
}

/*
 * Card_RodOfRuin_Ping
 * Purpose: Activate Rod of Ruin ability (pay 3, tap: deal 1 damage).
 * Procedure:
 * 1. Pay 3 mana cost.
 * 2. Deal 1 damage to target creature or player.
 */
/*
 * Decompiled function: Card_RodOfRuin_Ping
 * Entry Point: 004e0580
 * Size: 565 bytes
 */

uint32_t Card_RodOfRuin_Ping(int player,int card_index,int event_code)

{
  uint32_t u_res;
  int val_result;
  
  if (event_code == 0x73) {
    u_res = (&g_PlayerPoisonCounters)[player] & 0x40;
  }
  else if (event_code == 0x90) {
    Ai_GetOpponentPlayerScore(0);
    u_res = 0;
  }
  else {
    if (event_code == 0x6d) {
      val_result = CardTarget_HasValidPlayerOrCreatureTarget(player);
      if (val_result != 0) {
        *(short *)(&g_CardSlot_PowerCounters + card_index * 0x120 + player * 0x5b20) =
             *(short *)(&g_CardSlot_PowerCounters + card_index * 0x120 + player * 0x5b20) + 2;
        *(short *)(&g_CardSlot_ToughnessCounters + card_index * 0x120 + player * 0x5b20) =
             *(short *)(&g_CardSlot_ToughnessCounters + card_index * 0x120 + player * 0x5b20) + 2;
        *(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) =
             *(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) + 1;
      }
    }
    if (((event_code == 0x22) || (event_code == 199)) &&
       (*(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) != 0)) {
      *(short *)(&g_CardSlot_PowerCounters + card_index * 0x120 + player * 0x5b20) =
           *(short *)(&g_CardSlot_PowerCounters + card_index * 0x120 + player * 0x5b20) +
           (short)*(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) *
           -2;
      *(short *)(&g_CardSlot_ToughnessCounters + card_index * 0x120 + player * 0x5b20) =
           *(short *)(&g_CardSlot_ToughnessCounters + card_index * 0x120 + player * 0x5b20) +
           (short)*(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) *
           -2;
      *(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) = 0;
    }
    u_res = 0;
  }
  return u_res;
}

/*
 * Card_RodOfRuin_EvaluateAi
 * Purpose: Calculate AI tactical score for Rod of Ruin activation.
 * Procedure:
 * 1. Evaluate target advantage.
 */
/*
 * Decompiled function: Card_RodOfRuin_EvaluateAi
 * Entry Point: 004e07b5
 * Size: 247 bytes
 */

int Card_RodOfRuin_EvaluateAi(int player,int card_index,int event_code)

{
  int u_res;
  int val_result;
  int slot_idx;
  
  if (event_code == 0x73) {
    if (((*(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) & 0x20010) == 0) &&
       ((*(uint8_t *)(&g_PlayerPoisonCounters + player) & 0x40) != 0)) {
      u_res = 1;
    }
    else {
      u_res = 0;
    }
  }
  else if (event_code == 0x90) {
    Ai_GetOpponentPlayerScore(0);
    u_res = 0;
  }
  else {
    if (event_code == 0x6d) {
      val_result = CardTarget_HasValidPlayerOrCreatureTarget(player);
      if (val_result == 0) {
        g_ActivePlayer = 1;
      }
      else {
        FUN_0040d875(player,1,(int)(char)(&g_MasterCardManaCostTable)[slot_idx * 0x34]);
      }
      *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) | 0x10;
    }
    u_res = 0;
  }
  return u_res;
}

/*
 * Card_RodOfRuin_PayActivation
 * Purpose: Deduct mana cost for Rod of Ruin activation.
 * Procedure:
 * 1. Deduct 3 mana from pool.
 */
/*
 * Decompiled function: Card_RodOfRuin_PayActivation
 * Entry Point: 004e08ac
 * Size: 175 bytes
 */

int Card_RodOfRuin_PayActivation(int player,int card_index,int event_code)

{
  int status;
  
  if (((event_code == 2) && (card_index == g_EventSourceSlot)) && (player == g_EventSourcePlayer)) {
    g_CardEventResult = g_CardEventResult | 2;
  }
  if (((event_code == 4) && (card_index == g_EventSourceSlot)) && (player == g_EventSourcePlayer)) {
    status = CardTarget_HasValidPlayerOrCreatureTarget(player);
    if (status == 0) {
      *(uint32_t *)(&g_CardSlot_Flags + player * 0x5b20 + card_index * 0x120) =
           *(uint32_t *)(&g_CardSlot_Flags + player * 0x5b20 + card_index * 0x120) | 0x10;
      Mem_AllocOrFree_0041df33(player,2,player,card_index);
    }
  }
  return 0;
}

/*
 * Card_RodOfRuin_SelectTarget
 * Purpose: Select target for Rod of Ruin direct damage.
 * Procedure:
 * 1. Display target selector.
 */
/*
 * Decompiled function: Card_RodOfRuin_SelectTarget
 * Entry Point: 004e095b
 * Size: 348 bytes
 */

int Card_RodOfRuin_SelectTarget(int player,int card_index,int event_code)

{
  int u_res;
  int val_result;
  
  if (event_code == 0x73) {
    if (((*(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) & 0x20010) == 0) &&
       ((*(uint8_t *)(&g_PlayerPoisonCounters + player) & 0x40) != 0)) {
      u_res = 1;
    }
    else {
      u_res = 0;
    }
  }
  else if (event_code == 0x90) {
    Ai_GetOpponentPlayerScore(1);
    u_res = 0;
  }
  else {
    if (event_code == 0x6d) {
      val_result = CardTarget_HasValidPlayerOrCreatureTarget(player);
      if (val_result == 0) {
        g_ActivePlayer = 1;
      }
      else {
        Card_DirectDamage_EvaluateBestTarget(player,card_index);
      }
      *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) | 0x10;
    }
    if (event_code == 0x72) {
      Card_DirectDamage_PromptAndDealDamage(player,card_index,0x72,2);
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120] = 0;
    }
    u_res = 0;
  }
  return u_res;
}

/*
 * Card_OrcishArtillery_ShootTarget
 * Purpose: Activate Orcish Artillery ability (deal 2 damage to target, 3 to controller).
 * Procedure:
 * 1. Validate target.
 * 2. Deal 2 damage to target.
 * 3. Deal 3 damage to Orcish Artillery controller.
 */
/*
 * Decompiled function: Card_OrcishArtillery_ShootTarget
 * Entry Point: 004e0ab7
 * Size: 357 bytes
 */

bool Card_OrcishArtillery_ShootTarget(int player,int card_index,int event_code)

{
  int status;
  bool is_match;
  
  if (event_code == 0x73) {
    is_match = (*(uint32_t *)(&g_CardSlot_Flags + player * 0x5b20 + card_index * 0x120) & 0x20010) == 0;
  }
  else if (event_code == 0x90) {
    Ai_GetOpponentPlayerScore(1);
    is_match = false;
  }
  else {
    if (event_code == 0x6d) {
      Pic_Subsystem_00424500(s_prompts_txt_0052ede4,s_ORCISH_ARTILLERY_0052edd0);
      Card_DirectDamage_EvaluateBestTarget(player,card_index);
      if (g_ActivePlayer != 1) {
        *(uint32_t *)(&g_CardSlot_Flags + player * 0x5b20 + card_index * 0x120) =
             *(uint32_t *)(&g_CardSlot_Flags + player * 0x5b20 + card_index * 0x120) | 0x10;
      }
    }
    if (event_code == 0x72) {
      status = Card_DirectDamage_PromptAndDealDamage(player,card_index,0x72,2);
      if (status != 0) {
        Mem_AllocOrFree_0041df33(player,3,player,card_index);
      }
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_TapState + player * 0x5b20 + card_index * 0x120) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + player * 0x5b20 + card_index * 0x120) * 0x120] = 0;
    }
    is_match = false;
  }
  return is_match;
}

/*
 * Card_PsionicEntity_ShootTarget
 * Purpose: Activate Psionic Entity ability (deal 2 damage to target, 3 to self).
 * Procedure:
 * 1. Validate target.
 * 2. Deal 2 damage to target.
 * 3. Deal 3 damage to Psionic Entity.
 */
/*
 * Decompiled function: Card_PsionicEntity_ShootTarget
 * Entry Point: 004e0c1c
 * Size: 580 bytes
 */

bool Card_PsionicEntity_ShootTarget(int player,int card_index,int event_code)

{
  int status;
  bool is_match;
  
  if (((event_code == 199) && (status = Card_IsTapped(player,card_index), status != 0)) &&
     (3 < *(short *)(&DAT_006a5f46 + card_index * 0x120 + player * 0x5b20))) {
    if (player == g_ActivePlayerPriority) {
      g_SpellStackDepth = g_SpellStackDepth + 200;
    }
    else {
      g_SpellStackDepth = g_SpellStackDepth + -200;
    }
  }
  if (event_code == 0x73) {
    is_match = (*(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) & 0x20010) == 0;
  }
  else if (event_code == 0x90) {
    Ai_GetOpponentPlayerScore(1);
    is_match = false;
  }
  else {
    if (event_code == 0x6d) {
      Pic_Subsystem_00424500(s_prompts_txt_0052ee00,s_PSIONIC_ENTITY_0052edf0);
      Card_DirectDamage_EvaluateBestTarget(player,card_index);
      if (g_ActivePlayer != 1) {
        *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) | 0x10;
      }
    }
    if (event_code == 0x72) {
      status = Card_DirectDamage_PromptAndDealDamage(player,card_index,0x72,2);
      if ((status != 0) &&
         (*(int *)(&g_CardSlot_CardId +
                  *(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20 +
                  *(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) *
                  0x120) != -1)) {
        Card_ApplyCombatDamage(g_DialogPromptHwnd,g_DuelArenaHwnd,3,g_DialogPromptHwnd,g_DuelArenaHwnd);
      }
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120] = 0;
    }
    is_match = false;
  }
  return is_match;
}

/*
 * Card_PsionicEntity_EvaluateTarget
 * Purpose: Calculate AI tactical score for Psionic Entity activation.
 * Procedure:
 * 1. Evaluate target advantage versus self-damage.
 */
/*
 * Decompiled function: Card_PsionicEntity_EvaluateTarget
 * Entry Point: 004e0e60
 * Size: 368 bytes
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int Card_PsionicEntity_EvaluateTarget(int player,int card_index,int event_code)

{
  int status;
  int u_temp;
  int slot_idx;
  
  if (event_code == 0x73) {
    if (((*(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) & 0x20010) == 0) &&
       (status = CardQuery_PlayerControlsColor(player,0x40), status != 0)) {
      u_temp = 1;
    }
    else {
      u_temp = 0;
    }
  }
  else if (event_code == 0x90) {
    Ai_GetOpponentPlayerScore(0);
    u_temp = 0;
  }
  else {
    if (event_code == 0x6d) {
      status = CardTarget_HasValidPlayerOrCreatureTarget(player);
      if (status != 0) {
        if (slot_idx == -1) {
          g_ActivePlayer = 1;
        }
        else {
          *(short *)(&g_CardSlot_PowerCounters + slot_idx * 0x120 + g_TemporaryToughnessBuffer * 0x5b20) =
               *(short *)(&g_CardSlot_PowerCounters + slot_idx * 0x120 + g_TemporaryToughnessBuffer * 0x5b20) + 1;
          *(short *)(&g_CardSlot_ToughnessCounters + slot_idx * 0x120 + g_TemporaryToughnessBuffer * 0x5b20) =
               *(short *)(&g_CardSlot_ToughnessCounters + slot_idx * 0x120 + g_TemporaryToughnessBuffer * 0x5b20) + 1;
        }
      }
      *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) | 0x10;
    }
    u_temp = 0;
  }
  return u_temp;
}

/*
 * Card_PsionicEntity_SelfDamage
 * Purpose: Apply self-inflicted damage from Psionic Entity activation.
 * Procedure:
 * 1. Deal 3 damage to Psionic Entity creature slot.
 */
/*
 * Decompiled function: Card_PsionicEntity_SelfDamage
 * Entry Point: 004e0fd0
 * Size: 382 bytes
 */

int Card_PsionicEntity_SelfDamage(int player,int card_index,int event_code)

{
  if (((event_code == 0x77) &&
      (((&g_MasterCardColorTable)
        [*(int *)(&g_CardSlot_CardId + g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20
                 ) * 0x34] & 2) != 0)) && (g_CardEventResult < 1)) {
    *(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) =
         *(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) + 1;
  }
  if ((event_code == 0x22) || (event_code == 199)) {
    *(short *)(&g_CardSlot_PowerCounters + card_index * 0x120 + player * 0x5b20) =
         *(short *)(&g_CardSlot_PowerCounters + card_index * 0x120 + player * 0x5b20) +
         (short)*(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20);
    *(short *)(&g_CardSlot_ToughnessCounters + card_index * 0x120 + player * 0x5b20) =
         *(short *)(&g_CardSlot_ToughnessCounters + card_index * 0x120 + player * 0x5b20) +
         (short)*(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20);
    *(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) = 0;
  }
  return 0;
}

/*
 * Card_KhabalGhoul_AddCounterOnDeath
 * Purpose: Add +1/+1 counter to Khabal Ghoul when a creature dies.
 * Procedure:
 * 1. Check if a creature died this turn.
 * 2. Add +1/+1 counter at end of turn.
 */
/*
 * Decompiled function: Card_KhabalGhoul_AddCounterOnDeath
 * Entry Point: 004e114e
 * Size: 385 bytes
 */

int Card_KhabalGhoul_AddCounterOnDeath(int player,int card_index,int event_code)

{
  int status;
  int slot_idx;
  
  if ((event_code == 0x73) && ((g_DuelModeFlags._1_1_ & 2) != 0)) {
    slot_idx = Card_GenericCreature_Regenerate(player,card_index,0x73,0,0);
    status = Card_GetCounters(player,card_index);
    if (status == 0) {
      slot_idx = 0;
    }
  }
  else if ((event_code == 0x6d) && ((g_DuelModeFlags._1_1_ & 2) != 0)) {
    slot_idx = Card_GenericCreature_Regenerate(player,card_index,0x6d,0,0);
    Card_RemoveCounters(player,card_index,1);
  }
  else if ((event_code == 0x72) && ((g_DuelModeFlags._1_1_ & 2) != 0)) {
    slot_idx = Card_GenericCreature_Regenerate(player,card_index,0x72,0,0);
  }
  else {
    if (((g_CurrentStepCode == 0xcd) || (event_code == 199)) &&
       ((((card_index == g_EventSourceSlot && (player == g_EventSourcePlayer)) && (DAT_006b303c != 0)
         ) && (g_CurrentCardColorTarget == player)))) {
      if (event_code == 0x7d) {
        g_CardEventResult = g_CardEventResult | 2;
      }
      if ((event_code == 0x7e) || (event_code == 199)) {
        Card_AddCounters(player,card_index,DAT_006b303c);
      }
    }
    slot_idx = 0;
  }
  return slot_idx;
}

/*
 * Card_KhabalGhoul_CheckCreatureDeath
 * Purpose: Track creature death events for Khabal Ghoul.
 * Procedure:
 * 1. Increment death counter register.
 */
/*
 * Decompiled function: Card_KhabalGhoul_CheckCreatureDeath
 * Entry Point: 004e12cf
 * Size: 1614 bytes
 */

int Card_KhabalGhoul_CheckCreatureDeath(int player,int card_index,int event_code)

{
  bool is_valid;
  int match_count;
  int slot_idx;
  
  if (((((event_code == 0x6e) &&
        (*(int *)(&g_CardSlot_CardId + g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20
                 ) == g_PendingSpellTargetSlot)) &&
       (*(int *)(&g_CardSlot_ConvertedManaCost +
                g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20) != 0)) &&
      ((*(int *)(&g_CardSlot_TypeFlags +
                g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20) == card_index &&
       ((char)(&g_CardSlot_DamageReceived)
              [g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20] == player)))) &&
     ((*(int *)(&g_CardSlot_OriginalCardId +
               g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20) != -1 &&
      ((((&g_MasterCardColorTable)
         [*(int *)(&g_CardSlot_CardId +
                  *(int *)(&g_CardSlot_OriginalCardId +
                          g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20) * 0x120 +
                  (char)(&g_CardSlot_Toughness)
                        [g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20] * 0x5b20) *
          0x34] & 2) != 0 &&
       (*(int *)(&g_CardSlot_TargetSlot + card_index * 0x120 + player * 0x5b20) < 0x13)))))) {
    *(int *)
     (&g_CardSlot_AttachedAura +
     card_index * 0x120 +
     player * 0x5b20 + *(int *)(&g_CardSlot_TargetSlot + card_index * 0x120 + player * 0x5b20) * 8) =
         *(int *)
          (&g_CardSlot_OriginalCardId +
          g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20);
    *(int *)(&g_CardSlot_CombatTarget +
            card_index * 0x120 +
            player * 0x5b20 + *(int *)(&g_CardSlot_TargetSlot + card_index * 0x120 + player * 0x5b20) * 8)
         = (int)(char)(&g_CardSlot_Toughness)
                      [g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20];
    *(int *)(&g_CardSlot_TargetSlot + card_index * 0x120 + player * 0x5b20) =
         *(int *)(&g_CardSlot_TargetSlot + card_index * 0x120 + player * 0x5b20) + 1;
  }
  if (event_code == 0x77) {
    is_valid = false;
    for (slot_idx = 0; slot_idx < *(int *)(&g_CardSlot_TargetSlot + card_index * 0x120 + player * 0x5b20);
        slot_idx = slot_idx + 1) {
      if (((*(int *)(&g_CardSlot_AttachedAura + card_index * 0x120 + player * 0x5b20 + slot_idx * 8) ==
            g_EventSourceSlot) &&
          (*(int *)(&g_CardSlot_CombatTarget + card_index * 0x120 + player * 0x5b20 + slot_idx * 8) ==
           g_EventSourcePlayer)) &&
         ((&g_CardSlot_CardTypeIndex)[g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20] != '\x04'))
      {
        match_count = slot_idx;
        if (!is_valid) {
          *(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) =
               *(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) + 1;
          is_valid = true;
        }
        while (match_count = match_count + 1,
              match_count < *(int *)(&g_CardSlot_TargetSlot + card_index * 0x120 + player * 0x5b20)) {
          *(int *)(&DAT_006a5f80 + card_index * 0x120 + player * 0x5b20 + match_count * 8) =
               *(int *)
                (&g_CardSlot_CombatTarget + card_index * 0x120 + player * 0x5b20 + match_count * 8);
          *(int *)(&DAT_006a5f84 + card_index * 0x120 + player * 0x5b20 + match_count * 8) =
               *(int *)
                (&g_CardSlot_AttachedAura + card_index * 0x120 + player * 0x5b20 + match_count * 8);
        }
        *(int *)(&g_CardSlot_TargetSlot + card_index * 0x120 + player * 0x5b20) =
             *(int *)(&g_CardSlot_TargetSlot + card_index * 0x120 + player * 0x5b20) + -1;
      }
    }
  }
  if (((g_CurrentStepCode == 0xd5) &&
      (*(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) != 0)) &&
     ((g_CurrentCardColorTarget == player &&
      ((card_index == g_EventSourceSlot && (player == g_EventSourcePlayer)))))) {
    if (event_code == 0x7d) {
      g_CardEventResult = g_CardEventResult | 2;
    }
    if (event_code == 0x7e) {
      Card_AddCounters(player,card_index,
                       *(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20));
      *(short *)(&g_CardSlot_PowerCounters + card_index * 0x120 + player * 0x5b20) =
           *(short *)(&g_CardSlot_PowerCounters + card_index * 0x120 + player * 0x5b20) +
           (short)*(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20);
      *(short *)(&g_CardSlot_ToughnessCounters + card_index * 0x120 + player * 0x5b20) =
           *(short *)(&g_CardSlot_ToughnessCounters + card_index * 0x120 + player * 0x5b20) +
           (short)*(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20);
      *(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) = 0;
    }
  }
  if ((event_code == 0x22) || (event_code == 199)) {
    *(int *)(&g_CardSlot_TargetSlot + card_index * 0x120 + player * 0x5b20) = 0;
  }
  return 0;
}

/*
 * Card_KhabalGhoul_ApplyCounterBonus
 * Purpose: Apply stats bonus from Khabal Ghoul +1/+1 counters.
 * Procedure:
 * 1. Add counter bonus to effective power/toughness.
 */
/*
 * Decompiled function: Card_KhabalGhoul_ApplyCounterBonus
 * Entry Point: 004e191d
 * Size: 270 bytes
 */

int Card_KhabalGhoul_ApplyCounterBonus(int player,int card_index,int event_code)

{
  if ((((event_code == 0x85) && (card_index == g_EventSourceSlot)) && (player == g_EventSourcePlayer)) &&
     ((player == g_TurnPlayer && (player == g_CurrentTurnTargetPlayer)))) {
    *(uint32_t *)(&g_CardSlot_SpecialState + player * 0x5b20 + card_index * 0x120) =
         *(uint32_t *)(&g_CardSlot_SpecialState + player * 0x5b20 + card_index * 0x120) | 1;
    (&DAT_006a6049)[player * 0x5b20 + card_index * 0x120] =
         (&DAT_006a6049)[player * 0x5b20 + card_index * 0x120] + '\x02';
  }
  if (event_code == 0x86) {
    Pic_Subsystem_0044867e(g_DialogPromptHwnd,g_DuelArenaHwnd,1);
  }
  if ((event_code == 199) && ((int)(&DAT_0063ee34)[player * 8] < 2)) {
    Pic_Subsystem_0044867e(player,card_index,1);
  }
  return 0;
}

/*
 * Card_KhabalGhoul_ResetCounterBonus
 * Purpose: Reset turn counter bonus for Khabal Ghoul.
 * Procedure:
 * 1. Clear temporary buff register.
 */
/*
 * Decompiled function: Card_KhabalGhoul_ResetCounterBonus
 * Entry Point: 004e1a2b
 * Size: 269 bytes
 */

int Card_KhabalGhoul_ResetCounterBonus(int player,int card_index,int event_code)

{
  if ((((event_code == 0x85) && (card_index == g_EventSourceSlot)) && (player == g_EventSourcePlayer)) &&
     ((player == g_TurnPlayer && (g_CurrentTurnTargetPlayer == player)))) {
    *(uint32_t *)(&g_CardSlot_SpecialState + card_index * 0x120 + player * 0x5b20) =
         *(uint32_t *)(&g_CardSlot_SpecialState + card_index * 0x120 + player * 0x5b20) | 1;
    (&DAT_006a604a)[card_index * 0x120 + player * 0x5b20] =
         (&DAT_006a604a)[card_index * 0x120 + player * 0x5b20] + '\x01';
  }
  if (event_code == 0x86) {
    Pic_Subsystem_0044867e(g_DialogPromptHwnd,g_DuelArenaHwnd,1);
  }
  if ((event_code == 199) && ((int)(&DAT_0063ee38)[player * 8] < 1)) {
    Pic_Subsystem_0044867e(player,card_index,1);
  }
  return 0;
}

/*
 * Card_LordOfAtlantis_PayOrSacrifice
 * Purpose: Process Lord of Atlantis sacrifice or mana payment upkeep.
 * Procedure:
 * 1. Prompt player for upkeep payment.
 */
/*
 * Decompiled function: Card_LordOfAtlantis_PayOrSacrifice
 * Entry Point: 004e1b38
 * Size: 340 bytes
 */

int Card_LordOfAtlantis_PayOrSacrifice(int player,int card_index,int event_code)

{
  bool is_valid;
  int val_result;
  
  if (((event_code == 0x15) && (((&g_CardSlot_Flags)[player * 0x5b20 + card_index * 0x120] & 4) != 0)) &&
     (*(int *)(&g_CardSlot_ConvertedManaCost + player * 0x5b20 + card_index * 0x120) == 0)) {
    *(int *)(&g_CardSlot_ConvertedManaCost + player * 0x5b20 + card_index * 0x120) = 1;
    is_valid = false;
    val_result = Font_DrawString(player, 7, 2);
    if (val_result != 0) {
      val_result = Ai_Subsystem_004cc56d(player,player,card_index,-1,-1,s_Pay_2_mana__Lose_3_life__0052ee0c,0);
      if (val_result == 0) {
        Ai_CalcManaRequirement_004ba890(player,0,2);
        if (g_ActivePlayer == 1) {
          g_ActivePlayer = -1;
        }
        else {
          is_valid = true;
        }
      }
    }
    if (!is_valid) {
      Mem_AllocOrFree_0041df33(player,3,player,card_index);
    }
  }
  if (event_code == 0x22) {
    *(int *)(&g_CardSlot_ConvertedManaCost + player * 0x5b20 + card_index * 0x120) = 0;
  }
  return 0;
}

/*
 * Card_LordOfAtlantis_ApplyMerfolkBuff
 * Purpose: Apply Lord of Atlantis anthem (+1/+1 and islandwalk to all Merfolk).
 * Procedure:
 * 1. Iterate Merfolk creatures and grant buff.
 */
/*
 * Decompiled function: Card_LordOfAtlantis_ApplyMerfolkBuff
 * Entry Point: 004e1c8c
 * Size: 266 bytes
 */

int Card_LordOfAtlantis_ApplyMerfolkBuff(int player,int card_index,int event_code)

{
  int status;
  
  if (((event_code == 0x15) && (((&g_CardSlot_Flags)[card_index * 0x120 + player * 0x5b20] & 4) != 0)) &&
     (*(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) == 0)) {
    *(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) = 1;
    status = Util_GetRandomNumber(2);
    if (status != 0) {
      *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) | 0x10;
      *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) & 0xfffffffb;
    }
  }
  if (event_code == 0x22) {
    *(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) = 0;
  }
  return 0;
}

/*
 * Card_LordOfAtlantis_RemoveMerfolkBuff
 * Purpose: Remove Lord of Atlantis anthem when card leaves battlefield.
 * Procedure:
 * 1. Clear Merfolk buffs.
 */
/*
 * Decompiled function: Card_LordOfAtlantis_RemoveMerfolkBuff
 * Entry Point: 004e1d96
 * Size: 214 bytes
 */

int Card_LordOfAtlantis_RemoveMerfolkBuff(int player,int card_index,int event_code)

{
  int status;
  
  if (((event_code == 0x1a) && (g_TurnPlayer != player)) &&
     ((&g_CardSlot_ColorMask)[card_index * 0x120 + player * 0x5b20] != -1)) {
    *(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) = 1;
    status = Util_GetRandomNumber(2);
    if (status != 0) {
      (&g_CardSlot_ColorMask)[card_index * 0x120 + player * 0x5b20] = 0xff;
    }
  }
  if (event_code == 0x22) {
    *(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) = 0;
  }
  return 0;
}

/*
 * Card_LordOfAtlantis_IslandwalkTrigger
 * Purpose: Check islandwalk attack validity for buffed Merfolk.
 * Procedure:
 * 1. Verify defender Island presence.
 */
/*
 * Decompiled function: Card_LordOfAtlantis_IslandwalkTrigger
 * Entry Point: 004e1e6c
 * Size: 161 bytes
 */

int Card_LordOfAtlantis_IslandwalkTrigger(int player,int card_index,int event_code)

{
  if (((event_code == 2) && (card_index == g_EventSourceSlot)) && (player == g_EventSourcePlayer)) {
    g_CardEventResult = g_CardEventResult | 2;
  }
  if (((((event_code == 4) && (card_index == g_EventSourceSlot)) && (player == g_EventSourcePlayer)) ||
      (event_code == 199)) &&
     ((int)(&g_PlayerCreatureCount)[player] < (int)(&g_PlayerCreatureCount)[1 - player])) {
    Pic_Subsystem_0042ca53(player,card_index);
  }
  return 0;
}

/*
 * Card_LordOfAtlantis_CheckMerfolkType
 * Purpose: Test if target creature has Merfolk subtype.
 * Procedure:
 * 1. Check creature subtype.
 */
/*
 * Decompiled function: Card_LordOfAtlantis_CheckMerfolkType
 * Entry Point: 004e1f0d
 * Size: 190 bytes
 */

int Card_LordOfAtlantis_CheckMerfolkType(int player,int card_index)

{
  if (((char)(&g_CardSlot_Toughness)[card_index * 0x120 + player * 0x5b20] == DAT_005659a4) &&
     (*(int *)(&g_CardSlot_OriginalCardId + card_index * 0x120 + player * 0x5b20) == DAT_00565994)) {
    *(int *)(&g_CardSlot_OriginalCardId + card_index * 0x120 + player * 0x5b20) = DAT_00565990;
  }
  return 0;
}

/*
 * Card_ForceOfNature_PayUpkeep
 * Purpose: Process Force of Nature upkeep (pay GGGG or take 8 damage).
 * Procedure:
 * 1. Prompt controller to pay GGGG.
 * 2. Deal 8 damage to controller if unpaid.
 */
/*
 * Decompiled function: Card_ForceOfNature_PayUpkeep
 * Entry Point: 004e1fcb
 * Size: 310 bytes
 */

int Card_ForceOfNature_PayUpkeep(int player,int card_index,int event_code)

{
  if ((((event_code == 0x85) && (card_index == g_EventSourceSlot)) && (player == g_EventSourcePlayer)) &&
     ((player == g_TurnPlayer && (g_CurrentTurnTargetPlayer == player)))) {
    *(uint32_t *)(&g_CardSlot_SpecialState + player * 0x5b20 + card_index * 0x120) =
         *(uint32_t *)(&g_CardSlot_SpecialState + player * 0x5b20 + card_index * 0x120) | 1;
    (&DAT_006a604b)[player * 0x5b20 + card_index * 0x120] =
         (&DAT_006a604b)[player * 0x5b20 + card_index * 0x120] + '\x04';
  }
  if (event_code == 0x86) {
    Ai_Subsystem_004cc56d(player,player,card_index,-1,-1,s_Force_of_Nature_deals_8_damage__0052ee28,0);
    Mem_AllocOrFree_0041df33(player,8,g_DialogPromptHwnd,g_DuelArenaHwnd);
  }
  if ((event_code == 199) && (*(int *)(&DAT_0063ee3c + player * 0x20) < 4)) {
    Mem_AllocOrFree_0041df33(player,8,player,card_index);
  }
  return 0;
}

/*
 * Card_ForceOfNature_AiPayOrTakeDamage
 * Purpose: AI decision logic for Force of Nature upkeep.
 * Procedure:
 * 1. Evaluate available green mana versus life total.
 */
/*
 * Decompiled function: Card_ForceOfNature_AiPayOrTakeDamage
 * Entry Point: 004e2101
 * Size: 433 bytes
 */

bool Card_ForceOfNature_AiPayOrTakeDamage(int player,int card_index,int event_code)

{
  bool is_valid;
  
  if (event_code == 0x73) {
    is_valid = (*(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) & 0x20010) == 0;
  }
  else {
    if ((event_code == 0x6d) && (((&g_CardSlot_Flags)[card_index * 0x120 + player * 0x5b20] & 0x10) == 0)) {
      FUN_0040d901(player,3,1);
      *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) | 0x10;
      g_PendingAttackersTargetSlot = 3;
    }
    if ((((event_code == 0x7f) && (card_index == g_EventSourceSlot)) && (player == g_EventSourcePlayer))
       && ((*(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) & 0x20010) == 0)) {
      FUN_0040d7e9(player,3,1);
    }
    if (((event_code == 0x8a) && (card_index == g_EventSourceSlot)) && (player == g_EventSourcePlayer)) {
      g_AiBlockingCreatureCount = g_AiBlockingCreatureCount +
                     (int)(0x18 / (longlong)(*(int *)(&DAT_0063ee3c + player * 0x20) + 2));
    }
    if (((event_code == 0x8b) && (card_index == g_EventSourceSlot)) && (player == g_EventSourcePlayer)) {
      g_AiBlockingCreatureCount = g_AiBlockingCreatureCount -
                     (int)(0x60 / (longlong)(*(int *)(&DAT_0063ee3c + player * 0x20) + 2));
    }
    is_valid = false;
  }
  return is_valid;
}

/*
 * Card_BirdsOfParadise_TapForMana
 * Purpose: Activate Birds of Paradise ability (tap: add one mana of any color).
 * Procedure:
 * 1. Prompt player for chosen mana color.
 * 2. Add 1 mana of chosen color to player mana pool.
 */
/*
 * Decompiled function: Card_BirdsOfParadise_TapForMana
 * Entry Point: 004e22b2
 * Size: 988 bytes
 */

bool Card_BirdsOfParadise_TapForMana(int player,int card_index,int event_code)

{
  int card_index;
  char *mode_str;
  bool is_valid;
  int card_idx;
  int match_count;
  
  if (event_code == 0x73) {
    is_valid = (*(uint32_t *)(&g_CardSlot_Flags + player * 0x5b20 + card_index * 0x120) & 0x20010) == 0;
  }
  else {
    if ((event_code == 0x6d) &&
       (((&g_CardSlot_Flags)[player * 0x5b20 + card_index * 0x120] & 0x10) == 0)) {
      if ((player == 1) || ((g_IsAiThinking == 1 || (g_AiTurnDecisionFlag != 0)))) {
        card_idx = -1;
        match_count = 1;
        while ((match_count < 6 && (card_idx == -1))) {
          if ((0 < (&g_AiSelectedTargetCard)[match_count]) &&
             (((int)(char)(&g_CardSlot_PlusOneCounters)[player * 0x5b20 + card_index * 0x120] &
              1 << ((uint8_t)match_count & 0x1f)) != 0)) {
            card_idx = match_count;
          }
          match_count = match_count + 1;
        }
        if ((card_idx == -1) && (0 < g_AiSelectedTargetCard)) {
          card_idx = 1;
        }
        if ((card_idx == -1) && (0 < g_AiSelectedTargetPlayer)) {
          card_idx = 1;
        }
        if (card_idx == -1) {
          g_ActivePlayer = 1;
        }
      }
      else {
        card_idx = -1;
      }
      if (g_ActivePlayer != 1) {
        Pic_Subsystem_00424500(s_prompts_txt_0052ee5c,s_BIRDS_OF_PARADISE_0052ee48);
        card_index = Ai_Subsystem_004cc93d
                          (player,&g_OverworldGoldAmount,1,card_idx,
                           (int)(char)(&g_CardSlot_PlusOneCounters)[player * 0x5b20 + card_index * 0x120]);
        if (card_index == -1) {
          g_ActivePlayer = 1;
        }
        else {
          FUN_0040d875(player,card_index,1);
          FUN_0040d64c(player,(int)(char)(&g_CardSlot_PlusOneCounters)[player * 0x5b20 + card_index * 0x120],1)
          ;
          *(uint32_t *)(&g_CardSlot_Flags + player * 0x5b20 + card_index * 0x120) =
               *(uint32_t *)(&g_CardSlot_Flags + player * 0x5b20 + card_index * 0x120) | 0x10;
          g_PendingAttackersTargetSlot = card_index;
          if (player != g_CurrentTurnPhase) {
            strcpy(&g_OverworldWorldState,s_to_produce_0052ee68);
            str_2 = (char *)Mem_AllocOrFree_00473d7e(card_index);
            strcat(&g_OverworldWorldState,str_2);
            strcat(&g_OverworldWorldState,s_mana__0052ee74);
            Ai_Subsystem_004cc56d(player,player,card_index,-1,-1,&g_OverworldWorldState,0);
          }
        }
      }
    }
    if ((((event_code == 0x7f) && (card_index == g_EventSourceSlot)) &&
        (player == g_EventSourcePlayer)) &&
       ((*(uint32_t *)(&g_CardSlot_Flags + player * 0x5b20 + card_index * 0x120) & 0x20010) == 0)) {
      FUN_0040d59c(player,(int)(char)(&g_CardSlot_PlusOneCounters)[player * 0x5b20 + card_index * 0x120],1);
    }
    if (((event_code == 0x8a) && (card_index == g_EventSourceSlot)) &&
       (player == g_EventSourcePlayer)) {
      g_AiBlockingCreatureCount = g_AiBlockingCreatureCount +
                     (int)(0x60 / (longlong)(*(int *)(&g_PlayerManaPoolDelta + player * 0x20) + 2));
    }
    if (((event_code == 0x8b) && (card_index == g_EventSourceSlot)) &&
       (player == g_EventSourcePlayer)) {
      g_AiBlockingCreatureCount = g_AiBlockingCreatureCount -
                     (int)(0x60 / (longlong)(*(int *)(&g_PlayerManaPoolDelta + player * 0x20) + 2));
    }
    is_valid = false;
  }
  return is_valid;
}

/*
 * Card_CosmicHorror_PayUpkeep
 * Purpose: Process Cosmic Horror upkeep (pay 3 mana or take 7 damage and destroy).
 * Procedure:
 * 1. Prompt controller to pay 3 mana.
 * 2. Destroy card and deal 7 damage if unpaid.
 */
/*
 * Decompiled function: Card_CosmicHorror_PayUpkeep
 * Entry Point: 004e268e
 * Size: 435 bytes
 */

int Card_CosmicHorror_PayUpkeep(int player,int card_index,int event_code)

{
  if ((((event_code == 0x85) && (card_index == g_EventSourceSlot)) && (player == g_EventSourcePlayer)) &&
     ((player == g_TurnPlayer && (g_CurrentTurnTargetPlayer == player)))) {
    *(uint32_t *)(&g_CardSlot_SpecialState + card_index * 0x120 + player * 0x5b20) =
         *(uint32_t *)(&g_CardSlot_SpecialState + card_index * 0x120 + player * 0x5b20) | 1;
    (&DAT_006a6049)[card_index * 0x120 + player * 0x5b20] =
         (&DAT_006a6049)[card_index * 0x120 + player * 0x5b20] + '\x03';
    (&DAT_006a6048)[card_index * 0x120 + player * 0x5b20] =
         (&DAT_006a6048)[card_index * 0x120 + player * 0x5b20] + '\x03';
  }
  if (event_code == 0x86) {
    Ai_Subsystem_004cc56d(player,player,card_index,-1,-1,s_Cosmic_Horror_deals_7_damage__0052ee7c,0);
    Mem_AllocOrFree_0041df33(player,7,g_DialogPromptHwnd,g_DuelArenaHwnd);
    Pic_Subsystem_0044867e(g_DialogPromptHwnd,g_DuelArenaHwnd,1);
  }
  if ((event_code == 199) &&
     (((int)(&DAT_0063ee34)[player * 8] < 3 || (*(int *)(&g_PlayerManaPoolDelta + player * 0x20) < 6)))) {
    Mem_AllocOrFree_0041df33(player,7,player,card_index);
    Pic_Subsystem_0044867e(player,card_index,1);
  }
  return 0;
}

/*
 * Card_LordOfThePit_SacrificeOrDamage
 * Purpose: Process Lord of the Pit upkeep (sacrifice creature or take 7 damage).
 * Procedure:
 * 1. Prompt controller to sacrifice a creature.
 * 2. Deal 7 damage to controller if no creature is sacrificed.
 */
/*
 * Decompiled function: Card_LordOfThePit_SacrificeOrDamage
 * Entry Point: 004e2841
 * Size: 856 bytes
 */

int Card_LordOfThePit_SacrificeOrDamage(int player,int card_index,int event_code)

{
  int status;
  
  if ((((event_code == 0x6c) && (card_index == g_EventSourceSlot)) &&
      (player == g_EventSourcePlayer)) && (*(int *)(&DAT_006b3010 + player * 4) < 2)) {
    g_SpellStackDepth = g_SpellStackDepth + -0xa8;
  }
  if (event_code == 0x87) {
    status = Card_LordOfThePit_FindSacrificeCandidate(player,card_index);
    if (status == 0) {
      g_CardEventResult = g_CardEventResult | 1;
    }
  }
  if ((((event_code == 0x85) && (card_index == g_EventSourceSlot)) &&
      ((player == g_EventSourcePlayer &&
       ((*(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) == 0 &&
        (player == g_TurnPlayer)))))) && (g_CurrentTurnTargetPlayer == player)) {
    *(uint32_t *)(&g_CardSlot_SpecialState + card_index * 0x120 + player * 0x5b20) =
         *(uint32_t *)(&g_CardSlot_SpecialState + card_index * 0x120 + player * 0x5b20) | 0x101;
    status = Card_LordOfThePit_FindSacrificeCandidate(player,card_index);
    if (status == 0) {
      DAT_006ff550 = DAT_006ff550 + 1;
    }
  }
  if (((event_code == 4) && (card_index == g_EventSourceSlot)) && (player == g_EventSourcePlayer))
  {
    *(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) =
         *(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) + 1;
    status = Card_LordOfThePit_FindSacrificeCandidate(player,card_index);
    if (status == 0) {
      g_CardEventResult = g_CardEventResult | 1;
    }
    else {
      *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) | 0x100000;
      Ai_EvaluateTacticalPosition(0,0x20);
      Pic_Subsystem_00424500(s_prompts_txt_0052eeac,s_LORD_OF_THE_PIT_0052ee9c);
      status = CardTarget_HasValidCreatureTarget(player);
      *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) & 0xffefffff;
      Pic_Subsystem_0044867e(player,status,3);
    }
  }
  if (event_code == 0x86) {
    Ai_Subsystem_004cc56d
              (player,player,card_index,-1,-1,s_Lord_of_the_Pit_deals_7_damage__0052eeb8,0);
    Mem_AllocOrFree_0041df33(player,7,g_DialogPromptHwnd,g_DuelArenaHwnd);
  }
  if (event_code == 199) {
    status = Card_LordOfThePit_FindSacrificeCandidate(player,card_index);
    if (status == 0) {
      Mem_AllocOrFree_0041df33(player,7,g_DialogPromptHwnd,g_DuelArenaHwnd);
    }
  }
  if (((event_code == 0x22) || (event_code == 199)) &&
     ((card_index == g_EventSourceSlot && (player == g_EventSourcePlayer)))) {
    *(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) = 0;
  }
  if (((event_code == 0x8a) && (card_index == g_EventSourceSlot)) &&
     (player == g_EventSourcePlayer)) {
    g_AiBlockingCreatureCount = g_AiBlockingCreatureCount + -0x30;
  }
  if (((event_code == 0x8b) && (card_index == g_EventSourceSlot)) &&
     (player == g_EventSourcePlayer)) {
    g_AiBlockingCreatureCount = g_AiBlockingCreatureCount + 0x30;
  }
  return 0;
}

/*
 * Card_LordOfThePit_FindSacrificeCandidate
 * Purpose: Find eligible non-Lord creature to sacrifice.
 * Procedure:
 * 1. Iterate controller creatures.
 * 2. Return index of lowest value sacrifice candidate.
 */
/*
 * Decompiled function: Card_LordOfThePit_FindSacrificeCandidate
 * Entry Point: 004e2b99
 * Size: 230 bytes
 */

int Card_LordOfThePit_FindSacrificeCandidate(int player,int card_index)

{
  int match_count;
  int slot_idx;
  
  match_count = 0;
  slot_idx = 0;
  while ((match_count < (int)(&g_PlayerActiveCardCount)[player] && (slot_idx == 0))) {
    if ((((*(int *)(&g_CardSlot_CardId + player * 0x5b20 + match_count * 0x120) != -1) &&
         (((&g_CardSlot_Flags)[player * 0x5b20 + match_count * 0x120] & 2) != 0)) &&
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId + player * 0x5b20 + match_count * 0x120) * 0x34] & 2) != 0)) &&
       (match_count != card_index)) {
      slot_idx = 1;
    }
    match_count = match_count + 1;
  }
  return slot_idx;
}

/*
 * Card_KormusBell_PayLandUpkeep
 * Purpose: Process Kormus Bell / animated land upkeep cost.
 * Procedure:
 * 1. Prompt player to pay mana or sacrifice land.
 */
/*
 * Decompiled function: Card_KormusBell_PayLandUpkeep
 * Entry Point: 004e2c7f
 * Size: 873 bytes
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int Card_KormusBell_PayLandUpkeep(int player,int card_index,int event_code)

{
  bool is_valid;
  int u_temp;
  int temp_idx;
  int match_count;
  
  if (event_code == 0x73) {
    if (((*(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) & 0x20010) == 0) &&
       ((((&g_PlayerPoisonCounters)[1 - player] | g_PlayerPoisonCounters) & 1) != 0)) {
      u_temp = 1;
    }
    else {
      u_temp = 0;
    }
  }
  else if (event_code == 0x90) {
    Ai_GetOpponentPlayerScore(0);
    u_temp = 0;
  }
  else {
    if ((event_code == 0x6d) &&
       ((*(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) & 0x20010) == 0)) {
      if (match_count == -1) {
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[card_index * 0x120 + player * 0x5b20] = g_TemporaryToughnessBuffer;
        *(int *)(&g_CardSlot_OriginalCardId + card_index * 0x120 + player * 0x5b20) = match_count;
      }
      *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) | 0x10;
    }
    if (event_code == 0x72) {
      Pic_Subsystem_0044867e
                ((int)(char)(&g_CardSlot_Toughness)[card_index * 0x120 + player * 0x5b20],
                 *(int *)(&g_CardSlot_OriginalCardId + card_index * 0x120 + player * 0x5b20),2);
      *(int *)(&g_CardSlot_OriginalCardId + card_index * 0x120 + player * 0x5b20) = 0xffffffff;
      (&g_CardSlot_Toughness)[card_index * 0x120 + player * 0x5b20] =
           (&g_CardSlot_OriginalCardId)[card_index * 0x120 + player * 0x5b20];
    }
    if (((event_code == 2) && (card_index == g_EventSourceSlot)) && (player == g_EventSourcePlayer)) {
      g_CardEventResult = g_CardEventResult | 2;
    }
    if ((((event_code == 4) && (card_index == g_EventSourceSlot)) && (player == g_EventSourcePlayer)) ||
       (event_code == 199)) {
      is_valid = false;
      temp_idx = Font_DrawString(player,1,3);
      if ((temp_idx != 0) &&
         (temp_idx = Ai_Subsystem_004cc56d
                            (player,player,card_index,-1,-1,s_Pay_mana__Sacrifice_Land__0052eed8,0),
         temp_idx == 0)) {
        Ai_CalcManaRequirement_004ba890(player,1,3);
        if (g_ActivePlayer == 1) {
          g_ActivePlayer = -1;
        }
        else {
          is_valid = true;
        }
      }
      if ((event_code == 199) && (temp_idx = Font_DrawString(player,1,3), temp_idx != 0)) {
        is_valid = true;
      }
      if ((!is_valid) && (temp_idx = CardQuery_PlayerControlsColor(player,1), temp_idx != 0)) {
        do {
        } while (match_count == -1);
        Pic_Subsystem_0044867e(g_TemporaryToughnessBuffer,match_count,3);
        *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) | 0x10;
      }
    }
    u_temp = 0;
  }
  return u_temp;
}

/*
 * Card_KormusBell_CheckSwampCreature
 * Purpose: Test if permanent is an animated Swamp creature.
 * Procedure:
 * 1. Verify Swamp permanent type and creature status.
 */
/*
 * Decompiled function: Card_KormusBell_CheckSwampCreature
 * Entry Point: 004e2fe8
 * Size: 320 bytes
 */

int Card_KormusBell_CheckSwampCreature(int player,int card_index,int event_code)

{
  if ((g_EventSourceSlot == card_index) && (g_EventSourcePlayer == player)) {
    *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) =
         *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) & 0xfffcffff;
  }
  if (event_code == 199) {
    Pic_Subsystem_0044867e(player,card_index,1);
  }
  if ((((g_CurrentStepCode == 0xcd) && (g_EventSourceSlot == card_index)) &&
      (g_EventSourcePlayer == player)) && (g_CurrentCardColorTarget == player)) {
    if (event_code == 0x7d) {
      g_CardEventResult = g_CardEventResult | 2;
    }
    if (event_code == 0x7e) {
      Pic_Subsystem_0044867e(player,card_index,1);
    }
  }
  if (((event_code == 0x8a) && (g_EventSourceSlot == card_index)) && (g_EventSourcePlayer == player)) {
    g_AiBlockingCreatureCount = g_AiBlockingCreatureCount + -0x3c;
  }
  if (((event_code == 0x8b) && (g_EventSourceSlot == card_index)) && (g_EventSourcePlayer == player)) {
    g_AiBlockingCreatureCount = g_AiBlockingCreatureCount + 0x3c;
  }
  return 0;
}

/*
 * Card_NetherShadow_CheckGraveyard
 * Purpose: Check if Nether Shadow can return from graveyard at upkeep.
 * Procedure:
 * 1. Verify if at least 3 creature cards lie above Nether Shadow in graveyard.
 */
/*
 * Decompiled function: Card_NetherShadow_CheckGraveyard
 * Entry Point: 004e3128
 * Size: 93 bytes
 */

int Card_NetherShadow_CheckGraveyard(int player,int card_index,int event_code)

{
  if (((event_code == 0x77) && (card_index == g_EventSourceSlot)) && (player == g_EventSourcePlayer)) {
    (&g_CardSlot_CardTypeIndex)[g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20] = 4;
  }
  return 0;
}

/*
 * Card_NetherShadow_CountCreaturesAbove
 * Purpose: Count creature cards positioned above Nether Shadow in graveyard.
 * Procedure:
 * 1. Iterate graveyard cards above Nether Shadow index.
 */
/*
 * Decompiled function: Card_NetherShadow_CountCreaturesAbove
 * Entry Point: 004e3185
 * Size: 366 bytes
 */

int Card_NetherShadow_CountCreaturesAbove(int player,int card_index,int event_code)

{
  int status;
  
  if (((event_code == 0x6c) && (g_EventSourceSlot == card_index)) && (player == g_EventSourcePlayer)) {
    *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) =
         *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) & 0xfffcffff;
  }
  if ((event_code == 0x8d) ||
     (((event_code == 0x77 && (g_EventSourceSlot == card_index)) &&
      ((player == g_EventSourcePlayer &&
       ((((&g_CardSlot_Flags)[card_index * 0x120 + player * 0x5b20] & 0x20) == 0 &&
        ((&g_CardSlot_CardTypeIndex)[card_index * 0x120 + player * 0x5b20] != '\x04')))))))) {
    status = Deck_AddCardToDeck(player,DAT_006a28b4);
    if (status != -1) {
      *(uint32_t *)(&g_CardSlot_Flags + status * 0x120 + player * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_Flags + status * 0x120 + player * 0x5b20) | 2;
      *(int *)(&DAT_006a5f74 + status * 0x120 + player * 0x5b20) =
           *(int *)
            (&g_MasterCardTypeTable +
            *(int *)(&g_CardSlot_CardId + card_index * 0x120 + player * 0x5b20) * 0x34);
    }
  }
  return 0;
}

/*
 * Card_NetherShadow_ReturnFromGrave
 * Purpose: Return Nether Shadow from graveyard directly to battlefield.
 * Procedure:
 * 1. Move Nether Shadow from graveyard to battlefield.
 * 2. Log resurrection announcement.
 */
/*
 * Decompiled function: Card_NetherShadow_ReturnFromGrave
 * Entry Point: 004e32f3
 * Size: 497 bytes
 */

int Card_NetherShadow_ReturnFromGrave(int player,int card_index,int event_code)

{
  int status;
  int player_idx;
  int match_count;
  
  if (((((g_CurrentStepCode == 0xcb) || (event_code == 199)) && (card_index == g_EventSourceSlot)) &&
      ((player == g_EventSourcePlayer && (player == g_TurnPlayer)))) &&
     (g_CurrentCardColorTarget == player)) {
    status = Pic_Subsystem_0045268f(0xab);
    player_idx = 0;
    for (match_count = 499; -1 < match_count; match_count = match_count + -1) {
      if (((*(int *)(&g_PlayerGraveyardList + match_count * 4 + player * 2000) != -1) &&
          (((&g_MasterCardColorTable)[*(int *)(&g_PlayerGraveyardList + match_count * 4 + player * 2000) * 0x34] &
           2) != 0)) &&
         ((player_idx = player_idx + 1, *(int *)(&g_PlayerGraveyardList + match_count * 4 + player * 2000) == status &&
          (3 < player_idx)))) {
        if (event_code == 0x7d) {
          g_CardEventResult = g_CardEventResult | 1;
        }
        if ((event_code != 0x7e) && (event_code != 199)) {
          return 0;
        }
        status = Deck_AddCardToDeck(player,status);
        if (status == -1) {
          return 0;
        }
        Pic_Subsystem_0042ac1f(player,status);
        *(uint32_t *)(&g_CardSlot_Flags + player * 0x5b20 + status * 0x120) =
             *(uint32_t *)(&g_CardSlot_Flags + player * 0x5b20 + status * 0x120) & 0xfffcffff;
        Pic_Subsystem_00449223(player,match_count);
        Pic_Subsystem_0044867e(player,card_index,4);
        Ai_EvaluateTacticalPosition(0,0x30);
        Ai_Subsystem_004cc56d(player,player,status,-1,-1,s_is_returning_from_the_grave__0052eef4,0);
        return 0;
      }
    }
  }
  return 0;
}

/*
 * Card_RockHydra_DecrementHead
 * Purpose: Remove +1/+1 head counter from Rock Hydra when damaged.
 * Procedure:
 * 1. Deduct 1 head counter per damage point.
 */
/*
 * Decompiled function: Card_RockHydra_DecrementHead
 * Entry Point: 004e34e4
 * Size: 127 bytes
 */

int Card_RockHydra_DecrementHead(int player,int card_index,int event_code)

{
  uint32_t u_res;
  char cVar2;
  
  if (((event_code == 0x34) && (card_index == g_EventSourceSlot)) && (player == g_EventSourcePlayer)) {
    cVar2 = Card_SetTapState(player, card_index, 1);
    g_CardEventResult = g_CardEventResult | 0x800 << (cVar2 - 1U & 0x1f);
    u_res = g_CardEventResult;
    Card_RockHydra_UpdateStatsFromHeads(player,card_index,1);
    g_CardEventResult = u_res;
  }
  return 0;
}

/*
 * Card_RockHydra_DamageTrigger
 * Purpose: Process damage prevention via Rock Hydra head counter sacrifice.
 * Procedure:
 * 1. Prevent damage by removing head counters.
 */
/*
 * Decompiled function: Card_RockHydra_DamageTrigger
 * Entry Point: 004e3563
 * Size: 129 bytes
 */

int Card_RockHydra_DamageTrigger(int player,int card_index,int event_code)

{
  uint32_t u_res;
  char cVar2;
  
  if (((event_code == 0x34) && (g_EventSourceSlot == card_index)) && (g_EventSourcePlayer == player)) {
    cVar2 = Card_SetTapState(player,card_index,5);
    g_CardEventResult = g_CardEventResult | 0x800 << (cVar2 - 1U & 0x1f);
    u_res = g_CardEventResult;
    Card_RockHydra_UpdateStatsFromHeads(player,card_index,5);
    g_CardEventResult = u_res;
  }
  return 0;
}

/*
 * Card_RockHydra_UpdateStatsFromHeads
 * Purpose: Update Rock Hydra power and toughness based on active head counters.
 * Procedure:
 * 1. Set power and toughness equal to head counter count.
 */
/*
 * Decompiled function: Card_RockHydra_UpdateStatsFromHeads
 * Entry Point: 004e35e4
 * Size: 332 bytes
 */

void Card_RockHydra_UpdateStatsFromHeads(int player,int card_index,int event_code)

{
  char c_res;
  uint8_t is_match;
  int temp_idx;
  int match_count;
  int slot_idx;
  
  for (slot_idx = 0; slot_idx < 2; slot_idx = slot_idx + 1) {
    for (match_count = 0; match_count < (int)(&g_PlayerActiveCardCount)[slot_idx]; match_count = match_count + 1) {
      temp_idx = Card_IsTapped(slot_idx,match_count);
      if (((temp_idx != 0) &&
          ((char)(&g_CardSlot_Toughness)[match_count * 0x120 + slot_idx * 0x5b20] == player)) &&
         (*(int *)(&g_CardSlot_OriginalCardId + match_count * 0x120 + slot_idx * 0x5b20) == card_index)) {
        c_res = (&g_CardSlot_MinusOneCounters)[match_count * 0x120 + slot_idx * 0x5b20];
        is_match = Card_SetTapState(player,card_index,event_code);
        if (((1 << (is_match & 0x1f) & (int)c_res) != 0) &&
           (((&g_MasterCardColorTable)
             [*(int *)(&g_CardSlot_CardId + match_count * 0x120 + slot_idx * 0x5b20) * 0x34] & 4) != 0))
        {
          Pic_Subsystem_0044867e(slot_idx,match_count,1);
        }
      }
    }
  }
  return;
}

/*
 * Card_RockHydra_InitHeads
 * Purpose: Initialize Rock Hydra head counters upon entering play.
 * Procedure:
 * 1. Set head counters equal to X casting cost.
 */
/*
 * Decompiled function: Card_RockHydra_InitHeads
 * Entry Point: 004e3730
 * Size: 91 bytes
 */

int Card_RockHydra_InitHeads(int player,int card_index,int event_code)

{
  char c_res;
  
  if (((event_code == 0x34) && (g_EventSourceSlot == card_index)) && (player == g_EventSourcePlayer)) {
    c_res = Card_SetTapState(player,card_index,4);
    g_CardEventResult = g_CardEventResult | 0x800 << (c_res - 1U & 0x1f);
  }
  return 0;
}

/*
 * Card_RockHydra_RegrowHead
 * Purpose: Pay mana to regrow or restore Rock Hydra head counters.
 * Procedure:
 * 1. Prompt player to pay RRR to regrow heads.
 * 2. Add head counter if paid.
 */
/*
 * Decompiled function: Card_RockHydra_RegrowHead
 * Entry Point: 004e378b
 * Size: 970 bytes
 */

int Card_RockHydra_RegrowHead(int player,int card_index,int event_code)

{
  bool is_valid;
  int val_result;
  int slot_idx;
  
  if (((event_code == 0x6c) && (card_index == g_EventSourceSlot)) && (player == g_EventSourcePlayer)) {
    *(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) = g_TurnCounter;
  }
  if (((event_code == 2) && (card_index == g_EventSourceSlot)) &&
     ((player == g_EventSourcePlayer && (val_result = Font_DrawString(player,4,3), val_result != 0)))) {
    g_CardEventResult = g_CardEventResult | 1;
  }
  if ((card_index == g_EventSourceSlot) && (player == g_EventSourcePlayer)) {
    if ((event_code == 0x32) || (event_code == 0x33)) {
      g_CardEventResult =
           g_CardEventResult +
           *(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20);
    }
    if ((((event_code == 0x6e) &&
         ((char)(&g_CardSlot_Toughness)
                [g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20] == player)) &&
        (*(int *)(&g_CardSlot_OriginalCardId +
                 g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20) == card_index)) &&
       (*(int *)(&g_CardSlot_ConvertedManaCost +
                g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20) != 0)) {
      for (slot_idx = 0;
          slot_idx < *(int *)(&g_CardSlot_ConvertedManaCost +
                            g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20);
          slot_idx = slot_idx + 1) {
        is_valid = false;
        val_result = Font_DrawString(player,4,1);
        if ((val_result != 0) &&
           (val_result = Ai_Subsystem_004cc56d
                              (player,player,card_index,-1,-1,s_Restore_Hydra_Head__Never_mind__0052ef14,0)
           , val_result == 0)) {
          Ai_CalcManaRequirement_004ba890(player,4,1);
          if (g_ActivePlayer == 1) {
            g_ActivePlayer = -1;
          }
          else {
            is_valid = true;
          }
        }
        if (!is_valid) break;
        *(int *)(&g_CardSlot_ConvertedManaCost +
                g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20) =
             *(int *)(&g_CardSlot_ConvertedManaCost +
                     g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20) + -1;
      }
      val_result = Math_Clamp(*(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20),
                           0,*(int *)(&g_CardSlot_ConvertedManaCost +
                                     g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20))
      ;
      *(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) =
           *(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) - val_result;
      *(int *)(&g_CardSlot_ConvertedManaCost +
              g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20) =
           *(int *)(&g_CardSlot_ConvertedManaCost +
                   g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20) - val_result;
    }
    if (((event_code == 4) && (card_index == g_EventSourceSlot)) &&
       ((player == g_EventSourcePlayer &&
        ((val_result = Font_DrawString(player,4,3), val_result != 0 &&
         (val_result = Ai_Subsystem_004cc56d
                            (player,player,card_index,-1,-1,s_Grow_new_Hydra_head__Never_mind__0052ef38,0),
         val_result == 0)))))) {
      Ai_CalcManaRequirement_004ba890(player,4,3);
      if (g_ActivePlayer == 1) {
        g_ActivePlayer = -1;
      }
      else {
        *(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) =
             *(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) + 1;
      }
    }
  }
  return 0;
}

/*
 * Card_AliBaba_TapWall
 * Purpose: Activate Ali Baba ability (pay R: tap target Wall).
 * Procedure:
 * 1. Validate target Wall creature.
 * 2. Tap target Wall.
 */
/*
 * Decompiled function: Card_AliBaba_TapWall
 * Entry Point: 004e3b55
 * Size: 753 bytes
 */

int Card_AliBaba_TapWall(int player,int card_index,int event_code)

{
  int status;
  int u_temp;
  uint32_t uval_3;
  uint32_t uval_4;
  uint32_t uval_5;
  int arg_11;
  int val_6;
  int arg_12;
  uint32_t uval_7;
  int arg_13;
  uint32_t uval_8;
  int arg_14;
  uint32_t uVar9;
  int arg_15;
  uint32_t uVar10;
  int arg_16;
  uint32_t uVar11;
  int arg_17;
  uint8_t *arg_18;
  int arg_18_00;
  int arg_19;
  int *arg_20;
  int match_count;
  int slot_idx;
  
  if (event_code == 0x73) {
    status = Font_DrawString(player,4,1);
    if (status != 0) {
      arg_19 = 0;
      arg_18_00 = 0;
      arg_17 = 1;
      arg_16 = 0xffffffff;
      arg_15 = 0xffffffff;
      arg_14 = 0xffffffff;
      arg_13 = 0xffffffff;
      arg_12 = 0;
      arg_11 = 0;
      u_temp = Card_GetColorAndTypeFlags(player,card_index);
      status = UI_PaintBigCardInfo((int *)0x0,0,player,2,2,0x200,2,0,0,u_temp,arg_11,arg_12,arg_13,arg_14,
                           arg_15,arg_16,arg_17,arg_18_00,arg_19);
      if (status != 0) {
        return 1;
      }
    }
  }
  else if (event_code == 0x90) {
    Ai_GetOpponentPlayerScore(0);
  }
  else {
    if (((event_code == 0x6d) && (status = Font_DrawString(player,4,1), status != 0)) &&
       (Ai_CalcManaRequirement_004ba890(player,4,1), g_ActivePlayer != 1)) {
      Pic_Subsystem_00424500(s_prompts_txt_0052ef64,s_ALIBABA_0052ef5c);
      arg_20 = &match_count;
      u_temp = 1;
      arg_18 = &g_OverworldGoldAmount;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 1;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      val_6 = -1;
      status = -1;
      uval_5 = 0;
      uval_4 = 0;
      uval_3 = Card_GetColorAndTypeFlags(player,card_index);
      status = Duel_ChooseTarget
                        (player,2,1 - player,0x200,2,0,0,uval_3,uval_4,uval_5,status,val_6,uval_7,
                         uval_8,uVar9,uVar10,uVar11,arg_18,u_temp,arg_20);
      if (status == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + card_index * 0x120 + player * 0x5b20) = match_count;
        *(int *)(&g_CardSlot_AttachedAura + card_index * 0x120 + player * 0x5b20) = slot_idx;
        (&g_CardSlot_TurnPlayed)[card_index * 0x120 + player * 0x5b20] = 1;
      }
    }
    if (event_code == 0x72) {
      match_count = *(int *)(&g_CardSlot_CombatTarget + card_index * 0x120 + player * 0x5b20);
      slot_idx = *(int *)(&g_CardSlot_AttachedAura + card_index * 0x120 + player * 0x5b20);
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 1;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      val_6 = -1;
      status = -1;
      uval_5 = 0;
      uval_4 = 0;
      uval_3 = Card_GetColorAndTypeFlags(player,card_index);
      status = Rules_ParseFilter_0040360b
                        (match_count,slot_idx,(char *)0x0,player,2,2,0x200,2,0,0,uval_3,uval_4,uval_5,
                         status,val_6,uval_7,uval_8,uVar9,uVar10,uVar11);
      if (status == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(uint32_t *)(&g_CardSlot_Flags + match_count * 0x5b20 + slot_idx * 0x120) =
             *(uint32_t *)(&g_CardSlot_Flags + match_count * 0x5b20 + slot_idx * 0x120) | 0x10;
      }
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120 +
       *(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20] = 0;
    }
  }
  return 0;
}

/*
 * Card_LeyDruid_UntapLand
 * Purpose: Activate Ley Druid ability (tap: untap target land).
 * Procedure:
 * 1. Validate target tapped land.
 * 2. Untap target land.
 */
/*
 * Decompiled function: Card_LeyDruid_UntapLand
 * Entry Point: 004e3e46
 * Size: 766 bytes
 */

int Card_LeyDruid_UntapLand(int player,int card_index,int event_code)

{
  int u_res;
  int val_result;
  uint32_t uval_3;
  uint32_t uval_4;
  uint32_t uval_5;
  int arg_11;
  int val_6;
  int arg_12;
  uint32_t uval_7;
  int arg_13;
  uint32_t uval_8;
  int arg_14;
  uint32_t uVar9;
  int arg_15;
  uint32_t uVar10;
  int arg_16;
  uint32_t uVar11;
  int arg_17;
  uint8_t *arg_18;
  int arg_18_00;
  int arg_19;
  int *arg_20;
  int match_count;
  int slot_idx;
  
  if (event_code == 0x73) {
    if ((*(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) & 0x20010) == 0) {
      arg_19 = 0;
      arg_18_00 = 0;
      arg_17 = 0;
      arg_16 = 0xffffffff;
      arg_15 = 0xffffffff;
      arg_14 = 0xffffffff;
      arg_13 = 0xffffffff;
      arg_12 = 0;
      arg_11 = 0;
      u_res = Card_GetColorAndTypeFlags(player,card_index);
      val_result = UI_PaintBigCardInfo((int *)0x0,0,player,2,2,0x200,1,0,0,u_res,arg_11,arg_12,arg_13,arg_14,
                           arg_15,arg_16,arg_17,arg_18_00,arg_19);
      if (val_result != 0) {
        return 1;
      }
    }
  }
  else if (event_code == 0x90) {
    Ai_GetOpponentPlayerScore(0);
  }
  else {
    if (event_code == 0x6d) {
      Pic_Subsystem_00424500(s_prompts_txt_0052ef7c,s_LEY_DRUID_0052ef70);
      arg_20 = &match_count;
      u_res = 1;
      arg_18 = &g_OverworldGoldAmount;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      val_6 = -1;
      val_result = -1;
      uval_5 = 0;
      uval_4 = 0;
      uval_3 = Card_GetColorAndTypeFlags(player,card_index);
      val_result = Duel_ChooseTarget
                        (player,2,player,0x200,1,0,0,uval_3,uval_4,uval_5,val_result,val_6,uval_7,uval_8,
                         uVar9,uVar10,uVar11,arg_18,u_res,arg_20);
      if (val_result == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) | 0x10;
        *(int *)(&g_CardSlot_CombatTarget + card_index * 0x120 + player * 0x5b20) = match_count;
        *(int *)(&g_CardSlot_AttachedAura + card_index * 0x120 + player * 0x5b20) = slot_idx;
        (&g_CardSlot_TurnPlayed)[card_index * 0x120 + player * 0x5b20] = 1;
      }
    }
    if (event_code == 0x72) {
      match_count = *(int *)(&g_CardSlot_CombatTarget + card_index * 0x120 + player * 0x5b20);
      slot_idx = *(int *)(&g_CardSlot_AttachedAura + card_index * 0x120 + player * 0x5b20);
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      val_6 = -1;
      val_result = -1;
      uval_5 = 0;
      uval_4 = 0;
      uval_3 = Card_GetColorAndTypeFlags(player,card_index);
      val_result = Rules_ParseFilter_0040360b
                        (match_count,slot_idx,(char *)0x0,player,2,2,0x200,1,0,0,uval_3,uval_4,uval_5,
                         val_result,val_6,uval_7,uval_8,uVar9,uVar10,uVar11);
      if (val_result == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(uint32_t *)(&g_CardSlot_Flags + match_count * 0x5b20 + slot_idx * 0x120) =
             *(uint32_t *)(&g_CardSlot_Flags + match_count * 0x5b20 + slot_idx * 0x120) & 0xffffffef;
        Magic_TriggerCardEvent(match_count,slot_idx,1,0xffffffff,0xffffffff);
      }
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120] = 0;
    }
  }
  return 0;
}

/*
 * Card_LeyDruid_AiEvaluateLand
 * Purpose: Calculate AI tactical score for untapping target land.
 * Procedure:
 * 1. Evaluate mana generation advantage.
 */
/*
 * Decompiled function: Card_LeyDruid_AiEvaluateLand
 * Entry Point: 004e4144
 * Size: 355 bytes
 */

uint32_t Card_LeyDruid_AiEvaluateLand(int player,int card_index,int event_code)

{
  uint32_t u_res;
  int slot_idx;
  
  if (event_code == 0x73) {
    if ((*(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) & 0x20010) == 0) {
      if (player == g_CurrentTurnPhase) {
        u_res = (DAT_006a282c | g_PlayerPoisonCounters) & 0x40;
      }
      else {
        u_res = (&g_PlayerPoisonCounters)[g_CurrentTurnPhase] & 0x40;
      }
    }
    else {
      u_res = 0;
    }
  }
  else if (event_code == 0x90) {
    Ai_GetOpponentPlayerScore(0);
    u_res = 0;
  }
  else {
    if (event_code == 0x6d) {
      if (slot_idx == -1) {
        g_ActivePlayer = 1;
      }
      else {
        *(uint32_t *)(&g_CardSlot_Flags +
                 *(int *)(&g_CardSlot_AttachedAura + card_index * 0x120 + player * 0x5b20) * 0x120 +
                 *(int *)(&g_CardSlot_CombatTarget + card_index * 0x120 + player * 0x5b20) * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_Flags +
                      *(int *)(&g_CardSlot_AttachedAura + card_index * 0x120 + player * 0x5b20) * 0x120 +
                      *(int *)(&g_CardSlot_CombatTarget + card_index * 0x120 + player * 0x5b20) * 0x5b20)
             | 0x10;
        (&g_CardSlot_Toughness)[card_index * 0x120 + player * 0x5b20] = g_TemporaryToughnessBuffer;
        *(int *)(&g_CardSlot_OriginalCardId + card_index * 0x120 + player * 0x5b20) = slot_idx;
      }
    }
    u_res = 0;
  }
  return u_res;
}

/*
 * Card_LeyDruid_ExecuteUntap
 * Purpose: Execute untap action on chosen land.
 * Procedure:
 * 1. Clear STATUS_TAPPED flag on land slot.
 */
/*
 * Decompiled function: Card_LeyDruid_ExecuteUntap
 * Entry Point: 004e42ac
 * Size: 604 bytes
 */

int Card_LeyDruid_ExecuteUntap(int player,int card_index,int event_code)

{
  int status;
  
  if (((event_code == 0x6c) && (card_index == g_EventSourceSlot)) && (player == g_EventSourcePlayer)) {
    status = CardTarget_PromptTargetCreature(player,0xffffffff,card_index);
    if (status == 0) {
      Pic_Subsystem_0044867e(player,card_index,1);
      g_ActivePlayer = 1;
    }
  }
  if ((event_code == 0x71) &&
     (*(int *)(&g_CardSlot_OriginalCardId + card_index * 0x120 + player * 0x5b20) != -1)) {
    (&g_CardSlot_Toughness)[card_index * 0x120 + player * 0x5b20] =
         (&g_CardSlot_CombatTarget)[card_index * 0x120 + player * 0x5b20];
    *(int *)(&g_CardSlot_OriginalCardId + card_index * 0x120 + player * 0x5b20) =
         *(int *)(&g_CardSlot_AttachedAura + card_index * 0x120 + player * 0x5b20);
    *(int *)(&g_CardSlot_CardId + card_index * 0x120 + player * 0x5b20) =
         *(int *)
          (&g_CardSlot_CardId +
          *(int *)(&g_CardSlot_OriginalCardId + card_index * 0x120 + player * 0x5b20) * 0x120 +
          (char)(&g_CardSlot_Toughness)[card_index * 0x120 + player * 0x5b20] * 0x5b20);
    (&g_CardSlot_PlusOneCounters)[card_index * 0x120 + player * 0x5b20] =
         (&g_MasterCardColorTable)[*(int *)(&g_CardSlot_CardId + card_index * 0x120 + player * 0x5b20) * 0x34];
    *(int *)(&g_CardSlot_OriginalCardId + card_index * 0x120 + player * 0x5b20) = 0xffffffff;
    (&g_CardSlot_Toughness)[card_index * 0x120 + player * 0x5b20] =
         (&g_CardSlot_OriginalCardId)[card_index * 0x120 + player * 0x5b20];
    Magic_TriggerCardEvent(player,card_index,0x6c,1 - player,0xffffffff);
  }
  return 0;
}

/*
 * Card_HurkylsRecall_PickArtifact
 * Purpose: Prompt player to select target player for Hurkyl's Recall.
 * Procedure:
 * 1. Display player target selector.
 */
/*
 * Decompiled function: Card_HurkylsRecall_PickArtifact
 * Entry Point: 004e4508
 * Size: 582 bytes
 */

void Card_HurkylsRecall_PickArtifact(int player,int card_index,int event_code)

{
  int status;
  int slot_idx;
  
  if (event_code == 0x73) {
    if ((*(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) & 0x20010) == 0) {
      Font_DrawString(player,5,2);
    }
  }
  else if (((event_code == 0x6d) && (status = Font_DrawString(player,5,2), status != 0)) &&
          (Ai_CalcManaRequirement_004ba890(player,5,2), g_ActivePlayer != 1)) {
    if ((player == g_CurrentTurnPhase) && (g_IsAiThinking != 1)) {
      do {
        slot_idx = UI_DeckSelectionMenu(player,(int)(&g_PlayerGraveyardList + player * 2000),500,
                                    s_Pick_an_artifact_0052ef90,0);
        if (slot_idx == -1) break;
      } while (((&g_MasterCardColorTable)
                [*(int *)(&g_PlayerGraveyardList + slot_idx * 4 + player * 2000) * 0x34] & 0x40) == 0);
    }
    else {
      slot_idx = FUN_004fd9c0(player,0x40);
    }
    if (((slot_idx == -1) || (*(int *)(&g_PlayerGraveyardList + slot_idx * 4 + player * 2000) == -1)) ||
       (((&g_MasterCardColorTable)[*(int *)(&g_PlayerGraveyardList + slot_idx * 4 + player * 2000) * 0x34] &
        0x40) == 0)) {
      g_ActivePlayer = 1;
    }
    else {
      status = Deck_AddCardToDeck(player,*(int *)(&g_PlayerGraveyardList + slot_idx * 4 + player * 2000));
      if (status != -1) {
        *(int *)(&g_PlayerGraveyardList + slot_idx * 4 + player * 2000) = 0xffffffff;
      }
    }
    if (g_ActivePlayer != 1) {
      *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) | 0x10;
    }
  }
  return;
}

/*
 * Card_HurkylsRecall_ReturnAllArtifacts
 * Purpose: Return all artifacts owned by target player to hand.
 * Procedure:
 * 1. Iterate all artifacts controlled by target player.
 * 2. Move artifacts to owner hand.
 */
/*
 * Decompiled function: Card_HurkylsRecall_ReturnAllArtifacts
 * Entry Point: 004e474e
 * Size: 185 bytes
 */

void Card_HurkylsRecall_ReturnAllArtifacts(int player,int card_index,int event_code)

{
  int status;
  
  if ((event_code != 0x73) && (event_code == 0x6d)) {
    status = CardTarget_HasValidPlayerOrCreatureTarget(player);
    if (status == 0) {
      g_ActivePlayer = 1;
    }
    else {
      Magic_ExecuteDrawPhase(player);
    }
    *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) =
         *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) | 0x10;
  }
  return;
}

/*
 * Card_Venom_DestroyCombatBlocker
 * Purpose: Attach Venom aura to creature and setup combat destroy trigger.
 * Procedure:
 * 1. Validate target creature.
 * 2. Attach Venom aura.
 */
/*
 * Decompiled function: Card_Venom_DestroyCombatBlocker
 * Entry Point: 004e4807
 * Size: 1959 bytes
 */

int Card_Venom_DestroyCombatBlocker(int player,int card_index,int event_code)

{
  char c_res;
  int u_temp;
  int temp_idx;
  uint32_t arg_11;
  int arg_11_00;
  uint32_t arg_12;
  int arg_12_00;
  uint32_t arg_13;
  int arg_13_00;
  int arg_14;
  int val_4;
  int arg_15;
  uint32_t arg_16;
  int arg_16_00;
  uint32_t arg_17;
  int arg_17_00;
  uint32_t arg_18;
  int arg_18_00;
  uint32_t arg_19;
  int arg_19_00;
  uint32_t arg_20;
  int target_idx;
  int card_idx;
  
  if (((event_code == 0x3c) &&
      (*(int *)(&g_CardSlot_OriginalCardId + player * 0x5b20 + card_index * 0x120) != -1)) &&
     ((&g_CardSlot_Toughness)[player * 0x5b20 + card_index * 0x120] != -1)) {
    (&DAT_006a604f)
    [*(int *)(&g_CardSlot_OriginalCardId + player * 0x5b20 + card_index * 0x120) * 0x120 +
     (char)(&g_CardSlot_Toughness)[player * 0x5b20 + card_index * 0x120] * 0x5b20] =
         (&DAT_006a604f)
         [*(int *)(&g_CardSlot_OriginalCardId + player * 0x5b20 + card_index * 0x120) * 0x120 +
          (char)(&g_CardSlot_Toughness)[player * 0x5b20 + card_index * 0x120] * 0x5b20] | 0x3f;
  }
  if (event_code == 0x74) {
    arg_19_00 = 0;
    arg_18_00 = 0;
    arg_17_00 = 0;
    arg_16_00 = 0xffffffff;
    arg_15 = 0xffffffff;
    arg_14 = 0xffffffff;
    arg_13_00 = 0xffffffff;
    arg_12_00 = 0;
    arg_11_00 = 0;
    u_temp = Card_GetColorAndTypeFlags(player,card_index);
    u_temp = UI_PaintBigCardInfo((int *)0x0,0,player,2,2,0x200,2,0,0,u_temp,arg_11_00,arg_12_00,arg_13_00,
                         arg_14,arg_15,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
  }
  else if (event_code == 0x90) {
    Ai_GetOpponentPlayerScore(0);
    u_temp = 0;
  }
  else {
    if (((event_code == 0x6c) && (card_index == g_EventSourceSlot)) &&
       (player == g_EventSourcePlayer)) {
      Pic_Subsystem_00424500(s_prompts_txt_0052efac,s_VENOM_0052efa4);
      temp_idx = CardTarget_PromptTargetCreature(player,player,card_index);
      if (temp_idx == 0) {
        g_ActivePlayer = 1;
      }
    }
    if (event_code == 0x71) {
      arg_20 = 0;
      arg_19 = 0;
      arg_18 = 0;
      arg_17 = 0xffffffff;
      arg_16 = 0xffffffff;
      val_4 = -1;
      temp_idx = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = Card_GetColorAndTypeFlags(player,card_index);
      temp_idx = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + player * 0x5b20 + card_index * 0x120),
                         *(int *)(&g_CardSlot_AttachedAura + player * 0x5b20 + card_index * 0x120),
                         (char *)0x0,player,2,2,0x200,2,0,0,arg_11,arg_12,arg_13,temp_idx,val_4,
                         arg_16,arg_17,arg_18,arg_19,arg_20);
      if (temp_idx == 0) {
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[player * 0x5b20 + card_index * 0x120] =
             (&g_CardSlot_CombatTarget)[player * 0x5b20 + card_index * 0x120];
        *(int *)(&g_CardSlot_OriginalCardId + player * 0x5b20 + card_index * 0x120) =
             *(int *)(&g_CardSlot_AttachedAura + player * 0x5b20 + card_index * 0x120);
      }
      (&g_CardSlot_TurnPlayed)[player * 0x5b20 + card_index * 0x120] = 0;
    }
    if (event_code == 0x1a) {
      temp_idx = 1 - (char)(&g_CardSlot_Toughness)[player * 0x5b20 + card_index * 0x120];
      if (((char)(&g_CardSlot_Toughness)[player * 0x5b20 + card_index * 0x120] == g_TurnPlayer
          ) && (((&g_CardSlot_Flags)
                 [*(int *)(&g_CardSlot_OriginalCardId + player * 0x5b20 + card_index * 0x120) *
                  0x120 + (char)(&g_CardSlot_Toughness)[player * 0x5b20 + card_index * 0x120] *
                          0x5b20] & 0x44) != 0)) {
        if ((&g_CardSlot_ColorMask)
            [*(int *)(&g_CardSlot_OriginalCardId + player * 0x5b20 + card_index * 0x120) * 0x120 +
             (char)(&g_CardSlot_Toughness)[player * 0x5b20 + card_index * 0x120] * 0x5b20] == -1) {
          target_idx = *(int *)(&g_CardSlot_OriginalCardId + player * 0x5b20 + card_index * 0x120);
        }
        else {
          target_idx = (int)(char)(&g_CardSlot_ColorMask)
                                [*(int *)(&g_CardSlot_OriginalCardId +
                                         player * 0x5b20 + card_index * 0x120) * 0x120 +
                                 (char)(&g_CardSlot_Toughness)
                                       [player * 0x5b20 + card_index * 0x120] * 0x5b20];
        }
        for (card_idx = 0; card_idx < (int)(&g_PlayerActiveCardCount)[temp_idx];
            card_idx = card_idx + 1) {
          if ((((char)(&g_CardSlot_ColorMask)[temp_idx * 0x5b20 + card_idx * 0x120] == target_idx) &&
              ((&g_MasterCardRarityTable)
               [*(int *)(&g_CardSlot_CardId + temp_idx * 0x5b20 + card_idx * 0x120) * 0x34] != '\0'))
             && (((&g_MasterCardColorTable)
                  [*(int *)(&g_CardSlot_CardId + temp_idx * 0x5b20 + card_idx * 0x120) * 0x34] & 2) !=
                 0)) {
            Card_ApplyTriggerEffect(player,card_index,DAT_006a48e4,temp_idx,card_idx);
          }
        }
      }
      if (((char)(&g_CardSlot_Toughness)[player * 0x5b20 + card_index * 0x120] != g_TurnPlayer
          ) && ((&g_CardSlot_ColorMask)
                [*(int *)(&g_CardSlot_OriginalCardId + player * 0x5b20 + card_index * 0x120) *
                 0x120 + (char)(&g_CardSlot_Toughness)[player * 0x5b20 + card_index * 0x120] *
                         0x5b20] != -1)) {
        c_res = (&g_CardSlot_ColorMask)
                [temp_idx * 0x5b20 +
                 (char)(&g_CardSlot_ColorMask)
                       [*(int *)(&g_CardSlot_OriginalCardId + player * 0x5b20 + card_index * 0x120)
                        * 0x120 + (char)(&g_CardSlot_Toughness)
                                        [player * 0x5b20 + card_index * 0x120] * 0x5b20] * 0x120];
        if (c_res == -1) {
          Card_ApplyTriggerEffect(player,card_index,DAT_006a48e4,temp_idx,
                       (int)(char)(&g_CardSlot_ColorMask)
                                  [*(int *)(&g_CardSlot_OriginalCardId +
                                           player * 0x5b20 + card_index * 0x120) * 0x120 +
                                   (char)(&g_CardSlot_Toughness)
                                         [player * 0x5b20 + card_index * 0x120] * 0x5b20]);
        }
        else {
          for (card_idx = 0; card_idx < (int)(&g_PlayerActiveCardCount)[temp_idx];
              card_idx = card_idx + 1) {
            val_4 = Card_IsTapped(temp_idx,card_idx);
            if ((val_4 != 0) &&
               ((&g_CardSlot_ColorMask)[temp_idx * 0x5b20 + card_idx * 0x120] == c_res)) {
              Card_ApplyTriggerEffect(player,card_index,DAT_006a48e4,temp_idx,card_idx);
            }
          }
        }
      }
    }
    u_temp = 0;
  }
  return u_temp;
}

/*
 * Card_Venom_AttachToCreature
 * Purpose: Assign Venom aura link to enchanted creature slot.
 * Procedure:
 * 1. Store aura target relationship.
 */
/*
 * Decompiled function: Card_Venom_AttachToCreature
 * Entry Point: 004e4fae
 * Size: 992 bytes
 */

int Card_Venom_AttachToCreature(int player,int card_index,int event_code)

{
  char c_res;
  int player;
  int val_result;
  int target_idx;
  int card_idx;
  
  if (event_code == 0x3c) {
    (&DAT_006a604f)[player * 0x5b20 + card_index * 0x120] =
         (&DAT_006a604f)[player * 0x5b20 + card_index * 0x120] | 0x3f;
  }
  if (event_code == 0x1a) {
    player = 1 - player;
    if ((player == g_TurnPlayer) &&
       (((&g_CardSlot_Flags)[player * 0x5b20 + card_index * 0x120] & 0x44) != 0)) {
      if ((&g_CardSlot_ColorMask)[player * 0x5b20 + card_index * 0x120] == -1) {
        target_idx = card_index;
      }
      else {
        target_idx = (int)(char)(&g_CardSlot_ColorMask)[player * 0x5b20 + card_index * 0x120];
      }
      for (card_idx = 0; card_idx < (int)(&g_PlayerActiveCardCount)[player]; card_idx = card_idx + 1)
      {
        if ((((char)(&g_CardSlot_ColorMask)[player * 0x5b20 + card_idx * 0x120] == target_idx) &&
            ((&g_MasterCardRarityTable)[*(int *)(&g_CardSlot_CardId + player * 0x5b20 + card_idx * 0x120) * 0x34]
             != '\0')) &&
           (((&g_MasterCardColorTable)
             [*(int *)(&g_CardSlot_CardId + player * 0x5b20 + card_idx * 0x120) * 0x34] & 2) != 0)) {
          Card_ApplyTriggerEffect(player,card_index,DAT_006a48e4,player,card_idx);
        }
      }
    }
    if ((player != g_TurnPlayer) &&
       ((&g_CardSlot_ColorMask)[player * 0x5b20 + card_index * 0x120] != -1)) {
      c_res = (&g_CardSlot_ColorMask)
              [player * 0x5b20 + (char)(&g_CardSlot_ColorMask)[player * 0x5b20 + card_index * 0x120] * 0x120
              ];
      if (c_res == -1) {
        if (((&g_MasterCardRarityTable)
             [*(int *)(&g_CardSlot_CardId +
                      player * 0x5b20 +
                      (char)(&g_CardSlot_ColorMask)[player * 0x5b20 + card_index * 0x120] * 0x120) * 0x34]
             != '\0') &&
           (((&g_MasterCardColorTable)
             [*(int *)(&g_CardSlot_CardId +
                      player * 0x5b20 +
                      (char)(&g_CardSlot_ColorMask)[player * 0x5b20 + card_index * 0x120] * 0x120) * 0x34]
            & 2) != 0)) {
          Card_ApplyTriggerEffect(player,card_index,DAT_006a48e4,player,
                       (int)(char)(&g_CardSlot_ColorMask)[player * 0x5b20 + card_index * 0x120]);
        }
      }
      else {
        for (card_idx = 0; card_idx < (int)(&g_PlayerActiveCardCount)[player]; card_idx = card_idx + 1
            ) {
          val_result = Card_IsTapped(player,card_idx);
          if (((val_result != 0) && ((&g_CardSlot_ColorMask)[player * 0x5b20 + card_idx * 0x120] == c_res))
             && (((&g_MasterCardRarityTable)
                  [*(int *)(&g_CardSlot_CardId + player * 0x5b20 + card_idx * 0x120) * 0x34] != '\0'
                 && (((&g_MasterCardColorTable)
                      [*(int *)(&g_CardSlot_CardId + player * 0x5b20 + card_idx * 0x120) * 0x34] & 2)
                     != 0)))) {
            Card_ApplyTriggerEffect(player,card_index,DAT_006a48e4,player,card_idx);
          }
        }
      }
    }
  }
  return 0;
}

/*
 * Card_Venom_CombatDamageTrigger
 * Purpose: Mark combat opponents damaged by Venom creature for destruction.
 * Procedure:
 * 1. Set pending destroy flag on combat blockers.
 */
/*
 * Decompiled function: Card_Venom_CombatDamageTrigger
 * Entry Point: 004e538e
 * Size: 583 bytes
 */

int Card_Venom_CombatDamageTrigger(int player,int card_index,int event_code)

{
  char c_res;
  int player;
  int val_result;
  int match_count;
  
  if ((((event_code == 0x1a) && (player = 1 - player, player != g_TurnPlayer)) &&
      ((&g_CardSlot_ColorMask)[card_index * 0x120 + player * 0x5b20] != -1)) &&
     (*(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) == 0)) {
    *(uint32_t *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) =
         *(uint32_t *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) | 1;
    c_res = (&g_CardSlot_ColorMask)
            [player * 0x5b20 + (char)(&g_CardSlot_ColorMask)[card_index * 0x120 + player * 0x5b20] * 0x120];
    if (c_res == -1) {
      Card_ApplyTriggerEffect(player,card_index,DAT_006b2d84,player,
                   (int)(char)(&g_CardSlot_ColorMask)[card_index * 0x120 + player * 0x5b20]);
      *(uint32_t *)(&g_CardSlot_Abilities1 +
               player * 0x5b20 + (char)(&g_CardSlot_ColorMask)[card_index * 0x120 + player * 0x5b20] * 0x120
               ) = *(uint32_t *)(&g_CardSlot_Abilities1 +
                            player * 0x5b20 +
                            (char)(&g_CardSlot_ColorMask)[card_index * 0x120 + player * 0x5b20] * 0x120) |
                   0x8000;
    }
    else {
      for (match_count = 0; match_count < (int)(&g_PlayerActiveCardCount)[player]; match_count = match_count + 1) {
        val_result = Card_IsTapped(player,match_count);
        if ((val_result != 0) && ((&g_CardSlot_ColorMask)[match_count * 0x120 + player * 0x5b20] == c_res)) {
          Card_ApplyTriggerEffect(player,card_index,DAT_006b2d84,player,match_count);
          *(uint32_t *)(&g_CardSlot_Abilities1 + match_count * 0x120 + player * 0x5b20) =
               *(uint32_t *)(&g_CardSlot_Abilities1 + match_count * 0x120 + player * 0x5b20) | 0x8000;
        }
      }
    }
  }
  if (event_code == 0x22) {
    *(int *)(&g_CardSlot_ConvertedManaCost + card_index * 0x120 + player * 0x5b20) = 0;
  }
  return 0;
}

/*
 * Card_Venom_DestroyAtEndOfCombat
 * Purpose: Destroy all creatures marked by Venom at end of combat.
 * Procedure:
 * 1. Destroy marked combat creatures.
 */
/*
 * Decompiled function: Card_Venom_DestroyAtEndOfCombat
 * Entry Point: 004e55d5
 * Size: 568 bytes
 */

int Card_Venom_DestroyAtEndOfCombat(int player,int card_index,int event_code)

{
  char c_res;
  int player;
  int val_result;
  int card_idx;
  
  player = 1 - player;
  if (((event_code == 0x77) && (card_index == g_EventSourceSlot)) && (player == g_EventSourcePlayer)) {
    if ((player == g_TurnPlayer) &&
       (((&g_CardSlot_Flags)[card_index * 0x120 + player * 0x5b20] & 0x44) != 0)) {
      for (card_idx = 0; card_idx < 0x50; card_idx = card_idx + 1) {
        if (((char)(&g_CardSlot_ColorMask)[card_idx * 0x120 + player * 0x5b20] == card_index) &&
           (((&g_MasterCardColorTable)
             [*(int *)(&g_CardSlot_CardId + card_idx * 0x120 + player * 0x5b20) * 0x34] & 2) != 0)) {
          Pic_Subsystem_0044867e(player,card_idx,4);
        }
      }
    }
    if ((player != g_TurnPlayer) &&
       ((&g_CardSlot_ColorMask)[card_index * 0x120 + player * 0x5b20] != -1)) {
      c_res = (&g_CardSlot_ColorMask)
              [player * 0x5b20 + (char)(&g_CardSlot_ColorMask)[card_index * 0x120 + player * 0x5b20] * 0x120
              ];
      if (c_res == -1) {
        Pic_Subsystem_0044867e
                  (player,(int)(char)(&g_CardSlot_ColorMask)[card_index * 0x120 + player * 0x5b20],4);
      }
      else {
        for (card_idx = 0; card_idx < 0x50; card_idx = card_idx + 1) {
          val_result = Card_IsTapped(player,card_idx);
          if ((val_result != 0) && ((&g_CardSlot_ColorMask)[card_idx * 0x120 + player * 0x5b20] == c_res))
          {
            Pic_Subsystem_0044867e(player,card_idx,4);
          }
        }
      }
    }
  }
  return 0;
}

/*
 * Card_Venom_AiEvaluateAura
 * Purpose: Calculate AI tactical score for casting Venom on target creature.
 * Procedure:
 * 1. Evaluate combat advantage.
 */
/*
 * Decompiled function: Card_Venom_AiEvaluateAura
 * Entry Point: 004e580d
 * Size: 287 bytes
 */

bool Card_Venom_AiEvaluateAura(int player,int card_index,int event_code)

{
  bool is_valid;
  
  if (event_code == 0x73) {
    is_valid = (*(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) & 0x20010) == 0;
  }
  else {
    if ((event_code == 0x6d) && (((&g_CardSlot_Flags)[card_index * 0x120 + player * 0x5b20] & 0x10) == 0)) {
      FUN_0040d901(player,4,1);
      *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) | 0x10;
      g_PendingAttackersTargetSlot = 4;
    }
    if ((((event_code == 0x7f) && (card_index == g_EventSourceSlot)) && (player == g_EventSourcePlayer))
       && ((*(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) & 0x20010) == 0)) {
      FUN_0040d7e9(player,4,1);
    }
    is_valid = false;
  }
  return is_valid;
}

/*
 * Card_Venom_AiCastScore
 * Purpose: Determine AI mana allocation priority for Venom.
 * Procedure:
 * 1. Calculate casting priority.
 */
/*
 * Decompiled function: Card_Venom_AiCastScore
 * Entry Point: 004e592c
 * Size: 269 bytes
 */

int Card_Venom_AiCastScore(int player,int card_index,int event_code)

{
  int status;
  int u_temp;
  
  if (event_code == 0x73) {
    if (((*(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) & 0x20010) == 0) &&
       (status = Font_DrawString(player,2,1), status != 0)) {
      u_temp = 1;
    }
    else {
      u_temp = 0;
    }
  }
  else {
    if ((((event_code == 0x6d) && (((&g_CardSlot_Flags)[card_index * 0x120 + player * 0x5b20] & 0x10) == 0)) &&
        (status = Font_DrawString(player,2,1), status != 0)) &&
       (Ai_CalcManaRequirement_004ba890(player,2,1), g_ActivePlayer != 1)) {
      FUN_0040d901(player,0,3);
      *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) | 0x10;
      g_PendingAttackersTargetSlot = 0;
    }
    u_temp = 0;
  }
  return u_temp;
}

/*
 * Card_Venom_ClearAuraFlags
 * Purpose: Clear Venom combat tracking flags at end of turn.
 * Procedure:
 * 1. Reset temporary combat markers.
 */
/*
 * Decompiled function: Card_Venom_ClearAuraFlags
 * Entry Point: 004e5a39
 * Size: 1026 bytes
 */

int Card_Venom_ClearAuraFlags(int player,int card_index,int event_code)

{
  char c_res;
  uint8_t is_match;
  uint8_t flag_3;
  uint8_t bVar4;
  int player;
  int val_5;
  uint32_t uval_6;
  int color_idx;
  int player_idx;
  
  player = 1 - player;
  if (event_code == 0x3c) {
    bVar4 = (&DAT_006a604f)[card_index * 0x120 + player * 0x5b20];
    is_match = Card_SetTapState(player,card_index,3);
    flag_3 = Card_SetTapState(player,card_index,5);
    (&DAT_006a604f)[card_index * 0x120 + player * 0x5b20] =
         bVar4 | (uint8_t)(1 << (is_match & 0x1f)) | (uint8_t)(1 << (flag_3 & 0x1f)) | 0x80;
  }
  if (event_code == 0x1a) {
    bVar4 = Card_SetTapState(player,card_index,3);
    is_match = Card_SetTapState(player,card_index,5);
    uval_6 = 1 << (bVar4 & 0x1f) | 1 << (is_match & 0x1f);
    if ((player == g_TurnPlayer) &&
       (((&g_CardSlot_Flags)[card_index * 0x120 + player * 0x5b20] & 0x44) != 0)) {
      if ((&g_CardSlot_ColorMask)[card_index * 0x120 + player * 0x5b20] == -1) {
        color_idx = card_index;
      }
      else {
        color_idx = (int)(char)(&g_CardSlot_ColorMask)[card_index * 0x120 + player * 0x5b20];
      }
      for (player_idx = 0; player_idx < (int)(&g_PlayerActiveCardCount)[player]; player_idx = player_idx + 1)
      {
        if ((((char)(&g_CardSlot_ColorMask)[player_idx * 0x120 + player * 0x5b20] == color_idx) &&
            (((&g_MasterCardColorTable)
              [*(int *)(&g_CardSlot_CardId + player_idx * 0x120 + player * 0x5b20) * 0x34] & 2) != 0))
           && ((uval_6 & (int)(char)(&g_CardSlot_MinusOneCounters)[player_idx * 0x120 + player * 0x5b20]) != 0)) {
          Card_ApplyTriggerEffect(player,card_index,DAT_006a48e4,player,player_idx);
        }
      }
    }
    if ((player != g_TurnPlayer) &&
       ((&g_CardSlot_ColorMask)[card_index * 0x120 + player * 0x5b20] != -1)) {
      c_res = (&g_CardSlot_ColorMask)
              [player * 0x5b20 + (char)(&g_CardSlot_ColorMask)[card_index * 0x120 + player * 0x5b20] * 0x120
              ];
      if (c_res == -1) {
        if ((uval_6 & (int)(char)(&g_CardSlot_MinusOneCounters)
                                [player * 0x5b20 +
                                 (char)(&g_CardSlot_ColorMask)[card_index * 0x120 + player * 0x5b20] *
                                 0x120]) != 0) {
          Card_ApplyTriggerEffect(player,card_index,DAT_006a48e4,player,
                       (int)(char)(&g_CardSlot_ColorMask)[card_index * 0x120 + player * 0x5b20]);
        }
      }
      else {
        for (player_idx = 0; player_idx < (int)(&g_PlayerActiveCardCount)[player]; player_idx = player_idx + 1
            ) {
          val_5 = Card_IsTapped(player,player_idx);
          if (((val_5 != 0) && ((&g_CardSlot_ColorMask)[player_idx * 0x120 + player * 0x5b20] == c_res))
             && ((uval_6 & (int)(char)(&g_CardSlot_MinusOneCounters)[player_idx * 0x120 + player * 0x5b20]) != 0)) {
            Card_ApplyTriggerEffect(player,card_index,DAT_006a48e4,player,player_idx);
          }
        }
      }
    }
  }
  return 0;
}

/*
 * Card_RadjanSpirit_RemoveFlying
 * Purpose: Activate Radjan Spirit ability (tap: target creature loses flying).
 * Procedure:
 * 1. Validate target creature with flying.
 * 2. Remove flying keyword flag until end of turn.
 */
/*
 * Decompiled function: Card_RadjanSpirit_RemoveFlying
 * Entry Point: 004e5e3b
 * Size: 875 bytes
 */

int Card_RadjanSpirit_RemoveFlying(int player,int card_index,int event_code)

{
  int u_res;
  int val_result;
  uint32_t uval_3;
  uint32_t uval_4;
  uint32_t uval_5;
  int arg_11;
  int val_6;
  int arg_12;
  uint32_t uval_7;
  int arg_13;
  uint32_t uval_8;
  int arg_14;
  uint32_t uVar9;
  int arg_15;
  uint32_t uVar10;
  int arg_16;
  uint32_t uVar11;
  int arg_17;
  uint8_t *arg_18;
  int arg_18_00;
  int arg_19;
  int *arg_20;
  int card_idx;
  int match_count;
  
  if (event_code == 0x73) {
    if ((*(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) & 0x20010) == 0) {
      arg_19 = 0;
      arg_18_00 = 0;
      arg_17 = 0;
      arg_16 = 0xffffffff;
      arg_15 = 0xffffffff;
      arg_14 = 0xffffffff;
      arg_13 = 0xffffffff;
      arg_12 = 0;
      arg_11 = 0;
      u_res = Card_GetColorAndTypeFlags(player,card_index);
      val_result = UI_PaintBigCardInfo((int *)0x0,0,player,2,2,0x200,2,0,0,u_res,arg_11,arg_12,arg_13,arg_14,
                           arg_15,arg_16,arg_17,arg_18_00,arg_19);
      if (val_result != 0) {
        return 1;
      }
    }
  }
  else if (event_code == 0x90) {
    Ai_GetOpponentPlayerScore(0);
  }
  else {
    if ((event_code == 0x6d) &&
       ((*(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) & 0x20010) == 0)) {
      Pic_Subsystem_00424500(s_prompts_txt_0052efc8,s_RADJAN_SPIRIT_0052efb8);
      arg_20 = &card_idx;
      u_res = 1;
      arg_18 = &g_OverworldGoldAmount;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      val_6 = -1;
      val_result = -1;
      uval_5 = 0;
      uval_4 = 0;
      uval_3 = Card_GetColorAndTypeFlags(player,card_index);
      val_result = Duel_ChooseTarget
                        (player,2,1 - player,0x200,2,0,0,uval_3,uval_4,uval_5,val_result,val_6,uval_7,
                         uval_8,uVar9,uVar10,uVar11,arg_18,u_res,arg_20);
      if (val_result == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + card_index * 0x120 + player * 0x5b20) = card_idx;
        *(int *)(&g_CardSlot_AttachedAura + card_index * 0x120 + player * 0x5b20) = match_count;
        (&g_CardSlot_TurnPlayed)[card_index * 0x120 + player * 0x5b20] = 1;
        *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) | 0x10;
      }
    }
    if (event_code == 0x72) {
      card_idx = *(int *)(&g_CardSlot_CombatTarget + card_index * 0x120 + player * 0x5b20);
      match_count = *(int *)(&g_CardSlot_AttachedAura + card_index * 0x120 + player * 0x5b20);
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      val_6 = -1;
      val_result = -1;
      uval_5 = 0;
      uval_4 = 0;
      uval_3 = Card_GetColorAndTypeFlags(player,card_index);
      val_result = Rules_ParseFilter_0040360b
                        (card_idx,match_count,(char *)0x0,player,2,2,0x200,2,0,0,uval_3,uval_4,uval_5,
                         val_result,val_6,uval_7,uval_8,uVar9,uVar10,uVar11);
      if (val_result == 0) {
        g_ActivePlayer = 1;
      }
      else {
        val_result = Card_ApplyTriggerEffect(g_DialogPromptHwnd,g_DuelArenaHwnd,DAT_006a28b8,card_idx,match_count);
        if (val_result != -1) {
          *(int *)(&g_CardSlot_ConvertedManaCost + val_result * 0x120 + player * 0x5b20) = 0x20;
        }
        *(int *)(&g_CardSlot_Abilities2 + card_idx * 0x5b20 + match_count * 0x120) = 0x8000000;
      }
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120] = 0;
    }
  }
  return 0;
}

/*
 * Card_HurrJackal_GrantCombatAbility
 * Purpose: Activate Hurr Jackal ability granting combat advantage.
 * Procedure:
 * 1. Validate target creature.
 * 2. Apply temporary combat keyword buff.
 */
/*
 * Decompiled function: Card_HurrJackal_GrantCombatAbility
 * Entry Point: 004e61a6
 * Size: 932 bytes
 */

int Card_HurrJackal_GrantCombatAbility(int player,int card_index,int event_code)

{
  int u_res;
  int val_result;
  uint32_t uval_3;
  uint32_t uval_4;
  uint32_t uval_5;
  int arg_11;
  int val_6;
  int arg_12;
  uint32_t uval_7;
  int arg_13;
  uint32_t uval_8;
  int arg_14;
  uint32_t uVar9;
  int arg_15;
  uint32_t uVar10;
  int arg_16;
  uint32_t uVar11;
  int arg_17;
  uint8_t *arg_18;
  int arg_18_00;
  int arg_19;
  int *arg_20;
  int card_idx;
  int match_count;
  
  if (event_code == 0x73) {
    if ((*(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) & 0x20010) == 0) {
      arg_19 = 0;
      arg_18_00 = 0;
      arg_17 = 0;
      arg_16 = 0xffffffff;
      arg_15 = 0xffffffff;
      arg_14 = 0xffffffff;
      arg_13 = 0xffffffff;
      arg_12 = 0;
      arg_11 = 0;
      u_res = Card_GetColorAndTypeFlags(player,card_index);
      val_result = UI_PaintBigCardInfo((int *)0x0,0,player,2,2,0x200,2,0,0,u_res,arg_11,arg_12,arg_13,arg_14,
                           arg_15,arg_16,arg_17,arg_18_00,arg_19);
      if (val_result != 0) {
        return 1;
      }
    }
  }
  else if (event_code == 0x90) {
    Ai_GetOpponentPlayerScore(0);
  }
  else {
    if ((event_code == 0x6d) &&
       ((*(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) & 0x20010) == 0)) {
      Pic_Subsystem_00424500(s_prompts_txt_0052efe0,s_HURR_JACKAL_0052efd4);
      arg_20 = &card_idx;
      u_res = 1;
      arg_18 = &g_OverworldGoldAmount;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      val_6 = -1;
      val_result = -1;
      uval_5 = 0;
      uval_4 = 0;
      uval_3 = Card_GetColorAndTypeFlags(player,card_index);
      val_result = Duel_ChooseTarget
                        (player,2,1 - player,0x200,2,0,0,uval_3,uval_4,uval_5,val_result,val_6,uval_7,
                         uval_8,uVar9,uVar10,uVar11,arg_18,u_res,arg_20);
      if (val_result == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + card_index * 0x120 + player * 0x5b20) = card_idx;
        *(int *)(&g_CardSlot_AttachedAura + card_index * 0x120 + player * 0x5b20) = match_count;
        (&g_CardSlot_TurnPlayed)[card_index * 0x120 + player * 0x5b20] = 1;
        *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_Flags + card_index * 0x120 + player * 0x5b20) | 0x10;
        if (((&DAT_006a5f6d)[card_idx * 0x5b20 + match_count * 0x120] & 2) == 0) {
          g_SpellStackDepth = g_SpellStackDepth + -0x30;
        }
        else {
          g_SpellStackDepth = g_SpellStackDepth + 0x18;
        }
      }
    }
    if (event_code == 0x72) {
      card_idx = *(int *)(&g_CardSlot_CombatTarget + card_index * 0x120 + player * 0x5b20);
      match_count = *(int *)(&g_CardSlot_AttachedAura + card_index * 0x120 + player * 0x5b20);
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      val_6 = -1;
      val_result = -1;
      uval_5 = 0;
      uval_4 = 0;
      uval_3 = Card_GetColorAndTypeFlags(player,card_index);
      val_result = Rules_ParseFilter_0040360b
                        (card_idx,match_count,(char *)0x0,player,2,2,0x200,2,0,0,uval_3,uval_4,uval_5,
                         val_result,val_6,uval_7,uval_8,uVar9,uVar10,uVar11);
      if (val_result == 0) {
        g_ActivePlayer = 1;
      }
      else {
        val_result = Card_ApplyTriggerEffect(g_DialogPromptHwnd,g_DuelArenaHwnd,DAT_006a4b64,card_idx,match_count);
        if (val_result != -1) {
          *(uint32_t *)(&g_CardSlot_Abilities1 + val_result * 0x120 + player * 0x5b20) =
               *(uint32_t *)(&g_CardSlot_Abilities1 + val_result * 0x120 + player * 0x5b20) | 0x800000;
          *(int *)(&g_CardSlot_Abilities2 + card_idx * 0x5b20 + match_count * 0x120) = 0x8000000;
        }
      }
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_TapState + card_index * 0x120 + player * 0x5b20) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + card_index * 0x120 + player * 0x5b20) * 0x120] = 0;
    }
  }
  return 0;
}


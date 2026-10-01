/*
 * sid/Minit.c - Reconstructed MicroProse Source Module
 * Program: MAGIC.EXE
 * Contained Functions: 154
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include "shandalar/shandalar.h"
/* Modular Shandalar Subsystem */

/*
 * Decompiled function: Engine_ReportFatalError
 * Entry Point: 00452793
 * Size: 41 bytes
 */


void Engine_ReportFatalError(char *player)

{
  AssertOrLog(0,0x523ee0,0x63e,player);
  return;
}



/*
 * Decompiled function: UI_DrawCombatBanner
 * Entry Point: 004527bc
 * Size: 80 bytes
 */


void UI_DrawCombatBanner(void)

{
  UI_PrepareCombatViewport();
  Surface_FillRect((int *)g_DisplaySurfaceScreen,200,0x3c,0xf0,0x118,0xbc);
  UI_DrawCombatString(s_COMBAT_00523f00,0x140,0xc4,0xff);
  return;
}



/*
 * Decompiled function: Ai_TriggerTurnPhaseEvaluation
 * Entry Point: 0045280c
 * Size: 27 bytes
 */


void Ai_TriggerTurnPhaseEvaluation(void)

{
  Ai_EvaluateTacticalPosition(g_CurrentTurnPhase,6);
  return;
}



/*
 * Decompiled function: Engine_CountActiveCreatures
 * Entry Point: 00452827
 * Size: 141 bytes
 */


int Engine_CountActiveCreatures(void)

{
  int match_count;
  int slot_idx;
  
  match_count = 0;
  for (slot_idx = 0; slot_idx < 0x80; slot_idx = slot_idx + 1) {
    if ((((*(uint32_t *)(&g_CardSlot_StatusFlags + slot_idx * 100) & 0xff01) == 1) &&
        (1 < *(int *)(&g_CardSlot_CreatureType + slot_idx * 100))) &&
       (*(int *)(&g_CardSlot_CreatureType + slot_idx * 100) < 4)) {
      match_count = match_count + 1;
    }
  }
  return match_count;
}



/*
 * Decompiled function: UI_DrawManaSymbolBox
 * Entry Point: 004528c0
 * Size: 494 bytes
 */


int32_t UI_DrawManaSymbolBox(int x,int y,int width,int height)

{
  int32_t uval_1;
  
  if ((width == 0x71) && (g_IsAiThinking != 1)) {
    Duel_PlaySoundById(height + 8);
  }
  if (width == 0x73) {
    if ((((&g_CardSlot_Flags)[y * 0x120 + x * 0x5b20] & 0x10) == 0) &&
       ((((&g_CardSlot_Subtypes)[y * 0x120 + x * 0x5b20] & 3) == 0 ||
        (((&g_MasterCardColorTable)[*(int *)(&g_CardSlot_CardId + y * 0x120 + x * 0x5b20) * 0x34] &
         2) == 0)))) {
      uval_1 = 1;
    }
    else {
      uval_1 = 0;
    }
  }
  else {
    if (width == 0x6d) {
      FUN_0040d901(x,height,1);
      *(uint32_t *)(&g_CardSlot_Flags + y * 0x120 + x * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_Flags + y * 0x120 + x * 0x5b20) | 0x10;
      g_PendingAttackersTargetSlot = height;
    }
    if (((width == 0x7f) && (g_EventSourceSlot == y)) && (x == g_EventSourcePlayer)) {
      if (((((&g_CardSlot_Subtypes)[y * 0x120 + x * 0x5b20] & 3) == 0) ||
          (((&g_MasterCardColorTable)[*(int *)(&g_CardSlot_CardId + y * 0x120 + x * 0x5b20) * 0x34]
           & 2) == 0)) && (((&g_CardSlot_Flags)[y * 0x120 + x * 0x5b20] & 0x10) == 0)) {
        FUN_0040d7e9(x,height,1);
      }
      *(uint32_t *)(&DAT_0063eed0 + x * 4) =
           *(uint32_t *)(&DAT_0063eed0 + x * 4) | 1 << ((uint8_t)height & 0x1f);
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: Minit_Subsystem_00452ab3
 * Entry Point: 00452ab3
 * Size: 38 bytes
 */


void Minit_Subsystem_00452ab3(int player_id,int card_slot,int event_type)

{
  UI_DrawManaSymbolBox(player,card_slot,arg_3,1);
  return;
}



/*
 * Decompiled function: Minit_Subsystem_00452ad9
 * Entry Point: 00452ad9
 * Size: 38 bytes
 */


void Minit_Subsystem_00452ad9(int player_id,int card_slot,int event_type)

{
  UI_DrawManaSymbolBox(player,card_slot,arg_3,2);
  return;
}



/*
 * Decompiled function: Minit_Subsystem_00452aff
 * Entry Point: 00452aff
 * Size: 38 bytes
 */


void Minit_Subsystem_00452aff(int player_id,int card_slot,int event_type)

{
  UI_DrawManaSymbolBox(player,card_slot,arg_3,3);
  return;
}



/*
 * Decompiled function: Minit_Subsystem_00452b25
 * Entry Point: 00452b25
 * Size: 38 bytes
 */


void Minit_Subsystem_00452b25(int player_id,int card_slot,int event_type)

{
  UI_DrawManaSymbolBox(player,card_slot,arg_3,4);
  return;
}



/*
 * Decompiled function: Minit_Subsystem_00452b4b
 * Entry Point: 00452b4b
 * Size: 38 bytes
 */


void Minit_Subsystem_00452b4b(int player_id,int card_slot,int event_type)

{
  UI_DrawManaSymbolBox(player,card_slot,arg_3,5);
  return;
}



/*
 * Decompiled function: Mana_Init_00452b71
 * Entry Point: 00452b71
 * Size: 779 bytes
 */


void Mana_Init_00452b71(int player_id,int card_slot,int event_type,int arg_4,int arg_5)

{
  char *char_ptr_1;
  char *str_4;
  int val_2;
  char *str_6;
  int match_count;
  int slot_idx;
  
  if (arg_3 == 1) {
    for (slot_idx = 0; slot_idx < 7; slot_idx = slot_idx + 1) {
      if ((1 << ((uint8_t)slot_idx & 0x1f) & (int)(char)(&g_CardSlot_PlusOneCounters)[card_slot * 0x120 + player * 0x5b20])
          != 0) {
        FUN_0040d7e9(player,slot_idx,1);
      }
    }
  }
  if (arg_3 == 0x71) {
    for (slot_idx = 0; slot_idx < 7; slot_idx = slot_idx + 1) {
      if ((1 << ((uint8_t)slot_idx & 0x1f) & (int)(char)(&g_CardSlot_PlusOneCounters)[card_slot * 0x120 + player * 0x5b20])
          != 0) {
        FUN_0040d510(player,slot_idx,1);
      }
    }
  }
  if ((arg_3 != 0x73) && (arg_3 == 0x6d)) {
    if ((arg_4 == g_AiCombatDamageAssigned) || (g_AiCombatDamageAssigned == 0)) {
      match_count = arg_4;
    }
    else if (arg_5 == g_AiCombatDamageAssigned) {
      match_count = arg_5;
    }
    else {
      strcpy(&g_OverworldWorldState,s_Which_mana__1__00523f08);
      char_ptr_1 = (char *)Mem_AllocOrFree_00473d7e(arg_4);
      strcat(&g_OverworldWorldState,char_ptr_1);
      strcat(&g_OverworldWorldState,&DAT_00523f18);
      char_ptr_1 = (char *)Mem_AllocOrFree_00473d7e(arg_5);
      strcat(&g_OverworldWorldState,char_ptr_1);
      str_6 = (char *)0x0;
      char_ptr_1 = (char *)Mem_AllocOrFree_00473d7e(arg_5);
      str_4 = (char *)Mem_AllocOrFree_00473d7e(arg_4);
      val_2 = Ai_Subsystem_004cc814
                        (player,s_Which_type_of_mana_to_produce__00523f20,0,str_4,char_ptr_1,str_6);
      if (val_2 == 0) {
        match_count = arg_4;
      }
      else {
        match_count = arg_5;
      }
    }
    FUN_0040d875(player,match_count,1);
    for (slot_idx = 0; slot_idx < 7; slot_idx = slot_idx + 1) {
      if ((1 << ((uint8_t)slot_idx & 0x1f) & (int)(char)(&g_CardSlot_PlusOneCounters)[card_slot * 0x120 + player * 0x5b20])
          != 0) {
        FUN_0040d82b(player,slot_idx,1);
      }
    }
    *(uint32_t *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) =
         *(uint32_t *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) | 0x10;
    g_PendingAttackersTargetSlot = match_count;
  }
  return;
}



/*
 * Decompiled function: Minit_Subsystem_00452e81
 * Entry Point: 00452e81
 * Size: 42 bytes
 */


int32_t Minit_Subsystem_00452e81(int player_id,int card_slot,int event_type)

{
  Mana_Init_00452b71(player,card_slot,arg_3,4,1);
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_00452eab
 * Entry Point: 00452eab
 * Size: 42 bytes
 */


int32_t Minit_Subsystem_00452eab(int player_id,int card_slot,int event_type)

{
  Mana_Init_00452b71(player,card_slot,arg_3,1,3);
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_00452ed5
 * Entry Point: 00452ed5
 * Size: 42 bytes
 */


int32_t Minit_Subsystem_00452ed5(int player_id,int card_slot,int event_type)

{
  Mana_Init_00452b71(player,card_slot,arg_3,4,5);
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_00452eff
 * Entry Point: 00452eff
 * Size: 42 bytes
 */


int32_t Minit_Subsystem_00452eff(int player_id,int card_slot,int event_type)

{
  Mana_Init_00452b71(player,card_slot,arg_3,5,3);
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_00452f29
 * Entry Point: 00452f29
 * Size: 42 bytes
 */


int32_t Minit_Subsystem_00452f29(int player_id,int card_slot,int event_type)

{
  Mana_Init_00452b71(player,card_slot,arg_3,5,1);
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_00452f53
 * Entry Point: 00452f53
 * Size: 42 bytes
 */


int32_t Minit_Subsystem_00452f53(int player_id,int card_slot,int event_type)

{
  Mana_Init_00452b71(player,card_slot,arg_3,3,4);
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_00452f7d
 * Entry Point: 00452f7d
 * Size: 42 bytes
 */


int32_t Minit_Subsystem_00452f7d(int player_id,int card_slot,int event_type)

{
  Mana_Init_00452b71(player,card_slot,arg_3,3,2);
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_00452fa7
 * Entry Point: 00452fa7
 * Size: 42 bytes
 */


int32_t Minit_Subsystem_00452fa7(int player_id,int card_slot,int event_type)

{
  Mana_Init_00452b71(player,card_slot,arg_3,2,5);
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_00452fd1
 * Entry Point: 00452fd1
 * Size: 42 bytes
 */


int32_t Minit_Subsystem_00452fd1(int player_id,int card_slot,int event_type)

{
  Mana_Init_00452b71(player,card_slot,arg_3,1,2);
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_00452ffb
 * Entry Point: 00452ffb
 * Size: 42 bytes
 */


int32_t Minit_Subsystem_00452ffb(int player_id,int card_slot,int event_type)

{
  Mana_Init_00452b71(player,card_slot,arg_3,2,4);
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_00453025
 * Entry Point: 00453025
 * Size: 716 bytes
 */


int32_t Minit_Subsystem_00453025(int player_id,int card_slot,int event_type)

{
  char cVar1;
  int val_2;
  int32_t uval_3;
  
  if (arg_3 == 1) {
    val_2 = Rules_CalculateManaCostReduction((&g_CardSlot_PlusOneCounters)[card_slot * 0x120 + player * 0x5b20]);
    uval_3 = UI_DrawManaSymbolBox(player,card_slot,1,val_2);
  }
  else {
    if (arg_3 == 0x71) {
      if (g_IsAiThinking != 1) {
        Duel_PlaySoundById(0x25);
      }
      if (player == g_CurrentTurnPhase) {
        cVar1 = Util_GetRandomNumber(5);
        (&g_CardSlot_PlusOneCounters)[card_slot * 0x120 + player * 0x5b20] = (char)(1 << (cVar1 + 1U & 0x1f));
      }
      else {
        (&g_CardSlot_PlusOneCounters)[card_slot * 0x120 + player * 0x5b20] = DAT_00679ed0;
      }
    }
    if (arg_3 == 0x73) {
      val_2 = Rules_CalculateManaCostReduction((&g_CardSlot_PlusOneCounters)[card_slot * 0x120 + player * 0x5b20]);
      uval_3 = UI_DrawManaSymbolBox(player,card_slot,0x73,val_2);
    }
    else if (arg_3 == 0x6d) {
      val_2 = Rules_CalculateManaCostReduction((&g_CardSlot_PlusOneCounters)[card_slot * 0x120 + player * 0x5b20]);
      uval_3 = UI_DrawManaSymbolBox(player,card_slot,0x6d,val_2);
    }
    else {
      if (arg_3 == 0x72) {
        if (g_IsAiThinking != 1) {
          Duel_PlaySoundById(0x25);
        }
        if (player == g_CurrentTurnPhase) {
          cVar1 = Util_GetRandomNumber(5);
          (&g_CardSlot_PlusOneCounters)
          [*(int *)(&g_CardSlot_TapState + card_slot * 0x120 + player * 0x5b20) * 0x5b20 +
           *(int *)(&g_CardSlot_SicknessState + card_slot * 0x120 + player * 0x5b20) * 0x120] =
               (char)(1 << (cVar1 + 1U & 0x1f));
        }
        else {
          (&g_CardSlot_PlusOneCounters)
          [*(int *)(&g_CardSlot_TapState + card_slot * 0x120 + player * 0x5b20) * 0x5b20 +
           *(int *)(&g_CardSlot_SicknessState + card_slot * 0x120 + player * 0x5b20) * 0x120] =
               DAT_00679ed0;
        }
      }
      if (arg_3 == 0x7f) {
        val_2 = Rules_CalculateManaCostReduction((&g_CardSlot_PlusOneCounters)[card_slot * 0x120 + player * 0x5b20]);
        uval_3 = UI_DrawManaSymbolBox(player,card_slot,0x7f,val_2);
      }
      else {
        uval_3 = 0;
      }
    }
  }
  return uval_3;
}



/*
 * Decompiled function: Mana_Init_004532f1
 * Entry Point: 004532f1
 * Size: 514 bytes
 */


int32_t Mana_Init_004532f1(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  int val_2;
  int player_idx;
  int card_idx;
  int match_count;
  int slot_idx;
  
  if (arg_3 == 1) {
    uval_1 = UI_DrawManaSymbolBox(player,card_slot,1,0);
  }
  else if (arg_3 == 0x73) {
    if ((((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) == 0) &&
       ((((&g_CardSlot_Subtypes)[card_slot * 0x120 + player * 0x5b20] & 3) == 0 ||
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId + card_slot * 0x120 + player * 0x5b20) * 0x34] & 2) == 0)))) {
      uval_1 = 1;
    }
    else {
      uval_1 = 0;
    }
  }
  else {
    if (arg_3 == 0x6d) {
      if (player == g_CurrentTurnPhase) {
        val_2 = Util_GetRandomNumber(5);
        card_idx = val_2 + 1;
      }
      else {
        slot_idx = -1;
        for (match_count = 1; match_count < 7; match_count = match_count + 1) {
          if (slot_idx < *(int *)(&DAT_006ff690 + match_count * 4 + player * 0x20)) {
            slot_idx = *(int *)(&DAT_006ff690 + match_count * 4 + player * 0x20);
            card_idx = match_count;
          }
        }
      }
      if (player == 1) {
        player_idx = card_idx;
      }
      else {
        player_idx = -1;
      }
      val_2 = Ai_Subsystem_004cc93d(player,s_What_kind_of_mana__00523f40,1,player_idx,0xffffffff);
      if (val_2 == -1) {
        g_ActivePlayer = 1;
      }
      else {
        FUN_0040d875(player,val_2,1);
        Mem_AllocOrFree_0041df33(player,1,player,card_slot);
        *(uint32_t *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) | 0x10;
        g_PendingAttackersTargetSlot = val_2;
      }
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: CardScript_Desert
 * Entry Point: 0045350d
 * Size: 670 bytes
 */


int32_t CardScript_Desert(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  int val_2;
  
  if (arg_3 == 1) {
    uval_1 = UI_DrawManaSymbolBox(player,card_slot,1,0);
  }
  else if (arg_3 == 0x73) {
    if ((((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) == 0) &&
       ((((&g_CardSlot_Subtypes)[card_slot * 0x120 + player * 0x5b20] & 3) == 0 ||
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId + card_slot * 0x120 + player * 0x5b20) * 0x34] & 2) == 0)))) {
      uval_1 = 1;
    }
    else {
      uval_1 = 0;
    }
  }
  else {
    if (arg_3 == 0x6d) {
      if (((g_ScWillyScore < 0x1a) || (0x1d < g_ScWillyScore)) ||
         (val_2 = Ai_Subsystem_004cc814
                            (player,s_Desert__00523f64,1,s_Damage_00523f5c,&DAT_00523f54,(char *)0x0)
         , val_2 != 0)) {
        FUN_0040d875(player,0,1);
        g_PendingAttackersTargetSlot = 0;
      }
      else {
        val_2 = Glue_Subsystem_004e69ac(player,1 - player,card_slot);
        if (val_2 == 0) {
          g_ActivePlayer = 1;
        }
        else {
          if (((&g_CardSlot_Flags)
               [*(int *)(&g_CardSlot_CombatTarget + card_slot * 0x120 + player * 0x5b20) * 0x5b20 +
                *(int *)(&g_CardSlot_AttachedAura + card_slot * 0x120 + player * 0x5b20) * 0x120] & 0x44)
              != 0) {
            Card_ApplyCombatDamage(*(int *)(&g_CardSlot_CombatTarget + card_slot * 0x120 + player * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + card_slot * 0x120 + player * 0x5b20),1,player
                         ,card_slot);
          }
          (&g_CardSlot_TurnPlayed)[card_slot * 0x120 + player * 0x5b20] = 0;
          FUN_0040d82b(player,0,1);
          *(uint32_t *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) =
               *(uint32_t *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) | 0x10;
        }
      }
      (&g_CardSlot_TurnPlayed)[card_slot * 0x120 + player * 0x5b20] = 0;
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: CardScript_Oasis
 * Entry Point: 004537b0
 * Size: 1200 bytes
 */


int32_t CardScript_Oasis(int spell_id,int target_id,int flags)

{
  int32_t uval_1;
  int val_2;
  uint32_t player_idx;
  int card_idx;
  int match_count;
  int slot_idx;
  
  if (flags == 0x73) {
    player_idx = (uint32_t)(((uint8_t)g_DuelModeFlags & 4) != 0);
    if (((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) != 0) {
      player_idx = 0;
    }
    if (((player_idx != 0) && (((&g_CardSlot_Subtypes)[target_id * 0x120 + spell_id * 0x5b20] & 3) != 0)) &&
       (((&g_MasterCardColorTable)
         [*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) * 0x34] & 2) != 0)) {
      player_idx = 0;
    }
    if (player_idx != 0) {
      player_idx = UI_PaintBigCardInfo((int *)0x0,1,spell_id,2,2,0x200,2,0,0,0,0,0,0xffffffff,0xffffffff,
                              0xffffffff,0xffffffff,0,0,0);
    }
    if (player_idx == 0) {
      uval_1 = 0;
    }
    else {
      uval_1 = 99;
    }
  }
  else if (flags == 0x90) {
    Ai_PeekPlannedSlot(0);
    uval_1 = 0;
  }
  else {
    if ((flags == 0x6d) && (((uint8_t)g_DuelModeFlags & 4) != 0)) {
      if (g_AiManaPoolReserve == 0) {
        slot_idx = 0;
        while (slot_idx == 0) {
          Pic_Subsystem_00424500(s_prompts_txt_00523f74,s_OASIS_00523f6c);
          val_2 = Duel_ChooseTarget
                            (spell_id,2,2,0x200,0,0,0,0,0,0,g_PendingSpellTargetSlot,-1,0xffffffff,0xffffffff,0,
                             0,0,&g_OverworldGoldAmount,1,&card_idx);
          if (val_2 == 0) {
            g_ActivePlayer = 1;
            slot_idx = 1;
          }
          else if (*(int *)(&g_CardSlot_OriginalCardId + card_idx * 0x5b20 + match_count * 0x120) == -1)
          {
            if (g_IsAiThinking != 1) {
              Ai_Util_004cc42d(s_Illegal_target__damage_type___00523f80);
              Sleep(2000);
              Ai_Util_004cc42d(&DAT_00523fa0);
            }
          }
          else {
            slot_idx = 1;
            *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = card_idx;
            *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = match_count;
            (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
            *(uint32_t *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) =
                 *(uint32_t *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
          }
        }
      }
      else {
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
        g_ActivePlayer = 1;
      }
    }
    if ((flags == 0x72) && ((&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] != '\0')
       ) {
      card_idx = *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
      match_count = *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      val_2 = Rules_ParseFilter_0040360b
                        (card_idx,match_count,(char *)0x0,spell_id,2,2,0x200,0,0,0,0,0,0,g_PendingSpellTargetSlot,-1
                         ,0xffffffff,0xffffffff,0,0,0);
      if (val_2 != 0) {
        if (*(int *)(&g_CardSlot_ConvertedManaCost + card_idx * 0x5b20 + match_count * 0x120) < 1) {
          g_ActivePlayer = 1;
        }
        else {
          *(int *)(&g_CardSlot_ConvertedManaCost + card_idx * 0x5b20 + match_count * 0x120) =
               *(int *)(&g_CardSlot_ConvertedManaCost + card_idx * 0x5b20 + match_count * 0x120) + -1;
        }
      }
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120] = 0;
    }
    if ((flags == 0x3b) &&
       (((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0)) {
      *(int *)(&DAT_00695eb8 + spell_id * 4) = *(int *)(&DAT_00695eb8 + spell_id * 4) + 1;
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: CardScript_ElephantsGraveyard
 * Entry Point: 00453c60
 * Size: 886 bytes
 */


int32_t CardScript_ElephantsGraveyard(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  int val_2;
  int match_count;
  
  if (arg_3 == 1) {
    uval_1 = UI_DrawManaSymbolBox(player,card_slot,1,0);
    return uval_1;
  }
  if (arg_3 != 0x73) {
    if (arg_3 == 0x6d) {
      if ((((uint8_t)g_DuelModeFlags & 4) == 0) ||
         (val_2 = Ai_Subsystem_004cc814
                            (player,s_Elephant_s_Graveyard__00523fb8,1,s_Regenerate_00523fac,
                             &DAT_00523fa4,(char *)0x0), val_2 != 0)) {
        FUN_0040d875(player,0,1);
        g_PendingAttackersTargetSlot = 0;
      }
      else {
        if ((match_count != -1) &&
           (((&g_MasterCardRarityTable)
             [*(int *)(&g_CardSlot_CardId +
                      *(int *)(&g_CardSlot_AttachedAura + card_slot * 0x120 + player * 0x5b20) * 0x120 +
                      *(int *)(&g_CardSlot_CombatTarget + card_slot * 0x120 + player * 0x5b20) * 0x5b20)
              * 0x34] == '\n' ||
            ((&g_MasterCardRarityTable)
             [*(int *)(&g_CardSlot_CardId +
                      *(int *)(&g_CardSlot_AttachedAura + card_slot * 0x120 + player * 0x5b20) * 0x120 +
                      *(int *)(&g_CardSlot_CombatTarget + card_slot * 0x120 + player * 0x5b20) * 0x5b20)
              * 0x34] == '\v')))) {
          (&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20] = g_TemporaryToughnessBuffer;
          *(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) = match_count;
          *(uint32_t *)(&g_CardSlot_Abilities2 +
                   *(int *)(&g_CardSlot_AttachedAura + card_slot * 0x120 + player * 0x5b20) * 0x120 +
                   *(int *)(&g_CardSlot_CombatTarget + card_slot * 0x120 + player * 0x5b20) * 0x5b20) =
               *(uint32_t *)(&g_CardSlot_Abilities2 +
                        *(int *)(&g_CardSlot_AttachedAura + card_slot * 0x120 + player * 0x5b20) * 0x120
                        + *(int *)(&g_CardSlot_CombatTarget + card_slot * 0x120 + player * 0x5b20) *
                          0x5b20) | 0x200;
        }
        FUN_0040d82b(player,0,1);
      }
      *(uint32_t *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) | 0x10;
    }
    if (((uint8_t)g_DuelModeFlags & 4) == 0) {
      *(int32_t *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) = 0xffffffff;
      (&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20] =
           (&g_CardSlot_OriginalCardId)[card_slot * 0x120 + player * 0x5b20];
    }
    if ((((arg_3 == 0x34) &&
         (*(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) ==
          g_EventSourceSlot)) &&
        ((char)(&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20] == g_EventSourcePlayer))
       && (g_EventSourceSlot != -1)) {
      g_CardEventResult = g_CardEventResult | 0x200;
    }
    return 0;
  }
  if ((((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) == 0) &&
     ((((&g_CardSlot_Subtypes)[card_slot * 0x120 + player * 0x5b20] & 3) == 0 ||
      (((&g_MasterCardColorTable)
        [*(int *)(&g_CardSlot_CardId + card_slot * 0x120 + player * 0x5b20) * 0x34] & 2) == 0)))) {
    return 1;
  }
  return 0;
}



/*
 * Decompiled function: Mana_Init_00453fdb
 * Entry Point: 00453fdb
 * Size: 1016 bytes
 */


int32_t Mana_Init_00453fdb(int spell_id,int target_id,int flags)

{
  int color_mask;
  int val_1;
  uint32_t arg_11;
  uint32_t arg_12;
  uint32_t arg_13;
  int val_2;
  int arg_15;
  uint32_t arg_16;
  uint32_t arg_17;
  uint32_t arg_18;
  uint32_t arg_19;
  uint32_t arg_20;
  int32_t player_idx;
  int slot_idx;
  
  if (flags == 1) {
    player_idx = UI_DrawManaSymbolBox(spell_id,target_id,1,0);
  }
  else if (flags == 0x71) {
    player_idx = UI_DrawManaSymbolBox(spell_id,target_id,0x71,0);
  }
  else if (flags == 0x73) {
    player_idx = UI_DrawManaSymbolBox(spell_id,target_id,0x73,0);
  }
  else if (flags == 0x6d) {
    player_idx = 0;
    strcpy(&g_OverworldWorldState,s_Get_mana__00523fd0);
    strcat(&g_OverworldWorldState,s_Sacrifice_to_destroy_a_land__00523fdc);
    strcat(&g_OverworldWorldState,s_Cancel__00523ffc);
    (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    if (g_AiCombatDamageAssigned == 0) {
      slot_idx = 0;
    }
    else if (g_AiManaPoolReserve == 0) {
      if (spell_id == g_CurrentTurnPhase) {
        slot_idx = Ai_Subsystem_004cc56d(spell_id,spell_id,target_id,-1,-1,&g_OverworldWorldState,1);
      }
      else {
        slot_idx = 1;
      }
    }
    else {
      slot_idx = 0;
    }
    if (slot_idx == 0) {
      player_idx = UI_DrawManaSymbolBox(spell_id,target_id,0x6d,0);
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    }
    else if (slot_idx == 1) {
      g_PendingAttackersTargetSlot = 0xffffffff;
      Pic_Subsystem_00424500(s_prompts_txt_00524014,s_STRIPMINE_00524008);
      val_1 = Glue_Subsystem_004e6dcc(spell_id,1 - spell_id,target_id);
      if (val_1 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(uint32_t *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
        if (g_IsAiThinking != 1) {
          Duel_PlaySoundById(0xf);
        }
        Pic_Subsystem_0044867e(spell_id,target_id,3);
        FUN_0040d82b(spell_id,0,1);
      }
    }
    else {
      g_ActivePlayer = 1;
    }
    if (g_ActivePlayer == 1) {
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    }
  }
  else {
    if ((flags == 0x72) && ((&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] != '\0')
       ) {
      val_1 = *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
      color_mask = *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      arg_20 = 0;
      arg_19 = 0;
      arg_18 = 0;
      arg_17 = 0xffffffff;
      arg_16 = 0xffffffff;
      arg_15 = -1;
      val_2 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_2 = Rules_ParseFilter_0040360b
                        (val_1,color_mask,(char *)0x0,spell_id,2,2,0x200,1,0,0,arg_11,arg_12,arg_13,
                         val_2,arg_15,arg_16,arg_17,arg_18,arg_19,arg_20);
      if (val_2 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        Pic_Subsystem_0044867e(val_1,color_mask,2);
      }
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120] = 0;
    }
    if (flags == 0x7f) {
      player_idx = UI_DrawManaSymbolBox(spell_id,target_id,0x7f,0);
    }
    else {
      player_idx = 0;
    }
  }
  return player_idx;
}



/*
 * Decompiled function: Minit_Subsystem_004543d3
 * Entry Point: 004543d3
 * Size: 495 bytes
 */


int32_t Minit_Subsystem_004543d3(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  int val_2;
  
  if (arg_3 == 0x73) {
    if ((((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) == 0) &&
       ((((&g_CardSlot_Subtypes)[card_slot * 0x120 + player * 0x5b20] & 3) == 0 ||
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId + card_slot * 0x120 + player * 0x5b20) * 0x34] & 2) == 0)))) {
      uval_1 = 1;
    }
    else {
      uval_1 = 0;
    }
  }
  else {
    if (arg_3 == 0x6d) {
      val_2 = Glue_Subsystem_004e69ac(player,player,card_slot);
      if (val_2 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        if (*(int *)(&g_CardSlot_CombatTarget + card_slot * 0x120 + player * 0x5b20) == player) {
          val_2 = Magic_QueryCardAttribute(*(int *)(&g_CardSlot_CombatTarget + card_slot * 0x120 + player * 0x5b20),
                               *(int *)(&g_CardSlot_AttachedAura + card_slot * 0x120 + player * 0x5b20),
                               0x33,0xffffffff);
          (&g_PlayerCreatureCount)[player] = (&g_PlayerCreatureCount)[player] + val_2;
          Pic_Subsystem_0044867e
                    (*(int *)(&g_CardSlot_CombatTarget + card_slot * 0x120 + player * 0x5b20),
                     *(int *)(&g_CardSlot_AttachedAura + card_slot * 0x120 + player * 0x5b20),3);
        }
        *(uint32_t *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) | 0x10;
      }
      (&g_CardSlot_TurnPlayed)[card_slot * 0x120 + player * 0x5b20] = 0;
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: Minit_Subsystem_004545c7
 * Entry Point: 004545c7
 * Size: 310 bytes
 */


int32_t Minit_Subsystem_004545c7(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  int slot_idx;
  
  if (arg_3 == 0x73) {
    if ((((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) == 0) &&
       ((((&g_CardSlot_Subtypes)[card_slot * 0x120 + player * 0x5b20] & 3) == 0 ||
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId + card_slot * 0x120 + player * 0x5b20) * 0x34] & 2) == 0)))) {
      uval_1 = 1;
    }
    else {
      uval_1 = 0;
    }
  }
  else {
    if (arg_3 == 0x6d) {
      Magic_ExecuteDrawPhase(player);
      Magic_ExecuteDrawPhase(player);
      for (slot_idx = 0; slot_idx < 3; slot_idx = slot_idx + 1) {
        if (0 < (int)(&g_ActivePlayerSpellPriority)[player]) {
          Prompts_Load_0046fa40(player,0,0);
        }
      }
      *(uint32_t *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) | 0x10;
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: Card_Setup_00454702
 * Entry Point: 00454702
 * Size: 739 bytes
 */


int32_t Card_Setup_00454702(int player_id,int card_slot,int event_type)

{
  int val_1;
  int32_t uval_2;
  uint32_t match_count;
  uint32_t slot_idx;
  
  if (arg_3 == 1) {
    uval_2 = UI_DrawManaSymbolBox(player,card_slot,1,0);
  }
  else if (arg_3 == 0x71) {
    uval_2 = UI_DrawManaSymbolBox(player,card_slot,0x71,0);
  }
  else if (arg_3 == 0x73) {
    uval_2 = UI_DrawManaSymbolBox(player,card_slot,0x73,0);
  }
  else {
    if (arg_3 == 0x6d) {
      strcpy(&g_OverworldWorldState,s_Get_mana__00524020);
      val_1 = (&g_ActivePlayerSpellPriority)[player];
      if (val_1 != 7) {
        strcat(&g_OverworldWorldState,s___Draw_a_card__0052403c);
      }
      else {
        strcat(&g_OverworldWorldState,s_Draw_a_card__0052402c);
      }
      match_count = (uint32_t)(val_1 == 7);
      strcat(&g_OverworldWorldState,s_Cancel__0052404c);
      if (g_AiCombatDamageAssigned == 0) {
        slot_idx = 0;
      }
      else if (g_AiManaPoolReserve == 0) {
        if (player == g_CurrentTurnPhase) {
          slot_idx = Ai_Subsystem_004cc56d(player,player,card_slot,-1,-1,&g_OverworldWorldState,match_count);
        }
        else {
          slot_idx = match_count;
        }
      }
      else {
        slot_idx = 0;
      }
      *(int32_t *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) = 0;
      if (slot_idx == 0) {
        uval_2 = UI_DrawManaSymbolBox(player,card_slot,0x6d,0);
        return uval_2;
      }
      if (slot_idx == 1) {
        *(uint32_t *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) | 0x10;
        FUN_0040d82b(player,0,1);
        *(int32_t *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) = 1;
        g_PendingAttackersTargetSlot = 0xffffffff;
      }
      else {
        g_ActivePlayer = 1;
      }
    }
    if ((arg_3 == 0x72) &&
       (*(int *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) == 1)) {
      *(int32_t *)
       (&g_CardSlot_ConvertedManaCost +
       *(int *)(&g_CardSlot_TapState + card_slot * 0x120 + player * 0x5b20) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + card_slot * 0x120 + player * 0x5b20) * 0x120) = 0;
      Magic_ExecuteDrawPhase(player);
    }
    if (arg_3 == 0x7f) {
      uval_2 = UI_DrawManaSymbolBox(player,card_slot,0x7f,0);
    }
    else {
      uval_2 = 0;
    }
  }
  return uval_2;
}



/*
 * Decompiled function: Mana_Init_004549ea
 * Entry Point: 004549ea
 * Size: 3033 bytes
 */


int32_t Mana_Init_004549ea(int spell_id,int target_id,int flags)

{
  bool flag_1;
  int32_t uval_2;
  int val_3;
  int32_t uval_4;
  int32_t arg_10;
  uint32_t uval_5;
  uint32_t uval_6;
  uint32_t uval_7;
  int32_t arg_11;
  int val_8;
  int32_t arg_12;
  uint32_t uVar9;
  uint32_t uVar10;
  int32_t arg_14;
  uint32_t uVar11;
  int32_t arg_15;
  uint32_t uVar12;
  int32_t arg_16;
  uint32_t uVar13;
  int32_t arg_17;
  uint8_t *arg_18;
  int32_t arg_18_00;
  int32_t arg_19;
  int *arg_20;
  int local_24;
  int player_idx;
  int card_idx;
  int match_count;
  int slot_idx;
  
  if (flags == 1) {
    uval_2 = UI_DrawManaSymbolBox(spell_id,target_id,1,0);
    return uval_2;
  }
  if (flags == 0x6c) {
    g_SpellStackDepth = g_SpellStackDepth + 0x18;
  }
  if (flags == 0x71) {
    uval_2 = UI_DrawManaSymbolBox(spell_id,target_id,0x71,0);
    return uval_2;
  }
  if (flags == 0x73) {
    flag_1 = false;
    if ((((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0) &&
       ((((&g_CardSlot_Subtypes)[target_id * 0x120 + spell_id * 0x5b20] & 3) == 0 ||
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) * 0x34] & 2) == 0)))
       ) {
      flag_1 = true;
    }
    val_3 = Font_DrawString(spell_id, 7, 1);
    if (val_3 != 0) {
      flag_1 = true;
    }
    if (flag_1) {
      if ((spell_id == g_ActivePlayerPriority) && (0 < DAT_006ff550)) {
        g_CombatPhaseFlags = g_CombatPhaseFlags | 3;
      }
      return 1;
    }
    return 0;
  }
  if (flags != 0x6d) {
    if (flags == 0x72) {
      slot_idx = *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20);
      if (slot_idx != 0) {
        if (slot_idx == 1) {
          uval_2 = Pic_Subsystem_0045268f(0x38e);
          *(int32_t *)
           (&g_CardSlot_CardId +
           *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
           *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120) =
               uval_2;
          *(int32_t *)
           (&g_CardSlot_Controller +
           *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
           *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120) =
               *(int32_t *)
                (&g_CardSlot_CardId +
                *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
                *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120)
          ;
          *(int *)(&DAT_006b3010 + g_DialogPromptHwnd * 4) =
               *(int *)(&DAT_006b3010 + g_DialogPromptHwnd * 4) + 1;
          (&DAT_006b3018)[g_DialogPromptHwnd] = (&DAT_006b3018)[g_DialogPromptHwnd] + 1;
          *(uint32_t *)(&g_CardSlot_Flags +
                   *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
                   *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) *
                   0x120) =
               *(uint32_t *)(&g_CardSlot_Flags +
                        *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) *
                        0x5b20 + *(int *)(&g_CardSlot_SicknessState +
                                         target_id * 0x120 + spell_id * 0x5b20) * 0x120) | 2;
          Magic_TriggerCardEvent
                    (g_DialogPromptHwnd,g_DuelArenaHwnd,0x6c,1 - g_DialogPromptHwnd,0xffffffff);
          *(uint32_t *)(&g_CardSlot_Flags +
                   *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
                   *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) *
                   0x120) =
               *(uint32_t *)(&g_CardSlot_Flags +
                        *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) *
                        0x5b20 + *(int *)(&g_CardSlot_SicknessState +
                                         target_id * 0x120 + spell_id * 0x5b20) * 0x120) | 0x80;
          Magic_TriggerCardEvent
                    (g_DialogPromptHwnd,g_DuelArenaHwnd,0x71,1 - g_DialogPromptHwnd,0xffffffff);
        }
        else if ((slot_idx == 2) &&
                ((&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] != '\0')) {
          player_idx = *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
          card_idx = *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
          uVar13 = 0;
          uVar12 = 0;
          uVar11 = 0;
          uVar10 = 0xffffffff;
          uVar9 = 0xffffffff;
          val_8 = -1;
          val_3 = Pic_Subsystem_0045268f(0x38e);
          uval_7 = 0;
          uval_6 = 0;
          uval_5 = Glue_Subsystem_004d0a42(spell_id,target_id);
          val_3 = Rules_ParseFilter_0040360b
                            (player_idx,card_idx,(char *)0x0,spell_id,2,2,0x200,0,0,0,uval_5,uval_6,
                             uval_7,val_3,val_8,uVar9,uVar10,uVar11,uVar12,uVar13);
          if (val_3 == 0) {
            g_ActivePlayer = 1;
          }
          else {
            match_count = Card_ApplyTriggerEffect(g_DialogPromptHwnd, g_DuelArenaHwnd, g_PlayerSelectionPriority, player_idx, card_idx);
            if (match_count != -1) {
              *(int16_t *)(&g_CardSlot_PowerCounters + match_count * 0x120 + spell_id * 0x5b20) = 1;
              *(int16_t *)(&g_CardSlot_ToughnessCounters + match_count * 0x120 + spell_id * 0x5b20) = 1;
            }
          }
          (&g_CardSlot_TurnPlayed)
          [*(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
           *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120] = 0;
        }
      }
      *(int32_t *)
       (&g_CardSlot_ConvertedManaCost +
       *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120) = 0;
    }
    if (flags == 0x7f) {
      uval_2 = UI_DrawManaSymbolBox(spell_id,target_id,0x7f,0);
      return uval_2;
    }
    if (((((flags == 0x3c) && ((g_DuelModeFlags._2_1_ & 2) == 0)) &&
         (target_id == g_EventSourceSlot)) &&
        ((spell_id == g_EventSourcePlayer &&
         (val_3 = Card_IsInPlay(spell_id, target_id), val_3 != 0)))) &&
       (*(int *)(&g_CardSlot_Controller + target_id * 0x120 + spell_id * 0x5b20) != 0)) {
      g_CardEventResult =
           *(int32_t *)(&g_CardSlot_Controller + target_id * 0x120 + spell_id * 0x5b20);
    }
    if (flags == 199) {
      if (spell_id == g_ActivePlayerPriority) {
        g_SpellStackDepth = g_SpellStackDepth + 0x30;
      }
      else {
        g_SpellStackDepth = g_SpellStackDepth + -0x30;
      }
    }
    return 0;
  }
  uval_2 = 0;
  local_24 = 3;
  if ((((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0) &&
     ((((&g_CardSlot_Subtypes)[target_id * 0x120 + spell_id * 0x5b20] & 3) == 0 ||
      (((&g_MasterCardColorTable)
        [*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) * 0x34] & 2) == 0))))
  {
    strcpy(&g_OverworldWorldState,s_Get_mana__00524058);
    local_24 = 0;
  }
  else {
    strcpy(&g_OverworldWorldState,s__Get_mana__00524064);
  }
  val_3 = Font_DrawString(spell_id, 7, 1);
  if (val_3 == 0) {
    strcat(&g_OverworldWorldState,s__Change_to_Assembly_Worker__00524094);
  }
  else {
    strcat(&g_OverworldWorldState,s_Change_to_Assembly_Worker__00524074);
    if (g_ScWillyScore < 0x17) {
      local_24 = 1;
    }
  }
  if ((((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0) &&
     ((((&g_CardSlot_Subtypes)[target_id * 0x120 + spell_id * 0x5b20] & 3) == 0 ||
      (((&g_MasterCardColorTable)
        [*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) * 0x34] & 2) == 0))))
  {
    arg_19 = 0;
    arg_18_00 = 0;
    arg_17 = 0;
    arg_16 = 0xffffffff;
    arg_15 = 0xffffffff;
    arg_14 = 0xffffffff;
    uval_4 = Pic_Subsystem_0045268f(0x38e);
    arg_12 = 0;
    arg_11 = 0;
    arg_10 = Glue_Subsystem_004d0a42(spell_id,target_id);
    val_3 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,0,0,0,arg_10,arg_11,arg_12,uval_4,arg_14,
                         arg_15,arg_16,arg_17,arg_18_00,arg_19);
    if (val_3 != 0) {
      strcat(&g_OverworldWorldState,s_Pump_Assembly_Worker__005240b4);
      if ((g_ScWillyScore < 0x1e) && (0x16 < g_ScWillyScore)) {
        local_24 = 2;
      }
      goto LAB_00454d93;
    }
  }
  strcat(&g_OverworldWorldState,s__Pump_Assembly_Worker__005240cc);
LAB_00454d93:
  strcat(&g_OverworldWorldState,s_Cancel__005240e8);
  if (g_AiManaPoolReserve == 0) {
    slot_idx = Ai_Subsystem_004cc56d
                        (spell_id,spell_id,target_id,-1,-1,&g_OverworldWorldState,local_24);
  }
  else {
    slot_idx = 0;
  }
  *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) = slot_idx;
  if (slot_idx == 0) {
    uval_2 = UI_DrawManaSymbolBox(spell_id,target_id,0x6d,0);
    (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
  }
  else if (slot_idx == 1) {
    uval_5 = *(uint32_t *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20);
    *(uint32_t *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) =
         *(uint32_t *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) | 0x40000;
    Ai_CalcManaRequirement_004ba890(spell_id,0,1);
    if ((uval_5 & 0x40000) == 0) {
      *(uint32_t *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) & 0xfffbffff;
    }
    (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    g_PendingAttackersTargetSlot = 0xffffffff;
  }
  else if (slot_idx == 2) {
    Pic_Subsystem_00424500(s_prompts_txt_00524104,s_MISHRAS_FACTORY_005240f4);
    arg_20 = &player_idx;
    uval_4 = 1;
    arg_18 = &g_OverworldGoldAmount;
    uVar13 = 0;
    uVar12 = 0;
    uVar11 = 0;
    uVar10 = 0xffffffff;
    uVar9 = 0xffffffff;
    val_8 = -1;
    val_3 = Pic_Subsystem_0045268f(0x38e);
    uval_7 = 0;
    uval_6 = 0;
    uval_5 = Glue_Subsystem_004d0a42(spell_id,target_id);
    val_3 = Duel_ChooseTarget
                      (spell_id,2,spell_id,0x200,0,0,0,uval_5,uval_6,uval_7,val_3,val_8,uVar9,uVar10,
                       uVar11,uVar12,uVar13,arg_18,uval_4,arg_20);
    if (val_3 == 0) {
      g_ActivePlayer = 1;
    }
    else {
      *(uint32_t *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
      FUN_0040d82b(spell_id,0,1);
      *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = player_idx;
      *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = card_idx;
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
    }
    g_PendingAttackersTargetSlot = 0xffffffff;
  }
  else {
    g_ActivePlayer = 1;
  }
  if (0 < DAT_006ff550) {
    DAT_006ff550 = DAT_006ff550 + -1;
  }
  return uval_2;
}



/*
 * Decompiled function: Mana_Init_004555c8
 * Entry Point: 004555c8
 * Size: 2960 bytes
 */


int32_t Mana_Init_004555c8(int spell_id,int target_id,int flags)

{
  int32_t uval_1;
  int val_2;
  int32_t arg_10;
  uint32_t uval_3;
  uint32_t uval_4;
  uint32_t uval_5;
  int32_t arg_11;
  int val_6;
  int32_t arg_12;
  uint32_t uval_7;
  uint32_t uval_8;
  int32_t arg_14;
  uint32_t uVar9;
  int32_t arg_15;
  uint32_t uVar10;
  int32_t arg_16;
  uint32_t uVar11;
  int32_t arg_17;
  uint8_t *arg_18;
  int32_t arg_18_00;
  int32_t arg_19;
  int *arg_20;
  int local_24;
  int32_t loop_idx;
  int32_t target_idx;
  int player_idx;
  int card_idx;
  int match_count;
  int slot_idx;
  
  if (flags == 0x22) {
    uval_1 = Pic_Subsystem_0045268f(0x1fc);
    *(int32_t *)(&g_CardSlot_CardId + spell_id * 0x5b20 + target_id * 0x120) = uval_1;
    *(int32_t *)(&g_CardSlot_Controller + spell_id * 0x5b20 + target_id * 0x120) = 0;
    (&DAT_006b3018)[spell_id] = (&DAT_006b3018)[spell_id] + -1;
    *(int *)(&DAT_006b3010 + spell_id * 4) = *(int *)(&DAT_006b3010 + spell_id * 4) + -1;
    DAT_00679ec8 = spell_id;
    DAT_00679ec4 = target_id;
    Glue_Subsystem_004e65e1(Minit_Subsystem_00456158,spell_id);
  }
  if (((flags == 0x77) && (target_id == g_EventSourceSlot)) &&
     (spell_id == g_EventSourcePlayer)) {
    uval_1 = Pic_Subsystem_0045268f(0x1fc);
    *(int32_t *)(&g_CardSlot_CardId + spell_id * 0x5b20 + target_id * 0x120) = uval_1;
    return 0;
  }
  if (flags == 1) {
    uval_1 = UI_DrawManaSymbolBox(spell_id,target_id,1,0);
    return uval_1;
  }
  if (flags == 0x71) {
    uval_1 = UI_DrawManaSymbolBox(spell_id,target_id,0x71,0);
    return uval_1;
  }
  if (flags == 0x73) {
    target_idx = 0;
    if ((((&g_CardSlot_Flags)[spell_id * 0x5b20 + target_id * 0x120] & 0x10) == 0) &&
       ((((&g_CardSlot_Subtypes)[spell_id * 0x5b20 + target_id * 0x120] & 3) == 0 ||
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId + spell_id * 0x5b20 + target_id * 0x120) * 0x34] & 2) == 0)))
       ) {
      target_idx = 1;
    }
    val_2 = Font_DrawString(spell_id, 7, 1);
    if (val_2 == 0) {
      return target_idx;
    }
    return 1;
  }
  if (flags != 0x6d) {
    if (flags == 0x72) {
      slot_idx = *(int *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120);
      if (slot_idx != 0) {
        if (slot_idx == 1) {
          uval_1 = Pic_Subsystem_0045268f(0x38e);
          *(int32_t *)
           (&g_CardSlot_CardId +
           *(int *)(&g_CardSlot_TapState + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20 +
           *(int *)(&g_CardSlot_SicknessState + spell_id * 0x5b20 + target_id * 0x120) * 0x120) =
               uval_1;
          *(int32_t *)
           (&g_CardSlot_Controller +
           *(int *)(&g_CardSlot_TapState + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20 +
           *(int *)(&g_CardSlot_SicknessState + spell_id * 0x5b20 + target_id * 0x120) * 0x120) =
               *(int32_t *)
                (&g_CardSlot_CardId +
                *(int *)(&g_CardSlot_TapState + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20 +
                *(int *)(&g_CardSlot_SicknessState + spell_id * 0x5b20 + target_id * 0x120) * 0x120)
          ;
          *(int *)(&DAT_006b3010 + g_DialogPromptHwnd * 4) =
               *(int *)(&DAT_006b3010 + g_DialogPromptHwnd * 4) + 1;
          (&DAT_006b3018)[g_DialogPromptHwnd] = (&DAT_006b3018)[g_DialogPromptHwnd] + 1;
          *(uint32_t *)(&g_CardSlot_Flags +
                   *(int *)(&g_CardSlot_SicknessState + spell_id * 0x5b20 + target_id * 0x120) *
                   0x120 + *(int *)(&g_CardSlot_TapState + spell_id * 0x5b20 + target_id * 0x120) *
                           0x5b20) =
               *(uint32_t *)(&g_CardSlot_Flags +
                        *(int *)(&g_CardSlot_SicknessState + spell_id * 0x5b20 + target_id * 0x120)
                        * 0x120 + *(int *)(&g_CardSlot_TapState +
                                          spell_id * 0x5b20 + target_id * 0x120) * 0x5b20) | 2;
          Magic_TriggerCardEvent
                    (g_DialogPromptHwnd,g_DuelArenaHwnd,0x6c,1 - g_DialogPromptHwnd,0xffffffff);
          *(uint32_t *)(&g_CardSlot_Flags +
                   *(int *)(&g_CardSlot_SicknessState + spell_id * 0x5b20 + target_id * 0x120) *
                   0x120 + *(int *)(&g_CardSlot_TapState + spell_id * 0x5b20 + target_id * 0x120) *
                           0x5b20) =
               *(uint32_t *)(&g_CardSlot_Flags +
                        *(int *)(&g_CardSlot_SicknessState + spell_id * 0x5b20 + target_id * 0x120)
                        * 0x120 + *(int *)(&g_CardSlot_TapState +
                                          spell_id * 0x5b20 + target_id * 0x120) * 0x5b20) | 0x80;
          Magic_TriggerCardEvent
                    (g_DialogPromptHwnd,g_DuelArenaHwnd,0x71,1 - g_DialogPromptHwnd,0xffffffff);
        }
        else if ((slot_idx == 2) &&
                ((&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] != '\0')) {
          player_idx = *(int *)(&g_CardSlot_CombatTarget + spell_id * 0x5b20 + target_id * 0x120);
          card_idx = *(int *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120);
          uVar11 = 0;
          uVar10 = 0;
          uVar9 = 0;
          uval_8 = 0xffffffff;
          uval_7 = 0xffffffff;
          val_6 = -1;
          val_2 = Pic_Subsystem_0045268f(0x38e);
          uval_5 = 0;
          uval_4 = 0;
          uval_3 = Glue_Subsystem_004d0a42(spell_id,target_id);
          val_2 = Rules_ParseFilter_0040360b
                            (player_idx,card_idx,(char *)0x0,spell_id,2,2,0x200,0,0,0,uval_3,uval_4,
                             uval_5,val_2,val_6,uval_7,uval_8,uVar9,uVar10,uVar11);
          if (val_2 == 0) {
            g_ActivePlayer = 1;
          }
          else {
            match_count = Card_ApplyTriggerEffect(g_DialogPromptHwnd, g_DuelArenaHwnd, g_PlayerSelectionPriority, player_idx, card_idx);
            if (match_count != -1) {
              *(int16_t *)(&g_CardSlot_PowerCounters + match_count * 0x120 + spell_id * 0x5b20) = 1;
              *(int16_t *)(&g_CardSlot_ToughnessCounters + match_count * 0x120 + spell_id * 0x5b20) = 1;
            }
          }
          (&g_CardSlot_TurnPlayed)
          [*(int *)(&g_CardSlot_TapState + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20 +
           *(int *)(&g_CardSlot_SicknessState + spell_id * 0x5b20 + target_id * 0x120) * 0x120] = 0;
        }
      }
      *(int32_t *)
       (&g_CardSlot_ConvertedManaCost +
       *(int *)(&g_CardSlot_TapState + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + spell_id * 0x5b20 + target_id * 0x120) * 0x120) = 0;
    }
    if (flags == 0x7f) {
      uval_1 = UI_DrawManaSymbolBox(spell_id,target_id,0x7f,0);
      return uval_1;
    }
    return 0;
  }
  loop_idx = 0;
  local_24 = 3;
  if ((((&g_CardSlot_Flags)[spell_id * 0x5b20 + target_id * 0x120] & 0x10) == 0) &&
     ((((&g_CardSlot_Subtypes)[spell_id * 0x5b20 + target_id * 0x120] & 3) == 0 ||
      (((&g_MasterCardColorTable)
        [*(int *)(&g_CardSlot_CardId + spell_id * 0x5b20 + target_id * 0x120) * 0x34] & 2) == 0))))
  {
    strcpy(&g_OverworldWorldState,s_Get_mana__00524110);
    local_24 = 0;
  }
  else {
    strcpy(&g_OverworldWorldState,s__Get_mana__0052411c);
  }
  val_2 = Font_DrawString(spell_id, 7, 1);
  if (val_2 == 0) {
    strcat(&g_OverworldWorldState,s__Re_change_to_Assembly_Worker__0052414c);
  }
  else {
    strcat(&g_OverworldWorldState,s_Re_change_to_Assembly_Worker__0052412c);
  }
  if ((((&g_CardSlot_Flags)[spell_id * 0x5b20 + target_id * 0x120] & 0x10) == 0) &&
     ((((&g_CardSlot_Subtypes)[spell_id * 0x5b20 + target_id * 0x120] & 3) == 0 ||
      (((&g_MasterCardColorTable)
        [*(int *)(&g_CardSlot_CardId + spell_id * 0x5b20 + target_id * 0x120) * 0x34] & 2) == 0))))
  {
    arg_19 = 0;
    arg_18_00 = 0;
    arg_17 = 0;
    arg_16 = 0xffffffff;
    arg_15 = 0xffffffff;
    arg_14 = 0xffffffff;
    uval_1 = Pic_Subsystem_0045268f(0x38e);
    arg_12 = 0;
    arg_11 = 0;
    arg_10 = Glue_Subsystem_004d0a42(spell_id,target_id);
    val_2 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,0,0,0,arg_10,arg_11,arg_12,uval_1,arg_14,
                         arg_15,arg_16,arg_17,arg_18_00,arg_19);
    if (val_2 != 0) {
      strcat(&g_OverworldWorldState,s_Pump_Assembly_Worker__00524170);
      if ((g_ScWillyScore < 0x1e) && (0x16 < g_ScWillyScore)) {
        local_24 = 2;
      }
      goto LAB_004559f9;
    }
  }
  strcat(&g_OverworldWorldState,s__Pump_Assembly_Worker__00524188);
LAB_004559f9:
  strcat(&g_OverworldWorldState,s_Cancel__005241a4);
  if (g_AiManaPoolReserve == 0) {
    slot_idx = Ai_Subsystem_004cc56d
                        (spell_id,spell_id,target_id,-1,-1,&g_OverworldWorldState,local_24);
  }
  else {
    slot_idx = 0;
  }
  *(int *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) = slot_idx;
  if (slot_idx == 0) {
    loop_idx = UI_DrawManaSymbolBox(spell_id,target_id,0x6d,0);
    (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 0;
  }
  else if (slot_idx == 1) {
    uval_3 = *(uint32_t *)(&g_CardSlot_Flags + spell_id * 0x5b20 + target_id * 0x120);
    *(uint32_t *)(&g_CardSlot_Flags + spell_id * 0x5b20 + target_id * 0x120) =
         *(uint32_t *)(&g_CardSlot_Flags + spell_id * 0x5b20 + target_id * 0x120) | 0x40000;
    Ai_CalcManaRequirement_004ba890(spell_id,0,1);
    if ((uval_3 & 0x40000) == 0) {
      *(uint32_t *)(&g_CardSlot_Flags + spell_id * 0x5b20 + target_id * 0x120) =
           *(uint32_t *)(&g_CardSlot_Flags + spell_id * 0x5b20 + target_id * 0x120) & 0xfffbffff;
    }
    (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 0;
    g_PendingAttackersTargetSlot = 0xffffffff;
  }
  else if (slot_idx == 2) {
    Pic_Subsystem_00424500(s_prompts_txt_005241c0,s_ASSEMBLY_WORKER_005241b0);
    arg_20 = &player_idx;
    uval_1 = 1;
    arg_18 = &g_OverworldGoldAmount;
    uVar11 = 0;
    uVar10 = 0;
    uVar9 = 0;
    uval_8 = 0xffffffff;
    uval_7 = 0xffffffff;
    val_6 = -1;
    val_2 = Pic_Subsystem_0045268f(0x38e);
    uval_5 = 0;
    uval_4 = 0;
    uval_3 = Glue_Subsystem_004d0a42(spell_id,target_id);
    val_2 = Duel_ChooseTarget
                      (spell_id,2,spell_id,0x200,0,0,0,uval_3,uval_4,uval_5,val_2,val_6,uval_7,uval_8,
                       uVar9,uVar10,uVar11,arg_18,uval_1,arg_20);
    if (val_2 == 0) {
      g_ActivePlayer = 1;
    }
    else {
      *(uint32_t *)(&g_CardSlot_Flags + spell_id * 0x5b20 + target_id * 0x120) =
           *(uint32_t *)(&g_CardSlot_Flags + spell_id * 0x5b20 + target_id * 0x120) | 0x10;
      FUN_0040d82b(spell_id,0,1);
      *(int *)(&g_CardSlot_CombatTarget + spell_id * 0x5b20 + target_id * 0x120) = player_idx;
      *(int *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120) = card_idx;
      (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 1;
    }
    g_PendingAttackersTargetSlot = 0xffffffff;
  }
  else {
    g_ActivePlayer = 1;
  }
  return loop_idx;
}



/*
 * Decompiled function: Minit_Subsystem_00456158
 * Entry Point: 00456158
 * Size: 192 bytes
 */


int32_t Minit_Subsystem_00456158(int player_id,int card_slot,int event_type)

{
  if (((((char)(&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20] == DAT_00679ec8) &&
       (*(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) == DAT_00679ec4)) &&
      (((&g_MasterCardColorTable)[arg_3 * 0x34] & 4) != 0)) &&
     (*(int *)(&DAT_006b3088 + *(int *)(&g_MasterCardTypeTable + arg_3 * 0x34) * 0x98) != 0x6d)) {
    Pic_Subsystem_0044867e(player,card_slot,2);
  }
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_00456218
 * Entry Point: 00456218
 * Size: 477 bytes
 */


int32_t Minit_Subsystem_00456218(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  
  if ((arg_3 == 0x71) && (g_IsAiThinking != 1)) {
    Duel_PlaySoundById(8);
  }
  if (arg_3 == 0x73) {
    if ((((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) == 0) &&
       ((((&g_CardSlot_Subtypes)[card_slot * 0x120 + player * 0x5b20] & 3) == 0 ||
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId + card_slot * 0x120 + player * 0x5b20) * 0x34] & 2) == 0)))) {
      uval_1 = 1;
    }
    else {
      uval_1 = 0;
    }
  }
  else {
    if (arg_3 == 0x6d) {
      FUN_0040d901(player,6,3);
      *(uint32_t *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) | 0x10;
      g_PendingAttackersTargetSlot = 6;
    }
    if (((arg_3 == 0x7f) && (card_slot == g_EventSourceSlot)) && (player == g_EventSourcePlayer)) {
      if (((((&g_CardSlot_Subtypes)[card_slot * 0x120 + player * 0x5b20] & 3) == 0) ||
          (((&g_MasterCardColorTable)
            [*(int *)(&g_CardSlot_CardId + card_slot * 0x120 + player * 0x5b20) * 0x34] & 2) == 0)) &&
         (((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) == 0)) {
        FUN_0040d7e9(player,6,3);
      }
      *(uint32_t *)(&DAT_0063eed0 + player * 4) = *(uint32_t *)(&DAT_0063eed0 + player * 4) | 0x40;
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: Minit_Subsystem_004563fa
 * Entry Point: 004563fa
 * Size: 339 bytes
 */


int32_t Minit_Subsystem_004563fa(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  
  if (arg_3 == 1) {
    uval_1 = UI_DrawManaSymbolBox(player,card_slot,1,0);
  }
  else if (arg_3 == 0x73) {
    if ((((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) == 0) &&
       ((((&g_CardSlot_Subtypes)[card_slot * 0x120 + player * 0x5b20] & 3) == 0 ||
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId + card_slot * 0x120 + player * 0x5b20) * 0x34] & 2) == 0)))) {
      uval_1 = 1;
    }
    else {
      uval_1 = 0;
    }
  }
  else {
    if (arg_3 == 0x6d) {
      FUN_0040d875(player,0,1);
      *(uint32_t *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) | 0x10;
      g_PendingAttackersTargetSlot = 0;
      DAT_00679ecc = 0;
      Glue_Subsystem_004e65e1(Minit_Subsystem_00456552,player);
      if (DAT_00679ecc == 7) {
        FUN_0040d875(player,0,1);
      }
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: Minit_Subsystem_00456552
 * Entry Point: 00456552
 * Size: 133 bytes
 */


int32_t Minit_Subsystem_00456552(int32_t player,int32_t card_slot,int event_type)

{
  int val_1;
  
  if ((&g_MasterCardRarityTable)[arg_3 * 0x34] == '\b') {
    val_1 = Pic_Subsystem_0045268f(0x21d);
    if (val_1 == arg_3) {
      DAT_00679ecc = DAT_00679ecc | 1;
    }
    val_1 = Pic_Subsystem_0045268f(0x21f);
    if (val_1 == arg_3) {
      DAT_00679ecc = DAT_00679ecc | 2;
    }
    val_1 = Pic_Subsystem_0045268f(0x220);
    if (val_1 == arg_3) {
      DAT_00679ecc = DAT_00679ecc | 4;
    }
  }
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_004565d7
 * Entry Point: 004565d7
 * Size: 339 bytes
 */


int32_t Minit_Subsystem_004565d7(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  
  if (arg_3 == 1) {
    uval_1 = UI_DrawManaSymbolBox(player,card_slot,1,0);
  }
  else if (arg_3 == 0x73) {
    if ((((&g_CardSlot_Flags)[player * 0x5b20 + card_slot * 0x120] & 0x10) == 0) &&
       ((((&g_CardSlot_Subtypes)[player * 0x5b20 + card_slot * 0x120] & 3) == 0 ||
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId + player * 0x5b20 + card_slot * 0x120) * 0x34] & 2) == 0)))) {
      uval_1 = 1;
    }
    else {
      uval_1 = 0;
    }
  }
  else {
    if (arg_3 == 0x6d) {
      FUN_0040d875(player,0,1);
      *(uint32_t *)(&g_CardSlot_Flags + player * 0x5b20 + card_slot * 0x120) =
           *(uint32_t *)(&g_CardSlot_Flags + player * 0x5b20 + card_slot * 0x120) | 0x10;
      g_PendingAttackersTargetSlot = 0;
      DAT_00679ecc = 0;
      Glue_Subsystem_004e65e1(Minit_Subsystem_00456552,player);
      if (DAT_00679ecc == 7) {
        FUN_0040d875(player,0,2);
      }
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: CardScript_Arena
 * Entry Point: 0045672f
 * Size: 1364 bytes
 */


int32_t CardScript_Arena(int spell_id,int target_id,int flags)

{
  int32_t uval_1;
  uint32_t uval_2;
  int *arg_20;
  uint32_t uval_3;
  uint32_t uval_4;
  int val_5;
  int val_6;
  int arg_15;
  uint32_t uval_7;
  uint32_t arg_17;
  uint32_t uval_8;
  uint8_t *arg_18;
  uint32_t uVar9;
  uint32_t uVar10;
  uint32_t uVar11;
  int target_idx;
  uint32_t player_idx [2];
  uint32_t match_count;
  uint32_t slot_idx;
  
  if (flags == 0x73) {
    if ((((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0) &&
       ((((&g_CardSlot_Subtypes)[target_id * 0x120 + spell_id * 0x5b20] & 3) == 0 ||
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) * 0x34] & 2) == 0)))
       ) {
      uval_1 = 1;
    }
    else {
      uval_1 = 0;
    }
  }
  else {
    if (flags == 0x6d) {
      if (g_AiManaPoolReserve == 0) {
        Ai_CalcManaRequirement_004ba890(spell_id,0,3);
        if (g_ActivePlayer != 1) {
          Pic_Subsystem_00424500(s_prompts_txt_005241d4,s_ARENA_005241cc);
          for (target_idx = 0; target_idx < 2; target_idx = target_idx + 1) {
            arg_20 = (int *)(((spell_id == 0) - 1 & (int)&match_count - (int)player_idx) + (int)player_idx);
            uval_3 = (uint32_t)(spell_id == target_idx);
            arg_18 = &g_OverworldGoldAmount;
            arg_17 = 0;
            uVar11 = 0;
            uVar10 = 0;
            uVar9 = 0xffffffff;
            uval_8 = 0xffffffff;
            val_6 = -1;
            val_5 = -1;
            uval_7 = 0;
            uval_4 = 0;
            uval_2 = Glue_Subsystem_004d0a42(spell_id,target_id);
            val_5 = Duel_ChooseTarget
                              (spell_id,spell_id,spell_id,0x200,2,0,0,uval_2,uval_4,uval_7,val_5,val_6,
                               uval_8,uVar9,uVar10,uVar11,arg_17,arg_18,uval_3,arg_20);
            if (val_5 == 0) {
              g_ActivePlayer = 1;
            }
          }
          if (g_ActivePlayer != 1) {
            if (((((char)match_count == '\0') && ((slot_idx & 0xffff) == 0)) &&
                ((player_idx[0] & 0xffffff) == 0)) && (player_idx[1] == 0)) {
              *(int32_t *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20)
                   = 0;
            }
            else {
              *(int32_t *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20)
                   = 1;
            }
          }
        }
      }
      else {
        g_ActivePlayer = 1;
      }
    }
    if (flags == 0x72) {
      match_count = *(uint32_t *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) >>
                0x18;
      slot_idx = (*(uint32_t *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) &
                0xff0000) >> 0x10;
      player_idx[0] = (uint32_t)(uint8_t)(&DAT_006a5f55)[target_id * 0x120 + spell_id * 0x5b20];
      player_idx[1] = *(uint32_t *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20)
                    & 0xff;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      val_6 = -1;
      val_5 = -1;
      uval_4 = 0;
      uval_3 = 0;
      uval_2 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_5 = Rules_ParseFilter_0040360b
                        (match_count,slot_idx,(char *)0x0,1,1,1,0x200,2,0,0,uval_2,uval_3,uval_4,val_5,val_6
                         ,uval_7,uval_8,uVar9,uVar10,uVar11);
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      arg_15 = -1;
      val_6 = -1;
      uval_4 = 0;
      uval_3 = 0;
      uval_2 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_6 = Rules_ParseFilter_0040360b
                        (player_idx[0],player_idx[1],(char *)0x0,0,0,0,0x200,2,0,0,uval_2,uval_3,uval_4,
                         val_6,arg_15,uval_7,uval_8,uVar9,uVar10,uVar11);
      if ((val_5 == 0) || (val_6 == 0)) {
        if ((val_5 == 0) || (val_6 != 0)) {
          if (((val_5 == 0) && (val_6 != 0)) &&
             (*(uint32_t *)(&g_CardSlot_Flags + player_idx[0] * 0x5b20 + player_idx[1] * 0x120) =
                   *(uint32_t *)(&g_CardSlot_Flags + player_idx[0] * 0x5b20 + player_idx[1] * 0x120) | 0x10,
             *(int *)(&g_CardSlot_CardId + slot_idx * 0x120 + match_count * 0x5b20) != -1)) {
            val_5 = Magic_QueryCardAttribute(match_count,slot_idx,0x32,0xffffffff);
            Card_ApplyCombatDamage(player_idx[0],player_idx[1],val_5,match_count,slot_idx);
          }
        }
        else {
          *(uint32_t *)(&g_CardSlot_Flags + match_count * 0x5b20 + slot_idx * 0x120) =
               *(uint32_t *)(&g_CardSlot_Flags + match_count * 0x5b20 + slot_idx * 0x120) | 0x10;
          if (*(int *)(&g_CardSlot_CardId + player_idx[1] * 0x120 + player_idx[0] * 0x5b20) != -1) {
            val_5 = Magic_QueryCardAttribute(player_idx[0],player_idx[1],0x32,0xffffffff);
            Card_ApplyCombatDamage(match_count,slot_idx,val_5,player_idx[0],player_idx[1]);
          }
        }
      }
      else {
        *(uint32_t *)(&g_CardSlot_Flags + match_count * 0x5b20 + slot_idx * 0x120) =
             *(uint32_t *)(&g_CardSlot_Flags + match_count * 0x5b20 + slot_idx * 0x120) | 0x10;
        *(uint32_t *)(&g_CardSlot_Flags + player_idx[0] * 0x5b20 + player_idx[1] * 0x120) =
             *(uint32_t *)(&g_CardSlot_Flags + player_idx[0] * 0x5b20 + player_idx[1] * 0x120) | 0x10;
        val_5 = Magic_QueryCardAttribute(match_count,slot_idx,0x32,0xffffffff);
        val_6 = Magic_QueryCardAttribute(player_idx[0],player_idx[1],0x32,0xffffffff);
        Card_ApplyCombatDamage(match_count,slot_idx,val_6,player_idx[0],player_idx[1]);
        Card_ApplyCombatDamage(player_idx[0],player_idx[1],val_5,match_count,slot_idx);
      }
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: Minit_Subsystem_00456d10
 * Entry Point: 00456d10
 * Size: 38 bytes
 */


void Minit_Subsystem_00456d10(int player_id,int card_slot,int event_type)

{
  Minit_Subsystem_00456dce(player,card_slot,arg_3,3);
  return;
}



/*
 * Decompiled function: Minit_Subsystem_00456d36
 * Entry Point: 00456d36
 * Size: 38 bytes
 */


void Minit_Subsystem_00456d36(int player_id,int card_slot,int event_type)

{
  Minit_Subsystem_00456dce(player,card_slot,arg_3,1);
  return;
}



/*
 * Decompiled function: Minit_Subsystem_00456d5c
 * Entry Point: 00456d5c
 * Size: 38 bytes
 */


void Minit_Subsystem_00456d5c(int player_id,int card_slot,int event_type)

{
  Minit_Subsystem_00456dce(player,card_slot,arg_3,5);
  return;
}



/*
 * Decompiled function: Minit_Subsystem_00456d82
 * Entry Point: 00456d82
 * Size: 38 bytes
 */


void Minit_Subsystem_00456d82(int player_id,int card_slot,int event_type)

{
  Minit_Subsystem_00456dce(player,card_slot,arg_3,4);
  return;
}



/*
 * Decompiled function: Minit_Subsystem_00456da8
 * Entry Point: 00456da8
 * Size: 38 bytes
 */


void Minit_Subsystem_00456da8(int player_id,int card_slot,int event_type)

{
  Minit_Subsystem_00456dce(player,card_slot,arg_3,2);
  return;
}



/*
 * Decompiled function: Minit_Subsystem_00456dce
 * Entry Point: 00456dce
 * Size: 347 bytes
 */


int32_t Minit_Subsystem_00456dce(int x,int y,int width,int height)

{
  int32_t uval_1;
  
  if (width == 0x73) {
    if (((((&g_CardSlot_Subtypes)[y * 0x120 + x * 0x5b20] & 3) == 0) ||
        (((&g_MasterCardColorTable)[*(int *)(&g_CardSlot_CardId + y * 0x120 + x * 0x5b20) * 0x34] &
         2) == 0)) && (((&g_CardSlot_Flags)[y * 0x120 + x * 0x5b20] & 0x10) == 0)) {
      uval_1 = 1;
    }
    else {
      uval_1 = 0;
    }
  }
  else {
    if (width == 0x6d) {
      g_SpellStackDepth = g_SpellStackDepth + -0xc;
      FUN_0040d901(x,height,1);
      *(uint32_t *)(&g_CardSlot_Flags + y * 0x120 + x * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_Flags + y * 0x120 + x * 0x5b20) | 0x10;
      g_PendingAttackersTargetSlot = height;
    }
    if ((((width == 0x7f) && (y == g_EventSourceSlot)) && (x == g_EventSourcePlayer)) &&
       (((&g_CardSlot_Flags)[y * 0x120 + x * 0x5b20] & 0x10) == 0)) {
      FUN_0040d7e9(x,height,1);
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: Mana_Init_00456f29
 * Entry Point: 00456f29
 * Size: 897 bytes
 */


int32_t Mana_Init_00456f29(int spell_id,int target_id,int flags)

{
  int32_t uval_1;
  int card_slot;
  char *mode_str;
  int card_idx;
  int match_count;
  
  if (flags == 0x73) {
    if (((((&g_CardSlot_Subtypes)[target_id * 0x120 + spell_id * 0x5b20] & 3) == 0) ||
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) * 0x34] & 2) == 0))
       && (((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0)) {
      uval_1 = 1;
    }
    else {
      uval_1 = 0;
    }
  }
  else {
    if (flags == 0x6d) {
      g_SpellStackDepth = g_SpellStackDepth + -0x24;
      if (((spell_id == 1) || (g_IsAiThinking == 1)) || (g_AiTurnDecisionFlag != 0)) {
        card_idx = -1;
        match_count = 1;
        while ((match_count < 6 && (card_idx == -1))) {
          if ((0 < (&g_AiSelectedTargetCard)[match_count]) &&
             (((int)(char)(&g_CardSlot_PlusOneCounters)[target_id * 0x120 + spell_id * 0x5b20] &
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
        Pic_Subsystem_00424500(s_prompts_txt_005241ec,s_BLACK_LOTUS_005241e0);
        card_slot = Ai_Subsystem_004cc93d
                          (spell_id,&g_OverworldGoldAmount,1,card_idx,
                           (int)(char)(&g_CardSlot_PlusOneCounters)[target_id * 0x120 + spell_id * 0x5b20]);
        if (card_slot == -1) {
          g_ActivePlayer = 1;
        }
        else {
          FUN_0040d875(spell_id,card_slot,3);
          g_PendingAttackersTargetSlot = card_slot;
          if (g_IsAiThinking != 1) {
            Duel_PlaySoundById(0xf);
          }
          *(uint32_t *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) =
               *(uint32_t *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
          if (g_CurrentTurnPhase != spell_id) {
            strcpy(&g_OverworldWorldState,s_to_produce_005241f8);
            str_2 = (char *)Mem_AllocOrFree_00473d7e(card_slot);
            strcat(&g_OverworldWorldState,str_2);
            strcat(&g_OverworldWorldState,s_mana__00524204);
            Ai_Subsystem_004cc56d(spell_id,spell_id,target_id,-1,-1,&g_OverworldWorldState,0);
          }
          Pic_Subsystem_0044867e(spell_id,target_id,3);
        }
      }
    }
    if ((((flags == 0x7f) && (g_EventSourceSlot == target_id)) &&
        (g_EventSourcePlayer == spell_id)) &&
       (((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0)) {
      FUN_0040d59c(spell_id,(int)(char)(&g_CardSlot_PlusOneCounters)[target_id * 0x120 + spell_id * 0x5b20],3);
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: CardScript_TimeVault
 * Entry Point: 004572aa
 * Size: 1181 bytes
 */


int32_t CardScript_TimeVault(int spell_id,int target_id,int flags)

{
  bool flag_1;
  int val_2;
  int32_t uval_3;
  int match_count;
  int slot_idx;
  
  if ((flags == 0x82) &&
     (*(int *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) != 0)) {
    *(uint32_t *)(&g_CardSlot_ProtectionFlags + spell_id * 0x5b20 + target_id * 0x120) =
         *(uint32_t *)(&g_CardSlot_ProtectionFlags + spell_id * 0x5b20 + target_id * 0x120) & 0xfffffffc;
  }
  if (((flags == 0x6c) && (target_id == g_EventSourceSlot)) &&
     (spell_id == g_EventSourcePlayer)) {
    g_SpellStackDepth = g_SpellStackDepth + 0x18;
    *(uint32_t *)(&g_CardSlot_Flags + spell_id * 0x5b20 + target_id * 0x120) =
         *(uint32_t *)(&g_CardSlot_Flags + spell_id * 0x5b20 + target_id * 0x120) | 0x10;
    *(int32_t *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) = 1;
  }
  if (((flags == 0x6a) && (spell_id == g_TurnPlayer)) &&
     ((((&g_CardSlot_Flags)[spell_id * 0x5b20 + target_id * 0x120] & 0x10) != 0 &&
      (val_2 = Glue_Subsystem_004e6978(spell_id,target_id), val_2 == 0)))) {
    Pic_Subsystem_0042475a(s_prompts_txt_00524218,s_TIME_VAULT_0052420c);
    val_2 = Util_GetRandomNumber(5);
    val_2 = Ai_Subsystem_004cc56d
                      (spell_id,spell_id,target_id,-1,-1,&g_OverworldGoldAmount,(uint32_t)(val_2 < 1));
    if (val_2 != 0) {
      g_DuelModeFlags = g_DuelModeFlags | 0x8000;
      *(uint32_t *)(&g_CardSlot_Flags + spell_id * 0x5b20 + target_id * 0x120) =
           *(uint32_t *)(&g_CardSlot_Flags + spell_id * 0x5b20 + target_id * 0x120) & 0xffffffef;
      Glue_Subsystem_004e66b3(spell_id,target_id);
      *(int32_t *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) = 0;
    }
  }
  if (flags == 0x73) {
    if ((((((&g_CardSlot_Subtypes)[spell_id * 0x5b20 + target_id * 0x120] & 3) == 0) ||
         (((&g_MasterCardColorTable)
           [*(int *)(&g_CardSlot_CardId + spell_id * 0x5b20 + target_id * 0x120) * 0x34] & 2) == 0))
        && (((&g_CardSlot_Flags)[spell_id * 0x5b20 + target_id * 0x120] & 0x10) == 0)) &&
       (val_2 = Glue_Subsystem_004e6978(spell_id,target_id), val_2 != 0)) {
      uval_3 = 1;
    }
    else {
      uval_3 = 0;
    }
  }
  else {
    if (((flags == 0x6d) &&
        (((&g_CardSlot_Flags)[spell_id * 0x5b20 + target_id * 0x120] & 0x10) == 0)) &&
       (val_2 = Glue_Subsystem_004e6978(spell_id,target_id), val_2 != 0)) {
      *(uint32_t *)(&g_CardSlot_Flags + spell_id * 0x5b20 + target_id * 0x120) =
           *(uint32_t *)(&g_CardSlot_Flags + spell_id * 0x5b20 + target_id * 0x120) | 0x10;
    }
    if (flags == 0x72) {
      val_2 = rand();
      if (val_2 % 5 < 1) {
        g_SpellStackDepth = g_SpellStackDepth + 0x30;
      }
      if (DAT_006ff2d8 == -1) {
        flag_1 = false;
        match_count = 0;
        while ((match_count < 2 && (!flag_1))) {
          for (slot_idx = 0; slot_idx < (int)(&g_PlayerActiveCardCount)[match_count];
              slot_idx = slot_idx + 1) {
            if ((*(int *)(&g_CardSlot_CardId + slot_idx * 0x120 + match_count * 0x5b20) == DAT_006a4b64)
               && (((&DAT_006a5f69)[slot_idx * 0x120 + match_count * 0x5b20] & 1) != 0)) {
              flag_1 = true;
            }
          }
          match_count = match_count + 1;
        }
        if (!flag_1) {
          DAT_006ff2d8 = spell_id;
        }
      }
      Glue_Subsystem_004e676b(g_DialogPromptHwnd,g_DuelArenaHwnd);
      *(int32_t *)
       (&g_CardSlot_ConvertedManaCost +
       *(int *)(&g_CardSlot_TapState + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + spell_id * 0x5b20 + target_id * 0x120) * 0x120) = 1;
      val_2 = Card_ApplyTriggerEffect(g_DialogPromptHwnd,g_DuelArenaHwnd,DAT_006a4b64,-1,-1);
      *(uint32_t *)(&g_CardSlot_Abilities1 + val_2 * 0x120 + spell_id * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_Abilities1 + val_2 * 0x120 + spell_id * 0x5b20) | 0x120;
    }
    uval_3 = 0;
  }
  return uval_3;
}



/*
 * Decompiled function: Minit_Subsystem_00457747
 * Entry Point: 00457747
 * Size: 562 bytes
 */


int32_t Minit_Subsystem_00457747(int player_id,int card_slot,int event_type)

{
  int val_1;
  int match_count;
  
  if ((arg_3 == 199) && (((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 2) != 0)) {
    if (((&DAT_006a5f3d)[card_slot * 0x120 + player * 0x5b20] & 0x10) == 0) {
      match_count = g_ActivePlayerPriority;
    }
    else {
      match_count = g_CurrentTurnPhase;
    }
    val_1 = (&g_ActivePlayerSpellPriority)[match_count] + -4;
    if (val_1 < 1) {
      val_1 = 0;
    }
    if (val_1 != 0) {
      if (match_count == 0) {
        val_1 = 0x18 - (int)(&g_PlayerCreatureCount)[match_count] / val_1;
        if (val_1 < 2) {
          val_1 = 1;
        }
        g_SpellStackDepth = g_SpellStackDepth + val_1 * 0x18;
      }
      else {
        val_1 = 0x18 - (int)(&g_PlayerCreatureCount)[match_count] / val_1;
        if (val_1 < 2) {
          val_1 = 1;
        }
        g_SpellStackDepth = g_SpellStackDepth + val_1 * -0x18;
      }
    }
  }
  if ((((g_CurrentStepCode == 0xcb) && (card_slot == g_EventSourceSlot)) &&
      (player == g_EventSourcePlayer)) &&
     ((((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) == 0 ||
      (((&g_MasterCardColorTable)
        [*(int *)(&g_CardSlot_CardId + card_slot * 0x120 + player * 0x5b20) * 0x34] & 2) != 0)))) {
    if (((&DAT_006a5f3d)[card_slot * 0x120 + player * 0x5b20] & 0x10) == 0) {
      match_count = g_ActivePlayerPriority;
    }
    else {
      match_count = g_CurrentTurnPhase;
    }
    if ((match_count == g_TurnPlayer) && (4 < (int)(&g_ActivePlayerSpellPriority)[match_count])) {
      if (arg_3 == 0x7d) {
        g_CardEventResult = g_CardEventResult | 2;
      }
      if (arg_3 == 0x7e) {
        Mem_AllocOrFree_0041df33(match_count,(&g_ActivePlayerSpellPriority)[match_count] + -4,player,card_slot);
      }
    }
  }
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_00457979
 * Entry Point: 00457979
 * Size: 566 bytes
 */


int32_t Minit_Subsystem_00457979(int player_id,int card_slot,int event_type)

{
  int val_1;
  int match_count;
  
  if ((arg_3 == 199) && (((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 2) != 0)) {
    if (((&DAT_006a5f3d)[card_slot * 0x120 + player * 0x5b20] & 0x10) == 0) {
      match_count = g_ActivePlayerPriority;
    }
    else {
      match_count = g_CurrentTurnPhase;
    }
    val_1 = 3 - (&g_ActivePlayerSpellPriority)[match_count];
    if (val_1 < 1) {
      val_1 = 0;
    }
    if (val_1 != 0) {
      if (match_count == 0) {
        val_1 = 0x18 - (int)(&g_PlayerCreatureCount)[match_count] / val_1;
        if (val_1 < 2) {
          val_1 = 1;
        }
        g_SpellStackDepth = g_SpellStackDepth + val_1 * 0x18;
      }
      else {
        val_1 = 0x18 - (int)(&g_PlayerCreatureCount)[match_count] / val_1;
        if (val_1 < 2) {
          val_1 = 1;
        }
        g_SpellStackDepth = g_SpellStackDepth + val_1 * -0x18;
      }
    }
  }
  if ((((g_CurrentStepCode == 0xcb) && (card_slot == g_EventSourceSlot)) &&
      (player == g_EventSourcePlayer)) &&
     ((((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) == 0 ||
      (((&g_MasterCardColorTable)
        [*(int *)(&g_CardSlot_CardId + card_slot * 0x120 + player * 0x5b20) * 0x34] & 2) != 0)))) {
    if (((&DAT_006a5f3d)[card_slot * 0x120 + player * 0x5b20] & 0x10) == 0) {
      match_count = g_ActivePlayerPriority;
    }
    else {
      match_count = g_CurrentTurnPhase;
    }
    if ((match_count == g_TurnPlayer) && ((int)(&g_ActivePlayerSpellPriority)[match_count] < 3)) {
      if (arg_3 == 0x7d) {
        g_CardEventResult = g_CardEventResult | 2;
      }
      if (arg_3 == 0x7e) {
        Mem_AllocOrFree_0041df33(match_count,3 - (&g_ActivePlayerSpellPriority)[match_count],player,card_slot);
      }
    }
  }
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_00457baf
 * Entry Point: 00457baf
 * Size: 428 bytes
 */


int32_t Minit_Subsystem_00457baf(int player_id,int card_slot,int event_type)

{
  int val_1;
  
  if ((arg_3 == 199) && (((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 2) != 0)) {
    val_1 = (&g_ActivePlayerSpellPriority)[player] + -4;
    if (val_1 < 1) {
      val_1 = 0;
    }
    if (player == 0) {
      if (val_1 < 2) {
        val_1 = 1;
      }
      g_SpellStackDepth = g_SpellStackDepth + val_1 * -0x18;
    }
    else {
      if (val_1 < 2) {
        val_1 = 1;
      }
      g_SpellStackDepth = g_SpellStackDepth + val_1 * 0x18;
    }
  }
  if (((((g_CurrentStepCode == 0xc9) && (card_slot == g_EventSourceSlot)) &&
       (player == g_EventSourcePlayer)) &&
      ((player == g_TurnPlayer && (g_CurrentCardColorTarget == player)))) &&
     ((4 < (int)(&g_ActivePlayerSpellPriority)[player] &&
      ((((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) == 0 ||
       (((&g_MasterCardColorTable)
         [*(int *)(&g_CardSlot_CardId + card_slot * 0x120 + player * 0x5b20) * 0x34] & 2) != 0)))))) {
    if (arg_3 == 0x7d) {
      g_CardEventResult = g_CardEventResult | 2;
    }
    if ((arg_3 == 0x7e) && (4 < (int)(&g_ActivePlayerSpellPriority)[player])) {
      (&g_PlayerCreatureCount)[player] =
           (&g_PlayerCreatureCount)[player] + (&g_ActivePlayerSpellPriority)[player] + -4;
    }
  }
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_00457d5b
 * Entry Point: 00457d5b
 * Size: 268 bytes
 */


int32_t Minit_Subsystem_00457d5b(int player_id,int card_slot,int event_type)

{
  int slot_idx;
  
  if ((arg_3 == 0x1f) &&
     ((((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) == 0 ||
      (((&g_MasterCardColorTable)
        [*(int *)(&g_CardSlot_CardId + card_slot * 0x120 + player * 0x5b20) * 0x34] & 2) != 0)))) {
    if (((&DAT_006a5f3d)[card_slot * 0x120 + player * 0x5b20] & 0x10) == 0) {
      slot_idx = g_ActivePlayerPriority;
    }
    else {
      slot_idx = g_CurrentTurnPhase;
    }
    if ((g_TurnPlayer == slot_idx) && (4 < (int)(&g_ActivePlayerSpellPriority)[g_TurnPlayer])) {
      g_CardEventResult = g_CardEventResult | 1;
      while (4 < (int)(&g_ActivePlayerSpellPriority)[g_TurnPlayer]) {
        Prompts_Load_0046fa40(g_TurnPlayer,0,0);
      }
    }
  }
  return 0;
}



/*
 * Decompiled function: CardScript_AladdinsLamp
 * Entry Point: 00457e67
 * Size: 1839 bytes
 */


int32_t CardScript_AladdinsLamp(int spell_id,int target_id,int flags)

{
  bool flag_1;
  bool flag_2;
  int val_3;
  int local_164;
  int local_160;
  int local_15c;
  int local_150 [80];
  int card_idx;
  int match_count;
  int32_t slot_idx;
  
  if ((((g_CurrentStepCode == 0xcf) &&
       (((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0)) &&
      (val_3 = Font_DrawString(spell_id, 7, 1), val_3 != 0)) &&
     (((g_EventSourceSlot == target_id && (g_EventSourcePlayer == spell_id)) &&
      (g_CurrentCardColorTarget == spell_id)))) {
    if (flags == 0x7d) {
      if (g_ActivePlayerPriority == spell_id) {
        if (((*(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) != 0)
            && (card_idx = Font_DrawString(spell_id,7,3), card_idx != 0)) &&
           (g_CardEventResult = g_CardEventResult | 2,
           *(int *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) == 0)) {
          val_3 = Util_GetRandomNumber(card_idx + -2);
          *(int *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) = val_3 + 2;
          DAT_0062785c = *(int32_t *)
                          (&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20);
        }
      }
      else {
        g_CardEventResult = g_CardEventResult | 1;
      }
    }
    if (flags == 0x7e) {
      *(int32_t *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) = 0;
      val_3 = g_TurnCounter;
      slot_idx = g_OverworldPlayerCoordY;
      g_OverworldPlayerCoordY = 0xffffffff;
      if (((g_CurrentTurnPhase == spell_id) && (g_IsAiThinking != 1)) && (g_AiTurnDecisionFlag == 0)) {
        Magic_PushSpellStack(spell_id,target_id,0x72,0,0);
        Ai_CalcManaRequirement_004ba890(spell_id,0,-1);
        Magic_DropTopSpell();
        local_164 = g_TurnCounter;
      }
      else {
        local_164 = Ai_CalcManaRequirement_004ba890
                              (spell_id,0,
                               *(int *)(&g_CardSlot_TargetSlot +
                                       target_id * 0x120 + spell_id * 0x5b20));
        if (local_164 == 0) {
          g_ActivePlayer = 1;
        }
        *(int32_t *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) = 0;
      }
      g_OverworldPlayerCoordY = slot_idx;
      g_TurnCounter = val_3;
      if ((g_ActivePlayer == 1) || (local_164 < 1)) {
        g_ActivePlayer = -1;
      }
      else {
        *(uint32_t *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
        card_idx = 0;
        for (local_160 = 0; local_160 < local_164; local_160 = local_160 + 1) {
          if (*(int *)(&g_PlayerDeckCardList + local_160 * 4 + spell_id * 2000) != -1) {
            local_150[card_idx] = *(int *)(&g_PlayerDeckCardList + local_160 * 4 + spell_id * 2000);
            card_idx = card_idx + 1;
          }
        }
        local_150[card_idx] = -1;
        if (((g_CurrentTurnPhase == spell_id) && (g_IsAiThinking != 1)) && (g_AiTurnDecisionFlag == 0)) {
          Pic_Subsystem_00424500(s_prompts_txt_00524234,s_ALADDINS_LAMP_00524224);
          local_15c = UI_DeckSelectionMenu(spell_id,(int)local_150,card_idx,&g_OverworldGoldAmount,1);
        }
        else {
          local_15c = FUN_004fdc20(spell_id,spell_id,2,(int)local_150);
          if (local_15c == -1) {
            local_15c = 0;
          }
        }
        if (card_idx != 0) {
          Deck_AddCardToDeck(spell_id,local_150[local_15c]);
          for (local_160 = 0; local_160 < card_idx; local_160 = local_160 + 1) {
            Pic_Subsystem_004523fd(spell_id,0);
          }
          local_150[local_15c] = -1;
          flag_2 = false;
          while (!flag_2) {
            local_160 = 0;
            do {
              local_15c = Util_GetRandomNumber(local_164);
              if (local_150[local_15c] != -1) break;
              flag_1 = local_160 < 999;
              local_160 = local_160 + 1;
            } while (flag_1);
            if (local_150[local_15c] == -1) {
              for (local_160 = 0; local_160 < local_164; local_160 = local_160 + 1) {
                if (local_150[local_160] != -1) {
                  local_15c = local_160;
                }
              }
            }
            if (local_150[local_15c] == -1) {
              flag_2 = true;
            }
            else {
              Pic_Subsystem_0045245e(spell_id,local_150[local_15c]);
              local_150[local_15c] = -1;
            }
          }
        }
        DAT_006fe408 = 1;
      }
    }
  }
  if ((flags == 0x6a) && (g_ActivePlayerPriority == spell_id)) {
    *(int32_t *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) = 0;
    match_count = 0;
    card_idx = 0;
    for (local_160 = 0; local_160 < (int)(&g_PlayerActiveCardCount)[g_ActivePlayerPriority];
        local_160 = local_160 + 1) {
      if ((((*(int *)(&g_CardSlot_CardId + local_160 * 0x120 + g_ActivePlayerPriority * 0x5b20) !=
             -1) && (((&g_CardSlot_Flags)[local_160 * 0x120 + g_ActivePlayerPriority * 0x5b20] & 2)
                     != 0)) &&
          (((&g_MasterCardFlagsTable)
            [*(int *)(&g_CardSlot_CardId + local_160 * 0x120 + g_ActivePlayerPriority * 0x5b20) *
             0x34] & 0x10) != 0)) &&
         (card_idx = card_idx + 1,
         ((&g_CardSlot_Flags)[local_160 * 0x120 + g_ActivePlayerPriority * 0x5b20] & 0x10) == 0)) {
        match_count = match_count + 1;
      }
    }
    if (0x50 < (match_count * 100) / card_idx) {
      *(int32_t *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) = 2;
    }
  }
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_00458596
 * Entry Point: 00458596
 * Size: 322 bytes
 */


int32_t Minit_Subsystem_00458596(int player_id,int card_slot,int event_type)

{
  int val_1;
  int32_t uval_2;
  
  if (arg_3 == 0x73) {
    val_1 = Font_DrawString(player,7,2);
    if ((val_1 == 0) ||
       (((((&g_CardSlot_Subtypes)[player * 0x5b20 + card_slot * 0x120] & 3) != 0 &&
         (((&g_MasterCardColorTable)
           [*(int *)(&g_CardSlot_CardId + player * 0x5b20 + card_slot * 0x120) * 0x34] & 2) != 0)) ||
        (((&g_CardSlot_Flags)[player * 0x5b20 + card_slot * 0x120] & 0x10) != 0)))) {
      uval_2 = 0;
    }
    else {
      uval_2 = 1;
    }
  }
  else {
    if ((arg_3 == 0x6d) && (val_1 = Font_DrawString(player,7,2), val_1 != 0)) {
      Ai_CalcManaRequirement_004ba890(player,0,2);
    }
    if (arg_3 == 0x72) {
      Magic_ExecuteDrawPhase(player);
      Prompts_Load_0046fa40(player,0,0);
      *(uint32_t *)(&g_CardSlot_Flags + player * 0x5b20 + card_slot * 0x120) =
           *(uint32_t *)(&g_CardSlot_Flags + player * 0x5b20 + card_slot * 0x120) | 0x10;
    }
    uval_2 = 0;
  }
  return uval_2;
}



/*
 * Decompiled function: Minit_Subsystem_004586d8
 * Entry Point: 004586d8
 * Size: 445 bytes
 */


int32_t Minit_Subsystem_004586d8(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  int slot_idx;
  
  if (arg_3 == 0x73) {
    if (((((&g_CardSlot_Subtypes)[card_slot * 0x120 + player * 0x5b20] & 3) == 0) ||
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId + card_slot * 0x120 + player * 0x5b20) * 0x34] & 2) == 0)) &&
       (((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) == 0)) {
      uval_1 = 1;
    }
    else {
      uval_1 = 0;
    }
  }
  else {
    if ((arg_3 == 0x6d) && (((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) == 0)) {
      *(uint32_t *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) | 0x10;
      Pic_Subsystem_0044867e(player,card_slot,4);
    }
    if (arg_3 == 0x72) {
      for (slot_idx = 0; slot_idx < 500; slot_idx = slot_idx + 1) {
        if (*(int *)(&g_PlayerGraveyardList + slot_idx * 4 + player * 2000) != -1) {
          Pic_Subsystem_0045245e(player,*(int32_t *)(&g_PlayerGraveyardList + slot_idx * 4 + player * 2000));
          *(int32_t *)(&g_PlayerGraveyardList + slot_idx * 4 + player * 2000) = 0xffffffff;
        }
      }
      Ai_EvaluateTacticalPosition(0,0x30);
      Pic_Subsystem_00452276(player);
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: Minit_Subsystem_00458895
 * Entry Point: 00458895
 * Size: 882 bytes
 */


int32_t Minit_Subsystem_00458895(int player_id,int card_slot,int event_type)

{
  uint8_t uval_1;
  int val_2;
  int target_idx;
  
  if (arg_3 != 0x73) {
    if ((((arg_3 == 2) && (card_slot == g_EventSourceSlot)) && (player == g_EventSourcePlayer)) &&
       (val_2 = Font_DrawString(player,7,2), val_2 != 0)) {
      g_CardEventResult = g_CardEventResult | 1;
    }
    if (((arg_3 == 4) && (card_slot == g_EventSourceSlot)) &&
       ((player == g_EventSourcePlayer &&
        ((val_2 = Font_DrawString(player,7,2), val_2 != 0 &&
         (Ai_CalcManaRequirement_004ba890(player,0,2), target_idx != -1)))))) {
      val_2 = Card_RemapColorIndexFF(player,card_slot,1);
      uval_1 = Card_RemapColorIndexFF(player,card_slot,1);
      *(int32_t *)
       (&g_CardSlot_ConvertedManaCost +
       *(int *)(&g_CardSlot_CombatTarget + player * 0x5b20 + card_slot * 0x120) * 0x5b20 +
       *(int *)(&g_CardSlot_AttachedAura + player * 0x5b20 + card_slot * 0x120) * 0x120) =
           *(int32_t *)
            (&g_CardSlot_CardId +
            *(int *)(&g_CardSlot_CombatTarget + player * 0x5b20 + card_slot * 0x120) * 0x5b20 +
            *(int *)(&g_CardSlot_AttachedAura + player * 0x5b20 + card_slot * 0x120) * 0x120);
      *(int *)(&g_CardSlot_CardId +
              *(int *)(&g_CardSlot_CombatTarget + player * 0x5b20 + card_slot * 0x120) * 0x5b20 +
              *(int *)(&g_CardSlot_AttachedAura + player * 0x5b20 + card_slot * 0x120) * 0x120) =
           val_2 + -1;
      (&g_CardSlot_PlusOneCounters)
      [*(int *)(&g_CardSlot_CombatTarget + player * 0x5b20 + card_slot * 0x120) * 0x5b20 +
       *(int *)(&g_CardSlot_AttachedAura + player * 0x5b20 + card_slot * 0x120) * 0x120] = uval_1;
      *(uint32_t *)(&g_CardSlot_Abilities1 +
               *(int *)(&g_CardSlot_AttachedAura + player * 0x5b20 + card_slot * 0x120) * 0x120 +
               *(int *)(&g_CardSlot_CombatTarget + player * 0x5b20 + card_slot * 0x120) * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_Abilities1 +
                    *(int *)(&g_CardSlot_AttachedAura + player * 0x5b20 + card_slot * 0x120) * 0x120 +
                    *(int *)(&g_CardSlot_CombatTarget + player * 0x5b20 + card_slot * 0x120) * 0x5b20) |
           0x200;
    }
    if (((arg_3 == 0x77) && (card_slot == g_EventSourceSlot)) && (player == g_EventSourcePlayer)) {
      val_2 = Pic_Subsystem_0045268f(0x391);
      val_2 = Deck_AddCardToDeck(player,val_2);
      if (val_2 != -1) {
        *(uint32_t *)(&g_CardSlot_Flags + val_2 * 0x120 + player * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_Flags + val_2 * 0x120 + player * 0x5b20) | 2;
      }
    }
  }
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_00458c07
 * Entry Point: 00458c07
 * Size: 104 bytes
 */


int32_t Minit_Subsystem_00458c07(int player_id,int card_slot,int event_type)

{
  if (((arg_3 == 2) && (g_EventSourceSlot == card_slot)) && (g_EventSourcePlayer == player)) {
    Glue_Subsystem_004e65e1(Minit_Subsystem_00458c6f,-1);
    if (g_CardEventResult == 0) {
      Pic_Subsystem_0044867e(player,card_slot,4);
    }
  }
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_00458c6f
 * Entry Point: 00458c6f
 * Size: 63 bytes
 */


int32_t Minit_Subsystem_00458c6f(int arg1,int arg2)

{
  if (((&DAT_006a5f69)[arg2 * 0x120 + arg1 * 0x5b20] & 2) != 0) {
    g_CardEventResult = g_CardEventResult | 2;
  }
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_00458cae
 * Entry Point: 00458cae
 * Size: 1030 bytes
 */


int32_t Minit_Subsystem_00458cae(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  int val_2;
  
  if (arg_3 == 0x73) {
    if ((((DAT_006a282c | g_PlayerPoisonCounters) & 2) == 0) ||
       (((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) != 0)) {
      uval_1 = 0;
    }
    else {
      uval_1 = 1;
    }
  }
  else if (arg_3 == 0x90) {
    Ai_PeekPlannedSlot(0);
    uval_1 = 0;
  }
  else {
    if ((arg_3 == 0x6d) &&
       ((&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20] = g_TemporaryToughnessBuffer,
       ((&g_MasterCardColorTable)
        [*(int *)(&g_CardSlot_CardId +
                 *(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) * 0x120 +
                 (char)(&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20] * 0x5b20) * 0x34] &
       0x40) != 0)) {
      g_ActivePlayer = 1;
    }
    if ((arg_3 == 0x72) &&
       (*(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) != -1)) {
      if (((&g_MasterCardColorTable)
           [*(int *)(&g_CardSlot_CardId +
                    *(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) * 0x120 +
                    (char)(&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20] * 0x5b20) * 0x34]
          & 0x40) == 0) {
        val_2 = Card_ApplyTriggerEffect(player,card_slot,g_PlayerSelectionPriority,
                             (int)(char)(&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20],
                             *(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20));
        if (val_2 != -1) {
          *(int16_t *)(&g_CardSlot_PowerCounters + val_2 * 0x120 + player * 0x5b20) = 1;
          *(int16_t *)(&g_CardSlot_ToughnessCounters + val_2 * 0x120 + player * 0x5b20) = 1;
          *(uint32_t *)(&g_CardSlot_Abilities1 + val_2 * 0x120 + player * 0x5b20) =
               *(uint32_t *)(&g_CardSlot_Abilities1 + val_2 * 0x120 + player * 0x5b20) | 0x20;
        }
        val_2 = FUN_0041d8a6(*(int *)(&g_CardSlot_CardId +
                                     *(int *)(&g_CardSlot_OriginalCardId +
                                             card_slot * 0x120 + player * 0x5b20) * 0x120 +
                                     (char)(&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20] *
                                     0x5b20));
        if (val_2 != -1) {
          (&g_MasterCardColorTable)[val_2 * 0x34] = 0x42;
          *(int *)(&g_CardSlot_CardId +
                  *(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) * 0x120 +
                  (char)(&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20] * 0x5b20) = val_2;
        }
        (&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20] = 0xff;
        *(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) =
             (int)(char)(&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20];
      }
      Pic_Subsystem_0044867e(player,card_slot,1);
    }
    if (arg_3 == 0x3b) {
      *(int *)(&DAT_00695eb0 + player * 4) = *(int *)(&DAT_00695eb0 + player * 4) + 1;
      *(int *)(&DAT_00695eb8 + player * 4) = *(int *)(&DAT_00695eb8 + player * 4) + 1;
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: Card_Setup_004590b4
 * Entry Point: 004590b4
 * Size: 506 bytes
 */


int32_t Card_Setup_004590b4(int player_id,int card_slot,int event_type)

{
  if ((((arg_3 == 0x85) && (card_slot == g_EventSourceSlot)) && (player == g_EventSourcePlayer)) &&
     ((player == g_TurnPlayer && (g_CurrentTurnTargetPlayer == player)))) {
    *(uint32_t *)(&g_CardSlot_SpecialState + card_slot * 0x120 + player * 0x5b20) =
         *(uint32_t *)(&g_CardSlot_SpecialState + card_slot * 0x120 + player * 0x5b20) | 1;
  }
  if (((arg_3 == 4) && (card_slot == g_EventSourceSlot)) && (player == g_EventSourcePlayer)) {
    if ((int)(&g_ActivePlayerSpellPriority)[player] < 1) {
      g_CardEventResult = g_CardEventResult | 1;
    }
    else {
      Prompts_Load_0046fa40(player,0,1);
    }
  }
  if (arg_3 == 0x86) {
    Ai_Subsystem_004cc56d(player,player,card_slot,-1,-1,s_Unable_to_discard____Mishra_s_Wa_00524248,0);
    *(uint32_t *)(&g_CardSlot_Flags +
             *(int *)(&g_CardSlot_SicknessState + card_slot * 0x120 + player * 0x5b20) * 0x120 +
             *(int *)(&g_CardSlot_TapState + card_slot * 0x120 + player * 0x5b20) * 0x5b20) =
         *(uint32_t *)(&g_CardSlot_Flags +
                  *(int *)(&g_CardSlot_SicknessState + card_slot * 0x120 + player * 0x5b20) * 0x120 +
                  *(int *)(&g_CardSlot_TapState + card_slot * 0x120 + player * 0x5b20) * 0x5b20) | 0x10;
    Mem_AllocOrFree_0041df33(player,3,g_DialogPromptHwnd,g_DuelArenaHwnd);
  }
  if ((((arg_3 == 0x22) || (arg_3 == 199)) && (card_slot == g_EventSourceSlot)) &&
     (player == g_EventSourcePlayer)) {
    *(int32_t *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) = 0;
  }
  if ((arg_3 == 199) && ((&g_ActivePlayerSpellPriority)[player] != 0)) {
    Mem_AllocOrFree_0041df33(player,3,player,card_slot);
    g_SpellStackDepth = g_SpellStackDepth + 0x60;
  }
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_004592ae
 * Entry Point: 004592ae
 * Size: 554 bytes
 */


int32_t Minit_Subsystem_004592ae(int player_id,int card_slot,int event_type)

{
  int val_1;
  int32_t uval_2;
  
  if (arg_3 == 0x73) {
    val_1 = Font_DrawString(player,7,6);
    if (((val_1 == 0) || ((&g_PlayerPoisonCounters)[player] == 0)) ||
       (((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) != 0)) {
      uval_2 = 0;
    }
    else {
      uval_2 = 1;
    }
  }
  else if (arg_3 == 0x90) {
    Ai_PeekPlannedSlot(0);
    uval_2 = 0;
  }
  else {
    if ((arg_3 == 0x6d) && (val_1 = Font_DrawString(player,7,6), val_1 != 0)) {
      Ai_CalcManaRequirement_004ba890(player,0,6);
      strcpy(&g_OverworldWorldState,s_Pick_a_permanent_00524284);
      (&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20] = g_TemporaryToughnessBuffer;
      if (*(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) == -1) {
        g_ActivePlayer = 1;
      }
    }
    if ((arg_3 == 0x72) &&
       (*(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) != -1)) {
      FUN_0041da41((int)(char)(&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20],
                   *(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20));
      (&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20] = 0xff;
      *(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) =
           (int)(char)(&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20];
      *(uint32_t *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) | 0x10;
    }
    uval_2 = 0;
  }
  return uval_2;
}



/*
 * Decompiled function: CardScript_PrimalClay
 * Entry Point: 004594d8
 * Size: 759 bytes
 */


int32_t CardScript_PrimalClay(int spell_id,int target_id,int flags)

{
  int val_1;
  int val_2;
  
  if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
     (spell_id == g_EventSourcePlayer)) {
    Pic_Subsystem_0042475a(s_prompts_txt_005242a4,s_PRIMAL_CLAY_00524298);
    val_1 = Ai_Subsystem_004cc56d(spell_id,spell_id,target_id,-1,-1,&g_OverworldGoldAmount,1);
    val_2 = FUN_0041d8a6(*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20));
    if (val_2 != -1) {
      if (val_1 == 0) {
        *(int16_t *)(&DAT_0051aec2 + val_2 * 0x34) = 1;
        *(int16_t *)(&DAT_0051aec4 + val_2 * 0x34) = 6;
        (&g_MasterCardRarityTable)[val_2 * 0x34] = 0;
        *(int32_t *)(&DAT_0051aecc + val_2 * 0x34) = 0;
      }
      else if (val_1 == 1) {
        *(int16_t *)(&DAT_0051aec2 + val_2 * 0x34) = 2;
        *(int16_t *)(&DAT_0051aec4 + val_2 * 0x34) = 2;
        *(int32_t *)(&DAT_0051aecc + val_2 * 0x34) = 0x20;
      }
      else if (val_1 == 2) {
        *(int16_t *)(&DAT_0051aec2 + val_2 * 0x34) = 3;
        *(int16_t *)(&DAT_0051aec4 + val_2 * 0x34) = 3;
        *(int32_t *)(&DAT_0051aecc + val_2 * 0x34) = 0;
      }
      *(int *)(&g_CardSlot_Controller + target_id * 0x120 + spell_id * 0x5b20) = val_2;
      *(int32_t *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) =
           *(int32_t *)(&g_CardSlot_Controller + target_id * 0x120 + spell_id * 0x5b20);
      *(uint32_t *)(&g_CardSlot_Abilities2 + target_id * 0x120 + spell_id * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_Abilities2 + target_id * 0x120 + spell_id * 0x5b20) | 0x1000000;
    }
  }
  if (((flags == 0x3c) && ((g_DuelModeFlags._2_1_ & 2) == 0)) &&
     ((g_EventSourceSlot == target_id &&
      ((spell_id == g_EventSourcePlayer &&
       (val_1 = Card_IsInPlay(spell_id, target_id), val_1 != 0)))))) {
    g_CardEventResult =
         *(int32_t *)(&g_CardSlot_Controller + target_id * 0x120 + spell_id * 0x5b20);
  }
  if (((flags == 0x77) && (g_EventSourceSlot == target_id)) &&
     (spell_id == g_EventSourcePlayer)) {
    Mem_AllocOrFree_0041d942
              (*(int *)(&g_CardSlot_Controller + target_id * 0x120 + spell_id * 0x5b20));
  }
  return 0;
}



/*
 * Decompiled function: CardScript_Shapeshifter
 * Entry Point: 004597d4
 * Size: 1329 bytes
 */


int32_t CardScript_Shapeshifter(int spell_id,int target_id,int flags)

{
  short len_1;
  int val_2;
  int32_t uval_3;
  short match_count;
  
  if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
     (g_EventSourcePlayer == spell_id)) {
    if (g_CurrentTurnPhase != spell_id) {
      if (g_IsAiThinking == 1) {
        g_AiChoiceValue = Util_GetRandomNumber(7);
        Ai_RecordChoice();
      }
      else {
        Ai_ReplayChoice();
      }
    }
    Pic_Subsystem_0042475a(s_prompts_txt_005242c0,s_SHAPESHIFTER_005242b0);
    match_count = Ai_Subsystem_004cc56d
                        (spell_id,spell_id,target_id,-1,-1,&g_OverworldGoldAmount,g_AiChoiceValue)
    ;
    if (g_ActivePlayerPriority == spell_id) {
      match_count = (short)g_AiChoiceValue;
    }
    val_2 = FUN_0041d8a6(*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20));
    if (val_2 != -1) {
      *(short *)(&DAT_0051aec2 + val_2 * 0x34) = match_count;
      *(short *)(&DAT_0051aec4 + val_2 * 0x34) = 7 - match_count;
      *(int *)(&g_CardSlot_Controller + target_id * 0x120 + spell_id * 0x5b20) = val_2;
      *(int32_t *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) =
           *(int32_t *)(&g_CardSlot_Controller + target_id * 0x120 + spell_id * 0x5b20);
      *(uint32_t *)(&g_CardSlot_Abilities2 + target_id * 0x120 + spell_id * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_Abilities2 + target_id * 0x120 + spell_id * 0x5b20) | 0x1000000;
    }
  }
  if (((flags == 0x3c) && ((g_DuelModeFlags._2_1_ & 2) == 0)) &&
     ((g_EventSourceSlot == target_id && (g_EventSourcePlayer == spell_id)))) {
    val_2 = Card_IsInPlay(spell_id, target_id);
    if (val_2 != 0) {
      g_CardEventResult =
           *(int32_t *)(&g_CardSlot_Controller + target_id * 0x120 + spell_id * 0x5b20);
    }
  }
  if (flags == 0x73) {
    if ((((g_ScWillyScore == 4) && (g_TurnPlayer == spell_id)) &&
        (*(int *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) == 0)) &&
       (g_CurrentTurnTargetPlayer == spell_id)) {
      uval_3 = 1;
    }
    else {
      uval_3 = 0;
    }
  }
  else {
    if (((flags == 0x6d) && (g_EventSourceSlot == target_id)) &&
       (g_EventSourcePlayer == spell_id)) {
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
      len_1 = Ai_Subsystem_004cc56d(spell_id,spell_id,target_id,-1,-1,&g_OverworldGoldAmount,4);
      *(short *)(&DAT_0051aec2 +
                *(int *)(&g_CardSlot_CardId +
                        *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20)
                        * 0x120 + *(int *)(&g_CardSlot_TapState +
                                          target_id * 0x120 + spell_id * 0x5b20) * 0x5b20) * 0x34) =
           len_1;
      *(short *)(&DAT_0051aec4 +
                *(int *)(&g_CardSlot_CardId +
                        *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20)
                        * 0x120 + *(int *)(&g_CardSlot_TapState +
                                          target_id * 0x120 + spell_id * 0x5b20) * 0x5b20) * 0x34) =
           7 - len_1;
    }
    if (flags == 0x22) {
      *(int32_t *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) = 0;
    }
    uval_3 = 0;
  }
  return uval_3;
}



/*
 * Decompiled function: CardScript_Tetravite
 * Entry Point: 00459d0a
 * Size: 1041 bytes
 */


int32_t CardScript_Tetravite(int player_id,int card_slot,int event_type)

{
  bool flag_1;
  int val_2;
  int32_t uval_3;
  int val_4;
  
  if (((arg_3 == 0x6c) && (g_EventSourceSlot == card_slot)) && (g_EventSourcePlayer == player)) {
    Glue_Subsystem_004e6913(player,card_slot,3);
  }
  if (((arg_3 == 0x32) || (arg_3 == 0x33)) &&
     ((g_EventSourceSlot == card_slot && (g_EventSourcePlayer == player)))) {
    val_2 = Glue_Subsystem_004e6978(player,card_slot);
    g_CardEventResult = g_CardEventResult + val_2;
  }
  if (arg_3 == 0x73) {
    flag_1 = false;
    if (((g_ScWillyScore == 4) && (g_TurnPlayer == player)) && (g_CurrentTurnTargetPlayer == player)) {
      val_2 = Glue_Subsystem_004e6978(player,card_slot);
      if (*(int *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) < val_2) {
        flag_1 = true;
      }
      else {
        val_2 = Minit_Subsystem_0045a120(player,card_slot);
        if (val_2 != 0) {
          flag_1 = true;
        }
      }
    }
    if (flag_1) {
      if ((g_ActivePlayerPriority == player) && (0 < DAT_006ff550)) {
        g_CombatPhaseFlags = g_CombatPhaseFlags | 3;
      }
      uval_3 = 1;
    }
    else {
      uval_3 = 0;
    }
  }
  else {
    if (((arg_3 == 0x6d) && (g_EventSourceSlot == card_slot)) && (g_EventSourcePlayer == player)) {
      val_2 = Glue_Subsystem_004e6978(player,card_slot);
      val_2 = val_2 - *(int *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20);
      val_4 = Minit_Subsystem_0045a120(player,card_slot);
      if ((val_2 == 3) || ((val_2 != 0 && (val_4 == 0)))) {
        CardScript_Tetravus(player,card_slot,val_2);
      }
      else if ((val_2 == 0) && (val_4 != 0)) {
        *(uint32_t *)(&g_CardSlot_TargetSlot + card_slot * 0x120 + player * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_TargetSlot + card_slot * 0x120 + player * 0x5b20) | 0x100;
      }
      else if ((val_2 != 0) && (val_4 != 0)) {
        val_4 = Ai_Subsystem_004cc56d
                          (player,player,card_slot,-1,-1,s_Launch_tetravite__Dock_tetravite_005242e8,0);
        if (val_4 == 0) {
          CardScript_Tetravus(player,card_slot,val_2);
        }
        else {
          *(uint32_t *)(&g_CardSlot_TargetSlot + card_slot * 0x120 + player * 0x5b20) =
               *(uint32_t *)(&g_CardSlot_TargetSlot + card_slot * 0x120 + player * 0x5b20) | 0x100;
        }
      }
    }
    if ((arg_3 == 0x72) &&
       (*(int *)(&g_CardSlot_CardId +
                *(int *)(&g_CardSlot_SicknessState + card_slot * 0x120 + player * 0x5b20) * 0x120 +
                *(int *)(&g_CardSlot_TapState + card_slot * 0x120 + player * 0x5b20) * 0x5b20) != -1)) {
      if (((&DAT_006a5f61)[card_slot * 0x120 + player * 0x5b20] & 1) == 0) {
        Minit_Subsystem_0045a42a(player,card_slot);
      }
      else {
        CardScript_Tetravite(player,card_slot);
      }
    }
    if ((((arg_3 == 0x22) || (arg_3 == 199)) && (g_EventSourceSlot == card_slot)) &&
       (g_EventSourcePlayer == player)) {
      *(int32_t *)(&g_CardSlot_TargetSlot + card_slot * 0x120 + player * 0x5b20) = 0;
      *(int32_t *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) =
           *(int32_t *)(&g_CardSlot_TargetSlot + card_slot * 0x120 + player * 0x5b20);
    }
    uval_3 = 0;
  }
  return uval_3;
}



/*
 * Decompiled function: Minit_Subsystem_0045a120
 * Entry Point: 0045a120
 * Size: 306 bytes
 */


int Minit_Subsystem_0045a120(int arg1,int arg2)

{
  int val_1;
  int player_idx;
  int match_count;
  int slot_idx;
  
  match_count = 0;
  for (slot_idx = 0; slot_idx < 2; slot_idx = slot_idx + 1) {
    for (player_idx = 0; player_idx < (int)(&g_PlayerActiveCardCount)[slot_idx]; player_idx = player_idx + 1)
    {
      val_1 = Card_IsInPlay(slot_idx,player_idx);
      if ((((val_1 != 0) &&
           (*(int *)(&g_MasterCardTypeTable +
                    *(int *)(&g_CardSlot_CardId + player_idx * 0x120 + slot_idx * 0x5b20) * 0x34) ==
            0x37b)) &&
          ((char)(&g_CardSlot_DamageReceived)[player_idx * 0x120 + slot_idx * 0x5b20] == arg1)) &&
         ((*(int *)(&g_CardSlot_TypeFlags + player_idx * 0x120 + slot_idx * 0x5b20) == arg2 &&
          (*(int *)(&g_CardSlot_ConvertedManaCost + player_idx * 0x120 + slot_idx * 0x5b20) == 0)))) {
        match_count = match_count + 1;
      }
    }
  }
  return match_count;
}



/*
 * Decompiled function: CardScript_Tetravus
 * Entry Point: 0045a252
 * Size: 472 bytes
 */


int32_t CardScript_Tetravus(int spell_id,int target_id,int flags)

{
  int32_t uval_1;
  int card_idx;
  int match_count;
  int slot_idx;
  
  Pic_Subsystem_0042475a(s_prompts_txt_00524318,s_TETRAVUS_0052430c);
  if (flags < 3) {
    if (flags < 2) {
      card_idx = 0;
    }
    else {
      card_idx = 1;
    }
  }
  else {
    card_idx = 2;
  }
  uval_1 = Ai_Subsystem_004cc56d
                    (spell_id,spell_id,target_id,-1,-1,&g_OverworldGoldAmount + card_idx * 0xfa,0);
  *(int32_t *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) = uval_1;
  slot_idx = (int)*(short *)(&DAT_006a5f46 + target_id * 0x120 + spell_id * 0x5b20);
  if (*(int *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) <= flags) {
    match_count = 0;
    while ((match_count < *(int *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) &&
           (0 < slot_idx))) {
      Glue_Subsystem_004e689b(spell_id,target_id,1);
      *(uint32_t *)(&g_CardSlot_Abilities2 + target_id * 0x120 + spell_id * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_Abilities2 + target_id * 0x120 + spell_id * 0x5b20) | 0x2000000;
      slot_idx = Magic_QueryCardAttribute(spell_id,target_id,0x33,0xffffffff);
      if (0 < slot_idx) {
        *(uint32_t *)(&g_CardSlot_Abilities2 + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_Abilities2 + target_id * 0x120 + spell_id * 0x5b20) | 0x4000000;
        Magic_QueryCardAttribute(spell_id,target_id,0x32,0xffffffff);
      }
      match_count = match_count + 1;
    }
  }
  if (0 < DAT_006ff550) {
    DAT_006ff550 = DAT_006ff550 + -1;
  }
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_0045a42a
 * Entry Point: 0045a42a
 * Size: 331 bytes
 */


int32_t Minit_Subsystem_0045a42a(int arg1,int arg2)

{
  int val_1;
  int match_count;
  
  for (match_count = 0;
      match_count < *(int *)(&g_CardSlot_TargetSlot +
                        *(int *)(&g_CardSlot_TapState + arg2 * 0x120 + arg1 * 0x5b20) * 0x5b20 +
                        *(int *)(&g_CardSlot_SicknessState + arg2 * 0x120 + arg1 * 0x5b20) * 0x120);
      match_count = match_count + 1) {
    val_1 = Pic_Subsystem_0045268f(0x37b);
    val_1 = Deck_AddCardToDeck(arg1,val_1);
    if (val_1 != -1) {
      Pic_Subsystem_0042ac1f(arg1,val_1);
      (&g_CardSlot_DamageReceived)[val_1 * 0x120 + arg1 * 0x5b20] = (uint8_t)g_DialogPromptHwnd;
      *(int32_t *)(&g_CardSlot_TypeFlags + val_1 * 0x120 + arg1 * 0x5b20) = g_DuelArenaHwnd;
      *(uint32_t *)(&g_CardSlot_Abilities1 + val_1 * 0x120 + arg1 * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_Abilities1 + val_1 * 0x120 + arg1 * 0x5b20) | 0x10;
      *(int32_t *)(&g_CardSlot_ConvertedManaCost + val_1 * 0x120 + arg1 * 0x5b20) = 1;
    }
  }
  return 0;
}



/*
 * Decompiled function: CardScript_Tetravite
 * Entry Point: 0045a575
 * Size: 532 bytes
 */


int32_t CardScript_Tetravite(int spell_id,int target_id)

{
  bool flag_1;
  int val_2;
  int arg_12;
  uint32_t arg_13;
  uint32_t arg_14;
  uint32_t arg_15;
  uint32_t arg_16;
  uint32_t arg_17;
  uint8_t *arg_18;
  int32_t arg_19;
  int *arg_20;
  int card_idx;
  int match_count;
  int slot_idx;
  
  slot_idx = 0;
  do {
    Pic_Subsystem_00424500(s_prompts_txt_00524330,s_TETRAVITE_00524324);
    arg_20 = &card_idx;
    arg_19 = 1;
    arg_18 = &g_OverworldGoldAmount;
    arg_17 = 0;
    arg_16 = 0;
    arg_15 = 0;
    arg_14 = 0xffffffff;
    arg_13 = 0xffffffff;
    arg_12 = -1;
    val_2 = Pic_Subsystem_0045268f(0x37b);
    val_2 = Duel_ChooseTarget
                      (spell_id,2,2,0x200,0,0,0,0,0,0,val_2,arg_12,arg_13,arg_14,arg_15,arg_16,
                       arg_17,arg_18,arg_19,arg_20);
    if (val_2 == 0) {
      g_ActivePlayer = 1;
    }
    else {
      flag_1 = true;
      strcpy(&g_OverworldWorldState,s_Illegal_target__tetravite_not_re_0052433c);
      if ((((char)(&g_CardSlot_DamageReceived)[card_idx * 0x5b20 + match_count * 0x120] ==
            g_DialogPromptHwnd) &&
          (*(int *)(&g_CardSlot_TypeFlags + card_idx * 0x5b20 + match_count * 0x120) == g_DuelArenaHwnd)
          ) && (strcpy(&g_OverworldWorldState,s_Illegal_target__only_one_move_pe_00524370),
               *(int *)(&g_CardSlot_ConvertedManaCost + card_idx * 0x5b20 + match_count * 0x120) == 0))
      {
        Glue_Subsystem_004e66b3(g_DialogPromptHwnd,g_DuelArenaHwnd);
        Pic_Subsystem_0044867e(card_idx,match_count,4);
        *(int *)(&g_CardSlot_ConvertedManaCost +
                *(int *)(&g_CardSlot_SicknessState + spell_id * 0x5b20 + target_id * 0x120) * 0x120
                + *(int *)(&g_CardSlot_TapState + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20) =
             *(int *)(&g_CardSlot_ConvertedManaCost +
                     *(int *)(&g_CardSlot_SicknessState + spell_id * 0x5b20 + target_id * 0x120) *
                     0x120 + *(int *)(&g_CardSlot_TapState + spell_id * 0x5b20 + target_id * 0x120)
                             * 0x5b20) + 1;
        slot_idx = slot_idx + 1;
        flag_1 = false;
      }
      if ((flag_1) && (g_IsAiThinking != 1)) {
        Ai_Util_004cc42d(&g_OverworldWorldState);
        Sleep(2000);
        Ai_Util_004cc42d(&DAT_0052439c);
      }
    }
  } while ((g_ActivePlayer != 1) && (slot_idx == 0));
  g_OverworldWorldState = 0;
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_0045a789
 * Entry Point: 0045a789
 * Size: 156 bytes
 */


int32_t Minit_Subsystem_0045a789(int player_id,int card_slot,int event_type)

{
  if ((((arg_3 == 0x22) || (arg_3 == 199)) && (g_EventSourceSlot == card_slot)) &&
     (g_EventSourcePlayer == player)) {
    *(int32_t *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) = 0;
  }
  if (((arg_3 == 0x34) && (g_EventSourceSlot == card_slot)) && (g_EventSourcePlayer == player)) {
    g_CardEventResult = g_CardEventResult | 0x20000;
  }
  return 0;
}



/*
 * Decompiled function: CardScript_Triskelion
 * Entry Point: 0045a825
 * Size: 474 bytes
 */


bool CardScript_Triskelion(int spell_id,int target_id,int flags)

{
  bool flag_1;
  int val_2;
  
  if (((flags == 0x6c) && (target_id == g_EventSourceSlot)) &&
     (spell_id == g_EventSourcePlayer)) {
    Glue_Subsystem_004e6913(spell_id,target_id,3);
  }
  if (((flags == 0x32) || (flags == 0x33)) &&
     ((target_id == g_EventSourceSlot && (spell_id == g_EventSourcePlayer)))) {
    val_2 = Glue_Subsystem_004e6978(spell_id,target_id);
    g_CardEventResult = g_CardEventResult + val_2;
  }
  if (flags == 0x73) {
    val_2 = Glue_Subsystem_004e6978(spell_id,target_id);
    flag_1 = 0 < val_2;
  }
  else if (flags == 0x90) {
    Ai_PeekPlannedSlot(1);
    flag_1 = false;
  }
  else {
    if ((flags == 0x6d) && (val_2 = Glue_Subsystem_004e6978(spell_id,target_id), 0 < val_2)) {
      Pic_Subsystem_00424500(s_prompts_txt_005243ac,s_TRISKELION_005243a0);
      val_2 = Glue_Subsystem_004df8ba(spell_id,target_id);
      if (val_2 != 0) {
        *(uint32_t *)(&g_CardSlot_Abilities2 + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_Abilities2 + target_id * 0x120 + spell_id * 0x5b20) | 0x6000000;
        Glue_Subsystem_004e676b(spell_id,target_id);
      }
    }
    if (flags == 0x72) {
      Glue_Subsystem_004dfb23(spell_id,target_id,0x72,1);
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120] = 0;
    }
    flag_1 = false;
  }
  return flag_1;
}



/*
 * Decompiled function: CardScript_UrzasAvenger
 * Entry Point: 0045a9ff
 * Size: 1858 bytes
 */


int32_t CardScript_UrzasAvenger(int spell_id,int target_id,int flags)

{
  int32_t uval_1;
  int val_2;
  int slot_idx;
  
  if (flags == 0x73) {
    if ((g_ActivePlayerPriority == spell_id) &&
       (*(int *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) != 0)) {
      uval_1 = 0;
    }
    else {
      uval_1 = 1;
    }
  }
  else {
    if (flags == 0x6d) {
      Pic_Subsystem_0042475a(s_prompts_txt_005243c8,s_URZAS_AVENGER_005243b8);
      val_2 = Ai_Subsystem_004cc56d(spell_id,spell_id,target_id,-1,-1,&g_OverworldGoldAmount,0);
      *(int *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) = val_2 + 1;
      if (*(int *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) == 5) {
        g_ActivePlayer = 1;
        *(int32_t *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) = 0;
      }
    }
    if (flags == 0x72) {
      if (*(int *)(&g_CardSlot_CardId +
                  *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
                  *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) *
                  0x120) == -1) {
        g_ActivePlayer = 1;
      }
      else {
        if (((&g_CardSlot_DamageReceived)[target_id * 0x120 + spell_id * 0x5b20] == -1) &&
           (*(int *)(&g_CardSlot_TypeFlags + target_id * 0x120 + spell_id * 0x5b20) == -1)) {
          slot_idx = Card_ApplyTriggerEffect(g_DialogPromptHwnd,g_DuelArenaHwnd,DAT_0069f6dc,g_DialogPromptHwnd,
                                 g_DuelArenaHwnd);
          if (slot_idx != -1) {
            *(int32_t *)(&g_CardSlot_Abilities2 + slot_idx * 0x120 + spell_id * 0x5b20) = 0;
            (&g_CardSlot_DamageReceived)
            [*(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
             *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120] =
                 (uint8_t)spell_id;
            *(int *)(&g_CardSlot_TypeFlags +
                    *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20
                    + *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) *
                      0x120) = slot_idx;
          }
        }
        else {
          slot_idx = *(int *)(&g_CardSlot_TypeFlags + target_id * 0x120 + spell_id * 0x5b20);
        }
        if (slot_idx != -1) {
          switch(*(int32_t *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20)) {
          case 1:
            *(uint32_t *)(&g_CardSlot_ConvertedManaCost + slot_idx * 0x120 + spell_id * 0x5b20) =
                 *(uint32_t *)(&g_CardSlot_ConvertedManaCost + slot_idx * 0x120 + spell_id * 0x5b20) |
                 0x20;
            break;
          case 2:
            *(uint32_t *)(&g_CardSlot_ConvertedManaCost + slot_idx * 0x120 + spell_id * 0x5b20) =
                 *(uint32_t *)(&g_CardSlot_ConvertedManaCost + slot_idx * 0x120 + spell_id * 0x5b20) |
                 0x40;
            break;
          case 3:
            *(uint32_t *)(&g_CardSlot_ConvertedManaCost + slot_idx * 0x120 + spell_id * 0x5b20) =
                 *(uint32_t *)(&g_CardSlot_ConvertedManaCost + slot_idx * 0x120 + spell_id * 0x5b20) |
                 0x100;
            break;
          case 4:
            *(uint32_t *)(&g_CardSlot_ConvertedManaCost + slot_idx * 0x120 + spell_id * 0x5b20) =
                 *(uint32_t *)(&g_CardSlot_ConvertedManaCost + slot_idx * 0x120 + spell_id * 0x5b20) |
                 0x80;
          }
          *(short *)(&g_CardSlot_PowerCounters + slot_idx * 0x120 + spell_id * 0x5b20) =
               *(short *)(&g_CardSlot_PowerCounters + slot_idx * 0x120 + spell_id * 0x5b20) + 1;
          *(short *)(&g_CardSlot_ToughnessCounters + slot_idx * 0x120 + spell_id * 0x5b20) =
               *(short *)(&g_CardSlot_ToughnessCounters + slot_idx * 0x120 + spell_id * 0x5b20) + 1;
        }
        *(int32_t *)
         (&g_CardSlot_Abilities2 +
         *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
         *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120) =
             0x8000000;
        *(short *)(&g_CardSlot_PowerCounters +
                  *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) *
                  0x120 + *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) *
                          0x5b20) =
             *(short *)(&g_CardSlot_PowerCounters +
                       *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) *
                       0x120 + *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20
                                       ) * 0x5b20) + -1;
        *(short *)(&g_CardSlot_ToughnessCounters +
                  *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) *
                  0x120 + *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) *
                          0x5b20) =
             *(short *)(&g_CardSlot_ToughnessCounters +
                       *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) *
                       0x120 + *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20
                                       ) * 0x5b20) + -1;
        *(int *)(&g_CardSlot_ConvertedManaCost +
                *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120
                + *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20) =
             *(int *)(&g_CardSlot_ConvertedManaCost +
                     *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) *
                     0x120 + *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20)
                             * 0x5b20) + 1;
        *(int32_t *)
         (&g_CardSlot_TargetSlot +
         *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
         *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120) = 0;
      }
    }
    if ((flags == 0x22) || (flags == 199)) {
      *(short *)(&g_CardSlot_PowerCounters + target_id * 0x120 + spell_id * 0x5b20) =
           *(short *)(&g_CardSlot_PowerCounters + target_id * 0x120 + spell_id * 0x5b20) +
           (short)*(int32_t *)
                   (&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20);
      *(short *)(&g_CardSlot_ToughnessCounters + target_id * 0x120 + spell_id * 0x5b20) =
           *(short *)(&g_CardSlot_ToughnessCounters + target_id * 0x120 + spell_id * 0x5b20) +
           (short)*(int32_t *)
                   (&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20);
      *(int32_t *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) = 0;
      *(int32_t *)(&g_CardSlot_TypeFlags + target_id * 0x120 + spell_id * 0x5b20) = 0xffffffff;
      (&g_CardSlot_DamageReceived)[target_id * 0x120 + spell_id * 0x5b20] =
           (&g_CardSlot_TypeFlags)[target_id * 0x120 + spell_id * 0x5b20];
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: CardScript_Millstone
 * Entry Point: 0045b156
 * Size: 940 bytes
 */


int32_t CardScript_Millstone(int spell_id,int target_id,int flags)

{
  int val_1;
  int32_t uval_2;
  int target_idx;
  int32_t player_idx;
  int card_idx;
  int match_count;
  int slot_idx;
  
  if (flags == 0x73) {
    val_1 = Font_DrawString(spell_id,7,2);
    if (((val_1 == 0) ||
        ((((&g_CardSlot_Subtypes)[spell_id * 0x5b20 + target_id * 0x120] & 3) != 0 &&
         (((&g_MasterCardColorTable)
           [*(int *)(&g_CardSlot_CardId + spell_id * 0x5b20 + target_id * 0x120) * 0x34] & 2) != 0))
        )) || (((&g_CardSlot_Flags)[spell_id * 0x5b20 + target_id * 0x120] & 0x10) != 0)) {
      uval_2 = 0;
    }
    else {
      uval_2 = 1;
    }
  }
  else {
    if ((((flags == 0x6d) &&
         (((&g_CardSlot_Flags)[spell_id * 0x5b20 + target_id * 0x120] & 0x10) == 0)) &&
        (val_1 = Font_DrawString(spell_id,7,2), val_1 != 0)) &&
       (Ai_CalcManaRequirement_004ba890(spell_id,0,2), g_ActivePlayer != 1)) {
      Pic_Subsystem_00424500(s_prompts_txt_005243e0,s_MILLSTONE_005243d4);
      val_1 = Duel_ChooseTarget
                        (spell_id,2,1 - spell_id,0x1000,0,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0,0,
                         0,&g_OverworldGoldAmount,1,&target_idx);
      if (val_1 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + spell_id * 0x5b20 + target_id * 0x120) = target_idx;
        *(int32_t *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120) = player_idx
        ;
        (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 1;
        *(uint32_t *)(&g_CardSlot_Flags + spell_id * 0x5b20 + target_id * 0x120) =
             *(uint32_t *)(&g_CardSlot_Flags + spell_id * 0x5b20 + target_id * 0x120) | 0x10;
      }
    }
    if (flags == 0x72) {
      val_1 = *(int *)(&g_CardSlot_CombatTarget + spell_id * 0x5b20 + target_id * 0x120);
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_TapState + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + spell_id * 0x5b20 + target_id * 0x120) * 0x120] = 0;
      for (match_count = 0; match_count < 2; match_count = match_count + 1) {
        card_idx = *(int *)(&g_PlayerDeckCardList + val_1 * 2000);
        if (card_idx != -1) {
          Pic_Subsystem_004523fd(val_1,0);
          slot_idx = Deck_AddCardToDeck(val_1,card_idx);
          if (slot_idx != -1) {
            Pic_Subsystem_0044913a(val_1,slot_idx);
            *(int32_t *)(&g_CardSlot_CardId + slot_idx * 0x120 + val_1 * 0x5b20) = 0xffffffff;
          }
        }
        if (g_IsAiThinking != 1) {
          Duel_PlaySoundById(0x18);
        }
        if ((g_ScWillyScore == 0x1f) && (g_TurnPlayer == g_CurrentTurnPhase)) {
          g_SpellStackDepth = g_SpellStackDepth + 0x18;
        }
      }
    }
    if (flags == 199) {
      if (spell_id == g_ActivePlayerPriority) {
        g_SpellStackDepth = g_SpellStackDepth + 0x18;
      }
      else {
        g_SpellStackDepth = g_SpellStackDepth + -0x18;
      }
    }
    uval_2 = 0;
  }
  return uval_2;
}



/*
 * Decompiled function: Mana_Init_0045b502
 * Entry Point: 0045b502
 * Size: 727 bytes
 */


int32_t Mana_Init_0045b502(int spell_id,int target_id,int flags)

{
  int val_1;
  int32_t uval_2;
  char *mode_str;
  int slot_idx;
  
  if (flags == 0x73) {
    val_1 = Font_DrawString(spell_id,7,2);
    if ((val_1 == 0) ||
       (((((&g_CardSlot_Subtypes)[target_id * 0x120 + spell_id * 0x5b20] & 3) != 0 &&
         (((&g_MasterCardColorTable)
           [*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) * 0x34] & 2) != 0))
        || (((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) != 0)))) {
      uval_2 = 0;
    }
    else {
      uval_2 = 1;
    }
  }
  else {
    if ((flags == 0x6d) && (val_1 = Font_DrawString(spell_id,7,2), val_1 != 0)) {
      g_SpellStackDepth = g_SpellStackDepth + -0x18;
      Ai_CalcManaRequirement_004ba890(spell_id,0,2);
      if (g_ActivePlayer != 1) {
        if (spell_id == g_CurrentTurnPhase) {
          slot_idx = -1;
        }
        else if (g_IsAiThinking == 1) {
          slot_idx = DAT_006b1580 % 5 + 1;
          g_AiChoiceValue = slot_idx;
          Ai_RecordChoice();
        }
        else {
          Ai_ReplayChoice();
          if (g_AiChoiceValue < 6) {
            slot_idx = g_AiChoiceValue;
          }
          else {
            g_ActivePlayer = 1;
          }
        }
        if (g_ActivePlayer != 1) {
          Pic_Subsystem_00424500(s_prompts_txt_005243fc,s_CELESTIAL_PRISM_005243ec);
          val_1 = Ai_Subsystem_004cc93d
                            (spell_id,&g_OverworldGoldAmount,1,slot_idx,
                             (int)(char)(&g_CardSlot_PlusOneCounters)[target_id * 0x120 + spell_id * 0x5b20]);
          if (val_1 == -1) {
            g_ActivePlayer = 1;
          }
          if (g_ActivePlayer != 1) {
            FUN_0040d875(spell_id,val_1,1);
            FUN_0040d64c(spell_id,(int)(char)(&g_CardSlot_PlusOneCounters)[target_id * 0x120 + spell_id * 0x5b20],
                         1);
            *(uint32_t *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) =
                 *(uint32_t *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
            g_PendingAttackersTargetSlot = val_1;
            if (spell_id != g_CurrentTurnPhase) {
              strcpy(&g_OverworldWorldState,s_to_produce_00524408);
              str_2 = (char *)Mem_AllocOrFree_00473d7e(val_1);
              strcat(&g_OverworldWorldState,str_2);
              strcat(&g_OverworldWorldState,s_mana__00524414);
              Ai_Subsystem_004cc56d(spell_id,spell_id,target_id,-1,-1,&g_OverworldWorldState,0);
            }
          }
        }
      }
    }
    uval_2 = 0;
  }
  return uval_2;
}



/*
 * Decompiled function: Mana_Init_0045b7d9
 * Entry Point: 0045b7d9
 * Size: 1202 bytes
 */


int32_t Mana_Init_0045b7d9(int spell_id,int target_id,int flags)

{
  int32_t uval_1;
  int card_slot;
  char *mode_str;
  int card_idx;
  int match_count;
  
  if (((&g_CardSlot_Flags)[spell_id * 0x5b20 + target_id * 0x120] & 0x10) == 0) {
    FUN_0040d64c(spell_id,(int)(char)(&g_CardSlot_PlusOneCounters)[spell_id * 0x5b20 + target_id * 0x120],1);
    (&g_CardSlot_PlusOneCounters)[spell_id * 0x5b20 + target_id * 0x120] = (&DAT_0063eed0)[(1 - spell_id) * 4];
    FUN_0040d59c(spell_id,(int)(char)(&g_CardSlot_PlusOneCounters)[spell_id * 0x5b20 + target_id * 0x120],1);
  }
  if (flags == 0x73) {
    if (((((&g_CardSlot_Subtypes)[spell_id * 0x5b20 + target_id * 0x120] & 3) == 0) ||
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId + spell_id * 0x5b20 + target_id * 0x120) * 0x34] & 2) == 0))
       && (((&g_CardSlot_Flags)[spell_id * 0x5b20 + target_id * 0x120] & 0x10) == 0)) {
      uval_1 = 1;
    }
    else {
      uval_1 = 0;
    }
  }
  else {
    if (flags == 0x6d) {
      if ((char)(&g_CardSlot_PlusOneCounters)[spell_id * 0x5b20 + target_id * 0x120] < '\x01') {
        *(uint32_t *)(&g_CardSlot_Flags + spell_id * 0x5b20 + target_id * 0x120) =
             *(uint32_t *)(&g_CardSlot_Flags + spell_id * 0x5b20 + target_id * 0x120) | 0x10;
      }
      else {
        if (((spell_id == 1) || (g_IsAiThinking == 1)) || (g_AiTurnDecisionFlag != 0)) {
          card_idx = -1;
          match_count = 1;
          while ((match_count < 6 && (card_idx == -1))) {
            if ((0 < (&g_AiSelectedTargetCard)[match_count]) &&
               (((int)(char)(&g_CardSlot_PlusOneCounters)[spell_id * 0x5b20 + target_id * 0x120] &
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
          Pic_Subsystem_00424500(s_prompts_txt_0052442c,s_FELLWAR_STONE_0052441c);
          card_slot = Ai_Subsystem_004cc93d
                            (spell_id,&g_OverworldGoldAmount,1,card_idx,
                             (int)(char)(&g_CardSlot_PlusOneCounters)[spell_id * 0x5b20 + target_id * 0x120]);
          if (card_slot == -1) {
            g_ActivePlayer = 1;
          }
          else {
            card_idx._0_1_ = (uint8_t)card_slot;
            if ((*(uint32_t *)(&DAT_0063eed0 + (1 - spell_id) * 4) & 1 << ((uint8_t)card_idx & 0x1f)) == 0)
            {
              g_ActivePlayer = 1;
            }
          }
          if (g_ActivePlayer != 1) {
            FUN_0040d875(spell_id,card_slot,1);
            FUN_0040d64c(spell_id,(int)(char)(&g_CardSlot_PlusOneCounters)[spell_id * 0x5b20 + target_id * 0x120],
                         1);
            *(uint32_t *)(&g_CardSlot_Flags + spell_id * 0x5b20 + target_id * 0x120) =
                 *(uint32_t *)(&g_CardSlot_Flags + spell_id * 0x5b20 + target_id * 0x120) | 0x10;
            g_PendingAttackersTargetSlot = card_slot;
            if (spell_id != g_CurrentTurnPhase) {
              strcpy(&g_OverworldWorldState,s_to_produce_00524438);
              str_2 = (char *)Mem_AllocOrFree_00473d7e(card_slot);
              strcat(&g_OverworldWorldState,str_2);
              strcat(&g_OverworldWorldState,s_mana__00524444);
              Ai_Subsystem_004cc56d(spell_id,spell_id,target_id,-1,-1,&g_OverworldWorldState,0);
            }
          }
        }
      }
    }
    if ((((flags == 0x77) && (target_id == g_EventSourceSlot)) &&
        (spell_id == g_EventSourcePlayer)) &&
       (((&g_CardSlot_Flags)[spell_id * 0x5b20 + target_id * 0x120] & 0x10) == 0)) {
      FUN_0040d64c(spell_id,(int)(char)(&g_CardSlot_PlusOneCounters)[spell_id * 0x5b20 + target_id * 0x120],1);
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: Minit_Subsystem_0045bc8b
 * Entry Point: 0045bc8b
 * Size: 197 bytes
 */


int32_t Minit_Subsystem_0045bc8b(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  int arg_2_00;
  
  if (arg_3 == 0x73) {
    if (((*(uint8_t *)(&g_PlayerPoisonCounters + player) & 2) == 0) ||
       (((&g_CardSlot_Flags)[player * 0x5b20 + card_slot * 0x120] & 0x10) != 0)) {
      uval_1 = 0;
    }
    else {
      uval_1 = 1;
    }
  }
  else {
    if (arg_3 == 0x6d) {
      arg_2_00 = Glue_Subsystem_004e6bff(player);
      if (arg_2_00 == -1) {
        g_ActivePlayer = 1;
      }
      else {
        Pic_Subsystem_0044867e(player,arg_2_00,3);
      }
    }
    if (arg_3 == 0x72) {
      FUN_0040d875(player,0,2);
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: CardScript_AshnodsBattlegear
 * Entry Point: 0045bd50
 * Size: 2117 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int32_t CardScript_AshnodsBattlegear(int spell_id,int target_id,int flags)

{
  int val_1;
  int32_t uval_2;
  uint32_t uval_3;
  uint32_t uval_4;
  uint32_t uval_5;
  int32_t arg_11;
  int val_6;
  int32_t arg_12;
  uint32_t uval_7;
  int32_t arg_13;
  uint32_t uval_8;
  int32_t arg_14;
  uint32_t uVar9;
  int32_t arg_15;
  uint32_t uVar10;
  int32_t arg_16;
  uint32_t uVar11;
  int32_t arg_17;
  uint8_t *arg_18;
  int32_t arg_18_00;
  int32_t arg_19;
  int *arg_20;
  int card_idx;
  int match_count;
  int slot_idx;
  
  if (((flags == 0x82) && (g_EventSourceSlot == target_id)) &&
     (g_EventSourcePlayer == spell_id)) {
    *(uint32_t *)(&g_CardSlot_ProtectionFlags + target_id * 0x120 + spell_id * 0x5b20) =
         *(uint32_t *)(&g_CardSlot_ProtectionFlags + target_id * 0x120 + spell_id * 0x5b20) & 0xfffffffd;
  }
  if (((g_ScWillyScore == 1) && (g_EventSourceSlot == target_id)) &&
     (g_EventSourcePlayer == spell_id)) {
    if (((flags == 0x7d) && (((&g_CardSlot_ProtectionFlags)[target_id * 0x120 + spell_id * 0x5b20] & 1) != 0)) &&
       ((((&g_CardSlot_ProtectionFlags)[target_id * 0x120 + spell_id * 0x5b20] & 2) == 0 &&
        ((_DAT_006ff198 &
         (uint8_t)(&g_MasterCardColorTable)
               [*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) * 0x34]) == 0))
       )) {
      if (((spell_id == 1) || (g_IsAiThinking == 1)) || (g_AiTurnDecisionFlag != 0)) {
        val_1 = *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20);
        if ((val_1 == -1) ||
           ((((&g_CardSlot_ProtectionFlags)
              [*(int *)(&g_CardSlot_OriginalCardId + val_1 * 0x120 + spell_id * 0x5b20) * 0x120 +
               (char)(&g_CardSlot_Toughness)[val_1 * 0x120 + spell_id * 0x5b20] * 0x5b20] & 1) == 0
            && (((&g_CardSlot_Flags)
                 [*(int *)(&g_CardSlot_OriginalCardId + val_1 * 0x120 + spell_id * 0x5b20) * 0x120 +
                  (char)(&g_CardSlot_Toughness)[val_1 * 0x120 + spell_id * 0x5b20] * 0x5b20] & 0x10)
                != 0)))) {
          g_CardEventResult = g_CardEventResult | 2;
        }
      }
      else {
        g_CardEventResult = g_CardEventResult | 1;
      }
    }
    if (flags == 0x7e) {
      *(uint32_t *)(&g_CardSlot_ProtectionFlags + target_id * 0x120 + spell_id * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_ProtectionFlags + target_id * 0x120 + spell_id * 0x5b20) | 2;
    }
  }
  if (flags == 0x73) {
    if ((((((&g_CardSlot_Subtypes)[target_id * 0x120 + spell_id * 0x5b20] & 3) == 0) ||
         (((&g_MasterCardColorTable)
           [*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) * 0x34] & 2) == 0))
        && (((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0)) &&
       (val_1 = Font_DrawString(spell_id,7,2), val_1 != 0)) {
      arg_19 = 0;
      arg_18_00 = 0;
      arg_17 = 0;
      arg_16 = 0xffffffff;
      arg_15 = 0xffffffff;
      arg_14 = 0xffffffff;
      arg_13 = 0xffffffff;
      arg_12 = 0;
      arg_11 = 0;
      uval_2 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_1 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,spell_id,spell_id,0x200,2,0,0,uval_2,arg_11,arg_12,
                           arg_13,arg_14,arg_15,arg_16,arg_17,arg_18_00,arg_19);
      if (val_1 != 0) {
        return 1;
      }
    }
  }
  else if (flags == 0x90) {
    Ai_PeekPlannedSlot(0);
  }
  else {
    if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
       (g_EventSourcePlayer == spell_id)) {
      *(int32_t *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
           0xffffffff;
    }
    if ((((flags == 0x6d) &&
         (((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0)) &&
        (val_1 = Font_DrawString(spell_id,7,2), val_1 != 0)) &&
       (Ai_CalcManaRequirement_004ba890(spell_id,0,2), g_ActivePlayer != 1)) {
      Pic_Subsystem_00424500(s_prompts_txt_00524460,s_ASHNODS_BATTLEGEAR_0052444c);
      arg_20 = &card_idx;
      uval_2 = 1;
      arg_18 = &g_OverworldGoldAmount;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      val_6 = -1;
      val_1 = -1;
      uval_5 = 0;
      uval_4 = 0;
      uval_3 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_1 = Duel_ChooseTarget
                        (spell_id,spell_id,spell_id,0x200,2,0,0,uval_3,uval_4,uval_5,val_1,val_6,uval_7,
                         uval_8,uVar9,uVar10,uVar11,arg_18,uval_2,arg_20);
      if (val_1 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = card_idx;
        *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = match_count;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        *(uint32_t *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
      }
    }
    if (flags == 0x72) {
      card_idx = *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
      match_count = *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120] = 0;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      val_6 = -1;
      val_1 = -1;
      uval_5 = 0;
      uval_4 = 0;
      uval_3 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_1 = Rules_ParseFilter_0040360b
                        (card_idx,match_count,(char *)0x0,spell_id,(uint8_t)spell_id,(uint8_t)spell_id,0x200,2
                         ,0,0,uval_3,uval_4,uval_5,val_1,val_6,uval_7,uval_8,uVar9,uVar10,uVar11);
      if (val_1 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        slot_idx = Card_ApplyTriggerEffect(g_DialogPromptHwnd,g_DuelArenaHwnd,g_PlayerSelectionPriority,card_idx,match_count);
        if (slot_idx != -1) {
          *(int *)(&g_CardSlot_ConvertedManaCost +
                  *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
                  *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) *
                  0x120) = slot_idx;
          *(uint32_t *)(&g_CardSlot_Abilities1 + slot_idx * 0x120 + spell_id * 0x5b20) =
               *(uint32_t *)(&g_CardSlot_Abilities1 + slot_idx * 0x120 + spell_id * 0x5b20) | 0x20;
          *(int16_t *)(&g_CardSlot_PowerCounters + slot_idx * 0x120 + spell_id * 0x5b20) = 2;
          *(int16_t *)(&g_CardSlot_ToughnessCounters + slot_idx * 0x120 + spell_id * 0x5b20) = 0xfffe;
        }
      }
    }
    if (((flags == 0x77) && (g_EventSourceSlot == target_id)) &&
       ((g_EventSourcePlayer == spell_id &&
        (*(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) != -1)))) {
      Pic_Subsystem_0044867e
                (spell_id,*(int *)(&g_CardSlot_ConvertedManaCost +
                                  target_id * 0x120 + spell_id * 0x5b20),1);
    }
    if ((*(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) != -1) &&
       (((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0)) {
      Pic_Subsystem_0044867e
                (spell_id,*(int *)(&g_CardSlot_ConvertedManaCost +
                                  target_id * 0x120 + spell_id * 0x5b20),1);
      *(int32_t *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
           0xffffffff;
    }
  }
  return 0;
}



/*
 * Decompiled function: CardScript_TawnosWeaponry
 * Entry Point: 0045c59a
 * Size: 2702 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int32_t CardScript_TawnosWeaponry(int spell_id,int target_id,int flags)

{
  int val_1;
  int32_t uval_2;
  uint32_t uval_3;
  uint32_t uval_4;
  uint32_t uval_5;
  int32_t arg_11;
  int val_6;
  int32_t arg_12;
  uint32_t uval_7;
  int32_t arg_13;
  uint32_t uval_8;
  int32_t arg_14;
  uint32_t uVar9;
  int32_t arg_15;
  uint32_t uVar10;
  int32_t arg_16;
  uint32_t uVar11;
  int32_t arg_17;
  uint8_t *arg_18;
  int32_t arg_18_00;
  int32_t arg_19;
  int *arg_20;
  int card_idx;
  int match_count;
  int slot_idx;
  
  if (((flags == 0x82) && (target_id == g_EventSourceSlot)) &&
     (spell_id == g_EventSourcePlayer)) {
    *(uint32_t *)(&g_CardSlot_ProtectionFlags + target_id * 0x120 + spell_id * 0x5b20) =
         *(uint32_t *)(&g_CardSlot_ProtectionFlags + target_id * 0x120 + spell_id * 0x5b20) & 0xfffffffd;
  }
  if (((g_ScWillyScore == 1) && (target_id == g_EventSourceSlot)) &&
     (spell_id == g_EventSourcePlayer)) {
    if (((flags == 0x7d) && (((&g_CardSlot_ProtectionFlags)[target_id * 0x120 + spell_id * 0x5b20] & 1) != 0)) &&
       ((((&g_CardSlot_ProtectionFlags)[target_id * 0x120 + spell_id * 0x5b20] & 2) == 0 &&
        ((_DAT_006ff198 &
         (uint8_t)(&g_MasterCardColorTable)
               [*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) * 0x34]) == 0))
       )) {
      if (((spell_id == 1) || (g_IsAiThinking == 1)) || (g_AiTurnDecisionFlag != 0)) {
        val_1 = *(int *)(&g_CardSlot_TypeFlags + target_id * 0x120 + spell_id * 0x5b20);
        if ((val_1 == -1) ||
           ((((&g_CardSlot_ProtectionFlags)
              [*(int *)(&g_CardSlot_OriginalCardId + val_1 * 0x120 + spell_id * 0x5b20) * 0x120 +
               (char)(&g_CardSlot_Toughness)[val_1 * 0x120 + spell_id * 0x5b20] * 0x5b20] & 1) == 0
            && (((&g_CardSlot_Flags)
                 [*(int *)(&g_CardSlot_OriginalCardId + val_1 * 0x120 + spell_id * 0x5b20) * 0x120 +
                  (char)(&g_CardSlot_Toughness)[val_1 * 0x120 + spell_id * 0x5b20] * 0x5b20] & 0x10)
                != 0)))) {
          g_CardEventResult = g_CardEventResult | 2;
        }
      }
      else {
        g_CardEventResult = g_CardEventResult | 1;
      }
    }
    if (flags == 0x7e) {
      *(uint32_t *)(&g_CardSlot_ProtectionFlags + target_id * 0x120 + spell_id * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_ProtectionFlags + target_id * 0x120 + spell_id * 0x5b20) | 2;
    }
  }
  if (flags == 0x73) {
    if (((((&g_CardSlot_Subtypes)[target_id * 0x120 + spell_id * 0x5b20] & 3) == 0) ||
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) * 0x34] & 2) == 0))
       && ((((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0 &&
           (val_1 = Font_DrawString(spell_id,7,2), val_1 != 0)))) {
      arg_19 = 0;
      arg_18_00 = 0;
      arg_17 = 0;
      arg_16 = 0xffffffff;
      arg_15 = 0xffffffff;
      arg_14 = 0xffffffff;
      arg_13 = 0xffffffff;
      arg_12 = 0;
      arg_11 = 0;
      uval_2 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_1 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uval_2,arg_11,arg_12,arg_13,arg_14,
                           arg_15,arg_16,arg_17,arg_18_00,arg_19);
      if (val_1 != 0) {
        return 1;
      }
    }
  }
  else if (flags == 0x90) {
    Ai_PeekPlannedSlot(0);
  }
  else {
    if (((flags == 0x6d) &&
        (((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0)) &&
       ((val_1 = Font_DrawString(spell_id,7,2), val_1 != 0 &&
        (Ai_CalcManaRequirement_004ba890(spell_id,0,2), g_ActivePlayer != 1)))) {
      Pic_Subsystem_00424500(s_prompts_txt_0052447c,s_TAWNOS_WEAPONRY_0052446c);
      arg_20 = &card_idx;
      uval_2 = 1;
      arg_18 = &g_OverworldGoldAmount;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      val_6 = -1;
      val_1 = -1;
      uval_5 = 0;
      uval_4 = 0;
      uval_3 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_1 = Duel_ChooseTarget
                        (spell_id,2,spell_id,0x200,2,0,0,uval_3,uval_4,uval_5,val_1,val_6,uval_7,uval_8,
                         uVar9,uVar10,uVar11,arg_18,uval_2,arg_20);
      if (val_1 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = card_idx;
        *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = match_count;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        *(uint32_t *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
      }
    }
    if (flags == 0x72) {
      card_idx = *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
      match_count = *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120] = 0;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      val_6 = -1;
      val_1 = -1;
      uval_5 = 0;
      uval_4 = 0;
      uval_3 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_1 = Rules_ParseFilter_0040360b
                        (card_idx,match_count,(char *)0x0,spell_id,2,2,0x200,2,0,0,uval_3,uval_4,uval_5,
                         val_1,val_6,uval_7,uval_8,uVar9,uVar10,uVar11);
      if (val_1 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        slot_idx = Card_ApplyTriggerEffect(g_DialogPromptHwnd,g_DuelArenaHwnd,g_PlayerSelectionPriority,card_idx,match_count);
        if (slot_idx != -1) {
          *(uint32_t *)(&g_CardSlot_Abilities1 + slot_idx * 0x120 + spell_id * 0x5b20) =
               *(uint32_t *)(&g_CardSlot_Abilities1 + slot_idx * 0x120 + spell_id * 0x5b20) | 0x20;
          *(int16_t *)(&g_CardSlot_PowerCounters + slot_idx * 0x120 + spell_id * 0x5b20) = 1;
          *(int16_t *)(&g_CardSlot_ToughnessCounters + slot_idx * 0x120 + spell_id * 0x5b20) = 1;
          (&g_CardSlot_DamageReceived)
          [*(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
           *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120] =
               (uint8_t)spell_id;
          *(int *)(&g_CardSlot_TypeFlags +
                  *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
                  *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) *
                  0x120) = slot_idx;
        }
      }
    }
    if (flags == 0x77) {
      if (((*(int *)(&g_CardSlot_TypeFlags + target_id * 0x120 + spell_id * 0x5b20) != -1) &&
          ((char)(&g_CardSlot_Toughness)
                 [*(int *)(&g_CardSlot_TypeFlags + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
                  (char)(&g_CardSlot_DamageReceived)[target_id * 0x120 + spell_id * 0x5b20] * 0x5b20
                 ] == g_EventSourcePlayer)) &&
         (*(int *)(&g_CardSlot_OriginalCardId +
                  *(int *)(&g_CardSlot_TypeFlags + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
                  (char)(&g_CardSlot_DamageReceived)[target_id * 0x120 + spell_id * 0x5b20] * 0x5b20
                  ) == g_EventSourceSlot)) {
        *(int32_t *)(&g_CardSlot_TypeFlags + target_id * 0x120 + spell_id * 0x5b20) = 0xffffffff;
        (&g_CardSlot_DamageReceived)[target_id * 0x120 + spell_id * 0x5b20] =
             (&g_CardSlot_TypeFlags)[target_id * 0x120 + spell_id * 0x5b20];
      }
      if (((target_id == g_EventSourceSlot) && (spell_id == g_EventSourcePlayer)) &&
         (*(int *)(&g_CardSlot_TypeFlags + target_id * 0x120 + spell_id * 0x5b20) != -1)) {
        Pic_Subsystem_0044867e
                  ((int)(char)(&g_CardSlot_DamageReceived)[target_id * 0x120 + spell_id * 0x5b20],
                   *(int *)(&g_CardSlot_TypeFlags + target_id * 0x120 + spell_id * 0x5b20),1);
        *(int32_t *)(&g_CardSlot_TypeFlags + target_id * 0x120 + spell_id * 0x5b20) = 0xffffffff;
        (&g_CardSlot_DamageReceived)[target_id * 0x120 + spell_id * 0x5b20] =
             (&g_CardSlot_TypeFlags)[target_id * 0x120 + spell_id * 0x5b20];
      }
    }
    if ((*(int *)(&g_CardSlot_TypeFlags + target_id * 0x120 + spell_id * 0x5b20) != -1) &&
       (((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0)) {
      Pic_Subsystem_0044867e
                ((int)(char)(&g_CardSlot_DamageReceived)[target_id * 0x120 + spell_id * 0x5b20],
                 *(int *)(&g_CardSlot_TypeFlags + target_id * 0x120 + spell_id * 0x5b20),1);
      *(int32_t *)(&g_CardSlot_TypeFlags + target_id * 0x120 + spell_id * 0x5b20) = 0xffffffff;
    }
    if (((flags == 0x3b) &&
        ((*(uint32_t *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) & 0x20010) == 0)) &&
       (val_1 = Font_DrawString(spell_id,7,2), val_1 != 0)) {
      *(int *)(&DAT_00695eb0 + spell_id * 4) = *(int *)(&DAT_00695eb0 + spell_id * 4) + 1;
      *(int *)(&DAT_00695eb8 + spell_id * 4) = *(int *)(&DAT_00695eb8 + spell_id * 4) + 1;
    }
  }
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_0045d028
 * Entry Point: 0045d028
 * Size: 456 bytes
 */


int32_t Minit_Subsystem_0045d028(int player_id,int card_slot,int event_type)

{
  int arg_4;
  int player_idx;
  int match_count;
  
  if (arg_3 == 0x3c) {
    (&DAT_006a604f)[card_slot * 0x120 + player * 0x5b20] =
         (&DAT_006a604f)[card_slot * 0x120 + player * 0x5b20] | 0x40;
  }
  if (((arg_3 == 0x1a) && (arg_4 = 1 - player, player == g_TurnPlayer)) &&
     (((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x44) != 0)) {
    if ((&g_CardSlot_ColorMask)[card_slot * 0x120 + player * 0x5b20] == -1) {
      player_idx = card_slot;
    }
    else {
      player_idx = (int)(char)(&g_CardSlot_ColorMask)[card_slot * 0x120 + player * 0x5b20];
    }
    for (match_count = 0; match_count < (int)(&g_PlayerActiveCardCount)[arg_4]; match_count = match_count + 1) {
      if ((((char)(&g_CardSlot_ColorMask)[match_count * 0x120 + arg_4 * 0x5b20] == player_idx) &&
          ((&g_MasterCardRarityTable)[*(int *)(&g_CardSlot_CardId + match_count * 0x120 + arg_4 * 0x5b20) * 0x34]
           == '\0')) &&
         (((&g_MasterCardColorTable)
           [*(int *)(&g_CardSlot_CardId + match_count * 0x120 + arg_4 * 0x5b20) * 0x34] & 2) != 0)) {
        Card_ApplyTriggerEffect(player,card_slot,DAT_006a48e4,arg_4,match_count);
      }
    }
  }
  return 0;
}



/*
 * Decompiled function: CardScript_CandelabraOfTawnos
 * Entry Point: 0045d1f0
 * Size: 1618 bytes
 */


int32_t CardScript_CandelabraOfTawnos(int spell_id,int target_id,int flags)

{
  int32_t uval_1;
  uint32_t uval_2;
  uint32_t uval_3;
  uint32_t uval_4;
  int val_5;
  int32_t uval_6;
  int val_7;
  int32_t uval_8;
  uint32_t uVar9;
  int32_t uVar10;
  uint32_t uVar11;
  int32_t uVar12;
  uint32_t uVar13;
  int32_t uVar14;
  uint32_t uVar15;
  int32_t uVar16;
  uint32_t uVar17;
  int32_t uVar18;
  uint8_t *arg_18;
  int32_t uVar19;
  int32_t uVar20;
  int32_t arg_19;
  int *arg_20;
  int player_idx;
  int card_idx;
  int match_count;
  int slot_idx;
  
  if (flags == 0x73) {
    uVar20 = 0;
    uVar19 = 0;
    uVar18 = 0;
    uVar16 = 0xffffffff;
    uVar14 = 0xffffffff;
    uVar12 = 0xffffffff;
    uVar10 = 0xffffffff;
    uval_8 = 0;
    uval_6 = 0;
    uval_1 = Glue_Subsystem_004d0a42(spell_id,target_id);
    UI_PaintBigCardInfo((int *)(-(uint32_t)(DAT_0063ee88 == 0) & 0x6b2d68),0,spell_id,2,2,0x200,1,0,0,uval_1,
                 uval_6,uval_8,uVar10,uVar12,uVar14,uVar16,uVar18,uVar19,uVar20);
    if (((((&g_CardSlot_Subtypes)[target_id * 0x120 + spell_id * 0x5b20] & 3) == 0) ||
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) * 0x34] & 2) == 0))
       && (((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0)) {
      uval_1 = 1;
    }
    else {
      uval_1 = 0;
    }
  }
  else if (flags == 0x90) {
    Ai_PeekPlannedChoice(0);
    uval_1 = 0;
  }
  else {
    if (flags == 0x6d) {
      if (spell_id == g_ActivePlayerPriority) {
        g_SpellStackDepth = g_SpellStackDepth + -0x18;
      }
      *(uint32_t *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
      uval_1 = g_OverworldPlayerCoordY;
      arg_19 = 0;
      uVar20 = 0;
      uVar19 = 0;
      uVar18 = 0xffffffff;
      uVar16 = 0xffffffff;
      uVar14 = 0xffffffff;
      uVar12 = 0xffffffff;
      uVar10 = 0;
      uval_8 = 0;
      uval_6 = Glue_Subsystem_004d0a42(spell_id,target_id);
      UI_PaintBigCardInfo(&g_OverworldPlayerCoordY,0,spell_id,2,2,0x200,1,0,0,uval_6,uval_8,uVar10,uVar12,
                   uVar14,uVar16,uVar18,uVar19,uVar20,arg_19);
      g_AiSelectedTargetCard = 0xffffffff;
      Ai_CalcManaRequirement_004ba890(spell_id,0,0);
      g_OverworldPlayerCoordY = uval_1;
      if (g_ActivePlayer != 1) {
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
        match_count = 0;
        slot_idx = 0;
        while (((match_count < g_TurnCounter && (slot_idx == 0)) && (g_ActivePlayer != 1))) {
          Pic_Subsystem_00424500(s_prompts_txt_005244a0,s_CANDLEABRA_OF_TAWNOS_00524488);
          sprintf(&g_OverworldGoldAmount,&g_OverworldGoldAmount,match_count + 1,g_TurnCounter);
          arg_20 = &player_idx;
          uval_1 = 1;
          arg_18 = &g_OverworldGoldAmount;
          uVar17 = 0;
          uVar15 = 0;
          uVar13 = 0;
          uVar11 = 0xffffffff;
          uVar9 = 0xffffffff;
          val_7 = -1;
          val_5 = -1;
          uval_4 = 0;
          uval_3 = 0;
          uval_2 = Glue_Subsystem_004d0a42(spell_id,target_id);
          val_5 = Duel_ChooseTarget
                            (spell_id,2,spell_id,0x200,1,0,0,uval_2,uval_3,uval_4,val_5,val_7,uVar9,
                             uVar11,uVar13,uVar15,uVar17,arg_18,uval_1,arg_20);
          if (val_5 == 0) {
            if (card_idx == -1) {
              (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
              g_ActivePlayer = 1;
            }
            else {
              slot_idx = 1;
            }
          }
          else {
            *(uint32_t *)(&g_CardSlot_Flags + player_idx * 0x5b20 + card_idx * 0x120) =
                 *(uint32_t *)(&g_CardSlot_Flags + player_idx * 0x5b20 + card_idx * 0x120) | 0x300000;
            Ai_EvaluateTacticalPosition(0,0x20);
            *(int *)(&g_CardSlot_CombatTarget +
                    target_id * 0x120 +
                    spell_id * 0x5b20 +
                    (char)(&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] * 8) =
                 player_idx;
            *(int *)(&g_CardSlot_AttachedAura +
                    target_id * 0x120 +
                    spell_id * 0x5b20 +
                    (char)(&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] * 8) =
                 card_idx;
            (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] =
                 (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] + '\x01';
          }
          match_count = match_count + 1;
        }
        for (match_count = 0;
            match_count < (char)(&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20];
            match_count = match_count + 1) {
          *(uint32_t *)(&g_CardSlot_Flags +
                   *(int *)(&g_CardSlot_AttachedAura +
                           target_id * 0x120 + spell_id * 0x5b20 + match_count * 8) * 0x120 +
                   *(int *)(&g_CardSlot_CombatTarget +
                           target_id * 0x120 + spell_id * 0x5b20 + match_count * 8) * 0x5b20) =
               *(uint32_t *)(&g_CardSlot_Flags +
                        *(int *)(&g_CardSlot_AttachedAura +
                                target_id * 0x120 + spell_id * 0x5b20 + match_count * 8) * 0x120 +
                        *(int *)(&g_CardSlot_CombatTarget +
                                target_id * 0x120 + spell_id * 0x5b20 + match_count * 8) * 0x5b20) &
               0xffcfffff;
        }
      }
      if (g_ActivePlayer == 1) {
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
        *(uint32_t *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) & 0xffffffef;
      }
    }
    if (flags == 0x72) {
      for (match_count = 0;
          match_count < (char)(&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20];
          match_count = match_count + 1) {
        player_idx = *(int *)(&g_CardSlot_CombatTarget +
                           target_id * 0x120 + spell_id * 0x5b20 + match_count * 8);
        card_idx = *(int *)(&g_CardSlot_AttachedAura +
                           target_id * 0x120 + spell_id * 0x5b20 + match_count * 8);
        uVar17 = 0;
        uVar15 = 0;
        uVar13 = 0;
        uVar11 = 0xffffffff;
        uVar9 = 0xffffffff;
        val_7 = -1;
        val_5 = -1;
        uval_4 = 0;
        uval_3 = 0;
        uval_2 = Glue_Subsystem_004d0a42(spell_id,target_id);
        val_5 = Rules_ParseFilter_0040360b
                          (player_idx,card_idx,(char *)0x0,spell_id,2,2,0x200,1,0,0,uval_2,uval_3,uval_4,
                           val_5,val_7,uVar9,uVar11,uVar13,uVar15,uVar17);
        if (val_5 == 0) {
          g_ActivePlayer = 1;
        }
        else {
          Magic_TriggerCardEvent(player_idx,card_idx,1,0xffffffff,0xffffffff);
          *(uint32_t *)(&g_CardSlot_Flags + player_idx * 0x5b20 + card_idx * 0x120) =
               *(uint32_t *)(&g_CardSlot_Flags + player_idx * 0x5b20 + card_idx * 0x120) & 0xffffffef;
        }
      }
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120] = 0;
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: Minit_Subsystem_0045d842
 * Entry Point: 0045d842
 * Size: 77 bytes
 */


int32_t Minit_Subsystem_0045d842(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  
  if (((arg_3 == 0x73) || (arg_3 == 0x6d)) || (arg_3 == 0x72)) {
    uval_1 = Glue_Subsystem_004d7c60(player,card_slot,arg_3,0,2);
  }
  else {
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: Minit_Subsystem_0045d88f
 * Entry Point: 0045d88f
 * Size: 77 bytes
 */


int32_t Minit_Subsystem_0045d88f(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  
  if (((arg_3 == 0x73) || (arg_3 == 0x6d)) || (arg_3 == 0x72)) {
    uval_1 = Glue_Subsystem_004d7c60(player,card_slot,arg_3,0,3);
  }
  else {
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: CardScript_Forcefield
 * Entry Point: 0045d8dc
 * Size: 1225 bytes
 */


int32_t CardScript_Forcefield(int spell_id,int target_id,int flags)

{
  int32_t uval_1;
  int val_2;
  int match_count;
  int slot_idx;
  
  if (flags == 0x73) {
    if ((((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0) ||
       (((&g_MasterCardColorTable)
         [*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) * 0x34] & 2) != 0)) {
      if (((uint8_t)g_DuelModeFlags & 4) == 0) {
        uval_1 = 0;
      }
      else if ((g_ScWillyScore == 0x1a) || (g_ScWillyScore == 0x19)) {
        val_2 = Font_DrawString(spell_id, 7, 1);
        if (val_2 == 0) {
          uval_1 = 0;
        }
        else {
          val_2 = UI_PaintBigCardInfo((int *)0x0,2,spell_id,1 - spell_id,1 - spell_id,0x200,2,0,0,0,0,0,
                               0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,2,8);
          if (val_2 == 0) {
            uval_1 = 0;
          }
          else {
            uval_1 = 99;
          }
        }
      }
      else {
        uval_1 = 0;
      }
    }
    else {
      uval_1 = 0;
    }
  }
  else if (flags == 0x90) {
    Ai_PeekPlannedSlot(0);
    uval_1 = 0;
  }
  else {
    if ((((flags == 0x6d) && (val_2 = Font_DrawString(spell_id, 7, 1), val_2 != 0)) &&
        (((uint8_t)g_DuelModeFlags & 4) != 0)) &&
       ((g_ScWillyScore == 0x1a || (g_ScWillyScore == 0x19)))) {
      Ai_CalcManaRequirement_004ba890(spell_id,0,1);
      Pic_Subsystem_00424500(s_prompts_txt_005244b8,s_FORCEFIELD_005244ac);
      val_2 = Duel_ChooseTarget
                        (spell_id,spell_id,spell_id,0x200,0,0,0,0,0,0,g_PendingSpellTargetSlot,-1,0xffffffff,
                         0xffffffff,0x20,0,0,&g_OverworldGoldAmount,1,&match_count);
      if (val_2 == 0) {
        g_ActivePlayer = 1;
      }
      else if ((((&g_MasterCardColorTable)
                 [*(int *)(&g_CardSlot_CardId +
                          *(int *)(&g_CardSlot_TypeFlags + match_count * 0x5b20 + slot_idx * 0x120) *
                          0x120 + (char)(&g_CardSlot_DamageReceived)
                                        [match_count * 0x5b20 + slot_idx * 0x120] * 0x5b20) * 0x34] & 2)
                != 0) &&
              (((&DAT_006a5f3d)
                [*(int *)(&g_CardSlot_TypeFlags + match_count * 0x5b20 + slot_idx * 0x120) * 0x120 +
                 (char)(&g_CardSlot_DamageReceived)[match_count * 0x5b20 + slot_idx * 0x120] * 0x5b20] &
               2) == 0)) {
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = match_count;
        *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = slot_idx;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
      }
    }
    if (flags == 0x72) {
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120] = 0;
      val_2 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20),
                         (char *)0x0,spell_id,(uint8_t)spell_id,(uint8_t)spell_id,0x200,0,0,0,0,0,0,
                         g_PendingSpellTargetSlot,-1,0xffffffff,0xffffffff,0,0,0);
      if (val_2 == 0) {
        g_ActivePlayer = 1;
      }
      else if (*(int *)(&g_CardSlot_ConvertedManaCost +
                       *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) *
                       0x5b20 + *(int *)(&g_CardSlot_AttachedAura +
                                        target_id * 0x120 + spell_id * 0x5b20) * 0x120) != 0) {
        *(int32_t *)
         (&g_CardSlot_ConvertedManaCost +
         *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) * 0x120) = 1;
      }
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: CardScript_DisruptingScepter
 * Entry Point: 0045dda5
 * Size: 716 bytes
 */


int32_t CardScript_DisruptingScepter(int spell_id,int target_id,int flags)

{
  int val_1;
  int32_t uval_2;
  int match_count;
  int32_t slot_idx;
  
  if (flags == 0x73) {
    val_1 = Font_DrawString(spell_id,7,3);
    if ((((val_1 == 0) || (g_TurnPlayer != spell_id)) ||
        ((((&g_CardSlot_Subtypes)[target_id * 0x120 + spell_id * 0x5b20] & 3) != 0 &&
         (((&g_MasterCardColorTable)
           [*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) * 0x34] & 2) != 0))
        )) || (((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) != 0)) {
      uval_2 = 0;
    }
    else {
      uval_2 = 1;
    }
  }
  else {
    if ((((flags == 0x6d) &&
         (((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0)) &&
        (val_1 = Font_DrawString(spell_id,7,3), val_1 != 0)) &&
       ((g_TurnPlayer == spell_id &&
        (Ai_CalcManaRequirement_004ba890(spell_id,0,3), g_ActivePlayer != 1)))) {
      Pic_Subsystem_00424500(s_prompts_txt_005244d8,s_DISRUPTING_SCEPTER_005244c4);
      val_1 = Duel_ChooseTarget
                        (spell_id,2,1 - spell_id,0x1000,0,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0,0,
                         0,&g_OverworldGoldAmount,1,&match_count);
      if (val_1 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = match_count;
        *(int32_t *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = slot_idx;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        *(uint32_t *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
      }
    }
    if (flags == 0x72) {
      Prompts_Load_0046fa40
                (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),0,0);
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120] = 0;
    }
    uval_2 = 0;
  }
  return uval_2;
}



/*
 * Decompiled function: Minit_Subsystem_0045e071
 * Entry Point: 0045e071
 * Size: 395 bytes
 */


int32_t Minit_Subsystem_0045e071(int player_id,int card_slot,int event_type)

{
  if (((arg_3 == 0x6c) && (g_EventSourceSlot == card_slot)) && (g_EventSourcePlayer == player)) {
    g_SpellStackDepth =
         g_SpellStackDepth +
         ((&g_PlayerCreatureCount)[player] - (&g_PlayerCreatureCount)[1 - player]) * 0x18;
  }
  if (((arg_3 == 2) || (arg_3 == 3)) &&
     ((g_EventSourceSlot == card_slot &&
      ((g_EventSourcePlayer == player &&
       (*(int *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) == 0)))))) {
    g_CardEventResult = g_CardEventResult | 2;
  }
  if (((((arg_3 == 4) || (arg_3 == 5)) || (arg_3 == 199)) &&
      ((g_EventSourceSlot == card_slot && (g_EventSourcePlayer == player)))) &&
     (*(int *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) == 0)) {
    Mem_AllocOrFree_0041df33(g_TurnPlayer,1,player,card_slot);
    *(int32_t *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) = 1;
  }
  if (arg_3 == 0x22) {
    *(int32_t *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) = 0;
  }
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_0045e1fc
 * Entry Point: 0045e1fc
 * Size: 169 bytes
 */


int32_t Minit_Subsystem_0045e1fc(int player_id,int card_slot,int event_type)

{
  if (((arg_3 == 0x6c) && (card_slot == g_EventSourceSlot)) && (player == g_EventSourcePlayer)) {
    g_SpellStackDepth =
         g_SpellStackDepth +
         (*(int *)(&DAT_006b3010 + player * 4) - *(int *)(&DAT_006b3000 + (5 - player) * 4)) * 0xc;
  }
  if (((arg_3 == 0x32) &&
      (((&g_CardSlot_Flags)[g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20] & 4) != 0
      )) && (g_TurnPlayer == g_EventSourcePlayer)) {
    g_CardEventResult = g_CardEventResult + 1;
  }
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_0045e2a5
 * Entry Point: 0045e2a5
 * Size: 171 bytes
 */


int32_t Minit_Subsystem_0045e2a5(int player_id,int card_slot,int event_type)

{
  if (((arg_3 == 0x6c) && (g_EventSourceSlot == card_slot)) && (g_EventSourcePlayer == player)) {
    g_SpellStackDepth =
         g_SpellStackDepth +
         (*(int *)(&DAT_006b3000 + (5 - player) * 4) - *(int *)(&DAT_006b3010 + player * 4)) * 0xc;
  }
  if (((arg_3 == 0x32) &&
      (((&g_CardSlot_Flags)[g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20] & 4) != 0
      )) && (g_TurnPlayer == g_EventSourcePlayer)) {
    g_CardEventResult = g_CardEventResult + -1;
  }
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_0045e350
 * Entry Point: 0045e350
 * Size: 34 bytes
 */


int32_t Minit_Subsystem_0045e350(int32_t player,int32_t card_slot,int event_type)

{
  if (arg_3 == 10) {
    g_CardEventResult = g_CardEventResult + 1;
  }
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_0045e372
 * Entry Point: 0045e372
 * Size: 38 bytes
 */


void Minit_Subsystem_0045e372(int player_id,int card_slot,int event_type)

{
  Mana_Init_0045e430(player,card_slot,arg_3,2);
  return;
}



/*
 * Decompiled function: Minit_Subsystem_0045e398
 * Entry Point: 0045e398
 * Size: 38 bytes
 */


void Minit_Subsystem_0045e398(int player_id,int card_slot,int event_type)

{
  Mana_Init_0045e430(player,card_slot,arg_3,4);
  return;
}



/*
 * Decompiled function: Minit_Subsystem_0045e3be
 * Entry Point: 0045e3be
 * Size: 38 bytes
 */


void Minit_Subsystem_0045e3be(int player_id,int card_slot,int event_type)

{
  Mana_Init_0045e430(player,card_slot,arg_3,3);
  return;
}



/*
 * Decompiled function: Minit_Subsystem_0045e3e4
 * Entry Point: 0045e3e4
 * Size: 38 bytes
 */


void Minit_Subsystem_0045e3e4(int player_id,int card_slot,int event_type)

{
  Mana_Init_0045e430(player,card_slot,arg_3,5);
  return;
}



/*
 * Decompiled function: Minit_Subsystem_0045e40a
 * Entry Point: 0045e40a
 * Size: 38 bytes
 */


void Minit_Subsystem_0045e40a(int player_id,int card_slot,int event_type)

{
  Mana_Init_0045e430(player,card_slot,arg_3,1);
  return;
}



/*
 * Decompiled function: Mana_Init_0045e430
 * Entry Point: 0045e430
 * Size: 1569 bytes
 */


int32_t Mana_Init_0045e430(int x,int y,int width,int height)

{
  int32_t uval_1;
  int val_2;
  int local_78;
  char local_74 [100];
  int card_idx;
  int match_count;
  int slot_idx;
  
  if (width == 0x73) {
    if (((((&g_CardSlot_Subtypes)[y * 0x120 + x * 0x5b20] & 3) == 0) ||
        (((&g_MasterCardColorTable)[*(int *)(&g_CardSlot_CardId + y * 0x120 + x * 0x5b20) * 0x34] &
         2) == 0)) && (((&g_CardSlot_Flags)[y * 0x120 + x * 0x5b20] & 0x10) == 0)) {
      uval_1 = 1;
    }
    else {
      uval_1 = 0;
    }
  }
  else {
    if ((width == 0x6d) && (((&g_CardSlot_Flags)[y * 0x120 + x * 0x5b20] & 0x10) == 0)) {
      slot_idx = Glue_Subsystem_004e6978(x,y);
      if ((g_AiManaPoolReserve == 0) && (val_2 = Font_DrawString(x,7,slot_idx + 3), val_2 != 0)) {
        strcpy(&g_OverworldWorldState,s_Tap_to_get_mana__005244e4);
        strcat(&g_OverworldWorldState,s_Charge_battery__add_counter___005244f8);
        strcat(&g_OverworldWorldState,s_Cancel__00524518);
        if ((g_ScWillyScore == 0x1f) && (1 - x == g_TurnPlayer)) {
          card_idx = 1;
        }
        else {
          card_idx = 0;
        }
        match_count = Ai_Subsystem_004cc56d(x,x,y,-1,-1,&g_OverworldWorldState,card_idx);
      }
      else {
        match_count = 0;
      }
      *(int32_t *)(&g_CardSlot_ConvertedManaCost + y * 0x120 + x * 0x5b20) = 0;
      if (match_count == 0) {
        FUN_0040d875(x,height,1);
        slot_idx = Glue_Subsystem_004e6978(x,y);
        if (slot_idx != 0) {
          if (((x == 1) || (g_IsAiThinking == 1)) || (g_AiTurnDecisionFlag != 0)) {
            if (g_IsAiThinking == 1) {
              local_78 = Util_GetRandomNumber(slot_idx + 1);
              g_AiChoiceValue = local_78;
              Ai_RecordChoice();
            }
            else {
              Ai_ReplayChoice();
              local_78 = g_AiChoiceValue;
            }
          }
          else {
            sprintf(local_74,s__s_How_many_counters_do_you_wish_00524524,
                    *(int32_t *)
                     (&DAT_006b3074 +
                     *(int *)(&g_MasterCardTypeTable +
                             *(int *)(&g_CardSlot_CardId + y * 0x120 + x * 0x5b20) * 0x34) * 0x98),
                    slot_idx);
            local_78 = Ai_Subsystem_004cc8de(x,local_74,0);
          }
          if (local_78 == -1) {
            g_ActivePlayer = 1;
          }
          else {
            if (slot_idx < local_78) {
              local_78 = slot_idx;
            }
            FUN_0040d901(x,height,local_78);
            Glue_Subsystem_004e689b(x,y,local_78);
          }
        }
        if (g_ActivePlayer == 1) {
          FUN_0040d8b7(x,height,1);
        }
        else {
          *(int32_t *)(&g_CardSlot_ConvertedManaCost + y * 0x120 + x * 0x5b20) = 0;
          *(uint32_t *)(&g_CardSlot_Flags + y * 0x120 + x * 0x5b20) =
               *(uint32_t *)(&g_CardSlot_Flags + y * 0x120 + x * 0x5b20) | 0x10;
          g_PendingAttackersTargetSlot = height;
        }
      }
      else if (match_count == 1) {
        *(uint32_t *)(&g_CardSlot_Flags + y * 0x120 + x * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_Flags + y * 0x120 + x * 0x5b20) | 0x10;
        Ai_CalcManaRequirement_004ba890(x,0,2);
        if (g_ActivePlayer == 1) {
          *(uint32_t *)(&g_CardSlot_Flags + y * 0x120 + x * 0x5b20) =
               *(uint32_t *)(&g_CardSlot_Flags + y * 0x120 + x * 0x5b20) & 0xffffffef;
        }
        if (g_ActivePlayer != 1) {
          *(int32_t *)(&g_CardSlot_ConvertedManaCost + y * 0x120 + x * 0x5b20) = 1;
          g_PendingAttackersTargetSlot = -1;
        }
      }
      else if (match_count == 2) {
        g_ActivePlayer = 1;
      }
    }
    if ((width == 0x72) && (*(int *)(&g_CardSlot_ConvertedManaCost + y * 0x120 + x * 0x5b20) == 1))
    {
      Glue_Subsystem_004e66b3(g_DialogPromptHwnd,g_DuelArenaHwnd);
      *(int32_t *)
       (&g_CardSlot_ConvertedManaCost +
       *(int *)(&g_CardSlot_SicknessState + y * 0x120 + x * 0x5b20) * 0x120 +
       *(int *)(&g_CardSlot_TapState + y * 0x120 + x * 0x5b20) * 0x5b20) = 0;
    }
    if (((width == 0x7f) && (g_EventSourceSlot == y)) &&
       ((g_EventSourcePlayer == x && (((&g_CardSlot_Flags)[y * 0x120 + x * 0x5b20] & 0x10) == 0)
        ))) {
      FUN_0040d7e9(x,height,1);
      val_2 = Glue_Subsystem_004e6978(x,y);
      FUN_0040d7e9(x,height,val_2);
    }
    if (((width == 0x8f) && (*(int *)(&DAT_0063eea4 + x * 0x20) != 0)) &&
       (((&g_CardSlot_Flags)[y * 0x120 + x * 0x5b20] & 0x10) == 0)) {
      g_CardEventResult = g_CardEventResult | 1;
    }
    if ((width == 199) && (g_ActivePlayerPriority == x)) {
      val_2 = Glue_Subsystem_004e6978(x,y);
      g_SpellStackDepth = g_SpellStackDepth + val_2 * 0xc;
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: Minit_Subsystem_0045ea5b
 * Entry Point: 0045ea5b
 * Size: 388 bytes
 */


int32_t Minit_Subsystem_0045ea5b(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  int val_2;
  
  if (arg_3 == 0x73) {
    if (((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) == 0) {
      uval_1 = 1;
    }
    else {
      uval_1 = Font_DrawString(player,7,3);
    }
  }
  else {
    if (arg_3 == 0x6d) {
      if (((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) == 0) {
        FUN_0040d875(player,0,3);
        g_SpellStackDepth = g_SpellStackDepth + -0x24;
        *(int32_t *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) = 1;
      }
      else {
        val_2 = Font_DrawString(player,7,3);
        if ((val_2 != 0) &&
           ((g_CurrentTurnPhase == player ||
            (*(int *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) == 0)))) {
          Ai_CalcManaRequirement_004ba890(player,0,3);
        }
      }
    }
    if (arg_3 == 0x72) {
      *(uint32_t *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) ^ 0x10;
    }
    if (arg_3 == 0x22) {
      *(int32_t *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) = 0;
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: CardScript_Conservator
 * Entry Point: 0045ebe4
 * Size: 1647 bytes
 */


int32_t CardScript_Conservator(int spell_id,int target_id,int flags)

{
  int val_1;
  int32_t uval_2;
  int target_idx;
  int player_idx;
  int card_idx;
  int match_count;
  int slot_idx;
  
  if (((flags == 0x6c) && (target_id == g_EventSourceSlot)) &&
     (spell_id == g_EventSourcePlayer)) {
    g_SpellStackDepth = g_SpellStackDepth + *(int *)(&g_PlayerManaPoolDelta + spell_id * 0x20) * 6;
  }
  if (flags == 0x73) {
    if ((((uint8_t)g_DuelModeFlags & 4) == 0) ||
       ((((((&g_CardSlot_Subtypes)[spell_id * 0x5b20 + target_id * 0x120] & 3) != 0 &&
          (((&g_MasterCardColorTable)
            [*(int *)(&g_CardSlot_CardId + spell_id * 0x5b20 + target_id * 0x120) * 0x34] & 2) != 0)
          ) || (((&g_CardSlot_Flags)[spell_id * 0x5b20 + target_id * 0x120] & 0x10) != 0)) ||
        ((val_1 = Font_DrawString(spell_id,7,3), val_1 == 0 ||
         (val_1 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,spell_id,spell_id,0x200,0,0,0,0,0,0,
                               g_PendingSpellTargetSlot,0xffffffff,0xffffffff,0xffffffff,0x20,0,0), val_1 == 0))
        )))) {
      uval_2 = 0;
    }
    else {
      uval_2 = 99;
    }
  }
  else if (flags == 0x90) {
    Ai_PeekPlannedSlot(0);
    uval_2 = 0;
  }
  else {
    if (((flags == 0x6d) &&
        (((&g_CardSlot_Flags)[spell_id * 0x5b20 + target_id * 0x120] & 0x10) == 0)) &&
       (Ai_CalcManaRequirement_004ba890(spell_id,0,3), g_ActivePlayer != 1)) {
      (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 0;
      card_idx = 0;
      match_count = 0;
      while (((card_idx < 2 && (match_count == 0)) && (g_ActivePlayer != 1))) {
        Pic_Subsystem_00424500(s_prompts_txt_0052457c,s_CONSERVATOR_00524570);
        val_1 = Duel_ChooseTarget
                          (spell_id,spell_id,spell_id,0x200,0,0,0,0,0,0,g_PendingSpellTargetSlot,-1,0xffffffff,
                           0xffffffff,0x20,0,0,&g_OverworldGoldAmount,3,&target_idx);
        if (val_1 == 0) {
          if (player_idx == -1) {
            g_ActivePlayer = 1;
          }
          else {
            match_count = 1;
          }
        }
        else {
          *(uint32_t *)(&g_CardSlot_Flags + target_idx * 0x5b20 + player_idx * 0x120) =
               *(uint32_t *)(&g_CardSlot_Flags + target_idx * 0x5b20 + player_idx * 0x120) | 0x200000;
          Ai_EvaluateTacticalPosition(0,0x20);
          *(int *)(&g_CardSlot_CombatTarget +
                  spell_id * 0x5b20 +
                  target_id * 0x120 +
                  (char)(&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] * 8) =
               target_idx;
          *(int *)(&g_CardSlot_AttachedAura +
                  spell_id * 0x5b20 +
                  target_id * 0x120 +
                  (char)(&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] * 8) =
               player_idx;
          (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] =
               (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] + '\x01';
        }
        card_idx = card_idx + 1;
      }
      for (card_idx = 0;
          card_idx < (char)(&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120];
          card_idx = card_idx + 1) {
        *(uint32_t *)(&g_CardSlot_Flags +
                 *(int *)(&g_CardSlot_AttachedAura +
                         spell_id * 0x5b20 + target_id * 0x120 + card_idx * 8) * 0x120 +
                 *(int *)(&g_CardSlot_CombatTarget +
                         spell_id * 0x5b20 + target_id * 0x120 + card_idx * 8) * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_Flags +
                      *(int *)(&g_CardSlot_AttachedAura +
                              spell_id * 0x5b20 + target_id * 0x120 + card_idx * 8) * 0x120 +
                      *(int *)(&g_CardSlot_CombatTarget +
                              spell_id * 0x5b20 + target_id * 0x120 + card_idx * 8) * 0x5b20) &
             0xffcfffff;
      }
      if (g_ActivePlayer == 1) {
        (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 0;
      }
      else {
        *(uint32_t *)(&g_CardSlot_Flags + spell_id * 0x5b20 + target_id * 0x120) =
             *(uint32_t *)(&g_CardSlot_Flags + spell_id * 0x5b20 + target_id * 0x120) | 0x10;
      }
    }
    if (flags == 0x72) {
      slot_idx = 0;
      for (card_idx = 0;
          card_idx < (char)(&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120];
          card_idx = card_idx + 1) {
        target_idx = *(int *)(&g_CardSlot_CombatTarget +
                           card_idx * 8 + target_id * 0x120 + spell_id * 0x5b20);
        player_idx = *(int *)(&g_CardSlot_AttachedAura +
                           card_idx * 8 + target_id * 0x120 + spell_id * 0x5b20);
        val_1 = Rules_ParseFilter_0040360b
                          (*(int *)(&g_CardSlot_CombatTarget +
                                   card_idx * 8 + target_id * 0x120 + spell_id * 0x5b20),
                           *(int *)(&g_CardSlot_AttachedAura +
                                   card_idx * 8 + target_id * 0x120 + spell_id * 0x5b20),(char *)0x0
                           ,spell_id,(uint8_t)spell_id,(uint8_t)spell_id,0x200,0,0,0,0,0,0,g_PendingSpellTargetSlot,-1
                           ,0xffffffff,0xffffffff,0x20,0,0);
        if (val_1 == 0) {
          slot_idx = slot_idx + 1;
        }
        else if (*(int *)(&g_CardSlot_ConvertedManaCost + target_idx * 0x5b20 + player_idx * 0x120) != 0
                ) {
          *(int *)(&g_CardSlot_ConvertedManaCost + target_idx * 0x5b20 + player_idx * 0x120) =
               *(int *)(&g_CardSlot_ConvertedManaCost + target_idx * 0x5b20 + player_idx * 0x120) + -1;
        }
      }
      if ((char)(&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] == slot_idx) {
        g_ActivePlayer = 1;
      }
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_TapState + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + spell_id * 0x5b20 + target_id * 0x120) * 0x120] = 0;
    }
    uval_2 = 0;
  }
  return uval_2;
}



/*
 * Decompiled function: Minit_Subsystem_0045f258
 * Entry Point: 0045f258
 * Size: 371 bytes
 */


int32_t Minit_Subsystem_0045f258(int player_id,int card_slot,int event_type)

{
  char cVar1;
  uint8_t flag_2;
  int arg_2_00;
  int arg_3_00;
  
  if (((arg_3 == 0x33) || (arg_3 == 0x32)) &&
     (((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) == 0)) {
    cVar1 = (&g_CardSlot_PlusOneCounters)[g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20];
    flag_2 = Card_RemapColorIndexF9(player, card_slot, 4);
    if ((1 << (flag_2 & 0x1f) & (int)cVar1) != 0) {
      g_CardEventResult = g_CardEventResult + 1;
    }
  }
  if (((arg_3 == 0x7c) && (((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) == 0)) &&
     (((&g_MasterCardColorTable)
       [*(int *)(&g_CardSlot_CardId + g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20)
        * 0x34] & 1) != 0)) {
    cVar1 = (&g_CardSlot_PlusOneCounters)[g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20];
    flag_2 = Card_RemapColorIndexFF(player,card_slot,4);
    if ((1 << (flag_2 & 0x1f) & (int)cVar1) != 0) {
      arg_3_00 = 1;
      arg_2_00 = Card_RemapColorIndexFF(player,card_slot,4);
      FUN_0040d875(g_EventSourcePlayer,arg_2_00,arg_3_00);
    }
  }
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_0045f3cb
 * Entry Point: 0045f3cb
 * Size: 38 bytes
 */


void Minit_Subsystem_0045f3cb(int player_id,int card_slot,int event_type)

{
  Minit_Subsystem_0045f4af(player,card_slot,arg_3,4);
  return;
}



/*
 * Decompiled function: Minit_Subsystem_0045f3f1
 * Entry Point: 0045f3f1
 * Size: 38 bytes
 */


void Minit_Subsystem_0045f3f1(int player_id,int card_slot,int event_type)

{
  Minit_Subsystem_0045f4af(player,card_slot,arg_3,5);
  return;
}



/*
 * Decompiled function: Minit_Subsystem_0045f417
 * Entry Point: 0045f417
 * Size: 38 bytes
 */


void Minit_Subsystem_0045f417(int player_id,int card_slot,int event_type)

{
  Minit_Subsystem_0045f4af(player,card_slot,arg_3,2);
  return;
}



/*
 * Decompiled function: Minit_Subsystem_0045f43d
 * Entry Point: 0045f43d
 * Size: 38 bytes
 */


void Minit_Subsystem_0045f43d(int player_id,int card_slot,int event_type)

{
  Minit_Subsystem_0045f4af(player,card_slot,arg_3,1);
  return;
}



/*
 * Decompiled function: Minit_Subsystem_0045f463
 * Entry Point: 0045f463
 * Size: 38 bytes
 */


void Minit_Subsystem_0045f463(int player_id,int card_slot,int event_type)

{
  Minit_Subsystem_0045f4af(player,card_slot,arg_3,3);
  return;
}



/*
 * Decompiled function: Minit_Subsystem_0045f489
 * Entry Point: 0045f489
 * Size: 38 bytes
 */


void Minit_Subsystem_0045f489(int player_id,int card_slot,int event_type)

{
  Minit_Subsystem_0045f4af(player,card_slot,arg_3,0);
  return;
}



/*
 * Decompiled function: Minit_Subsystem_0045f4af
 * Entry Point: 0045f4af
 * Size: 467 bytes
 */


int32_t Minit_Subsystem_0045f4af(int x,int y,int width,int height)

{
  uint8_t flag_1;
  int val_2;
  
  if (((width == 0x6c) && (g_EventSourceSlot == y)) && (g_EventSourcePlayer == x)) {
    g_SpellStackDepth =
         g_SpellStackDepth +
         *(int *)(&g_AiCombatScore_Attacker + height * 4 + g_ActivePlayerPriority * 0x20) * 0xc;
  }
  if (((g_CurrentStepCode == 0xd3) && (g_EventSourceSlot == y)) &&
     ((g_EventSourcePlayer == x &&
      ((g_CurrentCardColorTarget == x && (((&g_CardSlot_Flags)[y * 0x120 + x * 0x5b20] & 0x20) == 0)))))) {
    val_2 = Font_DrawString(x,7,1);
    if (val_2 != 0) {
      flag_1 = Card_RemapColorIndexF9(x,y,height);
      if (((1 << (flag_1 & 0x1f) &
           (int)(char)(&g_CardSlot_MinusOneCounters)[DAT_006b2e14 * 0x120 + DAT_00695f08 * 0x5b20]) != 0) &&
         ((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId + DAT_006b2e14 * 0x120 + DAT_00695f08 * 0x5b20) * 0x34] !=
          '\x01')) {
        if (width == 0x7d) {
          if (g_ActivePlayerPriority == x) {
            g_CardEventResult = g_CardEventResult | 2;
          }
          else {
            g_CardEventResult = g_CardEventResult | 1;
          }
        }
        if (width == 0x7e) {
          Ai_CalcManaRequirement_004ba890(x,0,1);
          if ((g_ActivePlayer != 1) &&
             ((&g_PlayerCreatureCount)[x] = (&g_PlayerCreatureCount)[x] + 1,
             g_ActivePlayerPriority == x)) {
            g_SpellStackDepth = g_SpellStackDepth + -0x18;
          }
        }
      }
    }
  }
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_0045f682
 * Entry Point: 0045f682
 * Size: 425 bytes
 */


int32_t Minit_Subsystem_0045f682(int player_id,int card_slot,int event_type)

{
  if (((arg_3 == 0x6c) && (card_slot == g_EventSourceSlot)) && (player == g_EventSourcePlayer)) {
    g_SpellStackDepth =
         g_SpellStackDepth +
         (*(int *)(&g_PlayerManaPoolDelta + g_ActivePlayerPriority * 0x20) -
         *(int *)(&g_PlayerManaPoolDelta + g_CurrentTurnPhase * 0x20)) * 0xc;
  }
  if (((((g_CurrentStepCode == 0xdb) || (g_CurrentStepCode == 0xd3)) &&
       ((card_slot == g_EventSourceSlot &&
        ((player == g_EventSourcePlayer && (g_CurrentCardColorTarget == g_TurnPlayer)))))) &&
      (*(int *)(&g_CardSlot_CardId + DAT_006b2e14 * 0x120 + DAT_00695f08 * 0x5b20) != -1)) &&
     ((((&g_MasterCardColorTable)
        [*(int *)(&g_CardSlot_CardId + DAT_006b2e14 * 0x120 + DAT_00695f08 * 0x5b20) * 0x34] & 1) !=
       0 && ((((&g_CardSlot_Flags)[player * 0x5b20 + card_slot * 0x120] & 0x10) == 0 ||
             (((&g_MasterCardColorTable)
               [*(int *)(&g_CardSlot_CardId + player * 0x5b20 + card_slot * 0x120) * 0x34] & 2) != 0)))))
     ) {
    if (arg_3 == 0x7d) {
      g_CardEventResult = g_CardEventResult | 2;
    }
    if (arg_3 == 0x7e) {
      Mem_AllocOrFree_0041df33(DAT_00695f08,2,player,card_slot);
    }
  }
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_0045f82b
 * Entry Point: 0045f82b
 * Size: 1408 bytes
 */


int Minit_Subsystem_0045f82b(int player_id,int card_slot,int event_type)

{
  bool flag_1;
  int val_2;
  int y;
  int height;
  int match_count;
  
  if (((arg_3 == 0x6c) && (card_slot == g_EventSourceSlot)) && (player == g_EventSourcePlayer)) {
    g_SpellStackDepth =
         g_SpellStackDepth +
         ((&g_PlayerCreatureCount)[g_ActivePlayerPriority] -
         (&g_PlayerCreatureCount)[g_CurrentTurnPhase]) * 0x18;
  }
  if ((((g_CurrentStepCode == 0xc9) || (arg_3 == 199)) &&
      ((card_slot == g_EventSourceSlot &&
       ((player == g_EventSourcePlayer && (player == g_TurnPlayer)))))) &&
     ((((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) == 0 ||
      (((&g_MasterCardColorTable)
        [*(int *)(&g_CardSlot_CardId + card_slot * 0x120 + player * 0x5b20) * 0x34] & 2) != 0)))) {
    if (arg_3 == 0x7d) {
      g_CardEventResult = g_CardEventResult | 2;
    }
    if ((arg_3 == 0x7e) || (arg_3 == 199)) {
      Glue_Subsystem_004e66b3(player,card_slot);
      Ai_EvaluateTacticalPosition(0,0x20);
    }
  }
  if (arg_3 == 0x73) {
    if ((((g_ScWillyScore == 4) && (val_2 = Glue_Subsystem_004e6978(player,card_slot), val_2 != 0)) &&
        (val_2 = Font_DrawString(g_CurrentTurnTargetPlayer,7,4), val_2 != 0)) &&
       (((&g_CardSlot_ConvertedManaCost)[card_slot * 0x120 + player * 0x5b20] & 1) == 0)) {
      if (g_CurrentTurnTargetPlayer == g_CurrentTurnPhase) {
        match_count = 1;
      }
      else {
        if (((int)(&g_PlayerCreatureCount)[g_ActivePlayerPriority] <
             (int)(&g_PlayerCreatureCount)[g_CurrentTurnPhase]) ||
           (val_2 = Glue_Subsystem_004e6978(player,card_slot),
           (int)(&g_PlayerCreatureCount)[g_ActivePlayerPriority] < val_2)) {
          match_count = 1;
        }
        else {
          match_count = 0;
        }
        if (match_count != 0) {
          g_CombatPhaseFlags = g_CombatPhaseFlags | 3;
        }
      }
    }
    else {
      match_count = 0;
    }
  }
  else {
    if (((arg_3 == 0x6d) && (card_slot == g_EventSourceSlot)) && (player == g_EventSourcePlayer)) {
      *(uint32_t *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) | 1;
    }
    if ((arg_3 == 0x72) &&
       (*(int *)(&g_CardSlot_CardId +
                *(int *)(&g_CardSlot_SicknessState + card_slot * 0x120 + player * 0x5b20) * 0x120 +
                *(int *)(&g_CardSlot_TapState + card_slot * 0x120 + player * 0x5b20) * 0x5b20) != -1)) {
      *(int32_t *)
       (&g_CardSlot_ConvertedManaCost +
       *(int *)(&g_CardSlot_SicknessState + card_slot * 0x120 + player * 0x5b20) * 0x120 +
       *(int *)(&g_CardSlot_TapState + card_slot * 0x120 + player * 0x5b20) * 0x5b20) = 0;
      if (((int)(&g_PlayerCreatureCount)[g_ActivePlayerPriority] <
           (int)(&g_PlayerCreatureCount)[g_CurrentTurnPhase]) ||
         (val_2 = Glue_Subsystem_004e6978(player,card_slot),
         (int)(&g_PlayerCreatureCount)[g_ActivePlayerPriority] < val_2)) {
        flag_1 = true;
      }
      else {
        flag_1 = false;
      }
      if (((g_IsAiThinking != 1) && (g_AiTurnDecisionFlag == 0)) && (g_CurrentTurnTargetPlayer != 1)) {
        flag_1 = true;
      }
      if (flag_1) {
        Ai_CalcManaRequirement_004ba890(g_CurrentTurnTargetPlayer,0,4);
        if (g_ActivePlayer == 1) {
          g_ActivePlayer = -1;
        }
        else {
          Glue_Subsystem_004e676b(g_DialogPromptHwnd,g_DuelArenaHwnd);
        }
      }
    }
    if (((g_CurrentStepCode == 0xcb) || (arg_3 == 199)) &&
       ((((card_slot == g_EventSourceSlot &&
          ((player == g_EventSourcePlayer && (player == g_TurnPlayer)))) &&
         (g_CurrentCardColorTarget == player)) &&
        (((((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) == 0 ||
          (((&g_MasterCardColorTable)
            [*(int *)(&g_CardSlot_CardId + card_slot * 0x120 + player * 0x5b20) * 0x34] & 2) != 0)) &&
         (val_2 = Glue_Subsystem_004e6978(player,card_slot), val_2 != 0)))))) {
      if (arg_3 == 0x7d) {
        g_CardEventResult = g_CardEventResult | 2;
      }
      if ((arg_3 == 0x7e) || (arg_3 == 199)) {
        val_2 = player;
        height = card_slot;
        y = Glue_Subsystem_004e6978(player,card_slot);
        Mem_AllocOrFree_0041df33(g_TurnPlayer,y,val_2,height);
        val_2 = Glue_Subsystem_004e6978(player,card_slot);
        Mem_AllocOrFree_0041df33(1 - g_TurnPlayer,val_2,player,card_slot);
      }
    }
    match_count = 0;
  }
  return match_count;
}



/*
 * Decompiled function: Minit_Subsystem_0045fdb5
 * Entry Point: 0045fdb5
 * Size: 711 bytes
 */


int32_t Minit_Subsystem_0045fdb5(int player_id,int card_slot,int event_type)

{
  int match_count;
  int slot_idx;
  
  if ((((arg_3 == 0x77) &&
       ((&g_CardSlot_CardTypeIndex)[g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20] != '\0')) &&
      (((&g_MasterCardColorTable)
        [*(int *)(&g_CardSlot_CardId + g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20
                 ) * 0x34] & 1) != 0)) &&
     ((&g_CardSlot_CardTypeIndex)[g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20] != '\x04')) {
    if (g_EventSourcePlayer == 0) {
      *(int *)(&g_CardSlot_ConvertedManaCost + player * 0x5b20 + card_slot * 0x120) =
           *(int *)(&g_CardSlot_ConvertedManaCost + player * 0x5b20 + card_slot * 0x120) + 1;
    }
    else {
      *(int *)(&g_CardSlot_ConvertedManaCost + player * 0x5b20 + card_slot * 0x120) =
           *(int *)(&g_CardSlot_ConvertedManaCost + player * 0x5b20 + card_slot * 0x120) + 0x100;
    }
  }
  if ((((g_CurrentStepCode == 0xd5) && (card_slot == g_EventSourceSlot)) &&
      ((player == g_EventSourcePlayer &&
       (((*(uint32_t *)(&g_CardSlot_ConvertedManaCost + player * 0x5b20 + card_slot * 0x120) & 0xffff) != 0
        && (player == g_CurrentCardColorTarget)))))) &&
     ((((&g_CardSlot_Flags)[player * 0x5b20 + card_slot * 0x120] & 0x10) == 0 ||
      (((&g_MasterCardColorTable)
        [*(int *)(&g_CardSlot_CardId + player * 0x5b20 + card_slot * 0x120) * 0x34] & 2) != 0)))) {
    if (arg_3 == 0x7d) {
      g_CardEventResult = g_CardEventResult | 2;
    }
    if (arg_3 == 0x7e) {
      for (slot_idx = 0; slot_idx < 2; slot_idx = slot_idx + 1) {
        if ((&g_CardSlot_ConvertedManaCost)[player * 0x5b20 + card_slot * 0x120] != '\0') {
          for (match_count = 0;
              match_count < (int)(*(uint32_t *)(&g_CardSlot_ConvertedManaCost +
                                       player * 0x5b20 + card_slot * 0x120) & 0xff);
              match_count = match_count + 1) {
            Mem_AllocOrFree_0041df33(slot_idx,2,player,card_slot);
          }
        }
        *(int *)(&g_CardSlot_ConvertedManaCost + player * 0x5b20 + card_slot * 0x120) =
             *(int *)(&g_CardSlot_ConvertedManaCost + player * 0x5b20 + card_slot * 0x120) >> 8;
      }
      *(int32_t *)(&g_CardSlot_ConvertedManaCost + player * 0x5b20 + card_slot * 0x120) = 0;
    }
  }
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_0046007c
 * Entry Point: 0046007c
 * Size: 825 bytes
 */


int32_t Minit_Subsystem_0046007c(int player_id,int card_slot,int event_type)

{
  int val_1;
  
  if (((arg_3 == 0x6c) && (g_EventSourceSlot == card_slot)) && (player == g_EventSourcePlayer)) {
    g_SpellStackDepth = g_SpellStackDepth + 0x90;
  }
  if (((arg_3 == 0x77) &&
      ((&g_CardSlot_CardTypeIndex)[g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20] != '\0')) &&
     ((((&g_MasterCardColorTable)
        [*(int *)(&g_CardSlot_CardId + g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20
                 ) * 0x34] & 2) != 0 &&
      ((&g_CardSlot_CardTypeIndex)[g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20] != '\x04'))))
  {
    if (((&DAT_006a5f55)[card_slot * 0x120 + player * 0x5b20] & 1) == 0) {
      *(int *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) =
           *(int *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) + 1;
    }
    else {
      *(int32_t *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) = 1;
    }
  }
  if (((g_CurrentStepCode == 0xd5) && (g_EventSourceSlot == card_slot)) &&
     ((player == g_EventSourcePlayer &&
      (((&g_CardSlot_ConvertedManaCost)[card_slot * 0x120 + player * 0x5b20] != '\0' &&
       (player == g_CurrentCardColorTarget)))))) {
    *(uint32_t *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) =
         *(uint32_t *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) | 0x100;
    if ((arg_3 == 0x7d) && (val_1 = Font_DrawString(player,7,1), val_1 != 0)) {
      if ((player == g_ActivePlayerPriority) &&
         ((int)(&g_PlayerCreatureCount)[player] < (&g_PlayerCreatureCount)[1 - player] + 8)) {
        g_CardEventResult = g_CardEventResult | 2;
      }
      else {
        g_CardEventResult = g_CardEventResult | 1;
      }
    }
    if (arg_3 == 0x7e) {
      Ai_CalcManaRequirement_004ba890(player,0,1);
      if (g_ActivePlayer == 1) {
        g_ActivePlayer = -1;
      }
      else {
        (&g_PlayerCreatureCount)[player] = (&g_PlayerCreatureCount)[player] + 1;
        *(int *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) =
             *(int *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) + -1;
      }
    }
    if ((&g_CardSlot_ConvertedManaCost)[card_slot * 0x120 + player * 0x5b20] != '\0') {
      *(uint32_t *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) & 0xfffffeff;
    }
  }
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_004603b5
 * Entry Point: 004603b5
 * Size: 301 bytes
 */


int32_t Minit_Subsystem_004603b5(int player_id,int card_slot,int event_type)

{
  int val_1;
  
  if (((arg_3 == 0x6c) && (g_EventSourceSlot == card_slot)) && (g_EventSourcePlayer == player)) {
    g_SpellStackDepth =
         g_SpellStackDepth +
         (((&g_PlayerCreatureCount)[g_CurrentTurnPhase] + 4) -
         (&g_PlayerCreatureCount)[g_ActivePlayerPriority]) *
         *(int *)(&g_PlayerManaPoolDelta + g_ActivePlayerPriority * 0x20) * 6;
  }
  if (((arg_3 == 0x77) && (g_EventSourcePlayer == player)) &&
     (((&g_MasterCardColorTable)
       [*(int *)(&g_CardSlot_CardId + g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20)
        * 0x34] & 0x40) != 0)) {
    val_1 = Font_DrawString(player,7,1);
    if ((val_1 != 0) && (((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) == 0)) {
      Ai_CalcManaRequirement_004ba890(player,0,1);
      if (g_ActivePlayer != 1) {
        (&g_PlayerCreatureCount)[player] = (&g_PlayerCreatureCount)[player] + 1;
      }
    }
  }
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_004604e2
 * Entry Point: 004604e2
 * Size: 258 bytes
 */


int32_t Minit_Subsystem_004604e2(int player_id,int card_slot,int event_type)

{
  int val_1;
  
  if (((arg_3 == 0x6c) && (card_slot == g_EventSourceSlot)) && (player == g_EventSourcePlayer)) {
    g_SpellStackDepth = g_SpellStackDepth + (6 - (&g_ActivePlayerSpellPriority)[player]) * 0xc;
  }
  if ((arg_3 == 0x77) &&
     (((&g_MasterCardColorTable)
       [*(int *)(&g_CardSlot_CardId + g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20)
        * 0x34] & 0x40) != 0)) {
    val_1 = Font_DrawString(player,7,3);
    if ((val_1 != 0) && (((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) == 0)) {
      Ai_CalcManaRequirement_004ba890(player,0,3);
      if (g_ActivePlayer != 1) {
        Magic_ExecuteDrawPhase(player);
      }
    }
  }
  return 0;
}



/*
 * Decompiled function: CardScript_EbonyHorse
 * Entry Point: 004605e4
 * Size: 1086 bytes
 */


int32_t CardScript_EbonyHorse(int spell_id,int target_id,int flags)

{
  int val_1;
  int32_t uval_2;
  uint32_t uval_3;
  uint32_t uval_4;
  uint32_t uval_5;
  int32_t arg_11;
  int val_6;
  int32_t arg_12;
  uint32_t uval_7;
  int32_t arg_13;
  uint32_t uval_8;
  int32_t arg_14;
  uint32_t uVar9;
  int32_t arg_15;
  uint32_t uVar10;
  int32_t arg_16;
  uint32_t uVar11;
  int32_t arg_17;
  uint8_t *arg_18;
  int32_t arg_18_00;
  int32_t arg_19;
  int *arg_20;
  int match_count;
  int slot_idx;
  
  if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
     (g_EventSourcePlayer == spell_id)) {
    g_SpellStackDepth =
         g_SpellStackDepth + *(int *)(&DAT_006b2e5c + g_ActivePlayerPriority * 0x20) * 3;
  }
  if (flags == 0x73) {
    if ((((((&g_CardSlot_Subtypes)[target_id * 0x120 + spell_id * 0x5b20] & 3) == 0) ||
         (((&g_MasterCardColorTable)
           [*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) * 0x34] & 2) == 0))
        && (((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0)) &&
       (val_1 = Font_DrawString(spell_id,7,2), val_1 != 0)) {
      arg_19 = 0;
      arg_18_00 = 2;
      arg_17 = 0;
      arg_16 = 0xffffffff;
      arg_15 = 0xffffffff;
      arg_14 = 0xffffffff;
      arg_13 = 0xffffffff;
      arg_12 = 0;
      arg_11 = 0;
      uval_2 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_1 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,spell_id,spell_id,0x200,2,0,0,uval_2,arg_11,arg_12,
                           arg_13,arg_14,arg_15,arg_16,arg_17,arg_18_00,arg_19);
      if (val_1 != 0) {
        return 1;
      }
    }
  }
  else if (flags == 0x90) {
    Ai_PeekPlannedSlot(0);
  }
  else {
    if ((((flags == 0x6d) &&
         (((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0)) &&
        ((val_1 = Font_DrawString(spell_id,7,2), val_1 != 0 &&
         ((g_TurnPlayer == spell_id && (g_ActiveBattlefieldFlag != 0)))))) &&
       (Ai_CalcManaRequirement_004ba890(spell_id,0,2), g_ActivePlayer != 1)) {
      Pic_Subsystem_00424500(s_prompts_txt_00524594,s_EBONYHORSE_00524588);
      arg_20 = &match_count;
      uval_2 = 1;
      arg_18 = &g_OverworldGoldAmount;
      uVar11 = 0;
      uVar10 = 2;
      uVar9 = 0;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      val_6 = -1;
      val_1 = -1;
      uval_5 = 0;
      uval_4 = 0;
      uval_3 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_1 = Duel_ChooseTarget
                        (spell_id,spell_id,spell_id,0x200,2,0,0,uval_3,uval_4,uval_5,val_1,val_6,uval_7,
                         uval_8,uVar9,uVar10,uVar11,arg_18,uval_2,arg_20);
      if (val_1 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = match_count;
        *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = slot_idx;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        *(uint32_t *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
      }
    }
    if (flags == 0x72) {
      match_count = *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
      slot_idx = *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
       *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20] = 0;
      uVar11 = 0;
      uVar10 = 2;
      uVar9 = 0;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      val_6 = -1;
      val_1 = -1;
      uval_5 = 0;
      uval_4 = 0;
      uval_3 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_1 = Rules_ParseFilter_0040360b
                        (match_count,slot_idx,(char *)0x0,spell_id,(uint8_t)spell_id,(uint8_t)spell_id,0x200,2,
                         0,0,uval_3,uval_4,uval_5,val_1,val_6,uval_7,uval_8,uVar9,uVar10,uVar11);
      if (val_1 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(uint32_t *)(&g_CardSlot_Flags + match_count * 0x5b20 + slot_idx * 0x120) =
             *(uint32_t *)(&g_CardSlot_Flags + match_count * 0x5b20 + slot_idx * 0x120) & 0xffffffef;
        Card_ApplyTriggerEffect(g_DialogPromptHwnd,g_DuelArenaHwnd,DAT_00695f14,match_count,slot_idx);
      }
    }
  }
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_00460a22
 * Entry Point: 00460a22
 * Size: 472 bytes
 */


int32_t Minit_Subsystem_00460a22(int player_id,int card_slot,int event_type)

{
  int val_1;
  int32_t uval_2;
  
  if ((((arg_3 == 0x6c) && (g_EventSourceSlot == card_slot)) && (g_EventSourcePlayer == player)) &&
     (((g_ActivePlayerPriority == player &&
       (val_1 = FUN_004fa4b8(player,*(int *)(&g_CardSlot_CardId + card_slot * 0x120 + player * 0x5b20),
                             player), val_1 != 0)) &&
      (3 < *(int *)(&g_PlayerManaPoolDelta + g_ActivePlayerPriority * 0x20) / val_1)))) {
    g_SpellStackDepth = g_SpellStackDepth + 0x30;
  }
  if (arg_3 == 0x73) {
    val_1 = Font_DrawString(player,7,4);
    if ((val_1 == 0) ||
       (((((&g_CardSlot_Subtypes)[card_slot * 0x120 + player * 0x5b20] & 3) != 0 &&
         (((&g_MasterCardColorTable)
           [*(int *)(&g_CardSlot_CardId + card_slot * 0x120 + player * 0x5b20) * 0x34] & 2) != 0)) ||
        (((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) != 0)))) {
      uval_2 = 0;
    }
    else {
      uval_2 = 1;
    }
  }
  else {
    if (((arg_3 == 0x6d) && (val_1 = Font_DrawString(player,7,4), val_1 != 0)) &&
       (Ai_CalcManaRequirement_004ba890(player,0,4), g_ActivePlayer != 1)) {
      *(uint32_t *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) | 0x10;
    }
    if (arg_3 == 0x72) {
      Magic_ExecuteDrawPhase(player);
    }
    uval_2 = 0;
  }
  return uval_2;
}



/*
 * Decompiled function: Minit_Subsystem_00460bfa
 * Entry Point: 00460bfa
 * Size: 1095 bytes
 */


int32_t Minit_Subsystem_00460bfa(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  
  if (((arg_3 == 0x82) && (card_slot == g_EventSourceSlot)) && (player == g_EventSourcePlayer)) {
    *(uint32_t *)(&g_CardSlot_ProtectionFlags + player * 0x5b20 + card_slot * 0x120) =
         *(uint32_t *)(&g_CardSlot_ProtectionFlags + player * 0x5b20 + card_slot * 0x120) & 0xfffffffc;
  }
  if ((((arg_3 == 0x84) && (card_slot == g_EventSourceSlot)) &&
      ((player == g_EventSourcePlayer &&
       ((((&g_CardSlot_Flags)[player * 0x5b20 + card_slot * 0x120] & 0x10) != 0 &&
        (player == g_TurnPlayer)))))) && (player == g_CurrentTurnTargetPlayer)) {
    *(uint32_t *)(&g_CardSlot_SpecialState + player * 0x5b20 + card_slot * 0x120) =
         *(uint32_t *)(&g_CardSlot_SpecialState + player * 0x5b20 + card_slot * 0x120) | 0x10;
    (&DAT_006a603c)[player * 0x5b20 + card_slot * 0x120] =
         (&DAT_006a603c)[player * 0x5b20 + card_slot * 0x120] + '\x04';
  }
  if (((arg_3 == 1) && (card_slot == g_EventSourceSlot)) && (player == g_EventSourcePlayer)) {
    *(int32_t *)(&g_CardSlot_ConvertedManaCost + player * 0x5b20 + card_slot * 0x120) = 1;
  }
  if (((arg_3 == 0x6c) && (card_slot == g_EventSourceSlot)) && (player == g_EventSourcePlayer)) {
    g_SpellStackDepth = g_SpellStackDepth + 0xc;
  }
  if (arg_3 == 0x73) {
    if (((((&g_CardSlot_Subtypes)[player * 0x5b20 + card_slot * 0x120] & 3) == 0) ||
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId + player * 0x5b20 + card_slot * 0x120) * 0x34] & 2) == 0)) &&
       (((&g_CardSlot_Flags)[player * 0x5b20 + card_slot * 0x120] & 0x10) == 0)) {
      uval_1 = 1;
    }
    else {
      uval_1 = 0;
    }
  }
  else {
    if (arg_3 == 0x6d) {
      FUN_0040d901(player,0,3);
      *(uint32_t *)(&g_CardSlot_Flags + player * 0x5b20 + card_slot * 0x120) =
           *(uint32_t *)(&g_CardSlot_Flags + player * 0x5b20 + card_slot * 0x120) | 0x10;
      g_PendingAttackersTargetSlot = 0;
    }
    if (((g_CurrentStepCode == 0xcb) || (arg_3 == 199)) &&
       ((card_slot == g_EventSourceSlot &&
        ((((player == g_EventSourcePlayer && (player == g_TurnPlayer)) &&
          (player == g_CurrentCardColorTarget)) &&
         ((((&g_CardSlot_Flags)[player * 0x5b20 + card_slot * 0x120] & 0x10) != 0 &&
          (*(int *)(&g_CardSlot_ConvertedManaCost + player * 0x5b20 + card_slot * 0x120) == 0)))))))) {
      if (arg_3 == 0x7d) {
        g_CardEventResult = g_CardEventResult | 2;
      }
      if ((arg_3 == 0x7e) || (arg_3 == 199)) {
        Mem_AllocOrFree_0041df33(player,1,player,card_slot);
        *(int32_t *)(&g_CardSlot_ConvertedManaCost + player * 0x5b20 + card_slot * 0x120) = 0;
      }
    }
    if (((arg_3 == 199) && (*(int *)(&g_PlayerManaPoolDelta + player * 0x20) < 4)) &&
       (((&g_CardSlot_Flags)[player * 0x5b20 + card_slot * 0x120] & 0x10) != 0)) {
      (&g_PlayerCreatureCount)[player] =
           (&g_PlayerCreatureCount)[player] - (4 - *(int *)(&g_PlayerManaPoolDelta + player * 0x20));
    }
    if (((arg_3 == 0x7f) && (card_slot == g_EventSourceSlot)) &&
       ((player == g_EventSourcePlayer &&
        (((&g_CardSlot_Flags)[player * 0x5b20 + card_slot * 0x120] & 0x10) == 0)))) {
      FUN_0040d7e9(player,0,3);
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: Minit_Subsystem_00461041
 * Entry Point: 00461041
 * Size: 435 bytes
 */


int32_t Minit_Subsystem_00461041(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  int val_2;
  
  if (((arg_3 == 0x6c) && (g_EventSourceSlot == card_slot)) && (g_EventSourcePlayer == player)) {
    g_SpellStackDepth =
         g_SpellStackDepth + *(int *)(&g_PlayerManaPoolDelta + g_ActivePlayerPriority * 0x20) * 2;
  }
  if (arg_3 == 0x73) {
    if (((((&g_CardSlot_Subtypes)[card_slot * 0x120 + player * 0x5b20] & 3) == 0) ||
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId + card_slot * 0x120 + player * 0x5b20) * 0x34] & 2) == 0)) &&
       (((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) == 0)) {
      uval_1 = 1;
    }
    else {
      uval_1 = 0;
    }
  }
  else {
    if (arg_3 == 0x6d) {
      *(uint32_t *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) | 0x10;
    }
    if (arg_3 == 0x72) {
      FUN_0040d875(player,0,2);
    }
    if (((arg_3 == 2) && (g_EventSourceSlot == card_slot)) && (g_EventSourcePlayer == player)) {
      g_CardEventResult = g_CardEventResult | 2;
    }
    if (((arg_3 == 4) && (g_EventSourceSlot == card_slot)) &&
       ((g_EventSourcePlayer == player && (val_2 = Util_GetRandomNumber(2), val_2 != 0)))) {
      Mem_AllocOrFree_0041df33(player,3,player,card_slot);
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: Minit_Subsystem_004611f4
 * Entry Point: 004611f4
 * Size: 412 bytes
 */


int32_t Minit_Subsystem_004611f4(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  
  if (((arg_3 == 0x6c) && (card_slot == g_EventSourceSlot)) && (player == g_EventSourcePlayer)) {
    g_SpellStackDepth =
         g_SpellStackDepth +
         (int)(0xc0 / (longlong)(*(int *)(&g_PlayerManaPoolDelta + g_ActivePlayerPriority * 0x20) + 1));
  }
  if (arg_3 == 0x73) {
    if (((((&g_CardSlot_Subtypes)[card_slot * 0x120 + player * 0x5b20] & 3) == 0) ||
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId + card_slot * 0x120 + player * 0x5b20) * 0x34] & 2) == 0)) &&
       (((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) == 0)) {
      uval_1 = 1;
    }
    else {
      uval_1 = 0;
    }
  }
  else {
    if (arg_3 == 0x6d) {
      g_SpellStackDepth = g_SpellStackDepth + -0xc;
      FUN_0040d901(player,0,2);
      *(uint32_t *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) | 0x10;
      g_PendingAttackersTargetSlot = 0;
    }
    if (((arg_3 == 0x7f) && (card_slot == g_EventSourceSlot)) &&
       ((player == g_EventSourcePlayer &&
        (((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) == 0)))) {
      FUN_0040d7e9(player,0,2);
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: Minit_Subsystem_00461390
 * Entry Point: 00461390
 * Size: 1053 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int32_t Minit_Subsystem_00461390(int player_id,int card_slot,int event_type)

{
  int val_1;
  int val_2;
  int match_count;
  int slot_idx;
  
  if ((((arg_3 == 0x6c) && (g_EventSourceSlot == card_slot)) && (g_EventSourcePlayer == player)) &&
     (val_1 = FUN_004fa4b8(player,*(int *)(&g_CardSlot_CardId + card_slot * 0x120 + player * 0x5b20),-1),
     val_1 != 0)) {
    g_SpellStackDepth = g_SpellStackDepth + -0xf0;
  }
  if (((arg_3 == 0x82) &&
      (val_1 = Magic_QueryCardAttribute(g_EventSourcePlayer,g_EventSourceSlot,0x32,0xffffffff), 2 < val_1))
     && ((((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) == 0 &&
         (((&g_MasterCardColorTable)
           [*(int *)(&g_CardSlot_CardId + card_slot * 0x120 + player * 0x5b20) * 0x34] & 2) == 0)))) {
    *(uint32_t *)(&g_CardSlot_ProtectionFlags + g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20) =
         *(uint32_t *)(&g_CardSlot_ProtectionFlags + g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20) &
         0xfffffffd;
    _DAT_006ff198 = _DAT_006ff198 | 1;
  }
  if (arg_3 == 199) {
    val_1 = (&g_PlayerActiveCardCount)[g_ActivePlayerPriority];
    if ((int)(&g_PlayerActiveCardCount)[g_ActivePlayerPriority] <=
        (int)(&g_PlayerActiveCardCount)[g_CurrentTurnPhase]) {
      val_1 = (&g_PlayerActiveCardCount)[g_CurrentTurnPhase];
    }
    match_count = 0;
    for (slot_idx = 0; slot_idx < val_1; slot_idx = slot_idx + 1) {
      if (((*(int *)(&g_CardSlot_CardId + slot_idx * 0x120 + g_CurrentTurnPhase * 0x5b20) != -1) &&
          (((&g_CardSlot_Flags)[slot_idx * 0x120 + g_CurrentTurnPhase * 0x5b20] & 2) != 0)) &&
         (2 < *(short *)(&g_CardSlot_Counters + slot_idx * 0x120 + g_CurrentTurnPhase * 0x5b20))) {
        if (((&g_CardSlot_Flags)[slot_idx * 0x120 + g_CurrentTurnPhase * 0x5b20] & 0x10) == 0) {
          val_2 = Rules_ValidateCardTargetSlot(g_CurrentTurnPhase,slot_idx);
          if (val_2 == 0) {
            match_count = match_count + *(short *)(&g_CardSlot_Counters +
                                          slot_idx * 0x120 + g_CurrentTurnPhase * 0x5b20);
          }
        }
        else if ((&DAT_006a603c)[slot_idx * 0x120 + g_CurrentTurnPhase * 0x5b20] == '\0') {
          match_count = match_count + *(short *)(&g_CardSlot_Counters +
                                        slot_idx * 0x120 + g_CurrentTurnPhase * 0x5b20) * 2;
        }
      }
      if (((*(int *)(&g_CardSlot_CardId + slot_idx * 0x120 + g_ActivePlayerPriority * 0x5b20) != -1)
          && (((&g_CardSlot_Flags)[slot_idx * 0x120 + g_ActivePlayerPriority * 0x5b20] & 2) != 0)) &&
         (2 < *(short *)(&g_CardSlot_Counters + slot_idx * 0x120 + g_ActivePlayerPriority * 0x5b20)))
      {
        if (((&g_CardSlot_Flags)[slot_idx * 0x120 + g_ActivePlayerPriority * 0x5b20] & 0x10) == 0) {
          val_2 = Rules_ValidateCardTargetSlot(g_ActivePlayerPriority,slot_idx);
          if (val_2 == 0) {
            match_count = match_count - *(short *)(&g_CardSlot_Counters +
                                          slot_idx * 0x120 + g_ActivePlayerPriority * 0x5b20);
          }
        }
        else if ((&DAT_006a603c)[slot_idx * 0x120 + g_ActivePlayerPriority * 0x5b20] == '\0') {
          match_count = match_count + *(short *)(&g_CardSlot_Counters +
                                        slot_idx * 0x120 + g_ActivePlayerPriority * 0x5b20) * -2;
        }
      }
    }
    g_SpellStackDepth = g_SpellStackDepth + match_count * 0xc;
  }
  return 0;
}



/*
 * Decompiled function: CardScript_JandorsSaddlebags
 * Entry Point: 004617ad
 * Size: 1012 bytes
 */


int32_t CardScript_JandorsSaddlebags(int spell_id,int target_id,int flags)

{
  int val_1;
  int32_t uval_2;
  uint32_t uval_3;
  uint32_t uval_4;
  uint32_t uval_5;
  int32_t arg_11;
  int val_6;
  int32_t arg_12;
  uint32_t uval_7;
  int32_t arg_13;
  uint32_t uval_8;
  int32_t arg_14;
  uint32_t uVar9;
  int32_t arg_15;
  uint32_t uVar10;
  int32_t arg_16;
  uint32_t uVar11;
  int32_t arg_17;
  uint8_t *arg_18;
  int32_t arg_18_00;
  int32_t arg_19;
  int *arg_20;
  int match_count;
  int slot_idx;
  
  if (((flags == 0x6c) && (target_id == g_EventSourceSlot)) &&
     (spell_id == g_EventSourcePlayer)) {
    g_SpellStackDepth =
         g_SpellStackDepth + *(int *)(&DAT_006b2e5c + g_ActivePlayerPriority * 0x20) * 3;
  }
  if (flags == 0x73) {
    if (((((&g_CardSlot_Subtypes)[target_id * 0x120 + spell_id * 0x5b20] & 3) == 0) ||
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) * 0x34] & 2) == 0))
       && ((((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0 &&
           (val_1 = Font_DrawString(spell_id,7,3), val_1 != 0)))) {
      arg_19 = 0;
      arg_18_00 = 0;
      arg_17 = 0;
      arg_16 = 0xffffffff;
      arg_15 = 0xffffffff;
      arg_14 = 0xffffffff;
      arg_13 = 0xffffffff;
      arg_12 = 0;
      arg_11 = 0;
      uval_2 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_1 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uval_2,arg_11,arg_12,arg_13,arg_14,
                           arg_15,arg_16,arg_17,arg_18_00,arg_19);
      if (val_1 != 0) {
        return 1;
      }
    }
  }
  else if (flags == 0x90) {
    Ai_PeekPlannedSlot(0);
  }
  else {
    if (((flags == 0x6d) &&
        (((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0)) &&
       ((val_1 = Font_DrawString(spell_id,7,3), val_1 != 0 &&
        (Ai_CalcManaRequirement_004ba890(spell_id,0,3), g_ActivePlayer != 1)))) {
      Pic_Subsystem_00424500(s_prompts_txt_005245b4,s_JANDORS_SADDLEBAGS_005245a0);
      arg_20 = &match_count;
      uval_2 = 1;
      arg_18 = &g_OverworldGoldAmount;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      val_6 = -1;
      val_1 = -1;
      uval_5 = 0;
      uval_4 = 0;
      uval_3 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_1 = Duel_ChooseTarget
                        (spell_id,2,spell_id,0x200,2,0,0,uval_3,uval_4,uval_5,val_1,val_6,uval_7,uval_8,
                         uVar9,uVar10,uVar11,arg_18,uval_2,arg_20);
      if (val_1 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = match_count;
        *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = slot_idx;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        *(uint32_t *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
      }
    }
    if (flags == 0x72) {
      match_count = *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
      slot_idx = *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
       *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20] = 0;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      val_6 = -1;
      val_1 = -1;
      uval_5 = 0;
      uval_4 = 0;
      uval_3 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_1 = Rules_ParseFilter_0040360b
                        (match_count,slot_idx,(char *)0x0,spell_id,2,2,0x200,2,0,0,uval_3,uval_4,uval_5,
                         val_1,val_6,uval_7,uval_8,uVar9,uVar10,uVar11);
      if (val_1 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(uint32_t *)(&g_CardSlot_Flags + match_count * 0x5b20 + slot_idx * 0x120) =
             *(uint32_t *)(&g_CardSlot_Flags + match_count * 0x5b20 + slot_idx * 0x120) & 0xffffffef;
      }
    }
  }
  return 0;
}



/*
 * Decompiled function: CardScript_JadeMonolith
 * Entry Point: 00461ba1
 * Size: 920 bytes
 */


int32_t CardScript_JadeMonolith(int spell_id,int target_id,int flags)

{
  int val_1;
  int match_count;
  int slot_idx;
  
  if (((flags == 0x6c) && (target_id == g_EventSourceSlot)) &&
     (spell_id == g_EventSourcePlayer)) {
    g_SpellStackDepth =
         g_SpellStackDepth +
         ((&g_PlayerCreatureCount)[g_ActivePlayerPriority] -
         (&g_PlayerCreatureCount)[g_CurrentTurnPhase]) * 0xc;
  }
  if (flags == 0x73) {
    if (((((uint8_t)g_DuelModeFlags & 4) != 0) &&
        (val_1 = Font_DrawString(spell_id, 7, 1), val_1 != 0)) &&
       (((((&g_CardSlot_Subtypes)[target_id * 0x120 + spell_id * 0x5b20] & 3) == 0 ||
         (((&g_MasterCardColorTable)
           [*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) * 0x34] & 2) == 0))
        && ((((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0 &&
            (val_1 = UI_PaintBigCardInfo((int *)0x0,1,spell_id,2,2,0x200,2,0,0,0,0,0,0xffffffff,0xffffffff,
                                  0xffffffff,0xffffffff,0,0,0), val_1 != 0)))))) {
      return 99;
    }
  }
  else if (flags == 0x90) {
    Ai_PeekPlannedSlot(0);
  }
  else {
    if (((flags == 0x6d) && (val_1 = Font_DrawString(spell_id, 7, 1), val_1 != 0)) &&
       (Ai_CalcManaRequirement_004ba890(spell_id,0,1), g_ActivePlayer != 1)) {
      Pic_Subsystem_00424500(s_prompts_txt_005245d0,s_JADE_MONOLITH_005245c0);
      val_1 = Duel_ChooseTarget
                        (spell_id,2,spell_id,0x200,2,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0,0x200,0
                         ,&g_OverworldGoldAmount,1,&match_count);
      if (val_1 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = match_count;
        *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = slot_idx;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
      }
    }
    if (flags == 0x72) {
      match_count = *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
      slot_idx = *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
       *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20] = 0;
      val_1 = Rules_ParseFilter_0040360b
                        (match_count,slot_idx,(char *)0x0,spell_id,2,2,0x200,2,0,0,0,0,0,-1,-1,0xffffffff
                         ,0xffffffff,0,0x200,0);
      if (val_1 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        Minit_Subsystem_00461f3e(match_count,slot_idx,spell_id);
      }
    }
  }
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_00461f3e
 * Entry Point: 00461f3e
 * Size: 389 bytes
 */


void Minit_Subsystem_00461f3e(int player_id,int card_slot,int event_type)

{
  int match_count;
  int slot_idx;
  
  for (slot_idx = 0; slot_idx < 2; slot_idx = slot_idx + 1) {
    for (match_count = 0; match_count < (int)(&g_PlayerActiveCardCount)[slot_idx]; match_count = match_count + 1) {
      if ((((*(int *)(&g_CardSlot_CardId + match_count * 0x120 + slot_idx * 0x5b20) == g_PendingSpellTargetSlot) &&
           (((&g_CardSlot_Flags)[match_count * 0x120 + slot_idx * 0x5b20] & 2) != 0)) &&
          ((char)(&g_CardSlot_Toughness)[match_count * 0x120 + slot_idx * 0x5b20] == player)) &&
         (*(int *)(&g_CardSlot_OriginalCardId + match_count * 0x120 + slot_idx * 0x5b20) == card_slot)) {
        *(int32_t *)(&g_CardSlot_CardId + match_count * 0x120 + slot_idx * 0x5b20) = 0xffffffff;
        Mem_AllocOrFree_0041df33
                  (arg_3,*(int *)(&g_CardSlot_ConvertedManaCost + match_count * 0x120 + slot_idx * 0x5b20
                                 ),
                   (int)(char)(&g_CardSlot_DamageReceived)[match_count * 0x120 + slot_idx * 0x5b20],
                   *(int *)(&g_CardSlot_TypeFlags + match_count * 0x120 + slot_idx * 0x5b20));
      }
    }
  }
  return;
}



/*
 * Decompiled function: Minit_Subsystem_004620c3
 * Entry Point: 004620c3
 * Size: 460 bytes
 */


int32_t Minit_Subsystem_004620c3(int player_id,int card_slot,int event_type)

{
  int val_1;
  
  if (((arg_3 == 0x6c) && (card_slot == g_EventSourceSlot)) && (player == g_EventSourcePlayer)) {
    val_1 = Math_Clamp((&g_PlayerCreatureCount)[g_ActivePlayerPriority],1,99);
    g_SpellStackDepth = g_SpellStackDepth + (int)(0x30 / (longlong)val_1);
  }
  if (((arg_3 == 0x77) && (card_slot == g_EventSourceSlot)) &&
     ((player == g_EventSourcePlayer &&
      ((((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x20) == 0 &&
       ((&g_CardSlot_CardTypeIndex)[card_slot * 0x120 + player * 0x5b20] != '\x04')))))) {
    val_1 = Deck_AddCardToDeck(player,DAT_006ff564);
    if (val_1 != -1) {
      *(int32_t *)(&g_ActiveCardsInPlay + val_1 * 0x120 + player * 0x5b20) =
           *(int32_t *)(&g_CardSlot_CardId + card_slot * 0x120 + player * 0x5b20);
      *(uint32_t *)(&g_CardSlot_Flags + val_1 * 0x120 + player * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_Flags + val_1 * 0x120 + player * 0x5b20) | 2;
      *(int32_t *)(&DAT_006a5f74 + val_1 * 0x120 + player * 0x5b20) = 0x200;
      *(int32_t *)(&DAT_006a5f80 + val_1 * 0x120 + player * 0x5b20) = 0xd5;
      (&g_CardSlot_CardTypeIndex)[val_1 * 0x120 + player * 0x5b20] = 2;
      FUN_00476482(player,val_1);
    }
  }
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_0046228f
 * Entry Point: 0046228f
 * Size: 74 bytes
 */


int32_t Minit_Subsystem_0046228f(int player_id,int card_slot,int event_type)

{
  if (((arg_3 == 0x77) && (g_EventSourceSlot == card_slot)) && (g_EventSourcePlayer == player)) {
    FUN_0040d875(player,0,4);
  }
  return 0;
}



/*
 * Decompiled function: CardScript_AmuletOfKroog
 * Entry Point: 004622d9
 * Size: 1012 bytes
 */


int32_t CardScript_AmuletOfKroog(int spell_id,int target_id,int flags)

{
  int val_1;
  int32_t uval_2;
  int match_count;
  int slot_idx;
  
  if (flags == 0x73) {
    if (((((uint8_t)g_DuelModeFlags & 4) == 0) ||
        (val_1 = Font_DrawString(spell_id,7,2), val_1 == 0)) ||
       (((((&g_CardSlot_Subtypes)[target_id * 0x120 + spell_id * 0x5b20] & 3) != 0 &&
         (((&g_MasterCardColorTable)
           [*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) * 0x34] & 2) != 0))
        || ((((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) != 0 ||
            (val_1 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,0,0,0,0,0,0,g_PendingSpellTargetSlot,
                                  0xffffffff,0xffffffff,0xffffffff,0,0,0), val_1 == 0)))))) {
      uval_2 = 0;
    }
    else {
      uval_2 = 99;
    }
  }
  else if (flags == 0x90) {
    Ai_PeekPlannedSlot(0);
    uval_2 = 0;
  }
  else {
    if (((flags == 0x6d) && (val_1 = Font_DrawString(spell_id,7,2), val_1 != 0)) &&
       (Ai_CalcManaRequirement_004ba890(spell_id,0,2), g_ActivePlayer != 1)) {
      Pic_Subsystem_00424500(s_prompts_txt_005245ec,s_AMULET_KROOG_005245dc);
      val_1 = Duel_ChooseTarget
                        (spell_id,2,spell_id,0x200,0,0,0,0,0,0,g_PendingSpellTargetSlot,-1,0xffffffff,0xffffffff
                         ,0,0,0,&g_OverworldGoldAmount,1,&match_count);
      if (val_1 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = match_count;
        *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = slot_idx;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        *(uint32_t *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
      }
    }
    if (flags == 0x72) {
      match_count = *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
      slot_idx = *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120] = 0;
      val_1 = Rules_ParseFilter_0040360b
                        (match_count,slot_idx,(char *)0x0,spell_id,2,2,0x200,0,0,0,0,0,0,g_PendingSpellTargetSlot,-1,
                         0xffffffff,0xffffffff,0,0,0);
      if (val_1 == 0) {
        g_ActivePlayer = 1;
      }
      else if (*(int *)(&g_CardSlot_ConvertedManaCost + slot_idx * 0x120 + match_count * 0x5b20) != 0) {
        *(int *)(&g_CardSlot_ConvertedManaCost + match_count * 0x5b20 + slot_idx * 0x120) =
             *(int *)(&g_CardSlot_ConvertedManaCost + match_count * 0x5b20 + slot_idx * 0x120) + -1;
      }
    }
    if (((flags == 0x3b) &&
        (((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0)) &&
       (val_1 = Font_DrawString(spell_id,7,2), val_1 != 0)) {
      *(int *)(&DAT_00695eb8 + spell_id * 4) = *(int *)(&DAT_00695eb8 + spell_id * 4) + 1;
    }
    uval_2 = 0;
  }
  return uval_2;
}



/*
 * Decompiled function: Minit_Subsystem_004626d2
 * Entry Point: 004626d2
 * Size: 824 bytes
 */


int32_t Minit_Subsystem_004626d2(int player_id,int card_slot,int event_type)

{
  int val_1;
  int32_t uval_2;
  int slot_idx;
  
  if (arg_3 == 0x73) {
    if (((((uint8_t)g_DuelModeFlags & 4) == 0) || (val_1 = Font_DrawString(player,7,2), val_1 == 0))
       || (((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) != 0)) {
      uval_2 = 0;
    }
    else {
      uval_2 = 1;
    }
  }
  else if (arg_3 == 0x90) {
    Ai_PeekPlannedSlot(0);
    uval_2 = 0;
  }
  else {
    if ((arg_3 == 0x6d) && (val_1 = Font_DrawString(player,7,2), val_1 != 0)) {
      Ai_CalcManaRequirement_004ba890(player,0,2);
      if ((slot_idx == -1) ||
         (*(int *)(&g_CardSlot_CardId +
                  *(int *)(&g_CardSlot_CombatTarget + card_slot * 0x120 + player * 0x5b20) * 0x5b20 +
                  *(int *)(&g_CardSlot_AttachedAura + card_slot * 0x120 + player * 0x5b20) * 0x120) !=
          g_PendingSpellTargetSlot)) {
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20] = g_TemporaryToughnessBuffer;
        *(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) = slot_idx;
        *(int32_t *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) = 1;
      }
    }
    if ((arg_3 == 0x72) &&
       (*(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) != -1)) {
      if (*(int *)(&g_CardSlot_ConvertedManaCost +
                  *(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) * 0x120 +
                  (char)(&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20] * 0x5b20) != 0) {
        *(int *)(&g_CardSlot_ConvertedManaCost +
                *(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) * 0x120 +
                (char)(&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20] * 0x5b20) =
             *(int *)(&g_CardSlot_ConvertedManaCost +
                     *(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) * 0x120 +
                     (char)(&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20] * 0x5b20) + -1;
      }
      *(int32_t *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) = 0xffffffff;
      (&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20] =
           (&g_CardSlot_OriginalCardId)[card_slot * 0x120 + player * 0x5b20];
    }
    if ((arg_3 == 0x22) &&
       (*(int *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) != 0)) {
      FUN_0041da41(player,card_slot);
    }
    uval_2 = 0;
  }
  return uval_2;
}



/*
 * Decompiled function: CardScript_GrapeshotCatapult
 * Entry Point: 00462a0a
 * Size: 788 bytes
 */


int32_t CardScript_GrapeshotCatapult(int spell_id,int target_id,int flags)

{
  int32_t uval_1;
  int val_2;
  uint32_t uval_3;
  uint32_t uval_4;
  uint32_t uval_5;
  int32_t arg_11;
  int val_6;
  int32_t arg_12;
  uint32_t uval_7;
  int32_t arg_13;
  uint32_t uval_8;
  int32_t arg_14;
  uint32_t uVar9;
  int32_t arg_15;
  uint32_t uVar10;
  int32_t arg_16;
  uint32_t uVar11;
  int32_t arg_17;
  uint8_t *arg_18;
  int32_t arg_18_00;
  int32_t arg_19;
  int *arg_20;
  int match_count;
  int slot_idx;
  
  if (flags == 0x73) {
    if ((*(uint32_t *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) & 0x20010) == 0) {
      arg_19 = 0;
      arg_18_00 = 0;
      arg_17 = 0;
      arg_16 = 0xffffffff;
      arg_15 = 0xffffffff;
      arg_14 = 0xffffffff;
      arg_13 = 0xffffffff;
      arg_12 = 0;
      arg_11 = 0;
      uval_1 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_2 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,2,0,0x20,uval_1,arg_11,arg_12,arg_13,
                           arg_14,arg_15,arg_16,arg_17,arg_18_00,arg_19);
      if (val_2 != 0) {
        return 1;
      }
    }
  }
  else if (flags == 0x90) {
    Ai_PeekPlannedSlot(0);
  }
  else {
    if ((flags == 0x6d) &&
       ((*(uint32_t *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) & 0x20010) == 0)) {
      Pic_Subsystem_00424500(s_prompts_txt_0052460c,s_GRAPESHOT_CATAPULT_005245f8);
      arg_20 = &match_count;
      uval_1 = 1;
      arg_18 = &g_OverworldGoldAmount;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      val_6 = -1;
      val_2 = -1;
      uval_5 = 0;
      uval_4 = 0;
      uval_3 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_2 = Duel_ChooseTarget
                        (spell_id,2,1 - spell_id,0x200,2,0,0x20,uval_3,uval_4,uval_5,val_2,val_6,uval_7,
                         uval_8,uVar9,uVar10,uVar11,arg_18,uval_1,arg_20);
      if (val_2 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = match_count;
        *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = slot_idx;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        *(uint32_t *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
      }
    }
    if (flags == 0x72) {
      match_count = *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
      slot_idx = *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120] = 0;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      val_6 = -1;
      val_2 = -1;
      uval_5 = 0;
      uval_4 = 0;
      uval_3 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_2 = Rules_ParseFilter_0040360b
                        (match_count,slot_idx,(char *)0x0,spell_id,2,2,0x200,2,0,0x20,uval_3,uval_4,uval_5,
                         val_2,val_6,uval_7,uval_8,uVar9,uVar10,uVar11);
      if (val_2 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        Card_ApplyCombatDamage(match_count,slot_idx,1,g_DialogPromptHwnd,g_DuelArenaHwnd);
      }
    }
  }
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_00462d1e
 * Entry Point: 00462d1e
 * Size: 608 bytes
 */


int32_t Minit_Subsystem_00462d1e(int player_id,int card_slot,int event_type)

{
  int val_1;
  int32_t uval_2;
  
  if (((arg_3 == 0x6c) && (g_EventSourceSlot == card_slot)) && (g_EventSourcePlayer == player)) {
    g_SpellStackDepth =
         g_SpellStackDepth +
         (*(int *)(&DAT_0063edec + g_ActivePlayerPriority * 0x20) * 3 + -0xc) * 4;
    *(uint32_t *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) =
         *(uint32_t *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) | 0x10;
  }
  if (arg_3 == 0x73) {
    val_1 = Font_DrawString(player,7,2);
    if ((val_1 == 0) || (((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) != 0)) {
      uval_2 = 0;
    }
    else {
      uval_2 = 1;
    }
  }
  else if (arg_3 == 0x90) {
    Ai_PeekPlannedSlot(1);
    uval_2 = 0;
  }
  else {
    if ((arg_3 == 0x6d) && (val_1 = Font_DrawString(player,7,2), val_1 != 0)) {
      Ai_CalcManaRequirement_004ba890(player,0,2);
      *(int32_t *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) = 1;
      Glue_Subsystem_004df8ba(player,card_slot);
    }
    if ((arg_3 == 0x72) &&
       (*(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) != -1)) {
      Glue_Subsystem_004dfb23(player,card_slot,0x72,1);
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_TapState + card_slot * 0x120 + player * 0x5b20) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + card_slot * 0x120 + player * 0x5b20) * 0x120] = 0;
      *(uint32_t *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) & 0xffffffef;
    }
    if (((arg_3 == 0x22) || (arg_3 == 199)) &&
       (*(int *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) != 0)) {
      Pic_Subsystem_0044867e(player,card_slot,2);
    }
    uval_2 = 0;
  }
  return uval_2;
}



/*
 * Decompiled function: CardScript_BronzeTablet
 * Entry Point: 00462f7e
 * Size: 1952 bytes
 */


int32_t CardScript_BronzeTablet(int spell_id,int target_id,int flags)

{
  int val_1;
  int32_t uval_2;
  uint32_t uval_3;
  uint32_t uval_4;
  uint32_t uval_5;
  int32_t arg_11;
  int val_6;
  int32_t arg_12;
  uint32_t uval_7;
  int32_t arg_13;
  uint32_t uval_8;
  int32_t arg_14;
  uint32_t uVar9;
  int32_t arg_15;
  uint32_t uVar10;
  int32_t arg_16;
  uint32_t uVar11;
  int32_t arg_17;
  uint8_t *arg_18;
  int32_t arg_18_00;
  int32_t arg_19;
  int *arg_20;
  int match_count;
  int slot_idx;
  
  if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
     (g_EventSourcePlayer == spell_id)) {
    *(uint32_t *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) =
         *(uint32_t *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
  }
  if (flags == 0x73) {
    if ((((((&g_CardSlot_Subtypes)[target_id * 0x120 + spell_id * 0x5b20] & 3) == 0) ||
         (((&g_MasterCardColorTable)
           [*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) * 0x34] & 2) == 0))
        && (((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0)) &&
       (val_1 = Font_DrawString(spell_id,7,4), val_1 != 0)) {
      arg_19 = 0;
      arg_18_00 = 0;
      arg_17 = 0;
      arg_16 = 0xffffffff;
      arg_15 = 0xffffffff;
      arg_14 = 0xffffffff;
      arg_13 = 0xffffffff;
      arg_12 = 0;
      arg_11 = 0;
      uval_2 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_1 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,1 - spell_id,1 - spell_id,0x200,0,0,0,uval_2,arg_11,
                           arg_12,arg_13,arg_14,arg_15,arg_16,arg_17,arg_18_00,arg_19);
      if (val_1 != 0) {
        return 1;
      }
    }
  }
  else if (flags == 0x90) {
    Ai_PeekPlannedSlot(0);
  }
  else {
    if (((flags == 0x6d) && (val_1 = Font_DrawString(spell_id,7,4), val_1 != 0)) &&
       (Ai_CalcManaRequirement_004ba890(spell_id,0,4), g_ActivePlayer != 1)) {
      Pic_Subsystem_00424500(s_prompts_txt_00524628,s_BRONZE_TABLET_00524618);
      arg_20 = &match_count;
      uval_2 = 1;
      arg_18 = &g_OverworldGoldAmount;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      val_6 = -1;
      val_1 = -1;
      uval_5 = 0;
      uval_4 = 0;
      uval_3 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_1 = Duel_ChooseTarget
                        (spell_id,1 - spell_id,1 - spell_id,0x200,0x7f,0,0,uval_3,uval_4,uval_5,val_1,
                         val_6,uval_7,uval_8,uVar9,uVar10,uVar11,arg_18,uval_2,arg_20);
      if (val_1 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = match_count;
        *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = slot_idx;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        *(uint32_t *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
      }
    }
    if (flags == 0x72) {
      match_count = *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
      slot_idx = *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      val_6 = -1;
      val_1 = -1;
      uval_5 = 0;
      uval_4 = 0;
      uval_3 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_1 = Rules_ParseFilter_0040360b
                        (match_count,slot_idx,(char *)0x0,spell_id,1 - (char)spell_id,1 - (char)spell_id,
                         0x200,0x7f,0,0,uval_3,uval_4,uval_5,val_1,val_6,uval_7,uval_8,uVar9,uVar10,
                         uVar11);
      if (val_1 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        Pic_Subsystem_0042475a(s_prompts_txt_00524644,s_BRONZE_TABLET_00524634);
        uval_2 = Ai_Subsystem_004cc56d
                          (1 - spell_id,spell_id,target_id,-1,-1,
                           &g_OverworldGoldAmount +
                           ((uint32_t)((int)(&g_PlayerCreatureCount)[1 - spell_id] < 10) * 5 + 5) * 0x32
                           ,0);
        *(int32_t *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
             uval_2;
        val_1 = *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20);
        if (val_1 == 0) {
          if (*(int *)(&g_CardSlot_CardId +
                      *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) *
                      0x120 + *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20)
                              * 0x5b20) != -1) {
            if (g_CurrentTurnPhase == spell_id) {
              Pic_Subsystem_0045200d
                        (*(uint32_t *)(&g_CardSlot_CardId +
                                  *(int *)(&g_CardSlot_SicknessState +
                                          target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
                                  *(int *)(&g_CardSlot_TapState +
                                          target_id * 0x120 + spell_id * 0x5b20) * 0x5b20));
            }
            else {
              Pic_Subsystem_00451e40
                        (*(uint32_t *)(&g_CardSlot_CardId +
                                  *(int *)(&g_CardSlot_SicknessState +
                                          target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
                                  *(int *)(&g_CardSlot_TapState +
                                          target_id * 0x120 + spell_id * 0x5b20) * 0x5b20));
            }
            *(uint32_t *)(&g_CardSlot_Flags +
                     *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) *
                     0x120 + *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20)
                             * 0x5b20) =
                 *(uint32_t *)(&g_CardSlot_Flags +
                          *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20
                                  ) * 0x120 +
                          *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) *
                          0x5b20) ^ 0x1000;
            Pic_Subsystem_0044867e(g_DialogPromptHwnd,g_DuelArenaHwnd,4);
          }
          if (g_CurrentTurnPhase == spell_id) {
            Pic_Subsystem_00451e40
                      (*(uint32_t *)(&g_CardSlot_CardId + match_count * 0x5b20 + slot_idx * 0x120));
          }
          else {
            Pic_Subsystem_0045200d
                      (*(uint32_t *)(&g_CardSlot_CardId + match_count * 0x5b20 + slot_idx * 0x120));
          }
          *(uint32_t *)(&g_CardSlot_Flags + match_count * 0x5b20 + slot_idx * 0x120) =
               *(uint32_t *)(&g_CardSlot_Flags + match_count * 0x5b20 + slot_idx * 0x120) ^ 0x1000;
          Pic_Subsystem_0044867e(match_count,slot_idx,4);
        }
        else if (val_1 == 1) {
          (&g_PlayerCreatureCount)[1 - spell_id] = (&g_PlayerCreatureCount)[1 - spell_id] + -10;
          if (*(int *)(&g_CardSlot_CardId +
                      *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) *
                      0x120 + *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20)
                              * 0x5b20) != -1) {
            Pic_Subsystem_0044867e(g_DialogPromptHwnd,g_DuelArenaHwnd,2);
          }
        }
        else if ((val_1 == 2) &&
                ((&g_PlayerCreatureCount)[1 - spell_id] = 0,
                *(int *)(&g_CardSlot_CardId +
                        *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20)
                        * 0x120 + *(int *)(&g_CardSlot_TapState +
                                          target_id * 0x120 + spell_id * 0x5b20) * 0x5b20) != -1)) {
          Pic_Subsystem_0044867e(g_DialogPromptHwnd,g_DuelArenaHwnd,2);
        }
      }
    }
  }
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_00463723
 * Entry Point: 00463723
 * Size: 1261 bytes
 */


int32_t Minit_Subsystem_00463723(int player_id,int card_slot,int event_type)

{
  int val_1;
  int32_t uval_2;
  int match_count;
  
  if (((arg_3 == 0x6c) && (g_EventSourceSlot == card_slot)) && (g_EventSourcePlayer == player)) {
    val_1 = FUN_004fa4b8(player,*(int *)(&g_CardSlot_CardId + card_slot * 0x120 + player * 0x5b20),-1);
    if (val_1 == 0) {
      g_SpellStackDepth =
           g_SpellStackDepth +
           (*(int *)(&DAT_006b2e5c + (1 - player) * 0x20) - *(int *)(&DAT_006b2e5c + player * 0x20)) *
           0xc;
    }
    *(uint32_t *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) =
         *(uint32_t *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) | 0x10;
  }
  if (arg_3 == 0x73) {
    val_1 = Font_DrawString(player,7,1);
    if ((val_1 == 0) ||
       (((((&g_CardSlot_Subtypes)[card_slot * 0x120 + player * 0x5b20] & 3) != 0 &&
         (((&g_MasterCardColorTable)
           [*(int *)(&g_CardSlot_CardId + card_slot * 0x120 + player * 0x5b20) * 0x34] & 2) != 0)) ||
        (((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) != 0)))) {
      uval_2 = 0;
    }
    else {
      uval_2 = 1;
    }
  }
  else {
    if ((arg_3 == 0x6d) && (val_1 = Font_DrawString(player,7,1), val_1 != 0)) {
      Ai_CalcManaRequirement_004ba890(player,0,1);
      *(uint32_t *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) | 0x10;
    }
    if (arg_3 == 0x72) {
      match_count = 0;
      while( true ) {
        val_1 = (&g_PlayerActiveCardCount)[g_ActivePlayerPriority];
        if ((int)(&g_PlayerActiveCardCount)[g_ActivePlayerPriority] <=
            (int)(&g_PlayerActiveCardCount)[g_CurrentTurnPhase]) {
          val_1 = (&g_PlayerActiveCardCount)[g_CurrentTurnPhase];
        }
        if (val_1 <= match_count) break;
        if (((*(int *)(&g_CardSlot_CardId + match_count * 0x120 + g_CurrentTurnPhase * 0x5b20) != -1) &&
            (((&g_CardSlot_Flags)[match_count * 0x120 + g_CurrentTurnPhase * 0x5b20] & 2) != 0)) &&
           (((&g_MasterCardColorTable)
             [*(int *)(&g_CardSlot_CardId + match_count * 0x120 + g_CurrentTurnPhase * 0x5b20) * 0x34] &
            2) != 0)) {
          Pic_Subsystem_0044867e(g_CurrentTurnPhase,match_count,2);
        }
        if (((*(int *)(&g_CardSlot_CardId + match_count * 0x120 + g_ActivePlayerPriority * 0x5b20) != -1
             ) && (((&g_CardSlot_Flags)[match_count * 0x120 + g_ActivePlayerPriority * 0x5b20] & 2) != 0
                  )) &&
           (((&g_MasterCardColorTable)
             [*(int *)(&g_CardSlot_CardId + match_count * 0x120 + g_ActivePlayerPriority * 0x5b20) *
              0x34] & 2) != 0)) {
          Pic_Subsystem_0044867e(g_ActivePlayerPriority,match_count,2);
        }
        match_count = match_count + 1;
      }
      Rules_SendCardsToGraveyard();
      match_count = 0;
      while( true ) {
        val_1 = (&g_PlayerActiveCardCount)[g_ActivePlayerPriority];
        if ((int)(&g_PlayerActiveCardCount)[g_ActivePlayerPriority] <=
            (int)(&g_PlayerActiveCardCount)[g_CurrentTurnPhase]) {
          val_1 = (&g_PlayerActiveCardCount)[g_CurrentTurnPhase];
        }
        if (val_1 <= match_count) break;
        if (((*(int *)(&g_CardSlot_CardId + match_count * 0x120 + g_CurrentTurnPhase * 0x5b20) != -1) &&
            (((&g_CardSlot_Flags)[match_count * 0x120 + g_CurrentTurnPhase * 0x5b20] & 2) != 0)) &&
           ((((&g_MasterCardColorTable)
              [*(int *)(&g_CardSlot_CardId + match_count * 0x120 + g_CurrentTurnPhase * 0x5b20) * 0x34]
             & 0x44) != 0 &&
            (((&g_MasterCardColorTable)
              [*(int *)(&g_CardSlot_CardId + match_count * 0x120 + g_CurrentTurnPhase * 0x5b20) * 0x34]
             & 2) == 0)))) {
          Pic_Subsystem_0044867e(g_CurrentTurnPhase,match_count,2);
        }
        if ((((*(int *)(&g_CardSlot_CardId + match_count * 0x120 + g_ActivePlayerPriority * 0x5b20) !=
               -1) && (((&g_CardSlot_Flags)[match_count * 0x120 + g_ActivePlayerPriority * 0x5b20] & 2)
                       != 0)) &&
            (((&g_MasterCardColorTable)
              [*(int *)(&g_CardSlot_CardId + match_count * 0x120 + g_ActivePlayerPriority * 0x5b20) *
               0x34] & 0x44) != 0)) &&
           (((&g_MasterCardColorTable)
             [*(int *)(&g_CardSlot_CardId + match_count * 0x120 + g_ActivePlayerPriority * 0x5b20) *
              0x34] & 2) == 0)) {
          Pic_Subsystem_0044867e(g_ActivePlayerPriority,match_count,2);
        }
        match_count = match_count + 1;
      }
    }
    uval_2 = 0;
  }
  return uval_2;
}



/*
 * Decompiled function: Minit_Subsystem_00463c10
 * Entry Point: 00463c10
 * Size: 193 bytes
 */


int32_t Minit_Subsystem_00463c10(int player_id,int card_slot,int event_type)

{
  if ((((&g_CardSlot_Flags)[player * 0x5b20 + card_slot * 0x120] & 2) != 0) &&
     (((&g_MasterCardColorTable)[arg_3 * 0x34] & 2) != 0)) {
    Pic_Subsystem_0044867e(player,card_slot,2);
  }
  Rules_SendCardsToGraveyard();
  if ((((&g_CardSlot_Flags)[player * 0x5b20 + card_slot * 0x120] & 2) != 0) &&
     (((&g_MasterCardColorTable)[arg_3 * 0x34] & 0x44) != 0)) {
    Pic_Subsystem_0044867e(player,card_slot,2);
  }
  return 0;
}



/*
 * Decompiled function: CardScript_AladdinsRing
 * Entry Point: 00463cd1
 * Size: 543 bytes
 */


int32_t CardScript_AladdinsRing(int spell_id,int target_id,int flags)

{
  int val_1;
  int32_t uval_2;
  
  if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
     (g_EventSourcePlayer == spell_id)) {
    g_SpellStackDepth = g_SpellStackDepth + 0x60;
  }
  if (flags == 0x73) {
    val_1 = Font_DrawString(spell_id,7,8);
    if (((val_1 == 0) ||
        ((((&g_CardSlot_Subtypes)[target_id * 0x120 + spell_id * 0x5b20] & 3) != 0 &&
         (((&g_MasterCardColorTable)
           [*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) * 0x34] & 2) != 0))
        )) || (((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) != 0)) {
      uval_2 = 0;
    }
    else {
      uval_2 = 1;
    }
  }
  else if (flags == 0x90) {
    Ai_PeekPlannedSlot(1);
    uval_2 = 0;
  }
  else {
    if (((flags == 0x6d) && (val_1 = Font_DrawString(spell_id,7,8), val_1 != 0)) &&
       (Ai_CalcManaRequirement_004ba890(spell_id,0,8), g_ActivePlayer != 1)) {
      Pic_Subsystem_00424500(s_prompts_txt_00524660,s_ALADDIN_RING_00524650);
      Glue_Subsystem_004df8ba(spell_id,target_id);
      if (g_ActivePlayer != 1) {
        *(uint32_t *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
      }
    }
    if (flags == 0x72) {
      Glue_Subsystem_004dfb23(spell_id,target_id,0x72,4);
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120] = 0;
    }
    uval_2 = 0;
  }
  return uval_2;
}



/*
 * Decompiled function: CardScript_RodOfRuin
 * Entry Point: 00463ef0
 * Size: 538 bytes
 */


int32_t CardScript_RodOfRuin(int spell_id,int target_id,int flags)

{
  int val_1;
  int32_t uval_2;
  
  if (((flags == 0x6c) && (g_EventSourceSlot == target_id)) &&
     (spell_id == g_EventSourcePlayer)) {
    g_SpellStackDepth =
         g_SpellStackDepth + (*(int *)(&DAT_0063edec + g_ActivePlayerPriority * 0x20) * 3 + -6) * 4;
  }
  if (flags == 0x73) {
    val_1 = Font_DrawString(spell_id,7,3);
    if (((val_1 == 0) ||
        ((((&g_CardSlot_Subtypes)[target_id * 0x120 + spell_id * 0x5b20] & 3) != 0 &&
         (((&g_MasterCardColorTable)
           [*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) * 0x34] & 2) != 0))
        )) || (((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) != 0)) {
      uval_2 = 0;
    }
    else {
      uval_2 = 1;
    }
  }
  else if (flags == 0x90) {
    Ai_PeekPlannedSlot(1);
    uval_2 = 0;
  }
  else {
    if ((flags == 0x6d) && (Ai_CalcManaRequirement_004ba890(spell_id,0,3), g_ActivePlayer != 1)) {
      Pic_Subsystem_00424500(s_prompts_txt_00524678,s_ROD_OF_RUIN_0052466c);
      Glue_Subsystem_004df8ba(spell_id,target_id);
      if (g_ActivePlayer != 1) {
        *(uint32_t *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
      }
    }
    if (flags == 0x72) {
      Glue_Subsystem_004dfb23(spell_id,target_id,0x72,1);
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120] = 0;
    }
    uval_2 = 0;
  }
  return uval_2;
}



/*
 * Decompiled function: Minit_Subsystem_0046410a
 * Entry Point: 0046410a
 * Size: 1157 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int32_t Minit_Subsystem_0046410a(int player_id,int card_slot,int event_type)

{
  int val_1;
  int card_idx;
  int match_count;
  int slot_idx;
  
  if ((((arg_3 == 0x6c) && (card_slot == g_EventSourceSlot)) && (player == g_EventSourcePlayer)) &&
     (val_1 = FUN_004fa4b8(player,*(int *)(&g_CardSlot_CardId + card_slot * 0x120 + player * 0x5b20),-1),
     val_1 == 0)) {
    g_SpellStackDepth =
         g_SpellStackDepth +
         (*(int *)(&DAT_006b2e5c + g_ActivePlayerPriority * 0x20) -
         *(int *)(&DAT_006b2e5c + g_CurrentTurnPhase * 0x20)) * 0xc;
  }
  if (((arg_3 == 0x82) &&
      (((&g_MasterCardColorTable)
        [*(int *)(&g_CardSlot_CardId + g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20
                 ) * 0x34] & 1) != 0)) &&
     ((((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) == 0 &&
      (((&g_MasterCardColorTable)
        [*(int *)(&g_CardSlot_CardId + card_slot * 0x120 + player * 0x5b20) * 0x34] & 2) == 0)))) {
    *(uint32_t *)(&g_CardSlot_ProtectionFlags + g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20) =
         *(uint32_t *)(&g_CardSlot_ProtectionFlags + g_EventSourceSlot * 0x120 + g_EventSourcePlayer * 0x5b20) &
         0xfffffffd;
    _DAT_006ff198 = _DAT_006ff198 | 1;
  }
  if (((g_ScWillyScore == 1) && (card_slot == g_EventSourceSlot)) &&
     ((player == g_EventSourcePlayer &&
      ((((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) == 0 &&
       (((&g_MasterCardColorTable)
         [*(int *)(&g_CardSlot_CardId + card_slot * 0x120 + player * 0x5b20) * 0x34] & 2) == 0)))))) {
    if ((arg_3 == 0x7d) &&
       ((val_1 = UI_PaintBigCardInfo((int *)0x0,0,g_TurnPlayer,g_TurnPlayer,g_TurnPlayer,
                              0x200,1,0,0,0,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0x800,
                              0), val_1 == 0 &&
        (val_1 = UI_PaintBigCardInfo((int *)0x0,0,g_TurnPlayer,g_TurnPlayer,g_TurnPlayer,
                              0x200,1,0,0,0,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0x400,
                              0), val_1 != 0)))) {
      g_CardEventResult = g_CardEventResult | 2;
    }
    if (arg_3 == 0x7e) {
      if (g_TurnPlayer == 1) {
        card_idx = g_TurnPlayer;
        match_count = Pic_Subsystem_00441a42(1,1);
        Ai_Subsystem_004cc56d
                  (player,player,card_slot,card_idx,match_count,s_Opponent_chooses_to_untap__00524684,0);
      }
      else {
        Duel_ChooseTarget
                  (g_TurnPlayer,g_TurnPlayer,g_TurnPlayer,0x200,1,0,0,0,0,0,-1,-1,
                   0xffffffff,0xffffffff,0,0x401,0,s_PROCESSING_Winter_Orb__Select_la_005246a0,0,
                   &card_idx);
      }
      *(uint32_t *)(&g_CardSlot_ProtectionFlags + card_idx * 0x5b20 + match_count * 0x120) =
           *(uint32_t *)(&g_CardSlot_ProtectionFlags + card_idx * 0x5b20 + match_count * 0x120) | 2;
      for (slot_idx = 0; slot_idx < (int)(&g_PlayerActiveCardCount)[g_TurnPlayer];
          slot_idx = slot_idx + 1) {
        val_1 = Card_IsInPlay(g_TurnPlayer,slot_idx);
        if ((((val_1 != 0) &&
             (((&g_CardSlot_Flags)[g_TurnPlayer * 0x5b20 + slot_idx * 0x120] & 0x10) != 0)) &&
            (((&g_MasterCardColorTable)
              [*(int *)(&g_CardSlot_CardId + g_TurnPlayer * 0x5b20 + slot_idx * 0x120) * 0x34] &
             1) != 0)) && (((&g_CardSlot_ProtectionFlags)[g_TurnPlayer * 0x5b20 + slot_idx * 0x120] & 2) == 0)
           ) {
          *(uint32_t *)(&g_CardSlot_ProtectionFlags + g_TurnPlayer * 0x5b20 + slot_idx * 0x120) =
               *(uint32_t *)(&g_CardSlot_ProtectionFlags + g_TurnPlayer * 0x5b20 + slot_idx * 0x120) & 0xfffffffe;
        }
      }
    }
  }
  if (arg_3 == 0x22) {
    *(int32_t *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) = 0;
  }
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_0046458f
 * Entry Point: 0046458f
 * Size: 404 bytes
 */


int32_t Minit_Subsystem_0046458f(int player_id,int card_slot,int event_type)

{
  if (((arg_3 == 0x82) && (g_EventSourceSlot == card_slot)) && (g_EventSourcePlayer == player)) {
    *(uint32_t *)(&g_CardSlot_ProtectionFlags + card_slot * 0x120 + player * 0x5b20) =
         *(uint32_t *)(&g_CardSlot_ProtectionFlags + card_slot * 0x120 + player * 0x5b20) & 0xfffffffc;
  }
  if ((((arg_3 == 0x84) && (g_EventSourceSlot == card_slot)) &&
      ((g_EventSourcePlayer == player &&
       ((((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) != 0 &&
        (g_TurnPlayer == player)))))) && (g_CurrentTurnTargetPlayer == player)) {
    *(uint32_t *)(&g_CardSlot_SpecialState + card_slot * 0x120 + player * 0x5b20) =
         *(uint32_t *)(&g_CardSlot_SpecialState + card_slot * 0x120 + player * 0x5b20) | 0x10;
    (&DAT_006a603c)[card_slot * 0x120 + player * 0x5b20] =
         (&DAT_006a603c)[card_slot * 0x120 + player * 0x5b20] + '\x01';
  }
  if (((arg_3 == 0x6c) && (g_EventSourceSlot == card_slot)) && (g_EventSourcePlayer == player)) {
    (&DAT_006a603c)[card_slot * 0x120 + player * 0x5b20] =
         (&DAT_006a603c)[card_slot * 0x120 + player * 0x5b20] + '\x01';
  }
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_00464723
 * Entry Point: 00464723
 * Size: 1029 bytes
 */


int Minit_Subsystem_00464723(int player_id,int card_slot,int event_type)

{
  int val_1;
  
  if (((arg_3 == 0x6c) && (card_slot == g_EventSourceSlot)) && (player == g_EventSourcePlayer)) {
    *(int32_t *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) = 0;
  }
  if (arg_3 == 0x73) {
    val_1 = Font_DrawString(player,7,2);
  }
  else if (arg_3 == 0x90) {
    DAT_0062785c = 2;
    val_1 = 0;
  }
  else {
    if (((arg_3 == 0x6d) && (val_1 = Font_DrawString(player,7,2), val_1 != 0)) &&
       ((Ai_CalcManaRequirement_004ba890(player,0,2), g_ActivePlayer != 1 &&
        (*(int *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) == 0)))) {
      *(uint32_t *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) | 0x80000;
    }
    if (arg_3 == 0x72) {
      if (*(int *)(&g_CardSlot_CardId +
                  *(int *)(&g_CardSlot_SicknessState + card_slot * 0x120 + player * 0x5b20) * 0x120 +
                  *(int *)(&g_CardSlot_TapState + card_slot * 0x120 + player * 0x5b20) * 0x5b20) == -1) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_ConvertedManaCost +
                *(int *)(&g_CardSlot_SicknessState + card_slot * 0x120 + player * 0x5b20) * 0x120 +
                *(int *)(&g_CardSlot_TapState + card_slot * 0x120 + player * 0x5b20) * 0x5b20) =
             *(int *)(&g_CardSlot_ConvertedManaCost +
                     *(int *)(&g_CardSlot_SicknessState + card_slot * 0x120 + player * 0x5b20) * 0x120 +
                     *(int *)(&g_CardSlot_TapState + card_slot * 0x120 + player * 0x5b20) * 0x5b20) + 1;
        if (((&DAT_006a5f56)
             [*(int *)(&g_CardSlot_SicknessState + card_slot * 0x120 + player * 0x5b20) * 0x120 +
              *(int *)(&g_CardSlot_TapState + card_slot * 0x120 + player * 0x5b20) * 0x5b20] & 8) != 0) {
          *(uint32_t *)(&g_CardSlot_ConvertedManaCost +
                   *(int *)(&g_CardSlot_SicknessState + card_slot * 0x120 + player * 0x5b20) * 0x120 +
                   *(int *)(&g_CardSlot_TapState + card_slot * 0x120 + player * 0x5b20) * 0x5b20) =
               *(uint32_t *)(&g_CardSlot_ConvertedManaCost +
                        *(int *)(&g_CardSlot_SicknessState + card_slot * 0x120 + player * 0x5b20) * 0x120
                        + *(int *)(&g_CardSlot_TapState + card_slot * 0x120 + player * 0x5b20) * 0x5b20)
               & 0xfff7ffff;
          val_1 = Card_ApplyTriggerEffect(g_DialogPromptHwnd,g_DuelArenaHwnd,g_PlayerSelectionPriority,g_DialogPromptHwnd,
                               g_DuelArenaHwnd);
          if (val_1 != -1) {
            *(int16_t *)(&g_CardSlot_PowerCounters + val_1 * 0x120 + player * 0x5b20) = 1;
            *(uint32_t *)(&g_CardSlot_ConvertedManaCost + val_1 * 0x120 + player * 0x5b20) =
                 *(uint32_t *)(&g_CardSlot_ConvertedManaCost + val_1 * 0x120 + player * 0x5b20) | 0x80000
            ;
          }
        }
      }
    }
    if (arg_3 == 0x39) {
      val_1 = *(int *)(&DAT_0063edec + player * 0x20) / 2;
    }
    else {
      if ((arg_3 == 0x8f) && (1 < *(int *)(&DAT_0063eeac + player * 0x20))) {
        g_CardEventResult = g_CardEventResult | 1;
      }
      if (arg_3 == 199) {
        if (player == g_ActivePlayerPriority) {
          g_SpellStackDepth =
               g_SpellStackDepth + ((*(int *)(&g_PlayerManaPoolDelta + player * 0x20) / 2) * 3 + 3) * 4;
        }
        else {
          g_SpellStackDepth =
               g_SpellStackDepth + ((*(int *)(&g_PlayerManaPoolDelta + player * 0x20) / 2) * 3 + 3) * -4;
        }
      }
      if ((arg_3 == 0x22) || (arg_3 == 199)) {
        *(int32_t *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) = 0;
      }
      val_1 = 0;
    }
  }
  return val_1;
}



/*
 * Decompiled function: Minit_Subsystem_00464b28
 * Entry Point: 00464b28
 * Size: 38 bytes
 */


void Minit_Subsystem_00464b28(int player_id,int card_slot,int event_type)

{
  Minit_Subsystem_00464b74(player,card_slot,arg_3,7);
  return;
}



/*
 * Decompiled function: Minit_Subsystem_00464b4e
 * Entry Point: 00464b4e
 * Size: 38 bytes
 */


void Minit_Subsystem_00464b4e(int player_id,int card_slot,int event_type)

{
  Minit_Subsystem_00464b74(player,card_slot,arg_3,4);
  return;
}



/*
 * Decompiled function: Minit_Subsystem_00464b74
 * Entry Point: 00464b74
 * Size: 1108 bytes
 */


int32_t Minit_Subsystem_00464b74(int x,int y,int width,int height)

{
  int32_t uval_1;
  int val_2;
  int val_3;
  int32_t uval_4;
  int val_5;
  
  if (((width == 0x6c) && (y == g_EventSourceSlot)) && (x == g_EventSourcePlayer)) {
    Glue_Subsystem_004e6913(x,y,height);
  }
  if ((((g_CurrentStepCode == 0xcc) && (val_2 = Glue_Subsystem_004e6978(x,y), val_2 != 0)) &&
      ((y == g_EventSourceSlot && ((x == g_EventSourcePlayer && (g_CurrentCardColorTarget == x)))))) &&
     ((((&g_CardSlot_Flags)[y * 0x120 + x * 0x5b20] & 4) != 0 ||
      (((&g_CardSlot_ColorMask)[y * 0x120 + x * 0x5b20] != -1 && (x != g_TurnPlayer)))))) {
    if (width == 0x7d) {
      g_CardEventResult = g_CardEventResult | 2;
    }
    if (width == 0x7e) {
      Glue_Subsystem_004e676b(x,y);
    }
  }
  if (((width == 0x32) && (y == g_EventSourceSlot)) && (x == g_EventSourcePlayer)) {
    val_2 = Glue_Subsystem_004e6978(x,y);
    g_CardEventResult = g_CardEventResult + val_2;
  }
  uval_1 = g_OverworldPlayerCoordY;
  if (((width == 0x73) && (g_ScWillyScore == 4)) &&
     ((x == g_TurnPlayer &&
      ((((&g_CardSlot_Flags)[y * 0x120 + x * 0x5b20] & 0x10) == 0 && (g_CurrentTurnTargetPlayer == x)))))) {
    val_2 = Glue_Subsystem_004e6978(x,y);
    if ((val_2 < height) && (val_2 = Font_DrawString(x,7,1), val_2 != 0)) {
      return 1;
    }
  }
  else if (width == 0x90) {
    val_2 = Font_DrawString(x,7,1);
    val_5 = 0;
    val_3 = Glue_Subsystem_004e6978(x,y);
    DAT_0062785c = Math_Clamp(height - val_3,val_5,val_2);
  }
  else {
    if (((width == 0x6d) && (y == g_EventSourceSlot)) && (x == g_EventSourcePlayer)) {
      val_2 = Glue_Subsystem_004e6978(x,y);
      g_OverworldPlayerCoordY = height - val_2;
      if (x == g_CurrentTurnPhase) {
        uval_4 = Ai_CalcManaRequirement_004ba890(x,0,-1);
        *(int32_t *)(&g_CardSlot_ConvertedManaCost + y * 0x120 + x * 0x5b20) = uval_4;
      }
      else {
        val_2 = Font_DrawString(x,7,1);
        val_5 = 0;
        val_3 = Glue_Subsystem_004e6978(x,y);
        val_2 = Math_Clamp(height - val_3,val_5,val_2);
        uval_4 = Ai_CalcManaRequirement_004ba890(x,0,val_2);
        *(int32_t *)(&g_CardSlot_ConvertedManaCost + y * 0x120 + x * 0x5b20) = uval_4;
      }
      g_OverworldPlayerCoordY = uval_1;
      if (g_ActivePlayer == 1) {
        *(int32_t *)(&g_CardSlot_ConvertedManaCost + y * 0x120 + x * 0x5b20) = 0;
      }
      else {
        *(uint32_t *)(&g_CardSlot_Flags + y * 0x120 + x * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_Flags + y * 0x120 + x * 0x5b20) | 0x10;
      }
    }
    if ((width == 0x72) &&
       (*(int *)(&g_CardSlot_CardId +
                *(int *)(&g_CardSlot_SicknessState + y * 0x120 + x * 0x5b20) * 0x120 +
                *(int *)(&g_CardSlot_TapState + y * 0x120 + x * 0x5b20) * 0x5b20) != -1)) {
      val_5 = 0;
      val_2 = *(int *)(&g_CardSlot_ConvertedManaCost + y * 0x120 + x * 0x5b20);
      val_3 = Glue_Subsystem_004e6978(g_DialogPromptHwnd,g_DuelArenaHwnd);
      val_2 = Math_Clamp(val_2 + val_3,val_5,height);
      Glue_Subsystem_004e6913(g_DialogPromptHwnd,g_DuelArenaHwnd,val_2);
    }
  }
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_00464fcd
 * Entry Point: 00464fcd
 * Size: 408 bytes
 */


int32_t Minit_Subsystem_00464fcd(int player_id,int card_slot,int event_type)

{
  if (((arg_3 == 0x82) && (g_EventSourceSlot == card_slot)) && (g_EventSourcePlayer == player)) {
    *(uint32_t *)(&g_CardSlot_ProtectionFlags + card_slot * 0x120 + player * 0x5b20) =
         *(uint32_t *)(&g_CardSlot_ProtectionFlags + card_slot * 0x120 + player * 0x5b20) & 0xfffffffc;
  }
  if ((((arg_3 == 0x84) && (g_EventSourceSlot == card_slot)) &&
      ((g_EventSourcePlayer == player &&
       ((((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) != 0 &&
        (g_TurnPlayer == player)))))) && (g_CurrentTurnTargetPlayer == player)) {
    *(uint32_t *)(&g_CardSlot_SpecialState + card_slot * 0x120 + player * 0x5b20) =
         *(uint32_t *)(&g_CardSlot_SpecialState + card_slot * 0x120 + player * 0x5b20) | 0x10;
    (&DAT_006a603c)[card_slot * 0x120 + player * 0x5b20] =
         (&DAT_006a603c)[card_slot * 0x120 + player * 0x5b20] + '\t';
  }
  if (((arg_3 == 0x6c) && (g_EventSourceSlot == card_slot)) && (g_EventSourcePlayer == player)) {
    (&DAT_006a603c)[card_slot * 0x120 + player * 0x5b20] =
         (&DAT_006a603c)[card_slot * 0x120 + player * 0x5b20] + '\t';
  }
  return 0;
}



/*
 * Decompiled function: CardScript_FlyingCarpet
 * Entry Point: 00465165
 * Size: 1181 bytes
 */


int32_t CardScript_FlyingCarpet(int spell_id,int target_id,int flags)

{
  int val_1;
  int32_t uval_2;
  uint32_t uval_3;
  uint32_t uval_4;
  uint32_t uval_5;
  int32_t arg_11;
  int val_6;
  int32_t arg_12;
  uint32_t uval_7;
  int32_t arg_13;
  uint32_t uval_8;
  int32_t arg_14;
  uint32_t uVar9;
  int32_t arg_15;
  uint32_t uVar10;
  int32_t arg_16;
  uint32_t uVar11;
  int32_t arg_17;
  uint8_t *arg_18;
  int32_t arg_18_00;
  int32_t arg_19;
  int *arg_20;
  int card_idx;
  int32_t match_count;
  
  if (((flags == 0x6c) && (target_id == g_EventSourceSlot)) &&
     (spell_id == g_EventSourcePlayer)) {
    g_SpellStackDepth = g_SpellStackDepth + 0xc;
  }
  if (flags == 0x73) {
    if (((((&g_CardSlot_Subtypes)[target_id * 0x120 + spell_id * 0x5b20] & 3) == 0) ||
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) * 0x34] & 2) == 0))
       && ((((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0 &&
           (val_1 = Font_DrawString(spell_id,7,2), val_1 != 0)))) {
      arg_19 = 0;
      arg_18_00 = 0;
      arg_17 = 0;
      arg_16 = 0xffffffff;
      arg_15 = 0xffffffff;
      arg_14 = 0xffffffff;
      arg_13 = 0xffffffff;
      arg_12 = 0;
      arg_11 = 0;
      uval_2 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_1 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uval_2,arg_11,arg_12,arg_13,arg_14,
                           arg_15,arg_16,arg_17,arg_18_00,arg_19);
      if (val_1 != 0) {
        return 1;
      }
    }
  }
  else if (flags == 0x90) {
    Ai_PeekPlannedSlot(0);
  }
  else {
    if (((flags == 0x6d) &&
        (((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0)) &&
       ((val_1 = Font_DrawString(spell_id,7,2), val_1 != 0 &&
        (Ai_CalcManaRequirement_004ba890(spell_id,0,2), g_ActivePlayer != 1)))) {
      Pic_Subsystem_00424500(s_prompts_txt_005246dc,s_FLYING_CARPET_005246cc);
      arg_20 = &card_idx;
      uval_2 = 1;
      arg_18 = &g_OverworldGoldAmount;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      val_6 = -1;
      val_1 = -1;
      uval_5 = 0;
      uval_4 = 0;
      uval_3 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_1 = Duel_ChooseTarget
                        (spell_id,2,spell_id,0x200,2,0,0,uval_3,uval_4,uval_5,val_1,val_6,uval_7,uval_8,
                         uVar9,uVar10,uVar11,arg_18,uval_2,arg_20);
      if (val_1 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = card_idx;
        *(int32_t *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = match_count;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        *(uint32_t *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
      }
    }
    if (flags == 0x72) {
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      val_6 = -1;
      val_1 = -1;
      uval_5 = 0;
      uval_4 = 0;
      uval_3 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_1 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20),
                         (char *)0x0,spell_id,2,2,0x200,2,0,0,uval_3,uval_4,uval_5,val_1,val_6,uval_7,
                         uval_8,uVar9,uVar10,uVar11);
      if (val_1 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int32_t *)
         (&g_CardSlot_Abilities2 +
         *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) * 0x120) =
             0x8000000;
        val_1 = Card_ApplyTriggerEffect(g_DialogPromptHwnd,g_DuelArenaHwnd,DAT_0069f6dc,
                             *(int *)(&g_CardSlot_CombatTarget +
                                     target_id * 0x120 + spell_id * 0x5b20),
                             *(int *)(&g_CardSlot_AttachedAura +
                                     target_id * 0x120 + spell_id * 0x5b20));
        if (val_1 != -1) {
          *(int32_t *)(&g_CardSlot_ConvertedManaCost + val_1 * 0x120 + spell_id * 0x5b20) = 0x20;
        }
      }
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
       *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20] = 0;
    }
  }
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_00465602
 * Entry Point: 00465602
 * Size: 983 bytes
 */


/* WARNING: Removing unreachable block (ram,0x004659aa) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int32_t Minit_Subsystem_00465602(int player_id,int card_slot,int event_type)

{
  char cVar1;
  int val_2;
  int32_t uval_3;
  int match_count;
  
  if (((arg_3 == 0x6c) && (g_EventSourceSlot == card_slot)) && (g_EventSourcePlayer == player)) {
    g_SpellStackDepth = g_SpellStackDepth + 0xc;
  }
  if (arg_3 == 0x73) {
    if ((((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) == 0) &&
       (val_2 = Font_DrawString(player,7,2), val_2 != 0)) {
      uval_3 = 1;
    }
    else {
      uval_3 = 0;
    }
  }
  else if (arg_3 == 0x90) {
    Ai_PeekPlannedSlot(0);
    uval_3 = 0;
  }
  else {
    if ((arg_3 == 0x6d) && (val_2 = Font_DrawString(player,7,2), val_2 != 0)) {
      if (match_count == -1) {
        g_ActivePlayer = 1;
      }
      else {
        Ai_CalcManaRequirement_004ba890(player,0,2);
        *(uint32_t *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) | 0x10;
        (&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20] = g_TemporaryToughnessBuffer;
        *(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) = match_count;
      }
    }
    if ((arg_3 == 0x72) &&
       (*(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) != -1)) {
      val_2 = Card_ApplyTriggerEffect(player,card_slot,DAT_0069f6dc,
                           (int)(char)(&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20],
                           *(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20));
      if (val_2 != -1) {
        cVar1 = Card_RemapColorIndexFF(player,card_slot,2);
        *(int *)(&g_CardSlot_ConvertedManaCost + val_2 * 0x120 + player * 0x5b20) =
             1 << (cVar1 - 1U & 0x1f);
      }
      *(int32_t *)
       (&g_CardSlot_Abilities2 +
       *(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) * 0x120 +
       (char)(&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20] * 0x5b20) = 0x8000000;
      Minit_Subsystem_004659d9
                (player,card_slot,*(uint32_t *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20))
      ;
      *(int32_t *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) = 0xffffffff;
      (&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20] =
           (&g_CardSlot_OriginalCardId)[card_slot * 0x120 + player * 0x5b20];
    }
    if ((((arg_3 == 0x77) &&
         (*(int *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) != 0)) &&
        (val_2 = Minit_Subsystem_00465a19(player,card_slot), g_TemporaryToughnessBuffer == g_EventSourcePlayer))
       && (g_EventSourceSlot == val_2)) {
      Pic_Subsystem_0044867e(player,card_slot,2);
    }
    uval_3 = 0;
  }
  return uval_3;
}



/*
 * Decompiled function: Minit_Subsystem_004659d9
 * Entry Point: 004659d9
 * Size: 64 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Minit_Subsystem_004659d9(int player_id,int card_slot,uint32_t arg_3)

{
  *(uint32_t *)(&g_CardSlot_TargetSlot + card_slot * 0x120 + player * 0x5b20) =
       (-(uint32_t)(g_TemporaryToughnessBuffer == 0) & 0xffffff00) + 0x200 | arg_3;
  return;
}



/*
 * Decompiled function: Minit_Subsystem_00465a19
 * Entry Point: 00465a19
 * Size: 92 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint32_t Minit_Subsystem_00465a19(int arg1,int arg2)

{
  g_TemporaryToughnessBuffer = (*(int *)(&g_CardSlot_TargetSlot + arg2 * 0x120 + arg1 * 0x5b20) >> 8) + -1;
  return *(uint32_t *)(&g_CardSlot_TargetSlot + arg2 * 0x120 + arg1 * 0x5b20) & 0xff;
}



/*
 * Decompiled function: CardScript_HelmOfChatzuk
 * Entry Point: 00465a75
 * Size: 1063 bytes
 */


int32_t CardScript_HelmOfChatzuk(int spell_id,int target_id,int flags)

{
  int val_1;
  int32_t uval_2;
  uint32_t uval_3;
  uint32_t uval_4;
  uint32_t uval_5;
  int32_t arg_11;
  int val_6;
  int32_t arg_12;
  uint32_t uval_7;
  int32_t arg_13;
  uint32_t uval_8;
  int32_t arg_14;
  uint32_t uVar9;
  int32_t arg_15;
  uint32_t uVar10;
  int32_t arg_16;
  uint32_t uVar11;
  int32_t arg_17;
  uint8_t *arg_18;
  int32_t arg_18_00;
  int32_t arg_19;
  int *arg_20;
  int card_idx;
  int match_count;
  
  if (((flags == 0x6c) && (target_id == g_EventSourceSlot)) &&
     (spell_id == g_EventSourcePlayer)) {
    g_SpellStackDepth = g_SpellStackDepth + (*(int *)(&DAT_006b3010 + spell_id * 4) * 0xc) / 2;
  }
  if (flags == 0x73) {
    if (((((&g_CardSlot_Subtypes)[target_id * 0x120 + spell_id * 0x5b20] & 3) == 0) ||
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) * 0x34] & 2) == 0))
       && ((((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0 &&
           (val_1 = Font_DrawString(spell_id, 7, 1), val_1 != 0)))) {
      arg_19 = 0;
      arg_18_00 = 0;
      arg_17 = 0;
      arg_16 = 0xffffffff;
      arg_15 = 0xffffffff;
      arg_14 = 0xffffffff;
      arg_13 = 0xffffffff;
      arg_12 = 0;
      arg_11 = 0;
      uval_2 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_1 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uval_2,arg_11,arg_12,arg_13,arg_14,
                           arg_15,arg_16,arg_17,arg_18_00,arg_19);
      if (val_1 != 0) {
        return 1;
      }
    }
  }
  else if (flags == 0x90) {
    Ai_PeekPlannedSlot(0);
  }
  else {
    if (((flags == 0x6d) && (val_1 = Font_DrawString(spell_id, 7, 1), val_1 != 0)) &&
       (Ai_CalcManaRequirement_004ba890(spell_id,0,1), g_ActivePlayer != 1)) {
      Pic_Subsystem_00424500(s_prompts_txt_005246f8,s_HELM_OF_CHATZUK_005246e8);
      arg_20 = &card_idx;
      uval_2 = 1;
      arg_18 = &g_OverworldGoldAmount;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      val_6 = -1;
      val_1 = -1;
      uval_5 = 0;
      uval_4 = 0;
      uval_3 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_1 = Duel_ChooseTarget
                        (spell_id,2,spell_id,0x200,2,0,0,uval_3,uval_4,uval_5,val_1,val_6,uval_7,uval_8,
                         uVar9,uVar10,uVar11,arg_18,uval_2,arg_20);
      if (val_1 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = card_idx;
        *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = match_count;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        *(uint32_t *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
      }
    }
    if (flags == 0x72) {
      card_idx = *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
      match_count = *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
       *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20] = 0;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      val_6 = -1;
      val_1 = -1;
      uval_5 = 0;
      uval_4 = 0;
      uval_3 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_1 = Rules_ParseFilter_0040360b
                        (card_idx,match_count,(char *)0x0,spell_id,2,2,0x200,2,0,0,uval_3,uval_4,uval_5,
                         val_1,val_6,uval_7,uval_8,uVar9,uVar10,uVar11);
      if (val_1 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        val_1 = Card_ApplyTriggerEffect(g_DialogPromptHwnd,g_DuelArenaHwnd,DAT_0069f6dc,card_idx,match_count);
        if (val_1 != -1) {
          *(int32_t *)(&g_CardSlot_ConvertedManaCost + val_1 * 0x120 + spell_id * 0x5b20) = 0x40;
        }
        *(int32_t *)(&g_CardSlot_Abilities2 + match_count * 0x120 + card_idx * 0x5b20) = 0x8000000;
      }
    }
  }
  return 0;
}



/*
 * Decompiled function: CardScript_CoralHelm
 * Entry Point: 00465e9c
 * Size: 1094 bytes
 */


int32_t CardScript_CoralHelm(int spell_id,int target_id,int flags)

{
  int val_1;
  int32_t uval_2;
  uint32_t uval_3;
  uint32_t uval_4;
  uint32_t uval_5;
  int32_t arg_11;
  int val_6;
  int32_t arg_12;
  uint32_t uval_7;
  int32_t arg_13;
  uint32_t uval_8;
  int32_t arg_14;
  uint32_t uVar9;
  int32_t arg_15;
  uint32_t uVar10;
  int32_t arg_16;
  uint32_t uVar11;
  int32_t arg_17;
  uint8_t *arg_18;
  int32_t arg_18_00;
  int32_t arg_19;
  int *arg_20;
  int card_idx;
  int match_count;
  
  if (((flags == 0x6c) && (target_id == g_EventSourceSlot)) &&
     (spell_id == g_EventSourcePlayer)) {
    val_1 = (&g_ActivePlayerSpellPriority)[spell_id] * *(int *)(&DAT_006b3010 + spell_id * 4) * 0xc;
    g_SpellStackDepth = g_SpellStackDepth + ((int)(val_1 + (val_1 >> 0x1f & 0xfU)) >> 4);
  }
  if (flags == 0x73) {
    if ((((&g_ActivePlayerSpellPriority)[spell_id] != 0) && (val_1 = Font_DrawString(spell_id,7,3), val_1 != 0)) &&
       (((((&g_CardSlot_Subtypes)[target_id * 0x120 + spell_id * 0x5b20] & 3) == 0 ||
         (((&g_MasterCardColorTable)
           [*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) * 0x34] & 2) == 0))
        && (((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0)))) {
      arg_19 = 0;
      arg_18_00 = 0;
      arg_17 = 0;
      arg_16 = 0xffffffff;
      arg_15 = 0xffffffff;
      arg_14 = 0xffffffff;
      arg_13 = 0xffffffff;
      arg_12 = 0;
      arg_11 = 0;
      uval_2 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_1 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uval_2,arg_11,arg_12,arg_13,arg_14,
                           arg_15,arg_16,arg_17,arg_18_00,arg_19);
      if (val_1 != 0) {
        return 1;
      }
    }
  }
  else if (flags == 0x90) {
    Ai_PeekPlannedSlot(0);
  }
  else {
    if (((flags == 0x6d) && ((&g_ActivePlayerSpellPriority)[spell_id] != 0)) &&
       ((val_1 = Font_DrawString(spell_id,7,3), val_1 != 0 &&
        (Ai_CalcManaRequirement_004ba890(spell_id,0,3), g_ActivePlayer != 1)))) {
      Prompts_Load_0046fa40(spell_id,1,1);
      Pic_Subsystem_00424500(s_prompts_txt_00524710,s_CORAL_HELM_00524704);
      arg_20 = &card_idx;
      uval_2 = 1;
      arg_18 = &g_OverworldGoldAmount;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      val_6 = -1;
      val_1 = -1;
      uval_5 = 0;
      uval_4 = 0;
      uval_3 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_1 = Duel_ChooseTarget
                        (spell_id,2,spell_id,0x200,2,0,0,uval_3,uval_4,uval_5,val_1,val_6,uval_7,uval_8,
                         uVar9,uVar10,uVar11,arg_18,uval_2,arg_20);
      if (val_1 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = card_idx;
        *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = match_count;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
      }
    }
    if (flags == 0x72) {
      card_idx = *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
      match_count = *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
       *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20] = 0;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      val_6 = -1;
      val_1 = -1;
      uval_5 = 0;
      uval_4 = 0;
      uval_3 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_1 = Rules_ParseFilter_0040360b
                        (card_idx,match_count,(char *)0x0,spell_id,2,2,0x200,2,0,0,uval_3,uval_4,uval_5,
                         val_1,val_6,uval_7,uval_8,uVar9,uVar10,uVar11);
      if (val_1 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        val_1 = Card_ApplyTriggerEffect(g_DialogPromptHwnd,g_DuelArenaHwnd,g_PlayerSelectionPriority,card_idx,match_count);
        if (val_1 != -1) {
          *(int16_t *)(&g_CardSlot_PowerCounters + val_1 * 0x120 + spell_id * 0x5b20) = 2;
          *(int16_t *)(&g_CardSlot_ToughnessCounters + val_1 * 0x120 + spell_id * 0x5b20) = 2;
        }
      }
    }
  }
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_004662e2
 * Entry Point: 004662e2
 * Size: 607 bytes
 */


int32_t Minit_Subsystem_004662e2(int player_id,int card_slot,int event_type)

{
  int val_1;
  int32_t uval_2;
  int match_count;
  
  if (arg_3 == 0x73) {
    if (((((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) == 0) &&
        (val_1 = Font_DrawString(player,7,3), val_1 != 0)) &&
       ((((&g_PlayerPoisonCounters)[1 - player] | (&g_PlayerPoisonCounters)[g_CurrentTurnPhase]) & 2) != 0)) {
      uval_2 = 1;
    }
    else {
      uval_2 = 0;
    }
  }
  else if (arg_3 == 0x90) {
    Ai_PeekPlannedSlot(0);
    uval_2 = 0;
  }
  else {
    if (((arg_3 == 0x6d) && (((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) == 0)) &&
       (val_1 = Font_DrawString(player,7,3), val_1 != 0)) {
      Ai_CalcManaRequirement_004ba890(player,0,3);
      *(uint32_t *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) | 0x10;
      if (match_count == -1) {
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20] = g_TemporaryToughnessBuffer;
        *(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) = match_count;
      }
    }
    if (((arg_3 == 0x72) &&
        (*(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) != -1)) &&
       (val_1 = Card_ApplyTriggerEffect(player,card_slot,g_PlayerSelectionPriority,
                             (int)(char)(&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20],
                             *(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20)),
       val_1 != -1)) {
      *(int16_t *)(&g_CardSlot_PowerCounters + val_1 * 0x120 + player * 0x5b20) = 0xfffe;
      *(int16_t *)(&g_CardSlot_ToughnessCounters + val_1 * 0x120 + player * 0x5b20) = 0;
    }
    uval_2 = 0;
  }
  return uval_2;
}



/*
 * Decompiled function: CardScript_TawnosWand
 * Entry Point: 00466541
 * Size: 1053 bytes
 */


int32_t CardScript_TawnosWand(int spell_id,int target_id,int flags)

{
  int val_1;
  int32_t uval_2;
  uint32_t uval_3;
  uint32_t uval_4;
  uint32_t uval_5;
  int32_t arg_11;
  int val_6;
  int32_t arg_12;
  uint32_t uval_7;
  int32_t arg_13;
  uint32_t uval_8;
  int32_t arg_14;
  uint32_t uVar9;
  int32_t arg_15;
  uint32_t uVar10;
  int32_t arg_16;
  uint32_t uVar11;
  int32_t arg_17;
  uint8_t *arg_18;
  int32_t arg_18_00;
  int32_t arg_19;
  int *arg_20;
  int match_count;
  int slot_idx;
  
  if (((flags == 0x6c) && (target_id == g_EventSourceSlot)) &&
     (spell_id == g_EventSourcePlayer)) {
    g_SpellStackDepth = g_SpellStackDepth + 0x18;
  }
  if (flags == 0x73) {
    if (((((&g_CardSlot_Subtypes)[target_id * 0x120 + spell_id * 0x5b20] & 3) == 0) ||
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) * 0x34] & 2) == 0))
       && ((((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0 &&
           (val_1 = Font_DrawString(spell_id,7,2), val_1 != 0)))) {
      arg_19 = 0;
      arg_18_00 = 0;
      arg_17 = 0;
      arg_16 = 0xffffffff;
      arg_15 = 0x2002;
      arg_14 = 0xffffffff;
      arg_13 = 0xffffffff;
      arg_12 = 0;
      arg_11 = 0;
      uval_2 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_1 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uval_2,arg_11,arg_12,arg_13,arg_14,
                           arg_15,arg_16,arg_17,arg_18_00,arg_19);
      if (val_1 != 0) {
        return 1;
      }
    }
  }
  else if (flags == 0x90) {
    Ai_PeekPlannedSlot(0);
  }
  else {
    if (((flags == 0x6d) &&
        (((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0)) &&
       ((val_1 = Font_DrawString(spell_id,7,2), val_1 != 0 &&
        (Ai_CalcManaRequirement_004ba890(spell_id,0,2), g_ActivePlayer != 1)))) {
      Pic_Subsystem_00424500(s_prompts_txt_00524728,s_TAWNOS_WAND_0052471c);
      arg_20 = &match_count;
      uval_2 = 1;
      arg_18 = &g_OverworldGoldAmount;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uval_8 = 0xffffffff;
      uval_7 = 0x2002;
      val_6 = -1;
      val_1 = -1;
      uval_5 = 0;
      uval_4 = 0;
      uval_3 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_1 = Duel_ChooseTarget
                        (spell_id,2,spell_id,0x200,2,0,0,uval_3,uval_4,uval_5,val_1,val_6,uval_7,uval_8,
                         uVar9,uVar10,uVar11,arg_18,uval_2,arg_20);
      if (val_1 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = match_count;
        *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = slot_idx;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        *(uint32_t *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
      }
    }
    if (flags == 0x72) {
      match_count = *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
      slot_idx = *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120] = 0;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uval_8 = 0xffffffff;
      uval_7 = 0x2002;
      val_6 = -1;
      val_1 = -1;
      uval_5 = 0;
      uval_4 = 0;
      uval_3 = Glue_Subsystem_004d0a42(spell_id,target_id);
      val_1 = Rules_ParseFilter_0040360b
                        (match_count,slot_idx,(char *)0x0,spell_id,2,2,0x200,2,0,0,uval_3,uval_4,uval_5,
                         val_1,val_6,uval_7,uval_8,uVar9,uVar10,uVar11);
      if (val_1 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        Card_ApplyTriggerEffect(g_DialogPromptHwnd,g_DuelArenaHwnd,DAT_00696734,match_count,slot_idx);
      }
    }
    if (flags == 199) {
      if (spell_id == g_ActivePlayerPriority) {
        g_SpellStackDepth = g_SpellStackDepth + 0x18;
      }
      else {
        g_SpellStackDepth = g_SpellStackDepth + -0x18;
      }
    }
  }
  return 0;
}



/*
 * Decompiled function: Card_Setup_0046695e
 * Entry Point: 0046695e
 * Size: 349 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int32_t Card_Setup_0046695e(int player_id,int card_slot,int event_type)

{
  int val_1;
  int32_t uval_2;
  int slot_idx;
  
  if (((arg_3 == 0x6c) && (card_slot == g_EventSourceSlot)) && (player == g_EventSourcePlayer)) {
    g_SpellStackDepth = g_SpellStackDepth + 0xc;
  }
  if (arg_3 == 0x73) {
    val_1 = Font_DrawString(player,7,1);
    if ((val_1 == 0) || (((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) != 0)) {
      uval_2 = 0;
    }
    else {
      uval_2 = 1;
    }
  }
  else if (arg_3 == 0x90) {
    Ai_PeekPlannedSlot(0);
    uval_2 = 0;
  }
  else {
    if ((arg_3 == 0x6d) && (val_1 = Font_DrawString(player,7,1), val_1 != 0)) {
      Ai_CalcManaRequirement_004ba890(player,0,1);
      strcpy(&g_OverworldWorldState,s_Tap_which_card__00524734);
      if (slot_idx != -1) {
        *(uint32_t *)(&g_CardSlot_Flags + slot_idx * 0x120 + g_TemporaryToughnessBuffer * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_Flags + slot_idx * 0x120 + g_TemporaryToughnessBuffer * 0x5b20) | 0x10;
        Magic_BroadcastCardEvent(g_TemporaryToughnessBuffer,slot_idx,0x7c);
      }
      *(uint32_t *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) | 0x10;
    }
    uval_2 = 0;
  }
  return uval_2;
}



/*
 * Decompiled function: Minit_Subsystem_00466abb
 * Entry Point: 00466abb
 * Size: 617 bytes
 */


int32_t Minit_Subsystem_00466abb(int player_id,int card_slot,int event_type)

{
  int val_1;
  
  if (arg_3 == 0x73) {
    if ((((*(int *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) == 0) &&
         (val_1 = Font_DrawString(player,7,5), val_1 != 0)) &&
        ((((&g_CardSlot_Subtypes)[card_slot * 0x120 + player * 0x5b20] & 3) == 0 ||
         (((&g_MasterCardColorTable)
           [*(int *)(&g_CardSlot_CardId + card_slot * 0x120 + player * 0x5b20) * 0x34] & 2) == 0)))) &&
       (((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) == 0)) {
      if ((player == g_ActivePlayerPriority) && (0 < DAT_006ff550)) {
        g_CombatPhaseFlags = g_CombatPhaseFlags | 3;
      }
      return 1;
    }
  }
  else {
    if (((arg_3 == 0x6d) && (val_1 = Font_DrawString(player,7,5), val_1 != 0)) &&
       (Ai_CalcManaRequirement_004ba890(player,0,5), g_ActivePlayer != 1)) {
      *(uint32_t *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) | 0x10;
      *(uint32_t *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) | 1;
      if (0 < DAT_006ff550) {
        DAT_006ff550 = DAT_006ff550 + -1;
      }
    }
    if (arg_3 == 0x72) {
      val_1 = Pic_Subsystem_0045268f(0x375);
      val_1 = Deck_AddCardToDeck(player,val_1);
      if (val_1 != -1) {
        Pic_Subsystem_0042ac1f(player,val_1);
        *(uint32_t *)(&g_CardSlot_Abilities1 + val_1 * 0x120 + player * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_Abilities1 + val_1 * 0x120 + player * 0x5b20) | 0x10;
      }
      *(int32_t *)
       (&g_CardSlot_ConvertedManaCost +
       *(int *)(&g_CardSlot_TapState + card_slot * 0x120 + player * 0x5b20) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + card_slot * 0x120 + player * 0x5b20) * 0x120) = 0;
    }
  }
  return 0;
}



/*
 * Decompiled function: CardScript_BottleOfSuleiman
 * Entry Point: 00466d29
 * Size: 563 bytes
 */


int32_t CardScript_BottleOfSuleiman(int player_id,int card_slot,int event_type)

{
  int val_1;
  int32_t uval_2;
  int val_3;
  
  if (arg_3 == 0x73) {
    val_1 = Font_DrawString(player,7,1);
    if (((val_1 == 0) ||
        ((((&g_CardSlot_Subtypes)[card_slot * 0x120 + player * 0x5b20] & 3) != 0 &&
         (((&g_MasterCardColorTable)
           [*(int *)(&g_CardSlot_CardId + card_slot * 0x120 + player * 0x5b20) * 0x34] & 2) != 0)))) ||
       (((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) != 0)) {
      uval_2 = 0;
    }
    else {
      uval_2 = 1;
    }
  }
  else {
    if (((arg_3 == 0x6d) && (val_1 = Font_DrawString(player,7,1), val_1 != 0)) &&
       (Ai_CalcManaRequirement_004ba890(player,0,1), g_ActivePlayer != 1)) {
      Pic_Subsystem_0044867e(player,card_slot,3);
    }
    if (arg_3 == 0x72) {
      if (player == g_CurrentTurnPhase) {
        strcpy(&g_OverworldWorldState,s_Heads_Tails_00524744);
      }
      else {
        strcpy(&g_OverworldWorldState,s_Call_the_coin_flip__Heads_Tails_00524754);
      }
      val_1 = Util_GetRandomNumber(1);
      val_1 = Ai_Subsystem_004cc56d(1 - player,player,card_slot,-1,-1,&g_OverworldWorldState,val_1);
      strcpy(&g_OverworldWorldState,&DAT_00524778);
      val_3 = Ai_Subsystem_004b7d38(s_Bottle_of_Suleiman_0052477c);
      if (val_3 == val_1) {
        Mem_AllocOrFree_0041df33(player,5,g_DialogPromptHwnd,g_DuelArenaHwnd);
      }
      else {
        val_1 = Pic_Subsystem_0045268f(0x37a);
        val_1 = Deck_AddCardToDeck(player,val_1);
        if (val_1 != -1) {
          Pic_Subsystem_0042ac1f(player,val_1);
          *(uint32_t *)(&g_CardSlot_Abilities1 + val_1 * 0x120 + player * 0x5b20) =
               *(uint32_t *)(&g_CardSlot_Abilities1 + val_1 * 0x120 + player * 0x5b20) | 0x10;
        }
      }
    }
    uval_2 = 0;
  }
  return uval_2;
}



/*
 * Decompiled function: Minit_Subsystem_00466f5c
 * Entry Point: 00466f5c
 * Size: 320 bytes
 */


int32_t Minit_Subsystem_00466f5c(int player_id,int card_slot,int event_type)

{
  int val_1;
  int32_t uval_2;
  int match_count;
  int slot_idx;
  
  if (arg_3 == 0x73) {
    val_1 = Font_DrawString(player,7,1);
    if ((val_1 == 0) || (((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) != 0)) {
      uval_2 = 0;
    }
    else {
      uval_2 = 1;
    }
  }
  else {
    if (((arg_3 == 0x6d) && (val_1 = Font_DrawString(player,7,1), val_1 != 0)) &&
       (Ai_CalcManaRequirement_004ba890(player,0,1), g_ActivePlayer != 1)) {
      for (slot_idx = 0; slot_idx < 2; slot_idx = slot_idx + 1) {
        for (match_count = 0; match_count < (int)(&g_PlayerActiveCardCount)[slot_idx]; match_count = match_count + 1)
        {
          val_1 = Card_IsInPlay(slot_idx,match_count);
          if ((val_1 != 0) && (val_1 = Util_GetRandomNumber(3), val_1 == 0)) {
            Pic_Subsystem_0044867e(slot_idx,match_count,2);
          }
        }
      }
      Pic_Subsystem_0044867e(player,card_slot,2);
    }
    uval_2 = 0;
  }
  return uval_2;
}



/*
 * Decompiled function: Player_Init_0046709c
 * Entry Point: 0046709c
 * Size: 718 bytes
 */


int32_t Player_Init_0046709c(int spell_id,int target_id,int flags)

{
  int32_t uval_1;
  int val_2;
  int local_94;
  int local_90;
  int32_t local_8c;
  int local_88;
  int local_84;
  int local_80;
  int local_7c [30];
  
  if (flags == 0x73) {
    if (((((&g_CardSlot_Subtypes)[target_id * 0x120 + spell_id * 0x5b20] & 3) == 0) ||
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) * 0x34] & 2) == 0))
       && (((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0)) {
      uval_1 = 1;
    }
    else {
      uval_1 = 0;
    }
  }
  else {
    if (flags == 0x6d) {
      Pic_Subsystem_00424500(s_prompts_txt_005247a0,s_GLASSES_OF_URZA_00524790);
      val_2 = Duel_ChooseTarget
                        (spell_id,2,1 - spell_id,0x1000,0,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0,0,
                         0,&g_OverworldGoldAmount,1,&local_90);
      if (val_2 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = local_90;
        *(int32_t *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = local_8c
        ;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        *(uint32_t *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
      }
    }
    if (flags == 0x72) {
      local_94 = 0;
      local_88 = *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
      if (((g_IsAiThinking != 1) && (spell_id == 0)) && (g_AiTurnDecisionFlag == 0)) {
        for (local_84 = 0; local_84 < (int)(&g_PlayerActiveCardCount)[local_88];
            local_84 = local_84 + 1) {
          local_80 = *(int *)(&g_CardSlot_CardId + local_88 * 0x5b20 + local_84 * 0x120);
          if ((local_80 != -1) &&
             (((&g_CardSlot_Flags)[local_88 * 0x5b20 + local_84 * 0x120] & 2) == 0)) {
            local_7c[local_94] = local_80;
            local_94 = local_94 + 1;
          }
        }
        UI_DeckSelectionMenu(0,(int)local_7c,local_94,s_Target_Player_s_Hand_005247b4,0);
      }
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: Minit_Subsystem_0046736a
 * Entry Point: 0046736a
 * Size: 258 bytes
 */


int32_t Minit_Subsystem_0046736a(int player_id,int card_slot,int event_type)

{
  if (((arg_3 == 0x6c) && (g_EventSourceSlot == card_slot)) && (g_EventSourcePlayer == player)) {
    g_DuelModeFlags = g_DuelModeFlags | 0x800 << ((uint8_t)player & 0x1f);
  }
  if (((arg_3 == 0x1f) && (g_TurnPlayer == player)) &&
     ((((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) == 0 ||
      (((&g_MasterCardColorTable)
        [*(int *)(&g_CardSlot_CardId + card_slot * 0x120 + player * 0x5b20) * 0x34] & 2) != 0)))) {
    g_CardEventResult = g_CardEventResult + 1;
  }
  if (((arg_3 == 0x77) && (g_EventSourceSlot == card_slot)) && (g_EventSourcePlayer == player)) {
    g_DuelModeFlags = g_DuelModeFlags & ~(0x800 << ((uint8_t)player & 0x1f));
  }
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_0046746c
 * Entry Point: 0046746c
 * Size: 288 bytes
 */


int32_t Minit_Subsystem_0046746c(int player_id,int card_slot,int event_type)

{
  int val_1;
  int32_t uval_2;
  
  if (arg_3 == 0x73) {
    val_1 = Font_DrawString(player,7,3);
    if ((val_1 == 0) ||
       (((((&g_CardSlot_Subtypes)[card_slot * 0x120 + player * 0x5b20] & 3) != 0 &&
         (((&g_MasterCardColorTable)
           [*(int *)(&g_CardSlot_CardId + card_slot * 0x120 + player * 0x5b20) * 0x34] & 2) != 0)) ||
        (((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) != 0)))) {
      uval_2 = 0;
    }
    else {
      uval_2 = 1;
    }
  }
  else {
    if ((arg_3 == 0x6d) && (Ai_CalcManaRequirement_004ba890(player,0,3), g_ActivePlayer != 1)) {
      *(uint32_t *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) | 0x10;
    }
    if (arg_3 == 0x72) {
      Minit_Subsystem_0046758c();
    }
    uval_2 = 0;
  }
  return uval_2;
}



/*
 * Decompiled function: Minit_Subsystem_0046758c
 * Entry Point: 0046758c
 * Size: 546 bytes
 */


int32_t Minit_Subsystem_0046758c(void)

{
  int val_1;
  int arg1;
  int val_2;
  int local_fb4;
  int aiStack_fac [1000];
  int match_count;
  int slot_idx;
  
  slot_idx = 0;
  for (local_fb4 = 0; local_fb4 < 2; local_fb4 = local_fb4 + 1) {
    match_count = 0;
    while ((match_count < 500 &&
           (aiStack_fac[slot_idx] = *(int *)(&g_PlayerDeckCardList + match_count * 4 + local_fb4 * 2000),
           *(int *)(&g_PlayerDeckCardList + match_count * 4 + local_fb4 * 2000) != -1))) {
      if (((&g_MasterCardColorTable)
           [*(int *)(&g_PlayerDeckCardList + match_count * 4 + local_fb4 * 2000) * 0x34] & 2) != 0) {
        slot_idx = slot_idx + 1;
      }
      match_count = match_count + 1;
    }
  }
  val_1 = Util_GetRandomNumber(slot_idx);
  val_1 = aiStack_fac[val_1];
  if (val_1 == -1) {
    g_ActivePlayer = 1;
  }
  else {
    arg1 = Util_GetRandomNumber(2);
    match_count = Deck_AddCardToDeck(arg1,val_1);
    if (match_count != -1) {
      *(uint32_t *)(&g_CardSlot_Abilities1 + match_count * 0x120 + arg1 * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_Abilities1 + match_count * 0x120 + arg1 * 0x5b20) | 0x10;
      Pic_Subsystem_0042ac1f(arg1,match_count);
      val_2 = Util_GetRandomNumber(2);
      if ((val_2 != 0) && (match_count = Deck_AddCardToDeck(1 - arg1,val_1), match_count != -1)) {
        *(uint32_t *)(&g_CardSlot_Abilities1 + match_count * 0x120 + (1 - arg1) * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_Abilities1 + match_count * 0x120 + (1 - arg1) * 0x5b20) | 0x10;
        Pic_Subsystem_0042ac1f(1 - arg1,match_count);
      }
      if (g_IsAiThinking != 1) {
        Duel_PlaySoundById(0x28);
      }
    }
  }
  return 0;
}



/*
 * Decompiled function: Minit_Subsystem_004677ae
 * Entry Point: 004677ae
 * Size: 203 bytes
 */


int32_t Minit_Subsystem_004677ae(int player_id,int card_slot,int event_type)

{
  int arg_3_00;
  uint32_t arg_2_00;
  
  if ((((arg_3 == 0x7f) && (g_EventSourceSlot == card_slot)) && (g_EventSourcePlayer == player)) &&
     ((((&g_CardSlot_Flags)[card_slot * 0x120 + player * 0x5b20] & 0x10) == 0 ||
      (((&g_MasterCardColorTable)
        [*(int *)(&g_CardSlot_CardId + card_slot * 0x120 + player * 0x5b20) * 0x34] & 2) != 0)))) {
    arg_3_00 = Card_RemapColorIndexF9(player, card_slot, 4);
    arg_2_00 = Card_RemapColorIndexF9(player,card_slot,5);
    FUN_0040d72b(player,arg_2_00,arg_3_00);
  }
  return 0;
}



/*
 * Decompiled function: UI_RegisterClass_00467880
 * Entry Point: 00467880
 * Size: 287 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool UI_RegisterClass_00467880(LPCSTR str_1)

{
  ATOM AVar1;
  WNDCLASSA local_2c;
  
  local_2c.style = 0xb;
  local_2c.lpfnWndProc = Card_Setup_00467a68;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 0x14;
  local_2c.hInstance = g_AppHInstance;
  local_2c.hIcon = LoadIconA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = (HBRUSH)0x0;
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = str_1;
  AVar1 = RegisterClassA(&local_2c);
  DAT_00538db4 = CreatePopupMenu();
  DAT_00538db0 = CreatePopupMenu();
  AppendMenuA(DAT_00538db0,0,0x72,&DAT_005248f4);
  DAT_00538df0 = LoadCursorA(g_AppHInstance,s_HAND1_005248f8);
  DAT_00538ddc = 3;
  _DAT_00538dd0 = LoadCursorA(g_AppHInstance,s_HAND2_00524900);
  _DAT_00538dd4 = LoadCursorA(g_AppHInstance,s_HAND3_00524908);
  _DAT_00538dd8 = LoadCursorA(g_AppHInstance,s_HAND4_00524910);
  return AVar1 != 0;
}



/*
 * Decompiled function: Minit_Subsystem_0046799f
 * Entry Point: 0046799f
 * Size: 201 bytes
 */


void Minit_Subsystem_0046799f(void)

{
  int slot_idx;
  
  if (DAT_00538db4 != (HMENU)0x0) {
    DestroyMenu(DAT_00538db4);
  }
  if (DAT_00538db0 != (HMENU)0x0) {
    DestroyMenu(DAT_00538db0);
  }
  DAT_00538db4 = (HMENU)0x0;
  DAT_00538db0 = (HMENU)0x0;
  if (DAT_00538df0 != (HCURSOR)0x0) {
    DestroyCursor(DAT_00538df0);
  }
  DAT_00538df0 = (HCURSOR)0x0;
  for (slot_idx = 0; slot_idx < DAT_00538ddc; slot_idx = slot_idx + 1) {
    if (*(int *)(&DAT_00538dd0 + slot_idx * 4) != 0) {
      DestroyCursor(*(HCURSOR *)(&DAT_00538dd0 + slot_idx * 4));
    }
    *(int32_t *)(&DAT_00538dd0 + slot_idx * 4) = 0;
  }
  return;
}



/*
 * Decompiled function: Card_Setup_00467a68
 * Entry Point: 00467a68
 * Size: 12124 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

LRESULT Card_Setup_00467a68(HWND hwnd,uint32_t uMsg,LONG *wParam,int *lParam)

{
  POINT pt;
  POINT pt_00;
  POINT pt_01;
  POINT pt_02;
  uint8_t arg_3;
  uint32_t uval_1;
  LONG LVar2;
  HWND pHVar3;
  HBRUSH pHVar4;
  int val_5;
  uint32_t uval_6;
  DWORD DVar7;
  BOOL BVar8;
  LRESULT LVar9;
  UINT UVar10;
  int *wParam_00;
  LONG *pLVar11;
  LPARAM LVar12;
  int iVar13;
  int local_960;
  int32_t local_954;
  HWND local_950;
  int local_94c;
  uint32_t local_948;
  uint32_t local_944;
  uint32_t local_940;
  int32_t local_93c;
  int32_t local_938;
  uint32_t local_934;
  uint32_t local_930;
  int32_t local_92c;
  uint32_t local_928;
  int32_t local_924;
  HWND local_920;
  tagMSG local_91c;
  HWND local_900;
  int local_8fc;
  tagPOINT local_8f8;
  tagRECT local_8f0;
  int32_t local_8e0;
  uint32_t local_8dc;
  uint32_t local_8d8;
  int local_8d4;
  int local_8d0;
  int local_8cc;
  int local_8c8;
  HDC local_8c4;
  tagPAINTSTRUCT local_8c0;
  tagRECT local_880;
  DWORD local_870;
  ULONG_PTR local_86c;
  int32_t local_868;
  int32_t local_864;
  HWND local_860;
  HWND local_85c;
  HWND local_858;
  tagRECT local_854;
  tagMSG local_844;
  BOOL local_828;
  int local_824;
  tagRECT local_820;
  LONG *local_810;
  int32_t local_80c;
  CHAR local_808 [100];
  int local_7a4;
  int local_7a0;
  int local_79c;
  int local_798;
  int local_794;
  uint8_t local_790 [20];
  uint32_t local_77c;
  char local_778 [208];
  int local_6a8;
  int local_6a4;
  int local_6a0;
  CHAR local_69c [100];
  int local_638;
  int local_634;
  int local_630;
  int local_62c;
  int local_628;
  uint8_t local_624 [20];
  uint32_t local_610;
  char local_60c [208];
  int local_53c [2];
  char local_534 [264];
  ULONG_PTR local_42c;
  uint32_t local_428;
  int local_424;
  int local_420;
  WPARAM local_41c;
  LONG local_418;
  LONG local_414;
  HWND local_410;
  int local_40c;
  HWND local_408 [2];
  uint8_t local_400 [288];
  LONG *local_2e0;
  HDC local_2d4;
  tagRECT local_2d0;
  ULONG_PTR local_2c0;
  uint8_t local_2bc [84];
  int local_268;
  uint32_t local_19c;
  uint32_t local_198;
  uint32_t local_194;
  tagRECT local_190;
  char local_180 [100];
  uint32_t local_11c;
  uint32_t local_118;
  uint32_t local_114;
  uint32_t local_110;
  int local_10c;
  int local_108;
  uint32_t local_104 [18];
  tagRECT local_bc;
  int local_ac;
  int local_a8;
  int local_a4;
  char *local_a0 [4];
  char *local_90;
  char *local_8c;
  char *local_88;
  char *local_84;
  char *local_80;
  char *local_7c;
  char *local_78;
  char *local_74;
  char *local_70;
  char *local_6c;
  char *local_68;
  char *local_64;
  char *local_60;
  uint32_t local_5c;
  int local_58;
  tagRECT local_54;
  int local_44;
  int local_40;
  int local_3c;
  tagRECT local_38;
  tagRECT local_28;
  int target_idx;
  void *player_idx;
  int card_idx;
  int match_count;
  HWND slot_idx;
  
  if (uMsg < 0x10) {
    if (uMsg == 0xf) {
      match_count = GetWindowLongA(hwnd,0);
      card_idx = GetWindowLongA(hwnd,4);
      LVar9 = SendMessageA(hwnd,0x404,0,0);
      if (LVar9 != 0) {
        InvalidateRect(hwnd,(RECT *)0x0,0);
      }
      EnterCriticalSection((LPCRITICAL_SECTION)&g_ActiveCombatRoundCounter);
      local_870 = GetTickCount();
      GetClientRect(hwnd,&local_880);
      local_8c4 = BeginPaint(hwnd,&local_8c0);
      if (local_8c4 != (HDC)0x0) {
        GDI_RealizeAndFlushPalette_Magic(local_8c4);
        if (DAT_0068a674 != 0) {
          pHVar4 = GetStockObject(0);
          FillRect(local_8c4,&local_880,pHVar4);
          Sleep(200);
        }
        if ((match_count == -1) && (card_idx == -1)) {
          Palette_Subsystem_0049c6cb(local_8c4,&local_880);
        }
        else if (card_idx == -1) {
          UI_RenderDuelStatusBanner(local_8c4,&local_880,match_count);
          pHVar4 = GetStockObject(4);
          FrameRect(local_8c4,&local_880,pHVar4);
        }
        else {
          local_86c = Ai_Subsystem_004b5cbb(match_count,card_idx);
          if ((local_86c != 0xffffffff) && ((int)local_86c < g_CardsDatLoadedHandle)) {
            if (local_86c == DAT_006ff2e8) {
              Palette_Subsystem_0049c6cb(local_8c4,&local_880);
              iVar13 = 1;
              val_5 = Ai_Subsystem_004b673e(match_count,card_idx);
              Palette_Subsystem_004a11fa
                        (local_8c4,&local_880.left,s_Draw_a_card_00524c50,val_5,iVar13);
            }
            else if ((((local_86c == DAT_00695e94) || (local_86c == DAT_0068a70c)) ||
                     (local_86c == DAT_0068a694)) || (local_86c == DAT_006a2848)) {
              Ai_Subsystem_004b6023(&local_8cc,match_count,card_idx);
              Palette_Subsystem_004a155f(local_8c4,&local_880.left,local_86c,match_count,card_idx);
              val_5 = Ai_Subsystem_004b682f(match_count,card_idx);
              iVar13 = Ai_Subsystem_004b67ab(match_count,card_idx);
              Palette_Subsystem_004a289f(local_8c4,&local_880.left,iVar13,val_5);
              Palette_Subsystem_004a0466(local_8c4,&local_880.left,local_8cc,local_8c8,DAT_006fe438)
              ;
            }
            else if (local_86c == DAT_006ff2dc) {
              Ai_Subsystem_004b6da5(&local_8d4,match_count,card_idx);
              Palette_Subsystem_004a1b64
                        (g_HdcBackBuffer,&local_880,local_86c,match_count,card_idx,local_8d4,local_8d0);
              val_5 = Ai_Subsystem_004b682f(local_8d4,local_8d0);
              iVar13 = Ai_Subsystem_004b67ab(local_8d4,local_8d0);
              Palette_Subsystem_004a289f(g_HdcBackBuffer,&local_880.left,iVar13,val_5);
              Palette_Subsystem_004a0466
                        (g_HdcBackBuffer,&local_880.left,local_8d4,local_8d0,DAT_006fe438);
              BitBlt(local_8c4,0,0,local_880.right,local_880.bottom,g_HdcBackBuffer,0,0,0xcc0020);
            }
            else {
              local_8d8 = Ai_Subsystem_004b5de4(match_count,card_idx);
              pHVar3 = GetParent(hwnd);
              if (pHVar3 == g_AiDecisionMatrix_Row) {
                local_8dc = 0;
              }
              else {
                local_8dc = local_8d8 & 4;
                local_8e0 = Ai_Subsystem_004b5b6f(match_count,card_idx);
              }
              Ai_Subsystem_004b673e(match_count,card_idx);
              Palette_Subsystem_004a1e09(g_HdcBackBuffer,&local_880.left,match_count,card_idx);
              val_5 = Ai_Subsystem_004b682f(match_count,card_idx);
              iVar13 = Ai_Subsystem_004b67ab(match_count,card_idx);
              Palette_Subsystem_004a289f(g_HdcBackBuffer,&local_880.left,iVar13,val_5);
              uval_6 = Ai_Subsystem_004b6c5b(match_count,card_idx);
              Palette_Subsystem_004a29c5(g_HdcBackBuffer,&local_880.left,uval_6 & 0x20000);
              arg_3 = Ai_Subsystem_004b6cc8(match_count,card_idx);
              Palette_Subsystem_004a2a5b(g_HdcBackBuffer,&local_880,arg_3);
              Palette_Subsystem_004a0466
                        (g_HdcBackBuffer,&local_880.left,match_count,card_idx,DAT_006fe438);
              uval_6 = Ai_Subsystem_004b613b(match_count,card_idx);
              if ((((uval_6 & 2) != 0) || (DAT_006fe440 != 0)) &&
                 (uval_6 = Ai_Subsystem_004b5de4(match_count,card_idx), (uval_6 & 1) != 0)) {
                Palette_Util_004a2edc(&DAT_006a4a20,DAT_006b2e1c,&local_880);
              }
              if ((local_8d8 & 2) != 0) {
                FUN_004f48f1(0x6a4a20,DAT_006b2e1c,&local_880);
              }
              BitBlt(local_8c4,0,0,local_880.right,local_880.bottom,g_HdcBackBuffer,0,0,0xcc0020);
            }
            player_idx = (void *)GetWindowLongA(hwnd,0xc);
            Ai_Subsystem_004b70fe(player_idx,match_count,card_idx);
            if (DAT_006808c4 != 0) {
              FUN_0046ba19(local_8c4,(int)&local_880,match_count,card_idx);
            }
          }
        }
        EndPaint(hwnd,&local_8c0);
      }
      DVar7 = GetTickCount();
      _DAT_00696738 = _DAT_00696738 + (DVar7 - local_870);
      LeaveCriticalSection((LPCRITICAL_SECTION)&g_ActiveCombatRoundCounter);
      return 0;
    }
    if (uMsg == 1) {
      local_810 = (LONG *)*lParam;
      if (local_810 == (LONG *)0x0) {
        return -1;
      }
      match_count = *local_810;
      card_idx = local_810[1];
      SetWindowLongA(hwnd,0,match_count);
      SetWindowLongA(hwnd,4,card_idx);
      slot_idx = (HWND)0x0;
      SetWindowLongA(hwnd,8,0);
      player_idx = malloc(0x120);
      SetWindowLongA(hwnd,0xc,(LONG)player_idx);
      SetWindowLongA(hwnd,0x10,0);
      if (player_idx == (void *)0x0) {
        return -1;
      }
      memset(player_idx,0,0x120);
      return 0;
    }
    if (uMsg == 2) {
      player_idx = (void *)GetWindowLongA(hwnd,0xc);
      free(player_idx);
      return 0;
    }
    if (uMsg == 3) {
      LVar12 = 0;
      UVar10 = 0x410;
      pHVar3 = GetParent(hwnd);
      SendMessageA(pHVar3,UVar10,(WPARAM)hwnd,LVar12);
      return 0;
    }
  }
  else if (uMsg < 0x21) {
    if (uMsg == 0x20) {
      LVar9 = UI_WndProc_004f4fb8(hwnd,0x20,(WPARAM)wParam,(LPARAM)lParam);
      return LVar9;
    }
    if (uMsg == 0x14) {
      return 1;
    }
  }
  else if (uMsg < 0x117) {
    if (uMsg == 0x116) {
      match_count = GetWindowLongA(hwnd,0);
      card_idx = GetWindowLongA(hwnd,4);
      local_940 = Ai_Subsystem_004b5de4(match_count,card_idx);
      local_940 = local_940 & 4;
      if (local_940 != 0) {
        Ai_Subsystem_004b5b6f(match_count,card_idx);
      }
      local_938 = Ai_Subsystem_004b5b6f(match_count,card_idx);
      local_93c = FUN_0046ab25(hwnd);
      local_948 = Ai_Subsystem_004b6288(match_count,card_idx);
      local_948 = local_948 & 0x40;
      local_94c = Ai_Subsystem_004b5d2e(match_count,card_idx);
      local_944 = Ai_Subsystem_004b5c4b(match_count,card_idx);
      local_924 = Ai_Subsystem_004b5cbb(match_count,card_idx);
      local_930 = Ai_Subsystem_004b6432(match_count,card_idx);
      local_930 = local_930 & 0x40000;
      local_934 = *(uint32_t *)(&g_MasterCardSubtypeTable + local_944 * 0x34) & 0x1000;
      uval_6 = Ai_Subsystem_004b613b(match_count,card_idx);
      local_950 = GetParent(hwnd);
      local_928 = Ai_Subsystem_004b6e3b(match_count,card_idx);
      Ai_Subsystem_004b74b1(&local_92c,&local_954);
      if (local_944 != local_928) {
        AppendMenuA(DAT_00538db4,0x10,(UINT_PTR)DAT_00538db0,s_Original_type_00524c5c);
        val_5 = CardIDFromType(local_928);
        ModifyMenuA(DAT_00538db0,0x72,0,0x72,*(LPCSTR *)(&DAT_006b3074 + val_5 * 0x98));
      }
      if (g_DuelArenaStatusFlags == 2) {
        AppendMenuA(DAT_00538db4,0,0x6e,s_Show_full_card_R_DblClk_00524c6c);
      }
      else {
        AppendMenuA(DAT_00538db4,0,0x6e,s_View_in_full_card_00524c84);
      }
      if (((((uval_6 & 1) != 0) && (local_934 != 0)) &&
          (pHVar3 = GetParent(hwnd), pHVar3 == g_TurnPriorityState)) &&
         (AppendMenuA(DAT_00538db4,0,0x70,s_Don_t_auto_tap_this_card_00524c98), local_930 != 0)) {
        CheckMenuItem(DAT_00538db4,0x70,8);
      }
      AppendMenuA(DAT_00538db4,0,0x73,s_Show_ID_tags_Ctrl_T_00524cb4);
      if (DAT_006fe438 != 0) {
        CheckMenuItem(DAT_00538db4,0x73,8);
      }
      AppendMenuA(DAT_00538db4,0,0x74,s_Show_invisible_effects_Ctrl_I_00524cc8);
      if (DAT_006fe43c != 0) {
        CheckMenuItem(DAT_00538db4,0x74,8);
      }
      AppendMenuA(DAT_00538db4,0,0x75,s_Show_all_cards__summoning_sickne_00524ce8);
      if (DAT_006fe440 != 0) {
        CheckMenuItem(DAT_00538db4,0x75,8);
      }
      AppendMenuA(DAT_00538db4,0,0x71,s_Help____00524d14);
      if ((DAT_0068a718 != 0) && (DAT_006b1578 != 0)) {
        if (local_94c == 0) {
          AppendMenuA(DAT_00538db4,0x800,0,(LPCSTR)0x0);
          AppendMenuA(DAT_00538db4,0,0x262,s__M__Add_mana_for_this_card_00524d1c);
          AppendMenuA(DAT_00538db4,0,0x264,s__B__Bury_this_card_00524d38);
        }
        else {
          AppendMenuA(DAT_00538db4,0x800,0,(LPCSTR)0x0);
          AppendMenuA(DAT_00538db4,0,0x262,s__M__Add_mana_for_this_card_00524d4c);
          AppendMenuA(DAT_00538db4,0,0x263,s__T__Tap_untap_this_card_00524d68);
          AppendMenuA(DAT_00538db4,0,0x264,s__B__Bury_this_card_00524d80);
          AppendMenuA(DAT_00538db4,0,0x266,s__X__Increment_counters_for_this_c_00524d94);
        }
      }
      return 0;
    }
    if (uMsg == 0x111) {
      match_count = GetWindowLongA(hwnd,0);
      card_idx = GetWindowLongA(hwnd,4);
      slot_idx = (HWND)GetWindowLongA(hwnd,8);
      local_418 = match_count;
      local_414 = card_idx;
      pHVar3 = GetParent(hwnd);
      if (pHVar3 == g_AiDecisionMatrix_Row) {
        local_410 = hwnd;
        Glue_Subsystem_004ef849(g_TurnPriorityState,&local_418,(int32_t *)0x0,local_408);
      }
      else {
        local_408[0] = hwnd;
        FUN_00483139(g_AiDecisionMatrix_Row,&local_418,(int32_t *)0x0,&local_410,(int32_t *)0x0);
      }
      uval_6 = (uint32_t)wParam & 0xffff;
      if (uval_6 < 0x263) {
        if (uval_6 == 0x262) {
          if (DAT_0068a718 != 0) {
            local_40c = *(int *)(&g_CardSlot_CardId + match_count * 0x5b20 + card_idx * 0x120);
            val_5 = (int)(char)(&g_MasterCardSubTypeTable2)[local_40c * 0x34];
            iVar13 = Rules_CalculateManaCostReduction((&g_MasterCardColorTable)
                                  [*(int *)(&g_CardSlot_CardId + match_count * 0x5b20 + card_idx * 0x120
                                           ) * 0x34]);
            FUN_0040d875(match_count,iVar13,val_5);
            val_5 = abs((int)(char)(&g_MasterCardManaCostTable)[local_40c * 0x34]);
            FUN_0040d875(match_count,0,val_5);
            Ai_Subsystem_004b584e();
            Duel_RefreshAllWindows(0,0xff);
          }
        }
        else {
          switch(uval_6) {
          case 100:
          case 0x6d:
            g_AiTemporaryCardState = 0;
            FUN_0046aa75(hwnd);
            break;
          case 0x65:
            Ai_Subsystem_004b74b1((int32_t *)0x0,local_53c);
            val_5 = FUN_004726c5(match_count,card_idx);
            if (val_5 != 0) {
              local_53c[1] = 0xffffffff;
              *(uint32_t *)(&g_CardSlot_Flags + match_count * 0x5b20 + card_idx * 0x120) =
                   *(uint32_t *)(&g_CardSlot_Flags + match_count * 0x5b20 + card_idx * 0x120) | 4;
              (&g_CardSlot_ColorMask)[match_count * 0x5b20 + card_idx * 0x120] = 0xff;
              Ai_Subsystem_004b42dc();
              if ((local_53c[0] < 0x15) || (0x1d < local_53c[0])) {
                LVar12 = 0;
                pLVar11 = &local_418;
                UVar10 = 0x436;
                pHVar3 = GetParent(hwnd);
                SendMessageA(pHVar3,UVar10,(WPARAM)pLVar11,LVar12);
              }
              else {
                SendMessageA(g_AiDecisionMatrix_Row,0x412,0,0);
              }
            }
            break;
          case 0x66:
            val_5 = Ai_Subsystem_004b5b6f(match_count,card_idx);
            if (val_5 != -1) {
              SendMessageA(hwnd,0x111,0x69,0);
            }
            *(uint32_t *)(&g_CardSlot_Flags + match_count * 0x5b20 + card_idx * 0x120) =
                 *(uint32_t *)(&g_CardSlot_Flags + match_count * 0x5b20 + card_idx * 0x120) & 0xfffffffb;
            (&g_CardSlot_ColorMask)[match_count * 0x5b20 + card_idx * 0x120] = 0xff;
            Ai_Subsystem_004b42dc();
            if (hwnd == local_410) {
              SendMessageA(g_AiDecisionMatrix_Row,0x412,0,0);
            }
            else {
              LVar12 = 0;
              pLVar11 = &local_418;
              UVar10 = 0x436;
              pHVar3 = GetParent(hwnd);
              SendMessageA(pHVar3,UVar10,(WPARAM)pLVar11,LVar12);
            }
            break;
          case 0x68:
            SendMessageA(hwnd,0x111,0x69,0);
          case 0x67:
            val_5 = FUN_004726c5(match_count,card_idx);
            if (val_5 != 0) {
              memcpy(local_624,&DAT_006feec0,0xe8);
              GetWindowTextA(g_AiPlayerHandDifferential,local_69c,100);
              local_628 = DAT_006b1578;
              local_634 = Duel_ChooseTarget
                                    (0,0,1,0x200,2,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0,2,0,
                                     s_Band_with_which_attacker__00524bcc,1,&local_630);
              DAT_006b1578 = local_628;
              if (local_634 != 0) {
                uval_6 = Ai_Subsystem_004b5de4(local_630,local_62c);
                if ((uval_6 & 4) == 0) {
                  UpdateWindow(g_MainAppHwnd);
                  Ai_Subsystem_004b5501(s_That_isn_t_an_attacker_00524bf8);
                  UpdateWindow(DAT_007006b0);
                  Sleep(2000);
                }
                else {
                  val_5 = FUN_0048225c(match_count,card_idx);
                  if (val_5 == 0) {
                    UpdateWindow(g_MainAppHwnd);
                    Ai_Subsystem_004b5501(s_Illegal_band_00524be8);
                    UpdateWindow(DAT_007006b0);
                    Sleep(2000);
                  }
                  else {
                    local_638 = Ai_Subsystem_004b5b6f(local_630,local_62c);
                    if (local_638 == -1) {
                      local_638 = local_62c;
                      val_5 = local_638;
                      *(uint32_t *)(&g_CardSlot_Flags + match_count * 0x5b20 + card_idx * 0x120) =
                           *(uint32_t *)(&g_CardSlot_Flags + match_count * 0x5b20 + card_idx * 0x120) | 4;
                      local_638._0_1_ = (uint8_t)local_62c;
                      (&g_CardSlot_ColorMask)[match_count * 0x5b20 + card_idx * 0x120] =
                           (uint8_t)local_638;
                      *(uint32_t *)(&g_CardSlot_Flags + local_630 * 0x5b20 + local_62c * 0x120) =
                           *(uint32_t *)(&g_CardSlot_Flags + local_630 * 0x5b20 + local_62c * 0x120) | 4
                      ;
                      (&g_CardSlot_ColorMask)[local_630 * 0x5b20 + local_62c * 0x120] =
                           (uint8_t)local_638;
                      local_638 = val_5;
                      Ai_Subsystem_004b42dc();
                      SendMessageA(hwnd,0x432,0,0);
                      BVar8 = IsWindowVisible(g_AiDecisionMatrix_Row);
                      if (BVar8 == 0) {
                        LVar12 = 0;
                        wParam_00 = &local_630;
                        UVar10 = 0x436;
                        pHVar3 = GetParent(local_408[0]);
                        SendMessageA(pHVar3,UVar10,(WPARAM)wParam_00,LVar12);
                      }
                      else {
                        SendMessageA(g_AiDecisionMatrix_Row,0x412,0,0);
                        SendMessageA(g_AiDecisionMatrix_Row,0x436,(WPARAM)&local_630,0);
                      }
                    }
                    else {
                      *(uint32_t *)(&g_CardSlot_Flags + match_count * 0x5b20 + card_idx * 0x120) =
                           *(uint32_t *)(&g_CardSlot_Flags + match_count * 0x5b20 + card_idx * 0x120) | 4;
                      (&g_CardSlot_ColorMask)[match_count * 0x5b20 + card_idx * 0x120] =
                           (uint8_t)local_638;
                      Ai_Subsystem_004b42dc();
                      SendMessageA(hwnd,0x432,0,0);
                      BVar8 = IsWindowVisible(g_AiDecisionMatrix_Row);
                      if (BVar8 != 0) {
                        SendMessageA(g_AiDecisionMatrix_Row,0x412,0,0);
                      }
                    }
                  }
                }
              }
              memcpy(&DAT_006feec0,local_624,0xe8);
              FUN_00477d73(DAT_007006b0,local_60c,local_610);
              Ai_Subsystem_004b553f(local_69c);
            }
            break;
          case 0x69:
            local_6a0 = Ai_Subsystem_004b5b6f(match_count,card_idx);
            for (local_6a4 = 0; local_6a4 < (int)(&g_PlayerActiveCardCount)[match_count];
                local_6a4 = local_6a4 + 1) {
              val_5 = Ai_Subsystem_004b5c4b(match_count,local_6a4);
              if (((val_5 != -1) &&
                  (uval_6 = Ai_Subsystem_004b5de4(match_count,local_6a4), (uval_6 & 4) != 0)) &&
                 (val_5 = Ai_Subsystem_004b5b6f(match_count,local_6a4), val_5 == local_6a0)) {
                (&g_CardSlot_ColorMask)[local_6a4 * 0x120 + match_count * 0x5b20] = 0xff;
                Ai_Subsystem_004b42dc();
                local_418 = match_count;
                local_414 = local_6a4;
                BVar8 = IsWindowVisible(g_AiDecisionMatrix_Row);
                if (BVar8 == 0) {
                  LVar12 = 0;
                  pLVar11 = &local_418;
                  UVar10 = 0x436;
                  pHVar3 = GetParent(local_408[0]);
                  SendMessageA(pHVar3,UVar10,(WPARAM)pLVar11,LVar12);
                }
                else {
                  SendMessageA(g_AiDecisionMatrix_Row,0x436,(WPARAM)&local_418,0);
                }
              }
            }
            BVar8 = IsWindowVisible(g_AiDecisionMatrix_Row);
            if (BVar8 != 0) {
              SendMessageA(g_AiDecisionMatrix_Row,0x412,0,0);
            }
            break;
          case 0x6a:
          case 0x6b:
            memcpy(local_790,&DAT_006feec0,0xe8);
            GetWindowTextA(g_AiPlayerHandDifferential,local_808,100);
            local_794 = DAT_006b1578;
            local_7a0 = Duel_ChooseTarget
                                  (0,1,0,0x200,2,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0,2,0,
                                   s_Block_which_attacker__00524c10,1,&local_79c);
            DAT_006b1578 = local_794;
            if (local_7a0 != 0) {
              uval_6 = Ai_Subsystem_004b5de4(local_79c,local_798);
              if ((uval_6 & 4) == 0) {
                UpdateWindow(g_MainAppHwnd);
                Ai_Subsystem_004b5501(s_That_isn_t_an_attacker_00524c38);
                UpdateWindow(DAT_007006b0);
                Sleep(2000);
              }
              else {
                val_5 = FUN_00472e08(match_count,card_idx,local_79c,local_798);
                if (val_5 == 0) {
                  UpdateWindow(g_MainAppHwnd);
                  Ai_Subsystem_004b5501(s_Illegal_block_00524c28);
                  UpdateWindow(DAT_007006b0);
                  Sleep(2000);
                }
                else {
                  local_7a4 = Ai_Subsystem_004b5b6f(local_79c,local_798);
                  local_6a8 = local_7a4;
                  if (local_7a4 == -1) {
                    local_6a8 = local_798;
                  }
                  *(uint32_t *)(&g_CardSlot_Flags + match_count * 0x5b20 + card_idx * 0x120) =
                       *(uint32_t *)(&g_CardSlot_Flags + match_count * 0x5b20 + card_idx * 0x120) | 8;
                  (&g_CardSlot_ColorMask)[match_count * 0x5b20 + card_idx * 0x120] =
                       (uint8_t)local_6a8;
                  Ai_Subsystem_004b42dc();
                  BVar8 = IsWindowVisible(g_AiDecisionMatrix_Row);
                  if ((BVar8 == 0) || (pHVar3 = GetParent(hwnd), pHVar3 == g_AiDecisionMatrix_Row)) {
                    LVar12 = 0;
                    pLVar11 = &local_418;
                    UVar10 = 0x436;
                    pHVar3 = GetParent(hwnd);
                    SendMessageA(pHVar3,UVar10,(WPARAM)pLVar11,LVar12);
                  }
                  else {
                    SendMessageA(g_AiDecisionMatrix_Row,0x412,0,0);
                  }
                }
              }
            }
            memcpy(&DAT_006feec0,local_790,0xe8);
            FUN_00477d73(DAT_007006b0,local_778,local_77c);
            Ai_Subsystem_004b553f(local_808);
            break;
          case 0x6c:
            *(uint32_t *)(&g_CardSlot_Flags + match_count * 0x5b20 + card_idx * 0x120) =
                 *(uint32_t *)(&g_CardSlot_Flags + match_count * 0x5b20 + card_idx * 0x120) & 0xfffffff7;
            (&g_CardSlot_ColorMask)[match_count * 0x5b20 + card_idx * 0x120] = 0xff;
            Ai_Subsystem_004b42dc();
            if (hwnd == local_410) {
              SendMessageA(g_AiDecisionMatrix_Row,0x412,0,0);
            }
            else {
              LVar12 = 0;
              pLVar11 = &local_418;
              UVar10 = 0x436;
              pHVar3 = GetParent(hwnd);
              SendMessageA(pHVar3,UVar10,(WPARAM)pLVar11,LVar12);
            }
            break;
          case 0x6e:
            local_41c = Ai_Subsystem_004b5cbb(match_count,card_idx);
            local_424 = match_count;
            local_420 = card_idx;
            SendMessageA(DAT_0069f744,0x401,local_41c,(LPARAM)&local_424);
            break;
          case 0x6f:
            pHVar3 = GetParent(hwnd);
            if ((pHVar3 == g_AiLookaheadTreeRoot) || (pHVar3 = GetParent(hwnd), pHVar3 == g_AiDuelTurnState)) {
              LVar12 = 0;
              UVar10 = 0x400;
              pHVar3 = GetParent(hwnd);
              SendMessageA(pHVar3,UVar10,(WPARAM)hwnd,LVar12);
            }
            break;
          case 0x70:
            uval_6 = Ai_Subsystem_004b6432(match_count,card_idx);
            local_428 = (uint32_t)((uval_6 & 0x40000) == 0);
            if (local_428 == 0) {
              *(uint32_t *)(&g_CardSlot_Flags + match_count * 0x5b20 + card_idx * 0x120) =
                   *(uint32_t *)(&g_CardSlot_Flags + match_count * 0x5b20 + card_idx * 0x120) & 0xfffbffff;
            }
            else {
              *(uint32_t *)(&g_CardSlot_Flags + match_count * 0x5b20 + card_idx * 0x120) =
                   *(uint32_t *)(&g_CardSlot_Flags + match_count * 0x5b20 + card_idx * 0x120) | 0x40000;
            }
            EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
            *(int32_t *)(&g_AiEvaluationTimeout + match_count * 0x5b20 + card_idx * 0x120) =
                 *(int32_t *)(&g_CardSlot_Flags + match_count * 0x5b20 + card_idx * 0x120);
            LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
            InvalidateRect(hwnd,(RECT *)0x0,1);
            break;
          case 0x71:
            local_42c = Ai_Subsystem_004b5cbb(match_count,card_idx);
            if (local_42c == DAT_006ff2e8) {
              local_42c = 0xc1b;
            }
            if (local_42c != 0xffffffff) {
              strcpy(local_534,&g_GameInstallDirectory);
              strcat(local_534,s__duel_hlp_00524bc0);
              WinHelpA(g_MainAppHwnd,local_534,1,local_42c);
            }
            break;
          case 0x73:
            SendMessageA(g_MainAppHwnd,0x111,0x279,0);
            break;
          case 0x74:
            SendMessageA(g_MainAppHwnd,0x111,0x27a,0);
            break;
          case 0x75:
            SendMessageA(g_MainAppHwnd,0x111,0x27c,0);
          }
        }
      }
      else if (uval_6 == 0x263) {
        if (DAT_0068a718 != 0) {
          *(uint32_t *)(&g_CardSlot_Flags + match_count * 0x5b20 + card_idx * 0x120) =
               *(uint32_t *)(&g_CardSlot_Flags + match_count * 0x5b20 + card_idx * 0x120) ^ 0x10;
          Duel_RefreshAllWindows(0,0xff);
        }
      }
      else if (uval_6 == 0x264) {
        if (DAT_0068a718 != 0) {
          local_80c = *(int32_t *)(&g_PlayerManaPoolAvailable + g_ScWillyScore * 4 + g_TurnPlayer * 0x98)
          ;
          *(uint32_t *)(&g_PlayerManaPoolAvailable + g_ScWillyScore * 4 + g_TurnPlayer * 0x98) =
               *(uint32_t *)(&g_PlayerManaPoolAvailable + g_ScWillyScore * 4 + g_TurnPlayer * 0x98) & 0xfffe;
          *(uint32_t *)(&g_CardSlot_Abilities1 + match_count * 0x5b20 + card_idx * 0x120) =
               *(uint32_t *)(&g_CardSlot_Abilities1 + match_count * 0x5b20 + card_idx * 0x120) | 8;
          Pic_Subsystem_0044867e(match_count,card_idx,2);
          *(int32_t *)(&g_PlayerManaPoolAvailable + g_ScWillyScore * 4 + g_TurnPlayer * 0x98) = local_80c
          ;
          Duel_RefreshAllWindows(0,0xff);
        }
      }
      else if ((uval_6 == 0x266) && (DAT_0068a718 != 0)) {
        *(int *)(&DAT_006a5f7c + match_count * 0x5b20 + card_idx * 0x120) =
             *(int *)(&DAT_006a5f7c + match_count * 0x5b20 + card_idx * 0x120) + 1;
        Duel_RefreshAllWindows(0,0xff);
      }
      return 0;
    }
  }
  else if (uMsg < 0x202) {
    if (uMsg == 0x201) {
      match_count = GetWindowLongA(hwnd,0);
      card_idx = GetWindowLongA(hwnd,4);
      slot_idx = (HWND)GetWindowLongA(hwnd,8);
      UVar10 = GetDoubleClickTime();
      LVar2 = GetMessageTime();
      DVar7 = GetTickCount();
      Sleep(UVar10 - (LVar2 - DVar7));
      local_828 = PeekMessageA(&local_844,hwnd,0x203,0x203,0);
      pHVar3 = GetParent(hwnd);
      if ((pHVar3 == g_TurnPriorityState) || (pHVar3 = GetParent(hwnd), pHVar3 == g_AiSelectedActionCode)) {
        if (slot_idx == (HWND)0x0) {
          local_85c = hwnd;
        }
        else {
          local_85c = slot_idx;
          pHVar3 = local_85c;
          do {
            local_85c = pHVar3;
            local_860 = (HWND)FUN_0046bc92(local_85c);
            pHVar3 = local_860;
          } while (local_860 != (HWND)0x0);
          local_860 = (HWND)0x0;
        }
        GetWindowRect(local_85c,&local_854);
        local_858 = GetWindow(local_85c,3);
        SendMessageA(local_85c,0x112,0xf012,0);
        GetWindowRect(local_85c,&local_820);
        val_5 = abs(local_854.top - local_820.top);
        iVar13 = abs(local_854.left - local_820.left);
        if (val_5 + iVar13 < 5) {
          local_824 = 0;
          SetWindowPos(local_85c,local_858,0,0,0,0,3);
        }
        else {
          local_824 = 1;
        }
      }
      else {
        local_824 = 0;
      }
      if (local_824 == 0) {
        Ai_Subsystem_004b74b1(&local_864,&local_868);
        val_5 = FUN_0046ab25(hwnd);
        if (val_5 != 0) {
          g_AiTemporaryCardState = local_828;
          FUN_0046aa75(hwnd);
        }
      }
      return 0;
    }
    if (uMsg == 0x11f) {
      if (((uint32_t)wParam >> 0x10 == 0xffff) && (lParam == (int *)0x0)) {
        local_960 = GetMenuItemCount(DAT_00538db4);
        while (local_960 != 0) {
          RemoveMenu(DAT_00538db4,0,0x400);
          local_960 = local_960 + -1;
        }
        pHVar3 = GetParent(hwnd);
        if ((pHVar3 != g_AiLookaheadTreeRoot) && (pHVar3 = GetParent(hwnd), pHVar3 != g_AiDuelTurnState)) {
          pHVar3 = (HWND)GetWindowLongA(hwnd,0x10);
          SetWindowPos(hwnd,pHVar3,0,0,0,0,3);
        }
      }
      return 0;
    }
  }
  else if (uMsg < 0x312) {
    if (0x30e < uMsg) {
      LVar9 = GDI_RealizePaletteTree_Magic(hwnd,uMsg,(HWND)wParam,lParam);
      return LVar9;
    }
    if (uMsg == 0x204) {
      local_8fc = 1;
      match_count = GetWindowLongA(hwnd,0);
      card_idx = GetWindowLongA(hwnd,4);
      pHVar3 = GetParent(hwnd);
      if ((pHVar3 != g_AiLookaheadTreeRoot) && (pHVar3 = GetParent(hwnd), pHVar3 != g_AiDuelTurnState)) {
        local_900 = GetWindow(hwnd,3);
        SetWindowLongA(hwnd,0x10,(LONG)local_900);
        BringWindowToTop(hwnd);
      }
      if (g_DuelArenaStatusFlags == 2) {
        UVar10 = GetDoubleClickTime();
        Sleep(UVar10);
        BVar8 = PeekMessageA(&local_91c,hwnd,0x206,0x206,0);
        if (BVar8 != 0) {
          local_8fc = 0;
        }
      }
      if ((match_count != -1) && (card_idx == -1)) {
        local_8fc = 0;
      }
      if (local_8fc != 0) {
        local_8f8.x = (uint32_t)lParam & 0xffff;
        local_8f8.y = (uint32_t)lParam >> 0x10;
        ClientToScreen(hwnd,&local_8f8);
        val_5 = GetSystemMetrics(0xd);
        local_8f8.x = local_8f8.x + val_5;
        val_5 = local_8f8.y + 4;
        iVar13 = local_8f8.y + 5;
        local_8f8.y = val_5;
        SetRect(&local_8f0,local_8f8.x,val_5,local_8f8.x + 1,iVar13);
        TrackPopupMenu(DAT_00538db4,2,local_8f8.x,local_8f8.y,0,hwnd,(RECT *)0x0);
      }
      return 0;
    }
    if (uMsg == 0x205) {
      pHVar3 = GetParent(hwnd);
      if ((pHVar3 != g_AiLookaheadTreeRoot) && (pHVar3 = GetParent(hwnd), pHVar3 != g_AiDuelTurnState)) {
        local_920 = (HWND)GetWindowLongA(hwnd,0x10);
        SetWindowPos(hwnd,local_920,0,0,0,0,3);
      }
      return 0;
    }
    if (uMsg == 0x206) {
      match_count = GetWindowLongA(hwnd,0);
      card_idx = GetWindowLongA(hwnd,4);
      if ((match_count == -1) || (card_idx != -1)) {
        SendMessageA(hwnd,0x111,0x6e,0);
      }
      return 0;
    }
  }
  else {
    switch(uMsg) {
    case 0x400:
      match_count = GetWindowLongA(hwnd,0);
      card_idx = GetWindowLongA(hwnd,4);
      LVar9 = Ai_Subsystem_004b5cbb(match_count,card_idx);
      return LVar9;
    case 0x401:
      match_count = GetWindowLongA(hwnd,0);
      LVar2 = GetWindowLongA(hwnd,4);
      if (wParam != (LONG *)0x0) {
        *wParam = match_count;
        wParam[1] = LVar2;
      }
      return 0;
    case 0x402:
      slot_idx = (HWND)GetWindowLongA(hwnd,8);
      local_2e0 = wParam;
      if ((HWND)wParam != slot_idx) {
        if (wParam == (LONG *)0x0) {
          BringWindowToTop(hwnd);
        }
        slot_idx = (HWND)local_2e0;
        SetWindowLongA(hwnd,8,(LONG)local_2e0);
      }
      return 0;
    case 0x403:
      LVar2 = GetWindowLongA(hwnd,8);
      return LVar2;
    case 0x404:
      match_count = GetWindowLongA(hwnd,0);
      card_idx = GetWindowLongA(hwnd,4);
      player_idx = (void *)GetWindowLongA(hwnd,0xc);
      if ((match_count != -1) && (card_idx == -1)) {
        return 0;
      }
      Ai_Subsystem_004b70fe(local_400,match_count,card_idx);
      val_5 = memcmp(player_idx,local_400,0x120);
      return val_5;
    case 0x432:
      BVar8 = IsWindowVisible(hwnd);
      if (BVar8 == 0) {
        return 0;
      }
      match_count = GetWindowLongA(hwnd,0);
      card_idx = GetWindowLongA(hwnd,4);
      player_idx = (void *)GetWindowLongA(hwnd,0xc);
      Ai_Subsystem_004b70fe(local_2bc,match_count,card_idx);
      if ((match_count != -1) && (card_idx == -1)) {
        return 0;
      }
      val_5 = FUN_0046adbc((int)player_idx,(int)local_2bc);
      if (val_5 == 0) {
        InvalidateRect(hwnd,(RECT *)0x0,0);
      }
      else if ((DAT_006fe42c == 0) ||
              (val_5 = FUN_0046b3e6((int)player_idx,(int)local_2bc), val_5 != 0)) {
        if (*(int *)((int)player_idx + 0x54) != local_268) {
          local_2c0 = Ai_Subsystem_004b5cbb(match_count,card_idx);
          uval_6 = Ai_Subsystem_004b5de4(match_count,card_idx);
          if ((uval_6 & 2) == 0) {
            if ((((DAT_006ff2dc == local_2c0) || (DAT_006ff2e8 == local_2c0)) ||
                (DAT_0068a694 == local_2c0)) ||
               (((DAT_00695e94 == local_2c0 || (DAT_006a2848 == local_2c0)) ||
                (DAT_0068a70c == local_2c0)))) {
              InvalidateRect(hwnd,(RECT *)0x0,0);
            }
            else if (local_2c0 != 0xffffffff) {
              local_2d4 = GetDC(hwnd);
              GDI_RealizeAndFlushPalette_Magic(local_2d4);
              GetClientRect(hwnd,&local_2d0);
              val_5 = Ai_Subsystem_004b65bf(match_count,card_idx);
              uval_6 = (uint32_t)(val_5 == match_count);
              val_5 = Ai_Subsystem_004b673e(match_count,card_idx);
              Palette_Subsystem_004a11fa
                        (local_2d4,&local_2d0.left,*(char **)(&DAT_006b3078 + local_2c0 * 0x98),
                         val_5,uval_6);
              ReleaseDC(hwnd,local_2d4);
              *(int *)((int)player_idx + 0x54) = local_268;
            }
          }
          else {
            InvalidateRect(hwnd,(RECT *)0x0,0);
          }
        }
      }
      else {
        InvalidateRect(hwnd,(RECT *)0x0,0);
      }
      return 0;
    case 0x437:
      local_104[0] = 0x20;
      local_104[1] = 0x400;
      local_104[2] = 0x40;
      local_104[3] = 0x80;
      local_104[4] = 0x100;
      local_104[5] = 0x200;
      local_104[6] = 1;
      local_104[7] = 2;
      local_104[8] = 4;
      local_104[9] = 8;
      local_104[10] = 0x10;
      local_104[0xb] = 0x800;
      local_104[0xc] = 0x1000;
      local_104[0xd] = 0x2000;
      local_104[0xe] = 0x4000;
      local_104[0xf] = 0x8000;
      local_104[0x10] = 0x10000;
      local_a0[0] = s_Flying_00524920;
      local_a0[1] = &DAT_0052492c;
      local_a0[2] = s_Banding_00524938;
      local_a0[3] = s_Trample_00524948;
      local_90 = s_First_strike_00524960;
      local_8c = s_Regenerates_0052497c;
      local_88 = s_Swampwalk_00524994;
      local_84 = s_Islandwalk_005249ac;
      local_80 = s_Forestwalk_005249c4;
      local_7c = s_Mountainwalk_005249e0;
      local_78 = s_Plainswalk_005249fc;
      local_74 = s_Protection_from_black_00524a20;
      local_70 = s_Protection_from_blue_00524a50;
      local_6c = s_Protection_from_green_00524a80;
      local_68 = s_Protection_from_red_00524aac;
      local_64 = s_Protection_from_white_00524ad8;
      local_60 = s_Protection_from_artifacts_00524b0c;
      local_ac = 0x11;
      match_count = GetWindowLongA(hwnd,0);
      card_idx = GetWindowLongA(hwnd,4);
      local_3c = Ai_Subsystem_004b5cbb(match_count,card_idx);
      local_114 = (uint32_t)lParam & 0xffff;
      local_110 = (uint32_t)lParam >> 0x10;
      if ((match_count == -1) || (card_idx != -1)) {
        local_10c = 0;
        GetClientRect(hwnd,&local_54);
        uval_1 = Ai_Subsystem_004b5de4(match_count,card_idx);
        uval_6 = local_114;
        if ((uval_1 & 2) != 0) {
          local_19c = local_114;
          local_114 = local_110;
          local_110 = local_54.bottom - uval_6;
        }
        local_194 = Ai_Subsystem_004b6288(match_count,card_idx);
        local_44 = -1;
        if (local_194 != 0) {
          local_108 = 0;
          while ((local_108 < local_ac && (local_44 == -1))) {
            Palette_Subsystem_004a0f97(&local_190,local_104[local_108],&local_54.left,local_194);
            pt.y = local_110;
            pt.x = local_114;
            BVar8 = PtInRect(&local_190,pt);
            if (BVar8 != 0) {
              local_44 = local_108;
            }
            local_108 = local_108 + 1;
          }
        }
        local_58 = Ai_Subsystem_004b5a46(match_count,card_idx);
        Ai_Subsystem_004b5ab8(match_count,card_idx,&local_5c,local_104 + 0x11,&local_118);
        Palette_Subsystem_004a080b(&local_bc,&local_54.left,local_58);
        target_idx = Ai_Subsystem_004b67ab(match_count,card_idx);
        val_5 = Ai_Subsystem_004b682f(match_count,card_idx);
        local_198 = (uint32_t)(val_5 == 0);
        local_40 = Ai_Subsystem_004b5bdd(match_count,card_idx);
        Palette_Subsystem_004a0392(&local_38,&local_54.left);
        local_11c = Ai_Subsystem_004b6cc8(match_count,card_idx);
        Palette_Subsystem_004a2aa3(&local_28,&local_54.left);
        local_a4 = Ai_Subsystem_004b6eab(match_count,card_idx);
        if ((((local_11c & 1) == 0) || ((local_11c & 2) == 0)) ||
           (pt_00.y = local_110, pt_00.x = local_114, BVar8 = PtInRect(&local_28,pt_00), BVar8 == 0)
           ) {
          if (local_44 == -1) {
            if ((local_40 < 1) ||
               (pt_01.y = local_110, pt_01.x = local_114, BVar8 = PtInRect(&local_38,pt_01),
               BVar8 == 0)) {
              if ((local_58 < 1) ||
                 (pt_02.y = local_110, pt_02.x = local_114, BVar8 = PtInRect(&local_bc,pt_02),
                 BVar8 == 0)) {
                if ((((int)(local_118 + local_104[0x11] + local_5c) < 1) ||
                    ((int)local_110 <= (local_54.bottom * 0x23) / 100)) ||
                   ((local_54.bottom * 0x3e) / 100 <= (int)local_110)) {
                  val_5 = Ai_Subsystem_004b65bf(match_count,card_idx);
                  if ((val_5 == match_count) || ((local_54.bottom * 0xc) / 100 <= (int)local_110)) {
                    if (((target_idx == 0) && (local_198 == 0)) ||
                       (((((int)local_114 <= (local_54.right * 5) / 100 ||
                          ((local_54.right * 0x5f) / 100 <= (int)local_114)) ||
                         ((int)local_110 <= (local_54.bottom * 0xf) / 100)) ||
                        ((local_54.bottom * 0x5f) / 100 <= (int)local_110)))) {
                      if (((local_a4 == 2) && ((local_54.right * 5) / 100 < (int)local_114)) &&
                         (((int)local_114 < (local_54.right * 0x5f) / 100 &&
                          (((local_54.bottom * 0xf) / 100 < (int)local_110 &&
                           ((int)local_110 < (local_54.bottom * 0x5f) / 100)))))) {
                        strcpy(local_180,s_Dying_00524ba4);
                        local_10c = 1;
                      }
                      else {
                        uval_6 = Ai_Subsystem_004b613b(match_count,card_idx);
                        if ((((uval_6 & 2) != 0) &&
                            (((uval_6 = Ai_Subsystem_004b5de4(match_count,card_idx), (uval_6 & 1) != 0 &&
                              ((local_54.right * 5) / 100 < (int)local_114)) &&
                             ((int)local_114 < (local_54.right * 0x5f) / 100)))) &&
                           (((local_54.bottom * 0xf) / 100 < (int)local_110 &&
                            ((int)local_110 < (local_54.bottom * 0x5f) / 100)))) {
                          strcpy(local_180,s_Summoning_sickness_00524bac);
                          local_10c = 1;
                        }
                      }
                    }
                    else {
                      local_180[0] = '\0';
                      if (target_idx != 0) {
                        strcat(local_180,s_Is_a_target_00524b80);
                      }
                      if ((target_idx != 0) && (local_198 != 0)) {
                        strcat(local_180,&DAT_00524b8c);
                      }
                      if (local_198 != 0) {
                        strcat(local_180,s_Can_t_target_this_00524b90);
                      }
                      local_10c = 1;
                    }
                  }
                  else {
                    strcpy(local_180,s_Card_is_not_controlled_by_owner_00524b60);
                    local_10c = 1;
                  }
                }
                else {
                  local_a8 = (local_54.right - local_54.left) / 3;
                  if ((int)local_114 < local_54.left + local_a8) {
                    FUN_0046b887(local_180,1,local_118);
                  }
                  else if ((int)local_114 < local_a8 * 2 + local_54.left) {
                    FUN_0046b887(local_180,2,local_104[0x11]);
                  }
                  else {
                    FUN_0046b887(local_180,3,local_5c);
                  }
                  local_10c = 1;
                }
              }
              else {
                UI_FormatCardCounterString(local_180,local_3c,local_58);
                local_10c = 1;
              }
            }
            else {
              sprintf(local_180,s_Damage___d_00524b54,local_40);
              local_10c = 1;
            }
          }
          else {
            strcpy(local_180,local_a0[local_44]);
            local_10c = 1;
          }
        }
        else {
          strcpy(local_180,s_This_card_will_untap_00524b3c);
          local_10c = 1;
        }
      }
      else {
        local_10c = 1;
        strcpy(local_180,s_Damage_to_player_00524b28);
      }
      if (local_10c != 0) {
        strcpy((char *)wParam,local_180);
      }
      if (g_DuelArenaStatusFlags == 2) {
        return local_10c;
      }
      SendMessageA(hwnd,0x111,0x6e,0);
      return local_10c;
    }
  }
  LVar9 = DefWindowProcA(hwnd,uMsg,(WPARAM)wParam,(LPARAM)lParam);
  return LVar9;
}




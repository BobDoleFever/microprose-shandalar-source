/*
 * sid/Magic.c - Reconstructed MicroProse Source Module
 * Program: MAGIC.EXE
 * Contained Functions: 83
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include "shandalar/shandalar.h"
/* Modular Shandalar Subsystem */

/*
 * Magic_ScanCards
 * Purpose: Scan all active cards on the battlefield for triggers and state changes.
 * Procedure:
 * 1. Increment the scan depth counter and check that depth is less than 10.
 * 2. Count active card slots for both players.
 * 3. Call the card script action callback for each active card.
 * 4. Update status flags and trigger pending continuous effects.
 */
/*
 * Decompiled function: Magic_ScanCards
 * Entry Point: 00473f06
 * Size: 864 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Magic_ScanCards(int player_id)

{
  int arg2;
  int uval_1;
  int val_2;
  int player_idx;
  int card_idx;
  int slot_idx;
  
  uval_1 = g_CardSlot_PowerBonus;
  _DAT_006b1584 = arg_1;
  _DAT_00627a0c = _DAT_00627a0c + 1;
  g_CardScanDepth = g_CardScanDepth + 1;
  if (9 < g_CardScanDepth) {
    assert(s___nScan<10_00525d00,s_G__NewMagic_sources_sid_Magic_c_00525ce0,0x7f5);
  }
  for (slot_idx = 0; slot_idx < 2; slot_idx = slot_idx + 1) {
    for (card_idx = 0; card_idx < 0x50; card_idx = card_idx + 1) {
      if (*(int *)(&g_CardSlot_CardId + slot_idx * 0x5b20 + card_idx * 0x120) != -1) {
        (&g_PlayerActiveCardCount)[slot_idx] = card_idx + 1;
      }
    }
  }
  for (player_idx = 0; (player_idx < 500 && (*(int *)(&g_CardDisplayOrder_Player + player_idx * 4) != -1));
      player_idx = player_idx + 1) {
    slot_idx = *(int *)(&g_CardDisplayOrder_Player + player_idx * 4);
    arg2 = *(int *)(&g_CardDisplayOrder_Slot + player_idx * 4);
    if (((*(int *)(&g_CardSlot_DisplayIndex + slot_idx * 0x5b20 + arg2 * 0x120) == player_idx) &&
        (*(int *)(&g_CardSlot_CardId + slot_idx * 0x5b20 + arg2 * 0x120) != -1)) &&
       ((((&g_CardSlot_Flags)[slot_idx * 0x5b20 + arg2 * 0x120] & 2) != 0 ||
        (((&g_CardSlot_Flags)[slot_idx * 0x5b20 + arg2 * 0x120] & 0x20) != 0)))) {
      g_CurrentScanningCardIndex = slot_idx * 0x80 + arg2;
      if ((*(int *)(&g_CardSlot_CardId + slot_idx * 0x5b20 + arg2 * 0x120) < 0) ||
         (g_MasterCardCount + 0x10 < *(int *)(&g_CardSlot_CardId + slot_idx * 0x5b20 + arg2 * 0x120))
         ) {
        Engine_ReportFatalError(s_ScanCard_error_00525d0c);
      }
      else {
        (**(code **)(&g_CardScriptCallbackTable +
                    *(int *)(&g_CardSlot_CardId + slot_idx * 0x5b20 + arg2 * 0x120) * 0x34))
                  (slot_idx,arg2,arg_1);
        if ((((arg_1 == 0x15) && (g_DefendingPlayer == slot_idx)) &&
            (((uint8_t)*(int *)(&g_CardSlot_Flags + slot_idx * 0x5b20 + arg2 * 0x120) & 0x14) ==
             4)) && (val_2 = Rules_ValidateCardTargetSlot(slot_idx,arg2), val_2 == 0)) {
          *(uint32_t *)(&g_CardSlot_Flags + slot_idx * 0x5b20 + arg2 * 0x120) =
               *(uint32_t *)(&g_CardSlot_Flags + slot_idx * 0x5b20 + arg2 * 0x120) | 0x10;
          g_PendingAttackersTargetSlot = 0xffffffff;
          Rules_ApplyContinuousDamage(slot_idx,arg2,0x81);
        }
      }
    }
  }
  if ((arg_1 == 0x15) && (g_DefendingPlayer == slot_idx)) {
    Rules_ProcessCombatDamageStep();
  }
  g_CardScanDepth = g_CardScanDepth + -1;
  if (g_GlobalEnchantmentCardId != -1) {
    (**(code **)(&g_CardScriptCallbackTable + g_GlobalEnchantmentCardId * 0x34))(0,0x4e,arg_1);
  }
  g_CardSlot_PowerBonus = uval_1;
  return;
}



/*
 * Magic_TriggerCardEvent
 * Purpose: Execute a card script function with the specified event code.
 * Procedure:
 * 1. Read the card definition pointer from the master table.
 * 2. Execute the script event handler.
 * 3. Return the result code to the calling function.
 */
/*
 * Decompiled function: Magic_TriggerCardEvent
 * Entry Point: 00474266
 * Size: 291 bytes
 */


int Magic_TriggerCardEvent(int player_id,int card_slot,int event_type,int arg_4,int arg_5)

{
  int uval_1;
  int val_2;
  int val_3;
  
  if (*(int *)(&g_CardSlot_CardId + arg_2 * 0x120 + arg_1 * 0x5b20) == -1) {
    val_2 = 0;
  }
  else {
    Magic_PayManaCost();
    uval_1 = g_CombatPhaseFlags;
    g_ActivePalette = 0;
    g_OverworldPlayerCoordX = arg_1;
    g_OverworldMapGrid = arg_2;
    DAT_007006c8 = arg_4;
    DAT_006b2d5c = arg_5;
    val_2 = (**(code **)(&g_CardScriptCallbackTable +
                        *(int *)(&g_CardSlot_CardId + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34))
                      (arg_1,arg_2,arg_3);
    if ((((val_2 != 99) && ((g_PlayerHandCardCount & 0x224) != 0)) &&
        ((arg_3 == 0x74 || (arg_3 == 0x73)))) &&
       (val_3 = Magic_ResolveSpellStack(arg_1,arg_2), val_3 == 0)) {
      g_CombatPhaseFlags = uval_1;
      Magic_TapCardForMana();
      return 0;
    }
    DAT_006b2e38 = g_ActivePalette;
    Magic_TapCardForMana();
  }
  return val_2;
}



/*
 * Magic_ResolveSpellStack
 * Purpose: Resolve the top spell or activated ability on the resolution stack.
 * Procedure:
 * 1. Check if the spell stack contains active entries.
 * 2. Execute the top spell effect function.
 * 3. Move the card to the graveyard or battlefield.
 * 4. Decrement the stack depth counter.
 */
/*
 * Decompiled function: Magic_ResolveSpellStack
 * Entry Point: 00474389
 * Size: 159 bytes
 */


bool Magic_ResolveSpellStack(int x,int arg2)

{
  bool flag_1;
  
  if (((&g_MasterCardFlagsTable)[*(int *)(&g_CardSlot_CardId + arg2 * 0x120 + x * 0x5b20) * 0x34] & 0x10)
      == 0) {
    flag_1 = false;
  }
  else {
    flag_1 = ((&g_MasterCardSubtypeTable)[*(int *)(&g_CardSlot_CardId + arg2 * 0x120 + x * 0x5b20) * 0x34] & 1
            ) == 0;
  }
  return flag_1;
}



/*
 * Magic_PayManaCost
 * Purpose: Check and deduct required mana from the active player mana pool.
 * Returns: 1 if mana was paid successfully, or 0 if mana was insufficient.
 */
/*
 * Decompiled function: Magic_PayManaCost
 * Entry Point: 00474428
 * Size: 182 bytes
 */


void Magic_PayManaCost(void)

{
  if (DAT_0052577c < 0x20) {
    *(int *)(&DAT_00676e40 + DAT_0052577c * 0x28) = g_OverworldPlayerCoordX;
    *(int *)(&DAT_00676e44 + DAT_0052577c * 0x28) = g_OverworldMapGrid;
    *(int *)(&DAT_00676e48 + DAT_0052577c * 0x28) = DAT_006a4f70;
    *(int *)(&DAT_00676e4c + DAT_0052577c * 0x28) = DAT_006b2fe4;
    *(int *)(&DAT_00676e50 + DAT_0052577c * 0x28) = DAT_007006c8;
    *(int *)(&DAT_00676e54 + DAT_0052577c * 0x28) = DAT_006b2d5c;
    *(int *)(&DAT_00676e58 + DAT_0052577c * 0x28) = g_ActivePalette;
    DAT_0052577c = DAT_0052577c + 1;
  }
  return;
}



/*
 * Magic_TapCardForMana
 * Purpose: Tap an untapped land or artifact to add mana to the player pool.
 * Procedure:
 * 1. Verify that the card is untapped.
 * 2. Set the STATUS_TAPPED flag on the card slot.
 * 3. Add mana of the card color to the player mana pool.
 */
/*
 * Decompiled function: Magic_TapCardForMana
 * Entry Point: 004744de
 * Size: 170 bytes
 */


void Magic_TapCardForMana(void)

{
  if (0 < DAT_0052577c) {
    DAT_0052577c = DAT_0052577c + -1;
  }
  g_OverworldPlayerCoordX = *(int *)(&DAT_00676e40 + DAT_0052577c * 0x28);
  g_OverworldMapGrid = *(int *)(&DAT_00676e44 + DAT_0052577c * 0x28);
  DAT_006a4f70 = *(int *)(&DAT_00676e48 + DAT_0052577c * 0x28);
  DAT_006b2fe4 = *(int *)(&DAT_00676e4c + DAT_0052577c * 0x28);
  DAT_007006c8 = *(int *)(&DAT_00676e50 + DAT_0052577c * 0x28);
  DAT_006b2d5c = *(int *)(&DAT_00676e54 + DAT_0052577c * 0x28);
  g_ActivePalette = *(int *)(&DAT_00676e58 + DAT_0052577c * 0x28);
  return;
}



/*
 * Magic_UntapTurnPhase
 * Purpose: Execute the Untap step for the active player.
 * Procedure:
 * 1. Iterate through all cards controlled by the active player.
 * 2. Clear the STATUS_TAPPED flag on cards that can untap.
 * 3. Remove summoning sickness from creatures played on previous turns.
 */
/*
 * Decompiled function: Magic_UntapTurnPhase
 * Entry Point: 00474588
 * Size: 945 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Magic_UntapTurnPhase(void)

{
  uint8_t arg_1;
  int val_1;
  int val_2;
  int val_3;
  int val_4;
  int card_idx;
  int match_count;
  
  for (card_idx = 0; card_idx < 8; card_idx = card_idx + 1) {
    *(int *)(&DAT_006ff6b0 + card_idx * 4) = 0;
    *(int *)(&DAT_006ff690 + card_idx * 4) = *(int *)(&DAT_006ff6b0 + card_idx * 4);
    *(int *)(&DAT_006b2fc0 + card_idx * 4) = *(int *)(&DAT_006ff690 + card_idx * 4);
    *(int *)(&DAT_006b2fa0 + card_idx * 4) = *(int *)(&DAT_006b2fc0 + card_idx * 4);
    *(int *)(&DAT_006b2e60 + card_idx * 4) = *(int *)(&DAT_006b2fa0 + card_idx * 4);
    *(int *)(&DAT_006b2e40 + card_idx * 4) = *(int *)(&DAT_006b2e60 + card_idx * 4);
  }
  DAT_006a282c = 0;
  g_PlayerPoisonCounters = 0;
  DAT_00695e04 = 0;
  _DAT_00695e00 = 0;
  DAT_006a4a14 = 0;
  _DAT_006a4a10 = 0;
  for (card_idx = 0; card_idx < 0x18; card_idx = card_idx + 1) {
    *(int *)(&DAT_006b3000 + card_idx * 4) = 0;
  }
  _DAT_006b3000 = g_PlayerCreatureCount;
  DAT_006b3004 = g_PlayerDeckCardCount;
  for (match_count = 0; match_count < 2; match_count = match_count + 1) {
    (&g_ActivePlayerSpellPriority)[match_count] = 0;
    for (card_idx = 0; card_idx < (int)(&g_PlayerActiveCardCount)[match_count]; card_idx = card_idx + 1)
    {
      val_1 = Card_IsTapped(match_count, card_idx);
      if (val_1 == 0) {
        if (*(int *)(&g_CardSlot_CardId + card_idx * 0x120 + match_count * 0x5b20) != -1) {
          (&g_ActivePlayerSpellPriority)[match_count] = (&g_ActivePlayerSpellPriority)[match_count] + 1;
        }
      }
      else {
        val_1 = *(int *)(&g_CardSlot_CardId + card_idx * 0x120 + match_count * 0x5b20);
        arg_1 = (&g_MasterCardColorTable)[val_1 * 0x34];
        if (((&g_MasterCardColorTable)[val_1 * 0x34] & 2) != 0) {
          val_2 = Card_TapForMana(match_count, card_idx, 0x32, 0xffffffff);
          val_3 = Card_TapForMana(match_count,card_idx,0x33,0xffffffff);
          val_4 = Rules_CalculateManaCostReduction(arg_1);
          *(int *)(&DAT_006b2e40 + val_4 * 4 + match_count * 0x20) =
               *(int *)(&DAT_006b2e40 + val_4 * 4 + match_count * 0x20) + val_2;
          *(int *)(&DAT_006b2e5c + match_count * 0x20) =
               *(int *)(&DAT_006b2e5c + match_count * 0x20) + val_2;
          val_2 = Rules_CalculateManaCostReduction(arg_1);
          *(int *)(&DAT_006b2fa0 + val_2 * 4 + match_count * 0x20) =
               *(int *)(&DAT_006b2fa0 + val_2 * 4 + match_count * 0x20) + val_3;
          *(int *)(&DAT_006b2fbc + match_count * 0x20) =
               *(int *)(&DAT_006b2fbc + match_count * 0x20) + val_3;
          *(int *)(&DAT_006a4a10 + match_count * 4) = *(int *)(&DAT_006a4a10 + match_count * 4) + 1;
        }
        (&g_PlayerPoisonCounters)[match_count] =
             (&g_PlayerPoisonCounters)[match_count] | (uint32_t)(uint8_t)(&g_MasterCardColorTable)[val_1 * 0x34];
        if (((&g_MasterCardColorTable)[val_1 * 0x34] & 2) != 0) {
          *(int *)(&DAT_006b3010 + match_count * 4) = *(int *)(&DAT_006b3010 + match_count * 4) + 1;
        }
        if (((&g_MasterCardColorTable)[val_1 * 0x34] & 0x40) != 0) {
          (&DAT_006b3018)[match_count] = (&DAT_006b3018)[match_count] + 1;
        }
        if (((&g_MasterCardColorTable)[val_1 * 0x34] & 4) != 0) {
          *(int *)(&DAT_006b3020 + match_count * 4) = *(int *)(&DAT_006b3020 + match_count * 4) + 1;
        }
      }
    }
    for (card_idx = 0; card_idx < 500; card_idx = card_idx + 1) {
      if (*(int *)(&g_PlayerGraveyardList + card_idx * 4 + match_count * 2000) != -1) {
        *(uint32_t *)(&DAT_00695e00 + match_count * 4) =
             *(uint32_t *)(&DAT_00695e00 + match_count * 4) |
             (uint32_t)(uint8_t)(&g_MasterCardColorTable)
                         [*(int *)(&g_PlayerGraveyardList + card_idx * 4 + match_count * 2000) * 0x34];
      }
    }
  }
  return;
}



/*
 * Decompiled function: Magic_CheckTurnTriggers
 * Entry Point: 00474939
 * Size: 50 bytes
 */


void Magic_CheckTurnTriggers(int x,int arg2)

{
  if (g_IsAiThinking != 1) {
    Ai_Subsystem_004cc3c4(x,arg2);
  }
  g_ActivePlayer = 0;
  return;
}



/*
 * Magic_UpkeepPhase
 * Purpose: Execute the Upkeep step for the active player.
 * Procedure:
 * 1. Fire UPKEEP_EVENT triggers on all permanents in play.
 * 2. Process required upkeep payments.
 */
/*
 * Decompiled function: Magic_UpkeepPhase
 * Entry Point: 0047496b
 * Size: 788 bytes
 */


/* WARNING: Type propagation algorithm not settling */

int Magic_UpkeepPhase(int player_id)

{
  int uval_1;
  int val_2;
  char local_134 [264];
  int local_2c;
  int local_28 [8];
  uint32_t slot_idx;
  
  local_28[1] = 300;
  local_28[2] = 0;
  local_28[3] = 0;
  local_28[4] = 0;
  local_28[5] = 0;
  local_28[6] = 0;
  local_28[7] = arg_1;
  slot_idx = 0;
  if (g_IsAiThinking == 1) {
    uval_1 = 0;
  }
  else {
    local_28[0] = arg_1;
    if (arg_1 < 0x14) {
      Pic_Subsystem_00423bf4(arg_1,0);
    }
    else if (arg_1 < 0x1d) {
      val_2 = Pic_Subsystem_00424123(arg_1,local_28);
      if (val_2 == 0) {
        local_2c = Pic_Subsystem_00424165(local_28,0x14,0x16);
        if (local_2c == 0) {
          Pic_Subsystem_00423b93(local_28[0]);
        }
        else if (local_2c != 1) {
          return 0;
        }
        strcpy(local_134,&g_DuelSoundsDirectory);
        strcat(local_134,&DAT_00525d1c);
        strcat(local_134,(&PTR_s_artifact_wav_00525788)[arg_1]);
        Pic_Subsystem_00423b57(local_134,local_28[0],local_28 + 1);
      }
      Pic_Subsystem_00423bf4(local_28[0],0);
    }
    else if (arg_1 < 0x22) {
      val_2 = Pic_Subsystem_00424123(arg_1,local_28);
      if (val_2 == 0) {
        local_2c = Pic_Subsystem_00424165(local_28,0x1d,0x1d);
        if (local_2c == 0) {
          Pic_Subsystem_00423b93(local_28[0]);
        }
        else if (local_2c != 1) {
          return 0;
        }
        strcpy(local_134,&g_DuelSoundsDirectory);
        strcat(local_134,&DAT_00525d20);
        strcat(local_134,(&PTR_s_buried_wav_0052578c)[arg_1]);
        Pic_Subsystem_00423b57(local_134,local_28[0],local_28 + 1);
      }
      Pic_Subsystem_00423bf4(local_28[0],0);
    }
    else {
      if (0x2f < arg_1) {
        return 0;
      }
      local_28[1] = 400;
      val_2 = Pic_Subsystem_00424123(arg_1,local_28);
      if (val_2 == 0) {
        if (arg_1 == 0x2b) {
          local_28[6] = 0xffffffff;
        }
        else {
          slot_idx = slot_idx | 4;
        }
        strcpy(local_134,&g_DuelSoundsDirectory);
        strcat(local_134,&DAT_00525d24);
        strcat(local_134,(&PTR_s_draw_wav_00525790)[arg_1]);
        Pic_Subsystem_00423b57(local_134,local_28[0],local_28 + 1);
        Pic_Subsystem_00423bf4(local_28[0],local_28 + 1);
      }
      else {
        if (arg_1 == 0x2b) {
          local_28[6] = 0xffffffff;
        }
        else {
          slot_idx = slot_idx | 4;
        }
        Pic_Subsystem_00423bf4(local_28[0],local_28 + 1);
      }
    }
    uval_1 = 1;
  }
  return uval_1;
}



/*
 * Magic_DrawCardPhase
 * Purpose: Execute the Draw step for the active player.
 * Procedure:
 * 1. Verify that the active player library is not empty.
 * 2. Move the top card from the library to the player hand.
 * 3. Increment the hand card counter.
 */
/*
 * Decompiled function: Magic_DrawCardPhase
 * Entry Point: 00474c7f
 * Size: 143 bytes
 */


void Magic_DrawCardPhase(void)

{
  char local_130 [264];
  int local_28;
  uint32_t slot_idx;
  
  slot_idx = slot_idx & 0xfffffffb;
  Pic_Subsystem_00423bc7();
  for (local_28 = 0; local_28 < 0x14; local_28 = local_28 + 1) {
    strcpy(local_130,&g_DuelSoundsDirectory);
    strcat(local_130,&DAT_00525d28);
    strcat(local_130,(&PTR_s_artifact_wav_00525788)[local_28]);
    Pic_Subsystem_00423b57(local_130,local_28,0);
  }
  return;
}



/*
 * Decompiled function: FUN_00474d0e
 * Entry Point: 00474d0e
 * Size: 16 bytes
 */


void FUN_00474d0e(void)

{
  Pic_Subsystem_00423bc7();
  return;
}



/*
 * Decompiled function: Mem_AllocOrFree_00474d1e
 * Entry Point: 00474d1e
 * Size: 44 bytes
 */


int Mem_AllocOrFree_00474d1e(void)

{
  g_AiEvaluatedMoveCount = 0;
  DAT_006fecc0 = 0xffffffff;
  return 0;
}



/*
 * Decompiled function: FUN_00474d4a
 * Entry Point: 00474d4a
 * Size: 51 bytes
 */


int FUN_00474d4a(void)

{
  int uval_1;
  
  if (g_AiEvaluatedMoveCount == 0) {
    uval_1 = 0xffffffff;
  }
  else {
    uval_1 = *(int *)(&DAT_006ff4cc + g_AiEvaluatedMoveCount * 4);
  }
  return uval_1;
}



/*
 * Magic_MainTurnPhase
 * Purpose: Execute the Main phase.
 * Procedure:
 * 1. Grant priority to the active player.
 * 2. Process land drops and spell casts.
 */
/*
 * Decompiled function: Magic_MainTurnPhase
 * Entry Point: 00474d7d
 * Size: 1114 bytes
 */


int Magic_MainTurnPhase(int player_id)

{
  int val_1;
  int val_2;
  int uval_3;
  int uval_4;
  int uval_5;
  int val_6;
  
  val_6 = g_AiEvaluatedMoveCount + -1;
  val_1 = (&DAT_006fecc0)[val_6 * 2];
  val_2 = *(int *)(&DAT_006fecc4 + val_6 * 8);
  if (*(int *)(&g_CardSlot_CardId + val_2 * 0x120 + val_1 * 0x5b20) == DAT_006fd3f4) {
    uval_3 = *(int *)(&g_CardSlot_SicknessState + val_2 * 0x120 + val_1 * 0x5b20);
    uval_4 = *(int *)(&g_CardSlot_TapState + val_2 * 0x120 + val_1 * 0x5b20);
    uval_5 = *(int *)(&g_CardSlot_DisplayIndex + val_2 * 0x120 + val_1 * 0x5b20);
    memcpy(&g_ActiveCardsInPlay + val_1 * 0x5b20 + val_2 * 0x120,
           &g_ActiveCardsInPlay +
           *(int *)(&g_CardSlot_SicknessState + val_2 * 0x120 + val_1 * 0x5b20) * 0x120 +
           *(int *)(&g_CardSlot_TapState + val_2 * 0x120 + val_1 * 0x5b20) * 0x5b20,0x120);
    *(int *)(&g_CardSlot_CardId + val_2 * 0x120 + val_1 * 0x5b20) = DAT_006fd3f4;
    *(int *)(&DAT_006a5f80 + val_2 * 0x120 + val_1 * 0x5b20) = 0;
    (&g_CardSlot_CardTypeIndex)[val_2 * 0x120 + val_1 * 0x5b20] = 0;
    *(uint32_t *)(&g_CardSlot_Flags + val_2 * 0x120 + val_1 * 0x5b20) =
         *(uint32_t *)(&g_CardSlot_Flags + val_2 * 0x120 + val_1 * 0x5b20) | 2;
    *(int *)(&g_CardSlot_TapState + val_2 * 0x120 + val_1 * 0x5b20) = uval_4;
    *(int *)(&g_CardSlot_SicknessState + val_2 * 0x120 + val_1 * 0x5b20) = uval_3;
    *(int *)(&g_CardSlot_DisplayIndex + val_2 * 0x120 + val_1 * 0x5b20) = uval_5;
    if (*(int *)(&g_CardSlot_CardId +
                *(int *)(&g_CardSlot_TapState + val_2 * 0x120 + val_1 * 0x5b20) * 0x5b20 +
                *(int *)(&g_CardSlot_SicknessState + val_2 * 0x120 + val_1 * 0x5b20) * 0x120) != -1)
    {
      *(int *)(&g_ActiveCardsInPlay + val_2 * 0x120 + val_1 * 0x5b20) =
           *(int *)
            (&g_CardSlot_CardId +
            *(int *)(&g_CardSlot_TapState + val_2 * 0x120 + val_1 * 0x5b20) * 0x5b20 +
            *(int *)(&g_CardSlot_SicknessState + val_2 * 0x120 + val_1 * 0x5b20) * 0x120);
    }
    if ((*(int *)(&g_ActiveCardsInPlay + val_2 * 0x120 + val_1 * 0x5b20) < g_PendingSpellTargetSlot) ||
       (g_PendingSpellTargetSlot + 0x1d <= *(int *)(&g_ActiveCardsInPlay + val_2 * 0x120 + val_1 * 0x5b20))) {
      *(int *)(&DAT_006a5f74 + val_2 * 0x120 + val_1 * 0x5b20) =
           *(int *)
            (&g_MasterCardTypeTable +
            *(int *)(&g_ActiveCardsInPlay +
                    *(int *)(&g_CardSlot_TapState + val_2 * 0x120 + val_1 * 0x5b20) * 0x5b20 +
                    *(int *)(&g_CardSlot_SicknessState + val_2 * 0x120 + val_1 * 0x5b20) * 0x120) *
            0x34);
    }
  }
  if (g_IsAiThinking != 1) {
    *(int *)(&DAT_00695d70 + val_6 * 4) = arg_1;
  }
  *(int *)(&DAT_006ff390 + val_6 * 8) =
       (int)(char)(&g_CardSlot_Toughness)[val_2 * 0x120 + val_1 * 0x5b20];
  *(int *)(&DAT_006ff394 + val_6 * 8) =
       *(int *)(&g_CardSlot_OriginalCardId + val_2 * 0x120 + val_1 * 0x5b20);
  return 0;
}



/*
 * Magic_CombatPhase
 * Purpose: Execute the Combat phase.
 * Procedure:
 * 1. Declare attackers step.
 * 2. Declare blockers step.
 * 3. Combat damage step.
 */
/*
 * Decompiled function: Magic_CombatPhase
 * Entry Point: 004751d7
 * Size: 1062 bytes
 */


int Magic_CombatPhase(int player_id,int card_slot,int event_type,int arg_4,int arg_5)

{
  int uval_1;
  bool flag_2;
  int match_count;
  
  if (g_AiEvaluatedMoveCount < 0x20) {
    *(int *)(&DAT_006ff4d0 + g_AiEvaluatedMoveCount * 4) =
         *(int *)(&g_CardSlot_CardId + arg_2 * 0x120 + arg_1 * 0x5b20);
    *(uint32_t *)(&DAT_006ff4d0 + g_AiEvaluatedMoveCount * 4) =
         *(uint32_t *)(&DAT_006ff4d0 + g_AiEvaluatedMoveCount * 4) | arg_3 << 0x10;
    *(uint32_t *)(&DAT_006ff4d0 + g_AiEvaluatedMoveCount * 4) =
         *(uint32_t *)(&DAT_006ff4d0 + g_AiEvaluatedMoveCount * 4) | arg_4 << 0x18;
    if (((arg_3 == 0x71) || (arg_3 == 0x7e)) ||
       (*(int *)(&g_CardSlot_CardId + arg_2 * 0x120 + arg_1 * 0x5b20) < 5)) {
      match_count = arg_2;
      flag_2 = true;
    }
    else {
      match_count = Deck_AddCardToDeck(arg_1,DAT_006fd3f4);
      if (match_count == -1) {
        flag_2 = false;
      }
      else {
        uval_1 = *(int *)(&g_CardSlot_DisplayIndex + arg_1 * 0x5b20 + match_count * 0x120);
        memcpy(&g_ActiveCardsInPlay + match_count * 0x120 + arg_1 * 0x5b20,
               &g_ActiveCardsInPlay + arg_1 * 0x5b20 + arg_2 * 0x120,0x120);
        *(int *)(&g_CardSlot_CardId + arg_1 * 0x5b20 + match_count * 0x120) = DAT_006fd3f4;
        *(int *)(&DAT_006a5f80 + arg_1 * 0x5b20 + match_count * 0x120) = 0;
        (&g_CardSlot_CardTypeIndex)[arg_1 * 0x5b20 + match_count * 0x120] = 0;
        if (*(int *)(&g_CardSlot_CardId + arg_2 * 0x120 + arg_1 * 0x5b20) == -1) {
          *(int *)(&g_ActiveCardsInPlay + arg_1 * 0x5b20 + match_count * 0x120) =
               *(int *)(&g_ActiveCardsInPlay + arg_2 * 0x120 + arg_1 * 0x5b20);
        }
        else {
          *(int *)(&g_ActiveCardsInPlay + arg_1 * 0x5b20 + match_count * 0x120) =
               *(int *)(&g_CardSlot_CardId + arg_2 * 0x120 + arg_1 * 0x5b20);
        }
        *(int *)(&DAT_006a5f74 + arg_1 * 0x5b20 + match_count * 0x120) =
             *(int *)(&DAT_006a5f74 + arg_2 * 0x120 + arg_1 * 0x5b20);
        *(uint32_t *)(&g_CardSlot_Flags + arg_1 * 0x5b20 + match_count * 0x120) =
             *(uint32_t *)(&g_CardSlot_Flags + arg_1 * 0x5b20 + match_count * 0x120) | 2;
        *(int *)(&g_CardSlot_TapState + arg_1 * 0x5b20 + match_count * 0x120) = arg_1;
        *(int *)(&g_CardSlot_SicknessState + arg_1 * 0x5b20 + match_count * 0x120) = arg_2;
        *(int *)(&g_CardSlot_DisplayIndex + arg_1 * 0x5b20 + match_count * 0x120) = uval_1;
        flag_2 = true;
      }
    }
    if (flag_2) {
      (&DAT_006fecc0)[g_AiEvaluatedMoveCount * 2] = arg_1;
      *(int *)(&DAT_006fecc4 + g_AiEvaluatedMoveCount * 8) = match_count;
      *(int *)(&DAT_006ff390 + g_AiEvaluatedMoveCount * 8) =
           (int)(char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20];
      *(int *)(&DAT_006ff394 + g_AiEvaluatedMoveCount * 8) =
           *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20);
      if (g_PlayerManaPool == -1) {
        *(int *)(&DAT_00696880 + g_AiEvaluatedMoveCount * 4) = g_ScWillyScore;
      }
      else {
        *(int *)(&DAT_00696880 + g_AiEvaluatedMoveCount * 4) = g_PlayerManaPool;
      }
      if (g_IsAiThinking != 1) {
        *(int *)(&DAT_00695d70 + g_AiEvaluatedMoveCount * 4) = arg_5;
      }
      g_AiEvaluatedMoveCount = g_AiEvaluatedMoveCount + 1;
      (&DAT_006fecc0)[g_AiEvaluatedMoveCount * 2] = 0xffffffff;
    }
  }
  return 0;
}



/*
 * Decompiled function: FUN_004755fd
 * Entry Point: 004755fd
 * Size: 164 bytes
 */


int FUN_004755fd(void)

{
  int val_1;
  int match_count;
  
  for (match_count = 0; match_count < g_AiEvaluatedMoveCount; match_count = match_count + 1) {
    val_1 = (&DAT_006fecc0)[match_count * 2];
    *(int *)(&DAT_006ff390 + match_count * 8) =
         (int)(char)(&g_CardSlot_Toughness)
                    [val_1 * 0x5b20 + *(int *)(&DAT_006fecc4 + match_count * 8) * 0x120];
    *(int *)(&DAT_006ff394 + match_count * 8) =
         *(int *)
          (&g_CardSlot_OriginalCardId +
          val_1 * 0x5b20 + *(int *)(&DAT_006fecc4 + match_count * 8) * 0x120);
  }
  return 0;
}



/*
 * Magic_EndTurnPhase
 * Purpose: Execute the End of Turn step.
 * Procedure:
 * 1. Check end-of-turn triggers.
 * 2. Prompt player to discard to maximum hand size if needed.
 * 3. Switch the active player turn index.
 */
/*
 * Decompiled function: Magic_EndTurnPhase
 * Entry Point: 004756a1
 * Size: 1295 bytes
 */


int Magic_EndTurnPhase(void)

{
  int player_id;
  int card_slot;
  int match_count;
  
  if (0 < g_AiEvaluatedMoveCount) {
    g_AiEvaluatedMoveCount = g_AiEvaluatedMoveCount + -1;
    arg_1 = (&DAT_006fecc0)[g_AiEvaluatedMoveCount * 2];
    arg_2 = *(int *)(&DAT_006fecc4 + g_AiEvaluatedMoveCount * 8);
    match_count = *(int *)(&g_CardSlot_CardId + arg_2 * 0x120 + arg_1 * 0x5b20);
    if (DAT_006fd3f4 == match_count) {
      match_count = *(int *)(&g_ActiveCardsInPlay + arg_2 * 0x120 + arg_1 * 0x5b20);
    }
    if (*(int *)(&g_CardSlot_CardId + arg_2 * 0x120 + arg_1 * 0x5b20) != -1) {
      if ((char)((uint32_t)*(int *)(&DAT_006ff4d0 + g_AiEvaluatedMoveCount * 4) >> 0x10) == '~') {
        Pic_Subsystem_004485d6
                  (arg_1,arg_2,*(uint32_t *)(&DAT_006ff4d0 + g_AiEvaluatedMoveCount * 4) >> 0x10 & 0xff,
                   *(int *)(&DAT_006ff4d0 + g_AiEvaluatedMoveCount * 4) >> 0x18);
      }
      else if (((&g_CardSlot_SpecialState)[arg_2 * 0x120 + arg_1 * 0x5b20] & 8) == 0) {
        if (((&g_CardSlot_SpecialState)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x80) == 0) {
          Magic_TriggerCardEvent
                    (arg_1,arg_2,*(uint32_t *)(&DAT_006ff4d0 + g_AiEvaluatedMoveCount * 4) >> 0x10 & 0xff,
                     1 - arg_1,0xffffffff);
        }
        else {
          if (((&g_CardSlot_SpecialState)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x40) != 0) {
            *(uint32_t *)(&g_CardSlot_Flags +
                     *(int *)(&g_CardSlot_SicknessState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                     *(int *)(&g_CardSlot_TapState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) =
                 *(uint32_t *)(&g_CardSlot_Flags +
                          *(int *)(&g_CardSlot_SicknessState + arg_2 * 0x120 + arg_1 * 0x5b20) *
                          0x120 + *(int *)(&g_CardSlot_TapState + arg_2 * 0x120 + arg_1 * 0x5b20) *
                                  0x5b20) & 0xffffffef;
            Magic_TriggerCardEvent
                      (*(int *)(&g_CardSlot_TapState + arg_2 * 0x120 + arg_1 * 0x5b20),
                       *(int *)(&g_CardSlot_SicknessState + arg_2 * 0x120 + arg_1 * 0x5b20),0x83,
                       1 - arg_1,0xffffffff);
          }
          *(uint32_t *)(&g_CardSlot_SpecialState +
                   *(int *)(&g_CardSlot_SicknessState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                   *(int *)(&g_CardSlot_TapState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) =
               *(uint32_t *)(&g_CardSlot_SpecialState +
                        *(int *)(&g_CardSlot_SicknessState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120
                        + *(int *)(&g_CardSlot_TapState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20)
               & 0xffffff7f;
        }
      }
      else {
        if (((((&DAT_006a6045)[arg_2 * 0x120 + arg_1 * 0x5b20] & 2) == 0) &&
            (Magic_TriggerCardEvent(arg_1,arg_2,0x86,1 - arg_1,0xffffffff),
            *(int *)(&g_CardSlot_CardId + arg_2 * 0x120 + arg_1 * 0x5b20) != -1)) &&
           (((&g_CardSlot_SpecialState)[arg_2 * 0x120 + arg_1 * 0x5b20] & 2) != 0)) {
          Pic_Subsystem_0044867e
                    (*(int *)(&g_CardSlot_TapState + arg_2 * 0x120 + arg_1 * 0x5b20),
                     *(int *)(&g_CardSlot_SicknessState + arg_2 * 0x120 + arg_1 * 0x5b20),1);
        }
        *(uint32_t *)(&g_CardSlot_SpecialState +
                 *(int *)(&g_CardSlot_SicknessState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                 *(int *)(&g_CardSlot_TapState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_SpecialState +
                      *(int *)(&g_CardSlot_SicknessState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                      *(int *)(&g_CardSlot_TapState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) &
             0xfffffdf7;
        *(uint32_t *)(&g_CardSlot_SpecialState +
                 *(int *)(&g_CardSlot_SicknessState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                 *(int *)(&g_CardSlot_TapState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_SpecialState +
                      *(int *)(&g_CardSlot_SicknessState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                      *(int *)(&g_CardSlot_TapState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) | 4;
      }
      if (*(int *)(&g_CardSlot_CardId + arg_2 * 0x120 + arg_1 * 0x5b20) == DAT_006fd3f4) {
        Pic_Subsystem_0044867e(arg_1,arg_2,4);
      }
    }
    (&DAT_006fecc0)[g_AiEvaluatedMoveCount * 2] = 0xffffffff;
    Rules_ProcessCombatDamageStep();
    if (((((&g_MasterCardFlagsTable)[match_count * 0x34] & 0x10) == 0) || (((uint8_t)g_PlayerHandCardCount & 2) != 0)
        ) && ((DAT_006fd3f0 < 2 && (((g_PlayerHandCardCount._1_1_ & 2) == 0 || (g_AiEvaluatedMoveCount == 0)))
              ))) {
      Rules_ProcessDamagePrevention(g_DefendingPlayer);
      Rules_SendCardsToGraveyard();
    }
  }
  return 0;
}



/*
 * Magic_DiscardToHandSize
 * Purpose: Force a player to discard cards when hand count exceeds 7.
 */
/*
 * Decompiled function: Magic_DiscardToHandSize
 * Entry Point: 00475bb0
 * Size: 177 bytes
 */


int Magic_DiscardToHandSize(void)

{
  if (0 < g_AiEvaluatedMoveCount) {
    g_AiEvaluatedMoveCount = g_AiEvaluatedMoveCount + -1;
    if (DAT_006fd3f4 ==
        *(int *)(&g_CardSlot_CardId +
                *(int *)(&DAT_006fecc4 + g_AiEvaluatedMoveCount * 8) * 0x120 +
                (&DAT_006fecc0)[g_AiEvaluatedMoveCount * 2] * 0x5b20)) {
      *(int *)
       (&g_CardSlot_CardId +
       *(int *)(&DAT_006fecc4 + g_AiEvaluatedMoveCount * 8) * 0x120 +
       (&DAT_006fecc0)[g_AiEvaluatedMoveCount * 2] * 0x5b20) = 0xffffffff;
    }
    (&DAT_006fecc0)[g_AiEvaluatedMoveCount * 2] = 0xffffffff;
  }
  return 0;
}



/*
 * Decompiled function: Mem_AllocOrFree_00475c61
 * Entry Point: 00475c61
 * Size: 41 bytes
 */


void Mem_AllocOrFree_00475c61(void)

{
  DAT_006b2d24 = 0;
  DAT_006ff684 = 0;
  DAT_0052211c = 0;
  return;
}



/*
 * Decompiled function: FUN_00475c8a
 * Entry Point: 00475c8a
 * Size: 218 bytes
 */


int FUN_00475c8a(int x,int card_slot,char *arg_3,int arg_4)

{
  int uval_1;
  int val_2;
  int uval_3;
  
  uval_1 = DAT_0063ee1c;
  if (((g_AiEvaluatedMoveCount == 0) && (val_2 = FUN_00505c74(), val_2 != 0)) && (x != -2)) {
    DAT_0063ee1c = 1;
  }
  do {
    DAT_006ff380 = 0;
    uval_3 = Magic_CleanupPhase(x,arg_2,arg_3,arg_4);
    if ((DAT_006ff380 == 0) || (0 < g_AiEvaluatedMoveCount)) break;
  } while (g_IsAiThinking != 1);
  DAT_0063ee1c = uval_1;
  if (g_AiEvaluatedMoveCount == 0) {
    DAT_0063ee1c = 0;
    *(uint32_t *)(&g_PlayerManaPoolAvailable + g_DefendingPlayer * 0x98 + g_ScWillyScore * 4) =
         *(uint32_t *)(&g_PlayerManaPoolAvailable + g_DefendingPlayer * 0x98 + g_ScWillyScore * 4) & 0xfffffffd;
  }
  return uval_3;
}



/*
 * Magic_CleanupPhase
 * Purpose: Remove temporary damage from creatures and reset until-end-of-turn effects.
 */
/*
 * Decompiled function: Magic_CleanupPhase
 * Entry Point: 00475d64
 * Size: 1185 bytes
 */


int Magic_CleanupPhase(int x,int y,char *str_3,int arg_4)

{
  int uval_1;
  int uval_2;
  int uval_3;
  int val_4;
  int local_98;
  int local_94;
  char local_8c [128];
  int match_count;
  int slot_idx;
  
  uval_3 = g_CombatPhaseFlags;
  uval_2 = g_ActiveCardTargetSlot;
  uval_1 = DAT_006808b0;
  match_count = g_PlayerManaPool;
  g_PlayerManaPool = 0xffffffff;
  DAT_006ff684 = DAT_006ff684 + 1;
  if (DAT_006ff684 == 1) {
    DAT_006b2d24 = 0;
  }
  else if ((((DAT_006b2d24 < DAT_006ff684) && (y != 0x8e)) && (y != 0x70)) && (y != 0xd3)) {
    DAT_006b2d24 = DAT_006ff684;
  }
  local_94 = 0;
  g_ActiveCardTargetSlot = arg_4;
  slot_idx = DAT_00525850;
  if ((x == -2) && (val_4 = FUN_00505c74(), val_4 == 0)) {
    DAT_00525850 = 1;
  }
  else {
    DAT_00525850 = 0;
  }
  val_4 = FUN_00505c74();
  if ((val_4 == 0) &&
     ((*(int *)(&g_PlayerManaPoolAvailable + g_DefendingPlayer * 0x98 + y * 4) != 0 ||
      ((g_DefendingPlayer == DAT_00627a84 && (y == DAT_00627a88)))))) {
    DAT_006808b0 = 1;
  }
  else {
    DAT_006808b0 = 0;
  }
  if ((-1 < x) && (DAT_006808b0 == 0)) {
LAB_0047615d:
    DAT_006ff684 = DAT_006ff684 + -1;
    if ((DAT_006ff684 == 0) && (DAT_0063edc8 = 0xffffffff, DAT_006fd3f0 == 0)) {
      DAT_0063ee1c = 0;
      DAT_0063edc4 = 0;
    }
    DAT_0063ee70 = 0xffffffff;
    DAT_006808b0 = uval_1;
    DAT_00525850 = slot_idx;
    g_CombatPhaseFlags = uval_3;
    g_PlayerManaPool = match_count;
    g_ActiveCardTargetSlot = uval_2;
    if (local_94 != 0) {
      DAT_00633434 = 0;
    }
    return local_94;
  }
  strcpy(local_8c,str_3);
  if ((g_ScWillyScore == 4) && (DAT_006ff684 == 1)) {
    g_CurrentTurnTargetPlayer = g_DefendingPlayer;
    FUN_00476b0e();
  }
  do {
    do {
      if (g_DefendingPlayer == 0) {
        DAT_0068a67c = 1;
      }
      else if (x < 0) {
        DAT_0068a67c = 2;
      }
      else {
        DAT_0068a67c = 0;
      }
      if (DAT_006ff684 < 2) {
        DAT_0063ee70 = 0xffffffff;
      }
      g_ActivePlayer = 0;
      g_CombatPhaseFlags = 0;
      local_98 = UI_PromptFastEffectsDialog(g_DefendingPlayer,local_8c);
      if (local_98 != 0) {
        DAT_006ff380 = 1;
      }
      if (((g_DefendingPlayer == g_CurrentTurnPhase) && (local_98 != 0)) && (g_IsAiThinking != 1)) {
        local_94 = 1;
      }
      if ((DAT_006ff684 < DAT_006b2d24) && (-1 < g_AiEvaluatedMoveCount)) {
        local_98 = 0;
      }
    } while ((local_98 != 0) || (((g_CombatPhaseFlags & 1) != 0 && (DAT_006ff684 == 1))));
    if ((g_ScWillyScore == 4) && (DAT_006ff684 == 1)) {
      g_CurrentTurnTargetPlayer = 1 - g_DefendingPlayer;
      FUN_00476b0e();
    }
    while( true ) {
      if (g_DefendingPlayer == 0) {
        if (x < 0) {
          DAT_0068a67c = 2;
        }
        else {
          DAT_0068a67c = 0;
        }
      }
      else {
        DAT_0068a67c = 1;
      }
      if (DAT_006ff684 < 2) {
        DAT_0063ee70 = 0xffffffff;
      }
      g_ActivePlayer = 0;
      g_CombatPhaseFlags = 0;
      if (((DAT_006ff684 < DAT_006b2d24) && (-1 < g_AiEvaluatedMoveCount)) ||
         (val_4 = UI_PromptFastEffectsDialog(1 - g_DefendingPlayer,local_8c), val_4 == 0))
      goto LAB_0047615d;
      DAT_006ff380 = 1;
      if (g_IsAiThinking != 1) break;
      if ((g_DefendingPlayer != g_CurrentTurnPhase) &&
         (((g_CombatPhaseFlags & 1) == 0 || (DAT_006ff684 != 1)))) goto LAB_0047615d;
    }
  } while( true );
}



/*
 * Decompiled function: FUN_00476205
 * Entry Point: 00476205
 * Size: 74 bytes
 */


int FUN_00476205(int x,int card_slot,char *arg_3,int arg_4)

{
  FUN_0047624f(x,arg_2,arg_3,arg_4);
  FUN_0047624f(1 - x,arg_2,arg_3,arg_4);
  return 1;
}



/*
 * Decompiled function: FUN_0047624f
 * Entry Point: 0047624f
 * Size: 495 bytes
 */


int FUN_0047624f(int x,int card_slot,char *str_3,int height)

{
  uint32_t uval_1;
  int uval_2;
  int uval_3;
  int uval_4;
  int uval_5;
  int val_6;
  int target_idx;
  
  uval_5 = g_CurrentCardColorTarget;
  uval_4 = g_TurnPhaseStateFlags;
  uval_3 = g_ActiveCardTargetSlot;
  uval_2 = DAT_0068a67c;
  uval_1 = DAT_0063ee70;
  DAT_006fd3f0 = DAT_006fd3f0 + 1;
  g_ActiveCardTargetSlot = arg_2;
  g_CurrentCardColorTarget = x;
  do {
    if (x == 0) {
      DAT_0068a67c = 1;
    }
    else {
      DAT_0068a67c = 2;
    }
    g_PlayerManaPool = arg_2;
    if (height == 0) {
      DAT_0063ee70 = 0;
    }
    else {
      DAT_0063ee70 = 0x30;
    }
    g_ActivePlayer = 0;
    DAT_0068a714 = 0;
    g_TurnPhaseStateFlags = 0;
    val_6 = UI_PromptFastEffectsDialog(x,str_3);
    DAT_0063edc8 = uval_1 & 0x30;
  } while (((g_TurnPhaseStateFlags & (-(uint32_t)(val_6 == 0) & 0xfffffffe) + 6) != 0) ||
          ((height != 0 && (val_6 != 0))));
  g_PlayerManaPool = 0xffffffff;
  DAT_006fd3f0 = DAT_006fd3f0 + -1;
  DAT_0063ee70 = uval_1;
  DAT_0068a67c = uval_2;
  if (DAT_006fd3f0 == 0) {
    for (x = 0; x < 2; x = x + 1) {
      for (target_idx = 0; target_idx < (int)(&g_PlayerActiveCardCount)[x]; target_idx = target_idx + 1) {
        *(uint32_t *)(&g_CardSlot_Flags + target_idx * 0x120 + x * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_Flags + target_idx * 0x120 + x * 0x5b20) & 0xfffffeff;
      }
    }
    if (DAT_006ff684 == 0) {
      DAT_0063ee1c = 0;
      DAT_0063edc4 = 0;
    }
  }
  g_TurnPhaseStateFlags = uval_4;
  g_CurrentCardColorTarget = uval_5;
  g_ActiveCardTargetSlot = uval_3;
  return 0;
}



/*
 * Decompiled function: FUN_0047643e
 * Entry Point: 0047643e
 * Size: 68 bytes
 */


int FUN_0047643e(void)

{
  int slot_idx;
  
  for (slot_idx = 0; slot_idx < 500; slot_idx = slot_idx + 1) {
    *(int *)(&g_CardDisplayOrder_Player + slot_idx * 4) = 0xffffffff;
  }
  return 0;
}



/*
 * Decompiled function: FUN_00476482
 * Entry Point: 00476482
 * Size: 142 bytes
 */


int FUN_00476482(int x,int arg2)

{
  int slot_idx;
  
  slot_idx = 0;
  while( true ) {
    if (499 < slot_idx) {
      return -1;
    }
    if (*(int *)(&g_CardDisplayOrder_Player + slot_idx * 4) == -1) break;
    slot_idx = slot_idx + 1;
  }
  *(int *)(&g_CardDisplayOrder_Player + slot_idx * 4) = x;
  *(int *)(&g_CardDisplayOrder_Slot + slot_idx * 4) = arg2;
  *(int *)(&g_CardSlot_DisplayIndex + arg2 * 0x120 + x * 0x5b20) = slot_idx;
  return slot_idx;
}



/*
 * Decompiled function: FUN_00476510
 * Entry Point: 00476510
 * Size: 357 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00476510(void)

{
  int match_count;
  int slot_idx;
  
  for (slot_idx = 0; slot_idx < 500; slot_idx = slot_idx + 1) {
    while ((*(int *)(&g_CardDisplayOrder_Player + slot_idx * 4) != -1 &&
           ((match_count = slot_idx,
            *(int *)(&g_CardSlot_CardId +
                    *(int *)(&g_CardDisplayOrder_Player + slot_idx * 4) * 0x5b20 +
                    *(int *)(&g_CardDisplayOrder_Slot + slot_idx * 4) * 0x120) == -1 ||
            (*(int *)(&g_CardSlot_DisplayIndex +
                     *(int *)(&g_CardDisplayOrder_Player + slot_idx * 4) * 0x5b20 +
                     *(int *)(&g_CardDisplayOrder_Slot + slot_idx * 4) * 0x120) != slot_idx))))) {
      while (match_count = match_count + 1, match_count < 500) {
        *(int *)(&DAT_007006dc + match_count * 4) = *(int *)(&g_CardDisplayOrder_Player + match_count * 4);
        *(int *)(&DAT_006a574c + match_count * 4) = *(int *)(&g_CardDisplayOrder_Slot + match_count * 4);
        if (*(int *)(&g_CardSlot_DisplayIndex +
                    *(int *)(&g_CardDisplayOrder_Slot + match_count * 4) * 0x120 +
                    *(int *)(&g_CardDisplayOrder_Player + match_count * 4) * 0x5b20) == match_count) {
          *(int *)(&g_CardSlot_DisplayIndex +
                  *(int *)(&g_CardDisplayOrder_Player + match_count * 4) * 0x5b20 +
                  *(int *)(&g_CardDisplayOrder_Slot + match_count * 4) * 0x120) =
               *(int *)(&g_CardSlot_DisplayIndex +
                       *(int *)(&g_CardDisplayOrder_Player + match_count * 4) * 0x5b20 +
                       *(int *)(&g_CardDisplayOrder_Slot + match_count * 4) * 0x120) + -1;
        }
      }
      _DAT_00700eac = 0xffffffff;
    }
  }
  return;
}



/*
 * Decompiled function: FUN_00476675
 * Entry Point: 00476675
 * Size: 377 bytes
 */


int FUN_00476675(int x,int arg2)

{
  int uval_1;
  int val_2;
  int match_count;
  uint32_t slot_idx;
  
  if (((&g_CardSlot_Flags)[x * 0x5b20 + arg2 * 0x120] & 0x10) == 0) {
    uval_1 = 0;
  }
  else {
    match_count = 0;
    for (slot_idx = 1; (int)slot_idx < 7; slot_idx = slot_idx + 1) {
      if ((&DAT_006a603c)[slot_idx + arg2 * 0x120 + x * 0x5b20] != '\0') {
        val_2 = Font_DrawString(x,slot_idx,
                             (int)(char)(&DAT_006a603c)[slot_idx + arg2 * 0x120 + x * 0x5b20]);
        if (val_2 == 0) {
          return 0;
        }
        match_count = match_count + (char)(&DAT_006a603c)[slot_idx + arg2 * 0x120 + x * 0x5b20];
      }
    }
    val_2 = Font_DrawString(x,7,(char)(&DAT_006a603c)[x * 0x5b20 + arg2 * 0x120] + match_count);
    if (val_2 == 0) {
      uval_1 = 0;
    }
    else {
      Magic_TriggerCardEvent(x,arg2,0x88,1 - x,0xffffffff);
      if (DAT_006b2e38 == 0) {
        uval_1 = 1;
      }
      else {
        uval_1 = 0;
      }
    }
  }
  return uval_1;
}



/*
 * Decompiled function: FUN_004767ee
 * Entry Point: 004767ee
 * Size: 470 bytes
 */


void FUN_004767ee(int player_id)

{
  bool flag_1;
  int val_2;
  int target_idx;
  int card_idx;
  
  val_2 = 1 - arg_1;
  for (card_idx = 0; card_idx < (int)(&g_PlayerActiveCardCount)[arg_1]; card_idx = card_idx + 1) {
    if ((*(int *)(&g_CardSlot_CardId + card_idx * 0x120 + arg_1 * 0x5b20) != -1) &&
       (((uint8_t)*(int *)(&g_CardSlot_Flags + card_idx * 0x120 + arg_1 * 0x5b20) & 6) == 6)) {
      flag_1 = false;
      for (target_idx = 0; target_idx < (int)(&g_PlayerActiveCardCount)[val_2]; target_idx = target_idx + 1)
      {
        if ((*(int *)(&g_CardSlot_CardId + val_2 * 0x5b20 + target_idx * 0x120) != -1) &&
           ((char)(&g_CardSlot_ColorMask)[val_2 * 0x5b20 + target_idx * 0x120] == card_idx)) {
          flag_1 = true;
        }
      }
      if (flag_1) {
        for (target_idx = 0; target_idx < (int)(&g_PlayerActiveCardCount)[arg_1];
            target_idx = target_idx + 1) {
          if ((target_idx == card_idx) ||
             (((char)(&g_CardSlot_ColorMask)[target_idx * 0x120 + arg_1 * 0x5b20] == card_idx &&
              (((uint8_t)*(int *)(&g_CardSlot_Flags + target_idx * 0x120 + arg_1 * 0x5b20) & 6) ==
               6)))) {
            *(uint32_t *)(&g_CardSlot_Flags + target_idx * 0x120 + arg_1 * 0x5b20) =
                 *(uint32_t *)(&g_CardSlot_Flags + target_idx * 0x120 + arg_1 * 0x5b20) | 0x200;
          }
        }
      }
    }
  }
  return;
}



/*
 * Decompiled function: FUN_004769c4
 * Entry Point: 004769c4
 * Size: 183 bytes
 */


int FUN_004769c4(int x,int arg2)

{
  int uval_1;
  int slot_idx;
  
  if ((x == -1) || (arg2 == -1)) {
    uval_1 = 0;
  }
  else {
    slot_idx = *(int *)(&g_CardSlot_CardId + arg2 * 0x120 + x * 0x5b20);
    if (DAT_006fd3f4 == slot_idx) {
      slot_idx = *(int *)(&g_ActiveCardsInPlay + arg2 * 0x120 + x * 0x5b20);
    }
    if (slot_idx == -1) {
      uval_1 = 0;
    }
    else if (((&DAT_0051aed2)[slot_idx * 0x34] & 2) == 0) {
      uval_1 = 0;
    }
    else {
      uval_1 = 1;
    }
  }
  return uval_1;
}



/*
 * Decompiled function: FUN_00476a80
 * Entry Point: 00476a80
 * Size: 142 bytes
 */


void FUN_00476a80(void)

{
  int val_1;
  int match_count;
  int slot_idx;
  
  for (slot_idx = 0; slot_idx < 2; slot_idx = slot_idx + 1) {
    for (match_count = 0; match_count < (int)(&g_PlayerActiveCardCount)[slot_idx]; match_count = match_count + 1) {
      val_1 = Card_IsTapped(slot_idx,match_count);
      if (val_1 != 0) {
        *(int *)(&g_CardSlot_SpecialState + match_count * 0x120 + slot_idx * 0x5b20) = 0;
      }
    }
  }
  return;
}



/*
 * Decompiled function: FUN_00476b0e
 * Entry Point: 00476b0e
 * Size: 361 bytes
 */


void FUN_00476b0e(void)

{
  int val_1;
  int card_idx;
  int match_count;
  int slot_idx;
  
  for (slot_idx = 0; slot_idx < 2; slot_idx = slot_idx + 1) {
    for (card_idx = 0; card_idx < (int)(&g_PlayerActiveCardCount)[slot_idx]; card_idx = card_idx + 1)
    {
      if (((&g_CardSlot_SpecialState)[card_idx * 0x120 + slot_idx * 0x5b20] & 4) == 0) {
        val_1 = Card_IsTapped(slot_idx,card_idx);
        if (val_1 != 0) {
          for (match_count = 0; match_count < 7; match_count = match_count + 1) {
            (&DAT_006a603c)[match_count + slot_idx * 0x5b20 + card_idx * 0x120] = 0;
            (&DAT_006a6048)[match_count + slot_idx * 0x5b20 + card_idx * 0x120] =
                 (&DAT_006a603c)[match_count + slot_idx * 0x5b20 + card_idx * 0x120];
          }
          *(int *)(&g_CardSlot_SpecialState + card_idx * 0x120 + slot_idx * 0x5b20) = 0;
          Rules_ApplyContinuousDamage(slot_idx,card_idx,0x85);
          Rules_ApplyContinuousDamage(slot_idx,card_idx,0x84);
        }
      }
    }
  }
  return;
}



/*
 * Decompiled function: FUN_00476c77
 * Entry Point: 00476c77
 * Size: 475 bytes
 */


uint32_t FUN_00476c77(int x,int y,int width,int height)

{
  uint32_t uval_1;
  uint32_t slot_idx;
  
  slot_idx = 0;
  if (((&DAT_006a604f)[y * 0x120 + x * 0x5b20] == '\0') &&
     ((&DAT_006a604f)[height * 0x120 + width * 0x5b20] == '\0')) {
    uval_1 = 0;
  }
  else {
    if ((((&DAT_006a604f)[y * 0x120 + x * 0x5b20] & (&g_CardSlot_MinusOneCounters)[height * 0x120 + width * 0x5b20]
         & 0x3f) != 0) &&
       ((slot_idx = 1,
        (&g_MasterCardRarityTable)[*(int *)(&g_CardSlot_CardId + height * 0x120 + width * 0x5b20) * 0x34] ==
        '\0' && (((&DAT_006a604f)[y * 0x120 + x * 0x5b20] & 0x80) == 0)))) {
      slot_idx = 0;
    }
    uval_1 = slot_idx;
    if (((((&g_CardSlot_MinusOneCounters)[y * 0x120 + x * 0x5b20] &
           (&DAT_006a604f)[height * 0x120 + width * 0x5b20] & 0x3f) != 0) &&
        (uval_1 = slot_idx | 2,
        (&g_MasterCardRarityTable)[*(int *)(&g_CardSlot_CardId + y * 0x120 + x * 0x5b20) * 0x34] == '\0')) &&
       (((&DAT_006a604f)[height * 0x120 + width * 0x5b20] & 0x80) == 0)) {
      uval_1 = slot_idx;
    }
  }
  return uval_1;
}



/*
 * Decompiled function: Prompts_Load_00476e60
 * Entry Point: 00476e60
 * Size: 604 bytes
 */


int Prompts_Load_00476e60(LPCSTR filepath)

{
  ATOM AVar1;
  LOGFONTA *pLVar2;
  char local_138 [264];
  int local_30;
  WNDCLASSA local_2c;
  
  local_30 = 1;
  DAT_00695ecc = 2;
  DAT_0068a710 = 1;
  local_2c.style = 1;
  local_2c.lpfnWndProc = UI_Register_WINBK_TellUser_004771fa;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 4;
  local_2c.hInstance = g_AppHInstance;
  local_2c.hIcon = LoadIconA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = GetStockObject(2);
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = filepath;
  AVar1 = RegisterClassA(&local_2c);
  if (AVar1 == 0) {
    local_30 = 0;
  }
  strcpy(local_138,&g_AiCurrentChoiceIndex);
  strcat(local_138,s__WINBK_TellUser_pic_00525d2c);
  DAT_00538e40 = Pic_LoadKimPicture(local_138);
  Pic_Subsystem_00424500(s_prompts_txt_00525d50,s_BUTTONLABELS_00525d40);
  strcpy(&DAT_006b2d70,&g_OverworldGoldAmount);
  strcpy(&DAT_0068a680,&DAT_0069f84a);
  pLVar2 = (LOGFONTA *)FUN_004f58eb(s_TellUser_00525d5c,0);
  DAT_00538e14 = CreateFontIndirectA(pLVar2);
  pLVar2 = (LOGFONTA *)FUN_004f58eb(s_TellUser_00525d68,0);
  DAT_00538e08 = CreateFontIndirectA(pLVar2);
  DAT_00538e18 = CreatePen(0,0,0x10000cb);
  DAT_00538e44 = CreatePen(0,0,0x10000cd);
  DAT_00538e20 = CreatePen(0,0,0x10000cf);
  DAT_00538e0c = 0x10000b6;
  DAT_00538e10 = 0x10000c9;
  DAT_00538e2c = CreateSolidBrush(0x10000cd);
  DAT_00538e24 = CreatePen(0,0,0x10000cb);
  DAT_00538e1c = CreatePen(0,0,0x10000cf);
  DAT_00538e28 = DAT_00538e0c;
  if (((((DAT_00538e14 == (HFONT)0x0) || (DAT_00538e08 == (HFONT)0x0)) ||
       (DAT_00538e18 == (HPEN)0x0)) || ((DAT_00538e44 == (HPEN)0x0 || (DAT_00538e20 == (HPEN)0x0))))
     || ((DAT_00538e2c == (HBRUSH)0x0 ||
         ((DAT_00538e24 == (HPEN)0x0 || (DAT_00538e1c == (HPEN)0x0)))))) {
    local_30 = 0;
  }
  return local_30;
}



/*
 * Decompiled function: FUN_004770bc
 * Entry Point: 004770bc
 * Size: 318 bytes
 */


void FUN_004770bc(void)

{
  if (DAT_00538e40 != (HANDLE)0x0) {
    Pic_DestroyDIBSection(DAT_00538e40);
  }
  if (DAT_00538e14 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_00538e14);
  }
  if (DAT_00538e08 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_00538e08);
  }
  if (DAT_00538e18 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_00538e18);
  }
  if (DAT_00538e44 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_00538e44);
  }
  if (DAT_00538e20 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_00538e20);
  }
  if (DAT_00538e2c != (HGDIOBJ)0x0) {
    DeleteObject(DAT_00538e2c);
  }
  if (DAT_00538e24 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_00538e24);
  }
  if (DAT_00538e1c != (HGDIOBJ)0x0) {
    DeleteObject(DAT_00538e1c);
  }
  DAT_00538e40 = (HANDLE)0x0;
  DAT_00538e14 = (HGDIOBJ)0x0;
  DAT_00538e18 = (HGDIOBJ)0x0;
  DAT_00538e44 = (HGDIOBJ)0x0;
  DAT_00538e20 = (HGDIOBJ)0x0;
  DAT_00538e2c = (HGDIOBJ)0x0;
  DAT_00538e24 = (HGDIOBJ)0x0;
  DAT_00538e1c = (HGDIOBJ)0x0;
  return;
}



/*
 * Decompiled function: UI_Register_WINBK_TellUser_004771fa
 * Entry Point: 004771fa
 * Size: 2920 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint32_t UI_Register_WINBK_TellUser_004771fa(HWND hwnd,uint32_t y,LPSTR str_3,int height)

{
  BOOL BVar1;
  int cHeight;
  HBRUSH hbr;
  HGDIOBJ buf_ptr_2;
  uint32_t uval_3;
  char local_254 [264];
  HDC local_14c;
  tagPAINTSTRUCT local_148;
  CHAR local_108 [200];
  tagRECT local_40;
  LPCSTR local_30;
  int local_2c;
  HGDIOBJ local_28;
  HFONT local_24;
  tagRECT loop_idx;
  uint32_t card_idx;
  int match_count;
  LPSTR slot_idx;
  
  if (y < 0x10) {
    if (y == 0xf) {
      slot_idx = (LPSTR)GetWindowLongA(hwnd,0);
      local_14c = BeginPaint(hwnd,&local_148);
      if (local_14c != (HDC)0x0) {
        GDI_RealizeAndFlushPalette_Magic(local_14c);
        GetClientRect(hwnd,&local_40);
        if (DAT_00538e40 == (HANDLE)0x0) {
          strcpy(local_254,&g_AiCurrentChoiceIndex);
          strcat(local_254,s__WINBK_TellUser_pic_00525da0);
          DAT_00538e40 = (HANDLE)Pic_LoadKimPicture(local_254);
        }
        if (DAT_00538e40 == (HANDLE)0x0) {
          hbr = GetStockObject(1);
          FillRect(local_14c,&local_40,hbr);
        }
        else {
          FUN_004f3d11(local_14c,&local_40.left,DAT_00538e40);
        }
        SelectObject(local_14c,DAT_00538e18);
        MoveToEx(local_14c,0,0,(LPPOINT)0x0);
        LineTo(local_14c,local_40.right + -1,0);
        MoveToEx(local_14c,0,0,(LPPOINT)0x0);
        LineTo(local_14c,0,local_40.bottom + -1);
        SelectObject(local_14c,DAT_00538e44);
        MoveToEx(local_14c,1,1,(LPPOINT)0x0);
        LineTo(local_14c,local_40.right + -2,1);
        MoveToEx(local_14c,1,1,(LPPOINT)0x0);
        LineTo(local_14c,1,local_40.bottom + -2);
        SelectObject(local_14c,DAT_00538e20);
        MoveToEx(local_14c,2,2,(LPPOINT)0x0);
        LineTo(local_14c,local_40.right + -4,2);
        MoveToEx(local_14c,2,2,(LPPOINT)0x0);
        LineTo(local_14c,2,local_40.bottom + -4);
        buf_ptr_2 = GetStockObject(7);
        SelectObject(local_14c,buf_ptr_2);
        MoveToEx(local_14c,3,3,(LPPOINT)0x0);
        LineTo(local_14c,local_40.right + -4,3);
        MoveToEx(local_14c,3,3,(LPPOINT)0x0);
        LineTo(local_14c,3,local_40.bottom + -4);
        buf_ptr_2 = GetStockObject(7);
        SelectObject(local_14c,buf_ptr_2);
        MoveToEx(local_14c,0,local_40.bottom + -1,(LPPOINT)0x0);
        LineTo(local_14c,local_40.right,local_40.bottom + -1);
        MoveToEx(local_14c,local_40.right + -1,0,(LPPOINT)0x0);
        LineTo(local_14c,local_40.right + -1,local_40.bottom);
        SelectObject(local_14c,DAT_00538e20);
        MoveToEx(local_14c,1,local_40.bottom + -2,(LPPOINT)0x0);
        LineTo(local_14c,local_40.right + -1,local_40.bottom + -2);
        MoveToEx(local_14c,local_40.right + -2,1,(LPPOINT)0x0);
        LineTo(local_14c,local_40.right + -2,local_40.bottom + -1);
        SelectObject(local_14c,DAT_00538e44);
        MoveToEx(local_14c,2,local_40.bottom + -3,(LPPOINT)0x0);
        LineTo(local_14c,local_40.right + -2,local_40.bottom + -3);
        MoveToEx(local_14c,local_40.right + -3,2,(LPPOINT)0x0);
        LineTo(local_14c,local_40.right + -3,local_40.bottom + -2);
        SelectObject(local_14c,DAT_00538e18);
        MoveToEx(local_14c,2,local_40.bottom + -4,(LPPOINT)0x0);
        LineTo(local_14c,local_40.right + -3,local_40.bottom + -4);
        MoveToEx(local_14c,local_40.right + -4,2,(LPPOINT)0x0);
        LineTo(local_14c,local_40.right + -4,local_40.bottom + -3);
        GetWindowTextA(hwnd,local_108,200);
        SetBkMode(local_14c,1);
        FUN_0047820f(hwnd,local_14c,&local_40.left);
        DPtoLP(local_14c,(LPPOINT)&local_40,2);
        OffsetRect(&local_40,2,2);
        SetTextColor(local_14c,DAT_00538e10);
        Palette_Subsystem_0049e5bc(local_14c,&local_40.left,local_108,0);
        OffsetRect(&local_40,-2,-2);
        SetTextColor(local_14c,DAT_00538e0c);
        Palette_Subsystem_0049e5bc(local_14c,&local_40.left,local_108,1);
        EndPaint(hwnd,&local_148);
      }
      return 0;
    }
    if (y == 1) {
      slot_idx = DAT_00538e14;
      SetWindowLongA(hwnd,0,(LONG)DAT_00538e14);
      DAT_00676e38 = CreateWindowExA(0,s_BUTTON_00525d78,&DAT_00525d74,0x4080000b,0,0,0,0,hwnd,
                                     (HMENU)0x1,g_AppHInstance,(LPVOID)0x0);
      DAT_00676e34 = CreateWindowExA(0,s_BUTTON_00525d84,&DAT_00525d80,0x4080000b,0,0,0,0,hwnd,
                                     (HMENU)0x2,g_AppHInstance,(LPVOID)0x0);
      if ((DAT_00676e38 != (HWND)0x0) && (DAT_00676e34 != (HWND)0x0)) {
        GetClientRect(hwnd,&loop_idx);
        cHeight = (loop_idx.bottom * 2) / 100;
        if (cHeight < 0xd) {
          cHeight = 0xc;
        }
        local_24 = CreateFontA(cHeight,0,0,0,400,0,0,0,1,0,0,0,0,s_MS_Sans_Serif_00525d8c);
        SendMessageA(DAT_00676e38,0x30,(WPARAM)local_24,0);
        SendMessageA(DAT_00676e34,0x30,(WPARAM)local_24,0);
        return 0;
      }
      return 0xffffffff;
    }
    if (y == 2) {
      local_28 = (HGDIOBJ)SendMessageA(DAT_00676e38,0x31,0,0);
      SendMessageA(DAT_00676e38,0x30,0,0);
      SendMessageA(DAT_00676e34,0x30,0,0);
      DeleteObject(local_28);
      return 0;
    }
  }
  else if (y < 0x2c) {
    if (y == 0x2b) {
      local_2c = height;
      *(uint32_t *)(height + 0x10) = *(uint32_t *)(height + 0x10) & 0xffffffef;
      FUN_004f5107(height,DAT_00538e2c,DAT_00538e18,DAT_00538e20,DAT_00538e28,0);
      if (*(int *)(local_2c + 4) == 1) {
        local_30 = &DAT_006b2d70;
      }
      else if (*(int *)(local_2c + 4) == 2) {
        local_30 = &DAT_0068a680;
      }
      else {
        local_30 = &DAT_00525d9c;
      }
      SetMapMode(*(HDC *)(local_2c + 0x18),8);
      SetWindowExtEx(*(HDC *)(local_2c + 0x18),*(int *)(local_2c + 0x24) - *(int *)(local_2c + 0x1c)
                     ,0x18,(LPSIZE)0x0);
      SetViewportExtEx(*(HDC *)(local_2c + 0x18),
                       *(int *)(local_2c + 0x24) - *(int *)(local_2c + 0x1c),
                       *(int *)(local_2c + 0x28) - *(int *)(local_2c + 0x20),(LPSIZE)0x0);
      SelectObject(*(HDC *)(local_2c + 0x18),DAT_00538e08);
      SetTextColor(*(HDC *)(local_2c + 0x18),DAT_00538e28);
      if ((*(uint8_t *)(local_2c + 0x10) & 1) != 0) {
        OffsetRect((LPRECT)(local_2c + 0x1c),2,2);
      }
      DPtoLP(*(HDC *)(local_2c + 0x18),(LPPOINT)(local_2c + 0x1c),2);
      DrawTextA(*(HDC *)(local_2c + 0x18),local_30,-1,(LPRECT)(local_2c + 0x1c),0x25);
      return 1;
    }
    if (y == 0x14) {
      return 1;
    }
  }
  else if (y < 0x112) {
    if (y == 0x111) {
      if (((uint32_t)str_3 & 0xffff) == 1) {
        SendMessageA(hwnd,0x401,1,0);
      }
      else if (((uint32_t)str_3 & 0xffff) == 2) {
        SendMessageA(hwnd,0x401,2,0);
      }
      return 0;
    }
    if (y == 0x30) {
      slot_idx = str_3;
      if (str_3 == (LPSTR)0x0) {
        slot_idx = DAT_00538e14;
      }
      SetWindowLongA(hwnd,0,(LONG)slot_idx);
      InvalidateRect(hwnd,(RECT *)0x0,1);
      return 0;
    }
    if (y == 0x31) {
      uval_3 = GetWindowLongA(hwnd,0);
      return uval_3;
    }
  }
  else if (y < 0x312) {
    if (0x30e < y) {
      uval_3 = GDI_RealizePaletteTree_Magic(hwnd,y,(HWND)str_3,height);
      return uval_3;
    }
    if (y == 0x201) {
      SendMessageA(hwnd,0x112,0xf012,0);
      return 0;
    }
  }
  else {
    if (y == 0x401) {
      if ((DAT_006b1578 != 0) &&
         ((BVar1 = IsWindowVisible(DAT_00676e38), BVar1 != 0 ||
          (BVar1 = IsWindowVisible(DAT_00676e34), BVar1 != 0)))) {
        if (str_3 == (LPSTR)0x0) {
          BVar1 = IsWindowVisible(DAT_00676e34);
          if (BVar1 == 0) {
            match_count = 0xffffffff;
          }
          else {
            match_count = 0xfffffffe;
          }
        }
        else if (str_3 == (LPSTR)0x2) {
          match_count = 0xfffffffe;
        }
        else {
          match_count = 0xffffffff;
        }
        DAT_00627a84 = 0xffffffff;
        DAT_00627a88 = 0xffffffff;
        g_AiTemporaryCardState = 0;
        _DAT_00538e30 = 0xfffffffe;
        _DAT_00538e34 = 0xffffffff;
        _DAT_00538e38 = match_count;
        PostMessageA(g_MainAppHwnd,0x464,0,0x538e30);
      }
      return 0;
    }
    if (y == 0x402) {
      if (str_3 != (LPSTR)0x0) {
        GetWindowTextA(hwnd,str_3,200);
      }
      card_idx = 0;
      BVar1 = IsWindowVisible(DAT_00676e38);
      if (BVar1 != 0) {
        card_idx = card_idx | 1;
      }
      BVar1 = IsWindowVisible(DAT_00676e34);
      if (BVar1 == 0) {
        return card_idx;
      }
      return card_idx | 2;
    }
    if (y == 0x403) {
      FUN_00478163(hwnd);
      return 0;
    }
  }
  uval_3 = DefWindowProcA(hwnd,y,(WPARAM)str_3,height);
  return uval_3;
}



/*
 * Decompiled function: FUN_00477d73
 * Entry Point: 00477d73
 * Size: 1008 bytes
 */


void FUN_00477d73(HWND hwnd,char *mode_str,uint32_t arg_3)

{
  size_t len_1;
  HDC hdc;
  tagSIZE *psizl;
  tagRECT local_74;
  HDC local_64;
  tagRECT local_60;
  tagSIZE local_50;
  int local_48;
  int local_44;
  tagRECT local_40;
  int local_30;
  int local_2c;
  int local_28;
  uint32_t local_24;
  int loop_idx;
  int color_idx;
  int target_idx;
  tagRECT player_idx;
  
  local_48 = 4;
  loop_idx = 4;
  local_2c = 7;
  if (str_2 == (char *)0x0) {
LAB_00477daf:
    ShowWindow(hwnd,0);
  }
  else {
    len_1 = strlen(str_2);
    if (len_1 == 0) goto LAB_00477daf;
  }
  if ((arg_3 == 0) || ((arg_3 & 1) == 0)) {
    ShowWindow(DAT_00676e38,0);
  }
  if ((arg_3 == 0) || ((arg_3 & 2) == 0)) {
    ShowWindow(DAT_00676e34,0);
  }
  local_30 = 0;
  local_64 = GetDC(hwnd);
  GetClientRect(hwnd,&local_60);
  target_idx = (local_60.bottom - local_60.top) + loop_idx * -2;
  FUN_0047820f(hwnd,local_64,&local_60.left);
  psizl = &local_50;
  len_1 = strlen(&DAT_006b2d70);
  GetTextExtentPoint32A(local_64,&DAT_006b2d70,len_1,psizl);
  local_44 = local_50.cx + target_idx / 2;
  local_60.right = 2000;
  local_24 = Palette_Subsystem_0049e53b(local_64,(int)&local_60,(int)str_2);
  local_24 = local_24 & 0xffff;
  ReleaseDC(hwnd,local_64);
  if (((arg_3 & 2) != 0) || ((arg_3 & 1) != 0)) {
    SetWindowPos(DAT_00676e34,(HWND)0x0,0,0,local_44,target_idx,6);
    local_30 = local_30 + local_44 + local_2c;
  }
  if ((arg_3 & 1) != 0) {
    SetWindowPos(DAT_00676e38,(HWND)0x0,0,0,local_44,target_idx,6);
    local_30 = local_30 + local_44 + local_2c;
  }
  if (str_2 != (char *)0x0) {
    len_1 = strlen(str_2);
    if (len_1 != 0) {
      hdc = GetDC(hwnd);
      GetClientRect(hwnd,&local_74);
      FUN_0047820f(hwnd,hdc,&local_74.left);
      local_74.right = 2000;
      local_24 = Palette_Subsystem_0049e53b(hdc,(int)&local_74,(int)str_2);
      local_24 = local_24 & 0xffff;
      ReleaseDC(hwnd,hdc);
      SetWindowTextA(hwnd,str_2);
      goto LAB_00477fb6;
    }
  }
  local_24 = 0;
  SetWindowTextA(hwnd,&DAT_00525db4);
LAB_00477fb6:
  GetWindowRect(hwnd,&player_idx);
  SetWindowPos(hwnd,(HWND)0x0,0,0,local_48 * 2 + local_30 + local_24 + 0x19,
               player_idx.bottom - player_idx.top,6);
  GetClientRect(hwnd,&player_idx);
  color_idx = player_idx.left + local_48;
  if ((arg_3 & 2) != 0) {
    GetWindowRect(DAT_00676e34,&local_40);
    color_idx = color_idx + local_2c;
    local_28 = (player_idx.bottom - player_idx.top) / 2 - (local_40.bottom - local_40.top) / 2;
    SetWindowPos(DAT_00676e34,(HWND)0x0,color_idx,local_28,0,0,5);
  }
  if ((arg_3 & 1) != 0) {
    GetWindowRect(DAT_00676e38,&local_40);
    color_idx = color_idx + (local_40.right - local_40.left) + local_2c;
    local_28 = (player_idx.bottom - player_idx.top) / 2 - (local_40.bottom - local_40.top) / 2;
    SetWindowPos(DAT_00676e38,(HWND)0x0,color_idx,local_28,0,0,5);
  }
  FUN_00478163(hwnd);
  InvalidateRect(DAT_00676e38,(RECT *)0x0,1);
  InvalidateRect(DAT_00676e34,(RECT *)0x0,1);
  InvalidateRect(hwnd,(RECT *)0x0,1);
  if ((arg_3 & 1) != 0) {
    ShowWindow(DAT_00676e38,5);
  }
  if ((arg_3 & 2) != 0) {
    ShowWindow(DAT_00676e34,5);
  }
  if (str_2 != (char *)0x0) {
    len_1 = strlen(str_2);
    if (len_1 != 0) {
      ShowWindow(hwnd,5);
    }
  }
  FUN_004f59f7();
  UpdateWindow(hwnd);
  return;
}



/*
 * Decompiled function: FUN_00478163
 * Entry Point: 00478163
 * Size: 172 bytes
 */


void FUN_00478163(HWND hwnd)

{
  BOOL BVar1;
  tagRECT local_24;
  tagRECT player_idx;
  
  BVar1 = IsWindowVisible(DAT_006fe3fc);
  if (BVar1 == 0) {
    BVar1 = IsWindowVisible(g_AiDecisionMatrix_Row);
    if (BVar1 == 0) {
      GetWindowRect(g_AiSelectedActionCode,&local_24);
      GetWindowRect(hwnd,&player_idx);
      local_24.bottom = local_24.bottom - (player_idx.bottom - player_idx.top) / 2;
    }
    else {
      GetWindowRect(DAT_006b2e24,&local_24);
    }
  }
  else {
    GetWindowRect(DAT_006fe3fc,&local_24);
  }
  SetWindowPos(hwnd,(HWND)0x0,local_24.left,local_24.bottom,0,0,5);
  return;
}



/*
 * Decompiled function: FUN_0047820f
 * Entry Point: 0047820f
 * Size: 347 bytes
 */


void FUN_0047820f(HWND hwnd,HDC hdc,int *arg_3)

{
  BOOL BVar1;
  int val_2;
  tagRECT local_50;
  HGDIOBJ local_40;
  tagTEXTMETRICA local_3c;
  
  local_40 = (HGDIOBJ)GetWindowLongA(hwnd,0);
  if (local_40 != (HGDIOBJ)0x0) {
    SelectObject(hdc,local_40);
  }
  GetTextMetricsA(hdc,&local_3c);
  *arg_3 = *arg_3 + local_3c.tmHeight / 2;
  arg_3[1] = arg_3[1] + 4;
  arg_3[3] = arg_3[3] + -3;
  BVar1 = IsWindowVisible(DAT_00676e38);
  if (BVar1 != 0) {
    GetWindowRect(DAT_00676e38,&local_50);
    MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_50,2);
    val_2 = local_50.right + local_3c.tmHeight / 2;
    if (val_2 <= *arg_3) {
      val_2 = *arg_3;
    }
    *arg_3 = val_2;
  }
  BVar1 = IsWindowVisible(DAT_00676e34);
  if (BVar1 != 0) {
    GetWindowRect(DAT_00676e34,&local_50);
    MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_50,2);
    val_2 = local_50.right + local_3c.tmHeight / 2;
    if (val_2 <= *arg_3) {
      val_2 = *arg_3;
    }
    *arg_3 = val_2;
  }
  SetMapMode(hdc,8);
  SetWindowExtEx(hdc,arg_3[2] - *arg_3,0x14,(LPSIZE)0x0);
  SetViewportExtEx(hdc,arg_3[2] - *arg_3,arg_3[3] - arg_3[1],(LPSIZE)0x0);
  return;
}



/*
 * Decompiled function: FUN_00478370
 * Entry Point: 00478370
 * Size: 743 bytes
 */


int FUN_00478370(WPARAM arg_1,int y,int width,int height)

{
  int local_158;
  char local_154 [264];
  int local_4c;
  HBITMAP local_48;
  HDC local_44;
  int local_40;
  int local_3c;
  void *local_38;
  void *local_34;
  BITMAPINFO local_30;
  
  local_40 = 1;
  if (arg_1 == 0xffffffff) {
    local_40 = 0;
  }
  else {
    local_4c = FUN_0047865c(arg_1,y);
    if (local_4c != 0) {
      if ((*(int *)(local_4c + 8) == width) && (*(int *)(local_4c + 0xc) == height)) {
        return 1;
      }
      FUN_004788e0(arg_1,y);
    }
    if ((*(int *)(&DAT_006b30b4 + arg_1 * 0x98) < 2) || (y == 0)) {
      sprintf(local_154,s__s__04d_WVL_00525dc8,&g_CardArtDirectory,arg_1);
    }
    else {
      sprintf(local_154,s__s__04d_c_WVL_00525db8,&g_CardArtDirectory,arg_1,(int)(char)((char)y + '`'));
    }
    local_3c = Glue_Subsystem_004f15c0(1,local_154,0);
    if (local_3c == 0) {
      local_40 = 0;
    }
    else {
      local_44 = GetDC((HWND)0x0);
      GDI_RealizeAndFlushPalette_Magic(local_44);
      FUN_005017f0((int *)&local_30,width,height);
      local_48 = CreateDIBSection(local_44,&local_30,0,&local_38,(HANDLE)0x0,0);
      if (local_48 == (HBITMAP)0x0) {
        local_40 = 0;
      }
      else {
        local_34 = (void *)FUN_004f27c0(0,local_3c,width,height);
        if (local_34 == (void *)0x0) {
          local_40 = 0;
          DeleteObject(local_48);
        }
        else {
          if ((-width & 3U) == 0) {
            local_158 = 0;
          }
          else {
            local_158 = 4 - (-width & 3U);
          }
          memcpy(local_38,local_34,(width * 3 + local_158) * height);
        }
      }
      ReleaseDC((HWND)0x0,local_44);
      Glue_Util_004f1910(local_3c);
    }
    if (local_40 != 0) {
      if (0x13 < DAT_00680778) {
        FUN_004788e0(DAT_006fefc0,DAT_006fefc4);
      }
      *(HBITMAP *)(&DAT_006fefb0 + DAT_00680778 * 0x18) = local_48;
      *(void **)(&DAT_006fefb4 + DAT_00680778 * 0x18) = local_38;
      *(int *)(&DAT_006fefb8 + DAT_00680778 * 0x18) = width;
      *(int *)(&DAT_006fefbc + DAT_00680778 * 0x18) = height;
      (&DAT_006fefc0)[DAT_00680778 * 6] = arg_1;
      (&DAT_006fefc4)[DAT_00680778 * 6] = y;
      DAT_00680778 = DAT_00680778 + 1;
      PostMessageA(g_MainAppHwnd,0x434,arg_1,y);
    }
  }
  return local_40;
}



/*
 * Decompiled function: FUN_0047865c
 * Entry Point: 0047865c
 * Size: 151 bytes
 */


uint8_t * FUN_0047865c(int x,int arg2)

{
  uint8_t *match_count;
  int slot_idx;
  
  match_count = (uint8_t *)0x0;
  if (x == -1) {
    match_count = (uint8_t *)0x0;
  }
  else {
    slot_idx = 0;
    while ((slot_idx < DAT_00680778 && (match_count == (uint8_t *)0x0))) {
      if (((&DAT_006fefc0)[slot_idx * 6] == x) && ((&DAT_006fefc4)[slot_idx * 6] == arg2)) {
        match_count = &DAT_006fefb0 + slot_idx * 0x18;
      }
      slot_idx = slot_idx + 1;
    }
  }
  return match_count;
}



/*
 * Decompiled function: FUN_004786f3
 * Entry Point: 004786f3
 * Size: 112 bytes
 */


int FUN_004786f3(int x,int y,int width,int height)

{
  int slot_idx;
  
  if (x == -1) {
    slot_idx = 0;
  }
  else {
    slot_idx = FUN_0047865c(x,y);
    if ((slot_idx != 0) && ((*(int *)(slot_idx + 8) != width || (*(int *)(slot_idx + 0xc) != height))))
    {
      slot_idx = 0;
    }
  }
  return slot_idx;
}



/*
 * Decompiled function: FUN_00478763
 * Entry Point: 00478763
 * Size: 236 bytes
 */


int FUN_00478763(HDC hdc,RECT *arg_2,int width,int height)

{
  bool flag_1;
  HBRUSH hbr;
  int player_idx;
  int card_idx;
  int match_count;
  
  if (width == -1) {
    player_idx = 0;
  }
  else {
    match_count = 0;
    flag_1 = false;
    while ((match_count < DAT_00680778 && (!flag_1))) {
      if (((&DAT_006fefc0)[match_count * 6] == width) && ((&DAT_006fefc4)[match_count * 6] == height)) {
        flag_1 = true;
        card_idx = match_count;
      }
      match_count = match_count + 1;
    }
    if (flag_1) {
      player_idx = FUN_004f3b5f((int)hdc,(int)arg_2,*(HANDLE *)(&DAT_006fefb0 + card_idx * 0x18));
    }
    else {
      player_idx = 0;
    }
    if (player_idx == 0) {
      hbr = GetStockObject(2);
      FillRect(hdc,arg_2,hbr);
    }
  }
  return player_idx;
}



/*
 * Decompiled function: FUN_0047884f
 * Entry Point: 0047884f
 * Size: 135 bytes
 */


int FUN_0047884f(WPARAM arg_1,int y,int width,int height)

{
  int uval_1;
  int val_2;
  
  if (arg_1 == 0xffffffff) {
    uval_1 = 0;
  }
  else {
    val_2 = FUN_004786f3(arg_1,y,width,height);
    if (val_2 == 0) {
      FUN_004788e0(arg_1,y);
      val_2 = FUN_00478370(arg_1,y,width,height);
      if (val_2 == 0) {
        uval_1 = 0;
      }
      else {
        uval_1 = 1;
      }
    }
    else {
      uval_1 = 1;
    }
  }
  return uval_1;
}



/*
 * Decompiled function: FUN_004788e0
 * Entry Point: 004788e0
 * Size: 374 bytes
 */


void FUN_004788e0(int x,int arg2)

{
  bool flag_1;
  int card_idx;
  int match_count;
  
  if (x != -1) {
    match_count = 0;
    flag_1 = false;
    while ((match_count < DAT_00680778 && (!flag_1))) {
      if (((&DAT_006fefc0)[match_count * 6] == x) && ((&DAT_006fefc4)[match_count * 6] == arg2)) {
        flag_1 = true;
        if (*(int *)(&DAT_006fefb0 + match_count * 0x18) != 0) {
          DeleteObject(*(HGDIOBJ *)(&DAT_006fefb0 + match_count * 0x18));
        }
        DAT_00680778 = DAT_00680778 + -1;
        for (card_idx = match_count; card_idx < DAT_00680778; card_idx = card_idx + 1) {
          *(int *)(&DAT_006fefb0 + card_idx * 0x18) =
               *(int *)(&DAT_006fefb0 + (card_idx * 3 + 3) * 8);
          *(int *)(&DAT_006fefb4 + card_idx * 0x18) =
               *(int *)(&DAT_006fefb4 + (card_idx * 3 + 3) * 8);
          *(int *)(&DAT_006fefb8 + card_idx * 0x18) =
               *(int *)(&DAT_006fefb8 + (card_idx * 3 + 3) * 8);
          *(int *)(&DAT_006fefbc + card_idx * 0x18) =
               *(int *)(&DAT_006fefbc + (card_idx * 3 + 3) * 8);
          (&DAT_006fefc0)[card_idx * 6] = (&DAT_006fefc0)[(card_idx * 3 + 3) * 2];
          (&DAT_006fefc4)[card_idx * 6] = (&DAT_006fefc4)[(card_idx * 3 + 3) * 2];
        }
      }
      match_count = match_count + 1;
    }
  }
  return;
}



/*
 * Decompiled function: FUN_00478a56
 * Entry Point: 00478a56
 * Size: 78 bytes
 */


void FUN_00478a56(void)

{
  int slot_idx;
  
  for (slot_idx = 0; slot_idx < DAT_00680778; slot_idx = slot_idx + 1) {
    DeleteObject(*(HGDIOBJ *)(&DAT_006fefb0 + slot_idx * 0x18));
  }
  DAT_00680778 = 0;
  return;
}



/*
 * Decompiled function: FUN_00478aa4
 * Entry Point: 00478aa4
 * Size: 113 bytes
 */


int FUN_00478aa4(int player_id,int card_slot,int event_type)

{
  int val_1;
  
  if (arg_1 == -1) {
    val_1 = 0;
  }
  else if ((arg_2 == -1) || (arg_3 == -1)) {
    val_1 = 0;
  }
  else if (*(int *)(&DAT_006b30b4 + arg_1 * 0x98) < 2) {
    val_1 = 0;
  }
  else {
    val_1 = (arg_3 + arg_2) % *(int *)(&DAT_006b30b4 + arg_1 * 0x98);
  }
  return val_1;
}



/*
 * Decompiled function: UI_RegisterClass_00478b20
 * Entry Point: 00478b20
 * Size: 181 bytes
 */


uint8_t UI_RegisterClass_00478b20(LPCSTR str_1)

{
  uint8_t flag_1;
  ATOM AVar2;
  int val_3;
  int *arg_3;
  BITMAPINFO *arg_4;
  int *arg_5;
  int *arg_6;
  int *arg_7;
  WNDCLASSA local_2c;
  
  local_2c.style = 1;
  local_2c.lpfnWndProc = UI_WndProc_00478c08;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 0x28;
  local_2c.hInstance = g_AppHInstance;
  local_2c.hIcon = (HICON)0x0;
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = (HBRUSH)0x6;
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = str_1;
  AVar2 = RegisterClassA(&local_2c);
  arg_7 = (int *)0x0;
  arg_6 = (int *)0x0;
  arg_5 = &DAT_00538e58;
  arg_4 = (BITMAPINFO *)0x0;
  arg_3 = &DAT_00538e48;
  val_3 = GetSystemMetrics(3);
  flag_1 = FUN_004f39a4(1000,val_3 * 5,arg_3,arg_4,arg_5,arg_6,arg_7);
  return AVar2 != 0 & flag_1;
}



/*
 * Decompiled function: FUN_00478bd5
 * Entry Point: 00478bd5
 * Size: 51 bytes
 */


void FUN_00478bd5(void)

{
  FUN_004f3b2c(DAT_00538e48,DAT_00538e58);
  DAT_00538e48 = (HDC)0x0;
  DAT_00538e58 = (HGDIOBJ)0x0;
  return;
}



/*
 * Decompiled function: UI_WndProc_00478c08
 * Entry Point: 00478c08
 * Size: 4271 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint32_t UI_WndProc_00478c08(HWND hwnd,uint32_t uMsg,uint32_t *wParam,LONG *lParam)

{
  short len_1;
  LONG *pLVar2;
  LONG LVar3;
  uint32_t *puVar4;
  HWND pHVar5;
  HWND pHVar6;
  int val_7;
  HBRUSH pHVar8;
  uint32_t uVar9;
  WPARAM WVar10;
  tagRECT *lpPoints;
  HDC wParam_00;
  UINT UVar11;
  LPARAM lParam_00;
  uint8_t local_174 [4];
  int local_170;
  int local_16c;
  int local_15c;
  int local_158;
  int local_154;
  int local_150;
  int local_14c;
  int local_148;
  int local_144;
  int local_140;
  int local_13c;
  tagRECT local_138;
  HDC local_128;
  uint8_t local_124 [4];
  int local_120;
  int local_11c;
  int local_10c;
  tagPAINTSTRUCT local_108;
  int local_c8;
  tagRECT local_c4;
  int local_b4;
  int local_b0;
  int local_ac;
  tagRECT local_a8;
  tagRECT local_98;
  tagRECT local_88;
  int local_78;
  int local_74;
  tagRECT local_70;
  int local_60;
  int local_5c;
  tagRECT local_58;
  int local_48;
  int local_44;
  int local_40;
  tagRECT local_3c;
  uint32_t *local_2c;
  LONG *local_28;
  uint32_t *local_24;
  uint32_t *loop_idx;
  uint32_t *color_idx;
  int target_idx;
  LONG player_idx;
  uint32_t *card_idx;
  LONG *match_count;
  LONG *slot_idx;
  
  if (uMsg < 0x10) {
    if (uMsg == 0xf) {
      local_2c = (uint32_t *)GetWindowLongA(hwnd,0);
      player_idx = GetWindowLongA(hwnd,0x20);
      target_idx = GetWindowLongA(hwnd,0xc);
      color_idx = (uint32_t *)GetWindowLongA(hwnd,0x10);
      slot_idx = (LONG *)GetWindowLongA(hwnd,0x14);
      card_idx = (uint32_t *)GetWindowLongA(hwnd,0x18);
      local_28 = (LONG *)GetWindowLongA(hwnd,0x1c);
      loop_idx = (uint32_t *)GetWindowLongA(hwnd,0x24);
      local_24 = (uint32_t *)GetWindowLongA(hwnd,4);
      match_count = (LONG *)GetWindowLongA(hwnd,8);
      local_128 = BeginPaint(hwnd,&local_108);
      if (local_128 != (HDC)0x0) {
        GDI_RealizeAndFlushPalette_Magic(local_128);
        GetClientRect(hwnd,&local_88);
        local_b0 = SaveDC(DAT_00538e48);
        IntersectClipRect(DAT_00538e48,0,0,local_88.right,local_88.bottom);
        GetWindowRect(hwnd,&local_98);
        UVar11 = 2;
        lpPoints = &local_98;
        pHVar6 = GetParent(hwnd);
        MapWindowPoints((HWND)0x0,pHVar6,(LPPOINT)lpPoints,UVar11);
        OffsetViewportOrgEx(DAT_00538e48,-local_98.left,-local_98.top,(LPPOINT)0x0);
        lParam_00 = 0;
        UVar11 = 0x14;
        wParam_00 = DAT_00538e48;
        pHVar6 = GetParent(hwnd);
        SendMessageA(pHVar6,UVar11,(WPARAM)wParam_00,lParam_00);
        OffsetViewportOrgEx(DAT_00538e48,local_98.left,local_98.top,(LPPOINT)0x0);
        if (color_idx == (HANDLE)0x0) {
          pHVar8 = GetStockObject(2);
          FillRect(DAT_00538e48,&local_88,pHVar8);
        }
        else {
          CopyRect(&local_138,&local_88);
          GetObjectA(color_idx,0x18,local_124);
          local_138.left = -((int)local_2c % local_120);
          local_10c = local_88.bottom;
          local_ac = local_138.left;
          if (slot_idx == (LONG *)0x0) {
            local_c8 = ((local_120 / 2) * local_88.bottom) / local_11c;
            local_13c = local_120 / 2;
            local_140 = local_11c;
          }
          else {
            local_c8 = (local_120 * local_88.bottom) / (local_11c / 2);
            local_13c = local_120;
            local_140 = local_11c / 2;
          }
          for (; local_ac < local_138.right; local_ac = local_ac + local_13c) {
            for (local_b4 = local_138.top; local_b4 < local_138.bottom;
                local_b4 = local_b4 + local_140) {
              SetRect(&local_c4,local_ac,local_b4,local_ac + local_c8,local_b4 + local_10c);
              if (slot_idx == (LONG *)0x0) {
                FUN_004f3e29(DAT_00538e48,&local_c4,color_idx);
              }
              else {
                FUN_004f3eaa(DAT_00538e48,&local_c4.left,color_idx,local_120,local_11c / 2,0,0,0,
                             local_11c / 2);
              }
            }
          }
        }
        if (loop_idx != (uint32_t *)0x0) {
          local_150 = player_idx % (int)local_28;
          val_7 = FUN_00479d16(hwnd,player_idx);
          if ((uint32_t *)val_7 != local_2c) {
            player_idx = FUN_00479dac(hwnd,(int)local_2c);
            SetWindowLongA(hwnd,0x20,player_idx);
          }
          if ((card_idx == (HANDLE)0x0) || (local_28 == (LONG *)0x0)) {
            SetRect(&local_a8,player_idx - local_88.right / 0x14,0,player_idx + local_88.right / 0x14,
                    local_88.bottom);
            pHVar8 = GetStockObject(4);
            FillRect(DAT_00538e48,&local_a8,pHVar8);
          }
          else {
            GetObjectA(card_idx,0x18,local_174);
            local_158 = local_170 / 2;
            local_15c = local_16c / (int)local_28;
            local_14c = 0;
            local_154 = local_15c * local_150;
            local_148 = local_154;
            local_144 = local_158;
            FUN_00479e3f(hwnd,&local_a8);
            if (target_idx == 0) {
              SetMapMode(DAT_00538e48,8);
              SetWindowExtEx(DAT_00538e48,1,1,(LPSIZE)0x0);
              SetViewportExtEx(DAT_00538e48,-1,1,(LPSIZE)0x0);
              SetWindowOrgEx(DAT_00538e48,0,0,(LPPOINT)0x0);
              SetViewportOrgEx(DAT_00538e48,local_88.right,0,(LPPOINT)0x0);
              val_7 = local_88.right - local_a8.left;
              local_a8.left = local_88.right - local_a8.right;
              local_a8.right = val_7;
            }
            FUN_004f3eaa(DAT_00538e48,&local_a8.left,card_idx,local_158,local_15c,local_14c,
                         local_148,local_144,local_154);
            if (target_idx == 0) {
              SetMapMode(DAT_00538e48,1);
              SetWindowOrgEx(DAT_00538e48,0,0,(LPPOINT)0x0);
              SetViewportOrgEx(DAT_00538e48,0,0,(LPPOINT)0x0);
            }
          }
        }
        RestoreDC(DAT_00538e48,local_b0);
        BitBlt(local_128,0,0,local_88.right,local_88.bottom,DAT_00538e48,0,0,0xcc0020);
        EndPaint(hwnd,&local_108);
      }
      return 0;
    }
    if (uMsg == 1) {
      local_2c = (uint32_t *)0x0;
      local_24 = (uint32_t *)0x0;
      match_count = (LONG *)0x0;
      SetWindowLongA(hwnd,0,0);
      SetWindowLongA(hwnd,4,(LONG)local_24);
      SetWindowLongA(hwnd,8,(LONG)match_count);
      target_idx = 1;
      SetWindowLongA(hwnd,0xc,1);
      color_idx = (uint32_t *)0x0;
      slot_idx = (LONG *)0x0;
      SetWindowLongA(hwnd,0x10,0);
      SetWindowLongA(hwnd,0x14,(LONG)slot_idx);
      card_idx = (uint32_t *)0x0;
      local_28 = (LONG *)0x0;
      SetWindowLongA(hwnd,0x18,0);
      SetWindowLongA(hwnd,0x1c,(LONG)local_28);
      player_idx = 0;
      SetWindowLongA(hwnd,0x20,0);
      loop_idx = (uint32_t *)0x0;
      SetWindowLongA(hwnd,0x24,0);
      return 0;
    }
  }
  else if (uMsg < 0xe1) {
    if (uMsg == 0xe0) {
      puVar4 = (uint32_t *)GetWindowLongA(hwnd,0);
      if (puVar4 != wParam) {
        local_2c = wParam;
        SetWindowLongA(hwnd,0,(LONG)wParam);
        InvalidateRect(hwnd,(RECT *)0x0,1);
      }
      return 0;
    }
    if (uMsg == 0x14) {
      return 1;
    }
  }
  else {
    len_1 = (short)((uint32_t)lParam >> 0x10);
    if (uMsg < 0x201) {
      if (uMsg == 0x200) {
        pHVar6 = GetCapture();
        if (pHVar6 == hwnd) {
          target_idx = GetWindowLongA(hwnd,0xc);
          local_2c = (uint32_t *)GetWindowLongA(hwnd,0);
          local_24 = (uint32_t *)GetWindowLongA(hwnd,4);
          match_count = (LONG *)GetWindowLongA(hwnd,8);
          player_idx = GetWindowLongA(hwnd,0);
          local_44 = (int)(short)lParam;
          local_40 = (int)len_1;
          GetClientRect(hwnd,&local_3c);
          if (local_44 < 0) {
            local_44 = 0;
          }
          if (local_3c.right < local_44) {
            local_44 = local_3c.right;
          }
          if (local_40 < 0) {
            local_40 = 0;
          }
          if (local_3c.bottom < local_40) {
            local_40 = local_3c.bottom;
          }
          if (DAT_00538e50 < local_44) {
            if (target_idx == 0) {
              target_idx = 1;
              SetWindowLongA(hwnd,0xc,1);
              InvalidateRect(hwnd,(RECT *)0x0,1);
            }
          }
          else if ((local_44 < DAT_00538e50) && (target_idx != 0)) {
            target_idx = 0;
            SetWindowLongA(hwnd,0xc,0);
            InvalidateRect(hwnd,(RECT *)0x0,1);
          }
          local_48 = local_44;
          if (local_44 < (int)local_24) {
            local_48 = (int)local_24;
          }
          else if ((int)match_count < local_44) {
            local_48 = (int)match_count;
          }
          if (local_48 != player_idx) {
            player_idx = local_48;
            SetWindowLongA(hwnd,0x20,local_48);
            InvalidateRect(hwnd,(RECT *)0x0,1);
          }
          val_7 = FUN_00479d16(hwnd,local_44);
          if ((uint32_t *)val_7 != local_2c) {
            pHVar6 = hwnd;
            val_7 = FUN_00479d16(hwnd,local_44);
            WVar10 = CONCAT31((int3)((uint32_t)(val_7 << 0x10) >> 8),5);
            UVar11 = 0x114;
            pHVar5 = GetParent(hwnd);
            SendMessageA(pHVar5,UVar11,WVar10,(LPARAM)pHVar6);
          }
          UpdateWindow(hwnd);
          DAT_00538e50 = local_44;
          _DAT_00538e54 = local_40;
        }
        return 0;
      }
      if (uMsg == 0xe1) {
        uVar9 = GetWindowLongA(hwnd,0);
        return uVar9;
      }
      if (uMsg == 0xe2) {
        local_24 = (uint32_t *)GetWindowLongA(hwnd,4);
        pLVar2 = (LONG *)GetWindowLongA(hwnd,8);
        if ((local_24 != wParam) || (lParam != pLVar2)) {
          local_24 = wParam;
          match_count = lParam;
          SetWindowLongA(hwnd,4,(LONG)wParam);
          SetWindowLongA(hwnd,8,(LONG)match_count);
          InvalidateRect(hwnd,(RECT *)0x0,1);
        }
        return 0;
      }
      if (uMsg == 0xe3) {
        local_24 = (uint32_t *)GetWindowLongA(hwnd,4);
        LVar3 = GetWindowLongA(hwnd,8);
        if (wParam != (uint32_t *)0x0) {
          *wParam = (uint32_t)local_24;
        }
        if (lParam != (LONG *)0x0) {
          *lParam = LVar3;
        }
        return LVar3 << 0x10 | (uint32_t)local_24 & 0xffff;
      }
    }
    else if (uMsg < 0x312) {
      if (0x30e < uMsg) {
        uVar9 = GDI_RealizePaletteTree_Magic(hwnd,uMsg,(HWND)wParam,lParam);
        return uVar9;
      }
      if (uMsg == 0x201) {
        UpdateWindow(hwnd);
        player_idx = GetWindowLongA(hwnd,0x20);
        target_idx = GetWindowLongA(hwnd,0xc);
        loop_idx = (uint32_t *)GetWindowLongA(hwnd,0x24);
        local_60 = (int)(short)lParam;
        local_5c = (int)len_1;
        if (loop_idx == (uint32_t *)0x0) {
          return 0;
        }
        FUN_00479e3f(hwnd,&local_58);
        if ((local_60 < local_58.left) || (local_58.right < local_60)) {
          if (local_58.right < local_60) {
            if (target_idx == 0) {
              target_idx = 1;
              SetWindowLongA(hwnd,0xc,1);
              InvalidateRect(hwnd,(RECT *)0x0,1);
            }
            WVar10 = 1;
            UVar11 = 0x114;
            pHVar6 = GetParent(hwnd);
            SendMessageA(pHVar6,UVar11,WVar10,(LPARAM)hwnd);
          }
          else if (local_60 < local_58.left) {
            if (target_idx != 0) {
              target_idx = 0;
              SetWindowLongA(hwnd,0xc,0);
              InvalidateRect(hwnd,(RECT *)0x0,1);
            }
            WVar10 = 0;
            UVar11 = 0x114;
            pHVar6 = GetParent(hwnd);
            SendMessageA(pHVar6,UVar11,WVar10,(LPARAM)hwnd);
          }
        }
        else {
          SetCapture(hwnd);
        }
        DAT_00538e50 = local_60;
        _DAT_00538e54 = local_5c;
        return 0;
      }
      if (uMsg == 0x202) {
        pHVar6 = GetCapture();
        if (pHVar6 == hwnd) {
          ReleaseCapture();
          player_idx = GetWindowLongA(hwnd,0x20);
          local_78 = (int)(short)lParam;
          local_74 = (int)len_1;
          GetClientRect(hwnd,&local_70);
          if (local_78 < 0) {
            local_78 = 0;
          }
          if (local_70.right < local_78) {
            local_78 = local_70.right;
          }
          if (local_74 < 0) {
            local_74 = 0;
          }
          if (local_70.bottom < local_74) {
            local_74 = local_70.bottom;
          }
          player_idx = local_78;
          SetWindowLongA(hwnd,0x20,local_78);
          InvalidateRect(hwnd,(RECT *)0x0,1);
          pHVar6 = hwnd;
          val_7 = FUN_00479d16(hwnd,local_78);
          WVar10 = CONCAT31((int3)((uint32_t)(val_7 << 0x10) >> 8),4);
          UVar11 = 0x114;
          pHVar5 = GetParent(hwnd);
          SendMessageA(pHVar5,UVar11,WVar10,(LPARAM)pHVar6);
        }
        return 0;
      }
    }
    else {
      switch(uMsg) {
      case 0x432:
        InvalidateRect(hwnd,(RECT *)0x0,1);
        return 0;
      case 0x464:
        puVar4 = (uint32_t *)GetWindowLongA(hwnd,0x10);
        if (wParam != puVar4) {
          color_idx = wParam;
          slot_idx = lParam;
          SetWindowLongA(hwnd,0x10,(LONG)wParam);
          SetWindowLongA(hwnd,0x14,(LONG)slot_idx);
          InvalidateRect(hwnd,(RECT *)0x0,1);
        }
        return 0;
      case 0x465:
        uVar9 = GetWindowLongA(hwnd,0x10);
        if (wParam == (uint32_t *)0x0) {
          return uVar9;
        }
        *wParam = uVar9;
        return uVar9;
      case 0x466:
        card_idx = (uint32_t *)GetWindowLongA(hwnd,0x18);
        GetWindowLongA(hwnd,0x1c);
        if (wParam != card_idx) {
          card_idx = wParam;
          local_28 = lParam;
          SetWindowLongA(hwnd,0x18,(LONG)wParam);
          SetWindowLongA(hwnd,0x1c,(LONG)local_28);
          InvalidateRect(hwnd,(RECT *)0x0,1);
        }
        return 0;
      case 0x467:
        card_idx = (uint32_t *)GetWindowLongA(hwnd,0x18);
        LVar3 = GetWindowLongA(hwnd,0x1c);
        if (wParam != (uint32_t *)0x0) {
          *wParam = (uint32_t)card_idx;
        }
        if (lParam == (LONG *)0x0) {
          return (uint32_t)card_idx;
        }
        *lParam = LVar3;
        return (uint32_t)card_idx;
      case 0x468:
        puVar4 = (uint32_t *)GetWindowLongA(hwnd,0x24);
        if (wParam != puVar4) {
          loop_idx = wParam;
          SetWindowLongA(hwnd,0x24,(LONG)wParam);
          InvalidateRect(hwnd,(RECT *)0x0,1);
        }
        return 0;
      }
    }
  }
  uVar9 = DefWindowProcA(hwnd,uMsg,(WPARAM)wParam,(LPARAM)lParam);
  return uVar9;
}



/*
 * Decompiled function: FUN_00479d16
 * Entry Point: 00479d16
 * Size: 150 bytes
 */


int FUN_00479d16(HWND hwnd,int arg2)

{
  int val_1;
  LONG LVar2;
  tagRECT target_idx;
  int slot_idx;
  
  if (hwnd == (HWND)0x0) {
    val_1 = 0;
  }
  else {
    LVar2 = GetWindowLongA(hwnd,4);
    slot_idx = GetWindowLongA(hwnd,8);
    GetClientRect(hwnd,&target_idx);
    if (arg2 < target_idx.left) {
      arg2 = target_idx.left;
    }
    if (target_idx.right < arg2) {
      arg2 = target_idx.right;
    }
    val_1 = LVar2 + (((slot_idx - LVar2) + 1) * arg2) / target_idx.right;
  }
  return val_1;
}



/*
 * Decompiled function: FUN_00479dac
 * Entry Point: 00479dac
 * Size: 147 bytes
 */


int FUN_00479dac(HWND hwnd,int arg2)

{
  int val_1;
  LONG LVar2;
  tagRECT target_idx;
  int slot_idx;
  
  if (hwnd == (HWND)0x0) {
    val_1 = 0;
  }
  else {
    LVar2 = GetWindowLongA(hwnd,4);
    slot_idx = GetWindowLongA(hwnd,8);
    GetClientRect(hwnd,&target_idx);
    if (arg2 < LVar2) {
      arg2 = LVar2;
    }
    if (slot_idx < arg2) {
      arg2 = slot_idx;
    }
    val_1 = (target_idx.right * arg2) / ((slot_idx - LVar2) + 1);
  }
  return val_1;
}



/*
 * Decompiled function: FUN_00479e3f
 * Entry Point: 00479e3f
 * Size: 362 bytes
 */


void FUN_00479e3f(HWND hwnd,LPRECT arg2)

{
  LONG LVar1;
  uint8_t local_3c [4];
  int local_38;
  int local_34;
  int local_24;
  int loop_idx;
  LONG color_idx;
  HANDLE target_idx;
  tagRECT player_idx;
  
  if ((hwnd != (HWND)0x0) && (arg2 != (LPRECT)0x0)) {
    color_idx = GetWindowLongA(hwnd,0x20);
    target_idx = (HANDLE)GetWindowLongA(hwnd,0x18);
    LVar1 = GetWindowLongA(hwnd,0x1c);
    GetClientRect(hwnd,&player_idx);
    if ((target_idx == (HANDLE)0x0) || (LVar1 == 0)) {
      SetRect(arg2,color_idx - player_idx.right / 0x14,0,color_idx + player_idx.right / 0x14,
              player_idx.bottom);
    }
    else {
      GetObjectA(target_idx,0x18,local_3c);
      local_24 = player_idx.bottom;
      loop_idx = ((local_38 / 2) * player_idx.bottom) / (local_34 / LVar1);
      SetRect(arg2,color_idx - loop_idx / 2,0,(color_idx - loop_idx / 2) + loop_idx,player_idx.bottom);
    }
    if (arg2->left < player_idx.left) {
      OffsetRect(arg2,player_idx.left - arg2->left,0);
    }
    else if (player_idx.right < arg2->right) {
      OffsetRect(arg2,player_idx.right - arg2->right,0);
    }
  }
  return;
}



/*
 * Decompiled function: Mem_AllocOrFree_00479fb0
 * Entry Point: 00479fb0
 * Size: 44 bytes
 */


int Mem_AllocOrFree_00479fb0(int x,int arg2)

{
  if (arg2 == 2) {
    Mem_AllocOrFree_00479fdc(x);
  }
  return 0;
}



/*
 * Decompiled function: Mem_AllocOrFree_00479fdc
 * Entry Point: 00479fdc
 * Size: 29 bytes
 */


int Mem_AllocOrFree_00479fdc(int player_id)

{
  DAT_00525f28 = *(int *)(arg_1 + 0x2c);
  return 0;
}



/*
 * Decompiled function: FUN_00479ff9
 * Entry Point: 00479ff9
 * Size: 707 bytes
 */


int FUN_00479ff9(int x,int arg2)

{
  DWORD DVar1;
  int val_2;
  int val_3;
  int val_4;
  int card_slot;
  int event_type;
  int *piVar5;
  int arg_5;
  int target_idx;
  int player_idx;
  int *slot_idx;
  
  *(int *)g_DisplaySurfaceScreen = 1;
  val_2 = *(int *)(&DAT_00525f34 + x * 0x10);
  val_3 = *(int *)(&DAT_00525f30 + x * 0x10);
  piVar5 = (int *)g_DisplaySurfaceBackBuffer;
  DVar1 = Ai_Util_004c3bc4(0x2d);
  Surface_BlitToDevice((int *)g_DisplaySurfaceWork,*(uint32_t *)(&DAT_00525f30 + x * 0x10),
               *(int *)(&DAT_00525f34 + x * 0x10),
               g_AiManaColorCost_Red - *(int *)(&DAT_00525f30 + x * 0x10),DVar1,piVar5,val_3,val_2);
  switch(x) {
  case 0:
    slot_idx = &DAT_005394d8;
    break;
  case 1:
    slot_idx = (int *)&DAT_005394b0;
    break;
  case 2:
    slot_idx = (int *)&DAT_005394f8;
    break;
  case 3:
    slot_idx = (int *)&DAT_00539188;
  }
  switch(arg2) {
  case 0:
    target_idx = 0;
    player_idx = 0;
    break;
  case 1:
    target_idx = 1;
    player_idx = 1;
    break;
  case 2:
    target_idx = 1;
    player_idx = 2;
    break;
  case 3:
    target_idx = 2;
    player_idx = 3;
  }
  arg_2 = *(int *)(&DAT_00525f30 + x * 0x10) + (DAT_00525f84 - DAT_00525f80) / 2;
  arg_3 = *(int *)(&DAT_00525f34 + x * 0x10) + (DAT_00525f84 - DAT_00525f80) / 2;
  val_2 = Ai_Util_004c3bc4(2);
  val_3 = Ai_Util_004c3bc4(2);
  if (arg2 == 2) {
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,val_2 / 2 + arg_2,val_3 / 2 + arg_3,DAT_00525f80
                      ,DAT_00525f80,*(int *)(&DAT_005394e8 + player_idx * 4));
  }
  else {
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,arg_2,arg_3,DAT_00525f80,DAT_00525f80,
                      *(int *)(&DAT_005394e8 + player_idx * 4));
  }
  val_2 = slot_idx[target_idx];
  val_3 = *(int *)(&DAT_00525f38 + x * 0x10);
  arg_5 = DAT_00525f80;
  val_4 = Ai_Util_004c3bc4(0x24);
  Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,arg_2 + val_4,arg_3,val_3,arg_5,val_2);
  *(int *)g_DisplaySurfaceScreen = 0;
  val_2 = *(int *)(&DAT_00525f34 + x * 0x10);
  val_3 = *(int *)(&DAT_00525f30 + x * 0x10);
  piVar5 = (int *)g_DisplaySurfaceScreen;
  DVar1 = Ai_Util_004c3bc4(0x2d);
  Surface_BlitToDevice((int *)g_DisplaySurfaceBackBuffer,*(uint32_t *)(&DAT_00525f30 + x * 0x10),
               *(int *)(&DAT_00525f34 + x * 0x10),
               g_AiManaColorCost_Red - *(int *)(&DAT_00525f30 + x * 0x10),DVar1,piVar5,val_3,val_2);
  return 0;
}



/*
 * Decompiled function: Sprite_Load_begin_0047a2e6
 * Entry Point: 0047a2e6
 * Size: 1633 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int Sprite_Load_begin_0047a2e6(void)

{
  int val_1;
  int uval_2;
  int local_1ac;
  int local_1a8;
  int local_1a0 [100];
  int card_idx;
  char *match_count;
  int slot_idx;
  
  match_count = s_magic3_map_005269f4;
  do {
    strcpy(match_count,s_magic3_map_00526a00);
    DAT_00525f28 = -1;
    Surface_TransformPoint(0,(short)g_MidiMusicTrackId);
    FileIO_OpenFileStream(1,0,0,s_menubak_pic_00526a0c,
                 (short *)((int)&DAT_0070a130 + ((DAT_0070a880 == 8) - 1 & 0xff8f5ed1)));
    Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x280,0x1e0,
                       (int *)g_DisplaySurfaceScreen,0,0,g_AiManaColorCost_Red,g_AiManaColorCost_Green);
    Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x280,0x1e0,(int *)g_DisplaySurfaceWork
                       ,0,0,g_AiManaColorCost_Red,g_AiManaColorCost_Green);
    FUN_005115a0(0,(short)g_MidiMusicTrackId);
    *(int *)(g_DisplaySurfaceScreen + 0x20) = 5;
    *(int *)(g_DisplaySurfaceScreen + 0x20) = 1;
    _DAT_00525f98 = FUN_00406b01(match_count);
    for (slot_idx = 4; slot_idx < 0xe; slot_idx = slot_idx + 1) {
      if (slot_idx < 10) {
        match_count[5] = (char)slot_idx + '0';
      }
      else {
        match_count[5] = (char)slot_idx + 'W';
      }
      val_1 = FUN_00406b01(match_count);
      if (val_1 != 0) break;
    }
    if (slot_idx == 0xe) {
      _DAT_00525f94 = 0;
    }
    local_1ac = 0;
    Sprite_LoadAll(local_1a0,s_begin_spr_00526a18);
    for (local_1a8 = 0; local_1a8 < 2; local_1a8 = local_1a8 + 1) {
      (&DAT_005394d8)[local_1a8] = (void *)local_1a0[local_1ac];
      local_1ac = local_1ac + 1;
    }
    for (local_1a8 = 0; local_1a8 < 3; local_1a8 = local_1a8 + 1) {
      *(int *)(&DAT_005394b0 + local_1a8 * 4) = local_1a0[local_1ac];
      local_1ac = local_1ac + 1;
    }
    for (local_1a8 = 0; local_1a8 < 3; local_1a8 = local_1a8 + 1) {
      *(int *)(&DAT_005394f8 + local_1a8 * 4) = local_1a0[local_1ac];
      local_1ac = local_1ac + 1;
    }
    for (local_1a8 = 0; local_1a8 < 2; local_1a8 = local_1a8 + 1) {
      *(int *)(&DAT_005394c0 + local_1a8 * 4) = local_1a0[local_1ac];
      local_1ac = local_1ac + 1;
    }
    for (local_1a8 = 0; local_1a8 < 2; local_1a8 = local_1a8 + 1) {
      *(int *)(&DAT_00539188 + local_1a8 * 4) = local_1a0[local_1ac];
      local_1ac = local_1ac + 1;
    }
    for (local_1a8 = 0; local_1a8 < 2; local_1a8 = local_1a8 + 1) {
      *(int *)(&DAT_00538e60 + local_1a8 * 4) = local_1a0[local_1ac];
      local_1ac = local_1ac + 1;
    }
    for (local_1a8 = 0; local_1a8 < 4; local_1a8 = local_1a8 + 1) {
      *(int *)(&DAT_005394e8 + local_1a8 * 4) = local_1a0[local_1ac];
      local_1ac = local_1ac + 1;
    }
    if (DAT_00525de8 == DAT_00525dd8) {
      for (slot_idx = 0; slot_idx < 4; slot_idx = slot_idx + 1) {
        uval_2 = Ai_Util_004c3bc4(*(int *)(&DAT_00525f30 + slot_idx * 0x10));
        *(int *)(&DAT_00525f30 + slot_idx * 0x10) = uval_2;
        uval_2 = Ai_Util_004c3bc4(*(int *)(&DAT_00525f34 + slot_idx * 0x10));
        *(int *)(&DAT_00525f34 + slot_idx * 0x10) = uval_2;
        uval_2 = Ai_Util_004c3bc4(*(int *)(&DAT_00525f38 + slot_idx * 0x10));
        *(int *)(&DAT_00525f38 + slot_idx * 0x10) = uval_2;
        uval_2 = Ai_Util_004c3bc4(*(int *)(&DAT_00525f3c + slot_idx * 0x10));
        *(int *)(&DAT_00525f3c + slot_idx * 0x10) = uval_2;
        uval_2 = Ai_Util_004c3bc4((&DAT_00525de8)[slot_idx * 0x15]);
        (&DAT_00525de8)[slot_idx * 0x15] = uval_2;
        uval_2 = Ai_Util_004c3bc4(*(int *)(&DAT_00525dec + slot_idx * 0x54));
        *(int *)(&DAT_00525dec + slot_idx * 0x54) = uval_2;
        uval_2 = Ai_Util_004c3bc4(*(int *)(&DAT_00525df0 + slot_idx * 0x54));
        *(int *)(&DAT_00525df0 + slot_idx * 0x54) = uval_2;
        uval_2 = Ai_Util_004c3bc4(*(int *)(&DAT_00525df4 + slot_idx * 0x54));
        *(int *)(&DAT_00525df4 + slot_idx * 0x54) = uval_2;
      }
      DAT_00525f80 = Ai_Util_004c3bc4(DAT_00525f80);
      DAT_00525f84 = Ai_Util_004c3bc4(DAT_00525f84);
      DAT_00525f88 = Ai_Util_004c3bc4(DAT_00525f88);
    }
    card_idx = FUN_0041f354();
    Mem_AllocOrFree_0041f12b(card_idx);
    FUN_0041f17e(0x525dd8,4,card_idx);
    for (slot_idx = 0; slot_idx < 4; slot_idx = slot_idx + 1) {
      FUN_00479ff9(slot_idx,-(uint32_t)(*(int *)(&DAT_00525f90 + slot_idx * 4) == 0) & 3);
      if (*(int *)(&DAT_00525f90 + slot_idx * 4) == 0) {
        FUN_0041ece4((int)(&DAT_00525dd8 + slot_idx * 0x15));
      }
    }
    while (DAT_00525f28 == -1) {
      FUN_0041f3ea(g_MouseScreenCoordX,g_MouseScreenCoordY,g_MouseCursorButtonState);
    }
    FUN_0041f391();
    Mem_AllocOrFree_0041f12b(card_idx);
    Mem_AllocOrFree_0050fc50(DAT_005394d8);
    if (DAT_00525f28 != 4) {
      return DAT_00525f28 + -1;
    }
    UI_LoadHallBackdrop();
  } while( true );
}



/*
 * Decompiled function: FUN_0047a94c
 * Entry Point: 0047a94c
 * Size: 254 bytes
 */


int FUN_0047a94c(int x,int arg2)

{
  bool flag_1;
  int uval_2;
  
  if (g_MouseCaptureFlag == 0) {
    if ((g_MouseCursorX < *(int *)(x + 0x10)) ||
       (*(int *)(x + 0x18) + *(int *)(x + 0x10) < g_MouseCursorX)) {
      flag_1 = false;
    }
    else if ((g_MouseCursorY < *(int *)(x + 0x14)) ||
            (*(int *)(x + 0x14) + *(int *)(x + 0x1c) < g_MouseCursorY)) {
      flag_1 = false;
    }
    else {
      flag_1 = true;
    }
    if (!flag_1) {
      return 0;
    }
  }
  if (*(int *)(x + 0x40) == 3) {
    uval_2 = 0;
  }
  else {
    FUN_00479ff9((x + -0x525dd8) / 0x54,arg2);
    if ((arg2 == 2) && (*(int *)(x + 0x28) != 0)) {
      (**(code **)(x + 0x28))(x);
    }
    uval_2 = 1;
  }
  return uval_2;
}



/*
 * Decompiled function: Sound_LoadWav_x_sound_button2_0047aa4a
 * Entry Point: 0047aa4a
 * Size: 50 bytes
 */


int Sound_LoadWav_x_sound_button2_0047aa4a(int player_id)

{
  Glue_Subsystem_004ebcdc(s_x_sound_button2_wav_00526a24,0xf,100,100,0);
  DAT_00525f28 = *(int *)(arg_1 + 0x2c);
  return 0;
}



/*
 * Decompiled function: FUN_0047aa7c
 * Entry Point: 0047aa7c
 * Size: 368 bytes
 */


int FUN_0047aa7c(int x,int arg2)

{
  uint32_t arg_2;
  int event_type;
  uint32_t arg_4;
  DWORD arg_5;
  int val_1;
  uint32_t arg_4_00;
  DWORD arg_5_00;
  int *arg_6;
  int arg_7;
  int arg_8;
  int *target_idx;
  
  if (arg2 == 0) {
    target_idx = (int *)g_DisplaySurfaceBackBuffer;
  }
  else if (arg2 == 1) {
    target_idx = (int *)g_DisplaySurfaceWork;
  }
  else if (arg2 == 2) {
    target_idx = (int *)g_DisplaySurfaceWork;
  }
  arg_2 = *(uint32_t *)(&DAT_00526150 + x * 0x10);
  arg_3 = *(int *)(&DAT_00526154 + x * 0x10);
  arg_4 = *(uint32_t *)(&DAT_00526158 + x * 0x10);
  arg_5 = *(DWORD *)(&DAT_0052615c + x * 0x10);
  if (arg2 == 2) {
    arg_8 = 0;
    arg_7 = 0;
    arg_4_00 = arg_4;
    arg_5_00 = arg_5;
    arg_6 = (int *)g_DisplaySurfaceBackBuffer;
    val_1 = Ai_Util_004c3bc4(0x43);
    Surface_BlitToDevice((int *)g_DisplaySurfaceBackBuffer,200,arg_3 - val_1,arg_4_00,arg_5_00,arg_6,arg_7,
                 arg_8);
    Surface_StretchBlt(target_idx,arg_2,arg_3,arg_4,arg_5,(int *)g_DisplaySurfaceBackBuffer,4,4,
                       arg_4 - 4,arg_5 - 4);
    FUN_0050e040((int *)g_DisplaySurfaceBackBuffer,0,0,arg_4,arg_5,(int *)g_DisplaySurfaceScreen,
                 arg_2,arg_3);
  }
  else {
    FUN_0050e040(target_idx,arg_2,arg_3,arg_4,arg_5,(int *)g_DisplaySurfaceScreen,arg_2,arg_3);
  }
  return 0;
}



/*
 * Decompiled function: Pic_Load_menu2_hi_0047abf1
 * Entry Point: 0047abf1
 * Size: 945 bytes
 */


int Pic_Load_menu2_hi_0047abf1(void)

{
  int val_1;
  int val_2;
  int val_3;
  int val_4;
  int uval_5;
  int slot_idx;
  
  Surface_TransformPoint(0,(short)g_MidiMusicTrackId);
  FileIO_OpenFileStream(1,0,0,s_menu2_pic_00526a38,
               (short *)((int)&DAT_0070a130 + ((DAT_0070a880 == 8) - 1 & 0xff8f5ed1)));
  Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x280,0x1e0,(int *)g_DisplaySurfaceScreen
                     ,0,0,g_AiManaColorCost_Red,g_AiManaColorCost_Green);
  val_1 = Ai_Util_004c3bc4(0x19d);
  val_2 = Ai_Util_004c3bc4(0xa4);
  Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0x1b1,0x43,0xa4,0x19d,
                     (int *)g_DisplaySurfaceBackBuffer,200,0,val_2,val_1);
  FUN_005115a0(0,(short)g_MidiMusicTrackId);
  Mem_AllocOrFree_00510e20(1,s_menu2_norm_pic_00526a44);
  val_1 = Ai_Util_004c3bc4(0x19d);
  val_2 = Ai_Util_004c3bc4(0xa4);
  val_3 = Ai_Util_004c3bc4(0x43);
  val_4 = Ai_Util_004c3bc4(0x1b1);
  Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0xa4,0x19d,
                     (int *)g_DisplaySurfaceBackBuffer,val_4,val_3,val_2,val_1);
  Mem_AllocOrFree_00510e20(2,s_menu2_hi_pic_00526a54);
  val_1 = Ai_Util_004c3bc4(0x19d);
  val_2 = Ai_Util_004c3bc4(0xa4);
  val_3 = Ai_Util_004c3bc4(0x43);
  val_4 = Ai_Util_004c3bc4(0x1b1);
  Surface_StretchBlt((int *)g_DisplaySurfaceWork,0,0,0xa4,0x19d,(int *)g_DisplaySurfaceWork,val_4,
                     val_3,val_2,val_1);
  if (DAT_00525fb8 == DAT_00525fa8) {
    for (slot_idx = 0; slot_idx < 4; slot_idx = slot_idx + 1) {
      uval_5 = Ai_Util_004c3bc4(*(int *)(&DAT_00526150 + slot_idx * 0x10));
      *(int *)(&DAT_00526150 + slot_idx * 0x10) = uval_5;
      uval_5 = Ai_Util_004c3bc4(*(int *)(&DAT_00526154 + slot_idx * 0x10));
      *(int *)(&DAT_00526154 + slot_idx * 0x10) = uval_5;
      uval_5 = Ai_Util_004c3bc4(*(int *)(&DAT_00526158 + slot_idx * 0x10));
      *(int *)(&DAT_00526158 + slot_idx * 0x10) = uval_5;
      uval_5 = Ai_Util_004c3bc4(*(int *)(&DAT_0052615c + slot_idx * 0x10));
      *(int *)(&DAT_0052615c + slot_idx * 0x10) = uval_5;
      uval_5 = Ai_Util_004c3bc4((&DAT_00525fb8)[slot_idx * 0x15]);
      (&DAT_00525fb8)[slot_idx * 0x15] = uval_5;
      uval_5 = Ai_Util_004c3bc4(*(int *)(&DAT_00525fbc + slot_idx * 0x54));
      *(int *)(&DAT_00525fbc + slot_idx * 0x54) = uval_5;
      uval_5 = Ai_Util_004c3bc4(*(int *)(&DAT_00525fc0 + slot_idx * 0x54));
      *(int *)(&DAT_00525fc0 + slot_idx * 0x54) = uval_5;
      uval_5 = Ai_Util_004c3bc4(*(int *)(&DAT_00525fc4 + slot_idx * 0x54));
      *(int *)(&DAT_00525fc4 + slot_idx * 0x54) = uval_5;
    }
  }
  val_1 = FUN_0041f354();
  Mem_AllocOrFree_0041f12b(val_1);
  FUN_0041f17e(0x525fa8,5,val_1);
  for (slot_idx = 0; slot_idx < 4; slot_idx = slot_idx + 1) {
    FUN_0047aa7c(slot_idx,0);
  }
  DAT_00525f28 = -1;
  while (DAT_00525f28 == -1) {
    FUN_0041f3ea(g_MouseScreenCoordX,g_MouseScreenCoordY,g_MouseCursorButtonState);
  }
  FUN_0041f391();
  Mem_AllocOrFree_0041f12b(val_1);
  return DAT_00525f28 + -1;
}



/*
 * Decompiled function: FUN_0047afa2
 * Entry Point: 0047afa2
 * Size: 245 bytes
 */


int FUN_0047afa2(int x,int arg2)

{
  bool flag_1;
  int uval_2;
  
  if (g_MouseCaptureFlag == 0) {
    if ((g_MouseCursorX < *(int *)(x + 0x10)) ||
       (*(int *)(x + 0x18) + *(int *)(x + 0x10) < g_MouseCursorX)) {
      flag_1 = false;
    }
    else if ((g_MouseCursorY < *(int *)(x + 0x14)) ||
            (*(int *)(x + 0x14) + *(int *)(x + 0x1c) < g_MouseCursorY)) {
      flag_1 = false;
    }
    else {
      flag_1 = true;
    }
    if (!flag_1) {
      return 0;
    }
  }
  if (*(int *)(x + 0x40) == 3) {
    uval_2 = 0;
  }
  else {
    FUN_0047aa7c(*(int *)(x + 0x2c) + -1,arg2);
    if ((arg2 == 2) && (*(int *)(x + 0x28) != 0)) {
      (**(code **)(x + 0x28))(x);
    }
    uval_2 = 1;
  }
  return uval_2;
}



/*
 * Decompiled function: Sound_LoadWav_x_sound_button2_0047b097
 * Entry Point: 0047b097
 * Size: 50 bytes
 */


int Sound_LoadWav_x_sound_button2_0047b097(int player_id)

{
  Glue_Subsystem_004ebcdc(s_x_sound_button2_wav_00526a64,0xf,100,100,0);
  DAT_00525f28 = *(int *)(arg_1 + 0x2c);
  return 0;
}



/*
 * Decompiled function: FUN_0047b0c9
 * Entry Point: 0047b0c9
 * Size: 314 bytes
 */


int FUN_0047b0c9(int x,int arg2)

{
  uint32_t arg_2;
  int event_type;
  uint32_t arg_4;
  DWORD arg_5;
  int *slot_idx;
  
  if (arg2 == 0) {
    slot_idx = &DAT_00676d60;
  }
  else if (arg2 == 1) {
    slot_idx = (int *)&DAT_00676e20;
  }
  else if (arg2 == 2) {
    slot_idx = (int *)&DAT_00676e20;
  }
  arg_2 = *(uint32_t *)(&DAT_00526388 + x * 0x10);
  arg_3 = *(int *)(&DAT_0052638c + x * 0x10);
  arg_4 = *(uint32_t *)(&DAT_00526390 + x * 0x10);
  arg_5 = *(DWORD *)(&DAT_00526394 + x * 0x10);
  if (arg2 == 2) {
    Sprite_DrawScaled((int *)g_DisplaySurfaceWork,arg_2 + 2,arg_3 + 2,arg_4 - 4,arg_5 - 4,
                      slot_idx[x]);
    Surface_BlitToDevice((int *)g_DisplaySurfaceWork,arg_2,arg_3,arg_4,arg_5,(int *)g_DisplaySurfaceScreen,
                 arg_2,arg_3);
  }
  else {
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,arg_2,arg_3,arg_4,arg_5,slot_idx[x]);
  }
  return 0;
}



/*
 * Decompiled function: Pic_Load_menu3_but1_0047b208
 * Entry Point: 0047b208
 * Size: 1033 bytes
 */


int Pic_Load_menu3_but1_0047b208(void)

{
  int *i_ptr_1;
  int uval_2;
  int local_3c [4];
  int local_2c [4];
  int color_idx;
  int target_idx;
  int player_idx;
  int card_idx;
  int match_count;
  int slot_idx;
  
  Surface_TransformPoint(0,(short)g_MidiMusicTrackId);
  FileIO_OpenFileStream(1,0,0,s_menu3_pic_00526a78,
               (short *)((int)&DAT_0070a130 + ((DAT_0070a880 == 8) - 1 & 0xff8f5ed1)));
  Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x280,0x1e0,(int *)g_DisplaySurfaceScreen
                     ,0,0,g_AiManaColorCost_Red,g_AiManaColorCost_Green);
  Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x280,0x1e0,(int *)g_DisplaySurfaceWork,0
                     ,0,g_AiManaColorCost_Red,g_AiManaColorCost_Green);
  FUN_005115a0(0,(short)g_MidiMusicTrackId);
  i_ptr_1 = (int *)FUN_0050e6f0(local_2c,(int)g_DisplaySurfaceWork,0,0,g_AiManaColorCost_Red,g_AiManaColorCost_Green);
  player_idx = *i_ptr_1;
  card_idx = i_ptr_1[1];
  match_count = i_ptr_1[2];
  slot_idx = i_ptr_1[3];
  Mem_AllocOrFree_0050fc00();
  Mem_AllocOrFree_00510de0(1,s_menu3_but1_pic_00526a84);
  for (target_idx = 0; target_idx < 5; target_idx = target_idx + 1) {
    uval_2 = Sprite_EncodeFromSurface(1,0,target_idx * 0x4b,0x46,0x4b);
    (&DAT_00676d60)[target_idx] = (void *)uval_2;
  }
  Mem_AllocOrFree_00510de0(1,s_menu3but_pic_00526a94);
  for (target_idx = 0; target_idx < 5; target_idx = target_idx + 1) {
    uval_2 = Sprite_EncodeFromSurface(1,0,target_idx * 0x4b,0x46,0x4b);
    *(int *)(&DAT_00676e20 + target_idx * 4) = uval_2;
  }
  FUN_0050fc20();
  if (DAT_005261a0 == DAT_00526190) {
    for (target_idx = 0; target_idx < 5; target_idx = target_idx + 1) {
      uval_2 = Ai_Util_004c3bc4(*(int *)(&DAT_00526388 + target_idx * 0x10));
      *(int *)(&DAT_00526388 + target_idx * 0x10) = uval_2;
      uval_2 = Ai_Util_004c3bc4(*(int *)(&DAT_0052638c + target_idx * 0x10));
      *(int *)(&DAT_0052638c + target_idx * 0x10) = uval_2;
      uval_2 = Ai_Util_004c3bc4(*(int *)(&DAT_00526390 + target_idx * 0x10));
      *(int *)(&DAT_00526390 + target_idx * 0x10) = uval_2;
      uval_2 = Ai_Util_004c3bc4(*(int *)(&DAT_00526394 + target_idx * 0x10));
      *(int *)(&DAT_00526394 + target_idx * 0x10) = uval_2;
      uval_2 = Ai_Util_004c3bc4((&DAT_005261a0)[target_idx * 0x15]);
      (&DAT_005261a0)[target_idx * 0x15] = uval_2;
      uval_2 = Ai_Util_004c3bc4(*(int *)(&DAT_005261a4 + target_idx * 0x54));
      *(int *)(&DAT_005261a4 + target_idx * 0x54) = uval_2;
      uval_2 = Ai_Util_004c3bc4(*(int *)(&DAT_005261a8 + target_idx * 0x54));
      *(int *)(&DAT_005261a8 + target_idx * 0x54) = uval_2;
      uval_2 = Ai_Util_004c3bc4(*(int *)(&DAT_005261ac + target_idx * 0x54));
      *(int *)(&DAT_005261ac + target_idx * 0x54) = uval_2;
    }
  }
  color_idx = FUN_0041f354();
  Mem_AllocOrFree_0041f12b(color_idx);
  FUN_0041f17e(0x526190,6,color_idx);
  for (target_idx = 0; target_idx < 5; target_idx = target_idx + 1) {
    FUN_0047b0c9(target_idx,0);
  }
  DAT_00525f28 = -1;
  while (DAT_00525f28 == -1) {
    FUN_0041f3ea(g_MouseScreenCoordX,g_MouseScreenCoordY,g_MouseCursorButtonState);
  }
  FUN_0041f391();
  Mem_AllocOrFree_0041f12b(color_idx);
  Mem_AllocOrFree_0050fc50(DAT_00676d60);
  FUN_0050e6f0(local_3c,(int)g_DisplaySurfaceWork,player_idx,card_idx,match_count,slot_idx);
  if (DAT_00525f28 == 0) {
    uval_2 = 0xffffffff;
  }
  else {
    uval_2 = *(int *)(DAT_00525f28 * 4 + 0x5263d4);
  }
  return uval_2;
}



/*
 * Decompiled function: FUN_0047b616
 * Entry Point: 0047b616
 * Size: 245 bytes
 */


int FUN_0047b616(int x,int arg2)

{
  bool flag_1;
  int uval_2;
  
  if (g_MouseCaptureFlag == 0) {
    if ((g_MouseCursorX < *(int *)(x + 0x10)) ||
       (*(int *)(x + 0x18) + *(int *)(x + 0x10) < g_MouseCursorX)) {
      flag_1 = false;
    }
    else if ((g_MouseCursorY < *(int *)(x + 0x14)) ||
            (*(int *)(x + 0x14) + *(int *)(x + 0x1c) < g_MouseCursorY)) {
      flag_1 = false;
    }
    else {
      flag_1 = true;
    }
    if (!flag_1) {
      return 0;
    }
  }
  if (*(int *)(x + 0x40) == 3) {
    uval_2 = 0;
  }
  else {
    FUN_0047b0c9(*(int *)(x + 0x2c) + -1,arg2);
    if ((arg2 == 2) && (*(int *)(x + 0x28) != 0)) {
      (**(code **)(x + 0x28))(x);
    }
    uval_2 = 1;
  }
  return uval_2;
}



/*
 * Decompiled function: Sound_LoadWav_x_sound_button2_0047b70b
 * Entry Point: 0047b70b
 * Size: 50 bytes
 */


int Sound_LoadWav_x_sound_button2_0047b70b(int player_id)

{
  Glue_Subsystem_004ebcdc(s_x_sound_button2_wav_00526aa4,0xf,100,100,0);
  DAT_00525f28 = *(int *)(arg_1 + 0x2c);
  return 0;
}



/*
 * Decompiled function: FUN_0047b73d
 * Entry Point: 0047b73d
 * Size: 343 bytes
 */


int FUN_0047b73d(int x,int arg2)

{
  uint32_t arg_2;
  int event_type;
  uint32_t arg_4;
  DWORD arg_5;
  int *slot_idx;
  
  if (arg2 == 0) {
    slot_idx = &DAT_00676dd0;
  }
  else if (arg2 == 1) {
    slot_idx = &DAT_00676d80;
  }
  else if (arg2 == 2) {
    slot_idx = &DAT_00676d80;
  }
  arg_2 = Ai_Util_004c3bc4(*(int *)(&DAT_005263f0 + x * 0x54) + 0x1d);
  arg_3 = Ai_Util_004c3bc4(*(int *)(&DAT_005263f4 + x * 0x54));
  arg_4 = Ai_Util_004c3bc4(0x4d);
  arg_5 = Ai_Util_004c3bc4(0x5f);
  if (arg2 == 2) {
    Sprite_DrawScaled((int *)g_DisplaySurfaceWork,arg_2 + 4,arg_3 + 4,arg_4 - 4,arg_5 - 4,
                      slot_idx[x]);
    Surface_BlitToDevice((int *)g_DisplaySurfaceWork,arg_2,arg_3,arg_4,arg_5,(int *)g_DisplaySurfaceScreen,
                 arg_2,arg_3);
  }
  else {
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,arg_2,arg_3,arg_4,arg_5,slot_idx[x]);
  }
  return 0;
}



/*
 * Decompiled function: Sprite_Load__16faces_0047b899
 * Entry Point: 0047b899
 * Size: 1112 bytes
 */


int Sprite_Load__16faces_0047b899(void)

{
  int *i_ptr_1;
  int val_2;
  int local_90 [4];
  int local_80 [4];
  int local_70 [4];
  int local_60 [9];
  int *local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  char *local_24;
  int loop_idx;
  int color_idx;
  int target_idx;
  int player_idx;
  int card_idx;
  int match_count;
  int slot_idx;
  
  Surface_TransformPoint(0,(short)g_MidiMusicTrackId);
  FileIO_OpenFileStream(1,0,0,s_pedstls_pic_00526ab8,
               (short *)((int)&DAT_0070a130 + ((DAT_0070a880 == 8) - 1 & 0xff8f5ed1)));
  Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x280,0x1e0,(int *)g_DisplaySurfaceScreen
                     ,0,0,g_AiManaColorCost_Red,g_AiManaColorCost_Green);
  Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x280,0x1e0,(int *)g_DisplaySurfaceWork,0
                     ,0,g_AiManaColorCost_Red,g_AiManaColorCost_Green);
  FUN_005115a0(0,(short)g_MidiMusicTrackId);
  LoadPalNoPic(s_pedstls_pic_00526ac4);
  i_ptr_1 = (int *)FUN_0050e6f0(local_70,(int)g_DisplaySurfaceWork,0,0,g_AiManaColorCost_Red,g_AiManaColorCost_Green);
  player_idx = *i_ptr_1;
  card_idx = i_ptr_1[1];
  match_count = i_ptr_1[2];
  slot_idx = i_ptr_1[3];
  Sprite_LoadAll(&DAT_00676dd0,s_16facesLow_spr_00526ad0);
  Sprite_LoadAll(&DAT_00676d80,s_16faces_spr_00526ae0);
  FUN_0040b441((int *)&DAT_005263f0,0xe);
  color_idx = FUN_0041f354();
  Mem_AllocOrFree_0041f12b(color_idx);
  FUN_0041f17e(0x5263f0,0xf,color_idx);
  for (target_idx = 0; target_idx < 0xe; target_idx = target_idx + 1) {
    FUN_0047b73d(target_idx,0);
  }
  DAT_00525f28 = -1;
  while (DAT_00525f28 == -1) {
    FUN_0041f3ea(g_MouseScreenCoordX,g_MouseScreenCoordY,g_MouseCursorButtonState);
  }
  if (DAT_00525f28 == 0) {
    FUN_0041f391();
    Mem_AllocOrFree_0041f12b(color_idx);
    val_2 = -1;
  }
  else {
    FUN_0047c2fd(DAT_00525f28 + -1);
    FUN_0041f391();
    Mem_AllocOrFree_0041f12b(color_idx);
    local_60[0] = 4;
    local_60[1] = 0;
    local_60[2] = 0;
    local_60[3] = 800;
    local_60[4] = 600;
    local_60[5] = 1;
    local_60[6] = 0xf;
    local_60[7] = 4;
    local_60[8] = 0;
    local_3c = local_60;
    loop_idx = (&DAT_00676d7c)[DAT_00525f28];
    local_28 = (int)*(short *)(loop_idx + 4);
    local_2c = (int)*(short *)(loop_idx + 6);
    local_34 = Memory_AllocateVirtualPage(4,local_28 * 2,local_2c,8);
    FUN_0050d370(4,local_34);
    FUN_0050e6f0(local_80,(int)local_3c,0,0,local_28 * 2,local_2c);
    LoadPalNoPic(s_menu4_pic_00526aec);
    Surface_FillRect(local_3c,0,0,local_28,local_2c,0);
    Sprite_DrawDirect(local_3c,0,0,loop_idx);
    for (local_38 = 0; local_38 < local_2c; local_38 = local_38 + 1) {
      local_24 = (char *)((*(int *)(DAT_0070a860 + 0x2c) + *(int *)(DAT_0070a860 + 0x20)) * local_38
                         + *(int *)(DAT_0070a860 + 0x18));
      for (local_30 = 0; local_30 < local_28; local_30 = local_30 + 1) {
        if (*local_24 == '\0') {
          local_24[local_28] = -1;
        }
        local_24 = local_24 + 1;
      }
    }
    DAT_0067bdd8 = *(int *)(DAT_0070a860 + 8);
    DAT_0067bdd4 = DAT_0070a860;
    SelectObject(*(HDC *)(DAT_0070a860 + 4),*(HGDIOBJ *)(DAT_0070a860 + 0xc));
    DAT_0070a860 = 0;
    Mem_AllocOrFree_0050fc50(DAT_00676dd0);
    Mem_AllocOrFree_0050fc50(DAT_00676d80);
    FUN_0050e6f0(local_90,(int)g_DisplaySurfaceWork,player_idx,card_idx,match_count,slot_idx);
    memset(s_Ned_Way_the_Ratiocinator_0052f020,0,0x40);
    strcpy(s_Ned_Way_the_Ratiocinator_0052f020,*(char **)(DAT_00525f28 * 4 + 0x5268dc));
    DAT_00676dc8 = strlen(s_Ned_Way_the_Ratiocinator_0052f020);
    Pic_Load_namepick_0047be64(s_Ned_Way_the_Ratiocinator_0052f020);
    strcpy(&DAT_0068a6a0,s_Ned_Way_the_Ratiocinator_0052f020);
    val_2 = DAT_00525f28 + -1;
  }
  return val_2;
}



/*
 * Decompiled function: FUN_0047bcf1
 * Entry Point: 0047bcf1
 * Size: 371 bytes
 */


void FUN_0047bcf1(int *arg_1,int card_slot,int event_type,int arg_4,int arg_5,int *arg_6,
                 int arg_7,int arg_8)

{
  int local_3fc;
  int local_3f8;
  char local_3f4 [1000];
  char *match_count;
  uint32_t slot_idx;
  
  for (local_3fc = 0; local_3fc < arg_5; local_3fc = local_3fc + 1) {
    Surface_GetLine((int *)local_3f4,*arg_1,arg_2,local_3fc + arg_3,arg_4);
    if (local_3f4[0] == '\0') {
      match_count = (char *)0x0;
    }
    else {
      match_count = local_3f4;
    }
    slot_idx = 0;
    for (local_3f8 = 0; local_3f8 < arg_4; local_3f8 = local_3f8 + 1) {
      if (local_3f4[local_3f8] == '\0') {
        if (slot_idx == 0) {
          match_count = local_3f4 + local_3f8;
        }
        else {
          Surface_PutLine((int *)match_count,*arg_6,(int)(match_count + (arg_7 - (int)local_3f4)),
                          local_3fc + arg_8,slot_idx);
          slot_idx = 0;
          match_count = local_3f4 + local_3f8;
        }
      }
      else {
        slot_idx = slot_idx + 1;
      }
    }
    if (slot_idx != 0) {
      Surface_PutLine((int *)match_count,*arg_6,(int)(match_count + (arg_7 - (int)local_3f4)),
                      local_3fc + arg_8,slot_idx);
    }
  }
  return;
}



/*
 * Decompiled function: Pic_Load_namepick_0047be64
 * Entry Point: 0047be64
 * Size: 540 bytes
 */


void Pic_Load_namepick_0047be64(char *filepath)

{
  int val_1;
  uint32_t arg_2;
  int val_2;
  int val_3;
  int val_4;
  char *str_5;
  
  Mem_AllocOrFree_00510de0(1,s_namepick_pic_00526af8);
  *(int *)(g_DisplaySurfaceBackBuffer + 0x20) =
       *(int *)(g_DisplaySurfaceScreen + 0x20);
  FUN_0040d009((int)g_DisplaySurfaceBackBuffer,0xed,0x8b,0x19);
  FUN_0040d009((int)g_DisplaySurfaceBackBuffer,0xb4,0x8a,0x18);
  Surface_BlitToDevice((int *)g_DisplaySurfaceBackBuffer,0,0,0x114,0x6a,(int *)g_DisplaySurfaceBackBuffer,0,
               200);
  FUN_0040d009((int)g_DisplaySurfaceBackBuffer,0xb4,0x8a,0x100);
  val_1 = Ai_Util_004c3bc4(0xbc);
  FUN_0047bcf1((int *)g_DisplaySurfaceBackBuffer,0,200,0x114,0x6a,
               (int *)g_DisplaySurfaceScreen,(g_AiManaColorCost_Red + -0x114) / 2,val_1);
  while( true ) {
    arg_2 = Util_CopyMemoryBuffer();
    if (arg_2 == 0x1c0d) break;
    val_1 = FUN_0050f440((int *)g_DisplaySurfaceBackBuffer,filepath);
    if (arg_2 != 0) {
      FUN_0047c360(filepath,arg_2,0x19);
      Surface_BlitToDevice((int *)g_DisplaySurfaceBackBuffer,0,0,0x114,0x6a,
                   (int *)g_DisplaySurfaceBackBuffer,0,200);
      FUN_0040d009((int)g_DisplaySurfaceBackBuffer,0xb4,0x8a,0x100);
      val_2 = Ai_Util_004c3bc4(0xbc);
      FUN_0047bcf1((int *)g_DisplaySurfaceBackBuffer,0,200,0x114,0x6a,
                   (int *)g_DisplaySurfaceScreen,(g_AiManaColorCost_Red + -0x114) / 2,val_2);
    }
    str_5 = filepath;
    val_2 = DAT_00676dc8;
    val_3 = Ai_Util_004c3bc4(0xbc);
    val_3 = val_3 + 0x30;
    val_4 = Ai_Util_004c3bc4(0x140);
    FUN_0041fec7((int)g_DisplaySurfaceScreen,0xb4,val_4 - val_1 / 2,val_3,str_5,val_2);
  }
  Ai_Subsystem_004cd1d1();
  return;
}



/*
 * Decompiled function: FUN_0047c080
 * Entry Point: 0047c080
 * Size: 245 bytes
 */


int FUN_0047c080(int x,int arg2)

{
  bool flag_1;
  int uval_2;
  
  if (g_MouseCaptureFlag == 0) {
    if ((g_MouseCursorX < *(int *)(x + 0x10)) ||
       (*(int *)(x + 0x18) + *(int *)(x + 0x10) < g_MouseCursorX)) {
      flag_1 = false;
    }
    else if ((g_MouseCursorY < *(int *)(x + 0x14)) ||
            (*(int *)(x + 0x14) + *(int *)(x + 0x1c) < g_MouseCursorY)) {
      flag_1 = false;
    }
    else {
      flag_1 = true;
    }
    if (!flag_1) {
      return 0;
    }
  }
  if (*(int *)(x + 0x40) == 3) {
    uval_2 = 0;
  }
  else {
    FUN_0047b73d(*(int *)(x + 0x2c) + -1,arg2);
    if ((arg2 == 2) && (*(int *)(x + 0x28) != 0)) {
      (**(code **)(x + 0x28))(x);
    }
    uval_2 = 1;
  }
  return uval_2;
}



/*
 * Decompiled function: Sound_LoadWav_x_sound_button2_0047c175
 * Entry Point: 0047c175
 * Size: 50 bytes
 */


int Sound_LoadWav_x_sound_button2_0047c175(int player_id)

{
  Glue_Subsystem_004ebcdc(s_x_sound_button2_wav_00526b30,0xf,100,100,0);
  DAT_00525f28 = *(int *)(arg_1 + 0x2c);
  return 0;
}



/*
 * Decompiled function: Sprite_Load__16faces_0047c1a7
 * Entry Point: 0047c1a7
 * Size: 87 bytes
 */


void Sprite_Load__16faces_0047c1a7(int player_id)

{
  Sprite_LoadAll(&DAT_00676dd0,s_16facesLow_spr_00526b44);
  Sprite_LoadAll(&DAT_00676d80,s_16faces_spr_00526b54);
  FUN_0047c2fd(arg_1);
  Mem_AllocOrFree_0050fc50(DAT_00676dd0);
  Mem_AllocOrFree_0050fc50(DAT_00676d80);
  return;
}



/*
 * Decompiled function: Pic_Load_advfac64_0047c1fe
 * Entry Point: 0047c1fe
 * Size: 255 bytes
 */


int Pic_Load_advfac64_0047c1fe(int *arg_1,int y,int width,int height)

{
  int uval_1;
  int loop_idx [2];
  int target_idx;
  uint32_t player_idx [3];
  int slot_idx;
  
  slot_idx = height;
  if (height == 0) {
    uval_1 = 0;
  }
  else {
    Surface_FillRect(arg_1,y,width,*(short *)(height + 4) + 2,*(short *)(height + 6) + 2,0);
    Sprite_DrawDirect(arg_1,y,width,height);
    FUN_00488fdb(arg_1,y,width,(int)*(short *)(slot_idx + 4),(int)*(short *)(slot_idx + 6),
                 s_pedstls_pic_00526b70,s_advfac64_pic_00526b60);
    FUN_0048ed04(height,player_idx,loop_idx);
    target_idx = (int)*(short *)(slot_idx + 0xc);
    uval_1 = Sprite_EncodeFromSurface
                      (*arg_1,y + player_idx[0],width + target_idx,(loop_idx[0] - player_idx[0]) + 1,
                       (((int)*(short *)(slot_idx + 0xc) + (int)*(short *)(slot_idx + 0xe)) - target_idx
                       ) + 1);
  }
  return uval_1;
}



/*
 * Decompiled function: FUN_0047c2fd
 * Entry Point: 0047c2fd
 * Size: 99 bytes
 */


int FUN_0047c2fd(int player_id)

{
  Mem_AllocOrFree_0050fc00();
  DAT_00676d78 = Pic_Load_advfac64_0047c1fe
                           ((int *)g_DisplaySurfaceBackBuffer,0,0,(&DAT_00676dd0)[arg_1]);
  DAT_00676d7c = Pic_Load_advfac64_0047c1fe
                           ((int *)g_DisplaySurfaceBackBuffer,0,0,(&DAT_00676d80)[arg_1]);
  FUN_0050fc20();
  return DAT_00676d78;
}



/*
 * Decompiled function: FUN_0047c360
 * Entry Point: 0047c360
 * Size: 716 bytes
 */


int FUN_0047c360(char *filepath,uint32_t arg_2,uint32_t arg_3)

{
  uint32_t uval_1;
  size_t len_2;
  
  len_2 = DAT_00676dc8;
  if ((int)arg_2 < 0xf0a) {
    if (arg_2 == 0xf09) {
      DAT_00676dc8 = DAT_00676dc8 + 8;
      if ((int)DAT_00676dc8 < (int)arg_3) {
        return 0;
      }
      DAT_00676dc8 = arg_3;
      return 0;
    }
    if (arg_2 == 0xe08) {
      if (DAT_00676dc8 == 0) {
        return 0;
      }
      DAT_00676dc8 = DAT_00676dc8 - 1;
      strcpy(str_1 + DAT_00676dc8,str_1 + len_2);
      return 0;
    }
  }
  else if ((int)arg_2 < 0x1c0e) {
    if (arg_2 == 0x1c0d) {
      return 1;
    }
    if (arg_2 == 0xf0f) {
      DAT_00676dc8 = DAT_00676dc8 - 8;
      if (0 < (int)DAT_00676dc8) {
        return 0;
      }
      DAT_00676dc8 = 0;
      return 0;
    }
  }
  else if ((int)arg_2 < 0x4b01) {
    if (arg_2 == 0x4b00) {
      if ((int)DAT_00676dc8 < 0) {
        return 0;
      }
      DAT_00676dc8 = DAT_00676dc8 - 1;
      return 0;
    }
    if (arg_2 == 0x4700) {
      DAT_00676dc8 = 0;
      return 0;
    }
  }
  else if ((int)arg_2 < 0x4f01) {
    if (arg_2 == 0x4f00) {
      DAT_00676dc8 = strlen(str_1);
      return 0;
    }
    if (arg_2 == 0x4d00) {
      if ((int)arg_3 <= (int)DAT_00676dc8) {
        return 0;
      }
      len_2 = strlen(str_1);
      if (len_2 == DAT_00676dc8) {
        strcat(str_1,&DAT_00526b7c);
      }
      DAT_00676dc8 = DAT_00676dc8 + 1;
      return 0;
    }
  }
  else {
    if (arg_2 == 0x5200) {
      DAT_00676dc4 = DAT_00676dc4 ^ 1;
      return 0;
    }
    if (arg_2 == 0x5300) {
      len_2 = strlen(str_1);
      if ((int)len_2 <= (int)DAT_00676dc8) {
        return 0;
      }
      strcpy(str_1 + DAT_00676dc8,str_1 + DAT_00676dc8 + 1);
      return 0;
    }
  }
  len_2 = strlen(str_1);
  if ((len_2 < arg_3) &&
     ((((uval_1 = arg_2 & 0xff, 0x40 < uval_1 && (uval_1 < 0x5b)) || ((0x60 < uval_1 && (uval_1 < 0x7b)))
       ) || (((0x2f < uval_1 && (uval_1 < 0x3a)) || (uval_1 == 0x20)))))) {
    if (DAT_00676dc4 != 0) {
      memmove(str_1 + DAT_00676dc8 + 1,str_1 + DAT_00676dc8,(arg_3 - DAT_00676dc8) - 1);
    }
    str_1[DAT_00676dc8] = (char)arg_2;
    DAT_00676dc8 = DAT_00676dc8 + 1;
  }
  return 0;
}



/*
 * Decompiled function: UI_Register_sPoison_0047c640
 * Entry Point: 0047c640
 * Size: 244 bytes
 */


int UI_Register_sPoison_0047c640(LPCSTR str_1)

{
  ATOM AVar1;
  LOGFONTA *lplf;
  char local_138 [264];
  int local_30;
  WNDCLASSA local_2c;
  
  local_30 = 1;
  local_2c.style = 0xb;
  local_2c.lpfnWndProc = UI_LifePointsDisplayWndProc;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 0xc;
  local_2c.hInstance = g_AppHInstance;
  local_2c.hIcon = (HICON)0x0;
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = (HBRUSH)0x6;
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = str_1;
  AVar1 = RegisterClassA(&local_2c);
  if (AVar1 == 0) {
    local_30 = 0;
  }
  DAT_00539518 = CreatePopupMenu();
  sprintf(local_138,s__s_Poison_pic_00526b80,&g_CardArtDirectory);
  DAT_00539514 = Pic_LoadKimPicture(local_138);
  lplf = (LOGFONTA *)FUN_004f58eb(&DAT_00526b90,0);
  DAT_00539510 = CreateFontIndirectA(lplf);
  DAT_00539508 = 0x100004a;
  DAT_0053950c = 0x10000c9;
  return local_30;
}



/*
 * Decompiled function: FUN_0047c734
 * Entry Point: 0047c734
 * Size: 118 bytes
 */


void FUN_0047c734(void)

{
  if (DAT_00539518 != (HMENU)0x0) {
    DestroyMenu(DAT_00539518);
  }
  DAT_00539518 = (HMENU)0x0;
  if (DAT_00539514 != (HANDLE)0x0) {
    Pic_DestroyDIBSection(DAT_00539514);
  }
  DAT_00539514 = (HANDLE)0x0;
  if (DAT_00539510 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_00539510);
  }
  DAT_00539510 = (HGDIOBJ)0x0;
  return;
}



/*
 * Decompiled function: UI_LifePointsDisplayWndProc
 * Entry Point: 0047c7aa
 * Size: 3059 bytes
 */


LRESULT UI_LifePointsDisplayWndProc(HWND hwnd,uint32_t uMsg,char *wParam,uint32_t lParam)

{
  LONG LVar1;
  uint32_t uval_2;
  UINT dwMilliseconds;
  HBRUSH hbr;
  int val_3;
  LRESULT LVar4;
  int local_490;
  char local_48c [100];
  uint32_t local_428;
  char local_424 [100];
  tagPOINT local_3c0;
  tagRECT local_3b8;
  char local_3a8 [264];
  HDC local_2a0;
  int local_29c;
  tagPAINTSTRUCT local_298;
  int local_258;
  int local_254;
  int local_250;
  int local_24c;
  int local_248;
  int local_244;
  int local_240;
  CHAR local_23c [12];
  tagRECT local_230;
  tagRECT local_220;
  tagMSG local_210;
  uint32_t local_1f4;
  char local_1f0 [264];
  ULONG_PTR local_e8;
  uint32_t local_e4;
  int local_e0;
  int local_dc;
  char local_d8 [100];
  char local_74 [100];
  LONG card_idx;
  char *match_count;
  LONG slot_idx;
  
  if (uMsg < 0x10) {
    if (uMsg == 0xf) {
      slot_idx = GetWindowLongA(hwnd,0);
      card_idx = GetWindowLongA(hwnd,4);
      if (hwnd == DAT_006b2530) {
        local_240 = Ai_Subsystem_004b6fa6(0);
      }
      else {
        local_240 = Ai_Subsystem_004b6fa6(1);
      }
      wsprintfA(local_23c,&DAT_00526bdc,local_240);
      if (hwnd == DAT_006b2530) {
        local_248 = Ai_Subsystem_004b700c(0);
      }
      else {
        local_248 = Ai_Subsystem_004b700c(1);
      }
      if (local_240 != slot_idx) {
        InvalidateRect(hwnd,(RECT *)0x0,0);
      }
      if (local_248 != card_idx) {
        InvalidateRect(hwnd,(RECT *)0x0,0);
      }
      GetClientRect(hwnd,&local_220);
      EnterCriticalSection((LPCRITICAL_SECTION)&g_ActiveCombatRoundCounter);
      local_2a0 = g_HdcBackBuffer;
      local_254 = SaveDC(g_HdcBackBuffer);
      match_count = (char *)GetWindowLongA(hwnd,8);
      FUN_004f3b5f((int)local_2a0,(int)&local_220,match_count);
      if (DAT_00539514 == (HANDLE)0x0) {
        sprintf(local_3a8,s__s_Poison_pic_00526be0,&g_CardArtDirectory);
        DAT_00539514 = (HANDLE)Pic_LoadKimPicture(local_3a8);
      }
      local_258 = (int)(local_220.right + (local_220.right >> 0x1f & 3U)) >> 2;
      local_29c = local_220.bottom / 3;
      local_244 = 0;
      local_250 = 0;
      for (local_24c = 0; local_24c < local_248; local_24c = local_24c + 1) {
        SetRect(&local_230,local_244,local_250,local_244 + local_258,local_250 + local_29c);
        FUN_004f3e29(local_2a0,&local_230,DAT_00539514);
        local_244 = local_244 + local_258;
        if (local_220.right < local_244 + local_258) {
          local_244 = 0;
          local_250 = local_250 + local_29c;
        }
      }
      SetMapMode(local_2a0,8);
      SetWindowExtEx(local_2a0,0x7d,100,(LPSIZE)0x0);
      SetViewportExtEx(local_2a0,local_220.right - local_220.left,local_220.bottom - local_220.top,
                       (LPSIZE)0x0);
      SelectObject(local_2a0,DAT_00539510);
      SetBkMode(local_2a0,1);
      SetRect(&local_220,0,0,0x7d,100);
      OffsetRect(&local_220,3,3);
      SetTextColor(local_2a0,DAT_0053950c);
      DrawTextA(local_2a0,local_23c,-1,&local_220,0x25);
      OffsetRect(&local_220,-3,-3);
      SetTextColor(local_2a0,DAT_00539508);
      DrawTextA(local_2a0,local_23c,-1,&local_220,0x25);
      RestoreDC(g_HdcBackBuffer,local_254);
      local_2a0 = BeginPaint(hwnd,&local_298);
      if (local_2a0 != (HDC)0x0) {
        GDI_RealizeAndFlushPalette_Magic(local_2a0);
        GetClientRect(hwnd,&local_220);
        if (DAT_0068a674 != 0) {
          hbr = GetStockObject(0);
          FillRect(local_2a0,&local_220,hbr);
          Sleep(200);
        }
        BitBlt(local_2a0,0,0,local_220.right,local_220.bottom,g_HdcBackBuffer,0,0,0xcc0020);
        EndPaint(hwnd,&local_298);
        slot_idx = local_240;
        SetWindowLongA(hwnd,0,local_240);
        card_idx = local_248;
        SetWindowLongA(hwnd,4,local_248);
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&g_ActiveCombatRoundCounter);
      return 0;
    }
    if (uMsg == 1) {
      slot_idx = 0;
      SetWindowLongA(hwnd,0,0);
      card_idx = 0;
      SetWindowLongA(hwnd,4,0);
      match_count = (char *)0x0;
      SetWindowLongA(hwnd,8,0);
      return 0;
    }
    if (uMsg == 2) {
      match_count = (char *)GetWindowLongA(hwnd,8);
      if (match_count != (HANDLE)0x0) {
        Pic_DestroyDIBSection(match_count);
      }
      return 0;
    }
  }
  else if (uMsg < 0x21) {
    if (uMsg == 0x20) {
      LVar4 = UI_WndProc_004f4fb8(hwnd,0x20,(WPARAM)wParam,lParam);
      return LVar4;
    }
    if (uMsg == 0x14) {
      return 1;
    }
  }
  else if (uMsg < 0x118) {
    if (uMsg == 0x117) {
      local_428 = (uint32_t)(hwnd != DAT_006b2530);
      if ((DAT_006b1578 != 0) && (val_3 = FUN_00409cb2(local_428), val_3 != 0)) {
        if (local_428 == 1) {
          Ai_Subsystem_004b6f49(local_424);
          sprintf(local_48c,s_Target__s_00526bf0);
        }
        else {
          strcpy(local_48c,s_Target_yourself_00526bfc);
        }
        AppendMenuA(DAT_00539518,0,0x66,local_48c);
      }
      val_3 = GetMenuItemCount(DAT_00539518);
      if (0 < val_3) {
        AppendMenuA(DAT_00539518,0x800,0,(LPCSTR)0x0);
      }
      AppendMenuA(DAT_00539518,0,100,s_Flip_over_to_face_00526c0c);
      AppendMenuA(DAT_00539518,0,0x65,s_Help____00526c20);
      return 0;
    }
    if (uMsg == 0x111) {
      uval_2 = (uint32_t)wParam & 0xffff;
      if (uval_2 == 100) {
        UI_ShowDuelArenaWindow((uint32_t)(hwnd != DAT_006b2530),1);
      }
      else if (uval_2 == 0x65) {
        local_e8 = 0x7e8;
        strcpy(local_1f0,&g_GameInstallDirectory);
        strcat(local_1f0,s__duel_hlp_00526bd0);
        WinHelpA(g_MainAppHwnd,local_1f0,1,local_e8);
      }
      else if (uval_2 == 0x66) {
        local_e4 = (uint32_t)(hwnd != DAT_006b2530);
        g_AiTemporaryCardState = 0;
        FUN_0047d3cf(local_e4);
      }
      return 0;
    }
  }
  else if (uMsg < 0x202) {
    if (uMsg == 0x201) {
      local_1f4 = (uint32_t)(hwnd != DAT_006b2530);
      if (DAT_006b1578 != 0) {
        dwMilliseconds = GetDoubleClickTime();
        Sleep(dwMilliseconds);
        g_AiTemporaryCardState = PeekMessageA(&local_210,hwnd,0x203,0x203,0);
        FUN_0047d3cf(local_1f4);
      }
      return 0;
    }
    if (uMsg == 0x11f) {
      if (((uint32_t)wParam >> 0x10 == 0xffff) && (lParam == 0)) {
        local_490 = GetMenuItemCount(DAT_00539518);
        while (local_490 != 0) {
          DeleteMenu(DAT_00539518,0,0x400);
          local_490 = local_490 + -1;
        }
      }
      return 0;
    }
  }
  else if (uMsg < 0x312) {
    if (0x30e < uMsg) {
      LVar4 = GDI_RealizePaletteTree_Magic(hwnd,uMsg,(HWND)wParam,lParam);
      return LVar4;
    }
    if (uMsg == 0x204) {
      local_3c0.x = lParam & 0xffff;
      local_3c0.y = lParam >> 0x10;
      ClientToScreen(hwnd,&local_3c0);
      SetRect(&local_3b8,local_3c0.x,local_3c0.y,local_3c0.x + 1,local_3c0.y + 1);
      TrackPopupMenu(DAT_00539518,2,local_3c0.x,local_3c0.y,0,hwnd,&local_3b8);
      return 0;
    }
  }
  else {
    switch(uMsg) {
    case 0x432:
      slot_idx = GetWindowLongA(hwnd,0);
      if (hwnd == DAT_006b2530) {
        local_dc = Ai_Subsystem_004b6fa6(0);
      }
      else {
        local_dc = Ai_Subsystem_004b6fa6(1);
      }
      card_idx = GetWindowLongA(hwnd,4);
      if (hwnd == DAT_006b2530) {
        local_e0 = Ai_Subsystem_004b700c(0);
      }
      else {
        local_e0 = Ai_Subsystem_004b700c(1);
      }
      if (slot_idx != local_dc) {
        InvalidateRect(hwnd,(RECT *)0x0,0);
      }
      if (card_idx != local_e0) {
        InvalidateRect(hwnd,(RECT *)0x0,0);
      }
      return 0;
    case 0x437:
      card_idx = GetWindowLongA(hwnd,4);
      if (hwnd == DAT_006b2530) {
        strcpy(local_74,s_Your_00526b98);
      }
      else {
        Ai_Subsystem_004b6f49(local_74);
      }
      sprintf(local_d8,s__s_life_points_s_00526bbc,local_74,
              s_and_poison_counters_00526ba0 + ((card_idx != 0) - 1 & 0x18));
      strcpy(wParam,local_d8);
      return 1;
    case 0x438:
      LVar1 = GetWindowLongA(hwnd,8);
      return LVar1;
    case 0x439:
      match_count = (char *)GetWindowLongA(hwnd,8);
      if (match_count != (HGDIOBJ)0x0) {
        DeleteObject(match_count);
      }
      match_count = wParam;
      SetWindowLongA(hwnd,8,(LONG)wParam);
      InvalidateRect(hwnd,(RECT *)0x0,1);
      return 0;
    }
  }
  LVar4 = DefWindowProcA(hwnd,uMsg,(WPARAM)wParam,lParam);
  return LVar4;
}



/*
 * Decompiled function: FUN_0047d3cf
 * Entry Point: 0047d3cf
 * Size: 63 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0047d3cf(int player_id)

{
  _DAT_00539520 = 0;
  _DAT_00539524 = arg_1;
  _DAT_00539528 = 0xffffffff;
  PostMessageA(g_MainAppHwnd,0x464,0,0x539520);
  return;
}



/*
 * Decompiled function: FUN_0047d40e
 * Entry Point: 0047d40e
 * Size: 74 bytes
 */


int FUN_0047d40e(int player_id)

{
  int uval_1;
  
  if (((arg_1 == 1) && (DAT_006fefa0 != 0)) || ((arg_1 == 0 && (DAT_006fefa4 != 0)))) {
    uval_1 = 1;
  }
  else {
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: UI_Register_WINBK_Attack_0047d460
 * Entry Point: 0047d460
 * Size: 1020 bytes
 */


int UI_Register_WINBK_Attack_0047d460(LPCSTR str_1)

{
  ATOM AVar1;
  char local_138 [264];
  int local_30;
  WNDCLASSA local_2c;
  
  local_30 = 1;
  local_2c.style = 0x800;
  local_2c.lpfnWndProc = UI_Register_MAGICGAME_CardClass_0047da80;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 8;
  local_2c.hInstance = g_AppHInstance;
  local_2c.hIcon = (HICON)0x0;
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = (HBRUSH)0x6;
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = str_1;
  AVar1 = RegisterClassA(&local_2c);
  if (AVar1 == 0) {
    local_30 = 0;
  }
  local_2c.style = 0x801;
  local_2c.lpfnWndProc = UI_LoadAttackSwordShieldPics;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 0;
  local_2c.hInstance = g_AppHInstance;
  local_2c.hIcon = (HICON)0x0;
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = (HBRUSH)0x6;
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = s_AttackSwordShield_00526c2c;
  AVar1 = RegisterClassA(&local_2c);
  if (AVar1 == 0) {
    local_30 = 0;
  }
  local_2c.style = 3;
  local_2c.lpfnWndProc = UI_MinimizedAttackWindowWndProc;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 0;
  local_2c.hInstance = g_AppHInstance;
  local_2c.hIcon = (HICON)0x0;
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = (HBRUSH)0x6;
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = s_AttackMinimized_00526c40;
  AVar1 = RegisterClassA(&local_2c);
  if (AVar1 == 0) {
    local_30 = 0;
  }
  DAT_0053955c = CreatePopupMenu();
  strcpy(local_138,&g_AiCurrentChoiceIndex);
  strcat(local_138,s__WINBK_Attack_pic_00526c50);
  DAT_00539590 = Pic_LoadKimPicture(local_138);
  strcpy(local_138,&g_AiCurrentChoiceIndex);
  strcat(local_138,s__WINBK_AttackSword_pic_00526c64);
  DAT_00539534 = Pic_LoadKimPicture(local_138);
  strcpy(local_138,&g_AiCurrentChoiceIndex);
  strcat(local_138,s__WINBK_AttackShield_pic_00526c7c);
  DAT_00539564 = Pic_LoadKimPicture(local_138);
  strcpy(local_138,&g_AiCurrentChoiceIndex);
  strcat(local_138,s__WINBK_AttackBones_pic_00526c94);
  DAT_00539544 = Pic_LoadKimPicture(local_138);
  strcpy(local_138,&g_AiCurrentChoiceIndex);
  strcat(local_138,s__WINBK_AttackRats_pic_00526cac);
  DAT_00539530 = Pic_LoadKimPicture(local_138);
  DAT_00526c28 = 6;
  strcpy(local_138,&g_AiCurrentChoiceIndex);
  strcat(local_138,s__WINBK_AttackMin_pic_00526cc4);
  DAT_0053957c = Pic_LoadKimPicture(local_138);
  DAT_00539550 = CreatePen(0,0,0x10000b4);
  DAT_00539580 = CreatePen(0,0,0x100007c);
  DAT_0053953c = CreatePen(0,0,0x1000050);
  DAT_00539558 = CreateSolidBrush(0x1000076);
  DAT_00539568 = CreatePen(0,0,0x10000d3);
  DAT_0053956c = CreatePen(0,0,0x100002f);
  DAT_00539548 = CreatePen(0,0,0x10000d7);
  DAT_00539578 = CreateSolidBrush(0x100003a);
  DAT_0053954c = 0x10000bf;
  DAT_0053958c = 0x10000c9;
  if (((((DAT_00539550 == (HPEN)0x0) || (DAT_00539580 == (HPEN)0x0)) || (DAT_0053953c == (HPEN)0x0))
      || ((DAT_00539558 == (HBRUSH)0x0 || (DAT_00539568 == (HPEN)0x0)))) ||
     ((DAT_0053956c == (HPEN)0x0 || ((DAT_00539548 == (HPEN)0x0 || (DAT_00539578 == (HBRUSH)0x0)))))
     ) {
    local_30 = 0;
  }
  return local_30;
}



/*
 * Decompiled function: FUN_0047d85c
 * Entry Point: 0047d85c
 * Size: 548 bytes
 */


void FUN_0047d85c(void)

{
  if (DAT_0053955c != (HMENU)0x0) {
    DestroyMenu(DAT_0053955c);
  }
  DAT_0053955c = (HMENU)0x0;
  if (DAT_00539590 != (HANDLE)0x0) {
    Pic_DestroyDIBSection(DAT_00539590);
  }
  if (DAT_00539534 != (HANDLE)0x0) {
    Pic_DestroyDIBSection(DAT_00539534);
  }
  if (DAT_00539564 != (HANDLE)0x0) {
    Pic_DestroyDIBSection(DAT_00539564);
  }
  if (DAT_00539544 != (HANDLE)0x0) {
    Pic_DestroyDIBSection(DAT_00539544);
  }
  if (DAT_00539530 != (HANDLE)0x0) {
    Pic_DestroyDIBSection(DAT_00539530);
  }
  if (DAT_0053957c != (HANDLE)0x0) {
    Pic_DestroyDIBSection(DAT_0053957c);
  }
  if (DAT_00539550 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_00539550);
  }
  if (DAT_00539580 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_00539580);
  }
  if (DAT_0053953c != (HGDIOBJ)0x0) {
    DeleteObject(DAT_0053953c);
  }
  if (DAT_00539558 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_00539558);
  }
  if (DAT_00539568 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_00539568);
  }
  if (DAT_0053956c != (HGDIOBJ)0x0) {
    DeleteObject(DAT_0053956c);
  }
  if (DAT_00539548 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_00539548);
  }
  if (DAT_00539578 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_00539578);
  }
  DAT_00539590 = (HANDLE)0x0;
  DAT_00539534 = (HANDLE)0x0;
  DAT_00539564 = (HANDLE)0x0;
  DAT_00539544 = (HANDLE)0x0;
  DAT_00539530 = (HANDLE)0x0;
  DAT_0053957c = (HANDLE)0x0;
  DAT_00539550 = (HGDIOBJ)0x0;
  DAT_00539580 = (HGDIOBJ)0x0;
  DAT_0053953c = (HGDIOBJ)0x0;
  DAT_00539558 = (HGDIOBJ)0x0;
  DAT_00539568 = (HGDIOBJ)0x0;
  DAT_0053956c = (HGDIOBJ)0x0;
  DAT_00539548 = (HGDIOBJ)0x0;
  DAT_00539578 = (HGDIOBJ)0x0;
  return;
}



/*
 * Decompiled function: UI_Register_MAGICGAME_CardClass_0047da80
 * Entry Point: 0047da80
 * Size: 14661 bytes
 */


uint32_t UI_Register_MAGICGAME_CardClass_0047da80(HWND hwnd,uint32_t y,HWND param_3,HWND param_4)

{
  int *i_ptr_1;
  bool flag_2;
  int val_3;
  LONG LVar4;
  HWND pHVar5;
  HWND pHVar6;
  HBRUSH hbr;
  HGDIOBJ pvVar7;
  uint32_t uval_8;
  UINT UVar9;
  HMENU hMenu;
  WPARAM wParam;
  HINSTANCE hInstance;
  LPARAM LVar10;
  LPVOID lpParam;
  int local_598;
  tagPOINT local_594;
  tagRECT local_58c;
  uint32_t local_57c;
  int local_574;
  HGDIOBJ local_570;
  tagRECT local_56c;
  HBITMAP local_55c;
  CHAR local_558 [100];
  HBRUSH local_4f4;
  HDC local_4f0;
  uint8_t local_4ec [4];
  int local_4e8;
  int local_4e4;
  int local_4d4;
  int local_4d0;
  int local_4cc;
  int local_4c8;
  int local_4c4;
  int local_4c0;
  uint32_t local_4bc;
  tagRECT local_4b8;
  tagRECT local_4a8;
  HGDIOBJ local_498;
  tagRECT local_494;
  int local_484;
  HGDIOBJ local_480;
  HWND local_47c;
  int local_474;
  uint32_t local_470;
  tagRECT local_46c;
  int local_45c;
  HWND local_454;
  int local_450;
  uint32_t local_44c;
  uint32_t local_448;
  int local_444;
  tagRECT local_440;
  tagRECT local_430;
  HWND local_420;
  uint32_t local_41c;
  uint32_t local_418;
  char local_414 [264];
  HWND local_30c;
  uint8_t local_308 [4];
  int local_304;
  tagRECT local_2f0;
  tagRECT local_2e0;
  LRESULT local_2d0;
  HWND local_2cc;
  char local_2c8 [264];
  ULONG_PTR local_1c0;
  int local_1bc;
  uint8_t local_1b8 [4];
  int local_1b4;
  int local_1b0;
  int local_1a0;
  int local_19c;
  int local_198;
  tagRECT local_194;
  LPARAM local_184;
  int local_180 [2];
  int local_178;
  int local_174;
  int local_170;
  int local_16c;
  uint32_t local_168;
  HWND local_164;
  int local_160;
  int local_15c;
  int local_158;
  uint32_t local_154;
  uint32_t local_150;
  int local_14c;
  uint32_t local_148;
  HWND local_144;
  uint32_t local_140;
  int local_13c;
  int local_138;
  HWND local_134;
  HWND local_130;
  int local_12c;
  int local_128;
  HWND local_124;
  uint32_t local_120;
  int local_118;
  int local_114;
  HWND local_110;
  uint32_t local_10c;
  int local_108;
  int local_104;
  int local_100;
  HWND local_fc;
  int local_f8;
  int local_f4;
  int local_f0;
  int local_ec;
  HWND local_e8;
  uint32_t local_e4;
  int local_e0;
  int local_dc;
  int local_d8;
  int local_d4;
  int local_d0;
  int local_cc;
  HWND local_c8;
  tagRECT local_c4;
  HWND local_b4;
  int local_b0;
  int local_ac;
  int local_a8;
  HWND local_a4;
  HWND local_a0;
  int local_9c;
  int local_98;
  HWND local_94;
  int local_90;
  HWND local_8c;
  HWND local_88;
  int local_84;
  int local_80;
  int local_7c;
  uint32_t local_78;
  int local_74;
  HWND local_70;
  HWND local_6c;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  HWND local_4c;
  int local_48;
  int local_44;
  int local_40;
  tagPOINT local_3c;
  int local_34;
  int local_30;
  HWND local_2c;
  int local_28;
  tagRECT local_24;
  int player_idx;
  HWND card_idx;
  void *match_count;
  LONG slot_idx;
  
  if (y == 0x464) {
    local_2c = param_3;
    match_count = (void *)GetWindowLongA(hwnd,0);
    slot_idx = GetWindowLongA(hwnd,4);
    card_idx = GetDlgItem(hwnd,0);
    player_idx = 0;
    local_30 = 0;
    while ((local_30 < slot_idx && (player_idx == 0))) {
      if (*(HWND *)((int)match_count + local_30 * 0x19c) == local_2c) {
        player_idx = 1;
        local_28 = 5000;
        local_40 = -5000;
        for (local_34 = 0; local_34 < *(int *)((int)match_count + 0xcc + local_30 * 0x19c);
            local_34 = local_34 + 1) {
          GetWindowRect(*(HWND *)(local_34 * 4 + local_30 * 0x19c + 4 + (int)match_count),&local_24);
          if (local_24.left < local_28) {
            local_28 = local_24.left;
          }
          if (local_40 < local_24.right) {
            local_40 = local_24.right;
          }
        }
        for (local_34 = 0; local_34 < *(int *)((int)match_count + 0x198 + local_30 * 0x19c);
            local_34 = local_34 + 1) {
          GetWindowRect(*(HWND *)(local_34 * 4 + local_30 * 0x19c + 0xd0 + (int)match_count),&local_24);
          if (local_24.left < local_28) {
            local_28 = local_24.left;
          }
          if (local_40 < local_24.right) {
            local_40 = local_24.right;
          }
        }
      }
      local_30 = local_30 + 1;
    }
    if (player_idx != 0) {
      GetWindowRect(hwnd,&local_24);
      if (local_28 < local_24.left) {
        local_3c.x = local_28;
        local_3c.y = 0;
        ScreenToClient(hwnd,&local_3c);
      }
      else if (local_24.right < local_40) {
        local_3c.x = local_28;
        local_3c.y = 0;
        ScreenToClient(hwnd,&local_3c);
      }
    }
    return 0;
  }
  if (y < 7) {
    if (y == 6) {
      if ((((uint32_t)param_3 & 0xffff) == 1) || (((uint32_t)param_3 & 0xffff) == 2)) {
        SendMessageA(DAT_006b2e24,0x86,1,0);
      }
      else {
        SendMessageA(DAT_006b2e24,0x86,0,0);
      }
      uval_8 = DefWindowProcA(hwnd,6,(WPARAM)param_3,(LPARAM)param_4);
      return uval_8;
    }
    if (y == 1) {
      slot_idx = 0;
      SetWindowLongA(hwnd,4,0);
      match_count = malloc(0xa0f0);
      SetWindowLongA(hwnd,0,(LONG)match_count);
      local_2cc = CreateWindowExA(0,s_MAGICGAME_ScrollbarClass_00526d34,&DAT_00526d30,0x50000000,0,0
                                  ,0,0,hwnd,(HMENU)0x0,g_AppHInstance,(LPVOID)0x0);
      if (local_2cc != (HWND)0x0) {
        SendMessageA(local_2cc,0x464,DAT_00539544,1);
        SendMessageA(local_2cc,0x466,DAT_00539530,DAT_00526c28);
      }
      lpParam = (LPVOID)0x0;
      hMenu = (HMENU)0x0;
      hInstance = g_AppHInstance;
      pHVar6 = GetParent(hwnd);
      DAT_006b2e24 = CreateWindowExA(0,s_AttackSwordShield_00526d54,&DAT_00526d50,0x80c00000,0,0,0,0
                                     ,pHVar6,hMenu,hInstance,lpParam);
      DAT_00539540 = CreateWindowExA(0,s_AttackMinimized_00526d6c,&DAT_00526d68,0x80000000,0,0,0,0,
                                     hwnd,(HMENU)0x0,g_AppHInstance,(LPVOID)0x0);
      if ((((match_count != (void *)0x0) && (local_2cc != (HWND)0x0)) && (DAT_006b2e24 != (HWND)0x0)) &&
         (DAT_00539540 != (HWND)0x0)) {
        return 0;
      }
      if (match_count != (void *)0x0) {
        free(match_count);
      }
      return 0xffffffff;
    }
    if (y == 2) {
      match_count = (void *)GetWindowLongA(hwnd,0);
      free(match_count);
      return 0;
    }
  }
  else if (y < 0x15) {
    if (y == 0x14) {
      local_30c = param_3;
      GDI_RealizeAndFlushPalette_Magic((HDC)param_3);
      GetClientRect(hwnd,&local_2e0);
      local_2d0 = SendDlgItemMessageA(hwnd,0,0xe1,0,0);
      if (DAT_00539590 == (HANDLE)0x0) {
        strcpy(local_414,&g_AiCurrentChoiceIndex);
        strcat(local_414,s__WINBK_Attack_pic_00526d7c);
        DAT_00539590 = (HANDLE)Pic_LoadKimPicture(local_414);
      }
      if (DAT_00539590 == (HANDLE)0x0) {
        hbr = GetStockObject(4);
        FillRect((HDC)local_30c,&local_2e0,hbr);
      }
      else {
        CopyRect(&local_2f0,&local_2e0);
        GetObjectA(DAT_00539590,0x18,local_308);
        local_2f0.left = -(local_2d0 % local_304);
        FUN_004f3d11((HDC)local_30c,&local_2f0.left,DAT_00539590);
      }
      return 1;
    }
    if (y == 0x10) {
      ShowWindow(hwnd,0);
      ShowWindow(DAT_00539540,0);
      return 0;
    }
  }
  else if (y < 0x21) {
    if (y == 0x20) {
      uval_8 = UI_WndProc_004f4fb8(hwnd,0x20,(WPARAM)param_3,(LPARAM)param_4);
      return uval_8;
    }
    if (y == 0x18) {
      if (param_3 == (HWND)0x0) {
        ShowWindow(DAT_006b2e24,0);
      }
      else {
        ShowWindow(DAT_006b2e24,5);
      }
      PostMessageA(DAT_007006b0,0x403,0,0);
      uval_8 = DefWindowProcA(hwnd,0x18,(WPARAM)param_3,(LPARAM)param_4);
      return uval_8;
    }
  }
  else if (y < 0xa2) {
    if (y == 0xa1) {
      local_47c = param_3;
      if (param_3 == (HWND)0x8) {
        SendMessageA(hwnd,0x111,0x65,0);
        return 0;
      }
      uval_8 = DefWindowProcA(hwnd,0xa1,(WPARAM)param_3,(LPARAM)param_4);
      return uval_8;
    }
    switch(y) {
    case 0x83:
      local_454 = param_4;
      local_45c = param_4->unused;
      uval_8 = DefWindowProcA(hwnd,y,(WPARAM)param_3,(LPARAM)param_4);
      local_454->unused = local_45c;
      return uval_8;
    case 0x84:
      local_470 = DefWindowProcA(hwnd,y,(WPARAM)param_3,(LPARAM)param_4);
      if (local_470 != 2) {
        return local_470;
      }
      local_474 = GetSystemMetrics(0x1e);
      GetClientRect(hwnd,&local_46c);
      MapWindowPoints(hwnd,(HWND)0x0,(LPPOINT)&local_46c,2);
      return 8;
    case 0x85:
    case 0x86:
      GetWindowRect(hwnd,&local_494);
      OffsetRect(&local_494,-local_494.left,-local_494.top);
      if ((local_494.right != local_494.left) && (local_494.bottom != local_494.top)) {
        local_4bc = (uint32_t)(y != 0x85);
        local_4f0 = GetWindowDC(hwnd);
        if (local_4f0 == (HDC)0x0) {
          return local_4bc;
        }
        GDI_RealizeAndFlushPalette_Magic(local_4f0);
        GetWindowRect(hwnd,&local_494);
        GetClientRect(hwnd,&local_56c);
        MapWindowPoints(hwnd,(HWND)0x0,(LPPOINT)&local_56c,2);
        OffsetRect(&local_56c,-local_494.left,-local_494.top);
        OffsetRect(&local_494,-local_494.left,-local_494.top);
        GetWindowTextA(hwnd,local_558,100);
        local_574 = local_494.right - local_56c.right;
        local_4c4 = local_494.bottom - local_56c.bottom;
        Ai_Subsystem_004b74b1(&local_484,(int *)0x0);
        if (local_484 == 0) {
          local_498 = DAT_00539550;
          local_570 = DAT_00539580;
          local_480 = DAT_0053953c;
          local_4f4 = DAT_00539558;
        }
        else {
          local_498 = DAT_00539568;
          local_570 = DAT_0053956c;
          local_480 = DAT_00539548;
          local_4f4 = DAT_00539578;
        }
        SelectObject(local_4f0,local_570);
        local_4c8 = 0;
        MoveToEx(local_4f0,0,0,(LPPOINT)0x0);
        LineTo(local_4f0,local_494.right + -1,local_4c8);
        SelectObject(local_4f0,local_498);
        local_4c8 = 1;
        for (local_4cc = 1; local_4cc <= local_4c4 + -2; local_4cc = local_4cc + 1) {
          MoveToEx(local_4f0,0,local_4c8,(LPPOINT)0x0);
          LineTo(local_4f0,(local_494.right - local_574) + 1,local_4c8);
          local_4c8 = local_4c8 + 1;
        }
        SelectObject(local_4f0,local_570);
        local_4c8 = local_4c4 + -1;
        MoveToEx(local_4f0,0,local_4c8,(LPPOINT)0x0);
        LineTo(local_4f0,local_56c.right + 1,local_4c8);
        pvVar7 = GetStockObject(7);
        SelectObject(local_4f0,pvVar7);
        local_4c0 = local_494.right + -1;
        MoveToEx(local_4f0,local_4c0,0,(LPPOINT)0x0);
        LineTo(local_4f0,local_4c0,local_494.bottom);
        SelectObject(local_4f0,local_480);
        local_4c0 = local_494.right + -2;
        for (local_4cc = 1; local_4cc <= local_574 + -2; local_4cc = local_4cc + 1) {
          MoveToEx(local_4f0,local_4c0,1,(LPPOINT)0x0);
          LineTo(local_4f0,local_4c0,local_494.bottom + -1);
          local_4c0 = local_4c0 + -1;
        }
        SelectObject(local_4f0,local_570);
        local_4c0 = local_56c.right;
        MoveToEx(local_4f0,local_56c.right,local_4c4 + -1,(LPPOINT)0x0);
        LineTo(local_4f0,local_4c0,local_56c.bottom + 1);
        pvVar7 = GetStockObject(7);
        SelectObject(local_4f0,pvVar7);
        local_4c8 = local_494.bottom + -1;
        MoveToEx(local_4f0,0,local_4c8,(LPPOINT)0x0);
        LineTo(local_4f0,local_494.right,local_4c8);
        SelectObject(local_4f0,local_480);
        local_4c8 = local_494.bottom + -2;
        for (local_4cc = 1; local_4cc <= local_4c4 + -2; local_4cc = local_4cc + 1) {
          MoveToEx(local_4f0,0,local_4c8,(LPPOINT)0x0);
          LineTo(local_4f0,local_494.right + -1,local_4c8);
          local_4c8 = local_4c8 + -1;
        }
        SelectObject(local_4f0,local_570);
        local_4c8 = local_494.bottom - local_4c4;
        MoveToEx(local_4f0,0,local_4c8,(LPPOINT)0x0);
        LineTo(local_4f0,local_494.right + -2,local_4c8);
        SelectObject(local_4f0,local_570);
        local_4c8 = local_56c.top + -1;
        MoveToEx(local_4f0,0,local_4c8,(LPPOINT)0x0);
        LineTo(local_4f0,local_56c.right + 1,local_4c8);
        SetRect(&local_4a8,0,local_4c4,local_56c.right,local_56c.top + -1);
        FillRect(local_4f0,&local_4a8,local_4f4);
        SetBkMode(local_4f0,1);
        OffsetRect(&local_4a8,1,1);
        SetTextColor(local_4f0,DAT_0053958c);
        DrawTextA(local_4f0,local_558,-1,&local_4a8,0x24);
        OffsetRect(&local_4a8,-1,-1);
        SetTextColor(local_4f0,DAT_0053954c);
        DrawTextA(local_4f0,local_558,-1,&local_4a8,0x24);
        local_55c = LoadBitmapA((HINSTANCE)0x0,(LPCSTR)0x7fed);
        GetObjectA(local_55c,0x18,local_4ec);
        local_4d0 = local_4e8;
        local_4d4 = local_4e4;
        SetRect(&local_4b8,local_56c.right - local_4e8,local_56c.top - local_4e4,local_56c.right,
                local_56c.top);
        FUN_004f3b5f((int)local_4f0,(int)&local_4b8,DAT_0053957c);
        DeleteObject(local_55c);
        ReleaseDC(hwnd,local_4f0);
        return local_4bc;
      }
      uval_8 = DefWindowProcA(hwnd,y,(WPARAM)param_3,(LPARAM)param_4);
      return uval_8;
    }
  }
  else if (y < 0x112) {
    if (y == 0x111) {
      uval_8 = (uint32_t)param_3 & 0xffff;
      if (uval_8 == 100) {
        local_1c0 = 0xbbc;
        strcpy(local_2c8,&g_GameInstallDirectory);
        strcat(local_2c8,s__duel_hlp_00526d24);
        WinHelpA(g_MainAppHwnd,local_2c8,1,local_1c0);
      }
      else if (uval_8 == 0x65) {
        ShowWindow(hwnd,0);
        UpdateWindow(g_AiSelectedActionCode);
        GetWindowRect(DAT_006a284c,&local_194);
        local_198 = local_194.left;
        local_1a0 = local_194.right - local_194.left;
        if (DAT_0053957c == (HANDLE)0x0) {
          local_1bc = local_1a0 * 2;
        }
        else {
          GetObjectA(DAT_0053957c,0x18,local_1b8);
          local_1bc = (local_1b0 * local_1a0) / local_1b4;
        }
        local_19c = (local_194.bottom - local_194.top) / 2 + local_1bc / 2 + 2;
        MoveWindow(DAT_00539540,local_198,local_19c,local_1a0,local_1bc,1);
        ShowWindow(DAT_00539540,5);
        BringWindowToTop(DAT_00539540);
        SendMessageA(DAT_007006b0,0x403,0,0);
      }
      else if (uval_8 == 0x66) {
        ShowWindow(DAT_00539540,0);
        ShowWindow(hwnd,5);
        SendMessageA(DAT_007006b0,0x403,0,0);
        FUN_004f59f7();
      }
      return 0;
    }
    if (y == 0xa4) {
LAB_004810c3:
      local_594.x = (uint32_t)param_4 & 0xffff;
      local_594.y = (uint32_t)param_4 >> 0x10;
      if (y == 0x204) {
        ClientToScreen(hwnd,&local_594);
      }
      SetRect(&local_58c,local_594.x,local_594.y,local_594.x + 1,local_594.y + 1);
      TrackPopupMenu(DAT_0053955c,2,local_594.x,local_594.y,0,hwnd,&local_58c);
      return 0;
    }
  }
  else if (y < 0x120) {
    if (y == 0x11f) {
      if (((uint32_t)param_3 >> 0x10 == 0xffff) && (param_4 == (HWND)0x0)) {
        local_598 = GetMenuItemCount(DAT_0053955c);
        while (local_598 != 0) {
          DeleteMenu(DAT_0053955c,0,0x400);
          local_598 = local_598 + -1;
        }
      }
      return 0;
    }
    if (y == 0x112) {
      local_57c = (uint32_t)param_3 & 0xfff0;
      if (local_57c == 0xf010) {
        return 0;
      }
      uval_8 = DefWindowProcA(hwnd,0x112,(WPARAM)param_3,(LPARAM)param_4);
      return uval_8;
    }
    if (y == 0x114) {
      local_420 = GetDlgItem(hwnd,0);
      SendMessageA(local_420,0xe3,(WPARAM)&local_448,(LPARAM)&local_41c);
      local_44c = SendMessageA(local_420,0xe1,0,0);
      local_444 = g_PlayerGoldCoins;
      GetClientRect(hwnd,&local_430);
      local_450 = local_430.right;
      switch((uint32_t)param_3 & 0xffff) {
      case 0:
        local_418 = local_44c - local_444;
        break;
      case 1:
        local_418 = local_444 + local_44c;
        break;
      case 2:
        local_418 = local_44c - local_430.right;
        break;
      case 3:
        local_418 = local_430.right + local_44c;
        break;
      case 4:
      case 5:
        local_418 = (uint32_t)param_3 >> 0x10;
        break;
      case 6:
        local_418 = local_448;
        break;
      case 7:
        local_418 = local_41c;
        break;
      default:
        local_418 = local_44c;
      }
      if ((int)local_418 < (int)local_448) {
        local_418 = local_448;
      }
      if ((int)local_41c < (int)local_418) {
        local_418 = local_41c;
      }
      if (local_418 != local_44c) {
        SendMessageA(local_420,0xe0,local_418,1);
        GetWindowRect(local_420,&local_440);
        MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_440,2);
        ScrollWindow(hwnd,local_44c - local_418,0,(RECT *)0x0,(RECT *)0x0);
        MoveWindow(local_420,local_440.left,local_440.top,local_440.right - local_440.left,
                   local_440.bottom - local_440.top,0);
        UpdateWindow(hwnd);
      }
      return 0;
    }
    if (y == 0x117) {
      AppendMenuA(DAT_0053955c,0,0x65,s__Minimize_00526d90);
      AppendMenuA(DAT_0053955c,0,100,s_Help____00526d9c);
      return 0;
    }
  }
  else if (y < 0x205) {
    if (y == 0x204) goto LAB_004810c3;
    if (y == 0x201) {
      return 0;
    }
  }
  else if (y < 0x402) {
    if (0x3ff < y) {
      match_count = (void *)GetWindowLongA(hwnd,0);
      slot_idx = GetWindowLongA(hwnd,4);
      local_88 = param_3;
      if (param_3 == (HWND)0x0) {
        return 0;
      }
      FUN_00483139(hwnd,&param_3->unused,(int *)0x0,&local_8c,&local_84);
      if ((local_8c == (HWND)0x0) ||
         (((local_84 == 0 || (y != 0x400)) && ((local_84 != 0 || (y != 0x401)))))) {
        local_7c = 0;
      }
      else {
        local_7c = 1;
      }
      if (local_7c == 0) {
        local_8c = CreateWindowExA(0,s_MAGICGAME_CardClass_00526cec,s_Card_in_attack_00526cdc,
                                   0x54000000,0,0,0,0,hwnd,(HMENU)0x1,g_AppHInstance,local_88);
        if (local_8c == (HWND)0x0) {
          return 0;
        }
        if (y == 0x400) {
          local_80 = Ai_Subsystem_004b5b6f(local_88->unused,local_88[1].unused);
          if (local_80 == -1) {
            local_80 = local_88[1].unused;
          }
        }
        else {
          local_80 = Ai_Subsystem_004b5b6f(local_88->unused,local_88[1].unused);
        }
        local_90 = 0;
        local_7c = 0;
        while ((local_90 < slot_idx && (local_7c == 0))) {
          if (*(int *)((int)match_count + local_90 * 0x19c) == local_80) {
            local_7c = 1;
            if ((y == 0x400) && (*(int *)((int)match_count + 0xcc + local_90 * 0x19c) < 0x32)) {
              *(HWND *)(local_90 * 0x19c + *(int *)((int)match_count + 0xcc + local_90 * 0x19c) * 4 + 4
                       + (int)match_count) = local_8c;
              i_ptr_1 = (int *)((int)match_count + 0xcc + local_90 * 0x19c);
              *i_ptr_1 = *i_ptr_1 + 1;
            }
            else {
              if ((y != 0x401) || (0x31 < *(int *)((int)match_count + 0x198 + local_90 * 0x19c))) {
                DestroyWindow(local_8c);
                return 0;
              }
              *(HWND *)(local_90 * 0x19c + *(int *)((int)match_count + 0x198 + local_90 * 0x19c) * 4 +
                        0xd0 + (int)match_count) = local_8c;
              i_ptr_1 = (int *)((int)match_count + 0x198 + local_90 * 0x19c);
              *i_ptr_1 = *i_ptr_1 + 1;
            }
          }
          local_90 = local_90 + 1;
        }
        if (local_7c == 0) {
          if (99 < slot_idx) {
            DestroyWindow(local_8c);
            return 0;
          }
          *(int *)((int)match_count + slot_idx * 0x19c) = local_80;
          if (y == 0x400) {
            *(HWND *)((int)match_count + 4 + slot_idx * 0x19c) = local_8c;
            *(int *)((int)match_count + 0xcc + slot_idx * 0x19c) = 1;
            *(int *)((int)match_count + 0x198 + slot_idx * 0x19c) = 0;
          }
          else {
            *(HWND *)((int)match_count + 0xd0 + slot_idx * 0x19c) = local_8c;
            *(int *)((int)match_count + 0x198 + slot_idx * 0x19c) = 1;
            *(int *)((int)match_count + 0xcc + slot_idx * 0x19c) = 0;
          }
          slot_idx = slot_idx + 1;
          SetWindowLongA(hwnd,4,slot_idx);
        }
        BringWindowToTop(local_8c);
      }
      return 1;
    }
    if ((0x30e < y) && (y < 0x312)) {
      uval_8 = GDI_RealizePaletteTree_Magic(hwnd,y,param_3,param_4);
      return uval_8;
    }
  }
  else {
    switch(y) {
    case 0x402:
    case 0x403:
      match_count = (void *)GetWindowLongA(hwnd,0);
      slot_idx = GetWindowLongA(hwnd,4);
      local_fc = param_3;
      if (param_3 == (HWND)0x0) {
        local_e8 = param_4;
      }
      else {
        FUN_00483139(hwnd,&param_3->unused,(int *)0x0,&local_e8,(int *)0x0);
      }
      if ((local_e8 != (HWND)0x0) && (pHVar6 = GetParent(local_e8), pHVar6 == hwnd)) {
        for (local_ec = 0; local_ec < slot_idx; local_ec = local_ec + 1) {
          local_e4 = 0;
          local_f0 = 0;
          while ((local_f0 < *(int *)((int)match_count + 0xcc + local_ec * 0x19c) && (local_e4 == 0))) {
            if ((y == 0x403) &&
               (*(HWND *)(local_ec * 0x19c + local_f0 * 4 + 4 + (int)match_count) == local_e8)) {
              local_e4 = 1;
              FUN_00481491((int)local_e8,local_ec * 0x19c + (int)match_count + 4,
                           *(int *)((int)match_count + 0xcc + local_ec * 0x19c));
              local_f8 = 0;
              for (local_f4 = 0; local_f4 < *(int *)((int)match_count + 0xcc + local_ec * 0x19c);
                  local_f4 = local_f4 + 1) {
                if (*(int *)(local_f4 * 4 + local_ec * 0x19c + 4 + (int)match_count) != 0) {
                  *(int *)(local_ec * 0x19c + local_f8 * 4 + 4 + (int)match_count) =
                       *(int *)(local_f4 * 4 + local_ec * 0x19c + 4 + (int)match_count);
                  local_f8 = local_f8 + 1;
                }
              }
              *(int *)((int)match_count + 0xcc + local_ec * 0x19c) = local_f8;
            }
            else if ((y == 0x402) &&
                    (*(HWND *)(local_ec * 0x19c + local_f0 * 4 + 0xd0 + (int)match_count) == local_e8))
            {
              local_e4 = 1;
              FUN_00481491((int)local_e8,local_ec * 0x19c + (int)match_count + 0xd0,
                           *(int *)((int)match_count + 0x198 + local_ec * 0x19c));
              local_f8 = 0;
              for (local_f4 = 0; local_f4 < *(int *)((int)match_count + 0x198 + local_ec * 0x19c);
                  local_f4 = local_f4 + 1) {
                if (*(int *)(local_f4 * 4 + local_ec * 0x19c + 0xd0 + (int)match_count) != 0) {
                  *(int *)(local_ec * 0x19c + local_f8 * 4 + 0xd0 + (int)match_count) =
                       *(int *)(local_f4 * 4 + local_ec * 0x19c + 0xd0 + (int)match_count);
                  local_f8 = local_f8 + 1;
                }
              }
              *(int *)((int)match_count + 0x198 + local_ec * 0x19c) = local_f8;
            }
            local_f0 = local_f0 + 1;
          }
        }
        return local_e4;
      }
      return 0;
    case 0x404:
      match_count = (void *)GetWindowLongA(hwnd,0);
      slot_idx = GetWindowLongA(hwnd,4);
      local_134 = param_3;
      local_130 = param_4;
      if ((param_4 != (HWND)0x0) && (param_3 != (HWND)0xffffffff)) {
        local_140 = 0;
        for (local_138 = 0; local_138 < slot_idx; local_138 = local_138 + 1) {
          if (*(HWND *)((int)match_count + local_138 * 0x19c) == local_134) {
            for (local_13c = 0; local_13c < *(int *)((int)match_count + 0xcc + local_138 * 0x19c);
                local_13c = local_13c + 1) {
              val_3 = FUN_0046bc92(*(HWND *)(local_138 * 0x19c + local_13c * 4 + 4 + (int)match_count));
              if (val_3 == 0) {
                local_130[local_140].unused =
                     *(int *)(local_138 * 0x19c + local_13c * 4 + 4 + (int)match_count);
                local_140 = local_140 + 1;
              }
            }
          }
        }
        return local_140;
      }
      return 0;
    case 0x405:
      match_count = (void *)GetWindowLongA(hwnd,0);
      slot_idx = GetWindowLongA(hwnd,4);
      local_124 = param_3;
      if ((param_3 == (HWND)0x0) || (pHVar6 = GetParent(param_3), pHVar6 != hwnd)) {
        return 0xffffffff;
      }
      flag_2 = false;
      for (local_128 = 0; local_128 < slot_idx; local_128 = local_128 + 1) {
        local_12c = 0;
        while ((local_12c < *(int *)((int)match_count + 0xcc + local_128 * 0x19c) && (!flag_2))) {
          if (*(HWND *)(local_12c * 4 + local_128 * 0x19c + 4 + (int)match_count) == local_124) {
            flag_2 = true;
            local_120 = 1;
          }
          local_12c = local_12c + 1;
        }
        local_12c = 0;
        while ((local_12c < *(int *)((int)match_count + 0x198 + local_128 * 0x19c) && (!flag_2))) {
          if (*(HWND *)(local_12c * 4 + local_128 * 0x19c + 0xd0 + (int)match_count) == local_124) {
            flag_2 = true;
            local_120 = 0;
          }
          local_12c = local_12c + 1;
        }
      }
      if (flag_2) {
        return local_120;
      }
      return 0xffffffff;
    case 0x406:
      match_count = (void *)GetWindowLongA(hwnd,0);
      slot_idx = GetWindowLongA(hwnd,4);
      local_a0 = param_3;
      local_94 = param_4;
      if (((param_3 == (HWND)0x0) || (param_4 == (HWND)0x0)) ||
         (pHVar6 = GetParent(param_4), pHVar6 != hwnd)) {
        return 0;
      }
      val_3 = FUN_00483139(hwnd,&local_a0->unused,(int *)0x0,(int *)0x0,
                           (int *)0x0);
      if (val_3 != 0) {
        return 1;
      }
      local_a8 = 0;
      local_ac = 0;
      while ((local_ac < slot_idx && (local_a8 == 0))) {
        local_b0 = 0;
        while ((local_b0 < *(int *)((int)match_count + 0xcc + local_ac * 0x19c) && (local_a8 == 0))) {
          if (*(HWND *)(local_b0 * 4 + local_ac * 0x19c + 4 + (int)match_count) == local_94) {
            local_a8 = 1;
            local_98 = local_ac;
            local_9c = 1;
          }
          local_b0 = local_b0 + 1;
        }
        local_b0 = 0;
        while ((local_b0 < *(int *)((int)match_count + 0x198 + local_ac * 0x19c) && (local_a8 == 0))) {
          if (*(HWND *)(local_b0 * 4 + local_ac * 0x19c + 0xd0 + (int)match_count) == local_94) {
            local_a8 = 1;
            local_98 = local_ac;
            local_9c = 0;
          }
          local_b0 = local_b0 + 1;
        }
        local_ac = local_ac + 1;
      }
      if (local_a8 == 0) {
        return 0;
      }
      local_a4 = CreateWindowExA(0,s_MAGICGAME_CardClass_00526d10,s_Card_in_attack_00526d00,
                                 0x54000000,0,0,0,0,hwnd,(HMENU)0x1,g_AppHInstance,local_a0);
      if (local_a4 == (HWND)0x0) {
        return 0;
      }
      SendMessageA(local_a4,0x402,(WPARAM)local_94,0);
      if ((local_9c == 0) || (0x31 < *(int *)((int)match_count + 0xcc + local_98 * 0x19c))) {
        if ((local_9c != 0) || (0x31 < *(int *)((int)match_count + 0x198 + local_98 * 0x19c))) {
          DestroyWindow(local_a4);
          return 0;
        }
        *(HWND *)(local_98 * 0x19c + *(int *)((int)match_count + 0x198 + local_98 * 0x19c) * 4 + 0xd0 +
                 (int)match_count) = local_a4;
        i_ptr_1 = (int *)((int)match_count + 0x198 + local_98 * 0x19c);
        *i_ptr_1 = *i_ptr_1 + 1;
      }
      else {
        *(HWND *)(local_98 * 0x19c + *(int *)((int)match_count + 0xcc + local_98 * 0x19c) * 4 + 4 +
                 (int)match_count) = local_a4;
        i_ptr_1 = (int *)((int)match_count + 0xcc + local_98 * 0x19c);
        *i_ptr_1 = *i_ptr_1 + 1;
      }
      return 1;
    case 0x40c:
      match_count = (void *)GetWindowLongA(hwnd,0);
      slot_idx = GetWindowLongA(hwnd,4);
      ShowWindow(hwnd,0);
      ShowWindow(DAT_00539540,0);
      for (local_100 = 0; local_100 < slot_idx; local_100 = local_100 + 1) {
        for (local_104 = 0; local_104 < *(int *)((int)match_count + 0xcc + local_100 * 0x19c);
            local_104 = local_104 + 1) {
          DestroyWindow(*(HWND *)(local_104 * 4 + local_100 * 0x19c + 4 + (int)match_count));
        }
        *(int *)((int)match_count + 0xcc + local_100 * 0x19c) = 0;
        for (local_104 = 0; local_104 < *(int *)((int)match_count + 0x198 + local_100 * 0x19c);
            local_104 = local_104 + 1) {
          DestroyWindow(*(HWND *)(local_104 * 4 + local_100 * 0x19c + 0xd0 + (int)match_count));
        }
        *(int *)((int)match_count + 0x198 + local_100 * 0x19c) = 0;
      }
      slot_idx = 0;
      SetWindowLongA(hwnd,4,0);
      LVar10 = 1;
      wParam = 0;
      UVar9 = 0xe0;
      pHVar6 = GetDlgItem(hwnd,0);
      SendMessageA(pHVar6,UVar9,wParam,LVar10);
      return 0;
    case 0x40e:
    case 0x40f:
      match_count = (void *)GetWindowLongA(hwnd,0);
      slot_idx = GetWindowLongA(hwnd,4);
      local_110 = param_3;
      if (param_3 == (HWND)0x0) {
        local_108 = 0;
      }
      else {
        local_108 = 0;
        for (local_114 = 0; local_114 < slot_idx; local_114 = local_114 + 1) {
          local_118 = 0;
          while ((local_118 < *(int *)((int)match_count + 0xcc + local_114 * 0x19c) && (local_108 == 0))
                ) {
            val_3 = FUN_0046bb29(*(HWND *)(local_118 * 4 + local_114 * 0x19c + 4 + (int)match_count),
                                 &local_110->unused);
            if (val_3 != 0) {
              local_108 = 1;
              if (y == 0x40e) {
                local_10c = FUN_0046bc2f(*(HWND *)(local_118 * 4 + local_114 * 0x19c + 4 +
                                                  (int)match_count));
              }
              else {
                local_10c = *(uint32_t *)(local_118 * 4 + local_114 * 0x19c + 4 + (int)match_count);
              }
            }
            local_118 = local_118 + 1;
          }
          local_118 = 0;
          while ((local_118 < *(int *)((int)match_count + 0x198 + local_114 * 0x19c) && (local_108 == 0)
                 )) {
            val_3 = FUN_0046bb29(*(HWND *)(local_118 * 4 + local_114 * 0x19c + 0xd0 + (int)match_count),
                                 &local_110->unused);
            if (val_3 != 0) {
              local_108 = 1;
              if (y == 0x40e) {
                local_10c = FUN_0046bc2f(*(HWND *)(local_118 * 4 + local_114 * 0x19c + 0xd0 +
                                                  (int)match_count));
              }
              else {
                local_10c = *(uint32_t *)(local_118 * 4 + local_114 * 0x19c + 0xd0 + (int)match_count);
              }
            }
            local_118 = local_118 + 1;
          }
        }
      }
      if (local_108 != 0) {
        return local_10c;
      }
      if (y == 0x40e) {
        return 0xffffffff;
      }
      return 0;
    case 0x410:
      match_count = (void *)GetWindowLongA(hwnd,0);
      slot_idx = GetWindowLongA(hwnd,4);
      local_c8 = param_3;
      if (param_3 == (HWND)0x0) {
        return 0;
      }
      local_dc = 5;
      local_e0 = DAT_006ff67c;
      GetWindowRect(param_3,&local_c4);
      MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_c4,2);
      local_cc = local_c4.left + local_dc;
      local_d0 = local_c4.top - local_e0;
      local_b4 = local_c8;
      for (local_d4 = 0; local_d4 < slot_idx; local_d4 = local_d4 + 1) {
        for (local_d8 = 0; local_d8 < *(int *)((int)match_count + 0xcc + local_d4 * 0x19c);
            local_d8 = local_d8 + 1) {
          pHVar6 = (HWND)FUN_0046bc92(*(HWND *)(local_d8 * 4 + local_d4 * 0x19c + 4 + (int)match_count))
          ;
          if (pHVar6 == local_c8) {
            SetWindowPos(*(HWND *)(local_d8 * 4 + local_d4 * 0x19c + 4 + (int)match_count),local_b4,
                         local_cc,local_d0,g_PlayerGoldCoins,g_PlayerAmuletGems,0);
            local_d0 = local_d0 - local_e0;
            local_b4 = *(HWND *)(local_d8 * 4 + local_d4 * 0x19c + 4 + (int)match_count);
          }
        }
        for (local_d8 = 0; local_d8 < *(int *)((int)match_count + 0x198 + local_d4 * 0x19c);
            local_d8 = local_d8 + 1) {
          pHVar6 = (HWND)FUN_0046bc92(*(HWND *)(local_d8 * 4 + local_d4 * 0x19c + 0xd0 +
                                               (int)match_count));
          if (pHVar6 == local_c8) {
            SetWindowPos(*(HWND *)(local_d8 * 4 + local_d4 * 0x19c + 0xd0 + (int)match_count),local_b4,
                         local_cc,local_d0,g_PlayerGoldCoins,g_PlayerAmuletGems,0);
            local_d0 = local_d0 - local_e0;
            local_b4 = *(HWND *)(local_d8 * 4 + local_d4 * 0x19c + 0xd0 + (int)match_count);
          }
        }
      }
      return 0;
    case 0x411:
      match_count = (void *)GetWindowLongA(hwnd,0);
      LVar4 = GetWindowLongA(hwnd,4);
      local_78 = 0;
      for (local_74 = 0; local_74 < LVar4; local_74 = local_74 + 1) {
        if (*(int *)((int)match_count + 0xcc + local_74 * 0x19c) != 0) {
          local_78 = local_78 + 1;
        }
      }
      return local_78;
    case 0x412:
      local_164 = param_3;
      local_154 = 0;
      for (local_14c = 0; local_14c < 2; local_14c = local_14c + 1) {
        for (local_16c = 0; local_16c < 0x50; local_16c = local_16c + 1) {
          local_174 = local_14c;
          local_170 = local_16c;
          local_158 = Ai_Subsystem_004b5c4b(local_14c,local_16c);
          local_15c = Ai_Subsystem_004b5d2e(local_14c,local_16c);
          local_150 = Ai_Subsystem_004b6c5b(local_14c,local_16c);
          FUN_00483139(hwnd,&local_174,(int *)0x0,&local_178,&local_160);
          val_3 = Glue_Subsystem_004ef849(g_TurnPriorityState,&local_174,(int *)0x0,&local_144);
          if (val_3 == 0) {
            Glue_Subsystem_004ef849(g_AiSelectedActionCode,&local_174,(int *)0x0,&local_144);
          }
          if ((local_158 != DAT_006fd3f4) && (local_15c != 2)) {
            if (((local_158 == -1) || (local_15c != 1)) ||
               (((local_150 & 0x10000) != 0 && (DAT_006fe43c == 0)))) {
              if (local_178 != 0) {
                if (local_160 == 0) {
                  uval_8 = SendMessageA(hwnd,0x402,0,local_178);
                  local_154 = local_154 | uval_8;
                }
                else {
                  uval_8 = SendMessageA(hwnd,0x403,0,local_178);
                  local_154 = local_154 | uval_8;
                }
              }
              LVar10 = 1;
              UVar9 = 0x402;
              pHVar6 = local_144;
              pHVar5 = GetParent(local_144);
              SendMessageA(pHVar5,UVar9,(WPARAM)pHVar6,LVar10);
            }
            else {
              local_148 = Ai_Subsystem_004b5de4(local_14c,local_16c);
              local_168 = Ai_Subsystem_004b6432(local_14c,local_16c);
              if ((local_148 & 0x10) == 0) {
                if (((((local_148 & 8) == 0) || ((local_168 & 4) != 0)) || ((local_168 & 0x40) != 0)
                    ) && ((local_168 & 8) == 0)) {
                  if ((local_178 != 0) && (local_160 == 0)) {
                    uval_8 = SendMessageA(hwnd,0x402,0,local_178);
                    local_154 = local_154 | uval_8;
                    LVar10 = 1;
                    UVar9 = 0x402;
                    pHVar6 = local_144;
                    pHVar5 = GetParent(local_144);
                    SendMessageA(pHVar5,UVar9,(WPARAM)pHVar6,LVar10);
                  }
                }
                else if (local_178 == 0) {
                  SendMessageA(hwnd,0x401,(WPARAM)&local_174,0);
                  pHVar6 = local_144;
                  pHVar5 = GetParent(local_144);
                  Glue_Subsystem_004ef64b(pHVar5,pHVar6);
                  local_154 = 1;
                  LVar10 = 0;
                  UVar9 = 0x402;
                  pHVar6 = local_144;
                  pHVar5 = GetParent(local_144);
                  SendMessageA(pHVar5,UVar9,(WPARAM)pHVar6,LVar10);
                }
                if ((((local_148 & 4) == 0) && ((local_168 & 4) == 0)) && ((local_168 & 0x40) == 0))
                {
                  if ((local_178 != 0) && (local_160 != 0)) {
                    uval_8 = SendMessageA(hwnd,0x403,0,local_178);
                    local_154 = local_154 | uval_8;
                    LVar10 = 1;
                    UVar9 = 0x402;
                    pHVar6 = local_144;
                    pHVar5 = GetParent(local_144);
                    SendMessageA(pHVar5,UVar9,(WPARAM)pHVar6,LVar10);
                  }
                }
                else if (local_178 == 0) {
                  SendMessageA(hwnd,0x400,(WPARAM)&local_174,0);
                  pHVar6 = local_144;
                  pHVar5 = GetParent(local_144);
                  Glue_Subsystem_004ef64b(pHVar5,pHVar6);
                  local_154 = 1;
                  LVar10 = 0;
                  UVar9 = 0x402;
                  pHVar6 = local_144;
                  pHVar5 = GetParent(local_144);
                  SendMessageA(pHVar5,UVar9,(WPARAM)pHVar6,LVar10);
                }
              }
              else {
                val_3 = FUN_00483139(hwnd,&local_174,(int *)0x0,(int *)0x0,
                                     (int *)0x0);
                if (val_3 == 0) {
                  Ai_Subsystem_004b5f74(local_180,local_14c,local_16c);
                  val_3 = FUN_00483139(hwnd,local_180,(int *)0x0,&local_184,(int *)0x0
                                      );
                  if (val_3 != 0) {
                    SendMessageA(hwnd,0x406,(WPARAM)&local_174,local_184);
                    local_154 = 1;
                  }
                }
              }
            }
          }
        }
      }
      if ((local_154 != 0) || (local_164 != (HWND)0x0)) {
        UI_LayoutAttackCards(hwnd);
      }
      return 0;
    case 0x432:
      match_count = (void *)GetWindowLongA(hwnd,0);
      slot_idx = GetWindowLongA(hwnd,4);
      for (local_50 = 0; local_50 < slot_idx; local_50 = local_50 + 1) {
        for (local_54 = 0; local_54 < *(int *)((int)match_count + 0xcc + local_50 * 0x19c);
            local_54 = local_54 + 1) {
          SendMessageA(*(HWND *)(local_54 * 4 + local_50 * 0x19c + 4 + (int)match_count),0x432,0,0);
        }
        for (local_54 = 0; local_54 < *(int *)((int)match_count + 0x198 + local_50 * 0x19c);
            local_54 = local_54 + 1) {
          SendMessageA(*(HWND *)(local_54 * 4 + local_50 * 0x19c + 0xd0 + (int)match_count),0x432,0,0);
        }
      }
      return 0;
    case 0x433:
    case 0x434:
      match_count = (void *)GetWindowLongA(hwnd,0);
      slot_idx = GetWindowLongA(hwnd,4);
      local_4c = param_3;
      for (local_44 = 0; local_44 < slot_idx; local_44 = local_44 + 1) {
        for (local_48 = 0; local_48 < *(int *)((int)match_count + 0xcc + local_44 * 0x19c);
            local_48 = local_48 + 1) {
          val_3 = FUN_0046bbab(*(HWND *)(local_48 * 4 + local_44 * 0x19c + 4 + (int)match_count),
                               (int)local_4c);
          if (val_3 != 0) {
            InvalidateRect(*(HWND *)(local_48 * 4 + local_44 * 0x19c + 4 + (int)match_count),(RECT *)0x0
                           ,0);
          }
        }
        for (local_48 = 0; local_48 < *(int *)((int)match_count + 0x198 + local_44 * 0x19c);
            local_48 = local_48 + 1) {
          val_3 = FUN_0046bbab(*(HWND *)(local_48 * 4 + local_44 * 0x19c + 0xd0 + (int)match_count),
                               (int)local_4c);
          if (val_3 != 0) {
            InvalidateRect(*(HWND *)(local_48 * 4 + local_44 * 0x19c + 0xd0 + (int)match_count),
                           (RECT *)0x0,0);
          }
        }
      }
      return 0;
    case 0x435:
      match_count = (void *)GetWindowLongA(hwnd,0);
      slot_idx = GetWindowLongA(hwnd,4);
      for (local_58 = 0; local_58 < slot_idx; local_58 = local_58 + 1) {
        for (local_5c = 0; local_5c < *(int *)((int)match_count + 0xcc + local_58 * 0x19c);
            local_5c = local_5c + 1) {
          InvalidateRect(*(HWND *)(local_5c * 4 + local_58 * 0x19c + 4 + (int)match_count),(RECT *)0x0,0
                        );
        }
        for (local_5c = 0; local_5c < *(int *)((int)match_count + 0x198 + local_58 * 0x19c);
            local_5c = local_5c + 1) {
          InvalidateRect(*(HWND *)(local_5c * 4 + local_58 * 0x19c + 0xd0 + (int)match_count),
                         (RECT *)0x0,0);
        }
      }
      return 0;
    case 0x436:
      match_count = (void *)GetWindowLongA(hwnd,0);
      slot_idx = GetWindowLongA(hwnd,4);
      local_6c = param_3;
      local_70 = param_4;
      if (param_3 == (HWND)0x0) {
        return 0;
      }
      local_60 = 0;
      for (local_64 = 0; local_64 < slot_idx; local_64 = local_64 + 1) {
        for (local_68 = 0; local_68 < *(int *)((int)match_count + 0xcc + local_64 * 0x19c);
            local_68 = local_68 + 1) {
          val_3 = FUN_0046bb29(*(HWND *)(local_68 * 4 + local_64 * 0x19c + 4 + (int)match_count),
                               &local_6c->unused);
          if (val_3 != 0) {
            local_60 = 1;
            if (local_70 == (HWND)0x0) {
              InvalidateRect(*(HWND *)(local_68 * 4 + local_64 * 0x19c + 4 + (int)match_count),
                             (RECT *)0x0,0);
            }
            else {
              SendMessageA(*(HWND *)(local_68 * 4 + local_64 * 0x19c + 4 + (int)match_count),0x432,0,0);
            }
          }
        }
        for (local_68 = 0; local_68 < *(int *)((int)match_count + 0x198 + local_64 * 0x19c);
            local_68 = local_68 + 1) {
          val_3 = FUN_0046bb29(*(HWND *)(local_68 * 4 + local_64 * 0x19c + 0xd0 + (int)match_count),
                               &local_6c->unused);
          if (val_3 != 0) {
            local_60 = 1;
            if (local_70 == (HWND)0x0) {
              InvalidateRect(*(HWND *)(local_68 * 4 + local_64 * 0x19c + 0xd0 + (int)match_count),
                             (RECT *)0x0,0);
            }
            else {
              SendMessageA(*(HWND *)(local_68 * 4 + local_64 * 0x19c + 0xd0 + (int)match_count),0x432,0,
                           0);
            }
          }
        }
      }
      return 0;
    case 0x437:
      return 0;
    }
  }
  uval_8 = DefWindowProcA(hwnd,y,(WPARAM)param_3,(LPARAM)param_4);
  return uval_8;
}




/*
 * sid/glue_card_queries.c - Permanent Queries, Iterators, Counter Manipulation & Targeting
 * Reconstructed MicroProse Source Module
 * Author: Sid Meier / MicroProse (1997)
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
 * CardQuery_PlayerControlsColor
 * Purpose: Check if player controls any permanent matching the specified color mask.
 * Procedure:
 * 1. Iterate active cards in play for player.
 * 2. Test color mask against card color table.
 * 3. Return 1 if match found, else 0.
 */
/*
 * Decompiled function: CardQuery_PlayerControlsColor
 * Entry Point: 004e654a
 * Size: 151 bytes
 */

int CardQuery_PlayerControlsColor(int player,byte arg2)

{
  int status;
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if ((int)(&g_PlayerActiveCardCount)[player] <= local_8) {
      return 0;
    }
    status = Card_IsTapped(player,local_8);
    if ((status != 0) &&
       ((arg2 & (&g_MasterCardColorTable)
                [*(int *)(&g_CardSlot_CardId + local_8 * 0x120 + player * 0x5b20) * 0x34]) != 0))
    break;
    local_8 = local_8 + 1;
  }
  return 1;
}

/*
 * CardQuery_ForEachPermanent
 * Purpose: Iterate active battlefield cards and invoke callback on each permanent.
 * Procedure:
 * 1. Iterate players and active card slots.
 * 2. Execute callback function on each valid card slot.
 */
/*
 * Decompiled function: CardQuery_ForEachPermanent
 * Entry Point: 004e65e1
 * Size: 210 bytes
 */

void CardQuery_ForEachPermanent(uint8_t *player,int arg2)

{
  int local_10;
  int local_8;
  
  for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
    if ((arg2 == -1) || (local_8 == arg2)) {
      for (local_10 = 0; local_10 < (int)(&g_PlayerActiveCardCount)[local_8];
          local_10 = local_10 + 1) {
        if ((*(int *)(&g_CardSlot_CardId + local_10 * 0x120 + local_8 * 0x5b20) != -1) &&
           (((&g_CardSlot_Flags)[local_10 * 0x120 + local_8 * 0x5b20] & 2) != 0)) {
          (*(code *)player)(local_8,local_10,
                          *(int *)(&g_CardSlot_CardId + local_10 * 0x120 + local_8 * 0x5b20));
        }
      }
    }
  }
  return;
}

/*
 * Card_IncrementCounter
 * Purpose: Increment counter on card slot and notify state machine.
 * Procedure:
 * 1. Increment slot counter register.
 * 2. Trigger upkeep notification if not AI simulation.
 */
/*
 * Decompiled function: Card_IncrementCounter
 * Entry Point: 004e66b3
 * Size: 184 bytes
 */

void Card_IncrementCounter(int player,int card_index)

{
  if (((&DAT_006a5f7c)[card_index * 0x120 + player * 0x5b20] != -1) &&
     (*(uint *)(&DAT_006a5f7c + card_index * 0x120 + player * 0x5b20) =
           *(int *)(&DAT_006a5f7c + card_index * 0x120 + player * 0x5b20) + 1U & 0xff |
           *(uint *)(&DAT_006a5f7c + card_index * 0x120 + player * 0x5b20) & 0xffffff00, g_IsAiThinking != 1
     )) {
    Magic_UpkeepPhase(0x1b);
  }
  return;
}

/*
 * Card_DecrementCounter
 * Purpose: Decrement counter on card slot.
 * Procedure:
 * 1. Decrement slot counter register.
 */
/*
 * Decompiled function: Card_DecrementCounter
 * Entry Point: 004e676b
 * Size: 118 bytes
 */

void Card_DecrementCounter(int player,int card_index)

{
  *(uint *)(&DAT_006a5f7c + card_index * 0x120 + player * 0x5b20) =
       *(int *)(&DAT_006a5f7c + card_index * 0x120 + player * 0x5b20) - 1U & 0xff |
       *(uint *)(&DAT_006a5f7c + card_index * 0x120 + player * 0x5b20) & 0xffffff00;
  return;
}

/*
 * Card_AddCounters
 * Purpose: Add specified count of counters to card slot.
 * Procedure:
 * 1. Add delta to slot counter register.
 * 2. Trigger state machine update.
 */
/*
 * Decompiled function: Card_AddCounters
 * Entry Point: 004e67e1
 * Size: 186 bytes
 */

void Card_AddCounters(int player,int card_index,int event_code)

{
  if (((&DAT_006a5f7c)[player * 0x5b20 + card_index * 0x120] != -1) &&
     (*(uint *)(&DAT_006a5f7c + player * 0x5b20 + card_index * 0x120) =
           *(int *)(&DAT_006a5f7c + player * 0x5b20 + card_index * 0x120) + event_code & 0xffU |
           *(uint *)(&DAT_006a5f7c + player * 0x5b20 + card_index * 0x120) & 0xffffff00,
     g_IsAiThinking != 1)) {
    Magic_UpkeepPhase(0x1b);
  }
  return;
}

/*
 * Card_RemoveCounters
 * Purpose: Deduct specified count of counters from card slot.
 * Procedure:
 * 1. Subtract delta from counter register.
 */
/*
 * Decompiled function: Card_RemoveCounters
 * Entry Point: 004e689b
 * Size: 120 bytes
 */

void Card_RemoveCounters(int player,int card_index,int event_code)

{
  *(uint *)(&DAT_006a5f7c + card_index * 0x120 + player * 0x5b20) =
       *(int *)(&DAT_006a5f7c + card_index * 0x120 + player * 0x5b20) - event_code & 0xffU |
       *(uint *)(&DAT_006a5f7c + card_index * 0x120 + player * 0x5b20) & 0xffffff00;
  return;
}

/*
 * Card_SetCounters
 * Purpose: Set absolute counter value on card slot (clamped to 255).
 * Procedure:
 * 1. Clamp count to 0xFF.
 * 2. Write value to slot counter register.
 */
/*
 * Decompiled function: Card_SetCounters
 * Entry Point: 004e6913
 * Size: 101 bytes
 */

void Card_SetCounters(int player,int card_index,int event_code)

{
  if (0xff < event_code) {
    event_code = 0xff;
  }
  *(uint *)(&DAT_006a5f7c + card_index * 0x120 + player * 0x5b20) =
       CONCAT31((int3)((uint)*(int *)(&DAT_006a5f7c + card_index * 0x120 + player * 0x5b20) >> 8),
                (uint8_t)event_code);
  return;
}

/*
 * Card_GetCounters
 * Purpose: Read counter count from card slot.
 * Procedure:
 * 1. Return 8-bit counter value from card slot.
 */
/*
 * Decompiled function: Card_GetCounters
 * Entry Point: 004e6978
 * Size: 52 bytes
 */

uint Card_GetCounters(int player,int card_index)

{
  return *(uint *)(&DAT_006a5f7c + card_index * 0x120 + player * 0x5b20) & 0xff;
}

/*
 * CardTarget_PromptTargetCreature
 * Purpose: Display target selector for creature permanents.
 * Procedure:
 * 1. Invoke target selection dialog with creature filter.
 * 2. Store chosen target in target buffer.
 */
/*
 * Decompiled function: CardTarget_PromptTargetCreature
 * Entry Point: 004e69ac
 * Size: 300 bytes
 */

bool CardTarget_PromptTargetCreature(int player,uint arg2,int arg3)

{
  uint arg_8;
  uint arg_9;
  uint arg_10;
  int status;
  int arg_12;
  uint arg_13;
  uint arg_14;
  uint arg_15;
  uint arg_16;
  uint arg_17;
  uint8_t *arg_18;
  int arg_19;
  int *arg_20;
  int local_c;
  int local_8;
  
  if (arg2 == 0xffffffff) {
    arg2 = 2;
  }
  arg_20 = &local_c;
  arg_19 = 1;
  arg_18 = &g_OverworldGoldAmount;
  arg_17 = 0;
  arg_16 = 0;
  arg_15 = 0;
  arg_14 = 0xffffffff;
  arg_13 = 0xffffffff;
  arg_12 = -1;
  status = -1;
  arg_10 = 0;
  arg_9 = 0;
  arg_8 = SpellChain_ProcessTriggerEvent(player,arg3);
  status = Action_ValidateTarget_00405802
                    (player,2,arg2,0x200,2,0,0,arg_8,arg_9,arg_10,status,arg_12,arg_13,arg_14,arg_15,
                     arg_16,arg_17,arg_18,arg_19,arg_20);
  if (status != 0) {
    *(int *)
     (&g_CardSlot_AttachedAura +
     player * 0x5b20 +
     arg3 * 0x120 + (char)(&g_CardSlot_TurnPlayed)[player * 0x5b20 + arg3 * 0x120] * 8) = local_8;
    *(int *)(&g_CardSlot_CombatTarget +
            player * 0x5b20 +
            arg3 * 0x120 + (char)(&g_CardSlot_TurnPlayed)[player * 0x5b20 + arg3 * 0x120] * 8) =
         local_c;
    (&g_CardSlot_TurnPlayed)[player * 0x5b20 + arg3 * 0x120] =
         (&g_CardSlot_TurnPlayed)[player * 0x5b20 + arg3 * 0x120] + '\x01';
  }
  return status != 0;
}

/*
 * CardTarget_SetTargetCreature
 * Purpose: Assign targeted creature to card slot target buffer.
 * Procedure:
 * 1. Validate target and assign target index.
 */
/*
 * Decompiled function: CardTarget_SetTargetCreature
 * Entry Point: 004e6add
 * Size: 285 bytes
 */

bool CardTarget_SetTargetCreature(int player,uint arg2,int arg3)

{
  int status;
  int local_c;
  int local_8;
  
  if (arg2 == 0xffffffff) {
    arg2 = 2;
  }
  status = Action_ValidateTarget_00405802
                    (player,2,arg2,0x200,2,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0,0,0,
                     &g_OverworldGoldAmount,1,&local_c);
  if (status != 0) {
    *(int *)(&g_CardSlot_CombatTarget +
            arg3 * 0x120 +
            player * 0x5b20 + (char)(&g_CardSlot_TurnPlayed)[arg3 * 0x120 + player * 0x5b20] * 8) =
         local_c;
    *(int *)
     (&g_CardSlot_AttachedAura +
     arg3 * 0x120 +
     player * 0x5b20 + (char)(&g_CardSlot_TurnPlayed)[arg3 * 0x120 + player * 0x5b20] * 8) = local_8;
    (&g_CardSlot_TurnPlayed)[arg3 * 0x120 + player * 0x5b20] =
         (&g_CardSlot_TurnPlayed)[arg3 * 0x120 + player * 0x5b20] + '\x01';
  }
  return status != 0;
}

/*
 * CardTarget_HasValidCreatureTarget
 * Purpose: Validate whether valid creature target exists for action.
 * Procedure:
 * 1. Check available creatures matching criteria.
 */
/*
 * Decompiled function: CardTarget_HasValidCreatureTarget
 * Entry Point: 004e6bff
 * Size: 461 bytes
 */

int CardTarget_HasValidCreatureTarget(int player)

{
  int status;
  int val_result;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if ((player == g_CurrentTurnPhase) && (g_IsAiThinking != 1)) {
    status = Action_ValidateTarget_00405802
                      (player,player,player,0x200,2,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0,0,0,
                       &g_OverworldGoldAmount,0,&local_1c);
    if (status == 0) {
      local_20 = -1;
    }
    else {
      local_20 = local_18;
    }
  }
  else {
    local_20 = -1;
    local_14 = 0x7fff;
    for (local_10 = 0; local_10 < (int)(&g_PlayerActiveCardCount)[player]; local_10 = local_10 + 1) {
      local_c = *(int *)(&g_CardSlot_CardId + local_10 * 0x120 + player * 0x5b20);
      if ((((local_c != -1) && (((&g_CardSlot_Flags)[local_10 * 0x120 + player * 0x5b20] & 2) != 0))
          && (((&g_MasterCardColorTable)[local_c * 0x34] & 2) != 0)) &&
         ((&DAT_006a5f50)[local_10 * 0x120 + player * 0x5b20] != '\x03')) {
        status = Card_TapForMana(player, local_10, 0x32, 0xffffffff);
        val_result = Card_TapForMana(player,local_10,0x33,0xffffffff);
        local_8 = (status + 2) * (val_result + 2);
        if (local_8 < local_14) {
          local_20 = local_10;
          local_14 = local_8;
        }
      }
    }
  }
  if ((local_20 != -1) && (g_IsAiThinking != 1)) {
    Magic_UpkeepPhase(0xf);
  }
  return local_20;
}

/*
 * CardTarget_PromptTargetPermanent
 * Purpose: Display target selector for any permanent.
 * Procedure:
 * 1. Invoke target selection dialog with permanent filter.
 */
/*
 * Decompiled function: CardTarget_PromptTargetPermanent
 * Entry Point: 004e6dcc
 * Size: 300 bytes
 */

bool CardTarget_PromptTargetPermanent(int player,uint arg2,int arg3)

{
  uint arg_8;
  uint arg_9;
  uint arg_10;
  int status;
  int arg_12;
  uint arg_13;
  uint arg_14;
  uint arg_15;
  uint arg_16;
  uint arg_17;
  uint8_t *arg_18;
  int arg_19;
  int *arg_20;
  int local_c;
  int local_8;
  
  if (arg2 == 0xffffffff) {
    arg2 = 2;
  }
  arg_20 = &local_c;
  arg_19 = 1;
  arg_18 = &g_OverworldGoldAmount;
  arg_17 = 0;
  arg_16 = 0;
  arg_15 = 0;
  arg_14 = 0xffffffff;
  arg_13 = 0xffffffff;
  arg_12 = -1;
  status = -1;
  arg_10 = 0;
  arg_9 = 0;
  arg_8 = SpellChain_ProcessTriggerEvent(player,arg3);
  status = Action_ValidateTarget_00405802
                    (player,2,arg2,0x200,1,0,0,arg_8,arg_9,arg_10,status,arg_12,arg_13,arg_14,arg_15,
                     arg_16,arg_17,arg_18,arg_19,arg_20);
  if (status != 0) {
    *(int *)(&g_CardSlot_CombatTarget +
            player * 0x5b20 +
            arg3 * 0x120 + (char)(&g_CardSlot_TurnPlayed)[player * 0x5b20 + arg3 * 0x120] * 8) =
         local_c;
    *(int *)
     (&g_CardSlot_AttachedAura +
     player * 0x5b20 +
     arg3 * 0x120 + (char)(&g_CardSlot_TurnPlayed)[player * 0x5b20 + arg3 * 0x120] * 8) = local_8;
    (&g_CardSlot_TurnPlayed)[player * 0x5b20 + arg3 * 0x120] =
         (&g_CardSlot_TurnPlayed)[player * 0x5b20 + arg3 * 0x120] + '\x01';
  }
  return status != 0;
}

/*
 * CardTarget_SetTargetPermanent
 * Purpose: Assign targeted permanent to slot buffer.
 * Procedure:
 * 1. Validate and store permanent target.
 */
/*
 * Decompiled function: CardTarget_SetTargetPermanent
 * Entry Point: 004e6efd
 * Size: 285 bytes
 */

bool CardTarget_SetTargetPermanent(int player,uint arg2,int arg3)

{
  int status;
  int local_c;
  int local_8;
  
  if (arg2 == 0xffffffff) {
    arg2 = 2;
  }
  status = Action_ValidateTarget_00405802
                    (player,2,arg2,0x200,1,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0,0,0,
                     &g_OverworldGoldAmount,1,&local_c);
  if (status != 0) {
    *(int *)(&g_CardSlot_CombatTarget +
            arg3 * 0x120 +
            player * 0x5b20 + (char)(&g_CardSlot_TurnPlayed)[arg3 * 0x120 + player * 0x5b20] * 8) =
         local_c;
    *(int *)
     (&g_CardSlot_AttachedAura +
     arg3 * 0x120 +
     player * 0x5b20 + (char)(&g_CardSlot_TurnPlayed)[arg3 * 0x120 + player * 0x5b20] * 8) = local_8;
    (&g_CardSlot_TurnPlayed)[arg3 * 0x120 + player * 0x5b20] =
         (&g_CardSlot_TurnPlayed)[arg3 * 0x120 + player * 0x5b20] + '\x01';
  }
  return status != 0;
}

/*
 * CardTarget_HasValidPermanentTarget
 * Purpose: Validate permanent target availability.
 * Procedure:
 * 1. Check available permanents matching filter.
 */
/*
 * Decompiled function: CardTarget_HasValidPermanentTarget
 * Entry Point: 004e701f
 * Size: 142 bytes
 */

int CardTarget_HasValidPermanentTarget(int player)

{
  int status;
  int u_temp;
  int local_c;
  int local_8;
  
  status = Action_ValidateTarget_00405802
                    (player,player,player,0x200,1,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0,0,0,
                     &g_OverworldGoldAmount,0,&local_c);
  if (status == 0) {
    u_temp = 0;
  }
  else {
    if (g_IsAiThinking != 1) {
      Magic_UpkeepPhase(0xf);
    }
    Pic_Subsystem_0044867e(local_c,local_8,3);
    u_temp = 1;
  }
  return u_temp;
}

/*
 * CardTarget_PromptTargetPlayerOrCreature
 * Purpose: Display target selector for player or creature.
 * Procedure:
 * 1. Invoke target selector allowing player or creature targets.
 */
/*
 * Decompiled function: CardTarget_PromptTargetPlayerOrCreature
 * Entry Point: 004e70ad
 * Size: 300 bytes
 */

bool CardTarget_PromptTargetPlayerOrCreature(int player,uint arg2,int arg3)

{
  uint arg_8;
  uint arg_9;
  uint arg_10;
  int status;
  int arg_12;
  uint arg_13;
  uint arg_14;
  uint arg_15;
  uint arg_16;
  uint arg_17;
  uint8_t *arg_18;
  int arg_19;
  int *arg_20;
  int local_c;
  int local_8;
  
  if (arg2 == 0xffffffff) {
    arg2 = 2;
  }
  arg_20 = &local_c;
  arg_19 = 1;
  arg_18 = &g_OverworldGoldAmount;
  arg_17 = 0;
  arg_16 = 0;
  arg_15 = 0;
  arg_14 = 0xffffffff;
  arg_13 = 0xffffffff;
  arg_12 = -1;
  status = -1;
  arg_10 = 0;
  arg_9 = 0;
  arg_8 = SpellChain_ProcessTriggerEvent(player,arg3);
  status = Action_ValidateTarget_00405802
                    (player,2,arg2,0x200,0x40,0,0,arg_8,arg_9,arg_10,status,arg_12,arg_13,arg_14,
                     arg_15,arg_16,arg_17,arg_18,arg_19,arg_20);
  if (status != 0) {
    *(int *)(&g_CardSlot_CombatTarget +
            arg3 * 0x120 +
            player * 0x5b20 + (char)(&g_CardSlot_TurnPlayed)[arg3 * 0x120 + player * 0x5b20] * 8) =
         local_c;
    *(int *)
     (&g_CardSlot_AttachedAura +
     arg3 * 0x120 +
     player * 0x5b20 + (char)(&g_CardSlot_TurnPlayed)[arg3 * 0x120 + player * 0x5b20] * 8) = local_8;
    (&g_CardSlot_TurnPlayed)[arg3 * 0x120 + player * 0x5b20] =
         (&g_CardSlot_TurnPlayed)[arg3 * 0x120 + player * 0x5b20] + '\x01';
  }
  return status != 0;
}

/*
 * CardTarget_SetTargetPlayerOrCreature
 * Purpose: Assign player or creature target to slot buffer.
 * Procedure:
 * 1. Validate and store chosen target.
 */
/*
 * Decompiled function: CardTarget_SetTargetPlayerOrCreature
 * Entry Point: 004e71de
 * Size: 285 bytes
 */

bool CardTarget_SetTargetPlayerOrCreature(int player,uint arg2,int arg3)

{
  int status;
  int local_c;
  int local_8;
  
  if (arg2 == 0xffffffff) {
    arg2 = 2;
  }
  status = Action_ValidateTarget_00405802
                    (player,2,arg2,0x200,0x40,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0,0,0,
                     &g_OverworldGoldAmount,1,&local_c);
  if (status != 0) {
    *(int *)(&g_CardSlot_CombatTarget +
            arg3 * 0x120 +
            player * 0x5b20 + (char)(&g_CardSlot_TurnPlayed)[arg3 * 0x120 + player * 0x5b20] * 8) =
         local_c;
    *(int *)
     (&g_CardSlot_AttachedAura +
     arg3 * 0x120 +
     player * 0x5b20 + (char)(&g_CardSlot_TurnPlayed)[arg3 * 0x120 + player * 0x5b20] * 8) = local_8;
    (&g_CardSlot_TurnPlayed)[arg3 * 0x120 + player * 0x5b20] =
         (&g_CardSlot_TurnPlayed)[arg3 * 0x120 + player * 0x5b20] + '\x01';
  }
  return status != 0;
}

/*
 * CardTarget_HasValidPlayerOrCreatureTarget
 * Purpose: Validate player or creature target availability.
 * Procedure:
 * 1. Check available targets matching criteria.
 */
/*
 * Decompiled function: CardTarget_HasValidPlayerOrCreatureTarget
 * Entry Point: 004e7300
 * Size: 142 bytes
 */

int CardTarget_HasValidPlayerOrCreatureTarget(int player)

{
  int status;
  int u_temp;
  int local_c;
  int local_8;
  
  status = Action_ValidateTarget_00405802
                    (player,player,player,0x200,0x40,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0,0,0,
                     &g_OverworldGoldAmount,0,&local_c);
  if (status == 0) {
    u_temp = 0;
  }
  else {
    if (g_IsAiThinking != 1) {
      Magic_UpkeepPhase(0xf);
    }
    Pic_Subsystem_0044867e(local_c,local_8,3);
    u_temp = 1;
  }
  return u_temp;
}


/*
 * sid/Ai.c - MicroProse Sid Meier Tactical AI & Decision Heuristics Engine
 * Reconstructed MicroProse Source Module
 * Author: Sid Meier / MicroProse (1997)
 *
 * Comments follow Simplified Technical English (ASD-STE100) rules.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include "shandalar/shandalar.h"
#include "shandalar/win32_compat.h"
#include "shandalar/ai.h"
#include "shandalar/glue.h"

/*
 * Ai_SaveGameState
 * Purpose: Copy current game state to backup lookahead memory buffer.
 * Procedure:
 * 1. Set backup counter to zero.
 * 2. Copy card structures, player state, and life totals to backup buffer.
 * 3. Verify evaluation score validity (ScWilly >= 0).
 */
/*
 * Decompiled function: Ai_SaveGameState
 * Entry Point: 004aa830
 * Size: 698 bytes
 */

void Ai_SaveGameState(void)

{
  DAT_00556928 = 0;
  memcpy(&DAT_00627a90,&g_ActiveCardsInPlay,0xb640);
  memcpy(&DAT_006330f0,&g_MasterCardTable + g_MasterCardCount * 0x34,0x340);
  memcpy(&DAT_00554050,&g_AiLookaheadTreeCurrentNode,4000);
  memcpy(&DAT_0054e818,&g_AiEvaluationPassCounter,4000);
  memcpy(&DAT_0054c620,&g_AiTemporaryBuffer_006b1590,4000);
  memcpy(&DAT_0054e7d8,&g_AiCombatScore_Total,0x40);
  memcpy(&DAT_0054e790,&g_AiLookaheadDepth,0x40);
  memcpy(&DAT_00555900,&g_AiCombatScore_Attacker,0x40);
  memcpy(&DAT_005532a0,&DAT_00627870,0x198);
  memcpy(&DAT_00553438,&g_PlayerCreatureCount,8);
  memcpy(&DAT_00554048,&DAT_00696870,8);
  memcpy(&DAT_00555100,&DAT_006a2828,8);
  memcpy(&DAT_005550f8,&DAT_00695e00,8);
  memcpy(&DAT_005501a0,&DAT_006b3000,0x60);
  memcpy(&DAT_0054f7b8,&g_AiSelectedAbilityIndex,0x80);
  memcpy(&DAT_005529b8,&DAT_007006e0,2000);
  memcpy(&DAT_005518f8,&DAT_006a5750,2000);
  DAT_00555980 = g_PlayerHandCardCount;
  DAT_00550480 = g_ScWillyScore;
  DAT_006498f0 = g_ScWillyScore;
  DAT_00554ff0 = DAT_0068a708;
  DAT_0055319c = g_ActiveBattlefieldFlag;
  DAT_0054be40 = g_ActivePlayer;
  memcpy(&DAT_00552938,&DAT_006ff4d0,0x80);
  memcpy(&DAT_00554ff8,&DAT_006fecc0,0x100);
  memcpy(&DAT_00550308,&DAT_006ff390,0x100);
  memcpy(&DAT_005558f8,&g_PlayerActiveCardCount,8);
  if (g_AiEvaluatedMoveCount < 0) {
    assert(s_ScWilly>_0_0052ce44,s_G__NewMagic_sources_sid_Ai_c_0052ce24,0x176);
  }
  DAT_0054e5e8 = g_AiEvaluatedMoveCount;
  DAT_00550178 = DAT_00695f18;
  DAT_005528cc = DAT_007006d4;
  memcpy(&DAT_00550038,&DAT_00700ec0,0x140);
  memcpy(&DAT_00550450,&DAT_006330d0,0x20);
  memcpy(&DAT_00550180,&g_AiSelectedTargetCard,0x1c);
  FUN_0040a1ff();
  return;
}

/*
 * Ai_RestoreGameState
 * Purpose: Restore saved game state from backup lookahead memory buffer.
 * Procedure:
 * 1. Copy all card structures back to active memory.
 * 2. Restore life totals, mana pools, and turn counters.
 * 3. Reset temporary lookahead evaluation variables.
 */
/*
 * Decompiled function: Ai_RestoreGameState
 * Entry Point: 004aaaea
 * Size: 631 bytes
 */

void Ai_RestoreGameState(void)

{
  memcpy(&g_ActiveCardsInPlay,&DAT_00627a90,0xb640);
  memcpy(&g_MasterCardTable + g_MasterCardCount * 0x34,&DAT_006330f0,0x340);
  memcpy(&g_AiLookaheadTreeCurrentNode,&DAT_00554050,4000);
  memcpy(&g_AiEvaluationPassCounter,&DAT_0054e818,4000);
  memcpy(&g_AiTemporaryBuffer_006b1590,&DAT_0054c620,4000);
  memcpy(&g_AiCombatScore_Total,&DAT_0054e7d8,0x40);
  memcpy(&g_AiLookaheadDepth,&DAT_0054e790,0x40);
  memcpy(&g_AiCombatScore_Attacker,&DAT_00555900,0x40);
  memcpy(&DAT_00627870,&DAT_005532a0,0x198);
  memcpy(&g_PlayerCreatureCount,&DAT_00553438,8);
  memcpy(&DAT_00696870,&DAT_00554048,8);
  memcpy(&DAT_006a2828,&DAT_00555100,8);
  memcpy(&DAT_00695e00,&DAT_005550f8,8);
  memcpy(&DAT_006b3000,&DAT_005501a0,0x60);
  memcpy(&g_AiSelectedAbilityIndex,&DAT_0054f7b8,0x80);
  memcpy(&DAT_007006e0,&DAT_005529b8,2000);
  memcpy(&DAT_006a5750,&DAT_005518f8,2000);
  g_PlayerHandCardCount = DAT_00555980;
  g_ScWillyScore = DAT_00550480;
  DAT_0068a708 = DAT_00554ff0;
  g_ActiveBattlefieldFlag = DAT_0055319c;
  g_ActivePlayer = DAT_0054be40;
  memcpy(&DAT_006ff4d0,&DAT_00552938,0x80);
  memcpy(&DAT_006fecc0,&DAT_00554ff8,0x100);
  memcpy(&DAT_006ff390,&DAT_00550308,0x100);
  memcpy(&g_PlayerActiveCardCount,&DAT_005558f8,8);
  g_AiEvaluatedMoveCount = DAT_0054e5e8;
  DAT_00695f18 = DAT_00550178;
  DAT_007006d4 = DAT_005528cc;
  memcpy(&DAT_00700ec0,&DAT_00550038,0x140);
  memcpy(&DAT_006330d0,&DAT_00550450,0x20);
  memcpy(&g_AiSelectedTargetCard,&DAT_00550180,0x1c);
  Mem_AllocOrFree_0040a240();
  return;
}

/*
 * Ai_PushBoardState
 * Purpose: Push active board state onto tactical decision tree stack.
 * Procedure:
 * 1. Increment decision tree depth counter.
 * 2. Save card states, priorities, and scores onto stack frame.
 */
/*
 * Decompiled function: Ai_PushBoardState
 * Entry Point: 004aad61
 * Size: 583 bytes
 */

void Ai_PushBoardState(void)

{
  memcpy(&DAT_00633440,&g_ActiveCardsInPlay,0xb640);
  memcpy(&DAT_0063ea80,&g_MasterCardTable + g_MasterCardCount * 0x34,0x340);
  memcpy(&DAT_0054d648,&g_AiLookaheadTreeCurrentNode,4000);
  memcpy(&DAT_005504d8,&g_AiEvaluationPassCounter,4000);
  memcpy(&DAT_00555988,&g_AiTemporaryBuffer_006b1590,4000);
  memcpy(&DAT_00555940,&g_AiCombatScore_Total,0x40);
  memcpy(&DAT_00550498,&g_AiLookaheadDepth,0x40);
  memcpy(&DAT_00550408,&g_AiCombatScore_Attacker,0x40);
  memcpy(&DAT_0054e5f0,&DAT_00627870,0x198);
  memcpy(&DAT_0054be48,&g_PlayerCreatureCount,8);
  memcpy(&DAT_00550448,&DAT_00696870,8);
  memcpy(&DAT_00550470,&DAT_006a2828,8);
  memcpy(&DAT_00550478,&DAT_00695e00,8);
  memcpy(&DAT_005528d0,&DAT_006b3000,0x60);
  memcpy(&DAT_00551478,&g_AiSelectedAbilityIndex,0x80);
  memcpy(&DAT_00555108,&DAT_007006e0,2000);
  memcpy(&DAT_0054be50,&DAT_006a5750,2000);
  DAT_00550300 = g_PlayerHandCardCount;
  DAT_00554040 = g_ScWillyScore;
  DAT_00550484 = DAT_0068a708;
  DAT_00550490 = g_ActiveBattlefieldFlag;
  DAT_00552930 = g_ActivePlayer;
  memcpy(&DAT_0054d5c0,&DAT_006ff4d0,0x80);
  memcpy(&DAT_005531a0,&DAT_006fecc0,0x100);
  memcpy(&DAT_00550200,&DAT_006ff390,0x100);
  memcpy(&DAT_00550488,&g_PlayerActiveCardCount,8);
  DAT_00553188 = g_AiEvaluatedMoveCount;
  DAT_0054e7d0 = DAT_00695f18;
  DAT_0054e788 = g_SpellStackDepth;
  memcpy(&DAT_005558d8,&g_AiSelectedTargetCard,0x1c);
  return;
}

/*
 * Ai_PopBoardState
 * Purpose: Pop and restore previous board state from tactical decision tree stack.
 * Procedure:
 * 1. Decrement decision tree depth counter.
 * 2. Restore previous card states and scores from stack frame.
 */
/*
 * Decompiled function: Ai_PopBoardState
 * Entry Point: 004aafa8
 * Size: 583 bytes
 */

void Ai_PopBoardState(void)

{
  memcpy(&g_ActiveCardsInPlay,&DAT_00633440,0xb640);
  memcpy(&g_MasterCardTable + g_MasterCardCount * 0x34,&DAT_0063ea80,0x340);
  memcpy(&g_AiLookaheadTreeCurrentNode,&DAT_0054d648,4000);
  memcpy(&g_AiEvaluationPassCounter,&DAT_005504d8,4000);
  memcpy(&g_AiTemporaryBuffer_006b1590,&DAT_00555988,4000);
  memcpy(&g_AiCombatScore_Total,&DAT_00555940,0x40);
  memcpy(&g_AiLookaheadDepth,&DAT_00550498,0x40);
  memcpy(&g_AiCombatScore_Attacker,&DAT_00550408,0x40);
  memcpy(&DAT_00627870,&DAT_0054e5f0,0x198);
  memcpy(&g_PlayerCreatureCount,&DAT_0054be48,8);
  memcpy(&DAT_00696870,&DAT_00550448,8);
  memcpy(&DAT_006a2828,&DAT_00550470,8);
  memcpy(&DAT_00695e00,&DAT_00550478,8);
  memcpy(&DAT_006b3000,&DAT_005528d0,0x60);
  memcpy(&g_AiSelectedAbilityIndex,&DAT_00551478,0x80);
  memcpy(&DAT_007006e0,&DAT_00555108,2000);
  memcpy(&DAT_006a5750,&DAT_0054be50,2000);
  g_PlayerHandCardCount = DAT_00550300;
  g_ScWillyScore = DAT_00554040;
  DAT_0068a708 = DAT_00550484;
  g_ActiveBattlefieldFlag = DAT_00550490;
  g_ActivePlayer = DAT_00552930;
  memcpy(&DAT_006ff4d0,&DAT_0054d5c0,0x80);
  memcpy(&DAT_006fecc0,&DAT_005531a0,0x100);
  memcpy(&DAT_006ff390,&DAT_00550200,0x100);
  memcpy(&g_PlayerActiveCardCount,&DAT_00550488,8);
  g_AiEvaluatedMoveCount = DAT_00553188;
  DAT_00695f18 = DAT_0054e7d0;
  g_SpellStackDepth = DAT_0054e788;
  memcpy(&g_AiSelectedTargetCard,&DAT_005558d8,0x1c);
  return;
}

/*
 * Ai_ResetEvaluationState
 * Purpose: Clear all tactical evaluation state variables for new analysis pass.
 * Procedure:
 * 1. Reset active creature counter to zero.
 * 2. Initialize score lookup table to default values (99).
 */
/*
 * Decompiled function: Ai_ResetEvaluationState
 * Entry Point: 004ab1ef
 * Size: 37 bytes
 */

void Ai_ResetEvaluationState(void)

{
  g_AiBestScoreTable = 0;
  g_AiCardScore_BasicLand = 99;
  return;
}

/*
 * Ai_GetActivePlayerScore
 * Purpose: Calculate total tactical score for the active AI player.
 * Procedure:
 * 1. Restore baseline evaluation state.
 * 2. Aggregate creature power, card advantage, and life scores.
 * 3. Return calculated total score.
 */
/*
 * Decompiled function: Ai_GetActivePlayerScore
 * Entry Point: 004ab214
 * Size: 119 bytes
 */

void Ai_GetActivePlayerScore(void)

{
  int local_8;
  
  DAT_00701008 = 0;
  g_AiBestScoreTable = 0;
  DAT_0063ee70 = 0xffffffff;
  for (local_8 = 0; local_8 < 0x100; local_8 = local_8 + 1) {
    (&DAT_005524c8)[local_8] = 99;
  }
  Ai_RestoreGameState();
  if (g_IsAiThinking != 1) {
    DAT_006808a8 = 0xffffffff;
  }
  return;
}

/*
 * Ai_EvaluateCreaturePower
 * Purpose: Calculate attacking power and defensive toughness for creature.
 * Procedure:
 * 1. Read power and toughness attributes of creature slot.
 * 2. Apply ability multipliers (flying, first strike, trample).
 * 3. Store evaluated power in creature score array.
 */
/*
 * Decompiled function: Ai_EvaluateCreaturePower
 * Entry Point: 004ab28b
 * Size: 211 bytes
 */

void Ai_EvaluateCreaturePower(void)

{
  if (g_AiBestScoreTable < 0x100) {
    *(uint *)(&DAT_0054fc38 + g_AiBestScoreTable * 4) = g_AiCurrentSearchPath;
    *(int *)(&DAT_00553840 + g_AiBestScoreTable * 4) =
         *(int *)
          (&g_CardSlot_CardId +
          (g_AiCurrentSearchPath & 0xff) * 0x120 + ((g_AiCurrentSearchPath & 0x100) >> 8) * 0x5b20);
    *(int *)(&DAT_00553c40 + g_AiBestScoreTable * 4) = DAT_0052ce1c;
    (&DAT_005524c8)[g_AiBestScoreTable] = g_AiDecisionScore;
    g_AiBestScoreTable = g_AiBestScoreTable + 1;
    if ((DAT_005524c8 == 99) || (g_AiCardScore_BasicLand == 99)) {
      g_AiCurrentSearchPath = 0xffffffff;
    }
  }
  else {
    g_ActivePlayer = 1;
  }
  DAT_0052ce1c = 0;
  return;
}

/*
 * Ai_GetOpponentPlayerScore
 * Purpose: Calculate threat score of opponent cards on battlefield.
 * Procedure:
 * 1. Evaluate opponent creature power, hand size, and open mana.
 * 2. Return composite threat score (ScWilly metric).
 */
/*
 * Decompiled function: Ai_GetOpponentPlayerScore
 * Entry Point: 004ab35e
 * Size: 75 bytes
 */

int Ai_GetOpponentPlayerScore(int arg1)

{
  if ((g_IsAiThinking != 1) &&
     (g_AiCurrentSearchPath = *(uint *)(&DAT_0054f838 + (arg1 + g_AiBestScoreTable) * 4),
     g_AiCurrentSearchPath != 0xffffffff)) {
    g_AiCurrentSearchPath = g_AiCurrentSearchPath & 0xfff;
  }
  return 0;
}

/*
 * Ai_CalcLifeAdvantage
 * Purpose: Calculate heuristic score for life point difference between players.
 * Procedure:
 * 1. Compute life total differential (player life minus opponent life).
 * 2. Apply non-linear scaling when life is below critical threshold.
 */
/*
 * Decompiled function: Ai_CalcLifeAdvantage
 * Entry Point: 004ab3a9
 * Size: 74 bytes
 */

int Ai_CalcLifeAdvantage(int arg1)

{
  if ((g_IsAiThinking != 1) &&
     (DAT_0062785c = (&g_AiCardScore_BasicLand)[g_AiBestScoreTable + arg1], DAT_0062785c == 99)) {
    DAT_0062785c = 0;
  }
  return 0;
}

/*
 * Ai_CalcCardAdvantage
 * Purpose: Calculate heuristic score for hand and library card advantage.
 * Procedure:
 * 1. Count available cards in hand and library.
 * 2. Weight cards in hand higher than library depth.
 * 3. Return card advantage bonus score.
 */
/*
 * Decompiled function: Ai_CalcCardAdvantage
 * Entry Point: 004ab3f3
 * Size: 108 bytes
 */

void Ai_CalcCardAdvantage(void)

{
  g_AiCurrentSearchPath = *(int *)(&DAT_0054f838 + g_AiBestScoreTable * 4);
  g_AiDecisionScore = (&g_AiCardScore_BasicLand)[g_AiBestScoreTable];
  if ((&g_AiCardScore_BasicLand)[g_AiBestScoreTable] != 99) {
    g_AiBestScoreTable = g_AiBestScoreTable + 1;
  }
  DAT_0052ce1c = 0;
  return;
}

/*
 * Ai_ScoreBoardPosition
 * Purpose: Calculate composite score for entire battlefield board position.
 * Procedure:
 * 1. Iterate through all active permanents on battlefield.
 * 2. Sum creature scores, enchantment bonuses, and land tempo.
 * 3. Store evaluated composite score in master position buffer.
 */
/*
 * Decompiled function: Ai_ScoreBoardPosition
 * Entry Point: 004ab45f
 * Size: 177 bytes
 */

void Ai_ScoreBoardPosition(void)

{
  int local_8;
  
  for (local_8 = 0; local_8 < g_AiBestScoreTable; local_8 = local_8 + 1) {
    (&g_AiCardScore_BasicLand)[local_8] = (&DAT_005524c8)[local_8];
    *(int *)(&DAT_0054f838 + local_8 * 4) = *(int *)(&DAT_0054fc38 + local_8 * 4);
    *(int *)(&DAT_00553440 + local_8 * 4) = *(int *)(&DAT_00553840 + local_8 * 4);
    *(int *)(&DAT_005514f8 + local_8 * 4) = *(int *)(&DAT_00553c40 + local_8 * 4);
  }
  (&g_AiCardScore_BasicLand)[g_AiBestScoreTable] = 99;
  if (g_AiCardScore_BasicLand == 99) {
    DAT_00556928 = g_AiBestScoreTable;
  }
  DAT_00633434 = 1;
  return;
}

/*
 * Ai_Score_ClearCache
 * Purpose: Clear cached board evaluation scores.
 * Procedure:
 * 1. Reset score cache validity flags to zero.
 */
/*
 * Decompiled function: Ai_Score_ClearCache
 * Entry Point: 004ab510
 * Size: 21 bytes
 */

int Ai_Score_ClearCache(void)

{
  return g_AiBestScoreTable;
}

/*
 * Ai_Score_SetValidityFlag
 * Purpose: Set board evaluation score cache valid flag.
 * Procedure:
 * 1. Mark score cache as valid for current turn phase.
 */
/*
 * Decompiled function: Ai_Score_SetValidityFlag
 * Entry Point: 004ab525
 * Size: 45 bytes
 */

void Ai_Score_SetValidityFlag(void)

{
  if (g_AiBestScoreTable < 1) {
    g_AiBestScoreTable = 0;
  }
  else {
    g_AiBestScoreTable = g_AiBestScoreTable + -1;
  }
  return;
}

/*
 * Ai_SimulateCombatRound
 * Purpose: Simulate complete combat step between attacker and defender.
 * Procedure:
 * 1. Evaluate legal blocking assignments with Ai_FilterValidBlockers.
 * 2. Calculate combat damage dealt to creatures and defending player.
 * 3. Compute life point changes and determine combat advantage score.
 */
/*
 * Decompiled function: Ai_SimulateCombatRound
 * Entry Point: 004ab552
 * Size: 2722 bytes
 */

int Ai_SimulateCombatRound(int arg1)

{
  int status;
  uint u_temp;
  uint u_score;
  int card_idx;
  char *output_str;
  bool bVar5;
  uint local_e4;
  uint local_d4 [2];
  byte local_cc [160];
  uint local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  g_CardSlot_PowerBonus = 1;
  local_c = 0;
  local_28 = 1 - arg1;
  Ai_FilterValidBlockers(local_d4,local_d4 + 1);
  memset(local_cc,0,0xa0);
  local_20 = 0;
  for (local_1c = 1; local_1c <= (int)(&g_PlayerCreatureCount)[arg1]; local_1c = local_1c + 1) {
    local_20 = local_20 + (int)(0x18 / (longlong)local_1c) + 0xc;
  }
  status = *(int *)(&g_PlayerLifeTotals + arg1 * 4) * local_20;
  local_20 = 0;
  for (local_1c = 1; local_1c <= (int)(&g_PlayerCreatureCount)[local_28]; local_1c = local_1c + 1) {
    local_20 = local_20 + (int)(0x18 / (longlong)local_1c) + 0xc;
  }
  local_c = ((int)(status + (status >> 0x1f & 7U)) >> 3) -
            ((int)(*(int *)(&g_PlayerLifeTotals + local_28 * 4) * local_20 +
                  (*(int *)(&g_PlayerLifeTotals + local_28 * 4) * local_20 >> 0x1f & 7U)) >> 3);
  if ((int)(&g_PlayerCreatureCount)[arg1] < 1) {
    local_c = local_c + ((&g_PlayerCreatureCount)[arg1] * 4 + -8) * 0x4b;
  }
  if ((int)(&g_PlayerCreatureCount)[local_28] < 1) {
    local_c = local_c + ((&g_PlayerCreatureCount)[local_28] + -2) * -0x100;
  }
  if (g_CardSlot_ToughnessBonus != 0) {
    g_OverworldWorldState = 0;
  }
  local_8 = 0;
  do {
    if (1 < local_8) {
      for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
        for (local_1c = 0; local_1c < (int)(&g_PlayerActiveCardCount)[local_8];
            local_1c = local_1c + 1) {
          if ((1 << ((byte)arg1 & 0x1f) & (int)(char)local_cc[local_8 * 0x50 + local_1c]) != 0) {
            local_c = local_c + 2;
          }
          if ((1 << (1 - (byte)arg1 & 0x1f) & (int)(char)local_cc[local_8 * 0x50 + local_1c]) != 0)
          {
            local_c = local_c + -2;
          }
        }
      }
      if ((DAT_00676c8c == 0) && (g_DefendingPlayer == arg1)) {
        local_c = Ai_ChooseAttackers(arg1,local_c);
      }
      g_CardSlot_PowerBonus = 0;
      return local_c;
    }
    local_28 = 1 - local_8;
    local_10 = -(((-(uint)(g_ActivePlayerPriority == local_8) & 0x30) + 0x18) *
                *(int *)(&DAT_0063eeac + local_8 * 0x20));
    for (local_1c = 1; local_1c < 6; local_1c = local_1c + 1) {
      for (local_24 = 1; local_24 <= *(int *)(&g_AiCombatScore_Attacker + local_1c * 4 + local_8 * 0x20);
          local_24 = local_24 + 1) {
        local_10 = local_10 + (int)(0x30 / (longlong)local_24);
      }
    }
    for (local_1c = 0; local_1c < (int)(&g_PlayerActiveCardCount)[local_8]; local_1c = local_1c + 1)
    {
      if (*(int *)(&g_CardSlot_CardId + local_1c * 0x120 + local_8 * 0x5b20) != -1) {
        local_14 = *(int *)(&g_CardSlot_CardId + local_1c * 0x120 + local_8 * 0x5b20);
        if (((&g_MasterCardColorTable)[local_14 * 0x34] & 0x80) == 0) {
          local_2c = 1;
          if (((&g_MasterCardColorTable)[local_14 * 0x34] & 2) != 0) {
            u_temp = FUN_00473179(local_8,local_1c,0x34,0xffffffff);
            u_score = FUN_00473179(local_8,local_1c,0x32,0xffffffff);
            local_18 = (u_score & 0xffffbfff) * 2;
            if ((&DAT_0051aebd)[local_14 * 0x34] == '\0') {
              local_18 = 0;
            }
            status = local_18;
            u_score = FUN_00473179(local_8,local_1c,0x33,0xffffffff);
            u_score = u_score & 0xffffbfff;
            local_2c = (int)((status + 3) * (u_score + 4)) / 2;
            if ((((&g_CardSlot_Flags)[local_1c * 0x120 + local_8 * 0x5b20] & 0x10) != 0) &&
               (g_DefendingPlayer == local_8)) {
              local_2c = local_2c + -1;
            }
            if ((u_temp & 0x80) != 0) {
              local_2c = (int)(local_2c * 3) / 2;
            }
            if ((u_temp & 0x100) != 0) {
              local_2c = (int)(local_2c * 3) / 2;
            }
            if (((&g_MasterCardSubtypeTable)[local_14 * 0x34] & 3) != 0) {
              local_2c = (int)(local_2c * 3) / 2;
            }
            if ((u_temp & 0x40) != 0) {
              local_2c = (int)((u_score + 1) * local_2c) / 2;
            }
            if ((u_temp & 0x200) != 0) {
              local_2c = (int)(local_2c * 3) / 2;
            }
            if ((((DAT_00676c8c == 0) && (local_8 != arg1)) && (g_DefendingPlayer == arg1)) &&
               (((&g_CardSlot_Flags)[local_1c * 0x120 + local_8 * 0x5b20] & 2) != 0)) {
              local_e4 = 0;
              u_temp = FUN_00473179(local_8,local_1c,0x34,0xffffffff);
              for (local_24 = 0; local_24 < (int)(&g_PlayerActiveCardCount)[local_28];
                  local_24 = local_24 + 1) {
                card_idx = FUN_00472c0c(local_28,local_24,local_8,local_1c,u_temp,local_d4[local_8]);
                if (card_idx != 0) {
                  local_e4 = 1;
                  card_idx = FUN_00473179(local_28,local_24,0x33,local_1c);
                  if ((status < card_idx) ||
                     (card_idx = FUN_00473179(local_28,local_24,0x32,local_1c), (int)u_score <= card_idx)) {
                    local_e4 = 3;
                    break;
                  }
                }
              }
              if ((local_e4 & 2) == 0) {
                card_idx = *(int *)(&g_PlayerLifeTotals + local_28 * 4) * local_18 * 0x18;
                local_10 = local_10 + ((int)(card_idx + (card_idx >> 0x1f & 0xfU)) >> 4);
                if ((local_e4 == 0) && ((int)(&g_PlayerCreatureCount)[local_28] <= status)) {
                  local_10 = local_10 + 0x100;
                }
              }
            }
            if (((&g_CardSlot_Flags)[local_1c * 0x120 + local_8 * 0x5b20] & 2) == 0) {
              if (*(code **)(&g_MasterCardManaCostTable + local_14 * 0x34) == Card_KormusBell_CheckSwampCreature)
              {
                local_2c = 1;
              }
            }
            else {
              local_2c = local_2c * 3;
            }
            local_2c = (int)(*(int *)(&g_AiPlayerLifeDifferential + local_8 * 4) * local_2c +
                            ((int)(*(int *)(&g_AiPlayerLifeDifferential + local_8 * 4) * local_2c) >> 0x1f & 7U))
                       >> 3;
          }
          if (((&g_MasterCardColorTable)[local_14 * 0x34] & 1) != 0) {
            if (((&g_CardSlot_Flags)[local_1c * 0x120 + local_8 * 0x5b20] & 2) == 0) {
              local_2c = 2;
            }
            else {
              bVar5 = ((&g_CardSlot_Flags)[local_1c * 0x120 + local_8 * 0x5b20] & 0x10) == 0;
              if (bVar5) {
                local_2c = 1;
              }
              else {
                local_2c = 0;
              }
              local_2c = (uint)bVar5;
            }
          }
          if (((&g_MasterCardColorTable)[local_14 * 0x34] == '@') &&
             (((&g_CardSlot_Flags)[local_1c * 0x120 + local_8 * 0x5b20] & 2) != 0)) {
            local_2c = (((char)(&DAT_0051aec0)[local_14 * 0x34] * 3 + 3) * 4) / 2;
          }
          if (((((&g_MasterCardColorTable)[local_14 * 0x34] == '\x04') &&
               (((&g_CardSlot_Flags)[local_1c * 0x120 + local_8 * 0x5b20] & 2) != 0)) &&
              ((&g_CardSlot_Toughness)[local_1c * 0x120 + local_8 * 0x5b20] != -1)) &&
             (*(int *)(&g_CardSlot_OriginalCardId + local_1c * 0x120 + local_8 * 0x5b20) != -1)) {
            local_cc[(char)(&g_CardSlot_Toughness)[local_1c * 0x120 + local_8 * 0x5b20] * 0x50 +
                     *(int *)(&g_CardSlot_OriginalCardId + local_1c * 0x120 + local_8 * 0x5b20)] =
                 local_cc[(char)(&g_CardSlot_Toughness)[local_1c * 0x120 + local_8 * 0x5b20] * 0x50
                          + *(int *)(&g_CardSlot_OriginalCardId +
                                    local_1c * 0x120 + local_8 * 0x5b20)] |
                 (byte)(1 << ((byte)local_8 & 0x1f));
          }
          if ((((&g_MasterCardColorTable)[local_14 * 0x34] & 0x38) != 0) &&
             (((&g_CardSlot_Flags)[local_1c * 0x120 + local_8 * 0x5b20] & 2) == 0)) {
            status = Pic_Subsystem_00452551(local_14);
            local_2c = status * 0xc;
          }
          if ((((&g_MasterCardColorTable)[local_14 * 0x34] & 4) != 0) &&
             (((&g_CardSlot_Flags)[local_1c * 0x120 + local_8 * 0x5b20] & 2) == 0)) {
            local_2c = 3;
          }
          local_10 = local_10 + local_2c;
          if (((g_CardSlot_ToughnessBonus & 2) != 0) && (local_8 + 2U == g_CardSlot_ToughnessBonus)) {
            Ai_Subsystem_004b90de(local_8,local_1c);
            strcat(&g_OverworldWorldState,&DAT_0052ce50);
            output_str = _itoa(local_2c,&DAT_00553190,10);
            strcat(&g_OverworldWorldState,output_str);
            strcat(&g_OverworldWorldState,&DAT_0052ce54);
          }
        }
      }
    }
    (&DAT_006b2538)[local_8] = local_10;
    if (local_8 == arg1) {
      local_c = local_c + local_10;
    }
    else {
      local_c = local_c - local_10;
    }
    local_8 = local_8 + 1;
  } while( true );
}

/*
 * Ai_ChooseAttackers
 * Purpose: Select optimal set of creatures to declare as attackers.
 * Procedure:
 * 1. Evaluate combat strength for each untapped creature.
 * 2. Simulate combat outcomes against potential blockers.
 * 3. Mark optimal candidates with attacking flag.
 */
/*
 * Decompiled function: Ai_ChooseAttackers
 * Entry Point: 004abff4
 * Size: 2380 bytes
 */

int Ai_ChooseAttackers(int player, int attacker_idx)

{
  int x;
  int status;
  int val_result;
  int temp_idx;
  int local_1c0;
  int local_1bc;
  uint local_1b8;
  int local_1b4;
  int local_1b0;
  uint local_1a8;
  int local_1a4;
  int local_1a0;
  int local_19c;
  uint local_198;
  int aiStack_194 [16];
  int aiStack_154 [24];
  int local_f4;
  int aiStack_f0 [16];
  int local_b0;
  char acStack_ac [80];
  int local_5c;
  int aiStack_58 [16];
  int local_18;
  int local_14;
  int local_10;
  char acStack_c [8];
  
  x = 1 - arg1;
  Ai_FilterValidBlockers(&local_1a8,(uint *)0x0);
  for (local_1a0 = 0; local_1a0 < 8; local_1a0 = local_1a0 + 1) {
    acStack_c[local_1a0] = (&g_AiCombatScore_Total)[local_1a0 * 4 + x * 0x20];
    *(int *)(&g_AiCombatScore_Total + local_1a0 * 4 + x * 0x20) =
         *(int *)(&g_AiCombatScore_Attacker + local_1a0 * 4 + x * 0x20);
  }
  for (local_14 = 0; local_14 < 8; local_14 = local_14 + 1) {
    aiStack_154[local_14 * 3 + 1] = -1;
  }
  local_10 = 0;
  for (local_1b0 = 0; local_1b0 < (int)(&g_PlayerActiveCardCount)[arg1]; local_1b0 = local_1b0 + 1)
  {
    if (((*(int *)(&g_CardSlot_CardId + local_1b0 * 0x120 + arg1 * 0x5b20) != -1) &&
        ((*(uint *)(&g_CardSlot_Flags + local_1b0 * 0x120 + arg1 * 0x5b20) & 0x402) != 0)) &&
       (((&g_MasterCardColorTable)
         [*(int *)(&g_CardSlot_CardId + local_1b0 * 0x120 + arg1 * 0x5b20) * 0x34] & 2) != 0)) {
      acStack_ac[local_1b0] = (char)local_10;
      status = FUN_00473179(arg1,local_1b0,0x32,0xffffffff);
      aiStack_f0[local_10] = status;
      status = FUN_00473179(arg1,local_1b0,0x33,0xffffffff);
      aiStack_194[local_10] = status;
      aiStack_58[local_10] = *(int *)(&DAT_006a5f70 + local_1b0 * 0x120 + arg1 * 0x5b20);
      local_10 = local_10 + 1;
    }
  }
  for (local_1a0 = 0; local_1a0 < (int)(&g_PlayerActiveCardCount)[x]; local_1a0 = local_1a0 + 1) {
    local_19c = *(int *)(&g_CardSlot_CardId + local_1a0 * 0x120 + x * 0x5b20);
    if (((local_19c != -1) && (((&g_MasterCardColorTable)[local_19c * 0x34] & 2) != 0)) &&
       ((((&g_CardSlot_Flags)[local_1a0 * 0x120 + x * 0x5b20] & 2) != 0 &&
        (((&DAT_0051aebd)[local_19c * 0x34] != '\0' ||
         (((&DAT_006a5f69)[local_1a0 * 0x120 + x * 0x5b20] & 8) != 0)))))) {
      local_1c0 = FUN_00473179(x,local_1a0,0x32,0xffffffff);
      local_1bc = FUN_00473179(x,local_1a0,0x33,0xffffffff);
      if (g_CurrentTurnPhase == x) {
        if (((&g_MasterCardSubtypeTable)[local_19c * 0x34] & 8) != 0) {
          status = (**(code **)(&g_MasterCardManaCostTable + local_19c * 0x34))(x,local_1a0,0x39);
          local_1c0 = local_1c0 + status;
        }
        if (((&g_MasterCardSubtypeTable)[local_19c * 0x34] & 0x10) != 0) {
          status = (**(code **)(&g_MasterCardManaCostTable + local_19c * 0x34))(x,local_1a0,0x3a);
          local_1bc = local_1bc + status;
        }
      }
      local_1b0 = 0;
LAB_004ac40d:
      if (local_1b0 < 8) {
        if (local_1c0 <= aiStack_154[local_1b0 * 3 + 1]) goto LAB_004ac407;
        for (local_14 = 7; local_1b0 < local_14; local_14 = local_14 + -1) {
          aiStack_154[local_14 * 3] = aiStack_154[local_14 * 3 + -3];
          aiStack_154[local_14 * 3 + 1] = aiStack_154[local_14 * 3 + -2];
          aiStack_154[local_14 * 3 + 2] = aiStack_154[local_14 * 3 + -1];
        }
        aiStack_154[local_1b0 * 3] = local_1a0;
        aiStack_154[local_1b0 * 3 + 1] = local_1c0;
        aiStack_154[local_1b0 * 3 + 2] = local_1bc;
      }
    }
  }
  local_1a4 = 0;
  local_14 = 0;
  do {
    if ((7 < local_14) || (aiStack_154[local_14 * 3 + 1] == -1)) {
      if (((int)(&g_PlayerCreatureCount)[arg1] <= local_1a4) &&
         (0 < (int)(&g_PlayerCreatureCount)[x])) {
        arg2 = arg2 + -0x100;
      }
      for (local_1a0 = 0; local_1a0 < 8; local_1a0 = local_1a0 + 1) {
        *(int *)(&g_AiCombatScore_Total + local_1a0 * 4 + x * 0x20) = (int)acStack_c[local_1a0];
      }
      return arg2;
    }
    local_1a0 = aiStack_154[local_14 * 3];
    local_198 = FUN_00473179(x,local_1a0,0x34,0xffffffff);
    status = aiStack_154[local_14 * 3 + 1];
    temp_idx = aiStack_154[local_14 * 3 + 2];
    local_1b4 = 0;
    local_1b8 = 0;
    local_f4 = 0;
    local_5c = 0x7fff;
    for (local_1b0 = 0; local_1b0 < (int)(&g_PlayerActiveCardCount)[arg1]; local_1b0 = local_1b0 + 1
        ) {
      if (((*(int *)(&g_CardSlot_CardId + local_1b0 * 0x120 + arg1 * 0x5b20) != -1) &&
          (((&g_CardSlot_Flags)[local_1b0 * 0x120 + arg1 * 0x5b20] & 2) != 0)) &&
         (((&g_MasterCardColorTable)
           [*(int *)(&g_CardSlot_CardId + local_1b0 * 0x120 + arg1 * 0x5b20) * 0x34] & 2) != 0)) {
        local_f4 = (int)acStack_ac[local_1b0];
        local_18 = aiStack_f0[local_f4];
        local_b0 = aiStack_194[local_f4];
        val_result = FUN_004728c3(arg1,local_1b0);
        if (((*(uint *)(&g_CardSlot_Flags + local_1b0 * 0x120 + arg1 * 0x5b20) &
             (-(uint)(val_result == 0) & 4) + 8) == 0) &&
           (val_result = FUN_00472c0c(arg1,local_1b0,x,local_1a0,local_198,local_1a8), val_result != 0)) {
          local_1b8 = 1;
          if ((status < local_b0) || (temp_idx <= local_18)) {
            local_1b8 = 3;
            *(uint *)(&g_CardSlot_Flags + local_1b0 * 0x120 + arg1 * 0x5b20) =
                 *(uint *)(&g_CardSlot_Flags + local_1b0 * 0x120 + arg1 * 0x5b20) | 8;
            break;
          }
          if (aiStack_58[local_f4] < local_5c) {
            local_5c = aiStack_58[local_f4];
            local_1b4 = local_1b0;
          }
        }
      }
    }
    if ((local_1b8 & 2) == 0) {
      temp_idx = *(int *)(&g_PlayerLifeTotals + arg1 * 4) * status * 0x18;
      temp_idx = temp_idx + (temp_idx >> 0x1f & 3U);
      val_result = FUN_0040a305((&g_PlayerCreatureCount)[arg1] + 1,1,99);
      temp_idx = (int)(CONCAT44(temp_idx >> 0x1f,temp_idx >> 2) / (longlong)val_result);
      val_result = (int)(*(int *)(&g_AiPlayerLifeDifferential + arg1 * 4) * local_5c +
                   (*(int *)(&g_AiPlayerLifeDifferential + arg1 * 4) * local_5c >> 0x1f & 0xfU)) >> 4;
      if ((local_1b8 == 0) ||
         ((temp_idx < val_result && (status + local_1a4 < (int)(&g_PlayerCreatureCount)[arg1])))) {
        local_1a4 = local_1a4 + status;
        arg2 = arg2 - temp_idx;
      }
      else {
        arg2 = arg2 - val_result;
        *(uint *)(&g_CardSlot_Flags + local_1b4 * 0x120 + arg1 * 0x5b20) =
             *(uint *)(&g_CardSlot_Flags + local_1b4 * 0x120 + arg1 * 0x5b20) | 8;
      }
    }
    local_14 = local_14 + 1;
  } while( true );
LAB_004ac407:
  local_1b0 = local_1b0 + 1;
  goto LAB_004ac40d;
}

/*
 * Ai_ChooseBlockers
 * Purpose: Assign defending creatures to block attacking creatures.
 * Procedure:
 * 1. Check legal blocker restrictions for each attacking creature.
 * 2. Assign blockers to maximize creature survival and trade value.
 * 3. Record blocking pairs in combat assignment matrix.
 */
/*
 * Decompiled function: Ai_ChooseBlockers
 * Entry Point: 004ac940
 * Size: 575 bytes
 */

int Ai_ChooseBlockers(int player, int attacker_idx)

{
  char *pcVar1;
  int local_14;
  int local_10;
  uint local_c;
  int local_8;
  
  strcpy(&g_OverworldWorldState,&DAT_0052ce58);
  pcVar1 = _itoa(arg2,&DAT_00553190,10);
  strcat(&g_OverworldWorldState,pcVar1);
  strcat(&g_OverworldWorldState,&DAT_0052ce5c);
  pcVar1 = _itoa(g_PlayerCreatureCount,&DAT_00553190,10);
  strcat(&g_OverworldWorldState,pcVar1);
  strcat(&g_OverworldWorldState,&DAT_0052ce60);
  pcVar1 = _itoa(DAT_006a4a04,&DAT_00553190,10);
  strcat(&g_OverworldWorldState,pcVar1);
  strcat(&g_OverworldWorldState,s_____0052ce64);
  local_8 = 0;
  while( true ) {
    if (arg1 == 0) {
      local_10 = g_AiBestScoreTable;
    }
    else {
      local_10 = DAT_00556928;
    }
    if (local_10 <= local_8) break;
    if (arg1 == 0) {
      local_c = *(uint *)(&DAT_0054fc38 + local_8 * 4);
    }
    else {
      local_c = *(uint *)(&DAT_0054f838 + local_8 * 4);
    }
    if (local_c != 0xffffffff) {
      if ((local_c & 0x1000) != 0) {
        strcat(&g_OverworldWorldState,s_Cast_0052ce6c);
      }
      if ((local_c & 0x2000) != 0) {
        strcat(&g_OverworldWorldState,&DAT_0052ce74);
      }
      if ((local_c & 0x4000) != 0) {
        strcat(&g_OverworldWorldState,s____target_0052ce7c);
      }
      if ((local_c & 0x100) == 0) {
        strcat(&g_OverworldWorldState,&DAT_0052ce88);
      }
      if ((char)local_c == -1) {
        strcat(&g_OverworldWorldState,s_Player_0052ce8c);
      }
      else {
        if (arg1 == 0) {
          local_14 = *(int *)(&DAT_00553840 + local_8 * 4);
        }
        else {
          local_14 = *(int *)(&DAT_00553440 + local_8 * 4);
        }
        strcat(&g_OverworldWorldState,s_Swamp_0051aea9 + local_14 * 0x34);
      }
      strcat(&g_OverworldWorldState,&DAT_0052ce94);
    }
    local_8 = local_8 + 1;
  }
  Ai_Deck_SelectStartingHand(0,0,0,-1,-1,&g_OverworldWorldState,0);
  return 0;
}

/*
 * Ai_FilterValidBlockers
 * Purpose: Filter list of potential blockers against specific attacking creature.
 * Procedure:
 * 1. Verify flying, protection, and landwalk evasion restrictions.
 * 2. Return count of legal blocking candidates.
 */
/*
 * Decompiled function: Ai_FilterValidBlockers
 * Entry Point: 004acb7f
 * Size: 155 bytes
 */

void Ai_FilterValidBlockers(uint * arg1, uint * arg2)

{
  int local_10;
  uint local_c;
  uint local_8;
  
  local_c = 0;
  local_8 = 0;
  for (local_10 = 1; local_10 < 6; local_10 = local_10 + 1) {
    if (0 < *(int *)(&DAT_0063ee50 + local_10 * 4)) {
      local_8 = local_8 | 1 << ((char)local_10 - 1U & 0x1f);
    }
    if (0 < *(int *)(&g_AiCombatScore_Attacker + local_10 * 4)) {
      local_c = local_c | 1 << ((char)local_10 - 1U & 0x1f);
    }
  }
  if (arg1 != (uint *)0x0) {
    *arg1 = local_8;
  }
  if (arg2 != (uint *)0x0) {
    *arg2 = local_c;
  }
  return;
}

/*
 * Ai_AssignCombatDamage
 * Purpose: Assign combat damage distribution among blocking and attacking creatures.
 * Procedure:
 * 1. Calculate lethal damage threshold for primary blocker.
 * 2. Assign excess trample damage to defending player.
 * 3. Apply damage points to card slot damage registers.
 */
/*
 * Decompiled function: Ai_AssignCombatDamage
 * Entry Point: 004acc20
 * Size: 538 bytes
 */

int Ai_AssignCombatDamage(int * arg1, uint * arg2, uint arg3, int arg4, uint arg5, uint arg6, int arg7, int arg8, int arg9)

{
  int u_res;
  int val_result;
  uint local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  uint local_10;
  int local_c;
  INT_PTR local_8;
  
  if ((arg1 == (int *)0x0) || (arg2 == (uint *)0x0)) {
    u_res = 0;
  }
  else {
    if (arg4 == 0) {
      local_10 = arg3;
    }
    else {
      val_result = Ai_Subsystem_004b7d38(s_Start_of_duel_0052ce9c);
      local_10 = (uint)(val_result == 0);
    }
    if (DAT_006a2858 == 0) {
      local_c = 1;
    }
    else {
      if (local_10 == 0) {
        FUN_00409b2c(1,1);
        UpdateWindow(DAT_006a49f0);
      }
      local_8 = DialogBoxParamA(g_AppHInstance,(LPCSTR)0xf4,g_MainAppHwnd,Ai_DuelDialogProc,
                                (LPARAM)&local_10);
      FUN_00409b2c(1,0);
    }
    Pic_Subsystem_00452276(1);
    Pic_Subsystem_00452276(0);
    Ai_Turn_ExecuteMainPhase(0,0x30);
    if (((local_10 == 1) && (local_c != 0)) || ((local_10 == 0 && (local_c == 0)))) {
      local_2c = 1;
    }
    else {
      local_2c = 0;
    }
    local_28 = Ai_Subsystem_004cbd67(arg5);
    local_24 = Ai_Subsystem_004cbd67(arg6);
    local_20 = arg7;
    local_1c = arg_8;
    local_18 = arg_9;
    if (arg_8 != 0) {
      DAT_00695e90 = 1;
      Pic_Subsystem_0044cfe4(g_AiDuelTurnState);
    }
    local_8 = DialogBoxParamA(g_AppHInstance,(LPCSTR)0xe3,g_MainAppHwnd,Ai_StartDuelWndProc,
                              (LPARAM)&local_2c);
    local_30 = (uint)(local_8 != 0);
    *arg1 = local_2c;
    *arg2 = local_30;
    DAT_00695e90 = 0;
    Pic_Subsystem_0044cfe4(g_AiDuelTurnState);
    if (local_30 != 0) {
      PostMessageA(g_AiLookaheadTreeRoot,0x40c,0,0);
    }
    UpdateWindow(g_MainAppHwnd);
    u_res = 1;
  }
  return u_res;
}

/*
 * Ai_DuelDialogProc
 * Purpose: Main modal dialog procedure for duel interactive prompts.
 * Procedure:
 * 1. Handle WM_INITDIALOG, WM_COMMAND, and button messages.
 * 2. Dispatch user choices to duel turn state machine.
 */
/*
 * Decompiled function: Ai_DuelDialogProc
 * Entry Point: 004ace3a
 * Size: 2167 bytes
 */

HGDIOBJ Ai_DuelDialogProc(HWND hwnd, uint uMsg, HWND wParam, HWND lParam)

{
  size_t s_res;
  WPARAM wParam_00;
  HGDIOBJ pvVar2;
  HBRUSH hbr;
  HWND pHVar3;
  BOOL BVar4;
  HWND pHVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  tagSIZE *ptVar10;
  UINT UVar11;
  LPARAM lParam_00;
  char local_24c [200];
  int local_184;
  HWND local_180;
  tagRECT local_17c;
  COLORREF local_16c;
  HWND local_168;
  HWND local_164;
  int local_160;
  HWND local_15c;
  HWND local_158;
  HWND local_154;
  uint local_150;
  HDC local_14c;
  int local_148;
  int local_144;
  HGDIOBJ local_140;
  tagSIZE local_13c;
  char local_134 [200];
  char local_6c [100];
  HWND local_8;
  
  if (uMsg < 0x11) {
    if (uMsg == 0x10) {
      pHVar3 = GetDlgItem(hwnd,0x486);
      BVar4 = IsWindowVisible(pHVar3);
      if (BVar4 == 0) {
        KillTimer(hwnd,2);
        EndDialog(hwnd,1);
        return (HGDIOBJ)0x1;
      }
      return (HGDIOBJ)0x1;
    }
    if (uMsg == 2) {
      Ai_StartDuel_InitContext((int)DAT_00556ac8,(int)DAT_005569a4,(int)DAT_00556aac);
      return (HGDIOBJ)0x0;
    }
  }
  else if (uMsg < 0x2c) {
    if (uMsg == 0x2b) {
      local_168 = lParam;
      pHVar3 = GetFocus();
      if (pHVar3 == (HWND)local_168[5].unused) {
        local_16c = DAT_00556998;
      }
      else {
        local_16c = DAT_00556a3c;
      }
      FUN_004f54d5((int)local_168,DAT_005569a4,DAT_00556aac,DAT_005569a4,local_16c,0);
      return (HGDIOBJ)0x1;
    }
    if (uMsg == 0x14) {
      local_180 = wParam;
      FUN_004f3955((HDC)wParam);
      GetClientRect(hwnd,&local_17c);
      if (DAT_00556ac8 == (HANDLE)0x0) {
        hbr = GetStockObject(2);
        FillRect((HDC)local_180,&local_17c,hbr);
      }
      else {
        FUN_004f3b5f((int)local_180,(int)&local_17c,DAT_00556ac8);
      }
      return (HGDIOBJ)0x1;
    }
  }
  else if (uMsg < 0x111) {
    if (uMsg == 0x110) {
      local_8 = lParam;
      SetWindowLongA(hwnd,8,(LONG)lParam);
      Ai_LoadStartDuel2Backdrop
                (&DAT_00556ac8,&DAT_00556abc,&DAT_005569a4,&DAT_00556aac,&DAT_00556a3c,&DAT_00556998
                );
      Ai_Subsystem_004b6f49(local_6c);
      if (local_8->unused == 1) {
        sprintf(local_134,s__s_won_the_toss_0052ceac,local_6c);
        SetDlgItemTextA(hwnd,0x485,local_134);
        iVar9 = 0;
        pHVar3 = GetDlgItem(hwnd,0x488);
        ShowWindow(pHVar3,iVar9);
        iVar9 = 0;
        pHVar3 = GetDlgItem(hwnd,0x486);
        ShowWindow(pHVar3,iVar9);
        iVar9 = 0;
        pHVar3 = GetDlgItem(hwnd,0x487);
        ShowWindow(pHVar3,iVar9);
        SetFocus(hwnd);
        SetTimer(hwnd,1,1000,(TIMERPROC)0x0);
      }
      else {
        sprintf(local_134,s_You_won_the_coin_toss__0052cebc);
        SetDlgItemTextA(hwnd,0x485,local_134);
        sprintf(local_134,s_Would_you_like_to__0052ced4);
        SetDlgItemTextA(hwnd,0x488,local_134);
        pHVar3 = GetDlgItem(hwnd,0x486);
        SetFocus(pHVar3);
        SendMessageA(hwnd,0x401,0x486,0);
      }
      local_14c = GetDC(hwnd);
      FUN_004f3955(local_14c);
      local_140 = (HGDIOBJ)SendDlgItemMessageA(hwnd,0x486,0x31,0,0);
      SelectObject(local_14c,local_140);
      GetDlgItemTextA(hwnd,0x486,local_134,200);
      ptVar10 = &local_13c;
      s_res = strlen(local_134);
      GetTextExtentPoint32A(local_14c,local_134,s_res,ptVar10);
      local_144 = local_13c.cx;
      local_148 = (local_13c.cy * 5) / 2;
      GetDlgItemTextA(hwnd,0x487,local_134,200);
      ptVar10 = &local_13c;
      s_res = strlen(local_134);
      GetTextExtentPoint32A(local_14c,local_134,s_res,ptVar10);
      if (local_13c.cx <= local_144) {
        local_13c.cx = local_144;
      }
      iVar9 = local_13c.cx + local_13c.cy * 2;
      UVar11 = 6;
      iVar7 = 0;
      iVar6 = 0;
      pHVar5 = (HWND)0x0;
      iVar8 = local_148;
      local_144 = iVar9;
      pHVar3 = GetDlgItem(hwnd,0x486);
      SetWindowPos(pHVar3,pHVar5,iVar6,iVar7,iVar9,iVar8,UVar11);
      UVar11 = 6;
      iVar7 = 0;
      iVar6 = 0;
      pHVar5 = (HWND)0x0;
      iVar9 = local_144;
      iVar8 = local_148;
      pHVar3 = GetDlgItem(hwnd,0x487);
      SetWindowPos(pHVar3,pHVar5,iVar6,iVar7,iVar9,iVar8,UVar11);
      ReleaseDC(hwnd,local_14c);
      FUN_004f570c(hwnd);
      return (HGDIOBJ)0x0;
    }
    if (uMsg == 0x102) {
LAB_004ad556:
      pHVar3 = GetDlgItem(hwnd,0x486);
      BVar4 = IsWindowVisible(pHVar3);
      if (BVar4 == 0) {
        KillTimer(hwnd,2);
        EndDialog(hwnd,1);
        return (HGDIOBJ)0x1;
      }
      return (HGDIOBJ)0x0;
    }
  }
  else if (uMsg < 0x139) {
    if (uMsg == 0x138) {
      local_15c = wParam;
      FUN_004f3955((HDC)wParam);
      local_164 = lParam;
      local_160 = GetDlgCtrlID(lParam);
      SetBkMode((HDC)local_15c,1);
      SetTextColor((HDC)local_15c,DAT_00556abc);
      pvVar2 = GetStockObject(5);
      return pvVar2;
    }
    if (uMsg == 0x111) {
      local_150 = (uint)wParam & 0xffff;
      if ((0x485 < local_150) && (local_150 < 0x488)) {
        local_8 = (HWND)GetWindowLongA(hwnd,8);
        if (local_150 == 0x486) {
          *(int *)((int)local_8 + 4) = 1;
        }
        else {
          *(int *)((int)local_8 + 4) = 0;
        }
        EndDialog(hwnd,1);
      }
      return (HGDIOBJ)0x1;
    }
    if (uMsg == 0x113) {
      if (wParam == (HWND)0x1) {
        KillTimer(hwnd,1);
        local_184 = FUN_0040a1d2(2);
        local_8 = (HWND)GetWindowLongA(hwnd,8);
        *(int *)((int)local_8 + 4) = local_184;
        if (local_184 == 0) {
          sprintf(local_24c,s_and_has_chosen_to_draw_first__0052cf00);
        }
        else {
          sprintf(local_24c,s_and_will_play_first__0052cee8);
        }
        SetDlgItemTextA(hwnd,0x488,local_24c);
        iVar9 = 5;
        pHVar3 = GetDlgItem(hwnd,0x488);
        ShowWindow(pHVar3,iVar9);
        SetTimer(hwnd,2,3000,(TIMERPROC)0x0);
      }
      else if (wParam == (HWND)0x2) {
        KillTimer(hwnd,2);
        EndDialog(hwnd,1);
      }
      return (HGDIOBJ)0x0;
    }
  }
  else if (uMsg < 0x205) {
    if ((uMsg == 0x204) || (uMsg == 0x201)) goto LAB_004ad556;
  }
  else if (0x30e < uMsg) {
    if (uMsg < 0x312) {
      pvVar2 = (HGDIOBJ)FUN_004f5d1a(hwnd,uMsg,wParam,lParam);
      return pvVar2;
    }
    if (uMsg == 0x4c8) {
      local_154 = wParam;
      local_158 = lParam;
      if (wParam != (HWND)0x0) {
        lParam_00 = 0;
        wParam_00 = GetDlgCtrlID(wParam);
        SendMessageA(hwnd,0x401,wParam_00,lParam_00);
      }
      if (local_154 != (HWND)0x0) {
        InvalidateRect(local_154,(RECT *)0x0,1);
      }
      if (local_158 != (HWND)0x0) {
        InvalidateRect(local_158,(RECT *)0x0,1);
      }
      return (HGDIOBJ)0x0;
    }
  }
  return (HGDIOBJ)0x0;
}

/*
 * Ai_LoadStartDuel2Backdrop
 * Purpose: Load secondary duel startup backdrop art.
 * Procedure:
 * 1. Load WINBK_StartDuel2.pic into memory.
 * 2. Decompress 8-bit bitmap to display surface buffer.
 */
/*
 * Decompiled function: Ai_LoadStartDuel2Backdrop
 * Entry Point: 004ad6c5
 * Size: 182 bytes
 */

void Ai_LoadStartDuel2Backdrop(int * arg1, int * out_buffer, int * arg3, int * arg4, int * arg5, int * arg6)

{
  int u_res;
  char local_10c [264];
  
  sprintf(local_10c,s__s_WINBK_StartDuel2_pic_0052cf20,&g_AiCurrentChoiceIndex);
  u_res = Pic_Load_00423833(local_10c);
  *arg1 = u_res;
  *out_buffer = 0;
  sprintf(local_10c,s__s_WINBK_StartDuelButtonNormal_p_0052cf38,&g_AiCurrentChoiceIndex);
  u_res = Pic_Load_00423833(local_10c);
  *arg3 = u_res;
  sprintf(local_10c,s__s_WINBK_StartDuelButtonDepresse_0052cf5c,&g_AiCurrentChoiceIndex);
  u_res = Pic_Load_00423833(local_10c);
  *arg4 = u_res;
  *arg5 = 0x1000001;
  *arg6 = 0x10000bf;
  return;
}

/*
 * Ai_StartDuel_InitContext
 * Purpose: Initialize tactical duel session context.
 * Procedure:
 * 1. Allocate lookahead memory buffers.
 * 2. Reset turn counters and player life totals.
 */
/*
 * Decompiled function: Ai_StartDuel_InitContext
 * Entry Point: 004ad77b
 * Size: 77 bytes
 */

void Ai_StartDuel_InitContext(int arg1, int arg2, int arg3)

{
  if (arg1 != 0) {
    FUN_004f4548((HANDLE)arg1);
  }
  if (arg2 != 0) {
    FUN_004f4548((HANDLE)arg2);
  }
  if (arg3 != 0) {
    FUN_004f4548((HANDLE)arg3);
  }
  return;
}

/*
 * Ai_StartDuelWndProc
 * Purpose: Window procedure for startup duel initialization window.
 * Procedure:
 * 1. Process WM_CREATE, WM_PAINT, and start duel trigger messages.
 */
/*
 * Decompiled function: Ai_StartDuelWndProc
 * Entry Point: 004ad7c8
 * Size: 3680 bytes
 */

HGDIOBJ Ai_StartDuelWndProc(HWND hwnd, uint uMsg, HWND wParam, HWND lParam)

{
  POINT pt;
  POINT pt_00;
  size_t s_res;
  int val_result;
  int temp_idx;
  WPARAM wParam_00;
  HGDIOBJ pvVar4;
  BOOL BVar5;
  HBRUSH hbr;
  HWND pHVar6;
  HDC hdc;
  LONG Y;
  int iVar7;
  tagSIZE *ptVar8;
  LPARAM lParam_00;
  tagRECT *ptVar9;
  tagPAINTSTRUCT local_280;
  tagRECT local_240;
  uint local_230;
  uint local_22c;
  tagRECT local_228;
  tagRECT local_218;
  HWND local_208;
  tagRECT local_204;
  int local_1f4;
  COLORREF local_1f0;
  HWND local_1ec;
  HWND local_1e8;
  int local_1e4;
  HWND local_1e0;
  HWND local_1dc;
  HWND local_1d8;
  char local_1d4 [100];
  uint local_170;
  tagRECT local_16c;
  HDC local_15c;
  int local_158;
  int local_154;
  HGDIOBJ local_150;
  tagRECT local_14c;
  tagSIZE local_13c;
  char local_134 [200];
  char local_6c [100];
  HWND local_8;
  
  if (uMsg < 0x15) {
    if (uMsg == 0x14) {
      local_208 = wParam;
      FUN_004f3955((HDC)wParam);
      GetClientRect(hwnd,&local_204);
      if (DAT_00556a6c == (HANDLE)0x0) {
        hbr = GetStockObject(2);
        FillRect((HDC)local_208,&local_204,hbr);
      }
      else {
        FUN_004f3b5f((int)local_208,(int)&local_204,DAT_00556a6c);
      }
      return (HGDIOBJ)0x1;
    }
    if (uMsg == 0xf) {
      pHVar6 = GetDlgItem(hwnd,0x413);
      UpdateWindow(pHVar6);
      pHVar6 = GetDlgItem(hwnd,0x418);
      UpdateWindow(pHVar6);
      pHVar6 = GetDlgItem(hwnd,0x417);
      UpdateWindow(pHVar6);
      local_8 = (HWND)GetWindowLongA(hwnd,8);
      hdc = BeginPaint(hwnd,&local_280);
      if (hdc != (HDC)0x0) {
        FUN_004f3955(hdc);
        if (*(int *)((int)local_8 + 8) != -1) {
          ptVar9 = &local_240;
          pHVar6 = GetDlgItem(hwnd,0x470);
          GetWindowRect(pHVar6,ptVar9);
          MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_240,2);
          Palette_Subsystem_0049c7c7
                    (hdc,&local_240.left,
                     (WPARAM *)(&g_AiDecisionMatrix_Col + *(int *)((int)local_8 + 8) * 0x98),0,2,0);
        }
        if (*(int *)((int)local_8 + 4) != -1) {
          ptVar9 = &local_240;
          pHVar6 = GetDlgItem(hwnd,0x46f);
          GetWindowRect(pHVar6,ptVar9);
          MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_240,2);
          Palette_Subsystem_0049c7c7
                    (hdc,&local_240.left,
                     (WPARAM *)(&g_AiDecisionMatrix_Col + *(int *)((int)local_8 + 4) * 0x98),0,2,0);
        }
        EndPaint(hwnd,&local_280);
      }
      return (HGDIOBJ)0x1;
    }
  }
  else if (uMsg < 0x111) {
    if (uMsg == 0x110) {
      BringWindowToTop(g_AiLookaheadTreeRoot);
      local_8 = lParam;
      SetWindowLongA(hwnd,8,(LONG)lParam);
      iVar7 = 0;
      pHVar6 = GetDlgItem(hwnd,0x46f);
      ShowWindow(pHVar6,iVar7);
      iVar7 = 0;
      pHVar6 = GetDlgItem(hwnd,0x470);
      ShowWindow(pHVar6,iVar7);
      DAT_00556a68 = 0;
      Ai_LoadStartDuelBackdrop
                (&DAT_00556a6c,&DAT_00556ad8,&DAT_00556a94,&DAT_0055694c,&DAT_00556940,&DAT_00556a64
                 ,&DAT_00556a4c);
      Ai_Subsystem_004b6f49(local_6c);
      if (local_8->unused == 1) {
        sprintf(local_134,s__s_will_start_first_0052cf84,local_6c);
        SetDlgItemTextA(hwnd,0x413,local_134);
      }
      else {
        SetDlgItemTextA(hwnd,0x413,s_You_will_take_the_first_turn_0052cf98);
      }
      sprintf(local_134,s__s_ante__0052cfb8,local_6c);
      SetDlgItemTextA(hwnd,0x417,local_134);
      strcpy(local_134,s_Your_ante__0052cfc4);
      SetDlgItemTextA(hwnd,0x418,local_134);
      if (local_8[4].unused == 0) {
        sprintf(local_134,s__s_did_not_take_a_mulligan_0052d04c,local_6c);
        SetDlgItemTextA(hwnd,0x414,local_134);
      }
      else {
        if (local_8[4].unused == 1) {
          sprintf(local_134,s__s_has_no_land_and_chose_to_take_0052cfd0,local_6c);
        }
        else if (local_8[4].unused == 2) {
          sprintf(local_134,s__s_has_all_land_and_will_take_a_m_0052cffc,local_6c);
        }
        else {
          sprintf(local_134,s__s_has_chosen_to_take_a_mulligan_0052d028,local_6c);
        }
        SetDlgItemTextA(hwnd,0x414,local_134);
      }
      if (local_8[4].unused == 0) {
        if (local_8[3].unused == 0) {
          iVar7 = 0;
          pHVar6 = GetDlgItem(hwnd,0x415);
          ShowWindow(pHVar6,iVar7);
          pHVar6 = GetDlgItem(hwnd,1);
          SetFocus(pHVar6);
          SendMessageA(hwnd,0x401,1,0);
        }
        else {
          iVar7 = 5;
          pHVar6 = GetDlgItem(hwnd,0x415);
          ShowWindow(pHVar6,iVar7);
          pHVar6 = GetDlgItem(hwnd,0x415);
          SetFocus(pHVar6);
          SendMessageA(hwnd,0x401,0x415,0);
        }
      }
      else {
        iVar7 = 5;
        pHVar6 = GetDlgItem(hwnd,0x415);
        ShowWindow(pHVar6,iVar7);
        pHVar6 = GetDlgItem(hwnd,0x415);
        SetFocus(pHVar6);
        SendMessageA(hwnd,0x401,0x415,0);
      }
      iVar7 = 0;
      pHVar6 = GetDlgItem(hwnd,0x416);
      ShowWindow(pHVar6,iVar7);
      local_8[6].unused = 0;
      local_15c = GetDC(hwnd);
      FUN_004f3955(local_15c);
      local_150 = (HGDIOBJ)SendDlgItemMessageA(hwnd,0x415,0x31,0,0);
      SelectObject(local_15c,local_150);
      ptVar9 = &local_14c;
      pHVar6 = GetDlgItem(hwnd,0x415);
      GetWindowRect(pHVar6,ptVar9);
      MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_14c,2);
      GetDlgItemTextA(hwnd,0x415,local_134,200);
      ptVar8 = &local_13c;
      s_res = strlen(local_134);
      GetTextExtentPoint32A(local_15c,local_134,s_res,ptVar8);
      val_result = local_13c.cy * 2 + local_13c.cx;
      temp_idx = (local_13c.cy * 5) / 2;
      iVar7 = local_14c.left + ((local_14c.right - local_14c.left) / 2 - val_result / 2);
      BVar5 = 1;
      Y = local_14c.top;
      local_158 = temp_idx;
      local_154 = val_result;
      local_14c.left = iVar7;
      pHVar6 = GetDlgItem(hwnd,0x415);
      MoveWindow(pHVar6,iVar7,Y,val_result,temp_idx,BVar5);
      ptVar9 = &local_14c;
      pHVar6 = GetDlgItem(hwnd,1);
      GetWindowRect(pHVar6,ptVar9);
      MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_14c,2);
      GetDlgItemTextA(hwnd,1,local_134,200);
      ptVar8 = &local_13c;
      s_res = strlen(local_134);
      GetTextExtentPoint32A(local_15c,local_134,s_res,ptVar8);
      val_result = local_13c.cy * 2 + local_13c.cx;
      temp_idx = (local_13c.cy * 5) / 2;
      iVar7 = local_14c.left + ((local_14c.right - local_14c.left) / 2 - val_result / 2);
      BVar5 = 1;
      local_158 = temp_idx;
      local_154 = val_result;
      local_14c.left = iVar7;
      pHVar6 = GetDlgItem(hwnd,1);
      MoveWindow(pHVar6,iVar7,local_14c.top,val_result,temp_idx,BVar5);
      if (local_8[1].unused == -1) {
        iVar7 = 0;
        pHVar6 = GetDlgItem(hwnd,0x46f);
        ShowWindow(pHVar6,iVar7);
        iVar7 = 0;
        pHVar6 = GetDlgItem(hwnd,0x417);
        ShowWindow(pHVar6,iVar7);
      }
      if (local_8[2].unused == -1) {
        iVar7 = 0;
        pHVar6 = GetDlgItem(hwnd,0x470);
        ShowWindow(pHVar6,iVar7);
        iVar7 = 0;
        pHVar6 = GetDlgItem(hwnd,0x418);
        ShowWindow(pHVar6,iVar7);
      }
      ReleaseDC(hwnd,local_15c);
      FUN_004f570c(hwnd);
      if ((local_8[4].unused != 0) || (local_8[3].unused != 0)) {
        GetWindowRect(hwnd,&local_16c);
        SetWindowPos(hwnd,(HWND)0x0,5,local_16c.top,0,0,5);
      }
      return (HGDIOBJ)0x0;
    }
    if (uMsg == 0x2b) {
      local_1ec = lParam;
      pHVar6 = GetFocus();
      if (pHVar6 == (HWND)local_1ec[5].unused) {
        local_1f0 = DAT_00556a4c;
      }
      else {
        local_1f0 = DAT_00556a64;
      }
      local_1f4 = 0;
      pHVar6 = GetDlgItem(hwnd,0x415);
      BVar5 = IsWindowVisible(pHVar6);
      if (BVar5 == 0) {
        local_1f0 = DAT_00556a64;
        local_1f4 = 1;
      }
      FUN_004f54d5((int)local_1ec,DAT_00556a94,DAT_0055694c,DAT_00556940,local_1f0,local_1f4);
      return (HGDIOBJ)0x1;
    }
  }
  else if (uMsg < 0x139) {
    if (uMsg == 0x138) {
      local_1e0 = wParam;
      FUN_004f3955((HDC)wParam);
      local_1e8 = lParam;
      local_1e4 = GetDlgCtrlID(lParam);
      SetBkMode((HDC)local_1e0,1);
      SetTextColor((HDC)local_1e0,DAT_00556ad8);
      pvVar4 = GetStockObject(5);
      return pvVar4;
    }
    if (uMsg == 0x111) {
      local_170 = (uint)wParam & 0xffff;
      if (local_170 != 0) {
        if (local_170 < 3) {
          local_8 = (HWND)GetWindowLongA(hwnd,8);
          Ai_Duel_ResetBuffers
                    ((int)DAT_00556a6c,(int)DAT_00556a94,(int)DAT_0055694c,(int)DAT_00556940);
          EndDialog(hwnd,*(INT_PTR *)((int)local_8 + 0x18));
        }
        else if (local_170 == 0x415) {
          local_8 = (HWND)GetWindowLongA(hwnd,8);
          *(int *)((int)local_8 + 0x18) = 1;
          BVar5 = 0;
          pHVar6 = GetDlgItem(hwnd,0x415);
          EnableWindow(pHVar6,BVar5);
          iVar7 = 0;
          pHVar6 = GetDlgItem(hwnd,1);
          ShowWindow(pHVar6,iVar7);
          if (*(int *)((int)local_8 + 0x10) == 0) {
            Sleep(500);
            Ai_Subsystem_004b6f49(local_1d4);
            if (*(int *)((int)local_8 + 0x14) == 0) {
              strcat(local_1d4,s_decided_not_to_take_a_mulligan_0052d084);
            }
            else {
              strcat(local_1d4,s_will_also_take_a_mulligan_0052d068);
            }
            SetDlgItemTextA(hwnd,0x416,local_1d4);
            iVar7 = 5;
            pHVar6 = GetDlgItem(hwnd,0x416);
            ShowWindow(pHVar6,iVar7);
            if (*(int *)((int)local_8 + 0x14) != 0) {
              SendMessageA(g_AiDuelTurnState,0x40c,0,0);
            }
          }
          SetTimer(hwnd,1,2000,(TIMERPROC)0x0);
        }
      }
      return (HGDIOBJ)0x1;
    }
    if (uMsg == 0x113) {
      Ai_Duel_ResetBuffers((int)DAT_00556a6c,(int)DAT_00556a94,(int)DAT_0055694c,(int)DAT_00556940)
      ;
      EndDialog(hwnd,1);
      return (HGDIOBJ)0x1;
    }
  }
  else {
    if (uMsg < 0x312) {
      if (0x30e < uMsg) {
        pvVar4 = (HGDIOBJ)FUN_004f5d1a(hwnd,uMsg,wParam,lParam);
        return pvVar4;
      }
      if (uMsg != 0x200) {
        if (uMsg == 0x201) {
          SendMessageA(hwnd,0x112,0xf012,0);
          return (HGDIOBJ)0x1;
        }
        if (uMsg != 0x204) {
          return (HGDIOBJ)0x0;
        }
      }
      local_230 = (uint)lParam & 0xffff;
      local_22c = (uint)lParam >> 0x10;
      local_8 = (HWND)GetWindowLongA(hwnd,8);
      if (((uMsg == 0x200) && (g_DuelArenaStatusFlags != 2)) || ((uMsg == 0x204 && (g_DuelArenaStatusFlags == 2)))) {
        ptVar9 = &local_218;
        pHVar6 = GetDlgItem(hwnd,0x46f);
        GetWindowRect(pHVar6,ptVar9);
        MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_218,2);
        ptVar9 = &local_228;
        pHVar6 = GetDlgItem(hwnd,0x470);
        GetWindowRect(pHVar6,ptVar9);
        MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_228,2);
        if ((*(int *)((int)local_8 + 4) == -1) ||
           (pt.y = local_22c, pt.x = local_230, BVar5 = PtInRect(&local_218,pt), BVar5 == 0)) {
          if ((*(int *)((int)local_8 + 8) != -1) &&
             (pt_00.y = local_22c, pt_00.x = local_230, BVar5 = PtInRect(&local_228,pt_00),
             BVar5 != 0)) {
            SendMessageA(g_MainAppWindow,0x401,*(WPARAM *)((int)local_8 + 8),0);
          }
        }
        else {
          SendMessageA(g_MainAppWindow,0x401,*(WPARAM *)((int)local_8 + 4),0);
        }
      }
      return (HGDIOBJ)0x0;
    }
    if (uMsg == 0x4c8) {
      local_1d8 = wParam;
      local_1dc = lParam;
      if (wParam != (HWND)0x0) {
        lParam_00 = 0;
        wParam_00 = GetDlgCtrlID(wParam);
        SendMessageA(hwnd,0x401,wParam_00,lParam_00);
      }
      if (local_1d8 != (HWND)0x0) {
        InvalidateRect(local_1d8,(RECT *)0x0,1);
      }
      if (local_1dc != (HWND)0x0) {
        InvalidateRect(local_1dc,(RECT *)0x0,1);
      }
      return (HGDIOBJ)0x0;
    }
  }
  return (HGDIOBJ)0x0;
}

/*
 * Ai_LoadStartDuelBackdrop
 * Purpose: Load primary duel introduction backdrop art.
 * Procedure:
 * 1. Load WINBK_StartDuel.pic into memory.
 * 2. Paint introduction art to screen DC.
 */
/*
 * Decompiled function: Ai_LoadStartDuelBackdrop
 * Entry Point: 004ae632
 * Size: 228 bytes
 */

void Ai_LoadStartDuelBackdrop(int * arg1, int * out_buffer, int * arg3, int * arg4, int * arg5, int * arg6, int * arg7)

{
  int u_res;
  char local_10c [264];
  
  sprintf(local_10c,s__s_WINBK_StartDuel_pic_0052d0a4,&g_AiCurrentChoiceIndex);
  u_res = Pic_Load_00423833(local_10c);
  *arg1 = u_res;
  *out_buffer = 0;
  sprintf(local_10c,s__s_WINBK_StartDuelButtonNormal_p_0052d0bc,&g_AiCurrentChoiceIndex);
  u_res = Pic_Load_00423833(local_10c);
  *arg3 = u_res;
  sprintf(local_10c,s__s_WINBK_StartDuelButtonDepresse_0052d0e0,&g_AiCurrentChoiceIndex);
  u_res = Pic_Load_00423833(local_10c);
  *arg4 = u_res;
  sprintf(local_10c,s__s_WINBK_StartDuelButtonDisabled_0052d108,&g_AiCurrentChoiceIndex);
  u_res = Pic_Load_00423833(local_10c);
  *arg5 = u_res;
  *arg6 = 0x1000001;
  *arg7 = 0x10000bf;
  return;
}

/*
 * Ai_Duel_ResetBuffers
 * Purpose: Reset duel display buffers and surface handles.
 * Procedure:
 * 1. Release active surface memory buffers.
 */
/*
 * Decompiled function: Ai_Duel_ResetBuffers
 * Entry Point: 004ae716
 * Size: 99 bytes
 */

void Ai_Duel_ResetBuffers(int x, int y, int width, int height)

{
  if (x != 0) {
    FUN_004f4548((HANDLE)x);
  }
  if (y != 0) {
    FUN_004f4548((HANDLE)y);
  }
  if (width != 0) {
    FUN_004f4548((HANDLE)width);
  }
  if (height != 0) {
    FUN_004f4548((HANDLE)height);
  }
  return;
}

/*
 * Ai_Duel_SetupSurfaces
 * Purpose: Initialize duel rendering surfaces and clipping rects.
 * Procedure:
 * 1. Setup backbuffer DC and viewport rectangles.
 */
/*
 * Decompiled function: Ai_Duel_SetupSurfaces
 * Entry Point: 004ae779
 * Size: 298 bytes
 */

void Ai_Duel_SetupSurfaces(int arg1)

{
  int status;
  char local_918 [300];
  int local_7ec;
  int local_7e8;
  int local_7e4;
  int local_7e0 [500];
  int local_10;
  int local_c;
  
  KillTimer(g_MainAppHwnd,DAT_006fdbd4);
  status = Ai_Subsystem_004b72d0(local_7e0,0);
  if (status == 0) {
    local_c = 0xffffffff;
  }
  else {
    local_c = local_7e0[0];
  }
  status = Ai_Subsystem_004b72d0(local_7e0,1);
  if (status == 0) {
    local_10 = 0xffffffff;
  }
  else {
    local_10 = local_7e0[0];
  }
  if (arg1 == 0) {
    Ai_Subsystem_004b6f49(local_918);
    strcat(local_918,&DAT_0052d130);
  }
  else if (arg1 == 1) {
    strcpy(local_918,s_You_won__0052d138);
  }
  else {
    strcpy(local_918,s_The_duel_is_a_draw_0052d144);
  }
  local_7ec = 0;
  local_7e8 = local_c;
  local_7e4 = local_10;
  DialogBoxParamA(g_AppHInstance,(LPCSTR)0xf6,g_MainAppHwnd,Ai_DuelMainWndProc,(LPARAM)local_918);
  return;
}

/*
 * Ai_Duel_RenderBackdrop
 * Purpose: Render active duel backdrop to backbuffer DC.
 * Procedure:
 * 1. Blit cached background art to screen DC.
 */
/*
 * Decompiled function: Ai_Duel_RenderBackdrop
 * Entry Point: 004ae8a3
 * Size: 242 bytes
 */

INT_PTR Ai_Duel_RenderBackdrop(int arg1, int arg2, int arg3, int arg4, int arg5)

{
  int status;
  INT_PTR IVar2;
  char local_918 [300];
  int local_7ec;
  int local_7e8;
  int local_7e4;
  int local_7e0 [500];
  int local_10;
  int local_c;
  
  KillTimer(g_MainAppHwnd,DAT_006fdbd4);
  status = Ai_Subsystem_004b72d0(local_7e0,0);
  if (status == 0) {
    local_c = 0xffffffff;
  }
  else {
    local_c = local_7e0[0];
  }
  status = Ai_Subsystem_004b72d0(local_7e0,1);
  if (status == 0) {
    local_10 = 0xffffffff;
  }
  else {
    local_10 = local_7e0[0];
  }
  sprintf(local_918,s__s_That_was_round__d_Your_record_0052d158,arg1,arg2,arg3,arg4,arg5);
  local_7ec = 1;
  local_7e8 = local_c;
  local_7e4 = local_10;
  IVar2 = DialogBoxParamA(g_AppHInstance,(LPCSTR)0xf6,g_MainAppHwnd,Ai_DuelMainWndProc,
                          (LPARAM)local_918);
  return IVar2;
}

/*
 * Ai_DuelMainWndProc
 * Purpose: Master window procedure for tactical AI duel arena.
 * Procedure:
 * 1. Handle WM_PAINT, WM_TIMER, mouse clicks, and combat UI events.
 */
/*
 * Decompiled function: Ai_DuelMainWndProc
 * Entry Point: 004ae995
 * Size: 2915 bytes
 */

HGDIOBJ Ai_DuelMainWndProc(HWND hwnd, uint uMsg, HDC wParam, HWND lParam)

{
  POINT pt;
  POINT pt_00;
  HGDIOBJ pvVar1;
  HBRUSH hbr;
  int val_result;
  BOOL BVar3;
  HWND pHVar4;
  HDC hdc;
  int iVar5;
  tagRECT *ptVar6;
  tagPAINTSTRUCT local_1b4;
  int local_174;
  tagRECT local_170;
  int local_160;
  int local_15c;
  WPARAM local_158;
  uint local_154;
  uint local_150;
  tagRECT local_14c;
  tagRECT local_13c;
  WPARAM local_12c;
  tagRECT local_128;
  tagRECT local_118;
  HDC local_108;
  tagRECT local_104;
  COLORREF local_f4;
  HWND local_f0;
  HWND local_ec;
  int local_e8;
  HDC local_e4;
  HWND local_dc;
  HDC local_d8;
  WPARAM local_d4;
  char local_d0 [200];
  HWND local_8;
  
  if (uMsg < 0x15) {
    if (uMsg == 0x14) {
      local_108 = wParam;
      FUN_004f3955(wParam);
      GetClientRect(hwnd,&local_104);
      if (g_AiHeuristicWeight_Flyers == (HANDLE)0x0) {
        hbr = GetStockObject(2);
        FillRect(local_108,&local_104,hbr);
      }
      else {
        FUN_004f3b5f((int)local_108,(int)&local_104,g_AiHeuristicWeight_Flyers);
      }
      return (HGDIOBJ)0x1;
    }
    if (uMsg == 0xf) {
      local_8 = (HWND)GetWindowLongA(hwnd,8);
      pHVar4 = GetDlgItem(hwnd,0x48f);
      UpdateWindow(pHVar4);
      Ai_Subsystem_004b74b1(&local_160,(int *)0x0);
      if (local_160 == 0) {
        pHVar4 = GetDlgItem(hwnd,0x48d);
        UpdateWindow(pHVar4);
      }
      else {
        pHVar4 = GetDlgItem(hwnd,0x48e);
        UpdateWindow(pHVar4);
      }
      hdc = BeginPaint(hwnd,&local_1b4);
      if (hdc != (HDC)0x0) {
        FUN_004f3955(hdc);
        if (local_160 == 0) {
          local_15c = *(int *)((int)local_8 + 0x130);
          local_174 = 0x491;
        }
        else {
          local_15c = *(int *)((int)local_8 + 0x134);
          local_174 = 0x490;
        }
        if (local_15c != -1) {
          ptVar6 = &local_170;
          pHVar4 = GetDlgItem(hwnd,local_174);
          GetWindowRect(pHVar4,ptVar6);
          MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_170,2);
          Palette_Subsystem_0049c7c7
                    (hdc,&local_170.left,(WPARAM *)(&g_AiDecisionMatrix_Col + local_15c * 0x98),0,0x12,0);
        }
        if (local_160 == 0) {
          local_15c = *(int *)((int)local_8 + 0x134);
          local_174 = 0x490;
        }
        else {
          local_15c = *(int *)((int)local_8 + 0x130);
          local_174 = 0x491;
        }
        if (local_15c != -1) {
          ptVar6 = &local_170;
          pHVar4 = GetDlgItem(hwnd,local_174);
          GetWindowRect(pHVar4,ptVar6);
          MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_170,2);
          Palette_Subsystem_0049c7c7
                    (hdc,&local_170.left,(WPARAM *)(&g_AiDecisionMatrix_Col + local_15c * 0x98),0,0x12,0);
        }
        EndPaint(hwnd,&local_1b4);
      }
      return (HGDIOBJ)0x1;
    }
  }
  else if (uMsg < 0x103) {
    if (uMsg == 0x102) {
      local_8 = (HWND)GetWindowLongA(hwnd,8);
      if ((*(int *)((int)local_8 + 300) == 0) &&
         (((wParam == (HDC)0xd || (wParam == (HDC)0x20)) || (wParam == (HDC)0x1b)))) {
        Ai_EndDuel_ShowResult((int)g_AiHeuristicWeight_Flyers,DAT_005569d4,DAT_00556964,DAT_00556a80);
        EndDialog(hwnd,1);
      }
      return (HGDIOBJ)0x1;
    }
    if (uMsg == 0x2b) {
      local_f0 = lParam;
      pHVar4 = GetFocus();
      if (pHVar4 == (HWND)local_f0[5].unused) {
        local_f4 = DAT_005569ac;
      }
      else {
        local_f4 = DAT_0055693c;
      }
      if (DAT_006808c0 == 0) {
        local_f4 = DAT_0055693c;
      }
      FUN_004f5107((int)local_f0,DAT_005569d4,DAT_00556964,DAT_00556a80,local_f4,0);
      return (HGDIOBJ)0x1;
    }
  }
  else if (uMsg < 0x136) {
    if (uMsg == 0x135) {
LAB_004aecb5:
      local_e4 = wParam;
      FUN_004f3955(wParam);
      local_ec = lParam;
      local_e8 = GetDlgCtrlID(lParam);
      if ((local_e8 != 0x493) && (local_e8 != 0x494)) {
        SetTextColor(local_e4,DAT_005569a8);
        SetBkMode(local_e4,1);
        pvVar1 = GetStockObject(5);
        return pvVar1;
      }
      pHVar4 = GetFocus();
      if (pHVar4 == local_ec) {
        SetTextColor(local_e4,DAT_005569ac);
      }
      else {
        SetTextColor(local_e4,DAT_00556944);
      }
      SetBkMode(local_e4,1);
      pvVar1 = GetStockObject(5);
      return pvVar1;
    }
    if (uMsg == 0x110) {
      local_8 = lParam;
      SetWindowLongA(hwnd,8,(LONG)lParam);
      Ai_LoadEndDuelBackdrop
                (&g_AiHeuristicWeight_Flyers,&DAT_005569a8,&DAT_00556944,(int *)&DAT_005569d4,(int *)&DAT_00556964
                 ,(int *)&DAT_00556a80,&DAT_0055693c,&DAT_005569ac);
      iVar5 = 0;
      pHVar4 = GetDlgItem(hwnd,0x490);
      ShowWindow(pHVar4,iVar5);
      iVar5 = 0;
      pHVar4 = GetDlgItem(hwnd,0x491);
      ShowWindow(pHVar4,iVar5);
      Ai_Subsystem_004b6f49(local_d0);
      strcat(local_d0,s_next_draw__0052d188);
      SetDlgItemTextA(hwnd,0x48e,local_d0);
      strcpy(local_d0,s_Your_next_draw__0052d194);
      SetDlgItemTextA(hwnd,0x48d,local_d0);
      SetDlgItemTextA(hwnd,0x48f,(LPCSTR)local_8);
      if (local_8[0x4b].unused == 0) {
        iVar5 = 0;
        pHVar4 = GetDlgItem(hwnd,0x493);
        ShowWindow(pHVar4,iVar5);
        iVar5 = 0;
        pHVar4 = GetDlgItem(hwnd,0x494);
        ShowWindow(pHVar4,iVar5);
      }
      else {
        if (DAT_006808c0 == 0) {
          iVar5 = 0;
          pHVar4 = GetDlgItem(hwnd,0x493);
          ShowWindow(pHVar4,iVar5);
          SetDlgItemTextA(hwnd,0x494,&DAT_0052d1c0);
          local_d4 = 0x494;
        }
        else {
          local_d4 = 0x493;
          SetDlgItemTextA(hwnd,0x493,s_Next_Round_0052d1a4);
          SetDlgItemTextA(hwnd,0x494,s_Quit_Gauntlet_0052d1b0);
        }
        pHVar4 = GetDlgItem(hwnd,local_d4);
        SetFocus(pHVar4);
        SendMessageA(hwnd,0x401,local_d4,0);
        FUN_004f570c(hwnd);
      }
      return (HGDIOBJ)0x0;
    }
    if (uMsg == 0x111) {
      if (((uint)wParam & 0xffff) == 0x493) {
        Ai_EndDuel_ShowResult((int)g_AiHeuristicWeight_Flyers,DAT_005569d4,DAT_00556964,DAT_00556a80);
        EndDialog(hwnd,4);
      }
      else if ((((uint)wParam & 0xffff) == 0x494) || (((uint)wParam & 0xffff) == 2)) {
        Ai_EndDuel_ShowResult((int)g_AiHeuristicWeight_Flyers,DAT_005569d4,DAT_00556964,DAT_00556a80);
        EndDialog(hwnd,0);
      }
      return (HGDIOBJ)0x1;
    }
  }
  else if (uMsg < 0x201) {
    if (uMsg == 0x200) {
LAB_004aefff:
      local_154 = (uint)lParam & 0xffff;
      local_150 = (uint)lParam >> 0x10;
      local_8 = (HWND)GetWindowLongA(hwnd,8);
      if (((uMsg == 0x200) && (g_DuelArenaStatusFlags != 2)) || ((uMsg == 0x204 && (g_DuelArenaStatusFlags == 2)))) {
        local_12c = *(WPARAM *)((int)local_8 + 0x130);
        ptVar6 = &local_14c;
        pHVar4 = GetDlgItem(hwnd,0x491);
        GetWindowRect(pHVar4,ptVar6);
        MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_14c,2);
        local_158 = *(WPARAM *)((int)local_8 + 0x134);
        ptVar6 = &local_13c;
        pHVar4 = GetDlgItem(hwnd,0x490);
        GetWindowRect(pHVar4,ptVar6);
        MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_13c,2);
        if ((local_12c == 0xffffffff) ||
           (pt.y = local_150, pt.x = local_154, BVar3 = PtInRect(&local_14c,pt), BVar3 == 0)) {
          if ((local_158 != 0xffffffff) &&
             (pt_00.y = local_150, pt_00.x = local_154, BVar3 = PtInRect(&local_13c,pt_00),
             BVar3 != 0)) {
            SendMessageA(g_MainAppWindow,0x401,local_158,0);
          }
        }
        else {
          SendMessageA(g_MainAppWindow,0x401,local_12c,0);
        }
      }
      return (HGDIOBJ)0x0;
    }
    if (uMsg == 0x138) goto LAB_004aecb5;
  }
  else if (uMsg < 0x205) {
    if (uMsg == 0x204) goto LAB_004aefff;
    if (uMsg == 0x201) {
      GetWindowRect(hwnd,&local_118);
      SendMessageA(hwnd,0x112,0xf012,0);
      GetWindowRect(hwnd,&local_128);
      iVar5 = abs(local_128.top - local_118.top);
      val_result = abs(local_128.left - local_118.left);
      if ((iVar5 + val_result < 6) &&
         (local_8 = (HWND)GetWindowLongA(hwnd,8), *(int *)((int)local_8 + 300) == 0)) {
        Ai_EndDuel_ShowResult((int)g_AiHeuristicWeight_Flyers,DAT_005569d4,DAT_00556964,DAT_00556a80);
        EndDialog(hwnd,1);
      }
      return (HGDIOBJ)0x1;
    }
  }
  else if (0x30e < uMsg) {
    if (uMsg < 0x312) {
      pvVar1 = (HGDIOBJ)FUN_004f5d1a(hwnd,uMsg,(HWND)wParam,lParam);
      return pvVar1;
    }
    if (uMsg == 0x4c8) {
      local_d8 = wParam;
      local_dc = lParam;
      if (wParam != (HDC)0x0) {
        SendMessageA(hwnd,0x401,(WPARAM)wParam,0);
      }
      if (local_d8 != (HDC)0x0) {
        InvalidateRect((HWND)local_d8,(RECT *)0x0,1);
      }
      if (local_dc != (HWND)0x0) {
        InvalidateRect(local_dc,(RECT *)0x0,1);
      }
      return (HGDIOBJ)0x0;
    }
  }
  return (HGDIOBJ)0x0;
}

/*
 * Ai_LoadEndDuelBackdrop
 * Purpose: Load duel victory / defeat result backdrop art.
 * Procedure:
 * 1. Load WINBK_EndDuel.pic and render conclusion screen.
 */
/*
 * Decompiled function: Ai_LoadEndDuelBackdrop
 * Entry Point: 004af4fd
 * Size: 230 bytes
 */

void Ai_LoadEndDuelBackdrop(int * arg1, int * out_buffer, int * arg3, int * arg4, int * arg5, int * arg6, int * arg7, int * arg8)

{
  int u_res;
  HBRUSH pHVar2;
  HPEN pHVar3;
  HGDIOBJ pvVar4;
  char local_10c [264];
  
  sprintf(local_10c,s__s_WINBK_EndDuel_pic_0052d1c4,&g_AiCurrentChoiceIndex);
  u_res = Pic_Load_00423833(local_10c);
  *arg1 = u_res;
  *out_buffer = 0x1000040;
  *arg3 = 0x1000040;
  pHVar2 = CreateSolidBrush(0x100001a);
  *arg4 = (int)pHVar2;
  pHVar3 = CreatePen(0,0,0x100008c);
  *arg5 = (int)pHVar3;
  pHVar3 = CreatePen(0,0,0x1000001);
  *arg6 = (int)pHVar3;
  *arg7 = 0x1000040;
  *arg_8 = 0x10000bf;
  if (*arg4 == 0) {
    pvVar4 = GetStockObject(2);
    *arg4 = (int)pvVar4;
  }
  if (*arg5 == 0) {
    pvVar4 = GetStockObject(6);
    *arg5 = (int)pvVar4;
  }
  if (*arg6 == 0) {
    pvVar4 = GetStockObject(7);
    *arg6 = (int)pvVar4;
  }
  return;
}

/*
 * Ai_EndDuel_ShowResult
 * Purpose: Display duel victory or defeat result dialog.
 * Procedure:
 * 1. Format match statistics (turns played, life totals, prize).
 * 2. Display conclusion dialog prompt.
 */
/*
 * Decompiled function: Ai_EndDuel_ShowResult
 * Entry Point: 004af5e3
 * Size: 93 bytes
 */

void Ai_EndDuel_ShowResult(int x, HGDIOBJ arg2, HGDIOBJ arg3, HGDIOBJ arg4)

{
  if (x != 0) {
    FUN_004f4548((HANDLE)x);
  }
  if (arg2 != (HGDIOBJ)0x0) {
    DeleteObject(arg2);
  }
  if (arg3 != (HGDIOBJ)0x0) {
    DeleteObject(arg3);
  }
  if (arg4 != (HGDIOBJ)0x0) {
    DeleteObject(arg4);
  }
  return;
}

/*
 * Ai_EndDuel_ProcessRewards
 * Purpose: Calculate and award match bounty, gold, and ante cards.
 * Procedure:
 * 1. Transfer won ante cards to winner library.
 * 2. Award gold and experience points.
 */
/*
 * Decompiled function: Ai_EndDuel_ProcessRewards
 * Entry Point: 004af640
 * Size: 293 bytes
 */

int Ai_EndDuel_ProcessRewards(int arg1, int arg2)

{
  uint local_8;
  
  KillTimer(g_MainAppHwnd,DAT_006fdbd4);
  EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  if ((DAT_006808ac != arg1) || (DAT_006a2834 != arg2)) {
    local_8 = local_8 | 1;
  }
  DAT_006808ac = arg1;
  DAT_006a2834 = arg2;
  DAT_006a48e0 = g_ActiveBattlefieldFlag;
  LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  if (local_8 != 0) {
    SendMessageA(g_AiEvaluationLock,0x432,0,0);
    UpdateWindow(g_AiEvaluationLock);
    SendMessageA(DAT_006a283c,0x432,0,0);
    UpdateWindow(DAT_006a283c);
  }
  if ((arg2 == 0x15) && (arg1 == 1)) {
    DAT_0069f6d0 = 0;
  }
  if ((arg2 == 0x15) && (g_ActiveBattlefieldFlag != 0)) {
    FUN_00481586(g_AiDecisionMatrix_Row);
  }
  if (arg2 == 0x1e) {
    FUN_00481586(g_AiDecisionMatrix_Row);
  }
  return 0;
}

/*
 * Ai_EndDuel_Cleanup
 * Purpose: Release duel arena resources and return to overworld.
 * Procedure:
 * 1. Free duel temporary memory buffers.
 * 2. Restore overworld background music and map state.
 */
/*
 * Decompiled function: Ai_EndDuel_Cleanup
 * Entry Point: 004af765
 * Size: 737 bytes
 */

LRESULT Ai_EndDuel_Cleanup(int arg1, char * output_str, int arg3, int arg4, int arg5, int arg6, int arg7, int * arg8, int * arg9, int arg10, int arg11)

{
  POINT Point;
  POINT Point_00;
  BOOL BVar1;
  tagPOINT local_1e4;
  HWND local_1dc;
  DWORD local_1d8;
  tagPOINT local_1d4;
  HWND local_1cc;
  char local_1c8 [200];
  int local_100;
  int local_fc;
  int local_f8;
  LRESULT local_f0;
  int local_ec;
  int local_e8;
  int local_e4;
  int local_e0;
  int local_dc;
  int local_d8;
  char local_d4 [200];
  int local_c;
  int local_8;
  
  if (output_str == (char *)0x0) {
    strcpy(local_1c8,&DAT_0052d1dc);
  }
  else {
    strcpy(local_1c8,output_str);
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  if (DAT_00696730 != -1) {
    DAT_00696730 = -1;
    BVar1 = IsWindowVisible(g_AiEvaluationLock);
    if (BVar1 == 0) {
      InvalidateRect(DAT_006a283c,(RECT *)0x0,1);
    }
    else {
      InvalidateRect(g_AiEvaluationLock,(RECT *)0x0,1);
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  Ai_Turn_ExecuteMainPhase(0,0xff);
  GetCursorPos(&local_1d4);
  Point.y = local_1d4.y;
  Point.x = local_1d4.x;
  local_1cc = WindowFromPoint(Point);
  SendMessageA(local_1cc,0x20,(WPARAM)local_1cc,0x2000001);
  local_ec = arg1;
  local_e8 = arg4;
  local_e4 = arg5;
  local_e0 = arg6;
  local_dc = arg7;
  local_c = arg_10;
  local_8 = arg_11;
  strcpy(local_d4,local_1c8);
  local_d8 = arg3;
  local_f0 = SendMessageA(g_MainAppHwnd,0x403,(WPARAM)&local_ec,(LPARAM)&local_100);
  *arg_8 = local_100;
  *arg_9 = local_fc;
  arg_9[1] = local_f8;
  Ai_EvalAbility_Trample((char *)0x0);
  if (local_100 != -5) {
    GetCursorPos(&local_1e4);
    Point_00.y = local_1e4.y;
    Point_00.x = local_1e4.x;
    local_1dc = WindowFromPoint(Point_00);
    SendMessageA(local_1dc,0x20,(WPARAM)local_1dc,0x2000001);
    EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
    if (DAT_0063ee8c == -2) {
      if (DAT_00627a88 == -1) {
        DAT_00696730 = -1;
        DAT_00695ec0 = 0xffffffff;
      }
      else {
        DAT_00695ec0 = DAT_00627a84;
        DAT_00696730 = DAT_00627a88;
      }
    }
    else {
      DAT_00696730 = -1;
      DAT_00695ec0 = 0xffffffff;
    }
    BVar1 = IsWindowVisible(g_AiEvaluationLock);
    if (BVar1 == 0) {
      InvalidateRect(DAT_006a283c,(RECT *)0x0,1);
    }
    else {
      InvalidateRect(g_AiEvaluationLock,(RECT *)0x0,1);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
    return local_f0;
  }
  local_1d8 = 0;
  PostMessageA(g_MainAppHwnd,0x401,0,0);
                    /* WARNING: Subroutine does not return */
  ExitThread(local_1d8);
}

/*
 * Ai_Score_InitRegister
 * Purpose: Initialize AI card scoring evaluation registers.
 * Procedure:
 * 1. Zero out evaluation accumulator registers.
 */
/*
 * Decompiled function: Ai_Score_InitRegister
 * Entry Point: 004afa46
 * Size: 35 bytes
 */

void Ai_Score_InitRegister(void)

{
  SendMessageA(g_MainAppHwnd,0x464,0xff,0);
  return;
}

/*
 * Ai_ScoreCardPlay_Creature
 * Purpose: Evaluate tactical value of casting candidate creature spell.
 * Procedure:
 * 1. Read creature converted mana cost, power, and abilities.
 * 2. Score value based on current board state and tempo.
 * 3. Return numeric play score.
 */
/*
 * Decompiled function: Ai_ScoreCardPlay_Creature
 * Entry Point: 004afa69
 * Size: 445 bytes
 */

INT_PTR Ai_ScoreCardPlay_Creature(int * player, int card_index, int target_player, int action_flags, int arg5, char * arg6)

{
  INT_PTR IVar1;
  int u_temp;
  int local_690;
  int auStack_68c [200];
  int auStack_36c [200];
  int local_4c;
  uint local_48;
  int local_44;
  char local_40 [12];
  int local_34;
  WNDCLASSA local_30;
  
  if (((arg3 < 1) || (arg1 == (int *)0x0)) || (*arg1 == -1)) {
    IVar1 = -1;
  }
  else {
    local_30.style = 0;
    local_30.lpfnWndProc = Ai_ScoreDialog_WndProc;
    local_30.cbClsExtra = 0;
    local_30.cbWndExtra = 0xc;
    local_30.hInstance = g_AppHInstance;
    local_30.hIcon = LoadIconA((HINSTANCE)0x0,(LPCSTR)0x7f00);
    local_30.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
    local_30.hbrBackground = (HBRUSH)0x6;
    local_30.lpszMenuName = (LPCSTR)0x0;
    local_30.lpszClassName = s_ShowListCard_0052d1e0;
    RegisterClassA(&local_30);
    local_690 = arg4;
    for (local_34 = 0; (local_34 < arg3 && (arg1[local_34] != -1)); local_34 = local_34 + 1) {
      u_temp = Ai_Subsystem_004cbd67(arg1[local_34] & 0xfff);
      auStack_68c[local_34] = u_temp;
    }
    local_4c = local_34;
    local_48 = (uint)(arg2 != 0);
    if (local_48 != 0) {
      for (local_34 = 0; local_34 < local_4c; local_34 = local_34 + 1) {
        auStack_36c[local_34] = *(int *)(arg2 + local_34 * 4);
      }
    }
    local_44 = arg5;
    if (arg5 == 0) {
      strcpy(local_40,str_6);
    }
    else {
      strcpy(local_40,&DAT_0052d1f0);
    }
    IVar1 = DialogBoxParamA(g_AppHInstance,(LPCSTR)0xe9,g_MainAppHwnd,Ai_ScoreCardPlay_Spell,
                            (LPARAM)&local_690);
  }
  return IVar1;
}

/*
 * Ai_ScoreCardPlay_Spell
 * Purpose: Evaluate tactical value of casting candidate instant/sorcery spell.
 * Procedure:
 * 1. Analyze spell effect type (removal, burn, buff, draw).
 * 2. Calculate target priority and value swing.
 * 3. Return numeric play score.
 */
/*
 * Decompiled function: Ai_ScoreCardPlay_Spell
 * Entry Point: 004afc26
 * Size: 4316 bytes
 */

LRESULT Ai_ScoreCardPlay_Spell(HWND player, uint card_index, HDC target_player, int * action_flags)

{
  uint u_res;
  int val_result;
  DWORD dwStyle;
  int cx;
  int temp_idx;
  int card_idx;
  LRESULT LVar5;
  HGDIOBJ pvVar6;
  HDC hdc_00;
  size_t c;
  BOOL bMenu;
  UINT uFlags;
  tagSIZE *psizl;
  LONG local_15c;
  LONG local_154;
  tagRECT local_150;
  tagSIZE local_140;
  int local_138;
  tagRECT local_134;
  CHAR local_124 [100];
  HDC local_c0;
  int local_bc;
  int local_b8;
  int local_b4;
  int local_b0;
  LONG local_ac;
  uint local_a8;
  tagRECT local_a4;
  tagRECT local_94;
  HDC local_84;
  tagRECT local_80;
  uint local_70;
  int local_6c;
  uint local_68;
  int local_64;
  tagRECT local_60;
  uint local_50;
  uint local_4c;
  uint local_48;
  LONG local_44;
  int *local_40;
  LONG local_3c;
  HWND local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  tagRECT local_14;
  
  if (y < 0x15) {
    if (y == 0x14) {
      local_84 = hdc;
      FUN_004f3955(hdc);
      GetClientRect(hwnd,&local_80);
      FillRect(local_84,&local_80,DAT_00556a98);
      return 1;
    }
    if (y == 0x10) {
LAB_004aff88:
      local_3c = GetWindowLongA(hwnd,8);
      if (local_3c == 0) {
        Ai_ScoreCardPlay_Artifact(DAT_00556a98,DAT_00556968,DAT_00556a9c,DAT_0055696c,DAT_00556a5c);
        EndDialog(hwnd,-1);
      }
      return 1;
    }
  }
  else if (y < 0xa2) {
    if (y == 0xa1) {
      if (hdc == (HDC)0xc8) {
        SendMessageA(hwnd,0x10,0,0);
        local_15c = 0;
      }
      else {
        local_15c = DefWindowProcA(hwnd,0xa1,(WPARAM)hdc,(LPARAM)arg4);
      }
      SetWindowLongA(hwnd,0,local_15c);
      return 1;
    }
    if (y == 0x84) {
      local_154 = DefWindowProcA(hwnd,0x84,(WPARAM)hdc,(LPARAM)arg4);
      if ((local_154 == 8) || (local_154 == 2)) {
        hdc_00 = GetDC((HWND)0x0);
        psizl = &local_140;
        c = strlen((char *)((int)g_AiHeuristicWeight_ManaEfficiency + 0x650));
        GetTextExtentPoint32A(hdc_00,(LPCSTR)((int)g_AiHeuristicWeight_ManaEfficiency + 0x650),c,psizl);
        ReleaseDC((HWND)0x0,hdc_00);
        GetClientRect(hwnd,&local_150);
        MapWindowPoints(hwnd,(HWND)0x0,(LPPOINT)&local_150,2);
        if (local_150.right - local_140.cx <= (int)((uint)arg4 & 0xffff)) {
          local_154 = 200;
        }
      }
      SetWindowLongA(hwnd,0,local_154);
      return 1;
    }
    if ((0x84 < y) && (y < 0x87)) {
      local_ac = GetWindowLongA(hwnd,8);
      GetWindowRect(hwnd,&local_94);
      OffsetRect(&local_94,-local_94.left,-local_94.top);
      if ((local_94.right != local_94.left) && (local_94.bottom != local_94.top)) {
        if (y == 0x85) {
          DefWindowProcA(hwnd,0x85,(WPARAM)hdc,(LPARAM)arg4);
        }
        local_a8 = (uint)(y != 0x85);
        local_c0 = GetWindowDC(hwnd);
        if (local_c0 != (HDC)0x0) {
          FUN_004f3955(local_c0);
          GetWindowRect(hwnd,&local_94);
          GetClientRect(hwnd,&local_134);
          MapWindowPoints(hwnd,(HWND)0x0,(LPPOINT)&local_134,2);
          OffsetRect(&local_134,-local_94.left,-local_94.top);
          OffsetRect(&local_94,-local_94.left,-local_94.top);
          GetWindowTextA(hwnd,local_124,100);
          local_138 = local_134.left - local_94.left;
          local_b4 = local_94.bottom - local_134.bottom;
          SelectObject(local_c0,DAT_00556a9c);
          local_b8 = 0;
          MoveToEx(local_c0,0,0,(LPPOINT)0x0);
          LineTo(local_c0,local_94.right + -1,local_b8);
          SelectObject(local_c0,DAT_00556968);
          local_b8 = 1;
          for (local_bc = 1; local_bc <= local_b4 + -2; local_bc = local_bc + 1) {
            MoveToEx(local_c0,1,local_b8,(LPPOINT)0x0);
            LineTo(local_c0,(local_94.right - local_138) + 1,local_b8);
            local_b8 = local_b8 + 1;
          }
          SelectObject(local_c0,DAT_00556a9c);
          local_b8 = local_b4 + -1;
          MoveToEx(local_c0,local_138 + -1,local_b8,(LPPOINT)0x0);
          LineTo(local_c0,local_94.right - local_138,local_b8);
          SelectObject(local_c0,DAT_00556a9c);
          local_b0 = 0;
          MoveToEx(local_c0,0,0,(LPPOINT)0x0);
          LineTo(local_c0,local_b0,local_94.bottom + -1);
          SelectObject(local_c0,DAT_00556968);
          local_b0 = 1;
          for (local_bc = 1; local_bc <= local_138 + -2; local_bc = local_bc + 1) {
            MoveToEx(local_c0,local_b0,1,(LPPOINT)0x0);
            LineTo(local_c0,local_b0,local_94.bottom + -1);
            local_b0 = local_b0 + 1;
          }
          SelectObject(local_c0,DAT_00556a9c);
          local_b0 = local_134.left + -1;
          MoveToEx(local_c0,local_b0,local_b4 + -1,(LPPOINT)0x0);
          LineTo(local_c0,local_b0,local_134.bottom + 1);
          pvVar6 = GetStockObject(7);
          SelectObject(local_c0,pvVar6);
          local_b0 = local_94.right + -1;
          MoveToEx(local_c0,local_b0,0,(LPPOINT)0x0);
          LineTo(local_c0,local_b0,local_94.bottom);
          SelectObject(local_c0,DAT_0055696c);
          local_b0 = local_94.right + -2;
          for (local_bc = 1; local_bc <= local_138 + -2; local_bc = local_bc + 1) {
            MoveToEx(local_c0,local_b0,1,(LPPOINT)0x0);
            LineTo(local_c0,local_b0,local_94.bottom + -1);
            local_b0 = local_b0 + -1;
          }
          SelectObject(local_c0,DAT_00556a9c);
          local_b0 = local_94.right - local_138;
          MoveToEx(local_c0,local_b0,local_b4 + -1,(LPPOINT)0x0);
          LineTo(local_c0,local_b0,local_134.bottom + 1);
          pvVar6 = GetStockObject(7);
          SelectObject(local_c0,pvVar6);
          local_b8 = local_94.bottom + -1;
          MoveToEx(local_c0,0,local_b8,(LPPOINT)0x0);
          LineTo(local_c0,local_94.right,local_b8);
          SelectObject(local_c0,DAT_0055696c);
          local_b8 = local_94.bottom + -2;
          for (local_bc = 1; local_bc <= local_b4 + -2; local_bc = local_bc + 1) {
            MoveToEx(local_c0,1,local_b8,(LPPOINT)0x0);
            LineTo(local_c0,local_94.right + -1,local_b8);
            local_b8 = local_b8 + -1;
          }
          SelectObject(local_c0,DAT_00556a9c);
          local_b8 = local_94.bottom - local_b4;
          MoveToEx(local_c0,local_138 + -1,local_b8,(LPPOINT)0x0);
          LineTo(local_c0,local_94.right + -2,local_b8);
          SelectObject(local_c0,DAT_00556a9c);
          local_b8 = local_134.top + -1;
          MoveToEx(local_c0,local_134.left,local_b8,(LPPOINT)0x0);
          LineTo(local_c0,local_94.right - local_138,local_b8);
          SetRect(&local_a4,local_134.left,local_b4,local_94.right - local_138,local_134.top + -1);
          FillRect(local_c0,&local_a4,DAT_00556a5c);
          SetTextColor(local_c0,DAT_00556ac0);
          SetBkMode(local_c0,1);
          local_a4.left = local_a4.left + 5;
          DrawTextA(local_c0,local_124,-1,&local_a4,0x24);
          if (local_ac == 0) {
            DrawTextA(local_c0,(LPCSTR)((int)g_AiHeuristicWeight_ManaEfficiency + 0x650),-1,&local_a4,0x26);
          }
          ReleaseDC(hwnd,local_c0);
        }
        SetWindowLongA(hwnd,0,local_a8);
        return 1;
      }
      LVar5 = DefWindowProcA(hwnd,y,(WPARAM)hdc,(LPARAM)arg4);
      return LVar5;
    }
  }
  else if (y < 0x111) {
    if (y == 0x110) {
      local_34 = 1;
      g_AiHeuristicWeight_ManaEfficiency = arg4;
      SetWindowLongA(hwnd,8,arg4[0x193]);
      DAT_00556a68 = 0;
      Ai_ScoreCardPlay_Enchantment
                ((int *)&DAT_00556a98,(int *)&DAT_00556968,(int *)&DAT_00556a9c,(int *)&DAT_0055696c
                 ,(int *)&DAT_00556a5c,&DAT_00556ac0);
      SetWindowTextA(hwnd,(LPCSTR)*g_AiHeuristicWeight_ManaEfficiency);
      local_30 = g_AiHeuristicWeight_ManaEfficiency[0x191];
      DAT_00556974 = (DAT_006a28b0 * 2) / 3;
      g_AiHeuristicWeight_FirstStrike = (DAT_006b2e30 * 2) / 3;
      DAT_00556948 = 8;
      g_AiHeuristicWeight_Aggression = 8;
      local_2c = 6;
      if (local_30 % 6 == 1) {
        local_2c = 5;
      }
      local_18 = local_30 / local_2c;
      if (0 < local_30 % local_2c) {
        local_18 = local_18 + 1;
      }
      local_1c = 4;
      SetRect(&local_14,0,0,(DAT_00556974 + 8) * local_2c + 8,(g_AiHeuristicWeight_FirstStrike + 8) * local_18 + 8);
      u_res = GetWindowLongA(hwnd,-0x10);
      SetWindowLongA(hwnd,-0x10,u_res & 0xffdfffff);
      if (local_1c < local_18) {
        u_res = GetWindowLongA(hwnd,-0x10);
        SetWindowLongA(hwnd,-0x10,u_res | 0x200000);
        SetScrollRange(hwnd,1,0,local_14.bottom -
                                ((g_AiHeuristicWeight_FirstStrike + g_AiHeuristicWeight_Aggression) * local_1c + g_AiHeuristicWeight_Aggression),1);
        SetScrollPos(hwnd,1,0,1);
        local_14.bottom = (g_AiHeuristicWeight_FirstStrike + g_AiHeuristicWeight_Aggression) * local_1c + local_14.top + g_AiHeuristicWeight_Aggression;
        val_result = GetSystemMetrics(2);
        local_14.right = local_14.right + val_result;
      }
      bMenu = 0;
      dwStyle = GetWindowLongA(hwnd,-0x10);
      AdjustWindowRect(&local_14,dwStyle,bMenu);
      uFlags = 4;
      val_result = local_14.bottom - local_14.top;
      cx = local_14.right - local_14.left;
      temp_idx = GetSystemMetrics(1);
      temp_idx = (temp_idx - (local_14.bottom - local_14.top)) / 2;
      card_idx = GetSystemMetrics(0);
      SetWindowPos(hwnd,(HWND)0x0,(card_idx - (local_14.right - local_14.left)) / 2,temp_idx,cx,val_result,
                   uFlags);
      local_20 = DAT_00556948;
      local_24 = g_AiHeuristicWeight_Aggression;
      GetClientRect(hwnd,&local_14);
      for (local_28 = 0; local_28 < (int)g_AiHeuristicWeight_ManaEfficiency[0x191]; local_28 = local_28 + 1) {
        local_38 = CreateWindowExA(0,s_ShowListCard_0052d200,s_List_Card_0052d1f4,0x50000000,
                                   local_20,local_24,DAT_00556974,g_AiHeuristicWeight_FirstStrike,hwnd,
                                   (HMENU)(local_28 + 10),g_AppHInstance,
                                   (LPVOID)g_AiHeuristicWeight_ManaEfficiency[local_28 + 1]);
        if (g_AiHeuristicWeight_ManaEfficiency[0x192] != 0) {
          SendMessageA(local_38,0x414,1,g_AiHeuristicWeight_ManaEfficiency[local_28 + 0xc9]);
        }
        local_20 = local_20 + DAT_00556974 + DAT_00556948;
        if (local_14.right < local_20 + DAT_00556974) {
          local_24 = local_24 + g_AiHeuristicWeight_FirstStrike + g_AiHeuristicWeight_Aggression;
          local_20 = DAT_00556948;
        }
      }
      SetFocus(hwnd);
      return 0;
    }
    if (y == 0x100) {
      if (hdc == (HDC)0x22) {
        SendMessageA(hwnd,0x115,3,0);
      }
      else if (hdc == (HDC)0x21) {
        SendMessageA(hwnd,0x115,2,0);
      }
      else if (hdc == (HDC)0x28) {
        SendMessageA(hwnd,0x115,1,0);
      }
      else if (hdc == (HDC)0x26) {
        SendMessageA(hwnd,0x115,0,0);
      }
      else if (hdc == (HDC)0x1b) {
        SendMessageA(hwnd,0x10,0,0);
      }
      return 1;
    }
  }
  else if (y < 0x116) {
    if (y == 0x115) {
      local_70 = GetScrollPos(hwnd,1);
      GetScrollRange(hwnd,1,(LPINT)&local_68,(LPINT)&local_50);
      GetClientRect(hwnd,&local_60);
      local_6c = g_AiHeuristicWeight_FirstStrike + g_AiHeuristicWeight_Aggression;
      local_64 = local_60.bottom - g_AiHeuristicWeight_Aggression;
      switch((uint)hdc & 0xffff) {
      case 0:
        local_4c = local_70 - local_6c;
        break;
      case 1:
        local_4c = local_70 + local_6c;
        break;
      case 2:
      case 4:
      case 5:
        local_4c = (uint)hdc >> 0x10;
        break;
      case 3:
        local_4c = local_70 + local_64;
        break;
      default:
        local_4c = local_70;
      }
      if ((int)local_4c < (int)local_68) {
        local_4c = local_68;
      }
      if ((int)local_50 < (int)local_4c) {
        local_4c = local_50;
      }
      ScrollWindow(hwnd,0,-(local_4c - local_70),(RECT *)0x0,(RECT *)0x0);
      SetScrollPos(hwnd,1,local_4c,1);
      return 1;
    }
    if (y == 0x111) {
      local_48 = (uint)hdc & 0xffff;
      local_40 = arg4;
      local_44 = GetWindowLongA(hwnd,8);
      if ((local_48 == 2) || (local_48 == 1)) {
        if (local_44 == 0) {
          Ai_ScoreCardPlay_Artifact(DAT_00556a98,DAT_00556968,DAT_00556a9c,DAT_0055696c,DAT_00556a5c);
          EndDialog(hwnd,-1);
        }
      }
      else if (local_40 != (int *)0x0) {
        Ai_ScoreCardPlay_Artifact(DAT_00556a98,DAT_00556968,DAT_00556a9c,DAT_0055696c,DAT_00556a5c);
        EndDialog(hwnd,local_48 - 10);
      }
      return 1;
    }
  }
  else {
    if (y == 0x201) goto LAB_004aff88;
    if ((0x30e < y) && (y < 0x312)) {
      LVar5 = FUN_004f5d1a(hwnd,y,(HWND)hdc,arg4);
      return LVar5;
    }
  }
  return 0;
}

/*
 * Ai_ScoreCardPlay_Enchantment
 * Purpose: Evaluate tactical value of casting enchantment or aura.
 * Procedure:
 * 1. Score persistent buff or lockdown effect on target card.
 * 2. Return numeric enchantment score.
 */
/*
 * Decompiled function: Ai_ScoreCardPlay_Enchantment
 * Entry Point: 004b0d24
 * Size: 237 bytes
 */

void Ai_ScoreCardPlay_Enchantment(int * player, int * card_index, int * target_player, int * action_flags, int * arg5, int * arg6)

{
  HBRUSH h_wnd;
  HPEN pHVar2;
  HGDIOBJ pvVar3;
  
  h_wnd = CreateSolidBrush(0x10000c7);
  *arg1 = (int)h_wnd;
  pHVar2 = CreatePen(0,0,0x1000086);
  *arg2 = (int)pHVar2;
  pHVar2 = CreatePen(0,0,0x100001d);
  *arg3 = (int)pHVar2;
  pHVar2 = CreatePen(0,0,0x10000c9);
  *arg4 = (int)pHVar2;
  h_wnd = CreateSolidBrush(0x100000f);
  *arg5 = (int)h_wnd;
  *arg6 = 0x1000090;
  if (*arg1 == 0) {
    pvVar3 = GetStockObject(2);
    *arg1 = (int)pvVar3;
  }
  if (*arg2 == 0) {
    pvVar3 = GetStockObject(6);
    *arg2 = (int)pvVar3;
  }
  if (*arg3 == 0) {
    pvVar3 = GetStockObject(6);
    *arg3 = (int)pvVar3;
  }
  if (*arg4 == 0) {
    pvVar3 = GetStockObject(7);
    *arg4 = (int)pvVar3;
  }
  if (*arg5 == 0) {
    pvVar3 = GetStockObject(2);
    *arg5 = (int)pvVar3;
  }
  return;
}

/*
 * Ai_ScoreCardPlay_Artifact
 * Purpose: Evaluate tactical value of casting artifact spell.
 * Procedure:
 * 1. Evaluate activated abilities and passive mana generation.
 * 2. Return numeric artifact score.
 */
/*
 * Decompiled function: Ai_ScoreCardPlay_Artifact
 * Entry Point: 004b0e11
 * Size: 111 bytes
 */

void Ai_ScoreCardPlay_Artifact(HGDIOBJ player, HGDIOBJ card_index, HGDIOBJ target_player, HGDIOBJ action_flags, HGDIOBJ arg5)

{
  if (arg1 != (HGDIOBJ)0x0) {
    DeleteObject(arg1);
  }
  if (arg2 != (HGDIOBJ)0x0) {
    DeleteObject(arg2);
  }
  if (arg3 != (HGDIOBJ)0x0) {
    DeleteObject(arg3);
  }
  if (arg4 != (HGDIOBJ)0x0) {
    DeleteObject(arg4);
  }
  if (arg5 != (HGDIOBJ)0x0) {
    DeleteObject(arg5);
  }
  return;
}

/*
 * Ai_ScoreDialog_WndProc
 * Purpose: Window procedure for card play scoring selection dialog.
 * Procedure:
 * 1. Handle card choice radio buttons and OK/Cancel commands.
 */
/*
 * Decompiled function: Ai_ScoreDialog_WndProc
 * Entry Point: 004b0e80
 * Size: 1026 bytes
 */

LRESULT Ai_ScoreDialog_WndProc(HWND hwnd, uint uMsg, WPARAM wParam, LONG * lParam)

{
  HWND h_wnd;
  uint u_temp;
  HWND hWnd;
  HBRUSH hbr;
  HDC hdc;
  LRESULT LVar3;
  UINT Msg;
  tagPAINTSTRUCT local_60;
  tagRECT local_20;
  WPARAM local_10;
  LONG *local_c;
  WPARAM local_8;
  
  if (uMsg < 0x10) {
    if (uMsg == 0xf) {
      local_8 = GetWindowLongA(hwnd,0);
      local_10 = GetWindowLongA(hwnd,8);
      local_c = (LONG *)GetWindowLongA(hwnd,4);
      EnterCriticalSection((LPCRITICAL_SECTION)&g_ActiveCombatRoundCounter);
      GetClientRect(hwnd,&local_20);
      hbr = GetStockObject(4);
      FillRect(g_HdcBackBuffer,&local_20,hbr);
      if (DAT_006ff2e8 == local_8) {
        Palette_Subsystem_0049c6cb(g_HdcBackBuffer,&local_20);
      }
      else {
        Palette_Subsystem_0049f8cd
                  (g_HdcBackBuffer,&local_20.left,(WPARAM *)(&g_AiDecisionMatrix_Col + local_8 * 0x98),0,0);
      }
      if (local_10 != 0) {
        Palette_Subsystem_004a00d1(g_HdcBackBuffer,&local_20.left,local_c);
      }
      hdc = BeginPaint(hwnd,&local_60);
      if (hdc != (HDC)0x0) {
        FUN_004f3955(hdc);
        BitBlt(hdc,0,0,local_20.right,local_20.bottom,g_HdcBackBuffer,0,0,0xcc0020);
        EndPaint(hwnd,&local_60);
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&g_ActiveCombatRoundCounter);
      return 0;
    }
    if (uMsg == 1) {
      local_8 = *lParam;
      SetWindowLongA(hwnd,0,local_8);
      local_10 = 0;
      local_c = (LONG *)0x0;
      SetWindowLongA(hwnd,8,0);
      SetWindowLongA(hwnd,4,(LONG)local_c);
      return 0;
    }
  }
  else if (uMsg < 0x101) {
    if (uMsg == 0x100) {
      h_wnd = GetParent(hwnd);
      SendMessageA(h_wnd,uMsg,wParam,(LPARAM)lParam);
      return 0;
    }
    if (uMsg == 0x87) {
      return 4;
    }
  }
  else {
    if (uMsg < 0x312) {
      if (0x30e < uMsg) {
        LVar3 = FUN_004f5d1a(hwnd,uMsg,(HWND)wParam,lParam);
        return LVar3;
      }
      if (uMsg != 0x200) {
        if (uMsg == 0x201) {
          h_wnd = hwnd;
          u_temp = GetDlgCtrlID(hwnd);
          u_temp = u_temp & 0xffff | 0x10000;
          Msg = 0x111;
          hWnd = GetParent(hwnd);
          SendMessageA(hWnd,Msg,u_temp,(LPARAM)h_wnd);
          return 0;
        }
        if (uMsg != 0x204) goto LAB_004b11b7;
      }
      if ((((uMsg == 0x200) && (g_DuelArenaStatusFlags != 2)) || ((uMsg == 0x204 && (g_DuelArenaStatusFlags == 2)))) &&
         (local_8 = GetWindowLongA(hwnd,0), DAT_00556a68 != hwnd)) {
        SendMessageA(g_MainAppWindow,0x401,local_8,0);
        DAT_00556a68 = hwnd;
      }
      return 0;
    }
    if (uMsg == 0x414) {
      local_10 = wParam;
      local_c = lParam;
      SetWindowLongA(hwnd,8,wParam);
      SetWindowLongA(hwnd,4,(LONG)local_c);
      InvalidateRect(hwnd,(RECT *)0x0,1);
      return 0;
    }
    if (uMsg == 0x437) {
      local_8 = GetWindowLongA(hwnd,0);
      if (g_DuelArenaStatusFlags != 2) {
        SendMessageA(g_MainAppWindow,0x401,local_8,0);
      }
      return 0;
    }
  }
LAB_004b11b7:
  LVar3 = DefWindowProcA(hwnd,uMsg,wParam,(LPARAM)lParam);
  return LVar3;
}

/*
 * Ai_CalcMana_ResetPool
 * Purpose: Reset simulated mana pool counters for tactical lookahead.
 * Procedure:
 * 1. Clear simulated mana pool registers for all 5 colors.
 */
/*
 * Decompiled function: Ai_CalcMana_ResetPool
 * Entry Point: 004b128e
 * Size: 19 bytes
 */

void Ai_CalcMana_ResetPool(void)

{
  return;
}

/*
 * Ai_CalcMana_AddSource
 * Purpose: Add available mana source to simulated pool.
 * Procedure:
 * 1. Increment available mana count for matching color.
 */
/*
 * Decompiled function: Ai_CalcMana_AddSource
 * Entry Point: 004b137d
 * Size: 137 bytes
 */

void Ai_CalcMana_AddSource(uint player, int color_index, int required_amount)

{
  BOOL BVar1;
  WPARAM WVar2;
  int *lParam;
  LPARAM lParam_00;
  int local_c;
  int local_8;
  
  local_c = arg2;
  local_8 = arg3;
  BVar1 = IsWindowVisible(g_MainAppWindow);
  if (BVar1 != 0) {
    if ((arg2 == -1) || (arg3 == -1)) {
      lParam_00 = 0;
      WVar2 = Ai_Subsystem_004cbd67(arg1);
      SendMessageA(g_MainAppWindow,0x401,WVar2,lParam_00);
    }
    else {
      lParam = &local_c;
      WVar2 = Ai_Subsystem_004cbd67(arg1);
      SendMessageA(g_MainAppWindow,0x401,WVar2,(LPARAM)lParam);
    }
  }
  return;
}

/*
 * Ai_CalcMana_ClearAvailable
 * Purpose: Clear temporary available mana registers.
 * Procedure:
 * 1. Reset temporary mana evaluation flags.
 */
/*
 * Decompiled function: Ai_CalcMana_ClearAvailable
 * Entry Point: 004b1406
 * Size: 16 bytes
 */

void Ai_CalcMana_ClearAvailable(void)

{
  return;
}

/*
 * Ai_ManaSelection_DialogProc
 * Purpose: Dialog procedure for mana source color selection.
 * Procedure:
 * 1. Handle color choice buttons (White, Blue, Black, Red, Green).
 */
/*
 * Decompiled function: Ai_ManaSelection_DialogProc
 * Entry Point: 004b1416
 * Size: 452 bytes
 */

INT_PTR Ai_ManaSelection_DialogProc(int hwnd, int uMsg, INT_PTR wParam, char * lParam, char * arg5, char * arg6)

{
  bool is_valid;
  bool is_match;
  bool bVar3;
  int local_20;
  INT_PTR local_1c;
  uint local_18;
  char *local_14;
  char *local_10;
  char *local_c;
  
  if (arg1 == 0) {
    local_20 = arg2;
    local_18 = (uint)(arg3 != -1);
    local_14 = str_4;
    local_10 = str_5;
    local_c = str_6;
    if ((str_4 == (char *)0x0) || (*str_4 == '\0')) {
      is_valid = false;
    }
    else {
      is_valid = true;
    }
    if ((str_5 == (char *)0x0) || (*str_5 == '\0')) {
      is_match = false;
    }
    else {
      is_match = true;
    }
    if ((str_6 == (char *)0x0) || (*str_6 == '\0')) {
      bVar3 = false;
    }
    else {
      bVar3 = true;
    }
    if (((is_valid) || (is_match)) || (bVar3)) {
      if (arg3 < 0) {
        arg3 = 0;
      }
      if (2 < arg3) {
        arg3 = 2;
      }
      if ((arg3 == 0) && (!is_valid)) {
        arg3 = 1;
      }
      if ((arg3 == 1) && (!is_match)) {
        arg3 = 2;
      }
      if ((arg3 == 2) && (!bVar3)) {
        arg3 = 0;
      }
      if ((arg3 == 0) && (!is_valid)) {
        arg3 = 1;
      }
      local_1c = arg3;
      arg3 = DialogBoxParamA(g_AppHInstance,(LPCSTR)0xe4,g_MainAppHwnd,Ai_TargetSelection_DialogProc,
                              (LPARAM)&local_20);
    }
  }
  return arg3;
}

/*
 * Ai_TargetSelection_DialogProc
 * Purpose: Dialog procedure for AI target candidate selection.
 * Procedure:
 * 1. Render list of valid permanent and player targets.
 * 2. Return chosen target index.
 */
/*
 * Decompiled function: Ai_TargetSelection_DialogProc
 * Entry Point: 004b15df
 * Size: 912 bytes
 */

HWND Ai_TargetSelection_DialogProc(HWND hwnd, uint uMsg, uint wParam, int * lParam)

{
  UINT UVar1;
  LONG LVar2;
  HWND pHVar3;
  int card_idx;
  INT_PTR local_c;
  
  if (uMsg < 0x202) {
    if (uMsg == 0x201) {
      SendMessageA(hwnd,0x112,0xf012,0);
      return (HWND)0x0;
    }
    if (uMsg == 0x110) {
      SetWindowLongA(hwnd,8,lParam[1]);
      SetDlgItemTextA(hwnd,0x429,(LPCSTR)*lParam);
      if (lParam[2] == 0) {
        card_idx = 0;
        pHVar3 = GetDlgItem(hwnd,0x42a);
        ShowWindow(pHVar3,card_idx);
      }
      if ((lParam[3] == 0) || (*(char *)lParam[3] == '\0')) {
        card_idx = 0;
        pHVar3 = GetDlgItem(hwnd,0x42d);
        ShowWindow(pHVar3,card_idx);
      }
      else {
        SetDlgItemTextA(hwnd,0x42d,(LPCSTR)lParam[3]);
      }
      if ((lParam[4] == 0) || (*(char *)lParam[4] == '\0')) {
        card_idx = 0;
        pHVar3 = GetDlgItem(hwnd,0x42c);
        ShowWindow(pHVar3,card_idx);
      }
      else {
        SetDlgItemTextA(hwnd,0x42c,(LPCSTR)lParam[4]);
      }
      if ((lParam[5] == 0) || (*(char *)lParam[5] == '\0')) {
        card_idx = 0;
        pHVar3 = GetDlgItem(hwnd,0x42b);
        ShowWindow(pHVar3,card_idx);
      }
      else {
        SetDlgItemTextA(hwnd,0x42b,(LPCSTR)lParam[5]);
      }
      if (lParam[1] == 0) {
        CheckDlgButton(hwnd,0x42d,(uint)(lParam[1] == 0));
      }
      else if (lParam[1] == 1) {
        CheckDlgButton(hwnd,0x42c,(uint)(lParam[1] == 1));
      }
      else {
        CheckDlgButton(hwnd,0x42b,(uint)(lParam[1] == 2));
      }
      pHVar3 = GetDlgItem(hwnd,1);
      SetFocus(pHVar3);
      return (HWND)0x0;
    }
    if (uMsg == 0x111) {
      if ((wParam & 0xffff) == 1) {
        UVar1 = IsDlgButtonChecked(hwnd,0x42d);
        if (UVar1 != 0) {
          local_c = 0;
        }
        UVar1 = IsDlgButtonChecked(hwnd,0x42c);
        if (UVar1 != 0) {
          local_c = 1;
        }
        UVar1 = IsDlgButtonChecked(hwnd,0x42b);
        if (UVar1 != 0) {
          local_c = 2;
        }
        EndDialog(hwnd,local_c);
      }
      else if ((wParam & 0xffff) == 0x42a) {
        LVar2 = GetWindowLongA(hwnd,8);
        CheckDlgButton(hwnd,0x42d,(uint)(LVar2 == 0));
        CheckDlgButton(hwnd,0x42c,(uint)(LVar2 == 1));
        CheckDlgButton(hwnd,0x42b,(uint)(LVar2 == 2));
        pHVar3 = GetDlgItem(hwnd,1);
        pHVar3 = SetFocus(pHVar3);
        return pHVar3;
      }
      return (HWND)0x1;
    }
  }
  else if ((0x30e < uMsg) && (uMsg < 0x312)) {
    pHVar3 = (HWND)FUN_004f5d1a(hwnd,uMsg,(HWND)wParam,lParam);
    return pHVar3;
  }
  return (HWND)0x0;
}

/*
 * Ai_Target_HighlightCandidate
 * Purpose: Highlight selected target permanent on duel battlefield.
 * Procedure:
 * 1. Draw yellow selection border around target card slot.
 */
/*
 * Decompiled function: Ai_Target_HighlightCandidate
 * Entry Point: 004b1974
 * Size: 87 bytes
 */

INT_PTR Ai_Target_HighlightCandidate(int arg1, int arg2, INT_PTR arg3)

{
  int local_10;
  INT_PTR local_c;
  
  if (arg1 == 0) {
    local_10 = arg2;
    local_c = arg3;
    arg3 = DialogBoxParamA(g_AppHInstance,(LPCSTR)0xe5,g_MainAppHwnd,Ai_AttackSelection_DialogProc,
                            (LPARAM)&local_10);
  }
  return arg3;
}

/*
 * Ai_AttackSelection_DialogProc
 * Purpose: Dialog procedure for declaring attackers.
 * Procedure:
 * 1. Display attacking candidate creature slots.
 * 2. Allow player or AI to toggle attacker flags.
 */
/*
 * Decompiled function: Ai_AttackSelection_DialogProc
 * Entry Point: 004b19d0
 * Size: 355 bytes
 */

int Ai_AttackSelection_DialogProc(HWND hwnd, uint uMsg, uint wParam, int * lParam)

{
  HWND h_wnd;
  int u_temp;
  
  if (uMsg < 0x202) {
    if (uMsg == 0x201) {
      SendMessageA(hwnd,0x112,0xf012,0);
      return 0;
    }
    if (uMsg == 0x110) {
      SetWindowLongA(hwnd,8,lParam[1]);
      SetDlgItemTextA(hwnd,0x42e,(LPCSTR)*lParam);
      if (lParam[1] == 1) {
        h_wnd = GetDlgItem(hwnd,6);
        SetFocus(h_wnd);
      }
      else {
        h_wnd = GetDlgItem(hwnd,7);
        SetFocus(h_wnd);
      }
      return 0;
    }
    if (uMsg == 0x111) {
      if ((wParam & 0xffff) == 6) {
        EndDialog(hwnd,1);
      }
      else if ((wParam & 0xffff) == 7) {
        EndDialog(hwnd,0);
      }
      return 1;
    }
  }
  else if ((0x30e < uMsg) && (uMsg < 0x312)) {
    u_temp = FUN_004f5d1a(hwnd,uMsg,(HWND)wParam,lParam);
    return u_temp;
  }
  return 0;
}

/*
 * Ai_Attack_ToggleAttacker
 * Purpose: Toggle attacking state flag for creature slot.
 * Procedure:
 * 1. Toggle tap and attack status flags for creature.
 */
/*
 * Decompiled function: Ai_Attack_ToggleAttacker
 * Entry Point: 004b1b38
 * Size: 94 bytes
 */

INT_PTR Ai_Attack_ToggleAttacker(int arg1, int arg2, INT_PTR arg3)

{
  int local_14;
  INT_PTR local_10;
  int local_c;
  
  if (arg1 == 0) {
    local_14 = arg2;
    local_10 = arg3;
    local_c = 0;
    arg3 = DialogBoxParamA(g_AppHInstance,(LPCSTR)0xdc,g_MainAppHwnd,Ai_BlockSelection_DialogProc,
                            (LPARAM)&local_14);
  }
  return arg3;
}

/*
 * Ai_BlockSelection_DialogProc
 * Purpose: Dialog procedure for declaring blocking assignments.
 * Procedure:
 * 1. Display attacking and defending creature pairs.
 * 2. Confirm valid blocking configuration.
 */
/*
 * Decompiled function: Ai_BlockSelection_DialogProc
 * Entry Point: 004b1b9b
 * Size: 1344 bytes
 */

HGDIOBJ Ai_BlockSelection_DialogProc(HWND hwnd, uint uMsg, HDC wParam, HWND lParam)

{
  HDC hDC;
  HGDIOBJ pvVar1;
  HWND pHVar2;
  int temp_idx;
  HBRUSH hbr;
  code *dwNewLong;
  tagRECT local_44;
  COLORREF local_34;
  HWND local_30;
  HWND local_2c;
  int local_28;
  HDC local_24;
  HWND local_20;
  HWND local_1c;
  UINT local_18;
  UINT local_14;
  int local_10;
  uint local_c;
  HWND local_8;
  
  if (uMsg < 0x2c) {
    if (uMsg == 0x2b) {
      local_30 = lParam;
      pHVar2 = GetFocus();
      if (pHVar2 == (HWND)local_30[5].unused) {
        local_34 = DAT_00556a88;
      }
      else {
        local_34 = DAT_00556958;
      }
      FUN_004f5107((int)local_30,DAT_00556950,DAT_00556a48,DAT_005569d0,local_34,0);
      return (HGDIOBJ)0x1;
    }
    if (uMsg == 0x14) {
      FUN_004f3955(wParam);
      GetClientRect(hwnd,&local_44);
      EnterCriticalSection((LPCRITICAL_SECTION)&g_ActiveCombatRoundCounter);
      temp_idx = SaveDC(g_HdcBackBuffer);
      hDC = g_HdcBackBuffer;
      if (DAT_00556adc == (HANDLE)0x0) {
        hbr = GetStockObject(2);
        FillRect(hDC,&local_44,hbr);
      }
      else {
        FUN_004f3b5f((int)g_HdcBackBuffer,(int)&local_44,DAT_00556adc);
      }
      RestoreDC(g_HdcBackBuffer,temp_idx);
      GetClientRect(hwnd,&local_44);
      BitBlt(wParam,0,0,local_44.right,local_44.bottom,g_HdcBackBuffer,0,0,0xcc0020);
      LeaveCriticalSection((LPCRITICAL_SECTION)&g_ActiveCombatRoundCounter);
      return (HGDIOBJ)0x1;
    }
  }
  else if (uMsg < 0x139) {
    if (uMsg == 0x138) {
      local_24 = wParam;
      FUN_004f3955(wParam);
      local_2c = lParam;
      local_28 = GetDlgCtrlID(lParam);
      SetBkMode(local_24,1);
      SetTextColor(local_24,DAT_00556a70);
      pvVar1 = GetStockObject(5);
      return pvVar1;
    }
    if (uMsg == 0x110) {
      local_8 = lParam;
      SetWindowLongA(hwnd,8,lParam[1].unused);
      Ai_LoadQuestPromptBackdrop
                (&DAT_00556adc,&DAT_00556a70,(int *)&DAT_00556950,(int *)&DAT_00556a48,
                 (int *)&DAT_005569d0,&DAT_00556958,&DAT_00556a88);
      SetDlgItemTextA(hwnd,0x41a,(LPCSTR)local_8->unused);
      if (local_8[2].unused == 0) {
        temp_idx = 0;
        pHVar2 = GetDlgItem(hwnd,0x41b);
        ShowWindow(pHVar2,temp_idx);
      }
      SendMessageA(hwnd,0x401,1,0);
      SetDlgItemInt(hwnd,0x419,local_8[1].unused,0);
      dwNewLong = Ai_Block_AssignPair;
      temp_idx = -4;
      pHVar2 = GetDlgItem(hwnd,0x419);
      DAT_006498ec = SetWindowLongA(pHVar2,temp_idx,(LONG)dwNewLong);
      pHVar2 = GetDlgItem(hwnd,0x419);
      SetFocus(pHVar2);
      SendDlgItemMessageA(hwnd,0x419,0xb1,0,-1);
      FUN_004f570c(hwnd);
      return (HGDIOBJ)0x0;
    }
    if (uMsg == 0x111) {
      local_c = (uint)wParam & 0xffff;
      if (local_c == 1) {
        local_14 = GetDlgItemInt(hwnd,0x419,&local_10,0);
        if (local_10 == 0) {
          pHVar2 = GetDlgItem(hwnd,0x419);
          SetFocus(pHVar2);
          SendDlgItemMessageA(hwnd,0x419,0xb1,0,-1);
        }
        else {
          Ai_Quest_FormatPromptText((int)DAT_00556adc,DAT_00556950,DAT_00556a48,DAT_005569d0);
          EndDialog(hwnd,local_14);
        }
      }
      else if (local_c == 2) {
        Ai_Quest_FormatPromptText((int)DAT_00556adc,DAT_00556950,DAT_00556a48,DAT_005569d0);
        EndDialog(hwnd,-1);
      }
      else if (local_c == 0x41b) {
        local_18 = GetWindowLongA(hwnd,8);
        SetDlgItemInt(hwnd,0x419,local_18,0);
        pHVar2 = GetDlgItem(hwnd,0x419);
        SetFocus(pHVar2);
      }
      return (HGDIOBJ)0x1;
    }
  }
  else if (uMsg < 0x312) {
    if (0x30e < uMsg) {
      pvVar1 = (HGDIOBJ)FUN_004f5d1a(hwnd,uMsg,(HWND)wParam,lParam);
      return pvVar1;
    }
    if (uMsg == 0x201) {
      SendMessageA(hwnd,0x112,0xf012,0);
      return (HGDIOBJ)0x0;
    }
  }
  else if (uMsg == 0x4c8) {
    local_1c = (HWND)wParam;
    local_20 = lParam;
    pHVar2 = GetDlgItem(hwnd,2);
    if (pHVar2 == local_1c) {
      SendMessageA(hwnd,0x401,2,0);
    }
    else {
      SendMessageA(hwnd,0x401,1,0);
    }
    if (local_1c != (HWND)0x0) {
      InvalidateRect(local_1c,(RECT *)0x0,1);
    }
    if (local_20 != (HWND)0x0) {
      InvalidateRect(local_20,(RECT *)0x0,1);
    }
    return (HGDIOBJ)0x0;
  }
  return (HGDIOBJ)0x0;
}

/*
 * Ai_Block_AssignPair
 * Purpose: Assign defending creature to attacking creature slot.
 * Procedure:
 * 1. Link blocker card slot to attacker card slot.
 */
/*
 * Decompiled function: Ai_Block_AssignPair
 * Entry Point: 004b20e5
 * Size: 148 bytes
 */

LRESULT Ai_Block_AssignPair(HWND hwnd, UINT y, uint width, LPARAM arg4)

{
  LRESULT LVar1;
  
  if (y == 0x102) {
    if (((width < 0x30) || (0x39 < width)) && (width != 8)) {
      LVar1 = 0;
    }
    else {
      LVar1 = CallWindowProcA(DAT_006498ec,hwnd,0x102,width,arg4);
    }
  }
  else {
    LVar1 = CallWindowProcA(DAT_006498ec,hwnd,y,width,arg4);
  }
  return LVar1;
}

/*
 * Ai_LoadQuestPromptBackdrop
 * Purpose: Load quest and encounter dialog backdrop art.
 * Procedure:
 * 1. Load WINBK_QuestN.pic into dialog DC.
 */
/*
 * Decompiled function: Ai_LoadQuestPromptBackdrop
 * Entry Point: 004b2183
 * Size: 221 bytes
 */

void Ai_LoadQuestPromptBackdrop(int * arg1, int * out_buffer, int * arg3, int * arg4, int * arg5, int * arg6, int * arg7)

{
  int u_res;
  HBRUSH pHVar2;
  HPEN pHVar3;
  HGDIOBJ pvVar4;
  char local_10c [264];
  
  sprintf(local_10c,s__s_WINBK_QuestN_pic_0052d210,&g_AiCurrentChoiceIndex);
  u_res = Pic_Load_00423833(local_10c);
  *arg1 = u_res;
  *out_buffer = 0x100009a;
  pHVar2 = CreateSolidBrush(0x100001c);
  *arg3 = (int)pHVar2;
  pHVar3 = CreatePen(0,0,0x1000072);
  *arg4 = (int)pHVar3;
  pHVar3 = CreatePen(0,0,0x10000ca);
  *arg5 = (int)pHVar3;
  *arg6 = 0x100009a;
  *arg7 = 0x10000bf;
  if (*arg3 == 0) {
    pvVar4 = GetStockObject(2);
    *arg3 = (int)pvVar4;
  }
  if (*arg4 == 0) {
    pvVar4 = GetStockObject(6);
    *arg4 = (int)pvVar4;
  }
  if (*arg5 == 0) {
    pvVar4 = GetStockObject(7);
    *arg5 = (int)pvVar4;
  }
  return;
}

/*
 * Ai_Quest_FormatPromptText
 * Purpose: Format quest and encounter text string.
 * Procedure:
 * 1. Copy quest dialogue string into prompt display buffer.
 */
/*
 * Decompiled function: Ai_Quest_FormatPromptText
 * Entry Point: 004b2260
 * Size: 93 bytes
 */

void Ai_Quest_FormatPromptText(int x, HGDIOBJ arg2, HGDIOBJ arg3, HGDIOBJ arg4)

{
  if (x != 0) {
    FUN_004f4548((HANDLE)x);
  }
  if (arg2 != (HGDIOBJ)0x0) {
    DeleteObject(arg2);
  }
  if (arg3 != (HGDIOBJ)0x0) {
    DeleteObject(arg3);
  }
  if (arg4 != (HGDIOBJ)0x0) {
    DeleteObject(arg4);
  }
  return;
}

/*
 * Ai_Quest_ProcessChoice
 * Purpose: Process player or AI quest encounter decision.
 * Procedure:
 * 1. Evaluate encounter reward or combat initiation.
 */
/*
 * Decompiled function: Ai_Quest_ProcessChoice
 * Entry Point: 004b22bd
 * Size: 698 bytes
 */

INT_PTR Ai_Quest_ProcessChoice(int arg1, int arg2, int arg3, int arg4, uint arg5)

{
  char c_res;
  INT_PTR local_20;
  int local_1c;
  int local_18;
  uint local_14;
  int local_10;
  uint local_c;
  INT_PTR local_8;
  
  c_res = (arg5 & 2) != 0;
  if ((arg5 & 0x20) != 0) {
    c_res = c_res + '\x01';
  }
  if ((arg5 & 8) != 0) {
    c_res = c_res + '\x01';
  }
  if ((arg5 & 0x10) != 0) {
    c_res = c_res + '\x01';
  }
  if ((arg5 & 4) != 0) {
    c_res = c_res + '\x01';
  }
  if ((arg5 & 1) != 0) {
    c_res = c_res + '\x01';
  }
  if (c_res == '\0') {
    local_20 = -1;
  }
  else if (c_res == '\x01') {
    if ((arg5 & 2) == 0) {
      if ((arg5 & 0x20) == 0) {
        if ((arg5 & 8) == 0) {
          if ((arg5 & 0x10) == 0) {
            if ((arg5 & 4) == 0) {
              local_20 = local_8;
              if ((arg5 & 1) != 0) {
                local_8 = 0;
                local_20 = local_8;
              }
            }
            else {
              local_8 = 2;
              local_20 = local_8;
            }
          }
          else {
            local_8 = 4;
            local_20 = local_8;
          }
        }
        else {
          local_8 = 3;
          local_20 = local_8;
        }
      }
      else {
        local_8 = 5;
        local_20 = local_8;
      }
    }
    else {
      local_8 = 1;
      local_20 = local_8;
    }
  }
  else {
    if ((((((arg4 == 1) && ((arg5 & 2) == 0)) || ((arg4 == 5 && ((arg5 & 0x20) == 0)))) ||
         ((arg4 == 3 && ((arg5 & 8) == 0)))) || ((arg4 == 4 && ((arg5 & 0x10) == 0)))) ||
       ((((arg4 == 2 && ((arg5 & 4) == 0)) || ((arg4 == 0 && ((arg5 & 1) == 0)))) ||
        ((arg4 < 0 || (5 < arg4)))))) {
      if ((arg5 & 0x20) == 0) {
        if ((arg5 & 4) == 0) {
          if ((arg5 & 2) == 0) {
            if ((arg5 & 0x10) == 0) {
              if ((arg5 & 8) == 0) {
                if ((arg5 & 1) != 0) {
                  arg4 = 0;
                }
              }
              else {
                arg4 = 3;
              }
            }
            else {
              arg4 = 4;
            }
          }
          else {
            arg4 = 1;
          }
        }
        else {
          arg4 = 2;
        }
      }
      else {
        arg4 = 5;
      }
    }
    local_20 = arg4;
    if (arg1 == 0) {
      local_1c = arg2;
      local_18 = arg4;
      local_14 = (uint)(arg4 != -1);
      local_10 = arg3;
      local_c = arg5;
      local_20 = DialogBoxParamA(g_AppHInstance,(LPCSTR)0xde,g_MainAppHwnd,Ai_Quest_DialogProc,
                                 (LPARAM)&local_1c);
      if (local_20 == -1) {
        local_20 = -1;
      }
      else if (local_20 == -2) {
        local_20 = -1;
      }
    }
  }
  return local_20;
}

/*
 * Ai_Quest_DialogProc
 * Purpose: Dialog procedure for overworld quest and NPC dialogs.
 * Procedure:
 * 1. Handle NPC dialogue options and response buttons.
 */
/*
 * Decompiled function: Ai_Quest_DialogProc
 * Entry Point: 004b257c
 * Size: 3363 bytes
 */

HGDIOBJ Ai_Quest_DialogProc(HWND hwnd, uint uMsg, HDC wParam, HWND lParam)

{
  HDC hDC;
  HGDIOBJ pvVar1;
  int val_result;
  HBRUSH pHVar3;
  HWND pHVar4;
  BOOL BVar5;
  tagRECT *ptVar6;
  tagRECT local_48;
  COLORREF local_38;
  HWND local_34;
  HWND local_30;
  int local_2c;
  HDC local_28;
  HWND local_24;
  HWND local_20;
  uint local_1c;
  tagRECT local_18;
  HWND local_8;
  
  if (uMsg < 0x2c) {
    if (uMsg == 0x2b) {
      local_34 = lParam;
      pHVar4 = GetFocus();
      if (pHVar4 == (HWND)local_34[5].unused) {
        local_38 = DAT_0055695c;
      }
      else {
        local_38 = DAT_00556af0;
      }
      FUN_004f5107((int)local_34,DAT_00556aa8,DAT_00556a7c,DAT_00556a44,local_38,0);
      return (HGDIOBJ)0x1;
    }
    if (uMsg == 0x14) {
      FUN_004f3955(wParam);
      GetClientRect(hwnd,&local_48);
      EnterCriticalSection((LPCRITICAL_SECTION)&g_ActiveCombatRoundCounter);
      val_result = SaveDC(g_HdcBackBuffer);
      hDC = g_HdcBackBuffer;
      if (DAT_00556aa4 == (HANDLE)0x0) {
        pHVar3 = GetStockObject(2);
        FillRect(hDC,&local_48,pHVar3);
      }
      else {
        FUN_004f3b5f((int)g_HdcBackBuffer,(int)&local_48,DAT_00556aa4);
      }
      Ai_CalcManaRequirement_Green(&local_48,hwnd,g_AiHeuristicWeight_CreaturePower);
      if (DAT_00556a40 == (HANDLE)0x0) {
        pHVar3 = CreateSolidBrush(0x2908c52);
        FrameRect(hDC,&local_48,pHVar3);
        DeleteObject(pHVar3);
      }
      else {
        FUN_004f3b5f((int)hDC,(int)&local_48,DAT_00556a40);
      }
      pHVar4 = GetDlgItem(hwnd,0x422);
      BVar5 = IsWindowVisible(pHVar4);
      if (BVar5 != 0) {
        ptVar6 = &local_48;
        pHVar4 = GetDlgItem(hwnd,0x41c);
        GetWindowRect(pHVar4,ptVar6);
        MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_48,2);
        FUN_004f3e29(hDC,&local_48,DAT_00556994);
      }
      pHVar4 = GetDlgItem(hwnd,0x423);
      BVar5 = IsWindowVisible(pHVar4);
      if (BVar5 != 0) {
        ptVar6 = &local_48;
        pHVar4 = GetDlgItem(hwnd,0x41e);
        GetWindowRect(pHVar4,ptVar6);
        MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_48,2);
        FUN_004f3e29(hDC,&local_48,DAT_00556988);
      }
      pHVar4 = GetDlgItem(hwnd,0x424);
      BVar5 = IsWindowVisible(pHVar4);
      if (BVar5 != 0) {
        ptVar6 = &local_48;
        pHVar4 = GetDlgItem(hwnd,0x420);
        GetWindowRect(pHVar4,ptVar6);
        MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_48,2);
        FUN_004f3e29(hDC,&local_48,DAT_00556984);
      }
      pHVar4 = GetDlgItem(hwnd,0x425);
      BVar5 = IsWindowVisible(pHVar4);
      if (BVar5 != 0) {
        ptVar6 = &local_48;
        pHVar4 = GetDlgItem(hwnd,0x41f);
        GetWindowRect(pHVar4,ptVar6);
        MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_48,2);
        FUN_004f3e29(hDC,&local_48,DAT_00556990);
      }
      pHVar4 = GetDlgItem(hwnd,0x426);
      BVar5 = IsWindowVisible(pHVar4);
      if (BVar5 != 0) {
        ptVar6 = &local_48;
        pHVar4 = GetDlgItem(hwnd,0x41d);
        GetWindowRect(pHVar4,ptVar6);
        MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_48,2);
        FUN_004f3e29(hDC,&local_48,DAT_0055698c);
      }
      pHVar4 = GetDlgItem(hwnd,0x427);
      BVar5 = IsWindowVisible(pHVar4);
      if (BVar5 != 0) {
        ptVar6 = &local_48;
        pHVar4 = GetDlgItem(hwnd,0x421);
        GetWindowRect(pHVar4,ptVar6);
        MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_48,2);
        FUN_004f3e29(hDC,&local_48,DAT_00556980);
      }
      RestoreDC(g_HdcBackBuffer,val_result);
      GetClientRect(hwnd,&local_48);
      BitBlt(wParam,0,0,local_48.right,local_48.bottom,g_HdcBackBuffer,0,0,0xcc0020);
      LeaveCriticalSection((LPCRITICAL_SECTION)&g_ActiveCombatRoundCounter);
      return (HGDIOBJ)0x1;
    }
  }
  else if (uMsg < 0x139) {
    if (uMsg == 0x138) {
      local_28 = wParam;
      FUN_004f3955(wParam);
      local_30 = lParam;
      local_2c = GetDlgCtrlID(lParam);
      SetBkMode(local_28,1);
      if (local_2c == 0x489) {
        SetTextColor(local_28,DAT_005569c4);
      }
      else {
        SetTextColor(local_28,DAT_00556ae0);
      }
      pvVar1 = GetStockObject(5);
      return pvVar1;
    }
    if (uMsg == 0x110) {
      local_8 = lParam;
      SetWindowLongA(hwnd,8,lParam[1].unused);
      Ai_CalcManaRequirement_Black
                (&DAT_00556aa4,&DAT_005569c4,&DAT_00556a40,&DAT_00556980,&DAT_00556ae0,
                 (int *)&DAT_00556aa8,(int *)&DAT_00556a7c,(int *)&DAT_00556a44,&DAT_00556af0,
                 &DAT_0055695c);
      SetDlgItemTextA(hwnd,0x489,(LPCSTR)local_8->unused);
      if (local_8[2].unused == 0) {
        val_result = 0;
        pHVar4 = GetDlgItem(hwnd,0x428);
        ShowWindow(pHVar4,val_result);
      }
      pHVar4 = GetDlgItem(hwnd,1);
      SetFocus(pHVar4);
      SendMessageA(hwnd,0x401,1,0);
      g_AiHeuristicWeight_CreaturePower = local_8[1].unused;
      if (local_8[3].unused == 0) {
        SetDlgItemTextA(hwnd,0x424,s__Swamp_0052d224);
        SetDlgItemTextA(hwnd,0x423,s__Island_0052d22c);
        SetDlgItemTextA(hwnd,0x426,s__Forest_0052d234);
        SetDlgItemTextA(hwnd,0x425,s__Mountain_0052d23c);
        SetDlgItemTextA(hwnd,0x422,s__Plains_0052d248);
        SetDlgItemTextA(hwnd,0x427,s_Generic___X__0052d250);
      }
      if ((local_8[4].unused & 2) == 0) {
        val_result = 0;
        pHVar4 = GetDlgItem(hwnd,0x420);
        ShowWindow(pHVar4,val_result);
        val_result = 0;
        pHVar4 = GetDlgItem(hwnd,0x424);
        ShowWindow(pHVar4,val_result);
      }
      if ((local_8[4].unused & 4) == 0) {
        val_result = 0;
        pHVar4 = GetDlgItem(hwnd,0x41e);
        ShowWindow(pHVar4,val_result);
        val_result = 0;
        pHVar4 = GetDlgItem(hwnd,0x423);
        ShowWindow(pHVar4,val_result);
      }
      if ((local_8[4].unused & 8) == 0) {
        val_result = 0;
        pHVar4 = GetDlgItem(hwnd,0x41d);
        ShowWindow(pHVar4,val_result);
        val_result = 0;
        pHVar4 = GetDlgItem(hwnd,0x426);
        ShowWindow(pHVar4,val_result);
      }
      if ((local_8[4].unused & 0x10) == 0) {
        val_result = 0;
        pHVar4 = GetDlgItem(hwnd,0x41f);
        ShowWindow(pHVar4,val_result);
        val_result = 0;
        pHVar4 = GetDlgItem(hwnd,0x425);
        ShowWindow(pHVar4,val_result);
      }
      if ((local_8[4].unused & 0x20) == 0) {
        val_result = 0;
        pHVar4 = GetDlgItem(hwnd,0x41c);
        ShowWindow(pHVar4,val_result);
        val_result = 0;
        pHVar4 = GetDlgItem(hwnd,0x422);
        ShowWindow(pHVar4,val_result);
      }
      if ((local_8[4].unused & 1) == 0) {
        val_result = 0;
        pHVar4 = GetDlgItem(hwnd,0x421);
        ShowWindow(pHVar4,val_result);
        val_result = 0;
        pHVar4 = GetDlgItem(hwnd,0x427);
        ShowWindow(pHVar4,val_result);
      }
      FUN_004f570c(hwnd);
      return (HGDIOBJ)0x0;
    }
    if (uMsg == 0x111) {
      local_1c = (uint)wParam & 0xffff;
      if (local_1c < 0x41d) {
        if (local_1c == 0x41c) {
          Ai_CalcManaRequirement_Green(&local_18,hwnd,g_AiHeuristicWeight_CreaturePower);
          InvalidateRect(hwnd,&local_18,1);
          g_AiHeuristicWeight_CreaturePower = 5;
          Ai_CalcManaRequirement_Green(&local_18,hwnd,5);
          InvalidateRect(hwnd,&local_18,0);
          if ((uint)wParam >> 0x10 == 5) {
            pHVar4 = GetDlgItem(hwnd,1);
            SendMessageA(hwnd,0x111,0x10000,(LPARAM)pHVar4);
          }
        }
        else if ((local_1c != 0) && (local_1c < 3)) {
          Ai_CalcManaRequirement_Blue
                    ((int)DAT_00556aa4,(int)DAT_00556a40,0x556980,DAT_00556aa8,DAT_00556a7c,
                     DAT_00556a44);
          if (local_1c == 1) {
            EndDialog(hwnd,g_AiHeuristicWeight_CreaturePower);
          }
          else {
            EndDialog(hwnd,-2);
          }
        }
      }
      else {
        switch(local_1c) {
        case 0x41d:
          Ai_CalcManaRequirement_Green(&local_18,hwnd,g_AiHeuristicWeight_CreaturePower);
          InvalidateRect(hwnd,&local_18,1);
          g_AiHeuristicWeight_CreaturePower = 3;
          Ai_CalcManaRequirement_Green(&local_18,hwnd,3);
          InvalidateRect(hwnd,&local_18,0);
          if ((uint)wParam >> 0x10 == 5) {
            pHVar4 = GetDlgItem(hwnd,1);
            SendMessageA(hwnd,0x111,0x10000,(LPARAM)pHVar4);
          }
          break;
        case 0x41e:
          Ai_CalcManaRequirement_Green(&local_18,hwnd,g_AiHeuristicWeight_CreaturePower);
          InvalidateRect(hwnd,&local_18,1);
          g_AiHeuristicWeight_CreaturePower = 2;
          Ai_CalcManaRequirement_Green(&local_18,hwnd,2);
          InvalidateRect(hwnd,&local_18,0);
          if ((uint)wParam >> 0x10 == 5) {
            pHVar4 = GetDlgItem(hwnd,1);
            SendMessageA(hwnd,0x111,0x10000,(LPARAM)pHVar4);
          }
          break;
        case 0x41f:
          Ai_CalcManaRequirement_Green(&local_18,hwnd,g_AiHeuristicWeight_CreaturePower);
          InvalidateRect(hwnd,&local_18,1);
          g_AiHeuristicWeight_CreaturePower = 4;
          Ai_CalcManaRequirement_Green(&local_18,hwnd,4);
          InvalidateRect(hwnd,&local_18,0);
          if ((uint)wParam >> 0x10 == 5) {
            pHVar4 = GetDlgItem(hwnd,1);
            SendMessageA(hwnd,0x111,0x10000,(LPARAM)pHVar4);
          }
          break;
        case 0x420:
          Ai_CalcManaRequirement_Green(&local_18,hwnd,g_AiHeuristicWeight_CreaturePower);
          InvalidateRect(hwnd,&local_18,1);
          g_AiHeuristicWeight_CreaturePower = 1;
          Ai_CalcManaRequirement_Green(&local_18,hwnd,1);
          InvalidateRect(hwnd,&local_18,0);
          if ((uint)wParam >> 0x10 == 5) {
            pHVar4 = GetDlgItem(hwnd,1);
            SendMessageA(hwnd,0x111,0x10000,(LPARAM)pHVar4);
          }
          break;
        case 0x421:
          Ai_CalcManaRequirement_Green(&local_18,hwnd,g_AiHeuristicWeight_CreaturePower);
          InvalidateRect(hwnd,&local_18,1);
          g_AiHeuristicWeight_CreaturePower = 0;
          Ai_CalcManaRequirement_Green(&local_18,hwnd,0);
          InvalidateRect(hwnd,&local_18,0);
          if ((uint)wParam >> 0x10 == 5) {
            pHVar4 = GetDlgItem(hwnd,1);
            SendMessageA(hwnd,0x111,0x10000,(LPARAM)pHVar4);
          }
          break;
        case 0x428:
          Ai_CalcManaRequirement_Green(&local_18,hwnd,g_AiHeuristicWeight_CreaturePower);
          InvalidateRect(hwnd,&local_18,1);
          g_AiHeuristicWeight_CreaturePower = GetWindowLongA(hwnd,8);
          Ai_CalcManaRequirement_Green(&local_18,hwnd,g_AiHeuristicWeight_CreaturePower);
          InvalidateRect(hwnd,&local_18,0);
          pHVar4 = GetDlgItem(hwnd,1);
          SetFocus(pHVar4);
        }
      }
      return (HGDIOBJ)0x1;
    }
  }
  else if (uMsg < 0x312) {
    if (0x30e < uMsg) {
      pvVar1 = (HGDIOBJ)FUN_004f5d1a(hwnd,uMsg,(HWND)wParam,lParam);
      return pvVar1;
    }
    if (uMsg == 0x201) {
      SendMessageA(hwnd,0x112,0xf012,0);
      return (HGDIOBJ)0x0;
    }
  }
  else if (uMsg == 0x4c8) {
    local_20 = (HWND)wParam;
    local_24 = lParam;
    pHVar4 = GetDlgItem(hwnd,2);
    if (pHVar4 == local_20) {
      SendMessageA(hwnd,0x401,2,0);
    }
    else {
      SendMessageA(hwnd,0x401,1,0);
    }
    if (local_20 != (HWND)0x0) {
      InvalidateRect(local_20,(RECT *)0x0,1);
    }
    if (local_24 != (HWND)0x0) {
      InvalidateRect(local_24,(RECT *)0x0,1);
    }
    return (HGDIOBJ)0x0;
  }
  return (HGDIOBJ)0x0;
}

/*
 * Ai_CalcManaRequirement_Black
 * Purpose: Calculate Black mana requirement for candidate spell.
 * Procedure:
 * 1. Query swamp land count and dark ritual mana.
 * 2. Return available Black mana.
 */
/*
 * Decompiled function: Ai_CalcManaRequirement_Black
 * Entry Point: 004b32d1
 * Size: 557 bytes
 */

void Ai_CalcManaRequirement_Black(int * player, int * color_index, int * required_amount, int * arg4, int * arg5, int * arg6, int * arg7, int * arg8, int * arg9, int * arg10)

{
  int u_res;
  HBRUSH pHVar2;
  HPEN pHVar3;
  HGDIOBJ pvVar4;
  char local_10c [264];
  
  sprintf(local_10c,s__s_WINBK_QuestMana_pic_0052d260,&g_AiCurrentChoiceIndex);
  u_res = Pic_Load_00423833(local_10c);
  *arg1 = u_res;
  *out_buffer = 0x1000031;
  sprintf(local_10c,s__s_WINBK_QuestManaSelection_pic_0052d278,&g_AiCurrentChoiceIndex);
  u_res = Pic_Load_00423833(local_10c);
  *arg3 = u_res;
  sprintf(local_10c,s__s_QUESTMANA_Black_pic_0052d298,&g_AiCurrentChoiceIndex);
  u_res = Pic_Load_00423833(local_10c);
  arg4[1] = u_res;
  sprintf(local_10c,s__s_QUESTMANA_White_pic_0052d2b0,&g_AiCurrentChoiceIndex);
  u_res = Pic_Load_00423833(local_10c);
  arg4[5] = u_res;
  sprintf(local_10c,s__s_QUESTMANA_Green_pic_0052d2c8,&g_AiCurrentChoiceIndex);
  u_res = Pic_Load_00423833(local_10c);
  arg4[3] = u_res;
  sprintf(local_10c,s__s_QUESTMANA_Blue_pic_0052d2e0,&g_AiCurrentChoiceIndex);
  u_res = Pic_Load_00423833(local_10c);
  arg4[2] = u_res;
  sprintf(local_10c,s__s_QUESTMANA_Red_pic_0052d2f8,&g_AiCurrentChoiceIndex);
  u_res = Pic_Load_00423833(local_10c);
  arg4[4] = u_res;
  sprintf(local_10c,s__s_QUESTMANA_Gray_pic_0052d310,&g_AiCurrentChoiceIndex);
  u_res = Pic_Load_00423833(local_10c);
  *arg4 = u_res;
  *arg5 = 0x1000031;
  pHVar2 = CreateSolidBrush(0x10000c6);
  *arg6 = (int)pHVar2;
  pHVar3 = CreatePen(0,0,0x10000c2);
  *arg7 = (int)pHVar3;
  pHVar3 = CreatePen(0,0,0x10000c8);
  *arg_8 = (int)pHVar3;
  *arg_9 = 0x1000031;
  *arg_10 = 0x10000bf;
  if (*arg6 == 0) {
    pvVar4 = GetStockObject(2);
    *arg6 = (int)pvVar4;
  }
  if (*arg7 == 0) {
    pvVar4 = GetStockObject(6);
    *arg7 = (int)pvVar4;
  }
  if (*arg_8 == 0) {
    pvVar4 = GetStockObject(7);
    *arg_8 = (int)pvVar4;
  }
  return;
}

/*
 * Ai_CalcManaRequirement_Blue
 * Purpose: Calculate Blue mana requirement for candidate spell.
 * Procedure:
 * 1. Query island land count and blue mana sources.
 * 2. Return available Blue mana.
 */
/*
 * Decompiled function: Ai_CalcManaRequirement_Blue
 * Entry Point: 004b34fe
 * Size: 182 bytes
 */

void Ai_CalcManaRequirement_Blue(int player, int color_index, int required_amount, HGDIOBJ arg4, HGDIOBJ arg5, HGDIOBJ arg6)

{
  int local_8;
  
  if (arg1 != 0) {
    FUN_004f4548((HANDLE)arg1);
  }
  if (arg2 != 0) {
    FUN_004f4548((HANDLE)arg2);
  }
  for (local_8 = 0; local_8 < 6; local_8 = local_8 + 1) {
    if (*(int *)(arg3 + local_8 * 4) != 0) {
      FUN_004f4548(*(HANDLE *)(arg3 + local_8 * 4));
    }
  }
  if (arg4 != (HGDIOBJ)0x0) {
    DeleteObject(arg4);
  }
  if (arg5 != (HGDIOBJ)0x0) {
    DeleteObject(arg5);
  }
  if (arg6 != (HGDIOBJ)0x0) {
    DeleteObject(arg6);
  }
  return;
}

/*
 * Ai_CalcManaRequirement_Green
 * Purpose: Calculate Green mana requirement for candidate spell.
 * Procedure:
 * 1. Query forest land count and mana elves.
 * 2. Return available Green mana.
 */
/*
 * Decompiled function: Ai_CalcManaRequirement_Green
 * Entry Point: 004b35b4
 * Size: 451 bytes
 */

void Ai_CalcManaRequirement_Green(LPRECT player, HWND color_index, int required_amount)

{
  HWND h_wnd;
  tagRECT *ptVar2;
  tagRECT local_24;
  tagRECT local_14;
  
  if (arg1 != (LPRECT)0x0) {
    if (arg3 == 5) {
      ptVar2 = &local_24;
      h_wnd = GetDlgItem(hwnd,0x41c);
      GetWindowRect(h_wnd,ptVar2);
      ptVar2 = &local_14;
      h_wnd = GetDlgItem(hwnd,0x422);
      GetWindowRect(h_wnd,ptVar2);
    }
    if (arg3 == 2) {
      ptVar2 = &local_24;
      h_wnd = GetDlgItem(hwnd,0x41e);
      GetWindowRect(h_wnd,ptVar2);
      ptVar2 = &local_14;
      h_wnd = GetDlgItem(hwnd,0x423);
      GetWindowRect(h_wnd,ptVar2);
    }
    if (arg3 == 1) {
      ptVar2 = &local_24;
      h_wnd = GetDlgItem(hwnd,0x420);
      GetWindowRect(h_wnd,ptVar2);
      ptVar2 = &local_14;
      h_wnd = GetDlgItem(hwnd,0x424);
      GetWindowRect(h_wnd,ptVar2);
    }
    if (arg3 == 4) {
      ptVar2 = &local_24;
      h_wnd = GetDlgItem(hwnd,0x41f);
      GetWindowRect(h_wnd,ptVar2);
      ptVar2 = &local_14;
      h_wnd = GetDlgItem(hwnd,0x425);
      GetWindowRect(h_wnd,ptVar2);
    }
    if (arg3 == 3) {
      ptVar2 = &local_24;
      h_wnd = GetDlgItem(hwnd,0x41d);
      GetWindowRect(h_wnd,ptVar2);
      ptVar2 = &local_14;
      h_wnd = GetDlgItem(hwnd,0x426);
      GetWindowRect(h_wnd,ptVar2);
    }
    if (arg3 == 0) {
      ptVar2 = &local_24;
      h_wnd = GetDlgItem(hwnd,0x421);
      GetWindowRect(h_wnd,ptVar2);
      ptVar2 = &local_14;
      h_wnd = GetDlgItem(hwnd,0x427);
      GetWindowRect(h_wnd,ptVar2);
    }
    UnionRect(arg1,&local_24,&local_14);
    InflateRect(arg1,0,10);
    MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)arg1,2);
  }
  return;
}

/*
 * Ai_CalcManaRequirement_Red
 * Purpose: Calculate Red mana requirement for candidate spell.
 * Procedure:
 * 1. Query mountain land count and red mana sources.
 * 2. Return available Red mana.
 */
/*
 * Decompiled function: Ai_CalcManaRequirement_Red
 * Entry Point: 004b3777
 * Size: 193 bytes
 */

INT_PTR Ai_CalcManaRequirement_Red(int player, int * color_index, int required_amount, int arg4, uint arg5)

{
  INT_PTR IVar1;
  int local_1c;
  int local_18;
  uint local_14;
  int local_10;
  int local_c;
  
  if (arg1 == 0) {
    local_1c = arg3;
    local_18 = arg4;
    local_14 = arg5;
    local_10 = *arg2;
    local_c = arg2[1];
    IVar1 = DialogBoxParamA(g_AppHInstance,(LPCSTR)0xea,g_MainAppHwnd,Ai_CalcManaRequirement_White,
                            (LPARAM)&local_1c);
    if (IVar1 == -1) {
      IVar1 = -1;
    }
    else if (IVar1 == -2) {
      IVar1 = -1;
    }
  }
  else if (((arg5 & 0xffff) == 0) && (arg4 == 0)) {
    IVar1 = 0;
  }
  else {
    IVar1 = 1;
  }
  return IVar1;
}

/*
 * Ai_CalcManaRequirement_White
 * Purpose: Calculate White mana requirement for candidate spell.
 * Procedure:
 * 1. Query plains land count and white mana sources.
 * 2. Return available White mana.
 */
/*
 * Decompiled function: Ai_CalcManaRequirement_White
 * Entry Point: 004b3847
 * Size: 2379 bytes
 */

HBRUSH Ai_CalcManaRequirement_White(HWND player, uint color_index, HWND required_amount, HWND arg4)

{
  HBRUSH h_wnd;
  HWND pHVar2;
  int nCmdShow;
  BOOL BVar3;
  tagRECT *ptVar4;
  tagRECT local_58;
  HWND local_48;
  int local_44;
  tagRECT local_40;
  COLORREF local_30;
  HWND local_2c;
  HWND local_28;
  int local_24;
  HWND local_20;
  HWND local_18;
  HWND local_14;
  uint local_10;
  int local_c;
  HWND local_8;
  
  if (uMsg < 0x2c) {
    if (uMsg == 0x2b) {
      local_2c = lParam;
      pHVar2 = GetFocus();
      if (pHVar2 == (HWND)local_2c[5].unused) {
        local_30 = DAT_00556aec;
      }
      else if ((local_2c[4].unused & 2) == 0) {
        local_30 = DAT_005569cc;
      }
      else {
        local_30 = 0x10000c6;
      }
      FUN_004f5107((int)local_2c,DAT_00556a78,DAT_005569bc,DAT_00556a60,local_30,0);
      return (HBRUSH)0x1;
    }
    if (uMsg == 0x14) {
      local_48 = wParam;
      FUN_004f3955((HDC)wParam);
      GetClientRect(hwnd,&local_40);
      EnterCriticalSection((LPCRITICAL_SECTION)&g_ActiveCombatRoundCounter);
      local_44 = SaveDC(g_HdcBackBuffer);
      local_48 = (HWND)g_HdcBackBuffer;
      if (DAT_005569b8 == (HANDLE)0x0) {
        h_wnd = GetStockObject(2);
        FillRect((HDC)local_48,&local_40,h_wnd);
      }
      else {
        FUN_004f3b5f((int)g_HdcBackBuffer,(int)&local_40,DAT_005569b8);
      }
      if (DAT_005569c0 != 0xffffffff) {
        ptVar4 = &local_40;
        pHVar2 = GetDlgItem(hwnd,0x474);
        GetWindowRect(pHVar2,ptVar4);
        MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_40,2);
        Palette_Subsystem_0049d843
                  ((HDC)local_48,&local_40.left,(int)(&g_AiDecisionMatrix_Col + DAT_005569c0 * 0x98),
                   DAT_005569b0,DAT_005569b4,0x11,DAT_006fe430);
      }
      RestoreDC(g_HdcBackBuffer,local_44);
      local_48 = wParam;
      GetClientRect(hwnd,&local_40);
      BitBlt((HDC)local_48,0,0,local_40.right,local_40.bottom,g_HdcBackBuffer,0,0,0xcc0020);
      LeaveCriticalSection((LPCRITICAL_SECTION)&g_ActiveCombatRoundCounter);
      return (HBRUSH)0x1;
    }
  }
  else if (uMsg < 0x136) {
    if (uMsg == 0x135) {
LAB_004b3d43:
      local_20 = wParam;
      FUN_004f3955((HDC)wParam);
      local_28 = lParam;
      local_24 = GetDlgCtrlID(lParam);
      if ((local_24 != 0x498) && (local_24 != 0x499)) {
        pHVar2 = GetFocus();
        if (pHVar2 == local_28) {
          SetTextColor((HDC)local_20,DAT_00556aec);
        }
        else {
          SetTextColor((HDC)local_20,DAT_00556ac4);
        }
        SetBkMode((HDC)local_20,1);
        h_wnd = GetStockObject(5);
        return h_wnd;
      }
      SetTextColor((HDC)local_20,DAT_00556ac4);
      SetBkMode((HDC)local_20,1);
      return DAT_00556a78;
    }
    if (uMsg == 0x110) {
      local_8 = lParam;
      Ai_LoadChangeTextBackdrop
                (&DAT_005569b8,&DAT_00556ac4,(int *)&DAT_00556a78,(int *)&DAT_005569bc,
                 (int *)&DAT_00556a60,&DAT_005569cc,&DAT_00556aec);
      SetWindowTextA(hwnd,(LPCSTR)local_8->unused);
      DAT_005569b0 = local_8[3].unused;
      DAT_005569b4 = local_8[4].unused;
      DAT_005569c0 = Ai_EvalAbility_Disenchant(DAT_005569b0,DAT_005569b4);
      nCmdShow = 0;
      pHVar2 = GetDlgItem(hwnd,0x474);
      ShowWindow(pHVar2,nCmdShow);
      if (local_8[2].unused == 0) {
        SetDlgItemTextA(hwnd,0x431,s__Black_0052d328);
        SetDlgItemTextA(hwnd,0x430,s_Bl_ue_0052d330);
        SetDlgItemTextA(hwnd,0x433,s__Green_0052d338);
        SetDlgItemTextA(hwnd,0x432,&DAT_0052d340);
        SetDlgItemTextA(hwnd,0x42f,s__White_0052d348);
        SetDlgItemTextA(hwnd,0x436,s__Black_0052d350);
        SetDlgItemTextA(hwnd,0x435,s_Bl_ue_0052d358);
        SetDlgItemTextA(hwnd,0x438,s__Green_0052d360);
        SetDlgItemTextA(hwnd,0x437,&DAT_0052d368);
        SetDlgItemTextA(hwnd,0x434,s__White_0052d370);
      }
      CheckDlgButton(hwnd,0x42f,1);
      CheckRadioButton(hwnd,0x42f,0x433,0x42f);
      CheckDlgButton(hwnd,0x438,1);
      CheckRadioButton(hwnd,0x434,0x438,0x438);
      SetWindowLongA(hwnd,8,(uint)(ushort)local_8[2].unused << 0x10 | 0x820);
      pHVar2 = GetDlgItem(hwnd,1);
      SetFocus(pHVar2);
      SendMessageA(hwnd,0x401,1,0);
      FUN_004f570c(hwnd);
      return (HBRUSH)0x1;
    }
    if (uMsg == 0x111) {
      local_10 = (uint)wParam & 0xffff;
      local_c = GetWindowLongA(hwnd,8);
      if (local_10 == 1) {
        Ai_ChangeText_FormatOptions((int)DAT_005569b8,DAT_00556a78,DAT_005569bc,DAT_00556a60);
        EndDialog(hwnd,local_c);
      }
      else if (local_10 == 2) {
        Ai_ChangeText_FormatOptions((int)DAT_005569b8,DAT_00556a78,DAT_005569bc,DAT_00556a60);
        EndDialog(hwnd,-2);
      }
      else {
        if (local_10 == 0x431) {
          local_c = local_c & 0xffffff02 | 2;
        }
        else if (local_10 == 0x42f) {
          local_c = local_c & 0xffffff20 | 0x20;
        }
        else if (local_10 == 0x433) {
          local_c = local_c & 0xffffff08 | 8;
        }
        else if (local_10 == 0x430) {
          local_c = local_c & 0xffffff04 | 4;
        }
        else if (local_10 == 0x432) {
          local_c = local_c & 0xffffff10 | 0x10;
        }
        else if (local_10 == 0x436) {
          local_c = local_c & 0xffff02ff | 0x200;
        }
        else if (local_10 == 0x434) {
          local_c = local_c & 0xffff20ff | 0x2000;
        }
        else if (local_10 == 0x438) {
          local_c = local_c & 0xffff08ff | 0x800;
        }
        else if (local_10 == 0x435) {
          local_c = local_c & 0xffff04ff | 0x400;
        }
        else if (local_10 == 0x437) {
          local_c = local_c & 0xffff10ff | 0x1000;
        }
        SetWindowLongA(hwnd,8,local_c);
        if ((((char)local_c == '\0') || (local_c._1_1_ == '\0')) ||
           ((local_c & 0xffff) >> 8 == (local_c & 0xff))) {
          BVar3 = 0;
          pHVar2 = GetDlgItem(hwnd,1);
          EnableWindow(pHVar2,BVar3);
        }
        else {
          BVar3 = 1;
          pHVar2 = GetDlgItem(hwnd,1);
          EnableWindow(pHVar2,BVar3);
        }
      }
      return (HBRUSH)0x1;
    }
  }
  else if (uMsg < 0x201) {
    if (uMsg == 0x200) {
LAB_004b3ffd:
      if (((uMsg == 0x200) && (g_DuelArenaStatusFlags != 2)) || ((uMsg == 0x204 && (g_DuelArenaStatusFlags == 2)))) {
        ptVar4 = &local_58;
        pHVar2 = GetDlgItem(hwnd,0x474);
        GetWindowRect(pHVar2,ptVar4);
        MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_58,2);
        if ((DAT_005569c0 != 0xffffffff) &&
           (BVar3 = PtInRect(&local_58,
                             (POINT)(CONCAT44((uint)lParam >> 0x10,lParam) & 0xffffffff0000ffff)),
           BVar3 != 0)) {
          SendMessageA(g_MainAppWindow,0x401,DAT_005569c0,0);
        }
      }
      return (HBRUSH)0x0;
    }
    if (uMsg == 0x138) goto LAB_004b3d43;
  }
  else if (uMsg < 0x205) {
    if (uMsg == 0x204) goto LAB_004b3ffd;
    if (uMsg == 0x201) {
      SendMessageA(hwnd,0x112,0xf012,0);
      return (HBRUSH)0x0;
    }
  }
  else if (0x30e < uMsg) {
    if (uMsg < 0x312) {
      h_wnd = (HBRUSH)FUN_004f5d1a(hwnd,uMsg,wParam,lParam);
      return h_wnd;
    }
    if (uMsg == 0x4c8) {
      local_14 = wParam;
      local_18 = lParam;
      pHVar2 = GetDlgItem(hwnd,2);
      if (pHVar2 == local_14) {
        SendMessageA(hwnd,0x401,2,0);
      }
      else {
        SendMessageA(hwnd,0x401,1,0);
      }
      if (local_14 != (HWND)0x0) {
        InvalidateRect(local_14,(RECT *)0x0,1);
      }
      if (local_18 != (HWND)0x0) {
        InvalidateRect(local_18,(RECT *)0x0,1);
      }
      return (HBRUSH)0x0;
    }
  }
  return (HBRUSH)0x0;
}

/*
 * Ai_LoadChangeTextBackdrop
 * Purpose: Load card text modification dialog backdrop art.
 * Procedure:
 * 1. Load WINBK_ChangeText.pic into dialog surface.
 */
/*
 * Decompiled function: Ai_LoadChangeTextBackdrop
 * Entry Point: 004b4197
 * Size: 221 bytes
 */

void Ai_LoadChangeTextBackdrop(int * arg1, int * out_buffer, int * arg3, int * arg4, int * arg5, int * arg6, int * arg7)

{
  int u_res;
  HBRUSH pHVar2;
  HPEN pHVar3;
  HGDIOBJ pvVar4;
  char local_10c [264];
  
  sprintf(local_10c,s__s_WINBK_ChangeText_pic_0052d378,&g_AiCurrentChoiceIndex);
  u_res = Pic_Load_00423833(local_10c);
  *arg1 = u_res;
  *out_buffer = 0x1000098;
  pHVar2 = CreateSolidBrush(0x1000076);
  *arg3 = (int)pHVar2;
  pHVar3 = CreatePen(0,0,0x10000b3);
  *arg4 = (int)pHVar3;
  pHVar3 = CreatePen(0,0,0x100004e);
  *arg5 = (int)pHVar3;
  *arg6 = 0x1000098;
  *arg7 = 0x10000bf;
  if (*arg3 == 0) {
    pvVar4 = GetStockObject(2);
    *arg3 = (int)pvVar4;
  }
  if (*arg4 == 0) {
    pvVar4 = GetStockObject(6);
    *arg4 = (int)pvVar4;
  }
  if (*arg5 == 0) {
    pvVar4 = GetStockObject(7);
    *arg5 = (int)pvVar4;
  }
  return;
}

/*
 * Ai_ChangeText_FormatOptions
 * Purpose: Format text modification options for Sleight of Mind / Magical Hack.
 * Procedure:
 * 1. Display selectable color or basic land type words.
 */
/*
 * Decompiled function: Ai_ChangeText_FormatOptions
 * Entry Point: 004b4274
 * Size: 93 bytes
 */

void Ai_ChangeText_FormatOptions(int x, HGDIOBJ arg2, HGDIOBJ arg3, HGDIOBJ arg4)

{
  if (x != 0) {
    FUN_004f4548((HANDLE)x);
  }
  if (arg2 != (HGDIOBJ)0x0) {
    DeleteObject(arg2);
  }
  if (arg3 != (HGDIOBJ)0x0) {
    DeleteObject(arg3);
  }
  if (arg4 != (HGDIOBJ)0x0) {
    DeleteObject(arg4);
  }
  return;
}

/*
 * Ai_ChangeText_ResetState
 * Purpose: Reset text modification selection buffer.
 * Procedure:
 * 1. Clear selected color word buffer.
 */
/*
 * Decompiled function: Ai_ChangeText_ResetState
 * Entry Point: 004b42d1
 * Size: 11 bytes
 */

void Ai_ChangeText_ResetState(void)

{
  return;
}

/*
 * Ai_ChangeText_ApplyWord
 * Purpose: Apply modified color or land type word to target card.
 * Procedure:
 * 1. Update card text color flags in target card slot.
 */
/*
 * Decompiled function: Ai_ChangeText_ApplyWord
 * Entry Point: 004b42dc
 * Size: 1891 bytes
 */

uint Ai_ChangeText_ApplyWord(void)

{
  int status;
  int val_result;
  uint u_score;
  uint u_val;
  uint u_extra;
  uint uVar6;
  int uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int local_10;
  int local_c;
  uint local_8;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  local_8 = memcmp(&DAT_0068a730,&g_ActiveCardsInPlay,0xb640);
  memcpy(&DAT_0068a730,&g_ActiveCardsInPlay,0xb640);
  if ((g_PlayerActiveCardCount != DAT_006a29c8) || (DAT_006808bc != DAT_006a29cc)) {
    local_8 = 1;
  }
  DAT_006a29c8 = g_PlayerActiveCardCount;
  DAT_006a29cc = DAT_006808bc;
  if ((g_PlayerCreatureCount != DAT_006a3f7c) || (DAT_006a4a04 != DAT_006ff194)) {
    local_8 = 1;
  }
  DAT_006a3f7c = g_PlayerCreatureCount;
  DAT_006ff194 = DAT_006a4a04;
  if ((DAT_00696870 != DAT_00695ed8) || (DAT_00696874 != DAT_007006d8)) {
    local_8 = 1;
  }
  DAT_00695ed8 = DAT_00696870;
  DAT_007006d8 = DAT_00696874;
  u_score = memcmp(&DAT_0069f6e0,&g_AiLookaheadDepth,0x1c);
  u_val = memcmp(&DAT_00695ee0,&DAT_0063eeb0,0x1c);
  memcpy(&DAT_0069f6e0,&g_AiLookaheadDepth,0x1c);
  memcpy(&DAT_00695ee0,&DAT_0063eeb0,0x1c);
  u_extra = memcmp(&DAT_00695f20,&g_AiEvaluationPassCounter,2000);
  uVar6 = memcmp(&DAT_006fd400,&DAT_006ffee0,2000);
  DAT_006ff1a0 = 0;
  for (local_c = 0; (local_c < 500 && (*(int *)(&g_AiEvaluationPassCounter + local_c * 4) != -1));
      local_c = local_c + 1) {
    uVar7 = Ai_Subsystem_004cbd67(*(uint *)(&g_AiEvaluationPassCounter + local_c * 4));
    (&DAT_00695f20)[DAT_006ff1a0] = uVar7;
    DAT_006ff1a0 = DAT_006ff1a0 + 1;
  }
  DAT_007006b4 = 0;
  for (local_c = 0; (local_c < 500 && (*(int *)(&DAT_006ffee0 + local_c * 4) != -1));
      local_c = local_c + 1) {
    uVar7 = Ai_Subsystem_004cbd67(*(uint *)(&DAT_006ffee0 + local_c * 4));
    (&DAT_006fd400)[DAT_007006b4] = uVar7;
    DAT_007006b4 = DAT_007006b4 + 1;
  }
  uVar8 = memcmp(&DAT_006fe4a0,&g_AiTemporaryBuffer_006b1590,2000);
  uVar9 = memcmp(&DAT_006a4f80,&DAT_006b1d60,2000);
  DAT_006ff2e4 = 0;
  for (local_c = 0; (local_c < 500 && (*(int *)(&g_AiTemporaryBuffer_006b1590 + local_c * 4) != -1));
      local_c = local_c + 1) {
    uVar7 = Ai_Subsystem_004cbd67(*(uint *)(&g_AiTemporaryBuffer_006b1590 + local_c * 4));
    (&DAT_006fe4a0)[DAT_006ff2e4] = uVar7;
    DAT_006ff2e4 = DAT_006ff2e4 + 1;
  }
  DAT_006b2d34 = 0;
  for (local_c = 0; (local_c < 500 && (*(int *)(&DAT_006b1d60 + local_c * 4) != -1));
      local_c = local_c + 1) {
    uVar7 = Ai_Subsystem_004cbd67(*(uint *)(&DAT_006b1d60 + local_c * 4));
    (&DAT_006a4f80)[DAT_006b2d34] = uVar7;
    DAT_006b2d34 = DAT_006b2d34 + 1;
  }
  uVar10 = memcmp(&DAT_006b2550,&g_AiLookaheadTreeCurrentNode,2000);
  uVar11 = memcmp(&DAT_006fdbe0,&DAT_0069ef00,2000);
  local_8 = local_8 | u_score | u_val | u_extra | uVar6 | uVar8 | uVar9 | uVar10 | uVar11;
  DAT_006b2d30 = 0;
  for (local_c = 0; (local_c < 500 && (*(int *)(&g_AiLookaheadTreeCurrentNode + local_c * 4) != -1));
      local_c = local_c + 1) {
    uVar7 = Ai_Subsystem_004cbd67(*(uint *)(&g_AiLookaheadTreeCurrentNode + local_c * 4));
    (&DAT_006b2550)[DAT_006b2d30] = uVar7;
    DAT_006b2d30 = DAT_006b2d30 + 1;
  }
  DAT_006b2e20 = 0;
  for (local_c = 0; (local_c < 500 && (*(int *)(&DAT_0069ef00 + local_c * 4) != -1));
      local_c = local_c + 1) {
    uVar7 = Ai_Subsystem_004cbd67(*(uint *)(&DAT_0069ef00 + local_c * 4));
    (&DAT_006fdbe0)[DAT_006b2e20] = uVar7;
    DAT_006b2e20 = DAT_006b2e20 + 1;
  }
  g_AiCandidateActionCount = 0;
  for (local_c = 0; ((&DAT_006fecc0)[local_c * 2] != -1 && (local_c < 0x20)); local_c = local_c + 1)
  {
    if (*(int *)(&DAT_00695d70 + local_c * 4) != 0) {
      status = (&DAT_006fecc0)[local_c * 2];
      val_result = *(int *)(&DAT_006fecc4 + local_c * 8);
      (&DAT_006a29e0)[g_AiCandidateActionCount * 0x2b] = status;
      (&DAT_006a29e4)[g_AiCandidateActionCount * 0x2b] = val_result;
      (&DAT_006a2a88)[g_AiCandidateActionCount * 0x2b] =
           (int)(char)(&g_CardSlot_TurnPlayed)[val_result * 0x120 + status * 0x5b20];
      for (local_10 = 0; local_10 < (char)(&g_CardSlot_TurnPlayed)[val_result * 0x120 + status * 0x5b20];
          local_10 = local_10 + 1) {
        *(int *)(&DAT_006a29e8 + local_10 * 8 + g_AiCandidateActionCount * 0xac) =
             *(int *)
              (&g_CardSlot_CombatTarget + val_result * 0x120 + status * 0x5b20 + local_10 * 8);
        *(int *)(&DAT_006a29ec + local_10 * 8 + g_AiCandidateActionCount * 0xac) =
             *(int *)
              (&g_CardSlot_AttachedAura + val_result * 0x120 + status * 0x5b20 + local_10 * 8);
      }
      g_AiCandidateActionCount = g_AiCandidateActionCount + 1;
    }
  }
  DAT_0069f740 = 0;
  for (local_c = 0; (local_c < 0x10 && ((&DAT_006b2dd0)[local_c] != -1)); local_c = local_c + 1) {
    DAT_0069f740 = DAT_0069f740 + 1;
  }
  memcpy(&DAT_006fec70,&DAT_006b2dd0,0x40);
  DAT_00701004 = 0;
  for (local_c = 0; (local_c < 0x10 && ((&g_AiSelectedAbilityIndex)[local_c] != -1)); local_c = local_c + 1) {
    DAT_00701004 = DAT_00701004 + 1;
  }
  memcpy(&DAT_006ff6d0,&g_AiSelectedAbilityIndex,0x40);
  for (local_c = 0; local_c < 0x26; local_c = local_c + 1) {
    if (*(int *)(&DAT_00696740 + local_c * 4) != *(int *)(&DAT_006fedd0 + local_c * 4)) {
      local_8 = local_8 | 1;
    }
    if (*(int *)(&DAT_006967d8 + local_c * 4) != *(int *)(&DAT_006a4940 + local_c * 4)) {
      local_8 = local_8 | 1;
    }
    *(uint *)(&DAT_006fedd0 + local_c * 4) = *(uint *)(&DAT_00696740 + local_c * 4) & 1;
    *(uint *)(&DAT_006a4940 + local_c * 4) = *(uint *)(&DAT_006967d8 + local_c * 4) & 1;
  }
  if (DAT_0063ee10 != DAT_0068077c) {
    local_8 = 1;
  }
  DAT_0068077c = DAT_0063ee10;
  LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  return local_8;
}

/*
 * Ai_EvalAttackCandidate_CombatTrade
 * Purpose: Evaluate combat trade value for attacking creature candidate.
 * Procedure:
 * 1. Simulate damage exchange with defending creatures.
 * 2. Score positive if creature survives or kills high-value blocker.
 */
/*
 * Decompiled function: Ai_EvalAttackCandidate_CombatTrade
 * Entry Point: 004b4a3f
 * Size: 2402 bytes
 */

void Ai_EvalAttackCandidate_CombatTrade(int player, uint attacker_idx)

{
  HBRUSH h_wnd;
  int val_result;
  BOOL BVar3;
  uint u_val;
  HWND local_50;
  HWND local_4c;
  int local_48;
  HWND local_44;
  HWND local_40;
  HWND local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  uint local_18;
  int local_14;
  int local_10;
  uint local_c;
  WPARAM local_8;
  
  h_wnd = GetStockObject(0);
  FUN_004f5048(s_CD_struct_0052d390,0xff0000,h_wnd);
  KillTimer(g_MainAppHwnd,DAT_006fdbd4);
  EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  if (DAT_0068a678 != DAT_006ff2d8) {
    DAT_0068a678 = DAT_006ff2d8;
    InvalidateRect(g_AiEvaluationLock,(RECT *)0x0,0);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  local_10 = Ai_ChangeText_ApplyWord();
  EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  for (local_14 = 0; local_14 < 2; local_14 = local_14 + 1) {
    for (local_24 = 0; local_24 < 0x50; local_24 = local_24 + 1) {
      val_result = Ai_EvalAbility_Disenchant(local_14,local_24);
      if (val_result == DAT_006ff2e8) {
        *(uint *)(&g_AiEvaluationTimeout + local_24 * 0x120 + local_14 * 0x5b20) =
             *(uint *)(&g_AiEvaluationTimeout + local_24 * 0x120 + local_14 * 0x5b20) & 0xfffffffd;
      }
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  if ((arg2 == 0) || ((arg2 & 0x30) != 0)) {
    if (local_10 != 0) {
      for (local_14 = 0; local_14 < 2; local_14 = local_14 + 1) {
        for (local_24 = 0; local_24 < 0x50; local_24 = local_24 + 1) {
          local_30 = local_14;
          local_2c = local_24;
          local_20 = Ai_EvalAbility_BoardWipe(local_14,local_24);
          local_1c = Ai_EvalAbility_LifeGain(local_14,local_24);
          local_28 = Ai_EvalAbility_Disenchant(local_14,local_24);
          local_18 = Ai_Subsystem_004b6c5b(local_14,local_24);
          local_c = Ai_EvalAbility_LandDestruction(local_14,local_24);
          if (((local_1c == -1) || (((local_18 & 0x10000) != 0 && (DAT_006fe43c == 0)))) ||
             ((local_1c == DAT_006ff2e0 &&
              (val_result = Ai_EvalAbility_DirectDamage(local_14,local_24), val_result == 0)))) {
            SendMessageA(g_AiLookaheadTreeRoot,0x40b,(WPARAM)&local_30,0);
            SendMessageA(g_AiDuelTurnState,0x40b,(WPARAM)&local_30,0);
            SendMessageA(g_TurnPriorityState,0x40b,(WPARAM)&local_30,0);
            SendMessageA(g_AiSelectedActionCode,0x40b,(WPARAM)&local_30,0);
            SendMessageA(g_MainAppWindow,0x40b,(WPARAM)&local_30,0);
            BVar3 = IsWindowVisible(g_AiDecisionMatrix_Row);
            if ((BVar3 != 0) || (val_result = Ai_Subsystem_004b7629(), val_result != 0)) {
              SendMessageA(g_AiDecisionMatrix_Row,0x403,(WPARAM)&local_30,0);
              SendMessageA(g_AiDecisionMatrix_Row,0x402,(WPARAM)&local_30,0);
            }
          }
          else if (local_20 == 2) {
            SendMessageA(g_AiLookaheadTreeRoot,0x40b,(WPARAM)&local_30,0);
            SendMessageA(g_AiDuelTurnState,0x40b,(WPARAM)&local_30,0);
            SendMessageA(g_TurnPriorityState,0x40b,(WPARAM)&local_30,0);
            SendMessageA(g_AiSelectedActionCode,0x40b,(WPARAM)&local_30,0);
          }
          else if (local_1c != DAT_006fd3f4) {
            if (local_20 == 1) {
              SendMessageA(g_AiLookaheadTreeRoot,0x40b,(WPARAM)&local_30,0);
              SendMessageA(g_AiDuelTurnState,0x40b,(WPARAM)&local_30,0);
              if (((local_c & 0x10) == 0) ||
                 ((local_28 < DAT_00695e94 &&
                  ((*(int *)(&DAT_006b3084 + local_28 * 0x98) != 2 ||
                   (*(int *)(&DAT_006b3088 + local_28 * 0x98) == 0xda)))))) {
                if (local_14 == 0) {
                  local_44 = g_AiSelectedActionCode;
                  local_3c = g_TurnPriorityState;
                }
                else {
                  local_44 = g_TurnPriorityState;
                  local_3c = g_AiSelectedActionCode;
                }
                SendMessageA(local_44,0x40b,(WPARAM)&local_30,0);
                SendMessageA(local_3c,0x40a,(WPARAM)&local_30,0);
              }
              else {
                Ai_EvalAbility_ManaRamp(&local_38,local_14,local_24);
                while (((u_val = Ai_EvalAbility_LandDestruction(local_38,local_34), (u_val & 0x10) != 0 &&
                        (local_28 = Ai_EvalAbility_Disenchant(local_38,local_34), local_28 != -1)) &&
                       ((DAT_00695e94 <= local_28 ||
                        ((*(int *)(&DAT_006b3084 + local_28 * 0x98) == 2 &&
                         (*(int *)(&DAT_006b3088 + local_28 * 0x98) != 0xda))))))) {
                  Ai_EvalAbility_ManaRamp(&local_38,local_38,local_34);
                }
                if (local_38 == 0) {
                  local_44 = g_AiSelectedActionCode;
                  local_3c = g_TurnPriorityState;
                }
                else {
                  local_44 = g_TurnPriorityState;
                  local_3c = g_AiSelectedActionCode;
                }
                SendMessageA(local_44,0x40b,(WPARAM)&local_30,0);
                SendMessageA(local_3c,0x40a,(WPARAM)&local_30,0);
                val_result = FUN_00483139(g_AiDecisionMatrix_Row,&local_38,(int *)0x0,&local_40,
                                     (int *)0x0);
                if (val_result != 0) {
                  SendMessageA(g_AiDecisionMatrix_Row,0x406,(WPARAM)&local_30,(LPARAM)local_40);
                  SendMessageA(g_AiDecisionMatrix_Row,0x410,(WPARAM)local_40,0);
                  local_8 = 1;
                  val_result = Duel_HitTestCardSlot(local_3c,&local_38,(int *)0x0,&local_40);
                  if (((val_result != 0) && (BVar3 = IsWindowVisible(local_40), BVar3 == 0)) &&
                     (val_result = Duel_HitTestCardSlot(local_3c,&local_30,(int *)0x0,&local_40),
                     val_result != 0)) {
                    ShowWindow(local_40,0);
                  }
                }
              }
            }
            else if (local_20 == 0) {
              SendMessageA(g_TurnPriorityState,0x40b,(WPARAM)&local_30,0);
              SendMessageA(g_AiSelectedActionCode,0x40b,(WPARAM)&local_30,0);
              if (local_14 == 0) {
                local_4c = g_AiDuelTurnState;
              }
              else {
                local_4c = g_AiLookaheadTreeRoot;
              }
              SendMessageA(local_4c,0x40b,(WPARAM)&local_30,0);
              if (local_14 == 0) {
                local_50 = g_AiLookaheadTreeRoot;
              }
              else {
                local_50 = g_AiDuelTurnState;
              }
              SendMessageA(local_50,0x40a,(WPARAM)&local_30,0);
            }
          }
        }
      }
    }
    SendMessageA(g_TurnPriorityState,0x400,0,0);
    SendMessageA(g_AiSelectedActionCode,0x400,0,0);
    h_wnd = GetStockObject(1);
    FUN_004f5048(s_Align_Attack_Spell_0052d39c,0xff0000,h_wnd);
    Ai_Subsystem_004b74b1((int *)0x0,&local_48);
    if ((local_48 < 0x15) || (0x1d < local_48)) {
      SendMessageA(g_AiDecisionMatrix_Row,0x40c,0,0);
    }
    else {
      SendMessageA(g_AiDecisionMatrix_Row,0x412,local_8,0);
    }
    SendMessageA(DAT_006fe3fc,0x412,0,0);
  }
  SendMessageA(g_TurnPriorityState,0x412,0,0);
  SendMessageA(g_AiSelectedActionCode,0x412,0,0);
  if ((arg2 == 0) || ((arg2 & 0x20) != 0)) {
    h_wnd = GetStockObject(2);
    FUN_004f5048(s_Refresh_0052d3b0,0xff0000,h_wnd);
    SendMessageA(g_AiLookaheadTreeRoot,0x432,0,0);
    SendMessageA(g_AiDuelTurnState,0x432,0,0);
    SendMessageA(g_TurnPriorityState,0x432,0,0);
    SendMessageA(g_AiSelectedActionCode,0x432,0,0);
    BVar3 = IsWindowVisible(g_AiDecisionMatrix_Row);
    if (BVar3 != 0) {
      SendMessageA(g_AiDecisionMatrix_Row,0x432,0,0);
      UpdateWindow(g_AiDecisionMatrix_Row);
    }
    BVar3 = IsWindowVisible(DAT_006fe3fc);
    if (BVar3 != 0) {
      SendMessageA(DAT_006fe3fc,0x432,0,0);
      UpdateWindow(DAT_006fe3fc);
    }
    SendMessageA(g_MainAppWindow,0x432,0,0);
  }
  SendMessageA(DAT_006b2530,0x432,0,0);
  SendMessageA(DAT_006ff4a8,0x432,0,0);
  SendMessageA(g_AiSelectedCardTargetSlot,0x432,0,0);
  SendMessageA(DAT_006ff560,0x432,0,0);
  SendMessageA(DAT_006fe48c,0x432,0,0);
  SendMessageA(DAT_006ff388,0x432,0,0);
  SendMessageA(DAT_006b2e10,0x432,0,0);
  SendMessageA(DAT_006a4928,0x432,0,0);
  h_wnd = GetStockObject(0);
  FUN_004f5048(&DAT_0052d3b8,0xff0000,h_wnd);
  UpdateWindow(g_MainAppHwnd);
  return;
}

/*
 * Ai_Eval_ClearCandidateBuffer
 * Purpose: Clear evaluation candidate score buffer.
 * Procedure:
 * 1. Zero out candidate score list.
 */
/*
 * Decompiled function: Ai_Eval_ClearCandidateBuffer
 * Entry Point: 004b53a1
 * Size: 37 bytes
 */

void Ai_Eval_ClearCandidateBuffer(void)

{
  return;
}

/*
 * Ai_Eval_GetCandidateScore
 * Purpose: Get evaluation score for candidate card index.
 * Procedure:
 * 1. Return cached score value for card index.
 */
/*
 * Decompiled function: Ai_Eval_GetCandidateScore
 * Entry Point: 004b53c6
 * Size: 39 bytes
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int Ai_Eval_GetCandidateScore(void)

{
  _DAT_006498e8 = GetTickCount();
  _DAT_00696738 = 0;
  return 0;
}

/*
 * Ai_Eval_SetCandidateScore
 * Purpose: Store evaluation score for candidate card index.
 * Procedure:
 * 1. Write score value to candidate score array.
 */
/*
 * Decompiled function: Ai_Eval_SetCandidateScore
 * Entry Point: 004b53ed
 * Size: 64 bytes
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint Ai_Eval_SetCandidateScore(void)

{
  DWORD DVar1;
  
  DVar1 = GetTickCount();
  return ((DVar1 - _DAT_006498e8) - _DAT_00696738) / 0x37;
}

/*
 * Ai_Eval_GetBestCandidate
 * Purpose: Find candidate card index with highest evaluation score.
 * Procedure:
 * 1. Iterate through candidate scores and return maximum index.
 */
/*
 * Decompiled function: Ai_Eval_GetBestCandidate
 * Entry Point: 004b542d
 * Size: 16 bytes
 */

void Ai_Eval_GetBestCandidate(void)

{
  return;
}

/*
 * Ai_Eval_ResetBestCandidate
 * Purpose: Reset best candidate tracking registers.
 * Procedure:
 * 1. Set best score to minimum integer value.
 */
/*
 * Decompiled function: Ai_Eval_ResetBestCandidate
 * Entry Point: 004b543d
 * Size: 16 bytes
 */

void Ai_Eval_ResetBestCandidate(void)

{
  return;
}

/*
 * Ai_Eval_SortCandidates
 * Purpose: Sort candidate cards by evaluated score descending.
 * Procedure:
 * 1. Sort card indices using insertion sort on score array.
 */
/*
 * Decompiled function: Ai_Eval_SortCandidates
 * Entry Point: 004b544d
 * Size: 180 bytes
 */

int Ai_Eval_SortCandidates(void)

{
  LRESULT LVar1;
  int val_result;
  int local_c [2];
  
  if ((g_AiTurnDecisionFlag == 0) && (LVar1 = SendMessageA(g_AiDecisionMatrix_Row,0x411,0,0), LVar1 != 0)) {
    if (DAT_0069f6d0 == 0) {
      do {
        val_result = Action_ValidateTarget_00405802
                          (0,0,1,0x200,2,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0,0,0x10,
                           s_Choose_defenders_0052d3bc,2,local_c);
      } while (val_result != 0);
    }
    SendMessageA(g_AiDecisionMatrix_Row,0x412,0,0);
  }
  return 0;
}

/*
 * Ai_EvalAbility_Flying
 * Purpose: Evaluate tactical impact of Flying evasion ability.
 * Procedure:
 * 1. Check if opponent controls flying or reach creatures.
 * 2. Grant high evasion score bonus if unblockable.
 */
/*
 * Decompiled function: Ai_EvalAbility_Flying
 * Entry Point: 004b5501
 * Size: 62 bytes
 */

void Ai_EvalAbility_Flying(char * player)

{
  char *local_8;
  
  if (prompt_text == (char *)0x0) {
    local_8 = &DAT_0052d3d0;
  }
  else {
    local_8 = prompt_text;
  }
  FUN_00477d73(DAT_007006b0,local_8,0);
  return;
}

/*
 * Ai_EvalAbility_Trample
 * Purpose: Evaluate tactical impact of Trample damage ability.
 * Procedure:
 * 1. Calculate excess damage penetrating through blockers to player.
 * 2. Add trample score bonus to creature value.
 */
/*
 * Decompiled function: Ai_EvalAbility_Trample
 * Entry Point: 004b553f
 * Size: 526 bytes
 */

void Ai_EvalAbility_Trample(char * player)

{
  int status;
  int local_28;
  tagPOINT local_24;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  char *local_8;
  
  if (prompt_text == (char *)0x0) {
    local_8 = &DAT_0052d3d4;
  }
  else {
    local_8 = prompt_text;
  }
  if (g_DuelArenaStatusFlags != 0) {
    if (*local_8 == '\0') {
      ShowWindow(g_AiPlayerHandDifferential,0);
      SetWindowTextA(g_AiPlayerHandDifferential,local_8);
    }
    else {
      local_10 = GetSystemMetrics(0);
      local_c = GetSystemMetrics(1);
      if (DAT_006fe424 == 0) {
        status = GetSystemMetrics(1);
        if ((status * 3) / 100 < 0x13) {
          local_28 = 0x12;
        }
        else {
          status = GetSystemMetrics(1);
          local_28 = (status * 3) / 100;
        }
        local_1c = FUN_004f4eb3(g_AiPlayerHandDifferential,local_8);
        local_1c = local_1c + local_28 * 2;
        local_14 = (local_10 - (local_10 * 0x14) / 100) - local_1c;
        local_18 = (local_c - local_28) / 2;
      }
      else {
        status = GetSystemMetrics(1);
        if ((status * 2) / 100 < 0xd) {
          local_28 = 0xc;
        }
        else {
          status = GetSystemMetrics(1);
          local_28 = (status * 2) / 100;
        }
        local_1c = FUN_004f4eb3(g_AiPlayerHandDifferential,local_8);
        local_1c = local_1c + local_28 * 2;
        GetCursorPos(&local_24);
        status = GetSystemMetrics(0xe);
        local_24.y = local_24.y + status;
        if (local_10 < local_24.x + local_1c) {
          local_24.x = local_10 - local_1c;
        }
        if (local_c < local_24.y + local_28) {
          local_24.y = local_c - local_28;
        }
        local_14 = local_24.x;
        local_18 = local_24.y;
      }
      SetWindowPos(g_AiPlayerHandDifferential,(HWND)0x0,local_14,local_18,local_1c,local_28,4);
      SetWindowTextA(g_AiPlayerHandDifferential,local_8);
      ShowWindow(g_AiPlayerHandDifferential,5);
      BringWindowToTop(g_AiPlayerHandDifferential);
    }
  }
  return;
}

/*
 * Ai_EvalAbility_FirstStrike
 * Purpose: Evaluate tactical impact of First Strike combat ability.
 * Procedure:
 * 1. Simulate combat priority damage before normal strike.
 * 2. Add survival score bonus if first strike kills blocker.
 */
/*
 * Decompiled function: Ai_EvalAbility_FirstStrike
 * Entry Point: 004b574d
 * Size: 252 bytes
 */

int Ai_EvalAbility_FirstStrike(int player, int card_index, int target_player, int action_flags, int arg5, int arg6)

{
  int status;
  INT_PTR IVar2;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  
  KillTimer(g_MainAppHwnd,DAT_006fdbd4);
  if (arg4 == 0xff) {
    arg4 = -1;
  }
  if ((arg1 != -1) && (arg2 != -1)) {
    status = Ai_EvalAbility_Disenchant(arg1,arg2);
    if (status == -1) {
      Ai_ChangeText_ApplyWord();
    }
  }
  if ((arg3 != -1) && (arg4 != -1)) {
    status = Ai_EvalAbility_Disenchant(arg3,arg4);
    if (status == -1) {
      Ai_ChangeText_ApplyWord();
    }
  }
  local_20 = arg1;
  local_1c = arg2;
  local_18 = arg3;
  local_14 = arg4;
  local_10 = arg5;
  local_c = arg6;
  IVar2 = DialogBoxParamA(g_AppHInstance,(LPCSTR)0xdf,g_MainAppHwnd,
                          UI_Register_MAGICGAME_BigCardCardClass_00401000,(LPARAM)&local_20);
  if (IVar2 == 0) {
    status = -1;
  }
  else {
    status = IVar2 + -1;
  }
  return status;
}

/*
 * Ai_EvalAbility_Regeneration
 * Purpose: Evaluate tactical value of regenerating creature.
 * Procedure:
 * 1. Check available mana for regeneration cost.
 * 2. Score preservation of high-value creature.
 */
/*
 * Decompiled function: Ai_EvalAbility_Regeneration
 * Entry Point: 004b584e
 * Size: 139 bytes
 */

int Ai_EvalAbility_Regeneration(void)

{
  if (g_IsAiThinking != 1) {
    EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
    memcpy(&DAT_0069f6e0,&g_AiLookaheadDepth,0x1c);
    memcpy(&DAT_00695ee0,&DAT_0063eeb0,0x1c);
    LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
    SendMessageA(g_AiSelectedCardTargetSlot,0x432,0,0);
    SendMessageA(DAT_006ff560,0x432,0,0);
  }
  return 0;
}

/*
 * Ai_EvalAbility_Protection
 * Purpose: Evaluate tactical value of Protection from Color.
 * Procedure:
 * 1. Check if opponent plays matching color permanents.
 * 2. Add complete damage immunity bonus score.
 */
/*
 * Decompiled function: Ai_EvalAbility_Protection
 * Entry Point: 004b58d9
 * Size: 64 bytes
 */

void Ai_EvalAbility_Protection(int player)

{
  int local_8;
  
  if (arg1 == 0) {
    local_8 = DAT_006fe48c;
  }
  else {
    local_8 = DAT_006ff388;
  }
  SendMessageA(local_8,0x400,0,0);
  return;
}

/*
 * Ai_EvalAbility_Landwalk
 * Purpose: Evaluate tactical value of Landwalk evasion ability.
 * Procedure:
 * 1. Check if opponent controls matching basic land type.
 * 2. Grant unblockable attacking score bonus.
 */
/*
 * Decompiled function: Ai_EvalAbility_Landwalk
 * Entry Point: 004b5919
 * Size: 78 bytes
 */

int Ai_EvalAbility_Landwalk(int player, int card_index)

{
  int u_res;
  
  if ((arg1 == 0) || (arg1 == 1)) {
    if ((arg2 < 0) || (0x50 < arg2)) {
      u_res = 1;
    }
    else {
      u_res = 0;
    }
  }
  else {
    u_res = 1;
  }
  return u_res;
}

/*
 * Ai_EvalAbility_Deathtouch
 * Purpose: Evaluate tactical value of lethal combat damage (Basilisk/Venom).
 * Procedure:
 * 1. Score ability to destroy any blocking creature regardless of toughness.
 */
/*
 * Decompiled function: Ai_EvalAbility_Deathtouch
 * Entry Point: 004b5967
 * Size: 114 bytes
 */

uint Ai_EvalAbility_Deathtouch(int player, int card_index)

{
  int status;
  uint u_temp;
  
  status = Ai_EvalAbility_Landwalk(arg1,arg2);
  if (status == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
    u_temp = *(uint *)(&DAT_0068a768 + arg2 * 0x120 + arg1 * 0x5b20) & 0xff00;
    LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  }
  else {
    u_temp = 0;
  }
  return u_temp;
}

/*
 * Ai_EvalAbility_DirectDamage
 * Purpose: Evaluate direct damage spell against creature or player.
 * Procedure:
 * 1. Check if damage is lethal to target creature or player.
 * 2. Prioritize removal of high-threat utility creatures.
 */
/*
 * Decompiled function: Ai_EvalAbility_DirectDamage
 * Entry Point: 004b59d9
 * Size: 109 bytes
 */

int Ai_EvalAbility_DirectDamage(int player, int card_index)

{
  int status;
  int u_temp;
  
  status = Ai_EvalAbility_Landwalk(arg1,arg2);
  if (status == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
    u_temp = *(int *)(&DAT_0068a754 + arg2 * 0x120 + arg1 * 0x5b20);
    LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  }
  else {
    u_temp = 0;
  }
  return u_temp;
}

/*
 * Ai_EvalAbility_Removal
 * Purpose: Evaluate unconditional creature destruction spell.
 * Procedure:
 * 1. Identify highest-threat enemy creature.
 * 2. Score removal value proportional to enemy creature power/cost.
 */
/*
 * Decompiled function: Ai_EvalAbility_Removal
 * Entry Point: 004b5a46
 * Size: 114 bytes
 */

uint Ai_EvalAbility_Removal(int player, int card_index)

{
  int status;
  uint u_temp;
  
  status = Ai_EvalAbility_Landwalk(arg1,arg2);
  if (status == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
    u_temp = *(uint *)(&DAT_0068a77c + arg2 * 0x120 + arg1 * 0x5b20) & 0xff;
    LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  }
  else {
    u_temp = 0;
  }
  return u_temp;
}

/*
 * Ai_EvalAbility_Counterspell
 * Purpose: Evaluate tactical decision to cast Counterspell.
 * Procedure:
 * 1. Analyze active spell on spell stack.
 * 2. Counter high-threat bombs, board wipes, or combo pieces.
 */
/*
 * Decompiled function: Ai_EvalAbility_Counterspell
 * Entry Point: 004b5ab8
 * Size: 183 bytes
 */

void Ai_EvalAbility_Counterspell(int player, int card_index, uint * target_player, uint * action_flags, uint * arg5)

{
  int status;
  
  status = Ai_EvalAbility_Landwalk(arg1,arg2);
  if (status == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
    *arg3 = (uint)(byte)(&DAT_0068a77d)[arg2 * 0x120 + arg1 * 0x5b20];
    *arg4 = (*(uint *)(&DAT_0068a77c + arg2 * 0x120 + arg1 * 0x5b20) & 0xff0000) >> 0x10;
    *arg5 = *(uint *)(&DAT_0068a77c + arg2 * 0x120 + arg1 * 0x5b20) >> 0x18;
    LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  }
  return;
}

/*
 * Ai_EvalAbility_CardDraw
 * Purpose: Evaluate card drawing spell or ability.
 * Procedure:
 * 1. Score immediate hand advantage and mana efficiency.
 */
/*
 * Decompiled function: Ai_EvalAbility_CardDraw
 * Entry Point: 004b5b6f
 * Size: 110 bytes
 */

int Ai_EvalAbility_CardDraw(int player, int card_index)

{
  int status;
  
  status = Ai_EvalAbility_Landwalk(arg1,arg2);
  if (status == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
    status = (int)(char)(&DAT_0068a74e)[arg2 * 0x120 + arg1 * 0x5b20];
    LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  }
  else {
    status = 0;
  }
  return status;
}

/*
 * Ai_EvalAbility_Displacement
 * Purpose: Evaluate bounce / unsummon effect on permanent.
 * Procedure:
 * 1. Score tempo advantage gained by resetting opponent mana investment.
 */
/*
 * Decompiled function: Ai_EvalAbility_Displacement
 * Entry Point: 004b5bdd
 * Size: 110 bytes
 */

int Ai_EvalAbility_Displacement(int player, int card_index)

{
  int status;
  
  status = Ai_EvalAbility_Landwalk(arg1,arg2);
  if (status == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
    status = (int)*(short *)(&DAT_0068a740 + arg2 * 0x120 + arg1 * 0x5b20);
    LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  }
  else {
    status = 0;
  }
  return status;
}

/*
 * Ai_EvalAbility_LifeGain
 * Purpose: Evaluate life gain spell or healing ability.
 * Procedure:
 * 1. Score life preservation value when life is critically low.
 */
/*
 * Decompiled function: Ai_EvalAbility_LifeGain
 * Entry Point: 004b5c4b
 * Size: 112 bytes
 */

int Ai_EvalAbility_LifeGain(int player, int card_index)

{
  int status;
  int u_temp;
  
  status = Ai_EvalAbility_Landwalk(arg1,arg2);
  if (status == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
    u_temp = *(int *)(&DAT_0068a734 + arg2 * 0x120 + arg1 * 0x5b20);
    LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  }
  else {
    u_temp = 0xffffffff;
  }
  return u_temp;
}

/*
 * Ai_EvalAbility_Disenchant
 * Purpose: Evaluate artifact and enchantment removal spell.
 * Procedure:
 * 1. Target high-impact enchantments (Moat, Underworld Dreams) or artifacts.
 */
/*
 * Decompiled function: Ai_EvalAbility_Disenchant
 * Entry Point: 004b5cbb
 * Size: 110 bytes
 */

int Ai_EvalAbility_Disenchant(int player, int card_index)

{
  int status;
  int u_temp;
  
  status = Ai_EvalAbility_Landwalk(arg1,arg2);
  if (status == 0) {
    status = Ai_EvalAbility_LifeGain(arg1,arg2);
    if (status == -1) {
      u_temp = 0xffffffff;
    }
    else {
      u_temp = *(int *)(&g_MasterCardTypeTable + status * 0x34);
    }
  }
  else {
    u_temp = 0xffffffff;
  }
  return u_temp;
}

/*
 * Ai_EvalAbility_BoardWipe
 * Purpose: Evaluate Wrath of God / Armageddon board wipe spell.
 * Procedure:
 * 1. Compare total friendly creature power vs enemy creature power.
 * 2. Cast if opponent board advantage significantly exceeds friendly board.
 */
/*
 * Decompiled function: Ai_EvalAbility_BoardWipe
 * Entry Point: 004b5d2e
 * Size: 182 bytes
 */

int Ai_EvalAbility_BoardWipe(int player, int card_index)

{
  int status;
  int local_8;
  
  status = Ai_EvalAbility_Landwalk(arg1,arg2);
  if (status == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
    if (((&g_AiEvaluationTimeout)[arg2 * 0x120 + arg1 * 0x5b20] & 2) == 0) {
      if (((&g_AiEvaluationTimeout)[arg2 * 0x120 + arg1 * 0x5b20] & 0x20) == 0) {
        local_8 = 0;
      }
      else {
        local_8 = 2;
      }
    }
    else {
      local_8 = 1;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  }
  else {
    local_8 = 0;
  }
  return local_8;
}

/*
 * Ai_EvalAbility_LandDestruction
 * Purpose: Evaluate Sinkhole / Stone Rain land destruction spell.
 * Procedure:
 * 1. Target opponent color-fixing lands or sole mana sources.
 */
/*
 * Decompiled function: Ai_EvalAbility_LandDestruction
 * Entry Point: 004b5de4
 * Size: 400 bytes
 */

byte Ai_EvalAbility_LandDestruction(int player, int card_index)

{
  int status;
  byte is_match;
  
  status = Ai_EvalAbility_Landwalk(arg1,arg2);
  if (status == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
    is_match = ((&DAT_0068a73e)[arg2 * 0x120 + arg1 * 0x5b20] & 3) != 0;
    if ((((&g_AiEvaluationTimeout)[arg2 * 0x120 + arg1 * 0x5b20] & 0x10) != 0) &&
       (((&g_MasterCardColorTable)[*(int *)(&DAT_0068a734 + arg2 * 0x120 + arg1 * 0x5b20) * 0x34] &
        0x47) != 4)) {
      is_match = is_match | 2;
    }
    if (((&g_AiEvaluationTimeout)[arg2 * 0x120 + arg1 * 0x5b20] & 4) != 0) {
      is_match = is_match | 4;
    }
    if ((&DAT_0068a74e)[arg2 * 0x120 + arg1 * 0x5b20] != -1) {
      is_match = is_match | 8;
    }
    if (((&DAT_0068a742)[arg2 * 0x120 + arg1 * 0x5b20] != -1) &&
       (*(int *)(&DAT_0068a758 + arg2 * 0x120 + arg1 * 0x5b20) != -1)) {
      is_match = is_match | 0x10;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  }
  else {
    is_match = 0;
  }
  return is_match;
}

/*
 * Ai_EvalAbility_ManaRamp
 * Purpose: Evaluate Llanowar Elves / Birds of Paradise mana acceleration.
 * Procedure:
 * 1. Score turn-1/turn-2 mana ramp tempo bonus.
 */
/*
 * Decompiled function: Ai_EvalAbility_ManaRamp
 * Entry Point: 004b5f74
 * Size: 175 bytes
 */

void Ai_EvalAbility_ManaRamp(int * player, int card_index, int target_player)

{
  int status;
  
  if (arg1 != (int *)0x0) {
    status = Ai_EvalAbility_Landwalk(arg2,arg3);
    if (status == 0) {
      EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
      *arg1 = (int)(char)(&DAT_0068a742)[arg3 * 0x120 + arg2 * 0x5b20];
      arg1[1] = *(int *)(&DAT_0068a758 + arg3 * 0x120 + arg2 * 0x5b20);
      LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
    }
    else {
      *arg1 = -1;
      arg1[1] = -1;
    }
  }
  return;
}

/*
 * Ai_EvalAbility_Tapping
 * Purpose: Evaluate Icy Manipulator / Twiddle tapping ability.
 * Procedure:
 * 1. Tap opponent primary attacker before combat or lone land at upkeep.
 */
/*
 * Decompiled function: Ai_EvalAbility_Tapping
 * Entry Point: 004b6023
 * Size: 280 bytes
 */

int Ai_EvalAbility_Tapping(int * player, int card_index, int target_player)

{
  int status;
  int u_temp;
  
  status = Ai_EvalAbility_Landwalk(arg2,arg3);
  if (status == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
    if (arg1 != (int *)0x0) {
      *arg1 = (int)(char)(&DAT_0068a743)[arg3 * 0x120 + arg2 * 0x5b20];
      arg1[1] = *(int *)(&DAT_0068a75c + arg3 * 0x120 + arg2 * 0x5b20);
    }
    u_temp = *(int *)(&DAT_0068a774 + arg3 * 0x120 + arg2 * 0x5b20);
    LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  }
  else {
    if (arg1 != (int *)0x0) {
      *arg1 = (int)(char)(&DAT_0068a743)[arg3 * 0x120 + arg2 * 0x5b20];
      arg1[1] = *(int *)(&DAT_0068a75c + arg3 * 0x120 + arg2 * 0x5b20);
    }
    u_temp = 0xffffffff;
  }
  return u_temp;
}

/*
 * Ai_EvalAbility_Discard
 * Purpose: Evaluate Hymn to Tourach / Mind Twist discard spell.
 * Procedure:
 * 1. Score card advantage and depletion of opponent options.
 */
/*
 * Decompiled function: Ai_EvalAbility_Discard
 * Entry Point: 004b613b
 * Size: 108 bytes
 */

uint8_t Ai_EvalAbility_Discard(int player, int card_index)

{
  uint8_t u_res;
  int val_result;
  
  val_result = Ai_EvalAbility_Landwalk(arg1,arg2);
  if (val_result == 0) {
    val_result = Ai_EvalAbility_LifeGain(arg1,arg2);
    if (val_result == -1) {
      u_res = 0;
    }
    else {
      u_res = (&g_MasterCardColorTable)[val_result * 0x34];
    }
  }
  else {
    u_res = 0;
  }
  return u_res;
}

/*
 * Ai_EvalAbility_PumpSpell
 * Purpose: Evaluate Giant Growth / Blood Lust combat trick.
 * Procedure:
 * 1. Cast during combat damage step to save creature or deal lethal damage.
 */
/*
 * Decompiled function: Ai_EvalAbility_PumpSpell
 * Entry Point: 004b61ac
 * Size: 110 bytes
 */

int Ai_EvalAbility_PumpSpell(int player, int card_index)

{
  int status;
  
  status = Ai_EvalAbility_Landwalk(arg1,arg2);
  if (status == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
    status = (int)*(short *)(&DAT_0068a744 + arg2 * 0x120 + arg1 * 0x5b20);
    LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  }
  else {
    status = 0;
  }
  return status;
}

/*
 * Ai_EvalAbility_Haste
 * Purpose: Evaluate haste / immediate attack capability.
 * Procedure:
 * 1. Score immediate surprise combat damage bonus.
 */
/*
 * Decompiled function: Ai_EvalAbility_Haste
 * Entry Point: 004b621a
 * Size: 110 bytes
 */

int Ai_EvalAbility_Haste(int player, int card_index)

{
  int status;
  
  status = Ai_EvalAbility_Landwalk(arg1,arg2);
  if (status == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
    status = (int)*(short *)(&DAT_0068a746 + arg2 * 0x120 + arg1 * 0x5b20);
    LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  }
  else {
    status = 0;
  }
  return status;
}

/*
 * Ai_EvalAbility_Vigilance
 * Purpose: Evaluate vigilance / attacking without tapping.
 * Procedure:
 * 1. Score simultaneous attacking and blocking capability.
 */
/*
 * Decompiled function: Ai_EvalAbility_Vigilance
 * Entry Point: 004b6288
 * Size: 206 bytes
 */

uint Ai_EvalAbility_Vigilance(int player, int card_index)

{
  int status;
  uint local_8;
  
  status = Ai_EvalAbility_Landwalk(arg1,arg2);
  if (status == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
    local_8 = *(uint *)(&DAT_0068a76c + arg2 * 0x120 + arg1 * 0x5b20);
    if ((((&DAT_0068a76e)[arg2 * 0x120 + arg1 * 0x5b20] & 0x20) != 0) &&
       (((&g_AiEvaluationTimeout)[arg2 * 0x120 + arg1 * 0x5b20] & 4) != 0)) {
      local_8 = local_8 | 0x40;
    }
    if (local_8 == 0xffffffff) {
      local_8 = 0;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  }
  else {
    local_8 = 0;
  }
  return local_8;
}

/*
 * Ai_EvalAbility_Defender
 * Purpose: Evaluate Wall / Defender permanent value.
 * Procedure:
 * 1. Score defensive toughness against ground attackers.
 */
/*
 * Decompiled function: Ai_EvalAbility_Defender
 * Entry Point: 004b6356
 * Size: 110 bytes
 */

int Ai_EvalAbility_Defender(int player, int card_index)

{
  int status;
  
  status = Ai_EvalAbility_Landwalk(arg1,arg2);
  if (status == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
    status = (int)(char)(&DAT_0068a74d)[arg2 * 0x120 + arg1 * 0x5b20];
    LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  }
  else {
    status = 0;
  }
  return status;
}

/*
 * Ai_EvalAbility_PingDamage
 * Purpose: Evaluate Prodigal Sorcerer / Tim ping damage ability.
 * Procedure:
 * 1. Score reusable damage against 1-toughness creatures.
 */
/*
 * Decompiled function: Ai_EvalAbility_PingDamage
 * Entry Point: 004b63c4
 * Size: 110 bytes
 */

int Ai_EvalAbility_PingDamage(int player, int card_index)

{
  int status;
  
  status = Ai_EvalAbility_Landwalk(arg1,arg2);
  if (status == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
    status = (int)(char)(&DAT_0068a74c)[arg2 * 0x120 + arg1 * 0x5b20];
    LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  }
  else {
    status = 0;
  }
  return status;
}

/*
 * Ai_EvalAbility_Recursion
 * Purpose: Evaluate Animate Dead / Regrowth graveyard recursion.
 * Procedure:
 * 1. Target highest-power creature in graveyard.
 */
/*
 * Decompiled function: Ai_EvalAbility_Recursion
 * Entry Point: 004b6432
 * Size: 109 bytes
 */

int Ai_EvalAbility_Recursion(int player, int card_index)

{
  int status;
  int u_temp;
  
  status = Ai_EvalAbility_Landwalk(arg1,arg2);
  if (status == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
    u_temp = *(int *)(&g_AiEvaluationTimeout + arg2 * 0x120 + arg1 * 0x5b20);
    LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  }
  else {
    u_temp = 0;
  }
  return u_temp;
}

/*
 * Ai_EvalAbility_TokenGeneration
 * Purpose: Evaluate token generating permanent or spell.
 * Procedure:
 * 1. Score cumulative board presence and sacrifice fodder.
 */
/*
 * Decompiled function: Ai_EvalAbility_TokenGeneration
 * Entry Point: 004b649f
 * Size: 109 bytes
 */

int Ai_EvalAbility_TokenGeneration(int player, int card_index)

{
  int status;
  int u_temp;
  
  status = Ai_EvalAbility_Landwalk(arg1,arg2);
  if (status == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
    u_temp = *(int *)(&DAT_0068a760 + arg2 * 0x120 + arg1 * 0x5b20);
    LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  }
  else {
    u_temp = 0;
  }
  return u_temp;
}

/*
 * Ai_EvalAbility_SacrificeOutlet
 * Purpose: Evaluate Lord of the Pit / sacrifice requirement.
 * Procedure:
 * 1. Identify lowest-value friendly permanent to sacrifice.
 */
/*
 * Decompiled function: Ai_EvalAbility_SacrificeOutlet
 * Entry Point: 004b650c
 * Size: 161 bytes
 */

void Ai_EvalAbility_SacrificeOutlet(int player, int card_index, int * target_player, int * action_flags)

{
  int status;
  
  if (((width != (int *)0x0) && (height != (int *)0x0)) &&
     (status = Ai_EvalAbility_Landwalk(x,y), status == 0)) {
    EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
    *width = (int)*(short *)(&DAT_0068a748 + y * 0x120 + x * 0x5b20);
    *height = (int)*(short *)(&DAT_0068a74a + y * 0x120 + x * 0x5b20);
    LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  }
  return;
}

/*
 * Ai_Eval_ClearAbilityTable
 * Purpose: Clear ability evaluation score table.
 * Procedure:
 * 1. Zero out ability score accumulator.
 */
/*
 * Decompiled function: Ai_Eval_ClearAbilityTable
 * Entry Point: 004b65ad
 * Size: 18 bytes
 */

int Ai_Eval_ClearAbilityTable(void)

{
  return 0;
}

/*
 * Ai_EvalAbility_DamagePrevention
 * Purpose: Evaluate Healing Salve / Samite Healer damage prevention.
 * Procedure:
 * 1. Prevent lethal combat damage on friendly creatures.
 */
/*
 * Decompiled function: Ai_EvalAbility_DamagePrevention
 * Entry Point: 004b65bf
 * Size: 100 bytes
 */

uint Ai_EvalAbility_DamagePrevention(int player, int card_index)

{
  int status;
  uint u_temp;
  uint local_8;
  
  status = Ai_EvalAbility_Landwalk(arg1,arg2);
  if (status == 0) {
    u_temp = Ai_EvalAbility_Recursion(arg1,arg2);
    local_8 = (uint)((u_temp & 0x1000) != 0);
  }
  else {
    local_8 = 0xffffffff;
  }
  return local_8;
}

/*
 * Ai_EvalAbility_PowerMod
 * Purpose: Evaluate static power modifier effect.
 * Procedure:
 * 1. Compute delta in total attacking strength.
 */
/*
 * Decompiled function: Ai_EvalAbility_PowerMod
 * Entry Point: 004b6623
 * Size: 115 bytes
 */

uint Ai_EvalAbility_PowerMod(int player, int card_index)

{
  int status;
  uint u_temp;
  
  status = Ai_EvalAbility_Landwalk(arg1,arg2);
  if (status == 0) {
    status = Ai_EvalAbility_LifeGain(arg1,arg2);
    if (status == -1) {
      u_temp = 0;
    }
    else {
      u_temp = *(uint *)(&g_MasterCardSubtypeTable + status * 0x34) & 0x1000;
    }
  }
  else {
    u_temp = 0;
  }
  return u_temp;
}

/*
 * Ai_EvalAbility_ToughnessMod
 * Purpose: Evaluate static toughness modifier effect.
 * Procedure:
 * 1. Compute delta in creature survival rates.
 */
/*
 * Decompiled function: Ai_EvalAbility_ToughnessMod
 * Entry Point: 004b6696
 * Size: 168 bytes
 */

bool Ai_EvalAbility_ToughnessMod(int player, int card_index)

{
  int status;
  bool is_match;
  
  status = Ai_EvalAbility_Landwalk(arg1,arg2);
  if (status == 0) {
    status = Ai_EvalAbility_LifeGain(arg1,arg2);
    if (status == -1) {
      is_match = false;
    }
    else {
      EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
      is_match = ((&DAT_0068a768)[arg2 * 0x120 + arg1 * 0x5b20] & 6) != 0;
      LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
    }
  }
  else {
    is_match = false;
  }
  return is_match;
}

/*
 * Ai_EvalAbility_ColorIdentity
 * Purpose: Evaluate color identity change effect.
 * Procedure:
 * 1. Score bypass of opponent color protection.
 */
/*
 * Decompiled function: Ai_EvalAbility_ColorIdentity
 * Entry Point: 004b673e
 * Size: 109 bytes
 */

int Ai_EvalAbility_ColorIdentity(int player, int card_index)

{
  int status;
  int u_temp;
  
  status = Ai_EvalAbility_Landwalk(arg1,arg2);
  if (status == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
    u_temp = *(int *)(&DAT_0068a784 + arg2 * 0x120 + arg1 * 0x5b20);
    LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  }
  else {
    u_temp = 0;
  }
  return u_temp;
}

/*
 * Ai_Subsystem_004b67ab
 * Purpose: Tactical AI engine subsystem routine (004b67ab).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004b67ab
 * Entry Point: 004b67ab
 * Size: 132 bytes
 */

bool Ai_Subsystem_004b67ab(int arg1, int arg2)

{
  int status;
  bool is_match;
  
  status = Ai_EvalAbility_Landwalk(arg1,arg2);
  if (status == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
    is_match = ((&DAT_0068a73e)[arg1 * 0x5b20 + arg2 * 0x120] & 0x20) != 0;
    LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  }
  else {
    is_match = false;
  }
  return is_match;
}

/*
 * Ai_EvalAbility_StealCreature
 * Purpose: Evaluate Control Magic / creature stealing spell.
 * Procedure:
 * 1. Target highest-power enemy creature for maximum two-for-one swing.
 */
/*
 * Decompiled function: Ai_EvalAbility_StealCreature
 * Entry Point: 004b682f
 * Size: 132 bytes
 */

bool Ai_EvalAbility_StealCreature(int player, int card_index)

{
  int status;
  bool is_match;
  
  status = Ai_EvalAbility_Landwalk(arg1,arg2);
  if (status == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
    is_match = ((&DAT_0068a73e)[arg2 * 0x120 + arg1 * 0x5b20] & 0x10) == 0;
    LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  }
  else {
    is_match = false;
  }
  return is_match;
}

/*
 * Ai_Subsystem_004b68b3
 * Purpose: Tactical AI engine subsystem routine (004b68b3).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004b68b3
 * Entry Point: 004b68b3
 * Size: 263 bytes
 */

void Ai_Subsystem_004b68b3(int arg1, int arg2, char * arg3)

{
  int local_8;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  for (local_8 = 1; local_8 < 6; local_8 = local_8 + 1) {
    if (*(char *)(arg1 * 0x5b20 + arg2 * 0x120 + 0x68a829 + local_8) != '\0') {
      FUN_004f4a92(arg3,(char *)(local_8 * 10 + 0x649f70),1,
                   &DAT_00649f30 +
                   *(char *)(arg1 * 0x5b20 + arg2 * 0x120 + 0x68a829 + local_8) * 10);
      FUN_004f4a92(arg3,(char *)(local_8 * 10 + 0x64a030),1,
                   &DAT_00649f30 +
                   *(char *)(arg1 * 0x5b20 + arg2 * 0x120 + 0x68a829 + local_8) * 10);
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  return;
}

/*
 * Ai_Subsystem_004b69ba
 * Purpose: Tactical AI engine subsystem routine (004b69ba).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004b69ba
 * Entry Point: 004b69ba
 * Size: 494 bytes
 */

void Ai_Subsystem_004b69ba(int arg1, int arg2, char * arg3)

{
  char local_30 [20];
  int local_1c;
  char local_18 [20];
  
  EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  for (local_1c = 1; local_1c < 6; local_1c = local_1c + 1) {
    if (*(char *)(arg1 * 0x5b20 + arg2 * 0x120 + 0x68a82f + local_1c) != '\0') {
      FUN_004f4a92(arg3,(char *)(local_1c * 10 + 0x649ff0),1,
                   &DAT_0064a070 +
                   *(char *)(arg1 * 0x5b20 + arg2 * 0x120 + 0x68a82f + local_1c) * 10);
      FUN_004f4a92(arg3,(char *)(local_1c * 10 + 0x649fb0),1,
                   &DAT_0064a070 +
                   *(char *)(arg1 * 0x5b20 + arg2 * 0x120 + 0x68a82f + local_1c) * 10);
      FUN_004f4a92(arg3,s_PLAINSs_0052d3e0,1,s_PLAINS_0052d3d8);
      strcpy(local_30,(char *)(local_1c * 10 + 0x649ff0));
      strcat(local_30,&DAT_0052d3e8);
      strcpy(local_18,&DAT_0064a070 +
                      *(char *)(arg1 * 0x5b20 + arg2 * 0x120 + 0x68a82f + local_1c) * 10);
      strcat(local_18,&DAT_0052d3f0);
      FUN_004f4a92(arg3,local_30,1,local_18);
      strcpy(local_30,(char *)(local_1c * 10 + 0x649fb0));
      strcat(local_30,&DAT_0052d3f8);
      FUN_004f4a92(arg3,local_30,1,local_18);
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  return;
}

/*
 * Ai_Subsystem_004b6ba8
 * Purpose: Tactical AI engine subsystem routine (004b6ba8).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004b6ba8
 * Entry Point: 004b6ba8
 * Size: 179 bytes
 */

int Ai_Subsystem_004b6ba8(int arg1, int arg2, void * arg3)

{
  int status;
  
  status = Ai_EvalAbility_Landwalk(arg1,arg2);
  if (status == 0) {
    if (arg3 == (void *)0x0) {
      status = 0;
    }
    else {
      EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
      status = (int)(char)(&DAT_0068a828)[arg1 * 0x5b20 + arg2 * 0x120];
      memcpy(arg3,(void *)(arg2 * 0x120 + arg1 * 0x5b20 + 0x68a788),0xa0);
      LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
    }
  }
  else {
    status = 0;
  }
  return status;
}

/*
 * Ai_Subsystem_004b6c5b
 * Purpose: Tactical AI engine subsystem routine (004b6c5b).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004b6c5b
 * Entry Point: 004b6c5b
 * Size: 109 bytes
 */

int Ai_Subsystem_004b6c5b(int arg1, int arg2)

{
  int status;
  int u_temp;
  
  status = Ai_EvalAbility_Landwalk(arg1,arg2);
  if (status == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
    u_temp = *(int *)(&DAT_0068a768 + arg2 * 0x120 + arg1 * 0x5b20);
    LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  }
  else {
    u_temp = 0;
  }
  return u_temp;
}

/*
 * Ai_Subsystem_004b6cc8
 * Purpose: Tactical AI engine subsystem routine (004b6cc8).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004b6cc8
 * Entry Point: 004b6cc8
 * Size: 109 bytes
 */

int Ai_Subsystem_004b6cc8(int arg1, int arg2)

{
  int status;
  int u_temp;
  
  status = Ai_EvalAbility_Landwalk(arg1,arg2);
  if (status == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
    u_temp = *(int *)(&DAT_0068a838 + arg2 * 0x120 + arg1 * 0x5b20);
    LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  }
  else {
    u_temp = 0;
  }
  return u_temp;
}

/*
 * Ai_Subsystem_004b6d35
 * Purpose: Tactical AI engine subsystem routine (004b6d35).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004b6d35
 * Entry Point: 004b6d35
 * Size: 112 bytes
 */

int Ai_Subsystem_004b6d35(int arg1, int arg2)

{
  int status;
  int u_temp;
  
  status = Ai_EvalAbility_Landwalk(arg1,arg2);
  if (status == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
    u_temp = *(int *)(&DAT_0068a730 + arg1 * 0x5b20 + arg2 * 0x120);
    LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  }
  else {
    u_temp = 0xffffffff;
  }
  return u_temp;
}

/*
 * Ai_Subsystem_004b6da5
 * Purpose: Tactical AI engine subsystem routine (004b6da5).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004b6da5
 * Entry Point: 004b6da5
 * Size: 150 bytes
 */

void Ai_Subsystem_004b6da5(int * arg1, int arg2, int arg3)

{
  int status;
  
  status = Ai_EvalAbility_Landwalk(arg2,arg3);
  if ((status == 0) && (arg1 != (int *)0x0)) {
    EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
    *arg1 = *(int *)(&DAT_0068a820 + arg3 * 0x120 + arg2 * 0x5b20);
    arg1[1] = *(int *)(&DAT_0068a824 + arg3 * 0x120 + arg2 * 0x5b20);
    LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  }
  return;
}

/*
 * Ai_Subsystem_004b6e3b
 * Purpose: Tactical AI engine subsystem routine (004b6e3b).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004b6e3b
 * Entry Point: 004b6e3b
 * Size: 112 bytes
 */

int Ai_Subsystem_004b6e3b(int arg1, int arg2)

{
  int status;
  int u_temp;
  
  status = Ai_EvalAbility_Landwalk(arg1,arg2);
  if (status == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
    u_temp = *(int *)(&DAT_0068a730 + arg2 * 0x120 + arg1 * 0x5b20);
    LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  }
  else {
    u_temp = 0xffffffff;
  }
  return u_temp;
}

/*
 * Ai_Subsystem_004b6eab
 * Purpose: Tactical AI engine subsystem routine (004b6eab).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004b6eab
 * Entry Point: 004b6eab
 * Size: 110 bytes
 */

int Ai_Subsystem_004b6eab(int arg1, int arg2)

{
  int status;
  
  status = Ai_EvalAbility_Landwalk(arg1,arg2);
  if (status == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
    status = (int)(char)(&DAT_0068a750)[arg1 * 0x5b20 + arg2 * 0x120];
    LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  }
  else {
    status = 0;
  }
  return status;
}

/*
 * Ai_Util_004b6f19
 * Purpose: Tactical AI utility helper function (004b6f19).
 * Procedure:
 * 1. Execute internal state operation.
 */
/*
 * Decompiled function: Ai_Util_004b6f19
 * Entry Point: 004b6f19
 * Size: 48 bytes
 */

int Ai_Util_004b6f19(int arg1)

{
  int u_res;
  
  if ((arg1 == 0) || (arg1 == 1)) {
    u_res = 0;
  }
  else {
    u_res = 1;
  }
  return u_res;
}

/*
 * Ai_Subsystem_004b6f49
 * Purpose: Tactical AI engine subsystem routine (004b6f49).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004b6f49
 * Entry Point: 004b6f49
 * Size: 93 bytes
 */

void Ai_Subsystem_004b6f49(char * prompt_text)

{
  char *local_c;
  char *local_8;
  
  if (prompt_text != (char *)0x0) {
    local_8 = prompt_text;
  }
  for (local_c = &DAT_006ff310; (*local_c != '\0' && (*local_c != '-')); local_c = local_c + 1) {
    *local_8 = *local_c;
    local_8 = local_8 + 1;
  }
  *local_8 = '\0';
  return;
}

/*
 * Ai_Subsystem_004b6fa6
 * Purpose: Tactical AI engine subsystem routine (004b6fa6).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004b6fa6
 * Entry Point: 004b6fa6
 * Size: 102 bytes
 */

int Ai_Subsystem_004b6fa6(int arg1)

{
  int status;
  int local_8;
  
  status = Ai_Util_004b6f19(arg1);
  if (status == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
    if (arg1 == 0) {
      local_8 = DAT_006a3f7c;
    }
    else {
      local_8 = DAT_006ff194;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  }
  else {
    local_8 = 0;
  }
  return local_8;
}

/*
 * Ai_Subsystem_004b700c
 * Purpose: Tactical AI engine subsystem routine (004b700c).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004b700c
 * Entry Point: 004b700c
 * Size: 102 bytes
 */

int Ai_Subsystem_004b700c(int arg1)

{
  int status;
  int local_8;
  
  status = Ai_Util_004b6f19(arg1);
  if (status == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
    if (arg1 == 0) {
      local_8 = DAT_00695ed8;
    }
    else {
      local_8 = DAT_007006d8;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  }
  else {
    local_8 = 0;
  }
  return local_8;
}

/*
 * Ai_Subsystem_004b7072
 * Purpose: Tactical AI engine subsystem routine (004b7072).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004b7072
 * Entry Point: 004b7072
 * Size: 140 bytes
 */

int Ai_Subsystem_004b7072(void * arg1, int arg2)

{
  int u_res;
  int val_result;
  
  if (arg1 == (void *)0x0) {
    u_res = 0;
  }
  else {
    val_result = Ai_Util_004b6f19(arg2);
    if (val_result == 0) {
      EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
      if (arg2 == 0) {
        memcpy(arg1,&DAT_0069f6e0,0x1c);
      }
      else {
        memcpy(arg1,&DAT_00695ee0,0x1c);
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
      u_res = 1;
    }
    else {
      u_res = 0;
    }
  }
  return u_res;
}

/*
 * Ai_Subsystem_004b70fe
 * Purpose: Tactical AI engine subsystem routine (004b70fe).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004b70fe
 * Entry Point: 004b70fe
 * Size: 140 bytes
 */

int Ai_Subsystem_004b70fe(void * arg1, int arg2, int arg3)

{
  int u_res;
  int val_result;
  
  if (arg1 == (void *)0x0) {
    u_res = 0;
  }
  else {
    val_result = Ai_EvalAbility_Landwalk(arg2,arg3);
    if (val_result == 0) {
      EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
      memcpy(arg1,&DAT_0068a730 + arg2 * 0x5b20 + arg3 * 0x120,0x120);
      LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
      u_res = 1;
    }
    else {
      u_res = 0;
    }
  }
  return u_res;
}

/*
 * Ai_Subsystem_004b718a
 * Purpose: Tactical AI engine subsystem routine (004b718a).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004b718a
 * Entry Point: 004b718a
 * Size: 163 bytes
 */

int Ai_Subsystem_004b718a(void * arg1, int arg2)

{
  int status;
  int local_8;
  
  if (arg1 == (void *)0x0) {
    local_8 = 0;
  }
  else {
    status = Ai_Util_004b6f19(arg2);
    if (status == 0) {
      EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
      if (arg2 == 0) {
        local_8 = DAT_006ff1a0;
      }
      else {
        local_8 = DAT_007006b4;
      }
      memcpy(arg1,(void *)((int)&DAT_00695f20 + ((arg2 == 0) - 1 & 0x674e0)),2000);
      LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
    }
    else {
      local_8 = 0;
    }
  }
  return local_8;
}

/*
 * Ai_Subsystem_004b722d
 * Purpose: Tactical AI engine subsystem routine (004b722d).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004b722d
 * Entry Point: 004b722d
 * Size: 163 bytes
 */

int Ai_Subsystem_004b722d(void * arg1, int arg2)

{
  int status;
  int local_8;
  
  if (arg1 == (void *)0x0) {
    local_8 = 0;
  }
  else {
    status = Ai_Util_004b6f19(arg2);
    if (status == 0) {
      EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
      if (arg2 == 0) {
        local_8 = DAT_006ff2e4;
      }
      else {
        local_8 = DAT_006b2d34;
      }
      memcpy(arg1,(void *)((int)&DAT_006fe4a0 + ((arg2 == 0) - 1 & 0xfffa6ae0)),2000);
      LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
    }
    else {
      local_8 = 0;
    }
  }
  return local_8;
}

/*
 * Ai_Subsystem_004b72d0
 * Purpose: Tactical AI engine subsystem routine (004b72d0).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004b72d0
 * Entry Point: 004b72d0
 * Size: 163 bytes
 */

int Ai_Subsystem_004b72d0(void * arg1, int arg2)

{
  int status;
  int local_8;
  
  if (arg1 == (void *)0x0) {
    local_8 = 0;
  }
  else {
    status = Ai_Util_004b6f19(arg2);
    if (status == 0) {
      EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
      if (arg2 == 0) {
        local_8 = DAT_006b2d30;
      }
      else {
        local_8 = DAT_006b2e20;
      }
      memcpy(arg1,(void *)((int)&DAT_006b2550 + ((arg2 == 0) - 1 & 0x4b690)),2000);
      LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
    }
    else {
      local_8 = 0;
    }
  }
  return local_8;
}

/*
 * Ai_Subsystem_004b7373
 * Purpose: Tactical AI engine subsystem routine (004b7373).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004b7373
 * Entry Point: 004b7373
 * Size: 91 bytes
 */

int Ai_Subsystem_004b7373(void * arg1)

{
  int u_res;
  
  if (arg1 == (void *)0x0) {
    u_res = 0;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
    u_res = g_AiCandidateActionCount;
    memcpy(arg1,&DAT_006a29e0,0x1580);
    LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  }
  return u_res;
}

/*
 * Ai_Duel_CalculateLayout
 * Purpose: Calculate card slot layout coordinates in duel arena.
 * Procedure:
 * 1. Position hand, battlefield, and graveyard slots.
 */
/*
 * Decompiled function: Ai_Duel_CalculateLayout
 * Entry Point: 004b73ce
 * Size: 227 bytes
 */

void Ai_Duel_CalculateLayout(int x, int * y, int width, int * height)

{
  int u_res;
  int local_8;
  
  if ((((x != 0) && (y != (int *)0x0)) && (width != 0)) && (height != (int *)0x0)) {
    EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
    *y = DAT_0069f740;
    for (local_8 = 0; local_8 < DAT_0069f740; local_8 = local_8 + 1) {
      u_res = Ai_Subsystem_004cbd67(*(uint *)(&DAT_006fec70 + local_8 * 4));
      *(int *)(x + local_8 * 4) = u_res;
    }
    *height = DAT_00701004;
    for (local_8 = 0; local_8 < DAT_00701004; local_8 = local_8 + 1) {
      u_res = Ai_Subsystem_004cbd67(*(uint *)(&DAT_006ff6d0 + local_8 * 4));
      *(int *)(width + local_8 * 4) = u_res;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  }
  return;
}

/*
 * Ai_Subsystem_004b74b1
 * Purpose: Tactical AI engine subsystem routine (004b74b1).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004b74b1
 * Entry Point: 004b74b1
 * Size: 73 bytes
 */

void Ai_Subsystem_004b74b1(int * arg1, int * arg2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  if (arg1 != (int *)0x0) {
    *arg1 = DAT_006808ac;
  }
  if (arg2 != (int *)0x0) {
    *arg2 = DAT_006a2834;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  return;
}

/*
 * Ai_Subsystem_004b74fa
 * Purpose: Tactical AI engine subsystem routine (004b74fa).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004b74fa
 * Entry Point: 004b74fa
 * Size: 117 bytes
 */

void Ai_Subsystem_004b74fa(void * arg1, int arg2)

{
  int status;
  
  if ((arg1 != (void *)0x0) && (status = Ai_Util_004b6f19(arg2), status == 0)) {
    EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
    memcpy(arg1,&DAT_006fedd0 + ((arg2 == 0) - 1 & 0xfffa5b70),0x98);
    LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  }
  return;
}

/*
 * Ai_Subsystem_004b756f
 * Purpose: Tactical AI engine subsystem routine (004b756f).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004b756f
 * Entry Point: 004b756f
 * Size: 53 bytes
 */

void Ai_Subsystem_004b756f(int * arg1)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  if (arg1 != (int *)0x0) {
    *arg1 = DAT_0068a678;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  return;
}

/*
 * Ai_Subsystem_004b75a4
 * Purpose: Tactical AI engine subsystem routine (004b75a4).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004b75a4
 * Entry Point: 004b75a4
 * Size: 52 bytes
 */

int Ai_Subsystem_004b75a4(void)

{
  int u_res;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  u_res = DAT_0068077c;
  LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  return u_res;
}

/*
 * Ai_Subsystem_004b75d8
 * Purpose: Tactical AI engine subsystem routine (004b75d8).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004b75d8
 * Entry Point: 004b75d8
 * Size: 81 bytes
 */

bool Ai_Subsystem_004b75d8(int * arg1)

{
  if (arg1 != (int *)0x0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
    *arg1 = DAT_006a29c8;
    arg1[1] = DAT_006a29cc;
    LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  }
  return arg1 != (int *)0x0;
}

/*
 * Ai_Subsystem_004b7629
 * Purpose: Tactical AI engine subsystem routine (004b7629).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004b7629
 * Entry Point: 004b7629
 * Size: 52 bytes
 */

int Ai_Subsystem_004b7629(void)

{
  int u_res;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  u_res = DAT_006a48e0;
  LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  return u_res;
}

/*
 * Ai_Subsystem_004b765d
 * Purpose: Tactical AI engine subsystem routine (004b765d).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004b765d
 * Entry Point: 004b765d
 * Size: 73 bytes
 */

void Ai_Subsystem_004b765d(int * arg1, int * arg2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  if (arg1 != (int *)0x0) {
    *arg1 = DAT_00695ec0;
  }
  if (arg2 != (int *)0x0) {
    *arg2 = DAT_00696730;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  return;
}

/*
 * Ai_Subsystem_004b76a6
 * Purpose: Tactical AI engine subsystem routine (004b76a6).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004b76a6
 * Entry Point: 004b76a6
 * Size: 423 bytes
 */

int Ai_Subsystem_004b76a6(void * arg1, int y, int width, int height)

{
  int status;
  int local_8ac;
  char local_8a4 [200];
  int local_7dc [500];
  int local_c;
  int local_8;
  
  if ((((arg1 == (void *)0x0) || (y == 0)) || (width == 0)) || (height == 0)) {
    local_8ac = 0;
  }
  else {
    memcpy(local_7dc,arg1,y << 2);
    local_c = 0;
    local_8ac = 0;
    while ((local_c == 0 && (local_8ac < height))) {
      do {
        if (local_8ac == 0) {
          strcpy(local_8a4,&g_OverworldGoldAmount);
        }
        else if (local_8ac == 1) {
          strcpy(local_8a4,&DAT_0069f84a);
        }
        else {
          strcpy(local_8a4,&DAT_0069f944);
        }
        status = Ai_ScoreCardPlay_Creature(local_7dc,0,y,local_8a4,0,&DAT_0052d400);
        if (status == -1) {
          local_c = 1;
        }
        else if (local_7dc[status] < 5) {
          local_8 = 1;
          *(int *)(width + local_8ac * 4) = status;
          local_8ac = local_8ac + 1;
          local_7dc[status] = DAT_006a3f74;
        }
        else {
          local_8 = 0;
        }
      } while ((local_c == 0) && (local_8 == 0));
    }
  }
  return local_8ac;
}

/*
 * Ai_Subsystem_004b784d
 * Purpose: Tactical AI engine subsystem routine (004b784d).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004b784d
 * Entry Point: 004b784d
 * Size: 74 bytes
 */

void Ai_Subsystem_004b784d(int arg1, int arg2)

{
  int local_10;
  int local_c;
  
  if (g_IsAiThinking != 1) {
    local_10 = arg1;
    local_c = arg2;
    DialogBoxParamA(g_AppHInstance,(LPCSTR)0xf3,g_MainAppHwnd,Ai_CalcManaRequirement_Colorless,
                    (LPARAM)&local_10);
  }
  return;
}

/*
 * Ai_CalcManaRequirement_Colorless
 * Purpose: Calculate colorless mana requirement for artifact spell.
 * Procedure:
 * 1. Sum all untapped land sources regardless of color.
 */
/*
 * Decompiled function: Ai_CalcManaRequirement_Colorless
 * Entry Point: 004b7897
 * Size: 1180 bytes
 */

int Ai_CalcManaRequirement_Colorless(HWND player, uint color_index, HDC required_amount, int * arg4)

{
  int u_res;
  HBRUSH hbr;
  HWND pHVar2;
  int temp_idx;
  tagRECT *ptVar4;
  char local_2b4 [200];
  HDC local_1ec;
  HGDIOBJ local_1e8;
  tagRECT local_1e4;
  char local_1d4 [200];
  char local_10c [264];
  
  if (uMsg < 0x101) {
    if (uMsg == 0x100) {
LAB_004b7c11:
      FUN_004f4548(DAT_00556934);
      EndDialog(hwnd,0);
      return 1;
    }
    if (uMsg == 0x14) {
      local_1ec = wParam;
      FUN_004f3955(wParam);
      GetClientRect(hwnd,&local_1e4);
      if (DAT_00556934 == (HANDLE)0x0) {
        hbr = GetStockObject(2);
        FillRect(local_1ec,&local_1e4,hbr);
      }
      else {
        FUN_004f3b5f((int)local_1ec,(int)&local_1e4,DAT_00556934);
      }
      local_1e8 = (HGDIOBJ)SendDlgItemMessageA(hwnd,0x496,0x31,0,0);
      SelectObject(local_1ec,local_1e8);
      SetBkMode(local_1ec,1);
      SetTextColor(local_1ec,DAT_00556960);
      ptVar4 = &local_1e4;
      pHVar2 = GetDlgItem(hwnd,0x496);
      GetWindowRect(pHVar2,ptVar4);
      MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_1e4,2);
      SetTextColor(local_1ec,DAT_00556a74);
      DrawTextA(local_1ec,s_Mana_Burn__0052d420,-1,&local_1e4,1);
      OffsetRect(&local_1e4,-2,-2);
      SetTextColor(local_1ec,DAT_00556960);
      DrawTextA(local_1ec,s_Mana_Burn__0052d42c,-1,&local_1e4,1);
      ptVar4 = &local_1e4;
      pHVar2 = GetDlgItem(hwnd,0x484);
      GetWindowRect(pHVar2,ptVar4);
      MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_1e4,2);
      if (*DAT_00556ad0 == 0) {
        strcpy(local_1d4,&DAT_0052d438);
      }
      else {
        Ai_Subsystem_004b6f49(local_1d4);
      }
      if (*DAT_00556ad0 == 0) {
        sprintf(local_2b4,s__s_lose__d_life_0052d43c,local_1d4,DAT_00556ad0[1]);
      }
      else {
        sprintf(local_2b4,s__s_loses__d_life_0052d44c,local_1d4,DAT_00556ad0[1]);
      }
      SetTextColor(local_1ec,DAT_00556a74);
      DrawTextA(local_1ec,local_2b4,-1,&local_1e4,1);
      OffsetRect(&local_1e4,-2,-2);
      SetTextColor(local_1ec,DAT_00556960);
      DrawTextA(local_1ec,local_2b4,-1,&local_1e4,1);
      return 1;
    }
  }
  else if (uMsg < 0x202) {
    if (uMsg == 0x201) {
LAB_004b7c35:
      FUN_004f4548(DAT_00556934);
      EndDialog(hwnd,0);
      return 1;
    }
    if (uMsg == 0x110) {
      DAT_00556ad0 = lParam;
      sprintf(local_10c,s__s_WINBK_ManaBurn_pic_0052d408,&g_AiCurrentChoiceIndex);
      DAT_00556934 = (HANDLE)Pic_Load_00423833(local_10c);
      DAT_00556960 = 0x100009a;
      DAT_00556a74 = 0x10000c9;
      temp_idx = 0;
      pHVar2 = GetDlgItem(hwnd,0x496);
      ShowWindow(pHVar2,temp_idx);
      temp_idx = 0;
      pHVar2 = GetDlgItem(hwnd,0x484);
      ShowWindow(pHVar2,temp_idx);
      SetTimer(hwnd,1,3000,(TIMERPROC)0x0);
      return 1;
    }
    if (uMsg == 0x111) goto LAB_004b7c11;
    if (uMsg == 0x113) {
      FUN_004f4548(DAT_00556934);
      EndDialog(hwnd,0);
      return 1;
    }
  }
  else {
    if (uMsg == 0x204) goto LAB_004b7c35;
    if ((0x30e < uMsg) && (uMsg < 0x312)) {
      u_res = FUN_004f5d1a(hwnd,uMsg,(HWND)wParam,lParam);
      return u_res;
    }
  }
  return 0;
}

/*
 * Ai_Subsystem_004b7d38
 * Purpose: Tactical AI engine subsystem routine (004b7d38).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004b7d38
 * Entry Point: 004b7d38
 * Size: 176 bytes
 */

int Ai_Subsystem_004b7d38(char * prompt_text)

{
  uint u_res;
  uint u_temp;
  char local_70 [100];
  int local_c;
  INT_PTR local_8;
  
  KillTimer(g_MainAppHwnd,DAT_006fdbd4);
  u_res = rand();
  u_temp = (int)u_res >> 0x1f;
  local_c = ((u_res ^ u_temp) - u_temp & 1 ^ u_temp) - u_temp;
  if (g_IsAiThinking != 1) {
    strcpy(local_70,prompt_text);
    local_8 = DialogBoxParamA(g_AppHInstance,(LPCSTR)0xf0,g_MainAppHwnd,Ai_WndProc_004b7de8,
                              (LPARAM)local_70);
    InvalidateRect(g_TurnPriorityState,(RECT *)0x0,1);
    InvalidateRect(g_AiSelectedActionCode,(RECT *)0x0,1);
    Pic_Subsystem_00423c82(0x2f);
  }
  return local_c;
}

/*
 * Ai_WndProc_004b7de8
 * Purpose: Process window messages for tactical AI interface (004b7de8).
 * Procedure:
 * 1. Handle window messages (WM_PAINT, WM_COMMAND, mouse).
 * 2. Update interface state.
 */
/*
 * Decompiled function: Ai_WndProc_004b7de8
 * Entry Point: 004b7de8
 * Size: 1277 bytes
 */

HBRUSH Ai_WndProc_004b7de8(HWND hwnd, uint uMsg, HDC wParam, HWND lParam)

{
  size_t c;
  int X;
  HWND hWnd;
  DWORD dwStyle;
  UINT_PTR UVar1;
  HBRUSH pHVar2;
  int Y;
  int nWidth;
  int nHeight;
  tagSIZE *psizl;
  BOOL BVar3;
  tagRECT local_148;
  HWND local_138;
  int local_134;
  HDC local_130;
  char local_12c [264];
  HDC local_24;
  HGDIOBJ local_20;
  tagRECT local_1c;
  tagSIZE local_c;
  
  if (uMsg < 0x11) {
    if (uMsg == 0x10) {
LAB_004b80bf:
      KillTimer(hwnd,2);
      SendMessageA(g_AiHeuristicWeight_Trample,0x10,0,0);
      EndDialog(hwnd,0);
      return (HBRUSH)0x1;
    }
    if (uMsg == 2) {
      Ai_Util_004b830e(DAT_00556970);
      return (HBRUSH)0x0;
    }
  }
  else if (uMsg < 0x101) {
    if (uMsg == 0x100) {
      if (lParam == (HWND)0x20d) {
        KillTimer(hwnd,2);
        SendMessageA(g_AiHeuristicWeight_Trample,0x10,0,0);
        EndDialog(hwnd,0);
      }
      return (HBRUSH)0x1;
    }
    if (uMsg == 0x14) {
      FUN_004f3955(wParam);
      GetClientRect(hwnd,&local_148);
      FillRect(wParam,&local_148,DAT_00556970);
      return (HBRUSH)0x1;
    }
  }
  else if (uMsg < 0x111) {
    if (uMsg == 0x110) {
      DAT_00556ab8 = lParam;
      Ai_Util_004b82ea(&DAT_00556970,&DAT_00556ab4);
      SetDlgItemTextA(hwnd,0x48a,(LPCSTR)DAT_00556ab8);
      local_20 = (HGDIOBJ)SendDlgItemMessageA(hwnd,0x48a,0x31,0,0);
      local_24 = GetDC(hwnd);
      SelectObject(local_24,local_20);
      psizl = &local_c;
      c = strlen((char *)DAT_00556ab8);
      GetTextExtentPoint32A(local_24,(LPCSTR)DAT_00556ab8,c,psizl);
      ReleaseDC(hwnd,local_24);
      GetClientRect(hwnd,&local_1c);
      nWidth = local_c.cx + local_c.cy;
      nHeight = local_c.cy + 5;
      BVar3 = 1;
      Y = 0x14;
      X = (local_1c.right - nWidth) / 2;
      local_c.cx = nWidth;
      local_c.cy = nHeight;
      hWnd = GetDlgItem(hwnd,0x48a);
      MoveWindow(hWnd,X,Y,nWidth,nHeight,BVar3);
      if (DAT_00556ab8[0x19].unused == 0) {
        sprintf(local_12c,s__s_COINTOSS_Heads_AVI_0052d478,&g_AiCurrentChoiceIndex);
      }
      else {
        sprintf(local_12c,s__s_COINTOSS_Tails_AVI_0052d460,&g_AiCurrentChoiceIndex);
      }
      g_AiHeuristicWeight_Trample = (HWND)MCIWndCreateA(hwnd,g_AppHInstance,0x50000102,local_12c);
      GetWindowRect(g_AiHeuristicWeight_Trample,&local_1c);
      BVar3 = 0;
      dwStyle = GetWindowLongA(hwnd,-0x10);
      AdjustWindowRect(&local_1c,dwStyle,BVar3);
      MoveWindow(hwnd,local_1c.left,local_1c.top,local_1c.right - local_1c.left,
                 local_1c.bottom - local_1c.top,1);
      UVar1 = SetTimer(hwnd,1,10,(TIMERPROC)0x0);
      if (UVar1 == 0) {
        PostMessageA(hwnd,0x113,1,0);
      }
      SetTimer(hwnd,2,15000,(TIMERPROC)0x0);
      SetFocus(hwnd);
      return (HBRUSH)0x0;
    }
    if (uMsg == 0x102) goto LAB_004b80bf;
  }
  else if (uMsg < 0x139) {
    if (uMsg == 0x138) {
      local_130 = wParam;
      FUN_004f3955(wParam);
      local_138 = lParam;
      local_134 = GetDlgCtrlID(lParam);
      SetBkMode(local_130,1);
      SetTextColor(local_130,DAT_00556ab4);
      return DAT_00556970;
    }
    if (uMsg == 0x113) {
      KillTimer(hwnd,(UINT_PTR)wParam);
      if (wParam == (HDC)0x1) {
        SendMessageA(g_AiHeuristicWeight_Trample,0x806,0,0);
        Magic_UpkeepPhase(0x2f);
        SetFocus(hwnd);
      }
      else {
        EndDialog(hwnd,0);
      }
      return (HBRUSH)0x1;
    }
  }
  else {
    if (uMsg == 0x210) {
      if ((((uint)wParam & 0xffff) == 0x201) || (((uint)wParam & 0xffff) == 0x204)) {
        KillTimer(hwnd,2);
        SendMessageA(g_AiHeuristicWeight_Trample,0x808,0,0);
        SendMessageA(g_AiHeuristicWeight_Trample,0x10,0,0);
        EndDialog(hwnd,0);
      }
      return (HBRUSH)0x1;
    }
    if ((0x30e < uMsg) && (uMsg < 0x312)) {
      pHVar2 = (HBRUSH)FUN_004f5d1a(hwnd,uMsg,(HWND)wParam,lParam);
      return pHVar2;
    }
  }
  return (HBRUSH)0x0;
}

/*
 * Ai_Util_004b82ea
 * Purpose: Tactical AI utility helper function (004b82ea).
 * Procedure:
 * 1. Execute internal state operation.
 */
/*
 * Decompiled function: Ai_Util_004b82ea
 * Entry Point: 004b82ea
 * Size: 36 bytes
 */

void Ai_Util_004b82ea(int * arg1, int * arg2)

{
  HBRUSH h_wnd;
  
  h_wnd = CreateSolidBrush(0x100000d);
  *arg1 = h_wnd;
  *arg2 = 0x10000bf;
  return;
}

/*
 * Ai_Util_004b830e
 * Purpose: Tactical AI utility helper function (004b830e).
 * Procedure:
 * 1. Execute internal state operation.
 */
/*
 * Decompiled function: Ai_Util_004b830e
 * Entry Point: 004b830e
 * Size: 31 bytes
 */

void Ai_Util_004b830e(HGDIOBJ arg1)

{
  if (arg1 != (HGDIOBJ)0x0) {
    DeleteObject(arg1);
  }
  return;
}

/*
 * Ai_Subsystem_004b832d
 * Purpose: Tactical AI engine subsystem routine (004b832d).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004b832d
 * Entry Point: 004b832d
 * Size: 234 bytes
 */

int Ai_Subsystem_004b832d(int arg1, int arg2, int arg3, int arg4, int * arg5, int * arg6, int * arg7)

{
  int u_res;
  INT_PTR IVar2;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  
  if (arg1 == 1) {
    u_res = 0;
  }
  else if ((((arg1 == -1) || (arg2 == -1)) || (arg5 == (int *)0x0)) ||
          ((arg6 == (int *)0x0 || (arg7 == (int *)0x0)))) {
    u_res = 0;
  }
  else {
    local_20 = arg3;
    local_1c = arg4;
    local_18 = *arg5;
    local_14 = *arg6;
    local_c = Ai_Subsystem_004cbd67(arg2);
    IVar2 = DialogBoxParamA(g_AppHInstance,(LPCSTR)0xef,g_MainAppHwnd,Ai_WndProc_004b8421,
                            (LPARAM)&local_20);
    if (IVar2 == -1) {
      u_res = 0;
    }
    else if (IVar2 == -2) {
      u_res = 0;
    }
    else {
      *arg5 = local_18;
      *arg6 = local_14;
      *arg7 = local_10;
      u_res = 1;
    }
  }
  return u_res;
}

/*
 * Ai_WndProc_004b8421
 * Purpose: Process window messages for tactical AI interface (004b8421).
 * Procedure:
 * 1. Handle window messages (WM_PAINT, WM_COMMAND, mouse).
 * 2. Update interface state.
 */
/*
 * Decompiled function: Ai_WndProc_004b8421
 * Entry Point: 004b8421
 * Size: 2205 bytes
 */

HBRUSH Ai_WndProc_004b8421(HWND hwnd, uint uMsg, HWND wParam, HWND lParam)

{
  POINT pt;
  uint u_res;
  UINT UVar2;
  HBRUSH pHVar3;
  HDC hdc;
  HWND pHVar4;
  int iVar5;
  BOOL BVar6;
  tagRECT *ptVar7;
  tagPAINTSTRUCT local_118;
  tagRECT local_d8;
  uint local_c8;
  uint local_c4;
  tagRECT local_c0;
  HWND local_b0;
  tagRECT local_ac;
  COLORREF local_9c;
  HWND local_98;
  HWND local_94;
  int local_90;
  HWND local_8c;
  HWND local_84;
  HWND local_80;
  uint local_7c;
  UINT local_78;
  UINT local_74;
  HWND local_70;
  char local_6c [100];
  UINT local_8;
  
  if (uMsg < 0x15) {
    if (uMsg == 0x14) {
      local_b0 = wParam;
      FUN_004f3955((HDC)wParam);
      GetClientRect(hwnd,&local_ac);
      if (DAT_00556aa0 == (HANDLE)0x0) {
        pHVar3 = GetStockObject(3);
        FillRect((HDC)local_b0,&local_ac,pHVar3);
      }
      else {
        FUN_004f3b5f((int)local_b0,(int)&local_ac,DAT_00556aa0);
      }
      return (HBRUSH)0x1;
    }
    if (uMsg == 0xf) {
      hdc = BeginPaint(hwnd,&local_118);
      if ((hdc != (HDC)0x0) && (FUN_004f3955(hdc), DAT_00556954 != 0xffffffff)) {
        ptVar7 = &local_d8;
        pHVar4 = GetDlgItem(hwnd,0x475);
        GetWindowRect(pHVar4,ptVar7);
        MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_d8,2);
        Palette_Subsystem_0049c7c7
                  (hdc,&local_d8.left,(WPARAM *)(&g_AiDecisionMatrix_Col + DAT_00556954 * 0x98),0,0x11,0);
      }
      EndPaint(hwnd,&local_118);
      return (HBRUSH)0x0;
    }
  }
  else if (uMsg < 0x111) {
    if (uMsg == 0x110) {
      g_AiHeuristicWeight_DirectDamage = lParam;
      DAT_00556954 = lParam[5].unused;
      iVar5 = 0;
      pHVar4 = GetDlgItem(hwnd,0x475);
      ShowWindow(pHVar4,iVar5);
      sprintf(local_6c,s__max__d__0052d490,g_AiHeuristicWeight_DirectDamage->unused);
      SetDlgItemTextA(hwnd,0x478,local_6c);
      sprintf(local_6c,s__max__d__0052d49c,g_AiHeuristicWeight_DirectDamage[1].unused);
      SetDlgItemTextA(hwnd,0x47b,local_6c);
      Ai_Subsystem_004b8cc3
                (&DAT_00556aa0,&DAT_00556ab0,(int *)&DAT_00556930,(int *)&DAT_005569c8,
                 (int *)&DAT_00556a84,&DAT_005569a0,&DAT_00556ae4);
      SendDlgItemMessageA(hwnd,0x476,0x465,0,(uint)(ushort)g_AiHeuristicWeight_DirectDamage->unused);
      SendDlgItemMessageA(hwnd,0x47a,0x465,0,(uint)(ushort)g_AiHeuristicWeight_DirectDamage[1].unused);
      SendDlgItemMessageA(hwnd,0x476,0x467,0,(uint)(ushort)g_AiHeuristicWeight_DirectDamage[2].unused);
      SendDlgItemMessageA(hwnd,0x47a,0x467,0,(uint)(ushort)g_AiHeuristicWeight_DirectDamage[3].unused);
      local_8 = Ai_Subsystem_004b8dfd(g_AiHeuristicWeight_DirectDamage[2].unused,g_AiHeuristicWeight_DirectDamage[3].unused);
      SetDlgItemInt(hwnd,0x47c,local_8,1);
      pHVar4 = GetDlgItem(hwnd,1);
      SetFocus(pHVar4);
      SendMessageA(hwnd,0x401,1,0);
      local_70 = GetDlgItem(hwnd,1);
      u_res = GetWindowLongA(local_70,-0x10);
      SetWindowLongA(local_70,-0x10,u_res | 0x800000);
      FUN_004f570c(hwnd);
      return (HBRUSH)0x0;
    }
    if (uMsg == 0x2b) {
      local_98 = lParam;
      pHVar4 = GetFocus();
      if (pHVar4 == (HWND)local_98[5].unused) {
        local_9c = DAT_00556ae4;
      }
      else {
        local_9c = DAT_005569a0;
      }
      FUN_004f5107((int)local_98,DAT_00556930,DAT_005569c8,DAT_00556a84,local_9c,0);
      return (HBRUSH)0x1;
    }
  }
  else if (uMsg < 0x139) {
    if (uMsg == 0x138) {
      local_8c = wParam;
      FUN_004f3955((HDC)wParam);
      local_94 = lParam;
      local_90 = GetDlgCtrlID(lParam);
      pHVar4 = GetFocus();
      if (pHVar4 == local_94) {
        SetTextColor((HDC)local_8c,DAT_00556ae4);
      }
      else {
        SetTextColor((HDC)local_8c,DAT_00556ab0);
      }
      if (((local_90 != 0x47c) && (local_90 != 0x49a)) && (local_90 != 0x49b)) {
        SetBkMode((HDC)local_8c,1);
        pHVar3 = GetStockObject(5);
        return pHVar3;
      }
      SetBkMode((HDC)local_8c,1);
      return DAT_00556930;
    }
    if (uMsg == 0x111) {
      local_7c = (uint)wParam & 0xffff;
      if (local_7c == 1) {
        UVar2 = GetDlgItemInt(hwnd,0x477,(BOOL *)0x0,0);
        g_AiHeuristicWeight_DirectDamage[2].unused = UVar2;
        local_74 = g_AiHeuristicWeight_DirectDamage[2].unused;
        UVar2 = GetDlgItemInt(hwnd,0x479,(BOOL *)0x0,0);
        g_AiHeuristicWeight_DirectDamage[3].unused = UVar2;
        local_78 = g_AiHeuristicWeight_DirectDamage[3].unused;
        iVar5 = Ai_Subsystem_004b8dfd(local_74,local_78);
        g_AiHeuristicWeight_DirectDamage[4].unused = iVar5;
        Ai_Subsystem_004b8da0((int)DAT_00556aa0,DAT_00556930,DAT_005569c8,DAT_00556a84);
        EndDialog(hwnd,1);
      }
      else if (local_7c == 2) {
        Ai_Subsystem_004b8da0((int)DAT_00556aa0,DAT_00556930,DAT_005569c8,DAT_00556a84);
        EndDialog(hwnd,-2);
      }
      else if (((local_7c == 0x477) || (local_7c == 0x479)) && ((uint)wParam >> 0x10 == 0x400)) {
        local_74 = GetDlgItemInt(hwnd,0x477,(BOOL *)0x0,0);
        local_78 = GetDlgItemInt(hwnd,0x479,(BOOL *)0x0,0);
        SetDlgItemInt(hwnd,0x49a,local_74 - (local_78 - 1),1);
        SetDlgItemInt(hwnd,0x49b,local_78 - 1,1);
        BVar6 = 1;
        UVar2 = Ai_Subsystem_004b8dfd(local_74,local_78);
        SetDlgItemInt(hwnd,0x47c,UVar2,BVar6);
      }
      return (HBRUSH)0x1;
    }
  }
  else {
    if (uMsg < 0x312) {
      if (0x30e < uMsg) {
        pHVar3 = (HBRUSH)FUN_004f5d1a(hwnd,uMsg,wParam,lParam);
        return pHVar3;
      }
      if (uMsg != 0x200) {
        if (uMsg == 0x201) {
          SendMessageA(hwnd,0x112,0xf012,0);
          return (HBRUSH)0x0;
        }
        if (uMsg != 0x204) {
          return (HBRUSH)0x0;
        }
      }
      local_c8 = (uint)lParam & 0xffff;
      local_c4 = (uint)lParam >> 0x10;
      if (((uMsg == 0x200) && (g_DuelArenaStatusFlags != 2)) || ((uMsg == 0x204 && (g_DuelArenaStatusFlags == 2)))) {
        ptVar7 = &local_c0;
        pHVar4 = GetDlgItem(hwnd,0x475);
        GetWindowRect(pHVar4,ptVar7);
        MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_c0,2);
        if ((DAT_00556954 != 0xffffffff) &&
           (pt.y = local_c4, pt.x = local_c8, BVar6 = PtInRect(&local_c0,pt), BVar6 != 0)) {
          SendMessageA(g_MainAppWindow,0x401,DAT_00556954,0);
        }
      }
      return (HBRUSH)0x0;
    }
    if (uMsg == 0x4c8) {
      local_80 = wParam;
      local_84 = lParam;
      pHVar4 = GetDlgItem(hwnd,2);
      if (pHVar4 == local_80) {
        SendMessageA(hwnd,0x401,2,0);
      }
      else {
        SendMessageA(hwnd,0x401,1,0);
      }
      if (local_80 != (HWND)0x0) {
        InvalidateRect(local_80,(RECT *)0x0,1);
      }
      if (local_84 != (HWND)0x0) {
        InvalidateRect(local_84,(RECT *)0x0,1);
      }
      return (HBRUSH)0x0;
    }
  }
  return (HBRUSH)0x0;
}

/*
 * Ai_Subsystem_004b8cc3
 * Purpose: Tactical AI engine subsystem routine (004b8cc3).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004b8cc3
 * Entry Point: 004b8cc3
 * Size: 221 bytes
 */

void Ai_Subsystem_004b8cc3(int * arg1, int * out_buffer, int * arg3, int * arg4, int * arg5, int * arg6, int * arg7)

{
  int u_res;
  HBRUSH pHVar2;
  HPEN pHVar3;
  HGDIOBJ pvVar4;
  char local_10c [264];
  
  sprintf(local_10c,s__s_WINBK_Fireball_pic_0052d4a8,&g_AiCurrentChoiceIndex);
  u_res = Pic_Load_00423833(local_10c);
  *arg1 = u_res;
  *out_buffer = 0x10000b6;
  pHVar2 = CreateSolidBrush(0x10000e5);
  *arg3 = (int)pHVar2;
  pHVar3 = CreatePen(0,0,0x1000025);
  *arg4 = (int)pHVar3;
  pHVar3 = CreatePen(0,0,0x1000002);
  *arg5 = (int)pHVar3;
  *arg6 = 0x1000001;
  *arg7 = 0x10000bf;
  if (*arg3 == 0) {
    pvVar4 = GetStockObject(2);
    *arg3 = (int)pvVar4;
  }
  if (*arg4 == 0) {
    pvVar4 = GetStockObject(6);
    *arg4 = (int)pvVar4;
  }
  if (*arg5 == 0) {
    pvVar4 = GetStockObject(7);
    *arg5 = (int)pvVar4;
  }
  return;
}

/*
 * Ai_Subsystem_004b8da0
 * Purpose: Tactical AI engine subsystem routine (004b8da0).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004b8da0
 * Entry Point: 004b8da0
 * Size: 93 bytes
 */

void Ai_Subsystem_004b8da0(int x, HGDIOBJ arg2, HGDIOBJ arg3, HGDIOBJ arg4)

{
  if (x != 0) {
    FUN_004f4548((HANDLE)x);
  }
  if (arg2 != (HGDIOBJ)0x0) {
    DeleteObject(arg2);
  }
  if (arg3 != (HGDIOBJ)0x0) {
    DeleteObject(arg3);
  }
  if (arg4 != (HGDIOBJ)0x0) {
    DeleteObject(arg4);
  }
  return;
}

/*
 * Ai_Subsystem_004b8dfd
 * Purpose: Tactical AI engine subsystem routine (004b8dfd).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004b8dfd
 * Entry Point: 004b8dfd
 * Size: 80 bytes
 */

int Ai_Subsystem_004b8dfd(int arg1, int arg2)

{
  int local_8;
  
  if ((arg1 == 0) || (arg2 == 0)) {
    local_8 = 0;
  }
  else {
    local_8 = (arg1 - (arg2 + -1)) / arg2;
    if (local_8 < 1) {
      local_8 = 0;
    }
  }
  return local_8;
}

/*
 * Ai_FormatCardScoreString
 * Purpose: Format debugging score string for card evaluation.
 * Procedure:
 * 1. Write evaluated score breakdown to display buffer.
 */
/*
 * Decompiled function: Ai_FormatCardScoreString
 * Entry Point: 004b8e4d
 * Size: 657 bytes
 */

char * Ai_FormatCardScoreString(int arg1, int arg2)

{
  uint arg1;
  int status;
  char local_4c [52];
  int local_18;
  int local_14;
  uint local_10;
  char *local_c;
  int local_8;
  
  local_c = (char *)0x0;
  local_8 = Ai_Subsystem_004cbc65(arg1,arg2);
  if (local_8 != -1) {
    if (local_8 == DAT_006ff2dc) {
      arg1 = Ai_Util_004cbc07(arg1,arg2);
      local_8 = Ai_Subsystem_004cbd67(arg1);
    }
    local_10 = (uint)*(ushort *)(&DAT_006a5f74 + arg2 * 0x120 + arg1 * 0x5b20);
    local_14 = (int)(char)(&g_CardSlot_DamageReceived)[arg2 * 0x120 + arg1 * 0x5b20];
    local_18 = *(int *)(&g_CardSlot_TypeFlags + arg2 * 0x120 + arg1 * 0x5b20);
    if (local_8 == DAT_00695e94) {
      strcpy(&g_AiHeuristicWeight_Evasion,s_Damage_0052d4c0);
    }
    else if (local_8 == DAT_0068a70c) {
      sprintf(&g_AiHeuristicWeight_Evasion,s_Hunting___s_0052d4c8,
              (&PTR_DAT_00528cc8)
              [*(int *)(&g_CardSlot_ConvertedManaCost + arg2 * 0x120 + arg1 * 0x5b20)]);
    }
    else if (local_8 == DAT_0068a694) {
      strcpy(&g_AiHeuristicWeight_Evasion,*(char **)(&DAT_006809e4 + local_10 * 0x14));
    }
    else if (local_8 == DAT_006a2848) {
      strcpy(&g_AiHeuristicWeight_Evasion,*(char **)(&DAT_006809ec + local_10 * 0x14));
    }
    else {
      g_AiHeuristicWeight_Evasion = '\0';
    }
    if ((local_8 == DAT_0068a694) &&
       (0 < *(int *)(&g_CardSlot_TargetSlot + arg2 * 0x120 + arg1 * 0x5b20))) {
      strcpy(local_4c,&g_AiHeuristicWeight_Evasion);
      Palette_Subsystem_004a2dce
                (&g_AiHeuristicWeight_Evasion,local_4c,
                 *(int *)(&g_CardSlot_TargetSlot + arg2 * 0x120 + arg1 * 0x5b20));
    }
    status = Ai_Subsystem_004cbc65(local_14,local_18);
    if ((status == 0x361) || (status == 0x360)) {
      strcpy(&g_AiHeuristicWeight_Evasion,*(char **)(&DAT_006809e4 + status * 0x14));
    }
    if (g_AiHeuristicWeight_Evasion == '\0') {
      local_c = *(char **)(&DAT_006b3074 + local_8 * 0x98);
    }
    else {
      local_c = &g_AiHeuristicWeight_Evasion;
    }
  }
  return local_c;
}

/*
 * Ai_Subsystem_004b90de
 * Purpose: Tactical AI engine subsystem routine (004b90de).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004b90de
 * Entry Point: 004b90de
 * Size: 60 bytes
 */

void Ai_Subsystem_004b90de(int arg1, int arg2)

{
  char *output_str;
  
  output_str = (char *)Ai_FormatCardScoreString(arg1,arg2);
  if (output_str != (char *)0x0) {
    strcat(&g_OverworldWorldState,output_str);
  }
  return;
}

/*
 * Ai_CalcManaRequirement_MultiColor
 * Purpose: Calculate multicolor mana requirement for hybrid/gold spell.
 * Procedure:
 * 1. Solve optimal land tap assignment for multicolor cost.
 */
/*
 * Decompiled function: Ai_CalcManaRequirement_MultiColor
 * Entry Point: 004b9120
 * Size: 238 bytes
 */

int Ai_CalcManaRequirement_MultiColor(LPCSTR player)

{
  ATOM atom_res;
  LOGFONTA *lplf;
  char local_138 [264];
  int local_30;
  WNDCLASSA local_2c;
  
  local_30 = 1;
  local_2c.style = 0xb;
  local_2c.lpfnWndProc = Ai_CalcManaRequirement_General;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 4;
  local_2c.hInstance = g_AppHInstance;
  local_2c.hIcon = (HICON)0x0;
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = (HBRUSH)0x6;
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = prompt_text;
  atom_res = RegisterClassA(&local_2c);
  if (atom_res == 0) {
    local_30 = 0;
  }
  g_AiHeuristicWeight_BoardThreat = CreatePopupMenu();
  strcpy(local_138,&g_AiCurrentChoiceIndex);
  strcat(local_138,s__WINBK_ManaPool_pic_0052d4d4);
  g_AiHeuristicWeight_Removal = Pic_Load_00423833(local_138);
  lplf = (LOGFONTA *)FUN_004f58eb(s_ManaPool_0052d4e8,0);
  DAT_00556b1c = CreateFontIndirectA(lplf);
  return local_30;
}

/*
 * Ai_Subsystem_004b920e
 * Purpose: Tactical AI engine subsystem routine (004b920e).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004b920e
 * Entry Point: 004b920e
 * Size: 118 bytes
 */

void Ai_Subsystem_004b920e(void)

{
  if (g_AiHeuristicWeight_BoardThreat != (HMENU)0x0) {
    DestroyMenu(g_AiHeuristicWeight_BoardThreat);
  }
  g_AiHeuristicWeight_BoardThreat = (HMENU)0x0;
  if (g_AiHeuristicWeight_Removal != (HANDLE)0x0) {
    FUN_004f4548(g_AiHeuristicWeight_Removal);
  }
  g_AiHeuristicWeight_Removal = (HANDLE)0x0;
  if (DAT_00556b1c != (HGDIOBJ)0x0) {
    DeleteObject(DAT_00556b1c);
  }
  DAT_00556b1c = (HGDIOBJ)0x0;
  return;
}

/*
 * Ai_CalcManaRequirement_General
 * Purpose: General mana requirement calculator across all 5 colors.
 * Procedure:
 * 1. Verify if player has sufficient mana to cast spell.
 */
/*
 * Decompiled function: Ai_CalcManaRequirement_General
 * Entry Point: 004b9284
 * Size: 5153 bytes
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

LRESULT Ai_CalcManaRequirement_General(HWND player, uint color_index, char * required_amount, uint arg4)

{
  POINT pt;
  POINT pt_00;
  POINT pt_01;
  POINT pt_02;
  POINT pt_03;
  POINT pt_04;
  POINT pt_05;
  POINT pt_06;
  POINT pt_07;
  POINT pt_08;
  POINT pt_09;
  POINT pt_10;
  POINT pt_11;
  POINT pt_12;
  POINT pt_13;
  bool is_valid;
  UINT dwMilliseconds;
  BOOL BVar2;
  int temp_idx;
  HBRUSH pHVar4;
  LRESULT LVar5;
  int local_508;
  tagPOINT local_500;
  char local_4f8 [100];
  tagRECT local_494;
  int local_484;
  int local_480;
  char local_47c [12];
  tagPOINT local_470;
  tagRECT local_468;
  int local_458 [4];
  int local_448;
  int local_444;
  int local_440;
  char local_43c [264];
  CHAR local_334 [8];
  int local_32c;
  COLORREF local_328 [7];
  HDC local_30c;
  tagPAINTSTRUCT local_308;
  int local_2c8;
  int local_2c4;
  tagRECT local_2c0;
  tagRECT local_2b0;
  COLORREF local_2a0;
  int local_29c [7];
  uint local_280;
  uint local_27c;
  tagMSG local_278;
  tagRECT local_25c;
  BOOL local_24c;
  int local_248;
  int local_244;
  int local_240;
  tagRECT local_23c;
  uint local_22c;
  char local_228 [264];
  ULONG_PTR local_120;
  int local_11c;
  int local_118;
  int local_114;
  int local_110;
  int local_10c;
  int local_108;
  int local_104;
  char local_100 [100];
  int local_9c;
  uint local_98;
  uint local_94;
  int local_90;
  char local_8c [12];
  uint local_80;
  tagRECT local_7c;
  char local_6c [100];
  int *local_8;
  
  if (uMsg < 0x10) {
    if (uMsg == 0xf) {
      local_8 = (int *)GetWindowLongA(hwnd,0);
      Ai_Subsystem_004b7072(local_458,(uint)(hwnd != g_AiSelectedCardTargetSlot));
      if (((((*local_8 != local_458[0]) || (local_8[1] != local_458[1])) ||
           (local_8[2] != local_458[2])) ||
          ((local_8[4] != local_448 || (local_8[3] != local_458[3])))) ||
         ((local_8[5] != local_444 || (local_8[6] != local_440)))) {
        InvalidateRect(hwnd,(RECT *)0x0,0);
      }
      EnterCriticalSection((LPCRITICAL_SECTION)&g_ActiveCombatRoundCounter);
      GetClientRect(hwnd,&local_2b0);
      local_30c = g_HdcBackBuffer;
      local_2c8 = SaveDC(g_HdcBackBuffer);
      if (g_AiHeuristicWeight_Removal == (HANDLE)0x0) {
        strcpy(local_43c,&g_AiCurrentChoiceIndex);
        strcat(local_43c,s__WINBK_ManaPool_pic_0052d560);
        g_AiHeuristicWeight_Removal = (HANDLE)Pic_Load_00423833(local_43c);
      }
      if (g_AiHeuristicWeight_Removal == (HANDLE)0x0) {
        pHVar4 = GetStockObject(1);
        FillRect(local_30c,&local_2b0,pHVar4);
      }
      else {
        FUN_004f3b5f((int)local_30c,(int)&local_2b0,g_AiHeuristicWeight_Removal);
      }
      SelectObject(local_30c,DAT_00556b1c);
      SetBkMode(local_30c,1);
      SetTextAlign(local_30c,6);
      local_32c = (local_2b0.right * 0x28) / 100;
      SetMapMode(local_30c,8);
      Ai_WndProc_004ba6b6(&local_2c0,hwnd,1);
      SetWindowExtEx(local_30c,local_2c0.right - local_2c0.left,0x28,(LPSIZE)0x0);
      SetViewportExtEx(local_30c,local_2c0.right - local_2c0.left,local_2c0.bottom - local_2c0.top,
                       (LPSIZE)0x0);
      local_2a0 = 0x10000c9;
      local_328[1] = 0x10000c8;
      local_328[2] = 0x100005d;
      local_328[3] = 0x1000026;
      local_328[4] = 0x100001e;
      local_328[5] = 0x10000bf;
      local_328[0] = 0x10000c5;
      local_328[6] = 0x10000d0;
      local_2c4 = 0;
      do {
        if (6 < local_2c4) {
          RestoreDC(g_HdcBackBuffer,local_2c8);
          local_30c = BeginPaint(hwnd,&local_308);
          if (local_30c != (HDC)0x0) {
            FUN_004f3955(local_30c);
            GetClientRect(hwnd,&local_2b0);
            if (DAT_0068a674 != 0) {
              pHVar4 = GetStockObject(0);
              FillRect(local_30c,&local_2b0,pHVar4);
              Sleep(200);
            }
            BitBlt(local_30c,0,0,local_2b0.right,local_2b0.bottom,g_HdcBackBuffer,0,0,0xcc0020);
            EndPaint(hwnd,&local_308);
            *local_8 = local_458[0];
            local_8[1] = local_458[1];
            local_8[2] = local_458[2];
            local_8[4] = local_448;
            local_8[3] = local_458[3];
            local_8[5] = local_444;
            local_8[6] = local_440;
          }
          LeaveCriticalSection((LPCRITICAL_SECTION)&g_ActiveCombatRoundCounter);
          return 0;
        }
        wsprintfA(local_334,&DAT_0052d574,local_458[local_2c4]);
        Ai_WndProc_004ba6b6(&local_2c0,hwnd,local_2c4);
        DPtoLP(local_30c,(LPPOINT)&local_2c0,2);
        if (local_2c4 == 6) {
          BVar2 = IsRectEmpty(&local_2c0);
          if (BVar2 == 0) goto LAB_004b9e62;
        }
        else {
          local_2c0.left = local_2c0.left + local_32c;
LAB_004b9e62:
          SetTextColor(local_30c,local_2a0);
          temp_idx = lstrlenA(local_334);
          TextOutA(local_30c,local_2c0.left + 1,local_2c0.top + 1,local_334,temp_idx);
          SetTextColor(local_30c,local_328[local_2c4]);
          temp_idx = lstrlenA(local_334);
          TextOutA(local_30c,local_2c0.left,local_2c0.top,local_334,temp_idx);
        }
        local_2c4 = local_2c4 + 1;
      } while( true );
    }
    if (uMsg == 1) {
      local_8 = malloc(0x1c);
      local_8[6] = 0;
      local_8[5] = local_8[6];
      local_8[3] = local_8[5];
      local_8[4] = local_8[3];
      local_8[2] = local_8[4];
      local_8[1] = local_8[2];
      *local_8 = local_8[1];
      SetWindowLongA(hwnd,0,(LONG)local_8);
      if (local_8 == (int *)0x0) {
        return -1;
      }
      return 0;
    }
    if (uMsg == 2) {
      local_8 = (int *)GetWindowLongA(hwnd,0);
      free(local_8);
      return 0;
    }
  }
  else if (uMsg < 0x21) {
    if (uMsg == 0x20) {
      LVar5 = UI_WndProc_004f4fb8(hwnd,0x20,(WPARAM)wParam,lParam);
      return LVar5;
    }
    if (uMsg == 0x14) {
      return 1;
    }
  }
  else if (uMsg < 0x118) {
    if (uMsg == 0x117) {
      is_valid = false;
      for (local_480 = 0; local_480 < 7; local_480 = local_480 + 1) {
        if ((&g_AiSelectedTargetCard)[local_480] != 0) {
          is_valid = true;
        }
      }
      if ((((DAT_006b1578 != 0) && (is_valid)) &&
          ((DAT_006feec0 == 0xffffffff || (DAT_006feec0 == DAT_00627858)))) &&
         ((((DAT_006feec4 == -1 || (DAT_006feec4 == 0)) || (DAT_006feec4 == 1)) &&
          ((((DAT_006feec8 == -1 || (DAT_006feec8 == 0)) || (DAT_006feec8 == g_AiGameStateBackupBuffer)) &&
           (((DAT_006feecc == 0xffffffff || (DAT_006feecc == DAT_00627858)) &&
            ((DAT_006feed0 == 0xffffffff || ((DAT_006feed0 & 1) != 0)))))))))) {
        GetCursorPos(&local_500);
        MapWindowPoints((HWND)0x0,hwnd,&local_500,1);
        local_484 = -1;
        Ai_WndProc_004ba6b6(&local_494,hwnd,1);
        pt_07.y = local_500.y;
        pt_07.x = local_500.x;
        BVar2 = PtInRect(&local_494,pt_07);
        if (BVar2 != 0) {
          local_484 = 1;
          strcpy(local_47c,s_black_0052d578);
        }
        Ai_WndProc_004ba6b6(&local_494,hwnd,5);
        pt_08.y = local_500.y;
        pt_08.x = local_500.x;
        BVar2 = PtInRect(&local_494,pt_08);
        if (BVar2 != 0) {
          local_484 = 5;
          strcpy(local_47c,s_white_0052d580);
        }
        Ai_WndProc_004ba6b6(&local_494,hwnd,2);
        pt_09.y = local_500.y;
        pt_09.x = local_500.x;
        BVar2 = PtInRect(&local_494,pt_09);
        if (BVar2 != 0) {
          local_484 = 2;
          strcpy(local_47c,&DAT_0052d588);
        }
        Ai_WndProc_004ba6b6(&local_494,hwnd,3);
        pt_10.y = local_500.y;
        pt_10.x = local_500.x;
        BVar2 = PtInRect(&local_494,pt_10);
        if (BVar2 != 0) {
          local_484 = 3;
          strcpy(local_47c,s_green_0052d590);
        }
        Ai_WndProc_004ba6b6(&local_494,hwnd,4);
        pt_11.y = local_500.y;
        pt_11.x = local_500.x;
        BVar2 = PtInRect(&local_494,pt_11);
        if (BVar2 != 0) {
          local_484 = 4;
          strcpy(local_47c,&DAT_0052d598);
        }
        Ai_WndProc_004ba6b6(&local_494,hwnd,0);
        pt_12.y = local_500.y;
        pt_12.x = local_500.x;
        BVar2 = PtInRect(&local_494,pt_12);
        if (BVar2 != 0) {
          local_484 = 0;
          strcpy(local_47c,&DAT_0052d59c);
        }
        Ai_WndProc_004ba6b6(&local_494,hwnd,6);
        pt_13.y = local_500.y;
        pt_13.x = local_500.x;
        BVar2 = PtInRect(&local_494,pt_13);
        if (BVar2 != 0) {
          local_484 = 0;
          strcpy(local_47c,s_artifact_0052d5a4);
        }
        if (local_484 != -1) {
          sprintf(local_4f8,s_Spend_1_mana___s_0052d5b0,local_47c);
          AppendMenuA(g_AiHeuristicWeight_BoardThreat,0,local_484 + 0x65,local_4f8);
        }
      }
      temp_idx = GetMenuItemCount(g_AiHeuristicWeight_BoardThreat);
      if (0 < temp_idx) {
        AppendMenuA(g_AiHeuristicWeight_BoardThreat,0x800,0,(LPCSTR)0x0);
      }
      AppendMenuA(g_AiHeuristicWeight_BoardThreat,0,100,s_Help____0052d5c4);
      return 0;
    }
    if (uMsg == 0x111) {
      if (((uint)wParam & 0xffff) == 100) {
        local_120 = 0x7ea;
        strcpy(local_228,&DAT_006807a0);
        strcat(local_228,s__duel_hlp_0052d554);
        WinHelpA(g_MainAppHwnd,local_228,1,local_120);
      }
      else {
        local_22c = (uint)wParam & 0xffff;
        if (100 < local_22c) {
          DAT_00627858 = (uint)(hwnd != g_AiSelectedCardTargetSlot);
          g_AiGameStateBackupBuffer = local_22c - 0x65;
          g_AiTemporaryCardState = 0;
          _DAT_00556b08 = 0xfffffffd;
          _DAT_00556b0c = 0xffffffff;
          _DAT_00556b10 = 0xffffffff;
          PostMessageA(g_MainAppHwnd,0x464,0,0x556b08);
        }
      }
      return 0;
    }
  }
  else if (uMsg < 0x202) {
    if (uMsg == 0x201) {
      if (DAT_006b1578 != 0) {
        dwMilliseconds = GetDoubleClickTime();
        Sleep(dwMilliseconds);
        local_24c = PeekMessageA(&local_278,hwnd,0x203,0x203,0);
        Ai_Subsystem_004b7072(local_29c,(uint)(hwnd != g_AiSelectedCardTargetSlot));
        GetClientRect(hwnd,&local_23c);
        local_280 = lParam & 0xffff;
        local_27c = lParam >> 0x10;
        local_248 = local_23c.bottom / 6;
        DAT_00627858 = (uint)(hwnd != g_AiSelectedCardTargetSlot);
        g_AiGameStateBackupBuffer = -1;
        local_240 = local_248;
        for (local_244 = 0; local_244 < 7; local_244 = local_244 + 1) {
          Ai_WndProc_004ba6b6(&local_25c,hwnd,local_244);
          pt_06.y = local_27c;
          pt_06.x = local_280;
          BVar2 = PtInRect(&local_25c,pt_06);
          if ((BVar2 != 0) && (0 < local_29c[local_244])) {
            g_AiGameStateBackupBuffer = local_244;
          }
        }
        if ((((g_AiGameStateBackupBuffer != -1) && (DAT_006b1578 != 0)) &&
            ((DAT_006feec0 == 0xffffffff || (DAT_006feec0 == DAT_00627858)))) &&
           ((DAT_006feed0 == 0xffffffff || ((DAT_006feed0 & 1) != 0)))) {
          g_AiTemporaryCardState = local_24c;
          _DAT_00556af8 = 0xfffffffd;
          _DAT_00556afc = 0xffffffff;
          _DAT_00556b00 = 0xffffffff;
          PostMessageA(g_MainAppHwnd,0x464,0,0x556af8);
        }
      }
      return 0;
    }
    if (uMsg == 0x11f) {
      if (((uint)wParam >> 0x10 == 0xffff) && (lParam == 0)) {
        local_508 = GetMenuItemCount(g_AiHeuristicWeight_BoardThreat);
        while (local_508 != 0) {
          DeleteMenu(g_AiHeuristicWeight_BoardThreat,0,0x400);
          local_508 = local_508 + -1;
        }
      }
      return 0;
    }
  }
  else if (uMsg < 0x312) {
    if (0x30e < uMsg) {
      LVar5 = FUN_004f5d1a(hwnd,uMsg,(HWND)wParam,lParam);
      return LVar5;
    }
    if (uMsg == 0x204) {
      local_470.x = lParam & 0xffff;
      local_470.y = lParam >> 0x10;
      ClientToScreen(hwnd,&local_470);
      SetRect(&local_468,local_470.x,local_470.y,local_470.x + 1,local_470.y + 1);
      TrackPopupMenu(g_AiHeuristicWeight_BoardThreat,2,local_470.x,local_470.y,0,hwnd,&local_468);
      return 0;
    }
  }
  else {
    if (uMsg == 0x432) {
      local_8 = (int *)GetWindowLongA(hwnd,0);
      Ai_Subsystem_004b7072(&local_11c,(uint)(hwnd != g_AiSelectedCardTargetSlot));
      if ((((*local_8 != local_11c) || (local_8[1] != local_118)) || (local_8[2] != local_114)) ||
         (((local_8[4] != local_10c || (local_8[3] != local_110)) ||
          ((local_8[5] != local_108 || (local_8[6] != local_104)))))) {
        InvalidateRect(hwnd,(RECT *)0x0,0);
      }
      return 0;
    }
    if (uMsg == 0x437) {
      local_98 = lParam & 0xffff;
      local_94 = lParam >> 0x10;
      local_9c = -2;
      Ai_WndProc_004ba6b6(&local_7c,hwnd,1);
      pt.y = local_94;
      pt.x = local_98;
      BVar2 = PtInRect(&local_7c,pt);
      if (BVar2 != 0) {
        local_9c = 1;
      }
      Ai_WndProc_004ba6b6(&local_7c,hwnd,5);
      pt_00.y = local_94;
      pt_00.x = local_98;
      BVar2 = PtInRect(&local_7c,pt_00);
      if (BVar2 != 0) {
        local_9c = 5;
      }
      Ai_WndProc_004ba6b6(&local_7c,hwnd,2);
      pt_01.y = local_94;
      pt_01.x = local_98;
      BVar2 = PtInRect(&local_7c,pt_01);
      if (BVar2 != 0) {
        local_9c = 2;
      }
      Ai_WndProc_004ba6b6(&local_7c,hwnd,3);
      pt_02.y = local_94;
      pt_02.x = local_98;
      BVar2 = PtInRect(&local_7c,pt_02);
      if (BVar2 != 0) {
        local_9c = 3;
      }
      Ai_WndProc_004ba6b6(&local_7c,hwnd,4);
      pt_03.y = local_94;
      pt_03.x = local_98;
      BVar2 = PtInRect(&local_7c,pt_03);
      if (BVar2 != 0) {
        local_9c = 4;
      }
      Ai_WndProc_004ba6b6(&local_7c,hwnd,0);
      pt_04.y = local_94;
      pt_04.x = local_98;
      BVar2 = PtInRect(&local_7c,pt_04);
      if (BVar2 != 0) {
        local_9c = 0;
      }
      Ai_WndProc_004ba6b6(&local_7c,hwnd,6);
      pt_05.y = local_94;
      pt_05.x = local_98;
      BVar2 = PtInRect(&local_7c,pt_05);
      if (BVar2 != 0) {
        local_9c = 6;
      }
      local_80 = (uint)(hwnd != g_AiSelectedCardTargetSlot);
      if (local_80 == 0) {
        strcpy(local_6c,&DAT_0052d4f4);
      }
      else {
        Ai_Subsystem_004b6f49(local_6c);
      }
      strcat(local_6c,s_mana_pool_0052d4fc);
      if (local_9c == 1) {
        strcpy(local_8c,s_Black_0052d508);
      }
      else if (local_9c == 5) {
        strcpy(local_8c,s_White_0052d510);
      }
      else if (local_9c == 2) {
        strcpy(local_8c,&DAT_0052d518);
      }
      else if (local_9c == 3) {
        strcpy(local_8c,s_Green_0052d520);
      }
      else if (local_9c == 4) {
        strcpy(local_8c,&DAT_0052d528);
      }
      else if (local_9c == 0) {
        strcpy(local_8c,&DAT_0052d52c);
      }
      else if (local_9c == 6) {
        strcpy(local_8c,s_Artifact_0052d534);
      }
      if (((local_9c == 0) || (local_9c == 1)) ||
         ((local_9c == 5 ||
          ((((local_9c == 3 || (local_9c == 4)) || (local_9c == 2)) || (local_9c == 6)))))) {
        sprintf(local_100,s__s__amount_of__s_0052d540,local_6c,local_8c);
        local_90 = 1;
      }
      else {
        local_90 = 0;
      }
      if (local_90 == 0) {
        return 0;
      }
      strcpy(wParam,local_100);
      return local_90;
    }
  }
  LVar5 = DefWindowProcA(hwnd,uMsg,(WPARAM)wParam,lParam);
  return LVar5;
}

/*
 * Ai_WndProc_004ba6b6
 * Purpose: Process window messages for tactical AI interface (004ba6b6).
 * Procedure:
 * 1. Handle window messages (WM_PAINT, WM_COMMAND, mouse).
 * 2. Update interface state.
 */
/*
 * Decompiled function: Ai_WndProc_004ba6b6
 * Entry Point: 004ba6b6
 * Size: 472 bytes
 */

void Ai_WndProc_004ba6b6(LPRECT lprect, HWND hwnd_target, int wParam)

{
  uint8_t local_48 [24];
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  tagRECT local_18;
  int local_8;
  
  Ai_Subsystem_004b7072(local_48,(uint)(hwnd != g_AiSelectedCardTargetSlot));
  GetClientRect(hwnd,&local_18);
  local_20 = (local_18.bottom * 5) / 100;
  local_28 = (local_18.bottom * 0x91) / 1000;
  local_24 = (local_18.bottom * 0x14) / 1000;
  if (arg3 == 1) {
    local_2c = 0;
  }
  else if (arg3 == 2) {
    local_2c = 1;
  }
  else if (arg3 == 3) {
    local_2c = 2;
  }
  else if (arg3 == 4) {
    local_2c = 3;
  }
  else if (arg3 == 5) {
    local_2c = 4;
  }
  else if (arg3 == 0) {
    local_2c = 5;
  }
  else if (arg3 == 6) {
    local_2c = 5;
  }
  else {
    local_2c = -1;
  }
  if (local_2c == -1) {
    SetRect(arg1,0,0,0,0);
  }
  else {
    local_8 = (local_24 + local_28) * local_2c + local_20;
    local_1c = local_8 + local_28;
    SetRect(arg1,local_18.left,local_8,local_18.right,local_1c);
    if (local_30 == 0) {
      if (arg3 == 6) {
        SetRect(arg1,0,0,0,0);
      }
    }
    else if (arg3 == 0) {
      arg1->right = arg1->right - (local_18.right - local_18.left) / 2;
    }
    else if (arg3 == 6) {
      arg1->left = arg1->left + ((local_18.right - local_18.left) * 2) / 3;
    }
  }
  return;
}

/*
 * Ai_CalcManaRequirement_PayCost
 * Purpose: Simulate tapping lands and paying mana cost.
 * Procedure:
 * 1. Deduct required mana from simulated player pool.
 */
/*
 * Decompiled function: Ai_CalcManaRequirement_PayCost
 * Entry Point: 004ba890
 * Size: 4252 bytes
 */

/* WARNING: Heritage AFTER dead removal. Example location: r0x006b2d58 : 0x004bb0c4 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

int Ai_CalcManaRequirement_PayCost(int player, int color_index, int required_amount)

{
  int status;
  int local_d8;
  int aiStack_d4 [8];
  int local_b4;
  int aiStack_b0 [8];
  int local_90;
  int local_8c;
  int local_88;
  uint local_84;
  uint local_80;
  uint local_7c;
  uint local_78;
  int local_74;
  int local_70;
  uint local_6c;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50 [7];
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  uint local_1c;
  uint local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if ((g_PlayerHandCardCount._1_1_ & 4) == 0) {
    (&g_AiSelectedTargetCard)[arg2] = (&g_AiSelectedTargetCard)[arg2] + arg3;
    local_10 = 0;
    for (local_1c = 0; (int)local_1c < 7; local_1c = local_1c + 1) {
      local_50[local_1c] = 0;
    }
    status = FUN_0040d949(arg1,6,1);
    local_24 = FUN_0040d949(arg1,7,1);
    local_24 = status - local_24;
    local_8 = 1;
    if ((((g_AiTemporaryCardState == 0) && (arg1 != 1)) && (g_IsAiThinking != 1)) && (g_AiTurnDecisionFlag == 0)) {
      local_c = 0;
      local_28 = 0;
      local_2c = 0;
      local_34 = 0;
      local_54 = 0;
    }
    else {
      local_54 = 1;
      local_34 = 1;
      local_2c = 1;
      if (((arg1 == 1) || (g_IsAiThinking == 1)) || (g_AiTurnDecisionFlag != 0)) {
        local_28 = 1;
        local_c = 1;
      }
      else {
        local_c = 0;
        local_28 = 0;
      }
    }
    status = g_OverworldPlayerCoordY;
    if (arg1 == g_ActivePlayerPriority) {
      for (local_1c = 0; (int)local_1c < 7; local_1c = local_1c + 1) {
        if ((&g_AiSelectedTargetCard)[local_1c] == -1) {
          local_64 = FUN_0040d949(arg1,local_1c,1);
          if (g_IsAiThinking == 1) {
            status = FUN_0040a1d2(3);
            if ((status == 0) || (local_64 < 2)) {
              local_60 = local_64;
            }
            else {
              local_60 = FUN_0040a1d2(local_64 + -1);
              local_60 = local_60 + 1;
            }
            g_AiDecisionScore = local_60;
            Ai_EvaluateCreaturePower();
          }
          else {
            Ai_CalcCardAdvantage();
            if (g_AiDecisionScore == 99) {
              g_AiDecisionScore = 0;
            }
            local_60 = g_AiDecisionScore;
          }
        }
      }
      if (g_OverworldPlayerCoordY == -1) {
        g_OverworldPlayerCoordY = local_60;
        status = g_OverworldPlayerCoordY;
      }
      else {
        status = local_60;
        if (g_OverworldPlayerCoordY <= local_60) {
          status = g_OverworldPlayerCoordY;
        }
      }
    }
    g_OverworldPlayerCoordY = status;
    g_TurnCounter = 0;
    if (g_OverworldPlayerCoordY == 0) {
      for (local_1c = 0; (int)local_1c < 7; local_1c = local_1c + 1) {
        if ((&g_AiSelectedTargetCard)[local_1c] == -1) {
          (&g_AiSelectedTargetCard)[local_1c] = 0;
        }
      }
    }
    local_58 = 0;
    for (local_1c = 0; (int)local_1c < 7; local_1c = local_1c + 1) {
      if ((&g_AiSelectedTargetCard)[local_1c] == -1) {
        local_58 = 1;
      }
    }
    if ((local_8 != 0) &&
       (status = Ai_Subsystem_004bbf8e(0x6b2d40,g_TurnCounter,g_OverworldPlayerCoordY), status == 0))
    {
      Ai_Subsystem_004bb9f3(arg1,local_50,&local_10,local_24);
      Ai_EvalAbility_Regeneration();
    }
    if (((local_54 != 0) &&
        (status = Ai_Subsystem_004bbf8e(0x6b2d40,g_TurnCounter,g_OverworldPlayerCoordY), status == 0))
       && (local_58 != 0)) {
      Ai_Subsystem_004bbb99
                (arg1,local_50,&local_10,local_24,&g_TurnCounter,g_OverworldPlayerCoordY);
      Ai_EvalAbility_Regeneration();
    }
    if ((local_34 != 0) &&
       (status = Ai_Subsystem_004bbf8e(0x6b2d40,g_TurnCounter,g_OverworldPlayerCoordY), status == 0))
    {
      Ai_Subsystem_004bbd93
                (arg1,local_50,&local_10,local_24,&g_TurnCounter,g_OverworldPlayerCoordY);
      Ai_EvalAbility_Regeneration();
    }
    if ((local_2c != 0) &&
       (status = Ai_Subsystem_004bbf8e(0x6b2d40,g_TurnCounter,g_OverworldPlayerCoordY), status == 0))
    {
      status = Ai_Subsystem_004bbf8e(0x6b2d40,g_TurnCounter,g_OverworldPlayerCoordY);
      if (status == 0) {
        Ai_Subsystem_004bc72e(arg1,local_50,&local_10,0x1e,local_c);
      }
      status = Ai_Subsystem_004bbf8e(0x6b2d40,g_TurnCounter,g_OverworldPlayerCoordY);
      if (status == 0) {
        Ai_Subsystem_004bc72e(arg1,local_50,&local_10,0x1c,local_c);
      }
    }
    if ((local_28 != 0) &&
       (status = Ai_Subsystem_004bbf8e(0x6b2d40,g_TurnCounter,g_OverworldPlayerCoordY), status == 0))
    {
      status = Ai_Subsystem_004bbf8e(0x6b2d40,g_TurnCounter,g_OverworldPlayerCoordY);
      if (status == 0) {
        Ai_Subsystem_004bc72e(arg1,local_50,&local_10,0x14,local_c);
      }
      status = Ai_Subsystem_004bbf8e(0x6b2d40,g_TurnCounter,g_OverworldPlayerCoordY);
      if (status == 0) {
        Ai_Subsystem_004bc72e(arg1,local_50,&local_10,4,local_c);
      }
      status = Ai_Subsystem_004bbf8e(0x6b2d40,g_TurnCounter,g_OverworldPlayerCoordY);
      if (status == 0) {
        Ai_Subsystem_004bc72e(arg1,local_50,&local_10,0x1a,local_c);
      }
      status = Ai_Subsystem_004bbf8e(0x6b2d40,g_TurnCounter,g_OverworldPlayerCoordY);
      if (status == 0) {
        Ai_Subsystem_004bc72e(arg1,local_50,&local_10,0x18,local_c);
      }
      status = Ai_Subsystem_004bbf8e(0x6b2d40,g_TurnCounter,g_OverworldPlayerCoordY);
      if (status == 0) {
        Ai_Subsystem_004bc72e(arg1,local_50,&local_10,0x10,local_c);
      }
      status = Ai_Subsystem_004bbf8e(0x6b2d40,g_TurnCounter,g_OverworldPlayerCoordY);
      if (status == 0) {
        Ai_Subsystem_004bc72e(arg1,local_50,&local_10,0,local_c);
      }
    }
    if (((arg1 == 1) || (g_IsAiThinking == 1)) || (g_AiTurnDecisionFlag != 0)) {
      status = Ai_Subsystem_004bbf8e(0x6b2d40,g_TurnCounter,g_OverworldPlayerCoordY);
      if ((status == 0) && (local_58 == 0)) {
        g_ActivePlayer = 1;
      }
    }
    else {
      status = Ai_Subsystem_004bbf8e(0x6b2d40,g_TurnCounter,g_OverworldPlayerCoordY);
      if (status == 0) {
        local_5c = 0;
        while ((local_5c == 0 &&
               (status = Ai_Subsystem_004bbf8e(0x6b2d40,g_TurnCounter,g_OverworldPlayerCoordY),
               status == 0))) {
          local_68 = 1;
          for (local_1c = 0; (int)local_1c < 7; local_1c = local_1c + 1) {
            if (0 < (&g_AiSelectedTargetCard)[local_1c]) {
              local_68 = 0;
            }
          }
          Ai_Subsystem_004bc029
                    (&g_OverworldWorldState,&g_AiSelectedTargetCard,g_TurnCounter,g_OverworldPlayerCoordY);
          local_30 = Duel_LogActionStatusBanner
                               (arg1,arg1,arg1,0,0,&g_OverworldWorldState,
                                (-(uint)(local_68 == 0) & 0xfffffffe) + 3);
          if ((_DAT_0063ee20 == -1) && ((local_30 == -1 || (local_30 == -2)))) {
            if (DAT_0063ee8c == -2) {
              if ((DAT_00627a84 == -1) && (DAT_00627a88 == -1)) {
                if (local_30 == -1) {
                  g_ActivePlayer = 1;
                }
                local_5c = 1;
              }
              else if (local_68 != 0) {
                local_5c = 1;
              }
            }
            else if (((DAT_0063ee8c == -3) && (DAT_00627858 == arg1)) &&
                    (g_AiGameStateBackupBuffer != 0xffffffff)) {
              if ((0 < *(int *)(&g_AiLookaheadDepth + g_AiGameStateBackupBuffer * 4 + arg1 * 0x20)) &&
                 (((((&g_AiSelectedTargetCard)[g_AiGameStateBackupBuffer] != 0 || (g_AiSelectedTargetCard != 0)) ||
                   (g_AiSelectedTargetPlayer != 0)) && ((g_AiGameStateBackupBuffer != 6 || (g_AiSelectedTargetPlayer != 0)))))) {
                if ((&g_AiSelectedTargetCard)[g_AiGameStateBackupBuffer] == 0) {
                  if (g_AiSelectedTargetPlayer == 0) {
                    local_6c = 0;
                  }
                  else {
                    local_6c = 6;
                  }
                }
                else {
                  local_6c = g_AiGameStateBackupBuffer;
                }
                local_70 = Ai_Subsystem_004bd459
                                     (0x6b2d40,local_6c,(int)(&g_AiLookaheadDepth + arg1 * 0x20),
                                      g_AiGameStateBackupBuffer,g_AiTemporaryCardState,g_OverworldPlayerCoordY,
                                      g_TurnCounter);
                Ai_Subsystem_004bd3e9
                          (0x6b2d40,local_6c,local_70,&g_TurnCounter,g_OverworldPlayerCoordY,arg1,
                           g_AiGameStateBackupBuffer,(int)local_50,&local_10);
                Ai_EvalAbility_Regeneration();
              }
              if (0 < (&g_AiSelectedTargetCard)[g_AiGameStateBackupBuffer]) {
                local_78 = 0;
                local_20 = 0;
                while ((local_20 < 10 &&
                       (*(int *)(&g_AiTempTargetBuffer + local_20 * 4 + arg1 * 0x2c) != -1))) {
                  local_80 = (uint)*(ushort *)(&g_AiTempTargetBuffer + local_20 * 4 + arg1 * 0x2c);
                  status = local_20 * 4;
                  if (g_AiGameStateBackupBuffer == local_80) {
                    local_84._0_1_ = (byte)(*(uint *)(&g_AiTempTargetBuffer + status + arg1 * 0x2c) >> 0x10)
                    ;
                    local_78 = local_78 | 1 << ((byte)local_84 & 0x1f);
                  }
                  local_20 = local_20 + 1;
                  local_84 = *(uint *)(&g_AiTempTargetBuffer + status + arg1 * 0x2c) >> 0x10;
                }
                local_7c = 0;
                for (local_1c = 0; (int)local_1c < 7; local_1c = local_1c + 1) {
                  if ((&g_AiSelectedTargetCard)[local_1c] != 0) {
                    local_7c = local_7c | 1 << ((byte)local_1c & 0x1f);
                  }
                }
                local_78 = local_78 & local_7c;
                if (local_78 != 0) {
                  local_74 = 0;
                  for (local_1c = 0; (int)local_1c < 7; local_1c = local_1c + 1) {
                    if ((local_78 & 1 << ((byte)local_1c & 0x1f)) != 0) {
                      local_74 = local_74 + 1;
                    }
                  }
                  if (local_74 == 1) {
                    local_88 = FUN_00473cc5((byte)local_78);
                  }
                  else {
                    local_88 = Ai_Subsystem_004cc93d
                                         (arg1,s_Which_color_to_use_that_choice_a_0052d5d0,1,
                                          g_AiGameStateBackupBuffer,local_78);
                  }
                  local_8c = Ai_Subsystem_004bd459
                                       (0x6b2d40,local_88,(int)(&g_AiLookaheadDepth + arg1 * 0x20),
                                        g_AiGameStateBackupBuffer,g_AiTemporaryCardState,g_OverworldPlayerCoordY,
                                        g_TurnCounter);
                  Ai_Subsystem_004bd3e9
                            (0x6b2d40,local_88,local_8c,&g_TurnCounter,g_OverworldPlayerCoordY,arg1
                             ,g_AiGameStateBackupBuffer,(int)local_50,&local_10);
                  Ai_EvalAbility_Regeneration();
                }
              }
            }
          }
          else if ((((_DAT_0063ee20 == -1) || (local_30 != -1)) &&
                   (local_14 = *(int *)(&g_CardSlot_CardId + local_30 * 0x120 + arg1 * 0x5b20),
                   ((&DAT_0051aed1)[local_14 * 0x34] & 0x10) != 0)) &&
                  ((((&g_MasterCardColorTable)[local_14 * 0x34] & 0x20) != 0 ||
                   (((((&g_CardSlot_Flags)[local_30 * 0x120 + arg1 * 0x5b20] & 2) != 0 &&
                     (((&g_CardSlot_Flags)[local_30 * 0x120 + arg1 * 0x5b20] & 0x10) == 0)) &&
                    ((((&DAT_006a5f3e)[local_30 * 0x120 + arg1 * 0x5b20] & 3) == 0 ||
                     (((&g_MasterCardColorTable)
                       [*(int *)(&g_CardSlot_CardId + local_30 * 0x120 + arg1 * 0x5b20) * 0x34] & 2
                      ) == 0)))))))) {
            for (local_d8 = 0; local_d8 < 8; local_d8 = local_d8 + 1) {
              aiStack_d4[local_d8] = *(int *)(&g_AiLookaheadDepth + local_d8 * 4 + arg1 * 0x20);
            }
            local_b4 = g_TurnCounter;
            g_TurnCounter = 0;
            local_90 = g_OverworldPlayerCoordY;
            g_OverworldPlayerCoordY = -1;
            for (local_d8 = 0; local_d8 < 7; local_d8 = local_d8 + 1) {
              aiStack_b0[local_d8] = (&g_AiSelectedTargetCard)[local_d8];
              (&g_AiSelectedTargetCard)[local_d8] = 0;
            }
            if (((&g_CardSlot_Flags)[local_30 * 0x120 + arg1 * 0x5b20] & 2) == 0) {
              FUN_0046fe86(arg1,local_30);
              Ai_Turn_ExecuteMainPhase(0,0xff);
            }
            else if ((((&g_MasterCardColorTable)[local_14 * 0x34] & 1) != 0) ||
                    (status = Magic_TriggerCardEvent(arg1,local_30,0x73,1 - arg1,0xffffffff),
                    status != 0)) {
              Magic_CombatPhase(arg1,local_30,0x72,arg1,0);
              g_AiManaPoolReserve = 1;
              DAT_006ff2d4 = 0xffffffff;
              local_18 = *(uint *)(&g_CardSlot_Flags + local_30 * 0x120 + arg1 * 0x5b20) & 0x10;
              Magic_TriggerCardEvent(arg1,local_30,0x6d,1 - arg1,0xffffffff);
              g_AiManaPoolReserve = 0;
              if (g_ActivePlayer == 1) {
                g_ActivePlayer = 0;
                Magic_DiscardToHandSize();
              }
              else {
                if ((local_18 == 0) &&
                   (((&g_CardSlot_Flags)[local_30 * 0x120 + arg1 * 0x5b20] & 0x10) != 0)) {
                  FUN_00473e69(arg1,local_30,0x81);
                }
                if (g_IsAiThinking != 1) {
                  Magic_UpkeepPhase(0x12);
                }
                Magic_EndTurnPhase();
                Ai_Turn_ExecuteMainPhase(0,0xff);
              }
            }
            g_TurnCounter = local_b4;
            g_OverworldPlayerCoordY = local_90;
            for (local_d8 = 0; local_d8 < 7; local_d8 = local_d8 + 1) {
              (&g_AiSelectedTargetCard)[local_d8] = aiStack_b0[local_d8];
            }
            for (local_d8 = 0; local_d8 < 8; local_d8 = local_d8 + 1) {
              *(int *)(&g_AiLookaheadDepth + local_d8 * 4 + arg1 * 0x20) =
                   *(int *)(&g_AiLookaheadDepth + local_d8 * 4 + arg1 * 0x20) - aiStack_d4[local_d8];
            }
            status = FUN_0040d949(arg1,6,1);
            local_24 = FUN_0040d949(arg1,7,1);
            local_24 = status - local_24;
            Ai_Subsystem_004bb9f3(arg1,local_50,&local_10,local_24);
            Ai_Subsystem_004bbb99
                      (arg1,local_50,&local_10,local_24,&g_TurnCounter,g_OverworldPlayerCoordY);
            Ai_Subsystem_004bbd93
                      (arg1,local_50,&local_10,local_24,&g_TurnCounter,g_OverworldPlayerCoordY);
            for (local_d8 = 0; local_d8 < 8; local_d8 = local_d8 + 1) {
              *(int *)(&g_AiLookaheadDepth + local_d8 * 4 + arg1 * 0x20) =
                   *(int *)(&g_AiLookaheadDepth + local_d8 * 4 + arg1 * 0x20) + aiStack_d4[local_d8];
            }
            Ai_EvalAbility_Regeneration();
          }
        }
      }
    }
  }
  if (g_ActivePlayer == 1) {
    Ai_Subsystem_004bd682((int)local_50);
    for (local_1c = 0; (int)local_1c < 7; local_1c = local_1c + 1) {
      FUN_0040d875(arg1,local_1c,local_50[local_1c]);
      local_50[local_1c] = 0;
    }
    local_10 = 0;
    g_TurnCounter = 0;
  }
  for (local_1c = 0; (int)local_1c < 7; local_1c = local_1c + 1) {
    (&g_AiSelectedTargetCard)[local_1c] = 0;
  }
  g_OverworldPlayerCoordY = -1;
  return local_10;
}

/*
 * Ai_Subsystem_004bb9f3
 * Purpose: Tactical AI engine subsystem routine (004bb9f3).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004bb9f3
 * Entry Point: 004bb9f3
 * Size: 422 bytes
 */

void Ai_Subsystem_004bb9f3(int x, int arg2, int * arg3, int height)

{
  ushort u_res;
  uint u_temp;
  int local_c;
  int local_8;
  
  for (local_8 = 0; local_8 < 7; local_8 = local_8 + 1) {
    while ((0 < (int)(&g_AiSelectedTargetCard)[local_8] &&
           (0 < *(int *)(&g_AiLookaheadDepth + local_8 * 4 + x * 0x20)))) {
      Ai_Subsystem_004bd3e9(0x6b2d40,local_8,1,(int *)0x0,0,x,local_8,arg2,arg3);
    }
  }
  while (((0 < g_AiSelectedTargetPlayer && (0 < *(int *)(&g_AiLookaheadDepth + x * 0x20))) && (height < g_AiSelectedTargetPlayer))
        ) {
    Ai_Subsystem_004bd3e9(0x6b2d40,6,1,(int *)0x0,0,x,0,arg2,arg3);
  }
  local_c = 0;
  while ((local_c < 10 && (*(int *)(&g_AiTempTargetBuffer + local_c * 4 + x * 0x2c) != -1))) {
    u_res = *(ushort *)(&g_AiTempTargetBuffer + local_c * 4 + x * 0x2c);
    u_temp = *(uint *)(&g_AiTempTargetBuffer + local_c * 4 + x * 0x2c);
    while ((0 < *(int *)(&g_AiLookaheadDepth + (uint)u_res * 4 + x * 0x20) &&
           (0 < (int)(&g_AiSelectedTargetCard)[u_temp >> 0x10]))) {
      Ai_Subsystem_004bd3e9(0x6b2d40,u_temp >> 0x10,1,(int *)0x0,0,x,(uint)u_res,arg2,arg3);
    }
    local_c = local_c + 1;
  }
  return;
}

/*
 * Ai_Subsystem_004bbb99
 * Purpose: Tactical AI engine subsystem routine (004bbb99).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004bbb99
 * Entry Point: 004bbb99
 * Size: 506 bytes
 */

void Ai_Subsystem_004bbb99(int arg1, int arg2, int * arg3, int arg4, int * arg5, int arg6)

{
  ushort u_res;
  uint u_temp;
  int local_c;
  int local_8;
  
  for (local_8 = 0; local_8 < 7; local_8 = local_8 + 1) {
    if ((&g_AiSelectedTargetCard)[local_8] == -1) {
      while ((0 < *(int *)(&g_AiLookaheadDepth + local_8 * 4 + arg1 * 0x20) &&
             ((g_TurnCounter < arg6 || (arg6 == -1))))) {
        Ai_Subsystem_004bd3e9(0x6b2d40,local_8,1,arg5,arg6,arg1,local_8,arg2,arg3);
      }
    }
  }
  if (g_AiSelectedTargetPlayer == -1) {
    while (((0 < *(int *)(&g_AiLookaheadDepth + arg1 * 0x20) && (arg4 < g_AiSelectedTargetPlayer)) &&
           ((g_TurnCounter < arg6 || (arg6 == -1))))) {
      Ai_Subsystem_004bd3e9(0x6b2d40,6,1,arg5,arg6,arg1,0,arg2,arg3);
    }
  }
  local_c = 0;
  while ((local_c < 10 && (*(int *)(&g_AiTempTargetBuffer + local_c * 4 + arg1 * 0x2c) != -1))) {
    u_res = *(ushort *)(&g_AiTempTargetBuffer + local_c * 4 + arg1 * 0x2c);
    u_temp = *(uint *)(&g_AiTempTargetBuffer + local_c * 4 + arg1 * 0x2c);
    if ((&g_AiSelectedTargetCard)[u_temp >> 0x10] == -1) {
      while ((0 < *(int *)(&g_AiLookaheadDepth + (uint)u_res * 4 + arg1 * 0x20) &&
             ((g_TurnCounter < arg6 || (arg6 == -1))))) {
        Ai_Subsystem_004bd3e9(0x6b2d40,u_temp >> 0x10,1,arg5,arg6,arg1,(uint)u_res,arg2,arg3);
      }
    }
    local_c = local_c + 1;
  }
  return;
}

/*
 * Ai_Subsystem_004bbd93
 * Purpose: Tactical AI engine subsystem routine (004bbd93).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004bbd93
 * Entry Point: 004bbd93
 * Size: 507 bytes
 */

void Ai_Subsystem_004bbd93(int arg1, int arg2, int * arg3, int arg4, int * arg5, int arg6)

{
  int local_8;
  
  if (g_AiSelectedTargetPlayer != 0) {
    for (local_8 = 0; local_8 < 7; local_8 = local_8 + 1) {
      if (g_AiSelectedTargetPlayer < 1) {
        while (((0 < *(int *)(&g_AiLookaheadDepth + local_8 * 4 + arg1 * 0x20) && (g_AiSelectedTargetPlayer == -1))
               && ((arg6 == -1 || (arg4 < arg6 - g_TurnCounter))))) {
          Ai_Subsystem_004bd3e9(0x6b2d40,6,1,arg5,arg6,arg1,local_8,arg2,arg3);
        }
      }
      else {
        while ((0 < *(int *)(&g_AiLookaheadDepth + local_8 * 4 + arg1 * 0x20) && (arg4 < g_AiSelectedTargetPlayer)))
        {
          Ai_Subsystem_004bd3e9(0x6b2d40,6,1,(int *)0x0,0,arg1,local_8,arg2,arg3);
        }
      }
    }
  }
  if (g_AiSelectedTargetCard != 0) {
    for (local_8 = 0; local_8 < 7; local_8 = local_8 + 1) {
      if (local_8 != 6) {
        if (g_AiSelectedTargetCard == -1) {
          while ((0 < *(int *)(&g_AiLookaheadDepth + local_8 * 4 + arg1 * 0x20) &&
                 ((g_TurnCounter < arg6 || (arg6 == -1))))) {
            Ai_Subsystem_004bd3e9(0x6b2d40,0,1,arg5,arg6,arg1,local_8,arg2,arg3);
          }
        }
        else {
          while ((0 < g_AiSelectedTargetCard && (0 < *(int *)(&g_AiLookaheadDepth + local_8 * 4 + arg1 * 0x20)))) {
            Ai_Subsystem_004bd3e9(0x6b2d40,0,1,(int *)0x0,0,arg1,local_8,arg2,arg3);
          }
        }
      }
    }
  }
  return;
}

/*
 * Ai_Subsystem_004bbf8e
 * Purpose: Tactical AI engine subsystem routine (004bbf8e).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004bbf8e
 * Entry Point: 004bbf8e
 * Size: 155 bytes
 */

int Ai_Subsystem_004bbf8e(int arg1, int arg2, int arg3)

{
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (6 < local_8) {
      return 1;
    }
    if (0 < *(int *)(arg1 + local_8 * 4)) break;
    if (((*(int *)(arg1 + local_8 * 4) == -1) && (arg3 != -1)) && (arg2 < arg3)) {
      return 0;
    }
    if ((*(int *)(arg1 + local_8 * 4) == -1) && (arg3 == -1)) {
      return 0;
    }
    local_8 = local_8 + 1;
  }
  return 0;
}

/*
 * Ai_Subsystem_004bc029
 * Purpose: Tactical AI engine subsystem routine (004bc029).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004bc029
 * Entry Point: 004bc029
 * Size: 1018 bytes
 */

int Ai_Subsystem_004bc029(int spell_id, int * target_id, int flags, int height)

{
  size_t s_res;
  int val_result;
  int temp_idx;
  char *pcVar4;
  int u_extra;
  int iVar6;
  int local_8c;
  char local_88 [100];
  int local_24;
  size_t local_20;
  uint local_1c;
  int local_18;
  int local_14;
  char local_10;
  uint local_c;
  int local_8;
  
  g_OverworldWorldState = 0;
  local_1c = FUN_00474d4a();
  if (local_1c == 0xffffffff) {
    strcpy(&g_OverworldWorldState,&DAT_0052d640);
  }
  else {
    local_8 = *(int *)(&DAT_006fecb8 + g_AiEvaluatedMoveCount * 8);
    local_24 = *(int *)(&DAT_006fecbc + g_AiEvaluatedMoveCount * 8);
    local_c = local_1c >> 0x10 & 0xff;
    if (local_c == 0x71) {
      strcpy(&g_OverworldWorldState,s_CASTING__0052d5f4);
      Ai_Subsystem_004b90de(local_8,local_24);
      strcat(&g_OverworldWorldState,s___tap_0052d600);
    }
    else if (local_c == 0x72) {
      strcpy(&g_OverworldWorldState,s_ACTIVATING__0052d608);
      Ai_Subsystem_004b90de(local_8,local_24);
      strcat(&g_OverworldWorldState,s___tap_0052d618);
    }
    else if (local_c == 0x7e) {
      strcpy(&g_OverworldWorldState,s_PROCESSING__0052d620);
      Ai_Subsystem_004b90de(local_8,local_24);
      strcat(&g_OverworldWorldState,s___tap_0052d630);
    }
    else {
      strcpy(&g_OverworldWorldState,&DAT_0052d638);
    }
  }
  local_88[0] = '\0';
  if ((*target_id == -1) || (target_id[6] == -1)) {
    if (height == -1) {
      u_extra = 0xfffffff0;
      pcVar4 = s__c__d_so_far__0052d648;
      iVar6 = flags;
      s_res = strlen(local_88);
      sprintf(local_88 + s_res,pcVar4,u_extra,iVar6);
    }
    else if (flags < height) {
      u_extra = 0xfffffff0;
      pcVar4 = s__c__d_so_far__max__d__0052d658;
      iVar6 = flags;
      val_result = height;
      s_res = strlen(local_88);
      sprintf(local_88 + s_res,pcVar4,u_extra,iVar6,val_result);
    }
  }
  else if ((*target_id != 0) || (target_id[6] != 0)) {
    local_8c = target_id[6];
    iVar6 = *target_id;
    local_20 = strlen(local_88);
    for (local_8c = local_8c + iVar6; 9 < local_8c; local_8c = local_8c + -10) {
      local_88[local_20] = -0x11;
      iVar6 = local_20 + 1;
      local_20 = local_20 + 1;
      local_88[iVar6] = '\0';
    }
    if (local_8c != 0) {
      local_88[local_20] = (char)local_8c + -0xf;
      iVar6 = local_20 + 1;
      local_20 = local_20 + 1;
      local_88[iVar6] = '\0';
    }
  }
  for (local_14 = 1; local_14 < 6; local_14 = local_14 + 1) {
    if (local_14 == 1) {
      local_10 = -2;
    }
    else if (local_14 == 2) {
      local_10 = -3;
    }
    else if (local_14 == 3) {
      local_10 = -1;
    }
    else if (local_14 == 4) {
      local_10 = -4;
    }
    else {
      local_10 = -5;
    }
    if (target_id[local_14] == -1) {
      if (height == -1) {
        val_result = (int)local_10;
        pcVar4 = s__c__d_so_far__0052d670;
        iVar6 = flags;
        s_res = strlen(local_88);
        sprintf(local_88 + s_res,pcVar4,val_result,iVar6);
      }
      else if (flags < height) {
        temp_idx = (int)local_10;
        pcVar4 = s__c__d_so_far__max__d__0052d680;
        iVar6 = flags;
        val_result = height;
        s_res = strlen(local_88);
        sprintf(local_88 + s_res,pcVar4,temp_idx,iVar6,val_result);
      }
    }
    else if (target_id[local_14] != 0) {
      local_20 = strlen(local_88);
      for (local_18 = 0; local_18 < target_id[local_14]; local_18 = local_18 + 1) {
        local_88[local_20] = local_10;
        local_20 = local_20 + 1;
      }
      local_88[local_20] = '\0';
    }
  }
  strcat(&g_OverworldWorldState,local_88);
  return 0;
}

/*
 * Ai_CalcMana_004bc423
 * Purpose: Calculate mana requirements and available sources (004bc423).
 * Procedure:
 * 1. Query untapped mana sources.
 * 2. Verify spell cost.
 */
/*
 * Decompiled function: Ai_CalcMana_004bc423
 * Entry Point: 004bc423
 * Size: 675 bytes
 */

int Ai_CalcMana_004bc423(void)

{
  int arg2;
  int status;
  uint u_temp;
  char *pcVar3;
  int local_18;
  int local_c;
  
  local_18 = 0;
  for (local_c = 0; local_c < 7; local_c = local_c + 1) {
    status = abs((&g_AiSelectedTargetCard)[local_c]);
    local_18 = local_18 + status;
  }
  if (local_18 == 0) {
    g_OverworldWorldState = 0;
  }
  else {
    local_18 = 0;
    g_OverworldWorldState = 0;
    u_temp = FUN_00474d4a();
    if (u_temp != 0xffffffff) {
      status = *(int *)(&DAT_006fecb8 + g_AiEvaluatedMoveCount * 8);
      arg2 = *(int *)(&DAT_006fecbc + g_AiEvaluatedMoveCount * 8);
      u_temp = u_temp >> 0x10 & 0xff;
      if (u_temp == 0x71) {
        strcpy(&g_OverworldWorldState,s_CASTING__0052d698);
        Ai_Subsystem_004b90de(status,arg2);
      }
      if (u_temp == 0x72) {
        strcpy(&g_OverworldWorldState,s_ACTIVATING__0052d6a4);
        Ai_Subsystem_004b90de(status,arg2);
      }
      if (u_temp == 0x7e) {
        strcpy(&g_OverworldWorldState,s_PROCESSING__0052d6b4);
        Ai_Subsystem_004b90de(status,arg2);
      }
    }
    strcat(&g_OverworldWorldState,s___tap_0052d6c4);
    for (local_c = 6; -1 < local_c; local_c = local_c + -1) {
      if ((&g_AiSelectedTargetCard)[local_c] != 0) {
        if (local_18 != 0) {
          strcat(&g_OverworldWorldState,s_and_0052d6cc);
        }
        if ((&g_AiSelectedTargetCard)[local_c] == -1) {
          strcat(&g_OverworldWorldState,s_X__now_0052d6d4);
          pcVar3 = _itoa(g_TurnCounter,&DAT_00556c40,10);
          strcat(&g_OverworldWorldState,pcVar3);
          if (g_OverworldPlayerCoordY != -1) {
            strcat(&g_OverworldWorldState,s___max_0052d6dc);
            pcVar3 = _itoa(g_OverworldPlayerCoordY,&DAT_00556c40,10);
            strcat(&g_OverworldWorldState,pcVar3);
          }
          strcat(&g_OverworldWorldState,&DAT_0052d6e4);
        }
        else {
          pcVar3 = _itoa((&g_AiSelectedTargetCard)[local_c],&DAT_00556c40,10);
          strcat(&g_OverworldWorldState,pcVar3);
        }
        strcat(&g_OverworldWorldState,&DAT_0052d6e8);
        pcVar3 = (char *)Mem_AllocOrFree_00473d7e(local_c);
        strcat(&g_OverworldWorldState,pcVar3);
        local_18 = local_18 + 1;
      }
    }
    strcat(&g_OverworldWorldState,s_mana__0052d6ec);
  }
  return 0;
}

/*
 * Ai_Subsystem_004bc72e
 * Purpose: Tactical AI engine subsystem routine (004bc72e).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004bc72e
 * Entry Point: 004bc72e
 * Size: 2311 bytes
 */

int Ai_Subsystem_004bc72e(int arg1, int arg2, int arg3, int arg4, int arg5)

{
  bool is_valid;
  bool is_match;
  int temp_idx;
  int card_idx;
  byte local_28;
  byte local_20;
  int local_18;
  int local_14;
  int local_c;
  
  is_valid = false;
  for (local_14 = 0; local_14 < 7; local_14 = local_14 + 1) {
    if ((&g_AiSelectedTargetCard)[local_14] == -1) {
      is_valid = true;
    }
  }
  temp_idx = Ai_Subsystem_004bbf8e(0x6b2d40,g_TurnCounter,g_OverworldPlayerCoordY);
  if (temp_idx == 0) {
    for (local_c = 0; local_c < (int)(&g_PlayerActiveCardCount)[arg1]; local_c = local_c + 1) {
      temp_idx = Ai_Subsystem_004bd035(arg1,local_c,(byte)arg4);
      if (temp_idx != 0) {
        temp_idx = Magic_TriggerCardEvent(arg1,local_c,0x73,1 - arg1,0xffffffff);
        if (temp_idx != 0) {
          is_match = false;
          for (local_14 = 0; local_14 < 7; local_14 = local_14 + 1) {
            if (((&g_AiSelectedTargetCard)[local_14] < 1) ||
               ((1 << ((byte)local_14 & 0x1f) &
                (int)(char)(&g_CardSlot_CountersBonus)[arg1 * 0x5b20 + local_c * 0x120]) == 0)) {
              if ((((&g_AiSelectedTargetCard)[local_14] == -1) &&
                  ((g_TurnCounter < g_OverworldPlayerCoordY && (g_OverworldPlayerCoordY != -1)))) &&
                 ((1 << ((byte)local_14 & 0x1f) &
                  (int)(char)(&g_CardSlot_CountersBonus)[arg1 * 0x5b20 + local_c * 0x120]) != 0)) {
                is_match = true;
              }
            }
            else {
              is_match = true;
            }
          }
          if ((arg5 != 0) && (!is_match)) {
            local_18 = 0;
            while ((local_18 < 10 && (*(int *)(&g_AiTempTargetBuffer + local_18 * 4 + arg1 * 0x2c) != -1)))
            {
              local_20 = (byte)*(int16_t *)(&g_AiTempTargetBuffer + local_18 * 4 + arg1 * 0x2c);
              if (((&g_AiSelectedTargetCard)[*(uint *)(&g_AiTempTargetBuffer + local_18 * 4 + arg1 * 0x2c) >> 0x10] <
                   1) || ((1 << (local_20 & 0x1f) &
                          (int)(char)(&g_CardSlot_CountersBonus)[arg1 * 0x5b20 + local_c * 0x120]) == 0)) {
                if (((&g_AiSelectedTargetCard)[*(uint *)(&g_AiTempTargetBuffer + local_18 * 4 + arg1 * 0x2c) >> 0x10]
                     == -1) &&
                   (((g_TurnCounter < g_OverworldPlayerCoordY && (g_OverworldPlayerCoordY != -1)) &&
                    ((1 << (local_20 & 0x1f) &
                     (int)(char)(&g_CardSlot_CountersBonus)[arg1 * 0x5b20 + local_c * 0x120]) != 0)))) {
                  is_match = true;
                }
              }
              else {
                is_match = true;
              }
              local_18 = local_18 + 1;
            }
          }
          if (is_match) {
            temp_idx = Ai_Subsystem_004bd23f(arg1,local_c);
            if (temp_idx != 0) {
              temp_idx = FUN_0040d949(arg1,6,1);
              card_idx = FUN_0040d949(arg1,7,1);
              temp_idx = temp_idx - card_idx;
              Ai_Subsystem_004bb9f3(arg1,arg2,arg3,temp_idx);
              Ai_Subsystem_004bbb99(arg1,arg2,arg3,temp_idx,&g_TurnCounter,g_OverworldPlayerCoordY);
              Ai_Subsystem_004bbd93(arg1,arg2,arg3,temp_idx,&g_TurnCounter,g_OverworldPlayerCoordY);
            }
          }
        }
      }
    }
  }
  temp_idx = Ai_Subsystem_004bbf8e(0x6b2d40,g_TurnCounter,g_OverworldPlayerCoordY);
  if ((temp_idx == 0) && ((g_AiSelectedTargetCard != 0 || (g_AiSelectedTargetPlayer != 0)))) {
    for (local_c = 0; local_c < (int)(&g_PlayerActiveCardCount)[arg1]; local_c = local_c + 1) {
      temp_idx = Ai_Subsystem_004bd035(arg1,local_c,(byte)arg4);
      if (temp_idx != 0) {
        temp_idx = Magic_TriggerCardEvent(arg1,local_c,0x73,1 - arg1,0xffffffff);
        if (temp_idx != 0) {
          is_match = false;
          if (g_AiSelectedTargetCard < 1) {
            if (((g_AiSelectedTargetCard == -1) && (g_TurnCounter < g_OverworldPlayerCoordY)) &&
               (g_OverworldPlayerCoordY != -1)) {
              is_match = true;
            }
            else if (g_AiSelectedTargetPlayer < 1) {
              if (((g_AiSelectedTargetPlayer == -1) && (g_TurnCounter < g_OverworldPlayerCoordY)) &&
                 (g_OverworldPlayerCoordY != -1)) {
                is_match = true;
              }
            }
            else {
              is_match = true;
            }
          }
          else {
            is_match = true;
          }
          if (((&g_CardSlot_CountersBonus)[arg1 * 0x5b20 + local_c * 0x120] == '@') && (g_AiSelectedTargetPlayer == 0)) {
            is_match = false;
          }
          if (is_match) {
            temp_idx = Ai_Subsystem_004bd23f(arg1,local_c);
            if (temp_idx != 0) {
              temp_idx = FUN_0040d949(arg1,6,1);
              card_idx = FUN_0040d949(arg1,7,1);
              temp_idx = temp_idx - card_idx;
              Ai_Subsystem_004bb9f3(arg1,arg2,arg3,temp_idx);
              Ai_Subsystem_004bbb99(arg1,arg2,arg3,temp_idx,&g_TurnCounter,g_OverworldPlayerCoordY);
              Ai_Subsystem_004bbd93(arg1,arg2,arg3,temp_idx,&g_TurnCounter,g_OverworldPlayerCoordY);
            }
          }
        }
      }
    }
  }
  temp_idx = Ai_Subsystem_004bbf8e(0x6b2d40,g_TurnCounter,g_OverworldPlayerCoordY);
  if (((temp_idx == 0) && (is_valid)) && (g_OverworldPlayerCoordY == -1)) {
    for (local_c = 0; local_c < (int)(&g_PlayerActiveCardCount)[arg1]; local_c = local_c + 1) {
      temp_idx = Ai_Subsystem_004bd035(arg1,local_c,(byte)arg4);
      if (temp_idx != 0) {
        temp_idx = Magic_TriggerCardEvent(arg1,local_c,0x73,1 - arg1,0xffffffff);
        if (temp_idx != 0) {
          is_valid = false;
          for (local_14 = 1; local_14 < 7; local_14 = local_14 + 1) {
            if (((g_OverworldPlayerCoordY == -1) && ((&g_AiSelectedTargetCard)[local_14] == -1)) &&
               ((1 << ((byte)local_14 & 0x1f) &
                (int)(char)(&g_CardSlot_CountersBonus)[arg1 * 0x5b20 + local_c * 0x120]) != 0)) {
              is_valid = true;
            }
            else if ((g_OverworldPlayerCoordY == -1) && (g_AiSelectedTargetCard == -1)) {
              is_valid = true;
            }
            else if ((g_OverworldPlayerCoordY == -1) && (g_AiSelectedTargetPlayer == -1)) {
              is_valid = true;
            }
          }
          if (((&g_CardSlot_CountersBonus)[arg1 * 0x5b20 + local_c * 0x120] == '@') && (g_AiSelectedTargetPlayer != -1)) {
            is_valid = false;
          }
          if ((arg5 != 0) && (!is_valid)) {
            local_18 = 0;
            while ((local_18 < 10 && (*(int *)(&g_AiTempTargetBuffer + local_18 * 4 + arg1 * 0x2c) != -1)))
            {
              if (((g_OverworldPlayerCoordY == -1) &&
                  ((&g_AiSelectedTargetCard)[*(uint *)(&g_AiTempTargetBuffer + local_18 * 4 + arg1 * 0x2c) >> 0x10]
                   == -1)) &&
                 (local_28 = (byte)*(int16_t *)(&g_AiTempTargetBuffer + local_18 * 4 + arg1 * 0x2c),
                 (1 << (local_28 & 0x1f) &
                 (int)(char)(&g_CardSlot_CountersBonus)[arg1 * 0x5b20 + local_c * 0x120]) != 0)) {
                is_valid = true;
              }
              local_18 = local_18 + 1;
            }
          }
          if (is_valid) {
            temp_idx = Ai_Subsystem_004bd23f(arg1,local_c);
            if (temp_idx != 0) {
              temp_idx = FUN_0040d949(arg1,6,1);
              card_idx = FUN_0040d949(arg1,7,1);
              temp_idx = temp_idx - card_idx;
              Ai_Subsystem_004bb9f3(arg1,arg2,arg3,temp_idx);
              Ai_Subsystem_004bbb99(arg1,arg2,arg3,temp_idx,&g_TurnCounter,g_OverworldPlayerCoordY);
              Ai_Subsystem_004bbd93(arg1,arg2,arg3,temp_idx,&g_TurnCounter,g_OverworldPlayerCoordY);
            }
          }
        }
      }
    }
  }
  Ai_EvalAbility_Regeneration();
  return 1;
}

/*
 * Ai_Subsystem_004bd035
 * Purpose: Tactical AI engine subsystem routine (004bd035).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004bd035
 * Entry Point: 004bd035
 * Size: 522 bytes
 */

int Ai_Subsystem_004bd035(int arg1, int arg2, byte arg3)

{
  int status;
  int local_c;
  
  status = *(int *)(&g_CardSlot_CardId + arg1 * 0x5b20 + arg2 * 0x120);
  local_c = 1;
  if (((((&g_CardSlot_Flags)[arg1 * 0x5b20 + arg2 * 0x120] & 2) == 0) ||
      (((&DAT_0051aed1)[status * 0x34] & 0x10) == 0)) || (((&DAT_0051aed2)[status * 0x34] & 1) != 0))
  {
    local_c = 0;
  }
  else {
    if (((arg3 & 1) != 0) &&
       (((status < 5 || (*(int *)(&g_MasterCardTypeTable + status * 0x34) == 0x366)) ||
        ((&g_CardSlot_CountersBonus)[arg1 * 0x5b20 + arg2 * 0x120] == '@')))) {
      local_c = 0;
    }
    if ((((arg3 & 2) != 0) && (((&g_MasterCardColorTable)[status * 0x34] & 1) != 0)) &&
       ((4 < status &&
        ((*(int *)(&g_MasterCardTypeTable + status * 0x34) != 0x366 &&
         ((&g_CardSlot_CountersBonus)[arg1 * 0x5b20 + arg2 * 0x120] != '@')))))) {
      local_c = 0;
    }
    if (((arg3 & 4) != 0) && (((&DAT_006a5f3e)[arg1 * 0x5b20 + arg2 * 0x120] & 4) != 0)) {
      local_c = 0;
    }
    if (((arg3 & 8) != 0) && (((&g_MasterCardColorTable)[status * 0x34] & 0x40) != 0)) {
      local_c = 0;
    }
    if (((arg3 & 0x10) != 0) && (((&g_MasterCardColorTable)[status * 0x34] & 2) != 0)) {
      local_c = 0;
    }
  }
  return local_c;
}

/*
 * Ai_Subsystem_004bd23f
 * Purpose: Tactical AI engine subsystem routine (004bd23f).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004bd23f
 * Entry Point: 004bd23f
 * Size: 426 bytes
 */

int Ai_Subsystem_004bd23f(int arg1, int arg2)

{
  uint u_res;
  int local_8;
  
  if ((((&g_CardSlot_Flags)[arg1 * 0x5b20 + arg2 * 0x120] & 0x10) == 0) &&
     ((((&DAT_006a5f3e)[arg1 * 0x5b20 + arg2 * 0x120] & 3) == 0 ||
      (((&g_MasterCardColorTable)
        [*(int *)(&g_CardSlot_CardId + arg1 * 0x5b20 + arg2 * 0x120) * 0x34] & 2) == 0)))) {
    Magic_CombatPhase(arg1,arg2,0x72,arg1,0);
    g_AiManaPoolReserve = 1;
    DAT_006ff2d4 = 0xffffffff;
    u_res = *(uint *)(&g_CardSlot_Flags + arg1 * 0x5b20 + arg2 * 0x120);
    Magic_TriggerCardEvent(arg1,arg2,0x6d,1 - arg1,0xffffffff);
    g_AiManaPoolReserve = 0;
    if (g_ActivePlayer == 1) {
      g_ActivePlayer = 0;
      Magic_DiscardToHandSize();
      local_8 = 0;
    }
    else {
      if (((u_res & 0x10) == 0) && (((&g_CardSlot_Flags)[arg1 * 0x5b20 + arg2 * 0x120] & 0x10) != 0)
         ) {
        FUN_00473e69(arg1,arg2,0x81);
      }
      if (g_IsAiThinking != 1) {
        Magic_UpkeepPhase(0x12);
      }
      Magic_EndTurnPhase();
      local_8 = 1;
    }
  }
  else {
    local_8 = 0;
  }
  return local_8;
}

/*
 * Ai_Subsystem_004bd3e9
 * Purpose: Tactical AI engine subsystem routine (004bd3e9).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004bd3e9
 * Entry Point: 004bd3e9
 * Size: 112 bytes
 */

void Ai_Subsystem_004bd3e9(int arg1, int arg2, int arg3, int * arg4, int arg5, int arg6, int arg7, int arg8, int * arg9)

{
  int *p_ires;
  
  FUN_0040d8b7(arg6,arg7,arg3);
  if (*(int *)(arg1 + arg2 * 4) == -1) {
    *arg4 = *arg4 + arg3;
  }
  else {
    p_ires = (int *)(arg1 + arg2 * 4);
    *p_ires = *p_ires - arg3;
  }
  p_ires = (int *)(arg_8 + arg7 * 4);
  *p_ires = *p_ires + arg3;
  Ai_Subsystem_004bd563(arg7,arg3);
  *arg_9 = *arg_9 + arg3;
  return;
}

/*
 * Ai_Subsystem_004bd459
 * Purpose: Tactical AI engine subsystem routine (004bd459).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004bd459
 * Entry Point: 004bd459
 * Size: 151 bytes
 */

int Ai_Subsystem_004bd459(int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7)

{
  int status;
  int local_8;
  
  if (arg5 == 0) {
    local_8 = 1;
  }
  else if (*(int *)(arg1 + arg2 * 4) == -1) {
    if (arg6 == -1) {
      local_8 = *(int *)(arg3 + arg4 * 4);
    }
    else {
      local_8 = *(int *)(arg3 + arg4 * 4);
      if (arg6 - arg7 <= local_8) {
        local_8 = arg6 - arg7;
      }
    }
  }
  else {
    local_8 = *(int *)(arg3 + arg4 * 4);
    status = *(int *)(arg1 + arg2 * 4);
    if (status <= local_8) {
      local_8 = status;
    }
  }
  return local_8;
}

/*
 * Ai_Subsystem_004bd4f0
 * Purpose: Tactical AI engine subsystem routine (004bd4f0).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004bd4f0
 * Entry Point: 004bd4f0
 * Size: 110 bytes
 */

int Ai_Subsystem_004bd4f0(void)

{
  int u_res;
  int local_8;
  
  if (g_AiHeuristicWeight_LifeAdvantage < 10) {
    for (local_8 = 0; local_8 < 7; local_8 = local_8 + 1) {
      *(int *)(&g_AiHeuristicWeight_Protection + local_8 * 4 + g_AiHeuristicWeight_LifeAdvantage * 0x1c) = 0;
    }
    g_AiHeuristicWeight_LifeAdvantage = g_AiHeuristicWeight_LifeAdvantage + 1;
    u_res = 1;
  }
  else {
    u_res = 0;
  }
  return u_res;
}

/*
 * Ai_Subsystem_004bd563
 * Purpose: Tactical AI engine subsystem routine (004bd563).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004bd563
 * Entry Point: 004bd563
 * Size: 71 bytes
 */

bool Ai_Subsystem_004bd563(int arg1, int arg2)

{
  int status;
  
  status = g_AiHeuristicWeight_LifeAdvantage;
  if (0 < g_AiHeuristicWeight_LifeAdvantage) {
    *(int *)(&g_AiHeuristicWeight_Protection + (g_AiHeuristicWeight_LifeAdvantage + -1) * 0x1c + arg1 * 4) =
         *(int *)(&g_AiHeuristicWeight_Protection + (g_AiHeuristicWeight_LifeAdvantage + -1) * 0x1c + arg1 * 4) + arg2;
  }
  return 0 < status;
}

/*
 * Ai_Util_CheckTimer
 * Purpose: Check if tactical AI decision time limit expired.
 * Procedure:
 * 1. Return true if evaluation time exceeds threshold.
 */
/*
 * Decompiled function: Ai_Util_CheckTimer
 * Entry Point: 004bd5af
 * Size: 47 bytes
 */

bool Ai_Util_CheckTimer(void)

{
  int status;
  
  status = g_AiHeuristicWeight_LifeAdvantage;
  if (0 < g_AiHeuristicWeight_LifeAdvantage) {
    g_AiHeuristicWeight_LifeAdvantage = g_AiHeuristicWeight_LifeAdvantage + -1;
  }
  return 0 < status;
}

/*
 * Ai_Subsystem_004bd5e3
 * Purpose: Tactical AI engine subsystem routine (004bd5e3).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004bd5e3
 * Entry Point: 004bd5e3
 * Size: 154 bytes
 */

int Ai_Subsystem_004bd5e3(int arg1)

{
  int u_res;
  int local_8;
  
  if (g_AiHeuristicWeight_LifeAdvantage < 1) {
    u_res = 0;
  }
  else {
    for (local_8 = 0; local_8 < 7; local_8 = local_8 + 1) {
      *(int *)(&g_AiLookaheadDepth + local_8 * 4 + arg1 * 0x20) =
           *(int *)(&g_AiLookaheadDepth + local_8 * 4 + arg1 * 0x20) +
           *(int *)(&g_AiHeuristicWeight_Protection + (g_AiHeuristicWeight_LifeAdvantage + -1) * 0x1c + local_8 * 4);
      *(int *)(&DAT_0063eeac + arg1 * 0x20) =
           *(int *)(&DAT_0063eeac + arg1 * 0x20) +
           *(int *)(&g_AiHeuristicWeight_Protection + (g_AiHeuristicWeight_LifeAdvantage + -1) * 0x1c + local_8 * 4);
    }
    u_res = 1;
  }
  return u_res;
}

/*
 * Ai_Subsystem_004bd682
 * Purpose: Tactical AI engine subsystem routine (004bd682).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004bd682
 * Entry Point: 004bd682
 * Size: 114 bytes
 */

int Ai_Subsystem_004bd682(int arg1)

{
  int u_res;
  int local_8;
  
  if (g_AiHeuristicWeight_LifeAdvantage < 1) {
    u_res = 0;
  }
  else {
    for (local_8 = 0; local_8 < 7; local_8 = local_8 + 1) {
      *(int *)(&g_AiHeuristicWeight_Protection + (g_AiHeuristicWeight_LifeAdvantage + -1) * 0x1c + local_8 * 4) =
           *(int *)(&g_AiHeuristicWeight_Protection + (g_AiHeuristicWeight_LifeAdvantage + -1) * 0x1c + local_8 * 4) -
           *(int *)(arg1 + local_8 * 4);
    }
    u_res = 1;
  }
  return u_res;
}

/*
 * Ai_Subsystem_004bd6f9
 * Purpose: Tactical AI engine subsystem routine (004bd6f9).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004bd6f9
 * Entry Point: 004bd6f9
 * Size: 2684 bytes
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int Ai_Subsystem_004bd6f9(int arg1, uint arg2, int arg3)

{
  int status;
  uint u_temp;
  char *output_str;
  int local_34;
  uint local_30;
  int local_24;
  uint local_20;
  int local_10;
  byte local_8;
  
  g_AiCombatDamageAssigned = arg2;
LAB_004bd70a:
  while( true ) {
    if (0 < *(int *)(&g_AiLookaheadDepth + arg2 * 4 + arg1 * 0x20)) {
      FUN_0040d8b7(arg1,arg2,1);
      g_AiCombatDamageAssigned = 0xffffffff;
      return 1;
    }
    local_24 = 0;
    while ((local_24 < 10 && (*(int *)(&g_AiTempTargetBuffer + local_24 * 4 + arg1 * 0x2c) != -1))) {
      if ((0 < *(int *)(&g_AiLookaheadDepth +
                       (uint)*(ushort *)(&g_AiTempTargetBuffer + local_24 * 4 + arg1 * 0x2c) * 4 +
                       arg1 * 0x20)) &&
         (*(uint *)(&g_AiTempTargetBuffer + local_24 * 4 + arg1 * 0x2c) >> 0x10 == arg2)) {
        FUN_0040d8b7(arg1,(uint)*(ushort *)(&g_AiTempTargetBuffer + local_24 * 4 + arg1 * 0x2c),1);
        g_AiCombatDamageAssigned = 0xffffffff;
        return 1;
      }
      local_24 = local_24 + 1;
    }
    if (arg2 == 6) {
      for (local_20 = 0; (int)local_20 < 7; local_20 = local_20 + 1) {
        if (*(int *)(&g_AiLookaheadDepth + local_20 * 4 + arg1 * 0x20) != 0) {
          FUN_0040d8b7(arg1,local_10,1);
          g_AiCombatDamageAssigned = 0xffffffff;
          return 1;
        }
      }
    }
    if (arg2 == 0) {
      for (local_20 = 0; (int)local_20 < 7; local_20 = local_20 + 1) {
        if ((local_20 != 6) && (*(int *)(&g_AiLookaheadDepth + local_20 * 4 + arg1 * 0x20) != 0)) {
          FUN_0040d8b7(arg1,local_10,1);
          g_AiCombatDamageAssigned = 0xffffffff;
          return 1;
        }
      }
    }
    if ((((g_CurrentTurnPhase == arg1) && (g_IsAiThinking != 1)) && (g_AiTemporaryCardState == 0)) &&
       (g_AiTurnDecisionFlag == 0)) break;
    if (arg2 == 0) {
      local_10 = -1;
      for (local_20 = 1; (int)local_20 < 7; local_20 = local_20 + 1) {
        status = FUN_0040d949(arg1,local_20,1);
        if (status != 0) {
          status = FUN_0040d949(arg1,local_20,1);
          status = (status << 5) / (*(int *)(&DAT_006ff690 + local_20 * 4 + arg1 * 0x20) * 2 + 1);
          if (local_10 < status) {
            arg2 = local_20;
            g_AiCombatDamageAssigned = local_20;
            local_10 = status;
          }
        }
      }
    }
    local_30 = 0;
    local_24 = 0;
    while ((local_24 < 10 && (*(int *)(&g_AiTempTargetBuffer + local_24 * 4 + arg1 * 0x2c) != -1))) {
      if (*(uint *)(&g_AiTempTargetBuffer + local_24 * 4 + arg1 * 0x2c) >> 0x10 == arg2) {
        local_8 = (byte)*(int16_t *)(&g_AiTempTargetBuffer + local_24 * 4 + arg1 * 0x2c);
        local_30 = local_30 | 1 << (local_8 & 0x1f);
      }
      local_24 = local_24 + 1;
    }
    local_20 = 0;
    while( true ) {
      if ((int)(&g_PlayerActiveCardCount)[arg1] <= (int)local_20) {
        g_AiCombatDamageAssigned = 0xffffffff;
        return 0;
      }
      if (((((((&g_CardSlot_Flags)[arg1 * 0x5b20 + local_20 * 0x120] & 2) != 0) &&
            (((&g_CardSlot_Flags)[arg1 * 0x5b20 + local_20 * 0x120] & 0x10) == 0)) &&
           (status = *(int *)(&g_CardSlot_CardId + arg1 * 0x5b20 + local_20 * 0x120), status != -1))
          && ((((&g_MasterCardColorTable)[status * 0x34] & 1) != 0 &&
              (u_temp = (uint)(char)(&g_CardSlot_CountersBonus)[arg1 * 0x5b20 + local_20 * 0x120], u_temp != 0)))
          ) && ((((u_temp & 1 << ((byte)arg2 & 0x1f)) != 0 ||
                 (((u_temp & local_30) != 0 || (arg2 == 0)))) || (arg2 == 6)))) break;
      local_20 = local_20 + 1;
    }
    Magic_CombatPhase(arg1,local_20,0x72,arg1,0);
    g_AiManaPoolReserve = 1;
    DAT_006ff2d4 = 0xffffffff;
    u_temp = *(uint *)(&g_CardSlot_Flags + local_34 * 0x120 + arg1 * 0x5b20);
    _DAT_006b2d28 = status;
    Magic_TriggerCardEvent(arg1,local_20,0x6d,1 - arg1,0xffffffff);
    g_AiManaPoolReserve = 0;
    if (g_ActivePlayer == 1) {
      g_ActivePlayer = 0;
      Magic_DiscardToHandSize();
    }
    else {
      if (((u_temp & 0x10) == 0) &&
         (((&g_CardSlot_Flags)[local_34 * 0x120 + arg1 * 0x5b20] & 0x10) != 0)) {
        FUN_00473e69(arg1,local_20,0x81);
      }
      if (g_IsAiThinking != 1) {
        Magic_UpkeepPhase(0x12);
      }
      Magic_EndTurnPhase();
    }
    _DAT_006b2d28 = 0xffffffff;
  }
  do {
    switch(arg2) {
    case 0:
      strcpy(&g_OverworldWorldState,s_Tap_any_land__0052d74c);
      break;
    case 1:
      strcpy(&g_OverworldWorldState,s_Tap_a_swamp__0052d6fc);
      break;
    case 2:
      strcpy(&g_OverworldWorldState,s_Tap_an_island__0052d70c);
      break;
    case 3:
      strcpy(&g_OverworldWorldState,s_Tap_a_forest__0052d71c);
      break;
    case 4:
      strcpy(&g_OverworldWorldState,s_Tap_a_mountain__0052d72c);
      break;
    case 5:
      strcpy(&g_OverworldWorldState,s_Tap_a_plains__0052d73c);
    }
    if (arg3 == 0) {
      strcat(&g_OverworldWorldState,s__or_none__X_is_0052d75c);
      output_str = _itoa(g_TurnCounter,&DAT_00556c40,10);
      strcat(&g_OverworldWorldState,output_str);
    }
    local_34 = Duel_LogActionStatusBanner(arg1,arg1,arg1,0,0,&g_OverworldWorldState,1);
    if (((local_34 != -1) && (((&g_CardSlot_Flags)[local_34 * 0x120 + arg1 * 0x5b20] & 2) != 0)) &&
       (((&g_CardSlot_Flags)[local_34 * 0x120 + arg1 * 0x5b20] & 0x14) == 0)) {
      if (((&g_MasterCardColorTable)
           [*(int *)(&g_CardSlot_CardId + local_34 * 0x120 + arg1 * 0x5b20) * 0x34] & 1) == 0) {
        if ((((&DAT_0051aed1)
              [*(int *)(&g_CardSlot_CardId + local_34 * 0x120 + arg1 * 0x5b20) * 0x34] & 0x10) != 0
            ) && (status = Magic_TriggerCardEvent(arg1,local_34,0x73,1 - arg1,0xffffffff),
                 status != 0)) break;
      }
      else if (((int)(char)(&g_CardSlot_CountersBonus)[local_34 * 0x120 + arg1 * 0x5b20] != 0) &&
              ((((int)(char)(&g_CardSlot_CountersBonus)[local_34 * 0x120 + arg1 * 0x5b20] &
                1 << ((byte)arg2 & 0x1f)) != 0 || (arg2 == 0)))) {
        Magic_CombatPhase(arg1,local_20,0x72,arg1,0);
        _DAT_006b2d28 = *(int *)(&g_CardSlot_CardId + local_34 * 0x120 + arg1 * 0x5b20);
        g_AiManaPoolReserve = 1;
        DAT_006ff2d4 = 0xffffffff;
        u_temp = *(uint *)(&g_CardSlot_Flags + local_34 * 0x120 + arg1 * 0x5b20);
        Magic_TriggerCardEvent(arg1,local_34,0x6d,1 - arg1,0xffffffff);
        g_AiManaPoolReserve = 0;
        if (g_ActivePlayer == 1) {
          g_ActivePlayer = 0;
          Magic_DiscardToHandSize();
        }
        else {
          if (((u_temp & 0x10) == 0) &&
             (((&g_CardSlot_Flags)[local_34 * 0x120 + arg1 * 0x5b20] & 0x10) != 0)) {
            FUN_00473e69(arg1,local_34,0x81);
          }
          if (g_IsAiThinking != 1) {
            Magic_UpkeepPhase(0x12);
          }
          Magic_EndTurnPhase();
          Ai_Turn_ExecuteMainPhase(0,0xff);
        }
        _DAT_006b2d28 = 0xffffffff;
        goto LAB_004bd70a;
      }
    }
    FUN_0040a3e1();
    if (arg3 == 0) {
      Ai_Turn_ExecuteMainPhase(0,0xff);
      g_AiCombatDamageAssigned = 0xffffffff;
      return 0;
    }
  } while( true );
  Magic_CombatPhase(arg1,local_20,0x72,arg1,0);
  _DAT_006b2d28 = *(int *)(&g_CardSlot_CardId + local_34 * 0x120 + arg1 * 0x5b20);
  g_AiManaPoolReserve = 1;
  DAT_006ff2d4 = 0xffffffff;
  u_temp = *(uint *)(&g_CardSlot_Flags + local_34 * 0x120 + arg1 * 0x5b20);
  Magic_TriggerCardEvent(arg1,local_34,0x6d,1 - arg1,0xffffffff);
  g_AiManaPoolReserve = 0;
  if (g_ActivePlayer == 1) {
    g_ActivePlayer = 0;
    Magic_DiscardToHandSize();
  }
  else {
    if (((u_temp & 0x10) == 0) &&
       (((&g_CardSlot_Flags)[local_34 * 0x120 + arg1 * 0x5b20] & 0x10) != 0)) {
      FUN_00473e69(arg1,local_34,0x81);
    }
    if (g_IsAiThinking != 1) {
      Magic_UpkeepPhase(0x12);
    }
    Magic_EndTurnPhase();
    Ai_Turn_ExecuteMainPhase(0,0xff);
  }
  _DAT_006b2d28 = 0xffffffff;
  goto LAB_004bd70a;
}

/*
 * Ai_Subsystem_004be192
 * Purpose: Tactical AI engine subsystem routine (004be192).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004be192
 * Entry Point: 004be192
 * Size: 169 bytes
 */

int Ai_Subsystem_004be192(int x, int y, int width, int height)

{
  int status;
  int val_result;
  
  status = FUN_00473cc5((&DAT_006a5f4d)[y * 0x120 + x * 0x5b20]);
  g_AiSelectedTargetCard = g_AiSelectedTargetCard + *(int *)(&DAT_006330d0 + status * 4);
  val_result = Ai_CalcManaRequirement_PayCost(x,width,height);
  status = FUN_00473cc5((&DAT_006a5f4d)[y * 0x120 + x * 0x5b20]);
  val_result = val_result - *(int *)(&DAT_006330d0 + status * 4);
  if (g_ActivePlayer == 1) {
    val_result = 0;
  }
  return val_result;
}

/*
 * Ai_Util_004be240
 * Purpose: Tactical AI utility helper function (004be240).
 * Procedure:
 * 1. Execute internal state operation.
 */
/*
 * Decompiled function: Ai_Util_004be240
 * Entry Point: 004be240
 * Size: 31 bytes
 */

void Ai_Util_004be240(void)

{
  g_AiHeuristicWeight_Regeneration = 0;
  DAT_00556c64 = 0;
  return;
}

/*
 * Ai_Subsystem_004be25f
 * Purpose: Tactical AI engine subsystem routine (004be25f).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004be25f
 * Entry Point: 004be25f
 * Size: 248 bytes
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Ai_Subsystem_004be25f(int arg1, int arg2, int arg3, int arg4, int arg5)

{
  int local_c;
  int local_8;
  
  *(int *)(&DAT_00557cc0 + g_AiHeuristicWeight_Regeneration * 4) = arg2;
  *(int *)(&DAT_005584c0 + g_AiHeuristicWeight_Regeneration * 4) = arg3;
  *(int *)(&DAT_00556c70 + g_AiHeuristicWeight_Regeneration * 4) = arg4;
  *(int *)(&DAT_005574c0 + g_AiHeuristicWeight_Regeneration * 4) = arg5;
  if (g_AiHeuristicWeight_Regeneration == 0) {
    _DAT_00558dd8 = 0xffffffff;
  }
  else {
    local_8 = -1;
    for (local_c = DAT_00556c64; (*(int *)(&DAT_00556c70 + local_c * 4) < arg4 && (local_c != -1));
        local_c = *(int *)(&DAT_00558dd8 + local_c * 4)) {
      local_8 = local_c;
    }
    *(int *)(&DAT_00558dd8 + g_AiHeuristicWeight_Regeneration * 4) = local_c;
    if (local_8 == -1) {
      DAT_00556c64 = g_AiHeuristicWeight_Regeneration;
    }
    else {
      *(int *)(&DAT_00558dd8 + local_8 * 4) = g_AiHeuristicWeight_Regeneration;
    }
  }
  g_AiHeuristicWeight_Regeneration = g_AiHeuristicWeight_Regeneration + 1;
  return;
}

/*
 * Ai_Subsystem_004be357
 * Purpose: Tactical AI engine subsystem routine (004be357).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004be357
 * Entry Point: 004be357
 * Size: 109 bytes
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Ai_Subsystem_004be357(void)

{
  int local_8;
  
  for (local_8 = DAT_00556c64; local_8 != -1; local_8 = *(int *)(&DAT_00558dd8 + local_8 * 4)) {
    Sprite_DrawClipped((int *)g_DisplaySurfaceScreen,
                       *(int *)(&DAT_00557cc0 + local_8 * 4) - g_AiLookaheadScore_Player0,
                       *(int *)(&DAT_005584c0 + local_8 * 4) - g_AiLookaheadScore_Player1,
                       *(int *)(&DAT_005574c0 + local_8 * 4));
  }
  return;
}

/*
 * Ai_Subsystem_004be3c4
 * Purpose: Tactical AI engine subsystem routine (004be3c4).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004be3c4
 * Entry Point: 004be3c4
 * Size: 123 bytes
 */

void Ai_Subsystem_004be3c4(int * arg1, int arg2, int arg3, int arg4, int arg5, int arg6)

{
  Sprite_DrawScaled(arg1,(g_AiManaColorCost_Red * arg2) / 0x280,(g_AiManaColorCost_Green * arg3) / 0x1e0,
                    (g_AiManaColorCost_Red * arg5) / 0x280,(g_AiManaColorCost_Green * arg6) / 0x1e0,arg4);
  return;
}

/*
 * Ai_Subsystem_004be43f
 * Purpose: Tactical AI engine subsystem routine (004be43f).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004be43f
 * Entry Point: 004be43f
 * Size: 92 bytes
 */

void Ai_Subsystem_004be43f(int x, int y, int * width, int * height)

{
  int status;
  
  status = (y - x) * g_AiManaColorCost_Green;
  *width = ((y + x) * g_AiManaColorCost_Red * 2) / 0x280;
  *height = status / 0x1e0;
  return;
}

/*
 * Ai_Subsystem_004be49b
 * Purpose: Tactical AI engine subsystem routine (004be49b).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004be49b
 * Entry Point: 004be49b
 * Size: 138 bytes
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Ai_Subsystem_004be49b(int x, int y, int * width, int * height)

{
  int status;
  int val_result;
  
  status = ((y - _DAT_00641880) - (x - _DAT_0064187c)) * g_AiManaColorCost_Green;
  val_result = DAT_005574ac / 2;
  *width = (((y - _DAT_00641880) + (x - _DAT_0064187c)) * g_AiManaColorCost_Red * 2) / 0x280 +
           DAT_00557478 / 2;
  *height = status / 0x1e0 + val_result + g_AiHeuristicWeight_CardAdvantage;
  return;
}

/*
 * Ai_Subsystem_004be525
 * Purpose: Tactical AI engine subsystem routine (004be525).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004be525
 * Entry Point: 004be525
 * Size: 137 bytes
 */

void Ai_Subsystem_004be525(int x, int y, int * width, int * height)

{
  int status;
  int val_result;
  
  status = ((y - g_AiLookaheadBestMove) - (x - g_AiLookaheadDelta)) * g_AiManaColorCost_Green;
  val_result = DAT_005574ac / 2;
  *width = (((y - g_AiLookaheadBestMove) + (x - g_AiLookaheadDelta)) * g_AiManaColorCost_Red * 2) / 0x280 + DAT_00557478 / 2
  ;
  *height = g_AiHeuristicWeight_CardAdvantage + status / 0x1e0 + val_result;
  return;
}

/*
 * Ai_Subsystem_004be5ae
 * Purpose: Tactical AI engine subsystem routine (004be5ae).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004be5ae
 * Entry Point: 004be5ae
 * Size: 149 bytes
 */

void Ai_Subsystem_004be5ae(int x, int y, int * width, int * height)

{
  int status;
  int val_result;
  
  status = (((y - g_AiHeuristicWeight_CardAdvantage) - DAT_005574ac / 2) * 0x1e0) / g_AiManaColorCost_Green;
  val_result = ((x - DAT_00557478 / 2) * 0x280) / g_AiManaColorCost_Red >> 1;
  *width = g_AiLookaheadDelta + (val_result - status) / 2;
  *height = g_AiLookaheadBestMove + (val_result + status) / 2;
  return;
}

/*
 * Ai_Subsystem_004be643
 * Purpose: Tactical AI engine subsystem routine (004be643).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004be643
 * Entry Point: 004be643
 * Size: 3048 bytes
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Ai_Subsystem_004be643(int arg1, int arg2, int arg3)

{
  int *p_ires;
  int val_result;
  int temp_idx;
  char *pcVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  DWORD DVar9;
  uint arg4;
  int iVar10;
  HDC pHVar11;
  int iVar12;
  int arg_9;
  int arg5;
  int local_fc [4];
  int local_ec [4];
  int local_dc [4];
  int local_cc [4];
  int local_bc [4];
  int local_ac;
  int local_a8;
  int local_a4 [17];
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50 [2];
  int local_48 [2];
  uint local_40;
  uint local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_28 = *(int *)g_DisplaySurfaceBackBuffer;
  Pic_Subsystem_0044b8da();
  if (g_AiManaColorCost_Red == 0x280) {
    DAT_00557478 = 0x280;
    DAT_005574ac = 0x1e0;
    g_AiHeuristicWeight_Tempo = 0x80;
    g_AiPlayerScoreTable = 0x20;
  }
  else if (g_AiManaColorCost_Red == 800) {
    DAT_00557478 = 800;
    DAT_005574ac = 600;
    g_AiHeuristicWeight_Tempo = 0xa0;
    g_AiPlayerScoreTable = 0x28;
  }
  else if (g_AiManaColorCost_Red == 0x400) {
    DAT_00557478 = 0x400;
    DAT_005574ac = 0x300;
    g_AiHeuristicWeight_Tempo = 0xcc;
    g_AiPlayerScoreTable = 0x33;
  }
  g_AiLookaheadDelta = arg1;
  g_AiLookaheadBestMove = arg2;
  _DAT_00557484 = (int)(arg1 + (arg1 >> 0x1f & 0x1fU)) >> 5;
  _DAT_00557488 = (int)(arg2 + (arg2 >> 0x1f & 0x1fU)) >> 5;
  *(int *)g_DisplaySurfaceScreen = *(int *)g_DisplaySurfaceBackBuffer;
  Ai_Util_004be240();
  g_AiHeuristicWeight_CardAdvantage = 0x50;
  p_ires = (int *)FUN_0050e6f0(local_bc,(int)g_DisplaySurfaceBackBuffer,0,0x80,
                               *(int *)(g_DisplaySurfaceScreen + 0xc),
                               *(int *)(g_DisplaySurfaceScreen + 0x10) + -0x80);
  local_24 = *p_ires;
  local_20 = p_ires[1];
  local_1c = p_ires[2];
  local_18 = p_ires[3];
  p_ires = (int *)FUN_0050e6f0(local_cc,(int)g_DisplaySurfaceScreen,0,0x80,
                               *(int *)(g_DisplaySurfaceScreen + 0xc),
                               *(int *)(g_DisplaySurfaceScreen + 0x10) + -0x80);
  local_14 = *p_ires;
  local_10 = p_ires[1];
  local_c = p_ires[2];
  local_8 = p_ires[3];
  Ai_Subsystem_004c06df(arg1,arg2);
  Ai_Subsystem_004be525(arg1,arg2,local_48,local_50);
  val_result = Ai_Util_004c3ba3(0x8c);
  temp_idx = Ai_Util_004c3ba3(0x100);
  FUN_0050e6f0(local_dc,(int)g_DisplaySurfaceScreen,0x40,g_AiPlayerScoreTable * 2 + g_AiHeuristicWeight_CardAdvantage + 0x10,
               temp_idx,val_result);
  Ai_Subsystem_004be25f
            (g_DisplaySurfaceScreen,(local_48[0] - DAT_00678430 / 2) + g_AiLookaheadScore_Player0,
             (local_50[0] - DAT_006779d0) + g_AiLookaheadScore_Player1,g_AiLookaheadScore_Player1 + local_50[0],
             (&DAT_00679370)[(DAT_006410d4 + 2U & 7) * 5 + DAT_006410dc]);
  Sprite_DrawClipped((int *)g_DisplaySurfaceScreen,local_48[0] - DAT_00678434 / 2,
                     local_50[0] - DAT_006779d4,
                     (&DAT_00679424)[(DAT_006410d4 + 2U & 7) * 5 + DAT_006410dc]);
  g_OverworldWorldState = 0;
  pcVar4 = _itoa(local_30,&DAT_00557498,10);
  strcat(&g_OverworldWorldState,pcVar4);
  strcat(&g_OverworldWorldState,&DAT_0052db48);
  pcVar4 = _itoa(local_38,&DAT_00557498,10);
  strcat(&g_OverworldWorldState,pcVar4);
  local_3c = 0;
  do {
    if (7 < (int)local_3c) {
      Ai_Subsystem_004be357();
      *(int *)g_DisplaySurfaceScreen = 0;
      local_a4[0x10] = DAT_00677e10;
      local_a4[6] = 0x40;
      local_a4[7] = 0x50;
      local_a4[8] = 0x66;
      local_a4[0xd] = 0x48;
      local_a4[0xe] = 0x5a;
      local_a4[0xf] = 0x72;
      local_a4[0] = 0xcb;
      local_a4[1] = 0xfd;
      local_a4[2] = 0x143;
      local_a4[3] = 0x1af;
      local_a4[4] = 0x21a;
      local_a4[5] = 0x2b0;
      local_a4[10] = 0x2f;
      local_a4[0xb] = 0x3c;
      local_a4[0xc] = 0x4d;
      val_result = DAT_00677e10;
      temp_idx = Ai_Util_004c3bc4((int)*(short *)(DAT_00677e10 + 6));
      iVar6 = Ai_Util_004c3bc4((int)*(short *)(local_a4[0x10] + 4));
      iVar5 = Ai_Util_004c3bc4(0x105);
      iVar5 = iVar5 + g_AiPlayerScoreTable * 2 + g_AiHeuristicWeight_CardAdvantage + 0x10;
      iVar7 = Ai_Util_004c3bc4(0x141);
      Sprite_DrawScaled((int *)g_DisplaySurfaceBackBuffer,iVar7 + 0x40,iVar5,iVar6,temp_idx,val_result);
      if (g_AiManaColorCost_Red == 0x280) {
        local_a4[9] = 0;
      }
      else if (g_AiManaColorCost_Red == 800) {
        local_a4[9] = 1;
      }
      else if (g_AiManaColorCost_Red == 0x400) {
        local_a4[9] = 2;
      }
      iVar6 = local_a4[local_a4[9] + 0xd] + g_AiPlayerScoreTable * 2 + g_AiHeuristicWeight_CardAdvantage;
      val_result = DAT_00677fb0;
      temp_idx = Ai_Util_004c3bc4(0x30);
      Sprite_DrawDirect((int *)g_DisplaySurfaceBackBuffer,0x40,(iVar6 + 0x10) - temp_idx,val_result);
      iVar6 = g_AiPlayerScoreTable * 2 + g_AiHeuristicWeight_CardAdvantage + 0x10;
      val_result = local_a4[local_a4[9]];
      temp_idx = DAT_00677fe4;
      iVar5 = Ai_Util_004c3bc4(0x40);
      Sprite_DrawDirect((int *)g_DisplaySurfaceBackBuffer,(val_result + 0x40) - iVar5,iVar6,temp_idx);
      iVar6 = g_AiPlayerScoreTable * 2 + g_AiHeuristicWeight_CardAdvantage + 0x10;
      val_result = local_a4[local_a4[9] + 3];
      temp_idx = DAT_00677fe4;
      iVar5 = Ai_Util_004c3bc4(0x40);
      Sprite_DrawDirect((int *)g_DisplaySurfaceBackBuffer,(val_result + 0x40) - iVar5,iVar6,temp_idx);
      if (DAT_0064101c == 0) {
        if (g_AiManaColorCost_Red == 0x400) {
          val_result = Ai_Util_004c3ba3(0x18);
          temp_idx = Ai_Util_004c3ba3(0x20);
          uVar8 = temp_idx + 4U & 0xfffffffc;
          p_ires = (int *)g_DisplaySurfaceScreen;
          DVar9 = Ai_Util_004c3ba3(0x8c);
          temp_idx = Ai_Util_004c3ba3(0x100);
          FUN_0050dce0((int *)g_DisplaySurfaceBackBuffer,0x40,g_AiPlayerScoreTable * 2 + g_AiHeuristicWeight_CardAdvantage + 0x10
                       ,temp_idx - 2,DVar9,p_ires,uVar8,val_result);
        }
        else {
          val_result = Ai_Util_004c3ba3(0x18);
          uVar8 = Ai_Util_004c3ba3(0x20);
          uVar8 = uVar8 & 0xfffffffc;
          p_ires = (int *)g_DisplaySurfaceScreen;
          DVar9 = Ai_Util_004c3ba3(0x8c);
          arg4 = Ai_Util_004c3ba3(0x100);
          FUN_0050dce0((int *)g_DisplaySurfaceBackBuffer,0x40,g_AiPlayerScoreTable * 2 + g_AiHeuristicWeight_CardAdvantage + 0x10
                       ,arg4,DVar9,p_ires,uVar8,val_result);
        }
      }
      else {
        local_a8 = (&DAT_0070a850)[*(int *)g_DisplaySurfaceBackBuffer];
        local_ac = (&DAT_0070a850)[*(int *)g_DisplaySurfaceScreen];
        if (g_AiManaColorCost_Red == 0x400) {
          val_result = g_AiPlayerScoreTable * 2 + g_AiHeuristicWeight_CardAdvantage + 0x10;
          arg_9 = 0x40;
          pHVar11 = *(HDC *)(local_a8 + 4);
          iVar12 = 8;
          iVar10 = 8;
          temp_idx = Ai_Util_004c3ba3(0x8c);
          iVar6 = Ai_Util_004c3ba3(0x100);
          iVar6 = iVar6 + -2;
          iVar5 = Ai_Util_004c3ba3(0x18);
          iVar7 = Ai_Util_004c3ba3(0x20);
          FUN_00511b90(*(HDC *)(local_ac + 4),iVar7 + 4U & 0xfffffffc,iVar5,iVar6,temp_idx,iVar10,
                       iVar12,pHVar11,arg_9,val_result);
          FUN_00501736(0x2d);
        }
        else {
          val_result = g_AiPlayerScoreTable * 2 + g_AiHeuristicWeight_CardAdvantage + 0x10;
          iVar12 = 0x40;
          pHVar11 = *(HDC *)(local_a8 + 4);
          iVar10 = 6;
          iVar7 = 6;
          temp_idx = Ai_Util_004c3ba3(0x8c);
          iVar6 = Ai_Util_004c3ba3(0x100);
          iVar5 = Ai_Util_004c3ba3(0x18);
          uVar8 = Ai_Util_004c3ba3(0x20);
          FUN_00511b90(*(HDC *)(local_ac + 4),uVar8 & 0xfffffffc,iVar5,iVar6,temp_idx,iVar7,iVar10,
                       pHVar11,iVar12,val_result);
          FUN_00501736(0x2d);
        }
        DAT_0064101c = 0;
      }
      FUN_0050e6f0(local_ec,(int)g_DisplaySurfaceBackBuffer,local_24,local_20,local_1c,local_18);
      FUN_0050e6f0(local_fc,(int)g_DisplaySurfaceScreen,local_14,local_10,local_c,local_8);
      *(int *)g_DisplaySurfaceBackBuffer = local_28;
      if ((arg3 == 0) && (DAT_0052d778 == 0)) {
        *(int *)(g_DisplaySurfaceScreen + 0x20) = 1;
        Pic_Subsystem_0044b8aa();
        Ai_CalcMana_004bf4b3(0);
        Ai_Subsystem_004bf23a();
      }
      else {
        Ai_Subsystem_004c3c5c(0);
        DAT_0052d778 = 0;
        Pic_Subsystem_0044b8aa();
      }
      return;
    }
    Ai_Subsystem_004be49b
              (*(uint *)(&g_AiCardEvaluationScore + local_3c * 0x14) & 0xffffffe0,
               *(uint *)(&g_AiCardSynergyScore + local_3c * 0x14) & 0xffffffe0,&local_60,&local_54);
    Ai_Subsystem_004be43f
              (*(uint *)(&g_AiCardEvaluationScore + local_3c * 0x14) & 0x1f,
               *(uint *)(&g_AiCardSynergyScore + local_3c * 0x14) & 0x1f,&local_58,&local_5c);
    local_48[0] = local_58 + local_60;
    local_50[0] = local_5c + local_54;
    local_60 = (int)(*(int *)(&g_AiCardEvaluationScore + local_3c * 0x14) +
                    (*(int *)(&g_AiCardEvaluationScore + local_3c * 0x14) >> 0x1f & 0x1fU)) >> 5;
    local_54 = (int)(*(int *)(&g_AiCardSynergyScore + local_3c * 0x14) +
                    (*(int *)(&g_AiCardSynergyScore + local_3c * 0x14) >> 0x1f & 0x1fU)) >> 5;
    if (((*(int *)(&DAT_0067f2d0 + local_3c * 0x14) != -1) &&
        (val_result = abs(local_60 - _DAT_00557484), val_result < 2)) &&
       (val_result = abs(local_54 - _DAT_00557488), val_result < 2)) {
      local_34 = *(int *)(&DAT_0067f2d0 + local_3c * 0x14);
      if (((&DAT_00522630)[local_34 * 0x44] & 2) != 0) {
        local_34 = local_34 - (DAT_0067f37c >> 5 & 3);
      }
      if (((&DAT_00522631)[local_34 * 0x44] & 1) != 0) {
        val_result = FUN_0040a36f(local_48[0] + -0x140,local_50[0] + -0xf0);
        temp_idx = Ai_Util_004c3ba3(0x80);
        if (temp_idx < val_result) goto LAB_004be98f;
      }
      val_result = local_50[0];
      if (*(int *)(&DAT_0067f2d0 + local_3c * 0x14) == 0) {
        arg5 = *(int *)
                 (&DAT_00677420 +
                 (char)(&DAT_0052d7a8)[*(int *)(&DAT_0067f2dc + local_3c * 0x14)] * 4);
        iVar6 = local_50[0];
        iVar5 = Ai_Util_004c3ba3(0x30);
        temp_idx = local_48[0];
        val_result = val_result - iVar5;
        iVar5 = Ai_Util_004c3ba3(0x20);
        Ai_Subsystem_004be25f(g_DisplaySurfaceScreen,temp_idx - iVar5,val_result,iVar6,arg5);
        temp_idx = local_50[0];
        val_result = *(int *)(&DAT_00677438 +
                        (char)(&DAT_0052d7a8)[*(int *)(&DAT_0067f2dc + local_3c * 0x14)] * 4);
        iVar5 = Ai_Util_004c3ba3(0x30);
        iVar6 = local_48[0];
        iVar5 = (temp_idx - iVar5) - g_AiLookaheadScore_Player1;
        temp_idx = Ai_Util_004c3ba3(0x20);
        Sprite_DrawClipped((int *)g_DisplaySurfaceScreen,(iVar6 - temp_idx) - g_AiLookaheadScore_Player0,iVar5,val_result
                          );
      }
      else {
        local_40 = local_3c;
        Ai_Subsystem_004be25f
                  (g_DisplaySurfaceScreen,local_48[0] - *(int *)(&DAT_006783f0 + local_3c * 4) / 2,
                   local_50[0] - *(int *)(&DAT_00677990 + local_3c * 4),local_50[0],
                   *(int *)
                    (&g_OverworldFoodAmount +
                    local_3c * 0xb4 +
                    ((int)(char)(&DAT_0067f2e0)[local_3c * 0x14] + 2U & 7) * 0x14 +
                    (char)(&DAT_0067f2e1)[local_3c * 0x14] * 4));
        local_40 = local_3c + 8;
        Sprite_DrawClipped((int *)g_DisplaySurfaceScreen,
                           (local_48[0] - *(int *)(&DAT_006783f0 + local_40 * 4) / 2) -
                           g_AiLookaheadScore_Player0,
                           (local_50[0] - *(int *)(&DAT_00677990 + local_40 * 4)) - g_AiLookaheadScore_Player1,
                           *(int *)(&g_OverworldFoodAmount +
                                   local_40 * 0xb4 +
                                   ((int)(char)(&DAT_0067f2e0)[local_3c * 0x14] + 2U & 7) * 0x14 +
                                   (char)(&DAT_0067f2e1)[local_3c * 0x14] * 4));
      }
      if ((((int)DAT_0067f37c >> 3 ^ local_3c & 3) & 3) == 0) {
        *(int *)(g_DisplaySurfaceScreen + 0x20) = 3;
        g_OverworldWorldState = 0;
        Adventure_FormatNewsString(local_34,0,0);
      }
    }
LAB_004be98f:
    local_3c = local_3c + 1;
  } while( true );
}

/*
 * Ai_Subsystem_004bf23a
 * Purpose: Tactical AI engine subsystem routine (004bf23a).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004bf23a
 * Entry Point: 004bf23a
 * Size: 633 bytes
 */

void Ai_Subsystem_004bf23a(void)

{
  int status;
  uint u_temp;
  int temp_idx;
  int card_idx;
  int iVar5;
  int iVar6;
  DWORD DVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int *piVar11;
  
  iVar9 = DAT_00677fc0;
  iVar5 = DAT_00677e14;
  if (g_AiManaColorCost_White != -1) {
    status = DAT_0067bddc - DAT_00641020;
    if (DAT_0052f008 == 0) {
      u_temp = Ai_Util_004c3bc4(0x23a);
      temp_idx = Ai_Util_004c3bc4(0x148);
      card_idx = Ai_Util_004c3bc4(0x135);
      temp_idx = temp_idx - card_idx;
      DVar7 = *(DWORD *)(PTR_DAT_005174bc + 0x10);
      piVar11 = (int *)g_DisplaySurfaceBackBuffer;
      uVar8 = u_temp;
      card_idx = Ai_Util_004c3bc4(0x280);
      FUN_0050dce0((int *)PTR_DAT_005174bc,u_temp,0,card_idx - u_temp,DVar7,piVar11,uVar8,temp_idx);
      temp_idx = DAT_00677e14;
      card_idx = Ai_Util_004c3bc4((int)*(short *)(iVar5 + 6));
      iVar5 = Ai_Util_004c3bc4((int)*(short *)(iVar5 + 4));
      iVar10 = 0;
      iVar6 = Ai_Util_004c3bc4(0x181);
      Sprite_DrawScaled((int *)g_DisplaySurfaceBackBuffer,iVar6,iVar10,iVar5,card_idx,temp_idx);
      iVar5 = (&DAT_00677fc0)[DAT_0067f37c & 7];
      temp_idx = Ai_Util_004c3bc4((int)*(short *)(iVar9 + 6));
      card_idx = Ai_Util_004c3bc4((int)*(short *)(iVar9 + 4));
      iVar6 = Ai_Util_004c3bc4(0x15);
      iVar10 = Ai_Util_004c3bc4(0x23a);
      Sprite_DrawScaled((int *)g_DisplaySurfaceBackBuffer,iVar10,iVar6,card_idx,temp_idx,iVar5);
      iVar5 = *(int *)(&DAT_00677f50 + ((DAT_0067bddc - DAT_00641020) % 0xe) * 4);
      temp_idx = Ai_Util_004c3bc4((int)*(short *)(iVar9 + 6));
      card_idx = Ai_Util_004c3bc4((int)*(short *)(iVar9 + 4));
      iVar6 = Ai_Util_004c3bc4(0x15);
      iVar10 = Ai_Util_004c3bc4(0x23a);
      Sprite_DrawScaled((int *)g_DisplaySurfaceBackBuffer,iVar10,iVar6,card_idx,temp_idx,iVar5);
      iVar5 = *(int *)(&DAT_00678360 + (((int)(status + (status >> 0x1f & 0xfU)) >> 4) + 1) * 4);
      status = Ai_Util_004c3bc4((int)*(short *)(iVar9 + 6));
      temp_idx = Ai_Util_004c3bc4((int)*(short *)(iVar9 + 4));
      card_idx = Ai_Util_004c3bc4(0x15);
      iVar6 = Ai_Util_004c3bc4(0x23a);
      Sprite_DrawScaled((int *)g_DisplaySurfaceBackBuffer,iVar6,card_idx,temp_idx,status,iVar5);
      iVar5 = Ai_Util_004c3bc4(0x148);
      status = Ai_Util_004c3bc4(0x23a);
      piVar11 = (int *)g_DisplaySurfaceScreen;
      DVar7 = Ai_Util_004c3bc4((int)*(short *)(iVar9 + 6));
      uVar8 = Ai_Util_004c3bc4((int)*(short *)(iVar9 + 4));
      iVar9 = Ai_Util_004c3bc4(0x13);
      u_temp = Ai_Util_004c3bc4(0x23a);
      FUN_0050dce0((int *)g_DisplaySurfaceBackBuffer,u_temp,iVar9,uVar8,DVar7,piVar11,status,iVar5);
    }
  }
  return;
}

/*
 * Ai_CalcMana_004bf4b3
 * Purpose: Calculate mana requirements and available sources (004bf4b3).
 * Procedure:
 * 1. Query untapped mana sources.
 * 2. Verify spell cost.
 */
/*
 * Decompiled function: Ai_CalcMana_004bf4b3
 * Entry Point: 004bf4b3
 * Size: 2929 bytes
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void Ai_CalcMana_004bf4b3(int player)

{
  int status;
  int val_result;
  int temp_idx;
  int card_idx;
  int iVar5;
  uint uVar6;
  char *pcVar7;
  uint uVar8;
  DWORD DVar9;
  int *piVar10;
  char *local_420;
  char local_418 [1000];
  int local_30;
  int local_2c;
  int local_28;
  uint local_24;
  DWORD local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  status = DAT_00677e14;
  local_8 = DAT_00677e14;
  local_c = DAT_00677fc0;
  local_10 = *(int *)g_DisplaySurfaceBackBuffer;
  *(int *)g_DisplaySurfaceBackBuffer = 1;
  local_18 = ((int)((DAT_0067bddc - DAT_00641020) + (DAT_0067bddc - DAT_00641020 >> 0x1f & 0xfU)) >>
             4) + 1;
  if ((card_id == 0) ||
     ((((g_AiManaColorCost_White == 0xffffffff && (g_AiCardScoringThreshold == -1)) && (g_AiCombatLookaheadTarget == 0)) &&
      (g_AiManaColorCost_Blue == -1)))) {
    if (card_id != 0) {
      Ai_Subsystem_004be3c4(g_DisplaySurfaceScreen,0x181,0x135,DAT_00677e10,0xed,0x74);
    }
    goto LAB_004c002d;
  }
  _DAT_0052d7b4 = g_AiManaColorCost_Blue;
  _DAT_0052d7b0 = g_AiCombatLookaheadTarget;
  _DAT_00557474 = g_AiCardScoringThreshold;
  local_20 = Ai_Util_004c3bc4(*(short *)(status + 6) + -0x13);
  if (DAT_0052f008 == 0) {
    local_24 = Ai_Util_004c3bc4(0x17c);
    status = Ai_Util_004c3bc4(0x13);
    DVar9 = *(DWORD *)(PTR_DAT_005174bc + 0x10);
    piVar10 = (int *)g_DisplaySurfaceBackBuffer;
    uVar6 = local_24;
    val_result = Ai_Util_004c3bc4(0x280);
    FUN_0050dce0((int *)PTR_DAT_005174bc,local_24,0,val_result - local_24,DVar9,piVar10,uVar6,status);
    local_24 = Ai_Util_004c3bc4(0x181);
    status = DAT_00677e14;
    val_result = Ai_Util_004c3bc4((int)*(short *)(local_8 + 6));
    temp_idx = Ai_Util_004c3bc4((int)*(short *)(local_8 + 4));
    Sprite_DrawScaled((int *)g_DisplaySurfaceBackBuffer,local_24,0,temp_idx,val_result,status);
    if (g_AiManaColorCost_White != 0xffffffff) {
      status = (&DAT_00677fc0)[DAT_0067f37c & 7];
      val_result = Ai_Util_004c3bc4((int)*(short *)(local_c + 6));
      temp_idx = Ai_Util_004c3bc4((int)*(short *)(local_c + 4));
      card_idx = Ai_Util_004c3bc4(0x15);
      iVar5 = Ai_Util_004c3bc4(0x23a);
      Sprite_DrawScaled((int *)g_DisplaySurfaceBackBuffer,iVar5,card_idx,temp_idx,val_result,status);
      status = *(int *)(&DAT_00677f50 + ((DAT_0067bddc - DAT_00641020) % 0xe) * 4);
      val_result = Ai_Util_004c3bc4((int)*(short *)(local_c + 6));
      temp_idx = Ai_Util_004c3bc4((int)*(short *)(local_c + 4));
      card_idx = Ai_Util_004c3bc4(0x15);
      iVar5 = Ai_Util_004c3bc4(0x23a);
      Sprite_DrawScaled((int *)g_DisplaySurfaceBackBuffer,iVar5,card_idx,temp_idx,val_result,status);
      status = *(int *)(&DAT_00678360 + local_18 * 4);
      val_result = Ai_Util_004c3bc4((int)*(short *)(local_c + 6));
      temp_idx = Ai_Util_004c3bc4((int)*(short *)(local_c + 4));
      card_idx = Ai_Util_004c3bc4(0x15);
      iVar5 = Ai_Util_004c3bc4(0x23a);
      Sprite_DrawScaled((int *)g_DisplaySurfaceBackBuffer,iVar5,card_idx,temp_idx,val_result,status);
    }
  }
  status = g_AiBackupBoardRegister;
  *(int *)(g_DisplaySurfaceBackBuffer + 0x20) = 4;
  local_2c = 0x5b - (int)*(short *)(status + 6) / 2;
  local_28 = g_AiBackupBoardRegister;
  Ai_Subsystem_004be3c4
            (g_DisplaySurfaceBackBuffer,0x193,local_2c,g_AiBackupBoardRegister,
             (int)*(short *)(g_AiBackupBoardRegister + 4),(int)*(short *)(g_AiBackupBoardRegister + 6));
  FUN_0040d4d1((int)g_DisplaySurfaceBackBuffer,g_AiHeuristicWeight_HandAdvantage,0x1a9,
               local_2c + (int)*(short *)(local_28 + 6) / 2);
  local_24 = Ai_Util_004c3bc4(0x17c);
  local_1c = 0x200;
  local_14 = 0x33;
  *(int *)(g_DisplaySurfaceBackBuffer + 0x20) = 2;
  g_OverworldWorldState = 0;
  if (g_AiCardScoringThreshold == -1) {
    DAT_006410b0 = 0;
  }
  else {
    local_30 = 7;
    Adventure_FormatNewsString(g_AiCardScoringThreshold,0,0);
    strcat(&g_OverworldWorldState,s_attacking_0052db50);
    uVar6 = Duel_GetCardDrawOriginY
                      ((int)(*(int *)(&g_AiCardEvaluationScore + local_30 * 0x14) +
                            (*(int *)(&g_AiCardEvaluationScore + local_30 * 0x14) >> 0x1f & 0x1fU)) >> 5,
                       (int)(*(int *)(&g_AiCardSynergyScore + local_30 * 0x14) +
                            (*(int *)(&g_AiCardSynergyScore + local_30 * 0x14) >> 0x1f & 0x1fU)) >> 5);
    Ai_Subsystem_004c3b19(uVar6);
    strcat(&g_OverworldWorldState,&DAT_0052db5c);
  }
  if ((g_AiCombatLookaheadTarget != 0) || (g_AiManaColorCost_Blue != -1)) {
    strcat(&g_OverworldWorldState,s_Next_Duel__0052db60);
    if (g_AiCombatLookaheadTarget != 0) {
      strcat(&g_OverworldWorldState,&DAT_0052db6c + ((-1 < g_AiCombatLookaheadTarget) - 1 & 4));
      pcVar7 = _itoa(g_AiCombatLookaheadTarget,&DAT_00557498,10);
      strcat(&g_OverworldWorldState,pcVar7);
      strcat(&g_OverworldWorldState,s_lives_0052db74);
      status = DAT_00677fac;
      val_result = Ai_Util_004c3bc4(0x25);
      temp_idx = Ai_Util_004c3bc4(0x1c);
      card_idx = Ai_Util_004c3bc4(200);
      iVar5 = Ai_Util_004c3bc4(0x254);
      Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,iVar5,card_idx,temp_idx,val_result,status);
    }
    if (g_AiManaColorCost_Blue == 0) {
      strcat(&g_OverworldWorldState,s_First_Move_0052db7c);
      status = DAT_00677fa4;
      val_result = Ai_Util_004c3bc4(0x25);
      temp_idx = Ai_Util_004c3bc4(0x1c);
      card_idx = Ai_Util_004c3bc4(200);
      iVar5 = Ai_Util_004c3bc4(0x254);
      Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,iVar5,card_idx,temp_idx,val_result,status);
    }
    if ((0 < g_AiManaColorCost_Blue) && (g_AiManaColorCost_Blue < 6)) {
      strcat(&g_OverworldWorldState,&DAT_0052db88);
      pcVar7 = _itoa(g_AiManaColorCost_Blue,&DAT_00557498,10);
      strcat(&g_OverworldWorldState,pcVar7);
      strcat(&g_OverworldWorldState,s_lives_0052db8c);
      status = DAT_00677fa8;
      val_result = Ai_Util_004c3bc4(0x25);
      temp_idx = Ai_Util_004c3bc4(0x1c);
      card_idx = Ai_Util_004c3bc4(200);
      iVar5 = Ai_Util_004c3bc4(0x254);
      Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,iVar5,card_idx,temp_idx,val_result,status);
    }
    if (5 < g_AiManaColorCost_Blue) {
      strcat(&g_OverworldWorldState,s_Swamp_0051aea9 + g_AiManaColorCost_Blue * 0x34);
      status = DAT_00677fa0;
      val_result = Ai_Util_004c3bc4(0x25);
      temp_idx = Ai_Util_004c3bc4(0x1c);
      card_idx = Ai_Util_004c3bc4(0x90);
      iVar5 = Ai_Util_004c3bc4(0x254);
      Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,iVar5,card_idx,temp_idx,val_result,status);
    }
    strcat(&g_OverworldWorldState,&DAT_0052db94);
  }
  if (g_AiManaColorCost_White == 0xffffffff) {
LAB_004bfef2:
    FUN_0040d4d1((int)g_DisplaySurfaceBackBuffer,0xff,local_1c,0x41);
    status = Ai_Util_004c3bc4(0x148);
    DVar9 = local_20;
    piVar10 = (int *)g_DisplaySurfaceScreen;
    uVar6 = local_24;
    val_result = Ai_Util_004c3bc4(0x280);
    uVar8 = val_result - local_24;
    val_result = Ai_Util_004c3bc4(0x13);
    FUN_0050dce0((int *)g_DisplaySurfaceBackBuffer,local_24,val_result,uVar8,DVar9,piVar10,uVar6,status);
  }
  else {
    if (g_AiHandEvaluationBuffer == 0) {
      strcat(&g_OverworldWorldState,s_Mana_Link_0052dbac);
    }
    else {
      if (*(int *)(&g_CardSlot_CreatureType + g_AiManaColorCost_White * 100) == 1) {
        pcVar7 = (char *)Mem_AllocOrFree_00473d7e(DAT_0067b9a0);
        strcat(&g_OverworldWorldState,pcVar7);
        strcat(&g_OverworldWorldState,s_mana_stone__0052db98);
      }
      else {
        FUN_0050a73e(g_AiManaColorCost_White);
      }
      strcat(&g_OverworldWorldState,&DAT_0052dba8);
    }
    if ((((g_AiHandEvaluationBuffer != 0) && (g_AiHandEvaluationBuffer != 2)) &&
        ((g_AiHandEvaluationBuffer != 1 ||
         (status = FUN_0050b0fc((byte)DAT_0067b9a0,(byte)(1 << ((byte)g_AiManaColorCost_White & 3))), status == 0
         )))) && (-0x65 < g_AiHandEvaluationBuffer)) {
      if (g_AiHandEvaluationBuffer == 1) {
        pcVar7 = (char *)Mem_AllocOrFree_00473d7e(DAT_0067b9a0);
        strcat(&g_OverworldWorldState,s_Find_0052dc18);
        Adventure_AppendNewsDetails((int)*pcVar7,0);
        strcat(&g_OverworldWorldState,pcVar7);
        strcat(&g_OverworldWorldState,&DAT_0052dc20);
        FUN_00484c45(1 << ((byte)g_AiManaColorCost_White & 3));
        strcat(&g_OverworldWorldState,&DAT_0052dc24);
      }
      if (g_AiHandEvaluationBuffer < 0) {
        strcat(&g_OverworldWorldState,s_Defeat_0052dc28);
        Adventure_FormatNewsString(-g_AiHandEvaluationBuffer,0,0);
      }
      goto LAB_004bfef2;
    }
    strcpy(local_418,&g_OverworldWorldState);
    local_18 = FUN_0050aef6(*(int *)(&DAT_0067bdf4 + g_AiManaColorCost_White * 100),
                            *(int *)(&DAT_0067bdf8 + g_AiManaColorCost_White * 100));
    if (DAT_0067f3bc != local_18) {
      DAT_0067f3bc = -1;
    }
    strcpy(&g_OverworldWorldState,local_418);
    switch(DAT_0067f3bc) {
    case 0:
      strcat(&g_OverworldWorldState,s_Go_North_to_0052dbe4);
      break;
    case 1:
      strcat(&g_OverworldWorldState,s_Go_East_to_0052dbf0);
      break;
    case 2:
      strcat(&g_OverworldWorldState,s_Go_South_to_0052dbfc);
      break;
    case 3:
      strcat(&g_OverworldWorldState,s_Go_West_to_0052dc08);
      break;
    case -1:
      if (g_AiHandEvaluationBuffer < 0) {
        strcat(&g_OverworldWorldState,s_Return_to_0052dbb8);
      }
      else {
        if ((g_AiHandEvaluationBuffer == 0) || (g_AiHandEvaluationBuffer == 2)) {
          local_420 = s_Take_letter_to_0052dbc4;
        }
        else {
          local_420 = s_Take_card_to_0052dbd4;
        }
        strcat(&g_OverworldWorldState,local_420);
      }
    }
    strcat(&g_OverworldWorldState,&DAT_0052dc14);
    Ai_Subsystem_004c3b19(g_AiManaColorCost_White);
    FUN_0040d4d1((int)g_DisplaySurfaceBackBuffer,0xff,local_1c,0x41);
    status = Ai_Util_004c3bc4(0x148);
    DVar9 = local_20;
    piVar10 = (int *)g_DisplaySurfaceScreen;
    uVar6 = local_24;
    val_result = Ai_Util_004c3bc4(0x280);
    uVar8 = val_result - local_24;
    val_result = Ai_Util_004c3bc4(0x13);
    FUN_0050dce0((int *)g_DisplaySurfaceBackBuffer,local_24,val_result,uVar8,DVar9,piVar10,uVar6,status);
  }
  if ((g_AiManaColorCost_White != 0xffffffff) && (DAT_0067bddc <= DAT_00641020)) {
    FUN_0040b3c2(0x11,g_AiHandEvaluationBuffer);
    strcpy(&g_OverworldWorldState,s_The_people_of_0052dc30);
    Ai_Subsystem_004c3b19(DAT_0067f370);
    strcat(&g_OverworldWorldState,s_are_sorry_their_quest_was_not_co_0052dc40);
    *(int *)(g_DisplaySurfaceScreen + 0x20) = 4;
    FUN_004896be(&g_OverworldWorldState,0x5a,0x50);
    *(uint *)(&g_CardSlot_StatusFlags + DAT_0067f370 * 100) =
         *(uint *)(&g_CardSlot_StatusFlags + DAT_0067f370 * 100) | 4;
    g_AiManaColorCost_White = 0xffffffff;
    Ai_Subsystem_004c05ba();
  }
LAB_004c002d:
  *(int *)g_DisplaySurfaceBackBuffer = local_10;
  return;
}

/*
 * Ai_CalcMana_004c003d
 * Purpose: Calculate mana requirements and available sources (004c003d).
 * Procedure:
 * 1. Query untapped mana sources.
 * 2. Verify spell cost.
 */
/*
 * Decompiled function: Ai_CalcMana_004c003d
 * Entry Point: 004c003d
 * Size: 1380 bytes
 */

void Ai_CalcMana_004c003d(void)

{
  uint arg1;
  char *pcVar1;
  int val_result;
  char *local_114;
  char local_10c [256];
  int local_c;
  int local_8;
  
  g_OverworldWorldState = 0;
  if (g_AiCardScoringThreshold != -1) {
    local_c = 7;
    Adventure_FormatNewsString(g_AiCardScoringThreshold,0,0);
    strcat(&g_OverworldWorldState,s_attacking_0052dc6c);
    arg1 = Duel_GetCardDrawOriginY
                      ((int)(*(int *)(&g_AiCardEvaluationScore + local_c * 0x14) +
                            (*(int *)(&g_AiCardEvaluationScore + local_c * 0x14) >> 0x1f & 0x1fU)) >> 5,
                       (int)(*(int *)(&g_AiCardSynergyScore + local_c * 0x14) +
                            (*(int *)(&g_AiCardSynergyScore + local_c * 0x14) >> 0x1f & 0x1fU)) >> 5);
    Ai_Subsystem_004c3b19(arg1);
    strcat(&g_OverworldWorldState,&DAT_0052dc78);
  }
  if ((g_AiCombatLookaheadTarget != 0) || (g_AiManaColorCost_Blue != -1)) {
    strcat(&g_OverworldWorldState,s_Next_Duel__0052dc7c);
    if (g_AiCombatLookaheadTarget != 0) {
      pcVar1 = _itoa(g_AiManaColorCost_Blue,&DAT_00557498,10);
      strcat(&g_OverworldWorldState,pcVar1);
      strcat(&g_OverworldWorldState,s_lives_0052dc88);
    }
    if (g_AiManaColorCost_Blue == 0) {
      strcat(&g_OverworldWorldState,s_First_Move_0052dc90);
    }
    if ((0 < g_AiManaColorCost_Blue) && (g_AiManaColorCost_Blue < 6)) {
      strcat(&g_OverworldWorldState,&DAT_0052dc9c);
      pcVar1 = _itoa(g_AiManaColorCost_Blue,&DAT_00557498,10);
      strcat(&g_OverworldWorldState,pcVar1);
      strcat(&g_OverworldWorldState,s_lives_0052dca0);
    }
    if (5 < g_AiManaColorCost_Blue) {
      strcat(&g_OverworldWorldState,s_Swamp_0051aea9 + g_AiManaColorCost_Blue * 0x34);
    }
    strcat(&g_OverworldWorldState,&DAT_0052dca8);
  }
  if ((g_CardSlot_ToughnessBonus == 0) && (g_AiManaColorCost_White != 0xffffffff)) {
    if (g_AiHandEvaluationBuffer == 0) {
      strcat(&g_OverworldWorldState,s_Mana_Link_0052dcc0);
    }
    else if (*(int *)(&g_CardSlot_CreatureType + g_AiManaColorCost_White * 100) == 1) {
      pcVar1 = (char *)Mem_AllocOrFree_00473d7e(DAT_0067b9a0);
      strcat(&g_OverworldWorldState,pcVar1);
      strcat(&g_OverworldWorldState,s_mana_stone__0052dcac);
    }
    else {
      FUN_0050a73e(g_AiManaColorCost_White);
      strcat(&g_OverworldWorldState,&DAT_0052dcbc);
    }
    if ((((g_AiHandEvaluationBuffer == 0) || (g_AiHandEvaluationBuffer == 2)) ||
        ((g_AiHandEvaluationBuffer == 1 &&
         (val_result = FUN_0050b0fc((byte)DAT_0067b9a0,(byte)(1 << ((byte)g_AiManaColorCost_White & 3))), val_result != 0
         )))) || (g_AiHandEvaluationBuffer < -100)) {
      strcpy(local_10c,&g_OverworldWorldState);
      local_8 = FUN_0050aef6(*(int *)(&DAT_0067bdf4 + g_AiManaColorCost_White * 100),
                             *(int *)(&DAT_0067bdf8 + g_AiManaColorCost_White * 100));
      strcpy(&g_OverworldWorldState,local_10c);
      if (DAT_0067f3bc != local_8) {
        DAT_0067f3bc = -1;
      }
      switch(DAT_0067f3bc) {
      case 0:
        strcat(&g_OverworldWorldState,s_Go_North_to_0052dcf8);
        break;
      case 1:
        strcat(&g_OverworldWorldState,s_Go_East_to_0052dd04);
        break;
      case 2:
        strcat(&g_OverworldWorldState,s_Go_South_to_0052dd10);
        break;
      case 3:
        strcat(&g_OverworldWorldState,s_Go_West_to_0052dd1c);
        break;
      case -1:
        if (g_AiHandEvaluationBuffer < 0) {
          strcat(&g_OverworldWorldState,s_Return_to_0052dccc);
        }
        else {
          if ((g_AiHandEvaluationBuffer == 0) || (g_AiHandEvaluationBuffer == 2)) {
            local_114 = s_Take_letter_to_0052dcd8;
          }
          else {
            local_114 = s_Take_card_to_0052dce8;
          }
          strcat(&g_OverworldWorldState,local_114);
        }
      }
      strcat(&g_OverworldWorldState,&DAT_0052dd28);
      Ai_Subsystem_004c3b19(g_AiManaColorCost_White);
      strcat(&g_OverworldWorldState,&DAT_0052dd2c);
    }
    else {
      if (g_AiHandEvaluationBuffer == 1) {
        pcVar1 = (char *)Mem_AllocOrFree_00473d7e(DAT_0067b9a0);
        strcat(&g_OverworldWorldState,s_Find_0052dd30);
        Adventure_AppendNewsDetails((int)*pcVar1,0);
        strcat(&g_OverworldWorldState,pcVar1);
        strcat(&g_OverworldWorldState,&DAT_0052dd38);
        FUN_00484c45(1 << ((byte)g_AiManaColorCost_White & 3));
        strcat(&g_OverworldWorldState,&DAT_0052dd3c);
      }
      if (g_AiHandEvaluationBuffer < 0) {
        strcat(&g_OverworldWorldState,s_Defeat_0052dd40);
        Adventure_FormatNewsString(-g_AiHandEvaluationBuffer,0,0);
        strcat(&g_OverworldWorldState,&DAT_0052dd48);
      }
    }
  }
  return;
}

/*
 * Ai_Subsystem_004c05ba
 * Purpose: Tactical AI engine subsystem routine (004c05ba).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004c05ba
 * Entry Point: 004c05ba
 * Size: 293 bytes
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Ai_Subsystem_004c05ba(void)

{
  int status;
  int val_result;
  uint u_score;
  DWORD DVar4;
  int *piVar5;
  int arg7;
  int arg_8;
  
  DAT_00558dc8 = 0xffffffff;
  _DAT_0052d774 = 0xffffffff;
  DAT_0052d778 = 1;
  if (g_IsAiThinking == 0) {
    Mem_AllocOrFree_00510e20(1,PTR_s_advinter800_pic_00530d98);
    FUN_0050dce0((int *)g_DisplaySurfaceBackBuffer,0,0,g_AiManaColorCost_Red,g_AiManaColorCost_Green,
                 (int *)g_DisplaySurfaceScreen,0,0);
    FUN_0041f2af(0,4);
  }
  DAT_00641884 = 0;
  if (DAT_005574a4 == 0) {
    arg_8 = 0;
    arg7 = 0;
    piVar5 = (int *)PTR_DAT_005174bc;
    status = Ai_Util_004c3bc4(0x1e0);
    val_result = Ai_Util_004c3bc4(0x148);
    DVar4 = status - val_result;
    u_score = Ai_Util_004c3bc4(0x280);
    status = Ai_Util_004c3bc4(0x148);
    FUN_0050dce0((int *)g_DisplaySurfaceBackBuffer,0,status,u_score,DVar4,piVar5,arg7,arg_8);
    val_result = 0;
    status = 0;
    piVar5 = (int *)PTR_DAT_005174e4;
    DVar4 = Ai_Util_004c3bc4(0x148);
    u_score = Ai_Util_004c3bc4(0x40);
    FUN_0050dce0((int *)g_DisplaySurfaceBackBuffer,0,0,u_score,DVar4,piVar5,status,val_result);
    DAT_005574a4 = 1;
  }
  return;
}

/*
 * Ai_Subsystem_004c06df
 * Purpose: Tactical AI engine subsystem routine (004c06df).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004c06df
 * Entry Point: 004c06df
 * Size: 2074 bytes
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Ai_Subsystem_004c06df(uint arg1, uint arg2)

{
  bool is_valid;
  byte is_match;
  byte bVar3;
  byte bVar4;
  int iVar5;
  int local_d8;
  uint local_d4;
  int local_d0;
  DWORD local_cc;
  uint local_c8;
  int local_c4;
  int local_bc;
  int local_b8;
  int local_88 [5];
  uint local_74;
  int local_64;
  int local_60 [2];
  int local_58;
  int local_54;
  int local_50 [3];
  uint local_44;
  int local_3c;
  int local_38;
  int local_24;
  int local_20;
  int local_1c [2];
  int local_14 [3];
  int local_8;
  
  local_20 = *(int *)g_DisplaySurfaceScreen;
  *(int *)g_DisplaySurfaceScreen = 2;
  g_AiLookaheadDelta = arg1;
  g_AiLookaheadBestMove = arg2;
  local_38 = arg1 - (arg1 & 0x1f);
  local_54 = arg2 - (arg2 & 0x1f);
  Ai_Subsystem_004be525(local_38,local_54,local_50,local_60);
  Ai_Subsystem_004be525(arg1,arg2,local_14,local_1c);
  Ai_Subsystem_004be525(0,0,local_88,&local_24);
  if ((DAT_00556c54 == 0) || (DAT_00641884 == 0)) {
    local_44 = 0xfffffff7;
    local_64 = 9;
    local_3c = -4;
    local_58 = 6;
    _DAT_00557480 = local_88[0];
    _DAT_00558dcc = local_24;
    DAT_00556c6c = arg1;
    DAT_00558dc4 = arg2;
    g_AiLookaheadScore_Player0 = 0;
    g_AiLookaheadScore_Player1 = 0;
    _DAT_0064187c = arg1;
    _DAT_00641880 = arg2;
    DAT_00556c68 = 0x40;
    DAT_00556c5c = g_AiPlayerScoreTable * 2 + g_AiHeuristicWeight_CardAdvantage + 0x10;
    DAT_00558dc0 = Ai_Util_004c3ba3(0x100);
    DAT_00557490 = Ai_Util_004c3ba3(0x8c);
    DAT_00557470 = -0x40;
    DAT_00558dd0 = 0x40;
    DAT_005574b4 = 0x80 - DAT_00556c5c;
    DAT_005574a8 = *(int *)(g_DisplaySurfaceScreen + 0x10) - (DAT_00556c5c + DAT_00557490);
    DAT_00556c54 = 1;
    DAT_00641884 = 1;
    Ai_Subsystem_004c0efe(arg1,arg2,local_3c,local_58,local_44,local_64,1,0);
    Ai_Subsystem_004c0efe(arg1,arg2,local_3c + -2,local_58,local_44,local_64 + 2,2,1);
  }
  else {
    is_valid = false;
    is_match = 0;
    bVar3 = 0;
    bVar4 = 0;
    iVar5 = (int)(arg1 + ((int)arg1 >> 0x1f & 0x1fU)) >> 5;
    local_8 = (int)(arg2 + ((int)arg2 >> 0x1f & 0x1fU)) >> 5;
    g_AiLookaheadScore_Player0 = *(int *)(&DAT_006418d0 + iVar5 * 4 + local_8 * 0x100) - local_50[0];
    local_60[0] = *(int *)(&DAT_006458d0 + iVar5 * 4 + local_8 * 0x100) - local_60[0];
    if ((g_AiLookaheadScore_Player0 != 0) || (local_60[0] != 0)) {
      if (((int)g_AiLookaheadScore_Player0 < 0) && ((int)g_AiLookaheadScore_Player0 <= DAT_00557470)) {
        is_valid = true;
      }
      if ((0 < (int)g_AiLookaheadScore_Player0) && (DAT_00558dd0 <= (int)g_AiLookaheadScore_Player0)) {
        is_match = 1;
      }
      if ((0 < local_60[0]) && (DAT_005574a8 <= local_60[0])) {
        bVar4 = 1;
      }
      if ((local_60[0] < 0) && (local_60[0] <= DAT_005574b4)) {
        bVar3 = 1;
      }
    }
    g_AiLookaheadScore_Player1 = local_60[0];
    local_74 = g_AiLookaheadScore_Player0;
    if (!(bool)(bVar4 | bVar3 | is_match) && !is_valid) {
      FUN_0050dce0((int *)g_DisplaySurfaceScreen,DAT_00556c68 + g_AiLookaheadScore_Player0,
                   DAT_00556c5c + local_60[0],DAT_00558dc0,DAT_00557490,
                   (int *)g_DisplaySurfaceBackBuffer,0x40,g_AiPlayerScoreTable * 2 + g_AiHeuristicWeight_CardAdvantage + 0x10);
      *(int *)g_DisplaySurfaceScreen = local_20;
      Ai_Subsystem_004c0efe(DAT_00556c6c,DAT_00558dc4,-5,4,0xfffffff9,9,0,1);
      g_AiLookaheadDelta = arg1;
      g_AiLookaheadBestMove = arg2;
      return;
    }
    Ai_Subsystem_004c0efe(arg1,arg2,-5,4,0xfffffff9,9,0,1);
    if ((int)local_74 < 1) {
      if ((int)local_74 < 0) {
        local_d4 = 0;
        local_bc = -local_74;
        local_c8 = *(int *)(g_DisplaySurfaceScreen + 0xc) + local_74;
        local_d0 = 1;
      }
      else {
        local_d4 = 0;
        local_bc = 0;
        local_c8 = *(uint *)(g_DisplaySurfaceScreen + 0xc);
        local_d0 = -1;
      }
    }
    else {
      local_d4 = local_74;
      local_bc = 0;
      local_c8 = *(int *)(g_DisplaySurfaceScreen + 0xc) - local_74;
      local_d0 = 2;
    }
    if (local_60[0] < 1) {
      if (local_60[0] < 0) {
        local_d8 = 0x80;
        local_c4 = 0x80 - local_60[0];
        local_cc = (*(int *)(g_DisplaySurfaceScreen + 0x10) + local_60[0]) - 0x80;
        local_b8 = 1;
      }
      else {
        local_d8 = 0x80;
        local_c4 = 0x80;
        local_cc = *(int *)(g_DisplaySurfaceScreen + 0x10) - 0x80;
        local_b8 = -1;
      }
    }
    else {
      local_d8 = local_60[0] + 0x80;
      local_c4 = 0x80;
      local_cc = (*(int *)(g_DisplaySurfaceScreen + 0x10) - local_60[0]) - 0x80;
      local_b8 = 2;
    }
    FUN_0050dce0((int *)g_DisplaySurfaceScreen,local_d4,local_d8,local_c8,local_cc,
                 (int *)g_DisplaySurfaceScreen,local_bc,local_c4);
    if (local_d0 == 1) {
      Ai_Subsystem_004c0efe(arg1,arg2,-3,-1,0xfffffff9,7,1,0);
      if (local_b8 == 1) {
        Ai_Subsystem_004c0efe(arg1,arg2,-1,4,0xfffffff9,-3,1,0);
      }
      else if (local_b8 == 2) {
        Ai_Subsystem_004c0efe(arg1,arg2,-1,4,3,7,1,0);
      }
    }
    else if (local_d0 == 2) {
      Ai_Subsystem_004c0efe(arg1,arg2,2,5,0xfffffff9,7,1,0);
      if (local_b8 == 1) {
        Ai_Subsystem_004c0efe(arg1,arg2,-3,2,0xfffffff9,-3,1,0);
      }
      else if (local_b8 == 2) {
        Ai_Subsystem_004c0efe(arg1,arg2,-3,2,3,7,1,0);
      }
    }
    else if (local_b8 == 1) {
      Ai_Subsystem_004c0efe(arg1,arg2,-3,5,0xfffffff9,-3,1,0);
    }
    else if (local_b8 == 2) {
      Ai_Subsystem_004c0efe(arg1,arg2,-3,5,3,7,1,0);
    }
    Ai_Subsystem_004c0efe(arg1,arg2,-4,6,0xfffffff7,0xb,2,0);
    _DAT_00557480 = local_88[0];
    _DAT_00558dcc = local_24;
    DAT_00556c6c = arg1;
    DAT_00558dc4 = arg2;
    g_AiLookaheadScore_Player0 = 0;
    g_AiLookaheadScore_Player1 = 0;
    _DAT_0064187c = arg1;
    _DAT_00641880 = arg2;
  }
  g_AiLookaheadDelta = arg1;
  g_AiLookaheadBestMove = arg2;
  FUN_0050dce0((int *)g_DisplaySurfaceScreen,DAT_00556c68,DAT_00556c5c,DAT_00558dc0,DAT_00557490,
               (int *)g_DisplaySurfaceBackBuffer,0x40,g_AiPlayerScoreTable * 2 + g_AiHeuristicWeight_CardAdvantage + 0x10);
  *(int *)g_DisplaySurfaceScreen = local_20;
  return;
}

/*
 * Ai_Subsystem_004c0efe
 * Purpose: Tactical AI engine subsystem routine (004c0efe).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004c0efe
 * Entry Point: 004c0efe
 * Size: 4369 bytes
 */

void Ai_Subsystem_004c0efe(uint arg1, uint arg2, int arg3, int arg4, uint arg5, int arg6, int arg7, int arg8)

{
  short s_res;
  int val_result;
  int temp_idx;
  int card_idx;
  char *output_str;
  uint u_extra;
  bool bVar6;
  int uVar7;
  int local_bc;
  int local_b4;
  int local_a0;
  int local_80;
  int local_7c;
  int local_78;
  int local_74;
  uint local_70;
  uint local_6c;
  uint local_68;
  int local_64;
  uint local_60;
  int local_5c;
  uint local_58;
  int local_54;
  uint local_50;
  int local_4c;
  int local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  int local_38;
  uint local_34;
  int local_30;
  uint local_2c;
  uint local_28;
  int local_24;
  int local_20;
  int local_1c;
  uint local_18;
  uint local_14;
  uint local_10;
  int local_c;
  uint local_8;
  
  local_20 = *(int *)g_DisplaySurfaceScreen;
  *(int *)g_DisplaySurfaceScreen = 2;
  g_AiLookaheadDelta = arg1;
  g_AiLookaheadBestMove = arg2;
  local_38 = arg1 - (arg1 & 0x1f);
  local_4c = arg2 - (arg2 & 0x1f);
  Ai_Subsystem_004be525(local_38,local_4c,&local_48,&local_54);
  for (local_8 = arg5; (int)local_8 < arg6; local_8 = local_8 + 1) {
    for (local_80 = arg3; local_80 < arg4; local_80 = local_80 + 1) {
      local_78 = local_80 * g_AiHeuristicWeight_Tempo + local_48;
      local_24 = local_8 * g_AiPlayerScoreTable + local_54;
      if ((local_8 & 1) != 0) {
        local_78 = local_78 + g_AiHeuristicWeight_Tempo / 2;
      }
      Ai_Subsystem_004be5ae(local_78 + 0x10,local_24,(int *)&local_14,&local_1c);
      local_14 = (int)(local_14 + ((int)local_14 >> 0x1f & 0x1fU)) >> 5;
      local_1c = (int)(local_1c + (local_1c >> 0x1f & 0x1fU)) >> 5;
      val_result = abs(local_8);
      if ((val_result < 8) && (val_result = abs(local_80), val_result < 4)) {
        FUN_0040c81c(0x80,local_14,local_1c);
      }
      local_58 = FUN_0040c7c0(local_14,local_1c);
      local_2c = local_58 & 0xf;
      if (arg_8 != 0) {
        *(int *)(&DAT_006418d0 + local_14 * 4 + local_1c * 0x100) = local_78;
        *(int *)(&DAT_006458d0 + local_14 * 4 + local_1c * 0x100) = local_24;
      }
      local_24 = local_24 - g_AiPlayerScoreTable;
      local_50 = Adventure_GetLocationEncounterIndex(local_2c);
      if ((arg7 != 2) && ((arg_8 == 0 || (arg7 != 0)))) {
        if (((local_2c == 0) || (local_2c == 8)) && (arg7 != 0)) {
          Sprite_DrawClipped((int *)g_DisplaySurfaceScreen,local_78,local_24,DAT_00677654);
        }
        else if (arg7 != 0) {
          if (local_2c == 1) {
            Sprite_DrawClipped((int *)g_DisplaySurfaceScreen,local_78,local_24,DAT_00677658);
          }
          else {
            if (local_50 == 2) {
              local_a0 = DAT_00677660;
            }
            else {
              local_a0 = DAT_00677650;
            }
            Sprite_DrawClipped((int *)g_DisplaySurfaceScreen,local_78,local_24,local_a0);
          }
          local_10 = 0;
          local_34 = 0;
          for (local_3c = 1; (int)local_3c < 9; local_3c = local_3c + 1) {
            local_34 = (int)local_34 >> 1;
            local_10 = (int)local_10 >> 1;
            local_60 = FUN_0040c761(*(int *)(&DAT_00522378 + local_3c * 4) + local_14,
                                    *(int *)(&DAT_005223e0 + local_3c * 4) + local_1c);
            local_68 = Adventure_GetLocationEncounterIndex(local_60);
            if (((local_60 == 0) || (local_60 == 8)) ||
               ((local_2c != local_60 && (((local_50 | local_68) & 4) != 0)))) {
              local_34 = local_34 | 0x80;
            }
            if ((local_50 != 2) && (local_68 == 2)) {
              local_10 = local_10 | 0x80;
            }
          }
          local_40 = local_10;
          local_10 = local_10 | local_10 << 8;
          if ((local_10 != 0) && (DAT_005239f0 == 0)) {
            for (local_3c = 0; (int)local_3c < 4; local_3c = local_3c + 1) {
              switch(local_3c) {
              case 0:
                local_28 = local_10 & 7;
                break;
              case 1:
                local_28 = local_10 >> 4 & 7;
                break;
              case 2:
                local_28 = local_10 >> 6 & 7;
                break;
              case 3:
                local_28 = local_10 >> 2 & 7;
              }
              u_extra = local_28 - 1;
              bVar6 = local_28 != 0;
              local_28 = u_extra;
              if (bVar6) {
                if ((int)local_3c < 2) {
                  Sprite_DrawClipped((int *)g_DisplaySurfaceScreen,local_78 + g_AiPlayerScoreTable,
                                     (local_3c & 1) * g_AiPlayerScoreTable + local_24,
                                     *(int *)(&DAT_00677820 + (local_3c + 4) * 0x1c + u_extra * 4));
                }
                else {
                  Sprite_DrawClipped((int *)g_DisplaySurfaceScreen,
                                     (local_3c & 1) * g_AiPlayerScoreTable * 2 + local_78,
                                     local_24 + g_AiPlayerScoreTable / 2,
                                     *(int *)(&DAT_00677820 + (local_3c + 4) * 0x1c + u_extra * 4));
                }
              }
            }
          }
          local_40 = local_34;
          local_34 = local_34 | local_34 << 8;
          if ((local_34 != 0) && (DAT_005239f0 == 0)) {
            for (local_3c = 0; (int)local_3c < 4; local_3c = local_3c + 1) {
              switch(local_3c) {
              case 0:
                local_28 = local_34 & 7;
                break;
              case 1:
                local_28 = local_34 >> 4 & 7;
                break;
              case 2:
                local_28 = local_34 >> 6 & 7;
                break;
              case 3:
                local_28 = local_34 >> 2 & 7;
              }
              u_extra = local_28 - 1;
              bVar6 = local_28 != 0;
              local_28 = u_extra;
              if (bVar6) {
                if ((int)local_3c < 2) {
                  Sprite_DrawClipped((int *)g_DisplaySurfaceScreen,local_78 + g_AiPlayerScoreTable,
                                     (local_3c & 1) * g_AiPlayerScoreTable + local_24,
                                     *(int *)(&DAT_00677820 + u_extra * 4 + local_3c * 0x1c));
                }
                else {
                  Sprite_DrawClipped((int *)g_DisplaySurfaceScreen,
                                     (local_3c & 1) * g_AiPlayerScoreTable * 2 + local_78,
                                     local_24 + g_AiPlayerScoreTable / 2,
                                     *(int *)(&DAT_00677820 + u_extra * 4 + local_3c * 0x1c));
                }
              }
            }
          }
        }
        val_result = FUN_0040cbbd(local_14,local_1c);
        if (val_result == 0) {
          local_44 = 0;
        }
        else {
          local_44 = Surface_GetPixelPtr((int *)g_DisplaySurfaceWork,local_14,local_1c + 0x40);
        }
        if (local_44 != 0) {
          for (local_3c = 0; (int)local_3c < 8; local_3c = local_3c + 1) {
            if (((local_44 & 1 << ((byte)local_3c & 0x1f)) != 0) && (arg7 != 0)) {
              Sprite_DrawClipped((int *)g_DisplaySurfaceScreen,local_78,local_24,
                                 *(int *)(&DAT_00677354 + (local_3c - 2 & 7) * 4));
            }
          }
        }
      }
      if (arg7 != 1) {
        local_74 = local_24 + g_AiPlayerScoreTable;
        if ((local_58 & 0x10) == 0) {
          local_70 = (uint)((-local_14 - local_1c & 2) != 0);
          val_result = abs(local_14);
          temp_idx = abs(local_1c);
          local_6c = val_result * 7 + temp_idx * 3;
          switch(local_2c) {
          case 0:
            local_5c = -1;
            break;
          case 1:
            local_5c = 1;
            break;
          case 2:
            local_5c = 2;
            break;
          case 3:
            local_5c = 0;
            break;
          default:
            local_5c = -1;
            break;
          case 5:
            local_5c = 3;
            break;
          case 6:
            local_5c = 4;
            break;
          case 8:
            local_5c = 5;
            break;
          case 10:
            local_5c = 7;
            break;
          case 0xd:
            local_5c = 6;
            break;
          case 0xf:
            local_5c = 8;
          }
          local_40 = 0;
          local_64 = g_AiHeuristicWeight_Tempo / (((int)local_6c % 5) * 2 + 4);
          u_extra = (int)local_6c >> 0x1f;
          local_7c = Ai_Util_004c3bc4((((local_6c ^ u_extra) - u_extra & 3 ^ u_extra) - u_extra) * 2 + 5);
          if (local_2c == 1) {
            local_7c = 0;
            local_64 = 0;
          }
          if (-1 < local_5c) {
            local_30 = (int)local_6c % 0xb;
            if (4 < local_5c) {
              local_5c = local_5c % 5;
              local_30 = local_30 + 0xb;
            }
            if (*(short *)(*(int *)(&DAT_00677450 + local_5c * 4 + local_30 * 0x14) + 10) == 0xffff)
            {
              local_c = 0;
            }
            else {
              local_c = (int)*(short *)(*(int *)(&DAT_00677450 + local_5c * 4 + local_30 * 0x14) +
                                       10);
            }
            if (arg_8 != 0) {
              if (local_40 == 0) {
                val_result = -local_7c;
                local_b4 = local_64;
              }
              else {
                local_b4 = -local_64;
                val_result = local_7c;
              }
              Ai_Subsystem_004be25f
                        (g_DisplaySurfaceScreen,local_78 + local_b4,(local_74 - local_c) + val_result,
                         local_74 + val_result,
                         *(int *)(&DAT_00677450 + local_5c * 4 + local_30 * 0x14));
            }
            if (arg7 != 0) {
              if (local_40 == 0) {
                val_result = -local_7c;
                local_bc = local_64;
              }
              else {
                local_bc = -local_64;
                val_result = local_7c;
              }
              Sprite_DrawClipped((int *)g_DisplaySurfaceScreen,local_78 + local_bc,
                                 (local_74 - local_c) + val_result,
                                 *(int *)(&DAT_00678010 + local_5c * 4 + local_30 * 0x14));
            }
            local_40 = (uint)(local_40 == 0);
            local_30 = ((local_30 < 0xb) - 1 & 0xb) + (int)(local_14 + local_6c) % 0xb;
            if (*(short *)(*(int *)(&DAT_00677450 + local_5c * 4 + local_30 * 0x14) + 10) == 0xffff)
            {
              local_c = 0;
            }
            else {
              local_c = (int)*(short *)(*(int *)(&DAT_00677450 + local_5c * 4 + local_30 * 0x14) +
                                       10);
            }
            if (arg_8 != 0) {
              Ai_Subsystem_004be25f
                        (g_DisplaySurfaceScreen,local_78 - local_64,(local_74 - local_c) + local_7c,
                         local_74 + local_7c,
                         *(int *)(&DAT_00677450 + local_5c * 4 + local_30 * 0x14));
            }
            if (arg7 != 0) {
              Sprite_DrawClipped((int *)g_DisplaySurfaceScreen,local_78 - local_64,
                                 (local_74 - local_c) + local_7c,
                                 *(int *)(&DAT_00678010 + local_5c * 4 + local_30 * 0x14));
            }
          }
        }
        if ((((local_58 & 0x40) != 0) &&
            (local_3c = FUN_0048ec9a(local_14,local_1c), -1 < (int)local_3c)) &&
           (*(int *)(&DAT_0067f010 + local_3c * 0x30) != 0)) {
          local_40 = local_3c * 2 - 10;
          val_result = *(int *)(&DAT_00677a10 + *(int *)(&DAT_0052d7b8 + local_40 * 4) * 4);
          if (arg_8 != 0) {
            Ai_Subsystem_004be25f
                      (g_DisplaySurfaceScreen,local_78,
                       (local_74 - *(short *)(val_result + 6)) + g_AiPlayerScoreTable,local_74,
                       *(int *)(&DAT_00677a10 + *(int *)(&DAT_0052d7b8 + local_40 * 4) * 4));
          }
          if (arg7 != 0) {
            Sprite_DrawClipped((int *)g_DisplaySurfaceScreen,local_78,
                               (local_74 - *(short *)(val_result + 6)) + g_AiPlayerScoreTable,
                               *(int *)(&DAT_00677a10 + *(int *)(&DAT_0052d7bc + local_40 * 4) * 4))
            ;
          }
        }
        if ((local_58 & 0x10) != 0) {
          local_18 = Duel_GetCardDrawOriginX(local_14,local_1c);
          val_result = local_74;
          if (*(int *)(&g_CardSlot_CreatureType + local_18 * 100) == 4) {
            temp_idx = FUN_00473cc5((byte)local_50);
            val_result = local_74;
            local_50 = temp_idx - 1;
            if (arg_8 != 0) {
              uVar7 = *(int *)(&DAT_00678660 + (char)(&DAT_0052d818)[local_50 * 4] * 4);
              temp_idx = local_74;
              card_idx = Ai_Util_004c3bc4(0xa0);
              Ai_Subsystem_004be25f(g_DisplaySurfaceScreen,local_78,val_result - card_idx,temp_idx,uVar7);
            }
            val_result = local_74;
            if (arg7 != 0) {
              temp_idx = *(int *)(&DAT_00678660 + (char)(&DAT_0052d819)[local_50 * 4] * 4);
              card_idx = Ai_Util_004c3bc4(0xa0);
              Sprite_DrawClipped((int *)g_DisplaySurfaceScreen,local_78,val_result - card_idx,temp_idx);
            }
          }
          else if (*(int *)(&g_CardSlot_CreatureType + local_18 * 100) == 5) {
            temp_idx = FUN_00473cc5((byte)local_50);
            val_result = local_74;
            local_50 = temp_idx - 1;
            if (arg_8 != 0) {
              uVar7 = *(int *)(&DAT_00678660 + (char)(&DAT_0052d832)[local_50 * 4] * 4);
              temp_idx = local_74;
              card_idx = Ai_Util_004c3bc4(0xa0);
              Ai_Subsystem_004be25f(g_DisplaySurfaceScreen,local_78,val_result - card_idx,temp_idx,uVar7);
            }
            val_result = local_74;
            if (arg7 != 0) {
              temp_idx = *(int *)(&DAT_00678660 + (char)(&DAT_0052d833)[local_50 * 4] * 4);
              card_idx = Ai_Util_004c3bc4(0xa0);
              Sprite_DrawClipped((int *)g_DisplaySurfaceScreen,local_78,val_result - card_idx,temp_idx);
            }
          }
          else if ((&DAT_0067be01)[local_18 * 100] == '\0') {
            if (*(int *)(&g_CardSlot_CreatureType + local_18 * 100) == 1) {
              local_40 = (local_14 & 1) * 2 + 0x20;
            }
            else {
              u_extra = (int)local_18 >> 0x1f;
              local_40 = (((local_18 ^ u_extra) - u_extra & 0xf ^ u_extra) - u_extra) * 2;
            }
            s_res = *(short *)(*(int *)(&DAT_00677a10 + (char)(&DAT_0052d780)[local_40] * 4) + 6);
            if (arg_8 != 0) {
              uVar7 = *(int *)(&DAT_00677a10 + (char)(&DAT_0052d780)[local_40] * 4);
              temp_idx = Ai_Util_004c3bc4(0x18);
              Ai_Subsystem_004be25f
                        (g_DisplaySurfaceScreen,local_78,temp_idx + (local_74 - s_res),val_result,uVar7);
            }
            if (arg7 != 0) {
              val_result = *(int *)(&DAT_00677a10 + *(char *)(local_40 + 0x52d781) * 4);
              temp_idx = Ai_Util_004c3bc4(0x18);
              Sprite_DrawClipped((int *)g_DisplaySurfaceScreen,local_78,temp_idx + (local_74 - s_res),
                                 val_result);
            }
          }
          else {
            if (arg_8 != 0) {
              uVar7 = *(int *)
                       (&DAT_00677ff0 + ((*(int *)(&g_CardSlot_StatusFlags + local_18 * 100) >> 8) + -1) * 4);
              temp_idx = local_74;
              card_idx = Ai_Util_004c3bc4(0xa6);
              Ai_Subsystem_004be25f(g_DisplaySurfaceScreen,local_78,val_result - card_idx,temp_idx,uVar7);
            }
            val_result = local_74;
            if (arg7 != 0) {
              temp_idx = DAT_006784f8;
              card_idx = Ai_Util_004c3bc4(0xa6);
              Sprite_DrawClipped((int *)g_DisplaySurfaceScreen,local_78,val_result - card_idx,temp_idx);
            }
          }
          if ((local_18 == g_AiManaColorCost_White) && (arg7 != 0)) {
            *(int *)(g_DisplaySurfaceScreen + 0x20) = 1;
            if ((*(int *)(&g_CardSlot_CreatureType + local_18 * 100) < 2) && (local_18 != g_AiManaColorCost_White)) {
              FUN_0040d201((int)g_DisplaySurfaceScreen,0xff,local_78 + g_AiHeuristicWeight_Tempo / 2,
                           local_74 + g_AiPlayerScoreTable / 2);
            }
            else {
              if (*(int *)(&g_CardSlot_CreatureType + local_18 * 100) == 4) {
                local_40 = FUN_00473cc5((byte)local_50);
                output_str = (char *)Mem_AllocOrFree_00473d7e(local_40);
                strcpy(&g_OverworldWorldState,output_str);
                *(uint *)(&DAT_0067f010 + (local_40 - 1) * 0x30) =
                     *(uint *)(&DAT_0067f010 + (local_40 - 1) * 0x30) | 1;
              }
              else {
                val_result = local_18 + ((int)local_18 >> 0x1f & 7U);
                u_extra = val_result >> 0x1f;
                strcpy(&g_OverworldWorldState,
                       (&PTR_s_Amanaxis_00522460)
                       [((val_result >> 3 ^ u_extra) - u_extra & 0xf ^ u_extra) - u_extra]);
              }
              if (*(int *)(&g_CardSlot_CreatureType + local_18 * 100) == 4) {
                strcat(&g_OverworldWorldState,s_Castle_0052dd4c);
              }
              else if (*(int *)(&g_CardSlot_CreatureType + local_18 * 100) < 2) {
                if (*(int *)(&g_CardSlot_CreatureType + local_18 * 100) == 1) {
                  strcat(&g_OverworldWorldState,s_Village_0052dd54);
                }
              }
              else {
                u_extra = (int)local_18 >> 0x1f;
                strcat(&g_OverworldWorldState,
                       (&PTR_s_Tower_005224a0)[((local_18 ^ u_extra) - u_extra & 0xf ^ u_extra) - u_extra]);
              }
              FUN_0040d201((int)g_DisplaySurfaceScreen,0xff,local_78 + g_AiHeuristicWeight_Tempo / 2,
                           local_74 + g_AiPlayerScoreTable / 2);
            }
          }
        }
      }
    }
  }
  Ai_Subsystem_004be525(g_AiLookaheadDelta,g_AiLookaheadBestMove,&local_78,&local_24);
  *(int *)g_DisplaySurfaceScreen = local_20;
  return;
}

/*
 * Ai_Simulate_EvaluateMoveTree
 * Purpose: Evaluate mini-max game tree of candidate moves.
 * Procedure:
 * 1. Perform recursive lookahead search up to depth limit.
 */
/*
 * Decompiled function: Ai_Simulate_EvaluateMoveTree
 * Entry Point: 004c207a
 * Size: 497 bytes
 */

int Ai_Simulate_EvaluateMoveTree(int arg1, int arg2)

{
  int status;
  bool is_match;
  int u_score;
  int local_28;
  
  if (DAT_00680770 == 0) {
    if ((DAT_007039cc < *(int *)(arg1 + 0x10)) ||
       (*(int *)(arg1 + 0x18) + *(int *)(arg1 + 0x10) < DAT_007039cc)) {
      is_match = false;
    }
    else if ((DAT_007039c8 < *(int *)(arg1 + 0x14)) ||
            (*(int *)(arg1 + 0x14) + *(int *)(arg1 + 0x1c) < DAT_007039c8)) {
      is_match = false;
    }
    else {
      is_match = true;
    }
    if (!is_match) {
      return 0;
    }
  }
  if (*(int *)(arg1 + 0x40) == 3) {
    u_score = 0;
  }
  else {
    u_score = *(int *)g_DisplaySurfaceScreen;
    *(int *)g_DisplaySurfaceScreen = 0;
    status = *(int *)(&DAT_0052d8c4 + *(int *)(arg1 + 0x2c) * 0x54);
    if (arg2 == 0) {
      local_28 = 0;
    }
    else if (arg2 == 1) {
      local_28 = 1;
    }
    else if (arg2 == 2) {
      local_28 = 2;
    }
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,(&DAT_0052d8a8)[status * 0x15],
                      *(int *)(&DAT_0052d8ac + status * 0x54),*(int *)(&DAT_0052d8b0 + status * 0x54),
                      *(int *)(&DAT_0052d8b4 + status * 0x54),(&DAT_00641890)[status * 3 + local_28]);
    *(int *)g_DisplaySurfaceScreen = u_score;
    if ((arg2 == 2) && (*(int *)(arg1 + 0x28) != 0)) {
      (**(code **)(arg1 + 0x28))(arg1);
    }
    u_score = 1;
  }
  return u_score;
}

/*
 * Ai_Subsystem_004c2270
 * Purpose: Tactical AI engine subsystem routine (004c2270).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004c2270
 * Entry Point: 004c2270
 * Size: 50 bytes
 */

int Ai_Subsystem_004c2270(int arg1)

{
  Adventure_Audio_PlayEffect(s_x_sound_button2_wav_0052dd68,0xf,100,100,0);
  g_AiHeuristicWeight_Lifelink = *(int *)(arg1 + 0x2c);
  return 0;
}

/*
 * Ai_Subsystem_004c22a2
 * Purpose: Tactical AI engine subsystem routine (004c22a2).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004c22a2
 * Entry Point: 004c22a2
 * Size: 158 bytes
 */

int Ai_Subsystem_004c22a2(int x, int y, int width, byte * arg4)

{
  int status;
  int local_14;
  int local_10;
  int local_c;
  
  local_14 = 0x7fffffff;
  for (local_c = 0; local_c < 0x100; local_c = local_c + 1) {
    status = *(int *)(PTR_DAT_0052a1a4 + (width - (uint)arg4[2]) * 4) +
            *(int *)(PTR_DAT_0052a1a4 + (y - (uint)arg4[1]) * 4) +
            *(int *)(PTR_DAT_0052a1a4 + (x - (uint)*arg4) * 4);
    if (status < local_14) {
      local_10 = local_c;
      local_14 = status;
    }
    arg4 = arg4 + 3;
  }
  return local_10;
}

/*
 * Ai_Subsystem_004c2340
 * Purpose: Tactical AI engine subsystem routine (004c2340).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004c2340
 * Entry Point: 004c2340
 * Size: 371 bytes
 */

void Ai_Subsystem_004c2340(int * arg1, int arg2, int arg3, int arg4, int arg5, uint arg6, int arg7)

{
  uint8_t u_res;
  byte local_430 [1024];
  uint local_30;
  uint local_28;
  uint local_24;
  int local_20;
  int local_1c;
  int local_18;
  byte *local_14;
  int local_c;
  int local_8;
  
  local_14 = (byte *)((int)&DAT_0070a134 + 2);
  if (arg7 != 0) {
    local_28 = arg6 & 0xff;
    local_30 = arg6 >> 8 & 0xff;
    local_24 = (arg6 & 0xff0000) >> 0x10;
    for (local_1c = 0; local_1c < 0x100; local_1c = local_1c + 1) {
      local_c = (int)(*local_14 + local_28) / 2;
      local_18 = (int)(local_14[1] + local_30) / 2;
      local_8 = (int)(local_14[2] + local_24) / 2;
      local_14 = local_14 + 3;
      u_res = Ai_Subsystem_004c22a2(local_c,local_18,local_8,(byte *)((int)&DAT_0070a134 + 2));
      (&DAT_00558cc0)[local_1c] = u_res;
    }
  }
  for (local_20 = arg3; local_20 < arg5 + arg3; local_20 = local_20 + 1) {
    Surface_GetLine((int *)local_430,*arg1,arg2,local_20,arg4);
    for (local_1c = 0; local_1c < arg4; local_1c = local_1c + 1) {
      local_430[local_1c] = (&DAT_00558cc0)[local_430[local_1c]];
    }
    Surface_PutLine((int *)local_430,*arg1,arg2,local_20,arg4);
  }
  return;
}

/*
 * Ai_Subsystem_004c24b3
 * Purpose: Tactical AI engine subsystem routine (004c24b3).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004c24b3
 * Entry Point: 004c24b3
 * Size: 5604 bytes
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Ai_Subsystem_004c24b3(int arg1)

{
  byte arg_1_00;
  int u_res;
  int val_result;
  int temp_idx;
  int card_idx;
  int iVar5;
  int iVar6;
  char *pcVar7;
  size_t sVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  int local_dc;
  int local_d4 [7];
  int local_b8;
  int local_b4;
  int local_b0;
  int local_ac;
  int local_a8;
  int local_a4 [8];
  int aiStack_84 [7];
  uint local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  uint local_40;
  int local_3c;
  uint local_38;
  int local_34;
  uint local_30;
  int local_2c;
  int local_28 [9];
  
  local_2c = 1;
  local_4c = 0;
  local_64 = arg1;
  local_a4[0] = 0xd2;
  local_a4[1] = 0;
  local_a4[2] = 0x40;
  local_a4[3] = 0xd0;
  local_a4[4] = 0xbe;
  local_a4[5] = 3;
  local_44 = -1;
  local_48 = -1;
  Adventure_LoadFacePalette(0);
  if (arg1 == 4) {
    arg1 = 0;
  }
  Mem_AllocOrFree_00510e20(1,s_mapbttns_pic_0052dd7c);
  Mem_AllocOrFree_0050fc00();
  for (local_5c = 0; local_5c < 5; local_5c = local_5c + 1) {
    for (local_54 = 0; local_54 < 3; local_54 = local_54 + 1) {
      u_res = Sprite_EncodeFromSurface(1,local_54 * 0x5e + 1,local_5c * 0x1c + 1,0x5d,0x1b);
      (&DAT_00641890)[local_54 + local_5c * 3] = (void *)u_res;
    }
  }
  DAT_0055748c = Sprite_EncodeFromSurface(1,1,0x8d,0x2b,0xe9);
  DAT_00556c50 = Sprite_EncodeFromSurface(1,0x2d,0x8d,0xd1,0x1c);
  DAT_00641878 = Sprite_EncodeFromSurface(1,0xe8,0xaa,0x13,0x117);
  DAT_006498e4 = Sprite_EncodeFromSurface(1,0xfc,0xaa,0xf,0x46);
  FUN_0050fc20();
  if (DAT_0052d8a8 == DAT_0052d898) {
    for (local_54 = 0; local_54 < 5; local_54 = local_54 + 1) {
      u_res = Ai_Util_004c3bc4((&DAT_0052d8a8)[local_54 * 0x15]);
      (&DAT_0052d8a8)[local_54 * 0x15] = u_res;
      u_res = Ai_Util_004c3bc4(*(int *)(&DAT_0052d8ac + local_54 * 0x54));
      *(int *)(&DAT_0052d8ac + local_54 * 0x54) = u_res;
      u_res = Ai_Util_004c3bc4(*(int *)(&DAT_0052d8b0 + local_54 * 0x54));
      *(int *)(&DAT_0052d8b0 + local_54 * 0x54) = u_res;
      u_res = Ai_Util_004c3bc4(*(int *)(&DAT_0052d8b4 + local_54 * 0x54));
      *(int *)(&DAT_0052d8b4 + local_54 * 0x54) = u_res;
    }
  }
  do {
    *(int *)(g_DisplaySurfaceScreen + 0x20) = 1;
    *(int *)g_DisplaySurfaceScreen = 1;
    FUN_0050d560(*(int *)g_DisplaySurfaceScreen,0);
    FUN_00510b70(1,0,g_AiManaColorCost_Green - 0x1e0,s_mapback_pic_0052dd8c,(short *)&DAT_0070a130);
    if (g_AiManaColorCost_Red != 0x1e0) {
      Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,g_AiManaColorCost_Green - 0x1e0,0x280,0x1e0,
                         (int *)g_DisplaySurfaceScreen,0,0,g_AiManaColorCost_Red,g_AiManaColorCost_Green);
    }
    local_a8 = FUN_0041f354();
    Mem_AllocOrFree_0041f12b(local_a8);
    if (arg1 == 0) {
      _DAT_0052d8fc = Ai_Util_004c3bc4(DAT_0052d860);
      _DAT_0052d900 = Ai_Util_004c3bc4(DAT_0052d864);
      FUN_0041f17e(0x52d8ec,1,local_a8);
      _DAT_0052d950 = Ai_Util_004c3bc4(DAT_0052d868);
      _DAT_0052d954 = Ai_Util_004c3bc4(DAT_0052d86c);
      FUN_0041f17e(0x52d940,1,local_a8);
    }
    else if (arg1 == 1) {
      DAT_0052d8a8 = Ai_Util_004c3bc4(DAT_0052d860);
      _DAT_0052d8ac = Ai_Util_004c3bc4(DAT_0052d864);
      FUN_0041f17e(0x52d898,1,local_a8);
      _DAT_0052d8fc = Ai_Util_004c3bc4(DAT_0052d868);
      _DAT_0052d900 = Ai_Util_004c3bc4(DAT_0052d86c);
      FUN_0041f17e(0x52d8ec,1,local_a8);
    }
    else if (arg1 == 2) {
      DAT_0052d8a8 = Ai_Util_004c3bc4(DAT_0052d860);
      _DAT_0052d8ac = Ai_Util_004c3bc4(DAT_0052d864);
      FUN_0041f17e(0x52d898,1,local_a8);
      _DAT_0052d950 = Ai_Util_004c3bc4(DAT_0052d868);
      _DAT_0052d954 = Ai_Util_004c3bc4(DAT_0052d86c);
      FUN_0041f17e(0x52d940,1,local_a8);
    }
    FUN_0041f17e(0x52d994,1,local_a8);
    FUN_0041f17e(0x52d9e8,1,local_a8);
    local_a4[6] = 0;
    for (local_50 = 0; local_50 < 0x40; local_50 = local_50 + 1) {
      for (local_58 = 0; local_58 < 0x40; local_58 = local_58 + 1) {
        local_a4[7] = FUN_0040c7c0(local_50,local_58);
        local_40 = local_a4[7] & 0xf;
        if (((((local_a4[7] & 0x80U) != 0) || (g_CardSlot_ToughnessBonus != 0)) &&
            (Ai_Subsystem_004c3aa1(local_50,local_58,local_28,&local_34),
            local_28[0] <= (int)(g_AiManaColorCost_Red - 8))) &&
           (((7 < local_28[0] && (local_34 <= (int)(g_AiManaColorCost_Green - 8))) && (7 < local_34)))) {
          temp_idx = local_34 + 0x40;
          if ((6 < local_28[0]) && (6 < temp_idx)) {
            val_result = local_34 + 0x3a;
            local_34 = temp_idx;
            Ai_Subsystem_004be3c4
                      (g_DisplaySurfaceScreen,local_28[0] + -6,val_result,
                       *(int *)
                        (&DAT_00678560 +
                        local_40 * 4 +
                        ((*(int *)(&DAT_0052da40 + ((local_58 + local_50) % 6) * 4) *
                         *(int *)(&DAT_0052da40 + ((local_58 * local_50) % 6) * 4)) % 3) * 0x40),0xe
                       ,0xe);
            temp_idx = local_34;
          }
          local_34 = temp_idx;
          local_28[0] = (int)(g_AiManaColorCost_Red * local_28[0]) / 0x280;
          local_34 = (int)((local_34 + -0x40) * g_AiManaColorCost_Green) / 0x1e0;
          temp_idx = Ai_Util_004c3bc4(0x40);
          local_34 = local_34 + temp_idx;
          for (local_54 = 1; local_54 < 9; local_54 = local_54 + 1) {
            temp_idx = FUN_0040cb4f(local_50,local_58,((byte)local_54 & 7) + 1);
            if (temp_idx != 0) {
              iVar11 = 0xd2;
              temp_idx = Ai_Util_004c3bc4(*(int *)(&DAT_005223e0 + local_54 * 4) * 7);
              temp_idx = local_34 + temp_idx;
              val_result = Ai_Util_004c3bc4(*(int *)(&DAT_00522378 + local_54 * 4) * 7);
              Surface_DrawLine((int *)g_DisplaySurfaceScreen,local_28[0],local_34,
                               local_28[0] + val_result,temp_idx,iVar11);
              iVar11 = 0xd2;
              temp_idx = Ai_Util_004c3bc4(*(int *)(&DAT_005223e0 + local_54 * 4) * 7);
              temp_idx = local_34 + temp_idx;
              val_result = Ai_Util_004c3bc4(*(int *)(&DAT_00522378 + local_54 * 4) * 7);
              Surface_DrawLine((int *)g_DisplaySurfaceScreen,local_28[0] + -1,local_34,
                               local_28[0] + -1 + val_result,temp_idx,iVar11);
            }
          }
        }
      }
    }
    for (local_54 = 0; local_54 < 7; local_54 = local_54 + 1) {
      aiStack_84[local_54] = 0;
    }
    local_38 = 0xffffffff;
    if (g_AiCardScoringThreshold != -1) {
      local_38 = Duel_GetCardDrawOriginY
                           ((int)(DAT_0067f360 + (DAT_0067f360 >> 0x1f & 0x1fU)) >> 5,
                            (int)(DAT_0067f364 + (DAT_0067f364 >> 0x1f & 0x1fU)) >> 5);
    }
    for (local_50 = 0; local_50 < 0x40; local_50 = local_50 + 1) {
      for (local_58 = 0; local_58 < 0x40; local_58 = local_58 + 1) {
        local_a4[7] = FUN_0040c7c0(local_50,local_58);
        local_40 = local_a4[7] & 0xf;
        Ai_Subsystem_004c3aa1(local_50,local_58,local_28,&local_34);
        local_28[0] = (int)(g_AiManaColorCost_Red * local_28[0]) / 0x280;
        local_34 = (int)(local_34 * g_AiManaColorCost_Green) / 0x1e0;
        temp_idx = Ai_Util_004c3bc4(0x40);
        local_34 = local_34 + temp_idx;
        if ((((local_28[0] <= (int)(g_AiManaColorCost_Red - 8)) && (-1 < local_28[0])) &&
            (local_34 <= (int)(g_AiManaColorCost_Green - 8))) && (-1 < local_34)) {
          if ((local_a4[7] & 0x10U) != 0) {
            local_30 = Duel_GetCardDrawOriginX(local_50,local_58);
            if ((&DAT_0067be01)[local_30 * 100] != '\0') {
              local_68 = *(int *)(&g_CardSlot_StatusFlags + local_30 * 100) >> 8;
              aiStack_84[*(int *)(&g_CardSlot_StatusFlags + local_30 * 100) >> 8] =
                   aiStack_84[*(int *)(&g_CardSlot_StatusFlags + local_30 * 100) >> 8] + 1;
            }
            if (((arg1 == 0) && (((&g_CardSlot_StatusFlags)[local_30 * 100] & 1) != 0)) &&
               (1 < *(int *)(&g_CardSlot_CreatureType + local_30 * 100))) {
              local_a4[6] = local_a4[6] + 1;
            }
            if (((local_a4[7] & 0x80U) == 0) && (g_CardSlot_ToughnessBonus == 0)) goto LAB_004c2cf3;
            if (*(int *)(&g_CardSlot_CreatureType + local_30 * 100) == 1) {
              local_dc = 0;
            }
            else if ((*(int *)(&g_CardSlot_CreatureType + local_30 * 100) == 4) ||
                    (*(int *)(&g_CardSlot_CreatureType + local_30 * 100) == 5)) {
              local_dc = 2;
            }
            else {
              local_dc = 1;
            }
            temp_idx = *(int *)(&DAT_00677970 + local_dc * 4);
            card_idx = Ai_Util_004c3bc4(0x14);
            iVar5 = Ai_Util_004c3bc4(0xd);
            val_result = local_34;
            iVar6 = Ai_Util_004c3bc4(0x12);
            iVar11 = local_28[0];
            val_result = val_result - iVar6;
            iVar6 = Ai_Util_004c3bc4(7);
            Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,iVar11 - iVar6,val_result,iVar5,card_idx,temp_idx);
            if ((local_30 != 0xffffffff) && (1 < *(int *)(&g_CardSlot_CreatureType + local_30 * 100))) {
              if (((&g_CardSlot_StatusFlags)[local_30 * 100] & 1) == 0) {
                local_3c = 0xe3;
              }
              else {
                local_3c = 0xff;
              }
              if (local_38 == local_30) {
                local_3c = 0xbe;
              }
              if ((&DAT_0067be01)[local_30 * 100] != '\0') {
                local_68 = *(int *)(&g_CardSlot_StatusFlags + local_30 * 100) >> 8;
                local_3c = local_a4[*(int *)(&g_CardSlot_StatusFlags + local_30 * 100) >> 8];
              }
              if (arg1 == 1) {
                local_b0 = 0;
                local_d4[6] = (int)*(short *)(g_AiBackupBoardRegister + 4);
                local_b8 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
                u_res = FUN_0040c761(*(int *)(&DAT_0067bdf4 + local_30 * 100),
                                     *(int *)(&DAT_0067bdf8 + local_30 * 100));
                local_68 = Adventure_GetLocationEncounterIndex(u_res);
                for (local_54 = 1; local_54 < 6; local_54 = local_54 + 1) {
                  if ((local_68 & 1 << ((byte)local_54 & 0x1f)) != 0) {
                    local_b0 = local_b0 + 1;
                  }
                }
                local_ac = (local_28[0] + ((local_b0 + -1) * local_d4[6]) / 2) - local_d4[6] / 2;
                for (local_54 = 1; local_54 < 6; local_54 = local_54 + 1) {
                  local_d4[1] = 2;
                  local_d4[2] = 1;
                  local_d4[3] = 4;
                  local_d4[4] = 3;
                  local_d4[5] = 0;
                  if ((local_68 & 1 << ((byte)local_54 & 0x1f)) != 0) {
                    Sprite_DrawDirect((int *)g_DisplaySurfaceScreen,local_ac,local_34 + 0xc,
                                      (&g_AiBackupBoardRegister)[local_d4[local_54]]);
                    local_ac = local_ac - local_d4[6];
                  }
                }
                if ((&DAT_0067bdfc)[local_30 * 100] == '\0') {
                  g_OverworldWorldState = 0;
                  FUN_00484c45(1 << ((char)((uint)*(int *)(&DAT_0067bdfc + local_30 * 100) >>
                                           8) - 1U & 0x1f));
                  strcat(&g_OverworldWorldState,&DAT_0052dda0);
                }
                else {
                  local_68 = FUN_00473cc5((byte)*(int *)(&DAT_0067bdfc + local_30 * 100));
                  pcVar7 = (char *)Mem_AllocOrFree_00473d7e(local_68);
                  strcpy(&g_OverworldWorldState,pcVar7);
                  strcat(&g_OverworldWorldState,s_cards_0052dd98);
                }
                local_b4 = FUN_0050f440((int *)g_DisplaySurfaceScreen,&g_OverworldWorldState);
                uVar10 = (uint)(local_4c == 0);
                uVar9 = 0x3f3f3f;
                temp_idx = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
                Ai_Subsystem_004c2340
                          ((int *)g_DisplaySurfaceScreen,(local_28[0] + -2) - local_b4 / 2,
                           local_34 + -2,local_b4 + 4,temp_idx + 2,uVar9,uVar10);
                local_4c = 1;
                FUN_0040c421(&g_OverworldWorldState,local_28[0],local_34,local_3c);
                for (local_54 = 0; local_54 < 0xc; local_54 = local_54 + 1) {
                  if ((local_30 != 0) && (*(uint *)(&DAT_005224e8 + local_54 * 0x10) == local_30)) {
                    local_60 = Bazaar_GetCardBaseValue(local_54);
                    strcpy(&g_OverworldWorldState,(&PTR_s_Sleight_of_hand_005225d0)[local_54]);
                    local_b4 = FUN_0050f440((int *)g_DisplaySurfaceScreen,&g_OverworldWorldState);
                    uVar10 = (uint)(local_4c == 0);
                    uVar9 = 0x3f3f3f;
                    temp_idx = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
                    Ai_Subsystem_004c2340
                              ((int *)g_DisplaySurfaceScreen,
                               (local_28[0] + -2) - local_b4 / 2,local_34 + local_b8,local_b4 + 4,
                               temp_idx + 2,uVar9,uVar10);
                    FUN_0040c421(&g_OverworldWorldState,local_28[0],local_34 + local_b8,local_3c);
                  }
                }
              }
              if ((arg1 == 0) || ((arg1 == 1 && (*(int *)(&g_CardSlot_CreatureType + local_30 * 100) == 4))))
              {
                temp_idx = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
                g_OverworldWorldState = 0;
                if ((*(int *)(&g_CardSlot_CreatureType + local_30 * 100) == 4) ||
                   (*(int *)(&g_CardSlot_CreatureType + local_30 * 100) == 5)) {
                  u_res = FUN_0040c761(local_50,local_58);
                  arg_1_00 = Adventure_GetLocationEncounterIndex(u_res);
                  val_result = FUN_00473cc5(arg_1_00);
                  pcVar7 = (char *)Mem_AllocOrFree_00473d7e(val_result);
                  strcpy(&g_OverworldWorldState,pcVar7);
                }
                else {
                  val_result = local_30 + ((int)local_30 >> 0x1f & 7U);
                  uVar10 = val_result >> 0x1f;
                  strcpy(&g_OverworldWorldState,
                         (&PTR_s_Amanaxis_00522460)
                         [((val_result >> 3 ^ uVar10) - uVar10 & 0xf ^ uVar10) - uVar10]);
                }
                sVar8 = strlen(&g_OverworldWorldState);
                if ((&DAT_0062684f)[sVar8] == ' ') {
                  sVar8 = strlen(&g_OverworldWorldState);
                  (&DAT_0062684f)[sVar8] = 0;
                }
                local_d4[0] = FUN_0050f440((int *)g_DisplaySurfaceScreen,&g_OverworldWorldState);
                uVar10 = (uint)(local_4c == 0);
                uVar9 = 0x4f4f4f;
                val_result = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
                Ai_Subsystem_004c2340
                          ((int *)g_DisplaySurfaceScreen,(local_28[0] + -2) - local_d4[0] / 2
                           ,local_34 + -2,local_d4[0] + 4,val_result + 2,uVar9,uVar10);
                local_4c = 1;
                FUN_0040c421(&g_OverworldWorldState,local_28[0],local_34,local_3c);
                g_OverworldWorldState = 0;
                if ((*(int *)(&g_CardSlot_CreatureType + local_30 * 100) == 4) ||
                   (*(int *)(&g_CardSlot_CreatureType + local_30 * 100) == 5)) {
                  strcpy(&g_OverworldWorldState,s_Castle_0052dda4);
                }
                else {
                  uVar10 = (int)local_30 >> 0x1f;
                  strcpy(&g_OverworldWorldState,
                         (&PTR_s_Tower_005224a0)
                         [((local_30 ^ uVar10) - uVar10 & 0xf ^ uVar10) - uVar10]);
                }
                local_d4[0] = FUN_0050f440((int *)g_DisplaySurfaceScreen,&g_OverworldWorldState);
                iVar11 = 0;
                uVar10 = 0x4f4f4f;
                val_result = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
                Ai_Subsystem_004c2340
                          ((int *)g_DisplaySurfaceScreen,(local_28[0] + -2) - local_d4[0] / 2
                           ,temp_idx + local_34,local_d4[0] + 4,val_result,uVar10,iVar11);
                FUN_0040c421(&g_OverworldWorldState,local_28[0],temp_idx + local_34,local_3c);
              }
            }
          }
          if ((g_CardSlot_ToughnessBonus != 0) && ((local_a4[7] & 0x40U) != 0)) {
            Surface_FillRect((int *)g_DisplaySurfaceScreen,local_28[0] + 1,local_34 + 1,2,2,0xf6);
          }
        }
LAB_004c2cf3:
      }
    }
    temp_idx = DAT_00556c50;
    val_result = Ai_Util_004c3bc4((int)*(short *)(DAT_00556c50 + 6));
    iVar11 = Ai_Util_004c3bc4((int)*(short *)(DAT_00556c50 + 4));
    card_idx = Ai_Util_004c3bc4(0x36);
    iVar5 = Ai_Util_004c3bc4(0xdc);
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,iVar5,card_idx,iVar11,val_result,temp_idx);
    if (local_64 != 4) {
      temp_idx = DAT_0055748c;
      val_result = Ai_Util_004c3bc4((int)*(short *)(DAT_0055748c + 6));
      iVar11 = Ai_Util_004c3bc4((int)*(short *)(DAT_0055748c + 4));
      card_idx = Ai_Util_004c3bc4(0x85);
      iVar5 = Ai_Util_004c3bc4(0);
      Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,iVar5,card_idx,iVar11,val_result,temp_idx);
      for (local_54 = 0; local_54 < 5; local_54 = local_54 + 1) {
        FUN_0040d4d1((int)g_DisplaySurfaceScreen,0xfe,0x18,local_54 * 0x1a + 0xc6);
      }
    }
    *(int *)g_DisplaySurfaceScreen = 0;
    FUN_0050dce0((int *)g_DisplaySurfaceBackBuffer,0,0,g_AiManaColorCost_Red,g_AiManaColorCost_Green,
                 (int *)g_DisplaySurfaceScreen,0,0);
    if (local_64 == 4) {
      FUN_0041f391();
      return;
    }
    FUN_0041f213();
    Ai_Subsystem_004c3aa1(DAT_00641010,DAT_00641014,local_28,&local_34);
    local_28[0] = (int)(g_AiManaColorCost_Red * local_28[0]) / 0x280;
    temp_idx = Ai_Util_004c3bc4(0x40);
    local_34 = temp_idx + (int)(local_34 * g_AiManaColorCost_Green) / 0x1e0;
    g_AiHeuristicWeight_Lifelink = -1;
    local_2c = 1;
    Mem_AllocOrFree_005016f9();
    local_48 = -1;
    local_44 = -1;
    do {
      temp_idx = Mem_AllocOrFree_00501721();
      if ((temp_idx % 0x14 < 10) && (local_2c != 0)) {
        Surface_FillRect((int *)g_DisplaySurfaceScreen,local_28[0] + -1,local_34 + -1,4,4,0xff);
        local_2c = 0;
      }
      else {
        temp_idx = Mem_AllocOrFree_00501721();
        if ((9 < temp_idx % 0x14) && (local_2c == 0)) {
          Surface_FillRect((int *)g_DisplaySurfaceScreen,local_28[0] + -1,local_34 + -1,4,4,0);
          local_2c = 1;
        }
      }
      Pic_Subsystem_0044b84b();
      if (DAT_007039c4 == 0) {
        FUN_0041f3ea(DAT_0067bda4,DAT_0067bda8,0);
      }
      else {
        FUN_0041f3ea(DAT_0067bda4,DAT_0067bda8,DAT_007039c4);
        if (((DAT_007039c4 != 0) && (g_CardSlot_ToughnessBonus != 0)) && (g_AiHeuristicWeight_Lifelink < 0)) {
          FUN_0050dce0((int *)g_DisplaySurfaceBackBuffer,local_28[0] - 1,local_34 + -1,4,4,
                       (int *)g_DisplaySurfaceScreen,local_28[0] + -1,local_34 + -1);
          temp_idx = DAT_0067bda8;
          local_28[0] = DAT_0067bda4;
          local_48 = DAT_0067bda8;
          local_34 = DAT_0067bda8;
          local_44 = (DAT_0067bda4 * 0x280) / (int)g_AiManaColorCost_Red;
          val_result = Ai_Util_004c3bc4(0x40);
          local_48 = ((temp_idx - val_result) * 0x1e0) / (int)g_AiManaColorCost_Green;
          Ai_Subsystem_004c3ad4(local_44,local_48,&DAT_00641010,&DAT_00641014);
          DAT_0052eff0 = DAT_00641010 * 0x20 + 0x10;
          DAT_0052eff4 = DAT_00641014 * 0x20 + 0x10;
          Ai_Subsystem_004c3aa1(DAT_00641010,DAT_00641014,local_28,&local_34);
          local_28[0] = (int)(g_AiManaColorCost_Red * local_28[0]) / 0x280;
          temp_idx = Ai_Util_004c3bc4(0x40);
          local_34 = temp_idx + (int)(local_34 * g_AiManaColorCost_Green) / 0x1e0;
          DAT_00641884 = 0;
        }
      }
    } while (g_AiHeuristicWeight_Lifelink == -1);
    if (g_AiHeuristicWeight_Lifelink == 3) {
      FUN_0040a3e1();
      Town_Process_00490d7b(1);
      arg1 = 0;
      FUN_0041f391();
    }
    else {
      if (g_AiHeuristicWeight_Lifelink == 4) {
        FUN_0041f391();
        Mem_AllocOrFree_0050fc50(DAT_00641890);
        FUN_0040a3e1();
        return;
      }
      arg1 = g_AiHeuristicWeight_Lifelink;
      FUN_0040a3e1();
      FUN_0041f391();
    }
  } while( true );
}

/*
 * Ai_Subsystem_004c3aa1
 * Purpose: Tactical AI engine subsystem routine (004c3aa1).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004c3aa1
 * Entry Point: 004c3aa1
 * Size: 51 bytes
 */

void Ai_Subsystem_004c3aa1(int x, int y, int * width, int * height)

{
  *width = (y + x) * 6 + -0x40;
  *height = (y - x) * 6 + 200;
  return;
}

/*
 * Ai_Subsystem_004c3ad4
 * Purpose: Tactical AI engine subsystem routine (004c3ad4).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004c3ad4
 * Entry Point: 004c3ad4
 * Size: 69 bytes
 */

void Ai_Subsystem_004c3ad4(int x, int y, int * width, int * height)

{
  *width = ((x + 0x40) - (y + -200)) / 0xc;
  *height = *width + (y + -200) / 6;
  return;
}

/*
 * Ai_Subsystem_004c3b19
 * Purpose: Tactical AI engine subsystem routine (004c3b19).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004c3b19
 * Entry Point: 004c3b19
 * Size: 138 bytes
 */

void Ai_Subsystem_004c3b19(uint arg1)

{
  int status;
  uint u_temp;
  uint u_score;
  
  u_temp = (int)arg1 >> 0x1f;
  status = arg1 + (u_temp & 7);
  u_score = status >> 0x1f;
  strcat(&g_OverworldWorldState,
         (&PTR_s_Amanaxis_00522460)[((status >> 3 ^ u_score) - u_score & 0xf ^ u_score) - u_score]);
  if (*(int *)(&g_CardSlot_CreatureType + arg1 * 100) == 1) {
    strcat(&g_OverworldWorldState,s_Village_0052ddb0);
  }
  else {
    strcat(&g_OverworldWorldState,
           (&PTR_s_Tower_005224a0)[((arg1 ^ u_temp) - u_temp & 0xf ^ u_temp) - u_temp]);
  }
  return;
}

/*
 * Ai_Util_004c3ba3
 * Purpose: Tactical AI utility helper function (004c3ba3).
 * Procedure:
 * 1. Execute internal state operation.
 */
/*
 * Decompiled function: Ai_Util_004c3ba3
 * Entry Point: 004c3ba3
 * Size: 33 bytes
 */

int Ai_Util_004c3ba3(int arg1)

{
  return (g_AiManaColorCost_Red * arg1) / 0x140;
}

/*
 * Ai_Util_004c3bc4
 * Purpose: Tactical AI utility helper function (004c3bc4).
 * Procedure:
 * 1. Execute internal state operation.
 */
/*
 * Decompiled function: Ai_Util_004c3bc4
 * Entry Point: 004c3bc4
 * Size: 33 bytes
 */

int Ai_Util_004c3bc4(int arg1)

{
  return (g_AiManaColorCost_Red * arg1) / 0x280;
}

/*
 * Ai_Subsystem_004c3be5
 * Purpose: Tactical AI engine subsystem routine (004c3be5).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004c3be5
 * Entry Point: 004c3be5
 * Size: 119 bytes
 */

int Ai_Subsystem_004c3be5(int arg1, int arg2)

{
  int u_res;
  
  if ((arg1 < g_AiLookaheadDelta) || ((8 << (DAT_006498e0 & 0x1f)) + g_AiLookaheadDelta <= arg1)) {
    u_res = 0;
  }
  else if ((arg2 < g_AiLookaheadBestMove) || ((6 << (DAT_006498e0 & 0x1f)) + g_AiLookaheadBestMove <= arg2)) {
    u_res = 0;
  }
  else {
    u_res = 1;
  }
  return u_res;
}

/*
 * Ai_Subsystem_004c3c5c
 * Purpose: Tactical AI engine subsystem routine (004c3c5c).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004c3c5c
 * Entry Point: 004c3c5c
 * Size: 1459 bytes
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Ai_Subsystem_004c3c5c(int arg1)

{
  DWORD DVar1;
  uint u_temp;
  int temp_idx;
  uint arg2;
  int *piVar4;
  int iVar5;
  int arg_8;
  uint local_20;
  
  *(int *)(g_DisplaySurfaceScreen + 0x20) = 4;
  *(int *)(g_DisplaySurfaceBackBuffer + 0x20) = 4;
  arg_8 = 0;
  iVar5 = 0;
  piVar4 = (int *)g_DisplaySurfaceBackBuffer;
  DVar1 = Ai_Util_004c3bc4(0x15);
  u_temp = Ai_Util_004c3bc4(0x126);
  temp_idx = Ai_Util_004c3bc4(0x13);
  arg2 = Ai_Util_004c3bc4(0x58);
  FUN_0050dce0((int *)PTR_DAT_005174bc,arg2,temp_idx,u_temp,DVar1,piVar4,iVar5,arg_8);
  temp_idx = Ai_Util_004c3bc4(10);
  iVar5 = Ai_Util_004c3bc4(0x12);
  FUN_0040d269((int)g_DisplaySurfaceBackBuffer,g_AiHeuristicWeight_HandAdvantage,iVar5,temp_idx);
  temp_idx = Ai_Util_004c3bc4(10);
  iVar5 = Ai_Util_004c3bc4(0x60);
  FUN_0040d269((int)g_DisplaySurfaceBackBuffer,g_AiHeuristicWeight_HandAdvantage,iVar5,temp_idx);
  Minit_Subsystem_00452827();
  temp_idx = Ai_Util_004c3bc4(10);
  iVar5 = Ai_Util_004c3bc4(0xab);
  FUN_0040d269((int)g_DisplaySurfaceBackBuffer,g_AiHeuristicWeight_HandAdvantage,iVar5,temp_idx);
  temp_idx = Ai_Util_004c3bc4(10);
  iVar5 = Ai_Util_004c3bc4(0x10c);
  FUN_0040d269((int)g_DisplaySurfaceBackBuffer,g_AiHeuristicWeight_HandAdvantage,iVar5,temp_idx);
  temp_idx = Ai_Util_004c3bc4(0x15b);
  iVar5 = Ai_Util_004c3bc4(0x58);
  piVar4 = (int *)g_DisplaySurfaceScreen;
  DVar1 = Ai_Util_004c3bc4(0x15);
  u_temp = Ai_Util_004c3bc4(0x126);
  FUN_0050dce0((int *)g_DisplaySurfaceBackBuffer,0,0,u_temp,DVar1,piVar4,iVar5,temp_idx);
  *(int *)(g_DisplaySurfaceScreen + 0x20) = 2;
  Ai_CalcMana_004bf4b3(1);
  temp_idx = g_AiBackupBoardRegister;
  if ((DAT_0052d778 == 0) && (arg1 == 0)) {
    Pic_Subsystem_0044b8aa();
  }
  else {
    *(int *)(g_DisplaySurfaceScreen + 0x20) = 4;
    iVar5 = 400 - (int)*(short *)(temp_idx + 6) / 2;
    Ai_Subsystem_004be3c4
              (g_DisplaySurfaceScreen,0x4e,iVar5,DAT_006776a8,(int)*(short *)(temp_idx + 4),
               (int)*(short *)(temp_idx + 6));
    FUN_0040d4d1((int)g_DisplaySurfaceScreen,g_AiHeuristicWeight_HandAdvantage,100,iVar5 + (int)*(short *)(temp_idx + 6) / 2
                );
    Ai_Subsystem_004be3c4
              (g_DisplaySurfaceScreen,0xa1,iVar5,DAT_006776a4,(int)*(short *)(temp_idx + 4),
               (int)*(short *)(temp_idx + 6));
    FUN_0040d4d1((int)g_DisplaySurfaceScreen,g_AiHeuristicWeight_HandAdvantage,0xb7,
                 iVar5 + (int)*(short *)(temp_idx + 6) / 2);
    Ai_Subsystem_004be3c4
              (g_DisplaySurfaceScreen,0xf0,iVar5,DAT_006776b0,(int)*(short *)(temp_idx + 4),
               (int)*(short *)(temp_idx + 6));
    FUN_0040d4d1((int)g_DisplaySurfaceScreen,g_AiHeuristicWeight_HandAdvantage,0x106,
                 iVar5 + (int)*(short *)(temp_idx + 6) / 2);
    Ai_Subsystem_004be3c4
              (g_DisplaySurfaceScreen,0x140,iVar5,DAT_006776ac,(int)*(short *)(temp_idx + 4),
               (int)*(short *)(temp_idx + 6));
    FUN_0040d4d1((int)g_DisplaySurfaceScreen,g_AiHeuristicWeight_HandAdvantage,0x156,
                 iVar5 + (int)*(short *)(temp_idx + 6) / 2);
    Ai_Subsystem_004be3c4
              (g_DisplaySurfaceScreen,0x193,iVar5,g_AiBackupBoardRegister,(int)*(short *)(temp_idx + 4),
               (int)*(short *)(temp_idx + 6));
    FUN_0040d4d1((int)g_DisplaySurfaceScreen,g_AiHeuristicWeight_HandAdvantage,0x1a9,
                 iVar5 + (int)*(short *)(temp_idx + 6) / 2);
    for (local_20 = 0; (int)local_20 < 0xc; local_20 = local_20 + 1) {
      if ((_DAT_0067f374 & 1 << ((byte)local_20 & 0x1f)) != 0) {
        Bazaar_GetCardBaseValue(local_20);
        if (((int)local_20 < 2) || ((local_20 & 1) != 0)) {
          Ai_Subsystem_004be3c4
                    (g_DisplaySurfaceScreen,*(int *)(&DAT_0052da58 + local_20 * 0x10),
                     *(int *)(&DAT_0052da5c + local_20 * 0x10),
                     *(int *)(&DAT_006782a0 + local_20 * 4),
                     *(int *)(&DAT_0052da60 + local_20 * 0x10),
                     *(int *)(&DAT_0052da64 + local_20 * 0x10));
        }
        else if (*(int *)(&DAT_0067bdbc + ((int)local_20 / 2) * 4) == 0) {
          Ai_Subsystem_004be3c4
                    (g_DisplaySurfaceScreen,*(int *)(&DAT_0052da58 + local_20 * 0x10),
                     *(int *)(&DAT_0052da5c + local_20 * 0x10),
                     *(int *)(&DAT_00678300 + local_20 * 4),
                     *(int *)(&DAT_0052da60 + local_20 * 0x10),
                     *(int *)(&DAT_0052da64 + local_20 * 0x10));
        }
        else {
          Ai_Subsystem_004be3c4
                    (g_DisplaySurfaceScreen,*(int *)(&DAT_0052da58 + local_20 * 0x10),
                     *(int *)(&DAT_0052da5c + local_20 * 0x10),
                     *(int *)(&DAT_006782a0 + local_20 * 4),
                     *(int *)(&DAT_0052da60 + local_20 * 0x10),
                     *(int *)(&DAT_0052da64 + local_20 * 0x10));
          Ai_Subsystem_004be3c4
                    (g_DisplaySurfaceScreen,*(int *)(&DAT_0052da58 + local_20 * 0x10),
                     *(int *)(&DAT_0052da5c + local_20 * 0x10),
                     *(int *)(&DAT_00678330 + local_20 * 4),
                     *(int *)(&DAT_0052da60 + local_20 * 0x10),
                     *(int *)(&DAT_0052da64 + local_20 * 0x10));
        }
      }
    }
    *(int *)(g_DisplaySurfaceScreen + 0x20) = 1;
  }
  return;
}

/*
 * Ai_Subsystem_004c4210
 * Purpose: Tactical AI engine subsystem routine (004c4210).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004c4210
 * Entry Point: 004c4210
 * Size: 2676 bytes
 */

void Ai_Subsystem_004c4210(int arg1)

{
  int status;
  int u_temp;
  int arg_1_00;
  int temp_idx;
  int card_idx;
  uint u_extra;
  int iVar6;
  int local_14;
  
  arg_1_00 = 1 - arg1;
  memset(&g_AiBestScore,0,0x780);
  for (local_14 = 0; local_14 < (int)(&g_PlayerActiveCardCount)[arg1]; local_14 = local_14 + 1) {
    if ((*(int *)(&g_CardSlot_CardId + local_14 * 0x120 + arg1 * 0x5b20) != -1) &&
       (((&g_CardSlot_Flags)[local_14 * 0x120 + arg1 * 0x5b20] & 2) != 0)) {
      iVar6 = *(int *)(&g_CardSlot_CardId + local_14 * 0x120 + arg1 * 0x5b20);
      temp_idx = (int)(char)(&g_CardSlot_Toughness)[local_14 * 0x120 + arg1 * 0x5b20];
      status = *(int *)(&g_CardSlot_OriginalCardId + local_14 * 0x120 + arg1 * 0x5b20);
      if ((*(code **)(&g_MasterCardManaCostTable + iVar6 * 0x34) == Pic_Subsystem_0043ebbf) &&
         (card_idx = FUN_0040d949(temp_idx,3,1), card_idx != 0)) {
        *(uint *)(&g_AiBestTargetPlayer + status * 0xc + temp_idx * 0x3c0) =
             *(uint *)(&g_AiBestTargetPlayer + status * 0xc + temp_idx * 0x3c0) | 0x200;
        *(uint *)(&g_CardSlot_Abilities2 + status * 0x120 + temp_idx * 0x5b20) =
             *(uint *)(&g_CardSlot_Abilities2 + status * 0x120 + temp_idx * 0x5b20) | 0x200;
      }
      else if ((*(code **)(&g_MasterCardManaCostTable + iVar6 * 0x34) == Pic_Subsystem_0043f51d) &&
              (card_idx = FUN_0040d949(temp_idx,4,3), card_idx != 0)) {
        *(uint *)(&g_AiBestTargetPlayer + status * 0xc + temp_idx * 0x3c0) =
             *(uint *)(&g_AiBestTargetPlayer + status * 0xc + temp_idx * 0x3c0) | 0x200;
        *(uint *)(&g_CardSlot_Abilities2 + status * 0x120 + temp_idx * 0x5b20) =
             *(uint *)(&g_CardSlot_Abilities2 + status * 0x120 + temp_idx * 0x5b20) | 0x200;
      }
      if (*(code **)(&g_MasterCardManaCostTable + iVar6 * 0x34) == Pic_Subsystem_00435abf) {
        card_idx = FUN_0040d949(temp_idx,5,1);
        *(int *)(&g_AiBestCardIndex + status * 0xc + temp_idx * 0x3c0) =
             *(int *)(&g_AiBestCardIndex + status * 0xc + temp_idx * 0x3c0) + card_idx;
      }
      else if (*(code **)(&g_MasterCardManaCostTable + iVar6 * 0x34) == Pic_Subsystem_00436f60) {
        card_idx = FUN_0040d949(temp_idx,4,1);
        *(int *)(&g_AiBestScore + status * 0xc + temp_idx * 0x3c0) =
             *(int *)(&g_AiBestScore + status * 0xc + temp_idx * 0x3c0) + card_idx;
      }
      else if (*(code **)(&g_MasterCardManaCostTable + iVar6 * 0x34) == Pic_Subsystem_00436500) {
        card_idx = FUN_0040d949(temp_idx,5,1);
        *(int *)(&g_AiBestScore + status * 0xc + temp_idx * 0x3c0) =
             *(int *)(&g_AiBestScore + status * 0xc + temp_idx * 0x3c0) + card_idx;
        card_idx = FUN_0040d949(temp_idx,5,1);
        *(int *)(&g_AiBestCardIndex + status * 0xc + temp_idx * 0x3c0) =
             *(int *)(&g_AiBestCardIndex + status * 0xc + temp_idx * 0x3c0) + card_idx;
      }
      *(uint *)(&g_CardSlot_Abilities2 + local_14 * 0x120 + arg1 * 0x5b20) =
           *(uint *)(&g_CardSlot_Abilities2 + local_14 * 0x120 + arg1 * 0x5b20) | 0xe000000;
      u_temp = *(int *)(&g_CardSlot_Flags + local_14 * 0x120 + arg1 * 0x5b20);
      if (g_ActivePlayerPriority == arg1) {
        if (((&g_CardSlot_StateByte)[local_14 * 0x120 + arg1 * 0x5b20] & 0x20) == 0) {
          *(uint *)(&g_CardSlot_Flags + local_14 * 0x120 + arg1 * 0x5b20) =
               *(uint *)(&g_CardSlot_Flags + local_14 * 0x120 + arg1 * 0x5b20) | 0x14;
        }
        else {
          *(uint *)(&g_CardSlot_Flags + local_14 * 0x120 + arg1 * 0x5b20) =
               *(uint *)(&g_CardSlot_Flags + local_14 * 0x120 + arg1 * 0x5b20) | 4;
        }
      }
      DAT_006b2e18 = FUN_00473179(arg1,local_14,0x32,0xffffffff);
      DAT_00700eb4 = FUN_00473179(arg1,local_14,0x33,0xffffffff);
      g_AiAttackingCreatureCount = FUN_00473179(arg1,local_14,0x34,0xffffffff);
      u_extra = FUN_00473cc5((&DAT_0051aebe)[iVar6 * 0x34]);
      if (((g_AiAttackingCreatureCount & 0x200) != 0) && (iVar6 = FUN_0040d949(arg1,u_extra,1), iVar6 == 0)) {
        g_AiAttackingCreatureCount = g_AiAttackingCreatureCount & 0xfffffdff;
      }
      if (g_CurrentTurnPhase == arg1) {
        FUN_00473e69(arg1,local_14,0x8c);
      }
      *(int *)(&g_AiBestScore + local_14 * 0xc + arg1 * 0x3c0) =
           *(int *)(&g_AiBestScore + local_14 * 0xc + arg1 * 0x3c0) + DAT_006b2e18;
      *(int *)(&g_AiBestCardIndex + local_14 * 0xc + arg1 * 0x3c0) =
           *(int *)(&g_AiBestCardIndex + local_14 * 0xc + arg1 * 0x3c0) + DAT_00700eb4;
      *(uint *)(&g_AiBestTargetPlayer + local_14 * 0xc + arg1 * 0x3c0) =
           *(uint *)(&g_AiBestTargetPlayer + local_14 * 0xc + arg1 * 0x3c0) | g_AiAttackingCreatureCount;
      *(int *)(&g_CardSlot_Flags + local_14 * 0x120 + arg1 * 0x5b20) = u_temp;
    }
  }
  g_AiDecisionTreeDepth = 0;
  for (local_14 = 0; local_14 < (int)(&g_PlayerActiveCardCount)[arg_1_00]; local_14 = local_14 + 1)
  {
    if ((*(int *)(&g_CardSlot_CardId + local_14 * 0x120 + arg_1_00 * 0x5b20) != -1) &&
       (((&g_CardSlot_Flags)[local_14 * 0x120 + arg_1_00 * 0x5b20] & 2) != 0)) {
      iVar6 = *(int *)(&g_CardSlot_CardId + local_14 * 0x120 + arg_1_00 * 0x5b20);
      temp_idx = (int)(char)(&g_CardSlot_Toughness)[local_14 * 0x120 + arg_1_00 * 0x5b20];
      status = *(int *)(&g_CardSlot_OriginalCardId + local_14 * 0x120 + arg_1_00 * 0x5b20);
      if ((*(code **)(&g_MasterCardManaCostTable + iVar6 * 0x34) == Pic_Subsystem_0043ebbf) &&
         (card_idx = FUN_0040d949(temp_idx,3,1), card_idx != 0)) {
        *(uint *)(&g_AiBestTargetPlayer + status * 0xc + temp_idx * 0x3c0) =
             *(uint *)(&g_AiBestTargetPlayer + status * 0xc + temp_idx * 0x3c0) | 0x200;
        *(uint *)(&g_CardSlot_Abilities2 + status * 0x120 + temp_idx * 0x5b20) =
             *(uint *)(&g_CardSlot_Abilities2 + status * 0x120 + temp_idx * 0x5b20) | 0x200;
      }
      else if ((*(code **)(&g_MasterCardManaCostTable + iVar6 * 0x34) == Pic_Subsystem_0043f51d) &&
              (card_idx = FUN_0040d949(temp_idx,4,3), card_idx != 0)) {
        *(uint *)(&g_AiBestTargetPlayer + status * 0xc + temp_idx * 0x3c0) =
             *(uint *)(&g_AiBestTargetPlayer + status * 0xc + temp_idx * 0x3c0) | 0x200;
        *(uint *)(&g_CardSlot_Abilities2 + status * 0x120 + temp_idx * 0x5b20) =
             *(uint *)(&g_CardSlot_Abilities2 + status * 0x120 + temp_idx * 0x5b20) | 0x200;
      }
      if (*(code **)(&g_MasterCardManaCostTable + iVar6 * 0x34) == Pic_Subsystem_00435abf) {
        card_idx = FUN_0040d949(temp_idx,5,1);
        *(int *)(&g_AiBestCardIndex + status * 0xc + temp_idx * 0x3c0) =
             *(int *)(&g_AiBestCardIndex + status * 0xc + temp_idx * 0x3c0) + card_idx;
      }
      else if (*(code **)(&g_MasterCardManaCostTable + iVar6 * 0x34) == Pic_Subsystem_00436f60) {
        card_idx = FUN_0040d949(temp_idx,4,1);
        *(int *)(&g_AiBestScore + status * 0xc + temp_idx * 0x3c0) =
             *(int *)(&g_AiBestScore + status * 0xc + temp_idx * 0x3c0) + card_idx;
      }
      else if (*(code **)(&g_MasterCardManaCostTable + iVar6 * 0x34) == Pic_Subsystem_00436500) {
        card_idx = FUN_0040d949(temp_idx,5,1);
        *(int *)(&g_AiBestScore + status * 0xc + temp_idx * 0x3c0) =
             *(int *)(&g_AiBestScore + status * 0xc + temp_idx * 0x3c0) + card_idx;
        card_idx = FUN_0040d949(temp_idx,5,1);
        *(int *)(&g_AiBestCardIndex + status * 0xc + temp_idx * 0x3c0) =
             *(int *)(&g_AiBestCardIndex + status * 0xc + temp_idx * 0x3c0) + card_idx;
      }
      *(uint *)(&g_CardSlot_Abilities2 + local_14 * 0x120 + arg_1_00 * 0x5b20) =
           *(uint *)(&g_CardSlot_Abilities2 + local_14 * 0x120 + arg_1_00 * 0x5b20) | 0xe000000;
      u_temp = *(int *)(&g_CardSlot_Flags + local_14 * 0x120 + arg_1_00 * 0x5b20);
      *(uint *)(&g_CardSlot_Flags + local_14 * 0x120 + arg_1_00 * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + local_14 * 0x120 + arg_1_00 * 0x5b20) | 8;
      DAT_006b2e18 = FUN_00473179(arg_1_00,local_14,0x32,0xffffffff);
      DAT_00700eb4 = FUN_00473179(arg_1_00,local_14,0x33,0xffffffff);
      g_AiAttackingCreatureCount = FUN_00473179(arg_1_00,local_14,0x34,0xffffffff);
      u_extra = FUN_00473cc5((&DAT_0051aebe)[iVar6 * 0x34]);
      if (((g_AiAttackingCreatureCount & 0x200) != 0) && (iVar6 = FUN_0040d949(arg_1_00,u_extra,1), iVar6 == 0)) {
        g_AiAttackingCreatureCount = g_AiAttackingCreatureCount & 0xfffffdff;
      }
      if (g_CurrentTurnPhase == arg_1_00) {
        FUN_00473e69(arg_1_00,local_14,0x8c);
      }
      *(int *)(&g_AiBestScore + local_14 * 0xc + arg_1_00 * 0x3c0) =
           *(int *)(&g_AiBestScore + local_14 * 0xc + arg_1_00 * 0x3c0) + DAT_006b2e18;
      *(int *)(&g_AiBestCardIndex + local_14 * 0xc + arg_1_00 * 0x3c0) =
           *(int *)(&g_AiBestCardIndex + local_14 * 0xc + arg_1_00 * 0x3c0) + DAT_00700eb4;
      *(uint *)(&g_AiBestTargetPlayer + local_14 * 0xc + arg_1_00 * 0x3c0) =
           *(uint *)(&g_AiBestTargetPlayer + local_14 * 0xc + arg_1_00 * 0x3c0) | g_AiAttackingCreatureCount;
      *(int *)(&g_CardSlot_Flags + local_14 * 0x120 + arg_1_00 * 0x5b20) = u_temp;
      iVar6 = *(int *)(&g_CardSlot_CardId + local_14 * 0x120 + arg_1_00 * 0x5b20);
      if (*(code **)(&g_MasterCardManaCostTable + iVar6 * 0x34) == Pic_Subsystem_0043fd7b) {
        g_AiDecisionTreeDepth = g_AiDecisionTreeDepth | 2;
      }
      if (*(code **)(&g_MasterCardManaCostTable + iVar6 * 0x34) == Pic_Subsystem_0043fe20) {
        g_AiDecisionTreeDepth = g_AiDecisionTreeDepth | 4;
      }
      if (*(code **)(&g_MasterCardManaCostTable + iVar6 * 0x34) == Pic_Subsystem_0043fe57) {
        g_AiDecisionTreeDepth = g_AiDecisionTreeDepth | 8;
      }
      if (*(code **)(&g_MasterCardManaCostTable + iVar6 * 0x34) == Pic_Subsystem_0043fde9) {
        g_AiDecisionTreeDepth = g_AiDecisionTreeDepth | 0x10;
      }
      if (*(code **)(&g_MasterCardManaCostTable + iVar6 * 0x34) == Pic_Subsystem_0043fdb2) {
        g_AiDecisionTreeDepth = g_AiDecisionTreeDepth | 0x20;
      }
    }
  }
  if (g_AiDecisionTreeDepth == 0) {
    DAT_00641874 = 0;
  }
  else {
    DAT_00641874 = FUN_0040d949(arg_1_00,7,0);
  }
  FUN_00472fae();
  return;
}

/*
 * Ai_Subsystem_004c4c84
 * Purpose: Tactical AI engine subsystem routine (004c4c84).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004c4c84
 * Entry Point: 004c4c84
 * Size: 4933 bytes
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Ai_Subsystem_004c4c84(int arg1)

{
  int status;
  int val_result;
  int temp_idx;
  uint u_val;
  int aiStack_cc [16];
  uint local_8c;
  int local_88;
  int local_84;
  uint local_80;
  int local_7c;
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  int aiStack_58 [16];
  uint local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  g_AiCreatureToughnessEval = 1 - arg1;
  if (DAT_00559b18 == 0) {
    Ai_FilterValidBlockers(&local_8,&local_18);
    if (g_AiCreatureToughnessEval == 1) {
      DAT_0055a094 = local_8;
    }
    else {
      DAT_0055a094 = local_18;
    }
    DAT_0055a090 = 0;
    g_AiCreaturePowerEval = 0;
    local_6c = g_IsAiThinking;
    g_IsAiThinking = 1;
    DAT_00676c8c = 1;
    Ai_Subsystem_004cab92();
    Ai_PushBoardState();
    local_64 = g_SpellStackDepth;
    g_SpellStackDepth = 0;
    DAT_0055999c = 0;
    g_AiEvaluationCandidateCount = 0;
    Magic_ScanCards(199);
    Pic_Subsystem_004475a4(arg1);
    local_88 = Ai_SimulateCombatRound(arg1);
    local_88 = g_SpellStackDepth + local_88;
    Ai_PopBoardState();
    g_SpellStackDepth = local_64;
    for (local_70 = 0; local_70 < (int)(&g_PlayerActiveCardCount)[arg1]; local_70 = local_70 + 1) {
      local_68 = *(int *)(&g_CardSlot_CardId + local_70 * 0x120 + arg1 * 0x5b20);
      if (((local_68 != -1) && (((&g_CardSlot_Flags)[local_70 * 0x120 + arg1 * 0x5b20] & 4) != 0))
         && (((&g_CardSlot_ColorMask)[local_70 * 0x120 + arg1 * 0x5b20] == -1 ||
             ((char)(&g_CardSlot_ColorMask)[local_70 * 0x120 + arg1 * 0x5b20] == local_70)))) {
        local_80 = FUN_00473cc5((&DAT_0051aebe)[local_68 * 0x34]);
        local_78 = *(int *)(&g_AiBestScore + local_70 * 0xc + arg1 * 0x3c0);
        (&g_AiAttackerList)[g_AiCreaturePowerEval] = local_70;
        (&g_AiCombatSimulationState)[g_AiCreaturePowerEval] = *(int *)(&DAT_00695eb0 + arg1 * 4) + local_78;
        (&g_AiCandidateScoreList)[g_AiCreaturePowerEval] =
             *(int *)(&g_AiBestCardIndex + local_70 * 0xc + arg1 * 0x3c0) +
             *(int *)(&DAT_00695eb8 + arg1 * 4);
        (&g_AiBlockerList)[g_AiCreaturePowerEval] =
             *(int *)(&g_AiBestTargetPlayer + local_70 * 0xc + arg1 * 0x3c0);
        val_result = FUN_0040d949(arg1,local_80,1);
        if (val_result == 0) {
          (&g_AiBlockerList)[g_AiCreaturePowerEval] = (&g_AiBlockerList)[g_AiCreaturePowerEval] & 0xfffffdff;
        }
        g_AiBlockingCreatureCount = 0;
        FUN_00473e69(arg1,local_70,0x8a);
        (&DAT_00559a98)[g_AiCreaturePowerEval] = g_AiBlockingCreatureCount;
        if (((&g_MasterCardSubtypeTable)[local_68 * 0x34] & 8) != 0) {
          val_result = (**(code **)(&g_MasterCardManaCostTable + local_68 * 0x34))(arg1,local_70,0x39);
          (&g_AiCombatSimulationState)[g_AiCreaturePowerEval] = (&g_AiCombatSimulationState)[g_AiCreaturePowerEval] + val_result;
        }
        if (((&g_MasterCardSubtypeTable)[local_68 * 0x34] & 0x10) != 0) {
          val_result = (**(code **)(&g_MasterCardManaCostTable + local_68 * 0x34))(arg1,local_70,0x3a);
          (&g_AiCandidateScoreList)[g_AiCreaturePowerEval] = (&g_AiCandidateScoreList)[g_AiCreaturePowerEval] + val_result;
        }
        Ai_PushBoardState();
        local_64 = g_SpellStackDepth;
        g_SpellStackDepth = 0;
        *(uint *)(&g_CardSlot_Abilities1 + local_70 * 0x120 + arg1 * 0x5b20) =
             *(uint *)(&g_CardSlot_Abilities1 + local_70 * 0x120 + arg1 * 0x5b20) | 8;
        Pic_Subsystem_0044867e(arg1,local_70,2);
        Magic_ScanCards(199);
        Pic_Subsystem_004475a4(arg1);
        local_c = Ai_SimulateCombatRound(arg1);
        local_c = g_SpellStackDepth + local_c;
        Ai_PopBoardState();
        g_SpellStackDepth = local_64;
        val_result = abs((int)(char)(&DAT_0051aec0)[local_68 * 0x34]);
        local_10 = ((val_result + (char)(&DAT_0051aebf)[local_68 * 0x34]) - local_c) + local_88;
        if ((*(byte *)((int)&g_AiBlockerList + g_AiCreaturePowerEval * 4 + 1) & 2) != 0) {
          val_result = FUN_0040d949(arg1,local_80,1);
          if (val_result == 0) {
            local_10 = local_10 << 1;
          }
          else {
            local_10 = local_10 / 3;
          }
        }
        *(int *)(&DAT_006a5f70 + local_70 * 0x120 + arg1 * 0x5b20) = local_10;
        (&g_AiCombatSimulationBuffer_End)[g_AiCreaturePowerEval] = local_10;
        (&g_AiCandidateScoreList)[g_AiCreaturePowerEval] =
             (&g_AiCandidateScoreList)[g_AiCreaturePowerEval] -
             (int)*(short *)(&g_CardSlot_Power + local_70 * 0x120 + arg1 * 0x5b20);
        (&g_AiCandidatePriorityList)[g_AiCreaturePowerEval] = 0;
        if ((&DAT_006a604f)[local_70 * 0x120 + arg1 * 0x5b20] != '\0') {
          g_AiEvaluationCandidateCount = g_AiEvaluationCandidateCount | 1 << ((byte)g_AiCreaturePowerEval & 0x1f);
        }
        g_AiCreaturePowerEval = g_AiCreaturePowerEval + 1;
        if ((g_IsAiThinking == 1) && (6 < g_AiCreaturePowerEval)) break;
      }
    }
    for (local_70 = 0; local_70 < (int)(&g_PlayerActiveCardCount)[arg1]; local_70 = local_70 + 1) {
      local_68 = *(int *)(&g_CardSlot_CardId + local_70 * 0x120 + arg1 * 0x5b20);
      if ((((local_68 != -1) && (((&g_CardSlot_Flags)[local_70 * 0x120 + arg1 * 0x5b20] & 4) != 0))
          && ((&g_CardSlot_ColorMask)[local_70 * 0x120 + arg1 * 0x5b20] != -1)) &&
         ((char)(&g_CardSlot_ColorMask)[local_70 * 0x120 + arg1 * 0x5b20] != local_70)) {
        local_5c = -1;
        for (local_74 = 0; local_74 < g_AiCreaturePowerEval; local_74 = local_74 + 1) {
          if ((int)(char)(&g_CardSlot_ColorMask)[local_70 * 0x120 + arg1 * 0x5b20] ==
              (&g_AiAttackerList)[local_74]) {
            local_5c = local_74;
            break;
          }
        }
        if (local_5c != -1) {
          local_80 = FUN_00473cc5((&DAT_0051aebe)[local_68 * 0x34]);
          (&DAT_00559ad8)[DAT_0055a090] = local_70;
          local_78 = *(int *)(&g_AiBestScore + local_70 * 0xc + arg1 * 0x3c0);
          (&g_AiCombatSimulationState)[local_5c] = (&g_AiCombatSimulationState)[local_5c] + local_78;
          (&g_AiCandidateScoreList)[local_5c] =
               (&g_AiCandidateScoreList)[local_5c] + *(int *)(&g_AiBestCardIndex + local_70 * 0xc + arg1 * 0x3c0);
          local_8c = *(uint *)(&g_AiBestTargetPlayer + local_70 * 0xc + arg1 * 0x3c0) & 0x200 |
                     (&g_AiBlockerList)[local_5c] & 0x200;
          (&g_AiBlockerList)[local_5c] =
               (&g_AiBlockerList)[local_5c] & *(uint *)(&g_AiBestTargetPlayer + local_70 * 0xc + arg1 * 0x3c0)
          ;
          (&g_AiBlockerList)[local_5c] = (&g_AiBlockerList)[local_5c] | local_8c;
          if (((&g_MasterCardSubtypeTable)[local_68 * 0x34] & 8) != 0) {
            val_result = (**(code **)(&g_MasterCardManaCostTable + local_68 * 0x34))(arg1,local_70,0x39);
            (&g_AiCombatSimulationState)[local_5c] = (&g_AiCombatSimulationState)[local_5c] + val_result;
          }
          if (((&g_MasterCardSubtypeTable)[local_68 * 0x34] & 0x10) != 0) {
            val_result = (**(code **)(&g_MasterCardManaCostTable + local_68 * 0x34))(arg1,local_70,0x3a);
            (&g_AiCandidateScoreList)[local_5c] = (&g_AiCandidateScoreList)[local_5c] + val_result;
          }
          Ai_PushBoardState();
          local_64 = g_SpellStackDepth;
          g_SpellStackDepth = 0;
          *(uint *)(&g_CardSlot_Abilities1 + local_70 * 0x120 + arg1 * 0x5b20) =
               *(uint *)(&g_CardSlot_Abilities1 + local_70 * 0x120 + arg1 * 0x5b20) | 8;
          Pic_Subsystem_0044867e(arg1,local_70,2);
          Magic_ScanCards(199);
          Pic_Subsystem_004475a4(arg1);
          local_c = Ai_SimulateCombatRound(arg1);
          local_c = g_SpellStackDepth + local_c;
          Ai_PopBoardState();
          g_SpellStackDepth = local_64;
          val_result = abs((int)(char)(&DAT_0051aec0)[local_68 * 0x34]);
          local_10 = ((val_result + (char)(&DAT_0051aebf)[local_68 * 0x34]) - local_c) + local_88;
          if ((*(byte *)((int)&g_AiBlockerList + local_5c * 4 + 1) & 2) != 0) {
            val_result = FUN_0040d949(arg1,local_80,1);
            if (val_result == 0) {
              local_10 = local_10 << 1;
            }
            else {
              local_10 = local_10 / 3;
            }
          }
          *(int *)(&DAT_006a5f70 + local_70 * 0x120 + arg1 * 0x5b20) = local_10;
          if (local_10 < (int)(&g_AiCombatSimulationBuffer_End)[local_5c]) {
            (&g_AiCombatSimulationBuffer_End)[local_5c] = local_10;
          }
          (&g_AiCandidateScoreList)[local_5c] =
               (&g_AiCandidateScoreList)[local_5c] -
               (int)*(short *)(&g_CardSlot_Power + local_70 * 0x120 + arg1 * 0x5b20);
          (&g_AiCandidatePriorityList)[local_5c] = 0;
          if ((&DAT_006a604f)[local_70 * 0x120 + arg1 * 0x5b20] != '\0') {
            g_AiEvaluationCandidateCount = g_AiEvaluationCandidateCount | 1 << ((byte)local_5c & 0x1f);
          }
          DAT_0055a090 = DAT_0055a090 + 1;
        }
      }
    }
    local_60 = 0;
    for (local_70 = 0; local_70 < (int)(&g_PlayerActiveCardCount)[g_AiCreatureToughnessEval];
        local_70 = local_70 + 1) {
      local_68 = *(int *)(&g_CardSlot_CardId + local_70 * 0x120 + g_AiCreatureToughnessEval * 0x5b20);
      if (((local_68 != -1) && (((&g_MasterCardColorTable)[local_68 * 0x34] & 2) != 0)) &&
         ((((byte)*(int *)(&g_CardSlot_Flags + local_70 * 0x120 + g_AiCreatureToughnessEval * 0x5b20) &
           0x12) == 2 && ((&g_CardSlot_ColorMask)[local_70 * 0x120 + g_AiCreatureToughnessEval * 0x5b20] == -1)))
         ) {
        aiStack_58[local_60] = local_70;
        local_60 = local_60 + 1;
      }
      if ((g_IsAiThinking == 1) && (0xf < local_60)) break;
    }
    if ((g_IsAiThinking == 1) && (6 < local_60)) {
      for (local_70 = 0; local_70 < local_60; local_70 = local_70 + 1) {
        val_result = Ai_Subsystem_004cb04d(g_AiCreatureToughnessEval,aiStack_58[local_70]);
        aiStack_cc[local_70] = val_result;
      }
      for (local_70 = 0; local_70 < local_60; local_70 = local_70 + 1) {
        for (local_74 = local_70; local_74 < local_60; local_74 = local_74 + 1) {
          if (aiStack_cc[local_70] < aiStack_cc[local_74]) {
            val_result = aiStack_cc[local_70];
            aiStack_cc[local_70] = aiStack_cc[local_74];
            aiStack_cc[local_74] = val_result;
            val_result = aiStack_58[local_70];
            aiStack_58[local_70] = aiStack_58[local_74];
            aiStack_58[local_74] = val_result;
          }
        }
      }
      if (6 < local_60) {
        local_60 = 7;
      }
      for (local_70 = 0; local_70 < local_60; local_70 = local_70 + 1) {
        for (local_74 = local_70; local_74 < local_60; local_74 = local_74 + 1) {
          if (aiStack_58[local_74] < aiStack_58[local_70]) {
            val_result = aiStack_58[local_70];
            aiStack_58[local_70] = aiStack_58[local_74];
            aiStack_58[local_74] = val_result;
          }
        }
      }
    }
    g_AiCombatScoreBuffer = 0;
    for (local_84 = 0; local_84 < local_60; local_84 = local_84 + 1) {
      local_70 = aiStack_58[local_84];
      local_68 = *(int *)(&g_CardSlot_CardId + local_70 * 0x120 + g_AiCreatureToughnessEval * 0x5b20);
      local_80 = FUN_00473cc5((&DAT_0051aebe)[local_68 * 0x34]);
      *(uint *)(&g_CardSlot_Flags + local_70 * 0x120 + g_AiCreatureToughnessEval * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + local_70 * 0x120 + g_AiCreatureToughnessEval * 0x5b20) | 8;
      local_78 = *(int *)(&g_AiBestScore + local_70 * 0xc + g_AiCreatureToughnessEval * 0x3c0);
      (&g_AiCombatDamageTable)[g_AiCombatScoreBuffer] = local_70;
      (&g_AiLethalDamageFlag)[g_AiCombatScoreBuffer] = *(int *)(&DAT_00695eb0 + g_AiCreatureToughnessEval * 4) + local_78;
      (&g_AiCandidateCardList)[g_AiCombatScoreBuffer] =
           *(int *)(&g_AiBestCardIndex + local_70 * 0xc + g_AiCreatureToughnessEval * 0x3c0) +
           *(int *)(&DAT_00695eb8 + g_AiCreatureToughnessEval * 4);
      (&g_AiBlockerAssignmentList)[g_AiCombatScoreBuffer] =
           *(int *)(&g_AiBestTargetPlayer + local_70 * 0xc + g_AiCreatureToughnessEval * 0x3c0);
      val_result = FUN_0040d949(g_AiCreatureToughnessEval,local_80,1);
      if (val_result == 0) {
        (&g_AiBlockerAssignmentList)[g_AiCombatScoreBuffer] = (&g_AiBlockerAssignmentList)[g_AiCombatScoreBuffer] & 0xfffffdff;
      }
      g_AiBlockingCreatureCount = 0;
      FUN_00473e69(g_AiCreatureToughnessEval,local_70,0x8b);
      (&DAT_00559a28)[g_AiCreaturePowerEval] = g_AiBlockingCreatureCount;
      if (g_CurrentTurnPhase == g_AiCreatureToughnessEval) {
        if (((&g_MasterCardSubtypeTable)[local_68 * 0x34] & 8) != 0) {
          val_result = (**(code **)(&g_MasterCardManaCostTable + local_68 * 0x34))(g_AiCreatureToughnessEval,local_70,0x39);
          (&g_AiLethalDamageFlag)[g_AiCombatScoreBuffer] = (&g_AiLethalDamageFlag)[g_AiCombatScoreBuffer] + val_result;
        }
        if (((&g_MasterCardSubtypeTable)[local_68 * 0x34] & 0x10) != 0) {
          val_result = (**(code **)(&g_MasterCardManaCostTable + local_68 * 0x34))(g_AiCreatureToughnessEval,local_70,0x3a);
          (&g_AiCandidateCardList)[g_AiCombatScoreBuffer] = (&g_AiCandidateCardList)[g_AiCombatScoreBuffer] + val_result;
        }
      }
      Ai_PushBoardState();
      local_64 = g_SpellStackDepth;
      g_SpellStackDepth = 0;
      *(uint *)(&g_CardSlot_Abilities1 + local_70 * 0x120 + g_AiCreatureToughnessEval * 0x5b20) =
           *(uint *)(&g_CardSlot_Abilities1 + local_70 * 0x120 + g_AiCreatureToughnessEval * 0x5b20) | 8;
      Pic_Subsystem_0044867e(g_AiCreatureToughnessEval,local_70,2);
      Magic_ScanCards(199);
      Pic_Subsystem_004475a4(arg1);
      local_c = Ai_SimulateCombatRound(arg1);
      local_c = g_SpellStackDepth + local_c;
      Ai_PopBoardState();
      g_SpellStackDepth = 0;
      *(int *)(&g_CardSlot_CardId + local_70 * 0x120 + g_AiCreatureToughnessEval * 0x5b20) = 0xffffffff;
      local_14 = Ai_SimulateCombatRound(arg1);
      local_14 = g_SpellStackDepth + local_14;
      Ai_PopBoardState();
      g_SpellStackDepth = local_64;
      local_10 = local_c - local_88;
      if ((*(byte *)((int)&g_AiBlockerAssignmentList + g_AiCombatScoreBuffer * 4 + 1) & 2) != 0) {
        val_result = FUN_0040d949(g_AiCreatureToughnessEval,local_80,1);
        if (val_result == 0) {
          local_10 = local_10 << 1;
        }
        else {
          local_10 = local_10 / 5;
        }
      }
      (&DAT_0055a098)[g_AiCombatScoreBuffer] = local_10;
      *(int *)(&DAT_006a5f70 + local_70 * 0x120 + g_AiCreatureToughnessEval * 0x5b20) = local_10;
      (&g_AiCandidateCardList)[g_AiCombatScoreBuffer] =
           (&g_AiCandidateCardList)[g_AiCombatScoreBuffer] -
           (int)*(short *)(&g_CardSlot_Power + local_70 * 0x120 + g_AiCreatureToughnessEval * 0x5b20);
      *(uint *)(&g_CardSlot_Flags + local_70 * 0x120 + g_AiCreatureToughnessEval * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + local_70 * 0x120 + g_AiCreatureToughnessEval * 0x5b20) & 0xfffffff7;
      for (local_74 = 0; local_74 < g_AiCreaturePowerEval; local_74 = local_74 + 1) {
        val_result = FUN_00472c0c(g_AiCreatureToughnessEval,local_70,arg1,(&g_AiAttackerList)[local_74],
                             (&g_AiBlockerList)[local_74],DAT_0055a094);
        if (val_result == 0) {
          if (DAT_0055a090 != 0) {
            for (local_7c = 0; local_7c < DAT_0055a090; local_7c = local_7c + 1) {
              if (((int)(char)(&g_CardSlot_ColorMask)
                              [arg1 * 0x5b20 + (&DAT_00559ad8)[local_7c] * 0x120] ==
                   (&g_AiAttackerList)[local_70]) &&
                 (val_result = FUN_00472c0c(g_AiCreatureToughnessEval,local_70,arg1,(&DAT_00559ad8)[local_7c],
                                       (&g_AiBlockerList)[local_74],DAT_0055a094), val_result != 0)) {
                (&g_AiCandidatePriorityList)[local_74] =
                     (&g_AiCandidatePriorityList)[local_74] | 1 << ((byte)g_AiCombatScoreBuffer & 0x1f);
              }
            }
          }
        }
        else {
          (&g_AiCandidatePriorityList)[local_74] = (&g_AiCandidatePriorityList)[local_74] | 1 << ((byte)g_AiCombatScoreBuffer & 0x1f);
        }
      }
      if ((&DAT_006a604f)[local_70 * 0x120 + g_AiCreatureToughnessEval * 0x5b20] != '\0') {
        DAT_0055999c = DAT_0055999c | 1 << ((byte)g_AiCombatScoreBuffer & 0x1f);
      }
      *(uint *)(&g_CardSlot_Flags + local_70 * 0x120 + g_AiCreatureToughnessEval * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + local_70 * 0x120 + g_AiCreatureToughnessEval * 0x5b20) & 0xfffffff7;
      val_result = *(int *)(&g_AiPlayerLifeDifferential + g_AiCreatureToughnessEval * 4);
      status = (&DAT_0055a098)[g_AiCombatScoreBuffer];
      temp_idx = FUN_0040a305((&g_AiCandidateCardList)[g_AiCombatScoreBuffer] + 1,1,99);
      (&DAT_00559678)[g_AiCombatScoreBuffer] = (val_result * status) / temp_idx;
      g_AiCombatScoreBuffer = g_AiCombatScoreBuffer + 1;
      if ((g_IsAiThinking == 1) && (6 < g_AiCombatScoreBuffer)) break;
    }
    memset(&DAT_00559a68,0,0x1c);
    memset(&DAT_00559b20,0,0x1c);
    for (local_70 = 0; local_70 < g_AiCreaturePowerEval; local_70 = local_70 + 1) {
      for (local_74 = 0; local_74 < g_AiCombatScoreBuffer; local_74 = local_74 + 1) {
        u_val = FUN_00476c77(arg1,(&g_AiAttackerList)[local_70],g_AiCreatureToughnessEval,(&g_AiCombatDamageTable)[local_74])
        ;
        if ((u_val & 1) != 0) {
          *(uint *)(&DAT_00559a68 + local_70 * 4) =
               *(uint *)(&DAT_00559a68 + local_70 * 4) | 1 << ((byte)local_74 & 0x1f);
        }
        if ((u_val & 2) != 0) {
          *(uint *)(&DAT_00559b20 + local_74 * 4) =
               *(uint *)(&DAT_00559b20 + local_74 * 4) | 1 << ((byte)local_70 & 0x1f);
        }
      }
    }
    g_IsAiThinking = local_6c;
  }
  DAT_00559b18 = 0;
  DAT_00676c8c = 0;
  DAT_00559888 = (&DAT_0052dde0)[g_AiCreaturePowerEval];
  return;
}

/*
 * Ai_Subsystem_004c5fc9
 * Purpose: Tactical AI engine subsystem routine (004c5fc9).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004c5fc9
 * Entry Point: 004c5fc9
 * Size: 6879 bytes
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint Ai_Subsystem_004c5fc9(int arg1)

{
  uint u_res;
  int val_result;
  uint u_score;
  int card_idx;
  int local_47c;
  int local_478;
  int local_474;
  int local_470;
  int local_46c [7];
  int local_450 [9];
  uint local_42c;
  int local_428;
  int local_424;
  int local_420;
  int aiStack_41c [16];
  int aiStack_3dc [16];
  int local_39c [16];
  char acStack_35c [84];
  uint local_308 [16];
  int local_2c8;
  uint local_2c4;
  uint local_2c0;
  int local_2bc;
  int local_2b8;
  uint local_2b4;
  int local_2b0;
  int local_2ac;
  int local_2a8;
  uint local_2a4;
  int local_2a0;
  int local_29c;
  int local_298 [16];
  int local_258;
  int local_254;
  int local_250;
  int local_24c;
  int local_248;
  int aiStack_244 [16];
  int local_204;
  uint local_200;
  int aiStack_1fc [14];
  int aiStack_1c4 [18];
  int local_17c;
  int aiStack_178 [16];
  int local_138;
  char acStack_134 [80];
  int local_e4;
  int aiStack_e0 [16];
  int local_a0;
  int local_9c;
  int local_98;
  int local_94;
  int local_90;
  uint local_8c;
  int local_88 [16];
  int local_48 [16];
  uint local_8;
  
  Ai_Subsystem_004c4210(arg1);
  local_2a0 = g_CardSlot_PowerBonus;
  g_CardSlot_PowerBonus = 2;
  local_24c = g_IsAiThinking;
  if (g_IsAiThinking == 1) {
    DAT_00680790 = DAT_00680790 ^ 2;
  }
  for (local_2a8 = 0; local_2a8 < (int)(&g_PlayerActiveCardCount)[arg1]; local_2a8 = local_2a8 + 1)
  {
    *(uint *)(&g_CardSlot_Flags + local_2a8 * 0x120 + arg1 * 0x5b20) =
         *(uint *)(&g_CardSlot_Flags + local_2a8 * 0x120 + arg1 * 0x5b20) & 0xfffffffb;
  }
  Magic_ScanCards(0x15);
  local_2c4 = 0;
  local_29c = 0;
  local_248 = 0;
  local_8c = 0;
  local_254 = 0;
  local_8 = 0xffffffff;
  memset(local_46c,0,0x40);
  for (local_2a8 = 0; local_2a8 < (int)(&g_PlayerActiveCardCount)[arg1]; local_2a8 = local_2a8 + 1)
  {
    local_204 = *(int *)(&g_CardSlot_CardId + local_2a8 * 0x120 + arg1 * 0x5b20);
    if ((((local_204 != -1) && (((&g_MasterCardColorTable)[local_204 * 0x34] & 2) != 0)) &&
        ((*(uint *)(&g_CardSlot_Flags + local_2a8 * 0x120 + arg1 * 0x5b20) & 0x20012) == 2)) &&
       (val_result = FUN_004726c5(arg1,local_2a8), val_result != 0)) {
      if (((&g_CardSlot_StateByte)[local_2a8 * 0x120 + arg1 * 0x5b20] & 0x80) != 0) {
        local_8c = local_8c | 1 << ((byte)local_254 & 0x1f);
      }
      if ((((DAT_00680790 & 2) == 0) ||
          (((&g_CardSlot_StateByte)[local_2a8 * 0x120 + arg1 * 0x5b20] & 0x80) != 0)) ||
         (((&g_AiBestTargetPlayer)[local_2a8 * 0xc + arg1 * 0x3c0] & 0x40) == 0)) {
        val_result = Ai_Subsystem_004cae47(arg1,local_2a8);
        aiStack_e0[local_254] = val_result;
        local_46c[local_254] = local_2a8;
        local_254 = local_254 + 1;
        *(uint *)(&g_CardSlot_Flags + local_2a8 * 0x120 + arg1 * 0x5b20) =
             *(uint *)(&g_CardSlot_Flags + local_2a8 * 0x120 + arg1 * 0x5b20) | 4;
      }
      else {
        local_29c = local_29c + *(int *)(&g_AiBestScore + local_2a8 * 0xc + arg1 * 0x3c0);
        local_8 = local_8 & *(uint *)(&g_AiBestTargetPlayer + local_2a8 * 0xc + arg1 * 0x3c0);
        local_2c4 = local_2c4 | *(uint *)(&g_AiBestTargetPlayer + local_2a8 * 0xc + arg1 * 0x3c0) & 0x200;
        aiStack_244[local_248] = local_2a8;
        local_248 = local_248 + 1;
      }
    }
  }
  local_8 = local_8 | local_2c4;
  if (7 < local_254) {
    local_470 = 0;
    for (local_2a8 = 0; local_2a8 < (int)(&g_PlayerActiveCardCount)[g_AiCreatureToughnessEval];
        local_2a8 = local_2a8 + 1) {
      local_204 = *(int *)(&g_CardSlot_CardId + local_2a8 * 0x120 + g_AiCreatureToughnessEval * 0x5b20);
      if (((local_204 != -1) && (((&g_MasterCardColorTable)[local_204 * 0x34] & 2) != 0)) &&
         (((&g_CardSlot_Flags)[local_2a8 * 0x120 + g_AiCreatureToughnessEval * 0x5b20] & 0x12) != 0)) {
        local_470 = local_470 + 1;
      }
    }
    for (local_2a8 = 0; local_2a8 < 0x10; local_2a8 = local_2a8 + 1) {
      aiStack_178[local_2a8] = 0;
    }
    for (local_2a8 = 0; local_2a8 < local_254; local_2a8 = local_2a8 + 1) {
      aiStack_178[local_2a8] = *(int *)(&g_AiBestScore + local_46c[local_2a8] * 0xc + arg1 * 0x3c0);
    }
    while (local_470 != 0) {
      local_47c = 0;
      local_478 = 0;
      for (local_2a8 = 0; local_2a8 < local_254; local_2a8 = local_2a8 + 1) {
        if (local_47c < aiStack_178[local_2a8]) {
          local_47c = aiStack_178[local_2a8];
          local_478 = local_2a8;
        }
      }
      aiStack_178[local_478] = 0;
      local_470 = local_470 + -1;
    }
    local_474 = 0;
    for (local_2a8 = 0; local_2a8 < local_254; local_2a8 = local_2a8 + 1) {
      local_474 = local_474 + aiStack_178[local_2a8];
    }
    if ((int)(&g_PlayerCreatureCount)[1 - arg1] <= local_474) {
      for (local_2a8 = 0; local_2a8 < local_254; local_2a8 = local_2a8 + 1) {
        *(uint *)(&g_CardSlot_Flags + arg1 * 0x5b20 + local_46c[local_2a8] * 0x120) =
             *(uint *)(&g_CardSlot_Flags + arg1 * 0x5b20 + local_46c[local_2a8] * 0x120) | 4;
      }
      g_ActiveBattlefieldFlag = (1 << ((byte)local_254 & 0x1f)) - 1;
      return g_ActiveBattlefieldFlag;
    }
  }
  if (7 < local_254) {
    for (local_2a8 = 0; local_2a8 < local_254; local_2a8 = local_2a8 + 1) {
      for (local_2b8 = local_2a8; local_2b8 < local_254; local_2b8 = local_2b8 + 1) {
        if (aiStack_e0[local_2a8] < aiStack_e0[local_2b8]) {
          val_result = aiStack_e0[local_2a8];
          aiStack_e0[local_2a8] = aiStack_e0[local_2b8];
          aiStack_e0[local_2b8] = val_result;
          val_result = local_46c[local_2a8];
          local_46c[local_2a8] = local_46c[local_2b8];
          local_46c[local_2b8] = val_result;
          u_score = 1 << ((byte)local_2a8 & 0x1f) & local_8c;
          u_res = local_8c & ~(1 << ((byte)local_2a8 & 0x1f));
          local_8c = u_res & ~(1 << ((byte)local_2b8 & 0x1f));
          if (u_score != 0) {
            local_8c = local_8c | 1 << ((byte)local_2b8 & 0x1f);
          }
          if ((1 << ((byte)local_2b8 & 0x1f) & u_res) != 0) {
            local_8c = local_8c | 1 << ((byte)local_2a8 & 0x1f);
          }
        }
      }
    }
    if (6 < local_254) {
      local_254 = 7;
    }
    for (local_2a8 = 7; local_2a8 < 0x10; local_2a8 = local_2a8 + 1) {
      *(uint *)(&g_CardSlot_Flags + arg1 * 0x5b20 + local_46c[local_2a8] * 0x120) =
           *(uint *)(&g_CardSlot_Flags + arg1 * 0x5b20 + local_46c[local_2a8] * 0x120) & 0xfffffffb
      ;
    }
    memset(local_450,0,0x24);
    local_8c = 0;
    local_254 = 0;
    for (local_2a8 = 0; local_2a8 < (int)(&g_PlayerActiveCardCount)[arg1];
        local_2a8 = local_2a8 + 1) {
      if (((&g_CardSlot_Flags)[local_2a8 * 0x120 + arg1 * 0x5b20] & 4) != 0) {
        if (((&g_CardSlot_StateByte)[local_2a8 * 0x120 + arg1 * 0x5b20] & 0x80) != 0) {
          local_8c = local_8c | 1 << ((byte)local_254 & 0x1f);
        }
        local_46c[local_254] = local_2a8;
        local_254 = local_254 + 1;
      }
    }
  }
  Ai_Subsystem_004c4c84(arg1);
  memcpy(local_88,&g_AiCombatSimulationState,0x40);
  memcpy(local_48,&g_AiCandidateScoreList,0x40);
  memcpy(local_308,&g_AiBlockerList,0x40);
  memcpy(local_298,&g_AiCombatSimulationBuffer_End,0x40);
  memcpy(local_39c,&g_AiCandidatePriorityList,0x40);
  memcpy(&DAT_005598d8,&DAT_00559a98,0x40);
  memcpy(&DAT_00559778,&DAT_00559a28,0x40);
  Ai_PushBoardState();
  g_IsAiThinking = 1;
  Magic_ScanCards(199);
  g_IsAiThinking = local_24c;
  for (local_2a8 = 0; local_2a8 < 8; local_2a8 = local_2a8 + 1) {
    *(int *)(&g_AiCombatScore_Total + local_2a8 * 4 + g_AiCreatureToughnessEval * 0x20) =
         *(int *)(&g_AiCombatScore_Attacker + local_2a8 * 4 + g_AiCreatureToughnessEval * 0x20);
  }
  local_e4 = 0;
  local_90 = 0;
  for (local_2a8 = 0; local_2a8 < (int)(&g_PlayerActiveCardCount)[g_AiCreatureToughnessEval];
      local_2a8 = local_2a8 + 1) {
    local_204 = *(int *)(&g_CardSlot_CardId + local_2a8 * 0x120 + g_AiCreatureToughnessEval * 0x5b20);
    if (((local_204 != -1) && (((&g_MasterCardColorTable)[local_204 * 0x34] & 2) != 0)) &&
       (((&g_CardSlot_Flags)[local_2a8 * 0x120 + g_AiCreatureToughnessEval * 0x5b20] & 2) != 0)) {
      aiStack_41c[local_90] = *(int *)(&g_AiBestScore + local_2a8 * 0xc + g_AiCreatureToughnessEval * 0x3c0);
      aiStack_3dc[local_90] = *(int *)(&g_AiBestCardIndex + local_2a8 * 0xc + g_AiCreatureToughnessEval * 0x3c0);
      if (((&g_MasterCardSubtypeTable)[local_204 * 0x34] & 8) != 0) {
        val_result = (**(code **)(&g_MasterCardManaCostTable + local_204 * 0x34))(g_AiCreatureToughnessEval,local_2a8,0x39);
        aiStack_41c[local_90] = aiStack_41c[local_90] + val_result;
      }
      if (((&g_MasterCardSubtypeTable)[local_204 * 0x34] & 0x10) != 0) {
        val_result = (**(code **)(&g_MasterCardManaCostTable + local_204 * 0x34))(g_AiCreatureToughnessEval,local_2a8,0x3a);
        aiStack_3dc[local_90] = aiStack_3dc[local_90] + val_result;
      }
      if (local_e4 < aiStack_3dc[local_90]) {
        local_e4 = aiStack_3dc[local_90];
      }
      acStack_35c[local_2a8] = (char)local_90;
      local_90 = local_90 + 1;
    }
  }
  local_420 = -1;
  for (local_2a8 = 0; local_2a8 < local_254; local_2a8 = local_2a8 + 1) {
    if (((local_420 == -1) && (local_88[local_2a8] < local_e4)) &&
       ((local_e4 <= local_88[local_2a8] + local_29c &&
        ((local_308[local_2a8] & local_8) == local_308[local_2a8])))) {
      local_88[local_2a8] = local_88[local_2a8] + local_29c;
      local_420 = local_46c[local_2a8];
    }
  }
  local_17c = 0;
  for (local_2b8 = 0; local_2b8 < (int)(&g_PlayerActiveCardCount)[arg1]; local_2b8 = local_2b8 + 1)
  {
    if (((*(int *)(&g_CardSlot_CardId + local_2b8 * 0x120 + arg1 * 0x5b20) != -1) &&
        (((&g_CardSlot_Flags)[local_2b8 * 0x120 + arg1 * 0x5b20] & 2) != 0)) &&
       (((&g_MasterCardColorTable)
         [*(int *)(&g_CardSlot_CardId + local_2b8 * 0x120 + arg1 * 0x5b20) * 0x34] & 2) != 0)) {
      aiStack_178[local_17c] = *(int *)(&g_AiBestScore + local_2b8 * 0xc + arg1 * 0x3c0);
      aiStack_1fc[local_17c] = *(int *)(&g_AiBestCardIndex + local_2b8 * 0xc + arg1 * 0x3c0);
      aiStack_e0[local_17c] = (aiStack_1fc[local_17c] + 1) * (aiStack_178[local_17c] + 1);
      for (local_2c0 = 0; (int)local_2c0 < g_AiCreaturePowerEval; local_2c0 = local_2c0 + 1) {
        if ((&g_AiAttackerList)[local_2c0] == local_2b8) {
          aiStack_e0[local_17c] = (&g_AiCombatSimulationBuffer_End)[local_2c0];
        }
      }
      acStack_134[local_2b8] = (char)local_17c;
      local_17c = local_17c + 1;
    }
  }
  Ai_PopBoardState();
  local_258 = 9999;
  Ai_FilterValidBlockers(&local_2b4,(uint *)0x0);
  local_2c0 = 0;
  do {
    if (1 << ((byte)local_254 & 0x1f) <= (int)local_2c0) {
      for (local_2a8 = 0; local_2a8 < local_254; local_2a8 = local_2a8 + 1) {
        *(uint *)(&g_CardSlot_Flags + arg1 * 0x5b20 + local_46c[local_2a8] * 0x120) =
             *(uint *)(&g_CardSlot_Flags + arg1 * 0x5b20 + local_46c[local_2a8] * 0x120) &
             0xfffffffb;
        if ((local_2a4 & 1 << ((byte)local_2a8 & 0x1f)) != 0) {
          *(uint *)(&g_CardSlot_Flags + arg1 * 0x5b20 + local_46c[local_2a8] * 0x120) =
               *(uint *)(&g_CardSlot_Flags + arg1 * 0x5b20 + local_46c[local_2a8] * 0x120) | 4;
          FUN_004726c5(arg1,local_46c[local_2a8]);
          if (((local_248 != 0) && (local_420 == -1)) &&
             ((local_308[local_2a8] & local_8) == local_308[local_2a8])) {
            local_420 = local_46c[local_2a8];
          }
        }
      }
      if (((local_248 == 0) || (local_420 == -1)) ||
         (((&g_CardSlot_Flags)[local_420 * 0x120 + arg1 * 0x5b20] & 4) == 0)) {
        if ((local_248 != 0) && (local_e4 == 0)) {
          for (local_2a8 = 0; local_2a8 < local_248; local_2a8 = local_2a8 + 1) {
            *(uint *)(&g_CardSlot_Flags + arg1 * 0x5b20 + aiStack_244[local_2a8] * 0x120) =
                 *(uint *)(&g_CardSlot_Flags + arg1 * 0x5b20 + aiStack_244[local_2a8] * 0x120) | 4;
            FUN_004726c5(arg1,aiStack_244[local_2a8]);
          }
          local_2a4 = 1;
        }
      }
      else {
        for (local_2a8 = 0; local_2a8 < local_248; local_2a8 = local_2a8 + 1) {
          (&g_CardSlot_ColorMask)[arg1 * 0x5b20 + aiStack_244[local_2a8] * 0x120] =
               (uint8_t)local_420;
          *(uint *)(&g_CardSlot_Flags + arg1 * 0x5b20 + aiStack_244[local_2a8] * 0x120) =
               *(uint *)(&g_CardSlot_Flags + arg1 * 0x5b20 + aiStack_244[local_2a8] * 0x120) | 4;
          FUN_004726c5(arg1,aiStack_244[local_2a8]);
        }
        (&g_CardSlot_ColorMask)[local_420 * 0x120 + arg1 * 0x5b20] = (uint8_t)local_420;
      }
      g_CardSlot_PowerBonus = local_2a0;
      g_ActiveBattlefieldFlag = local_2a4;
      return local_2a4;
    }
    local_2bc = 1;
    g_AiCreaturePowerEval = 0;
    g_AiEvaluationCandidateCount = 0;
    for (local_2a8 = 0; local_2a8 < local_254; local_2a8 = local_2a8 + 1) {
      *(uint *)(&g_CardSlot_Flags + arg1 * 0x5b20 + local_46c[local_2a8] * 0x120) =
           *(uint *)(&g_CardSlot_Flags + arg1 * 0x5b20 + local_46c[local_2a8] * 0x120) & 0xfffffffb
      ;
      local_2b0 = *(int *)(&g_MasterCardTypeTable +
                          *(int *)(&g_CardSlot_CardId +
                                  arg1 * 0x5b20 + local_46c[local_2a8] * 0x120) * 0x34);
      if ((local_2c0 & 1 << ((byte)local_2a8 & 0x1f)) == 0) {
        if ((local_2b0 == 0x19f) || (local_2b0 == 0x84)) {
          local_2bc = 0;
        }
        if ((local_8c & 1 << ((byte)local_2a8 & 0x1f)) != 0) {
          local_2bc = 0;
        }
      }
      else {
        *(uint *)(&g_CardSlot_Flags + arg1 * 0x5b20 + local_46c[local_2a8] * 0x120) =
             *(uint *)(&g_CardSlot_Flags + arg1 * 0x5b20 + local_46c[local_2a8] * 0x120) | 4;
        (&g_AiAttackerList)[g_AiCreaturePowerEval] = local_46c[local_2a8];
        (&g_AiCombatSimulationState)[g_AiCreaturePowerEval] = local_88[local_2a8];
        (&g_AiCandidateScoreList)[g_AiCreaturePowerEval] = local_48[local_2a8];
        (&g_AiBlockerList)[g_AiCreaturePowerEval] = local_308[local_2a8];
        (&g_AiCombatSimulationBuffer_End)[g_AiCreaturePowerEval] = local_298[local_2a8];
        (&g_AiCandidatePriorityList)[g_AiCreaturePowerEval] = local_39c[local_2a8];
        (&DAT_00559a98)[g_AiCreaturePowerEval] = *(int *)(&DAT_005598d8 + local_2a8 * 4);
        (&DAT_00559a28)[g_AiCreaturePowerEval] = *(int *)(&DAT_00559778 + local_2a8 * 4);
        if ((local_2b0 == 0x28) || (local_2b0 == 0x98)) {
          g_AiEvaluationCandidateCount = g_AiEvaluationCandidateCount | 1 << ((byte)g_AiCreaturePowerEval & 0x1f);
        }
        g_AiCreaturePowerEval = g_AiCreaturePowerEval + 1;
      }
    }
    if (local_2bc != 0) {
      DAT_00559b18 = 1;
      Ai_Subsystem_004c7aa8(arg1);
      Ai_PushBoardState();
      g_IsAiThinking = 1;
      Magic_ScanCards(199);
      g_IsAiThinking = local_24c;
      local_2ac = 0;
      for (local_98 = 0; local_98 < 8; local_98 = local_98 + 1) {
        aiStack_1c4[local_98 * 2 + 3] = -1;
      }
      for (local_2a8 = 0; local_2a8 < (int)(&g_PlayerActiveCardCount)[g_AiCreatureToughnessEval];
          local_2a8 = local_2a8 + 1) {
        local_204 = *(int *)(&g_CardSlot_CardId + local_2a8 * 0x120 + g_AiCreatureToughnessEval * 0x5b20);
        if (((local_204 != -1) && (((&g_MasterCardColorTable)[local_204 * 0x34] & 2) != 0)) &&
           ((*(uint *)(&g_CardSlot_Flags + local_2a8 * 0x120 + g_AiCreatureToughnessEval * 0x5b20) & 0x402) != 0)
           ) {
          local_90 = (int)acStack_35c[local_2a8];
          local_428 = aiStack_41c[acStack_35c[local_2a8]];
          local_2b8 = 0;
LAB_004c72b0:
          if (local_2b8 < 8) {
            if (local_428 <= aiStack_1c4[local_2b8 * 2 + 3]) goto LAB_004c72aa;
            for (local_98 = 7; local_2b8 < local_98; local_98 = local_98 + -1) {
              aiStack_1c4[local_98 * 2 + 2] = aiStack_1c4[local_98 * 2];
              aiStack_1c4[local_98 * 2 + 3] = aiStack_1c4[local_98 * 2 + 1];
            }
            aiStack_1c4[local_2b8 * 2 + 2] = local_2a8;
            aiStack_1c4[local_2b8 * 2 + 3] = local_428;
          }
        }
      }
      local_98 = 0;
      while ((local_98 < 8 && (aiStack_1c4[local_98 * 2 + 3] != -1))) {
        local_2a8 = aiStack_1c4[local_98 * 2 + 2];
        local_200 = FUN_00473179(g_AiCreatureToughnessEval,local_2a8,0x34,0xffffffff);
        local_90 = (int)acStack_35c[local_2a8];
        local_428 = aiStack_41c[local_90];
        local_424 = aiStack_3dc[local_90];
        local_2c8 = 0;
        local_42c = 0;
        local_17c = 0;
        local_9c = 0x7fff;
        for (local_2b8 = 0; local_2b8 < (int)(&g_PlayerActiveCardCount)[arg1];
            local_2b8 = local_2b8 + 1) {
          if (((*(int *)(&g_CardSlot_CardId + local_2b8 * 0x120 + arg1 * 0x5b20) != -1) &&
              ((*(uint *)(&g_CardSlot_Flags + local_2b8 * 0x120 + arg1 * 0x5b20) & 0x402) != 0)) &&
             (((&g_MasterCardColorTable)
               [*(int *)(&g_CardSlot_CardId + local_2b8 * 0x120 + arg1 * 0x5b20) * 0x34] & 2) != 0)
             ) {
            local_17c = (int)acStack_134[local_2b8];
            local_a0 = aiStack_178[local_17c];
            local_138 = aiStack_1fc[local_17c];
            card_idx = local_2b8 * 0x120;
            val_result = FUN_004728c3(arg1,local_2b8);
            if (((*(uint *)(&g_CardSlot_Flags + card_idx + arg1 * 0x5b20) &
                 (-(uint)(val_result == 0) & 4) + 8) == 0) &&
               (val_result = FUN_00472c0c(arg1,local_2b8,g_AiCreatureToughnessEval,local_2a8,local_200,local_2b4),
               u_res = local_42c, val_result != 0)) {
              local_42c = local_42c | 1;
              if ((local_428 < local_138) || (local_424 <= local_a0)) {
                local_42c = u_res | 3;
                *(uint *)(&g_CardSlot_Flags + local_2b8 * 0x120 + arg1 * 0x5b20) =
                     *(uint *)(&g_CardSlot_Flags + local_2b8 * 0x120 + arg1 * 0x5b20) | 8;
                break;
              }
              if (aiStack_e0[local_17c] < local_9c) {
                local_9c = aiStack_e0[local_17c];
                local_2c8 = local_2b8;
              }
            }
          }
        }
        if ((local_42c & 2) == 0) {
          val_result = *(int *)(&g_PlayerLifeTotals + arg1 * 4) * local_428 * 0x18;
          val_result = val_result + (val_result >> 0x1f & 3U);
          card_idx = FUN_0040a305((&g_PlayerCreatureCount)[arg1] + 1,1,99);
          local_250 = (int)(CONCAT44(val_result >> 0x1f,val_result >> 2) / (longlong)card_idx);
          if (local_42c != 0) {
            local_94 = (int)(*(int *)(&g_AiPlayerLifeDifferential + arg1 * 4) * local_9c +
                            (*(int *)(&g_AiPlayerLifeDifferential + arg1 * 4) * local_9c >> 0x1f & 7U)) >> 3;
            if (local_94 <= local_250) {
              g_AiDamageAssignmentBuffer = g_AiDamageAssignmentBuffer + local_94;
              *(uint *)(&g_CardSlot_Flags + local_2c8 * 0x120 + arg1 * 0x5b20) =
                   *(uint *)(&g_CardSlot_Flags + local_2c8 * 0x120 + arg1 * 0x5b20) | 8;
              goto LAB_004c737a;
            }
          }
          local_2ac = local_2ac + local_428;
          g_AiDamageAssignmentBuffer = g_AiDamageAssignmentBuffer + local_250;
        }
LAB_004c737a:
        local_98 = local_98 + 1;
      }
      Ai_PopBoardState();
      if ((((int)(&g_PlayerCreatureCount)[arg1] <= local_2ac) &&
          (0 < (int)(&g_PlayerCreatureCount)[arg1])) &&
         (0 < (int)(&g_PlayerCreatureCount)[1 - arg1])) {
        g_AiDamageAssignmentBuffer = g_AiDamageAssignmentBuffer + ((local_2ac - (&g_PlayerCreatureCount)[arg1]) + 2) * 0x80;
        g_AiDamageAssignmentBuffer = g_AiDamageAssignmentBuffer + DAT_00559998;
      }
      if (g_AiDamageAssignmentBuffer < local_258) {
        local_258 = g_AiDamageAssignmentBuffer;
        local_2a4 = local_2c0;
      }
    }
    local_2c0 = local_2c0 + 1;
  } while( true );
LAB_004c72aa:
  local_2b8 = local_2b8 + 1;
  goto LAB_004c72b0;
}

/*
 * Ai_Subsystem_004c7aa8
 * Purpose: Tactical AI engine subsystem routine (004c7aa8).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004c7aa8
 * Entry Point: 004c7aa8
 * Size: 317 bytes
 */

void Ai_Subsystem_004c7aa8(int arg1)

{
  int u_res;
  int local_c;
  
  u_res = g_CardSlot_PowerBonus;
  g_CardSlot_PowerBonus = 2;
  Ai_Subsystem_004c4c84(arg1);
  DAT_005597b8 = (uint)(g_CurrentTurnPhase != arg1);
  g_AiDamageAssignmentBuffer = 0xffffd8f1;
  for (local_c = 0; local_c < 0x10; local_c = local_c + 1) {
    *(int *)(&DAT_00559738 + local_c * 4) = 0;
  }
  Ai_Subsystem_004c7be5(arg1,0);
  if ((g_IsAiThinking == 1) || (g_DefendingPlayer == g_CurrentTurnPhase)) {
    for (local_c = 0; local_c < g_AiCombatScoreBuffer; local_c = local_c + 1) {
      (&g_CardSlot_ColorMask)[g_AiCreatureToughnessEval * 0x5b20 + (&g_AiCombatDamageTable)[local_c] * 0x120] =
           (&DAT_005597c0)[local_c * 4];
      if (g_IsAiThinking != 1) {
        Ai_Subsystem_004cc3f8(g_AiCreatureToughnessEval,(&g_AiCombatDamageTable)[local_c],5,2);
      }
    }
  }
  g_CardSlot_PowerBonus = u_res;
  return;
}

/*
 * Ai_Subsystem_004c7be5
 * Purpose: Tactical AI engine subsystem routine (004c7be5).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004c7be5
 * Entry Point: 004c7be5
 * Size: 388 bytes
 */

void Ai_Subsystem_004c7be5(int arg1, int arg2)

{
  int status;
  int local_c;
  
  if (arg2 == g_AiCombatScoreBuffer) {
    status = Ai_Subsystem_004c7d69();
    if (g_AiDamageAssignmentBuffer < status) {
      g_AiDamageAssignmentBuffer = status;
      memcpy(&DAT_005597c0,&DAT_00559958,0x1c);
      DAT_00559998 = DAT_00559f80;
    }
  }
  else {
    status = (&g_AiCombatDamageTable)[arg2] * 0x120 + g_AiCreatureToughnessEval * 0x5b20;
    if ((((&g_CardSlot_StateByte)[status] & 0x80) == 0) || ((&g_CardSlot_ColorMask)[status] == -1)) {
      *(int *)(&DAT_00559958 + arg2 * 4) = 0xffffffff;
      Ai_Subsystem_004c7be5(arg1,arg2 + 1);
    }
    for (local_c = 0; local_c < g_AiCreaturePowerEval; local_c = local_c + 1) {
      if (((*(int *)(&DAT_00559b40 + local_c * 4) < DAT_00559888) &&
          (((&g_AiCandidatePriorityList)[local_c] & 1 << ((byte)arg2 & 0x1f)) != 0)) &&
         ((((&g_CardSlot_StateByte)[status] & 0x80) == 0 ||
          ((int)(char)(&g_CardSlot_ColorMask)[status] == (&g_AiAttackerList)[local_c])))) {
        *(int *)(&DAT_00559b40 + local_c * 4) = *(int *)(&DAT_00559b40 + local_c * 4) + 1;
        *(int *)(&DAT_00559958 + arg2 * 4) = (&g_AiAttackerList)[local_c];
        Ai_Subsystem_004c7be5(arg1,arg2 + 1);
        *(int *)(&DAT_00559b40 + local_c * 4) = *(int *)(&DAT_00559b40 + local_c * 4) + -1;
      }
    }
  }
  return;
}

/*
 * Ai_Subsystem_004c7d69
 * Purpose: Tactical AI engine subsystem routine (004c7d69).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004c7d69
 * Entry Point: 004c7d69
 * Size: 2276 bytes
 */

int Ai_Subsystem_004c7d69(void)

{
  int status;
  bool is_match;
  int temp_idx;
  int local_e4;
  int local_e0;
  int local_dc;
  int local_d8;
  int local_d4;
  int local_d0;
  int local_cc;
  int local_c8;
  int local_c4;
  uint local_c0;
  int local_bc;
  int local_b4;
  int local_a8;
  int local_a4;
  int local_a0;
  int local_98;
  int local_94;
  int aiStack_90 [16];
  uint local_50;
  int aiStack_4c [16];
  int local_c;
  int local_8;
  
  local_a0 = 0;
  g_AiBlockingCreatureCount = 0;
  local_c = 0;
  local_94 = (&g_PlayerCreatureCount)[g_AiCreatureToughnessEval];
  local_98 = 0;
  DAT_00559f80 = 0;
  if (g_AiDecisionTreeDepth != 0) {
    local_a0 = DAT_00641874;
  }
  local_a8 = 0;
  do {
    temp_idx = local_94;
    if (g_AiCreaturePowerEval <= local_a8) {
      local_c = local_c + g_AiBlockingCreatureCount;
      if (local_98 != 0) {
        while (local_a0 != 0) {
          local_e4 = 0;
          for (local_a8 = 0; local_a8 < local_98; local_a8 = local_a8 + 1) {
            if (local_e4 < aiStack_90[local_a8]) {
              local_e4 = aiStack_90[local_a8];
              local_e0 = local_a8;
            }
          }
          if (local_e4 == 0) {
            local_a0 = 0;
          }
          else {
            local_94 = local_94 + aiStack_90[local_e0];
            aiStack_90[local_e0] = 0;
            local_a0 = local_a0 + -1;
          }
        }
      }
      if (local_94 < 1) {
        local_c = local_c - (local_94 * -0x60 + 999);
      }
      else {
        temp_idx = ((&g_PlayerCreatureCount)[g_AiCreatureToughnessEval] - local_94) *
                *(int *)(&g_PlayerLifeTotals + g_AiCreatureToughnessEval * 4) * 0x18;
        temp_idx = temp_idx + (temp_idx >> 0x1f & 3U);
        local_c = local_c - (int)(CONCAT44(temp_idx >> 0x1f,temp_idx >> 2) / (longlong)local_94);
        if (DAT_005597b8 != 0) {
          DAT_00559f80 = (((&g_PlayerCreatureCount)[g_AiCreatureToughnessEval] - local_94) * 700) /
                         (int)(&g_PlayerCreatureCount)[g_AiCreatureToughnessEval];
          local_c = local_c - DAT_00559f80;
        }
      }
      return local_c;
    }
    status = (&g_AiCombatSimulationState)[local_a8];
    local_dc = 0;
    local_d0 = -1;
    local_bc = -1;
    local_c8 = 0;
    is_match = false;
    local_50 = 0;
    local_cc = 0;
    g_AiBlockingCreatureCount = g_AiBlockingCreatureCount + (&DAT_00559a98)[local_a8];
    for (local_d4 = 0; local_d4 < g_AiCombatScoreBuffer; local_d4 = local_d4 + 1) {
      if (*(int *)(&DAT_00559958 + local_d4 * 4) == (&g_AiAttackerList)[local_a8]) {
        local_cc = local_cc + 1;
        g_AiBlockingCreatureCount = g_AiBlockingCreatureCount + (&DAT_00559a28)[local_d4];
        local_dc = local_dc + (&g_AiLethalDamageFlag)[local_d4];
        local_d0 = local_d4;
        if ((*(byte *)(&g_AiBlockerAssignmentList + local_d4) & 0x40) != 0) {
          is_match = true;
        }
        if ((*(uint *)(&DAT_00559b20 + local_d4 * 4) & 1 << ((byte)local_a8 & 0x1f)) != 0) {
          local_dc = local_dc + 99;
        }
        if ((*(uint *)(&DAT_00559a68 + local_a8 * 4) & 1 << ((byte)local_d4 & 0x1f)) != 0) {
          local_50 = local_50 | 1 << ((byte)local_d4 & 0x1f);
        }
        if ((((int)(&g_AiCandidateCardList)[local_d4] <= status) || (local_50 != 0)) &&
           ((*(byte *)((int)&g_AiBlockerAssignmentList + local_d4 * 4 + 1) & 2) == 0)) {
          aiStack_4c[local_c8] = local_d4;
          local_c8 = local_c8 + 1;
        }
        if (local_bc < (int)(&DAT_00559678)[local_d4]) {
          local_8 = local_d4;
          local_bc = (&DAT_00559678)[local_d4];
        }
      }
    }
    if (local_d0 == -1) {
      local_94 = local_94 - status;
    }
    else if (((*(byte *)(&g_AiBlockerList + local_a8) & 0x80) != 0) && (local_dc < status)) {
      local_94 = local_94 - (status - local_dc);
    }
    if (((g_AiDecisionTreeDepth != 0) && (local_94 < temp_idx)) &&
       ((g_AiDecisionTreeDepth &
        (int)(char)(&DAT_006a5f4d)[(1 - g_AiCreatureToughnessEval) * 0x5b20 + (&g_AiAttackerList)[local_a8] * 0x120])
        != 0)) {
      aiStack_90[local_98] = temp_idx - local_94;
      local_98 = local_98 + 1;
    }
    if (((local_d0 != -1) && ((int)(&g_AiCandidateScoreList)[local_a8] <= local_dc)) &&
       (((*(byte *)((int)&g_AiBlockerList + local_a8 * 4 + 1) & 3) == 0 || (local_c8 == 0)))) {
      local_c = local_c + ((int)(*(int *)(&g_PlayerLifeTotals + (3 - g_AiCreatureToughnessEval) * 4) *
                                 (&g_AiCombatSimulationBuffer_End)[local_a8] +
                                (*(int *)(&g_PlayerLifeTotals + (3 - g_AiCreatureToughnessEval) * 4) *
                                 (&g_AiCombatSimulationBuffer_End)[local_a8] >> 0x1f & 7U)) >> 3);
    }
    local_c4 = -1;
    for (local_c0 = 0; (int)local_c0 < 1 << ((byte)local_c8 & 0x1f); local_c0 = local_c0 + 1) {
      if (local_50 == 0) {
        local_d8 = status;
        if (!is_match) goto LAB_004c8311;
        if (local_dc - local_cc < status) {
          if (local_c0 == 0) {
            local_a4 = 0;
          }
          else {
            local_a4 = 9999;
          }
          for (local_b4 = 0; local_b4 < local_c8; local_b4 = local_b4 + 1) {
            if ((local_c0 & 1 << ((byte)local_b4 & 0x1f)) != 0) {
              temp_idx = aiStack_4c[local_b4];
              if ((int)(&DAT_0055a098)[temp_idx] < local_a4) {
                local_a4 = (&DAT_0055a098)[temp_idx];
              }
              if (status < (int)(&g_AiCandidateCardList)[temp_idx]) {
                local_a4 = 0;
              }
              else if ((((&g_AiBlockerAssignmentList)[temp_idx] & 0x1ff800) != 0) &&
                      (((int)(char)(&DAT_006a5f4d)
                                   [(1 - g_AiCreatureToughnessEval) * 0x5b20 + (&g_AiAttackerList)[local_a8] * 0x120]
                        << 10 & (&g_AiBlockerAssignmentList)[temp_idx] & 0x1ff800U) != 0)) {
                local_a4 = 0;
              }
            }
          }
        }
        else {
          local_a4 = 0;
        }
      }
      else {
        local_d8 = 99;
LAB_004c8311:
        local_a4 = 0;
        for (local_b4 = 0; local_b4 < local_c8; local_b4 = local_b4 + 1) {
          if ((local_c0 & 1 << ((byte)local_b4 & 0x1f)) != 0) {
            temp_idx = aiStack_4c[local_b4];
            if ((((*(byte *)((int)&g_AiBlockerAssignmentList + temp_idx * 4 + 1) & 1) == 0) ||
                ((int)(&g_AiLethalDamageFlag)[temp_idx] < (int)(&g_AiCandidateScoreList)[local_a8])) &&
               (((int)(char)(&DAT_006a5f4d)
                            [(1 - g_AiCreatureToughnessEval) * 0x5b20 + (&g_AiAttackerList)[local_a8] * 0x120] << 10
                 & (&g_AiBlockerAssignmentList)[temp_idx] & 0x1ff800U) == 0)) {
              local_a4 = local_a4 + (&DAT_0055a098)[temp_idx];
            }
            local_d8 = local_d8 - (&g_AiCandidateCardList)[temp_idx];
            if (local_d8 < 0) break;
          }
        }
      }
      if ((-1 < local_d8) && (local_c4 < local_a4)) {
        local_c4 = local_a4;
        DAT_005595d8 = local_c0;
      }
    }
    if (local_c8 == 0) {
      *(int *)(&DAT_00559738 + local_a8 * 4) = -local_8;
    }
    else {
      *(uint *)(&DAT_00559738 + local_a8 * 4) = DAT_005595d8;
    }
    local_c = local_c - local_c4;
    local_a8 = local_a8 + 1;
  } while( true );
}

/*
 * Ai_EvalAttackCandidate_General
 * Purpose: Evaluate general attacking candidate suitability.
 * Procedure:
 * 1. Calculate net board advantage gained by attacking.
 */
/*
 * Decompiled function: Ai_EvalAttackCandidate_General
 * Entry Point: 004c864d
 * Size: 6381 bytes
 */

void Ai_EvalAttackCandidate_General(uint player)

{
  int u_res;
  int val_result;
  char *pcVar3;
  int local_e4 [9];
  int local_c0;
  int local_bc;
  int local_b8;
  int local_b4;
  int local_b0;
  int local_ac [16];
  uint local_6c;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_54;
  int local_50 [16];
  int local_10;
  int local_c;
  int local_8;
  
  local_6c = 1 - spell_id;
  local_bc = 0;
  local_64 = 0;
  do {
    if (1 < local_64) {
      return;
    }
    if (local_64 == 0) {
      g_ScWillyScore = 0x19;
    }
    else {
      g_ScWillyScore = 0x1a;
    }
    Magic_CheckTurnTriggers(spell_id,g_ScWillyScore);
    for (local_60 = 0; local_60 < (int)(&g_PlayerActiveCardCount)[spell_id]; local_60 = local_60 + 1
        ) {
      if (((&g_CardSlot_ColorMask)[local_60 * 0x120 + spell_id * 0x5b20] == -1) ||
         ((char)(&g_CardSlot_ColorMask)[local_60 * 0x120 + spell_id * 0x5b20] == local_60)) {
        if ((local_bc == 0) && (g_IsAiThinking != 1)) {
          Magic_UpkeepPhase(0x14);
          local_bc = 1;
        }
        local_54 = 0;
        local_10 = 0;
        g_AiCreaturePowerEval = 0;
        local_e4[6] = 0;
        for (local_e4[7] = 0; local_e4[7] < (int)(&g_PlayerActiveCardCount)[spell_id];
            local_e4[7] = local_e4[7] + 1) {
          if ((((local_e4[7] == local_60) ||
               ((char)(&g_CardSlot_ColorMask)[spell_id * 0x5b20 + local_e4[7] * 0x120] == local_60))
              && (*(int *)(&g_CardSlot_CardId + spell_id * 0x5b20 + local_e4[7] * 0x120) != -1)) &&
             (((byte)*(int *)(&g_CardSlot_Flags + spell_id * 0x5b20 + local_e4[7] * 0x120) &
              6) == 6)) {
            (&g_AiAttackerList)[g_AiCreaturePowerEval] = local_e4[7];
            u_res = FUN_00473179(spell_id,local_e4[7],0x33,0xffffffff);
            (&g_AiCandidateScoreList)[g_AiCreaturePowerEval] = u_res;
            u_res = FUN_00473179(spell_id,local_e4[7],0x34,0xffffffff);
            (&g_AiBlockerList)[g_AiCreaturePowerEval] = u_res;
            local_b4 = 0;
            (&g_AiCombatSimulationState)[g_AiCreaturePowerEval] = 0;
            val_result = Ai_Subsystem_004c9f3a(local_64,(&g_AiBlockerList)[g_AiCreaturePowerEval]);
            if (val_result != 0) {
              local_b4 = FUN_00473179(spell_id,local_e4[7],0x32,0xffffffff);
              if (local_b4 < 0) {
                local_b4 = 0;
              }
              (&g_AiCombatSimulationState)[g_AiCreaturePowerEval] = local_b4;
              local_10 = local_10 + local_b4;
              if ((*(byte *)(&g_AiBlockerList + g_AiCreaturePowerEval) & 0x80) != 0) {
                local_54 = local_54 + local_b4;
              }
            }
            g_AiCreaturePowerEval = g_AiCreaturePowerEval + 1;
            if (g_AiCreaturePowerEval == 0x10) break;
          }
        }
        if (1 < g_AiCreaturePowerEval) {
          local_e4[6] = 1;
        }
        local_5c = 0;
        g_AiCombatScoreBuffer = 0;
        local_b0 = 0;
        for (local_e4[7] = 0; local_e4[7] < (int)(&g_PlayerActiveCardCount)[local_6c];
            local_e4[7] = local_e4[7] + 1) {
          if (((*(int *)(&g_CardSlot_CardId + local_e4[7] * 0x120 + local_6c * 0x5b20) != -1) &&
              ((char)(&g_CardSlot_ColorMask)[local_e4[7] * 0x120 + local_6c * 0x5b20] == local_60))
             && (((&g_CardSlot_Flags)[local_e4[7] * 0x120 + local_6c * 0x5b20] & 2) != 0)) {
            (&g_AiCombatDamageTable)[g_AiCombatScoreBuffer] = local_e4[7];
            val_result = FUN_00473179(local_6c,local_e4[7],0x33,local_60);
            (&g_AiCandidateCardList)[g_AiCombatScoreBuffer] =
                 val_result - *(short *)(&g_CardSlot_Power + local_e4[7] * 0x120 + local_6c * 0x5b20);
            u_res = FUN_00473179(local_6c,local_e4[7],0x34,0xffffffff);
            (&g_AiBlockerAssignmentList)[g_AiCombatScoreBuffer] = u_res;
            local_e4[4] = 0;
            (&g_AiLethalDamageFlag)[g_AiCombatScoreBuffer] = 0;
            if ((((&g_CardSlot_Flags)[local_e4[7] * 0x120 + local_6c * 0x5b20] & 0x10) == 0) &&
               (val_result = Ai_Subsystem_004c9f3a(local_64,(&g_AiBlockerAssignmentList)[g_AiCombatScoreBuffer]), val_result != 0))
            {
              local_e4[4] = FUN_00473179(local_6c,local_e4[7],0x32,local_60);
              if (local_e4[4] < 0) {
                local_e4[4] = 0;
              }
              (&g_AiLethalDamageFlag)[g_AiCombatScoreBuffer] = local_e4[4];
              local_5c = local_5c + local_e4[4];
            }
            if ((*(byte *)(&g_AiBlockerAssignmentList + g_AiCombatScoreBuffer) & 0x40) != 0) {
              local_b0 = 1;
            }
            g_AiCombatScoreBuffer = g_AiCombatScoreBuffer + 1;
            if (g_AiCombatScoreBuffer == 0x10) break;
          }
        }
        if (g_AiCombatScoreBuffer != 0) {
          for (local_b8 = 0; local_b8 < g_AiCreaturePowerEval; local_b8 = local_b8 + 1) {
            *(uint *)(&g_CardSlot_Flags + spell_id * 0x5b20 + (&g_AiAttackerList)[local_b8] * 0x120) =
                 *(uint *)(&g_CardSlot_Flags + spell_id * 0x5b20 + (&g_AiAttackerList)[local_b8] * 0x120
                          ) | 0x200;
          }
        }
        if ((g_AiCreaturePowerEval != 0) || (g_AiCombatScoreBuffer != 0)) {
          if (g_AiCombatScoreBuffer < 2) {
            if (g_AiCombatScoreBuffer == 1) {
              for (local_b8 = 0; local_b8 < g_AiCreaturePowerEval; local_b8 = local_b8 + 1) {
                val_result = Ai_Subsystem_004c9f3a(local_64,(&g_AiBlockerList)[local_b8]);
                if ((val_result != 0) &&
                   (local_50[0] = FUN_0041db67(local_6c,g_AiCombatDamageTable,(&g_AiCombatSimulationState)[local_b8],
                                               spell_id,(&g_AiAttackerList)[local_b8]),
                   local_c = local_50[0], local_50[0] != -1)) {
                  *(uint *)(&g_CardSlot_Abilities1 + local_50[0] * 0x120 + spell_id * 0x5b20) =
                       *(uint *)(&g_CardSlot_Abilities1 + local_50[0] * 0x120 + spell_id * 0x5b20) |
                       0x40000;
                  if ((*(byte *)(&g_AiBlockerList + local_b8) & 0x80) != 0) {
                    *(uint *)(&g_CardSlot_Abilities1 + local_50[0] * 0x120 + spell_id * 0x5b20) =
                         *(uint *)(&g_CardSlot_Abilities1 + local_50[0] * 0x120 + spell_id * 0x5b20)
                         | 0x80000;
                  }
                  if (local_64 == 0) {
                    *(uint *)(&g_CardSlot_Abilities1 + local_50[0] * 0x120 + spell_id * 0x5b20) =
                         *(uint *)(&g_CardSlot_Abilities1 + local_50[0] * 0x120 + spell_id * 0x5b20)
                         | 0x100000;
                  }
                }
              }
            }
            else {
              for (local_b8 = 0; local_b8 < g_AiCreaturePowerEval; local_b8 = local_b8 + 1) {
                val_result = Ai_Subsystem_004c9f3a(local_64,(&g_AiBlockerList)[local_b8]);
                if ((val_result != 0) &&
                   ((((&g_CardSlot_StateByte)[spell_id * 0x5b20 + (&g_AiAttackerList)[local_b8] * 0x120] & 2) ==
                     0 || ((*(byte *)(&g_AiBlockerList + local_b8) & 0x80) != 0)))) {
                  Mem_AllocOrFree_0041df33
                            (local_6c,(&g_AiCombatSimulationState)[local_b8],spell_id,(&g_AiAttackerList)[local_b8]);
                }
              }
            }
          }
          else if (((g_IsAiThinking == 1) || ((local_b0 == 0 && (g_CurrentTurnPhase != spell_id))))
                  || ((local_b0 != 0 && (g_CurrentTurnPhase != local_6c)))) {
            local_e4[2] = 0x7fffffff;
            local_e4[3] = 0xffff8001;
            Ai_Subsystem_004ca07b();
            for (local_68 = 0; local_68 < 0x10; local_68 = local_68 + 1) {
              local_50[local_68] = -1;
            }
            Ai_Subsystem_004ca0d9
                      (spell_id,0,local_b0,(int)local_50,local_64,0,local_e4 + 2,local_e4 + 3);
            Ai_Subsystem_004ca0d9
                      (spell_id,0,local_b0,(int)local_50,local_64,1,local_e4 + 2,local_e4 + 3);
          }
          else {
            for (local_b8 = 0; local_b8 < g_AiCreaturePowerEval; local_b8 = local_b8 + 1) {
              for (local_68 = 0; local_68 < 0x10; local_68 = local_68 + 1) {
                local_50[local_68] = -1;
              }
              local_b4 = (&g_AiCombatSimulationState)[local_b8];
              while (local_b4 != 0) {
                if (g_DuelArenaStatusFlags == 2) {
                  sprintf(&g_OverworldWorldState,s_Assign__d__sdamage_0052de74,local_b4,
                          s_trample_0052de64 +
                          (((*(byte *)(&g_AiBlockerList + local_b8) & 0x80) != 0) - 1 & 0xc));
                }
                else {
                  pcVar3 = s_trample_0052de24 +
                           (((*(byte *)(&g_AiBlockerList + local_b8) & 0x80) != 0) - 1 & 0xc);
                  val_result = local_b4;
                  u_res = Ai_FormatCardScoreString(spell_id,(&g_AiAttackerList)[local_b8]);
                  sprintf(&g_OverworldWorldState,s__s__Assign__sdamage_to_blockers__0052de34,u_res,
                          pcVar3,val_result);
                }
                Ai_Subsystem_004cad65(spell_id,(&g_AiAttackerList)[local_b8],1);
                local_8 = 0;
                while (local_8 == 0) {
                  Action_ValidateTarget_00405802
                            (g_CurrentTurnPhase,local_6c,local_6c,0x200,2,0,0,0,0,0,-1,-1,0xffffffff
                             ,0xffffffff,0,0x10,0,&g_OverworldWorldState,0,local_e4 + 8);
                  for (local_68 = 0; local_68 < g_AiCombatScoreBuffer; local_68 = local_68 + 1) {
                    if ((&g_AiCombatDamageTable)[local_68] == local_c0) {
                      local_8 = 1;
                    }
                  }
                  if ((local_8 == 0) && (g_IsAiThinking != 1)) {
                    Ai_Overworld_LogAction(s_Illegal_target__wrong_attack_gro_0052de88);
                    Sleep(0x5dc);
                    Ai_Overworld_LogAction(&DAT_0052deac);
                  }
                  if (((local_8 == 1) &&
                      (val_result = Ai_Subsystem_004cb1d6(local_e4[8],local_c0), val_result != 0)) &&
                     (local_8 = 0, g_IsAiThinking != 1)) {
                    Ai_Overworld_LogAction(s_Illegal_target__gasseous_form__0052deb0);
                    Sleep(0x5dc);
                    Ai_Overworld_LogAction(&DAT_0052ded0);
                  }
                }
                g_OverworldWorldState = 0;
                Ai_Subsystem_004cad65(spell_id,(&g_AiAttackerList)[local_b8],0);
                if (((local_e4[8] != -1) && (local_c0 != -1)) && (local_c0 != -2)) {
                  for (local_68 = 0; local_68 < g_AiCombatScoreBuffer; local_68 = local_68 + 1) {
                    if ((&g_AiCombatDamageTable)[local_68] == local_c0) {
                      if (g_AiTemporaryCardState == 0) {
                        local_e4[5] = 1;
                      }
                      else {
                        local_e4[5] = local_b4;
                      }
                      if (local_50[local_68] == -1) {
                        local_c = FUN_0041db67(local_e4[8],local_c0,local_e4[5],spell_id,
                                               (&g_AiAttackerList)[local_b8]);
                        local_50[local_68] = local_c;
                        if (local_c != -1) {
                          *(uint *)(&g_CardSlot_Abilities1 + local_c * 0x120 + spell_id * 0x5b20) =
                               *(uint *)(&g_CardSlot_Abilities1 +
                                        local_c * 0x120 + spell_id * 0x5b20) | 0x40000;
                          if ((*(byte *)(&g_AiBlockerList + local_b8) & 0x80) != 0) {
                            *(uint *)(&g_CardSlot_Abilities1 + local_c * 0x120 + spell_id * 0x5b20)
                                 = *(uint *)(&g_CardSlot_Abilities1 +
                                            local_c * 0x120 + spell_id * 0x5b20) | 0x80000;
                          }
                          if (local_64 == 0) {
                            *(uint *)(&g_CardSlot_Abilities1 + local_c * 0x120 + spell_id * 0x5b20)
                                 = *(uint *)(&g_CardSlot_Abilities1 +
                                            local_c * 0x120 + spell_id * 0x5b20) | 0x100000;
                          }
                        }
                      }
                      else {
                        *(int *)(&g_CardSlot_ConvertedManaCost +
                                spell_id * 0x5b20 + local_50[local_68] * 0x120) =
                             *(int *)(&g_CardSlot_ConvertedManaCost +
                                     spell_id * 0x5b20 + local_50[local_68] * 0x120) + local_e4[5];
                      }
                      local_b4 = local_b4 - local_e4[5];
                    }
                  }
                }
              }
            }
          }
          if (g_AiCreaturePowerEval < 2) {
            if (g_AiCreaturePowerEval == 1) {
              for (local_b8 = 0; local_b8 < g_AiCombatScoreBuffer; local_b8 = local_b8 + 1) {
                val_result = Ai_Subsystem_004c9f3a(local_64,(&g_AiBlockerAssignmentList)[local_b8]);
                if (((val_result != 0) &&
                    (local_ac[0] = FUN_0041db67(spell_id,g_AiAttackerList,(&g_AiLethalDamageFlag)[local_b8],
                                                local_6c,(&g_AiCombatDamageTable)[local_b8]),
                    local_c = local_ac[0], local_ac[0] != -1)) &&
                   (*(uint *)(&g_CardSlot_Abilities1 + local_ac[0] * 0x120 + local_6c * 0x5b20) =
                         *(uint *)(&g_CardSlot_Abilities1 + local_ac[0] * 0x120 + local_6c * 0x5b20)
                         | 0x40000, local_64 == 0)) {
                  *(uint *)(&g_CardSlot_Abilities1 + local_ac[0] * 0x120 + local_6c * 0x5b20) =
                       *(uint *)(&g_CardSlot_Abilities1 + local_ac[0] * 0x120 + local_6c * 0x5b20) |
                       0x100000;
                }
              }
            }
          }
          else if (((g_IsAiThinking == 1) ||
                   ((local_e4[6] == 0 && (g_CurrentTurnPhase != local_6c)))) ||
                  ((local_e4[6] != 0 && (g_CurrentTurnPhase != spell_id)))) {
            local_e4[0] = 0x7fffffff;
            local_e4[1] = 0xffffffff;
            Ai_Subsystem_004ca07b();
            for (local_68 = 0; local_68 < 0x10; local_68 = local_68 + 1) {
              local_ac[local_68] = -1;
            }
            Ai_Subsystem_004ca714
                      (spell_id,0,local_e4[6],(int)local_ac,local_64,0,local_e4,local_e4 + 1);
            Ai_Subsystem_004ca714
                      (spell_id,0,local_e4[6],(int)local_ac,local_64,1,local_e4,local_e4 + 1);
          }
          else {
            for (local_b8 = 0; local_b8 < g_AiCombatScoreBuffer; local_b8 = local_b8 + 1) {
              for (local_68 = 0; local_68 < 0x10; local_68 = local_68 + 1) {
                local_ac[local_68] = -1;
              }
              local_e4[4] = (&g_AiLethalDamageFlag)[local_b8];
              while (local_e4[4] != 0) {
                if (g_DuelArenaStatusFlags == 2) {
                  sprintf(&g_OverworldWorldState,s_Assign__d_damage_0052df04,local_e4[4]);
                }
                else {
                  val_result = local_e4[4];
                  u_res = Ai_FormatCardScoreString(local_6c,(&g_AiCombatDamageTable)[local_b8]);
                  sprintf(&g_OverworldWorldState,s__s__Assign_damage_to_attackers____0052ded4,u_res,
                          val_result);
                }
                Ai_Subsystem_004cadc5(local_6c,(&g_AiCombatDamageTable)[local_b8],1);
                local_8 = 0;
                while (local_8 == 0) {
                  Action_ValidateTarget_00405802
                            (g_CurrentTurnPhase,spell_id,spell_id,0x200,2,0,0,0,0,0,-1,-1,0xffffffff
                             ,0xffffffff,0,2,0,&g_OverworldWorldState,0,local_e4 + 8);
                  for (local_68 = 0; local_68 < g_AiCreaturePowerEval; local_68 = local_68 + 1) {
                    if ((&g_AiAttackerList)[local_68] == local_c0) {
                      local_8 = 1;
                    }
                  }
                  if ((local_8 == 0) && (g_IsAiThinking != 1)) {
                    Ai_Overworld_LogAction(s_Illegal_target__wrong_attack_gro_0052df18);
                    Sleep(0x5dc);
                    Ai_Overworld_LogAction(&DAT_0052df3c);
                  }
                  if (((local_8 == 1) &&
                      (val_result = Ai_Subsystem_004cb1d6(local_e4[8],local_c0), val_result != 0)) &&
                     (local_8 = 0, g_IsAiThinking != 1)) {
                    Ai_Overworld_LogAction(s_Illegal_target__gasseous_form__0052df40);
                    Sleep(0x5dc);
                    Ai_Overworld_LogAction(&DAT_0052df60);
                  }
                }
                g_OverworldWorldState = 0;
                Ai_Subsystem_004cadc5(local_6c,(&g_AiCombatDamageTable)[local_b8],0);
                if (((local_e4[8] != -1) && (local_c0 != -1)) && (local_c0 != -2)) {
                  for (local_68 = 0; local_68 < g_AiCreaturePowerEval; local_68 = local_68 + 1) {
                    if ((&g_AiAttackerList)[local_68] == local_c0) {
                      if (g_AiTemporaryCardState == 0) {
                        local_e4[5] = 1;
                      }
                      else {
                        local_e4[5] = local_e4[4];
                      }
                      if (local_ac[local_68] == -1) {
                        local_c = FUN_0041db67(spell_id,local_c0,local_e4[5],local_6c,
                                               (&g_AiCombatDamageTable)[local_b8]);
                        local_ac[local_68] = local_c;
                        if ((local_c != -1) &&
                           (*(uint *)(&g_CardSlot_Abilities1 + local_c * 0x120 + local_6c * 0x5b20)
                                 = *(uint *)(&g_CardSlot_Abilities1 +
                                            local_c * 0x120 + local_6c * 0x5b20) | 0x40000,
                           local_64 == 0)) {
                          *(uint *)(&g_CardSlot_Abilities1 + local_c * 0x120 + local_6c * 0x5b20) =
                               *(uint *)(&g_CardSlot_Abilities1 +
                                        local_c * 0x120 + local_6c * 0x5b20) | 0x100000;
                        }
                      }
                      else {
                        *(int *)(&g_CardSlot_ConvertedManaCost +
                                local_6c * 0x5b20 + local_ac[local_68] * 0x120) =
                             *(int *)(&g_CardSlot_ConvertedManaCost +
                                     local_6c * 0x5b20 + local_ac[local_68] * 0x120) + local_e4[5];
                      }
                      local_e4[4] = local_e4[4] - local_e4[5];
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    g_AiCombatScoreBuffer = 0;
    for (local_e4[7] = 0; local_e4[7] < (int)(&g_PlayerActiveCardCount)[local_6c];
        local_e4[7] = local_e4[7] + 1) {
      if ((*(int *)(&g_CardSlot_CardId + local_e4[7] * 0x120 + local_6c * 0x5b20) != -1) &&
         ((&g_CardSlot_ColorMask)[local_e4[7] * 0x120 + local_6c * 0x5b20] != -1)) {
        (&g_AiCombatDamageTable)[g_AiCombatScoreBuffer] = local_e4[7];
        val_result = FUN_00473179(local_6c,local_e4[7],0x33,local_60);
        (&g_AiCandidateCardList)[g_AiCombatScoreBuffer] =
             val_result - *(short *)(&g_CardSlot_Power + local_e4[7] * 0x120 + local_6c * 0x5b20);
        val_result = Ai_Subsystem_004cb1d6(local_6c,local_e4[7]);
        if (val_result != 0) {
          (&g_AiCandidateCardList)[g_AiCombatScoreBuffer] = 0;
        }
        g_AiCombatScoreBuffer = g_AiCombatScoreBuffer + 1;
        if (g_AiCombatScoreBuffer == 0x10) break;
      }
    }
    DAT_007006d0 = 0;
    DAT_00627860 = 0;
    if (g_IsAiThinking != 1) {
      DAT_0063ee1c = 0;
    }
    Pic_Subsystem_004475a4(spell_id);
    if (DAT_007006d0 == 0) {
      FUN_00505ea7(g_ScWillyScore);
      DAT_007006d0 = 1;
    }
    for (local_68 = 0; local_68 < g_AiCombatScoreBuffer; local_68 = local_68 + 1) {
      local_e4[7] = (&g_AiCombatDamageTable)[local_68];
      local_e4[4] = (&g_AiCandidateCardList)[local_68];
      for (local_60 = 0; local_60 < (int)(&g_PlayerActiveCardCount)[spell_id];
          local_60 = local_60 + 1) {
        if (((((*(int *)(&g_ActiveCardsInPlay + local_60 * 0x120 + spell_id * 0x5b20) ==
                DAT_006ff2e0) &&
              ((int)(char)(&g_CardSlot_Toughness)[local_60 * 0x120 + spell_id * 0x5b20] == local_6c)
              ) && (*(int *)(&g_CardSlot_OriginalCardId + local_60 * 0x120 + spell_id * 0x5b20) ==
                    local_e4[7])) &&
            (((local_64 == 0 &&
              (((&DAT_006a5f6a)[local_60 * 0x120 + spell_id * 0x5b20] & 0x10) != 0)) ||
             ((local_64 == 1 &&
              (((&DAT_006a5f6a)[local_60 * 0x120 + spell_id * 0x5b20] & 0x10) == 0)))))) &&
           ((((&DAT_006a5f6a)[local_60 * 0x120 + spell_id * 0x5b20] & 4) != 0 &&
            (((&DAT_006a5f6a)[local_60 * 0x120 + spell_id * 0x5b20] & 8) == 0)))) {
          local_e4[4] = local_e4[4] -
                        *(int *)(&g_CardSlot_ConvertedManaCost +
                                local_60 * 0x120 + spell_id * 0x5b20);
        }
      }
      for (local_60 = 0; local_60 < (int)(&g_PlayerActiveCardCount)[spell_id];
          local_60 = local_60 + 1) {
        if ((((*(int *)(&g_ActiveCardsInPlay + local_60 * 0x120 + spell_id * 0x5b20) == DAT_006ff2e0
              ) && ((int)(char)(&g_CardSlot_Toughness)[local_60 * 0x120 + spell_id * 0x5b20] ==
                    local_6c)) &&
            (*(int *)(&g_CardSlot_OriginalCardId + local_60 * 0x120 + spell_id * 0x5b20) ==
             local_e4[7])) &&
           ((((local_64 == 0 &&
              (((&DAT_006a5f6a)[local_60 * 0x120 + spell_id * 0x5b20] & 0x10) != 0)) ||
             ((local_64 == 1 &&
              (((&DAT_006a5f6a)[local_60 * 0x120 + spell_id * 0x5b20] & 0x10) == 0)))) &&
            ((((&DAT_006a5f6a)[local_60 * 0x120 + spell_id * 0x5b20] & 8) != 0 &&
             (local_e4[4] -
              ((int)(char)(&DAT_006a5f4f)[local_60 * 0x120 + spell_id * 0x5b20] +
              *(int *)(&g_CardSlot_ConvertedManaCost + local_60 * 0x120 + spell_id * 0x5b20)) < 0)))
            ))) {
          val_result = -(local_e4[4] -
                   ((int)(char)(&DAT_006a5f4f)[local_60 * 0x120 + spell_id * 0x5b20] +
                   *(int *)(&g_CardSlot_ConvertedManaCost + local_60 * 0x120 + spell_id * 0x5b20)));
          if ((int)(char)(&DAT_006a5f4f)[local_60 * 0x120 + spell_id * 0x5b20] +
              *(int *)(&g_CardSlot_ConvertedManaCost + local_60 * 0x120 + spell_id * 0x5b20) <=
              val_result) {
            val_result = (int)(char)(&DAT_006a5f4f)[local_60 * 0x120 + spell_id * 0x5b20] +
                    *(int *)(&g_CardSlot_ConvertedManaCost + local_60 * 0x120 + spell_id * 0x5b20);
          }
          Mem_AllocOrFree_0041df33
                    (local_6c,val_result,
                     (int)(char)(&g_CardSlot_DamageReceived)[local_60 * 0x120 + spell_id * 0x5b20],
                     *(int *)(&g_CardSlot_TypeFlags + local_60 * 0x120 + spell_id * 0x5b20));
          local_e4[4] = local_e4[4] -
                        ((int)(char)(&DAT_006a5f4f)[local_60 * 0x120 + spell_id * 0x5b20] +
                        *(int *)(&g_CardSlot_ConvertedManaCost +
                                local_60 * 0x120 + spell_id * 0x5b20));
        }
      }
    }
    Pic_Subsystem_004488a0();
    Pic_Subsystem_004475a4(spell_id);
    DAT_00627860 = 0;
    DAT_0063ee1c = 0;
    if (DAT_007006d0 == 0) {
      FUN_00505ea7(g_ScWillyScore);
    }
    local_64 = local_64 + 1;
  } while( true );
}

/*
 * Ai_Subsystem_004c9f3a
 * Purpose: Tactical AI engine subsystem routine (004c9f3a).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004c9f3a
 * Entry Point: 004c9f3a
 * Size: 78 bytes
 */

int Ai_Subsystem_004c9f3a(int arg1, uint arg2)

{
  int u_res;
  
  if ((arg1 == 0) && ((arg2 & 0x100) != 0)) {
    u_res = 1;
  }
  else if ((arg1 == 0) || ((arg2 & 0x100) != 0)) {
    u_res = 0;
  }
  else {
    u_res = 1;
  }
  return u_res;
}

/*
 * Ai_Overworld_EvaluateEncounterThreat
 * Purpose: Evaluate threat level of roaming overworld monster.
 * Procedure:
 * 1. Read monster archetype, deck strength, and distance to player.
 */
/*
 * Decompiled function: Ai_Overworld_EvaluateEncounterThreat
 * Entry Point: 004c9f88
 * Size: 243 bytes
 */

int Ai_Overworld_EvaluateEncounterThreat(int arg1)

{
  int local_8;
  
  for (local_8 = 0; local_8 < g_AiCombatScoreBuffer; local_8 = local_8 + 1) {
    *(uint *)(&g_CardSlot_Flags + (1 - arg1) * 0x5b20 + (&g_AiCombatDamageTable)[local_8] * 0x120) =
         *(uint *)(&g_CardSlot_Flags + (1 - arg1) * 0x5b20 + (&g_AiCombatDamageTable)[local_8] * 0x120) &
         0xfffffff7;
  }
  for (local_8 = 0; local_8 < (int)(&g_PlayerActiveCardCount)[arg1]; local_8 = local_8 + 1) {
    if (((&g_CardSlot_Flags)[arg1 * 0x5b20 + local_8 * 0x120] & 4) != 0) {
      *(uint *)(&g_CardSlot_Flags + arg1 * 0x5b20 + local_8 * 0x120) =
           *(uint *)(&g_CardSlot_Flags + arg1 * 0x5b20 + local_8 * 0x120) & 0xfffffffb;
      *(uint *)(&g_CardSlot_Flags + arg1 * 0x5b20 + local_8 * 0x120) =
           *(uint *)(&g_CardSlot_Flags + arg1 * 0x5b20 + local_8 * 0x120) | 0x40;
    }
  }
  return 1;
}

/*
 * Ai_Subsystem_004ca07b
 * Purpose: Tactical AI engine subsystem routine (004ca07b).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004ca07b
 * Entry Point: 004ca07b
 * Size: 94 bytes
 */

void Ai_Subsystem_004ca07b(void)

{
  int local_c;
  int local_8;
  
  for (local_8 = 0; local_8 < 0x10; local_8 = local_8 + 1) {
    for (local_c = 0; local_c < 0x10; local_c = local_c + 1) {
      *(int *)(&g_AiCombatRoundResult + local_c * 4 + local_8 * 0x40) = 0;
    }
  }
  return;
}

/*
 * Ai_Subsystem_004ca0d9
 * Purpose: Tactical AI engine subsystem routine (004ca0d9).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004ca0d9
 * Entry Point: 004ca0d9
 * Size: 1595 bytes
 */

/* WARNING: Removing unreachable block (ram,0x004ca67e) */
/* WARNING: Removing unreachable block (ram,0x004ca688) */

void Ai_Subsystem_004ca0d9(int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int * arg7, int * arg8)

{
  int status;
  int val_result;
  int temp_idx;
  int local_40;
  int local_3c;
  int local_38;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_1c;
  int local_10;
  int local_c;
  
  status = 1 - arg1;
  if (arg2 < g_AiCreaturePowerEval) {
    val_result = (&g_AiCombatSimulationState)[arg2];
    temp_idx = val_result + 1;
    local_3c = 1;
    for (local_28 = 0; local_28 < g_AiCombatScoreBuffer; local_28 = local_28 + 1) {
      local_3c = temp_idx * local_3c;
    }
    if (arg6 == 0) {
      if ((DAT_0067f380 + 1) * 0x100 < local_3c) {
        local_2c = 0;
        local_38 = val_result;
        local_28 = g_AiCombatScoreBuffer;
        while (local_28 = local_28 + -1, 0 < local_28) {
          if (((int)(&g_AiCandidateCardList)[local_28] < local_38) &&
             ((*(byte *)((int)&g_AiBlockerAssignmentList + local_28 * 4 + 1) & 2) == 0)) {
            local_2c = local_2c + (&g_AiCandidateCardList)[local_28];
            *(int *)(&g_AiCombatRoundResult + local_28 * 4 + arg2 * 0x40) = (&g_AiCandidateCardList)[local_28]
            ;
            local_38 = local_38 - (&g_AiCandidateCardList)[local_28];
          }
          local_2c = local_2c * temp_idx;
        }
        if (local_38 != 0) {
          local_2c = local_2c + local_38;
        }
        *(int *)(&DAT_005599e0 + arg2 * 4) = local_2c;
        Ai_Subsystem_004ca0d9(arg1,arg2 + 1,arg3,arg4,arg5,0,arg7,arg_8);
      }
      else {
        if (4999999 < local_3c) {
          local_3c = 5000000;
        }
        for (local_28 = 0; local_28 < local_3c; local_28 = local_28 + 1) {
          local_2c = local_28;
          memset(&g_AiCombatRoundResult + arg2 * 0x40,0,0x40);
          local_30 = 0;
          for (local_38 = val_result; (local_30 < g_AiCombatScoreBuffer && (0 < local_38));
              local_38 = local_38 - status) {
            status = local_2c % temp_idx;
            *(int *)(&g_AiCombatRoundResult + local_30 * 4 + arg2 * 0x40) = status;
            local_2c = local_2c / temp_idx;
            local_30 = local_30 + 1;
          }
          if (local_38 == 0) {
            *(int *)(&DAT_005599e0 + arg2 * 4) = local_28;
            Ai_Subsystem_004ca0d9(arg1,arg2 + 1,arg3,arg4,arg5,0,arg7,arg_8);
          }
        }
      }
    }
    else {
      local_2c = *(int *)(&DAT_00559918 + arg2 * 4);
      for (local_30 = 0; local_30 < g_AiCombatScoreBuffer; local_30 = local_30 + 1) {
        local_24 = local_2c % temp_idx;
        val_result = Ai_Subsystem_004cb1d6(status,(&g_AiCombatDamageTable)[local_30]);
        if (val_result != 0) {
          local_24 = 0;
        }
        if (local_24 != 0) {
          val_result = FUN_0041db67(status,(&g_AiCombatDamageTable)[local_30],local_24,arg1,(&g_AiAttackerList)[arg2]
                              );
          *(int *)(arg4 + local_30 * 4) = val_result;
          if (val_result != -1) {
            *(uint *)(&g_CardSlot_Abilities1 + arg1 * 0x5b20 + val_result * 0x120) =
                 *(uint *)(&g_CardSlot_Abilities1 + arg1 * 0x5b20 + val_result * 0x120) | 0x40000;
            if ((*(byte *)(&g_AiBlockerList + arg2) & 0x80) != 0) {
              *(uint *)(&g_CardSlot_Abilities1 + arg1 * 0x5b20 + val_result * 0x120) =
                   *(uint *)(&g_CardSlot_Abilities1 + arg1 * 0x5b20 + val_result * 0x120) | 0x80000;
            }
            if (arg5 == 0) {
              *(uint *)(&g_CardSlot_Abilities1 + arg1 * 0x5b20 + val_result * 0x120) =
                   *(uint *)(&g_CardSlot_Abilities1 + arg1 * 0x5b20 + val_result * 0x120) | 0x100000;
            }
          }
        }
        *(int *)(&g_AiCombatRoundResult + local_30 * 4 + arg2 * 0x40) = local_24;
        local_2c = local_2c / temp_idx;
      }
      Ai_Subsystem_004ca0d9(arg1,arg2 + 1,arg3,arg4,arg5,arg6,arg7,arg_8);
    }
  }
  else {
    local_c = 0;
    local_10 = (&g_PlayerCreatureCount)[status];
    for (local_28 = 0; local_28 < g_AiCombatScoreBuffer; local_28 = local_28 + 1) {
      local_1c = 0;
      local_40 = 0;
      for (local_30 = 0; local_30 < g_AiCreaturePowerEval; local_30 = local_30 + 1) {
        local_40 = local_40 + *(int *)(&g_AiCombatRoundResult + local_28 * 4 + local_30 * 0x40);
        if ((*(byte *)(&g_AiBlockerList + local_30) & 0x80) != 0) {
          local_1c = local_1c + *(int *)(&g_AiCombatRoundResult + local_28 * 4 + local_30 * 0x40);
        }
      }
      if (local_40 < (int)(&g_AiCandidateCardList)[local_28]) {
        local_c = local_c + local_40 * 2;
      }
      else {
        local_c = local_c + *(int *)(&DAT_006a5f70 +
                                    status * 0x5b20 + (&g_AiCombatDamageTable)[local_28] * 0x120) +
                  (local_40 - (&g_AiCandidateCardList)[local_28]);
        val_result = FUN_0040a305(local_40 - (&g_AiCandidateCardList)[local_28],0,local_1c);
        local_10 = local_10 - val_result;
      }
    }
    if (local_10 < 1) {
      local_10 = local_10 * -0x18 + 999;
    }
    else {
      local_10 = (((&g_PlayerCreatureCount)[status] - local_10) * 0x30) / local_10;
    }
    local_c = local_c + local_10;
    if (arg3 == 0) {
      if (*arg_8 < local_c) {
        *arg_8 = local_c;
        for (local_28 = 0; local_28 < 0x10; local_28 = local_28 + 1) {
          *(int *)(&DAT_00559918 + local_28 * 4) =
               *(int *)(&DAT_005599e0 + local_28 * 4);
        }
      }
    }
    else if (local_c < *arg7) {
      *arg7 = local_c;
      for (local_28 = 0; local_28 < 0x10; local_28 = local_28 + 1) {
        *(int *)(&DAT_00559918 + local_28 * 4) =
             *(int *)(&DAT_005599e0 + local_28 * 4);
      }
    }
  }
  return;
}

/*
 * Ai_Subsystem_004ca714
 * Purpose: Tactical AI engine subsystem routine (004ca714).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004ca714
 * Entry Point: 004ca714
 * Size: 1150 bytes
 */

void Ai_Subsystem_004ca714(int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int * arg7, int * arg8)

{
  int status;
  int val_result;
  int temp_idx;
  int local_30;
  int local_2c;
  int local_28;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_8;
  
  status = 1 - arg1;
  if (arg2 < g_AiCombatScoreBuffer) {
    if (((&g_CardSlot_Flags)[status * 0x5b20 + (&g_AiCombatDamageTable)[arg2] * 0x120] & 0x10) == 0) {
      temp_idx = (&g_AiLethalDamageFlag)[arg2];
      val_result = temp_idx + 1;
      local_2c = 1;
      for (local_18 = 0; local_18 < g_AiCreaturePowerEval; local_18 = local_18 + 1) {
        local_2c = val_result * local_2c;
      }
      if (arg6 == 0) {
        for (local_18 = 0; local_18 < local_2c; local_18 = local_18 + 1) {
          local_1c = local_18;
          local_28 = temp_idx;
          for (local_20 = 0; local_20 < g_AiCreaturePowerEval; local_20 = local_20 + 1) {
            status = local_1c % val_result;
            if (((local_2c < 0x101) || (status < 2)) || (local_28 <= status)) {
              *(int *)(&g_AiCombatRoundResult + local_20 * 4 + arg2 * 0x40) = status;
              local_1c = local_1c / val_result;
              local_28 = local_28 - status;
            }
          }
          if (local_28 == 0) {
            *(int *)(&DAT_005599e0 + arg2 * 4) = local_18;
            Ai_Subsystem_004ca714(arg1,arg2 + 1,arg3,arg4,arg5,0,arg7,arg_8);
          }
        }
      }
      else {
        local_1c = *(int *)(&DAT_00559918 + arg2 * 4);
        for (local_20 = 0; local_20 < g_AiCreaturePowerEval; local_20 = local_20 + 1) {
          local_14 = local_1c % val_result;
          temp_idx = Ai_Subsystem_004cb1d6(status,(&g_AiCombatDamageTable)[local_20]);
          if (temp_idx != 0) {
            local_14 = 0;
          }
          if (local_14 != 0) {
            temp_idx = FUN_0041db67(arg1,(&g_AiAttackerList)[local_20],local_14,status,
                                 (&g_AiCombatDamageTable)[arg2]);
            *(int *)(arg4 + local_20 * 4) = temp_idx;
            if ((temp_idx != -1) &&
               (*(uint *)(&g_CardSlot_Abilities1 + temp_idx * 0x120 + status * 0x5b20) =
                     *(uint *)(&g_CardSlot_Abilities1 + temp_idx * 0x120 + status * 0x5b20) | 0x40000,
               arg5 == 0)) {
              *(uint *)(&g_CardSlot_Abilities1 + temp_idx * 0x120 + status * 0x5b20) =
                   *(uint *)(&g_CardSlot_Abilities1 + temp_idx * 0x120 + status * 0x5b20) | 0x100000;
            }
          }
          local_1c = local_1c / val_result;
        }
        Ai_Subsystem_004ca714(arg1,arg2 + 1,arg3,arg4,arg5,arg6,arg7,arg_8);
      }
    }
    else {
      Ai_Subsystem_004ca714(arg1,arg2 + 1,arg3,arg4,arg5,arg6,arg7,arg_8);
    }
  }
  else {
    local_8 = 0;
    for (local_18 = 0; local_18 < g_AiCreaturePowerEval; local_18 = local_18 + 1) {
      local_30 = 0;
      for (local_20 = 0; local_20 < g_AiCombatScoreBuffer; local_20 = local_20 + 1) {
        local_30 = local_30 + *(int *)(&g_AiCombatRoundResult + local_18 * 4 + local_20 * 0x40);
      }
      if (local_30 < (int)(&g_AiCandidateScoreList)[local_18]) {
        local_8 = local_8 + local_30 * 2;
      }
      else {
        local_8 = local_8 + *(int *)(&DAT_006a5f70 +
                                    arg1 * 0x5b20 + (&g_AiAttackerList)[local_18] * 0x120) +
                  (local_30 - (&g_AiCandidateScoreList)[local_18]);
      }
    }
    if (arg3 == 0) {
      if (*arg_8 < local_8) {
        *arg_8 = local_8;
        for (local_18 = 0; local_18 < 0x10; local_18 = local_18 + 1) {
          *(int *)(&DAT_00559918 + local_18 * 4) =
               *(int *)(&DAT_005599e0 + local_18 * 4);
        }
      }
    }
    else if (local_8 < *arg7) {
      *arg7 = local_8;
      for (local_18 = 0; local_18 < 0x10; local_18 = local_18 + 1) {
        *(int *)(&DAT_00559918 + local_18 * 4) =
             *(int *)(&DAT_005599e0 + local_18 * 4);
      }
    }
  }
  return;
}

/*
 * Ai_Subsystem_004cab92
 * Purpose: Tactical AI engine subsystem routine (004cab92).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004cab92
 * Entry Point: 004cab92
 * Size: 467 bytes
 */

void Ai_Subsystem_004cab92(void)

{
  int status;
  int local_8;
  
  for (local_8 = 0; local_8 < 4; local_8 = local_8 + 1) {
    *(int *)(&DAT_00695eb0 + local_8 * 4) = 0;
  }
  local_8 = 0;
  while( true ) {
    status = (&g_PlayerActiveCardCount)[g_ActivePlayerPriority];
    if ((int)(&g_PlayerActiveCardCount)[g_ActivePlayerPriority] <=
        (int)(&g_PlayerActiveCardCount)[g_CurrentTurnPhase]) {
      status = (&g_PlayerActiveCardCount)[g_CurrentTurnPhase];
    }
    if (status <= local_8) break;
    if ((*(int *)(&g_CardSlot_CardId + local_8 * 0x120 + g_CurrentTurnPhase * 0x5b20) != -1) &&
       (((&g_CardSlot_Flags)[local_8 * 0x120 + g_CurrentTurnPhase * 0x5b20] & 2) != 0)) {
      (**(code **)(&g_MasterCardManaCostTable +
                  *(int *)(&g_CardSlot_CardId + local_8 * 0x120 + g_CurrentTurnPhase * 0x5b20) *
                  0x34))(g_CurrentTurnPhase,local_8,0x3b);
    }
    if ((*(int *)(&g_CardSlot_CardId + local_8 * 0x120 + g_ActivePlayerPriority * 0x5b20) != -1) &&
       ((((&g_CardSlot_Flags)[local_8 * 0x120 + g_CurrentTurnPhase * 0x5b20] & 2) != 0 ||
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId + local_8 * 0x120 + g_ActivePlayerPriority * 0x5b20) * 0x34]
         & 0x10) != 0)))) {
      (**(code **)(&g_MasterCardManaCostTable +
                  *(int *)(&g_CardSlot_CardId + local_8 * 0x120 + g_ActivePlayerPriority * 0x5b20) *
                  0x34))(g_ActivePlayerPriority,local_8,0x3b);
    }
    local_8 = local_8 + 1;
  }
  return;
}

/*
 * Ai_Subsystem_004cad65
 * Purpose: Tactical AI engine subsystem routine (004cad65).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004cad65
 * Entry Point: 004cad65
 * Size: 96 bytes
 */

void Ai_Subsystem_004cad65(int arg1, int arg2, int arg3)

{
  if (arg3 == 0) {
    *(uint *)(&g_CardSlot_Abilities1 + arg2 * 0x120 + arg1 * 0x5b20) =
         *(uint *)(&g_CardSlot_Abilities1 + arg2 * 0x120 + arg1 * 0x5b20) & 0xfffdffff;
  }
  else {
    *(uint *)(&g_CardSlot_Abilities1 + arg2 * 0x120 + arg1 * 0x5b20) =
         *(uint *)(&g_CardSlot_Abilities1 + arg2 * 0x120 + arg1 * 0x5b20) | 0x20000;
  }
  return;
}

/*
 * Ai_Subsystem_004cadc5
 * Purpose: Tactical AI engine subsystem routine (004cadc5).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004cadc5
 * Entry Point: 004cadc5
 * Size: 96 bytes
 */

void Ai_Subsystem_004cadc5(int arg1, int arg2, int arg3)

{
  if (arg3 == 0) {
    *(uint *)(&g_CardSlot_Abilities1 + arg1 * 0x5b20 + arg2 * 0x120) =
         *(uint *)(&g_CardSlot_Abilities1 + arg1 * 0x5b20 + arg2 * 0x120) & 0xfffdffff;
  }
  else {
    *(uint *)(&g_CardSlot_Abilities1 + arg1 * 0x5b20 + arg2 * 0x120) =
         *(uint *)(&g_CardSlot_Abilities1 + arg1 * 0x5b20 + arg2 * 0x120) | 0x20000;
  }
  return;
}

/*
 * Ai_Util_004cae25
 * Purpose: Tactical AI utility helper function (004cae25).
 * Procedure:
 * 1. Execute internal state operation.
 */
/*
 * Decompiled function: Ai_Util_004cae25
 * Entry Point: 004cae25
 * Size: 34 bytes
 */

void Ai_Util_004cae25(WPARAM arg1)

{
  PostMessageA(g_AiDecisionMatrix_Row,0x464,arg1,0);
  return;
}

/*
 * Ai_Subsystem_004cae47
 * Purpose: Tactical AI engine subsystem routine (004cae47).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004cae47
 * Entry Point: 004cae47
 * Size: 518 bytes
 */

int Ai_Subsystem_004cae47(int arg1, int arg2)

{
  int status;
  int val_result;
  int local_24;
  int local_20;
  int local_8;
  
  status = *(int *)(&g_CardSlot_CardId + arg2 * 0x120 + arg1 * 0x5b20);
  local_20 = FUN_00473179(arg1,arg2,0x32,0xffffffff);
  local_24 = FUN_00473179(arg1,arg2,0x33,0xffffffff);
  if (local_20 == 0) {
    local_20 = 0;
  }
  else {
    local_20 = local_20 + 5;
  }
  if (local_24 == 0) {
    local_24 = 0;
  }
  else {
    local_24 = local_24 + 3;
  }
  val_result = (*(int *)(&DAT_0051aed8 + status * 0x34) + local_20 + 2) * (local_24 + 2);
  local_8 = val_result * 5;
  if (((&DAT_0051aecc)[status * 0x34] & 0x1f) != 0) {
    local_8 = (val_result * 0xf) / 2;
  }
  if (((&DAT_0051aecd)[status * 0x34] & 2) != 0) {
    local_8 = (local_8 * 3) / 2;
  }
  if (((&g_MasterCardSubtypeTable)[status * 0x34] & 3) != 0) {
    local_8 = local_8 / 2;
  }
  if (*(code **)(&g_MasterCardManaCostTable + status * 0x34) != SpellChain_GetActiveCount) {
    local_8 = (local_8 * 3) / 2;
  }
  if ((*(uint *)(&DAT_0051aecc + status * 0x34) & 0x1c0) != 0) {
    local_8 = (local_8 * 3) / 2;
  }
  if (((&g_MasterCardSubtypeTable)[status * 0x34] & 8) != 0) {
    local_8 = local_8 * 3;
  }
  if (((&g_MasterCardSubtypeTable)[status * 0x34] & 0x10) != 0) {
    local_8 = local_8 * 3;
  }
  if (((&g_CardSlot_StateByte)[arg2 * 0x120 + arg1 * 0x5b20] & 0x80) != 0) {
    local_8 = local_8 << 1;
  }
  return local_8;
}

/*
 * Ai_Subsystem_004cb04d
 * Purpose: Tactical AI engine subsystem routine (004cb04d).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004cb04d
 * Entry Point: 004cb04d
 * Size: 393 bytes
 */

int Ai_Subsystem_004cb04d(int arg1, int arg2)

{
  int status;
  int val_result;
  int local_24;
  int local_20;
  int local_8;
  
  status = *(int *)(&g_CardSlot_CardId + arg2 * 0x120 + arg1 * 0x5b20);
  local_20 = FUN_00473179(arg1,arg2,0x32,0xffffffff);
  local_24 = FUN_00473179(arg1,arg2,0x33,0xffffffff);
  if (local_20 == 0) {
    local_20 = 0;
  }
  else {
    local_20 = local_20 + 5;
  }
  if (local_24 == 0) {
    local_24 = 0;
  }
  else {
    local_24 = local_24 + 5;
  }
  val_result = (*(int *)(&DAT_0051aed8 + status * 0x34) + local_20 + 2) * (local_24 + 2);
  local_8 = val_result * 5;
  if (((&DAT_0051aecd)[status * 0x34] & 2) != 0) {
    local_8 = (val_result * 0xf) / 2;
  }
  if (((&g_MasterCardSubtypeTable)[status * 0x34] & 3) != 0) {
    local_8 = local_8 / 2;
  }
  if (((&DAT_0051aecc)[status * 0x34] & 0x20) != 0) {
    local_8 = (local_8 * 3) / 2;
  }
  if (((&g_MasterCardSubtypeTable)[status * 0x34] & 8) != 0) {
    local_8 = local_8 * 3;
  }
  if (((&g_MasterCardSubtypeTable)[status * 0x34] & 0x10) != 0) {
    local_8 = local_8 * 3;
  }
  return local_8;
}

/*
 * Ai_Subsystem_004cb1d6
 * Purpose: Tactical AI engine subsystem routine (004cb1d6).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004cb1d6
 * Entry Point: 004cb1d6
 * Size: 237 bytes
 */

int Ai_Subsystem_004cb1d6(int arg1, int arg2)

{
  int local_c;
  int local_8;
  
  local_c = 0;
  do {
    if (1 < local_c) {
      return 0;
    }
    for (local_8 = 0; local_8 < (int)(&g_PlayerActiveCardCount)[local_c]; local_8 = local_8 + 1) {
      if ((((char)(&g_CardSlot_Toughness)[local_8 * 0x120 + local_c * 0x5b20] == arg1) &&
          (*(int *)(&g_CardSlot_OriginalCardId + local_8 * 0x120 + local_c * 0x5b20) == arg2)) &&
         (*(int *)(&g_MasterCardTypeTable +
                  *(int *)(&g_CardSlot_CardId + local_8 * 0x120 + local_c * 0x5b20) * 0x34) == 0x285
         )) {
        return 1;
      }
    }
    local_c = local_c + 1;
  } while( true );
}

/*
 * Ai_Util_004cb2d0
 * Purpose: Tactical AI utility helper function (004cb2d0).
 * Procedure:
 * 1. Execute internal state operation.
 */
/*
 * Decompiled function: Ai_Util_004cb2d0
 * Entry Point: 004cb2d0
 * Size: 21 bytes
 */

int Ai_Util_004cb2d0(void)

{
  return 0;
}

/*
 * Ai_Subsystem_004cbad0
 * Purpose: Tactical AI engine subsystem routine (004cbad0).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004cbad0
 * Entry Point: 004cbad0
 * Size: 52 bytes
 */

uint Ai_Subsystem_004cbad0(int arg1, int arg2)

{
  return *(uint *)(&g_CardSlot_Abilities1 + arg2 * 0x120 + arg1 * 0x5b20) & 0xff00;
}

/*
 * Ai_Util_004cbb04
 * Purpose: Tactical AI utility helper function (004cbb04).
 * Procedure:
 * 1. Execute internal state operation.
 */
/*
 * Decompiled function: Ai_Util_004cbb04
 * Entry Point: 004cbb04
 * Size: 47 bytes
 */

int Ai_Util_004cbb04(int arg1, int arg2)

{
  return *(int *)(&g_CardSlot_ConvertedManaCost + arg2 * 0x120 + arg1 * 0x5b20);
}

/*
 * Ai_Subsystem_004cbb33
 * Purpose: Tactical AI engine subsystem routine (004cbb33).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004cbb33
 * Entry Point: 004cbb33
 * Size: 106 bytes
 */

uint Ai_Subsystem_004cbb33(int arg1, int arg2)

{
  int status;
  uint u_temp;
  
  status = Ai_Util_004cbc36(arg1,arg2);
  if (status == -1) {
    u_temp = 0;
  }
  else if (((&g_MasterCardSubtypeTable)[status * 0x34] & 0x20) == 0) {
    u_temp = 0;
  }
  else {
    u_temp = Ai_Util_004cbb04(arg1,arg2);
    u_temp = u_temp & 0xf;
  }
  return u_temp;
}

/*
 * Ai_Util_004cbba7
 * Purpose: Tactical AI utility helper function (004cbba7).
 * Procedure:
 * 1. Execute internal state operation.
 */
/*
 * Decompiled function: Ai_Util_004cbba7
 * Entry Point: 004cbba7
 * Size: 48 bytes
 */

int Ai_Util_004cbba7(int arg1, int arg2)

{
  return (int)(char)(&g_CardSlot_ColorMask)[arg2 * 0x120 + arg1 * 0x5b20];
}

/*
 * Ai_Util_004cbbd7
 * Purpose: Tactical AI utility helper function (004cbbd7).
 * Procedure:
 * 1. Execute internal state operation.
 */
/*
 * Decompiled function: Ai_Util_004cbbd7
 * Entry Point: 004cbbd7
 * Size: 48 bytes
 */

int Ai_Util_004cbbd7(int arg1, int arg2)

{
  return (int)*(short *)(&g_CardSlot_Power + arg2 * 0x120 + arg1 * 0x5b20);
}

/*
 * Ai_Util_004cbc07
 * Purpose: Tactical AI utility helper function (004cbc07).
 * Procedure:
 * 1. Execute internal state operation.
 */
/*
 * Decompiled function: Ai_Util_004cbc07
 * Entry Point: 004cbc07
 * Size: 47 bytes
 */

int Ai_Util_004cbc07(int arg1, int arg2)

{
  return *(int *)(&g_ActiveCardsInPlay + arg2 * 0x120 + arg1 * 0x5b20);
}

/*
 * Ai_Util_004cbc36
 * Purpose: Tactical AI utility helper function (004cbc36).
 * Procedure:
 * 1. Execute internal state operation.
 */
/*
 * Decompiled function: Ai_Util_004cbc36
 * Entry Point: 004cbc36
 * Size: 47 bytes
 */

int Ai_Util_004cbc36(int arg1, int arg2)

{
  return *(int *)(&g_CardSlot_CardId + arg2 * 0x120 + arg1 * 0x5b20);
}

/*
 * Ai_Subsystem_004cbc65
 * Purpose: Tactical AI engine subsystem routine (004cbc65).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004cbc65
 * Entry Point: 004cbc65
 * Size: 106 bytes
 */

int Ai_Subsystem_004cbc65(int arg1, int arg2)

{
  int u_res;
  int val_result;
  
  if ((arg1 == -1) || (arg2 == -1)) {
    u_res = 0xffffffff;
  }
  else {
    val_result = Ai_Util_004cbc36(arg1,arg2);
    if (val_result == -1) {
      u_res = 0xffffffff;
    }
    else {
      u_res = *(int *)(&g_MasterCardTypeTable + val_result * 0x34);
    }
  }
  return u_res;
}

/*
 * Ai_Overworld_ChooseRoamDirection
 * Purpose: Choose movement direction for roaming enemy on world map.
 * Procedure:
 * 1. Calculate pathfinding vector toward player or objective.
 */
/*
 * Decompiled function: Ai_Overworld_ChooseRoamDirection
 * Entry Point: 004cbcd9
 * Size: 137 bytes
 */

int Ai_Overworld_ChooseRoamDirection(int player)

{
  int local_c;
  int local_8;
  
                    /* 0xcbcd9  3  CardTypeFromID */
  if (arg1 == -1) {
    local_8 = -1;
  }
  else {
    local_8 = -1;
    local_c = 0;
    while ((*(int *)(&g_MasterCardTypeTable + local_c * 0x34) != -1 && (local_8 == -1))) {
      if (*(int *)(&g_MasterCardTypeTable + local_c * 0x34) == arg1) {
        local_8 = local_c;
      }
      local_c = local_c + 1;
    }
  }
  return local_8;
}

/*
 * Ai_Subsystem_004cbd67
 * Purpose: Tactical AI engine subsystem routine (004cbd67).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004cbd67
 * Entry Point: 004cbd67
 * Size: 61 bytes
 */

int Ai_Subsystem_004cbd67(uint arg1)

{
  int u_res;
  
                    /* 0xcbd67  1  CardIDFromType */
  if (arg1 == 0xffffffff) {
    u_res = 0xffffffff;
  }
  else {
    u_res = *(int *)(&g_MasterCardTypeTable + (arg1 & 0xfff) * 0x34);
  }
  return u_res;
}

/*
 * Ai_Util_004cbda9
 * Purpose: Tactical AI utility helper function (004cbda9).
 * Procedure:
 * 1. Execute internal state operation.
 */
/*
 * Decompiled function: Ai_Util_004cbda9
 * Entry Point: 004cbda9
 * Size: 44 bytes
 */

uint Ai_Util_004cbda9(uint arg1)

{
  uint u_res;
  
                    /* 0xcbda9  2  CardInDeck */
  if (arg1 == 0xffffffff) {
    u_res = 0xffffffff;
  }
  else {
    u_res = arg1 & 0x4000;
  }
  return u_res;
}

/*
 * Ai_Subsystem_004cbdda
 * Purpose: Tactical AI engine subsystem routine (004cbdda).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004cbdda
 * Entry Point: 004cbdda
 * Size: 54 bytes
 */

void Ai_Subsystem_004cbdda(int arg1, int arg2)

{
                    /* 0xcbdda  8  SetCardInDeck */
  if (arg2 == 1) {
    *(uint *)(&deck + arg1 * 4) = *(uint *)(&deck + arg1 * 4) | 0x4000;
  }
  else {
    *(uint *)(&deck + arg1 * 4) = *(uint *)(&deck + arg1 * 4) & 0x8fff;
  }
  return;
}

/*
 * Ai_Subsystem_004cbe10
 * Purpose: Tactical AI engine subsystem routine (004cbe10).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004cbe10
 * Entry Point: 004cbe10
 * Size: 66 bytes
 */

bool Ai_Subsystem_004cbe10(int arg1, int arg2)

{
  return ((&g_CardSlot_Flags)[arg2 * 0x120 + arg1 * 0x5b20] & 2) != 0;
}

/*
 * Ai_Subsystem_004cbe57
 * Purpose: Tactical AI engine subsystem routine (004cbe57).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004cbe57
 * Entry Point: 004cbe57
 * Size: 283 bytes
 */

byte Ai_Subsystem_004cbe57(int arg1, int arg2)

{
  byte is_valid;
  
  is_valid = ((&DAT_006a5f3e)[arg1 * 0x5b20 + arg2 * 0x120] & 3) != 0;
  if (((&g_CardSlot_Flags)[arg1 * 0x5b20 + arg2 * 0x120] & 0x10) != 0) {
    is_valid = is_valid | 2;
  }
  if (((&g_CardSlot_Flags)[arg1 * 0x5b20 + arg2 * 0x120] & 4) != 0) {
    is_valid = is_valid | 4;
  }
  if ((&g_CardSlot_ColorMask)[arg1 * 0x5b20 + arg2 * 0x120] != -1) {
    is_valid = is_valid | 8;
  }
  if (((&g_CardSlot_Toughness)[arg1 * 0x5b20 + arg2 * 0x120] != -1) &&
     (*(int *)(&g_CardSlot_OriginalCardId + arg1 * 0x5b20 + arg2 * 0x120) != -1)) {
    is_valid = is_valid | 0x10;
  }
  return is_valid;
}

/*
 * Ai_Subsystem_004cbf72
 * Purpose: Tactical AI engine subsystem routine (004cbf72).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004cbf72
 * Entry Point: 004cbf72
 * Size: 94 bytes
 */

undefined8 Ai_Subsystem_004cbf72(int arg1, int arg2)

{
  return CONCAT44(*(int *)(&g_CardSlot_OriginalCardId + arg2 * 0x120 + arg1 * 0x5b20),
                  (int)(char)(&g_CardSlot_Toughness)[arg2 * 0x120 + arg1 * 0x5b20]);
}

/*
 * Ai_Subsystem_004cbfd0
 * Purpose: Tactical AI engine subsystem routine (004cbfd0).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004cbfd0
 * Entry Point: 004cbfd0
 * Size: 131 bytes
 */

int Ai_Subsystem_004cbfd0(int arg1, int arg2, int * arg3)

{
  if (arg3 != (int *)0x0) {
    *arg3 = (int)(char)(&g_CardSlot_DamageReceived)[arg2 * 0x120 + arg1 * 0x5b20];
    arg3[1] = *(int *)(&g_CardSlot_TypeFlags + arg2 * 0x120 + arg1 * 0x5b20);
  }
  return *(int *)(&DAT_006a5f74 + arg2 * 0x120 + arg1 * 0x5b20);
}

/*
 * Ai_Subsystem_004cc053
 * Purpose: Tactical AI engine subsystem routine (004cc053).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004cc053
 * Entry Point: 004cc053
 * Size: 111 bytes
 */

uint8_t Ai_Subsystem_004cc053(int arg1, int arg2)

{
  uint8_t u_res;
  
  if (*(int *)(&g_CardSlot_CardId + arg2 * 0x120 + arg1 * 0x5b20) == -1) {
    u_res = 0;
  }
  else {
    u_res = (&g_MasterCardColorTable)
            [*(int *)(&g_CardSlot_CardId + arg2 * 0x120 + arg1 * 0x5b20) * 0x34];
  }
  return u_res;
}

/*
 * Ai_Util_004cc0c7
 * Purpose: Tactical AI utility helper function (004cc0c7).
 * Procedure:
 * 1. Execute internal state operation.
 */
/*
 * Decompiled function: Ai_Util_004cc0c7
 * Entry Point: 004cc0c7
 * Size: 48 bytes
 */

int Ai_Util_004cc0c7(int arg1, int arg2)

{
  return (int)*(short *)(&g_CardSlot_Counters + arg2 * 0x120 + arg1 * 0x5b20);
}

/*
 * Ai_Util_004cc0f7
 * Purpose: Tactical AI utility helper function (004cc0f7).
 * Procedure:
 * 1. Execute internal state operation.
 */
/*
 * Decompiled function: Ai_Util_004cc0f7
 * Entry Point: 004cc0f7
 * Size: 48 bytes
 */

int Ai_Util_004cc0f7(int arg1, int arg2)

{
  return (int)*(short *)(&DAT_006a5f46 + arg2 * 0x120 + arg1 * 0x5b20);
}

/*
 * Ai_Subsystem_004cc127
 * Purpose: Tactical AI engine subsystem routine (004cc127).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004cc127
 * Entry Point: 004cc127
 * Size: 92 bytes
 */

int Ai_Subsystem_004cc127(int arg1, int arg2)

{
  int u_res;
  
  if (*(int *)(&g_CardSlot_Abilities2 + arg2 * 0x120 + arg1 * 0x5b20) == -1) {
    u_res = 0;
  }
  else {
    u_res = *(int *)(&g_CardSlot_Abilities2 + arg2 * 0x120 + arg1 * 0x5b20);
  }
  return u_res;
}

/*
 * Ai_Util_004cc188
 * Purpose: Tactical AI utility helper function (004cc188).
 * Procedure:
 * 1. Execute internal state operation.
 */
/*
 * Decompiled function: Ai_Util_004cc188
 * Entry Point: 004cc188
 * Size: 48 bytes
 */

int Ai_Util_004cc188(int arg1, int arg2)

{
  return (int)(char)(&DAT_006a5f4d)[arg1 * 0x5b20 + arg2 * 0x120];
}

/*
 * Ai_Util_004cc1b8
 * Purpose: Tactical AI utility helper function (004cc1b8).
 * Procedure:
 * 1. Execute internal state operation.
 */
/*
 * Decompiled function: Ai_Util_004cc1b8
 * Entry Point: 004cc1b8
 * Size: 48 bytes
 */

int Ai_Util_004cc1b8(int arg1, int arg2)

{
  return (int)(char)(&g_CardSlot_CountersBonus)[arg2 * 0x120 + arg1 * 0x5b20];
}

/*
 * Ai_Subsystem_004cc1e8
 * Purpose: Tactical AI engine subsystem routine (004cc1e8).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004cc1e8
 * Entry Point: 004cc1e8
 * Size: 110 bytes
 */

char * Ai_Subsystem_004cc1e8(int arg1, int arg2)

{
  char *pcVar1;
  
  if (*(int *)(&g_CardSlot_CardId + arg2 * 0x120 + arg1 * 0x5b20) == -1) {
    pcVar1 = &DAT_0052e5c8;
  }
  else {
    pcVar1 = s_Swamp_0051aea9 + *(int *)(&g_CardSlot_CardId + arg2 * 0x120 + arg1 * 0x5b20) * 0x34;
  }
  return pcVar1;
}

/*
 * Ai_Subsystem_004cc25b
 * Purpose: Tactical AI engine subsystem routine (004cc25b).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004cc25b
 * Entry Point: 004cc25b
 * Size: 108 bytes
 */

int Ai_Subsystem_004cc25b(int arg1, int arg2)

{
  int status;
  
  if (*(int *)(&g_CardSlot_CardId + arg2 * 0x120 + arg1 * 0x5b20) == -1) {
    status = 0;
  }
  else {
    status = (int)(char)(&DAT_0051aebf)
                       [*(int *)(&g_CardSlot_CardId + arg2 * 0x120 + arg1 * 0x5b20) * 0x34];
  }
  return status;
}

/*
 * Ai_Subsystem_004cc2cc
 * Purpose: Tactical AI engine subsystem routine (004cc2cc).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004cc2cc
 * Entry Point: 004cc2cc
 * Size: 108 bytes
 */

int Ai_Subsystem_004cc2cc(int arg1, int arg2)

{
  int status;
  
  if (*(int *)(&g_CardSlot_CardId + arg1 * 0x5b20 + arg2 * 0x120) == -1) {
    status = 0;
  }
  else {
    status = (int)(char)(&DAT_0051aec0)
                       [*(int *)(&g_CardSlot_CardId + arg1 * 0x5b20 + arg2 * 0x120) * 0x34];
  }
  return status;
}

/*
 * Ai_Subsystem_004cc33d
 * Purpose: Tactical AI engine subsystem routine (004cc33d).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004cc33d
 * Entry Point: 004cc33d
 * Size: 135 bytes
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int Ai_Subsystem_004cc33d(int arg1, int arg2, int arg3)

{
  if (arg2 == 0) {
    _DAT_006ab81c = 0;
  }
  else {
    _DAT_006ab81c = 0x10;
  }
  _DAT_006ab838 = arg3;
  DAT_006ab82e = 0xff;
  DAT_006ab82c = (&DAT_0051aebe)[arg1 * 0x34];
  _DAT_006ab84c = *(int *)(&DAT_0051aecc + arg1 * 0x34);
  _DAT_006ab814 = 0xffffffff;
  return 0x4f;
}

/*
 * Ai_Subsystem_004cc3c4
 * Purpose: Tactical AI engine subsystem routine (004cc3c4).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004cc3c4
 * Entry Point: 004cc3c4
 * Size: 52 bytes
 */

int Ai_Subsystem_004cc3c4(int arg1, int arg2)

{
  int u_res;
  
  if (g_IsAiThinking == 1) {
    u_res = 0;
  }
  else {
    u_res = Ai_EndDuel_ProcessRewards(arg1,arg2);
  }
  return u_res;
}

/*
 * Ai_Subsystem_004cc3f8
 * Purpose: Tactical AI engine subsystem routine (004cc3f8).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004cc3f8
 * Entry Point: 004cc3f8
 * Size: 53 bytes
 */

void Ai_Subsystem_004cc3f8(int arg1, int arg2, int arg3, int arg4)

{
  if (g_IsAiThinking != 1) {
    Ai_Score_InitRegister(arg1,arg2,arg3,arg4);
  }
  return;
}

/*
 * Ai_Overworld_LogAction
 * Purpose: Log AI overworld strategic decision.
 * Procedure:
 * 1. Write diagnostic message to game console.
 */
/*
 * Decompiled function: Ai_Overworld_LogAction
 * Entry Point: 004cc42d
 * Size: 40 bytes
 */

void Ai_Overworld_LogAction(char * prompt_text)

{
  strcpy(&DAT_00565830,prompt_text);
  Ai_EvalAbility_Flying(prompt_text);
  return;
}

/*
 * Ai_Subsystem_004cc455
 * Purpose: Tactical AI engine subsystem routine (004cc455).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004cc455
 * Entry Point: 004cc455
 * Size: 69 bytes
 */

int Ai_Subsystem_004cc455(int * arg1, int arg2, int arg3, int arg4, char * str_5)

{
  int u_res;
  
  if (g_IsAiThinking == 1) {
    u_res = 1;
  }
  else {
    u_res = Ai_ScoreCardPlay_Creature(arg1,0,arg2,arg3,arg4,str_5);
  }
  return u_res;
}

/*
 * Ai_Subsystem_004cc49a
 * Purpose: Tactical AI engine subsystem routine (004cc49a).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004cc49a
 * Entry Point: 004cc49a
 * Size: 71 bytes
 */

int Ai_Subsystem_004cc49a(int * arg1, int arg2, int arg3, int arg4, int arg5, char * str_6)

{
  int u_res;
  
  if (g_IsAiThinking == 1) {
    u_res = 1;
  }
  else {
    u_res = Ai_ScoreCardPlay_Creature(arg1,arg2,arg3,arg4,arg5,str_6);
  }
  return u_res;
}

/*
 * Ai_Util_004cc4e1
 * Purpose: Tactical AI utility helper function (004cc4e1).
 * Procedure:
 * 1. Execute internal state operation.
 */
/*
 * Decompiled function: Ai_Util_004cc4e1
 * Entry Point: 004cc4e1
 * Size: 41 bytes
 */

void Ai_Util_004cc4e1(int arg1)

{
  if (g_IsAiThinking != 1) {
    Ai_CalcMana_ResetPool(arg1);
  }
  return;
}

/*
 * Ai_Subsystem_004cc50a
 * Purpose: Tactical AI engine subsystem routine (004cc50a).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004cc50a
 * Entry Point: 004cc50a
 * Size: 99 bytes
 */

void Ai_Subsystem_004cc50a(int arg1, int arg2, char * str_3)

{
  if (g_IsAiThinking != 1) {
    if (g_AiCombatScore_Blocker == 0) {
      Sprite_Load_dungbutt_00484738(arg1,arg2,str_3);
    }
    else {
      Ai_CalcMana_AddSource(arg1,-1,-1);
    }
  }
  return;
}

/*
 * Ai_Deck_SelectStartingHand
 * Purpose: Evaluate mulligan decision for AI opening hand.
 * Procedure:
 * 1. Count lands and playable spells in opening hand.
 * 2. Mulligan if fewer than 2 lands or more than 5 lands.
 */
/*
 * Decompiled function: Ai_Deck_SelectStartingHand
 * Entry Point: 004cc56d
 * Size: 595 bytes
 */

int Ai_Deck_SelectStartingHand(int arg1, int arg2, int arg3, int arg4, int arg5, char * str_6, int arg7)

{
  int status;
  int local_274;
  char local_26c [600];
  int local_14;
  int local_c;
  uint local_8;
  
  if ((((g_IsAiThinking != 1) && (-1 < arg1)) && (-1 < arg2)) && (-1 < arg3)) {
    strcpy(local_26c,str_6);
    g_OverworldWorldState = 0;
    if (g_CurrentTurnPhase == arg1) {
      Ai_Subsystem_004b90de(arg2,arg3);
      strcat(&g_OverworldWorldState,&DAT_0052e5d8);
    }
    else {
      strcat(&g_OverworldWorldState,&DAT_00695e10);
      strcat(&g_OverworldWorldState,s_selects__0052e5cc);
      local_8 = 1;
      local_14 = arg7;
      for (local_c = 0; status = local_14, local_c < 1000; local_c = local_c + 1) {
        if (((local_8 != 0) && (local_26c[local_c] == ' ')) &&
           (local_14 = local_14 + -1, status == 0)) {
          local_26c[local_c] = '>';
          break;
        }
        if (local_26c[local_c] != '\n') {
          local_8 = 0;
        }
        else {
          local_8 = 1;
        }
        local_8 = (uint)(local_26c[local_c] == '\n');
      }
    }
    strcat(&g_OverworldWorldState,local_26c);
    if ((*(int *)(&g_CardSlot_CardId + arg3 * 0x120 + arg2 * 0x5b20) == -1) ||
       (*(int *)(&g_CardSlot_CardId + arg5 * 0x120 + arg4 * 0x5b20) == -1)) {
      Ai_Turn_ExecuteMainPhase(1,0xff);
    }
    if ((g_CurrentTurnPhase == arg1) && (g_AiTurnDecisionFlag == 0)) {
      local_274 = 1;
    }
    else {
      local_274 = 0;
    }
    status = Ai_EvalAbility_FirstStrike(arg2,arg3,arg4,arg5,&g_OverworldWorldState,local_274);
    if ((g_CurrentTurnPhase == arg1) && (g_AiTurnDecisionFlag == 0)) {
      arg7 = status;
    }
  }
  return arg7;
}

/*
 * Ai_Subsystem_004cc7c5
 * Purpose: Tactical AI engine subsystem routine (004cc7c5).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004cc7c5
 * Entry Point: 004cc7c5
 * Size: 79 bytes
 */

void Ai_Subsystem_004cc7c5(int arg1, int arg2)

{
  if (g_IsAiThinking != 1) {
    if (g_AiCombatScore_Blocker == 0) {
      FUN_00484df9(arg1,arg2);
    }
    else {
      Ai_CalcMana_ClearAvailable(arg1,arg2);
    }
  }
  return;
}

/*
 * Ai_Subsystem_004cc814
 * Purpose: Tactical AI engine subsystem routine (004cc814).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004cc814
 * Entry Point: 004cc814
 * Size: 107 bytes
 */

INT_PTR Ai_Subsystem_004cc814(int arg1, char * output_str, INT_PTR arg3, char * str_4, char * str_5, char * str_6)

{
  if (g_IsAiThinking != 1) {
    if (g_AiCombatScore_Blocker == 0) {
      arg3 = FUN_004854a4(arg1,output_str,arg3);
    }
    else {
      arg3 = Ai_ManaSelection_DialogProc(arg1,output_str,arg3,str_4,str_5,str_6);
    }
  }
  return arg3;
}

/*
 * Ai_Subsystem_004cc87f
 * Purpose: Tactical AI engine subsystem routine (004cc87f).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004cc87f
 * Entry Point: 004cc87f
 * Size: 95 bytes
 */

INT_PTR Ai_Subsystem_004cc87f(int arg1, char * output_str, INT_PTR arg3)

{
  if (g_IsAiThinking != 1) {
    if (g_AiCombatScore_Blocker == 0) {
      arg3 = FUN_004854a4(arg1,output_str,arg3);
    }
    else {
      arg3 = Ai_Target_HighlightCandidate(arg1,output_str,arg3);
    }
  }
  return arg3;
}

/*
 * Ai_Subsystem_004cc8de
 * Purpose: Tactical AI engine subsystem routine (004cc8de).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004cc8de
 * Entry Point: 004cc8de
 * Size: 95 bytes
 */

INT_PTR Ai_Subsystem_004cc8de(int arg1, char * output_str, INT_PTR arg3)

{
  if (g_IsAiThinking != 1) {
    if (g_AiCombatScore_Blocker == 0) {
      arg3 = FUN_00485605(arg1,output_str,arg3);
    }
    else {
      arg3 = Ai_Attack_ToggleAttacker(arg1,output_str,arg3);
    }
  }
  return arg3;
}

/*
 * Ai_Subsystem_004cc93d
 * Purpose: Tactical AI engine subsystem routine (004cc93d).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004cc93d
 * Entry Point: 004cc93d
 * Size: 65 bytes
 */

int Ai_Subsystem_004cc93d(int arg1, int arg2, int arg3, int arg4, uint arg5)

{
  if (g_IsAiThinking != 1) {
    arg4 = Ai_Quest_ProcessChoice(arg1,arg2,arg3,arg4,arg5);
  }
  return arg4;
}

/*
 * Ai_Subsystem_004cc97e
 * Purpose: Tactical AI engine subsystem routine (004cc97e).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004cc97e
 * Entry Point: 004cc97e
 * Size: 71 bytes
 */

void Ai_Subsystem_004cc97e(char * prompt_text)

{
  if (g_IsAiThinking != 1) {
    if (g_AiCombatScore_Blocker == 0) {
      FUN_00484668(prompt_text);
    }
    else {
      Ai_ChangeText_ResetState(prompt_text);
    }
  }
  return;
}

/*
 * Ai_Turn_ExecuteMainPhase
 * Purpose: Execute AI main turn phase action loop.
 * Procedure:
 * 1. Play optimal land.
 * 2. Cast highest-scoring available spells.
 * 3. Declare optimal attacks during combat.
 */
/*
 * Decompiled function: Ai_Turn_ExecuteMainPhase
 * Entry Point: 004cc9c5
 * Size: 734 bytes
 */

void Ai_Turn_ExecuteMainPhase(int arg1, int arg2)

{
  int u_res;
  int local_10;
  int local_8;
  
  Ai_Subsystem_004ccca3();
  if ((DAT_0063ee10 == 0) && (g_PlayerManaPool == -1)) {
    DAT_0063ee78 = 0;
  }
  for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
    for (local_10 = 0; local_10 < (int)(&g_PlayerActiveCardCount)[local_8]; local_10 = local_10 + 1)
    {
      if ((*(int *)(&g_CardSlot_CardId + local_10 * 0x120 + local_8 * 0x5b20) != -1) &&
         (((&g_MasterCardColorTable)
           [*(int *)(&g_CardSlot_CardId + local_10 * 0x120 + local_8 * 0x5b20) * 0x34] & 2) != 0)) {
        FUN_00473179(local_8,local_10,0x3c,0xffffffff);
      }
    }
  }
  Ai_Subsystem_004cced8();
  for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
    for (local_10 = 0; local_10 < (int)(&g_PlayerActiveCardCount)[local_8]; local_10 = local_10 + 1)
    {
      if ((*(int *)(&g_CardSlot_CardId + local_10 * 0x120 + local_8 * 0x5b20) != -1) &&
         (((&g_MasterCardColorTable)
           [*(int *)(&g_CardSlot_CardId + local_10 * 0x120 + local_8 * 0x5b20) * 0x34] & 2) != 0)) {
        FUN_00473179(local_8,local_10,0x34,0xffffffff);
        FUN_00473179(local_8,local_10,0x32,0xffffffff);
        FUN_00473179(local_8,local_10,0x33,0xffffffff);
      }
    }
  }
  if (g_IsAiThinking != 1) {
    DAT_006a4920 = 0;
    for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
      for (local_10 = 0; local_10 < (int)(&g_PlayerActiveCardCount)[local_8];
          local_10 = local_10 + 1) {
        if (*(int *)(&g_CardSlot_CardId + local_10 * 0x120 + local_8 * 0x5b20) != -1) {
          u_res = Pic_Subsystem_00447b57(local_8,local_10);
          *(int *)(&DAT_006a5f84 + local_10 * 0x120 + local_8 * 0x5b20) = u_res;
        }
      }
    }
    if (g_AiCombatScore_Blocker == 0) {
      Pic_Load_combat2_0048369c(arg1,arg2);
    }
    else {
      SendMessageA(g_MainAppHwnd,0x464,0xffff,0);
    }
  }
  return;
}

/*
 * Ai_Subsystem_004ccca3
 * Purpose: Tactical AI engine subsystem routine (004ccca3).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004ccca3
 * Entry Point: 004ccca3
 * Size: 565 bytes
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Ai_Subsystem_004ccca3(void)

{
  int local_c;
  int local_8;
  
  for (local_c = 0; local_c < 8; local_c = local_c + 1) {
    *(int *)(&DAT_006330d0 + local_c * 4) = 0;
    *(int *)(&DAT_0063edf0 + local_c * 4) = *(int *)(&DAT_006330d0 + local_c * 4);
    *(int *)(&g_AiCombatScore_Total + local_c * 4) = *(int *)(&DAT_0063edf0 + local_c * 4);
  }
  DAT_0062793c = 0xffffffff;
  _DAT_00627870 = 0xffffffff;
  DAT_00627a4c = 0xffffffff;
  g_AiTempTargetBuffer = 0xffffffff;
  DAT_0063eed4 = 0;
  _DAT_0063eed0 = 0;
  for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
    for (local_c = 0; local_c < (int)(&g_PlayerActiveCardCount)[local_8]; local_c = local_c + 1) {
      if ((((&DAT_0051aed1)
            [*(int *)(&g_CardSlot_CardId + local_c * 0x120 + local_8 * 0x5b20) * 0x34] & 0x10) != 0)
         && (((&g_CardSlot_Flags)[local_c * 0x120 + local_8 * 0x5b20] & 2) != 0)) {
        FUN_00473e69(local_8,local_c,0x7f);
      }
      if ((*(int *)(&g_MasterCardTypeTable +
                   *(int *)(&g_CardSlot_CardId + local_c * 0x120 + local_8 * 0x5b20) * 0x34) == 0xee
          ) && (((&g_CardSlot_Flags)[local_c * 0x120 + local_8 * 0x5b20] & 2) != 0)) {
        Magic_TriggerCardEvent(local_8,local_c,0x7f,0xffffffff,0xffffffff);
      }
      if ((*(int *)(&g_MasterCardTypeTable +
                   *(int *)(&g_CardSlot_CardId + local_c * 0x120 + local_8 * 0x5b20) * 0x34) == 100)
         && (((&g_CardSlot_Flags)[local_c * 0x120 + local_8 * 0x5b20] & 2) != 0)) {
        Magic_TriggerCardEvent(local_8,local_c,0x7f,0xffffffff,0xffffffff);
      }
    }
  }
  return;
}

/*
 * Ai_Subsystem_004cced8
 * Purpose: Tactical AI engine subsystem routine (004cced8).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004cced8
 * Entry Point: 004cced8
 * Size: 631 bytes
 */

void Ai_Subsystem_004cced8(void)

{
  int local_10;
  int local_c;
  int local_8;
  
  for (local_c = 0; local_c < 8; local_c = local_c + 1) {
    *(int *)(&DAT_0063ee50 + local_c * 4) = 0;
    *(int *)(&g_AiCombatScore_Attacker + local_c * 4) = *(int *)(&DAT_0063ee50 + local_c * 4);
  }
  for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
    for (local_c = 0; local_c < (int)(&g_PlayerActiveCardCount)[local_8]; local_c = local_c + 1) {
      if ((((*(int *)(&g_CardSlot_CardId + local_c * 0x120 + local_8 * 0x5b20) != -1) &&
           (((&g_MasterCardColorTable)
             [*(int *)(&g_CardSlot_CardId + local_c * 0x120 + local_8 * 0x5b20) * 0x34] & 1) != 0))
          && (((&g_CardSlot_Flags)[local_c * 0x120 + local_8 * 0x5b20] & 2) != 0)) &&
         (((&g_CardSlot_Flags)[local_c * 0x120 + local_8 * 0x5b20] & 0x20) == 0)) {
        if (*(int *)(&g_CardSlot_CardId + local_c * 0x120 + local_8 * 0x5b20) < 5) {
          (&DAT_0063ee34)
          [local_8 * 8 + *(int *)(&g_CardSlot_CardId + local_c * 0x120 + local_8 * 0x5b20)] =
               (&DAT_0063ee34)
               [local_8 * 8 + *(int *)(&g_CardSlot_CardId + local_c * 0x120 + local_8 * 0x5b20)] + 1
          ;
        }
        else if ((*(int *)(&g_CardSlot_CardId + local_c * 0x120 + local_8 * 0x5b20) <
                  g_MasterCardCount) ||
                (g_MasterCardCount + 0x10 <=
                 *(int *)(&g_CardSlot_CardId + local_c * 0x120 + local_8 * 0x5b20))) {
          *(int *)(&g_AiCombatScore_Attacker + local_8 * 0x20) = *(int *)(&g_AiCombatScore_Attacker + local_8 * 0x20) + 1;
        }
        else {
          for (local_10 = 0; local_10 < 5; local_10 = local_10 + 1) {
            if (*(int *)(&g_MasterCardTypeTable +
                        *(int *)(&g_CardSlot_CardId + local_c * 0x120 + local_8 * 0x5b20) * 0x34) ==
                (&DAT_006ff2c0)[local_10]) {
              (&DAT_0063ee34)[local_8 * 8 + local_10] = (&DAT_0063ee34)[local_8 * 8 + local_10] + 1;
            }
          }
        }
        *(int *)(&DAT_0063ee4c + local_8 * 0x20) = *(int *)(&DAT_0063ee4c + local_8 * 0x20) + 1;
      }
    }
  }
  return;
}

/*
 * Ai_Subsystem_004cd14f
 * Purpose: Tactical AI engine subsystem routine (004cd14f).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004cd14f
 * Entry Point: 004cd14f
 * Size: 73 bytes
 */

void Ai_Subsystem_004cd14f(int arg1)

{
  if (g_IsAiThinking != 1) {
    if (g_AiCombatScore_Blocker == 0) {
      FUN_00485234(arg1);
    }
    else {
      Ai_Eval_GetBestCandidate(arg1,1);
    }
  }
  return;
}

/*
 * Ai_Subsystem_004cd198
 * Purpose: Tactical AI engine subsystem routine (004cd198).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004cd198
 * Entry Point: 004cd198
 * Size: 57 bytes
 */

void Ai_Subsystem_004cd198(void)

{
  if (g_IsAiThinking != 1) {
    if (g_AiCombatScore_Blocker == 0) {
      FUN_004853c2();
    }
    else {
      Ai_Eval_ResetBestCandidate();
    }
  }
  return;
}

/*
 * Ai_Subsystem_004cd1d1
 * Purpose: Tactical AI engine subsystem routine (004cd1d1).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004cd1d1
 * Entry Point: 004cd1d1
 * Size: 61 bytes
 */

int Ai_Subsystem_004cd1d1(void)

{
  int u_res;
  
  if (g_IsAiThinking == 1) {
    u_res = 0;
  }
  else if (g_AiCombatScore_Blocker == 0) {
    u_res = FUN_0040a444();
  }
  else {
    u_res = 0;
  }
  return u_res;
}

/*
 * Ai_Subsystem_004cd20e
 * Purpose: Tactical AI engine subsystem routine (004cd20e).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004cd20e
 * Entry Point: 004cd20e
 * Size: 452 bytes
 */

int Ai_Subsystem_004cd20e(void)

{
  int u_res;
  LPVOID local_10;
  int local_c;
  int local_8;
  
  Mem_AllocOrFree_00510de0(1,s_title_pic_0052e5e0);
  Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x280,0x1e0,(int *)g_DisplaySurfaceScreen
                     ,0,0,g_AiManaColorCost_Red,g_AiManaColorCost_Green);
  FUN_00501736(0x78);
  for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
    u_res = FUN_0040a1d2(5);
    switch(u_res) {
    case 0:
      FUN_00409f99(s_decks_0016_dck_0052e5ec,local_8,1,-1);
      local_10 = (LPVOID)0x2;
      break;
    case 1:
      FUN_00409f99(s_decks_0283_dck_0052e5fc,local_8,1,-1);
      local_10 = (LPVOID)0xa;
      break;
    case 2:
      FUN_00409f99(s_decks_0150_dck_0052e60c,local_8,1,-1);
      local_10 = (LPVOID)0x10;
      break;
    case 3:
      FUN_00409f99(s_decks_0076_dck_0052e61c,local_8,1,-1);
      local_10 = (LPVOID)0x17;
      break;
    case 4:
      FUN_00409f99(s_decks_0102_dck_0052e62c,local_8,1,-1);
      local_10 = (LPVOID)0x20;
    }
  }
  DAT_0052effc = 0;
  DAT_0052eff8 = 1;
  for (local_c = 0; local_c < 0x10; local_c = local_c + 1) {
    (&DAT_006b2dd0)[local_c] = 0xffffffff;
    (&g_AiSelectedAbilityIndex)[local_c] = (&DAT_006b2dd0)[local_c];
  }
  g_AiTurnDecisionFlag = 1;
  Pic_Load_0044ef70(0,local_10);
  g_AiTurnDecisionFlag = 0;
  Ai_Subsystem_004c05ba();
  return 0;
}

/*
 * Ai_Subsystem_004cd3eb
 * Purpose: Tactical AI engine subsystem routine (004cd3eb).
 * Procedure:
 * 1. Execute decision evaluation step.
 */
/*
 * Decompiled function: Ai_Subsystem_004cd3eb
 * Entry Point: 004cd3eb
 * Size: 592 bytes
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Ai_Subsystem_004cd3eb(void)

{
  uint u_res;
  
  u_res = DAT_00520cb4 / 0x34;
  g_MasterCardCount = u_res - 0x10;
  DAT_006ff2e0 = u_res - 0x2d;
  DAT_006a2854 = u_res - 0x2c;
  DAT_00696734 = u_res - 0x2b;
  DAT_0069f6dc = u_res - 0x2a;
  _DAT_006b2540 = u_res - 0x29;
  _DAT_006b2d88 = u_res - 0x28;
  DAT_006a48e4 = u_res - 0x27;
  DAT_006a28b8 = u_res - 0x26;
  DAT_006b2d84 = u_res - 0x25;
  DAT_006a3f74 = u_res - 0x24;
  DAT_006fefac = u_res - 0x23;
  DAT_00695df4 = u_res - 0x22;
  DAT_006ff374 = u_res - 0x21;
  DAT_0068a670 = u_res - 0x20;
  DAT_006a2824 = u_res - 0x1f;
  DAT_006a4b64 = u_res - 0x1e;
  DAT_006a28ac = u_res - 0x1d;
  DAT_006a28b4 = u_res - 0x1c;
  DAT_006ff564 = u_res - 0x1b;
  DAT_006fd3f4 = u_res - 0x1a;
  DAT_006809d8 = u_res - 0x19;
  DAT_00695f14 = u_res - 0x18;
  DAT_00695edc = u_res - 0x17;
  DAT_006a49ec = u_res - 0x16;
  DAT_0068a658 = u_res - 0x15;
  DAT_006fdbd0 = u_res - 0x14;
  DAT_00701000 = u_res - 0x13;
  DAT_006b3060 = u_res - 0x12;
  DAT_00695ed0 = u_res - 0x11;
  DAT_00695e94 = 0x385;
  DAT_006a2848 = 0x386;
  DAT_0068a694 = 0x387;
  DAT_006ff2e8 = 0x388;
  DAT_0068a70c = 0x389;
  DAT_006ff2dc = 0x38a;
  _g_PlayerLifeTotals = 8;
  _DAT_00695e84 = 8;
  g_AiPlayerLifeDifferential = 0xc;
  _DAT_00695e8c = 0xc;
  _DAT_006a2830 = 0xffffffff;
  g_AiCombatDamageAssigned = 0xffffffff;
  DAT_006ff2d4 = 0xffffffff;
  g_ActivePlayerPriority = 1;
  g_CardSlot_PowerBonus = 0xffffffff;
  DAT_0063edc8 = 0x30;
  _DAT_0063ee14 = 1;
  DAT_0052244c = 2;
  return;
}


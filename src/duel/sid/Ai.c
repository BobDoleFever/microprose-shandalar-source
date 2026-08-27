/*
 * sid/Ai.c - Reconstructed MicroProse Source Module
 * Program: DUEL.EXE
 * Contained Functions: 39
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include "shandalar/shandalar.h"
/* Modular Shandalar Subsystem */

/*
 * Decompiled function: Ai_SaveGameState
 * Entry Point: 0042fbf0
 * Size: 697 bytes
 */


void Ai_SaveGameState(void)

{
  DAT_00515e60 = 0;
  FID_conflict__memcpy(&DAT_0066ab10,&DAT_006826c0,0xb640);
  FID_conflict__memcpy(&DAT_00676170,&DAT_004ff580 + DAT_00665ed0 * 0x34,0x340);
  FID_conflict__memcpy(&DAT_00513588,&DAT_006669f0,4000);
  FID_conflict__memcpy(&DAT_0050dd50,&DAT_0068f370,4000);
  FID_conflict__memcpy(&DAT_0050bb58,&DAT_0068dd10,4000);
  FID_conflict__memcpy(&DAT_0050dd10,&DAT_0068ed10,0x40);
  FID_conflict__memcpy(&DAT_0050dcc8,&DAT_0068f2e0,0x40);
  FID_conflict__memcpy(&DAT_00514e38,&DAT_0068ef50,0x40);
  FID_conflict__memcpy(&DAT_005127d8,&DAT_00666570,0x198);
  FID_conflict__memcpy(&DAT_00512970,&g_DuelPlayerLifeTotals,8);
  FID_conflict__memcpy(&DAT_00513580,&DAT_006668f0,8);
  FID_conflict__memcpy(&DAT_00514638,&DAT_0066aad0,8);
  FID_conflict__memcpy(&DAT_00514630,&DAT_006664f0,8);
  FID_conflict__memcpy(&DAT_0050f6d8,&DAT_0068ee70,0x60);
  FID_conflict__memcpy(&DAT_0050ecf0,&DAT_0068ed50,0x80);
  FID_conflict__memcpy(&DAT_00511ef0,&DAT_00690320,2000);
  FID_conflict__memcpy(&DAT_00510e30,&DAT_00681ee0,2000);
  DAT_00514eb8 = g_DuelPlayerManaPool;
  DAT_0050f9b8 = g_DuelCombatPhaseState;
  DAT_006c1214 = g_DuelCombatPhaseState;
  DAT_00514528 = DAT_0066644c;
  DAT_005126d4 = DAT_006826b0;
  DAT_0050b378 = g_DuelHumanPlayerIndex;
  FID_conflict__memcpy(&DAT_00511e70,&DAT_0068f240,0x80);
  FID_conflict__memcpy(&DAT_00514530,&DAT_0068efb0,0x100);
  FID_conflict__memcpy(&DAT_0050f840,&DAT_0068f120,0x100);
  FID_conflict__memcpy(&DAT_00514e30,&g_DuelPlayerCreatureCount,8);
  if (DAT_006764b8 < 0) {
    __assert((uint32_t *)s_ScWilly>_0_004f3c94,(uint32_t *)s_D__Newmagic_sources_sid_Ai_c_004f3c74,0x176);
  }
  DAT_0050db20 = DAT_006764b8;
  DAT_0050f6b0 = DAT_00666760;
  DAT_00511e04 = DAT_00690318;
  FID_conflict__memcpy(&DAT_0050f570,&DAT_00690b00,0x140);
  FID_conflict__memcpy(&DAT_0050f988,&DAT_00676150,0x20);
  FID_conflict__memcpy(&DAT_0050f6b8,&DAT_0068ece0,0x1c);
  FUN_004398be();
  return;
}



/*
 * Decompiled function: FUN_0042fea9
 * Entry Point: 0042fea9
 * Size: 631 bytes
 */


void FUN_0042fea9(void)

{
  FID_conflict__memcpy(&DAT_006826c0,&DAT_0066ab10,0xb640);
  FID_conflict__memcpy(&DAT_004ff580 + DAT_00665ed0 * 0x34,&DAT_00676170,0x340);
  FID_conflict__memcpy(&DAT_006669f0,&DAT_00513588,4000);
  FID_conflict__memcpy(&DAT_0068f370,&DAT_0050dd50,4000);
  FID_conflict__memcpy(&DAT_0068dd10,&DAT_0050bb58,4000);
  FID_conflict__memcpy(&DAT_0068ed10,&DAT_0050dd10,0x40);
  FID_conflict__memcpy(&DAT_0068f2e0,&DAT_0050dcc8,0x40);
  FID_conflict__memcpy(&DAT_0068ef50,&DAT_00514e38,0x40);
  FID_conflict__memcpy(&DAT_00666570,&DAT_005127d8,0x198);
  FID_conflict__memcpy(&g_DuelPlayerLifeTotals,&DAT_00512970,8);
  FID_conflict__memcpy(&DAT_006668f0,&DAT_00513580,8);
  FID_conflict__memcpy(&DAT_0066aad0,&DAT_00514638,8);
  FID_conflict__memcpy(&DAT_006664f0,&DAT_00514630,8);
  FID_conflict__memcpy(&DAT_0068ee70,&DAT_0050f6d8,0x60);
  FID_conflict__memcpy(&DAT_0068ed50,&DAT_0050ecf0,0x80);
  FID_conflict__memcpy(&DAT_00690320,&DAT_00511ef0,2000);
  FID_conflict__memcpy(&DAT_00681ee0,&DAT_00510e30,2000);
  g_DuelPlayerManaPool = DAT_00514eb8;
  g_DuelCombatPhaseState = DAT_0050f9b8;
  DAT_0066644c = DAT_00514528;
  DAT_006826b0 = DAT_005126d4;
  g_DuelHumanPlayerIndex = DAT_0050b378;
  FID_conflict__memcpy(&DAT_0068f240,&DAT_00511e70,0x80);
  FID_conflict__memcpy(&DAT_0068efb0,&DAT_00514530,0x100);
  FID_conflict__memcpy(&DAT_0068f120,&DAT_0050f840,0x100);
  FID_conflict__memcpy(&g_DuelPlayerCreatureCount,&DAT_00514e30,8);
  DAT_006764b8 = DAT_0050db20;
  DAT_00666760 = DAT_0050f6b0;
  DAT_00690318 = DAT_00511e04;
  FID_conflict__memcpy(&DAT_00690b00,&DAT_0050f570,0x140);
  FID_conflict__memcpy(&DAT_00676150,&DAT_0050f988,0x20);
  FID_conflict__memcpy(&DAT_0068ece0,&DAT_0050f6b8,0x1c);
  Mem_AllocOrFree_004398fe();
  return;
}



/*
 * Decompiled function: FUN_00430120
 * Entry Point: 00430120
 * Size: 583 bytes
 */


void FUN_00430120(void)

{
  FID_conflict__memcpy(&DAT_00676520,&DAT_006826c0,0xb640);
  FID_conflict__memcpy(&DAT_00681b60,&DAT_004ff580 + DAT_00665ed0 * 0x34,0x340);
  FID_conflict__memcpy(&DAT_0050cb80,&DAT_006669f0,4000);
  FID_conflict__memcpy(&DAT_0050fa10,&DAT_0068f370,4000);
  FID_conflict__memcpy(&DAT_00514ec0,&DAT_0068dd10,4000);
  FID_conflict__memcpy(&DAT_00514e78,&DAT_0068ed10,0x40);
  FID_conflict__memcpy(&DAT_0050f9d0,&DAT_0068f2e0,0x40);
  FID_conflict__memcpy(&DAT_0050f940,&DAT_0068ef50,0x40);
  FID_conflict__memcpy(&DAT_0050db28,&DAT_00666570,0x198);
  FID_conflict__memcpy(&DAT_0050b380,&g_DuelPlayerLifeTotals,8);
  FID_conflict__memcpy(&DAT_0050f980,&DAT_006668f0,8);
  FID_conflict__memcpy(&DAT_0050f9a8,&DAT_0066aad0,8);
  FID_conflict__memcpy(&DAT_0050f9b0,&DAT_006664f0,8);
  FID_conflict__memcpy(&DAT_00511e08,&DAT_0068ee70,0x60);
  FID_conflict__memcpy(&DAT_005109b0,&DAT_0068ed50,0x80);
  FID_conflict__memcpy(&DAT_00514640,&DAT_00690320,2000);
  FID_conflict__memcpy(&DAT_0050b388,&DAT_00681ee0,2000);
  DAT_0050f838 = g_DuelPlayerManaPool;
  DAT_00513578 = g_DuelCombatPhaseState;
  DAT_0050f9bc = DAT_0066644c;
  DAT_0050f9c8 = DAT_006826b0;
  DAT_00511e68 = g_DuelHumanPlayerIndex;
  FID_conflict__memcpy(&DAT_0050caf8,&DAT_0068f240,0x80);
  FID_conflict__memcpy(&DAT_005126d8,&DAT_0068efb0,0x100);
  FID_conflict__memcpy(&DAT_0050f738,&DAT_0068f120,0x100);
  FID_conflict__memcpy(&DAT_0050f9c0,&g_DuelPlayerCreatureCount,8);
  DAT_005126c0 = DAT_006764b8;
  DAT_0050dd08 = DAT_00666760;
  DAT_0050dcc0 = g_DuelDamageAccumulator;
  FID_conflict__memcpy(&DAT_00514e10,&DAT_0068ece0,0x1c);
  return;
}



/*
 * Decompiled function: FUN_00430367
 * Entry Point: 00430367
 * Size: 583 bytes
 */


void FUN_00430367(void)

{
  FID_conflict__memcpy(&DAT_006826c0,&DAT_00676520,0xb640);
  FID_conflict__memcpy(&DAT_004ff580 + DAT_00665ed0 * 0x34,&DAT_00681b60,0x340);
  FID_conflict__memcpy(&DAT_006669f0,&DAT_0050cb80,4000);
  FID_conflict__memcpy(&DAT_0068f370,&DAT_0050fa10,4000);
  FID_conflict__memcpy(&DAT_0068dd10,&DAT_00514ec0,4000);
  FID_conflict__memcpy(&DAT_0068ed10,&DAT_00514e78,0x40);
  FID_conflict__memcpy(&DAT_0068f2e0,&DAT_0050f9d0,0x40);
  FID_conflict__memcpy(&DAT_0068ef50,&DAT_0050f940,0x40);
  FID_conflict__memcpy(&DAT_00666570,&DAT_0050db28,0x198);
  FID_conflict__memcpy(&g_DuelPlayerLifeTotals,&DAT_0050b380,8);
  FID_conflict__memcpy(&DAT_006668f0,&DAT_0050f980,8);
  FID_conflict__memcpy(&DAT_0066aad0,&DAT_0050f9a8,8);
  FID_conflict__memcpy(&DAT_006664f0,&DAT_0050f9b0,8);
  FID_conflict__memcpy(&DAT_0068ee70,&DAT_00511e08,0x60);
  FID_conflict__memcpy(&DAT_0068ed50,&DAT_005109b0,0x80);
  FID_conflict__memcpy(&DAT_00690320,&DAT_00514640,2000);
  FID_conflict__memcpy(&DAT_00681ee0,&DAT_0050b388,2000);
  g_DuelPlayerManaPool = DAT_0050f838;
  g_DuelCombatPhaseState = DAT_00513578;
  DAT_0066644c = DAT_0050f9bc;
  DAT_006826b0 = DAT_0050f9c8;
  g_DuelHumanPlayerIndex = DAT_00511e68;
  FID_conflict__memcpy(&DAT_0068f240,&DAT_0050caf8,0x80);
  FID_conflict__memcpy(&DAT_0068efb0,&DAT_005126d8,0x100);
  FID_conflict__memcpy(&DAT_0068f120,&DAT_0050f738,0x100);
  FID_conflict__memcpy(&g_DuelPlayerCreatureCount,&DAT_0050f9c0,8);
  DAT_006764b8 = DAT_005126c0;
  DAT_00666760 = DAT_0050dd08;
  g_DuelDamageAccumulator = DAT_0050dcc0;
  FID_conflict__memcpy(&DAT_0068ece0,&DAT_00514e10,0x1c);
  return;
}



/*
 * Decompiled function: Mem_AllocOrFree_004305ae
 * Entry Point: 004305ae
 * Size: 37 bytes
 */


void Mem_AllocOrFree_004305ae(void)

{
  DAT_0050b37c = 0;
  DAT_00511600 = 99;
  return;
}



/*
 * Decompiled function: FUN_004305d3
 * Entry Point: 004305d3
 * Size: 119 bytes
 */


void FUN_004305d3(void)

{
  int slot_idx;
  
  DAT_00690c44 = 0;
  DAT_0050b37c = 0;
  DAT_0068ef98 = 0xffffffff;
  for (slot_idx = 0; slot_idx < 0x100; slot_idx = slot_idx + 1) {
    (&DAT_00511a00)[slot_idx] = 99;
  }
  FUN_0042fea9();
  if (g_DuelDebugModeFlag != 1) {
    DAT_00666400 = 0xffffffff;
  }
  return;
}



/*
 * Decompiled function: FUN_0043064a
 * Entry Point: 0043064a
 * Size: 211 bytes
 */


void FUN_0043064a(void)

{
  if (DAT_0050b37c < 0x100) {
    *(uint32_t *)(&DAT_0050f170 + DAT_0050b37c * 4) = DAT_0068f0bc;
    *(int32_t *)(&DAT_00512d78 + DAT_0050b37c * 4) =
         *(int32_t *)
          (&g_DuelCardSlot_CardId + (DAT_0068f0bc & 0xff) * 0x120 + ((DAT_0068f0bc & 0x100) >> 8) * 0x5b20);
    *(int32_t *)(&DAT_00513178 + DAT_0050b37c * 4) = DAT_004f3c6c;
    (&DAT_00511a00)[DAT_0050b37c] = DAT_0068f2c8;
    DAT_0050b37c = DAT_0050b37c + 1;
    if ((DAT_00511a00 == 99) || (DAT_00511600 == 99)) {
      DAT_0068f0bc = 0xffffffff;
    }
  }
  else {
    g_DuelHumanPlayerIndex = 1;
  }
  DAT_004f3c6c = 0;
  return;
}



/*
 * Decompiled function: Card_DispatchRulesEvent
 * Entry Point: 0043071d
 * Size: 75 bytes
 */


int32_t Card_DispatchRulesEvent(int player_id)

{
  if ((g_DuelDebugModeFlag != 1) &&
     (DAT_0068f0bc = *(uint32_t *)(&DAT_0050ed70 + (arg_1 + DAT_0050b37c) * 4),
     DAT_0068f0bc != 0xffffffff)) {
    DAT_0068f0bc = DAT_0068f0bc & 0xfff;
  }
  return 0;
}



/*
 * Decompiled function: FUN_00430768
 * Entry Point: 00430768
 * Size: 74 bytes
 */


int32_t FUN_00430768(int player_id)

{
  if ((g_DuelDebugModeFlag != 1) &&
     (DAT_00666410 = (&DAT_00511600)[DAT_0050b37c + arg_1], DAT_00666410 == 99)) {
    DAT_00666410 = 0;
  }
  return 0;
}



/*
 * Decompiled function: FUN_004307b2
 * Entry Point: 004307b2
 * Size: 108 bytes
 */


void FUN_004307b2(void)

{
  DAT_0068f0bc = *(int32_t *)(&DAT_0050ed70 + DAT_0050b37c * 4);
  DAT_0068f2c8 = (&DAT_00511600)[DAT_0050b37c];
  if ((&DAT_00511600)[DAT_0050b37c] != 99) {
    DAT_0050b37c = DAT_0050b37c + 1;
  }
  DAT_004f3c6c = 0;
  return;
}



/*
 * Decompiled function: FUN_0043081e
 * Entry Point: 0043081e
 * Size: 177 bytes
 */


void FUN_0043081e(void)

{
  int slot_idx;
  
  for (slot_idx = 0; slot_idx < DAT_0050b37c; slot_idx = slot_idx + 1) {
    (&DAT_00511600)[slot_idx] = (&DAT_00511a00)[slot_idx];
    *(int32_t *)(&DAT_0050ed70 + slot_idx * 4) = *(int32_t *)(&DAT_0050f170 + slot_idx * 4);
    *(int32_t *)(&DAT_00512978 + slot_idx * 4) = *(int32_t *)(&DAT_00512d78 + slot_idx * 4);
    *(int32_t *)(&DAT_00510a30 + slot_idx * 4) = *(int32_t *)(&DAT_00513178 + slot_idx * 4);
  }
  (&DAT_00511600)[DAT_0050b37c] = 99;
  if (DAT_00511600 == 99) {
    DAT_00515e60 = DAT_0050b37c;
  }
  DAT_0067650c = 1;
  return;
}



/*
 * Decompiled function: Mem_AllocOrFree_004308cf
 * Entry Point: 004308cf
 * Size: 21 bytes
 */


int32_t Mem_AllocOrFree_004308cf(void)

{
  return DAT_0050b37c;
}



/*
 * Decompiled function: Mem_AllocOrFree_004308e4
 * Entry Point: 004308e4
 * Size: 45 bytes
 */


void Mem_AllocOrFree_004308e4(void)

{
  if (DAT_0050b37c < 1) {
    DAT_0050b37c = 0;
  }
  else {
    DAT_0050b37c = DAT_0050b37c + -1;
  }
  return;
}



/*
 * Decompiled function: FUN_00430911
 * Entry Point: 00430911
 * Size: 2728 bytes
 */


int FUN_00430911(int player_id)

{
  int val_1;
  uint32_t uval_2;
  uint32_t uval_3;
  int val_4;
  uint32_t *arg2;
  bool bVar5;
  uint32_t local_e4;
  uint32_t local_d4 [2];
  uint8_t local_cc [160];
  uint32_t local_2c;
  int local_28;
  int local_24;
  int loop_idx;
  int color_idx;
  int target_idx;
  int player_idx;
  int card_idx;
  int match_count;
  int slot_idx;
  
  DAT_005ef980 = 1;
  match_count = 0;
  local_28 = 1 - arg_1;
  FUN_00431f41(local_d4,local_d4 + 1);
  _memset(local_cc,0,0xa0);
  loop_idx = 0;
  for (color_idx = 1; color_idx <= (int)(&g_DuelPlayerLifeTotals)[arg_1]; color_idx = color_idx + 1) {
    loop_idx = loop_idx + (int)(0x18 / (longlong)color_idx) + 0xc;
  }
  val_1 = *(int *)(&DAT_00666710 + arg_1 * 4) * loop_idx;
  loop_idx = 0;
  for (color_idx = 1; color_idx <= (int)(&g_DuelPlayerLifeTotals)[local_28]; color_idx = color_idx + 1) {
    loop_idx = loop_idx + (int)(0x18 / (longlong)color_idx) + 0xc;
  }
  match_count = ((int)(val_1 + (val_1 >> 0x1f & 7U)) >> 3) -
            ((int)(*(int *)(&DAT_00666710 + local_28 * 4) * loop_idx +
                  (*(int *)(&DAT_00666710 + local_28 * 4) * loop_idx >> 0x1f & 7U)) >> 3);
  if ((int)(&g_DuelPlayerLifeTotals)[arg_1] < 1) {
    match_count = match_count + ((&g_DuelPlayerLifeTotals)[arg_1] * 4 + -8) * 0x4b;
  }
  if ((int)(&g_DuelPlayerLifeTotals)[local_28] < 1) {
    match_count = match_count + ((&g_DuelPlayerLifeTotals)[local_28] + -2) * -0x100;
  }
  if (DAT_005ef574 != 0) {
    g_DuelCardChoicePrompt = 0;
  }
  slot_idx = 0;
  do {
    if (1 < slot_idx) {
      for (slot_idx = 0; slot_idx < 2; slot_idx = slot_idx + 1) {
        for (color_idx = 0; color_idx < (int)(&g_DuelPlayerCreatureCount)[slot_idx]; color_idx = color_idx + 1) {
          if ((1 << ((uint8_t)arg_1 & 0x1f) & (int)(char)local_cc[slot_idx * 0x50 + color_idx]) != 0) {
            match_count = match_count + 2;
          }
          if ((1 << (1 - (uint8_t)arg_1 & 0x1f) & (int)(char)local_cc[slot_idx * 0x50 + color_idx]) != 0)
          {
            match_count = match_count + -2;
          }
        }
      }
      if ((DAT_006c121c == 0) && (g_DuelDefendingPlayer == arg_1)) {
        match_count = FUN_004313b9(arg_1,match_count);
      }
      DAT_005ef980 = 0;
      return match_count;
    }
    local_28 = 1 - slot_idx;
    card_idx = -(((-(uint32_t)(g_DuelTargetCardSlot == slot_idx) & 0x30) + 0x18) *
                *(int *)(&DAT_0068f2fc + slot_idx * 0x20));
    for (color_idx = 1; color_idx < 6; color_idx = color_idx + 1) {
      for (local_24 = 1; local_24 <= *(int *)(&DAT_0068ef50 + color_idx * 4 + slot_idx * 0x20);
          local_24 = local_24 + 1) {
        card_idx = card_idx + (int)(0x30 / (longlong)local_24);
      }
    }
    for (color_idx = 0; color_idx < (int)(&g_DuelPlayerCreatureCount)[slot_idx]; color_idx = color_idx + 1) {
      if (*(int *)(&g_DuelCardSlot_CardId + color_idx * 0x120 + slot_idx * 0x5b20) != -1) {
        player_idx = *(int *)(&g_DuelCardSlot_CardId + color_idx * 0x120 + slot_idx * 0x5b20);
        if (((&g_DuelMasterCardTable)[player_idx * 0x34] & 0x80) == 0) {
          local_2c = 1;
          if (((&g_DuelMasterCardTable)[player_idx * 0x34] & 2) != 0) {
            uval_2 = Duel_TapCardForMana(slot_idx, color_idx, 0x34, 0xffffffff);
            uval_3 = Duel_TapCardForMana(slot_idx,color_idx,0x32,0xffffffff);
            target_idx = (uval_3 & 0xffffbfff) * 2;
            if ((&DAT_004ff595)[player_idx * 0x34] == '\0') {
              target_idx = 0;
            }
            val_1 = target_idx;
            uval_3 = Duel_TapCardForMana(slot_idx,color_idx,0x33,0xffffffff);
            uval_3 = uval_3 & 0xffffbfff;
            local_2c = (int)((val_1 + 3) * (uval_3 + 4)) / 2;
            if ((((&g_DuelCardSlot_Flags)[color_idx * 0x120 + slot_idx * 0x5b20] & 0x10) != 0) &&
               (g_DuelDefendingPlayer == slot_idx)) {
              local_2c = local_2c + -1;
            }
            if ((uval_2 & 0x80) != 0) {
              local_2c = (int)(local_2c * 3) / 2;
            }
            if ((uval_2 & 0x100) != 0) {
              local_2c = (int)(local_2c * 3) / 2;
            }
            if (((&DAT_004ff5a8)[player_idx * 0x34] & 3) != 0) {
              local_2c = (int)(local_2c * 3) / 2;
            }
            if ((uval_2 & 0x40) != 0) {
              local_2c = (int)((uval_3 + 1) * local_2c) / 2;
            }
            if ((uval_2 & 0x200) != 0) {
              local_2c = (int)(local_2c * 3) / 2;
            }
            if ((((DAT_006c121c == 0) && (slot_idx != arg_1)) && (g_DuelDefendingPlayer == arg_1)) &&
               (((&g_DuelCardSlot_Flags)[color_idx * 0x120 + slot_idx * 0x5b20] & 2) != 0)) {
              local_e4 = 0;
              uval_2 = Duel_TapCardForMana(slot_idx, color_idx, 0x34, 0xffffffff);
              for (local_24 = 0; local_24 < (int)(&g_DuelPlayerCreatureCount)[local_28]; local_24 = local_24 + 1)
              {
                val_4 = FUN_0048b2c9(local_28,local_24,slot_idx,color_idx,uval_2,local_d4[slot_idx]);
                if (val_4 != 0) {
                  local_e4 = 1;
                  val_4 = Duel_TapCardForMana(local_28,local_24,0x33,color_idx);
                  if ((val_1 < val_4) ||
                     (val_4 = Duel_TapCardForMana(local_28,local_24,0x32,color_idx), (int)uval_3 <= val_4)) {
                    local_e4 = 3;
                    break;
                  }
                }
              }
              if ((local_e4 & 2) == 0) {
                val_4 = *(int *)(&DAT_00666710 + local_28 * 4) * target_idx * 0x18;
                card_idx = card_idx + ((int)(val_4 + (val_4 >> 0x1f & 0xfU)) >> 4);
                if ((local_e4 == 0) && ((int)(&g_DuelPlayerLifeTotals)[local_28] <= val_1)) {
                  card_idx = card_idx + 0x100;
                }
              }
            }
            if (((&g_DuelCardSlot_Flags)[color_idx * 0x120 + slot_idx * 0x5b20] & 2) == 0) {
              if (*(code **)(&DAT_004ff5a0 + player_idx * 0x34) == FUN_00464774) {
                local_2c = 1;
              }
            }
            else {
              local_2c = local_2c * 3;
            }
            local_2c = (int)(*(int *)(&DAT_00666718 + slot_idx * 4) * local_2c +
                            ((int)(*(int *)(&DAT_00666718 + slot_idx * 4) * local_2c) >> 0x1f & 7U))
                       >> 3;
          }
          if (((&g_DuelMasterCardTable)[player_idx * 0x34] & 1) != 0) {
            if (((&g_DuelCardSlot_Flags)[color_idx * 0x120 + slot_idx * 0x5b20] & 2) == 0) {
              local_2c = 2;
            }
            else {
              bVar5 = ((&g_DuelCardSlot_Flags)[color_idx * 0x120 + slot_idx * 0x5b20] & 0x10) == 0;
              if (bVar5) {
                local_2c = 1;
              }
              else {
                local_2c = 0;
              }
              local_2c = (uint32_t)bVar5;
            }
          }
          if (((&g_DuelMasterCardTable)[player_idx * 0x34] == '@') &&
             (((&g_DuelCardSlot_Flags)[color_idx * 0x120 + slot_idx * 0x5b20] & 2) != 0)) {
            local_2c = (((char)(&DAT_004ff598)[player_idx * 0x34] * 3 + 3) * 4) / 2;
          }
          if (((((&g_DuelMasterCardTable)[player_idx * 0x34] == '\x04') &&
               (((&g_DuelCardSlot_Flags)[color_idx * 0x120 + slot_idx * 0x5b20] & 2) != 0)) &&
              ((&g_DuelCardSlot_ColorMask)[color_idx * 0x120 + slot_idx * 0x5b20] != -1)) &&
             (*(int *)(&g_DuelCardSlot_TargetSlot + color_idx * 0x120 + slot_idx * 0x5b20) != -1)) {
            local_cc[(char)(&g_DuelCardSlot_ColorMask)[color_idx * 0x120 + slot_idx * 0x5b20] * 0x50 +
                     *(int *)(&g_DuelCardSlot_TargetSlot + color_idx * 0x120 + slot_idx * 0x5b20)] =
                 local_cc[(char)(&g_DuelCardSlot_ColorMask)[color_idx * 0x120 + slot_idx * 0x5b20] * 0x50 +
                          *(int *)(&g_DuelCardSlot_TargetSlot + color_idx * 0x120 + slot_idx * 0x5b20)] |
                 (uint8_t)(1 << ((uint8_t)slot_idx & 0x1f));
          }
          if ((((&g_DuelMasterCardTable)[player_idx * 0x34] & 0x38) != 0) &&
             (((&g_DuelCardSlot_Flags)[color_idx * 0x120 + slot_idx * 0x5b20] & 2) == 0)) {
            val_1 = File_Load_Info(player_idx);
            local_2c = val_1 * 0xc;
          }
          if ((((&g_DuelMasterCardTable)[player_idx * 0x34] & 4) != 0) &&
             (((&g_DuelCardSlot_Flags)[color_idx * 0x120 + slot_idx * 0x5b20] & 2) == 0)) {
            local_2c = 3;
          }
          card_idx = card_idx + local_2c;
          if (((DAT_005ef574 & 2) != 0) && (slot_idx + 2U == DAT_005ef574)) {
            FUN_0044a5a4(slot_idx,color_idx);
            Str_CopyFast((uint32_t *)&g_DuelCardChoicePrompt,(uint32_t *)&DAT_004f3ca0);
            arg2 = (uint32_t *)__itoa(local_2c,&DAT_005126c8,10);
            Str_CopyFast((uint32_t *)&g_DuelCardChoicePrompt,arg2);
            Str_CopyFast((uint32_t *)&g_DuelCardChoicePrompt,(uint32_t *)&DAT_004f3ca4);
          }
        }
      }
    }
    (&DAT_0068ecb8)[slot_idx] = card_idx;
    if (slot_idx == arg_1) {
      match_count = match_count + card_idx;
    }
    else {
      match_count = match_count - card_idx;
    }
    slot_idx = slot_idx + 1;
  } while( true );
}



/*
 * Decompiled function: FUN_004313b9
 * Entry Point: 004313b9
 * Size: 2380 bytes
 */


int FUN_004313b9(int arg1,int arg2)

{
  int x;
  int val_1;
  int val_2;
  int val_3;
  int local_1c0;
  int local_1bc;
  uint32_t local_1b8;
  int local_1b4;
  int local_1b0;
  uint32_t local_1a8;
  int local_1a4;
  int local_1a0;
  int local_19c;
  uint32_t local_198;
  int aiStack_194 [16];
  int aiStack_154 [24];
  int local_f4;
  int aiStack_f0 [16];
  int local_b0;
  char acStack_ac [80];
  int local_5c;
  int aiStack_58 [16];
  int target_idx;
  int player_idx;
  int card_idx;
  char acStack_c [8];
  
  x = 1 - arg1;
  FUN_00431f41(&local_1a8,(uint32_t *)0x0);
  for (local_1a0 = 0; local_1a0 < 8; local_1a0 = local_1a0 + 1) {
    acStack_c[local_1a0] = (&DAT_0068ed10)[local_1a0 * 4 + x * 0x20];
    *(int32_t *)(&DAT_0068ed10 + local_1a0 * 4 + x * 0x20) =
         *(int32_t *)(&DAT_0068ef50 + local_1a0 * 4 + x * 0x20);
  }
  for (player_idx = 0; player_idx < 8; player_idx = player_idx + 1) {
    aiStack_154[player_idx * 3 + 1] = -1;
  }
  card_idx = 0;
  for (local_1b0 = 0; local_1b0 < (int)(&g_DuelPlayerCreatureCount)[arg1]; local_1b0 = local_1b0 + 1) {
    if (((*(int *)(&g_DuelCardSlot_CardId + local_1b0 * 0x120 + arg1 * 0x5b20) != -1) &&
        ((*(uint32_t *)(&g_DuelCardSlot_Flags + local_1b0 * 0x120 + arg1 * 0x5b20) & 0x402) != 0)) &&
       (((&g_DuelMasterCardTable)[*(int *)(&g_DuelCardSlot_CardId + local_1b0 * 0x120 + arg1 * 0x5b20) * 0x34] & 2) !=
        0)) {
      acStack_ac[local_1b0] = (char)card_idx;
      val_1 = Duel_TapCardForMana(arg1,local_1b0,0x32,0xffffffff);
      aiStack_f0[card_idx] = val_1;
      val_1 = Duel_TapCardForMana(arg1,local_1b0,0x33,0xffffffff);
      aiStack_194[card_idx] = val_1;
      aiStack_58[card_idx] = *(int *)(&DAT_00682700 + local_1b0 * 0x120 + arg1 * 0x5b20);
      card_idx = card_idx + 1;
    }
  }
  for (local_1a0 = 0; local_1a0 < (int)(&g_DuelPlayerCreatureCount)[x]; local_1a0 = local_1a0 + 1) {
    local_19c = *(int *)(&g_DuelCardSlot_CardId + local_1a0 * 0x120 + x * 0x5b20);
    if (((local_19c != -1) && (((&g_DuelMasterCardTable)[local_19c * 0x34] & 2) != 0)) &&
       ((((&g_DuelCardSlot_Flags)[local_1a0 * 0x120 + x * 0x5b20] & 2) != 0 &&
        (((&DAT_004ff595)[local_19c * 0x34] != '\0' ||
         (((&DAT_006826f9)[local_1a0 * 0x120 + x * 0x5b20] & 8) != 0)))))) {
      local_1c0 = Duel_TapCardForMana(x,local_1a0,0x32,0xffffffff);
      local_1bc = Duel_TapCardForMana(x,local_1a0,0x33,0xffffffff);
      if (g_DuelTargetPlayer == x) {
        if (((&DAT_004ff5a8)[local_19c * 0x34] & 8) != 0) {
          val_1 = (**(code **)(&DAT_004ff5a0 + local_19c * 0x34))(x,local_1a0,0x39);
          local_1c0 = local_1c0 + val_1;
        }
        if (((&DAT_004ff5a8)[local_19c * 0x34] & 0x10) != 0) {
          val_1 = (**(code **)(&DAT_004ff5a0 + local_19c * 0x34))(x,local_1a0,0x3a);
          local_1bc = local_1bc + val_1;
        }
      }
      local_1b0 = 0;
LAB_004317d2:
      if (local_1b0 < 8) {
        if (local_1c0 <= aiStack_154[local_1b0 * 3 + 1]) goto LAB_004317cc;
        for (player_idx = 7; local_1b0 < player_idx; player_idx = player_idx + -1) {
          aiStack_154[player_idx * 3] = aiStack_154[player_idx * 3 + -3];
          aiStack_154[player_idx * 3 + 1] = aiStack_154[player_idx * 3 + -2];
          aiStack_154[player_idx * 3 + 2] = aiStack_154[player_idx * 3 + -1];
        }
        aiStack_154[local_1b0 * 3] = local_1a0;
        aiStack_154[local_1b0 * 3 + 1] = local_1c0;
        aiStack_154[local_1b0 * 3 + 2] = local_1bc;
      }
    }
  }
  local_1a4 = 0;
  player_idx = 0;
  do {
    if ((7 < player_idx) || (aiStack_154[player_idx * 3 + 1] == -1)) {
      if (((int)(&g_DuelPlayerLifeTotals)[arg1] <= local_1a4) && (0 < (int)(&g_DuelPlayerLifeTotals)[x])) {
        arg2 = arg2 + -0x100;
      }
      for (local_1a0 = 0; local_1a0 < 8; local_1a0 = local_1a0 + 1) {
        *(int *)(&DAT_0068ed10 + local_1a0 * 4 + x * 0x20) = (int)acStack_c[local_1a0];
      }
      return arg2;
    }
    local_1a0 = aiStack_154[player_idx * 3];
    local_198 = Duel_TapCardForMana(x,local_1a0,0x34,0xffffffff);
    val_1 = aiStack_154[player_idx * 3 + 1];
    val_3 = aiStack_154[player_idx * 3 + 2];
    local_1b4 = 0;
    local_1b8 = 0;
    local_f4 = 0;
    local_5c = 0x7fff;
    for (local_1b0 = 0; local_1b0 < (int)(&g_DuelPlayerCreatureCount)[arg1]; local_1b0 = local_1b0 + 1) {
      if (((*(int *)(&g_DuelCardSlot_CardId + local_1b0 * 0x120 + arg1 * 0x5b20) != -1) &&
          (((&g_DuelCardSlot_Flags)[local_1b0 * 0x120 + arg1 * 0x5b20] & 2) != 0)) &&
         (((&g_DuelMasterCardTable)[*(int *)(&g_DuelCardSlot_CardId + local_1b0 * 0x120 + arg1 * 0x5b20) * 0x34] & 2)
          != 0)) {
        local_f4 = (int)acStack_ac[local_1b0];
        target_idx = aiStack_f0[local_f4];
        local_b0 = aiStack_194[local_f4];
        val_2 = FUN_0048af80(arg1,local_1b0);
        if (((*(uint32_t *)(&g_DuelCardSlot_Flags + local_1b0 * 0x120 + arg1 * 0x5b20) &
             (-(uint32_t)(val_2 == 0) & 4) + 8) == 0) &&
           (val_2 = FUN_0048b2c9(arg1,local_1b0,x,local_1a0,local_198,local_1a8), val_2 != 0)) {
          local_1b8 = 1;
          if ((val_1 < local_b0) || (val_3 <= target_idx)) {
            local_1b8 = 3;
            *(uint32_t *)(&g_DuelCardSlot_Flags + local_1b0 * 0x120 + arg1 * 0x5b20) =
                 *(uint32_t *)(&g_DuelCardSlot_Flags + local_1b0 * 0x120 + arg1 * 0x5b20) | 8;
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
      val_3 = *(int *)(&DAT_00666710 + arg1 * 4) * val_1 * 0x18;
      val_3 = val_3 + (val_3 >> 0x1f & 3U);
      val_2 = FUN_0049aa14((&g_DuelPlayerLifeTotals)[arg1] + 1,1,99);
      val_3 = (int)(CONCAT44(val_3 >> 0x1f,val_3 >> 2) / (longlong)val_2);
      val_2 = (int)(*(int *)(&DAT_00666718 + arg1 * 4) * local_5c +
                   (*(int *)(&DAT_00666718 + arg1 * 4) * local_5c >> 0x1f & 0xfU)) >> 4;
      if ((local_1b8 == 0) || ((val_3 < val_2 && (val_1 + local_1a4 < (int)(&g_DuelPlayerLifeTotals)[arg1]))))
      {
        local_1a4 = local_1a4 + val_1;
        arg2 = arg2 - val_3;
      }
      else {
        arg2 = arg2 - val_2;
        *(uint32_t *)(&g_DuelCardSlot_Flags + local_1b4 * 0x120 + arg1 * 0x5b20) =
             *(uint32_t *)(&g_DuelCardSlot_Flags + local_1b4 * 0x120 + arg1 * 0x5b20) | 8;
      }
    }
    player_idx = player_idx + 1;
  } while( true );
LAB_004317cc:
  local_1b0 = local_1b0 + 1;
  goto LAB_004317d2;
}



/*
 * Decompiled function: Ai_ChooseBlockers
 * Entry Point: 00431d05
 * Size: 572 bytes
 */


int32_t Ai_ChooseBlockers(int arg1,int arg2)

{
  uint32_t *u_ptr_1;
  int player_idx;
  int card_idx;
  uint32_t match_count;
  int slot_idx;
  
  Mem_AllocOrFree_004d9630((uint32_t *)&g_DuelCardChoicePrompt,(uint32_t *)&DAT_004f3ca8);
  u_ptr_1 = (uint32_t *)__itoa(arg2,&DAT_005126c8,10);
  Str_CopyFast((uint32_t *)&g_DuelCardChoicePrompt,u_ptr_1);
  Str_CopyFast((uint32_t *)&g_DuelCardChoicePrompt,(uint32_t *)&DAT_004f3cac);
  u_ptr_1 = (uint32_t *)__itoa(g_DuelPlayerLifeTotals,&DAT_005126c8,10);
  Str_CopyFast((uint32_t *)&g_DuelCardChoicePrompt,u_ptr_1);
  Str_CopyFast((uint32_t *)&g_DuelCardChoicePrompt,(uint32_t *)&DAT_004f3cb0);
  u_ptr_1 = (uint32_t *)__itoa(DAT_00681eac,&DAT_005126c8,10);
  Str_CopyFast((uint32_t *)&g_DuelCardChoicePrompt,u_ptr_1);
  Str_CopyFast((uint32_t *)&g_DuelCardChoicePrompt,(uint32_t *)s_____004f3cb4);
  slot_idx = 0;
  while( true ) {
    if (arg1 == 0) {
      card_idx = DAT_0050b37c;
    }
    else {
      card_idx = DAT_00515e60;
    }
    if (card_idx <= slot_idx) break;
    if (arg1 == 0) {
      match_count = *(uint32_t *)(&DAT_0050f170 + slot_idx * 4);
    }
    else {
      match_count = *(uint32_t *)(&DAT_0050ed70 + slot_idx * 4);
    }
    if (match_count != 0xffffffff) {
      if ((match_count & 0x1000) != 0) {
        Str_CopyFast((uint32_t *)&g_DuelCardChoicePrompt,(uint32_t *)s_Cast_004f3cbc);
      }
      if ((match_count & 0x2000) != 0) {
        Str_CopyFast((uint32_t *)&g_DuelCardChoicePrompt,(uint32_t *)&DAT_004f3cc4);
      }
      if ((match_count & 0x4000) != 0) {
        Str_CopyFast((uint32_t *)&g_DuelCardChoicePrompt,(uint32_t *)s____target_004f3ccc);
      }
      if ((match_count & 0x100) == 0) {
        Str_CopyFast((uint32_t *)&g_DuelCardChoicePrompt,(uint32_t *)&DAT_004f3cd8);
      }
      if ((char)match_count == -1) {
        Str_CopyFast((uint32_t *)&g_DuelCardChoicePrompt,(uint32_t *)s_Player_004f3cdc);
      }
      else {
        if (arg1 == 0) {
          player_idx = *(int *)(&DAT_00512d78 + slot_idx * 4);
        }
        else {
          player_idx = *(int *)(&DAT_00512978 + slot_idx * 4);
        }
        Str_CopyFast((uint32_t *)&g_DuelCardChoicePrompt,(uint32_t *)(s_Swamp_004ff581 + player_idx * 0x34));
      }
      Str_CopyFast((uint32_t *)&g_DuelCardChoicePrompt,(uint32_t *)&DAT_004f3ce4);
    }
    slot_idx = slot_idx + 1;
  }
  Ai_Subsystem_004cc56d(0,0,0,-1,-1,&g_DuelCardChoicePrompt,0);
  return 0;
}



/*
 * Decompiled function: FUN_00431f41
 * Entry Point: 00431f41
 * Size: 155 bytes
 */


void FUN_00431f41(uint32_t *arg1,uint32_t *arg2)

{
  int card_idx;
  uint32_t match_count;
  uint32_t slot_idx;
  
  match_count = 0;
  slot_idx = 0;
  for (card_idx = 1; card_idx < 6; card_idx = card_idx + 1) {
    if (0 < *(int *)(&DAT_0068ef70 + card_idx * 4)) {
      slot_idx = slot_idx | 1 << ((char)card_idx - 1U & 0x1f);
    }
    if (0 < *(int *)(&DAT_0068ef50 + card_idx * 4)) {
      match_count = match_count | 1 << ((char)card_idx - 1U & 0x1f);
    }
  }
  if (arg1 != (uint32_t *)0x0) {
    *arg1 = slot_idx;
  }
  if (arg2 != (uint32_t *)0x0) {
    *arg2 = match_count;
  }
  return;
}



/*
 * Decompiled function: Mem_AllocOrFree_00431fe0
 * Entry Point: 00431fe0
 * Size: 21 bytes
 */


int32_t Mem_AllocOrFree_00431fe0(void)

{
  return 0;
}



/*
 * Decompiled function: FUN_004327e0
 * Entry Point: 004327e0
 * Size: 66 bytes
 */


int32_t FUN_004327e0(void)

{
  ShowWindow(DAT_005f67ec,5);
  BringWindowToTop(DAT_005f67ec);
  SetFocus(DAT_005f67ec);
  DAT_0068eed8 = 0;
  return 0;
}



/*
 * Decompiled function: FUN_00432822
 * Entry Point: 00432822
 * Size: 54 bytes
 */


int32_t FUN_00432822(void)

{
  DAT_0068eed8 = 1;
  ShowWindow(DAT_005f67ec,0);
  SetFocus(g_DuelMainHwnd);
  return 0;
}



/*
 * Decompiled function: FUN_00432860
 * Entry Point: 00432860
 * Size: 80 bytes
 */


int FUN_00432860(int player_id)

{
  int val_1;
  
  if ((arg_1 < 0) || (9 < arg_1)) {
    if ((arg_1 < 10) || (0xf < arg_1)) {
      val_1 = 0;
    }
    else {
      val_1 = arg_1 + 0x57;
    }
  }
  else {
    val_1 = arg_1 + 0x30;
  }
  return val_1;
}



/*
 * Decompiled function: FUN_004328ba
 * Entry Point: 004328ba
 * Size: 329 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_004328ba(int player_id)

{
  int val_1;
  uint32_t slot_idx;
  
  DAT_00515e80 = 1;
  val_1 = Mem_AllocOrFree_00432c72();
  if (val_1 == -1) {
    val_1 = -1;
  }
  else {
    if (arg_1 == -1) {
      Mem_AllocOrFree_004d9630((uint32_t *)&g_DuelCardChoicePrompt,(uint32_t *)&DAT_004f4458);
      _DAT_0068f0c0 = 0;
      for (slot_idx = 0; slot_idx < 10; slot_idx = slot_idx + 1) {
        s_D_MAGIC0_SVE_004f4350[7] = FUN_00432860(slot_idx);
        val_1 = FUN_00432a0b(s_D_MAGIC0_SVE_004f4350,1);
        if (val_1 != 0) {
          _DAT_0068f0c0 = _DAT_0068f0c0 | 1 << ((uint8_t)slot_idx & 0x1f);
        }
      }
      DAT_006669e0 = 0;
      if ((_DAT_0068f0c0 & 1) == 0) {
        DAT_006669e0 = -1;
      }
    }
    else {
      DAT_006669e0 = arg_1;
    }
    if (DAT_006669e0 != -1) {
      s_D_MAGIC0_SVE_004f4350[7] = FUN_00432860(DAT_006669e0);
      val_1 = FUN_00432a0b(s_D_MAGIC0_SVE_004f4350,0);
      if (val_1 == 0) {
        DAT_006669e0 = -1;
      }
    }
    val_1 = DAT_006669e0;
    if (DAT_006669e0 == -1) {
                    /* WARNING: Subroutine does not return */
      _exit(1);
    }
  }
  return val_1;
}



/*
 * Decompiled function: FUN_00432a0b
 * Entry Point: 00432a0b
 * Size: 178 bytes
 */


uint32_t FUN_00432a0b(char *filepath,int arg2)

{
  uint32_t uval_1;
  
  Mem_AllocOrFree_004d9630((uint32_t *)(str_1 + 9),(uint32_t *)&DAT_004f4470);
  if (arg2 == 0) {
    uval_1 = FUN_00432c99(str_1);
  }
  else {
    DAT_00515e88 = __open(str_1,0x8000);
    if (DAT_00515e88 == -1) {
      Str_CopyFast((uint32_t *)&g_DuelCardChoicePrompt,(uint32_t *)s__EMPTY__004f4478);
    }
    else {
      Str_CopyFast((uint32_t *)&g_DuelCardChoicePrompt,(uint32_t *)&DAT_004f4474);
    }
    __close(DAT_00515e88);
    uval_1 = (uint32_t)(DAT_00515e88 != -1);
  }
  return uval_1;
}



/*
 * Decompiled function: FUN_00432ac7
 * Entry Point: 00432ac7
 * Size: 286 bytes
 */


void FUN_00432ac7(int player_id)

{
  int val_1;
  
  DAT_00515ea4 = 0;
  DAT_00515e80 = 0;
  val_1 = Mem_AllocOrFree_00432c72();
  if (val_1 != -1) {
    if (arg_1 == -1) {
      arg_1 = 0;
    }
    if (arg_1 != -1) {
      DAT_006669e0 = arg_1;
      s_D_MAGIC0_SVE_004f4350[7] = FUN_00432860(arg_1);
      val_1 = FUN_00432be5(s_D_MAGIC0_SVE_004f4350);
      if (val_1 != 0) {
        if (DAT_00515ea4 == 0) {
          Mem_AllocOrFree_004d9630((uint32_t *)&g_DuelCardChoicePrompt,(uint32_t *)s_Game_has_been_saved__004f4484);
        }
        else {
          Mem_AllocOrFree_004d9630((uint32_t *)&g_DuelCardChoicePrompt,(uint32_t *)s_Game_NOT_saved__004f449c);
          Mem_AllocOrFree_0049f628(DAT_005f6c50,0x40,0x7f,0xc0,0x22,0xc);
        }
        if (DAT_00515ea4 == 0xd) {
          Str_CopyFast((uint32_t *)&g_DuelCardChoicePrompt,(uint32_t *)s_Write_access_denied__004f44b0);
        }
        if (DAT_00515ea4 == 0x1c) {
          Str_CopyFast((uint32_t *)&g_DuelCardChoicePrompt,(uint32_t *)s_Disk_Full__004f44c8);
        }
        Str_CopyFast((uint32_t *)&g_DuelCardChoicePrompt,(uint32_t *)s_Press_key_to_continue__004f44d8);
      }
    }
  }
  return;
}



/*
 * Decompiled function: FUN_00432be5
 * Entry Point: 00432be5
 * Size: 69 bytes
 */


int32_t FUN_00432be5(char *arg_1)

{
  Mem_AllocOrFree_004d9630((uint32_t *)&g_DuelCardChoicePrompt,(uint32_t *)&DAT_004f44f4);
  Str_CopyFast((uint32_t *)&g_DuelCardChoicePrompt,(uint32_t *)s_____save_in_progress__004f44f8);
  FUN_00432d7b(arg_1);
  return 1;
}



/*
 * Decompiled function: FUN_00432c2a
 * Entry Point: 00432c2a
 * Size: 67 bytes
 */


bool FUN_00432c2a(int player_id,void *arg_2,uint32_t arg_3)

{
  int val_1;
  
  val_1 = __write(arg_1,arg_2,arg_3);
  if (val_1 == -1) {
    DAT_00515ea4 = DAT_00509420;
  }
  return val_1 != -1;
}



/*
 * Decompiled function: Mem_AllocOrFree_00432c72
 * Entry Point: 00432c72
 * Size: 21 bytes
 */


int32_t Mem_AllocOrFree_00432c72(void)

{
  return DAT_004f4454;
}



/*
 * Decompiled function: Mem_AllocOrFree_00432c87
 * Entry Point: 00432c87
 * Size: 18 bytes
 */


int32_t Mem_AllocOrFree_00432c87(void)

{
  return 0;
}



/*
 * Decompiled function: FUN_00432c99
 * Entry Point: 00432c99
 * Size: 226 bytes
 */


int32_t FUN_00432c99(char *filepath)

{
  int32_t uval_1;
  int match_count;
  int slot_idx;
  
  Mem_AllocOrFree_004d9630((uint32_t *)(str_1 + 9),(uint32_t *)&DAT_004f4514);
  DAT_00515e88 = __open(str_1,0x8000);
  if (DAT_00515e88 == -1) {
    uval_1 = 0;
  }
  else {
    DAT_00515e80 = 1;
    FUN_00432e04();
    __close(DAT_00515e88);
    for (slot_idx = 0; slot_idx < 2; slot_idx = slot_idx + 1) {
      for (match_count = 0; match_count < 0x50; match_count = match_count + 1) {
        if (*(int *)(&g_DuelCardSlot_CardId + slot_idx * 0x5b20 + match_count * 0x120) != -1) {
          (&g_DuelPlayerCreatureCount)[slot_idx] = match_count;
        }
      }
    }
    uval_1 = 1;
  }
  return uval_1;
}



/*
 * Decompiled function: FUN_00432d7b
 * Entry Point: 00432d7b
 * Size: 137 bytes
 */


int32_t FUN_00432d7b(char *filepath)

{
  int32_t uval_1;
  
  Mem_AllocOrFree_004d9630((uint32_t *)(str_1 + 9),(uint32_t *)&DAT_004f4518);
  DAT_00515e88 = __open(str_1,0x8301,0x80);
  if (DAT_00515e88 == -1) {
    uval_1 = 0;
  }
  else {
    DAT_00515e80 = 0;
    FUN_00432e04();
    __close(DAT_00515e88);
    if (DAT_00515ea4 == 0) {
      uval_1 = 1;
    }
    else {
      uval_1 = 0;
    }
  }
  return uval_1;
}



/*
 * Decompiled function: FUN_00432e04
 * Entry Point: 00432e04
 * Size: 3506 bytes
 */


uint32_t FUN_00432e04(void)

{
  uint32_t uval_1;
  uint32_t uval_2;
  uint32_t uval_3;
  uint32_t uval_4;
  uint32_t uval_5;
  uint32_t uval_6;
  uint32_t uval_7;
  uint32_t uval_8;
  uint32_t uVar9;
  uint32_t uVar10;
  uint32_t uVar11;
  uint32_t uVar12;
  uint32_t uVar13;
  uint32_t uVar14;
  uint32_t uVar15;
  uint32_t uVar16;
  uint32_t uVar17;
  uint32_t uVar18;
  uint32_t uVar19;
  uint32_t uVar20;
  uint32_t uVar21;
  uint32_t uVar22;
  uint32_t uVar23;
  uint32_t uVar24;
  uint32_t uVar25;
  uint32_t uVar26;
  uint32_t uVar27;
  uint32_t uVar28;
  uint32_t uVar29;
  uint32_t uVar30;
  uint32_t uVar31;
  uint32_t uVar32;
  uint32_t uVar33;
  uint32_t uVar34;
  uint32_t uVar35;
  uint32_t uVar36;
  uint32_t uVar37;
  uint32_t uVar38;
  uint32_t uVar39;
  uint32_t uVar40;
  uint32_t uVar41;
  uint32_t uVar42;
  uint32_t uVar43;
  uint32_t uVar44;
  uint32_t uVar45;
  uint32_t uVar46;
  uint32_t uVar47;
  uint32_t uVar48;
  uint32_t uVar49;
  uint32_t uVar50;
  uint32_t uVar51;
  uint32_t uVar52;
  uint32_t uVar53;
  uint32_t uVar54;
  uint32_t uVar55;
  uint32_t uVar56;
  uint32_t uVar57;
  uint32_t uVar58;
  uint32_t uVar59;
  uint32_t uVar60;
  uint32_t uVar61;
  uint32_t uVar62;
  uint32_t uVar63;
  uint32_t uVar64;
  uint32_t uVar65;
  uint32_t uVar66;
  uint32_t uVar67;
  uint32_t uVar68;
  uint32_t uVar69;
  uint32_t uVar70;
  uint32_t uVar71;
  uint32_t uVar72;
  uint32_t uVar73;
  uint32_t uVar74;
  uint32_t uVar75;
  uint32_t uVar76;
  uint32_t uVar77;
  uint32_t uVar78;
  uint32_t uVar79;
  uint32_t uVar80;
  uint32_t uVar81;
  uint32_t uVar82;
  uint32_t uVar83;
  uint32_t uVar84;
  uint32_t uVar85;
  uint32_t uVar86;
  uint32_t uVar87;
  uint32_t uVar88;
  uint32_t uVar89;
  uint32_t uVar90;
  uint32_t uVar91;
  uint32_t uVar92;
  uint32_t uVar93;
  uint32_t uVar94;
  uint32_t uVar95;
  uint32_t uVar96;
  uint32_t uVar97;
  uint32_t uVar98;
  uint32_t uVar99;
  uint32_t uVar100;
  uint32_t uVar101;
  uint32_t uVar102;
  uint32_t uVar103;
  uint32_t uVar104;
  uint32_t uVar105;
  uint32_t uVar106;
  uint32_t uVar107;
  uint32_t uVar108;
  uint32_t uVar109;
  uint32_t uVar110;
  uint32_t uVar111;
  uint32_t uVar112;
  uint32_t uVar113;
  uint32_t uVar114;
  uint32_t uVar115;
  uint32_t uVar116;
  uint32_t uVar117;
  uint32_t uVar118;
  uint32_t uVar119;
  uint32_t uVar120;
  uint32_t uVar121;
  uint32_t uVar122;
  uint32_t uVar123;
  uint32_t uVar124;
  uint32_t uVar125;
  uint32_t uVar126;
  uint32_t uVar127;
  uint32_t uVar128;
  uint32_t uVar129;
  uint32_t uVar130;
  uint32_t uVar131;
  uint32_t uVar132;
  uint32_t uVar133;
  uint32_t uVar134;
  uint32_t uVar135;
  uint32_t uVar136;
  uint32_t uVar137;
  uint32_t uVar138;
  uint32_t uVar139;
  uint32_t uVar140;
  uint32_t uVar141;
  uint32_t uVar142;
  uint32_t uVar143;
  uint32_t uVar144;
  uint32_t uVar145;
  uint32_t uVar146;
  uint32_t uVar147;
  uint32_t uVar148;
  uint32_t uVar149;
  uint32_t uVar150;
  uint32_t uVar151;
  uint32_t uVar152;
  uint32_t uVar153;
  uint32_t uVar154;
  uint32_t uVar155;
  uint32_t uVar156;
  uint32_t uVar157;
  uint32_t uVar158;
  uint32_t uVar159;
  uint32_t uVar160;
  uint32_t uVar161;
  uint32_t uVar162;
  uint32_t uVar163;
  uint32_t uVar164;
  uint32_t uVar165;
  uint32_t uVar166;
  uint32_t uVar167;
  uint32_t uVar168;
  uint32_t uVar169;
  uint32_t uVar170;
  uint32_t uVar171;
  uint32_t uVar172;
  uint32_t uVar173;
  uint32_t uVar174;
  uint32_t uVar175;
  uint32_t uVar176;
  uint32_t uVar177;
  uint32_t uVar178;
  uint32_t uVar179;
  uint32_t uVar180;
  uint32_t uVar181;
  uint32_t uVar182;
  uint32_t uVar183;
  uint32_t uVar184;
  uint32_t uVar185;
  uint32_t uVar186;
  uint32_t uVar187;
  uint32_t uVar188;
  
  uval_1 = FileIo_ReadDataBlock(&DAT_004ff580 + DAT_00665ed0 * 0x34, 0x340);
  uval_2 = FileIo_ReadDataBlock(&DAT_004f71c0,0x500);
  uval_3 = FileIo_ReadDataBlock(&DAT_0068eef0,4);
  uval_4 = FileIo_ReadDataBlock(&DAT_006663fc,4);
  uval_5 = FileIo_ReadDataBlock(&DAT_006764bc,4);
  uval_6 = FileIo_ReadDataBlock(&DAT_0066ab04,4);
  uval_7 = FileIo_ReadDataBlock(&DAT_0066aac4,4);
  uval_8 = FileIo_ReadDataBlock(&DAT_0066643c,4);
  uVar9 = FileIo_ReadDataBlock(&DAT_00666728,4);
  uVar10 = FileIo_ReadDataBlock(&DAT_0068eee4,4);
  uVar11 = FileIo_ReadDataBlock(&DAT_0067650c,4);
  uVar12 = FileIo_ReadDataBlock(&DAT_006c121c,4);
  uVar13 = FileIo_ReadDataBlock(&DAT_006826b4,4);
  uVar14 = FileIo_ReadDataBlock(&DAT_0068ef98,4);
  uVar15 = FileIo_ReadDataBlock(&DAT_0068edd4,4);
  uVar16 = FileIo_ReadDataBlock(&DAT_0068f0b4,4);
  uVar17 = FileIo_ReadDataBlock(&DAT_00666724,4);
  uVar18 = FileIo_ReadDataBlock(&DAT_0068f368,4);
  uVar19 = FileIo_ReadDataBlock(&DAT_00681ed0,4);
  uVar20 = FileIo_ReadDataBlock(&DAT_00681eb4,4);
  uVar21 = FileIo_ReadDataBlock(&DAT_00666740,4);
  uVar22 = FileIo_ReadDataBlock(&DAT_0068ed10,0x40);
  uVar23 = FileIo_ReadDataBlock(&DAT_00666570,0x198);
  uVar24 = FileIo_ReadDataBlock(&DAT_00666900,0x58);
  uVar25 = FileIo_ReadDataBlock(&DAT_0068f360,8);
  uVar26 = FileIo_ReadDataBlock(&DAT_0068f2e0,0x40);
  uVar27 = FileIo_ReadDataBlock(&DAT_0068ef50,0x40);
  uVar28 = FileIo_ReadDataBlock(&DAT_006669e4,4);
  uVar29 = FileIo_ReadDataBlock(&DAT_006664e0,4);
  uVar30 = FileIo_ReadDataBlock(&DAT_0068f0d0,4);
  uVar31 = FileIo_ReadDataBlock(&DAT_0068eed8,4);
  uVar32 = FileIo_ReadDataBlock(&DAT_006668f8,4);
  uVar33 = FileIo_ReadDataBlock(&DAT_0068eef4,4);
  uVar34 = FileIo_ReadDataBlock(&DAT_0068eed4,4);
  uVar35 = FileIo_ReadDataBlock(&deck,2000);
  uVar36 = FileIo_ReadDataBlock(&DAT_006826c0,0xb640);
  uVar37 = FileIo_ReadDataBlock(&DAT_00690b00,0x140);
  uVar38 = FileIo_ReadDataBlock(&DAT_0068f370,4000);
  uVar39 = FileIo_ReadDataBlock(&DAT_0068dd10,4000);
  uVar40 = FileIo_ReadDataBlock(&DAT_006669f0,4000);
  uVar41 = FileIo_ReadDataBlock(&DAT_0068ed50,0x80);
  uVar42 = FileIo_ReadDataBlock(&DAT_00690318,4);
  uVar43 = FileIo_ReadDataBlock(&DAT_0068f0f8,4);
  uVar44 = FileIo_ReadDataBlock(&DAT_0068f2c8,4);
  uVar45 = FileIo_ReadDataBlock(&DAT_0068f0bc,4);
  uVar46 = FileIo_ReadDataBlock(&DAT_0068ee70,0x60);
  uVar47 = FileIo_ReadDataBlock(&DAT_00666430,8);
  uVar48 = FileIo_ReadDataBlock(&DAT_0068ece0,0x1c);
  uVar49 = FileIo_ReadDataBlock(&DAT_0068eeec,4);
  uVar50 = FileIo_ReadDataBlock(&DAT_00666710,0x10);
  uVar51 = FileIo_ReadDataBlock(&g_DuelHumanPlayerIndex,4);
  uVar52 = FileIo_ReadDataBlock(&g_DuelPlayerCreatureCount,8);
  uVar53 = FileIo_ReadDataBlock(&DAT_006663f8,4);
  uVar54 = FileIo_ReadDataBlock(&DAT_00666500,100);
  uVar55 = FileIo_ReadDataBlock(&g_DuelPlayerLifeTotals,8);
  uVar56 = FileIo_ReadDataBlock(&DAT_006668f0,8);
  uVar57 = FileIo_ReadDataBlock(&DAT_0068f228,8);
  uVar58 = FileIo_ReadDataBlock(&DAT_00666730,0x10);
  uVar59 = FileIo_ReadDataBlock(&g_DuelDefendingPlayer,4);
  uVar60 = FileIo_ReadDataBlock(&DAT_0068ed00,4);
  uVar61 = FileIo_ReadDataBlock(&g_DuelDamageAccumulator,4);
  uVar62 = FileIo_ReadDataBlock(&g_DuelCombatPhaseState,4);
  uVar63 = FileIo_ReadDataBlock(&g_DuelPlayerManaPool,4);
  uVar64 = FileIo_ReadDataBlock(&DAT_006826b0,4);
  uVar65 = FileIo_ReadDataBlock(&DAT_00666440,4);
  uVar66 = FileIo_ReadDataBlock(&DAT_006669e8,4);
  uVar67 = FileIo_ReadDataBlock(&DAT_006664e4,4);
  uVar68 = FileIo_ReadDataBlock(&g_DuelTurnCounter,4);
  uVar69 = FileIo_ReadDataBlock(&DAT_0068ed04,4);
  uVar70 = FileIo_ReadDataBlock(&g_DuelTargetPlayer,4);
  uVar71 = FileIo_ReadDataBlock(&g_DuelTargetCardSlot,4);
  uVar72 = FileIo_ReadDataBlock(&g_DuelActivePlayer,4);
  uVar73 = FileIo_ReadDataBlock(&g_DuelActiveCardSlot,4);
  uVar74 = FileIo_ReadDataBlock(&DAT_00681ecc,4);
  uVar75 = FileIo_ReadDataBlock(&DAT_0068ee64,4);
  uVar76 = FileIo_ReadDataBlock(&DAT_00690310,4);
  uVar77 = FileIo_ReadDataBlock(&DAT_0068ecfc,4);
  uVar78 = FileIo_ReadDataBlock(&g_DuelCurrentTurnPhase,4);
  uVar79 = FileIo_ReadDataBlock(&DAT_0066aadc,4);
  uVar80 = FileIo_ReadDataBlock(&DAT_0066aae0,4);
  uVar81 = FileIo_ReadDataBlock(&DAT_0066641c,4);
  uVar82 = FileIo_ReadDataBlock(&DAT_0066644c,4);
  uVar83 = FileIo_ReadDataBlock(&DAT_0068f0c8,4);
  uVar84 = FileIo_ReadDataBlock(&DAT_0066aad8,4);
  uVar85 = FileIo_ReadDataBlock(&DAT_00666748,4);
  uVar86 = FileIo_ReadDataBlock(&DAT_0068f0f4,4);
  uVar87 = FileIo_ReadDataBlock(&DAT_0068ecd0,4);
  uVar88 = FileIo_ReadDataBlock(&DAT_0068eccc,4);
  uVar89 = FileIo_ReadDataBlock(&DAT_0068ee68,4);
  uVar90 = FileIo_ReadDataBlock(&g_DuelCurrentEventCode,4);
  uVar91 = FileIo_ReadDataBlock(&DAT_00666754,4);
  uVar92 = FileIo_ReadDataBlock(&DAT_0068edd0,4);
  uVar93 = FileIo_ReadDataBlock(&g_DuelCombatAttackerPlayer,4);
  uVar94 = FileIo_ReadDataBlock(&g_DuelCombatBlockerSlot,4);
  uVar95 = FileIo_ReadDataBlock(&DAT_00681ec4,4);
  uVar96 = FileIo_ReadDataBlock(&DAT_00666744,4);
  uVar97 = FileIo_ReadDataBlock(&DAT_00666418,4);
  uVar98 = FileIo_ReadDataBlock(&DAT_0068ee60,4);
  uVar99 = FileIo_ReadDataBlock(&DAT_0068f0b8,4);
  uVar100 = FileIo_ReadDataBlock(&DAT_00666770,0x40);
  uVar101 = FileIo_ReadDataBlock(&DAT_0066aae4,4);
  uVar102 = FileIo_ReadDataBlock(&DAT_0068ecb8,8);
  uVar103 = FileIo_ReadDataBlock(&DAT_0068ef00,0x40);
  uVar104 = FileIo_ReadDataBlock(&DAT_00667990,4);
  uVar105 = FileIo_ReadDataBlock(&DAT_0068ecc8,4);
  uVar106 = FileIo_ReadDataBlock(&DAT_006663f0,4);
  uVar107 = FileIo_ReadDataBlock(&DAT_00690c44,4);
  uVar108 = FileIo_ReadDataBlock(&DAT_00666758,4);
  uVar109 = FileIo_ReadDataBlock(&DAT_00666454,4);
  uVar110 = FileIo_ReadDataBlock(&DAT_006663f4,4);
  uVar111 = FileIo_ReadDataBlock(&DAT_0068ef44,4);
  uVar112 = FileIo_ReadDataBlock(&DAT_0068ede0,0x40);
  uVar113 = FileIo_ReadDataBlock(&DAT_0068ee20,0x40);
  uVar114 = FileIo_ReadDataBlock(&DAT_0068f320,0x40);
  uVar115 = FileIo_ReadDataBlock(&DAT_0066aad0,8);
  uVar116 = FileIo_ReadDataBlock(&DAT_00681eb8,8);
  uVar117 = FileIo_ReadDataBlock(&DAT_006764b0,4);
  uVar118 = FileIo_ReadDataBlock(&DAT_0068ef94,4);
  uVar119 = FileIo_ReadDataBlock(&DAT_00666400,4);
  uVar120 = FileIo_ReadDataBlock(&DAT_006664f0,8);
  uVar121 = FileIo_ReadDataBlock(&DAT_006764d0,0x30);
  uVar122 = FileIo_ReadDataBlock(&DAT_00676508,4);
  uVar123 = FileIo_ReadDataBlock(&DAT_0068f220,4);
  uVar124 = FileIo_ReadDataBlock(&DAT_00681ec0,4);
  uVar125 = FileIo_ReadDataBlock(&DAT_0066aaf0,4);
  uVar126 = FileIo_ReadDataBlock(&DAT_006663e8,8);
  uVar127 = FileIo_ReadDataBlock(&DAT_0068f240,0x80);
  uVar128 = FileIo_ReadDataBlock(&DAT_0068efb0,0x100);
  uVar129 = FileIo_ReadDataBlock(&DAT_0068f120,0x100);
  uVar130 = FileIo_ReadDataBlock(&DAT_00666960,0x80);
  uVar131 = FileIo_ReadDataBlock(&DAT_00666460,0x80);
  uVar132 = FileIo_ReadDataBlock(&DAT_006764b8,4);
  uVar133 = FileIo_ReadDataBlock(&DAT_00676500,4);
  uVar134 = FileIo_ReadDataBlock(&DAT_0068dd04,4);
  uVar135 = FileIo_ReadDataBlock(&DAT_00666448,4);
  uVar136 = FileIo_ReadDataBlock(&DAT_0068edd8,4);
  uVar137 = FileIo_ReadDataBlock(&DAT_00666404,4);
  uVar138 = FileIo_ReadDataBlock(&DAT_006664ec,4);
  uVar139 = FileIo_ReadDataBlock(&DAT_0068dd00,4);
  uVar140 = FileIo_ReadDataBlock(&DAT_00690320,2000);
  uVar141 = FileIo_ReadDataBlock(&DAT_00681ee0,2000);
  uVar142 = FileIo_ReadDataBlock(&DAT_0068f2c0,4);
  uVar143 = FileIo_ReadDataBlock(&DAT_0068ef90,4);
  uVar144 = FileIo_ReadDataBlock(&DAT_00666428,4);
  uVar145 = FileIo_ReadDataBlock(&DAT_0068f2d8,4);
  uVar146 = FileIo_ReadDataBlock(&DAT_0068ecc4,4);
  uVar147 = FileIo_ReadDataBlock(&DAT_0068eedc,4);
  uVar148 = FileIo_ReadDataBlock(&DAT_0068f110,4);
  uVar149 = FileIo_ReadDataBlock(&DAT_00505984,4);
  uVar150 = FileIo_ReadDataBlock(&DAT_00505988,4);
  uVar151 = FileIo_ReadDataBlock(&DAT_0050598c,4);
  uVar152 = FileIo_ReadDataBlock(&DAT_005f2f50,4);
  uVar153 = FileIo_ReadDataBlock(&DAT_005f2f58,4);
  uVar154 = FileIo_ReadDataBlock(&DAT_005f2ea0,0xa0);
  uVar155 = FileIo_ReadDataBlock(&DAT_005f6c48,4);
  uVar156 = FileIo_ReadDataBlock(&DAT_005f6c4c,4);
  uVar157 = FileIo_ReadDataBlock(&DAT_005f2f4c,4);
  uVar158 = FileIo_ReadDataBlock(&DAT_005ef9c0,0x3200);
  uVar159 = FileIo_ReadDataBlock(&DAT_005f2e90,4);
  uVar160 = FileIo_ReadDataBlock(&DAT_005071c0,4);
  uVar161 = FileIo_ReadDataBlock(&DAT_005ef570,4);
  uVar162 = FileIo_ReadDataBlock(&DAT_005f2f8c,4);
  uVar163 = FileIo_ReadDataBlock(&DAT_005ef9a4,4);
  uVar164 = FileIo_ReadDataBlock(&DAT_005ef990,0x14);
  uVar165 = FileIo_ReadDataBlock(&Gold,4);
  uVar166 = FileIo_ReadDataBlock(&DAT_005071b8,4);
  uVar167 = FileIo_ReadDataBlock(&DAT_005ef580,1000);
  uVar168 = FileIo_ReadDataBlock(&DAT_005f2f44,4);
  uVar169 = FileIo_ReadDataBlock(&Scards,0xc0);
  uVar170 = FileIo_ReadDataBlock(&DAT_005ef984,4);
  uVar171 = FileIo_ReadDataBlock(&DAT_005f2bc0,0x2d0);
  uVar172 = FileIo_ReadDataBlock(&DAT_005f6c64,4);
  uVar173 = FileIo_ReadDataBlock(&DAT_005f2f54,4);
  uVar174 = FileIo_ReadDataBlock(&DAT_005f67f8,4);
  uVar175 = FileIo_ReadDataBlock(&DAT_00664d48,4);
  uVar176 = FileIo_ReadDataBlock(&DAT_005f76cc,4);
  uVar177 = FileIo_ReadDataBlock(&DAT_006669e4,4);
  uVar178 = FileIo_ReadDataBlock(&DAT_005071c4,4);
  uVar179 = FileIo_ReadDataBlock(&DAT_005f67f4,4);
  uVar180 = FileIo_ReadDataBlock(&DAT_005ee570,0x1000);
  uVar181 = FileIo_ReadDataBlock(&DAT_005ef9a8,4);
  uVar182 = FileIo_ReadDataBlock(&DAT_00663e28,4);
  uVar183 = FileIo_ReadDataBlock(&DAT_00663e2c,4);
  uVar184 = FileIo_ReadDataBlock(&DAT_006169f0,4);
  uVar185 = FileIo_ReadDataBlock(&DAT_00663e6c,4);
  uVar186 = FileIo_ReadDataBlock(&DAT_00617380,4);
  uVar187 = FileIo_ReadDataBlock(&DAT_005f6c70,0x40);
  uVar188 = FileIo_ReadDataBlock(&DAT_005f6c5c,4);
  return uval_1 & 1 & uval_2 & uval_3 & uval_4 & uval_5 & uval_6 & uval_7 & uval_8 & uVar9 & uVar10 & uVar11
         & uVar12 & uVar13 & uVar14 & uVar15 & uVar16 & uVar17 & uVar18 & uVar19 & uVar20 & uVar21 &
         uVar22 & uVar23 & uVar24 & uVar25 & uVar26 & uVar27 & uVar28 & uVar29 & uVar30 & uVar31 &
         uVar32 & uVar33 & uVar34 & uVar35 & uVar36 & uVar37 & uVar38 & uVar39 & uVar40 & uVar41 &
         uVar42 & uVar43 & uVar44 & uVar45 & uVar46 & uVar47 & uVar48 & uVar49 & uVar50 & uVar51 &
         uVar52 & uVar53 & uVar54 & uVar55 & uVar56 & uVar57 & uVar58 & uVar59 & uVar60 & uVar61 &
         uVar62 & uVar63 & uVar64 & uVar65 & uVar66 & uVar67 & uVar68 & uVar69 & uVar70 & uVar71 &
         uVar72 & uVar73 & uVar74 & uVar75 & uVar76 & uVar77 & uVar78 & uVar79 & uVar80 & uVar81 &
         uVar82 & uVar83 & uVar84 & uVar85 & uVar86 & uVar87 & uVar88 & uVar89 & uVar90 & uVar91 &
         uVar92 & uVar93 & uVar94 & uVar95 & uVar96 & uVar97 & uVar98 & uVar99 & uVar100 & uVar101 &
         uVar102 & uVar103 & uVar104 & uVar105 & uVar106 & uVar107 & uVar108 & uVar109 & uVar110 &
         uVar111 & uVar112 & uVar113 & uVar114 & uVar115 & uVar116 & uVar117 & uVar118 & uVar119 &
         uVar120 & uVar121 & uVar122 & uVar123 & uVar124 & uVar125 & uVar126 & uVar127 & uVar128 &
         uVar129 & uVar130 & uVar131 & uVar132 & uVar133 & uVar134 & uVar135 & uVar136 & uVar137 &
         uVar138 & uVar139 & uVar140 & uVar141 & uVar142 & uVar143 & uVar144 & uVar145 & uVar146 &
         uVar147 & uVar148 & uVar149 & uVar150 & uVar151 & uVar152 & uVar153 & uVar154 & uVar155 &
         uVar156 & uVar157 & uVar158 & uVar159 & uVar160 & uVar161 & uVar162 & uVar163 & uVar164 &
         uVar165 & uVar166 & uVar167 & uVar168 & uVar169 & uVar170 & uVar171 & uVar172 & uVar173 &
         uVar174 & uVar175 & uVar176 & uVar177 & uVar178 & uVar179 & uVar180 & uVar181 & uVar182 &
         uVar183 & uVar184 & uVar185 & uVar186 & uVar187 & uVar188;
}



/*
 * Decompiled function: FileIo_ReadDataBlock
 * Entry Point: 00433bb6
 * Size: 131 bytes
 */


uint32_t FileIo_ReadDataBlock(void *arg1,uint32_t arg2)

{
  uint32_t uval_1;
  uint32_t slot_idx;
  
  if (DAT_00515e80 == 0) {
    slot_idx = FUN_00432c2a(DAT_00515e88,arg1,arg2);
  }
  else {
    uval_1 = __read(DAT_00515e88,arg1,arg2);
    slot_idx = (uint32_t)(uval_1 == arg2);
  }
  if (slot_idx == 0) {
    OutputDebugStringA(s_SHIT_004f451c);
  }
  return slot_idx;
}



/*
 * Decompiled function: FUN_00433c39
 * Entry Point: 00433c39
 * Size: 77 bytes
 */


int FUN_00433c39(char *filepath)

{
  int val_1;
  int slot_idx;
  
  slot_idx = 0;
  for (; *str_1 != '\0'; str_1 = str_1 + 1) {
    val_1 = Mem_AllocOrFree_0049f725(*(int32_t *)(DAT_005f6c50 + 0x20),*str_1);
    slot_idx = slot_idx + val_1;
  }
  return slot_idx;
}



/*
 * Decompiled function: Mem_AllocOrFree_00433c86
 * Entry Point: 00433c86
 * Size: 18 bytes
 */


int32_t Mem_AllocOrFree_00433c86(void)

{
  return 0;
}



/*
 * Decompiled function: Mem_AllocOrFree_00433c98
 * Entry Point: 00433c98
 * Size: 18 bytes
 */


int32_t Mem_AllocOrFree_00433c98(void)

{
  return 0;
}



/*
 * Decompiled function: FUN_00433caa
 * Entry Point: 00433caa
 * Size: 155 bytes
 */


void FUN_00433caa(char *filepath)

{
  DAT_00515e88 = __open(str_1,0x8301,0x80);
  if (DAT_00515e88 != -1) {
    DAT_00515e80 = 0;
    FileIo_ReadDataBlock(&DAT_0060cc64,4);
    FUN_00432e04();
    FileIo_ReadDataBlock(&_PlayerFace,4);
    FileIo_ReadDataBlock(&_OpponFace,4);
    FileIo_ReadDataBlock(&DAT_00664b90,0x32);
    FileIo_ReadDataBlock(&DAT_006015b0,0x32);
    __close(DAT_00515e88);
  }
  return;
}



/*
 * Decompiled function: FUN_00433d45
 * Entry Point: 00433d45
 * Size: 237 bytes
 */


uint32_t FUN_00433d45(char *filepath)

{
  uint32_t uval_1;
  uint32_t uval_2;
  uint32_t uval_3;
  uint32_t uval_4;
  uint32_t uval_5;
  uint32_t match_count;
  int slot_idx;
  
  DAT_00515e88 = __open(str_1,0x8000);
  if (DAT_00515e88 == -1) {
    match_count = 0;
  }
  else {
    DAT_00515e80 = 1;
    uval_1 = FileIo_ReadDataBlock(&slot_idx,4);
    if (slot_idx == DAT_0060cc64) {
      uval_2 = FUN_00432e04();
      uval_3 = FileIo_ReadDataBlock(&_PlayerFace,4);
      uval_4 = FileIo_ReadDataBlock(&_OpponFace,4);
      uval_5 = FileIo_ReadDataBlock(&DAT_00664b90,0x32);
      DAT_00664bc2 = 0;
      match_count = FileIo_ReadDataBlock(&DAT_006015b0,0x32);
      match_count = uval_1 & 1 & uval_2 & uval_3 & uval_4 & uval_5 & match_count;
      DAT_006015e2 = 0;
    }
    else {
      match_count = 0;
    }
    __close(DAT_00515e88);
  }
  return match_count;
}



/*
 * Decompiled function: UI_RegisterClass_00433e40
 * Entry Point: 00433e40
 * Size: 146 bytes
 */


bool UI_RegisterClass_00433e40(LPCSTR str_1)

{
  ATOM AVar1;
  WNDCLASSA local_2c;
  
  local_2c.style = 1;
  local_2c.lpfnWndProc = UI_WndProc_00433ed2;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 0;
  local_2c.hInstance = g_DuelInstanceHandle;
  local_2c.hIcon = LoadIconA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = (HBRUSH)0x6;
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = str_1;
  AVar1 = RegisterClassA(&local_2c);
  return AVar1 != 0;
}



/*
 * Decompiled function: UI_WndProc_00433ed2
 * Entry Point: 00433ed2
 * Size: 516 bytes
 */


LRESULT UI_WndProc_00433ed2(HWND hwnd,uint32_t uMsg,HDC wParam,LPARAM lParam)

{
  HDC hdc;
  LRESULT LVar1;
  tagPAINTSTRUCT local_134;
  CHAR local_f4 [200];
  tagRECT local_2c;
  HDC color_idx;
  tagRECT target_idx;
  HBRUSH slot_idx;
  
  if (uMsg < 0xd) {
    if (uMsg == 0xc) {
      InvalidateRect(hwnd,(RECT *)0x0,1);
      LVar1 = DefWindowProcA(hwnd,0xc,(WPARAM)wParam,lParam);
      return LVar1;
    }
    if (uMsg == 1) {
      return 0;
    }
  }
  else if (uMsg < 0x15) {
    if (uMsg == 0x14) {
      color_idx = wParam;
      GDI_RealizeAndFlushPalette(wParam);
      GetClientRect(hwnd,&target_idx);
      slot_idx = CreateSolidBrush(0xffff);
      FillRect(color_idx,&target_idx,slot_idx);
      DeleteObject(slot_idx);
      return 1;
    }
    if (uMsg == 0xf) {
      hdc = BeginPaint(hwnd,&local_134);
      if (hdc != (HDC)0x0) {
        GDI_RealizeAndFlushPalette(hdc);
        GetWindowTextA(hwnd,local_f4,200);
        SetTextAlign(hdc,6);
        SetBkMode(hdc,1);
        SetTextColor(hdc,0);
        GetClientRect(hwnd,&local_2c);
        FUN_0042233a(hdc,&local_2c.left,local_f4,1);
        EndPaint(hwnd,&local_134);
      }
      return 0;
    }
  }
  else if ((0x30e < uMsg) && (uMsg < 0x312)) {
    LVar1 = GDI_RealizePaletteTree(hwnd,uMsg,(HWND)wParam,lParam);
    return LVar1;
  }
  LVar1 = DefWindowProcA(hwnd,uMsg,(WPARAM)wParam,lParam);
  return LVar1;
}




/*
 * sid/Magic.c - Reconstructed MicroProse Source Module
 * Program: DUEL.EXE
 * Contained Functions: 62
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include "shandalar/shandalar.h"
/* Modular Shandalar Subsystem */

/*
 * Decompiled function: Magic_ScanCards
 * Entry Point: 0048c5a8
 * Size: 863 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Magic_ScanCards(int player_id)

{
  int arg2;
  int32_t uval_1;
  int val_2;
  int player_idx;
  int card_idx;
  int slot_idx;
  
  uval_1 = DAT_005ef980;
  _DAT_0068dd04 = color_mask;
  _DAT_00666728 = _DAT_00666728 + 1;
  DAT_0068ef48 = DAT_0068ef48 + 1;
  if (9 < DAT_0068ef48) {
    __assert((uint32_t *)s___nScan<10_004fb0d0,(uint32_t *)s_D__Newmagic_sources_sid_Magic_c_004fb0b0,0x7f5)
    ;
  }
  for (slot_idx = 0; slot_idx < 2; slot_idx = slot_idx + 1) {
    for (card_idx = 0; card_idx < 0x50; card_idx = card_idx + 1) {
      if (*(int *)(&g_DuelCardSlot_CardId + card_idx * 0x120 + slot_idx * 0x5b20) != -1) {
        (&g_DuelPlayerCreatureCount)[slot_idx] = card_idx + 1;
      }
    }
  }
  for (player_idx = 0; (player_idx < 500 && (*(int *)(&DAT_00690320 + player_idx * 4) != -1));
      player_idx = player_idx + 1) {
    slot_idx = *(int *)(&DAT_00690320 + player_idx * 4);
    arg2 = *(int *)(&DAT_00681ee0 + player_idx * 4);
    if (((*(int *)(&DAT_006826f4 + arg2 * 0x120 + slot_idx * 0x5b20) == player_idx) &&
        (*(int *)(&g_DuelCardSlot_CardId + arg2 * 0x120 + slot_idx * 0x5b20) != -1)) &&
       ((((&g_DuelCardSlot_Flags)[arg2 * 0x120 + slot_idx * 0x5b20] & 2) != 0 ||
        (((&g_DuelCardSlot_Flags)[arg2 * 0x120 + slot_idx * 0x5b20] & 0x20) != 0)))) {
      _DAT_00666448 = slot_idx * 0x80 + arg2;
      if ((*(int *)(&g_DuelCardSlot_CardId + arg2 * 0x120 + slot_idx * 0x5b20) < 0) ||
         (DAT_00665ed0 + 0x10 < *(int *)(&g_DuelCardSlot_CardId + arg2 * 0x120 + slot_idx * 0x5b20))) {
        FUN_004d7e62(s_ScanCard_error_004fb0dc);
      }
      else {
        (**(code **)(&DAT_004ff5a0 +
                    *(int *)(&g_DuelCardSlot_CardId + arg2 * 0x120 + slot_idx * 0x5b20) * 0x34))
                  (slot_idx,arg2,color_mask);
        if ((((color_mask == 0x15) && (g_TurnPlayer == slot_idx)) &&
            (((uint8_t)*(int32_t *)(&g_DuelCardSlot_Flags + arg2 * 0x120 + slot_idx * 0x5b20) & 0x14) == 4))
           && (val_2 = FUN_0048af80(slot_idx,arg2), val_2 == 0)) {
          *(uint32_t *)(&g_DuelCardSlot_Flags + arg2 * 0x120 + slot_idx * 0x5b20) =
               *(uint32_t *)(&g_DuelCardSlot_Flags + arg2 * 0x120 + slot_idx * 0x5b20) | 0x10;
          DAT_0068f0f4 = 0xffffffff;
          FUN_0048c50b(slot_idx,arg2,0x81);
        }
      }
    }
  }
  if ((color_mask == 0x15) && (g_TurnPlayer == slot_idx)) {
    FUN_0048b64f();
  }
  DAT_0068ef48 = DAT_0068ef48 + -1;
  if (DAT_00666418 != -1) {
    (**(code **)(&DAT_004ff5a0 + DAT_00666418 * 0x34))(0,0x4e,color_mask);
  }
  DAT_005ef980 = uval_1;
  return;
}



/*
 * Decompiled function: Duel_PlayCardSoundEffect
 * Entry Point: 0048c907
 * Size: 291 bytes
 */


int Duel_PlayCardSoundEffect(int player_id,int card_slot,int event_type,int32_t arg_4,int32_t arg_5)

{
  int32_t uval_1;
  int val_2;
  int val_3;
  
  if (*(int *)(&g_DuelCardSlot_CardId + arg_2 * 0x120 + color_mask * 0x5b20) == -1) {
    val_2 = 0;
  }
  else {
    FUN_0048cac9();
    uval_1 = DAT_00676500;
    g_CardEventResult = 0;
    g_EventSourcePlayer = color_mask;
    g_EventSourceSlot = arg_2;
    DAT_00690310 = arg_4;
    DAT_0068ecfc = arg_5;
    val_2 = (**(code **)(&DAT_004ff5a0 +
                        *(int *)(&g_DuelCardSlot_CardId + arg_2 * 0x120 + color_mask * 0x5b20) * 0x34))
                      (color_mask,arg_2,arg_3);
    if ((((val_2 != 99) && ((g_DuelModeFlags & 0x224) != 0)) && ((arg_3 == 0x74 || (arg_3 == 0x73))))
       && (val_3 = Magic_IsManaSource(color_mask,arg_2), val_3 == 0)) {
      DAT_00676500 = uval_1;
      FUN_0048cb7f();
      return 0;
    }
    DAT_0068edd8 = g_CardEventResult;
    FUN_0048cb7f();
  }
  return val_2;
}



/*
 * Decompiled function: Magic_IsManaSource
 * Entry Point: 0048ca2a
 * Size: 159 bytes
 */


bool Magic_IsManaSource(int x,int arg2)

{
  bool flag_1;
  
  if (((&DAT_004ff5a9)[*(int *)(&g_DuelCardSlot_CardId + arg2 * 0x120 + x * 0x5b20) * 0x34] & 0x10) == 0)
  {
    flag_1 = false;
  }
  else {
    flag_1 = ((&DAT_004ff5a8)[*(int *)(&g_DuelCardSlot_CardId + arg2 * 0x120 + x * 0x5b20) * 0x34] & 1) ==
            0;
  }
  return flag_1;
}



/*
 * Decompiled function: FUN_0048cac9
 * Entry Point: 0048cac9
 * Size: 182 bytes
 */


void FUN_0048cac9(void)

{
  if (DAT_004fab4c < 0x20) {
    *(int32_t *)(&DAT_00665ee0 + DAT_004fab4c * 0x28) = g_EventSourcePlayer;
    *(int32_t *)(&DAT_00665ee4 + DAT_004fab4c * 0x28) = g_EventSourceSlot;
    *(int32_t *)(&DAT_00665ee8 + DAT_004fab4c * 0x28) = DAT_00681ecc;
    *(int32_t *)(&DAT_00665eec + DAT_004fab4c * 0x28) = DAT_0068ee64;
    *(int32_t *)(&DAT_00665ef0 + DAT_004fab4c * 0x28) = DAT_00690310;
    *(int32_t *)(&DAT_00665ef4 + DAT_004fab4c * 0x28) = DAT_0068ecfc;
    *(int32_t *)(&DAT_00665ef8 + DAT_004fab4c * 0x28) = g_CardEventResult;
    DAT_004fab4c = DAT_004fab4c + 1;
  }
  return;
}



/*
 * Decompiled function: FUN_0048cb7f
 * Entry Point: 0048cb7f
 * Size: 170 bytes
 */


void FUN_0048cb7f(void)

{
  if (0 < DAT_004fab4c) {
    DAT_004fab4c = DAT_004fab4c + -1;
  }
  g_EventSourcePlayer = *(int32_t *)(&DAT_00665ee0 + DAT_004fab4c * 0x28);
  g_EventSourceSlot = *(int32_t *)(&DAT_00665ee4 + DAT_004fab4c * 0x28);
  DAT_00681ecc = *(int32_t *)(&DAT_00665ee8 + DAT_004fab4c * 0x28);
  DAT_0068ee64 = *(int32_t *)(&DAT_00665eec + DAT_004fab4c * 0x28);
  DAT_00690310 = *(int32_t *)(&DAT_00665ef0 + DAT_004fab4c * 0x28);
  DAT_0068ecfc = *(int32_t *)(&DAT_00665ef4 + DAT_004fab4c * 0x28);
  g_CardEventResult = *(int32_t *)(&DAT_00665ef8 + DAT_004fab4c * 0x28);
  return;
}



/*
 * Decompiled function: FUN_0048cc29
 * Entry Point: 0048cc29
 * Size: 945 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0048cc29(void)

{
  uint8_t color_mask;
  int val_1;
  int val_2;
  int val_3;
  int val_4;
  int card_idx;
  int match_count;
  
  for (card_idx = 0; card_idx < 8; card_idx = card_idx + 1) {
    *(int32_t *)(&DAT_0068f340 + card_idx * 4) = 0;
    *(int32_t *)(&DAT_0068f320 + card_idx * 4) = *(int32_t *)(&DAT_0068f340 + card_idx * 4);
    *(int32_t *)(&DAT_0068ee40 + card_idx * 4) = *(int32_t *)(&DAT_0068f320 + card_idx * 4);
    *(int32_t *)(&DAT_0068ee20 + card_idx * 4) = *(int32_t *)(&DAT_0068ee40 + card_idx * 4);
    *(int32_t *)(&DAT_0068ee00 + card_idx * 4) = *(int32_t *)(&DAT_0068ee20 + card_idx * 4);
    *(int32_t *)(&DAT_0068ede0 + card_idx * 4) = *(int32_t *)(&DAT_0068ee00 + card_idx * 4);
  }
  DAT_0066aad4 = 0;
  _DAT_0066aad0 = 0;
  DAT_006664f4 = 0;
  _DAT_006664f0 = 0;
  DAT_00681ebc = 0;
  _DAT_00681eb8 = 0;
  for (card_idx = 0; card_idx < 0x18; card_idx = card_idx + 1) {
    *(int32_t *)(&DAT_0068ee70 + card_idx * 4) = 0;
  }
  _DAT_0068ee70 = g_DuelPlayerLifeTotals;
  DAT_0068ee74 = DAT_00681eac;
  for (match_count = 0; match_count < 2; match_count = match_count + 1) {
    (&DAT_0068ee78)[match_count] = 0;
    for (card_idx = 0; card_idx < (int)(&g_DuelPlayerCreatureCount)[match_count]; card_idx = card_idx + 1) {
      val_1 = Duel_CardIsTapped(match_count, card_idx);
      if (val_1 == 0) {
        if (*(int *)(&g_DuelCardSlot_CardId + match_count * 0x5b20 + card_idx * 0x120) != -1) {
          (&DAT_0068ee78)[match_count] = (&DAT_0068ee78)[match_count] + 1;
        }
      }
      else {
        val_1 = *(int *)(&g_DuelCardSlot_CardId + match_count * 0x5b20 + card_idx * 0x120);
        color_mask = (&DAT_004ff596)[val_1 * 0x34];
        if (((&g_DuelMasterCardTable)[val_1 * 0x34] & 2) != 0) {
          val_2 = Duel_QueryCardAttribute(match_count, card_idx, 0x32, 0xffffffff);
          val_3 = Duel_QueryCardAttribute(match_count,card_idx,0x33,0xffffffff);
          val_4 = Duel_ColorMaskToIndex(color_mask);
          *(int *)(&DAT_0068ede0 + val_4 * 4 + match_count * 0x20) =
               *(int *)(&DAT_0068ede0 + val_4 * 4 + match_count * 0x20) + val_2;
          *(int *)(&DAT_0068edfc + match_count * 0x20) =
               *(int *)(&DAT_0068edfc + match_count * 0x20) + val_2;
          val_2 = Duel_ColorMaskToIndex(color_mask);
          *(int *)(&DAT_0068ee20 + val_2 * 4 + match_count * 0x20) =
               *(int *)(&DAT_0068ee20 + val_2 * 4 + match_count * 0x20) + val_3;
          *(int *)(&DAT_0068ee3c + match_count * 0x20) =
               *(int *)(&DAT_0068ee3c + match_count * 0x20) + val_3;
          *(int *)(&DAT_00681eb8 + match_count * 4) = *(int *)(&DAT_00681eb8 + match_count * 4) + 1;
        }
        *(uint32_t *)(&DAT_0066aad0 + match_count * 4) =
             *(uint32_t *)(&DAT_0066aad0 + match_count * 4) | (uint32_t)(uint8_t)(&g_DuelMasterCardTable)[val_1 * 0x34];
        if (((&g_DuelMasterCardTable)[val_1 * 0x34] & 2) != 0) {
          *(int *)(&DAT_0068ee80 + match_count * 4) = *(int *)(&DAT_0068ee80 + match_count * 4) + 1;
        }
        if (((&g_DuelMasterCardTable)[val_1 * 0x34] & 0x40) != 0) {
          (&DAT_0068ee88)[match_count] = (&DAT_0068ee88)[match_count] + 1;
        }
        if (((&g_DuelMasterCardTable)[val_1 * 0x34] & 4) != 0) {
          *(int *)(&DAT_0068ee90 + match_count * 4) = *(int *)(&DAT_0068ee90 + match_count * 4) + 1;
        }
      }
    }
    for (card_idx = 0; card_idx < 500; card_idx = card_idx + 1) {
      if (*(int *)(&DAT_0068f370 + card_idx * 4 + match_count * 2000) != -1) {
        *(uint32_t *)(&DAT_006664f0 + match_count * 4) =
             *(uint32_t *)(&DAT_006664f0 + match_count * 4) |
             (uint32_t)(uint8_t)(&g_DuelMasterCardTable)
                         [*(int *)(&DAT_0068f370 + card_idx * 4 + match_count * 2000) * 0x34];
      }
    }
  }
  return;
}



/*
 * Decompiled function: FUN_0048cfda
 * Entry Point: 0048cfda
 * Size: 50 bytes
 */


void FUN_0048cfda(int x,int arg2)

{
  if (g_IsAiThinking != 1) {
    FUN_00450e84(x,arg2);
  }
  g_DuelHumanPlayerIndex = 0;
  return;
}



/*
 * Decompiled function: Sound_PlayTrackById
 * Entry Point: 0048d00c
 * Size: 788 bytes
 */


/* WARNING: Type propagation algorithm not settling */

int32_t Sound_PlayTrackById(int player_id)

{
  int32_t uval_1;
  int val_2;
  uint32_t local_134 [66];
  int local_2c;
  int local_28 [8];
  uint32_t slot_idx;
  
  local_28[1] = 300;
  local_28[2] = 0;
  local_28[3] = 0;
  local_28[4] = 0;
  local_28[5] = 0;
  local_28[6] = 0;
  local_28[7] = color_mask;
  slot_idx = 0;
  if (g_IsAiThinking == 1) {
    uval_1 = 0;
  }
  else {
    local_28[0] = color_mask;
    if (color_mask < 0x14) {
      PlaySnd(color_mask,0);
    }
    else if (color_mask < 0x1d) {
      val_2 = IsSndLoaded(color_mask,local_28);
      if (val_2 == 0) {
        local_2c = GetLRUSnd(local_28,0x14,0x16);
        if (local_2c == 0) {
          CloseSndTrack(local_28[0]);
        }
        else if (local_2c != 1) {
          return 0;
        }
        Mem_AllocOrFree_004d9630(local_134,(uint32_t *)&DAT_0060d4a0);
        Str_CopyFast(local_134, (uint32_t *)&DAT_004fb0ec);
        Str_CopyFast(local_134, (uint32_t *)(&PTR_s_artifact_wav_004fab58)[color_mask]);
        InitSndTrack(local_134,local_28[0],local_28 + 1);
      }
      PlaySnd(local_28[0],0);
    }
    else if (color_mask < 0x22) {
      val_2 = IsSndLoaded(color_mask,local_28);
      if (val_2 == 0) {
        local_2c = GetLRUSnd(local_28,0x1d,0x1d);
        if (local_2c == 0) {
          CloseSndTrack(local_28[0]);
        }
        else if (local_2c != 1) {
          return 0;
        }
        Mem_AllocOrFree_004d9630(local_134,(uint32_t *)&DAT_0060d4a0);
        Str_CopyFast(local_134, (uint32_t *)&DAT_004fb0f0);
        Str_CopyFast(local_134, (uint32_t *)(&PTR_s_buried_wav_004fab5c)[color_mask]);
        InitSndTrack(local_134,local_28[0],local_28 + 1);
      }
      PlaySnd(local_28[0],0);
    }
    else {
      if (0x2f < color_mask) {
        return 0;
      }
      local_28[1] = 400;
      val_2 = IsSndLoaded(color_mask,local_28);
      if (val_2 == 0) {
        if (color_mask == 0x2b) {
          local_28[6] = 0xffffffff;
        }
        else {
          slot_idx = slot_idx | 4;
        }
        Mem_AllocOrFree_004d9630(local_134,(uint32_t *)&DAT_0060d4a0);
        Str_CopyFast(local_134, (uint32_t *)&DAT_004fb0f4);
        Str_CopyFast(local_134, (uint32_t *)(&PTR_s_draw_wav_004fab60)[color_mask]);
        InitSndTrack(local_134,local_28[0],local_28 + 1);
        PlaySnd(local_28[0],local_28 + 1);
      }
      else {
        if (color_mask == 0x2b) {
          local_28[6] = 0xffffffff;
        }
        else {
          slot_idx = slot_idx | 4;
        }
        PlaySnd(local_28[0],local_28 + 1);
      }
    }
    uval_1 = 1;
  }
  return uval_1;
}



/*
 * Decompiled function: Duel_PreloadSoundEffects
 * Entry Point: 0048d320
 * Size: 143 bytes
 */


void Duel_PreloadSoundEffects(void)

{
  uint32_t local_130 [66];
  int local_28;
  uint32_t slot_idx;
  
  slot_idx = slot_idx & 0xfffffffb;
  StopSndTrack();
  for (local_28 = 0; local_28 < 0x14; local_28 = local_28 + 1) {
    Mem_AllocOrFree_004d9630(local_130,(uint32_t *)&DAT_0060d4a0);
    Str_CopyFast(local_130,(uint32_t *)&DAT_004fb0f8);
    Str_CopyFast(local_130,(uint32_t *)(&PTR_s_artifact_wav_004fab58)[local_28]);
    InitSndTrack(local_130,local_28,0);
  }
  return;
}



/*
 * Decompiled function: FUN_0048d3af
 * Entry Point: 0048d3af
 * Size: 16 bytes
 */


void FUN_0048d3af(void)

{
  StopSndTrack();
  return;
}



/*
 * Decompiled function: Magic_ClearSpellStack
 * Entry Point: 0048d3bf
 * Size: 44 bytes
 */


int32_t Magic_ClearSpellStack(void)

{
  DAT_006764b8 = 0;
  DAT_0068efb0 = 0xffffffff;
  return 0;
}



/*
 * Decompiled function: FUN_0048d3eb
 * Entry Point: 0048d3eb
 * Size: 51 bytes
 */


int32_t FUN_0048d3eb(void)

{
  int32_t uval_1;
  
  if (DAT_006764b8 == 0) {
    uval_1 = 0xffffffff;
  }
  else {
    uval_1 = *(int32_t *)(&DAT_0068f23c + DAT_006764b8 * 4);
  }
  return uval_1;
}



/*
 * Decompiled function: FUN_0048d41e
 * Entry Point: 0048d41e
 * Size: 1114 bytes
 */


int32_t FUN_0048d41e(int32_t color_mask)

{
  int val_1;
  int val_2;
  int32_t uval_3;
  int32_t uval_4;
  int32_t uval_5;
  int val_6;
  
  val_6 = DAT_006764b8 + -1;
  val_1 = (&DAT_0068efb0)[val_6 * 2];
  val_2 = *(int *)(&DAT_0068efb4 + val_6 * 8);
  if (*(int *)(&g_DuelCardSlot_CardId + val_2 * 0x120 + val_1 * 0x5b20) == DAT_0068eee0) {
    uval_3 = *(int32_t *)(&g_DuelCardSlot_AttachedAuraSlot + val_2 * 0x120 + val_1 * 0x5b20);
    uval_4 = *(int32_t *)(&g_DuelCardSlot_AttachedAuraPlayer + val_2 * 0x120 + val_1 * 0x5b20);
    uval_5 = *(int32_t *)(&DAT_006826f4 + val_2 * 0x120 + val_1 * 0x5b20);
    FID_conflict__memcpy
              (&DAT_006826c0 + val_1 * 0x5b20 + val_2 * 0x120,
               &DAT_006826c0 +
               *(int *)(&g_DuelCardSlot_AttachedAuraPlayer + val_2 * 0x120 + val_1 * 0x5b20) * 0x5b20 +
               *(int *)(&g_DuelCardSlot_AttachedAuraSlot + val_2 * 0x120 + val_1 * 0x5b20) * 0x120,0x120);
    *(int *)(&g_DuelCardSlot_CardId + val_2 * 0x120 + val_1 * 0x5b20) = DAT_0068eee0;
    *(int32_t *)(&DAT_00682710 + val_2 * 0x120 + val_1 * 0x5b20) = 0;
    (&DAT_006826e0)[val_2 * 0x120 + val_1 * 0x5b20] = 0;
    *(uint32_t *)(&g_DuelCardSlot_Flags + val_2 * 0x120 + val_1 * 0x5b20) =
         *(uint32_t *)(&g_DuelCardSlot_Flags + val_2 * 0x120 + val_1 * 0x5b20) | 2;
    *(int32_t *)(&g_DuelCardSlot_AttachedAuraPlayer + val_2 * 0x120 + val_1 * 0x5b20) = uval_4;
    *(int32_t *)(&g_DuelCardSlot_AttachedAuraSlot + val_2 * 0x120 + val_1 * 0x5b20) = uval_3;
    *(int32_t *)(&DAT_006826f4 + val_2 * 0x120 + val_1 * 0x5b20) = uval_5;
    if (*(int *)(&g_DuelCardSlot_CardId +
                *(int *)(&g_DuelCardSlot_AttachedAuraSlot + val_2 * 0x120 + val_1 * 0x5b20) * 0x120 +
                *(int *)(&g_DuelCardSlot_AttachedAuraPlayer + val_2 * 0x120 + val_1 * 0x5b20) * 0x5b20) != -1) {
      *(int32_t *)(&DAT_006826c0 + val_2 * 0x120 + val_1 * 0x5b20) =
           *(int32_t *)
            (&g_DuelCardSlot_CardId +
            *(int *)(&g_DuelCardSlot_AttachedAuraSlot + val_2 * 0x120 + val_1 * 0x5b20) * 0x120 +
            *(int *)(&g_DuelCardSlot_AttachedAuraPlayer + val_2 * 0x120 + val_1 * 0x5b20) * 0x5b20);
    }
    if ((*(int *)(&DAT_006826c0 + val_2 * 0x120 + val_1 * 0x5b20) < g_DuelTargetCardId) ||
       (g_DuelTargetCardId + 0x1d <= *(int *)(&DAT_006826c0 + val_2 * 0x120 + val_1 * 0x5b20))) {
      *(int32_t *)(&DAT_00682704 + val_2 * 0x120 + val_1 * 0x5b20) =
           *(int32_t *)
            (&DAT_004ff590 +
            *(int *)(&DAT_006826c0 +
                    *(int *)(&g_DuelCardSlot_AttachedAuraSlot + val_2 * 0x120 + val_1 * 0x5b20) * 0x120 +
                    *(int *)(&g_DuelCardSlot_AttachedAuraPlayer + val_2 * 0x120 + val_1 * 0x5b20) * 0x5b20) * 0x34);
    }
  }
  if (g_IsAiThinking != 1) {
    *(int32_t *)(&DAT_00666460 + val_6 * 4) = color_mask;
  }
  *(int *)(&DAT_0068f120 + val_6 * 8) = (int)(char)(&g_DuelCardSlot_ColorMask)[val_2 * 0x120 + val_1 * 0x5b20];
  *(int32_t *)(&DAT_0068f124 + val_6 * 8) =
       *(int32_t *)(&g_DuelCardSlot_TargetSlot + val_2 * 0x120 + val_1 * 0x5b20);
  return 0;
}



/*
 * Decompiled function: Magic_PushSpellStack
 * Entry Point: 0048d878
 * Size: 1062 bytes
 */


int32_t Magic_PushSpellStack(int player_id,int card_slot,int event_type,int arg_4,int32_t arg_5)

{
  int32_t uval_1;
  bool flag_2;
  int match_count;
  
  if (DAT_006764b8 < 0x20) {
    *(int32_t *)(&DAT_0068f240 + DAT_006764b8 * 4) =
         *(int32_t *)(&g_DuelCardSlot_CardId + arg_2 * 0x120 + color_mask * 0x5b20);
    *(uint32_t *)(&DAT_0068f240 + DAT_006764b8 * 4) =
         *(uint32_t *)(&DAT_0068f240 + DAT_006764b8 * 4) | arg_3 << 0x10;
    *(uint32_t *)(&DAT_0068f240 + DAT_006764b8 * 4) =
         *(uint32_t *)(&DAT_0068f240 + DAT_006764b8 * 4) | arg_4 << 0x18;
    if (((arg_3 == 0x71) || (arg_3 == 0x7e)) ||
       (*(int *)(&g_DuelCardSlot_CardId + arg_2 * 0x120 + color_mask * 0x5b20) < 5)) {
      match_count = arg_2;
      flag_2 = true;
    }
    else {
      match_count = Deck_AddCardToDeck(color_mask,DAT_0068eee0);
      if (match_count == -1) {
        flag_2 = false;
      }
      else {
        uval_1 = *(int32_t *)(&DAT_006826f4 + color_mask * 0x5b20 + match_count * 0x120);
        FID_conflict__memcpy
                  (&DAT_006826c0 + match_count * 0x120 + color_mask * 0x5b20,
                   &DAT_006826c0 + color_mask * 0x5b20 + arg_2 * 0x120,0x120);
        *(int *)(&g_DuelCardSlot_CardId + color_mask * 0x5b20 + match_count * 0x120) = DAT_0068eee0;
        *(int32_t *)(&DAT_00682710 + color_mask * 0x5b20 + match_count * 0x120) = 0;
        (&DAT_006826e0)[color_mask * 0x5b20 + match_count * 0x120] = 0;
        if (*(int *)(&g_DuelCardSlot_CardId + arg_2 * 0x120 + color_mask * 0x5b20) == -1) {
          *(int32_t *)(&DAT_006826c0 + color_mask * 0x5b20 + match_count * 0x120) =
               *(int32_t *)(&DAT_006826c0 + arg_2 * 0x120 + color_mask * 0x5b20);
        }
        else {
          *(int32_t *)(&DAT_006826c0 + color_mask * 0x5b20 + match_count * 0x120) =
               *(int32_t *)(&g_DuelCardSlot_CardId + arg_2 * 0x120 + color_mask * 0x5b20);
        }
        *(int32_t *)(&DAT_00682704 + color_mask * 0x5b20 + match_count * 0x120) =
             *(int32_t *)(&DAT_00682704 + arg_2 * 0x120 + color_mask * 0x5b20);
        *(uint32_t *)(&g_DuelCardSlot_Flags + color_mask * 0x5b20 + match_count * 0x120) =
             *(uint32_t *)(&g_DuelCardSlot_Flags + color_mask * 0x5b20 + match_count * 0x120) | 2;
        *(int *)(&g_DuelCardSlot_AttachedAuraPlayer + color_mask * 0x5b20 + match_count * 0x120) = color_mask;
        *(int *)(&g_DuelCardSlot_AttachedAuraSlot + color_mask * 0x5b20 + match_count * 0x120) = arg_2;
        *(int32_t *)(&DAT_006826f4 + color_mask * 0x5b20 + match_count * 0x120) = uval_1;
        flag_2 = true;
      }
    }
    if (flag_2) {
      (&DAT_0068efb0)[DAT_006764b8 * 2] = color_mask;
      *(int *)(&DAT_0068efb4 + DAT_006764b8 * 8) = match_count;
      *(int *)(&DAT_0068f120 + DAT_006764b8 * 8) =
           (int)(char)(&g_DuelCardSlot_ColorMask)[arg_2 * 0x120 + color_mask * 0x5b20];
      *(int32_t *)(&DAT_0068f124 + DAT_006764b8 * 8) =
           *(int32_t *)(&g_DuelCardSlot_TargetSlot + arg_2 * 0x120 + color_mask * 0x5b20);
      if (g_DuelCurrentEventCode == -1) {
        *(int32_t *)(&DAT_00666960 + DAT_006764b8 * 4) = g_DuelCombatPhaseState;
      }
      else {
        *(int *)(&DAT_00666960 + DAT_006764b8 * 4) = g_DuelCurrentEventCode;
      }
      if (g_IsAiThinking != 1) {
        *(int32_t *)(&DAT_00666460 + DAT_006764b8 * 4) = arg_5;
      }
      DAT_006764b8 = DAT_006764b8 + 1;
      (&DAT_0068efb0)[DAT_006764b8 * 2] = 0xffffffff;
    }
  }
  return 0;
}



/*
 * Decompiled function: FUN_0048dc9e
 * Entry Point: 0048dc9e
 * Size: 165 bytes
 */


int32_t FUN_0048dc9e(void)

{
  int val_1;
  int match_count;
  
  for (match_count = 0; match_count < DAT_006764b8; match_count = match_count + 1) {
    val_1 = (&DAT_0068efb0)[match_count * 2];
    *(int *)(&DAT_0068f120 + match_count * 8) =
         (int)(char)(&g_DuelCardSlot_ColorMask)[*(int *)(&DAT_0068efb4 + match_count * 8) * 0x120 + val_1 * 0x5b20];
    *(int32_t *)(&DAT_0068f124 + match_count * 8) =
         *(int32_t *)
          (&g_DuelCardSlot_TargetSlot + *(int *)(&DAT_0068efb4 + match_count * 8) * 0x120 + val_1 * 0x5b20);
  }
  return 0;
}



/*
 * Decompiled function: FUN_0048dd43
 * Entry Point: 0048dd43
 * Size: 1294 bytes
 */


int32_t FUN_0048dd43(void)

{
  int player_id;
  int card_slot;
  int match_count;
  
  if (0 < DAT_006764b8) {
    DAT_006764b8 = DAT_006764b8 + -1;
    color_mask = (&DAT_0068efb0)[DAT_006764b8 * 2];
    arg_2 = *(int *)(&DAT_0068efb4 + DAT_006764b8 * 8);
    match_count = *(int *)(&g_DuelCardSlot_CardId + color_mask * 0x5b20 + arg_2 * 0x120);
    if (match_count == DAT_0068eee0) {
      match_count = *(int *)(&DAT_006826c0 + color_mask * 0x5b20 + arg_2 * 0x120);
    }
    if (*(int *)(&g_DuelCardSlot_CardId + color_mask * 0x5b20 + arg_2 * 0x120) != -1) {
      if ((char)((uint32_t)*(int32_t *)(&DAT_0068f240 + DAT_006764b8 * 4) >> 0x10) == '~') {
        FUN_0046e4c9(color_mask,arg_2,*(uint32_t *)(&DAT_0068f240 + DAT_006764b8 * 4) >> 0x10 & 0xff,
                     *(int *)(&DAT_0068f240 + DAT_006764b8 * 4) >> 0x18);
      }
      else if (((&DAT_006827d4)[color_mask * 0x5b20 + arg_2 * 0x120] & 8) == 0) {
        if (((&DAT_006827d4)[color_mask * 0x5b20 + arg_2 * 0x120] & 0x80) == 0) {
          Duel_PlayCardSoundEffect(color_mask,arg_2,*(uint32_t *)(&DAT_0068f240 + DAT_006764b8 * 4) >> 0x10 & 0xff,
                       1 - color_mask,0xffffffff);
        }
        else {
          if (((&DAT_006827d4)[color_mask * 0x5b20 + arg_2 * 0x120] & 0x40) != 0) {
            *(uint32_t *)(&g_DuelCardSlot_Flags +
                     *(int *)(&g_DuelCardSlot_AttachedAuraPlayer + color_mask * 0x5b20 + arg_2 * 0x120) * 0x5b20 +
                     *(int *)(&g_DuelCardSlot_AttachedAuraSlot + color_mask * 0x5b20 + arg_2 * 0x120) * 0x120) =
                 *(uint32_t *)(&g_DuelCardSlot_Flags +
                          *(int *)(&g_DuelCardSlot_AttachedAuraPlayer + color_mask * 0x5b20 + arg_2 * 0x120) * 0x5b20 +
                          *(int *)(&g_DuelCardSlot_AttachedAuraSlot + color_mask * 0x5b20 + arg_2 * 0x120) * 0x120) &
                 0xffffffef;
            Duel_PlayCardSoundEffect(*(int *)(&g_DuelCardSlot_AttachedAuraPlayer + color_mask * 0x5b20 + arg_2 * 0x120),
                         *(int *)(&g_DuelCardSlot_AttachedAuraSlot + color_mask * 0x5b20 + arg_2 * 0x120),0x83,1 - color_mask,
                         0xffffffff);
          }
          *(uint32_t *)(&DAT_006827d4 +
                   *(int *)(&g_DuelCardSlot_AttachedAuraPlayer + color_mask * 0x5b20 + arg_2 * 0x120) * 0x5b20 +
                   *(int *)(&g_DuelCardSlot_AttachedAuraSlot + color_mask * 0x5b20 + arg_2 * 0x120) * 0x120) =
               *(uint32_t *)(&DAT_006827d4 +
                        *(int *)(&g_DuelCardSlot_AttachedAuraPlayer + color_mask * 0x5b20 + arg_2 * 0x120) * 0x5b20 +
                        *(int *)(&g_DuelCardSlot_AttachedAuraSlot + color_mask * 0x5b20 + arg_2 * 0x120) * 0x120) &
               0xffffff7f;
        }
      }
      else {
        if (((((&DAT_006827d5)[color_mask * 0x5b20 + arg_2 * 0x120] & 2) == 0) &&
            (Duel_PlayCardSoundEffect(color_mask,arg_2,0x86,1 - color_mask,0xffffffff),
            *(int *)(&g_DuelCardSlot_CardId + color_mask * 0x5b20 + arg_2 * 0x120) != -1)) &&
           (((&DAT_006827d4)[color_mask * 0x5b20 + arg_2 * 0x120] & 2) != 0)) {
          Duel_DrawCardSprite(*(int *)(&g_DuelCardSlot_AttachedAuraPlayer + color_mask * 0x5b20 + arg_2 * 0x120),
                       *(int *)(&g_DuelCardSlot_AttachedAuraSlot + color_mask * 0x5b20 + arg_2 * 0x120),1);
        }
        *(uint32_t *)(&DAT_006827d4 +
                 *(int *)(&g_DuelCardSlot_AttachedAuraPlayer + color_mask * 0x5b20 + arg_2 * 0x120) * 0x5b20 +
                 *(int *)(&g_DuelCardSlot_AttachedAuraSlot + color_mask * 0x5b20 + arg_2 * 0x120) * 0x120) =
             *(uint32_t *)(&DAT_006827d4 +
                      *(int *)(&g_DuelCardSlot_AttachedAuraPlayer + color_mask * 0x5b20 + arg_2 * 0x120) * 0x5b20 +
                      *(int *)(&g_DuelCardSlot_AttachedAuraSlot + color_mask * 0x5b20 + arg_2 * 0x120) * 0x120) & 0xfffffdf7
        ;
        *(uint32_t *)(&DAT_006827d4 +
                 *(int *)(&g_DuelCardSlot_AttachedAuraPlayer + color_mask * 0x5b20 + arg_2 * 0x120) * 0x5b20 +
                 *(int *)(&g_DuelCardSlot_AttachedAuraSlot + color_mask * 0x5b20 + arg_2 * 0x120) * 0x120) =
             *(uint32_t *)(&DAT_006827d4 +
                      *(int *)(&g_DuelCardSlot_AttachedAuraPlayer + color_mask * 0x5b20 + arg_2 * 0x120) * 0x5b20 +
                      *(int *)(&g_DuelCardSlot_AttachedAuraSlot + color_mask * 0x5b20 + arg_2 * 0x120) * 0x120) | 4;
      }
      if (*(int *)(&g_DuelCardSlot_CardId + color_mask * 0x5b20 + arg_2 * 0x120) == DAT_0068eee0) {
        Duel_DrawCardSprite(color_mask,arg_2,4);
      }
    }
    (&DAT_0068efb0)[DAT_006764b8 * 2] = 0xffffffff;
    FUN_0048b64f();
    if (((((&DAT_004ff5a9)[match_count * 0x34] & 0x10) == 0) || (((uint8_t)g_DuelModeFlags & 2) != 0)) &&
       ((DAT_0068eedc < 2 && (((g_DuelModeFlags._1_1_ & 2) == 0 || (DAT_006764b8 == 0)))))) {
      Rules_ProcessDamagePrevention(g_TurnPlayer);
      Rules_SendCardsToGraveyard();
    }
  }
  return 0;
}



/*
 * Decompiled function: FUN_0048e251
 * Entry Point: 0048e251
 * Size: 177 bytes
 */


int32_t FUN_0048e251(void)

{
  if (0 < DAT_006764b8) {
    DAT_006764b8 = DAT_006764b8 + -1;
    if (DAT_0068eee0 ==
        *(int *)(&g_DuelCardSlot_CardId +
                *(int *)(&DAT_0068efb4 + DAT_006764b8 * 8) * 0x120 +
                (&DAT_0068efb0)[DAT_006764b8 * 2] * 0x5b20)) {
      *(int32_t *)
       (&g_DuelCardSlot_CardId +
       *(int *)(&DAT_0068efb4 + DAT_006764b8 * 8) * 0x120 +
       (&DAT_0068efb0)[DAT_006764b8 * 2] * 0x5b20) = 0xffffffff;
    }
    (&DAT_0068efb0)[DAT_006764b8 * 2] = 0xffffffff;
  }
  return 0;
}



/*
 * Decompiled function: Mem_AllocOrFree_0048e302
 * Entry Point: 0048e302
 * Size: 41 bytes
 */


void Mem_AllocOrFree_0048e302(void)

{
  DAT_0068ecc4 = 0;
  DAT_0068f2d8 = 0;
  DAT_004f965c = 0;
  return;
}



/*
 * Decompiled function: FUN_0048e32b
 * Entry Point: 0048e32b
 * Size: 218 bytes
 */


int32_t FUN_0048e32b(int x,int card_slot,int32_t arg_3,int32_t arg_4)

{
  int32_t uval_1;
  int val_2;
  int32_t uval_3;
  
  uval_1 = DAT_0068eee4;
  if (((DAT_006764b8 == 0) && (val_2 = FUN_0042a99c(), val_2 != 0)) && (x != -2)) {
    DAT_0068eee4 = 1;
  }
  do {
    DAT_0068f110 = 0;
    uval_3 = FUN_0048e405(x,arg_2,arg_3,arg_4);
    if ((DAT_0068f110 == 0) || (0 < DAT_006764b8)) break;
  } while (g_IsAiThinking != 1);
  DAT_0068eee4 = uval_1;
  if (DAT_006764b8 == 0) {
    DAT_0068eee4 = 0;
    *(uint32_t *)(&DAT_006667c0 + g_TurnPlayer * 0x98 + g_DuelCombatPhaseState * 4) =
         *(uint32_t *)(&DAT_006667c0 + g_TurnPlayer * 0x98 + g_DuelCombatPhaseState * 4) & 0xfffffffd;
  }
  return uval_3;
}



/*
 * Decompiled function: FUN_0048e405
 * Entry Point: 0048e405
 * Size: 1187 bytes
 */


int FUN_0048e405(int x,int y,uint32_t *arg_3,int32_t arg_4)

{
  int32_t uval_1;
  int32_t uval_2;
  int32_t uval_3;
  int val_4;
  int local_98;
  int local_94;
  uint32_t local_8c [32];
  int32_t match_count;
  int32_t slot_idx;
  
  uval_3 = DAT_00676500;
  uval_2 = DAT_00666744;
  uval_1 = DAT_00666404;
  match_count = g_DuelCurrentEventCode;
  g_DuelCurrentEventCode = 0xffffffff;
  DAT_0068f2d8 = DAT_0068f2d8 + 1;
  if (DAT_0068f2d8 == 1) {
    DAT_0068ecc4 = 0;
  }
  else if ((((DAT_0068ecc4 < DAT_0068f2d8) && (y != 0x8e)) && (y != 0x70)) && (y != 0xd3)) {
    DAT_0068ecc4 = DAT_0068f2d8;
  }
  local_94 = 0;
  DAT_00666744 = arg_4;
  slot_idx = DAT_004fac20;
  if ((x == -2) && (val_4 = FUN_0042a99c(), val_4 == 0)) {
    DAT_004fac20 = 1;
  }
  else {
    DAT_004fac20 = 0;
  }
  val_4 = FUN_0042a99c();
  if ((val_4 == 0) &&
     ((*(int *)(&DAT_006667c0 + y * 4 + g_TurnPlayer * 0x98) != 0 ||
      ((g_TurnPlayer == DAT_0066aac4 && (DAT_0066ab04 == y)))))) {
    DAT_00666404 = 1;
  }
  else {
    DAT_00666404 = 0;
  }
  if ((-1 < x) && (DAT_00666404 == 0)) {
LAB_0048e800:
    DAT_0068f2d8 = DAT_0068f2d8 + -1;
    if ((DAT_0068f2d8 == 0) && (DAT_006826b4 = 0xffffffff, DAT_0068eedc == 0)) {
      DAT_0068eee4 = 0;
      DAT_00681ed0 = 0;
    }
    DAT_0068ef98 = 0xffffffff;
    DAT_00666404 = uval_1;
    DAT_004fac20 = slot_idx;
    DAT_00676500 = uval_3;
    g_DuelCurrentEventCode = match_count;
    DAT_00666744 = uval_2;
    if (local_94 != 0) {
      DAT_0067650c = 0;
    }
    return local_94;
  }
  Mem_AllocOrFree_004d9630(local_8c,arg_3);
  if ((g_DuelCombatPhaseState == 4) && (DAT_0068f2d8 == 1)) {
    DAT_00681eb4 = g_TurnPlayer;
    FUN_0048f1b1();
  }
  do {
    do {
      if (g_TurnPlayer == 0) {
        DAT_00666440 = 1;
      }
      else if (x < 0) {
        DAT_00666440 = 2;
      }
      else {
        DAT_00666440 = 0;
      }
      if (DAT_0068f2d8 < 2) {
        DAT_0068ef98 = 0xffffffff;
      }
      g_DuelHumanPlayerIndex = 0;
      DAT_00676500 = 0;
      local_98 = UI_PromptFastEffectsDialog(g_TurnPlayer,local_8c);
      if (local_98 != 0) {
        DAT_0068f110 = 1;
      }
      if (((g_TurnPlayer == g_DuelTargetPlayer) && (local_98 != 0)) && (g_IsAiThinking != 1)) {
        local_94 = 1;
      }
      if ((DAT_0068f2d8 < DAT_0068ecc4) && (-1 < DAT_006764b8)) {
        local_98 = 0;
      }
    } while ((local_98 != 0) || (((DAT_00676500 & 1) != 0 && (DAT_0068f2d8 == 1))));
    if ((g_DuelCombatPhaseState == 4) && (DAT_0068f2d8 == 1)) {
      DAT_00681eb4 = 1 - g_TurnPlayer;
      FUN_0048f1b1();
    }
    while( true ) {
      if (g_TurnPlayer == 0) {
        if (x < 0) {
          DAT_00666440 = 2;
        }
        else {
          DAT_00666440 = 0;
        }
      }
      else {
        DAT_00666440 = 1;
      }
      if (DAT_0068f2d8 < 2) {
        DAT_0068ef98 = 0xffffffff;
      }
      g_DuelHumanPlayerIndex = 0;
      DAT_00676500 = 0;
      if (((DAT_0068f2d8 < DAT_0068ecc4) && (-1 < DAT_006764b8)) ||
         (val_4 = UI_PromptFastEffectsDialog(1 - g_TurnPlayer,local_8c), val_4 == 0)) goto LAB_0048e800;
      DAT_0068f110 = 1;
      if (g_IsAiThinking != 1) break;
      if ((g_TurnPlayer != g_DuelTargetPlayer) && (((DAT_00676500 & 1) == 0 || (DAT_0068f2d8 != 1))))
      goto LAB_0048e800;
    }
  } while( true );
}



/*
 * Decompiled function: FUN_0048e8a8
 * Entry Point: 0048e8a8
 * Size: 74 bytes
 */


int32_t FUN_0048e8a8(int x,int32_t arg_2,int32_t arg_3,int arg_4)

{
  Magic_RunTurnStep(x,arg_2,arg_3,arg_4);
  Magic_RunTurnStep(1 - x,arg_2,arg_3,arg_4);
  return 1;
}



/*
 * Decompiled function: Magic_RunTurnStep
 * Entry Point: 0048e8f2
 * Size: 495 bytes
 */


int32_t Magic_RunTurnStep(int x,int32_t arg_2,int32_t arg_3,int height)

{
  int32_t uval_1;
  int32_t uval_2;
  int32_t uval_3;
  int32_t uval_4;
  uint32_t uval_5;
  int val_6;
  int target_idx;
  
  uval_5 = DAT_0068ef98;
  uval_4 = DAT_00681ec4;
  uval_3 = DAT_00666758;
  uval_2 = DAT_00666744;
  uval_1 = DAT_00666440;
  DAT_0068eedc = DAT_0068eedc + 1;
  DAT_00666744 = arg_2;
  DAT_00681ec4 = x;
  do {
    if (x == 0) {
      DAT_00666440 = 1;
    }
    else {
      DAT_00666440 = 2;
    }
    g_DuelCurrentEventCode = arg_2;
    if (height == 0) {
      DAT_0068ef98 = 0;
    }
    else {
      DAT_0068ef98 = 0x30;
    }
    g_DuelHumanPlayerIndex = 0;
    DAT_00666454 = 0;
    DAT_00666758 = 0;
    val_6 = UI_PromptFastEffectsDialog(x,arg_3);
    DAT_006826b4 = uval_5 & 0x30;
  } while (((DAT_00666758 & (-(uint32_t)(val_6 == 0) & 0xfffffffe) + 6) != 0) ||
          ((height != 0 && (val_6 != 0))));
  g_DuelCurrentEventCode = 0xffffffff;
  DAT_0068eedc = DAT_0068eedc + -1;
  DAT_00666440 = uval_1;
  DAT_0068ef98 = uval_5;
  if (DAT_0068eedc == 0) {
    for (x = 0; x < 2; x = x + 1) {
      for (target_idx = 0; target_idx < (int)(&g_DuelPlayerCreatureCount)[x]; target_idx = target_idx + 1) {
        *(uint32_t *)(&g_DuelCardSlot_Flags + x * 0x5b20 + target_idx * 0x120) =
             *(uint32_t *)(&g_DuelCardSlot_Flags + x * 0x5b20 + target_idx * 0x120) & 0xfffffeff;
      }
    }
    if (DAT_0068f2d8 == 0) {
      DAT_0068eee4 = 0;
      DAT_00681ed0 = 0;
    }
  }
  DAT_00666758 = uval_3;
  DAT_00681ec4 = uval_4;
  DAT_00666744 = uval_2;
  return 0;
}



/*
 * Decompiled function: FUN_0048eae1
 * Entry Point: 0048eae1
 * Size: 68 bytes
 */


int32_t FUN_0048eae1(void)

{
  int slot_idx;
  
  for (slot_idx = 0; slot_idx < 500; slot_idx = slot_idx + 1) {
    *(int32_t *)(&DAT_00690320 + slot_idx * 4) = 0xffffffff;
  }
  return 0;
}



/*
 * Decompiled function: FUN_0048eb25
 * Entry Point: 0048eb25
 * Size: 142 bytes
 */


int FUN_0048eb25(int x,int arg2)

{
  int slot_idx;
  
  slot_idx = 0;
  while( true ) {
    if (499 < slot_idx) {
      return -1;
    }
    if (*(int *)(&DAT_00690320 + slot_idx * 4) == -1) break;
    slot_idx = slot_idx + 1;
  }
  *(int *)(&DAT_00690320 + slot_idx * 4) = x;
  *(int *)(&DAT_00681ee0 + slot_idx * 4) = arg2;
  *(int *)(&DAT_006826f4 + arg2 * 0x120 + x * 0x5b20) = slot_idx;
  return slot_idx;
}



/*
 * Decompiled function: FUN_0048ebb3
 * Entry Point: 0048ebb3
 * Size: 357 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0048ebb3(void)

{
  int match_count;
  int slot_idx;
  
  for (slot_idx = 0; slot_idx < 500; slot_idx = slot_idx + 1) {
    while ((*(int *)(&DAT_00690320 + slot_idx * 4) != -1 &&
           ((match_count = slot_idx,
            *(int *)(&g_DuelCardSlot_CardId +
                    *(int *)(&DAT_00681ee0 + slot_idx * 4) * 0x120 +
                    *(int *)(&DAT_00690320 + slot_idx * 4) * 0x5b20) == -1 ||
            (*(int *)(&DAT_006826f4 +
                     *(int *)(&DAT_00681ee0 + slot_idx * 4) * 0x120 +
                     *(int *)(&DAT_00690320 + slot_idx * 4) * 0x5b20) != slot_idx))))) {
      while (match_count = match_count + 1, match_count < 500) {
        *(int32_t *)(&DAT_0069031c + match_count * 4) = *(int32_t *)(&DAT_00690320 + match_count * 4);
        *(int32_t *)(&DAT_00681edc + match_count * 4) = *(int32_t *)(&DAT_00681ee0 + match_count * 4);
        if (*(int *)(&DAT_006826f4 +
                    *(int *)(&DAT_00681ee0 + match_count * 4) * 0x120 +
                    *(int *)(&DAT_00690320 + match_count * 4) * 0x5b20) == match_count) {
          *(int *)(&DAT_006826f4 +
                  *(int *)(&DAT_00681ee0 + match_count * 4) * 0x120 +
                  *(int *)(&DAT_00690320 + match_count * 4) * 0x5b20) =
               *(int *)(&DAT_006826f4 +
                       *(int *)(&DAT_00681ee0 + match_count * 4) * 0x120 +
                       *(int *)(&DAT_00690320 + match_count * 4) * 0x5b20) + -1;
        }
      }
      _DAT_00690aec = 0xffffffff;
    }
  }
  return;
}



/*
 * Decompiled function: FUN_0048ed18
 * Entry Point: 0048ed18
 * Size: 377 bytes
 */


int32_t FUN_0048ed18(int x,int arg2)

{
  int32_t uval_1;
  int val_2;
  int match_count;
  uint32_t slot_idx;
  
  if (((&g_DuelCardSlot_Flags)[arg2 * 0x120 + x * 0x5b20] & 0x10) == 0) {
    uval_1 = 0;
  }
  else {
    match_count = 0;
    for (slot_idx = 1; (int)slot_idx < 7; slot_idx = slot_idx + 1) {
      if ((&DAT_006827cc)[slot_idx + x * 0x5b20 + arg2 * 0x120] != '\0') {
        val_2 = Duel_DrawString(x,slot_idx,
                             (int)(char)(&DAT_006827cc)[slot_idx + x * 0x5b20 + arg2 * 0x120]);
        if (val_2 == 0) {
          return 0;
        }
        match_count = match_count + (char)(&DAT_006827cc)[slot_idx + x * 0x5b20 + arg2 * 0x120];
      }
    }
    val_2 = Duel_DrawString(x,7,(char)(&DAT_006827cc)[arg2 * 0x120 + x * 0x5b20] + match_count);
    if (val_2 == 0) {
      uval_1 = 0;
    }
    else {
      Duel_PlayCardSoundEffect(x,arg2,0x88,1 - x,0xffffffff);
      if (DAT_0068edd8 == 0) {
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
 * Decompiled function: FUN_0048ee91
 * Entry Point: 0048ee91
 * Size: 470 bytes
 */


void FUN_0048ee91(int player_id)

{
  bool flag_1;
  int val_2;
  int target_idx;
  int card_idx;
  
  val_2 = 1 - color_mask;
  for (card_idx = 0; card_idx < (int)(&g_DuelPlayerCreatureCount)[color_mask]; card_idx = card_idx + 1) {
    if ((*(int *)(&g_DuelCardSlot_CardId + card_idx * 0x120 + color_mask * 0x5b20) != -1) &&
       (((uint8_t)*(int32_t *)(&g_DuelCardSlot_Flags + card_idx * 0x120 + color_mask * 0x5b20) & 6) == 6)) {
      flag_1 = false;
      for (target_idx = 0; target_idx < (int)(&g_DuelPlayerCreatureCount)[val_2]; target_idx = target_idx + 1) {
        if ((*(int *)(&g_DuelCardSlot_CardId + target_idx * 0x120 + val_2 * 0x5b20) != -1) &&
           ((char)(&DAT_006826de)[target_idx * 0x120 + val_2 * 0x5b20] == card_idx)) {
          flag_1 = true;
        }
      }
      if (flag_1) {
        for (target_idx = 0; target_idx < (int)(&g_DuelPlayerCreatureCount)[color_mask]; target_idx = target_idx + 1) {
          if ((target_idx == card_idx) ||
             (((char)(&DAT_006826de)[target_idx * 0x120 + color_mask * 0x5b20] == card_idx &&
              (((uint8_t)*(int32_t *)(&g_DuelCardSlot_Flags + target_idx * 0x120 + color_mask * 0x5b20) & 6) == 6))
             )) {
            *(uint32_t *)(&g_DuelCardSlot_Flags + target_idx * 0x120 + color_mask * 0x5b20) =
                 *(uint32_t *)(&g_DuelCardSlot_Flags + target_idx * 0x120 + color_mask * 0x5b20) | 0x200;
          }
        }
      }
    }
  }
  return;
}



/*
 * Decompiled function: FUN_0048f067
 * Entry Point: 0048f067
 * Size: 183 bytes
 */


int32_t FUN_0048f067(int x,int arg2)

{
  int32_t uval_1;
  int slot_idx;
  
  if ((x == -1) || (arg2 == -1)) {
    uval_1 = 0;
  }
  else {
    slot_idx = *(int *)(&g_DuelCardSlot_CardId + arg2 * 0x120 + x * 0x5b20);
    if (DAT_0068eee0 == slot_idx) {
      slot_idx = *(int *)(&DAT_006826c0 + arg2 * 0x120 + x * 0x5b20);
    }
    if (slot_idx == -1) {
      uval_1 = 0;
    }
    else if (((&DAT_004ff5aa)[slot_idx * 0x34] & 2) == 0) {
      uval_1 = 0;
    }
    else {
      uval_1 = 1;
    }
  }
  return uval_1;
}



/*
 * Decompiled function: FUN_0048f123
 * Entry Point: 0048f123
 * Size: 142 bytes
 */


void FUN_0048f123(void)

{
  int val_1;
  int match_count;
  int slot_idx;
  
  for (slot_idx = 0; slot_idx < 2; slot_idx = slot_idx + 1) {
    for (match_count = 0; match_count < (int)(&g_DuelPlayerCreatureCount)[slot_idx]; match_count = match_count + 1) {
      val_1 = Duel_CardIsTapped(slot_idx,match_count);
      if (val_1 != 0) {
        *(int32_t *)(&DAT_006827d4 + match_count * 0x120 + slot_idx * 0x5b20) = 0;
      }
    }
  }
  return;
}



/*
 * Decompiled function: FUN_0048f1b1
 * Entry Point: 0048f1b1
 * Size: 361 bytes
 */


void FUN_0048f1b1(void)

{
  int val_1;
  int card_idx;
  int match_count;
  int slot_idx;
  
  for (slot_idx = 0; slot_idx < 2; slot_idx = slot_idx + 1) {
    for (card_idx = 0; card_idx < (int)(&g_DuelPlayerCreatureCount)[slot_idx]; card_idx = card_idx + 1) {
      if (((&DAT_006827d4)[slot_idx * 0x5b20 + card_idx * 0x120] & 4) == 0) {
        val_1 = Duel_CardIsTapped(slot_idx,card_idx);
        if (val_1 != 0) {
          for (match_count = 0; match_count < 7; match_count = match_count + 1) {
            (&DAT_006827cc)[match_count + card_idx * 0x120 + slot_idx * 0x5b20] = 0;
            (&DAT_006827d8)[match_count + card_idx * 0x120 + slot_idx * 0x5b20] =
                 (&DAT_006827cc)[match_count + card_idx * 0x120 + slot_idx * 0x5b20];
          }
          *(int32_t *)(&DAT_006827d4 + slot_idx * 0x5b20 + card_idx * 0x120) = 0;
          FUN_0048c50b(slot_idx,card_idx,0x85);
          FUN_0048c50b(slot_idx,card_idx,0x84);
        }
      }
    }
  }
  return;
}



/*
 * Decompiled function: FUN_0048f31a
 * Entry Point: 0048f31a
 * Size: 475 bytes
 */


uint32_t FUN_0048f31a(int x,int y,int width,int height)

{
  uint32_t uval_1;
  uint32_t slot_idx;
  
  slot_idx = 0;
  if (((&DAT_006827df)[y * 0x120 + x * 0x5b20] == '\0') &&
     ((&DAT_006827df)[width * 0x5b20 + height * 0x120] == '\0')) {
    uval_1 = 0;
  }
  else {
    if ((((&DAT_006826dd)[width * 0x5b20 + height * 0x120] & (&DAT_006827df)[y * 0x120 + x * 0x5b20]
         & 0x3f) != 0) &&
       ((slot_idx = 1,
        (&DAT_004ff595)[*(int *)(&g_DuelCardSlot_CardId + width * 0x5b20 + height * 0x120) * 0x34] == '\0' &&
        (((&DAT_006827df)[y * 0x120 + x * 0x5b20] & 0x80) == 0)))) {
      slot_idx = 0;
    }
    uval_1 = slot_idx;
    if (((((&DAT_006827df)[width * 0x5b20 + height * 0x120] &
           (&DAT_006826dd)[y * 0x120 + x * 0x5b20] & 0x3f) != 0) &&
        (uval_1 = slot_idx | 2,
        (&DAT_004ff595)[*(int *)(&g_DuelCardSlot_CardId + y * 0x120 + x * 0x5b20) * 0x34] == '\0')) &&
       (((&DAT_006827df)[width * 0x5b20 + height * 0x120] & 0x80) == 0)) {
      uval_1 = slot_idx;
    }
  }
  return uval_1;
}



/*
 * Decompiled function: Palette_Subsystem_0049608e
 * Entry Point: 0048f500
 * Size: 3217 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int32_t Palette_Subsystem_0049608e(HWND hwnd,uint32_t y,HDC hdc,uint32_t height)

{
  POINT pt;
  POINT pt_00;
  LRESULT LVar1;
  int32_t uval_2;
  HBRUSH hbr;
  int val_3;
  int val_4;
  BOOL BVar5;
  HWND pHVar6;
  uint32_t color_mask;
  size_t sVar7;
  HGDIOBJ ho;
  tagRECT *lpRect;
  char local_134 [12];
  HDC local_128;
  tagPAINTSTRUCT local_124;
  int32_t local_e4;
  int local_e0;
  int local_dc;
  int local_d8;
  int local_d4;
  uint32_t local_d0;
  uint32_t local_cc;
  WPARAM local_c8;
  WPARAM local_c4;
  tagRECT local_c0;
  uint32_t local_b0;
  tagRECT local_ac;
  HDC local_9c;
  tagRECT local_98;
  LRESULT local_88;
  uint32_t local_84;
  HGDIOBJ local_80;
  LOGFONTA local_7c;
  HFONT local_40;
  HANDLE local_3c;
  int local_38;
  int32_t local_34;
  HWND local_30;
  tagRECT local_2c;
  int color_idx;
  int target_idx;
  tagRECT player_idx;
  
  if (y < 0x15) {
    if (y == 0x14) {
      local_9c = hdc;
      GDI_RealizeAndFlushPalette(hdc);
      GetClientRect(hwnd,&local_98);
      if (DAT_005daf00 == (HANDLE)0x0) {
        hbr = GetStockObject(0);
        FillRect(local_9c,&local_98,hbr);
      }
      else {
        GDI_DrawBitmapToHDC((int)local_9c,(int)&local_98,DAT_005daf00);
      }
      return 1;
    }
    if (y == 0xf) {
      pHVar6 = GetDlgItem(hwnd,0x3f1);
      UpdateWindow(pHVar6);
      local_128 = BeginPaint(hwnd,&local_124);
      if (local_128 != (HDC)0x0) {
        GDI_RealizeAndFlushPalette(local_128);
        local_dc = Deck_ValidateCardLimit(*DAT_005dae18, DAT_005dae18[1]);
        color_mask = FUN_00448304(*DAT_005dae18,DAT_005dae18[1]);
        local_e0 = CardIDFromType(color_mask);
        if (local_dc == -1) {
          if ((((local_e0 != -1) && (local_e0 != DAT_0068f108)) && (local_e0 != DAT_00666720)) &&
             (((local_e0 != DAT_00666450 && (local_e0 != DAT_00666444)) &&
              ((local_e0 != DAT_0066aae8 &&
               ((local_e0 != DAT_0068f0fc &&
                (Palette_Subsystem_0049c7c7
                           (local_128,&DAT_005dae08,(int32_t *)(&DAT_00618ac0 + local_e0 * 0x98),
                            0,0x12,0), DAT_005f77f0 != 0)))))))) {
            _sprintf(local_134,s__d__d_004fb138,*DAT_005dae18,DAT_005dae18[1]);
            SetBkMode(local_128,1);
            SetTextColor(local_128,0);
            sVar7 = _strlen(local_134);
            TextOutA(local_128,DAT_005dae08 + 5,
                     DAT_005dae0c + ((DAT_005dae14 - DAT_005dae0c) * 0x14) / 100,local_134,sVar7);
            SetTextColor(local_128,0xffffff);
            sVar7 = _strlen(local_134);
            TextOutA(local_128,DAT_005dae08 + 4,
                     DAT_005dae0c + ((DAT_005dae14 - DAT_005dae0c) * 0x14) / 100 + -1,local_134,
                     sVar7);
          }
        }
        else {
          local_e4 = FUN_00486c12(local_dc,*DAT_005dae18,DAT_005dae18[1]);
          if (local_dc == DAT_0068f108) {
            FUN_0042043e(local_128,(RECT *)&DAT_005dae08);
          }
          else if ((((local_dc == DAT_00666720) || (local_dc == DAT_00666450)) ||
                   (local_dc == DAT_00666444)) || (local_dc == DAT_0066aae8)) {
            Palette_Subsystem_0049eda9
                      (local_128,&DAT_005dae08,local_dc,*DAT_005dae18,DAT_005dae18[1]);
          }
          else if (DAT_0068f0fc == local_dc) {
            FUN_0042297a(local_128,(RECT *)&DAT_005dae08,*DAT_005dae18,DAT_005dae18[1]);
          }
          else {
            FUN_004215c2(local_128,&DAT_005dae08,(int)(&DAT_00618ac0 + local_dc * 0x98),
                         *DAT_005dae18,DAT_005dae18[1],0x12,0);
          }
          if (DAT_005f77f0 != 0) {
            _sprintf(local_134,s__d__d_004fb130,*DAT_005dae18,DAT_005dae18[1]);
            SetBkMode(local_128,1);
            SetTextColor(local_128,0);
            sVar7 = _strlen(local_134);
            TextOutA(local_128,DAT_005dae08 + 5,
                     DAT_005dae0c + ((DAT_005dae14 - DAT_005dae0c) * 0x14) / 100,local_134,sVar7);
            SetTextColor(local_128,0xffffff);
            sVar7 = _strlen(local_134);
            TextOutA(local_128,DAT_005dae08 + 4,
                     DAT_005dae0c + ((DAT_005dae14 - DAT_005dae0c) * 0x14) / 100 + -1,local_134,
                     sVar7);
          }
        }
        EndPaint(hwnd,&local_124);
      }
      return 1;
    }
  }
  else if (y < 0x201) {
    if (y == 0x200) {
LAB_0048fa2f:
      local_d0 = height & 0xffff;
      local_cc = height >> 0x10;
      if (((y == 0x200) && (DAT_00663e24 != 2)) || ((y == 0x204 && (DAT_00663e24 == 2)))) {
        local_c8 = Deck_ValidateCardLimit(*DAT_005dae18, DAT_005dae18[1]);
        if ((DAT_005dae18[2] == -1) || (DAT_005dae18[3] == -1)) {
          local_c4 = 0xffffffff;
        }
        else {
          local_c4 = Deck_ValidateCardLimit(DAT_005dae18[2],DAT_005dae18[3]);
        }
        if ((local_c8 == 0xffffffff) ||
           (pt.y = local_cc, pt.x = local_d0, BVar5 = PtInRect((RECT *)&DAT_005dae08,pt), BVar5 == 0
           )) {
          if ((local_c4 != 0xffffffff) &&
             (pt_00.y = local_cc, pt_00.x = local_d0, BVar5 = PtInRect((RECT *)&DAT_005dae20,pt_00),
             BVar5 != 0)) {
            local_d8 = DAT_005dae18[2];
            local_d4 = DAT_005dae18[3];
            SendMessageA(DAT_006152e0,0x401,local_c4,(LPARAM)&local_d8);
          }
        }
        else {
          local_d8 = *DAT_005dae18;
          local_d4 = DAT_005dae18[1];
          SendMessageA(DAT_006152e0,0x401,local_c8,(LPARAM)&local_d8);
        }
      }
      return 0;
    }
    if (y == 0x110) {
      _DAT_005dae30 = 0;
      if (DAT_0068f0b0 != 0) {
        SetTimer(hwnd,1,2000,(TIMERPROC)0x0);
      }
      lpRect = &local_2c;
      pHVar6 = GetDlgItem(hwnd,0x3f1);
      GetWindowRect(pHVar6,lpRect);
      MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_2c,2);
      GetClientRect(hwnd,&player_idx);
      color_idx = local_2c.top;
      target_idx = player_idx.right - local_2c.right;
      InflateRect(&player_idx,-local_2c.top,-target_idx);
      CopyRect((LPRECT)&DAT_005dae08,&player_idx);
      _DAT_005dae10 = local_2c.left - color_idx;
      CopyRect((LPRECT)&DAT_005dae20,&player_idx);
      DAT_005dae20 = local_2c.left;
      DAT_005dae24 = local_2c.bottom;
      if (DAT_005dae2c - local_2c.bottom < DAT_005dae28 - local_2c.left) {
        DAT_005dae28 = (DAT_005dae2c - local_2c.bottom) + local_2c.left;
      }
      else {
        DAT_005dae2c = (DAT_005dae28 - local_2c.left) + local_2c.bottom;
      }
      DAT_005dae18 = (int *)height;
      SetDlgItemTextA(hwnd,0x3f1,*(LPCSTR *)(height + 0x10));
      SendDlgItemMessageA(hwnd,0x3f1,0x401,*(WPARAM *)((int)DAT_005dae18 + 0x14),0);
      if (*(int *)((int)DAT_005dae18 + 8) != -1) {
        local_38 = *(int *)((int)DAT_005dae18 + 8);
        local_34 = *(int32_t *)((int)DAT_005dae18 + 0xc);
        local_30 = CreateWindowExA(0,s_MAGICGAME_BigCardCardClass_004fb114,
                                   s_BigCard_small_card_004fb100,0x50000000,DAT_005dae20,
                                   DAT_005dae24,DAT_0061534c,DAT_0061898c,hwnd,(HMENU)0x1,
                                   g_DuelInstanceHandle,&local_38);
      }
      local_3c = (HANDLE)SendDlgItemMessageA(hwnd,0x3f1,0x31,0,0);
      GetObjectA(local_3c,0x3c,&local_7c);
      local_7c.lfWeight = 700;
      local_40 = CreateFontIndirectA(&local_7c);
      SendDlgItemMessageA(hwnd,0x3f1,0x30,(WPARAM)local_40,0);
      pHVar6 = GetDlgItem(hwnd,0x3f1);
      SetFocus(pHVar6);
      LVar1 = SendDlgItemMessageA(hwnd,0x3f1,0x400,0,0);
      if ((LVar1 == 0) || (*(int *)((int)DAT_005dae18 + 0x14) == 0)) {
        SetTimer(hwnd,1,DAT_0060d498,(TIMERPROC)0x0);
      }
      return 0;
    }
    if (y == 0x111) {
      if (((height & 0xffff) == 1) || ((height & 0xffff) == 2)) {
        pHVar6 = GetDlgItem(hwnd,0x3f1);
        SendMessageA(hwnd,0x111,0x3f1,(LPARAM)pHVar6);
      }
      else if (((uint32_t)hdc & 0xffff) == 0x3f1) {
        local_84 = (uint32_t)hdc >> 0x10;
        local_88 = SendDlgItemMessageA(hwnd,0x3f1,0x400,0,0);
        if (local_84 == 0) {
          if ((local_88 == 0) || (DAT_005dae18[5] == 0)) {
            local_80 = (HGDIOBJ)SendDlgItemMessageA(hwnd,0x3f1,0x31,0,0);
            SendDlgItemMessageA(hwnd,0x3f1,0x30,0,0);
            DeleteObject(local_80);
            EndDialog(hwnd,local_84);
          }
        }
        else {
          local_80 = (HGDIOBJ)SendDlgItemMessageA(hwnd,0x3f1,0x31,0,0);
          SendDlgItemMessageA(hwnd,0x3f1,0x30,0,0);
          DeleteObject(local_80);
          EndDialog(hwnd,local_84);
        }
      }
      return 1;
    }
    if (y == 0x113) {
      ho = (HGDIOBJ)SendDlgItemMessageA(hwnd,0x3f1,0x31,0,0);
      SendDlgItemMessageA(hwnd,0x3f1,0x30,0,0);
      DeleteObject(ho);
      EndDialog(hwnd,0);
      return 1;
    }
  }
  else if (y < 0x205) {
    if (y == 0x204) goto LAB_0048fa2f;
    if (y == 0x201) {
      GetWindowRect(hwnd,&local_c0);
      SendMessageA(hwnd,0x112,0xf012,0);
      GetWindowRect(hwnd,&local_ac);
      val_3 = Mem_AllocOrFree_004d9810(local_c0.top - local_ac.top);
      val_4 = Mem_AllocOrFree_004d9810(local_c0.left - local_ac.left);
      local_b0 = (uint32_t)(4 < val_3 + val_4);
      if (local_b0 == 0) {
        pHVar6 = GetDlgItem(hwnd,0x3f1);
        SendMessageA(hwnd,0x111,0x3f1,(LPARAM)pHVar6);
      }
      return 1;
    }
  }
  else if ((0x30e < y) && (y < 0x312)) {
    uval_2 = GDI_RealizePaletteTree(hwnd,y,(HWND)hdc,height);
    return uval_2;
  }
  return 0;
}



/*
 * Decompiled function: UI_RegisterClass_00490196
 * Entry Point: 00490196
 * Size: 146 bytes
 */


bool UI_RegisterClass_00490196(LPCSTR str_1)

{
  ATOM AVar1;
  WNDCLASSA local_2c;
  
  local_2c.style = 0xb;
  local_2c.lpfnWndProc = UI_WndProc_00490233;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 0x14;
  local_2c.hInstance = g_DuelInstanceHandle;
  local_2c.hIcon = LoadIconA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = (HBRUSH)0x0;
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = str_1;
  AVar1 = RegisterClassA(&local_2c);
  return AVar1 != 0;
}



/*
 * Decompiled function: Mem_AllocOrFree_00490228
 * Entry Point: 00490228
 * Size: 11 bytes
 */


void Mem_AllocOrFree_00490228(void)

{
  return;
}



/*
 * Decompiled function: UI_WndProc_00490233
 * Entry Point: 00490233
 * Size: 309 bytes
 */


LRESULT UI_WndProc_00490233(HWND hwnd,uint32_t uMsg,WPARAM wParam,uint32_t lParam)

{
  HWND pHVar1;
  uint32_t lParam_00;
  LRESULT LVar2;
  tagPOINT *lpPoints;
  UINT cPoints;
  tagPOINT match_count;
  
  if (uMsg < 0x10) {
    if ((uMsg == 0xf) || ((uMsg != 0 && (uMsg < 3)))) goto LAB_00490247;
  }
  else if (uMsg < 0x203) {
    if (0x200 < uMsg) {
      match_count.x = lParam & 0xffff;
      match_count.y = lParam >> 0x10;
      cPoints = 1;
      lpPoints = &match_count;
      pHVar1 = GetParent(hwnd);
      MapWindowPoints(hwnd,pHVar1,lpPoints,cPoints);
      lParam_00 = match_count.y << 0x10 | match_count.x & 0xffffU;
      pHVar1 = GetParent(hwnd);
      SendMessageA(pHVar1,uMsg,wParam,lParam_00);
      return 0;
    }
    if (uMsg == 0x14) {
LAB_00490247:
      LVar2 = CallWindowProcA(Card_Setup_00467a68,hwnd,uMsg,wParam,lParam);
      return LVar2;
    }
  }
  else if ((0x30e < uMsg) && (uMsg < 0x312)) goto LAB_00490247;
  LVar2 = DefWindowProcA(hwnd,uMsg,wParam,lParam);
  return LVar2;
}



/*
 * Decompiled function: UI_Register_WINBK_BigCard_0049036d
 * Entry Point: 0049036d
 * Size: 219 bytes
 */


int32_t UI_Register_WINBK_BigCard_0049036d(LPCSTR str_1)

{
  ATOM AVar1;
  uint32_t local_138 [66];
  int32_t local_30;
  WNDCLASSA local_2c;
  
  local_30 = 1;
  local_2c.style = 0;
  local_2c.lpfnWndProc = UI_WndProc_00490478;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 0x14;
  local_2c.hInstance = g_DuelInstanceHandle;
  local_2c.hIcon = LoadIconA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = (HBRUSH)0x6;
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = str_1;
  AVar1 = RegisterClassA(&local_2c);
  if (AVar1 == 0) {
    local_30 = 0;
  }
  Mem_AllocOrFree_004d9630(local_138,(uint32_t *)&g_DuelAssetDirectory);
  Str_CopyFast(local_138,(uint32_t *)s__WINBK_BigCard_pic_004fb140);
  DAT_005daf00 = Pic_LoadKimPicture((char *)local_138);
  DAT_0060d498 = 9000;
  return local_30;
}



/*
 * Decompiled function: Mem_AllocOrFree_00490448
 * Entry Point: 00490448
 * Size: 48 bytes
 */


void Mem_AllocOrFree_00490448(void)

{
  if (DAT_005daf00 != (HANDLE)0x0) {
    GDI_DestroyDIBSection(DAT_005daf00);
  }
  DAT_005daf00 = (HANDLE)0x0;
  return;
}



/*
 * Decompiled function: UI_WndProc_00490478
 * Entry Point: 00490478
 * Size: 4331 bytes
 */


LRESULT UI_WndProc_00490478(HWND hwnd,uint32_t uMsg,HWND wParam,LONG *lParam)

{
  bool flag_1;
  char *char_ptr_2;
  SHORT SVar3;
  HWND pHVar4;
  LONG LVar5;
  int val_6;
  int val_7;
  HBRUSH hbr;
  HWND pHVar8;
  size_t sVar9;
  uint32_t uVar10;
  LRESULT LVar11;
  UINT UVar12;
  WPARAM wParam_00;
  tagRECT *ptVar13;
  LPARAM lParam_00;
  tagSIZE *lpsz;
  uint32_t local_394;
  int local_38c;
  LONG *local_384;
  tagRECT local_380;
  tagSIZE local_370;
  COLORREF local_368;
  HDC local_364;
  int local_360;
  tagPAINTSTRUCT local_35c;
  int local_31c;
  int local_318;
  COLORREF local_314;
  COLORREF local_310;
  COLORREF local_30c;
  COLORREF local_308;
  CHAR local_304 [500];
  tagTEXTMETRICA local_110;
  COLORREF local_d8;
  tagRECT local_d4;
  COLORREF local_c4;
  char *local_c0;
  int local_bc;
  tagRECT local_b8;
  int local_a8;
  tagRECT local_a4;
  uint32_t local_94;
  uint32_t local_90;
  HDC local_8c;
  int local_88;
  int local_84;
  int local_80;
  uint32_t local_7c;
  tagTEXTMETRICA local_78;
  tagRECT local_40;
  tagRECT local_30;
  int loop_idx;
  int color_idx;
  int target_idx;
  LONG player_idx;
  HWND card_idx;
  HWND match_count;
  char *slot_idx;
  
  if (uMsg < 0xd) {
    if (uMsg == 0xc) {
      local_384 = lParam;
      local_38c = 0;
      flag_1 = false;
      while (((char)*local_384 != '\0' && (!flag_1))) {
        if (((char)*local_384 == ' ') || ((char)*local_384 == '>')) {
          (&DAT_005dae38)[local_38c] = 0;
          flag_1 = true;
        }
        else {
          for (; ((char)*local_384 != '\0' && ((char)*local_384 != '\n'));
              local_384 = (LONG *)((int)local_384 + 1)) {
            (&DAT_005dae38)[local_38c] = (char)*local_384;
            local_38c = local_38c + 1;
          }
          if ((char)*local_384 != '\0') {
            (&DAT_005dae38)[local_38c] = (char)*local_384;
            local_384 = (LONG *)((int)local_384 + 1);
            local_38c = local_38c + 1;
          }
        }
      }
      (&DAT_005dae38)[local_38c] = 0;
      while (sVar9 = _strlen(&DAT_005dae38), (&DAT_005dae36)[sVar9] == '\n') {
        sVar9 = _strlen(&DAT_005dae38);
        (&DAT_005dae36)[sVar9] = 0;
      }
      LVar11 = DefWindowProcA(hwnd,0xc,(WPARAM)wParam,0x5dae38);
      slot_idx = (char *)GetWindowLongA(hwnd,4);
      target_idx = 0;
      player_idx = -1;
      if ((char)*local_384 != '\0') {
        local_38c = 0;
        while ((char)*local_384 != '\0') {
          for (; (char)*local_384 == ' '; local_384 = (LONG *)((int)local_384 + 1)) {
          }
          if ((char)*local_384 == '>') {
            player_idx = target_idx;
            local_384 = (LONG *)((int)local_384 + 1);
          }
          for (; (char)*local_384 == '\n'; local_384 = (LONG *)((int)local_384 + 1)) {
          }
          for (; ((char)*local_384 != '\0' && ((char)*local_384 != '\n'));
              local_384 = (LONG *)((int)local_384 + 1)) {
            *(char *)(local_38c + (int)slot_idx) = (char)*local_384;
            local_38c = local_38c + 1;
          }
          *(uint8_t *)(local_38c + (int)slot_idx) = 0;
          local_38c = local_38c + 1;
          if ((char)*local_384 != '\0') {
            local_384 = (LONG *)((int)local_384 + 1);
          }
          target_idx = target_idx + 1;
        }
        *(uint8_t *)(local_38c + (int)slot_idx) = 0;
      }
      if ((target_idx != 0) && (player_idx == -1)) {
        player_idx = 0;
      }
      local_394 = 0;
      for (local_38c = 0; local_38c < target_idx; local_38c = local_38c + 1) {
        uVar10 = FUN_00491688(hwnd,local_38c);
        local_394 = local_394 | uVar10;
      }
      if (local_394 == 0) {
        card_idx = (HWND)0x0;
        SetWindowLongA(hwnd,0x10,0);
      }
      SetWindowLongA(hwnd,8,target_idx);
      SetWindowLongA(hwnd,4,(LONG)slot_idx);
      SetWindowLongA(hwnd,0xc,player_idx);
      return LVar11;
    }
    if (uMsg == 1) {
      match_count = (HWND)0x0;
      SetWindowLongA(hwnd,0,0);
      slot_idx = _malloc(1000);
      target_idx = 0;
      player_idx = -1;
      SetWindowLongA(hwnd,8,0);
      SetWindowLongA(hwnd,4,(LONG)slot_idx);
      SetWindowLongA(hwnd,0xc,player_idx);
      card_idx = (HWND)*lParam;
      SetWindowLongA(hwnd,0x10,(LONG)card_idx);
      color_idx = lParam[9];
      if (color_idx != 0) {
        PostMessageA(hwnd,0xc,0,color_idx);
      }
      return 0;
    }
    if (uMsg == 2) {
      slot_idx = (char *)GetWindowLongA(hwnd,4);
      if (slot_idx != (char *)0x0) {
        FUN_004db150(slot_idx);
      }
      return 0;
    }
  }
  else if (uMsg < 0x15) {
    if (uMsg == 0x14) {
      return 1;
    }
    if (uMsg == 0xf) {
      match_count = (HWND)GetWindowLongA(hwnd,0);
      target_idx = GetWindowLongA(hwnd,8);
      slot_idx = (char *)GetWindowLongA(hwnd,4);
      player_idx = GetWindowLongA(hwnd,0xc);
      card_idx = (HWND)GetWindowLongA(hwnd,0x10);
      GetWindowTextA(hwnd,local_304,500);
      local_c0 = slot_idx;
      local_314 = 0x1000097;
      local_310 = 0x1000097;
      local_30c = 0x1000097;
      local_d8 = 0x10000c3;
      local_308 = 0x10000bf;
      local_c4 = 0x10000c9;
      local_364 = BeginPaint(hwnd,&local_35c);
      if (local_364 != (HDC)0x0) {
        GDI_RealizeAndFlushPalette(local_364);
        GetClientRect(hwnd,&local_d4);
        SetBkMode(local_364,1);
        SelectObject(local_364,match_count);
        SetTextColor(local_364,local_c4);
        OffsetRect(&local_d4,1,1);
        DrawTextA(local_364,local_304,-1,&local_d4,0x10);
        OffsetRect(&local_d4,-1,-1);
        SetTextColor(local_364,local_314);
        DrawTextA(local_364,local_304,-1,&local_d4,0x10);
        local_bc = DrawTextA(local_364,local_304,-1,&local_d4,0x410);
        if (target_idx != 0) {
          local_31c = local_d4.top + local_bc + 0x14;
          GetTextMetricsA(local_364,&local_110);
          local_360 = local_110.tmExternalLeading + (local_110.tmHeight * 10) / 100 +
                      local_110.tmHeight;
          SetBkMode(local_364,1);
          for (local_318 = 0; local_318 < target_idx; local_318 = local_318 + 1) {
            val_7 = FUN_00491688(hwnd,local_318);
            char_ptr_2 = local_c0;
            if ((val_7 == 0) && (char_ptr_2 = local_c0 + 1, local_c0[1] == ' ')) {
              char_ptr_2 = local_c0 + 2;
            }
            local_c0 = char_ptr_2;
            if (card_idx == (HWND)0x0) {
              if (player_idx == local_318) {
                lpsz = &local_370;
                sVar9 = _strlen(local_c0);
                GetTextExtentPointA(local_364,local_c0,sVar9,lpsz);
                SetRect(&local_380,local_d4.left + -5,local_31c,local_d4.left + local_370.cx + 5,
                        local_31c + local_360);
                hbr = GetStockObject(0);
                FillRect(local_364,&local_380,hbr);
              }
              val_7 = FUN_00491688(hwnd,local_318);
              if (val_7 == 0) {
                local_368 = local_d8;
              }
              else {
                local_368 = local_30c;
              }
            }
            else {
              val_7 = FUN_00491688(hwnd,local_318);
              if (val_7 == 0) {
                local_368 = local_d8;
              }
              else if (player_idx == local_318) {
                local_368 = local_308;
              }
              else {
                local_368 = local_310;
              }
            }
            SetTextColor(local_364,local_c4);
            sVar9 = _strlen(local_c0);
            TextOutA(local_364,local_d4.left + 1,local_31c + 1,local_c0,sVar9);
            SetTextColor(local_364,local_368);
            sVar9 = _strlen(local_c0);
            TextOutA(local_364,local_d4.left,local_31c,local_c0,sVar9);
            local_31c = local_31c + local_360;
            sVar9 = _strlen(local_c0);
            local_c0 = local_c0 + sVar9 + 1;
          }
        }
        if (target_idx != 0) {
          GetClientRect(hwnd,&local_d4);
          local_d4.bottom = local_31c;
          SetWindowPos(hwnd,(HWND)0x0,0,0,local_d4.right - local_d4.left,local_31c - local_d4.top,6)
          ;
        }
        EndPaint(hwnd,&local_35c);
      }
      return 0;
    }
  }
  else if (uMsg < 0x88) {
    if (uMsg == 0x87) {
      return 4;
    }
    if (uMsg == 0x30) {
      pHVar8 = (HWND)GetWindowLongA(hwnd,0);
      if (pHVar8 != wParam) {
        match_count = wParam;
        SetWindowLongA(hwnd,0,(LONG)wParam);
        InvalidateRect(hwnd,(RECT *)0x0,1);
      }
      return 0;
    }
    if (uMsg == 0x31) {
      LVar5 = GetWindowLongA(hwnd,0);
      return LVar5;
    }
  }
  else if (uMsg < 0x203) {
    if (0x1ff < uMsg) {
      target_idx = GetWindowLongA(hwnd,8);
      match_count = (HWND)GetWindowLongA(hwnd,0);
      player_idx = GetWindowLongA(hwnd,0xc);
      card_idx = (HWND)GetWindowLongA(hwnd,0x10);
      if (uMsg == 0x201) {
        ptVar13 = &local_b8;
        pHVar8 = GetParent(hwnd);
        GetWindowRect(pHVar8,ptVar13);
        lParam_00 = 0;
        wParam_00 = 0xf012;
        UVar12 = 0x112;
        pHVar8 = GetParent(hwnd);
        SendMessageA(pHVar8,UVar12,wParam_00,lParam_00);
        uMsg = 0x202;
        ptVar13 = &local_40;
        pHVar8 = GetParent(hwnd);
        GetWindowRect(pHVar8,ptVar13);
        val_7 = Mem_AllocOrFree_004d9810(local_b8.top - local_40.top);
        val_6 = Mem_AllocOrFree_004d9810(local_b8.left - local_40.left);
        local_7c = (uint32_t)(4 < val_7 + val_6);
      }
      else {
        local_7c = 0;
      }
      if (local_7c == 0) {
        local_88 = player_idx + 1;
        if (card_idx == (HWND)0x0) {
          if (uMsg == 0x202) {
            pHVar8 = hwnd;
            uVar10 = GetDlgCtrlID(hwnd);
            uVar10 = uVar10 & 0xffff | local_88 << 0x10;
            UVar12 = 0x111;
            pHVar4 = GetParent(hwnd);
            SendMessageA(pHVar4,UVar12,uVar10,(LPARAM)pHVar8);
          }
        }
        else if (target_idx < 1) {
          if (uMsg == 0x202) {
            pHVar8 = hwnd;
            uVar10 = GetDlgCtrlID(hwnd);
            uVar10 = uVar10 & 0xffff;
            UVar12 = 0x111;
            pHVar4 = GetParent(hwnd);
            SendMessageA(pHVar4,UVar12,uVar10,(LPARAM)pHVar8);
          }
        }
        else {
          local_94 = (uint32_t)lParam & 0xffff;
          local_90 = (uint32_t)lParam >> 0x10;
          local_8c = GetDC(hwnd);
          GDI_RealizeAndFlushPalette(local_8c);
          SelectObject(local_8c,match_count);
          GetTextMetricsA(local_8c,&local_78);
          local_a8 = local_78.tmExternalLeading + local_78.tmHeight;
          ReleaseDC(hwnd,local_8c);
          local_88 = 0;
          GetClientRect(hwnd,&local_30);
          local_80 = local_30.bottom - local_a8;
          local_84 = target_idx;
          while ((0 < local_84 && (local_88 == 0))) {
            if (local_80 < (int)local_90) {
              local_88 = local_84;
              SetRect(&local_a4,0,local_80,local_30.right,local_80 + local_a8);
            }
            local_80 = local_80 - local_a8;
            local_84 = local_84 + -1;
          }
          val_7 = FUN_00491688(hwnd,local_88 + -1);
          if (val_7 != 0) {
            player_idx = local_88 + -1;
            SetWindowLongA(hwnd,0xc,player_idx);
            InvalidateRect(hwnd,(RECT *)0x0,0);
            UpdateWindow(hwnd);
            if (uMsg == 0x202) {
              Sleep(0x2ee);
              pHVar8 = hwnd;
              uVar10 = GetDlgCtrlID(hwnd);
              uVar10 = uVar10 & 0xffff | local_88 << 0x10;
              UVar12 = 0x111;
              pHVar4 = GetParent(hwnd);
              SendMessageA(pHVar4,UVar12,uVar10,(LPARAM)pHVar8);
            }
          }
        }
      }
      return 0;
    }
    if (uMsg == 0x100) {
      target_idx = GetWindowLongA(hwnd,8);
      player_idx = GetWindowLongA(hwnd,0xc);
      card_idx = (HWND)GetWindowLongA(hwnd,0x10);
      if (card_idx != (HWND)0x0) {
        if ((wParam == (HWND)0xd) || (wParam == (HWND)0x20)) {
          loop_idx = player_idx + 1;
          pHVar8 = hwnd;
          uVar10 = GetDlgCtrlID(hwnd);
          uVar10 = uVar10 & 0xffff | loop_idx << 0x10;
          UVar12 = 0x111;
          pHVar4 = GetParent(hwnd);
          SendMessageA(pHVar4,UVar12,uVar10,(LPARAM)pHVar8);
        }
        else {
          if (wParam == (HWND)0x9) {
            SVar3 = GetKeyState(0x10);
            if (((int)SVar3 & 0x8000U) == 0) {
              wParam = (HWND)0x28;
            }
            else {
              wParam = (HWND)0x26;
            }
          }
          switch(wParam) {
          case (HWND)0x23:
            player_idx = target_idx;
            do {
              player_idx = player_idx + -1;
              val_7 = FUN_00491688(hwnd,player_idx);
            } while (val_7 == 0);
            break;
          case (HWND)0x24:
            player_idx = 0;
            while (val_7 = FUN_00491688(hwnd,player_idx), val_7 == 0) {
              player_idx = player_idx + 1;
            }
            break;
          case (HWND)0x26:
            player_idx = player_idx + -1;
            if (player_idx < 0) {
              player_idx = target_idx + -1;
            }
            while (val_7 = FUN_00491688(hwnd,player_idx), val_7 == 0) {
              player_idx = player_idx + -1;
              if (player_idx < 0) {
                player_idx = target_idx + -1;
              }
            }
            break;
          case (HWND)0x28:
            player_idx = player_idx + 1;
            if (target_idx + -1 < player_idx) {
              player_idx = 0;
            }
            while (val_7 = FUN_00491688(hwnd,player_idx), val_7 == 0) {
              player_idx = player_idx + 1;
              if (target_idx + -1 < player_idx) {
                player_idx = 0;
              }
            }
          }
          SetWindowLongA(hwnd,0xc,player_idx);
          InvalidateRect(hwnd,(RECT *)0x0,0);
        }
      }
      return 0;
    }
    if (uMsg == 0x102) {
      pHVar8 = hwnd;
      uVar10 = GetDlgCtrlID(hwnd);
      uVar10 = uVar10 & 0xffff;
      UVar12 = 0x111;
      pHVar4 = GetParent(hwnd);
      SendMessageA(pHVar4,UVar12,uVar10,(LPARAM)pHVar8);
      return 0;
    }
  }
  else {
    switch(uMsg) {
    case 0x30f:
    case 0x310:
    case 0x311:
      LVar11 = GDI_RealizePaletteTree(hwnd,uMsg,wParam,lParam);
      return LVar11;
    case 0x400:
      LVar5 = GetWindowLongA(hwnd,8);
      return LVar5;
    case 0x401:
      card_idx = wParam;
      SetWindowLongA(hwnd,0x10,(LONG)wParam);
      return 0;
    }
  }
  LVar11 = DefWindowProcA(hwnd,uMsg,(WPARAM)wParam,(LPARAM)lParam);
  return LVar11;
}



/*
 * Decompiled function: FUN_00491688
 * Entry Point: 00491688
 * Size: 185 bytes
 */


bool FUN_00491688(HWND hwnd,int arg2)

{
  LONG LVar1;
  size_t len_2;
  bool flag_3;
  int card_idx;
  char *slot_idx;
  
  if (hwnd == (HWND)0x0) {
    flag_3 = false;
  }
  else {
    slot_idx = (char *)GetWindowLongA(hwnd,4);
    LVar1 = GetWindowLongA(hwnd,8);
    if (LVar1 + -1 < arg2) {
      flag_3 = false;
    }
    else {
      for (card_idx = 0; card_idx < arg2; card_idx = card_idx + 1) {
        len_2 = _strlen(slot_idx);
        slot_idx = slot_idx + len_2 + 1;
      }
      flag_3 = *slot_idx != '_';
    }
  }
  return flag_3;
}



/*
 * Decompiled function: FUN_00491750
 * Entry Point: 00491750
 * Size: 118 bytes
 */


void FUN_00491750(int32_t *color_mask,int32_t arg_2,int event_type)

{
  *color_mask = 0x28;
  color_mask[1] = arg_2;
  color_mask[2] = -arg_3;
  *(int16_t *)(color_mask + 3) = 1;
  *(int16_t *)((int)color_mask + 0xe) = 0x18;
  color_mask[4] = 0;
  color_mask[5] = 0;
  color_mask[6] = 0;
  color_mask[7] = 0;
  color_mask[8] = 0x100;
  color_mask[9] = 0x100;
  return;
}



/*
 * Decompiled function: UI_RegisterClass_004917d0
 * Entry Point: 004917d0
 * Size: 289 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool UI_RegisterClass_004917d0(LPCSTR str_1)

{
  ATOM AVar1;
  LOGFONTA *lplf;
  bool flag_2;
  WNDCLASSA local_2c;
  
  local_2c.style = 0x800;
  local_2c.lpfnWndProc = UI_WndProc_0049198a;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 4;
  local_2c.hInstance = g_DuelInstanceHandle;
  local_2c.hIcon = (HICON)0x0;
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = (HBRUSH)0x6;
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = str_1;
  AVar1 = RegisterClassA(&local_2c);
  flag_2 = AVar1 != 0;
  DAT_00618974 = 0;
  DAT_006152f0 = 500;
  _DAT_00664d98 = 10;
  _DAT_0061746c = 0x12;
  DAT_0060ccb8 = 0x14;
  lplf = (LOGFONTA *)FUN_00472731(s_CueCard_005053a0,0);
  DAT_005daf04 = CreateFontIndirectA(lplf);
  DAT_005daf10 = CreateSolidBrush(0x296bed2);
  DAT_005daf0c = CreateSolidBrush(0x27f7f7f);
  DAT_005daf08 = 0x2505050;
  if ((DAT_005daf10 == (HBRUSH)0x0) || (DAT_005daf0c == (HBRUSH)0x0)) {
    flag_2 = false;
  }
  return flag_2;
}



/*
 * Decompiled function: FUN_004918f1
 * Entry Point: 004918f1
 * Size: 153 bytes
 */


void FUN_004918f1(void)

{
  if (DAT_00618974 != 0) {
    KillTimer((HWND)0x0,DAT_00618974);
    DAT_00618974 = 0;
  }
  if (DAT_005daf04 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_005daf04);
  }
  if (DAT_005daf10 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_005daf10);
  }
  if (DAT_005daf0c != (HGDIOBJ)0x0) {
    DeleteObject(DAT_005daf0c);
  }
  DAT_005daf04 = (HGDIOBJ)0x0;
  DAT_005daf10 = (HGDIOBJ)0x0;
  DAT_005daf0c = (HGDIOBJ)0x0;
  return;
}



/*
 * Decompiled function: UI_WndProc_0049198a
 * Entry Point: 0049198a
 * Size: 1114 bytes
 */


LRESULT UI_WndProc_0049198a(HWND hwnd,uint32_t uMsg,HWND wParam,LPSTR lParam)

{
  int c;
  LONG LVar1;
  HWND hWnd;
  LRESULT LVar2;
  tagSIZE *psizl;
  HWND local_104;
  CHAR local_100 [100];
  HDC local_9c;
  tagPAINTSTRUCT local_98;
  tagRECT local_58;
  tagRECT local_48;
  HWND local_38;
  LPSTR local_34;
  int local_30;
  HDC local_2c;
  int local_28;
  uint32_t local_24;
  uint32_t loop_idx;
  int color_idx;
  LPSTR target_idx;
  tagSIZE player_idx;
  int match_count;
  HWND slot_idx;
  
  if (uMsg < 0x10) {
    if (uMsg == 0xf) {
      slot_idx = (HWND)GetWindowLongA(hwnd,0);
      local_9c = BeginPaint(hwnd,&local_98);
      if (local_9c != (HDC)0x0) {
        GDI_RealizeAndFlushPalette(local_9c);
        GetClientRect(hwnd,&local_48);
        SetRect(&local_58,local_48.left,local_48.top,local_48.right + -2,local_48.bottom + -2);
        FillRect(local_9c,&local_48,DAT_005daf0c);
        FillRect(local_9c,&local_58,DAT_005daf10);
        SetTextColor(local_9c,DAT_005daf08);
        SetBkMode(local_9c,1);
        GetWindowTextA(hwnd,local_100,100);
        SelectObject(local_9c,slot_idx);
        DrawTextA(local_9c,local_100,-1,&local_58,0x25);
        EndPaint(hwnd,&local_98);
      }
      return 0;
    }
    if (uMsg == 1) {
      slot_idx = DAT_005daf04;
      SetWindowLongA(hwnd,0,(LONG)DAT_005daf04);
      return 0;
    }
  }
  else if (uMsg < 0x31) {
    if (uMsg == 0x30) {
      local_104 = wParam;
      if (wParam == (HWND)0x0) {
        local_104 = DAT_005daf04;
      }
      SetWindowLongA(hwnd,0,(LONG)local_104);
      InvalidateRect(hwnd,(RECT *)0x0,1);
      return 0;
    }
    if (uMsg == 0x14) {
      return 1;
    }
  }
  else if (uMsg < 0x101) {
    if (uMsg == 0x100) {
      SetFocus(g_DuelMainHwnd);
      hWnd = GetFocus();
      PostMessageA(hWnd,uMsg,(WPARAM)wParam,(LPARAM)lParam);
      return 0;
    }
    if (uMsg == 0x31) {
      LVar1 = GetWindowLongA(hwnd,0);
      return LVar1;
    }
  }
  else {
    switch(uMsg) {
    case 0x30f:
    case 0x310:
    case 0x311:
      LVar2 = GDI_RealizePaletteTree(hwnd,uMsg,wParam,lParam);
      return LVar2;
    case 0x400:
      slot_idx = (HWND)GetWindowLongA(hwnd,0);
      loop_idx = (uint32_t)wParam & 0xffff;
      local_24 = (uint32_t)wParam >> 0x10;
      target_idx = lParam;
      local_2c = GetDC(hwnd);
      if (local_2c != (HDC)0x0) {
        GDI_RealizeAndFlushPalette(local_2c);
        SelectObject(local_2c,slot_idx);
        psizl = &player_idx;
        c = lstrlenA(target_idx);
        GetTextExtentPoint32A(local_2c,target_idx,c,psizl);
        local_28 = player_idx.cx + 10;
        local_30 = player_idx.cy + 6;
        ReleaseDC(hwnd,local_2c);
        color_idx = GetSystemMetrics(0);
        match_count = GetSystemMetrics(1);
        if ((int)loop_idx < 1) {
          loop_idx = 1;
        }
        if (color_idx + -1 < (int)(local_28 + loop_idx)) {
          loop_idx = (color_idx + -1) - local_28;
        }
        if ((int)local_24 < 1) {
          local_24 = 1;
        }
        if (match_count + -1 < (int)(local_30 + local_24)) {
          local_24 = (match_count + -1) - local_30;
        }
        MoveWindow(hwnd,loop_idx,local_24,local_28,local_30,1);
        SetWindowTextA(hwnd,target_idx);
        ShowWindow(hwnd,5);
        InvalidateRect(hwnd,(RECT *)0x0,1);
      }
      return 0;
    case 0x401:
      local_34 = lParam;
      local_38 = wParam;
      GetWindowTextA(hwnd,lParam,(int)wParam);
      return 0;
    }
  }
  LVar2 = DefWindowProcA(hwnd,uMsg,(WPARAM)wParam,(LPARAM)lParam);
  return LVar2;
}



/*
 * Decompiled function: FUN_00491ef3
 * Entry Point: 00491ef3
 * Size: 1064 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int32_t FUN_00491ef3(int *color_mask)

{
  POINT Point;
  BOOL BVar1;
  int val_2;
  int val_3;
  LRESULT LVar4;
  int32_t uval_5;
  tagPOINT local_f0;
  tagPOINT local_e8;
  HWND local_e0;
  int local_dc;
  char local_d8 [100];
  tagPOINT local_74;
  int local_6c;
  char local_68 [100];
  
  switch(color_mask[1]) {
  case 0x113:
    if ((*color_mask == 0) && (color_mask[2] == DAT_00618974)) {
      KillTimer((HWND)0x0,DAT_00618974);
      DAT_00618974 = 0;
      GetCursorPos(&local_e8);
      Point.y = local_e8.y;
      Point.x = local_e8.x;
      local_e0 = WindowFromPoint(Point);
      local_f0.x = local_e8.x;
      local_f0.y = local_e8.y;
      ScreenToClient(local_e0,&local_f0);
      LVar4 = SendMessageA(local_e0,0x437,(WPARAM)local_68,local_f0.y << 0x10 | local_f0.x & 0xffffU
                          );
      if ((LVar4 != 0) && (DAT_00663e00 != 0)) {
        SendMessageA(DAT_00618150,0x400,
                     (local_e8.y + _DAT_0061746c) * 0x10000 | local_e8.x + _DAT_00664d98 & 0xffffU,
                     (LPARAM)local_68);
      }
      uval_5 = 1;
    }
    else {
      uval_5 = 0;
    }
    break;
  default:
    uval_5 = 0;
    break;
  case 0x200:
    BVar1 = IsWindowVisible(DAT_00618150);
    if (BVar1 == 0) {
      if (DAT_00618974 != 0) {
        KillTimer((HWND)0x0,DAT_00618974);
        DAT_00618974 = 0;
      }
      DAT_00618974 = SetTimer((HWND)0x0,0,DAT_006152f0,(TIMERPROC)0x0);
    }
    else if (*color_mask == DAT_00505390) {
      local_6c = 1;
      local_dc = 1;
      if (*color_mask == DAT_00505390) {
        val_3 = Mem_AllocOrFree_004d9810(((uint32_t)color_mask[3] >> 0x10) - _DAT_0050539c);
        val_2 = Mem_AllocOrFree_004d9810(*(uint16_t *)(color_mask + 3) - _DAT_00505398);
        if (DAT_0060ccb8 < val_3 + val_2) {
          local_dc = SendMessageA((HWND)*color_mask,0x437,(WPARAM)local_68,color_mask[3]);
        }
        else {
          local_6c = 0;
        }
      }
      else {
        local_dc = SendMessageA((HWND)*color_mask,0x437,(WPARAM)local_68,color_mask[3]);
      }
      if (local_dc == 0) {
        ShowWindow(DAT_00618150,0);
      }
      else if (local_6c != 0) {
        DAT_00505390 = *color_mask;
        _DAT_00505398 = (uint32_t)*(uint16_t *)(color_mask + 3);
        _DAT_0050539c = (uint32_t)color_mask[3] >> 0x10;
        GetCursorPos(&local_74);
        if (DAT_00663e00 == 0) {
          ShowWindow(DAT_00618150,0);
        }
        else {
          SendMessageA(DAT_00618150,0x401,0,(LPARAM)local_d8);
          val_3 = _strcmp(local_d8,local_68);
          if (val_3 != 0) {
            SendMessageA(DAT_00618150,0x400,
                         (local_74.y + _DAT_0061746c) * 0x10000 |
                         local_74.x + _DAT_00664d98 & 0xffffU,(LPARAM)local_68);
          }
        }
      }
    }
    else {
      if (DAT_00618974 != 0) {
        KillTimer((HWND)0x0,DAT_00618974);
        DAT_00618974 = 0;
      }
      DAT_00618974 = SetTimer((HWND)0x0,0,DAT_006152f0,(TIMERPROC)0x0);
      DAT_00505390 = *color_mask;
      ShowWindow(DAT_00618150,0);
    }
    uval_5 = 0;
    break;
  case 0x201:
  case 0x204:
  case 0x207:
    ShowWindow(DAT_00618150,0);
    if (DAT_00618974 != 0) {
      KillTimer((HWND)0x0,DAT_00618974);
      DAT_00618974 = 0;
    }
    uval_5 = 0;
  }
  return uval_5;
}



/*
 * Decompiled function: File_Load_Info
 * Entry Point: 00492440
 * Size: 595 bytes
 */


/* WARNING: Type propagation algorithm not settling */

void File_Load_Info(void)

{
  bool flag_1;
  size_t len_2;
  int val_3;
  int val_4;
  uint32_t local_328 [96];
  int local_1a8;
  uint8_t local_1a4 [11];
  char acStack_199 [385];
  char target_idx;
  FILE *player_idx;
  int card_idx;
  int match_count;
  int slot_idx;
  
  player_idx = _fopen(s_info_csv_005053ac,&DAT_005053a8);
  flag_1 = false;
  target_idx = '\0';
  local_328[0]._0_1_ = '\0';
  card_idx = 9;
  do {
    slot_idx = _fscanf(player_idx,s______________005053b8,(int)acStack_199 + 1,local_1a4);
    if (slot_idx == -1) break;
    if (acStack_199[1] == '0') {
      local_1a8 = _atoi((char *)((int)acStack_199 + 1));
      local_328[0]._0_1_ = '\0';
      target_idx = '\0';
    }
    target_idx = target_idx + '\x01';
    if ((target_idx == card_idx) && (flag_1)) {
      Str_CopyFast(local_328,(uint32_t *)&DAT_005053c8);
    }
    if (acStack_199[1] == '\"') {
      flag_1 = true;
    }
    if (target_idx == card_idx) {
      Str_CopyFast(local_328,(uint32_t *)((int)acStack_199 + 1));
    }
    len_2 = _strlen((char *)((int)acStack_199 + 1));
    if (acStack_199[len_2] == '\"') {
      flag_1 = false;
    }
    if (flag_1) {
      target_idx = target_idx + -1;
    }
    if ((target_idx == card_idx) && (val_3 = Card_IsValidCardId(local_1a8), val_3 != -1)) {
      if ((*(uint32_t *)(&DAT_004ff5a8 + val_3 * 0x34) & 0x180) != 0) {
        (&DAT_004ff5ac)[val_3 * 0x34] = 4;
      }
      match_count = 1;
      val_4 = _strcmp((char *)local_328,&DAT_005053cc);
      if (val_4 == 0) {
        match_count = 3;
      }
      val_4 = _strcmp((char *)local_328,s_Uncommon_005053d4);
      if (val_4 == 0) {
        match_count = 2;
      }
      if ((((&DAT_004ff5a9)[val_3 * 0x34] & 4) != 0) && (match_count < 3)) {
        match_count = match_count + 1;
      }
      (&DAT_004ff5ac)[val_3 * 0x34] = (uint8_t)match_count;
    }
  } while (slot_idx != -1);
  _fclose(player_idx);
  return;
}



/*
 * Decompiled function: Csv_LoadMaster_00492693
 * Entry Point: 00492693
 * Size: 315 bytes
 */


void Csv_LoadMaster_00492693(void)

{
  long lVar1;
  int player_id;
  int local_214;
  char local_20c [512];
  FILE *match_count;
  char *slot_idx;
  
  match_count = _fopen(s_master_csv_005053e4,&DAT_005053e0);
  for (local_214 = 0; local_214 < 0x4e2; local_214 = local_214 + 1) {
    *(int32_t *)(&DAT_005daf18 + local_214 * 4) = 0xffffffff;
  }
  do {
    lVar1 = _ftell(match_count);
    slot_idx = _fgets(local_20c,0x200,match_count);
    if (slot_idx == (char *)0x0) break;
    if (local_20c[0] == '0') {
      color_mask = _atoi(local_20c);
      if (((-1 < color_mask) && (color_mask < 0x4e2)) && (*(int *)(&DAT_005daf18 + color_mask * 4) == -1)) {
        *(long *)(&DAT_005daf18 + color_mask * 4) = lVar1;
      }
      Card_IsValidCardId(color_mask);
    }
  } while (slot_idx != (char *)0xffffffff);
  _fclose(match_count);
  return;
}



/*
 * Decompiled function: Csv_ReadConcise_004927ce
 * Entry Point: 004927ce
 * Size: 164 bytes
 */


void Csv_ReadConcise_004927ce(void)

{
  FILE *fp;
  int player_idx;
  
  fp = _fopen(s_concise_csv_005053f4,&DAT_005053f0);
  for (player_idx = 0; player_idx < DAT_00665ed0; player_idx = player_idx + 1) {
    _fprintf(fp,s__d__d__ld_00505400,*(int *)(&DAT_004ff590 + player_idx * 0x34),
             (int)(char)(&DAT_004ff5ac)[player_idx * 0x34],
             *(int32_t *)(&DAT_005daf18 + *(int *)(&DAT_004ff590 + player_idx * 0x34) * 4));
  }
  _fclose(fp);
  return;
}



/*
 * Decompiled function: Csv_ReadConcise_00492872
 * Entry Point: 00492872
 * Size: 223 bytes
 */


void Csv_ReadConcise_00492872(void)

{
  uint8_t loop_idx [4];
  uint8_t color_idx [4];
  int32_t target_idx;
  int player_idx;
  int card_idx;
  FILE *match_count;
  int slot_idx;
  
  for (player_idx = 0; player_idx < 0x4e2; player_idx = player_idx + 1) {
    *(int32_t *)(&DAT_005daf18 + player_idx * 4) = 0xffffffff;
  }
  match_count = _fopen(s_concise_csv_00505410,&DAT_0050540c);
  card_idx = 0;
  for (player_idx = 0; player_idx < DAT_00665ed0; player_idx = player_idx + 1) {
    card_idx = *(int *)(&DAT_004ff590 + player_idx * 0x34);
    slot_idx = _fscanf(match_count,s__d__d__ld_0050541c,color_idx,loop_idx,&target_idx);
    (&DAT_004ff5ac)[player_idx * 0x34] = loop_idx[0];
    *(int32_t *)(&DAT_005daf18 + card_idx * 4) = target_idx;
  }
  _fclose(match_count);
  return;
}



/*
 * Decompiled function: Csv_LoadMaster_00492951
 * Entry Point: 00492951
 * Size: 436 bytes
 */


/* WARNING: Type propagation algorithm not settling */

void Csv_LoadMaster_00492951(uint8_t *color_mask,int y,int width,char *str_4)

{
  bool flag_1;
  int val_2;
  size_t len_3;
  int local_220;
  uint8_t local_21c [11];
  char acStack_211 [513];
  char card_idx;
  FILE *match_count;
  int slot_idx;
  
  match_count = _fopen(str_4,&DAT_00505428);
  flag_1 = false;
  card_idx = '\0';
  *color_mask = 0;
  if ((*(int *)(&DAT_005daf18 + y * 4) != -1) &&
     (val_2 = _strcmp(str_4,s_master_csv_0050542c), val_2 == 0)) {
    _fseek(match_count,*(long *)(&DAT_005daf18 + y * 4),0);
  }
  while (slot_idx = _fscanf(match_count,s______________00505438,(int)acStack_211 + 1,local_21c),
        slot_idx != 0) {
    if (acStack_211[1] == '0') {
      local_220 = _atoi((char *)((int)acStack_211 + 1));
    }
    if (local_220 == y) {
      card_idx = card_idx + '\x01';
      if ((card_idx == width) && (flag_1)) {
        Str_CopyFast((uint32_t *)color_mask,(uint32_t *)&DAT_00505448);
      }
      if (acStack_211[1] == '\"') {
        flag_1 = true;
      }
      if (card_idx == width) {
        Str_CopyFast((uint32_t *)color_mask,(uint32_t *)((int)acStack_211 + 1));
      }
      len_3 = _strlen((char *)((int)acStack_211 + 1));
      if (acStack_211[len_3] == '\"') {
        flag_1 = false;
      }
      if (flag_1) {
        card_idx = card_idx + -1;
      }
    }
    if ((slot_idx == -1) || ((card_idx != '\0' && (local_220 != y)))) break;
  }
  _fclose(match_count);
  return;
}



/*
 * Decompiled function: Mem_AllocOrFree_00492b05
 * Entry Point: 00492b05
 * Size: 18 bytes
 */


int32_t Mem_AllocOrFree_00492b05(void)

{
  return 0;
}



/*
 * Decompiled function: FUN_00492b17
 * Entry Point: 00492b17
 * Size: 121 bytes
 */


void FUN_00492b17(char *filepath,int arg2)

{
  int val_1;
  size_t len_2;
  
  while( true ) {
    val_1 = Mem_AllocOrFree_0049f5c6(str_1);
    if (val_1 <= arg2) break;
    len_2 = _strlen(str_1);
    if (str_1[len_2 - 3] != ' ') {
      len_2 = _strlen(str_1);
      str_1[len_2 - 2] = '.';
    }
    len_2 = _strlen(str_1);
    str_1[len_2 - 1] = '\0';
  }
  return;
}



/*
 * Decompiled function: FUN_00492b90
 * Entry Point: 00492b90
 * Size: 73 bytes
 */


bool FUN_00492b90(char *filepath)

{
  FILE *fp;
  
  fp = _fopen(str_1,&DAT_0050544c);
  if (fp != (FILE *)0x0) {
    _fclose(fp);
  }
  return fp != (FILE *)0x0;
}



/*
 * Decompiled function: Deck_FilterAttributes_00492bd9
 * Entry Point: 00492bd9
 * Size: 1297 bytes
 */


int Deck_FilterAttributes_00492bd9(char *filter_string,int color_mask,uint32_t width,int height)

{
  int *i_ptr_1;
  int val_2;
  uint32_t local_230;
  uint32_t local_22c;
  int local_220;
  int local_21c;
  int local_218;
  char *local_214;
  int local_210;
  int local_20c;
  uint32_t local_208;
  char local_204;
  char local_203 [499];
  int card_idx;
  FILE *match_count;
  int slot_idx;
  
  Mem_AllocOrFree_004d9630((uint32_t *)&DAT_006655c0,(uint32_t *)filter_string);
  match_count = _fopen(filter_string,&DAT_00505450);
  if (match_count == (FILE *)0x0) {
    card_idx = 0;
  }
  else {
    card_idx = 0;
    local_218 = 0;
    local_230 = 0;
    slot_idx = _fscanf(match_count,s_______00505454,&local_204);
    slot_idx = _fscanf(match_count,&DAT_0050545c,&local_204);
    local_208 = 0;
    local_20c = -1;
    local_22c = 0xffffffff;
    local_210 = 0;
    local_21c = -1;
    local_220 = -1;
    do {
      slot_idx = _fscanf(match_count,s_______00505464,&local_204);
      if (local_204 == '.') {
        if (local_203[0] == 'v') {
          local_214 = _strchr(&local_204,0x20);
          if (local_214 != (char *)0x0) {
            *local_214 = '\0';
          }
          val_2 = __strcmpi(&local_204,s__vNONE_00505474);
          if (val_2 == 0) {
            local_208 = 1;
          }
          val_2 = __strcmpi(&local_204,s__vBLACK_0050547c);
          if (val_2 == 0) {
            local_208 = 2;
          }
          val_2 = __strcmpi(&local_204,s__vBLUE_00505484);
          if (val_2 == 0) {
            local_208 = 4;
          }
          val_2 = __strcmpi(&local_204,s__vRED_0050548c);
          if (val_2 == 0) {
            local_208 = 0x10;
          }
          val_2 = __strcmpi(&local_204,s__vGREEN_00505494);
          if (val_2 == 0) {
            local_208 = 8;
          }
          val_2 = __strcmpi(&local_204,s__vWHITE_0050549c);
          if (val_2 == 0) {
            local_208 = 0x20;
          }
          val_2 = __strcmpi(&local_204,s__vFAST_005054a4);
          if (val_2 == 0) {
            local_20c = 0;
          }
          val_2 = __strcmpi(&local_204,s__vLARGE_005054ac);
          if (val_2 == 0) {
            local_20c = 1;
          }
          val_2 = __strcmpi(&local_204,s__vDIRECT_005054b4);
          if (val_2 == 0) {
            local_20c = 2;
          }
          val_2 = __strcmpi(&local_204,s__vARTIFACT_005054c0);
          if (val_2 == 0) {
            local_20c = 6;
          }
        }
        else {
          _sscanf(local_203,s__d__d_0050546c,&local_220,&local_21c);
          local_210 = local_210 + local_21c;
          if (((local_208 == 0) || ((width & local_208) != 0)) &&
             ((local_20c == -1 || (local_20c == height)))) {
            *(int *)(color_mask + local_230 * 8) = local_220;
            *(int *)(color_mask + 4 + local_230 * 8) = local_21c;
            val_2 = Card_IsValidCardId(local_220);
            if (local_21c == 0) {
              local_21c = DAT_005f2f50;
            }
            if (val_2 == -1) {
              if ((local_22c != 0xffffffff) &&
                 (local_21c < *(int *)(color_mask + 4 + local_22c * 8))) {
                i_ptr_1 = (int *)(color_mask + 4 + local_22c * 8);
                *i_ptr_1 = *i_ptr_1 - (int)((local_230 & 1) + local_21c) / 2;
              }
            }
            else if (val_2 < 5) {
              local_22c = local_230;
            }
          }
        }
        local_230 = local_230 + 1;
      }
      else {
        local_218 = local_218 + 1;
        if (local_218 == 5) {
          card_idx = _atoi(local_203);
        }
        else if ((local_218 == 6) && (val_2 = _strcmp(local_203,s_4th_Edition_005054cc), val_2 != 0)
                ) {
          card_idx = -2;
        }
      }
      slot_idx = _fscanf(match_count,&DAT_005054d8,&local_204);
    } while ((((int)local_230 < 0x50) && (slot_idx != -1)) && ((local_220 != 0 || (local_21c != 0))))
    ;
    _fclose(match_count);
    if (local_210 < 0x28) {
      card_idx = -3;
    }
    if (0x37 < card_idx) {
      card_idx = -1;
    }
  }
  return card_idx;
}



/*
 * Decompiled function: Tale_Load_004930ea
 * Entry Point: 004930ea
 * Size: 192 bytes
 */


void Tale_Load_004930ea(int player_id)

{
  int local_74;
  char local_70 [100];
  FILE *match_count;
  int slot_idx;
  
  match_count = _fopen(s_tale_txt_005054e4,&DAT_005054e0);
  local_74 = 0;
  do {
    slot_idx = _fscanf(match_count,s_______005054f0,local_70);
    if (local_70[0] == '.') {
      local_74 = local_74 + 1;
    }
    else if (local_74 == color_mask) {
      Str_CopyFast((uint32_t *)&g_DuelCardChoicePrompt,(uint32_t *)local_70);
      Str_CopyFast((uint32_t *)&g_DuelCardChoicePrompt,(uint32_t *)&DAT_005054f8);
    }
    slot_idx = _fscanf(match_count,&DAT_005054fc,local_70);
  } while ((slot_idx != -1) && (local_74 <= color_mask));
  _fclose(match_count);
  return;
}



/*
 * Decompiled function: Hints_Load_004931aa
 * Entry Point: 004931aa
 * Size: 578 bytes
 */


void Hints_Load_004931aa(void)

{
  char *char_ptr_1;
  long lVar2;
  int local_124;
  char local_120 [8];
  int local_118;
  int local_114;
  int32_t local_110;
  char local_10c;
  char local_10b [255];
  FILE *match_count;
  int slot_idx;
  
  match_count = _fopen(s_hints_txt_00505508,&DAT_00505504);
  local_118 = 0;
  do {
    slot_idx = _fscanf(match_count,s_______00505514,&local_10c);
    if (local_10c == '.') {
      _sscanf(local_10b,s__d__d__s_0050551c,&local_124,&local_114,local_120);
      *(int *)(&DAT_006656d0 + local_118 * 8) = local_124;
      *(int *)(&DAT_006656d4 + local_118 * 8) = local_114;
      *(int32_t *)(&DAT_006651c0 + local_118 * 4) = 0;
      char_ptr_1 = _strchr(local_120,0x41);
      if (char_ptr_1 != (char *)0x0) {
        *(uint32_t *)(&DAT_006651c0 + local_118 * 4) = *(uint32_t *)(&DAT_006651c0 + local_118 * 4) | 1;
      }
      char_ptr_1 = _strchr(local_120,0x42);
      if (char_ptr_1 != (char *)0x0) {
        *(uint32_t *)(&DAT_006651c0 + local_118 * 4) = *(uint32_t *)(&DAT_006651c0 + local_118 * 4) | 2;
      }
      char_ptr_1 = _strchr(local_120,0x43);
      if (char_ptr_1 != (char *)0x0) {
        *(uint32_t *)(&DAT_006651c0 + local_118 * 4) = *(uint32_t *)(&DAT_006651c0 + local_118 * 4) | 4;
      }
      char_ptr_1 = _strchr(local_120,0x44);
      if (char_ptr_1 != (char *)0x0) {
        *(uint32_t *)(&DAT_006651c0 + local_118 * 4) = *(uint32_t *)(&DAT_006651c0 + local_118 * 4) | 8;
      }
      local_110 = Card_IsValidCardId(local_124);
      local_110 = Card_IsValidCardId(local_114);
      slot_idx = _fscanf(match_count,&DAT_00505528,&local_10c);
      lVar2 = _ftell(match_count);
      *(long *)(&DAT_00664dc0 + local_118 * 4) = lVar2;
      local_118 = local_118 + 1;
    }
    else {
      slot_idx = _fscanf(match_count,&DAT_00505530,&local_10c);
    }
  } while ((local_118 < 0x100) && (slot_idx != -1));
  do {
    *(int32_t *)(&DAT_006656d4 + local_118 * 8) = 0xffffffff;
    *(int32_t *)(&DAT_006656d0 + local_118 * 8) = *(int32_t *)(&DAT_006656d4 + local_118 * 8);
    local_118 = local_118 + 1;
  } while (local_118 < 0x100);
  _fclose(match_count);
  return;
}



/*
 * Decompiled function: Hints_Load_004933ec
 * Entry Point: 004933ec
 * Size: 122 bytes
 */


void Hints_Load_004933ec(int player_id)

{
  uint32_t local_10c [64];
  FILE *match_count;
  int slot_idx;
  
  match_count = _fopen(s_hints_txt_0050553c,&DAT_00505538);
  _fseek(match_count,*(long *)(&DAT_00664dc0 + color_mask * 4),0);
  slot_idx = _fscanf(match_count,s_______00505548,local_10c);
  Str_CopyFast((uint32_t *)&g_DuelCardChoicePrompt,local_10c);
  _fclose(match_count);
  return;
}



/*
 * Decompiled function: FUN_00493466
 * Entry Point: 00493466
 * Size: 681 bytes
 */


int FUN_00493466(int player_id)

{
  int val_1;
  int val_2;
  int local_420;
  int local_41c;
  int local_418;
  int aiStack_404 [256];
  
  local_420 = 0;
  for (local_418 = 0; local_418 < 0x100; local_418 = local_418 + 1) {
    if (*(int *)(&DAT_006656d4 + local_418 * 8) == -1) {
      if (((*(int *)(&DAT_004ff590 + color_mask * 0x34) == *(int *)(&DAT_006656d0 + local_418 * 8)) &&
          (val_1 = FUN_00493714(*(int *)(&DAT_006656d0 + local_418 * 8)), val_1 == 0)) &&
         ((*(uint32_t *)(&DAT_006651c0 + local_418 * 4) & 1 << ((uint8_t)DAT_005f2f50 & 0x1f)) != 0)) {
        local_41c = 0;
        while ((local_41c < 500 &&
               ((((&g_DuelMasterCardTable)[(*(uint32_t *)(&deck + local_41c * 4) & 0xfff) * 0x34] & 1) == 0 ||
                (((&DAT_004ff596)[color_mask * 0x34] &
                 (&DAT_004ff596)[(*(uint32_t *)(&deck + local_41c * 4) & 0xfff) * 0x34]) == 0))))) {
          local_41c = local_41c + 1;
        }
      }
    }
    else {
      val_1 = FUN_00493714(*(int *)(&DAT_006656d0 + local_418 * 8));
      val_2 = FUN_00493714(*(int *)(&DAT_006656d4 + local_418 * 8));
      if (((val_1 == 0) || (val_2 == 0)) &&
         ((*(uint32_t *)(&DAT_006651c0 + local_418 * 4) & 1 << ((uint8_t)DAT_005f2f50 & 0x1f)) != 0)) {
        if ((*(int *)(&DAT_004ff590 + color_mask * 0x34) == *(int *)(&DAT_006656d0 + local_418 * 8)) &&
           (val_2 != 0)) {
          aiStack_404[local_420] = local_418;
          local_420 = local_420 + 1;
        }
        if ((*(int *)(&DAT_006656d4 + local_418 * 8) == *(int *)(&DAT_004ff590 + color_mask * 0x34)) &&
           (val_1 != 0)) {
          aiStack_404[local_420] = local_418;
          local_420 = local_420 + 1;
        }
      }
    }
  }
  if (local_420 == 0) {
    val_1 = -1;
  }
  else {
    val_1 = Duel_RandomRange(local_420);
    val_1 = aiStack_404[val_1];
  }
  return val_1;
}



/*
 * Decompiled function: FUN_00493714
 * Entry Point: 00493714
 * Size: 103 bytes
 */


int32_t FUN_00493714(int player_id)

{
  int slot_idx;
  
  slot_idx = 0;
  while( true ) {
    if (499 < slot_idx) {
      return 0;
    }
    if (*(int *)(&DAT_004ff590 + (*(uint32_t *)(&deck + slot_idx * 4) & 0xfff) * 0x34) == color_mask) break;
    slot_idx = slot_idx + 1;
  }
  return 1;
}



/*
 * Decompiled function: FUN_0049377b
 * Entry Point: 0049377b
 * Size: 144 bytes
 */


char * FUN_0049377b(char *filepath)

{
  for (; ((*str_1 != '\0' && (*str_1 == ' ')) && (*str_1 != '\n')); str_1 = str_1 + 1) {
  }
  for (; ((*str_1 != '\0' && (*str_1 != ' ')) && (*str_1 != '\n')); str_1 = str_1 + 1) {
  }
  if (*str_1 == '\0') {
    str_1 = (char *)0x0;
  }
  return str_1;
}



/*
 * Decompiled function: UI_Register_WINBK_Attack_00493810
 * Entry Point: 00493810
 * Size: 1020 bytes
 */


int32_t UI_Register_WINBK_Attack_00493810(LPCSTR str_1)

{
  ATOM AVar1;
  uint32_t local_138 [66];
  int32_t local_30;
  WNDCLASSA local_2c;
  
  local_30 = 1;
  local_2c.style = 0x800;
  local_2c.lpfnWndProc = SpellChain_WndProc;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 8;
  local_2c.hInstance = g_DuelInstanceHandle;
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
  local_2c.lpfnWndProc = UI_WndProc_0049866e;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 0;
  local_2c.hInstance = g_DuelInstanceHandle;
  local_2c.hIcon = (HICON)0x0;
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = (HBRUSH)0x6;
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = s_AttackSwordShield_00505554;
  AVar1 = RegisterClassA(&local_2c);
  if (AVar1 == 0) {
    local_30 = 0;
  }
  local_2c.style = 3;
  local_2c.lpfnWndProc = SpellChain_MinimizedWndProc;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 0;
  local_2c.hInstance = g_DuelInstanceHandle;
  local_2c.hIcon = (HICON)0x0;
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = (HBRUSH)0x6;
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = s_AttackMinimized_00505568;
  AVar1 = RegisterClassA(&local_2c);
  if (AVar1 == 0) {
    local_30 = 0;
  }
  DAT_005dc2d8 = CreatePopupMenu();
  Mem_AllocOrFree_004d9630(local_138,(uint32_t *)&g_DuelAssetDirectory);
  Str_CopyFast(local_138,(uint32_t *)s__WINBK_Attack_pic_00505578);
  DAT_005dc30c = Pic_LoadKimPicture((char *)local_138);
  Mem_AllocOrFree_004d9630(local_138,(uint32_t *)&g_DuelAssetDirectory);
  Str_CopyFast(local_138,(uint32_t *)s__WINBK_AttackSword_pic_0050558c);
  DAT_005dc2b0 = Pic_LoadKimPicture((char *)local_138);
  Mem_AllocOrFree_004d9630(local_138,(uint32_t *)&g_DuelAssetDirectory);
  Str_CopyFast(local_138,(uint32_t *)s__WINBK_AttackShield_pic_005055a4);
  DAT_005dc2e0 = Pic_LoadKimPicture((char *)local_138);
  Mem_AllocOrFree_004d9630(local_138,(uint32_t *)&g_DuelAssetDirectory);
  Str_CopyFast(local_138,(uint32_t *)s__WINBK_AttackBones_pic_005055bc);
  DAT_005dc2c0 = Pic_LoadKimPicture((char *)local_138);
  Mem_AllocOrFree_004d9630(local_138,(uint32_t *)&g_DuelAssetDirectory);
  Str_CopyFast(local_138,(uint32_t *)s__WINBK_AttackRats_pic_005055d4);
  DAT_005dc2ac = Pic_LoadKimPicture((char *)local_138);
  DAT_00505550 = 6;
  Mem_AllocOrFree_004d9630(local_138,(uint32_t *)&g_DuelAssetDirectory);
  Str_CopyFast(local_138,(uint32_t *)s__WINBK_AttackMin_pic_005055ec);
  DAT_005dc2f8 = Pic_LoadKimPicture((char *)local_138);
  DAT_005dc2cc = CreatePen(0,0,0x10000b4);
  DAT_005dc2fc = CreatePen(0,0,0x100007c);
  DAT_005dc2b8 = CreatePen(0,0,0x1000050);
  DAT_005dc2d4 = CreateSolidBrush(0x1000076);
  DAT_005dc2e4 = CreatePen(0,0,0x10000d3);
  DAT_005dc2e8 = CreatePen(0,0,0x100002f);
  DAT_005dc2c4 = CreatePen(0,0,0x10000d7);
  DAT_005dc2f4 = CreateSolidBrush(0x100003a);
  DAT_005dc2c8 = 0x10000bf;
  DAT_005dc308 = 0x10000c9;
  if (((((DAT_005dc2cc == (HPEN)0x0) || (DAT_005dc2fc == (HPEN)0x0)) || (DAT_005dc2b8 == (HPEN)0x0))
      || ((DAT_005dc2d4 == (HBRUSH)0x0 || (DAT_005dc2e4 == (HPEN)0x0)))) ||
     ((DAT_005dc2e8 == (HPEN)0x0 || ((DAT_005dc2c4 == (HPEN)0x0 || (DAT_005dc2f4 == (HBRUSH)0x0)))))
     ) {
    local_30 = 0;
  }
  return local_30;
}



/*
 * Decompiled function: FUN_00493c0c
 * Entry Point: 00493c0c
 * Size: 548 bytes
 */


void FUN_00493c0c(void)

{
  if (DAT_005dc2d8 != (HMENU)0x0) {
    DestroyMenu(DAT_005dc2d8);
  }
  DAT_005dc2d8 = (HMENU)0x0;
  if (DAT_005dc30c != (HANDLE)0x0) {
    GDI_DestroyDIBSection(DAT_005dc30c);
  }
  if (DAT_005dc2b0 != (HANDLE)0x0) {
    GDI_DestroyDIBSection(DAT_005dc2b0);
  }
  if (DAT_005dc2e0 != (HANDLE)0x0) {
    GDI_DestroyDIBSection(DAT_005dc2e0);
  }
  if (DAT_005dc2c0 != (HANDLE)0x0) {
    GDI_DestroyDIBSection(DAT_005dc2c0);
  }
  if (DAT_005dc2ac != (HANDLE)0x0) {
    GDI_DestroyDIBSection(DAT_005dc2ac);
  }
  if (DAT_005dc2f8 != (HANDLE)0x0) {
    GDI_DestroyDIBSection(DAT_005dc2f8);
  }
  if (DAT_005dc2cc != (HGDIOBJ)0x0) {
    DeleteObject(DAT_005dc2cc);
  }
  if (DAT_005dc2fc != (HGDIOBJ)0x0) {
    DeleteObject(DAT_005dc2fc);
  }
  if (DAT_005dc2b8 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_005dc2b8);
  }
  if (DAT_005dc2d4 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_005dc2d4);
  }
  if (DAT_005dc2e4 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_005dc2e4);
  }
  if (DAT_005dc2e8 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_005dc2e8);
  }
  if (DAT_005dc2c4 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_005dc2c4);
  }
  if (DAT_005dc2f4 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_005dc2f4);
  }
  DAT_005dc30c = (HANDLE)0x0;
  DAT_005dc2b0 = (HANDLE)0x0;
  DAT_005dc2e0 = (HANDLE)0x0;
  DAT_005dc2c0 = (HANDLE)0x0;
  DAT_005dc2ac = (HANDLE)0x0;
  DAT_005dc2f8 = (HANDLE)0x0;
  DAT_005dc2cc = (HGDIOBJ)0x0;
  DAT_005dc2fc = (HGDIOBJ)0x0;
  DAT_005dc2b8 = (HGDIOBJ)0x0;
  DAT_005dc2d4 = (HGDIOBJ)0x0;
  DAT_005dc2e4 = (HGDIOBJ)0x0;
  DAT_005dc2e8 = (HGDIOBJ)0x0;
  DAT_005dc2c4 = (HGDIOBJ)0x0;
  DAT_005dc2f4 = (HGDIOBJ)0x0;
  return;
}



/*
 * Decompiled function: SpellChain_WndProc
 * Entry Point: 00493e30
 * Size: 14669 bytes
 */


uint32_t SpellChain_WndProc(HWND hwnd,uint32_t y,HWND param_3,HWND param_4)

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
  uint32_t local_414 [66];
  HWND local_30c;
  uint8_t local_308 [4];
  int local_304;
  tagRECT local_2f0;
  tagRECT local_2e0;
  LRESULT local_2d0;
  HWND local_2cc;
  uint32_t local_2c8 [66];
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
  int32_t local_60;
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
        SendMessageA(DAT_00694748,0x86,1,0);
      }
      else {
        SendMessageA(DAT_00694748,0x86,0,0);
      }
      uval_8 = DefWindowProcA(hwnd,6,(WPARAM)param_3,(LPARAM)param_4);
      return uval_8;
    }
    if (y == 1) {
      slot_idx = 0;
      SetWindowLongA(hwnd,4,0);
      match_count = _malloc(0xa0f0);
      SetWindowLongA(hwnd,0,(LONG)match_count);
      local_2cc = CreateWindowExA(0,s_MAGICGAME_ScrollbarClass_0050565c,&DAT_00505658,0x50000000,0,0
                                  ,0,0,hwnd,(HMENU)0x0,g_DuelInstanceHandle,(LPVOID)0x0);
      if (local_2cc != (HWND)0x0) {
        SendMessageA(local_2cc,0x464,DAT_005dc2c0,1);
        SendMessageA(local_2cc,0x466,DAT_005dc2ac,DAT_00505550);
      }
      lpParam = (LPVOID)0x0;
      hMenu = (HMENU)0x0;
      hInstance = g_DuelInstanceHandle;
      pHVar6 = GetParent(hwnd);
      DAT_00694748 = CreateWindowExA(0,s_AttackSwordShield_0050567c,&DAT_00505678,0x80c00000,0,0,0,0
                                     ,pHVar6,hMenu,hInstance,lpParam);
      DAT_005dc2bc = CreateWindowExA(0,s_AttackMinimized_00505694,&DAT_00505690,0x80000000,0,0,0,0,
                                     hwnd,(HMENU)0x0,g_DuelInstanceHandle,(LPVOID)0x0);
      if ((((match_count != (void *)0x0) && (local_2cc != (HWND)0x0)) && (DAT_00694748 != (HWND)0x0)) &&
         (DAT_005dc2bc != (HWND)0x0)) {
        return 0;
      }
      if (match_count != (void *)0x0) {
        FUN_004db150(match_count);
      }
      return 0xffffffff;
    }
    if (y == 2) {
      match_count = (void *)GetWindowLongA(hwnd,0);
      FUN_004db150(match_count);
      return 0;
    }
  }
  else if (y < 0x15) {
    if (y == 0x14) {
      local_30c = param_3;
      GDI_RealizeAndFlushPalette((HDC)param_3);
      GetClientRect(hwnd,&local_2e0);
      local_2d0 = SendDlgItemMessageA(hwnd,0,0xe1,0,0);
      if (DAT_005dc30c == (HANDLE)0x0) {
        Mem_AllocOrFree_004d9630(local_414,(uint32_t *)&g_DuelAssetDirectory);
        Str_CopyFast(local_414,(uint32_t *)s__WINBK_Attack_pic_005056a4);
        DAT_005dc30c = (HANDLE)Pic_LoadKimPicture((char *)local_414);
      }
      if (DAT_005dc30c == (HANDLE)0x0) {
        hbr = GetStockObject(4);
        FillRect((HDC)local_30c,&local_2e0,hbr);
      }
      else {
        CopyRect(&local_2f0,&local_2e0);
        GetObjectA(DAT_005dc30c,0x18,local_308);
        local_2f0.left = -(local_2d0 % local_304);
        FUN_00470b60((HDC)local_30c,&local_2f0.left,DAT_005dc30c);
      }
      return 1;
    }
    if (y == 0x10) {
      ShowWindow(hwnd,0);
      ShowWindow(DAT_005dc2bc,0);
      return 0;
    }
  }
  else if (y < 0x21) {
    if (y == 0x20) {
      uval_8 = UI_WndProc_00471df6(hwnd,0x20,(WPARAM)param_3,(LPARAM)param_4);
      return uval_8;
    }
    if (y == 0x18) {
      if (param_3 == (HWND)0x0) {
        ShowWindow(DAT_00694748,0);
      }
      else {
        ShowWindow(DAT_00694748,5);
      }
      PostMessageA(DAT_00664d90,0x403,0,0);
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
        GDI_RealizeAndFlushPalette(local_4f0);
        GetWindowRect(hwnd,&local_494);
        GetClientRect(hwnd,&local_56c);
        MapWindowPoints(hwnd,(HWND)0x0,(LPPOINT)&local_56c,2);
        OffsetRect(&local_56c,-local_494.left,-local_494.top);
        OffsetRect(&local_494,-local_494.left,-local_494.top);
        GetWindowTextA(hwnd,local_558,100);
        local_574 = local_494.right - local_56c.right;
        local_4c4 = local_494.bottom - local_56c.bottom;
        FUN_0044897a(&local_484,(int32_t *)0x0);
        if (local_484 == 0) {
          local_498 = DAT_005dc2cc;
          local_570 = DAT_005dc2fc;
          local_480 = DAT_005dc2b8;
          local_4f4 = DAT_005dc2d4;
        }
        else {
          local_498 = DAT_005dc2e4;
          local_570 = DAT_005dc2e8;
          local_480 = DAT_005dc2c4;
          local_4f4 = DAT_005dc2f4;
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
        SetTextColor(local_4f0,DAT_005dc308);
        DrawTextA(local_4f0,local_558,-1,&local_4a8,0x24);
        OffsetRect(&local_4a8,-1,-1);
        SetTextColor(local_4f0,DAT_005dc2c8);
        DrawTextA(local_4f0,local_558,-1,&local_4a8,0x24);
        local_55c = LoadBitmapA((HINSTANCE)0x0,(LPCSTR)0x7fed);
        GetObjectA(local_55c,0x18,local_4ec);
        local_4d0 = local_4e8;
        local_4d4 = local_4e4;
        SetRect(&local_4b8,local_56c.right - local_4e8,local_56c.top - local_4e4,local_56c.right,
                local_56c.top);
        GDI_DrawBitmapToHDC((int)local_4f0,(int)&local_4b8,DAT_005dc2f8);
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
        Mem_AllocOrFree_004d9630(local_2c8,(uint32_t *)&DAT_005f76e0);
        Str_CopyFast(local_2c8,(uint32_t *)s__duel_hlp_0050564c);
        WinHelpA(g_DuelMainHwnd,(LPCSTR)local_2c8,1,local_1c0);
      }
      else if (uval_8 == 0x65) {
        ShowWindow(hwnd,0);
        UpdateWindow(DAT_00618988);
        GetWindowRect(DAT_006152ec,&local_194);
        local_198 = local_194.left;
        local_1a0 = local_194.right - local_194.left;
        if (DAT_005dc2f8 == (HANDLE)0x0) {
          local_1bc = local_1a0 * 2;
        }
        else {
          GetObjectA(DAT_005dc2f8,0x18,local_1b8);
          local_1bc = (local_1b0 * local_1a0) / local_1b4;
        }
        local_19c = (local_194.bottom - local_194.top) / 2 + local_1bc / 2 + 2;
        MoveWindow(DAT_005dc2bc,local_198,local_19c,local_1a0,local_1bc,1);
        ShowWindow(DAT_005dc2bc,5);
        BringWindowToTop(DAT_005dc2bc);
        SendMessageA(DAT_00664d90,0x403,0,0);
      }
      else if (uval_8 == 0x66) {
        ShowWindow(DAT_005dc2bc,0);
        ShowWindow(hwnd,5);
        SendMessageA(DAT_00664d90,0x403,0,0);
        FUN_0047283d();
      }
      return 0;
    }
    if (y == 0xa4) {
LAB_00497475:
      local_594.x = (uint32_t)param_4 & 0xffff;
      local_594.y = (uint32_t)param_4 >> 0x10;
      if (y == 0x204) {
        ClientToScreen(hwnd,&local_594);
      }
      SetRect(&local_58c,local_594.x,local_594.y,local_594.x + 1,local_594.y + 1);
      TrackPopupMenu(DAT_005dc2d8,2,local_594.x,local_594.y,0,hwnd,&local_58c);
      return 0;
    }
  }
  else if (y < 0x120) {
    if (y == 0x11f) {
      if (((uint32_t)param_3 >> 0x10 == 0xffff) && (param_4 == (HWND)0x0)) {
        local_598 = GetMenuItemCount(DAT_005dc2d8);
        while (local_598 != 0) {
          DeleteMenu(DAT_005dc2d8,0,0x400);
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
      local_444 = DAT_0061534c;
      GetClientRect(hwnd,&local_430);
      local_450 = local_430.right;
      switch((uint32_t)param_3 & 0xffff) {
      case 0:
        local_418 = local_44c - local_444;
        break;
      case 1:
        local_418 = local_44c + local_444;
        break;
      case 2:
        local_418 = local_44c - local_430.right;
        break;
      case 3:
        local_418 = local_44c + local_430.right;
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
      AppendMenuA(DAT_005dc2d8,0,0x65,s__Minimize_005056b8);
      AppendMenuA(DAT_005dc2d8,0,100,s_Help____005056c4);
      return 0;
    }
  }
  else if (y < 0x205) {
    if (y == 0x204) goto LAB_00497475;
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
      FUN_004994f8(hwnd,&param_3->unused,(int32_t *)0x0,&local_8c,&local_84);
      if ((local_8c == (HWND)0x0) ||
         (((local_84 == 0 || (y != 0x400)) && ((local_84 != 0 || (y != 0x401)))))) {
        local_7c = 0;
      }
      else {
        local_7c = 1;
      }
      if (local_7c == 0) {
        local_8c = CreateWindowExA(0,s_MAGICGAME_CardClass_00505614,s_Card_in_attack_00505604,
                                   0x54000000,0,0,0,0,hwnd,(HMENU)0x1,g_DuelInstanceHandle,local_88);
        if (local_8c == (HWND)0x0) {
          return 0;
        }
        if (y == 0x400) {
          local_80 = FUN_00447038(local_88->unused,local_88[1].unused);
          if (local_80 == -1) {
            local_80 = local_88[1].unused;
          }
        }
        else {
          local_80 = FUN_00447038(local_88->unused,local_88[1].unused);
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
            *(int32_t *)((int)match_count + 0xcc + slot_idx * 0x19c) = 1;
            *(int32_t *)((int)match_count + 0x198 + slot_idx * 0x19c) = 0;
          }
          else {
            *(HWND *)((int)match_count + 0xd0 + slot_idx * 0x19c) = local_8c;
            *(int32_t *)((int)match_count + 0x198 + slot_idx * 0x19c) = 1;
            *(int32_t *)((int)match_count + 0xcc + slot_idx * 0x19c) = 0;
          }
          slot_idx = slot_idx + 1;
          SetWindowLongA(hwnd,4,slot_idx);
        }
        BringWindowToTop(local_8c);
      }
      return 1;
    }
    if ((0x30e < y) && (y < 0x312)) {
      uval_8 = GDI_RealizePaletteTree(hwnd,y,param_3,param_4);
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
        FUN_004994f8(hwnd,&param_3->unused,(int32_t *)0x0,&local_e8,(int32_t *)0x0);
      }
      if ((local_e8 != (HWND)0x0) && (pHVar6 = GetParent(local_e8), pHVar6 == hwnd)) {
        for (local_ec = 0; local_ec < slot_idx; local_ec = local_ec + 1) {
          local_e4 = 0;
          local_f0 = 0;
          while ((local_f0 < *(int *)((int)match_count + 0xcc + local_ec * 0x19c) && (local_e4 == 0))) {
            if ((y == 0x403) &&
               (*(HWND *)(local_f0 * 4 + local_ec * 0x19c + 4 + (int)match_count) == local_e8)) {
              local_e4 = 1;
              FUN_00497849((int)local_e8,local_ec * 0x19c + (int)match_count + 4,
                           *(int *)((int)match_count + 0xcc + local_ec * 0x19c));
              local_f8 = 0;
              for (local_f4 = 0; local_f4 < *(int *)((int)match_count + 0xcc + local_ec * 0x19c);
                  local_f4 = local_f4 + 1) {
                if (*(int *)(local_f4 * 4 + local_ec * 0x19c + 4 + (int)match_count) != 0) {
                  *(int32_t *)(local_f8 * 4 + local_ec * 0x19c + 4 + (int)match_count) =
                       *(int32_t *)(local_f4 * 4 + local_ec * 0x19c + 4 + (int)match_count);
                  local_f8 = local_f8 + 1;
                }
              }
              *(int *)((int)match_count + 0xcc + local_ec * 0x19c) = local_f8;
            }
            else if ((y == 0x402) &&
                    (*(HWND *)(local_f0 * 4 + local_ec * 0x19c + 0xd0 + (int)match_count) == local_e8))
            {
              local_e4 = 1;
              FUN_00497849((int)local_e8,local_ec * 0x19c + (int)match_count + 0xd0,
                           *(int *)((int)match_count + 0x198 + local_ec * 0x19c));
              local_f8 = 0;
              for (local_f4 = 0; local_f4 < *(int *)((int)match_count + 0x198 + local_ec * 0x19c);
                  local_f4 = local_f4 + 1) {
                if (*(int *)(local_f4 * 4 + local_ec * 0x19c + 0xd0 + (int)match_count) != 0) {
                  *(int32_t *)(local_f8 * 4 + local_ec * 0x19c + 0xd0 + (int)match_count) =
                       *(int32_t *)(local_f4 * 4 + local_ec * 0x19c + 0xd0 + (int)match_count);
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
              val_3 = FUN_004864b1(*(HWND *)(local_13c * 4 + local_138 * 0x19c + 4 + (int)match_count));
              if (val_3 == 0) {
                local_130[local_140].unused =
                     *(int *)(local_13c * 4 + local_138 * 0x19c + 4 + (int)match_count);
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
      val_3 = FUN_004994f8(hwnd,&local_a0->unused,(int32_t *)0x0,(int32_t *)0x0,
                           (int32_t *)0x0);
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
      local_a4 = CreateWindowExA(0,s_MAGICGAME_CardClass_00505638,s_Card_in_attack_00505628,
                                 0x54000000,0,0,0,0,hwnd,(HMENU)0x1,g_DuelInstanceHandle,local_a0);
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
      ShowWindow(DAT_005dc2bc,0);
      for (local_100 = 0; local_100 < slot_idx; local_100 = local_100 + 1) {
        for (local_104 = 0; local_104 < *(int *)((int)match_count + 0xcc + local_100 * 0x19c);
            local_104 = local_104 + 1) {
          DestroyWindow(*(HWND *)(local_104 * 4 + local_100 * 0x19c + 4 + (int)match_count));
        }
        *(int32_t *)((int)match_count + 0xcc + local_100 * 0x19c) = 0;
        for (local_104 = 0; local_104 < *(int *)((int)match_count + 0x198 + local_100 * 0x19c);
            local_104 = local_104 + 1) {
          DestroyWindow(*(HWND *)(local_104 * 4 + local_100 * 0x19c + 0xd0 + (int)match_count));
        }
        *(int32_t *)((int)match_count + 0x198 + local_100 * 0x19c) = 0;
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
            val_3 = FUN_00486348(*(HWND *)(local_118 * 4 + local_114 * 0x19c + 4 + (int)match_count),
                                 &local_110->unused);
            if (val_3 != 0) {
              local_108 = 1;
              if (y == 0x40e) {
                local_10c = FUN_0048644e(*(HWND *)(local_118 * 4 + local_114 * 0x19c + 4 +
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
            val_3 = FUN_00486348(*(HWND *)(local_118 * 4 + local_114 * 0x19c + 0xd0 + (int)match_count),
                                 &local_110->unused);
            if (val_3 != 0) {
              local_108 = 1;
              if (y == 0x40e) {
                local_10c = FUN_0048644e(*(HWND *)(local_118 * 4 + local_114 * 0x19c + 0xd0 +
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
      local_e0 = DAT_00664d4c;
      GetWindowRect(param_3,&local_c4);
      MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_c4,2);
      local_cc = local_c4.left + local_dc;
      local_d0 = local_c4.top - local_e0;
      local_b4 = local_c8;
      for (local_d4 = 0; local_d4 < slot_idx; local_d4 = local_d4 + 1) {
        for (local_d8 = 0; local_d8 < *(int *)((int)match_count + 0xcc + local_d4 * 0x19c);
            local_d8 = local_d8 + 1) {
          pHVar6 = (HWND)FUN_004864b1(*(HWND *)(local_d8 * 4 + local_d4 * 0x19c + 4 + (int)match_count))
          ;
          if (pHVar6 == local_c8) {
            SetWindowPos(*(HWND *)(local_d8 * 4 + local_d4 * 0x19c + 4 + (int)match_count),local_b4,
                         local_cc,local_d0,DAT_0061534c,DAT_0061898c,0);
            local_d0 = local_d0 - local_e0;
            local_b4 = *(HWND *)(local_d8 * 4 + local_d4 * 0x19c + 4 + (int)match_count);
          }
        }
        for (local_d8 = 0; local_d8 < *(int *)((int)match_count + 0x198 + local_d4 * 0x19c);
            local_d8 = local_d8 + 1) {
          pHVar6 = (HWND)FUN_004864b1(*(HWND *)(local_d8 * 4 + local_d4 * 0x19c + 0xd0 +
                                               (int)match_count));
          if (pHVar6 == local_c8) {
            SetWindowPos(*(HWND *)(local_d8 * 4 + local_d4 * 0x19c + 0xd0 + (int)match_count),local_b4,
                         local_cc,local_d0,DAT_0061534c,DAT_0061898c,0);
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
          local_158 = FUN_00447114(local_14c,local_16c);
          local_15c = FUN_004471f7(local_14c,local_16c);
          local_150 = FUN_00448124(local_14c,local_16c);
          FUN_004994f8(hwnd,&local_174,(int32_t *)0x0,&local_178,&local_160);
          val_3 = FUN_004b26c4(DAT_00617378,&local_174,(int32_t *)0x0,&local_144);
          if (val_3 == 0) {
            FUN_004b26c4(DAT_00618988,&local_174,(int32_t *)0x0,&local_144);
          }
          if ((local_158 != DAT_0068eee0) && (local_15c != 2)) {
            if (((local_158 == -1) || (local_15c != 1)) ||
               (((local_150 & 0x10000) != 0 && (DAT_00663e1c == 0)))) {
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
              local_148 = FUN_004472ad(local_14c,local_16c);
              local_168 = FUN_004478fb(local_14c,local_16c);
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
                  FUN_004b24c6(pHVar5,pHVar6);
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
                  FUN_004b24c6(pHVar5,pHVar6);
                  local_154 = 1;
                  LVar10 = 0;
                  UVar9 = 0x402;
                  pHVar6 = local_144;
                  pHVar5 = GetParent(local_144);
                  SendMessageA(pHVar5,UVar9,(WPARAM)pHVar6,LVar10);
                }
              }
              else {
                val_3 = FUN_004994f8(hwnd,&local_174,(int32_t *)0x0,(int32_t *)0x0,
                                     (int32_t *)0x0);
                if (val_3 == 0) {
                  FUN_0044743d(local_180,local_14c,local_16c);
                  val_3 = FUN_004994f8(hwnd,local_180,(int32_t *)0x0,&local_184,(int32_t *)0x0
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
        FUN_0049793e(hwnd);
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
          val_3 = FUN_004863ca(*(HWND *)(local_48 * 4 + local_44 * 0x19c + 4 + (int)match_count),
                               (int)local_4c);
          if (val_3 != 0) {
            InvalidateRect(*(HWND *)(local_48 * 4 + local_44 * 0x19c + 4 + (int)match_count),(RECT *)0x0
                           ,0);
          }
        }
        for (local_48 = 0; local_48 < *(int *)((int)match_count + 0x198 + local_44 * 0x19c);
            local_48 = local_48 + 1) {
          val_3 = FUN_004863ca(*(HWND *)(local_48 * 4 + local_44 * 0x19c + 0xd0 + (int)match_count),
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
          val_3 = FUN_00486348(*(HWND *)(local_68 * 4 + local_64 * 0x19c + 4 + (int)match_count),
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
          val_3 = FUN_00486348(*(HWND *)(local_68 * 4 + local_64 * 0x19c + 0xd0 + (int)match_count),
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




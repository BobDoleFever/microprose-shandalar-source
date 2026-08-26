/*
 * magic/world/database.c - Shandalar Database - CSV Parsers, Deck Filters & Rules Lookup
 * Reconstructed Module containing 14 functions
 */
#include "magic.h"

/*
 * Decompiled function: Rules_ParseFilter_0040360b
 * Entry Point: 0040360b
 * Size: 7256 bytes
 */


uint Rules_ParseFilter_0040360b
               (int card_id,int color_mask,char *str_3,int arg_4,byte arg_5,byte arg_6,uint arg_7,
               uint arg_8,uint arg_9,uint arg_10,uint arg_11,uint arg_12,uint arg_13,int arg_14,
               int arg_15,uint arg_16,uint arg_17,uint arg_18,uint arg_19,uint arg_20)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  bool bVar4;
  bool bVar5;
  int local_11c;
  int local_118;
  int local_110;
  int local_10c;
  int local_f0;
  int local_e4;
  int local_e0;
  int local_dc;
  int local_d8;
  char local_d0;
  char local_cf [199];
  uint local_8;
  
  if (card_id == -1) {
    if (str_3 != (char *)0x0) {
      strcpy(str_3,&DAT_00516068);
    }
    local_8 = 0;
  }
  else if (((card_id == -1) || (color_mask == -1)) ||
          (*(int *)(&g_CardSlot_CardId + color_mask * 0x120 + card_id * 0x5b20) != -1)) {
    bVar4 = false;
    strcpy(&local_d0,&DAT_00516070);
    if (color_mask == -1) {
      if ((arg_7 == 0) || ((arg_7 & 0x1000) != 0)) {
        if (((arg_4 == 0) && ((arg_5 & 2) != 0)) || ((arg_4 == 1 && ((arg_6 & 2) != 0)))) {
          local_d8 = 1;
          local_dc = 1;
        }
        else if (((arg_4 == 0) && ((arg_5 & 1) != 0)) || ((arg_4 == 1 && ((arg_6 & 1) != 0)))) {
          local_d8 = 0;
          local_dc = 1;
        }
      }
      else {
        local_d8 = 0;
        local_dc = 0;
      }
      if (((card_id == 0) && (local_d8 == 0)) || ((card_id == 1 && (local_dc == 0)))) {
        bVar4 = true;
        strcat(&local_d0,s__player_00516074);
      }
    }
    else {
      if (arg_4 == 0) {
        if ((arg_5 & 4) == 0) {
          if ((arg_5 & 2) == 0) {
            if ((arg_5 & 1) == 0) {
              local_e4 = 0;
            }
            else {
              local_e4 = 1;
            }
          }
          else {
            local_e4 = -1;
          }
          local_e0 = -1;
        }
        else {
          if ((arg_5 & 2) == 0) {
            if ((arg_5 & 1) == 0) {
              local_e0 = 0;
            }
            else {
              local_e0 = 1;
            }
          }
          else {
            local_e0 = -1;
          }
          local_e4 = -1;
        }
      }
      else if ((arg_6 & 4) == 0) {
        if ((arg_6 & 2) == 0) {
          if ((arg_6 & 1) == 0) {
            local_e4 = 0;
          }
          else {
            local_e4 = 1;
          }
        }
        else {
          local_e4 = -1;
        }
        local_e0 = -1;
      }
      else {
        if ((arg_6 & 2) == 0) {
          if ((arg_6 & 1) == 0) {
            local_e0 = 0;
          }
          else {
            local_e0 = 1;
          }
        }
        else {
          local_e0 = -1;
        }
        local_e4 = -1;
      }
      bVar4 = ((&DAT_006a5f3e)[color_mask * 0x120 + card_id * 0x5b20] & 0x10) != 0;
      if (bVar4) {
        strcat(&local_d0,s__can_t_target_this_0051607c);
      }
      if ((arg_7 != 0) &&
         (((((&g_CardSlot_Flags)[color_mask * 0x120 + card_id * 0x5b20] & 2) != 0 &&
           ((arg_7 & 0x200) == 0)) ||
          ((((&g_CardSlot_Flags)[color_mask * 0x120 + card_id * 0x5b20] & 2) == 0 &&
           ((arg_7 & 0x100) == 0)))))) {
        bVar4 = true;
        strcat(&local_d0,s__where_00516090);
      }
      if ((local_e4 != -1) && (local_e4 != card_id)) {
        bVar4 = true;
        strcat(&local_d0,s__controller_00516098);
      }
      if ((local_e0 != -1) &&
         (((((&DAT_006a5f3d)[color_mask * 0x120 + card_id * 0x5b20] & 0x10) != 0 && (local_e0 == 0))
          || ((((&DAT_006a5f3d)[color_mask * 0x120 + card_id * 0x5b20] & 0x10) == 0 &&
              (local_e0 != 0)))))) {
        bVar4 = true;
        strcat(&local_d0,s__owner_005160a4);
      }
      if (arg_8 != 0) {
        bVar5 = (arg_8 & (byte)(&g_MasterCardColorTable)
                               [*(int *)(&g_CardSlot_CardId + color_mask * 0x120 + card_id * 0x5b20)
                                * 0x34]) != 0;
        if (((arg_8 & 0x80) != 0) &&
           ((*(int *)(&g_MasterCardTypeTable +
                     *(int *)(&g_CardSlot_CardId + color_mask * 0x120 + card_id * 0x5b20) * 0x34) ==
             DAT_0068a694 ||
            (*(int *)(&g_MasterCardTypeTable +
                     *(int *)(&g_CardSlot_CardId + color_mask * 0x120 + card_id * 0x5b20) * 0x34) ==
             DAT_0068a70c)))) {
          bVar5 = true;
        }
        if (((arg_8 & 0x1000) != 0) &&
           (((&g_CardSlot_Abilities1)[color_mask * 0x120 + card_id * 0x5b20] & 0x10) != 0)) {
          bVar5 = true;
        }
        if (((arg_8 & 0x2000) != 0) &&
           (*(int *)(&g_MasterCardTypeTable +
                    *(int *)(&g_CardSlot_CardId + color_mask * 0x120 + card_id * 0x5b20) * 0x34) ==
            DAT_00695e94)) {
          bVar5 = true;
        }
        if (((arg_8 & 0x4000) != 0) &&
           (*(int *)(&g_MasterCardTypeTable +
                    *(int *)(&g_CardSlot_CardId + color_mask * 0x120 + card_id * 0x5b20) * 0x34) ==
            DAT_006a2848)) {
          bVar5 = true;
        }
        if (((arg_8 & 0x8000) != 0) &&
           (*(int *)(&g_MasterCardTypeTable +
                    *(int *)(&g_CardSlot_CardId + color_mask * 0x120 + card_id * 0x5b20) * 0x34) ==
            DAT_006ff2e8)) {
          bVar5 = true;
        }
        if (!bVar5) {
          bVar4 = true;
          strcat(&local_d0,s__type_005160ac);
        }
      }
      if (arg_9 != 0) {
        bVar5 = (arg_9 & (byte)(&g_MasterCardColorTable)
                               [*(int *)(&g_CardSlot_CardId + color_mask * 0x120 + card_id * 0x5b20)
                                * 0x34]) != 0;
        if (((arg_9 & 0x80) != 0) &&
           ((*(int *)(&g_MasterCardTypeTable +
                     *(int *)(&g_CardSlot_CardId + color_mask * 0x120 + card_id * 0x5b20) * 0x34) ==
             DAT_0068a694 ||
            (*(int *)(&g_MasterCardTypeTable +
                     *(int *)(&g_CardSlot_CardId + color_mask * 0x120 + card_id * 0x5b20) * 0x34) ==
             DAT_0068a70c)))) {
          bVar5 = true;
        }
        if (((arg_9 & 0x1000) != 0) &&
           (((&g_CardSlot_Abilities1)[color_mask * 0x120 + card_id * 0x5b20] & 0x10) != 0)) {
          bVar5 = true;
        }
        if (((arg_9 & 0x2000) != 0) &&
           (*(int *)(&g_MasterCardTypeTable +
                    *(int *)(&g_CardSlot_CardId + color_mask * 0x120 + card_id * 0x5b20) * 0x34) ==
            DAT_00695e94)) {
          bVar5 = true;
        }
        if (((arg_9 & 0x4000) != 0) &&
           (*(int *)(&g_MasterCardTypeTable +
                    *(int *)(&g_CardSlot_CardId + color_mask * 0x120 + card_id * 0x5b20) * 0x34) ==
            DAT_006a2848)) {
          bVar5 = true;
        }
        if (((arg_9 & 0x8000) != 0) &&
           (*(int *)(&g_MasterCardTypeTable +
                    *(int *)(&g_CardSlot_CardId + color_mask * 0x120 + card_id * 0x5b20) * 0x34) ==
            DAT_006ff2e8)) {
          bVar5 = true;
        }
        if (bVar5) {
          bVar4 = true;
          strcat(&local_d0,s__type_005160b4);
        }
      }
      if ((arg_10 != 0) &&
         ((*(uint *)(&g_CardSlot_Abilities2 + color_mask * 0x120 + card_id * 0x5b20) & arg_10) !=
          arg_10)) {
        bVar4 = true;
        strcat(&local_d0,s__abilities_005160bc);
      }
      if ((arg_11 != 0) &&
         ((arg_11 & *(uint *)(&g_CardSlot_Abilities2 + color_mask * 0x120 + card_id * 0x5b20)) != 0)
         ) {
        bVar4 = true;
        strcat(&local_d0,s__abilities_005160c8);
      }
      if ((arg_12 != 0) &&
         ((arg_12 & (int)(char)(&DAT_006a5f4d)[color_mask * 0x120 + card_id * 0x5b20]) == 0)) {
        bVar4 = true;
        strcat(&local_d0,s__color_005160d4);
      }
      if ((arg_13 != 0) &&
         ((arg_13 & (int)(char)(&DAT_006a5f4d)[color_mask * 0x120 + card_id * 0x5b20]) != 0)) {
        bVar4 = true;
        strcat(&local_d0,s__color_005160dc);
      }
      if (arg_14 != -1) {
        if (arg_14 < 5) {
          iVar1 = FUN_00405f97(*(int *)(&g_CardSlot_CardId + color_mask * 0x120 + card_id * 0x5b20),
                               arg_14);
          if (iVar1 == 0) {
            bVar4 = true;
            strcat(&local_d0,s__card_005160e4);
          }
        }
        else if (*(int *)(&g_CardSlot_CardId + color_mask * 0x120 + card_id * 0x5b20) != arg_14) {
          bVar4 = true;
          strcat(&local_d0,s__card_005160ec);
        }
      }
      if (arg_15 != -1) {
        if ((arg_18 & 0x10) == 0) {
          local_f0 = arg_15;
        }
        else if (arg_15 == 8) {
          local_f0 = 9;
        }
        else if (arg_15 == 9) {
          local_f0 = 8;
        }
        else if (arg_15 == 0x11) {
          local_f0 = 0x12;
        }
        else if (arg_15 == 0x12) {
          local_f0 = 0x11;
        }
        else if (arg_15 == 0x4a) {
          local_f0 = 0x4b;
        }
        else if (arg_15 == 0x4b) {
          local_f0 = 0x4a;
        }
        else if (arg_15 == 0x57) {
          local_f0 = 0x58;
        }
        else if (arg_15 == 0x58) {
          local_f0 = 0x57;
        }
        else if (arg_15 == 0x5a) {
          local_f0 = 0x5b;
        }
        else if (arg_15 == 0x5b) {
          local_f0 = 0x5a;
        }
        else if (arg_15 == 0x6a) {
          local_f0 = 0x6b;
        }
        else if (arg_15 == 0x6b) {
          local_f0 = 0x6a;
        }
        else if (arg_15 == 0x94) {
          local_f0 = 0x95;
        }
        else if (arg_15 == 0x95) {
          local_f0 = 0x94;
        }
        else {
          local_f0 = arg_15;
        }
        if ((*(int *)(&DAT_006b3088 +
                     *(int *)(&g_MasterCardTypeTable +
                             *(int *)(&g_CardSlot_CardId + color_mask * 0x120 + card_id * 0x5b20) *
                             0x34) * 0x98) != arg_15) &&
           (*(int *)(&DAT_006b3088 +
                    *(int *)(&g_MasterCardTypeTable +
                            *(int *)(&g_CardSlot_CardId + color_mask * 0x120 + card_id * 0x5b20) *
                            0x34) * 0x98) != local_f0)) {
          bVar4 = true;
          strcat(&local_d0,s__subtype_005160f4);
        }
      }
      if (arg_16 != 0xffffffff) {
        uVar2 = arg_16 & 0xfff;
        uVar3 = arg_16 & 0xf000;
        if ((((uVar3 == 0) &&
             ((int)*(short *)(&g_CardSlot_Counters + color_mask * 0x120 + card_id * 0x5b20) != uVar2
             )) || ((uVar3 == 0x1000 &&
                    ((int)*(short *)(&g_CardSlot_Counters + color_mask * 0x120 + card_id * 0x5b20) <
                     (int)uVar2)))) ||
           ((uVar3 == 0x2000 &&
            ((int)uVar2 <
             (int)*(short *)(&g_CardSlot_Counters + color_mask * 0x120 + card_id * 0x5b20))))) {
          bVar4 = true;
          strcat(&local_d0,s__power_00516100);
        }
      }
      if (arg_17 != 0xffffffff) {
        uVar2 = arg_17 & 0xfff;
        uVar3 = arg_17 & 0xf000;
        if ((((uVar3 == 0) &&
             ((int)*(short *)(&DAT_006a5f46 + color_mask * 0x120 + card_id * 0x5b20) != uVar2)) ||
            ((uVar3 == 0x1000 &&
             ((int)*(short *)(&DAT_006a5f46 + color_mask * 0x120 + card_id * 0x5b20) < (int)uVar2)))
            ) || ((uVar3 == 0x2000 &&
                  ((int)uVar2 <
                   (int)*(short *)(&DAT_006a5f46 + color_mask * 0x120 + card_id * 0x5b20))))) {
          bVar4 = true;
          strcat(&local_d0,s__toughness_00516108);
        }
      }
      if (arg_18 != 0) {
        if (((((arg_18 & 1) != 0) &&
             (*(int *)(&DAT_006b3088 +
                      *(int *)(&g_MasterCardTypeTable +
                              *(int *)(&g_CardSlot_CardId + color_mask * 0x120 + card_id * 0x5b20) *
                              0x34) * 0x98) != 0xcc)) &&
            (*(int *)(&g_CardSlot_CardId + color_mask * 0x120 + card_id * 0x5b20) != 0x221)) &&
           ((&DAT_0051aebd)
            [*(int *)(&g_CardSlot_CardId + color_mask * 0x120 + card_id * 0x5b20) * 0x34] != '\0'))
        {
          bVar4 = true;
          strcat(&local_d0,s__walls_00516114);
        }
        if (((arg_18 & 2) != 0) &&
           (((DAT_006b2d3c == -1 || (DAT_006b2d3c != card_id)) ||
            ((DAT_006b2d2c != color_mask ||
             (((&g_CardSlot_Flags)[color_mask * 0x120 + card_id * 0x5b20] & 0x80) != 0)))))) {
          bVar4 = true;
          strcat(&local_d0,s__spell_0051611c);
        }
        if (((arg_18 & 4) != 0) && (iVar1 = FUN_00405edf(card_id,color_mask), iVar1 == 0)) {
          bVar4 = true;
          strcat(&local_d0,s__basicland_00516124);
        }
        if (((arg_18 & 8) != 0) &&
           (((&g_MasterCardColorTable)
             [*(int *)(&g_CardSlot_CardId + color_mask * 0x120 + card_id * 0x5b20) * 0x34] & 0x42)
            != 0x42)) {
          bVar4 = true;
          strcat(&local_d0,s__artifact_creature_00516130);
        }
        if (((arg_18 & 0x20) != 0) &&
           (((char)(&g_CardSlot_Toughness)[color_mask * 0x120 + card_id * 0x5b20] != arg_4 ||
            (*(int *)(&g_CardSlot_OriginalCardId + color_mask * 0x120 + card_id * 0x5b20) != -1))))
        {
          bVar4 = true;
          strcat(&local_d0,s__target_player_00516144);
        }
      }
      if (arg_19 != 0) {
        if (((arg_19 & 1) != 0) &&
           (((&g_CardSlot_Flags)[color_mask * 0x120 + card_id * 0x5b20] & 0x10) == 0)) {
          bVar4 = true;
          strcat(&local_d0,s__tapped_00516154);
        }
        if (((arg_19 & 2) != 0) &&
           (((&g_CardSlot_Flags)[color_mask * 0x120 + card_id * 0x5b20] & 4) == 0)) {
          bVar4 = true;
          strcat(&local_d0,s__attacking_0051615c);
        }
        if (((arg_19 & 4) != 0) &&
           (((&g_CardSlot_Flags)[color_mask * 0x120 + card_id * 0x5b20] & 0x40) == 0)) {
          bVar4 = true;
          strcat(&local_d0,s__attacked_00516168);
        }
        if (((arg_19 & 8) != 0) &&
           (((&DAT_006a5f3d)[color_mask * 0x120 + card_id * 0x5b20] & 2) == 0)) {
          bVar4 = true;
          strcat(&local_d0,s__blocked_00516174);
        }
        if (((arg_19 & 0x10) != 0) &&
           ((card_id == g_DefendingPlayer ||
            ((&g_CardSlot_ColorMask)[color_mask * 0x120 + card_id * 0x5b20] == -1)))) {
          bVar4 = true;
          strcat(&local_d0,s__blocking_00516180);
        }
        if ((arg_19 & 0x20) != 0) {
          bVar5 = false;
          if (((g_ScWillyScore < 0x15) || (0x1d < g_ScWillyScore)) || (card_id == g_DefendingPlayer)
             ) {
            bVar5 = true;
          }
          else if ((card_id == g_DefendingPlayer) ||
                  ((&g_CardSlot_ColorMask)[color_mask * 0x120 + card_id * 0x5b20] == -1)) {
            bVar5 = true;
          }
          if ((((&g_CardSlot_Flags)[color_mask * 0x120 + card_id * 0x5b20] & 4) == 0) && (bVar5)) {
            bVar4 = true;
            strcat(&local_d0,s__attacking_blocking_0051618c);
          }
        }
        if ((arg_19 & 0x40) != 0) {
          bVar5 = false;
          for (local_10c = 0; local_10c < 2; local_10c = local_10c + 1) {
            for (local_110 = 0; local_110 < (int)(&g_PlayerActiveCardCount)[local_10c];
                local_110 = local_110 + 1) {
              if ((((*(int *)(&g_CardSlot_CardId + local_110 * 0x120 + local_10c * 0x5b20) != -1) &&
                   (((&g_MasterCardColorTable)
                     [*(int *)(&g_CardSlot_CardId + local_110 * 0x120 + local_10c * 0x5b20) * 0x34]
                    & 4) != 0)) &&
                  ((char)(&g_CardSlot_Toughness)[local_110 * 0x120 + local_10c * 0x5b20] == card_id)
                  ) && (*(int *)(&g_CardSlot_OriginalCardId + local_110 * 0x120 + local_10c * 0x5b20
                                ) == color_mask)) {
                bVar5 = true;
              }
            }
          }
          if (!bVar5) {
            bVar4 = true;
            strcat(&local_d0,s__enchanted_005161a0);
          }
        }
        if (((arg_19 & 0x80) != 0) &&
           (((&g_CardSlot_Flags)[color_mask * 0x120 + card_id * 0x5b20] & 0x80) == 0)) {
          bVar4 = true;
          strcat(&local_d0,s__casted_005161ac);
        }
        if (((arg_19 & 0x100) != 0) &&
           ((((&g_CardSlot_Flags)[color_mask * 0x120 + card_id * 0x5b20] & 0x80) == 0 ||
            (((&g_CardSlot_Flags)[color_mask * 0x120 + card_id * 0x5b20] & 0x20) != 0)))) {
          bVar4 = true;
          strcat(&local_d0,s__castresolved_005161b4);
        }
        if (((arg_19 & 0x200) != 0) && (iVar1 = FUN_00405277(card_id,color_mask), iVar1 == 0)) {
          bVar4 = true;
          strcat(&local_d0,s__damaged_005161c4);
        }
        if (((arg_19 & 0x400) != 0) &&
           (((&DAT_006a6038)[color_mask * 0x120 + card_id * 0x5b20] & 1) == 0)) {
          bVar4 = true;
          strcat(&local_d0,s__canuntap_005161d0);
        }
        if (((arg_19 & 0x800) != 0) &&
           (((&DAT_006a6038)[color_mask * 0x120 + card_id * 0x5b20] & 2) == 0)) {
          bVar4 = true;
          strcat(&local_d0,s__willuntap_005161dc);
        }
      }
      if (arg_20 != 0) {
        if (((arg_20 & 1) != 0) &&
           (((&g_CardSlot_Flags)[color_mask * 0x120 + card_id * 0x5b20] & 0x10) != 0)) {
          bVar4 = true;
          strcat(&local_d0,s__tapped_005161e8);
        }
        if ((((arg_20 & 2) != 0) || ((arg_20 & 0x20) != 0)) &&
           (((&g_CardSlot_Flags)[color_mask * 0x120 + card_id * 0x5b20] & 4) != 0)) {
          bVar4 = true;
          strcat(&local_d0,s__attacking_005161f0);
        }
        if (((arg_20 & 4) != 0) &&
           (((&g_CardSlot_Flags)[color_mask * 0x120 + card_id * 0x5b20] & 0x40) != 0)) {
          bVar4 = true;
          strcat(&local_d0,s__attacked_005161fc);
        }
        if (((arg_20 & 8) != 0) &&
           (((&DAT_006a5f3d)[color_mask * 0x120 + card_id * 0x5b20] & 2) != 0)) {
          bVar4 = true;
          strcat(&local_d0,s__blocked_00516208);
        }
        if (((((arg_20 & 0x10) != 0) || ((arg_20 & 0x20) != 0)) &&
            ((&g_CardSlot_ColorMask)[color_mask * 0x120 + card_id * 0x5b20] != -1)) &&
           (card_id != g_DefendingPlayer)) {
          bVar4 = true;
          strcat(&local_d0,s__blocking_00516214);
        }
        if ((arg_20 & 0x40) != 0) {
          bVar5 = false;
          for (local_118 = 0; local_118 < 2; local_118 = local_118 + 1) {
            for (local_11c = 0; local_11c < (int)(&g_PlayerActiveCardCount)[local_118];
                local_11c = local_11c + 1) {
              if (((*(int *)(&g_CardSlot_CardId + local_11c * 0x120 + local_118 * 0x5b20) != -1) &&
                  (((&g_MasterCardColorTable)
                    [*(int *)(&g_CardSlot_CardId + local_11c * 0x120 + local_118 * 0x5b20) * 0x34] &
                   4) != 0)) &&
                 (((char)(&g_CardSlot_Toughness)[local_11c * 0x120 + local_118 * 0x5b20] == card_id
                  && (*(int *)(&g_CardSlot_OriginalCardId + local_11c * 0x120 + local_118 * 0x5b20)
                      == color_mask)))) {
                bVar5 = true;
              }
            }
          }
          if (bVar5) {
            bVar4 = true;
            strcat(&local_d0,s__enchanted_00516220);
          }
        }
        if (((arg_20 & 0x80) != 0) &&
           (((&g_CardSlot_Flags)[color_mask * 0x120 + card_id * 0x5b20] & 0x80) != 0)) {
          bVar4 = true;
          strcat(&local_d0,s__casted_0051622c);
        }
        if ((((arg_20 & 0x100) != 0) &&
            (((&g_CardSlot_Flags)[color_mask * 0x120 + card_id * 0x5b20] & 0x80) != 0)) &&
           (((&g_CardSlot_Flags)[color_mask * 0x120 + card_id * 0x5b20] & 0x20) == 0)) {
          bVar4 = true;
          strcat(&local_d0,s__castresolved_00516234);
        }
        if (((arg_20 & 0x200) != 0) && (iVar1 = FUN_00405277(card_id,color_mask), iVar1 != 0)) {
          bVar4 = true;
          strcat(&local_d0,s__damaged_00516244);
        }
        if (((arg_20 & 0x400) != 0) &&
           (((&DAT_006a6038)[color_mask * 0x120 + card_id * 0x5b20] & 1) != 0)) {
          bVar4 = true;
          strcat(&local_d0,s__canuntap_00516250);
        }
        if (((arg_20 & 0x800) != 0) &&
           (((&DAT_006a6038)[color_mask * 0x120 + card_id * 0x5b20] & 2) != 0)) {
          bVar4 = true;
          strcat(&local_d0,s__willuntap_0051625c);
        }
      }
    }
    local_8 = (uint)!bVar4;
    if (str_3 != (char *)0x0) {
      if (local_d0 == '\0') {
        *str_3 = '\0';
      }
      else {
        strcpy(str_3,local_cf);
      }
    }
  }
  else {
    if (str_3 != (char *)0x0) {
      strcpy(str_3,&DAT_0051606c);
    }
    local_8 = 0;
  }
  return local_8;
}

/*
 * Decompiled function: Action_PromptTarget_00405370
 * Entry Point: 00405370
 * Size: 832 bytes
 */


/* WARNING: Removing unreachable block (ram,0x004054e2) */

void Action_PromptTarget_00405370(uint spell_id,undefined4 target_id,int flags)

{
  uint uVar1;
  char cVar2;
  
  g_OverworldWorldState = 0;
  uVar1 = FUN_00474d4a();
  if ((uVar1 != 0xffffffff) &&
     (((uVar1 = uVar1 >> 0x10 & 0xff, uVar1 == 0x71 || (uVar1 == 0x72)) || (uVar1 == 0x7e)))) {
    if (uVar1 == 0x71) {
      strcpy(&g_OverworldWorldState,s_CASTING__00516268);
    }
    if (uVar1 == 0x72) {
      strcpy(&g_OverworldWorldState,s_ACTIVATING__00516274);
    }
    if (uVar1 == 0x7e) {
      strcpy(&g_OverworldWorldState,s_PROCESSING__00516284);
    }
    Ai_Subsystem_004b90de
              (*(int *)(&DAT_006fecb8 + DAT_006a3f78 * 8),*(int *)(&DAT_006fecbc + DAT_006a3f78 * 8)
              );
    strcat(&g_OverworldWorldState,&DAT_00516294);
  }
  if ((flags != 0) && (strcat(&g_OverworldWorldState,s_Pick_a_player_00516298), spell_id != 0)) {
    strcat(&g_OverworldWorldState,&DAT_005162a8);
  }
  if ((spell_id & 1) == 0) {
    if (spell_id != 0) {
      strcat(&g_OverworldWorldState,s_Pick_target_005162bc);
      cVar2 = (spell_id & 1) != 0;
      if ((bool)cVar2) {
        strcat(&g_OverworldWorldState,&DAT_005162d0);
      }
      if ((spell_id & 2) != 0) {
        if ((bool)cVar2) {
          strcat(&g_OverworldWorldState,&DAT_005162d8);
        }
        strcat(&g_OverworldWorldState,s_creature_005162dc);
        cVar2 = cVar2 + '\x01';
      }
      if ((spell_id & 4) != 0) {
        if (cVar2 != '\0') {
          strcat(&g_OverworldWorldState,&DAT_005162e8);
        }
        strcat(&g_OverworldWorldState,s_enchantment_005162ec);
        cVar2 = cVar2 + '\x01';
      }
      if ((spell_id & 0x40) != 0) {
        if (cVar2 != '\0') {
          strcat(&g_OverworldWorldState,&DAT_005162f8);
        }
        strcat(&g_OverworldWorldState,s_artifact_005162fc);
        cVar2 = cVar2 + '\x01';
      }
      if ((spell_id & 0x80) != 0) {
        if (cVar2 != '\0') {
          strcat(&g_OverworldWorldState,&DAT_00516308);
        }
        strcat(&g_OverworldWorldState,s_effect_0051630c);
        cVar2 = cVar2 + '\x01';
      }
      if ((spell_id & 8) != 0) {
        if (cVar2 != '\0') {
          strcat(&g_OverworldWorldState,&DAT_00516314);
        }
        strcat(&g_OverworldWorldState,s_sorcery_00516318);
        cVar2 = cVar2 + '\x01';
      }
      if ((spell_id & 0x10) != 0) {
        if (cVar2 != '\0') {
          strcat(&g_OverworldWorldState,&DAT_00516320);
        }
        strcat(&g_OverworldWorldState,s_instant_00516324);
        cVar2 = cVar2 + '\x01';
      }
      if ((spell_id & 0x20) != 0) {
        if (cVar2 != '\0') {
          strcat(&g_OverworldWorldState,&DAT_0051632c);
        }
        strcat(&g_OverworldWorldState,s_interrupt_00516330);
      }
    }
  }
  else {
    strcat(&g_OverworldWorldState,s_Pick_a_card_005162b0);
  }
  return;
}

/*
 * Decompiled function: Action_ValidateTarget_00405802
 * Entry Point: 00405802
 * Size: 1737 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int Action_ValidateTarget_00405802
              (int spell_id,uint target_id,uint flags,uint arg_4,uint arg_5,uint arg_6,uint arg_7,
              uint arg_8,uint arg_9,uint arg_10,int arg_11,int arg_12,uint arg_13,uint arg_14,
              uint arg_15,uint arg_16,uint arg_17,undefined1 *arg_18,undefined4 arg_19,int *arg_20)

{
  int iVar1;
  size_t sVar2;
  char *local_3bc;
  int local_3b8;
  int local_3b4;
  int local_3b0;
  undefined4 local_3ac;
  char local_3a8 [200];
  char local_2e0 [200];
  int local_218;
  int aiStack_214 [60];
  int local_124;
  int local_120;
  int local_11c;
  int aiStack_118 [60];
  int local_28;
  uint local_24;
  uint local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  if (((spell_id == 1) || (g_IsAiThinking == 1)) || (DAT_006fedc0 != 0)) {
    if ((((byte)DAT_00680790 & 1) != 0) && ((target_id & 2) != 0)) {
      flags = target_id;
    }
    local_28 = spell_id;
    if ((target_id & 2) == 0) {
      local_18 = target_id & 1;
    }
    else {
      local_18 = 0xffffffff;
    }
    if ((flags & 2) == 0) {
      local_20 = flags & 1;
    }
    else {
      local_20 = 0xffffffff;
    }
    local_1c = arg_5;
    local_24 = arg_9;
    if ((arg_4 == 0) || ((arg_4 & 0x1000) != 0)) {
      if ((flags & 2) == 0) {
        if ((flags & 1) == 0) {
          local_8 = 1;
          local_14 = 0;
        }
        else {
          local_8 = 0;
          local_14 = 1;
        }
      }
      else {
        local_8 = 1;
        local_14 = 1;
      }
    }
    else {
      local_8 = 0;
      local_14 = 0;
    }
    if (g_ActivePlayer == 1) {
      local_10 = 0;
    }
    else {
      local_124 = 0;
      for (local_11c = 0; local_11c < 2; local_11c = local_11c + 1) {
        for (local_120 = 0; local_120 < (int)(&g_PlayerActiveCardCount)[local_11c];
            local_120 = local_120 + 1) {
          if ((*(int *)(&g_CardSlot_CardId + local_120 * 0x120 + local_11c * 0x5b20) != -1) &&
             (iVar1 = Rules_ParseFilter_0040360b
                                (local_11c,local_120,(char *)0x0,spell_id,(byte)target_id,
                                 (byte)flags,arg_4,arg_5,arg_6,arg_7,arg_8,arg_9,arg_10,arg_11,
                                 arg_12,arg_13,arg_14,arg_15,arg_16,arg_17), iVar1 != 0)) {
            aiStack_118[local_124] = local_11c;
            aiStack_214[local_124] = local_120;
            local_124 = local_124 + 1;
          }
        }
      }
      if (local_14 != 0) {
        aiStack_118[local_124] = 1;
        aiStack_214[local_124] = -1;
        local_124 = local_124 + 1;
      }
      if (local_8 != 0) {
        aiStack_118[local_124] = 0;
        aiStack_214[local_124] = -1;
        local_124 = local_124 + 1;
      }
      if (local_124 == 0) {
        local_10 = 0;
      }
      else {
        if (g_IsAiThinking == 1) {
          g_AiDecisionScore = FUN_0040a1d2(local_124);
          DAT_006fefa8 = CONCAT31((int3)((aiStack_118[g_AiDecisionScore] == 0) - 1 >> 8),
                                  (char)aiStack_214[g_AiDecisionScore]) & 0x1ff | 0x4000;
          DAT_0052ce1c = 3;
          Ai_EvaluateCreaturePower();
        }
        else {
          DAT_0052ce1c = 3;
          Ai_CalcCardAdvantage();
          if ((g_AiDecisionScore == 99) || (local_124 <= g_AiDecisionScore)) {
            g_AiDecisionScore = FUN_0040a1d2(local_124);
          }
        }
        _DAT_0063ee20 = aiStack_118[g_AiDecisionScore];
        *arg_20 = aiStack_118[g_AiDecisionScore];
        arg_20[1] = aiStack_214[g_AiDecisionScore];
        local_10 = 1;
      }
    }
  }
  else {
    if ((arg_4 == 0) || ((arg_4 & 0x1000) != 0)) {
      if ((target_id & 2) == 0) {
        if ((target_id & 1) == 0) {
          local_8 = 1;
          local_14 = 0;
        }
        else {
          local_8 = 0;
          local_14 = 1;
        }
      }
      else {
        local_8 = 1;
        local_14 = 1;
      }
    }
    else {
      local_8 = 0;
      local_14 = 0;
    }
    local_c = Glue_Subsystem_004d0965();
    local_218 = 1;
    while (local_218 != 0) {
      if (arg_18 == (undefined1 *)0x0) {
        Action_PromptTarget_00405370(arg_5,arg_9,local_14 | local_8);
      }
      DAT_00627a88 = -1;
      if (arg_18 == (undefined1 *)0x0) {
        local_3bc = &g_OverworldWorldState;
      }
      else {
        local_3bc = arg_18;
      }
      local_10 = Ai_Subsystem_004af765
                           (0xffffffff,local_3bc,arg_19,0xffffffff,0xffffffff,0xffffffff,0xffffffff,
                            &local_3b8,&local_3b4,local_14,local_8);
      if (local_10 == 0) {
        if ((local_3b8 != -3) && (local_3b8 == -2)) {
          if ((DAT_00627a84 == -1) && (DAT_00627a88 == -1)) {
            *arg_20 = local_3b4;
            arg_20[1] = local_3b0;
            local_218 = 0;
          }
          else if ((arg_4 & 0x2000) != 0) {
            *arg_20 = -1;
            arg_20[1] = -3;
            local_218 = 0;
          }
        }
      }
      else {
        iVar1 = Rules_ParseFilter_0040360b
                          (local_3b4,local_3b0,local_2e0,spell_id,(byte)target_id,(byte)flags,arg_4,
                           arg_5,arg_6,arg_7,arg_8,arg_9,arg_10,arg_11,arg_12,arg_13,arg_14,arg_15,
                           arg_16,arg_17);
        if (iVar1 == 0) {
          local_3ac = 1;
          sVar2 = strlen(local_2e0);
          if (sVar2 == 0) {
            strcpy(local_3a8,s_Illegal_target__005163a8);
          }
          else {
            sprintf(local_3a8,s_Illegal_target___s___00516390,local_2e0);
          }
          if (g_IsAiThinking != 1) {
            Ai_Util_004cc42d(local_3a8);
            Sleep(2000);
            Ai_Util_004cc42d(&DAT_005163b8);
          }
        }
        else {
          local_3ac = 0;
          *arg_20 = local_3b4;
          arg_20[1] = local_3b0;
          local_218 = 0;
        }
      }
    }
    if (local_c == 0) {
      Glue_Subsystem_004d09bd();
    }
    if (local_10 != 0) {
      DAT_00633434 = 0;
    }
    Ai_Util_004cc42d(&DAT_005163bc);
    strcpy(&g_OverworldGoldAmount,&DAT_005163c0);
  }
  return local_10;
}

/*
 * Decompiled function: Csv_LoadInfo_004060e0
 * Entry Point: 004060e0
 * Size: 728 bytes
 */


void Csv_LoadInfo_004060e0(void)

{
  bool bVar1;
  size_t sVar2;
  int iVar3;
  int iVar4;
  char local_328 [384];
  int local_1a8;
  undefined1 local_1a4 [11];
  char acStack_199 [385];
  char local_18;
  FILE *local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_14 = fopen(s_info_csv_005163c8,&DAT_005163c4);
  bVar1 = false;
  local_18 = '\0';
  local_328[0] = '\0';
  local_10 = 9;
  do {
    local_8 = fscanf(local_14,s______________005163d4,acStack_199 + 1,local_1a4);
    if (local_8 == -1) break;
    if (acStack_199[1] == '0') {
      local_1a8 = atoi(acStack_199 + 1);
      local_328[0] = '\0';
      local_18 = '\0';
    }
    local_18 = local_18 + '\x01';
    if ((local_18 == local_10) && (bVar1)) {
      strcat(local_328,&DAT_005163e4);
    }
    if (acStack_199[1] == '\"') {
      bVar1 = true;
    }
    if (local_18 == local_10) {
      strcat(local_328,acStack_199 + 1);
    }
    sVar2 = strlen(acStack_199 + 1);
    if (acStack_199[sVar2] == '\"') {
      bVar1 = false;
    }
    if (bVar1) {
      local_18 = local_18 + -1;
    }
    if ((local_18 == local_10) && (iVar3 = Pic_Subsystem_0045268f(local_1a8), iVar3 != -1)) {
      if ((*(uint *)(&DAT_0051aed0 + iVar3 * 0x34) & 0x180) != 0) {
        (&DAT_0051aed4)[iVar3 * 0x34] = 4;
      }
      local_c = 1;
      iVar4 = strcmp(local_328,&DAT_005163e8);
      if (iVar4 == 0) {
        local_c = 3;
      }
      iVar4 = strcmp(local_328,s_Uncommon_005163f0);
      if (iVar4 == 0) {
        local_c = 2;
      }
      if ((((&DAT_0051aed1)[iVar3 * 0x34] & 4) != 0) && (local_c < 3)) {
        local_c = local_c + 1;
      }
      (&DAT_0051aed4)[iVar3 * 0x34] = (undefined1)local_c;
      strcpy(&g_OverworldWorldState,s_Swamp_0051aea9 + iVar3 * 0x34);
      strcat(&g_OverworldWorldState,&DAT_005163fc);
      strcat(&g_OverworldWorldState,local_328);
      Surface_FillRect((int *)g_DisplaySurfaceScreen,100,0x80,0x78,8,0);
      FUN_0040c3cc(&g_OverworldWorldState,0xa0,0x81,0xff);
    }
  } while (local_8 != -1);
  fclose(local_14);
  return;
}

/*
 * Decompiled function: Csv_LoadMaster_004063b8
 * Entry Point: 004063b8
 * Size: 320 bytes
 */


void Csv_LoadMaster_004063b8(void)

{
  long lVar1;
  int arg_1;
  int local_214;
  char local_20c [512];
  FILE *local_c;
  char *local_8;
  
  local_c = fopen(s_master_csv_00516404,&DAT_00516400);
  for (local_214 = 0; local_214 < 0x4e2; local_214 = local_214 + 1) {
    *(undefined4 *)(&DAT_00536e78 + local_214 * 4) = 0xffffffff;
  }
  do {
    lVar1 = ftell(local_c);
    local_8 = fgets(local_20c,0x200,local_c);
    if (local_8 == (char *)0x0) break;
    if (local_20c[0] == '0') {
      arg_1 = atoi(local_20c);
      if (((-1 < arg_1) && (arg_1 < 0x4e2)) && (*(int *)(&DAT_00536e78 + arg_1 * 4) == -1)) {
        *(long *)(&DAT_00536e78 + arg_1 * 4) = lVar1;
      }
      Pic_Subsystem_0045268f(arg_1);
    }
  } while (local_8 != (char *)0xffffffff);
  fclose(local_c);
  return;
}

/*
 * Decompiled function: Csv_WriteConcise_004064f8
 * Entry Point: 004064f8
 * Size: 167 bytes
 */


void Csv_WriteConcise_004064f8(void)

{
  FILE *_File;
  int local_14;
  
  _File = fopen(s_concise_csv_00516414,&DAT_00516410);
  for (local_14 = 0; local_14 < g_MasterCardCount; local_14 = local_14 + 1) {
    fprintf(_File,s__d__d__ld_00516420,*(int *)(&g_MasterCardTypeTable + local_14 * 0x34),
            (int)(char)(&DAT_0051aed4)[local_14 * 0x34],
            *(undefined4 *)(&DAT_00536e78 + *(int *)(&g_MasterCardTypeTable + local_14 * 0x34) * 4))
    ;
  }
  fclose(_File);
  return;
}

/*
 * Decompiled function: Csv_ReadConcise_0040659f
 * Entry Point: 0040659f
 * Size: 226 bytes
 */


void Csv_ReadConcise_0040659f(void)

{
  undefined1 local_20 [4];
  undefined1 local_1c [4];
  undefined4 local_18;
  int local_14;
  int local_10;
  FILE *local_c;
  int local_8;
  
  for (local_14 = 0; local_14 < 0x4e2; local_14 = local_14 + 1) {
    *(undefined4 *)(&DAT_00536e78 + local_14 * 4) = 0xffffffff;
  }
  local_c = fopen(s_concise_csv_00516430,&DAT_0051642c);
  local_10 = 0;
  for (local_14 = 0; local_14 < g_MasterCardCount; local_14 = local_14 + 1) {
    local_10 = *(int *)(&g_MasterCardTypeTable + local_14 * 0x34);
    local_8 = fscanf(local_c,s__d__d__ld_0051643c,local_1c,local_20,&local_18);
    (&DAT_0051aed4)[local_14 * 0x34] = local_20[0];
    *(undefined4 *)(&DAT_00536e78 + local_10 * 4) = local_18;
  }
  fclose(local_c);
  return;
}

/*
 * Decompiled function: Csv_SearchMaster_00406681
 * Entry Point: 00406681
 * Size: 441 bytes
 */


void Csv_SearchMaster_00406681(char *filepath,int y,int width,char *str_4)

{
  bool bVar1;
  int iVar2;
  size_t sVar3;
  int local_220;
  undefined1 local_21c [11];
  char acStack_211 [513];
  char local_10;
  FILE *local_c;
  int local_8;
  
  local_c = fopen(str_4,&DAT_00516448);
  bVar1 = false;
  local_10 = '\0';
  *filepath = '\0';
  if ((*(int *)(&DAT_00536e78 + y * 4) != -1) &&
     (iVar2 = strcmp(str_4,s_master_csv_0051644c), iVar2 == 0)) {
    fseek(local_c,*(long *)(&DAT_00536e78 + y * 4),0);
  }
  while (local_8 = fscanf(local_c,s______________00516458,acStack_211 + 1,local_21c), local_8 != 0)
  {
    if (acStack_211[1] == '0') {
      local_220 = atoi(acStack_211 + 1);
    }
    if (local_220 == y) {
      local_10 = local_10 + '\x01';
      if ((local_10 == width) && (bVar1)) {
        strcat(filepath,&DAT_00516468);
      }
      if (acStack_211[1] == '\"') {
        bVar1 = true;
      }
      if (local_10 == width) {
        strcat(filepath,acStack_211 + 1);
      }
      sVar3 = strlen(acStack_211 + 1);
      if (acStack_211[sVar3] == '\"') {
        bVar1 = false;
      }
      if (bVar1) {
        local_10 = local_10 + -1;
      }
    }
    if ((local_8 == -1) || ((local_10 != '\0' && (local_220 != y)))) break;
  }
  fclose(local_c);
  return;
}

/*
 * Decompiled function: Deck_FilterAttributes_00406b4c
 * Entry Point: 00406b4c
 * Size: 1315 bytes
 */


int Deck_FilterAttributes_00406b4c(char *filter_string,int color_mask,uint width,int height)

{
  int *piVar1;
  int iVar2;
  uint local_230;
  uint local_22c;
  int local_220;
  int local_21c;
  int local_218;
  char *local_214;
  int local_210;
  int local_20c;
  uint local_208;
  char local_204;
  char local_203 [499];
  int local_10;
  FILE *local_c;
  int local_8;
  
  strcpy(&DAT_00701830,filter_string);
  local_c = fopen(filter_string,&DAT_00516470);
  if (local_c == (FILE *)0x0) {
    local_10 = 0;
  }
  else {
    local_10 = 0;
    local_218 = 0;
    local_230 = 0;
    local_8 = fscanf(local_c,s_______00516474,&local_204);
    local_8 = fscanf(local_c,&DAT_0051647c,&local_204);
    local_208 = 0;
    local_20c = -1;
    local_22c = 0xffffffff;
    local_210 = 0;
    local_21c = -1;
    local_220 = -1;
    do {
      local_8 = fscanf(local_c,s_______00516484,&local_204);
      if (local_204 == '.') {
        if (local_203[0] == 'v') {
          local_214 = strchr(&local_204,0x20);
          if (local_214 != (char *)0x0) {
            *local_214 = '\0';
          }
          iVar2 = _strcmpi(&local_204,s__vNONE_00516494);
          if (iVar2 == 0) {
            local_208 = 1;
          }
          iVar2 = _strcmpi(&local_204,s__vBLACK_0051649c);
          if (iVar2 == 0) {
            local_208 = 2;
          }
          iVar2 = _strcmpi(&local_204,s__vBLUE_005164a4);
          if (iVar2 == 0) {
            local_208 = 4;
          }
          iVar2 = _strcmpi(&local_204,s__vRED_005164ac);
          if (iVar2 == 0) {
            local_208 = 0x10;
          }
          iVar2 = _strcmpi(&local_204,s__vGREEN_005164b4);
          if (iVar2 == 0) {
            local_208 = 8;
          }
          iVar2 = _strcmpi(&local_204,s__vWHITE_005164bc);
          if (iVar2 == 0) {
            local_208 = 0x20;
          }
          iVar2 = _strcmpi(&local_204,s__vFAST_005164c4);
          if (iVar2 == 0) {
            local_20c = 0;
          }
          iVar2 = _strcmpi(&local_204,s__vLARGE_005164cc);
          if (iVar2 == 0) {
            local_20c = 1;
          }
          iVar2 = _strcmpi(&local_204,s__vDIRECT_005164d4);
          if (iVar2 == 0) {
            local_20c = 2;
          }
          iVar2 = _strcmpi(&local_204,s__vARTIFACT_005164e0);
          if (iVar2 == 0) {
            local_20c = 6;
          }
        }
        else {
          sscanf(local_203,s__d__d_0051648c,&local_220,&local_21c);
          local_210 = local_210 + local_21c;
          if (((local_208 == 0) || ((width & local_208) != 0)) &&
             ((local_20c == -1 || (local_20c == height)))) {
            *(int *)(color_mask + local_230 * 8) = local_220;
            *(int *)(color_mask + 4 + local_230 * 8) = local_21c;
            iVar2 = Pic_Subsystem_0045268f(local_220);
            if (local_21c == 0) {
              local_21c = DAT_0067f380;
            }
            if (iVar2 == -1) {
              if ((local_22c != 0xffffffff) &&
                 (local_21c < *(int *)(color_mask + 4 + local_22c * 8))) {
                piVar1 = (int *)(color_mask + 4 + local_22c * 8);
                *piVar1 = *piVar1 - (int)((local_230 & 1) + local_21c) / 2;
              }
            }
            else if (iVar2 < 5) {
              local_22c = local_230;
            }
          }
        }
        local_230 = local_230 + 1;
      }
      else {
        local_218 = local_218 + 1;
        if (local_218 == 5) {
          local_10 = atoi(local_203);
        }
        else if ((local_218 == 6) && (iVar2 = strcmp(local_203,s_4th_Edition_005164ec), iVar2 != 0))
        {
          local_10 = -2;
        }
      }
      local_8 = fscanf(local_c,&DAT_005164f8,&local_204);
    } while ((((int)local_230 < 0x50) && (local_8 != -1)) && ((local_220 != 0 || (local_21c != 0))))
    ;
    fclose(local_c);
    if (local_210 < 0x28) {
      local_10 = -3;
    }
    if (0x37 < local_10) {
      local_10 = -1;
    }
  }
  return local_10;
}

/*
 * Decompiled function: Hints_Load_004071ce
 * Entry Point: 004071ce
 * Size: 589 bytes
 */


void Hints_Load_004071ce(void)

{
  char *pcVar1;
  long lVar2;
  int local_124;
  char local_120 [8];
  int local_118;
  int local_114;
  undefined4 local_110;
  char local_10c;
  char local_10b [255];
  FILE *local_c;
  int local_8;
  
  local_c = fopen(s_hints_txt_00516548,&DAT_00516544);
  local_118 = 0;
  do {
    local_8 = fscanf(local_c,s_______00516554,&local_10c);
    if (local_10c == '.') {
      sscanf(local_10b,s__d__d__s_0051655c,&local_124,&local_114,local_120);
      *(int *)(&DAT_00701940 + local_118 * 8) = local_124;
      *(int *)(&DAT_00701944 + local_118 * 8) = local_114;
      *(undefined4 *)(&DAT_00701430 + local_118 * 4) = 0;
      pcVar1 = strchr(local_120,0x41);
      if (pcVar1 != (char *)0x0) {
        *(uint *)(&DAT_00701430 + local_118 * 4) = *(uint *)(&DAT_00701430 + local_118 * 4) | 1;
      }
      pcVar1 = strchr(local_120,0x42);
      if (pcVar1 != (char *)0x0) {
        *(uint *)(&DAT_00701430 + local_118 * 4) = *(uint *)(&DAT_00701430 + local_118 * 4) | 2;
      }
      pcVar1 = strchr(local_120,0x43);
      if (pcVar1 != (char *)0x0) {
        *(uint *)(&DAT_00701430 + local_118 * 4) = *(uint *)(&DAT_00701430 + local_118 * 4) | 4;
      }
      pcVar1 = strchr(local_120,0x44);
      if (pcVar1 != (char *)0x0) {
        *(uint *)(&DAT_00701430 + local_118 * 4) = *(uint *)(&DAT_00701430 + local_118 * 4) | 8;
      }
      local_110 = Pic_Subsystem_0045268f(local_124);
      local_110 = Pic_Subsystem_0045268f(local_114);
      local_8 = fscanf(local_c,&DAT_00516568,&local_10c);
      lVar2 = ftell(local_c);
      *(long *)(&DAT_00701030 + local_118 * 4) = lVar2;
      local_118 = local_118 + 1;
    }
    else {
      local_8 = fscanf(local_c,&DAT_00516570,&local_10c);
    }
  } while ((local_118 < 0x100) && (local_8 != -1));
  do {
    *(undefined4 *)(&DAT_00701944 + local_118 * 8) = 0xffffffff;
    *(undefined4 *)(&DAT_00701940 + local_118 * 8) = *(undefined4 *)(&DAT_00701944 + local_118 * 8);
    local_118 = local_118 + 1;
  } while (local_118 < 0x100);
  fclose(local_c);
  return;
}

/*
 * Decompiled function: Hints_GetNext_0040741b
 * Entry Point: 0040741b
 * Size: 126 bytes
 */


void Hints_GetNext_0040741b(int arg_1)

{
  char local_10c [256];
  FILE *local_c;
  int local_8;
  
  local_c = fopen(s_hints_txt_0051657c,&DAT_00516578);
  fseek(local_c,*(long *)(&DAT_00701030 + arg_1 * 4),0);
  local_8 = fscanf(local_c,s_______00516588,local_10c);
  strcat(&g_OverworldWorldState,local_10c);
  fclose(local_c);
  return;
}

/*
 * Decompiled function: Save_ProcessGame_004207a8
 * Entry Point: 004207a8
 * Size: 2576 bytes
 */


int Save_ProcessGame_004207a8(int arg_1)

{
  uint uVar1;
  char cVar2;
  undefined4 uVar3;
  size_t sVar4;
  int iVar5;
  uint uVar6;
  char local_234;
  char local_230 [255];
  char acStack_131 [257];
  int local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  int local_18;
  char *local_10;
  int local_c;
  FILE *local_8;
  
  local_10 = s_magic4_map_0051a438;
  FUN_005112b0(0,(short)DAT_00530d9c);
  FUN_00510b70(1,0,0,s_menopt_pic_0051a444,
               (short *)((int)&DAT_0070a130 + ((DAT_0070a880 == 8) - 1 & 0xff8f5ed1)));
  Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x280,0x1e0,(int *)g_DisplaySurfaceScreen
                     ,0,0,DAT_00522458,DAT_0052245c);
  FUN_005115a0(0,(short)DAT_00530d9c);
  Mem_AllocOrFree_00510e20(1,s_optbox_pic_0051a450);
  Mem_AllocOrFree_0050fc00();
  DAT_005387b8 = (void *)Sprite_EncodeFromSurface(1,1,1,0x40,0x19);
  DAT_005387bc = Sprite_EncodeFromSurface(1,0x42,1,0xe,0xe);
  DAT_005387c0 = Sprite_EncodeFromSurface(1,0x83,1,0xe,0xe);
  DAT_005387c4 = Sprite_EncodeFromSurface(1,1,0x1d,0xe,0xe);
  DAT_005387c8 = Sprite_EncodeFromSurface(1,0x42,0x1d,0xe,0xe);
  DAT_005387cc = Sprite_EncodeFromSurface(1,0x83,0x1d,8,0xb);
  DAT_005387d0 = Sprite_EncodeFromSurface(1,1,0x39,0xb,8);
  DAT_005387d4 = Sprite_EncodeFromSurface(1,0x42,0x39,8,0xb);
  DAT_005387d8 = Sprite_EncodeFromSurface(1,0x83,0x39,0xb,8);
  for (local_18 = 0; local_18 < 2; local_18 = local_18 + 1) {
    for (local_c = 0; local_c < 3; local_c = local_c + 1) {
      uVar3 = Sprite_EncodeFromSurface(1,local_c * 0x41 + 1,local_18 * 0x1c + 0x55,0x1e,0x1b);
      *(undefined4 *)(&DAT_00538818 + local_18 * 0xc + local_c * 4) = uVar3;
    }
  }
  FUN_0050fc20();
  local_28 = 0x1c;
  local_2c = 0x45;
  local_20 = 0x188;
  local_24 = 0x149;
  FUN_0042038c(g_DisplaySurfaceScreen,0x1c,0x45,0x188,0x149);
  strcpy(&g_OverworldWorldState,s_Save_0051a45c + ((arg_1 != 0) - 1 & 8));
  strcat(&g_OverworldWorldState,s_Game_Files_0051a46c);
  local_10[5] = '4';
  local_8 = fopen(s_saveDescs_0051a480,&DAT_0051a47c);
  for (local_c = 0; local_c < 10; local_c = local_c + 1) {
    fgets(&DAT_0067f450 + local_c * 0x40,0x40,local_8);
    sVar4 = strlen(&DAT_0067f450 + local_c * 0x40);
    (&DAT_0067f44f)[local_c * 0x40 + sVar4] = 0;
    cVar2 = FUN_0048c6d0(local_c + 4);
    local_10[5] = cVar2;
    uVar3 = FUN_00406b01(local_10);
    *(undefined4 *)(&DAT_005387e0 + local_c * 4) = uVar3;
    if (*(int *)(&DAT_005387e0 + local_c * 4) == 0) {
      strcpy(&DAT_0067f450 + local_c * 0x40,s__Empty__0051a48c);
    }
    if (arg_1 != 0) {
      *(undefined4 *)(&DAT_005387e0 + local_c * 4) = 1;
    }
  }
  if (DAT_0051a090 == DAT_0051a080) {
    for (local_c = 0; local_c < 10; local_c = local_c + 1) {
      iVar5 = Ai_Util_004c3bc4((&DAT_0051a090)[local_c * 0x15]);
      (&DAT_0051a090)[local_c * 0x15] = iVar5;
      uVar3 = Ai_Util_004c3bc4(*(int *)(&DAT_0051a094 + local_c * 0x54));
      *(undefined4 *)(&DAT_0051a094 + local_c * 0x54) = uVar3;
      uVar3 = Ai_Util_004c3bc4(*(int *)(&DAT_0051a098 + local_c * 0x54));
      *(undefined4 *)(&DAT_0051a098 + local_c * 0x54) = uVar3;
      uVar3 = Ai_Util_004c3bc4(*(int *)(&DAT_0051a09c + local_c * 0x54));
      *(undefined4 *)(&DAT_0051a09c + local_c * 0x54) = uVar3;
    }
  }
LAB_00420bf9:
  local_1c = FUN_0041f354();
  Mem_AllocOrFree_0041f12b(local_1c);
  FUN_0041f17e(0x51a080,0xb - (uint)(arg_1 == 0),local_1c);
  for (local_c = 0; local_c < 10; local_c = local_c + 1) {
    if (*(int *)(&DAT_005387e0 + local_c * 4) == 0) {
      FUN_0041ece4((int)(&DAT_0051a080 + local_c * 0x15));
      FUN_0042024f(local_c,3);
    }
    else {
      FUN_0041ed3a((int)(&DAT_0051a080 + local_c * 0x15));
      FUN_0042024f(local_c,0);
    }
  }
  DAT_005387b0 = -1;
  while (DAT_005387b0 == -1) {
    FUN_0041f3ea(DAT_0067bda4,DAT_0067bda8,DAT_007039c4);
  }
  FUN_0041f391();
  Mem_AllocOrFree_0041f12b(local_1c);
  if (DAT_005387b0 == 0xe) {
    FUN_005112b0(0,(short)DAT_00530d9c);
    return -1;
  }
  if (arg_1 == 0) {
LAB_00421183:
    fclose(local_8);
    Mem_AllocOrFree_0050fc50(DAT_005387b8);
    FUN_005112b0(0,(short)DAT_00530d9c);
    return DAT_005387b0;
  }
  local_30 = DAT_005387b0 + -4;
  strcpy(local_230,&DAT_0067f450 + local_30 * 0x40);
  DAT_00538834 = 1;
  memset(acStack_131 + 1,0,0x100);
  strcpy(acStack_131 + 1,&DAT_0067f450 + local_30 * 0x40);
  iVar5 = strcmp(acStack_131 + 1,s__Empty__0051a494);
  if (iVar5 == 0) {
    acStack_131[1] = 0;
  }
  DAT_00538830 = strlen(acStack_131 + 1);
  FUN_0042024f(local_30,2);
  do {
    uVar6 = FUN_004080b2();
    sVar4 = DAT_00538830;
    if (uVar6 == 0x1c0d) {
      DAT_00538834 = 0;
      fseek(local_8,0,0);
      for (local_c = 0; local_c < 10; local_c = local_c + 1) {
        fprintf(local_8,&DAT_0051a4a0,&DAT_0067f450 + local_c * 0x40);
      }
      goto LAB_00421183;
    }
    if ((int)uVar6 < 0xe09) {
      if (uVar6 == 0xe08) {
        if (DAT_00538830 != 0) {
          DAT_00538830 = DAT_00538830 - 1;
          strcpy(acStack_131 + sVar4,acStack_131 + sVar4 + 1);
        }
      }
      else {
        if (uVar6 == 0x11b) break;
LAB_00420f5c:
        uVar1 = uVar6 & 0xff;
        if ((((0x40 < uVar1) && (uVar1 < 0x5b)) || ((0x60 < uVar1 && (uVar1 < 0x7b)))) ||
           (((0x2f < uVar1 && (uVar1 < 0x3a)) || (uVar1 == 0x20)))) {
          if (DAT_0051a078 != 0) {
            memmove(acStack_131 + DAT_00538830 + 2,acStack_131 + DAT_00538830 + 1,
                    0xff - DAT_00538830);
          }
          local_234 = (char)uVar6;
          acStack_131[DAT_00538830 + 1] = local_234;
          DAT_00538830 = DAT_00538830 + 1;
        }
      }
    }
    else if ((int)uVar6 < 0xf10) {
      if (uVar6 == 0xf0f) {
        DAT_00538830 = DAT_00538830 - 8;
        if ((int)DAT_00538830 < 1) {
          DAT_00538830 = 0;
        }
      }
      else {
        if (uVar6 != 0xf09) goto LAB_00420f5c;
        DAT_00538830 = DAT_00538830 + 8;
      }
    }
    else if ((int)uVar6 < 0x4701) {
      if (uVar6 == 0x4700) {
        DAT_00538830 = 0;
      }
      else if (uVar6 != 0x1c0d) goto LAB_00420f5c;
    }
    else if ((int)uVar6 < 0x4d01) {
      if (uVar6 == 0x4d00) {
        sVar4 = strlen(acStack_131 + 1);
        if (sVar4 == DAT_00538830) {
          strcat(acStack_131 + 1,&DAT_0051a49c);
        }
        DAT_00538830 = DAT_00538830 + 1;
      }
      else {
        if (uVar6 != 0x4b00) goto LAB_00420f5c;
        if (-1 < (int)DAT_00538830) {
          DAT_00538830 = DAT_00538830 - 1;
        }
      }
    }
    else if (uVar6 == 0x4f00) {
      DAT_00538830 = strlen(acStack_131 + 1);
    }
    else if (uVar6 == 0x5200) {
      DAT_0051a078 = DAT_0051a078 ^ 1;
    }
    else {
      if (uVar6 != 0x5300) goto LAB_00420f5c;
      sVar4 = strlen(acStack_131 + 1);
      if ((int)DAT_00538830 < (int)sVar4) {
        strcpy(acStack_131 + DAT_00538830 + 1,acStack_131 + DAT_00538830 + 2);
      }
    }
    strcpy(&DAT_0067f450 + local_30 * 0x40,acStack_131 + 1);
    FUN_0042024f(local_30,2);
  } while( true );
  DAT_00538834 = 0;
  strcpy(&DAT_0067f450 + local_30 * 0x40,local_230);
  goto LAB_00420bf9;
}

/*
 * Decompiled function: Action_PromptTarget_0049239e
 * Entry Point: 0049239e
 * Size: 2323 bytes
 */


void Action_PromptTarget_0049239e(int spell_id)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  undefined4 local_98;
  char local_90 [100];
  int local_2c;
  uint local_28;
  int local_24;
  int local_20;
  uint local_1c;
  int local_18;
  LPVOID local_14;
  uint auStack_10 [3];
  
  local_24 = (int)(char)(&DAT_0067f00c)[spell_id * 0x30];
  FUN_0040b3c2(2,(*(int *)(&DAT_005283a0 + spell_id * 4) + 1) * 7 | 0x80);
  Glue_Subsystem_004ec98e(1,(int)(char)(&DAT_0067f00c)[spell_id * 0x30]);
  LoadPalNoPic(s_advfac64_pic_005286e8);
  Mem_AllocOrFree_00510e20(1,s_tradscrn_pic_005286f8);
  Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x280,0x1e0,(int *)g_DisplaySurfaceScreen
                     ,0,0,DAT_00522458,DAT_0052245c);
  Glue_Sound_004ebeeb(spell_id + 1);
  strcpy(&g_OverworldWorldState,s_You_have_defeated_the_dreaded_00528708);
  pcVar1 = (char *)Mem_AllocOrFree_00473d7e(local_24);
  strcat(&g_OverworldWorldState,pcVar1);
  strcat(&g_OverworldWorldState,s_wizard__No_longer_shall_00528728);
  strcat(&g_OverworldWorldState,
         &DAT_00528744 + ((*(int *)(&DAT_00528384 + local_24 * 4) != 0) - 1 & 8));
  strcat(&g_OverworldWorldState,s_evil_creatures_oppress_00528754);
  strcat(&g_OverworldWorldState,s_the_good_people_of_Shandalar__0052876c);
  for (local_1c = 0; (int)local_1c < 0x80; local_1c = local_1c + 1) {
    if ((*(uint *)(&DAT_0067be00 + local_1c * 100) & 0xff00) == local_24 << 8) {
      *(uint *)(&DAT_0067be00 + local_1c * 100) =
           *(uint *)(&DAT_0067be00 + local_1c * 100) & 0xffff00ff;
      Ai_TownEncounter_004c3b19(local_1c);
      strcat(&g_OverworldWorldState,s_freed__0052878c);
    }
  }
  FUN_0040d469((int)g_DisplaySurfaceScreen,0xfe,0x140,0x72);
  DAT_0067bdb4 = DAT_0067bdb4 | 1 << ((byte)local_24 & 0x1f);
  local_18 = Glue_Subsystem_004f09c0
                       (*(int *)(&DAT_0067f000 + spell_id * 0x30),
                        *(int *)(&DAT_0067f004 + spell_id * 0x30));
  *(undefined4 *)(&DAT_0067bdf0 + local_18 * 100) = 5;
  for (local_1c = 0; (int)local_1c < 8; local_1c = local_1c + 1) {
    if (*(int *)(&DAT_0067f2dc + local_1c * 0x14) == local_24) {
      FUN_0046e70d(local_1c,local_1c + 8);
      *(undefined4 *)(&DAT_0067f2d0 + local_1c * 0x14) = 0xffffffff;
    }
  }
  local_2c = 1;
  strcpy(&g_OverworldWorldState,s_You_may_take_any_three_different_00528798);
  pcVar1 = (char *)Mem_AllocOrFree_00473d7e(local_24);
  strcat(&g_OverworldWorldState,pcVar1);
  strcat(&g_OverworldWorldState,s_cards__005287bc);
  FUN_0040d469((int)g_DisplaySurfaceScreen,0xfe,0x140,200);
  FUN_0040a3e1();
  Ai_Subsystem_004cd1d1();
  PTR_FUN_00527b3c = Mem_AllocOrFree_0040eea2;
  iVar2 = FUN_0041f354();
  Mem_AllocOrFree_0041f12b(iVar2);
  Glue_Subsystem_004ead96(1);
  DAT_0067bdb4 = DAT_0067bdb4 & ~(1 << ((byte)local_24 & 0x1f));
  local_1c = 0;
  do {
    if (2 < (int)local_1c) {
      for (local_1c = 0; (int)local_1c < 3; local_1c = local_1c + 1) {
        *(uint *)(&DAT_0051aed0 + auStack_10[local_1c] * 0x34) =
             *(uint *)(&DAT_0051aed0 + auStack_10[local_1c] * 0x34) & 0xfffffeff;
      }
      FUN_0041f391();
      DAT_0067bdb4 = DAT_0067bdb4 | 1 << ((byte)local_24 & 0x1f);
      PTR_FUN_00527b3c = FUN_0048a3cc;
      if (DAT_0067bdb4 != 0x3e) {
        Pic_Subsystem_00423c82(0x10);
      }
      FUN_005112b0(0,(short)DAT_00530d9c);
      if (DAT_0067bdb4 != 0x3e) {
        return;
      }
      FUN_00501736(0x3c);
      Mem_AllocOrFree_00510de0(1,s_5thwiz_pic_0052880c);
      Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x280,0x1e0,
                         (int *)g_DisplaySurfaceScreen,0,0,DAT_00522458,DAT_0052245c);
      strcpy(&g_OverworldWorldState,s_You_have_defeated_all_five_wizar_00528818);
      strcat(&g_OverworldWorldState,s_Shandalar_is_free__Prepare_to_fa_00528840);
      *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 5;
      FUN_0040d469((int)g_DisplaySurfaceScreen,99,0x140,0x100);
      FUN_0040a3e1();
      Ai_Subsystem_004cd1d1();
      local_20 = FUN_004922dc();
      strcpy(&g_OverworldWorldState,s_Your_battles_so_far_will_banish_t_0052887c);
      iVar2 = local_20;
      if (local_20 < 1) {
        iVar2 = 0;
      }
      pcVar1 = _itoa(iVar2,&DAT_0054aae8,10);
      strcat(&g_OverworldWorldState,pcVar1);
      strcat(&g_OverworldWorldState,s_years__Each_life_it_loses_in_the_005288c0);
      strcat(&g_OverworldWorldState,s_will_banish_it_for_10_additional_005288f0);
      FUN_0040d469((int)g_DisplaySurfaceScreen,99,0x140,0x15e);
      FUN_0040a3e1();
      Ai_Subsystem_004cd1d1();
      FUN_005112b0(0,(short)DAT_00530d9c);
      DeckBuilderMain(_hwndScreen,1,1);
      Pic_Load_advfac64_0040a4fc();
      local_14 = (LPVOID)Glue_Subsystem_004ea97c(0,100);
      (&DAT_00522628)[(int)local_14 * 0x44] =
           (&DAT_00522628)[(int)local_14 * 0x44] * ((char)DAT_0067f380 + '\x01');
      FUN_004909d3((int)local_14,0,0,-1);
      DAT_006b2d64 = local_24;
      DAT_0063ee24 = 0;
      DAT_00695df0 = 3;
      DAT_00627a7c = 0;
      Pic_Subsystem_00423c82(0x10);
      DAT_006b2fe0 = Pic_Subsystem_0045268f(0x11);
      DAT_0068a64c = Pic_Subsystem_0045268f(0x1d);
      Pic_Load_0044ef70(0,local_14);
      FUN_0040b3c2(2,0xb7);
      FUN_005112b0(0,(short)DAT_00530d9c);
      FUN_0050d560(0,0);
      LoadPalNoPic(s_advfac64_pic_00528924);
      FUN_00409e6d(s_mtgend_avi_00528934,(DAT_00522458 + -0x230) / 2,(DAT_0052245c + -0x1a4) / 2,0);
      SetForegroundWindow(_hwndScreen);
      BringWindowToTop(_hwndScreen);
      SetFocus(_hwndScreen);
      LoadPalNoPic(s_advfac64_pic_00528940);
      Catalog_LoadPaletteMap(s_todpal_tr_00528950,(char *)0x0);
      SelectPalette(*(HDC *)(DAT_0070a850 + 4),_hLibPal,0);
      RealizePalette(*(HDC *)(DAT_0070a850 + 4));
      Glue_Sound_004ebeeb(6);
      local_20 = local_20 + (100 - DAT_006a4a04) * 10;
      LoadPalNoPic(s_wingame_pic_0052895c);
      if (DAT_00522458 == 0x280) {
        local_98 = 3;
      }
      else if (DAT_00522458 == 800) {
        local_98 = 4;
      }
      else {
        local_98 = 6;
      }
      FUN_0040adaf(s_wingame_pic_00528968,local_98,local_98);
      strcpy(&g_OverworldWorldState,s_You_have_protected_the_plane_of_S_00528974);
      pcVar1 = _itoa(local_20,&DAT_0054aae8,10);
      strcat(&g_OverworldWorldState,pcVar1);
      strcat(&g_OverworldWorldState,s_years__005289ac);
      strcat(&g_OverworldWorldState,s_The_people_rejoice__Life_is_good_005289b8);
      FUN_0040d4d1((int)g_DisplaySurfaceScreen,0xd8,0x140,0x81);
      FUN_0040a3e1();
      Ai_Subsystem_004cd1d1();
      FUN_005112b0(0,(short)DAT_00530d9c);
      LoadPalNoPic(s_advfac64_pic_005289dc);
      Palette_Subsystem_004a5fdc();
      Castle_Process_00421b32();
      DAT_006fe3f0 = 1;
      FUN_00409db6();
      Palette_Util_00496d20();
                    /* WARNING: Subroutine does not return */
      exit(0xff);
    }
    sprintf(local_90,s_Pick_a_card____d_left_005287c8,3 - local_1c);
    local_28 = Palette_Color_0049716e(local_90,1 << ((byte)local_24 & 0x1f),0xffffffff,local_2c,0);
    if (local_28 == 0xffffffff) {
      local_1c = local_1c + -1;
LAB_004927e6:
      FUN_00501736(0xf);
    }
    else {
      strcpy(&g_OverworldWorldState,s_Will_you_take_this_card____Yes_N_005287e0);
      do {
        iVar2 = Ai_Util_004c3bc4(0x15c);
        iVar2 = iVar2 + 10;
        iVar3 = Ai_Util_004c3bc4(0xf4);
        iVar2 = FUN_00489710(&g_OverworldWorldState,iVar3 + 10,iVar2);
      } while (iVar2 < 0);
      if (iVar2 == 0) {
        local_18 = Pic_Subsystem_00451e40(local_28);
        if (local_18 != -1) {
          *(uint *)(&deck + local_18 * 4) = *(uint *)(&deck + local_18 * 4) | 0x4000;
        }
        auStack_10[local_1c] = local_28;
        *(uint *)(&DAT_0051aed0 + local_28 * 0x34) =
             *(uint *)(&DAT_0051aed0 + local_28 * 0x34) | 0x100;
        goto LAB_004927e6;
      }
      local_1c = local_1c + -1;
    }
    local_1c = local_1c + 1;
  } while( true );
}

/*
 * Decompiled function: DeckBuilderMain
 * Entry Point: 0050ce6c
 * Size: 6 bytes
 */


void DeckBuilderMain(void)

{
                    /* WARNING: Could not recover jumptable at 0x0050ce6c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DeckBuilderMain();
  return;
}


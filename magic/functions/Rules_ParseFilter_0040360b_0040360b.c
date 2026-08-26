/*
 * Decompiled function: Rules_ParseFilter_0040360b
 * Entry Point: 0040360b
 * Size: 7256 bytes
 */
#include "magic.h"


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



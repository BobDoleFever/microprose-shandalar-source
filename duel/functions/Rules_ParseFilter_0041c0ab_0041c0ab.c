/*
 * Decompiled function: Rules_ParseFilter_0041c0ab
 * Entry Point: 0041c0ab
 * Size: 7256 bytes
 */
#include "duel.h"


uint Rules_ParseFilter_0041c0ab
               (int card_id,int color_mask,undefined1 *arg_3,int arg_4,byte arg_5,byte arg_6,
               uint arg_7,uint arg_8,uint arg_9,uint arg_10,uint arg_11,uint arg_12,uint arg_13,
               int arg_14,int arg_15,uint arg_16,uint arg_17,uint arg_18,uint arg_19,uint arg_20)

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
  uint local_cf [49];
  uint local_8;
  
  if (card_id == -1) {
    if (arg_3 != (undefined1 *)0x0) {
      Mem_AllocOrFree_004d9630((uint *)arg_3,(uint *)&DAT_004f2ce4);
    }
    local_8 = 0;
  }
  else if (((card_id == -1) || (color_mask == -1)) ||
          (*(int *)(&DAT_006826c4 + color_mask * 0x120 + card_id * 0x5b20) != -1)) {
    bVar4 = false;
    Mem_AllocOrFree_004d9630((uint *)&local_d0,(uint *)&DAT_004f2cec);
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
        FUN_004d9640((uint *)&local_d0,(uint *)s__player_004f2cf0);
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
      bVar4 = ((&DAT_006826ce)[color_mask * 0x120 + card_id * 0x5b20] & 0x10) != 0;
      if (bVar4) {
        FUN_004d9640((uint *)&local_d0,(uint *)s__can_t_target_this_004f2cf8);
      }
      if ((arg_7 != 0) &&
         (((((&DAT_006826cc)[color_mask * 0x120 + card_id * 0x5b20] & 2) != 0 &&
           ((arg_7 & 0x200) == 0)) ||
          ((((&DAT_006826cc)[color_mask * 0x120 + card_id * 0x5b20] & 2) == 0 &&
           ((arg_7 & 0x100) == 0)))))) {
        bVar4 = true;
        FUN_004d9640((uint *)&local_d0,(uint *)s__where_004f2d0c);
      }
      if ((local_e4 != -1) && (local_e4 != card_id)) {
        bVar4 = true;
        FUN_004d9640((uint *)&local_d0,(uint *)s__controller_004f2d14);
      }
      if ((local_e0 != -1) &&
         (((((&DAT_006826cd)[color_mask * 0x120 + card_id * 0x5b20] & 0x10) != 0 && (local_e0 == 0))
          || ((((&DAT_006826cd)[color_mask * 0x120 + card_id * 0x5b20] & 0x10) == 0 &&
              (local_e0 != 0)))))) {
        bVar4 = true;
        FUN_004d9640((uint *)&local_d0,(uint *)s__owner_004f2d20);
      }
      if (arg_8 != 0) {
        bVar5 = (arg_8 & (byte)(&DAT_004ff594)
                               [*(int *)(&DAT_006826c4 + color_mask * 0x120 + card_id * 0x5b20) *
                                0x34]) != 0;
        if (((arg_8 & 0x80) != 0) &&
           ((*(int *)(&DAT_004ff590 +
                     *(int *)(&DAT_006826c4 + color_mask * 0x120 + card_id * 0x5b20) * 0x34) ==
             DAT_00666444 ||
            (*(int *)(&DAT_004ff590 +
                     *(int *)(&DAT_006826c4 + color_mask * 0x120 + card_id * 0x5b20) * 0x34) ==
             DAT_00666450)))) {
          bVar5 = true;
        }
        if (((arg_8 & 0x1000) != 0) &&
           (((&DAT_006826f8)[color_mask * 0x120 + card_id * 0x5b20] & 0x10) != 0)) {
          bVar5 = true;
        }
        if (((arg_8 & 0x2000) != 0) &&
           (*(int *)(&DAT_004ff590 +
                    *(int *)(&DAT_006826c4 + color_mask * 0x120 + card_id * 0x5b20) * 0x34) ==
            DAT_00666720)) {
          bVar5 = true;
        }
        if (((arg_8 & 0x4000) != 0) &&
           (*(int *)(&DAT_004ff590 +
                    *(int *)(&DAT_006826c4 + color_mask * 0x120 + card_id * 0x5b20) * 0x34) ==
            DAT_0066aae8)) {
          bVar5 = true;
        }
        if (((arg_8 & 0x8000) != 0) &&
           (*(int *)(&DAT_004ff590 +
                    *(int *)(&DAT_006826c4 + color_mask * 0x120 + card_id * 0x5b20) * 0x34) ==
            DAT_0068f108)) {
          bVar5 = true;
        }
        if (!bVar5) {
          bVar4 = true;
          FUN_004d9640((uint *)&local_d0,(uint *)s__type_004f2d28);
        }
      }
      if (arg_9 != 0) {
        bVar5 = (arg_9 & (byte)(&DAT_004ff594)
                               [*(int *)(&DAT_006826c4 + color_mask * 0x120 + card_id * 0x5b20) *
                                0x34]) != 0;
        if (((arg_9 & 0x80) != 0) &&
           ((*(int *)(&DAT_004ff590 +
                     *(int *)(&DAT_006826c4 + color_mask * 0x120 + card_id * 0x5b20) * 0x34) ==
             DAT_00666444 ||
            (*(int *)(&DAT_004ff590 +
                     *(int *)(&DAT_006826c4 + color_mask * 0x120 + card_id * 0x5b20) * 0x34) ==
             DAT_00666450)))) {
          bVar5 = true;
        }
        if (((arg_9 & 0x1000) != 0) &&
           (((&DAT_006826f8)[color_mask * 0x120 + card_id * 0x5b20] & 0x10) != 0)) {
          bVar5 = true;
        }
        if (((arg_9 & 0x2000) != 0) &&
           (*(int *)(&DAT_004ff590 +
                    *(int *)(&DAT_006826c4 + color_mask * 0x120 + card_id * 0x5b20) * 0x34) ==
            DAT_00666720)) {
          bVar5 = true;
        }
        if (((arg_9 & 0x4000) != 0) &&
           (*(int *)(&DAT_004ff590 +
                    *(int *)(&DAT_006826c4 + color_mask * 0x120 + card_id * 0x5b20) * 0x34) ==
            DAT_0066aae8)) {
          bVar5 = true;
        }
        if (((arg_9 & 0x8000) != 0) &&
           (*(int *)(&DAT_004ff590 +
                    *(int *)(&DAT_006826c4 + color_mask * 0x120 + card_id * 0x5b20) * 0x34) ==
            DAT_0068f108)) {
          bVar5 = true;
        }
        if (bVar5) {
          bVar4 = true;
          FUN_004d9640((uint *)&local_d0,(uint *)s__type_004f2d30);
        }
      }
      if ((arg_10 != 0) &&
         ((*(uint *)(&DAT_006826fc + color_mask * 0x120 + card_id * 0x5b20) & arg_10) != arg_10)) {
        bVar4 = true;
        FUN_004d9640((uint *)&local_d0,(uint *)s__abilities_004f2d38);
      }
      if ((arg_11 != 0) &&
         ((arg_11 & *(uint *)(&DAT_006826fc + color_mask * 0x120 + card_id * 0x5b20)) != 0)) {
        bVar4 = true;
        FUN_004d9640((uint *)&local_d0,(uint *)s__abilities_004f2d44);
      }
      if ((arg_12 != 0) &&
         ((arg_12 & (int)(char)(&DAT_006826dd)[color_mask * 0x120 + card_id * 0x5b20]) == 0)) {
        bVar4 = true;
        FUN_004d9640((uint *)&local_d0,(uint *)s__color_004f2d50);
      }
      if ((arg_13 != 0) &&
         ((arg_13 & (int)(char)(&DAT_006826dd)[color_mask * 0x120 + card_id * 0x5b20]) != 0)) {
        bVar4 = true;
        FUN_004d9640((uint *)&local_d0,(uint *)s__color_004f2d58);
      }
      if (arg_14 != -1) {
        if (arg_14 < 5) {
          iVar1 = FUN_0041ea36(*(int *)(&DAT_006826c4 + color_mask * 0x120 + card_id * 0x5b20),
                               arg_14);
          if (iVar1 == 0) {
            bVar4 = true;
            FUN_004d9640((uint *)&local_d0,(uint *)s__card_004f2d60);
          }
        }
        else if (*(int *)(&DAT_006826c4 + color_mask * 0x120 + card_id * 0x5b20) != arg_14) {
          bVar4 = true;
          FUN_004d9640((uint *)&local_d0,(uint *)s__card_004f2d68);
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
        if ((*(int *)(&DAT_00618ad8 +
                     *(int *)(&DAT_004ff590 +
                             *(int *)(&DAT_006826c4 + color_mask * 0x120 + card_id * 0x5b20) * 0x34)
                     * 0x98) != arg_15) &&
           (*(int *)(&DAT_00618ad8 +
                    *(int *)(&DAT_004ff590 +
                            *(int *)(&DAT_006826c4 + color_mask * 0x120 + card_id * 0x5b20) * 0x34)
                    * 0x98) != local_f0)) {
          bVar4 = true;
          FUN_004d9640((uint *)&local_d0,(uint *)s__subtype_004f2d70);
        }
      }
      if (arg_16 != 0xffffffff) {
        uVar2 = arg_16 & 0xfff;
        uVar3 = arg_16 & 0xf000;
        if ((((uVar3 == 0) &&
             ((int)*(short *)(&DAT_006826d4 + color_mask * 0x120 + card_id * 0x5b20) != uVar2)) ||
            ((uVar3 == 0x1000 &&
             ((int)*(short *)(&DAT_006826d4 + color_mask * 0x120 + card_id * 0x5b20) < (int)uVar2)))
            ) || ((uVar3 == 0x2000 &&
                  ((int)uVar2 <
                   (int)*(short *)(&DAT_006826d4 + color_mask * 0x120 + card_id * 0x5b20))))) {
          bVar4 = true;
          FUN_004d9640((uint *)&local_d0,(uint *)s__power_004f2d7c);
        }
      }
      if (arg_17 != 0xffffffff) {
        uVar2 = arg_17 & 0xfff;
        uVar3 = arg_17 & 0xf000;
        if ((((uVar3 == 0) &&
             ((int)*(short *)(&DAT_006826d6 + color_mask * 0x120 + card_id * 0x5b20) != uVar2)) ||
            ((uVar3 == 0x1000 &&
             ((int)*(short *)(&DAT_006826d6 + color_mask * 0x120 + card_id * 0x5b20) < (int)uVar2)))
            ) || ((uVar3 == 0x2000 &&
                  ((int)uVar2 <
                   (int)*(short *)(&DAT_006826d6 + color_mask * 0x120 + card_id * 0x5b20))))) {
          bVar4 = true;
          FUN_004d9640((uint *)&local_d0,(uint *)s__toughness_004f2d84);
        }
      }
      if (arg_18 != 0) {
        if (((((arg_18 & 1) != 0) &&
             (*(int *)(&DAT_00618ad8 +
                      *(int *)(&DAT_004ff590 +
                              *(int *)(&DAT_006826c4 + color_mask * 0x120 + card_id * 0x5b20) * 0x34
                              ) * 0x98) != 0xcc)) &&
            (*(int *)(&DAT_006826c4 + color_mask * 0x120 + card_id * 0x5b20) != 0x221)) &&
           ((&DAT_004ff595)[*(int *)(&DAT_006826c4 + color_mask * 0x120 + card_id * 0x5b20) * 0x34]
            != '\0')) {
          bVar4 = true;
          FUN_004d9640((uint *)&local_d0,(uint *)s__walls_004f2d90);
        }
        if (((arg_18 & 2) != 0) &&
           (((DAT_0068ecd0 == -1 || (DAT_0068ecd0 != card_id)) ||
            ((DAT_0068eccc != color_mask ||
             (((&DAT_006826cc)[color_mask * 0x120 + card_id * 0x5b20] & 0x80) != 0)))))) {
          bVar4 = true;
          FUN_004d9640((uint *)&local_d0,(uint *)s__spell_004f2d98);
        }
        if (((arg_18 & 4) != 0) && (iVar1 = FUN_0041e97e(card_id,color_mask), iVar1 == 0)) {
          bVar4 = true;
          FUN_004d9640((uint *)&local_d0,(uint *)s__basicland_004f2da0);
        }
        if (((arg_18 & 8) != 0) &&
           (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + color_mask * 0x120 + card_id * 0x5b20) * 0x34]
            & 0x42) != 0x42)) {
          bVar4 = true;
          FUN_004d9640((uint *)&local_d0,(uint *)s__artifact_creature_004f2dac);
        }
        if (((arg_18 & 0x20) != 0) &&
           (((char)(&DAT_006826d2)[color_mask * 0x120 + card_id * 0x5b20] != arg_4 ||
            (*(int *)(&DAT_006826e8 + color_mask * 0x120 + card_id * 0x5b20) != -1)))) {
          bVar4 = true;
          FUN_004d9640((uint *)&local_d0,(uint *)s__target_player_004f2dc0);
        }
      }
      if (arg_19 != 0) {
        if (((arg_19 & 1) != 0) &&
           (((&DAT_006826cc)[color_mask * 0x120 + card_id * 0x5b20] & 0x10) == 0)) {
          bVar4 = true;
          FUN_004d9640((uint *)&local_d0,(uint *)s__tapped_004f2dd0);
        }
        if (((arg_19 & 2) != 0) &&
           (((&DAT_006826cc)[color_mask * 0x120 + card_id * 0x5b20] & 4) == 0)) {
          bVar4 = true;
          FUN_004d9640((uint *)&local_d0,(uint *)s__attacking_004f2dd8);
        }
        if (((arg_19 & 4) != 0) &&
           (((&DAT_006826cc)[color_mask * 0x120 + card_id * 0x5b20] & 0x40) == 0)) {
          bVar4 = true;
          FUN_004d9640((uint *)&local_d0,(uint *)s__attacked_004f2de4);
        }
        if (((arg_19 & 8) != 0) &&
           (((&DAT_006826cd)[color_mask * 0x120 + card_id * 0x5b20] & 2) == 0)) {
          bVar4 = true;
          FUN_004d9640((uint *)&local_d0,(uint *)s__blocked_004f2df0);
        }
        if (((arg_19 & 0x10) != 0) &&
           ((card_id == DAT_00666458 ||
            ((&DAT_006826de)[color_mask * 0x120 + card_id * 0x5b20] == -1)))) {
          bVar4 = true;
          FUN_004d9640((uint *)&local_d0,(uint *)s__blocking_004f2dfc);
        }
        if ((arg_19 & 0x20) != 0) {
          bVar5 = false;
          if (((DAT_0068f2c4 < 0x15) || (0x1d < DAT_0068f2c4)) || (card_id == DAT_00666458)) {
            bVar5 = true;
          }
          else if ((card_id == DAT_00666458) ||
                  ((&DAT_006826de)[color_mask * 0x120 + card_id * 0x5b20] == -1)) {
            bVar5 = true;
          }
          if ((((&DAT_006826cc)[color_mask * 0x120 + card_id * 0x5b20] & 4) == 0) && (bVar5)) {
            bVar4 = true;
            FUN_004d9640((uint *)&local_d0,(uint *)s__attacking_blocking_004f2e08);
          }
        }
        if ((arg_19 & 0x40) != 0) {
          bVar5 = false;
          for (local_10c = 0; local_10c < 2; local_10c = local_10c + 1) {
            for (local_110 = 0; local_110 < (int)(&DAT_00666408)[local_10c];
                local_110 = local_110 + 1) {
              if ((((*(int *)(&DAT_006826c4 + local_10c * 0x5b20 + local_110 * 0x120) != -1) &&
                   (((&DAT_004ff594)
                     [*(int *)(&DAT_006826c4 + local_10c * 0x5b20 + local_110 * 0x120) * 0x34] & 4)
                    != 0)) &&
                  ((char)(&DAT_006826d2)[local_10c * 0x5b20 + local_110 * 0x120] == card_id)) &&
                 (*(int *)(&DAT_006826e8 + local_10c * 0x5b20 + local_110 * 0x120) == color_mask)) {
                bVar5 = true;
              }
            }
          }
          if (!bVar5) {
            bVar4 = true;
            FUN_004d9640((uint *)&local_d0,(uint *)s__enchanted_004f2e1c);
          }
        }
        if (((arg_19 & 0x80) != 0) &&
           (((&DAT_006826cc)[color_mask * 0x120 + card_id * 0x5b20] & 0x80) == 0)) {
          bVar4 = true;
          FUN_004d9640((uint *)&local_d0,(uint *)s__casted_004f2e28);
        }
        if (((arg_19 & 0x100) != 0) &&
           ((((&DAT_006826cc)[color_mask * 0x120 + card_id * 0x5b20] & 0x80) == 0 ||
            (((&DAT_006826cc)[color_mask * 0x120 + card_id * 0x5b20] & 0x20) != 0)))) {
          bVar4 = true;
          FUN_004d9640((uint *)&local_d0,(uint *)s__castresolved_004f2e30);
        }
        if (((arg_19 & 0x200) != 0) && (iVar1 = FUN_0041dd17(card_id,color_mask), iVar1 == 0)) {
          bVar4 = true;
          FUN_004d9640((uint *)&local_d0,(uint *)s__damaged_004f2e40);
        }
        if (((arg_19 & 0x400) != 0) &&
           (((&DAT_006827c8)[color_mask * 0x120 + card_id * 0x5b20] & 1) == 0)) {
          bVar4 = true;
          FUN_004d9640((uint *)&local_d0,(uint *)s__canuntap_004f2e4c);
        }
        if (((arg_19 & 0x800) != 0) &&
           (((&DAT_006827c8)[color_mask * 0x120 + card_id * 0x5b20] & 2) == 0)) {
          bVar4 = true;
          FUN_004d9640((uint *)&local_d0,(uint *)s__willuntap_004f2e58);
        }
      }
      if (arg_20 != 0) {
        if (((arg_20 & 1) != 0) &&
           (((&DAT_006826cc)[color_mask * 0x120 + card_id * 0x5b20] & 0x10) != 0)) {
          bVar4 = true;
          FUN_004d9640((uint *)&local_d0,(uint *)s__tapped_004f2e64);
        }
        if ((((arg_20 & 2) != 0) || ((arg_20 & 0x20) != 0)) &&
           (((&DAT_006826cc)[color_mask * 0x120 + card_id * 0x5b20] & 4) != 0)) {
          bVar4 = true;
          FUN_004d9640((uint *)&local_d0,(uint *)s__attacking_004f2e6c);
        }
        if (((arg_20 & 4) != 0) &&
           (((&DAT_006826cc)[color_mask * 0x120 + card_id * 0x5b20] & 0x40) != 0)) {
          bVar4 = true;
          FUN_004d9640((uint *)&local_d0,(uint *)s__attacked_004f2e78);
        }
        if (((arg_20 & 8) != 0) &&
           (((&DAT_006826cd)[color_mask * 0x120 + card_id * 0x5b20] & 2) != 0)) {
          bVar4 = true;
          FUN_004d9640((uint *)&local_d0,(uint *)s__blocked_004f2e84);
        }
        if (((((arg_20 & 0x10) != 0) || ((arg_20 & 0x20) != 0)) &&
            ((&DAT_006826de)[color_mask * 0x120 + card_id * 0x5b20] != -1)) &&
           (card_id != DAT_00666458)) {
          bVar4 = true;
          FUN_004d9640((uint *)&local_d0,(uint *)s__blocking_004f2e90);
        }
        if ((arg_20 & 0x40) != 0) {
          bVar5 = false;
          for (local_118 = 0; local_118 < 2; local_118 = local_118 + 1) {
            for (local_11c = 0; local_11c < (int)(&DAT_00666408)[local_118];
                local_11c = local_11c + 1) {
              if (((*(int *)(&DAT_006826c4 + local_11c * 0x120 + local_118 * 0x5b20) != -1) &&
                  (((&DAT_004ff594)
                    [*(int *)(&DAT_006826c4 + local_11c * 0x120 + local_118 * 0x5b20) * 0x34] & 4)
                   != 0)) &&
                 (((char)(&DAT_006826d2)[local_11c * 0x120 + local_118 * 0x5b20] == card_id &&
                  (*(int *)(&DAT_006826e8 + local_11c * 0x120 + local_118 * 0x5b20) == color_mask)))
                 ) {
                bVar5 = true;
              }
            }
          }
          if (bVar5) {
            bVar4 = true;
            FUN_004d9640((uint *)&local_d0,(uint *)s__enchanted_004f2e9c);
          }
        }
        if (((arg_20 & 0x80) != 0) &&
           (((&DAT_006826cc)[color_mask * 0x120 + card_id * 0x5b20] & 0x80) != 0)) {
          bVar4 = true;
          FUN_004d9640((uint *)&local_d0,(uint *)s__casted_004f2ea8);
        }
        if ((((arg_20 & 0x100) != 0) &&
            (((&DAT_006826cc)[color_mask * 0x120 + card_id * 0x5b20] & 0x80) != 0)) &&
           (((&DAT_006826cc)[color_mask * 0x120 + card_id * 0x5b20] & 0x20) == 0)) {
          bVar4 = true;
          FUN_004d9640((uint *)&local_d0,(uint *)s__castresolved_004f2eb0);
        }
        if (((arg_20 & 0x200) != 0) && (iVar1 = FUN_0041dd17(card_id,color_mask), iVar1 != 0)) {
          bVar4 = true;
          FUN_004d9640((uint *)&local_d0,(uint *)s__damaged_004f2ec0);
        }
        if (((arg_20 & 0x400) != 0) &&
           (((&DAT_006827c8)[color_mask * 0x120 + card_id * 0x5b20] & 1) != 0)) {
          bVar4 = true;
          FUN_004d9640((uint *)&local_d0,(uint *)s__canuntap_004f2ecc);
        }
        if (((arg_20 & 0x800) != 0) &&
           (((&DAT_006827c8)[color_mask * 0x120 + card_id * 0x5b20] & 2) != 0)) {
          bVar4 = true;
          FUN_004d9640((uint *)&local_d0,(uint *)s__willuntap_004f2ed8);
        }
      }
    }
    local_8 = (uint)!bVar4;
    if (arg_3 != (undefined1 *)0x0) {
      if (local_d0 == '\0') {
        *arg_3 = 0;
      }
      else {
        Mem_AllocOrFree_004d9630((uint *)arg_3,local_cf);
      }
    }
  }
  else {
    if (arg_3 != (undefined1 *)0x0) {
      Mem_AllocOrFree_004d9630((uint *)arg_3,(uint *)&DAT_004f2ce8);
    }
    local_8 = 0;
  }
  return local_8;
}



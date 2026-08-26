/*
 * Decompiled function: FUN_0041c0ab
 * Entry Point: 0041c0ab
 * Size: 7256 bytes
 */
#include "duel.h"


uint FUN_0041c0ab(int param_1,int param_2,undefined1 *param_3,int param_4,byte param_5,byte param_6,
                 uint param_7,uint param_8,uint param_9,uint param_10,uint param_11,uint param_12,
                 uint param_13,int param_14,int param_15,uint param_16,uint param_17,uint param_18,
                 uint param_19,uint param_20)

{
  int iVar1;
  uint uVar2;
  bool bVar3;
  bool bVar4;
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
  undefined1 local_cf [199];
  uint local_8;
  
  if (param_1 == -1) {
    if (param_3 != (undefined1 *)0x0) {
      FUN_004d9630(param_3,&DAT_004f2ce4);
    }
    local_8 = 0;
  }
  else if (((param_1 == -1) || (param_2 == -1)) ||
          (*(int *)(&DAT_006826c4 + param_2 * 0x120 + param_1 * 0x5b20) != -1)) {
    bVar3 = false;
    FUN_004d9630(&local_d0,&DAT_004f2cec);
    if (param_2 == -1) {
      if ((param_7 == 0) || ((param_7 & 0x1000) != 0)) {
        if (((param_4 == 0) && ((param_5 & 2) != 0)) || ((param_4 == 1 && ((param_6 & 2) != 0)))) {
          local_d8 = 1;
          local_dc = 1;
        }
        else if (((param_4 == 0) && ((param_5 & 1) != 0)) ||
                ((param_4 == 1 && ((param_6 & 1) != 0)))) {
          local_d8 = 0;
          local_dc = 1;
        }
      }
      else {
        local_d8 = 0;
        local_dc = 0;
      }
      if (((param_1 == 0) && (local_d8 == 0)) || ((param_1 == 1 && (local_dc == 0)))) {
        bVar3 = true;
        FUN_004d9640(&local_d0,s__player_004f2cf0);
      }
    }
    else {
      if (param_4 == 0) {
        if ((param_5 & 4) == 0) {
          if ((param_5 & 2) == 0) {
            if ((param_5 & 1) == 0) {
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
          if ((param_5 & 2) == 0) {
            if ((param_5 & 1) == 0) {
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
      else if ((param_6 & 4) == 0) {
        if ((param_6 & 2) == 0) {
          if ((param_6 & 1) == 0) {
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
        if ((param_6 & 2) == 0) {
          if ((param_6 & 1) == 0) {
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
      bVar3 = ((&DAT_006826ce)[param_2 * 0x120 + param_1 * 0x5b20] & 0x10) != 0;
      if (bVar3) {
        FUN_004d9640(&local_d0,s__can_t_target_this_004f2cf8);
      }
      if ((param_7 != 0) &&
         (((((&DAT_006826cc)[param_2 * 0x120 + param_1 * 0x5b20] & 2) != 0 &&
           ((param_7 & 0x200) == 0)) ||
          ((((&DAT_006826cc)[param_2 * 0x120 + param_1 * 0x5b20] & 2) == 0 &&
           ((param_7 & 0x100) == 0)))))) {
        bVar3 = true;
        FUN_004d9640(&local_d0,s__where_004f2d0c);
      }
      if ((local_e4 != -1) && (local_e4 != param_1)) {
        bVar3 = true;
        FUN_004d9640(&local_d0,s__controller_004f2d14);
      }
      if ((local_e0 != -1) &&
         (((((&DAT_006826cd)[param_2 * 0x120 + param_1 * 0x5b20] & 0x10) != 0 && (local_e0 == 0)) ||
          ((((&DAT_006826cd)[param_2 * 0x120 + param_1 * 0x5b20] & 0x10) == 0 && (local_e0 != 0)))))
         ) {
        bVar3 = true;
        FUN_004d9640(&local_d0,s__owner_004f2d20);
      }
      if (param_8 != 0) {
        bVar4 = (param_8 &
                (byte)(&DAT_004ff594)
                      [*(int *)(&DAT_006826c4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x34]) != 0;
        if (((param_8 & 0x80) != 0) &&
           ((*(int *)(&DAT_004ff590 +
                     *(int *)(&DAT_006826c4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x34) ==
             DAT_00666444 ||
            (*(int *)(&DAT_004ff590 +
                     *(int *)(&DAT_006826c4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x34) ==
             DAT_00666450)))) {
          bVar4 = true;
        }
        if (((param_8 & 0x1000) != 0) &&
           (((&DAT_006826f8)[param_2 * 0x120 + param_1 * 0x5b20] & 0x10) != 0)) {
          bVar4 = true;
        }
        if (((param_8 & 0x2000) != 0) &&
           (*(int *)(&DAT_004ff590 +
                    *(int *)(&DAT_006826c4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x34) ==
            DAT_00666720)) {
          bVar4 = true;
        }
        if (((param_8 & 0x4000) != 0) &&
           (*(int *)(&DAT_004ff590 +
                    *(int *)(&DAT_006826c4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x34) ==
            DAT_0066aae8)) {
          bVar4 = true;
        }
        if (((param_8 & 0x8000) != 0) &&
           (*(int *)(&DAT_004ff590 +
                    *(int *)(&DAT_006826c4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x34) ==
            DAT_0068f108)) {
          bVar4 = true;
        }
        if (!bVar4) {
          bVar3 = true;
          FUN_004d9640(&local_d0,s__type_004f2d28);
        }
      }
      if (param_9 != 0) {
        bVar4 = (param_9 &
                (byte)(&DAT_004ff594)
                      [*(int *)(&DAT_006826c4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x34]) != 0;
        if (((param_9 & 0x80) != 0) &&
           ((*(int *)(&DAT_004ff590 +
                     *(int *)(&DAT_006826c4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x34) ==
             DAT_00666444 ||
            (*(int *)(&DAT_004ff590 +
                     *(int *)(&DAT_006826c4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x34) ==
             DAT_00666450)))) {
          bVar4 = true;
        }
        if (((param_9 & 0x1000) != 0) &&
           (((&DAT_006826f8)[param_2 * 0x120 + param_1 * 0x5b20] & 0x10) != 0)) {
          bVar4 = true;
        }
        if (((param_9 & 0x2000) != 0) &&
           (*(int *)(&DAT_004ff590 +
                    *(int *)(&DAT_006826c4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x34) ==
            DAT_00666720)) {
          bVar4 = true;
        }
        if (((param_9 & 0x4000) != 0) &&
           (*(int *)(&DAT_004ff590 +
                    *(int *)(&DAT_006826c4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x34) ==
            DAT_0066aae8)) {
          bVar4 = true;
        }
        if (((param_9 & 0x8000) != 0) &&
           (*(int *)(&DAT_004ff590 +
                    *(int *)(&DAT_006826c4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x34) ==
            DAT_0068f108)) {
          bVar4 = true;
        }
        if (bVar4) {
          bVar3 = true;
          FUN_004d9640(&local_d0,s__type_004f2d30);
        }
      }
      if ((param_10 != 0) &&
         ((*(uint *)(&DAT_006826fc + param_2 * 0x120 + param_1 * 0x5b20) & param_10) != param_10)) {
        bVar3 = true;
        FUN_004d9640(&local_d0,s__abilities_004f2d38);
      }
      if ((param_11 != 0) &&
         ((param_11 & *(uint *)(&DAT_006826fc + param_2 * 0x120 + param_1 * 0x5b20)) != 0)) {
        bVar3 = true;
        FUN_004d9640(&local_d0,s__abilities_004f2d44);
      }
      if ((param_12 != 0) &&
         ((param_12 & (int)(char)(&DAT_006826dd)[param_2 * 0x120 + param_1 * 0x5b20]) == 0)) {
        bVar3 = true;
        FUN_004d9640(&local_d0,s__color_004f2d50);
      }
      if ((param_13 != 0) &&
         ((param_13 & (int)(char)(&DAT_006826dd)[param_2 * 0x120 + param_1 * 0x5b20]) != 0)) {
        bVar3 = true;
        FUN_004d9640(&local_d0,s__color_004f2d58);
      }
      if (param_14 != -1) {
        if (param_14 < 5) {
          iVar1 = FUN_0041ea36(*(undefined4 *)(&DAT_006826c4 + param_2 * 0x120 + param_1 * 0x5b20),
                               param_14);
          if (iVar1 == 0) {
            bVar3 = true;
            FUN_004d9640(&local_d0,s__card_004f2d60);
          }
        }
        else if (*(int *)(&DAT_006826c4 + param_2 * 0x120 + param_1 * 0x5b20) != param_14) {
          bVar3 = true;
          FUN_004d9640(&local_d0,s__card_004f2d68);
        }
      }
      if (param_15 != -1) {
        if ((param_18 & 0x10) == 0) {
          local_f0 = param_15;
        }
        else if (param_15 == 8) {
          local_f0 = 9;
        }
        else if (param_15 == 9) {
          local_f0 = 8;
        }
        else if (param_15 == 0x11) {
          local_f0 = 0x12;
        }
        else if (param_15 == 0x12) {
          local_f0 = 0x11;
        }
        else if (param_15 == 0x4a) {
          local_f0 = 0x4b;
        }
        else if (param_15 == 0x4b) {
          local_f0 = 0x4a;
        }
        else if (param_15 == 0x57) {
          local_f0 = 0x58;
        }
        else if (param_15 == 0x58) {
          local_f0 = 0x57;
        }
        else if (param_15 == 0x5a) {
          local_f0 = 0x5b;
        }
        else if (param_15 == 0x5b) {
          local_f0 = 0x5a;
        }
        else if (param_15 == 0x6a) {
          local_f0 = 0x6b;
        }
        else if (param_15 == 0x6b) {
          local_f0 = 0x6a;
        }
        else if (param_15 == 0x94) {
          local_f0 = 0x95;
        }
        else if (param_15 == 0x95) {
          local_f0 = 0x94;
        }
        else {
          local_f0 = param_15;
        }
        if ((*(int *)(&DAT_00618ad8 +
                     *(int *)(&DAT_004ff590 +
                             *(int *)(&DAT_006826c4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x34) *
                     0x98) != param_15) &&
           (*(int *)(&DAT_00618ad8 +
                    *(int *)(&DAT_004ff590 +
                            *(int *)(&DAT_006826c4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x34) *
                    0x98) != local_f0)) {
          bVar3 = true;
          FUN_004d9640(&local_d0,s__subtype_004f2d70);
        }
      }
      if (param_16 != 0xffffffff) {
        uVar2 = param_16 & 0xfff;
        param_16 = param_16 & 0xf000;
        if ((((param_16 == 0) &&
             ((int)*(short *)(&DAT_006826d4 + param_2 * 0x120 + param_1 * 0x5b20) != uVar2)) ||
            ((param_16 == 0x1000 &&
             ((int)*(short *)(&DAT_006826d4 + param_2 * 0x120 + param_1 * 0x5b20) < (int)uVar2))))
           || ((param_16 == 0x2000 &&
               ((int)uVar2 < (int)*(short *)(&DAT_006826d4 + param_2 * 0x120 + param_1 * 0x5b20)))))
        {
          bVar3 = true;
          FUN_004d9640(&local_d0,s__power_004f2d7c);
        }
      }
      if (param_17 != 0xffffffff) {
        uVar2 = param_17 & 0xfff;
        param_17 = param_17 & 0xf000;
        if ((((param_17 == 0) &&
             ((int)*(short *)(&DAT_006826d6 + param_2 * 0x120 + param_1 * 0x5b20) != uVar2)) ||
            ((param_17 == 0x1000 &&
             ((int)*(short *)(&DAT_006826d6 + param_2 * 0x120 + param_1 * 0x5b20) < (int)uVar2))))
           || ((param_17 == 0x2000 &&
               ((int)uVar2 < (int)*(short *)(&DAT_006826d6 + param_2 * 0x120 + param_1 * 0x5b20)))))
        {
          bVar3 = true;
          FUN_004d9640(&local_d0,s__toughness_004f2d84);
        }
      }
      if (param_18 != 0) {
        if (((((param_18 & 1) != 0) &&
             (*(int *)(&DAT_00618ad8 +
                      *(int *)(&DAT_004ff590 +
                              *(int *)(&DAT_006826c4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x34) *
                      0x98) != 0xcc)) &&
            (*(int *)(&DAT_006826c4 + param_2 * 0x120 + param_1 * 0x5b20) != 0x221)) &&
           ((&DAT_004ff595)[*(int *)(&DAT_006826c4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x34] !=
            '\0')) {
          bVar3 = true;
          FUN_004d9640(&local_d0,s__walls_004f2d90);
        }
        if (((param_18 & 2) != 0) &&
           (((DAT_0068ecd0 == -1 || (DAT_0068ecd0 != param_1)) ||
            ((DAT_0068eccc != param_2 ||
             (((&DAT_006826cc)[param_2 * 0x120 + param_1 * 0x5b20] & 0x80) != 0)))))) {
          bVar3 = true;
          FUN_004d9640(&local_d0,s__spell_004f2d98);
        }
        if (((param_18 & 4) != 0) && (iVar1 = FUN_0041e97e(param_1,param_2), iVar1 == 0)) {
          bVar3 = true;
          FUN_004d9640(&local_d0,s__basicland_004f2da0);
        }
        if (((param_18 & 8) != 0) &&
           (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x34] &
            0x42) != 0x42)) {
          bVar3 = true;
          FUN_004d9640(&local_d0,s__artifact_creature_004f2dac);
        }
        if (((param_18 & 0x20) != 0) &&
           (((char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20] != param_4 ||
            (*(int *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20) != -1)))) {
          bVar3 = true;
          FUN_004d9640(&local_d0,s__target_player_004f2dc0);
        }
      }
      if (param_19 != 0) {
        if (((param_19 & 1) != 0) &&
           (((&DAT_006826cc)[param_2 * 0x120 + param_1 * 0x5b20] & 0x10) == 0)) {
          bVar3 = true;
          FUN_004d9640(&local_d0,s__tapped_004f2dd0);
        }
        if (((param_19 & 2) != 0) &&
           (((&DAT_006826cc)[param_2 * 0x120 + param_1 * 0x5b20] & 4) == 0)) {
          bVar3 = true;
          FUN_004d9640(&local_d0,s__attacking_004f2dd8);
        }
        if (((param_19 & 4) != 0) &&
           (((&DAT_006826cc)[param_2 * 0x120 + param_1 * 0x5b20] & 0x40) == 0)) {
          bVar3 = true;
          FUN_004d9640(&local_d0,s__attacked_004f2de4);
        }
        if (((param_19 & 8) != 0) &&
           (((&DAT_006826cd)[param_2 * 0x120 + param_1 * 0x5b20] & 2) == 0)) {
          bVar3 = true;
          FUN_004d9640(&local_d0,s__blocked_004f2df0);
        }
        if (((param_19 & 0x10) != 0) &&
           ((param_1 == DAT_00666458 || ((&DAT_006826de)[param_2 * 0x120 + param_1 * 0x5b20] == -1))
           )) {
          bVar3 = true;
          FUN_004d9640(&local_d0,s__blocking_004f2dfc);
        }
        if ((param_19 & 0x20) != 0) {
          bVar4 = false;
          if (((DAT_0068f2c4 < 0x15) || (0x1d < DAT_0068f2c4)) || (param_1 == DAT_00666458)) {
            bVar4 = true;
          }
          else if ((param_1 == DAT_00666458) ||
                  ((&DAT_006826de)[param_2 * 0x120 + param_1 * 0x5b20] == -1)) {
            bVar4 = true;
          }
          if ((((&DAT_006826cc)[param_2 * 0x120 + param_1 * 0x5b20] & 4) == 0) && (bVar4)) {
            bVar3 = true;
            FUN_004d9640(&local_d0,s__attacking_blocking_004f2e08);
          }
        }
        if ((param_19 & 0x40) != 0) {
          bVar4 = false;
          for (local_10c = 0; local_10c < 2; local_10c = local_10c + 1) {
            for (local_110 = 0; local_110 < (int)(&DAT_00666408)[local_10c];
                local_110 = local_110 + 1) {
              if ((((*(int *)(&DAT_006826c4 + local_10c * 0x5b20 + local_110 * 0x120) != -1) &&
                   (((&DAT_004ff594)
                     [*(int *)(&DAT_006826c4 + local_10c * 0x5b20 + local_110 * 0x120) * 0x34] & 4)
                    != 0)) &&
                  ((char)(&DAT_006826d2)[local_10c * 0x5b20 + local_110 * 0x120] == param_1)) &&
                 (*(int *)(&DAT_006826e8 + local_10c * 0x5b20 + local_110 * 0x120) == param_2)) {
                bVar4 = true;
              }
            }
          }
          if (!bVar4) {
            bVar3 = true;
            FUN_004d9640(&local_d0,s__enchanted_004f2e1c);
          }
        }
        if (((param_19 & 0x80) != 0) &&
           (((&DAT_006826cc)[param_2 * 0x120 + param_1 * 0x5b20] & 0x80) == 0)) {
          bVar3 = true;
          FUN_004d9640(&local_d0,s__casted_004f2e28);
        }
        if (((param_19 & 0x100) != 0) &&
           ((((&DAT_006826cc)[param_2 * 0x120 + param_1 * 0x5b20] & 0x80) == 0 ||
            (((&DAT_006826cc)[param_2 * 0x120 + param_1 * 0x5b20] & 0x20) != 0)))) {
          bVar3 = true;
          FUN_004d9640(&local_d0,s__castresolved_004f2e30);
        }
        if (((param_19 & 0x200) != 0) && (iVar1 = FUN_0041dd17(param_1,param_2), iVar1 == 0)) {
          bVar3 = true;
          FUN_004d9640(&local_d0,s__damaged_004f2e40);
        }
        if (((param_19 & 0x400) != 0) &&
           (((&DAT_006827c8)[param_2 * 0x120 + param_1 * 0x5b20] & 1) == 0)) {
          bVar3 = true;
          FUN_004d9640(&local_d0,s__canuntap_004f2e4c);
        }
        if (((param_19 & 0x800) != 0) &&
           (((&DAT_006827c8)[param_2 * 0x120 + param_1 * 0x5b20] & 2) == 0)) {
          bVar3 = true;
          FUN_004d9640(&local_d0,s__willuntap_004f2e58);
        }
      }
      if (param_20 != 0) {
        if (((param_20 & 1) != 0) &&
           (((&DAT_006826cc)[param_2 * 0x120 + param_1 * 0x5b20] & 0x10) != 0)) {
          bVar3 = true;
          FUN_004d9640(&local_d0,s__tapped_004f2e64);
        }
        if ((((param_20 & 2) != 0) || ((param_20 & 0x20) != 0)) &&
           (((&DAT_006826cc)[param_2 * 0x120 + param_1 * 0x5b20] & 4) != 0)) {
          bVar3 = true;
          FUN_004d9640(&local_d0,s__attacking_004f2e6c);
        }
        if (((param_20 & 4) != 0) &&
           (((&DAT_006826cc)[param_2 * 0x120 + param_1 * 0x5b20] & 0x40) != 0)) {
          bVar3 = true;
          FUN_004d9640(&local_d0,s__attacked_004f2e78);
        }
        if (((param_20 & 8) != 0) &&
           (((&DAT_006826cd)[param_2 * 0x120 + param_1 * 0x5b20] & 2) != 0)) {
          bVar3 = true;
          FUN_004d9640(&local_d0,s__blocked_004f2e84);
        }
        if (((((param_20 & 0x10) != 0) || ((param_20 & 0x20) != 0)) &&
            ((&DAT_006826de)[param_2 * 0x120 + param_1 * 0x5b20] != -1)) &&
           (param_1 != DAT_00666458)) {
          bVar3 = true;
          FUN_004d9640(&local_d0,s__blocking_004f2e90);
        }
        if ((param_20 & 0x40) != 0) {
          bVar4 = false;
          for (local_118 = 0; local_118 < 2; local_118 = local_118 + 1) {
            for (local_11c = 0; local_11c < (int)(&DAT_00666408)[local_118];
                local_11c = local_11c + 1) {
              if (((*(int *)(&DAT_006826c4 + local_11c * 0x120 + local_118 * 0x5b20) != -1) &&
                  (((&DAT_004ff594)
                    [*(int *)(&DAT_006826c4 + local_11c * 0x120 + local_118 * 0x5b20) * 0x34] & 4)
                   != 0)) &&
                 (((char)(&DAT_006826d2)[local_11c * 0x120 + local_118 * 0x5b20] == param_1 &&
                  (*(int *)(&DAT_006826e8 + local_11c * 0x120 + local_118 * 0x5b20) == param_2)))) {
                bVar4 = true;
              }
            }
          }
          if (bVar4) {
            bVar3 = true;
            FUN_004d9640(&local_d0,s__enchanted_004f2e9c);
          }
        }
        if (((param_20 & 0x80) != 0) &&
           (((&DAT_006826cc)[param_2 * 0x120 + param_1 * 0x5b20] & 0x80) != 0)) {
          bVar3 = true;
          FUN_004d9640(&local_d0,s__casted_004f2ea8);
        }
        if ((((param_20 & 0x100) != 0) &&
            (((&DAT_006826cc)[param_2 * 0x120 + param_1 * 0x5b20] & 0x80) != 0)) &&
           (((&DAT_006826cc)[param_2 * 0x120 + param_1 * 0x5b20] & 0x20) == 0)) {
          bVar3 = true;
          FUN_004d9640(&local_d0,s__castresolved_004f2eb0);
        }
        if (((param_20 & 0x200) != 0) && (iVar1 = FUN_0041dd17(param_1,param_2), iVar1 != 0)) {
          bVar3 = true;
          FUN_004d9640(&local_d0,s__damaged_004f2ec0);
        }
        if (((param_20 & 0x400) != 0) &&
           (((&DAT_006827c8)[param_2 * 0x120 + param_1 * 0x5b20] & 1) != 0)) {
          bVar3 = true;
          FUN_004d9640(&local_d0,s__canuntap_004f2ecc);
        }
        if (((param_20 & 0x800) != 0) &&
           (((&DAT_006827c8)[param_2 * 0x120 + param_1 * 0x5b20] & 2) != 0)) {
          bVar3 = true;
          FUN_004d9640(&local_d0,s__willuntap_004f2ed8);
        }
      }
    }
    local_8 = (uint)!bVar3;
    if (param_3 != (undefined1 *)0x0) {
      if (local_d0 == '\0') {
        *param_3 = 0;
      }
      else {
        FUN_004d9630(param_3,local_cf);
      }
    }
  }
  else {
    if (param_3 != (undefined1 *)0x0) {
      FUN_004d9630(param_3,&DAT_004f2ce8);
    }
    local_8 = 0;
  }
  return local_8;
}



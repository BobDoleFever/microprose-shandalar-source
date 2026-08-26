/*
 * Decompiled function: Glue_Subsystem_004dba1c
 * Entry Point: 0045d1b7
 * Size: 1469 bytes
 */
#include "duel.h"


undefined4 Glue_Subsystem_004dba1c(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 arg_11;
  int iVar6;
  undefined4 arg_12;
  uint uVar7;
  undefined4 arg_13;
  uint uVar8;
  undefined4 arg_14;
  uint uVar9;
  undefined4 arg_15;
  uint uVar10;
  undefined4 arg_16;
  uint uVar11;
  undefined4 arg_17;
  undefined *arg_18;
  undefined4 arg_18_00;
  undefined4 arg_19;
  int *arg_20;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (flags == 0x73) {
    uVar1 = 0;
    if ((*(uint *)(&DAT_006826cc + spell_id * 0x5b20 + target_id * 0x120) & 0x20010) == 0) {
      arg_19 = 0;
      arg_18_00 = 0;
      arg_17 = 0;
      arg_16 = 0xffffffff;
      arg_15 = 0xffffffff;
      arg_14 = 0xffffffff;
      arg_13 = 0xffffffff;
      arg_12 = 0;
      arg_11 = 0;
      uVar1 = FUN_004521e2(spell_id,target_id);
      uVar1 = FUN_0041bcf0((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uVar1,arg_11,arg_12,arg_13,arg_14,
                           arg_15,arg_16,arg_17,arg_18_00,arg_19);
    }
  }
  else if (flags == 0x90) {
    FUN_0043071d(0);
    uVar1 = 0;
  }
  else {
    if ((flags == 0x6d) &&
       ((*(uint *)(&DAT_006826cc + spell_id * 0x5b20 + target_id * 0x120) & 0x20010) == 0)) {
      FUN_00434660(s_prompts_txt_004f8a90,s_SORCERESS_QUEEN_004f8a80);
      *(uint *)(&DAT_006826cc + spell_id * 0x5b20 + target_id * 0x120) =
           *(uint *)(&DAT_006826cc + spell_id * 0x5b20 + target_id * 0x120) | 0x100000;
      FUN_00451482(0,0x20);
      arg_20 = &local_14;
      uVar1 = 1;
      arg_18 = &DAT_006679f0;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
      iVar6 = -1;
      iVar5 = -1;
      uVar4 = 0;
      uVar3 = 0;
      uVar2 = FUN_004521e2(spell_id,target_id);
      iVar5 = Action_ValidateTarget_0041e2a2
                        (spell_id,2,1 - spell_id,0x200,2,0,0,uVar2,uVar3,uVar4,iVar5,iVar6,uVar7,
                         uVar8,uVar9,uVar10,uVar11,arg_18,uVar1,arg_20);
      if (iVar5 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        *(int *)(&DAT_00682718 + spell_id * 0x5b20 + target_id * 0x120) = local_14;
        *(int *)(&DAT_0068271c + spell_id * 0x5b20 + target_id * 0x120) = local_10;
        (&DAT_006827b8)[spell_id * 0x5b20 + target_id * 0x120] = 1;
        *(uint *)(&DAT_006826cc + spell_id * 0x5b20 + target_id * 0x120) =
             *(uint *)(&DAT_006826cc + spell_id * 0x5b20 + target_id * 0x120) | 0x10;
      }
      *(uint *)(&DAT_006826cc + spell_id * 0x5b20 + target_id * 0x120) =
           *(uint *)(&DAT_006826cc + spell_id * 0x5b20 + target_id * 0x120) & 0xffefffff;
    }
    if (flags == 0x72) {
      local_14 = *(int *)(&DAT_00682718 + spell_id * 0x5b20 + target_id * 0x120);
      local_10 = *(int *)(&DAT_0068271c + spell_id * 0x5b20 + target_id * 0x120);
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
      iVar6 = -1;
      iVar5 = -1;
      uVar4 = 0;
      uVar3 = 0;
      uVar2 = FUN_004521e2(spell_id,target_id);
      iVar5 = Rules_ParseFilter_0041c0ab
                        (local_14,local_10,(undefined1 *)0x0,spell_id,2,2,0x200,2,0,0,uVar2,uVar3,
                         uVar4,iVar5,iVar6,uVar7,uVar8,uVar9,uVar10,uVar11);
      if (iVar5 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
          for (local_c = 0; local_c < (int)(&DAT_00666408)[local_8]; local_c = local_c + 1) {
            if ((((*(int *)(&DAT_006826c4 + local_c * 0x120 + local_8 * 0x5b20) == DAT_0068eed0) &&
                 (((&DAT_006826cc)[local_c * 0x120 + local_8 * 0x5b20] & 2) != 0)) &&
                ((char)(&DAT_006826d2)[local_c * 0x120 + local_8 * 0x5b20] == local_14)) &&
               (*(int *)(&DAT_006826e8 + local_c * 0x120 + local_8 * 0x5b20) == local_10)) {
              *(uint *)(&DAT_006826f8 + local_c * 0x120 + local_8 * 0x5b20) =
                   *(uint *)(&DAT_006826f8 + local_c * 0x120 + local_8 * 0x5b20) & 0xfeffffff;
            }
          }
        }
        iVar5 = FUN_004a2b00(DAT_00690af0,DAT_0068efa0,DAT_0068eed0,local_14,local_10);
        if (iVar5 != -1) {
          *(uint *)(&DAT_006826f8 + iVar5 * 0x120 + spell_id * 0x5b20) =
               *(uint *)(&DAT_006826f8 + iVar5 * 0x120 + spell_id * 0x5b20) | 0x1000000;
          *(ushort *)(&DAT_006826d8 + iVar5 * 0x120 + spell_id * 0x5b20) =
               -(*(ushort *)
                  (&DAT_004ff59a +
                  *(int *)(&DAT_006826c4 + local_14 * 0x5b20 + local_10 * 0x120) * 0x34) & 0xbfff);
          *(ushort *)(&DAT_006826da + iVar5 * 0x120 + spell_id * 0x5b20) =
               2 - (*(ushort *)
                     (&DAT_004ff59c +
                     *(int *)(&DAT_006826c4 + local_14 * 0x5b20 + local_10 * 0x120) * 0x34) & 0xbfff
                   );
        }
      }
      (&DAT_006827b8)
      [*(int *)(&DAT_006827b0 + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20 +
       *(int *)(&DAT_006827b4 + spell_id * 0x5b20 + target_id * 0x120) * 0x120] = 0;
    }
    if (((flags == 0x8a) && (target_id == DAT_00690c48)) && (spell_id == DAT_0068ecb0)) {
      DAT_0069340c = DAT_0069340c + 0xc;
    }
    if (((flags == 0x8b) && (target_id == DAT_00690c48)) && (spell_id == DAT_0068ecb0)) {
      DAT_0069340c = DAT_0069340c + -0xc;
    }
    uVar1 = 0;
  }
  return uVar1;
}



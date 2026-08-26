/*
 * Decompiled function: Prompts_Load_00402fea
 * Entry Point: 00402fea
 * Size: 1851 bytes
 */
#include "duel.h"


undefined4 Prompts_Load_00402fea(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
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
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (flags == 0x74) {
    arg_19 = 0;
    arg_18_00 = 0;
    arg_17 = 0;
    arg_16 = 0xffffffff;
    arg_15 = 0xffffffff;
    arg_14 = 0xffffffff;
    arg_13 = 3;
    arg_12 = 0;
    arg_11 = 0;
    uVar1 = FUN_004521e2(spell_id,target_id);
    FUN_0041bcf0((int *)(-(uint)(DAT_0068f100 == 0) & 0x68ed04),0,spell_id,2,2,0x200,0,0,0,uVar1,
                 arg_11,arg_12,arg_13,arg_14,arg_15,arg_16,arg_17,arg_18_00,arg_19);
    if ((spell_id == DAT_00676504) &&
       ((DAT_0068ed04 == 0 || (iVar2 = FUN_0049b309(spell_id,7,4), iVar2 == 0)))) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
    return uVar1;
  }
  if (((flags == 0x6c) && (DAT_00690c48 == target_id)) && (DAT_0068ecb0 == spell_id)) {
    iVar2 = FUN_00404a71(spell_id,*(int *)(&DAT_006826c4 + spell_id * 0x5b20 + target_id * 0x120));
    DAT_0068f2d4 = DAT_0068f2d4 - (int)(0x24 / (longlong)iVar2);
    (&DAT_006827b8)[spell_id * 0x5b20 + target_id * 0x120] = 0;
    local_18 = 0;
    local_10 = 0;
    while (((local_18 < DAT_00681ea0 && (local_10 == 0)) && (DAT_00681ea4 != 1))) {
      local_14 = FUN_004af74c(spell_id,target_id,4);
      local_14 = local_14 + -1;
      FUN_00434660(s_prompts_txt_004f2160,s_VOLCANIC_ERUPTION_004f214c);
      _sprintf(&DAT_006679f0,&DAT_006679f0,local_18 + 1,DAT_00681ea0);
      if (local_14 == 4) {
        FUN_004718de(&DAT_006679f0,s_mountain_004f2174,0,s_PLAINS_004f216c);
      }
      else if (local_14 == 0) {
        FUN_004718de(&DAT_006679f0,s_mountain_004f2188,0,s_SWAMP_004f2180);
      }
      else if (local_14 == 1) {
        FUN_004718de(&DAT_006679f0,s_mountain_004f219c,0,s_ISLAND_004f2194);
      }
      else if (local_14 == 2) {
        FUN_004718de(&DAT_006679f0,s_mountain_004f21b0,0,s_FOREST_004f21a8);
      }
      arg_20 = &local_20;
      uVar1 = 1;
      arg_18 = &DAT_006679f0;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
      iVar6 = -1;
      uVar5 = 0;
      uVar4 = 0;
      iVar2 = local_14;
      uVar3 = FUN_004521e2(spell_id,target_id);
      iVar2 = Action_ValidateTarget_0041e2a2
                        (spell_id,2,1 - spell_id,0x200,0,0,0,uVar3,uVar4,uVar5,iVar2,iVar6,uVar7,
                         uVar8,uVar9,uVar10,uVar11,arg_18,uVar1,arg_20);
      if (iVar2 == 0) {
        if (local_1c == -1) {
          DAT_00681ea4 = 1;
        }
        else {
          local_10 = 1;
        }
      }
      else {
        *(uint *)(&DAT_006826cc + local_20 * 0x5b20 + local_1c * 0x120) =
             *(uint *)(&DAT_006826cc + local_20 * 0x5b20 + local_1c * 0x120) | 0x300000;
        FUN_00451482(0,0x20);
        *(int *)(&DAT_00682718 +
                spell_id * 0x5b20 +
                target_id * 0x120 + (char)(&DAT_006827b8)[spell_id * 0x5b20 + target_id * 0x120] * 8
                ) = local_20;
        *(int *)(&DAT_0068271c +
                spell_id * 0x5b20 +
                target_id * 0x120 + (char)(&DAT_006827b8)[spell_id * 0x5b20 + target_id * 0x120] * 8
                ) = local_1c;
        (&DAT_006827b8)[spell_id * 0x5b20 + target_id * 0x120] =
             (&DAT_006827b8)[spell_id * 0x5b20 + target_id * 0x120] + '\x01';
      }
      local_18 = local_18 + 1;
    }
    for (local_18 = 0; local_18 < (char)(&DAT_006827b8)[spell_id * 0x5b20 + target_id * 0x120];
        local_18 = local_18 + 1) {
      *(uint *)(&DAT_006826cc +
               *(int *)(&DAT_0068271c + local_18 * 8 + target_id * 0x120 + spell_id * 0x5b20) *
               0x120 + *(int *)(&DAT_00682718 + local_18 * 8 + target_id * 0x120 + spell_id * 0x5b20
                               ) * 0x5b20) =
           *(uint *)(&DAT_006826cc +
                    *(int *)(&DAT_0068271c + local_18 * 8 + target_id * 0x120 + spell_id * 0x5b20) *
                    0x120 + *(int *)(&DAT_00682718 +
                                    local_18 * 8 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20)
           & 0xffcfffff;
    }
    if (DAT_00681ea4 == 1) {
      (&DAT_006827b8)[spell_id * 0x5b20 + target_id * 0x120] = 0;
    }
  }
  if (flags == 0x71) {
    local_14 = FUN_004af74c(spell_id,target_id,4);
    local_14 = local_14 + -1;
    local_8 = 0;
    for (local_18 = 0; local_18 < (char)(&DAT_006827b8)[spell_id * 0x5b20 + target_id * 0x120];
        local_18 = local_18 + 1) {
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
      iVar6 = -1;
      uVar5 = 0;
      uVar4 = 0;
      iVar2 = local_14;
      uVar3 = FUN_004521e2(spell_id,target_id);
      iVar2 = Rules_ParseFilter_0041c0ab
                        (*(int *)(&DAT_00682718 +
                                 local_18 * 8 + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&DAT_0068271c +
                                 local_18 * 8 + target_id * 0x120 + spell_id * 0x5b20),
                         (undefined1 *)0x0,spell_id,2,2,0x200,0,0,0,uVar3,uVar4,uVar5,iVar2,iVar6,
                         uVar7,uVar8,uVar9,uVar10,uVar11);
      if (iVar2 == 0) {
        local_8 = local_8 + 1;
      }
      else {
        FUN_0046e571(*(int *)(&DAT_00682718 + local_18 * 8 + target_id * 0x120 + spell_id * 0x5b20),
                     *(int *)(&DAT_0068271c + local_18 * 8 + target_id * 0x120 + spell_id * 0x5b20),
                     2);
      }
    }
    if ((char)(&DAT_006827b8)[spell_id * 0x5b20 + target_id * 0x120] == local_8) {
      DAT_00681ea4 = 1;
    }
    if ((DAT_00681ea4 != 1) && (local_c = FUN_004d695b(spell_id,DAT_0068f2d0), local_c != -1)) {
      *(undefined4 *)(&DAT_006826c0 + local_c * 0x120 + spell_id * 0x5b20) =
           *(undefined4 *)(&DAT_006826c4 + spell_id * 0x5b20 + target_id * 0x120);
      *(uint *)(&DAT_006826cc + local_c * 0x120 + spell_id * 0x5b20) =
           *(uint *)(&DAT_006826cc + local_c * 0x120 + spell_id * 0x5b20) | 2;
      *(undefined4 *)(&DAT_00682704 + local_c * 0x120 + spell_id * 0x5b20) = 0x109;
      *(int *)(&DAT_006826e4 + local_c * 0x120 + spell_id * 0x5b20) =
           (char)(&DAT_006827b8)[spell_id * 0x5b20 + target_id * 0x120] - local_8;
      FUN_0048eb25(spell_id,local_c);
    }
    (&DAT_006827b8)[spell_id * 0x5b20 + target_id * 0x120] = 0;
    FUN_0046e571(spell_id,target_id,1);
  }
  return 0;
}



/*
 * Decompiled function: Palette_Color_0049ae00
 * Entry Point: 004aa5bf
 * Size: 1231 bytes
 */
#include "duel.h"


undefined4 Palette_Color_0049ae00(int spell_id,int target_id,int flags)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  undefined4 arg_11;
  uint uVar5;
  undefined4 arg_12;
  uint uVar6;
  undefined4 arg_13;
  undefined4 arg_14;
  int iVar7;
  undefined4 arg_15;
  uint uVar8;
  undefined4 arg_16;
  uint uVar9;
  undefined4 arg_17;
  undefined *arg_18;
  uint uVar10;
  undefined4 arg_18_00;
  uint uVar11;
  undefined4 arg_19;
  int *arg_20;
  uint uVar12;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (flags == 0x74) {
    if (DAT_0068ecd0 == -1) {
      FUN_0043071d(0);
      arg_19 = 0;
      arg_18_00 = 0;
      arg_17 = 0;
      arg_16 = 0xffffffff;
      arg_15 = 0xffffffff;
      arg_14 = 0xffffffff;
      arg_13 = 0xffffffff;
      arg_12 = 0;
      arg_11 = 0;
      uVar2 = FUN_004521e2(spell_id,target_id);
      uVar2 = FUN_0041bcf0((int *)0x0,0,spell_id,2,2,0x200,0xff,0,0,uVar2,arg_11,arg_12,arg_13,
                           arg_14,arg_15,arg_16,arg_17,arg_18_00,arg_19);
    }
    else if (((spell_id == DAT_00676510) ||
             ((spell_id == DAT_00676504 && (DAT_00666458 == DAT_00676510)))) &&
            (iVar3 = Rules_ParseFilter_0041c0ab
                               (DAT_0068ecd0,DAT_0068eccc,(undefined1 *)0x0,spell_id,2,2,0,0xff,0,0,
                                0,0,0,-1,-1,0xffffffff,0xffffffff,2,0,0), iVar3 != 0)) {
      uVar2 = 99;
    }
    else {
      uVar2 = 0;
    }
  }
  else {
    if (((flags == 0x6c) && (DAT_00690c48 == target_id)) && (DAT_0068ecb0 == spell_id)) {
      DAT_0068f2d4 = DAT_0068f2d4 + -0x18;
      if (DAT_0068ecd0 == -1) {
        FUN_00434660(s_prompts_txt_00506368,s_ANY_LACE_0050635c);
        arg_20 = &local_14;
        uVar2 = 1;
        arg_18 = &DAT_006679f0;
        uVar12 = 0;
        uVar11 = 0;
        uVar10 = 0;
        uVar9 = 0xffffffff;
        uVar8 = 0xffffffff;
        iVar7 = -1;
        iVar3 = -1;
        uVar6 = 0;
        uVar5 = 0;
        uVar4 = FUN_004521e2(spell_id,target_id);
        iVar3 = Action_ValidateTarget_0041e2a2
                          (spell_id,2,2,0x200,0xff,0,0,uVar4,uVar5,uVar6,iVar3,iVar7,uVar8,uVar9,
                           uVar10,uVar11,uVar12,arg_18,uVar2,arg_20);
        if (iVar3 == 0) {
          DAT_00681ea4 = 1;
        }
        else {
          *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20) = local_14;
          *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20) = local_10;
          (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        }
      }
      else {
        *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20) = DAT_0068ecd0;
        *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20) = DAT_0068eccc;
        (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 1;
      }
    }
    if (flags == 0x71) {
      local_8 = 0;
      if (DAT_0068ecd0 == -1) {
        uVar12 = 0;
        uVar11 = 0;
        uVar10 = 0;
        uVar9 = 0xffffffff;
        uVar8 = 0xffffffff;
        iVar7 = -1;
        iVar3 = -1;
        uVar6 = 0;
        uVar5 = 0;
        uVar4 = FUN_004521e2(spell_id,target_id);
        iVar3 = Rules_ParseFilter_0041c0ab
                          (*(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20),
                           *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20),
                           (undefined1 *)0x0,spell_id,2,2,0x200,0xff,0,0,uVar4,uVar5,uVar6,iVar3,
                           iVar7,uVar8,uVar9,uVar10,uVar11,uVar12);
        if (iVar3 != 0) {
          local_8 = local_8 + 1;
        }
      }
      else {
        iVar3 = Rules_ParseFilter_0041c0ab
                          (*(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20),
                           *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20),
                           (undefined1 *)0x0,spell_id,2,2,0,0xff,0,0,0,0,0,-1,-1,0xffffffff,
                           0xffffffff,2,0,0);
        if (iVar3 != 0) {
          local_8 = local_8 + 1;
        }
      }
      if (local_8 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        local_14 = *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20);
        local_10 = *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20);
        local_c = FUN_0048c367((&DAT_004ff596)
                               [*(int *)(&DAT_006826c4 + target_id * 0x120 + spell_id * 0x5b20) *
                                0x34]);
        bVar1 = FUN_004af7bb(spell_id,target_id,local_c);
        (&DAT_006826dd)[local_14 * 0x5b20 + local_10 * 0x120] = (char)(1 << (bVar1 & 0x1f));
        if (DAT_0066aaf4 != 1) {
          FUN_0048d00c(0x1d);
        }
      }
      (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      FUN_0046e571(spell_id,target_id,1);
    }
    uVar2 = 0;
  }
  return uVar2;
}



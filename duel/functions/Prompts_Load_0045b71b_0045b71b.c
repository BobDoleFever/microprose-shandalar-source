/*
 * Decompiled function: Prompts_Load_0045b71b
 * Entry Point: 0045b71b
 * Size: 1284 bytes
 */
#include "duel.h"


undefined4 Prompts_Load_0045b71b(int spell_id,int target_id,int flags)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  bool bVar4;
  uint uVar5;
  uint uVar6;
  undefined4 arg_11;
  int iVar7;
  undefined4 arg_12;
  uint uVar8;
  undefined4 arg_13;
  uint uVar9;
  undefined4 arg_14;
  uint uVar10;
  undefined4 arg_15;
  uint uVar11;
  undefined4 arg_16;
  uint uVar12;
  undefined4 arg_17;
  undefined *arg_18;
  undefined4 arg_18_00;
  undefined4 arg_19;
  int *arg_20;
  int local_c;
  int local_8;
  
  if (flags == 1) {
    *(int *)(&DAT_0068f334 + spell_id * 0x20) = *(int *)(&DAT_0068f334 + spell_id * 0x20) + 1;
  }
  if (flags == 0x73) {
    bVar4 = (*(uint *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) & 0x20010) == 0;
    if ((bVar4) && (iVar1 = FUN_0049b309(spell_id,2,2), iVar1 == 0)) {
      bVar4 = false;
    }
    if ((bVar4) && (iVar1 = FUN_0049b309(spell_id,7,4), iVar1 == 0)) {
      bVar4 = false;
    }
    uVar2 = 0;
    if (bVar4) {
      arg_19 = 0x40;
      arg_18_00 = 0;
      arg_17 = 0;
      arg_16 = 0xffffffff;
      arg_15 = 0xffffffff;
      arg_14 = 0xffffffff;
      arg_13 = 0xffffffff;
      arg_12 = 0;
      arg_11 = 0;
      uVar2 = FUN_004521e2(spell_id,target_id);
      uVar2 = FUN_0041bcf0((int *)0x0,0,spell_id,2,2,0x200,0x1047,0,0,uVar2,arg_11,arg_12,arg_13,
                           arg_14,arg_15,arg_16,arg_17,arg_18_00,arg_19);
    }
  }
  else if (flags == 0x90) {
    FUN_0043071d(0);
    uVar2 = 0;
  }
  else {
    if ((flags == 0x6d) &&
       ((*(uint *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) & 0x20010) == 0)) {
      DAT_0068ece0 = 2;
      FUN_0042b6b0(spell_id,2,2);
      if (DAT_00681ea4 != 1) {
        FUN_00434660(s_prompts_txt_004f89e4,s_TIME_ELEMENTAL_004f89d4);
        arg_20 = &local_c;
        uVar2 = 1;
        arg_18 = &DAT_006679f0;
        uVar12 = 0x40;
        uVar11 = 0;
        uVar10 = 0;
        uVar9 = 0xffffffff;
        uVar8 = 0xffffffff;
        iVar7 = -1;
        iVar1 = -1;
        uVar6 = 0;
        uVar5 = 0;
        uVar3 = FUN_004521e2(spell_id,target_id);
        iVar1 = Action_ValidateTarget_0041e2a2
                          (spell_id,2,1 - spell_id,0x200,0x1047,0,0,uVar3,uVar5,uVar6,iVar1,iVar7,
                           uVar8,uVar9,uVar10,uVar11,uVar12,arg_18,uVar2,arg_20);
        if (iVar1 == 0) {
          DAT_00681ea4 = 1;
        }
        else {
          *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20) = local_c;
          *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20) = local_8;
          (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 1;
          *(uint *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) =
               *(uint *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
        }
      }
    }
    if (flags == 0x72) {
      local_c = *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20);
      local_8 = *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20);
      uVar12 = 0x40;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0xffffffff;
      uVar8 = 0xffffffff;
      iVar7 = -1;
      iVar1 = -1;
      uVar6 = 0;
      uVar5 = 0;
      uVar3 = FUN_004521e2(spell_id,target_id);
      iVar1 = Rules_ParseFilter_0041c0ab
                        (local_c,local_8,(undefined1 *)0x0,spell_id,2,2,0x200,0x1047,0,0,uVar3,uVar5
                         ,uVar6,iVar1,iVar7,uVar8,uVar9,uVar10,uVar11,uVar12);
      if (iVar1 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        FUN_004af82a(local_c,local_8);
      }
      (&DAT_006827b8)
      [*(int *)(&DAT_006827b0 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
       *(int *)(&DAT_006827b4 + target_id * 0x120 + spell_id * 0x5b20) * 0x120] = 0;
    }
    if (((flags == 0x15) || (flags == 199)) &&
       (((&DAT_006826cc)[target_id * 0x120 + spell_id * 0x5b20] & 4) != 0)) {
      FUN_004a2b00(spell_id,target_id,DAT_0066674c,spell_id,-1);
    }
    if (((flags == 0x1a) || (flags == 199)) &&
       ((DAT_0068f2c4 == 0x17 && ((&DAT_006826de)[target_id * 0x120 + spell_id * 0x5b20] != -1)))) {
      FUN_004a2b00(spell_id,target_id,DAT_0066674c,spell_id,-1);
    }
    if ((flags == 0x22) || (flags == 199)) {
      *(undefined4 *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) = 0;
    }
    if (((flags == 0x8a) && (target_id == DAT_00690c48)) && (spell_id == DAT_0068ecb0)) {
      DAT_0069340c = DAT_0069340c + 0x78;
    }
    if (((flags == 0x8b) && (target_id == DAT_00690c48)) && (spell_id == DAT_0068ecb0)) {
      DAT_0069340c = DAT_0069340c + -0x78;
    }
    uVar2 = 0;
  }
  return uVar2;
}



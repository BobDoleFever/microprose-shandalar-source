/*
 * Decompiled function: Prompts_Load_0041336b
 * Entry Point: 0041336b
 * Size: 1084 bytes
 */
#include "duel.h"


undefined4 Prompts_Load_0041336b(int spell_id,int target_id,int flags)

{
  int iVar1;
  undefined4 uVar2;
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
  int local_c;
  int local_8;
  
  if (((flags == 0x6c) && (DAT_00690c48 == target_id)) && (spell_id == DAT_0068ecb0)) {
    DAT_0068f2d4 = DAT_0068f2d4 + *(int *)(&DAT_0068edfc + DAT_00676504 * 0x20) * 3;
  }
  if (flags == 0x73) {
    if ((((((&DAT_006826ce)[target_id * 0x120 + spell_id * 0x5b20] & 3) == 0) ||
         (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + target_id * 0x120 + spell_id * 0x5b20) * 0x34] &
          2) == 0)) && (((&DAT_006826cc)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0)) &&
       (iVar1 = FUN_0049b309(spell_id,7,2), iVar1 != 0)) {
      arg_19 = 0;
      arg_18_00 = 2;
      arg_17 = 0;
      arg_16 = 0xffffffff;
      arg_15 = 0xffffffff;
      arg_14 = 0xffffffff;
      arg_13 = 0xffffffff;
      arg_12 = 0;
      arg_11 = 0;
      uVar2 = FUN_004521e2(spell_id,target_id);
      iVar1 = FUN_0041bcf0((int *)0x0,0,spell_id,spell_id,spell_id,0x200,2,0,0,uVar2,arg_11,arg_12,
                           arg_13,arg_14,arg_15,arg_16,arg_17,arg_18_00,arg_19);
      if (iVar1 != 0) {
        return 1;
      }
    }
  }
  else if (flags == 0x90) {
    FUN_0043071d(0);
  }
  else {
    if ((((flags == 0x6d) && (((&DAT_006826cc)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0))
        && ((iVar1 = FUN_0049b309(spell_id,7,2), iVar1 != 0 &&
            ((spell_id == DAT_00666458 && (DAT_006826b0 != 0)))))) &&
       (FUN_0042b6b0(spell_id,0,2), DAT_00681ea4 != 1)) {
      FUN_00434660(s_prompts_txt_004f2a60,s_EBONYHORSE_004f2a54);
      arg_20 = &local_c;
      uVar2 = 1;
      arg_18 = &DAT_006679f0;
      uVar11 = 0;
      uVar10 = 2;
      uVar9 = 0;
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
      iVar6 = -1;
      iVar1 = -1;
      uVar5 = 0;
      uVar4 = 0;
      uVar3 = FUN_004521e2(spell_id,target_id);
      iVar1 = Action_ValidateTarget_0041e2a2
                        (spell_id,spell_id,spell_id,0x200,2,0,0,uVar3,uVar4,uVar5,iVar1,iVar6,uVar7,
                         uVar8,uVar9,uVar10,uVar11,arg_18,uVar2,arg_20);
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
    if (flags == 0x72) {
      local_c = *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20);
      local_8 = *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20);
      (&DAT_006827b8)
      [*(int *)(&DAT_006827b0 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
       *(int *)(&DAT_006827b4 + target_id * 0x120 + spell_id * 0x5b20) * 0x120] = 0;
      uVar11 = 0;
      uVar10 = 2;
      uVar9 = 0;
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
      iVar6 = -1;
      iVar1 = -1;
      uVar5 = 0;
      uVar4 = 0;
      uVar3 = FUN_004521e2(spell_id,target_id);
      iVar1 = Rules_ParseFilter_0041c0ab
                        (local_c,local_8,(undefined1 *)0x0,spell_id,(byte)spell_id,(byte)spell_id,
                         0x200,2,0,0,uVar3,uVar4,uVar5,iVar1,iVar6,uVar7,uVar8,uVar9,uVar10,uVar11);
      if (iVar1 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        *(uint *)(&DAT_006826cc + local_c * 0x5b20 + local_8 * 0x120) =
             *(uint *)(&DAT_006826cc + local_c * 0x5b20 + local_8 * 0x120) & 0xffffffef;
        FUN_004a2b00(DAT_00690af0,DAT_0068efa0,DAT_0066675c,local_c,local_8);
      }
    }
  }
  return 0;
}



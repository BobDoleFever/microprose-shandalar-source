/*
 * Decompiled function: Prompts_Load_0045de60
 * Entry Point: 0045de60
 * Size: 806 bytes
 */
#include "duel.h"


undefined4 Prompts_Load_0045de60(int spell_id,int target_id,int flags)

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
  int local_c;
  int local_8;
  
  if (flags == 0x73) {
    uVar1 = 0;
    if ((*(uint *)(&DAT_006826cc + spell_id * 0x5b20 + target_id * 0x120) & 0x20010) == 0) {
      arg_19 = 0;
      arg_18_00 = 0;
      arg_17 = 0;
      arg_16 = 0xffffffff;
      arg_15 = 0x2002;
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
      FUN_00434660(s_prompts_txt_004f8ac8,s_DWARVEN_WARRIORS_004f8ab4);
      arg_20 = &local_c;
      uVar1 = 1;
      arg_18 = &DAT_006679f0;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uVar8 = 0xffffffff;
      uVar7 = 0x2002;
      iVar6 = -1;
      iVar5 = -1;
      uVar4 = 0;
      uVar3 = 0;
      uVar2 = FUN_004521e2(spell_id,target_id);
      iVar5 = Action_ValidateTarget_0041e2a2
                        (spell_id,2,spell_id,0x200,2,0,0,uVar2,uVar3,uVar4,iVar5,iVar6,uVar7,uVar8,
                         uVar9,uVar10,uVar11,arg_18,uVar1,arg_20);
      if (iVar5 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        *(int *)(&DAT_00682718 + spell_id * 0x5b20 + target_id * 0x120) = local_c;
        *(int *)(&DAT_0068271c + spell_id * 0x5b20 + target_id * 0x120) = local_8;
        (&DAT_006827b8)[spell_id * 0x5b20 + target_id * 0x120] = 1;
        *(uint *)(&DAT_006826cc + spell_id * 0x5b20 + target_id * 0x120) =
             *(uint *)(&DAT_006826cc + spell_id * 0x5b20 + target_id * 0x120) | 0x10;
      }
    }
    if (flags == 0x72) {
      local_c = *(int *)(&DAT_00682718 + spell_id * 0x5b20 + target_id * 0x120);
      local_8 = *(int *)(&DAT_0068271c + spell_id * 0x5b20 + target_id * 0x120);
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uVar8 = 0xffffffff;
      uVar7 = 0x2002;
      iVar6 = -1;
      iVar5 = -1;
      uVar4 = 0;
      uVar3 = 0;
      uVar2 = FUN_004521e2(spell_id,target_id);
      iVar5 = Rules_ParseFilter_0041c0ab
                        (local_c,local_8,(undefined1 *)0x0,spell_id,2,2,0x200,2,0,0,uVar2,uVar3,
                         uVar4,iVar5,iVar6,uVar7,uVar8,uVar9,uVar10,uVar11);
      if (iVar5 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        FUN_004a2b00(DAT_00690af0,DAT_0068efa0,DAT_006667b0,local_c,local_8);
      }
      (&DAT_006827b8)
      [*(int *)(&DAT_006827b0 + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20 +
       *(int *)(&DAT_006827b4 + spell_id * 0x5b20 + target_id * 0x120) * 0x120] = 0;
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Palette_Subsystem_004a6fef
 * Entry Point: 00468def
 * Size: 1486 bytes
 */
#include "duel.h"


undefined4 Palette_Subsystem_004a6fef(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 arg_10;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined4 arg_11;
  undefined4 arg_12;
  uint uVar7;
  undefined4 arg_13;
  uint uVar8;
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
  undefined4 local_c;
  undefined4 local_8;
  
  if (flags == 0x71) {
    local_8 = DAT_0066642c;
    uVar1 = FUN_004693bd(1 - spell_id);
    FUN_0046951b(spell_id,target_id,uVar1);
    DAT_0066642c = local_8;
  }
  if (flags == 0x73) {
    if (((((&DAT_006826ce)[target_id * 0x120 + spell_id * 0x5b20] & 3) == 0) ||
        (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + target_id * 0x120 + spell_id * 0x5b20) * 0x34] &
         2) == 0)) &&
       ((((&DAT_006826cc)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0 &&
        (iVar2 = FUN_0049b309(spell_id,3,2), iVar2 != 0)))) {
      arg_19 = 0;
      arg_18_00 = 0;
      arg_17 = 0x10;
      arg_16 = 0xffffffff;
      arg_15 = 0xffffffff;
      uVar1 = *(undefined4 *)
               (&DAT_006826e4 +
               *(int *)(&DAT_006826ec + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
               (char)(&DAT_006826d3)[target_id * 0x120 + spell_id * 0x5b20] * 0x5b20);
      arg_13 = 0xffffffff;
      arg_12 = 0;
      arg_11 = 0;
      arg_10 = FUN_004521e2(spell_id,target_id);
      iVar2 = FUN_0041bcf0((int *)0x0,0,spell_id,2,2,0x200,2,0,0,arg_10,arg_11,arg_12,arg_13,uVar1,
                           arg_15,arg_16,arg_17,arg_18_00,arg_19);
      if (iVar2 != 0) {
        return 1;
      }
    }
  }
  else if (flags == 0x90) {
    FUN_0043071d(0);
  }
  else {
    if ((((flags == 0x6d) &&
         ((*(uint *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) & 0x20010) == 0)) &&
        (iVar2 = FUN_00468b20(spell_id,target_id,
                              *(int *)(&DAT_006826e4 +
                                      *(int *)(&DAT_006826ec + target_id * 0x120 + spell_id * 0x5b20
                                              ) * 0x120 +
                                      (char)(&DAT_006826d3)[target_id * 0x120 + spell_id * 0x5b20] *
                                      0x5b20)), iVar2 != 0)) &&
       (Ai_CalcManaRequirement_004ba890(spell_id,3,2), DAT_00681ea4 != 1)) {
      FUN_00434660(s_prompts_txt_004f9390,s_ASWANJAGUAR_004f9384);
      arg_20 = &local_14;
      uVar1 = 1;
      arg_18 = &DAT_006679f0;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0x10;
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
      iVar2 = *(int *)(&DAT_006826e4 +
                      *(int *)(&DAT_006826ec + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
                      (char)(&DAT_006826d3)[target_id * 0x120 + spell_id * 0x5b20] * 0x5b20);
      iVar6 = -1;
      uVar5 = 0;
      uVar4 = 0;
      uVar3 = FUN_004521e2(spell_id,target_id);
      iVar2 = Action_ValidateTarget_0041e2a2
                        (spell_id,2,1 - spell_id,0x200,2,0,0,uVar3,uVar4,uVar5,iVar6,iVar2,uVar7,
                         uVar8,uVar9,uVar10,uVar11,arg_18,uVar1,arg_20);
      if (iVar2 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20) = local_10;
        *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20) = local_14;
        (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        local_c = *(undefined4 *)
                   (&DAT_00618ad8 +
                   *(int *)(&DAT_004ff590 +
                           *(int *)(&DAT_006826c4 + local_14 * 0x5b20 + local_10 * 0x120) * 0x34) *
                   0x98);
        *(uint *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
      }
    }
    if (flags == 0x72) {
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0x10;
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
      iVar2 = *(int *)(&DAT_006826e4 +
                      *(int *)(&DAT_006826ec + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
                      (char)(&DAT_006826d3)[target_id * 0x120 + spell_id * 0x5b20] * 0x5b20);
      iVar6 = -1;
      uVar5 = 0;
      uVar4 = 0;
      uVar3 = FUN_004521e2(spell_id,target_id);
      iVar2 = Rules_ParseFilter_0041c0ab
                        (*(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20),
                         (undefined1 *)0x0,spell_id,2,2,0x200,2,0,0,uVar3,uVar4,uVar5,iVar6,iVar2,
                         uVar7,uVar8,uVar9,uVar10,uVar11);
      if (iVar2 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        if (DAT_0066aaf4 != 1) {
          FUN_0048d00c(0x22);
        }
        FUN_0046e571(*(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20),
                     *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20),1);
      }
      (&DAT_006827b8)
      [*(int *)(&DAT_006827b4 + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
       *(int *)(&DAT_006827b0 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20] = 0;
    }
  }
  return 0;
}



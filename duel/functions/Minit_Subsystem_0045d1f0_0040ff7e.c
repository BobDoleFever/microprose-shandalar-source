/*
 * Decompiled function: Minit_Subsystem_0045d1f0
 * Entry Point: 0040ff7e
 * Size: 1617 bytes
 */
#include "duel.h"


undefined4 Minit_Subsystem_0045d1f0(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 uVar8;
  uint uVar9;
  undefined4 uVar10;
  uint uVar11;
  undefined4 uVar12;
  uint uVar13;
  undefined4 uVar14;
  uint uVar15;
  undefined4 uVar16;
  uint uVar17;
  undefined4 uVar18;
  undefined *arg_18;
  undefined4 uVar19;
  undefined4 uVar20;
  undefined4 arg_19;
  int *arg_20;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (flags == 0x73) {
    uVar20 = 0;
    uVar19 = 0;
    uVar18 = 0;
    uVar16 = 0xffffffff;
    uVar14 = 0xffffffff;
    uVar12 = 0xffffffff;
    uVar10 = 0xffffffff;
    uVar8 = 0;
    uVar6 = 0;
    uVar1 = FUN_004521e2(spell_id,target_id);
    FUN_0041bcf0((int *)(-(uint)(DAT_0068f100 == 0) & 0x68ed04),0,spell_id,2,2,0x200,1,0,0,uVar1,
                 uVar6,uVar8,uVar10,uVar12,uVar14,uVar16,uVar18,uVar19,uVar20);
    if (((((&DAT_006826ce)[target_id * 0x120 + spell_id * 0x5b20] & 3) == 0) ||
        (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + target_id * 0x120 + spell_id * 0x5b20) * 0x34] &
         2) == 0)) && (((&DAT_006826cc)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0)) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else if (flags == 0x90) {
    FUN_00430768(0);
    uVar1 = 0;
  }
  else {
    if (flags == 0x6d) {
      if (spell_id == DAT_00676504) {
        DAT_0068f2d4 = DAT_0068f2d4 + -0x18;
      }
      *(uint *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) =
           *(uint *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
      uVar1 = DAT_0068ed04;
      arg_19 = 0;
      uVar20 = 0;
      uVar19 = 0;
      uVar18 = 0xffffffff;
      uVar16 = 0xffffffff;
      uVar14 = 0xffffffff;
      uVar12 = 0xffffffff;
      uVar10 = 0;
      uVar8 = 0;
      uVar6 = FUN_004521e2(spell_id,target_id);
      FUN_0041bcf0(&DAT_0068ed04,0,spell_id,2,2,0x200,1,0,0,uVar6,uVar8,uVar10,uVar12,uVar14,uVar16,
                   uVar18,uVar19,uVar20,arg_19);
      DAT_0068ece0 = 0xffffffff;
      Ai_CalcManaRequirement_004ba890(spell_id,0,0);
      DAT_0068ed04 = uVar1;
      if (DAT_00681ea4 != 1) {
        (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 0;
        local_c = 0;
        local_8 = 0;
        while (((local_c < DAT_00681ea0 && (local_8 == 0)) && (DAT_00681ea4 != 1))) {
          FUN_00434660(s_prompts_txt_004f296c,s_CANDLEABRA_OF_TAWNOS_004f2954);
          _sprintf(&DAT_006679f0,&DAT_006679f0,local_c + 1,DAT_00681ea0);
          arg_20 = &local_14;
          uVar1 = 1;
          arg_18 = &DAT_006679f0;
          uVar17 = 0;
          uVar15 = 0;
          uVar13 = 0;
          uVar11 = 0xffffffff;
          uVar9 = 0xffffffff;
          iVar7 = -1;
          iVar5 = -1;
          uVar4 = 0;
          uVar3 = 0;
          uVar2 = FUN_004521e2(spell_id,target_id);
          iVar5 = Action_ValidateTarget_0041e2a2
                            (spell_id,2,spell_id,0x200,1,0,0,uVar2,uVar3,uVar4,iVar5,iVar7,uVar9,
                             uVar11,uVar13,uVar15,uVar17,arg_18,uVar1,arg_20);
          if (iVar5 == 0) {
            if (local_10 == -1) {
              (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 0;
              DAT_00681ea4 = 1;
            }
            else {
              local_8 = 1;
            }
          }
          else {
            *(uint *)(&DAT_006826cc + local_14 * 0x5b20 + local_10 * 0x120) =
                 *(uint *)(&DAT_006826cc + local_14 * 0x5b20 + local_10 * 0x120) | 0x300000;
            FUN_00451482(0,0x20);
            *(int *)(&DAT_00682718 +
                    target_id * 0x120 +
                    spell_id * 0x5b20 +
                    (char)(&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] * 8) = local_14;
            *(int *)(&DAT_0068271c +
                    target_id * 0x120 +
                    spell_id * 0x5b20 +
                    (char)(&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] * 8) = local_10;
            (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] =
                 (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] + '\x01';
          }
          local_c = local_c + 1;
        }
        for (local_c = 0; local_c < (char)(&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20];
            local_c = local_c + 1) {
          *(uint *)(&DAT_006826cc +
                   *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20 + local_c * 8) *
                   0x5b20 + *(int *)(&DAT_0068271c +
                                    target_id * 0x120 + spell_id * 0x5b20 + local_c * 8) * 0x120) =
               *(uint *)(&DAT_006826cc +
                        *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20 + local_c * 8
                                ) * 0x5b20 +
                        *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20 + local_c * 8
                                ) * 0x120) & 0xffcfffff;
        }
      }
      if (DAT_00681ea4 == 1) {
        (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 0;
        *(uint *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) & 0xffffffef;
      }
    }
    if (flags == 0x72) {
      for (local_c = 0; local_c < (char)(&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20];
          local_c = local_c + 1) {
        local_14 = *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20 + local_c * 8);
        local_10 = *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20 + local_c * 8);
        uVar17 = 0;
        uVar15 = 0;
        uVar13 = 0;
        uVar11 = 0xffffffff;
        uVar9 = 0xffffffff;
        iVar7 = -1;
        iVar5 = -1;
        uVar4 = 0;
        uVar3 = 0;
        uVar2 = FUN_004521e2(spell_id,target_id);
        iVar5 = Rules_ParseFilter_0041c0ab
                          (local_14,local_10,(undefined1 *)0x0,spell_id,2,2,0x200,1,0,0,uVar2,uVar3,
                           uVar4,iVar5,iVar7,uVar9,uVar11,uVar13,uVar15,uVar17);
        if (iVar5 == 0) {
          DAT_00681ea4 = 1;
        }
        else {
          FUN_0048c907(local_14,local_10,1,0xffffffff,0xffffffff);
          *(uint *)(&DAT_006826cc + local_14 * 0x5b20 + local_10 * 0x120) =
               *(uint *)(&DAT_006826cc + local_14 * 0x5b20 + local_10 * 0x120) & 0xffffffef;
        }
      }
      (&DAT_006827b8)
      [*(int *)(&DAT_006827b0 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
       *(int *)(&DAT_006827b4 + target_id * 0x120 + spell_id * 0x5b20) * 0x120] = 0;
    }
    uVar1 = 0;
  }
  return uVar1;
}



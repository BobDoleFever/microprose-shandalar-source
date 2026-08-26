/*
 * Decompiled function: Prompts_Load_004be92e
 * Entry Point: 004be92e
 * Size: 951 bytes
 */
#include "duel.h"


undefined4 Prompts_Load_004be92e(int spell_id,int target_id,int flags)

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
  undefined4 local_8;
  
  if (flags == 0x74) {
    arg_19 = 0;
    arg_18_00 = 0;
    arg_17 = 1;
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
  else {
    if (((flags == 0x6c) && (target_id == DAT_00690c48)) && (spell_id == DAT_0068ecb0)) {
      FUN_00434660(s_prompts_txt_00508910,s_ANIMATE_WALL_00508900);
      arg_20 = &local_c;
      uVar1 = 1;
      arg_18 = &DAT_006679f0;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 1;
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
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
        *(undefined4 *)(&DAT_0068271c + spell_id * 0x5b20 + target_id * 0x120) = local_8;
        (&DAT_006827b8)[spell_id * 0x5b20 + target_id * 0x120] = 1;
      }
    }
    if (flags == 0x71) {
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 1;
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
      iVar6 = -1;
      iVar5 = -1;
      uVar4 = 0;
      uVar3 = 0;
      uVar2 = FUN_004521e2(spell_id,target_id);
      iVar5 = Rules_ParseFilter_0041c0ab
                        (*(int *)(&DAT_00682718 + spell_id * 0x5b20 + target_id * 0x120),
                         *(int *)(&DAT_0068271c + spell_id * 0x5b20 + target_id * 0x120),
                         (undefined1 *)0x0,spell_id,2,2,0x200,2,0,0,uVar2,uVar3,uVar4,iVar5,iVar6,
                         uVar7,uVar8,uVar9,uVar10,uVar11);
      if (iVar5 == 0) {
        FUN_0046e571(spell_id,target_id,1);
        DAT_00681ea4 = 1;
      }
      else {
        (&DAT_006826d2)[spell_id * 0x5b20 + target_id * 0x120] =
             (&DAT_00682718)[spell_id * 0x5b20 + target_id * 0x120];
        *(undefined4 *)(&DAT_006826e8 + spell_id * 0x5b20 + target_id * 0x120) =
             *(undefined4 *)(&DAT_0068271c + spell_id * 0x5b20 + target_id * 0x120);
        *(uint *)(&DAT_006826f8 +
                 *(int *)(&DAT_006826e8 + spell_id * 0x5b20 + target_id * 0x120) * 0x120 +
                 (char)(&DAT_006826d2)[spell_id * 0x5b20 + target_id * 0x120] * 0x5b20) =
             *(uint *)(&DAT_006826f8 +
                      *(int *)(&DAT_006826e8 + spell_id * 0x5b20 + target_id * 0x120) * 0x120 +
                      (char)(&DAT_006826d2)[spell_id * 0x5b20 + target_id * 0x120] * 0x5b20) | 0x800
        ;
      }
      (&DAT_006827b8)[spell_id * 0x5b20 + target_id * 0x120] = 0;
    }
    if (((flags == 0x77) && (target_id == DAT_00690c48)) &&
       ((spell_id == DAT_0068ecb0 &&
        (*(int *)(&DAT_006826e8 + spell_id * 0x5b20 + target_id * 0x120) != -1)))) {
      *(uint *)(&DAT_006826f8 +
               *(int *)(&DAT_006826e8 + spell_id * 0x5b20 + target_id * 0x120) * 0x120 +
               (char)(&DAT_006826d2)[spell_id * 0x5b20 + target_id * 0x120] * 0x5b20) =
           *(uint *)(&DAT_006826f8 +
                    *(int *)(&DAT_006826e8 + spell_id * 0x5b20 + target_id * 0x120) * 0x120 +
                    (char)(&DAT_006826d2)[spell_id * 0x5b20 + target_id * 0x120] * 0x5b20) &
           0xfffff7ff;
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: Minit_Subsystem_0045c59a
 * Entry Point: 0040f321
 * Size: 2708 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 Minit_Subsystem_0045c59a(int spell_id,int target_id,int flags)

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
  int local_10;
  int local_c;
  int local_8;
  
  if (((flags == 0x82) && (DAT_00690c48 == target_id)) && (DAT_0068ecb0 == spell_id)) {
    *(uint *)(&DAT_006827c8 + target_id * 0x120 + spell_id * 0x5b20) =
         *(uint *)(&DAT_006827c8 + target_id * 0x120 + spell_id * 0x5b20) & 0xfffffffd;
  }
  if (((DAT_0068f2c4 == 1) && (DAT_00690c48 == target_id)) && (DAT_0068ecb0 == spell_id)) {
    if (((flags == 0x7d) && (((&DAT_006827c8)[target_id * 0x120 + spell_id * 0x5b20] & 1) != 0)) &&
       ((((&DAT_006827c8)[target_id * 0x120 + spell_id * 0x5b20] & 2) == 0 &&
        ((_DAT_0068f0cc &
         (byte)(&DAT_004ff594)
               [*(int *)(&DAT_006826c4 + target_id * 0x120 + spell_id * 0x5b20) * 0x34]) == 0)))) {
      if (((spell_id == 1) || (DAT_0066aaf4 == 1)) || (DAT_0068f0b0 != 0)) {
        iVar1 = *(int *)(&DAT_006826ec + target_id * 0x120 + spell_id * 0x5b20);
        if ((iVar1 == -1) ||
           ((((&DAT_006827c8)
              [*(int *)(&DAT_006826e8 + iVar1 * 0x120 + spell_id * 0x5b20) * 0x120 +
               (char)(&DAT_006826d2)[iVar1 * 0x120 + spell_id * 0x5b20] * 0x5b20] & 1) == 0 &&
            (((&DAT_006826cc)
              [*(int *)(&DAT_006826e8 + iVar1 * 0x120 + spell_id * 0x5b20) * 0x120 +
               (char)(&DAT_006826d2)[iVar1 * 0x120 + spell_id * 0x5b20] * 0x5b20] & 0x10) != 0)))) {
          DAT_0066642c = DAT_0066642c | 2;
        }
      }
      else {
        DAT_0066642c = DAT_0066642c | 1;
      }
    }
    if (flags == 0x7e) {
      *(uint *)(&DAT_006827c8 + target_id * 0x120 + spell_id * 0x5b20) =
           *(uint *)(&DAT_006827c8 + target_id * 0x120 + spell_id * 0x5b20) | 2;
    }
  }
  if (flags == 0x73) {
    if (((((&DAT_006826ce)[target_id * 0x120 + spell_id * 0x5b20] & 3) == 0) ||
        (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + target_id * 0x120 + spell_id * 0x5b20) * 0x34] &
         2) == 0)) &&
       ((((&DAT_006826cc)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0 &&
        (iVar1 = FUN_0049b309(spell_id,7,2), iVar1 != 0)))) {
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
      iVar1 = FUN_0041bcf0((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uVar2,arg_11,arg_12,arg_13,arg_14,
                           arg_15,arg_16,arg_17,arg_18_00,arg_19);
      if (iVar1 != 0) {
        return 1;
      }
    }
  }
  else if (flags == 0x90) {
    FUN_0043071d(0);
  }
  else {
    if (((flags == 0x6d) && (((&DAT_006826cc)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0))
       && ((iVar1 = FUN_0049b309(spell_id,7,2), iVar1 != 0 &&
           (Ai_CalcManaRequirement_004ba890(spell_id,0,2), DAT_00681ea4 != 1)))) {
      FUN_00434660(s_prompts_txt_004f2948,s_TAWNOS_WEAPONRY_004f2938);
      arg_20 = &local_10;
      uVar2 = 1;
      arg_18 = &DAT_006679f0;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
      iVar6 = -1;
      iVar1 = -1;
      uVar5 = 0;
      uVar4 = 0;
      uVar3 = FUN_004521e2(spell_id,target_id);
      iVar1 = Action_ValidateTarget_0041e2a2
                        (spell_id,2,spell_id,0x200,2,0,0,uVar3,uVar4,uVar5,iVar1,iVar6,uVar7,uVar8,
                         uVar9,uVar10,uVar11,arg_18,uVar2,arg_20);
      if (iVar1 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20) = local_10;
        *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20) = local_c;
        (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        *(uint *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
      }
    }
    if (flags == 0x72) {
      local_10 = *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20);
      local_c = *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20);
      (&DAT_006827b8)
      [*(int *)(&DAT_006827b0 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
       *(int *)(&DAT_006827b4 + target_id * 0x120 + spell_id * 0x5b20) * 0x120] = 0;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
      iVar6 = -1;
      iVar1 = -1;
      uVar5 = 0;
      uVar4 = 0;
      uVar3 = FUN_004521e2(spell_id,target_id);
      iVar1 = Rules_ParseFilter_0041c0ab
                        (local_10,local_c,(undefined1 *)0x0,spell_id,2,2,0x200,2,0,0,uVar3,uVar4,
                         uVar5,iVar1,iVar6,uVar7,uVar8,uVar9,uVar10,uVar11);
      if (iVar1 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        local_8 = FUN_004a2b00(DAT_00690af0,DAT_0068efa0,DAT_0066aaec,local_10,local_c);
        if (local_8 != -1) {
          *(uint *)(&DAT_006826f8 + local_8 * 0x120 + spell_id * 0x5b20) =
               *(uint *)(&DAT_006826f8 + local_8 * 0x120 + spell_id * 0x5b20) | 0x20;
          *(undefined2 *)(&DAT_006826d8 + local_8 * 0x120 + spell_id * 0x5b20) = 1;
          *(undefined2 *)(&DAT_006826da + local_8 * 0x120 + spell_id * 0x5b20) = 1;
          (&DAT_006826d3)
          [*(int *)(&DAT_006827b0 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
           *(int *)(&DAT_006827b4 + target_id * 0x120 + spell_id * 0x5b20) * 0x120] =
               (undefined1)spell_id;
          *(int *)(&DAT_006826ec +
                  *(int *)(&DAT_006827b0 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
                  *(int *)(&DAT_006827b4 + target_id * 0x120 + spell_id * 0x5b20) * 0x120) = local_8
          ;
        }
      }
    }
    if (flags == 0x77) {
      if (((*(int *)(&DAT_006826ec + target_id * 0x120 + spell_id * 0x5b20) != -1) &&
          ((char)(&DAT_006826d2)
                 [*(int *)(&DAT_006826ec + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
                  (char)(&DAT_006826d3)[target_id * 0x120 + spell_id * 0x5b20] * 0x5b20] ==
           DAT_0068ecb0)) &&
         (*(int *)(&DAT_006826e8 +
                  *(int *)(&DAT_006826ec + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
                  (char)(&DAT_006826d3)[target_id * 0x120 + spell_id * 0x5b20] * 0x5b20) ==
          DAT_00690c48)) {
        *(undefined4 *)(&DAT_006826ec + target_id * 0x120 + spell_id * 0x5b20) = 0xffffffff;
        (&DAT_006826d3)[target_id * 0x120 + spell_id * 0x5b20] =
             (&DAT_006826ec)[target_id * 0x120 + spell_id * 0x5b20];
      }
      if (((DAT_00690c48 == target_id) && (DAT_0068ecb0 == spell_id)) &&
         (*(int *)(&DAT_006826ec + target_id * 0x120 + spell_id * 0x5b20) != -1)) {
        FUN_0046e571((int)(char)(&DAT_006826d3)[target_id * 0x120 + spell_id * 0x5b20],
                     *(int *)(&DAT_006826ec + target_id * 0x120 + spell_id * 0x5b20),1);
        *(undefined4 *)(&DAT_006826ec + target_id * 0x120 + spell_id * 0x5b20) = 0xffffffff;
        (&DAT_006826d3)[target_id * 0x120 + spell_id * 0x5b20] =
             (&DAT_006826ec)[target_id * 0x120 + spell_id * 0x5b20];
      }
    }
    if ((*(int *)(&DAT_006826ec + target_id * 0x120 + spell_id * 0x5b20) != -1) &&
       (((&DAT_006826cc)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0)) {
      FUN_0046e571((int)(char)(&DAT_006826d3)[target_id * 0x120 + spell_id * 0x5b20],
                   *(int *)(&DAT_006826ec + target_id * 0x120 + spell_id * 0x5b20),1);
      *(undefined4 *)(&DAT_006826ec + target_id * 0x120 + spell_id * 0x5b20) = 0xffffffff;
    }
    if (((flags == 0x3b) &&
        ((*(uint *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) & 0x20010) == 0)) &&
       (iVar1 = FUN_0049b309(spell_id,7,2), iVar1 != 0)) {
      *(int *)(&DAT_00666730 + spell_id * 4) = *(int *)(&DAT_00666730 + spell_id * 4) + 1;
      *(int *)(&DAT_00666738 + spell_id * 4) = *(int *)(&DAT_00666738 + spell_id * 4) + 1;
    }
  }
  return 0;
}



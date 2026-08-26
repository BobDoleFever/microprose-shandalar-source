/*
 * Decompiled function: Prompts_Load_00415cfc
 * Entry Point: 00415cfc
 * Size: 1948 bytes
 */
#include "duel.h"


undefined4 Prompts_Load_00415cfc(int spell_id,int target_id,int flags)

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
  
  if (((flags == 0x6c) && (target_id == DAT_00690c48)) && (spell_id == DAT_0068ecb0)) {
    *(uint *)(&DAT_006826cc + spell_id * 0x5b20 + target_id * 0x120) =
         *(uint *)(&DAT_006826cc + spell_id * 0x5b20 + target_id * 0x120) | 0x10;
  }
  if (flags == 0x73) {
    if ((((((&DAT_006826ce)[spell_id * 0x5b20 + target_id * 0x120] & 3) == 0) ||
         (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + spell_id * 0x5b20 + target_id * 0x120) * 0x34] &
          2) == 0)) && (((&DAT_006826cc)[spell_id * 0x5b20 + target_id * 0x120] & 0x10) == 0)) &&
       (iVar1 = FUN_0049b309(spell_id,7,4), iVar1 != 0)) {
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
      iVar1 = FUN_0041bcf0((int *)0x0,0,spell_id,1 - spell_id,1 - spell_id,0x200,0,0,0,uVar2,arg_11,
                           arg_12,arg_13,arg_14,arg_15,arg_16,arg_17,arg_18_00,arg_19);
      if (iVar1 != 0) {
        return 1;
      }
    }
  }
  else if (flags == 0x90) {
    FUN_0043071d(0);
  }
  else {
    if (((flags == 0x6d) && (iVar1 = FUN_0049b309(spell_id,7,4), iVar1 != 0)) &&
       (FUN_0042b6b0(spell_id,0,4), DAT_00681ea4 != 1)) {
      FUN_00434660(s_prompts_txt_004f2af4,s_BRONZE_TABLET_004f2ae4);
      arg_20 = &local_c;
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
                        (spell_id,1 - spell_id,1 - spell_id,0x200,0x7f,0,0,uVar3,uVar4,uVar5,iVar1,
                         iVar6,uVar7,uVar8,uVar9,uVar10,uVar11,arg_18,uVar2,arg_20);
      if (iVar1 == 0) {
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
      uVar7 = 0xffffffff;
      iVar6 = -1;
      iVar1 = -1;
      uVar5 = 0;
      uVar4 = 0;
      uVar3 = FUN_004521e2(spell_id,target_id);
      iVar1 = Rules_ParseFilter_0041c0ab
                        (local_c,local_8,(undefined1 *)0x0,spell_id,1 - (char)spell_id,
                         1 - (char)spell_id,0x200,0x7f,0,0,uVar3,uVar4,uVar5,iVar1,iVar6,uVar7,uVar8
                         ,uVar9,uVar10,uVar11);
      if (iVar1 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        FUN_004348b2(s_prompts_txt_004f2b10,s_BRONZE_TABLET_004f2b00);
        uVar2 = FUN_0045102d(1 - spell_id,spell_id,target_id,-1,-1,
                             &DAT_006679f0 +
                             ((uint)((int)(&DAT_00681ea8)[1 - spell_id] < 10) * 5 + 5) * 0x32,0);
        *(undefined4 *)(&DAT_006826e4 + spell_id * 0x5b20 + target_id * 0x120) = uVar2;
        iVar1 = *(int *)(&DAT_006826e4 + spell_id * 0x5b20 + target_id * 0x120);
        if (iVar1 == 0) {
          if (*(int *)(&DAT_006826c4 +
                      *(int *)(&DAT_006827b0 + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20 +
                      *(int *)(&DAT_006827b4 + spell_id * 0x5b20 + target_id * 0x120) * 0x120) != -1
             ) {
            if (spell_id == DAT_00676510) {
              FUN_004d76dd(*(uint *)(&DAT_006826c4 +
                                    *(int *)(&DAT_006827b0 + spell_id * 0x5b20 + target_id * 0x120)
                                    * 0x5b20 +
                                    *(int *)(&DAT_006827b4 + spell_id * 0x5b20 + target_id * 0x120)
                                    * 0x120));
            }
            else {
              FUN_004d7510(*(uint *)(&DAT_006826c4 +
                                    *(int *)(&DAT_006827b0 + spell_id * 0x5b20 + target_id * 0x120)
                                    * 0x5b20 +
                                    *(int *)(&DAT_006827b4 + spell_id * 0x5b20 + target_id * 0x120)
                                    * 0x120));
            }
            *(uint *)(&DAT_006826cc +
                     *(int *)(&DAT_006827b0 + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20 +
                     *(int *)(&DAT_006827b4 + spell_id * 0x5b20 + target_id * 0x120) * 0x120) =
                 *(uint *)(&DAT_006826cc +
                          *(int *)(&DAT_006827b0 + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20 +
                          *(int *)(&DAT_006827b4 + spell_id * 0x5b20 + target_id * 0x120) * 0x120) ^
                 0x1000;
            FUN_0046e571(DAT_00690af0,DAT_0068efa0,4);
          }
          if (spell_id == DAT_00676510) {
            FUN_004d7510(*(uint *)(&DAT_006826c4 + local_c * 0x5b20 + local_8 * 0x120));
          }
          else {
            FUN_004d76dd(*(uint *)(&DAT_006826c4 + local_c * 0x5b20 + local_8 * 0x120));
          }
          *(uint *)(&DAT_006826cc + local_c * 0x5b20 + local_8 * 0x120) =
               *(uint *)(&DAT_006826cc + local_c * 0x5b20 + local_8 * 0x120) ^ 0x1000;
          FUN_0046e571(local_c,local_8,4);
        }
        else if (iVar1 == 1) {
          (&DAT_00681ea8)[1 - spell_id] = (&DAT_00681ea8)[1 - spell_id] + -10;
          if (*(int *)(&DAT_006826c4 +
                      *(int *)(&DAT_006827b0 + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20 +
                      *(int *)(&DAT_006827b4 + spell_id * 0x5b20 + target_id * 0x120) * 0x120) != -1
             ) {
            FUN_0046e571(DAT_00690af0,DAT_0068efa0,2);
          }
        }
        else if ((iVar1 == 2) &&
                ((&DAT_00681ea8)[1 - spell_id] = 0,
                *(int *)(&DAT_006826c4 +
                        *(int *)(&DAT_006827b0 + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20 +
                        *(int *)(&DAT_006827b4 + spell_id * 0x5b20 + target_id * 0x120) * 0x120) !=
                -1)) {
          FUN_0046e571(DAT_00690af0,DAT_0068efa0,2);
        }
      }
    }
  }
  return 0;
}



/*
 * Decompiled function: Prompts_Load_004044b3
 * Entry Point: 004044b3
 * Size: 1470 bytes
 */
#include "duel.h"


undefined4 Prompts_Load_004044b3(int spell_id,int target_id,int flags)

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
    arg_13 = 0xffffffff;
    arg_12 = 0;
    arg_11 = 0;
    uVar1 = FUN_004521e2(spell_id,target_id);
    FUN_0041bcf0((int *)(-(uint)(DAT_0068f100 == 0) & 0x68ed04),0,spell_id,2,2,0x200,2,0,0,uVar1,
                 arg_11,arg_12,arg_13,arg_14,arg_15,arg_16,arg_17,arg_18_00,arg_19);
    if ((DAT_00676504 == spell_id) &&
       ((DAT_0068ed04 == 0 || (iVar2 = FUN_0049b309(spell_id,7,2), iVar2 == 0)))) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  else {
    if (((flags == 0x6c) && (DAT_00690c48 == target_id)) && (DAT_0068ecb0 == spell_id)) {
      (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      local_c = 0;
      local_8 = 0;
      while (((local_c < DAT_00681ea0 && (local_8 == 0)) && (DAT_00681ea4 != 1))) {
        FUN_00434660(s_prompts_txt_004f2204,s_WINTER_BLAST_004f21f4);
        _sprintf(&DAT_006679f0,&DAT_006679f0,local_c + 1,DAT_00681ea0);
        arg_20 = &local_14;
        uVar1 = 1;
        arg_18 = &DAT_006679f0;
        uVar11 = 0;
        uVar10 = 0;
        uVar9 = 0;
        uVar8 = 0xffffffff;
        uVar7 = 0xffffffff;
        iVar6 = -1;
        iVar2 = -1;
        uVar5 = 0;
        uVar4 = 0;
        uVar3 = FUN_004521e2(spell_id,target_id);
        iVar2 = Action_ValidateTarget_0041e2a2
                          (spell_id,2,1 - spell_id,0x200,2,0,0,uVar3,uVar4,uVar5,iVar2,iVar6,uVar7,
                           uVar8,uVar9,uVar10,uVar11,arg_18,uVar1,arg_20);
        if (iVar2 == 0) {
          if (local_10 == -1) {
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
                      *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20 + local_c * 8)
                      * 0x5b20 +
                      *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20 + local_c * 8)
                      * 0x120) & 0xffcfffff;
      }
      if (DAT_00681ea4 == 1) {
        (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      }
    }
    if (flags == 0x71) {
      for (local_c = 0; local_c < (char)(&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20];
          local_c = local_c + 1) {
        uVar11 = 0;
        uVar10 = 0;
        uVar9 = 0;
        uVar8 = 0xffffffff;
        uVar7 = 0xffffffff;
        iVar6 = -1;
        iVar2 = -1;
        uVar5 = 0;
        uVar4 = 0;
        uVar3 = FUN_004521e2(spell_id,target_id);
        iVar2 = Rules_ParseFilter_0041c0ab
                          (*(int *)(&DAT_00682718 +
                                   target_id * 0x120 + spell_id * 0x5b20 + local_c * 8),
                           *(int *)(&DAT_0068271c +
                                   target_id * 0x120 + spell_id * 0x5b20 + local_c * 8),
                           (undefined1 *)0x0,spell_id,2,2,0x200,2,0,0,uVar3,uVar4,uVar5,iVar2,iVar6,
                           uVar7,uVar8,uVar9,uVar10,uVar11);
        if (iVar2 == 0) {
          DAT_00681ea4 = 1;
        }
        else {
          FUN_004a7b83(*(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20 + local_c * 8)
                       ,*(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20 + local_c * 8
                                ));
          uVar3 = FUN_0048b81a(*(int *)(&DAT_00682718 +
                                       target_id * 0x120 + spell_id * 0x5b20 + local_c * 8),
                               *(int *)(&DAT_0068271c +
                                       target_id * 0x120 + spell_id * 0x5b20 + local_c * 8),0x34,
                               0xffffffff);
          if ((uVar3 & 0x20) != 0) {
            FUN_004af950(*(int *)(&DAT_00682718 +
                                 target_id * 0x120 + spell_id * 0x5b20 + local_c * 8),
                         *(int *)(&DAT_0068271c +
                                 target_id * 0x120 + spell_id * 0x5b20 + local_c * 8),2,spell_id,
                         target_id);
          }
        }
      }
      (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      FUN_0046e571(spell_id,target_id,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}



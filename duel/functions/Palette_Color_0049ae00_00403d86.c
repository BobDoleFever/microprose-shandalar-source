/*
 * Decompiled function: Palette_Color_0049ae00
 * Entry Point: 00403d86
 * Size: 1153 bytes
 */
#include "duel.h"


undefined4 Palette_Color_0049ae00(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  int *arg_20;
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
    FUN_0041bcf0(&local_10,0,spell_id,2,2,0x200,2,0x40,0,uVar1,arg_11,arg_12,arg_13,arg_14,arg_15,
                 arg_16,arg_17,arg_18_00,arg_19);
    if (local_10 < 2) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  else {
    if (((flags == 0x6c) && (DAT_00690c48 == target_id)) && (DAT_0068ecb0 == spell_id)) {
      local_c = 0;
      while ((local_c < 2 && (DAT_00681ea4 != 1))) {
        FUN_00434660(s_prompts_txt_004f21cc,s_ASHESTOASHES_004f21bc);
        arg_20 = (int *)(&DAT_00682718 + spell_id * 0x5b20 + target_id * 0x120 + local_c * 8);
        uVar1 = 1;
        arg_18 = &DAT_006679f0 + local_c * 0xfa;
        uVar11 = 0;
        uVar10 = 0;
        uVar9 = 0;
        uVar8 = 0xffffffff;
        uVar7 = 0xffffffff;
        iVar6 = -1;
        iVar5 = -1;
        uVar4 = 0;
        uVar3 = 0;
        uVar2 = FUN_004521e2(spell_id,target_id);
        iVar5 = Action_ValidateTarget_0041e2a2
                          (spell_id,2,1 - spell_id,0x200,2,0x40,0,uVar2,uVar3,uVar4,iVar5,iVar6,
                           uVar7,uVar8,uVar9,uVar10,uVar11,arg_18,uVar1,arg_20);
        if (iVar5 == 0) {
          DAT_00681ea4 = 1;
        }
        else {
          *(uint *)(&DAT_006826cc +
                   *(int *)(&DAT_0068271c + local_c * 8 + spell_id * 0x5b20 + target_id * 0x120) *
                   0x120 + *(int *)(&DAT_00682718 +
                                   local_c * 8 + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20) =
               *(uint *)(&DAT_006826cc +
                        *(int *)(&DAT_0068271c + local_c * 8 + spell_id * 0x5b20 + target_id * 0x120
                                ) * 0x120 +
                        *(int *)(&DAT_00682718 + local_c * 8 + spell_id * 0x5b20 + target_id * 0x120
                                ) * 0x5b20) | 0x300000;
          FUN_00451482(0,0x20);
        }
        local_c = local_c + 1;
      }
      (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 2;
      for (local_c = 0; local_c < (char)(&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20];
          local_c = local_c + 1) {
        *(uint *)(&DAT_006826cc +
                 *(int *)(&DAT_0068271c + local_c * 8 + spell_id * 0x5b20 + target_id * 0x120) *
                 0x120 + *(int *)(&DAT_00682718 +
                                 local_c * 8 + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20) =
             *(uint *)(&DAT_006826cc +
                      *(int *)(&DAT_0068271c + local_c * 8 + spell_id * 0x5b20 + target_id * 0x120)
                      * 0x120 + *(int *)(&DAT_00682718 +
                                        local_c * 8 + spell_id * 0x5b20 + target_id * 0x120) *
                                0x5b20) & 0xffcfffff;
      }
      if (DAT_00681ea4 == 1) {
        (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      }
    }
    if (flags == 0x71) {
      local_8 = 0;
      for (local_c = 0; local_c < (char)(&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20];
          local_c = local_c + 1) {
        uVar11 = 0;
        uVar10 = 0;
        uVar9 = 0;
        uVar8 = 0xffffffff;
        uVar7 = 0xffffffff;
        iVar6 = -1;
        iVar5 = -1;
        uVar4 = 0;
        uVar3 = 0;
        uVar2 = FUN_004521e2(spell_id,target_id);
        iVar5 = Rules_ParseFilter_0041c0ab
                          (*(int *)(&DAT_00682718 +
                                   local_c * 8 + spell_id * 0x5b20 + target_id * 0x120),
                           *(int *)(&DAT_0068271c +
                                   local_c * 8 + spell_id * 0x5b20 + target_id * 0x120),
                           (undefined1 *)0x0,spell_id,2,2,0x200,2,0x40,0,uVar2,uVar3,uVar4,iVar5,
                           iVar6,uVar7,uVar8,uVar9,uVar10,uVar11);
        if (iVar5 == 0) {
          local_8 = local_8 + 1;
        }
        else {
          FUN_0046e571(*(int *)(&DAT_00682718 + local_c * 8 + spell_id * 0x5b20 + target_id * 0x120)
                       ,*(int *)(&DAT_0068271c + local_c * 8 + spell_id * 0x5b20 + target_id * 0x120
                                ),4);
        }
      }
      if (local_8 == 2) {
        DAT_00681ea4 = 1;
      }
      else {
        Mem_AllocOrFree_004afd1c(spell_id,5,spell_id,target_id);
      }
      (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      FUN_0046e571(spell_id,target_id,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}



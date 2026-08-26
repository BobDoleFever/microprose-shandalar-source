/*
 * Decompiled function: Palette_Color_0049ae00
 * Entry Point: 004086ae
 * Size: 1568 bytes
 */
#include "duel.h"


undefined4 Palette_Color_0049ae00(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  undefined *arg_18;
  uint uVar9;
  uint uVar10;
  int *arg_20;
  uint uVar11;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (flags == 0x74) {
    uVar1 = 1;
  }
  else {
    if (((flags == 0x6c) && (DAT_00690c48 == target_id)) && (DAT_0068ecb0 == spell_id)) {
      if ((DAT_00676510 == spell_id) && (DAT_0066aaf4 != 1)) {
        (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 0;
        FUN_00434660(s_prompts_txt_004f263c,s_PYROTECHNICS_004f262c);
        local_c = 0;
        while ((local_c < 4 && (DAT_00681ea4 != 1))) {
          arg_20 = &local_14;
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
                            (spell_id,2,1 - spell_id,0x1200,2,0,0,uVar2,uVar3,uVar4,iVar5,iVar6,
                             uVar7,uVar8,uVar9,uVar10,uVar11,arg_18,uVar1,arg_20);
          if (iVar5 == 0) {
            DAT_00681ea4 = 1;
          }
          else {
            *(uint *)(&DAT_006826cc + local_14 * 0x5b20 + local_10 * 0x120) =
                 *(uint *)(&DAT_006826cc + local_14 * 0x5b20 + local_10 * 0x120) | 0x200000;
            FUN_00451482(0,0x20);
            *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20 + local_c * 8) = local_14
            ;
            *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20 + local_c * 8) = local_10
            ;
            (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] =
                 (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] + '\x01';
          }
          local_c = local_c + 1;
        }
        for (local_c = 0; local_c < (char)(&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20];
            local_c = local_c + 1) {
          *(uint *)(&DAT_006826cc +
                   *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20 + local_c * 8) *
                   0x120 + *(int *)(&DAT_00682718 +
                                   target_id * 0x120 + spell_id * 0x5b20 + local_c * 8) * 0x5b20) =
               *(uint *)(&DAT_006826cc +
                        *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20 + local_c * 8
                                ) * 0x120 +
                        *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20 + local_c * 8
                                ) * 0x5b20) & 0xffcfffff;
        }
        if (DAT_00681ea4 == 1) {
          (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 0;
        }
      }
      else {
        for (local_c = 0; local_c < 4; local_c = local_c + 1) {
          FUN_00461047(spell_id,target_id);
          *(undefined4 *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20 + (3 - local_c) * 8)
               = *(undefined4 *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20);
          *(undefined4 *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20 + (3 - local_c) * 8)
               = *(undefined4 *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20);
          (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 4;
        }
      }
    }
    if (flags == 0x71) {
      if ((DAT_00676510 == spell_id) && (DAT_0066aaf4 != 1)) {
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
                                     target_id * 0x120 + spell_id * 0x5b20 + local_c * 8),
                             *(int *)(&DAT_0068271c +
                                     target_id * 0x120 + spell_id * 0x5b20 + local_c * 8),
                             (undefined1 *)0x0,spell_id,2,2,0x1200,2,0,0,uVar2,uVar3,uVar4,iVar5,
                             iVar6,uVar7,uVar8,uVar9,uVar10,uVar11);
          if (iVar5 == 0) {
            local_8 = local_8 + 1;
          }
          else {
            FUN_004af950(*(int *)(&DAT_00682718 +
                                 target_id * 0x120 + spell_id * 0x5b20 + local_c * 8),
                         *(int *)(&DAT_0068271c +
                                 target_id * 0x120 + spell_id * 0x5b20 + local_c * 8),1,spell_id,
                         target_id);
          }
        }
        if ((char)(&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] == local_8) {
          DAT_00681ea4 = 1;
        }
        (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      }
      else {
        for (local_c = 0; local_c < 4; local_c = local_c + 1) {
          *(undefined4 *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20) =
               *(undefined4 *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20 + local_c * 8);
          *(undefined4 *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20) =
               *(undefined4 *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20 + local_c * 8);
          FUN_004612b0(spell_id,target_id,0x71,1);
        }
      }
      FUN_0046e571(spell_id,target_id,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}



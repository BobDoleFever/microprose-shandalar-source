/*
 * Decompiled function: Prompts_Load_004cda70
 * Entry Point: 004cda70
 * Size: 811 bytes
 */
#include "duel.h"


undefined4 Prompts_Load_004cda70(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
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
    uVar1 = 1;
  }
  else {
    if (((flags == 0x6c) && (DAT_00690c48 == target_id)) && (DAT_0068ecb0 == spell_id)) {
      DAT_0068f2d4 = DAT_0068f2d4 + 0x30;
    }
    if (flags == 0x73) {
      iVar2 = FUN_0049b68d(spell_id,target_id,2,2);
      if (iVar2 != 0) {
        arg_19 = 0;
        arg_18_00 = 0;
        arg_17 = 0;
        arg_16 = 0xffffffff;
        arg_15 = 0xffffffff;
        arg_14 = 0xffffffff;
        arg_13 = 0xffffffff;
        arg_12 = 0;
        uVar1 = 0;
        uVar3 = FUN_004521e2(spell_id,target_id);
        iVar2 = FUN_0041bcf0((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uVar3 | 0x20,uVar1,arg_12,arg_13,
                             arg_14,arg_15,arg_16,arg_17,arg_18_00,arg_19);
        if (iVar2 != 0) {
          return 1;
        }
      }
      uVar1 = 0;
    }
    else {
      if ((flags == 0x6d) && (FUN_0042ecaf(spell_id,target_id,2,2), DAT_00681ea4 != 1)) {
        FUN_00434660(s_prompts_txt_00508d4c,s_FLOOD_00508d44);
        arg_20 = &local_c;
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
                          (spell_id,2,1 - spell_id,0x200,2,0,0,uVar3 | 0x20,uVar4,uVar5,iVar2,iVar6,
                           uVar7,uVar8,uVar9,uVar10,uVar11,arg_18,uVar1,arg_20);
        if (iVar2 == 0) {
          DAT_00681ea4 = 1;
        }
        else {
          *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20) = local_c;
          *(undefined4 *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20) = local_8;
          (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        }
      }
      if (flags == 0x72) {
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
                          (*(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20),
                           *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20),
                           (undefined1 *)0x0,spell_id,2,2,0x200,2,0,0,uVar3 | 0x20,uVar4,uVar5,iVar2
                           ,iVar6,uVar7,uVar8,uVar9,uVar10,uVar11);
        if (iVar2 == 0) {
          DAT_00681ea4 = 1;
        }
        else {
          FUN_004a7b83(*(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20),
                       *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20));
        }
        (&DAT_006827b8)
        [*(int *)(&DAT_006827b0 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
         *(int *)(&DAT_006827b4 + target_id * 0x120 + spell_id * 0x5b20) * 0x120] = 0;
      }
      uVar1 = 0;
    }
  }
  return uVar1;
}



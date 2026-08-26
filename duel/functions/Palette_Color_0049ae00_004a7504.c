/*
 * Decompiled function: Palette_Color_0049ae00
 * Entry Point: 004a7504
 * Size: 599 bytes
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
  uint uVar9;
  uint uVar10;
  uint uVar11;
  undefined *arg_18;
  int *arg_20;
  int local_c;
  int local_8;
  
  if (flags == 0x74) {
    FUN_0043071d(0);
    uVar1 = FUN_0041bcf0((int *)0x0,0,spell_id,2,2,0x200,0x44,0,0,0,0,0,0xffffffff,0xffffffff,
                         0xffffffff,0xffffffff,0,0,0);
  }
  else {
    if (((flags == 0x6c) && (DAT_00690c48 == target_id)) && (DAT_0068ecb0 == spell_id)) {
      DAT_0068f2d4 = DAT_0068f2d4 + -0x10;
      FUN_00434660(s_prompts_txt_005061b4,s_DISENCHANT_005061a8);
      arg_20 = &local_c;
      uVar1 = 1;
      arg_18 = &DAT_006679f0;
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
                        (spell_id,2,2,0x200,0x44,0,0,uVar2,uVar3,uVar4,iVar5,iVar6,uVar7,uVar8,uVar9
                         ,uVar10,uVar11,arg_18,uVar1,arg_20);
      if (iVar5 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20) = local_c;
        *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20) = local_8;
        (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 1;
      }
    }
    if (flags == 0x71) {
      local_c = *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20);
      local_8 = *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20);
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
                        (local_c,local_8,(undefined1 *)0x0,spell_id,2,2,0x200,0x44,0,0,uVar2,uVar3,
                         uVar4,iVar5,iVar6,uVar7,uVar8,uVar9,uVar10,uVar11);
      if (iVar5 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        FUN_0046e571(local_c,local_8,2);
      }
      (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      FUN_0046e571(spell_id,target_id,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}



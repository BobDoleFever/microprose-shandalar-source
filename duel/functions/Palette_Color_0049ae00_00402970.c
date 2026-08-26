/*
 * Decompiled function: Palette_Color_0049ae00
 * Entry Point: 00402970
 * Size: 849 bytes
 */
#include "duel.h"


undefined4 Palette_Color_0049ae00(int spell_id,int target_id,int flags)

{
  char cVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined4 arg_11;
  int iVar7;
  undefined4 arg_12;
  uint uVar8;
  undefined4 arg_13;
  uint uVar9;
  undefined4 arg_14;
  uint uVar10;
  undefined4 arg_15;
  uint uVar11;
  undefined4 arg_16;
  uint uVar12;
  undefined4 arg_17;
  undefined *arg_18;
  undefined4 arg_18_00;
  undefined4 arg_19;
  int *arg_20;
  int local_c;
  int local_8;
  
  if (flags == 0x74) {
    arg_19 = 1;
    arg_18_00 = 0;
    arg_17 = 0;
    arg_16 = 0xffffffff;
    arg_15 = 0xffffffff;
    arg_14 = 0xffffffff;
    arg_13 = 0xffffffff;
    arg_12 = 0;
    arg_11 = 0;
    uVar2 = FUN_004521e2(spell_id,target_id);
    uVar2 = FUN_0041bcf0((int *)0x0,0,spell_id,spell_id,spell_id,0x200,2,0,0,uVar2,arg_11,arg_12,
                         arg_13,arg_14,arg_15,arg_16,arg_17,arg_18_00,arg_19);
  }
  else {
    if (((flags == 0x6c) && (DAT_00690c48 == target_id)) && (DAT_0068ecb0 == spell_id)) {
      FUN_00434660(s_prompts_txt_004f2124,s_ENERGYTAP_004f2118);
      arg_20 = &local_c;
      uVar2 = 1;
      arg_18 = &DAT_006679f0;
      uVar12 = 1;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0xffffffff;
      uVar8 = 0xffffffff;
      iVar7 = -1;
      iVar6 = -1;
      uVar5 = 0;
      uVar4 = 0;
      uVar3 = FUN_004521e2(spell_id,target_id);
      iVar6 = Action_ValidateTarget_0041e2a2
                        (spell_id,spell_id,spell_id,0x200,2,0,0,uVar3,uVar4,uVar5,iVar6,iVar7,uVar8,
                         uVar9,uVar10,uVar11,uVar12,arg_18,uVar2,arg_20);
      if (iVar6 == 0) {
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
      uVar12 = 1;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0xffffffff;
      uVar8 = 0xffffffff;
      iVar7 = -1;
      iVar6 = -1;
      uVar5 = 0;
      uVar4 = 0;
      uVar3 = FUN_004521e2(spell_id,target_id);
      iVar6 = Rules_ParseFilter_0041c0ab
                        (local_c,local_8,(undefined1 *)0x0,spell_id,(byte)spell_id,(byte)spell_id,
                         0x200,2,0,0,uVar3,uVar4,uVar5,iVar6,iVar7,uVar8,uVar9,uVar10,uVar11,uVar12)
      ;
      if (iVar6 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        FUN_004a7b83(local_c,local_8);
        cVar1 = (&DAT_004ff597)[*(int *)(&DAT_006826c4 + local_c * 0x5b20 + local_8 * 0x120) * 0x34]
        ;
        iVar6 = FUN_0049aa14((int)(char)(&DAT_004ff598)
                                        [*(int *)(&DAT_006826c4 + local_c * 0x5b20 + local_8 * 0x120
                                                 ) * 0x34],0,99);
        *(int *)(&DAT_0068f2e0 + spell_id * 0x20) =
             *(int *)(&DAT_0068f2e0 + spell_id * 0x20) + cVar1 + iVar6;
        cVar1 = (&DAT_004ff597)[*(int *)(&DAT_006826c4 + local_c * 0x5b20 + local_8 * 0x120) * 0x34]
        ;
        iVar6 = FUN_0049aa14((int)(char)(&DAT_004ff598)
                                        [*(int *)(&DAT_006826c4 + local_c * 0x5b20 + local_8 * 0x120
                                                 ) * 0x34],0,99);
        *(int *)(&DAT_0068f2fc + spell_id * 0x20) =
             *(int *)(&DAT_0068f2fc + spell_id * 0x20) + cVar1 + iVar6;
      }
      (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      FUN_0046e571(spell_id,target_id,1);
    }
    uVar2 = 0;
  }
  return uVar2;
}



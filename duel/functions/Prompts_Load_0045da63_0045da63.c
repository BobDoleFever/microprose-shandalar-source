/*
 * Decompiled function: Prompts_Load_0045da63
 * Entry Point: 0045da63
 * Size: 1021 bytes
 */
#include "duel.h"


undefined4 Prompts_Load_0045da63(int spell_id,int target_id,int flags)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 arg_11;
  int iVar7;
  undefined4 arg_12;
  uint uVar8;
  undefined4 arg_13;
  undefined4 arg_14;
  uint uVar9;
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
  
  if (flags == 0x73) {
    uVar2 = 0;
    if ((*(uint *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) & 0x20010) == 0) {
      arg_19 = 0;
      arg_18_00 = 0;
      arg_17 = 0;
      arg_16 = 0xffffffff;
      uVar1 = (int)*(short *)(&DAT_006826d4 + target_id * 0x120 + spell_id * 0x5b20) - 1U | 0x2000;
      arg_14 = 0xffffffff;
      arg_13 = 0xffffffff;
      arg_12 = 0;
      arg_11 = 0;
      uVar2 = FUN_004521e2(spell_id,target_id);
      uVar2 = FUN_0041bcf0((int *)0x0,0,spell_id,spell_id,spell_id,0x200,2,0,0,uVar2,arg_11,arg_12,
                           arg_13,arg_14,uVar1,arg_16,arg_17,arg_18_00,arg_19);
    }
  }
  else if (flags == 0x90) {
    FUN_0043071d(0);
    uVar2 = 0;
  }
  else {
    if ((flags == 0x6d) &&
       ((*(uint *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) & 0x20010) == 0)) {
      FUN_00434660(s_prompts_txt_004f8aa8,s_STONE_GIANT_004f8a9c);
      arg_20 = &local_10;
      uVar2 = 1;
      arg_18 = &DAT_006679f0;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      iVar3 = FUN_0048b81a(spell_id,target_id,0x32,0xffffffff);
      uVar1 = iVar3 - 1U | 0x2000;
      uVar8 = 0xffffffff;
      iVar7 = -1;
      iVar3 = -1;
      uVar6 = 0;
      uVar5 = 0;
      uVar4 = FUN_004521e2(spell_id,target_id);
      iVar3 = Action_ValidateTarget_0041e2a2
                        (spell_id,spell_id,spell_id,0x200,2,0,0,uVar4,uVar5,uVar6,iVar3,iVar7,uVar8,
                         uVar1,uVar9,uVar10,uVar11,arg_18,uVar2,arg_20);
      if (iVar3 == 0) {
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
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uVar1 = (int)*(short *)(&DAT_006826d4 + target_id * 0x120 + spell_id * 0x5b20) - 1U | 0x2000;
      uVar8 = 0xffffffff;
      iVar7 = -1;
      iVar3 = -1;
      uVar6 = 0;
      uVar5 = 0;
      uVar4 = FUN_004521e2(spell_id,target_id);
      iVar3 = Rules_ParseFilter_0041c0ab
                        (local_10,local_c,(undefined1 *)0x0,spell_id,(byte)spell_id,(byte)spell_id,
                         0x200,2,0,0,uVar4,uVar5,uVar6,iVar3,iVar7,uVar8,uVar1,uVar9,uVar10,uVar11);
      if (iVar3 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        iVar3 = FUN_004a2b00(DAT_00690af0,DAT_0068efa0,DAT_00667994,local_10,local_c);
        if (iVar3 != -1) {
          (&DAT_006826e0)[iVar3 * 0x120 + spell_id * 0x5b20] = 5;
          *(undefined4 *)(&DAT_006826e4 + iVar3 * 0x120 + spell_id * 0x5b20) = 0x20;
          *(undefined4 *)(&DAT_006826fc + local_10 * 0x5b20 + local_c * 0x120) = 0x8000000;
        }
      }
      (&DAT_006827b8)
      [*(int *)(&DAT_006827b4 + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
       *(int *)(&DAT_006827b0 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20] = 0;
    }
    uVar2 = 0;
  }
  return uVar2;
}



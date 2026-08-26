/*
 * Decompiled function: Glue_Subsystem_004e5e3b
 * Entry Point: 004675bf
 * Size: 875 bytes
 */
#include "duel.h"


undefined4 Glue_Subsystem_004e5e3b(int spell_id,int target_id,int flags)

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
  int local_10;
  int local_c;
  
  if (flags == 0x73) {
    if ((*(uint *)(&DAT_006826cc + spell_id * 0x5b20 + target_id * 0x120) & 0x20010) == 0) {
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
      iVar2 = FUN_0041bcf0((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uVar1,arg_11,arg_12,arg_13,arg_14,
                           arg_15,arg_16,arg_17,arg_18_00,arg_19);
      if (iVar2 != 0) {
        return 1;
      }
    }
  }
  else if (flags == 0x90) {
    FUN_0043071d(0);
  }
  else {
    if ((flags == 0x6d) &&
       ((*(uint *)(&DAT_006826cc + spell_id * 0x5b20 + target_id * 0x120) & 0x20010) == 0)) {
      FUN_00434660(s_prompts_txt_004f8e5c,s_RADJAN_SPIRIT_004f8e4c);
      arg_20 = &local_10;
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
        DAT_00681ea4 = 1;
      }
      else {
        *(int *)(&DAT_00682718 + spell_id * 0x5b20 + target_id * 0x120) = local_10;
        *(int *)(&DAT_0068271c + spell_id * 0x5b20 + target_id * 0x120) = local_c;
        (&DAT_006827b8)[spell_id * 0x5b20 + target_id * 0x120] = 1;
        *(uint *)(&DAT_006826cc + spell_id * 0x5b20 + target_id * 0x120) =
             *(uint *)(&DAT_006826cc + spell_id * 0x5b20 + target_id * 0x120) | 0x10;
      }
    }
    if (flags == 0x72) {
      local_10 = *(int *)(&DAT_00682718 + spell_id * 0x5b20 + target_id * 0x120);
      local_c = *(int *)(&DAT_0068271c + spell_id * 0x5b20 + target_id * 0x120);
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
                        (local_10,local_c,(undefined1 *)0x0,spell_id,2,2,0x200,2,0,0,uVar3,uVar4,
                         uVar5,iVar2,iVar6,uVar7,uVar8,uVar9,uVar10,uVar11);
      if (iVar2 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        iVar2 = FUN_004a2b00(DAT_00690af0,DAT_0068efa0,DAT_0066ab00,local_10,local_c);
        if (iVar2 != -1) {
          *(undefined4 *)(&DAT_006826e4 + iVar2 * 0x120 + spell_id * 0x5b20) = 0x20;
        }
        *(undefined4 *)(&DAT_006826fc + local_10 * 0x5b20 + local_c * 0x120) = 0x8000000;
      }
      (&DAT_006827b8)
      [*(int *)(&DAT_006827b0 + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20 +
       *(int *)(&DAT_006827b4 + spell_id * 0x5b20 + target_id * 0x120) * 0x120] = 0;
    }
  }
  return 0;
}



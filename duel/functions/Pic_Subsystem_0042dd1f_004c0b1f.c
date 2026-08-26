/*
 * Decompiled function: Pic_Subsystem_0042dd1f
 * Entry Point: 004c0b1f
 * Size: 1461 bytes
 */
#include "duel.h"


undefined4 Pic_Subsystem_0042dd1f(int spell_id,int target_id,int flags)

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
  undefined4 local_8;
  
  if (((flags == 199) && (((&DAT_006826cc)[target_id * 0x120 + spell_id * 0x5b20] & 2) != 0)) &&
     ((&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20] != -1)) {
    if ((char)(&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20] == DAT_00676510) {
      iVar1 = 0x18 - (&DAT_00681ea8)[(char)(&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20]];
      if (iVar1 < 2) {
        iVar1 = 1;
      }
      DAT_0068f2d4 = DAT_0068f2d4 + iVar1 * 0x18;
    }
    else {
      iVar1 = 0x18 - (&DAT_00681ea8)[(char)(&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20]];
      if (iVar1 < 2) {
        iVar1 = 1;
      }
      DAT_0068f2d4 = DAT_0068f2d4 + iVar1 * -0x18;
    }
  }
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
    uVar2 = FUN_004521e2(spell_id,target_id);
    uVar2 = FUN_0041bcf0((int *)0x0,0,spell_id,2,2,0x200,4,0,0,uVar2,arg_11,arg_12,arg_13,arg_14,
                         arg_15,arg_16,arg_17,arg_18_00,arg_19);
  }
  else {
    if (((flags == 0x6c) && (DAT_00690c48 == target_id)) && (DAT_0068ecb0 == spell_id)) {
      FUN_00434660(s_prompts_txt_00508960,s_FEEDBACK_00508954);
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
                        (spell_id,2,1 - spell_id,0x200,4,0,0,uVar3,uVar4,uVar5,iVar1,iVar6,uVar7,
                         uVar8,uVar9,uVar10,uVar11,arg_18,uVar2,arg_20);
      if (iVar1 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        if (*(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20) == DAT_00676510) {
          DAT_0068f2d4 = DAT_0068f2d4 + 0x30;
        }
        if (*(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20) == DAT_00676504) {
          DAT_0068f2d4 = DAT_0068f2d4 + -0x60;
        }
        *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20) = local_c;
        *(undefined4 *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20) = local_8;
        (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 1;
      }
    }
    if (flags == 0x71) {
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
                        (*(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20),
                         (undefined1 *)0x0,spell_id,2,2,0x200,4,0,0,uVar3,uVar4,uVar5,iVar1,iVar6,
                         uVar7,uVar8,uVar9,uVar10,uVar11);
      if (iVar1 == 0) {
        FUN_0046e571(spell_id,target_id,1);
        DAT_00681ea4 = 1;
      }
      else {
        (&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20] =
             (&DAT_00682718)[target_id * 0x120 + spell_id * 0x5b20];
        *(undefined4 *)(&DAT_006826e8 + target_id * 0x120 + spell_id * 0x5b20) =
             *(undefined4 *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20);
      }
      (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    }
    if (flags == 0x73) {
      if ((((DAT_0068f2c4 == 4) && (DAT_00666458 == DAT_00681eb4)) &&
          ((char)(&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20] == DAT_00666458)) &&
         (((&DAT_006826e4)[target_id * 0x120 + spell_id * 0x5b20] & 1) == 0)) {
        *(uint *)(&DAT_006827d4 + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint *)(&DAT_006827d4 + target_id * 0x120 + spell_id * 0x5b20) | 0x101;
        DAT_00676500 = DAT_00676500 | 3;
        uVar2 = 1;
      }
      else {
        uVar2 = 0;
      }
    }
    else {
      if (((flags == 4) && (DAT_00690c48 == target_id)) && (DAT_0068ecb0 == spell_id)) {
        *(uint *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) | 1;
        DAT_006664ec = 1;
        DAT_0066642c = DAT_0066642c | 1;
      }
      if (flags == 0x86) {
        Mem_AllocOrFree_004afd1c
                  ((int)(char)(&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20],1,spell_id,
                   target_id);
      }
      if (flags == 0x22) {
        *(uint *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) & 0xfffffffe;
      }
      uVar2 = 0;
    }
  }
  return uVar2;
}



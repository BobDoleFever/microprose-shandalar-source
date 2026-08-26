/*
 * Decompiled function: Pic_Subsystem_0042e2d9
 * Entry Point: 004c10d9
 * Size: 1335 bytes
 */
#include "duel.h"


undefined4 Pic_Subsystem_0042e2d9(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
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
  int *arg_20;
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
    uVar1 = FUN_0041bcf0((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uVar1,arg_11,arg_12,arg_13,arg_14,
                         arg_15,arg_16,arg_17,arg_18_00,arg_19);
  }
  else {
    if (((flags == 0x6c) && (DAT_00690c48 == target_id)) && (DAT_0068ecb0 == spell_id)) {
      FUN_00434660(s_prompts_txt_00508978,s_BRAINWASH_0050896c);
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
                        (spell_id,2,1 - spell_id,0x200,2,0,0,uVar2,uVar3,uVar4,iVar5,iVar6,uVar7,
                         uVar8,uVar9,uVar10,uVar11,arg_18,uVar1,arg_20);
      if (iVar5 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20) = local_c;
        *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20) = local_8;
        (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        if (local_c == spell_id) {
          iVar5 = FUN_0048b81a(local_c,local_8,0x32,0xffffffff);
          DAT_0068f2d4 = DAT_0068f2d4 - (iVar5 * 0xc) / 2;
        }
        else {
          iVar5 = FUN_0048b81a(local_c,local_8,0x32,0xffffffff);
          DAT_0068f2d4 = DAT_0068f2d4 + (iVar5 * 0xc) / 2;
        }
      }
    }
    if (flags == 0x71) {
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
                        (*(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20),
                         (undefined1 *)0x0,spell_id,2,2,0x200,2,0,0,uVar2,uVar3,uVar4,iVar5,iVar6,
                         uVar7,uVar8,uVar9,uVar10,uVar11);
      if (iVar5 == 0) {
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
    if (((((DAT_0068f230 == 0xdc) && (DAT_0068f2c4 == 0x15)) &&
         ((DAT_00690c48 == target_id &&
          ((DAT_0068ecb0 == spell_id && (DAT_00666458 == DAT_00681ec4)))))) &&
        (*(int *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) == 0)) &&
       (((char)(&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20] == DAT_00666754 &&
        (*(int *)(&DAT_006826e8 + target_id * 0x120 + spell_id * 0x5b20) == DAT_0068edd0)))) {
      iVar5 = FUN_0049b309(DAT_00666458,7,3);
      if (iVar5 == 0) {
        DAT_00666428 = 1;
      }
      else {
        if (flags == 0x7d) {
          DAT_0066642c = DAT_0066642c | 2;
        }
        if (flags == 0x7e) {
          FUN_0048d878(spell_id,target_id,0x7e,spell_id,0);
          Ai_CalcManaRequirement_004ba890(DAT_00666458,0,3);
          FUN_0048e251();
          if (DAT_00681ea4 == 1) {
            DAT_00666428 = 1;
            DAT_00681ea4 = 0;
          }
          else {
            *(undefined4 *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) = 1;
          }
        }
      }
    }
    if ((flags == 0x79) && (*(int *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) == 0)) {
      iVar5 = FUN_0049b309(DAT_00666458,7,3);
      if (iVar5 == 0) {
        DAT_0066642c = 1;
      }
      uVar1 = 0;
    }
    else {
      if ((flags == 0x22) || (flags == 199)) {
        *(undefined4 *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) = 0;
      }
      uVar1 = 0;
    }
  }
  return uVar1;
}



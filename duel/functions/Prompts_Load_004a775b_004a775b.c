/*
 * Decompiled function: Prompts_Load_004a775b
 * Entry Point: 004a775b
 * Size: 1064 bytes
 */
#include "duel.h"


undefined4 Prompts_Load_004a775b(int spell_id,int target_id,int flags)

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
    FUN_0043071d(0);
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
    uVar1 = FUN_0041bcf0((int *)0x0,0,spell_id,2,2,0x200,0x43,0,0,uVar1,arg_11,arg_12,arg_13,arg_14,
                         arg_15,arg_16,arg_17,arg_18_00,arg_19);
  }
  else {
    if (((flags == 0x6c) && (DAT_00690c48 == target_id)) && (DAT_0068ecb0 == spell_id)) {
      DAT_0068f2d4 = DAT_0068f2d4 + -0x18;
      FUN_00434660(s_prompts_txt_005061c8,s_TWIDDLE_005061c0);
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
                        (spell_id,2,2,0x200,0x43,0,0,uVar2,uVar3,uVar4,iVar5,iVar6,uVar7,uVar8,uVar9
                         ,uVar10,uVar11,arg_18,uVar1,arg_20);
      if (iVar5 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20) = local_c;
        *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20) = local_8;
        (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        if ((DAT_00681eb0._1_1_ & 4) == 0) {
          uVar1 = FUN_0045102d(spell_id,spell_id,target_id,local_c,local_8,s_Tap__Untap__005061d4,
                               (*(uint *)(&DAT_006826cc + local_8 * 0x120 + local_c * 0x5b20) & 0x10
                               ) >> 4);
          *(undefined4 *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) = uVar1;
        }
        else {
          *(undefined4 *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) =
               *(undefined4 *)(&DAT_006826e4 + DAT_0068eccc * 0x120 + DAT_0068ecd0 * 0x5b20);
        }
        if (DAT_00676504 == spell_id) {
          if (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + local_8 * 0x120 + local_c * 0x5b20) * 0x34]
              & 1) != 0) {
            DAT_0068f2d4 = DAT_0068f2d4 + -0x18;
          }
          if (((*(int *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) == 0) &&
              (local_c == DAT_00676504)) ||
             ((*(int *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) == 1 &&
              (local_c == DAT_00676510)))) {
            DAT_0068f2d4 = DAT_0068f2d4 + -0x60;
          }
        }
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
                        (local_c,local_8,(undefined1 *)0x0,spell_id,2,2,0x200,0x43,0,0,uVar2,uVar3,
                         uVar4,iVar5,iVar6,uVar7,uVar8,uVar9,uVar10,uVar11);
      if (iVar5 == 0) {
        DAT_00681ea4 = 1;
      }
      else if (*(int *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) == 0) {
        FUN_004a7b83(local_c,local_8);
      }
      else {
        *(uint *)(&DAT_006826cc + local_c * 0x5b20 + local_8 * 0x120) =
             *(uint *)(&DAT_006826cc + local_c * 0x5b20 + local_8 * 0x120) & 0xffffffef;
      }
      (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      FUN_0046e571(spell_id,target_id,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}



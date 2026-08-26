/*
 * Decompiled function: Prompts_Load_004c2681
 * Entry Point: 004c2681
 * Size: 1562 bytes
 */
#include "duel.h"


undefined4 Prompts_Load_004c2681(int spell_id,int target_id,int flags)

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
  int local_18;
  undefined4 local_14;
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
    uVar1 = FUN_0041bcf0((int *)0x0,0,spell_id,2,2,0x200,4,0,0,uVar1,arg_11,arg_12,arg_13,arg_14,
                         arg_15,arg_16,arg_17,arg_18_00,arg_19);
  }
  else {
    if (((flags == 0x6c) && (DAT_00690c48 == target_id)) && (DAT_0068ecb0 == spell_id)) {
      FUN_00434660(s_prompts_txt_005089f8,s_POWERLEAK_005089ec);
      arg_20 = &local_18;
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
                        (spell_id,2,1 - spell_id,0x200,4,0,0,uVar2,uVar3,uVar4,iVar5,iVar6,uVar7,
                         uVar8,uVar9,uVar10,uVar11,arg_18,uVar1,arg_20);
      if (iVar5 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        *(undefined4 *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20) = local_14;
        *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20) = local_18;
        (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        DAT_0068f2d4 = DAT_0068f2d4 + 0x30;
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
                         (undefined1 *)0x0,spell_id,2,2,0x200,4,0,0,uVar2,uVar3,uVar4,iVar5,iVar6,
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
    if (flags == 0x73) {
      if ((((DAT_0068f2c4 == 4) && (DAT_00666458 == DAT_00681eb4)) &&
          ((char)(&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20] == DAT_00666458)) &&
         (((&DAT_006826e4)[target_id * 0x120 + spell_id * 0x5b20] & 1) == 0)) {
        *(uint *)(&DAT_006827d4 + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint *)(&DAT_006827d4 + target_id * 0x120 + spell_id * 0x5b20) | 0x101;
        DAT_00676500 = DAT_00676500 | 3;
        uVar1 = 1;
      }
      else {
        uVar1 = 0;
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
        local_c = FUN_0049b309((int)(char)(&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20],7,1
                              );
        if (2 < local_c) {
          if (((local_c < 8) && (5 < (int)(&DAT_0068ee78)[spell_id])) &&
             (7 < (int)(&DAT_00681ea8)[spell_id])) {
            local_c = 0;
          }
          else {
            local_c = 2;
          }
        }
        local_8 = FUN_0045102d((int)(char)(&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20],
                               spell_id,target_id,
                               (int)(char)(&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20],
                               *(int *)(&DAT_006826e8 + target_id * 0x120 + spell_id * 0x5b20),
                               s_Take_the_2_damage__Pay_1_mana__t_00508a04,local_c);
        if (local_8 == 0) {
          local_10 = 2;
        }
        else if (local_8 == 1) {
          FUN_0048d878(spell_id,target_id,0x7e,0,0);
          FUN_0042b6b0((int)(char)(&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20],0,1);
          FUN_0048e251();
          if (DAT_00681ea4 == 1) {
            local_10 = 2;
          }
          else {
            local_10 = 1;
          }
        }
        else {
          FUN_0042b6b0((int)(char)(&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20],0,2);
          if (DAT_00681ea4 == 1) {
            local_10 = 2;
          }
          else {
            local_10 = 0;
          }
        }
        Mem_AllocOrFree_004afd1c
                  ((int)(char)(&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20],local_10,
                   DAT_00690af0,DAT_0068efa0);
        DAT_00681ea4 = -1;
      }
      if (flags == 0x22) {
        *(uint *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) & 0xfffffffe;
      }
      uVar1 = 0;
    }
  }
  return uVar1;
}



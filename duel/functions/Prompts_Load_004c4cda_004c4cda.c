/*
 * Decompiled function: Prompts_Load_004c4cda
 * Entry Point: 004c4cda
 * Size: 1831 bytes
 */
#include "duel.h"


undefined4 Prompts_Load_004c4cda(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  int iVar2;
  uint arg_11;
  undefined4 arg_11_00;
  uint arg_12;
  undefined4 arg_12_00;
  uint arg_13;
  undefined4 arg_13_00;
  undefined4 arg_14;
  int arg_15;
  undefined4 arg_15_00;
  uint arg_16;
  undefined4 arg_16_00;
  uint arg_17;
  undefined4 arg_17_00;
  uint arg_18;
  undefined4 arg_18_00;
  uint arg_19;
  undefined4 arg_19_00;
  uint arg_20;
  int local_8;
  
  if ((((flags == 0x6e) &&
       (*(int *)(&DAT_006826c4 + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120) == DAT_0068f104)) &&
      ((char)(&DAT_006826d2)[DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120] == spell_id)) &&
     ((*(int *)(&DAT_006826e8 + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120) == -1 &&
      (*(int *)(&DAT_006826e4 + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120) != 0)))) {
    *(int *)(&DAT_006826f0 + target_id * 0x120 + spell_id * 0x5b20) =
         *(int *)(&DAT_006826f0 + target_id * 0x120 + spell_id * 0x5b20) +
         *(int *)(&DAT_006826e4 + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120);
  }
  if (((DAT_0068f230 == 0xd7) && (DAT_00690c48 == target_id)) &&
     ((DAT_0068ecb0 == spell_id &&
      ((*(int *)(&DAT_006826f0 + target_id * 0x120 + spell_id * 0x5b20) != 0 &&
       (spell_id == DAT_00681ec4)))))) {
    if (flags == 0x7d) {
      DAT_0066642c = DAT_0066642c | 2;
    }
    if (flags == 0x7e) {
      FUN_00467f65(spell_id,target_id,
                   *(int *)(&DAT_006826f0 + target_id * 0x120 + spell_id * 0x5b20));
      *(undefined4 *)(&DAT_006826f0 + target_id * 0x120 + spell_id * 0x5b20) = 0;
    }
  }
  if (flags == 0x74) {
    arg_19_00 = 0;
    arg_18_00 = 0;
    arg_17_00 = 0;
    arg_16_00 = 0xffffffff;
    arg_15_00 = 0xffffffff;
    arg_14 = 0xffffffff;
    arg_13_00 = 0xffffffff;
    arg_12_00 = 0;
    arg_11_00 = 0;
    uVar1 = FUN_004521e2(spell_id,target_id);
    uVar1 = FUN_0041bcf0((int *)0x0,0,spell_id,2,2,0x200,0x40,0,0,uVar1,arg_11_00,arg_12_00,
                         arg_13_00,arg_14,arg_15_00,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
  }
  else {
    if (((flags == 0x6c) && (DAT_00690c48 == target_id)) && (DAT_0068ecb0 == spell_id)) {
      FUN_00434660(s_prompts_txt_00508b08,s_LIVING_ARTIFACT_00508af8);
      iVar2 = FUN_00468831(spell_id,2,target_id);
      DAT_00681ea4 = (uint)(iVar2 == 0);
      if (DAT_00681ea4 != 1) {
        if ((int)(&DAT_00681ea8)[spell_id] < (int)(&DAT_00681ea8)[1 - spell_id]) {
          local_8 = 3;
        }
        else {
          local_8 = 1;
        }
        if (*(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20) == DAT_00676510) {
          DAT_0068f2d4 = DAT_0068f2d4 +
                         (char)(&DAT_004ff598)
                               [*(int *)(&DAT_006826c4 +
                                        *(int *)(&DAT_0068271c +
                                                target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
                                        *(int *)(&DAT_00682718 +
                                                target_id * 0x120 + spell_id * 0x5b20) * 0x5b20) *
                                0x34] * local_8 * 0x18;
        }
        if (*(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20) == DAT_00676504) {
          DAT_0068f2d4 = DAT_0068f2d4 + (uint)(local_8 * 0x18) / 2;
        }
      }
    }
    if (flags == 0x71) {
      arg_20 = 0;
      arg_19 = 0;
      arg_18 = 0;
      arg_17 = 0xffffffff;
      arg_16 = 0xffffffff;
      arg_15 = -1;
      iVar2 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = FUN_004521e2(spell_id,target_id);
      iVar2 = Rules_ParseFilter_0041c0ab
                        (*(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20),
                         (undefined1 *)0x0,spell_id,2,2,0x200,0x40,0,0,arg_11,arg_12,arg_13,iVar2,
                         arg_15,arg_16,arg_17,arg_18,arg_19,arg_20);
      if (iVar2 == 0) {
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
      if ((((DAT_0068f2c4 == 4) && (DAT_00666458 == spell_id)) && (spell_id == DAT_00681eb4)) &&
         ((*(int *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) == 0 &&
          (iVar2 = FUN_004680fc(spell_id,target_id), iVar2 != 0)))) {
        iVar2 = FUN_0048c367((&DAT_006826dd)[target_id * 0x120 + spell_id * 0x5b20]);
        if ((*(int *)(&DAT_00676150 + iVar2 * 4) == 0) ||
           (iVar2 = FUN_0049b68d(spell_id,target_id,7,0), iVar2 != 0)) {
          if (DAT_00676504 == spell_id) {
            DAT_00676500 = DAT_00676500 | 3;
          }
          uVar1 = 1;
        }
        else {
          uVar1 = 0;
        }
      }
      else {
        uVar1 = 0;
      }
    }
    else {
      if (((flags == 0x6d) && (DAT_00690c48 == target_id)) && (DAT_0068ecb0 == spell_id)) {
        iVar2 = FUN_0048c367((&DAT_006826dd)[target_id * 0x120 + spell_id * 0x5b20]);
        if (*(int *)(&DAT_00676150 + iVar2 * 4) != 0) {
          FUN_0042ecaf(spell_id,target_id,0,0);
        }
        if (DAT_00681ea4 != 1) {
          *(int *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) =
               *(int *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) + 1;
          FUN_00467eef(spell_id,target_id);
        }
      }
      if (flags == 0x72) {
        (&DAT_00681ea8)[spell_id] = (&DAT_00681ea8)[spell_id] + 1;
      }
      if ((flags == 0x22) || (flags == 199)) {
        *(undefined4 *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) = 0;
        *(undefined4 *)(&DAT_006826f0 + target_id * 0x120 + spell_id * 0x5b20) = 0;
      }
      uVar1 = 0;
    }
  }
  return uVar1;
}



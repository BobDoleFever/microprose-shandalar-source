/*
 * Decompiled function: FUN_004c4cda
 * Entry Point: 004c4cda
 * Size: 1831 bytes
 */
#include "duel.h"


undefined4 FUN_004c4cda(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int local_8;
  
  if ((((param_3 == 0x6e) &&
       (*(int *)(&DAT_006826c4 + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120) == DAT_0068f104)) &&
      ((char)(&DAT_006826d2)[DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120] == param_1)) &&
     ((*(int *)(&DAT_006826e8 + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120) == -1 &&
      (*(int *)(&DAT_006826e4 + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120) != 0)))) {
    *(int *)(&DAT_006826f0 + param_2 * 0x120 + param_1 * 0x5b20) =
         *(int *)(&DAT_006826f0 + param_2 * 0x120 + param_1 * 0x5b20) +
         *(int *)(&DAT_006826e4 + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120);
  }
  if (((DAT_0068f230 == 0xd7) && (DAT_00690c48 == param_2)) &&
     ((DAT_0068ecb0 == param_1 &&
      ((*(int *)(&DAT_006826f0 + param_2 * 0x120 + param_1 * 0x5b20) != 0 &&
       (param_1 == DAT_00681ec4)))))) {
    if (param_3 == 0x7d) {
      DAT_0066642c = DAT_0066642c | 2;
    }
    if (param_3 == 0x7e) {
      FUN_00467f65(param_1,param_2,
                   *(undefined4 *)(&DAT_006826f0 + param_2 * 0x120 + param_1 * 0x5b20));
      *(undefined4 *)(&DAT_006826f0 + param_2 * 0x120 + param_1 * 0x5b20) = 0;
    }
  }
  if (param_3 == 0x74) {
    uVar1 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
    uVar1 = FUN_0041bcf0(0,0,param_1,2,2,0x200,0x40,0,0,uVar1);
  }
  else {
    if (((param_3 == 0x6c) && (DAT_00690c48 == param_2)) && (DAT_0068ecb0 == param_1)) {
      FUN_00434660(s_prompts_txt_00508b08,s_LIVING_ARTIFACT_00508af8);
      iVar2 = FUN_00468831(param_1,2,param_2);
      DAT_00681ea4 = (uint)(iVar2 == 0);
      if (DAT_00681ea4 != 1) {
        if ((int)(&DAT_00681ea8)[param_1] < (int)(&DAT_00681ea8)[1 - param_1]) {
          local_8 = 3;
        }
        else {
          local_8 = 1;
        }
        if (*(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20) == DAT_00676510) {
          DAT_0068f2d4 = DAT_0068f2d4 +
                         (char)(&DAT_004ff598)
                               [*(int *)(&DAT_006826c4 +
                                        *(int *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20)
                                        * 0x120 + *(int *)(&DAT_00682718 +
                                                          param_2 * 0x120 + param_1 * 0x5b20) *
                                                  0x5b20) * 0x34] * local_8 * 0x18;
        }
        if (*(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20) == DAT_00676504) {
          DAT_0068f2d4 = DAT_0068f2d4 + (uint)(local_8 * 0x18) / 2;
        }
      }
    }
    if (param_3 == 0x71) {
      uVar1 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
      iVar2 = FUN_0041c0ab(*(undefined4 *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20),
                           *(undefined4 *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20),0,
                           param_1,2,2,0x200,0x40,0,0,uVar1);
      if (iVar2 == 0) {
        FUN_0046e571(param_1,param_2,1);
        DAT_00681ea4 = 1;
      }
      else {
        (&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20] =
             (&DAT_00682718)[param_2 * 0x120 + param_1 * 0x5b20];
        *(undefined4 *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20) =
             *(undefined4 *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20);
      }
      (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 0;
    }
    if (param_3 == 0x73) {
      if ((((DAT_0068f2c4 == 4) && (DAT_00666458 == param_1)) && (param_1 == DAT_00681eb4)) &&
         ((*(int *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) == 0 &&
          (iVar2 = FUN_004680fc(param_1,param_2), iVar2 != 0)))) {
        iVar2 = FUN_0048c367((int)(char)(&DAT_006826dd)[param_2 * 0x120 + param_1 * 0x5b20]);
        if ((*(int *)(&DAT_00676150 + iVar2 * 4) == 0) ||
           (iVar2 = FUN_0049b68d(param_1,param_2,7,0), iVar2 != 0)) {
          if (DAT_00676504 == param_1) {
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
      if (((param_3 == 0x6d) && (DAT_00690c48 == param_2)) && (DAT_0068ecb0 == param_1)) {
        iVar2 = FUN_0048c367((int)(char)(&DAT_006826dd)[param_2 * 0x120 + param_1 * 0x5b20]);
        if (*(int *)(&DAT_00676150 + iVar2 * 4) != 0) {
          FUN_0042ecaf(param_1,param_2,0,0);
        }
        if (DAT_00681ea4 != 1) {
          *(int *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) =
               *(int *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) + 1;
          FUN_00467eef(param_1,param_2);
        }
      }
      if (param_3 == 0x72) {
        (&DAT_00681ea8)[param_1] = (&DAT_00681ea8)[param_1] + 1;
      }
      if ((param_3 == 0x22) || (param_3 == 199)) {
        *(undefined4 *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) = 0;
        *(undefined4 *)(&DAT_006826f0 + param_2 * 0x120 + param_1 * 0x5b20) = 0;
      }
      uVar1 = 0;
    }
  }
  return uVar1;
}



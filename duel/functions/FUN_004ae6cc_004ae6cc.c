/*
 * Decompiled function: FUN_004ae6cc
 * Entry Point: 004ae6cc
 * Size: 697 bytes
 */
#include "duel.h"


undefined4 FUN_004ae6cc(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int local_c;
  int local_8;
  
  if (param_3 == 0x74) {
    FUN_0043071d(0);
    if ((((byte)DAT_00681eb0 & 4) == 0) ||
       (iVar1 = FUN_0041bcf0(0,0,param_1,2,2,0x200,0,0,0,0,0,0,DAT_0068f104,0xffffffff,0xffffffff,
                             0xffffffff,0x20,0,0), iVar1 == 0)) {
      uVar2 = 0;
    }
    else {
      uVar2 = 99;
    }
  }
  else {
    if (((param_3 == 0x6c) && (DAT_00690c48 == param_2)) && (DAT_0068ecb0 == param_1)) {
      FUN_00434660(s_prompts_txt_00506550,s_EYE_FOR_EYE_00506544);
      iVar1 = FUN_0041e2a2(param_1,2,2,0x200,0,0,0,0,0,0,DAT_0068f104,0xffffffff,0xffffffff,
                           0xffffffff,0x20,0,0,&DAT_006679f0,1,&local_c);
      if (iVar1 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        if ((int)(&DAT_00681ea8)[1 - param_1] < 1) {
          DAT_0068f2d4 = DAT_0068f2d4 + 1000;
        }
        else {
          DAT_0068f2d4 = DAT_0068f2d4 +
                         (*(int *)(&DAT_006826e4 + local_c * 0x5b20 + local_8 * 0x120) * 100) /
                         (int)(&DAT_00681ea8)[1 - param_1];
        }
        *(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20) = local_c;
        *(int *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20) = local_8;
        (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 1;
      }
    }
    if (param_3 == 0x71) {
      FUN_004afd1c((int)(char)(&DAT_006826d3)
                              [*(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20
                               + *(int *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20) *
                                 0x120],
                   *(undefined4 *)
                    (&DAT_006826e4 +
                    *(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20 +
                    *(int *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20) * 0x120),param_1,
                   param_2);
      FUN_0046e571(param_1,param_2,1);
    }
    uVar2 = 0;
  }
  return uVar2;
}



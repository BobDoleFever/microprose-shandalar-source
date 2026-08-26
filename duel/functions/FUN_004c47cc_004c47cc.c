/*
 * Decompiled function: FUN_004c47cc
 * Entry Point: 004c47cc
 * Size: 1294 bytes
 */
#include "duel.h"


undefined4 FUN_004c47cc(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_3 == 0x74) {
    uVar1 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
    uVar1 = FUN_0041bcf0(0,0,param_1,2,2,0x200,1,0,0,uVar1);
  }
  else {
    if (((param_3 == 0x6c) && (DAT_00690c48 == param_2)) && (DAT_0068ecb0 == param_1)) {
      FUN_00434660(s_prompts_txt_00508aec,s_EVIL_PRESENCE_00508adc);
      iVar2 = FUN_00468550(param_1,1 - param_1,param_2);
      DAT_00681ea4 = (uint)(iVar2 == 0);
      if (DAT_00681ea4 != 1) {
        if (*(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20) == DAT_00676510) {
          DAT_0068f2d4 = DAT_0068f2d4 +
                         (int)(0x40 / (longlong)(*(int *)(&DAT_0068ef6c + DAT_00676510 * 0x20) + 1))
          ;
        }
        if (*(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20) == DAT_00676504) {
          DAT_0068f2d4 = DAT_0068f2d4 + -0x60;
        }
        if (*(int *)(&DAT_006826c4 +
                    *(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20 +
                    *(int *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20) * 0x120) == 0) {
          DAT_0068f2d4 = DAT_0068f2d4 + -0xf0;
        }
      }
    }
    if (param_3 == 0x71) {
      uVar1 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
      iVar2 = FUN_0041c0ab(*(undefined4 *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20),
                           *(undefined4 *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20),0,
                           param_1,2,2,0x200,1,0,0,uVar1);
      if (iVar2 == 0) {
        FUN_0046e571(param_1,param_2,1);
        DAT_00681ea4 = 1;
      }
      else {
        (&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20] =
             (&DAT_00682718)[param_2 * 0x120 + param_1 * 0x5b20];
        *(undefined4 *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20) =
             *(undefined4 *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20);
        *(undefined4 *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) = 1;
        iVar2 = FUN_004af74c(param_1,param_2,
                             *(undefined4 *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20));
        *(int *)(&DAT_006826c4 +
                *(int *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120 +
                (char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20] * 0x5b20) = iVar2 + -1;
        *(uint *)(&DAT_006826fc +
                 *(int *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120 +
                 (char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20] * 0x5b20) =
             *(uint *)(&DAT_006826fc +
                      *(int *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120 +
                      (char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20] * 0x5b20) |
             0x1000000;
      }
      (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 0;
    }
    if ((((param_3 == 0x3c) && ((DAT_00681eb0._2_1_ & 2) == 0)) &&
        ((*(int *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20) == DAT_00690c48 &&
         (((char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20] == DAT_0068ecb0 &&
          (DAT_00690c48 != -1)))))) && (iVar2 = FUN_0048a33f(param_1,param_2), iVar2 != 0)) {
      iVar2 = FUN_004af74c(param_1,param_2,
                           *(undefined4 *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20));
      DAT_0066642c = iVar2 + -1;
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: FUN_004d3f63
 * Entry Point: 004d3f63
 * Size: 885 bytes
 */
#include "duel.h"


undefined4 FUN_004d3f63(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_3 == 0x74) {
    FUN_0043071d(0);
    uVar1 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
    uVar1 = FUN_0041bcf0(0,0,param_1,2,2,0x200,2,0,0,uVar1);
  }
  else {
    if (((param_3 == 0x6c) && (DAT_00690c48 == param_2)) && (DAT_0068ecb0 == param_1)) {
      FUN_00434660(s_prompts_txt_0050904c,s_FLIGHT_00509044);
      iVar2 = FUN_00468130(param_1,param_1,param_2);
      if (iVar2 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        if (*(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20) == DAT_00676510) {
          DAT_0068f2d4 = DAT_0068f2d4 + -0x18;
        }
        if (((&DAT_006826fc)
             [*(int *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20) * 0x120 +
              *(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20] & 0x20) != 0) {
          DAT_0068f2d4 = DAT_0068f2d4 + -99;
        }
      }
    }
    if (param_3 == 0x71) {
      uVar1 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
      iVar2 = FUN_0041c0ab(*(undefined4 *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20),
                           *(undefined4 *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20),0,
                           param_1,2,2,0x200,2,0,0,uVar1);
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
      }
      (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 0;
    }
    if (((*(int *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) != 0) &&
        (*(int *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20) == DAT_00690c48)) &&
       ((*(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20) == DAT_0068ecb0 &&
        ((DAT_00690c48 != -1 && (param_3 == 0x34)))))) {
      DAT_0066642c = DAT_0066642c | 0x20;
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: FUN_004c7d3b
 * Entry Point: 004c7d3b
 * Size: 1153 bytes
 */
#include "duel.h"


undefined4 FUN_004c7d3b(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_3 == 0x74) {
    uVar1 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
    uVar1 = FUN_0041bcf0(0,0,param_1,2,2,0x200,2,0,0,uVar1);
  }
  else {
    if (((param_3 == 0x6c) && (DAT_00690c48 == param_2)) && (DAT_0068ecb0 == param_1)) {
      FUN_00434660(s_prompts_txt_00508bc0,s_GASEOUSFORM_00508bb4);
      iVar2 = FUN_00468130(param_1,2,param_2);
      if (iVar2 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        DAT_00681ea4 = 0;
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
      }
      (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 0;
    }
    if (((param_3 == 0x21) && ((DAT_0068f2c4 == 0x1a || (DAT_0068f2c4 == 0x19)))) &&
       (*(int *)(&DAT_006826c4 + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120) == DAT_0068f104)) {
      if (((&DAT_006826d2)[DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120] ==
           (&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20]) &&
         (*(int *)(&DAT_006826e8 + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120) ==
          *(int *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20))) {
        (&DAT_006826df)[DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120] =
             (&DAT_006826e4)[DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120];
        *(undefined4 *)(&DAT_006826e4 + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120) = 0;
      }
      if (((&DAT_006826d3)[DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120] ==
           (&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20]) &&
         (*(int *)(&DAT_006826ec + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120) ==
          *(int *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20))) {
        (&DAT_006826df)[DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120] =
             (&DAT_006826e4)[DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120];
        *(undefined4 *)(&DAT_006826e4 + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120) = 0;
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}



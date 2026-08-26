/*
 * Decompiled function: FUN_004c73b2
 * Entry Point: 004c73b2
 * Size: 1398 bytes
 */
#include "duel.h"


undefined4 FUN_004c73b2(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int local_8;
  
  if (param_3 == 0x74) {
    uVar1 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
    uVar1 = FUN_0041bcf0(0,0,param_1,2,2,0x200,2,0,0,uVar1);
  }
  else {
    if (((param_3 == 0x6c) && (DAT_00690c48 == param_2)) && (DAT_0068ecb0 == param_1)) {
      FUN_00434660(s_prompts_txt_00508b8c,s_SPIRITLINK_00508b80);
      iVar2 = FUN_00468130(param_1,2,param_2);
      DAT_00681ea4 = (uint)(iVar2 == 0);
      if (DAT_00681ea4 != 1) {
        iVar2 = FUN_0048b81a(*(undefined4 *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20),
                             *(undefined4 *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20),
                             0x32,0xffffffff);
        DAT_0068f2d4 = DAT_0068f2d4 + iVar2 * 0x18;
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
    if (((param_3 == 0x6e) &&
        (*(int *)(&DAT_006826c4 + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120) == DAT_0068f104)) &&
       (((&DAT_006826d3)[DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120] ==
         (&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20] &&
        ((*(int *)(&DAT_006826ec + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120) ==
          *(int *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20) &&
         (*(int *)(&DAT_006826e4 + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120) != 0)))))) {
      *(int *)(&DAT_00682718 +
              param_2 * 0x120 +
              param_1 * 0x5b20 + *(int *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) * 8) =
           DAT_0068ecb0;
      *(int *)(&DAT_0068271c +
              param_2 * 0x120 +
              param_1 * 0x5b20 + *(int *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) * 8) =
           DAT_00690c48;
      *(int *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) =
           *(int *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) + 1;
    }
    if ((((DAT_0068f230 == 0xd7) && (DAT_00690c48 == param_2)) && (DAT_0068ecb0 == param_1)) &&
       ((*(int *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) != 0 &&
        (param_1 == DAT_00681ec4)))) {
      if (param_3 == 0x7d) {
        DAT_0066642c = DAT_0066642c | 2;
      }
      if (param_3 == 0x7e) {
        for (local_8 = 0; local_8 < *(int *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20);
            local_8 = local_8 + 1) {
          (&DAT_00681ea8)[param_1] =
               (&DAT_00681ea8)[param_1] +
               *(int *)(&DAT_006826e4 +
                       *(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20 + local_8 * 8) *
                       0x5b20 + *(int *)(&DAT_0068271c +
                                        param_2 * 0x120 + param_1 * 0x5b20 + local_8 * 8) * 0x120);
        }
        *(undefined4 *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) = 0;
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}



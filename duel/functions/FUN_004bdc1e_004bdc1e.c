/*
 * Decompiled function: FUN_004bdc1e
 * Entry Point: 004bdc1e
 * Size: 2008 bytes
 */
#include "duel.h"


undefined4 FUN_004bdc1e(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  
  if (param_3 == 0x74) {
    uVar1 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
    uVar1 = FUN_0041bcf0(0,0,param_1,2,2,0x200,0x40,0,0,uVar1);
  }
  else {
    if (((param_3 == 0x6c) && (DAT_00690c48 == param_2)) && (DAT_0068ecb0 == param_1)) {
      FUN_00434660(s_prompts_txt_005088f4,s_ANIMATE_ARTIFACT_005088e0);
      uVar1 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0,
                           &DAT_006679f0,1,&local_10);
      iVar2 = FUN_0041e2a2(param_1,2,2,0x200,0x40,0,0,uVar1);
      if (iVar2 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        *(undefined4 *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20) = local_10;
        *(undefined4 *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20) = local_c;
        (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 1;
        DAT_0068f2d4 = DAT_0068f2d4 + -0x18;
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
        if (((&DAT_004ff594)
             [*(int *)(&DAT_006826c4 +
                      *(int *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120 +
                      (char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20] * 0x5b20) * 0x34] &
            0x42) == 0x40) {
          local_8 = FUN_004af68f(*(undefined4 *)
                                  (&DAT_006826c4 +
                                  *(int *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20) *
                                  0x120 + (char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20]
                                          * 0x5b20));
          if (local_8 != -1) {
            (&DAT_004ff594)[local_8 * 0x34] = 0x42;
            *(short *)(&DAT_004ff59c + local_8 * 0x34) =
                 (short)(char)(&DAT_004ff598)
                              [*(int *)(&DAT_006826c4 +
                                       *(int *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20)
                                       * 0x120 + (char)(&DAT_006826d2)
                                                       [param_2 * 0x120 + param_1 * 0x5b20] * 0x5b20
                                       ) * 0x34];
            *(undefined2 *)(&DAT_004ff59a + local_8 * 0x34) =
                 *(undefined2 *)(&DAT_004ff59c + local_8 * 0x34);
            *(int *)(&DAT_006826c8 + param_2 * 0x120 + param_1 * 0x5b20) = local_8;
            *(int *)(&DAT_006826c4 +
                    *(int *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120 +
                    (char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20] * 0x5b20) = local_8;
            *(uint *)(&DAT_006826fc +
                     *(int *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120 +
                     (char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20] * 0x5b20) =
                 *(uint *)(&DAT_006826fc +
                          *(int *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120 +
                          (char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20] * 0x5b20) |
                 0x1000000;
          }
        }
        else {
          *(undefined4 *)(&DAT_006826c8 + param_2 * 0x120 + param_1 * 0x5b20) =
               *(undefined4 *)
                (&DAT_006826c4 +
                *(int *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120 +
                (char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20] * 0x5b20);
        }
      }
      (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 0;
    }
    if (((param_3 == 0x77) && (DAT_00690c48 == param_2)) &&
       ((DAT_0068ecb0 == param_1 &&
        (*(int *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20) != -1)))) {
      (&DAT_004ff594)
      [*(int *)(&DAT_006826c4 +
               *(int *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120 +
               (char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20] * 0x5b20) * 0x34] =
           (&DAT_004ff594)
           [*(int *)(&DAT_006826c4 +
                    *(int *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120 +
                    (char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20] * 0x5b20) * 0x34] &
           0xfd;
    }
    if (((param_3 == 0x3c) && ((DAT_00681eb0._2_1_ & 2) == 0)) &&
       ((*(int *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20) == DAT_00690c48 &&
        ((((char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20] == DAT_0068ecb0 &&
          (DAT_00690c48 != -1)) && (iVar2 = FUN_0048a33f(param_1,param_2), iVar2 != 0)))))) {
      DAT_0066642c = *(undefined4 *)(&DAT_006826c8 + param_2 * 0x120 + param_1 * 0x5b20);
      *(uint *)(&DAT_006826f8 +
               *(int *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120 +
               (char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20] * 0x5b20) =
           *(uint *)(&DAT_006826f8 +
                    *(int *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120 +
                    (char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20] * 0x5b20) | 0x40;
    }
    uVar1 = 0;
  }
  return uVar1;
}



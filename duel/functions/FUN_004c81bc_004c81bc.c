/*
 * Decompiled function: FUN_004c81bc
 * Entry Point: 004c81bc
 * Size: 1804 bytes
 */
#include "duel.h"


undefined4 FUN_004c81bc(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int local_10;
  
  if (param_3 == 0x74) {
    uVar1 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
    uVar1 = FUN_0041bcf0(0,0,param_1,2,2,0x200,2,0,0,uVar1);
  }
  else {
    if (((param_3 == 0x6c) && (DAT_00690c48 == param_2)) && (DAT_0068ecb0 == param_1)) {
      FUN_00434660(s_prompts_txt_00508bd8,s_BACKFIRE_00508bcc);
      iVar2 = FUN_00468130(param_1,1 - param_1,param_2);
      DAT_00681ea4 = (uint)(iVar2 == 0);
      if (DAT_00681ea4 != 1) {
        if (*(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20) == DAT_00676510) {
          iVar2 = FUN_0048b81a(*(undefined4 *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20),
                               *(undefined4 *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20),
                               0x32,0xffffffff);
          DAT_0068f2d4 = DAT_0068f2d4 + iVar2 * 0xc;
        }
        else {
          DAT_0068f2d4 = DAT_0068f2d4 + -0x18;
        }
        (&DAT_006826d3)[param_2 * 0x120 + param_1 * 0x5b20] = 0xff;
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
    if ((((param_3 == 0x6e) &&
         (*(int *)(&DAT_006826c4 + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120) == DAT_0068f104))
        && ((*(int *)(&DAT_006826e8 + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120) == -1 &&
            (((char)(&DAT_006826d2)[DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120] == param_1 &&
             (*(int *)(&DAT_006826ec + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120) ==
              *(int *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20))))))) &&
       ((&DAT_006826d3)[DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120] ==
        (&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20])) {
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
        for (local_10 = 0; local_10 < *(int *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20);
            local_10 = local_10 + 1) {
          FUN_004afd1c((int)(char)(&DAT_006826d3)
                                  [*(int *)(&DAT_0068271c +
                                           param_2 * 0x120 + param_1 * 0x5b20 + local_10 * 8) *
                                   0x120 + *(int *)(&DAT_00682718 +
                                                   param_2 * 0x120 + param_1 * 0x5b20 + local_10 * 8
                                                   ) * 0x5b20],
                       *(undefined4 *)
                        (&DAT_006826e4 +
                        *(int *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20 + local_10 * 8)
                        * 0x120 + *(int *)(&DAT_00682718 +
                                          param_2 * 0x120 + param_1 * 0x5b20 + local_10 * 8) *
                                  0x5b20),param_1,param_2);
        }
        *(undefined4 *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) = 0;
      }
    }
    if (((param_3 == 0x8a) &&
        (*(int *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20) == DAT_00690c48)) &&
       (((char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20] == DAT_0068ecb0 &&
        (DAT_00690c48 != -1)))) {
      DAT_0069340c = DAT_0069340c +
                     *(short *)(&DAT_006826d4 +
                               *(int *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120
                               + (char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20] * 0x5b20)
                     * 0x18;
    }
    uVar1 = 0;
  }
  return uVar1;
}



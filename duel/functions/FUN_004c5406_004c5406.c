/*
 * Decompiled function: FUN_004c5406
 * Entry Point: 004c5406
 * Size: 1300 bytes
 */
#include "duel.h"


undefined4 FUN_004c5406(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int local_10;
  int local_c;
  
  if (param_3 == 0x74) {
    uVar1 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
    uVar1 = FUN_0041bcf0(0,0,param_1,2,2,0x200,1,0,0,uVar1);
  }
  else {
    if (((param_3 == 0x6c) && (DAT_00690c48 == param_2)) && (DAT_0068ecb0 == param_1)) {
      FUN_00434660(s_prompts_txt_00508b1c,s_BLIGHT_00508b14);
      uVar1 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0,
                           &DAT_006679f0,1,&local_10);
      iVar2 = FUN_0041e2a2(param_1,2,2,0x200,1,0,0,uVar1);
      if (iVar2 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        *(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20) = local_10;
        *(int *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20) = local_c;
        (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 1;
        if (local_10 == DAT_00676510) {
          iVar2 = FUN_0048c367((int)(char)(&DAT_004ff596)
                                          [*(int *)(&DAT_006826c4 +
                                                   local_10 * 0x5b20 + local_c * 0x120) * 0x34]);
          DAT_0068f2d4 = DAT_0068f2d4 +
                         (int)(0x60 / (longlong)
                                      (*(int *)(&DAT_0068ef50 + iVar2 * 4 + DAT_00676510 * 0x20) + 1
                                      ));
        }
        if (local_10 == DAT_00676504) {
          DAT_0068f2d4 = DAT_0068f2d4 + -0x18;
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
        if (*(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20) == DAT_00676504) {
          *(uint *)(&DAT_006826cc +
                   *(int *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20) * 0x120 +
                   *(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20) =
               *(uint *)(&DAT_006826cc +
                        *(int *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20) * 0x120 +
                        *(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20) |
               0x40000;
        }
      }
      (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 0;
    }
    if ((((param_3 == 0x81) &&
         (*(int *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20) == DAT_00690c48)) &&
        (((char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20] == DAT_0068ecb0 &&
         ((DAT_00690c48 != -1 && (((&DAT_006826cc)[param_2 * 0x120 + param_1 * 0x5b20] & 0x20) == 0)
          ))))) && (((&DAT_006826e4)[param_2 * 0x120 + param_1 * 0x5b20] & 2) == 0)) {
      iVar2 = FUN_004a2b00(param_1,param_2,DAT_00681ec8,
                           (int)(char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20],
                           *(undefined4 *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20));
      if (iVar2 != -1) {
        (&DAT_006826e0)[iVar2 * 0x120 + param_1 * 0x5b20] = 5;
      }
      *(uint *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) =
           *(uint *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) | 2;
    }
    uVar1 = 0;
  }
  return uVar1;
}



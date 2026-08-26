/*
 * Decompiled function: FUN_004ad480
 * Entry Point: 004ad480
 * Size: 519 bytes
 */
#include "duel.h"


uint FUN_004ad480(int arg_1,int arg_2,int arg_3)

{
  uint uVar1;
  int local_10;
  
  if (arg_3 == 0x74) {
    FUN_0043071d(0);
    uVar1 = *(uint *)(&DAT_0066aad0 + arg_1 * 4) & 2;
  }
  else {
    if (((arg_3 == 0x6c) && (DAT_00690c48 == arg_2)) && (DAT_0068ecb0 == arg_1)) {
      if (local_10 == -1) {
        DAT_00681ea4 = 1;
      }
      else {
        *(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) = local_10;
        (&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] = (undefined1)DAT_0068eef0;
      }
    }
    if (arg_3 == 0x71) {
      if (*(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) != -1) {
        FUN_0049b235(arg_1,1,(int)(char)(&DAT_004ff597)
                                        [*(int *)(&DAT_006826c4 +
                                                 *(int *)(&DAT_006826e8 +
                                                         arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                                                 (char)(&DAT_006826d2)
                                                       [arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) *
                                         0x34] +
                             (int)(char)(&DAT_004ff598)
                                        [*(int *)(&DAT_006826c4 +
                                                 *(int *)(&DAT_006826e8 +
                                                         arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                                                 (char)(&DAT_006826d2)
                                                       [arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) *
                                         0x34]);
        FUN_0046e571((int)(char)(&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20],
                     *(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20),2);
      }
      (&DAT_006827b8)[arg_2 * 0x120 + arg_1 * 0x5b20] = 0;
      FUN_0046e571(arg_1,arg_2,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: FUN_004c5e5f
 * Entry Point: 004c5e5f
 * Size: 474 bytes
 */
#include "duel.h"


undefined4 FUN_004c5e5f(int arg_1,int arg_2,int arg_3)

{
  byte arg_1_00;
  undefined4 uVar1;
  int arg_2_00;
  int arg_3_00;
  int local_c;
  int local_8;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (((arg_3 == 0x6c) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) {
      DAT_0068f2d4 = DAT_0068f2d4 + 0x30;
    }
    if (((arg_3 == 0x81) &&
        (((&DAT_004ff594)
          [*(int *)(&DAT_006826c4 + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120) * 0x34] & 1) != 0)
        ) && (DAT_0068f0f4 != -1)) {
      FUN_0049b235(DAT_0068ecb0,DAT_0068f0f4,1);
    }
    if (((arg_3 == 0x7f) &&
        (((&DAT_004ff594)
          [*(int *)(&DAT_006826c4 + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120) * 0x34] & 1) != 0)
        ) && (((&DAT_006826cc)[DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120] & 0x10) == 0)) {
      arg_1_00 = (&DAT_006826dc)[DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120];
      local_8 = 0;
      for (local_c = 0; local_c < 7; local_c = local_c + 1) {
        if (((int)(char)arg_1_00 & 1 << ((byte)local_c & 0x1f)) != 0) {
          local_8 = local_8 + 1;
        }
      }
      if (local_8 < 1) {
        arg_3_00 = 1;
        arg_2_00 = FUN_0048c367(arg_1_00);
        FUN_0049b1a9(DAT_0068ecb0,arg_2_00,arg_3_00);
      }
      else {
        FUN_0049af5c(DAT_0068ecb0,(int)(char)arg_1_00,1);
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: FUN_004c258e
 * Entry Point: 004c258e
 * Size: 243 bytes
 */
#include "duel.h"


undefined4 FUN_004c258e(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (((arg_3 == 0x6c) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) {
      DAT_0068f2d4 = DAT_0068f2d4 + (*(int *)(&DAT_0068ee70 + (7 - arg_1) * 4) * 0x18) / 2;
    }
    if (((((&DAT_006826cc)[arg_1 * 0x5b20 + arg_2 * 0x120] & 0x20) == 0) && (arg_3 == 0x7c)) &&
       ((arg_1 != DAT_0068ecb0 &&
        (((&DAT_004ff594)
          [*(int *)(&DAT_006826c4 + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120) * 0x34] & 0x40) !=
         0)))) {
      (&DAT_00681ea8)[arg_1] = (&DAT_00681ea8)[arg_1] + 1;
    }
    uVar1 = 0;
  }
  return uVar1;
}



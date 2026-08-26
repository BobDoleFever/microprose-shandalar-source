/*
 * Decompiled function: FUN_004c33f8
 * Entry Point: 004c33f8
 * Size: 283 bytes
 */
#include "duel.h"


undefined4 FUN_004c33f8(int arg_1,int arg_2,int arg_3)

{
  if ((((((&DAT_004ff594)[arg_3 * 0x34] & 4) != 0) &&
       (*(int *)(&DAT_006826e8 + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120) ==
        *(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20))) &&
      ((&DAT_006826d2)[DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120] ==
       (&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20])) &&
     ((*(int *)(&DAT_006826c4 + arg_2 * 0x120 + arg_1 * 0x5b20) != 0x29 &&
      ((DAT_0068ecb0 != arg_1 || (DAT_00690c48 != arg_2)))))) {
    FUN_0046e571(arg_1,arg_2,1);
  }
  return 0;
}



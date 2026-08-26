/*
 * Decompiled function: FUN_004631b8
 * Entry Point: 004631b8
 * Size: 269 bytes
 */
#include "duel.h"


undefined4 FUN_004631b8(int arg_1,int arg_2,int arg_3)

{
  if ((((arg_3 == 0x85) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) &&
     ((arg_1 == DAT_00666458 && (DAT_00681eb4 == arg_1)))) {
    *(uint *)(&DAT_006827d4 + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(uint *)(&DAT_006827d4 + arg_2 * 0x120 + arg_1 * 0x5b20) | 1;
    (&DAT_006827da)[arg_2 * 0x120 + arg_1 * 0x5b20] =
         (&DAT_006827da)[arg_2 * 0x120 + arg_1 * 0x5b20] + '\x01';
  }
  if (arg_3 == 0x86) {
    FUN_0046e571(DAT_00690af0,DAT_0068efa0,1);
  }
  if ((arg_3 == 199) && ((int)(&DAT_0068ef58)[arg_1 * 8] < 1)) {
    FUN_0046e571(arg_1,arg_2,1);
  }
  return 0;
}



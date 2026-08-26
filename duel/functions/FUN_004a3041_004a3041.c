/*
 * Decompiled function: FUN_004a3041
 * Entry Point: 004a3041
 * Size: 269 bytes
 */
#include "duel.h"


undefined4 FUN_004a3041(int arg_1,int arg_2,int arg_3)

{
  if (((arg_3 == 0x22) || (arg_3 == 199)) &&
     ((char)(&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] == DAT_00666458)) {
    if (*(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) == 0) {
      *(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) + 1;
    }
    else {
      *(uint *)(&DAT_006826f8 +
               *(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
               (char)(&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) =
           *(uint *)(&DAT_006826f8 +
                    *(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                    (char)(&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) & 0xffff7fff;
      FUN_0046e571(arg_1,arg_2,1);
    }
  }
  return 0;
}



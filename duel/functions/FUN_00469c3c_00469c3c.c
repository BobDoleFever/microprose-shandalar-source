/*
 * Decompiled function: FUN_00469c3c
 * Entry Point: 00469c3c
 * Size: 238 bytes
 */
#include "duel.h"


undefined4 FUN_00469c3c(int arg_1,int arg_2,int arg_3)

{
  if ((((arg_3 == 0x82) &&
       (*(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) == DAT_00690c48)) &&
      ((char)(&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] == DAT_0068ecb0)) &&
     (DAT_00690c48 != -1)) {
    *(uint *)(&DAT_006827c8 +
             *(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
             (char)(&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) =
         *(uint *)(&DAT_006827c8 +
                  *(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                  (char)(&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) & 0xfffffffc;
    FUN_0046e571(arg_1,arg_2,1);
  }
  return 0;
}



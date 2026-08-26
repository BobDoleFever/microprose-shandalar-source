/*
 * Decompiled function: FUN_004a586e
 * Entry Point: 004a586e
 * Size: 376 bytes
 */
#include "duel.h"


undefined4 FUN_004a586e(int arg_1,int arg_2,int arg_3)

{
  if (((&DAT_006826f8)
       [*(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
        (char)(&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20] & 0x80) != 0) {
    (&DAT_006826e0)
    [*(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
     (char)(&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20] = 4;
  }
  if ((arg_3 == 0x22) || (arg_3 == 199)) {
    if ((&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] != -1) {
      *(undefined4 *)
       (&DAT_006826fc +
       *(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
       (char)(&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) = 0x8000000;
    }
    FUN_0046e571(arg_1,arg_2,1);
  }
  return 0;
}



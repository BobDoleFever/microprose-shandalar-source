/*
 * Decompiled function: FUN_0046275d
 * Entry Point: 0046275d
 * Size: 382 bytes
 */
#include "duel.h"


undefined4 FUN_0046275d(int arg_1,int arg_2,int arg_3)

{
  if (((arg_3 == 0x77) &&
      (((&DAT_004ff594)
        [*(int *)(&DAT_006826c4 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) * 0x34] & 2) != 0))
     && (DAT_0066642c < 1)) {
    *(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) + 1;
  }
  if ((arg_3 == 0x22) || (arg_3 == 199)) {
    *(short *)(&DAT_006826d8 + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(short *)(&DAT_006826d8 + arg_2 * 0x120 + arg_1 * 0x5b20) +
         (short)*(undefined4 *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20);
    *(short *)(&DAT_006826da + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(short *)(&DAT_006826da + arg_2 * 0x120 + arg_1 * 0x5b20) +
         (short)*(undefined4 *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20);
    *(undefined4 *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
  }
  return 0;
}



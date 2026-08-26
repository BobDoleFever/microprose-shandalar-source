/*
 * Decompiled function: FUN_004a43c4
 * Entry Point: 004a43c4
 * Size: 260 bytes
 */
#include "duel.h"


undefined4 FUN_004a43c4(int arg_1,int arg_2,int arg_3)

{
  if ((arg_3 == 0x21) &&
     (((DAT_0068f2c4 == 0x1a || (DAT_0068f2c4 == 0x19)) &&
      (((&DAT_004ff594)
        [*(int *)(&DAT_006826c4 +
                 *(int *)(&DAT_006826ec + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120) * 0x120 +
                 (char)(&DAT_006826d3)[DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120] * 0x5b20) *
         0x34] & 2) != 0)))) {
    *(undefined4 *)(&DAT_006826e4 + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120) = 0;
  }
  if ((arg_3 == 0x22) || (arg_3 == 199)) {
    FUN_0046e571(arg_1,arg_2,1);
  }
  return 0;
}



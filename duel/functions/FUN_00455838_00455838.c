/*
 * Decompiled function: FUN_00455838
 * Entry Point: 00455838
 * Size: 373 bytes
 */
#include "duel.h"


undefined4 FUN_00455838(int arg_1,int arg_2,int arg_3)

{
  if ((((arg_3 == 0x21) && (DAT_0068f2c4 == 0x1a)) &&
      (((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0)) &&
     ((((char)(&DAT_006826d2)[DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20] == arg_1 &&
       (*(int *)(&DAT_006826e8 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) == -1)) &&
      (((&DAT_004ff594)
        [*(int *)(&DAT_006826c4 +
                 *(int *)(&DAT_006826ec + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) * 0x120 +
                 (char)(&DAT_006826d3)[DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20] * 0x5b20) *
         0x34] & 0x40) != 0)))) {
    (&DAT_006826d2)[DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20] = (undefined1)arg_1;
    *(int *)(&DAT_006826e8 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) = arg_2;
  }
  return 0;
}



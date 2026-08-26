/*
 * Decompiled function: FUN_0045470b
 * Entry Point: 0045470b
 * Size: 322 bytes
 */
#include "duel.h"


undefined4 FUN_0045470b(int arg1,int arg2)

{
  if ((((*(int *)(&DAT_006826c4 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) == DAT_0068f104) &&
       (*(int *)(&DAT_006826e8 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) == arg2)) &&
      ((char)(&DAT_006826d2)[DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20] == arg1)) &&
     (((&DAT_004ff594)
       [*(int *)(&DAT_006826c4 +
                *(int *)(&DAT_006826ec + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) * 0x120 +
                (char)(&DAT_006826d3)[DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20] * 0x5b20) * 0x34
       ] & 0x40) != 0)) {
    *(undefined4 *)(&DAT_006826e4 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) = 0;
  }
  return 0;
}



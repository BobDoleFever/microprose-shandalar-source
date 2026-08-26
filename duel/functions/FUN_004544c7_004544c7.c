/*
 * Decompiled function: FUN_004544c7
 * Entry Point: 004544c7
 * Size: 258 bytes
 */
#include "duel.h"


undefined4 FUN_004544c7(int arg1,int arg2)

{
  if ((((*(int *)(&DAT_006826c4 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) == DAT_0068f104) &&
       (*(int *)(&DAT_006826e8 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) == arg2)) &&
      ((char)(&DAT_006826d2)[DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20] == arg1)) &&
     (*(int *)(&DAT_004ff590 +
              *(int *)(&DAT_006826c4 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) * 0x34) ==
      0x197)) {
    *(undefined4 *)(&DAT_006826e4 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) = 0;
  }
  return 0;
}



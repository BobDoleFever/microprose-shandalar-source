/*
 * Decompiled function: FUN_0048e251
 * Entry Point: 0048e251
 * Size: 177 bytes
 */
#include "duel.h"


undefined4 FUN_0048e251(void)

{
  if (0 < DAT_006764b8) {
    DAT_006764b8 = DAT_006764b8 + -1;
    if (DAT_0068eee0 ==
        *(int *)(&DAT_006826c4 +
                *(int *)(&DAT_0068efb4 + DAT_006764b8 * 8) * 0x120 +
                (&DAT_0068efb0)[DAT_006764b8 * 2] * 0x5b20)) {
      *(undefined4 *)
       (&DAT_006826c4 +
       *(int *)(&DAT_0068efb4 + DAT_006764b8 * 8) * 0x120 +
       (&DAT_0068efb0)[DAT_006764b8 * 2] * 0x5b20) = 0xffffffff;
    }
    (&DAT_0068efb0)[DAT_006764b8 * 2] = 0xffffffff;
  }
  return 0;
}



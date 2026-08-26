/*
 * Decompiled function: Magic_DiscardToHandSize
 * Entry Point: 00475bb0
 * Size: 177 bytes
 */
#include "magic.h"


undefined4 Magic_DiscardToHandSize(void)

{
  if (0 < DAT_006a3f78) {
    DAT_006a3f78 = DAT_006a3f78 + -1;
    if (DAT_006fd3f4 ==
        *(int *)(&g_CardSlot_CardId +
                *(int *)(&DAT_006fecc4 + DAT_006a3f78 * 8) * 0x120 +
                (&DAT_006fecc0)[DAT_006a3f78 * 2] * 0x5b20)) {
      *(undefined4 *)
       (&g_CardSlot_CardId +
       *(int *)(&DAT_006fecc4 + DAT_006a3f78 * 8) * 0x120 +
       (&DAT_006fecc0)[DAT_006a3f78 * 2] * 0x5b20) = 0xffffffff;
    }
    (&DAT_006fecc0)[DAT_006a3f78 * 2] = 0xffffffff;
  }
  return 0;
}



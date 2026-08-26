/*
 * Decompiled function: FUN_10009244
 * Entry Point: 10009244
 * Size: 356 bytes
 */
#include "deckdll.h"


void FUN_10009244(void)

{
  int local_8;
  
  for (local_8 = 0; local_8 < 6; local_8 = local_8 + 1) {
    *(int32_t *)(&DAT_10205b20 + local_8 * 0x1c38) = (&DAT_101c12e0)[local_8 * 0x70e];
    *(int32_t *)(&DAT_10205fd4 + local_8 * 0x1c38) = (&DAT_101c1794)[local_8 * 0x70e];
    *(int32_t *)(&DAT_10206488 + local_8 * 0x1c38) = (&DAT_101c1c48)[local_8 * 0x70e];
    *(int32_t *)(&DAT_1020693c + local_8 * 0x1c38) = (&DAT_101c20fc)[local_8 * 0x70e];
    *(int32_t *)(&DAT_10206df0 + local_8 * 0x1c38) = (&DAT_101c25b0)[local_8 * 0x70e];
    *(int32_t *)(&DAT_102072a4 + local_8 * 0x1c38) = (&DAT_101c2a64)[local_8 * 0x70e];
  }
  return;
}



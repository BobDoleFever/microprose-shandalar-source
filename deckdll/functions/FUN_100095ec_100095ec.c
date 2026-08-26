/*
 * Decompiled function: FUN_100095ec
 * Entry Point: 100095ec
 * Size: 224 bytes
 */
#include "deckdll.h"


void FUN_100095ec(void)

{
  int local_8;
  
  for (local_8 = 0; local_8 < 6; local_8 = local_8 + 1) {
    *(int32_t *)(&DAT_10205b20 + local_8 * 0x1c38) = 0;
    *(int32_t *)(&DAT_10205fd4 + local_8 * 0x1c38) = 0;
    *(int32_t *)(&DAT_10206488 + local_8 * 0x1c38) = 0;
    *(int32_t *)(&DAT_1020693c + local_8 * 0x1c38) = 0;
    *(int32_t *)(&DAT_10206df0 + local_8 * 0x1c38) = 0;
    *(int32_t *)(&DAT_102072a4 + local_8 * 0x1c38) = 0;
  }
  return;
}



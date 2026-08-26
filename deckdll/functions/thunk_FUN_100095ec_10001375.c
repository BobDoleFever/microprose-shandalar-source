/*
 * Decompiled function: thunk_FUN_100095ec
 * Entry Point: 10001375
 * Size: 5 bytes
 */
#include "deckdll.h"


void thunk_FUN_100095ec(void)

{
  int iStack_8;
  
  for (iStack_8 = 0; iStack_8 < 6; iStack_8 = iStack_8 + 1) {
    *(int32_t *)(&DAT_10205b20 + iStack_8 * 0x1c38) = 0;
    *(int32_t *)(&DAT_10205fd4 + iStack_8 * 0x1c38) = 0;
    *(int32_t *)(&DAT_10206488 + iStack_8 * 0x1c38) = 0;
    *(int32_t *)(&DAT_1020693c + iStack_8 * 0x1c38) = 0;
    *(int32_t *)(&DAT_10206df0 + iStack_8 * 0x1c38) = 0;
    *(int32_t *)(&DAT_102072a4 + iStack_8 * 0x1c38) = 0;
  }
  return;
}



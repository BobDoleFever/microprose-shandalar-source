/*
 * Decompiled function: thunk_FUN_100093a8
 * Entry Point: 10001771
 * Size: 5 bytes
 */
#include "deckdll.h"


void thunk_FUN_100093a8(void)

{
  int iStack_8;
  
  for (iStack_8 = 0; iStack_8 < 6; iStack_8 = iStack_8 + 1) {
    (&DAT_101c12e0)[iStack_8 * 0x70e] = *(int32_t *)(&DAT_10205b20 + iStack_8 * 0x1c38);
    (&DAT_101c1794)[iStack_8 * 0x70e] = *(int32_t *)(&DAT_10205fd4 + iStack_8 * 0x1c38);
    (&DAT_101c1c48)[iStack_8 * 0x70e] = *(int32_t *)(&DAT_10206488 + iStack_8 * 0x1c38);
    (&DAT_101c20fc)[iStack_8 * 0x70e] = *(int32_t *)(&DAT_1020693c + iStack_8 * 0x1c38);
    (&DAT_101c25b0)[iStack_8 * 0x70e] = *(int32_t *)(&DAT_10206df0 + iStack_8 * 0x1c38);
    (&DAT_101c2a64)[iStack_8 * 0x70e] = *(int32_t *)(&DAT_102072a4 + iStack_8 * 0x1c38);
  }
  return;
}



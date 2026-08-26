/*
 * Decompiled function: FUN_1000ef86
 * Entry Point: 1000ef86
 * Size: 152 bytes
 */
#include "deckdll.h"


int32_t FUN_1000ef86(uint32_t *x,int y,int width,int height)

{
  uint32_t uval_1;
  int32_t uval_2;
  int32_t local_14;
  int32_t local_10;
  int32_t local_8;
  
  for (local_14 = 0; local_14 < y; local_14 = local_14 + 1) {
    local_10 = 0;
    local_8 = *x;
    for (; local_10 < width * 3; local_10 = local_10 + 3) {
      uval_1 = *(uint32_t *)(local_10 + 3 + (int)x);
      uval_2 = thunk_FUN_1000ebea(local_8);
      *(int32_t *)(local_10 + (int)x) = uval_2;
      local_8 = uval_1;
    }
    x = (uint32_t *)((int)x + height + width * 3);
  }
  return 0;
}



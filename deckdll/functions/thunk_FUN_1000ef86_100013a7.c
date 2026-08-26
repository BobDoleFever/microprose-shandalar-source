/*
 * Decompiled function: thunk_FUN_1000ef86
 * Entry Point: 100013a7
 * Size: 5 bytes
 */
#include "deckdll.h"


int32_t thunk_FUN_1000ef86(uint32_t *x,int y,int width,int height)

{
  uint32_t uval_1;
  int32_t uval_2;
  int32_t uStack_14;
  int32_t uStack_10;
  int32_t uStack_8;
  
  for (uStack_14 = 0; uStack_14 < y; uStack_14 = uStack_14 + 1) {
    uStack_10 = 0;
    uStack_8 = *x;
    for (; uStack_10 < width * 3; uStack_10 = uStack_10 + 3) {
      uval_1 = *(uint32_t *)(uStack_10 + 3 + (int)x);
      uval_2 = thunk_FUN_1000ebea(uStack_8);
      *(int32_t *)(uStack_10 + (int)x) = uval_2;
      uStack_8 = uval_1;
    }
    x = (uint32_t *)((int)x + height + width * 3);
  }
  return 0;
}



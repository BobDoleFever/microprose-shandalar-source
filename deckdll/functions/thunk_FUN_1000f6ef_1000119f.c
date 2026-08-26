/*
 * Decompiled function: thunk_FUN_1000f6ef
 * Entry Point: 1000119f
 * Size: 5 bytes
 */
#include "deckdll.h"


int32_t thunk_FUN_1000f6ef(int arg1,int arg2)

{
  int val_1;
  int val_2;
  void *buf_ptr_3;
  int iStack_14;
  int iStack_10;
  
  val_1 = *(int *)(&DAT_100415d8 + arg1 * 4);
  for (iStack_10 = 0; iStack_10 < *(int *)(&DAT_10041588 + arg1 * 4); iStack_10 = iStack_10 + 1) {
    val_2 = *(int *)(&DAT_10041600 + iStack_10 * 0x10 + arg1 * 0xc0);
    if (*(int *)(arg2 + val_2 * 4) == 0) {
      buf_ptr_3 = malloc(0x800);
      *(void **)(arg2 + val_2 * 4) = buf_ptr_3;
      for (iStack_14 = -0x100; iStack_14 < 0x100; iStack_14 = iStack_14 + 1) {
        *(int *)(*(int *)(arg2 + val_2 * 4) + 0x400 + iStack_14 * 4) =
             ((val_2 * iStack_14 + (val_1 >> 1)) * 0x100) / *(int *)(&DAT_100415d8 + arg1 * 4);
      }
      *(int *)(&DAT_1004160c + iStack_10 * 0x10 + arg1 * 0xc0) = *(int *)(arg2 + val_2 * 4) + 0x3fc;
    }
    else {
      *(int *)(&DAT_1004160c + iStack_10 * 0x10 + arg1 * 0xc0) = *(int *)(arg2 + val_2 * 4) + 0x400;
    }
  }
  for (iStack_10 = 0; iStack_10 < *(int *)(&DAT_10041588 + arg1 * 4); iStack_10 = iStack_10 + 1) {
    *(int *)(&DAT_10041ccc + iStack_10 * 0x10 + arg1 * 0xc0) =
         *(int *)(arg2 + *(int *)(&DAT_10041cc0 + iStack_10 * 0x10 + arg1 * 0xc0) * 4) + 0x3fc;
  }
  return 0;
}



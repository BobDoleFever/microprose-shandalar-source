/*
 * Decompiled function: FUN_1000f6ef
 * Entry Point: 1000f6ef
 * Size: 392 bytes
 */
#include "deckdll.h"


int32_t FUN_1000f6ef(int arg1,int arg2)

{
  int val_1;
  int val_2;
  void *buf_ptr_3;
  int local_14;
  int local_10;
  
  val_1 = *(int *)(&DAT_100415d8 + arg1 * 4);
  for (local_10 = 0; local_10 < *(int *)(&DAT_10041588 + arg1 * 4); local_10 = local_10 + 1) {
    val_2 = *(int *)(&DAT_10041600 + local_10 * 0x10 + arg1 * 0xc0);
    if (*(int *)(arg2 + val_2 * 4) == 0) {
      buf_ptr_3 = malloc(0x800);
      *(void **)(arg2 + val_2 * 4) = buf_ptr_3;
      for (local_14 = -0x100; local_14 < 0x100; local_14 = local_14 + 1) {
        *(int *)(*(int *)(arg2 + val_2 * 4) + 0x400 + local_14 * 4) =
             ((val_2 * local_14 + (val_1 >> 1)) * 0x100) / *(int *)(&DAT_100415d8 + arg1 * 4);
      }
      *(int *)(&DAT_1004160c + local_10 * 0x10 + arg1 * 0xc0) = *(int *)(arg2 + val_2 * 4) + 0x3fc;
    }
    else {
      *(int *)(&DAT_1004160c + local_10 * 0x10 + arg1 * 0xc0) = *(int *)(arg2 + val_2 * 4) + 0x400;
    }
  }
  for (local_10 = 0; local_10 < *(int *)(&DAT_10041588 + arg1 * 4); local_10 = local_10 + 1) {
    *(int *)(&DAT_10041ccc + local_10 * 0x10 + arg1 * 0xc0) =
         *(int *)(arg2 + *(int *)(&DAT_10041cc0 + local_10 * 0x10 + arg1 * 0xc0) * 4) + 0x3fc;
  }
  return 0;
}



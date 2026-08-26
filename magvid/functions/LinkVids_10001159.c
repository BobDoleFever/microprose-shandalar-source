/*
 * Decompiled function: LinkVids
 * Entry Point: 10001159
 * Size: 5 bytes
 */
#include "magvid.h"


int32_t __cdecl LinkVids(int arg1,int arg2)

{
  int val_1;
  int32_t uval_2;
  
                    /* 0x1159  17  LinkVids */
  if ((arg1 < 0) || (2 < arg1)) {
    uval_2 = 2;
  }
  else if ((arg2 < 0) || (2 < arg2)) {
    uval_2 = 2;
  }
  else if (*(int *)(&DAT_10010868 + arg1 * 4) == 0) {
    uval_2 = 5;
  }
  else {
    val_1 = *(int *)(&DAT_10010868 + arg2 * 4);
    if (val_1 == 0) {
      uval_2 = 5;
    }
    else {
      *(int *)(*(int *)(&DAT_10010868 + arg1 * 4) + 100) = val_1;
      *(int32_t *)(val_1 + 0x68) = 1;
      uval_2 = 0;
    }
  }
  return uval_2;
}



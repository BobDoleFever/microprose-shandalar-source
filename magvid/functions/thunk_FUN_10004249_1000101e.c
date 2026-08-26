/*
 * Decompiled function: thunk_FUN_10004249
 * Entry Point: 1000101e
 * Size: 5 bytes
 */
#include "magvid.h"


int32_t __cdecl thunk_FUN_10004249(int arg1,int *arg2)

{
  int val_1;
  bool flag_2;
  int32_t uval_3;
  int iStack_8;
  
  iStack_8 = 0;
  do {
    if ((*(int *)(&DAT_10010868 + iStack_8 * 4) == 0) ||
       (*(int *)(*(int *)(&DAT_10010868 + iStack_8 * 4) + 0x10) == arg1)) break;
    val_1 = iStack_8 + 1;
    flag_2 = iStack_8 < 3;
    iStack_8 = val_1;
  } while (flag_2);
  if (iStack_8 < 3) {
    *arg2 = iStack_8;
    uval_3 = 0;
  }
  else {
    uval_3 = 2;
  }
  return uval_3;
}



/*
 * Decompiled function: thunk_FUN_1000eef0
 * Entry Point: 10001415
 * Size: 5 bytes
 */
#include "deckdll.h"


int thunk_FUN_1000eef0(int *arg1,int *arg2)

{
  int val_1;
  int iStack_10;
  int iStack_8;
  
  iStack_8 = 0;
  if (*arg1 == 0) {
    for (iStack_10 = 0; iStack_10 < 8; iStack_10 = iStack_10 + 1) {
      if (arg1[iStack_10 + 2] != 0) {
        val_1 = thunk_FUN_1000eef0((int *)arg1[iStack_10 + 2],arg2);
        iStack_8 = iStack_8 + val_1;
        arg2 = arg2 + val_1;
      }
    }
  }
  else {
    *arg2 = arg1[1];
    iStack_8 = 1;
  }
  return iStack_8;
}



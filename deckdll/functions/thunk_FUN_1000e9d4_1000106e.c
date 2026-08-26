/*
 * Decompiled function: thunk_FUN_1000e9d4
 * Entry Point: 1000106e
 * Size: 5 bytes
 */
#include "deckdll.h"


int thunk_FUN_1000e9d4(int *arg_1)

{
  int val_1;
  int iStack_c;
  int iStack_8;
  
  iStack_8 = 0;
  if (*arg_1 == 0) {
    for (iStack_c = 0; iStack_c < 8; iStack_c = iStack_c + 1) {
      if (arg_1[iStack_c + 2] != 0) {
        val_1 = thunk_FUN_1000e9d4((int *)arg_1[iStack_c + 2]);
        iStack_8 = iStack_8 + val_1;
      }
    }
    if (arg_1[10] != 0) {
      free((void *)arg_1[10]);
    }
    free(arg_1);
  }
  else {
    free(arg_1);
    iStack_8 = 1;
  }
  return iStack_8;
}



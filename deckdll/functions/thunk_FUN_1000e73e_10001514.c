/*
 * Decompiled function: thunk_FUN_1000e73e
 * Entry Point: 10001514
 * Size: 5 bytes
 */
#include "deckdll.h"


void thunk_FUN_1000e73e(int *arg_1,int arg_2,int *arg_3)

{
  int iStack_8;
  
  if (*arg_1 == 0) {
    for (iStack_8 = 0; iStack_8 < 8; iStack_8 = iStack_8 + 1) {
      if (arg_1[iStack_8 + 2] != 0) {
        thunk_FUN_1000e73e((int *)arg_1[iStack_8 + 2],arg_2,arg_3);
      }
    }
  }
  else {
    *(char *)(*arg_3 + arg_2) = (char)arg_1[1];
    *arg_3 = *arg_3 + 1;
  }
  return;
}



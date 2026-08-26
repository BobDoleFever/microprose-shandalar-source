/*
 * Decompiled function: FUN_1000eef0
 * Entry Point: 1000eef0
 * Size: 150 bytes
 */
#include "deckdll.h"


int FUN_1000eef0(int *arg1,int *arg2)

{
  int val_1;
  int local_10;
  int local_8;
  
  local_8 = 0;
  if (*arg1 == 0) {
    for (local_10 = 0; local_10 < 8; local_10 = local_10 + 1) {
      if (arg1[local_10 + 2] != 0) {
        val_1 = thunk_FUN_1000eef0((int *)arg1[local_10 + 2],arg2);
        local_8 = local_8 + val_1;
        arg2 = arg2 + val_1;
      }
    }
  }
  else {
    *arg2 = arg1[1];
    local_8 = 1;
  }
  return local_8;
}



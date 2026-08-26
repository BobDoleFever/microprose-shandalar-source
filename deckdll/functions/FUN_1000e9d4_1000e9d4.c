/*
 * Decompiled function: FUN_1000e9d4
 * Entry Point: 1000e9d4
 * Size: 175 bytes
 */
#include "deckdll.h"


int FUN_1000e9d4(int *arg_1)

{
  int val_1;
  int local_c;
  int local_8;
  
  local_8 = 0;
  if (*arg_1 == 0) {
    for (local_c = 0; local_c < 8; local_c = local_c + 1) {
      if (arg_1[local_c + 2] != 0) {
        val_1 = thunk_FUN_1000e9d4((int *)arg_1[local_c + 2]);
        local_8 = local_8 + val_1;
      }
    }
    if (arg_1[10] != 0) {
      free((void *)arg_1[10]);
    }
    free(arg_1);
  }
  else {
    free(arg_1);
    local_8 = 1;
  }
  return local_8;
}



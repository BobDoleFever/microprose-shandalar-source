/*
 * Decompiled function: FUN_1000e7bd
 * Entry Point: 1000e7bd
 * Size: 311 bytes
 */
#include "deckdll.h"


int FUN_1000e7bd(int *arg_1)

{
  int val_1;
  void *buf_ptr_2;
  int local_410;
  size_t local_40c;
  uint8_t local_408 [1024];
  int local_8;
  
  val_1 = DAT_10129248;
  local_8 = 0;
  local_40c = 0;
  DAT_10129248 = DAT_10129248 + 1;
  if (DAT_10041568 < DAT_10129248) {
    DAT_10041568 = DAT_10129248;
  }
  if (*arg_1 == 0) {
    for (local_410 = 0; local_410 < 8; local_410 = local_410 + 1) {
      if (arg_1[local_410 + 2] != 0) {
        val_1 = thunk_FUN_1000e7bd((int *)arg_1[local_410 + 2]);
        local_8 = local_8 + val_1;
        local_40c = local_40c + 1;
      }
    }
    if (local_40c != 0) {
      local_40c = 0;
      thunk_FUN_1000e73e(arg_1,(int)local_408,(int *)&local_40c);
      buf_ptr_2 = malloc(local_40c);
      arg_1[10] = (int)buf_ptr_2;
      arg_1[0xb] = local_40c;
      memcpy((void *)arg_1[10],local_408,local_40c);
    }
    DAT_10129248 = DAT_10129248 + -1;
  }
  else {
    local_8 = 1;
    DAT_10129248 = val_1;
  }
  return local_8;
}



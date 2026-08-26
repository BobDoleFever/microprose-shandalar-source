/*
 * Decompiled function: thunk_FUN_1000e7bd
 * Entry Point: 10001500
 * Size: 5 bytes
 */
#include "deckdll.h"


int thunk_FUN_1000e7bd(int *arg_1)

{
  int val_1;
  void *buf_ptr_2;
  int iStack_410;
  size_t sStack_40c;
  uint8_t auStack_408 [1024];
  int iStack_8;
  
  val_1 = DAT_10129248;
  iStack_8 = 0;
  sStack_40c = 0;
  DAT_10129248 = DAT_10129248 + 1;
  if (DAT_10041568 < DAT_10129248) {
    DAT_10041568 = DAT_10129248;
  }
  if (*arg_1 == 0) {
    for (iStack_410 = 0; iStack_410 < 8; iStack_410 = iStack_410 + 1) {
      if (arg_1[iStack_410 + 2] != 0) {
        val_1 = thunk_FUN_1000e7bd((int *)arg_1[iStack_410 + 2]);
        iStack_8 = iStack_8 + val_1;
        sStack_40c = sStack_40c + 1;
      }
    }
    if (sStack_40c != 0) {
      sStack_40c = 0;
      thunk_FUN_1000e73e(arg_1,(int)auStack_408,(int *)&sStack_40c);
      buf_ptr_2 = malloc(sStack_40c);
      arg_1[10] = (int)buf_ptr_2;
      arg_1[0xb] = sStack_40c;
      memcpy((void *)arg_1[10],auStack_408,sStack_40c);
    }
    DAT_10129248 = DAT_10129248 + -1;
  }
  else {
    iStack_8 = 1;
    DAT_10129248 = val_1;
  }
  return iStack_8;
}



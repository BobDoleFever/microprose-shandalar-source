/*
 * Decompiled function: FUN_10028c81
 * Entry Point: 10028c81
 * Size: 130 bytes
 */
#include "deckdll.h"


int32_t FUN_10028c81(int arg1,int arg2)

{
  int32_t uval_1;
  int val_2;
  
  if (arg1 == -1) {
    uval_1 = 0;
  }
  else if (*(int *)(&DAT_10176af4 + arg1 * 0x98) < 2) {
    if (*(int *)(&DAT_10162910 + arg1 * 0x10) == 0) {
      uval_1 = 0;
    }
    else {
      uval_1 = 1;
    }
  }
  else {
    val_2 = thunk_FUN_10029205(arg1,arg2);
    if (val_2 == 0) {
      uval_1 = 0;
    }
    else {
      uval_1 = 1;
    }
  }
  return uval_1;
}



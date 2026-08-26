/*
 * Decompiled function: FUN_1000e08a
 * Entry Point: 1000e08a
 * Size: 70 bytes
 */
#include "deckdll.h"


int32_t FUN_1000e08a(int *arg1,int *arg2)

{
  int32_t uval_1;
  
  if (*arg2 < *arg1) {
    uval_1 = 1;
  }
  else if (*arg1 < *arg2) {
    uval_1 = 0xffffffff;
  }
  else {
    uval_1 = 0;
  }
  return uval_1;
}



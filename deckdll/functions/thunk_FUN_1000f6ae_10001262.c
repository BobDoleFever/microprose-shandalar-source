/*
 * Decompiled function: thunk_FUN_1000f6ae
 * Entry Point: 10001262
 * Size: 5 bytes
 */
#include "deckdll.h"


void thunk_FUN_1000f6ae(int32_t *arg1,int arg2)

{
  int32_t uval_1;
  
  uval_1 = *arg1;
  memcpy(arg1,arg1 + 1,arg2 * 4 - 4);
  arg1[arg2 + -1] = uval_1;
  return;
}



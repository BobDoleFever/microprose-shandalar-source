/*
 * Decompiled function: FUN_1000f6ae
 * Entry Point: 1000f6ae
 * Size: 65 bytes
 */
#include "deckdll.h"


void FUN_1000f6ae(int32_t *arg1,int arg2)

{
  int32_t uval_1;
  
  uval_1 = *arg1;
  memcpy(arg1,arg1 + 1,arg2 * 4 - 4);
  arg1[arg2 + -1] = uval_1;
  return;
}



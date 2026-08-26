/*
 * Decompiled function: FUN_0040a1d2
 * Entry Point: 0040a1d2
 * Size: 45 bytes
 */
#include "magic.h"


int FUN_0040a1d2(int arg_1)

{
  int iVar1;
  
  if (arg_1 < 2) {
    iVar1 = 0;
  }
  else {
    iVar1 = rand();
    iVar1 = iVar1 % arg_1;
  }
  return iVar1;
}



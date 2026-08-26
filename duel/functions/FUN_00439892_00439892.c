/*
 * Decompiled function: FUN_00439892
 * Entry Point: 00439892
 * Size: 44 bytes
 */
#include "duel.h"


int FUN_00439892(int arg_1)

{
  int iVar1;
  
  if (arg_1 < 2) {
    iVar1 = 0;
  }
  else {
    iVar1 = _rand();
    iVar1 = iVar1 % arg_1;
  }
  return iVar1;
}



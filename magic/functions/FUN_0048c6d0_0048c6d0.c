/*
 * Decompiled function: FUN_0048c6d0
 * Entry Point: 0048c6d0
 * Size: 80 bytes
 */
#include "magic.h"


int FUN_0048c6d0(int arg_1)

{
  int iVar1;
  
  if ((arg_1 < 0) || (9 < arg_1)) {
    if ((arg_1 < 10) || (0xf < arg_1)) {
      iVar1 = 0;
    }
    else {
      iVar1 = arg_1 + 0x57;
    }
  }
  else {
    iVar1 = arg_1 + 0x30;
  }
  return iVar1;
}



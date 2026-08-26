/*
 * Decompiled function: FUN_00432860
 * Entry Point: 00432860
 * Size: 80 bytes
 */
#include "duel.h"


int FUN_00432860(int arg_1)

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



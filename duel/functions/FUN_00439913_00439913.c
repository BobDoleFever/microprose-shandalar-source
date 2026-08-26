/*
 * Decompiled function: FUN_00439913
 * Entry Point: 00439913
 * Size: 101 bytes
 */
#include "duel.h"


uint FUN_00439913(uint arg_1)

{
  uint uVar1;
  
  if (DAT_00516744 < 100) {
    uVar1 = (int)(*(int *)(&DAT_00516748 + (DAT_00516744 % 100) * 4) * arg_1) >> 0xf;
  }
  else {
    uVar1 = DAT_00516744 % arg_1;
  }
  DAT_00516744 = DAT_00516744 + 1;
  return uVar1;
}



/*
 * Decompiled function: FUN_0040a255
 * Entry Point: 0040a255
 * Size: 101 bytes
 */
#include "magic.h"


uint FUN_0040a255(uint arg_1)

{
  uint uVar1;
  
  if (DAT_00538334 < 100) {
    uVar1 = (int)(*(int *)(&DAT_00538338 + (DAT_00538334 % 100) * 4) * arg_1) >> 0xf;
  }
  else {
    uVar1 = DAT_00538334 % arg_1;
  }
  DAT_00538334 = DAT_00538334 + 1;
  return uVar1;
}



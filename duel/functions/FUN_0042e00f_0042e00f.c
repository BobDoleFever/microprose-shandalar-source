/*
 * Decompiled function: FUN_0042e00f
 * Entry Point: 0042e00f
 * Size: 109 bytes
 */
#include "duel.h"


undefined4 FUN_0042e00f(void)

{
  undefined4 uVar1;
  int local_8;
  
  if (DAT_004f3b2c < 10) {
    for (local_8 = 0; local_8 < 7; local_8 = local_8 + 1) {
      *(undefined4 *)(&DAT_0050b250 + DAT_004f3b2c * 0x1c + local_8 * 4) = 0;
    }
    DAT_004f3b2c = DAT_004f3b2c + 1;
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: FUN_0042e1a0
 * Entry Point: 0042e1a0
 * Size: 114 bytes
 */
#include "duel.h"


undefined4 FUN_0042e1a0(int arg_1)

{
  undefined4 uVar1;
  int local_8;
  
  if (DAT_004f3b2c < 1) {
    uVar1 = 0;
  }
  else {
    for (local_8 = 0; local_8 < 7; local_8 = local_8 + 1) {
      *(int *)(&DAT_0050b250 + (DAT_004f3b2c + -1) * 0x1c + local_8 * 4) =
           *(int *)(&DAT_0050b250 + (DAT_004f3b2c + -1) * 0x1c + local_8 * 4) -
           *(int *)(arg_1 + local_8 * 4);
    }
    uVar1 = 1;
  }
  return uVar1;
}



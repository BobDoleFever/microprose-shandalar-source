/*
 * Decompiled function: FUN_00434c97
 * Entry Point: 00434c97
 * Size: 114 bytes
 */
#include "duel.h"


undefined4 FUN_00434c97(void)

{
  undefined4 uVar1;
  int local_c;
  int local_8;
  
  if (DAT_004f4618 == 0) {
    local_c = -0xff;
    for (local_8 = 0; local_8 < 0x200; local_8 = local_8 + 1) {
      *(int *)(&DAT_00695750 + local_8 * 4) = local_c * local_c;
      local_c = local_c + 1;
    }
    DAT_004f4618 = 1;
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



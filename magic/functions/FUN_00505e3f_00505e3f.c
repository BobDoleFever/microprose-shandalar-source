/*
 * Decompiled function: FUN_00505e3f
 * Entry Point: 00505e3f
 * Size: 104 bytes
 */
#include "magic.h"


undefined4 FUN_00505e3f(int arg_1)

{
  undefined4 uVar1;
  
  if (*(int *)(&DAT_00696740 + arg_1 * 4 + g_DefendingPlayer * 0x98) == 0) {
    if ((DAT_00627a88 == arg_1) && (DAT_00627a84 == g_DefendingPlayer)) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}



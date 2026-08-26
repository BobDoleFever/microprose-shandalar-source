/*
 * Decompiled function: FUN_0042ab67
 * Entry Point: 0042ab67
 * Size: 104 bytes
 */
#include "duel.h"


undefined4 FUN_0042ab67(int arg_1)

{
  undefined4 uVar1;
  
  if (*(int *)(&DAT_006667c0 + arg_1 * 4 + DAT_00666458 * 0x98) == 0) {
    if ((DAT_0066ab04 == arg_1) && (DAT_0066aac4 == DAT_00666458)) {
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



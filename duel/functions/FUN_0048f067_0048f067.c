/*
 * Decompiled function: FUN_0048f067
 * Entry Point: 0048f067
 * Size: 183 bytes
 */
#include "duel.h"


undefined4 FUN_0048f067(int arg1,int arg2)

{
  undefined4 uVar1;
  int local_8;
  
  if ((arg1 == -1) || (arg2 == -1)) {
    uVar1 = 0;
  }
  else {
    local_8 = *(int *)(&DAT_006826c4 + arg2 * 0x120 + arg1 * 0x5b20);
    if (DAT_0068eee0 == local_8) {
      local_8 = *(int *)(&DAT_006826c0 + arg2 * 0x120 + arg1 * 0x5b20);
    }
    if (local_8 == -1) {
      uVar1 = 0;
    }
    else if (((&DAT_004ff5aa)[local_8 * 0x34] & 2) == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  return uVar1;
}



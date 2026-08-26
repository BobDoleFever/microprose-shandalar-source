/*
 * Decompiled function: FUN_004769c4
 * Entry Point: 004769c4
 * Size: 183 bytes
 */
#include "magic.h"


undefined4 FUN_004769c4(int arg1,int arg2)

{
  undefined4 uVar1;
  int local_8;
  
  if ((arg1 == -1) || (arg2 == -1)) {
    uVar1 = 0;
  }
  else {
    local_8 = *(int *)(&g_CardSlot_CardId + arg2 * 0x120 + arg1 * 0x5b20);
    if (DAT_006fd3f4 == local_8) {
      local_8 = *(int *)(&g_ActiveCardsInPlay + arg2 * 0x120 + arg1 * 0x5b20);
    }
    if (local_8 == -1) {
      uVar1 = 0;
    }
    else if (((&DAT_0051aed2)[local_8 * 0x34] & 2) == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  return uVar1;
}



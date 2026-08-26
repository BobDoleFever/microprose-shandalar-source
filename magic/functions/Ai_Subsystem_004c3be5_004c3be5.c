/*
 * Decompiled function: Ai_Subsystem_004c3be5
 * Entry Point: 004c3be5
 * Size: 119 bytes
 */
#include "magic.h"


undefined4 Ai_Subsystem_004c3be5(int arg1,int arg2)

{
  undefined4 uVar1;
  
  if ((arg1 < DAT_006498d8) || ((8 << (DAT_006498e0 & 0x1f)) + DAT_006498d8 <= arg1)) {
    uVar1 = 0;
  }
  else if ((arg2 < DAT_006498dc) || ((6 << (DAT_006498e0 & 0x1f)) + DAT_006498dc <= arg2)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}



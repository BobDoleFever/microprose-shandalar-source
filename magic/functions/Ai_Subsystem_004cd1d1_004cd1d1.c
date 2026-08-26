/*
 * Decompiled function: Ai_Subsystem_004cd1d1
 * Entry Point: 004cd1d1
 * Size: 61 bytes
 */
#include "magic.h"


undefined4 Ai_Subsystem_004cd1d1(void)

{
  undefined4 uVar1;
  
  if (g_IsAiThinking == 1) {
    uVar1 = 0;
  }
  else if (DAT_0063ee18 == 0) {
    uVar1 = FUN_0040a444();
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



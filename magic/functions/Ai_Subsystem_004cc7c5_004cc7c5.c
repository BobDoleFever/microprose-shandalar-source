/*
 * Decompiled function: Ai_Subsystem_004cc7c5
 * Entry Point: 004cc7c5
 * Size: 79 bytes
 */
#include "magic.h"


void Ai_Subsystem_004cc7c5(undefined4 arg1,undefined4 arg2)

{
  if (g_IsAiThinking != 1) {
    if (DAT_0063ee18 == 0) {
      FUN_00484df9(arg1,arg2);
    }
    else {
      Ai_Util_004b1406(arg1,arg2);
    }
  }
  return;
}



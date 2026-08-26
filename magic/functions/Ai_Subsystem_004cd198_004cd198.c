/*
 * Decompiled function: Ai_Subsystem_004cd198
 * Entry Point: 004cd198
 * Size: 57 bytes
 */
#include "magic.h"


void Ai_Subsystem_004cd198(void)

{
  if (g_IsAiThinking != 1) {
    if (DAT_0063ee18 == 0) {
      FUN_004853c2();
    }
    else {
      Ai_Util_004b543d();
    }
  }
  return;
}



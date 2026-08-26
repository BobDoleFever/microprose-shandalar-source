/*
 * Decompiled function: Ai_Subsystem_004cd14f
 * Entry Point: 004cd14f
 * Size: 73 bytes
 */
#include "magic.h"


void Ai_Subsystem_004cd14f(int arg_1)

{
  if (g_IsAiThinking != 1) {
    if (DAT_0063ee18 == 0) {
      FUN_00485234(arg_1);
    }
    else {
      Ai_Util_004b542d(arg_1,1);
    }
  }
  return;
}



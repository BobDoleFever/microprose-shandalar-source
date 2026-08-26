/*
 * Decompiled function: Ai_Subsystem_004cc97e
 * Entry Point: 004cc97e
 * Size: 71 bytes
 */
#include "magic.h"


void Ai_Subsystem_004cc97e(char *str_1)

{
  if (g_IsAiThinking != 1) {
    if (DAT_0063ee18 == 0) {
      FUN_00484668(str_1);
    }
    else {
      Ai_Util_004b42d1(str_1);
    }
  }
  return;
}



/*
 * Decompiled function: Pic_Subsystem_0045275a
 * Entry Point: 0045275a
 * Size: 57 bytes
 */
#include "magic.h"


void Pic_Subsystem_0045275a(undefined1 *arg_1)

{
  if (g_IsAiThinking != 1) {
    Pic_Subsystem_0044b8da();
    Ai_Util_004b128e(arg_1);
    *arg_1 = 0;
    Pic_Subsystem_0044b8aa();
  }
  return;
}



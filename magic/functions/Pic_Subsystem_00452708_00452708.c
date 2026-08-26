/*
 * Decompiled function: Pic_Subsystem_00452708
 * Entry Point: 00452708
 * Size: 82 bytes
 */
#include "magic.h"


void Pic_Subsystem_00452708(char *str_1)

{
  int iVar1;
  
  if (g_IsAiThinking != 1) {
    Pic_Subsystem_0044b8da();
    iVar1 = FUN_0040c465(str_1);
    if (8 < iVar1 + 8) {
      Ai_Subsystem_004cc97e(str_1);
    }
    Pic_Subsystem_0044b8aa();
  }
  return;
}



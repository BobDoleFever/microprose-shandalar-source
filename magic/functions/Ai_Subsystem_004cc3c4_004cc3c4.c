/*
 * Decompiled function: Ai_Subsystem_004cc3c4
 * Entry Point: 004cc3c4
 * Size: 52 bytes
 */
#include "magic.h"


undefined4 Ai_Subsystem_004cc3c4(int arg1,int arg2)

{
  undefined4 uVar1;
  
  if (g_IsAiThinking == 1) {
    uVar1 = 0;
  }
  else {
    uVar1 = Ai_Subsystem_004af640(arg1,arg2);
  }
  return uVar1;
}



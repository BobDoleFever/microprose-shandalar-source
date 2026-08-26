/*
 * Decompiled function: Magic_CheckTurnTriggers
 * Entry Point: 00474939
 * Size: 50 bytes
 */
#include "magic.h"


void Magic_CheckTurnTriggers(int arg1,int arg2)

{
  if (g_IsAiThinking != 1) {
    Ai_Subsystem_004cc3c4(arg1,arg2);
  }
  g_ActivePlayer = 0;
  return;
}



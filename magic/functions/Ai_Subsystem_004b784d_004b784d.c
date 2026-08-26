/*
 * Decompiled function: Ai_Subsystem_004b784d
 * Entry Point: 004b784d
 * Size: 74 bytes
 */
#include "magic.h"


void Ai_Subsystem_004b784d(undefined4 arg1,undefined4 arg2)

{
  undefined4 local_10;
  undefined4 local_c;
  
  if (g_IsAiThinking != 1) {
    local_10 = arg1;
    local_c = arg2;
    DialogBoxParamA(g_AppHInstance,(LPCSTR)0xf3,g_MainAppHwnd,Ai_CalcManaRequirement_004b7897,
                    (LPARAM)&local_10);
  }
  return;
}



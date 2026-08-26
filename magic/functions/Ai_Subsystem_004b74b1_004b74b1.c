/*
 * Decompiled function: Ai_Subsystem_004b74b1
 * Entry Point: 004b74b1
 * Size: 73 bytes
 */
#include "magic.h"


void Ai_Subsystem_004b74b1(undefined4 *arg1,undefined4 *arg2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  if (arg1 != (undefined4 *)0x0) {
    *arg1 = DAT_006808ac;
  }
  if (arg2 != (undefined4 *)0x0) {
    *arg2 = DAT_006a2834;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  return;
}



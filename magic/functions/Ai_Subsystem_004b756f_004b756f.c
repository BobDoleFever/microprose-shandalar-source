/*
 * Decompiled function: Ai_Subsystem_004b756f
 * Entry Point: 004b756f
 * Size: 53 bytes
 */
#include "magic.h"


void Ai_Subsystem_004b756f(undefined4 *arg_1)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  if (arg_1 != (undefined4 *)0x0) {
    *arg_1 = DAT_0068a678;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  return;
}



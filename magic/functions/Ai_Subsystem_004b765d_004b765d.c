/*
 * Decompiled function: Ai_Subsystem_004b765d
 * Entry Point: 004b765d
 * Size: 73 bytes
 */
#include "magic.h"


void Ai_Subsystem_004b765d(undefined4 *arg1,undefined4 *arg2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  if (arg1 != (undefined4 *)0x0) {
    *arg1 = DAT_00695ec0;
  }
  if (arg2 != (undefined4 *)0x0) {
    *arg2 = DAT_00696730;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  return;
}



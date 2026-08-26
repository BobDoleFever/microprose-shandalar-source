/*
 * Decompiled function: Ai_Subsystem_004b75d8
 * Entry Point: 004b75d8
 * Size: 81 bytes
 */
#include "magic.h"


bool Ai_Subsystem_004b75d8(undefined4 *arg_1)

{
  if (arg_1 != (undefined4 *)0x0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
    *arg_1 = DAT_006a29c8;
    arg_1[1] = DAT_006a29cc;
    LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  }
  return arg_1 != (undefined4 *)0x0;
}



/*
 * Decompiled function: Ai_Subsystem_004b7629
 * Entry Point: 004b7629
 * Size: 52 bytes
 */
#include "magic.h"


undefined4 Ai_Subsystem_004b7629(void)

{
  undefined4 uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  uVar1 = DAT_006a48e0;
  LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  return uVar1;
}



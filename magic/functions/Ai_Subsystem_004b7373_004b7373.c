/*
 * Decompiled function: Ai_Subsystem_004b7373
 * Entry Point: 004b7373
 * Size: 91 bytes
 */
#include "magic.h"


undefined4 Ai_Subsystem_004b7373(void *arg_1)

{
  undefined4 uVar1;
  
  if (arg_1 == (void *)0x0) {
    uVar1 = 0;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
    uVar1 = DAT_006b2e28;
    memcpy(arg_1,&DAT_006a29e0,0x1580);
    LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  }
  return uVar1;
}



/*
 * Decompiled function: Ai_Subsystem_004b74fa
 * Entry Point: 004b74fa
 * Size: 117 bytes
 */
#include "magic.h"


void Ai_Subsystem_004b74fa(void *arg1,int arg2)

{
  int iVar1;
  
  if ((arg1 != (void *)0x0) && (iVar1 = Ai_Util_004b6f19(arg2), iVar1 == 0)) {
    EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
    memcpy(arg1,&DAT_006fedd0 + ((arg2 == 0) - 1 & 0xfffa5b70),0x98);
    LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  }
  return;
}



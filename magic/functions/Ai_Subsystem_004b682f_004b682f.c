/*
 * Decompiled function: Ai_Subsystem_004b682f
 * Entry Point: 004b682f
 * Size: 132 bytes
 */
#include "magic.h"


bool Ai_Subsystem_004b682f(int arg1,int arg2)

{
  int iVar1;
  bool bVar2;
  
  iVar1 = Ai_Subsystem_004b5919(arg1,arg2);
  if (iVar1 == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
    bVar2 = ((&DAT_0068a73e)[arg2 * 0x120 + arg1 * 0x5b20] & 0x10) == 0;
    LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  }
  else {
    bVar2 = false;
  }
  return bVar2;
}



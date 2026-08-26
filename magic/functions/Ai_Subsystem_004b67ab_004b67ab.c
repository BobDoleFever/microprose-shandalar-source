/*
 * Decompiled function: Ai_Subsystem_004b67ab
 * Entry Point: 004b67ab
 * Size: 132 bytes
 */
#include "magic.h"


bool Ai_Subsystem_004b67ab(int arg1,int arg2)

{
  int iVar1;
  bool bVar2;
  
  iVar1 = Ai_Subsystem_004b5919(arg1,arg2);
  if (iVar1 == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
    bVar2 = ((&DAT_0068a73e)[arg1 * 0x5b20 + arg2 * 0x120] & 0x20) != 0;
    LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  }
  else {
    bVar2 = false;
  }
  return bVar2;
}



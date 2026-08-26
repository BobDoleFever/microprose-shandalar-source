/*
 * Decompiled function: Ai_Subsystem_004b6356
 * Entry Point: 004b6356
 * Size: 110 bytes
 */
#include "magic.h"


int Ai_Subsystem_004b6356(int arg1,int arg2)

{
  int iVar1;
  
  iVar1 = Ai_Subsystem_004b5919(arg1,arg2);
  if (iVar1 == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
    iVar1 = (int)(char)(&DAT_0068a74d)[arg2 * 0x120 + arg1 * 0x5b20];
    LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}



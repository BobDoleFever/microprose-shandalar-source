/*
 * Decompiled function: Ai_Subsystem_004b5a46
 * Entry Point: 004b5a46
 * Size: 114 bytes
 */
#include "magic.h"


uint Ai_Subsystem_004b5a46(int arg1,int arg2)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = Ai_Subsystem_004b5919(arg1,arg2);
  if (iVar1 == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
    uVar2 = *(uint *)(&DAT_0068a77c + arg2 * 0x120 + arg1 * 0x5b20) & 0xff;
    LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



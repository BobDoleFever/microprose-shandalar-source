/*
 * Decompiled function: Ai_Subsystem_004b5c4b
 * Entry Point: 004b5c4b
 * Size: 112 bytes
 */
#include "magic.h"


undefined4 Ai_Subsystem_004b5c4b(int arg1,int arg2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Ai_Subsystem_004b5919(arg1,arg2);
  if (iVar1 == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
    uVar2 = *(undefined4 *)(&DAT_0068a734 + arg2 * 0x120 + arg1 * 0x5b20);
    LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}



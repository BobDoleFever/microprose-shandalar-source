/*
 * Decompiled function: Ai_Subsystem_004b7072
 * Entry Point: 004b7072
 * Size: 140 bytes
 */
#include "magic.h"


undefined4 Ai_Subsystem_004b7072(void *arg1,int arg2)

{
  undefined4 uVar1;
  int iVar2;
  
  if (arg1 == (void *)0x0) {
    uVar1 = 0;
  }
  else {
    iVar2 = Ai_Util_004b6f19(arg2);
    if (iVar2 == 0) {
      EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
      if (arg2 == 0) {
        memcpy(arg1,&DAT_0069f6e0,0x1c);
      }
      else {
        memcpy(arg1,&DAT_00695ee0,0x1c);
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}



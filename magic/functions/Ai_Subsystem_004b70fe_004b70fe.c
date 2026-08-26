/*
 * Decompiled function: Ai_Subsystem_004b70fe
 * Entry Point: 004b70fe
 * Size: 140 bytes
 */
#include "magic.h"


undefined4 Ai_Subsystem_004b70fe(void *arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (arg_1 == (void *)0x0) {
    uVar1 = 0;
  }
  else {
    iVar2 = Ai_Subsystem_004b5919(arg_2,arg_3);
    if (iVar2 == 0) {
      EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
      memcpy(arg_1,&DAT_0068a730 + arg_2 * 0x5b20 + arg_3 * 0x120,0x120);
      LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}



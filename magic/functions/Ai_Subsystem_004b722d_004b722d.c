/*
 * Decompiled function: Ai_Subsystem_004b722d
 * Entry Point: 004b722d
 * Size: 163 bytes
 */
#include "magic.h"


undefined4 Ai_Subsystem_004b722d(void *arg1,int arg2)

{
  int iVar1;
  undefined4 local_8;
  
  if (arg1 == (void *)0x0) {
    local_8 = 0;
  }
  else {
    iVar1 = Ai_Util_004b6f19(arg2);
    if (iVar1 == 0) {
      EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
      if (arg2 == 0) {
        local_8 = DAT_006ff2e4;
      }
      else {
        local_8 = DAT_006b2d34;
      }
      memcpy(arg1,(void *)((int)&DAT_006fe4a0 + ((arg2 == 0) - 1 & 0xfffa6ae0)),2000);
      LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
    }
    else {
      local_8 = 0;
    }
  }
  return local_8;
}



/*
 * Decompiled function: Ai_Subsystem_004b718a
 * Entry Point: 004b718a
 * Size: 163 bytes
 */
#include "magic.h"


undefined4 Ai_Subsystem_004b718a(void *arg1,int arg2)

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
        local_8 = DAT_006ff1a0;
      }
      else {
        local_8 = DAT_007006b4;
      }
      memcpy(arg1,(void *)((int)&DAT_00695f20 + ((arg2 == 0) - 1 & 0x674e0)),2000);
      LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
    }
    else {
      local_8 = 0;
    }
  }
  return local_8;
}



/*
 * Decompiled function: Ai_Subsystem_004b5d2e
 * Entry Point: 004b5d2e
 * Size: 182 bytes
 */
#include "magic.h"


undefined4 Ai_Subsystem_004b5d2e(int arg1,int arg2)

{
  int iVar1;
  undefined4 local_8;
  
  iVar1 = Ai_Subsystem_004b5919(arg1,arg2);
  if (iVar1 == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
    if (((&DAT_0068a73c)[arg2 * 0x120 + arg1 * 0x5b20] & 2) == 0) {
      if (((&DAT_0068a73c)[arg2 * 0x120 + arg1 * 0x5b20] & 0x20) == 0) {
        local_8 = 0;
      }
      else {
        local_8 = 2;
      }
    }
    else {
      local_8 = 1;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  }
  else {
    local_8 = 0;
  }
  return local_8;
}



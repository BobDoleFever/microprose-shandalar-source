/*
 * Decompiled function: Ai_Subsystem_004b700c
 * Entry Point: 004b700c
 * Size: 102 bytes
 */
#include "magic.h"


undefined4 Ai_Subsystem_004b700c(int arg_1)

{
  int iVar1;
  undefined4 local_8;
  
  iVar1 = Ai_Util_004b6f19(arg_1);
  if (iVar1 == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
    if (arg_1 == 0) {
      local_8 = DAT_00695ed8;
    }
    else {
      local_8 = DAT_007006d8;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  }
  else {
    local_8 = 0;
  }
  return local_8;
}



/*
 * Decompiled function: Ai_Subsystem_004b6288
 * Entry Point: 004b6288
 * Size: 206 bytes
 */
#include "magic.h"


uint Ai_Subsystem_004b6288(int arg1,int arg2)

{
  int iVar1;
  uint local_8;
  
  iVar1 = Ai_Subsystem_004b5919(arg1,arg2);
  if (iVar1 == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
    local_8 = *(uint *)(&DAT_0068a76c + arg2 * 0x120 + arg1 * 0x5b20);
    if ((((&DAT_0068a76e)[arg2 * 0x120 + arg1 * 0x5b20] & 0x20) != 0) &&
       (((&DAT_0068a73c)[arg2 * 0x120 + arg1 * 0x5b20] & 4) != 0)) {
      local_8 = local_8 | 0x40;
    }
    if (local_8 == 0xffffffff) {
      local_8 = 0;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  }
  else {
    local_8 = 0;
  }
  return local_8;
}



/*
 * Decompiled function: Ai_Subsystem_004b5de4
 * Entry Point: 004b5de4
 * Size: 400 bytes
 */
#include "magic.h"


byte Ai_Subsystem_004b5de4(int arg1,int arg2)

{
  int iVar1;
  byte bVar2;
  
  iVar1 = Ai_Subsystem_004b5919(arg1,arg2);
  if (iVar1 == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
    bVar2 = ((&DAT_0068a73e)[arg2 * 0x120 + arg1 * 0x5b20] & 3) != 0;
    if ((((&DAT_0068a73c)[arg2 * 0x120 + arg1 * 0x5b20] & 0x10) != 0) &&
       (((&g_MasterCardColorTable)[*(int *)(&DAT_0068a734 + arg2 * 0x120 + arg1 * 0x5b20) * 0x34] &
        0x47) != 4)) {
      bVar2 = bVar2 | 2;
    }
    if (((&DAT_0068a73c)[arg2 * 0x120 + arg1 * 0x5b20] & 4) != 0) {
      bVar2 = bVar2 | 4;
    }
    if ((&DAT_0068a74e)[arg2 * 0x120 + arg1 * 0x5b20] != -1) {
      bVar2 = bVar2 | 8;
    }
    if (((&DAT_0068a742)[arg2 * 0x120 + arg1 * 0x5b20] != -1) &&
       (*(int *)(&DAT_0068a758 + arg2 * 0x120 + arg1 * 0x5b20) != -1)) {
      bVar2 = bVar2 | 0x10;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  }
  else {
    bVar2 = 0;
  }
  return bVar2;
}



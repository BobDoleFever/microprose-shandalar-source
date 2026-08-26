/*
 * Decompiled function: Ai_Subsystem_004b584e
 * Entry Point: 004b584e
 * Size: 139 bytes
 */
#include "magic.h"


undefined4 Ai_Subsystem_004b584e(void)

{
  if (g_IsAiThinking != 1) {
    EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
    memcpy(&DAT_0069f6e0,&DAT_0063ee90,0x1c);
    memcpy(&DAT_00695ee0,&DAT_0063eeb0,0x1c);
    LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
    SendMessageA(DAT_006b2d60,0x432,0,0);
    SendMessageA(DAT_006ff560,0x432,0,0);
  }
  return 0;
}



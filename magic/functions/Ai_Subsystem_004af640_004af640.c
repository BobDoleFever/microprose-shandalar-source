/*
 * Decompiled function: Ai_Subsystem_004af640
 * Entry Point: 004af640
 * Size: 293 bytes
 */
#include "magic.h"


undefined4 Ai_Subsystem_004af640(int arg1,int arg2)

{
  uint local_8;
  
  KillTimer(g_MainAppHwnd,DAT_006fdbd4);
  EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  if ((DAT_006808ac != arg1) || (DAT_006a2834 != arg2)) {
    local_8 = local_8 | 1;
  }
  DAT_006808ac = arg1;
  DAT_006a2834 = arg2;
  DAT_006a48e0 = DAT_006a5f20;
  LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  if (local_8 != 0) {
    SendMessageA(DAT_006a284c,0x432,0,0);
    UpdateWindow(DAT_006a284c);
    SendMessageA(DAT_006a283c,0x432,0,0);
    UpdateWindow(DAT_006a283c);
  }
  if ((arg2 == 0x15) && (arg1 == 1)) {
    DAT_0069f6d0 = 0;
  }
  if ((arg2 == 0x15) && (DAT_006a5f20 != 0)) {
    FUN_00481586(DAT_006b3064);
  }
  if (arg2 == 0x1e) {
    FUN_00481586(DAT_006b3064);
  }
  return 0;
}



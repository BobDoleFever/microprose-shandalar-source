/*
 * Decompiled function: FUN_00440af9
 * Entry Point: 00440af9
 * Size: 293 bytes
 */
#include "duel.h"


undefined4 FUN_00440af9(int arg1,int arg2)

{
  uint local_8;
  
  KillTimer(DAT_00618990,DAT_00663610);
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  if ((DAT_005f77e8 != arg1) || (DAT_006152e4 != arg2)) {
    local_8 = local_8 | 1;
  }
  DAT_005f77e8 = arg1;
  DAT_006152e4 = arg2;
  DAT_00617370 = DAT_006826b0;
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  if (local_8 != 0) {
    SendMessageA(DAT_006152ec,0x432,0,0);
    UpdateWindow(DAT_006152ec);
    SendMessageA(DAT_006152e8,0x432,0,0);
    UpdateWindow(DAT_006152e8);
  }
  if ((arg2 == 0x15) && (arg1 == 1)) {
    DAT_006152b4 = 0;
  }
  if ((arg2 == 0x15) && (DAT_006826b0 != 0)) {
    FUN_0049793e(DAT_00618ab0);
  }
  if (arg2 == 0x1e) {
    FUN_0049793e(DAT_00618ab0);
  }
  return 0;
}



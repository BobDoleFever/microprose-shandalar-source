/*
 * Decompiled function: FUN_0046aa75
 * Entry Point: 0046aa75
 * Size: 176 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0046aa75(HWND hwnd)

{
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_c = GetWindowLongA(hwnd,0);
  local_10 = GetWindowLongA(hwnd,4);
  local_8 = Ai_Subsystem_004b5cbb(local_c,local_10);
  if (local_8 == DAT_006ff2dc) {
    Ai_Subsystem_004b6da5(&local_18,local_c,local_10);
    _DAT_00538de4 = local_18;
    _DAT_00538de8 = local_14;
  }
  else {
    _DAT_00538de4 = local_c;
    _DAT_00538de8 = local_10;
  }
  _DAT_00538de0 = 0;
  PostMessageA(g_MainAppHwnd,0x464,0,0x538de0);
  return;
}



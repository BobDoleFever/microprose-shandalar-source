/*
 * Decompiled function: FUN_004852b1
 * Entry Point: 004852b1
 * Size: 176 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004852b1(HWND hwnd)

{
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_c = GetWindowLongA(hwnd,0);
  local_10 = GetWindowLongA(hwnd,4);
  local_8 = FUN_00447184(local_c,local_10);
  if (local_8 == DAT_0068f0fc) {
    FUN_0044826e(&local_18,local_c,local_10);
    _DAT_005daddc = local_18;
    _DAT_005dade0 = local_14;
  }
  else {
    _DAT_005daddc = local_c;
    _DAT_005dade0 = local_10;
  }
  _DAT_005dadd8 = 0;
  PostMessageA(DAT_00618990,0x464,0,0x5dadd8);
  return;
}



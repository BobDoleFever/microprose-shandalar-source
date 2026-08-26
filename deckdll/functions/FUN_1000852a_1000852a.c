/*
 * Decompiled function: FUN_1000852a
 * Entry Point: 1000852a
 * Size: 259 bytes
 */
#include "deckdll.h"


void FUN_1000852a(HWND hwnd,int *arg2)

{
  int val_1;
  int val_2;
  HWND local_1c;
  HWND local_14;
  int local_c;
  int local_8;
  
  val_1 = DAT_10176860 * 0x12;
  val_2 = DAT_10176860 / 10;
  local_8 = *arg2 + val_2;
  local_c = arg2[1] + val_2;
  local_1c = (HWND)0x0;
  for (local_14 = GetTopWindow(hwnd); local_14 != (HWND)0x0; local_14 = GetWindow(local_14,2)) {
    local_1c = local_14;
  }
  for (local_14 = local_1c; local_14 != (HWND)0x0; local_14 = GetWindow(local_14,3)) {
    if (arg2[3] < DAT_10176860 + local_c) {
      local_8 = local_8 + DAT_10175558 + 8;
      local_c = arg2[1] + val_2;
    }
    SetWindowPos(local_14,(HWND)0x0,local_8,local_c,DAT_10175558,DAT_10176860,4);
    local_c = local_c + val_1 / 100;
  }
  return;
}



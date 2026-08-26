/*
 * Decompiled function: FUN_004b7f54
 * Entry Point: 004b7f54
 * Size: 173 bytes
 */
#include "duel.h"


void FUN_004b7f54(HWND hwnd)

{
  BOOL BVar1;
  tagRECT local_24;
  tagRECT local_14;
  
  BVar1 = IsWindowVisible(DAT_00663df0);
  if (BVar1 == 0) {
    BVar1 = IsWindowVisible(DAT_00618ab0);
    if (BVar1 == 0) {
      GetWindowRect(DAT_00618988,&local_24);
      GetWindowRect(hwnd,&local_14);
      local_24.bottom = local_24.bottom - (local_14.bottom - local_14.top) / 2;
    }
    else {
      GetWindowRect(DAT_00694748,&local_24);
    }
  }
  else {
    GetWindowRect(DAT_00663df0,&local_24);
  }
  SetWindowPos(hwnd,(HWND)0x0,local_24.left,local_24.bottom,0,0,5);
  return;
}



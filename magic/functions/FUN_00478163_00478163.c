/*
 * Decompiled function: FUN_00478163
 * Entry Point: 00478163
 * Size: 172 bytes
 */
#include "magic.h"


void FUN_00478163(HWND hwnd)

{
  BOOL BVar1;
  tagRECT local_24;
  tagRECT local_14;
  
  BVar1 = IsWindowVisible(DAT_006fe3fc);
  if (BVar1 == 0) {
    BVar1 = IsWindowVisible(DAT_006b3064);
    if (BVar1 == 0) {
      GetWindowRect(DAT_006b2e2c,&local_24);
      GetWindowRect(hwnd,&local_14);
      local_24.bottom = local_24.bottom - (local_14.bottom - local_14.top) / 2;
    }
    else {
      GetWindowRect(DAT_006b2e24,&local_24);
    }
  }
  else {
    GetWindowRect(DAT_006fe3fc,&local_24);
  }
  SetWindowPos(hwnd,(HWND)0x0,local_24.left,local_24.bottom,0,0,5);
  return;
}



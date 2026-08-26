/*
 * Decompiled function: FUN_0047256e
 * Entry Point: 0047256e
 * Size: 65 bytes
 */
#include "duel.h"


undefined4 FUN_0047256e(HWND hwnd)

{
  int iVar1;
  
  iVar1 = FUN_004726e4(hwnd);
  if (iVar1 != 0) {
    DAT_00693418 = SetWindowLongA(hwnd,-4,0x4725af);
  }
  return 1;
}



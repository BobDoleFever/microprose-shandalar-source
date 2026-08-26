/*
 * Decompiled function: FUN_004f5728
 * Entry Point: 004f5728
 * Size: 65 bytes
 */
#include "magic.h"


undefined4 FUN_004f5728(HWND hwnd)

{
  int iVar1;
  
  iVar1 = FUN_004f589e(hwnd);
  if (iVar1 != 0) {
    DAT_0063eedc = SetWindowLongA(hwnd,-4,0x4f5769);
  }
  return 1;
}



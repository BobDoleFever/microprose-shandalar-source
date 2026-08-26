/*
 * Decompiled function: FUN_004f5ec4
 * Entry Point: 004f5ec4
 * Size: 84 bytes
 */
#include "magic.h"


undefined4 FUN_004f5ec4(HWND hwnd,int *arg2)

{
  HWND pHVar1;
  
  pHVar1 = GetParent(hwnd);
  if (pHVar1 == (HWND)*arg2) {
    SendMessageA(hwnd,arg2[1],arg2[2],arg2[3]);
  }
  return 1;
}



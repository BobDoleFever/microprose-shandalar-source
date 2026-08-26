/*
 * Decompiled function: FUN_00472d0a
 * Entry Point: 00472d0a
 * Size: 84 bytes
 */
#include "duel.h"


undefined4 FUN_00472d0a(HWND hwnd,int *arg2)

{
  HWND pHVar1;
  
  pHVar1 = GetParent(hwnd);
  if (pHVar1 == (HWND)*arg2) {
    SendMessageA(hwnd,arg2[1],arg2[2],arg2[3]);
  }
  return 1;
}



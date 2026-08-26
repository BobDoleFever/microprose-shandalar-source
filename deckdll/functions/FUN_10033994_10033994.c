/*
 * Decompiled function: FUN_10033994
 * Entry Point: 10033994
 * Size: 84 bytes
 */
#include "deckdll.h"


int32_t FUN_10033994(HWND hwnd,int *arg2)

{
  HWND pHVar1;
  
  pHVar1 = GetParent(hwnd);
  if (pHVar1 == (HWND)*arg2) {
    SendMessageA(hwnd,arg2[1],arg2[2],arg2[3]);
  }
  return 1;
}



/*
 * Decompiled function: FUN_1000842b
 * Entry Point: 1000842b
 * Size: 111 bytes
 */
#include "deckdll.h"


void FUN_1000842b(HWND hwnd,int arg2)

{
  LRESULT LVar1;
  int32_t local_c;
  
  for (local_c = GetTopWindow(hwnd); local_c != (HWND)0x0; local_c = GetWindow(local_c,2)) {
    LVar1 = SendMessageA(local_c,0x400,0,0);
    if (LVar1 == arg2) {
      InvalidateRect(local_c,(RECT *)0x0,1);
    }
  }
  return;
}



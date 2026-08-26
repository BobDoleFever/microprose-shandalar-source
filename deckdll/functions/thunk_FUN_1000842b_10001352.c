/*
 * Decompiled function: thunk_FUN_1000842b
 * Entry Point: 10001352
 * Size: 5 bytes
 */
#include "deckdll.h"


void thunk_FUN_1000842b(HWND hwnd,int arg2)

{
  LRESULT LVar1;
  int32_t uStack_c;
  
  for (uStack_c = GetTopWindow(hwnd); uStack_c != (HWND)0x0; uStack_c = GetWindow(uStack_c,2)) {
    LVar1 = SendMessageA(uStack_c,0x400,0,0);
    if (LVar1 == arg2) {
      InvalidateRect(uStack_c,(RECT *)0x0,1);
    }
  }
  return;
}



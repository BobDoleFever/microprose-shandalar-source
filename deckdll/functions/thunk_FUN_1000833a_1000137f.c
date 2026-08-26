/*
 * Decompiled function: thunk_FUN_1000833a
 * Entry Point: 1000137f
 * Size: 5 bytes
 */
#include "deckdll.h"


HWND thunk_FUN_1000833a(HWND hwnd,int arg2)

{
  LRESULT LVar1;
  int32_t uStack_c;
  int32_t uStack_8;
  
  uStack_8 = (HWND)0x0;
  for (uStack_c = GetTopWindow(hwnd); uStack_c != (HWND)0x0; uStack_c = GetWindow(uStack_c,2)) {
    LVar1 = SendMessageA(uStack_c,0x400,0,0);
    if (LVar1 == arg2) {
      uStack_8 = uStack_c;
    }
  }
  return uStack_8;
}



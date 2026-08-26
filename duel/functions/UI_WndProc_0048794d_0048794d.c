/*
 * Decompiled function: UI_WndProc_0048794d
 * Entry Point: 0048794d
 * Size: 179 bytes
 */
#include "duel.h"


LRESULT UI_WndProc_0048794d(HWND hwnd,uint uMsg,HDC wParam,LPARAM lParam)

{
  LRESULT LVar1;
  tagRECT local_14;
  
  if (uMsg == 0x14) {
    FUN_004707a4(wParam);
    GetClientRect(hwnd,&local_14);
    FUN_0042043e(wParam,&local_14);
    LVar1 = 0;
  }
  else if ((uMsg < 0x30f) || (0x311 < uMsg)) {
    LVar1 = DefWindowProcA(hwnd,uMsg,(WPARAM)wParam,lParam);
  }
  else {
    LVar1 = FUN_00472b60(hwnd,uMsg,(HWND)wParam,lParam);
  }
  return LVar1;
}



/*
 * Decompiled function: UI_WndProc_004f4fb8
 * Entry Point: 004f4fb8
 * Size: 134 bytes
 */
#include "magic.h"


LRESULT UI_WndProc_004f4fb8(HWND hwnd,UINT uMsg,WPARAM wParam,LPARAM lParam)

{
  HCURSOR hCursor;
  LRESULT LVar1;
  
  if (uMsg == 0x20) {
    if (DAT_006b1578 == 0) {
      hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f8a);
      SetCursor(hCursor);
      LVar1 = 0;
    }
    else {
      LVar1 = DefWindowProcA(hwnd,0x20,wParam,lParam);
    }
  }
  else {
    LVar1 = DefWindowProcA(hwnd,uMsg,wParam,lParam);
  }
  return LVar1;
}



/*
 * Decompiled function: UI_WndProc_00471df6
 * Entry Point: 00471df6
 * Size: 134 bytes
 */
#include "duel.h"


LRESULT UI_WndProc_00471df6(HWND hwnd,UINT uMsg,WPARAM wParam,LPARAM lParam)

{
  HCURSOR hCursor;
  LRESULT LVar1;
  
  if (uMsg == 0x20) {
    if (DAT_00618158 == 0) {
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



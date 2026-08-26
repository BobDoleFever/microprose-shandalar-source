/*
 * Decompiled function: UI_WndProc_0050c854
 * Entry Point: 0050c854
 * Size: 179 bytes
 */
#include "magic.h"


LRESULT UI_WndProc_0050c854(HWND hwnd,uint uMsg,HDC wParam,LPARAM lParam)

{
  LRESULT LVar1;
  tagRECT local_14;
  
  if (uMsg == 0x14) {
    FUN_004f3955(wParam);
    GetClientRect(hwnd,&local_14);
    Palette_Subsystem_0049c6cb(wParam,&local_14);
    LVar1 = 0;
  }
  else if ((uMsg < 0x30f) || (0x311 < uMsg)) {
    LVar1 = DefWindowProcA(hwnd,uMsg,(WPARAM)wParam,lParam);
  }
  else {
    LVar1 = FUN_004f5d1a(hwnd,uMsg,(HWND)wParam,lParam);
  }
  return LVar1;
}



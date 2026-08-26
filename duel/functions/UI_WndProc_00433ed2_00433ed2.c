/*
 * Decompiled function: UI_WndProc_00433ed2
 * Entry Point: 00433ed2
 * Size: 516 bytes
 */
#include "duel.h"


LRESULT UI_WndProc_00433ed2(HWND hwnd,uint uMsg,HDC wParam,LPARAM lParam)

{
  HDC hdc;
  LRESULT LVar1;
  tagPAINTSTRUCT local_134;
  CHAR local_f4 [200];
  tagRECT local_2c;
  HDC local_1c;
  tagRECT local_18;
  HBRUSH local_8;
  
  if (uMsg < 0xd) {
    if (uMsg == 0xc) {
      InvalidateRect(hwnd,(RECT *)0x0,1);
      LVar1 = DefWindowProcA(hwnd,0xc,(WPARAM)wParam,lParam);
      return LVar1;
    }
    if (uMsg == 1) {
      return 0;
    }
  }
  else if (uMsg < 0x15) {
    if (uMsg == 0x14) {
      local_1c = wParam;
      FUN_004707a4(wParam);
      GetClientRect(hwnd,&local_18);
      local_8 = CreateSolidBrush(0xffff);
      FillRect(local_1c,&local_18,local_8);
      DeleteObject(local_8);
      return 1;
    }
    if (uMsg == 0xf) {
      hdc = BeginPaint(hwnd,&local_134);
      if (hdc != (HDC)0x0) {
        FUN_004707a4(hdc);
        GetWindowTextA(hwnd,local_f4,200);
        SetTextAlign(hdc,6);
        SetBkMode(hdc,1);
        SetTextColor(hdc,0);
        GetClientRect(hwnd,&local_2c);
        FUN_0042233a(hdc,&local_2c.left,local_f4,1);
        EndPaint(hwnd,&local_134);
      }
      return 0;
    }
  }
  else if ((0x30e < uMsg) && (uMsg < 0x312)) {
    LVar1 = FUN_00472b60(hwnd,uMsg,(HWND)wParam,lParam);
    return LVar1;
  }
  LVar1 = DefWindowProcA(hwnd,uMsg,(WPARAM)wParam,lParam);
  return LVar1;
}



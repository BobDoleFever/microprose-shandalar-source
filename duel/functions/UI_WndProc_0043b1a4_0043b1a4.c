/*
 * Decompiled function: UI_WndProc_0043b1a4
 * Entry Point: 0043b1a4
 * Size: 705 bytes
 */
#include "duel.h"


LRESULT UI_WndProc_0043b1a4(HWND hwnd,uint uMsg,WPARAM wParam,LPARAM lParam)

{
  BOOL BVar1;
  LONG LVar2;
  WPARAM WVar3;
  HBRUSH hbr;
  HDC hdc;
  LRESULT LVar4;
  tagPAINTSTRUCT local_58;
  tagRECT local_18;
  WPARAM local_8;
  
  if (uMsg < 0x10) {
    if (uMsg == 0xf) {
      local_8 = GetWindowLongA(hwnd,0);
      GetClientRect(hwnd,&local_18);
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00664b70);
      hbr = GetStockObject(4);
      FillRect(DAT_0060157c,&local_18,hbr);
      Palette_Subsystem_0049c7c7
                (DAT_0060157c,&local_18.left,(undefined4 *)(&DAT_00618ac0 + local_8 * 0x98),0,0x11,0
                );
      hdc = BeginPaint(hwnd,&local_58);
      if (hdc != (HDC)0x0) {
        FUN_004707a4(hdc);
        BitBlt(hdc,0,0,local_18.right,local_18.bottom,DAT_0060157c,0,0,0xcc0020);
        EndPaint(hwnd,&local_58);
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00664b70);
      return 0;
    }
    if (uMsg == 1) {
      local_8 = 0xffffffff;
      SetWindowLongA(hwnd,0,-1);
      return 0;
    }
  }
  else if (uMsg < 0x312) {
    if (0x30e < uMsg) {
      LVar4 = FUN_00472b60(hwnd,uMsg,(HWND)wParam,lParam);
      return LVar4;
    }
    if (uMsg == 0x206) {
      local_8 = GetWindowLongA(hwnd,0);
      if (DAT_00663e24 == 2) {
        SendMessageA(DAT_006152e0,0x401,local_8,0);
      }
      return 0;
    }
  }
  else {
    if (uMsg == 0x400) {
      LVar2 = GetWindowLongA(hwnd,0);
      return LVar2;
    }
    if (uMsg == 0x401) {
      WVar3 = GetWindowLongA(hwnd,0);
      if (wParam != WVar3) {
        local_8 = wParam;
        SetWindowLongA(hwnd,0,wParam);
        InvalidateRect(hwnd,(RECT *)0x0,0);
      }
      return 0;
    }
    if (uMsg == 0x437) {
      local_8 = GetWindowLongA(hwnd,0);
      if ((DAT_00663e24 != 2) || (BVar1 = IsWindowVisible(DAT_006152e0), BVar1 != 0)) {
        SendMessageA(DAT_006152e0,0x401,local_8,0);
      }
      return 0;
    }
  }
  LVar4 = DefWindowProcA(hwnd,uMsg,wParam,lParam);
  return LVar4;
}



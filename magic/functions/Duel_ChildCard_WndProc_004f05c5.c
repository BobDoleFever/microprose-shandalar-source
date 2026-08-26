/*
 * Decompiled function: Duel_ChildCard_WndProc
 * Entry Point: 004f05c5
 * Size: 1007 bytes
 */
#include "magic.h"


LRESULT Duel_ChildCard_WndProc(HWND hwnd,uint uMsg,WPARAM wParam,LPARAM lParam)

{
  LONG LVar1;
  LRESULT LVar2;
  CHAR local_2d8 [500];
  CHAR local_e4 [100];
  HDC local_80;
  tagPAINTSTRUCT local_7c;
  tagRECT local_3c;
  tagRECT local_2c;
  tagRECT local_1c;
  HGDIOBJ local_c;
  WPARAM local_8;
  
  if (uMsg < 0x10) {
    if (uMsg == 0xf) {
      local_c = (HGDIOBJ)GetWindowLongA(hwnd,0);
      local_80 = BeginPaint(hwnd,&local_7c);
      if (local_80 != (HDC)0x0) {
        FUN_004f3955(local_80);
        SetTextColor(local_80,DAT_00565a00);
        SetBkMode(local_80,1);
        SelectObject(local_80,local_c);
        GetWindowTextA(hwnd,local_e4,100);
        GetClientRect(hwnd,&local_3c);
        local_3c.left = local_3c.left + 10;
        SetMapMode(local_80,8);
        SetWindowExtEx(local_80,local_3c.right - local_3c.left,0x14,(LPSIZE)0x0);
        SetViewportExtEx(local_80,local_3c.right - local_3c.left,local_3c.bottom - local_3c.top,
                         (LPSIZE)0x0);
        DrawTextA(local_80,local_e4,-1,&local_3c,8);
        EndPaint(hwnd,&local_7c);
      }
      return 0;
    }
    if (uMsg == 1) {
      local_c = (HGDIOBJ)DAT_00565a04;
      SetWindowLongA(hwnd,0,DAT_00565a04);
      GetWindowRect(hwnd,&local_2c);
      local_8 = local_2c.right - local_2c.left;
      SetWindowLongA(hwnd,4,local_8);
      return 0;
    }
  }
  else if (uMsg < 0x19) {
    if (uMsg == 0x18) {
      if (wParam != 0) {
        SetTimer(hwnd,1,10000,(TIMERPROC)0x0);
      }
      LVar2 = DefWindowProcA(hwnd,0x18,wParam,lParam);
      return LVar2;
    }
    if (uMsg == 0x10) {
      ShowWindow(hwnd,0);
      return 0;
    }
  }
  else if (uMsg < 0x114) {
    if (uMsg == 0x113) {
      KillTimer(hwnd,1);
      ShowWindow(hwnd,0);
      return 0;
    }
    if (uMsg == 0x30) {
      local_c = (HGDIOBJ)wParam;
      if (wParam == 0) {
        local_c = (HGDIOBJ)DAT_00565a04;
      }
      SetWindowLongA(hwnd,0,(LONG)local_c);
      InvalidateRect(hwnd,(RECT *)0x0,1);
      GetWindowTextA(hwnd,local_2d8,500);
      SetWindowTextA(hwnd,local_2d8);
      return 0;
    }
    if (uMsg == 0x31) {
      LVar1 = GetWindowLongA(hwnd,0);
      return LVar1;
    }
  }
  else if (uMsg < 0x312) {
    if (0x30e < uMsg) {
      LVar2 = FUN_004f5d1a(hwnd,uMsg,(HWND)wParam,lParam);
      return LVar2;
    }
    if (uMsg == 0x201) {
      SendMessageA(hwnd,0x113,1,0);
      return 0;
    }
  }
  else {
    if (uMsg == 0x400) {
      LVar1 = GetWindowLongA(hwnd,4);
      return LVar1;
    }
    if (uMsg == 0x401) {
      local_8 = wParam;
      SetWindowLongA(hwnd,4,wParam);
      GetWindowRect(hwnd,&local_1c);
      if (local_1c.right - local_1c.left < (int)local_8) {
        SetWindowPos(hwnd,(HWND)0x0,0,0,local_8,local_1c.bottom - local_1c.top,6);
      }
      return 0;
    }
  }
  LVar2 = DefWindowProcA(hwnd,uMsg,wParam,lParam);
  return LVar2;
}



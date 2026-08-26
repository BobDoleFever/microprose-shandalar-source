/*
 * Decompiled function: UI_WndProc_0040836a
 * Entry Point: 0040836a
 * Size: 1111 bytes
 */
#include "magic.h"


LRESULT UI_WndProc_0040836a(HWND hwnd,uint uMsg,uint wParam,LPSTR lParam)

{
  int c;
  LONG LVar1;
  HWND hWnd;
  LRESULT LVar2;
  tagSIZE *psizl;
  uint local_104;
  CHAR local_100 [100];
  HDC local_9c;
  tagPAINTSTRUCT local_98;
  tagRECT local_58;
  tagRECT local_48;
  uint local_38;
  LPSTR local_34;
  int local_30;
  HDC local_2c;
  int local_28;
  uint local_24;
  uint local_20;
  int local_1c;
  LPSTR local_18;
  tagSIZE local_14;
  int local_c;
  HGDIOBJ local_8;
  
  if (uMsg < 0x10) {
    if (uMsg == 0xf) {
      local_8 = (HGDIOBJ)GetWindowLongA(hwnd,0);
      local_9c = BeginPaint(hwnd,&local_98);
      if (local_9c != (HDC)0x0) {
        FUN_004f3955(local_9c);
        GetClientRect(hwnd,&local_48);
        SetRect(&local_58,local_48.left,local_48.top,local_48.right + -2,local_48.bottom + -2);
        FillRect(local_9c,&local_48,DAT_005382e4);
        FillRect(local_9c,&local_58,DAT_005382e8);
        SetTextColor(local_9c,DAT_005382e0);
        SetBkMode(local_9c,1);
        GetWindowTextA(hwnd,local_100,100);
        SelectObject(local_9c,local_8);
        DrawTextA(local_9c,local_100,-1,&local_58,0x25);
        EndPaint(hwnd,&local_98);
      }
      return 0;
    }
    if (uMsg == 1) {
      local_8 = (HGDIOBJ)DAT_005382dc;
      SetWindowLongA(hwnd,0,DAT_005382dc);
      return 0;
    }
  }
  else if (uMsg < 0x31) {
    if (uMsg == 0x30) {
      local_104 = wParam;
      if (wParam == 0) {
        local_104 = DAT_005382dc;
      }
      SetWindowLongA(hwnd,0,local_104);
      InvalidateRect(hwnd,(RECT *)0x0,1);
      return 0;
    }
    if (uMsg == 0x14) {
      return 1;
    }
  }
  else if (uMsg < 0x101) {
    if (uMsg == 0x100) {
      SetFocus(g_MainAppHwnd);
      hWnd = GetFocus();
      PostMessageA(hWnd,uMsg,wParam,(LPARAM)lParam);
      return 0;
    }
    if (uMsg == 0x31) {
      LVar1 = GetWindowLongA(hwnd,0);
      return LVar1;
    }
  }
  else {
    switch(uMsg) {
    case 0x30f:
    case 0x310:
    case 0x311:
      LVar2 = FUN_004f5d1a(hwnd,uMsg,(HWND)wParam,lParam);
      return LVar2;
    case 0x400:
      local_8 = (HGDIOBJ)GetWindowLongA(hwnd,0);
      local_20 = wParam & 0xffff;
      local_24 = wParam >> 0x10;
      local_18 = lParam;
      local_2c = GetDC(hwnd);
      if (local_2c != (HDC)0x0) {
        FUN_004f3955(local_2c);
        SelectObject(local_2c,local_8);
        psizl = &local_14;
        c = lstrlenA(local_18);
        GetTextExtentPoint32A(local_2c,local_18,c,psizl);
        local_28 = local_14.cx + 10;
        local_30 = local_14.cy + 6;
        ReleaseDC(hwnd,local_2c);
        local_1c = GetSystemMetrics(0);
        local_c = GetSystemMetrics(1);
        if ((int)local_20 < 1) {
          local_20 = 1;
        }
        if (local_1c + -1 < (int)(local_28 + local_20)) {
          local_20 = (local_1c + -1) - local_28;
        }
        if ((int)local_24 < 1) {
          local_24 = 1;
        }
        if (local_c + -1 < (int)(local_30 + local_24)) {
          local_24 = (local_c + -1) - local_30;
        }
        MoveWindow(hwnd,local_20,local_24,local_28,local_30,1);
        SetWindowTextA(hwnd,local_18);
        ShowWindow(hwnd,5);
        InvalidateRect(hwnd,(RECT *)0x0,1);
      }
      return 0;
    case 0x401:
      local_34 = lParam;
      local_38 = wParam;
      GetWindowTextA(hwnd,lParam,wParam);
      return 0;
    }
  }
  LVar2 = DefWindowProcA(hwnd,uMsg,wParam,(LPARAM)lParam);
  return LVar2;
}



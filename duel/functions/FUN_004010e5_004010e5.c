/*
 * Decompiled function: FUN_004010e5
 * Entry Point: 004010e5
 * Size: 1007 bytes
 */
#include "duel.h"


LRESULT FUN_004010e5(HWND param_1,uint param_2,WPARAM param_3,LPARAM param_4)

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
  
  if (param_2 < 0x10) {
    if (param_2 == 0xf) {
      local_c = (HGDIOBJ)GetWindowLongA(param_1,0);
      local_80 = BeginPaint(param_1,&local_7c);
      if (local_80 != (HDC)0x0) {
        FUN_004707a4(local_80);
        SetTextColor(local_80,DAT_0050abb0);
        SetBkMode(local_80,1);
        SelectObject(local_80,local_c);
        GetWindowTextA(param_1,local_e4,100);
        GetClientRect(param_1,&local_3c);
        local_3c.left = local_3c.left + 10;
        SetMapMode(local_80,8);
        SetWindowExtEx(local_80,local_3c.right - local_3c.left,0x14,(LPSIZE)0x0);
        SetViewportExtEx(local_80,local_3c.right - local_3c.left,local_3c.bottom - local_3c.top,
                         (LPSIZE)0x0);
        DrawTextA(local_80,local_e4,-1,&local_3c,8);
        EndPaint(param_1,&local_7c);
      }
      return 0;
    }
    if (param_2 == 1) {
      local_c = (HGDIOBJ)DAT_0050abb4;
      SetWindowLongA(param_1,0,DAT_0050abb4);
      GetWindowRect(param_1,&local_2c);
      local_8 = local_2c.right - local_2c.left;
      SetWindowLongA(param_1,4,local_8);
      return 0;
    }
  }
  else if (param_2 < 0x19) {
    if (param_2 == 0x18) {
      if (param_3 != 0) {
        SetTimer(param_1,1,10000,(TIMERPROC)0x0);
      }
      LVar2 = DefWindowProcA(param_1,0x18,param_3,param_4);
      return LVar2;
    }
    if (param_2 == 0x10) {
      ShowWindow(param_1,0);
      return 0;
    }
  }
  else if (param_2 < 0x114) {
    if (param_2 == 0x113) {
      KillTimer(param_1,1);
      ShowWindow(param_1,0);
      return 0;
    }
    if (param_2 == 0x30) {
      local_c = (HGDIOBJ)param_3;
      if (param_3 == 0) {
        local_c = (HGDIOBJ)DAT_0050abb4;
      }
      SetWindowLongA(param_1,0,(LONG)local_c);
      InvalidateRect(param_1,(RECT *)0x0,1);
      GetWindowTextA(param_1,local_2d8,500);
      SetWindowTextA(param_1,local_2d8);
      return 0;
    }
    if (param_2 == 0x31) {
      LVar1 = GetWindowLongA(param_1,0);
      return LVar1;
    }
  }
  else if (param_2 < 0x312) {
    if (0x30e < param_2) {
      LVar2 = FUN_00472b60(param_1,param_2,param_3,param_4);
      return LVar2;
    }
    if (param_2 == 0x201) {
      SendMessageA(param_1,0x113,1,0);
      return 0;
    }
  }
  else {
    if (param_2 == 0x400) {
      LVar1 = GetWindowLongA(param_1,4);
      return LVar1;
    }
    if (param_2 == 0x401) {
      local_8 = param_3;
      SetWindowLongA(param_1,4,param_3);
      GetWindowRect(param_1,&local_1c);
      if (local_1c.right - local_1c.left < (int)local_8) {
        SetWindowPos(param_1,(HWND)0x0,0,0,local_8,local_1c.bottom - local_1c.top,6);
      }
      return 0;
    }
  }
  LVar2 = DefWindowProcA(param_1,param_2,param_3,param_4);
  return LVar2;
}



/*
 * Decompiled function: FUN_0049198a
 * Entry Point: 0049198a
 * Size: 1114 bytes
 */
#include "duel.h"


LRESULT FUN_0049198a(HWND param_1,uint param_2,uint param_3,LPSTR param_4)

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
  
  if (param_2 < 0x10) {
    if (param_2 == 0xf) {
      local_8 = (HGDIOBJ)GetWindowLongA(param_1,0);
      local_9c = BeginPaint(param_1,&local_98);
      if (local_9c != (HDC)0x0) {
        FUN_004707a4(local_9c);
        GetClientRect(param_1,&local_48);
        SetRect(&local_58,local_48.left,local_48.top,local_48.right + -2,local_48.bottom + -2);
        FillRect(local_9c,&local_48,DAT_005daf0c);
        FillRect(local_9c,&local_58,DAT_005daf10);
        SetTextColor(local_9c,DAT_005daf08);
        SetBkMode(local_9c,1);
        GetWindowTextA(param_1,local_100,100);
        SelectObject(local_9c,local_8);
        DrawTextA(local_9c,local_100,-1,&local_58,0x25);
        EndPaint(param_1,&local_98);
      }
      return 0;
    }
    if (param_2 == 1) {
      local_8 = (HGDIOBJ)DAT_005daf04;
      SetWindowLongA(param_1,0,DAT_005daf04);
      return 0;
    }
  }
  else if (param_2 < 0x31) {
    if (param_2 == 0x30) {
      local_104 = param_3;
      if (param_3 == 0) {
        local_104 = DAT_005daf04;
      }
      SetWindowLongA(param_1,0,local_104);
      InvalidateRect(param_1,(RECT *)0x0,1);
      return 0;
    }
    if (param_2 == 0x14) {
      return 1;
    }
  }
  else if (param_2 < 0x101) {
    if (param_2 == 0x100) {
      SetFocus(DAT_00618990);
      hWnd = GetFocus();
      PostMessageA(hWnd,param_2,param_3,(LPARAM)param_4);
      return 0;
    }
    if (param_2 == 0x31) {
      LVar1 = GetWindowLongA(param_1,0);
      return LVar1;
    }
  }
  else {
    switch(param_2) {
    case 0x30f:
    case 0x310:
    case 0x311:
      LVar2 = FUN_00472b60(param_1,param_2,param_3,param_4);
      return LVar2;
    case 0x400:
      local_8 = (HGDIOBJ)GetWindowLongA(param_1,0);
      local_20 = param_3 & 0xffff;
      local_24 = param_3 >> 0x10;
      local_18 = param_4;
      local_2c = GetDC(param_1);
      if (local_2c != (HDC)0x0) {
        FUN_004707a4(local_2c);
        SelectObject(local_2c,local_8);
        psizl = &local_14;
        c = lstrlenA(local_18);
        GetTextExtentPoint32A(local_2c,local_18,c,psizl);
        local_28 = local_14.cx + 10;
        local_30 = local_14.cy + 6;
        ReleaseDC(param_1,local_2c);
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
        MoveWindow(param_1,local_20,local_24,local_28,local_30,1);
        SetWindowTextA(param_1,local_18);
        ShowWindow(param_1,5);
        InvalidateRect(param_1,(RECT *)0x0,1);
      }
      return 0;
    case 0x401:
      local_34 = param_4;
      local_38 = param_3;
      GetWindowTextA(param_1,param_4,param_3);
      return 0;
    }
  }
  LVar2 = DefWindowProcA(param_1,param_2,param_3,(LPARAM)param_4);
  return LVar2;
}



/*
 * Decompiled function: UI_WndProc_004090f6
 * Entry Point: 004090f6
 * Size: 1750 bytes
 */
#include "magic.h"


LRESULT UI_WndProc_004090f6(HWND hwnd,uint uMsg,uint wParam,uint lParam)

{
  LONG LVar1;
  uint uVar2;
  UINT dwMilliseconds;
  HBRUSH hbr;
  int iVar3;
  LRESULT LVar4;
  int local_278;
  char local_274 [100];
  uint local_210;
  char local_20c [100];
  tagPOINT local_1a8;
  tagRECT local_1a0;
  HDC local_190;
  tagPAINTSTRUCT local_18c;
  tagRECT local_14c;
  tagMSG local_13c;
  uint local_120;
  char local_11c [264];
  ULONG_PTR local_14;
  uint local_10;
  HANDLE local_c;
  uint local_8;
  
  if (uMsg < 0x10) {
    if (uMsg == 0xf) {
      local_c = (HANDLE)GetWindowLongA(hwnd,0);
      local_190 = BeginPaint(hwnd,&local_18c);
      if (local_190 != (HDC)0x0) {
        FUN_004f3955(local_190);
        GetClientRect(hwnd,&local_14c);
        if (local_c == (HANDLE)0x0) {
          hbr = GetStockObject(4);
          FillRect(local_190,&local_14c,hbr);
        }
        else {
          FUN_004097e2(local_190,&local_14c,(uint)(hwnd != DAT_0068a620));
        }
        EndPaint(hwnd,&local_18c);
      }
      return 0;
    }
    if (uMsg == 1) {
      local_c = (HANDLE)0x0;
      SetWindowLongA(hwnd,0,0);
      local_8 = 0;
      SetWindowLongA(hwnd,4,0);
      return 0;
    }
    if (uMsg == 2) {
      local_c = (HANDLE)GetWindowLongA(hwnd,0);
      local_8 = GetWindowLongA(hwnd,4);
      if ((local_c != (HANDLE)0x0) && (local_8 == 0)) {
        FUN_004f4548(local_c);
      }
      return 0;
    }
  }
  else if (uMsg < 0x112) {
    if (uMsg == 0x111) {
      uVar2 = wParam & 0xffff;
      if (uVar2 == 100) {
        FUN_00409b2c((uint)(hwnd != DAT_0068a620),0);
      }
      else if (uVar2 == 0x65) {
        local_14 = 0xbdf;
        strcpy(local_11c,&DAT_006807a0);
        strcat(local_11c,s__duel_hlp_00516c60);
        WinHelpA(g_MainAppHwnd,local_11c,1,local_14);
      }
      else if (uVar2 == 0x66) {
        local_10 = (uint)(hwnd != DAT_0068a620);
        DAT_00627864 = 0;
        FUN_00409c73(local_10);
      }
      return 0;
    }
    if (uMsg == 0x20) {
      LVar4 = UI_WndProc_004f4fb8(hwnd,0x20,wParam,lParam);
      return LVar4;
    }
  }
  else if (uMsg < 0x120) {
    if (uMsg == 0x11f) {
      if ((wParam >> 0x10 == 0xffff) && (lParam == 0)) {
        local_278 = GetMenuItemCount(DAT_00538308);
        while (local_278 != 0) {
          DeleteMenu(DAT_00538308,0,0x400);
          local_278 = local_278 + -1;
        }
      }
      return 0;
    }
    if (uMsg == 0x117) {
      local_210 = (uint)(hwnd != DAT_006b2530);
      if ((DAT_006b1578 != 0) && (iVar3 = FUN_00409cb2(local_210), iVar3 != 0)) {
        if (local_210 == 1) {
          Ai_Subsystem_004b6f49(local_20c);
          sprintf(local_274,s_Target__s_00516c6c,local_20c);
        }
        else {
          strcpy(local_274,s_Target_yourself_00516c78);
        }
        AppendMenuA(DAT_00538308,0,0x66,local_274);
      }
      iVar3 = GetMenuItemCount(DAT_00538308);
      if (0 < iVar3) {
        AppendMenuA(DAT_00538308,0x800,0,(LPCSTR)0x0);
      }
      AppendMenuA(DAT_00538308,0,100,s_Flip_back_to_lifepoints_00516c88);
      AppendMenuA(DAT_00538308,0,0x65,s_Help____00516ca0);
      return 0;
    }
  }
  else if (uMsg < 0x205) {
    if (uMsg == 0x204) {
      local_1a8.x = lParam & 0xffff;
      local_1a8.y = lParam >> 0x10;
      ClientToScreen(hwnd,&local_1a8);
      SetRect(&local_1a0,local_1a8.x,local_1a8.y,local_1a8.x + 1,local_1a8.y + 1);
      TrackPopupMenu(DAT_00538308,2,local_1a8.x,local_1a8.y,0,hwnd,&local_1a0);
      return 0;
    }
    if (uMsg == 0x201) {
      local_120 = (uint)(hwnd != DAT_0068a620);
      if (DAT_006b1578 != 0) {
        dwMilliseconds = GetDoubleClickTime();
        Sleep(dwMilliseconds);
        DAT_00627864 = PeekMessageA(&local_13c,hwnd,0x203,0x203,0);
        FUN_00409c73(local_120);
      }
      return 0;
    }
  }
  else if (uMsg < 0x439) {
    if (uMsg == 0x438) {
      LVar1 = GetWindowLongA(hwnd,0);
      return LVar1;
    }
    if ((0x30e < uMsg) && (uMsg < 0x312)) {
      LVar4 = FUN_004f5d1a(hwnd,uMsg,(HWND)wParam,lParam);
      return LVar4;
    }
  }
  else if (uMsg == 0x439) {
    local_c = (HANDLE)GetWindowLongA(hwnd,0);
    local_8 = GetWindowLongA(hwnd,4);
    if ((local_c != (HANDLE)0x0) && (local_8 == 0)) {
      FUN_004f4548(local_c);
    }
    local_c = (HANDLE)wParam;
    local_8 = lParam;
    SetWindowLongA(hwnd,0,wParam);
    SetWindowLongA(hwnd,4,local_8);
    InvalidateRect(hwnd,(RECT *)0x0,0);
    return 0;
  }
  LVar4 = DefWindowProcA(hwnd,uMsg,wParam,lParam);
  return LVar4;
}



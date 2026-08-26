/*
 * Decompiled function: Ai_CalcManaRequirement_004b9284
 * Entry Point: 00436af6
 * Size: 1760 bytes
 */
#include "duel.h"


LRESULT Ai_CalcManaRequirement_004b9284(HWND hwnd,uint uMsg,uint wParam,uint lParam)

{
  LONG LVar1;
  uint uVar2;
  UINT dwMilliseconds;
  HBRUSH hbr;
  int iVar3;
  LRESULT LVar4;
  int local_278;
  uint local_274 [25];
  uint local_210;
  char local_20c [100];
  tagPOINT local_1a8;
  tagRECT local_1a0;
  HDC local_190;
  tagPAINTSTRUCT local_18c;
  tagRECT local_14c;
  tagMSG local_13c;
  uint local_120;
  uint local_11c [66];
  ULONG_PTR local_14;
  uint local_10;
  HANDLE local_c;
  uint local_8;
  
  if (uMsg < 0x10) {
    if (uMsg == 0xf) {
      local_c = (HANDLE)GetWindowLongA(hwnd,0);
      local_190 = BeginPaint(hwnd,&local_18c);
      if (local_190 != (HDC)0x0) {
        FUN_004707a4(local_190);
        GetClientRect(hwnd,&local_14c);
        if (local_c == (HANDLE)0x0) {
          hbr = GetStockObject(4);
          FillRect(local_190,&local_14c,hbr);
        }
        else {
          FUN_004371ec(local_190,&local_14c,(uint)(hwnd != DAT_00601550));
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
        FUN_00471395(local_c);
      }
      return 0;
    }
  }
  else if (uMsg < 0x112) {
    if (uMsg == 0x111) {
      uVar2 = wParam & 0xffff;
      if (uVar2 == 100) {
        FUN_0043753a((uint)(hwnd != DAT_00601550),0);
      }
      else if (uVar2 == 0x65) {
        local_14 = 0xbdf;
        Mem_AllocOrFree_004d9630(local_11c,(uint *)&DAT_005f76e0);
        FUN_004d9640(local_11c,(uint *)s__duel_hlp_004f6a40);
        WinHelpA(DAT_00618990,(LPCSTR)local_11c,1,local_14);
      }
      else if (uVar2 == 0x66) {
        local_10 = (uint)(hwnd != DAT_00601550);
        DAT_0066643c = 0;
        FUN_00437681(local_10);
      }
      return 0;
    }
    if (uMsg == 0x20) {
      LVar4 = UI_WndProc_00471df6(hwnd,0x20,wParam,lParam);
      return LVar4;
    }
  }
  else if (uMsg < 0x120) {
    if (uMsg == 0x11f) {
      if ((wParam >> 0x10 == 0xffff) && (lParam == 0)) {
        local_278 = GetMenuItemCount(DAT_00516700);
        while (local_278 != 0) {
          DeleteMenu(DAT_00516700,0,0x400);
          local_278 = local_278 + -1;
        }
      }
      return 0;
    }
    if (uMsg == 0x117) {
      local_210 = (uint)(DAT_00618160 != hwnd);
      if ((DAT_00618158 != 0) && (iVar3 = FUN_004376c0(local_210), iVar3 != 0)) {
        if (local_210 == 1) {
          FUN_00448412(local_20c);
          _sprintf((char *)local_274,s_Target__s_004f6a4c,local_20c);
        }
        else {
          Mem_AllocOrFree_004d9630(local_274,(uint *)s_Target_yourself_004f6a58);
        }
        AppendMenuA(DAT_00516700,0,0x66,(LPCSTR)local_274);
      }
      iVar3 = GetMenuItemCount(DAT_00516700);
      if (0 < iVar3) {
        AppendMenuA(DAT_00516700,0x800,0,(LPCSTR)0x0);
      }
      AppendMenuA(DAT_00516700,0,100,s_Flip_back_to_lifepoints_004f6a68);
      AppendMenuA(DAT_00516700,0,0x65,s_Help____004f6a80);
      return 0;
    }
  }
  else if (uMsg < 0x205) {
    if (uMsg == 0x204) {
      local_1a8.x = lParam & 0xffff;
      local_1a8.y = lParam >> 0x10;
      ClientToScreen(hwnd,&local_1a8);
      SetRect(&local_1a0,local_1a8.x,local_1a8.y,local_1a8.x + 1,local_1a8.y + 1);
      TrackPopupMenu(DAT_00516700,2,local_1a8.x,local_1a8.y,0,hwnd,&local_1a0);
      return 0;
    }
    if (uMsg == 0x201) {
      local_120 = (uint)(hwnd != DAT_00601550);
      if (DAT_00618158 != 0) {
        dwMilliseconds = GetDoubleClickTime();
        Sleep(dwMilliseconds);
        DAT_0066643c = PeekMessageA(&local_13c,hwnd,0x203,0x203,0);
        FUN_00437681(local_120);
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
      LVar4 = FUN_00472b60(hwnd,uMsg,(HWND)wParam,lParam);
      return LVar4;
    }
  }
  else if (uMsg == 0x439) {
    local_c = (HANDLE)GetWindowLongA(hwnd,0);
    local_8 = GetWindowLongA(hwnd,4);
    if ((local_c != (HANDLE)0x0) && (local_8 == 0)) {
      FUN_00471395(local_c);
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



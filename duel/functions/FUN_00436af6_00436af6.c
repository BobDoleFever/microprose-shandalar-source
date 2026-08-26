/*
 * Decompiled function: FUN_00436af6
 * Entry Point: 00436af6
 * Size: 1760 bytes
 */
#include "duel.h"


LRESULT FUN_00436af6(HWND param_1,uint param_2,uint param_3,uint param_4)

{
  LONG LVar1;
  UINT dwMilliseconds;
  HBRUSH hbr;
  int iVar2;
  LRESULT LVar3;
  int local_278;
  char local_274 [100];
  uint local_210;
  undefined1 local_20c [100];
  tagPOINT local_1a8;
  tagRECT local_1a0;
  HDC local_190;
  tagPAINTSTRUCT local_18c;
  tagRECT local_14c;
  tagMSG local_13c;
  uint local_120;
  CHAR local_11c [264];
  ULONG_PTR local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  if (param_2 < 0x10) {
    if (param_2 == 0xf) {
      local_c = GetWindowLongA(param_1,0);
      local_190 = BeginPaint(param_1,&local_18c);
      if (local_190 != (HDC)0x0) {
        FUN_004707a4(local_190);
        GetClientRect(param_1,&local_14c);
        if (local_c == 0) {
          hbr = GetStockObject(4);
          FillRect(local_190,&local_14c,hbr);
        }
        else {
          FUN_004371ec(local_190,&local_14c,param_1 != DAT_00601550);
        }
        EndPaint(param_1,&local_18c);
      }
      return 0;
    }
    if (param_2 == 1) {
      local_c = 0;
      SetWindowLongA(param_1,0,0);
      local_8 = 0;
      SetWindowLongA(param_1,4,0);
      return 0;
    }
    if (param_2 == 2) {
      local_c = GetWindowLongA(param_1,0);
      local_8 = GetWindowLongA(param_1,4);
      if ((local_c != 0) && (local_8 == 0)) {
        FUN_00471395(local_c);
      }
      return 0;
    }
  }
  else if (param_2 < 0x112) {
    if (param_2 == 0x111) {
      param_3 = param_3 & 0xffff;
      if (param_3 == 100) {
        FUN_0043753a(param_1 != DAT_00601550,0);
      }
      else if (param_3 == 0x65) {
        local_14 = 0xbdf;
        FUN_004d9630(local_11c,&DAT_005f76e0);
        FUN_004d9640(local_11c,s__duel_hlp_004f6a40);
        WinHelpA(DAT_00618990,local_11c,1,local_14);
      }
      else if (param_3 == 0x66) {
        local_10 = (uint)(param_1 != DAT_00601550);
        DAT_0066643c = 0;
        FUN_00437681(local_10);
      }
      return 0;
    }
    if (param_2 == 0x20) {
      LVar3 = FUN_00471df6(param_1,0x20,param_3,param_4);
      return LVar3;
    }
  }
  else if (param_2 < 0x120) {
    if (param_2 == 0x11f) {
      if ((param_3 >> 0x10 == 0xffff) && (param_4 == 0)) {
        local_278 = GetMenuItemCount(DAT_00516700);
        while (local_278 != 0) {
          DeleteMenu(DAT_00516700,0,0x400);
          local_278 = local_278 + -1;
        }
      }
      return 0;
    }
    if (param_2 == 0x117) {
      local_210 = (uint)(DAT_00618160 != param_1);
      if ((DAT_00618158 != 0) && (iVar2 = FUN_004376c0(local_210), iVar2 != 0)) {
        if (local_210 == 1) {
          FUN_00448412(local_20c);
          _sprintf(local_274,s_Target__s_004f6a4c,local_20c);
        }
        else {
          FUN_004d9630(local_274,s_Target_yourself_004f6a58);
        }
        AppendMenuA(DAT_00516700,0,0x66,local_274);
      }
      iVar2 = GetMenuItemCount(DAT_00516700);
      if (0 < iVar2) {
        AppendMenuA(DAT_00516700,0x800,0,(LPCSTR)0x0);
      }
      AppendMenuA(DAT_00516700,0,100,s_Flip_back_to_lifepoints_004f6a68);
      AppendMenuA(DAT_00516700,0,0x65,s_Help____004f6a80);
      return 0;
    }
  }
  else if (param_2 < 0x205) {
    if (param_2 == 0x204) {
      local_1a8.x = param_4 & 0xffff;
      local_1a8.y = param_4 >> 0x10;
      ClientToScreen(param_1,&local_1a8);
      SetRect(&local_1a0,local_1a8.x,local_1a8.y,local_1a8.x + 1,local_1a8.y + 1);
      TrackPopupMenu(DAT_00516700,2,local_1a8.x,local_1a8.y,0,param_1,&local_1a0);
      return 0;
    }
    if (param_2 == 0x201) {
      local_120 = (uint)(param_1 != DAT_00601550);
      if (DAT_00618158 != 0) {
        dwMilliseconds = GetDoubleClickTime();
        Sleep(dwMilliseconds);
        DAT_0066643c = PeekMessageA(&local_13c,param_1,0x203,0x203,0);
        FUN_00437681(local_120);
      }
      return 0;
    }
  }
  else if (param_2 < 0x439) {
    if (param_2 == 0x438) {
      LVar1 = GetWindowLongA(param_1,0);
      return LVar1;
    }
    if ((0x30e < param_2) && (param_2 < 0x312)) {
      LVar3 = FUN_00472b60(param_1,param_2,param_3,param_4);
      return LVar3;
    }
  }
  else if (param_2 == 0x439) {
    local_c = GetWindowLongA(param_1,0);
    local_8 = GetWindowLongA(param_1,4);
    if ((local_c != 0) && (local_8 == 0)) {
      FUN_00471395(local_c);
    }
    local_c = param_3;
    local_8 = param_4;
    SetWindowLongA(param_1,0,param_3);
    SetWindowLongA(param_1,4,local_8);
    InvalidateRect(param_1,(RECT *)0x0,0);
    return 0;
  }
  LVar3 = DefWindowProcA(param_1,param_2,param_3,param_4);
  return LVar3;
}



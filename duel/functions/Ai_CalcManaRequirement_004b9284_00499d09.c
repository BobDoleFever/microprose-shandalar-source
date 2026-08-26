/*
 * Decompiled function: Ai_CalcManaRequirement_004b9284
 * Entry Point: 00499d09
 * Size: 3071 bytes
 */
#include "duel.h"


LRESULT Ai_CalcManaRequirement_004b9284(HWND hwnd,uint uMsg,HWND wParam,uint lParam)

{
  LONG LVar1;
  uint uVar2;
  UINT dwMilliseconds;
  HBRUSH hbr;
  int iVar3;
  LRESULT LVar4;
  int local_490;
  uint local_48c [25];
  uint local_428;
  char local_424 [100];
  tagPOINT local_3c0;
  tagRECT local_3b8;
  char local_3a8 [264];
  HDC local_2a0;
  int local_29c;
  tagPAINTSTRUCT local_298;
  int local_258;
  int local_254;
  int local_250;
  int local_24c;
  int local_248;
  int local_244;
  int local_240;
  CHAR local_23c [12];
  tagRECT local_230;
  tagRECT local_220;
  tagMSG local_210;
  uint local_1f4;
  uint local_1f0 [66];
  ULONG_PTR local_e8;
  uint local_e4;
  int local_e0;
  int local_dc;
  uint local_d8 [25];
  uint local_74 [25];
  LONG local_10;
  HWND local_c;
  LONG local_8;
  
  if (uMsg < 0x10) {
    if (uMsg == 0xf) {
      local_8 = GetWindowLongA(hwnd,0);
      local_10 = GetWindowLongA(hwnd,4);
      if (DAT_00618160 == hwnd) {
        local_240 = FUN_0044846f(0);
      }
      else {
        local_240 = FUN_0044846f(1);
      }
      wsprintfA(local_23c,&DAT_005058e4,local_240);
      if (DAT_00618160 == hwnd) {
        local_248 = FUN_004484d5(0);
      }
      else {
        local_248 = FUN_004484d5(1);
      }
      if (local_240 != local_8) {
        InvalidateRect(hwnd,(RECT *)0x0,0);
      }
      if (local_248 != local_10) {
        InvalidateRect(hwnd,(RECT *)0x0,0);
      }
      GetClientRect(hwnd,&local_220);
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00664b70);
      local_2a0 = DAT_0060157c;
      local_254 = SaveDC(DAT_0060157c);
      local_c = (HWND)GetWindowLongA(hwnd,8);
      FUN_004709ae((int)local_2a0,(int)&local_220,local_c);
      if (DAT_005dcaf4 == (HANDLE)0x0) {
        _sprintf(local_3a8,s__s_Poison_pic_005058e8,&DAT_005f7800);
        DAT_005dcaf4 = (HANDLE)Pic_Load_00423833(local_3a8);
      }
      local_258 = (int)(local_220.right + (local_220.right >> 0x1f & 3U)) >> 2;
      local_29c = local_220.bottom / 3;
      local_244 = 0;
      local_250 = 0;
      for (local_24c = 0; local_24c < local_248; local_24c = local_24c + 1) {
        SetRect(&local_230,local_244,local_250,local_244 + local_258,local_250 + local_29c);
        FUN_00470c78(local_2a0,&local_230,DAT_005dcaf4);
        local_244 = local_244 + local_258;
        if (local_220.right < local_244 + local_258) {
          local_244 = 0;
          local_250 = local_250 + local_29c;
        }
      }
      SetMapMode(local_2a0,8);
      SetWindowExtEx(local_2a0,0x7d,100,(LPSIZE)0x0);
      SetViewportExtEx(local_2a0,local_220.right - local_220.left,local_220.bottom - local_220.top,
                       (LPSIZE)0x0);
      SelectObject(local_2a0,DAT_005dcaf0);
      SetBkMode(local_2a0,1);
      SetRect(&local_220,0,0,0x7d,100);
      OffsetRect(&local_220,3,3);
      SetTextColor(local_2a0,DAT_005dcaec);
      DrawTextA(local_2a0,local_23c,-1,&local_220,0x25);
      OffsetRect(&local_220,-3,-3);
      SetTextColor(local_2a0,DAT_005dcae8);
      DrawTextA(local_2a0,local_23c,-1,&local_220,0x25);
      RestoreDC(DAT_0060157c,local_254);
      local_2a0 = BeginPaint(hwnd,&local_298);
      if (local_2a0 != (HDC)0x0) {
        FUN_004707a4(local_2a0);
        GetClientRect(hwnd,&local_220);
        if (DAT_00601580 != 0) {
          hbr = GetStockObject(0);
          FillRect(local_2a0,&local_220,hbr);
          Sleep(200);
        }
        BitBlt(local_2a0,0,0,local_220.right,local_220.bottom,DAT_0060157c,0,0,0xcc0020);
        EndPaint(hwnd,&local_298);
        local_8 = local_240;
        SetWindowLongA(hwnd,0,local_240);
        local_10 = local_248;
        SetWindowLongA(hwnd,4,local_248);
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00664b70);
      return 0;
    }
    if (uMsg == 1) {
      local_8 = 0;
      SetWindowLongA(hwnd,0,0);
      local_10 = 0;
      SetWindowLongA(hwnd,4,0);
      local_c = (HWND)0x0;
      SetWindowLongA(hwnd,8,0);
      return 0;
    }
    if (uMsg == 2) {
      local_c = (HWND)GetWindowLongA(hwnd,8);
      if (local_c != (HANDLE)0x0) {
        FUN_00471395(local_c);
      }
      return 0;
    }
  }
  else if (uMsg < 0x21) {
    if (uMsg == 0x20) {
      LVar4 = UI_WndProc_00471df6(hwnd,0x20,(WPARAM)wParam,lParam);
      return LVar4;
    }
    if (uMsg == 0x14) {
      return 1;
    }
  }
  else if (uMsg < 0x118) {
    if (uMsg == 0x117) {
      local_428 = (uint)(DAT_00618160 != hwnd);
      if ((DAT_00618158 != 0) && (iVar3 = FUN_004376c0(local_428), iVar3 != 0)) {
        if (local_428 == 1) {
          FUN_00448412(local_424);
          _sprintf((char *)local_48c,s_Target__s_005058f8);
        }
        else {
          Mem_AllocOrFree_004d9630(local_48c,(uint *)s_Target_yourself_00505904);
        }
        AppendMenuA(DAT_005dcaf8,0,0x66,(LPCSTR)local_48c);
      }
      iVar3 = GetMenuItemCount(DAT_005dcaf8);
      if (0 < iVar3) {
        AppendMenuA(DAT_005dcaf8,0x800,0,(LPCSTR)0x0);
      }
      AppendMenuA(DAT_005dcaf8,0,100,s_Flip_over_to_face_00505914);
      AppendMenuA(DAT_005dcaf8,0,0x65,s_Help____00505928);
      return 0;
    }
    if (uMsg == 0x111) {
      uVar2 = (uint)wParam & 0xffff;
      if (uVar2 == 100) {
        FUN_0043753a((uint)(DAT_00618160 != hwnd),1);
      }
      else if (uVar2 == 0x65) {
        local_e8 = 0x7e8;
        Mem_AllocOrFree_004d9630(local_1f0,(uint *)&DAT_005f76e0);
        FUN_004d9640(local_1f0,(uint *)s__duel_hlp_005058d8);
        WinHelpA(DAT_00618990,(LPCSTR)local_1f0,1,local_e8);
      }
      else if (uVar2 == 0x66) {
        local_e4 = (uint)(DAT_00618160 != hwnd);
        DAT_0066643c = 0;
        FUN_0049a93a(local_e4);
      }
      return 0;
    }
  }
  else if (uMsg < 0x202) {
    if (uMsg == 0x201) {
      local_1f4 = (uint)(DAT_00618160 != hwnd);
      if (DAT_00618158 != 0) {
        dwMilliseconds = GetDoubleClickTime();
        Sleep(dwMilliseconds);
        DAT_0066643c = PeekMessageA(&local_210,hwnd,0x203,0x203,0);
        FUN_0049a93a(local_1f4);
      }
      return 0;
    }
    if (uMsg == 0x11f) {
      if (((uint)wParam >> 0x10 == 0xffff) && (lParam == 0)) {
        local_490 = GetMenuItemCount(DAT_005dcaf8);
        while (local_490 != 0) {
          DeleteMenu(DAT_005dcaf8,0,0x400);
          local_490 = local_490 + -1;
        }
      }
      return 0;
    }
  }
  else if (uMsg < 0x312) {
    if (0x30e < uMsg) {
      LVar4 = FUN_00472b60(hwnd,uMsg,wParam,lParam);
      return LVar4;
    }
    if (uMsg == 0x204) {
      local_3c0.x = lParam & 0xffff;
      local_3c0.y = lParam >> 0x10;
      ClientToScreen(hwnd,&local_3c0);
      SetRect(&local_3b8,local_3c0.x,local_3c0.y,local_3c0.x + 1,local_3c0.y + 1);
      TrackPopupMenu(DAT_005dcaf8,2,local_3c0.x,local_3c0.y,0,hwnd,&local_3b8);
      return 0;
    }
  }
  else {
    switch(uMsg) {
    case 0x432:
      local_8 = GetWindowLongA(hwnd,0);
      if (DAT_00618160 == hwnd) {
        local_dc = FUN_0044846f(0);
      }
      else {
        local_dc = FUN_0044846f(1);
      }
      local_10 = GetWindowLongA(hwnd,4);
      if (DAT_00618160 == hwnd) {
        local_e0 = FUN_004484d5(0);
      }
      else {
        local_e0 = FUN_004484d5(1);
      }
      if (local_8 != local_dc) {
        InvalidateRect(hwnd,(RECT *)0x0,0);
      }
      if (local_10 != local_e0) {
        InvalidateRect(hwnd,(RECT *)0x0,0);
      }
      return 0;
    case 0x437:
      local_10 = GetWindowLongA(hwnd,4);
      if (DAT_00618160 == hwnd) {
        Mem_AllocOrFree_004d9630(local_74,(uint *)s_Your_005058a0);
      }
      else {
        FUN_00448412((char *)local_74);
      }
      _sprintf((char *)local_d8,s__s_life_points_s_005058c4,local_74,
               s_and_poison_counters_005058a8 + ((local_10 != 0) - 1 & 0x18));
      Mem_AllocOrFree_004d9630((uint *)wParam,local_d8);
      return 1;
    case 0x438:
      LVar1 = GetWindowLongA(hwnd,8);
      return LVar1;
    case 0x439:
      local_c = (HWND)GetWindowLongA(hwnd,8);
      if (local_c != (HGDIOBJ)0x0) {
        DeleteObject(local_c);
      }
      local_c = wParam;
      SetWindowLongA(hwnd,8,(LONG)wParam);
      InvalidateRect(hwnd,(RECT *)0x0,1);
      return 0;
    }
  }
  LVar4 = DefWindowProcA(hwnd,uMsg,(WPARAM)wParam,lParam);
  return LVar4;
}



/*
 * Decompiled function: FUN_0043a55f
 * Entry Point: 0043a55f
 * Size: 2639 bytes
 */
#include "duel.h"


LRESULT FUN_0043a55f(HWND param_1,uint param_2,uint param_3,uint param_4)

{
  LONG LVar1;
  HBRUSH pHVar2;
  UINT dwMilliseconds;
  BOOL BVar3;
  int iVar4;
  WPARAM wParam;
  LRESULT LVar5;
  int local_a68;
  undefined1 local_a60 [2000];
  uint local_290;
  tagMSG local_28c;
  int local_270;
  tagPOINT local_26c;
  tagRECT local_264;
  HDC local_254;
  tagPAINTSTRUCT local_250;
  tagRECT local_210;
  int local_200;
  CHAR local_1fc [264];
  ULONG_PTR local_f4;
  uint local_f0;
  uint local_ec;
  int local_e8;
  uint local_e4;
  uint local_e0;
  WPARAM local_dc;
  char local_d8 [100];
  undefined1 local_74 [100];
  LONG local_10;
  HGDIOBJ local_c;
  HWND local_8;
  
  if (param_2 < 0x10) {
    if (param_2 == 0xf) {
      local_10 = GetWindowLongA(param_1,0);
      local_c = (HGDIOBJ)GetWindowLongA(param_1,8);
      local_200 = FUN_0043b850(param_1 != DAT_00618978);
      if (local_200 != local_10) {
        InvalidateRect(param_1,(RECT *)0x0,0);
      }
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00664b70);
      GetClientRect(param_1,&local_210);
      pHVar2 = GetStockObject(4);
      FillRect(DAT_0060157c,&local_210,pHVar2);
      if (local_200 == -1) {
        if (local_c != (HGDIOBJ)0x0) {
          FUN_004709ae(DAT_0060157c,&local_210,local_c);
        }
      }
      else {
        FUN_0042053a(DAT_0060157c,&local_210,&DAT_00618ac0 + local_200 * 0x98,0,0x11,0);
      }
      local_254 = BeginPaint(param_1,&local_250);
      if (local_254 != (HDC)0x0) {
        FUN_004707a4(local_254);
        if (DAT_00601580 != 0) {
          pHVar2 = GetStockObject(0);
          FillRect(local_254,&local_210,pHVar2);
          Sleep(200);
        }
        BitBlt(local_254,0,0,local_210.right,local_210.bottom,DAT_0060157c,0,0,0xcc0020);
        EndPaint(param_1,&local_250);
        local_10 = local_200;
        SetWindowLongA(param_1,0,local_200);
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00664b70);
      return 0;
    }
    if (param_2 == 1) {
      local_10 = 0xffffffff;
      SetWindowLongA(param_1,0,-1);
      local_8 = (HWND)0x0;
      SetWindowLongA(param_1,4,0);
      local_c = (HGDIOBJ)0x0;
      SetWindowLongA(param_1,8,0);
      return 0;
    }
    if (param_2 == 2) {
      local_c = (HGDIOBJ)GetWindowLongA(param_1,8);
      if (local_c != (HGDIOBJ)0x0) {
        FUN_00471395(local_c);
      }
      return 0;
    }
  }
  else if (param_2 < 0x21) {
    if (param_2 == 0x20) {
      LVar5 = FUN_00471df6(param_1,0x20,param_3,param_4);
      return LVar5;
    }
    if (param_2 == 0x14) {
      return 1;
    }
  }
  else if (param_2 < 0x118) {
    if (param_2 == 0x117) {
      local_290 = (uint)(param_1 != DAT_00618978);
      AppendMenuA(DAT_005168ec,0,100,s_View_the_graveyard_004f7794);
      iVar4 = FUN_00448653(local_a60,local_290);
      if (iVar4 == 0) {
        EnableMenuItem(DAT_005168ec,100,1);
      }
      AppendMenuA(DAT_005168ec,0,0x65,s_View_the_out_of_play_cards_004f77a8);
      iVar4 = FUN_004486f6(local_a60,local_290);
      if (iVar4 == 0) {
        EnableMenuItem(DAT_005168ec,0x65,1);
      }
      AppendMenuA(DAT_005168ec,0,0x66,s_View_both_antes_004f77c4);
      AppendMenuA(DAT_005168ec,0x800,0,(LPCSTR)0x0);
      AppendMenuA(DAT_005168ec,0,0x67,s_Help____004f77d4);
      return 0;
    }
    if (param_2 == 0x111) {
      switch(param_3 & 0xffff) {
      case 100:
        SendMessageA(param_1,0x400,1,1);
        break;
      case 0x65:
        SendMessageA(param_1,0x400,1,0);
        break;
      case 0x66:
        FUN_0043b8a8();
        break;
      case 0x67:
        local_f4 = 0x7e6;
        FUN_004d9630(local_1fc,&DAT_005f76e0);
        FUN_004d9640(local_1fc,s__duel_hlp_004f7788);
        WinHelpA(DAT_00618990,local_1fc,1,local_f4);
      }
      return 0;
    }
  }
  else if (param_2 < 0x202) {
    if (param_2 == 0x201) {
      SendMessageA(param_1,0x400,1,1);
      return 0;
    }
    if (param_2 == 0x11f) {
      if ((param_3 >> 0x10 == 0xffff) && (param_4 == 0)) {
        local_a68 = GetMenuItemCount(DAT_005168ec);
        while (local_a68 != 0) {
          DeleteMenu(DAT_005168ec,0,0x400);
          local_a68 = local_a68 + -1;
        }
      }
      return 0;
    }
  }
  else if (param_2 < 0x312) {
    if (0x30e < param_2) {
      LVar5 = FUN_00472b60(param_1,param_2,param_3,param_4);
      return LVar5;
    }
    if (param_2 == 0x204) {
      local_270 = 1;
      if (DAT_00663e24 == 2) {
        dwMilliseconds = GetDoubleClickTime();
        Sleep(dwMilliseconds);
        BVar3 = PeekMessageA(&local_28c,param_1,0x206,0x206,0);
        if (BVar3 != 0) {
          local_270 = 0;
        }
      }
      if (local_270 != 0) {
        local_26c.x = param_4 & 0xffff;
        local_26c.y = param_4 >> 0x10;
        ClientToScreen(param_1,&local_26c);
        SetRect(&local_264,local_26c.x,local_26c.y,local_26c.x + 1,local_26c.y + 1);
        TrackPopupMenu(DAT_005168ec,2,local_26c.x,local_26c.y,0,param_1,&local_264);
      }
      return 0;
    }
    if (param_2 == 0x206) {
      wParam = FUN_0043b850(param_1 != DAT_00618978);
      if ((wParam != 0xffffffff) && (DAT_00663e24 == 2)) {
        SendMessageA(DAT_006152e0,0x401,wParam,0);
      }
      return 0;
    }
  }
  else {
    switch(param_2) {
    case 0x400:
      local_8 = (HWND)GetWindowLongA(param_1,4);
      local_ec = param_3;
      local_f0 = param_4;
      if (param_3 == 0) {
        if (local_8 != (HWND)0x0) {
          ReleaseCapture();
          FUN_0043b83b(local_8);
          local_8 = (HWND)0x0;
          SetWindowLongA(param_1,4,0);
        }
      }
      else {
        if (local_8 == (HWND)0x0) {
          local_8 = (HWND)FUN_0043b471(param_1,param_4);
        }
        SetWindowLongA(param_1,4,(LONG)local_8);
        if (local_8 != (HWND)0x0) {
          SetCapture(local_8);
        }
      }
      return 0;
    case 0x432:
      local_10 = GetWindowLongA(param_1,0);
      local_e8 = FUN_0043b850(param_1 != DAT_00618978);
      SendMessageA(param_1,0x400,0,0);
      if (local_e8 != local_10) {
        InvalidateRect(param_1,(RECT *)0x0,0);
      }
      return 0;
    case 0x433:
    case 0x434:
      local_e0 = FUN_0043b850(param_1 != DAT_00618978);
      local_e4 = param_3;
      if (param_3 == local_e0) {
        InvalidateRect(param_1,(RECT *)0x0,0);
      }
      return 0;
    case 0x437:
      if (param_1 == DAT_00618978) {
        FUN_004d9630(local_74,s_Your_004f7770);
      }
      else {
        FUN_00448412(local_74);
      }
      _sprintf(local_d8,s__s_graveyard_004f7778,local_74);
      FUN_004d9630(param_3,local_d8);
      local_dc = FUN_0043b850(param_1 != DAT_00618978);
      if ((local_dc != 0xffffffff) &&
         ((DAT_00663e24 != 2 || (BVar3 = IsWindowVisible(DAT_006152e0), BVar3 != 0)))) {
        SendMessageA(DAT_006152e0,0x401,local_dc,0);
      }
      return 1;
    case 0x438:
      LVar1 = GetWindowLongA(param_1,8);
      return LVar1;
    case 0x439:
      local_c = (HGDIOBJ)GetWindowLongA(param_1,8);
      if (local_c != (HGDIOBJ)0x0) {
        DeleteObject(local_c);
      }
      local_c = (HGDIOBJ)param_3;
      SetWindowLongA(param_1,8,param_3);
      InvalidateRect(param_1,(RECT *)0x0,1);
      return 0;
    }
  }
  LVar5 = DefWindowProcA(param_1,param_2,param_3,param_4);
  return LVar5;
}



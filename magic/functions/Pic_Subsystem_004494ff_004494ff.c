/*
 * Decompiled function: Pic_Subsystem_004494ff
 * Entry Point: 004494ff
 * Size: 2624 bytes
 */
#include "magic.h"


LRESULT Pic_Subsystem_004494ff(HWND hwnd,uint uMsg,char *wParam,uint lParam)

{
  LONG LVar1;
  HBRUSH pHVar2;
  UINT dwMilliseconds;
  BOOL BVar3;
  int iVar4;
  WPARAM wParam_00;
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
  char local_1fc [264];
  ULONG_PTR local_f4;
  uint local_f0;
  char *local_ec;
  int local_e8;
  char *local_e4;
  char *local_e0;
  WPARAM local_dc;
  char local_d8 [100];
  char local_74 [100];
  LONG local_10;
  char *local_c;
  HWND local_8;
  
  if (uMsg < 0x10) {
    if (uMsg == 0xf) {
      local_10 = GetWindowLongA(hwnd,0);
      local_c = (char *)GetWindowLongA(hwnd,8);
      local_200 = Pic_Subsystem_0044a7e1((uint)(hwnd != DAT_006b2e10));
      if (local_200 != local_10) {
        InvalidateRect(hwnd,(RECT *)0x0,0);
      }
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_006ff2f0);
      GetClientRect(hwnd,&local_210);
      pHVar2 = GetStockObject(4);
      FillRect(g_HdcBackBuffer,&local_210,pHVar2);
      if (local_200 == -1) {
        if (local_c != (HANDLE)0x0) {
          FUN_004f3b5f((int)g_HdcBackBuffer,(int)&local_210,local_c);
        }
      }
      else {
        Palette_Subsystem_0049c7c7
                  (g_HdcBackBuffer,&local_210.left,(WPARAM *)(&DAT_006b3070 + local_200 * 0x98),0,
                   0x11,0);
      }
      local_254 = BeginPaint(hwnd,&local_250);
      if (local_254 != (HDC)0x0) {
        FUN_004f3955(local_254);
        if (DAT_0068a674 != 0) {
          pHVar2 = GetStockObject(0);
          FillRect(local_254,&local_210,pHVar2);
          Sleep(200);
        }
        BitBlt(local_254,0,0,local_210.right,local_210.bottom,g_HdcBackBuffer,0,0,0xcc0020);
        EndPaint(hwnd,&local_250);
        local_10 = local_200;
        SetWindowLongA(hwnd,0,local_200);
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ff2f0);
      return 0;
    }
    if (uMsg == 1) {
      local_10 = 0xffffffff;
      SetWindowLongA(hwnd,0,-1);
      local_8 = (HWND)0x0;
      SetWindowLongA(hwnd,4,0);
      local_c = (char *)0x0;
      SetWindowLongA(hwnd,8,0);
      return 0;
    }
    if (uMsg == 2) {
      local_c = (char *)GetWindowLongA(hwnd,8);
      if (local_c != (HANDLE)0x0) {
        FUN_004f4548(local_c);
      }
      return 0;
    }
  }
  else if (uMsg < 0x21) {
    if (uMsg == 0x20) {
      LVar5 = UI_WndProc_004f4fb8(hwnd,0x20,(WPARAM)wParam,lParam);
      return LVar5;
    }
    if (uMsg == 0x14) {
      return 1;
    }
  }
  else if (uMsg < 0x118) {
    if (uMsg == 0x117) {
      local_290 = (uint)(hwnd != DAT_006b2e10);
      AppendMenuA(DAT_00538bcc,0,100,s_View_the_graveyard_00522284);
      iVar4 = Ai_Subsystem_004b718a(local_a60,local_290);
      if (iVar4 == 0) {
        EnableMenuItem(DAT_00538bcc,100,1);
      }
      AppendMenuA(DAT_00538bcc,0,0x65,s_View_the_out_of_play_cards_00522298);
      iVar4 = Ai_Subsystem_004b722d(local_a60,local_290);
      if (iVar4 == 0) {
        EnableMenuItem(DAT_00538bcc,0x65,1);
      }
      AppendMenuA(DAT_00538bcc,0,0x66,s_View_both_antes_005222b4);
      AppendMenuA(DAT_00538bcc,0x800,0,(LPCSTR)0x0);
      AppendMenuA(DAT_00538bcc,0,0x67,s_Help____005222c4);
      return 0;
    }
    if (uMsg == 0x111) {
      switch((uint)wParam & 0xffff) {
      case 100:
        SendMessageA(hwnd,0x400,1,1);
        break;
      case 0x65:
        SendMessageA(hwnd,0x400,1,0);
        break;
      case 0x66:
        Pic_Subsystem_0044a839();
        break;
      case 0x67:
        local_f4 = 0x7e6;
        strcpy(local_1fc,&DAT_006807a0);
        strcat(local_1fc,s__duel_hlp_00522278);
        WinHelpA(g_MainAppHwnd,local_1fc,1,local_f4);
      }
      return 0;
    }
  }
  else if (uMsg < 0x202) {
    if (uMsg == 0x201) {
      SendMessageA(hwnd,0x400,1,1);
      return 0;
    }
    if (uMsg == 0x11f) {
      if (((uint)wParam >> 0x10 == 0xffff) && (lParam == 0)) {
        local_a68 = GetMenuItemCount(DAT_00538bcc);
        while (local_a68 != 0) {
          DeleteMenu(DAT_00538bcc,0,0x400);
          local_a68 = local_a68 + -1;
        }
      }
      return 0;
    }
  }
  else if (uMsg < 0x312) {
    if (0x30e < uMsg) {
      LVar5 = FUN_004f5d1a(hwnd,uMsg,(HWND)wParam,lParam);
      return LVar5;
    }
    if (uMsg == 0x204) {
      local_270 = 1;
      if (DAT_006fe444 == 2) {
        dwMilliseconds = GetDoubleClickTime();
        Sleep(dwMilliseconds);
        BVar3 = PeekMessageA(&local_28c,hwnd,0x206,0x206,0);
        if (BVar3 != 0) {
          local_270 = 0;
        }
      }
      if (local_270 != 0) {
        local_26c.x = lParam & 0xffff;
        local_26c.y = lParam >> 0x10;
        ClientToScreen(hwnd,&local_26c);
        SetRect(&local_264,local_26c.x,local_26c.y,local_26c.x + 1,local_26c.y + 1);
        TrackPopupMenu(DAT_00538bcc,2,local_26c.x,local_26c.y,0,hwnd,&local_264);
      }
      return 0;
    }
    if (uMsg == 0x206) {
      wParam_00 = Pic_Subsystem_0044a7e1((uint)(hwnd != DAT_006b2e10));
      if ((wParam_00 != 0xffffffff) && (DAT_006fe444 == 2)) {
        SendMessageA(DAT_0069f744,0x401,wParam_00,0);
      }
      return 0;
    }
  }
  else {
    switch(uMsg) {
    case 0x400:
      local_8 = (HWND)GetWindowLongA(hwnd,4);
      local_ec = wParam;
      local_f0 = lParam;
      if (wParam == (char *)0x0) {
        if (local_8 != (HWND)0x0) {
          ReleaseCapture();
          Pic_Util_0044a7cc(local_8);
          local_8 = (HWND)0x0;
          SetWindowLongA(hwnd,4,0);
        }
      }
      else {
        if (local_8 == (HWND)0x0) {
          local_8 = (HWND)Pic_Subsystem_0044a402(hwnd,lParam);
        }
        SetWindowLongA(hwnd,4,(LONG)local_8);
        if (local_8 != (HWND)0x0) {
          SetCapture(local_8);
        }
      }
      return 0;
    case 0x432:
      local_10 = GetWindowLongA(hwnd,0);
      local_e8 = Pic_Subsystem_0044a7e1((uint)(hwnd != DAT_006b2e10));
      SendMessageA(hwnd,0x400,0,0);
      if (local_e8 != local_10) {
        InvalidateRect(hwnd,(RECT *)0x0,0);
      }
      return 0;
    case 0x433:
    case 0x434:
      local_e0 = (char *)Pic_Subsystem_0044a7e1((uint)(hwnd != DAT_006b2e10));
      local_e4 = wParam;
      if (wParam == local_e0) {
        InvalidateRect(hwnd,(RECT *)0x0,0);
      }
      return 0;
    case 0x437:
      if (hwnd == DAT_006b2e10) {
        strcpy(local_74,s_Your_00522260);
      }
      else {
        Ai_Subsystem_004b6f49(local_74);
      }
      sprintf(local_d8,s__s_graveyard_00522268,local_74);
      strcpy(wParam,local_d8);
      local_dc = Pic_Subsystem_0044a7e1((uint)(hwnd != DAT_006b2e10));
      if ((local_dc != 0xffffffff) &&
         ((DAT_006fe444 != 2 || (BVar3 = IsWindowVisible(DAT_0069f744), BVar3 != 0)))) {
        SendMessageA(DAT_0069f744,0x401,local_dc,0);
      }
      return 1;
    case 0x438:
      LVar1 = GetWindowLongA(hwnd,8);
      return LVar1;
    case 0x439:
      local_c = (char *)GetWindowLongA(hwnd,8);
      if (local_c != (HGDIOBJ)0x0) {
        DeleteObject(local_c);
      }
      local_c = wParam;
      SetWindowLongA(hwnd,8,(LONG)wParam);
      InvalidateRect(hwnd,(RECT *)0x0,1);
      return 0;
    }
  }
  LVar5 = DefWindowProcA(hwnd,uMsg,(WPARAM)wParam,lParam);
  return LVar5;
}



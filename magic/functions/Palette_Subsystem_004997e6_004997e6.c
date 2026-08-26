/*
 * Decompiled function: Palette_Subsystem_004997e6
 * Entry Point: 004997e6
 * Size: 4913 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

LRESULT Palette_Subsystem_004997e6(HWND hwnd,uint uMsg,int *wParam,int *lParam)

{
  POINT Point;
  byte bVar1;
  int *piVar2;
  LONG LVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  HBRUSH pHVar7;
  DWORD DVar8;
  HWND pHVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  LRESULT LVar13;
  tagPOINT local_30c;
  int local_304;
  tagPOINT local_300;
  tagRECT local_2f8;
  int local_2e8;
  int local_2e4;
  uint local_2e0;
  HDC local_2dc;
  tagPAINTSTRUCT local_2d8;
  int local_298;
  tagRECT local_294;
  uint local_284;
  DWORD local_280;
  int local_264;
  int local_260;
  int local_25c;
  int local_258;
  int *local_254;
  char local_250 [264];
  ULONG_PTR local_148;
  char local_144 [264];
  int *local_3c;
  int *local_38;
  int local_34;
  int *local_30;
  int local_2c;
  uint local_28;
  int local_24;
  uint local_20;
  int *local_1c;
  int local_18;
  uint local_14;
  int local_10;
  LONG local_c;
  int *local_8;
  
  if (uMsg < 0x10) {
    if (uMsg == 0xf) {
      local_8 = (int *)GetWindowLongA(hwnd,0);
      local_10 = GetWindowLongA(hwnd,4);
      local_18 = GetWindowLongA(hwnd,8);
      local_14 = GetWindowLongA(hwnd,0xc);
      local_c = GetWindowLongA(hwnd,0x10);
      if ((((local_8 == (int *)0xffffffff) || (DAT_006ff2e8 == local_8)) ||
          (DAT_006a49f4 + -1 < (int)local_8)) && ((DAT_006fe444 == 2 && (hwnd == DAT_0069f744)))) {
        SendMessageA(hwnd,0x113,1,0);
        LVar13 = DefWindowProcA(hwnd,0xf,(WPARAM)wParam,(LPARAM)lParam);
        return LVar13;
      }
      if (DAT_00695e94 == local_8) {
        local_284 = Ai_Subsystem_004b59d9(local_10,local_18);
      }
      else if (DAT_0068a694 == local_8) {
        Ai_Subsystem_004b650c(local_10,local_18,(int *)&local_2e0,&local_2e4);
        local_284 = local_2e4 << 0x10 | local_2e0 & 0xffff;
      }
      else {
        local_284 = 0;
      }
      if ((local_10 == -1) || (local_18 == -1)) {
        local_298 = 0;
      }
      else {
        bVar1 = Ai_Subsystem_004b6356(local_10,local_18);
        local_298 = FUN_00473cc5(bVar1);
      }
      if (local_14 != local_284) {
        InvalidateRect(hwnd,(RECT *)0x0,0);
      }
      if (local_c != local_298) {
        InvalidateRect(hwnd,(RECT *)0x0,0);
      }
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_006ff2f0);
      local_280 = GetTickCount();
      GetClientRect(hwnd,&local_294);
      local_2dc = BeginPaint(hwnd,&local_2d8);
      if (local_2dc != (HDC)0x0) {
        FUN_004f3955(local_2dc);
        if (DAT_0068a674 != 0) {
          pHVar7 = GetStockObject(0);
          FillRect(local_2dc,&local_294,pHVar7);
          Sleep(200);
        }
        if (DAT_006a49f4 + -1 < (int)local_8) {
          pHVar7 = GetStockObject(4);
          FillRect(g_HdcBackBuffer,&local_294,pHVar7);
          Palette_Subsystem_0049c6cb(g_HdcBackBuffer,&local_294);
          BitBlt(local_2dc,0,0,local_294.right,local_294.bottom,g_HdcBackBuffer,0,0,0xcc0020);
        }
        else if (((int)local_8 < 0) || (DAT_006ff2e8 == local_8)) {
          pHVar7 = GetStockObject(4);
          FillRect(g_HdcBackBuffer,&local_294,pHVar7);
          Palette_Subsystem_0049c6cb(g_HdcBackBuffer,&local_294);
          BitBlt(local_2dc,0,0,local_294.right,local_294.bottom,g_HdcBackBuffer,0,0,0xcc0020);
        }
        else if ((((DAT_00695e94 == local_8) || (DAT_0068a70c == local_8)) ||
                 (DAT_0068a694 == local_8)) || (DAT_006a2848 == local_8)) {
          pHVar7 = GetStockObject(4);
          FillRect(g_HdcBackBuffer,&local_294,pHVar7);
          iVar5 = Ai_Subsystem_004b5cbb(local_10,local_18);
          if (iVar5 == -1) {
            Palette_Subsystem_0049c6cb(g_HdcBackBuffer,&local_294);
          }
          else {
            Palette_Subsystem_0049eda9
                      (g_HdcBackBuffer,&local_294.left,(int)local_8,local_10,local_18);
          }
          BitBlt(local_2dc,0,0,local_294.right,local_294.bottom,g_HdcBackBuffer,0,0,0xcc0020);
        }
        else if (DAT_006ff2dc == local_8) {
          pHVar7 = GetStockObject(4);
          FillRect(g_HdcBackBuffer,&local_294,pHVar7);
          iVar5 = Ai_Subsystem_004b5cbb(local_10,local_18);
          if (iVar5 == -1) {
            Palette_Subsystem_0049c6cb(g_HdcBackBuffer,&local_294);
          }
          else {
            Palette_Subsystem_0049ebf6(g_HdcBackBuffer,&local_294,local_10,local_18);
          }
          BitBlt(local_2dc,0,0,local_294.right,local_294.bottom,g_HdcBackBuffer,0,0,0xcc0020);
        }
        else {
          pHVar7 = GetStockObject(4);
          FillRect(g_HdcBackBuffer,&local_294,pHVar7);
          if (((local_10 == -1) || (local_18 == -1)) ||
             (iVar5 = Ai_Subsystem_004b5cbb(local_10,local_18), iVar5 == -1)) {
            if (local_8 == (int *)0xffffffff) {
              Palette_Subsystem_0049c6cb(g_HdcBackBuffer,&local_294);
              local_2e8 = 1;
            }
            else {
              local_2e8 = Palette_Subsystem_0049c7c7
                                    (g_HdcBackBuffer,&local_294.left,
                                     (WPARAM *)(&DAT_006b3070 + (int)local_8 * 0x98),0,0,
                                     DAT_006fe430);
            }
          }
          else {
            local_2e8 = Palette_Subsystem_0049d843
                                  (g_HdcBackBuffer,&local_294.left,
                                   (int)(&DAT_006b3070 + (int)local_8 * 0x98),local_10,local_18,0,
                                   DAT_006fe430);
          }
          BitBlt(local_2dc,0,0,local_294.right,local_294.bottom,g_HdcBackBuffer,0,0,0xcc0020);
          if (local_2e8 == 0) {
            if (((local_10 == -1) || (local_18 == -1)) ||
               (iVar5 = Ai_Subsystem_004b5cbb(local_10,local_18), iVar5 == -1)) {
              if (local_8 != (int *)0xffffffff) {
                Palette_Subsystem_0049c7c7
                          (g_HdcBackBuffer,&local_294.left,
                           (WPARAM *)(&DAT_006b3070 + (int)local_8 * 0x98),0,2,DAT_006fe430);
              }
            }
            else {
              Palette_Subsystem_0049d843
                        (g_HdcBackBuffer,&local_294.left,(int)(&DAT_006b3070 + (int)local_8 * 0x98),
                         local_10,local_18,2,DAT_006fe430);
            }
            BitBlt(local_2dc,0,0,local_294.right,local_294.bottom,g_HdcBackBuffer,0,0,0xcc0020);
          }
        }
        EndPaint(hwnd,&local_2d8);
        local_14 = local_284;
        SetWindowLongA(hwnd,0xc,local_284);
        local_c = local_298;
        SetWindowLongA(hwnd,0x10,local_298);
      }
      DVar8 = GetTickCount();
      _DAT_00696738 = _DAT_00696738 + (DVar8 - local_280);
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ff2f0);
      return 0;
    }
    if (uMsg == 1) {
      local_8 = (int *)0xffffffff;
      SetWindowLongA(hwnd,0,-1);
      local_10 = 0xffffffff;
      local_18 = -1;
      SetWindowLongA(hwnd,4,-1);
      SetWindowLongA(hwnd,8,local_18);
      local_14 = 0;
      SetWindowLongA(hwnd,0xc,0);
      local_c = 0;
      SetWindowLongA(hwnd,0x10,0);
      local_254 = lParam;
      local_25c = lParam[5];
      local_264 = lParam[4];
      local_260 = (local_264 * 200) / 300;
      local_258 = (local_25c * 300) / 200;
      iVar5 = abs(local_258 - local_264);
      iVar6 = abs(local_260 - local_25c);
      if (4 < iVar5 + iVar6) {
        if (local_260 < local_25c) {
          SetWindowPos(hwnd,(HWND)0x0,0,0,local_260,local_264,6);
        }
        else {
          SetWindowPos(hwnd,(HWND)0x0,0,0,local_25c,local_258,6);
        }
      }
      return 0;
    }
  }
  else if (uMsg < 0x21) {
    if (uMsg == 0x20) {
      LVar13 = UI_WndProc_004f4fb8(hwnd,0x20,(WPARAM)wParam,(LPARAM)lParam);
      return LVar13;
    }
    if (uMsg == 0x14) {
      return 1;
    }
  }
  else if (uMsg < 0x112) {
    if (uMsg == 0x111) {
      uVar4 = (uint)wParam & 0xffff;
      if (uVar4 == 1) {
        DAT_006fe430 = (uint)(DAT_006fe430 == 0);
        Rules_ParseFilter_0050065d();
        InvalidateRect(hwnd,(RECT *)0x0,0);
      }
      else if (uVar4 == 100) {
        local_3c = (int *)GetWindowLongA(hwnd,0);
        if (DAT_006ff2e8 == local_3c) {
          local_3c = (int *)0xc1b;
        }
        if (local_3c != (int *)0xffffffff) {
          strcpy(local_144,&DAT_006807a0);
          strcat(local_144,s__duel_hlp_0052bbe4);
          WinHelpA(g_MainAppHwnd,local_144,1,(ULONG_PTR)local_3c);
        }
      }
      else if (uVar4 == 0x65) {
        local_148 = 0x7e7;
        strcpy(local_250,&DAT_006807a0);
        strcat(local_250,s__duel_hlp_0052bbf0);
        WinHelpA(g_MainAppHwnd,local_250,1,local_148);
      }
      return 0;
    }
    if (uMsg == 0x46) {
      DefWindowProcA(hwnd,0x46,(WPARAM)wParam,(LPARAM)lParam);
      iVar5 = lParam[4];
      iVar6 = lParam[5];
      iVar10 = (iVar6 * 200) / 300;
      iVar11 = (iVar5 * 300) / 200;
      iVar12 = abs(iVar10 - iVar5);
      iVar6 = abs(iVar11 - iVar6);
      if (iVar12 + iVar6 < 5) {
        return 0;
      }
      if (iVar10 < iVar5) {
        lParam[4] = iVar10;
      }
      else {
        lParam[5] = iVar11;
      }
      return 0;
    }
  }
  else if (uMsg < 0x118) {
    if (uMsg == 0x117) {
      AppendMenuA(DAT_0054b360,0,1,s_Expand_text_box_0052bbfc);
      if (DAT_006fe430 != 0) {
        CheckMenuItem(DAT_0054b360,1,8);
      }
      AppendMenuA(DAT_0054b360,0,100,s_Help_for_this_card____0052bc0c);
      AppendMenuA(DAT_0054b360,0,0x65,s_Help____0052bc24);
      return 0;
    }
    if (uMsg == 0x113) {
      if ((wParam == (int *)0x1) && (DAT_006fe444 == 2)) {
        GetCursorPos(&local_30c);
        Point.y = local_30c.y;
        Point.x = local_30c.x;
        pHVar9 = WindowFromPoint(Point);
        if (pHVar9 != hwnd) {
          SendMessageA(hwnd,0x201,1,0);
        }
      }
      return 0;
    }
  }
  else if (uMsg < 0x201) {
    if (uMsg == 0x200) {
      pHVar9 = GetParent(hwnd);
      if (pHVar9 != g_MainAppHwnd) {
        return 0;
      }
      return 0;
    }
    if (uMsg == 0x11f) {
      if (((uint)wParam >> 0x10 == 0xffff) && (lParam == (int *)0x0)) {
        local_304 = GetMenuItemCount(DAT_0054b360);
        while (local_304 != 0) {
          local_304 = local_304 + -1;
          DeleteMenu(DAT_0054b360,0,0x400);
        }
      }
      return 0;
    }
  }
  else if (uMsg < 0x205) {
    if (uMsg == 0x204) {
      local_300.x = (uint)lParam & 0xffff;
      local_300.y = (uint)lParam >> 0x10;
      ClientToScreen(hwnd,&local_300);
      SetRect(&local_2f8,local_300.x,local_300.y,local_300.x + 1,local_300.y + 1);
      TrackPopupMenu(DAT_0054b360,2,local_300.x,local_300.y,0,hwnd,&local_2f8);
      return 0;
    }
    if (uMsg == 0x201) {
      if (DAT_006fe444 == 2) {
        ShowWindow(hwnd,0);
        KillTimer(hwnd,1);
      }
      return 0;
    }
  }
  else if (uMsg < 0x402) {
    if (uMsg == 0x401) {
      local_8 = wParam;
      local_30 = lParam;
      if (((((DAT_00695e94 == wParam) || (DAT_0068a70c == wParam)) || (DAT_0068a694 == wParam)) ||
          (DAT_006a2848 == wParam)) &&
         (((lParam == (int *)0x0 || (*lParam == -1)) || (lParam[1] == -1)))) {
        return 0;
      }
      if (((lParam != (int *)0x0) && (*lParam != -1)) && (lParam[1] == -1)) {
        return 0;
      }
      if (lParam == (int *)0x0) {
        local_10 = -1;
        local_18 = -1;
      }
      else {
        local_10 = *lParam;
        local_18 = lParam[1];
      }
      local_34 = 0;
      piVar2 = (int *)GetWindowLongA(hwnd,0);
      if (piVar2 != local_8) {
        local_34 = 1;
      }
      LVar3 = GetWindowLongA(hwnd,4);
      if ((LVar3 != local_10) || (LVar3 = GetWindowLongA(hwnd,8), LVar3 != local_18)) {
        local_34 = 1;
      }
      if (local_34 == 0) {
        SendMessageA(hwnd,0x432,0,0);
      }
      else {
        SetWindowLongA(hwnd,0,(LONG)local_8);
        SetWindowLongA(hwnd,4,local_10);
        SetWindowLongA(hwnd,8,local_18);
        InvalidateRect(hwnd,(RECT *)0x0,0);
      }
      if (DAT_006fe444 == 2) {
        ShowWindow(hwnd,5);
        if (hwnd == DAT_0069f744) {
          SetTimer(hwnd,1,12000,(TIMERPROC)0x0);
        }
        BringWindowToTop(hwnd);
      }
      return 0;
    }
    if ((0x30e < uMsg) && (uMsg < 0x312)) {
      LVar13 = FUN_004f5d1a(hwnd,uMsg,(HWND)wParam,lParam);
      return LVar13;
    }
  }
  else {
    switch(uMsg) {
    case 0x40b:
      local_38 = wParam;
      local_10 = GetWindowLongA(hwnd,4);
      local_18 = GetWindowLongA(hwnd,8);
      if ((*local_38 == local_10) && (local_38[1] == local_18)) {
        SendMessageA(hwnd,0x401,0xffffffff,0);
        return 1;
      }
      return 0;
    case 0x432:
      local_8 = (int *)GetWindowLongA(hwnd,0);
      local_10 = GetWindowLongA(hwnd,4);
      local_18 = GetWindowLongA(hwnd,8);
      local_14 = GetWindowLongA(hwnd,0xc);
      if (DAT_00695e94 == local_8) {
        local_20 = Ai_Subsystem_004b59d9(local_10,local_18);
      }
      else if (DAT_0068a694 == local_8) {
        Ai_Subsystem_004b650c(local_10,local_18,(int *)&local_28,&local_2c);
        local_20 = local_2c << 0x10 | local_28 & 0xffff;
      }
      else {
        local_20 = 0;
      }
      local_c = GetWindowLongA(hwnd,0x10);
      if ((local_10 == -1) || (local_18 == -1)) {
        local_24 = 0;
      }
      else {
        bVar1 = Ai_Subsystem_004b6356(local_10,local_18);
        local_24 = FUN_00473cc5(bVar1);
      }
      if (local_20 != local_14) {
        InvalidateRect(hwnd,(RECT *)0x0,0);
      }
      if (local_c != local_24) {
        InvalidateRect(hwnd,(RECT *)0x0,0);
      }
      if ((local_10 != -1) && (local_18 != -1)) {
        iVar5 = Ai_Subsystem_004b6696(local_10,local_18);
        if (iVar5 != 0) {
          InvalidateRect(hwnd,(RECT *)0x0,0);
        }
        piVar2 = (int *)Ai_Subsystem_004b5cbb(local_10,local_18);
        if (piVar2 != local_8) {
          InvalidateRect(hwnd,(RECT *)0x0,0);
        }
      }
      return 0;
    case 0x433:
    case 0x434:
      local_1c = wParam;
      local_1c = (int *)GetWindowLongA(hwnd,0);
      InvalidateRect(hwnd,(RECT *)0x0,0);
      return 0;
    case 0x437:
      return 0;
    }
  }
  LVar13 = DefWindowProcA(hwnd,uMsg,(WPARAM)wParam,(LPARAM)lParam);
  return LVar13;
}



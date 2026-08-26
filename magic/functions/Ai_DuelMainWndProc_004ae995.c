/*
 * Decompiled function: Ai_DuelMainWndProc
 * Entry Point: 004ae995
 * Size: 2915 bytes
 */
#include "magic.h"


HGDIOBJ Ai_DuelMainWndProc(HWND hwnd,uint uMsg,HDC wParam,HWND lParam)

{
  POINT pt;
  POINT pt_00;
  HGDIOBJ pvVar1;
  HBRUSH hbr;
  int iVar2;
  BOOL BVar3;
  HWND pHVar4;
  HDC hdc;
  int iVar5;
  tagRECT *ptVar6;
  tagPAINTSTRUCT local_1b4;
  int local_174;
  tagRECT local_170;
  int local_160;
  int local_15c;
  WPARAM local_158;
  uint local_154;
  uint local_150;
  tagRECT local_14c;
  tagRECT local_13c;
  WPARAM local_12c;
  tagRECT local_128;
  tagRECT local_118;
  HDC local_108;
  tagRECT local_104;
  COLORREF local_f4;
  HWND local_f0;
  HWND local_ec;
  int local_e8;
  HDC local_e4;
  HWND local_dc;
  HDC local_d8;
  WPARAM local_d4;
  char local_d0 [200];
  HWND local_8;
  
  if (uMsg < 0x15) {
    if (uMsg == 0x14) {
      local_108 = wParam;
      FUN_004f3955(wParam);
      GetClientRect(hwnd,&local_104);
      if (DAT_00556acc == (HANDLE)0x0) {
        hbr = GetStockObject(2);
        FillRect(local_108,&local_104,hbr);
      }
      else {
        FUN_004f3b5f((int)local_108,(int)&local_104,DAT_00556acc);
      }
      return (HGDIOBJ)0x1;
    }
    if (uMsg == 0xf) {
      local_8 = (HWND)GetWindowLongA(hwnd,8);
      pHVar4 = GetDlgItem(hwnd,0x48f);
      UpdateWindow(pHVar4);
      Ai_Subsystem_004b74b1(&local_160,(undefined4 *)0x0);
      if (local_160 == 0) {
        pHVar4 = GetDlgItem(hwnd,0x48d);
        UpdateWindow(pHVar4);
      }
      else {
        pHVar4 = GetDlgItem(hwnd,0x48e);
        UpdateWindow(pHVar4);
      }
      hdc = BeginPaint(hwnd,&local_1b4);
      if (hdc != (HDC)0x0) {
        FUN_004f3955(hdc);
        if (local_160 == 0) {
          local_15c = *(int *)((int)local_8 + 0x130);
          local_174 = 0x491;
        }
        else {
          local_15c = *(int *)((int)local_8 + 0x134);
          local_174 = 0x490;
        }
        if (local_15c != -1) {
          ptVar6 = &local_170;
          pHVar4 = GetDlgItem(hwnd,local_174);
          GetWindowRect(pHVar4,ptVar6);
          MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_170,2);
          Palette_Subsystem_0049c7c7
                    (hdc,&local_170.left,(WPARAM *)(&DAT_006b3070 + local_15c * 0x98),0,0x12,0);
        }
        if (local_160 == 0) {
          local_15c = *(int *)((int)local_8 + 0x134);
          local_174 = 0x490;
        }
        else {
          local_15c = *(int *)((int)local_8 + 0x130);
          local_174 = 0x491;
        }
        if (local_15c != -1) {
          ptVar6 = &local_170;
          pHVar4 = GetDlgItem(hwnd,local_174);
          GetWindowRect(pHVar4,ptVar6);
          MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_170,2);
          Palette_Subsystem_0049c7c7
                    (hdc,&local_170.left,(WPARAM *)(&DAT_006b3070 + local_15c * 0x98),0,0x12,0);
        }
        EndPaint(hwnd,&local_1b4);
      }
      return (HGDIOBJ)0x1;
    }
  }
  else if (uMsg < 0x103) {
    if (uMsg == 0x102) {
      local_8 = (HWND)GetWindowLongA(hwnd,8);
      if ((*(int *)((int)local_8 + 300) == 0) &&
         (((wParam == (HDC)0xd || (wParam == (HDC)0x20)) || (wParam == (HDC)0x1b)))) {
        Ai_Subsystem_004af5e3((int)DAT_00556acc,DAT_005569d4,DAT_00556964,DAT_00556a80);
        EndDialog(hwnd,1);
      }
      return (HGDIOBJ)0x1;
    }
    if (uMsg == 0x2b) {
      local_f0 = lParam;
      pHVar4 = GetFocus();
      if (pHVar4 == (HWND)local_f0[5].unused) {
        local_f4 = DAT_005569ac;
      }
      else {
        local_f4 = DAT_0055693c;
      }
      if (DAT_006808c0 == 0) {
        local_f4 = DAT_0055693c;
      }
      FUN_004f5107((int)local_f0,DAT_005569d4,DAT_00556964,DAT_00556a80,local_f4,0);
      return (HGDIOBJ)0x1;
    }
  }
  else if (uMsg < 0x136) {
    if (uMsg == 0x135) {
LAB_004aecb5:
      local_e4 = wParam;
      FUN_004f3955(wParam);
      local_ec = lParam;
      local_e8 = GetDlgCtrlID(lParam);
      if ((local_e8 != 0x493) && (local_e8 != 0x494)) {
        SetTextColor(local_e4,DAT_005569a8);
        SetBkMode(local_e4,1);
        pvVar1 = GetStockObject(5);
        return pvVar1;
      }
      pHVar4 = GetFocus();
      if (pHVar4 == local_ec) {
        SetTextColor(local_e4,DAT_005569ac);
      }
      else {
        SetTextColor(local_e4,DAT_00556944);
      }
      SetBkMode(local_e4,1);
      pvVar1 = GetStockObject(5);
      return pvVar1;
    }
    if (uMsg == 0x110) {
      local_8 = lParam;
      SetWindowLongA(hwnd,8,(LONG)lParam);
      Ai_LoadEndDuelBackdrop
                (&DAT_00556acc,&DAT_005569a8,&DAT_00556944,(int *)&DAT_005569d4,(int *)&DAT_00556964
                 ,(int *)&DAT_00556a80,&DAT_0055693c,&DAT_005569ac);
      iVar5 = 0;
      pHVar4 = GetDlgItem(hwnd,0x490);
      ShowWindow(pHVar4,iVar5);
      iVar5 = 0;
      pHVar4 = GetDlgItem(hwnd,0x491);
      ShowWindow(pHVar4,iVar5);
      Ai_Subsystem_004b6f49(local_d0);
      strcat(local_d0,s_next_draw__0052d188);
      SetDlgItemTextA(hwnd,0x48e,local_d0);
      strcpy(local_d0,s_Your_next_draw__0052d194);
      SetDlgItemTextA(hwnd,0x48d,local_d0);
      SetDlgItemTextA(hwnd,0x48f,(LPCSTR)local_8);
      if (local_8[0x4b].unused == 0) {
        iVar5 = 0;
        pHVar4 = GetDlgItem(hwnd,0x493);
        ShowWindow(pHVar4,iVar5);
        iVar5 = 0;
        pHVar4 = GetDlgItem(hwnd,0x494);
        ShowWindow(pHVar4,iVar5);
      }
      else {
        if (DAT_006808c0 == 0) {
          iVar5 = 0;
          pHVar4 = GetDlgItem(hwnd,0x493);
          ShowWindow(pHVar4,iVar5);
          SetDlgItemTextA(hwnd,0x494,&DAT_0052d1c0);
          local_d4 = 0x494;
        }
        else {
          local_d4 = 0x493;
          SetDlgItemTextA(hwnd,0x493,s_Next_Round_0052d1a4);
          SetDlgItemTextA(hwnd,0x494,s_Quit_Gauntlet_0052d1b0);
        }
        pHVar4 = GetDlgItem(hwnd,local_d4);
        SetFocus(pHVar4);
        SendMessageA(hwnd,0x401,local_d4,0);
        FUN_004f570c(hwnd);
      }
      return (HGDIOBJ)0x0;
    }
    if (uMsg == 0x111) {
      if (((uint)wParam & 0xffff) == 0x493) {
        Ai_Subsystem_004af5e3((int)DAT_00556acc,DAT_005569d4,DAT_00556964,DAT_00556a80);
        EndDialog(hwnd,4);
      }
      else if ((((uint)wParam & 0xffff) == 0x494) || (((uint)wParam & 0xffff) == 2)) {
        Ai_Subsystem_004af5e3((int)DAT_00556acc,DAT_005569d4,DAT_00556964,DAT_00556a80);
        EndDialog(hwnd,0);
      }
      return (HGDIOBJ)0x1;
    }
  }
  else if (uMsg < 0x201) {
    if (uMsg == 0x200) {
LAB_004aefff:
      local_154 = (uint)lParam & 0xffff;
      local_150 = (uint)lParam >> 0x10;
      local_8 = (HWND)GetWindowLongA(hwnd,8);
      if (((uMsg == 0x200) && (DAT_006fe444 != 2)) || ((uMsg == 0x204 && (DAT_006fe444 == 2)))) {
        local_12c = *(WPARAM *)((int)local_8 + 0x130);
        ptVar6 = &local_14c;
        pHVar4 = GetDlgItem(hwnd,0x491);
        GetWindowRect(pHVar4,ptVar6);
        MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_14c,2);
        local_158 = *(WPARAM *)((int)local_8 + 0x134);
        ptVar6 = &local_13c;
        pHVar4 = GetDlgItem(hwnd,0x490);
        GetWindowRect(pHVar4,ptVar6);
        MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_13c,2);
        if ((local_12c == 0xffffffff) ||
           (pt.y = local_150, pt.x = local_154, BVar3 = PtInRect(&local_14c,pt), BVar3 == 0)) {
          if ((local_158 != 0xffffffff) &&
             (pt_00.y = local_150, pt_00.x = local_154, BVar3 = PtInRect(&local_13c,pt_00),
             BVar3 != 0)) {
            SendMessageA(DAT_0069f744,0x401,local_158,0);
          }
        }
        else {
          SendMessageA(DAT_0069f744,0x401,local_12c,0);
        }
      }
      return (HGDIOBJ)0x0;
    }
    if (uMsg == 0x138) goto LAB_004aecb5;
  }
  else if (uMsg < 0x205) {
    if (uMsg == 0x204) goto LAB_004aefff;
    if (uMsg == 0x201) {
      GetWindowRect(hwnd,&local_118);
      SendMessageA(hwnd,0x112,0xf012,0);
      GetWindowRect(hwnd,&local_128);
      iVar5 = abs(local_128.top - local_118.top);
      iVar2 = abs(local_128.left - local_118.left);
      if ((iVar5 + iVar2 < 6) &&
         (local_8 = (HWND)GetWindowLongA(hwnd,8), *(int *)((int)local_8 + 300) == 0)) {
        Ai_Subsystem_004af5e3((int)DAT_00556acc,DAT_005569d4,DAT_00556964,DAT_00556a80);
        EndDialog(hwnd,1);
      }
      return (HGDIOBJ)0x1;
    }
  }
  else if (0x30e < uMsg) {
    if (uMsg < 0x312) {
      pvVar1 = (HGDIOBJ)FUN_004f5d1a(hwnd,uMsg,(HWND)wParam,lParam);
      return pvVar1;
    }
    if (uMsg == 0x4c8) {
      local_d8 = wParam;
      local_dc = lParam;
      if (wParam != (HDC)0x0) {
        SendMessageA(hwnd,0x401,(WPARAM)wParam,0);
      }
      if (local_d8 != (HDC)0x0) {
        InvalidateRect((HWND)local_d8,(RECT *)0x0,1);
      }
      if (local_dc != (HWND)0x0) {
        InvalidateRect(local_dc,(RECT *)0x0,1);
      }
      return (HGDIOBJ)0x0;
    }
  }
  return (HGDIOBJ)0x0;
}



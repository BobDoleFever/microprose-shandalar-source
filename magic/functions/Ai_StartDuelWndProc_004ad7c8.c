/*
 * Decompiled function: Ai_StartDuelWndProc
 * Entry Point: 004ad7c8
 * Size: 3680 bytes
 */
#include "magic.h"


HGDIOBJ Ai_StartDuelWndProc(HWND hwnd,uint uMsg,HWND wParam,HWND lParam)

{
  POINT pt;
  POINT pt_00;
  size_t sVar1;
  int iVar2;
  int iVar3;
  WPARAM wParam_00;
  HGDIOBJ pvVar4;
  BOOL BVar5;
  HBRUSH hbr;
  HWND pHVar6;
  HDC hdc;
  LONG Y;
  int iVar7;
  tagSIZE *ptVar8;
  LPARAM lParam_00;
  tagRECT *ptVar9;
  tagPAINTSTRUCT local_280;
  tagRECT local_240;
  uint local_230;
  uint local_22c;
  tagRECT local_228;
  tagRECT local_218;
  HWND local_208;
  tagRECT local_204;
  int local_1f4;
  COLORREF local_1f0;
  HWND local_1ec;
  HWND local_1e8;
  int local_1e4;
  HWND local_1e0;
  HWND local_1dc;
  HWND local_1d8;
  char local_1d4 [100];
  uint local_170;
  tagRECT local_16c;
  HDC local_15c;
  int local_158;
  int local_154;
  HGDIOBJ local_150;
  tagRECT local_14c;
  tagSIZE local_13c;
  char local_134 [200];
  char local_6c [100];
  HWND local_8;
  
  if (uMsg < 0x15) {
    if (uMsg == 0x14) {
      local_208 = wParam;
      FUN_004f3955((HDC)wParam);
      GetClientRect(hwnd,&local_204);
      if (DAT_00556a6c == (HANDLE)0x0) {
        hbr = GetStockObject(2);
        FillRect((HDC)local_208,&local_204,hbr);
      }
      else {
        FUN_004f3b5f((int)local_208,(int)&local_204,DAT_00556a6c);
      }
      return (HGDIOBJ)0x1;
    }
    if (uMsg == 0xf) {
      pHVar6 = GetDlgItem(hwnd,0x413);
      UpdateWindow(pHVar6);
      pHVar6 = GetDlgItem(hwnd,0x418);
      UpdateWindow(pHVar6);
      pHVar6 = GetDlgItem(hwnd,0x417);
      UpdateWindow(pHVar6);
      local_8 = (HWND)GetWindowLongA(hwnd,8);
      hdc = BeginPaint(hwnd,&local_280);
      if (hdc != (HDC)0x0) {
        FUN_004f3955(hdc);
        if (*(int *)((int)local_8 + 8) != -1) {
          ptVar9 = &local_240;
          pHVar6 = GetDlgItem(hwnd,0x470);
          GetWindowRect(pHVar6,ptVar9);
          MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_240,2);
          Palette_Subsystem_0049c7c7
                    (hdc,&local_240.left,
                     (WPARAM *)(&DAT_006b3070 + *(int *)((int)local_8 + 8) * 0x98),0,2,0);
        }
        if (*(int *)((int)local_8 + 4) != -1) {
          ptVar9 = &local_240;
          pHVar6 = GetDlgItem(hwnd,0x46f);
          GetWindowRect(pHVar6,ptVar9);
          MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_240,2);
          Palette_Subsystem_0049c7c7
                    (hdc,&local_240.left,
                     (WPARAM *)(&DAT_006b3070 + *(int *)((int)local_8 + 4) * 0x98),0,2,0);
        }
        EndPaint(hwnd,&local_280);
      }
      return (HGDIOBJ)0x1;
    }
  }
  else if (uMsg < 0x111) {
    if (uMsg == 0x110) {
      BringWindowToTop(DAT_0069e720);
      local_8 = lParam;
      SetWindowLongA(hwnd,8,(LONG)lParam);
      iVar7 = 0;
      pHVar6 = GetDlgItem(hwnd,0x46f);
      ShowWindow(pHVar6,iVar7);
      iVar7 = 0;
      pHVar6 = GetDlgItem(hwnd,0x470);
      ShowWindow(pHVar6,iVar7);
      DAT_00556a68 = 0;
      Ai_LoadStartDuelBackdrop
                (&DAT_00556a6c,&DAT_00556ad8,&DAT_00556a94,&DAT_0055694c,&DAT_00556940,&DAT_00556a64
                 ,&DAT_00556a4c);
      Ai_Subsystem_004b6f49(local_6c);
      if (local_8->unused == 1) {
        sprintf(local_134,s__s_will_start_first_0052cf84,local_6c);
        SetDlgItemTextA(hwnd,0x413,local_134);
      }
      else {
        SetDlgItemTextA(hwnd,0x413,s_You_will_take_the_first_turn_0052cf98);
      }
      sprintf(local_134,s__s_ante__0052cfb8,local_6c);
      SetDlgItemTextA(hwnd,0x417,local_134);
      strcpy(local_134,s_Your_ante__0052cfc4);
      SetDlgItemTextA(hwnd,0x418,local_134);
      if (local_8[4].unused == 0) {
        sprintf(local_134,s__s_did_not_take_a_mulligan_0052d04c,local_6c);
        SetDlgItemTextA(hwnd,0x414,local_134);
      }
      else {
        if (local_8[4].unused == 1) {
          sprintf(local_134,s__s_has_no_land_and_chose_to_take_0052cfd0,local_6c);
        }
        else if (local_8[4].unused == 2) {
          sprintf(local_134,s__s_has_all_land_and_will_take_a_m_0052cffc,local_6c);
        }
        else {
          sprintf(local_134,s__s_has_chosen_to_take_a_mulligan_0052d028,local_6c);
        }
        SetDlgItemTextA(hwnd,0x414,local_134);
      }
      if (local_8[4].unused == 0) {
        if (local_8[3].unused == 0) {
          iVar7 = 0;
          pHVar6 = GetDlgItem(hwnd,0x415);
          ShowWindow(pHVar6,iVar7);
          pHVar6 = GetDlgItem(hwnd,1);
          SetFocus(pHVar6);
          SendMessageA(hwnd,0x401,1,0);
        }
        else {
          iVar7 = 5;
          pHVar6 = GetDlgItem(hwnd,0x415);
          ShowWindow(pHVar6,iVar7);
          pHVar6 = GetDlgItem(hwnd,0x415);
          SetFocus(pHVar6);
          SendMessageA(hwnd,0x401,0x415,0);
        }
      }
      else {
        iVar7 = 5;
        pHVar6 = GetDlgItem(hwnd,0x415);
        ShowWindow(pHVar6,iVar7);
        pHVar6 = GetDlgItem(hwnd,0x415);
        SetFocus(pHVar6);
        SendMessageA(hwnd,0x401,0x415,0);
      }
      iVar7 = 0;
      pHVar6 = GetDlgItem(hwnd,0x416);
      ShowWindow(pHVar6,iVar7);
      local_8[6].unused = 0;
      local_15c = GetDC(hwnd);
      FUN_004f3955(local_15c);
      local_150 = (HGDIOBJ)SendDlgItemMessageA(hwnd,0x415,0x31,0,0);
      SelectObject(local_15c,local_150);
      ptVar9 = &local_14c;
      pHVar6 = GetDlgItem(hwnd,0x415);
      GetWindowRect(pHVar6,ptVar9);
      MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_14c,2);
      GetDlgItemTextA(hwnd,0x415,local_134,200);
      ptVar8 = &local_13c;
      sVar1 = strlen(local_134);
      GetTextExtentPoint32A(local_15c,local_134,sVar1,ptVar8);
      iVar2 = local_13c.cy * 2 + local_13c.cx;
      iVar3 = (local_13c.cy * 5) / 2;
      iVar7 = local_14c.left + ((local_14c.right - local_14c.left) / 2 - iVar2 / 2);
      BVar5 = 1;
      Y = local_14c.top;
      local_158 = iVar3;
      local_154 = iVar2;
      local_14c.left = iVar7;
      pHVar6 = GetDlgItem(hwnd,0x415);
      MoveWindow(pHVar6,iVar7,Y,iVar2,iVar3,BVar5);
      ptVar9 = &local_14c;
      pHVar6 = GetDlgItem(hwnd,1);
      GetWindowRect(pHVar6,ptVar9);
      MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_14c,2);
      GetDlgItemTextA(hwnd,1,local_134,200);
      ptVar8 = &local_13c;
      sVar1 = strlen(local_134);
      GetTextExtentPoint32A(local_15c,local_134,sVar1,ptVar8);
      iVar2 = local_13c.cy * 2 + local_13c.cx;
      iVar3 = (local_13c.cy * 5) / 2;
      iVar7 = local_14c.left + ((local_14c.right - local_14c.left) / 2 - iVar2 / 2);
      BVar5 = 1;
      local_158 = iVar3;
      local_154 = iVar2;
      local_14c.left = iVar7;
      pHVar6 = GetDlgItem(hwnd,1);
      MoveWindow(pHVar6,iVar7,local_14c.top,iVar2,iVar3,BVar5);
      if (local_8[1].unused == -1) {
        iVar7 = 0;
        pHVar6 = GetDlgItem(hwnd,0x46f);
        ShowWindow(pHVar6,iVar7);
        iVar7 = 0;
        pHVar6 = GetDlgItem(hwnd,0x417);
        ShowWindow(pHVar6,iVar7);
      }
      if (local_8[2].unused == -1) {
        iVar7 = 0;
        pHVar6 = GetDlgItem(hwnd,0x470);
        ShowWindow(pHVar6,iVar7);
        iVar7 = 0;
        pHVar6 = GetDlgItem(hwnd,0x418);
        ShowWindow(pHVar6,iVar7);
      }
      ReleaseDC(hwnd,local_15c);
      FUN_004f570c(hwnd);
      if ((local_8[4].unused != 0) || (local_8[3].unused != 0)) {
        GetWindowRect(hwnd,&local_16c);
        SetWindowPos(hwnd,(HWND)0x0,5,local_16c.top,0,0,5);
      }
      return (HGDIOBJ)0x0;
    }
    if (uMsg == 0x2b) {
      local_1ec = lParam;
      pHVar6 = GetFocus();
      if (pHVar6 == (HWND)local_1ec[5].unused) {
        local_1f0 = DAT_00556a4c;
      }
      else {
        local_1f0 = DAT_00556a64;
      }
      local_1f4 = 0;
      pHVar6 = GetDlgItem(hwnd,0x415);
      BVar5 = IsWindowVisible(pHVar6);
      if (BVar5 == 0) {
        local_1f0 = DAT_00556a64;
        local_1f4 = 1;
      }
      FUN_004f54d5((int)local_1ec,DAT_00556a94,DAT_0055694c,DAT_00556940,local_1f0,local_1f4);
      return (HGDIOBJ)0x1;
    }
  }
  else if (uMsg < 0x139) {
    if (uMsg == 0x138) {
      local_1e0 = wParam;
      FUN_004f3955((HDC)wParam);
      local_1e8 = lParam;
      local_1e4 = GetDlgCtrlID(lParam);
      SetBkMode((HDC)local_1e0,1);
      SetTextColor((HDC)local_1e0,DAT_00556ad8);
      pvVar4 = GetStockObject(5);
      return pvVar4;
    }
    if (uMsg == 0x111) {
      local_170 = (uint)wParam & 0xffff;
      if (local_170 != 0) {
        if (local_170 < 3) {
          local_8 = (HWND)GetWindowLongA(hwnd,8);
          Ai_Subsystem_004ae716
                    ((int)DAT_00556a6c,(int)DAT_00556a94,(int)DAT_0055694c,(int)DAT_00556940);
          EndDialog(hwnd,*(INT_PTR *)((int)local_8 + 0x18));
        }
        else if (local_170 == 0x415) {
          local_8 = (HWND)GetWindowLongA(hwnd,8);
          *(undefined4 *)((int)local_8 + 0x18) = 1;
          BVar5 = 0;
          pHVar6 = GetDlgItem(hwnd,0x415);
          EnableWindow(pHVar6,BVar5);
          iVar7 = 0;
          pHVar6 = GetDlgItem(hwnd,1);
          ShowWindow(pHVar6,iVar7);
          if (*(int *)((int)local_8 + 0x10) == 0) {
            Sleep(500);
            Ai_Subsystem_004b6f49(local_1d4);
            if (*(int *)((int)local_8 + 0x14) == 0) {
              strcat(local_1d4,s_decided_not_to_take_a_mulligan_0052d084);
            }
            else {
              strcat(local_1d4,s_will_also_take_a_mulligan_0052d068);
            }
            SetDlgItemTextA(hwnd,0x416,local_1d4);
            iVar7 = 5;
            pHVar6 = GetDlgItem(hwnd,0x416);
            ShowWindow(pHVar6,iVar7);
            if (*(int *)((int)local_8 + 0x14) != 0) {
              SendMessageA(DAT_006fe400,0x40c,0,0);
            }
          }
          SetTimer(hwnd,1,2000,(TIMERPROC)0x0);
        }
      }
      return (HGDIOBJ)0x1;
    }
    if (uMsg == 0x113) {
      Ai_Subsystem_004ae716((int)DAT_00556a6c,(int)DAT_00556a94,(int)DAT_0055694c,(int)DAT_00556940)
      ;
      EndDialog(hwnd,1);
      return (HGDIOBJ)0x1;
    }
  }
  else {
    if (uMsg < 0x312) {
      if (0x30e < uMsg) {
        pvVar4 = (HGDIOBJ)FUN_004f5d1a(hwnd,uMsg,wParam,lParam);
        return pvVar4;
      }
      if (uMsg != 0x200) {
        if (uMsg == 0x201) {
          SendMessageA(hwnd,0x112,0xf012,0);
          return (HGDIOBJ)0x1;
        }
        if (uMsg != 0x204) {
          return (HGDIOBJ)0x0;
        }
      }
      local_230 = (uint)lParam & 0xffff;
      local_22c = (uint)lParam >> 0x10;
      local_8 = (HWND)GetWindowLongA(hwnd,8);
      if (((uMsg == 0x200) && (DAT_006fe444 != 2)) || ((uMsg == 0x204 && (DAT_006fe444 == 2)))) {
        ptVar9 = &local_218;
        pHVar6 = GetDlgItem(hwnd,0x46f);
        GetWindowRect(pHVar6,ptVar9);
        MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_218,2);
        ptVar9 = &local_228;
        pHVar6 = GetDlgItem(hwnd,0x470);
        GetWindowRect(pHVar6,ptVar9);
        MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_228,2);
        if ((*(int *)((int)local_8 + 4) == -1) ||
           (pt.y = local_22c, pt.x = local_230, BVar5 = PtInRect(&local_218,pt), BVar5 == 0)) {
          if ((*(int *)((int)local_8 + 8) != -1) &&
             (pt_00.y = local_22c, pt_00.x = local_230, BVar5 = PtInRect(&local_228,pt_00),
             BVar5 != 0)) {
            SendMessageA(DAT_0069f744,0x401,*(WPARAM *)((int)local_8 + 8),0);
          }
        }
        else {
          SendMessageA(DAT_0069f744,0x401,*(WPARAM *)((int)local_8 + 4),0);
        }
      }
      return (HGDIOBJ)0x0;
    }
    if (uMsg == 0x4c8) {
      local_1d8 = wParam;
      local_1dc = lParam;
      if (wParam != (HWND)0x0) {
        lParam_00 = 0;
        wParam_00 = GetDlgCtrlID(wParam);
        SendMessageA(hwnd,0x401,wParam_00,lParam_00);
      }
      if (local_1d8 != (HWND)0x0) {
        InvalidateRect(local_1d8,(RECT *)0x0,1);
      }
      if (local_1dc != (HWND)0x0) {
        InvalidateRect(local_1dc,(RECT *)0x0,1);
      }
      return (HGDIOBJ)0x0;
    }
  }
  return (HGDIOBJ)0x0;
}



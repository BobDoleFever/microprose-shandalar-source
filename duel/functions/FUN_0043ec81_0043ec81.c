/*
 * Decompiled function: FUN_0043ec81
 * Entry Point: 0043ec81
 * Size: 3683 bytes
 */
#include "duel.h"


HGDIOBJ FUN_0043ec81(HWND param_1,uint param_2,HWND param_3,HWND param_4)

{
  POINT pt;
  POINT pt_00;
  size_t sVar1;
  int iVar2;
  int iVar3;
  WPARAM wParam;
  HGDIOBJ pvVar4;
  BOOL BVar5;
  HBRUSH hbr;
  HWND pHVar6;
  HDC pHVar7;
  LONG Y;
  int iVar8;
  tagSIZE *ptVar9;
  LPARAM lParam;
  tagRECT *ptVar10;
  tagPAINTSTRUCT local_280;
  tagRECT local_240;
  uint local_230;
  uint local_22c;
  tagRECT local_228;
  tagRECT local_218;
  HWND local_208;
  tagRECT local_204;
  undefined4 local_1f4;
  undefined4 local_1f0;
  HWND local_1ec;
  HWND local_1e8;
  int local_1e4;
  HWND local_1e0;
  HWND local_1dc;
  HWND local_1d8;
  CHAR local_1d4 [100];
  uint local_170;
  tagRECT local_16c;
  HDC local_15c;
  int local_158;
  int local_154;
  HGDIOBJ local_150;
  tagRECT local_14c;
  tagSIZE local_13c;
  char local_134 [200];
  undefined1 local_6c [100];
  HWND local_8;
  
  if (param_2 < 0x15) {
    if (param_2 == 0x14) {
      local_208 = param_3;
      FUN_004707a4(param_3);
      GetClientRect(param_1,&local_204);
      if (DAT_00516a9c == 0) {
        hbr = GetStockObject(2);
        FillRect((HDC)local_208,&local_204,hbr);
      }
      else {
        FUN_004709ae(local_208,&local_204,DAT_00516a9c);
      }
      return (HGDIOBJ)0x1;
    }
    if (param_2 == 0xf) {
      pHVar6 = GetDlgItem(param_1,0x413);
      UpdateWindow(pHVar6);
      pHVar6 = GetDlgItem(param_1,0x418);
      UpdateWindow(pHVar6);
      pHVar6 = GetDlgItem(param_1,0x417);
      UpdateWindow(pHVar6);
      local_8 = (HWND)GetWindowLongA(param_1,8);
      pHVar7 = BeginPaint(param_1,&local_280);
      if (pHVar7 != (HDC)0x0) {
        FUN_004707a4(pHVar7);
        if (*(int *)((int)local_8 + 8) != -1) {
          ptVar10 = &local_240;
          pHVar6 = GetDlgItem(param_1,0x470);
          GetWindowRect(pHVar6,ptVar10);
          MapWindowPoints((HWND)0x0,param_1,(LPPOINT)&local_240,2);
          FUN_0042053a(pHVar7,&local_240,&DAT_00618ac0 + *(int *)((int)local_8 + 8) * 0x98,0,2,0);
        }
        if (*(int *)((int)local_8 + 4) != -1) {
          ptVar10 = &local_240;
          pHVar6 = GetDlgItem(param_1,0x46f);
          GetWindowRect(pHVar6,ptVar10);
          MapWindowPoints((HWND)0x0,param_1,(LPPOINT)&local_240,2);
          FUN_0042053a(pHVar7,&local_240,&DAT_00618ac0 + *(int *)((int)local_8 + 4) * 0x98,0,2,0);
        }
        EndPaint(param_1,&local_280);
      }
      return (HGDIOBJ)0x1;
    }
  }
  else if (param_2 < 0x111) {
    if (param_2 == 0x110) {
      BringWindowToTop(DAT_006152b0);
      local_8 = param_4;
      SetWindowLongA(param_1,8,(LONG)param_4);
      iVar8 = 0;
      pHVar6 = GetDlgItem(param_1,0x46f);
      ShowWindow(pHVar6,iVar8);
      iVar8 = 0;
      pHVar6 = GetDlgItem(param_1,0x470);
      ShowWindow(pHVar6,iVar8);
      DAT_00516a98 = 0;
      FUN_0043faee(&DAT_00516a9c,&DAT_00516b08,&DAT_00516ac4,&DAT_0051697c,&DAT_00516970,
                   &DAT_00516a94,&DAT_00516a7c);
      FUN_00448412(local_6c);
      if (local_8->unused == 1) {
        _sprintf(local_134,s__s_will_start_first_004f7aa4,local_6c);
        SetDlgItemTextA(param_1,0x413,local_134);
      }
      else {
        SetDlgItemTextA(param_1,0x413,s_You_will_take_the_first_turn_004f7ab8);
      }
      _sprintf(local_134,s__s_ante__004f7ad8,local_6c);
      SetDlgItemTextA(param_1,0x417,local_134);
      FUN_004d9630(local_134,s_Your_ante__004f7ae4);
      SetDlgItemTextA(param_1,0x418,local_134);
      if (local_8[4].unused == 0) {
        _sprintf(local_134,s__s_did_not_take_a_mulligan_004f7b6c,local_6c);
        SetDlgItemTextA(param_1,0x414,local_134);
      }
      else {
        if (local_8[4].unused == 1) {
          _sprintf(local_134,s__s_has_no_land_and_chose_to_take_004f7af0,local_6c);
        }
        else if (local_8[4].unused == 2) {
          _sprintf(local_134,s__s_has_all_land_and_will_take_a_m_004f7b1c,local_6c);
        }
        else {
          _sprintf(local_134,s__s_has_chosen_to_take_a_mulligan_004f7b48,local_6c);
        }
        SetDlgItemTextA(param_1,0x414,local_134);
      }
      if (local_8[4].unused == 0) {
        if (local_8[3].unused == 0) {
          iVar8 = 0;
          pHVar6 = GetDlgItem(param_1,0x415);
          ShowWindow(pHVar6,iVar8);
          pHVar6 = GetDlgItem(param_1,1);
          SetFocus(pHVar6);
          SendMessageA(param_1,0x401,1,0);
        }
        else {
          iVar8 = 5;
          pHVar6 = GetDlgItem(param_1,0x415);
          ShowWindow(pHVar6,iVar8);
          pHVar6 = GetDlgItem(param_1,0x415);
          SetFocus(pHVar6);
          SendMessageA(param_1,0x401,0x415,0);
        }
      }
      else {
        iVar8 = 5;
        pHVar6 = GetDlgItem(param_1,0x415);
        ShowWindow(pHVar6,iVar8);
        pHVar6 = GetDlgItem(param_1,0x415);
        SetFocus(pHVar6);
        SendMessageA(param_1,0x401,0x415,0);
      }
      iVar8 = 0;
      pHVar6 = GetDlgItem(param_1,0x416);
      ShowWindow(pHVar6,iVar8);
      local_8[6].unused = 0;
      local_15c = GetDC(param_1);
      FUN_004707a4(local_15c);
      local_150 = (HGDIOBJ)SendDlgItemMessageA(param_1,0x415,0x31,0,0);
      SelectObject(local_15c,local_150);
      ptVar10 = &local_14c;
      pHVar6 = GetDlgItem(param_1,0x415);
      GetWindowRect(pHVar6,ptVar10);
      MapWindowPoints((HWND)0x0,param_1,(LPPOINT)&local_14c,2);
      GetDlgItemTextA(param_1,0x415,local_134,200);
      ptVar9 = &local_13c;
      sVar1 = _strlen(local_134);
      GetTextExtentPoint32A(local_15c,local_134,sVar1,ptVar9);
      iVar2 = local_13c.cy * 2 + local_13c.cx;
      iVar3 = (local_13c.cy * 5) / 2;
      iVar8 = local_14c.left + ((local_14c.right - local_14c.left) / 2 - iVar2 / 2);
      BVar5 = 1;
      Y = local_14c.top;
      local_158 = iVar3;
      local_154 = iVar2;
      local_14c.left = iVar8;
      pHVar6 = GetDlgItem(param_1,0x415);
      MoveWindow(pHVar6,iVar8,Y,iVar2,iVar3,BVar5);
      ptVar10 = &local_14c;
      pHVar6 = GetDlgItem(param_1,1);
      GetWindowRect(pHVar6,ptVar10);
      MapWindowPoints((HWND)0x0,param_1,(LPPOINT)&local_14c,2);
      GetDlgItemTextA(param_1,1,local_134,200);
      ptVar9 = &local_13c;
      sVar1 = _strlen(local_134);
      GetTextExtentPoint32A(local_15c,local_134,sVar1,ptVar9);
      iVar2 = local_13c.cy * 2 + local_13c.cx;
      iVar3 = (local_13c.cy * 5) / 2;
      iVar8 = local_14c.left + ((local_14c.right - local_14c.left) / 2 - iVar2 / 2);
      BVar5 = 1;
      local_158 = iVar3;
      local_154 = iVar2;
      local_14c.left = iVar8;
      pHVar6 = GetDlgItem(param_1,1);
      MoveWindow(pHVar6,iVar8,local_14c.top,iVar2,iVar3,BVar5);
      if (local_8[1].unused == -1) {
        iVar8 = 0;
        pHVar6 = GetDlgItem(param_1,0x46f);
        ShowWindow(pHVar6,iVar8);
        iVar8 = 0;
        pHVar6 = GetDlgItem(param_1,0x417);
        ShowWindow(pHVar6,iVar8);
      }
      if (local_8[2].unused == -1) {
        iVar8 = 0;
        pHVar6 = GetDlgItem(param_1,0x470);
        ShowWindow(pHVar6,iVar8);
        iVar8 = 0;
        pHVar6 = GetDlgItem(param_1,0x418);
        ShowWindow(pHVar6,iVar8);
      }
      ReleaseDC(param_1,local_15c);
      FUN_00472552(param_1);
      if ((local_8[4].unused != 0) || (local_8[3].unused != 0)) {
        GetWindowRect(param_1,&local_16c);
        SetWindowPos(param_1,(HWND)0x0,5,local_16c.top,0,0,5);
      }
      return (HGDIOBJ)0x0;
    }
    if (param_2 == 0x2b) {
      local_1ec = param_4;
      pHVar6 = GetFocus();
      if (pHVar6 == (HWND)local_1ec[5].unused) {
        local_1f0 = DAT_00516a7c;
      }
      else {
        local_1f0 = DAT_00516a94;
      }
      local_1f4 = 0;
      pHVar6 = GetDlgItem(param_1,0x415);
      BVar5 = IsWindowVisible(pHVar6);
      if (BVar5 == 0) {
        local_1f0 = DAT_00516a94;
        local_1f4 = 1;
      }
      FUN_00472317(local_1ec,DAT_00516ac4,DAT_0051697c,DAT_00516970,local_1f0,local_1f4);
      return (HGDIOBJ)0x1;
    }
  }
  else if (param_2 < 0x139) {
    if (param_2 == 0x138) {
      local_1e0 = param_3;
      FUN_004707a4(param_3);
      local_1e8 = param_4;
      local_1e4 = GetDlgCtrlID(param_4);
      SetBkMode((HDC)local_1e0,1);
      SetTextColor((HDC)local_1e0,DAT_00516b08);
      pvVar4 = GetStockObject(5);
      return pvVar4;
    }
    if (param_2 == 0x111) {
      local_170 = (uint)param_3 & 0xffff;
      if (local_170 != 0) {
        if (local_170 < 3) {
          local_8 = (HWND)GetWindowLongA(param_1,8);
          FUN_0043fbce(DAT_00516a9c,DAT_00516ac4,DAT_0051697c,DAT_00516970);
          EndDialog(param_1,*(INT_PTR *)((int)local_8 + 0x18));
        }
        else if (local_170 == 0x415) {
          local_8 = (HWND)GetWindowLongA(param_1,8);
          *(undefined4 *)((int)local_8 + 0x18) = 1;
          BVar5 = 0;
          pHVar6 = GetDlgItem(param_1,0x415);
          EnableWindow(pHVar6,BVar5);
          iVar8 = 0;
          pHVar6 = GetDlgItem(param_1,1);
          ShowWindow(pHVar6,iVar8);
          if (*(int *)((int)local_8 + 0x10) == 0) {
            Sleep(500);
            FUN_00448412(local_1d4);
            if (*(int *)((int)local_8 + 0x14) == 0) {
              FUN_004d9640(local_1d4,s_decided_not_to_take_a_mulligan_004f7ba4);
            }
            else {
              FUN_004d9640(local_1d4,s_will_also_take_a_mulligan_004f7b88);
            }
            SetDlgItemTextA(param_1,0x416,local_1d4);
            iVar8 = 5;
            pHVar6 = GetDlgItem(param_1,0x416);
            ShowWindow(pHVar6,iVar8);
            if (*(int *)((int)local_8 + 0x14) != 0) {
              SendMessageA(DAT_00663df4,0x40c,0,0);
            }
          }
          SetTimer(param_1,1,2000,(TIMERPROC)0x0);
        }
      }
      return (HGDIOBJ)0x1;
    }
    if (param_2 == 0x113) {
      FUN_0043fbce(DAT_00516a9c,DAT_00516ac4,DAT_0051697c,DAT_00516970);
      EndDialog(param_1,1);
      return (HGDIOBJ)0x1;
    }
  }
  else {
    if (param_2 < 0x312) {
      if (0x30e < param_2) {
        pvVar4 = (HGDIOBJ)FUN_00472b60(param_1,param_2,param_3,param_4);
        return pvVar4;
      }
      if (param_2 != 0x200) {
        if (param_2 == 0x201) {
          SendMessageA(param_1,0x112,0xf012,0);
          return (HGDIOBJ)0x1;
        }
        if (param_2 != 0x204) {
          return (HGDIOBJ)0x0;
        }
      }
      local_230 = (uint)param_4 & 0xffff;
      local_22c = (uint)param_4 >> 0x10;
      local_8 = (HWND)GetWindowLongA(param_1,8);
      if (((param_2 == 0x200) && (DAT_00663e24 != 2)) || ((param_2 == 0x204 && (DAT_00663e24 == 2)))
         ) {
        ptVar10 = &local_218;
        pHVar6 = GetDlgItem(param_1,0x46f);
        GetWindowRect(pHVar6,ptVar10);
        MapWindowPoints((HWND)0x0,param_1,(LPPOINT)&local_218,2);
        ptVar10 = &local_228;
        pHVar6 = GetDlgItem(param_1,0x470);
        GetWindowRect(pHVar6,ptVar10);
        MapWindowPoints((HWND)0x0,param_1,(LPPOINT)&local_228,2);
        if ((*(int *)((int)local_8 + 4) == -1) ||
           (pt.y = local_22c, pt.x = local_230, BVar5 = PtInRect(&local_218,pt), BVar5 == 0)) {
          if ((*(int *)((int)local_8 + 8) != -1) &&
             (pt_00.y = local_22c, pt_00.x = local_230, BVar5 = PtInRect(&local_228,pt_00),
             BVar5 != 0)) {
            SendMessageA(DAT_006152e0,0x401,*(WPARAM *)((int)local_8 + 8),0);
          }
        }
        else {
          SendMessageA(DAT_006152e0,0x401,*(WPARAM *)((int)local_8 + 4),0);
        }
      }
      return (HGDIOBJ)0x0;
    }
    if (param_2 == 0x4c8) {
      local_1d8 = param_3;
      local_1dc = param_4;
      if (param_3 != (HWND)0x0) {
        lParam = 0;
        wParam = GetDlgCtrlID(param_3);
        SendMessageA(param_1,0x401,wParam,lParam);
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



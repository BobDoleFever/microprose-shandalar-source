/*
 * Decompiled function: FUN_0043fe4c
 * Entry Point: 0043fe4c
 * Size: 2918 bytes
 */
#include "duel.h"


HGDIOBJ FUN_0043fe4c(HWND param_1,uint param_2,HDC param_3,HWND param_4)

{
  POINT pt;
  POINT pt_00;
  HGDIOBJ pvVar1;
  HBRUSH hbr;
  int iVar2;
  BOOL BVar3;
  HWND pHVar4;
  HDC pHVar5;
  int iVar6;
  tagRECT *ptVar7;
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
  CHAR local_d0 [200];
  HWND local_8;
  
  if (param_2 < 0x15) {
    if (param_2 == 0x14) {
      local_108 = param_3;
      FUN_004707a4(param_3);
      GetClientRect(param_1,&local_104);
      if (DAT_00516afc == 0) {
        hbr = GetStockObject(2);
        FillRect(local_108,&local_104,hbr);
      }
      else {
        FUN_004709ae(local_108,&local_104,DAT_00516afc);
      }
      return (HGDIOBJ)0x1;
    }
    if (param_2 == 0xf) {
      local_8 = (HWND)GetWindowLongA(param_1,8);
      pHVar4 = GetDlgItem(param_1,0x48f);
      UpdateWindow(pHVar4);
      FUN_0044897a(&local_160,0);
      if (local_160 == 0) {
        pHVar4 = GetDlgItem(param_1,0x48d);
        UpdateWindow(pHVar4);
      }
      else {
        pHVar4 = GetDlgItem(param_1,0x48e);
        UpdateWindow(pHVar4);
      }
      pHVar5 = BeginPaint(param_1,&local_1b4);
      if (pHVar5 != (HDC)0x0) {
        FUN_004707a4(pHVar5);
        if (local_160 == 0) {
          local_15c = *(int *)((int)local_8 + 0x130);
          local_174 = 0x491;
        }
        else {
          local_15c = *(int *)((int)local_8 + 0x134);
          local_174 = 0x490;
        }
        if (local_15c != -1) {
          ptVar7 = &local_170;
          pHVar4 = GetDlgItem(param_1,local_174);
          GetWindowRect(pHVar4,ptVar7);
          MapWindowPoints((HWND)0x0,param_1,(LPPOINT)&local_170,2);
          FUN_0042053a(pHVar5,&local_170,&DAT_00618ac0 + local_15c * 0x98,0,0x12,0);
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
          ptVar7 = &local_170;
          pHVar4 = GetDlgItem(param_1,local_174);
          GetWindowRect(pHVar4,ptVar7);
          MapWindowPoints((HWND)0x0,param_1,(LPPOINT)&local_170,2);
          FUN_0042053a(pHVar5,&local_170,&DAT_00618ac0 + local_15c * 0x98,0,0x12,0);
        }
        EndPaint(param_1,&local_1b4);
      }
      return (HGDIOBJ)0x1;
    }
  }
  else if (param_2 < 0x103) {
    if (param_2 == 0x102) {
      local_8 = (HWND)GetWindowLongA(param_1,8);
      if ((*(int *)((int)local_8 + 300) == 0) &&
         (((param_3 == (HDC)0xd || (param_3 == (HDC)0x20)) || (param_3 == (HDC)0x1b)))) {
        FUN_00440a9c(DAT_00516afc,DAT_00516a04,DAT_00516994,DAT_00516ab0);
        EndDialog(param_1,1);
      }
      return (HGDIOBJ)0x1;
    }
    if (param_2 == 0x2b) {
      local_f0 = param_4;
      pHVar4 = GetFocus();
      if (pHVar4 == (HWND)local_f0[5].unused) {
        local_f4 = DAT_005169dc;
      }
      else {
        local_f4 = DAT_0051696c;
      }
      if (DAT_005f77ec == 0) {
        local_f4 = DAT_0051696c;
      }
      FUN_00471f45(local_f0,DAT_00516a04,DAT_00516994,DAT_00516ab0,local_f4,0);
      return (HGDIOBJ)0x1;
    }
  }
  else if (param_2 < 0x136) {
    if (param_2 == 0x135) {
LAB_0044016c:
      local_e4 = param_3;
      FUN_004707a4(param_3);
      local_ec = param_4;
      local_e8 = GetDlgCtrlID(param_4);
      if ((local_e8 != 0x493) && (local_e8 != 0x494)) {
        SetTextColor(local_e4,DAT_005169d8);
        SetBkMode(local_e4,1);
        pvVar1 = GetStockObject(5);
        return pvVar1;
      }
      pHVar4 = GetFocus();
      if (pHVar4 == local_ec) {
        SetTextColor(local_e4,DAT_005169dc);
      }
      else {
        SetTextColor(local_e4,DAT_00516974);
      }
      SetBkMode(local_e4,1);
      pvVar1 = GetStockObject(5);
      return pvVar1;
    }
    if (param_2 == 0x110) {
      local_8 = param_4;
      SetWindowLongA(param_1,8,(LONG)param_4);
      FUN_004409b7(&DAT_00516afc,&DAT_005169d8,&DAT_00516974,&DAT_00516a04,&DAT_00516994,
                   &DAT_00516ab0,&DAT_0051696c,&DAT_005169dc);
      iVar6 = 0;
      pHVar4 = GetDlgItem(param_1,0x490);
      ShowWindow(pHVar4,iVar6);
      iVar6 = 0;
      pHVar4 = GetDlgItem(param_1,0x491);
      ShowWindow(pHVar4,iVar6);
      FUN_00448412(local_d0);
      FUN_004d9640(local_d0,s_next_draw__004f7ca8);
      SetDlgItemTextA(param_1,0x48e,local_d0);
      FUN_004d9630(local_d0,s_Your_next_draw__004f7cb4);
      SetDlgItemTextA(param_1,0x48d,local_d0);
      SetDlgItemTextA(param_1,0x48f,(LPCSTR)local_8);
      if (local_8[0x4b].unused == 0) {
        iVar6 = 0;
        pHVar4 = GetDlgItem(param_1,0x493);
        ShowWindow(pHVar4,iVar6);
        iVar6 = 0;
        pHVar4 = GetDlgItem(param_1,0x494);
        ShowWindow(pHVar4,iVar6);
      }
      else {
        if (DAT_005f77ec == 0) {
          iVar6 = 0;
          pHVar4 = GetDlgItem(param_1,0x493);
          ShowWindow(pHVar4,iVar6);
          SetDlgItemTextA(param_1,0x494,&DAT_004f7ce0);
          local_d4 = 0x494;
        }
        else {
          local_d4 = 0x493;
          SetDlgItemTextA(param_1,0x493,s_Next_Round_004f7cc4);
          SetDlgItemTextA(param_1,0x494,s_Quit_Gauntlet_004f7cd0);
        }
        pHVar4 = GetDlgItem(param_1,local_d4);
        SetFocus(pHVar4);
        SendMessageA(param_1,0x401,local_d4,0);
        FUN_00472552(param_1);
      }
      return (HGDIOBJ)0x0;
    }
    if (param_2 == 0x111) {
      if (((uint)param_3 & 0xffff) == 0x493) {
        FUN_00440a9c(DAT_00516afc,DAT_00516a04,DAT_00516994,DAT_00516ab0);
        EndDialog(param_1,4);
      }
      else if ((((uint)param_3 & 0xffff) == 0x494) || (((uint)param_3 & 0xffff) == 2)) {
        FUN_00440a9c(DAT_00516afc,DAT_00516a04,DAT_00516994,DAT_00516ab0);
        EndDialog(param_1,0);
      }
      return (HGDIOBJ)0x1;
    }
  }
  else if (param_2 < 0x201) {
    if (param_2 == 0x200) {
LAB_004404b6:
      local_154 = (uint)param_4 & 0xffff;
      local_150 = (uint)param_4 >> 0x10;
      local_8 = (HWND)GetWindowLongA(param_1,8);
      if (((param_2 == 0x200) && (DAT_00663e24 != 2)) || ((param_2 == 0x204 && (DAT_00663e24 == 2)))
         ) {
        local_12c = *(WPARAM *)((int)local_8 + 0x130);
        ptVar7 = &local_14c;
        pHVar4 = GetDlgItem(param_1,0x491);
        GetWindowRect(pHVar4,ptVar7);
        MapWindowPoints((HWND)0x0,param_1,(LPPOINT)&local_14c,2);
        local_158 = *(WPARAM *)((int)local_8 + 0x134);
        ptVar7 = &local_13c;
        pHVar4 = GetDlgItem(param_1,0x490);
        GetWindowRect(pHVar4,ptVar7);
        MapWindowPoints((HWND)0x0,param_1,(LPPOINT)&local_13c,2);
        if ((local_12c == 0xffffffff) ||
           (pt.y = local_150, pt.x = local_154, BVar3 = PtInRect(&local_14c,pt), BVar3 == 0)) {
          if ((local_158 != 0xffffffff) &&
             (pt_00.y = local_150, pt_00.x = local_154, BVar3 = PtInRect(&local_13c,pt_00),
             BVar3 != 0)) {
            SendMessageA(DAT_006152e0,0x401,local_158,0);
          }
        }
        else {
          SendMessageA(DAT_006152e0,0x401,local_12c,0);
        }
      }
      return (HGDIOBJ)0x0;
    }
    if (param_2 == 0x138) goto LAB_0044016c;
  }
  else if (param_2 < 0x205) {
    if (param_2 == 0x204) goto LAB_004404b6;
    if (param_2 == 0x201) {
      GetWindowRect(param_1,&local_118);
      SendMessageA(param_1,0x112,0xf012,0);
      GetWindowRect(param_1,&local_128);
      iVar6 = FUN_004d9810(local_128.top - local_118.top);
      iVar2 = FUN_004d9810(local_128.left - local_118.left);
      if ((iVar6 + iVar2 < 6) &&
         (local_8 = (HWND)GetWindowLongA(param_1,8), *(int *)((int)local_8 + 300) == 0)) {
        FUN_00440a9c(DAT_00516afc,DAT_00516a04,DAT_00516994,DAT_00516ab0);
        EndDialog(param_1,1);
      }
      return (HGDIOBJ)0x1;
    }
  }
  else if (0x30e < param_2) {
    if (param_2 < 0x312) {
      pvVar1 = (HGDIOBJ)FUN_00472b60(param_1,param_2,param_3,param_4);
      return pvVar1;
    }
    if (param_2 == 0x4c8) {
      local_d8 = param_3;
      local_dc = param_4;
      if (param_3 != (HDC)0x0) {
        SendMessageA(param_1,0x401,(WPARAM)param_3,0);
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



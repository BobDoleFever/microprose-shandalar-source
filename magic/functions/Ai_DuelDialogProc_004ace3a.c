/*
 * Decompiled function: Ai_DuelDialogProc
 * Entry Point: 004ace3a
 * Size: 2167 bytes
 */
#include "magic.h"


HGDIOBJ Ai_DuelDialogProc(HWND hwnd,uint uMsg,HWND wParam,HWND lParam)

{
  size_t sVar1;
  WPARAM wParam_00;
  HGDIOBJ pvVar2;
  HBRUSH hbr;
  HWND pHVar3;
  BOOL BVar4;
  HWND pHVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  tagSIZE *ptVar10;
  UINT UVar11;
  LPARAM lParam_00;
  char local_24c [200];
  int local_184;
  HWND local_180;
  tagRECT local_17c;
  COLORREF local_16c;
  HWND local_168;
  HWND local_164;
  int local_160;
  HWND local_15c;
  HWND local_158;
  HWND local_154;
  uint local_150;
  HDC local_14c;
  int local_148;
  int local_144;
  HGDIOBJ local_140;
  tagSIZE local_13c;
  char local_134 [200];
  char local_6c [100];
  HWND local_8;
  
  if (uMsg < 0x11) {
    if (uMsg == 0x10) {
      pHVar3 = GetDlgItem(hwnd,0x486);
      BVar4 = IsWindowVisible(pHVar3);
      if (BVar4 == 0) {
        KillTimer(hwnd,2);
        EndDialog(hwnd,1);
        return (HGDIOBJ)0x1;
      }
      return (HGDIOBJ)0x1;
    }
    if (uMsg == 2) {
      Ai_Subsystem_004ad77b((int)DAT_00556ac8,(int)DAT_005569a4,(int)DAT_00556aac);
      return (HGDIOBJ)0x0;
    }
  }
  else if (uMsg < 0x2c) {
    if (uMsg == 0x2b) {
      local_168 = lParam;
      pHVar3 = GetFocus();
      if (pHVar3 == (HWND)local_168[5].unused) {
        local_16c = DAT_00556998;
      }
      else {
        local_16c = DAT_00556a3c;
      }
      FUN_004f54d5((int)local_168,DAT_005569a4,DAT_00556aac,DAT_005569a4,local_16c,0);
      return (HGDIOBJ)0x1;
    }
    if (uMsg == 0x14) {
      local_180 = wParam;
      FUN_004f3955((HDC)wParam);
      GetClientRect(hwnd,&local_17c);
      if (DAT_00556ac8 == (HANDLE)0x0) {
        hbr = GetStockObject(2);
        FillRect((HDC)local_180,&local_17c,hbr);
      }
      else {
        FUN_004f3b5f((int)local_180,(int)&local_17c,DAT_00556ac8);
      }
      return (HGDIOBJ)0x1;
    }
  }
  else if (uMsg < 0x111) {
    if (uMsg == 0x110) {
      local_8 = lParam;
      SetWindowLongA(hwnd,8,(LONG)lParam);
      Ai_LoadStartDuel2Backdrop
                (&DAT_00556ac8,&DAT_00556abc,&DAT_005569a4,&DAT_00556aac,&DAT_00556a3c,&DAT_00556998
                );
      Ai_Subsystem_004b6f49(local_6c);
      if (local_8->unused == 1) {
        sprintf(local_134,s__s_won_the_toss_0052ceac,local_6c);
        SetDlgItemTextA(hwnd,0x485,local_134);
        iVar9 = 0;
        pHVar3 = GetDlgItem(hwnd,0x488);
        ShowWindow(pHVar3,iVar9);
        iVar9 = 0;
        pHVar3 = GetDlgItem(hwnd,0x486);
        ShowWindow(pHVar3,iVar9);
        iVar9 = 0;
        pHVar3 = GetDlgItem(hwnd,0x487);
        ShowWindow(pHVar3,iVar9);
        SetFocus(hwnd);
        SetTimer(hwnd,1,1000,(TIMERPROC)0x0);
      }
      else {
        sprintf(local_134,s_You_won_the_coin_toss__0052cebc);
        SetDlgItemTextA(hwnd,0x485,local_134);
        sprintf(local_134,s_Would_you_like_to__0052ced4);
        SetDlgItemTextA(hwnd,0x488,local_134);
        pHVar3 = GetDlgItem(hwnd,0x486);
        SetFocus(pHVar3);
        SendMessageA(hwnd,0x401,0x486,0);
      }
      local_14c = GetDC(hwnd);
      FUN_004f3955(local_14c);
      local_140 = (HGDIOBJ)SendDlgItemMessageA(hwnd,0x486,0x31,0,0);
      SelectObject(local_14c,local_140);
      GetDlgItemTextA(hwnd,0x486,local_134,200);
      ptVar10 = &local_13c;
      sVar1 = strlen(local_134);
      GetTextExtentPoint32A(local_14c,local_134,sVar1,ptVar10);
      local_144 = local_13c.cx;
      local_148 = (local_13c.cy * 5) / 2;
      GetDlgItemTextA(hwnd,0x487,local_134,200);
      ptVar10 = &local_13c;
      sVar1 = strlen(local_134);
      GetTextExtentPoint32A(local_14c,local_134,sVar1,ptVar10);
      if (local_13c.cx <= local_144) {
        local_13c.cx = local_144;
      }
      iVar9 = local_13c.cx + local_13c.cy * 2;
      UVar11 = 6;
      iVar7 = 0;
      iVar6 = 0;
      pHVar5 = (HWND)0x0;
      iVar8 = local_148;
      local_144 = iVar9;
      pHVar3 = GetDlgItem(hwnd,0x486);
      SetWindowPos(pHVar3,pHVar5,iVar6,iVar7,iVar9,iVar8,UVar11);
      UVar11 = 6;
      iVar7 = 0;
      iVar6 = 0;
      pHVar5 = (HWND)0x0;
      iVar9 = local_144;
      iVar8 = local_148;
      pHVar3 = GetDlgItem(hwnd,0x487);
      SetWindowPos(pHVar3,pHVar5,iVar6,iVar7,iVar9,iVar8,UVar11);
      ReleaseDC(hwnd,local_14c);
      FUN_004f570c(hwnd);
      return (HGDIOBJ)0x0;
    }
    if (uMsg == 0x102) {
LAB_004ad556:
      pHVar3 = GetDlgItem(hwnd,0x486);
      BVar4 = IsWindowVisible(pHVar3);
      if (BVar4 == 0) {
        KillTimer(hwnd,2);
        EndDialog(hwnd,1);
        return (HGDIOBJ)0x1;
      }
      return (HGDIOBJ)0x0;
    }
  }
  else if (uMsg < 0x139) {
    if (uMsg == 0x138) {
      local_15c = wParam;
      FUN_004f3955((HDC)wParam);
      local_164 = lParam;
      local_160 = GetDlgCtrlID(lParam);
      SetBkMode((HDC)local_15c,1);
      SetTextColor((HDC)local_15c,DAT_00556abc);
      pvVar2 = GetStockObject(5);
      return pvVar2;
    }
    if (uMsg == 0x111) {
      local_150 = (uint)wParam & 0xffff;
      if ((0x485 < local_150) && (local_150 < 0x488)) {
        local_8 = (HWND)GetWindowLongA(hwnd,8);
        if (local_150 == 0x486) {
          *(undefined4 *)((int)local_8 + 4) = 1;
        }
        else {
          *(undefined4 *)((int)local_8 + 4) = 0;
        }
        EndDialog(hwnd,1);
      }
      return (HGDIOBJ)0x1;
    }
    if (uMsg == 0x113) {
      if (wParam == (HWND)0x1) {
        KillTimer(hwnd,1);
        local_184 = FUN_0040a1d2(2);
        local_8 = (HWND)GetWindowLongA(hwnd,8);
        *(int *)((int)local_8 + 4) = local_184;
        if (local_184 == 0) {
          sprintf(local_24c,s_and_has_chosen_to_draw_first__0052cf00);
        }
        else {
          sprintf(local_24c,s_and_will_play_first__0052cee8);
        }
        SetDlgItemTextA(hwnd,0x488,local_24c);
        iVar9 = 5;
        pHVar3 = GetDlgItem(hwnd,0x488);
        ShowWindow(pHVar3,iVar9);
        SetTimer(hwnd,2,3000,(TIMERPROC)0x0);
      }
      else if (wParam == (HWND)0x2) {
        KillTimer(hwnd,2);
        EndDialog(hwnd,1);
      }
      return (HGDIOBJ)0x0;
    }
  }
  else if (uMsg < 0x205) {
    if ((uMsg == 0x204) || (uMsg == 0x201)) goto LAB_004ad556;
  }
  else if (0x30e < uMsg) {
    if (uMsg < 0x312) {
      pvVar2 = (HGDIOBJ)FUN_004f5d1a(hwnd,uMsg,wParam,lParam);
      return pvVar2;
    }
    if (uMsg == 0x4c8) {
      local_154 = wParam;
      local_158 = lParam;
      if (wParam != (HWND)0x0) {
        lParam_00 = 0;
        wParam_00 = GetDlgCtrlID(wParam);
        SendMessageA(hwnd,0x401,wParam_00,lParam_00);
      }
      if (local_154 != (HWND)0x0) {
        InvalidateRect(local_154,(RECT *)0x0,1);
      }
      if (local_158 != (HWND)0x0) {
        InvalidateRect(local_158,(RECT *)0x0,1);
      }
      return (HGDIOBJ)0x0;
    }
  }
  return (HGDIOBJ)0x0;
}



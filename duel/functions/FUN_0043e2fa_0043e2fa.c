/*
 * Decompiled function: FUN_0043e2fa
 * Entry Point: 0043e2fa
 * Size: 2163 bytes
 */
#include "duel.h"


HGDIOBJ FUN_0043e2fa(HWND param_1,uint param_2,HWND param_3,HWND param_4)

{
  size_t sVar1;
  WPARAM wParam;
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
  LPARAM lParam;
  char local_24c [200];
  int local_184;
  HWND local_180;
  tagRECT local_17c;
  undefined4 local_16c;
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
  undefined1 local_6c [100];
  HWND local_8;
  
  if (param_2 < 0x11) {
    if (param_2 == 0x10) {
      pHVar3 = GetDlgItem(param_1,0x486);
      BVar4 = IsWindowVisible(pHVar3);
      if (BVar4 == 0) {
        KillTimer(param_1,2);
        EndDialog(param_1,1);
        return (HGDIOBJ)0x1;
      }
      return (HGDIOBJ)0x1;
    }
    if (param_2 == 2) {
      FUN_0043ec34(DAT_00516af8,DAT_005169d4,DAT_00516adc);
      return (HGDIOBJ)0x0;
    }
  }
  else if (param_2 < 0x2c) {
    if (param_2 == 0x2b) {
      local_168 = param_4;
      pHVar3 = GetFocus();
      if (pHVar3 == (HWND)local_168[5].unused) {
        local_16c = DAT_005169c8;
      }
      else {
        local_16c = DAT_00516a6c;
      }
      FUN_00472317(local_168,DAT_005169d4,DAT_00516adc,DAT_005169d4,local_16c,0);
      return (HGDIOBJ)0x1;
    }
    if (param_2 == 0x14) {
      local_180 = param_3;
      FUN_004707a4(param_3);
      GetClientRect(param_1,&local_17c);
      if (DAT_00516af8 == 0) {
        hbr = GetStockObject(2);
        FillRect((HDC)local_180,&local_17c,hbr);
      }
      else {
        FUN_004709ae(local_180,&local_17c,DAT_00516af8);
      }
      return (HGDIOBJ)0x1;
    }
  }
  else if (param_2 < 0x111) {
    if (param_2 == 0x110) {
      local_8 = param_4;
      SetWindowLongA(param_1,8,(LONG)param_4);
      FUN_0043eb81(&DAT_00516af8,&DAT_00516aec,&DAT_005169d4,&DAT_00516adc,&DAT_00516a6c,
                   &DAT_005169c8);
      FUN_00448412(local_6c);
      if (local_8->unused == 1) {
        _sprintf(local_134,s__s_won_the_toss_004f79cc,local_6c);
        SetDlgItemTextA(param_1,0x485,local_134);
        iVar9 = 0;
        pHVar3 = GetDlgItem(param_1,0x488);
        ShowWindow(pHVar3,iVar9);
        iVar9 = 0;
        pHVar3 = GetDlgItem(param_1,0x486);
        ShowWindow(pHVar3,iVar9);
        iVar9 = 0;
        pHVar3 = GetDlgItem(param_1,0x487);
        ShowWindow(pHVar3,iVar9);
        SetFocus(param_1);
        SetTimer(param_1,1,1000,(TIMERPROC)0x0);
      }
      else {
        _sprintf(local_134,s_You_won_the_coin_toss__004f79dc);
        SetDlgItemTextA(param_1,0x485,local_134);
        _sprintf(local_134,s_Would_you_like_to__004f79f4);
        SetDlgItemTextA(param_1,0x488,local_134);
        pHVar3 = GetDlgItem(param_1,0x486);
        SetFocus(pHVar3);
        SendMessageA(param_1,0x401,0x486,0);
      }
      local_14c = GetDC(param_1);
      FUN_004707a4(local_14c);
      local_140 = (HGDIOBJ)SendDlgItemMessageA(param_1,0x486,0x31,0,0);
      SelectObject(local_14c,local_140);
      GetDlgItemTextA(param_1,0x486,local_134,200);
      ptVar10 = &local_13c;
      sVar1 = _strlen(local_134);
      GetTextExtentPoint32A(local_14c,local_134,sVar1,ptVar10);
      local_144 = local_13c.cx;
      local_148 = (local_13c.cy * 5) / 2;
      GetDlgItemTextA(param_1,0x487,local_134,200);
      ptVar10 = &local_13c;
      sVar1 = _strlen(local_134);
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
      pHVar3 = GetDlgItem(param_1,0x486);
      SetWindowPos(pHVar3,pHVar5,iVar6,iVar7,iVar9,iVar8,UVar11);
      UVar11 = 6;
      iVar7 = 0;
      iVar6 = 0;
      pHVar5 = (HWND)0x0;
      iVar9 = local_144;
      iVar8 = local_148;
      pHVar3 = GetDlgItem(param_1,0x487);
      SetWindowPos(pHVar3,pHVar5,iVar6,iVar7,iVar9,iVar8,UVar11);
      ReleaseDC(param_1,local_14c);
      FUN_00472552(param_1);
      return (HGDIOBJ)0x0;
    }
    if (param_2 == 0x102) {
LAB_0043ea12:
      pHVar3 = GetDlgItem(param_1,0x486);
      BVar4 = IsWindowVisible(pHVar3);
      if (BVar4 == 0) {
        KillTimer(param_1,2);
        EndDialog(param_1,1);
        return (HGDIOBJ)0x1;
      }
      return (HGDIOBJ)0x0;
    }
  }
  else if (param_2 < 0x139) {
    if (param_2 == 0x138) {
      local_15c = param_3;
      FUN_004707a4(param_3);
      local_164 = param_4;
      local_160 = GetDlgCtrlID(param_4);
      SetBkMode((HDC)local_15c,1);
      SetTextColor((HDC)local_15c,DAT_00516aec);
      pvVar2 = GetStockObject(5);
      return pvVar2;
    }
    if (param_2 == 0x111) {
      local_150 = (uint)param_3 & 0xffff;
      if ((0x485 < local_150) && (local_150 < 0x488)) {
        local_8 = (HWND)GetWindowLongA(param_1,8);
        if (local_150 == 0x486) {
          *(undefined4 *)((int)local_8 + 4) = 1;
        }
        else {
          *(undefined4 *)((int)local_8 + 4) = 0;
        }
        EndDialog(param_1,1);
      }
      return (HGDIOBJ)0x1;
    }
    if (param_2 == 0x113) {
      if (param_3 == (HWND)0x1) {
        KillTimer(param_1,1);
        local_184 = FUN_00439892(2);
        local_8 = (HWND)GetWindowLongA(param_1,8);
        *(int *)((int)local_8 + 4) = local_184;
        if (local_184 == 0) {
          _sprintf(local_24c,s_and_has_chosen_to_draw_first__004f7a20);
        }
        else {
          _sprintf(local_24c,s_and_will_play_first__004f7a08);
        }
        SetDlgItemTextA(param_1,0x488,local_24c);
        iVar9 = 5;
        pHVar3 = GetDlgItem(param_1,0x488);
        ShowWindow(pHVar3,iVar9);
        SetTimer(param_1,2,3000,(TIMERPROC)0x0);
      }
      else if (param_3 == (HWND)0x2) {
        KillTimer(param_1,2);
        EndDialog(param_1,1);
      }
      return (HGDIOBJ)0x0;
    }
  }
  else if (param_2 < 0x205) {
    if ((param_2 == 0x204) || (param_2 == 0x201)) goto LAB_0043ea12;
  }
  else if (0x30e < param_2) {
    if (param_2 < 0x312) {
      pvVar2 = (HGDIOBJ)FUN_00472b60(param_1,param_2,param_3,param_4);
      return pvVar2;
    }
    if (param_2 == 0x4c8) {
      local_154 = param_3;
      local_158 = param_4;
      if (param_3 != (HWND)0x0) {
        lParam = 0;
        wParam = GetDlgCtrlID(param_3);
        SendMessageA(param_1,0x401,wParam,lParam);
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



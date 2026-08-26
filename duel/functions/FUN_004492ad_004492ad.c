/*
 * Decompiled function: FUN_004492ad
 * Entry Point: 004492ad
 * Size: 1276 bytes
 */
#include "duel.h"


HBRUSH FUN_004492ad(HWND param_1,uint param_2,HDC param_3,HWND param_4)

{
  size_t c;
  int X;
  HWND hWnd;
  DWORD dwStyle;
  UINT_PTR UVar1;
  HBRUSH pHVar2;
  int Y;
  int nWidth;
  int nHeight;
  tagSIZE *psizl;
  BOOL BVar3;
  tagRECT local_148;
  HWND local_138;
  int local_134;
  HDC local_130;
  char local_12c [264];
  HDC local_24;
  HGDIOBJ local_20;
  tagRECT local_1c;
  tagSIZE local_c;
  
  if (param_2 < 0x11) {
    if (param_2 == 0x10) {
LAB_00449583:
      KillTimer(param_1,2);
      SendMessageA(DAT_004f79b8,0x10,0,0);
      EndDialog(param_1,0);
      return (HBRUSH)0x1;
    }
    if (param_2 == 2) {
      FUN_004497d2(DAT_005169a0);
      return (HBRUSH)0x0;
    }
  }
  else if (param_2 < 0x101) {
    if (param_2 == 0x100) {
      if (param_4 == (HWND)0x20d) {
        KillTimer(param_1,2);
        SendMessageA(DAT_004f79b8,0x10,0,0);
        EndDialog(param_1,0);
      }
      return (HBRUSH)0x1;
    }
    if (param_2 == 0x14) {
      FUN_004707a4(param_3);
      GetClientRect(param_1,&local_148);
      FillRect(param_3,&local_148,DAT_005169a0);
      return (HBRUSH)0x1;
    }
  }
  else if (param_2 < 0x111) {
    if (param_2 == 0x110) {
      DAT_00516ae8 = param_4;
      FUN_004497ae(&DAT_005169a0,&DAT_00516ae4);
      SetDlgItemTextA(param_1,0x48a,(LPCSTR)DAT_00516ae8);
      local_20 = (HGDIOBJ)SendDlgItemMessageA(param_1,0x48a,0x31,0,0);
      local_24 = GetDC(param_1);
      SelectObject(local_24,local_20);
      psizl = &local_c;
      c = _strlen((char *)DAT_00516ae8);
      GetTextExtentPoint32A(local_24,(LPCSTR)DAT_00516ae8,c,psizl);
      ReleaseDC(param_1,local_24);
      GetClientRect(param_1,&local_1c);
      nWidth = local_c.cx + local_c.cy;
      nHeight = local_c.cy + 5;
      BVar3 = 1;
      Y = 0x14;
      X = (local_1c.right - nWidth) / 2;
      local_c.cx = nWidth;
      local_c.cy = nHeight;
      hWnd = GetDlgItem(param_1,0x48a);
      MoveWindow(hWnd,X,Y,nWidth,nHeight,BVar3);
      if (DAT_00516ae8[0x19].unused == 0) {
        _sprintf(local_12c,s__s_COINTOSS_Heads_AVI_004f7f98,&DAT_006189a0);
      }
      else {
        _sprintf(local_12c,s__s_COINTOSS_Tails_AVI_004f7f80,&DAT_006189a0);
      }
      DAT_004f79b8 = (HWND)MCIWndCreateA(param_1,DAT_00664680,0x50000102,local_12c);
      GetWindowRect(DAT_004f79b8,&local_1c);
      BVar3 = 0;
      dwStyle = GetWindowLongA(param_1,-0x10);
      AdjustWindowRect(&local_1c,dwStyle,BVar3);
      MoveWindow(param_1,local_1c.left,local_1c.top,local_1c.right - local_1c.left,
                 local_1c.bottom - local_1c.top,1);
      UVar1 = SetTimer(param_1,1,10,(TIMERPROC)0x0);
      if (UVar1 == 0) {
        PostMessageA(param_1,0x113,1,0);
      }
      SetTimer(param_1,2,15000,(TIMERPROC)0x0);
      SetFocus(param_1);
      return (HBRUSH)0x0;
    }
    if (param_2 == 0x102) goto LAB_00449583;
  }
  else if (param_2 < 0x139) {
    if (param_2 == 0x138) {
      local_130 = param_3;
      FUN_004707a4(param_3);
      local_138 = param_4;
      local_134 = GetDlgCtrlID(param_4);
      SetBkMode(local_130,1);
      SetTextColor(local_130,DAT_00516ae4);
      return DAT_005169a0;
    }
    if (param_2 == 0x113) {
      KillTimer(param_1,(UINT_PTR)param_3);
      if (param_3 == (HDC)0x1) {
        SendMessageA(DAT_004f79b8,0x806,0,0);
        FUN_0048d00c(0x2f);
        SetFocus(param_1);
      }
      else {
        EndDialog(param_1,0);
      }
      return (HBRUSH)0x1;
    }
  }
  else {
    if (param_2 == 0x210) {
      if ((((uint)param_3 & 0xffff) == 0x201) || (((uint)param_3 & 0xffff) == 0x204)) {
        KillTimer(param_1,2);
        SendMessageA(DAT_004f79b8,0x808,0,0);
        SendMessageA(DAT_004f79b8,0x10,0,0);
        EndDialog(param_1,0);
      }
      return (HBRUSH)0x1;
    }
    if ((0x30e < param_2) && (param_2 < 0x312)) {
      pHVar2 = (HBRUSH)FUN_00472b60(param_1,param_2,param_3,param_4);
      return pHVar2;
    }
  }
  return (HBRUSH)0x0;
}



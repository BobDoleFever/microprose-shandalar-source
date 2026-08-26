/*
 * Decompiled function: Ai_Subsystem_004b7de8
 * Entry Point: 004b7de8
 * Size: 1277 bytes
 */
#include "magic.h"


HBRUSH Ai_Subsystem_004b7de8(HWND hwnd,uint uMsg,HDC wParam,HWND lParam)

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
  
  if (uMsg < 0x11) {
    if (uMsg == 0x10) {
LAB_004b80bf:
      KillTimer(hwnd,2);
      SendMessageA(DAT_0052ce98,0x10,0,0);
      EndDialog(hwnd,0);
      return (HBRUSH)0x1;
    }
    if (uMsg == 2) {
      Ai_Util_004b830e(DAT_00556970);
      return (HBRUSH)0x0;
    }
  }
  else if (uMsg < 0x101) {
    if (uMsg == 0x100) {
      if (lParam == (HWND)0x20d) {
        KillTimer(hwnd,2);
        SendMessageA(DAT_0052ce98,0x10,0,0);
        EndDialog(hwnd,0);
      }
      return (HBRUSH)0x1;
    }
    if (uMsg == 0x14) {
      FUN_004f3955(wParam);
      GetClientRect(hwnd,&local_148);
      FillRect(wParam,&local_148,DAT_00556970);
      return (HBRUSH)0x1;
    }
  }
  else if (uMsg < 0x111) {
    if (uMsg == 0x110) {
      DAT_00556ab8 = lParam;
      Ai_Util_004b82ea(&DAT_00556970,&DAT_00556ab4);
      SetDlgItemTextA(hwnd,0x48a,(LPCSTR)DAT_00556ab8);
      local_20 = (HGDIOBJ)SendDlgItemMessageA(hwnd,0x48a,0x31,0,0);
      local_24 = GetDC(hwnd);
      SelectObject(local_24,local_20);
      psizl = &local_c;
      c = strlen((char *)DAT_00556ab8);
      GetTextExtentPoint32A(local_24,(LPCSTR)DAT_00556ab8,c,psizl);
      ReleaseDC(hwnd,local_24);
      GetClientRect(hwnd,&local_1c);
      nWidth = local_c.cx + local_c.cy;
      nHeight = local_c.cy + 5;
      BVar3 = 1;
      Y = 0x14;
      X = (local_1c.right - nWidth) / 2;
      local_c.cx = nWidth;
      local_c.cy = nHeight;
      hWnd = GetDlgItem(hwnd,0x48a);
      MoveWindow(hWnd,X,Y,nWidth,nHeight,BVar3);
      if (DAT_00556ab8[0x19].unused == 0) {
        sprintf(local_12c,s__s_COINTOSS_Heads_AVI_0052d478,&DAT_006b2e90);
      }
      else {
        sprintf(local_12c,s__s_COINTOSS_Tails_AVI_0052d460,&DAT_006b2e90);
      }
      DAT_0052ce98 = (HWND)MCIWndCreateA(hwnd,g_AppHInstance,0x50000102,local_12c);
      GetWindowRect(DAT_0052ce98,&local_1c);
      BVar3 = 0;
      dwStyle = GetWindowLongA(hwnd,-0x10);
      AdjustWindowRect(&local_1c,dwStyle,BVar3);
      MoveWindow(hwnd,local_1c.left,local_1c.top,local_1c.right - local_1c.left,
                 local_1c.bottom - local_1c.top,1);
      UVar1 = SetTimer(hwnd,1,10,(TIMERPROC)0x0);
      if (UVar1 == 0) {
        PostMessageA(hwnd,0x113,1,0);
      }
      SetTimer(hwnd,2,15000,(TIMERPROC)0x0);
      SetFocus(hwnd);
      return (HBRUSH)0x0;
    }
    if (uMsg == 0x102) goto LAB_004b80bf;
  }
  else if (uMsg < 0x139) {
    if (uMsg == 0x138) {
      local_130 = wParam;
      FUN_004f3955(wParam);
      local_138 = lParam;
      local_134 = GetDlgCtrlID(lParam);
      SetBkMode(local_130,1);
      SetTextColor(local_130,DAT_00556ab4);
      return DAT_00556970;
    }
    if (uMsg == 0x113) {
      KillTimer(hwnd,(UINT_PTR)wParam);
      if (wParam == (HDC)0x1) {
        SendMessageA(DAT_0052ce98,0x806,0,0);
        Magic_UpkeepPhase(0x2f);
        SetFocus(hwnd);
      }
      else {
        EndDialog(hwnd,0);
      }
      return (HBRUSH)0x1;
    }
  }
  else {
    if (uMsg == 0x210) {
      if ((((uint)wParam & 0xffff) == 0x201) || (((uint)wParam & 0xffff) == 0x204)) {
        KillTimer(hwnd,2);
        SendMessageA(DAT_0052ce98,0x808,0,0);
        SendMessageA(DAT_0052ce98,0x10,0,0);
        EndDialog(hwnd,0);
      }
      return (HBRUSH)0x1;
    }
    if ((0x30e < uMsg) && (uMsg < 0x312)) {
      pHVar2 = (HBRUSH)FUN_004f5d1a(hwnd,uMsg,(HWND)wParam,lParam);
      return pHVar2;
    }
  }
  return (HBRUSH)0x0;
}



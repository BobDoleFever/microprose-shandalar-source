/*
 * Decompiled function: UI_DialogProc_004ff5c6
 * Entry Point: 004ff5c6
 * Size: 2001 bytes
 */
#include "magic.h"


HBRUSH UI_DialogProc_004ff5c6(HWND hwnd,uint uMsg,HDC wParam,HWND lParam)

{
  UINT UVar1;
  HWND pHVar2;
  HBRUSH pHVar3;
  BOOL bEnable;
  tagRECT local_38;
  COLORREF local_28;
  HWND local_24;
  HWND local_20;
  int local_1c;
  HDC local_18;
  HWND local_10;
  HWND local_c;
  int local_8;
  
  if (uMsg < 0x2c) {
    if (uMsg == 0x2b) {
      local_24 = lParam;
      pHVar2 = GetFocus();
      if (pHVar2 == (HWND)local_24[5].unused) {
        local_28 = DAT_0061d85c;
      }
      else {
        local_28 = DAT_0061d86c;
      }
      FUN_004f5107((int)local_24,DAT_0061d864,DAT_0061d850,DAT_0061d860,local_28,0);
      return (HBRUSH)0x1;
    }
    if (uMsg == 0x14) {
      FUN_004f3955(wParam);
      GetClientRect(hwnd,&local_38);
      if (DAT_0061d858 == (HANDLE)0x0) {
        pHVar3 = GetStockObject(2);
        FillRect(wParam,&local_38,pHVar3);
      }
      else {
        FUN_004f3b5f((int)wParam,(int)&local_38,DAT_0061d858);
      }
      return (HBRUSH)0x1;
    }
  }
  else if (uMsg < 0x136) {
    if (uMsg == 0x135) {
LAB_004ffaf5:
      local_18 = wParam;
      FUN_004f3955(wParam);
      local_20 = lParam;
      local_1c = GetDlgCtrlID(lParam);
      if ((local_1c != 0x3ff) && (local_1c != 0x40d)) {
        if (local_1c == 0x48b) {
          SetTextColor(local_18,DAT_0061d854);
          SetBkMode(local_18,1);
          pHVar3 = GetStockObject(5);
          return pHVar3;
        }
        pHVar2 = GetFocus();
        if (pHVar2 == local_20) {
          SetTextColor(local_18,DAT_0061d85c);
        }
        else {
          SetTextColor(local_18,DAT_0061d868);
        }
        SetBkMode(local_18,1);
        pHVar3 = GetStockObject(5);
        return pHVar3;
      }
      SetTextColor(local_18,DAT_0061d868);
      SetBkMode(local_18,1);
      return DAT_0061d864;
    }
    if (uMsg == 0x110) {
      Pic_Load_s_WINBK_Options_004ffd9c
                (&DAT_0061d858,&DAT_0061d854,&DAT_0061d868,(int *)&DAT_0061d864,(int *)&DAT_0061d850
                 ,(int *)&DAT_0061d860,&DAT_0061d86c,&DAT_0061d85c);
      if (DAT_006fe444 == 1) {
        local_8 = 0x400;
      }
      else {
        local_8 = 0x401;
      }
      CheckDlgButton(hwnd,local_8,1);
      CheckRadioButton(hwnd,0x400,0x401,local_8);
      if (DAT_006fe420 != 0) {
        CheckDlgButton(hwnd,0x403,1);
      }
      if (DAT_006fe428 != 0) {
        CheckDlgButton(hwnd,0x404,1);
      }
      if (DAT_006fe42c != 0) {
        CheckDlgButton(hwnd,0x405,1);
      }
      if (DAT_006fe434 != 0) {
        CheckDlgButton(hwnd,0x495,1);
      }
      if (((byte)DAT_006fe410 & 1) == 0) {
        bEnable = 0;
        pHVar2 = GetDlgItem(hwnd,0x495);
        EnableWindow(pHVar2,bEnable);
        CheckDlgButton(hwnd,0x495,1);
      }
      if (DAT_006fe448 == 1) {
        local_8 = 0x409;
      }
      else if (DAT_006fe448 == 2) {
        local_8 = 0x408;
      }
      else if (DAT_006fe448 == 3) {
        local_8 = 0x40b;
      }
      else if (DAT_006fe448 == 5) {
        local_8 = 0x407;
      }
      else if (DAT_006fe448 == 4) {
        local_8 = 0x40a;
      }
      else {
        local_8 = 0x40c;
      }
      CheckDlgButton(hwnd,local_8,1);
      CheckRadioButton(hwnd,0x407,0x40c,local_8);
      if (DAT_006fe44c == 0) {
        local_8 = 0x40e;
      }
      else if (DAT_006fe44c == 1) {
        local_8 = 0x40f;
      }
      else {
        local_8 = 0x410;
      }
      CheckDlgButton(hwnd,local_8,1);
      CheckRadioButton(hwnd,0x40e,0x410,local_8);
      pHVar2 = GetDlgItem(hwnd,1);
      SetFocus(pHVar2);
      SendMessageA(hwnd,0x401,1,0);
      FUN_004f570c(hwnd);
      return (HBRUSH)0x0;
    }
    if (uMsg == 0x111) {
      if (((uint)wParam & 0xffff) == 2) {
        FUN_004ffe82(DAT_0061d858,DAT_0061d864,DAT_0061d850,DAT_0061d860);
        EndDialog(hwnd,0);
      }
      else if (((uint)wParam & 0xffff) == 1) {
        UVar1 = IsDlgButtonChecked(hwnd,0x400);
        if (UVar1 == 0) {
          DAT_006fe444 = 2;
        }
        else {
          DAT_006fe444 = 1;
        }
        DAT_006fe420 = IsDlgButtonChecked(hwnd,0x403);
        DAT_006fe428 = IsDlgButtonChecked(hwnd,0x404);
        DAT_006fe42c = IsDlgButtonChecked(hwnd,0x405);
        DAT_006fe434 = IsDlgButtonChecked(hwnd,0x495);
        UVar1 = IsDlgButtonChecked(hwnd,0x409);
        if (UVar1 == 0) {
          UVar1 = IsDlgButtonChecked(hwnd,0x408);
          if (UVar1 == 0) {
            UVar1 = IsDlgButtonChecked(hwnd,0x407);
            if (UVar1 == 0) {
              UVar1 = IsDlgButtonChecked(hwnd,0x40b);
              if (UVar1 == 0) {
                UVar1 = IsDlgButtonChecked(hwnd,0x40a);
                if (UVar1 == 0) {
                  DAT_006fe448 = -1;
                }
                else {
                  DAT_006fe448 = 4;
                }
              }
              else {
                DAT_006fe448 = 3;
              }
            }
            else {
              DAT_006fe448 = 5;
            }
          }
          else {
            DAT_006fe448 = 2;
          }
        }
        else {
          DAT_006fe448 = 1;
        }
        UVar1 = IsDlgButtonChecked(hwnd,0x40e);
        if (UVar1 == 0) {
          UVar1 = IsDlgButtonChecked(hwnd,0x40f);
          if (UVar1 == 0) {
            DAT_006fe44c = 2;
          }
          else {
            DAT_006fe44c = 1;
          }
        }
        else {
          DAT_006fe44c = 0;
        }
        Rules_ParseFilter_0050065d();
        FUN_004ffe82(DAT_0061d858,DAT_0061d864,DAT_0061d850,DAT_0061d860);
        EndDialog(hwnd,1);
      }
      return (HBRUSH)0x1;
    }
  }
  else if (uMsg < 0x202) {
    if (uMsg == 0x201) {
      SendMessageA(hwnd,0x112,0xf012,0);
      return (HBRUSH)0x0;
    }
    if (uMsg == 0x138) goto LAB_004ffaf5;
  }
  else if (0x30e < uMsg) {
    if (uMsg < 0x312) {
      pHVar3 = (HBRUSH)FUN_004f5d1a(hwnd,uMsg,(HWND)wParam,lParam);
      return pHVar3;
    }
    if (uMsg == 0x4c8) {
      local_c = (HWND)wParam;
      local_10 = lParam;
      pHVar2 = GetDlgItem(hwnd,2);
      if (pHVar2 == local_c) {
        SendMessageA(hwnd,0x401,2,0);
      }
      else {
        SendMessageA(hwnd,0x401,1,0);
      }
      if (local_c != (HWND)0x0) {
        InvalidateRect(local_c,(RECT *)0x0,1);
      }
      if (local_10 != (HWND)0x0) {
        InvalidateRect(local_10,(RECT *)0x0,1);
      }
      return (HBRUSH)0x0;
    }
  }
  return (HBRUSH)0x0;
}



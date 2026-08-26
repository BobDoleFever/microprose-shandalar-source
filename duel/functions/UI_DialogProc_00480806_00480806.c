/*
 * Decompiled function: UI_DialogProc_00480806
 * Entry Point: 00480806
 * Size: 2001 bytes
 */
#include "duel.h"


HBRUSH UI_DialogProc_00480806(HWND hwnd,uint uMsg,HDC wParam,HWND lParam)

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
        local_28 = DAT_005dad94;
      }
      else {
        local_28 = DAT_005dada4;
      }
      FUN_00471f45((int)local_24,DAT_005dad9c,DAT_005dad88,DAT_005dad98,local_28,0);
      return (HBRUSH)0x1;
    }
    if (uMsg == 0x14) {
      FUN_004707a4(wParam);
      GetClientRect(hwnd,&local_38);
      if (DAT_005dad90 == (HANDLE)0x0) {
        pHVar3 = GetStockObject(2);
        FillRect(wParam,&local_38,pHVar3);
      }
      else {
        FUN_004709ae((int)wParam,(int)&local_38,DAT_005dad90);
      }
      return (HBRUSH)0x1;
    }
  }
  else if (uMsg < 0x136) {
    if (uMsg == 0x135) {
LAB_00480d35:
      local_18 = wParam;
      FUN_004707a4(wParam);
      local_20 = lParam;
      local_1c = GetDlgCtrlID(lParam);
      if ((local_1c != 0x3ff) && (local_1c != 0x40d)) {
        if (local_1c == 0x48b) {
          SetTextColor(local_18,DAT_005dad8c);
          SetBkMode(local_18,1);
          pHVar3 = GetStockObject(5);
          return pHVar3;
        }
        pHVar2 = GetFocus();
        if (pHVar2 == local_20) {
          SetTextColor(local_18,DAT_005dad94);
        }
        else {
          SetTextColor(local_18,DAT_005dada0);
        }
        SetBkMode(local_18,1);
        pHVar3 = GetStockObject(5);
        return pHVar3;
      }
      SetTextColor(local_18,DAT_005dada0);
      SetBkMode(local_18,1);
      return DAT_005dad9c;
    }
    if (uMsg == 0x110) {
      Pic_Load_s_WINBK_Options_00480fdc
                (&DAT_005dad90,&DAT_005dad8c,&DAT_005dada0,(int *)&DAT_005dad9c,(int *)&DAT_005dad88
                 ,(int *)&DAT_005dad98,&DAT_005dada4,&DAT_005dad94);
      if (DAT_00663e24 == 1) {
        local_8 = 0x400;
      }
      else {
        local_8 = 0x401;
      }
      CheckDlgButton(hwnd,local_8,1);
      CheckRadioButton(hwnd,0x400,0x401,local_8);
      if (DAT_00663e00 != 0) {
        CheckDlgButton(hwnd,0x403,1);
      }
      if (DAT_00663e08 != 0) {
        CheckDlgButton(hwnd,0x404,1);
      }
      if (DAT_00663e0c != 0) {
        CheckDlgButton(hwnd,0x405,1);
      }
      if (DAT_00663e14 != 0) {
        CheckDlgButton(hwnd,0x495,1);
      }
      if (((byte)DAT_00663dfc & 1) == 0) {
        bEnable = 0;
        pHVar2 = GetDlgItem(hwnd,0x495);
        EnableWindow(pHVar2,bEnable);
        CheckDlgButton(hwnd,0x495,1);
      }
      if (DAT_00663e28 == 1) {
        local_8 = 0x409;
      }
      else if (DAT_00663e28 == 2) {
        local_8 = 0x408;
      }
      else if (DAT_00663e28 == 3) {
        local_8 = 0x40b;
      }
      else if (DAT_00663e28 == 5) {
        local_8 = 0x407;
      }
      else if (DAT_00663e28 == 4) {
        local_8 = 0x40a;
      }
      else {
        local_8 = 0x40c;
      }
      CheckDlgButton(hwnd,local_8,1);
      CheckRadioButton(hwnd,0x407,0x40c,local_8);
      if (DAT_00663e2c == 0) {
        local_8 = 0x40e;
      }
      else if (DAT_00663e2c == 1) {
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
      FUN_00472552(hwnd);
      return (HBRUSH)0x0;
    }
    if (uMsg == 0x111) {
      if (((uint)wParam & 0xffff) == 2) {
        FUN_004810c1(DAT_005dad90,DAT_005dad9c,DAT_005dad88,DAT_005dad98);
        EndDialog(hwnd,0);
      }
      else if (((uint)wParam & 0xffff) == 1) {
        UVar1 = IsDlgButtonChecked(hwnd,0x400);
        if (UVar1 == 0) {
          DAT_00663e24 = 2;
        }
        else {
          DAT_00663e24 = 1;
        }
        DAT_00663e00 = IsDlgButtonChecked(hwnd,0x403);
        DAT_00663e08 = IsDlgButtonChecked(hwnd,0x404);
        DAT_00663e0c = IsDlgButtonChecked(hwnd,0x405);
        DAT_00663e14 = IsDlgButtonChecked(hwnd,0x495);
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
                  DAT_00663e28 = -1;
                }
                else {
                  DAT_00663e28 = 4;
                }
              }
              else {
                DAT_00663e28 = 3;
              }
            }
            else {
              DAT_00663e28 = 5;
            }
          }
          else {
            DAT_00663e28 = 2;
          }
        }
        else {
          DAT_00663e28 = 1;
        }
        UVar1 = IsDlgButtonChecked(hwnd,0x40e);
        if (UVar1 == 0) {
          UVar1 = IsDlgButtonChecked(hwnd,0x40f);
          if (UVar1 == 0) {
            DAT_00663e2c = 2;
          }
          else {
            DAT_00663e2c = 1;
          }
        }
        else {
          DAT_00663e2c = 0;
        }
        Rules_ParseFilter_00481890();
        FUN_004810c1(DAT_005dad90,DAT_005dad9c,DAT_005dad88,DAT_005dad98);
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
    if (uMsg == 0x138) goto LAB_00480d35;
  }
  else if (0x30e < uMsg) {
    if (uMsg < 0x312) {
      pHVar3 = (HBRUSH)FUN_00472b60(hwnd,uMsg,(HWND)wParam,lParam);
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



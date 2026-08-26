/*
 * Decompiled function: FUN_00480806
 * Entry Point: 00480806
 * Size: 2001 bytes
 */
#include "duel.h"


HGDIOBJ FUN_00480806(HWND param_1,uint param_2,HDC param_3,HWND param_4)

{
  UINT UVar1;
  HGDIOBJ pvVar2;
  HWND pHVar3;
  HBRUSH hbr;
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
  
  if (param_2 < 0x2c) {
    if (param_2 == 0x2b) {
      local_24 = param_4;
      pHVar3 = GetFocus();
      if (pHVar3 == (HWND)local_24[5].unused) {
        local_28 = DAT_005dad94;
      }
      else {
        local_28 = DAT_005dada4;
      }
      FUN_00471f45(local_24,DAT_005dad9c,DAT_005dad88,DAT_005dad98,local_28,0);
      return (HGDIOBJ)0x1;
    }
    if (param_2 == 0x14) {
      FUN_004707a4(param_3);
      GetClientRect(param_1,&local_38);
      if (DAT_005dad90 == 0) {
        hbr = GetStockObject(2);
        FillRect(param_3,&local_38,hbr);
      }
      else {
        FUN_004709ae(param_3,&local_38,DAT_005dad90);
      }
      return (HGDIOBJ)0x1;
    }
  }
  else if (param_2 < 0x136) {
    if (param_2 == 0x135) {
LAB_00480d35:
      local_18 = param_3;
      FUN_004707a4(param_3);
      local_20 = param_4;
      local_1c = GetDlgCtrlID(param_4);
      if ((local_1c != 0x3ff) && (local_1c != 0x40d)) {
        if (local_1c == 0x48b) {
          SetTextColor(local_18,DAT_005dad8c);
          SetBkMode(local_18,1);
          pvVar2 = GetStockObject(5);
          return pvVar2;
        }
        pHVar3 = GetFocus();
        if (pHVar3 == local_20) {
          SetTextColor(local_18,DAT_005dad94);
        }
        else {
          SetTextColor(local_18,DAT_005dada0);
        }
        SetBkMode(local_18,1);
        pvVar2 = GetStockObject(5);
        return pvVar2;
      }
      SetTextColor(local_18,DAT_005dada0);
      SetBkMode(local_18,1);
      return DAT_005dad9c;
    }
    if (param_2 == 0x110) {
      FUN_00480fdc(&DAT_005dad90,&DAT_005dad8c,&DAT_005dada0,&DAT_005dad9c,&DAT_005dad88,
                   &DAT_005dad98,&DAT_005dada4,&DAT_005dad94);
      if (DAT_00663e24 == 1) {
        local_8 = 0x400;
      }
      else {
        local_8 = 0x401;
      }
      CheckDlgButton(param_1,local_8,1);
      CheckRadioButton(param_1,0x400,0x401,local_8);
      if (DAT_00663e00 != 0) {
        CheckDlgButton(param_1,0x403,1);
      }
      if (DAT_00663e08 != 0) {
        CheckDlgButton(param_1,0x404,1);
      }
      if (DAT_00663e0c != 0) {
        CheckDlgButton(param_1,0x405,1);
      }
      if (DAT_00663e14 != 0) {
        CheckDlgButton(param_1,0x495,1);
      }
      if (((byte)DAT_00663dfc & 1) == 0) {
        bEnable = 0;
        pHVar3 = GetDlgItem(param_1,0x495);
        EnableWindow(pHVar3,bEnable);
        CheckDlgButton(param_1,0x495,1);
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
      CheckDlgButton(param_1,local_8,1);
      CheckRadioButton(param_1,0x407,0x40c,local_8);
      if (DAT_00663e2c == 0) {
        local_8 = 0x40e;
      }
      else if (DAT_00663e2c == 1) {
        local_8 = 0x40f;
      }
      else {
        local_8 = 0x410;
      }
      CheckDlgButton(param_1,local_8,1);
      CheckRadioButton(param_1,0x40e,0x410,local_8);
      pHVar3 = GetDlgItem(param_1,1);
      SetFocus(pHVar3);
      SendMessageA(param_1,0x401,1,0);
      FUN_00472552(param_1);
      return (HGDIOBJ)0x0;
    }
    if (param_2 == 0x111) {
      if (((uint)param_3 & 0xffff) == 2) {
        FUN_004810c1(DAT_005dad90,DAT_005dad9c,DAT_005dad88,DAT_005dad98);
        EndDialog(param_1,0);
      }
      else if (((uint)param_3 & 0xffff) == 1) {
        UVar1 = IsDlgButtonChecked(param_1,0x400);
        if (UVar1 == 0) {
          DAT_00663e24 = 2;
        }
        else {
          DAT_00663e24 = 1;
        }
        DAT_00663e00 = IsDlgButtonChecked(param_1,0x403);
        DAT_00663e08 = IsDlgButtonChecked(param_1,0x404);
        DAT_00663e0c = IsDlgButtonChecked(param_1,0x405);
        DAT_00663e14 = IsDlgButtonChecked(param_1,0x495);
        UVar1 = IsDlgButtonChecked(param_1,0x409);
        if (UVar1 == 0) {
          UVar1 = IsDlgButtonChecked(param_1,0x408);
          if (UVar1 == 0) {
            UVar1 = IsDlgButtonChecked(param_1,0x407);
            if (UVar1 == 0) {
              UVar1 = IsDlgButtonChecked(param_1,0x40b);
              if (UVar1 == 0) {
                UVar1 = IsDlgButtonChecked(param_1,0x40a);
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
        UVar1 = IsDlgButtonChecked(param_1,0x40e);
        if (UVar1 == 0) {
          UVar1 = IsDlgButtonChecked(param_1,0x40f);
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
        FUN_00481890();
        FUN_004810c1(DAT_005dad90,DAT_005dad9c,DAT_005dad88,DAT_005dad98);
        EndDialog(param_1,1);
      }
      return (HGDIOBJ)0x1;
    }
  }
  else if (param_2 < 0x202) {
    if (param_2 == 0x201) {
      SendMessageA(param_1,0x112,0xf012,0);
      return (HGDIOBJ)0x0;
    }
    if (param_2 == 0x138) goto LAB_00480d35;
  }
  else if (0x30e < param_2) {
    if (param_2 < 0x312) {
      pvVar2 = (HGDIOBJ)FUN_00472b60(param_1,param_2,param_3,param_4);
      return pvVar2;
    }
    if (param_2 == 0x4c8) {
      local_c = (HWND)param_3;
      local_10 = param_4;
      pHVar3 = GetDlgItem(param_1,2);
      if (pHVar3 == local_c) {
        SendMessageA(param_1,0x401,2,0);
      }
      else {
        SendMessageA(param_1,0x401,1,0);
      }
      if (local_c != (HWND)0x0) {
        InvalidateRect(local_c,(RECT *)0x0,1);
      }
      if (local_10 != (HWND)0x0) {
        InvalidateRect(local_10,(RECT *)0x0,1);
      }
      return (HGDIOBJ)0x0;
    }
  }
  return (HGDIOBJ)0x0;
}



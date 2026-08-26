/*
 * Decompiled function: FUN_0049eaa0
 * Entry Point: 0049eaa0
 * Size: 1944 bytes
 */
#include "duel.h"


HGDIOBJ FUN_0049eaa0(HWND param_1,uint param_2,HDC param_3,HWND param_4)

{
  UINT UVar1;
  HGDIOBJ pvVar2;
  HWND pHVar3;
  HBRUSH hbr;
  char *pcVar4;
  tagRECT local_44;
  COLORREF local_34;
  HWND local_30;
  int local_2c;
  HWND local_28;
  HDC local_24;
  HWND local_1c;
  HWND local_18;
  int local_14;
  char local_10 [12];
  
  if (param_2 < 0x2c) {
    if (param_2 == 0x2b) {
      local_30 = param_4;
      pHVar3 = GetFocus();
      if (pHVar3 == (HWND)local_30[5].unused) {
        local_34 = DAT_005dccd4;
      }
      else {
        local_34 = DAT_005dcce0;
      }
      FUN_00471f45(local_30,DAT_005dcd04,DAT_005dccfc,DAT_005dcd00,local_34,0);
      return (HGDIOBJ)0x1;
    }
    if (param_2 == 0x14) {
      FUN_004707a4(param_3);
      GetClientRect(param_1,&local_44);
      if (DAT_005dccc4 == 0) {
        hbr = GetStockObject(2);
        FillRect(param_3,&local_44,hbr);
      }
      else {
        FUN_004709ae(param_3,&local_44,DAT_005dccc4);
      }
      return (HGDIOBJ)0x1;
    }
  }
  else if (param_2 < 0x136) {
    if (param_2 == 0x135) {
LAB_0049efa8:
      local_24 = param_3;
      FUN_004707a4(param_3);
      local_28 = param_4;
      local_2c = GetDlgCtrlID(param_4);
      if (local_2c == 0x482) {
        SetTextColor(local_24,DAT_005dcccc);
        SetBkMode(local_24,1);
        return DAT_005dcd04;
      }
      if (local_2c == 0x48c) {
        SetTextColor(local_24,DAT_005dccc0);
        SetBkMode(local_24,1);
        pvVar2 = GetStockObject(5);
        return pvVar2;
      }
      pHVar3 = GetFocus();
      if (pHVar3 == local_28) {
        SetTextColor(local_24,DAT_005dccd4);
      }
      else {
        SetTextColor(local_24,DAT_005dcccc);
      }
      SetBkMode(local_24,1);
      pvVar2 = GetStockObject(5);
      return pvVar2;
    }
    if (param_2 == 0x110) {
      if (DAT_005f67f0 == 0) {
        local_14 = 0x458;
      }
      else {
        local_14 = 0x459;
      }
      CheckDlgButton(param_1,local_14,1);
      CheckRadioButton(param_1,0x458,0x459,local_14);
      if (DAT_005f628c == 2) {
        local_14 = 0x456;
      }
      else {
        local_14 = 0x457;
      }
      CheckDlgButton(param_1,local_14,1);
      CheckRadioButton(param_1,0x456,0x457,local_14);
      if (DAT_005f6294 == 0x3c) {
        local_14 = 0x45e;
      }
      else {
        local_14 = 0x45f;
      }
      CheckDlgButton(param_1,local_14,1);
      CheckRadioButton(param_1,0x45e,0x45f,local_14);
      if (DAT_005f2f50 == 0) {
        local_14 = 0x45a;
      }
      else if (DAT_005f2f50 == 1) {
        local_14 = 0x45b;
      }
      else if (DAT_005f2f50 == 2) {
        local_14 = 0x45c;
      }
      else {
        local_14 = 0x45d;
      }
      CheckDlgButton(param_1,local_14,1);
      CheckRadioButton(param_1,0x45a,0x45d,local_14);
      if (DAT_005f64a0 == 0) {
        local_14 = 0x460;
      }
      else {
        local_14 = 0x461;
      }
      CheckDlgButton(param_1,local_14,1);
      CheckRadioButton(param_1,0x460,0x461,local_14);
      CheckDlgButton(param_1,0x46a,DAT_005f64a4);
      _sprintf(local_10,&DAT_00505e68,DAT_005f2f50);
      pcVar4 = local_10;
      pHVar3 = GetDlgItem(param_1,0x482);
      SetWindowTextA(pHVar3,pcVar4);
      FUN_0049f242(&DAT_005dccc4,&DAT_005dccc0,&DAT_005dcccc,&DAT_005dcd04,&DAT_005dccfc,
                   &DAT_005dcd00,&DAT_005dcce0,&DAT_005dccd4);
      pHVar3 = GetDlgItem(param_1,1);
      SetFocus(pHVar3);
      SendMessageA(param_1,0x401,1,0);
      FUN_00472552(param_1);
      return (HGDIOBJ)0x0;
    }
    if (param_2 == 0x111) {
      if (((uint)param_3 & 0xffff) == 1) {
        UVar1 = IsDlgButtonChecked(param_1,0x456);
        if (UVar1 == 0) {
          DAT_005f628c = 1;
        }
        else {
          DAT_005f628c = 2;
        }
        UVar1 = IsDlgButtonChecked(param_1,0x46a);
        DAT_005f64a4 = (UINT)(UVar1 != 0);
        UVar1 = IsDlgButtonChecked(param_1,0x45a);
        if (UVar1 == 0) {
          UVar1 = IsDlgButtonChecked(param_1,0x45b);
          if (UVar1 == 0) {
            UVar1 = IsDlgButtonChecked(param_1,0x45c);
            if (UVar1 == 0) {
              DAT_005f2f50 = 3;
            }
            else {
              DAT_005f2f50 = 2;
            }
          }
          else {
            DAT_005f2f50 = 1;
          }
        }
        else {
          DAT_005f2f50 = 0;
        }
        FUN_0049f327(DAT_005dccc4,DAT_005dcd04,DAT_005dccfc,DAT_005dcd00);
        EndDialog(param_1,1);
      }
      else if (((uint)param_3 & 0xffff) == 2) {
        FUN_0049f327(DAT_005dccc4,DAT_005dcd04,DAT_005dccfc,DAT_005dcd00);
        EndDialog(param_1,0);
      }
      else {
        UVar1 = IsDlgButtonChecked(param_1,0x45a);
        if (UVar1 == 0) {
          UVar1 = IsDlgButtonChecked(param_1,0x45b);
          if (UVar1 == 0) {
            UVar1 = IsDlgButtonChecked(param_1,0x45c);
            if (UVar1 == 0) {
              DAT_005f2f50 = 3;
            }
            else {
              DAT_005f2f50 = 2;
            }
          }
          else {
            DAT_005f2f50 = 1;
          }
        }
        else {
          DAT_005f2f50 = 0;
        }
        _sprintf(local_10,&DAT_00505e6c,DAT_005f2f50);
        pcVar4 = local_10;
        pHVar3 = GetDlgItem(param_1,0x482);
        SetWindowTextA(pHVar3,pcVar4);
      }
      return (HGDIOBJ)0x1;
    }
  }
  else if (param_2 < 0x202) {
    if (param_2 == 0x201) {
      SendMessageA(param_1,0x112,0xf012,0);
      return (HGDIOBJ)0x0;
    }
    if (param_2 == 0x138) goto LAB_0049efa8;
  }
  else if (0x30e < param_2) {
    if (param_2 < 0x312) {
      pvVar2 = (HGDIOBJ)FUN_00472b60(param_1,param_2,param_3,param_4);
      return pvVar2;
    }
    if (param_2 == 0x4c8) {
      local_18 = (HWND)param_3;
      local_1c = param_4;
      pHVar3 = GetDlgItem(param_1,2);
      if (pHVar3 == local_18) {
        SendMessageA(param_1,0x401,2,0);
      }
      else {
        SendMessageA(param_1,0x401,1,0);
      }
      if (local_18 != (HWND)0x0) {
        InvalidateRect(local_18,(RECT *)0x0,1);
      }
      if (local_1c != (HWND)0x0) {
        InvalidateRect(local_1c,(RECT *)0x0,1);
      }
      return (HGDIOBJ)0x0;
    }
  }
  return (HGDIOBJ)0x0;
}



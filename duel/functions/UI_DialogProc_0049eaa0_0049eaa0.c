/*
 * Decompiled function: UI_DialogProc_0049eaa0
 * Entry Point: 0049eaa0
 * Size: 1944 bytes
 */
#include "duel.h"


HBRUSH UI_DialogProc_0049eaa0(HWND hwnd,uint uMsg,HDC wParam,HWND lParam)

{
  UINT UVar1;
  HWND pHVar2;
  HBRUSH pHVar3;
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
  
  if (uMsg < 0x2c) {
    if (uMsg == 0x2b) {
      local_30 = lParam;
      pHVar2 = GetFocus();
      if (pHVar2 == (HWND)local_30[5].unused) {
        local_34 = DAT_005dccd4;
      }
      else {
        local_34 = DAT_005dcce0;
      }
      FUN_00471f45((int)local_30,DAT_005dcd04,DAT_005dccfc,DAT_005dcd00,local_34,0);
      return (HBRUSH)0x1;
    }
    if (uMsg == 0x14) {
      FUN_004707a4(wParam);
      GetClientRect(hwnd,&local_44);
      if (DAT_005dccc4 == (HANDLE)0x0) {
        pHVar3 = GetStockObject(2);
        FillRect(wParam,&local_44,pHVar3);
      }
      else {
        FUN_004709ae((int)wParam,(int)&local_44,DAT_005dccc4);
      }
      return (HBRUSH)0x1;
    }
  }
  else if (uMsg < 0x136) {
    if (uMsg == 0x135) {
LAB_0049efa8:
      local_24 = wParam;
      FUN_004707a4(wParam);
      local_28 = lParam;
      local_2c = GetDlgCtrlID(lParam);
      if (local_2c == 0x482) {
        SetTextColor(local_24,DAT_005dcccc);
        SetBkMode(local_24,1);
        return DAT_005dcd04;
      }
      if (local_2c == 0x48c) {
        SetTextColor(local_24,DAT_005dccc0);
        SetBkMode(local_24,1);
        pHVar3 = GetStockObject(5);
        return pHVar3;
      }
      pHVar2 = GetFocus();
      if (pHVar2 == local_28) {
        SetTextColor(local_24,DAT_005dccd4);
      }
      else {
        SetTextColor(local_24,DAT_005dcccc);
      }
      SetBkMode(local_24,1);
      pHVar3 = GetStockObject(5);
      return pHVar3;
    }
    if (uMsg == 0x110) {
      if (DAT_005f67f0 == 0) {
        local_14 = 0x458;
      }
      else {
        local_14 = 0x459;
      }
      CheckDlgButton(hwnd,local_14,1);
      CheckRadioButton(hwnd,0x458,0x459,local_14);
      if (DAT_005f628c == 2) {
        local_14 = 0x456;
      }
      else {
        local_14 = 0x457;
      }
      CheckDlgButton(hwnd,local_14,1);
      CheckRadioButton(hwnd,0x456,0x457,local_14);
      if (DAT_005f6294 == 0x3c) {
        local_14 = 0x45e;
      }
      else {
        local_14 = 0x45f;
      }
      CheckDlgButton(hwnd,local_14,1);
      CheckRadioButton(hwnd,0x45e,0x45f,local_14);
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
      CheckDlgButton(hwnd,local_14,1);
      CheckRadioButton(hwnd,0x45a,0x45d,local_14);
      if (DAT_005f64a0 == 0) {
        local_14 = 0x460;
      }
      else {
        local_14 = 0x461;
      }
      CheckDlgButton(hwnd,local_14,1);
      CheckRadioButton(hwnd,0x460,0x461,local_14);
      CheckDlgButton(hwnd,0x46a,DAT_005f64a4);
      _sprintf(local_10,&DAT_00505e68,DAT_005f2f50);
      pcVar4 = local_10;
      pHVar2 = GetDlgItem(hwnd,0x482);
      SetWindowTextA(pHVar2,pcVar4);
      Pic_Load_s_GAUN_Options_0049f242
                (&DAT_005dccc4,&DAT_005dccc0,&DAT_005dcccc,(int *)&DAT_005dcd04,(int *)&DAT_005dccfc
                 ,(int *)&DAT_005dcd00,&DAT_005dcce0,&DAT_005dccd4);
      pHVar2 = GetDlgItem(hwnd,1);
      SetFocus(pHVar2);
      SendMessageA(hwnd,0x401,1,0);
      FUN_00472552(hwnd);
      return (HBRUSH)0x0;
    }
    if (uMsg == 0x111) {
      if (((uint)wParam & 0xffff) == 1) {
        UVar1 = IsDlgButtonChecked(hwnd,0x456);
        if (UVar1 == 0) {
          DAT_005f628c = 1;
        }
        else {
          DAT_005f628c = 2;
        }
        UVar1 = IsDlgButtonChecked(hwnd,0x46a);
        DAT_005f64a4 = (UINT)(UVar1 != 0);
        UVar1 = IsDlgButtonChecked(hwnd,0x45a);
        if (UVar1 == 0) {
          UVar1 = IsDlgButtonChecked(hwnd,0x45b);
          if (UVar1 == 0) {
            UVar1 = IsDlgButtonChecked(hwnd,0x45c);
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
        EndDialog(hwnd,1);
      }
      else if (((uint)wParam & 0xffff) == 2) {
        FUN_0049f327(DAT_005dccc4,DAT_005dcd04,DAT_005dccfc,DAT_005dcd00);
        EndDialog(hwnd,0);
      }
      else {
        UVar1 = IsDlgButtonChecked(hwnd,0x45a);
        if (UVar1 == 0) {
          UVar1 = IsDlgButtonChecked(hwnd,0x45b);
          if (UVar1 == 0) {
            UVar1 = IsDlgButtonChecked(hwnd,0x45c);
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
        pHVar2 = GetDlgItem(hwnd,0x482);
        SetWindowTextA(pHVar2,pcVar4);
      }
      return (HBRUSH)0x1;
    }
  }
  else if (uMsg < 0x202) {
    if (uMsg == 0x201) {
      SendMessageA(hwnd,0x112,0xf012,0);
      return (HBRUSH)0x0;
    }
    if (uMsg == 0x138) goto LAB_0049efa8;
  }
  else if (0x30e < uMsg) {
    if (uMsg < 0x312) {
      pHVar3 = (HBRUSH)FUN_00472b60(hwnd,uMsg,(HWND)wParam,lParam);
      return pHVar3;
    }
    if (uMsg == 0x4c8) {
      local_18 = (HWND)wParam;
      local_1c = lParam;
      pHVar2 = GetDlgItem(hwnd,2);
      if (pHVar2 == local_18) {
        SendMessageA(hwnd,0x401,2,0);
      }
      else {
        SendMessageA(hwnd,0x401,1,0);
      }
      if (local_18 != (HWND)0x0) {
        InvalidateRect(local_18,(RECT *)0x0,1);
      }
      if (local_1c != (HWND)0x0) {
        InvalidateRect(local_1c,(RECT *)0x0,1);
      }
      return (HBRUSH)0x0;
    }
  }
  return (HBRUSH)0x0;
}



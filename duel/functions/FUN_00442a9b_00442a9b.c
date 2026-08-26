/*
 * Decompiled function: FUN_00442a9b
 * Entry Point: 00442a9b
 * Size: 924 bytes
 */
#include "duel.h"


HWND FUN_00442a9b(HWND param_1,uint param_2,uint param_3,undefined4 *param_4)

{
  UINT UVar1;
  LONG LVar2;
  HWND pHVar3;
  int iVar4;
  INT_PTR local_c;
  
  if (param_2 < 0x202) {
    if (param_2 == 0x201) {
      SendMessageA(param_1,0x112,0xf012,0);
      return (HWND)0x0;
    }
    if (param_2 == 0x110) {
      SetWindowLongA(param_1,8,param_4[1]);
      SetDlgItemTextA(param_1,0x429,(LPCSTR)*param_4);
      if (param_4[2] == 0) {
        iVar4 = 0;
        pHVar3 = GetDlgItem(param_1,0x42a);
        ShowWindow(pHVar3,iVar4);
      }
      if ((param_4[3] == 0) || (*(char *)param_4[3] == '\0')) {
        iVar4 = 0;
        pHVar3 = GetDlgItem(param_1,0x42d);
        ShowWindow(pHVar3,iVar4);
      }
      else {
        SetDlgItemTextA(param_1,0x42d,(LPCSTR)param_4[3]);
      }
      if ((param_4[4] == 0) || (*(char *)param_4[4] == '\0')) {
        iVar4 = 0;
        pHVar3 = GetDlgItem(param_1,0x42c);
        ShowWindow(pHVar3,iVar4);
      }
      else {
        SetDlgItemTextA(param_1,0x42c,(LPCSTR)param_4[4]);
      }
      if ((param_4[5] == 0) || (*(char *)param_4[5] == '\0')) {
        iVar4 = 0;
        pHVar3 = GetDlgItem(param_1,0x42b);
        ShowWindow(pHVar3,iVar4);
      }
      else {
        SetDlgItemTextA(param_1,0x42b,(LPCSTR)param_4[5]);
      }
      if (param_4[1] == 0) {
        CheckDlgButton(param_1,0x42d,(uint)(param_4[1] == 0));
      }
      else if (param_4[1] == 1) {
        CheckDlgButton(param_1,0x42c,(uint)(param_4[1] == 1));
      }
      else {
        CheckDlgButton(param_1,0x42b,(uint)(param_4[1] == 2));
      }
      pHVar3 = GetDlgItem(param_1,1);
      SetFocus(pHVar3);
      return (HWND)0x0;
    }
    if (param_2 == 0x111) {
      if ((param_3 & 0xffff) == 1) {
        UVar1 = IsDlgButtonChecked(param_1,0x42d);
        if (UVar1 != 0) {
          local_c = 0;
        }
        UVar1 = IsDlgButtonChecked(param_1,0x42c);
        if (UVar1 != 0) {
          local_c = 1;
        }
        UVar1 = IsDlgButtonChecked(param_1,0x42b);
        if (UVar1 != 0) {
          local_c = 2;
        }
        EndDialog(param_1,local_c);
      }
      else if ((param_3 & 0xffff) == 0x42a) {
        LVar2 = GetWindowLongA(param_1,8);
        CheckDlgButton(param_1,0x42d,(uint)(LVar2 == 0));
        CheckDlgButton(param_1,0x42c,(uint)(LVar2 == 1));
        CheckDlgButton(param_1,0x42b,(uint)(LVar2 == 2));
        pHVar3 = GetDlgItem(param_1,1);
        pHVar3 = SetFocus(pHVar3);
        return pHVar3;
      }
      return (HWND)0x1;
    }
  }
  else if ((0x30e < param_2) && (param_2 < 0x312)) {
    pHVar3 = (HWND)FUN_00472b60(param_1,param_2,param_3,param_4);
    return pHVar3;
  }
  return (HWND)0x0;
}



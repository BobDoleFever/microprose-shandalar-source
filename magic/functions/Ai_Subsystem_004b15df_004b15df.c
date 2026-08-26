/*
 * Decompiled function: Ai_Subsystem_004b15df
 * Entry Point: 004b15df
 * Size: 912 bytes
 */
#include "magic.h"


HWND Ai_Subsystem_004b15df(HWND hwnd,uint uMsg,uint wParam,undefined4 *lParam)

{
  UINT UVar1;
  LONG LVar2;
  HWND pHVar3;
  int iVar4;
  INT_PTR local_c;
  
  if (uMsg < 0x202) {
    if (uMsg == 0x201) {
      SendMessageA(hwnd,0x112,0xf012,0);
      return (HWND)0x0;
    }
    if (uMsg == 0x110) {
      SetWindowLongA(hwnd,8,lParam[1]);
      SetDlgItemTextA(hwnd,0x429,(LPCSTR)*lParam);
      if (lParam[2] == 0) {
        iVar4 = 0;
        pHVar3 = GetDlgItem(hwnd,0x42a);
        ShowWindow(pHVar3,iVar4);
      }
      if ((lParam[3] == 0) || (*(char *)lParam[3] == '\0')) {
        iVar4 = 0;
        pHVar3 = GetDlgItem(hwnd,0x42d);
        ShowWindow(pHVar3,iVar4);
      }
      else {
        SetDlgItemTextA(hwnd,0x42d,(LPCSTR)lParam[3]);
      }
      if ((lParam[4] == 0) || (*(char *)lParam[4] == '\0')) {
        iVar4 = 0;
        pHVar3 = GetDlgItem(hwnd,0x42c);
        ShowWindow(pHVar3,iVar4);
      }
      else {
        SetDlgItemTextA(hwnd,0x42c,(LPCSTR)lParam[4]);
      }
      if ((lParam[5] == 0) || (*(char *)lParam[5] == '\0')) {
        iVar4 = 0;
        pHVar3 = GetDlgItem(hwnd,0x42b);
        ShowWindow(pHVar3,iVar4);
      }
      else {
        SetDlgItemTextA(hwnd,0x42b,(LPCSTR)lParam[5]);
      }
      if (lParam[1] == 0) {
        CheckDlgButton(hwnd,0x42d,(uint)(lParam[1] == 0));
      }
      else if (lParam[1] == 1) {
        CheckDlgButton(hwnd,0x42c,(uint)(lParam[1] == 1));
      }
      else {
        CheckDlgButton(hwnd,0x42b,(uint)(lParam[1] == 2));
      }
      pHVar3 = GetDlgItem(hwnd,1);
      SetFocus(pHVar3);
      return (HWND)0x0;
    }
    if (uMsg == 0x111) {
      if ((wParam & 0xffff) == 1) {
        UVar1 = IsDlgButtonChecked(hwnd,0x42d);
        if (UVar1 != 0) {
          local_c = 0;
        }
        UVar1 = IsDlgButtonChecked(hwnd,0x42c);
        if (UVar1 != 0) {
          local_c = 1;
        }
        UVar1 = IsDlgButtonChecked(hwnd,0x42b);
        if (UVar1 != 0) {
          local_c = 2;
        }
        EndDialog(hwnd,local_c);
      }
      else if ((wParam & 0xffff) == 0x42a) {
        LVar2 = GetWindowLongA(hwnd,8);
        CheckDlgButton(hwnd,0x42d,(uint)(LVar2 == 0));
        CheckDlgButton(hwnd,0x42c,(uint)(LVar2 == 1));
        CheckDlgButton(hwnd,0x42b,(uint)(LVar2 == 2));
        pHVar3 = GetDlgItem(hwnd,1);
        pHVar3 = SetFocus(pHVar3);
        return pHVar3;
      }
      return (HWND)0x1;
    }
  }
  else if ((0x30e < uMsg) && (uMsg < 0x312)) {
    pHVar3 = (HWND)FUN_004f5d1a(hwnd,uMsg,(HWND)wParam,lParam);
    return pHVar3;
  }
  return (HWND)0x0;
}



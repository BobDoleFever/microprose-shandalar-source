/*
 * Decompiled function: UI_DialogProc_00442e98
 * Entry Point: 00442e98
 * Size: 355 bytes
 */
#include "duel.h"


undefined4 UI_DialogProc_00442e98(HWND hwnd,uint uMsg,uint wParam,undefined4 *lParam)

{
  HWND pHVar1;
  undefined4 uVar2;
  
  if (uMsg < 0x202) {
    if (uMsg == 0x201) {
      SendMessageA(hwnd,0x112,0xf012,0);
      return 0;
    }
    if (uMsg == 0x110) {
      SetWindowLongA(hwnd,8,lParam[1]);
      SetDlgItemTextA(hwnd,0x42e,(LPCSTR)*lParam);
      if (lParam[1] == 1) {
        pHVar1 = GetDlgItem(hwnd,6);
        SetFocus(pHVar1);
      }
      else {
        pHVar1 = GetDlgItem(hwnd,7);
        SetFocus(pHVar1);
      }
      return 0;
    }
    if (uMsg == 0x111) {
      if ((wParam & 0xffff) == 6) {
        EndDialog(hwnd,1);
      }
      else if ((wParam & 0xffff) == 7) {
        EndDialog(hwnd,0);
      }
      return 1;
    }
  }
  else if ((0x30e < uMsg) && (uMsg < 0x312)) {
    uVar2 = FUN_00472b60(hwnd,uMsg,(HWND)wParam,lParam);
    return uVar2;
  }
  return 0;
}



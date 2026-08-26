/*
 * Decompiled function: UI_WndProc_0042b324
 * Entry Point: 0042b324
 * Size: 878 bytes
 */
#include "duel.h"


LRESULT UI_WndProc_0042b324(HWND hwnd,uint uMsg,WPARAM wParam,uint lParam)

{
  POINT pt;
  LONG LVar1;
  HWND pHVar2;
  uint uVar3;
  HWND pHVar4;
  LRESULT LVar5;
  UINT UVar6;
  WPARAM wParam_00;
  int nIDDlgItem;
  tagRECT local_34;
  uint local_24;
  uint local_20;
  tagRECT local_1c;
  WPARAM local_c;
  HICON local_8;
  
  if (uMsg < 8) {
    if (uMsg == 7) {
      pHVar2 = hwnd;
      uVar3 = GetDlgCtrlID(hwnd);
      uVar3 = uVar3 & 0xffff;
      UVar6 = 0x111;
      pHVar4 = GetParent(hwnd);
      SendMessageA(pHVar4,UVar6,uVar3,(LPARAM)pHVar2);
      return 0;
    }
    if (uMsg == 1) {
      local_8 = LoadIconA(DAT_00664680,*(LPCSTR *)(lParam + 0x24));
      SetWindowLongA(hwnd,0,(LONG)local_8);
      local_c = 0;
      SetWindowLongA(hwnd,4,0);
      return 0;
    }
    if (uMsg == 2) {
      local_8 = (HICON)GetWindowLongA(hwnd,0);
      if (local_8 != (HICON)0x0) {
        DestroyIcon(local_8);
      }
      return 0;
    }
  }
  else if (uMsg < 0x88) {
    if (uMsg == 0x87) {
      return 0x2000;
    }
    if (uMsg == 0x14) {
      return 1;
    }
  }
  else if (uMsg < 0x312) {
    if (0x30e < uMsg) {
      LVar5 = FUN_00472b60(hwnd,uMsg,(HWND)wParam,lParam);
      return LVar5;
    }
    switch(uMsg) {
    case 0x200:
      pHVar2 = GetCapture();
      if (pHVar2 == hwnd) {
        local_24 = lParam & 0xffff;
        local_20 = lParam >> 0x10;
        GetClientRect(hwnd,&local_1c);
        pt.y = local_20;
        pt.x = local_24;
        local_c = PtInRect(&local_1c,pt);
        SetWindowLongA(hwnd,4,local_c);
        InvalidateRect(hwnd,(RECT *)0x0,1);
      }
      return 0;
    case 0x201:
      SetCapture(hwnd);
      local_c = 1;
      SetWindowLongA(hwnd,4,1);
      InvalidateRect(hwnd,(RECT *)0x0,1);
      return 0;
    case 0x202:
      pHVar2 = GetCapture();
      if (pHVar2 == hwnd) {
        GetClientRect(hwnd,&local_34);
        local_c = PtInRect(&local_34,(POINT)(CONCAT44(lParam >> 0x10,lParam) & 0xffffffff0000ffff));
        SetWindowLongA(hwnd,4,local_c);
        InvalidateRect(hwnd,(RECT *)0x0,1);
        ReleaseCapture();
        if (local_c != 0) {
          SetFocus(hwnd);
        }
      }
      return 0;
    case 0x203:
      nIDDlgItem = 1;
      pHVar2 = GetParent(hwnd);
      pHVar2 = GetDlgItem(pHVar2,nIDDlgItem);
      wParam_00 = 1;
      UVar6 = 0x111;
      pHVar4 = GetParent(hwnd);
      SendMessageA(pHVar4,UVar6,wParam_00,(LPARAM)pHVar2);
      return 0;
    }
  }
  else {
    if (uMsg == 0x400) {
      local_c = wParam;
      SetWindowLongA(hwnd,4,wParam);
      InvalidateRect(hwnd,(RECT *)0x0,1);
      return 0;
    }
    if (uMsg == 0x401) {
      LVar1 = GetWindowLongA(hwnd,4);
      return LVar1;
    }
  }
  LVar5 = DefWindowProcA(hwnd,uMsg,wParam,lParam);
  return LVar5;
}



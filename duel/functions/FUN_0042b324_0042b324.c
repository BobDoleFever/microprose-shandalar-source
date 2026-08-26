/*
 * Decompiled function: FUN_0042b324
 * Entry Point: 0042b324
 * Size: 878 bytes
 */
#include "duel.h"


LRESULT FUN_0042b324(HWND param_1,uint param_2,WPARAM param_3,uint param_4)

{
  POINT pt;
  LONG LVar1;
  HWND pHVar2;
  uint uVar3;
  HWND pHVar4;
  LRESULT LVar5;
  UINT UVar6;
  WPARAM wParam;
  int nIDDlgItem;
  tagRECT local_34;
  uint local_24;
  uint local_20;
  tagRECT local_1c;
  WPARAM local_c;
  HICON local_8;
  
  if (param_2 < 8) {
    if (param_2 == 7) {
      pHVar2 = param_1;
      uVar3 = GetDlgCtrlID(param_1);
      uVar3 = uVar3 & 0xffff;
      UVar6 = 0x111;
      pHVar4 = GetParent(param_1);
      SendMessageA(pHVar4,UVar6,uVar3,(LPARAM)pHVar2);
      return 0;
    }
    if (param_2 == 1) {
      local_8 = LoadIconA(DAT_00664680,*(LPCSTR *)(param_4 + 0x24));
      SetWindowLongA(param_1,0,(LONG)local_8);
      local_c = 0;
      SetWindowLongA(param_1,4,0);
      return 0;
    }
    if (param_2 == 2) {
      local_8 = (HICON)GetWindowLongA(param_1,0);
      if (local_8 != (HICON)0x0) {
        DestroyIcon(local_8);
      }
      return 0;
    }
  }
  else if (param_2 < 0x88) {
    if (param_2 == 0x87) {
      return 0x2000;
    }
    if (param_2 == 0x14) {
      return 1;
    }
  }
  else if (param_2 < 0x312) {
    if (0x30e < param_2) {
      LVar5 = FUN_00472b60(param_1,param_2,param_3,param_4);
      return LVar5;
    }
    switch(param_2) {
    case 0x200:
      pHVar2 = GetCapture();
      if (pHVar2 == param_1) {
        local_24 = param_4 & 0xffff;
        local_20 = param_4 >> 0x10;
        GetClientRect(param_1,&local_1c);
        pt.y = local_20;
        pt.x = local_24;
        local_c = PtInRect(&local_1c,pt);
        SetWindowLongA(param_1,4,local_c);
        InvalidateRect(param_1,(RECT *)0x0,1);
      }
      return 0;
    case 0x201:
      SetCapture(param_1);
      local_c = 1;
      SetWindowLongA(param_1,4,1);
      InvalidateRect(param_1,(RECT *)0x0,1);
      return 0;
    case 0x202:
      pHVar2 = GetCapture();
      if (pHVar2 == param_1) {
        GetClientRect(param_1,&local_34);
        local_c = PtInRect(&local_34,(POINT)(CONCAT44(param_4 >> 0x10,param_4) & 0xffffffff0000ffff)
                          );
        SetWindowLongA(param_1,4,local_c);
        InvalidateRect(param_1,(RECT *)0x0,1);
        ReleaseCapture();
        if (local_c != 0) {
          SetFocus(param_1);
        }
      }
      return 0;
    case 0x203:
      nIDDlgItem = 1;
      pHVar2 = GetParent(param_1);
      pHVar2 = GetDlgItem(pHVar2,nIDDlgItem);
      wParam = 1;
      UVar6 = 0x111;
      pHVar4 = GetParent(param_1);
      SendMessageA(pHVar4,UVar6,wParam,(LPARAM)pHVar2);
      return 0;
    }
  }
  else {
    if (param_2 == 0x400) {
      local_c = param_3;
      SetWindowLongA(param_1,4,param_3);
      InvalidateRect(param_1,(RECT *)0x0,1);
      return 0;
    }
    if (param_2 == 0x401) {
      LVar1 = GetWindowLongA(param_1,4);
      return LVar1;
    }
  }
  LVar5 = DefWindowProcA(param_1,param_2,param_3,param_4);
  return LVar5;
}



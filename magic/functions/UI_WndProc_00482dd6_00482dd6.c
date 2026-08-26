/*
 * Decompiled function: UI_WndProc_00482dd6
 * Entry Point: 00482dd6
 * Size: 855 bytes
 */
#include "magic.h"


LRESULT UI_WndProc_00482dd6(HWND hwnd,uint uMsg,HDC wParam,uint lParam)

{
  HBRUSH hbr;
  LRESULT LVar1;
  int local_13c;
  tagPOINT local_138;
  tagRECT local_130;
  char local_120 [264];
  HDC local_18;
  tagRECT local_14;
  
  if (uMsg < 0x15) {
    if (uMsg == 0x14) {
      local_18 = wParam;
      FUN_004f3955(wParam);
      GetClientRect(hwnd,&local_14);
      IntersectClipRect(local_18,0,0,local_14.right,local_14.bottom);
      if (DAT_0053957c == (HANDLE)0x0) {
        strcpy(local_120,&DAT_006b2e90);
        strcat(local_120,s__WINBK_AttackMin_pic_00526e18);
        DAT_0053957c = (HANDLE)Pic_Load_00423833(local_120);
      }
      if (DAT_0053957c == (HANDLE)0x0) {
        hbr = GetStockObject(4);
        FillRect(local_18,&local_14,hbr);
      }
      else {
        FUN_004f3b5f((int)local_18,(int)&local_14,DAT_0053957c);
      }
      return 1;
    }
    if (uMsg == 0x10) {
      ShowWindow(hwnd,0);
      ShowWindow(DAT_006b3064,0);
      return 0;
    }
  }
  else if (uMsg < 0x120) {
    if (uMsg == 0x11f) {
      if (((uint)wParam >> 0x10 == 0xffff) && (lParam == 0)) {
        local_13c = GetMenuItemCount(DAT_0053955c);
        while (local_13c != 0) {
          DeleteMenu(DAT_0053955c,0,0x400);
          local_13c = local_13c + -1;
        }
      }
      return 0;
    }
    if (uMsg == 0x117) {
      AppendMenuA(DAT_0053955c,0,0x66,s__Restore_00526e30);
      AppendMenuA(DAT_0053955c,0,100,s_Help____00526e3c);
      return 0;
    }
  }
  else if (uMsg < 0x205) {
    if (uMsg == 0x204) {
      local_138.x = lParam & 0xffff;
      local_138.y = lParam >> 0x10;
      ClientToScreen(hwnd,&local_138);
      SetRect(&local_130,local_138.x,local_138.y,local_138.x + 1,local_138.y + 1);
      TrackPopupMenu(DAT_0053955c,2,local_138.x,local_138.y,0,DAT_006b3064,&local_130);
      return 0;
    }
    if (uMsg == 0x201) {
      SendMessageA(DAT_006b3064,0x111,0x66,0);
      return 0;
    }
  }
  else if (0x30e < uMsg) {
    if (uMsg < 0x312) {
      LVar1 = FUN_004f5d1a(hwnd,uMsg,(HWND)wParam,lParam);
      return LVar1;
    }
    if (uMsg == 0x437) {
      strcpy((char *)wParam,s_Minimized_attack_window_00526e00);
      return 1;
    }
  }
  LVar1 = DefWindowProcA(hwnd,uMsg,(WPARAM)wParam,lParam);
  return LVar1;
}



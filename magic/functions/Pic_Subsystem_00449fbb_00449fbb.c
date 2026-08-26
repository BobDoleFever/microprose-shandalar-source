/*
 * Decompiled function: Pic_Subsystem_00449fbb
 * Entry Point: 00449fbb
 * Size: 366 bytes
 */
#include "magic.h"


LRESULT Pic_Subsystem_00449fbb(HWND hwnd,uint uMsg,WPARAM wParam,LPARAM lParam)

{
  POINT Point;
  LRESULT LVar1;
  tagPOINT local_10;
  HWND local_8;
  
  if (uMsg < 0x201) {
    if (uMsg == 0x200) {
LAB_0044a00e:
      GetCursorPos(&local_10);
      Point.y = local_10.y;
      Point.x = local_10.x;
      local_8 = WindowFromPoint(Point);
      MapWindowPoints((HWND)0x0,local_8,&local_10,1);
      if (hwnd != local_8) {
        SendMessageA(local_8,uMsg,wParam,local_10.y << 0x10 | local_10.x & 0xffffU);
      }
      return 0;
    }
    if (uMsg == 1) {
      return 0;
    }
  }
  else if (uMsg < 0x207) {
    if (uMsg == 0x206) goto LAB_0044a00e;
    if (uMsg == 0x201) {
      SendMessageA(DAT_006b2e10,0x400,0,0);
      SendMessageA(DAT_006a4928,0x400,0,0);
      return 0;
    }
  }
  else if (0x30e < uMsg) {
    if (uMsg < 0x312) {
      LVar1 = FUN_004f5d1a(hwnd,uMsg,(HWND)wParam,lParam);
      return LVar1;
    }
    if (uMsg == 0x437) {
      return 0;
    }
  }
  LVar1 = DefWindowProcA(hwnd,uMsg,wParam,lParam);
  return LVar1;
}



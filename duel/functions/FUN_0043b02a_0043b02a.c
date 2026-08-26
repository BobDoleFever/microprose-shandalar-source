/*
 * Decompiled function: FUN_0043b02a
 * Entry Point: 0043b02a
 * Size: 366 bytes
 */
#include "duel.h"


LRESULT FUN_0043b02a(HWND param_1,uint param_2,WPARAM param_3,LPARAM param_4)

{
  POINT Point;
  LRESULT LVar1;
  tagPOINT local_10;
  HWND local_8;
  
  if (param_2 < 0x201) {
    if (param_2 == 0x200) {
LAB_0043b07d:
      GetCursorPos(&local_10);
      Point.y = local_10.y;
      Point.x = local_10.x;
      local_8 = WindowFromPoint(Point);
      MapWindowPoints((HWND)0x0,local_8,&local_10,1);
      if (param_1 != local_8) {
        SendMessageA(local_8,param_2,param_3,local_10.y << 0x10 | local_10.x & 0xffffU);
      }
      return 0;
    }
    if (param_2 == 1) {
      return 0;
    }
  }
  else if (param_2 < 0x207) {
    if (param_2 == 0x206) goto LAB_0043b07d;
    if (param_2 == 0x201) {
      SendMessageA(DAT_00618978,0x400,0,0);
      SendMessageA(DAT_0061737c,0x400,0,0);
      return 0;
    }
  }
  else if (0x30e < param_2) {
    if (param_2 < 0x312) {
      LVar1 = FUN_00472b60(param_1,param_2,param_3,param_4);
      return LVar1;
    }
    if (param_2 == 0x437) {
      return 0;
    }
  }
  LVar1 = DefWindowProcA(param_1,param_2,param_3,param_4);
  return LVar1;
}



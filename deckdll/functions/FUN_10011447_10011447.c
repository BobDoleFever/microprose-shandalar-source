/*
 * Decompiled function: FUN_10011447
 * Entry Point: 10011447
 * Size: 488 bytes
 */
#include "deckdll.h"


int32_t FUN_10011447(int *arg_1)

{
  POINT Point;
  int32_t uval_1;
  int val_2;
  int val_3;
  tagPOINT local_1c;
  LRESULT local_14;
  HWND local_10;
  tagPOINT local_c;
  
  if (((arg_1[1] == 0x113) && ((HWND)*arg_1 == DAT_10176868)) && (arg_1[2] == 0)) {
    GetCursorPos(&local_1c);
    KillTimer(DAT_10176868,0);
    Point.y = local_1c.y;
    Point.x = local_1c.x;
    local_10 = WindowFromPoint(Point);
    local_c.x = local_1c.x;
    local_c.y = local_1c.y;
    ScreenToClient(local_10,&local_c);
    local_14 = SendMessageA(local_10,0x465,0,local_c.y << 0x10 | local_c.x & 0xffffU);
    if (local_14 != 0) {
      SendMessageA(DAT_10176314,0x400,(local_1c.y + 0xf) * 0x10000 | local_1c.x + 5U & 0xffff,
                   (LPARAM)(&DAT_1016e4c0 + (local_14 + -1) * 0x80));
    }
    uval_1 = 1;
  }
  else if (arg_1[1] == 0x200) {
    GetCursorPos(&local_1c);
    val_2 = abs(DAT_1004269c - local_1c.y);
    val_3 = abs(DAT_10042698 - local_1c.x);
    if (val_2 + val_3 < 2) {
      uval_1 = 0;
    }
    else {
      DAT_10042698 = local_1c.x;
      DAT_1004269c = local_1c.y;
      SetTimer(DAT_10176868,0,500,(TIMERPROC)0x0);
      if (*arg_1 != DAT_10129408) {
        DAT_10129408 = *arg_1;
        ShowWindow(DAT_10176314,0);
      }
      uval_1 = 0;
    }
  }
  else if (((uint32_t)arg_1[1] < 0x200) || (0x209 < (uint32_t)arg_1[1])) {
    uval_1 = 0;
  }
  else {
    KillTimer(DAT_10176868,0);
    ShowWindow(DAT_10176314,0);
    uval_1 = 0;
  }
  return uval_1;
}



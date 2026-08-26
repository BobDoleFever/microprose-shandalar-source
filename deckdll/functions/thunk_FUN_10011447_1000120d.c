/*
 * Decompiled function: thunk_FUN_10011447
 * Entry Point: 1000120d
 * Size: 5 bytes
 */
#include "deckdll.h"


int32_t thunk_FUN_10011447(int *arg_1)

{
  POINT Point;
  int32_t uval_1;
  int val_2;
  int val_3;
  tagPOINT tStack_1c;
  LRESULT LStack_14;
  HWND pHStack_10;
  tagPOINT tStack_c;
  
  if (((arg_1[1] == 0x113) && ((HWND)*arg_1 == DAT_10176868)) && (arg_1[2] == 0)) {
    GetCursorPos(&tStack_1c);
    KillTimer(DAT_10176868,0);
    Point.y = tStack_1c.y;
    Point.x = tStack_1c.x;
    pHStack_10 = WindowFromPoint(Point);
    tStack_c.x = tStack_1c.x;
    tStack_c.y = tStack_1c.y;
    ScreenToClient(pHStack_10,&tStack_c);
    LStack_14 = SendMessageA(pHStack_10,0x465,0,tStack_c.y << 0x10 | tStack_c.x & 0xffffU);
    if (LStack_14 != 0) {
      SendMessageA(DAT_10176314,0x400,(tStack_1c.y + 0xf) * 0x10000 | tStack_1c.x + 5U & 0xffff,
                   (LPARAM)(&DAT_1016e4c0 + (LStack_14 + -1) * 0x80));
    }
    uval_1 = 1;
  }
  else if (arg_1[1] == 0x200) {
    GetCursorPos(&tStack_1c);
    val_2 = abs(DAT_1004269c - tStack_1c.y);
    val_3 = abs(DAT_10042698 - tStack_1c.x);
    if (val_2 + val_3 < 2) {
      uval_1 = 0;
    }
    else {
      DAT_10042698 = tStack_1c.x;
      DAT_1004269c = tStack_1c.y;
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



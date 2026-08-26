/*
 * Decompiled function: thunk_FUN_1000ce3f
 * Entry Point: 100012b2
 * Size: 5 bytes
 */
#include "deckdll.h"


void thunk_FUN_1000ce3f(HWND hwnd,int arg_2,int arg_3,int arg_4,int arg_5)

{
  POINT Point;
  WORD WVar1;
  int val_2;
  LRESULT LVar3;
  tagPOINT tStack_38;
  int iStack_30;
  int iStack_2c;
  HWND pHStack_28;
  uint32_t uStack_24;
  HWND pHStack_20;
  tagRECT tStack_1c;
  LPVOID pvStack_c;
  HWND pHStack_8;
  
  pvStack_c = (LPVOID)GetWindowLongA(hwnd,0);
  WVar1 = GetWindowWord(hwnd,4);
  pHStack_20 = GetParent(hwnd);
  iStack_30 = GetDlgCtrlID(hwnd);
  GetWindowRect(hwnd,&tStack_1c);
  if (1 < WVar1) {
    tStack_38.x = tStack_1c.left;
    tStack_38.y = tStack_1c.top;
    SendMessageA(hwnd,0x401,1,0);
    MapWindowPoints((HWND)0x0,pHStack_20,&tStack_38,1);
    pHStack_28 = CreateWindowExA(0,s_MAGICDECK_CardClass_10041448,&DAT_10041444,0x54000000,
                                 tStack_38.x,tStack_38.y,DAT_10175558,DAT_10176860,pHStack_20,
                                 (HMENU)0x1,DAT_101cf334,pvStack_c);
    SendMessageA(pHStack_28,0x401,WVar1 - 1,0);
    BringWindowToTop(pHStack_28);
  }
  if (arg_5 == 1) {
    LockWindowUpdate(DAT_10176868);
    MapWindowPoints((HWND)0x0,DAT_10176868,(LPPOINT)&tStack_1c,2);
    MoveWindow(hwnd,tStack_1c.left,tStack_1c.top,0,0,1);
    SetParent(hwnd,DAT_10176868);
    MoveWindow(hwnd,tStack_1c.left,tStack_1c.top,tStack_1c.right - tStack_1c.left,
               tStack_1c.bottom - tStack_1c.top,1);
    BringWindowToTop(hwnd);
    LockWindowUpdate((HWND)0x0);
    SendMessageA(hwnd,0x112,0xf012,0);
    DestroyWindow(hwnd);
    GetCursorPos(&tStack_38);
    Point.y = tStack_38.y;
    Point.x = tStack_38.x;
    for (pHStack_8 = WindowFromPoint(Point);
        ((((pHStack_8 != (HWND)0x0 && (DAT_10176868 != pHStack_8)) && (DAT_101cf33c != pHStack_8))
         && ((DAT_10176850 != pHStack_8 && (DAT_101625ec != pHStack_8)))) &&
        (DAT_101cfb80 != pHStack_8)); pHStack_8 = GetParent(pHStack_8)) {
    }
  }
  else {
    pHStack_8 = DAT_101cfb80;
    DestroyWindow(hwnd);
    SetFocus(DAT_101cfb80);
  }
  uStack_24 = CONCAT22(uStack_24._2_2_,1);
  if (pHStack_20 == DAT_101cf33c) {
    if (arg_4 < 2) {
      SendMessageA(pHStack_28,0x401,WVar1 - 1,0);
      uStack_24 = CONCAT22(uStack_24._2_2_,1);
    }
    else {
      DAT_101cfb9c = (uint32_t)WVar1;
      val_2 = thunk_FUN_1000ad0b();
      if (val_2 == 0) {
        DAT_10175ecc = 0;
      }
      if (DAT_10175ecc < 1) {
        SendMessageA(pHStack_28,0x401,(uint32_t)WVar1,0);
        uStack_24 = uStack_24 & 0xffff0000;
      }
      else if (DAT_10175ecc < (int)(uint32_t)WVar1) {
        SendMessageA(pHStack_28,0x401,(uint32_t)WVar1 - DAT_10175ecc,0);
        uStack_24 = CONCAT22(uStack_24._2_2_,(short)DAT_10175ecc);
      }
      else {
        DestroyWindow(pHStack_28);
        uStack_24 = CONCAT22(uStack_24._2_2_,WVar1);
      }
    }
    for (iStack_2c = 0; iStack_2c < (int)(uStack_24 & 0xffff); iStack_2c = iStack_2c + 1) {
      thunk_FUN_1000d510((int)pvStack_c,0);
    }
    thunk_FUN_100395de((int)pvStack_c,uStack_24 & 0xffff,0x101cded0);
    thunk_FUN_1000880b();
    thunk_FUN_10027036();
  }
  else if (DAT_10176850 == pHStack_20) {
    thunk_FUN_100397d0(iStack_30,(int)pvStack_c,1,0x101cded0);
  }
  else {
    thunk_FUN_10039a61(iStack_30,(int)pvStack_c,1,0x101cded0);
  }
  if (DAT_101cf33c == pHStack_8) {
    if (pHStack_20 != pHStack_8) {
      DAT_1016a618 = 1;
    }
    ScreenToClient(pHStack_8,&tStack_38);
    tStack_38.x = tStack_38.x - arg_2;
    tStack_38.y = tStack_38.y - arg_3;
    for (iStack_2c = 0; iStack_2c < (int)(uStack_24 & 0xffff); iStack_2c = iStack_2c + 1) {
      LVar3 = SendMessageA(pHStack_8,0x4c8,(WPARAM)pvStack_c,
                           tStack_38.y << 0x10 | tStack_38.x & 0xffffU);
      if (LVar3 == 0) {
        MessageBeep(0);
      }
      thunk_FUN_1000d510((int)pvStack_c,2);
    }
    thunk_FUN_1000880b();
  }
  else if ((DAT_101625ec == pHStack_8) || (DAT_10176850 == pHStack_8)) {
    if (pHStack_20 != pHStack_8) {
      DAT_1016a618 = 1;
    }
    ScreenToClient(pHStack_8,&tStack_38);
    if (DAT_101625ec == pHStack_8) {
      uStack_24 = uStack_24 & 0xffff0000;
    }
    for (iStack_2c = 0; iStack_2c < (int)(uStack_24 & 0xffff); iStack_2c = iStack_2c + 1) {
      LVar3 = SendMessageA(pHStack_8,0x4c8,(WPARAM)pvStack_c,
                           tStack_38.y << 0x10 | tStack_38.x & 0xffffU);
      if (LVar3 == 0) {
        MessageBeep(0);
      }
    }
  }
  else if (DAT_101cfb80 == pHStack_8) {
    thunk_FUN_1003a490();
    if ((pHStack_20 != pHStack_8) && (DAT_1016a618 = 1, DAT_101cf542 != '\0')) {
      thunk_FUN_10027a61(3,400,0,0);
    }
    for (iStack_2c = 0; iStack_2c < (int)(uStack_24 & 0xffff); iStack_2c = iStack_2c + 1) {
      val_2 = thunk_FUN_1000d510((int)pvStack_c,3);
      if (val_2 != 0) {
        thunk_FUN_1003798a(DAT_101cf538,DAT_101cfb80);
      }
    }
    if ((DAT_1017646c & 1) != 0) {
      SendMessageA(DAT_101cfb80,0x466,(WPARAM)pvStack_c,0);
    }
  }
  else {
    ScreenToClient(pHStack_8,&tStack_38);
    tStack_38.x = tStack_38.x - arg_2;
    tStack_38.y = tStack_38.y - arg_3;
    thunk_FUN_1000d510((int)pvStack_c,2);
    for (iStack_2c = 0; iStack_2c < (int)(uStack_24 & 0xffff); iStack_2c = iStack_2c + 1) {
      LVar3 = SendMessageA(DAT_101cf33c,0x4c8,(WPARAM)pvStack_c,
                           tStack_38.y << 0x10 | tStack_38.x & 0xffffU);
      if (LVar3 == 0) {
        MessageBeep(0);
      }
    }
    thunk_FUN_1000880b();
  }
  if (DAT_101cece4 == 0) {
    DAT_1016a618 = 0;
  }
  return;
}



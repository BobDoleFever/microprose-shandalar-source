/*
 * Decompiled function: thunk_FUN_10037c37
 * Entry Point: 10001451
 * Size: 5 bytes
 */
#include "deckdll.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int32_t thunk_FUN_10037c37(HWND hwnd,int arg_2,int arg_3)

{
  POINT pt;
  POINT Point;
  WPARAM wParam;
  BOOL BVar1;
  int32_t uval_2;
  int val_3;
  LRESULT LVar4;
  int iStack_30;
  int iStack_2c;
  int iStack_28;
  tagRECT tStack_24;
  LPVOID pvStack_14;
  HWND pHStack_10;
  HWND pHStack_c;
  int iStack_8;
  
  wParam = SendMessageA(hwnd,0x188,0,0);
  pvStack_14 = (LPVOID)SendMessageA(hwnd,0x199,wParam,0);
  thunk_FUN_100372c5(DAT_101cfb80,wParam,&tStack_24);
  pt.y = DAT_1013f17c;
  pt.x = DAT_1013f178;
  BVar1 = PtInRect(&tStack_24,pt);
  if (BVar1 == 0) {
    uval_2 = 0;
  }
  else {
    MapWindowPoints(DAT_101cfb80,DAT_10176868,(LPPOINT)&tStack_24,2);
    if (arg_2 == 1) {
      pHStack_10 = CreateWindowExA(0,s_MAGICDECK_CardClass_1004bab0,&DAT_1004baa8,0x54000000,
                                   tStack_24.left,tStack_24.top,DAT_10175558,DAT_10176860,
                                   DAT_10176868,(HMENU)0x1,DAT_101cf334,pvStack_14);
      if (pHStack_10 == (HWND)0x0) {
        return 0;
      }
      BringWindowToTop(pHStack_10);
      UpdateWindow(pHStack_10);
      iStack_28 = _DAT_1013f190 - tStack_24.left;
      iStack_8 = _DAT_1013f194 - tStack_24.top;
      SendMessageA(pHStack_10,0x112,0xf012,0);
      DestroyWindow(pHStack_10);
      GetCursorPos((LPPOINT)&DAT_1013f190);
      Point.y = _DAT_1013f194;
      Point.x = _DAT_1013f190;
      for (pHStack_c = WindowFromPoint(Point);
          ((((pHStack_c != (HWND)0x0 && (DAT_10176868 != pHStack_c)) && (pHStack_c != DAT_101cf33c))
           && ((pHStack_c != DAT_10176850 && (pHStack_c != DAT_101625ec)))) &&
          (pHStack_c != DAT_101cfb80)); pHStack_c = GetParent(pHStack_c)) {
      }
    }
    else {
      pHStack_c = DAT_101cf33c;
    }
    if (arg_3 == 1) {
      if (((DAT_1017646c & 1) == 0) && ((DAT_1017646c & 0x20) == 0)) {
        thunk_FUN_1000ad0b();
        iStack_30 = DAT_10175ecc;
      }
      else {
        iStack_30 = thunk_FUN_1003724f((int)pvStack_14);
        DAT_101cfb9c = iStack_30;
        val_3 = thunk_FUN_1000ad0b();
        if (val_3 == 0) {
          DAT_10175ecc = 0;
        }
        if (DAT_10175ecc < iStack_30) {
          iStack_30 = DAT_10175ecc;
        }
        for (iStack_2c = 0; iStack_2c < iStack_30; iStack_2c = iStack_2c + 1) {
          thunk_FUN_1000d510((int)pvStack_14,1);
        }
        thunk_FUN_10037837(DAT_101cf538,DAT_101cfb80);
      }
    }
    else {
      iStack_30 = 1;
      if ((((DAT_1017646c & 1) != 0) || ((DAT_1017646c & 0x20) != 0)) &&
         (val_3 = thunk_FUN_1000d510((int)pvStack_14,1), val_3 != 0)) {
        thunk_FUN_10037837(DAT_101cf538,DAT_101cfb80);
      }
    }
    if (pHStack_c == DAT_101cf33c) {
      thunk_FUN_1003a490();
      if (DAT_101cf542 != '\0') {
        thunk_FUN_10027a61(2,400,0,0);
      }
      DAT_1016a618 = 1;
      ScreenToClient(pHStack_c,(LPPOINT)&DAT_1013f190);
      _DAT_1013f190 = _DAT_1013f190 - iStack_28;
      _DAT_1013f194 = _DAT_1013f194 - iStack_8;
      for (iStack_2c = 0; iStack_2c < iStack_30; iStack_2c = iStack_2c + 1) {
        LVar4 = SendMessageA(pHStack_c,0x4c8,(WPARAM)pvStack_14,CONCAT22(DAT_1013f194,DAT_1013f190))
        ;
        if (LVar4 == 0) {
          MessageBeep(0);
        }
        thunk_FUN_1000d510((int)pvStack_14,2);
      }
      thunk_FUN_1000880b();
      if ((DAT_1017646c & 0x20) == 0) {
        SendMessageA(DAT_1016e4a8,0x400,(WPARAM)pvStack_14,0);
        SendMessageA(DAT_101cfb80,0x186,wParam,0);
        SendMessageA(DAT_101cf538,0x186,wParam,0);
      }
      else {
        SendMessageA(DAT_101cfb80,0x186,0,0);
        SendMessageA(DAT_101cf538,0x186,0,0);
      }
      if ((DAT_1017646c & 1) != 0) {
        SendMessageA(DAT_101cfb80,0x466,(WPARAM)pvStack_14,0);
      }
    }
    else if ((pHStack_c == DAT_101625ec) || (pHStack_c == DAT_10176850)) {
      if (DAT_101cf542 != '\0') {
        thunk_FUN_10027a61(2,400,0,0);
      }
      DAT_1016a618 = 1;
      ScreenToClient(pHStack_c,(LPPOINT)&DAT_1013f190);
      for (iStack_2c = 0; iStack_2c < iStack_30; iStack_2c = iStack_2c + 1) {
        LVar4 = SendMessageA(pHStack_c,0x4c8,(WPARAM)pvStack_14,CONCAT22(DAT_1013f194,DAT_1013f190))
        ;
        if (LVar4 == 0) {
          MessageBeep(0);
        }
      }
      if ((DAT_1017646c & 0x20) == 0) {
        SendMessageA(DAT_1016e4a8,0x400,(WPARAM)pvStack_14,0);
        SendMessageA(DAT_101cfb80,0x186,wParam,0);
        SendMessageA(DAT_101cf538,0x186,wParam,0);
      }
      else {
        SendMessageA(DAT_101cfb80,0x186,0,0);
        SendMessageA(DAT_101cf538,0x186,0,0);
      }
    }
    else if (pHStack_c == DAT_101cfb80) {
      for (iStack_2c = 0; iStack_2c < iStack_30; iStack_2c = iStack_2c + 1) {
        thunk_FUN_1000d510((int)pvStack_14,3);
      }
      thunk_FUN_1003798a(DAT_101cf538,DAT_101cfb80);
      SendMessageA(DAT_1016e4a8,0x400,(WPARAM)pvStack_14,0);
      SendMessageA(DAT_101cfb80,0x186,wParam,0);
      SendMessageA(DAT_101cf538,0x186,wParam,0);
      if ((DAT_1017646c & 1) != 0) {
        SendMessageA(DAT_101cfb80,0x466,(WPARAM)pvStack_14,0);
      }
    }
    else {
      for (iStack_2c = 0; iStack_2c < iStack_30; iStack_2c = iStack_2c + 1) {
        thunk_FUN_1000d510((int)pvStack_14,3);
      }
      thunk_FUN_1003798a(DAT_101cf538,DAT_101cfb80);
      SendMessageA(DAT_1016e4a8,0x400,(WPARAM)pvStack_14,0);
      SendMessageA(DAT_101cfb80,0x186,wParam,0);
      SendMessageA(DAT_101cf538,0x186,wParam,0);
      if ((DAT_1017646c & 1) != 0) {
        SendMessageA(DAT_101cfb80,0x466,(WPARAM)pvStack_14,0);
      }
    }
    thunk_FUN_10027036();
    uval_2 = 1;
  }
  return uval_2;
}



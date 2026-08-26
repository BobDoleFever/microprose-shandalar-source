/*
 * Decompiled function: FUN_10037c37
 * Entry Point: 10037c37
 * Size: 1807 bytes
 */
#include "deckdll.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int32_t FUN_10037c37(HWND hwnd,int arg_2,int arg_3)

{
  POINT pt;
  POINT Point;
  WPARAM wParam;
  BOOL BVar1;
  int32_t uval_2;
  int val_3;
  LRESULT LVar4;
  int local_30;
  int local_2c;
  int local_28;
  tagRECT local_24;
  LPVOID local_14;
  HWND local_10;
  HWND local_c;
  int local_8;
  
  wParam = SendMessageA(hwnd,0x188,0,0);
  local_14 = (LPVOID)SendMessageA(hwnd,0x199,wParam,0);
  thunk_FUN_100372c5(DAT_101cfb80,wParam,&local_24);
  pt.y = DAT_1013f17c;
  pt.x = DAT_1013f178;
  BVar1 = PtInRect(&local_24,pt);
  if (BVar1 == 0) {
    uval_2 = 0;
  }
  else {
    MapWindowPoints(DAT_101cfb80,DAT_10176868,(LPPOINT)&local_24,2);
    if (arg_2 == 1) {
      local_10 = CreateWindowExA(0,s_MAGICDECK_CardClass_1004bab0,&DAT_1004baa8,0x54000000,
                                 local_24.left,local_24.top,DAT_10175558,DAT_10176860,DAT_10176868,
                                 (HMENU)0x1,DAT_101cf334,local_14);
      if (local_10 == (HWND)0x0) {
        return 0;
      }
      BringWindowToTop(local_10);
      UpdateWindow(local_10);
      local_28 = _DAT_1013f190 - local_24.left;
      local_8 = _DAT_1013f194 - local_24.top;
      SendMessageA(local_10,0x112,0xf012,0);
      DestroyWindow(local_10);
      GetCursorPos((LPPOINT)&DAT_1013f190);
      Point.y = _DAT_1013f194;
      Point.x = _DAT_1013f190;
      for (local_c = WindowFromPoint(Point);
          ((((local_c != (HWND)0x0 && (DAT_10176868 != local_c)) && (local_c != DAT_101cf33c)) &&
           ((local_c != DAT_10176850 && (local_c != DAT_101625ec)))) && (local_c != DAT_101cfb80));
          local_c = GetParent(local_c)) {
      }
    }
    else {
      local_c = DAT_101cf33c;
    }
    if (arg_3 == 1) {
      if (((DAT_1017646c & 1) == 0) && ((DAT_1017646c & 0x20) == 0)) {
        thunk_FUN_1000ad0b();
        local_30 = DAT_10175ecc;
      }
      else {
        local_30 = thunk_FUN_1003724f((int)local_14);
        DAT_101cfb9c = local_30;
        val_3 = thunk_FUN_1000ad0b();
        if (val_3 == 0) {
          DAT_10175ecc = 0;
        }
        if (DAT_10175ecc < local_30) {
          local_30 = DAT_10175ecc;
        }
        for (local_2c = 0; local_2c < local_30; local_2c = local_2c + 1) {
          thunk_FUN_1000d510((int)local_14,1);
        }
        thunk_FUN_10037837(DAT_101cf538,DAT_101cfb80);
      }
    }
    else {
      local_30 = 1;
      if ((((DAT_1017646c & 1) != 0) || ((DAT_1017646c & 0x20) != 0)) &&
         (val_3 = thunk_FUN_1000d510((int)local_14,1), val_3 != 0)) {
        thunk_FUN_10037837(DAT_101cf538,DAT_101cfb80);
      }
    }
    if (local_c == DAT_101cf33c) {
      thunk_FUN_1003a490();
      if (DAT_101cf542 != '\0') {
        thunk_FUN_10027a61(2,400,0,0);
      }
      DAT_1016a618 = 1;
      ScreenToClient(local_c,(LPPOINT)&DAT_1013f190);
      _DAT_1013f190 = _DAT_1013f190 - local_28;
      _DAT_1013f194 = _DAT_1013f194 - local_8;
      for (local_2c = 0; local_2c < local_30; local_2c = local_2c + 1) {
        LVar4 = SendMessageA(local_c,0x4c8,(WPARAM)local_14,CONCAT22(DAT_1013f194,DAT_1013f190));
        if (LVar4 == 0) {
          MessageBeep(0);
        }
        thunk_FUN_1000d510((int)local_14,2);
      }
      thunk_FUN_1000880b();
      if ((DAT_1017646c & 0x20) == 0) {
        SendMessageA(DAT_1016e4a8,0x400,(WPARAM)local_14,0);
        SendMessageA(DAT_101cfb80,0x186,wParam,0);
        SendMessageA(DAT_101cf538,0x186,wParam,0);
      }
      else {
        SendMessageA(DAT_101cfb80,0x186,0,0);
        SendMessageA(DAT_101cf538,0x186,0,0);
      }
      if ((DAT_1017646c & 1) != 0) {
        SendMessageA(DAT_101cfb80,0x466,(WPARAM)local_14,0);
      }
    }
    else if ((local_c == DAT_101625ec) || (local_c == DAT_10176850)) {
      if (DAT_101cf542 != '\0') {
        thunk_FUN_10027a61(2,400,0,0);
      }
      DAT_1016a618 = 1;
      ScreenToClient(local_c,(LPPOINT)&DAT_1013f190);
      for (local_2c = 0; local_2c < local_30; local_2c = local_2c + 1) {
        LVar4 = SendMessageA(local_c,0x4c8,(WPARAM)local_14,CONCAT22(DAT_1013f194,DAT_1013f190));
        if (LVar4 == 0) {
          MessageBeep(0);
        }
      }
      if ((DAT_1017646c & 0x20) == 0) {
        SendMessageA(DAT_1016e4a8,0x400,(WPARAM)local_14,0);
        SendMessageA(DAT_101cfb80,0x186,wParam,0);
        SendMessageA(DAT_101cf538,0x186,wParam,0);
      }
      else {
        SendMessageA(DAT_101cfb80,0x186,0,0);
        SendMessageA(DAT_101cf538,0x186,0,0);
      }
    }
    else if (local_c == DAT_101cfb80) {
      for (local_2c = 0; local_2c < local_30; local_2c = local_2c + 1) {
        thunk_FUN_1000d510((int)local_14,3);
      }
      thunk_FUN_1003798a(DAT_101cf538,DAT_101cfb80);
      SendMessageA(DAT_1016e4a8,0x400,(WPARAM)local_14,0);
      SendMessageA(DAT_101cfb80,0x186,wParam,0);
      SendMessageA(DAT_101cf538,0x186,wParam,0);
      if ((DAT_1017646c & 1) != 0) {
        SendMessageA(DAT_101cfb80,0x466,(WPARAM)local_14,0);
      }
    }
    else {
      for (local_2c = 0; local_2c < local_30; local_2c = local_2c + 1) {
        thunk_FUN_1000d510((int)local_14,3);
      }
      thunk_FUN_1003798a(DAT_101cf538,DAT_101cfb80);
      SendMessageA(DAT_1016e4a8,0x400,(WPARAM)local_14,0);
      SendMessageA(DAT_101cfb80,0x186,wParam,0);
      SendMessageA(DAT_101cf538,0x186,wParam,0);
      if ((DAT_1017646c & 1) != 0) {
        SendMessageA(DAT_101cfb80,0x466,(WPARAM)local_14,0);
      }
    }
    thunk_FUN_10027036();
    uval_2 = 1;
  }
  return uval_2;
}



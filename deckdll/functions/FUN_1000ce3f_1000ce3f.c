/*
 * Decompiled function: FUN_1000ce3f
 * Entry Point: 1000ce3f
 * Size: 1745 bytes
 */
#include "deckdll.h"


void FUN_1000ce3f(HWND hwnd,int arg_2,int arg_3,int arg_4,int arg_5)

{
  POINT Point;
  WORD WVar1;
  int val_2;
  LRESULT LVar3;
  tagPOINT local_38;
  int local_30;
  int local_2c;
  HWND local_28;
  uint32_t local_24;
  HWND local_20;
  tagRECT local_1c;
  LPVOID local_c;
  HWND local_8;
  
  local_c = (LPVOID)GetWindowLongA(hwnd,0);
  WVar1 = GetWindowWord(hwnd,4);
  local_20 = GetParent(hwnd);
  local_30 = GetDlgCtrlID(hwnd);
  GetWindowRect(hwnd,&local_1c);
  if (1 < WVar1) {
    local_38.x = local_1c.left;
    local_38.y = local_1c.top;
    SendMessageA(hwnd,0x401,1,0);
    MapWindowPoints((HWND)0x0,local_20,&local_38,1);
    local_28 = CreateWindowExA(0,s_MAGICDECK_CardClass_10041448,&DAT_10041444,0x54000000,local_38.x,
                               local_38.y,DAT_10175558,DAT_10176860,local_20,(HMENU)0x1,DAT_101cf334
                               ,local_c);
    SendMessageA(local_28,0x401,WVar1 - 1,0);
    BringWindowToTop(local_28);
  }
  if (arg_5 == 1) {
    LockWindowUpdate(DAT_10176868);
    MapWindowPoints((HWND)0x0,DAT_10176868,(LPPOINT)&local_1c,2);
    MoveWindow(hwnd,local_1c.left,local_1c.top,0,0,1);
    SetParent(hwnd,DAT_10176868);
    MoveWindow(hwnd,local_1c.left,local_1c.top,local_1c.right - local_1c.left,
               local_1c.bottom - local_1c.top,1);
    BringWindowToTop(hwnd);
    LockWindowUpdate((HWND)0x0);
    SendMessageA(hwnd,0x112,0xf012,0);
    DestroyWindow(hwnd);
    GetCursorPos(&local_38);
    Point.y = local_38.y;
    Point.x = local_38.x;
    for (local_8 = WindowFromPoint(Point);
        ((((local_8 != (HWND)0x0 && (DAT_10176868 != local_8)) && (DAT_101cf33c != local_8)) &&
         ((DAT_10176850 != local_8 && (DAT_101625ec != local_8)))) && (DAT_101cfb80 != local_8));
        local_8 = GetParent(local_8)) {
    }
  }
  else {
    local_8 = DAT_101cfb80;
    DestroyWindow(hwnd);
    SetFocus(DAT_101cfb80);
  }
  local_24 = CONCAT22(local_24._2_2_,1);
  if (local_20 == DAT_101cf33c) {
    if (arg_4 < 2) {
      SendMessageA(local_28,0x401,WVar1 - 1,0);
      local_24 = CONCAT22(local_24._2_2_,1);
    }
    else {
      DAT_101cfb9c = (uint32_t)WVar1;
      val_2 = thunk_FUN_1000ad0b();
      if (val_2 == 0) {
        DAT_10175ecc = 0;
      }
      if (DAT_10175ecc < 1) {
        SendMessageA(local_28,0x401,(uint32_t)WVar1,0);
        local_24 = local_24 & 0xffff0000;
      }
      else if (DAT_10175ecc < (int)(uint32_t)WVar1) {
        SendMessageA(local_28,0x401,(uint32_t)WVar1 - DAT_10175ecc,0);
        local_24 = CONCAT22(local_24._2_2_,(short)DAT_10175ecc);
      }
      else {
        DestroyWindow(local_28);
        local_24 = CONCAT22(local_24._2_2_,WVar1);
      }
    }
    for (local_2c = 0; local_2c < (int)(local_24 & 0xffff); local_2c = local_2c + 1) {
      thunk_FUN_1000d510((int)local_c,0);
    }
    thunk_FUN_100395de((int)local_c,local_24 & 0xffff,0x101cded0);
    thunk_FUN_1000880b();
    thunk_FUN_10027036();
  }
  else if (DAT_10176850 == local_20) {
    thunk_FUN_100397d0(local_30,(int)local_c,1,0x101cded0);
  }
  else {
    thunk_FUN_10039a61(local_30,(int)local_c,1,0x101cded0);
  }
  if (DAT_101cf33c == local_8) {
    if (local_20 != local_8) {
      DAT_1016a618 = 1;
    }
    ScreenToClient(local_8,&local_38);
    local_38.x = local_38.x - arg_2;
    local_38.y = local_38.y - arg_3;
    for (local_2c = 0; local_2c < (int)(local_24 & 0xffff); local_2c = local_2c + 1) {
      LVar3 = SendMessageA(local_8,0x4c8,(WPARAM)local_c,local_38.y << 0x10 | local_38.x & 0xffffU);
      if (LVar3 == 0) {
        MessageBeep(0);
      }
      thunk_FUN_1000d510((int)local_c,2);
    }
    thunk_FUN_1000880b();
  }
  else if ((DAT_101625ec == local_8) || (DAT_10176850 == local_8)) {
    if (local_20 != local_8) {
      DAT_1016a618 = 1;
    }
    ScreenToClient(local_8,&local_38);
    if (DAT_101625ec == local_8) {
      local_24 = local_24 & 0xffff0000;
    }
    for (local_2c = 0; local_2c < (int)(local_24 & 0xffff); local_2c = local_2c + 1) {
      LVar3 = SendMessageA(local_8,0x4c8,(WPARAM)local_c,local_38.y << 0x10 | local_38.x & 0xffffU);
      if (LVar3 == 0) {
        MessageBeep(0);
      }
    }
  }
  else if (DAT_101cfb80 == local_8) {
    thunk_FUN_1003a490();
    if ((local_20 != local_8) && (DAT_1016a618 = 1, DAT_101cf542 != '\0')) {
      thunk_FUN_10027a61(3,400,0,0);
    }
    for (local_2c = 0; local_2c < (int)(local_24 & 0xffff); local_2c = local_2c + 1) {
      val_2 = thunk_FUN_1000d510((int)local_c,3);
      if (val_2 != 0) {
        thunk_FUN_1003798a(DAT_101cf538,DAT_101cfb80);
      }
    }
    if ((DAT_1017646c & 1) != 0) {
      SendMessageA(DAT_101cfb80,0x466,(WPARAM)local_c,0);
    }
  }
  else {
    ScreenToClient(local_8,&local_38);
    local_38.x = local_38.x - arg_2;
    local_38.y = local_38.y - arg_3;
    thunk_FUN_1000d510((int)local_c,2);
    for (local_2c = 0; local_2c < (int)(local_24 & 0xffff); local_2c = local_2c + 1) {
      LVar3 = SendMessageA(DAT_101cf33c,0x4c8,(WPARAM)local_c,
                           local_38.y << 0x10 | local_38.x & 0xffffU);
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



/*
 * Decompiled function: FUN_10018b75
 * Entry Point: 10018b75
 * Size: 1030 bytes
 */
#include "deckdll.h"


/* WARNING: Removing unreachable block (ram,0x10018bf9) */

uint32_t FUN_10018b75(HWND hwnd,uint32_t y,uint32_t width,uint32_t height)

{
  WORD WVar1;
  LRESULT LVar2;
  uint32_t uval_3;
  tagPOINT local_70;
  int32_t local_68;
  HDC local_64;
  tagPAINTSTRUCT local_60;
  tagRECT local_20;
  uint32_t local_10;
  uint32_t local_c;
  uint32_t local_8;
  
  if (y < 0x10) {
    if (y == 0xf) {
      local_8 = GetWindowLongA(hwnd,4);
      WVar1 = GetWindowWord(hwnd,8);
      local_c = (uint32_t)WVar1;
      local_64 = BeginPaint(hwnd,&local_60);
      GetClientRect(hwnd,&local_20);
      thunk_FUN_10031425(local_64);
      if ((int)local_8 < 0) {
        thunk_FUN_1001ad0b(local_64,&local_20);
      }
      else {
        FillRect(DAT_101625e8,&local_20,DAT_101cf91c);
        local_68 = thunk_FUN_1001ae07(DAT_101625e8,&local_20.left,
                                      (int32_t *)(&DAT_10176ab0 + local_8 * 0x98),0,1,local_c);
        BitBlt(local_64,0,0,local_20.right,local_20.bottom,DAT_101625e8,0,0,0xcc0020);
      }
      EndPaint(hwnd,&local_60);
      return 0;
    }
    if (y == 1) {
      DAT_1013dfe0 = CreatePopupMenu();
      AppendMenuA(DAT_1013dfe0,0,0xfa1,s__Show_full_card_text_100432f0);
      local_8 = 0xffffffff;
      SetWindowLongA(hwnd,4,-1);
      local_c = (uint32_t)DAT_101cf5e3;
      SetWindowWord(hwnd,8,(short)DAT_101cf5e3);
      CheckMenuItem(DAT_1013dfe0,0xfa1,(local_c == 0) - 1 & 8);
      return 0;
    }
    if (y == 2) {
      WVar1 = GetWindowWord(hwnd,8);
      DAT_101cf5e3 = (char)WVar1;
      DestroyMenu(DAT_1013dfe0);
      return 0;
    }
  }
  else if (y < 0x205) {
    if (y == 0x204) {
      local_70.x = height & 0xffff;
      local_70.y = height >> 0x10;
      ClientToScreen(hwnd,&local_70);
      TrackPopupMenu(DAT_1013dfe0,2,local_70.x,local_70.y,0,hwnd,(RECT *)0x0);
      return 0;
    }
    if (y == 0x111) {
      if ((width & 0xffff) == 0xfa1) {
        LVar2 = SendMessageA(hwnd,0x402,0,0);
        if (LVar2 == 0) {
          SendMessageA(hwnd,0x401,1,0);
        }
        else {
          SendMessageA(hwnd,0x401,0,0);
        }
      }
      return 0;
    }
  }
  else {
    switch(y) {
    case 0x400:
      local_8 = width;
      uval_3 = GetWindowLongA(hwnd,4);
      if (uval_3 != local_8) {
        SetWindowLongA(hwnd,4,local_8);
        InvalidateRect(hwnd,(RECT *)0x0,0);
      }
      return 0;
    case 0x401:
      local_c = width;
      SetWindowWord(hwnd,8,(WORD)width);
      InvalidateRect(hwnd,(RECT *)0x0,0);
      CheckMenuItem(DAT_1013dfe0,0xfa1,(local_c == 0) - 1 & 8);
      return local_c;
    case 0x402:
      WVar1 = GetWindowWord(hwnd,8);
      return (uint32_t)WVar1;
    case 0x466:
      local_10 = width;
      local_8 = GetWindowLongA(hwnd,4);
      if (local_10 == local_8) {
        InvalidateRect(hwnd,(RECT *)0x0,0);
      }
      return 0;
    }
  }
  uval_3 = DefWindowProcA(hwnd,y,width,height);
  return uval_3;
}



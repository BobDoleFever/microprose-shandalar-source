/*
 * Decompiled function: FUN_100129a2
 * Entry Point: 100129a2
 * Size: 78 bytes
 */
#include "deckdll.h"


int32_t FUN_100129a2(LPCSTR str_1,HWND hwnd)

{
  MessageBoxA(hwnd,str_1,(LPCSTR)0x0,0x1010);
  if (hwnd == (HWND)0x0) {
    PostQuitMessage(1);
  }
  else {
    SendMessageA(hwnd,0x10,0,0);
  }
  return 0;
}



/*
 * Decompiled function: Duel_UpdateWindowScroll
 * Entry Point: 004eed47
 * Size: 263 bytes
 */
#include "magic.h"


void Duel_UpdateWindowScroll(HWND hwnd)

{
  LONG LVar1;
  LONG LVar2;
  int local_20;
  tagRECT local_18;
  HWND local_8;
  
  GetClientRect(hwnd,&local_18);
  LVar1 = GetWindowLongA(hwnd,4);
  LVar2 = GetWindowLongA(hwnd,0);
  local_8 = (HWND)GetWindowLongA(hwnd,0xc);
  for (local_20 = 0; local_20 < LVar1; local_20 = local_20 + 1) {
    SetWindowPos(*(HWND *)(LVar2 + local_20 * 4),(HWND)0x0,0,0,DAT_006a28b0,DAT_006b2e30,6);
  }
  for (local_20 = 0; local_20 < LVar1; local_20 = local_20 + 1) {
    SendMessageA(hwnd,0x410,*(WPARAM *)(LVar2 + local_20 * 4),0);
  }
  SetWindowPos(local_8,(HWND)0x0,0,0,DAT_006a28b0,DAT_006b2e30,6);
  SendMessageA(hwnd,0x410,(WPARAM)local_8,0);
  return;
}



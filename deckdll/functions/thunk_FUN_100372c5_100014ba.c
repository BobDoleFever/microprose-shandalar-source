/*
 * Decompiled function: thunk_FUN_100372c5
 * Entry Point: 100014ba
 * Size: 5 bytes
 */
#include "deckdll.h"


int32_t thunk_FUN_100372c5(HWND hwnd,int arg_2,LPRECT arg_3)

{
  WORD WVar1;
  WORD WVar2;
  WORD WVar3;
  int32_t uval_4;
  tagRECT tStack_14;
  
  WVar1 = GetWindowWord(hwnd,10);
  WVar2 = GetWindowWord(hwnd,8);
  WVar3 = GetWindowWord(hwnd,0xc);
  GetClientRect(hwnd,&tStack_14);
  SetRect(arg_3,(arg_2 - (uint32_t)WVar2) * (uint32_t)WVar1 + tStack_14.left,tStack_14.top,
          ((arg_2 - (uint32_t)WVar2) + 1) * (uint32_t)WVar1 + tStack_14.left,tStack_14.bottom);
  if ((arg_2 < (int)(uint32_t)WVar2) || ((int)((uint32_t)WVar3 + (uint32_t)WVar2) < arg_2)) {
    uval_4 = 0;
  }
  else {
    uval_4 = 1;
  }
  return uval_4;
}



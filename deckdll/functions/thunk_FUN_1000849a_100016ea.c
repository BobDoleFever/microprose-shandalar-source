/*
 * Decompiled function: thunk_FUN_1000849a
 * Entry Point: 100016ea
 * Size: 5 bytes
 */
#include "deckdll.h"


void thunk_FUN_1000849a(HWND hwnd)

{
  HWND hWnd;
  
  while( true ) {
    hWnd = GetTopWindow(hwnd);
    if (hWnd == (HWND)0x0) break;
    DestroyWindow(hWnd);
  }
  return;
}



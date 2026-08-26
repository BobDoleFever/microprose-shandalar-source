/*
 * Decompiled function: FUN_1000849a
 * Entry Point: 1000849a
 * Size: 52 bytes
 */
#include "deckdll.h"


void FUN_1000849a(HWND hwnd)

{
  HWND hWnd;
  
  while( true ) {
    hWnd = GetTopWindow(hwnd);
    if (hWnd == (HWND)0x0) break;
    DestroyWindow(hWnd);
  }
  return;
}



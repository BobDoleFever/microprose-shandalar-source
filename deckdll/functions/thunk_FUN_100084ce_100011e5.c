/*
 * Decompiled function: thunk_FUN_100084ce
 * Entry Point: 100011e5
 * Size: 5 bytes
 */
#include "deckdll.h"


void thunk_FUN_100084ce(HWND hwnd)

{
  int32_t uStack_8;
  
  for (uStack_8 = GetTopWindow(hwnd); uStack_8 != (HWND)0x0; uStack_8 = GetWindow(uStack_8,2)) {
    SetWindowPos(uStack_8,(HWND)0x0,0,0,DAT_10175558,DAT_10176860,6);
  }
  return;
}



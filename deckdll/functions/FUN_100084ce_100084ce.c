/*
 * Decompiled function: FUN_100084ce
 * Entry Point: 100084ce
 * Size: 92 bytes
 */
#include "deckdll.h"


void FUN_100084ce(HWND hwnd)

{
  int32_t local_8;
  
  for (local_8 = GetTopWindow(hwnd); local_8 != (HWND)0x0; local_8 = GetWindow(local_8,2)) {
    SetWindowPos(local_8,(HWND)0x0,0,0,DAT_10175558,DAT_10176860,6);
  }
  return;
}



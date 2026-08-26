/*
 * Decompiled function: thunk_FUN_1000852a
 * Entry Point: 10001442
 * Size: 5 bytes
 */
#include "deckdll.h"


void thunk_FUN_1000852a(HWND hwnd,int *arg2)

{
  int val_1;
  int val_2;
  HWND pHStack_1c;
  HWND pHStack_14;
  int iStack_c;
  int iStack_8;
  
  val_1 = DAT_10176860 * 0x12;
  val_2 = DAT_10176860 / 10;
  iStack_8 = *arg2 + val_2;
  iStack_c = arg2[1] + val_2;
  pHStack_1c = (HWND)0x0;
  for (pHStack_14 = GetTopWindow(hwnd); pHStack_14 != (HWND)0x0;
      pHStack_14 = GetWindow(pHStack_14,2)) {
    pHStack_1c = pHStack_14;
  }
  for (pHStack_14 = pHStack_1c; pHStack_14 != (HWND)0x0; pHStack_14 = GetWindow(pHStack_14,3)) {
    if (arg2[3] < DAT_10176860 + iStack_c) {
      iStack_8 = iStack_8 + DAT_10175558 + 8;
      iStack_c = arg2[1] + val_2;
    }
    SetWindowPos(pHStack_14,(HWND)0x0,iStack_8,iStack_c,DAT_10175558,DAT_10176860,4);
    iStack_c = iStack_c + val_1 / 100;
  }
  return;
}



/*
 * Decompiled function: thunk_FUN_100315fc
 * Entry Point: 10001267
 * Size: 5 bytes
 */
#include "deckdll.h"


void thunk_FUN_100315fc(HDC hdc,HGDIOBJ arg2)

{
  if (hdc != (HDC)0x0) {
    DeleteDC(hdc);
  }
  if (arg2 != (HGDIOBJ)0x0) {
    DeleteObject(arg2);
  }
  return;
}



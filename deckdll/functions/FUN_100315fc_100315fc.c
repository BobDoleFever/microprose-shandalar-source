/*
 * Decompiled function: FUN_100315fc
 * Entry Point: 100315fc
 * Size: 51 bytes
 */
#include "deckdll.h"


void FUN_100315fc(HDC hdc,HGDIOBJ arg2)

{
  if (hdc != (HDC)0x0) {
    DeleteDC(hdc);
  }
  if (arg2 != (HGDIOBJ)0x0) {
    DeleteObject(arg2);
  }
  return;
}



/*
 * Decompiled function: thunk_FUN_10031425
 * Entry Point: 10001113
 * Size: 5 bytes
 */
#include "deckdll.h"


void thunk_FUN_10031425(HDC hdc)

{
  SelectPalette(hdc,DAT_10140990,0);
  RealizePalette(hdc);
  GdiFlush();
  SetDIBColorTable(hdc,0,0x100,(RGBQUAD *)&DAT_10175f10);
  SetStretchBltMode(hdc,3);
  return;
}



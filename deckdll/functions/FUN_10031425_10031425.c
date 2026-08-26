/*
 * Decompiled function: FUN_10031425
 * Entry Point: 10031425
 * Size: 79 bytes
 */
#include "deckdll.h"


void FUN_10031425(HDC hdc)

{
  SelectPalette(hdc,DAT_10140990,0);
  RealizePalette(hdc);
  GdiFlush();
  SetDIBColorTable(hdc,0,0x100,(RGBQUAD *)&DAT_10175f10);
  SetStretchBltMode(hdc,3);
  return;
}



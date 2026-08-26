/*
 * Decompiled function: FUN_004707a4
 * Entry Point: 004707a4
 * Size: 79 bytes
 */
#include "duel.h"


void FUN_004707a4(HDC hdc)

{
  SelectPalette(hdc,DAT_005f76d0,0);
  RealizePalette(hdc);
  GdiFlush();
  SetDIBColorTable(hdc,0,0x100,(RGBQUAD *)&DAT_00617580);
  SetStretchBltMode(hdc,3);
  return;
}



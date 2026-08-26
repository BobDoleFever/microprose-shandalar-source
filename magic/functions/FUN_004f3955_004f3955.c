/*
 * Decompiled function: FUN_004f3955
 * Entry Point: 004f3955
 * Size: 79 bytes
 */
#include "magic.h"


void FUN_004f3955(HDC hdc)

{
  SelectPalette(hdc,DAT_00680774,0);
  RealizePalette(hdc);
  GdiFlush();
  SetDIBColorTable(hdc,0,0x100,(RGBQUAD *)&DAT_006a4b70);
  SetStretchBltMode(hdc,3);
  return;
}



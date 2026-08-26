/*
 * Decompiled function: Pic_Load_advfac64_0040a4fc
 * Entry Point: 0040a4fc
 * Size: 106 bytes
 */
#include "magic.h"


undefined4 Pic_Load_advfac64_0040a4fc(void)

{
  SetFocus(_hwndScreen);
  LoadPalNoPic(s_advfac64_pic_005171e4);
  Catalog_LoadPaletteMap(s_todpal_tr_005171f4,(char *)0x0);
  SelectPalette(*(HDC *)(DAT_0070a850 + 4),_hLibPal,0);
  RealizePalette(*(HDC *)(DAT_0070a850 + 4));
  FUN_0040a566();
  FUN_0040a3e1();
  return 0;
}



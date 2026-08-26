/*
 * Decompiled function: Adventure_LoadFacePalette
 * Entry Point: 004eadb7
 * Size: 46 bytes
 */
#include "magic.h"


void Adventure_LoadFacePalette(int arg_1)

{
  if (arg_1 != DAT_005659b4) {
    LoadPalNoPic(s_advfac64_pic_0052f500);
    DAT_005659b4 = arg_1;
  }
  return;
}



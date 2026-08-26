/*
 * Decompiled function: Palette_Subsystem_004997b8
 * Entry Point: 004997b8
 * Size: 46 bytes
 */
#include "magic.h"


void Palette_Subsystem_004997b8(void)

{
  if (DAT_0054b360 != (HMENU)0x0) {
    DestroyMenu(DAT_0054b360);
  }
  DAT_0054b360 = (HMENU)0x0;
  return;
}



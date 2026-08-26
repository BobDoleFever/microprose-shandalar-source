/*
 * Decompiled function: Pic_Subsystem_0044ba83
 * Entry Point: 0044ba83
 * Size: 81 bytes
 */
#include "magic.h"


void Pic_Subsystem_0044ba83(void)

{
  if (DAT_00538bf8 != (HMENU)0x0) {
    DestroyMenu(DAT_00538bf8);
  }
  DAT_00538bf8 = (HMENU)0x0;
  if (DAT_00538bfc != (HGDIOBJ)0x0) {
    DeleteObject(DAT_00538bfc);
  }
  DAT_00538bfc = (HGDIOBJ)0x0;
  return;
}



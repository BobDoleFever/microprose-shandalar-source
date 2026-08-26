/*
 * Decompiled function: Pic_Subsystem_004249a8
 * Entry Point: 004249a8
 * Size: 118 bytes
 */
#include "magic.h"


void Pic_Subsystem_004249a8(void)

{
  if (DAT_00538b40 != (HMENU)0x0) {
    DestroyMenu(DAT_00538b40);
  }
  DAT_00538b40 = (HMENU)0x0;
  if (DAT_00538b20 != (HANDLE)0x0) {
    FUN_004f4548(DAT_00538b20);
  }
  if (DAT_00538b3c != (HGDIOBJ)0x0) {
    DeleteObject(DAT_00538b3c);
  }
  DAT_00538b20 = (HANDLE)0x0;
  DAT_00538b3c = (HGDIOBJ)0x0;
  return;
}



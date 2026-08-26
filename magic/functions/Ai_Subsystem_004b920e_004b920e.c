/*
 * Decompiled function: Ai_Subsystem_004b920e
 * Entry Point: 004b920e
 * Size: 118 bytes
 */
#include "magic.h"


void Ai_Subsystem_004b920e(void)

{
  if (DAT_00556b18 != (HMENU)0x0) {
    DestroyMenu(DAT_00556b18);
  }
  DAT_00556b18 = (HMENU)0x0;
  if (DAT_00556b20 != (HANDLE)0x0) {
    FUN_004f4548(DAT_00556b20);
  }
  DAT_00556b20 = (HANDLE)0x0;
  if (DAT_00556b1c != (HGDIOBJ)0x0) {
    DeleteObject(DAT_00556b1c);
  }
  DAT_00556b1c = (HGDIOBJ)0x0;
  return;
}



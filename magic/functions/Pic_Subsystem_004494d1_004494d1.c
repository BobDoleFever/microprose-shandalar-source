/*
 * Decompiled function: Pic_Subsystem_004494d1
 * Entry Point: 004494d1
 * Size: 46 bytes
 */
#include "magic.h"


void Pic_Subsystem_004494d1(void)

{
  if (DAT_00538bcc != (HMENU)0x0) {
    DestroyMenu(DAT_00538bcc);
  }
  DAT_00538bcc = (HMENU)0x0;
  return;
}



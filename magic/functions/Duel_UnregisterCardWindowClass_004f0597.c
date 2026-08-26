/*
 * Decompiled function: Duel_UnregisterCardWindowClass
 * Entry Point: 004f0597
 * Size: 46 bytes
 */
#include "magic.h"


void Duel_UnregisterCardWindowClass(void)

{
  if (DAT_00565a04 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_00565a04);
  }
  DAT_00565a04 = (HGDIOBJ)0x0;
  return;
}



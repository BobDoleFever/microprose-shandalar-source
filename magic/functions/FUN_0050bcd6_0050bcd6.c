/*
 * Decompiled function: FUN_0050bcd6
 * Entry Point: 0050bcd6
 * Size: 81 bytes
 */
#include "magic.h"


void FUN_0050bcd6(void)

{
  if (DAT_0061e118 != (HMENU)0x0) {
    DestroyMenu(DAT_0061e118);
  }
  if (DAT_0061e11c != (HMENU)0x0) {
    DestroyMenu(DAT_0061e11c);
  }
  DAT_0061e118 = (HMENU)0x0;
  DAT_0061e11c = (HMENU)0x0;
  return;
}



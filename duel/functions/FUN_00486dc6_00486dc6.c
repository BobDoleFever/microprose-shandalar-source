/*
 * Decompiled function: FUN_00486dc6
 * Entry Point: 00486dc6
 * Size: 81 bytes
 */
#include "duel.h"


void FUN_00486dc6(void)

{
  if (DAT_005dadec != (HMENU)0x0) {
    DestroyMenu(DAT_005dadec);
  }
  if (DAT_005dadf0 != (HMENU)0x0) {
    DestroyMenu(DAT_005dadf0);
  }
  DAT_005dadec = (HMENU)0x0;
  DAT_005dadf0 = (HMENU)0x0;
  return;
}



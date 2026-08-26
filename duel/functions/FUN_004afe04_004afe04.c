/*
 * Decompiled function: FUN_004afe04
 * Entry Point: 004afe04
 * Size: 81 bytes
 */
#include "duel.h"


void FUN_004afe04(void)

{
  if (DAT_005dcd98 != (HMENU)0x0) {
    DestroyMenu(DAT_005dcd98);
  }
  if (DAT_005dcd80 != (HMENU)0x0) {
    DestroyMenu(DAT_005dcd80);
  }
  DAT_005dcd98 = (HMENU)0x0;
  DAT_005dcd80 = (HMENU)0x0;
  return;
}



/*
 * Decompiled function: FUN_004b9523
 * Entry Point: 004b9523
 * Size: 81 bytes
 */
#include "duel.h"


void FUN_004b9523(void)

{
  if (DAT_005dce04 != (HMENU)0x0) {
    DestroyMenu(DAT_005dce04);
  }
  DAT_005dce04 = (HMENU)0x0;
  if (DAT_005dce08 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_005dce08);
  }
  DAT_005dce08 = (HGDIOBJ)0x0;
  return;
}



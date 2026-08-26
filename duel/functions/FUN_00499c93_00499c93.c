/*
 * Decompiled function: FUN_00499c93
 * Entry Point: 00499c93
 * Size: 118 bytes
 */
#include "duel.h"


void FUN_00499c93(void)

{
  if (DAT_005dcaf8 != (HMENU)0x0) {
    DestroyMenu(DAT_005dcaf8);
  }
  DAT_005dcaf8 = (HMENU)0x0;
  if (DAT_005dcaf4 != (HANDLE)0x0) {
    FUN_00471395(DAT_005dcaf4);
  }
  DAT_005dcaf4 = (HANDLE)0x0;
  if (DAT_005dcaf0 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_005dcaf0);
  }
  DAT_005dcaf0 = (HGDIOBJ)0x0;
  return;
}



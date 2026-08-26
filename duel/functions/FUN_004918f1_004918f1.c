/*
 * Decompiled function: FUN_004918f1
 * Entry Point: 004918f1
 * Size: 153 bytes
 */
#include "duel.h"


void FUN_004918f1(void)

{
  if (DAT_00618974 != 0) {
    KillTimer((HWND)0x0,DAT_00618974);
    DAT_00618974 = 0;
  }
  if (DAT_005daf04 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_005daf04);
  }
  if (DAT_005daf10 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_005daf10);
  }
  if (DAT_005daf0c != (HGDIOBJ)0x0) {
    DeleteObject(DAT_005daf0c);
  }
  DAT_005daf04 = (HGDIOBJ)0x0;
  DAT_005daf10 = (HGDIOBJ)0x0;
  DAT_005daf0c = (HGDIOBJ)0x0;
  return;
}



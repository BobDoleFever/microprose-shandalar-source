/*
 * Decompiled function: FUN_004082d1
 * Entry Point: 004082d1
 * Size: 153 bytes
 */
#include "magic.h"


void FUN_004082d1(void)

{
  if (DAT_006b2d8c != 0) {
    KillTimer((HWND)0x0,DAT_006b2d8c);
    DAT_006b2d8c = 0;
  }
  if (DAT_005382dc != (HGDIOBJ)0x0) {
    DeleteObject(DAT_005382dc);
  }
  if (DAT_005382e8 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_005382e8);
  }
  if (DAT_005382e4 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_005382e4);
  }
  DAT_005382dc = (HGDIOBJ)0x0;
  DAT_005382e8 = (HGDIOBJ)0x0;
  DAT_005382e4 = (HGDIOBJ)0x0;
  return;
}



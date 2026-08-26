/*
 * Decompiled function: FUN_0047072d
 * Entry Point: 0047072d
 * Size: 65 bytes
 */
#include "duel.h"


void FUN_0047072d(void)

{
  if (DAT_004f9780 != (HDC)0x0) {
    FUN_0047097b(DAT_004f9780,DAT_00522460);
    DAT_004f9780 = (HDC)0x0;
    DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_005224a8);
  }
  return;
}



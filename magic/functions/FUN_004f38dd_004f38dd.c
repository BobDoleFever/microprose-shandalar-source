/*
 * Decompiled function: FUN_004f38dd
 * Entry Point: 004f38dd
 * Size: 65 bytes
 */
#include "magic.h"


void FUN_004f38dd(void)

{
  if (DAT_00530180 != (HDC)0x0) {
    FUN_004f3b2c(DAT_00530180,DAT_0061d7f0);
    DAT_00530180 = (HDC)0x0;
    DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_0061d838);
  }
  return;
}



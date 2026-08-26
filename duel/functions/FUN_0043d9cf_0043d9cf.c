/*
 * Decompiled function: FUN_0043d9cf
 * Entry Point: 0043d9cf
 * Size: 118 bytes
 */
#include "duel.h"


void FUN_0043d9cf(void)

{
  if (DAT_004f79a4 != 0) {
    DAT_004f79a4 = 0;
    if ((DAT_004f79a8 != 0) && (DAT_004f79a0 == 0)) {
      (*DAT_006944d4)();
    }
    FreeLibrary(DAT_006944c8);
    FUN_0043e09c();
    DAT_006944c8 = (HMODULE)0x0;
    DAT_004f79a0 = 0;
    DAT_004f79a8 = 0;
  }
  return;
}



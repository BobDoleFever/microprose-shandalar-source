/*
 * Decompiled function: thunk_FUN_1000160f
 * Entry Point: 1000120d
 * Size: 5 bytes
 */
#include "statwin.h"


void thunk_FUN_1000160f(void)

{
  if (DAT_10011524 != 0) {
    DAT_10011524 = 0;
    if ((DAT_10011528 != 0) && (DAT_10011520 == 0)) {
      (*DAT_1001e8a4)();
    }
    FreeLibrary(DAT_1001e87c);
    thunk_FUN_10001cdc();
    DAT_1001e87c = (HMODULE)0x0;
    DAT_10011520 = 0;
    DAT_10011528 = 0;
  }
  return;
}



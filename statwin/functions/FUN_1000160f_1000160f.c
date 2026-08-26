/*
 * Decompiled function: StatWin_FreeSoundDll
 * Entry Point: 1000160f
 * Size: 118 bytes
 */
#include "statwin.h"


void StatWin_FreeSoundDll(void)

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



/*
 * Decompiled function: FUN_1003b411
 * Entry Point: 1003b411
 * Size: 118 bytes
 */
#include "deckdll.h"


void FUN_1003b411(void)

{
  if (DAT_1004bb90 != 0) {
    DAT_1004bb90 = 0;
    if ((DAT_1004bb94 != 0) && (DAT_1004bb8c == 0)) {
      (*DAT_1013ee94)();
    }
    FreeLibrary(DAT_1013ee64);
    thunk_FUN_1003bade();
    DAT_1013ee64 = (HMODULE)0x0;
    DAT_1004bb8c = 0;
    DAT_1004bb94 = 0;
  }
  return;
}



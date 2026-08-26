/*
 * Decompiled function: thunk_FUN_10004def
 * Entry Point: 1000133e
 * Size: 5 bytes
 */
#include "magvid.h"


void thunk_FUN_10004def(void)

{
  if (DAT_10010584 != 0) {
    DAT_10010584 = 0;
    if ((DAT_10010588 != 0) && (DAT_10010580 == 0)) {
      (*DAT_10032c74)();
    }
    FreeLibrary(DAT_10032c44);
    thunk_FUN_100054bc();
    DAT_10032c44 = (HMODULE)0x0;
    DAT_10010580 = 0;
    DAT_10010588 = 0;
  }
  return;
}



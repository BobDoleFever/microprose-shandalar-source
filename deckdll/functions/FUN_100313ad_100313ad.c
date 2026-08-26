/*
 * Decompiled function: FUN_100313ad
 * Entry Point: 100313ad
 * Size: 65 bytes
 */
#include "deckdll.h"


void FUN_100313ad(void)

{
  if (DAT_10046630 != (HDC)0x0) {
    thunk_FUN_100315fc(DAT_10046630,DAT_1013eb30);
    DAT_10046630 = (HDC)0x0;
    DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_1013eb78);
  }
  return;
}



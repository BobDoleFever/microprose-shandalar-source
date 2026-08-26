/*
 * Decompiled function: thunk_FUN_10031350
 * Entry Point: 10001258
 * Size: 5 bytes
 */
#include "deckdll.h"


bool thunk_FUN_10031350(void)

{
  if (DAT_10046630 == 0) {
    thunk_FUN_10031474(10,10,&DAT_10046630,(BITMAPINFO *)0x0,&DAT_1013eb30,(int32_t *)0x0,
                       (int *)0x0);
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_1013eb78);
  }
  return DAT_10046630 != 0;
}



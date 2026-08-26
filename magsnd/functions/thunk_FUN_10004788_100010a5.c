/*
 * Decompiled function: thunk_FUN_10004788
 * Entry Point: 100010a5
 * Size: 5 bytes
 */
#include "magsnd.h"


void thunk_FUN_10004788(void)

{
  if (DAT_1000a424 != 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
    timeKillEvent(DAT_1000ba94);
    DAT_1000ba94 = 0;
    timeEndPeriod(DAT_1000a480);
    DAT_1000a424 = 0;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
  }
  return;
}



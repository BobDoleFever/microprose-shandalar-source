/*
 * Decompiled function: FUN_10004788
 * Entry Point: 10004788
 * Size: 95 bytes
 */
#include "magsnd.h"


void FUN_10004788(void)

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



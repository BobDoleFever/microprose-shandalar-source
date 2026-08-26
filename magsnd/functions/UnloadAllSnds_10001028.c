/*
 * Decompiled function: UnloadAllSnds
 * Entry Point: 10001028
 * Size: 5 bytes
 */
#include "magsnd.h"


int32_t UnloadAllSnds(void)

{
                    /* 0x1028  5  UnloadAllSnds */
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
  while (DAT_1000a410 != 0) {
    UnloadSnd(*(int *)(DAT_1000a410 + 0x10));
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
  return 0;
}



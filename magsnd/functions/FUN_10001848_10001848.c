/*
 * Decompiled function: Sound_UnlockAudioBuffer
 * Entry Point: 10001848
 * Size: 75 bytes
 */
#include "magsnd.h"


int32_t Sound_UnlockAudioBuffer(void)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
  while (DAT_1000a410 != 0) {
    UnloadSnd(*(int *)(DAT_1000a410 + 0x10));
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
  return 0;
}



/*
 * Decompiled function: Sound_SetMasterVolume
 * Entry Point: 100028a5
 * Size: 91 bytes
 */
#include "magsnd.h"


void Sound_SetMasterVolume(void)

{
  int local_8;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
  for (local_8 = DAT_1000a410; local_8 != 0; local_8 = *(int *)(local_8 + 0x200)) {
    StopSnd(*(int *)(local_8 + 0x10));
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
  return;
}



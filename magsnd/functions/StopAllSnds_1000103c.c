/*
 * Decompiled function: StopAllSnds
 * Entry Point: 1000103c
 * Size: 5 bytes
 */
#include "magsnd.h"


void StopAllSnds(void)

{
  int iStack_8;
  
                    /* 0x103c  9  StopAllSnds */
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
  for (iStack_8 = DAT_1000a410; iStack_8 != 0; iStack_8 = *(int *)(iStack_8 + 0x200)) {
    StopSnd(*(int *)(iStack_8 + 0x10));
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
  return;
}



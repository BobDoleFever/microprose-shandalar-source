/*
 * Decompiled function: FUN_10003450
 * Entry Point: 10003450
 * Size: 142 bytes
 */
#include "magsnd.h"


int32_t __cdecl FUN_10003450(int arg1,int32_t *arg2)

{
  int local_8;
  
  if (0 < arg1) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
    for (local_8 = DAT_1000a410; local_8 != 0; local_8 = *(int *)(local_8 + 0x200)) {
      if (*(int *)(local_8 + 0x14) == arg1) {
        *arg2 = *(int32_t *)(local_8 + 0x10);
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
        return 1;
      }
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
  }
  return 0;
}



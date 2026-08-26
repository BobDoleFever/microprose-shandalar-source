/*
 * Decompiled function: IsSndLoaded
 * Entry Point: 100010cd
 * Size: 5 bytes
 */
#include "magsnd.h"


int32_t __cdecl IsSndLoaded(int arg1,int32_t *arg2)

{
  int iStack_8;
  
                    /* 0x10cd  26  IsSndLoaded */
  if (0 < arg1) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
    for (iStack_8 = DAT_1000a410; iStack_8 != 0; iStack_8 = *(int *)(iStack_8 + 0x200)) {
      if (*(int *)(iStack_8 + 0x14) == arg1) {
        *arg2 = *(int32_t *)(iStack_8 + 0x10);
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
        return 1;
      }
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
  }
  return 0;
}



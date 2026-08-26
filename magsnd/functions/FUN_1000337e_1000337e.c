/*
 * Decompiled function: FUN_1000337e
 * Entry Point: 1000337e
 * Size: 192 bytes
 */
#include "magsnd.h"


int32_t __cdecl FUN_1000337e(int arg1,int32_t *arg2)

{
  int32_t uval_1;
  
  if ((arg1 < 0x110) && (-1 < arg1)) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
    if (*(int *)(&DAT_1000a648 + arg1 * 4) == 0) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
      uval_1 = 1;
    }
    else {
      if ((*(uint8_t *)(*(int *)(&DAT_1000a648 + arg1 * 4) + 4) & 1) == 0) {
        if ((*(uint32_t *)(*(int *)(&DAT_1000a648 + arg1 * 4) + 4) >> 3 & 1) == 0) {
          *arg2 = 0;
        }
        else {
          *arg2 = 2;
        }
      }
      else {
        *arg2 = 1;
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
      uval_1 = 0;
    }
  }
  else {
    uval_1 = 5;
  }
  return uval_1;
}



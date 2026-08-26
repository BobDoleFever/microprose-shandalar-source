/*
 * Decompiled function: Sound_LockAudioBuffer
 * Entry Point: 100016e4
 * Size: 356 bytes
 */
#include "magsnd.h"


int32_t __cdecl Sound_LockAudioBuffer(int arg_1)

{
  int32_t uval_1;
  uint32_t local_8;
  
  if ((arg_1 < 0x110) && (-1 < arg_1)) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
    if (*(int *)(&DAT_1000a648 + arg_1 * 4) == 0) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
      uval_1 = 1;
    }
    else {
      thunk_FUN_10002900(arg_1);
      thunk_FUN_10004665(*(int *)(&DAT_1000a648 + arg_1 * 4));
      if ((*(uint32_t *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 8) >> 1 & 1) != 0) {
        thunk_FUN_1000458d(*(int *)(&DAT_1000a648 + arg_1 * 4));
        if ((*(uint32_t *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 8) >> 5 & 1) == 0) {
          thunk_FUN_10005a46(*(int32_t **)(&DAT_1000a648 + arg_1 * 4));
          for (local_8 = 0; local_8 < *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 0x30);
              local_8 = local_8 + 1) {
            if (*(int *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 0x38 + local_8 * 4) != 0) {
              thunk_FUN_10005a46(*(int32_t **)
                                  (*(int *)(&DAT_1000a648 + arg_1 * 4) + 0x38 + local_8 * 4));
            }
          }
        }
      }
      thunk_FUN_10006622(*(void **)(&DAT_1000a648 + arg_1 * 4));
      *(int32_t *)(&DAT_1000a648 + arg_1 * 4) = 0;
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
      uval_1 = 0;
    }
  }
  else {
    uval_1 = 5;
  }
  return uval_1;
}



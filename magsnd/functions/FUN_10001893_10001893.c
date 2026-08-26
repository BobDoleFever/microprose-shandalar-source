/*
 * Decompiled function: Sound_SetChannelVolume
 * Entry Point: 10001893
 * Size: 153 bytes
 */
#include "magsnd.h"


int32_t __cdecl Sound_SetChannelVolume(int arg1,int *arg2)

{
  int32_t uval_1;
  
  if ((arg1 < 0x110) && (-1 < arg1)) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
    if (*(int *)(&DAT_1000a648 + arg1 * 4) == 0) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
      uval_1 = 1;
    }
    else {
      thunk_FUN_1000192c(*(int32_t **)(&DAT_1000a648 + arg1 * 4),arg2);
      *(int *)(*(int *)(&DAT_1000a648 + arg1 * 4) + 0xc) =
           *(int *)(*(int *)(&DAT_1000a648 + arg1 * 4) + 0xc) + 1;
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
      uval_1 = 0;
    }
  }
  else {
    uval_1 = 5;
  }
  return uval_1;
}



/*
 * Decompiled function: Sound_PlayWaveSample
 * Entry Point: 10002389
 * Size: 237 bytes
 */
#include "magsnd.h"


int __cdecl Sound_PlayWaveSample(int arg1,uint32_t arg2)

{
  int32_t *ptr_1;
  int local_8;
  
  if ((arg1 < 0x100) && (-1 < arg1)) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
    ptr_1 = *(int32_t **)(&DAT_1000a648 + arg1 * 4);
    if (ptr_1 == (int32_t *)0x0) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
      local_8 = 1;
    }
    else if ((ptr_1[0xc] == 0) || ((uint32_t)ptr_1[0xc] < arg2)) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
      local_8 = 5;
    }
    else {
      if (ptr_1[arg2 + 0xd] == 0) {
        local_8 = thunk_FUN_1000207f(ptr_1,arg2);
      }
      else {
        local_8 = thunk_FUN_1000219c((int)ptr_1,arg2);
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
    }
  }
  else {
    local_8 = 5;
  }
  return local_8;
}



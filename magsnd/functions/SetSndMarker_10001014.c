/*
 * Decompiled function: SetSndMarker
 * Entry Point: 10001014
 * Size: 5 bytes
 */
#include "magsnd.h"


int __cdecl SetSndMarker(int arg1,uint32_t arg2)

{
  int32_t *ptr_1;
  int iStack_8;
  
                    /* 0x1014  18  SetSndMarker */
  if ((arg1 < 0x100) && (-1 < arg1)) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
    ptr_1 = *(int32_t **)(&DAT_1000a648 + arg1 * 4);
    if (ptr_1 == (int32_t *)0x0) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
      iStack_8 = 1;
    }
    else if ((ptr_1[0xc] == 0) || ((uint32_t)ptr_1[0xc] < arg2)) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
      iStack_8 = 5;
    }
    else {
      if (ptr_1[arg2 + 0xd] == 0) {
        iStack_8 = thunk_FUN_1000207f(ptr_1,arg2);
      }
      else {
        iStack_8 = thunk_FUN_1000219c((int)ptr_1,arg2);
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
    }
  }
  else {
    iStack_8 = 5;
  }
  return iStack_8;
}



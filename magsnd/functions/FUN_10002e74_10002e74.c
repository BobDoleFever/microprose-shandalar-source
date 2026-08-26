/*
 * Decompiled function: FUN_10002e74
 * Entry Point: 10002e74
 * Size: 273 bytes
 */
#include "magsnd.h"


int32_t __cdecl FUN_10002e74(int arg1,int arg2)

{
  int32_t uval_1;
  int *i_ptr_2;
  int local_8;
  
  if ((arg1 < 0x110) && (-1 < arg1)) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
    if (*(int *)(&DAT_1000a648 + arg1 * 4) == 0) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
      uval_1 = 1;
    }
    else {
      (**(code **)(**(int **)(*(int *)(&DAT_1000a648 + arg1 * 4) + 0xbc) + 0x40))
                (*(int32_t *)(*(int *)(&DAT_1000a648 + arg1 * 4) + 0xbc),arg2 * 10);
      local_8 = 0;
      while ((local_8 < 0x10 &&
             (i_ptr_2 = (int *)(*(int *)(&DAT_1000a648 + arg1 * 4) + local_8 * 0xc + 0xc0),
             *i_ptr_2 != 0))) {
        (**(code **)(*(int *)*i_ptr_2 + 0x40))(*i_ptr_2,arg2 * 10);
        local_8 = local_8 + 1;
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



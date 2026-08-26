/*
 * Decompiled function: StopSnd
 * Entry Point: 100010d2
 * Size: 5 bytes
 */
#include "magsnd.h"


int32_t __cdecl StopSnd(int arg_1)

{
  int32_t uval_1;
  int *i_ptr_2;
  int val_3;
  int iStack_10;
  
                    /* 0x10d2  8  StopSnd */
  if ((arg_1 < 0x110) && (-1 < arg_1)) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
    if (*(int *)(&DAT_1000a648 + arg_1 * 4) == 0) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
      uval_1 = 1;
    }
    else {
      if ((*(uint32_t *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 4) >> 6 & 1) == 0) {
        if ((*(uint32_t *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 8) >> 1 & 1) == 0) {
          val_3 = (**(code **)(**(int **)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 0xbc) + 0x48))
                            (*(int32_t *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 0xbc));
          if (val_3 != 0) {
            LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
            return 9;
          }
        }
        else {
          *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 4) =
               *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 4) | 2;
        }
      }
      else {
        val_3 = *(int *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 0x38 +
                        *(int *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 0x18) * 4);
        if (val_3 == 0) {
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
          return 1;
        }
        *(uint32_t *)(val_3 + 4) = *(uint32_t *)(val_3 + 4) | 2;
      }
      if ((*(uint32_t *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 8) >> 1 & 1) == 0) {
        iStack_10 = 0;
        while ((iStack_10 < 0x10 &&
               (i_ptr_2 = (int *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + iStack_10 * 0xc + 0xc0),
               *i_ptr_2 != 0))) {
          val_3 = (**(code **)(*(int *)*i_ptr_2 + 0x48))(*i_ptr_2);
          if (val_3 != 0) {
            LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
            return 9;
          }
          iStack_10 = iStack_10 + 1;
        }
        *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 4) =
             *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 4) & 0xfffffffe;
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



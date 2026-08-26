/*
 * Decompiled function: SetVol
 * Entry Point: 10001055
 * Size: 5 bytes
 */
#include "magsnd.h"


/* WARNING: Removing unreachable block (ram,0x10002ce6) */

int32_t __cdecl SetVol(int arg1,uint32_t arg2)

{
  int val_1;
  int32_t uval_2;
  int *i_ptr_3;
  int iStack_10;
  
                    /* 0x1055  13  SetVol */
  if ((arg1 < 0x110) && (-1 < arg1)) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
    if (*(int *)(&DAT_1000a648 + arg1 * 4) == 0) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
      uval_2 = 1;
    }
    else {
      if (400 < arg2) {
        arg2 = 400;
      }
      if ((*(uint32_t *)(*(int *)(&DAT_1000a648 + arg1 * 4) + 4) >> 6 & 1) == 0) {
        *(uint32_t *)(*(int *)(&DAT_1000a648 + arg1 * 4) + 0x1f0) = arg2;
        *(uint32_t *)(*(int *)(&DAT_1000a648 + arg1 * 4) + 0x1f0) = arg2;
        arg2 = (arg2 * 5 + -2000) * 2;
        (**(code **)(**(int **)(*(int *)(&DAT_1000a648 + arg1 * 4) + 0xbc) + 0x3c))
                  (*(int32_t *)(*(int *)(&DAT_1000a648 + arg1 * 4) + 0xbc),arg2);
      }
      else {
        val_1 = *(int *)(*(int *)(&DAT_1000a648 + arg1 * 4) + 0x38 +
                        *(int *)(*(int *)(&DAT_1000a648 + arg1 * 4) + 0x18) * 4);
        if (val_1 == 0) {
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
          return 1;
        }
        *(uint32_t *)(val_1 + 0x1f0) = arg2;
        arg2 = (arg2 * 5 + -2000) * 2;
        (**(code **)(**(int **)(val_1 + 0xbc) + 0x3c))(*(int32_t *)(val_1 + 0xbc),arg2);
      }
      iStack_10 = 0;
      while ((iStack_10 < 0x10 &&
             (i_ptr_3 = (int *)(*(int *)(&DAT_1000a648 + arg1 * 4) + iStack_10 * 0xc + 0xc0),
             *i_ptr_3 != 0))) {
        (**(code **)(*(int *)*i_ptr_3 + 0x3c))(*i_ptr_3,arg2);
        iStack_10 = iStack_10 + 1;
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
      uval_2 = 0;
    }
  }
  else {
    uval_2 = 5;
  }
  return uval_2;
}



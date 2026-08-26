/*
 * Decompiled function: FUN_100030e6
 * Entry Point: 100030e6
 * Size: 664 bytes
 */
#include "magsnd.h"


int32_t __cdecl FUN_100030e6(int arg1,uint32_t *arg2)

{
  int32_t uval_1;
  uint32_t uval_2;
  uint32_t local_20;
  int local_1c;
  uint32_t local_18;
  double local_14;
  uint32_t local_c;
  uint8_t local_8 [4];
  
  if ((arg1 < 0x110) && (-1 < arg1)) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
    if (*(int *)(&DAT_1000a648 + arg1 * 4) == 0) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
      uval_1 = 1;
    }
    else {
      local_1c = *(int *)(&DAT_1000a648 + arg1 * 4);
      (**(code **)(**(int **)(local_1c + 0xbc) + 0x10))
                (*(int32_t *)(local_1c + 0xbc),&local_20,local_8);
      local_18 = *(uint32_t *)(local_1c + 0x1dc) % *(uint32_t *)(local_1c + 0xb0);
      if (local_18 < local_20) {
        *(int *)(local_1c + 0x1dc) = *(int *)(local_1c + 0x1dc) + (local_20 - local_18);
      }
      else {
        *(int *)(local_1c + 0x1dc) =
             *(int *)(local_1c + 0x1dc) + (*(int *)(local_1c + 0xb0) - local_18);
        *(int *)(local_1c + 0x1dc) = *(int *)(local_1c + 0x1dc) + local_20;
      }
      if ((*(uint32_t *)(local_1c + 8) >> 5 & 1) != 0) {
        local_c = *(uint32_t *)(local_1c + 0x1dc) / *(uint32_t *)(local_1c + 0x8c);
        while (*(uint32_t *)(local_1c + 0xa0) < local_c) {
          PostMessageA(DAT_1000ba88,0x3bd,0,local_c);
          *(int *)(local_1c + 0xa0) = *(int *)(local_1c + 0xa0) + 1;
        }
      }
      local_14 = (double)*(uint32_t *)(local_1c + 0x1dc);
      if (*(int *)(local_1c + 0x80) == 0x15888) {
        uval_2 = ftol();
        *arg2 = uval_2;
      }
      else if (*(int *)(local_1c + 0x80) == 0xac44) {
        uval_2 = ftol();
        *arg2 = uval_2;
      }
      else if (*(int *)(local_1c + 0x80) == 0x5622) {
        uval_2 = ftol();
        *arg2 = uval_2;
      }
      else {
        if (*(int *)(local_1c + 0x80) != 0x2b11) {
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
          return 8;
        }
        uval_2 = ftol();
        *arg2 = uval_2;
      }
      *(uint32_t *)(&DAT_1000aa88 + DAT_1000a474 * 0x10) = DAT_1000a438;
      *(uint32_t *)(&DAT_1000aa8c + DAT_1000a474 * 0x10) = *arg2;
      DAT_1000a474 = DAT_1000a474 + 1;
      DAT_1000a474 = DAT_1000a474 & 0xff;
      if (*arg2 < DAT_1000a438) {
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
        uval_1 = 5;
      }
      else {
        DAT_1000a438 = *arg2;
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
        uval_1 = 0;
      }
    }
  }
  else {
    uval_1 = 5;
  }
  return uval_1;
}



/*
 * Decompiled function: GetSndTime
 * Entry Point: 1000105f
 * Size: 5 bytes
 */
#include "magsnd.h"


int32_t __cdecl GetSndTime(int arg1,uint32_t *arg2)

{
  int32_t uval_1;
  uint32_t uval_2;
  uint32_t uStack_20;
  int iStack_1c;
  uint32_t uStack_18;
  double dStack_14;
  uint32_t uStack_c;
  uint8_t auStack_8 [4];
  
                    /* 0x105f  20  GetSndTime */
  if ((arg1 < 0x110) && (-1 < arg1)) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
    if (*(int *)(&DAT_1000a648 + arg1 * 4) == 0) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
      uval_1 = 1;
    }
    else {
      iStack_1c = *(int *)(&DAT_1000a648 + arg1 * 4);
      (**(code **)(**(int **)(iStack_1c + 0xbc) + 0x10))
                (*(int32_t *)(iStack_1c + 0xbc),&uStack_20,auStack_8);
      uStack_18 = *(uint32_t *)(iStack_1c + 0x1dc) % *(uint32_t *)(iStack_1c + 0xb0);
      if (uStack_18 < uStack_20) {
        *(int *)(iStack_1c + 0x1dc) = *(int *)(iStack_1c + 0x1dc) + (uStack_20 - uStack_18);
      }
      else {
        *(int *)(iStack_1c + 0x1dc) =
             *(int *)(iStack_1c + 0x1dc) + (*(int *)(iStack_1c + 0xb0) - uStack_18);
        *(int *)(iStack_1c + 0x1dc) = *(int *)(iStack_1c + 0x1dc) + uStack_20;
      }
      if ((*(uint32_t *)(iStack_1c + 8) >> 5 & 1) != 0) {
        uStack_c = *(uint32_t *)(iStack_1c + 0x1dc) / *(uint32_t *)(iStack_1c + 0x8c);
        while (*(uint32_t *)(iStack_1c + 0xa0) < uStack_c) {
          PostMessageA(DAT_1000ba88,0x3bd,0,uStack_c);
          *(int *)(iStack_1c + 0xa0) = *(int *)(iStack_1c + 0xa0) + 1;
        }
      }
      dStack_14 = (double)*(uint32_t *)(iStack_1c + 0x1dc);
      if (*(int *)(iStack_1c + 0x80) == 0x15888) {
        uval_2 = ftol();
        *arg2 = uval_2;
      }
      else if (*(int *)(iStack_1c + 0x80) == 0xac44) {
        uval_2 = ftol();
        *arg2 = uval_2;
      }
      else if (*(int *)(iStack_1c + 0x80) == 0x5622) {
        uval_2 = ftol();
        *arg2 = uval_2;
      }
      else {
        if (*(int *)(iStack_1c + 0x80) != 0x2b11) {
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



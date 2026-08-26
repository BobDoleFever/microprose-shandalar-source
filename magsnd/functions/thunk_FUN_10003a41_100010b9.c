/*
 * Decompiled function: thunk_FUN_10003a41
 * Entry Point: 100010b9
 * Size: 5 bytes
 */
#include "magsnd.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl thunk_FUN_10003a41(int arg_1)

{
  uint32_t uval_1;
  int iStack_38;
  int iStack_34;
  void *pvStack_30;
  uint32_t uStack_2c;
  uint32_t uStack_28;
  uint32_t uStack_24;
  int32_t uStack_20;
  int iStack_1c;
  uint32_t uStack_18;
  int iStack_14;
  void *pvStack_10;
  size_t sStack_c;
  size_t sStack_8;
  
  uStack_20 = 0;
  iStack_34 = 0;
  uStack_18 = 0;
  uStack_2c = 0;
  uStack_24 = 0;
  iStack_1c = 0;
  pvStack_30 = (void *)0x0;
  pvStack_10 = (void *)0x0;
  sStack_8 = 0;
  sStack_c = 0;
  uStack_28 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
  (**(code **)(**(int **)(arg_1 + 0xbc) + 0x10))
            (*(int32_t *)(arg_1 + 0xbc),&iStack_34,&uStack_20);
  *(int *)(arg_1 + 0x1dc) =
       *(int *)(arg_1 + 0x1dc) + (iStack_34 - *(int *)(arg_1 + 0x1dc) & 0xffffU);
  if (*(uint32_t *)(arg_1 + 0x1cc) < *(uint32_t *)(arg_1 + 0x1dc)) {
    *(int *)(arg_1 + 0x1dc) = *(int *)(arg_1 + 0x1dc) - *(int *)(arg_1 + 0x1cc);
  }
  if ((((*(uint32_t *)(arg_1 + 4) >> 4 & 1) == 0) || (*(uint32_t *)(arg_1 + 0x1d4) < 0x10000)) &&
     (((*(uint32_t *)(arg_1 + 4) >> 1 & 1) == 0 || (*(int *)(arg_1 + 0x1f0) != 0)))) {
    uval_1 = iStack_34 - *(int *)(arg_1 + 0x1d8) & 0xffff;
    uStack_24 = *(int *)(arg_1 + 0x1cc) - *(int *)(arg_1 + 0x1d0);
    if ((*(uint32_t *)(arg_1 + 4) >> 4 & 1) == 0) {
      uStack_2c = *(int *)(arg_1 + 0x1d0) - *(int *)(arg_1 + 0x1d4);
      if (0x10000 < uStack_2c) {
        _DAT_1000a47c = _DAT_1000a47c + 1;
      }
    }
    else {
      uStack_2c = 0;
    }
    iStack_1c = uStack_24 + uStack_2c;
    uStack_18 = uval_1;
    if (iStack_1c == 0) {
      uStack_18 = 0;
      uStack_28 = uval_1;
    }
    if ((uStack_18 == 0) && (uStack_28 == 0)) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
    }
    else {
      if (uStack_2c < uStack_18) {
        uStack_18 = uStack_2c;
      }
      if (uStack_18 + uStack_28 != 0) {
        iStack_14 = (**(code **)(**(int **)(arg_1 + 0xbc) + 0x2c))
                              (*(int32_t *)(arg_1 + 0xbc),*(int32_t *)(arg_1 + 0x1d8),
                               uStack_18 + uStack_28,&pvStack_30,&sStack_8,&pvStack_10,&sStack_c,0);
        if (iStack_14 != 0) {
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
          return;
        }
        *(uint32_t *)(arg_1 + 4) = *(uint32_t *)(arg_1 + 4) | 0x80;
        if (uStack_28 == 0) {
          mmioGetInfo(*(HMMIO *)(arg_1 + 0x1c8),(LPMMIOINFO)(arg_1 + 0x180),0);
          memmove(pvStack_30,*(void **)(arg_1 + 0x19c),sStack_8);
          *(int *)(arg_1 + 0x19c) = *(int *)(arg_1 + 0x19c) + sStack_8;
          if (pvStack_10 != (void *)0x0) {
            memmove(pvStack_10,*(void **)(arg_1 + 0x19c),sStack_c);
            *(int *)(arg_1 + 0x19c) = *(int *)(arg_1 + 0x19c) + sStack_c;
          }
          mmioSetInfo(*(HMMIO *)(arg_1 + 0x1c8),(LPCMMIOINFO)(arg_1 + 0x180),0);
          uStack_2c = uStack_2c - uStack_18;
          iStack_1c = iStack_1c - uStack_18;
          *(int *)(arg_1 + 0x1d4) = *(int *)(arg_1 + 0x1d4) + uStack_18;
        }
        else {
          if (*(short *)(arg_1 + 0x86) == 8) {
            iStack_38 = 0x80;
          }
          else {
            iStack_38 = 0;
          }
          memset(pvStack_30,iStack_38,sStack_8);
          if (pvStack_10 != (void *)0x0) {
            memset(pvStack_10,iStack_38,sStack_c);
          }
          *(int *)(arg_1 + 0x1d4) = *(int *)(arg_1 + 0x1d4) + uStack_28;
        }
        *(uint32_t *)(arg_1 + 0x1d8) = *(int *)(arg_1 + 0x1d8) + uStack_18 + uStack_28 & 0xffff;
        (**(code **)(**(int **)(arg_1 + 0xbc) + 0x4c))
                  (*(int32_t *)(arg_1 + 0xbc),pvStack_30,sStack_8,pvStack_10,sStack_c);
        *(uint32_t *)(arg_1 + 4) = *(uint32_t *)(arg_1 + 4) & 0xffffff7f;
      }
      if (((iStack_1c != 0) && (uStack_24 != 0)) &&
         ((uStack_2c == 0 || (uStack_2c < uStack_18 * 2)))) {
        mmioAdvance(*(HMMIO *)(arg_1 + 0x1c8),(LPMMIOINFO)(arg_1 + 0x180),0);
        if (uStack_24 < *(int *)(arg_1 + 0x194) - uStack_2c) {
          *(int *)(arg_1 + 0x1d0) = *(int *)(arg_1 + 0x1d0) + uStack_24;
        }
        else {
          *(int *)(arg_1 + 0x1d0) = *(int *)(arg_1 + 0x1d0) + (*(int *)(arg_1 + 0x194) - uStack_2c);
        }
      }
      if (iStack_1c == 0) {
        if ((*(uint8_t *)(arg_1 + 8) & 1) == 0) {
          if ((*(uint32_t *)(arg_1 + 4) >> 4 & 1) == 0) {
            *(int32_t *)(arg_1 + 0x1e4) = *(int32_t *)(arg_1 + 0x1d8);
            *(int32_t *)(arg_1 + 0x1d4) = 0;
            *(uint32_t *)(arg_1 + 4) = *(uint32_t *)(arg_1 + 4) | 0x10;
          }
        }
        else {
          *(int32_t *)(arg_1 + 0x19c) = *(int32_t *)(arg_1 + 0x1a0);
          mmioSetInfo(*(HMMIO *)(arg_1 + 0x1c8),(LPCMMIOINFO)(arg_1 + 0x180),0);
          mmioSeek(*(HMMIO *)(arg_1 + 0x1c8),*(LONG *)(arg_1 + 0x1e0),0);
          mmioGetInfo(*(HMMIO *)(arg_1 + 0x1c8),(LPMMIOINFO)(arg_1 + 0x180),0);
          mmioAdvance(*(HMMIO *)(arg_1 + 0x1c8),(LPMMIOINFO)(arg_1 + 0x180),0);
          *(int *)(arg_1 + 0x1d0) = *(int *)(arg_1 + 0x19c) - *(int *)(arg_1 + 0x198);
          if (*(uint32_t *)(arg_1 + 0x1cc) < *(uint32_t *)(arg_1 + 0x1d0)) {
            *(int32_t *)(arg_1 + 0x1d0) = *(int32_t *)(arg_1 + 0x1cc);
          }
          *(int32_t *)(arg_1 + 0x1d4) = 0;
        }
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
    }
  }
  else {
    (**(code **)(**(int **)(arg_1 + 0xbc) + 0x48))(*(int32_t *)(arg_1 + 0xbc));
    if ((0 < DAT_1000a428) && (DAT_1000a428 = DAT_1000a428 + -1, DAT_1000a428 == 0)) {
      thunk_FUN_10004788();
    }
    *(uint32_t *)(arg_1 + 4) = *(uint32_t *)(arg_1 + 4) & 0xfffffffe;
    *(uint32_t *)(arg_1 + 4) = *(uint32_t *)(arg_1 + 4) & 0xfffffffd;
    *(uint32_t *)(arg_1 + 4) = *(uint32_t *)(arg_1 + 4) | 4;
    *(uint32_t *)(arg_1 + 4) = *(uint32_t *)(arg_1 + 4) & 0xffffffdf;
    if ((*(uint32_t *)(arg_1 + 8) >> 4 & 1) != 0) {
      *(uint32_t *)(*(int *)(&DAT_1000a648 + *(int *)(arg_1 + 0x10) * 4) + 4) =
           *(uint32_t *)(*(int *)(&DAT_1000a648 + *(int *)(arg_1 + 0x10) * 4) + 4) & 0xffffffbf;
      *(uint32_t *)(*(int *)(&DAT_1000a648 + *(int *)(arg_1 + 0x10) * 4) + 4) =
           *(uint32_t *)(*(int *)(&DAT_1000a648 + *(int *)(arg_1 + 0x10) * 4) + 4) & 0xfffffffe;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
  }
  return;
}



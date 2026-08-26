/*
 * Decompiled function: FUN_10003a41
 * Entry Point: 10003a41
 * Size: 1561 bytes
 */
#include "magsnd.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10003a41(int arg_1)

{
  uint32_t uval_1;
  int local_38;
  int local_34;
  void *local_30;
  uint32_t local_2c;
  uint32_t local_28;
  uint32_t local_24;
  int32_t local_20;
  int local_1c;
  uint32_t local_18;
  int local_14;
  void *local_10;
  size_t local_c;
  size_t local_8;
  
  local_20 = 0;
  local_34 = 0;
  local_18 = 0;
  local_2c = 0;
  local_24 = 0;
  local_1c = 0;
  local_30 = (void *)0x0;
  local_10 = (void *)0x0;
  local_8 = 0;
  local_c = 0;
  local_28 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
  (**(code **)(**(int **)(arg_1 + 0xbc) + 0x10))(*(int32_t *)(arg_1 + 0xbc),&local_34,&local_20);
  *(int *)(arg_1 + 0x1dc) = *(int *)(arg_1 + 0x1dc) + (local_34 - *(int *)(arg_1 + 0x1dc) & 0xffffU)
  ;
  if (*(uint32_t *)(arg_1 + 0x1cc) < *(uint32_t *)(arg_1 + 0x1dc)) {
    *(int *)(arg_1 + 0x1dc) = *(int *)(arg_1 + 0x1dc) - *(int *)(arg_1 + 0x1cc);
  }
  if ((((*(uint32_t *)(arg_1 + 4) >> 4 & 1) == 0) || (*(uint32_t *)(arg_1 + 0x1d4) < 0x10000)) &&
     (((*(uint32_t *)(arg_1 + 4) >> 1 & 1) == 0 || (*(int *)(arg_1 + 0x1f0) != 0)))) {
    uval_1 = local_34 - *(int *)(arg_1 + 0x1d8) & 0xffff;
    local_24 = *(int *)(arg_1 + 0x1cc) - *(int *)(arg_1 + 0x1d0);
    if ((*(uint32_t *)(arg_1 + 4) >> 4 & 1) == 0) {
      local_2c = *(int *)(arg_1 + 0x1d0) - *(int *)(arg_1 + 0x1d4);
      if (0x10000 < local_2c) {
        _DAT_1000a47c = _DAT_1000a47c + 1;
      }
    }
    else {
      local_2c = 0;
    }
    local_1c = local_24 + local_2c;
    local_18 = uval_1;
    if (local_1c == 0) {
      local_18 = 0;
      local_28 = uval_1;
    }
    if ((local_18 == 0) && (local_28 == 0)) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
    }
    else {
      if (local_2c < local_18) {
        local_18 = local_2c;
      }
      if (local_18 + local_28 != 0) {
        local_14 = (**(code **)(**(int **)(arg_1 + 0xbc) + 0x2c))
                             (*(int32_t *)(arg_1 + 0xbc),*(int32_t *)(arg_1 + 0x1d8),
                              local_18 + local_28,&local_30,&local_8,&local_10,&local_c,0);
        if (local_14 != 0) {
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
          return;
        }
        *(uint32_t *)(arg_1 + 4) = *(uint32_t *)(arg_1 + 4) | 0x80;
        if (local_28 == 0) {
          mmioGetInfo(*(HMMIO *)(arg_1 + 0x1c8),(LPMMIOINFO)(arg_1 + 0x180),0);
          memmove(local_30,*(void **)(arg_1 + 0x19c),local_8);
          *(int *)(arg_1 + 0x19c) = *(int *)(arg_1 + 0x19c) + local_8;
          if (local_10 != (void *)0x0) {
            memmove(local_10,*(void **)(arg_1 + 0x19c),local_c);
            *(int *)(arg_1 + 0x19c) = *(int *)(arg_1 + 0x19c) + local_c;
          }
          mmioSetInfo(*(HMMIO *)(arg_1 + 0x1c8),(LPCMMIOINFO)(arg_1 + 0x180),0);
          local_2c = local_2c - local_18;
          local_1c = local_1c - local_18;
          *(int *)(arg_1 + 0x1d4) = *(int *)(arg_1 + 0x1d4) + local_18;
        }
        else {
          if (*(short *)(arg_1 + 0x86) == 8) {
            local_38 = 0x80;
          }
          else {
            local_38 = 0;
          }
          memset(local_30,local_38,local_8);
          if (local_10 != (void *)0x0) {
            memset(local_10,local_38,local_c);
          }
          *(int *)(arg_1 + 0x1d4) = *(int *)(arg_1 + 0x1d4) + local_28;
        }
        *(uint32_t *)(arg_1 + 0x1d8) = *(int *)(arg_1 + 0x1d8) + local_18 + local_28 & 0xffff;
        (**(code **)(**(int **)(arg_1 + 0xbc) + 0x4c))
                  (*(int32_t *)(arg_1 + 0xbc),local_30,local_8,local_10,local_c);
        *(uint32_t *)(arg_1 + 4) = *(uint32_t *)(arg_1 + 4) & 0xffffff7f;
      }
      if (((local_1c != 0) && (local_24 != 0)) && ((local_2c == 0 || (local_2c < local_18 * 2)))) {
        mmioAdvance(*(HMMIO *)(arg_1 + 0x1c8),(LPMMIOINFO)(arg_1 + 0x180),0);
        if (local_24 < *(int *)(arg_1 + 0x194) - local_2c) {
          *(int *)(arg_1 + 0x1d0) = *(int *)(arg_1 + 0x1d0) + local_24;
        }
        else {
          *(int *)(arg_1 + 0x1d0) = *(int *)(arg_1 + 0x1d0) + (*(int *)(arg_1 + 0x194) - local_2c);
        }
      }
      if (local_1c == 0) {
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



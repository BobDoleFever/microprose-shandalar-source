/*
 * Decompiled function: FUN_1000755a
 * Entry Point: 1000755a
 * Size: 194 bytes
 */
#include "magvid.h"


int __fastcall FUN_1000755a(int arg_1)

{
  uint32_t uval_1;
  uint32_t uval_2;
  int local_8;
  
  local_8 = 0;
  while (((local_8 < 0x20 && (*(int *)(arg_1 + 0x124) < 0x20)) &&
         (*(int *)(arg_1 + 0x11c) != *(int *)(arg_1 + 0x120)))) {
    waveOutWrite(*(HWAVEOUT *)(arg_1 + 0x74),
                 *(LPWAVEHDR *)(arg_1 + 0x9c + *(int *)(arg_1 + 0x120) * 4),0x20);
    *(int *)(arg_1 + 0x124) = *(int *)(arg_1 + 0x124) + 1;
    *(int *)(arg_1 + 0x120) = *(int *)(arg_1 + 0x120) + 1;
    uval_1 = *(uint32_t *)(arg_1 + 0x120);
    uval_2 = (int)uval_1 >> 0x1f;
    *(uint32_t *)(arg_1 + 0x120) = ((uval_1 ^ uval_2) - uval_2 & 0x1f ^ uval_2) - uval_2;
    local_8 = local_8 + 1;
  }
  return local_8;
}



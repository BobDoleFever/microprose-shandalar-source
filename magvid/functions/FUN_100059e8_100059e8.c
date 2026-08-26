/*
 * Decompiled function: FUN_100059e8
 * Entry Point: 100059e8
 * Size: 115 bytes
 */
#include "magvid.h"


void __cdecl FUN_100059e8(int arg_1)

{
  if (*(int *)(arg_1 + 0x40) != 0) {
    *(int32_t *)(arg_1 + 0x48) = 0;
    *(int32_t *)(arg_1 + 0x40) = 0;
  }
  if (*(int *)(arg_1 + 8) != 0) {
    if (*(void **)(arg_1 + 8) != (void *)0x0) {
      thunk_FUN_10004b20(*(void **)(arg_1 + 8),1);
    }
    *(int32_t *)(arg_1 + 8) = 0;
  }
  return;
}



/*
 * Decompiled function: thunk_FUN_100019c7
 * Entry Point: 1000114f
 * Size: 5 bytes
 */
#include "magvid.h"


int32_t __fastcall thunk_FUN_100019c7(int arg_1)

{
  if (*(int *)(arg_1 + 8) != 0) {
    AVIFileRelease(*(int32_t *)(arg_1 + 8));
    *(int32_t *)(arg_1 + 8) = 0;
  }
  return 0;
}



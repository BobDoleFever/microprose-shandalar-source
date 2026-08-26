/*
 * Decompiled function: thunk_FUN_10001c16
 * Entry Point: 10001271
 * Size: 5 bytes
 */
#include "magvid.h"


int32_t __fastcall thunk_FUN_10001c16(int *ptr_1)

{
  thunk_FUN_10001d28(ptr_1);
  thunk_FUN_10007a85(ptr_1);
  thunk_FUN_10007238((int)ptr_1);
  if (ptr_1[3] != 0) {
    AVIStreamRelease(ptr_1[3]);
  }
  if (ptr_1[4] != 0) {
    AVIStreamRelease(ptr_1[4]);
  }
  ptr_1[4] = 0;
  ptr_1[3] = ptr_1[4];
  return 0;
}



/*
 * Decompiled function: thunk_FUN_10001d28
 * Entry Point: 1000105f
 * Size: 5 bytes
 */
#include "magvid.h"


int32_t __fastcall thunk_FUN_10001d28(int32_t *ptr_1)

{
  ptr_1[6] = 0;
  ptr_1[7] = 0;
  thunk_FUN_1000735d();
  thunk_FUN_10007bff(ptr_1);
  timeEndPeriod(ptr_1[10]);
  return 0;
}



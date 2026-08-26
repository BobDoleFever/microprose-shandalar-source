/*
 * Decompiled function: AVI_EndTimerPeriod
 * Entry Point: 10001d28
 * Size: 73 bytes
 */
#include "magvid.h"


int32_t __fastcall AVI_EndTimerPeriod(int32_t *ptr_1)

{
  ptr_1[6] = 0;
  ptr_1[7] = 0;
  thunk_FUN_1000735d();
  thunk_FUN_10007bff(ptr_1);
  timeEndPeriod(ptr_1[10]);
  return 0;
}



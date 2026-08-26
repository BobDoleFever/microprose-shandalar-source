/*
 * Decompiled function: AVI_StopPlaybackTimer
 * Entry Point: 10001d71
 * Size: 73 bytes
 */
#include "magvid.h"


int32_t __fastcall AVI_StopPlaybackTimer(int32_t *ptr_1)

{
  ptr_1[6] = 0;
  ptr_1[7] = 1;
  thunk_FUN_10007383();
  thunk_FUN_10007bff(ptr_1);
  timeEndPeriod(ptr_1[10]);
  return 0;
}



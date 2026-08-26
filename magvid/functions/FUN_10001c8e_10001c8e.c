/*
 * Decompiled function: AVI_InitTimerPeriod
 * Entry Point: 10001c8e
 * Size: 154 bytes
 */
#include "magvid.h"


int32_t __thiscall AVI_InitTimerPeriod(void *this,int arg_2)

{
  int32_t uval_1;
  timecaps_tag local_c;
  
  if (*(int *)((int)this + 0xc) == 0) {
    uval_1 = 0xffffffff;
  }
  else if (*(int *)((int)this + 0x18) == 0) {
    *(int32_t *)((int)this + 0x18) = 1;
    timeGetDevCaps(&local_c,8);
    if (local_c.wPeriodMin < 2) {
      local_c.wPeriodMin = 1;
    }
    *(UINT *)((int)this + 0x28) = local_c.wPeriodMin;
    timeBeginPeriod(*(UINT *)((int)this + 0x28));
    *(int32_t *)((int)this + 0x1c) = 0;
    thunk_FUN_10007b00(this,arg_2,-1);
    uval_1 = 0;
  }
  else {
    uval_1 = 0xfffffffc;
  }
  return uval_1;
}



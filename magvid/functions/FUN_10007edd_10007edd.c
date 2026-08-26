/*
 * Decompiled function: FUN_10007edd
 * Entry Point: 10007edd
 * Size: 46 bytes
 */
#include "magvid.h"


int32_t __thiscall FUN_10007edd(void *this,int32_t arg_2)

{
  int32_t uval_1;
  
  uval_1 = AVIStreamSampleToTime(*(int32_t *)((int)this + 0xc),arg_2);
  return uval_1;
}



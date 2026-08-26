/*
 * Decompiled function: FUN_100070d0
 * Entry Point: 100070d0
 * Size: 133 bytes
 */
#include "magvid.h"


void FUN_100070d0(int32_t arg_1,int arg_2,void *ptr_3)

{
  if (arg_2 == 0x3bb) {
    DAT_1001bf50 = ptr_3;
  }
  else if (arg_2 == 0x3bc) {
    DAT_1001bf50 = (void *)0x0;
  }
  else if ((arg_2 == 0x3bd) && (DAT_1001bf50 != (void *)0x0)) {
    thunk_FUN_1000761c(DAT_1001bf50);
  }
  return;
}



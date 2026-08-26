/*
 * Decompiled function: VidStatus
 * Entry Point: 10001325
 * Size: 5 bytes
 */
#include "magvid.h"


int32_t __cdecl VidStatus(int arg_1)

{
  int32_t uval_1;
  
                    /* 0x1325  16  VidStatus */
  if ((arg_1 < 0) || (2 < arg_1)) {
    uval_1 = 2;
  }
  else if (*(int *)(&DAT_10010868 + arg_1 * 4) == 0) {
    uval_1 = 0;
  }
  else {
    uval_1 = *(int32_t *)(*(int *)(&DAT_10010868 + arg_1 * 4) + 0x38);
  }
  return uval_1;
}



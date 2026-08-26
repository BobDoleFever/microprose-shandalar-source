/*
 * Decompiled function: SetVidCallBack
 * Entry Point: 1000128a
 * Size: 5 bytes
 */
#include "magvid.h"


int32_t __cdecl SetVidCallBack(int arg1,int32_t arg2)

{
  int32_t uval_1;
  
                    /* 0x128a  7  SetVidCallBack */
  if ((arg1 < 0) || (2 < arg1)) {
    uval_1 = 2;
  }
  else if (*(int *)(&DAT_10010868 + arg1 * 4) == 0) {
    uval_1 = 5;
  }
  else {
    *(int32_t *)(*(int *)(&DAT_10010868 + arg1 * 4) + 0x6c) = arg2;
    uval_1 = 0;
  }
  return uval_1;
}



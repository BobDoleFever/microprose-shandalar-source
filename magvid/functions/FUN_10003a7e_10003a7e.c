/*
 * Decompiled function: FUN_10003a7e
 * Entry Point: 10003a7e
 * Size: 85 bytes
 */
#include "magvid.h"


int32_t __cdecl FUN_10003a7e(int arg_1)

{
  int32_t uval_1;
  
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



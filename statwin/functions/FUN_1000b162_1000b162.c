/*
 * Decompiled function: FUN_1000b162
 * Entry Point: 1000b162
 * Size: 109 bytes
 */
#include "statwin.h"


int32_t FUN_1000b162(int arg1,int arg2)

{
  int32_t uval_1;
  int32_t local_c;
  int32_t local_8;
  
  if ((arg2 < 0x101) && (-1 < arg2)) {
    for (local_c = 0; local_c < arg2; local_c = local_c + 1) {
      *(int32_t *)(local_8 + local_c * 4) = *(int32_t *)(arg1 + local_c * 4);
    }
    uval_1 = 0;
  }
  else {
    uval_1 = 1;
  }
  return uval_1;
}



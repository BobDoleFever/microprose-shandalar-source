/*
 * Decompiled function: FUN_1000761c
 * Entry Point: 1000761c
 * Size: 97 bytes
 */
#include "magvid.h"


int32_t __fastcall FUN_1000761c(void *ptr_1)

{
  int32_t uval_1;
  
  if (*(int *)((int)ptr_1 + 0x78) < 0) {
    uval_1 = 0xffffffff;
  }
  else if (*(int *)((int)ptr_1 + 0x18) == 0) {
    uval_1 = 0xffffffff;
  }
  else {
    thunk_FUN_1000743e(ptr_1,1);
    *(int *)((int)ptr_1 + 0x124) = *(int *)((int)ptr_1 + 0x124) + -1;
    thunk_FUN_1000755a((int)ptr_1);
    uval_1 = 0;
  }
  return uval_1;
}



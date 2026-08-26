/*
 * Decompiled function: thunk_FUN_10007bff
 * Entry Point: 10001050
 * Size: 5 bytes
 */
#include "magvid.h"


int32_t __fastcall thunk_FUN_10007bff(int32_t *ptr_1)

{
  int32_t uval_1;
  
  if (ptr_1[0xc] == 0) {
    uval_1 = 0xffffffea;
  }
  else {
    thunk_FUN_1000aea5((int32_t *)*ptr_1);
    thunk_FUN_1000acaf((int32_t *)*ptr_1);
    ptr_1[0xd] = 0xffffffff;
    ptr_1[0xc] = 0;
    uval_1 = 0;
  }
  return uval_1;
}



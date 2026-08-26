/*
 * Decompiled function: thunk_FUN_100080e7
 * Entry Point: 10001014
 * Size: 5 bytes
 */
#include "statwin.h"


int32_t __thiscall thunk_FUN_100080e7(void *this,int arg_2)

{
  int32_t uStack_8;
  
  for (uStack_8 = 0; uStack_8 < 5; uStack_8 = uStack_8 + 1) {
    *(int32_t *)(*(int *)this + uStack_8 * 4) = *(int32_t *)(arg_2 + uStack_8 * 4);
    if (*(int *)(arg_2 + uStack_8 * 4) != 0) {
      thunk_FUN_10007d32(this,uStack_8);
    }
  }
  return 0;
}



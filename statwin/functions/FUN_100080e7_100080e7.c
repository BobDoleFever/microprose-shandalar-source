/*
 * Decompiled function: FUN_100080e7
 * Entry Point: 100080e7
 * Size: 104 bytes
 */
#include "statwin.h"


int32_t __thiscall FUN_100080e7(void *this,int arg_2)

{
  int32_t local_8;
  
  for (local_8 = 0; local_8 < 5; local_8 = local_8 + 1) {
    *(int32_t *)(*(int *)this + local_8 * 4) = *(int32_t *)(arg_2 + local_8 * 4);
    if (*(int *)(arg_2 + local_8 * 4) != 0) {
      thunk_FUN_10007d32(this,local_8);
    }
  }
  return 0;
}



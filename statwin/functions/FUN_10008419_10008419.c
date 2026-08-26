/*
 * Decompiled function: FUN_10008419
 * Entry Point: 10008419
 * Size: 124 bytes
 */
#include "statwin.h"


int32_t __thiscall FUN_10008419(void *this,int arg_2)

{
  int32_t local_8;
  
  for (local_8 = 0; local_8 < 5; local_8 = local_8 + 1) {
    if (*(char *)(*(int *)this + 0x28 + local_8) != *(char *)(local_8 + 0x28 + arg_2)) {
      *(uint8_t *)(*(int *)this + 0x28 + local_8) = *(uint8_t *)(local_8 + 0x28 + arg_2);
      thunk_FUN_10007083(this,local_8);
    }
  }
  return 0;
}



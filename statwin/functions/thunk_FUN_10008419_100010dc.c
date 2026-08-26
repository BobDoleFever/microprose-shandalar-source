/*
 * Decompiled function: thunk_FUN_10008419
 * Entry Point: 100010dc
 * Size: 5 bytes
 */
#include "statwin.h"


int32_t __thiscall thunk_FUN_10008419(void *this,int arg_2)

{
  int32_t uStack_8;
  
  for (uStack_8 = 0; uStack_8 < 5; uStack_8 = uStack_8 + 1) {
    if (*(char *)(*(int *)this + 0x28 + uStack_8) != *(char *)(uStack_8 + 0x28 + arg_2)) {
      *(uint8_t *)(*(int *)this + 0x28 + uStack_8) = *(uint8_t *)(uStack_8 + 0x28 + arg_2);
      thunk_FUN_10007083(this,uStack_8);
    }
  }
  return 0;
}



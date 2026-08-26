/*
 * Decompiled function: thunk_FUN_10004b20
 * Entry Point: 10001352
 * Size: 5 bytes
 */
#include "magvid.h"


int * __thiscall thunk_FUN_10004b20(void *this,uint8_t arg_2)

{
  thunk_FUN_10001926(this);
  if ((arg_2 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



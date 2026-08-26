/*
 * Decompiled function: thunk_FUN_10004b70
 * Entry Point: 10001311
 * Size: 5 bytes
 */
#include "magvid.h"


int32_t * __thiscall thunk_FUN_10004b70(void *this,uint8_t arg_2)

{
  thunk_FUN_10008774(this);
  if ((arg_2 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



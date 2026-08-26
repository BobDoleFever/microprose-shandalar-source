/*
 * Decompiled function: FUN_10008520
 * Entry Point: 10008520
 * Size: 57 bytes
 */
#include "magvid.h"


int * __thiscall FUN_10008520(void *this,uint8_t arg_2)

{
  thunk_FUN_1000a2f1(this);
  if ((arg_2 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



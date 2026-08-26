/*
 * Decompiled function: FUN_100041b0
 * Entry Point: 100041b0
 * Size: 57 bytes
 */
#include "statwin.h"


void * __thiscall FUN_100041b0(void *this,uint8_t arg_2)

{
  thunk_FUN_10004481((int)this);
  if ((arg_2 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



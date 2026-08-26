/*
 * Decompiled function: thunk_FUN_100041b0
 * Entry Point: 1000112c
 * Size: 5 bytes
 */
#include "statwin.h"


void * __thiscall thunk_FUN_100041b0(void *this,uint8_t arg_2)

{
  thunk_FUN_10004481((int)this);
  if ((arg_2 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



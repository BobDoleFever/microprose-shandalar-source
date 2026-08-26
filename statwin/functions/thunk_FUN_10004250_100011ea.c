/*
 * Decompiled function: thunk_FUN_10004250
 * Entry Point: 100011ea
 * Size: 5 bytes
 */
#include "statwin.h"


int32_t * __thiscall thunk_FUN_10004250(void *this,uint8_t arg_2)

{
  thunk_FUN_10009de4(this);
  if ((arg_2 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



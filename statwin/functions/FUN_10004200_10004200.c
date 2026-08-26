/*
 * Decompiled function: FUN_10004200
 * Entry Point: 10004200
 * Size: 64 bytes
 */
#include "statwin.h"


void __thiscall FUN_10004200(void *this,int32_t arg_2)

{
  void *buf_ptr_1;
  
  buf_ptr_1 = operator_new(4);
  *(void **)((int)this + 0x10) = buf_ptr_1;
  if (*(int *)((int)this + 0x10) != 0) {
    **(int32_t **)((int)this + 0x10) = arg_2;
  }
  return;
}



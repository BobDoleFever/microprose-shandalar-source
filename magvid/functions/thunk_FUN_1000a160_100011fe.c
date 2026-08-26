/*
 * Decompiled function: thunk_FUN_1000a160
 * Entry Point: 100011fe
 * Size: 5 bytes
 */
#include "magvid.h"


void __thiscall thunk_FUN_1000a160(void *this,int32_t arg_2)

{
  void *buf_ptr_1;
  
  buf_ptr_1 = operator_new(4);
  *(void **)((int)this + 0x10) = buf_ptr_1;
  if (*(int *)((int)this + 0x10) != 0) {
    **(int32_t **)((int)this + 0x10) = arg_2;
  }
  return;
}



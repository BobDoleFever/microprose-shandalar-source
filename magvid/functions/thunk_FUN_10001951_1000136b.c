/*
 * Decompiled function: thunk_FUN_10001951
 * Entry Point: 1000136b
 * Size: 5 bytes
 */
#include "magvid.h"


int __thiscall thunk_FUN_10001951(void *this,int32_t arg_2)

{
  int val_1;
  
  if (*(int *)((int)this + 8) != 0) {
    thunk_FUN_100019c7((int)this);
  }
  *(int32_t *)((int)this + 0x10) = 0;
  *(int32_t *)((int)this + 0xc) = *(int32_t *)((int)this + 0x10);
  val_1 = AVIFileOpenA((int)this + 8,arg_2,0x20,0);
  if (val_1 == 0) {
    val_1 = 0;
  }
  else {
    thunk_FUN_100019c7((int)this);
  }
  return val_1;
}



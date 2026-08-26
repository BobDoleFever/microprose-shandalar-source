/*
 * Decompiled function: FUN_100023d1
 * Entry Point: 100023d1
 * Size: 128 bytes
 */
#include "magvid.h"


int32_t __thiscall FUN_100023d1(void *this,int arg_2)

{
  int32_t uval_1;
  int val_2;
  
  if ((*(int *)((int)this + 0xc) == 0) || (*(int *)this == 0)) {
    uval_1 = 0xffffffff;
  }
  else if (*(int *)((int)this + 0x18) == 0) {
    *(int *)((int)this + 4) = arg_2;
    val_2 = thunk_FUN_1000bac7(*(void **)this,*(int **)((int)this + 4));
    if (val_2 == 0) {
      uval_1 = 0xfffffffb;
    }
    else {
      uval_1 = 0;
    }
  }
  else {
    uval_1 = 0xfffffffc;
  }
  return uval_1;
}



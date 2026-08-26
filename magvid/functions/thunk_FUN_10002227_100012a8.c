/*
 * Decompiled function: thunk_FUN_10002227
 * Entry Point: 100012a8
 * Size: 5 bytes
 */
#include "magvid.h"


int32_t __thiscall thunk_FUN_10002227(void *this,int arg_2)

{
  bool flag_1;
  int32_t uval_2;
  undefined3 extraout_var;
  
  if ((*(int *)((int)this + 0xc) == 0) || (*(int *)this == 0)) {
    uval_2 = 0xffffffff;
  }
  else {
    flag_1 = thunk_FUN_1000b99f(*(void **)this,arg_2);
    if (CONCAT31(extraout_var,flag_1) == 0) {
      uval_2 = 0xfffffffb;
    }
    else {
      uval_2 = 0;
    }
  }
  return uval_2;
}



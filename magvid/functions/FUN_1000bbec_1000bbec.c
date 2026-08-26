/*
 * Decompiled function: FUN_1000bbec
 * Entry Point: 1000bbec
 * Size: 154 bytes
 */
#include "magvid.h"


int32_t __thiscall FUN_1000bbec(void *this,int arg_2)

{
  int32_t uval_1;
  
  if (*(int *)((int)this + 0x180) == 0) {
    uval_1 = 1;
  }
  else {
    if (arg_2 == 1) {
      *(int32_t *)((int)this + 0x80) = 0;
      *(int32_t *)((int)this + 0x188) = 1;
    }
    else {
      *(int32_t *)((int)this + 0x80) = 0;
      *(int32_t *)((int)this + 0x188) = 0;
    }
    *(int32_t *)((int)this + 0x70) = 0x80000004;
    ICSendMessage(*(int32_t *)this,0x5001,(int)this + 0x5c,0x2c);
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: FUN_1000bd47
 * Entry Point: 1000bd47
 * Size: 163 bytes
 */
#include "magvid.h"


bool __thiscall FUN_1000bd47(void *this,int arg_2)

{
  int val_1;
  bool flag_2;
  
  if (*(int *)((int)this + 0xc) == 0x31347669) {
    *(int32_t *)((int)this + 0x70) = 0x80000008;
    *(int32_t *)((int)this + 0x68) = 4;
    if (arg_2 == 1) {
      *(int32_t *)((int)this + 0x84) = 0;
    }
    else {
      *(int32_t *)((int)this + 0x84) = 1;
    }
    val_1 = ICSendMessage(*(int32_t *)this,0x5001,(int)this + 0x5c,
                          *(int32_t *)((int)this + 0x5c));
    flag_2 = val_1 == 0;
  }
  else {
    flag_2 = false;
  }
  return flag_2;
}



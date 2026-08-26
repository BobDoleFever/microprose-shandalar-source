/*
 * Decompiled function: FUN_10007f0b
 * Entry Point: 10007f0b
 * Size: 102 bytes
 */
#include "magvid.h"


bool __thiscall FUN_10007f0b(void *this,int arg_2)

{
  int val_1;
  bool flag_2;
  
  if (*(int *)((int)this + 0xc) == 0) {
    flag_2 = false;
  }
  else {
    if (arg_2 < 0) {
      arg_2 = *(int *)((int)this + 0x44);
    }
    val_1 = AVIStreamFindSample(*(int32_t *)((int)this + 0xc),arg_2,0x14);
    flag_2 = val_1 == arg_2;
  }
  return flag_2;
}



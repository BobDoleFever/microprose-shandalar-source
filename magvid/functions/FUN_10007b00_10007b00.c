/*
 * Decompiled function: FUN_10007b00
 * Entry Point: 10007b00
 * Size: 222 bytes
 */
#include "magvid.h"


int32_t __thiscall FUN_10007b00(void *this,int arg_2,int arg_3)

{
  int32_t uval_1;
  int val_2;
  DWORD DVar3;
  
  if (*(int *)this == 0) {
    uval_1 = 0xffffffeb;
  }
  else if (arg_2 == 0) {
    uval_1 = 0xffffffea;
  }
  else {
    *(int *)((int)this + 0x30) = arg_2;
    if (-1 < arg_3) {
      *(int *)((int)this + 0x44) = arg_3;
    }
    val_2 = thunk_FUN_1000a8d3(*(void **)this,arg_2);
    if (val_2 == 0) {
      if (*(int *)((int)this + 0x18) != 0) {
        thunk_FUN_1000ae35(*(int32_t **)this);
      }
      DVar3 = timeGetTime();
      *(DWORD *)((int)this + 0x34) = DVar3;
      uval_1 = AVIStreamSampleToTime
                        (*(int32_t *)((int)this + 0xc),*(int32_t *)((int)this + 0x44));
      *(int32_t *)((int)this + 0x38) = uval_1;
      *(int32_t *)((int)this + 0x3c) = *(int32_t *)((int)this + 0x44);
      uval_1 = 0;
    }
    else {
      thunk_FUN_10007bff(this);
      uval_1 = 0xffffffeb;
    }
  }
  return uval_1;
}



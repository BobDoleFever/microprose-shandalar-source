/*
 * Decompiled function: FUN_10007268
 * Entry Point: 10007268
 * Size: 245 bytes
 */
#include "magvid.h"


int __thiscall FUN_10007268(void *this,int y,int32_t width,int height)

{
  int val_1;
  int32_t uval_2;
  
  if (*(int *)((int)this + 0x1c) == 0) {
    val_1 = thunk_FUN_1000715a((int)this);
    if (val_1 == 0) {
      if (height == 0) {
        *(int *)((int)this + 0x98) = y / *(int *)((int)this + 0x94);
      }
      else {
        *(int *)((int)this + 0x98) = y;
      }
      uval_2 = AVIStreamSampleToTime
                        (*(int32_t *)((int)this + 0x10),
                         *(int *)((int)this + 0x94) * *(int *)((int)this + 0x98));
      *(int32_t *)((int)this + 0x78) = uval_2;
      val_1 = thunk_FUN_10004e65(*(int32_t *)((int)this + 0x10),DAT_10010618,&DAT_100105f8);
      if (val_1 == 0) {
        thunk_FUN_10004f02(DAT_10010618,0);
        val_1 = 0;
      }
      else {
        val_1 = -0xd;
      }
    }
  }
  else {
    thunk_FUN_10004f02(DAT_10010618,0);
    val_1 = 0;
  }
  return val_1;
}



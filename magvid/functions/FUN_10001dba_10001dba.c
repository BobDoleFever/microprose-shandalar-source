/*
 * Decompiled function: AVI_SeekFrameToTime
 * Entry Point: 10001dba
 * Size: 264 bytes
 */
#include "magvid.h"


int32_t __thiscall AVI_SeekFrameToTime(void *this,int32_t arg_2)

{
  int32_t uval_1;
  int val_2;
  
  if (*(int *)((int)this + 0x18) == 0) {
    *(int32_t *)((int)this + 0x44) = arg_2;
    if (*(int *)((int)this + 0x44) < *(int *)((int)this + 0x54)) {
      *(int32_t *)((int)this + 0x44) = *(int32_t *)((int)this + 0x54);
    }
    else if (*(int *)((int)this + 0x58) < *(int *)((int)this + 0x44)) {
      *(int32_t *)((int)this + 0x44) = *(int32_t *)((int)this + 0x58);
    }
    if (*(int *)((int)this + 0x54) == *(int *)((int)this + 0x44)) {
      *(int32_t *)((int)this + 0x48) = 0xffffffff;
      *(int32_t *)((int)this + 0x4c) = 0xffffffff;
      *(int32_t *)((int)this + 0x50) = 0xffffffff;
    }
    if ((*(int *)((int)this + 0x10) != 0) && (*(int *)((int)this + 0x94) != 0)) {
      uval_1 = AVIStreamSampleToTime(*(int32_t *)((int)this + 0xc),arg_2);
      val_2 = AVIStreamTimeToSample(*(int32_t *)((int)this + 0x10),uval_1);
      *(int *)((int)this + 0x98) = val_2 / *(int *)((int)this + 0x94);
    }
    uval_1 = *(int32_t *)((int)this + 0x44);
  }
  else {
    uval_1 = 0xffffffff;
  }
  return uval_1;
}



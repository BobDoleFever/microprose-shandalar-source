/*
 * Decompiled function: AVI_GetVideoStreamInfo
 * Entry Point: 10001a02
 * Size: 532 bytes
 */
#include "magvid.h"


int __thiscall AVI_GetVideoStreamInfo(void *this,int arg_2,int arg_3)

{
  int val_1;
  int32_t local_b4;
  int32_t local_b0;
  int32_t local_ac;
  int32_t local_a8;
  int32_t local_a4;
  int32_t local_a0;
  int32_t local_9c;
  int32_t local_98;
  uint8_t local_94 [20];
  uint32_t local_80;
  uint32_t local_7c;
  int local_8;
  
  if ((*(int *)((int)this + 0xc) != 0) || (*(int *)((int)this + 0x10) != 0)) {
    thunk_FUN_10001c16(this);
  }
  *(int32_t *)((int)this + 0x1c) = 0;
  *(int32_t *)((int)this + 0x18) = *(int32_t *)((int)this + 0x1c);
  *(int *)((int)this + 0x14) = arg_2;
  *(int32_t *)this = 0;
  *(int32_t *)((int)this + 0x74) = 0;
  local_8 = AVIFileGetStream(*(int32_t *)((int)this + 8),(int)this + 0xc,0x73646976,0);
  if (local_8 == -0x7ffbbf8d) {
    *(int32_t *)((int)this + 0xc) = 0;
    val_1 = -1;
  }
  else {
    local_8 = AVIFileGetStream(*(int32_t *)((int)this + 8),(int)this + 0x10,0x73647561,0);
    if (local_8 == -0x7ffbbf8d) {
      *(int32_t *)((int)this + 0x10) = 0;
    }
    else {
      local_b4 = 400;
      local_b0 = 0;
      local_ac = 0;
      local_a8 = 0;
      local_a4 = 0;
      local_a0 = 0;
      local_9c = 0;
      local_98 = 0x14;
      thunk_FUN_10004e65(*(int32_t *)((int)this + 0x10),arg_3 + 0x100,&local_b4);
    }
    AVIStreamInfoA(*(int32_t *)((int)this + 0xc),local_94,0x8c);
    *(float *)((int)this + 0x24) = (float)((float10)local_7c / (float10)local_80);
    *(int32_t *)((int)this + 0x20) = *(int32_t *)((int)this + 0x24);
    val_1 = thunk_FUN_1000785e(this);
    if (val_1 == 0) {
      val_1 = 0;
    }
  }
  return val_1;
}



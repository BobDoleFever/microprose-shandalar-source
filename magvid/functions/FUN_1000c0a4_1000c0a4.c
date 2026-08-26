/*
 * Decompiled function: FUN_1000c0a4
 * Entry Point: 1000c0a4
 * Size: 193 bytes
 */
#include "magvid.h"


void __thiscall FUN_1000c0a4(void *this,int32_t y,int32_t width,int height)

{
  if (*(int *)((int)this + 0xc) == 0x31347669) {
    *(int32_t *)((int)this + 200) = 0x80000001;
    if (height == 0) {
      *(int32_t *)((int)this + 0xc0) = 2;
      *(int32_t *)((int)this + 0xcc) = width;
      ICSendMessage(*(int32_t *)this,0x5001,(int)this + 0xb4,*(int32_t *)((int)this + 0xb4));
    }
    else {
      *(int32_t *)((int)this + 0xc0) = 1;
      ICSendMessage(*(int32_t *)this,0x5001,(int)this + 0xb4,*(int32_t *)((int)this + 0xb4));
    }
  }
  return;
}



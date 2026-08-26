/*
 * Decompiled function: FUN_1000c165
 * Entry Point: 1000c165
 * Size: 150 bytes
 */
#include "magvid.h"


void __thiscall FUN_1000c165(void *this,int32_t arg_2)

{
  if (*(int *)((int)this + 0xc) == 0x31347669) {
    *(int32_t *)((int)this + 0x68) = 4;
    *(int32_t *)((int)this + 0x70) = 0x80000001;
    ICSendMessage(*(int32_t *)this,0x5000,(int)this + 0x5c,*(int32_t *)((int)this + 0x5c));
    *(int32_t *)((int)this + 0x78) = 1;
    *(int32_t *)((int)this + 0x74) = arg_2;
    ICSendMessage(*(int32_t *)this,0x5001,(int)this + 0x5c,*(int32_t *)((int)this + 0x5c));
  }
  return;
}



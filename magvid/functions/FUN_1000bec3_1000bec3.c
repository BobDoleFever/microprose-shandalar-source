/*
 * Decompiled function: FUN_1000bec3
 * Entry Point: 1000bec3
 * Size: 286 bytes
 */
#include "magvid.h"


void __thiscall FUN_1000bec3(void *this,int arg_2,int arg_3,int arg_4,int arg_5)

{
  if ((((*(int *)((int)this + 0xc) == 0x31347669) && (-0x100 < arg_2)) && (arg_2 < 0x100)) &&
     (((-0x100 < arg_3 && (arg_3 < 0x100)) && ((-0x100 < arg_4 && (arg_4 < 0x100)))))) {
    *(int32_t *)((int)this + 200) = 0x800000e0;
    if (arg_5 == 0) {
      *(int *)((int)this + 0xfc) = arg_2;
      *(int *)((int)this + 0x100) = arg_3;
      *(int *)((int)this + 0x104) = arg_4;
      *(int32_t *)((int)this + 0xc0) = 2;
      ICSendMessage(*(int32_t *)this,0x5001,(int)this + 0xb4,0x54);
    }
    else {
      *(int32_t *)((int)this + 0xc0) = 1;
      ICSendMessage(*(int32_t *)this,0x5001,(int)this + 0xb4,*(int32_t *)((int)this + 0xb4));
    }
  }
  return;
}



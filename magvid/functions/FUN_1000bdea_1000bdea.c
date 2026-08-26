/*
 * Decompiled function: FUN_1000bdea
 * Entry Point: 1000bdea
 * Size: 217 bytes
 */
#include "magvid.h"


void __thiscall
FUN_1000bdea(void *this,int32_t *ptr_2,int32_t *ptr_3,int32_t *ptr_4,int arg_5)

{
  if (*(int *)((int)this + 0xc) == 0x31347669) {
    *(int32_t *)((int)this + 200) = 0x800000e0;
    if (arg_5 == 0) {
      *(int32_t *)((int)this + 0xc0) = 2;
      ICSendMessage(*(int32_t *)this,0x5000,(int)this + 0xb4,*(int32_t *)((int)this + 0xb4));
    }
    else {
      *(int32_t *)((int)this + 0xc0) = 1;
      ICSendMessage(*(int32_t *)this,0x5000,(int)this + 0xb4,*(int32_t *)((int)this + 0xb4));
    }
    *ptr_2 = *(int32_t *)((int)this + 0xfc);
    *ptr_3 = *(int32_t *)((int)this + 0x100);
    *ptr_4 = *(int32_t *)((int)this + 0x104);
  }
  return;
}



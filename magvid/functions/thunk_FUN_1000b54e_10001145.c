/*
 * Decompiled function: thunk_FUN_1000b54e
 * Entry Point: 10001145
 * Size: 5 bytes
 */
#include "magvid.h"


void __thiscall thunk_FUN_1000b54e(void *this,int *ptr_2)

{
  *(int *)((int)this + 0x3c) = *ptr_2;
  *(int *)((int)this + 0x40) = ptr_2[1];
  *(int *)((int)this + 0x44) = ptr_2[2] - *ptr_2;
  *(int *)((int)this + 0x48) = ptr_2[3] - ptr_2[1];
  if (*(int *)((int)this + 0x180) == 0) {
    *(int32_t *)((int)this + 0x4c) = *(int32_t *)((int)this + 0x3c);
    *(int32_t *)((int)this + 0x50) = *(int32_t *)((int)this + 0x40);
    *(int32_t *)((int)this + 0x54) = *(int32_t *)((int)this + 0x44);
    *(int32_t *)((int)this + 0x58) = *(int32_t *)((int)this + 0x48);
  }
  return;
}



/*
 * Decompiled function: FUN_1000b4fb
 * Entry Point: 1000b4fb
 * Size: 83 bytes
 */
#include "magvid.h"


void __thiscall FUN_1000b4fb(void *this,int32_t *ptr_2)

{
  *ptr_2 = *(int32_t *)((int)this + 0x3c);
  ptr_2[1] = *(int32_t *)((int)this + 0x40);
  ptr_2[2] = *(int *)((int)this + 0x3c) + *(int *)((int)this + 0x44);
  ptr_2[3] = *(int *)((int)this + 0x48) + *(int *)((int)this + 0x40);
  return;
}



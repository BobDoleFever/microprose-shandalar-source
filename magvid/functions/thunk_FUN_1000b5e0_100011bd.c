/*
 * Decompiled function: thunk_FUN_1000b5e0
 * Entry Point: 100011bd
 * Size: 5 bytes
 */
#include "magvid.h"


void __thiscall thunk_FUN_1000b5e0(void *this,int32_t *ptr_2)

{
  *ptr_2 = *(int32_t *)((int)this + 0x4c);
  ptr_2[1] = *(int32_t *)((int)this + 0x50);
  ptr_2[2] = *(int *)((int)this + 0x4c) + *(int *)((int)this + 0x54);
  ptr_2[3] = *(int *)((int)this + 0x50) + *(int *)((int)this + 0x58);
  return;
}



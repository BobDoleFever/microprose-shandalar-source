/*
 * Decompiled function: thunk_FUN_1000b786
 * Entry Point: 100011a9
 * Size: 5 bytes
 */
#include "magvid.h"


void __thiscall thunk_FUN_1000b786(void *this,void *ptr_2)

{
  int val_1;
  void *buf_ptr_2;
  
  if (*(int *)((int)this + 0x180) == 0) {
    memcpy(*(void **)((int)this + 0x18),ptr_2,0x28);
    if (*(uint32_t *)((int)this + 0x198) < *(uint32_t *)((int)ptr_2 + 0x14)) {
      val_1 = *(int *)(*(int *)((int)this + 0x18) + 4) + 3;
      val_1 = ((int)(val_1 + (val_1 >> 0x1f & 3U)) >> 2) *
              (uint32_t)*(uint16_t *)(*(int *)((int)this + 0x18) + 0xe) * *(int *)((int)ptr_2 + 8) * 4;
      *(int *)((int)this + 0x198) = (int)(val_1 + (val_1 >> 0x1f & 7U)) >> 3;
      buf_ptr_2 = realloc(*(void **)((int)this + 0x19c),*(size_t *)((int)this + 0x198));
      *(void **)((int)this + 0x19c) = buf_ptr_2;
    }
  }
  return;
}



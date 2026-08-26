/*
 * Decompiled function: FUN_1000743e
 * Entry Point: 1000743e
 * Size: 284 bytes
 */
#include "magvid.h"


int __thiscall FUN_1000743e(void *this,int arg_2)

{
  uint32_t uval_1;
  int val_2;
  uint32_t uval_3;
  int local_c;
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if ((arg_2 <= local_8) || (*(int *)((int)this + 0x80) < *(int *)((int)this + 0x98))) {
      *(int *)((int)this + 0x98) = *(int *)((int)this + 0x98) + local_8;
      return local_8;
    }
    val_2 = AVIStreamRead(*(int32_t *)((int)this + 0x10),
                          (*(int *)((int)this + 0x98) + local_8) * *(int *)((int)this + 0x94),
                          *(int32_t *)((int)this + 0x94),
                          **(int32_t **)((int)this + *(int *)((int)this + 0x11c) * 4 + 0x9c),
                          *(int *)((int)this + 0x90) * *(int *)((int)this + 0x94),&local_c,0);
    if (val_2 != 0) {
      return local_8;
    }
    if (*(int *)((int)this + 0x90) * *(int *)((int)this + 0x94) - local_c != 0) break;
    *(int *)((int)this + 0x11c) = *(int *)((int)this + 0x11c) + 1;
    uval_1 = *(uint32_t *)((int)this + 0x11c);
    uval_3 = (int)uval_1 >> 0x1f;
    *(uint32_t *)((int)this + 0x11c) = ((uval_1 ^ uval_3) - uval_3 & 0x1f ^ uval_3) - uval_3;
    local_8 = local_8 + 1;
  }
  return local_8;
}



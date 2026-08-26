/*
 * Decompiled function: thunk_FUN_1000743e
 * Entry Point: 10001118
 * Size: 5 bytes
 */
#include "magvid.h"


int __thiscall thunk_FUN_1000743e(void *this,int arg_2)

{
  uint32_t uval_1;
  int val_2;
  uint32_t uval_3;
  int iStack_c;
  int iStack_8;
  
  iStack_8 = 0;
  while( true ) {
    if ((arg_2 <= iStack_8) || (*(int *)((int)this + 0x80) < *(int *)((int)this + 0x98))) {
      *(int *)((int)this + 0x98) = *(int *)((int)this + 0x98) + iStack_8;
      return iStack_8;
    }
    val_2 = AVIStreamRead(*(int32_t *)((int)this + 0x10),
                          (*(int *)((int)this + 0x98) + iStack_8) * *(int *)((int)this + 0x94),
                          *(int32_t *)((int)this + 0x94),
                          **(int32_t **)((int)this + *(int *)((int)this + 0x11c) * 4 + 0x9c),
                          *(int *)((int)this + 0x90) * *(int *)((int)this + 0x94),&iStack_c,0);
    if (val_2 != 0) {
      return iStack_8;
    }
    if (*(int *)((int)this + 0x90) * *(int *)((int)this + 0x94) - iStack_c != 0) break;
    *(int *)((int)this + 0x11c) = *(int *)((int)this + 0x11c) + 1;
    uval_1 = *(uint32_t *)((int)this + 0x11c);
    uval_3 = (int)uval_1 >> 0x1f;
    *(uint32_t *)((int)this + 0x11c) = ((uval_1 ^ uval_3) - uval_3 & 0x1f ^ uval_3) - uval_3;
    iStack_8 = iStack_8 + 1;
  }
  return iStack_8;
}



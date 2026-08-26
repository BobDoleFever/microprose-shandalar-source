/*
 * Decompiled function: FUN_1000bac7
 * Entry Point: 1000bac7
 * Size: 293 bytes
 */
#include "magvid.h"


int32_t __thiscall FUN_1000bac7(void *this,int *ptr_2)

{
  int val_1;
  int32_t uval_2;
  
  if (((*(int *)((int)this + 0xc) != 0x31347669) ||
      (val_1 = (**(code **)(*ptr_2 + 8))(), val_1 < *(int *)((int)this + 0x44))) ||
     (val_1 = (**(code **)(*ptr_2 + 0xc))(), val_1 < *(int *)((int)this + 0x48))) {
    return 0;
  }
  if ((*(int *)((int)this + 0x180) != 0) && (*(void **)((int)this + 0x180) != (void *)0x0)) {
    thunk_FUN_10004b70(*(void **)((int)this + 0x180),1);
  }
  if (ptr_2 != (int *)0x0) {
    *(int **)((int)this + 0x180) = ptr_2;
    *(int32_t *)((int)this + 0x50) = 0;
    *(int32_t *)((int)this + 0x4c) = *(int32_t *)((int)this + 0x50);
    uval_2 = (**(code **)(**(int **)((int)this + 0x180) + 8))();
    *(int32_t *)((int)this + 0x54) = uval_2;
    uval_2 = (**(code **)(**(int **)((int)this + 0x180) + 0xc))();
    *(int32_t *)((int)this + 0x58) = uval_2;
    *(int32_t *)((int)this + 0x2c) = 0;
    *(int32_t *)((int)this + 0x30) = 0;
    return 1;
  }
  return 0;
}



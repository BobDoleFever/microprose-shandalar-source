/*
 * Decompiled function: FUN_1000bc86
 * Entry Point: 1000bc86
 * Size: 193 bytes
 */
#include "magvid.h"


int32_t __thiscall FUN_1000bc86(void *this,int *ptr_2)

{
  int val_1;
  
  if (((*(int *)((int)this + 0xc) != 0x31347669) ||
      (val_1 = (**(code **)(*ptr_2 + 8))(), val_1 < *(int *)((int)this + 0x44))) ||
     (val_1 = (**(code **)(*ptr_2 + 0xc))(), val_1 < *(int *)((int)this + 0x48))) {
    return 0;
  }
  if ((*(int *)((int)this + 0x184) != 0) && (*(void **)((int)this + 0x180) != (void *)0x0)) {
    thunk_FUN_10004b70(*(void **)((int)this + 0x180),1);
  }
  if (ptr_2 != (int *)0x0) {
    *(int **)((int)this + 0x184) = ptr_2;
    return 1;
  }
  return 0;
}



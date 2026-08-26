/*
 * Decompiled function: FUN_1000a058
 * Entry Point: 1000a058
 * Size: 237 bytes
 */
#include "statwin.h"


int32_t __thiscall FUN_1000a058(void *this,int *ptr_2,int32_t arg_3)

{
  void *buf_ptr_1;
  int32_t uval_2;
  int val_3;
  
  if (*(int *)((int)this + 4) != 0) {
    free(*(void **)((int)this + 4));
  }
  if (*(short *)((int)ptr_2 + 0xe) == 8) {
    buf_ptr_1 = malloc(0x428);
    *(void **)((int)this + 4) = buf_ptr_1;
  }
  else {
    buf_ptr_1 = malloc(0x28);
    *(void **)((int)this + 4) = buf_ptr_1;
  }
  if (*(int *)((int)this + 4) == 0) {
    uval_2 = 0;
  }
  else {
    val_3 = FUN_1000a145(ptr_2);
    memcpy(*(void **)((int)this + 4),ptr_2,val_3 * 4 + 0x28);
    if ((*(int *)((int)this + 0xc) != 0) && (*(int *)((int)this + 8) != 0)) {
      free(*(void **)((int)this + 8));
    }
    *(int32_t *)((int)this + 8) = arg_3;
    *(int32_t *)((int)this + 0xc) = 0;
    uval_2 = 1;
  }
  return uval_2;
}



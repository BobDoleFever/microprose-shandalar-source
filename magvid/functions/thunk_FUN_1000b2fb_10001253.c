/*
 * Decompiled function: thunk_FUN_1000b2fb
 * Entry Point: 10001253
 * Size: 5 bytes
 */
#include "magvid.h"


int __thiscall thunk_FUN_1000b2fb(void *this,int32_t arg_2,int32_t arg_3)

{
  int val_1;
  int32_t uStack_c;
  
  if (*(int *)((int)this + 0x10) == 0) {
    val_1 = 0;
  }
  else {
    if (DAT_100275d0 == 0) {
      uStack_c = *(int32_t *)((int)this + 0x19c);
    }
    else {
      uStack_c = *(int32_t *)((int)this + 400);
    }
    val_1 = FUN_1000b284(*(int32_t *)this,arg_3,*(int32_t *)((int)this + 0x14),arg_2,0,0,
                         *(int32_t *)((int)this + 0x24),*(int32_t *)((int)this + 0x28),
                         *(int32_t *)((int)this + 0x18),uStack_c,0,0,
                         *(int32_t *)((int)this + 0x24),*(int32_t *)((int)this + 0x28));
    if (val_1 == 0) {
      val_1 = 0;
    }
  }
  return val_1;
}



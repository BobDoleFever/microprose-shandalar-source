/*
 * Decompiled function: thunk_FUN_1000b83e
 * Entry Point: 100012e9
 * Size: 5 bytes
 */
#include "magvid.h"


int __thiscall thunk_FUN_1000b83e(void *this,int arg_2,int arg_3,int arg_4,int arg_5,int arg_6)

{
  int val_1;
  int iStack_8;
  
  if (arg_3 == 0) {
    arg_3 = *(int *)((int)this + 0x2c);
  }
  if (arg_4 == 0) {
    arg_4 = *(int *)((int)this + 0x30);
  }
  if (arg_5 == 0) {
    arg_5 = *(int *)((int)this + 0x34);
  }
  if (arg_6 == 0) {
    arg_6 = *(int *)((int)this + 0x38);
  }
  if (arg_2 == 0) {
    iStack_8 = *(int *)((int)this + 0x18);
  }
  else {
    iStack_8 = arg_2;
  }
  if ((((arg_3 < 0) || (arg_4 < 0)) || (*(int *)(iStack_8 + 4) < arg_5 + arg_3)) ||
     (*(int *)(iStack_8 + 8) < arg_6 + arg_4)) {
    val_1 = -1;
  }
  else {
    val_1 = FUN_1000ac38(*(int32_t *)this,0,*(int32_t *)((int)this + 0x14),0,
                         *(int32_t *)((int)this + 0x1c),*(int32_t *)((int)this + 0x20),
                         *(int32_t *)((int)this + 0x24),*(int32_t *)((int)this + 0x28),
                         iStack_8,0,arg_3,arg_4,arg_5,arg_6);
    if (val_1 == 0) {
      if ((*(int *)((int)this + 0x180) == 0) ||
         ((*(int *)(iStack_8 + 4) <= *(int *)((int)this + 0x54) &&
          (*(int *)(iStack_8 + 8) <= *(int *)((int)this + 0x58))))) {
        val_1 = 0;
      }
      else {
        val_1 = -1;
      }
    }
  }
  return val_1;
}



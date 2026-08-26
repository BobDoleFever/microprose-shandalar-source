/*
 * Decompiled function: FUN_1000ac3f
 * Entry Point: 1000ac3f
 * Size: 131 bytes
 */
#include "statwin.h"


int __thiscall FUN_1000ac3f(void *this,int arg_2,int arg_3)

{
  int val_1;
  uint32_t uval_2;
  int val_3;
  
  val_1 = CFontDialog::GetWeight(this);
  if ((arg_2 < val_1) && (val_1 = CFontDialog::GetWeight(this), arg_3 < val_1)) {
    uval_2 = thunk_FUN_1000b760((int)this);
    val_1 = CFontDialog::GetWeight(this);
    val_3 = (uint32_t)*(uint16_t *)(*(int *)((int)this + 4) + 0xe) * arg_2;
    return ((val_1 - arg_3) + -1) * uval_2 + ((int)(val_3 + (val_3 >> 0x1f & 7U)) >> 3) +
           *(int *)((int)this + 8);
  }
  return 0;
}



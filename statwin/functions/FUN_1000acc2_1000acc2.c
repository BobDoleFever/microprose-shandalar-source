/*
 * Decompiled function: FUN_1000acc2
 * Entry Point: 1000acc2
 * Size: 71 bytes
 */
#include "statwin.h"


void __thiscall FUN_1000acc2(void *this,int32_t *ptr_2)

{
  int val_1;
  
  ptr_2[1] = 0;
  *ptr_2 = 0;
  val_1 = CFontDialog::GetWeight(this);
  ptr_2[3] = val_1;
  val_1 = CFontDialog::GetWeight(this);
  ptr_2[2] = val_1;
  return;
}



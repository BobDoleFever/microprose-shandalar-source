/*
 * Decompiled function: FUN_10009652
 * Entry Point: 10009652
 * Size: 71 bytes
 */
#include "magvid.h"


void __thiscall FUN_10009652(void *this,int32_t *ptr_2)

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



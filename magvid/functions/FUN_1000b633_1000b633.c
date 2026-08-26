/*
 * Decompiled function: FUN_1000b633
 * Entry Point: 1000b633
 * Size: 82 bytes
 */
#include "magvid.h"


void __thiscall FUN_1000b633(void *this,int *ptr_2)

{
  *(int *)((int)this + 0x4c) = *ptr_2;
  *(int *)((int)this + 0x50) = ptr_2[1];
  *(int *)((int)this + 0x54) = ptr_2[2] - *ptr_2;
  *(int *)((int)this + 0x58) = ptr_2[3] - ptr_2[1];
  return;
}



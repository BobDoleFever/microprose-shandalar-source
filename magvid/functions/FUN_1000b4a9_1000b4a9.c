/*
 * Decompiled function: FUN_1000b4a9
 * Entry Point: 1000b4a9
 * Size: 82 bytes
 */
#include "magvid.h"


void __thiscall FUN_1000b4a9(void *this,int *ptr_2)

{
  *(int *)((int)this + 0x2c) = *ptr_2;
  *(int *)((int)this + 0x30) = ptr_2[1];
  *(int *)((int)this + 0x34) = ptr_2[2] - *ptr_2;
  *(int *)((int)this + 0x38) = ptr_2[3] - ptr_2[1];
  return;
}



/*
 * Decompiled function: FUN_1000b404
 * Entry Point: 1000b404
 * Size: 82 bytes
 */
#include "magvid.h"


void __thiscall FUN_1000b404(void *this,int *ptr_2)

{
  *(int *)((int)this + 0x1c) = *ptr_2;
  *(int *)((int)this + 0x20) = ptr_2[1];
  *(int *)((int)this + 0x24) = ptr_2[2] - *ptr_2;
  *(int *)((int)this + 0x28) = ptr_2[3] - ptr_2[1];
  return;
}



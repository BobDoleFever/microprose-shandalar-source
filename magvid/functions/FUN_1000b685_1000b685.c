/*
 * Decompiled function: FUN_1000b685
 * Entry Point: 1000b685
 * Size: 122 bytes
 */
#include "magvid.h"


int32_t __thiscall FUN_1000b685(void *this,int *ptr_2)

{
  int32_t uval_1;
  
  if (*(int *)((int)this + 0xc) == 0x31347669) {
    *ptr_2 = *(int *)((int)this + 0x16c);
    ptr_2[1] = *(int *)((int)this + 0x170);
    ptr_2[2] = *(int *)((int)this + 0x174) + *ptr_2;
    ptr_2[3] = *(int *)((int)this + 0x178) + ptr_2[1];
    uval_1 = 0;
  }
  else {
    uval_1 = 0xffffffff;
  }
  return uval_1;
}



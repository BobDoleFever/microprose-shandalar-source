/*
 * Decompiled function: FUN_1000435f
 * Entry Point: 1000435f
 * Size: 163 bytes
 */
#include "statwin.h"


int __thiscall FUN_1000435f(void *this,int *y,int width,int *height)

{
  int val_1;
  int local_8;
  
  if ((*y == 2) || (*y == 1)) {
    val_1 = *y;
  }
  else {
    if (*y == 3) {
      for (local_8 = 0; local_8 < 5; local_8 = local_8 + 1) {
        if (*(char *)(*(int *)this + 0x28 + local_8) != *(char *)(local_8 + 0x28 + width)) {
          *y = 3;
          *height = local_8;
          return 1;
        }
      }
    }
    val_1 = 0;
  }
  return val_1;
}



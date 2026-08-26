/*
 * Decompiled function: thunk_FUN_1000435f
 * Entry Point: 100011b3
 * Size: 5 bytes
 */
#include "statwin.h"


int __thiscall thunk_FUN_1000435f(void *this,int *y,int width,int *height)

{
  int val_1;
  int iStack_8;
  
  if ((*y == 2) || (*y == 1)) {
    val_1 = *y;
  }
  else {
    if (*y == 3) {
      for (iStack_8 = 0; iStack_8 < 5; iStack_8 = iStack_8 + 1) {
        if (*(char *)(*(int *)this + 0x28 + iStack_8) != *(char *)(iStack_8 + 0x28 + width)) {
          *y = 3;
          *height = iStack_8;
          return 1;
        }
      }
    }
    val_1 = 0;
  }
  return val_1;
}



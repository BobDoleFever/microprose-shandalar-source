/*
 * Decompiled function: FUN_1000381e
 * Entry Point: 1000381e
 * Size: 134 bytes
 */
#include "magvid.h"


int32_t __cdecl FUN_1000381e(int arg1,int arg2)

{
  int val_1;
  int32_t uval_2;
  int local_8;
  
  if ((arg1 < 0) || (2 < arg1)) {
    uval_2 = 2;
  }
  else {
    val_1 = *(int *)(&DAT_10010868 + arg1 * 4);
    if (val_1 == 0) {
      uval_2 = 0;
    }
    else {
      if (*(int *)(val_1 + 0x40) != 0) {
        local_8 = SetThreadPriority(*(HANDLE *)(val_1 + 0x40),arg2);
      }
      if (local_8 == 0) {
        uval_2 = 8;
      }
      else {
        uval_2 = 0;
      }
    }
  }
  return uval_2;
}



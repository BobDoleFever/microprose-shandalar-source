/*
 * Decompiled function: SetVidThreadPriority
 * Entry Point: 1000137f
 * Size: 5 bytes
 */
#include "magvid.h"


int32_t __cdecl SetVidThreadPriority(int arg1,int arg2)

{
  int val_1;
  int32_t uval_2;
  int iStack_8;
  
                    /* 0x137f  18  SetVidThreadPriority */
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
        iStack_8 = SetThreadPriority(*(HANDLE *)(val_1 + 0x40),arg2);
      }
      if (iStack_8 == 0) {
        uval_2 = 8;
      }
      else {
        uval_2 = 0;
      }
    }
  }
  return uval_2;
}



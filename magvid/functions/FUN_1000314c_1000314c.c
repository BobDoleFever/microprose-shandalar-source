/*
 * Decompiled function: FUN_1000314c
 * Entry Point: 1000314c
 * Size: 130 bytes
 */
#include "magvid.h"


int32_t __cdecl FUN_1000314c(int arg1,int arg2)

{
  LPARAM *ptr_1;
  int32_t uval_1;
  
  if ((arg2 < 0) || (2 < arg2)) {
    uval_1 = 2;
  }
  else {
    ptr_1 = *(LPARAM **)(&DAT_10010868 + arg2 * 4);
    if (ptr_1 == (LPARAM *)0x0) {
      uval_1 = 0;
    }
    else {
      thunk_FUN_100065fe(ptr_1,arg1);
      thunk_FUN_10006467(ptr_1);
      thunk_FUN_10006a43(ptr_1);
      uval_1 = 0;
    }
  }
  return uval_1;
}



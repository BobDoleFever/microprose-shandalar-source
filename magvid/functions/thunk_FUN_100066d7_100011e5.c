/*
 * Decompiled function: thunk_FUN_100066d7
 * Entry Point: 100011e5
 * Size: 5 bytes
 */
#include "magvid.h"


int32_t __cdecl thunk_FUN_100066d7(LPARAM *ptr_1)

{
  void *this;
  int arg_2;
  int val_1;
  bool flag_2;
  int32_t uval_3;
  undefined3 extraout_var;
  
  if ((ptr_1 == (LPARAM *)0x0) || (ptr_1[2] == 0)) {
    uval_3 = 2;
  }
  else {
    this = (void *)ptr_1[2];
    arg_2 = ptr_1[0x14];
    if (arg_2 == 0) {
      uval_3 = 2;
    }
    else {
      flag_2 = thunk_FUN_10004c20((int)this);
      if (CONCAT31(extraout_var,flag_2) == 0) {
        uval_3 = 1;
      }
      else {
        val_1 = ptr_1[0xe];
        if (val_1 != 0) {
          thunk_FUN_10005ef9((int)ptr_1);
        }
        thunk_FUN_100023d1(this,arg_2);
        if (val_1 != 0) {
          thunk_FUN_10005d8d(ptr_1);
        }
        PostMessageA((HWND)ptr_1[4],0x401,0,*ptr_1);
        uval_3 = 0;
      }
    }
  }
  return uval_3;
}



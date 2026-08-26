/*
 * Decompiled function: thunk_FUN_100065fe
 * Entry Point: 100011e0
 * Size: 5 bytes
 */
#include "magvid.h"


int32_t __cdecl thunk_FUN_100065fe(LPARAM *ptr_1,int arg_2)

{
  void *this;
  int val_1;
  bool flag_2;
  int32_t uval_3;
  undefined3 extraout_var;
  
  if ((ptr_1 == (LPARAM *)0x0) || (ptr_1[2] == 0)) {
    uval_3 = 2;
  }
  else {
    this = (void *)ptr_1[2];
    flag_2 = thunk_FUN_10004c20((int)this);
    if (CONCAT31(extraout_var,flag_2) == 0) {
      uval_3 = 1;
    }
    else if (arg_2 == 0) {
      uval_3 = 1;
    }
    else {
      val_1 = ptr_1[0xe];
      if (val_1 != 0) {
        thunk_FUN_10005ef9((int)ptr_1);
      }
      thunk_FUN_10002289(this,arg_2);
      if (val_1 != 0) {
        thunk_FUN_10005d8d(ptr_1);
      }
      PostMessageA((HWND)ptr_1[4],0x401,0,*ptr_1);
      uval_3 = 0;
    }
  }
  return uval_3;
}



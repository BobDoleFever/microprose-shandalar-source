/*
 * Decompiled function: thunk_FUN_10005c78
 * Entry Point: 100010aa
 * Size: 5 bytes
 */
#include "magvid.h"


void __cdecl thunk_FUN_10005c78(int arg1,int arg2)

{
  int *ptr_1;
  bool flag_1;
  undefined3 extraout_var;
  
  ptr_1 = *(int **)(arg1 + 8);
  flag_1 = thunk_FUN_10004c20((int)ptr_1);
  if (((CONCAT31(extraout_var,flag_1) != 0) && (ptr_1 != (int *)0x0)) && (*(int *)(arg1 + 0x38) == 0)
     ) {
    thunk_FUN_10007b00(ptr_1,arg2,-1);
    thunk_FUN_10007c85(ptr_1);
    thunk_FUN_10007bff(ptr_1);
  }
  return;
}



/*
 * Decompiled function: FUN_10003766
 * Entry Point: 10003766
 * Size: 179 bytes
 */
#include "magvid.h"


int32_t __cdecl FUN_10003766(int arg_1)

{
  int val_1;
  int *ptr_1;
  bool flag_2;
  int32_t uval_3;
  undefined3 extraout_var;
  
  if ((arg_1 < 0) || (2 < arg_1)) {
    uval_3 = 2;
  }
  else {
    val_1 = *(int *)(&DAT_10010868 + arg_1 * 4);
    if (val_1 == 0) {
      uval_3 = 0;
    }
    else {
      ptr_1 = *(int **)(val_1 + 8);
      flag_2 = thunk_FUN_10004c20((int)ptr_1);
      if (CONCAT31(extraout_var,flag_2) == 0) {
        uval_3 = 1;
      }
      else {
        if (ptr_1 != (int *)0x0) {
          if (*(int *)(val_1 + 0x38) != 0) {
            return 0;
          }
          thunk_FUN_10007b00(ptr_1,*(int *)(val_1 + 0x1c),-1);
          thunk_FUN_10007c85(ptr_1);
          thunk_FUN_10007bff(ptr_1);
        }
        uval_3 = 0;
      }
    }
  }
  return uval_3;
}



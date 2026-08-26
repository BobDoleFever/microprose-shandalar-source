/*
 * Decompiled function: FUN_1000634a
 * Entry Point: 1000634a
 * Size: 156 bytes
 */
#include "magvid.h"


int32_t __cdecl FUN_1000634a(int arg_1,LONG arg_2,LONG arg_3)

{
  int32_t *arg_1_00;
  POINT pt;
  bool flag_1;
  int32_t uval_2;
  undefined3 extraout_var;
  int val_3;
  BOOL BVar4;
  RECT local_14;
  
  if ((arg_1 == 0) || (*(int *)(arg_1 + 8) == 0)) {
    uval_2 = 2;
  }
  else {
    arg_1_00 = *(int32_t **)(arg_1 + 8);
    flag_1 = thunk_FUN_10004c20((int)arg_1_00);
    if (CONCAT31(extraout_var,flag_1) == 0) {
      uval_2 = 0;
    }
    else {
      val_3 = thunk_FUN_1000b685((void *)*arg_1_00,&local_14.left);
      if ((val_3 == 0) && (pt.y = arg_3, pt.x = arg_2, BVar4 = PtInRect(&local_14,pt), BVar4 != 0))
      {
        return 1;
      }
      uval_2 = 0;
    }
  }
  return uval_2;
}



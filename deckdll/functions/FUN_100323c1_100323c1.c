/*
 * Decompiled function: FUN_100323c1
 * Entry Point: 100323c1
 * Size: 417 bytes
 */
#include "deckdll.h"


void FUN_100323c1(int arg_1,int arg_2,RECT *arg_3)

{
  int arg_3_00;
  int val_1;
  int32_t arg_6;
  int32_t uval_2;
  uint32_t arg_2_00;
  int local_28;
  tagRECT local_14;
  
  if (((arg_1 != 0) && (arg_2 != 0)) && (arg_3 != (RECT *)0x0)) {
    CopyRect(&local_14,arg_3);
    arg_3_00 = *(int *)(arg_1 + 4);
    arg_2_00 = (uint32_t)*(uint16_t *)(arg_1 + 0xe);
    while( true ) {
      local_14.bottom = local_14.bottom + -1;
      local_14.right = local_14.right + -1;
      if (local_14.right <= local_14.left) break;
      for (local_28 = local_14.left; local_28 < local_14.right; local_28 = local_28 + 1) {
        val_1 = local_28 - local_14.left;
        arg_6 = thunk_FUN_10034390(arg_2,arg_2_00,arg_3_00,local_14.left + val_1,local_14.top);
        uval_2 = thunk_FUN_10034390(arg_2,arg_2_00,arg_3_00,local_14.left,local_14.bottom - val_1);
        thunk_FUN_10034510(arg_2,arg_2_00,arg_3_00,local_14.left + val_1,local_14.top,uval_2);
        uval_2 = thunk_FUN_10034390(arg_2,arg_2_00,arg_3_00,local_14.right - val_1,local_14.bottom);
        thunk_FUN_10034510(arg_2,arg_2_00,arg_3_00,local_14.left,local_14.bottom - val_1,uval_2);
        uval_2 = thunk_FUN_10034390(arg_2,arg_2_00,arg_3_00,local_14.right,local_14.top + val_1);
        thunk_FUN_10034510(arg_2,arg_2_00,arg_3_00,local_14.right - val_1,local_14.bottom,uval_2);
        thunk_FUN_10034510(arg_2,arg_2_00,arg_3_00,local_14.right,local_14.top + val_1,arg_6);
      }
      local_14.left = local_14.left + 1;
      local_14.top = local_14.top + 1;
    }
  }
  return;
}



/*
 * Decompiled function: FUN_100063e6
 * Entry Point: 100063e6
 * Size: 129 bytes
 */
#include "magvid.h"


void __cdecl FUN_100063e6(int arg_1,int arg_2,int arg_3)

{
  int32_t *arg_1_00;
  bool flag_1;
  undefined3 extraout_var;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if ((arg_1 != 0) && (*(int *)(arg_1 + 8) != 0)) {
    arg_1_00 = *(int32_t **)(arg_1 + 8);
    flag_1 = thunk_FUN_10004c20((int)arg_1_00);
    if (CONCAT31(extraout_var,flag_1) != 0) {
      thunk_FUN_1000b456((void *)*arg_1_00,&local_14);
      local_10 = local_10 + arg_3;
      local_8 = local_8 + arg_3;
      local_c = local_c + arg_2;
      local_14 = local_14 + arg_2;
      thunk_FUN_1000b4a9((void *)*arg_1_00,&local_14);
    }
  }
  return;
}



/*
 * Decompiled function: thunk_FUN_100063e6
 * Entry Point: 100011b3
 * Size: 5 bytes
 */
#include "magvid.h"


void __cdecl thunk_FUN_100063e6(int arg_1,int arg_2,int arg_3)

{
  int32_t *arg_1_00;
  bool flag_1;
  undefined3 extraout_var;
  int iStack_14;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  
  if ((arg_1 != 0) && (*(int *)(arg_1 + 8) != 0)) {
    arg_1_00 = *(int32_t **)(arg_1 + 8);
    flag_1 = thunk_FUN_10004c20((int)arg_1_00);
    if (CONCAT31(extraout_var,flag_1) != 0) {
      thunk_FUN_1000b456((void *)*arg_1_00,&iStack_14);
      iStack_10 = iStack_10 + arg_3;
      iStack_8 = iStack_8 + arg_3;
      iStack_c = iStack_c + arg_2;
      iStack_14 = iStack_14 + arg_2;
      thunk_FUN_1000b4a9((void *)*arg_1_00,&iStack_14);
    }
  }
  return;
}



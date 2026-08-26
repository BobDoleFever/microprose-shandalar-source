/*
 * Decompiled function: thunk_FUN_10004665
 * Entry Point: 10001113
 * Size: 5 bytes
 */
#include "magsnd.h"


void __cdecl thunk_FUN_10004665(int arg_1)

{
  int val_1;
  int val_2;
  int val_3;
  
  val_1 = *(int *)(arg_1 + 0x1fc);
  val_2 = *(int *)(arg_1 + 0x200);
  val_3 = val_2;
  if (val_1 != 0) {
    *(int *)(val_1 + 0x200) = val_2;
    val_3 = DAT_1000a410;
  }
  DAT_1000a410 = val_3;
  if (val_2 != 0) {
    *(int *)(val_2 + 0x1fc) = val_1;
    val_1 = DAT_1000a414;
  }
  DAT_1000a414 = val_1;
  return;
}



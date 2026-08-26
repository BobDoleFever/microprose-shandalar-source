/*
 * Decompiled function: FUN_1000458d
 * Entry Point: 1000458d
 * Size: 127 bytes
 */
#include "magsnd.h"


void __cdecl FUN_1000458d(int arg_1)

{
  int val_1;
  int val_2;
  int val_3;
  
  val_1 = *(int *)(arg_1 + 500);
  val_2 = *(int *)(arg_1 + 0x1f8);
  val_3 = val_2;
  if (val_1 != 0) {
    *(int *)(val_1 + 0x1f8) = val_2;
    val_3 = DAT_1000a418;
  }
  DAT_1000a418 = val_3;
  if (val_2 != 0) {
    *(int *)(val_2 + 500) = val_1;
    val_1 = DAT_1000a41c;
  }
  DAT_1000a41c = val_1;
  return;
}



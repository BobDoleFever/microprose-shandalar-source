/*
 * Decompiled function: FUN_004267dc
 * Entry Point: 004267dc
 * Size: 72 bytes
 */
#include "duel.h"


void FUN_004267dc(undefined4 arg_1,int *arg_2,byte arg_3)

{
  tagRECT local_14;
  
  if (((arg_3 & 1) != 0) && ((arg_3 & 2) != 0)) {
    FUN_00426824(&local_14,arg_2);
    FUN_00470c78(arg_1,&local_14,DAT_0050ac30);
  }
  return;
}



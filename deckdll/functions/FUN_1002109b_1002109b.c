/*
 * Decompiled function: FUN_1002109b
 * Entry Point: 1002109b
 * Size: 72 bytes
 */
#include "deckdll.h"


void FUN_1002109b(int32_t arg_1,int *arg_2,uint8_t arg_3)

{
  tagRECT local_14;
  
  if (((arg_3 & 1) != 0) && ((arg_3 & 2) != 0)) {
    thunk_FUN_100210e3(&local_14,arg_2);
    thunk_FUN_100318f9(arg_1,&local_14,DAT_1013e048);
  }
  return;
}



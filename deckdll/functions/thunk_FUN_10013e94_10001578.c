/*
 * Decompiled function: thunk_FUN_10013e94
 * Entry Point: 10001578
 * Size: 5 bytes
 */
#include "deckdll.h"


int thunk_FUN_10013e94(int arg_1,int arg_2,int arg_3)

{
  int val_1;
  
  if (arg_1 == -1) {
    val_1 = 0;
  }
  else if ((arg_2 == -1) || (arg_3 == -1)) {
    val_1 = 0;
  }
  else if (*(int *)(&DAT_10176af4 + arg_1 * 0x98) < 2) {
    val_1 = 0;
  }
  else {
    val_1 = (arg_3 + arg_2) % *(int *)(&DAT_10176af4 + arg_1 * 0x98);
  }
  return val_1;
}



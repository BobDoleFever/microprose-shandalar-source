/*
 * Decompiled function: FUN_10002d30
 * Entry Point: 10002d30
 * Size: 10 bytes
 */
#include "deckdll.h"


void FUN_10002d30(int *arg_1,int *arg_2,int *arg_3,int arg_4,int arg_5,int32_t arg_6,int arg_7)

{
  int *i_ptr_1;
  int *i_ptr_2;
  int *i_ptr_3;
  int iStack_4;
  
  if (0 < arg_5) {
    iStack_4 = arg_5;
    do {
      i_ptr_1 = arg_3 + arg_7 * 2;
      i_ptr_2 = arg_2;
      i_ptr_3 = arg_1;
      while (i_ptr_3 = i_ptr_3 + 1, i_ptr_3 < arg_1 + arg_4) {
        *i_ptr_1 = *i_ptr_2 + *i_ptr_3 >> 1;
        i_ptr_1[arg_7] = *i_ptr_3 - *i_ptr_2 >> 1;
        i_ptr_1 = i_ptr_1 + arg_7 * 2;
        i_ptr_2 = i_ptr_2 + 1;
      }
      arg_2 = i_ptr_2 + 1;
      *arg_3 = *i_ptr_2 + *arg_1 >> 1;
      arg_3[arg_7] = *arg_1 - *i_ptr_2 >> 1;
      iStack_4 = iStack_4 + -1;
      arg_1 = i_ptr_3;
      arg_3 = arg_3 + 1;
    } while (iStack_4 != 0);
  }
  return;
}



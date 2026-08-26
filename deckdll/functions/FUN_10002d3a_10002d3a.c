/*
 * Decompiled function: FUN_10002d3a
 * Entry Point: 10002d3a
 * Size: 140 bytes
 */
#include "deckdll.h"


void FUN_10002d3a(int arg_1,int32_t arg_2,int *arg_3,int *arg_4,int *arg_5,int arg_6,
                 int32_t arg_7,int32_t arg_8,int arg_9)

{
  int *i_ptr_1;
  int *i_ptr_2;
  int *i_ptr_3;
  int reg_eax;
  bool in_ZF;
  char in_SF;
  char in_OF;
  
  arg_1 = reg_eax;
  if (!in_ZF && in_OF == in_SF) {
    do {
      i_ptr_1 = arg_5 + arg_9 * 2;
      i_ptr_2 = arg_4;
      i_ptr_3 = arg_3;
      while (i_ptr_3 = i_ptr_3 + 1, i_ptr_3 < arg_3 + arg_6) {
        *i_ptr_1 = *i_ptr_2 + *i_ptr_3 >> 1;
        i_ptr_1[arg_9] = *i_ptr_3 - *i_ptr_2 >> 1;
        i_ptr_1 = i_ptr_1 + arg_9 * 2;
        i_ptr_2 = i_ptr_2 + 1;
      }
      arg_4 = i_ptr_2 + 1;
      *arg_5 = *i_ptr_2 + *arg_3 >> 1;
      arg_5[arg_9] = *arg_3 - *i_ptr_2 >> 1;
      arg_1 = arg_1 + -1;
      arg_3 = i_ptr_3;
      arg_5 = arg_5 + 1;
    } while (arg_1 != 0);
  }
  return;
}



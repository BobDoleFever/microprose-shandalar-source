/*
 * Decompiled function: FUN_00434d09
 * Entry Point: 00434d09
 * Size: 127 bytes
 */
#include "duel.h"


void FUN_00434d09(int *arg_1,int arg_2,int *arg_3)

{
  int local_8;
  
  if (*arg_1 == 0) {
    for (local_8 = 0; local_8 < 8; local_8 = local_8 + 1) {
      if (arg_1[local_8 + 2] != 0) {
        FUN_00434d09((int *)arg_1[local_8 + 2],arg_2,arg_3);
      }
    }
  }
  else {
    *(char *)(*arg_3 + arg_2) = (char)arg_1[1];
    *arg_3 = *arg_3 + 1;
  }
  return;
}



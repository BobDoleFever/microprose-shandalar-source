/*
 * Decompiled function: FUN_0047f011
 * Entry Point: 0047f011
 * Size: 213 bytes
 */
#include "duel.h"


void FUN_0047f011(int *arg_1,int *arg_2,int *arg_3,int arg_4,int arg_5,undefined4 arg_6,int arg_7)

{
  int *piVar1;
  int *piVar2;
  int *local_c;
  int local_8;
  
  for (local_8 = 0; piVar1 = arg_1, local_8 < arg_5; local_8 = local_8 + 1) {
    piVar2 = arg_1 + arg_4;
    local_c = arg_3 + arg_7 * 2;
    while (arg_1 = arg_1 + 1, arg_1 < piVar2) {
      *local_c = *arg_2 + *arg_1;
      local_c[arg_7] = *arg_1 - *arg_2;
      arg_2 = arg_2 + 1;
      local_c = local_c + arg_7 * 2;
    }
    *arg_3 = *piVar1 + *arg_2;
    arg_3[arg_7] = *piVar1 - *arg_2;
    arg_3 = arg_3 + 1;
    arg_2 = arg_2 + 1;
  }
  return;
}



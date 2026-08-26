/*
 * Decompiled function: FUN_0042df08
 * Entry Point: 0042df08
 * Size: 112 bytes
 */
#include "duel.h"


void FUN_0042df08(int arg_1,int arg_2,int arg_3,int *arg_4,undefined4 arg_5,int arg_6,int arg_7,
                 int arg_8,int *arg_9)

{
  int *piVar1;
  
  FUN_0049b277(arg_6,arg_7,arg_3);
  if (*(int *)(arg_1 + arg_2 * 4) == -1) {
    *arg_4 = *arg_4 + arg_3;
  }
  else {
    piVar1 = (int *)(arg_1 + arg_2 * 4);
    *piVar1 = *piVar1 - arg_3;
  }
  piVar1 = (int *)(arg_8 + arg_7 * 4);
  *piVar1 = *piVar1 + arg_3;
  FUN_0042e081(arg_7,arg_3);
  *arg_9 = *arg_9 + arg_3;
  return;
}



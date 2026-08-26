/*
 * Decompiled function: FUN_004f211a
 * Entry Point: 004f211a
 * Size: 140 bytes
 */
#include "magic.h"


void FUN_004f211a(int arg_1,undefined4 arg_2,int *arg_3,int *arg_4,int *arg_5,int arg_6,
                 undefined4 arg_7,undefined4 arg_8,int arg_9)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int in_EAX;
  bool in_ZF;
  char in_SF;
  char in_OF;
  
  arg_1 = in_EAX;
  if (!in_ZF && in_OF == in_SF) {
    do {
      piVar1 = arg_5 + arg_9 * 2;
      piVar2 = arg_4;
      piVar3 = arg_3;
      while (piVar3 = piVar3 + 1, piVar3 < arg_3 + arg_6) {
        *piVar1 = *piVar2 + *piVar3 >> 1;
        piVar1[arg_9] = *piVar3 - *piVar2 >> 1;
        piVar1 = piVar1 + arg_9 * 2;
        piVar2 = piVar2 + 1;
      }
      arg_4 = piVar2 + 1;
      *arg_5 = *piVar2 + *arg_3 >> 1;
      arg_5[arg_9] = *arg_3 - *piVar2 >> 1;
      arg_1 = arg_1 + -1;
      arg_3 = piVar3;
      arg_5 = arg_5 + 1;
    } while (arg_1 != 0);
  }
  return;
}



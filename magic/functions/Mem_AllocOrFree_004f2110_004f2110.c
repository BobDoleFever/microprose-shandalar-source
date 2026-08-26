/*
 * Decompiled function: Mem_AllocOrFree_004f2110
 * Entry Point: 004f2110
 * Size: 10 bytes
 */
#include "magic.h"


void Mem_AllocOrFree_004f2110
               (int *arg_1,int *arg_2,int *arg_3,int arg_4,int arg_5,undefined4 arg_6,int arg_7)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iStack_4;
  
  if (0 < arg_5) {
    iStack_4 = arg_5;
    do {
      piVar1 = arg_3 + arg_7 * 2;
      piVar2 = arg_2;
      piVar3 = arg_1;
      while (piVar3 = piVar3 + 1, piVar3 < arg_1 + arg_4) {
        *piVar1 = *piVar2 + *piVar3 >> 1;
        piVar1[arg_7] = *piVar3 - *piVar2 >> 1;
        piVar1 = piVar1 + arg_7 * 2;
        piVar2 = piVar2 + 1;
      }
      arg_2 = piVar2 + 1;
      *arg_3 = *piVar2 + *arg_1 >> 1;
      arg_3[arg_7] = *arg_1 - *piVar2 >> 1;
      iStack_4 = iStack_4 + -1;
      arg_1 = piVar3;
      arg_3 = arg_3 + 1;
    } while (iStack_4 != 0);
  }
  return;
}



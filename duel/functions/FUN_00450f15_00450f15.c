/*
 * Decompiled function: FUN_00450f15
 * Entry Point: 00450f15
 * Size: 69 bytes
 */
#include "duel.h"


undefined4 FUN_00450f15(int *arg_1,int arg_2,undefined4 arg_3,int arg_4,undefined4 arg_5)

{
  undefined4 uVar1;
  
  if (DAT_0066aaf4 == 1) {
    uVar1 = 1;
  }
  else {
    uVar1 = Ai_ScoreCardPlay_004afa69(arg_1,0,arg_2,arg_3,arg_4,arg_5);
  }
  return uVar1;
}



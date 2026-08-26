/*
 * Decompiled function: FUN_00450f5a
 * Entry Point: 00450f5a
 * Size: 71 bytes
 */
#include "duel.h"


undefined4 FUN_00450f5a(int *arg_1,int arg_2,int arg_3,undefined4 arg_4,int arg_5,undefined4 arg_6)

{
  undefined4 uVar1;
  
  if (DAT_0066aaf4 == 1) {
    uVar1 = 1;
  }
  else {
    uVar1 = Ai_ScoreCardPlay_004afa69(arg_1,arg_2,arg_3,arg_4,arg_5,arg_6);
  }
  return uVar1;
}



/*
 * Decompiled function: FUN_00435c74
 * Entry Point: 00435c74
 * Size: 65 bytes
 */
#include "duel.h"


void FUN_00435c74(undefined4 *arg1,int arg2)

{
  undefined4 uVar1;
  
  uVar1 = *arg1;
  FID_conflict__memcpy(arg1,arg1 + 1,arg2 * 4 - 4);
  arg1[arg2 + -1] = uVar1;
  return;
}



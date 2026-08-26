/*
 * Decompiled function: FUN_00432c2a
 * Entry Point: 00432c2a
 * Size: 67 bytes
 */
#include "duel.h"


bool FUN_00432c2a(int arg_1,void *arg_2,uint arg_3)

{
  int iVar1;
  
  iVar1 = __write(arg_1,arg_2,arg_3);
  if (iVar1 == -1) {
    DAT_00515ea4 = DAT_00509420;
  }
  return iVar1 != -1;
}



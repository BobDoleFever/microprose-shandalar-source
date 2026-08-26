/*
 * Decompiled function: FUN_00486c12
 * Entry Point: 00486c12
 * Size: 113 bytes
 */
#include "duel.h"


int FUN_00486c12(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  
  if (arg_1 == -1) {
    iVar1 = 0;
  }
  else if ((arg_2 == -1) || (arg_3 == -1)) {
    iVar1 = 0;
  }
  else if (*(int *)(&DAT_00618b04 + arg_1 * 0x98) < 2) {
    iVar1 = 0;
  }
  else {
    iVar1 = (arg_2 + arg_3) % *(int *)(&DAT_00618b04 + arg_1 * 0x98);
  }
  return iVar1;
}



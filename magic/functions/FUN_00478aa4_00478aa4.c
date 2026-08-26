/*
 * Decompiled function: FUN_00478aa4
 * Entry Point: 00478aa4
 * Size: 113 bytes
 */
#include "magic.h"


int FUN_00478aa4(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  
  if (arg_1 == -1) {
    iVar1 = 0;
  }
  else if ((arg_2 == -1) || (arg_3 == -1)) {
    iVar1 = 0;
  }
  else if (*(int *)(&DAT_006b30b4 + arg_1 * 0x98) < 2) {
    iVar1 = 0;
  }
  else {
    iVar1 = (arg_3 + arg_2) % *(int *)(&DAT_006b30b4 + arg_1 * 0x98);
  }
  return iVar1;
}



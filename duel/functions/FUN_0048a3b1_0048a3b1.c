/*
 * Decompiled function: FUN_0048a3b1
 * Entry Point: 0048a3b1
 * Size: 114 bytes
 */
#include "duel.h"


undefined4 FUN_0048a3b1(int arg1,int arg2)

{
  undefined4 uVar1;
  
  if (*(int *)(&DAT_006826c4 + arg2 * 0x120 + arg1 * 0x5b20) == -1) {
    uVar1 = 0;
  }
  else if (((byte)*(undefined4 *)(&DAT_006826cc + arg2 * 0x120 + arg1 * 0x5b20) & 0x1e) == 2) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



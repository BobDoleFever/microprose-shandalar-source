/*
 * Decompiled function: FUN_00450b13
 * Entry Point: 00450b13
 * Size: 111 bytes
 */
#include "duel.h"


undefined1 FUN_00450b13(int arg1,int arg2)

{
  undefined1 uVar1;
  
  if (*(int *)(&DAT_006826c4 + arg2 * 0x120 + arg1 * 0x5b20) == -1) {
    uVar1 = 0;
  }
  else {
    uVar1 = (&DAT_004ff594)[*(int *)(&DAT_006826c4 + arg2 * 0x120 + arg1 * 0x5b20) * 0x34];
  }
  return uVar1;
}



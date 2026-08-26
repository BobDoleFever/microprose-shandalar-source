/*
 * Decompiled function: FUN_00450d1b
 * Entry Point: 00450d1b
 * Size: 108 bytes
 */
#include "duel.h"


int FUN_00450d1b(int arg1,int arg2)

{
  int iVar1;
  
  if (*(int *)(&DAT_006826c4 + arg1 * 0x5b20 + arg2 * 0x120) == -1) {
    iVar1 = 0;
  }
  else {
    iVar1 = (int)(char)(&DAT_004ff597)
                       [*(int *)(&DAT_006826c4 + arg1 * 0x5b20 + arg2 * 0x120) * 0x34];
  }
  return iVar1;
}



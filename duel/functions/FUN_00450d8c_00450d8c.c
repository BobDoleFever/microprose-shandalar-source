/*
 * Decompiled function: FUN_00450d8c
 * Entry Point: 00450d8c
 * Size: 108 bytes
 */
#include "duel.h"


int FUN_00450d8c(int arg1,int arg2)

{
  int iVar1;
  
  if (*(int *)(&DAT_006826c4 + arg2 * 0x120 + arg1 * 0x5b20) == -1) {
    iVar1 = 0;
  }
  else {
    iVar1 = (int)(char)(&DAT_004ff598)
                       [*(int *)(&DAT_006826c4 + arg2 * 0x120 + arg1 * 0x5b20) * 0x34];
  }
  return iVar1;
}



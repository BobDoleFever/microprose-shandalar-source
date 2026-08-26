/*
 * Decompiled function: FUN_0048a2cd
 * Entry Point: 0048a2cd
 * Size: 114 bytes
 */
#include "duel.h"


bool FUN_0048a2cd(int arg1,int arg2)

{
  bool bVar1;
  
  if (*(int *)(&DAT_006826c4 + arg1 * 0x5b20 + arg2 * 0x120) == -1) {
    bVar1 = false;
  }
  else {
    bVar1 = ((byte)*(undefined4 *)(&DAT_006826cc + arg1 * 0x5b20 + arg2 * 0x120) & 0x22) != 2;
  }
  return bVar1;
}



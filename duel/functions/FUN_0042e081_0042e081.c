/*
 * Decompiled function: FUN_0042e081
 * Entry Point: 0042e081
 * Size: 71 bytes
 */
#include "duel.h"


bool FUN_0042e081(int arg1,int arg2)

{
  int iVar1;
  
  iVar1 = DAT_004f3b2c;
  if (0 < DAT_004f3b2c) {
    *(int *)(&DAT_0050b250 + (DAT_004f3b2c + -1) * 0x1c + arg1 * 4) =
         *(int *)(&DAT_0050b250 + (DAT_004f3b2c + -1) * 0x1c + arg1 * 4) + arg2;
  }
  return 0 < iVar1;
}



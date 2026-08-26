/*
 * Decompiled function: FUN_004395d6
 * Entry Point: 004395d6
 * Size: 131 bytes
 */
#include "duel.h"


void FUN_004395d6(int arg1,int arg2)

{
  int iVar1;
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (0x4f < local_8) {
      return;
    }
    if ((0 < (int)(&DAT_004f71c4)[arg1 * 0xa0 + local_8 * 2]) &&
       (iVar1 = FUN_004d7d5e(*(int *)(&DAT_004f71c0 + local_8 * 8 + arg1 * 0x280)), iVar1 == arg2))
    break;
    local_8 = local_8 + 1;
  }
  (&DAT_004f71c4)[arg1 * 0xa0 + local_8 * 2] = (&DAT_004f71c4)[arg1 * 0xa0 + local_8 * 2] + -1;
  return;
}



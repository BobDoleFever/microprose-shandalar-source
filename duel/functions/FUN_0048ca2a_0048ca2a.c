/*
 * Decompiled function: FUN_0048ca2a
 * Entry Point: 0048ca2a
 * Size: 159 bytes
 */
#include "duel.h"


bool FUN_0048ca2a(int arg1,int arg2)

{
  bool bVar1;
  
  if (((&DAT_004ff5a9)[*(int *)(&DAT_006826c4 + arg2 * 0x120 + arg1 * 0x5b20) * 0x34] & 0x10) == 0)
  {
    bVar1 = false;
  }
  else {
    bVar1 = ((&DAT_004ff5a8)[*(int *)(&DAT_006826c4 + arg2 * 0x120 + arg1 * 0x5b20) * 0x34] & 1) ==
            0;
  }
  return bVar1;
}



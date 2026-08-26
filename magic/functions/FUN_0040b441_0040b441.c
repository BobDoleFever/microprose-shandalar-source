/*
 * Decompiled function: FUN_0040b441
 * Entry Point: 0040b441
 * Size: 167 bytes
 */
#include "magic.h"


void FUN_0040b441(int *arg1,int arg2)

{
  int iVar1;
  int local_8;
  
  if ((DAT_00522458 != 0x280) && (arg1[4] == *arg1)) {
    for (local_8 = 0; local_8 < arg2; local_8 = local_8 + 1) {
      iVar1 = Ai_Util_004c3bc4(arg1[4]);
      arg1[4] = iVar1;
      iVar1 = Ai_Util_004c3bc4(arg1[5]);
      arg1[5] = iVar1;
      iVar1 = Ai_Util_004c3bc4(arg1[6]);
      arg1[6] = iVar1;
      iVar1 = Ai_Util_004c3bc4(arg1[7]);
      arg1[7] = iVar1;
      arg1 = arg1 + 0x15;
    }
  }
  return;
}



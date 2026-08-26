/*
 * Decompiled function: FUN_00461715
 * Entry Point: 00461715
 * Size: 175 bytes
 */
#include "duel.h"


undefined4 FUN_00461715(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  
  if (((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 2) != 0) {
    iVar1 = FUN_004af74c(arg_1,arg_2,2);
    if (*(int *)(&DAT_0068ef50 + iVar1 * 4 + arg_1 * 0x20) == 0) {
      FUN_0046e571(arg_1,arg_2,2);
    }
  }
  if (arg_3 == 0x79) {
    iVar1 = FUN_004af74c(arg_1,arg_2,2);
    if (*(int *)(&DAT_0068ef50 + iVar1 * 4 + (1 - arg_1) * 0x20) == 0) {
      DAT_0066642c = 1;
    }
  }
  return 0;
}



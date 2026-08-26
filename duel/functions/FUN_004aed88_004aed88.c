/*
 * Decompiled function: FUN_004aed88
 * Entry Point: 004aed88
 * Size: 117 bytes
 */
#include "duel.h"


undefined4 FUN_004aed88(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  
  if (arg_3 == 0x74) {
    if (arg_1 == DAT_00676510) {
      uVar1 = 1;
    }
    else {
      uVar1 = *(undefined4 *)(&DAT_0068ee98 + arg_1 * 4);
    }
  }
  else {
    if (arg_3 == 0x71) {
      (&DAT_00681ea8)[arg_1] = (&DAT_00681ea8)[arg_1] + *(int *)(&DAT_0068ee98 + arg_1 * 4) * 2;
      FUN_0046e571(arg_1,arg_2,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}



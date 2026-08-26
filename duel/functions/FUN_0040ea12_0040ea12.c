/*
 * Decompiled function: FUN_0040ea12
 * Entry Point: 0040ea12
 * Size: 197 bytes
 */
#include "duel.h"


undefined4 FUN_0040ea12(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int arg_2_00;
  
  if (arg_3 == 0x73) {
    if ((((&DAT_0066aad0)[arg_1 * 4] & 2) == 0) ||
       (((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) != 0)) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  else {
    if (arg_3 == 0x6d) {
      arg_2_00 = FUN_00468383(arg_1);
      if (arg_2_00 == -1) {
        DAT_00681ea4 = 1;
      }
      else {
        FUN_0046e571(arg_1,arg_2_00,3);
      }
    }
    if (arg_3 == 0x72) {
      FUN_0049b235(arg_1,0,2);
    }
    uVar1 = 0;
  }
  return uVar1;
}



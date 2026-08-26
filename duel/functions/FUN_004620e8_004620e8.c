/*
 * Decompiled function: FUN_004620e8
 * Entry Point: 004620e8
 * Size: 348 bytes
 */
#include "duel.h"


undefined4 FUN_004620e8(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (arg_3 == 0x73) {
    if (((*(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) & 0x20010) == 0) &&
       (((&DAT_0066aad0)[arg_1 * 4] & 0x40) != 0)) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else if (arg_3 == 0x90) {
    FUN_0043071d(1);
    uVar1 = 0;
  }
  else {
    if (arg_3 == 0x6d) {
      iVar2 = FUN_00468a84(arg_1);
      if (iVar2 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        FUN_00461047(arg_1,arg_2);
      }
      *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
    }
    if (arg_3 == 0x72) {
      FUN_004612b0(arg_1,arg_2,0x72,2);
      (&DAT_006827b8)
      [*(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
       *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20] = 0;
    }
    uVar1 = 0;
  }
  return uVar1;
}



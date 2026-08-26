/*
 * Decompiled function: FUN_004cdd9b
 * Entry Point: 004cdd9b
 * Size: 212 bytes
 */
#include "duel.h"


undefined4 FUN_004cdd9b(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else if (arg_3 == 0x73) {
    if ((DAT_00676504 == arg_1) && ((&DAT_00681ea8)[arg_1] == 2)) {
      uVar1 = 0;
    }
    else {
      iVar2 = FUN_0049b68d(arg_1,arg_2,1,1);
      if ((iVar2 == 0) || ((int)(&DAT_00681ea8)[arg_1] < 2)) {
        uVar1 = 0;
      }
      else {
        uVar1 = 1;
      }
    }
  }
  else {
    if (arg_3 == 0x6d) {
      FUN_0042ecaf(arg_1,arg_2,1,1);
    }
    if (arg_3 == 0x72) {
      FUN_00487ce1(arg_1);
      (&DAT_00681ea8)[arg_1] = (&DAT_00681ea8)[arg_1] + -2;
    }
    uVar1 = 0;
  }
  return uVar1;
}



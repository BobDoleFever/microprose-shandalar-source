/*
 * Decompiled function: FUN_004a9944
 * Entry Point: 004a9944
 * Size: 176 bytes
 */
#include "duel.h"


undefined4 FUN_004a9944(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (arg_3 == 0x71) {
      DAT_005dcd78 = arg_1;
      DAT_005dcd74 = arg_2;
      FUN_00467d65(FUN_004a99f4,1 - DAT_00666458);
      FUN_0046e571(arg_1,arg_2,1);
    }
    if (arg_3 == 0x3b) {
      iVar2 = FUN_0049b309(arg_1,5,1);
      if (iVar2 != 0) {
        iVar2 = FUN_0049b309(arg_1,7,2);
        if (iVar2 != 0) {
          *(int *)(&DAT_00666738 + arg_1 * 4) = *(int *)(&DAT_00666738 + arg_1 * 4) + 3;
        }
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}



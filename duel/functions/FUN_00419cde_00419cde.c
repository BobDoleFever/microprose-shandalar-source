/*
 * Decompiled function: FUN_00419cde
 * Entry Point: 00419cde
 * Size: 320 bytes
 */
#include "duel.h"


undefined4 FUN_00419cde(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  undefined4 uVar2;
  int local_c;
  int local_8;
  
  if (arg_3 == 0x73) {
    iVar1 = FUN_0049b309(arg_1,7,1);
    if ((iVar1 == 0) || (((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) != 0)) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  else {
    if (((arg_3 == 0x6d) && (iVar1 = FUN_0049b309(arg_1,7,1), iVar1 != 0)) &&
       (Ai_CalcManaRequirement_004ba890(arg_1,0,1), DAT_00681ea4 != 1)) {
      for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
        for (local_c = 0; local_c < (int)(&DAT_00666408)[local_8]; local_c = local_c + 1) {
          iVar1 = FUN_0048a33f(local_8,local_c);
          if ((iVar1 != 0) && (iVar1 = FUN_00439892(3), iVar1 == 0)) {
            FUN_0046e571(local_8,local_c,2);
          }
        }
      }
      FUN_0046e571(arg_1,arg_2,2);
    }
    uVar2 = 0;
  }
  return uVar2;
}



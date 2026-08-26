/*
 * Decompiled function: FUN_004a7f64
 * Entry Point: 004a7f64
 * Size: 249 bytes
 */
#include "duel.h"


undefined4 FUN_004a7f64(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  int local_c;
  int local_8;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (arg_3 == 0x71) {
      for (local_c = 0; local_c < 2; local_c = local_c + 1) {
        for (local_8 = 0; local_8 < (int)(&DAT_00666408)[local_c]; local_8 = local_8 + 1) {
          iVar2 = FUN_0048a33f(local_c,local_8);
          if ((iVar2 != 0) &&
             (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + local_8 * 0x120 + local_c * 0x5b20) * 0x34]
              & 2) != 0)) {
            FUN_004a2b00(arg_1,arg_2,DAT_0068f10c,local_c,local_8);
          }
        }
      }
      FUN_0046e571(arg_1,arg_2,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}



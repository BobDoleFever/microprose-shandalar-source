/*
 * Decompiled function: FUN_00417b09
 * Entry Point: 00417b09
 * Size: 176 bytes
 */
#include "magic.h"


undefined4 FUN_00417b09(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (arg_3 == 0x71) {
      DAT_00538740 = arg_1;
      DAT_0053873c = arg_2;
      CardQuery_ForEachPermanent(FUN_00417bb9,1 - g_DefendingPlayer);
      Pic_Subsystem_0044867e(arg_1,arg_2,1);
    }
    if (arg_3 == 0x3b) {
      iVar2 = FUN_0040d949(arg_1,5,1);
      if (iVar2 != 0) {
        iVar2 = FUN_0040d949(arg_1,7,2);
        if (iVar2 != 0) {
          *(int *)(&DAT_00695eb8 + arg_1 * 4) = *(int *)(&DAT_00695eb8 + arg_1 * 4) + 3;
        }
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}



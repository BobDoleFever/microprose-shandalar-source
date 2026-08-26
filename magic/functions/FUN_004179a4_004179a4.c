/*
 * Decompiled function: FUN_004179a4
 * Entry Point: 004179a4
 * Size: 179 bytes
 */
#include "magic.h"


undefined4 FUN_004179a4(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (arg_3 == 0x71) {
      DAT_00538728 = arg_1;
      DAT_0053872c = arg_2;
      CardQuery_ForEachPermanent(FUN_00417a57,g_DefendingPlayer);
      Pic_Subsystem_0044867e(arg_1,arg_2,1);
    }
    if (arg_3 == 0x3b) {
      iVar2 = FUN_0040d949(arg_1,5,2);
      if (iVar2 != 0) {
        iVar2 = FUN_0040d949(arg_1,7,3);
        if (iVar2 != 0) {
          *(int *)(&DAT_00695eb0 + arg_1 * 4) = *(int *)(&DAT_00695eb0 + arg_1 * 4) + 1;
          *(int *)(&DAT_00695eb8 + arg_1 * 4) = *(int *)(&DAT_00695eb8 + arg_1 * 4) + 1;
        }
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}



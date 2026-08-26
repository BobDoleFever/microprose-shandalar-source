/*
 * Decompiled function: FUN_004cde6f
 * Entry Point: 004cde6f
 * Size: 366 bytes
 */
#include "duel.h"


undefined4 FUN_004cde6f(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else if (arg_3 == 0x73) {
    uVar1 = FUN_0049b68d(arg_1,arg_2,1,1);
  }
  else {
    if (arg_3 == 0x6d) {
      iVar2 = FUN_0049b68d(arg_1,arg_2,1,1);
      if (iVar2 != 0) {
        FUN_0042ecaf(arg_1,arg_2,1,1);
      }
    }
    if (arg_3 == 0x72) {
      Mem_AllocOrFree_004afd1c(1 - arg_1,1,DAT_00690af0,DAT_0068efa0);
      Mem_AllocOrFree_004afd1c(arg_1,1,DAT_00690af0,DAT_0068efa0);
      FUN_00467d65(FUN_004cdfdd,-1);
    }
    if ((((DAT_0068f230 == 0xcd) && (DAT_00690c48 == arg_2)) && (arg_1 == DAT_0068ecb0)) &&
       (arg_1 == DAT_00681ec4)) {
      if (arg_3 == 0x7d) {
        DAT_0066642c = DAT_0066642c | 2;
      }
      if (arg_3 == 0x7e) {
        iVar2 = FUN_00467cce(arg_1,2);
        if (iVar2 == 0) {
          iVar2 = FUN_00467cce(1 - arg_1,2);
          if (iVar2 == 0) {
            FUN_0046e571(arg_1,arg_2,2);
          }
        }
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}



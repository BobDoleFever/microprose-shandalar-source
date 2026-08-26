/*
 * Decompiled function: FUN_004605f8
 * Entry Point: 004605f8
 * Size: 343 bytes
 */
#include "duel.h"


undefined4 FUN_004605f8(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  int local_8;
  
  if (((arg_3 == 2) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) {
    DAT_0066642c = DAT_0066642c | 2;
  }
  if ((arg_2 == DAT_00690c48) && (arg_1 == DAT_0068ecb0)) {
    iVar1 = FUN_00467cce(arg_1,1);
    if (iVar1 == 0) {
      FUN_0046e571(arg_1,arg_2,2);
    }
  }
  if ((((arg_3 == 4) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) || (arg_3 == 199)) {
    Mem_AllocOrFree_004d9630((uint *)&DAT_005f6810,(uint *)s_Pick_a_land__004f8bb8);
    do {
    } while (local_8 == -1);
    if (local_8 != -1) {
      if (((&DAT_006826dc)[local_8 * 0x120 + arg_1 * 0x5b20] & 4) != 0) {
        Mem_AllocOrFree_004afd1c(arg_1,3,arg_1,arg_2);
      }
      FUN_0046e571(arg_1,local_8,3);
    }
    iVar1 = FUN_00467cce(arg_1,1);
    if (iVar1 == 0) {
      FUN_0046e571(arg_1,arg_2,2);
    }
  }
  return 0;
}



/*
 * Decompiled function: FUN_00413dc5
 * Entry Point: 00413dc5
 * Size: 429 bytes
 */
#include "duel.h"


undefined4 FUN_00413dc5(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (((arg_3 == 0x6c) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) {
    DAT_0068f2d4 = DAT_0068f2d4 + *(int *)(&DAT_0068ef6c + DAT_00676504 * 0x20) * 2;
  }
  if (arg_3 == 0x73) {
    if (((((&DAT_006826ce)[arg_1 * 0x5b20 + arg_2 * 0x120] & 3) == 0) ||
        (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x34] & 2) == 0
        )) && (((&DAT_006826cc)[arg_1 * 0x5b20 + arg_2 * 0x120] & 0x10) == 0)) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    if (arg_3 == 0x6d) {
      *(uint *)(&DAT_006826cc + arg_1 * 0x5b20 + arg_2 * 0x120) =
           *(uint *)(&DAT_006826cc + arg_1 * 0x5b20 + arg_2 * 0x120) | 0x10;
    }
    if (arg_3 == 0x72) {
      FUN_0049b235(arg_1,0,2);
    }
    if (((arg_3 == 2) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) {
      DAT_0066642c = DAT_0066642c | 2;
    }
    if (((arg_3 == 4) && (arg_2 == DAT_00690c48)) &&
       ((arg_1 == DAT_0068ecb0 && (iVar2 = FUN_00439892(2), iVar2 != 0)))) {
      Mem_AllocOrFree_004afd1c(arg_1,3,arg_1,arg_2);
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: FUN_004020ca
 * Entry Point: 004020ca
 * Size: 379 bytes
 */
#include "duel.h"


undefined4 FUN_004020ca(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  int local_c;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (((arg_3 == 0x6c) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) {
      if ((arg_1 == DAT_00676510) && (DAT_0066aaf4 != 1)) {
        FUN_00451c55();
        iVar2 = FUN_004512d1(arg_1,s_Darkpact__Swap_ante_004f20d4,0,s_Swap_my_ante_004f20c4,
                             s_Swap_opponent_s_ante_004f20ac,(char *)0x0);
        if (iVar2 == 0) {
          local_c = arg_1;
        }
        else {
          local_c = 1 - arg_1;
        }
      }
      else {
        local_c = arg_1;
      }
      *(int *)(&DAT_006826e4 + arg_1 * 0x5b20 + arg_2 * 0x120) = local_c;
    }
    if (arg_3 == 0x71) {
      if (*(int *)(&DAT_006669f0 + arg_1 * 2000) != -1) {
        uVar1 = (&DAT_0068ed50)[*(int *)(&DAT_006826e4 + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x10];
        (&DAT_0068ed50)[*(int *)(&DAT_006826e4 + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x10] =
             *(undefined4 *)(&DAT_006669f0 + arg_1 * 2000);
        *(undefined4 *)(&DAT_006669f0 + arg_1 * 2000) = uVar1;
      }
      FUN_0046e571(arg_1,arg_2,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: FUN_004c68a5
 * Entry Point: 004c68a5
 * Size: 229 bytes
 */
#include "duel.h"


undefined4 FUN_004c68a5(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (((arg_3 == 0x6c) && (DAT_00690c48 == arg_2)) && (DAT_0068ecb0 == arg_1)) {
      DAT_0068f2d4 = DAT_0068f2d4 + *(int *)(&DAT_0068ee80 + arg_1 * 4) * 0xc;
    }
    if (((arg_3 == 0x32) &&
        (((&DAT_006826cc)[DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120] & 4) != 0)) &&
       ((arg_1 == DAT_00666458 &&
        ((DAT_0068ecb0 == arg_1 &&
         (((byte)*(undefined4 *)(&DAT_006826cc + arg_1 * 0x5b20 + arg_2 * 0x120) & 0x22) == 2))))))
    {
      DAT_0066642c = DAT_0066642c + 1;
    }
    uVar1 = 0;
  }
  return uVar1;
}



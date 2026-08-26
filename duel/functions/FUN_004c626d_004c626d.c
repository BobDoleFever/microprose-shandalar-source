/*
 * Decompiled function: FUN_004c626d
 * Entry Point: 004c626d
 * Size: 438 bytes
 */
#include "duel.h"


undefined4 FUN_004c626d(int arg_1,int arg_2,int arg_3)

{
  char cVar1;
  byte bVar2;
  undefined4 uVar3;
  
  if (arg_3 == 0x74) {
    uVar3 = 1;
  }
  else {
    if (((arg_3 == 0x32) || (arg_3 == 0x33)) &&
       (((byte)*(undefined4 *)(&DAT_006826cc + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120) & 0x22)
        == 2)) {
      cVar1 = (&DAT_006826dd)[DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120];
      bVar2 = FUN_004af7bb(arg_1,arg_2,2);
      if ((1 << (bVar2 & 0x1f) & (int)cVar1) != 0) {
        DAT_0066642c = DAT_0066642c + 1;
      }
    }
    if (((arg_3 == 0x85) && (DAT_00690c48 == arg_2)) &&
       ((DAT_0068ecb0 == arg_1 && ((DAT_00666458 == arg_1 && (DAT_00681eb4 == arg_1)))))) {
      *(uint *)(&DAT_006827d4 + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&DAT_006827d4 + arg_2 * 0x120 + arg_1 * 0x5b20) | 1;
      (&DAT_006827da)[arg_2 * 0x120 + arg_1 * 0x5b20] =
           (&DAT_006827da)[arg_2 * 0x120 + arg_1 * 0x5b20] + '\x02';
    }
    if (arg_3 == 0x86) {
      FUN_0046e571(DAT_00690af0,DAT_0068efa0,1);
    }
    if ((arg_3 == 199) && ((int)(&DAT_0068ef58)[arg_1 * 8] < 2)) {
      FUN_0046e571(arg_1,arg_2,1);
    }
    uVar3 = 0;
  }
  return uVar3;
}



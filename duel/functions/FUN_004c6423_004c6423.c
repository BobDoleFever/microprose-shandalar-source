/*
 * Decompiled function: FUN_004c6423
 * Entry Point: 004c6423
 * Size: 220 bytes
 */
#include "duel.h"


undefined4 FUN_004c6423(int arg_1,int arg_2,int arg_3)

{
  char cVar1;
  byte bVar2;
  undefined4 uVar3;
  
  if (arg_3 == 0x74) {
    uVar3 = 1;
  }
  else {
    if ((((arg_3 == 0x32) || (arg_3 == 0x33)) &&
        (((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x20) == 0)) &&
       (((byte)*(undefined4 *)(&DAT_006826cc + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120) & 0x22)
        == 2)) {
      cVar1 = (&DAT_006826dd)[DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120];
      bVar2 = FUN_004af7bb(arg_1,arg_2,1);
      if ((1 << (bVar2 & 0x1f) & (int)cVar1) != 0) {
        DAT_0066642c = DAT_0066642c + 1;
      }
    }
    uVar3 = 0;
  }
  return uVar3;
}



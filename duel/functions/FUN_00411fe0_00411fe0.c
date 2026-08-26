/*
 * Decompiled function: FUN_00411fe0
 * Entry Point: 00411fe0
 * Size: 371 bytes
 */
#include "duel.h"


undefined4 FUN_00411fe0(int arg_1,int arg_2,int arg_3)

{
  char cVar1;
  byte bVar2;
  int arg_2_00;
  int arg_3_00;
  
  if (((arg_3 == 0x33) || (arg_3 == 0x32)) &&
     (((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0)) {
    cVar1 = (&DAT_006826dc)[DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20];
    bVar2 = FUN_004af7bb(arg_1,arg_2,4);
    if ((1 << (bVar2 & 0x1f) & (int)cVar1) != 0) {
      DAT_0066642c = DAT_0066642c + 1;
    }
  }
  if (((arg_3 == 0x7c) && (((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0)) &&
     (((&DAT_004ff594)
       [*(int *)(&DAT_006826c4 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) * 0x34] & 1) != 0)) {
    cVar1 = (&DAT_006826dc)[DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20];
    bVar2 = FUN_004af74c(arg_1,arg_2,4);
    if ((1 << (bVar2 & 0x1f) & (int)cVar1) != 0) {
      arg_3_00 = 1;
      arg_2_00 = FUN_004af74c(arg_1,arg_2,4);
      FUN_0049b235(DAT_0068ecb0,arg_2_00,arg_3_00);
    }
  }
  return 0;
}



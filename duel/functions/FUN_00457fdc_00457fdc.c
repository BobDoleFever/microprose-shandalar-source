/*
 * Decompiled function: FUN_00457fdc
 * Entry Point: 00457fdc
 * Size: 661 bytes
 */
#include "duel.h"


undefined4 FUN_00457fdc(int arg_1,int arg_2,int arg_3)

{
  uint uVar1;
  char cVar2;
  
  if (((arg_3 == 0x34) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) {
    cVar2 = FUN_004af7bb(arg_1,arg_2,1);
    DAT_0066642c = DAT_0066642c | 0x800 << (cVar2 - 1U & 0x1f);
    uVar1 = DAT_0066642c;
    FUN_00464d69(arg_1,arg_2,1);
    DAT_0066642c = uVar1;
  }
  if ((((arg_3 == 0x6e) &&
       (*(int *)(&DAT_006826c4 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) == DAT_0068f104)) &&
      ((*(int *)(&DAT_006826e8 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) == -1 &&
       (((char)(&DAT_006826d3)[DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20] == arg_1 &&
        (*(int *)(&DAT_006826ec + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) == arg_2)))))) &&
     (*(int *)(&DAT_006826e4 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) != 0)) {
    *(undefined4 *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = 1;
  }
  if (((((DAT_0068f230 == 0xcd) || (arg_3 == 199)) && (arg_2 == DAT_00690c48)) &&
      ((arg_1 == DAT_0068ecb0 && (*(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) != 0))))
     && (arg_1 == DAT_00681ec4)) {
    if (arg_3 == 0x7d) {
      DAT_0066642c = DAT_0066642c | 2;
    }
    if ((arg_3 == 0x7e) || (arg_3 == 199)) {
      FUN_00467e37(arg_1,arg_2);
      *(short *)(&DAT_006826d8 + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(short *)(&DAT_006826d8 + arg_2 * 0x120 + arg_1 * 0x5b20) + 1;
      *(short *)(&DAT_006826da + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(short *)(&DAT_006826da + arg_2 * 0x120 + arg_1 * 0x5b20) + 1;
      *(undefined4 *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
    }
  }
  return 0;
}



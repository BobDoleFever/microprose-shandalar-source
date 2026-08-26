/*
 * Decompiled function: FUN_004564bd
 * Entry Point: 004564bd
 * Size: 596 bytes
 */
#include "duel.h"


undefined4 FUN_004564bd(int arg_1,int arg_2,int arg_3)

{
  if ((((arg_3 == 0x80) && ((DAT_00681eb0._1_1_ & 2) != 0)) &&
      ((char)(&DAT_006826d2)[DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20] == arg_1)) &&
     ((*(int *)(&DAT_006826e8 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) == arg_2 &&
      (0 < *(short *)(&DAT_006826d0 + arg_2 * 0x120 + arg_1 * 0x5b20))))) {
    *(undefined4 *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = 1;
  }
  if (((DAT_0068f230 == 0xd7) && (arg_2 == DAT_00690c48)) &&
     ((arg_1 == DAT_0068ecb0 && (0 < *(short *)(&DAT_006826d0 + arg_2 * 0x120 + arg_1 * 0x5b20)))))
  {
    *(undefined4 *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = 1;
  }
  if (((((DAT_0068f230 == 0xcd) || (arg_3 == 199)) && (arg_2 == DAT_00690c48)) &&
      ((arg_1 == DAT_0068ecb0 && (*(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) != 0))))
     && (DAT_00681ec4 == arg_1)) {
    if (arg_3 == 0x7d) {
      DAT_0066642c = DAT_0066642c | 2;
    }
    if ((arg_3 == 0x7e) || (arg_3 == 199)) {
      *(short *)(&DAT_006826d8 + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(short *)(&DAT_006826d8 + arg_2 * 0x120 + arg_1 * 0x5b20) + 1;
      *(short *)(&DAT_006826da + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(short *)(&DAT_006826da + arg_2 * 0x120 + arg_1 * 0x5b20) + 1;
      FUN_00467f65(arg_1,arg_2,1);
      *(undefined4 *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
    }
  }
  return 0;
}



/*
 * Decompiled function: FUN_004a2d31
 * Entry Point: 004a2d31
 * Size: 622 bytes
 */
#include "duel.h"


undefined4 FUN_004a2d31(int arg_1,int arg_2,int arg_3)

{
  if (((*(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) == DAT_00690c48) &&
      ((char)(&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] == DAT_0068ecb0)) &&
     (DAT_00690c48 != -1)) {
    if ((((&DAT_006826e6)[arg_2 * 0x120 + arg_1 * 0x5b20] & 8) != 0) &&
       (*(int *)(&DAT_006826ec + arg_2 * 0x120 + arg_1 * 0x5b20) != -1)) {
      *(ushort *)(&DAT_006826d8 + arg_2 * 0x120 + arg_1 * 0x5b20) =
           (ushort)*(undefined4 *)
                    (&DAT_006826e4 +
                    *(int *)(&DAT_006826ec + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                    (char)(&DAT_006826d3)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) & 0xff;
      *(ushort *)(&DAT_006826da + arg_2 * 0x120 + arg_1 * 0x5b20) =
           (ushort)((uint)*(undefined4 *)
                           (&DAT_006826e4 +
                           *(int *)(&DAT_006826ec + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                           (char)(&DAT_006826d3)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) >> 8) &
           0xff;
    }
    if (arg_3 == 0x32) {
      DAT_0066642c = DAT_0066642c + *(short *)(&DAT_006826d8 + arg_2 * 0x120 + arg_1 * 0x5b20);
    }
    if (arg_3 == 0x33) {
      DAT_0066642c = DAT_0066642c + *(short *)(&DAT_006826da + arg_2 * 0x120 + arg_1 * 0x5b20);
    }
  }
  if ((((&DAT_006826f8)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x20) == 0) &&
     ((arg_3 == 0x22 || (arg_3 == 199)))) {
    FUN_0046e571(arg_1,arg_2,1);
  }
  return 0;
}



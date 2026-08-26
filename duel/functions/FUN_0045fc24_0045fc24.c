/*
 * Decompiled function: FUN_0045fc24
 * Entry Point: 0045fc24
 * Size: 939 bytes
 */
#include "duel.h"


undefined4 FUN_0045fc24(int arg_1,int arg_2,int arg_3)

{
  int arg_3_00;
  int local_8;
  
  if ((((arg_3 == 0x6e) &&
       (*(int *)(&DAT_006826c4 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) == DAT_0068f104)) &&
      ((char)(&DAT_006826d3)[DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20] == arg_1)) &&
     ((*(int *)(&DAT_006826ec + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) == arg_2 &&
      (*(int *)(&DAT_006826e4 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) != 0)))) {
    (&DAT_006826d3)[arg_2 * 0x120 + arg_1 * 0x5b20] = (undefined1)DAT_0068ecb0;
    *(int *)(&DAT_006826ec + arg_2 * 0x120 + arg_1 * 0x5b20) = DAT_00690c48;
  }
  if (((DAT_0068f230 == 0xd7) && (DAT_00690c48 == arg_2)) &&
     ((DAT_0068ecb0 == arg_1 &&
      (((&DAT_006826d3)[arg_2 * 0x120 + arg_1 * 0x5b20] != -1 && (DAT_00681ec4 == arg_1)))))) {
    if (arg_3 == 0x7d) {
      DAT_0066642c = DAT_0066642c | 2;
    }
    if (arg_3 == 0x7e) {
      local_8 = *(int *)(&DAT_006826e4 +
                        *(int *)(&DAT_006826ec + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                        (char)(&DAT_006826d3)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20);
      if (*(int *)(&DAT_006826e8 +
                  *(int *)(&DAT_006826ec + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                  (char)(&DAT_006826d3)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) != -1) {
        arg_3_00 = FUN_0048b81a((int)(char)(&DAT_006826d2)
                                           [*(int *)(&DAT_006826ec + arg_2 * 0x120 + arg_1 * 0x5b20)
                                            * 0x120 + (char)(&DAT_006826d3)
                                                            [arg_2 * 0x120 + arg_1 * 0x5b20] *
                                                      0x5b20],
                                *(int *)(&DAT_006826e8 +
                                        *(int *)(&DAT_006826ec + arg_2 * 0x120 + arg_1 * 0x5b20) *
                                        0x120 + (char)(&DAT_006826d3)
                                                      [arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20),
                                0x33,0xffffffff);
        local_8 = FUN_0049aa14(*(int *)(&DAT_006826e4 +
                                       *(int *)(&DAT_006826ec + arg_2 * 0x120 + arg_1 * 0x5b20) *
                                       0x120 + (char)(&DAT_006826d3)[arg_2 * 0x120 + arg_1 * 0x5b20]
                                               * 0x5b20),0,arg_3_00);
      }
      (&DAT_00681ea8)[arg_1] = (&DAT_00681ea8)[arg_1] + local_8;
      (&DAT_006826d3)[arg_2 * 0x120 + arg_1 * 0x5b20] = 0xff;
    }
  }
  return 0;
}



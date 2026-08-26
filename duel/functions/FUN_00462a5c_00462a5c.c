/*
 * Decompiled function: FUN_00462a5c
 * Entry Point: 00462a5c
 * Size: 1614 bytes
 */
#include "duel.h"


undefined4 FUN_00462a5c(int arg_1,int arg_2,int arg_3)

{
  bool bVar1;
  int local_c;
  int local_8;
  
  if (((((arg_3 == 0x6e) &&
        (*(int *)(&DAT_006826c4 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) == DAT_0068f104)) &&
       (*(int *)(&DAT_006826e4 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) != 0)) &&
      ((*(int *)(&DAT_006826ec + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) == arg_2 &&
       ((char)(&DAT_006826d3)[DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20] == arg_1)))) &&
     ((*(int *)(&DAT_006826e8 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) != -1 &&
      ((((&DAT_004ff594)
         [*(int *)(&DAT_006826c4 +
                  *(int *)(&DAT_006826e8 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) * 0x120 +
                  (char)(&DAT_006826d2)[DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20] * 0x5b20) *
          0x34] & 2) != 0 && (*(int *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) < 0x13))))))
  {
    *(undefined4 *)
     (&DAT_0068271c +
     arg_2 * 0x120 + arg_1 * 0x5b20 + *(int *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 8)
         = *(undefined4 *)(&DAT_006826e8 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20);
    *(int *)(&DAT_00682718 +
            arg_2 * 0x120 +
            arg_1 * 0x5b20 + *(int *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 8) =
         (int)(char)(&DAT_006826d2)[DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20];
    *(int *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(int *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) + 1;
  }
  if (arg_3 == 0x77) {
    bVar1 = false;
    for (local_8 = 0; local_8 < *(int *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20);
        local_8 = local_8 + 1) {
      if (((*(int *)(&DAT_0068271c + arg_2 * 0x120 + arg_1 * 0x5b20 + local_8 * 8) == DAT_00690c48)
          && (*(int *)(&DAT_00682718 + arg_2 * 0x120 + arg_1 * 0x5b20 + local_8 * 8) == DAT_0068ecb0
             )) && ((&DAT_006826e0)[DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20] != '\x04')) {
        local_c = local_8;
        if (!bVar1) {
          *(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) =
               *(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) + 1;
          bVar1 = true;
        }
        while (local_c = local_c + 1,
              local_c < *(int *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20)) {
          *(undefined4 *)(&DAT_00682710 + arg_2 * 0x120 + arg_1 * 0x5b20 + local_c * 8) =
               *(undefined4 *)(&DAT_00682718 + arg_2 * 0x120 + arg_1 * 0x5b20 + local_c * 8);
          *(undefined4 *)(&DAT_00682714 + arg_2 * 0x120 + arg_1 * 0x5b20 + local_c * 8) =
               *(undefined4 *)(&DAT_0068271c + arg_2 * 0x120 + arg_1 * 0x5b20 + local_c * 8);
        }
        *(int *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) =
             *(int *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) + -1;
      }
    }
  }
  if (((DAT_0068f230 == 0xd5) && (*(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) != 0)) &&
     ((DAT_00681ec4 == arg_1 && ((arg_2 == DAT_00690c48 && (arg_1 == DAT_0068ecb0)))))) {
    if (arg_3 == 0x7d) {
      DAT_0066642c = DAT_0066642c | 2;
    }
    if (arg_3 == 0x7e) {
      FUN_00467f65(arg_1,arg_2,*(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20));
      *(short *)(&DAT_006826d8 + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(short *)(&DAT_006826d8 + arg_2 * 0x120 + arg_1 * 0x5b20) +
           (short)*(undefined4 *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20);
      *(short *)(&DAT_006826da + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(short *)(&DAT_006826da + arg_2 * 0x120 + arg_1 * 0x5b20) +
           (short)*(undefined4 *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20);
      *(undefined4 *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
    }
  }
  if ((arg_3 == 0x22) || (arg_3 == 199)) {
    *(undefined4 *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
  }
  return 0;
}



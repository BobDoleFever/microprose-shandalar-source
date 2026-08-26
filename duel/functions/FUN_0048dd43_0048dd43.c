/*
 * Decompiled function: FUN_0048dd43
 * Entry Point: 0048dd43
 * Size: 1294 bytes
 */
#include "duel.h"


undefined4 FUN_0048dd43(void)

{
  int arg_1;
  int arg_2;
  int local_c;
  
  if (0 < DAT_006764b8) {
    DAT_006764b8 = DAT_006764b8 + -1;
    arg_1 = (&DAT_0068efb0)[DAT_006764b8 * 2];
    arg_2 = *(int *)(&DAT_0068efb4 + DAT_006764b8 * 8);
    local_c = *(int *)(&DAT_006826c4 + arg_1 * 0x5b20 + arg_2 * 0x120);
    if (local_c == DAT_0068eee0) {
      local_c = *(int *)(&DAT_006826c0 + arg_1 * 0x5b20 + arg_2 * 0x120);
    }
    if (*(int *)(&DAT_006826c4 + arg_1 * 0x5b20 + arg_2 * 0x120) != -1) {
      if ((char)((uint)*(undefined4 *)(&DAT_0068f240 + DAT_006764b8 * 4) >> 0x10) == '~') {
        FUN_0046e4c9(arg_1,arg_2,*(uint *)(&DAT_0068f240 + DAT_006764b8 * 4) >> 0x10 & 0xff,
                     *(int *)(&DAT_0068f240 + DAT_006764b8 * 4) >> 0x18);
      }
      else if (((&DAT_006827d4)[arg_1 * 0x5b20 + arg_2 * 0x120] & 8) == 0) {
        if (((&DAT_006827d4)[arg_1 * 0x5b20 + arg_2 * 0x120] & 0x80) == 0) {
          FUN_0048c907(arg_1,arg_2,*(uint *)(&DAT_0068f240 + DAT_006764b8 * 4) >> 0x10 & 0xff,
                       1 - arg_1,0xffffffff);
        }
        else {
          if (((&DAT_006827d4)[arg_1 * 0x5b20 + arg_2 * 0x120] & 0x40) != 0) {
            *(uint *)(&DAT_006826cc +
                     *(int *)(&DAT_006827b0 + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x5b20 +
                     *(int *)(&DAT_006827b4 + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x120) =
                 *(uint *)(&DAT_006826cc +
                          *(int *)(&DAT_006827b0 + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x5b20 +
                          *(int *)(&DAT_006827b4 + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x120) &
                 0xffffffef;
            FUN_0048c907(*(int *)(&DAT_006827b0 + arg_1 * 0x5b20 + arg_2 * 0x120),
                         *(int *)(&DAT_006827b4 + arg_1 * 0x5b20 + arg_2 * 0x120),0x83,1 - arg_1,
                         0xffffffff);
          }
          *(uint *)(&DAT_006827d4 +
                   *(int *)(&DAT_006827b0 + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x5b20 +
                   *(int *)(&DAT_006827b4 + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x120) =
               *(uint *)(&DAT_006827d4 +
                        *(int *)(&DAT_006827b0 + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x5b20 +
                        *(int *)(&DAT_006827b4 + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x120) &
               0xffffff7f;
        }
      }
      else {
        if (((((&DAT_006827d5)[arg_1 * 0x5b20 + arg_2 * 0x120] & 2) == 0) &&
            (FUN_0048c907(arg_1,arg_2,0x86,1 - arg_1,0xffffffff),
            *(int *)(&DAT_006826c4 + arg_1 * 0x5b20 + arg_2 * 0x120) != -1)) &&
           (((&DAT_006827d4)[arg_1 * 0x5b20 + arg_2 * 0x120] & 2) != 0)) {
          FUN_0046e571(*(int *)(&DAT_006827b0 + arg_1 * 0x5b20 + arg_2 * 0x120),
                       *(int *)(&DAT_006827b4 + arg_1 * 0x5b20 + arg_2 * 0x120),1);
        }
        *(uint *)(&DAT_006827d4 +
                 *(int *)(&DAT_006827b0 + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x5b20 +
                 *(int *)(&DAT_006827b4 + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x120) =
             *(uint *)(&DAT_006827d4 +
                      *(int *)(&DAT_006827b0 + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x5b20 +
                      *(int *)(&DAT_006827b4 + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x120) & 0xfffffdf7
        ;
        *(uint *)(&DAT_006827d4 +
                 *(int *)(&DAT_006827b0 + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x5b20 +
                 *(int *)(&DAT_006827b4 + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x120) =
             *(uint *)(&DAT_006827d4 +
                      *(int *)(&DAT_006827b0 + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x5b20 +
                      *(int *)(&DAT_006827b4 + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x120) | 4;
      }
      if (*(int *)(&DAT_006826c4 + arg_1 * 0x5b20 + arg_2 * 0x120) == DAT_0068eee0) {
        FUN_0046e571(arg_1,arg_2,4);
      }
    }
    (&DAT_0068efb0)[DAT_006764b8 * 2] = 0xffffffff;
    FUN_0048b64f();
    if (((((&DAT_004ff5a9)[local_c * 0x34] & 0x10) == 0) || (((byte)DAT_00681eb0 & 2) != 0)) &&
       ((DAT_0068eedc < 2 && (((DAT_00681eb0._1_1_ & 2) == 0 || (DAT_006764b8 == 0)))))) {
      Pic_Subsystem_004475a4(DAT_00666458);
      Pic_Subsystem_004488a0();
    }
  }
  return 0;
}



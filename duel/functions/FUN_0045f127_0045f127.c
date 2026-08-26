/*
 * Decompiled function: FUN_0045f127
 * Entry Point: 0045f127
 * Size: 869 bytes
 */
#include "duel.h"


undefined4 FUN_0045f127(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int local_8;
  
  if (arg_3 == 0x73) {
    if (((*(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) & 0x20010) == 0) &&
       (((byte)DAT_00681eb0 & 4) != 0)) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else if (arg_3 == 0x90) {
    FUN_0043071d(0);
    uVar1 = 0;
  }
  else {
    if (arg_3 == 0x6d) {
      if ((local_8 == -1) ||
         (*(int *)(&DAT_006826c4 +
                  *(int *)(&DAT_0068271c + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                  *(int *)(&DAT_00682718 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) != DAT_0068f104
         )) {
        DAT_00681ea4 = 1;
      }
      else if ((*(int *)(&DAT_006826e4 +
                        *(int *)(&DAT_0068271c + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                        *(int *)(&DAT_00682718 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) == 0) ||
              (((&DAT_004ff594)
                [*(int *)(&DAT_006826c4 +
                         *(int *)(&DAT_006826e8 +
                                 *(int *)(&DAT_0068271c + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                                 *(int *)(&DAT_00682718 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20)
                         * 0x120 + (char)(&DAT_006826d2)
                                         [*(int *)(&DAT_0068271c + arg_2 * 0x120 + arg_1 * 0x5b20) *
                                          0x120 + *(int *)(&DAT_00682718 +
                                                          arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20]
                                   * 0x5b20) * 0x34] & 0x40) == 0)) {
        DAT_00681ea4 = 1;
      }
      else {
        uVar1 = FUN_0049aa14(*(int *)(&DAT_006826e4 +
                                     *(int *)(&DAT_0068271c + arg_2 * 0x120 + arg_1 * 0x5b20) *
                                     0x120 + *(int *)(&DAT_00682718 + arg_2 * 0x120 + arg_1 * 0x5b20
                                                     ) * 0x5b20) + -2,0,99);
        *(undefined4 *)
         (&DAT_006826e4 +
         *(int *)(&DAT_0068271c + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
         *(int *)(&DAT_00682718 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) = uVar1;
        *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) =
             *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
      }
      if (arg_1 == DAT_00676504) {
        *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) =
             *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}



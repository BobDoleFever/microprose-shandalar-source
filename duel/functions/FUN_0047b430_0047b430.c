/*
 * Decompiled function: FUN_0047b430
 * Entry Point: 0047b430
 * Size: 886 bytes
 */
#include "duel.h"


undefined4 FUN_0047b430(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  int local_c;
  
  if (arg_3 == 1) {
    uVar1 = FUN_0047a090(arg_1,arg_2,1,0);
    return uVar1;
  }
  if (arg_3 != 0x73) {
    if (arg_3 == 0x6d) {
      if ((((byte)DAT_00681eb0 & 4) == 0) ||
         (iVar2 = FUN_004512d1(arg_1,s_Elephant_s_Graveyard__004f9adc,1,s_Regenerate_004f9ad0,
                               &DAT_004f9ac8,(char *)0x0), iVar2 != 0)) {
        FUN_0049b235(arg_1,0,1);
        DAT_0068f0f4 = 0;
      }
      else {
        if ((local_c != -1) &&
           (((&DAT_004ff595)
             [*(int *)(&DAT_006826c4 +
                      *(int *)(&DAT_0068271c + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                      *(int *)(&DAT_00682718 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) * 0x34] ==
             '\n' || ((&DAT_004ff595)
                      [*(int *)(&DAT_006826c4 +
                               *(int *)(&DAT_0068271c + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                               *(int *)(&DAT_00682718 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) *
                       0x34] == '\v')))) {
          (&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] = (undefined1)DAT_0068eef0;
          *(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) = local_c;
          *(uint *)(&DAT_006826fc +
                   *(int *)(&DAT_0068271c + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                   *(int *)(&DAT_00682718 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) =
               *(uint *)(&DAT_006826fc +
                        *(int *)(&DAT_0068271c + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                        *(int *)(&DAT_00682718 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) | 0x200;
        }
        FUN_0049b1eb(arg_1,0,1);
      }
      *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
    }
    if (((byte)DAT_00681eb0 & 4) == 0) {
      *(undefined4 *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0xffffffff;
      (&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] =
           (&DAT_006826e8)[arg_2 * 0x120 + arg_1 * 0x5b20];
    }
    if ((((arg_3 == 0x34) &&
         (*(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) == DAT_00690c48)) &&
        ((char)(&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] == DAT_0068ecb0)) &&
       (DAT_00690c48 != -1)) {
      DAT_0066642c = DAT_0066642c | 0x200;
    }
    return 0;
  }
  if ((((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0) &&
     ((((&DAT_006826ce)[arg_2 * 0x120 + arg_1 * 0x5b20] & 3) == 0 ||
      (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34] & 2) == 0))
     )) {
    return 1;
  }
  return 0;
}



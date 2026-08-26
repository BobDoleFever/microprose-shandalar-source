/*
 * Decompiled function: FUN_0047acdd
 * Entry Point: 0047acdd
 * Size: 670 bytes
 */
#include "duel.h"


undefined4 FUN_0047acdd(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (arg_3 == 1) {
    uVar1 = FUN_0047a090(arg_1,arg_2,1,0);
  }
  else if (arg_3 == 0x73) {
    if ((((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0) &&
       ((((&DAT_006826ce)[arg_2 * 0x120 + arg_1 * 0x5b20] & 3) == 0 ||
        (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34] & 2) == 0
        )))) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    if (arg_3 == 0x6d) {
      if (((DAT_0068f2c4 < 0x1a) || (0x1d < DAT_0068f2c4)) ||
         (iVar2 = FUN_004512d1(arg_1,s_Desert__004f9a88,1,s_Damage_004f9a80,&DAT_004f9a78,
                               (char *)0x0), iVar2 != 0)) {
        FUN_0049b235(arg_1,0,1);
        DAT_0068f0f4 = 0;
      }
      else {
        iVar2 = FUN_00468130(arg_1,1 - arg_1,arg_2);
        if (iVar2 == 0) {
          DAT_00681ea4 = 1;
        }
        else {
          if (((&DAT_006826cc)
               [*(int *)(&DAT_00682718 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
                *(int *)(&DAT_0068271c + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120] & 0x44) != 0) {
            FUN_004af950(*(int *)(&DAT_00682718 + arg_2 * 0x120 + arg_1 * 0x5b20),
                         *(int *)(&DAT_0068271c + arg_2 * 0x120 + arg_1 * 0x5b20),1,arg_1,arg_2);
          }
          (&DAT_006827b8)[arg_2 * 0x120 + arg_1 * 0x5b20] = 0;
          FUN_0049b1eb(arg_1,0,1);
          *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) =
               *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
        }
      }
      (&DAT_006827b8)[arg_2 * 0x120 + arg_1 * 0x5b20] = 0;
    }
    uVar1 = 0;
  }
  return uVar1;
}



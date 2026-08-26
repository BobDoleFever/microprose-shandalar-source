/*
 * Decompiled function: FUN_0041983c
 * Entry Point: 0041983c
 * Size: 618 bytes
 */
#include "duel.h"


undefined4 FUN_0041983c(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  
  if (arg_3 == 0x73) {
    if ((((*(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) == 0) &&
         (iVar1 = FUN_0049b309(arg_1,7,5), iVar1 != 0)) &&
        ((((&DAT_006826ce)[arg_2 * 0x120 + arg_1 * 0x5b20] & 3) == 0 ||
         (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34] & 2) ==
          0)))) && (((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0)) {
      if ((DAT_00676504 == arg_1) && (0 < DAT_0068f2c0)) {
        DAT_00676500 = DAT_00676500 | 3;
      }
      return 1;
    }
  }
  else {
    if (((arg_3 == 0x6d) && (iVar1 = FUN_0049b309(arg_1,7,5), iVar1 != 0)) &&
       (Ai_CalcManaRequirement_004ba890(arg_1,0,5), DAT_00681ea4 != 1)) {
      *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
      *(uint *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) | 1;
      if (0 < DAT_0068f2c0) {
        DAT_0068f2c0 = DAT_0068f2c0 + -1;
      }
    }
    if (arg_3 == 0x72) {
      iVar1 = FUN_004d7d5e(0x375);
      iVar1 = Pic_Subsystem_00451291(arg_1,iVar1);
      if (iVar1 != -1) {
        Pic_Subsystem_0042ac1f(arg_1,iVar1);
        *(uint *)(&DAT_006826f8 + iVar1 * 0x120 + arg_1 * 0x5b20) =
             *(uint *)(&DAT_006826f8 + iVar1 * 0x120 + arg_1 * 0x5b20) | 0x10;
      }
      *(undefined4 *)
       (&DAT_006826e4 +
       *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
       *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120) = 0;
    }
  }
  return 0;
}



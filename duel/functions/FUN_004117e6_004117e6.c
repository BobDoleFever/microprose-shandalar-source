/*
 * Decompiled function: FUN_004117e6
 * Entry Point: 004117e6
 * Size: 387 bytes
 */
#include "duel.h"


undefined4 FUN_004117e6(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (arg_3 == 0x73) {
    if (((&DAT_006826cc)[arg_1 * 0x5b20 + arg_2 * 0x120] & 0x10) == 0) {
      uVar1 = 1;
    }
    else {
      uVar1 = FUN_0049b309(arg_1,7,3);
    }
  }
  else {
    if (arg_3 == 0x6d) {
      if (((&DAT_006826cc)[arg_1 * 0x5b20 + arg_2 * 0x120] & 0x10) == 0) {
        FUN_0049b235(arg_1,0,3);
        DAT_0068f2d4 = DAT_0068f2d4 + -0x24;
        *(undefined4 *)(&DAT_006826e4 + arg_1 * 0x5b20 + arg_2 * 0x120) = 1;
      }
      else {
        iVar2 = FUN_0049b309(arg_1,7,3);
        if ((iVar2 != 0) &&
           ((arg_1 == DAT_00676510 ||
            (*(int *)(&DAT_006826e4 + arg_1 * 0x5b20 + arg_2 * 0x120) == 0)))) {
          Ai_CalcManaRequirement_004ba890(arg_1,0,3);
        }
      }
    }
    if (arg_3 == 0x72) {
      *(uint *)(&DAT_006826cc + arg_1 * 0x5b20 + arg_2 * 0x120) =
           *(uint *)(&DAT_006826cc + arg_1 * 0x5b20 + arg_2 * 0x120) ^ 0x10;
    }
    if (arg_3 == 0x22) {
      *(undefined4 *)(&DAT_006826e4 + arg_1 * 0x5b20 + arg_2 * 0x120) = 0;
    }
    uVar1 = 0;
  }
  return uVar1;
}



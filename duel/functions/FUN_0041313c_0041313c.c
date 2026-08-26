/*
 * Decompiled function: FUN_0041313c
 * Entry Point: 0041313c
 * Size: 301 bytes
 */
#include "duel.h"


undefined4 FUN_0041313c(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  
  if (((arg_3 == 0x6c) && (DAT_00690c48 == arg_2)) && (DAT_0068ecb0 == arg_1)) {
    DAT_0068f2d4 = DAT_0068f2d4 +
                   (((&DAT_00681ea8)[DAT_00676510] + 4) - (&DAT_00681ea8)[DAT_00676504]) *
                   *(int *)(&DAT_0068ef6c + DAT_00676504 * 0x20) * 6;
  }
  if (((arg_3 == 0x77) && (DAT_0068ecb0 == arg_1)) &&
     (((&DAT_004ff594)
       [*(int *)(&DAT_006826c4 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) * 0x34] & 0x40) != 0)
     ) {
    iVar1 = FUN_0049b309(arg_1,7,1);
    if ((iVar1 != 0) && (((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0)) {
      Ai_CalcManaRequirement_004ba890(arg_1,0,1);
      if (DAT_00681ea4 != 1) {
        (&DAT_00681ea8)[arg_1] = (&DAT_00681ea8)[arg_1] + 1;
      }
    }
  }
  return 0;
}



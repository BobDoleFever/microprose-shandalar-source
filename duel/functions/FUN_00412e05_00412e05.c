/*
 * Decompiled function: FUN_00412e05
 * Entry Point: 00412e05
 * Size: 823 bytes
 */
#include "duel.h"


undefined4 FUN_00412e05(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  
  if (((arg_3 == 0x6c) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) {
    DAT_0068f2d4 = DAT_0068f2d4 + 0x90;
  }
  if (((arg_3 == 0x77) && ((&DAT_006826e0)[DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20] != '\0'))
     && ((((&DAT_004ff594)
           [*(int *)(&DAT_006826c4 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) * 0x34] & 2) != 0
         && ((&DAT_006826e0)[DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20] != '\x04')))) {
    if (((&DAT_006826e5)[arg_1 * 0x5b20 + arg_2 * 0x120] & 1) == 0) {
      *(int *)(&DAT_006826e4 + arg_1 * 0x5b20 + arg_2 * 0x120) =
           *(int *)(&DAT_006826e4 + arg_1 * 0x5b20 + arg_2 * 0x120) + 1;
    }
    else {
      *(undefined4 *)(&DAT_006826e4 + arg_1 * 0x5b20 + arg_2 * 0x120) = 1;
    }
  }
  if (((DAT_0068f230 == 0xd5) && (arg_2 == DAT_00690c48)) &&
     ((arg_1 == DAT_0068ecb0 &&
      (((&DAT_006826e4)[arg_1 * 0x5b20 + arg_2 * 0x120] != '\0' && (arg_1 == DAT_00681ec4)))))) {
    *(uint *)(&DAT_006826e4 + arg_1 * 0x5b20 + arg_2 * 0x120) =
         *(uint *)(&DAT_006826e4 + arg_1 * 0x5b20 + arg_2 * 0x120) | 0x100;
    if ((arg_3 == 0x7d) && (iVar1 = FUN_0049b309(arg_1,7,1), iVar1 != 0)) {
      if ((arg_1 == DAT_00676504) && ((int)(&DAT_00681ea8)[arg_1] < (&DAT_00681ea8)[1 - arg_1] + 8))
      {
        DAT_0066642c = DAT_0066642c | 2;
      }
      else {
        DAT_0066642c = DAT_0066642c | 1;
      }
    }
    if (arg_3 == 0x7e) {
      Ai_CalcManaRequirement_004ba890(arg_1,0,1);
      if (DAT_00681ea4 == 1) {
        DAT_00681ea4 = -1;
      }
      else {
        (&DAT_00681ea8)[arg_1] = (&DAT_00681ea8)[arg_1] + 1;
        *(int *)(&DAT_006826e4 + arg_1 * 0x5b20 + arg_2 * 0x120) =
             *(int *)(&DAT_006826e4 + arg_1 * 0x5b20 + arg_2 * 0x120) + -1;
      }
    }
    if ((&DAT_006826e4)[arg_1 * 0x5b20 + arg_2 * 0x120] != '\0') {
      *(uint *)(&DAT_006826cc + arg_1 * 0x5b20 + arg_2 * 0x120) =
           *(uint *)(&DAT_006826cc + arg_1 * 0x5b20 + arg_2 * 0x120) & 0xfffffeff;
    }
  }
  return 0;
}



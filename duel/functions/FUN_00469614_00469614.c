/*
 * Decompiled function: FUN_00469614
 * Entry Point: 00469614
 * Size: 529 bytes
 */
#include "duel.h"


undefined4 FUN_00469614(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (arg_3 == 0x73) {
    iVar1 = FUN_0049b309(arg_1,7,2);
    if ((iVar1 == 0) || ((*(uint *)(&DAT_006826cc + arg_1 * 0x5b20 + arg_2 * 0x120) & 0x20014) != 0)
       ) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  else if (arg_3 == 0x90) {
    FUN_0043071d(1);
    FUN_00430768(0);
    uVar2 = 0;
  }
  else {
    if ((arg_3 == 0x6d) && (iVar1 = FUN_00469b05(arg_1,arg_2), iVar1 != 0)) {
      Ai_CalcManaRequirement_004ba890(arg_1,0,2);
      if (DAT_00681ea4 != 1) {
        Ai_CalcManaRequirement_004ba890(arg_1,4,-1);
      }
      if (DAT_00681ea4 != 1) {
        *(undefined4 *)(&DAT_006826e4 + arg_1 * 0x5b20 + arg_2 * 0x120) = DAT_00681ea0;
        *(uint *)(&DAT_006826cc + arg_1 * 0x5b20 + arg_2 * 0x120) =
             *(uint *)(&DAT_006826cc + arg_1 * 0x5b20 + arg_2 * 0x120) | 0x10;
      }
    }
    if ((arg_3 == 0x72) && (0 < *(int *)(&DAT_006826e4 + arg_1 * 0x5b20 + arg_2 * 0x120))) {
      if (DAT_0066aaf4 != 1) {
        FUN_0048d00c(0x27);
      }
      FUN_00469825(DAT_00690af0,DAT_0068efa0,
                   *(int *)(&DAT_006826e4 + arg_1 * 0x5b20 + arg_2 * 0x120));
      *(undefined4 *)
       (&DAT_006826e4 +
       *(int *)(&DAT_006827b0 + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x5b20 +
       *(int *)(&DAT_006827b4 + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x120) = 0;
    }
    uVar2 = 0;
  }
  return uVar2;
}



/*
 * Decompiled function: FUN_004593fd
 * Entry Point: 004593fd
 * Size: 560 bytes
 */
#include "duel.h"


undefined4 FUN_004593fd(int arg_1,int arg_2,int arg_3,int arg_4,int arg_5)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (((arg_3 == 0x73) && ((DAT_00681eb0._1_1_ & 2) != 0)) &&
     (*(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) == 0)) {
    bVar1 = (&DAT_006826e0)[arg_2 * 0x120 + arg_1 * 0x5b20] == '\x02' &&
            (((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 2) != 0 &&
            ((&DAT_006826fd)[arg_2 * 0x120 + arg_1 * 0x5b20] & 2) != 0);
    if ((bVar1) && (iVar2 = FUN_0049b309(arg_1,arg_4,arg_5), iVar2 == 0)) {
      bVar1 = false;
    }
    if (bVar1) {
      uVar3 = 99;
    }
    else {
      uVar3 = 0;
    }
  }
  else if (arg_3 == 0x90) {
    FUN_0043071d(0);
    uVar3 = 0;
  }
  else {
    if (((arg_3 == 0x6d) && ((DAT_00681eb0._1_1_ & 2) != 0)) &&
       (Ai_CalcManaRequirement_004ba890(arg_1,arg_4,arg_5), DAT_00681ea4 != 1)) {
      DAT_006664ec = 1;
      *(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) + 1;
    }
    if ((arg_3 == 0x72) && ((DAT_00681eb0._1_1_ & 2) != 0)) {
      *(undefined4 *)
       (&DAT_006826e4 +
       *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
       *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120) = 0;
      FUN_0045962d(DAT_00690af0,DAT_0068efa0);
    }
    uVar3 = 0;
  }
  return uVar3;
}



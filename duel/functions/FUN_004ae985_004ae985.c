/*
 * Decompiled function: FUN_004ae985
 * Entry Point: 004ae985
 * Size: 1027 bytes
 */
#include "duel.h"


uint FUN_004ae985(int arg_1,int arg_2,int arg_3)

{
  uint uVar1;
  int iVar2;
  
  if (arg_3 == 0x74) {
    FUN_0043071d(0);
    uVar1 = DAT_00681eb0 & 4;
  }
  else {
    if (((arg_3 == 0x6c) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) {
      if (*(int *)(&DAT_006826c4 +
                  *(int *)(&DAT_0068271c + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x120 +
                  *(int *)(&DAT_00682718 + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x5b20) == DAT_0068f104
         ) {
        (&DAT_006826d2)[arg_1 * 0x5b20 + arg_2 * 0x120] =
             (&DAT_006826d2)
             [*(int *)(&DAT_0068271c + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x120 +
              *(int *)(&DAT_00682718 + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x5b20];
        *(undefined4 *)(&DAT_006826e8 + arg_1 * 0x5b20 + arg_2 * 0x120) =
             *(undefined4 *)
              (&DAT_006826e8 +
              *(int *)(&DAT_0068271c + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x120 +
              *(int *)(&DAT_00682718 + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x5b20);
        *(int *)(&DAT_006826e4 + arg_1 * 0x5b20 + arg_2 * 0x120) = DAT_00681ea0;
      }
      else {
        DAT_00681ea4 = 1;
      }
      DAT_0068f2d4 = DAT_0068f2d4 + -0x30;
    }
    if (((arg_3 == 0x6e) && (*(int *)(&DAT_006826e8 + arg_1 * 0x5b20 + arg_2 * 0x120) != -1)) &&
       ((*(int *)(&DAT_006826e8 + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120) ==
         *(int *)(&DAT_006826e8 + arg_1 * 0x5b20 + arg_2 * 0x120) &&
        ((&DAT_006826d2)[DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120] ==
         (&DAT_006826d2)[arg_1 * 0x5b20 + arg_2 * 0x120])))) {
      iVar2 = FUN_0049aa14(*(int *)(&DAT_006826e4 + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120),0,
                           *(int *)(&DAT_006826e4 + arg_1 * 0x5b20 + arg_2 * 0x120));
      *(int *)(&DAT_006826e4 + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120) =
           *(int *)(&DAT_006826e4 + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120) - iVar2;
      *(int *)(&DAT_006826e4 + arg_1 * 0x5b20 + arg_2 * 0x120) =
           *(int *)(&DAT_006826e4 + arg_1 * 0x5b20 + arg_2 * 0x120) - iVar2;
    }
    if (arg_3 == 0x73) {
      if (((DAT_00681eb0 & 4) == 0) || (iVar2 = FUN_0049b309(arg_1,7,1), iVar2 == 0)) {
        uVar1 = 0;
      }
      else {
        uVar1 = 1;
      }
    }
    else {
      if ((arg_3 == 0x6d) && (Ai_CalcManaRequirement_004ba890(arg_1,0,-1), DAT_00681ea4 != 1)) {
        *(int *)(&DAT_006826e4 + arg_1 * 0x5b20 + arg_2 * 0x120) =
             *(int *)(&DAT_006826e4 + arg_1 * 0x5b20 + arg_2 * 0x120) + DAT_00681ea0;
      }
      if ((arg_3 == 0x22) || (arg_3 == 199)) {
        FUN_0046e571(arg_1,arg_2,1);
      }
      uVar1 = 0;
    }
  }
  return uVar1;
}



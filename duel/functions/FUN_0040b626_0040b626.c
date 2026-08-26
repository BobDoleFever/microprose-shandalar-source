/*
 * Decompiled function: FUN_0040b626
 * Entry Point: 0040b626
 * Size: 882 bytes
 */
#include "duel.h"


undefined4 FUN_0040b626(int arg_1,int arg_2,int arg_3)

{
  undefined1 uVar1;
  int iVar2;
  int local_18;
  
  if (arg_3 != 0x73) {
    if ((((arg_3 == 2) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) &&
       (iVar2 = FUN_0049b309(arg_1,7,2), iVar2 != 0)) {
      DAT_0066642c = DAT_0066642c | 1;
    }
    if (((arg_3 == 4) && (arg_2 == DAT_00690c48)) &&
       ((arg_1 == DAT_0068ecb0 &&
        ((iVar2 = FUN_0049b309(arg_1,7,2), iVar2 != 0 &&
         (Ai_CalcManaRequirement_004ba890(arg_1,0,2), local_18 != -1)))))) {
      iVar2 = FUN_004af74c(arg_1,arg_2,1);
      uVar1 = FUN_004af74c(arg_1,arg_2,1);
      *(undefined4 *)
       (&DAT_006826e4 +
       *(int *)(&DAT_0068271c + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x120 +
       *(int *)(&DAT_00682718 + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x5b20) =
           *(undefined4 *)
            (&DAT_006826c4 +
            *(int *)(&DAT_0068271c + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x120 +
            *(int *)(&DAT_00682718 + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x5b20);
      *(int *)(&DAT_006826c4 +
              *(int *)(&DAT_0068271c + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x120 +
              *(int *)(&DAT_00682718 + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x5b20) = iVar2 + -1;
      (&DAT_006826dc)
      [*(int *)(&DAT_0068271c + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x120 +
       *(int *)(&DAT_00682718 + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x5b20] = uVar1;
      *(uint *)(&DAT_006826f8 +
               *(int *)(&DAT_00682718 + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x5b20 +
               *(int *)(&DAT_0068271c + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x120) =
           *(uint *)(&DAT_006826f8 +
                    *(int *)(&DAT_00682718 + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x5b20 +
                    *(int *)(&DAT_0068271c + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x120) | 0x200;
    }
    if (((arg_3 == 0x77) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) {
      iVar2 = FUN_004d7d5e(0x391);
      iVar2 = Pic_Subsystem_00451291(arg_1,iVar2);
      if (iVar2 != -1) {
        *(uint *)(&DAT_006826cc + iVar2 * 0x120 + arg_1 * 0x5b20) =
             *(uint *)(&DAT_006826cc + iVar2 * 0x120 + arg_1 * 0x5b20) | 2;
      }
    }
  }
  return 0;
}



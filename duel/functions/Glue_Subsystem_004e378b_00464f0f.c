/*
 * Decompiled function: Glue_Subsystem_004e378b
 * Entry Point: 00464f0f
 * Size: 970 bytes
 */
#include "duel.h"


undefined4 Glue_Subsystem_004e378b(int arg_1,int arg_2,int arg_3)

{
  bool bVar1;
  int iVar2;
  int local_8;
  
  if (((arg_3 == 0x6c) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) {
    *(undefined4 *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = DAT_00681ea0;
  }
  if (((arg_3 == 2) && (arg_2 == DAT_00690c48)) &&
     ((arg_1 == DAT_0068ecb0 && (iVar2 = FUN_0049b309(arg_1,4,3), iVar2 != 0)))) {
    DAT_0066642c = DAT_0066642c | 1;
  }
  if ((arg_2 == DAT_00690c48) && (arg_1 == DAT_0068ecb0)) {
    if ((arg_3 == 0x32) || (arg_3 == 0x33)) {
      DAT_0066642c = DAT_0066642c + *(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20);
    }
    if ((((arg_3 == 0x6e) &&
         ((char)(&DAT_006826d2)[DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20] == arg_1)) &&
        (*(int *)(&DAT_006826e8 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) == arg_2)) &&
       (*(int *)(&DAT_006826e4 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) != 0)) {
      for (local_8 = 0;
          local_8 < *(int *)(&DAT_006826e4 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20);
          local_8 = local_8 + 1) {
        bVar1 = false;
        iVar2 = FUN_0049b309(arg_1,4,1);
        if ((iVar2 != 0) &&
           (iVar2 = Ai_Subsystem_004cc56d
                              (arg_1,arg_1,arg_2,-1,-1,s_Restore_Hydra_Head__Never_mind__004f8da8,0)
           , iVar2 == 0)) {
          Ai_CalcManaRequirement_004ba890(arg_1,4,1);
          if (DAT_00681ea4 == 1) {
            DAT_00681ea4 = -1;
          }
          else {
            bVar1 = true;
          }
        }
        if (!bVar1) break;
        *(int *)(&DAT_006826e4 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) =
             *(int *)(&DAT_006826e4 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) + -1;
      }
      iVar2 = FUN_0049aa14(*(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20),0,
                           *(int *)(&DAT_006826e4 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20));
      *(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) - iVar2;
      *(int *)(&DAT_006826e4 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) =
           *(int *)(&DAT_006826e4 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) - iVar2;
    }
    if (((arg_3 == 4) && (arg_2 == DAT_00690c48)) &&
       ((arg_1 == DAT_0068ecb0 &&
        ((iVar2 = FUN_0049b309(arg_1,4,3), iVar2 != 0 &&
         (iVar2 = Ai_Subsystem_004cc56d
                            (arg_1,arg_1,arg_2,-1,-1,s_Grow_new_Hydra_head__Never_mind__004f8dcc,0),
         iVar2 == 0)))))) {
      Ai_CalcManaRequirement_004ba890(arg_1,4,3);
      if (DAT_00681ea4 == 1) {
        DAT_00681ea4 = -1;
      }
      else {
        *(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) =
             *(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) + 1;
      }
    }
  }
  return 0;
}



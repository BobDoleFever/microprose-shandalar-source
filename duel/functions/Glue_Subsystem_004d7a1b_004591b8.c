/*
 * Decompiled function: Glue_Subsystem_004d7a1b
 * Entry Point: 004591b8
 * Size: 333 bytes
 */
#include "duel.h"


undefined4 Glue_Subsystem_004d7a1b(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  uint arg_2_00;
  int arg_3_00;
  
  if (((arg_2 == DAT_00690c48) && (arg_1 == DAT_0068ecb0)) && (0 < (int)(&DAT_0068ef54)[arg_1 * 8]))
  {
    if (arg_3 == 0x32) {
      DAT_0066642c = DAT_0066642c + 1;
    }
    if (arg_3 == 0x33) {
      DAT_0066642c = DAT_0066642c + 1;
    }
  }
  if (arg_3 == 1) {
    iVar1 = FUN_004af74c(arg_1,arg_2,1);
    *(int *)(&DAT_0068f320 + iVar1 * 4 + arg_1 * 0x20) =
         *(int *)(&DAT_0068f320 + iVar1 * 4 + arg_1 * 0x20) + 2;
  }
  if (((arg_3 == 0x70) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) {
    iVar1 = 1;
    arg_2_00 = FUN_004af74c(arg_1,arg_2,1);
    iVar1 = FUN_0049b309(arg_1,arg_2_00,iVar1);
    if (iVar1 != 0) {
      iVar1 = Ai_Subsystem_004cc56d
                        (arg_1,arg_1,arg_2,-1,-1,s_Regenerate_Sedge_Troll__Don_t_re_004f8938,0);
      if (iVar1 == 0) {
        arg_3_00 = 1;
        iVar1 = FUN_004af74c(arg_1,arg_2,1);
        Ai_CalcManaRequirement_004ba890(arg_1,iVar1,arg_3_00);
        if (DAT_00681ea4 == 1) {
          DAT_00681ea4 = -1;
        }
        else {
          DAT_0066642c = DAT_0066642c + 1;
        }
      }
    }
  }
  return 0;
}



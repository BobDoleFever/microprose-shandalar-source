/*
 * Decompiled function: Glue_Subsystem_004d7bb5
 * Entry Point: 00459352
 * Size: 171 bytes
 */
#include "duel.h"


undefined4 Glue_Subsystem_004d7bb5(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  
  if (((arg_3 == 0x70) && (DAT_00690c48 == arg_2)) && (DAT_0068ecb0 == arg_1)) {
    iVar1 = FUN_0049b309(arg_1,7,1);
    if (iVar1 != 0) {
      iVar1 = Ai_Subsystem_004cc56d
                        (arg_1,arg_1,arg_2,-1,-1,s_Regenerate_Living_Wall__Don_t_re_004f8964,0);
      if (iVar1 == 0) {
        Ai_CalcManaRequirement_004ba890(arg_1,0,1);
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



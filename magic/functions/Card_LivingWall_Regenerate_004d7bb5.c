/*
 * Decompiled function: Card_LivingWall_Regenerate
 * Entry Point: 004d7bb5
 * Size: 171 bytes
 */
#include "magic.h"


undefined4 Card_LivingWall_Regenerate(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  
  if (((arg_3 == 0x70) && (g_OverworldMapGrid == arg_2)) && (g_OverworldPlayerCoordX == arg_1)) {
    iVar1 = FUN_0040d949(arg_1,7,1);
    if (iVar1 != 0) {
      iVar1 = Ai_Subsystem_004cc56d
                        (arg_1,arg_1,arg_2,-1,-1,s_Regenerate_Living_Wall__Don_t_re_0052ead0,0);
      if (iVar1 == 0) {
        Ai_CalcManaRequirement_004ba890(arg_1,0,1);
        if (g_ActivePlayer == 1) {
          g_ActivePlayer = -1;
        }
        else {
          g_ActivePalette = g_ActivePalette + 1;
        }
      }
    }
  }
  return 0;
}



/*
 * Decompiled function: Card_SedgeTroll_Regenerate
 * Entry Point: 004d7a1b
 * Size: 333 bytes
 */
#include "magic.h"


undefined4 Card_SedgeTroll_Regenerate(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  uint arg_2_00;
  int arg_3_00;
  
  if (((arg_2 == g_OverworldMapGrid) && (arg_1 == g_OverworldPlayerCoordX)) &&
     (0 < (int)(&DAT_0063ee34)[arg_1 * 8])) {
    if (arg_3 == 0x32) {
      g_ActivePalette = g_ActivePalette + 1;
    }
    if (arg_3 == 0x33) {
      g_ActivePalette = g_ActivePalette + 1;
    }
  }
  if (arg_3 == 1) {
    iVar1 = FUN_0041d963(arg_1,arg_2,1);
    *(int *)(&DAT_006ff690 + iVar1 * 4 + arg_1 * 0x20) =
         *(int *)(&DAT_006ff690 + iVar1 * 4 + arg_1 * 0x20) + 2;
  }
  if (((arg_3 == 0x70) && (arg_2 == g_OverworldMapGrid)) && (arg_1 == g_OverworldPlayerCoordX)) {
    iVar1 = 1;
    arg_2_00 = FUN_0041d963(arg_1,arg_2,1);
    iVar1 = FUN_0040d949(arg_1,arg_2_00,iVar1);
    if (iVar1 != 0) {
      iVar1 = Ai_Subsystem_004cc56d
                        (arg_1,arg_1,arg_2,-1,-1,s_Regenerate_Sedge_Troll__Don_t_re_0052eaa4,0);
      if (iVar1 == 0) {
        arg_3_00 = 1;
        iVar1 = FUN_0041d963(arg_1,arg_2,1);
        Ai_CalcManaRequirement_004ba890(arg_1,iVar1,arg_3_00);
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



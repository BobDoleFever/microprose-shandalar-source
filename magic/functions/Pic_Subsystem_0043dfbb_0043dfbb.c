/*
 * Decompiled function: Pic_Subsystem_0043dfbb
 * Entry Point: 0043dfbb
 * Size: 315 bytes
 */
#include "magic.h"


undefined4 Pic_Subsystem_0043dfbb(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (((arg_3 == 0x6c) && (g_OverworldMapGrid == arg_2)) && (g_OverworldPlayerCoordX == arg_1)) {
      g_SpellStackDepth = g_SpellStackDepth + *(int *)(&DAT_0063ede4 + arg_1 * 0x20) * 0xc;
    }
    if (((arg_3 == 2) && (g_OverworldMapGrid == arg_2)) && (g_OverworldPlayerCoordX == arg_1)) {
      iVar2 = FUN_0040d949(arg_1,5,2);
      if (iVar2 != 0) {
        g_ActivePalette = g_ActivePalette | 1;
      }
    }
    if ((((arg_3 == 4) && (g_OverworldMapGrid == arg_2)) && (g_OverworldPlayerCoordX == arg_1)) ||
       (arg_3 == 199)) {
      iVar2 = FUN_0040d949(arg_1,5,2);
      if (iVar2 != 0) {
        iVar2 = Ai_Subsystem_004cc56d
                          (arg_1,arg_1,arg_2,-1,-1,s_Add_life_for_2_white_mana__No_Ye_00521888,1);
        if (iVar2 != 0) {
          Ai_CalcManaRequirement_004ba890(arg_1,5,2);
          (&g_PlayerCreatureCount)[arg_1] = (&g_PlayerCreatureCount)[arg_1] + 1;
        }
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}



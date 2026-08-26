/*
 * Decompiled function: Pic_Subsystem_0043b224
 * Entry Point: 0043b224
 * Size: 512 bytes
 */
#include "magic.h"


undefined4 Pic_Subsystem_0043b224(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (arg_3 == 0x6c) {
      g_SpellStackDepth =
           g_SpellStackDepth +
           ((&g_PlayerCreatureCount)[arg_1] - (&g_PlayerCreatureCount)[1 - arg_1]) * 0xc;
    }
    if (((arg_3 == 2) && (g_OverworldMapGrid == arg_2)) && (arg_1 == g_OverworldPlayerCoordX)) {
      g_ActivePalette = g_ActivePalette | 2;
    }
    if (((arg_3 == 4) && (g_OverworldMapGrid == arg_2)) && (arg_1 == g_OverworldPlayerCoordX)) {
      iVar2 = FUN_0040d949(arg_1,3,*(int *)(&g_CardSlot_ConvertedManaCost +
                                           arg_2 * 0x120 + arg_1 * 0x5b20) + 1);
      if (iVar2 == 0) {
        Pic_Subsystem_0044867e(arg_1,arg_2,2);
      }
      else {
        iVar2 = Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,-1,-1,s_Pay_mana__No_Yes_005216d0,1);
        if (iVar2 == 0) {
          Pic_Subsystem_0044867e(arg_1,arg_2,2);
        }
        else {
          Ai_CalcManaRequirement_004ba890
                    (arg_1,3,*(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20
                                     ) + 1);
          *(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) =
               *(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) + 1;
          Mem_AllocOrFree_0041df33
                    (1 - arg_1,
                     *(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20),arg_1,
                     arg_2);
          Mem_AllocOrFree_0041df33
                    (arg_1,*(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20),
                     arg_1,arg_2);
          CardQuery_ForEachPermanent(Pic_Subsystem_0043b1d7,-1);
        }
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}



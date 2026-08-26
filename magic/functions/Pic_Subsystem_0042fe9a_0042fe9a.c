/*
 * Decompiled function: Pic_Subsystem_0042fe9a
 * Entry Point: 0042fe9a
 * Size: 387 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 Pic_Subsystem_0042fe9a(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if ((((arg_3 == 2) && (g_OverworldMapGrid == arg_2)) && (g_OverworldPlayerCoordX == arg_1)) &&
       ((*(byte *)(&DAT_006a2828 + arg_1) & 2) != 0)) {
      g_ActivePalette = g_ActivePalette | 1;
    }
    if (((arg_3 == 4) && (g_OverworldMapGrid == arg_2)) &&
       ((g_OverworldPlayerCoordX == arg_1 && ((*(byte *)(&DAT_006a2828 + arg_1) & 2) != 0)))) {
      iVar2 = Ai_Subsystem_004cc56d
                        (arg_1,arg_1,arg_2,-1,-1,s_Sacrifice_creature_to_use_gate__N_005213bc,0);
      if (iVar2 != 0) {
        iVar2 = CardTarget_HasValidCreatureTarget(arg_1);
        if (iVar2 != -1) {
          Pic_Subsystem_0044867e(arg_1,iVar2,3);
          if ((iVar2 != -1) &&
             (((&g_MasterCardColorTable)
               [*(int *)(&g_CardSlot_CardId +
                        *(int *)(&g_CardSlot_AttachedAura + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120
                        + *(int *)(&g_CardSlot_CombatTarget + arg_2 * 0x120 + arg_1 * 0x5b20) *
                          0x5b20) * 0x34] & 0x40) != 0)) {
            Pic_Subsystem_0044867e(_DAT_0063ee20,iVar2,2);
          }
        }
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}



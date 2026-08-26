/*
 * Decompiled function: Pic_Subsystem_00433232
 * Entry Point: 00433232
 * Size: 258 bytes
 */
#include "magic.h"


undefined4 Pic_Subsystem_00433232(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if ((arg_3 == 0x81) && (g_OverworldPlayerCoordX != arg_1)) {
      iVar3 = *(int *)(&g_CardSlot_CardId +
                      g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120);
      iVar2 = FUN_0041d963(arg_1,arg_2,3);
      if (*(int *)(&g_MasterCardTypeTable + iVar3 * 0x34) == *(int *)(&DAT_006ff2bc + iVar2 * 4)) {
        (&g_PlayerCreatureCount)[arg_1] = (&g_PlayerCreatureCount)[arg_1] + 1;
      }
    }
    if ((((arg_3 == 0x6c) || (arg_3 == 199)) && (g_OverworldMapGrid == arg_2)) &&
       (g_OverworldPlayerCoordX == arg_1)) {
      iVar3 = FUN_0041d963(arg_1,arg_2,3);
      g_SpellStackDepth =
           g_SpellStackDepth +
           (*(int *)(&DAT_0063ee30 + iVar3 * 4 + g_CurrentTurnPhase * 0x20) * 3 + 3) * 8;
    }
    uVar1 = 0;
  }
  return uVar1;
}



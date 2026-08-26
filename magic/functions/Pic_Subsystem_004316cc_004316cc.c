/*
 * Decompiled function: Pic_Subsystem_004316cc
 * Entry Point: 004316cc
 * Size: 756 bytes
 */
#include "magic.h"


undefined4 Pic_Subsystem_004316cc(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  if ((arg_3 == 199) && (((&g_CardSlot_Flags)[arg_2 * 0x120 + arg_1 * 0x5b20] & 2) != 0)) {
    iVar1 = FUN_0041d963(arg_1,arg_2,1);
    if (*(int *)(&DAT_0063ee30 + iVar1 * 4 + g_CurrentTurnPhase * 0x20) != 0) {
      iVar1 = 0x18 - (int)(&g_PlayerCreatureCount)[g_CurrentTurnPhase] /
                     *(int *)(&DAT_0063ee30 + iVar1 * 4 + g_CurrentTurnPhase * 0x20);
      if (iVar1 < 2) {
        iVar1 = 1;
      }
      g_SpellStackDepth = g_SpellStackDepth + iVar1 * 0x18;
    }
    iVar1 = FUN_0041d963(arg_1,arg_2,1);
    if (*(int *)(&DAT_0063ee30 + iVar1 * 4 + g_ActivePlayerPriority * 0x20) != 0) {
      iVar1 = 0x18 - (int)(&g_PlayerCreatureCount)[g_ActivePlayerPriority] /
                     *(int *)(&DAT_0063ee30 + iVar1 * 4 + g_ActivePlayerPriority * 0x20);
      if (iVar1 < 2) {
        iVar1 = 1;
      }
      g_SpellStackDepth = g_SpellStackDepth + iVar1 * -0x18;
    }
  }
  if (arg_3 == 0x74) {
    uVar2 = 1;
  }
  else if (arg_3 == 0x73) {
    if (((g_ScWillyScore == 4) &&
        (((&g_CardSlot_ConvertedManaCost)[arg_2 * 0x120 + arg_1 * 0x5b20] & 1) == 0)) &&
       ((g_DefendingPlayer == DAT_0063edc0 &&
        (iVar1 = FUN_0041d963(arg_1,arg_2,1),
        *(int *)(&DAT_0063ee30 + iVar1 * 4 + DAT_0063edc0 * 0x20) != 0)))) {
      *(uint *)(&g_CardSlot_SpecialState + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&g_CardSlot_SpecialState + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x101;
      DAT_006a4920 = DAT_006a4920 | 3;
      return 1;
    }
    uVar2 = 0;
  }
  else {
    if (((arg_3 == 4) && (g_OverworldMapGrid == arg_2)) && (g_OverworldPlayerCoordX == arg_1)) {
      *(uint *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) | 1;
      DAT_00695df8 = 1;
      g_ActivePalette = g_ActivePalette | 1;
    }
    if (arg_3 == 0x86) {
      iVar1 = arg_1;
      iVar4 = arg_2;
      iVar3 = FUN_0041d963(arg_1,arg_2,1);
      Mem_AllocOrFree_0041df33
                (g_DefendingPlayer,*(int *)(&DAT_0063ee30 + iVar3 * 4 + g_DefendingPlayer * 0x20),
                 iVar1,iVar4);
    }
    if (arg_3 == 0x22) {
      *(uint *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) & 0xfffffffe;
    }
    if (arg_3 == 199) {
      iVar1 = 1 - g_DefendingPlayer;
      iVar4 = FUN_0041d963(arg_1,arg_2,1);
      Mem_AllocOrFree_0041df33(iVar1,*(int *)(&DAT_0063ee30 + iVar4 * 4 + iVar1 * 0x20),arg_1,arg_2)
      ;
    }
    uVar2 = 0;
  }
  return uVar2;
}



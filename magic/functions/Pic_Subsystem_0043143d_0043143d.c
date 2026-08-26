/*
 * Decompiled function: Pic_Subsystem_0043143d
 * Entry Point: 0043143d
 * Size: 650 bytes
 */
#include "magic.h"


uint Pic_Subsystem_0043143d(int arg_1,int arg_2,int arg_3)

{
  uint uVar1;
  int iVar2;
  byte bVar3;
  int local_c;
  
  if (arg_3 == 0x74) {
    if (arg_1 == g_CurrentTurnPhase) {
      uVar1 = (DAT_006a2828 | DAT_006a282c) & 1;
    }
    else {
      uVar1 = (&DAT_006a2828)[g_CurrentTurnPhase] & 1;
    }
  }
  else {
    if (((arg_3 == 0x6c) && (g_OverworldMapGrid == arg_2)) && (g_OverworldPlayerCoordX == arg_1)) {
      iVar2 = CardTarget_PromptTargetPermanent(arg_1,1 - arg_1,arg_2);
      if (iVar2 == 0) {
        g_ActivePlayer = 1;
      }
      else if ((char)(&g_CardSlot_Toughness)[arg_1 * 0x5b20 + arg_2 * 0x120] == arg_1) {
        g_SpellStackDepth = g_SpellStackDepth + -0x18;
      }
      else {
        g_SpellStackDepth =
             g_SpellStackDepth +
             (*(int *)(&DAT_0063ee4c + (1 - arg_1) * 0x20) - *(int *)(&DAT_0063ee4c + arg_1 * 0x20))
             * 0xc;
      }
    }
    if (((arg_3 == 0x7c) && (((&g_CardSlot_Flags)[arg_1 * 0x5b20 + arg_2 * 0x120] & 0x20) == 0)) &&
       ((*(int *)(&g_CardSlot_OriginalCardId + arg_1 * 0x5b20 + arg_2 * 0x120) == g_OverworldMapGrid
        && (((char)(&g_CardSlot_Toughness)[arg_1 * 0x5b20 + arg_2 * 0x120] ==
             g_OverworldPlayerCoordX && (g_OverworldMapGrid != -1)))))) {
      iVar2 = CardQuery_PlayerControlsColor(g_OverworldPlayerCoordX,1);
      bVar3 = iVar2 != 0;
      iVar2 = CardQuery_PlayerControlsColor(1 - g_OverworldPlayerCoordX,1);
      if (iVar2 != 0) {
        bVar3 = bVar3 | 2;
      }
      if (bVar3 == 0) {
        Pic_Subsystem_0044867e(arg_1,arg_2,2);
      }
      else {
        if (g_OverworldPlayerCoordX == g_CurrentTurnPhase) {
          do {
          } while (local_c == -1);
        }
        else {
          do {
          } while (local_c == -1);
        }
        *(int *)(&g_CardSlot_OriginalCardId + arg_1 * 0x5b20 + arg_2 * 0x120) = local_c;
        (&g_CardSlot_Toughness)[arg_1 * 0x5b20 + arg_2 * 0x120] = DAT_0063ee20;
      }
      Pic_Subsystem_0044867e(g_OverworldPlayerCoordX,g_OverworldMapGrid,2);
    }
    uVar1 = 0;
  }
  return uVar1;
}


